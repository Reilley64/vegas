// fallout_shared/pathfinding/navmeshobstacletask_decls.h: declares ObstacleSource, ObstacleData, NavMeshPtr, NavMeshInfo, ObstacleTask and more
#ifndef NAVMESHOBSTACLETASK_DECLS_H
#define NAVMESHOBSTACLETASK_DECLS_H

#include "fnv/decl/TESForm.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_006c0000.h"
class NavMesh;
class NiAVObject;
class NiNode;
class NavMeshEdgeData;
class ObstacleSource
{
  public:
    char padding[8];
    unsigned int id;
};
class ObstacleData
{
  public:
    char padding[8];
    ObstacleSource* source;
};
template <class T> class NiPointer
{
  public:
    T* ptr;
    bool operator==(const NiPointer&) const;
    T* operator->() const;
};
class NavMeshPtr
{
  public:
    NavMesh* ptr;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NavMeshPtr&);
    NavMesh* operator->() const;
};
class NavMeshInfo
{
  public:
    unsigned int id;
    bool ResolveNavMesh(NavMeshPtr&);
};
enum OBSTACLE_TASK_TYPE
{
    ADD = 16,
    ADD_UPDATE = 17,
    REMOVE = 32,
    REMOVE_UPDATE = 33,
    ADD_DOOR = 48,
    REMOVE_DOOR = 64
};
class ObstacleTask
{
  public:
    NiPointer<ObstacleData> m_spRegisteredObstacle;
    OBSTACLE_TASK_TYPE eType;
    unsigned int m_kResult;
    NavMeshPtr apSearchNavMesh;
    ObstacleTask(const NiPointer<ObstacleData>&, OBSTACLE_TASK_TYPE, const NavMeshPtr&);
    ~ObstacleTask();
};
class NavMeshTriangle;
class GlobalObject_00869f00
{
  public:
};
template <class T, int N> class BSSimpleArray : public GlobalObject_00869f00
{
  public:
    void* vtable;
    T* buffer;
    unsigned int size;
    unsigned int capacity;
    T& operator[](unsigned int);
    T* FUN_00558dd0(unsigned short);
    T& FUN_006a1440(unsigned int);
    void Remove(unsigned int, bool);
    void AppendValue(const T&);
};
class NavMeshEdgeReference
{
  public:
    NavMeshInfo* pInfo;
    unsigned int triangle;
    unsigned int edge;
};
class ParentChildLinks
{
  public:
    BSSimpleArray<NavMeshEdgeReference, 1024> children, parents;
};
class ObstacleTaskData
{
  public:
    char padding[24];
    NavMeshInfo* pInfo;
    NavMeshPtr m_spSourceNavMesh;
    NavMeshPtr m_spWorkingNavMesh;
    BSSimpleArray<ObstacleTask, 1024> Operations;
    ParentChildLinks m_kParentChildLinks;
    bool AddOperation(const NiPointer<ObstacleData>&, OBSTACLE_TASK_TYPE);
    void Process();
};
class BGSLoadGameBuffer;
class Interface
{
  public:
};
enum MEM_CONTEXT
{
    MEM_CONTEXT_NAVMESH = 46
};
class AutoMemContext
{
  public:
    unsigned int context;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NavMesh : public NiMemObject
{
  public:
    char padding[264];
    NavMesh();
    void CopyNavMeshDataTo(NavMeshPtr&);
    bool Search(const NiPointer<ObstacleData>&, ParentChildLinks&);
    bool RemoveObstacleAndUpdateLinks(const NiPointer<ObstacleData>&, ParentChildLinks&);
    bool AddDoorObstacle(unsigned int, ObstacleData*);
    bool RemoveDoorObstacle(unsigned int);
public:
    void ForceSetFormID(unsigned int);
};
class LockPrimitive
{
  public:
};
class NavMeshObstacleManager
{
  public:
    void AddProcessedTask(ObstacleTaskData*);
};
// The canonical binding is a folded array accessor with a narrower index type.
// Preserve its symbol while using the 32-bit index ABI observed at these call sites.
#define OPERATION_AT(array, index)                                                                                     \
    (reinterpret_cast<BSSimpleArray<NavMeshTriangle, 1024>&>(array).*                                                  \
     reinterpret_cast<ObstacleTask& (BSSimpleArray<NavMeshTriangle, 1024>::*)(unsigned int)>(                          \
         &BSSimpleArray<NavMeshTriangle, 1024>::FUN_00558dd0))(index)
typedef BSSimpleArray<NavMeshEdgeData, 1024> BoundEdgeArray;
#define EDGE_AT(array, index)                                                                                          \
    (reinterpret_cast<BoundEdgeArray&>(array).*                                                                        \
     reinterpret_cast<NavMeshEdgeReference& (BoundEdgeArray::*)(unsigned int)>(&BoundEdgeArray::FUN_006a1440))(index)
typedef NiPointer<NiNode> BoundSmartPointer;
#define NAVMESH_FROM(pointer)                                                                                          \
    (reinterpret_cast<const BoundSmartPointer&>(pointer).*                                                             \
     reinterpret_cast<NavMesh* (BoundSmartPointer::*)() const>(&BoundSmartPointer::operator->))()
#define OBSTACLE_FROM(pointer)                                                                                         \
    (reinterpret_cast<const BoundSmartPointer&>(pointer).*                                                             \
     reinterpret_cast<ObstacleData* (BoundSmartPointer::*)() const>(&BoundSmartPointer::operator->))()
#endif
