// src/havok/common/visualize/shape/hkdisplaysemicircle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysemicircle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <new>
#include "fnv/decl/FUN_00cb2e30_cls.h"
#include <xmmintrin.h>
#include "fnv/decl/ArcPointsPrivate__ArcSamples_de4af0.h"
#include "fnv/symbols_00c90000.h"
struct VectorArray
{
    __m128* data;
    int size;
    unsigned int capacityAndFlags;
};
struct Heap
{
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void deallocate(void*, unsigned int);
};
struct GlobalContext
{
    void* unk00; void* unk04; void* unk08; void* unk0c;
    Heap* heap;
    __forceinline Heap* getHeap()
    {
        return heap;
    }
};
struct Geometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    void FUN_00de4c40(VectorArray*, void*);
};
// Fills a temporary array via FUN_00de4af0, then writes consecutive pairs (i, i+1) from it into destination, 2*unk9c entries, growing destination as needed.
// @fnv 0x00de4c40
void Geometry::FUN_00de4c40(VectorArray* destination, void* allocator)
{
    VectorArray temporary = {0, 0, 0x80000000u};
    reinterpret_cast<::ArcPointsPrivate::ArcSamples_de4af0 *>(this)->FUN_00de4af0((::ArcPointsPrivate::VecArr_de4af0 *)(::VectorArray *)(&temporary));
    int required = unk9c * 2;
    int capacity = destination->capacityAndFlags & 0x3fffffff;
    if (capacity < required)
    {
        int newCapacity = capacity * 2;
        if (required >= newCapacity)
            newCapacity = required;
        ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(destination), newCapacity, 16);
    }
    destination->size = required;
    int outputIndex = 0;
    for (int i = 0; i < unk9c; ++i)
    {
        destination->data[outputIndex++] = temporary.data[i];
        destination->data[outputIndex++] = temporary.data[i + 1];
    }
    Heap* heap = static_cast<GlobalContext*>(::FUN_00c85750())->getHeap();
    temporary.size = 0;
    if ((temporary.capacityAndFlags & 0x80000000u) == 0)
    {
        heap->deallocate(temporary.data, (temporary.capacityAndFlags & 0x3fffffff) * 16);
    }
}

#include <xmmintrin.h>
namespace fnv_00de4d20 {
#include <xmmintrin.h>

struct S_de4d20_Heap
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
};

struct S_de4d20_Holder
{
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkc;
    S_de4d20_Heap* unk10;

    S_de4d20_Heap& heap()
    {
        return *unk10;
    }
};


struct __declspec(align(16)) S_de4d20_Vec
{
    float x;
    float y;
    float z;
    float w;
};

struct S_de4d20_Cell
{
    int a;
    int b;
    int c;
    int d;
};

struct S_de4d20_Grid
{
    S_de4d20_Vec* data;
    int size;
    unsigned int cap;
    S_de4d20_Cell* cells;
    int cellSize;
    unsigned int cellCap;

    static void* operator new(std::size_t n)
    {
        return static_cast<S_de4d20_Holder*>(::FUN_00c85750())->heap().AllocateMemoryBlock(n);
    }

    static void operator delete(void*)
    {}

    S_de4d20_Grid() throw()
    {
        data = 0;
        size = 0;
        cap = 0x80000000;
        cells = 0;
        cellSize = 0;
        cellCap = 0x80000000;
    }
};

struct S_de4d20_Context
{
    int unk0;
    int unk4;
    S_de4d20_Grid* m8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;

    __declspec(align(16)) S_de4d20_Vec m80;

    int unk90;
    int unk94;
    int unk98;
    int m9c;

    void FUN_00de4d20() throw();
};

// Allocates a grid, stores it in m8, calls FUN_00de4af0, appends m80 to the grid data, and fills m9c cells with index ranges.
// @fnv 0x00de4d20
void S_de4d20_Context::FUN_00de4d20() throw()
{
    S_de4d20_Grid* g = new S_de4d20_Grid;
    m8 = g;
    reinterpret_cast<::ArcPointsPrivate::ArcSamples_de4af0 *>(this)->FUN_00de4af0((::ArcPointsPrivate::VecArr_de4af0 *)(g));

    S_de4d20_Grid* arr = m8;
    S_de4d20_Holder* r = static_cast<S_de4d20_Holder*>(::FUN_00c85750());

    if (arr->size == (int)(arr->cap & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)&(r->heap()), (::AudioStream *)(arr), 0x10);

    int i = 0;
    int off = 0;

    *(__m128*)&arr->data[arr->size] = *(__m128*)&m80;
    arr->size++;

    volatile S_de4d20_Grid* current = m8;
    int last = current->size - 1;

    if (m9c > 0)
    {
        do
        {
            S_de4d20_Cell* c = (S_de4d20_Cell*)((char*)m8->cells + off);

            c->a = last;
            c->b = i + 1;
            c->c = i;
            c->d = -1;

            off += 16;
            i++;
        } while (i < m9c);
    }
}
}  // namespace fnv_00de4d20


namespace ArcPointsPrivate {
struct Holder_de4af0
{
    void* unk00; void* unk04; void* unk08; void* unk0C;
    void* m_pAllocator;  // +0x10
};
struct Frame_de4af0;
// 16 byte vector stored as four floats. Used as a `this` object and as
// the in-place input/output of the frame transform.
struct Vec_de4af0
{
    union
    {
        __m128 v;
        struct
        {
            float m_f00, m_f04, m_f08, m_f0C;
        };
    };
    void add(const Vec_de4af0& a, const Vec_de4af0& b)
    {
        v = _mm_add_ps(a.v, b.v);
    }
    void sub(const Vec_de4af0& a, const Vec_de4af0& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    Vec_de4af0& operator=(const Vec_de4af0& b)
    {
        v = b.v;
        return *this;
    }
    void FUN_00c7f700(Frame_de4af0* f, Vec_de4af0* v);
};
// Three-column rotation used by the transform helpers.
struct Frame_de4af0
{
    __m128 column0, column1, column2;
};
// Output array: data pointer, element count, capacity.
struct VecArr_de4af0
{
    Vec_de4af0* m_pData;  // +0x00
    int m_iArrayLength;         // +0x04
    unsigned int m_uCap;  // +0x08
};
struct ArcSamples_de4af0
{
    int unk00;         // +0x00
    int unk04;         // +0x04
    int unk08;         // +0x08
    int unk0C;         // +0x0c
    int unk10;         // +0x10
    int unk14;         // +0x14
    int unk18;         // +0x18
    int unk1C;         // +0x1c
    int unk20;         // +0x20
    int unk24;         // +0x24
    int unk28;         // +0x28
    int unk2C;         // +0x2c
    int unk30;         // +0x30
    int unk34;         // +0x34
    int unk38;         // +0x38
    int unk3C;         // +0x3c
    int unk40;         // +0x40
    int unk44;         // +0x44
    int unk48;         // +0x48
    int unk4C;         // +0x4c
    int unk50;         // +0x50
    int unk54;         // +0x54
    int unk58;         // +0x58
    int unk5C;         // +0x5c
    Vec_de4af0 m_v60;  // +0x60
    Vec_de4af0 m_v70;  // +0x70
    Vec_de4af0 m_v80;  // +0x80
    float m_f90;       // +0x90
    float m_f94;       // +0x94
    float m_f98;       // +0x98
    int m_i9c;         // +0x9c
    void FUN_00de4af0(VecArr_de4af0* arr);
};
// @fnv 0x00de4af0
void ArcSamples_de4af0::FUN_00de4af0(VecArr_de4af0* arr)
{
    const Vec_de4af0& origin = m_v80;
    __declspec(align(16)) float step = (m_f94 - m_f90) / (float)m_i9c;
    Frame_de4af0 local;
    reinterpret_cast<::FUN_00cb2e30_cls *>(&(local))->SpawnSnap((int)(&m_v60), m_f90);
    Vec_de4af0 x;
    _mm_store_ps(&x.m_f00,
                 _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&m_f98), _mm_load_ss(&m_f98), 0), _mm_load_ps(&m_v70.m_f00)));
    x.FUN_00c7f700(&local, &x);
    x.add(origin, x);
    reinterpret_cast<::FUN_00cb2e30_cls *>(&(local))->SpawnSnap((int)(&m_v60), step);
    int n = m_i9c + 2;
    Holder_de4af0* h = static_cast<Holder_de4af0*>(::FUN_00c85750());
    _ReadWriteBarrier();
    void* alloc = h->m_pAllocator;
    unsigned int cap = arr->m_uCap & 0x3fffffffu;
    if ((int)cap < n)
    {
        unsigned int newCap = cap * 2;
        if (n >= (int)newCap)
        {
            newCap = n;
        }
        ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(arr), newCap, 0x10);
    }
    __m128 initial = x.v;
    arr->m_iArrayLength = n;
    arr->m_pData[0].v = initial;
    int i = 0;
    if (m_i9c >= i)
    {
        unsigned int off = 0;
        do
        {
            Vec_de4af0 y;
            _mm_store_ps(&y.m_f00, _mm_sub_ps(_mm_load_ps(&x.m_f00), _mm_load_ps(&m_v80.m_f00)));
            y.FUN_00c7f700(&local, &y);
            y.add(origin, y);
            _mm_store_ps(&arr->m_pData[off + 1].m_f00, _mm_load_ps(&y.m_f00));
            x = y;
            off++;
            i++;
        } while (i <= m_i9c);
    }
}

}
