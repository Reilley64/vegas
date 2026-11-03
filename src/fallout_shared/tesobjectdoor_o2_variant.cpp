
// src/fallout_shared/tesobjectdoor_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectdoor.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005194d0_shell_base.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00575770_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00518000.h"
#include "fnv/symbols_00573000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00871000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "tesobjectdoor_decls.h"

// Adjustor thunk: sub ecx,0x3c; jmp FUN_005174d0
// Both bases declare the same virtual; Derived overrides it, so the compiler
// emits a this-adjusting thunk in Derived's vtable for the secondary base.
struct PrimaryBase
{
    virtual void FUN_00519cb0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
};

struct SecondaryBase
{
    virtual void FUN_00519cb0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00519cb0
    virtual void FUN_00519cb0();
};

Derived::Derived()
{}
