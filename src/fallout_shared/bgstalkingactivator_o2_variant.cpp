
// src/fallout_shared/bgstalkingactivator_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgstalkingactivator.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_004011d0_shell.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0056b190__FUN_0056b190_shell.h"
#include "fnv/decl/fnv_0056b210__FUN_0056b210_shell.h"
#include "fnv/decl/fnv_00572380__Fn572380.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0056b000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_011c8000.h"
#include "bgstalkingactivator.h"
#include <malloc.h>
static const char s_kTalkingVoiceTypeWarning[] =
    "MASTERFILE: Could not find voice type (%08X) for activator '%s' (%08X).";
#include "bgstalkingactivator_radio.h"
#include "bgstalkingactivator_load.h"

// Adjustor thunk for FUN_004ffa90: "sub ecx, 0x3c; jmp FUN_004fe6e0".
//
// MSVC "this adjusting thunk" emitted for a virtual function inherited from a
// secondary base: the thunk converts the secondary base sub-object pointer
// (this + 0x3c) back into the derived object pointer (sub ecx, 0x3c) and then
// tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 14 int members (4 + 14 * 4 = 0x3c).
// Both bases declare the same virtual, the derived class redeclares it and
// defines only its constructor, which is what makes the compiler emit the
// vtables and the adjusting thunk.
struct AdjustorPrimary
{
    virtual void FUN_004ffa90();
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

struct AdjustorSecondary
{
    virtual void FUN_004ffa90();
};

struct AdjustorDerived : AdjustorPrimary, AdjustorSecondary
{
    AdjustorDerived();
// @fnv 0x004ffa90
    virtual void FUN_004ffa90();
};

AdjustorDerived::AdjustorDerived()
{}
