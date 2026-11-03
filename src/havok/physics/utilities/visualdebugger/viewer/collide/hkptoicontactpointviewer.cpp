
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicontactpointviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkptoicontactpointviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00d68260
#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include <intrin.h>
#include <windows.h>
#include <new>
#include "fnv/decl/FUN_00ddcc60.h"
#include "fnv/decl/FUN_00ddccb0_cls.h"
#include "fnv/decl/S_00dd9380.h"
#include "fnv/decl/fnv_00c93a20__hkpWorldXc93a20.h"
#include "fnv/decl/hkWorldXc91a20.h"
#include "fnv/decl/hkpPositionTrackerCBB1.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
int __cdecl FUN_00d68260() {
    return ::DAT_01269004;
}

struct Built { int field00; short field04; int field08; int FUN_00d682d0(int); };
// Allocates a 0x2c-byte Built via the global allocator, sets its field04 to 0x2c, calls FUN_00d682d0(arg), and returns result+8 or 0.
// @fnv 0x00d686b0
int __cdecl FUN_00d686b0(int arg)
{
    hkMemoryRouter* global = &hkMemoryRouter::getInstance();
    Built* pBuilt = (Built*)global->m_heap->blockAlloc(0x2c);
    pBuilt->field04 = 0x2c;
    int result = pBuilt->FUN_00d682d0(arg);
    if (result) return result + 8;
    return 0;
}

struct SpawnedChild {
    int unk00;
    int unk04;
    int m_i08;
};

struct FUN_00d66bf0_cls {
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
    SpawnedChild* m_pChildObject;

    void DispatchToChild(const void* arg);
};

// @fnv 0x00d66bf0
void FUN_00d66bf0_cls::DispatchToChild(const void* arg)
{
    SpawnedChild* child = m_pChildObject;
    if (child != 0 && child->m_i08 != 0) {
        reinterpret_cast<::hkpPositionTrackerCBB1 *>((child))->FUN_00cbb150((*(const ::hkVector4CBB1 *)(arg)));
    }
}

struct Target {
};

// The TOI contact point viewer: hkReferencedObject, hkProcess at +0x08, its world listener part
// (FUN_00d682a0_cls) at +0x20 and its contact listener part at +0x28.
struct ToiViewerRefObject {
    void* volatile m_vtbl;
    int m_memSizeAndRefCount;
};
struct ToiViewerProcess {
    void* volatile m_processVtbl;
    int unk04[5];
};
struct FUN_00d682a0_cls {
    void* volatile m_worldListenerVtbl;
    void* m_context;

    void InvokeTargetWithSelfOffset(Target* apTarget);
};
struct ToiViewerContactListener {
    void* m_vtbl28;
};

extern char DAT_010d1f0c[];
extern char DAT_010d1eec[];
extern char DAT_010d1edc[];
extern char DAT_010d1ebc[];

struct FUN_00d682d0_cls : ToiViewerRefObject, ToiViewerProcess, FUN_00d682a0_cls, ToiViewerContactListener {
    void* FUN_00d682d0(void* a1);
};

// Calls apTarget->FUN_00c91a20 with the viewer's contact listener part.
// @fnv 0x00d682a0
void FUN_00d682a0_cls::InvokeTargetWithSelfOffset(Target* apTarget)
{
    ToiViewerContactListener* listener = static_cast<FUN_00d682d0_cls*>(this);
    reinterpret_cast<::hkWorldXc91a20 *>((apTarget))->FUN_00c91a20(listener);
}

// Calls FUN_00ddccb0 with a1, then stores the vtables of the contact listener part, the object, the process part,
// the world listener part and the contact listener part again, and returns this.
// @fnv 0x00d682d0
void* FUN_00d682d0_cls::FUN_00d682d0(void* aiArg)
{
    new ((void *)this) ::FUN_00ddccb0_cls(*static_cast<const ::BDDCCB0Array< ::BDDCCB0ProcessContext *> *>(aiArg));
    this->m_vtbl28 = (void*)&DAT_0104dd7c;
    this->m_vtbl = (void*)&DAT_010d1f0c;
    this->m_processVtbl = (void*)&DAT_010d1eec;
    this->m_worldListenerVtbl = (void*)&DAT_010d1edc;
    this->m_vtbl28 = (void*)&DAT_010d1ebc;
    return this;
}

struct ItemList {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68;
    void** items;   // +0x6c
    int count;      // +0x70
};

struct Sub {
    virtual void v0();
    virtual void v1(void* item);
};

class FUN_00d68310_cls {
public:
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14;
    Sub m_sub;          // +0x18
    ItemList* m_kNode;   // +0x1c
    void FUN_00d68310();
};

// Iterates the item list and calls m_sub.v1 on each item until the list ends or the count is reached.
// @fnv 0x00d68310
void FUN_00d68310_cls::FUN_00d68310() {
    int i = 0;
    while (m_kNode != 0) {
        if (i >= m_kNode->count) break;
        m_sub.v1(m_kNode->items[i]);
        i++;
    }
}

struct Part0_t
{
    virtual ~Part0_t() {}
    int m_i04;
};

struct Part1_t
{
    virtual ~Part1_t() {}
};

struct Part2_t
{
    virtual ~Part2_t() {}
};

struct Part3_t
{
    virtual ~Part3_t() {}
};

struct SubObj_t
{
    virtual ~SubObj_t() {}
};

struct ListBlob_t
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
    void** m_items;
    int m_uiItemCount;
};

struct ParentBase_t
{
};

class FUN_00d68350_cls : public Part0_t, public Part1_t
{
public:
    int m_u0c;
    int m_u10;
    int m_u14;
    int m_u18;
    int m_u1c;
    SubObj_t m_sub;
    ListBlob_t* m_pEntries;
    Part2_t m_pTail;

    void FUN_00d68350();
};

// @fnv 0x00d68350
void FUN_00d68350_cls::FUN_00d68350()
{
    int i = 0;
    this->Part0_t::~Part0_t();
    this->Part1_t::~Part1_t();
    m_sub.SubObj_t::~SubObj_t();
    m_pTail.Part2_t::~Part2_t();
    while (m_pEntries != 0)
    {
        ListBlob_t* p = m_pEntries;
        if (i >= p->m_uiItemCount)
        {
            break;
        }
        reinterpret_cast<::FUN_00d682a0_cls *>(&(m_sub))->InvokeTargetWithSelfOffset((::Target *)(p->m_items[i]));
        i++;
    }
    ((Part3_t*)&m_pTail)->Part3_t::~Part3_t();
    reinterpret_cast<struct ::FUN_00ddcc60 *>((((ParentBase_t*)this)))->FUN_00ddcc60::~FUN_00ddcc60();
}

struct StateTarget {
};

extern const char str_010d1ea0[];

// @fnv 0x00d686f0
void DispatchStateHandler()
{
    ::DAT_01269004 = reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::StateTarget * *>(&::DAT_01269cd0))))->FUN_00dd9380(str_010d1ea0, reinterpret_cast<intptr_t>(FUN_00d686b0));
}

struct FUN_00d68270_Base0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FUN_00d68270_Base1 {
    int unk00;
    int unk04;
    void FUN_00d68270(struct FUN_00d68270_Arg* arg);
};
struct FUN_00d68270_Base2 {
    int unk00;
};
struct FUN_00d68270_Derived : public FUN_00d68270_Base0, public FUN_00d68270_Base1, public FUN_00d68270_Base2 {
};
struct FUN_00d68270_Arg {
};
// Calls arg->FUN_00c93a20 with the Base2 part of the enclosing Derived object.
// @fnv 0x00d68270
void FUN_00d68270_Base1::FUN_00d68270(FUN_00d68270_Arg* arg)
{
    reinterpret_cast<::fnv_00c93a20::hkpWorldXc93a20 *>((arg))->FUN_00c93a20((::fnv_00c93a20::hkpEntityListenerXc93a20 *)(static_cast<FUN_00d68270_Base2*>(static_cast<FUN_00d68270_Derived*>(this))));
}

// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x20).
struct PrimaryBase
{
    virtual void FUN_00d68710();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SecondaryBase
{
    virtual void FUN_00d68710();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68710
    virtual void FUN_00d68710();
};

Derived::Derived()
{
}

// FUN_00d68720 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00d68720 {
    A1_00d68720();
    virtual void FUN_00d68720();
    char pad[0x04];
};
struct A2_00d68720 {
    A2_00d68720();
    virtual void FUN_00d68720();
};
struct Own_00d68720 : A1_00d68720, A2_00d68720 {
    Own_00d68720();
    virtual void key_fn();
// @fnv 0x00d68720
    void FUN_00d68720();
};
Own_00d68720::Own_00d68720() { }
void Own_00d68720::key_fn() { }
Own_00d68720* make_00d68720() { static Own_00d68720 o; return &o; }

namespace fnv_00d68730 {
// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void FUN_00d68730();
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

struct SecondaryBase
{
    virtual void FUN_00d68730();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68730
    virtual void FUN_00d68730();
};

Derived::Derived()
{
}
}  // namespace fnv_00d68730

namespace fnv_00d68740 {



struct FUN_00d68740 {
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00d68740();
    virtual ~FUN_00d68740();
    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = &hkMemoryRouter::getInstance();
        unsigned int uiSize = ((FUN_00d68740*)apMemory)->m_u04;
        hkMemoryAllocator* pAllocator = pHolder->m_heap;
        pAllocator->blockFree(apMemory, uiSize);
    }
};

// Constructor that zero-initializes m_u04 and m_u06.
// @fnv 0x00d68740
FUN_00d68740::FUN_00d68740()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00d68740

#include <math.h>

#include "fnv/symbols_simd.h"




extern const float DAT_010c69c0=(0.85f-1.0f);

struct Vec {
    union {
        __m128 m;
        struct { float x, y, z, w; };
    };
};

struct Handler {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void DisplayLine(const Vec& a, const Vec& b, int color, uintptr_t id, int tag);
};

struct TimerCmd {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonStream {
    int unk00;
    TimerCmd* m_kRayEnd;
    int unk08;
    TimerCmd* m_cap;
};

__forceinline __m128 lengthSquared3(__m128 v) {
    __m128 sq = _mm_mul_ps(v, v);
    __m128 y = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 xy = _mm_add_ss(y, sq);
    __m128 z = _mm_shuffle_ps(sq, sq, 0xAA);
    return _mm_add_ss(z, xy);
}

__forceinline __m128 sqrtInverse(__m128 len2) {
    __m128 y0 = _mm_rsqrt_ss(len2);
    __m128 zero = _mm_set_ss(::DAT_01011d78);
    __m128 three = _mm_set_ss(::DAT_01017718);
    __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
    __m128 r2 = _mm_mul_ss(_mm_mul_ss(len2, y0), y0);
    __m128 eq = _mm_cmpeq_ss(len2, zero);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(half, y0), _mm_sub_ss(three, r2));
    return _mm_andnot_ps(eq, inv);
}

__forceinline __m128 splat(float s) {
    __m128 a = _mm_load_ss(&s);
    return _mm_shuffle_ps(a, a, 0);
}

// @fnv 0x00d683b0
static __declspec(noinline) void FUN_00d683b0(Handler* self, Vec* from, Vec* dir, int color, uintptr_t id, int tag) {
    float lenSq;

    _mm_store_ss(&lenSq, lengthSquared3(dir->m));
    if (lenSq > 1.1920928955078125e-07f) {
        { MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
        if (s->m_kRayEnd < s->m_cap) {
            TimerCmd* h = s->m_kRayEnd;
            h->m_pCommandName = "TtToiDisplayArrow";
            unsigned t1;
            t1 = static_cast<unsigned int>(__rdtsc());
            h->m_uiStartTicks = t1;
            s->m_kRayEnd = h + 1;
        } }
        struct Endpoints { Vec head1; Vec perp; };
        Endpoints endpoints;
        Vec to;
        Vec head2;
        to.m = _mm_add_ps(from->m, dir->m);
        int iAlt = 0;
        float cur = fabsf(dir->x);
        int i0 = 1;
        float ay = fabsf(dir->y);
        int i2 = i0 + 1;
        float az = fabsf(dir->z);
        if (ay < cur) {
            cur = ay;
            i0 = 0;
            iAlt = 1;
        }
        if (az < cur) i2 = iAlt;
        endpoints.perp.m = _mm_setzero_ps();
        (&endpoints.perp.x)[i0] = (&dir->x)[i2];
        (&endpoints.perp.x)[i2] = -(&dir->x)[i0];
        __m128 inv = sqrtInverse(lengthSquared3(endpoints.perp.m));
        __m128 len = _mm_sqrt_ss(lengthSquared3(dir->m));
        __m128 perpS = _mm_mul_ps(_mm_mul_ps(endpoints.perp.m, _mm_shuffle_ps(inv, inv, 0)), _mm_shuffle_ps(len, len, 0));
        float coeff = DAT_01019de0;
        __m128 cb = splat(coeff);
        __m128 one = _mm_load_ps(&(*reinterpret_cast<float *>((void *)&::DAT_010ec7f0)));
        __m128 base = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(one, cb), from->m), _mm_mul_ps(cb, to.m));
        float scalePos = ::ArrowHeadRatios::DAT_010c69c4;
        endpoints.head1.m = _mm_add_ps(base, _mm_mul_ps(splat(scalePos), perpS));
        float scaleNeg = DAT_010c69c0;
        head2.m = _mm_add_ps(base, _mm_mul_ps(splat(scaleNeg), perpS));
        self->DisplayLine(*from, to, color, id, tag);
        self->DisplayLine(to, endpoints.head1, color, id, tag);
        self->DisplayLine(to, head2, color, id, tag);
        { MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
        if (s->m_kRayEnd < s->m_cap) {
            TimerCmd* h = s->m_kRayEnd;
            h->m_pCommandName = "Et";
            unsigned t2;
            t2 = static_cast<unsigned int>(__rdtsc());
            h->m_uiStartTicks = t2;
            s->m_kRayEnd = h + 1;
        } }
    }
}

void RenderLine(Handler* handler, Vec* direction, Vec* origin, int color, uintptr_t id, int tag) {
    FUN_00d683b0(handler, origin, direction, color, id, tag);
}


class S00d68670_hkBool {
public:
    S00d68670_hkBool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};

struct S00d68670_ContactPoint {
    Vec m_vContactPosition;
    Vec m_vSeparatingNormal;
    const Vec& getPosition() { return m_vContactPosition; }
    const Vec& getNormal() const { return m_vSeparatingNormal; }
};

struct S00d68670_Collidable {
    int unk00;
};

struct S00d68670_Entity {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d68670_Collidable m_kCollidable;
    const S00d68670_Collidable* getCollidable() const { return &m_kCollidable; }
};

struct S00d68670_ContactPointEvent {
    void* m_pObservedSource;
    S00d68670_Entity* m_apEntities[2];
    void* m_pContactManager;
    int m_type;
    S00d68670_ContactPoint* m_vContactPoint;
    S00d68670_hkBool isToi() const { return m_type <= 0; }
};

struct S00d68670_WorldViewerBase {
    virtual void v00();
    int unk04;
    int unk08;
    Handler* m_pDisplayHandler;
    int unk10;
    int unk14;
    int unk18;
};

struct S00d68670_ContactListener {
    virtual void FUN_00d68670(const S00d68670_ContactPointEvent& event);
};

struct S00d68670_ToiContactPointViewer : S00d68670_WorldViewerBase, S00d68670_ContactListener {
    virtual void FUN_00d68670(const S00d68670_ContactPointEvent& event);
};

// @fnv 0x00d68670
void S00d68670_ToiContactPointViewer::FUN_00d68670(const S00d68670_ContactPointEvent& event)
{
    if (event.isToi())
    {
        const S00d68670_Collidable* collidable = event.m_apEntities[0]->getCollidable();
        FUN_00d683b0(m_pDisplayHandler, (Vec*)&event.m_vContactPoint->getPosition(), (Vec*)&event.m_vContactPoint->getNormal(), 0xffff0000, reinterpret_cast<uintptr_t>(collidable), DAT_01269004);
    }
}

#include "generated/data/havok/physics/utilities/visualdebugger/viewer/collide/hkptoicontactpointviewer.inc"
