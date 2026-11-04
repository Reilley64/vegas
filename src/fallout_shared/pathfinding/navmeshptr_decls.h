// fallout_shared/pathfinding/navmeshptr_decls.h: declares NavMeshInfo
#ifndef NAVMESHPTR_DECLS_H
#define NAVMESHPTR_DECLS_H

#include "fnv/symbols_00690000.h"
class NavMesh;
class NavMeshPtr;
class NavMeshInfo
{
  public:
    char padding[0x54];
    NavMesh* m_pLocationNavMesh;
    bool AcquireNavMesh(NavMeshPtr& out);
};
#endif
