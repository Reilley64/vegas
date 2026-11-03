
// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesconnectivityclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convexvertices/hkpconvexverticesconnectivityclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"



struct FUN_00e00e40
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00e00e40();
    virtual ~FUN_00e00e40();

    static void operator delete(void* p, size_t nbytes)
    {
        FUN_00e00e40* b = static_cast<FUN_00e00e40*>(p);
        hkMemoryRouter::getInstance().heap().blockFree(p, b->m_usMemSizeAndFlags);
    }
};

// Constructor with an empty body; the class has a vtable, m_usMemSizeAndFlags and m_sReferenceCount.
// @fnv 0x00e00e40
FUN_00e00e40::FUN_00e00e40()
{}
