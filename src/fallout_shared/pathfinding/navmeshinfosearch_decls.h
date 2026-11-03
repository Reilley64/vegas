// fallout_shared/pathfinding/navmeshinfosearch_decls.h: declares NiPoint3, NavMeshInfo, NavMeshPortalData, ExtraDataList, TESForm and more
#ifndef FNV_NAVMESHINFOSEARCH_DECLS_H
#define FNV_NAVMESHINFOSEARCH_DECLS_H

#include <cstdint>

#include <cstring>
#include "fnv/decl/ActiveEffect.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_0042e2a0_shell.h"
#include "fnv/decl/FUN_00501e80_shell.h"
#include "fnv/decl/FUN_0057b4b0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0068f000.h"
#include "fnv/symbols_011de000.h"
#include "layout_support.h"
// PC NiPoint3 layout with the out-of-line arithmetic used by this search.
#define FNV_NIPOINT3_H
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
};

template <class T, unsigned int Growth> class BSSimpleArray<T*, Growth>
{
  public:
    void** m_ppVirtualMethodTable;
    T** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    T*& GetAt(unsigned int);
    unsigned int Add(T*&);
};

class NavMeshInfo
{
  public:
    unsigned int m_uiNavMeshID, m_uiParentSpaceID, uiFlags;
    int m_uiPathingFlags;
    NiPoint3 m_kNavMeshPosition;
    TESForm* m_pParentSpace;
    float m_fStoredValue;
    mutable BSSimpleArray<NavMeshInfo*, 1024> m_kConnectedNavMeshInfos;
    mutable BSSimpleArray<NavMeshInfo*, 1024> m_kPreferredConnections;
    mutable BSSimpleArray<TESObjectREFR*, 1024> m_kDoorReferences;
};
class NavMeshPortalData
{
  public:
    char extraDataPrefix[12];
    unsigned int m_uiNavMeshID;
};
class ExtraDataList
{
  public:
};
class TeleportableReference
{
  public:
};
class TESBoundObject;
class TESForm
{
  public:
public:
    bool GetDisabled() const;
};
class ExtraRadioData;
class TESObjectREFR : public TESForm
{
  public:
public:
    ::ExtraRadioData *GetExtraRadioData();
};
class TESObjectDOOR
{
  public:
    bool IsTeleportDoor();
};
class TESObjectREFR;
class Pathing
{
  public:
    enum DOOR_LOCK_DISPOSITION
    {
        IGNORE_LOCKS = 0,
        ALLOW_LOCKS = 1,
        PENALIZE_LOCKS = 2
    };
public:
    ::TESObjectREFR *FindReferenceByFormId(unsigned int);
};
class TES
{
  public:
};
class PathingActorData;
class LockExtraData;
class DoorAccessData
{
  public:
    TESObjectCELL* m_pSourceCell;
    TESObjectCELL* m_pDestinationCell;
    LockExtraData* m_pTeleportData;
    TESForm* m_pKeyForm;
    int m_iLockLevel;
    TESGlobal* m_pLockLevelGlobal;
    bool CanUnlockDoor(const PathingActorData*, TESObjectREFR*, bool&);
};
void __cdecl FUN_005330e0(float&, float, float);
enum CREATE_ASTARNODE_RESULT
{
    ASTARNODE_CREATED = 0,
    ASTARNODE_UPDATED = 1,
    ASTARNODE_UNCHANGED = 2
};

class NavMeshInfo;
class TESObjectREFR;
class PathingActorData;
template <class NodeDataType, class LinkDataType> class AStarNode
{
  public:
    float m_fPathingCostCur;
    float m_fCost;
    NodeDataType ObjectResolver;
    float GetHeuristic() const;
    LinkDataType m_kOpenListLink;
    AStarNode* m_pParentNode;
    AStarNode** m_ppPreviousNodeLink;
    AStarNode* pListNode;
    std::uintptr_t iKey;
    AStarNode* m_pNextHashNode;
};
template <class NodeDataType, class LinkDataType> class AStarOpenList
{
  public:
    float m_fValue;
    AStarNode<NodeDataType, LinkDataType>* m_ppNodes[20];
    AStarOpenList();
};
template <class T, unsigned int GrowBy> class BSSimpleArray;
class ScrapHeapBuffer
{
  public:
    class Header;
    char* m_pHeapBase;
    char* m_pCurrentPosition;
    char* m_pBufferLimit;
    Header* m_pBufferHeader;
};
template <class NodeDataType, class LinkDataType, unsigned int BlockSize> class AStarNodeAllocator
{
  public:
    ScrapHeapBuffer Heap;
};
template <class NodeType> class AStarNodeHashTable
{
  public:
    NodeType* m_ppNodes[2039];
    unsigned int iCount;
};
template <class NodeDataType, class LinkDataType> class AStarSearch
{
  public:
    typedef AStarNode<NodeDataType, LinkDataType> AStarNodeType;
    virtual ~AStarSearch();
    virtual bool CollectConnections(const AStarNodeType*, BSSimpleArray<AStarNodeType*, 1024>*);
    virtual bool HasReachedGoal(const AStarNodeType*);
    CREATE_ASTARNODE_RESULT CreateOrUpdateNode(std::uintptr_t, float, AStarNodeType*&);
    AStarNodeAllocator<NodeDataType, LinkDataType, 512> m_kNodeAllocator;
    AStarNodeHashTable<AStarNodeType> m_kNodeHashTable;
    AStarOpenList<NodeDataType, LinkDataType> AStarBucketQueue;
    AStarNodeType* m_pFirstNode;
    AStarNodeType* m_pCurrentNode;
    AStarNodeType* m_pLastCreatedNode;
    bool m_bUseBestNode;
};
class NavMeshInfoSearch : public AStarSearch<const NavMeshInfo*, TESObjectREFR*>
{
  public:
    virtual ~NavMeshInfoSearch();
    virtual bool CollectConnections(const AStarNodeType*, BSSimpleArray<AStarNodeType*, 1024>*);
    virtual bool HasReachedGoal(const AStarNodeType*);
    NiPoint3 m_kPathStartPosition;
    const NavMeshInfo* m_pStartNavMeshInfo;
    NiPoint3 m_kGoalPosition;
    const NavMeshInfo* m_pGoalNavMeshInfo;
    PathingActorData* m_pPathingActorData;
    Pathing::DOOR_LOCK_DISPOSITION m_eDoorLockDisposition;
    bool m_bUseGoalDistanceHeuristic;
    DoorAccessData m_kDoorAccessData;
};
typedef AStarOpenList<const NavMeshInfo*, TESObjectREFR*> NavMeshInfoQueue;
#endif
