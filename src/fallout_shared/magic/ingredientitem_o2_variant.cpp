
// src/fallout_shared/magic/ingredientitem_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/magic/ingredientitem.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "ingredientitem.h"
struct FUN_00409a30_shell
{
    bool FUN_00409a30(unsigned int aFlag);
};
struct BipedModelForm
{
};
struct FUN_0040a0f0_shell : BipedModelForm
{
    void __thiscall EndianAtOffset9C(void);
};

// sub ecx,0x30; jmp <target>  ==  MSVC adjustor thunk for a second base.
// PrimaryBase is vptr + 11 ints = 0x30 bytes. The shared virtual is named after the claim.
struct PrimaryBase
{
    virtual void FUN_0040a120();
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
};

struct SecondaryBase
{
    virtual void FUN_0040a120();
};

struct AdjustedDerived : PrimaryBase, SecondaryBase
{
    AdjustedDerived();
// @fnv 0x0040a120
    virtual void FUN_0040a120();
};

AdjustedDerived::AdjustedDerived()
{}
