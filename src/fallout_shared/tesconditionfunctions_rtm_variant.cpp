
// src/fallout_shared/tesconditionfunctions_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesconditionfunctions.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
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
#include "tesconditionfunctions_conditionfn_MobileObject.h"
#include "tesconditionfunctions_conditionfn_low_Script.h"
#include "tesconditionfunctions_conditionfn_class_faction.h"
#include "tesconditionfunctions_conditionfn_dep_TESQuest.h"
#include "tesconditionfunctions_conditionfn_BGSQuestObjective.h"
#include "tesconditionfunctions_packet.h"
#include "tesconditionfunctions_conditionfn_dep_TESObjectREFR.h"
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

namespace s59e490 {


void FUN_00703c00(const char* pcFormat, ...);

struct Quest
{
};

static const char s_szGetStageDoneFormat[] = "GetStageDone >> %0.2f";

// @fnv 0x0059e490
bool FUN_0059e490(void* pvThisObj, Quest* pkQuestArg, unsigned int uiStage, double* pdResult)
{
    Quest* pkQuest;
    unsigned int uiStageIndex;

    *pdResult = 0.0;
    pkQuest = pkQuestArg ? pkQuestArg : 0;
    uiStageIndex = uiStage;
    if (pkQuest && reinterpret_cast<::TESQuest *>((pkQuest))->HasStage((unsigned char)uiStageIndex))
        *pdResult = 1.0;
    if (::bConditionFunctionDebug)
        FUN_00703c00(s_szGetStageDoneFormat, *pdResult);
    return true;
}

}
