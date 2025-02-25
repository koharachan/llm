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
    if (auto handler = ll::service::getServerNetworkHandler()) { // �ϲ��������
        // ʹ���ֲ߳̾���̬����������������Ч�ʣ���������
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

    // ʹ��ֵ�����Ż���η���optional
    if (mDestroyingBlockPos.has_value() && mDestroyingBlockFace.has_value()) {
        if (pos == mDestroyingBlockPos.value() && static_cast<uchar>(face) == mDestroyingBlockFace.value()) {
            return true;
        }
        simulateStopDestroyingBlock();
    }

    BlockSource&       blockSource = getDimensionBlockSource(); // ����BlockSource
    Block const&       block       = blockSource.getBlock(pos);
    BlockLegacy const& legacy      = block.getLegacyBlock();

    if (legacy.mayPick()) {
        // ���mItemInUse���пռ���ֹ����
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
    // ʹ��һ��ת���Ż����ͼ��
    return ll::service::getServerNetworkHandler()
             ? static_cast<SimulatedPlayer*>(Player::tryGetFromEntity(entity, includeRemoved))
             : nullptr;
}