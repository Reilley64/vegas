
// src/fallout_shared/pathfinding/pathingrequest_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/pathfinding/pathingrequest.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSSimpleArray_PathingAvoidNode_1024.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_006a7910_shell.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_006d3ac0_Class.h"
#include "fnv/decl/FUN_006d3ae0.h"
#include "fnv/decl/FUN_006dc910_shell.h"
#include "fnv/decl/FUN_006e2980_shell.h"
#include "fnv/decl/FUN_006e29b0_Class.h"
#include "fnv/decl/FUN_006e3960.h"
#include "fnv/decl/FUN_006e39d0.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiPtr.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_006780e0__TESPackageExt.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011de000.h"
#include "pathingrequest_types_PathingRequest.h"
#include "pathingrequest_types_TESPackage.h"
#include "TESObjectREFR.h"
#include "pathingrequest_decls.h"

// sub ecx,0x10; jmp FUN_006e3880  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_006e3f20();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_006e3f20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x006e3f20
    virtual void FUN_006e3f20();
};

Derived::Derived()
{}
