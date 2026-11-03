
// src/fallout_shared/tesobjectanio_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectanio.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00511a10_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "tesobjectanio_decls.h"
struct SFTX
{
};
struct B2_4fe
{
    B2_4fe();
    virtual ~B2_4fe();
    unsigned char pad[0x1c];
};
struct FUN_00511950 : public TESForm, public B2_4fe
{
    int pAnim;
    FUN_00511950();
    virtual ~FUN_00511950();
};
void operator delete(void*);
struct FUN_005119e0_obj
{
    void* Destroy(unsigned int flags);
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct S_0048a520
{
};
struct _ref_0084e3a0_t
{
};
struct FUN_00511d10_shell
{
    void FUN_00511d10();
};

// sub ecx,0x18; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x18).
struct PrimaryBase
{
    virtual void FUN_00511e30();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase
{
    virtual void FUN_00511e30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00511e30
    virtual void FUN_00511e30();
};

Derived::Derived()
{}
