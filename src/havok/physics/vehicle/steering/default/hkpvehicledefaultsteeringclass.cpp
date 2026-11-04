
// src/havok/physics/vehicle/steering/default/hkpvehicledefaultsteeringclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/steering/default/hkpvehicledefaultsteeringclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"


struct S_00dfee20_Array
{
    unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(unsigned char));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00dfee20_Array() throw()
    {
        _clearAndDeallocate(hkMemoryRouter::getInstance().heap());
    }
};

struct S_00dfee20_Base
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    S_00dfee20_Base();
    virtual ~S_00dfee20_Base() throw()
    {}
    static void operator delete(void* p)
    {
        S_00dfee20_Base* b = static_cast<S_00dfee20_Base*>(p);
        hkMemoryRouter::getInstance().heap().blockFree(p, b->m_usMemSizeAndFlags);
    }
};

struct __declspec(novtable) S_00dfee20 : S_00dfee20_Base
{
    int unk8;
    int unkC;
    S_00dfee20_Array unk10;

    virtual ~S_00dfee20() throw()
    {}
    S_00dfee20* DestroyAndMaybeFree(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, frees the object via operator delete; returns this.
// @fnv 0x00dfee20
S_00dfee20* S_00dfee20::DestroyAndMaybeFree(unsigned int flags)
{
    this->S_00dfee20::~S_00dfee20();
    if (flags & 1)
        operator delete(this);
    return this;
}
