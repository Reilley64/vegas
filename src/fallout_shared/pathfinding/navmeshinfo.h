
#include "fnv/decl/FUN_0069dfb0_class.h"
#include "fnv/symbols_0068f000.h"
#include "fnv/symbols_00690000.h"
#include "navmeshinfo_decls.h"
// @fnv 0x0069ad00
bool NavMeshInfo::ResolveNavMesh(NavMeshPtr& out)
{
    if (::FUN_0068f320((const ::NavMeshInfo *)this))
        return false;
    ::ProcessWithScopedRef((::DecompRefOwner *)&(out), m_pLocationNavMesh);
    return ((const NiPointer<NiNode>&)out).operator->() ? true : false;
}
// @fnv 0x006dd6a0
bool PathingLocation::HasValidTriangle_006dd6a0()
{
    if (data == 0)
        return false;
    if (!reinterpret_cast<::FUN_0069dfb0_class *>((data))->HasNonZeroAtOffset54())
        return false;
    if (triangle == 0xffff)
        return false;
    return true;
}
