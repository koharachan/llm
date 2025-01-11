#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated forward declare list
// clang-format off
class Block;
class HashedString;
namespace cereal { struct ReflectionCtx; }
// clang-format on

namespace Editor {

struct WeightedRandomBlock {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::UntypedStorage<8, 8> mUnk9bba29;
    ::ll::UntypedStorage<4, 4> mUnk2e0875;
    // NOLINTEND

public:
    // prevent constructor by default
    WeightedRandomBlock& operator=(WeightedRandomBlock const&);
    WeightedRandomBlock(WeightedRandomBlock const&);
    WeightedRandomBlock();

public:
    // member functions
    // NOLINTBEGIN
    MCAPI WeightedRandomBlock(::Block const* block, int weight);

    MCAPI ::HashedString _getBlock() const;

    MCFOLD int getWeight() const;
    // NOLINTEND

public:
    // static functions
    // NOLINTBEGIN
    MCAPI static void bindType(::cereal::ReflectionCtx& ctx);
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCFOLD void* $ctor(::Block const* block, int weight);
    // NOLINTEND
};

} // namespace Editor
