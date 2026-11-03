// fallout_shared/pathfinding/navmeshsearchlos_decls.h: declares NavMeshSearchLOSArray
#ifndef NAVMESHSEARCHLOS_DECLS_H
#define NAVMESHSEARCHLOS_DECLS_H
#include "fnv/decl/S_006ac070.h"
#include "fnv/symbols_006a8000.h"
class NavMeshSearchLOSArray
{
  public:
    unsigned int allocator;
    void* data;
    unsigned int size;
    unsigned int capacity;
    void Clear(bool freeStorage);
};
#endif
