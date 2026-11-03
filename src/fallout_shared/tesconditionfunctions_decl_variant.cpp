
// src/fallout_shared/tesconditionfunctions_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0059c010: the skeleton of src/fallout_shared/tesconditionfunctions.cpp
// with declarations corrected to what the original code does (tesconditionfunctions_conditionfn_dep_layout_support.h: TESObjectCELL += void* FUN_00546c20();; tesconditionfunctions_conditionfn_dep_TESObjectREFR.h: TESObjectREFR += class TESWorldSpace* FUN_00575d70();). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_0061af10_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_008a5270_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFaction_RankDataView.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0059f000.h"
#include "fnv/symbols_005a3000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01272000.h"
#include "tesconditionfunctions_conditionfn_MobileObject_decl_tesconditionfunctions.h"
#include "tesconditionfunctions_conditionfn_low_Script.h"
#include "tesconditionfunctions_conditionfn_class_faction.h"
#include "tesconditionfunctions_conditionfn_dep_TESQuest.h"
#include "tesconditionfunctions_conditionfn_BGSQuestObjective.h"
#include "tesconditionfunctions_packet.h"
#include "tesconditionfunctions_conditionfn_dep_TESObjectREFR_decl_tesconditionfunctions.h"
class PlayerCharacter;
struct PlayerCharacterMovingStateView
{
    unsigned char padding[0x20c];
    unsigned char movingIntoNewSpace;
};
class Actor
{
  public:
};

void __cdecl DebugLog(char const*, ...);
class TESWorldSpace
{
  public:
};
// @fnv 0x0059c010
bool __cdecl FUN_0059c010(TESObjectREFR* reference, void* parameter, void* unused, double& result)
{
    result = 0.0;
    void* zone = parameter;
    if (reference && zone)
    {
        void* found = 0;
        TESObjectCELL* cell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget()));
        if (cell)
            found = ((void *)(cell->FindEncounterZone()));
        if (!found)
        {
            TESWorldSpace* world = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((reference))->FUN_00575d70()));
            if (world)
                found = ((void *)(reinterpret_cast<::FUN_00458400_cls *>((world))->GetFieldD0()));
        }
        if (found == zone)
            result = 1.0;
    }
    if (::bConditionFunctionDebug)
        DebugLog("GetInZone >> %0.2f", result);
    return true;
}
