// src/havok/physics/utilities/serialize/hkpphysicsdataclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpphysicsdataclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/fnv_00d4c250__FUN_00d4c250.h"



struct FUN_00d48370_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;


    FUN_00d48370_cls* FUN_00d48370(unsigned char acFlags);
};

// Calls FinishObject, then if acFlags bit 0 is set frees this object through the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00d48370
FUN_00d48370_cls* FUN_00d48370_cls::FUN_00d48370(unsigned char acFlags)
{
    reinterpret_cast<::fnv_00d4c250::FUN_00d4c250 *>(this)->fnv_00d4c250::FUN_00d4c250::~FUN_00d4c250();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* pAllocator = pHolder->m_heap;
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
