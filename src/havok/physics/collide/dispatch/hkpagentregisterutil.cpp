
// src/havok/physics/collide/dispatch/hkpagentregisterutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/hkpagentregisterutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00cfb1e0.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_00d42000.h"
#include "fnv/symbols_00d43000.h"
#include "fnv/symbols_00d44000.h"
#include "fnv/symbols_00d45000.h"
#include "fnv/symbols_00d46000.h"
struct FlagCBFD
{
    bool m_bValue;
    FlagCBFD(bool bValue) : m_bValue(bValue)
    {}
    FlagCBFD(const FlagCBFD& kOther) : m_bValue(kOther.m_bValue)
    {}
};

class WorldCBFD
{
  public:
};


// Calls a sequence of registration and configuration functions on pkWorld, toggling a flag between two of them.
// @fnv 0x00cbfd20
void __cdecl InitializeWorld(WorldCBFD* pkWorld)
{
    ::FUN_00d46410((::hkpCollisionDispatcher *)(pkWorld));
    ::ConfigureVtblHandlers((::FUN_00cfbbe0 *)(pkWorld));
    ::RegisterTwoTables((::RegistryOwner *)(pkWorld));
    ::RegisterAll((::CBFC10Registry *)(pkWorld));
    reinterpret_cast<::FUN_00cfb1e0 *>((pkWorld))->Set((*(bool *)&(const ::FlagCBFD &)(FlagCBFD(false))));
    ::FUN_00d44310((::Agent *)(pkWorld));
    reinterpret_cast<::FUN_00cfb1e0 *>((pkWorld))->Set((*(bool *)&(const ::FlagCBFD &)(FlagCBFD(true))));
    ::FUN_00cbfc60((::CBFC60Dispatcher *)(pkWorld));
    ::RegisterCallbacks((::Agent *)(pkWorld));
    ::FUN_00d42960((::Agent *)(pkWorld));
    ::FUN_00cbfcb0(pkWorld);
}
