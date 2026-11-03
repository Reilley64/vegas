// fallout_shared/pathfinding/navmesh.h: declares CenterCalculation
#ifndef FNV_NAVMESH_H
#define FNV_NAVMESH_H

#include "fnv/decl/FUN_005582d0_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0068f0a0_shell.h"
#include "fnv/decl/MyPoint439180.h"
#include "navmesh_decls.h"
// @fnv 0x00558220
NiPoint3 NavMesh::GetNavMeshData(unsigned short m_usTriangleID)
{
    struct CenterCalculation
    {
        NiPoint3 Center;
        NavMeshTriangle* pTriangle;
    } calculation;
    calculation.pTriangle = GetTriangle(m_usTriangleID);
    calculation.Center = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((calculation.pTriangle))->FUN_005582d0(0))));
    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(calculation.Center))->FUN_0063c8a0((void *)&((*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((calculation.pTriangle))->FUN_005582d0(1))))));
    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(calculation.Center))->FUN_0063c8a0((void *)&((*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(this)->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((calculation.pTriangle))->FUN_005582d0(2))))));
    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(calculation.Center))->FUN_00439180(DAT_0102f200);
    return calculation.Center;
}
#endif
