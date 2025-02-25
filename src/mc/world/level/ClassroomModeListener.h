#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/world/level/BlockChangedEventTarget.h"
#include "mc/world/level/LevelListener.h"

// auto generated forward declare list
// clang-format off
class Actor;
class Block;
class BlockPos;
class BlockSource;
class ChunkSource;
class LevelChunk;
struct ActorBlockSyncMessage;
// clang-format on

class ClassroomModeListener : public ::LevelListener {
public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 17
    virtual void onEntityAdded(::Actor& entity) /*override*/;

    // vIndex: 18
    virtual void onEntityRemoved(::Actor& entity) /*override*/;

    // vIndex: 4
    virtual void onBlockChanged(
        ::BlockSource&                 source,
        ::BlockPos const&              pos,
        uint                           layer,
        ::Block const&                 block,
        ::Block const&                 oldBlock,
        int                            updateFlags,
        ::ActorBlockSyncMessage const* syncMsg,
        ::BlockChangedEventTarget      eventTarget,
        ::Actor*                       blockChangeSource
    ) /*override*/;

    // vIndex: 3
    virtual void onAreaChanged(::BlockSource& source, ::BlockPos const& min, ::BlockPos const& max) /*override*/;

    // vIndex: 19
    virtual void onChunkLoaded(::ChunkSource& source, ::LevelChunk& lc) /*override*/;

    // vIndex: 22
    virtual void onChunkUnloaded(::LevelChunk& lc) /*override*/;

    // vIndex: 0
    virtual ~ClassroomModeListener() /*override*/ = default;
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN

    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCFOLD void $onEntityAdded(::Actor& entity);

    MCFOLD void $onEntityRemoved(::Actor& entity);

    MCFOLD void $onBlockChanged(
        ::BlockSource&                 source,
        ::BlockPos const&              pos,
        uint                           layer,
        ::Block const&                 block,
        ::Block const&                 oldBlock,
        int                            updateFlags,
        ::ActorBlockSyncMessage const* syncMsg,
        ::BlockChangedEventTarget      eventTarget,
        ::Actor*                       blockChangeSource
    );

    MCFOLD void $onAreaChanged(::BlockSource& source, ::BlockPos const& min, ::BlockPos const& max);

    MCFOLD void $onChunkLoaded(::ChunkSource& source, ::LevelChunk& lc);

    MCFOLD void $onChunkUnloaded(::LevelChunk& lc);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};
