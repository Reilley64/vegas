
// src/fallout_shared/pathfinding/pathingsearchraycast.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingsearchraycast.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_006e62b0_Class.h"
#include "fnv/symbols_00401000.h"
struct PathingSearchRayCast
{
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_006e62b0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x006e6280
void* __thiscall PathingSearchRayCast::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_006e62b0_Class *>(this)->FUN_006e62b0_Class::~FUN_006e62b0_Class();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
