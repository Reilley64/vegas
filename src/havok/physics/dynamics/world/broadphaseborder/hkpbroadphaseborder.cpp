
// src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00d0b5d0
#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c91620_Class.h"
#include "fnv/decl/FUN_00ca8420_Class.h"
#include "fnv/decl/PhRemoveListener.h"
#include "fnv/decl/SearchArray.h"
#include "fnv/decl/World_RemovePhantomBatch.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkWorldXc91a70.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00e10000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010c9000.h"
#include "fnv/symbols_010cb000.h"
#include "fnv/symbols_010cc000.h"
// hkpEntity::m_uiUniqueId.
struct BorderUniqueIdFields
{
    char pad00[0xd4];
    unsigned int m_uiUniqueId;  // +0xd4
};
int __cdecl CompareByOffsetD4(const void* apFirst, const void* apSecond)
{
    return static_cast<const BorderUniqueIdFields*>(apFirst)->m_uiUniqueId < static_cast<const BorderUniqueIdFields*>(apSecond)->m_uiUniqueId;
}

class hkReferencedObject
{
};
struct Item : hkReferencedObject
{
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
};
struct Manager
{
};
struct Collection
{
    virtual void slot00();
    virtual void removeItems(Manager* manager);
};
struct AllocatorOwner
{
    int unk00;
    int unk04;
    Collection collection;
    int unk0C;
    int unk10;
    Manager* manager;
    Item* entries[6];
    void ReleaseEntries();
};
// @fnv 0x00d0b570
void AllocatorOwner::ReleaseEntries()
{
    if (manager == 0)
        return;
    reinterpret_cast<::World_RemovePhantomBatch *>((manager))->FUN_00c95800((::hkpPhantom **)(entries), 6);
    Item** pEntry = entries;
    void* owner = &unk0C;
    int count = 6;
    do
    {
        reinterpret_cast<::PhRemoveListener *>(((*pEntry)))->FUN_00d07c80(owner);
        reinterpret_cast<::hkReferencedObjectC905 *>(((*pEntry)))->FUN_00c905b0();
        *pEntry = 0;
        ++pEntry;
        --count;
    } while (count != 0);
    collection.removeItems(manager);
    manager = 0;
}

struct DispatchItem;
struct DispatchOwner
{
};
struct DispatchItem
{
    unsigned int unknown00;
    unsigned int unknown04;
    DispatchOwner* owner;
};
struct Dispatcher
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    DispatchOwner* owner;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    int mode;
    void DispatchItemByMode(DispatchItem* item);
};
// Switches on mode: for modes 0 and 1 calls item->FUN_00ca8420(5,1,0); for mode 2, if item->owner equals owner, calls owner->ProcessTarget(&success, item).
// @fnv 0x00d0b5f0
void Dispatcher::DispatchItemByMode(DispatchItem* item)
{
    switch (mode)
    {
    case 0:
        reinterpret_cast<::FUN_00ca8420_Class *>((item))->FUN_00ca8420(5, 1, 0);
        break;
    case 1:
        reinterpret_cast<::FUN_00ca8420_Class *>((item))->FUN_00ca8420(5, 1, 0);
        break;
    case 2:
        if (item->owner == owner)
        {
            bool success;
            reinterpret_cast<::FUN_00c91620_Class *>((owner))->ProcessTarget((unsigned char *)(bool *)(&success), (::FUN_00c91620_Target *)(item));
        }
        break;
    }
}

template <typename T> inline void S_00e10760_swap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
struct S_00e10760_Item;
typedef bool (*S_00e10760_Less)(S_00e10760_Item* a, S_00e10760_Item* b);

// Sorts the range [d, h] of pArr in place using a Hoare-partition quicksort with cmpLess, recursing on the left part and looping on the right.
// @fnv 0x00e10760
void FUN_00e10760(S_00e10760_Item** apItems, int aiLow, int aiHigh, S_00e10760_Less apLess)
{
    int i, iRight;
    __declspec(align(16)) S_00e10760_Item* pPivot;
begin:
    iRight = aiHigh;
    i = aiLow;
    pPivot = apItems[(aiLow + aiHigh) >> 1];
    do
    {
        while (apLess(apItems[i], pPivot))
        {
            i++;
        }
        while (apLess(pPivot, apItems[iRight]))
        {
            iRight--;
        }
        if (i <= iRight)
        {
            if (iRight != i)
            {
                S_00e10760_swap(apItems[iRight], apItems[i]);
            }
            iRight--;
            i++;
        }
    } while (i <= iRight);
    if (aiLow < iRight)
    {
        FUN_00e10760(apItems, aiLow, iRight, apLess);
    }
    if (i < aiHigh)
    {
        aiLow = i;
        goto begin;
    }
}

struct OwnerDest
{
};

struct NodeHdr
{
};

// The world-deletion listener base of hkpBroadPhaseBorder sits at +0x8, after hkReferencedObject.
static const int kBorderListenerOffset = 0x8;
struct FUN_00d0b530_cls
{
    int unk00;
    int unk04;
    int unk08;
    OwnerDest* m_0C;

    void FUN_00d0b530(int unused);
};

// @fnv 0x00d0b530
void FUN_00d0b530_cls::FUN_00d0b530(int unused)
{
    NodeHdr* owner = reinterpret_cast<NodeHdr*>((char*)this - kBorderListenerOffset);
    reinterpret_cast<::hkWorldXc91a70 *>((m_0C))->FUN_00c91a70(owner ? (void*)this : 0);
    reinterpret_cast<::SearchArray *>((m_0C))->ClearValue((owner ? (void*)((char*)&this->unk08) : 0));
    reinterpret_cast<::hkReferencedObjectC905 *>(owner)->FUN_00c905b0();
}

struct D0B630Entity;

int __cdecl CompareByOffsetD4(const void* a, const void* b);

class D0B630Primary
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void entityAdded(D0B630Entity* entity);

    int unk04;
    int unk08;
    int unk0C;
};

class D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);
};

class D0B630Collector : public D0B630Primary, public D0B630Secondary
{
  public:
    virtual void FlushDeferredEntities(const void* event);

    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    D0B630Entity** m_deferred;
    int m_numDeferred;
};

// @fnv 0x00d0b630
void D0B630Collector::FlushDeferredEntities(const void* event)
{
    if (m_numDeferred)
    {
        if (m_numDeferred > 1)
            ::FUN_00e10760((::S_00e10760_Item **)(m_deferred), 0, m_numDeferred - 1, (bool (*)(S_00e10760_Item *, S_00e10760_Item *))(CompareByOffsetD4));
        for (int i = 0; i < m_numDeferred; i++)
            entityAdded(m_deferred[i]);
        ::FUN_00c90740(m_deferred, m_numDeferred, sizeof(D0B630Entity*));
        m_numDeferred = 0;
    }
}



struct D0B6A0Entity
{
};

struct D0B6A0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_type;

    void* getOwner() const
    {
        return const_cast<char*>(reinterpret_cast<const char*>(this)) + m_iOwnerOffset;
    }
};

struct D0B6A0Event
{
    int unk00;
    const D0B6A0Collidable* m_kCollidable;
};

struct D0B6A0EntityArray
{
    D0B6A0Entity** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    static void construct(D0B6A0Entity** p, int n, D0B6A0Entity* const& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    __forceinline void AddBack(D0B6A0Entity* const& e)
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(D0B6A0Entity*));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

class D0B6A0Primary
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void entityAdded(D0B6A0Entity* entity);

    int unk04;
    int unk08;
};

class D0B6A0Secondary
{
  public:
    virtual void HandleEvent(const D0B6A0Event& event);
};

class D0B6A0Collector : public D0B6A0Primary, public D0B6A0Secondary
{
  public:
    virtual void HandleEvent(const D0B6A0Event& event);

    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    bool m_deferAdds;
    D0B6A0EntityArray m_deferredEntities;
};

// Handles an event: if the collidable's m_type is 1, gets its owner entity and either defers it into m_deferredEntities or calls entityAdded.
// @fnv 0x00d0b6a0
void D0B6A0Collector::HandleEvent(const D0B6A0Event& event)
{
    const D0B6A0Collidable* collidable = event.m_kCollidable;
    if (collidable->m_type == 1)
    {
        D0B6A0Entity* entity = static_cast<D0B6A0Entity*>(collidable->getOwner());
        if (entity)
        {
            if (m_deferAdds)
            {
                m_deferredEntities.AddBack(entity);
                reinterpret_cast<::FUN_00c90510_class *>((void *)(entity))->FUN_00c90510();
            }
            else
            {
                entityAdded(entity);
            }
        }
    }
}

namespace fnv_00d0bb20 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct BSAudio;


extern int DAT_010cd3c4;
extern int DAT_010cd3b4;
extern int DAT_010cd3a4;
extern int DAT_010cd394;

struct FUN_00d0bb20_cls
{
    const void* m_vptr00;
    int unk04;
    const void* m_vptr08;
    const void* m_vptr0c;
    const void* m_vptr10;
    int unk14;
    hkReferencedObject* m_entries[6];
    int unk30;
    int unk34;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void Destroy();
};


// @fnv 0x00d0bb20
void FUN_00d0bb20_cls::Destroy()
{
    m_vptr00 = &DAT_010cd3c4;
    m_vptr08 = &DAT_010cd3b4;
    m_vptr0c = &DAT_010cd3a4;
    m_vptr10 = &DAT_010cd394;
    hkReferencedObject** pEntry = m_entries;
    int i = 6;
    do
    {
        if (*pEntry != 0)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>(((*pEntry)))->FUN_00c905b0();
            *pEntry = 0;
        }
        pEntry++;
        i--;
    } while (i != 0);
    hkMemoryAllocator* pAudioAllocator = hkMemoryRouter::getInstance().m_heap;
    m_iArrayLength = i;
    unsigned int uiCapBits = m_uCapBits;
    if ((uiCapBits & 0x80000000u) == 0)
    {
        pAudioAllocator->bufFree(m_pData, (uiCapBits & 0x3fffffffu) * 4);
    }
    unsigned int* puiCap = &m_uCapBits;
    m_pData = 0;
    *puiCap = 0x80000000u;
    m_vptr10 = &::DAT_010ccf7c;
    m_vptr0c = &::DAT_010c925c;
    m_vptr08 = &::DAT_010cb1c4;
    m_vptr00 = &::DAT_0102e388;
}
}  // namespace fnv_00d0bb20

// @fnv 0x00d0b520
void FUN_00d0b520(int)
{}

// hkpBroadPhaseBorder (the RTTI name in the image) has one primary base and
// several secondary bases; all of them declare the same virtual function and
// the border class overrides it.  MSVC 2008 builds a per-base vftable for
// every secondary base, and the slot of the overridden virtual points at a
// compiler generated adjustor thunk that moves `this' from the secondary base
// back to the border object.  This is the thunk of the base that sits eight
// bytes into the object, so it steps `this' back by eight and jumps to the
// overriding implementation.
//
// The virtual itself is deliberately left undefined: the thunk then jumps to
// an undefined external just like in the image, and the checker resolves that
// relocation from the original bytes instead of comparing a second function.
struct hkBroadPhasePrimary
{
    hkBroadPhasePrimary();
    virtual void FUN_00d0bbc0(int flag);
    int unk04;
};

struct hkBroadPhaseSecondary
{
    hkBroadPhaseSecondary();
    virtual void FUN_00d0bbc0(int flag);
};

struct hkBroadPhaseBorder : public hkBroadPhasePrimary, public hkBroadPhaseSecondary
{
    hkBroadPhaseBorder();
// @fnv 0x00d0bbc0
    virtual void FUN_00d0bbc0(int flag);
};

hkBroadPhasePrimary::hkBroadPhasePrimary()
{}
hkBroadPhaseSecondary::hkBroadPhaseSecondary()
{}
hkBroadPhaseBorder::hkBroadPhaseBorder() : hkBroadPhasePrimary(), hkBroadPhaseSecondary()
{}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct FnvHavok00d0bbe0_PrimaryBase
{
    virtual void FUN_00d0bbe0();
    int unk04;
    int unk08;
    int unk0C;
};

struct FnvHavok00d0bbe0_SecondaryBase
{
    virtual void FUN_00d0bbe0();
};

struct FnvHavok00d0bbe0_Derived : FnvHavok00d0bbe0_PrimaryBase, FnvHavok00d0bbe0_SecondaryBase
{
    FnvHavok00d0bbe0_Derived();
// @fnv 0x00d0bbe0
    virtual void FUN_00d0bbe0();
};

FnvHavok00d0bbe0_Derived::FnvHavok00d0bbe0_Derived()
{}

namespace fnv_00d0bbf0 {



struct FUN_00d0bbf0
{
    __declspec(noinline) virtual ~FUN_00d0bbf0();
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    static void operator delete(void* object)
    {
        hkMemoryRouter::getInstance().heap().blockFree(object, static_cast<FUN_00d0bbf0*>(object)->unk04);
    }
};

// Empty destructor; the class's operator delete returns the block to the allocator using the size stored in unk04.
// @fnv 0x00d0bbf0
FUN_00d0bbf0::~FUN_00d0bbf0()
{}
}  // namespace fnv_00d0bbf0

struct BorderDeletePrimary : D0B6A0Primary
{
    virtual void* FUN_00d0bbd0(unsigned int flags);
};

struct BorderDeleteSecondary
{
    virtual void* FUN_00d0bbd0(unsigned int flags);
};

struct BorderDelete : BorderDeletePrimary, BorderDeleteSecondary
{
    BorderDelete();
// @fnv 0x00d0bbd0
    virtual void* FUN_00d0bbd0(unsigned int flags);
};

BorderDelete::BorderDelete()
{}

// Moved from hkpbroadphaseborder_ehsc_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_00c936a0_World.h"
#include "fnv/decl/FUN_00cf2cb0.h"
#include "fnv/decl/fnv_00c93920__hkpWorldXc93920.h"
#include "fnv/decl/hkOwnerXd07de0.h"
#include "fnv/decl/hkpWorld_Listener.h"
void FUN_00d0b520(int);


struct hkVector4
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    const float& operator()(int i) const
    {
        return m_vComponents[i];
    }
};

class hkAabb
{
  public:
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};


namespace bpb {

class hkpPhantom;

struct hkpWorld
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    hkVector4 m_broadPhaseExtentsMin;
    hkVector4 m_broadPhaseExtentsMax;
};

class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    static void* operator new(size_t nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p);
};

struct hkpWorldDeletionListener
{
    virtual ~hkpWorldDeletionListener();
};
struct hkpPhantomOverlapListener
{
    virtual ~hkpPhantomOverlapListener();
};
struct hkpWorldPostSimulationListener
{
    virtual ~hkpWorldPostSimulationListener();
};

struct hkpTypedBroadPhaseHandle
{
    unsigned int m_iOwnerObjectOffset;
    char m_type;
    void setType(int type)
    {
        m_type = static_cast<char>(type);
    }
};

class hkpPhantom : public hkReferencedObject
{
  public:
    int m_pOwningWorld;
    int m_ulUserData;
    int m_pCollisionShape;
    int m_uiCollisionShapeKey;
    int m_pMotionState;
    int m_parent;
    int m_iOwnerOffset;
    hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
};

struct hkpAabbPhantom : hkpPhantom
{
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct hkpBroadPhaseBorder : hkReferencedObject,
                             hkpWorldDeletionListener,
                             hkpPhantomOverlapListener,
                             hkpWorldPostSimulationListener
{
    hkpBroadPhaseBorder(hkpWorld* world, int type, bool postponeAndSortCallbacks);
    __forceinline void createPhantom(hkpWorld* world, const hkAabb& aabb, int i)
    {
        hkpAabbPhantom* phantom =
            ((::bpb::hkpAabbPhantom *)(new ((void *)(static_cast<hkpAabbPhantom*>(hkReferencedObject::operator new(0xe0)))) ::FUN_00cf2cb0((const ::Aabb_cf2c &)(aabb), 0)));
        phantom->m_kBroadPhaseHandle.setType(3);
        reinterpret_cast<::hkOwnerXd07de0 *>((phantom))->FUN_00d07de0(this);
        m_kPhantoms[i] = phantom;
        reinterpret_cast<::FUN_00c936a0_World *>((world))->FUN_00c936a0((::hkpPhantom *)(phantom));
    }
    hkpWorld* m_pOwningWorld;
    hkpPhantom* m_kPhantoms[6];
    int m_type;
    bool m_bPostponeAndSortCallbacks;
    hkArray<void*> m_kPostponedCallbacks;
};

}

// @fnv 0x00d0b710
bpb::hkpBroadPhaseBorder::hkpBroadPhaseBorder(hkpWorld* world, int type, bool postponeAndSortCallbacks)
{
    m_type = type;
    m_pOwningWorld = world;
    m_bPostponeAndSortCallbacks = postponeAndSortCallbacks;
    reinterpret_cast<::FUN_00c90510_class *>(this)->FUN_00c90510();
    reinterpret_cast<::hkpWorld_Listener *>((m_pOwningWorld))->FUN_00c93a60(static_cast<hkpWorldDeletionListener*>(this));
    reinterpret_cast<::fnv_00c93920::hkpWorldXc93920 *>((m_pOwningWorld))->FUN_00c93920((::fnv_00c93920::hkpEntityListenerXc93920 *)(void *)(static_cast<hkpWorldPostSimulationListener*>(this)));

    hkVector4 wMin = m_pOwningWorld->m_broadPhaseExtentsMin;
    hkVector4 wMax = m_pOwningWorld->m_broadPhaseExtentsMax;

    hkAabb aabb;
    aabb.m_kMinimumCorner.set(wMax(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 0);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMin(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 1);

    aabb.m_kMinimumCorner.set(wMin(0), wMax(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 2);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMin(1), wMax(2));
    createPhantom(world, aabb, 3);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMax(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 4);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMin(2));
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMin(2));
    createPhantom(world, aabb, 5);
}
