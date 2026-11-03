
// src/gamebryo2.2/corelibs/nimain/niglobalstringtable_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niglobalstringtable.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <new>
#include "fnv/decl/EC2DF0Registry.h"
#include "fnv/decl/FUN_00a5b530.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MovieSignalState.h"
#include "fnv/decl/StringTable169.h"
#include "fnv/decl/ThreadedTable.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_0126f000.h"
#include "niglobalstringtable_decls.h"
// 1 Nov: the base unit's #pragma optimize lines removed here (they turned /O2 off for every function added; 0x00a5b630)
#pragma intrinsic(strlen)
#pragma function(strlen, strcpy)

struct P03MM
{
};

// @fnv 0x00a5b630
void FUN_00a5b630()
{
    NiGlobalStringTable* allocatedTable = static_cast<NiGlobalStringTable*>(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(0x2100));
    if (allocatedTable)
    {
        DAT_011f42c0 = ((::NiGlobalStringTable *)(new ((void *)(allocatedTable)) class ::FUN_00a5b530()));
        return;
    }
    DAT_011f42c0 = 0;
}
