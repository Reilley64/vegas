
// src/bsshader/bsshaderproperty_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshaderproperty.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_0043a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f6000.h"
#include "bsshaderproperty_decls.h"

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
struct PoolMemoryAllocator
{
};
struct FUN_0043a010_t
{
    unsigned int m_pNext;
    unsigned int m_pInventoryEntryData;
    unsigned int m_pItem2;
};
struct FUN_0043a010_shell
{
    FUN_0043a010_t* FUN_0043a010();
};
// @fnv 0x0043a010
FUN_0043a010_t* FUN_0043a010_shell::FUN_0043a010()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
    if (DAT_011c5f58 == 0)
        ::FUN_0043a080();
    FUN_0043a010_t* pkNode = (FUN_0043a010_t*)DAT_011c5f58;
    DAT_011c5f58 = (void*)((FUN_0043a010_t*)DAT_011c5f58)->m_pNext;
    pkNode->m_pItem2 = 0;
    pkNode->m_pNext = 0;
    pkNode->m_pInventoryEntryData = 0;
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fba0();
    return pkNode;
}

#include "generated/data/bsshader/bsshaderproperty_od_variant.inc"
