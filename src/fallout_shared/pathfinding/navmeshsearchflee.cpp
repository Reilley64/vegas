
// src/fallout_shared/pathfinding/navmeshsearchflee.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchflee.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv_result_slot.h"
#include "fnv/decl/AvoidNodeList.h"
#include "fnv/decl/DoorAccessData.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0068f230_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_006a94f0_shell.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/FUN_006a9560_Class.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_009962d0_class.h"
#include "fnv/decl/GetCenterX_006a6eb0.h"
#include "fnv/decl/MeshX.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESObjectDOOR.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_006dc990__Sdc990.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_011d6000.h"
struct FUN_006a9290_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

extern int DAT_0106b87c;
struct NavMeshSearch
{
    NavMeshSearch();
    void* m_vtbl;
    float fFleeTime;
    bool bFleeActive;
};
struct FUN_006ab410 : NavMeshSearch
{
    FUN_006ab410();
};
// Initializes the vtable pointer and clears the flee time and flee-active flag at offsets 0x20a4 and 0x20a8.
// @fnv 0x006ab410
FUN_006ab410::FUN_006ab410()
{
    m_vtbl = (void*)&DAT_0106b87c;
    *(float*)((char*)this + 0x20a4) = 0.0f;
    *(char*)((char*)this + 0x20a8) = 0;
}

class NavMesh;
class NavMeshTriangleEdgeReference;
struct NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
struct NavMeshPtr
{
  public:
    NavMesh* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
};
class Flt
{
  public:
    operator unsigned int();
};
class NavMeshTriangleReference
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
};
template <class N, class L> class AStarNode
{
  public:
    unsigned int unk0, unk4;
    N kNode;
    const N& FUN_00413f40() const;
};
struct PathingLocation
{
  public:
    bool FindNavMeshTriangle(NavMeshPtr&, unsigned short&);
};
class PathingAvoidNodeArray
{
  public:
};
struct PathingRequest
{
  public:
};

class NavMeshSearchFlee
{
  public:
    unsigned int pad0[0x2058 / 4];
    PathingRequest* pRequest;
    unsigned int pad205c[9];
    bool bHasDestination;
    NiPoint3 kDestination;
    bool IsNodeValid(const AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode);
};

// @fnv 0x006a9a70
bool NavMeshSearchFlee::IsNodeValid(const AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode)
{
    PathingLocation* pdest = ((::PathingLocation *)(::FUN_006a9540((char *)(pRequest))));
    float fscore;
    if (bHasDestination)
    {
        NavMeshPtr spmeshPtr;
        unsigned short sgoalTri;
        if (pdest->FindNavMeshTriangle(spmeshPtr, sgoalTri))
        {
            const NavMeshTriangleReference* thisNode = &(*(const ::NavMeshTriangleReference *)(reinterpret_cast<::TESTopicInfoData *>((void *)(apNode))->GetLinkToList()));
            if ((std::uintptr_t)thisNode->m_pLocationNavMesh == *(Flt*)&spmeshPtr &&
                thisNode->m_usTriangleIdentifier == sgoalTri)
                return true;
        }
    }
    if (apNode == ((const ::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *)(reinterpret_cast<::FUN_009962d0_class *>(this)->GetFieldAt2050())))
        return false;
    NiPoint3 nodeCenter = (*(::NiPoint3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((void *)&(apNode->kNode))->FUN_006a6eb0({})));
    float fsqrLength = reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::NiPoint3 &)((reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathingLocation *)(::GetOffsetC((std::intptr_t)(pRequest))))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>()) - nodeCenter)))->GetSquaredXYLength();
    if (fsqrLength < reinterpret_cast<::FUN_006d2c20_Class *>((void *)(pRequest))->GetFloatAtOffsetB0() * reinterpret_cast<::FUN_006d2c20_Class *>((void *)(pRequest))->GetFloatAtOffsetB0())
        return false;
    if (bHasDestination)
    {
        NiPoint3 destinationVec = kDestination - nodeCenter;
        NiPoint3 originDestinationVec = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathingLocation *)(::GetOffsetC((std::intptr_t)(pRequest))))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>()) - kDestination;
        if (reinterpret_cast<::TESCombatStyle *>((void *)&(originDestinationVec))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)&(destinationVec))->UpdateCombatStyle())
            return false;
    }
    fscore = 0.0f;
    if (((::PathingAvoidNodeArray *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(pRequest))->GetString())))
        fscore = reinterpret_cast<::fnv_006dc990::Sdc990 *>((((::PathingAvoidNodeArray *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(pRequest))->GetString()))))->SumNodeValues((std::intptr_t)&(nodeCenter));
    return fscore <= ::_DAT_01012060;
}

struct Pt
{
};

struct P3 : public Pt
{
    float x, y, z;
    P3 operator-(const P3&) const;
};

class NavMeshClosedDoorInfo;
class NavMeshTriangle;
class NavMesh
{
  public:
    P3 GetNavMeshData(unsigned short);
public:
    ::NavMeshTriangle *GetTriangle(unsigned short);
public:
    ::NavMeshClosedDoorInfo *GetClosedDoorInfo(unsigned short);
};

void FUN_005330e0(float&, float, float);

struct FUN_006a9580_NodeLayout
{
    unsigned int unk0;
    float fcost;
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    float GetCenterX;
    float m_fCenterY;
    float m_fCenterZ;
};

struct FUN_006a9580_shell
{
    unsigned int pad0[0x2058 / 4];
    void* pRequest;
    unsigned int pad205c[5];
    P3 kAvoidVector;
    float fFleeRange;

    void SetNodeFleeCost(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode, NavMesh* apNavMesh,
                         unsigned short aiTriangle);
};

// Stores the navmesh and triangle on the node, computes the triangle center, and sets the node cost from the flee range minus the distance to the avoid vector.
// @fnv 0x006a9580
void FUN_006a9580_shell::SetNodeFleeCost(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode,
                                         NavMesh* apNavMesh, unsigned short aiTriangle)
{
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_pLocationNavMesh = apNavMesh;
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_usTriangleIdentifier = aiTriangle;

    P3 center = apNavMesh->GetNavMeshData(aiTriangle);

    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->GetCenterX = center.x;
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_fCenterY = center.y;
    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->m_fCenterZ = center.z;

    P3 avoidVector = center - kAvoidVector;
    float fcost = fFleeRange - reinterpret_cast<::NiPoint3 *>((void *)&(avoidVector))->ComputeMagnitude();

    FUN_005330e0(fcost, 0.0f, fFleeRange);

    reinterpret_cast<FUN_006a9580_NodeLayout*>(apNode)->fcost = fcost;
}

// NavMeshSearchFlee's destructor.
//
// The compiler-generated destructor of a class with a base class first restores
// the class vtable pointer into the object and then runs the base class
// destructor on the same object.
struct AStarSearchBase
{
    AStarSearchBase();
    virtual void v00();
    virtual ~AStarSearchBase();
};

struct FUN_006a92c0_cls : public AStarSearchBase
{
    virtual void v01();
    virtual ~FUN_006a92c0_cls();
};
// Calls FUN_006a92c0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006a9290
void* FUN_006a9290_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_006a92c0_cls *>(this)->::FUN_006a92c0_cls::~FUN_006a92c0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006a92c0
FUN_006a92c0_cls::~FUN_006a92c0_cls()
{}

struct FleeStartNode : NavMeshTriangleReference
{
    NiPoint3 position;
};
struct FleePath
{
};
struct FleeLocation : PathingLocation
{
};
struct FleeRequest : PathingRequest
{
};
struct FleeAvoidNodes : PathingAvoidNodeArray
{
};
struct FleeSearch : FUN_006a9580_shell
{
    bool bHasDestination;
    NiPoint3 kDestination;
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* FUN_006a7c90(unsigned int, const FleeStartNode*,
                                                                                    float);
    bool FUN_006a7d60(FleePath*, unsigned int, bool);
    bool StartFleeSearch(FleeRequest*, const FleeStartNode*, FleePath*, std::uintptr_t);
};
// @fnv 0x006a92e0
bool FleeSearch::StartFleeSearch(FleeRequest* request, const FleeStartNode* start, FleePath* path, std::uintptr_t limit)
{
    pRequest = request;
    reinterpret_cast<FleeStartNode&>(pad205c) = *start;
    NiPoint3 a = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathingLocation *)(::GetOffsetC((std::intptr_t)(request))))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
    reinterpret_cast<NiPoint3&>(kAvoidVector) = ::NiPoint3::ZERO;
    fFleeRange = reinterpret_cast<::FUN_006d2c20_Class *>((void *)(request))->GetFloatAtOffsetB0();
    if (((::PathingAvoidNodeArray *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(static_cast<FleeRequest*>(pRequest)))->GetString())))
        reinterpret_cast<::AvoidNodeList *>((static_cast<FleeAvoidNodes*>(((::PathingAvoidNodeArray *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(static_cast<FleeRequest*>(pRequest)))->GetString())))))->FUN_006dc9f0(a, (::NiPoint3 &)(kAvoidVector));
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* p =
        FUN_006a7c90(reinterpret_cast<::FUN_006a94f0_shell *>(this)->FUN_006a94f0(start->m_pLocationNavMesh, start->m_usTriangleIdentifier), start, 0.0f);
    SetNodeFleeCost(p, start->m_pLocationNavMesh, start->m_usTriangleIdentifier);
    if (!reinterpret_cast<::FUN_006a9520_Class *>((static_cast<FleeLocation*>(((::PathingLocation *)(::FUN_006a9540((char *)(request)))))))->FUN_006a9520())
    {
        bHasDestination = true;
        kDestination = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathingLocation *)(::FUN_006a9540((char *)(static_cast<FleeRequest*>(pRequest)))))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
    }
    bool h = FUN_006a7d60(path, limit, ((bool)(reinterpret_cast<::FUN_006a9560_Class *>((static_cast<FleeRequest*>(pRequest)))->GetByteAtOffset9B())));
    if (!h && !reinterpret_cast<::FUN_0076b610_Class *>((path))->FUN_0076b610())
    {
        const NavMeshTriangleReference* f = ((const ::NavMeshTriangleReference *)&(::GetLastElement((const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(path))));
        NiPoint3 eb = (*(::NiPoint3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((void *)(f))->FUN_006a6eb0({})));
        float s = reinterpret_cast<::FUN_006d2c20_Class *>((void *)(static_cast<FleeRequest*>(pRequest)))->GetFloatAtOffsetB0() * 0.5;
        s = FUN_0040ebd0(s, 256.0f);
        NiPoint3 i = a - eb;
        if (reinterpret_cast<::TESCombatStyle *>((void *)&(i))->UpdateCombatStyle() > s * s)
            h = true;
    }
    return h;
}

#include <float.h>
struct Vector3
{
    float x, y, z;
    Vector3 operator-(const Vector3&) const;
};
extern float g_doorCost;
extern double g_destinationWeight;
struct Threshold
{
};
struct Mesh;
struct MeshTriangle
{
};
struct EdgeInfo
{
    int type;
};
struct DoorBase
{
};
struct Door
{
};
struct DoorLockX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorLockX(Door*);
    ~DoorLockX();
};
struct Mesh
{
    Vector3 FUN_00558220(unsigned short);
};
struct AvoidPoints
{
};
struct Request
{
};
struct Node
{
    float cost;
    int unk04;
    Mesh* edgeData;
    unsigned short triangle;
    unsigned short unk0e;
    int unk10, unk14, unk18;
    Mesh* parentMesh;
    unsigned short parentTriangle;
    unsigned short unk22;
    int parentEdge;
};
struct NodeGeometry
{
    Mesh* edgeData;
    unsigned short triangle;
};
struct NodeArray
{
};
enum SearchResult
{
    Added,
    Updated,
    Unchanged
};
struct Search : FUN_006a9580_shell
{
    bool hasDestination;
    Vector3 destination;
    SearchResult FUN_006a7e00(unsigned int, Mesh*, unsigned short, float, Node**);
    bool ExpandNode(Node*, NodeArray*);
};
// @fnv 0x006a9620
bool Search::ExpandNode(Node* node, NodeArray* output)
{
    // Local names preserve the required compiler stack layout.
    Vector3 position;  // Normalized avoidance direction.
    Vector3 direction = (*(::Vector3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((void *)(((NodeGeometry*)&node->edgeData)))->FUN_006a6eb0({})));
    AvoidPoints* avoid = ((::AvoidPoints *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(((Request*)pRequest)))->GetString()));
    position = *(const Vector3*)&::NiPoint3::ZERO;
    if (avoid)
    {
        position = *(Vector3*)&kAvoidVector - direction;
        reinterpret_cast<::FUN_004a0c10_s *>(&(position))->FUN_004a0c10();
    }
    if (!_finite(node->cost))
    {
        float& initial = node->cost;
        initial = 0.0f;
    }
    for (int edge = 0; edge < 3; ++edge)
    {
        Mesh* edgeData;
        unsigned short triangle;
        int mesh;
        if (reinterpret_cast<::MeshX *>((node->edgeData))->FindAdjacentEdge(node->triangle, edge, (::MeshX **)(::Mesh **)(&edgeData), &triangle, &mesh))
        {
            EdgeInfo* next = ((::EdgeInfo *)(reinterpret_cast<::FUN_0068f230_shell *>((node->edgeData))->FUN_0068f230(node->triangle, edge)));
            if (next && next->type == 1)
                continue;
            float delta = 1.0f;
            if (reinterpret_cast<::FUN_00691140_shell *>((((::MeshTriangle *)(reinterpret_cast<::NavMesh *>((edgeData))->GetTriangle(triangle)))))->FUN_00691140(0x1000))
            {
                if (reinterpret_cast<::DoorAccessData *>((void *)(((Request*)pRequest)))->ReadState98())
                    continue;
                else
                {
                    unsigned int door = *((unsigned int *)(reinterpret_cast<::NavMesh *>((edgeData))->GetClosedDoorInfo(triangle)));
                    Door* id = ((::Door *)(::FUN_004839c0(door)));
                    if (id)
                    {
                        DoorLockX result(id);
                        void* lock = ((void *)(reinterpret_cast<::FUN_006c9900_shell *>((((Request*)pRequest)))->FUN_006c9900()));
                        bool actor;
                        if (!reinterpret_cast<::DoorAccessData *>(&(result))->CanUnlockDoor((const ::PathingActorData *)(lock), (::TESObjectREFR *)(id), (*(bool *)(&actor))))
                            continue;
                        if (reinterpret_cast<::TESObjectDOOR *>((((::DoorBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((id))->FUN_007af430()))))->IsTeleportDoor())
                            delta = 100.0f;
                    }
                }
            }
            if (::GetFloatAtOffset68((const char *)(((Request*)pRequest))) > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Threshold *>(&::originalRuntimeFloatSetting1308)))))) &&
                reinterpret_cast<::FUN_00691140_shell *>((((::MeshTriangle *)(reinterpret_cast<::NavMesh *>((edgeData))->GetTriangle(triangle)))))->FUN_00691140(0x10))
                continue;
            Node* neighbour;
            // Adjacent triangle centre and displacement from the current node.
            Vector3 multiplier = edgeData->FUN_00558220(triangle);
            Vector3 cost = multiplier - direction;
            // Accumulated path cost.
            float extra = reinterpret_cast<::FUN_00589850_Class *>((void *)&(cost))->FUN_00589850() * delta + node->cost;
            if (avoid)
            {
                extra += reinterpret_cast<::fnv_006dc990::Sdc990 *>((((::AvoidPoints *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(((Request*)pRequest)))->GetString()))))->SumNodeValues((std::intptr_t)&(multiplier));
                Vector3 penalty = cost;
                reinterpret_cast<::FUN_004a0c10_s *>(&(penalty))->FUN_004a0c10();
                float travel = FUN_00404010(0.0f, reinterpret_cast<::FUN_004b6190_shell *>((void *)&(penalty))->DotProduct((void *)&(position)));
                extra += travel * ::CombatWeapons::DAT_0106b798;
            }
            if (hasDestination)
            {
                float distance = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::Vector3 &)((multiplier - destination)))->FUN_00589850();
                extra += distance * 10.0;
            }
            switch (FUN_006a7e00(reinterpret_cast<::FUN_006a94f0_shell *>(this)->FUN_006a94f0({}, {}), edgeData, triangle, extra, &neighbour))
            {
            case 0:
                reinterpret_cast<::FUN_006a9580_shell *>(this)->SetNodeFleeCost((::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *)(neighbour), (::NavMesh *)(edgeData), triangle);
            case 1:
                neighbour->parentMesh = node->edgeData;
                neighbour->parentTriangle = node->triangle;
                neighbour->parentEdge = edge;
                reinterpret_cast<::FUN_00438690 *>((output))->FUN_007cb2e0((unsigned int *)&(neighbour));
                break;
            }
        }
    }
    return true;
}

#include "generated/data/fallout_shared/pathfinding/navmeshsearchflee.inc"
