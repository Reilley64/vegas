
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <windows.h>
#include <new>
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/FUN_00c86490_Class.h"
#include "fnv/decl/FUN_00cb18f0_t.h"
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00ddcc60.h"
#include "fnv/decl/FUN_00ddccb0_cls.h"
#include "fnv/decl/S_00dd9380.h"
#include "fnv/decl/SearchArray.h"
#include "fnv/decl/fnv_00c93820__hkpWorldC938.h"
#include "fnv/decl/fnv_00c93920__hkpWorldXc93920.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/decl/hkWorldC917.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_010cc000.h"
#include "fnv/symbols_010d1000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
struct FUN_00d65970_stub
{
};
struct FUN_00d65f70_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00d65f70();
};
struct S_00c6d840_Pair
{
    int m_kPointA;
    int m_kPointB;
    S_00c6d840_Pair(int a, int b) : m_kPointA(a), m_kPointB(b)
    {}
};

struct S_00c6d840_Entry
{
    int m_key;
    int unk04;
    S_00c6d840_Pair m_uiFilterValue;
};

struct S_00c6d840
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    S_00c6d840_Entry* m_entries;
    int m_uiItemCount;
    S_00c6d840_Pair FindEntry(int key, int unused);
};

// @fnv 0x00c6d840
S_00c6d840_Pair S_00c6d840::FindEntry(int key, int unused)
{
    for (int i = 0; i < m_uiItemCount; i++)
    {
        if (m_entries[i].m_key == key)
        {
            return m_entries[i].m_uiFilterValue;
        }
    }
    return S_00c6d840_Pair(0, 0);
}

struct FUN_00cb1a60_t
{
    void ResetEntries();
};

struct FUN_00d653e0_cls
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
    FUN_00cb1a60_t sub54;
    void FUN_00d653e0();
};

// @fnv 0x00d653e0
void FUN_00d653e0_cls::FUN_00d653e0()
{
    sub54.ResetEntries();
}

struct FUN_00d655e0_Item
{
    int key;
};
struct FUN_00d655e0_class
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
    FUN_00d655e0_Item** items30;
    int count34;
    int FindItemIndex(int key);
};
// Scans the items array for an entry whose key equals key and returns its index, or -1 if none matches.
// @fnv 0x00d655e0
int FUN_00d655e0_class::FindItemIndex(int key)
{
    for (int i = 0; i < count34; ++i)
        if (items30[i]->key == key)
            return i;
    return -1;
}

struct Allocator
{
    virtual void reserved();
    virtual void* allocate(unsigned int);
};
struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
static inline void* getMemoryRouter() { return ::FUN_00c85750(); }
struct FUN_00d657d0_class
{
    FUN_00d657d0_class* FUN_00d657d0(int);
};
// Allocates a 0x74-byte object from the audio allocator, initializes it with context, and returns a pointer 8 bytes into it, or null on failure.
// @fnv 0x00d65910
void* __cdecl FUN_00d65910(void* context)
{
    BSAudio* audio = (BSAudio*)getMemoryRouter();
    FUN_00d657d0_class* result = (FUN_00d657d0_class*)audio->allocator->allocate(0x74);
    *(unsigned short*)((char*)result + 4) = 0x74;
    result = result->FUN_00d657d0((int)context);
    if (result)
        return (char*)result + 8;
    return 0;
}

struct FUN_00dd9380_class
{
};
struct hkProcessFactory : FUN_00dd9380_class
{
};
struct GlobalObjectO2_00d472a0
{
};
extern void* __cdecl FUN_00d65910(void*);

// @fnv 0x00d65950
void RegisterShapesProcess()
{
    void* process = ((void *)(reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::hkProcessFactory * *>(&::DAT_01269cd0))))->FUN_00dd9380("Shapes", (int)((void*)&FUN_00d65910))));
    *(void**)((char*)&::g_01268f2c + 0xB4) = process;
}

struct Target
{
};
struct Adjustor
{
    void FUN_00d65fb0();
};

// @fnv 0x00d661d0
int __cdecl FUN_00d661d0()
{
    return ::DAT_01268fe0;
}

struct FUN_00d652a0_cls
{
    virtual void v00() = 0;
    virtual void v04() = 0;
    virtual void v08() = 0;
    virtual void v0c() = 0;
    virtual void v10(int a, int b) = 0;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    void FUN_00d652a0(int arg);
};

// @fnv 0x00d652a0
void FUN_00d652a0_cls::FUN_00d652a0(int arg)
{
    v10(m_18, arg);
}


struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

struct BSAudio;

struct SpawnedBuf
{
    int unk00;
    int unk04;
    int unk08;

};

struct FUN_00d66080_cls
{
    int m_vptr00;
    int unk04;
    int m_vptr08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_vptr20;
    int unk24;
    int m_vptr28;
    int m_vptr2c;
    int* m_pData;
    int m_iArrayLength;
    unsigned int m_uiObjectFlags;
    SpawnedBuf m_buf3c;
    SpawnedBuf m_buf48;
    SpawnedBuf m_buf54;

    void Destroy();
};

struct OwnerObject
{
};

struct FUN_00d66160_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00d66160(int arg);
};

struct D66180PropertyValue
{
    void* m_ptr;
    int m_extra;

    D66180PropertyValue()
    {}
};

struct D66180Property
{
    unsigned int m_key;
    int m_uiAlignmentPadding;
    int m_value0;
    int m_value1;
};

struct D66180Entity
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    D66180Property* m_kProperties;
    int m_iPropertyCount;

    D66180PropertyValue getProperty(unsigned int key, void* lockCheck = 0) const;
};

// Scans the entity's property array for key 0x1134 and returns that property's pointer, or a pointer to unk10 if not found.
// @fnv 0x00d66180
void* __cdecl GetProperty1134(D66180Entity* entity)
{
    for (int i = 0; i < entity->m_iPropertyCount; i++)
    {
        if (entity->m_kProperties[i].m_key == 0x1134)
            return entity->getProperty(0x1134).m_ptr;
    }
    return &entity->unk10;
}

struct SpawnAlloc
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnAlloc* m_pAllocator;
};

struct SpawnSub
{
    virtual void v00();
    virtual void v04(void* p);
};

struct SpawnList
{
    void** m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

struct SpawnOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char* m_20;
    int unk24;
    char** m_28;
    int m_2c;
    int unk30;
    char** m_34;
    int m_38;

};

struct SpawnSublist
{
    void** m_data;
    int m_uiItemCount;
};


struct PendingNode
{
    SpawnOwner* m_pSharedOwner;
    int m_04;
    int m_08;
    unsigned int m_0c;

    PendingNode()
    {
        m_04 = 0;
        m_08 = 0;
        m_0c = 0x80000000u;
    }
    void* operator new(size_t size) throw()
    {
        AllocHolder* holder = (AllocHolder*)getMemoryRouter();
        SpawnAlloc* alloc = holder->m_pAllocator;
        return alloc->Alloc(size);
    }
};

template <class T> inline void hkArrayConstruct(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

struct FUN_00d64650_cls
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
    SpawnSub m_28;
    int m_2c;
    SpawnList m_30;

    void FUN_00d64650(SpawnOwner* a1);
};

// @fnv 0x00d64650
void FUN_00d64650_cls::FUN_00d64650(SpawnOwner* apOwner)
{
    void* pSubA;
    if (this != 0)
    {
        pSubA = &m_28;
    }
    else
    {
        pSubA = 0;
    }
    reinterpret_cast<::fnv_00c93820::hkpWorldC938 *>((apOwner))->FUN_00c93820((::fnv_00c93820::hkpEntityListenerC938 *)(pSubA));
    void* pSubB;
    if (this != 0)
    {
        pSubB = &m_2c;
    }
    else
    {
        pSubB = 0;
    }
    reinterpret_cast<::fnv_00c93920::hkpWorldXc93920 *>((apOwner))->FUN_00c93920((::fnv_00c93920::hkpEntityListenerXc93920 *)(pSubB));

    PendingNode* node = new PendingNode();
    node->m_pSharedOwner = apOwner;

    SpawnList* list = &m_30;
    AllocHolder* holder = (AllocHolder*)getMemoryRouter();
    if (list->m_uiItemCount == (int)(list->m_capBits & 0x3fffffffu))
    {
        ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(list), 4);
    }
    hkArrayConstruct((PendingNode**)list->m_data + list->m_uiItemCount, 1, node);
    list->m_uiItemCount++;

    for (int i = 0; i < apOwner->m_2c; i++)
    {
        char* item = apOwner->m_28[i];
        SpawnSublist* pSublist = (SpawnSublist*)(item + 0x48);
        for (int j = 0; j < pSublist->m_uiItemCount; j++)
        {
            m_28.v04(pSublist->m_data[j]);
        }
    }

    for (int i = 0; i < apOwner->m_38; i++)
    {
        char* item = apOwner->m_34[i];
        SpawnSublist* pSublist = (SpawnSublist*)(item + 0x48);
        for (int j = 0; j < pSublist->m_uiItemCount; j++)
        {
            m_28.v04(pSublist->m_data[j]);
        }
    }

    SpawnSublist* tail = (SpawnSublist*)(apOwner->m_20 + 0x48);
    for (int j = 0; j < tail->m_uiItemCount; j++)
    {
        m_28.v04(tail->m_data[j]);
    }
}

struct D65610Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* a, void* b, int c);
};
struct D65610Prim
{
    virtual void p00();
    D65610Obj* m_pEntryObject;
    int unk08, unk0c, unk10, unk14;
};
struct D65610Sec
{
    virtual void FUN_00d65610(D66180Entity* e);
};
struct D65610Self : D65610Prim, D65610Sec
{
    void FUN_00d65610(D66180Entity* e);
};

// Calls v10 on the stored object with the entity's offset 0xf0 pointer, the result of GetProperty1134(e), and DAT_01268fe0.
// @fnv 0x00d65610
void D65610Self::FUN_00d65610(D66180Entity* pEntity)
{
    D65610Obj* obj = m_pEntryObject;
    char* p = (char*)pEntity;
    obj->v10(p + 0xf0, GetProperty1134(pEntity), DAT_01268fe0);
}

static inline bool HasProperty(const S_00c6d840* props, int key)
{
    for (int i = 0; i < props->m_uiItemCount; i++)
    {
        if (props->m_entries[i].m_key == key)
            return true;
    }
    return false;
}

// Returns the value of the first present entry among 0x1234 (if checkOverride), 0x1235 and 0x1135; sets *usedDefault and returns 0 if that value is 0.
// @fnv 0x00d652c0
static int FUN_00d652c0(S_00c6d840* props, bool checkOverride, bool* usedDefault)
{
    int base = props->FindEntry(0x1135, 0).m_kPointA;
    int level = props->FindEntry(0x1235, 0).m_kPointA;
    int iOverride = props->FindEntry(0x1234, 0).m_kPointA;
    int result = 0;
    *usedDefault = false;
    if (checkOverride && HasProperty(props, 0x1234))
    {
        if (iOverride == 0)
        {
            *usedDefault = true;
            return 0;
        }
        result = iOverride;
    }
    else if (HasProperty(props, 0x1235))
    {
        if (level == 0)
        {
            *usedDefault = true;
            return 0;
        }
        result = level;
    }
    else if (HasProperty(props, 0x1135))
    {
        if (base == 0)
        {
            *usedDefault = true;
            return 0;
        }
        result = base;
    }
    return result;
}

int PropertyQueryCaller(S_00c6d840* props, bool checkOverride, bool* usedDefault)
{
    return FUN_00d652c0(props, checkOverride, usedDefault);
}

struct ShapeList
{
    struct ShapeItem** data;
    int count;
};

struct ShapeItem
{
    virtual void v00()
    {}
    virtual void* GetDesc()
    {
        return 0;
    }
};

struct ShapeSub
{
    int m_00;
    int m_04;
    int m_08;
};

extern int DAT_01268fe8;
extern int DAT_01268fe4;


struct FUN_00d657d0_cls
{
    void* m_vptr00;
    int unk04;
    void* m_vptr08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_vptr20;
    int unk24;
    void* m_vptr28;
    void* m_vptr2c;
    int m_30;
    int m_34;
    unsigned int m_38;
    ShapeSub m_3c;
    ShapeSub m_48;
    ShapeSub m_54;
    unsigned char m_60;
    unsigned char m_61;
    unsigned char m_62;
    unsigned char m_63;
    unsigned char m_64;
    unsigned char m_65;
    unsigned char m_66;
    float m_68;
    int m_6c;
    int m_70;

    FUN_00d657d0_cls* FUN_00d657d0(ShapeList* a1);
};

// Initializes vtables, ShapeSub members, and flags, then searches a1 for a ShapeDisplayViewerOptions item to set m_60.
// @fnv 0x00d657d0
FUN_00d657d0_cls* FUN_00d657d0_cls::FUN_00d657d0(ShapeList* apShapes)
{
    int i;
    new ((void *)this) ::FUN_00ddccb0_cls((*(const ::BDDCCB0Array< ::BDDCCB0ProcessContext *> *)(apShapes)));
    *(void* volatile*)&m_vptr28 = (void*)::str_0102f13c;
    *(void* volatile*)&m_vptr2c = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_010ccf7c));
    m_vptr00 = (void*)DAT_010d1b04;
    m_vptr08 = (void*)DAT_010d1ae4;
    m_vptr20 = (void*)DAT_010d1ad4;
    *(void* volatile*)&m_vptr28 = (void*)DAT_010d1ab8;
    *(void* volatile*)&m_vptr2c = (void*)DAT_010d1aa8;
    *(int volatile*)&m_30 = 0;
    *(int volatile*)&m_34 = 0;
    m_38 = 0x80000000;
    ShapeSub* pShapeSub1 = &m_3c;
    pShapeSub1->m_00 = 0;
    pShapeSub1->m_04 = 0;
    pShapeSub1->m_08 = -1;
    {
        void* h1 = getMemoryRouter();
        int val1 = ((int*)h1)[4];
        reinterpret_cast<::FUN_00cb1fe0_t *>((pShapeSub1))->EnsureCapacity(val1, 0);
    }
    ShapeSub* pShapeSub2 = &m_48;
    pShapeSub2->m_00 = 0;
    pShapeSub2->m_04 = 0;
    pShapeSub2->m_08 = -1;
    {
        void* h2 = getMemoryRouter();
        int val2 = ((int*)h2)[4];
        reinterpret_cast<::FUN_00cb1fe0_t *>((pShapeSub2))->EnsureCapacity(val2, 0);
    }
    ShapeSub* pShapeSub3 = &m_54;
    pShapeSub3->m_00 = 0;
    pShapeSub3->m_04 = 0;
    pShapeSub3->m_08 = -1;
    {
        void* h3 = getMemoryRouter();
        int val3 = ((int*)h3)[4];
        reinterpret_cast<::FUN_00cb1fe0_t *>((pShapeSub3))->EnsureCapacity(val3, 0);
    }

    FUN_00d657d0_cls* __restrict self = this;
    *(unsigned char volatile*)&self->m_60 = 1;
    *(unsigned char volatile*)&self->m_61 = 0;
    *(unsigned char volatile*)&self->m_62 = 0;
    *(unsigned char volatile*)&self->m_63 = 1;
    *(unsigned char volatile*)&self->m_64 = 1;
    *(unsigned char volatile*)&self->m_65 = 1;
    *(unsigned char volatile*)&self->m_66 = 0;
    *(float volatile*)&self->m_68 = -1.0f;
    *(int volatile*)&self->m_6c = DAT_01268fe8;
    m_70 = DAT_01268fe4;
    int count = apShapes->count;
    for (i = 0; i < count; ++i)
    {
        ShapeItem* item = apShapes->data[i];
        void* desc = item->GetDesc();
        if (::fnv_00cb0fa0::FUN_00cb0fa0("ShapeDisplayViewerOptions", (const char *)(desc)) == 0)
            goto found;
    }
    return this;
found: {
    char* o = (char*)apShapes->data[i];
    m_60 = ((o != 0) ? o - 8 : (char*)0)[0x58];
}
    return this;
}

struct Mem_d65f
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
    virtual void deallocateChunk(void* p, int nbytes) throw();
    virtual void v0C();
    virtual void deallocate(void* p, int nbytes) throw();
};

struct Holder_d65f
{
    int unk00, unk04, unk08, unk0C;
    Mem_d65f* m_pMemoryAllocator;
    Mem_d65f& heap()
    {
        return *m_pMemoryAllocator;
    }
};

struct Router_d65f
{
    static inline Holder_d65f& getMemoryRouter() { return *static_cast<Holder_d65f*>(::FUN_00c85750()); }
};
inline Mem_d65f& getMemory_d65f()
{
    return *Router_d65f::getMemoryRouter().m_pMemoryAllocator;
}

inline void memCpy4_d65f(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d65f
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~hkArray_d65f() throw()
    {
        Mem_d65f& mem = Router_d65f::getMemoryRouter().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            mem.deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d65f(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Listener_d65f;
struct Watch2_d65f
{
    virtual void w00();
};

struct Agent_d65f
{
};

struct Node_d65f
{
    Agent_d65f* m_pCollisionAgent;
    hkArray_d65f<int> m_items;
    static void operator delete(void* p) throw()
    {
        Router_d65f::getMemoryRouter().heap().deallocateChunk(p, sizeof(Node_d65f));
    }
};

struct Base_d65f
{
    virtual void v00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
};

struct Listener_d65f
{
    virtual void l00();
};

struct Watch_d65f
{
    int unk00;
};

struct Phantom_d65f : Base_d65f, Listener_d65f, Watch2_d65f
{
    hkArray_d65f<Node_d65f*> m_kNodeCollection;
    void FUN_00d65750(int index);
    void FUN_00d65fc0(int index);
};
// @fnv 0x00d66080
void FUN_00d66080_cls::Destroy()
{
    m_vptr00 = (int)&(*reinterpret_cast<int *>(&::DAT_010d1b04));
    m_vptr08 = (int)&(*reinterpret_cast<int *>(&::DAT_010d1ae4));
    m_vptr20 = (int)&(*reinterpret_cast<int *>(&::DAT_010d1ad4));
    m_vptr28 = (int)&(*reinterpret_cast<int *>(&::DAT_010d1ab8));
    m_vptr2c = (int)&(*reinterpret_cast<int *>(&::DAT_010d1aa8));

    for (int i = m_iArrayLength - 1; i >= 0; --i)
    {
        reinterpret_cast<::Phantom_d65f *>(this)->FUN_00d65fc0(i);
    }

    {
        SpawnedBuf* pBuf = &m_buf54;
        AudioHolder* pHolder = (AudioHolder*)getMemoryRouter();
        reinterpret_cast<::CB1A90Owner *>((pBuf))->ProcessArgument((::CB1A90Argument *)(pHolder->m_pAllocator));
        ::FUN_00a29680();
    }
    {
        SpawnedBuf* pBuf = &m_buf48;
        AudioHolder* pHolder = (AudioHolder*)getMemoryRouter();
        reinterpret_cast<::CB1A90Owner *>((pBuf))->ProcessArgument((::CB1A90Argument *)(pHolder->m_pAllocator));
        ::FUN_00a29680();
    }
    {
        SpawnedBuf* pBuf = &m_buf3c;
        AudioHolder* pHolder = (AudioHolder*)getMemoryRouter();
        reinterpret_cast<::CB1A90Owner *>((pBuf))->ProcessArgument((::CB1A90Argument *)(pHolder->m_pAllocator));
        ::FUN_00a29680();
    }

    AudioHolder* pHolder = (AudioHolder*)getMemoryRouter();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uiFlags = m_uiObjectFlags;
    m_iArrayLength = 0;
    if ((uiFlags & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData, (int)((uiFlags & 0x3fffffffu) * 4));
    }
    m_pData = 0;
    // the original stores the new flag value AFTER the m_pData=0 store and
    // BEFORE the pop edi; writing it through a reference keeps MSVC from
    // sinking the constant store past the register restore.
    {
        unsigned int& ruiFlags = m_uiObjectFlags;
        ruiFlags = 0x80000000u;
    }
    m_vptr2c = (int)&(*reinterpret_cast<int *>(&::DAT_010ccf7c));
    m_vptr28 = (int)&(*reinterpret_cast<int *>(&::str_0102f13c));
    reinterpret_cast<struct ::FUN_00ddcc60 *>(this)->FUN_00ddcc60::~FUN_00ddcc60();
}
// Calls FindItemIndex on the owner object at this-0x20 and, if the result is non-negative, passes it to FUN_00d65fc0.
// @fnv 0x00d66160
void FUN_00d66160_cls::FUN_00d66160(int arg)
{
    OwnerObject* pOwner = (OwnerObject*)((char*)this - 0x20);
    int result = reinterpret_cast<::FUN_00d655e0_class *>((pOwner))->FindItemIndex(arg);
    if (result >= 0)
    {
        reinterpret_cast<::Phantom_d65f *>((pOwner))->FUN_00d65fc0(result);
    }
}

// Calls FUN_00c917a0 and ClearValue on the node's collision agent with this, calls FUN_00d65750, then deletes the node and removes it from m_kNodeCollection.
// @fnv 0x00d65fc0
void Phantom_d65f::FUN_00d65fc0(int index)
{
    reinterpret_cast<::hkWorldC917 *>((m_kNodeCollection[index]->m_pCollisionAgent))->FUN_00c917a0(this);
    reinterpret_cast<::SearchArray *>((m_kNodeCollection[index]->m_pCollisionAgent))->ClearValue((int)(this));
    FUN_00d65750(index);
    delete m_kNodeCollection[index];
    m_kNodeCollection.removeAt(index);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
struct TtShapeDisplayBase : FUN_00d652a0_cls
{
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
};

struct TtShapeDisplayOuter;

struct TtTlsRecord
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int m_spare;
};

struct TtTlsData
{
    int unk00;
    TtTlsRecord* m_cur;
    int unk08;
    TtTlsRecord* m_kRayEnd;
};


struct TtShapeDisplayInner
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
    bool m_flag34;

    TtShapeDisplayOuter* GetOuter();
    void FUN_00d65520(int arg);
};

struct TtShapeDisplayOuter : TtShapeDisplayBase, TtShapeDisplayInner
{
};

__forceinline TtShapeDisplayOuter* TtShapeDisplayInner::GetOuter()
{
    return (TtShapeDisplayOuter*)((char*)this - 0x2c);
}

static void __forceinline TtPushEvent(const char* name)
{
    TtTlsData* data = (TtTlsData*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    TtTlsRecord* rec = data->m_cur;
    if (rec < data->m_kRayEnd)
    {
        rec->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        rec->m_uiCommandId = t;
        data->m_cur = rec + 1;
    }
}

// Pushes a TthkpShapeDisplayViewer event, returns early if m_flag34 is false, otherwise calls GetOuter()->v10 with m_18 and arg, then pushes an Et event.
// @fnv 0x00d65520
void TtShapeDisplayInner::FUN_00d65520(int arg)
{
    TtPushEvent("TthkpShapeDisplayViewer");
    if (!m_flag34)
    {
        TtPushEvent("Et");
        return;
    }
    GetOuter()->v10(GetOuter()->m_18, arg);
    TtPushEvent("Et");
}

struct D661E0Primary
{
    virtual void vfunc00();
    virtual void FUN_00d661e0();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct D661E0Secondary
{
    virtual void FUN_00d661e0();
};

struct D661E0Object : D661E0Primary, D661E0Secondary
{
    D661E0Object();

// @fnv 0x00d661e0
    virtual void FUN_00d661e0();
};

D661E0Object::D661E0Object()
{}

// sub ecx,8; jmp FUN_00d661f0: adjustor thunk from multiple inheritance.
struct PrimaryBase
{
    virtual void FUN_00d661f0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d661f0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d661f0
    virtual void FUN_00d661f0();
};

Derived::Derived()
{}

// FUN_00d66200 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 40 bytes so the second
// base lands at +0x28.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_00d66200; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_00d66200
{
    A1_00d66200();
    virtual void FUN_00d66200();
    char pad[0x24];
};

struct A2_00d66200
{
    A2_00d66200();
// @fnv 0x00d66200
    virtual void FUN_00d66200();
};

struct Own_00d66200 : A1_00d66200, A2_00d66200
{
    Own_00d66200();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_00d66200();    // the shared override - declared only
};

Own_00d66200::Own_00d66200()
{}
void Own_00d66200::key_fn()
{}

Own_00d66200* make_00d66200()
{
    static Own_00d66200 o;
    return &o;
}

namespace fnv_00d66210 {
// sub ecx,0x2c; jmp target == MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by sizeof(PrimaryBase) = 0x2c.
struct PrimaryBase
{
    virtual void FUN_00d66210();
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

struct SecondaryBase
{
    virtual void FUN_00d66210();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66210
    virtual void FUN_00d66210();
};

Derived::Derived()
{}
}  // namespace fnv_00d66210

namespace fnv_00d66220 {
struct S_00d66220_Allocator
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00d66220_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d66220_Allocator* unk10;
    S_00d66220_Allocator* heap()
    {
        return unk10;
    }
};
static inline S_00d66220_Router* getMemoryRouter() { return static_cast<S_00d66220_Router*>(::FUN_00c85750()); }

struct S_00d66220_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~S_00d66220_RefObject();
    static void operator delete(void* p, size_t)
    {
        S_00d66220_RefObject* o = static_cast<S_00d66220_RefObject*>(p);
        getMemoryRouter()->heap()->ReleaseBlock(p, o->m_usMemSizeAndFlags);
    }
};

struct FUN_00d66220 : S_00d66220_RefObject
{
    FUN_00d66220();
    virtual ~FUN_00d66220();
};

// @fnv 0x00d66220
FUN_00d66220::FUN_00d66220()
{}
}  // namespace fnv_00d66220

struct OutVec
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
};

struct Visitor
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(OutVec* out, const void* item, int g);
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
};

struct S8
{
    unsigned __int64 value;
    void* getPtr() const
    {
        return (void*)(unsigned int)value;
    }
};

struct Entry16
{
    int m_type;
    int unk04;
    void* m_p8;
    int m_iThirdValue;
};

struct SubObj
{
};

struct Item
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    Entry16* m_entries;
    int m_entryCount;
    bool hasProperty(int key) const
    {
        for (int i = 0; i < m_entryCount; ++i)
        {
            if (m_entries[i].m_type == key)
                return true;
        }
        return false;
    }
    S8 getProperty(int key) const
    {
        int n = m_entryCount;
        for (int i = 0; i < n; ++i)
        {
            if (m_entries[i].m_type == key)
            {
                return *(const S8*)&m_entries[i].m_p8;
            }
        }
        S8 s = {0};
        return s;
    }
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    SubObj m_e0;
};

struct ItemList
{
    Item** m_items;
    int m_uiItemCount;
};

struct Group
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    ItemList m_kNode;
};

struct Node
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
    Group** m_28;
    int m_2c;
public:
    void FUN_00de0f90(void *, ::XfResult *);
};

class S00d653f0_Obj
{
  public:
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    float m_68;
    void FUN_00d653f0(Visitor* a1, Node* a2);
};

// Calls a1->v04 with each item's SweepTransform result and property pointer, using m_68 (or a2->FUN_00c91020() if m_68 is not positive), between v18 and v19.
// @fnv 0x00d653f0
void S00d653f0_Obj::FUN_00d653f0(Visitor* apVisitor, Node* apNode)
{
    float f = (m_68 > 0.0f) ? m_68 : reinterpret_cast<::CpuObject *>((apNode))->FUN_00c91020();
    apVisitor->v18();
    int i = 0;
    if (apNode->m_2c > 0)
    {
        do
        {
            ItemList* pItemList = &apNode->m_28[i]->m_kNode;
            int j = 0;
            if (pItemList->m_uiItemCount > 0)
            {
                do
                {
                    Item* pItem = pItemList->m_items[j];

                    const void* p =
                        pItem->hasProperty(0x1134) ? pItem->getProperty(0x1134).getPtr() : (char*)&pItem->unk10;
                    __declspec(align(16)) OutVec sweptTransform;
                    reinterpret_cast<::FUN_00c86490_Class *>(&(pItem->m_e0))->SweepTransform(f, &sweptTransform);
                    apVisitor->v04(&sweptTransform, p, DAT_01268fe0);
                    ++j;
                } while (j < pItemList->m_uiItemCount);
            }
            ++i;
        } while (i < apNode->m_2c);
    }
    apVisitor->v19();
}

namespace fnv_00d65750 {
struct ArrayStruct
{
    void** m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};

struct Entry
{
    int m_00;
    ArrayStruct m_aiIndexedValues;
};

struct Listener
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void FUN_v5(void* a, void* b, int c);
};

struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* volatile m_10;
};

static inline Singleton* getMemoryRouter() { return static_cast<Singleton*>(::FUN_00c85750()); }

struct Shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    Listener* m_pListener;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    Entry** m_pTable;
    void FUN_00d65750(int index);
};

// Invokes m_pListener->FUN_v5 for each item in m_pTable[index]->m_aiIndexedValues, then resets the array count to 0.
// @fnv 0x00d65750
void Shell::FUN_00d65750(int index)
{
    Entry* entry = m_pTable[index];
    for (int i = 0; i < entry->m_aiIndexedValues.m_iArrayLength; i++)
    {
        int nItem = (int)entry->m_aiIndexedValues.m_pData[i];
        m_pListener->FUN_v5(entry->m_aiIndexedValues.m_pData[i], (*reinterpret_cast<void * *>(&::DAT_01268fe0)), *(int*)nItem);
    }
    ArrayStruct* arr = &entry->m_aiIndexedValues;
    Singleton* holder = getMemoryRouter();
    void* pContext = holder->m_10;
    int iCapacity = arr->m_iCapacity & 0x3fffffff;
    if (iCapacity < 0)
    {
        ::FUN_00c908c0((::SpawnedObject *)(pContext), (::SpawnedArray *)(arr), (iCapacity * 2) > 0 ? iCapacity * 2 : 0, 4);
    }
    arr->m_iArrayLength = 0;
}
}  // namespace fnv_00d65750

// Remove a displayed entity and its cached display geometry.
extern "C" void _ReadWriteBarrier();
// The voice object that receives the finished sample.
struct AudioVoiceHost
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(int iKey, int iGlobal, int iResult);
};
// The channel that owns a playback buffer.
struct AudioChannel
{
};
// The playback buffer itself.
struct AudioBuffer
{
};
// One list of played items.
struct AudioItemList
{
    int unk00;
    int* m_pItems;
    int m_iArrayLength;

    __forceinline int find(int key) const
    {
        int count = m_iArrayLength;
        for (int i = 0; i < count; ++i)
        {
            if (m_pItems[i] == key)
                return i;
        }
        return -1;
    }
    __forceinline void removeAt(int i)
    {
        --m_iArrayLength;
        if (m_iArrayLength != i)
        {
            memCpy4_d65f(m_pItems + i, m_pItems + m_iArrayLength, sizeof(int));
        }
    }
};
// The sound that is being played.
struct AudioParam
{
    int unk00;
    int unk04;
    int m_i08;
    int unk0c;
    int m_i10;
    int unk14;
    int unk18;
    int unk1c;
};
// The flag the helper is given: it is a single byte but the helper reads it
// as a whole word.
union AudioFlag
{
    int m_iValue;
    char m_cValue;
};
// The sub object this method belongs to.
struct AudioNodeSub
{
    int unk00;
    int unk04;
    AudioItemList** m_pItemLists;
    int unk0c;
    int unk10;
    AudioChannel m_channel;
    int unk18;
    int unk1c;
    AudioBuffer m_buffer;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char unk38;
    unsigned char m_bPlayed;

    void FUN_00d65640(AudioParam* pParam);
};
struct DisplayPrimary
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_override10;
    int m_override14;
    AudioVoiceHost* m_display;
    int unk1c;
    int unk20;
    int unk24;
};
struct DisplayOuter : DisplayPrimary, AudioNodeSub
{
};
static DisplayOuter* GetDisplayOuter(AudioNodeSub* p)
{
    return (DisplayOuter*)((char*)p - sizeof(DisplayPrimary));
}
struct S_00c6d840_Q : S_00c6d840
{
    S_00c6d840_Pair FindEntry(int key, int unused);
};
struct FUN_00d655e0_Q : FUN_00d655e0_class
{
};
void* __cdecl GetProperty1134(D66180Entity* e);
// Module local helper: it is called from exactly one place, so the compiler
// hands it the sound in EAX and keeps the two other arguments on the stack.
// Resolves a display result for pParam, notifies the voice host, adjusts the audio buffer, and removes the matching item from the item list.
// @fnv 0x00d65640
void AudioNodeSub::FUN_00d65640(AudioParam* pParam)
{
    AudioNodeSub* self = this;
    int iResult;
    bool checkOverride = GetDisplayOuter(self)->m_override10 == 0 && GetDisplayOuter(self)->m_override14 == 0;
    bool usedDefault;
    iResult = FUN_00d652c0((S_00c6d840*)pParam, checkOverride, &usedDefault);

    FUN_00d655e0_Q* pList = (FUN_00d655e0_Q*)((char*)self - 0x28);
    int iIndex = reinterpret_cast<::FUN_00d655e0_class *>((pList))->FindItemIndex(pParam->m_i08);
    if (iIndex < 0)
    {
        return;
    }

    AudioItemList* pItems = self->m_pItemLists[iIndex];
    int displayResult = iResult;
    if (!displayResult)
        displayResult = pParam->m_i10;

    iResult = displayResult;
    int iKey = (int)(size_t)GetProperty1134((D66180Entity*)pParam);
    AudioVoiceHost* pVoiceHost = GetDisplayOuter(self)->m_display;
    pVoiceHost->v14(iKey, DAT_01268fe0, iResult);

    if (self->m_bPlayed && iResult)
    {
        int iCount = reinterpret_cast<::FUN_00cb1930_t *>(&(self->m_buffer))->LookupHashEntry(iResult, 0);
        iCount = iCount - 1;
        if (iCount == 0)
        {
            reinterpret_cast<::FUN_00cb18f0_t *>(&(self->m_channel))->FUN_00cb1fb0(iResult);
            reinterpret_cast<::FUN_00cb18f0_t *>(&(self->m_buffer))->FUN_00cb1fb0(iResult);
        }
        else
        {
            AudioHolder* pHolder = (AudioHolder*)getMemoryRouter();
            reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(&(self->m_buffer))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(pHolder->m_pAllocator)), iResult, iCount);
        }
    }

    int i = pItems->find(iKey);
    if (i >= 0)
    {
        _ReadWriteBarrier();
        pItems->removeAt(i);
    }
}

struct S_00d65970_Heap
{
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};

struct S_00d65970_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d65970_Heap* unk10;
    S_00d65970_Heap& heap()
    {
        return *unk10;
    }
};

struct S_00d65970_Item;

inline void* __cdecl operator new(size_t, void* where) throw()
{
    return where;
}

struct S_00d65970_ItemArray
{
    S_00d65970_Item** data;
    int size;
    int capacityAndFlags;
};

struct S_00d65970_Elem
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
    S_00d65970_ItemArray items;
};

struct S_00d65970_B28;
struct S_00d65970_B2c;

struct S_00d65970_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00d65970_Elem* unk20;
    int unk24;
    S_00d65970_Elem** unk28;
    int unk2c;
    int unk30;
    S_00d65970_Elem** unk34;
    int unk38;
};

struct S_00d65970_Node
{
    S_00d65970_Arg* arg;
    S_00d65970_ItemArray arr;
    S_00d65970_Node()
    {
        arr.data = 0;
        arr.size = 0;
        arr.capacityAndFlags = 0x80000000;
    }
};

struct S_00d65970_NodeArray
{
    S_00d65970_Node** data;
    int size;
    int capacityAndFlags;
};


struct S_00d65970_Base0
{
    virtual void vfn0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};

struct S_00d65970_B28
{
    virtual void vfn0();
    virtual void vfn1(S_00d65970_Item* item);
};

struct S_00d65970_B2c
{
    int unk00;
};

struct S_00d65970_Obj : S_00d65970_Base0, S_00d65970_B28, S_00d65970_B2c
{
    S_00d65970_NodeArray nodes;
    void FUN_00d65970(S_00d65970_Arg* arg);
};
// If m_1c is set, iterates its count at offset 0x70 and calls FUN_00d65970 on each entry from the array at 0x6c.
// @fnv 0x00d65f70
void FUN_00d65f70_class::FUN_00d65f70()
{
    if (m_1c)
    {
        for (int i = 0; i < *(int*)(m_1c + 0x70); ++i)
            reinterpret_cast<::S_00d65970_Obj *>((((FUN_00d65970_stub*)((char*)this - 8))))->FUN_00d65970((::S_00d65970_Arg *)(*(*(int**)(m_1c + 0x6c) + i)));
    }
}
// @fnv 0x00d65fb0
void Adjustor::FUN_00d65fb0()
{
    reinterpret_cast<::S_00d65970_Obj *>((((Target*)((char*)this - 0x20))))->FUN_00d65970({});
}

// Creates a node from arg, appends it to the nodes array, and calls vfn1 on all items in arg's element arrays.
// @fnv 0x00d65970
void S_00d65970_Obj::FUN_00d65970(S_00d65970_Arg* arg)
{
    reinterpret_cast<::fnv_00c93820::hkpWorldC938 *>((arg))->FUN_00c93820((::fnv_00c93820::hkpEntityListenerC938 *)(::S_00d65970_B28 *)(this));
    reinterpret_cast<::fnv_00c93920::hkpWorldXc93920 *>((arg))->FUN_00c93920((::fnv_00c93920::hkpEntityListenerXc93920 *)(::S_00d65970_B2c *)(this));
    S_00d65970_Heap& heap = ((S_00d65970_Router*)getMemoryRouter())->heap();
    void* mem = heap.AllocateMemoryBlock(0x10);
    S_00d65970_Node* node = new (mem) S_00d65970_Node;
    node->arg = arg;
    S_00d65970_NodeArray& arr = nodes;
    S_00d65970_Router* router = (S_00d65970_Router*)getMemoryRouter();
    if (arr.size == (arr.capacityAndFlags & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(::S_00d65970_Heap *)(&router->heap()), (::AudioStream *)(void *)(&arr), 4);
    S_00d65970_Node** p = arr.data + arr.size;
    for (int k = 0; k < 1; k++)
        p[k] = node;
    arr.size++;
    for (int i = 0; i < arg->unk2c; i++)
    {
        S_00d65970_ItemArray& items = arg->unk28[i]->items;
        for (int j = 0; j < items.size; j++)
            vfn1(items.data[j]);
    }
    for (int i = 0; i < arg->unk38; i++)
    {
        S_00d65970_ItemArray& items = arg->unk34[i]->items;
        for (int j = 0; j < items.size; j++)
            vfn1(items.data[j]);
    }
    S_00d65970_Elem* e = arg->unk20;
    if (e)
    {
        for (int j = 0; j < e->items.size; j++)
            vfn1(e->items.data[j]);
    }
}

// Moved from hkpshapedisplayviewer_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00ddfb70_cls.h"
#include "fnv/decl/FUN_00de1d20.h"
#include "fnv/decl/S_00d65970_Obj.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/fnv_00d65750__Shell.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00ddf000.h"
void* __cdecl FUN_00d65910(void* context);
void RegisterShapesProcess();
int __cdecl FUN_00d661d0();
void* __cdecl GetProperty1134(D66180Entity* entity);
static int FUN_00d652c0(S_00c6d840* props, bool checkOverride, bool* usedDefault);
int PropertyQueryCaller(S_00c6d840* props, bool checkOverride, bool* usedDefault);
struct XfResult;

#include <xmmintrin.h>
struct S65_Alloc
{
    virtual void v00();
    virtual void* allocate(unsigned int size);
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* p, int size);
};
struct S65_Heap
{
    int h00;
    int h04;
    int h08;
    int h0c;
    S65_Alloc* allocator;
    __forceinline S65_Alloc& heap()
    {
        return *allocator;
    }
};
__forceinline S65_Heap& s65Router()
{
    return *static_cast<S65_Heap*>(getMemoryRouter());
}

struct S65_Pair
{
    unsigned __int64 bits;
    S65_Pair()
    {}

    int integer() const
    {
        return (int)bits;
    }
    void* pointer() const
    {
        return (void*)(unsigned long)bits;
    }
};
struct S65_Param : S_00c6d840
{
    int p80;
    int p84;
    int p88;
    int p8c;
    int p90;
    int p94;
    int p98;
    int p9c;
    int pa0;
    int pa4;
    int pa8;
    int pac;
    int pb0;
    int pb4;
    int pb8;
    int pbc;
    int pc0;
    int pc4;
    int pc8;
    int pcc;
    int pd0;
    int pd4;
    int pd8;
    int pdc;
    int pe0;
    int pe4;
    unsigned char motionType;
    unsigned char pe9;
    unsigned char pea;
    unsigned char peb;
    int pec;
    int transform;
    S65_Pair FindEntry(int key, int unused);
    __forceinline void* pointerProperty(int key)
    {
        return FindEntry(key, 0).pointer();
    }
    __forceinline int integerProperty(int key)
    {
        return FindEntry(key, 0).integer();
    }
    S65_Pair FUN_00cd2a50(int key);
    bool has(int key) const
    {
        for (int i = 0; i < m_uiItemCount; ++i)
            if (m_entries[i].m_key == key)
                return true;
        return false;
    }
};

struct S65_Map
{
    int s00;
    int s04;
    int s08;
    __forceinline void insert(void* key, int val)
    {
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(this)->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(&s65Router().heap())), (unsigned int)(key), val);
    }
};
struct S65_Ref
{
};
struct S65_Val
{
    int phi;
    int theta;
};
struct S65_Str
{
    int s00;
    int s04;
    int s08;
};
struct S65_Elem
{
    virtual ~S65_Elem();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
};
struct S65_Vec
{
    S65_Elem** data;
    int count;
    int cap;
    S65_Elem* inlineBuf[8];
};
struct S65_Work
{
    int w00;
    int w04;
    int w08;
    int w0c;
    int w10;
};
union S65_V4
{
    __m128 q;
    float f[4];
};
struct S65_NewObj
{
    int n00;
    short s04;
    short s06;
    int n08;
    int n0c;
    S65_V4 c0;
    S65_V4 c1;
    S65_V4 c2;
    S65_V4 t;
    float& cell(int row, int col)
    {
        return ((float*)&c0)[col * 4 + row];
    }
};
struct S65_Host
{
    virtual void v00();
    virtual void v04(S65_Vec* out, void* arg, void* nv, int glob, void* saved);
    virtual void v08(int a, void* arg, void* nv, int glob, void* saved);
    virtual void v0c(int val, void* nv, int glob);
};
struct S65_Err
{
    virtual void d00();
    virtual void d04();
    virtual void d08();
    virtual void d0c(int a, int b, const char* buf, const char* s, int n);
};
struct S65_IntArr
{
    int* data;
    int count;
    int cap;
};
struct S65_Item
{
    int i00;
    S65_IntArr arr;
};

extern const char str_010d1b18[];

static __declspec(noinline) void* FUN_00d652c0(S65_Param* p, bool flag, unsigned char* out)
{
    void* base = p->pointerProperty(0x1135);
    void* alt = p->pointerProperty(0x1235);
    void* over = p->pointerProperty(0x1234);
    *out = 0;
    if (flag && p->has(0x1234))
    {
        if (!over)
            *out = 1;
        return (void*)over;
    }
    if (p->has(0x1235))
    {
        if (!alt)
            *out = 1;
        return (void*)alt;
    }
    if (p->has(0x1135))
    {
        if (!base)
            *out = 1;
        return (void*)base;
    }
    return 0;
}

struct S65_Prim
{
    virtual void p00();
    int o04;
    int o08;
    int o0c;
    int f10;
    int f14;
    S65_Host* host;
    int o1c;
    int o20;
    int o24;
};
struct S65_Sec
{
    virtual void FUN_00d65ad0(S65_Param* param);
};
struct S65_Self : S65_Prim, S65_Sec
{
    int t04;
    S65_Item** m_items;
    int t0c;
    int t10;
    S65_Map sub14;
    S65_Map sub20;
    S65_Map sub2c;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
    int t40;
    int f44;
    int f48;
    void FUN_00d65ad0(S65_Param* param);
};

inline void* operator new(size_t, void* p)
{
    return p;
}

// @fnv 0x00d65ad0
void S65_Self::FUN_00d65ad0(S65_Param* param)
{
    unsigned char done;
    bool flag = (f10 == 0 && f14 == 0) ? true : false;
    void* ret = FUN_00d652c0(param, flag, &done);
    if (done)
        return;
    int idx = reinterpret_cast<::FUN_00d655e0_class *>(this)->FindItemIndex(param->unk08);
    if (idx < 0)
        return;
    S65_Item* item = m_items[idx];
    void* key = ret;
    if (!key)
        key = (void*)param->unk10;
    if (!key)
        return;
    bool isNew = false;
    if (b3a)
    {
        unsigned int r = ((unsigned int)(reinterpret_cast<::FUN_00cb1930_t *>(&(sub2c))->LookupHashEntry((int)(key), 0)));
        isNew = r > 0;
        if (!r)
            reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(&(sub2c))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(s65Router().allocator)), (unsigned int)(key), 1);
    }
    int existing = 0;
    if (b39)
        existing = ((unsigned int)(reinterpret_cast<::FUN_00cb1930_t *>(&(sub14))->LookupHashEntry((int)(key), 0)));
    S65_Vec vec;
    vec.data = vec.inlineBuf;
    vec.count = 0;
    vec.cap = (int)0x80000008;
    bool keep = true;
    if (!existing && !isNew && b3b && b3c)
    {
        void* a = param->pointerProperty(0x1136);
        void* alt = param->pointerProperty(0x1131);
        if (!a && !alt)
        {
            S65_Val val;
            reinterpret_cast<::FUN_00ddfb70_cls *>(&(val))->FUN_00ddfb70();
            S65_Work work;
            ::FUN_00ddfb80((::FUN_00ddfb80_s *)&(work), (int)(&val), {});
            reinterpret_cast<::Node *>(&(work))->FUN_00de0f90(key, (::XfResult *)(::S65_Vec *)(&vec));
            for (int i = vec.count - 1; i >= 0; i--)
            {
                S65_Elem* e = vec.data[i];
                if (e->f50 == 6 && e->f08 == 0)
                {
                    __declspec(align(16)) char buf[0x200];
                    S65_Str str;
                    new ((void *)&(str)) ::FUN_00cb1600(buf, 0x200);
                    reinterpret_cast<::SinkOwner *>(&(str))->FUN_00cc01c0(::fnv_00d66530::str_010d196c);
                    (*reinterpret_cast<::S65_Err * *>(&::DAT_01268360))->d0c(0, -1, buf, str_010d1b18, 0x13c);
                    reinterpret_cast<struct ::FUN_00cc00e0 *>(&(str))->FUN_00cc00e0::~FUN_00cc00e0();
                    vec.count--;
                    if (vec.count != i)
                        vec.data[i] = vec.data[vec.count];
                }
            }
            void* v = param->pointerProperty(0x1135);
            if (v && (void*)v == ret)
            {
                reinterpret_cast<::hkReferencedObjectC905 *>((((S65_Ref*)v)))->FUN_00c905b0();
                param->FUN_00cd2a50(0x1135);
            }
        }
        else
        {
            keep = a == 0;
            if (alt)
                param->FUN_00cd2a50(0x1131);
            S65_NewObj* mem = (S65_NewObj*)s65Router().heap().allocate(0x60);
            mem->s04 = (short)0x60;
            S65_NewObj* obj = ((::S65_NewObj *)(new ((void *)(mem)) ::FUN_00de1d20((int)(a ? a : alt))));
            obj->c0.q = _mm_setzero_ps();
            obj->c1.q = _mm_setzero_ps();
            obj->c2.q = _mm_setzero_ps();
            obj->cell(0, 0) = 1.0f;
            obj->cell(1, 1) = 1.0f;
            obj->cell(2, 2) = 1.0f;
            obj->t.q = _mm_setzero_ps();
            hkArrayConstruct(vec.data + vec.count, 1, (S65_Elem*)obj);
            ++vec.count;
        }
    }
    void* nv = GetProperty1134((D66180Entity*)param);
    S65_IntArr* arr = &item->arr;
    S65_Heap* heap = (S65_Heap*)getMemoryRouter();
    if (arr->count == (arr->cap & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(heap->allocator), (::AudioStream *)(arr), 4);
    int* slot = arr->data + arr->count;
    __assume(slot != 0);
    new (slot) int((int)nv);
    arr->count++;
    if (!existing)
    {
        if (vec.count > 0 || isNew || !b3c)
        {
            host->v04(&vec, &param->transform, nv, DAT_01268fe0, key);
            if (b39)
            {
                sub14.insert(key, (int)nv);
                sub20.insert(key, 1);
            }
            int val = param->integerProperty(0x1130);
            if (b3d)
            {
                if (b3e || !val)
                    val = (param->motionType == 5) ? f44 : f48;
            }
            if (val)
                host->v0c(val, nv, DAT_01268fe0);
        }
    }
    else
    {
        int n = ((unsigned int)(reinterpret_cast<::FUN_00cb1930_t *>(&(sub20))->LookupHashEntry((int)(key), 1))) + 1;
        sub20.insert(key, n);
        host->v08(existing, &param->transform, nv, DAT_01268fe0, key);
    }
    for (int i = 0; i < vec.count; i++)
    {
        if (!keep)
            vec.data[i]->f08 = 0;
        delete vec.data[i];
    }
    S65_Alloc& al = s65Router().heap();
    vec.count = 0;
    if ((vec.cap & 0x80000000) == 0)
        al.FreeArray(vec.data, (vec.cap & 0x3fffffff) * 4);
}
#include "generated/data/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.inc"
#include "generated/data/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer_gs_ehsc_nogs_noehsc_variant.inc"
