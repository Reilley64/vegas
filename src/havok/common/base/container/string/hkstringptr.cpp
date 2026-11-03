
// src/havok/common/base/container/string/hkstringptr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstringptr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include "fnv/decl/SStringPtr.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_01268000.h"
char* __cdecl AllocateWithHeader(void* alloc, intptr_t size);

// @fnv 0x00cb1160
char* __cdecl FUN_00cb1160(const char* aString, void* apAllocator)
{
    char* p = AllocateWithHeader(apAllocator, ::fnv_00cb10d0::FUN_00cb10d0(aString) + 1);
    FUN_00cb1090(p, aString);
    return p;
}


struct FUN_00cb0a60
{
    void* unk00;
    FUN_00cb0a60();
};

// @fnv 0x00cb0a60
FUN_00cb0a60::FUN_00cb0a60()
{
    unk00 = (*reinterpret_cast<void * *>(&::DAT_01268358));
}

// @fnv 0x00cb1190
int __cdecl CallSwappedArgs(uintptr_t arg0, uintptr_t arg1)
{
    ::FUN_00c856c0((::FNV_Dispatch *)arg1, (char *)arg0);
    return 0;
}


struct WriterCC0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Write(const char* s, intptr_t len);
};

// Writes the string s to w, or the literal "(null)" when s is null.
// @fnv 0x00cc0080
static __declspec(noinline) void FUN_00cc0080(WriterCC0* apWriter, const char* apString)
{
    if (apString)
        apWriter->Write(apString, ::fnv_00cb10d0::FUN_00cb10d0(apString));
    else
        apWriter->Write("(null)", 6);
}

volatile intptr_t g_wcc0;
volatile intptr_t g_scc0;
void CallTarget_cc0080()
{
    WriterCC0* w = (WriterCC0*)g_wcc0;
    const char* s = (const char*)g_scc0;
    FUN_00cc0080(w, s);
    FUN_00cc0080(w, s);
}

struct SinkOwner
{
    virtual void v0();
    void* unk04;
    WriterCC0* writer;
    SinkOwner* FUN_00cc01c0(const char* text);
};

// @fnv 0x00cc01c0
SinkOwner* SinkOwner::FUN_00cc01c0(const char* text)
{
    FUN_00cc0080(writer, text);
    return this;
}

namespace fnv_00cb11b0 {
// unit_ff4bdaca3856.cpp

extern "C"
{
    void* __cdecl AllocateWithHeader(void* p, intptr_t n);
}

// Copies up to n2 characters from p1 into a new null-terminated buffer allocated from p3 and returns it.
// @fnv 0x00cb11b0
void* __cdecl FUN_00cb11b0(void* apSrc, int anMaxLen, void* p3)
{
    intptr_t len = (intptr_t)((void *)(::fnv_00cb10d0::FUN_00cb10d0((const char *)(apSrc))));
    if (len > anMaxLen)
        len = anMaxLen;

    void* buf = AllocateWithHeader(p3, len + 1);
    ::CopyIfNonEmpty((char *)(buf), (const char *)(apSrc), len);
    ((char*)buf)[len] = 0;
    return buf;
}
}


typedef char* hk_va_list;

struct hkMemoryAllocatorq
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterq
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    hkMemoryAllocatorq* m_pStreamAllocator;

    __forceinline hkMemoryAllocatorq& heap()
    {
        return *m_pStreamAllocator;
    }
};


static __forceinline hkMemoryRouterq& hkGetMemoryRouter()
{
    return *(hkMemoryRouterq*)FUN_00c85750();
}

int __cdecl FUN_00cb0f50(char* buf, int n, const char* fmt, hk_va_list args) throw();

template <class T, int N> struct hkInplaceArrayq
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    __forceinline hkInplaceArrayq() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {}
    __forceinline ~hkInplaceArrayq()
    {
        hkMemoryAllocatorq& alloc = hkGetMemoryRouter().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocatorq& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        GrowArrayCapacity(hkGetMemoryRouter().heap(), n);
    }
};

class hkStringPtr
{
  public:
    void operator=(const char* s) throw();
    void FUN_00cb0c70(const char* fmt, ...);

    const char* m_pcText;
};

// @fnv 0x00cb0c70
void hkStringPtr::FUN_00cb0c70(const char* fmt, ...)
{
    hkInplaceArrayq<char, 255> buf;
    hk_va_list args = (hk_va_list)&fmt + sizeof(fmt);
    while (1)
    {
        int size = buf.getCapacity();
        int nchars = FUN_00cb0f50(buf.begin(), size, fmt, args);
        if (nchars >= 0 && nchars < size)
        {
            break;
        }
        else if (nchars < 0)
        {
            buf.reserve(buf.getCapacity() * 2);
        }
        else
        {
            buf.reserve(nchars);
        }
    }
    reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(*this))->FUN_00cb0c10(buf.begin());
    reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(*this))->FUN_00cb0c10(buf.begin());
}

#include "generated/data/havok/common/base/container/string/hkstringptr.inc"
