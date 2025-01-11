#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/world/level/levelgen/feature/Feature.h"

// auto generated forward declare list
// clang-format off
class Block;
class BlockPos;
class BlockSource;
class Random;
// clang-format on

class CoralFeature : public ::Feature {
public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 4
    virtual bool place(::BlockSource& region, ::BlockPos const& pos, ::Random& random) const /*override*/;

    // vIndex: 0
    virtual ~CoralFeature() /*override*/ = default;
    // NOLINTEND

public:
    // member functions
    // NOLINTBEGIN
    MCAPI void _buildHand(
        ::BlockSource&                                 region,
        ::BlockPos const&                              pos,
        ::Random&                                      random,
        ::std::vector<::BlockPos>&                     topDec,
        ::std::vector<::std::pair<::BlockPos, uchar>>& sideDec,
        ::gsl::not_null<::Block const*>                block
    ) const;

    MCAPI void _buildPlantArm(
        ::BlockSource&                                 region,
        ::Random&                                      random,
        ::BlockPos const&                              pos,
        ::gsl::not_null<::Block const*>                block,
        ::std::vector<::BlockPos>&                     topDec,
        ::std::vector<::std::pair<::BlockPos, uchar>>& sideDec,
        uchar                                          direction,
        bool                                           notTall
    ) const;

    MCAPI void _buildPlantLike(
        ::BlockSource&                                 region,
        ::BlockPos const&                              pos,
        ::Random&                                      random,
        ::std::vector<::BlockPos>&                     topDec,
        ::std::vector<::std::pair<::BlockPos, uchar>>& sideDec,
        ::gsl::not_null<::Block const*>                block
    ) const;

    MCAPI void _buildSmallClump(
        ::BlockSource&             region,
        ::BlockPos const&          pos,
        ::Random&                  random,
        ::std::vector<::BlockPos>& topDec,
        ::std::vector<::std::pair<::BlockPos, uchar>>&,
        ::gsl::not_null<::Block const*> block
    ) const;

    MCAPI void _buildSpire(
        ::BlockSource&                                 region,
        ::BlockPos const&                              pos,
        ::Random&                                      random,
        ::std::vector<::BlockPos>&                     topDec,
        ::std::vector<::std::pair<::BlockPos, uchar>>& sideDec,
        ::gsl::not_null<::Block const*>                block
    ) const;

    MCAPI int _getColor(::Block const& block) const;

    MCAPI void _placeSideDecorations(::BlockSource& region, ::BlockPos const& pos, ::Random& random, uchar dir) const;

    MCAPI bool
    _setBlock(::BlockSource& region, ::BlockPos const& pos, ::gsl::not_null<::Block const*> block, int color) const;

    MCAPI bool
    _setBlockOnSolid(::BlockSource& region, ::BlockPos const& pos, ::gsl::not_null<::Block const*> block, int color)
        const;

    MCAPI ::gsl::not_null<::Block const*> _setCoralHangData(int face, int color, int type) const;
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN

    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI bool $place(::BlockSource& region, ::BlockPos const& pos, ::Random& random) const;
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};
