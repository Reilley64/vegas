
// src/fallout_shared/tesammo_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesammo.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00502cb0_shell.h"
#include "fnv/decl/FUN_00503240_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0097a000.h"
#include "tesammo_load.h"
#include <malloc.h>
#include <string.h>

// The claimed function is a compiler-generated this-adjusting thunk:
//     sub ecx, 0x3c
//     jmp  <the most derived class' implementation of the virtual>
// MSVC emits it for the second copy of a duplicated common base: the most
// derived class inherits the same common base twice, so the vtable slot of
// the second copy has to move `this` back onto the first copy.
class ThunkCommonBase
{
  public:
    virtual void FUN_00503bb0();
};

class ThunkPrimaryBase : public ThunkCommonBase
{
  public:
    int m_pad01[14];
};

class ThunkSecondaryBase : public ThunkCommonBase
{
  public:
};

class ThunkDerived : public ThunkPrimaryBase, public ThunkSecondaryBase
{
  public:
// @fnv 0x00503bb0
    virtual void FUN_00503bb0();
    ThunkDerived();
};

ThunkDerived::ThunkDerived()
{}

ThunkDerived g_thunkDerived;
