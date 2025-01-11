#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated forward declare list
// clang-format off
namespace Core { class FileSizePresetToken; }
namespace Core { class Path; }
// clang-format on

namespace Core {

class FileSizePresetManager {
public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 0
    virtual ~FileSizePresetManager();

    // vIndex: 1
    virtual ::std::unique_ptr<::Core::FileSizePresetToken> presetInitialSizeForFile(::Core::Path const&, uint64) = 0;

    // vIndex: 2
    virtual ::std::optional<uint64> checkFileInitialSize(::Core::Path const&) = 0;
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCAPI void $dtor();
    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN

    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};

} // namespace Core
