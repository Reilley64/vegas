
// src/fallout_shared/bgsnote_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsnote.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005e8d40_shell.h"
#include "fnv/decl/FUN_005e9130_shell.h"
#include "fnv/decl/FUN_005e9270_shell.h"
#include "fnv/decl/FUN_005e92d0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_005b5000.h"
#include "bgsnote_decls.h"

// Adjustor thunk: the derived class inherits a virtual that is declared by a
// secondary base, so MSVC emits a this-adjusting thunk that moves `this` back
// to the primary sub-object (sizeof(NotePrimaryBase) == 0x30) before jumping
// to the implementation.
struct NotePrimaryBase
{
    virtual void FUN_005e9520();
    char unk04[0x2c];
};

struct NoteSecondaryBase
{
    virtual void FUN_005e9520();
};

struct NoteDerived : NotePrimaryBase, NoteSecondaryBase
{
    NoteDerived();
// @fnv 0x005e9520
    virtual void FUN_005e9520();
};

NoteDerived::NoteDerived()
{}
