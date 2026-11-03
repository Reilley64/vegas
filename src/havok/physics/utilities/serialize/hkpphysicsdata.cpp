
// src/havok/physics/utilities/serialize/hkpphysicsdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpphysicsdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <new>
#include <cstring>
#include "fnv/decl/BodyCollection.h"
#include "fnv/decl/Container64.h"
#include "fnv/decl/FUN_00c90b80.h"
#include "fnv/decl/FUN_00c9bff0_Class.h"
#include "fnv/decl/FUN_00d065e0.h"
#include "fnv/decl/MatchWorld.h"
#include "fnv/decl/S96_WorldShell.h"
#include "fnv/decl/Src_00c91c50.h"
#include "fnv/decl/SystemWorld.h"
#include "fnv/decl/WorldCtor.h"
#include "fnv/decl/fnv_00dcecc0__FUN_00dcecc0.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_00dcd000.h"
#include "fnv/symbols_00dce000.h"
#include "fnv/symbols_0102f000.h"
#include "havok/hkpPhysicsData.h"


struct FUN_00d4c000
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int Method(int a);
};

// @fnv 0x00d4c000
int FUN_00d4c000::Method(int a)
{
    for (int i = 0; i < m_10; i++)
    {
        int v = *reinterpret_cast<int*>(*(reinterpret_cast<char**>(m_0c) + i) + 0x38) & 0xfffffffe;
        if (v && !::fnv_00cb0fe0::CompareStringsCaseInsensitive((const char *)(v), (const char *)(a)))
            return m_0c[i];
    }
    return 0;
}

extern int DAT_010cf9a4;

struct FUN_00d4c220_s
{
    int* m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00d4c220_s();
};

// @fnv 0x00d4c220
FUN_00d4c220_s::FUN_00d4c220_s()
{
    m_06 = 1;
    m_00 = &DAT_010cf9a4;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0x80000000;
    m_08 = 0;
}


struct FUN_00d4c050_obj
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
    int m_10;
    int FindMatchingEntry(int a);
};

// Scans m_10 entries, checks each entry's sub-items via CompareStringsCaseInsensitive on the masked field at offset 0x74, and returns the first matching item or 0.
// @fnv 0x00d4c050
int FUN_00d4c050_obj::FindMatchingEntry(int a)
{
    for (int i = 0; i < m_10; ++i)
    {
        int* p = (int*)m_0c[i];
        for (int jItem = 0; jItem < p[3]; ++jItem)
        {
            int v = ((int*)p[2])[jItem];
            int m = *(int*)((char*)v + 0x74);
            if ((m & ~1) && !::fnv_00cb0fe0::CompareStringsCaseInsensitive((const char *)(m & ~1), (const char *)(a)))
                return v;
        }
    }
    return 0;
}



class hkThreadMemory
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pMemoryAllocator;

    __forceinline void* allocateChunk(int size) throw()
    {
        return m_pMemoryAllocator->blockAlloc(size);
    }
};


struct FUN_00d1df70
{
};

template <typename T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;
    __forceinline ReferenceCountedPointer() throw()
    {}
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00d1df70*)m_pRetainedObject)))->FUN_00c905b0();
        }
        m_pRetainedObject = 0;
    }
};

struct BoolResult
{
    char val;
    __forceinline BoolResult() throw()
    {}
};

class hkpPhysicsSystem : public hkReferencedObject
{
  public:
    virtual void vfunc1() throw();
    virtual void vfunc2() throw();
    virtual void vfunc3() throw();
    virtual BoolResult vfunc4() throw();
};

class __declspec(align(16)) FUN_00553540
{
  public:
    void* vtable;
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
    ReferenceCountedPointer<void> m_pCollisionFilter;  // 0x58
    ReferenceCountedPointer<void> m_pConvexListCollisionFilter;  // 0x5c
    int unk60;
    int unk64;
    int unk68;
    ReferenceCountedPointer<void> m_pMemoryWatchDog;  // 0x6c
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;

    __forceinline FUN_00553540() throw()
    {
        new ((void *)this) ::FUN_00c90b80();
    }
    __forceinline ~FUN_00553540() throw()
    {
        vtable = &DAT_0102f0ec;
    }
};

class hkpWorld
{
  public:
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
    void* m_pDispatcher;  // 0x80
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;

    void* operator new(size_t size) throw()
    {
        void* p = ((hkThreadMemory*)&hkMemoryRouter::getInstance())->allocateChunk(size);
        ((unsigned short*)p)[2] = (unsigned short)size;
        return p;
    }
    hkpWorld* FUN_00c95a80(const FUN_00553540* info, unsigned int version = 0x111d4) throw();
    __forceinline hkpWorld(const FUN_00553540* info) throw()
    {
        reinterpret_cast<::WorldCtor *>(this)->FUN_00c95a80((::WorldInfoCtor *)(info), 0x111d4);
    }
};

struct ContactOptions
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    int m_04;
    char m_08;
    char m_09;
    char m_0a;
    char m_0b;
};

struct PhysicsDataExt : public hkpPhysicsData
{
    hkpWorld* CreateWorld(char bRegisterWithMemoryManager) throw();
};

// @fnv 0x00d4c0c0
hkpWorld* PhysicsDataExt::CreateWorld(char bRegisterWithMemoryManager) throw()
{
    FUN_00553540 defaultCinfo;
    hkpWorld* world;
    if (this->m_pWorldCinfo == 0)
    {
        world = ((hkpWorld*)hkpWorld::operator new(0x350))->FUN_00c95a80(&defaultCinfo);
    }
    else
    {
        world = ((hkpWorld*)hkpWorld::operator new(0x350))->FUN_00c95a80((FUN_00553540*)this->m_pWorldCinfo);
    }

    if (bRegisterWithMemoryManager)
    {
        ::InitializeWorld((::WorldCBFD *)(world->m_pDispatcher));
    }

    for (int i = 0; i < this->m_kPhysicsSystems.m_iElementCount; ++i)
    {
        reinterpret_cast<::SystemWorld *>((world))->FUN_00c97f80((::PhysicsSystem *)(this->m_kPhysicsSystems.m_data[i]));
        if (this->m_kPhysicsSystems.m_data[i]->vfunc4().val)
        {
            ContactOptions opts;
            opts.m_00 = 0;
            opts.m_01 = 0;
            opts.m_04 = 0;
            opts.m_08 = 1;
            opts.m_09 = 1;
            opts.m_0a = 0;
            ::RunWithLocalContext((int)(&opts), (int)(this->m_kPhysicsSystems.m_data[i]), (int)(world));
        }
    }

    if (this->m_pWorldCinfo && ((FUN_00553540*)this->m_pWorldCinfo)->m_pCollisionFilter.m_pRetainedObject)
    {
        reinterpret_cast<::S96_WorldShell *>((world))->FUN_00c96ff0(0, 1);
    }

    return world;
}

namespace fnv_00d4c8e0 {


class FUN_00dcecc0
{
  public:
    virtual ~FUN_00dcecc0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, static_cast<FUN_00dcecc0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00dcecc0* Destroy(unsigned int uiFlags) throw();
};

// Runs the destructor and, when bit 0 of uiFlags is set, frees the object through the heap allocator, then returns this.
// @fnv 0x00d4c8e0
FUN_00dcecc0* FUN_00dcecc0::Destroy(unsigned int uiFlags) throw()
{
    reinterpret_cast<::fnv_00dcecc0::FUN_00dcecc0 *>((this))->fnv_00dcecc0::FUN_00dcecc0::~FUN_00dcecc0();
    if (uiFlags & 1)
        FUN_00dcecc0::operator delete(this);
    return this;
}
}  // namespace fnv_00d4c8e0

extern int DAT_010d07f4;

struct D4C2Place
{
};
inline void* operator new(size_t, void* p, D4C2Place)
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, D4C2Place)
{}

struct BigType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
};

struct ArrayField
{
    int m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ArrayField() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct SmallType
{
    int m_00;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    unsigned char m_40;
    unsigned char m_41;
    unsigned char m_42;
    unsigned char m_43;
    ArrayField m_ppData;
public:
    void FUN_00d065e0(void);
};

struct AllocType
{
    virtual void vf00(void);
    virtual void* vf04(int);
};
struct HolderType
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    AllocType* m_10;
};
struct ClientType
{
};
struct ArrayType
{
    SmallType** m_data;
    int m_iElementCount;
    int m_cap;
};
struct HostType
{
    int m_00;
    int m_04;
    void* m_08;
    ArrayType m_0c;
    void FUN_00d4c2d0(ClientType*, unsigned char);
};

// Ensures m_08 is allocated, registers client and m_0c, and when value is set allocates a SmallType, calls ProcessCollisionRecords, and appends it to m_0c.
// @fnv 0x00d4c2d0
void HostType::FUN_00d4c2d0(ClientType* client, unsigned char ubFlag)
{
    if (m_08 == 0)
    {
        HolderType* holder = (HolderType*)&hkMemoryRouter::getInstance();
        BigType* big = (BigType*)holder->m_10->vf04(0xF0);
        big->m_04 = 0xF0;
        m_08 = ((void *)(new ((void *)(big)) ::FUN_00c90b80()));
    }

    reinterpret_cast<::Src_00c91c50 *>((client))->FUN_00c91c50((::Dst_00c91c50 *)(m_08));
    ArrayType* array = &m_0c;
    reinterpret_cast<::MatchWorld *>((client))->AddPhysicsSystem((::hkArrayXc937a0< ::FUN_00d065e0 *> *)(array));

    if (ubFlag != 0)
    {
        struct Local
        {
            unsigned char m_flag;
            int m_uiFilterValue;
        } local;

        local.m_flag = 0;
        local.m_uiFilterValue = 0;

        HolderType* holder = (HolderType*)&hkMemoryRouter::getInstance();
        SmallType* small = (SmallType*)holder->m_10->vf04(0x50);
        small->m_04 = 0x50;
        new ((void *)(small)) ::FUN_00d065e0();

        small->m_00 = (int)&DAT_010d07f4;
        new (&small->m_ppData, D4C2Place()) ArrayField();

        ::ProcessCollisionRecords(&local, (::S_00dcda40_World *)(client), (::S_00dcdd80_Listener *)(small));

        small->m_40 = 0;

        holder = (HolderType*)&hkMemoryRouter::getInstance();
        if (array->m_iElementCount == (array->m_cap & 0x3fffffff))
        {
            ::ResizeAudioStream((::AudioAllocator *)(holder->m_10), (::AudioStream *)(array), 4);
        }

        new (array->m_data + array->m_iElementCount, D4C2Place()) SmallType*(small);
        array->m_iElementCount++;
    }
}

struct Value
{
};
struct Owner
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
};
struct Entity
{
    int unk00;
    int unk04;
    int** m_08;
    int m_0c;
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
    unsigned char m_40;
};
struct OwnerArg
{
    Owner* p;
};
struct ValueArg
{
    Value* p;
};
template <class T> __forceinline int findValue(T* self, Value* value)
{
    int count = ((volatile T*)self)->m_0c;
    for (int i = 0; i < count; ++i)
    {
        if (self->m_08[i] == (int*)value)
            return i;
    }
    return -1;
}
typedef int Owner::*MemberPtr;
// If value is in owner's list but not entity's, sets entity->m_40, calls entity->AddShape(value) and owner->FUN_00d06130 with the owner index.
// @fnv 0x00d4bf70
static __declspec(noinline) void FUN_00d4bf70(Owner* owner, Entity* volatile apEntity, MemberPtr valueArg)
{
    Entity* entity = apEntity;
    Value* pValue;
    memcpy(&pValue, &valueArg, 4);
    Value* value = pValue;
    int ownerIndex = findValue(owner, value);
    int entityIndex = findValue(entity, value);
    if (entityIndex == -1 && ownerIndex != -1)
    {
        entity->m_40 = entity->m_40 || (*(::BoolResult *)(reinterpret_cast<::FUN_00c9bff0_Class *>((value))->FUN_00c9bff0({}))).val;
        reinterpret_cast<::Container64 *>((entity))->AddShape((::Shape64 *)((int)value));
        reinterpret_cast<::BodyCollection *>((owner))->FUN_00d06130(ownerIndex);
    }
}
Owner* volatile probeOwner;
Value* volatile probeValue;
Entity* volatile probeEntity;
void probeCaller()
{
    OwnerArg o = {probeOwner};
    ValueArg v = {probeValue};
    FUN_00d4bf70(o.p, probeEntity, *(MemberPtr*)&v.p);
}

namespace fnv_00d4c250 {
struct hkRefD4C
{
};

template <class T> class hkArrayD4C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD4C() throw()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkBaseObjectD4C
{
  public:
    virtual ~hkBaseObjectD4C()
    {}
};

class hkReferencedObjectD4C : public hkBaseObjectD4C
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d4c250 : public hkReferencedObjectD4C
{
  public:
    hkRefD4C* m_pCollisionShape;
    hkArrayD4C<hkRefD4C*> m_children;

    virtual ~FUN_00d4c250();
};

// Destructor: calls FUN_00c905b0 on m_pCollisionShape if set and on each element of m_children.
// @fnv 0x00d4c250
FUN_00d4c250::~FUN_00d4c250()
{
    if (m_pCollisionShape)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pCollisionShape))->FUN_00c905b0();
    for (int i = 0; i < m_children.m_iElementCount; i++)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_children.m_data[i]))->FUN_00c905b0();
}
}  // namespace fnv_00d4c250

// Moved from hkpphysicsdata_ehsc_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00d061b0_Class.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/fnv_00d061f0__FUN_00d061f0_Class.h"
#include "fnv/decl/hkOwnerD064.h"
#include "fnv/decl/hkOwnerXd06540.h"
#include "fnv/decl/hkOwnerXd06590.h"
static void FUN_00d4bf70(Owner* owner, Entity* volatile entityArg, MemberPtr valueArg);
void probeCaller();

struct SplitPlace
{
};
inline void* operator new(size_t, void* p, SplitPlace)
{
    return p;
}
inline void operator delete(void*, void*, SplitPlace)
{}
struct SplitRef
{
    virtual ~SplitRef();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class SplitBool
{
    char value;

  public:
    inline SplitBool()
    {}
    inline SplitBool(bool b)
    {
        value = (char)b;
    }
    inline operator bool() const
    {
        return value != 0;
    }
    inline SplitBool& operator=(bool b)
    {
        value = (char)b;
        return *this;
    }
    inline SplitBool operator==(bool b) const
    {
        return (int)value == (int)b;
    }
    inline SplitBool operator!=(bool b) const
    {
        return (int)value != (int)b;
    }
};

struct SplitAllocator
{
    virtual void vf00();
    virtual void* alloc(int);
    virtual void vf08();
    virtual void vf0c();
    virtual void freeBuffer(void*, int);
    template <class T> inline void freeItems(void* p, int count)
    {
        freeBuffer(p, count * sizeof(T));
    }
};
struct SplitRouter
{
    int unk00, unk04, unk08, unk0c;
    SplitAllocator* heap;
    inline SplitAllocator& allocator()
    {
        return *heap;
    }
};
struct SplitHeap
{
    inline SplitAllocator& get(const void*)
    {
        return ((SplitRouter*)&hkMemoryRouter::getInstance())->allocator();
    }
};
template <class T> static __forceinline void copyItems(T* dest, int count, const T& item)
{
    for (int i = 0; i < count; ++i)
        dest[i] = item;
}
template <class T> struct SplitArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline SplitArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline void clearWith(SplitAllocator& alloc)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            alloc.freeItems<T>(data, getCapacity());
        data = 0;
        capacity = 0x80000000;
    }
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline int indexOf(const T& item, int start = 0, int end = -1) const
    {
        if (end < 0)
            end = size;
        for (int i = start; i < end; ++i)
            if (data[i] == item)
                return i;
        return -1;
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline void appendWith(SplitAllocator& alloc, const T& item)
    {
        if (size == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(T));
        copyItems(data + size, 1, item);
        ++size;
    }
};
template <class T> struct SplitArray : SplitArrayBase<T>
{
    __forceinline SplitArray()
    {}
    __forceinline ~SplitArray()
    {
        clearWith(SplitHeap().get(this));
    }
    __forceinline void AddBack(const T& item)
    {
        appendWith(SplitHeap().get(this), item);
    }
};
struct SplitName
{
    char* text;
    __forceinline SplitName& operator=(const char* str)
    {
        return (*(::SplitName *)(reinterpret_cast<::SStringPtr *>(this)->FUN_00cb0c10(str)));
    }
};
struct SplitBody;
struct SplitEntity;
struct SplitConstraint
{
    int unk00, unk04, unk08, unk0c, unk10;
    SplitEntity* bodyA;
    SplitEntity* bodyB;
    __forceinline SplitEntity* getEntityA() const
    {
        return bodyA;
    }
    __forceinline SplitEntity* getEntityB() const
    {
        return bodyB;
    }
    __forceinline SplitEntity* getOtherEntity(const SplitEntity* item) const
    {
        return (SplitEntity*)((unsigned int)bodyA ^ (unsigned int)bodyB ^ (unsigned int)item);
    }
};
struct SplitAction
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void GetEntities(SplitArray<SplitEntity*>&);
};
struct SplitSystem : SplitRef
{
    virtual ~SplitSystem() throw();
    SplitArray<SplitBody*> bodies;
    SplitArray<SplitConstraint*> constraints;
    SplitArray<SplitAction*> actions;
    SplitArray<void*> phantoms;
    SplitName name;
    unsigned long userData;
    SplitBool active;
    static __forceinline void* operator new(size_t bytes)
    {
        SplitRef* p = (SplitRef*)((SplitRouter*)&hkMemoryRouter::getInstance())->allocator().alloc(bytes);
        p->m_usMemSizeAndFlags = (unsigned short)bytes;
        return p;
    }

    __forceinline const SplitArray<SplitBody*>& getRigidBodies() const
    {
        return bodies;
    }
    __forceinline const SplitArray<SplitConstraint*>& getConstraints() const
    {
        return constraints;
    }
    __forceinline const SplitArray<SplitAction*>& getActions() const
    {
        return actions;
    }
    __forceinline const SplitArray<void*>& getPhantomArray() const
    {
        return phantoms;
    }
    __forceinline void SetParentObject(const char* str)
    {
        name = str;
    }
    __forceinline unsigned long getUserData() const
    {
        return userData;
    }
    __forceinline void setUserData(unsigned long p)
    {
        userData = p;
    }
    __forceinline SplitBool isActive() const
    {
        return active;
    }
    __forceinline void setActive(SplitBool b)
    {
        active = b;
    }
};
struct SplitOutput
{
    SplitSystem* m_pFirstSplitSystem;
    SplitSystem* m_pSecondSplitSystem;
    SplitSystem* m_pThirdSplitSystem;
    SplitSystem* m_kPhantoms;
    SplitArray<SplitSystem*> m_kSplitSystemArray;
};

struct FUN_00d065e0 : SplitSystem
{
    FUN_00d065e0();
};

enum SplitMotionKind
{
    SplitMotionInvalid,
    SplitMotionDynamic,
    SplitMotionSphere,
    SplitMotionBox,
    SplitMotionKeyframed,
    SplitMotionFixed
};
class SplitMotionByte
{
    unsigned char value;

  public:
    inline SplitMotionByte()
    {}
    inline SplitMotionByte(SplitMotionKind k)
    {
        value = (unsigned char)k;
    }
    inline operator SplitMotionKind() const
    {
        return (SplitMotionKind)value;
    }
    inline void operator=(SplitMotionKind k)
    {
        value = (unsigned char)k;
    }
    inline SplitBool operator==(SplitMotionKind k) const
    {
        return value == (unsigned char)k;
    }
    inline SplitBool operator!=(SplitMotionKind k) const
    {
        return value != (unsigned char)k;
    }
};
struct SplitMotion
{
    int unk00, unk04;
    SplitMotionByte type;
    inline SplitMotionKind getType() const
    {
        return type;
    }
};
struct SplitEntity
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    void* island;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    SplitMotion motion;
    inline SplitBool isFixed() const
    {
        return motion.type == SplitMotionFixed;
    }
    __forceinline void* GetSimulationIsland() const
    {
        return island;
    }
};
struct SplitBody : SplitEntity
{
    inline SplitMotion* getRigidMotion() const
    {
        return const_cast<SplitMotion*>(&motion);
    }
    inline SplitMotionKind getMotionType() const
    {
        return getRigidMotion()->getType();
    }
};

static __forceinline SplitSystem* makeSystem()
{
    return new FUN_00d065e0;
}
typedef int SplitSystem::*MoveMember;
static __declspec(noinline) void FUN_00d4bf70(SplitSystem* from, SplitSystem* volatile toArg, MoveMember encoded)
{
    SplitSystem* to = toArg;
    SplitBody* body;
    memcpy(&body, &encoded, 4);
    int fromIndex = from->getRigidBodies().indexOf(body);
    int toIndex = to->getRigidBodies().indexOf(body);
    if (toIndex == -1 && fromIndex != -1)
    {
        to->setActive(to->isActive() || (*(::SplitBool *)(reinterpret_cast<::FUN_00c9bff0_Class *>((void *)(body))->FUN_00c9bff0({}))));
        reinterpret_cast<::Container64 *>((to))->AddShape((::Shape64 *)(body));
        reinterpret_cast<::BodyCollection *>((from))->FUN_00d06130(fromIndex);
    }
}
static __forceinline void moveConnected(SplitSystem* from, SplitSystem* to, SplitEntity* item)
{
    MoveMember encoded;
    memcpy(&encoded, &item, 4);
    FUN_00d4bf70(from, to, encoded);
}

// @fnv 0x00d4c3b0
void FUN_00d4c3b0(const SplitSystem* source, SplitOutput& output)
{
    SplitSystem* remaining = makeSystem();
    for (int i = 0; i < source->getRigidBodies().GetLogicalSize(); ++i)
        reinterpret_cast<::Container64 *>((remaining))->AddShape((::Shape64 *)(source->getRigidBodies()[i]));
    for (int i = 0; i < source->getActions().GetLogicalSize(); ++i)
        reinterpret_cast<::hkOwnerXd06590 *>((remaining))->FUN_00d06590((::hkShapeXd06590 *)(source->getActions()[i]));
    for (int i = 0; i < source->getConstraints().GetLogicalSize(); ++i)
        reinterpret_cast<::hkOwnerXd06540 *>((remaining))->FUN_00d06540((::hkShapeXd06540 *)(source->getConstraints()[i]));
    for (int i = 0; i < source->getPhantomArray().GetLogicalSize(); ++i)
        reinterpret_cast<::hkOwnerD064 *>((remaining))->FUN_00d064f0((::hkShapeD064 *)(source->getPhantomArray()[i]));

    const SplitArray<SplitBody*>& bodies = remaining->getRigidBodies();
    SplitSystem* moving = makeSystem();
    moving->SetParentObject("Unconstrained Rigid Bodies");
    moving->setUserData(remaining->getUserData());
    moving->setActive(false);
    SplitSystem* fixed = makeSystem();
    fixed->SetParentObject("Fixed Rigid Bodies");
    fixed->setUserData(remaining->getUserData());
    fixed->setActive(false);
    SplitSystem* keyframed = makeSystem();
    keyframed->SetParentObject("Keyframed Rigid Bodies");
    keyframed->setUserData(remaining->getUserData());
    keyframed->setActive(false);

    const SplitArray<SplitConstraint*>& constraints = remaining->getConstraints();
    const SplitArray<SplitAction*>& actions = remaining->getActions();
    while (bodies.GetLogicalSize() > 0)
    {
        SplitSystem* component = makeSystem();
        component->SetParentObject("Constrained System");
        component->setUserData(remaining->getUserData());
        component->setActive((*(::SplitBool *)(reinterpret_cast<::FUN_00c9bff0_Class *>((void *)(bodies[0]))->FUN_00c9bff0({}))));
        reinterpret_cast<::Container64 *>((component))->AddShape((::Shape64 *)(bodies[0]));
        reinterpret_cast<::BodyCollection *>((remaining))->FUN_00d06130(0);
        bool changed = true;
        while (changed)
        {
            changed = false;
            for (int j = 0; j < component->getRigidBodies().GetLogicalSize(); ++j)
            {
                SplitBody* current = component->getRigidBodies()[j];
                int i = 0;
                while (i < constraints.GetLogicalSize())
                {
                    if (constraints[i]->getEntityA() == current || constraints[i]->getEntityB() == current)
                    {
                        changed = true;
                        reinterpret_cast<::hkOwnerXd06540 *>((component))->FUN_00d06540((::hkShapeXd06540 *)(constraints[i]));
                        SplitEntity* other = constraints[i]->getOtherEntity(current);
                        if (other && !other->isFixed())
                            moveConnected(remaining, component, other);
                        reinterpret_cast<::FUN_00d061b0_Class *>((remaining))->FUN_00d061b0(i);
                    }
                    else
                        ++i;
                }
                i = 0;
                while (i < actions.GetLogicalSize())
                {
                    SplitArray<SplitEntity*> participants;
                    actions[i]->GetEntities(participants);
                    bool moved = false;
                    for (int k = 0; k < participants.GetLogicalSize(); ++k)
                    {
                        if (participants[k] == current)
                        {
                            changed = true;
                            reinterpret_cast<::hkOwnerXd06590 *>((component))->FUN_00d06590((::hkShapeXd06590 *)(actions[i]));
                            reinterpret_cast<::fnv_00d061f0::FUN_00d061f0_Class *>((remaining))->FUN_00d061f0(i);
                            moved = true;
                            for (int l = 0; l < participants.GetLogicalSize(); ++l)
                            {
                                if (participants[l] != current)
                                    if (!participants[l]->isFixed())
                                        moveConnected(remaining, component, participants[l]);
                            }
                        }
                    }
                    if (!moved)
                        ++i;
                }
            }
        }
        if (component->getConstraints().GetLogicalSize() == 0 && component->getActions().GetLogicalSize() == 0)
        {
            SplitBody* body = component->getRigidBodies()[0];
            bool active = !body->GetSimulationIsland() || (*(::SplitBool *)(reinterpret_cast<::FUN_00c9bff0_Class *>((void *)(body))->FUN_00c9bff0({})));
            if (body->getMotionType() == 4)
            {
                keyframed->setActive(keyframed->isActive() || active);
                reinterpret_cast<::Container64 *>((keyframed))->AddShape((::Shape64 *)(body));
            }
            else if (body->getMotionType() == 5)
                reinterpret_cast<::Container64 *>((fixed))->AddShape((::Shape64 *)(body));
            else
            {
                moving->setActive(moving->isActive() || active);
                reinterpret_cast<::Container64 *>((moving))->AddShape((::Shape64 *)(body));
            }
            delete component;
        }
        else
            output.m_kSplitSystemArray.AddBack(component);
    }
    if (keyframed->getRigidBodies().GetLogicalSize())
        output.m_pSecondSplitSystem = keyframed;
    else
    {
        delete keyframed;
        output.m_pSecondSplitSystem = 0;
    }
    if (fixed->getRigidBodies().GetLogicalSize())
        output.m_pFirstSplitSystem = fixed;
    else
    {
        delete fixed;
        output.m_pFirstSplitSystem = 0;
    }
    if (moving->getRigidBodies().GetLogicalSize())
        output.m_pThirdSplitSystem = moving;
    else
    {
        delete moving;
        output.m_pThirdSplitSystem = 0;
    }
    const SplitArray<void*>& phantoms = remaining->getPhantomArray();
    if (phantoms.GetLogicalSize() > 0)
    {
        SplitSystem* phantomGroup = makeSystem();
        phantomGroup->SetParentObject("Phantoms");
        phantomGroup->setUserData(remaining->getUserData());
        output.m_kPhantoms = phantomGroup;
        for (int i = 0; i < phantoms.GetLogicalSize(); ++i)
            reinterpret_cast<::hkOwnerD064 *>((phantomGroup))->FUN_00d064f0((::hkShapeD064 *)(phantoms[i]));
    }
    else
        output.m_kPhantoms = 0;
    delete remaining;
}
