
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurveclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurveclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00e00000_cls.h"

struct Object
{
    void* vtable;
    unsigned short allocationSize;
    Object* FUN_00e00070(unsigned int flags);
};
// @fnv 0x00e00070
Object* Object::FUN_00e00070(unsigned int flags)
{
    reinterpret_cast<::FUN_00e00000_cls *>(this)->FUN_00e00000();
    if (flags & 1)
    {
        hkMemoryRouter* state = &hkMemoryRouter::getInstance();
        unsigned int size = allocationSize;
        state->m_heap->blockFree(this, size);
    }
    return this;
}
