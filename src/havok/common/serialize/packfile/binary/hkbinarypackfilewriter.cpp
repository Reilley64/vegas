
// src/havok/common/serialize/packfile/binary/hkbinarypackfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/binary/hkbinarypackfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/Archive.h"
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/CB1BC0Map.h"
#include "fnv/decl/Cls_t.h"
#include "fnv/decl/D60590Object.h"
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00cb1e40_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00d47690_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00d60830.h"
#include "fnv/decl/FUN_00d60aa0_class.h"
#include "fnv/decl/FUN_00d87790.h"
#include "fnv/decl/FUN_00d877d0_class.h"
#include "fnv/decl/FUN_00d87820_Class.h"
#include "fnv/decl/FUN_00dbdf60.h"
#include "fnv/decl/FUN_00e028e0.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/ListMapDBA.h"
#include "fnv/decl/MapCB1C.h"
#include "fnv/decl/OffsetView.h"
#include "fnv/decl/OwnerClass.h"
#include "fnv/decl/OwnerDC9E.h"
#include "fnv/decl/Owner_t.h"
#include "fnv/decl/ProbeMap64.h"
#include "fnv/decl/hkMapCB1E.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/decl/hkObjectD878.h"
#include "fnv/decl/hkStringMapD874.h"
#include "fnv/decl/hkStringPoolXdbdd40.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00db8000.h"
#include "fnv/symbols_00dbc000.h"
#include "fnv/symbols_00dbd000.h"
#include "fnv/symbols_00dc8000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_0126c000.h"
struct GlobalObjectO2_00d472a0
{
    int x;
};
extern int DAT_011b7a7c;
extern intptr_t DAT_011b7aec;
extern void* DAT_010d65bc;
struct FUN_00dbdf30_s
{
public:
    void FUN_00dbdf30(intptr_t, intptr_t);
};
struct FUN_00dbc670
{
    void* m_vft;
    FUN_00dbc670();
};
extern void FUN_00dbe4d0();
// Calls FUN_00dbe4d0, sets m_vft, then calls FUN_00dbdef0 and FUN_00dbdf30 on four global objects with DAT_011b7aec.
// @fnv 0x00dbc670
FUN_00dbc670::FUN_00dbc670()
{
    FUN_00dbe4d0();
    m_vft = &DAT_010d65bc;
    ::FUN_00dbdef0();
    ((FUN_00dbdf30_s*)this)->FUN_00dbdf30((intptr_t)(&::g_0126cae8), DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->FUN_00dbdf30((intptr_t)(&::g_0126ca58), DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->FUN_00dbdf30((intptr_t)(&::g_0126cab8), DAT_011b7aec);
    ((FUN_00dbdf30_s*)this)->FUN_00dbdf30((intptr_t)(&::g_0126ca88), DAT_011b7aec);
}

// @fnv 0x00dbd720
uintptr_t __cdecl FUN_00dbd720(uintptr_t arg)
{
    return *reinterpret_cast<unsigned int*>(arg + 4) * 3 * 16;
}

struct FUN_00dbc6e0_s
{
    void* m_vft;
    void FUN_00dbc6e0();
};
// @fnv 0x00dbc6e0
void FUN_00dbc6e0_s::FUN_00dbc6e0()
{
    m_vft = &DAT_010d65bc;
    reinterpret_cast<::FUN_00dbdf60 *>(this)->FUN_00dbdf60::~FUN_00dbdf60();
}

struct CallbackTarget
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void Send(void* value);
};
struct FUN_00dbd730_class
{
    int unk00;
    int unk04;
    CallbackTarget* target;
    void* ForwardToTarget(void* value);
};
// @fnv 0x00dbd730
void* FUN_00dbd730_class::ForwardToTarget(void* value)
{
    target->Send(value);
    return value;
}

struct S_00dbd770_Inner
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18(void* p);
};

struct S_00dbd770
{
    int unk0;
    int unk4;
    S_00dbd770_Inner* unk8;
    void* ForwardToInner(void* p);
};

// @fnv 0x00dbd770
void* S_00dbd770::ForwardToInner(void* apArg)
{
    unk8->unk18(apArg);
    return apArg;
}

struct Inner
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual int f8();
};
struct FUN_00dbd7d0_Class
{
    int unk00;
    int unk04;
    Inner* object;
    int offset;
    int GetAdjustedValue();
};
// @fnv 0x00dbd7d0
int FUN_00dbd7d0_Class::GetAdjustedValue()
{
    return object->f8() - offset;
}

struct Triple
{
    int x;
    int y;
    int z;
    Triple() : x(0), y(0), z(0x80000000)
    {}
};
struct FUN_00dbd870
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    FUN_00dbd870();
};
// Default-constructs four Triple members and sets trailing to 0.
// @fnv 0x00dbd870
FUN_00dbd870::FUN_00dbd870() : trailing(0)
{}

struct FUN_00dbc6f0_cls_callee
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Write(void* apNode, int aiValue);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int Count();
};

struct FUN_00dbc6f0_cls_store
{
    int unk00;
};

struct FUN_00dbc6f0_cls_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00dbc6f0_cls_callee* m_pCallee;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    FUN_00dbc6f0_cls_store m_store;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    unsigned char m_byReverse;
};

struct FUN_00dbc6f0_cls_source
{
};

struct FUN_00dbc6f0_cls_key
{
    int m_iValue;
    unsigned char m_byTag;
};

struct FUN_00dbc6f0_cls_bytes
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};

union FUN_00dbc6f0_cls_word
{
    int iValue;
    FUN_00dbc6f0_cls_bytes bytes;
};

int __cdecl FUN_00cb10d0(void* apNode);

typedef void(* S_WriteFn)(FUN_00dbc6f0_cls_callee*, void*, int);

static inline void S_Swap(unsigned char& a, unsigned char& b)
{
    unsigned char t = a;
    a = b;
    b = t;
}

static inline int S_Rev(int v)
{
    unsigned char* p = (unsigned char*)&v;
    S_Swap(p[0], p[3]);
    S_Swap(p[1], p[2]);
    return v;
}

// @fnv 0x00dbc6f0
void WriteNodeDiff(FUN_00dbc6f0_cls_owner* apOwner, FUN_00dbc6f0_cls_source* apSource, intptr_t aiDiff)
{
    int x = ((int)(reinterpret_cast<::FUN_00d47690_class *>((apSource))->ComputeSignature(0)));
    if (apOwner->m_byReverse != 0)
        x = S_Rev(x);
    FUN_00dbc6f0_cls_key key;
    key.m_iValue = x;
    key.m_byTag = 9;
    apOwner->m_pCallee->Write(&key, 5);
    void* pNode = ((void *)(reinterpret_cast<::FnvClassNameNode *>((apSource))->FUN_00d46d40()));
    intptr_t iDiff = apOwner->m_pCallee->Count() - aiDiff;
    reinterpret_cast<::hkStringMapD874 *>(&(apOwner->m_store))->FUN_00d874d0((const char *)(pNode), iDiff);
    void** pVtable = *(void***)apOwner->m_pCallee;
    ((S_WriteFn)pVtable[4])(apOwner->m_pCallee, pNode, FUN_00cb10d0(pNode) + 1);
}

struct Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
};

struct FUN_00dbd760_cls
{
    int unk00;
    int unk04;
    Target* m_08;
    void FUN_00dbd760();
};

// @fnv 0x00dbd760
void FUN_00dbd760_cls::FUN_00dbd760()
{
    m_08->unk14();
}

struct S_00dbd790_Obj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int a, int b);
};
struct S_00dbd790_Class
{
    int unk00;
    int unk04;
    S_00dbd790_Obj* object;
    int offset;
    void DispatchToObject(int a, int b);
};
// Calls the object's f7 virtual method, passing a plus offset when b is zero and a otherwise, along with b.
// @fnv 0x00dbd790
void S_00dbd790_Class::DispatchToObject(int aiValue, int b)
{
    object->f7(b == 0 ? aiValue + offset : aiValue, b);
}

struct FUN_00dbd820_pair
{
    unsigned int first;
    unsigned int second;
};

struct FUN_00dbd820_cls
{
    FUN_00dbd820_pair* m_data;
    int m_iElementCount;
    unsigned int m_flags;
    void AppendPair(FUN_00dbd820_pair p);
};


// @fnv 0x00dbd820
void FUN_00dbd820_cls::AppendPair(FUN_00dbd820_pair aPair)
{
    FUN_00dbd820_pair entry;
    entry.first = aPair.first;
    entry.second = *(volatile unsigned int*)&aPair.second;
    void* holder = FUN_00c85750();
    if (m_iElementCount == (int)(m_flags & 0x3fffffffu))
    {
        ::ResizeAudioStream((::AudioAllocator *)(*(void**)((char*)holder + 0x10)), (::AudioStream *)(void *)(this), 8);
    }
    int idx = m_iElementCount;
    FUN_00dbd820_pair* slot = m_data + idx;
    slot->first = entry.first;
    slot->second = entry.second;
    m_iElementCount++;
}

struct S_00dbd8a0_Sub
{
    char unk0;
    char unk1;
};

struct S_00dbd8a0_Arg
{
    int unk00;
    S_00dbd8a0_Sub unk04;
};

struct S_00dbd8a0_Byte
{
    char c;
    S_00dbd8a0_Byte(char v) : c(v)
    {}
};

struct S_00dbd8a0_Mem20
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbd8a0_Mem20(S_00dbd8a0_Sub* p);
};

struct S_00dbd8a0_Mem30
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbd8a0_Mem30(S_00dbd8a0_Byte b);
};

extern char DAT_011b7b89;

struct FUN_00dbd8a0
{
    S_00dbd8a0_Arg* unk00;
    Triple first;
    Triple second;
    int unk1c;
    S_00dbd8a0_Mem20 unk20;
    S_00dbd8a0_Mem30 unk30;
    Triple third;
    bool unk4c;
    FUN_00dbd8a0(S_00dbd8a0_Arg* p);
};

// Initialises members from p: stores p, builds unk20 from p->unk04 and unk30 from byte 0, and sets unk4c by comparing DAT_011b7b89 with p->unk04.unk1.
// @fnv 0x00dbd8a0
FUN_00dbd8a0::FUN_00dbd8a0(S_00dbd8a0_Arg* apArg) : unk00(apArg), unk20(&apArg->unk04), unk30(S_00dbd8a0_Byte(0))
{
    unk4c = DAT_011b7b89 != apArg->unk04.unk1;
}

class BDBD910Allocator
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};

class BDBD910Router
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BDBD910Allocator* m_pkHeap;

    BDBD910Allocator& heap()
    {
        return *m_pkHeap;
    }
};

BDBD910Router* BDBD910GetRouter();

template <class T> __forceinline void BDBD910Destruct(T* pkData, int iCount)
{
    for (int i = 0; i < iCount; i++)
        reinterpret_cast<::FUN_00e028e0 *>(&(pkData[i]))->FUN_00e028e0::~FUN_00e028e0();
}

template <class T> class BDBD910Array
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~BDBD910Array()
    {
        BDBD910Allocator& kAlloc = BDBD910GetRouter()->heap();
        BDBD910Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct BDBD910Entry48
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
};

struct BDBD910Entry8
{
    int unk00;
    int unk04;
};

struct BDBD910Entry52
{
    ~BDBD910Entry52();

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
};

class BDBD910Member20
{
  public:
    ~BDBD910Member20();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class BDBD910Member30
{
  public:
    ~BDBD910Member30();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00dbd910_cls
{
  public:
    ~FUN_00dbd910_cls() throw();

    int unk00;
    BDBD910Array<BDBD910Entry48> m_kArray04;
    BDBD910Array<BDBD910Entry8> m_kArray10;
    int unk1C;
    BDBD910Member20 m_kMember20;
    BDBD910Member30 m_kMember30;
    BDBD910Array<BDBD910Entry52> m_kArray40;
};

// Destructor for the container class; the member arrays and members are destroyed automatically by their own destructors.
// @fnv 0x00dbd910
FUN_00dbd910_cls::~FUN_00dbd910_cls() throw()
{}

namespace fnv_00dbd620 {
struct S_00dbd620_Arg;

struct S_00dbd620_Poly
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void v7(void* a, unsigned int b);
    virtual void* v8();
};

struct S_00dbd620_Writer
{
    void* vtbl;
    char unk04;
    char unk05;
    short unk06;
    S_00dbd620_Poly* unk08;
    void* unk0c;
};

struct S_00dbd620_Obj
{
    void* unk00;
    int unk04;
    void* unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* unk1c;
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
    char unk4c;
    S_00dbd620_Obj(S_00dbd620_Arg* p);
    void FUN_00dbd8a0(S_00dbd620_Arg* p);
};

struct S_00dbd620_Dtor
{
    int unk00;
    ~S_00dbd620_Dtor();
};

extern int DAT_010d65ec;


static __declspec(noinline) void S_00dbd620_Helper(void* a, void* b, void* c, void* d)
{
    int n = *(int*)b;
    for (int i = 0; i < n; i++)
        ((S_00dbd620_Poly*)a)->v3();
    *(int*)c += n + *(int*)d;
}

struct S_00dbd620_Owner
{
    void FUN_00dbc7a0(void* p);
    void FUN_00dbcea0(void* p);
    void FUN_00dbc960(void* p, void* q);
    void* ProcessPoly(S_00dbd620_Poly* a1, S_00dbd620_Arg* a2);
};

// @fnv 0x00dbd620
void* S_00dbd620_Owner::ProcessPoly(S_00dbd620_Poly* pPoly, S_00dbd620_Arg* a2)
{
    S_00dbd620_Obj obj(a2);
    S_00dbd620_Writer writer;

    writer.unk06 = 1;
    writer.vtbl = &DAT_010d65ec;
    writer.unk08 = pPoly;
    writer.unk0c = writer.unk08->v8();

    obj.unk1c = &writer;
    FUN_00dbc7a0(&obj);

    S_00dbd620_Helper((void*)&obj.unk20, (void*)a2, obj.unk1c, obj.unk08);

    void* pSaved = ((S_00dbd620_Poly*)&writer)->v8();

    unsigned int one = 1;
    ((S_00dbd620_Poly*)&writer)->v7((void*)::FUN_00dbd720((uintptr_t)&obj.unk04), one);

    FUN_00dbcea0(&obj);

    void* pSaved2 = ((S_00dbd620_Poly*)&writer)->v8();

    FUN_00dbc960(&obj, pSaved);

    ((S_00dbd620_Poly*)&writer)->v7(pSaved2, 0);

    ((S_00dbd620_Poly*)&writer)->v5();

    writer.vtbl = &(*reinterpret_cast<int *>(&::DAT_0102e388));

    reinterpret_cast<::FUN_00dbd910_cls *>((((S_00dbd620_Dtor*)&obj)))->FUN_00dbd910_cls::~FUN_00dbd910_cls();

    return 0;
}
}  // namespace fnv_00dbd620

// Havok patch manager: rebuild patch dependency order (topological sort).
typedef unsigned __int64 S_00db8670_Uint64;
typedef uintptr_t S_00db8670_Ulong;

struct S_00db8670_Heap
{
    virtual void unkVfn0();
    virtual void* AllocateMemoryBlock(int n);
    virtual void unkVfn2();
    virtual void unkVfn3();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00db8670_Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    S_00db8670_Heap* m_pStreamAllocator;
    S_00db8670_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline S_00db8670_Router& S_GetRouter() throw()
{
    return *(S_00db8670_Router*)FUN_00c85750();
}

template <typename T> __forceinline void S_ConstructWithCopy(T* p, int n, const T& fill) throw()
{
    for (int i = 0; i < n; ++i)
        p[i] = fill;
}

template <typename T> struct S_00db8670_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00db8670_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~S_00db8670_Array() throw()
    {
        _clearAndDeallocate(S_GetRouter().heap());
    }

    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    int getCapacity() const throw()
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    const T& operator[](int i) const throw()
    {
        return m_data[i];
    }

    void _clearAndDeallocate(S_00db8670_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00db8670_Heap& alloc, int n) throw()
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00db8670_Heap& alloc, int n) throw()
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void _setSize(S_00db8670_Heap& alloc, int n, const T& fill) throw()
    {
        GrowArrayCapacity(alloc, n);
        S_ConstructWithCopy(m_data + m_iElementCount, n - m_iElementCount, fill);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n) throw()
    {
        _setSize(S_GetRouter().heap(), n);
    }
    void SetSizeAndGrow(int n, const T& fill) throw()
    {
        _setSize(S_GetRouter().heap(), n, fill);
    }

    // copy assignment (out of line)
    void SwapThreeInts(const S_00db8670_Array& other) throw();
};

struct S_00db8670_MapBase64
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    S_00db8670_MapBase64() throw() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S_00db8670_MapBase64() throw();

};

struct S_00db8670_Map64 : S_00db8670_MapBase64
{
    S_00db8670_Map64() throw()
    {
        reinterpret_cast<::CB1BC0Map *>(this)->ResizeToFit((::CB1BC0Allocator &)(S_GetRouter().heap()), 0);
    }
    ~S_00db8670_Map64() throw()
    {
        reinterpret_cast<::FUN_00cb1e40_t *>(this)->FUN_00cb1e40((::FUN_00cb1e40_arg_t *)&(S_GetRouter().heap()));
    }

    void clear() throw()
    {
        reinterpret_cast<::hkMapCB1E *>(this)->FUN_00cb1e00();
    }
    int hasKey(S_00db8670_Uint64 key) const throw()
    {
        return reinterpret_cast<::ProbeMap64 *>((void *)this)->FUN_00cb1c60(key) <= m_iPairCount;
    }
    void insert(S_00db8670_Uint64 key, const int& val) throw()
    {
        S_00db8670_Router& router = S_GetRouter();
        reinterpret_cast<::CB1BC0Map *>(this)->InsertKeyValue((::CB1BC0Allocator &)(router.heap()), key, val);
    }
    S_00db8670_Uint64 FindValueForKey(S_00db8670_Uint64 key, S_00db8670_Uint64 def) const throw()
    {
        return reinterpret_cast<::MapCB1C *>((void *)this)->FUN_00cb1cb0(key, def);
    }
};

struct S_00db8670_MapBaseUlong
{
    struct Pair
    {
        S_00db8670_Ulong key;
        S_00db8670_Ulong val;
    };
    Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    S_00db8670_MapBaseUlong() throw() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~S_00db8670_MapBaseUlong() throw();

    S_00db8670_Ulong LookupHashEntry(S_00db8670_Ulong key, S_00db8670_Ulong def) const throw();
    void FUN_00cb1870(S_00db8670_Heap& alloc, S_00db8670_Ulong key, S_00db8670_Ulong value) throw();

    int GetFirstIterator() const throw()
    {
        int i;
        for (i = 0; i <= m_iPairCount; i++)
        {
            if (m_kPrimitiveElement[i].key != S_00db8670_Ulong(-1))
            {
                break;
            }
        }
        return i;
    }
    int getNext(int it) const throw()
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; i++)
        {
            if (m_kPrimitiveElement[i].key != S_00db8670_Ulong(-1))
            {
                break;
            }
        }
        return i;
    }
    int isValid(int it) const throw()
    {
        return it <= m_iPairCount;
    }
    S_00db8670_Ulong GetIteratorKey(int it) const throw()
    {
        return m_kPrimitiveElement[it].key;
    }
};

struct S_00db8670_MapUlong : S_00db8670_MapBaseUlong
{
    S_00db8670_MapUlong() throw()
    {
        reinterpret_cast<::FUN_00cb1fe0_t *>(this)->EnsureCapacity((intptr_t)&(S_GetRouter().heap()), 0);
    }
    ~S_00db8670_MapUlong() throw()
    {
        reinterpret_cast<::CB1A90Owner *>(this)->ProcessArgument((::CB1A90Argument *)&(S_GetRouter().heap()));
    }
};

struct S_00db8670_ChainValue
{
    int value;
    int next;
};

struct S_00db8670_MultiMap64
{
    S_00db8670_Array<S_00db8670_ChainValue> m_kChainValues;
    S_00db8670_Map64 m_pHashFunction;
    int m_iFreeListHead;

    S_00db8670_MultiMap64() throw() : m_iFreeListHead(-1)
    {}

    int AllocateSlot() throw();
    void Insert(S_00db8670_Uint64 key, const int& value) throw();
    int GetNextChainIndex(int i) const throw()
    {
        return m_kChainValues[i].next;
    }
    int getValue(int i) const throw()
    {
        return m_kChainValues[i].value;
    }
};

struct S_00db8670_MultiMapUlong
{
    S_00db8670_Array<S_00db8670_ChainValue> m_kChainValues;
    S_00db8670_MapUlong m_pHashFunction;
    int m_iFreeListHead;

    S_00db8670_MultiMapUlong() throw() : m_iFreeListHead(-1)
    {}

    int AllocateSlot() throw();
    void FUN_00dc9ec0(S_00db8670_Ulong key, const int& value) throw();
    int GetNextChainIndex(intptr_t i) const throw()
    {
        return m_kChainValues[i].next;
    }
    int getValue(intptr_t i) const throw()
    {
        return m_kChainValues[i].value;
    }
};

__declspec(noinline) void S_00db8670_MultiMap64::Insert(S_00db8670_Uint64 key, const int& value) throw()
{
    int oldHead = (int)reinterpret_cast<::MapCB1C *>((void *)&(m_pHashFunction))->FUN_00cb1cb0(key, S_00db8670_Uint64(-1));
    int newHead = AllocateSlot();
    m_kChainValues[newHead].value = value;
    m_kChainValues[newHead].next = oldHead;
    reinterpret_cast<::CB1BC0Map *>(&(m_pHashFunction))->InsertKeyValue((::CB1BC0Allocator &)(S_GetRouter().heap()), key, newHead);
}
__declspec(noinline) void S_00db8670_MultiMapUlong::FUN_00dc9ec0(S_00db8670_Ulong key, const int& value) throw()
{
    int oldHead = (int)m_pHashFunction.LookupHashEntry(key, S_00db8670_Ulong(-1));
    int newHead = AllocateSlot();
    m_kChainValues[newHead].value = value;
    m_kChainValues[newHead].next = oldHead;
    m_pHashFunction.FUN_00cb1870(S_GetRouter().heap(), key, newHead);
}

struct S_00db8670_StringMapOps
{
};

struct S_00db8670_StringMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    S_00db8670_StringMapOps m_pOperations;

    S_00db8670_StringMap(S_00db8670_StringMapOps ops = S_00db8670_StringMapOps()) throw();
    ~S_00db8670_StringMap() throw();

};

struct S_00db8670_Component
{
    int m_type;
    const void* m_patch;
};

struct S_00db8670_DependsPatch
{
    const char* m_name;
    int m_version;
};

struct S_00db8670_PatchInfo
{
    const char* m_oldName;
    const char* m_newName;
    int m_oldVersion;
    int m_newVersion;
    const S_00db8670_Component* m_component;
    int m_numComponent;
};

struct S_00db8670_UidFromClassVersion
{
};

__declspec(noinline) int __cdecl FUN_00db7cb0(const S_00db8670_PatchInfo* p) throw()
{
    if (p->m_oldVersion == -1)
    {
        if (p->m_oldName != 0 || p->m_newVersion == -1 || p->m_newName == 0)
            return 0;
    }
    else if (p->m_newVersion == -1)
    {
        if (p->m_oldName == 0 || p->m_newName != 0)
            return 0;
    }
    else if (p->m_oldName == 0)
        return 0;
    return 1;
}
int __cdecl FUN_00db7e70(int from, int to, const S_00db8670_MultiMapUlong& deps, S_00db8670_MapUlong& visited) throw();

struct S_00db8670_PatchManager
{
    int unk00;
    int unk04;
    S_00db8670_UidFromClassVersion* m_pUidFromClassVersion;
    S_00db8670_Array<const S_00db8670_PatchInfo*> m_kPatchInfos;
    S_00db8670_Map64 m_kPatchInfoIndexMap;

    int FUN_00db8670() throw();
};

struct Dbc860Triple
{
    int x;
    int y;
    int z;
};

struct Dbc860Frame
{
    Dbc860Triple first;
    Dbc860Triple second;
    Dbc860Triple third;
    Dbc860Triple fourth;
    int trailing;
};

struct Dbc860Src
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    void* m_0c;
};

struct Dbc860Guid
{
    unsigned char b0;
    unsigned char b1;
    unsigned short s2;
    unsigned int d4;
    unsigned int d8;
    unsigned int dc;
};

struct Dbc860Header
{
    unsigned int magic0;
    unsigned int magic1;
    unsigned int id;
    unsigned int type;
    unsigned int data;
    unsigned int extra;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    Dbc860Guid guid;
    unsigned int tail0;
    unsigned int tail1;
};

struct Dbc860Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Call(int value, void* a, void* b, void* c);
};

extern "C" void __cdecl FUN_00cb1280(void* dst, int a, intptr_t b);
extern "C" void __cdecl FUN_00cb1260(void* dst, void* src, intptr_t n);
extern "C" void __cdecl CopyIfNonEmpty(char* dst, const char* src, int count);

// Builds a Dbc860Header and initializes a Dbc860Frame, then calls sink->Call with the value, header, DAT_0126c6c8, and frame.
// @fnv 0x00dbc860
static __declspec(noinline) void __cdecl FUN_00dbc860(Dbc860Src* apSrc, int value, int extra, Dbc860Sink* sink)
{
    Dbc860Header header;
    Dbc860Frame f;

    FUN_00cb1280(&header, -1, 0x40);
    header.magic0 = 0x57e0e057;
    header.magic1 = 0x10c0c010;
    header.guid.b0 = 0;
    header.id = apSrc->m_00;
    header.type = 7;
    FUN_00cb1260(&header.data, &apSrc->m_04, 4);
    header.extra = extra;
    FUN_00cb1280(&header.tail0, -1, 8);
    if (apSrc->m_0c == 0)
    {
        ::FUN_00dbda20(&header.guid, (void *)(0x10));
    }
    else
    {
        CopyIfNonEmpty((char*)&header.guid, (const char*)apSrc->m_0c, 0x10);
    }
    f.first.z = (int)0x80000000;
    f.second.z = (int)0x80000000;
    f.third.z = (int)0x80000000;
    f.fourth.z = (int)0x80000000;
    f.first.x = 0;
    f.first.y = 0;
    f.second.x = 0;
    f.second.y = 0;
    f.third.x = 0;
    f.third.y = 0;
    f.fourth.x = 0;
    f.fourth.y = 0;
    f.trailing = 0;
    sink->Call(value, &header, &(*reinterpret_cast<int *>(&::g_0126c6c8)), &f);
    reinterpret_cast<::FUN_00e028e0 *>(&(f))->FUN_00e028e0::~FUN_00e028e0();
}

volatile int g_dbc860_value;
volatile int g_dbc860_extra;
Dbc860Src* volatile g_dbc860_self;
Dbc860Sink* volatile g_dbc860_sink;
void CallTarget_dbc860()
{
    FUN_00dbc860(g_dbc860_self, g_dbc860_value, g_dbc860_extra, g_dbc860_sink);
}

struct S00dbcdd0_Obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10(void* p, unsigned int n);
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual unsigned int unk20();
};

struct S00dbcdd0_Alloc
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Free(void* p, unsigned int n);
};

struct S00dbcdd0_Holder
{
    void* u00;
    void* u04;
    void* u08;
    void* u0C;
    S00dbcdd0_Alloc* m_pAllocator;
    S00dbcdd0_Alloc& heap()
    {
        return *m_pAllocator;
    }
};

struct S00dbcdd0_Arr
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
};

extern void FUN_00ec61c0(void* dst, int value, int n);

template <class T> __forceinline void S00dbcdd0_Construct(T* p, int n, const T& fill)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = fill;
    }
}

// Fills count bytes with -1, calls obj->unk10 when r is nonzero, then frees the buffer if heap-allocated.
// @fnv 0x00dbcdd0
static __declspec(noinline) void FUN_00dbcdd0(S00dbcdd0_Obj* obj, unsigned int count)
{
    int value = (int)obj->unk20();
    S00dbcdd0_Arr arr;
    arr.m_data = &arr.u0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000020;
    S00dbcdd0_Alloc& heap = ((S00dbcdd0_Holder*)FUN_00c85750())->heap();
    int cap = (int)(arr.m_capFlags & 0x3fffffff);
    if (cap < (int)count)
    {
        int newCap = cap + cap;
        if ((int)count >= newCap)
        {
            newCap = (int)count;
        }
        ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap), (::SpawnedArray *)(void **)(&arr.m_data), newCap, 1);
    }
    S00dbcdd0_Construct((char*)arr.m_data + arr.m_iElementCount, (int)count - arr.m_iElementCount, (char)-1);
    int r = ((int)count - 1) & value;
    arr.m_iElementCount = (int)count;
    if (r != 0)
    {
        obj->unk10(arr.m_data, count - r);
    }
    S00dbcdd0_Alloc& heap2 = ((S00dbcdd0_Holder*)FUN_00c85750())->heap();
    unsigned int capFlags = arr.m_capFlags;
    arr.m_iElementCount = 0;
    if ((capFlags & 0x80000000u) == 0)
    {
        heap2.Free(arr.m_data, capFlags & 0x3fffffff);
    }
}

void S00dbcdd0_Entry(S00dbcdd0_Obj* obj, unsigned int count)
{
    FUN_00dbcdd0(obj, count);
}

namespace fnv_00dbd7f0 {
struct S_00dbd7f0_Allocator
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00dbd7f0_Router
{
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    S_00dbd7f0_Allocator* m_pStreamAllocator;
    S_00dbd7f0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00dbd7f0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00dbd7f0_RefObj();
    void operator delete(void* p)
    {
        S_00dbd7f0_RefObj* b = static_cast<S_00dbd7f0_RefObj*>(p);
        static_cast<S_00dbd7f0_Router*>(::FUN_00c85750())->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00dbd7f0 : S_00dbd7f0_RefObj
{
    FUN_00dbd7f0();
    virtual ~FUN_00dbd7f0();
};
// @fnv 0x00dbd7f0
FUN_00dbd7f0::FUN_00dbd7f0()
{}
}  // namespace fnv_00dbd7f0

extern "C" void _ReadWriteBarrier();
struct OuterOffsets
{
    int fixup;
    int section;
    void step()
    {
        section += 48;
        fixup += 52;
    }
};
struct WriterBool
{
    unsigned char value;
};
struct BinaryWriter
{
    void* stream;
    int mode;
    int state;
    int extra;
    void FUN_00d60830(void*, WriterBool);
    void FUN_00d60590();
    void WriteInt(int);
};
struct OutputStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void seek(int, int);
};
struct HashLookup
{
    int state;
    int LookupHashEntry(int, int);
};
struct KeyLookup
{
    int state;
};
struct RootObject
{
};
struct RootEntry
{
    RootObject* object;
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
};
struct WriterOwner
{
    int a00;
    int a04;
    RootEntry* roots;
    int a0c;
    int a10;
    HashLookup hash;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    int a44;
    int a48;
    int a4c;
    int a50;
    int a54;
    int a58;
    int a5c;
    int a60;
    int a64;
    int a68;
    int a6c;
    int a70;
    int a74;
    int a78;
    int a7c;
    int a80;
    int a84;
    int a88;
    int rootIndex;
    int objectIndex;
    void FUN_00dbc960(struct SourceData*, int);
};
struct PointerPair
{
    int first;
    int second;
};
struct Fixup
{
    int location;
    int key;
    int a08;
    int a0c;
};
struct LocalFixup
{
    int location;
    int key;
};
struct ReserveAllocator;
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    void reserve(ReserveAllocator& allocator, int wanted);
    void resize(int wanted, const int& value);
    void resize(int wanted);
    void clear();
    void releaseOnly();
    T& operator[](int i)
    {
        return data[i];
    }
};
template <class T> struct LocalArray : ArrayBase<T>
{
    LocalArray()
    {
        data = 0;
        size = 0;
        *(volatile int*)&capacity = 0x80000000;
    }
};
struct SectionRecord
{
    int a00;
    int a04;
    int a08;
    int a0c;
    int a10;
    int base;
    int a18;
    int globalOffset;
    int localOffset;
    int a24;
    int a28;
    int a2c;
};
struct SectionFixups
{
    LocalArray<int> first;
    LocalArray<Fixup> globals;
    LocalArray<LocalFixup> locals;
    int a24;
    int a28;
    int a2c;
    int a30;
};
struct SectionContext
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
};
struct Serializer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void serialize(OutputStream*, SectionRecord*, int*, SectionContext*);
    int a04;
    int a08;
    int a0c;
};
struct SourceData
{
    int a00;
    LocalArray<SectionRecord> sections;
    LocalArray<PointerPair> pointers;
    OutputStream* stream;
    Serializer serializer;
    KeyLookup keys;
    int a34;
    int a38;
    int a3c;
    LocalArray<SectionFixups> fixups;
    WriterBool reverse;
};
struct ReserveAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void release(void*, int);
};
struct ReserveRouter
{
    void* a00;
    void* a04;
    void* a08;
    void* a0c;
    ReserveAllocator* allocator;
    ReserveAllocator& heap()
    {
        return *allocator;
    }
};
template <class T> __forceinline void ArrayBase<T>::reserve(ReserveAllocator& allocator, int wanted)
{
    int cap = capacity & 0x3fffffff;
    if (cap < wanted)
    {
        int newCapacity = wanted < cap * 2 ? cap * 2 : wanted;
        ::FUN_00c908c0((::SpawnedObject *)(void *)(&allocator), (::SpawnedArray *)(void *)(this), newCapacity, sizeof(T));
    }
}
template <class T> __forceinline void ArrayBase<T>::resize(int wanted, const int& value)
{
    reserve(((ReserveRouter*)FUN_00c85750())->heap(), wanted);
    int remaining = wanted - size;
    T* fill = data + size;
    for (int n = 0; n < remaining; n++)
        fill[n] = value;
    size = wanted;
}
template <class T> __forceinline void ArrayBase<T>::resize(int wanted)
{
    reserve(((ReserveRouter*)FUN_00c85750())->heap(), wanted);
    size = wanted;
}
template <class T> __forceinline void ArrayBase<T>::clear()
{
    ReserveAllocator& allocator = ((ReserveRouter*)FUN_00c85750())->heap();
    size = 0;
    if ((capacity & 0x80000000) == 0)
        allocator.release(data, (capacity & 0x3fffffff) * sizeof(T));
    data = 0;
    capacity = 0x80000000;
}
template <class T> __forceinline void ArrayBase<T>::releaseOnly()
{
    ReserveAllocator& allocator = ((ReserveRouter*)FUN_00c85750())->heap();
    size = 0;
    if ((capacity & 0x80000000) == 0)
        allocator.release(data, (capacity & 0x3fffffff) * sizeof(T));
}
// Writes global and local fixup data for each section, then serializes each section and writes the root object header to the stream.
// @fnv 0x00dbc960
void WriterOwner::FUN_00dbc960(SourceData* source, int position)
{
    BinaryWriter values;
    new ((void *)&(values)) ::FUN_00d60830((::hkReferencedObject *)(source->stream), (*(char *)&(const ::WriterBool &)(source->reverse)));
    SectionRecord* kIter;
    {
        int ptr = 0;
        if (ptr < source->sections.size)
        {
            OuterOffsets offsets;
            offsets.fixup = 0;
            offsets.section = 0;
            do
            {
                SectionFixups* pFixups = ((SectionFixups*)((char*)source->fixups.data + offsets.fixup));
                LocalArray<Fixup>* pGlobals = &pFixups->globals;
                ArrayBase<int> localOut;
                {
                    LocalArray<int> n;

                    kIter = ((SectionRecord*)((char*)source->sections.data + offsets.section));
                    n.resize((*(volatile int*)&pGlobals->size) * 3, -1);
                    _ReadWriteBarrier();
                    int j = 0;
                    unsigned int writer = 0;
                    if (pGlobals->size > 0)
                    {

                        HashLookup* volatile pHash = &hash;

                        do
                        {
                            intptr_t q;
                            int key = pGlobals->data[j].key;
                            q = reinterpret_cast<::FUN_00cb1930_t *>((pHash))->LookupHashEntry(key, -3);
                            if (0 <= q && source->pointers.data[q].first >= 0)
                            {
                                n.data[writer] = pGlobals->data[j].location - kIter->base;
                                n.data[writer + 1] = source->pointers.data[q].first;
                                n.data[2 + writer] = source->pointers.data[q].second;
                                writer += 3;
                            }
                        } while (++j < pGlobals->size);
                    }
                    source->stream->seek(kIter->base + kIter->globalOffset, 0);
                    reinterpret_cast<::FUN_00d60aa0_class *>(&(values))->FUN_00d60aa0(n.data, n.size);
                    n.clear();
                }
                LocalArray<LocalFixup>* b;
                b = &((SectionFixups*)((char*)source->fixups.data + offsets.fixup))->locals;
                kIter = ((SectionRecord*)((char*)source->sections.data + offsets.section));

                ArrayBase<int>& out = localOut;
                out.data = 0;
                out.size = 0;
                out.capacity = 0x80000000;
                out.resize(b->size * 3);
                for (int k = 0, offset = 0; k < b->size; k++, offset += 3)
                {
                    out.data[offset] = b->data[k].location - kIter->base;
                    out.data[offset + 1] = 0;
                    int localKey = b->data[k].key;
                    intptr_t mapped = reinterpret_cast<::hkObjectD878 *>(&(source->keys))->GetValue(localKey, -1);
                    out.data[2 + offset] = mapped;
                }
                source->stream->seek(kIter->localOffset + kIter->base, 0);
                reinterpret_cast<::FUN_00d60aa0_class *>(&(values))->FUN_00d60aa0(out.data, out.size);
                out.clear();
                offsets.section += 48;
                offsets.fixup += 52;
            } while (++ptr < source->sections.size);
        }
    }
    source->stream->seek(position, 0);
    for (int s = 0; s < source->sections.size; s++)
    {
        SectionContext context;
        context.trailing = 0;
        source->serializer.serialize(source->stream, &source->sections.data[s], &(*reinterpret_cast<int *>(&::g_0126c698)), &context);
        reinterpret_cast<::FUN_00e028e0 *>(&(context))->FUN_00e028e0::~FUN_00e028e0();
    }
    source->stream->seek(24, 0);
    WriterBool p;
    p.value = (unsigned char)(((unsigned int)*((int *)(reinterpret_cast<::OffsetView *>(&(source->serializer))->FUN_00e02a70()))) >> 8) != (unsigned char)DAT_011b7b89;
    BinaryWriter ptr;
    new ((void *)&(ptr)) ::FUN_00d60830((::hkReferencedObject *)(source->stream), (*(char *)&(const ::WriterBool &)(p)));
    reinterpret_cast<::hkOArchive_2 *>(&(ptr))->WriteInt(source->pointers.data[rootIndex].first);
    reinterpret_cast<::hkOArchive_2 *>(&(ptr))->WriteInt(source->pointers.data[rootIndex].second);
    RootObject* section;
    section = roots[objectIndex].object;
    reinterpret_cast<::hkOArchive_2 *>(&(ptr))->WriteInt(0);
    uintptr_t index;
    index = ((intptr_t)(reinterpret_cast<::FnvClassNameNode *>((section))->FUN_00d46d40()));
    reinterpret_cast<::hkOArchive_2 *>(&(ptr))->WriteInt(reinterpret_cast<::hkObjectD878 *>(&(source->keys))->GetValue(index, -1));
    reinterpret_cast<::D60590Object *>(&(ptr))->FUN_00d60590();
    reinterpret_cast<::D60590Object *>(&(values))->FUN_00d60590();
}

// Grouped serialization and offset-table construction.
struct ClockObj
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10(int a, int b);
    virtual void c14();
    virtual void c18();
    virtual int c1c(int n, int f);
    virtual int Get20();
};
struct FUN_00d46d40_s
{
    const char* text;
};

struct FUN_00d874b0_class
{
    char* SetBoolFromThreshold(char* buf, intptr_t v);
};
struct FUN_00dbdd40_s
{
    int GetOrAddString(int v);
};
struct FUN_00dce8d0_class
{
    int LookupHashEntry(unsigned long a, unsigned long b);
};
struct FUN_00d60940_Class
{
    void WriteInt(unsigned int v);
};
struct FUN_00d607b0_s
{
};
struct FUN_00d9ec10_cls
{
    void SwapThreeInts(int* a);
};
// Validates patch info, builds dependency and rename maps, topologically sorts m_kPatchInfos, and rebuilds m_kPatchInfoIndexMap.
// @fnv 0x00db8670
int S_00db8670_PatchManager::FUN_00db8670() throw()
{
    S_00db8670_Map64 newClassIndexFromUid;
    S_00db8670_Map64& patchIndexFromUid = m_kPatchInfoIndexMap;
    S_00db8670_MultiMap64 patchesFromUid;
    const S_00db8670_UidFromClassVersion* uidFromClassVersion = m_pUidFromClassVersion;
    S_00db8670_MultiMapUlong patchesFromName;

    patchIndexFromUid.clear();

    {
        for (int i = 0; i < m_kPatchInfos.GetLogicalSize(); i++)
        {
            const S_00db8670_PatchInfo* p = m_kPatchInfos[i];
            if (!FUN_00db7cb0(p))
            {
                return 1;
            }
            if (p->m_oldVersion != -1)
            {
                S_00db8670_Uint64 uid = ((unsigned long long)(reinterpret_cast<::Owner_t *>((void *)(m_pUidFromClassVersion))->FUN_00db7d60((uintptr_t)(p->m_oldName), p->m_oldVersion)));
                if (patchIndexFromUid.hasKey(uid))
                {
                    return 1;
                }
                patchIndexFromUid.insert(uid, i);
                if (p->m_newVersion == -1 || (p->m_newName && ::fnv_00cb0fa0::FUN_00cb0fa0(p->m_oldName, p->m_newName)))
                {
                    reinterpret_cast<::OwnerDC9E *>(&(patchesFromName))->FUN_00dc9ec0((S_00db8670_Ulong)p->m_oldName, (const ::KeyDC9E *)&(i));
                }
            }
            else
            {
                S_00db8670_Uint64 uid = ((unsigned long long)(reinterpret_cast<::Owner_t *>((void *)(m_pUidFromClassVersion))->FUN_00db7d60((uintptr_t)(p->m_newName), p->m_newVersion)));
                if (newClassIndexFromUid.hasKey(uid))
                {
                    return 1;
                }
                newClassIndexFromUid.insert(uid, i);
            }
            if (p->m_newVersion != -1)
            {
                const char* name = p->m_newName ? p->m_newName : p->m_oldName;
                S_00db8670_Uint64 uid = ((unsigned long long)(reinterpret_cast<::Owner_t *>((void *)(uidFromClassVersion))->FUN_00db7d60((uintptr_t)(name), p->m_newVersion)));
                reinterpret_cast<::ListMapDBA *>(&(patchesFromUid))->Insert(uid, i);
            }
        }
    }

    S_00db8670_StringMap newClassNames;
    S_00db8670_MultiMapUlong dependencies;
    S_00db8670_MultiMapUlong renames;

    for (int j = 0; j < m_kPatchInfos.GetLogicalSize(); j++)
    {
        const S_00db8670_PatchInfo* p = m_kPatchInfos[j];
        const char* name = p->m_oldName;
        int version = p->m_oldVersion;
        if (version == -1)
        {
            name = p->m_newName;
            version = p->m_newVersion;
            if (name == 0 || version == -1)
            {
                return 1;
            }
        }
        S_00db8670_Uint64 uid = ((unsigned long long)(reinterpret_cast<::Owner_t *>((void *)(uidFromClassVersion))->FUN_00db7d60((uintptr_t)(name), version)));
        int iNewClassIndex;
        if (p->m_oldVersion == -1)
        {
            iNewClassIndex = (int)newClassIndexFromUid.FindValueForKey(uid, S_00db8670_Uint64(-1));
        }
        else
        {
            iNewClassIndex = (int)patchIndexFromUid.FindValueForKey(uid, S_00db8670_Uint64(-1));
            for (int k = reinterpret_cast<::OwnerClass *>((void *)&(patchesFromUid))->CallHelperWithDefaults(uid, {}); k != -1; k = patchesFromUid.GetNextChainIndex(k))
            {
                int value = patchesFromUid.getValue(k);
                reinterpret_cast<::OwnerDC9E *>(&(dependencies))->FUN_00dc9ec0(iNewClassIndex, (const ::KeyDC9E *)&(value));
            }
        }

        for (int c = 0; c < p->m_numComponent; c++)
        {
            const S_00db8670_Component& component = p->m_component[c];
            if (component.m_type == 6)
            {
                const S_00db8670_DependsPatch* dep = (const S_00db8670_DependsPatch*)component.m_patch;
                S_00db8670_Uint64 depUid = ((unsigned long long)(reinterpret_cast<::Owner_t *>((void *)(uidFromClassVersion))->FUN_00db7d60((uintptr_t)(dep->m_name), dep->m_version)));
                int depIndex = (int)patchIndexFromUid.FindValueForKey(depUid, S_00db8670_Uint64(-1));
                if (depIndex != -1)
                {
                    reinterpret_cast<::OwnerDC9E *>(&(dependencies))->FUN_00dc9ec0(depIndex, (const ::KeyDC9E *)&(iNewClassIndex));
                }
                for (int k = reinterpret_cast<::OwnerClass *>((void *)&(patchesFromUid))->CallHelperWithDefaults(depUid, {}); k != -1;
                     k = patchesFromUid.GetNextChainIndex(k))
                {
                    int value = patchesFromUid.getValue(k);
                    reinterpret_cast<::OwnerDC9E *>(&(dependencies))->FUN_00dc9ec0(iNewClassIndex, (const ::KeyDC9E *)&(value));
                }
            }
        }

        if (p->m_oldVersion == -1)
        {
            if (((int)(::LookupWithDefault((::HashEntryTable *)&(patchesFromName), (S_00db8670_Ulong)name))) != -1)
            {
                intptr_t k = ((int)(::LookupWithDefault((::HashEntryTable *)&(patchesFromName), (S_00db8670_Ulong)name)));
                if (k != -1)
                {
                    int lastIndex = reinterpret_cast<::Cls_t *>(this)->FindEntry(uid, 0, {});
                    S_00db8670_MultiMapUlong* target;
                    if (lastIndex == -1)
                    {
                        if (reinterpret_cast<::hkObjectD878 *>((void *)&(newClassNames))->GetValue((intptr_t)(name), -1) != -1)
                        {
                            return 1;
                        }
                        reinterpret_cast<::hkStringMapD874 *>(&(newClassNames))->FUN_00d874d0(name, j);
                        target = &dependencies;
                    }
                    else
                    {
                        target = &renames;
                    }
                    do
                    {
                        int value = patchesFromName.getValue(k);
                        if (lastIndex != value)
                        {
                            reinterpret_cast<::OwnerDC9E *>((target))->FUN_00dc9ec0(iNewClassIndex, (const ::KeyDC9E *)&(value));
                        }
                        k = patchesFromName.GetNextChainIndex(k);
                    } while (k != -1);
                }
            }
        }
    }

    for (int it = renames.m_pHashFunction.GetFirstIterator(); renames.m_pHashFunction.isValid(it);
         it = renames.m_pHashFunction.getNext(it))
    {
        S_00db8670_Ulong key = renames.m_pHashFunction.GetIteratorKey(it);
        for (intptr_t k = ((int)(::LookupWithDefault((::HashEntryTable *)&(renames), key))); k != -1; k = renames.GetNextChainIndex(k))
        {
            S_00db8670_MapUlong visited;
            int value = renames.getValue(k);
            if (!FUN_00db7e70(key, value, dependencies, visited))
            {
                reinterpret_cast<::OwnerDC9E *>(&(dependencies))->FUN_00dc9ec0(key, (const ::KeyDC9E *)&(value));
            }
        }
    }

    S_00db8670_Array<const S_00db8670_PatchInfo*> sorted;
    reinterpret_cast<::FUN_00d9ec10_cls *>((void *)&(sorted))->SwapThreeInts((int *)&(m_kPatchInfos));
    S_00db8670_Array<int> newIndex;
    newIndex.SetSizeAndGrow(sorted.GetLogicalSize(), -1);
    S_00db8670_Array<int> stack;
    int next = 0;
    for (int i = 0; i < sorted.GetLogicalSize(); i++)
    {
        next = ::fnv_00db83c0::FUN_00db83c0(i, (::fnv_00db83c0::hkIntArray *)&(newIndex), (::fnv_00db83c0::Graph *)&(dependencies), next, (::fnv_00db83c0::hkIntArray *)&(stack), (intptr_t)&(sorted));
    }

    m_kPatchInfos.SetSizeAndGrow(sorted.GetLogicalSize());
    for (int i = 0; i < sorted.GetLogicalSize(); i++)
    {
        int n = newIndex[i];
        if (n < 0)
        {
            reinterpret_cast<::FUN_00d9ec10_cls *>((void *)&(m_kPatchInfos))->SwapThreeInts((int *)&(sorted));
            return 1;
        }
        m_kPatchInfos[n] = sorted[i];
    }

    patchIndexFromUid.clear();
    for (int i = 0; i < m_kPatchInfos.GetLogicalSize(); i++)
    {
        const S_00db8670_PatchInfo* p = m_kPatchInfos[i];
        if (p->m_oldName)
        {
            patchIndexFromUid.insert(((unsigned long long)(reinterpret_cast<::Owner_t *>((void *)(m_pUidFromClassVersion))->FUN_00db7d60((uintptr_t)(p->m_oldName), p->m_oldVersion))), i);
        }
    }
    return 0;
}
extern void WriteSwapped(void* data, int elem, int bytes);
struct Ctx
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void FUN_00d60830(ClockObj* c, int f);
    void FUN_00d60590();
    void WriteSwapped(void* data, int elem, int count);
};
struct MapBool
{
    char value;
    MapBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct LocObj
{
    int l00;
    int l04;
    int l08;
    int l0c;
    void FUN_00d60830(ClockObj* c, int f);
    void WriteSwapped(void* data, int elem, int bytes);
    void WriteInt(int v);
    void FUN_00d607b0(int v, int n);
    void FUN_00d60590();
};
struct Pair8
{
    int p0;
    intptr_t p1;
};
struct Record16
{
    int value;
    int key;
    int unk08;
    int unk0c;
    __forceinline int GetIteratorKey() const
    {
        return key;
    }
};
struct Record12
{
    int value;
    int key;
    int unk08;
};
template <class T> struct Vec
{
    T* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    Vec() : m_data(0), m_iElementCount(0), m_cap((int)0x80000000)
    {}
};
typedef Vec<Pair8> Arr8;
struct Stats
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int start;
    int end1;
    int end2;
    int end3;
    int end4;
    int end5;
    int end6;
};
struct SrcOptions
{
    int unk00;
    int unk04;
    unsigned char flag08;
};
struct SubVec
{
    int v00;
    int v04;
    int v08;
    void SwapThreeInts(Arr8* a);
};

struct Entry52
{
    Triple first;
    Triple second;
    Triple third;
    Triple fourth;
    int trailing;
    Entry52() : trailing(0)
    {}
};
struct Arr52
{
    Entry52* m_data;
    int m_iElementCount;
    int m_cap;
};
struct Sub20Obj
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void write(ClockObj* c, int a, intptr_t b, Arr8* arr);
    int unk04;
    int unk08;
    int unk0c;
};
struct Src
{
    SrcOptions* unk00;
    Stats* unk04;
    int count08;
    int unk0c;
    Arr8 arr10;
    ClockObj* clock1c;
    Sub20Obj sub20;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Arr52 arr40;
    unsigned char flag4c;
    unsigned char unk4d;
    unsigned char unk4e;
    unsigned char unk4f;
};
struct ThisEntry
{
    int t00;
    intptr_t t04;
    int t08;
    int t0c;
    int t10;
    int t14;
    __forceinline const char* getName();
};
__forceinline const char* ThisEntry::getName()
{
    return reinterpret_cast<::FnvClassNameNode *>((((FUN_00d46d40_s*)t04)))->FUN_00d46d40();
}
struct ThisSub
{
    int d00;
    int d04;
    int d08;
    int LookupHashEntry(int val, int def);
};
struct ThisSub1
{
    int d00;
    int LookupHashEntry(int val, int def);
};
struct PairMap
{
    Pair8* data;
    int size;
    int last;
};
struct ThisCls
{
    int unk00;
    int unk04;
    Vec<ThisEntry> entries;
    ThisSub sub14;
    ThisSub1 sub20o;
    int unk24;
    int unk28;
    PairMap map2c;
    int GetOrAddString(int v);
    void FUN_00dbcea0(Src* arg);
};
extern intptr_t DAT_011b7aec;
extern int __cdecl FUN_00cb10d0(void* p);
struct Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    BDBD910Allocator* heap;
    __forceinline BDBD910Allocator& getHeap()
    {
        return *heap;
    }
};
extern "C" void _ReadWriteBarrier();

extern void FUN_00ec61c0(void* dst, int value, int n);
static __declspec(noinline) void FUN_00dbcdd0(ClockObj* obj0, unsigned int count)
{
    S00dbcdd0_Obj* obj = (S00dbcdd0_Obj*)obj0;
    int value = (int)obj->unk20();
    S00dbcdd0_Arr arr;
    arr.m_data = &arr.u0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000020;
    S00dbcdd0_Alloc& heap = ((S00dbcdd0_Holder*)FUN_00c85750())->heap();
    int cap = (int)(arr.m_capFlags & 0x3fffffff);
    if (cap < (int)count)
    {
        int newCap = cap + cap;
        if ((int)count >= newCap)
        {
            newCap = (int)count;
        }
        ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap), (::SpawnedArray *)(void *)(&arr), newCap, 1);
    }
    intptr_t end = (intptr_t)arr.m_data + arr.m_iElementCount;
    int fill = (int)count - arr.m_iElementCount;
    if (fill > 0)
    {
        FUN_00ec61c0((void*)end, -1, fill);
    }
    int r = ((int)count - 1) & value;
    arr.m_iElementCount = (int)count;
    if (r != 0)
    {
        obj->unk10(arr.m_data, count - r);
    }
    S00dbcdd0_Alloc& heap2 = ((S00dbcdd0_Holder*)FUN_00c85750())->heap();
    unsigned int capFlags = arr.m_capFlags;
    arr.m_iElementCount = 0;
    if ((capFlags & 0x80000000u) == 0)
    {
        heap2.Free(arr.m_data, capFlags & 0x3fffffff);
    }
}

struct Work
{
    Arr8 a1;
    Vec<Record16> a2;
    Vec<Record12> a3;
    Arr8 a4;
    int extra;
    Work() : extra(0)
    {}
};

template <class A> __forceinline void Reserve(A& array, BDBD910Allocator& alloc, int n, int size)
{
    int cap = array.m_cap & 0x3fffffff;
    if (cap < n)
    {
        cap *= 2;
        if (n >= cap)
            cap = n;
        ::FUN_00c908c0((::SpawnedObject *)(void *)(&alloc), (::SpawnedArray *)(void *)(&array), cap, size);
    }
}
template <class T> __forceinline void Destroy(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        reinterpret_cast<::FUN_00e028e0 *>(&(p[i]))->FUN_00e028e0::~FUN_00e028e0();
}
template <class T> __forceinline void Construct(T* p, int count)
{
    for (int i = 0; i < count; ++i)
        new (p + i) T();
}
__forceinline void Resize52(Arr52& a, int n)
{
    BDBD910Allocator& alloc = ((Router*)FUN_00c85750())->getHeap();
    Reserve(a, alloc, n, 52);
    Destroy(a.m_data + n, a.m_iElementCount - n);
    Construct(a.m_data + a.m_iElementCount, n - a.m_iElementCount);
    a.m_iElementCount = n;
}
__forceinline void Resize8(Arr8& a, int n)
{
    BDBD910Allocator& alloc = ((Router*)FUN_00c85750())->getHeap();
    Reserve(a, alloc, n, 8);
    a.m_iElementCount = n;
}
template <unsigned Bytes> __forceinline void CopyWords(void* dst, const void* src)
{
    unsigned cursor = 0;
    do
    {
        ((unsigned*)dst)[cursor] = ((const unsigned*)src)[cursor];
    } while (++cursor < Bytes / sizeof(unsigned));
}

typedef void* MapIter;
__forceinline Pair8& ExpandOne(Arr8& a, Router& router)
{
    if (a.m_iElementCount == (a.m_cap & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(router.heap), (::AudioStream *)(void *)(&a), 8);
    return a.m_data[a.m_iElementCount++];
}
__forceinline void RemoveAt(Vec<Record16>& a, int index, int byteOffset)
{
    --a.m_iElementCount;
    if (a.m_iElementCount != index)
        CopyWords<16>((char*)a.m_data + byteOffset, a.m_data + a.m_iElementCount);
}
__forceinline MapIter BeginPairs(PairMap* map)
{
    intptr_t i = 0;
    while (i <= map->last)
    {
        if (map->data[i].p0 != -1)
            break;
        ++i;
    }
    return (MapIter)i;
}
__forceinline MapIter NextPair(PairMap* map, MapIter previous)
{
    intptr_t i = (intptr_t)previous + 1;
    while (i <= map->last)
    {
        if (map->data[i].p0 != -1)
            break;
        ++i;
    }
    return (MapIter)i;
}
// Calls WriteNodeDiff for four globals and unseen entries, writes per-counter data, records timings, and resizes two arrays.
// @fnv 0x00dbcea0
void ThisCls::FUN_00dbcea0(Src* apSrc)
{
    int i, j, counter, iResult;
    int objectBytes;
    (void)objectBytes;
    (void)counter;
    Stats* stats = apSrc->unk04;
    stats->start = apSrc->clock1c->Get20();
    {
        LocObj locObj;
        new ((void *)&(locObj)) ::FUN_00d87790((*(int *)&(const ::MapBool &)(MapBool(false))));
        void* tbl[4];
        tbl[0] = &::g_0126cae8;
        tbl[1] = &::g_0126ca58;
        tbl[2] = &::g_0126cab8;
        tbl[3] = &::g_0126ca88;
        for (i = 0; i < 4; i++)
        {
            FUN_00d46d40_s* g = (FUN_00d46d40_s*)tbl[i];
            const char* name = reinterpret_cast<::FnvClassNameNode *>((g))->FUN_00d46d40();
            reinterpret_cast<::hkStringMapD874 *>(&(locObj))->FUN_00d874d0(name, 1);
            ::WriteNodeDiff((::FUN_00dbc6f0_cls_owner *)this, (::FUN_00dbc6f0_cls_source *)(apSrc), (intptr_t)(tbl[i]));
        }
        for (j = 0, objectBytes = 0; j < entries.m_iElementCount; j++, objectBytes += sizeof(ThisEntry))
        {
            void* found = ((void *)(reinterpret_cast<::FUN_00d87820_Class *>(&(locObj))->FindStringKey((intptr_t)(((ThisEntry*)((char*)entries.m_data + objectBytes))->getName()))));
            MapBool has = (*(::MapBool *)(reinterpret_cast<::FUN_00d874b0_class *>(&(locObj))->SetBoolFromThreshold((char *)((intptr_t)found), {})));
            if (!has)
            {
                const char* name = ((ThisEntry*)((char*)entries.m_data + objectBytes))->getName();
                reinterpret_cast<::hkStringMapD874 *>(&(locObj))->FUN_00d874d0(name, 1);
                ::WriteNodeDiff((::FUN_00dbc6f0_cls_owner *)this, (::FUN_00dbc6f0_cls_source *)(apSrc), (intptr_t)((void*)((ThisEntry*)((char*)entries.m_data + objectBytes))->t04));
            }
        }
        FUN_00dbcdd0(apSrc->clock1c, 16);
        int d = apSrc->clock1c->Get20() - stats->start;
        stats->end1 = d;
        stats->end2 = d;
        stats->end3 = d;
        stats->end4 = d;
        stats->end5 = d;
        stats->end6 = d;
        reinterpret_cast<::FUN_00d877d0_class *>(&(locObj))->FreeBuffer();
    }
    Resize8(apSrc->arr10, entries.m_iElementCount);
    Resize52(apSrc->arr40, apSrc->count08);
    iResult = reinterpret_cast<::hkStringPoolXdbdd40 *>((((FUN_00dbdd40_s*)this)))->GetOrAddString((const char *)(DAT_011b7aec));
    for (counter = 1; counter < apSrc->count08; counter++)
    {
        stats = apSrc->unk04 + counter;
        stats->start = apSrc->clock1c->Get20();
        Work work;
        SrcOptions* u0 = apSrc->unk00;
        if (u0->flag08 != 0 || counter != iResult)
        {
            for (int idx = 0; idx < entries.m_iElementCount; idx++)
            {
                ThisEntry* pEntry = &entries[idx];
                if (pEntry->t10 == counter)
                {
                    int saved0 = pEntry->t00;
                    intptr_t saved4 = pEntry->t04;
                    int ai = idx;
                    apSrc->arr10.m_data[ai].p0 = counter;
                    Pair8* pair = &apSrc->arr10.m_data[ai];
                    pair->p1 = apSrc->clock1c->Get20() - stats->start;
                    if (saved4 != 0)
                    {
                        apSrc->sub20.write(apSrc->clock1c, saved0, saved4, &work.a1);
                    }
                    else
                    {
                        apSrc->clock1c->c10(pEntry->t00, pEntry->t14);
                    }
                }
            }
        }
        else
        {
            int idx = 0;
            if (idx < entries.m_iElementCount)
            {
                objectBytes = 0;
                do
                {
                    if (((ThisEntry*)((char*)entries.m_data + objectBytes))->t10 == iResult)
                    {
                        apSrc->arr10.m_data[idx].p0 = -1;
                        apSrc->arr10.m_data[idx].p1 = -1;
                    }
                    objectBytes += sizeof(ThisEntry);
                } while (++idx < entries.m_iElementCount);
            }
        }
        for (int k = 0; k < work.a1.m_iElementCount; k++)
        {
            work.a1.m_data[k].p0 -= stats->start;
            work.a1.m_data[k].p1 -= stats->start;
        }
        {
            int jfix = work.a2.m_iElementCount - 1;
            if (jfix >= 0)
            {
                FUN_00dce8d0_class* imports = (FUN_00dce8d0_class*)&sub20o;
                objectBytes = jfix * 16;
                for (; jfix >= 0; jfix--, objectBytes -= 16)
                {
                    intptr_t found = reinterpret_cast<::FUN_00cb1930_t *>((imports))->LookupHashEntry(
                        (unsigned long)((Record16*)((char*)work.a2.m_data + objectBytes))->GetIteratorKey(), 0);
                    if (found != 0)
                    {
                        Record16* elem = (Record16*)((char*)work.a2.m_data + objectBytes);
                        Pair8* out = &ExpandOne(work.a4, *(Router*)FUN_00c85750());
                        out->p0 = elem->value - stats->start;
                        out->p1 = found;
                        RemoveAt(work.a2, jfix, objectBytes);
                    }
                }
            }
        }
        Ctx ctx;
        new ((void *)&(ctx)) ::FUN_00d60830((::hkReferencedObject *)(apSrc->clock1c), apSrc->flag4c);
        stats->end1 = apSrc->clock1c->Get20() - stats->start;
        reinterpret_cast<::Archive *>(&(ctx))->WriteSwapped(work.a1.m_data, 4, work.a1.m_iElementCount * 2);
        FUN_00dbcdd0(apSrc->clock1c, 16);
        stats->end2 = apSrc->clock1c->Get20() - stats->start;
        apSrc->clock1c->c1c(work.a2.m_iElementCount * 12, 1);
        ((FUN_00d9ec10_cls*)&apSrc->arr40.m_data[counter].second)->SwapThreeInts((int*)&work.a2);
        FUN_00dbcdd0(apSrc->clock1c, 16);
        stats->end3 = apSrc->clock1c->Get20() - stats->start;
        apSrc->clock1c->c1c(work.a3.m_iElementCount * 12, 1);
        ((FUN_00d9ec10_cls*)&apSrc->arr40.m_data[counter].third)->SwapThreeInts((int*)&work.a3);
        FUN_00dbcdd0(apSrc->clock1c, 16);
        stats->end4 = apSrc->clock1c->Get20() - stats->start;
        {
            MapIter idx = BeginPairs(&map2c);
            bool flag = false;
            if ((intptr_t)idx <= map2c.last)
            {
                for (;;)
                {
                    Pair8* pr = map2c.data + (intptr_t)idx;
                    int v = pr->p0;
                    intptr_t foundIdx = reinterpret_cast<::FUN_00cb1930_t *>((((FUN_00dce8d0_class*)&sub14)))->LookupHashEntry((unsigned long)v, (unsigned long)-1);
                    if (foundIdx >= 0)
                    {
                        ThisEntry* pEntry = &entries[foundIdx];
                        if (pEntry->t10 == counter)
                        {
                            intptr_t second = (map2c.data + (intptr_t)idx)->p1;
                            intptr_t av = apSrc->arr10.m_data[foundIdx].p1;
                            flag = true;
                            reinterpret_cast<::hkOArchive_2 *>((((FUN_00d60940_Class*)&ctx)))->WriteInt((unsigned int)av);
                            int r = FUN_00cb10d0((void*)second);
                            reinterpret_cast<::FUN_00d607b0_class *>((((FUN_00d607b0_s*)&ctx)))->FUN_00d607b0(second);
                            FUN_00dbcdd0(apSrc->clock1c, 4);
                        }
                    }
                    idx = NextPair(&map2c, idx);
                    if ((intptr_t)idx > map2c.last)
                        break;
                }
            }
            if (flag)
            {
                reinterpret_cast<::hkOArchive_2 *>((((FUN_00d60940_Class*)&ctx)))->WriteInt((unsigned int)-1);
                FUN_00dbcdd0(apSrc->clock1c, 16);
            }
        }
        stats->end5 = apSrc->clock1c->Get20() - stats->start;
        for (int k = 0; k < work.a4.m_iElementCount; k++)
        {
            Pair8* pr = work.a4.m_data + k;
            reinterpret_cast<::hkOArchive_2 *>((((FUN_00d60940_Class*)&ctx)))->WriteInt((unsigned int)pr->p0);
            int r = FUN_00cb10d0((void*)pr->p1);
            reinterpret_cast<::FUN_00d607b0_class *>((((FUN_00d607b0_s*)&ctx)))->FUN_00d607b0(pr->p1);
            FUN_00dbcdd0(apSrc->clock1c, 4);
        }
        if (work.a4.m_iElementCount != 0)
        {
            reinterpret_cast<::hkOArchive_2 *>((((FUN_00d60940_Class*)&ctx)))->WriteInt((unsigned int)-1);
            ((FUN_00d9ec10_cls*)&apSrc->arr40.m_data[counter].fourth)->SwapThreeInts((int*)&work.a4);
            FUN_00dbcdd0(apSrc->clock1c, 16);
        }
        stats->end6 = apSrc->clock1c->Get20() - stats->start;
        reinterpret_cast<::D60590Object *>(&(ctx))->FUN_00d60590();
        reinterpret_cast<::FUN_00e028e0 *>(&(work))->FUN_00e028e0::~FUN_00e028e0();
    }
}

namespace SectionTagsPrivate {

struct Header
{
    char tag[19];
    char terminator;
    int dataStart;
    int localFixups;
    int globalFixups;
    int finishFixups;
    int exports;
    int imports;
    int end;
    Header()
    {
        FUN_00cb1280(this, 0, 4);
    }
};

struct HeaderArray
{
    Header* data;
    int size;
    int capacity;
    int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
};

struct Context
{
    void* options;
    HeaderArray headers;
};

extern "C" void __cdecl CopyIfNonEmpty(char* dst, const char* src, int count);

template <class T> __forceinline void ConstructHeaders(T* first, int count)
{
    for (int i = 0; i < count; ++i)
        new (first + i) T;
}

struct Writer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    const char** tags;
    int tagCount;
    void FUN_00dbc7a0(Context* context);
};

// Resizes the header array to tagCount, initializes its data range to -1, and copies 19 bytes from each tag.
// @fnv 0x00dbc7a0
void Writer::FUN_00dbc7a0(Context* context)
{
    HeaderArray* headers = &context->headers;
    int count = tagCount;
    BDBD910Allocator& allocator = ((Router*)FUN_00c85750())->getHeap();
    if (headers->getCapacity() < count)
    {
        int capacity = 2 * headers->getCapacity();
        ::FUN_00c908c0((::SpawnedObject *)(void *)(&allocator), (::SpawnedArray *)(headers), count < capacity ? capacity : count, 48);
    }
    ConstructHeaders(headers->data + headers->size, count - headers->size);
    headers->size = count;
    uintptr_t bytes = (::FUN_00dbd720)((uintptr_t)(headers));
    FUN_00cb1280(headers->data, -1, (int)bytes);
    for (int i = 0; i < tagCount; ++i)
        (CopyIfNonEmpty)(headers->data[i].tag, tags[i], 19);
}

}

#include "generated/data/havok/common/serialize/packfile/binary/hkbinarypackfilewriter.inc"
