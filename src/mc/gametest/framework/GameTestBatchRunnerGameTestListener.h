#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/gametest/framework/IGameTestListener.h"

// auto generated forward declare list
// clang-format off
namespace gametest { class BaseGameTestInstance; }
// clang-format on

namespace gametest {

class GameTestBatchRunnerGameTestListener : public ::gametest::IGameTestListener {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::UntypedStorage<8, 8> mUnkb2fb6a;
    // NOLINTEND

public:
    // prevent constructor by default
    GameTestBatchRunnerGameTestListener& operator=(GameTestBatchRunnerGameTestListener const&);
    GameTestBatchRunnerGameTestListener(GameTestBatchRunnerGameTestListener const&);
    GameTestBatchRunnerGameTestListener();

public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 1
    virtual void onTestStructureLoaded(::gametest::BaseGameTestInstance&) /*override*/;

    // vIndex: 2
    virtual void onTestPassed(::gametest::BaseGameTestInstance&) /*override*/;

    // vIndex: 3
    virtual void onTestFailed(::gametest::BaseGameTestInstance&) /*override*/;

    // vIndex: 6
    virtual void onTestRetryFinished(::gametest::BaseGameTestInstance&) /*override*/;

    // vIndex: 0
    virtual ~GameTestBatchRunnerGameTestListener() /*override*/ = default;
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN

    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCFOLD void $onTestStructureLoaded(::gametest::BaseGameTestInstance&);

    MCFOLD void $onTestPassed(::gametest::BaseGameTestInstance&);

    MCFOLD void $onTestFailed(::gametest::BaseGameTestInstance&);

    MCFOLD void $onTestRetryFinished(::gametest::BaseGameTestInstance&);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};

} // namespace gametest
