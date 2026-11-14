// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapperclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkppoweredchainmapperclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00e3ad80__hkpPoweredChainMapper.h"
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* FUN_00dfc540(unsigned int flags);
};
// @fnv 0x00dfc540
CpuObject* CpuObject::FUN_00dfc540(unsigned int flags)
{
    reinterpret_cast<::FUN_00e3ad80::hkpPoweredChainMapper *>(this)->FUN_00e3ad80::hkpPoweredChainMapper::~hkpPoweredChainMapper();
    if (flags & 1)
    {
        hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}
