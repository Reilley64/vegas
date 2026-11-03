// fallout/ai/combat/combataction.cpp: CombatAction (12 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_009aadc0_cls.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WorldStateNode.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0108c000.h"
#include "fnv/symbols_011a4000.h"
#include "combataction_decls.h"

// Creates and returns a new CombatAction subclass instance matching the given COMBAT_ACTION type, warning and returning 0 for unknown types.
// @fnv 0x00979f90
CombatAction* CombatAction::CreateAction(COMBAT_ACTION type)
{
    switch (type)
    {
    case COMBAT_ACTION_ATTACK_RANGED:
        return new CombatActionAttackRanged(type);
    case COMBAT_ACTION_ATTACK_RANGED_FROM_COVER:
        return new CombatActionAttackRangedFromCover(type);
    case COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE:
        return new CombatActionAttackRangedExplosive(type);
    case COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE_FROM_COVER:
        return new CombatActionAttackRangedExplosiveFromCover(type);
    case COMBAT_ACTION_ATTACK_MELEE:
        return new CombatActionAttackMelee(type);
    case COMBAT_ACTION_ATTACK_HAND_TO_HAND:
        return new CombatActionAttackHandToHand(type);
    case COMBAT_ACTION_ATTACK_GRENADE:
        return new CombatActionAttackGrenade(type);
    case COMBAT_ACTION_ATTACK_GRENADE_FLUSH_TARGET:
        return new CombatActionAttackGrenadeFlushTarget(type);
    case COMBAT_ACTION_ATTACK_GRENADE_FROM_COVER:
        return new CombatActionAttackGrenadeFromCover(type);
    case COMBAT_ACTION_MOVE:
        return new CombatActionMove(type);
    case COMBAT_ACTION_MOVE_AND_SWITCH_TO_MELEE:
        return new CombatActionMoveAndSwitchToMelee(type);
    case COMBAT_ACTION_MOVE_AND_ATTACK_RANGED:
        return new CombatActionMoveAndAttackRanged(type);
    case COMBAT_ACTION_MOVE_AND_ATTACK_RANGED_EXPLOSIVE:
        return new CombatActionMoveAndAttackRangedExplosive(type);
    case COMBAT_ACTION_MOVE_AND_ATTACK_GRENADE:
        return new CombatActionMoveAndAttackGrenade(type);
    case COMBAT_ACTION_DRAW_WEAPON:
        return new CombatActionDrawWeapon(type);
    case COMBAT_ACTION_SWITCH_WEAPON:
        return new CombatActionSwitchWeapon(type);
    case COMBAT_ACTION_AVOID_THREAT:
        return new CombatActionAvoidThreat(type);
    case COMBAT_ACTION_SEARCH:
        return new CombatActionSearch(type);
    case COMBAT_ACTION_INVESTIGATE:
        return new CombatActionInvestigate(type);
    case COMBAT_ACTION_DODGE:
        return new CombatActionDodge(type);
    case COMBAT_ACTION_IGNORE_BLOCKED_TARGET:
        return new CombatActionIgnoreBlockedTarget(type);
    case COMBAT_ACTION_FLEE:
        return new CombatActionFlee(type);
    case COMBAT_ACTION_ACTIVATE_COMBAT_ITEM:
        return new CombatActionActivateCombatItem(type);
    case COMBAT_ACTION_USE_COMBAT_ITEM:
        return new CombatActionUseCombatItem(type);
    case COMBAT_ACTION_ACQUIRE_LINE_OF_SIGHT:
        return new CombatActionAcquireLineOfSight(type);
    case COMBAT_ACTION_HIDE:
        return new CombatActionHide(type);
    case COMBAT_ACTION_APPROACH_TARGET:
        return new CombatActionApproachTarget(type);
    default:
        ::FUN_005b5e40();
        return 0;
    }
}

struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};

struct BSThread
{
};

struct FUN_00979e20_shell
{
    char* GetCombatActionName();
};

// @fnv 0x00979e20
char* FUN_00979e20_shell::GetCombatActionName()
{
    return DAT_011a4280[reinterpret_cast<::ActorMover *>((reinterpret_cast<BSThread*>(this)))->GetCurrentMoveModeType()].pName;
}

namespace fnv_00979e40 {
struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};

struct BSThread
{
};

struct CombatController;

struct FUN_00979e40_shell
{
    float FUN_00979e40(CombatController* apCombatController, int aiActionValue);
};

// @fnv 0x00979e40
float FUN_00979e40_shell::FUN_00979e40(CombatController* apCombatController, int aiActionValue)
{
    return (*reinterpret_cast<fnv_00979e40::CombatActionEntry (*)[]>(&::DAT_011a4280))[reinterpret_cast<::ActorMover *>((reinterpret_cast<BSThread*>(this)))->GetCurrentMoveModeType()].m_fPathingCostCur;
}
}  // namespace fnv_00979e40

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

struct FUN_00979e60_shell
{
    void FUN_00979e60(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};

// @fnv 0x00979e60
void FUN_00979e60_shell::FUN_00979e60(char* apDebugText, unsigned int aiMaxLength, int aiActionValue)
{
    TaskQueueInterface::CopyStringToBuffer(apDebugText, aiMaxLength, reinterpret_cast<::FUN_00979e20_shell *>(this)->GetCombatActionName());
}

struct CombatController;
struct CombatStateArray
{
};
struct UnsignedIdHandle
{
    operator unsigned int() const;
};
struct B006815c0
{
};
struct CombatWorldStateListNext
{
};
struct TgtOps
{
};
struct FUN_005e3fc0_shell
{
    unsigned int Get();
};
struct FUN_00979f70_shell
{
    void FUN_00979f70(unsigned int);
};

struct FUN_00979e90_shell
{
    bool FUN_00979f50(int, int*);
    bool FUN_00979e90(CombatController* apCombatController, CombatStateArray* apWorldStateArray, int aiActionValue);
};

// @fnv 0x00979e90
bool FUN_00979e90_shell::FUN_00979e90(CombatController* apCombatController, CombatStateArray* apWorldStateArray,
                                      int aiActionValue)
{
    UnsignedIdHandle* pWorldState4;
    int iValue3;
    int _iCombatLocation;
    CombatWorldStateListNode* pList;

    pList = reinterpret_cast<CombatWorldStateListNode*>(((void *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<TgtOps*>(this)))->GetCurrentProcessData())));
    while (pList)
    {
        pWorldState4 = *((::UnsignedIdHandle **)(((::Vec3 *)(void *)(reinterpret_cast<B006815c0*>(pList)))));
        if (pWorldState4)
        {
            iValue3 = ((int)(reinterpret_cast<::Callees *>((pWorldState4))->FUN_00726070())) == -1 ? aiActionValue : ((int)(reinterpret_cast<::Callees *>((pWorldState4))->FUN_00726070()));
            if (!((bool)(reinterpret_cast<::FUN_009aadc0_cls *>((apWorldStateArray))->FUN_009aadc0(*pWorldState4, iValue3))))
                return false;
        }
        pList = reinterpret_cast<::CombatWorldStateListNode *>((reinterpret_cast<CombatWorldStateListNext*>(pList)))->GetNext();
    }
    _iCombatLocation = -1;
    if (FUN_00979f50(1, &_iCombatLocation))
        reinterpret_cast<FUN_00979f70_shell*>(reinterpret_cast<FUN_005e3fc0_shell*>(apCombatController)->Get())
            ->FUN_00979f70(_iCombatLocation);
    return true;
}

struct FUN_009aa410_shell
{
};

struct FUN_00979f50_shell
{
    void FUN_00979f50(int a, intptr_t b);
};

// Calls FindStateByType on the object at offset 0xc of this, passing a and b through.
// @fnv 0x00979f50
void FUN_00979f50_shell::FUN_00979f50(int aiArg1, intptr_t aiArg2)
{
    reinterpret_cast<::WorldStateNode *>((reinterpret_cast<FUN_009aa410_shell*>(reinterpret_cast<char*>(this) + 0xc)))->FindStateByType(aiArg1, (unsigned int *)(aiArg2));
}

namespace fnv_00979f70 {
struct QuantityData
{
};

struct FUN_00979f70_shell
{
    void FUN_00979f70(unsigned int aiQuantity);
};

// @fnv 0x00979f70
void FUN_00979f70_shell::FUN_00979f70(unsigned int aiQuantity)
{
    reinterpret_cast<::FUN_00537e90 *>(((*reinterpret_cast<QuantityData**>(reinterpret_cast<char*>(this) + 4))))->SetQuantity(aiQuantity);
}
}  // namespace fnv_00979f70

namespace fnv_0097abd0 {

struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};

// @fnv 0x0097abd0
bool FUN_0097abd0(char* apCombatActionName, float afCost)
{
    for (unsigned int i = 0; i < 0x1b; i++)
    {
        if (!::FUN_00404dc0((*reinterpret_cast<fnv_0097abd0::CombatActionEntry (*)[]>(&::DAT_011a4280))[i].pName, apCombatActionName))
        {
            (*reinterpret_cast<fnv_0097abd0::CombatActionEntry (*)[]>(&::DAT_011a4280))[i].m_fPathingCostCur = afCost;
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0097abd0

struct CombatController;
struct FUN_009cdac0_shell
{
    float GetField60Float();
};
struct CombatState : FUN_009cdac0_shell
{
    float FUN_0097ac90(int);
};
struct IMH
{
};
extern float DAT_0108ca80;

// Gets the combat state's attack DPS for a weapon type and returns the default value if zero, otherwise the max attack DPS minus it.
// @fnv 0x0097ac30
float GetWeaponDPSDeficit(CombatController* apCombatController, int aeWeaponType)
{
    float fattackDPS;
    CombatState* pcombatState;
    float fmaxAttackDPS;

    pcombatState = ((::CombatState *)(reinterpret_cast<::InterfaceManager *>((reinterpret_cast<IMH*>(apCombatController)))->FUN_00586150()));
    fattackDPS = pcombatState->FUN_0097ac90(aeWeaponType);
    if (fattackDPS == ::_DAT_01012060)
        return DAT_0108ca80;
    fmaxAttackDPS = pcombatState->GetField60Float();
    return fmaxAttackDPS - fattackDPS;
}

struct FUN_0097ac90_shell
{
    float FUN_0097ac90(int aiIndex);
};

// @fnv 0x0097ac90
float FUN_0097ac90_shell::FUN_0097ac90(int aiIndex)
{
    return reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x3c)[aiIndex];
}

struct CombatController;
struct CoordinateTriple
{
    double FUN_00527a40(CoordinateTriple*);
};

// @fnv 0x0097acb0
float FUN_0097acb0(CombatController* apCombatController, CoordinateTriple* arStartWorldLoc,
                   CoordinateTriple* arEndWorldLoc)
{
    float fmovementCost;

    fmovementCost = arStartWorldLoc->FUN_00527a40(arEndWorldLoc) / DAT_0108cb08;
    fmovementCost = FUN_0040ebd0(fmovementCost, DAT_0108cb00);
    fmovementCost = FUN_00404010(fmovementCost, 0.01f);
    return fmovementCost;
}

extern int DAT_0108cab8;

struct CondS
{
    int data[2];
    CondS();
    ~CondS();
};

struct FUN_00979bd0
{
    virtual void vfunc();
    CondS cond0;
    CondS cond1;
    CondS cond2;
    CondS cond3;
    int aeType;
    int iFlags;

    FUN_00979bd0(int aeType);
};

// Stores the type argument in aeType and copies iFlags from the global type table entry at that index.
// @fnv 0x00979bd0
FUN_00979bd0::FUN_00979bd0(int a)
{
    aeType = a;
    iFlags = DAT_011a4280[aeType].iFlags;
}

#include "generated/data/fallout/ai/combat/combataction.inc"
