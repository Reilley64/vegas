// src/havok/physics/vehicle/transmission/default/hkpvehicledefaulttransmissionclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/transmission/default/hkpvehicledefaulttransmissionclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/fnv_00dfed30__Holder.h"

struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* FUN_00dfedb0(unsigned int flags);
};
// Calls FUN_00dfed30, then if bit 0 of flags is set, invokes the allocator's Invoke on this with size, and returns this.
// @fnv 0x00dfedb0
CpuObject* CpuObject::FUN_00dfedb0(unsigned int flags)
{
    reinterpret_cast<::fnv_00dfed30::Holder *>(this)->FUN_00dfed30();
    if (flags & 1)
    {
        hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}
