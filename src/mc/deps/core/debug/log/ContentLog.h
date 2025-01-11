#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/debug/log/LogArea.h"
#include "mc/deps/core/debug/log/LogLevel.h"
#include "mc/deps/core/utility/DisableServiceLocatorOverride.h"
#include "mc/deps/core/utility/EnableNonOwnerReferences.h"
#include "mc/deps/core/utility/typeid_t.h"
#include "mc/diagnostics/LogAreaID.h"

// auto generated forward declare list
// clang-format off
class ContentLogEndPoint;
class ContextMessageLogger;
namespace Bedrock { class StaticOptimizedString; }
namespace Bedrock::Threading { class Mutex; }
// clang-format on

class ContentLog : public ::Bedrock::EnableNonOwnerReferences, public ::DisableServiceLocatorOverride {
public:
    // ContentLog inner types declare
    // clang-format off
    class ContentLogEndPointData;
    class ContentLogScope;
    class ScopeHandler;
    class ThreadSpecificData;
    // clang-format on

    // ContentLog inner types define
    class ScopeHandler : public ::std::enable_shared_from_this<::ContentLog::ScopeHandler> {
    public:
        // member variables
        // NOLINTBEGIN
        ::ll::UntypedStorage<8, 168> mUnkf021af;
        // NOLINTEND

    public:
        // prevent constructor by default
        ScopeHandler& operator=(ScopeHandler const&);
        ScopeHandler(ScopeHandler const&);
        ScopeHandler();
    };

    class ContentLogScope {
    public:
        // member variables
        // NOLINTBEGIN
        ::ll::TypedStorage<1, 1, bool>                                         mPopScope;
        ::ll::TypedStorage<8, 16, ::std::weak_ptr<::ContentLog::ScopeHandler>> mScopeHandler;
        // NOLINTEND

    public:
        // member functions
        // NOLINTBEGIN
        MCAPI explicit ContentLogScope(::Bedrock::StaticOptimizedString scope);

        MCAPI ~ContentLogScope();
        // NOLINTEND

    public:
        // constructor thunks
        // NOLINTBEGIN
        MCAPI void* $ctor(::Bedrock::StaticOptimizedString scope);
        // NOLINTEND

    public:
        // destructor thunk
        // NOLINTBEGIN
        MCAPI void $dtor();
        // NOLINTEND
    };

    class ContentLogEndPointData {
    public:
        // member variables
        // NOLINTBEGIN
        ::ll::TypedStorage<8, 8, ::gsl::not_null<::ContentLogEndPoint*>> mContentLogEndPoint;
        // NOLINTEND

    public:
        // member functions
        // NOLINTBEGIN
        MCAPI explicit ContentLogEndPointData(::gsl::not_null<::ContentLogEndPoint*> contentLogEndPoint);
        // NOLINTEND

    public:
        // constructor thunks
        // NOLINTBEGIN
        MCFOLD void* $ctor(::gsl::not_null<::ContentLogEndPoint*> contentLogEndPoint);
        // NOLINTEND
    };

    class ThreadSpecificData {
    public:
        // ThreadSpecificData inner types declare
        // clang-format off
        struct ScopeData;
        // clang-format on

        // ThreadSpecificData inner types define
        struct ScopeData {
        public:
            // member variables
            // NOLINTBEGIN
            ::ll::UntypedStorage<8, 8> mUnkeefd3d;
            ::ll::UntypedStorage<8, 8> mUnkc883e3;
            // NOLINTEND

        public:
            // prevent constructor by default
            ScopeData& operator=(ScopeData const&);
            ScopeData(ScopeData const&);
            ScopeData();
        };

    public:
        // member variables
        // NOLINTBEGIN
        ::ll::TypedStorage<8, 24, ::std::vector<::ContentLog::ThreadSpecificData::ScopeData>> mScope;
        ::ll::TypedStorage<8, 24, ::std::vector<::ContextMessageLogger*>>                     mMessageLoggers;
        // NOLINTEND
    };

public:
    // member variables
    // NOLINTBEGIN
    ::ll::TypedStorage<1, 1, bool> mEnabled;
    ::ll::TypedStorage<8, 16, ::std::map<::Bedrock::typeid_t<::ContentLog>, ::ContentLog::ContentLogEndPointData>>
                                                                             mEndPoints;
    ::ll::TypedStorage<8, 80, ::Bedrock::Threading::Mutex>                   mEndpointMutex;
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::ContentLog::ScopeHandler>> mScopeHandler;
    ::ll::TypedStorage<
        8,
        64,
        ::std::unordered_map<::LogLevel, ::std::unordered_map<::LogArea, ::std::unordered_set<uint64>>>>
        mOnceOnlyMessages;
    // NOLINTEND

public:
    // virtual functions
    // NOLINTBEGIN
    // vIndex: 0
    virtual ~ContentLog() /*override*/ = default;
    // NOLINTEND

public:
    // member functions
    // NOLINTBEGIN
    MCAPI ContentLog();

    MCAPI void _writeToLog(bool logOnlyOnce, ::LogArea area, ::LogLevel level, char*& args);

    MCAPI ::std::string getScope();

    MCFOLD bool isEnabled() const;

    MCAPI void log(bool, ::LogLevel, ::LogArea, ...);

    MCAPI void unregisterEndPoint(::gsl::not_null<::ContentLogEndPoint*> endPoint);

    MCAPI void updateEnabledStatus();
    // NOLINTEND

public:
    // static functions
    // NOLINTBEGIN
    MCAPI static ::LogAreaID const getBedrockLogAreaFromContentLogArea(::LogArea contentLogArea);

    MCAPI static char const* getLogAreaName(::LogArea area);
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
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};
