
// src/havok/physics/vehicle/hkpvehicledataclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicledataclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"


struct FUN_00dfc1e0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dfc1e0();
    virtual ~FUN_00dfc1e0();

    static void operator delete(void* p, size_t nbytes)
    {
        FUN_00dfc1e0* b = static_cast<FUN_00dfc1e0*>(p);
        hkMemoryRouter::getInstance().heap().blockFree(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00dfc1e0
FUN_00dfc1e0::FUN_00dfc1e0()
{}
