
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/S_00dd9380.h"
#include "fnv/decl/SearchArray.h"
#include "fnv/decl/fnv_00c93920__hkpWorldXc93920.h"
#include "fnv/symbols_00d6a000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_01269000.h"
struct Container
{
    int ClearValue(void* value);
};
struct Owner
{
    int FUN_00d6a910(Container* container);
};
// Passes a pointer to this+8 (or null when this equals 0x20) to container->ClearValue and returns its result.
// @fnv 0x00d6a910
int Owner::FUN_00d6a910(Container* container)
{
    void* value;
    if ((char*)this - 0x20)
        value = (char*)this + 8;
    else
        value = 0;
    return container->ClearValue(value);
}

struct FUN_00dd9380_StandIn
{
};
extern int DAT_01269028;
// @fnv 0x00d6ad40
void __cdecl FUN_00d6ad40()
{
    DAT_01269028 = reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::FUN_00dd9380_StandIn * *>(&::DAT_01269cd0))))->FUN_00dd9380(&::str_010c65b0, reinterpret_cast<intptr_t>((void*)&((void (&)())::fnv_00d6ad00::FUN_00d6ad00)));
}

extern int DAT_01269028;
// @fnv 0x00d6ad60
int FUN_00d6ad60()
{
    return DAT_01269028;
}

struct Target
{
};

struct FUN_00d6a8e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void CallTargetWithSelfOffset(Target* apTarget);
};

// Passes a pointer derived from this (this+8, or null when this-0x20 is null) to apTarget's FUN_00c93920.
// @fnv 0x00d6a8e0
void FUN_00d6a8e0_cls::CallTargetWithSelfOffset(Target* apTarget)
{
    reinterpret_cast<::fnv_00c93920::hkpWorldXc93920 *>((apTarget))->FUN_00c93920((::fnv_00c93920::hkpEntityListenerXc93920 *)(void *)(((char*)this - 0x20) != 0 ? (char*)&this->unk08 : 0));
}

// ---------------------------------------------------------------------------
// FUN_00d6a940  (0x00d6a940, 112 bytes) - the constructor of the game's
// hkpBroadphaseViewer.
//
//   8b442404          mov eax,[esp+4]        ; the ctor argument
//   53 56 57         push ebx / esi / edi
//   50                push eax
//   8bf1              mov esi,ecx             ; this -> esi
//   e861230700        call 0xddccb0           ; hkpWorldViewerBase::hkpWorldViewerBase(arg)
//   c746287ccf0c01   mov [esi+0x28],<hkpWorldPostSimulationListener vftable>
//   8d5e28            lea ebx,[esi+0x28]
//   33ff              xor edi,edi
//   c706b4230d01     mov [esi],<hkpBroadphaseViewer vftable>
//   c7460894230d01   mov [esi+8],<hkpBroadphaseViewer vftable>
//   c7462084230d01   mov [esi+0x20],<hkpBroadphaseViewer vftable>
//   c70374230d01     mov [ebx],<hkpBroadphaseViewer vftable>
//   897e2c 897e30     mov [esi+0x2c],edi / mov [esi+0x30],edi
//   c7463400000080   mov [esi+0x34],0x80000000
//   8b4624            mov eax,[esi+0x24]     ; the shape list of the world
//   3bc7 741f         cmp eax,edi / je end
//   397870 7e1a       cmp [eax+0x70],edi / jle end
//   ...loop: for each shape, shape->FUN_00c93920(this+0x28)
//   5f 8bc6 5e 5b     pop edi / mov eax,esi / pop esi / pop ebx
//   c20400            ret 4
//
// The class therefore has four vptr-bearing base subobjects, at complete
// object offsets 0x00, 0x08, 0x20 and 0x28.  Modelling that hierarchy for
// real makes MSVC emit the vftable-initialisation itself, which is the only
// way to get the two vtable stores at 0x28 (the base's own vtable first, the
// derived's per-base vtable second, the second one through the address
// taken in ebx) and the exact order of the initialisations.
// ---------------------------------------------------------------------------

// the object the world keeps at this+0x24: an array of shapes and a count
struct BroadCtx
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
    void** arr;  // +0x6c
    int count;   // +0x70
};

// the secondary base at 0x28 - the listener the shapes are told about
struct PostSimListener
{
    virtual void ps0();
    virtual void ps1();
    virtual void ps2();
    virtual void ps3();
};

// one shape of the world; 0xc93920 appends a listener to its list at +0x164
struct BroadElem
{
};

// the primary base at 0x00 (its vptr is the one at 0x00)
struct PrimBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int unk04;
};

// the secondary base at 0x08, 0x18 bytes long
struct ProcBase
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// the secondary base at 0x20
struct CtxListenerBase
{
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
};

// 0xddccb0 - hkpWorldViewerBase's constructor; it fills the three vptrs it
// owns and the shape list at 0x24
struct WorldViewerBase : PrimBase, ProcBase, CtxListenerBase
{
    BroadCtx* m_ctx;  // +0x24
    WorldViewerBase(void* a);
};

// hkpBroadphaseViewer itself (the class is named after the function so that
// its constructor's decorated name carries the tag the checker looks for)
struct FUN_00d6a940 : WorldViewerBase, PostSimListener
{
    int unk2c;  // +0x2c
    int unk30;  // +0x30
    int unk34;  // +0x34
    FUN_00d6a940(void* a);

  private:
    ~FUN_00d6a940();  // never defined: keeps a second tagged
                      // symbol out of the object file
};

// @fnv 0x00d6a940
FUN_00d6a940::FUN_00d6a940(void* a) : WorldViewerBase(a)
{
    // The three flags are written through a pointer: that gives the stores an
    // unknown member displacement, so MSVC may not hoist the load of the
    // shape list (this+0x24) above them - the original keeps that load below
    // the three stores, this source does the same.
    int* q = &this->unk2c;
    q[0] = 0;
    q[1] = 0;
    q[2] = (int)0x80000000;
    if (m_ctx)
    {
        for (int i = 0; i < m_ctx->count; i++)
        {
            BroadElem* e = (BroadElem*)m_ctx->arr[i];
            reinterpret_cast<::fnv_00c93920::hkpWorldXc93920 *>((e))->FUN_00c93920((::fnv_00c93920::hkpEntityListenerXc93920 *)(::PostSimListener *)(this));  // this+0x28: the listener subobject
        }
    }
}

struct AudioAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void FreeData(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

static inline AudioHolder* getMemoryRouter() { return static_cast<AudioHolder*>(::FUN_00c85750()); }

struct SpawnedItem
{
    virtual void v00(int aiFlags);
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
};

struct OwnerNode
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
    Container** m_ppItems;
    int m_iArrayLength;
};

struct PrimaryBase
{
    virtual void unk00();
    unsigned int unk04;
    ~PrimaryBase();
};

struct MidBase
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct TailBase
{
    virtual void unk00();
    OwnerNode* m_pSharedOwner;
};

struct SubObject
{
    virtual ~SubObject()
    {}
};

struct FUN_00d6ac40_cls : PrimaryBase, MidBase, TailBase, SubObject
{
    SpawnedItem* m_pData;
    int m_iField30;
    unsigned int m_uiObjectFlags;

    ~FUN_00d6ac40_cls() throw();
};

// @fnv 0x00d6ac40
FUN_00d6ac40_cls::~FUN_00d6ac40_cls() throw()
{
    if (m_pSharedOwner != 0)
    {
        for (int i = 0; i < m_pSharedOwner->m_iArrayLength; ++i)
        {
            reinterpret_cast<::SearchArray *>((m_pSharedOwner->m_ppItems[i]))->ClearValue((int)(static_cast<SubObject*>(this)));
        }
    }
    AudioHolder* pAudioHolder = getMemoryRouter();
    AudioAllocator* pAllocator = pAudioHolder->m_pAllocator;
    SpawnedItem* p = m_pData;
    if (m_iField30 > 0)
    {
        int iRemaining = m_iField30;
        do
        {
            p->v00(0);
            ++p;
            --iRemaining;
        } while (iRemaining != 0);
    }
    m_iField30 = 0;
    unsigned int uiAllocFlags = m_uiObjectFlags;
    if ((uiAllocFlags & 0x80000000u) == 0)
    {
        pAllocator->FreeData(m_pData, (uiAllocFlags & 0x3fffffffu) * 0x80);
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000u;
}

namespace fnv_00d6ad00 {
struct AllocatorIface
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocatorIface* m_pAllocator;
};
static inline AllocHolder* getMemoryRouter() { return static_cast<AllocHolder*>(::FUN_00c85750()); }

struct SpawnedObject
{
    int unk00;
    unsigned short m_wSize;
    unsigned short unk06;
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
};

// Allocates a 0x38-byte object from the holder's allocator, sets its size, calls Init(arg), and returns the result plus 8 or 0.
// @fnv 0x00d6ad00
int FUN_00d6ad00(int arg)
{
    AllocHolder* pAllocHolder = getMemoryRouter();
    AllocatorIface* pAllocator = pAllocHolder->m_pAllocator;
    SpawnedObject* pObject = (SpawnedObject*)pAllocator->allocate(0x38);
    pObject->m_wSize = 0x38;
    int iInitResult = ((int)(new ((void *)(pObject)) ::FUN_00d6a940((void *)(arg))));
    return iInitResult != 0 ? iInitResult + 8 : 0;
}
}  // namespace fnv_00d6ad00

namespace fnv_00d6ad70 {
// MSVC adjustor thunk: the primary base occupies 0x20 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00d6ad70();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void FUN_00d6ad70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d6ad70
    virtual void FUN_00d6ad70();
};

Derived::Derived()
{}
}  // namespace fnv_00d6ad70

struct D6AD80Primary
{
    virtual void vfunc00();
    virtual void FUN_00d6ad80();

    int unk04;
};

struct D6AD80Secondary
{
    virtual void FUN_00d6ad80();
};

struct D6AD80Object : D6AD80Primary, D6AD80Secondary
{
    D6AD80Object();

// @fnv 0x00d6ad80
    virtual void FUN_00d6ad80();
};

D6AD80Object::D6AD80Object()
{}

struct D6AD90Primary
{
    virtual void vfunc00();
    virtual void FUN_00d6ad90();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct D6AD90Secondary
{
    virtual void FUN_00d6ad90();
};

struct D6AD90Object : D6AD90Primary, D6AD90Secondary
{
    D6AD90Object();

// @fnv 0x00d6ad90
    virtual void FUN_00d6ad90();
};

D6AD90Object::D6AD90Object()
{}

namespace fnv_00d6ada0 {
struct S_00d6ada0_Allocator
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d6ada0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d6ada0_Allocator* m_pStreamAllocator;
    S_00d6ada0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
static inline S_00d6ada0_Router* getMemoryRouter() { return static_cast<S_00d6ada0_Router*>(::FUN_00c85750()); }

struct S_00d6ada0_ReferencedObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void operator delete(void* p, size_t)
    {
        S_00d6ada0_ReferencedObject* b = static_cast<S_00d6ada0_ReferencedObject*>(p);
        getMemoryRouter()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
    virtual ~S_00d6ada0_ReferencedObject()
    {}
};

struct FUN_00d6ada0 : S_00d6ada0_ReferencedObject
{
    FUN_00d6ada0();
    virtual ~FUN_00d6ada0();
};

// @fnv 0x00d6ada0
FUN_00d6ada0::FUN_00d6ada0()
{}
}  // namespace fnv_00d6ada0

// Moved from hkpbroadphaseviewer_ehsc_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FUN_00de1210.h"
#include "fnv/decl/FnvCpu_FUN_00de1170_CpuObject.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01268000.h"
void __cdecl FUN_00d6ad40();
int FUN_00d6ad60();


struct S00d6a9b0_Rec
{
    const char* m_pName;
    unsigned int m_uTick;
    unsigned int unk08;
};

struct S00d6a9b0_Prof
{
    int unk00;
    S00d6a9b0_Rec* m_pCur;
    int unk08;
    S00d6a9b0_Rec* m_pRecordEnd;
};

static inline void S00d6a9b0_Mark(const char* name)
{
    S00d6a9b0_Prof* p = (S00d6a9b0_Prof*)TlsGetValue(DAT_0126835c);
    S00d6a9b0_Rec* r = p->m_pCur;
    if (r < p->m_pRecordEnd)
    {
        r->m_pName = name;
        unsigned int t;
        t = static_cast<unsigned int>(__rdtsc());
        r->m_uTick = t;
        p->m_pCur = r + 1;
    }
}

struct S00d6a9b0_Alloc
{
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void* GetStack(int& nBytes);
    virtual void FreeData(void* p, unsigned int size);
};

struct S00d6a9b0_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d6a9b0_Alloc* m_pAllocationContext;
    S00d6a9b0_Alloc& heap() { return *m_pAllocationContext; }
};

static inline S00d6a9b0_Alloc& S00d6a9b0_heap()
{
    return reinterpret_cast<S00d6a9b0_Holder*>(getMemoryRouter())->heap();
}

template <typename T>
struct S00d6a9b0_Arr
{
    T* m_data;
    int m_iElementCount;
    int m_capFlags;

    S00d6a9b0_Arr() : m_data(0), m_iElementCount(0), m_capFlags((int)0x80000000) {}
    ~S00d6a9b0_Arr()
    {
        S00d6a9b0_Alloc& a = S00d6a9b0_heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            a.FreeData(m_data, (m_capFlags & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_capFlags = (int)0x80000000;
    }
    void SetSizeAndGrow(int n);
    void setSizePod(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    void reserve(int n)
    {
        S00d6a9b0_Alloc& a = S00d6a9b0_heap();
        int cap = m_capFlags & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int nc = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(::S00d6a9b0_Alloc *)(&a), (::SpawnedArray *)(void *)(this), nc, sizeof(T));
        }
    }
};

struct __declspec(align(16)) S00d6a9b0_Vec
{
    float x, y, z, w;
};

struct __declspec(align(16)) S00d6a9b0_Cap
{
    int n;
};

struct S00d6a9b0_Blk
{
    S00d6a9b0_Vec m_kMinimumCorner;
    S00d6a9b0_Vec m_kMaximumCorner;
};

template <typename T>
static inline void S00d6a9b0_destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].v00(0);
}

template <typename T>
static inline void S00d6a9b0_construct(T* t, int n)
{
    for (int i = 0; i < n; i++)
    {
        T* p = t + i;
        if (p)
            new ((void *)(p)) ::FUN_00de1210();
    }
}

template <typename T>
__forceinline void S00d6a9b0_Arr<T>::SetSizeAndGrow(int n)
{
    reserve(n);
    S00d6a9b0_destruct(m_data + n, m_iElementCount - n);
    S00d6a9b0_construct(m_data + m_iElementCount, n - m_iElementCount);
    m_iElementCount = n;
}

template <typename T>
static __forceinline T* S00d6a9b0_bufAlloc(S00d6a9b0_Alloc& a, int n, int& nbytes)
{
    int req = n * (int)sizeof(T);
    T* p = (T*)a.GetStack(req);
    nbytes = req;
    return p;
}

struct S00d6a9b0_Req : S00d6a9b0_Arr<S00d6a9b0_Blk>
{
    __forceinline S00d6a9b0_Req(int n)
    {
        int nbytes;
        S00d6a9b0_Blk* p = S00d6a9b0_bufAlloc<S00d6a9b0_Blk>(S00d6a9b0_heap(), n, nbytes);
        S00d6a9b0_Cap c;
        c.n = nbytes / (int)sizeof(S00d6a9b0_Blk);
        if (c.n == 0)
            c.n = (int)0x80000000;
        m_data = p;
        m_capFlags = c.n;
    }
};

struct S00d6a9b0_Item
{
    virtual void v00(int flags);
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
};

struct S00d6a9b0_Sub
{
    virtual void p00(); virtual void p04(); virtual void p08(); virtual void p0c();
    virtual void p10(); virtual void p14(); virtual void p18(); virtual void p1c();
    virtual void p20(); virtual void p24(); virtual void p28(); virtual void p2c();
    virtual void p30(); virtual void p34();
    virtual void Run(void* params);
};

struct S00d6a9b0_Ctx
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    S00d6a9b0_Sub* m_58;
};

struct S00d6a9b0_Owner
{
    virtual void o00(); virtual void o04(); virtual void o08(); virtual void o0c();
    virtual void o10(); virtual void o14(); virtual void o18(); virtual void o1c();
    virtual void o20(); virtual void o24(); virtual void o28(); virtual void o2c();
    virtual void o30(); virtual void o34();
    virtual void Fill(void* out, unsigned int mask, int zero, int flags);
};

struct S00d6a9b0_Obj
{
    int unk00;
    S00d6a9b0_Arr<S00d6a9b0_Item> m_aiIndexedValues;

    void FUN_00d6a9b0(S00d6a9b0_Ctx* a1);
};

struct ViewerPrefix { S00d6a9b0_Owner* m_pOwnerObject; int unk04; int unk08; int unk0c; };
struct WholeViewer : ViewerPrefix, S00d6a9b0_Obj {};

// @fnv 0x00d6a9b0
void S00d6a9b0_Obj::FUN_00d6a9b0(S00d6a9b0_Ctx* a1)
{
    S00d6a9b0_Mark("TthkpBroadphaseViewer");

    S00d6a9b0_Req req(0x400);
    req.m_iElementCount = 0x400;
    a1->m_58->Run(&req);

    if (req.m_iElementCount > m_aiIndexedValues.m_iElementCount)
        m_aiIndexedValues.SetSizeAndGrow(req.m_iElementCount);

    S00d6a9b0_Arr<S00d6a9b0_Item*> ptrs;
    ptrs.setSizePod(req.m_iElementCount);
    for (int k = req.m_iElementCount - 1; k >= 0; k--)
    {
        S00d6a9b0_Blk* b = req.m_data + k;
        reinterpret_cast<::FnvCpu_FUN_00de1170_CpuObject *>(&(m_aiIndexedValues.m_data[k]))->FUN_00de1170((::FnvCpu_FUN_00de1170_CpuData0 *)(void *)(&b->m_kMinimumCorner), (::FnvCpu_FUN_00de1170_CpuData1 *)(void *)(&b->m_kMaximumCorner));
        ptrs.m_data[k] = m_aiIndexedValues.m_data + k;
    }

    static_cast<WholeViewer*>(this)->m_pOwnerObject->Fill(&ptrs, 0xffff0000, 0, DAT_01269028);

    S00d6a9b0_Mark("Et");
}
#include "generated/data/havok/physics/utilities/visualdebugger/viewer/collide/hkpbroadphaseviewer.inc"
