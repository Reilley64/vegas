#pragma once

#include "fnv/decl/MemoryManagerStandIn.h"

// Release and allocation are real receiver bases in ONE inheritance chain.
// Two independent empty bases have distinct offsets on Windows; this chain
// preserves both source entry identities without a fabricated owner prefix.
struct FNV_MemoryManager : MemoryManagerStandIn {
protected:
    FNV_MemoryManager() = default;
public:
    // 0x00aa4060
    void FUN_00aa4060(void *);
};
