
// src/havok/common/scenedata/attributes/hkxattributeholder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxattributeholder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <new>
#include "fnv/decl/FUN_00dfb720.h"
#include "fnv/decl/FUN_00dfd840.h"
#include "fnv/decl/S00e5cce0_Class.h"
#include "fnv/symbols_00c90000.h"
struct S_00e3eaa0_Allocator
{
    virtual ~S_00e3eaa0_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00e3eaa0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00e3eaa0_Allocator* m_pStreamAllocator;
    S_00e3eaa0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
template <class T> __forceinline void destruct(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        reinterpret_cast<::FUN_00dfd840 *>(&(t[i]))->FUN_00dfd840::~FUN_00dfd840();
}
template <class T> struct S_00e3eaa0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void _clearAndDeallocate(S_00e3eaa0_Allocator& alloc)
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~S_00e3eaa0_Array() throw()
    {
        _clearAndDeallocate(static_cast<S_00e3eaa0_Router*>(::FUN_00c85750())->heap());
    }
};
struct S_00e3eaa0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~S_00e3eaa0_Elem() throw();
};
struct S_00e3eaa0_Base
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00e3eaa0_Base() throw()
    {}
};
struct FUN_00e3eaa0 : S_00e3eaa0_Base
{
    S_00e3eaa0_Array<S_00e3eaa0_Elem> m_ppData;
    virtual ~FUN_00e3eaa0() throw();
};
// Destructor for the container; the array member is destroyed automatically after this body runs.
// @fnv 0x00e3eaa0
FUN_00e3eaa0::~FUN_00e3eaa0() throw()
{}


struct S_00e3e950_Heap;
struct S_00e3e950_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00e3e950_Heap* m_pStreamAllocator;
    S_00e3e950_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
}

struct S_00e3e950_Str
{
    int m_ptr;
    S_00e3e950_Str();
};

struct S_00e3e950_Arr8
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct S_00e3e950_Elem
{
    S_00e3e950_Str m_name;
    S_00e3e950_Arr8 m_aiIndexedValues;

    S_00e3e950_Elem(const S_00e3e950_Elem& o)
    {
        m_aiIndexedValues.m_data = 0;
        m_aiIndexedValues.m_iElementCount = 0;
        m_aiIndexedValues.m_iCapacityState = 0x80000000;
        reinterpret_cast<::S00e5cce0_Class *>((void *)&(const ::S_00e3e950_Elem &)(*this))->FUN_00e5cce0((const ::S00e5cce0_Class &)(o));
    }
    ~S_00e3e950_Elem();
    S_00e3e950_Elem& operator=(const S_00e3e950_Elem& o);
};

struct S_00e3e950_ArrayUtil
{
    template <typename T> static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; i++)
        {
            reinterpret_cast<::FUN_00dfd840 *>(&(t[i]))->FUN_00dfd840::~FUN_00dfd840();
        }
    }
    template <typename T> static __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            reinterpret_cast<::S00e5cce0_Class *>((void *)&(const ::S_00e3e950_Elem &)(dst[i]))->FUN_00e5cce0((const ::S00e5cce0_Class &)(src[i]));
        }
    }
    template <typename T> static __forceinline void construct(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            new (dst + i) T(src[i]);
        }
    }
};

template <typename T> struct S_00e3e950_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00e3e950_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(S_00e3e950_Heap& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }

    __forceinline void _copyFromArray(S_00e3e950_Heap& alloc, const S_00e3e950_Array<T>& a)
    {
        int oldSize = m_iElementCount;
        int newSize = a.m_iElementCount;
        int copiedSize = newSize > oldSize ? oldSize : newSize;

        GrowArrayCapacity(alloc, newSize);

        S_00e3e950_ArrayUtil::destruct(m_data + newSize, oldSize - newSize);
        S_00e3e950_ArrayUtil::copy(m_data, a.m_data, copiedSize);
        S_00e3e950_ArrayUtil::construct(m_data + copiedSize, a.m_data + copiedSize, newSize - copiedSize);

        m_iElementCount = newSize;
    }

    __forceinline S_00e3e950_Array& operator=(const S_00e3e950_Array& a)
    {
        _copyFromArray((*static_cast<S_00e3e950_Router*>(::FUN_00c85750())).heap(), a);
        return *this;
    }
};

struct S_00e3e950_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    S_00e3e950_RefObj() : m_sReferenceCount(1)
    {}
    virtual void vfn0();
};

struct FUN_00e3e950 : S_00e3e950_RefObj
{
    S_00e3e950_Array<S_00e3e950_Elem> m_aiIndexedValues;

    FUN_00e3e950(const FUN_00e3e950& o);
    virtual void vfn0();
};

// Copy constructor: copies the element array from o into this object's array.
// @fnv 0x00e3e950
FUN_00e3e950::FUN_00e3e950(const FUN_00e3e950& o)
{
    m_aiIndexedValues = o.m_aiIndexedValues;
}

namespace fnv_00dfe360 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00dfe360_cls
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
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void FUN_00dfe360();
};

// @fnv 0x00dfe360
void FUN_00dfe360_cls::FUN_00dfe360()
{
    AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapBits1 = m_uCapBits1;
    m_iCount1 = 0;
    if ((uCapBits1 & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData1, (uCapBits1 & 0x3fffffffu) * 4);
    }
    m_pData1 = 0;
    m_uCapBits1 = 0x80000000u;

    AudioHolder* pHolder2 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((uCapBits2 & 0x80000000u) == 0)
    {
        pAllocator2->FreeArray(m_pData2, (uCapBits2 & 0x3fffffffu) * 48);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
    reinterpret_cast<::FUN_00dfb720 *>(this)->FUN_00dfb720::~FUN_00dfb720();
}
}  // namespace fnv_00dfe360
