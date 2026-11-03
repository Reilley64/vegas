
// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppcodegenerator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/assembler/hkpmoppcodegenerator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include <cstddef>
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_0102e000.h"
extern "C"
{
    void __cdecl FUN_00c856c0(void*, void*);
}
extern void* DAT_010ea5b4;
struct Buffer
{
    void* data;
    int size;
    unsigned int capacity;
    __forceinline void clear(hkMemoryAllocator& allocator)
    {
        unsigned int flags = capacity;
        size = 0;
        if ((flags & 0x80000000u) == 0)
        {
            allocator.bufFree(data, (flags & 0x3fffffffu) * 8);
        }
        data = 0;
        capacity = 0x80000000u;
    }
};
struct SomeClass
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
    Buffer buffer;
    void Destroy();
};
// Resets the vtable, frees unk10 through the allocator if set, clears buffer, then sets the vtable to DAT_0102e388.
// @fnv 0x00e06650
void SomeClass::Destroy()
{
    void* p = unk10;
    vtable = &DAT_010ea5b4;
    if (p)
    {
        FUN_00c856c0(hkMemoryRouter::getInstance().m_heap, p);
    }
    buffer.clear(hkMemoryRouter::getInstance().heap());
    vtable = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct E06490Allocator;

struct E06490MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E06490Allocator* m_pStreamAllocator;

    E06490Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" E06490MemoryRouter& __cdecl E06490GetMemoryRouter();
char* __cdecl AllocateWithHeader(E06490Allocator* alloc, int numBytes);
void __cdecl FUN_00c856c0(E06490Allocator* alloc, void* p);

struct E06490Stack
{
    int unk00;
    int unk04;
    int m_pRayCursor;
    int unk0C;
    char* m_buffer;

    void GrowBuffer();
};

// @fnv 0x00e06490
void E06490Stack::GrowBuffer()
{
    int newCapacity = m_pRayCursor * 2;
    char* newBuffer = AllocateWithHeader(&E06490GetMemoryRouter().heap(), newCapacity);
    ::FUN_00cb1280(newBuffer, 0xcd, m_pRayCursor);
    ::FUN_00cb1260(newBuffer + m_pRayCursor, m_buffer, m_pRayCursor);
    char* oldBuffer = m_buffer;
    m_pRayCursor *= 2;
    FUN_00c856c0(&E06490GetMemoryRouter().heap(), oldBuffer);
    m_buffer = newBuffer;
}

struct hkMemoryAllocatorE06;

struct hkThreadMemoryE06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE06* m_pkHeap;
};

extern "C" hkThreadMemoryE06& __cdecl hkThreadMemoryInstanceE06() throw();
void* __cdecl hkAllocateE06(hkMemoryAllocatorE06* pkHeap, int iNumBytes) throw();

template <class T> class hkArrayE06
{
  public:
    hkArrayE06() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkReferencedObjectE06
{
  public:
    hkReferencedObjectE06() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE06();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00e065f0 : public hkReferencedObjectE06
{
  public:
    FUN_00e065f0(int iSize);
    virtual ~FUN_00e065f0();

    int m_uiLogicalSize;
    int m_iUsed;
    void* m_pData;
    hkArrayE06<int> m_kArray;
};

// @fnv 0x00e065f0
FUN_00e065f0::FUN_00e065f0(int iSize)
{
    hkMemoryAllocatorE06* pkHeap = hkThreadMemoryInstanceE06().m_pkHeap;
    m_pData = hkAllocateE06(pkHeap, iSize);
    m_uiLogicalSize = iSize;
    m_iUsed = 0;
}

// @fnv 0x00e06480
extern "C" void __cdecl FUN_00e06480()
{}

#include <xmmintrin.h>


struct S_00e064f0_Arr
{
    char* m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_00e064f0_Arr() throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
    void reserveExactly(int n)
    {
        hkMemoryRouter& r = hkMemoryRouter::getInstance();
        if ((int)(m_cap & 0x3fffffff) < n)
            ::FUN_00c908c0((::SpawnedObject *)(r.m_heap), (::SpawnedArray *)(void *)(this), n, 1);
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& a, int n)
    {
        int c = m_cap & 0x3fffffff;
        if (c < n)
        {
            int dbl = c * 2;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&a), (::SpawnedArray *)(void *)(this), (n < dbl) ? dbl : n, 1);
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(hkMemoryRouter::getInstance().heap(), n);
        m_iElementCount = n;
    }
};

struct S_00e064f0_Ref
{
    virtual void vfn00();
    short m_usAllocationSize;
    short m_ref;
    static void* operator new(size_t n)
    {
        S_00e064f0_Ref* p = static_cast<S_00e064f0_Ref*>(hkMemoryRouter::getInstance().heap().blockAlloc(n));
        p->m_usAllocationSize = (short)n;
        return p;
    }
    static void operator delete(void*)
    {}
    S_00e064f0_Ref() throw()
    {
        m_ref = 1;
    }
};

struct S_00e064f0_Obj : S_00e064f0_Ref
{
    int unk08, unk0C;
    __m128 m10;
    S_00e064f0_Arr m_aiIndexedValues;
    char m2c;
    S_00e064f0_Obj() throw()
    {
        m10 = _mm_setzero_ps();
        m2c = 2;
    }
    virtual void vfn00();
};

struct FUN_00e064f0_class
{
    int unk00, unk04, unk08, unk0C;
    char* unk10;
    S_00e064f0_Obj* FUN_00e064f0();
};

// Allocates an S_00e064f0_Obj, copies the unk0C code bytes at the end of the unk10 buffer (unk10 + unk08 - unk0C) into its array, frees unk10, clears unk10 and unk0C, and sets unk08 to the old count.
// @fnv 0x00e064f0
S_00e064f0_Obj* FUN_00e064f0_class::FUN_00e064f0()
{
    int n = unk0C;
    S_00e064f0_Obj* pNewObj = new S_00e064f0_Obj;
    pNewObj->m_aiIndexedValues.reserveExactly(n);
    pNewObj->m_aiIndexedValues.SetSizeAndGrow(n);
    ::FUN_00cb1260(pNewObj->m_aiIndexedValues.m_data, unk10 + (unk08 - unk0C), n);
    void* pOldBuffer = unk10;
    FUN_00c856c0(hkMemoryRouter::getInstance().m_heap, pOldBuffer);
    unk10 = 0;
    unk0C = 0;
    unk08 = n;
    return pNewObj;
}

namespace fnv_00e066c0 {
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* FUN_00e066c0(unsigned int flags);
};
// Calls FUN_00e06650, then if the low bit of flags is set, frees this block of size bytes from the thread heap, and returns this.
// @fnv 0x00e066c0
CpuObject* CpuObject::FUN_00e066c0(unsigned int flags)
{
    reinterpret_cast<::SomeClass *>(this)->Destroy();
    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00e066c0
