// fallout_shared/pathfinding/navmesh_util_decls.h: declares NiPoint3, TwoIntRecord, NavMeshEdgeData, NavMeshTriangleHandle, NavMeshPOVData and more
#ifndef NAVMESH_UTIL_DECLS_H
#define NAVMESH_UTIL_DECLS_H

#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_005582d0_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0068f0a0_shell.h"
#include "fnv/decl/FUN_0068f1d0_shell.h"
#include "fnv/decl/FUN_0068f2c0_shell.h"
#include "fnv/decl/FUN_00691570_shell.h"
#include "fnv/decl/FUN_006a0840_shell.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_0069b000.h"
#include <cmath>
struct NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3 Cross(const NiPoint3&) const;
    NiPoint3 CrossProduct(const NiPoint3&) const;
    static const NiPoint3 ZERO;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
};
bool FUN_006b9cf0(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, float&, float, float);
class NavMesh;
class TwoIntRecord
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usVertexId;
    TwoIntRecord();
    TwoIntRecord(NavMesh*, unsigned short);
    TwoIntRecord(const TwoIntRecord&);
    TwoIntRecord& operator=(const TwoIntRecord&);
};
class NavMeshEdgeData
{
  public:
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    int m_iEdgeIndex;
    NavMeshEdgeData();
    NavMeshEdgeData(NavMesh*, unsigned short, int);
    NavMeshEdgeData& operator=(const NavMeshEdgeData&);
};
class NavMeshTriangleHandle
{
  public:
    unsigned short m_usIndex;
};
class NavMeshPOVData
{
  public:
    NavMeshTriangleHandle m_kFirstEdge, m_kSecondEdge;
};
template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    void* vtable;
    T* data;
    unsigned int size, capacity;
    BSSimpleArray();
    ~BSSimpleArray();
    unsigned int GetSize();
    void Clear(bool);
    unsigned int ReserveIndex(const T&);
    T& FUN_006a1440(unsigned int);
    unsigned short& GetBufferEntry(unsigned int);
    unsigned int AppendElement(const T&);
    unsigned int Append(const T&);
    T& GetElement(unsigned int);
};
template <> BSSimpleArray<unsigned short, 1024>::BSSimpleArray();
class NavMeshVertexEdgeData
{
  public:
    TwoIntRecord m_kVertexKey;
    BSSimpleArray<NavMeshEdgeData> Edges, m_kOutgoingEdges;
    NavMeshVertexEdgeData();
    ~NavMeshVertexEdgeData();
};
template <class K, class V> class NiTPointerMap
{
  public:
    void* vtable;
    unsigned int hashSize;
    void* table;
    unsigned int count;
    void RemoveAll();
    void* GetFirstPos();
    void InsertOrUpdate(unsigned short, NavMeshPOVData);
    void FUN_00694d30(void*&, unsigned short&, NavMeshPOVData&);
};
class NavMeshVertexMap
{
  public:
    void* vtable;
    unsigned int hashSize;
    void* table;
    unsigned int count;
    NavMeshVertexMap(unsigned int);
    ~NavMeshVertexMap();
};
class NavMeshTriangle
{
  public:
};
struct NavMeshEdgeVertexPair
{
    const NiPoint3* first;
    const NiPoint3* second;
};
class NavMeshClosedDoorInfo
{
  public:
    unsigned int iDoorID;
    unsigned short m_usTriangleID;
    NavMeshClosedDoorInfo();
};
class ObstacleData
{
  public:
    unsigned char prefix[0x40];
    NiPoint3 m_kBoundsMin, m_kBoundsMax;
};
template <class T> class NiPointer
{
  public:
    T* object;
    NiPointer(T*);
    NiPointer(const NiPointer&);
    ~NiPointer();
};
struct NiPoint3;
class NavMeshVertex;
class EdgeExtraInfo;
class NavMeshTriangleDoorPortal;
class NavMeshStaticAvoidNode;
class NavMeshInfo;
class NavMesh
{
  public:
    unsigned char prefix[0x28];
    BSSimpleArray<NavMeshVertex> Vertices;                         // +0x28
    BSSimpleArray<NavMeshTriangle> Triangles;                      // +0x38
    BSSimpleArray<EdgeExtraInfo> m_kEdgeExtraInfo;                 // +0x48
    BSSimpleArray<NavMeshTriangleDoorPortal> m_kDoorPortals;       // +0x58
    BSSimpleArray<NavMeshClosedDoorInfo> m_kClosedDoorInfo;        // +0x68
    BSSimpleArray<unsigned short> m_kIndexList;                    // +0x78
    NiTPointerMap<unsigned int, unsigned int> POVPointerArray;     // +0x88
    BSSimpleArray<unsigned short> m_kAdditionalIndexList;          // +0x98
    unsigned char m_kGrid[0x28];                                   // +0xA8
    BSSimpleArray<void*> m_kObstacleUndoData;                      // +0xD0
    void* pTriangleToObstacleMap;                                  // +0xE0
    BSSimpleArray<unsigned short> m_kAdditionalData;               // +0xE4
    BSSimpleArray<NavMeshStaticAvoidNode> m_kStaticAvoidNodes;     // +0xF4
    NavMeshInfo* m_pNavigationMesh;                                // +0x104
    NavMeshTriangle* GetTriangle(unsigned short);
    NavMeshEdgeVertexPair FUN_0068f040(unsigned short, int);
    NiPoint3 FUN_00697290(unsigned short);
    NiPoint3 GetPlaneNormal(unsigned short);
    bool AddDoorObstacle(unsigned int, ObstacleData*);
    NavMeshClosedDoorInfo* GetClosedDoorInfo(unsigned short);
    bool FindHeightOnTriangle(unsigned short, const NiPoint3&, float&, float, float);
public:
    ::NiPoint3 GetNavMeshData(unsigned short);
};
#endif
class SineCosine
{
  public:
    float sine, cosine;
    SineCosine operator-(const SineCosine&) const;
};
class CircularArc
{
  public:
    SineCosine Start, End;
    int Dir;
    float GetLength(float);
};
