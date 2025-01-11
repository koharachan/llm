#pragma once

#include "mc/_HeaderOutputPredefine.h"

namespace Bedrock {

class SessionInfo {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::UntypedStorage<8, 32> mUnkd1ebd7;
    ::ll::UntypedStorage<8, 32> mUnkd9e956;
    ::ll::UntypedStorage<8, 32> mUnk5a1ed1;
    ::ll::UntypedStorage<8, 32> mUnkdc6067;
    ::ll::UntypedStorage<8, 32> mUnk2fa3c9;
    ::ll::UntypedStorage<8, 32> mUnkc9ca4e;
    ::ll::UntypedStorage<8, 16> mUnk46f4f1;
    ::ll::UntypedStorage<8, 8>  mUnk519224;
    ::ll::UntypedStorage<8, 8>  mUnk6a042c;
    ::ll::UntypedStorage<4, 8>  mUnkc1616b;
    ::ll::UntypedStorage<8, 32> mUnkcdddba;
    // NOLINTEND

public:
    // prevent constructor by default
    SessionInfo& operator=(SessionInfo const&);
    SessionInfo(SessionInfo const&);
    SessionInfo();

public:
    // member functions
    // NOLINTBEGIN
    MCFOLD ::std::string const& getBranchId() const;

    MCFOLD ::std::string const& getBuildId() const;

    MCFOLD ::std::string const& getCommitId() const;

    MCFOLD int64 getCrashTimestamp() const;

    MCFOLD ::std::optional<uint> const& getErrorCode() const;

    MCFOLD ::std::string const& getErrorMessage() const;

    MCFOLD ::std::string const& getSessionId() const;

    MCFOLD ::std::map<::std::string, ::std::string>& getTags();
    // NOLINTEND
};

} // namespace Bedrock
