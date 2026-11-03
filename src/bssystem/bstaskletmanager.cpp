
// src/bssystem/bstaskletmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystem/bstaskletmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_010a4000.h"
#include "fnv/symbols_011f6000.h"
struct MemoryManager
{
    void* __thiscall _DeallocateAlias(void*);
};

extern "C" void* __cdecl _DeallocateAlias(void*);

struct BSTaskletManagerCallback
{
    int* vtable;
    void* __thiscall Destroy(unsigned int flags);
};

// Sets the vtable to DAT_010a47b8 and, when flags has bit 0 set, deallocates this through g_memoryManager, returning this.
// @fnv 0x00b00e90
void* __thiscall BSTaskletManagerCallback::Destroy(unsigned int flags)
{
    this->vtable = &DAT_010a47b8;
    if (flags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    }
    return this;
}
