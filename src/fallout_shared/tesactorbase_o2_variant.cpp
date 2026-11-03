
// src/fallout_shared/tesactorbase_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesactorbase.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0047e340_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0096bbc0_cls.h"
#include "fnv/decl/TESActorBaseData47E.h"
#include "fnv/decl/TESSpellList.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0047f980__FUN_0047f980_Class.h"
#include "fnv/decl/fnv_004802b0__FUN_004802b0_Class.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_005d8000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "tesactorbase_decls.h"

// 005fbfa0 = VC9 adjustor thunk. Recipe (b90180 class of matches): MI dual-slot override,
// the virtual METHOD named after the claim token FUN_005fbfa0, declared only (never defined)
// so the emitted [thunk] COMDAT is the unique defined symbol carrying the token, and
// fnvcheck binds its jmp target from the original bytes.

struct ThunkPrim
{
    virtual void* FUN_005fbfa0(unsigned int);
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    int p34;
    int p38;
    int p3c;
    int p40;
    int p44;
    int p48;
    int p4c;
    int p50;
    int p54;
    int p58;
    int p5c;
    int p60;
    int p64;
    int p68;
    int p6c;
    int p70;
    int p74;
    int p78;
    int p7c;
    int p80;
    int p84;
    int p88;
    int p8c;
    int p90;
    int p94;
    int p98;
    int p9c;
    int pa0;
    int pa4;
    int pa8;
    int pac;
    int pb0;
    int pb4;
    int pb8;
    int pbc;
    int pc0;
    int pc4;
    int pc8;
    int pcc;
    int pd0;
    int pd4;
    int pd8;
};

struct ThunkSec
{
    virtual void* FUN_005fbfa0(unsigned int);
};

struct ThunkHost : ThunkPrim, ThunkSec
{
// @fnv 0x005fbfa0
    virtual void* FUN_005fbfa0(unsigned int);
};

static ThunkHost g_thunk;
