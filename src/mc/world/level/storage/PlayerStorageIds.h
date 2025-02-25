#pragma once

#include "mc/_HeaderOutputPredefine.h"

struct PlayerStorageIds {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::TypedStorage<8, 32, ::std::string> MsaId;
    ::ll::TypedStorage<8, 32, ::std::string> PlatformId;
    ::ll::TypedStorage<8, 32, ::std::string> PlatformOnlineId;
    ::ll::TypedStorage<8, 32, ::std::string> PlatformOfflineId;
    ::ll::TypedStorage<8, 32, ::std::string> SelfSignedId;
    ::ll::TypedStorage<8, 32, ::std::string> RandomClientId;
    // NOLINTEND

public:
    // member functions
    // NOLINTBEGIN
    MCAPI PlayerStorageIds();

    MCAPI ~PlayerStorageIds();
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor();
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCFOLD void $dtor();
    // NOLINTEND
};
