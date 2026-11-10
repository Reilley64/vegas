#ifndef PATHSMOOTHERPOV_DECLS_H
#define PATHSMOOTHERPOV_DECLS_H

#include <cmath>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AvoidNodes__Search.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/ClearanceSearch.h"
#include "fnv/decl/FUN_0045cbc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00505c00_shell.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_00691620_shell.h"
#include "fnv/decl/FUN_00691640_shell.h"
#include "fnv/decl/FUN_00697980_t.h"
#include "fnv/decl/FUN_00698320_t.h"
#include "fnv/decl/FUN_0069f900_shell.h"
#include "fnv/decl/FUN_0069f920_cls.h"
#include "fnv/decl/FUN_006a0840_shell.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/FUN_006a9560_Class.h"
#include "fnv/decl/FUN_006b0570_shell.h"
#include "fnv/decl/FUN_006b05d0_shell.h"
#include "fnv/decl/FUN_006b1df0_shell.h"
#include "fnv/decl/FUN_006b3380_shell.h"
#include "fnv/decl/FUN_006b3420_shell.h"
#include "fnv/decl/FloatValueProvider.h"
#include "fnv/decl/GetCenterX_006a6eb0.h"
#include "fnv/decl/Holder670.h"
#include "fnv/decl/LastNodeSearch17.h"
#include "fnv/decl/PSSearchView.h"
#include "fnv/decl/PathSmootherAccess.h"
#include "fnv/decl/S_FUN_006b05a0.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_0068f0c0__FUN_0068f0c0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_006ba000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011d7000.h"
#include "fnv/symbols_011de000.h"
struct NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3 CrossProduct(const NiPoint3&) const;
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator*(float) const;
    NiPoint3& operator*=(float);
    NiPoint3& operator+=(const NiPoint3&);
    float GetLengthSquared();
    static const NiPoint3 ZERO;
public:
    float ComputeMagnitude() const;
};
namespace std {
float abs(float);
}
class NavMeshClosedDoorInfo
{
  public:
    void* pPathNodeDoor;
};
class NavMeshTriangle
{
  public:
};
class NavMeshEdgeVertexPair
{
  public:
    const NiPoint3 *p1, *p2;
};
class NavMeshEdgeData;
class AvoidSphere
{
  public:
};
struct NiPoint3;
class NavMesh
{
  public:
    static void Deallocate(void*);
    NavMeshClosedDoorInfo* GetClosedDoorInfo(unsigned short);
public:
    ::NiPoint3 GetPlaneNormal(unsigned short);
};
class TES
{
  public:
};
class SineCosine
{
  public:
    float fCos, fSin;
    SineCosine(float);
    SineCosine& operator=(const SineCosine&);
    SineCosine operator-(const SineCosine&) const;
    NiPoint3 MakePointOnCircle(float) const;
};
enum ANGLE_DIRECTION
{
    AD_NONE = -1,
    AD_CCW = 0,
    AD_CW = 1
};
class CircularArc
{
  public:
    SineCosine Start, End;
    ANGLE_DIRECTION Direction;
    CircularArc(const SineCosine&, const SineCosine&, ANGLE_DIRECTION);
    CircularArc(const CircularArc&);
    bool FUN_006a0660(const SineCosine&) const;
public:
    float GetLength(float);
};
class Sphere
{
  public:
    NiPoint3 Center;
    float Radius;
    Sphere(const NiPoint3&, float);
};
class SphereTangent
{
  public:
    ANGLE_DIRECTION Direction;
    SineCosine m_kStartAngle, m_kEnd;
};
class SphereTangents
{
  public:
    int Count;
    SphereTangent Tangents[2];
    SphereTangents();
};
class NavMeshPOVSearch
{
  public:
    static int FindSphereTangents(const Sphere&, const Sphere&, ANGLE_DIRECTION, SphereTangents&);
};
class NavMeshEdgePoint
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    int m_iEdgeIndex;
    NiPoint3 Location;
    NavMeshEdgePoint();
    NavMeshEdgePoint& operator=(const NavMeshEdgePoint&);
};
class NavMeshEdgeData
{
  public:
    NavMeshEdgeData();
    NavMeshEdgeData(NavMesh*, unsigned short, int);
    NavMeshEdgeData& operator=(const NavMeshEdgeData&);
    NavMeshEdgeData(const NavMeshEdgeData&);
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    int m_iEdgeIndex;
};
class PathSmootherPOVPoint
{
  public:
    PathSmootherPOVPoint();
    int eType;
    NiPoint3 Center;
    float fRadius;
    NavMeshEdgeData MeshEdgeRecord;
    NiPoint3 m_kFirstEdge, m_kSecondEdge;
    float m_fWeight;
    unsigned int m_uiListIndex, m_uiReferenceIndex, m_uiCompositeId;
    unsigned short m_usResult;
};
class PathSmootherPOVAvoidanceNode
{
  public:
    PathSmootherPOVPoint* m_pAvoidNode;
    ANGLE_DIRECTION Direction;
    float m_fPathDistance;
};
class NavMeshEdgeSegment
{
  public:
    SineCosine m_kStartAngle, m_kEnd;
    NavMeshEdgePoint m_kStartPoint, m_kEndPoint;
};
template <class N, class L> class AStarNode
{
  public:
    unsigned int m_uiSoundID;
    float m_fPathingCostCur;
    N Node;
    L Link;
    const N& FUN_00413f40() const;
    const L& FUN_007d6bb0() const;
    AStarNode* GetField54() const;
    float FUN_006a7f50() const;
};
template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    BSSimpleArray();
    ~BSSimpleArray();
    unsigned int Find(const T&, unsigned int, bool (*)(const T&, const T&));
    class NavMesh* const& FUN_006dad90(unsigned int) const;
    void* vtable;
    T* data;
    unsigned int size, capacity;
    T& operator[](unsigned int) const;
    unsigned int GetSize() const;
    T& GetBufferElementAddress(unsigned int);
    T& FUN_006a1440(unsigned int);
    bool FUN_0076b610() const;
    unsigned int Add(const T&);
    void Clear(bool);
    void GrowCapacity(unsigned int);
    void ReserveIndex(unsigned int);
    unsigned int FUN_0084e3a0();
    const T& GetLastEdge();
    const T& FUN_006b3160(unsigned int) const;
    const T& GetFirstElement() const;
    const T& GetLastElement() const;
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
class NavMeshInfo;
class TESObjectCELL;
struct PathingLocation
{
  public:
    void* vtable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    void* pCell;
    void* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    PathingLocation(const NiPoint3&, const NavMeshInfo*);
    PathingLocation(const NiPoint3&, const NavMeshInfo*, unsigned short);
    ~PathingLocation();
public:
    ::TESObjectCELL *GetContainingCell();
};
class PathingGraphNode
{
  public:
};
class PathingSolution
{
  public:
    char base[0x30];
    BSSimpleArray<void*> Doors;
};
struct PathingRequest
{
  public:
};
typedef AStarNode<PathSmootherPOVAvoidanceNode, NavMeshEdgeSegment> POVNode;
template <class N, class L> class AStarSearch
{
  public:
    virtual ~AStarSearch();
    char searchState[0x2054];
};
class PathSmootherPOVSearch : public AStarSearch<PathSmootherPOVAvoidanceNode, NavMeshEdgeSegment>
{
  public:
      // declared for the original code (decl_variants.py)
  public:
    virtual ~PathSmootherPOVSearch();
    class NavMeshEdgeRecord
    {
      public:
        NavMesh* m_pLocationNavMesh;
        unsigned short m_usVertexId;
        NavMeshEdgeData Edge;
        unsigned int m_uiReferenceIndex, m_uiListIndex, m_uiTrailingValue;
    };

    PathingRequest* pRequest;
    PathingSolution* m_pOutputSolution;
    NiPoint3 m_kPathStartPosition, m_kGoalPosition;
    bool m_bUnderwaterPath;
    const BSSimpleArray<NavMeshTriangleReference>* Triangles;
    const BSSimpleArray<NavMeshTriangleEdgeReference>* Edges;
    BSSimpleArray<PathSmootherPOVPoint*> m_kPrimaryPathPoints, m_kSecondaryPathPoints, m_kRequestPathPoints,
        m_kPathPoints;
    PathSmootherPOVPoint *m_pStartPoint, *m_pGoalPoint;
    BSSimpleArray<PathSmootherPOVAvoidanceNode> Nodes;
    BSSimpleArray<NavMeshEdgeSegment> Links;
    BSSimpleArray<NavMeshEdgeRecord> m_kPrimaryEdgeRecords, m_kSecondaryEdgeRecords;
    BSSimpleArray<const NavMeshInfo*>* m_pNavMeshInfos;
    bool SearchForPath(PathingRequest*, const BSSimpleArray<NavMeshTriangleReference>&,
                       const BSSimpleArray<NavMeshTriangleEdgeReference>&, const NiPoint3&, const NiPoint3&,
                       PathingSolution*, BSSimpleArray<NavMeshTriangleEdgeReference>*,
                       BSSimpleArray<const NavMeshInfo*>*);
    bool FUN_006b2fc0(BSSimpleArray<NavMeshTriangleEdgeReference>*);
    void CollectUniqueNavMeshes();
    void BuildSmoothedPath();
    void AddPathPoints(bool);
    void AddNavMeshEdgeRecord(NavMesh*, unsigned short, const NiPoint3&, const NiPoint3&);
    bool FindPathToPoint(const POVNode*, PathSmootherPOVPoint*, BSSimpleArray<POVNode*>*);
    bool CalculatePathCost(PathSmootherPOVPoint*, PathSmootherPOVPoint*, const NiPoint3&, const NiPoint3&, float*);
    virtual bool CollectConnections(const POVNode*, BSSimpleArray<POVNode*>*);
    virtual bool HasReachedGoal(const POVNode*);
    bool FUN_006b1e50(const NavMeshEdgePoint&, Sphere&, CircularArc, NavMeshEdgePoint*);
    bool FUN_006b23d0(const NavMeshEdgePoint&, Sphere&, CircularArc);
};
class Segment
{
  public:
    NiPoint3 start, end;
    Segment(const NiPoint3&, const NiPoint3&);
};
class SphereIntersection
{
  public:
    unsigned int type;
    NiPoint3 p1;
    float t1;
    NiPoint3 p2;
    float t2;
    SphereIntersection();
};
union SETTING_VALUE
{
    float f;
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
};
#endif
