#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/editor/network/NetworkPayload.h"

// auto generated forward declare list
// clang-format off
namespace cereal { struct ReflectionCtx; }
// clang-format on

namespace Editor::Network {

class DataTransferServiceRequestDataPayload
: public ::Editor::Network::NetworkPayload<::Editor::Network::DataTransferServiceRequestDataPayload> {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::UntypedStorage<8, 16> mUnk73ce7c;
    ::ll::UntypedStorage<8, 32> mUnk2c41bd;
    // NOLINTEND

public:
    // prevent constructor by default
    DataTransferServiceRequestDataPayload& operator=(DataTransferServiceRequestDataPayload const&);
    DataTransferServiceRequestDataPayload(DataTransferServiceRequestDataPayload const&);
    DataTransferServiceRequestDataPayload();

public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 0
    virtual ~DataTransferServiceRequestDataPayload() /*override*/;
    // NOLINTEND

public:
    // static functions
    // NOLINTBEGIN
    MCAPI static void bindType(::cereal::ReflectionCtx& ctx);
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCFOLD void $dtor();
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};

} // namespace Editor::Network
