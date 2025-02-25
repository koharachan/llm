#include "ll/core/Statistics.h"


#include "ll/api/Versions.h"
#include "ll/api/base/Containers.h"
#include "ll/api/chrono/GameChrono.h"
#include "ll/api/coro/CoroTask.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/server/ServerStartedEvent.h"
#include "ll/api/i18n/I18n.h"
#include "ll/api/io/FileUtils.h"
#include "ll/api/memory/Hook.h"
#include "ll/api/mod/ModManagerRegistry.h"
#include "ll/api/service/Bedrock.h"
#include "ll/api/service/ServerInfo.h"
#include "ll/api/thread/ServerThreadExecutor.h"
#include "ll/api/thread/ThreadPoolExecutor.h"
#include "ll/api/utils/ErrorUtils.h"
#include "ll/api/utils/RandomUtils.h"
#include "ll/api/utils/StringUtils.h"
#include "ll/api/utils/SystemUtils.h"
#include "ll/core/LeviLamina.h"


#include "mc/common/BuildInfo.h"
#include "mc/common/Common.h"
#include "mc/platform/UUID.h"
#include "mc/server/PropertiesSettings.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/level/Level.h"

#include "cpr/cpr.h"
#include "magic_enum/magic_enum.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"

namespace ll {

static nlohmann::json addSimplePie(std::string_view key, std::variant<std::string, int> value) {
    return {
        {"chartId",                                                                              key},
        {   "data", {{"value", std::visit([](auto&& arg) -> nlohmann::json { return arg; }, value)}}}
    };
}

static nlohmann::json addAdvancedPie(std::string_view key, const SmallDenseMap<std::string_view, int>& value) {
    nlohmann::json valuesBuilder;
    for (const auto& [k, v] : value) {
        valuesBuilder[std::string(k)] = v; // 显式转换string_view->string
    }
    return {
        {"chartId",                                    key},
        {   "data", {{"values", std::move(valuesBuilder)}}}
    };
}

static nlohmann::json addSingleLineChart(std::string_view key, int value) {
    return {
        {"chartId",                key},
        {   "data", {{"value", value}}}
    };
}

static nlohmann::json getCustomCharts() {
    nlohmann::json res;
    res.reserve(5); // 预分配已知数量

    const auto& buildInfo   = Common::getBuildInfo();
    const auto  levelOpt    = service::getLevel();
    const auto  settingsOpt = service::getPropertiesSettings();

    // 基础信息
    res.emplace_back(addSimplePie("levilamina_version", getLoaderVersion().to_string()));
    res.emplace_back(addSimplePie("minecraft_version", buildInfo.mBuildId));

    // 玩家数量
    const int playerCount = levelOpt.transform([](auto& l) { return l.getActivePlayerCount(); }).value_or(0);
    res.emplace_back(addSingleLineChart("players", playerCount));

    // 在线模式
    const bool onlineMode = settingsOpt.transform([](auto& s) { return s.mIsOnlineMode; }).value_or(false);
    res.emplace_back(addSimplePie("online_mode", onlineMode ? "true" : "false"));

    // 玩家平台统计
    SmallDenseMap<std::string_view, int> platforms;
    levelOpt.transform([&platforms](auto& level) {
        level.forEachPlayer([&platforms](Player& player) {
            ++platforms[magic_enum::enum_name(player.mBuildPlatform)];
            return true;
        });
    });
    res.emplace_back(addAdvancedPie("player_platform", platforms));

    return res;
}

struct Statistics::Impl {
    nlohmann::json json;

    void submitData() {
        coro::keepThis([&]() -> coro::CoroTask<> {
            nlohmann::json pluginInfo;
            pluginInfo["pluginName"]   = getSelfModIns()->getName();
            pluginInfo["customCharts"] = getCustomCharts();

            // 直接替换plugins数组
            json["plugins"] = nlohmann::json::array({pluginInfo});

            co_return;
        }).syncLaunch(thread::ServerThreadExecutor::getDefault());

        try {
            cpr::Post(
                cpr::Url{
                    "https://bstats.org/submitData/server-implementation"
            },
                cpr::Body{json.dump()},
                cpr::Header{
                    {"Accept", "application/json"},
                    {"Content-Type", "application/json"},
                    {"User-Agent", "Metrics-Service/1"}
                }
            );
        } catch (...) {}
    }

    Impl() {
        json["serverUUID"] = getServiceUuid();
        json["osName"]     = sys_utils::isWine() ? "Linux(wine)" : "Windows";
        json["osArch"]     = "amd64";
        json["osVersion"]  = "";
        json["coreCount"]  = std::thread::hardware_concurrency();

        coro::keepThis([&]() -> coro::CoroTask<> {
            co_await (1.0min * random_utils::rand(3.0, 6.0));
            submitData();
            co_await (1.0min * random_utils::rand(1.0, 30.0));
            submitData();
            while (true) {
                co_await 30min;
                submitData();
            }
        }).launch(thread::ThreadPoolExecutor::getDefault());
        getLogger().info("Statistics has been enabled, you can disable statistics in configuration file"_tr());
    }
};

void Statistics::call(bool enable) {
    if (enable && !impl) {
        impl = std::make_unique<Impl>();
    } else if (!enable) {
        impl.reset();
    }
}

Statistics::Statistics()  = default;
Statistics::~Statistics() = default;
} // namespace ll
