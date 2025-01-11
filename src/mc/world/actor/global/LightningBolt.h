#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/ActorInitializationMethod.h"

// auto generated forward declare list
// clang-format off
class ActorDefinitionGroup;
class CompoundTag;
class DataLoadHelper;
class EntityContext;
struct ActorDefinitionIdentifier;
struct VariantParameterList;
// clang-format on

class LightningBolt : public ::Actor {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::UntypedStorage<4, 4> mUnkcdcb88;
    ::ll::UntypedStorage<4, 4> mUnkd45498;
    ::ll::UntypedStorage<4, 4> mUnkcf0099;
    ::ll::UntypedStorage<1, 1> mUnk97fd43;
    ::ll::UntypedStorage<1, 1> mUnkf5773f;
    // NOLINTEND

public:
    // prevent constructor by default
    LightningBolt& operator=(LightningBolt const&);
    LightningBolt(LightningBolt const&);
    LightningBolt();

public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 2
    virtual void reloadHardcoded(::ActorInitializationMethod method, ::VariantParameterList const& params) /*override*/;

    // vIndex: 3
    virtual void reloadHardcodedClient(::ActorInitializationMethod method) /*override*/;

    // vIndex: 24
    virtual void normalTick() /*override*/;

    // vIndex: 141
    virtual void addAdditionalSaveData(::CompoundTag& tag) const /*override*/;

    // vIndex: 140
    virtual void readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper) /*override*/;

    // vIndex: 36
    virtual float getShadowRadius() const /*override*/;

    // vIndex: 143
    virtual bool shouldAlwaysRender();

    // vIndex: 8
    virtual ~LightningBolt() /*override*/ = default;
    // NOLINTEND

public:
    // member functions
    // NOLINTBEGIN
    MCAPI LightningBolt(
        ::ActorDefinitionGroup*            definitions,
        ::ActorDefinitionIdentifier const& definitionName,
        ::EntityContext&                   entityContext
    );

    MCAPI bool _shouldSetOnFire() const;
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::ActorDefinitionGroup*            definitions,
        ::ActorDefinitionIdentifier const& definitionName,
        ::EntityContext&                   entityContext
    );
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN

    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI void $reloadHardcoded(::ActorInitializationMethod method, ::VariantParameterList const& params);

    MCAPI void $reloadHardcodedClient(::ActorInitializationMethod method);

    MCAPI void $normalTick();

    MCFOLD void $addAdditionalSaveData(::CompoundTag& tag) const;

    MCFOLD void $readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    MCFOLD float $getShadowRadius() const;

    MCFOLD bool $shouldAlwaysRender();
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};
