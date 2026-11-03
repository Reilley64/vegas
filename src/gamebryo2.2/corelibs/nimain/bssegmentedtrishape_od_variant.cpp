
// src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/bssegmentedtrishape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstdint>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00a745c0_This.h"
#include "fnv/decl/S00a87040_Obj.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f5000.h"
void* __cdecl FUN_00a86fe0();
void __cdecl FUN_00a87120();
struct FUN_00a86ff0_shell
{
    void SetEntryActive(unsigned int index);
};

struct PointerSource
{
};

struct ScreenSize
{
};

struct HitRect
{
    int unk00;
    int extent;
    short left;
    short top;
    bool FUN_006fede0();
};

// @fnv 0x006fede0
bool HitRect::FUN_006fede0()
{
    intptr_t y;
    int x;
    x = ((int)(reinterpret_cast<::ActorMover *>(((*reinterpret_cast<::PointerSource * *>(&::g_TES))))->GetCurrentMoveModeType())) - (int)((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ScreenSize *>(&::g_011c63cc)))))) >> 1);
    y = ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::PointerSource * *>(&::g_TES))))->FUN_0045cd60())) - (int)((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ScreenSize *>(&::g_011c63cc)))))) >> 1);
    if (x + *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ScreenSize *>(&::g_011c63cc)))))) >= left && x <= left + extent && y + *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ScreenSize *>(&::g_011c63cc)))))) >= top &&
        y <= top + extent)
    {
        return true;
    }
    return false;
}
