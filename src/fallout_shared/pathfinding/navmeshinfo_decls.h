// fallout_shared/pathfinding/navmeshinfo_decls.h: declares NavMeshPtr, NavMeshInfo, PathingLocationData, PathingLocation
#ifndef NAVMESHINFO_DECLS_H
#define NAVMESHINFO_DECLS_H

#include "fnv/decl/FUN_0069dfb0_class.h"
#include "fnv/symbols_0068f000.h"
#include "fnv/symbols_00690000.h"
class NavMesh;
class NiNode;
template <class T> class NiPointer
{
  public:
    T* m_ptr;
    T* operator->() const;
};
struct NavMeshPtr : public NiPointer<NavMesh>
{
};
class NavMeshInfo
{
  public:
    char pad[0x54];
    NavMesh* m_pLocationNavMesh;
    bool ResolveNavMesh(NavMeshPtr&);
};
class PathingLocationData
{
  public:
};
struct PathingLocation
{
  public:
    char pad[0x10];
    PathingLocationData* data;
    char pad2[0x10];
    unsigned short triangle;
    bool HasValidTriangle_006dd6a0();
};
#endif
