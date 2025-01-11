#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/util/ItemCerealSchemaUpgrade.h"

namespace WearableItemComponentVersioning {

class UpgradeTo12020 : public ::ItemCerealSchemaUpgrade {
public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 1
    virtual bool previousSchema(::rapidjson::GenericValue<
                                ::rapidjson::UTF8<char>,
                                ::rapidjson::MemoryPoolAllocator<::rapidjson::CrtAllocator>> const& component) const
        /*override*/;

    // vIndex: 0
    virtual ~UpgradeTo12020() /*override*/ = default;
    // NOLINTEND

public:
    // member functions
    // NOLINTBEGIN
    MCAPI UpgradeTo12020();
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor();
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN

    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI bool $previousSchema(::rapidjson::GenericValue<
                               ::rapidjson::UTF8<char>,
                               ::rapidjson::MemoryPoolAllocator<::rapidjson::CrtAllocator>> const& component) const;
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};

} // namespace WearableItemComponentVersioning
