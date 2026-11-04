// fallout_shared/pathfinding/navmesharray.h: declares NavMeshCollection
#ifndef NAVMESHARRAY_H
#define NAVMESHARRAY_H

#include "fnv/decl/Twin_0044ddc0.h"
#include "navmesharray_decls.h"
class NavMeshCollection
{
  public:
    GlobalObject_00869f00 m_kGlobalObject;
    NavMeshPtr GetNavMeshAt(unsigned int index);
};
// @fnv 0x00464f60
NavMeshPtr NavMeshCollection::GetNavMeshAt(unsigned int index)
{
    if (index >= ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kGlobalObject))->GetName())))
        return MakeNavMeshPointer(0);
    return reinterpret_cast<const NavMeshPtr&>(m_kGlobalObject.GetAt(index));
}
#endif
