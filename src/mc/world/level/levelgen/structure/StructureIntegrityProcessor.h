#pragma once

#include "mc/_HeaderOutputPredefine.h"

class StructureIntegrityProcessor {
public:
    // member variables
    // NOLINTBEGIN
    ::ll::UntypedStorage<4, 4> mUnkc757b4;
    ::ll::UntypedStorage<4, 4> mUnk938b91;
    // NOLINTEND

public:
    // prevent constructor by default
    StructureIntegrityProcessor& operator=(StructureIntegrityProcessor const&);
    StructureIntegrityProcessor(StructureIntegrityProcessor const&);
    StructureIntegrityProcessor();

public:
    // member functions
    // NOLINTBEGIN
    MCAPI ::std::vector<bool> generateFlagsForIndices(int endIndex, int startIndex) const;
    // NOLINTEND
};
