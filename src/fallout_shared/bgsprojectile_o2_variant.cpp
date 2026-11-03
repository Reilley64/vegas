
// src/fallout_shared/bgsprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_004078a0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fcc20_shell.h"
#include "fnv/decl/FUN_004fccf0_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_004fd3a0_shell.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_004ea000.h"
#include "fnv/symbols_004fd000.h"
#include "bgsprojectile_decls.h"

// Adjustor thunk for FUN_004fe250: "sub ecx, 0x3c; jmp DestroyIfFlagged".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function that a
// class inherits from a secondary base: the thunk converts the secondary base
// sub-object pointer (this + 0x3c) back into the derived object pointer
// (sub ecx, 0x3c) and then tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 14 int members (4 + 14 * 4 = 0x3c
// bytes).  Both bases declare the same virtual function, the derived class
// redeclares it and defines only its constructor, which is what makes the
// compiler emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_004fe250();
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
    virtual void FUN_004fe250();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fe250
    virtual void FUN_004fe250();
};

Derived::Derived()
{}
