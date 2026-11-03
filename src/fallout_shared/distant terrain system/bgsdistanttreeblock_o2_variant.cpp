
// src/fallout_shared/distant terrain system/bgsdistanttreeblock_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistanttreeblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_006f94a0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01200000.h"
struct NP
{
    NP& operator=(void*);
};
void FUN_006f7a60(void* p);
struct BGSDistantTreeBlockLoadTask
{
    void* Destroy(unsigned int flags);
};

extern unsigned int DAT_012007b8;

// @fnv 0x00bb6030
unsigned int __cdecl FUN_00bb6030()
{
    if (!DAT_012007b8)
        DAT_012007b8 = 40 + ((::DAT_011f91c0 < 2) ? 0 : 74);
    return DAT_012007b8;
}
