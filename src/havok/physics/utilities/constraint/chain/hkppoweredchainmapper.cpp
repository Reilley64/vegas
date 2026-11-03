
// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <new>
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cb18f0_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00e5a000.h"
#include "fnv/symbols_010e0000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkpPoweredChainMapper.h"

class hkMemoryAllocatorE3A5;


namespace hkRouterE3A5 {
}

struct hkBoolE3A5
{
    char m_cBooleanValue;
    hkBoolE3A5()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE3A5(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE3A5
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(router.m_heap), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyE3A5<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct hkRowE3A5
{
    int m_slots[20];
};

struct hkTableE3A5
{
    int unk00[16];
    hkRowE3A5 m_rows[1];
};

struct hkOwnerE3A5
{
    int unk00[6];
    hkTableE3A5* m_table;
};

struct hkRefE3A5
{
    hkOwnerE3A5* m_pOwnerObject;
    int m_row;
};

struct hkRangeE3A5
{
    int m_kRayStart;
    int m_uiItemCount;
    int unk08;
};

class hkSetE3A5
{
  public:
    int unk00;
    int unk04;
    hkRangeE3A5* m_ranges;
    int unk0C;
    int unk10;
    hkRefE3A5* m_refs;

    void CollectSlotValues(int range, int slot, hkArrayE3A5<int>& out);
};

// Iterates the refs of a range and appends the slot value from each owner's table row to out when non-zero.
// @fnv 0x00e3a520
void hkSetE3A5::CollectSlotValues(int range, int slot, hkArrayE3A5<int>& out)
{
    const hkRangeE3A5& r = m_ranges[range];
    for (int i = 0; i < r.m_uiItemCount; i++)
    {
        const hkRefE3A5& ref = m_refs[r.m_kRayStart + i];
        int v = ref.m_pOwnerObject->m_table->m_rows[ref.m_row].m_slots[slot];
        if (v)
            out.AddBack(v);
    }
}

struct FnPlacement
{
};

template <class T> struct FnArray
{
    T* data;
    int size;
    int capacity;
    FnArray() throw() : data(0), size(0), capacity(0x80000000)
    {}
    ~FnArray() throw()
    {
        clear();
    }
    void clear()
    {
        hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
        size = 0;
        if (!(capacity & 0x80000000))
            heap.bufFree(data, sizeof(T) * (capacity & 0x3fffffff));
        data = 0;
        capacity = 0x80000000;
    }
    void reserve(hkMemoryAllocator& heap, int n)
    {
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            cap *= 2;
            if (n >= cap)
                cap = n;
            ::FUN_00c908c0((::SpawnedObject *)(::hkMemoryAllocator *)(&heap), (::SpawnedArray *)(void *)(this), cap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(hkMemoryAllocator& allocator, int count)
    {
        reserve(allocator, count);
        int n = count - size;
        T* p = data + size;
        if (n > 0)
            do
            {
                new ((FnPlacement*)p) T;
                ++p;
            } while (--n);
        size = count;
    }
    void push(const T& value)
    {
        hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(::hkMemoryAllocator *)(&heap), (::AudioStream *)(void *)(this), sizeof(T));
        T* destination = data + size;
        const T* source = &value;
        for (int i = 0; i < 1; ++i)
            *destination++ = *source++;
        ++size;
    }
    T& expand()
    {
        hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(::hkMemoryAllocator *)(&heap), (::AudioStream *)(void *)(this), sizeof(T));
        return data[size++];
    }
};
struct FnMap
{
    struct Entry
    {
        int key;
        int value;
    };
    Entry* data;
    int size;
    int capacity;
    FnMap() throw() : data(0), size(0), capacity(-1)
    {
        hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
        reinterpret_cast<::FUN_00cb1fe0_t *>(this)->EnsureCapacity(reinterpret_cast<intptr_t>(&heap), 0);
    }
    ~FnMap() throw()
    {
        ProcessArgument(hkMemoryRouter::getInstance().m_heap);
        ::FUN_00a29680();
    }
    void ProcessArgument(hkMemoryAllocator*) throw();
};
struct FnNodePair
{
    int first;
    int second;
};
struct FnLink
{
    int offset;
    int count;
    int fallback;
    FnLink() : offset(-1), count(0), fallback(0)
    {}
};
struct FnTarget
{
    void* constraint;
    int target;
};
struct FnVisit
{
    void* constraint;
    int localIndex;
    int linkIndex;
};
struct FnConstraint
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void reserved0C();
    virtual void VirtualFunction10();
    virtual void reserved14();
    virtual void reserved18();
    virtual void reserved1C();
    virtual int getType() throw();
};
struct FnObject
{
    int reserved00;
    int reserved04;
    int reserved08;
    FnConstraint* constraint;
};
struct FnMapper
{
    void* vtable;
    unsigned short GetAllocationSize;
    unsigned short refs;
    FnArray<FnLink> links;
    FnArray<FnTarget> targets;
    FnArray<FnObject*> chains;
    static void* operator new(size_t size)
    {
        hkMemoryAllocator& allocator = hkMemoryRouter::getInstance().heap();
        FnMapper* p = (FnMapper*)allocator.blockAlloc(size);
        p->GetAllocationSize = (unsigned short)size;
        return p;
    }
    FnMapper() : vtable(&::DAT_010e0654), refs(1)
    {}
};
extern "C" int __cdecl FUN_00e5ba30(hkArray<int>*, int, int, FnArray<int>*, FnArray<int>*);
extern "C" FnObject* __cdecl FUN_00e5b510(FnArray<int>*, unsigned char);
struct FnDiagnostic
{
    int stream;
    int cursor;
    int capacity;
};
struct FnLogger
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void report(int, unsigned int, char*, const char*, int) throw();
};
inline void reportError(const char* message, unsigned int id, int line)
{
    unsigned int buffer[128];
    FnDiagnostic diagnostic;
    new ((void *)&(diagnostic)) ::FUN_00cb1600((char*)buffer, 512);
    reinterpret_cast<::SinkOwner *>(&(diagnostic))->FUN_00cc01c0(message);
    (*reinterpret_cast<::FnLogger * *>(&::DAT_01268360))->report(1, id, (char*)buffer, ".\\Constraint\\Chain\\hkpPoweredChainMapper.cpp", line);
    reinterpret_cast<struct ::FUN_00cc00e0 *>(&(diagnostic))->FUN_00cc00e0::~FUN_00cc00e0();
}
__forceinline int buildOffsets(FnMapper* mapper, FnArray<int>& linkCounts)
{
    int total = 0;
    for (int i = 0; i < mapper->links.size; ++i)
    {
        mapper->links.data[i].offset = total;
        total += linkCounts.data[i];
        mapper->links.data[i].count = 0;
    }
    return total;
}
struct FnFlags
{
    unsigned char copyFallbacks;
    unsigned char includeChains;
};
// Builds an FnMapper by resolving constraint chains for node pairs, populating link offsets, targets, and optionally collecting unlinked ids.
// @fnv 0x00e3a5b0
FnMapper* __cdecl BuildPoweredChainMapper(FnFlags flags, hkArray<int>* linkIds, hkArray<FnNodePair>* pairs,
                                          hkArray<int>* unlinked) throw()
{
    FnMapper* mapper = new FnMapper;

    FnArray<FnVisit> visits;
    FnArray<int> linkCounts;
    int count = linkIds->m_iElementCount;
    linkCounts.reserve(hkMemoryRouter::getInstance().heap(), count);
    linkCounts.size = count;
    ::FUN_00cb1280(linkCounts.data, 0, 4 * count);
    FnMap table;
    for (int k = 0; k < linkIds->m_iElementCount; ++k)
    {
        int key = linkIds->m_data[k];
        hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(&(table))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(&heap)), key, k);
    }
    count = linkIds->m_iElementCount;
    mapper->links.SetSizeAndGrow(hkMemoryRouter::getInstance().heap(), count);
    ::FUN_00cb1280(mapper->links.data, 0, 12 * mapper->links.size);
    for (int pairIndex = 0; pairIndex < pairs->m_iElementCount; ++pairIndex)
    {
        FnArray<int> scratch;
        FnArray<int> chainLinks;
        FnNodePair& pair = pairs->m_data[pairIndex];
        if (FUN_00e5ba30(linkIds, pair.first, pair.second, &scratch, &chainLinks) == 1)
        {
            reportError("Cannot find a chain of constraints linking one of the entity pairs.", 0xabbaaa88, 68);
            reinterpret_cast<::hkReferencedObjectC905 *>((((FnObject*)mapper)))->FUN_00c905b0();
            return 0;
        }
        FnObject* obj = FUN_00e5b510(&chainLinks, flags.includeChains);
        if (!obj)
        {
            reportError("Failed to build a chain.", 0xabbaddaa, 78);
            reinterpret_cast<::hkReferencedObjectC905 *>((((FnObject*)mapper)))->FUN_00c905b0();
            return 0;
        }
        mapper->chains.push(obj);
        for (int j = 0; j < chainLinks.size; ++j)
        {
            int entity = chainLinks.data[j];
            int index = reinterpret_cast<::FUN_00cb18f0_t *>(&(table))->FindSlot(entity);
            if (index > table.capacity)
            {
                reportError("Internal error.", 0xabba99dd, 93);
                reinterpret_cast<::hkReferencedObjectC905 *>((obj))->FUN_00c905b0();
                reinterpret_cast<::hkReferencedObjectC905 *>((((FnObject*)mapper)))->FUN_00c905b0();
                return 0;
            }
            int linkIndex = table.data[index].value;
            FnLink* link = &mapper->links.data[linkIndex];
            FnVisit& v = visits.expand();
            v.linkIndex = linkIndex;
            ++linkCounts.data[linkIndex];
            if (obj->constraint->getType() != 0x66)
            {
                reportError("Internal error; invalid chain type.", 0xabba9d6d, 108);
                reinterpret_cast<::hkReferencedObjectC905 *>((obj))->FUN_00c905b0();
                reinterpret_cast<::hkReferencedObjectC905 *>((((FnObject*)mapper)))->FUN_00c905b0();
                return 0;
            }
            v.constraint = obj->constraint;
            v.localIndex = j;
            if (flags.copyFallbacks && !link->fallback)
                link->fallback = ((int)(::CloneInstanceFromSource((::Instance *)(chainLinks.data[j]))));
        }
    }
    int total = buildOffsets(mapper, linkCounts);
    mapper->targets.SetSizeAndGrow(hkMemoryRouter::getInstance().heap(), total);
    for (int i = 0; i < visits.size; ++i)
    {
        FnVisit& visit = visits.data[i];
        FnLink& link = mapper->links.data[visit.linkIndex];
        FnTarget& target = mapper->targets.data[link.offset + link.count];
        target = *(FnTarget*)&visit;
        ++link.count;
    }
    if (unlinked)
    {
        for (int i = 0; i < mapper->links.size; ++i)
        {
            if (!mapper->links.data[i].count)
            {
                int& key = linkIds->m_data[i];
                ((FnArray<int>*)unlinked)->push(key);
            }
        }
    }
    return mapper;
}

#include <xmmintrin.h>
struct TargetRuntime
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_vVectorData;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

struct ChainInstance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    TargetRuntime* m_pRuntime;
};

struct hkpPoweredChainMapperTarget
{
    ChainInstance* m_pChainInstance;
    int m_targetIndex;
};

struct hkpPoweredChainMapperLinkInfo
{
    int m_iChainIndex;
    int m_iLinkIndex;
    int unk08;
};

struct SomeClass : public hkpPoweredChainMapper
{
    void SetLinkVector(int chainIndex, const __m128& vec);
};

// Writes vec into the runtime vector slot of every target belonging to the link at chainIndex.
// @fnv 0x00e3a4d0
void SomeClass::SetLinkVector(int chainIndex, const __m128& vec)
{
    hkpPoweredChainMapperLinkInfo& linkInfo = m_ppLinks.m_data[chainIndex];
    for (int i = 0; i < linkInfo.m_iLinkIndex; ++i)
    {
        hkpPoweredChainMapperTarget& target = m_kTargets.m_data[linkInfo.m_iChainIndex + i];
        target.m_pChainInstance->m_pRuntime[target.m_targetIndex].m_vVectorData = vec;
    }
}

class hkMemoryAllocatorE3A3
{
  public:
    virtual ~hkMemoryAllocatorE3A3() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE3A3
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE3A3* m_pStreamAllocator;
    hkMemoryAllocatorE3A3& heap()
    {
        return *m_pStreamAllocator;
    }
};

template <class T> __forceinline void destructE3A3(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE3A3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T& operator[](int i)
    {
        T* p0 = m_data;
        T* p1 = p0;
        T* p2 = p1;
        T* p3 = p2;
        T* p4 = p3;
        T* p5 = p4;
        T* p6 = p5;
        T* p7 = p6;
        T* p8 = p7;
        T* p9 = p8;
        T* p10 = p9;
        T* p11 = p10;
        T* p12 = p11;
        T* p13 = p12;
        T* p14 = p13;
        T* p15 = p14;
        T* p16 = p15;
        T* p17 = p16;
        T* p18 = p17;
        T* p19 = p18;
        return p19[i];
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayE3A3() throw()
    {
        ClearAndRelease(hkMemoryRouter::getInstance().heap());
    }
    __forceinline void clear()
    {
        destructE3A3(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocator& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkConstraintRefE3A3
{
  public:
};

struct hkpConstraintEntryE3A3
{
    hkConstraintRefE3A3* m_pHavokConstraint;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

class hkReferencedObjectE3A3
{
  public:
    virtual ~hkReferencedObjectE3A3() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

namespace FUN_00e3a3d0 {
class hkpConstraintChainMapperE3A3 : public hkReferencedObjectE3A3
{
  public:
    hkArrayE3A3<hkpConstraintEntryE3A3> m_entries;

    virtual ~hkpConstraintChainMapperE3A3() throw();
};

// Iterates over m_entries and calls removeReference on each m_pHavokConstraint.
// @fnv 0x00e3a3d0
hkpConstraintChainMapperE3A3::~hkpConstraintChainMapperE3A3() throw()
{
    const int iEntryIndex = m_entries.m_iElementCount;
    for (int i = 0; i < iEntryIndex; i++)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_entries[i].m_pHavokConstraint))->FUN_00c905b0();
}
}



namespace hkR3AD {
}

template <class T> class hkArrayE3AD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        T* p = m_data;
        return p[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }

    ~hkArrayE3AD() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkE3AD {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
}

namespace hkE3AD {
struct LinkInfoE3AD
{
    int unk00;
    int unk04;
    hkReferencedObject* m_pConstraintInstance;
};

struct TargetE3AD
{
    int unk00;
    int unk04;
};
}

namespace FUN_00e3ad80 {
class hkpPoweredChainMapper : public hkE3AD::hkReferencedObject
{
  public:
    virtual ~hkpPoweredChainMapper();

    hkArrayE3AD<hkE3AD::LinkInfoE3AD> m_ppLinks;
    hkArrayE3AD<hkE3AD::TargetE3AD> m_kTargets;
    hkArrayE3AD<hkE3AD::hkReferencedObject*> m_kChainInstances;
};

// @fnv 0x00e3ad80
hkpPoweredChainMapper::~hkpPoweredChainMapper()
{
    for (int i = 0; i < m_ppLinks.GetLogicalSize(); i++)
    {
        if (m_ppLinks[i].m_pConstraintInstance)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_ppLinks[i].m_pConstraintInstance))->FUN_00c905b0();
    }
    for (int i = 0; i < m_kChainInstances.m_iElementCount; i++)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_kChainInstances.m_data[i]))->FUN_00c905b0();
}
}

// Moved from hkppoweredchainmapper_decl_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00e3a440: the skeleton of src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp
// with declarations corrected to what the original code does (hkpPoweredChainMapper.h: hkpPoweredChainMapper += void FUN_00e3a440(int linkIndex, int motorIndex, class hkpConstraintMotor* motor);; hkReferencedObject.h: hkReferencedObject += void RetainReference() const; void removeReference() const;). Move the function to its real unit once
// that unit declares it this way.

// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00c90510_class.h"
#include "havok/hkpPoweredChainMapper_decl_hkppoweredchainmapper.h"

class hkpConstraintMotor : public hkReferencedObject
{
};
struct __declspec(align(16)) ChainConstraintInfo
{
    hkVector4 pivotInA;
    hkVector4 pivotInB;
    hkQuaternion rotationA;
    hkQuaternion rotationB;
    hkpConstraintMotor* motors[3];
    hkBool switchBodies;
};
class hkpPoweredChainData : public hkReferencedObject
{
  public:
    int unk08, unk0c, unk10, unk14;
    ChainConstraintInfo* infos;
};
// @fnv 0x00e3a440
void hkpPoweredChainMapper::FUN_00e3a440(int linkIndex, int motorIndex, hkpConstraintMotor* motor)
{
    hkpPoweredChainMapperLinkInfo* link = &m_ppLinks.m_data[linkIndex];
    for (int i = 0; i < link->targetCount; ++i)
    {
        hkpPoweredChainMapperTarget& target = m_kTargets.m_data[link->firstTarget + i];
        hkpPoweredChainData* data = target.chainData;
        hkpConstraintMotor* oldMotor = data->infos[target.infoIndex].motors[motorIndex];
        if (oldMotor)
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(oldMotor))->FUN_00c905b0();
        data->infos[target.infoIndex].motors[motorIndex] = motor;
        if (motor)
            reinterpret_cast<::FUN_00c90510_class *>((void *)(motor))->FUN_00c90510();
    }
}
