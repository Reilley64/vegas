
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include <windows.h>
#include <new>
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/FUN_00c86490_Class.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00ddcc60.h"
#include "fnv/decl/FUN_00ddccb0_cls.h"
#include "fnv/decl/FUN_00ddfb70_cls.h"
#include "fnv/decl/FUN_00de1d20.h"
#include "fnv/decl/S_00d65970_Obj.h"
#include "fnv/decl/S_00dd9380.h"
#include "fnv/decl/SearchArray.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/fnv_00c93820__hkpWorldC938.h"
#include "fnv/decl/fnv_00c93920__hkpWorldXc93920.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/decl/fnv_00d65750__Shell.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkWorldC917.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00ddf000.h"
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
void* __cdecl FUN_00c85750();
struct FUN_00d657d0_class
{
};
void* __cdecl FUN_00d65910(void* context);
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
void RegisterShapesProcess();
struct Target
{
};
struct Adjustor
{
    void FUN_00d65fb0();
};
int __cdecl FUN_00d661d0();
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
void* __cdecl GetProperty1134(D66180Entity* entity);
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
    void* operator new(std::size_t size) throw()
    {
        AllocHolder* holder = (AllocHolder*)FUN_00c85750();
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
static inline bool HasProperty(const S_00c6d840* props, int key)
{
    for (int i = 0; i < props->m_uiItemCount; i++)
    {
        if (props->m_entries[i].m_key == key)
            return true;
    }
    return false;
}
static int FUN_00d652c0(S_00c6d840* props, bool checkOverride, bool* usedDefault);
int PropertyQueryCaller(S_00c6d840* props, bool checkOverride, bool* usedDefault);
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
void* __cdecl FUN_00c85750();
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
    static Holder_d65f& __cdecl FUN_00c85750() throw();
};
inline Mem_d65f& getMemory_d65f()
{
    return *Router_d65f::FUN_00c85750().m_pMemoryAllocator;
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
        Mem_d65f& mem = Router_d65f::FUN_00c85750().heap();
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
        Router_d65f::FUN_00c85750().heap().deallocateChunk(p, sizeof(Node_d65f));
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
    void FUN_00d65fc0(int index);
};
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
struct XfResult;
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
    return *static_cast<S65_Heap*>(FUN_00c85750());
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
    S65_Heap* heap = (S65_Heap*)FUN_00c85750();
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

#include "generated/data/havok/physics/utilities/visualdebugger/viewer/collide/hkpshapedisplayviewer_gs_ehsc_nogs_noehsc_variant.inc"
