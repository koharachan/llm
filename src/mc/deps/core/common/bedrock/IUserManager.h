#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/common/bedrock/EnableNonOwnerReferences.h"

// auto generated forward declare list
// clang-format off
namespace Bedrock { class EnableNonOwnerReferences; }
// clang-format on

namespace Social {

class IUserManager : public ::Bedrock::EnableNonOwnerReferences {
public:
    // prevent constructor by default
    IUserManager& operator=(IUserManager const&);
    IUserManager(IUserManager const&);
    IUserManager();

public:
    // NOLINTBEGIN
    // vIndex: 0, symbol: __gen_??1IUserManager@Social@@UEAA@XZ
    virtual ~IUserManager() = default;

    // NOLINTEND
};

}; // namespace Social
