
// src/fallout_shared/havok/teswaterlistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teswaterlistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00563200_Struct.h"
#include "fnv/decl/FUN_0062e860_cls.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/OwnerC9Body.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_00631000.h"
#include "fnv/symbols_011c7000.h"
struct FUN_0062e750_shell
{
    void* __thiscall FUN_0062e750(unsigned int flags);
};
extern int DAT_011c7a3c;
extern unsigned char DAT_011c7a5a;
void FUN_0062f8e0(unsigned char value);
struct BSOcclusionPlane
{
};
struct ExtraDataList
{
};
struct BSThread
{
};
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane);
extern "C" float __cdecl ExpFloat(float);
float FUN_00630aa0(float value);
extern "C" double __cdecl _exp(double);
float ExpFloat(float value);
extern float _gModifierZero;
struct FUN_005631e0_shell
{
    bool __thiscall IsNonZero(int a);
};
struct FUN_0062e710_shell
{
    void __thiscall SetValueAt(float f, int a, int b);
};
struct BSSimpleList_Ragdoll
{
    void* __thiscall FUN_006310e0();
};
struct TESDataHandler
{
};
struct FUN_006310c0_shell
{
    void __thiscall FUN_006310c0();
};

struct FUN_00c9a460_shell
{
    void __thiscall FUN_00c9a600(int a);
};

// @fnv 0x00c9a600
void __thiscall FUN_00c9a460_shell::FUN_00c9a600(int a)
{
    int r = ((int(__thiscall*)(void*, int))(*reinterpret_cast<void***>(this))[9])(this, a);
    reinterpret_cast<::OwnerC9Body *>(this)->AddObject((::RefObjectC9 *)(r));
}
