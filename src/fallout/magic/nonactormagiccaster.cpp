// src/fallout/magic/nonactormagiccaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/nonactormagiccaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00825b60.h"
#include "fnv/symbols_00401000.h"

struct FUN_00825aa0_shell
{
    void FUN_00825b60();
    void* FUN_00825aa0(unsigned int flags);
};

// Calls FUN_00825b60, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00825aa0
void* FUN_00825aa0_shell::FUN_00825aa0(unsigned int flags)
{
    reinterpret_cast<::FUN_00825b60 *>(this)->FUN_00825b60::~FUN_00825b60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
