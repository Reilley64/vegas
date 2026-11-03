
// src/fallout_shared/bgsplaceablewater_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsplaceablewater.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fc360_shell.h"
#include "fnv/decl/FUN_004fc3a0_shell.h"
#include "fnv/decl/FUN_004fc3c0_shell.h"
#include "fnv/decl/FUN_004fc3e0_shell.h"
#include "fnv/decl/FUN_004fc400_shell.h"
#include "fnv/decl/FUN_004fc470_shell.h"
#include "fnv/decl/FUN_004fc490_shell.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_00843170_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/HungerStageData.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004fc450__FUN_004fc450_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_011ca000.h"
#include "bgsplaceablewater_decls.h"
#include "bgsplaceablewater_types_BGSPlaceableWater.h"
#include <malloc.h>
struct FUN_004fc380_shell : public BGSPlaceableWater
{
    void FUN_004fc380(bool);
};
struct FUN_004fc990_t
{
    void __thiscall FUN_004fc990(int, bool);
};
struct FUN_004fc790_shell
{
    unsigned short m0;
    unsigned int m4;
    FUN_004fc790_shell* Reset();
};
struct FUN_004fc420_shell : public BGSPlaceableWater
{
    void FUN_004fc420(bool);
};
struct FUN_005e78f0_t
{
};
struct FUN_004fc860_shell : public BGSPlaceableWater
{
    void FUN_004fc860(TESForm* apCopy);
};

// sub ecx,0x30; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x30).
struct PrimaryBase
{
    virtual void FUN_004fcbf0();
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
    virtual void FUN_004fcbf0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fcbf0
    virtual void FUN_004fcbf0();
};

Derived::Derived()
{}
