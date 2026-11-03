// havok/common/serialize/copier/hkobjectcopier.cpp: Object, Host (12 functions)

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include "fnv/decl/Owner.h"
#include "fnv/decl/TestClass.h"
#include "fnv/decl/fnv_00e036b0__Host.h"
#include "fnv/symbols_0126c000.h"
#include <new>
#include "fnv/decl/Archive.h"
#include "fnv/decl/ClassMember_d869.h"
#include "fnv/decl/D60590Object.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00d46f00_s.h"
#include "fnv/decl/FUN_00d46fe0_Class.h"
#include "fnv/decl/FUN_00d605b0_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00d607e0_class.h"
#include "fnv/decl/FUN_00d60800_class.h"
#include "fnv/decl/FUN_00d60830.h"
#include "fnv/decl/FUN_00d86930_StandIn.h"
#include "fnv/decl/FUN_00db75b0_class.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/FnvCpu_FUN_00d470d0_CpuObject.h"
#include "fnv/decl/HkClassNode.h"
#include "fnv/decl/OwnerD869.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/Struct_d86920.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/decl/hkOwnerXdb76f0.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_00d86000.h"
#include "fnv/symbols_00e03000.h"
#include "fnv/symbols_00e04000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01044000.h"
#include "fnv/symbols_010ea000.h"
#include "fnv/symbols_01268000.h"
#include "fnv_asm_helpers.h"
// src/havok/common/serialize/copier/hkobjectcopier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/copier/hkobjectcopier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Compares byte 0xc of two entries and returns 1 if equal and byte 0xd also matches or byte 0xc is 0x18, otherwise 0.
// @fnv 0x00e032d0
int FUN_00e032d0(const void* a, const void* b)
{
    const unsigned char* pa = static_cast<const unsigned char*>(a);
    const unsigned char* pb = static_cast<const unsigned char*>(b);
    if (pa[0xc] == pb[0xc] && (pa[0xd] == pb[0xd] || pa[0xc] == 0x18))
        return 1;
    return 0;
}

// @fnv 0x00e049c0
int __cdecl FUN_00e049c0(int a, int b)
{
    return a < b ? a : b;
}

struct Object {
    int* vtable;
    void FUN_00e03160();
};
// @fnv 0x00e03160
void Object::FUN_00e03160() {
    vtable = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct E04A00Allocator;

struct E04A00MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E04A00Allocator* m_pStreamAllocator;

    E04A00Allocator& heap() { return *m_pStreamAllocator; }
};


struct E04A00Entry {
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
};

struct E04A00EntryArray {
    E04A00Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _pushBack(E04A00Allocator& alloc, const E04A00Entry& e)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(E04A00Entry));
        m_data[m_iElementCount] = e;
        m_iElementCount++;
    }

    void AddBack(const E04A00Entry& e) { _pushBack((*static_cast<E04A00MemoryRouter*>(::FUN_00c85750())).heap(), e); }
};

struct E04A00Registry {
    int unk00;
    int unk04;
    int unk08;
    E04A00EntryArray m_entries;

    void AddEntry(void* a, void* b, void* c, void* d);
};

// Builds an entry from the four arguments and appends it to m_entries via the registry's allocator.
// @fnv 0x00e04a00
void E04A00Registry::AddEntry(void* a, void* b, void* c, void* d)
{
    E04A00Entry e;
    e.m_kPointA = a;
    e.m_kPointB = b;
    e.m_iThirdValue = c;
    e.m_iFourthElementInteger = d;
    m_entries.AddBack(e);
}

// FUN_00e03100
//
// The object pointer reaches this function in ESI (the compiler passes the
// argument of the internal-linkage function in the callee-saved register),
// and the accessor at 0xd86940 returns the signed short stored at +0x0e of
// the object.  The value is tested once and, when it is not zero, the
// accessor is called a second time (as a tail call) to produce the result;
// when it is zero the function returns 1.
class Obj {
public:
    int m();
};

// @fnv 0x00e03100
static int FUN_00e03100(Obj* apObj) {
    if (reinterpret_cast<::OwnerD869 *>((apObj))->FUN_00d86940()) {
        return reinterpret_cast<::OwnerD869 *>((apObj))->FUN_00d86940();
    }
    return 1;
}

// The internal-linkage function above is only called from here, so that the
// compiler keeps it (and gives it the argument convention).
int keep_alive(Obj* p) {
    int r = reinterpret_cast<::OwnerD869 *>((p))->FUN_00d86940();
    return FUN_00e03100(p) + r;
}

struct FUN_00e03120 {
    virtual ~FUN_00e03120();
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    bool unk14;

    FUN_00e03120(const int* param1, const int* param2, int param3);
};

// Initializes the object from two int pointers and a third int, setting unk14 by comparing the second byte of the two stored ints.
// @fnv 0x00e03120
FUN_00e03120::FUN_00e03120(const int* piFirst, const int* piSecond, int aiValue)
    : unk06(1)
{
    unk08 = *piFirst;
    unk0C = *piSecond;
    unk10 = aiValue;
    unk14 = ((char*)&unk08)[1] != ((char*)&unk0C)[1];
}

struct Writer {
};

struct Pair {
    unsigned int lo;
    unsigned int hi;
};

extern "C" unsigned int* __cdecl FNV_e03300_arena();

// Writes count unsigned ints to w; when elemSize is not 4, widens each into a Pair (lo=data[i], hi=0) from arena memory and writes that instead.
// @fnv 0x00e03300
static __declspec(noinline) void WriteUIntArray(const unsigned int* data, int count,
                                             Writer* pWriter, int elemSize)
{
    if (elemSize == 4) {
        reinterpret_cast<::Archive *>((pWriter))->WriteSwapped(data, elemSize, count);
        return;
    }
    unsigned int* pArena = FNV_e03300_arena();
    uintptr_t base = *pArena;
    *pArena = base + (((unsigned int)count * 8 + 0x7f) & 0xffffff80u);
    Pair* pPairs = (Pair*)base;
    for (int i = 0; i < count; i++) {
        pPairs[i].lo = data[i];
        pPairs[i].hi = 0;
    }
    reinterpret_cast<::Archive *>((pWriter))->WriteSwapped(pPairs, elemSize, count);
    *FNV_e03300_arena() = base;
}

void e03300_driver(Writer* w, int elemSize, const unsigned int* data, int count)
{
    WriteUIntArray(data, count, w, elemSize);
}

// AppendListEntry
//
// The routine is an internal-linkage (static) helper of its module, so MSVC
// 2008 /O2 specialises it: its two pointer parameters arrive in callee-saved
// registers (the manager in EBX, the entry list in ESI) instead of on the
// stack, while the two integer arguments keep their stack slots.  Keeping the
// function static and calling it from exactly one place is what produces that
// convention.
//
// The first object pointer is handed to the module-local helper below, which
// is itself internal-linkage, so its arguments arrive in EDI (the pointer) and
// EAX (the integer).  That is why the caller materialises the constant 2 in
// EAX and lets the pointer stay in EDI across the call.

struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual VObj* v20();
};

struct Ctx
{
};

struct ListEntry
{
    intptr_t m_key;
    void* m_uiFilterValue;
};

struct List
{
    ListEntry* m_data;
    int m_uiItemCount;
    unsigned int m_iCapacityState;
};

int __cdecl FUN_00e03360_ext1(int);
int __cdecl FUN_00e03360_ext2(VObj* p);

// Module-local helper: the manager hands it the object it just looked up
// together with a mode value.
__declspec(noinline) static void FUN_00e03360(VObj* p, int n)
{
    int k = FUN_00e03360_ext1(n);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext1(k);
    FUN_00e03360_ext1(k);
}

// @fnv 0x00e03e20
static int AppendListEntry(Ctx* ctx, List* list, intptr_t a, intptr_t b)
{
    VObj* value = ((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((ctx))->FUN_00d60800()));
    FUN_00e03360(value, 2);
    value = ((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((ctx))->FUN_00d60800()))->v20();
    E04A00MemoryRouter& router = (*static_cast<E04A00MemoryRouter*>(::FUN_00c85750()));
    if (list->m_uiItemCount == (int)(list->m_iCapacityState & 0x3fffffffu))
    {
        ::ResizeAudioStream((::AudioAllocator *)(router.m_pStreamAllocator), (::AudioStream *)(list), 8);
    }
    ListEntry& entry = list->m_data[list->m_uiItemCount];
    entry.m_key = b;
    entry.m_uiFilterValue = value;
    list->m_uiItemCount++;
    reinterpret_cast<::FUN_00d607b0_class *>((ctx))->FUN_00d607b0(a);
    return 0;
}

// The helper above is only called from here, which keeps the register
// calling convention the original module was built with.
int keep_alive2(Ctx* ctx, List* list, int a, int b)
{
    return AppendListEntry(ctx, list, a, b);
}

struct Scratch16 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};
struct FUN_00e04920_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char m_flag14;
    unsigned int FUN_00e036b0(uintptr_t a, uintptr_t b, Scratch16* scratch, uintptr_t c);
    int FUN_00e04920(uintptr_t a1, uintptr_t a2, uintptr_t a3,
                     uintptr_t a4, uintptr_t a5);
};

// FUN_00e03360: module-local helper (custom convention: n in EAX, obj in EDI).
// lets the object fill it, then frees it.

struct HeapAlloc
{
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void a0c();
    virtual void ReleaseBlock(void* p, int size);
};

struct MemRouter
{
    char* m_stackCur;
    int unk04;
    int unk08;
    int unk0C;
    HeapAlloc* m_pStreamAllocator;
};

inline MemRouter& Router() { return reinterpret_cast<MemRouter&>((*static_cast<E04A00MemoryRouter*>(::FUN_00c85750()))); }
extern "C" void* __cdecl FUN_00ec61c0(void* dst, int val, int n);

static __forceinline void Construct(char* p, int c)
{
    for (int i = 0; i < c; ++i)
        p[i] = 0;
}
static __forceinline void Zero(char* p, int c)
{
    FUN_00ec61c0(p, 0, c);
}

struct Reader
{
    virtual void r00();
    virtual void r04();
    virtual void r08();
    virtual void r0c();
    virtual void read(char* buf, int n);
    virtual void r14();
    virtual void r18();
    virtual void r1c();
    virtual int GetReadOffset();
};

struct CharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CharArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline void destroy(HeapAlloc* h)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h->ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
    }
    __forceinline void reserve(HeapAlloc* h, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap + cap;
            ::FUN_00c908c0((::SpawnedObject *)(h), (::SpawnedArray *)(void *)(this), n < c2 ? c2 : n, 1);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(Router().m_pStreamAllocator, n);
        Construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
};

struct LocalCharArray : CharArray
{
    char* m_localMem;

    LocalCharArray(int n)
    {
        MemRouter& r = Router();
        char* p = r.m_stackCur;
        r.m_stackCur = p + ((n + 0x7f) & ~0x7f);
        m_data = p;
        m_iCapacityState = n | 0x80000000;
        m_localMem = p;
    }
    __forceinline void destroyLocal()
    {
        char* mem = m_localMem;
        if (mem == m_data)
            m_iElementCount = 0;
        Router().m_stackCur = mem;
        destroy(Router().m_pStreamAllocator);
    }
};

// Gets the reader offset and, when the computed mask is nonzero, reads n minus that mask bytes into a local buffer.
// @fnv 0x00e03360
static __declspec(noinline) void __cdecl FUN_00e03360(Reader* apReader, int aiCount)
{
    int align = apReader->GetReadOffset();
    LocalCharArray buf(aiCount);
    buf.SetSizeAndGrow(aiCount);
    int iMisalign = (aiCount - 1) & align;
    if (iMisalign != 0)
        apReader->read(buf.m_data, aiCount - iMisalign);
    buf.destroyLocal();
}

void keep_alive_b11425(Reader* obj, int a, int b)
{
    FUN_00e03360(obj, a);
    FUN_00e03360(obj, b + a);
}

struct DiagnosticWriter {
    void* vtbl;                                            // +0
    int unk04;                                             // +4
    void* p;                                               // +8
    void FUN_00cb1600(void* buf, int size);                // (this,buf,size), ret 8
    void FUN_00cc01c0(const char* msg);                    // (this,msg), ret 4
    void FUN_00cc00e0();                                   // (this), ret
};

struct Target {
                  // (this,void*,int,int)
};

struct AssertMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a, unsigned int b, char* c, const char* d, int e);
};

extern const char str_010ea3e4[];

// Calls WriteSwapped for listed type values, adjusting its integer arguments for cases 12 through 18; other values enter the diagnostic path.
// @fnv 0x00e03170
static __declspec(noinline) void FUN_00e03170(unsigned int a, unsigned int aiSize, unsigned int type, Target* apTarget, void* apData)
{
    switch (type - 1) {
    case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        aiSize >>= 2;
        a *= aiSize;
        aiSize = 4;
        /* fall through */
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 9: case 10: case 31:
        reinterpret_cast<::Archive *>((apTarget))->WriteSwapped(apData, aiSize, a);
        return;
    case 19: case 20: case 21: case 22: case 24: case 25: case 26: case 27: case 29:
        goto fail;
    default:
fail:
    {
        unsigned int buf[128];
        DiagnosticWriter w;
        new ((void *)&(w)) ::FUN_00cb1600(buf, 0x200);
        reinterpret_cast<::SinkOwner *>(&(w))->FUN_00cc01c0(str_010ea3e4);
        if ((*reinterpret_cast<::AssertMgr * *>(&::DAT_01268360))->v3(3, 0x747e1e03u, (char*)buf, str_010ea3c8, 0xfb))
            __debugbreak();
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(w))->FUN_00cc00e0::~FUN_00cc00e0();
        return;
    }
    }
}

void target_driver(unsigned int type, unsigned int count, unsigned int size, void* data, Target* target)
{
    FUN_00e03170(count, size, type, target, data);
}

namespace fnv_00e036b0 {
extern "C" void _ReadWriteBarrier();
struct Item {
    int f00; int f04; int f08;
    unsigned char type; unsigned char f0d; unsigned char f0e; unsigned char f0f;
    unsigned short f10; unsigned short f12;
    intptr_t getName() const { return f00; }
    int FUN_00d86940();
};
struct EbpObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int v1c(int a, int b);
    virtual int v20();
};
struct ExitObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int v1c(int a);
};
struct HObj {
    int Lookup(int a, void* b);
};
struct Inner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(int a, int b);
};
struct InnerHolder { int f00; int f04; int f08; int f0c; Inner* f10; };
struct Chain {
    Chain* FUN_00cc01c0(const void* s, void* a);
    Chain* FUN_00cc01c0();
    void FUN_00cc00e0();
};
struct StrBuf {
    char* data; int size; int capacity;
    void FUN_00cb1600(void* a, int n);
};
struct StreamObj {
    StreamObj* FUN_00d46fe0(int v);
};
struct DescriptorList {
    int unk00; int unk04; int unk08;
};
struct Host {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(Item* a, Item* b);
    int f04; int f08;
    unsigned char f0c; unsigned char f0d; unsigned char f0e; unsigned char f0f;
    int f10;
    StreamObj* FUN_00d46fe0(int v);
    int FUN_00e036b0(StreamObj* p0, StreamObj* p1, StreamObj* p2, DescriptorList* p3);
};
extern int DAT_010ea4ac;
extern int DAT_010ea47c;

static __declspec(noinline) int FUN_00e03100(Item* p) {
    if (p->FUN_00d86940()) return p->FUN_00d86940();
    return 1;
}

extern const char str_010ea3e4[];


struct DiagnosticWriterOrig {
    void* vtbl;
    int unk04;
    void* p;
    void FUN_00cb1600(void* buf, int size);
    DiagnosticWriterOrig* FUN_00cc01c0(const void* msg);
    void FUN_00cc00e0();
};
static DiagnosticWriterOrig& wch(DiagnosticWriter& w) { return *(DiagnosticWriterOrig*)&w; }

static __declspec(noinline) void FUN_00e03170(Target* obj, unsigned int type, unsigned int size, unsigned int count, void* data) {
    switch (type) {
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        count = count * (size / 4);
        size = 4;
        goto output;
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
    case 32:
    output:
        reinterpret_cast<::Archive *>((obj))->WriteSwapped(data, size, count);
        return;
    default: {
        unsigned int storage[128];
        DiagnosticWriter w;
        new ((void *)&(w)) ::FUN_00cb1600(storage, sizeof(storage));
        reinterpret_cast<::SinkOwner *>(&(w))->FUN_00cc01c0((const char*)str_010ea3e4);
        if ((*reinterpret_cast<::AssertMgr * *>(&::DAT_01268360))->v3(3, 0x747e1e03, (char*)storage, (const char*)&(*reinterpret_cast<int *>((void *)&::str_010ea3c8)), 0xfb)) __debugbreak();
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(w))->FUN_00cc00e0::~FUN_00cc00e0();
        return;
    }
    }
}

static __declspec(noinline) void WriteUIntArray(int count, const unsigned int* data, Writer* w, int elemSize) {
    if (elemSize == 4) {
        reinterpret_cast<::Archive *>((w))->WriteSwapped(data, elemSize, count);
        return;
    }
    {
        unsigned int* arena = FNV_e03300_arena();
        uintptr_t saved = *arena;
        *arena += (count * 8 + 127) & ~127;
        Pair* output = (Pair*)saved;
        for (int index = 0; index < count; ++index) {
            output[index].lo = data[index];
            output[index].hi = 0;
        }
        reinterpret_cast<::Archive *>((w))->WriteSwapped(output, elemSize, count);
        *FNV_e03300_arena() = saved;
    }
}

struct PointerValue { int valid; int pointer; int object; };

struct LookupResult { int value; };
struct ValueArray { int* data; int size; int capacity; };
struct Scratch { DiagnosticWriter bad; int out[2]; int pair[2]; int pair2[2]; int buf4[4]; DiagnosticWriter missing; };
// Iterates descriptor items, compares matching items, dispatches by type, and writes values through the supplied stream.
// @fnv 0x00e036b0
int Host::FUN_00e036b0(StreamObj* apSourceStream, StreamObj* apLookupStream, StreamObj* apOutputStream, DescriptorList* apDescriptorList)
{
    struct State0 { void* flagh2; int base; int index; int out40; } state0;
    struct State1 { EbpObj* ebp; int flagq; void* flagh1; LookupResult lookup; } state1;
    struct Work { int local20; int acc; ValueArray values; } work;
    unsigned int storage[128];
    Scratch scratch;
    
    
    state1.ebp = ((::fnv_00e036b0::EbpObj *)(reinterpret_cast<::FUN_00d60800_class *>((apOutputStream))->FUN_00d60800()));
    state0.base = state1.ebp->v20();
    for (state0.index = 0; state0.index < ((int)(reinterpret_cast<::FUN_00d46f00_s *>((apDescriptorList))->FUN_00d46f00())); state0.index++) {
        Item* pItem = ((::fnv_00e036b0::Item *)(reinterpret_cast<::HkClassNode *>((apDescriptorList))->FUN_00d46f20(state0.index)));
        state1.ebp->v1c((int)pItem->f12 + state0.base, 0);
        if (pItem->f10 & 0x400) {
            int fl = this->f10;
            if (fl & 2) {
                reinterpret_cast<::ZeroCopier *>((this))->FUN_00e03460((*(::ZeroArchive *)(apOutputStream)), (*(const ::ZeroMember *)(pItem)));
                continue;
            }
            if (fl & 1) {
                ::FUN_00e03240((::S_00e03240_Holder *)(apDescriptorList), (::S_00e03240_Node *)(pItem), state0.index, (intptr_t)state1.ebp);
                continue;
            }
        }
        {
            Item* nb = (Item*)((::fnv_00e036b0::StreamObj *)(reinterpret_cast<::FUN_00d46fe0_Class *>((apLookupStream))->FUN_00d46fe0((const int *)(pItem->getName()))));
            if (nb && this->v10(nb, pItem)) {
            intptr_t iSourceOffset = (int)nb->f12 + (intptr_t)apSourceStream;
            switch (pItem->type - 1) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
            case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
            case 16: case 17: case 31: {
                int x = FUN_00e03100(nb);
                int y = FUN_00e03100(pItem);
                int v = reinterpret_cast<::ClassMember_d869 *>((pItem))->FUN_00d86980();
                FUN_00e03170((Target*)apOutputStream, pItem->type, v / y, ::FUN_00e049c0(x,y), (void*)iSourceOffset);
                break;
            }
            case 29: {
                int x = FUN_00e03100(nb);
                int y = FUN_00e03100(pItem);
                int r = ::FUN_00e049c0(x, y);
                WriteUIntArray(r, (const unsigned int*)iSourceOffset, (Writer*)apOutputStream, (int)this->f0c);
                break;
            }
            case 23: {
                if (nb->f08 == 0) break;
                if (pItem->f08 == 0) break;
                int denominator = FUN_00e03100(nb);
                int u = FUN_00e03100(pItem);
                int iCount = ::FUN_00e049c0(*(volatile int*)&denominator, u);
                void* h1 = ((void *)(reinterpret_cast<::FUN_00d86930_StandIn *>((nb))->FUN_00d86930()));
                void* h2 = ((void *)(reinterpret_cast<::FUN_00d86930_StandIn *>((pItem))->FUN_00d86930()));
                int v = reinterpret_cast<::ClassMember_d869 *>((nb))->FUN_00d86980();
                int iStep = v / denominator;
                if (iCount <= 0) break;
                
                
                do {
                    int r86 = ::ReadSignedValueBySize((const void *)(nb));
                    work.local20 = 0;
                    LookupResult* __restrict pLookupResult = &state1.lookup;
                    int iResult = ((HObj*)h1)->Lookup(r86, pLookupResult);
                    if (iResult == 0) {
                        reinterpret_cast<::FUN_00db75b0_class *>((((HObj*)h2)))->FUN_00db75b0(pLookupResult->value, (unsigned int *)(void *)(&work.local20));
                    }
                    switch (iStep) {
                    case 1: reinterpret_cast<::FUN_00d605b0_class *>((apOutputStream))->FUN_00d605b0(work.local20); break;
                    case 2: ::FUN_00d60900((char *)(apOutputStream)); break;
                    case 4: reinterpret_cast<::hkOArchive_2 *>((apOutputStream))->WriteInt(work.local20); break;
                    }
                    iSourceOffset += iStep;
                    iCount--;
                } while (iCount != 0);
                break;
            }
            case 18: break;
            case 19: case 20: case 28: case 32: {
                int count;
                int rawCount = FUN_00e03100(pItem);
                scratch.pair[0] = 0; scratch.pair[1] = 0;
                if (rawCount <= 0) break;
                count = rawCount;
                do {
                    reinterpret_cast<::FUN_00d607b0_class *>((apOutputStream))->FUN_00d607b0((intptr_t)(scratch.pair));
                    count--;
                } while (count != 0);
                break;
            }
            case 21: case 25: case 26: {
                StreamObj* pStream = apOutputStream;
                intptr_t ebpInt = iSourceOffset;
                if (pItem->type == 0x1b) {
                    scratch.pair2[0] = 0; scratch.pair2[1] = 0;
                    reinterpret_cast<::Archive *>((pStream))->WriteSwapped(scratch.pair2, (int)this->f0c, 1);
                    if (((PointerValue*)ebpInt)->valid != 0) {
                        ebpInt = ((PointerValue*)ebpInt)->object;
                    } else {
                        
                        new ((void *)&(scratch.missing)) ::FUN_00cb1600(storage, 0x200);
                        reinterpret_cast<::SinkOwner *>((((::fnv_00e036b0::DiagnosticWriterOrig *)(reinterpret_cast<::SinkOwner *>((((::fnv_00e036b0::DiagnosticWriterOrig *)(reinterpret_cast<::SinkOwner *>((((::fnv_00e036b0::DiagnosticWriterOrig *)(reinterpret_cast<::SinkOwner *>((((::fnv_00e036b0::DiagnosticWriterOrig *)(reinterpret_cast<::SinkOwner *>(&(wch(scratch.missing)))->FUN_00cc01c0((const char *)(const void *)((const void*)&DAT_010ea47c))))))->FUN_00cc01c0((const char *)(const void *)((const void*)((void *)(reinterpret_cast<::FnvClassNameNode *>((apLookupStream))->FUN_00d46d40()))))))))->FUN_00cc01c0((const char *)(const void *)((const void*)&DAT_010ea4ac))))))->FUN_00cc01c0((const char *)(const void *)((const void*)nb->getName()))))))->FUN_00cc01c0((const char *)(const void *)((const void*)&(*reinterpret_cast<int *>((void *)&::DAT_01044c28))));
                        (*reinterpret_cast<::AssertMgr * *>(&::DAT_01268360))->v3(1, 0xabba5a55, (char*)storage, (const char*)&(*reinterpret_cast<int *>((void *)&::str_010ea3c8)), 0x1b8);
                        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(scratch.missing))->FUN_00cc00e0::~FUN_00cc00e0();
                        ebpInt = 0;
                    }
                } else if (pItem->f0d == 0) {
                    ebpInt = 0;
                } else {
                    ebpInt = ((PointerValue*)ebpInt)->pointer;
                }
                {
                    scratch.out[0] = 0; scratch.out[1] = 0;
                    reinterpret_cast<::Archive *>((pStream))->WriteSwapped(scratch.out, (int)this->f0c, 1);
                    reinterpret_cast<::hkOArchive_2 *>((pStream))->WriteInt(ebpInt);
                    if (pItem->type == 0x16) {
                        ebpInt |= 0x80000000;
                        reinterpret_cast<::hkOArchive_2 *>((pStream))->WriteInt(ebpInt);
                    }
                }
                break;
            }
            case 24: {
                void* h1 = ((void *)(reinterpret_cast<::Struct_d86920 *>((nb))->FUN_00d86920()));
                void* h2 = ((void *)(reinterpret_cast<::Struct_d86920 *>((pItem))->FUN_00d86920()));
                if (!h1) break;
                if (!h2) break;
                int iRemaining = ::FUN_00e049c0(FUN_00e03100(nb), FUN_00e03100(pItem));
                int k = 0;
                if (iRemaining <= 0) break;
                do {
                    int v = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((((DescriptorList*)h1)))->FUN_00d470d0();
                    const char* pElementData = (const char*)iSourceOffset + v * k;
                    this->FUN_00e036b0((StreamObj*)pElementData, (StreamObj*)h1, apOutputStream, (DescriptorList*)h2);
                    k++;
                } while (k < iRemaining);
                break;
            }
            case 27: {
                scratch.buf4[0] = 0; scratch.buf4[1] = 0; scratch.buf4[2] = 0; scratch.buf4[3] = 0;
                int rawCount = ::FUN_00e049c0(FUN_00e03100(nb), FUN_00e03100(pItem));
                if (rawCount <= 0) break;
                int iRemaining = rawCount;
                do {
                    reinterpret_cast<::Archive *>((apOutputStream))->WriteSwapped(scratch.buf4, (int)this->f0c, 2);
                    iRemaining--;
                } while (iRemaining != 0);
                break;
            }
            case 30: {
                if (nb->f08 == 0) break;
                if (pItem->f08 == 0) break;
                int denominator = FUN_00e03100(nb);
                int u = FUN_00e03100(pItem);
                int iCount = ::FUN_00e049c0(*(volatile int*)&denominator, u);
                state1.flagh1 = ((void *)(reinterpret_cast<::FUN_00d86930_StandIn *>((nb))->FUN_00d86930()));
                state0.flagh2 = ((void *)(reinterpret_cast<::FUN_00d86930_StandIn *>((pItem))->FUN_00d86930()));
                int v = reinterpret_cast<::ClassMember_d869 *>((nb))->FUN_00d86980();
                state1.flagq = v / denominator;
                intptr_t cur = iSourceOffset;
                if (iCount <= 0) break;
                int remaining = iCount;
                do {
                    int r86 = ::ReadSignedValueBySize((const void *)(nb));
                    
                    work.values.data = 0; work.values.size = 0; work.values.capacity = 0x80000000;
                    work.acc = 0;
                    reinterpret_cast<::hkOwnerXdb76f0 *>((((HObj*)state1.flagh1)))->CollectMatchingEntries(r86, (*(::hkArrayXdb76f0<void *> *)(&work.values)), (unsigned int *)(void *)(&work.acc));
                    int iOrValue = 0;
                    int iValueIndex = 0;
                    while (iValueIndex < work.values.size) {
                        
                        int* __restrict outputValue = &state0.out40;
                        int iLookupResult = ((int)(reinterpret_cast<::FUN_00db75b0_class *>((((HObj*)state0.flagh2)))->FUN_00db75b0(work.values.data[iValueIndex], (unsigned int *)(outputValue))));
                        if (iLookupResult == 0) iOrValue |= *outputValue;
                        else work.acc |= *outputValue;
                        iValueIndex++;
                    }
                    if (work.acc != 0) {
                        int iAccumulated = 0;
                        reinterpret_cast<::hkOwnerXdb76f0 *>((((HObj*)state0.flagh2)))->CollectMatchingEntries(work.acc, (*(::hkArrayXdb76f0<void *> *)(&work.values)), (unsigned int *)(void *)(&iAccumulated));
                        iOrValue |= iAccumulated;
                    }
                    switch (state1.flagq) {
                    case 1: reinterpret_cast<::FUN_00d605b0_class *>((apOutputStream))->FUN_00d605b0(iOrValue); break;
                    case 2: ::FUN_00d60900((char *)(apOutputStream)); break;
                    case 4: reinterpret_cast<::hkOArchive_2 *>((apOutputStream))->WriteInt(iOrValue); break;
                    }
                    cur += state1.flagq;
                    {
                        HeapAlloc& heap = *reinterpret_cast<HeapAlloc*>(&(*static_cast<E04A00MemoryRouter*>(::FUN_00c85750())).heap());
                        work.values.size = 0;
                        if ((work.values.capacity & 0x80000000) == 0)
                            heap.ReleaseBlock(work.values.data, (work.values.capacity & 0x3fffffff) * 4);
                    }
                    work.values.data = 0;
                    work.values.capacity = 0x80000000;
                    remaining--;
                } while (remaining != 0);
                break;
            }
            case 22: default: {
                
                        new ((void *)&(scratch.bad)) ::FUN_00cb1600(storage, 0x200);
                reinterpret_cast<::SinkOwner *>(&(scratch.bad))->FUN_00cc01c0((const char*)&(*reinterpret_cast<int *>((void *)&::DAT_010ea448)));
                int iResult = (*reinterpret_cast<::AssertMgr * *>(&::DAT_01268360))->v3(3, 0x641e3e03, (char*)storage, (const char*)&(*reinterpret_cast<int *>((void *)&::str_010ea3c8)), 0x225);
                if (iResult) __debugbreak();
                reinterpret_cast<struct ::FUN_00cc00e0 *>(&(scratch.bad))->FUN_00cc00e0::~FUN_00cc00e0();
                break;
            }
            }
            } else {
                ::FUN_00e03240((::S_00e03240_Holder *)(apDescriptorList), (::S_00e03240_Node *)(pItem), state0.index, (intptr_t)state1.ebp);
            }
        }
    }
    {
        EbpObj* e2 = ((::fnv_00e036b0::EbpObj *)(reinterpret_cast<::FUN_00d60800_class *>((apOutputStream))->FUN_00d60800()));
        e2->v1c(reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((apDescriptorList))->FUN_00d470d0() + state0.base, 0);
    }
    return state0.base;
}
}

static int FUN_00e03100(Obj* apObj);
static void WriteUIntArray(const unsigned int* data, int count, Writer* pWriter, int elemSize);
static int AppendListEntry(Ctx* ctx, List* list, intptr_t a, intptr_t b);
static void __cdecl FUN_00e03360(Reader* obj, int n);
static void FUN_00e03170(unsigned int a, unsigned int b, unsigned int type, Target* obj, void* p);

extern "C" void _ReadWriteBarrier();
struct S00e03ea0_Schema;

struct S00e03ea0_Member {
    void* m_name;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_subType;
    unsigned short unk0e;
    unsigned short m_flags;
    unsigned short m_offset;

    int getOffset() const { return m_offset; }
};

struct S00e03ea0_Schema {
};

struct S00e03ea0_Writer {
};

struct S00e03ea0_Scr2 {
    int a;
    int b;
};

struct S00e03ea0_Scr4 {
    int a;
    int b;
    int c;
    int d;
};


struct S00e03ea0_Pair {
    void* m_object;
    void* m_class;
};

struct RootPair {
    int offset;
    const char* name;
    RootPair(intptr_t where, const char* what) : offset(where), name(what) {}
};
struct S00e03ea0_PairArray {
    RootPair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _pushBack(E04A00Allocator& alloc, const RootPair& e)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(RootPair));
        RootPair* slot = m_data + m_iElementCount;
        slot->offset = e.offset;
        slot->name = e.name;
        m_iElementCount++;
    }

    void AddBack(const RootPair& e) { _pushBack((*static_cast<E04A00MemoryRouter*>(::FUN_00c85750())).heap(), e); }
};

struct S00e03ea0_Out {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00e03ea0_PairArray m_pairs;

    void AppendPair(intptr_t at, intptr_t data);
};

struct S00e03ea0_Array {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct S00e03ea0_VArray {
    S00e03ea0_Schema* m_class;
    char* m_data;
    int m_iElementCount;
};

struct S00e03ea0_Ostream {
    int unk00;
    int unk04;
    int unk08;
};

struct S00e03ea0_Locals {
    S00e03ea0_Ostream osDefault;
    S00e03ea0_Ostream os13;
    S00e03ea0_Scr2 s21;
    S00e03ea0_Scr2 s14;
    S00e03ea0_Scr2 s1d;
    S00e03ea0_Scr4 s1c;
    char buf[512];
};
extern const char DAT_010ea4b0[];
struct S00e03ea0_Out;
struct S00e03ea0_Schema;
struct S00e03ea0_Writer;


struct S00e03ea0_Ser {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(S00e03ea0_Member* type, S00e03ea0_Member* member);
    int unk04;
    unsigned char m_srcPtrSize;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char m_dstPtrSize;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char m_flags;

    void FUN_00e03ea0(char* src, S00e03ea0_Schema* srcClass, S00e03ea0_Writer* writer,
                      S00e03ea0_Schema* dstClass, intptr_t dst, S00e03ea0_Out* out, int depth);
};

static __forceinline void fixedPointerLoop(S00e03ea0_Ser*& self, char* s, S00e03ea0_Member* member, S00e03ea0_Writer* writer, intptr_t dst, S00e03ea0_Out* out, int count, int stride, int& j) {
            for (; j < count; j++) {
                void* p = *(void**)s;
                if (p) {
                    int off = self->m_dstPtrSize * j + member->getOffset();
                    if (member->m_subType == 2)
                        AppendListEntry((Ctx*)writer, (List*)out, (intptr_t)p, (int)(dst + off));
                    else
                        reinterpret_cast<::E04A00Registry *>((out))->AddEntry((void *)(dst + off), p, ((::S00e03ea0_Schema *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920())), (void *)(0));
                }
                s += stride;
            }
}
// @fnv 0x00e03ea0
void S00e03ea0_Ser::FUN_00e03ea0(char* src, S00e03ea0_Schema* srcClass, S00e03ea0_Writer* writer,
                                 S00e03ea0_Schema* dstClass, intptr_t dst, S00e03ea0_Out* out, int depth)
{
    S00e03ea0_Ser* self = this;
    S00e03ea0_Locals sc;
    char* buf = sc.buf;

    if (depth == 0) {
        RootPair p(dst, reinterpret_cast<::FnvClassNameNode *>((dstClass))->FUN_00d46d40());
        out->m_pairs.AddBack(p);
    }
    depth++;

    for (int i = 0; i < ((int)(reinterpret_cast<::FUN_00d46f00_s *>((dstClass))->FUN_00d46f00())); i++) {
        S00e03ea0_Member* member = ((::S00e03ea0_Member *)(reinterpret_cast<::HkClassNode *>((dstClass))->FUN_00d46f20(i)));
        void* memberName = member->m_name;
        S00e03ea0_Member* type = ((::S00e03ea0_Member *)(reinterpret_cast<::FUN_00d46fe0_Class *>((srcClass))->FUN_00d46fe0((const int *)(memberName))));
        if (!type)
            continue;
        char* s = src + type->getOffset();
        if (!self->v10(type, member))
            continue;
        if ((self->m_flags & 2) && (member->m_flags & 0x400))
            continue;

        switch (member->m_type) {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        case 21: case 24: case 30: case 31: case 32:
            break;
        case 0x1d: {
            void* p = *(void**)s;
            if (p)
                AppendListEntry((Ctx*)writer, (List*)out, (intptr_t)p, (int)(dst + member->getOffset()));
            break;
        }
        case 0x21: {
            unsigned int p = *(unsigned int*)s;
            if (p & ~1u)
                AppendListEntry((Ctx*)writer, (List*)out, (int)(p & ~1u), (int)(dst + member->getOffset()));
            break;
        }
        case 0x14: {
            int count = FUN_00e049c0(FUN_00e03100((Obj*)type), FUN_00e03100((Obj*)member));
            int stride = reinterpret_cast<::ClassMember_d869 *>((type))->FUN_00d86980() / FUN_00e03100((Obj*)type);
            int j=0;
            fixedPointerLoop(self, s, member, writer, dst, out, count, stride, j);
            break;
        }
        case 0x16: case 0x17: case 0x1a: {
            S00e03ea0_Array* arr = (S00e03ea0_Array*)s;
            if (arr->m_iElementCount == 0)
                break;
            unsigned char sub = member->m_subType;
            if (sub == 0)
                break;
            if (sub == 0x14) {
                out->AppendPair(dst + member->getOffset(), (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20());
                S00e03ea0_Scr2& scratch = sc.s14;
                scratch.a = 0;
                scratch.b = 0;
                int stride = reinterpret_cast<::Owner *>((type))->GetTagValue();
                int j=0; if (j < arr->m_iElementCount) { int off=0; do {
                    void* condition = *(void**)((char*)arr->m_data + off);
                    void* volatile p = condition;
                    if (condition) {
                        VObj* r = ((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()));
                        reinterpret_cast<::E04A00Registry *>((out))->AddEntry((void *)((intptr_t)r->v20()), p, ((::S00e03ea0_Schema *)(reinterpret_cast<::Struct_d86920 *>((type))->FUN_00d86920())), (void *)(0));
                    }
                    reinterpret_cast<::FUN_00d607b0_class *>((writer))->FUN_00d607b0((intptr_t)(&scratch));
                    off += stride;
                } while (++j < arr->m_iElementCount); }
            } else if (sub == 0x1d) {
                out->AppendPair(dst + member->getOffset(), (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20());
                S00e03ea0_Scr2& scratch = sc.s1d;
                scratch.a = 0;
                scratch.b = 0;
                intptr_t d = (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20();
                if (arr->m_iElementCount > 0) {
                    S00e03ea0_Ser* loopSelf = self;
                    int j = 0; do { reinterpret_cast<::FUN_00d607b0_class *>((writer))->FUN_00d607b0((intptr_t)(&scratch)); } while (++j < arr->m_iElementCount);
                }
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    void** e = (void**)arr->m_data + j;
                    if (*e) { _ReadWriteBarrier(); AppendListEntry((Ctx*)writer, (List*)out, (intptr_t)*e, d + self->m_dstPtrSize * j); }
                }
            } else if (sub == 0x21) {
                out->AppendPair(dst + member->getOffset(), (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20());
                S00e03ea0_Scr2& scratch = sc.s21;
                scratch.a = 0;
                scratch.b = 0;
                intptr_t d = (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20();
                if (arr->m_iElementCount > 0) {
                    S00e03ea0_Ser* loopSelf = self;
                    int j = 0; do { reinterpret_cast<::FUN_00d607b0_class *>((writer))->FUN_00d607b0((intptr_t)(&scratch)); } while (++j < arr->m_iElementCount);
                }
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    unsigned int e = ((unsigned int*)arr->m_data)[j];
                    if (e & ~1u)
                        AppendListEntry((Ctx*)writer, (List*)out, (int)(e & ~1u), (int)(d + self->m_dstPtrSize * j));
                }
            } else if (sub == 0x19) {
                intptr_t d = (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20();
                out->AppendPair(dst + member->getOffset(), d);
                S00e03ea0_Schema* sc = ((::S00e03ea0_Schema *)(reinterpret_cast<::Struct_d86920 *>((type))->FUN_00d86920()));
                S00e03ea0_Schema* dc = ((::S00e03ea0_Schema *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()));
                if (sc && dc) {
                    char* data = (char*)arr->m_data;
                    for (int j = 0; j < arr->m_iElementCount; j++)
                        reinterpret_cast<::fnv_00e036b0::Host *>((self))->FUN_00e036b0((::fnv_00e036b0::StreamObj *)(char *)(data + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((sc))->FUN_00d470d0() * j), (::fnv_00e036b0::StreamObj *)(sc), (::fnv_00e036b0::StreamObj *)(writer), (::fnv_00e036b0::DescriptorList *)(dc));
                    for (int j = 0; j < arr->m_iElementCount; j++)
                        self->FUN_00e03ea0(data + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((sc))->FUN_00d470d0() * j, sc, writer, dc,
                                     d + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((dc))->FUN_00d470d0() * j, out, depth);
                }
            } else if (sub == 0x1c) {
                intptr_t d = (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20();
                out->AppendPair(dst + member->getOffset(), d);
                S00e03ea0_Scr4& scratch = sc.s1c;
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    scratch.a = 0;
                    scratch.b = 0;
                    scratch.c = 0;
                    scratch.d = 0;
                    reinterpret_cast<::Archive *>((writer))->WriteSwapped(&scratch, self->m_dstPtrSize, 2);
                }
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    int off = self->m_dstPtrSize * j * 2;
                    if (((S00e03ea0_Pair*)arr->m_data)[j].m_object)
                        reinterpret_cast<::E04A00Registry *>((out))->AddEntry((void *)(d + off), ((S00e03ea0_Pair*)arr->m_data)[j].m_object, ((S00e03ea0_Pair*)arr->m_data)[j].m_class, (void *)(0));
                    void* c = ((S00e03ea0_Pair*)arr->m_data)[j].m_class;
                    if (c)
                        reinterpret_cast<::E04A00Registry *>((out))->AddEntry((void *)(d + off + self->m_dstPtrSize), c, &(*reinterpret_cast<int *>(&::g_0126cae8)), (void *)(0));
                }
            } else {
                VObj* stream = ((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()));
                int off = member->getOffset();
                out->AppendPair(dst + off, (intptr_t)stream->v20());
                if (member->m_subType == 0x1e) {
                    const unsigned int* rawData = (const unsigned int*)arr->m_data;
                    int rawCount = arr->m_iElementCount;
                    
                    
                    WriteUIntArray(rawData, rawCount, (Writer*)*(S00e03ea0_Writer* volatile const*)&writer, self->m_dstPtrSize);
                }
                else {
                    FUN_00e03170((Target*)writer, arr->m_iElementCount, reinterpret_cast<::Owner *>((member))->GetTagValue(), member->m_subType, arr->m_data);
                }
            }
            break;
        }
        case 0x1b: {
            S00e03ea0_VArray* arr = (S00e03ea0_VArray*)s;
            S00e03ea0_Schema* c = arr->m_class;
            if (!c)
                break;
            reinterpret_cast<::E04A00Registry *>((out))->AddEntry((void *)(dst + member->getOffset()), c, &(*reinterpret_cast<int *>(&::g_0126cae8)), (void *)(1));
            intptr_t d = (intptr_t)((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800()))->v20();
            out->AppendPair(dst + self->m_dstPtrSize + member->getOffset(), d);
            char* data = arr->m_data;
            for (int j = 0; j < arr->m_iElementCount; j++)
                reinterpret_cast<::fnv_00e036b0::Host *>((self))->FUN_00e036b0((::fnv_00e036b0::StreamObj *)(char *)(data + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((c))->FUN_00d470d0() * j), (::fnv_00e036b0::StreamObj *)(c), (::fnv_00e036b0::StreamObj *)(writer), (::fnv_00e036b0::DescriptorList *)(c));
            for (int j = 0; j < arr->m_iElementCount; j++)
                self->FUN_00e03ea0(data + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((c))->FUN_00d470d0() * j, c, writer, c,
                             d + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((c))->FUN_00d470d0() * j, out, depth);
            break;
        }
        case 0x19: {
            S00e03ea0_Schema* sc = ((::S00e03ea0_Schema *)(reinterpret_cast<::Struct_d86920 *>((type))->FUN_00d86920()));
            S00e03ea0_Schema* dc = ((::S00e03ea0_Schema *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()));
            if (!sc || !dc)
                break;
            intptr_t d = dst + member->getOffset();
            int n = FUN_00e03100((Obj*)type);
            int count = FUN_00e049c0(n, FUN_00e03100((Obj*)member));
            for (int j = 0; j < count; j++) {
                char* ss = s + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((sc))->FUN_00d470d0() * j;
                self->FUN_00e03ea0(ss, sc, writer, dc, d + reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((dc))->FUN_00d470d0() * j, out, depth);
            }
            break;
        }
        case 0x1c: {
            int n = FUN_00e03100((Obj*)type);
            int count = FUN_00e049c0(n, FUN_00e03100((Obj*)member));
            for (int j = 0; j < count; j++) {
                unsigned char ptrSize = self->m_srcPtrSize;
                void* o = *(void**)(s + j * ptrSize * 2);
                void* c = *(void**)(s + (j * 2 + 1) * ptrSize);
                if (o)
                    reinterpret_cast<::E04A00Registry *>((out))->AddEntry((void *)(dst + member->getOffset() + self->m_dstPtrSize * j * 2), o, c, (void *)(0));
                if (c)
                    reinterpret_cast<::E04A00Registry *>((out))->AddEntry((void *)(dst + member->getOffset() + self->m_dstPtrSize * (j * 2 + 1)), c, &(*reinterpret_cast<int *>(&::g_0126cae8)), (void *)(0));
            }
            break;
        }
        case 0x13: {
            S00e03ea0_Ostream& os = sc.os13;
            new ((void *)&(os)) ::FUN_00cb1600(buf, 0x200);
            reinterpret_cast<::SinkOwner *>(&(os))->FUN_00cc01c0(DAT_010ea4b0);
            if ((*reinterpret_cast<::AssertMgr * *>(&::DAT_01268360))->v3(3, 0x641e3e05, buf, ::str_010ea3c8, 0x39e))
                __debugbreak();
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(os))->FUN_00cc00e0::~FUN_00cc00e0();
            break;
        }
        default: {
            S00e03ea0_Ostream& os = sc.osDefault;
            new ((void *)&(os)) ::FUN_00cb1600(buf, 0x200);
            reinterpret_cast<::SinkOwner *>(&(os))->FUN_00cc01c0(DAT_010ea448);
            if ((*reinterpret_cast<::AssertMgr * *>(&::DAT_01268360))->v3(3, 0x641e3e05, buf, ::str_010ea3c8, 0x3a3))
                __debugbreak();
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(os))->FUN_00cc00e0::~FUN_00cc00e0();
            break;
        }
        }
        FUN_00e03360(((::VObj *)(reinterpret_cast<::FUN_00d60800_class *>((writer))->FUN_00d60800())), 0x10);
    }
}

struct ZeroClass {
};
struct ZeroMember {
    const char* m_name;
    ZeroClass* m_class;
    void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    void* m_pCustomAttributes;
    int type() const { return m_type; }
};
struct ZeroArchive {
};
static __declspec(noinline) int FUN_00e03100(Obj* p);
extern const char str_010ea424[];
struct ZeroArchive;
struct ZeroMember;

struct ZeroCopier {
    void* m_ppVirtualMethodTable;
    short m_usAllocationSize;
    short m_iObjectReferenceCount;
    unsigned char m_inputPointerSize;
    unsigned char m_inputLittleEndian;
    unsigned char m_inputTailPadding;
    unsigned char m_inputEmptyBase;
    unsigned char m_outputPointerSize;
    unsigned char m_outputLittleEndian;
    unsigned char m_outputTailPadding;
    unsigned char m_outputEmptyBase;
    unsigned int m_flags;
    unsigned char m_bStreamResult;
    void FUN_00e03460(ZeroArchive& archive, const ZeroMember& member);
};
// @fnv 0x00e03460
void ZeroCopier::FUN_00e03460(ZeroArchive& archive, const ZeroMember& member)
{
    int bytes = 0;
    switch (member.type()) {
    case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17: case 18:
    case 24: case 31: case 32:
        bytes = reinterpret_cast<::ClassMember_d869 *>((void *)&(member))->FUN_00d86980();
        break;
    case 20: case 21: case 30:
        bytes = m_outputPointerSize * FUN_00e03100((Obj*)&member);
        break;
    case 22: case 23: case 26: case 27:
        if (member.type() == 27)
            bytes += m_outputPointerSize;
        bytes += m_outputPointerSize;
        bytes += 4;
        if (member.type() == 22) {
            char header[12] = {0};
            reinterpret_cast<::FUN_00d607b0_class *>(&(archive))->FUN_00d607b0((intptr_t)(header));
            ::FUN_00d60960((const float *)&(archive));
            return;
        }
        break;
    case 25: {
        const ZeroClass& pClassInfo = (*(const ::ZeroClass *)(reinterpret_cast<::TestClass *>((void *)&(member))->FUN_00d86910()));
        bytes = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((void *)&(pClassInfo))->FUN_00d470d0() * FUN_00e03100((Obj*)&member);
        break;
    }
    case 28:
        bytes = 2 * m_outputPointerSize * FUN_00e03100((Obj*)&member);
        break;
    default: {
        unsigned int report[128];
        DiagnosticWriter stream;
        new ((void *)&(stream)) ::FUN_00cb1600(report, sizeof(report));
        reinterpret_cast<::SinkOwner *>(&(stream))->FUN_00cc01c0(str_010ea424);
        if ((*reinterpret_cast<::AssertMgr * *>(&::DAT_01268360))->v3(3, 0x5ef4e5a4u, (char*)report, str_010ea3c8, 168))
            __debugbreak();
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(stream))->FUN_00cc00e0::~FUN_00cc00e0();
        break;
    }
    }
    LocalCharArray zero(bytes);
    zero.SetSizeAndGrow(bytes);
    reinterpret_cast<::FUN_00d607b0_class *>(&(archive))->FUN_00d607b0((intptr_t)(zero.m_data));
    zero.destroyLocal();
}



// Calls FUN_00e036b0 and FUN_00e03ea0 with a scratch object, then returns whether the byte from ForwardValueToObject is zero.
// @fnv 0x00e04920
int FUN_00e04920_cls::FUN_00e04920(uintptr_t a1, uintptr_t a2,
                                   uintptr_t a3, uintptr_t a4, uintptr_t a5)
{
    Scratch16 scratch;
    VObj* original = reinterpret_cast<VObj*>(a3);
    new ((void *)&(scratch)) ::FUN_00d60830((::hkReferencedObject *)(a3), static_cast<unsigned int>(m_flag14));
    unsigned int uiIntermediate = FUN_00e036b0(a1, a2, &scratch, a4);
    FUN_00e03360(original, 16);
    reinterpret_cast<::S00e03ea0_Ser *>(this)->FUN_00e03ea0((char *)(a1), (::S00e03ea0_Schema *)(a2), (::S00e03ea0_Writer *)(::Scratch16 *)(&scratch), (::S00e03ea0_Schema *)(a4), uiIntermediate, (::S00e03ea0_Out *)(a5), 0);
    FUN_00e03360(original, 16);
    unsigned char* status = ((unsigned char *)(reinterpret_cast<::FUN_00d607e0_class *>(&(scratch))->ForwardValueToObject((intptr_t)(&a1))));
    unsigned int success = (*status == 0);
    reinterpret_cast<::D60590Object *>(&(scratch))->FUN_00d60590();
    return success;
}

#include "generated/data/havok/common/serialize/copier/hkobjectcopier.inc"
