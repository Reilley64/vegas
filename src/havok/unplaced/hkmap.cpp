
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include "fnv/decl/ProbeMap64.h"
#include "fnv/symbols_00a29000.h"

// hkMap<hkUlong, hkUlong>: open addressing over key/value pairs. An empty slot holds the key ~0.
struct hkMapUlongPair
{
    uintptr_t key;
    uintptr_t val;
};

const uintptr_t hkMapUlongEmpty = ~uintptr_t(0);

inline unsigned hkMapUlongHash(uintptr_t key, int mod)
{
    return unsigned((key >> 4) * 2654435761U) & unsigned(mod);
}

namespace fnv_00cb1870 {
class hkMemoryAllocatorCB18;

class hkMapBaseCB18
{
  public:
    hkMapUlongPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FUN_00cb1870(hkMemoryAllocatorCB18& alloc, uintptr_t key, uintptr_t val);
};
}  // namespace fnv_00cb1870

struct FUN_00cb18f0_t
{
    hkMapUlongPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    intptr_t FindSlot(intptr_t);
    int FUN_00cb1fb0(intptr_t key);
};

// @fnv 0x00cb1810
int __cdecl FUN_00cb1810(int key)
{
    int iDoubled = key * 2;
    int size = 8;
    if (iDoubled > 8)
    {
        while (size < iDoubled)
            size += size;
    }
    return size << 4;
}

struct FUN_00cb1930_t
{
    hkMapUlongPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    intptr_t LookupHashEntry(intptr_t key, intptr_t defaultValue);
};

// @fnv 0x00cb1930
intptr_t FUN_00cb1930_t::LookupHashEntry(intptr_t key, intptr_t defaultValue)
{
    if (m_iPairCount > 0)
    {
        unsigned uiIndex = hkMapUlongHash(key, m_iPairCount);
        uintptr_t uiCurrentKey = m_kPrimitiveElement[uiIndex].key;
        while (uiCurrentKey != hkMapUlongEmpty)
        {
            if (uiCurrentKey == uintptr_t(key))
                return m_kPrimitiveElement[uiIndex].val;
            uiIndex = (uiIndex + 1) & m_iPairCount;
            uiCurrentKey = m_kPrimitiveElement[uiIndex].key;
        }
    }
    return defaultValue;
}

// @fnv 0x00cb17f0
int FUN_00cb17f0(int value)
{
    int required = value * 2;
    int size = 8;

    if (size < required)
    {
        do
        {
            size *= 2;
        } while (size < required);
    }

    return size * int(sizeof(hkMapUlongPair));
}

struct DepthLimit
{
    hkMapUlongPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
// Hashes key, and if the hash is within the limit, writes the bucket's paired value to out and returns 0; otherwise returns 1.
// @fnv 0x00cb1980
int LookupBucketValue(DepthLimit* self, uintptr_t key, uintptr_t* puiOut)
{
    intptr_t iHash = reinterpret_cast<::FUN_00cb18f0_t *>((self))->FindSlot(key);
    if (iHash <= self->m_iPairCount)
    {
        *puiOut = self->m_kPrimitiveElement[iHash].val;
        return 0;
    }
    return 1;
}

struct FUN_00cb1a60_t
{
    hkMapUlongPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    void ResetEntries();
};

// @fnv 0x00cb1a60
void FUN_00cb1a60_t::ResetEntries()
{
    int i;
    int n = m_iPairCount + 1;
    for (i = 0; i < n; ++i)
        m_kPrimitiveElement[i].key = hkMapUlongEmpty;
    m_iCapacityFlags &= 0x80000000;
}

namespace fnv_00cb1ac0 {
struct Allocator
{
    virtual void Unused() = 0;
    virtual void* Allocate(int size);
    virtual void Free(void* data, int size);
};

struct DepthLimit
{
    hkMapUlongPair* m_data;
    int m_flags;
    int m_uiItemCount;

    void ResizeAndRehash(Allocator* allocator, int count);
};

// @fnv 0x00cb1ac0
void DepthLimit::ResizeAndRehash(Allocator* allocator, int count)
{
    int iNewCapacity = count;
    if (iNewCapacity <= 8)
        iNewCapacity = 8;

    unsigned int flags = m_flags & 0x80000000u;
    hkMapUlongPair* pOldEntries = m_data;
    int iOldCapacity = m_uiItemCount + 1;

    m_data = static_cast<hkMapUlongPair*>(allocator->Allocate(iNewCapacity * int(sizeof(hkMapUlongPair))));

    for (int i = 0; i < iNewCapacity; ++i)
        m_data[i].key = hkMapUlongEmpty;

    m_uiItemCount = iNewCapacity - 1;
    m_flags = 0;

    for (int i = 0; i < iOldCapacity; ++i)
    {
        if (pOldEntries[i].key != hkMapUlongEmpty)
            reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18*>(this)->FUN_00cb1870(
                *reinterpret_cast<::fnv_00cb1870::hkMemoryAllocatorCB18*>(allocator), pOldEntries[i].key,
                pOldEntries[i].val);
    }

    if (flags == 0)
        allocator->Free(pOldEntries, iOldCapacity * int(sizeof(hkMapUlongPair)));
}
}  // namespace fnv_00cb1ac0

struct FUN_00cb1e40_arg_t
{
    // Empty virtual function body that does nothing.
// @fnv 0x00cb1e40
    virtual void FUN_00cb1e40_dummy()
    {}

    virtual void FUN_00cb1e40_dummy2()
    {}

    virtual void FUN_00cb1e40_op(void* data, int size)
    {}
};

struct FUN_00cb1e40_t
{
    void* m_data;
    int m_flags;
    int m_uiItemCount;

    void FUN_00cb1e40(FUN_00cb1e40_arg_t* arg);
};

struct CB1BC0Allocator
{
};

struct CB1BC0Allocator;
struct CB1BC0Map
{
    void ResizeToFit(CB1BC0Allocator&, int);
public:
    int InsertKeyValue(::CB1BC0Allocator &, unsigned long long, unsigned long long);
};

struct HashEntryTable
{
};
// @fnv 0x00dc8e30
uintptr_t LookupWithDefault(HashEntryTable* self, uintptr_t key)
{
    return reinterpret_cast<::FUN_00cb1930_t *>((((HashEntryTable*)((char*)self + 0xc))))->LookupHashEntry(key, -1);
}

struct FUN_00cb17e0_cls
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_iPairCount;
    int FUN_00cb17e0();
};

// @fnv 0x00cb17e0
int FUN_00cb17e0_cls::FUN_00cb17e0()
{
    return (m_iPairCount + 1) * int(sizeof(hkMapUlongPair));
}

struct hkMapOperatorsCB19
{
    static unsigned hash(uintptr_t key, int mod)
    {
        return hkMapUlongHash(key, mod);
    }
    static void invalidate(uintptr_t& key)
    {
        key = hkMapUlongEmpty;
    }
    static bool isValid(uintptr_t key)
    {
        return key != hkMapUlongEmpty;
    }
};

class hkMapBaseCB19
{
  public:
    hkMapUlongPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void RemoveEntry(void* it) throw();
};
// @fnv 0x00cb1fb0
int FUN_00cb18f0_t::FUN_00cb1fb0(intptr_t key)
{
    intptr_t found = FindSlot(key);
    if (found <= m_iPairCount)
    {
        reinterpret_cast<::hkMapBaseCB19 *>(this)->RemoveEntry((void *)(found));
        return 0;
    }
    return 1;
}

// Removes the map entry at the given slot, invalidates its key, and shifts later entries back to fill the gap.
// @fnv 0x00cb19b0
void hkMapBaseCB19::RemoveEntry(void* it) throw()
{
    typedef hkMapOperatorsCB19 OPS;
    unsigned i = unsigned(uintptr_t(it));

    --m_iCapacityFlags;
    OPS::invalidate(m_kPrimitiveElement[i].key);

    unsigned lo = (i + m_iPairCount) & m_iPairCount;
    while (OPS::isValid(m_kPrimitiveElement[lo].key))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    unsigned empty = i;

    for (i = (i + 1) & m_iPairCount; OPS::isValid(m_kPrimitiveElement[i].key); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = OPS::hash(m_kPrimitiveElement[i].key, m_iPairCount);

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
        m_kPrimitiveElement[empty].key = m_kPrimitiveElement[i].key;
        m_kPrimitiveElement[empty].val = m_kPrimitiveElement[i].val;
        OPS::invalidate(m_kPrimitiveElement[i].key);
        empty = i;
    }
}

struct CB1A90Argument
{
    virtual void Dummy0();
    virtual void Dummy1();
    virtual void Process(void* data, int size);
};
struct CB1A90Owner
{
    void* data;
    int flags;
    int count;
    void ProcessArgument(CB1A90Argument* argument);
};
// Calls ResetEntries, then if the high flag bit is clear, passes data and (count + 1) << 3 to argument->Process.
// @fnv 0x00cb1a90
void CB1A90Owner::ProcessArgument(CB1A90Argument* argument)
{
    reinterpret_cast<::FUN_00cb1a60_t *>(this)->ResetEntries();
    if (!(flags & 0x80000000))
    {
        argument->Process(data, (count + 1) * int(sizeof(hkMapUlongPair)));
    }
}

struct hkMapPairCB1E
{
    __int64 m_key;
    int m_val;
    int m_val2;
};

class hkMapCB1E
{
  public:
    hkMapPairCB1E* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00cb1e00();
};
void FUN_00cb1e40_t::FUN_00cb1e40(FUN_00cb1e40_arg_t* arg)
{
    reinterpret_cast<::hkMapCB1E *>(this)->FUN_00cb1e00();

    if (!(m_flags & 0x80000000))
    {
        arg->FUN_00cb1e40_op(m_data, (m_uiItemCount + 1) << 4);
    }
}

// @fnv 0x00cb1e00
void hkMapCB1E::FUN_00cb1e00()
{
    int n = m_iPairCount + 1;
    for (int i = 0; i < n; i++)
    {
        m_kPrimitiveElement[i].m_key = -1;
    }
    m_iCapacityFlags &= 0x80000000;
}

struct FUN_00cb1ac0_Obj
{
};

struct FUN_00cb1fe0_t
{
    void EnsureCapacity(intptr_t a1, int n);
};

// @fnv 0x00cb1fe0
void FUN_00cb1fe0_t::EnsureCapacity(intptr_t a1, int n)
{
    int iWantedSize = n * 2;
    int size = 8;
    while (size < iWantedSize)
    {
        size += size;
    }
    reinterpret_cast<::fnv_00cb1ac0::DepthLimit *>((((FUN_00cb1ac0_Obj*)this)))->ResizeAndRehash((::fnv_00cb1ac0::Allocator *)(a1), size);
}

class FUN_00cb2000_cls
{
  public:
    int m_00;
    int m_04;
    int m_pFreeList;

    int FUN_00cb2000(int iArg0, int iArg1);
};

class FUN_00cb1830
{
  public:
    hkMapUlongPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    FUN_00cb1830(void* ptr, unsigned int sizeInBytes);
};

// @fnv 0x00cb1830
FUN_00cb1830::FUN_00cb1830(void* apElements, unsigned int sizeInBytes)
{
    int maxKeys = sizeInBytes / sizeof(hkMapUlongPair);
    m_kPrimitiveElement = static_cast<hkMapUlongPair*>(apElements);
    m_iCapacityFlags = 0x80000000;
    m_iPairCount = maxKeys - 1;
    for (int i = 0; i < maxKeys; i++)
    {
        m_kPrimitiveElement[i].key = hkMapUlongEmpty;
    }
}

namespace fnv_00cb1870 {
// Inserts or updates a key/val pair in the hash map, resizing if needed, and returns 1 if the key was new.
// @fnv 0x00cb1870
int hkMapBaseCB18::FUN_00cb1870(hkMemoryAllocatorCB18& alloc, uintptr_t key, uintptr_t val)
{
    if ((m_iCapacityFlags & 0x7fffffff) * 2 > m_iPairCount)
        reinterpret_cast<::fnv_00cb1ac0::DepthLimit *>(this)->ResizeAndRehash((::fnv_00cb1ac0::Allocator *)&(alloc), m_iPairCount + m_iPairCount + 2);
    uintptr_t i;
    int isNewKey = 1;
    for (i = hkMapUlongHash(key, m_iPairCount); m_kPrimitiveElement[i].key != hkMapUlongEmpty;
         i = (i + 1) & m_iPairCount)
    {
        if (m_kPrimitiveElement[i].key == key)
        {
            isNewKey = 0;
            break;
        }
    }
    m_iCapacityFlags += isNewKey;
    m_kPrimitiveElement[i].key = key;
    m_kPrimitiveElement[i].val = val;
    return isNewKey;
}
}  // namespace fnv_00cb1870

struct Allocator;
struct EdgeMap
{
    hkMapUlongPair* unk00;
    int unk04;
    int unk08;
    int first() const
    {
        int i;
        for (i = 0; i <= unk08; ++i)
        {
            if (unk00[i].key != hkMapUlongEmpty)
                break;
        }
        return i;
    }
    int next(int i) const
    {
        for (++i; i <= unk08; ++i)
        {
            if (unk00[i].key != hkMapUlongEmpty)
                break;
        }
        return i;
    }
};
struct Manager
{
    void* unk00; void* unk04; void* unk08; void* unk0c;
    Allocator* unk10;
    Allocator& heap()
    {
        return *unk10;
    }
};
struct Target
{
    int unk00, unk04;
    unsigned short* unk08;
    int unk0c, unk10;
    unsigned char* unk14;
    int unk18;
    bool* FUN_00e48e80(bool* out);
};
// Checks that every edge in the vertex list appears exactly twice with opposite orientation, returning true only when all edge keys have value 3.
// @fnv 0x00e48e80
bool* Target::FUN_00e48e80(bool* apResult)
{
    EdgeMap edgeMap = {0, 0, -1};
    Allocator& allocator = static_cast<Manager*>(::FUN_00c85750())->heap();
    reinterpret_cast<::FUN_00cb1fe0_t *>(&(edgeMap))->EnsureCapacity((intptr_t)&(allocator), 0);
    int count = unk18;
    int iVertexOffset = 0;
    for (int i = 0; i < count; ++i)
    {
        int n = unk14[i];
        unsigned short* vertices = &unk08[iVertexOffset];
        int iPrevVertex = vertices[n - 1];
        for (int j = 0; j < n; ++j)
        {
            int iCurrVertex = vertices[j];
            unsigned int key;
            if (iPrevVertex < iCurrVertex)
                key = (static_cast<unsigned int>(iPrevVertex) << 16) | iCurrVertex;
            else
                key = (static_cast<unsigned int>(iCurrVertex) << 16) | iPrevVertex;
            int iOrientation = 1 + (iPrevVertex < iCurrVertex);
            int keyPlus = key + 1;
            intptr_t index = reinterpret_cast<::FUN_00cb18f0_t *>(&(edgeMap))->FindSlot(keyPlus);
            if (index <= edgeMap.unk08)
            {
                int value = int(edgeMap.unk00[index].val);
                if (value & iOrientation)
                {
                    *apResult = false;
                    reinterpret_cast<::CB1A90Owner *>(&(edgeMap))->ProcessArgument((::CB1A90Argument *)&(static_cast<Manager*>(::FUN_00c85750())->heap()));
                    ::FUN_00a29680();
                    return apResult;
                }
                edgeMap.unk00[index].val = value | iOrientation;
            }
            else
            {
                Allocator& allocator = static_cast<Manager*>(::FUN_00c85750())->heap();
                reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(&(edgeMap))->FUN_00cb1870((::fnv_00cb1870::hkMemoryAllocatorCB18 &)(allocator), keyPlus, iOrientation);
            }
            iPrevVertex = iCurrVertex;
        }
        iVertexOffset += n;
    }
    for (int index = edgeMap.first(); index <= edgeMap.unk08; index = edgeMap.next(index))
    {
        if (edgeMap.unk00[index].val != 3)
        {
            *apResult = false;
            reinterpret_cast<::CB1A90Owner *>(&(edgeMap))->ProcessArgument((::CB1A90Argument *)&(static_cast<Manager*>(::FUN_00c85750())->heap()));
            ::FUN_00a29680();
            return apResult;
        }
    }
    *apResult = true;
    reinterpret_cast<::CB1A90Owner *>(&(edgeMap))->ProcessArgument((::CB1A90Argument *)&(static_cast<Manager*>(::FUN_00c85750())->heap()));
    ::FUN_00a29680();
    return apResult;
}

typedef unsigned __int64 hkUint64CB1C;

struct MapOpsCB1C
{
    static inline unsigned hash(hkUint64CB1C key, unsigned mod)
    {
        return (unsigned)(((unsigned)key >> 4) * 0x9e3779b1u) & mod;
    }
    static inline bool isValid(hkUint64CB1C key)
    {
        return key != hkUint64CB1C(-1);
    }
    static inline bool equal(hkUint64CB1C key0, hkUint64CB1C key1)
    {
        return key0 == key1;
    }
};

struct MapCB1C
{
    struct Pair
    {
        hkUint64CB1C key;
        hkUint64CB1C val;
    };
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    hkUint64CB1C FUN_00cb1cb0(hkUint64CB1C key, hkUint64CB1C def) const;
};

// Looks up a key in the primitive element array and returns its value, or def when the key is not present.
// @fnv 0x00cb1cb0
hkUint64CB1C MapCB1C::FUN_00cb1cb0(hkUint64CB1C key, hkUint64CB1C def) const
{
    typedef MapOpsCB1C OPS;
    if (m_iPairCount > 0)
    {
        for (unsigned i = OPS::hash(key, m_iPairCount); OPS::isValid(m_kPrimitiveElement[i].key);
             i = (i + 1) & m_iPairCount)
        {
            if (OPS::equal(m_kPrimitiveElement[i].key, key))
            {
                return m_kPrimitiveElement[i].val;
            }
        }
    }
    return def;
}

struct hkMapOperatorsU64
{
    static unsigned hash(unsigned __int64 key, unsigned mod)
    {
        return unsigned((unsigned(key) >> 4) * 2654435761U) & mod;
    }
    static void invalidate(unsigned __int64& key)
    {
        key = (unsigned __int64)(-1);
    }
    static bool isValid(unsigned __int64 key)
    {
        return key != (unsigned __int64)(-1);
    }
};

class hkMapBaseU64
{
  public:
    struct Pair
    {
        unsigned __int64 key;
        unsigned __int64 val;
    };

    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00cb1d20(unsigned it);
};
// @fnv 0x00cb2000
int FUN_00cb2000_cls::FUN_00cb2000(int iArg0, int iArg1)
{
    int iCount = reinterpret_cast<::ProbeMap64 *>(this)->FUN_00cb1c60(iArg0);
    if (iCount <= m_pFreeList)
    {
        reinterpret_cast<::hkMapBaseU64 *>(this)->FUN_00cb1d20(iCount);
        return 0;
    }
    return 1;
}

// Invalidates the entry at index it and rehashes subsequent entries to close the gap in the open-addressed map.
// @fnv 0x00cb1d20
void hkMapBaseU64::FUN_00cb1d20(unsigned aiIndex)
{
    unsigned i = aiIndex;
    --m_iCapacityFlags;
    hkMapOperatorsU64::invalidate(m_kPrimitiveElement[i].key);

    unsigned lo = (i + m_iPairCount) & m_iPairCount;
    while (hkMapOperatorsU64::isValid(m_kPrimitiveElement[lo].key))
    {
        lo = (lo + m_iPairCount) & m_iPairCount;
    }
    lo = (lo + 1) & m_iPairCount;

    unsigned empty = i;

    for (i = (i + 1) & m_iPairCount; hkMapOperatorsU64::isValid(m_kPrimitiveElement[i].key); i = (i + 1) & m_iPairCount)
    {
        unsigned hash = hkMapOperatorsU64::hash(m_kPrimitiveElement[i].key, m_iPairCount);

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

        m_kPrimitiveElement[empty].key = m_kPrimitiveElement[i].key;
        m_kPrimitiveElement[empty].val = m_kPrimitiveElement[i].val;
        hkMapOperatorsU64::invalidate(m_kPrimitiveElement[i].key);
        empty = i;
    }
}

struct Allocator_cb1e
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct MapPair_cb1e
{
    unsigned __int64 key;
    unsigned __int64 val;
};

class MapBase_cb1e
{
  public:
    MapPair_cb1e* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00cb1e70(Allocator_cb1e& alloc, int newcap);
};
// @fnv 0x00cb2030
void CB1BC0Map::ResizeToFit(CB1BC0Allocator& allocator, int size)
{
    int doubledSize = size + size;
    int newSize = 8;

    if (doubledSize > 8)
    {
        do
        {
            newSize += newSize;
        } while (newSize < doubledSize);
    }

    reinterpret_cast<::MapBase_cb1e *>(this)->FUN_00cb1e70((::Allocator_cb1e &)(allocator), newSize);
}

// Reallocates the pair array to newcap (min 8), reinserts old pairs, and frees the old block unless the high bit of m_iCapacityFlags was set.
// @fnv 0x00cb1e70
void MapBase_cb1e::FUN_00cb1e70(Allocator_cb1e& alloc, int aiNewCapacity)
{
    if (aiNewCapacity <= 8)
        aiNewCapacity = 8;
    int iOldCapacity = m_iPairCount + 1;
    int dontDeallocate = m_iCapacityFlags & 0x80000000;
    MapPair_cb1e* oldelem = m_kPrimitiveElement;
    m_kPrimitiveElement = (MapPair_cb1e*)alloc.AllocateMemoryBlock(sizeof(MapPair_cb1e) * aiNewCapacity);
    for (int i = 0; i < aiNewCapacity; ++i)
        m_kPrimitiveElement[i].key = (unsigned __int64)-1;
    m_iCapacityFlags = 0;
    m_iPairCount = aiNewCapacity - 1;
    for (int i = 0; i < iOldCapacity; ++i)
    {
        if (oldelem[i].key != (unsigned __int64)-1)
            reinterpret_cast<::CB1BC0Map *>(this)->InsertKeyValue((::CB1BC0Allocator &)(alloc), oldelem[i].key, oldelem[i].val);
    }
    if (dontDeallocate == 0)
        alloc.ReleaseBlock(oldelem, sizeof(MapPair_cb1e) * iOldCapacity);
}

struct hkMemoryAllocatorCB1F;

struct hkMapOperationsCB1F
{
    static unsigned hash(uintptr_t key, unsigned mod)
    {
        return hkMapUlongHash(key, mod);
    }
    static bool equal(uintptr_t keyCur, uintptr_t keyValue)
    {
        return keyCur == keyValue;
    }
    static bool isValid(uintptr_t key)
    {
        return key != hkMapUlongEmpty;
    }
};

struct hkMapPairCB1F
{
    uintptr_t key;
    uintptr_t val;
};

class hkMapBaseCB1F
{
  public:
    int FUN_00cb1f40(hkMemoryAllocatorCB1F& alloc, uintptr_t key, unsigned int val);

    hkMapPairCB1F* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

// Grows the table if over half full, adds key/val if key is absent, and returns the key's slot index.
// @fnv 0x00cb1f40
int hkMapBaseCB1F::FUN_00cb1f40(hkMemoryAllocatorCB1F& alloc, uintptr_t key, unsigned int uiValue)
{
    {
        int numElems = m_iCapacityFlags & static_cast<int>(0x7fffffff);
        if ((numElems + numElems) > m_iPairCount)
        {
            reinterpret_cast<::fnv_00cb1ac0::DepthLimit *>(this)->ResizeAndRehash((::fnv_00cb1ac0::Allocator *)&(alloc), m_iPairCount + m_iPairCount + 2);
        }
    }

    unsigned i;
    for (i = hkMapOperationsCB1F::hash(key, m_iPairCount); !hkMapOperationsCB1F::equal(m_kPrimitiveElement[i].key, key);
         i = (i + 1) & m_iPairCount)
    {
        if (!hkMapOperationsCB1F::isValid(m_kPrimitiveElement[i].key))
        {
            m_kPrimitiveElement[i].key = key;
            m_kPrimitiveElement[i].val = uiValue;
            m_iCapacityFlags++;
            return i;
        }
    }
    return i;
}

// Hashes key into the open-addressing table and linearly probes for a matching entry, returning its slot index or a not-found value.
// @fnv 0x00cb18f0
intptr_t FUN_00cb18f0_t::FindSlot(intptr_t key)
{
    int mod = m_iPairCount;
    if (mod > 0)
    {
        unsigned index = hkMapUlongHash(key, mod);
        uintptr_t value = m_kPrimitiveElement[index].key;
        while (value != hkMapUlongEmpty)
        {
            if (value == uintptr_t(key))
                return (int)index;
            index = (index + 1) & unsigned(mod);
            value = m_kPrimitiveElement[index].key;
        }
    }
    return mod + 1;
}
