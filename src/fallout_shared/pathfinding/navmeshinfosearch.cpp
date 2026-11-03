// fallout_shared/pathfinding/navmeshinfosearch.cpp: NavMeshInfoSearch, StandInSearch (8 functions)

#include "fnv/decl/ActiveEffect.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_0042e2a0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00501e80_shell.h"
#include "fnv/decl/FUN_0057b4b0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006b8ec0_cls.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_006b8f40__FUN_006b8f40_cls.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0068f000.h"
#include "fnv/symbols_00690000.h"
#include "fnv/symbols_011de000.h"
#include "navmeshinfosearch_decls.h"

// The legacy destructor label is contradicted by the queue member initialization
// at AStarSearch construction: the receiver is this + 0x1ff4.
// Default-constructs the AStarOpenList, initializing m_fValue to -1.0f and zeroing the m_ppNodes array.
// @fnv 0x006b9470
template <> AStarOpenList<const NavMeshInfo*, TESObjectREFR*>::AStarOpenList()
{
    m_fValue = -1.0f;
    memset(m_ppNodes, 0, sizeof(m_ppNodes));
}

// @fnv 0x006b8c20
bool NavMeshInfoSearch::HasReachedGoal(const AStarNodeType* pNode)
{
    return pNode->ObjectResolver == m_pGoalNavMeshInfo;
}

// Builds the A* connection list for pNode from its mesh's connections, preferred connections and door portals, computing costs and adding nodes to pConnections.
// @fnv 0x006b8490
bool NavMeshInfoSearch::CollectConnections(const AStarNodeType* pNode,
                                           BSSimpleArray<AStarNodeType*, 1024>* pConnections)
{
    float fInitialCost = pNode->m_fPathingCostCur;
    const NavMeshInfo* m_pNavigationMesh = pNode->ObjectResolver;
    float fCostMultiplier = 1.0f - reinterpret_cast<::ActiveEffect *>((void *)(m_pNavigationMesh))->GetDuration() * 100.0;
    FUN_005330e0(fCostMultiplier, 0.1f, 1.0f);
    unsigned int ItemUpdateArray = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_pNavigationMesh->m_kConnectedNavMeshInfos))->GetName()));
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        const NavMeshInfo* pNextMesh = m_pNavigationMesh->m_kConnectedNavMeshInfos.GetAt(i);
        if (!pNextMesh)
            continue;
        NiPoint3 Start =
            m_pNavigationMesh == m_pStartNavMeshInfo ? m_kPathStartPosition : m_pNavigationMesh->m_kNavMeshPosition;
        NiPoint3 Goal = pNextMesh == m_pGoalNavMeshInfo ? m_kGoalPosition : pNextMesh->m_kNavMeshPosition;
        float fConnectionCost = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((Goal - Start)))->ComputeMagnitude() * fCostMultiplier * 3.0 + fInitialCost;
        AStarNodeType* pNewAStarNode;
        switch (CreateOrUpdateNode(reinterpret_cast<unsigned int>(pNextMesh), fConnectionCost, pNewAStarNode))
        {
        case ASTARNODE_CREATED:
            pNewAStarNode->ObjectResolver = pNextMesh;
            if (m_bUseGoalDistanceHeuristic)
                pNewAStarNode->m_fCost = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((m_kGoalPosition - pNextMesh->m_kNavMeshPosition)))->ComputeMagnitude() * 0.1f;
            else
                pNewAStarNode->m_fCost = 1.0f;
        case ASTARNODE_UPDATED:
            pNewAStarNode->m_kOpenListLink = 0;
            reinterpret_cast<::FUN_00438690 *>((void *)(pConnections))->FUN_007cb2e0((unsigned int *)&(pNewAStarNode));
            break;
        }
    }
    unsigned int uiPreferredConnections = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_pNavigationMesh->m_kPreferredConnections))->GetName()));
    for (unsigned int i = 0; i < uiPreferredConnections; ++i)
    {
        const NavMeshInfo* pNextMesh = m_pNavigationMesh->m_kPreferredConnections.GetAt(i);
        if (!pNextMesh)
            continue;
        NiPoint3 Start =
            m_pNavigationMesh == m_pStartNavMeshInfo ? m_kPathStartPosition : m_pNavigationMesh->m_kNavMeshPosition;
        NiPoint3 Goal = pNextMesh == m_pGoalNavMeshInfo ? m_kGoalPosition : pNextMesh->m_kNavMeshPosition;
        float fConnectionCost = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((Goal - Start)))->ComputeMagnitude() * fCostMultiplier + fInitialCost;
        AStarNodeType* pNewAStarNode;
        switch (CreateOrUpdateNode(reinterpret_cast<unsigned int>(pNextMesh), fConnectionCost, pNewAStarNode))
        {
        case ASTARNODE_CREATED:
            pNewAStarNode->ObjectResolver = pNextMesh;
            if (m_bUseGoalDistanceHeuristic)
                pNewAStarNode->m_fCost = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((m_kGoalPosition - pNextMesh->m_kNavMeshPosition)))->ComputeMagnitude() * 0.1f;
            else
                pNewAStarNode->m_fCost = 1.0f;
        case ASTARNODE_UPDATED:
            pNewAStarNode->m_kOpenListLink = 0;
            reinterpret_cast<::FUN_00438690 *>((void *)(pConnections))->FUN_007cb2e0((unsigned int *)&(pNewAStarNode));
            break;
        }
    }
    if (m_pPathingActorData || m_eDoorLockDisposition == Pathing::ALLOW_LOCKS)
    {
        ItemUpdateArray = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_pNavigationMesh->m_kDoorReferences))->GetName()));
        for (unsigned int i = 0; i < ItemUpdateArray; ++i)
        {
            TESObjectREFR* pPathNodeDoor = m_pNavigationMesh->m_kDoorReferences.GetAt(i);
            if (!pPathNodeDoor)
                continue;
            if (pPathNodeDoor->GetDisabled())
                continue;
            reinterpret_cast<::FUN_00501e80_shell *>(&(m_kDoorAccessData))->FUN_00501e80(pPathNodeDoor);
            bool bDoorLocked;
            bool bCanUnlockLockedDoor = m_kDoorAccessData.CanUnlockDoor(m_pPathingActorData, pPathNodeDoor, bDoorLocked);
            float fDoorCost = 0.0f;
            if (!bCanUnlockLockedDoor || bDoorLocked)
            {
                switch (m_eDoorLockDisposition)
                {
                case Pathing::ALLOW_LOCKS:
                    break;
                case Pathing::PENALIZE_LOCKS:
                    fDoorCost = 409600.0f;
                    break;
                case Pathing::IGNORE_LOCKS:
                    continue;
                }
            }
            if (reinterpret_cast<TESObjectDOOR*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pPathNodeDoor))->FUN_007af430())))->IsTeleportDoor())
                fDoorCost = 409600.0f;
            if (m_eDoorLockDisposition == Pathing::PENALIZE_LOCKS && reinterpret_cast<::FUN_0057b4b0_shell *>((pPathNodeDoor))->FUN_0057b4b0())
                continue;
            if (!((::TeleportableReference *)(pPathNodeDoor->GetExtraRadioData())))
                continue;
            TESObjectREFR* m_pLinkedDoorReference = ((::TESObjectREFR *)(::FUN_00559450((int *)(((::TeleportableReference *)(pPathNodeDoor->GetExtraRadioData()))))));
            if (!m_pLinkedDoorReference)
                continue;
            NavMeshPortalData* pExtraNavMeshPortal = ((::NavMeshPortalData *)(reinterpret_cast<::FUN_0042e2a0_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((m_pLinkedDoorReference))->FUN_005d43c0()))))->GetExtraNavMeshPortal()));
            if (pExtraNavMeshPortal)
            {
                const NavMeshInfo* pNextMesh =
                    ((::NavMeshInfo *)(((::Pathing *)(reinterpret_cast<::Owner45A *>((((::TES *)::g_TES)))->FUN_0045af00()))->FindReferenceByFormId({})));
                if (pNextMesh && !::FUN_0068f320((const ::NavMeshInfo *)(pNextMesh)))
                {
                    NiPoint3 Start = m_pNavigationMesh == m_pStartNavMeshInfo ? m_kPathStartPosition
                                                                              : m_pNavigationMesh->m_kNavMeshPosition;
                    NiPoint3 Goal = pNextMesh == m_pGoalNavMeshInfo ? m_kGoalPosition : pNextMesh->m_kNavMeshPosition;
                    float fConnectionCost = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)(((*(const ::NiPoint3 *)(reinterpret_cast<::BaseProcess *>((((::TeleportableReference *)(m_pLinkedDoorReference->GetExtraRadioData()))))->GetCurrentProcessData())) - Start)))->ComputeMagnitude() +
                                            reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((Goal - (*(const ::NiPoint3 *)(reinterpret_cast<::BaseProcess *>((((::TeleportableReference *)(pPathNodeDoor->GetExtraRadioData()))))->GetCurrentProcessData())))))->ComputeMagnitude();
                    fConnectionCost *= fCostMultiplier;
                    fConnectionCost *= 3.0;
                    fConnectionCost += fInitialCost;
                    fConnectionCost += fDoorCost;
                    AStarNodeType* pNewAStarNode;
                    switch (
                        CreateOrUpdateNode(reinterpret_cast<unsigned int>(pNextMesh), fConnectionCost, pNewAStarNode))
                    {
                    case ASTARNODE_CREATED:
                        pNewAStarNode->ObjectResolver = pNextMesh;
                        if (m_bUseGoalDistanceHeuristic)
                            pNewAStarNode->m_fCost = reinterpret_cast<::TimeoutTimer *>((void *)(pNode))->FUN_006b9130() * 2;
                        else
                            pNewAStarNode->m_fCost = 1.0f;
                    case ASTARNODE_UPDATED:
                        pNewAStarNode->m_kOpenListLink = pPathNodeDoor;
                        reinterpret_cast<::FUN_00438690 *>((void *)(pConnections))->FUN_007cb2e0((unsigned int *)&(pNewAStarNode));
                        break;
                    }
                }
            }
        }
    }
    return true;
}

struct RefA
{
    char b[12];
    RefA();
};
struct FUN_00501cd0
{
    char b[8];
    FUN_00501cd0();
};
struct FUN_006b8d90
{
    virtual ~FUN_006b8d90();
    char pad[0x2054];
    FUN_006b8d90();
};
struct FUN_006b8340 : public FUN_006b8d90
{
    RefA a;
    int i1;
    RefA b;
    int i2;
    int i3;
    char pad2[8];
    FUN_00501cd0 c;
    FUN_006b8340();
    virtual ~FUN_006b8340();
};
// Initializes the three integer members i1, i2 and i3 to zero.
// @fnv 0x006b8340
FUN_006b8340::FUN_006b8340()
{
    i3 = 0;
    i1 = 0;
    i2 = 0;
}

struct DoorLockX
{
    char b[8];
    ~DoorLockX();
};
struct FUN_006b8e40
{
    virtual ~FUN_006b8e40();
    char pad[0x2080];
};
struct FUN_006b8420 : public FUN_006b8e40
{
    DoorLockX lock;
    virtual ~FUN_006b8420();
};
// Destructor for FUN_006b8420; destroys the embedded lock member and the base FUN_006b8e40.
// @fnv 0x006b8420
FUN_006b8420::~FUN_006b8420()
{}


struct FUN_006b83f0_shell : public FUN_006b8420
{
    void* DestroyAndFree(unsigned int flags);
};

// Runs the base destructor, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006b83f0
void* FUN_006b83f0_shell::DestroyAndFree(unsigned int flags)
{
    FUN_006b8420::~FUN_006b8420();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NavMeshInfo;
struct NavMeshInfoMap
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void virtC8(int);
    void InsertNavMeshInfo(NavMeshInfo*);
};
struct DummyPointerMap
{
};
struct StandInSearch : public NavMeshInfoMap
{
    char pad[0x18];
    DummyPointerMap map;
    void RegisterNavMeshInfo(TeleportableReference*);
};
// @fnv 0x006b6940
void StandInSearch::RegisterNavMeshInfo(TeleportableReference* pInfo)
{
    reinterpret_cast<::FUN_00844700_Class *>(&(map))->FUN_00844700((std::uintptr_t)((::TESObjectREFR *)(::FUN_00559450((int *)(pInfo)))), (unsigned int)pInfo);
    InsertNavMeshInfo((NavMeshInfo*)pInfo);
    virtC8(1);
}

namespace fnv_006b8c50 {
struct InventoryChanges;
struct TESActorBase;
struct PathingActorData
{
    TESActorBase* m_pActorBaseFormItem;
    InventoryChanges* m_pInventoryChangesValue;
    bool m_bCanIgnoreLocks;
    char _pad_9[3];
};
struct FUN_006b8c50_shell : public NavMeshInfoSearch
{
    bool SetupNavMeshSearch(PathingActorData*, void*, void*, void*, void*, void*, void*, int);
};

class TESWorldSpace;
struct NavSearch_S
{
};
// @fnv 0x006b8c50
bool FUN_006b8c50_shell::SetupNavMeshSearch(PathingActorData* apActorLockData, void* aStartLocation, void* apStartMesh,
                                            void* aGoalLocation, void* apGoalMesh, void* apReturnNodes,
                                            void* apReturnLinks, int aeDoorLockDisposition)
{
    this->m_kPathStartPosition = *(const NiPoint3*)aStartLocation;
    *(void**)&this->m_pStartNavMeshInfo = apStartMesh;
    this->m_kGoalPosition = *(const NiPoint3*)aGoalLocation;
    *(void**)&this->m_pGoalNavMeshInfo = apGoalMesh;
    *(PathingActorData**)&this->m_pPathingActorData = apActorLockData;
    *(int*)&this->m_eDoorLockDisposition = aeDoorLockDisposition;
    this->m_bUseGoalDistanceHeuristic = false;
    if (((::fnv_006b8c50::TESWorldSpace *)(::FUN_00690800((const NavMeshInfo*)apStartMesh))) &&
        ((::fnv_006b8c50::TESWorldSpace *)(::FUN_00690800((const NavMeshInfo*)apStartMesh))) == ((::fnv_006b8c50::TESWorldSpace *)(::FUN_00690800((const NavMeshInfo*)apGoalMesh))))
        this->m_bUseGoalDistanceHeuristic = true;
    float fstartheuristic = 3.402823466e+38F;
    if (this->m_bUseGoalDistanceHeuristic)
    {
        ::NiPoint3 kGoalOffset;
        reinterpret_cast<::FUN_00439ef0_class *>((void *)((&this->m_kGoalPosition)))->FUN_00439ef0(&kGoalOffset, *(const ::NiPoint3 *)&((this->m_pStartNavMeshInfo)->m_kNavMeshPosition));
        fstartheuristic = kGoalOffset.ComputeMagnitude() * (double)0.1f;
    }
    else
        fstartheuristic = 1.0f;
    reinterpret_cast<::FUN_006b8ec0_cls *>((((NavSearch_S*)this)))->FUN_006b8ec0((std::intptr_t)(apStartMesh), (int *)(void **)(&apStartMesh), fstartheuristic);
    if (!reinterpret_cast<::fnv_006b8f40::FUN_006b8f40_cls *>((((NavSearch_S*)this)))->ProcessWithFallback((std::intptr_t)(apReturnNodes), (int)(apReturnLinks), true))
        return false;
    return true;
}
}  // namespace fnv_006b8c50
