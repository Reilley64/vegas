
// src/fallout/ai/combat/combatplanner.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatplanner.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/BGSDebris.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/CombatWorldStateListNode.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_00984470_Class.h"
#include "fnv/decl/FUN_00994250_shell.h"
#include "fnv/decl/FUN_009947f0_Class.h"
#include "fnv/decl/FUN_00994ea0_class.h"
#include "fnv/decl/FUN_009aadc0_cls.h"
#include "fnv/decl/FUN_009aae10_Class.h"
#include "fnv/decl/FUN_00aa54a0_s.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_009957c0__FUN_009957c0_Class.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00994000.h"
#include "fnv/symbols_00995000.h"
#include "fnv/symbols_010a2000.h"
struct AStarNodeData
{
    int m_iNodeIndex;
};
struct AStarNode
{
    int m_i;
    int m_iUnknownValue;
    AStarNodeData* m_p;
};
struct CombatPlanner
{
    bool FUN_00995800(const AStarNode* p);
};
// Returns true when the int at offset 0xdc of the node's m_p is zero, otherwise false.
// @fnv 0x00995800
bool CombatPlanner::FUN_00995800(const AStarNode* apNode)
{
    if (*(const int*)((const char*)apNode->m_p + 0xdc) == 0)
        return true;
    return false;
}


extern const float DAT_0108dbf0;  // FLT_MAX

struct CPScrapHeap
{
    int unk00;
};

class CPTarget;

class CPCond
{
  public:
    int iKey;
    int iValue;
};

struct CPCondList
{
    CPCond* m_pkItem;
    CPCondList* m_pkNext;
};

struct CPEntry
{
    CPCond* m_pkCond;
    void* m_pAssociatedData;
};

class CPNodeData
{
  public:
    int unk00[23];
    CPEntry m_aEntries[16];       // +0x5c
    unsigned int m_uiNumEntries;  // +0xdc
};

class CPNode
{
  public:
    float m_fCost;
    int unk04;
    CPNodeData* m_pUserData;
};

struct CPWorldState
{
    int unk00[23];
};

class CPGoals
{
  public:
};

class CPOwner
{
  public:
};

class CPAction
{
  public:
    virtual bool IsValid(CPOwner* pkOwner, CPWorldState* pkState, CPTarget* pkTarget);
    virtual void v01();
    virtual void v02();
    virtual float GetCost(CPOwner* pkOwner, CPTarget* pkTarget);

};

struct CPActionList
{
    CPAction* m_pkItem;
    CPActionList* m_pkNext;
};


class FUN_00995760_Aim
{
  public:
    int m_iValue;
    FUN_00995760_Aim();
};

class FUN_004b0680_Pair
{
  public:
    int m_iKey;
    int m_iNext;
    FUN_004b0680_Pair(int iItem, int iNext);
};

class FUN_00994e60_State
{
  public:
    int unk00[57];
    FUN_00994e60_State(CPWorldState* pkState);
};

class FUN_00995780_Plan
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iAim;
    FUN_00995780_Plan(CPAction* pkAction, CPTarget* pkTarget, void* pvValue);
};

struct CPOutItem
{
    int unk00;
    float m_fCost;
    FUN_00994e60_State* m_pkState;
    FUN_00995780_Plan* m_pkPlan;
};

class CPOutArray
{
  public:
};

class CPPlanner
{
  public:
    int unk0000[0x816];
    CPOwner* m_pkOwnerManager;   // +0x2058
    CPWorldState m_kWorldState;  // +0x205c
    CPScrapHeap m_kHeap;         // +0x20b8

    int FUN_009950a0(FUN_00994e60_State** ppkState);
    int FUN_006b8fe0(int iState, float m_fPathingCostCur, CPOutItem** ppkItem);
    bool ExpandNode(CPNode* pkNode, CPOutArray* pkOut);
};

// @fnv 0x009950c0
bool CPPlanner::ExpandNode(CPNode* pkNode, CPOutArray* pkOut)
{
    float m_fPathingCostCur = pkNode->m_fCost;
    bool bFirst = (((::CPNode *)(reinterpret_cast<::MagicCaster_shell *>((pkNode))->FUN_0044edb0())) == 0) ? true : false;
    if (bFirst)
        reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>((pkOut))->FUN_0084b5c0(0x10);

    for (unsigned int i = 0; i < pkNode->m_pUserData->m_uiNumEntries; i++)
    {
        CPCond* pkCond = pkNode->m_pUserData->m_aEntries[i].m_pkCond;
        CPActionList* pkNodeIter = ((::CPActionList *)(::FUN_009957f0(pkCond->iKey)));
        bool bFound = false;
        while (pkNodeIter && *((::CPAction **)(((::Vec3 *)(void *)(pkNodeIter)))))
        {
            CPAction* pkAction = *((::CPAction **)(((::Vec3 *)(void *)(pkNodeIter))));
            if (!reinterpret_cast<::FUN_00994250_shell *>((pkAction))->HasFlags(true) || bFirst)
            {
                bool bValid = reinterpret_cast<::fnv_009957c0::FUN_009957c0_Class *>((pkAction))->FUN_009957c0((::BSSimpleList<int> *)(pkCond));
                CPTarget* pkTarget = ((::CPTarget *)(intptr_t)pkCond->iValue);
                if (::IsValidCode((intptr_t)(pkTarget)))
                    pkTarget = ((::CPTarget *)(reinterpret_cast<::FUN_00984470_Class *>((pkNode->m_pUserData))->GetCombatGoal((intptr_t)(pkTarget))));
                FUN_00995760_Aim kAim;
                (*reinterpret_cast<::CombatProcedure **>(reinterpret_cast<char *>(m_pkOwnerManager) + 0xa4))->Initialize((::CombatController *)(::FUN_00995760_Aim *)(&kAim));
                if (bValid)
                {
                    if (pkAction->IsValid(m_pkOwnerManager, &m_kWorldState, pkTarget))
                    {
                        float fActionCost = pkAction->GetCost(m_pkOwnerManager, pkTarget);
                        if (fActionCost < DAT_0108dbf0)
                        {
                            FUN_00994e60_State* pkState =
                                new (reinterpret_cast<::FUN_00aa54a0_s *>(&(m_kHeap))->FUN_00aa54a0(sizeof(FUN_00994e60_State), DAT_010a2720))
                                    FUN_00994e60_State(&m_kWorldState);

                            CPCondList* pkEffect = ((::CPCondList *)(reinterpret_cast<::NonActorMagicTarget *>((pkAction))->GetActiveEffectList()));
                            while (pkEffect && *((::CPCond **)(((::Vec3 *)(void *)(pkEffect)))))
                            {
                                CPCond* pkEffectCond = *((::CPCond **)(((::Vec3 *)(void *)(pkEffect))));
                                int iCondValue = reinterpret_cast<::FUN_009947f0_Class *>((pkState))->FUN_009947f0(pkEffectCond->iValue, (intptr_t)(pkTarget));
                                reinterpret_cast<::FUN_009aae10_Class *>((pkState))->FUN_009aae10(pkEffectCond->iKey, iCondValue);
                                pkEffect = ((::CPCondList *)(reinterpret_cast<::CombatWorldStateListNode *>((pkEffect))->GetNext()));
                            }

                            CPCondList* pkSide = ((::CPCondList *)(reinterpret_cast<::BGSDebris *>((pkAction))->GetDataList()));
                            while (pkSide && *((::CPCond **)(((::Vec3 *)(void *)(pkSide)))))
                            {
                                CPCond* pkSideCond = *((::CPCond **)(((::Vec3 *)(void *)(pkSide))));
                                int iCondValue = reinterpret_cast<::FUN_009947f0_Class *>((pkState))->FUN_009947f0(pkSideCond->iValue, (intptr_t)(pkTarget));
                                reinterpret_cast<::FUN_009aae10_Class *>((pkState))->FUN_009aae10(pkSideCond->iKey, iCondValue);
                                pkSide = ((::CPCondList *)(reinterpret_cast<::CombatWorldStateListNode *>((pkSide))->GetNext()));
                            }

                            for (unsigned int j = 0; j < pkNode->m_pUserData->m_uiNumEntries; j++)
                            {
                                CPCond* pkGoalCond = pkNode->m_pUserData->m_aEntries[j].m_pkCond;
                                int iCondValue = reinterpret_cast<::FUN_009947f0_Class *>((pkState))->FUN_009947f0(pkGoalCond->iValue, (intptr_t)(pkTarget));
                                if (!((bool)(reinterpret_cast<::FUN_009aadc0_cls *>((pkState))->FUN_009aadc0(pkGoalCond->iKey, iCondValue))))
                                    reinterpret_cast<::FUN_00994ea0_class *>((pkState))->AppendPair(
                                        (intptr_t)(new (reinterpret_cast<::FUN_00aa54a0_s *>(&(m_kHeap))->FUN_00aa54a0(sizeof(FUN_004b0680_Pair), DAT_010a2720))
                                            FUN_004b0680_Pair(pkGoalCond->iKey, iCondValue)),
                                        (intptr_t)(pkNode->m_pUserData->m_aEntries[j].m_pAssociatedData));
                            }

                            CPCondList* pkRequire = ((::CPCondList *)(::GetOffsetC((intptr_t)(pkAction))));
                            while (pkRequire && *((::CPCond **)(((::Vec3 *)(void *)(pkRequire)))))
                            {
                                CPCond* pkPreCond = *((::CPCond **)(((::Vec3 *)(void *)(pkRequire))));
                                int iCondValue = reinterpret_cast<::FUN_009947f0_Class *>((pkState))->FUN_009947f0(pkPreCond->iValue, (intptr_t)(pkTarget));
                                if (!((bool)(reinterpret_cast<::FUN_009aadc0_cls *>((pkState))->FUN_009aadc0(pkPreCond->iKey, iCondValue))))
                                    reinterpret_cast<::FUN_00994ea0_class *>((pkState))->AppendPair(
                                        (intptr_t)(new (reinterpret_cast<::FUN_00aa54a0_s *>(&(m_kHeap))->FUN_00aa54a0(sizeof(FUN_004b0680_Pair), DAT_010a2720))
                                            FUN_004b0680_Pair(pkPreCond->iKey, iCondValue)),
                                        (intptr_t)(pkState));
                                pkRequire = ((::CPCondList *)(reinterpret_cast<::CombatWorldStateListNode *>((pkRequire))->GetNext()));
                            }

                            fActionCost += m_fPathingCostCur;
                            bFound = true;
                            int iState = FUN_009950a0(&pkState);
                            CPOutItem* pkResult;
                            switch (FUN_006b8fe0(iState, fActionCost, &pkResult))
                            {
                            case 0:
                                pkResult->m_pkState = pkState;
                                pkResult->m_fCost = 0.0f;
                            case 1: {
                                FUN_00995780_Plan* pkPlan =
                                    new (reinterpret_cast<::FUN_00aa54a0_s *>(&(m_kHeap))->FUN_00aa54a0(sizeof(FUN_00995780_Plan), DAT_010a2720))
                                        FUN_00995780_Plan(pkAction, pkTarget,
                                                          pkNode->m_pUserData->m_aEntries[i].m_pAssociatedData);
                                pkPlan->m_iAim = kAim.m_iValue;
                                pkResult->m_pkPlan = pkPlan;
                                reinterpret_cast<::FUN_00438690 *>((pkOut))->FUN_007cb2e0((unsigned int *)&(pkResult));
                            }
                            break;
                            }
                        }
                    }
                }
            }
            pkNodeIter = pkNodeIter->m_pkNext;
        }
        if (!bFound)
        {
            reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((pkOut))->Clear(false);
            return false;
        }
    }
    return true;
}

#include "generated/data/fallout/ai/combat/combatplanner.inc"
