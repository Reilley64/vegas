
// src/fallout_shared/tesobjectacti_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectacti.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FloatValueProvider.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_01011000.h"
#include "tesobjectacti_load.h"
#include <malloc.h>

// Adjustor thunk.
//
// The most derived form class inherits two different base sub-objects that
// both provide the same virtual slot (FUN_00511940).  One of those bases sits
// 0x3C bytes into the complete object, so the entry stored in that base's
// vtable slot has to move `this` back by 0x3C before it can jump to the
// implementation that expects the complete object pointer.
//
// MSVC emits such a thunk as
//     sub ecx, 0x3C
//     jmp <implementation>

// First base of the complete object: 0x3C bytes long (vtable pointer plus the
// state that precedes the second base sub-object).
struct ThunkPrimary
{
    virtual void FUN_00511940();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

// Second base of the complete object, placed at offset 0x3C.
struct ThunkSecondary
{
    virtual void FUN_00511940();
};

// Complete object: the virtual is overridden here, so the vtable slot of the
// second base needs a `this` adjusting thunk.
struct ThunkDerived : public ThunkPrimary, public ThunkSecondary
{
// @fnv 0x00511940
    virtual void FUN_00511940();
    ThunkDerived();
};

ThunkDerived::ThunkDerived()
{}
