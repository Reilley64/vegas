
// src/havok/physics/dynamics/phantom/hkpcachingshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpcachingshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <new>
#include "fnv/decl/C.h"
#include "fnv/decl/CA92A0Object.h"
#include "fnv/decl/FUN_00ca94c0_Class.h"
#include "fnv/decl/FUN_00cfa7d0.h"
#include "fnv/decl/FUN_00d07cf0_cls.h"
#include "fnv/decl/fnv_00d4ce60__FUN_00d4ce60.h"
#include "fnv/decl/hkpAabbPhantomD07.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c9e000.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_00d4d000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01269000.h"
#include "havok/hkpCachingShapePhantom.h"

struct hkpCachingShapePhantomStandIn
{
    char m_padding000[0x8];
    char* unk08;
    char pad0c[0x4];
    char m_kCollidable[0x150];  // +0x10, hkpWorldObject::m_collidable
    void* m_kCollisionDetails;
    int m_collisionDetailsSize;
    char m_padding168[4];
    unsigned char m_bOrderDirty;

    void FUN_00d4d090();
};


// @fnv 0x00d4d090
void hkpCachingShapePhantomStandIn::FUN_00d4d090()
{
    if (m_bOrderDirty)
    {
        int size = m_collisionDetailsSize;

        union
        {
            unsigned char byteValue;
            unsigned int value;
        } seed;

        seed.byteValue = 0;

        if (size > 1)
            ::SortEntriesByCollisionKey((::CollisionKeyEntry *)(m_kCollisionDetails), 0, size - 1, seed.value);

        m_bOrderDirty = 0;
    }
}

// @fnv 0x00d4c910
int FUN_00d4c910()
{
    return 2;
}

struct GskAgentInput;
struct WorldOperationEntry;

struct hkpWorld
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74;
    GskAgentInput* m_pCollisionInput;
};

class hkpCollisionAgent
{
  public:
    virtual ~hkpCollisionAgent();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void ProcessAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const GskAgentInput& input,
                                  WorldOperationEntry& output);
};

struct CollisionAgentPair
{
    hkpCollisionAgent* m_pCollisionAgent;
    hkpCollidable* m_kCollidable;
};

class hkpCachingShapePhantomEx : public hkpShapePhantom
{
  public:
    hkArray<CollisionAgentPair> m_kCollisionDetails;
    hkBool m_bOrderDirty;
    char pad16D_0;
    char pad16D_1;
    char pad16D_2;

    void DispatchCollisionAgents(WorldOperationEntry& output, GskAgentInput* input);
};

// @fnv 0x00d4c920
void hkpCachingShapePhantomEx::DispatchCollisionAgents(WorldOperationEntry& output, GskAgentInput* input)
{
    if (!input)
    {
        input = ((hkpWorld*)this->m_pOwningWorld)->m_pCollisionInput;
    }
    for (int i = this->m_kCollisionDetails.m_iElementCount - 1; i >= 0; --i)
    {
        CollisionAgentPair* detail = &this->m_kCollisionDetails.m_data[i];
        detail->m_pCollisionAgent->ProcessAgent(this->m_kCollidable, *detail->m_kCollidable, *input, output);
    }
}

namespace fnv_00d4c980 {
struct CollisionAgentContext;

struct hkpWorldStandIn
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    CollisionAgentContext* m_pCollisionInput;
};

struct hkpCdBodyPairCollector
{
    virtual ~hkpCdBodyPairCollector();
    hkBool m_earlyOutHit;
};

struct hkpCollisionAgent
{
    virtual ~hkpCollisionAgent();
    virtual void unk04();
    virtual void unk08();
    virtual void getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                 hkpCdBodyPairCollector& collector);
};

struct CollisionAgentPair
{
    hkpCollisionAgent* m_pCollisionAgent;
    hkpCollidable* m_kCollidable;
};

struct hkpCachingShapePhantomStandIn2 : public hkpShapePhantom
{
    hkArray<CollisionAgentPair> m_kCollisionDetails;
    hkBool m_bOrderDirty;
    char pad16D;
    char pad16E;
    char pad16F;

    void GetPenetrations(hkpCdBodyPairCollector& collector, const CollisionAgentContext* input);
};

// Iterates the cached collision agent/collidable pairs and calls getPenetrations on each, stopping early if the collector signals an early-out hit.
// @fnv 0x00d4c980
void hkpCachingShapePhantomStandIn2::GetPenetrations(hkpCdBodyPairCollector& collector,
                                                     const CollisionAgentContext* input)
{
    if (!input)
    {
        input = ((hkpWorldStandIn*)m_pOwningWorld)->m_pCollisionInput;
    }

    for (int i = m_kCollisionDetails.m_iElementCount - 1; i >= 0; i--)
    {
        CollisionAgentPair* detail = &m_kCollisionDetails.m_data[i];
        detail->m_pCollisionAgent->getPenetrations(m_kCollidable, *detail->m_kCollidable, *input, collector);
        if (collector.m_earlyOutHit)
        {
            break;
        }
    }
}
}  // namespace fnv_00d4c980

struct hkBoolD4C9
{
    char m_cBooleanValue;
    hkBoolD4C9(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkpCollidableD4C9;

struct hkpCollisionDetailD4C9
{
    void* m_pCollisionAgent;
    hkpCollidableD4C9* m_kCollidable;
};

template <class T> class hkArrayD4C9
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkpCachingShapePhantomD4C9
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    hkArrayD4C9<hkpCollisionDetailD4C9> m_kCollisionDetails;

    hkBoolD4C9 ContainsCollidable(const hkpCollidableD4C9* pkCollidable) const;
};

// Searches the collision detail array for an entry whose collidable pointer equals pkCollidable and returns true if found, otherwise false.
// @fnv 0x00d4c9e0
hkBoolD4C9 hkpCachingShapePhantomD4C9::ContainsCollidable(const hkpCollidableD4C9* pkCollidable) const
{
    for (int i = 0; i < m_kCollisionDetails.GetLogicalSize(); i++)
    {
        if (m_kCollisionDetails[i].m_kCollidable == pkCollidable)
            return true;
    }
    return false;
}

class hkClassD4CD;



template <class T> class hkArrayD4CD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
};

class hkStatisticsCollectorD4CD
{
  public:
    virtual ~hkStatisticsCollectorD4CD() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();
    virtual void beginObject(const char* pcName) throw();
    virtual void endObject() throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayD4CD<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            int iAllocated = ::fnv_00d06f80::FUN_00d06f80((const char *)(kArray.m_data), kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkpCollidableD4CD;

class FUN_00d08130
{
  public:
    virtual ~FUN_00d08130() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    char m_pad08[0xa8];

};

class hkpCollisionAgentD4CD;

struct hkpCollisionDetailD4CD
{
    hkpCollisionAgentD4CD* m_pCollisionAgent;
    hkpCollidableD4CD* m_kCollidable;
};

class hkpCachingShapePhantomD4CD : public FUN_00d08130
{
  public:
    char m_padB0[0xb0];
    hkArrayD4CD<hkpCollisionDetailD4CD> m_kCollisionDetails;
    hkBool m_bOrderDirty;

    void AddToCollector(hkStatisticsCollectorD4CD* pkCollector, const hkClassD4CD* pkClass) const throw();
};

// Adds this phantom's base data and its AgentPtr array to the collector, then reports each collision agent as a child object under "agents".
// @fnv 0x00d4cd60
void hkpCachingShapePhantomD4CD::AddToCollector(hkStatisticsCollectorD4CD* pkCollector,
                                                const hkClassD4CD* pkClass) const throw()
{
    reinterpret_cast<::FUN_00d07cf0_cls *>((void *)this)->WritePhantomLists((::PhArchive *)(pkCollector), &::g_0126902c);
    pkCollector->addArray("AgentPtr", m_kCollisionDetails);
    pkCollector->beginObject("agents");
    for (int i = 0; i < m_kCollisionDetails.GetLogicalSize(); i++)
        pkCollector->addChildObject(0, m_kCollisionDetails.m_data[i].m_pCollisionAgent, 0);
    pkCollector->endObject();
}




template <class T> __forceinline void copyD4D0(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <class T> class hkArrayD4D0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void operator=(const hkArrayD4D0& a)
    {
        copyFromArray(hkMemoryRouter::getInstance().heap(), a);
    }
    __forceinline void copyFromArray(hkMemoryAllocator& kAlloc, const hkArrayD4D0& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = kAlloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyD4D0(m_data, a.m_data, m_iElementCount);
    }
};

struct hkVector4D4D0
{
    hkReal x, y, z, w;
};

struct hkTransformD4D0
{
    hkVector4D4D0 m_kColumn0;
    hkVector4D4D0 m_kColumn1;
    hkVector4D4D0 m_kColumn2;
    hkVector4D4D0 m_vTranslation;
};

class hkpShapeD4D0;
class hkpPhantomOverlapListenerD4D0;
class hkpPhantomListenerD4D0;

struct hkpCollidableD4D0
{
    const hkpShapeD4D0* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    char m_pad10[0xc];
    hkUint32 m_uiCollisionFilterData;
    char m_pad20[0x50];

    const hkpShapeD4D0* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

class hkpWorldObjectD4D0
{
  public:
    virtual ~hkpWorldObjectD4D0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    void* m_pOwningWorld;
    hkUlong m_ulUserData;
    hkpCollidableD4D0 m_kCollidable;

    const hkpCollidableD4D0* getCollidable() const
    {
        return &m_kCollidable;
    }
};

class FUN_00d4ce10 : public hkpWorldObjectD4D0
{
  public:
    static __forceinline void* operator new(size_t uiSize) throw()
    {
        hkpWorldObjectD4D0* p = static_cast<hkpWorldObjectD4D0*>(hkMemoryRouter::getInstance().heap().blockAlloc(uiSize));
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    char m_pad80[0xc];
    hkArrayD4D0<hkpPhantomOverlapListenerD4D0*> m_kPhantomOverlapListeners;
    hkArrayD4D0<hkpPhantomListenerD4D0*> m_kPhantomListeners;
    char m_padA4[0xc];
    hkTransformD4D0 m_kMotionTransform;
    char m_padF0[0x80];

    const hkTransformD4D0& getTransform() const
    {
        return m_kMotionTransform;
    }

    FUN_00d4ce10(const hkpShapeD4D0* pkShape, const hkTransformD4D0& kTransform,
                 hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObjectD4D0* FUN_00d4d0d0() const throw();
};


// @fnv 0x00d4d0d0
hkpWorldObjectD4D0* FUN_00d4ce10::FUN_00d4d0d0() const throw()
{
    const hkpCollidableD4D0* pkCollidable = getCollidable();
    FUN_00d4ce10* pkPhantom =
        new FUN_00d4ce10(pkCollidable->getShape(), getTransform(), pkCollidable->GetFilterInfoForKey());
    pkPhantom->m_kPhantomOverlapListeners = m_kPhantomOverlapListeners;
    pkPhantom->m_kPhantomListeners = m_kPhantomListeners;
    reinterpret_cast<::CA92A0Object *>((pkPhantom))->CopyEntriesFrom((const ::CA92A0Object *)(const ::hkpWorldObjectD4D0 *)(this));
    return pkPhantom;
}

struct CollisionTarget
{
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    unsigned int collisionKey;
};
struct CollisionKeyEntry
{
    int shapeKey;
    CollisionTarget* target;
};
// Recursively quicksorts entries by their target's collisionKey, partitioning around a pivot and swapping out-of-order elements.
// @fnv 0x00d4d250
void __cdecl SortEntriesByCollisionKey(CollisionKeyEntry* entries, int left, int right, int context)
{
    int i = left;
    int iRight = right;
    __declspec(align(16)) CollisionKeyEntry pivotEntry = entries[(i + iRight) >> 1];
    do
    {
        while (entries[i].target->collisionKey < pivotEntry.target->collisionKey)
            ++i;
        while (pivotEntry.target->collisionKey < entries[iRight].target->collisionKey)
            --iRight;
        if (iRight < i)
            break;
        if (iRight != i)
        {
            CollisionKeyEntry tempEntry = entries[iRight];
            entries[iRight] = entries[i];
            entries[i] = tempEntry;
        }
        --iRight;
        ++i;
    } while (i <= iRight);
    if (left < iRight)
        SortEntriesByCollisionKey(entries, left, iRight, context);
    if (i < right)
        SortEntriesByCollisionKey(entries, i, right, context);
}

namespace fnv_00d4d310 {

struct FnvCpu_FUN_00d4d310_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d4d310_CpuObject* FUN_00d4d310(unsigned int flags);
};
// @fnv 0x00d4d310
FnvCpu_FUN_00d4d310_CpuObject* FnvCpu_FUN_00d4d310_CpuObject::FUN_00d4d310(unsigned int flags)
{
    reinterpret_cast<::fnv_00d4ce60::FUN_00d4ce60 *>(this)->fnv_00d4ce60::FUN_00d4ce60::~FUN_00d4ce60();
    if (flags & 1)
    {
        hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d4d310

#include <xmmintrin.h>
struct Aligned_00d4cc50
{
    __m128 column0, column1, column2;
    __m128 translation;  // +0x30
};
struct FUN_00d4cc50_cls
{
    int field000;
    int field004;
    int field008;
    int field00c;
    int field010;
    int field014;
    int field018;
    int field01c;
    int field020;
    int field024;
    int field028;
    int field02c;
    int field030;
    int field034;
    int field038;
    int field03c;
    int field040;
    int field044;
    int field048;
    int field04c;
    int field050;
    int field054;
    int field058;
    int field05c;
    int field060;
    int field064;
    int field068;
    int field06c;
    int field070;
    int field074;
    int field078;
    int field07c;
    int field080;
    int field084;
    int field088;
    int field08c;
    int field090;
    int field094;
    int field098;
    int field09c;
    int field0a0;
    int field0a4;
    int field0a8;
    int field0ac;
    __m128 output0;
    __m128 output1;
    __m128 output2;
    void CopyFrom(const Aligned_00d4cc50* source, const void* a, void* b, void* c);
};
extern int DAT_010ccebc;

struct hkBool_d4cc
{
    char m_cBooleanValue;
    hkBool_d4cc(bool b) : m_cBooleanValue(b)
    {}
    hkBool_d4cc(const hkBool_d4cc& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
};

struct Visitor_d4cc
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14;
};

struct Listener_d4cc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void visit(Visitor_d4cc* v);
};

struct Entry_d4cc
{
    Listener_d4cc* m_kListener;
    void* m_object;
};

inline void memCpy4_d4cc(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d4cc
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d4cc(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Owned_d4cc
{
    int m_00;
};

struct World_d4cc
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    hkArray_d4cc<Entry_d4cc> m_entries;
    unsigned char m_bValueAt0C;
    void FUN_00d4cca0(Owned_d4cc* obj);
};

// Removes the first entry whose m_object matches obj, notifying listeners via NotifyAll and visit, and sets m_bValueAt0C on success.
// @fnv 0x00d4cca0
void World_d4cc::FUN_00d4cca0(Owned_d4cc* apOwned)
{
    Visitor_d4cc visitor;
    visitor.m_sReferenceCount = 1;
    visitor.m_vtbl = &DAT_010ccebc;
    if (!apOwned->m_00)
        return;
    for (int i = m_entries.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (m_entries[i].m_object == apOwned)
        {
            reinterpret_cast<::C *>(this)->NotifyAll((intptr_t)(apOwned), (*(char *)&(const ::hkBool_d4cc &)(hkBool_d4cc(true))));
            if (m_entries[i].m_kListener)
                m_entries[i].m_kListener->visit(&visitor);
            m_entries.removeAt(i);
            m_bValueAt0C = 1;
            return;
        }
    }
    reinterpret_cast<::C *>(this)->NotifyAll((intptr_t)(apOwned), (*(char *)&(const ::hkBool_d4cc &)(hkBool_d4cc(false))));
}

class hkpCollidable;


template <typename T> struct hkArrayD4CF
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& _expandOne(hkMemoryAllocator& kAlloc)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        return m_data[m_iElementCount++];
    }
    T& AllocatePair()
    {
        return _expandOne(hkMemoryRouter::getInstance().heap());
    }
};

struct hkpShapeD4CF
{
    void* m_ppVirtualMethodTable;
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUlong m_ulUserData;
    int m_type;
};

struct hkpProcessCollisionInputD4CF;
struct hkpCollisionAgentD4CF;
typedef hkpCollisionAgentD4CF*(__cdecl* hkpCreateAgentFuncD4CF)(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                                                const hkpProcessCollisionInputD4CF& kInput,
                                                                void* pvMgr);

struct hkpAgentFuncsD4CF
{
    hkpCreateAgentFuncD4CF m_pCreateFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pLinearCastFunc;
    int m_bIsFlipped;
};

struct hkpCollisionQualityInfoD4CF
{
    int m_unk00;
};

struct hkpCollisionDispatcherD4CF
{
    int m_unk000, m_unk004, m_unk008, m_unk00c, m_unk010, m_unk014, m_unk018, m_unk01c;
    int m_unk020, m_unk024, m_unk028, m_unk02c, m_unk030, m_unk034, m_unk038, m_unk03c;
    int m_unk040, m_unk044, m_unk048, m_unk04c, m_unk050, m_unk054, m_unk058, m_unk05c;
    int m_unk060, m_unk064, m_unk068, m_unk06c, m_unk070, m_unk074, m_unk078, m_unk07c;
    int m_unk080, m_unk084, m_unk088, m_unk08c, m_unk090, m_unk094, m_unk098, m_unk09c;
    int m_unk0a0, m_unk0a4, m_unk0a8, m_unk0ac, m_unk0b0, m_unk0b4, m_unk0b8, m_unk0bc;
    int m_unk0c0, m_unk0c4, m_unk0c8, m_unk0cc, m_unk0d0, m_unk0d4, m_unk0d8, m_unk0dc;
    int m_unk0e0, m_unk0e4, m_unk0e8, m_unk0ec, m_unk0f0, m_unk0f4, m_unk0f8, m_unk0fc;
    int m_unk100, m_unk104, m_unk108, m_unk10c, m_unk110, m_unk114, m_unk118, m_unk11c;
    int m_unk120, m_unk124, m_unk128, m_unk12c, m_unk130, m_unk134, m_unk138, m_unk13c;
    int m_unk140, m_unk144, m_unk148, m_unk14c, m_unk150, m_unk154, m_unk158, m_unk15c;
    int m_unk160, m_unk164, m_unk168, m_unk16c, m_unk170, m_unk174, m_unk178, m_unk17c;
    int m_unk180, m_unk184, m_unk188, m_unk18c, m_unk190, m_unk194, m_unk198, m_unk19c;
    hkUint8 m_agent2TypeMap[32][32];
    hkUint8 m_agent3TypeMap[32][32];
    hkpAgentFuncsD4CF m_agent2Funcs[240];
    hkpCollisionQualityInfoD4CF m_pCollisionQualityInfo[1];

    hkpCreateAgentFuncD4CF getNewCollisionAgentFunc(int iTypeA, int iTypeB, int iPredictive) const
    {
        const hkUint8* pTypes = iPredictive ? &m_agent3TypeMap[0][0] : &m_agent2TypeMap[0][0];
        int iIdx = pTypes[iTypeA * 32 + iTypeB];
        return m_agent2Funcs[iIdx].m_pCreateFunc;
    }
    hkpCollisionAgentD4CF* getNewCollisionAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB,
                                                const hkpProcessCollisionInputD4CF& kInput, void* pvMgr) const;
    hkpCollisionQualityInfoD4CF* getCollisionQualityInfo(int iIndex)
    {
        return &m_pCollisionQualityInfo[iIndex];
    }
};

struct __declspec(align(16)) hkVector4D4CF
{
    hkReal x, y, z, w;
};

struct hkpCollisionInputD4CF
{
    hkpCollisionDispatcherD4CF* m_pCollisionDispatcher;
    hkUint32 m_collisionQuality;
    hkUint32 m_forceAcceptContactPoints;
    hkReal m_fScalar;
    const void* m_iFilter;
    hkUint32 m_bCreatePredictiveAgents;
    hkVector4D4CF m_kAabbMin;
    hkVector4D4CF m_kAabbMaximum;
    hkVector4D4CF m_kAabbScale;
};

struct hkpProcessCollisionInputD4CF : public hkpCollisionInputD4CF
{
    hkReal m_uiStartTime;
    hkReal m_fEndTime;
    hkReal m_fTimeStep;
    hkReal m_fInverseDeltaTime;
    hkpCollisionQualityInfoD4CF* m_pCollisionQualityInfo;
    void* m_pAgent1nSector;
    void* m_pCollisionFilter;
    hkBool m_bEnableDeprecatedWelding;
    hkBool m_bAllowToSkipConfirmedCallbacks;
    void* m_pConfiguration;

    hkpProcessCollisionInputD4CF(const hkpProcessCollisionInputD4CF& kOther) throw() : hkpCollisionInputD4CF(kOther)
    {
        m_pAgent1nSector = 0;
        new ((void *)this) ::FUN_00cfa7d0((const ::FUN_00cfa7d0 &)(kOther));
    }
    ~hkpProcessCollisionInputD4CF() throw()
    {
        if (m_pAgent1nSector)
            hkMemoryRouter::getInstance().heap().blockFree(m_pAgent1nSector, 0x200);
    }
};

__forceinline hkpCollisionAgentD4CF* hkpCollisionDispatcherD4CF::getNewCollisionAgent(
    const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const hkpProcessCollisionInputD4CF& kInput, void* pvMgr) const
{
    int iTypeA = ((hkpShapeD4CF*)kBodyA.m_pCollisionShape)->m_type;
    int iTypeB = ((hkpShapeD4CF*)kBodyB.m_pCollisionShape)->m_type;
    hkpCreateAgentFuncD4CF pfnCreate = getNewCollisionAgentFunc(iTypeA, iTypeB, kInput.m_bCreatePredictiveAgents);
    return pfnCreate(kBodyA, kBodyB, kInput, pvMgr);
}

struct hkpWorldD4CF
{
    int m_unk000, m_unk004, m_unk008, m_unk00c, m_unk010, m_unk014, m_unk018, m_unk01c;
    int m_unk020, m_unk024, m_unk028, m_unk02c, m_unk030, m_unk034, m_unk038, m_unk03c;
    int m_unk040, m_unk044, m_unk048, m_unk04c, m_unk050, m_unk054, m_unk058, m_unk05c;
    int m_unk060, m_unk064, m_unk068, m_unk06c, m_unk070, m_unk074;
    hkpProcessCollisionInputD4CF* m_pCollisionInput;
};

struct hkpCollisionDetailD4CF
{
    hkpCollisionAgentD4CF* m_pCollisionAgent;
    hkpCollidable* m_kCollidable;
};

class hkpCachingShapePhantomD4CF : public hkpShapePhantom
{
  public:
    hkArrayD4CF<hkpCollisionDetailD4CF> m_kCollisionDetails;
    hkBool m_bOrderDirty;

    void FUN_00d4cf10(hkpCollidable* pkCollidable) throw();
};

// @fnv 0x00d4cf10
void hkpCachingShapePhantomD4CF::FUN_00d4cf10(hkpCollidable* pkCollidable) throw()
{
    if (pkCollidable->m_pCollisionShape != 0 && reinterpret_cast<::FUN_00ca94c0_Class *>(this)->FUN_00ca94c0((pkCollidable)) == 0)
    {
        hkpCollisionDetailD4CF& kDetail = m_kCollisionDetails.AllocatePair();
        hkpProcessCollisionInputD4CF kInput = *((hkpWorldD4CF*)m_pOwningWorld)->m_pCollisionInput;
        kInput.m_bCreatePredictiveAgents = false;
        kInput.m_pCollisionQualityInfo = kInput.m_pCollisionDispatcher->getCollisionQualityInfo(0);
        kDetail.m_pCollisionAgent =
            kInput.m_pCollisionDispatcher->getNewCollisionAgent(m_kCollidable, *pkCollidable, kInput, 0);
        kDetail.m_kCollidable = pkCollidable;
        m_bOrderDirty = true;
    }
}

#include <string.h>
extern int DAT_010ccebc;

struct VFn20Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20(void* a, int b, int* c, void* d);
};

struct PairDC4A30
{
    VFn20Obj* m_obj;
    int m_data;
};

__declspec(align(8)) struct QueryDC4A30
{
    const void* m_pOwningWorld;
    hkUint16 m_unk04;
    hkUint16 m_type;
    hkUint64 m_unk08;
    hkUint64 m_unk10;
};

struct Ca30Derived : public hkpCachingShapePhantomStandIn
{
    void QueryCollisionDetails();
};

// Copies 0x50 bytes from the pointer at (this->8)+0x78 into a local buffer, then calls v20 on each collision detail entry with it and a type-1 query.
// @fnv 0x00d4ca30
void Ca30Derived::QueryCollisionDetails()
{
    QueryDC4A30 query;
    __declspec(align(16)) int buffer[20];

    char* container = this->unk08;
    char* src = *(char**)(container + 0x78);
    memcpy(buffer, src, 0x50);

    query.m_type = 1;
    query.m_pOwningWorld = &DAT_010ccebc;

    for (int i = 0; i < m_collisionDetailsSize; ++i)
    {
        PairDC4A30* pair = (PairDC4A30*)m_kCollisionDetails + i;
        pair->m_obj->v20(m_kCollidable, pair->m_data, buffer, &query);
    }
}

namespace fnv_00d4d030 {


namespace hkRouterD4D0 {

}

struct PairD4D0
{
    int m_kPointA;
    int m_kPointB;
};

template <class T> class hkArrayD4D0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkOwnerD4D0
{
  public:
    char unk000[0x160];
    hkArrayD4D0<PairD4D0> m_ppData;

    void FUN_00d4d030();
};

// Releases m_ppData's buffer when its element count is 0, then calls FUN_00c9e820.
// @fnv 0x00d4d030
void hkOwnerD4D0::FUN_00d4d030()
{
    if (m_ppData.m_iElementCount == 0)
        m_ppData.ClearAndRelease();
    ::FUN_00c9e820();
}
}  // namespace fnv_00d4d030



class hkpCdPointCollector;

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

class hkpShape : public hkReferencedObject
{
  public:
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void getAabb(const hkTransform& transform, hkReal floatTolerance, hkAabb& out) const;
};

struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    int m_unk04;
    union
    {
        hkReal m_fScalar;
        int m_toleranceInt;
    };
    void* m_unk0c;
    void* m_unk10;
    int m_unk14;
    int m_pad18;
    int m_pad1c;
    hkVector4 m_v0;
    hkVector4 m_v1;
    hkVector4 m_v2;
};

struct GskAgentInput : public CollisionAgentContext
{
    int m_pad50;
    int m_pad54;
    int m_pad58;
    int m_pad5c;
    int m_pad60;
    int m_pad64;
    int m_pad68;
    int m_pad6c;
    void* m_pConfiguration;
};

struct ShapeSweepParameters : public CollisionAgentContext
{
    hkVector4 m_path;
    hkReal m_fMaxExtraPenetration;
    hkReal m_cachedDistances;
    void* m_pConfiguration;

    __forceinline ShapeSweepParameters()
    {
        m_fMaxExtraPenetration = ::DAT_0104da4c;
        m_unk04 = 0;
    }
    __forceinline void set(const GskAgentInput& input)
    {
        m_pCollisionDispatcher = input.m_pCollisionDispatcher;
        m_unk04 = input.m_unk04;
        m_toleranceInt = input.m_toleranceInt;
        m_unk0c = input.m_unk0c;
        m_unk10 = input.m_unk10;
        m_unk14 = input.m_unk14;
        *(__m128*)&m_v0 = *(__m128*)&input.m_v0;
        *(__m128*)&m_v1 = *(__m128*)&input.m_v1;
        *(__m128*)&m_v2 = *(__m128*)&input.m_v2;
        m_pConfiguration = input.m_pConfiguration;
    }
};

struct LinearCastParameters
{
    hkVector4 m_vTo;
    hkReal m_fMaxExtraPenetrationAgainstFixed;
    hkReal m_fMaxExtraPenetration;
};

struct hkpCachingShapePhantomLocal : public hkpCachingShapePhantom
{
    void FUN_00d4cab0(const hkVector4& position, const LinearCastParameters& input, hkpCdPointCollector& castCollector,
                      hkpCdPointCollector* startCollector);
};
// Copies source's three __m128 columns into output0..2, then calls FUN_00d4cab0 with source's translation and a, b, c.
// @fnv 0x00d4cc50
void FUN_00d4cc50_cls::CopyFrom(const Aligned_00d4cc50* source, const void* a, void* b, void* c)
{
    output0 = source->column0;
    output1 = source->column1;
    output2 = source->column2;
    reinterpret_cast<::hkpCachingShapePhantomLocal *>(this)->FUN_00d4cab0((*(const ::hkVector4 *)(&source->translation)), (*(const ::LinearCastParameters *)(a)), (*(::hkpCdPointCollector *)(b)), (::hkpCdPointCollector *)(c));
}

class hkpCollisionAgentLinear : public hkpCollisionAgent
{
  public:
    virtual void linearCast(const hkpCdBody& a, const hkpCdBody& b, const ShapeSweepParameters& input,
                            hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector);
};

// Performs a linear cast against collidables by computing an expanded AABB and invoking linearCast on each collision agent pair.
// @fnv 0x00d4cab0
void hkpCachingShapePhantomLocal::FUN_00d4cab0(const hkVector4& position, const LinearCastParameters& input,
                                               hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector)
{
    *(__m128*)&m_kMotionState.m_kMotionTransform.m_vTranslation = *(__m128*)&position;

    hkAabb aabb;
    hkReal tol =
        (hkReal)(((hkpWorld*)m_pOwningWorld)->m_pCollisionInput->m_fScalar * 0.5) + input.m_fMaxExtraPenetration;
    m_kCollidable.m_pCollisionShape->getAabb(m_kMotionState.m_kMotionTransform, tol, aabb);

    __m128 path = _mm_sub_ps(*(__m128*)&input.m_vTo, *(__m128*)&position);

    __m128 zero = _mm_setzero_ps();
    __m128 minVal = _mm_min_ps(zero, path);
    __m128 maxVal = _mm_max_ps(zero, path);

    __m128 auiLowerBounds = *(__m128*)&aabb.m_kMinimumCorner;
    __m128 auiUpperBounds = *(__m128*)&aabb.m_kMaximumCorner;

    auiLowerBounds = _mm_add_ps(minVal, auiLowerBounds);
    auiUpperBounds = _mm_add_ps(maxVal, auiUpperBounds);

    *(__m128*)&aabb.m_kMinimumCorner = auiLowerBounds;
    *(__m128*)&aabb.m_kMaximumCorner = auiUpperBounds;

    reinterpret_cast<::hkpAabbPhantomD07 *>(this)->FUN_00d07ec0((const ::hkAabbD07 &)(aabb));

    ShapeSweepParameters linearInput;
    linearInput.set(*((hkpWorld*)m_pOwningWorld)->m_pCollisionInput);

    *(__m128*)&linearInput.m_path = path;

    __m128 sq = _mm_mul_ps(path, path);
    __m128 sh1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 sh2 = _mm_shuffle_ps(sq, sq, 0xAA);
    __m128 add1 = _mm_add_ss(sh1, sq);
    __m128 add2 = _mm_add_ss(sh2, add1);
    __m128 len = _mm_sqrt_ss(add2);

    linearInput.m_cachedDistances = _mm_cvtss_f32(len);

    linearInput.m_fScalar = input.m_fMaxExtraPenetration;
    linearInput.m_fMaxExtraPenetration = input.m_fMaxExtraPenetrationAgainstFixed;

    for (int i = m_kCollisionDetails.m_iElementCount - 1; i >= 0; --i)
    {
        CollisionAgentPair* detail = &((CollisionAgentPair*)m_kCollisionDetails.m_data)[i];
        ((hkpCollisionAgentLinear*)detail->m_pCollisionAgent)
            ->linearCast(*(hkpCdBody*)&m_kCollidable, *detail->m_kCollidable, linearInput, castCollector,
                         startCollector);
    }
}
