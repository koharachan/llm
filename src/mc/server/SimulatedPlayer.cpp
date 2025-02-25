#include "mc/server/SimulatedPlayer.h"
#include "ll/api/service/Bedrock.h"
#include "ll/api/utils/RandomUtils.h"
#include "mc/deps/core/string/HashedString.h"
#include "mc/network/ServerNetworkHandler.h"
#include "mc/server/ServerLevel.h"
#include "mc/world/actor/player/Inventory.h"
#include "mc/world/actor/player/PlayerInventory.h"
#include "mc/world/actor/player/PlayerItemInUse.h"
#include "mc/world/level/BlockSource.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/phys/HitResult.h"

optional_ref<SimulatedPlayer>
SimulatedPlayer::create(std::string const& name, Vec3 const& pos, DimensionType dimId, Vec2 const& rotation) {
    if (auto handler = ll::service::getServerNetworkHandler()) { // 合并条件检查
        // 使用线程局部静态变量提高随机数生成效率（假设允许）
        static thread_local std::mt19937_64    gen(std::random_device{}());
        std::uniform_int_distribution<int64_t> dis(INT64_MIN, -1);
        auto player = create(name, BlockPos{pos}, dimId, *handler, std::to_string(dis(gen)));
        if (player) {
            player->teleport(pos, dimId, rotation);
        }
        return player;
    }
    return nullptr;
}

bool SimulatedPlayer::simulateDestroyBlock(const BlockPos& pos, ScriptModuleMinecraft::ScriptFacing face) {
    if (!isAlive()) return false;

    // 使用值缓存优化多次访问optional
    if (mDestroyingBlockPos.has_value() && mDestroyingBlockFace.has_value()) {
        if (pos == mDestroyingBlockPos.value() && static_cast<uchar>(face) == mDestroyingBlockFace.value()) {
            return true;
        }
        simulateStopDestroyingBlock();
    }

    BlockSource&       blockSource = getDimensionBlockSource(); // 缓存BlockSource
    Block const&       block       = blockSource.getBlock(pos);
    BlockLegacy const& legacy      = block.getLegacyBlock();

    if (legacy.mayPick()) {
        // 添加mItemInUse的判空检查防止崩溃
        if (mItemInUse && mItemInUse->mUnkf0096a.as<ItemStack>().isNull()) {
            mDestroyingBlockPos  = pos;
            mDestroyingBlockFace = static_cast<uchar>(face);
            return true;
        }
    }
    return false;
}

bool SimulatedPlayer::simulateDestroyLookAt(float handLength) {
    auto hitResult = traceRay(handLength, false);
    return hitResult.mType == HitResultType::Tile
        && simulateDestroyBlock(hitResult.mBlock, static_cast<ScriptModuleMinecraft::ScriptFacing>(hitResult.mFacing));
}

::SimulatedPlayer* tryGetFromEntity(::EntityContext& entity, bool includeRemoved) {
    // 使用一步转换优化类型检查
    return ll::service::getServerNetworkHandler()
             ? static_cast<SimulatedPlayer*>(Player::tryGetFromEntity(entity, includeRemoved))
             : nullptr;
}