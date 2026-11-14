// bssystemutilities/bscachedrivesystemutility.cpp: BSCacheDriveSystemUtility (3 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00af3900_Class.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "BSCacheDriveSystemUtility.h"

// @fnv 0x00af3940
void BSCacheDriveSystemUtility::Destroy()
{}

struct FUN_00af3920_shell : public BSCacheDriveSystemUtility
{
    void FUN_00af3920();
};

struct VTableHelper_00af3920
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

// @fnv 0x00af3920
void FUN_00af3920_shell::FUN_00af3920()
{
    reinterpret_cast<VTableHelper_00af3920*>(this)->v2();
}

struct MemoryManager
{
};
struct Host03950
{
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00af3900, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00af3950
void* Host03950::ReleaseIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00af3900_Class *>(this)->FUN_00af3900();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
