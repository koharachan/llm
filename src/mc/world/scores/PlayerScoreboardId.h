#pragma once

#include "mc/_HeaderOutputPredefine.h"

struct PlayerScoreboardId {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::TypedStorage<8, 8, int64> mActorUniqueId;
    // NOLINTEND

public:
    // static variables
    // NOLINTBEGIN
    MCAPI static ::PlayerScoreboardId const& INVALID();
    // NOLINTEND
};
