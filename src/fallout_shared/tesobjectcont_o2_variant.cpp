
// src/fallout_shared/tesobjectcont_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectcont.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tesobjectcont_decls.h"
#include "tesobjectcont_types_TESObjectCONT.h"
#include "tesobjectcont_match_decls.h"
#include <new>
#include <string.h>

// FUN_005173d0 : 8-byte MSVC this-adjusting (adjustor) thunk.
//     sub ecx, 0x48 ; jmp <final overrider>
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot from two bases: the slot of the secondary base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, sizeof of
// the primary base) and tail-jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 17 int members (4 + 68 = 0x48 bytes).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct ContainerPrimaryBase
{
    virtual void FUN_005173d0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
};

struct ContainerSecondaryBase
{
    virtual void FUN_005173d0();
};

struct ContainerDerived : ContainerPrimaryBase, ContainerSecondaryBase
{
    ContainerDerived();
// @fnv 0x005173d0
    virtual void FUN_005173d0();
};

ContainerDerived::ContainerDerived()
{}
