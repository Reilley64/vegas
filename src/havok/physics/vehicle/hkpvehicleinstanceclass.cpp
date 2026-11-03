// src/havok/physics/vehicle/hkpvehicleinstanceclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstanceclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00e38bf0.h"

struct FUN_00dfbe50_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;


    FUN_00dfbe50_cls* FUN_00dfbe50(unsigned char acFlags);
};

// Calls FUN_00e38bf0, then if bit 0 of acFlags is set frees this via the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00dfbe50
FUN_00dfbe50_cls* FUN_00dfbe50_cls::FUN_00dfbe50(unsigned char acFlags)
{
    reinterpret_cast<::FUN_00e38bf0 *>(this)->FUN_00e38bf0::~FUN_00e38bf0();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* pAllocator = pHolder->m_heap;
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
