// src/fallout/ai/gunwobble.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/gunwobble.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004f0110_Holder.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_01268000.h"
struct S_008d6a80_Obj
{
};
struct S_008d6a80_Holder
{
};

// Looks up the object named by DAT_011e00e0[idx] under root, resolves its holder via FUN_00653270 and passes DAT_011a9448 to FUN_004f0110.
// @fnv 0x008d6a80
void FUN_008d6a80(int iIndex, void* root)
{
    if ((*reinterpret_cast<void * (*)[]>(&::DAT_011e00e0))[iIndex])
    {
        S_008d6a80_Obj* obj = ((::S_008d6a80_Obj *)(::FUN_004aae30((::NiAVObject *)(root), (::NiFixedString *)((*reinterpret_cast<void * (*)[]>(&::DAT_011e00e0))[iIndex]))));
        if (obj)
        {
            S_008d6a80_Holder* holder = (S_008d6a80_Holder*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_012681cc))), (::NiObject *)(void *)(((void *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((obj))->FUN_006838b0()))))));
            if (holder)
                reinterpret_cast<::FUN_004f0110_Holder *>((holder))->FUN_004f0110((::FUN_004f0110_Data *)(void *)(&(*reinterpret_cast<char *>(&::DAT_011a9448))));
        }
    }
}

#include "generated/data/fallout/ai/gunwobble.inc"
