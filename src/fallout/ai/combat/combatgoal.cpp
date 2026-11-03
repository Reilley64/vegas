// fallout/ai/combat/combatgoal.cpp: CombatGoal (22 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CombatAction.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00984290.h"
#include "fnv/decl/FUN_00984390_shell.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011f1000.h"
#include "combatgoal.h"

// Creates and returns a new CombatGoal subclass instance matching eType, or warns and returns 0 for an unknown type.
// @fnv 0x00984490
CombatGoal* CombatGoal::CreateGoal(CombatGoal::COMBAT_GOAL eType)
{
    switch (eType)
    {
    case COMBAT_GOAL_KILL_TARGET:
        return new CombatGoalKillTarget(eType);
    case COMBAT_GOAL_FIND_TARGET:
        return new CombatGoalFindTarget(eType);
    case COMBAT_GOAL_AVOID_THREATS:
        return new CombatGoalAvoidThreats(eType);
    case COMBAT_GOAL_FLEE:
        return new CombatGoalFlee(eType);
    case COMBAT_GOAL_ACTIVATE_COMBAT_ITEM:
        return new CombatGoalActivateCombatItem(eType);
    case COMBAT_GOAL_USE_COMBAT_ITEM:
        return new CombatGoalUseCombatItem(eType);
    case COMBAT_GOAL_FLANK:
        return new CombatGoalFlank(eType);
    case COMBAT_GOAL_FALLBACK:
        return new CombatGoalFallBack(eType);
    case COMBAT_GOAL_AMBUSH:
        return new CombatGoalAmbush(eType);
    case COMBAT_GOAL_REACH_DESTINATION:
        return new CombatGoalReachDestination(eType);
    case COMBAT_GOAL_ADVANCE:
        return new CombatGoalAdvance(eType);
    case COMBAT_GOAL_GUARD:
        return new CombatGoalGuard(eType);
    case COMBAT_GOAL_CLUSTER:
        return new CombatGoalCluster(eType);
    case COMBAT_GOAL_HIDE_FROM_TARGET:
        return new CombatGoalHideFromTarget(eType);
    case COMBAT_GOAL_FLUSH_TARGET:
        return new CombatGoalFlushTarget(eType);
    case COMBAT_GOAL_STAY_IN_COMBAT_AREA:
        return new CombatGoalStayInCombatArea(eType);
    default:
        ::FUN_005b5e40();
        return 0;
    }
}

extern int DAT_0108d47c;
struct FUN_00984ba0
{
    FUN_00984ba0(int);
    ~FUN_00984ba0();
    virtual void vfn_0();
};
struct FUN_00984b20 : public FUN_00984ba0
{
    FUN_00984b20(int a);
};
// Constructs the base with a, then calls FUN_0097ade0(3, 0) and FUN_00984390(0, 1).
// @fnv 0x00984b20
FUN_00984b20::FUN_00984b20(int aiValue) : FUN_00984ba0(aiValue)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(3, 0);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(0, 1);
}

struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
};
struct FUN_00984e60 : CGBase
{
    FUN_00984e60(int t);
};
// @fnv 0x00984e60
FUN_00984e60::FUN_00984e60(int aiValue) : CGBase(aiValue)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0x16, 0xffff0017);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(0x10, 0xffff0017);
}

namespace fnv_00984ee0 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
};
struct FUN_00984ee0 : CGBase
{
    FUN_00984ee0(int t);
};
// @fnv 0x00984ee0
FUN_00984ee0::FUN_00984ee0(int t) : CGBase(t)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0x13, 1);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(1, 4);
    reinterpret_cast<::TESPackage *>(this)->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(1));
}
}  // namespace fnv_00984ee0

namespace fnv_00984f80 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
};
struct FUN_00984f80 : CGBase
{
    FUN_00984f80(int t);
};
// @fnv 0x00984f80
FUN_00984f80::FUN_00984f80(int t) : CGBase(t)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0x13, 2);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(1, 5);
    reinterpret_cast<::TESPackage *>(this)->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(2));
}
}  // namespace fnv_00984f80

namespace fnv_00985080 {
extern int DAT_0108d47c;
struct FUN_00984ba0
{
    FUN_00984ba0(int);
    ~FUN_00984ba0();
    virtual void vfn_0();
};
struct FUN_00985080 : public FUN_00984ba0
{
    FUN_00985080(int a);
};
// Constructs the base with a, then calls FUN_0097ade0(2, 7) and FUN_00984390(1, 7).
// @fnv 0x00985080
FUN_00985080::FUN_00985080(int aiValue) : FUN_00984ba0(aiValue)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(2, 7);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(1, 7);
}
}  // namespace fnv_00985080

namespace fnv_00985180 {
extern int DAT_0108d47c;
struct FUN_00984ba0
{
    FUN_00984ba0(int);
    ~FUN_00984ba0();
    virtual void vfn_0();
};
struct FUN_00985180 : public FUN_00984ba0
{
    FUN_00985180(int a);
};
// Constructs the object via FUN_00984ba0(a), then calls FUN_0097ade0(2, 8) and FUN_00984390(1, 8).
// @fnv 0x00985180
FUN_00985180::FUN_00985180(int a) : FUN_00984ba0(a)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(2, 8);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(1, 8);
}
}  // namespace fnv_00985180

namespace fnv_00985200 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
};
struct FUN_00985200 : CGBase
{
    FUN_00985200(int t);
};
// Constructs the base with t, then calls FUN_0097ade0(2, 9) and FUN_00984390(1, 9).
// @fnv 0x00985200
FUN_00985200::FUN_00985200(int aiValue) : CGBase(aiValue)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(2, 9);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(1, 9);
}
}  // namespace fnv_00985200

namespace fnv_00985280 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
};
struct FUN_00985280 : CGBase
{
    FUN_00985280(int t);
};
// Constructs the object via CGBase(t), then calls FUN_0097ade0(3, 0) and FUN_00984390(0x11, 0x3c).
// @fnv 0x00985280
FUN_00985280::FUN_00985280(int aiValue) : CGBase(aiValue)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(3, 0);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(0x11, 0x3c);
}
}  // namespace fnv_00985280

namespace fnv_00985390 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
};
struct FUN_00985390 : CGBase
{
    FUN_00985390(int t);
};
// Constructs the object via CGBase(t), then calls FUN_0097ade0(2, 0x10) and FUN_00984390(1, 0x10).
// @fnv 0x00985390
FUN_00985390::FUN_00985390(int t) : CGBase(t)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(2, 0x10);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(1, 0x10);
}
}  // namespace fnv_00985390

namespace ol4_00985000 {
struct CGBase
{
    CGBase(int);
    ~CGBase();
    virtual void vf();
};
struct FUN_00985000 : CGBase
{
    FUN_00985000(int t);
};
// @fnv 0x00985000
FUN_00985000::FUN_00985000(int t) : CGBase(t)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0x13, 3);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(0x11, 0xf);
    reinterpret_cast<::TESPackage *>(this)->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(3));
}
}

namespace fnv_00985300 {
class CGBase
{
  public:
    CGBase(int);
    ~CGBase();
    virtual void v0();
};
class FUN_00985300 : public CGBase
{
  public:
    FUN_00985300(int aeType);
};
// Constructs the object with CGBase(aeType), then calls FUN_0097ade0(3,0), FUN_0097ade0(9,0) and FUN_00984390(9,1).
// @fnv 0x00985300
FUN_00985300::FUN_00985300(int aeType) : CGBase(aeType)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(3, 0);
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(9, 0);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(9, 1);
}
}  // namespace fnv_00985300

namespace fnv_00984c20 {
extern int DAT_0108d488;
class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
};
class FUN_00984c20 : public CGBase
{
  public:
    FUN_00984c20(int aeType);
};
// @fnv 0x00984c20
FUN_00984c20::FUN_00984c20(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d488;
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0x12, 0x10);
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(3, 1);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(3, 0);
}
}  // namespace fnv_00984c20

namespace fnv_00984cb0 {
extern int DAT_0108d494;

class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
};
class FUN_00984cb0 : public CGBase
{
  public:
    FUN_00984cb0(int aeType);
};
// @fnv 0x00984cb0
FUN_00984cb0::FUN_00984cb0(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d494;
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0xe, 1);
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0xf, 0);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(0xe, 0);
}
}  // namespace fnv_00984cb0

namespace fnv_00984d40 {
extern int DAT_0108d4a0;

class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
};
class FUN_00984d40 : public CGBase
{
  public:
    FUN_00984d40(int aeType);
};
// @fnv 0x00984d40
FUN_00984d40::FUN_00984d40(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d4a0;
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0xf, 1);
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(1, 8);
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(1, 7);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(0xf, 0);
}
}  // namespace fnv_00984d40

namespace fnv_00985100 {
extern int DAT_0108d4f4;
namespace ol4_00985000 {
class CGBase
{
  public:
};
}
class CGBase
{
  public:
    void** m_ppVirtualMethodTable;
    CGBase(int);
    ~CGBase();
};
class FUN_00985100 : public CGBase
{
  public:
    FUN_00985100(int aeType);
};
// @fnv 0x00985100
FUN_00985100::FUN_00985100(int aeType) : CGBase(aeType)
{
    m_ppVirtualMethodTable = (void**)&DAT_0108d4f4;
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0x13, 4);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(1, 6);
    reinterpret_cast<::TESPackage *>((((ol4_00985000::CGBase*)this)))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(4));
}
}  // namespace fnv_00985100


// @fnv 0x00984a50
void InitCombatGoalTable()
{
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        CombatGoal* pCombatGoal = CombatGoal::CreateGoal((CombatGoal::COMBAT_GOAL)i);
        DAT_011f17a0[i] = pCombatGoal;
    }
}

struct CombatGoal;

struct FUN_00984470_Class
{
    CombatGoal* GetCombatGoal(int index);
};

// @fnv 0x00984470
CombatGoal* FUN_00984470_Class::GetCombatGoal(int index)
{
    return *reinterpret_cast<CombatGoal**>(reinterpret_cast<char*>(this) + 0x3fff8 + index * 4);
}

struct S
{
    int DestroyIfFlagged(int);
};
// Iterates the 16 entries of DAT_011f17a0 and, for each non-null CombatGoal, calls DestroyIfFlagged with 1.
// @fnv 0x00984a90
void FUN_00984a90()
{
    unsigned int i;
    {
        CombatGoal* pGoalCopy;
        {
            CombatGoal* a;
            {
                int iResult;
                for (i = 0; i < 0x10; ++i)
                {
                    a = DAT_011f17a0[i];
                    pGoalCopy = a;
                    if (pGoalCopy)
                        iResult = ((S*)pGoalCopy)->DestroyIfFlagged(1);
                    else
                        iResult = 0;
                }
            }
        }
    }
}

struct S_984af0
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00984290, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00984af0
void* S_984af0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00984290 *>(this)->FUN_00984290::~FUN_00984290();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00984ba0 {
struct CondS
{
    int m_field0;
    int m_field1;

    CondS();
    ~CondS()
    {}
};

extern int DAT_0108d440;

struct FUN_00984ba0
{
    int* m_vftable;
    CondS m_condition0;
    CondS m_condition1;
    int m_uiFilterValue;
    int m_zero;

    FUN_00984ba0(int value);
};

// @fnv 0x00984ba0
FUN_00984ba0::FUN_00984ba0(int value) : m_vftable(&DAT_0108d440), m_condition0(), m_condition1(), m_uiFilterValue(value)
{
    m_zero = 0;
}
}  // namespace fnv_00984ba0

struct CombatGoalStub_b4510
{
    CombatGoalStub_b4510(int eType);
    virtual ~CombatGoalStub_b4510();
    virtual void vfn_0();
};

struct FUN_00984dd0 : CombatGoalStub_b4510
{
    FUN_00984dd0(int eType);
    virtual ~FUN_00984dd0();
};

// @fnv 0x00984dd0
FUN_00984dd0::FUN_00984dd0(int eType) : CombatGoalStub_b4510(eType)
{
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0x16, 0xffff0016);
    reinterpret_cast<::CombatAction *>(this)->FUN_0097ade0(0xf, 0);
    reinterpret_cast<::FUN_00984390_shell *>(this)->FUN_00984390(0xd, 0xffff0016);
}
