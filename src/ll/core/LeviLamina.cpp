#include "ll/core/LeviLamina.h"
#include "ll/api/Versions.h"
#include "ll/api/i18n/I18n.h"
#include "ll/api/io/FileUtils.h"
#include "ll/api/reflection/Deserialization.h"
#include "ll/core/Version.h"
#include "mc/platform/UUID.h"
#include "nlohmann/json.hpp"

namespace ll {
namespace {
// 预缓存常用路径和翻译结果以优化性能
static const auto& getManifestPath() {
    static const auto path = [] {
        return mod::getModsRoot() / string_utils::sv2u8sv(selfModName) / u8"manifest.json";
    }();
    return path;
}

// 缓存欢迎消息的翻译结果
struct CachedMessages {
    std::string_view licenseMsg;
    std::string_view translateMsg;

    CachedMessages() {
        licenseMsg   = "LeviLamina is a free software licensed under {0}"_tr("LGPLv3");
        translateMsg = "Help us translate & improve text -> {0}"_tr("https://translate.liteldev.com/");
    }
};
} // namespace

std::shared_ptr<mod::NativeMod> const& getSelfModIns() {
    static const auto llSelf = [] {
        // 使用快速JSON解析选项：禁用异常和评论
        auto json = nlohmann::json::parse(
            file_utils::readFile(getManifestPath()).value(),
            nullptr,
            false, // 禁用注释
            false  // 严格模式
        );
        return std::make_shared<mod::NativeMod>(
            reflection::deserialize_to<mod::Manifest>(json).value(),
            sys_utils::getCurrentModuleHandle()
        );
    }();
    return llSelf;
}

io::Logger& getLogger() {
    static auto& logger = getSelfModIns()->getLogger();
    return logger;
}

std::string_view getServiceUuid() {
    static const std::string serverUuid = [] {
        const auto uuidPath = getSelfModIns()->getDataDir() / u8"statisticsUuid";
        auto       content  = file_utils::readFile(uuidPath);
        if (!content) {
            std::string uuid = mce::UUID::random().asString();
            file_utils::writeFile(uuidPath, uuid);
            return uuid;
        }
        return std::move(*content); // 避免二次拷贝
    }();
    return serverUuid;
}

void printWelcomeMsg() {
    static const CachedMessages cached; // 首次调用时初始化翻译缓存
    auto& logger = getLogger();
    logger.info(R"(                                                                      )");
    logger.info(R"(         _               _ _                    _                     )");
    logger.info(R"(        | |    _____   _(_) |    __ _ _ __ ___ (_)_ __   __ _         )");
    logger.info(R"(        | |   / _ \ \ / / | |   / _` | '_ ` _ \| | '_ \ / _` |        )");
    logger.info(R"(        | |__|  __/\ V /| | |__| (_| | | | | | | | | | | (_| |        )");
    logger.info(R"(        |_____\___| \_/ |_|_____\__,_|_| |_| |_|_|_| |_|\__,_|        )");
    logger.info(R"(                                                                      )");
    logger.info(R"(        ------------   Light-Weight Mod Loader   -------------        )");
    logger.info(R"(                                                                      )");
    logger.info(R"(                                                                      )");

    logger.info("LeviLamina is a free software licensed under {0}"_tr("LGPLv3"));
    logger.info("Help us translate & improve text -> {0}"_tr("https://translate.liteldev.com/"));
}

} // namespace ll
