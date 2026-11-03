
// src/fallout_shared/bgsaddonnode_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsaddonnode.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00512810_holder.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "bgsaddonnode_types_BGSAddonNode.h"
#include "bgsaddonnode_decls.h"
#include <malloc.h>
#include <string.h>

// sub ecx,0x30; jmp FUN_004f8b90  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x30).
// Derived overrides a virtual that both of its bases declare, so the second base's vtable slot
// holds a thunk that moves `this` back by the size of the first base (0x30) and tail-jumps to
// the final overrider. Only the constructor is defined, so the vtables (and the thunk) get emitted.
struct PrimaryBase
{
    virtual void FUN_004f93a0();
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
    virtual void FUN_004f93a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004f93a0
    virtual void FUN_004f93a0();
};

Derived::Derived()
{}
