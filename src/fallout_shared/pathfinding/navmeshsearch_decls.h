// fallout_shared/pathfinding/navmeshsearch_decls.h: declares NiPoint3, NavMeshTriangle, EdgeExtraInfo, NavMeshEdgeExtra, NavMeshClosedDoorInfo and more
#ifndef NAVMESHSEARCH_DECLS_H
#define NAVMESHSEARCH_DECLS_H

#include "fnv/decl/FUN_00501e80_shell.h"
#include "fnv/decl/FUN_0057b460_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0068f1d0_shell.h"
#include "fnv/decl/FUN_0068f230_shell.h"
#include "fnv/decl/FUN_0068f2c0_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_00693b70_shell.h"
#include "fnv/decl/FUN_00693d30_shell.h"
#include "fnv/decl/FUN_006a5ec0_shell.h"
#include "fnv/decl/FUN_006a7d30_shell.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_00996800_shell.h"
#include "fnv/decl/MeshX.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_0068f0c0__FUN_0068f0c0_shell.h"
#include "fnv/decl/fnv_006dc990__Sdc990.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_011d6000.h"
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
};
class NavMesh;
class NavMeshInfo;
class NavMeshStaticAvoidNode;
class TESObjectREFR;
class PathingActorData;
class PathingAvoidNodeArray;
template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    void* vtable;
    T* pBase;
    unsigned int uiSize, uiAllocSize;
    BSSimpleArray();
    BSSimpleArray(unsigned int);
    ~BSSimpleArray();
    unsigned int GetSize();
    T& GetAt(int);
    T& operator[](unsigned int);
    void Clear(bool);
    unsigned int Add(T&);
    template <class U> unsigned int Find(U&, unsigned int, bool(__cdecl*)(U&, U&));
};
class NavMeshTriangle
{
  public:
};
class EdgeExtraInfo
{
  public:
    int type;
};
class NavMeshEdgeExtra
{
  public:
    unsigned int unknown;
    NavMeshInfo* info;
};
class NavMeshClosedDoorInfo
{
  public:
    unsigned int door;
};
class NavMeshTriangle;
class NavMesh
{
  public:
    NiPoint3 GetNavMeshData(unsigned short);
    NavMeshClosedDoorInfo* GetClosedDoorInfo(unsigned short);
    bool GetStaticAvoidNodesForTriangle(unsigned short, BSSimpleArray<NavMeshStaticAvoidNode*>&);
public:
    ::NavMeshTriangle *GetTriangle(unsigned short);
};
class NavMeshTriangleReference
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    float GetCenterX, m_fCenterY, m_fCenterZ;
    NavMeshTriangle* FUN_006a78d0() const;
};
class NavMeshTriangleEdgeReference
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    int m_iEdgeIndex;
};
template <class N, class L> class AStarNode
{
  public:
    unsigned int key;
    float cost;
    N Node;
    L Link;
    N& GetNode() const;
    void FUN_004f5d90(float);
    float GetCost() const;
};
typedef AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference> SearchNode;
class NavMeshStaticAvoidNode
{
  public:
};
class PathingAvoidNodeArray
{
  public:
};
class PathingRequest
{
  public:
    NiPoint3 FUN_006a7910() const;
public:
    float GetTargetRadius();
public:
    float GetCenterRadius();
};
class TESForm
{
  public:
};
class TESBoundObject
{
};
class TESObjectDOOR : public TESBoundObject
{
  public:
    bool IsTeleportDoor();
};
class TESObjectREFR : public TESForm
{
  public:
};
class DoorAccessData
{
  public:
    unsigned int fields[6];
    bool CanUnlockDoor(const PathingActorData*, TESObjectREFR*, bool&);
public:
    bool ReadState98();
};
class AStarMapNav
{
  public:
    char storage[0x1fe0];
};
class AStarQueueNav
{
  public:
    char storage[0x54];
};
class NavMeshSearch
{
  public:
    char Heap[0x14];
    AStarMapNav m_kNodeHashTable;
    AStarQueueNav AStarBucketQueue;
    SearchNode* m_pFirstNode;
    SearchNode* m_pCurrentNode;
    SearchNode* m_pLastCreatedNode;
    unsigned int searchState;
    const PathingRequest* m_pPathingRequest;
    NavMeshTriangleReference m_kStartingTriangle, m_kGoalTriangle;
    BSSimpleArray<NavMeshTriangleEdgeReference>* m_pNavMeshTriangleEdges;
    BSSimpleArray<NavMeshInfo*>* m_pNavMeshInfos;
    DoorAccessData m_kDoorAccessData;
    bool CollectConnections(const SearchNode*, BSSimpleArray<SearchNode*>*);
    bool ComputePath(const PathingRequest*, const NavMeshTriangleReference&, const NavMeshTriangleReference&,
                     BSSimpleArray<NavMeshTriangleReference>*, BSSimpleArray<NavMeshTriangleEdgeReference>*,
                     BSSimpleArray<NavMeshInfo*>*);
    void SetSearchNodeTriangle(SearchNode*, NavMesh*, unsigned short);
    bool HasReachedGoal(const SearchNode*);
    ~NavMeshSearch();
    SearchNode* FindOrCreateSearchNode(unsigned int, const NavMeshTriangleReference&, float);
    bool Search(BSSimpleArray<NavMeshTriangleReference>*, BSSimpleArray<NavMeshTriangleEdgeReference>*, bool);
    int CreateOrUpdateNode(unsigned int, float, SearchNode*&);
};
class NavMeshPtr
{
  public:
    NavMesh* ptr;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NavMeshPtr&);
};
class NavMeshInfo
{
  public:
    bool ResolveNavMesh(NavMeshPtr&);
};
union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
};
extern float DAT_0119cdf8;
namespace std {
float abs(float);
}
void WrapValueToRange(float&, float, float);
void FUN_005330e0(float&, float, float);
#endif
