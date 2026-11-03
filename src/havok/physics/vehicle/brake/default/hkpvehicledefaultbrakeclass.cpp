
// src/havok/physics/vehicle/brake/default/hkpvehicledefaultbrakeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/brake/default/hkpvehicledefaultbrakeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"


struct S_00dfc080_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    virtual ~S_00dfc080_RefObj() throw()
    {}
    static void operator delete(void* p, size_t)
    {
        S_00dfc080_RefObj* b = static_cast<S_00dfc080_RefObj*>(p);
        hkMemoryRouter::getInstance().heap().blockFree(p, b->m_usMemSizeAndFlags);
    }
};

struct S_00dfc080_Elem
{
    int unk0;
    int unk4;
    int unk8;
};

template <class T> struct S_00dfc080_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~S_00dfc080_Array() throw()
    {
        _clearAndDeallocate(hkMemoryRouter::getInstance().heap());
    }
};

struct __declspec(novtable) S_00dfc080 : S_00dfc080_RefObj
{
    S_00dfc080_Array<S_00dfc080_Elem> m_ppData;
    virtual ~S_00dfc080() throw()
    {}
    S_00dfc080* DestroyAndFree(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, frees the object; returns this.
// @fnv 0x00dfc080
S_00dfc080* S_00dfc080::DestroyAndFree(unsigned int flags)
{
    this->S_00dfc080::~S_00dfc080();
    if (flags & 1)
        operator delete(this, sizeof(S_00dfc080));
    return this;
}
