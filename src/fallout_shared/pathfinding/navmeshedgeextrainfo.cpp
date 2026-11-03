// fallout_shared/pathfinding/navmeshedgeextrainfo.cpp: EdgeExtraInfo, EdgeHolder (2 functions)

#include "fnv/decl/DFD0Data.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/symbols_011de000.h"
#include "navmeshedgeextrainfo_decls.h"

// @fnv 0x00694de0
EdgeExtraInfo* EdgeExtraInfo::DeserializeFromFile()
{
    vtable = &DAT_0106b0dc;
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->FUN_006b3eb0(0, false);
    return this;
}

struct TES
{
};
struct PortalHolder
{
};
struct EdgeHolder
{
    void FUN_0069d240(void* a, void* b);
};
// @fnv 0x0069d240
void EdgeHolder::FUN_0069d240(void* apArg1, void* apArg2)
{
    *(int*)this = 0;
    reinterpret_cast<::DFD0Data *>((((PortalHolder*)((char*)this + 4))))->LoadFormRef(((void *)(reinterpret_cast<::Owner45A *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_0045af00())), {}, {});
}
