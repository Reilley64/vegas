
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/WorldData.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010d7000.h"
struct FUN_00d87430_class
{
    int* m_p;
    int m_kPointB;
    int m_iThirdValue;
    intptr_t GetEntry(intptr_t idx);
};

// @fnv 0x00d87430
intptr_t FUN_00d87430_class::GetEntry(intptr_t idx)
{
    return m_p[m_iThirdValue + idx + 1];
}

struct FUN_00d87440_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    intptr_t FUN_00d87440(intptr_t a);
};
// @fnv 0x00d87440
intptr_t FUN_00d87440_Class::FUN_00d87440(intptr_t aiIndex)
{
    return *(int*)((char*)m_iWordAt00 + aiIndex * 4 + m_8 * 8 + 8);
}

struct SlotBitmap
{
    uintptr_t* m_kPrimitiveElement;
    int m_auiShapeKeys;
    int m_iPairCount;
    int FindNextUsedSlot(int i);
};

// @fnv 0x00d87480
int SlotBitmap::FindNextUsedSlot(int aiStartIndex)
{
    ++aiStartIndex;
    if (aiStartIndex <= m_iPairCount)
    {
        uintptr_t* p = m_kPrimitiveElement + aiStartIndex;
        do
        {
            if (*p != ~uintptr_t(0))
                break;
            ++aiStartIndex;
            p += 1;
        } while (aiStartIndex <= m_iPairCount);
    }
    return aiStartIndex;
}

struct FUN_00d874b0_class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;
    char* SetBoolFromThreshold(char* p, intptr_t value);
};

// @fnv 0x00d874b0
char* FUN_00d874b0_class::SetBoolFromThreshold(char* pbOut, intptr_t value)
{
    *pbOut = value <= m_cByteAtOffset2;
    return pbOut;
}

struct FUN_00d87460_class
{
    intptr_t m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void SetElement(intptr_t idx, int val);
};

// @fnv 0x00d87460
void FUN_00d87460_class::SetElement(intptr_t aiIndex, int aiValue)
{
    *(int*)((int*)m_iWordAt00 + m_8 * 2 + 2 + aiIndex) = aiValue;
}

struct FUN_00d87760_class
{
    uintptr_t* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    void ClearEntries();
};

// @fnv 0x00d87760
void FUN_00d87760_class::ClearEntries()
{
    int i;
    for (i = 0; i < m_iPairCount + 1; i++)
        m_kPrimitiveElement[i] = ~uintptr_t(0);
    m_iCapacityFlags = 0;
}

struct FUN_00d877d0_allocator
{
    virtual void FUN_00d877d0_virtual0() = 0;
    virtual void FUN_00d877d0_virtual1() = 0;
    virtual void FUN_00d877d0_free(void* p, unsigned int size) = 0;
};

struct FUN_00d877d0_router
{
    unsigned char m_auiShapeKeys[0x10];
    FUN_00d877d0_allocator* m_pThreadAllocator;
};

FUN_00d877d0_router* _D1A0E0GetMemoryRouter();

struct FUN_00d877d0_class
{
    uintptr_t* m_kPrimitiveElement;
    int m_auiShapeKeys;
    int m_iPairCount;
    void FreeBuffer();
};

// @fnv 0x00d877d0
void FUN_00d877d0_class::FreeBuffer()
{
    FUN_00d877d0_router* router = _D1A0E0GetMemoryRouter();
    router->m_pThreadAllocator->FUN_00d877d0_free(m_kPrimitiveElement, 3 * sizeof(uintptr_t) * (m_iPairCount + 1));
}

struct FUN_00d87820_Class
{
    intptr_t FindStringKey(intptr_t);
    int FUN_00d87820(intptr_t a);
};

namespace fnv_00dc8080 {
struct FUN_00dc7750_class
{
};

struct FUN_allocator_class
{
// @fnv 0x00dc8080
    virtual void FUN_00dc8080_0()
    {}
    virtual void FUN_00dc8080_1()
    {}
    virtual void FUN_00dc8080_2(void* p, unsigned int size)
    {}
};

struct FUN_router_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
};


FUN_router_class* _D1A0E0GetMemoryRouter();

struct FUN_00dc8080_class
{
    void* m_vptr;
    int m_iWordAt04;
    FUN_00dc7750_class* m_8;

    void FUN_00dc8080();
};

void FUN_00dc8080_class::FUN_00dc8080()
{
    FUN_00dc7750_class* object = m_8;
    m_vptr = &(*reinterpret_cast<int *>(&::fnv_00dc8030::DAT_010d7510));

    if (object)
    {
        reinterpret_cast<::WorldData *>((object))->FUN_00dc7750();

        FUN_router_class* router = _D1A0E0GetMemoryRouter();
        FUN_allocator_class* allocator =
            *reinterpret_cast<FUN_allocator_class**>(reinterpret_cast<unsigned char*>(router) + 0x10);
        allocator->FUN_00dc8080_2(object, 0x88);
    }

    m_vptr = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}
}  // namespace fnv_00dc8080


static __forceinline int stringHash(const char* str)
{
    int hash = 0;
    if (*str)
    {
        const char* p = str;
        do
        {
            hash = 31 * hash + *p;
            ++p;
        } while (*p);
    }
    return hash & 0x7fffffff;
}

// @fnv 0x00d87580
intptr_t FUN_00d87820_Class::FindStringKey(intptr_t key)
{
    const char* str = (const char*)key;
    SlotBitmap* table = (SlotBitmap*)this;
    int hash = stringHash(str);
    unsigned int slot = hash & table->m_iPairCount;
    while (table->m_kPrimitiveElement[slot] != ~uintptr_t(0))
    {
        if (table->m_kPrimitiveElement[slot] == (unsigned int)hash &&
            ::fnv_00cb0fa0::FUN_00cb0fa0(str, (const char*)table->m_kPrimitiveElement[table->m_iPairCount + slot + 1]) == 0)
            return slot;
        slot = (slot + 1) & table->m_iPairCount;
    }
    return table->m_iPairCount + 1;
}

struct Allocator
{
    virtual void v0() = 0;
    virtual void* alloc(int size) = 0;
    virtual void free(void* p, unsigned int size) = 0;
};

struct MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pThreadAllocator;
};


struct FUN_00d87790
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    FUN_00d87790(int a);
};

// @fnv 0x00d87790
FUN_00d87790::FUN_00d87790(int a)
{
    MemoryRouter* router = static_cast<MemoryRouter*>(::FUN_00c85750());
    void* p = router->m_pThreadAllocator->alloc(0xc0);
    m_kPrimitiveElement = p;
    ::FUN_00cb1280(p, 0xff, 0x40);
    m_iCapacityFlags = 0;
    m_iPairCount = 0xf;
}

class hkObjectD878
{
  public:
    intptr_t GetValue(intptr_t a, int b);
};

struct hkBoolD876
{
    char m_cBooleanValue;
    hkBoolD876(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkStringMapD876
{
  public:
    int unk00;
    int unk04;
    int unk08;

    intptr_t GetOrSetInt(const char* key, int def);
};

struct hkBoolD8765
{
    char m_cBooleanValue;
    hkBoolD8765(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkStringMapD8765
{
  public:
    int unk00;
    int unk04;
    int unk08;

    int FUN_00d87650(const char* key, int* out);
};
// @fnv 0x00d87800
intptr_t hkObjectD878::GetValue(intptr_t a, int aiDefault)
{
    int iValue = aiDefault;
    reinterpret_cast<::hkStringMapD8765 *>(this)->FUN_00d87650((const char *)(a), &iValue);
    return iValue;
}

// Looks up key; if found writes its value to out and returns 0, otherwise returns 1.
// @fnv 0x00d87650
int hkStringMapD8765::FUN_00d87650(const char* key, int* piOut)
{
    intptr_t it = reinterpret_cast<::FUN_00d87820_Class *>(this)->FindStringKey((intptr_t)(key));
    if ((*(::hkBoolD8765 *)(reinterpret_cast<::FUN_00d874b0_class *>(this)->SetBoolFromThreshold((char *)(it), {}))))
    {
        *piOut = reinterpret_cast<::FUN_00d87440_Class *>(this)->FUN_00d87440(it);
        return 0;
    }
    return 1;
}

class hkMemoryAllocatorD878
{
  public:
    virtual ~hkMemoryAllocatorD878() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD878
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD878* m_pStreamAllocator;
    hkMemoryAllocatorD878& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
}

class FUN_00d874d0_s
{
  public:
    uintptr_t* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00d87860(int iNewCap);
};

struct S00d876a0_Map
{
    uintptr_t* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00d876a0(intptr_t it);
};
// @fnv 0x00d87820
int FUN_00d87820_Class::FUN_00d87820(intptr_t a)
{
    intptr_t v = FindStringKey(a);
    char r;
    if (*reinterpret_cast<::FUN_00d874b0_class *>(this)->SetBoolFromThreshold(&r, v))
    {
        reinterpret_cast<::S00d876a0_Map *>(this)->FUN_00d876a0(v);
        return 0;
    }
    return 1;
}

// Removes the element at index it from the open-addressing hash table, compacting remaining entries to fill the gap.
// @fnv 0x00d876a0
void S00d876a0_Map::FUN_00d876a0(intptr_t aiIndex)
{
    uintptr_t i = aiIndex;

    // remove it
    --m_iCapacityFlags;
    m_kPrimitiveElement[i] = ~uintptr_t(0);

    // find lowest element of this unbroken run
    uintptr_t lo = (i + m_iPairCount) & m_iPairCount;
    while (m_kPrimitiveElement[lo] != ~uintptr_t(0))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    // the slot which has become empty
    uintptr_t empty = i;

    // shift up, closing any gaps we find
    for (i = (i + 1) & m_iPairCount; m_kPrimitiveElement[i] != ~uintptr_t(0); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = m_kPrimitiveElement[i] & m_iPairCount;

        if ((i >= lo) && (hash > empty))
        {
            continue;
        }
        else if ((i < empty) && (hash > empty || hash <= i))
        {
            continue;
        }
        else if (hash > empty && hash < lo)
        {
            continue;
        }
        m_kPrimitiveElement[empty] = m_kPrimitiveElement[i];
        m_kPrimitiveElement[m_iPairCount + 1 + empty] = m_kPrimitiveElement[m_iPairCount + 1 + i];
        m_kPrimitiveElement[2 * (m_iPairCount + 1) + empty] = m_kPrimitiveElement[2 * (m_iPairCount + 1) + i];
        m_kPrimitiveElement[i] = ~uintptr_t(0);
        empty = i;
    }
}


class hkStringMapD874
{
  public:
    uintptr_t* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    static __forceinline int hash(const char* pcKey)
    {
        int h = 0;
        for (int i = 0; pcKey[i]; i++)
            h = 31 * h + pcKey[i];
        return h & 0x7fffffff;
    }

    void FUN_00d874d0(const char* pcKey, intptr_t iValue);
};
// Looks up key; if found returns its value, otherwise stores def under key and returns def.
// @fnv 0x00d87600
intptr_t hkStringMapD876::GetOrSetInt(const char* key, int iDefault)
{
    intptr_t it = reinterpret_cast<::FUN_00d87820_Class *>(this)->FindStringKey((intptr_t)(key));
    if ((*(::hkBoolD876 *)(reinterpret_cast<::FUN_00d874b0_class *>(this)->SetBoolFromThreshold((char *)(it), {}))))
        return reinterpret_cast<::FUN_00d87440_Class *>(this)->FUN_00d87440(it);
    reinterpret_cast<::hkStringMapD874 *>(this)->FUN_00d874d0(key, iDefault);
    return iDefault;
}
// Grows the primitive element array to iNewCap, re-inserts existing pairs via FUN_00d874d0, and releases the old block.
// @fnv 0x00d87860
void FUN_00d874d0_s::FUN_00d87860(int iNewCap)
{
    int iOldCap = m_iPairCount + 1;
    uintptr_t* puiOldElements = m_kPrimitiveElement;
    hkMemoryAllocatorD878& kAlloc = (*static_cast<hkMemoryRouterD878*>(::FUN_00c85750())).heap();
    m_kPrimitiveElement = (uintptr_t*)kAlloc.AllocateMemoryBlock(iNewCap * 3 * sizeof(uintptr_t));
    ::FUN_00cb1280(m_kPrimitiveElement, 0xff, iNewCap * sizeof(uintptr_t));
    m_iCapacityFlags = 0;
    m_iPairCount = iNewCap - 1;

    for (int i = 0; i < iOldCap; i++)
    {
        if (puiOldElements[i] != ~uintptr_t(0))
            reinterpret_cast<::hkStringMapD874 *>(this)->FUN_00d874d0((const char*)puiOldElements[iOldCap + i], puiOldElements[i + 2 * iOldCap]);
    }

    kAlloc.ReleaseBlock(puiOldElements, iOldCap * 3 * sizeof(uintptr_t));
}

// Inserts a key-value pair into the hash map, growing the table if the load factor exceeds half capacity.
// @fnv 0x00d874d0
void hkStringMapD874::FUN_00d874d0(const char* pcKey, intptr_t iValue)
{
    int uiHash = hash(pcKey);
    if (m_iCapacityFlags * 2 > m_iPairCount)
        reinterpret_cast<::FUN_00d874d0_s *>(this)->FUN_00d87860(m_iPairCount + m_iPairCount + 2);

    int i = uiHash & m_iPairCount;
    while (m_kPrimitiveElement[i] != ~uintptr_t(0))
    {
        if (m_kPrimitiveElement[i] == uiHash)
        {
            const char* pcStored = (const char*)m_kPrimitiveElement[m_iPairCount + i + 1];
            if (::fnv_00cb0fa0::FUN_00cb0fa0(pcKey, pcStored) == 0)
                goto KEY_FOUND;
        }
        i = (i + 1) & m_iPairCount;
    }

    m_iCapacityFlags += 1;

KEY_FOUND:
    m_kPrimitiveElement[i] = uiHash;
    m_kPrimitiveElement[m_iPairCount + i + 1] = (uintptr_t)pcKey;
    m_kPrimitiveElement[2 * m_iPairCount + 2 + i] = iValue;
}

namespace fnv_00e02800 {
class AllocatorE028
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};

struct RouterE028
{
    int unk00, unk04, unk08, unk0C;
    AllocatorE028* m_pStreamAllocator;

    AllocatorE028& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE028 {
}

char* __cdecl FUN_00cb1160(const char* pcString, AllocatorE028& kAlloc);

struct hkBoolE028
{
    char m_cBooleanValue;
    hkBoolE028(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class FUN_00d87790
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int unk0C;

    FUN_00d87790(hkBoolE028 bOwnsKeys) throw();

    static void* operator new(std::size_t uiSize)
    {
        return (*static_cast<RouterE028*>(::FUN_00c85750())).heap().AllocateMemoryBlock(uiSize);
    }
    static void operator delete(void* p);


    bool isValid(intptr_t iIt)
    {
        char cValid;
        reinterpret_cast<::FUN_00d874b0_class *>(this)->SetBoolFromThreshold(&cValid, iIt);
        return cValid != 0;
    }
};

class StringMapE028 : public FUN_00d87790
{
  public:
    StringMapE028() throw() : FUN_00d87790(hkBoolE028(false))
    {}
};

struct EntryE028
{
    void* m_pPointer;
    const char* m_pcName;
};

template <class T> __forceinline void constructWithCopyE028(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayE028
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void _pushBack(RouterE028& kRouter, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(::fnv_00e02800::AllocatorE028 *)(&kRouter.heap()), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyE028(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(const T& t)
    {
        _pushBack((*static_cast<RouterE028*>(::FUN_00c85750())), t);
    }
};

class NamedObjectsE028
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    hkArrayE028<EntryE028> m_kEntries;
    StringMapE028* m_pkPool;

    void FUN_00e02800(void* pkObject, const char* pcName);
};

// Pools pcName via m_pkPool, stores a new EntryE028 with pkObject and the pooled name into m_kEntries.
// @fnv 0x00e02800
void NamedObjectsE028::FUN_00e02800(void* pkObject, const char* pcName)
{
    if (!m_pkPool)
        m_pkPool = new StringMapE028();
    StringMapE028* pkPool = m_pkPool;
    intptr_t iIt = reinterpret_cast<::FUN_00d87820_Class *>((pkPool))->FindStringKey((intptr_t)(pcName));
    const char* pcPooled;
    if (!pkPool->isValid(iIt))
    {
        pcPooled = FUN_00cb1160(pcName, (*static_cast<RouterE028*>(::FUN_00c85750())).heap());
        reinterpret_cast<::hkStringMapD874 *>((pkPool))->FUN_00d874d0(pcPooled, 0);
    }
    else
    {
        pcPooled = (const char*)reinterpret_cast<::FUN_00d87430_class *>((pkPool))->GetEntry(iIt);
        reinterpret_cast<::FUN_00d87460_class *>((pkPool))->SetElement(iIt, 0);
    }
    EntryE028 kEntry;
    kEntry.m_pPointer = pkObject;
    kEntry.m_pcName = pcPooled;
    m_kEntries.AddBack(kEntry);
}
}  // namespace fnv_00e02800
