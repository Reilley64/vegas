
// src/fallout_shared/tesobjectmisc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectmisc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e9b0__TESValueForm.h"
#include "fnv/decl/fnv_0048e9e0__TESValueForm.h"
#include "fnv/decl/fnv_0048ea10__TESValueForm.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tesobjectmisc_decls.h"
#include <malloc.h>
extern const char DAT_0102b038[];
struct FUN_0051b070_shell
{
    void FUN_0051b070(unsigned int aiFlags);
};
struct FUN_00484bf0
{
};
struct FUN_0048e9b0
{
};
struct FUN_0051b020_shell
{
    unsigned short __thiscall FUN_0051b020(unsigned int aiFlags);
};
struct TESFormStub
{
};
struct TESValueFormStub
{
};
struct BGSLoadFormBuffer;
struct FUN_0051b0a0_shell
{
    void LoadForm(unsigned int aiFlags, BGSLoadFormBuffer* apLoadGameBuffer);
};

// MSVC adjustor thunk: the primary base occupies 0x3c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0051b130();
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

struct SecondaryBase
{
    virtual void FUN_0051b130();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0051b130
    virtual void FUN_0051b130();
};

Derived::Derived()
{}
