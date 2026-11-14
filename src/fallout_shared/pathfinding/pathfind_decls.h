
// Shared classes come from the canonical include/ headers: NiPoint3, AutoMemContext/MEM_CONTEXT, NiTPointerMap,
// MobileObject/TESObjectREFR forward declarations. Explicit ../../../include/ paths: pathfinding/PathingLocation.h
// and src/fallout_shared/layout_support.h shadow the canonical names (case-insensitive include lookup under Wine).
// Unit-local supersets of canonical types (same layout), for members the canonical headers do not declare yet:
//   PathingLocation: ctors/dtor, copy ctor, operator=, GetLocation and the navmesh queries used by matched code.
//   BSSimpleArray: Add.   NiPointer: smart-pointer API (canonical NiPointer bodies need a complete T).
#include <cstdint>
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_006e78b0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0096aaf0_shell.h"
#include "fnv/decl/PathBuilderCore.h"
#include "fnv/decl/This152.h"
#include "fnv/decl/fnv_006f49c0__FUN_006f49c0_shell.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_006d0000.h"
#include "fnv/symbols_006d1000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_006d7000.h"
#define NiPointer FNV_NiPointer_Canonical
#define BSSimpleArray FNV_BSSimpleArray_Canonical
#define PathingLocation FNV_PathingLocation_Canonical
#include "../../../include/layout_support.h"
#include "../../../include/NiPoint3.h"
#undef PathingLocation
#undef BSSimpleArray
#undef NiPointer
// packet's first-definition-wins type index shows them (not the renamed canonical text).
#include "pathfind_local_types.h"
#define BSSimpleArray FNV_BSSimpleArray_Canonical
#define PathingLocation FNV_PathingLocation_Canonical
#include "../../../include/PathingLocation.h"
#undef PathingLocation
#undef BSSimpleArray
#include "../../../include/AutoMemContext.h"
class PathfindQueueStorage
{
  public:
};
class ActorDeletionQueue
{
    unsigned int pad;
    PathfindQueueStorage storage;

  public:
    void FUN_0096d470(MobileObject*, intptr_t);
};
struct PathingLocation;
class FindTriangleForLocationFilter;
class NavMeshTriangle;
struct NiPoint3;
class NavMesh
{
  public:
    NiPoint3 GetNavMeshData(unsigned short);
public:
    ::NavMeshTriangle *GetTriangle(unsigned short);
public:
    ::NiPoint3 GetPlaneNormal(unsigned short);
};
struct NavMeshPtr : public NiPointer<NavMesh>
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
public:
    ::NavMeshPtr &operator=(const ::NavMeshPtr &);
};
class PathingLocationProxy
{
  protected:
    void* table;

  public:
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
};
class NavMesh;
class PathingActorData;
class PathingPath
{
  public:
    void* a;
    unsigned int b, c, d;
    void* e;
    unsigned int f, g, h;
    float i, j, k, l, m, n;
    PathingPath();
    ~PathingPath();
};
class TESObjectREFR;
class PathingSolution;
enum PATHING_REQUEST_TYPE
{
    RequestLocation = 0,
    RequestClosePoint = 3,
    RequestHide = 4,
    RequestFlee = 5,
    RequestLOS = 6,
    RequestOptimal = 7,
    RequestUnknown = 8
};
struct PathingLocation;
template <class, unsigned int> class BSSimpleArray;
struct PathingRequest
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual PATHING_REQUEST_TYPE GetType();
    char layoutPadding4[0xAC];
public:
    void SetDestination(::PathingLocation *);
public:
    void SetAvoidNodeArray(::BSSimpleArray<void *, 1024> *);
public:
    float GetActorRadius();
};
class PathingRequestClosePoint : public PathingRequest
{
};
class PathingRequestHide : public PathingRequest
{
};
class PathingRequestFlee : public PathingRequest
{
};
class PathingRequestLOS : public PathingRequest
{
};
class PathingRequestOptimalLocation : public PathingRequest
{
  public:
    float afTargetPoint[3];  // +0xB0
    float fUnkBC;
    float fUnkC0;
    char padC4[8];
    unsigned char ucUnkCC;
    unsigned char ucUnkCD;
    unsigned char ucUnkCE;
    unsigned char ucUnkCF;
    unsigned char ucUnkD0;
    unsigned char ucUnkD1;
};
class PathingRequestUnknown : public PathingRequest
{
};
bool FUN_006d0be0(PathingRequestClosePoint*, PathingSolution*);
class Pathing
{
    unsigned char pad[28];
    NiTPointerMap<unsigned int, TESObjectREFR*> map;

  public:
    static bool BuildPath(PathingRequest*, PathingSolution*);
    TESObjectREFR* FindReferenceByFormId(unsigned int);
    class CheckLineOfSightFilter;
    enum TELEPORT_DOOR_PATH_RESTRICTION
    {
        RestrictionNone = 0
    };
    enum DOOR_LOCK_DISPOSITION
    {
        LockDefault = 0
    };
    static bool FindClosestPathingPoint(TESWorldSpace*, TESObjectCELL*, const NiPoint3&, NiPoint3*);
    static float FindPathDistance(const PathingLocation&, const PathingLocation&, float, PathingActorData*,
                                  DOOR_LOCK_DISPOSITION);
    static bool FindPathingLocation(PathingLocation&, const NiPoint3&, PathingLocation*, CheckLineOfSightFilter*);
};
class TESPackage
{
  public:
};
class PathingGraphNode
{
  public:
};
class PacketNodeRecord : public PathingGraphNode
{
  public:
};
class PathingSolution
{
  public:
};
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    T& GetAt(int index);
    unsigned int Add(const T&);
};
class PathBuilder
{
  public:
    void* field0;
    PathingSolution* solution;
    void* field8;
    void* fieldC;
    bool skipTransitions;
    int AppendPathNodeLocations(int, BSSimpleArray<PathingLocation, 1024>*, TESObjectREFR*);
};
