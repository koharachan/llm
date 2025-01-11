#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/scripting/modules/minecraft/events/metadata/ScriptCustomComponentScriptInterface.h"

namespace ScriptModuleMinecraft {

class ScriptBlockCustomComponentInterface : public ::ScriptModuleMinecraft::ScriptCustomComponentScriptInterface<9> {
public:
    // member functions
    // NOLINTBEGIN
    MCAPI ScriptBlockCustomComponentInterface(::ScriptModuleMinecraft::ScriptBlockCustomComponentInterface&&);

    MCAPI bool isEmpty() const;

    MCAPI ::ScriptModuleMinecraft::ScriptBlockCustomComponentInterface&
    operator=(::ScriptModuleMinecraft::ScriptBlockCustomComponentInterface&&);

    MCAPI ~ScriptBlockCustomComponentInterface();
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(::ScriptModuleMinecraft::ScriptBlockCustomComponentInterface&&);
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCAPI void $dtor();
    // NOLINTEND
};

} // namespace ScriptModuleMinecraft
