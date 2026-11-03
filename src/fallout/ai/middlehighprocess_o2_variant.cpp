
// src/fallout/ai/middlehighprocess_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/middlehighprocess.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_0092a000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c68000.h"
#include "middlehighprocess_decls.h"

struct C69FC0State
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
};
struct C69FC0Packet
{
    unsigned int status;
    unsigned char mode;
    unsigned int opcode;
    unsigned int selection;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
extern unsigned int DAT_011afebc;

static inline unsigned int C69FC0IsEnabled(int object)
{
    C69FC0State* pkState = ((::C69FC0State *)(::GetExtraDataChecked((::NiAVObjectX *)(object))));
    return pkState ? (pkState->flags & 2) : 0;
}

// @fnv 0x00c69fc0
bool __cdecl FUN_00c69fc0(int object, unsigned char bSelect, unsigned char mode, unsigned char overrideCheck)
{
    bool bResult = false;
    if (object)
    {
        if (overrideCheck || C69FC0IsEnabled(object))
        {
            bResult = true;
            C69FC0Packet kPacket;
            kPacket.status = 0;
            kPacket.mode = mode;
            kPacket.opcode = 0xd;
            kPacket.selection = bSelect != 0;
            if (DAT_011afebc)
                ::FUN_00c68900((::S_00c68900_Node *)(object), (::S_00c68900_Context *)(::C69FC0Packet *)(&kPacket), (void (*)(void *, S_00c68900_Context *))(DAT_011afebc));
        }
    }
    return bResult;
}
