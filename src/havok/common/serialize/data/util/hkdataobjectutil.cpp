
// src/havok/common/serialize/data/util/hkdataobjectutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/util/hkdataobjectutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/AudioHandle.h"
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/ClassMember_d869.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/DBA7F0Ref.h"
#include "fnv/decl/DBABE0Binding.h"
#include "fnv/decl/DBADC0Binding.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00d46f00_s.h"
#include "fnv/decl/FUN_00d46f70_cls.h"
#include "fnv/decl/FUN_00d46f80_class.h"
#include "fnv/decl/FUN_00d5f640_cls.h"
#include "fnv/decl/FUN_00dba6a0_cls.h"
#include "fnv/decl/FUN_00dba870_cls.h"
#include "fnv/decl/FUN_00dba980_cls.h"
#include "fnv/decl/FUN_00dba9d0_cls.h"
#include "fnv/decl/FUN_00dbaa30_cls.h"
#include "fnv/decl/FUN_00dbaa50_cls.h"
#include "fnv/decl/FUN_00dbaab0_cls.h"
#include "fnv/decl/FUN_00dbab50.h"
#include "fnv/decl/FUN_00dbab70_cls.h"
#include "fnv/decl/FUN_00dbaca0_cls.h"
#include "fnv/decl/FUN_00dbad00_cls.h"
#include "fnv/decl/FUN_00dbad60_cls.h"
#include "fnv/decl/FUN_00dbaea0_cls.h"
#include "fnv/decl/FUN_00e04eb0_class.h"
#include "fnv/decl/FUN_00e05100_cls.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/FnvCpu_FUN_00d470d0_CpuObject.h"
#include "fnv/decl/HkClassNode.h"
#include "fnv/decl/OwnerD869.h"
#include "fnv/decl/ReflectObj.h"
#include "fnv/decl/S00e05700_Class.h"
#include "fnv/decl/S_00dba990.h"
#include "fnv/decl/S_00dbab30_Ref.h"
#include "fnv/decl/S_00dbaed0_Obj.h"
#include "fnv/decl/S_00dbafe0.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/Struct_d86920.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/decl/fnv_00dba920__Target.h"
#include "fnv/decl/fnv_00dbad20__AudioHandle.h"
#include "fnv/decl/fnv_00dbada0__Wrapper.h"
#include "fnv/decl/fnv_00e04ee0__FUN_00e04ee0_class.h"
#include "fnv/decl/hkClassD47120.h"
#include "fnv/decl/hkClassMember_FUN_00d86960.h"
#include "fnv/decl/hkMapBaseCB1F.h"
#include "fnv/decl/hkMatrix4CD60.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00dba000.h"
#include "fnv/symbols_00dc1000.h"
#include "fnv/symbols_00dc3000.h"
#include "fnv/symbols_01268000.h"
struct FUN_00dc35e0_class
{
    int FUN_00dc35e0();
};

// @fnv 0x00dc35e0
int FUN_00dc35e0_class::FUN_00dc35e0()
{
    int count = *(int*)((char*)this + 8);
    int result = 0;
    if (count >= 0)
    {
        void* node = *(void**)this;
        while (result <= count && *(int*)node == -1)
        {
            ++result;
            node = (char*)node + 0xc;
        }
    }
    return result;
}

struct DC3980Pair
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
};

struct DC3980Map
{
    DC3980Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void Reset();
};

// @fnv 0x00dc3980
void DC3980Map::Reset()
{
    int capacity = m_iPairCount + 1;
    for (int i = 0; i < capacity; i++)
        m_kPrimitiveElement[i].m_key = -1;
    m_iCapacityFlags &= 0x80000000;
}

struct Callback
{
    virtual void unk00();
    virtual void unk04();
    virtual void update(void* entries, int bytes);
};
struct FUN_00dc3b60_class
{
    void** entries;
    unsigned int flags;
    int count;
    void NotifyCallback(Callback* callback);
};
struct S_00dc3b90_Pair
{
    unsigned __int64 key;
    unsigned __int64 val;
};

struct S_00dc3b90
{
    S_00dc3b90_Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int LookupValue(unsigned __int64 key, unsigned __int64* out);
};

struct DC3CC0Allocator;

struct DC3CC0Map
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void FUN_00dc3cc0(DC3CC0Allocator& alloc, int numElements);
};

struct S_00dc3ce0_Allocator
{
    int unk0;
};

struct S_00dc3ce0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dc3ce0_Allocator* m_pStreamAllocator;
    static S_00dc3ce0_Router& FUN_00c85750();
    S_00dc3ce0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};


struct S_00dc3ce0_Entry
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    S_00dc3ce0_Entry(intptr_t a, int b, int c) : m_kPointA(a), m_kPointB(b), m_iThirdValue(c)
    {}
};


struct S_00dc3ce0_Array
{
    S_00dc3ce0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(S_00dc3ce0_Allocator& alloc, const S_00dc3ce0_Entry& e)
    {
        if (m_iElementCount == getCapacity())
        {
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(S_00dc3ce0_Entry));
        }
        new (m_data + m_iElementCount) S_00dc3ce0_Entry(e);
        m_iElementCount++;
    }
    __forceinline void AddBack(const S_00dc3ce0_Entry& e)
    {
        AddBack(S_00dc3ce0_Router::FUN_00c85750().heap(), e);
    }
};

struct S_00dc3ce0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00dc3ce0_Array m_entries;
    void AddEntry(intptr_t a, int b, int c);
};

// Appends a new entry constructed from the three arguments to m_entries.
// @fnv 0x00dc3ce0
void S_00dc3ce0::AddEntry(intptr_t aiFirst, int aiSecond, int aiThird)
{
    m_entries.AddBack(S_00dc3ce0_Entry(aiFirst, aiSecond, aiThird));
}

struct Temp
{
    int f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11;
    Temp* Construct(void* a2, int one, void* a1, void* a3) throw();
    ~Temp() throw();
    int FUN_00dc4710() throw();
};

// @fnv 0x00dc32c0
intptr_t __cdecl FUN_00dc32c0(void* a1, void* a2, void* a3)
{
    Temp temp;
    return temp.Construct(a2, 1, a1, a3)->FUN_00dc4710();
}

struct GlobalObj_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c();
    virtual intptr_t v10();
};


// Calls v0c on DAT_01268b08, then passes a1, obj->v10() and that result to FUN_00dc32c0 and returns its result.
// @fnv 0x00dc3500
intptr_t __cdecl FUN_00dc3500(intptr_t a1)
{
    GlobalObj_cls* obj = (*reinterpret_cast<::GlobalObj_cls * *>(&::DAT_01268b08));
    intptr_t r1 = (*reinterpret_cast<::GlobalObj_cls * *>(&::DAT_01268b08))->v0c();
    return ::FUN_00dc32c0((void *)(a1), (void *)(obj->v10()), (void *)(r1));
}

namespace fnv_00dc3530 {


struct SvcHolder_b0466
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual int unk10();
};

// @fnv 0x00dc3530
intptr_t __cdecl FUN_00dc3530(intptr_t a1)
{
    SvcHolder_b0466* svc = (SvcHolder_b0466*)::DAT_01268b08;
    intptr_t r = svc->unk10();
    return ((intptr_t)(::FUN_00dc3300((::S_PH *)(a1), (::S_Dom *)(r))));
}
}  // namespace fnv_00dc3530

struct Handle
{
    void* p;
};

struct X
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int V7(Handle* other);
};

struct Slt
{
    void* m0;
    void* m4;
    int m8;
    void FUN_00dc3bd0(void*, int);
};

struct Rec
{
    Handle f1;
    X* f2;
    Slt slt;
    void CloneObject(Handle* h, int v);
};

struct CT
{
    Handle f1;
    Handle f2;
};

void* __cdecl FUN_00c85750();

// @fnv 0x00dc3550
int FUN_00dc3550(CT ct)
{
    Rec home;
    home.f1 = ct.f1;
    home.f2 = (X*)ct.f2.p;
    home.slt.m0 = 0;
    home.slt.m4 = 0;
    home.slt.m8 = -1;
    void* mgr = FUN_00c85750();
    home.slt.FUN_00dc3bd0(((void**)mgr)[4], 0);
    (void)home.f1.p;  // keep
    home.CloneObject(&ct.f1, home.f2->V7(&ct.f2));
    reinterpret_cast<::DBA7F0Ref *>(&(ct.f1))->FUN_00dba7f0();
    reinterpret_cast<::DBA7F0Ref *>(&(ct.f2))->FUN_00dba7f0();
    mgr = FUN_00c85750();
    reinterpret_cast<::FUN_00d5f640_cls *>(&(home.slt))->FreeStorage((::Deallocator *)(((void**)mgr)[4]));
    return 0;
}

struct DC3600Allocator;

struct DC3600Key
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct DC3600MapOperations
{
    static unsigned hash(const DC3600Key& key, unsigned mod)
    {
        return (key.m_ucLowNibble >> 4) * 2654435761U & mod;
    }
    static bool isValid(const DC3600Key& key)
    {
        return key.m_ucLowNibble != 0xffffffff;
    }
    static bool equal(const DC3600Key& key0, const DC3600Key& key1)
    {
        return key0.m_ucLowNibble == key1.m_ucLowNibble && key0.m_ucHighNibble == key1.m_ucHighNibble;
    }
};

struct DC3600Pair
{
    DC3600Key key;
    intptr_t val;
};

struct DC3600Map
{
    DC3600Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int InsertKeyValue(DC3600Allocator& alloc, DC3600Key key, intptr_t val);
};

struct FUN_00dc36b0_cls
{
    struct HashEntry
    {
        unsigned int key0;
        unsigned int key1;
        unsigned int value;
    };

    HashEntry* m_pEntries;
    unsigned int m_u04;
    unsigned int m_uMask;

    uintptr_t Lookup(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault);
};

// Probes the hash table for the entry matching aKey0 and aKey1, returning its value or aDefault when not found.
// @fnv 0x00dc36b0
uintptr_t FUN_00dc36b0_cls::Lookup(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault)
{
    unsigned int mask = m_uMask;
    if ((int)mask > 0)
    {
        unsigned int idx = ((aKey0 >> 4) * 0x9e3779b1u) & mask;
        if (m_pEntries[idx].key0 != 0xffffffffu)
        {
            for (;;)
            {
                HashEntry* e = &m_pEntries[idx];
                if (e->key0 == aKey0 && e->key1 == aKey1)
                {
                    return m_pEntries[idx].value;
                }
                idx = (idx + 1) & mask;
                if (m_pEntries[idx].key0 == 0xffffffffu)
                {
                    break;
                }
            }
        }
    }
    return aDefault;
}

struct Wrapper
{
    void FUN_00dc3bd0(intptr_t first, int count);
};
struct DC3BF0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct DC3BF0Key
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

struct DC3BF0Pair
{
    DC3BF0Key key;
    int val;
};

struct DC3BF0Map
{
    DC3BF0Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int insert(DC3BF0Allocator& alloc, DC3BF0Key key, int val);
    void FUN_00dc3bf0(DC3BF0Allocator& alloc, int newcap);
};
// @fnv 0x00dc3cc0
void DC3CC0Map::FUN_00dc3cc0(DC3CC0Allocator& alloc, int numElements)
{
    int minCap = numElements * 2;
    int cap = 8;
    while (cap < minCap)
        cap *= 2;
    reinterpret_cast<::DC3BF0Map *>(this)->FUN_00dc3bf0((::DC3BF0Allocator &)(alloc), cap);
}
// Grows the table if needed, probes for the key, stores key and value, and returns whether the key was new.
// @fnv 0x00dc3600
int DC3600Map::InsertKeyValue(DC3600Allocator& alloc, DC3600Key key, intptr_t val)
{
    {
        int iCount = m_iCapacityFlags & 0x7fffffff;
        if ((iCount + iCount) > m_iPairCount)
            reinterpret_cast<::DC3BF0Map *>(this)->FUN_00dc3bf0((::DC3BF0Allocator &)(alloc), m_iPairCount + m_iPairCount + 2);
    }

    unsigned i;
    int isNewKey = true;
    for (i = DC3600MapOperations::hash(key, m_iPairCount); DC3600MapOperations::isValid(m_kPrimitiveElement[i].key);
         i = (i + 1) & m_iPairCount)
    {
        if (DC3600MapOperations::equal(m_kPrimitiveElement[i].key, key))
        {
            isNewKey = false;
            break;
        }
    }

    m_iCapacityFlags += isNewKey;

    m_kPrimitiveElement[i].key = key;
    m_kPrimitiveElement[i].val = val;
    return isNewKey;
}

// Reallocates the map's pair array to at least 8 slots, rehashes existing entries via insert, and frees the old array unless the high flag bit is set.
// @fnv 0x00dc3bf0
void DC3BF0Map::FUN_00dc3bf0(DC3BF0Allocator& alloc, int aiNewCapacity)
{
    aiNewCapacity = (aiNewCapacity > 8) ? aiNewCapacity : 8;
    int iKeepOldBuffer = m_iCapacityFlags & 0x80000000;
    int iOldCapacity = m_iPairCount + 1;
    DC3BF0Pair* pOldPairs = m_kPrimitiveElement;
    m_kPrimitiveElement = static_cast<DC3BF0Pair*>(alloc.AllocateMemoryBlock(sizeof(DC3BF0Pair) * aiNewCapacity));
    for (int i = 0; i < aiNewCapacity; i++)
        m_kPrimitiveElement[i].key.m_ucLowNibble = 0xffffffff;
    m_iCapacityFlags = 0;
    m_iPairCount = aiNewCapacity - 1;

    for (int i = 0; i < iOldCapacity; i++)
    {
        if (pOldPairs[i].key.m_ucLowNibble != 0xffffffff)
            reinterpret_cast<::DC3600Map *>(this)->InsertKeyValue((::DC3600Allocator &)(alloc), (*(::DC3600Key *)&(const ::DC3BF0Key &)(pOldPairs[i].key)), pOldPairs[i].val);
    }

    if (iKeepOldBuffer == 0)
        alloc.ReleaseBlock(pOldPairs, sizeof(DC3BF0Pair) * iOldCapacity);
}

namespace fnv_00dc43a0 {
struct DC43A0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct DC43A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DC43A0Allocator* m_pStreamAllocator;

    DC43A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DC43A0MemoryRouter& __cdecl FUN_00c85750();

struct DC43A0ReferencedObject
{
};

template <typename T> struct DC43A0RefPtr
{
    T* m_pRetainedObject;

    ~DC43A0RefPtr()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};

struct DC43A0MapA
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ClearAndRelease(DC43A0Allocator& alloc);
    ~DC43A0MapA()
    {
        reinterpret_cast<::FUN_00dc3b60_class *>(this)->NotifyCallback((struct ::Callback *)&(FUN_00c85750().heap()));
    }
};

struct DC43A0MapB
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ClearAndRelease(DC43A0Allocator& alloc);
    ~DC43A0MapB()
    {
        reinterpret_cast<::CB1A90Owner *>(this)->ProcessArgument((::CB1A90Argument *)&(FUN_00c85750().heap()));
    }
};

struct DC43A0Pair
{
    int m_kPointA;
    int m_kPointB;
};

struct DC43A0PairArray
{
    DC43A0Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~DC43A0PairArray()
    {
        DC43A0Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(DC43A0Pair));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct FUN_00dc43a0
{
    DC43A0RefPtr<DC43A0ReferencedObject> m_pHeadNode;
    DC43A0RefPtr<DC43A0ReferencedObject> m_iSecondInteger;
    int unk08;
    DC43A0MapB m_mapB;
    DC43A0MapA m_mapA;
    DC43A0PairArray m_pairs;

    ~FUN_00dc43a0() throw();
};

// Destructor that destroys the two reference pointers, both maps and the pair array in reverse declaration order.
// @fnv 0x00dc43a0
FUN_00dc43a0::~FUN_00dc43a0() throw()
{}
}  // namespace fnv_00dc43a0

namespace fnv_00dc4f20 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    intptr_t m_iValue10;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct ObjectRef
{
};

struct SubRecord
{
    int m_i00;
    int m_i04;
    int m_i08;

};

struct FUN_00dc4f20_cls
{
    ObjectRef* m_pReference;
    int m_i04;
    int m_iSecond;
    SubRecord m_sub0c;
    SubRecord m_sub18;
    int unk24;
    int unk28;
    unsigned int m_uFlags2c;

    FUN_00dc4f20_cls* Construct(ObjectRef* apRef, int aiSecond);
};

// @fnv 0x00dc4f20
FUN_00dc4f20_cls* FUN_00dc4f20_cls::Construct(ObjectRef* apRef, int aiSecond)
{
    if (apRef != 0)
    {
        reinterpret_cast<::FUN_00c90510_class *>((apRef))->FUN_00c90510();
    }

    m_pReference = apRef;
    m_i04 = 0;
    m_iSecond = aiSecond;

    SubRecord* pSub = &m_sub0c;
    pSub->m_i00 = 0;
    pSub->m_i04 = 0;
    pSub->m_i08 = -1;
    AudioHolder* pHolder = FUN_00c85750();
    reinterpret_cast<::FUN_00cb1fe0_t *>((pSub))->EnsureCapacity(pHolder->m_iValue10, 0);

    SubRecord* pSub2 = &m_sub18;
    pSub2->m_i00 = 0;
    pSub2->m_i04 = 0;
    pSub2->m_i08 = -1;
    AudioHolder* pHolder2 = FUN_00c85750();
    reinterpret_cast<::DC3CC0Map *>((pSub2))->FUN_00dc3cc0((*(::DC3CC0Allocator *)(pHolder2->m_iValue10)), 0);

    unk24 = 0;
    unk28 = 0;
    m_uFlags2c = 0x80000000;
    return this;
}
}  // namespace fnv_00dc4f20

namespace fnv_00dc58a0 {
struct S_00dc58a0_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};
struct S_00dc58a0_Router
{
    int unk0;
    int unk4;
    int unk8;
    S_00dc58a0_Alloc* m_buf;
    S_00dc58a0_Alloc& buf()
    {
        return *m_buf;
    }
};
S_00dc58a0_Router* FUN_00c85750();

struct S_00dc58a0_Obj
{
    int unk0;
    ~S_00dc58a0_Obj() throw();
};
struct S_00dc58a0_Src
{
    S_00dc58a0_Obj GetObjectValue();
};
struct S_00dc58a0_Item
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};
struct S_00dc58a0_Arr
{
    S_00dc58a0_Item* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ClearAndRelease(S_00dc58a0_Alloc& a)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S_00dc58a0_Item));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct FUN_00dc58a0_cls
{
    void FUN_00dc56f0(S_00dc58a0_Arr& out, const S_00dc58a0_Obj& a, const S_00dc58a0_Obj& b) throw();
    void FUN_00dc4210(S_00dc58a0_Src* a, S_00dc58a0_Src* b, S_00dc58a0_Item* item) throw();
    void ProcessSourcePair(S_00dc58a0_Src* a, S_00dc58a0_Src* b) throw();
};

// Builds an item array from two sources, applies FUN_00dc4210 to each item, then frees the array via the router's allocator.
// @fnv 0x00dc58a0
void FUN_00dc58a0_cls::ProcessSourcePair(S_00dc58a0_Src* pSourceA, S_00dc58a0_Src* pSourceB) throw()
{
    S_00dc58a0_Obj ha = pSourceA->GetObjectValue();
    S_00dc58a0_Arr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_iCapacityState = 0x80000000;
    FUN_00dc56f0(arr, ha, pSourceB->GetObjectValue());
    for (int i = 0; i < arr.m_iElementCount; i++)
        FUN_00dc4210(pSourceA, pSourceB, &arr.m_data[i]);
    arr.ClearAndRelease(FUN_00c85750()->buf());
}
}  // namespace fnv_00dc58a0

struct S_00dc5970_Allocator;
struct S_00dc5970_ClassImpl;
struct S_00dc5970_ObjectImpl;

struct S_00dc5970_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00dc5970_Allocator* m_pStreamAllocator;

    static S_00dc5970_Router& FUN_00c85750() throw();
    S_00dc5970_Allocator& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00dc5970_Handle
{
    void* p0;
    void* p1;
};

struct S_00dc5970_Class
{
    S_00dc5970_ClassImpl* m_pClassImpl;

    S_00dc5970_Class(S_00dc5970_ClassImpl* impl) throw();     // FUN_00dba650
    ~S_00dc5970_Class() throw();                              // FUN_00dba660
    S_00dc5970_ClassImpl* getImplementation() const throw();  // FUN_00dba680
};

struct S_00dc5970_Object
{
    S_00dc5970_ObjectImpl* m_pClassImpl;

    S_00dc5970_Object(S_00dc5970_ObjectImpl* impl) throw();  // FUN_00dba760
    S_00dc5970_Object(const S_00dc5970_Object& o) throw();   // AssignRef
    ~S_00dc5970_Object() throw();                            // FUN_00dba7f0
                           // FUN_00dba980
    S_00dc5970_Handle GetObjectHandle() const throw();       // GetSourcePair
    S_00dc5970_Class GetVariantValue() const throw();        // GetObjectValue
};

struct S_00dc5970_World
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual S_00dc5970_ObjectImpl* GetObject(const S_00dc5970_Class& pClassInfo) throw();
    virtual void vf5() throw();
    virtual void vf6() throw();
    virtual void vf7() throw();
    virtual void vf8() throw();
    virtual void vf9() throw();
    virtual S_00dc5970_Object GetSelectionItem(const S_00dc5970_Handle& handle) throw();
};

struct S_00dc5970_Map
{
                              // get
    void Insert(S_00dc5970_Allocator& alloc, S_00dc5970_Handle key, S_00dc5970_Handle val) throw();  // insert

    int get(S_00dc5970_Handle key, S_00dc5970_Handle* out) throw()
    {
        return reinterpret_cast<::S_00dc3b90 *>(this)->LookupValue((*(unsigned long long *)&(const ::S_00dc5970_Handle &)(key)), (unsigned long long *)(out));
    }
    void insert(S_00dc5970_Handle key, S_00dc5970_Handle val) throw()
    {
        Insert(S_00dc5970_Router::FUN_00c85750().heap(), key, val);
    }
};

struct S_00dc5970_Cloner
{
    S_00dc5970_World& m_kSourceWorld;
    intptr_t unk4;
    S_00dc5970_Map m_kHandleMap;

    S_00dc5970_ClassImpl* FUN_00dc5440(S_00dc5970_ClassImpl* srcClass) throw();  // copyClass
    S_00dc5970_Object CloneObject(const S_00dc5970_Object& srcObj) throw();
};

// Looks up srcObj's handle in the map; if absent, clones its class, creates a destination object, records the handle mapping, copies the object and returns it.
// @fnv 0x00dc5970
S_00dc5970_Object S_00dc5970_Cloner::CloneObject(const S_00dc5970_Object& srcObj) throw()
{
    if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(srcObj))->FUN_00dba980())))
    {
        S_00dc5970_Handle dstHandle;
        if (m_kHandleMap.get(srcObj.GetObjectHandle(), &dstHandle) == 0)
            return m_kSourceWorld.GetSelectionItem(dstHandle);

        S_00dc5970_Class dstClass(FUN_00dc5440(srcObj.GetVariantValue().getImplementation()));
        S_00dc5970_Object dstObj(m_kSourceWorld.GetObject(dstClass));
        m_kHandleMap.insert(srcObj.GetObjectHandle(), dstObj.GetObjectHandle());
        reinterpret_cast<::fnv_00dc58a0::FUN_00dc58a0_cls *>(this)->ProcessSourcePair((::fnv_00dc58a0::S_00dc58a0_Src *)&(dstObj), (::fnv_00dc58a0::S_00dc58a0_Src *)&(srcObj));
        return dstObj;
    }
    return S_00dc5970_Object(0);
}

struct FUN_00dc38f0_cls
{
    struct E
    {
        int k;
        int a;
        int b;
    }* m_00;
    unsigned int m_04;
    int m_08;
    void ResetEntries();
};
// Calls ResetEntries, then if the high flag bit is clear, invokes callback->update with entries and (count + 1) * 12 bytes.
// @fnv 0x00dc3b60
void FUN_00dc3b60_class::NotifyCallback(Callback* callback)
{
    reinterpret_cast<::FUN_00dc38f0_cls *>(this)->ResetEntries();
    if ((flags & 0x80000000) == 0)
        callback->update(entries, (count + 1) * 12);
}

// Sets the k field of the first m_08 + 1 entries to -1 and clears all but the top bit of m_04.
// @fnv 0x00dc38f0
void FUN_00dc38f0_cls::ResetEntries()
{
    int count = m_08 + 1;
    for (int i = 0; i < count; ++i)
        m_00[i].k = -1;
    m_04 &= 0x80000000u;
}

// FUN_00dc39b0 - rehash a hash table into a freshly allocated one.
//
// The table owns an array of 16-byte entries; the allocator is a polymorphic
// object whose virtual slot 4 allocates and slot 8 frees.  Every entry that
// is still in use is re-inserted through Insert; the old array is only
// released when the table did not grow behind a 0x80000000 flag.
struct Allocator_cls
{
    virtual void unk();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p, unsigned int size);
};

struct Pair_dc3
{
    unsigned int lo;
    unsigned int hi;
};
struct HashEntry
{
    Pair_dc3 key;
    Pair_dc3 val;
};

struct HashTable_cls
{
    HashEntry* m_00;
    unsigned int m_04;
    unsigned int m_08;

    void FUN_00dc39b0(Allocator_cls* alloc, int newSize);
};
// @fnv 0x00dc3bd0
void Wrapper::FUN_00dc3bd0(intptr_t first, int count)
{
    int needed = count + count;
    int capacity = 8;
    while (capacity < needed)
        capacity += capacity;
    reinterpret_cast<::HashTable_cls *>(this)->FUN_00dc39b0((::Allocator_cls *)(first), capacity);
}

extern int DAT_010d6b98[];
struct DC1C50Shape
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
};
struct DC1C50Collection
{
};

// Maps a type/subtype pair to a flag value from DAT_010d6b98, resolving subtype 0x19 against the collection's child types and optionally OR-ing 0x20.
// @fnv 0x00dc1c50
int __cdecl GetShapeTypeFlags(int iType, int iSubType, DC1C50Collection* pkCollection, int abAddFlag)
{
    if (iType == 0x18 || iType == 0x1f)
    {
        iType = iSubType;
        iSubType = 0;
    }
    int iFlags = DAT_010d6b98[iType];
    if (iFlags == 0x10)
    {
        switch (iSubType)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
            iFlags = DAT_010d6b98[iSubType] | 0x10;
            break;
        case 4:
            iFlags = 0x11;
            break;
        case 0x19: {
            int bValid = 1;
            for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00d46f00_s *>((pkCollection))->FUN_00d46f00())); i++)
            {
                int iChildType = ((::DC1C50Shape *)(reinterpret_cast<::HkClassNode *>((pkCollection))->FUN_00d46f20(i)))->m_type;
                if (iChildType == 0x16 || (iChildType > 0x19 && iChildType <= 0x1b))
                {
                    bValid = 0;
                    break;
                }
            }
            iFlags = bValid ? 0x19 : 0x18;
            break;
        }
        }
    }
    if (abAddFlag)
        iFlags |= 0x20;
    return iFlags;
}

struct ValueQ
{
    void* m_pClassImpl;
    int m_handle;
    float FUN_00dbaa00() const throw();
    const float* DispatchToInterface(int n) const throw();
    const char* FUN_00dba9c0() const throw();
};

struct ClonerQ : S_00dc5970_Cloner
{
    void CopyValue(ValueQ dst, const ValueQ& src) throw();
};

// Copies src into dst by dispatching on src's type tag and calling the matching setter for int, float, float array, object or string values.
// @fnv 0x00dc5ab0
void ClonerQ::CopyValue(ValueQ dst, const ValueQ& src) throw()
{
    switch (reinterpret_cast<::fnv_00dba920::Target *>((void *)&(src))->QueryAndWriteResult())
    {
    case 1:
    case 2:
        reinterpret_cast<::FUN_00dbaa30_cls *>(&(dst))->FUN_00dbaa30(reinterpret_cast<::S_00dba990 *>((void *)&(src))->FUN_00dba990());
        break;
    case 3:
        reinterpret_cast<::FUN_00dbaab0_cls *>(&(dst))->DispatchFloatToVtbl(src.FUN_00dbaa00());
        break;
    case 4:
    case 5:
    case 6:
    case 7: {
        int n = (reinterpret_cast<::fnv_00dba920::Target *>((void *)&(src))->QueryAndWriteResult() - 3) * 4;
        reinterpret_cast<::AudioHandle *>(&(dst))->FUN_00dbab10((uintptr_t)(src.DispatchToInterface(n)), n);
        break;
    }
    case 8:
    case 9:
        reinterpret_cast<::FUN_00dbaa50_cls *>(&(dst))->DispatchToObject((void **)&(const ::S_00dc5970_Object &)(CloneObject((*(::S_00dc5970_Object *)(reinterpret_cast<::FUN_00dba9d0_cls *>((void *)&(src))->FUN_00dba9d0({}))))));
        break;
    case 10:
        reinterpret_cast<::S_00dbab30_Ref *>(&(dst))->FUN_00dbab30((intptr_t)(src.FUN_00dba9c0()));
        break;
    }
}

class hkMemoryAllocatorDC37;

struct hkPairKeyDC37
{
    unsigned int m_k1;
    unsigned int m_k2;
    bool operator==(const hkPairKeyDC37& o) const
    {
        return m_k1 == o.m_k1 && m_k2 == o.m_k2;
    }
};

struct hkPairValueDC37
{
    unsigned int m_v1;
    unsigned int m_v2;
};

struct hkPairMapElemDC37
{
    hkPairKeyDC37 m_key;
    hkPairValueDC37 m_uiFilterValue;
};

class hkPairMapDC37
{
  public:
    hkPairMapElemDC37* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int Insert(hkMemoryAllocatorDC37& alloc, hkPairKeyDC37 key, hkPairValueDC37 value);
};
// @fnv 0x00dc39b0
void HashTable_cls::FUN_00dc39b0(Allocator_cls* alloc, int newSize)
{
    int n = newSize;
    if (n <= 8)
    {
        n = 8;
    }
    unsigned int flag = m_04 & 0x80000000u;
    int remain = (int)(m_08 + 1);
    HashEntry* pOldEntries = m_00;
    m_00 = (HashEntry*)alloc->Alloc((unsigned int)n << 4);
    for (int i = 0; i < n; i++)
    {
        m_00[i].key.lo = -1;
    }
    m_04 = 0;
    m_08 = (unsigned int)(n - 1);
    for (int i = 0; i < remain; i++)
    {
        if (pOldEntries[i].key.lo != -1)
        {
            reinterpret_cast<::hkPairMapDC37 *>(this)->Insert((*(::hkMemoryAllocatorDC37 *)(alloc)), (*(::hkPairKeyDC37 *)&(const ::Pair_dc3 &)(pOldEntries[i].key)), (*(::hkPairValueDC37 *)&(const ::Pair_dc3 &)(pOldEntries[i].val)));
        }
    }
    if (flag == 0)
    {
        alloc->Free(pOldEntries, (unsigned int)remain << 4);
    }
}

// Checks for the key, calls FUN_00dc39b0 under the shown condition, stores the key/value, and returns whether the key was new.
// @fnv 0x00dc3740
int hkPairMapDC37::Insert(hkMemoryAllocatorDC37& alloc, hkPairKeyDC37 key, hkPairValueDC37 value)
{
    if ((m_iCapacityFlags & 0x7fffffff) * 2 > m_iPairCount)
        reinterpret_cast<::HashTable_cls *>(this)->FUN_00dc39b0((::Allocator_cls *)&(alloc), m_iPairCount * 2 + 2);

    unsigned int i = ((key.m_k1 >> 4) * 0x9e3779b1) & m_iPairCount;
    int isNewKey = 1;
    while (m_kPrimitiveElement[i].m_key.m_k1 != 0xffffffff)
    {
        if (m_kPrimitiveElement[i].m_key == key)
        {
            isNewKey = 0;
            break;
        }
        i = (i + 1) & m_iPairCount;
    }
    m_iCapacityFlags += isNewKey;
    m_kPrimitiveElement[i].m_key = key;
    m_kPrimitiveElement[i].m_uiFilterValue = value;
    return isNewKey;
}

#include <xmmintrin.h>
class FUN_00c6cd00_cls
{
  public:
    __m128 m_v0;
    __m128 m_v1;
    __m128 m_v2;

    void FUN_00c6cd00(const FUN_00c6cd00_cls* src);
};

// Copies the three __m128 vector fields from src into the current object.
// @fnv 0x00c6cd00
void FUN_00c6cd00_cls::FUN_00c6cd00(const FUN_00c6cd00_cls* src)
{
    m_v0 = src->m_v0;
    m_v1 = src->m_v1;
    m_v2 = src->m_v2;
}

struct S48
{
    __m128 v[3];
    void CopyFromFloatArray(const float* src);
};
// Copies 12 floats from src into the three __m128 members of v using SSE load/store.
// @fnv 0x00c6cd30
void S48::CopyFromFloatArray(const float* src)
{
    _mm_store_ps((float*)&v[0], _mm_load_ps(src));
    _mm_store_ps((float*)&v[1], _mm_load_ps(src + 4));
    _mm_store_ps((float*)&v[2], _mm_load_ps(src + 8));
}

typedef __m128 M128;

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Mat3a
{
    Vec4 c0, c1, c2;
};

struct Mat3b
{
    Vec4 c0, c1, c2;
};

struct Mat4a
{
    Vec4 c0, c1, c2, c3;
};

struct Mat4b
{
    Vec4 c0, c1, c2, c3;
};

struct DKlass
{
};

struct DObj
{
    int unk00;
    __forceinline ~DObj() throw()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
};

struct DValue
{
    int unk00;
    int unk04;
    int CallVirtualWithArg() throw();
    float ApplyValue() throw();
    const float* DispatchToVTableSlot8(int n) throw();
    template <int Width> __forceinline const float* asVector() throw()
    {
        return DispatchToVTableSlot8(Width);
    }
};

struct DArray
{
    int FUN_00dbac00() throw();
    DValue FUN_00dbabb0(int i) throw();
};

struct DVariant
{
    void* unk00;
    void* unk04;
};

struct DAllocator
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
};

struct DMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DAllocator* unk10;
};

__declspec(restrict) void* __cdecl FUN_00c85750() throw();
extern "C" void __cdecl FUN_00cb1280(void* p, int v, intptr_t n) throw();

struct DOutArray
{
    void* unk00;
    int unk04;
    int unk08;
};

struct DMember
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;
};

struct DTracker
{
};

template <class T> __forceinline T* AllocElems(int& count)
{
    DMemory* mem = (DMemory*)FUN_00c85750();
    DAllocator& heap = *mem->unk10;
    T* p;
    {
        int numBytes = count * (int)sizeof(T);
        p = (T*)heap.AllocateBufferWithSize(numBytes);
        count = numBytes / (int)sizeof(T);
    }
    return p;
}

__forceinline void* CopyClassBytes(DAllocator& heap, const int& bytes) throw()
{
    int localBytes = bytes;
    return heap.AllocateBufferWithSize(localBytes);
}

struct DReader
{
    int unk00;
    DTracker* unk04;
    int unk08;

    DKlass* FUN_00dc3a80(DMember* member, DObj& obj) throw();
    int ReadObject(void* p, DObj& obj) throw();
    DVariant FUN_00dc4430(DObj& obj, int flag) throw();
    int ReadValue(char** p, int type, DValue& v, int unk, int flag) throw();

    int ReadArray(DOutArray* out, DMember* member, DArray* arr) throw();
};

struct DC3710Vector4
{
    __m128 m_vComponents;

    void operator=(const DC3710Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct DC3710Transform
{
    DC3710Vector4 m_kColumn0;
    DC3710Vector4 m_kColumn1;
    DC3710Vector4 m_kColumn2;
    DC3710Vector4 m_vTranslation;

    void FUN_00dc3710(const DC3710Transform& t);
};
// Converts DArray elements into a type-selected output buffer, records eligible allocations, and updates out->unk08 for member type 0x16.
// @fnv 0x00dc1d30
int DReader::ReadArray(DOutArray* out, DMember* member, DArray* apArray) throw()
{
    if (apArray->FUN_00dbac00() == 0)
    {
        if (member->unk0C == 0x16)
        {
            out->unk08 = 0x80000000;
        }
        return 0;
    }

    int result = 0;
    int flag = ((unsigned short)~member->unk10 >> 9) & 1;
    int elemSize = 0;

    switch (member->unk0D)
    {
    case 0:
        goto checkTrack;
    case 1: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<bool>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((bool*)out->unk00)[i] = apArray->FUN_00dbabb0(i).CallVirtualWithArg() != 0;
        }
        break;
    }
    case 2: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<char>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((char*)out->unk00)[i] = (char)apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 3: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<unsigned char>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((unsigned char*)out->unk00)[i] = (unsigned char)apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 4: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<char>(out->unk04);
        elemSize = 1;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((char*)out->unk00)[i] = (char)apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 5: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<short>(out->unk04);
        elemSize = 2;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((short*)out->unk00)[i] = (short)apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 6: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<unsigned short>(out->unk04);
        elemSize = 2;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((unsigned short*)out->unk00)[i] = (unsigned short)apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 7: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<int>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((int*)out->unk00)[i] = apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 8: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<unsigned int>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((unsigned int*)out->unk00)[i] = apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 9: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<__int64>(out->unk04);
        elemSize = 8;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((__int64*)out->unk00)[i] = apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 10: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<unsigned __int64>(out->unk04);
        elemSize = 8;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((unsigned __int64*)out->unk00)[i] = apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 30: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<unsigned long>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((unsigned long*)out->unk00)[i] = apArray->FUN_00dbabb0(i).CallVirtualWithArg();
        }
        break;
    }
    case 11: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<float>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            ((float*)out->unk00)[i] = apArray->FUN_00dbabb0(i).ApplyValue();
        }
        break;
    }
    case 32: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<short>(out->unk04);
        elemSize = 2;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            union
            {
                float f;
                int i;
            } u;
            u.f = apArray->FUN_00dbabb0(i).ApplyValue();
            ((short*)out->unk00)[i] = (short)(u.i >> 16);
        }
        break;
    }
    case 12: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<Vec4>(out->unk04);
        elemSize = 16;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            *(M128*)&((Vec4*)out->unk00)[i] = *(const M128*)apArray->FUN_00dbabb0(i).asVector<4>();
        }
        break;
    }
    case 13: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<Vec4>(out->unk04);
        elemSize = 16;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            *(M128*)&((Vec4*)out->unk00)[i] = *(const M128*)apArray->FUN_00dbabb0(i).asVector<4>();
        }
        break;
    }
    case 14: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<Mat3a>(out->unk04);
        elemSize = 48;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            reinterpret_cast<::FUN_00c6cd00_cls *>(&(((Mat3a*)out->unk00)[i]))->FUN_00c6cd00((const ::FUN_00c6cd00_cls *)(const float *)(apArray->FUN_00dbabb0(i).asVector<12>()));
        }
        break;
    }
    case 15: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<Mat3b>(out->unk04);
        elemSize = 48;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            reinterpret_cast<::S48 *>(&(((Mat3b*)out->unk00)[i]))->CopyFromFloatArray(apArray->FUN_00dbabb0(i).asVector<12>());
        }
        break;
    }
    case 16: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<Mat3b>(out->unk04);
        elemSize = 48;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            reinterpret_cast<::S48 *>(&(((Mat3b*)out->unk00)[i]))->CopyFromFloatArray(apArray->FUN_00dbabb0(i).asVector<12>());
        }
        break;
    }
    case 17: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<Mat4a>(out->unk04);
        elemSize = 64;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            reinterpret_cast<::DC3710Transform *>(&(((Mat4a*)out->unk00)[i]))->FUN_00dc3710((*(const ::DC3710Transform *)(apArray->FUN_00dbabb0(i).asVector<16>())));
        }
        break;
    }
    case 18: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<Mat4b>(out->unk04);
        elemSize = 64;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            reinterpret_cast<::hkMatrix4CD60 *>(&(((Mat4b*)out->unk00)[i]))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(apArray->FUN_00dbabb0(i).asVector<16>())));
        }
        break;
    }
    case 25: {
        DKlass* pClassInfo = FUN_00dc3a80(member, (*(::DObj *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::DValue &)(apArray->FUN_00dbabb0(0)))->CreateValueInto({}))));
        if (pClassInfo)
        {
            out->unk04 = apArray->FUN_00dbac00();
            int totalBytes = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((pClassInfo))->FUN_00d470d0() * out->unk04;
            DMemory* mem = (DMemory*)FUN_00c85750();
            {
                int numBytes = totalBytes;
                out->unk00 = CopyClassBytes(*mem->unk10, numBytes);
            }
            elemSize = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((pClassInfo))->FUN_00d470d0();
            FUN_00cb1280(out->unk00, 0, reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((pClassInfo))->FUN_00d470d0() * apArray->FUN_00dbac00());
            for (int i = 0; i < apArray->FUN_00dbac00(); i++)
            {
                if (result != 0)
                {
                    goto checkTrack;
                }
                void* p;
                {
                    int offset = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((pClassInfo))->FUN_00d470d0() * i;
                    p = (char*)out->unk00 + offset;
                }
                result = ReadObject(p, (*(::DObj *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::DValue &)(apArray->FUN_00dbabb0(i)))->CreateValueInto({}))));
            }
        }
        if (!pClassInfo)
            goto finish;
        break;
    }
    case 20: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<void*>(out->unk04);
        elemSize = 4;
        FUN_00cb1280(out->unk00, 0, out->unk04 * 4);
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            DObj o = (*(::DObj *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::DValue &)(apArray->FUN_00dbabb0(i)))->CreateValueInto({})));
            if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>(&(o))->FUN_00dba980())))
            {
                DVariant v = FUN_00dc4430(o, flag);
                if (v.unk00 == 0)
                {
                    result = 1;
                }
                else
                {
                    ((void**)out->unk00)[i] = v.unk00;
                }
            }
        }
        break;
    }
    case 28: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<DVariant>(out->unk04);
        elemSize = 8;
        FUN_00cb1280(out->unk00, 0, out->unk04 * 8);
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            DObj o = (*(::DObj *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::DValue &)(apArray->FUN_00dbabb0(i)))->CreateValueInto({})));
            if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>(&(o))->FUN_00dba980())))
            {
                DVariant v = FUN_00dc4430(o, flag);
                if (v.unk00 == 0)
                {
                    result = 1;
                }
                else
                {
                    ((DVariant*)out->unk00)[i] = v;
                }
            }
        }
        break;
    }
    case 29: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<char*>(out->unk04);
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            if (result != 0)
            {
                break;
            }
            int subtype = member->unk0D;
            char** destination = &((char**)out->unk00)[i];
            result = ReadValue(destination, subtype, apArray->FUN_00dbabb0(i), 0, flag);
        }
    }
    case 33: {
        out->unk04 = apArray->FUN_00dbac00();
        out->unk00 = AllocElems<char*>(out->unk04);
        elemSize = 4;
        for (int i = 0; i < apArray->FUN_00dbac00(); i++)
        {
            if (result != 0)
            {
                goto checkTrack;
            }
            int subtype = member->unk0D;
            char** destination = &((char**)out->unk00)[i];
            result = ReadValue(destination, subtype, apArray->FUN_00dbabb0(i), 0, flag);
        }
        break;
    }
    default:
        return 1;
    }

checkTrack:
    if (elemSize <= 0)
        goto finish;
track:
    reinterpret_cast<::S_00dc3ce0 *>((unk04))->AddEntry((intptr_t)(out->unk00), out->unk04 * elemSize, 0x18);

finish:
    if (member->unk0C == 0x16)
    {
        out->unk08 = out->unk04;
        if (unk08 == 0)
        {
            out->unk08 |= 0x80000000;
        }
    }
    return result;
}

// Copies the four vector fields from the source transform into this transform.
// @fnv 0x00dc3710
void DC3710Transform::FUN_00dc3710(const DC3710Transform& akSource)
{
    m_kColumn0 = akSource.m_kColumn0;
    m_kColumn1 = akSource.m_kColumn1;
    m_kColumn2 = akSource.m_kColumn2;
    m_vTranslation = akSource.m_vTranslation;
}

struct S_00dc4a80_Reader
{
    void* DispatchToVTableSlot8(int count) throw();
    const char* FUN_00dbac70() throw();
    float ApplyValue() throw();
    int CallVirtualWithArg() throw();
};

struct S_00dc4a80_M3
{
};

struct S_00dc4a80_Rot
{
};

struct S_00dc4a80_QsTr
{
};

struct S_00dc4a80_M4
{
};

struct S_00dc4a80_Tr
{
};

__forceinline void constructStrings(char** p, int n, char* const& str) throw()
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = str;
    }
}

struct StringArray
{
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(char* str) throw()
    {
        S_00dc3ce0_Router& r = S_00dc3ce0_Router::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ::ResizeAudioStream((::AudioAllocator *)&(r.heap()), (::AudioStream *)(void *)(this), 4);
        }
        constructStrings(m_data + m_iElementCount, 1, str);
        m_iElementCount++;
    }
};

struct StringHolder
{
    int unk00;
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
    StringArray m_pStringFunctions;
};

extern "C" char* __cdecl FUN_00cb1410(const char*) throw();

struct S_00dc4a80
{
    int unk00;
    StringHolder* unk04;
    int unk08;


    int ReadValue(void* out, int type, S_00dc4a80_Reader* reader, intptr_t arg3, int arg4) throw();
};

namespace fnv_00dc4fa0 {


struct S_00dc4fa0_Reader
{
    void* DispatchToInterface(int count) throw();
    const char* FUN_00dba9c0() throw();
    float FUN_00dbaa00() throw();
};

struct S_00dc4fa0_M3
{
};

struct S_00dc4fa0_Rot
{
};

struct S_00dc4fa0_QsTr
{
};

struct S_00dc4fa0_M4
{
};

struct S_00dc4fa0_Tr
{
};

struct StringArray
{
    char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(char* str) throw()
    {
        S_00dc3ce0_Router* r = &S_00dc3ce0_Router::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(*r->m_pStreamAllocator), (::AudioStream *)(void *)(this), sizeof(char*));
        char** p = m_data + m_iElementCount;
        __assume(p != 0);
        new (p) char*(str);
        m_iElementCount++;
    }
};

struct StringHolder
{
    int unk00;
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
    StringArray m_pStringFunctions;
};

extern "C" char* __cdecl FUN_00cb1410(const char*) throw();

struct S_00dc4fa0
{
    int unk00;
    StringHolder* unk04;
    int unk08;

    void FUN_00dc4430(S_00dc5970_Handle* out, const S_00dc5970_Object& obj, int arg4) throw();
    int ReadObject(void* out, const S_00dc5970_Object& obj) throw();

    int FUN_00dc4fa0(void* out, int type, S_00dc4fa0_Reader* reader, intptr_t arg3, int arg4) throw();
};

// Reads a typed value from reader into out based on type, returning 1 on error or unsupported type.
// @fnv 0x00dc4fa0
int S_00dc4fa0::FUN_00dc4fa0(void* out, int type, S_00dc4fa0_Reader* reader, intptr_t aiFlag, int arg4) throw()
{
    switch (type)
    {
    case 1:
        *(bool*)out = (reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990() != 0);
        return 0;
    case 2:
        *(unsigned char*)out = (unsigned char)reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 3:
        *(char*)out = (char)reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 4:
        *(unsigned char*)out = (unsigned char)reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 5:
        *(short*)out = (short)reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 6:
        *(unsigned short*)out = (unsigned short)reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 7:
        *(int*)out = reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 8:
        *(unsigned int*)out = (unsigned int)reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 30:
        *(int*)out = reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 9:
        *(__int64*)out = reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 10:
        *(__int64*)out = reinterpret_cast<::S_00dba990 *>((reader))->FUN_00dba990();
        return 0;
    case 11:
        *(float*)out = reader->FUN_00dbaa00();
        return 0;
    case 32: {
        float f = reader->FUN_00dbaa00();
        *(short*)out = (short)(*(int*)&f >> 16);
        return 0;
    }
    case 20:
        if (aiFlag)
        {
            S_00dc5970_Object obj = (*(::S_00dc5970_Object *)(reinterpret_cast<::FUN_00dba9d0_cls *>((reader))->FUN_00dba9d0({})));
            if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(obj))->FUN_00dba980())))
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                FUN_00dc4430(&h, obj, arg4);
                if (!h.p0)
                {
                    return 1;
                }
                *(void**)out = h.p0;
            }
        }
        break;
    case 25:
        if (aiFlag)
        {
            bool err;
            if (err = (ReadObject(out, (*(::S_00dc5970_Object *)(reinterpret_cast<::FUN_00dba9d0_cls *>((reader))->FUN_00dba9d0({})))) == 1))
            {
                return 1;
            }
        }
        break;
    case 12:
        *(__m128*)out = *(__m128*)reader->DispatchToInterface(4);
        return 0;
    case 13:
        *(__m128*)out = *(__m128*)reader->DispatchToInterface(4);
        return 0;
    case 14:
        reinterpret_cast<::FUN_00c6cd00_cls *>((((S_00dc4fa0_M3*)out)))->FUN_00c6cd00((const ::FUN_00c6cd00_cls *)(void *)(reader->DispatchToInterface(12)));
        return 0;
    case 15:
        reinterpret_cast<::S48 *>((((S_00dc4fa0_Rot*)out)))->CopyFromFloatArray((const float *)(void *)(reader->DispatchToInterface(12)));
        return 0;
    case 16:
        reinterpret_cast<::S48 *>((((S_00dc4fa0_QsTr*)out)))->CopyFromFloatArray((const float *)(void *)(reader->DispatchToInterface(12)));
        return 0;
    case 17:
        reinterpret_cast<::DC3710Transform *>((((S_00dc4fa0_M4*)out)))->FUN_00dc3710((*(const ::DC3710Transform *)(reader->DispatchToInterface(16))));
        return 0;
    case 18:
        reinterpret_cast<::hkMatrix4CD60 *>((((S_00dc4fa0_Tr*)out)))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(reader->DispatchToInterface(16))));
        return 0;
    case 29: {
        if (unk08)
        {
            return 1;
        }
        char* copy;
        if (reader->FUN_00dba9c0())
        {
            copy = FUN_00cb1410(reader->FUN_00dba9c0());
            unk04->m_pStringFunctions.AddBack(copy);
        }
        else
        {
            copy = 0;
        }
        *(char**)out = copy;
        return 0;
    }
    case 33: {
        intptr_t val;
        if (reader->FUN_00dba9c0())
        {
            char* copy = FUN_00cb1410(reader->FUN_00dba9c0());
            unk04->m_pStringFunctions.AddBack(copy);
            val = (intptr_t)copy;
        }
        else
        {
            val = 0;
        }
        *(int*)out = val;
        if (unk08)
        {
            *(int*)out = val | 1;
            return 0;
        }
        break;
    }
    case 28:
        if (unk08)
        {
            return 1;
        }
        {
            S_00dc5970_Object obj = (*(::S_00dc5970_Object *)(reinterpret_cast<::FUN_00dba9d0_cls *>((reader))->FUN_00dba9d0({})));
            if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(obj))->FUN_00dba980())))
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                FUN_00dc4430(&h, obj, arg4);
                if (!h.p0)
                {
                    return 1;
                }
                *(S_00dc5970_Handle*)out = h;
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
}  // namespace fnv_00dc4fa0

struct DCNode;
struct DCWorld
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void add(void*);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual DCNode* find(DCNode*);
};
struct DCNode
{
    virtual void f0();
    virtual void f1();
    virtual DCNode* get();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int count();
    virtual void member(int, void*);
};
struct DCIterator
{
    int p;
    DCIterator(DCNode*) throw();
    ~DCIterator() throw();
    DCNode* FUN_00dba680() throw();
};
struct DCEntry
{
    int x[3];
    void* data;
    int size;
    int cap;
};
struct DCArray
{
    DCEntry* data;
    int size;
    int cap;
    void reserve(void*, int);
};
inline void DCArray::reserve(void* heap, int min)
{
    int old = cap & 0x3fffffff;
    if (old < min)
    {
        int n = old * 2;
        if (n <= min)
            n = min;
        ::FUN_00c908c0((::SpawnedObject *)(heap), (::SpawnedArray *)(::DCArray *)(this), n, 24);
    }
}
struct DCAlloc
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Free(void*, int);
};
struct DCRouter
{
    int x[3];
    DCAlloc* heap;
    DCAlloc* other;
};
__forceinline void clearPart(int flags, int* cap, DCAlloc* other)
{
    cap[-1] = 0;
    if (!(flags & 0x80000000))
        other->Free(*(void**)(cap - 2), (flags & 0x3fffffff) * 16);
    *(void**)(cap - 2) = 0;
    cap[0] = 0x80000000;
}
// Looks up srcClass in m_kSourceWorld; on a miss, walks nodes, adds collected entries, visits members recursively, and frees temporary array storage.
// @fnv 0x00dc5440
S_00dc5970_ClassImpl* S_00dc5970_Cloner::FUN_00dc5440(S_00dc5970_ClassImpl* srcClass) throw()
{

    DCNode* arg = (DCNode*)srcClass;
    DCNode* result = ((DCWorld*)&m_kSourceWorld)->find(arg);
    if (result)
        return (S_00dc5970_ClassImpl*)result;
    {
        DCArray a = {0, 0, (int)0x80000000};
        DCRouter* r = (DCRouter*)FUN_00c85750();
        a.reserve(r->heap, 10);
        DCNode* node = arg;
        while (node && !((DCWorld*)&m_kSourceWorld)->find(node))
        {
            DCIterator it(((DCWorld*)unk4)->find(node));
            r = (DCRouter*)FUN_00c85750();
            if (a.size == (a.cap & 0x3fffffff))
                ::ResizeAudioStream((::AudioAllocator *)(r->heap), (::AudioStream *)(::DCArray *)(&a), 24);
            DCEntry* e = a.data + a.size;
            if (e)
            {
                e->data = 0;
                e->size = 0;
                e->cap = 0x80000000;
            }
            DCEntry* out = a.data + a.size;
            a.size++;
            reinterpret_cast<::S_00dbafe0 *>(&(it))->FillOutFromInterface((::S_Out *)(out));
            node = ((int)(reinterpret_cast<::CpuObject *>((void *)&(const ::DCIterator &)((*(::DCIterator *)(reinterpret_cast<::FUN_00dba6a0_cls *>(&(it))->SetShiftedValue({})))))->FUN_00dba670())) ? 0 : (*(::DCIterator *)(reinterpret_cast<::FUN_00dba6a0_cls *>(&(it))->SetShiftedValue({}))).FUN_00dba680();
        }
        for (int i = a.size - 1; i >= 0; --i)
            ((DCWorld*)&m_kSourceWorld)->add(a.data + i);
        DCNode* pClass = ((DCWorld*)unk4)->find(arg);
        for (int i = 0; i < pClass->count(); ++i)
        {
            struct Member
            {
                int x[5];
            } member = {0, 0, 0, 0, 0};
            pClass->member(i, &member);
            if (member.x[3])
                FUN_00dc5440((S_00dc5970_ClassImpl*)((DCNode*)member.x[3])->get());
        }
        srcClass = (S_00dc5970_ClassImpl*)((DCWorld*)&m_kSourceWorld)->find(arg);
        DCAlloc* heap = ((DCRouter*)FUN_00c85750())->heap;
        if (a.size > 0)
        {
            int* cap = &a.data->cap;
            int i = a.size;
            do
            {
                DCRouter* r = (DCRouter*)FUN_00c85750();
                clearPart(cap[0], cap, r->other);
                cap += 6;
            } while (--i);
        }
        a.size = 0;
        if (!(a.cap & 0x80000000))
            heap->Free(a.data, (a.cap & 0x3fffffff) * 24);
    }
    return srcClass;
}

struct DWC_Allocator;
struct DWC_Router
{
    int unk0;
    int unk4;
    int unk8;
    DWC_Allocator* m_pTemp;

    static DWC_Router& FUN_00c85750() throw();
    DWC_Allocator& temp() throw()
    {
        return *m_pTemp;
    }
};
struct DWC_Allocator
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct DWC_ClassImpl;
struct DWC_ClassSource
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual DWC_ClassImpl* getImplementation() throw();
};
struct DWC_MemberInfo
{
    const char* m_name;
    int m_type;
    int m_tuple;
    DWC_ClassSource* m_class;
    const void* m_valuePtr;
    DWC_MemberInfo() throw() : m_name(0), m_type(0), m_tuple(0), m_class(0), m_valuePtr(0)
    {}
};
inline void* operator new(std::size_t, DWC_MemberInfo* p) throw()
{
    return p;
}

__forceinline void DWC_construct(DWC_MemberInfo* t, int n) throw()
{
    for (int i = 0; i < n; ++i)
    {
        ::new (t + i) DWC_MemberInfo();
    }
}

struct DWC_MemberArray
{
    DWC_MemberInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    DWC_MemberArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~DWC_MemberArray() throw()
    {
        _clearAndDeallocate(DWC_Router::FUN_00c85750().temp());
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    DWC_MemberInfo& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(DWC_Allocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(DWC_MemberInfo));
        }
    }
    __forceinline void GrowArrayCapacity(DWC_Allocator& alloc, int n) throw()
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(DWC_MemberInfo));
        }
    }
    __forceinline void _setSize(DWC_Allocator& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        DWC_construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        _setSize(DWC_Router::FUN_00c85750().temp(), n);
    }
};

struct DWC_Class
{
    int FUN_00dba730() const throw();
};

struct DWC_Cloner
{
    void FUN_00dc56f0(DWC_MemberArray& dstInfos, const DWC_Class& dstClass, const DWC_Class& srcClass) throw();
};

// Dispatches member info for both classes, then fills null destination m_class entries with cloned source implementations.
// @fnv 0x00dc56f0
void DWC_Cloner::FUN_00dc56f0(DWC_MemberArray& dstInfos, const DWC_Class& dstClass, const DWC_Class& srcClass) throw()
{
    DWC_MemberArray srcInfos;
    srcInfos.SetSizeAndGrow(srcClass.FUN_00dba730());
    reinterpret_cast<::S_00dbaed0_Obj *>((void *)&(srcClass))->DispatchItems((::S_00dbaed0_Elem **)&(srcInfos));

    dstInfos.SetSizeAndGrow(dstClass.FUN_00dba730());
    reinterpret_cast<::S_00dbaed0_Obj *>((void *)&(dstClass))->DispatchItems((::S_00dbaed0_Elem **)&(dstInfos));

    for (int i = 0; i < srcClass.FUN_00dba730(); ++i)
    {
        if (srcInfos[i].m_class && !dstInfos[i].m_class)
        {
            dstInfos[i].m_class = (DWC_ClassSource*)((::DWC_ClassImpl *)(reinterpret_cast<::S_00dc5970_Cloner *>(this)->FUN_00dc5440((::S_00dc5970_ClassImpl *)(::DWC_ClassImpl *)(srcInfos[i].m_class->getImplementation()))));
        }
    }
}

extern "C" void _ReadWriteBarrier(void);
struct S_00dc3920_E
{
    unsigned int key0;
    unsigned int key1;
    unsigned int unk08;
    unsigned int unk0C;
};
struct FUN_00dc3920_cls
{
    S_00dc3920_E* m_pEntries;
    unsigned int unk04;
    int m_iMask;
    unsigned int FindEntry(unsigned int a, unsigned int b);
};
// @fnv 0x00dc3b90
int S_00dc3b90::LookupValue(unsigned __int64 key, unsigned __int64* out)
{
    int i = ((int)(reinterpret_cast<::FUN_00dc3920_cls *>(this)->FindEntry(key, {})));
    if (i <= m_iPairCount)
    {
        *out = m_kPrimitiveElement[i].val;
        return 0;
    }
    return 1;
}
// Linearly probes the hash table m_pEntries for a matching key pair (a, b) and returns the slot index, or mask+1 when not found.
// @fnv 0x00dc3920
unsigned int FUN_00dc3920_cls::FindEntry(unsigned int auiKey0, unsigned int auiKey1)
{
    int mask = m_iMask;
    if (mask > 0)
    {
        S_00dc3920_E* pEntries = m_pEntries;
        unsigned int idx = ((auiKey0 >> 4) * 0x9e3779b1u) & mask;
        S_00dc3920_E* e = &pEntries[idx];
        while (e->key0 != 0xffffffffu)
        {
            _ReadWriteBarrier();
            if (e->key0 == auiKey0 && e->key1 == auiKey1)
                return idx;
            idx = (idx + 1) & mask;
            e = &pEntries[idx];
        }
    }
    return mask + 1;
}

struct Member355
{
    const char* name;
    void* typeInfo;
    void* enumInfo;
    unsigned char type;
    unsigned char subtype;
    unsigned short fixedCount;
    unsigned short flags;
    unsigned short offset;
    __forceinline const char* getName() const throw()
    {
        return name;
    }
};
struct Class355
{
};
struct ClassHandle355
{
    void* impl;
    void* FUN_00dba680() throw();
    void FUN_00dba660() throw();
};
struct Object355;
struct Value355;
struct Array355
{
    void* impl;
    int FUN_00dbac00() throw();
    Value355 FUN_00dbab90(int index) throw();
    ~Array355() throw();
};
struct Value355
{
    void* impl;
    int index;
    Array355 GetResult() throw();
};
struct Object355
{
    void* impl;
    ClassHandle355* GetObjectValue(ClassHandle355* out) throw();
    int FUN_00dba910(const char* name) throw();
    ~Object355() throw();
};
struct Registry355
{
    virtual void f0() throw();
    virtual void f4() throw();
    virtual void f8() throw();
    virtual void fC() throw();
    virtual Class355* find(void* name) throw();
};
struct Allocator355
{
    virtual void f0() throw();
    virtual void f4() throw();
    virtual void f8() throw();
    virtual void* allocate(int& bytes) throw();
};
struct Router355
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator355* heap;
    static Router355& FUN_00c85750() throw();
    __forceinline Allocator355& getHeap() throw()
    {
        return *heap;
    }
};

struct Sequence355
{
    Class355* elementClass;
    char* data;
    int count;
};
struct Reader355
{
    Registry355* registry;
    S_00dc3ce0* tracker;
    int restricted;
    int ReadObject(char* destination, Object355* object) throw();
};
struct S_Heap
{
    virtual void* v0() throw();
    virtual void* alloc(unsigned int n) throw();
};
struct S_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_Heap* m10;
    S_Heap& heap()
    {
        return *m10;
    }
};
void* __cdecl FUN_00c85750() throw();
struct S_Heap;
inline S_Heap& S_heap()
{
    return ((S_Holder*)FUN_00c85750())->heap();
}
struct S_Blk
{
    int unk00;
    unsigned short sz;
};
struct S_Str
{
};
struct S_Key
{
    int a;
    int b;
};
struct S_Ent
{
    S_Key k;
    int v8;
};
struct S_Arr12 : FUN_00dc35e0_class
{
    S_Ent* data;
    int m4;
    int m8;
    int next(int i)
    {
        int j = i + 1;
        while (j <= m8 && data[j].k.a == -1)
            j++;
        return j;
    }
    S_Key GetIteratorKey(int i)
    {
        return data[i].k;
    }
    int getValue(int i)
    {
        return data[i].v8;
    }
};
struct S_Map
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_Obj
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int m8;
    int unk0c;
    S_Map m10;
};
struct S_PH;
struct S_X
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void v8() throw();
    virtual void v9() throw();
    virtual void v10(S_PH* out, S_Key* k) throw();
};
struct S_PH
{
    S_X* p;
    S_PH* GetObjectValue(S_PH* out);
    S_X* FUN_00dba6c0();
    const char* FUN_00dba680();
    void FUN_00dba660() throw();
};
struct S_Dom
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual S_Str* v4(const char* y) throw();
};
struct S_T2
{
    int f0;
    S_Str* f4;
};
struct S_Owner
{
    S_Obj* p;
    operator S_Obj*() const
    {
        return p;
    }
    S_Obj* operator->() const
    {
        return p;
    }
    void operator=(S_Obj* n)
    {
        if (p && p != n)
            reinterpret_cast<::hkReferencedObjectC905 *>((p))->FUN_00c905b0();
        p = n;
    }
};
struct S_Ctx
{
    S_Dom* m0;
    S_Owner m4;
    int m8;
    int unk0c;
    int unk10;
    int unk14;
    S_Arr12 m18;
    int unk24;
    int unk28;
    int unk2c;
    S_Ctx* Construct(S_Dom* d, int x) throw();
    ~S_Ctx() throw()
    {
        reinterpret_cast<::fnv_00dc43a0::FUN_00dc43a0 *>(this)->fnv_00dc43a0::FUN_00dc43a0::~FUN_00dc43a0();
    }
    __declspec(noalias) void FUN_00dc4430(S_T2* t, S_PH* h, int f) throw();
    void FUN_00dc43a0() throw();
};

__forceinline S_Obj* S_toResource(S_Ctx* context, S_PH* object) throw()
{
    S_Obj* result = 0;
    if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>((object))->FUN_00dba980())))
    {
        S_Obj* resource = (S_Obj*)S_heap().alloc(0x64);
        ((S_Blk*)resource)->sz = 0x64;
        S_Obj* replacement = ((::S_Obj *)(reinterpret_cast<::S00e05700_Class *>((resource))->FUN_00e05700()));
        context->m4 = replacement;
        S_T2 target;
        context->FUN_00dc4430(&target, object, 0);
        if (target.f0 && target.f4)
        {
            S_PH temporary;
            S_X* x = object->GetObjectValue(&temporary)->FUN_00dba6c0();
            ::FUN_00dba660();
            int index = context->m18.FUN_00dc35e0();
            while (index <= context->m18.m8)
            {
                S_Key key = context->m18.GetIteratorKey(index);
                S_PH value;
                x->v10(&value, &key);
                S_PH text;
                const char* name = value.GetObjectValue(&text)->FUN_00dba680();
                ::FUN_00dba660();
                S_Str* string = context->m0->v4(name);
                int number = context->m18.getValue(index);
                S_Obj* owner = context->m4;
                const char* keyName = reinterpret_cast<::FnvClassNameNode *>((string))->FUN_00d46d40();
                S_Heap& heap = S_heap();
                reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(&(owner->m10))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(&heap)), number, (uintptr_t)(keyName));
                reinterpret_cast<::DBA7F0Ref *>(&(value))->FUN_00dba7f0();
                index = context->m18.next(index);
            }
            S_Obj* owner = context->m4;
            const char* name = reinterpret_cast<::FnvClassNameNode *>((target.f4))->FUN_00d46d40();
            reinterpret_cast<::FUN_00e05100_cls *>((owner))->FUN_00e05100(target.f0, (intptr_t)(name));
            result = context->m4;
            reinterpret_cast<::FUN_00c90510_class *>((result))->FUN_00c90510();
            context->m4 = 0;
            return result;
        }
        context->m4 = 0;
    }
    return result;
}

// Constructs a context from domain and delegates to S_toResource to build an S_Obj from object.
// @fnv 0x00dc3300
S_Obj* __cdecl FUN_00dc3300(S_PH* object, S_Dom* domain) throw()
{
    S_Ctx context;
    S_Ctx* ctx = context.Construct(domain, 0);
    return S_toResource(ctx, object);
}

struct Object
{
    void* impl;
    Object() throw() : impl(0)
    {}
    ~Object() throw()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
};
struct Element
{
    void* array;
    int index;
    int FUN_00dbac40() const throw();
    int CallVirtualWithArg() const throw();
    float ApplyValue() const throw();
    const float* DispatchToVTableSlot8(int) const throw();
    const char* FUN_00dbac70() const throw();
};
struct ClonerStandin
{
    void* world;
    Object CloneObject(const Object&) throw();
    void FUN_00dc37f0(Element dst, const Element& src);
};
// Dispatches on the value returned by src.FUN_00dbac40() and invokes the corresponding destination method for handled cases.
// @fnv 0x00dc37f0
void ClonerStandin::FUN_00dc37f0(Element dst, const Element& src)
{

    switch (src.FUN_00dbac40())
    {
    case 1:
    case 2:
        reinterpret_cast<::fnv_00dbada0::Wrapper *>(&(dst))->InvokeOnInterface(src.CallVirtualWithArg());
        break;
    case 3:
        reinterpret_cast<::fnv_00dbad20::AudioHandle *>(&(dst))->FUN_00dbad20(src.ApplyValue());
        break;
    case 4:
    case 5:
    case 6:
    case 7: {
        int n = 4 * (src.FUN_00dbac40() - 3);
        reinterpret_cast<::FUN_00dbad60_cls *>(&(dst))->FUN_00dbad60((intptr_t)(src.DispatchToVTableSlot8(n)), n);
        break;
    }
    case 8:
    case 9: {
        reinterpret_cast<::FUN_00dbad00_cls *>(&(dst))->FUN_00dbad00((int *)&(const ::Object &)(CloneObject(&dst ? (*(::Object *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(src))->CreateValueInto({}))) : Object())));
        break;
    }
    case 10:
        reinterpret_cast<::DBADC0Binding *>(&(dst))->FUN_00dbadc0((void *)(src.FUN_00dbac70()));
        break;
    }
}

struct S_00dc4710_Alloc
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00dc4710_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00dc4710_Alloc* m_pStreamAllocator;
    S_00dc4710_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00dc4710_Ref
{
    virtual void v0();
    short m_iElementCount;
    short m_iObjectReferenceCount;
      // FUN_00c905b0
    static void* operator new(std::size_t n)
    {
        void* p = ((S_00dc4710_Router*)FUN_00c85750())->heap().AllocateMemoryBlock(n);
        ((S_00dc4710_Ref*)p)->m_iElementCount = (short)n;
        return p;
    }
    static void operator delete(void*)
    {}
};
struct S_00dc4710_Thing : S_00dc4710_Ref
{
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
    S_00dc4710_Thing() throw();  // FUN_00e05700
};
struct S_00dc4710_Key
{
    int a;
    int b;
};
struct S_00dc4710_Ret
{
    int p;
    int q;
};
struct S_00dc4710_Bool
{
    char b;
    S_00dc4710_Bool()
    {}
};

template <typename K, typename V> struct hkMap_dc4710
{
    struct Pair
    {
        K key;
        V val;
    };
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    typedef int Iterator;

    inline Iterator GetFirstIterator() const
    {
        int i = 0;
        int last = m_iPairCount;
        if (last >= 0)
        {
            Pair* p = m_kPrimitiveElement;
            do
            {
                if (p->key.a != -1)
                    break;
                i++;
                p++;
            } while (i <= last);
        }
        return i;
    }
    inline Iterator getNext(Iterator i) const
    {
        int last = m_iPairCount;
        i++;
        if (i <= last)
        {
            Pair* p = m_kPrimitiveElement + i;
            do
            {
                if (p->key.a != -1)
                    break;
                i++;
                p++;
            } while (i <= last);
        }
        return i;
    }
    inline bool isValid(Iterator i) const
    {
        return i <= m_iPairCount;
    }
    inline Pair& getPair(Iterator i) const
    {
        const Iterator& index = i;
        Pair* const& data = m_kPrimitiveElement;
        return data[index];
    }
    inline K GetIteratorKey(Iterator i) const
    {
        return getPair(i).key;
    }
    inline V getValue(Iterator i) const
    {
        __assume(m_kPrimitiveElement != 0);
        return getPair(i).val;
    }
};
struct S_00dc4710_ClassC
{
    S_00dc4710_Bool GetLastNodeFlag() throw();
};
struct S_00dc4710_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual S_00dc4710_ClassC* vf10(void* impl) throw();
};
struct S_00dc4710_ClassImpl;
struct S_00dc4710_Obj;
struct S_00dc4710_Class
{
    S_00dc4710_ClassImpl* m_pClassImpl;
    ~S_00dc4710_Class() throw();                        // FUN_00dba660
    S_00dc4710_ClassImpl* getImplementation() throw();  // FUN_00dba680
    struct S_00dc4710_World* FUN_00dba6c0() throw();
};
struct S_00dc4710_ObjImpl;
struct S_00dc4710_Obj
{
    S_00dc4710_ObjImpl* m_pClassImpl;
    ~S_00dc4710_Obj() throw();  // FUN_00dba7f0
    S_00dc4710_Class GetObjectValue() throw();
};
struct S_00dc4710_World
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual S_00dc4710_Obj vf28(const S_00dc4710_Key& k) throw();
};
struct S_00dc4710_Entry
{
    S_00dc4710_Key key;
    unsigned short* item;
};
struct S_00dc4710_Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* vf10(void* item, const char* name) throw();
};
struct S_00dc4710_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vc(int a, int id, const char* msg, const char* file, int line) throw();
};
struct S_00dc4710_Stream
{
    int unk0;
    int unk4;
    int unk8;
    S_00dc4710_Stream(char* b, int n) throw();  // FUN_00cb1600
    ~S_00dc4710_Stream() throw();               // FUN_00cc00e0
};
struct S_00dc4710_Result : S_00dc4710_Ref
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00dc4710_Result(const S_00dc4710_Ret& r) throw();  // Initialize
};
struct S_00dc4710_Map
{
    int unk0;
    int unk4;
    int unk8;
};
struct S_00dc4710_Cls
{
    S_00dc4710_Owner* m_pOwnerObject;
    S_00dc4710_Thing* m_thing;
    int unk08;
    S_00dc4710_Map m_map;
    hkMap_dc4710<S_00dc4710_Key, unsigned short*> m_entries;
    S_00dc4710_Ret FUN_00dc4430(S_00dc4710_Obj* a1, int one) throw();
    S_00dc4710_Result* FUN_00dc4710(S_00dc4710_Obj* a1, S_00dc4710_Sink* a2) throw();
};

// Creates a Result from a1, updates m_entries via m_map and m_pOwnerObject, and reports unregistered classes through DAT_01268360.
// @fnv 0x00dc4710
S_00dc4710_Result* S_00dc4710_Cls::FUN_00dc4710(S_00dc4710_Obj* apObj, S_00dc4710_Sink* apSink) throw()
{
    S_00dc4710_Thing* t = new S_00dc4710_Thing;
    if (m_thing && m_thing != t)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_thing))->FUN_00c905b0();
    m_thing = t;
    S_00dc4710_Ret ret = FUN_00dc4430(apObj, 1);
    S_00dc4710_World* world = apObj->GetObjectValue().FUN_00dba6c0();
    if (ret.p == 0)
    {
        m_thing->unk30 = 0;
        if (m_thing)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_thing))->FUN_00c905b0();
        m_thing = 0;
        return 0;
    }
    for (int i = m_entries.GetFirstIterator(); m_entries.isValid(i); i = m_entries.getNext(i))
    {
        S_00dc4710_Obj obj = world->vf28(m_entries.GetIteratorKey(i));
        S_00dc4710_ClassImpl* impl = obj.GetObjectValue().getImplementation();
        S_00dc4710_ClassC* c = m_pOwnerObject->vf10(impl);
        unsigned short* item = m_entries.getValue(i);
        unsigned short n = ((unsigned short)(reinterpret_cast<::FUN_00cb1930_t *>(&(m_map))->LookupHashEntry((intptr_t)(item), 0)));
        if ((short)n > 0)
        {
            item[2] = (unsigned short)reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((c))->FUN_00d470d0();
            item[3] = n;
        }
    }
    for (int i = m_entries.GetFirstIterator(); m_entries.isValid(i); i = m_entries.getNext(i))
    {
        S_00dc4710_Obj obj = world->vf28(m_entries.GetIteratorKey(i));
        S_00dc4710_ClassImpl* impl = obj.GetObjectValue().getImplementation();
        S_00dc4710_ClassC* c = m_pOwnerObject->vf10(impl);
        unsigned short* item = m_entries.getValue(i);
        void* r = apSink->vf10(item, reinterpret_cast<::FnvClassNameNode *>((c))->FUN_00d46d40());
        if (c->GetLastNodeFlag().b != 0 && r == 0)
        {
            unsigned int buf[128];
            S_00dc4710_Stream s((char*)buf, 512);
            reinterpret_cast<::SinkOwner *>(&((*(::S_00dc4710_Stream *)(reinterpret_cast<::SinkOwner *>(&((*(::S_00dc4710_Stream *)(reinterpret_cast<::SinkOwner *>(&(s))->FUN_00cc01c0("Cannot finish virtual object of class ")))))->FUN_00cc01c0(reinterpret_cast<::FnvClassNameNode *>((c))->FUN_00d46d40())))))->FUN_00cc01c0(". Please make sure the class is registered.");
            (*reinterpret_cast<::S_00dc4710_Err * *>(&::DAT_01268360))->vc(1, 0x7c303834, (const char*)buf, ".\\Data\\Util\\hkDataObjectUtil.cpp", 0x133);
        }
    }
    S_00dc4710_Result* pResult = new S_00dc4710_Result(ret);
    reinterpret_cast<::FUN_00e04eb0_class *>((pResult))->FUN_00e04eb0((::hkReferencedObject *)(m_pOwnerObject));
    reinterpret_cast<::fnv_00e04ee0::FUN_00e04ee0_class *>((pResult))->FUN_00e04ee0((::fnv_00e04ee0::hkReferencedObject *)(apSink));
    S_00dc4710_Thing* pThing = m_thing;
    pThing->unk30 = 0;
    pThing->unk38 = 0;
    pThing->unk44 = 0;
    if (m_thing)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_thing))->FUN_00c905b0();
    m_thing = 0;
    return pResult;
}

namespace fnv_00dc3d40 {
struct DObj
{
    int unk00;
    __forceinline ~DObj() throw()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
};
struct DArray;
struct DValue
{
    union
    {
        __int64 handle;
        struct
        {
            int unk00;
            int unk04;
        };
    };
    int CallVirtualWithArg() throw();
    float ApplyValue() throw();
    const float* DispatchToVTableSlot8(int n) throw();
    const char* FUN_00dbac70() throw();
    DArray FUN_00dbacd0() throw();
};
struct DMember
{
    const char* name;
    int unk04;
    unsigned int type;
    int unk0c;
    int tupleSize;
    __forceinline DMember() throw() : name(0), unk04(0), type(0), unk0c(0), tupleSize(0)
    {}
};
struct DAllocator
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
    virtual void ReturnMemory(void*, int) throw();
};
struct DMemory
{
    int unk00;
    int unk04;
    int unk08;
    DAllocator* heap;
    DAllocator& getHeap() throw()
    {
        return *heap;
    }
};
__declspec(restrict) void* __cdecl FUN_00c85750();
// hkMemoryAllocator::_bufAlloc<T>: the allocator may round the request up, the element count is updated
template <class T> __forceinline T* AllocateBufferWithSize(DAllocator& a, int& reqNumInOut) throw()
{
    int n = reqNumInOut * (int)sizeof(T);
    T* p = (T*)a.AllocateBufferWithSize(n);
    reqNumInOut = n / (int)sizeof(T);
    return p;
}
template <class T> __forceinline void construct(T* p, int n) throw()
{
    for (int i = 0; i < n; ++i)
        new (p + i) T();
}

// hkArray<MemberInfo>::Temp: hkArray(int n) constructs every allocated element (n is updated by _bufAlloc)
struct DMembers
{
    DMember* data;
    int size;
    int capacity;
    __forceinline DMembers(int n) throw() : data(0), size(0), capacity(0x80000000)
    {
        DAllocator& alloc = ((DMemory*)FUN_00c85750())->getHeap();
        DMember* p = n ? AllocateBufferWithSize<DMember>(alloc, n) : 0;
        int cap = n ? n : 0x80000000;
        data = p;
        size = n;
        capacity = cap;
        construct(data, size);
    }
    __forceinline void setSizeUnchecked(int n) throw()
    {
        construct(data + size, n - size);
        size = n;
    }
    __forceinline ~DMembers() throw()
    {
        DAllocator& a = ((DMemory*)FUN_00c85750())->getHeap();
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.ReturnMemory(data, (capacity & 0x3fffffff) * sizeof(DMember));
        data = 0;
        capacity = 0x80000000;
    }
};
struct DClass
{
    int impl;
    int FUN_00dba730() throw();
    void FUN_00dba660() throw();
    __forceinline ~DClass() throw()
    {
        ::FUN_00dba660();
    }
};
struct DArray
{
    int impl;
    int FUN_00dbac10() throw();
    int FUN_00dbac00() throw();
    DValue FUN_00dbabb0(int i) throw();
    DValue FUN_00dbab90(int i) throw();
    DClass FUN_00dbac20() throw();
    void FUN_00dbab70() throw();
    __forceinline ~DArray() throw()
    {
        reinterpret_cast<::FUN_00dbab70_cls *>(this)->FUN_00dbab70();
    }
};
struct DCloner
{
    DObj CloneObject(const DObj& o) throw();
    void FUN_00dc3d40(DArray& destination, const DArray& src, intptr_t n) throw();
};
// Copies n elements from source array to destination array, dispatching on element type to clone scalars, vectors, objects, classes, or strings.
// @fnv 0x00dc3d40
void DCloner::FUN_00dc3d40(DArray& destination, const DArray& source, intptr_t aiCount) throw()
{
    DArray& src = const_cast<DArray&>(source);
    switch (src.FUN_00dbac10())
    {
    case 1:
    case 2:
        for (int i = 0; i < aiCount; ++i)
            reinterpret_cast<::fnv_00dbada0::Wrapper *>((void *)&(const ::fnv_00dc3d40::DValue &)(destination.FUN_00dbab90(i)))->InvokeOnInterface(src.FUN_00dbabb0(i).CallVirtualWithArg());
        break;
    case 3:
        for (int i = 0; i < aiCount; ++i)
            reinterpret_cast<::fnv_00dbad20::AudioHandle *>((void *)&(const ::fnv_00dc3d40::DValue &)(destination.FUN_00dbab90(i)))->FUN_00dbad20(src.FUN_00dbabb0(i).ApplyValue());
        break;
    case 4:
    case 5:
    case 6:
    case 7: {
        int iVectorSize = (src.FUN_00dbac10() - 3) * 4;
        for (int i = 0; i < aiCount; ++i)
            reinterpret_cast<::FUN_00dbad60_cls *>((void *)&(const ::fnv_00dc3d40::DValue &)(destination.FUN_00dbab90(i)))->FUN_00dbad60((intptr_t)(src.FUN_00dbabb0(i).DispatchToVTableSlot8(iVectorSize)), iVectorSize);
        break;
    }
    case 8:
        reinterpret_cast<::DBABE0Binding *>(&(destination))->FUN_00dbabe0((void *)(aiCount));
        for (int i = 0; i < aiCount; ++i)
            reinterpret_cast<::FUN_00dbad00_cls *>((void *)&(const ::fnv_00dc3d40::DValue &)(destination.FUN_00dbab90(i)))->FUN_00dbad00((int *)&(const ::fnv_00dc3d40::DObj &)(CloneObject((*(::fnv_00dc3d40::DObj *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::fnv_00dc3d40::DValue &)(src.FUN_00dbabb0(i)))->CreateValueInto({}))))));
        break;
    case 9: {
        reinterpret_cast<::DBABE0Binding *>(&(destination))->FUN_00dbabe0((void *)(aiCount));
        DClass pClassInfo = src.FUN_00dbac20();
        int numMembers = pClassInfo.FUN_00dba730();
        DMembers members(numMembers);
        members.setSizeUnchecked(numMembers);
        reinterpret_cast<::S_00dbaed0_Obj *>(&(pClassInfo))->DispatchItems((::S_00dbaed0_Elem **)&(members));
        for (int iMemberIndex = 0; iMemberIndex < numMembers; ++iMemberIndex)
        {
            DMember& member = members.data[iMemberIndex];
            if (member.type & 15)
            {
                DArray dstMember = (*(::fnv_00dc3d40::DArray *)(reinterpret_cast<::FUN_00dbaea0_cls *>(&(destination))->InvokeCallbackInto((::FUN_00dbab50_cls *)(member.name), {})));
                DArray srcMember = (*(::fnv_00dc3d40::DArray *)(reinterpret_cast<::FUN_00dbaea0_cls *>(&(src))->InvokeCallbackInto((::FUN_00dbab50_cls *)(member.name), {})));
                if (member.type & 0x30)
                {
                    for (int i = 0; i < aiCount; ++i)
                    {
                        int iLength = (member.type & 0x10) ? dstMember.FUN_00dbab90(i).FUN_00dbacd0().FUN_00dbac00()
                                                           : member.tupleSize;
                        DArray dstNested = dstMember.FUN_00dbab90(i).FUN_00dbacd0();
                        FUN_00dc3d40(dstNested, srcMember.FUN_00dbab90(i).FUN_00dbacd0(), iLength);
                    }
                }
                else
                {
                    for (int i = 0; i < aiCount; ++i)
                    {
                        reinterpret_cast<::ClonerStandin *>(this)->FUN_00dc37f0((*(::Element *)&(const ::fnv_00dc3d40::DValue &)(dstMember.FUN_00dbab90(i))), (const ::Element &)((const ::fnv_00dc3d40::DValue &)(srcMember.FUN_00dbab90(i))));
                    }
                }
            }
        }
        break;
    }
    case 10:
        for (int i = 0; i < aiCount; ++i)
            reinterpret_cast<::DBADC0Binding *>((void *)&(const ::fnv_00dc3d40::DValue &)(destination.FUN_00dbab90(i)))->FUN_00dbadc0((void *)(src.FUN_00dbabb0(i).FUN_00dbac70()));
        break;
    }
}
}  // namespace fnv_00dc3d40

struct ArrayImpl;
struct MemberInfo
{
    const char* m_name;
    const char* m_pClassName;
    int m_type;
    void* m_valuePtr;
    intptr_t m_uiItemCount;
};

struct FUN_00dbab70
{
    ArrayImpl* m_pClassImpl;
    FUN_00dbab70() throw()
    {}
    ~FUN_00dbab70() throw();
    intptr_t FUN_00dbac00() const throw();
};

struct DataObject;
struct DataWorld
{
    virtual void vf0() throw();
    virtual void vf1() throw();
    virtual void vf2() throw();
    virtual void vf3() throw();
    virtual void vf4() throw();
    virtual ArrayImpl* m_ppNewArray(DataObject& obj, const MemberInfo& minfo) throw();
};

struct FUN_00dba660
{
    void* m_pClassImpl;
    ~FUN_00dba660() throw();
    DataWorld* FUN_00dba6c0() const throw();
};

struct DataValue
{
    void* m_pClassImpl;
    void* m_handle;
    FUN_00dbab70 GetResult() const throw();
};

struct DataObject
{
    void* m_pClassImpl;
    FUN_00dba660 GetObjectValue() const throw();
    DataValue* FUN_00dba890(DataValue* out, const char* name) const throw();
    DataValue FUN_00dba890(const char* name) const throw();
};

struct ValueCloner
{
    void FUN_00dc4210(DataObject& dstObj, const DataObject& srcObj, const MemberInfo& minfo) throw();
};

template <class T> struct CheckedReference
{
    T* value;
    CheckedReference(T& object) throw() : value(&object)
    {}
    ~CheckedReference() throw()
    {}
    operator T&() const throw()
    {
        return *value;
    }
};
// Clones a data member from srcObj to dstObj based on minfo.m_type, handling arrays and plain values.
// @fnv 0x00dc4210
void ValueCloner::FUN_00dc4210(DataObject& dstObj, const DataObject& srcObj, const MemberInfo& minfo) throw()
{
    DataValue v;

    if (minfo.m_type & 0x20)
    {
        FUN_00dbab70 srcArray =
            ((const DataObject&)((minfo.m_type & 0x20) ? CheckedReference<const DataObject>(srcObj)
                                                       : CheckedReference<const DataObject>(srcObj)))
                .FUN_00dba890(&v, minfo.m_name)
                ->GetResult();
        FUN_00dbab70 dstArray;
        new ((void *)&(dstArray)) ::FUN_00dbab50((::DBAB50Object *)(::ArrayImpl *)(dstObj.GetObjectValue().FUN_00dba6c0()->m_ppNewArray(dstObj, minfo)));
        reinterpret_cast<::DBABE0Binding *>(&(dstArray))->FUN_00dbabe0((void *)(minfo.m_uiItemCount));
        reinterpret_cast<::fnv_00dc3d40::DCloner *>(this)->FUN_00dc3d40((::fnv_00dc3d40::DArray &)(dstArray), (const ::fnv_00dc3d40::DArray &)(srcArray), minfo.m_uiItemCount);
    }
    else if (minfo.m_type & 0x10)
    {
        FUN_00dbab70 srcArray = srcObj.FUN_00dba890(&v, minfo.m_name)->GetResult();
        FUN_00dbab70 dstArray;
        new ((void *)&(dstArray)) ::FUN_00dbab50((::DBAB50Object *)(::ArrayImpl *)(dstObj.GetObjectValue().FUN_00dba6c0()->m_ppNewArray(dstObj, minfo)));
        reinterpret_cast<::DBABE0Binding *>(&(dstArray))->FUN_00dbabe0((void *)(srcArray.FUN_00dbac00()));
        reinterpret_cast<::fnv_00dc3d40::DCloner *>(this)->FUN_00dc3d40((::fnv_00dc3d40::DArray &)(dstArray), (const ::fnv_00dc3d40::DArray &)(srcArray), srcArray.FUN_00dbac00());
    }
    else
    {
        reinterpret_cast<::FUN_00dba870_cls *>(&(dstObj))->FUN_00dba870(&v, (void *)(minfo.m_name));
        reinterpret_cast<::ClonerQ *>(this)->CopyValue((*(::ValueQ *)&(const ::DataValue &)(v)), (const ::ValueQ &)((const ::DataValue &)(srcObj.FUN_00dba890(minfo.m_name))));
    }
}

extern "C" void _ReadWriteBarrier();
struct AllocatorVtbl;
__declspec(restrict) void* __cdecl FUN_00c85750() throw();
struct DC4430Memory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorVtbl* m_pStreamAllocator;
    __forceinline S_00dc3ce0_Allocator& heap() throw()
    {
        return *(S_00dc3ce0_Allocator*)m_pStreamAllocator;
    }
};
struct FlagBool
{
    char value;
    FlagBool()
    {}
    ~FlagBool() throw()
    {}
    FlagBool(bool b) : value(b)
    {}
    __forceinline operator bool() const throw()
    {
        return value != 0;
    }
};

struct Key64
{
    union
    {
        unsigned __int64 val;
        struct
        {
            unsigned int low, high;
        };
    };
    __forceinline bool operator==(const Key64& o) const throw()
    {
        return low == o.low && high == o.high;
    }
};

struct DObjWrap
{
    void* m_ptr;
    ~DObjWrap() throw();
    int FUN_00dba680() throw();
    int FUN_00dba690() throw();
};

struct ObjB
{
    FlagBool GetLastNodeFlag() throw();
};

struct ObjA
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual ObjB* v10(int arg) throw();
};

struct Arg1
{
    DObjWrap GetObjectValue() throw();
    Key64* GetSourcePair(Key64* out) throw();
};

struct KeyArray
{
    Key64* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline int indexOf(const Key64& key) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    __forceinline void AddBack(S_00dc3ce0_Allocator& alloc, const Key64& e) throw()
    {
        if (m_iElementCount == getCapacity())
        {
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(Key64));
        }
        new (m_data + m_iElementCount) Key64(e);
        m_iElementCount++;
    }

    __forceinline void AddBack(const Key64& e) throw()
    {
        AddBack((*(DC4430Memory*)FUN_00c85750()).heap(), e);
    }

    __forceinline void popBack() throw()
    {
        m_iElementCount--;
    }
};

struct Map18
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

};

struct Pair0C
{
    void* key;
    int val;
};

struct Map0C
{
    Pair0C* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

};

class GlobalObjectO2_00d472a0
{
  public:
    FlagBool FUN_00d46d80(ObjB* obj) throw();
};

extern "C" void* __cdecl _FUN_00cb1280(void*, int, unsigned int) throw();

struct AllocatorVtbl
{
    virtual void v00() throw();
    virtual void* allocate(int size) throw();
};

struct RetDC4430
{
    void* first;
    ObjB* second;
};

struct DC4430_Class
{
    ObjA* m_obj00;
    S_00dc3ce0* m_obj04;
    int m_unk08;
    Map0C m_map0c;
    Map18 m_map18;
    KeyArray m_ppData;

    RetDC4430 FUN_00dc4430(Arg1* arg1, intptr_t arg2) throw();
};
// Reads a value of the given type from reader into out, returning 1 on failure.
// @fnv 0x00dc4a80
int S_00dc4a80::ReadValue(void* out, int type, S_00dc4a80_Reader* reader, intptr_t aiFlag3, int arg4) throw()
{
    switch (type)
    {
    case 1:
        *(bool*)out = (reader->CallVirtualWithArg() != 0);
        return 0;
    case 2:
        *(unsigned char*)out = (unsigned char)reader->CallVirtualWithArg();
        return 0;
    case 3:
        *(char*)out = (char)reader->CallVirtualWithArg();
        return 0;
    case 4:
        *(unsigned char*)out = (unsigned char)reader->CallVirtualWithArg();
        return 0;
    case 5:
        *(short*)out = (short)reader->CallVirtualWithArg();
        return 0;
    case 6:
        *(unsigned short*)out = (unsigned short)reader->CallVirtualWithArg();
        return 0;
    case 7:
        *(int*)out = reader->CallVirtualWithArg();
        return 0;
    case 8:
        *(unsigned int*)out = (unsigned int)reader->CallVirtualWithArg();
        return 0;
    case 9:
        *(__int64*)out = reader->CallVirtualWithArg();
        return 0;
    case 10:
        *(unsigned __int64*)out = reader->CallVirtualWithArg();
        return 0;
    case 30:
        *(unsigned long*)out = (unsigned long)reader->CallVirtualWithArg();
        return 0;
    case 11:
        *(float*)out = reader->ApplyValue();
        return 0;
    case 32: {
        float f = reader->ApplyValue();
        *(short*)out = (short)(*(int*)&f >> 16);
        return 0;
    }
    case 20:
        if (aiFlag3)
        {
            S_00dc5970_Object obj = (*(::S_00dc5970_Object *)(reinterpret_cast<::FUN_00dbaca0_cls *>((reader))->CreateValueInto({})));
            if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(obj))->FUN_00dba980())))
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                reinterpret_cast<::DC4430_Class *>(this)->FUN_00dc4430((::Arg1 *)(::S_00dc5970_Handle *)(&h), (intptr_t)&(obj));
                if (!h.p0)
                {
                    return 1;
                }
                *(void**)out = h.p0;
            }
        }
        break;
    case 25:
        if (aiFlag3)
        {
            bool err;
            if (err = (reinterpret_cast<::Reader355 *>(this)->ReadObject((char *)(out), (::Object355 *)&(const ::S_00dc5970_Object &)((*(::S_00dc5970_Object *)(reinterpret_cast<::FUN_00dbaca0_cls *>((reader))->CreateValueInto({}))))) == 1))
            {
                return 1;
            }
        }
        break;
    case 12:
        *(__m128*)out = *(__m128*)reader->DispatchToVTableSlot8(4);
        return 0;
    case 13:
        *(__m128*)out = *(__m128*)reader->DispatchToVTableSlot8(4);
        return 0;
    case 14:
        reinterpret_cast<::FUN_00c6cd00_cls *>((((S_00dc4a80_M3*)out)))->FUN_00c6cd00((const ::FUN_00c6cd00_cls *)(void *)(reader->DispatchToVTableSlot8(12)));
        return 0;
    case 15:
        reinterpret_cast<::S48 *>((((S_00dc4a80_Rot*)out)))->CopyFromFloatArray((const float *)(void *)(reader->DispatchToVTableSlot8(12)));
        return 0;
    case 16:
        reinterpret_cast<::S48 *>((((S_00dc4a80_QsTr*)out)))->CopyFromFloatArray((const float *)(void *)(reader->DispatchToVTableSlot8(12)));
        return 0;
    case 17:
        reinterpret_cast<::DC3710Transform *>((((S_00dc4a80_M4*)out)))->FUN_00dc3710((*(const ::DC3710Transform *)(reader->DispatchToVTableSlot8(16))));
        return 0;
    case 18:
        reinterpret_cast<::hkMatrix4CD60 *>((((S_00dc4a80_Tr*)out)))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(reader->DispatchToVTableSlot8(16))));
        return 0;
    case 29: {
        if (unk08)
        {
            return 1;
        }
        char* copy;
        if (reader->FUN_00dbac70())
        {
            copy = FUN_00cb1410(reader->FUN_00dbac70());
            unk04->m_pStringFunctions.AddBack(copy);
        }
        else
        {
            copy = 0;
        }
        *(char**)out = copy;
        return 0;
    }
    case 33: {
        intptr_t val;
        if (reader->FUN_00dbac70())
        {
            char* copy = FUN_00cb1410(reader->FUN_00dbac70());
            unk04->m_pStringFunctions.AddBack(copy);
            val = (intptr_t)copy;
        }
        else
        {
            val = 0;
        }
        *(int*)out = val;
        if (unk08)
        {
            *(int*)out = val | 1;
            return 0;
        }
        break;
    }
    case 28:
        if (unk08)
        {
            return 1;
        }
        {
            S_00dc5970_Object obj = (*(::S_00dc5970_Object *)(reinterpret_cast<::FUN_00dbaca0_cls *>((reader))->CreateValueInto({})));
            if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(obj))->FUN_00dba980())))
            {
                __declspec(align(8)) S_00dc5970_Handle h;
                reinterpret_cast<::DC4430_Class *>(this)->FUN_00dc4430((::Arg1 *)(::S_00dc5970_Handle *)(&h), (intptr_t)&(obj));
                if (!h.p0)
                {
                    return 1;
                }
                *(S_00dc5970_Handle*)out = h;
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}

// Looks up or allocates a Map18 entry for arg1's key, optionally tracking it in m_ppData and m_map0c, returning the entry pointer and class info.
// @fnv 0x00dc4430
RetDC4430 DC4430_Class::FUN_00dc4430(Arg1* apArg, intptr_t aiFlag) throw()
{
    RetDC4430 result;
    result.first = 0;

    long ret;
    if (m_unk08)
    {
        ret = 1;
        if (!aiFlag)
        {
            ret = 0;
        }
    }

    else
    {
        ret = 0;
    }

    _ReadWriteBarrier();
    result.second = 0;
    if (!((int)(reinterpret_cast<::FUN_00dba980_cls *>((apArg))->FUN_00dba980())))
    {

        if (((int)(reinterpret_cast<::CpuObject *>((void *)&(const ::DObjWrap &)(apArg->GetObjectValue()))->FUN_00dba670())) || !apArg->GetObjectValue().FUN_00dba680())
        {
            result.second = 0;
            return result;
        }

        Key64 key;
        if (ret)
        {
            if (m_ppData.indexOf(*apArg->GetSourcePair(&key)) != -1)
            {
                RetDC4430 size;
                size.first = 0;
                size.second = 0;
                return size;
            }
            m_ppData.AddBack(*apArg->GetSourcePair(&key));
        }

        ObjA* world = m_obj00;
        ObjB* pClassInfo = world->v10(apArg->GetObjectValue().FUN_00dba680());

        result.first = ((void *)(reinterpret_cast<::FUN_00dc36b0_cls *>(&(m_map18))->Lookup(apArg->GetSourcePair(&key)->val, (unsigned int)(0), {})));
        if (result.first == 0)
        {
            (apArg->GetObjectValue().FUN_00dba690(), reinterpret_cast<::hkClassD47120 *>((pClassInfo))->FUN_00d47120());
            int mem = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((pClassInfo))->FUN_00d470d0();
            DC4430Memory* memory = (DC4430Memory*)FUN_00c85750();
            AllocatorVtbl* heap = memory->m_pStreamAllocator;
            result.first = heap->allocate(mem);
            m_obj04->AddEntry((intptr_t)result.first, mem, 6);
            _FUN_00cb1280(result.first, 0, reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((pClassInfo))->FUN_00d470d0());

            Key64 temp;
            Key64* __restrict pReturnedKey = apArg->GetSourcePair(&temp);
            Key64* __restrict destination = &key;
            *destination = *pReturnedKey;
            reinterpret_cast<::DC3600Map *>(&(m_map18))->InsertKeyValue((::DC3600Allocator &)((*(DC4430Memory*)FUN_00c85750()).heap()), (::DC3600Key)(key.val), (intptr_t)(result.first));

            if (reinterpret_cast<::Reader355 *>(this)->ReadObject((char *)(result.first), (::Object355 *)(apArg)) == 1)
            {
                result.first = 0;
                pClassInfo = 0;
            }
        }

        if (0 != result.first)
        {
            if (ret)
            {

                if (pClassInfo->GetLastNodeFlag() && g_01268748.FUN_00d46d80(pClassInfo))
                {
                    int b = reinterpret_cast<::hkMapBaseCB1F *>(&(m_map0c))->FUN_00cb1f40((::hkMemoryAllocatorCB1F &)((*(DC4430Memory*)FUN_00c85750()).heap()), (uintptr_t)(result.first), 0);
                    m_map0c.m_kPrimitiveElement[b].val++;
                }
            }
        }

        if (ret)
        {
            m_ppData.popBack();
        }

        result.second = pClassInfo;
    }
    return result;
}

struct DBool_dc3a80
{
    char m_cBooleanValue;
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};
struct DKlass_dc3a80
{
    DBool_dc3a80 FUN_00d46d80(const DKlass_dc3a80* other) throw();
};
struct DClass_dc3a80
{
    void* m_pClassImpl;
    const char* FUN_00dba680() const throw();
    void FUN_00dba660() throw();
    __forceinline ~DClass_dc3a80() throw()
    {
        ::FUN_00dba660();
    }
};
struct DObj_dc3a80
{
    int unk00;
    DClass_dc3a80 GetObjectValue() const throw();
};
struct DAttribute_dc3a80
{
    void** unk00;
};
struct DMember_dc3a80
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned short unk0E;
    unsigned short unk10;
};
struct DWorld_dc3a80
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual DKlass_dc3a80* GetClassFromName(const char* name) throw();
};
struct DReader_dc3a80
{
    DWorld_dc3a80* unk00;
    void* unk04;
    int unk08;
    DKlass_dc3a80* FUN_00dc3a80(const DMember_dc3a80* member, const DObj_dc3a80& obj) throw();
};
// Deserializes an Object355 into destination by iterating class members and dispatching on member type, returning 1 on failure.
// @fnv 0x00dc2d60
int Reader355::ReadObject(char* destination, Object355* object) throw()
{
    int result = 0;
    ClassHandle355 classHandle;
    void* name = object->GetObjectValue(&classHandle)->FUN_00dba680();
    ::FUN_00dba660();
    Class355* type = registry->find(name);
    if (!type)
        goto finished;
    do
    {
        for (int memberIndex = 0; memberIndex < reinterpret_cast<::FUN_00d46f70_cls *>((type))->FUN_00d46f70(); ++memberIndex)
        {
            Member355* member = ((::Member355 *)(reinterpret_cast<::FUN_00d46f80_class *>((type))->FUN_00d46f80(memberIndex)));
            char* output = destination + member->offset;
            if (!object->FUN_00dba910(member->getName()))
            {
                if (member->type == 22)
                    ((Sequence355*)output)->count = 0x80000000;
                continue;
            }
            Value355 value = (*(::Value355 *)(reinterpret_cast<::FUN_00dba870_cls *>((object))->FUN_00dba870((void *)(member->getName()), {})));
            int count = reinterpret_cast<::OwnerD869 *>((member))->FUN_00d86940();
            if (!count)
                count = 1;
            int stride = reinterpret_cast<::ClassMember_d869 *>((member))->FUN_00d86980() / count;
            unsigned char kind = member->type;
            int owned = ((unsigned short)~member->flags >> 9) & 1;
            switch (kind)
            {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 25:
            case 28:
            case 29:
            case 30:
            case 32:
            case 33:
                if (count == 1)
                {
                    result = reinterpret_cast<::fnv_00dc4fa0::S_00dc4fa0 *>(this)->FUN_00dc4fa0(output, kind, (::fnv_00dc4fa0::S_00dc4fa0_Reader *)(::Value355 *)(&value), (intptr_t)(((void *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()))), owned);
                }
                else
                {
                    Array355 array = value.GetResult();
                    for (int i = 0; i < array.FUN_00dbac00() && !result; ++i, output += stride)
                    {

                        result = reinterpret_cast<::S_00dc4a80 *>(this)->ReadValue(output, kind, (::S_00dc4a80_Reader *)(::Value355 *)(&array.FUN_00dbab90(i)), (intptr_t)(((void *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()))), owned);
                    }
                }
                break;
            case 22:
            case 26: {
                if (restricted && ((unsigned char)kind == 26 || member->subtype == 28 || member->subtype == 29))
                    goto failed;
                result = reinterpret_cast<::DReader *>(this)->ReadArray((::DOutArray *)(output), (::DMember *)(member), (::DArray *)(::Array355 *)(&value.GetResult()));
                break;
            }
            case 20:
                if (member->subtype == 2)
                {
                    if (count == 1)
                        result = reinterpret_cast<::fnv_00dc4fa0::S_00dc4fa0 *>(this)->FUN_00dc4fa0(output, 29, (::fnv_00dc4fa0::S_00dc4fa0_Reader *)(::Value355 *)(&value), (int)(0), owned);
                    else
                    {
                        Array355 array = value.GetResult();
                        for (int i = 0; i < array.FUN_00dbac00() && !result; ++i)
                        {

                            result = reinterpret_cast<::S_00dc4a80 *>(this)->ReadValue(output, 29, (::S_00dc4a80_Reader *)(::Value355 *)(&array.FUN_00dbab90(i)), (int)(0), owned);
                            output += stride;
                        }
                    }
                }
                else if (member->subtype == 25)
                {
                    if (count == 1)
                    {

                        result = reinterpret_cast<::fnv_00dc4fa0::S_00dc4fa0 *>(this)->FUN_00dc4fa0(output, kind, (::fnv_00dc4fa0::S_00dc4fa0_Reader *)(::Value355 *)(&value), (intptr_t)(((::Class355 *)(reinterpret_cast<::DReader_dc3a80 *>(this)->FUN_00dc3a80((const ::DMember_dc3a80 *)(member), (*(const ::DObj_dc3a80 *)(&(*(::Object355 *)(reinterpret_cast<::FUN_00dba9d0_cls *>(&(value))->FUN_00dba9d0({}))))))))), owned);
                    }
                    else
                    {
                        Array355 array = value.GetResult();
                        for (int i = 0; i < array.FUN_00dbac00() && !result; ++i, output += stride)
                        {

                            result = reinterpret_cast<::S_00dc4a80 *>(this)->ReadValue(output, kind, (::S_00dc4a80_Reader *)(::Value355 *)(&array.FUN_00dbab90(i)),
                                               (intptr_t)(((::Class355 *)(reinterpret_cast<::DReader_dc3a80 *>(this)->FUN_00dc3a80((const ::DMember_dc3a80 *)(member), (*(const ::DObj_dc3a80 *)(&(*(::Object355 *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::Value355 &)(array.FUN_00dbab90(i)))->CreateValueInto({}))))))))), owned);
                        }
                    }
                }
                break;
            case 24:
            case 31:
                result = ((int)(::FUN_00dc1bf0((intptr_t)this, (intptr_t)(output), (intptr_t)(member), (intptr_t)(&value))));
                break;
            case 27: {
                if (restricted)
                    goto failed;
                Array355 array = value.GetResult();

                Sequence355* sequence = (Sequence355*)output;
                sequence->elementClass = ((::Class355 *)(reinterpret_cast<::DReader_dc3a80 *>(this)->FUN_00dc3a80((const ::DMember_dc3a80 *)(member), (*(const ::DObj_dc3a80 *)(&(*(::Object355 *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::Value355 &)(array.FUN_00dbab90(0)))->CreateValueInto({}))))))));

                sequence->count = array.FUN_00dbac00();
                int elementSize = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((sequence->elementClass))->FUN_00d470d0();
                {
                    int bytes = sequence->count * elementSize;
                    sequence->data = AllocElems<char>(bytes);
                    FUN_00cb1280(sequence->data, 0, bytes);
                }
                tracker->AddEntry((intptr_t)sequence->data, sequence->count * elementSize, 6);
                int i = 0;
                if (i < sequence->count)
                {
                    int offset = 0;
                    for (; i < sequence->count && !result; ++i, offset += elementSize)
                    {
                        char* elementDestination = sequence->data + offset;

                        result = ReadObject(elementDestination, &(*(::Object355 *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::Value355 &)(array.FUN_00dbab90(i)))->CreateValueInto({}))));
                    }
                }
                break;
            }
            default:
                goto failed;
            }
            if (result == 1)
                goto failed;
        }
        type = ((::Class355 *)(reinterpret_cast<::ReflectObj *>((type))->FUN_00d46d50()));
    } while (type);
    goto finished;
failed:
    return 1;
finished:
    return result;
}
// Resolves the DKlass for a DMember by comparing the object's class name against the expected class and the hk.DataObjectType attribute.
// @fnv 0x00dc3a80
DKlass_dc3a80* DReader_dc3a80::FUN_00dc3a80(const DMember_dc3a80* member, const DObj_dc3a80& obj) throw()
{
    if (((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(obj))->FUN_00dba980())))
        return 0;
    DKlass_dc3a80* pExpectedClass = ((::DKlass_dc3a80 *)(reinterpret_cast<::Struct_d86920 *>((void *)(member))->FUN_00d86920()));
    const char* name = obj.GetObjectValue().FUN_00dba680();
    DKlass_dc3a80* pActualClass = name ? unk00->GetClassFromName(name) : 0;
    if (!pExpectedClass)
        return pActualClass;
    if (!pActualClass)
        return 0;
    if (!::fnv_00cb0fa0::FUN_00cb0fa0(reinterpret_cast<::FnvClassNameNode *>((pExpectedClass))->FUN_00d46d40(), name))
        return pExpectedClass;
    if (pExpectedClass->FUN_00d46d80(pActualClass))
        return pActualClass;
    DAttribute_dc3a80* pAttribute = ((::DAttribute_dc3a80 *)(reinterpret_cast<::hkClassMember_FUN_00d86960 *>((void *)(member))->FUN_00d86960("hk.DataObjectType")));
    if (pAttribute)
    {
        const char* pcTypeName = (const char*)*pAttribute->unk00;
        pExpectedClass = unk00->GetClassFromName(pcTypeName);
        if (pExpectedClass->FUN_00d46d80(pActualClass))
            return pActualClass;
    }
    return pExpectedClass;
}

#include "generated/data/havok/common/serialize/data/util/hkdataobjectutil.inc"
