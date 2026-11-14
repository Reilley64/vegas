// src/bssystemutilities/bsmsgdialogsystemutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystemutilities/bsmsgdialogsystemutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/FUN_00af3420_Class.h"
#include "fnv/symbols_011f6000.h"
// The complete native owner is defined in canonical_memory_manager.cpp.

struct FUN_00af3440_shell
{
    void* FUN_00af3440(unsigned int flags);
};

// Calls FUN_00af3420, then if bit 0 of flags is set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00af3440
void* FUN_00af3440_shell::FUN_00af3440(unsigned int flags)
{
    reinterpret_cast<::FUN_00af3420_Class *>(this)->FUN_00af3420();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
