// src/havok/physics/utilities/serialize/display/hkpserializeddisplayrbtransformsclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/display/hkpserializeddisplayrbtransformsclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00e3a3d0__hkpConstraintChainMapperE3A3.h"
struct Owner
{
    unsigned int unk00;
    unsigned short size4, unk06;
    Owner* FUN_00dfc490(unsigned int flags);
};
// Calls FUN_00e3a3d0, and if flags has bit 0 set, releases this object through the hkMemoryRouter allocator using size4 bytes, then returns this.
// @fnv 0x00dfc490
Owner* Owner::FUN_00dfc490(unsigned int flags)
{
    reinterpret_cast<::FUN_00e3a3d0::hkpConstraintChainMapperE3A3 *>(this)->FUN_00e3a3d0::hkpConstraintChainMapperE3A3::~hkpConstraintChainMapperE3A3();
    if (flags & 1u)
    {
        hkMemoryRouter* audio = &hkMemoryRouter::getInstance();
        unsigned int bytes = size4;
        audio->m_heap->blockFree(this, bytes);
    }
    return this;
}
