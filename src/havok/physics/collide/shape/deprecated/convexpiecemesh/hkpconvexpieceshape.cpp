// havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp: AdjDerived (12 functions)

#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_01268000.h"
#include "fnv_asm_helpers.h"
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010ece2c;
extern int DAT_010ece08;

struct FUN_00e607c0
{
    void* m_p00;            // +0x00
    short m_s04;            // +0x04
    short m_s06;            // +0x06
    int   m_i08;            // +0x08
    int   m_i0C;            // +0x0c
    float m_f10;            // +0x10
    void* volatile m_p14;   // +0x14

    FUN_00e607c0(float arg);
};

// Initializes the object's fields from a float argument and assigns fixed globals to its pointers.
// @fnv 0x00e607c0
FUN_00e607c0::FUN_00e607c0(float afValue)
{
    m_f10 = afValue;
    m_s06 = 1;
    m_i08 = 0;
    m_i0C = 0x14;
    m_p14 = &DAT_010c6fb0;
    m_p00 = &DAT_010ece2c;
    m_p14 = &DAT_010ece08;
}

struct FUN_00e60680_class {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int capacity;
    int GetNextIndex(int index);
};
// @fnv 0x00e60680
int FUN_00e60680_class::GetNextIndex(int index) {
    int next = index + 1;
    if (next < capacity) return next;
    return -1;
}

struct InnerDispatch {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void run(int,int);
};
struct Dispatch { int x0,x4,x8,xc; InnerDispatch inner; };
struct FUN_00e60690_owner { int unk00; int unk04; int unk08; Dispatch* unk0c; int* unk10; void DispatchToInner(int index,int value); };
// Calls run on the inner dispatcher with the value from unk10 at index and the given value.
// @fnv 0x00e60690
void FUN_00e60690_owner::DispatchToInner(int index,int value) { unk0c->inner.run(unk10[index],value); }


struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00e60c30_cls {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    void* volatile m_p14;

    FUN_00e60c30_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Sets the vtable and a global pointer, then, if acFlags has bit 0 set, frees this object through the allocator obtained from FUN_00c85750.
// @fnv 0x00e60c30
FUN_00e60c30_cls* FUN_00e60c30_cls::Destroy(unsigned char acFlags)
{
    m_p14 = (void*)&DAT_010c6fb0;
    m_vptr = (int)&(*reinterpret_cast<int *>(&::DAT_0102e388));
    if (acFlags & 1) {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}

// @fnv 0x00e60670
int FUN_00e60670()
{
    return 0;
}

#include <xmmintrin.h>
struct FUN_00e606c0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    __m128* m_pSrc;

    void Copy(__m128* apDst);
};

// @fnv 0x00e606c0
void FUN_00e606c0_cls::Copy(__m128* apDst)
{
    *apDst = *m_pSrc;
}

struct E606E0Vector4 {
    __m128 m_vComponents;

    void operator=(const E606E0Vector4& v) { m_vComponents = v.m_vComponents; }
};

struct E606E0Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
    int unk14;
    E606E0Vector4* m_kVertices;
    int m_iStridedVertexCount;

    E606E0Vector4* CopyVerticesWithRadius(E606E0Vector4* vertices) const;
};

// @fnv 0x00e606e0
E606E0Vector4* E606E0Shape::CopyVerticesWithRadius(E606E0Vector4* apDestVertices) const
{
    E606E0Vector4* pDest = apDestVertices;
    for (int i = 0; i < m_iStridedVertexCount; i++) {
        *pDest = m_kVertices[i];
        pDest->m_vComponents[3] = m_fSphereRadius;
        pDest++;
    }
    return apDestVertices;
}

struct __declspec(align(16)) Vec4 {
    __m128 v;
};

struct Mat {
    Vec4 rows[8];
};

struct __declspec(align(16)) Scratch {
    float data[128];
};

struct Sub {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual Mat* GetMat(void* apKey, Scratch* apScratch);
};

struct Holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Sub sub10;
};

struct FUN_00e60730_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Holder* m_p20;
    void** m_p24;
    void FUN_00e60730(const unsigned short* apIndices, int aiCount, Vec4* apOut);
};

// @fnv 0x00e60730
void FUN_00e60730_cls::FUN_00e60730(const unsigned short* apIndices, int aiCount, Vec4* apOut)
{
    Scratch scratch;
    for (int i = aiCount - 1; i >= 0; i--) {
        int iIndex = *apIndices;
        Mat* pMatrix = m_p20->sub10.GetMat(m_p24[iIndex / 3], &scratch);
        apIndices++;
        apOut->v = pMatrix->rows[iIndex % 3 + 2].v;
        *((unsigned int*)apOut + 3) = iIndex | 0x3f000000;
        apOut++;
    }
}

struct Transform_e608 {
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;
};

inline __m128 TransformedPos_e608(const Transform_e608& a, const __m128& b)
{
    const __m128 xb = _mm_shuffle_ps(b, b, 0x00);
    const __m128 yb = _mm_shuffle_ps(b, b, 0x55);
    const __m128 zb = _mm_shuffle_ps(b, b, 0xaa);
    __m128 t0 = _mm_mul_ps(xb, a.m_kColumn0);
    __m128 t1 = _mm_mul_ps(yb, a.m_kColumn1);
    __m128 t2 = _mm_mul_ps(zb, a.m_kColumn2);
    return _mm_add_ps(_mm_add_ps(t0, t1), _mm_add_ps(t2, a.m_vTranslation));
}

struct Aabb_e608 {
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

class Shape_e608 {
public:
    int unk00, unk04, unk08, unk0c;
    float m_fSphereRadius;
    int unk14;
    __m128* m_kVertices;
    int m_iStridedVertexCount;

    void FUN_00e60800(const Transform_e608& kLocalToWorld, float fTolerance, Aabb_e608& kOut) const;
};

// Computes the world-space AABB of the shape's vertices via kLocalToWorld, then expands it by m_fSphereRadius plus fTolerance into kOut.
// @fnv 0x00e60800
void Shape_e608::FUN_00e60800(const Transform_e608& kLocalToWorld, float fTolerance, Aabb_e608& kOut) const
{
    kOut.m_kMinimumCorner = _mm_set1_ps(3.40282e+38f);
    kOut.m_kMaximumCorner = _mm_set1_ps(-3.40282e+38f);
    for (int i = 0; i < m_iStridedVertexCount; i++) {
        __m128 world = TransformedPos_e608(kLocalToWorld, m_kVertices[i]);
        kOut.m_kMinimumCorner = _mm_min_ps(kOut.m_kMinimumCorner, world);
        kOut.m_kMaximumCorner = _mm_max_ps(kOut.m_kMaximumCorner, world);
    }
    float fRadius = m_fSphereRadius + fTolerance;
    __m128 r = _mm_load1_ps(&fRadius);
    kOut.m_kMinimumCorner = _mm_sub_ps(kOut.m_kMinimumCorner, r);
    kOut.m_kMaximumCorner = _mm_add_ps(kOut.m_kMaximumCorner, r);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>

struct S_00e609c0_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00e609c0_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00e609c0_Timer(const char* name, int& t) {
    S_00e609c0_MonitorStream* s = (S_00e609c0_MonitorStream*)TlsGetValue(::DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        S_00e609c0_TimerCommand* h = (S_00e609c0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00e609c0_Bool {
    char m_cBooleanValue;
    S_00e609c0_Bool() {}
    S_00e609c0_Bool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

struct __declspec(align(16)) S_00e609c0_ShapeBuffer {
    unsigned int m_data[128];
};

struct S_00e609c0_RayInput;

struct S_00e609c0_RayOutput {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    void changeLevel(int delta) { m_uiShapeKeyIndex += delta; }
    void setKey(unsigned int key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};

struct S_00e609c0_Shape {
    virtual ~S_00e609c0_Shape();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual S_00e609c0_Bool RayCast(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const;
    int unk04_;
    int unk08_;
    int unk0C_;
};

struct S_00e609c0_ShapeContainer {
    virtual ~S_00e609c0_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00e609c0_Shape* GetShapeForKey(unsigned int key, S_00e609c0_ShapeBuffer& buffer) const;
};

struct S_00e609c0_ShapeCollection : S_00e609c0_Shape, S_00e609c0_ShapeContainer {
};

struct S_00e609c0_RayShapeCollectionFilter {
    virtual S_00e609c0_Bool IsCollisionEnabled(const S_00e609c0_RayInput& input, const S_00e609c0_Shape& shape,
        const S_00e609c0_ShapeContainer& container, unsigned int key) const = 0;
};

struct S_00e609c0_RayInput {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    const S_00e609c0_RayShapeCollectionFilter* m_pRayShapeCollectionFilter;
};

struct S_00e609c0_ConvexPieceShape : S_00e609c0_Shape {
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    const S_00e609c0_ShapeCollection* m_pShapeCollection;
    unsigned int* m_keys;
    int m_numKeys;

    S_00e609c0_Bool FUN_00e609c0(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const;
};

// Ray-casts each child shape whose filter allows it and, if any hit, sets results' key to the last hit index; returns whether any child was hit.
// @fnv 0x00e609c0
S_00e609c0_Bool S_00e609c0_ConvexPieceShape::FUN_00e609c0(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const
{
    int hitIndex;
    S_00e609c0_Timer("TtrcConvxPiece", hitIndex);
    results.changeLevel(1);
    hitIndex = -1;
    for (int i = 0; i < m_numKeys; i++)
    {
        if (!input.m_pRayShapeCollectionFilter ||
            input.m_pRayShapeCollectionFilter->IsCollisionEnabled(input, *m_pShapeCollection,
                *static_cast<const S_00e609c0_ShapeContainer*>(m_pShapeCollection), m_keys[i]))
        {
            S_00e609c0_ShapeBuffer buffer;
            const S_00e609c0_Shape* child = m_pShapeCollection->GetShapeForKey(m_keys[i], buffer);
            S_00e609c0_Bool hit = child->RayCast(input, results);
            if (hit)
            {
                hitIndex = i;
            }
        }
    }
    results.changeLevel(-1);
    if (hitIndex != -1)
    {
        results.setKey(hitIndex);
    }
    int endTicks;
    S_00e609c0_Timer("Et", endTicks);
    return hitIndex != -1;
}


struct StringCursor {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pFreeList;

    static inline StringCursor& GetMonitorStream() {
        return *(StringCursor*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    }

    inline void timerBegin(const char* name) {
        char* cur = m_kRayEnd;
        if (cur < m_pFreeList) {
            *(const char**)cur = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(cur + 4) = t;
            cur += 12;
            m_kRayEnd = cur;
        }
    }

    inline void timerEnd(const char* name) {
        char* cur = m_kRayEnd;
        if (cur < m_pFreeList) {
            *(const char**)cur = name;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(cur + 4) = t;
            cur += 12;
            m_kRayEnd = cur;
        }
    }
};

struct hkBool {
    char m_cBooleanValue;
    operator bool() const { return m_cBooleanValue != 0; }
};

struct BodyA {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    struct Filter* m_iFilter;
};

struct ShapeBase;
struct ShapeDerived;

struct Filter {
    virtual hkBool IsCollisionEnabled(const BodyA* bodyA, const ShapeDerived* shapeD, const ShapeBase* shapeB, int key);
};

struct ChildShape {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void func24(const BodyA* bodyA, const struct CdBody* bodyB, void* input);
};

struct ShapeBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual ChildShape* GetShapeForKey(int key, void* buffer);
};

struct ShapeDerived {
    int unk00; int unk04; int unk08; int unk0c;
    ShapeBase m_base;
};

struct BodyB {
    int unk00; int unk04;
    void* m_kMotionState;
};

struct CdBody {
    ChildShape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_kMotionState;
    const BodyB* m_parent;
};

struct FUN_00e60b00_cls {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    ShapeDerived* m_pCollisionShape;
    int* m_keys;
    int m_uiItemCount;

    void ProcessCollisionShapes(const BodyA* bodyA, const BodyB* bodyB, void* input);
};

// For each key passing bodyA's filter, gets the child shape and calls its func24 with bodyA, a CdBody built from bodyB, and input, between profiler timers.
// @fnv 0x00e60b00
void FUN_00e60b00_cls::ProcessCollisionShapes(const BodyA* bodyA, const BodyB* bodyB, void* input) {
    StringCursor::GetMonitorStream().timerBegin("TtrcConvxPiece");

    for (int i = 0; i < this->m_uiItemCount; ++i) {
        if (bodyA->m_iFilter) {
            const ShapeBase* pShapeBase = this->m_pCollisionShape ? &this->m_pCollisionShape->m_base : 0;
            if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(bodyA->m_iFilter->IsCollisionEnabled(bodyA, this->m_pCollisionShape, pShapeBase, this->m_keys[i])))->FUN_005609f0())
                continue;
        }

        __declspec(align(16)) int buffer[128];
        ChildShape* child = this->m_pCollisionShape->m_base.GetShapeForKey(this->m_keys[i], buffer);
        CdBody body;
        body.m_parent = bodyB;
        body.m_kMotionState = bodyB->m_kMotionState;
        body.m_pCollisionShape = child;
        body.m_uiCollisionShapeKey = i;
        child->func24(bodyA, &body, input);
    }

    StringCursor::GetMonitorStream().timerEnd("Et");
}

// sub ecx,0x14; jmp Destroy == MSVC adjustor thunk (Derived overrides a virtual both bases declare).
struct AdjPrimaryBase
{
    virtual void FUN_00e60c20();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct AdjSecondaryBase
{
    virtual void FUN_00e60c20();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00e60c20
    virtual void FUN_00e60c20();
};

AdjDerived::AdjDerived()
{
}

// Moved from hkpconvexpieceshape_gs_nogs_variant.cpp (VEGAS-15).

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include <new>
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/MoppFindAllVM.h"
#include "fnv/decl/MoppFindAllVirtualMachine.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_simd.h"

struct __declspec(align(16)) FNV_V4
{
    float x;
    float y;
    float z;
    int w;
};

union __declspec(align(16)) ShapeBuffer338
{
    __m128 alignment;
    char bytes[512];
};

struct FNV_Res
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void calc(__m128* a, __m128* out);
};

struct FNV_Inner
{
    virtual void i00();
    virtual void i04();
    virtual void i08();
    virtual void i0c();
    virtual void i10();
    virtual FNV_Res* run(int index, ShapeBuffer338* out);
};

struct FNV_Disp
{
    int d00;
    int d04;
    int d08;
    int d0c;
    FNV_Inner inner;
};

struct FNV_Owner
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    FNV_Disp* p20;
    int* p24;
    int n28;
    void FUN_00e608d0(FNV_V4* pA, FNV_V4* pOut);
};

// @fnv 0x00e608d0
void FNV_Owner::FUN_00e608d0(FNV_V4* pA, FNV_V4* pOut)
{
    ShapeBuffer338 big;
    FNV_V4 buf;
    float dot;
    float best = ::DAT_0104e148;
    int idx = 0;
    for (int i = 0; i < n28; i++)
    {
        FNV_Res* r = p20->inner.run(p24[i], &big);
        r->calc((__m128*)pA, (__m128*)&buf);
        __m128 prod = _mm_mul_ps(*(const __m128*)pA, *(const __m128*)&buf);
        __m128 s1 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        float d;
        _mm_store_ss(&d, _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), s1));
        if (d > best)
        {
            best = d;
            int t = buf.w & 0xc0ffffff;
            idx = t / 16 + i * 3;
            *(__m128*)pOut = *(const __m128*)&buf;
        }
    }
    pOut->w = idx | 0x3f000000;
}

extern "C" void __debugbreak();

inline void* operator new(size_t, void* p)
{
    return p;
}

class S5fb50_SimdReal
{
  public:
    S5fb50_SimdReal(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    __m128 m_vValue;
};

// hkVector4
class S5fb50_Vector4
{
  public:
    __m128 m_vComponents;
    inline void operator=(const S5fb50_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    inline void setAdd4(const S5fb50_Vector4& v0, const S5fb50_Vector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void sub4(const S5fb50_Vector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    inline void setSub4(const S5fb50_Vector4& v0, const S5fb50_Vector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setAbs4(const S5fb50_Vector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, *(const __m128*)&(*reinterpret_cast<const unsigned int (*)[4]>((void *)&::DAT_01017d10)));
    }
    inline void setMin4(const S5fb50_Vector4& a, const S5fb50_Vector4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    inline S5fb50_SimdReal dot3(const S5fb50_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
    }
    inline S5fb50_SimdReal lengthSquared3() const
    {
        return this->dot3(*this);
    }
    inline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    inline const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[a];
    }
};

// hkSphere
class S5fb50_Sphere
{
  public:
    inline float getRadius() const
    {
        return m_pos(3);
    }
    inline const S5fb50_Vector4& getPosition() const
    {
        return m_pos;
    }
    S5fb50_Vector4 m_pos;
};

// hkAabb
class S5fb50_Aabb
{
  public:
    S5fb50_Vector4 m_kMinimumCorner;
    S5fb50_Vector4 m_kMaximumCorner;
};

class S5fb50_PrimitiveInfo
{
  public:
    unsigned int ID;
};

struct S5fb50_Array
{
    S5fb50_PrimitiveInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    inline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    inline S5fb50_PrimitiveInfo& _expandOne(AudioHolder* router)
    {
        if (m_iElementCount == getCapacity())
        {
            ::ResizeAudioStream((::AudioAllocator *)(router->m_pAllocator), (::AudioStream *)(void *)(this), sizeof(S5fb50_PrimitiveInfo));
        }
        for (int i = 0; i < 1; i++)
            ::new (m_data + m_iElementCount + i) S5fb50_PrimitiveInfo;
        return m_data[m_iElementCount++];
    }
    inline S5fb50_PrimitiveInfo& AllocatePair()
    {
        return _expandOne(FUN_00c85750());
    }
};

struct S5fb50_Query
{
    unsigned int m_uiPropertyCount;
    unsigned int m_kProperties[1];
    int m_offset[3];
    int m_iIndex;
};

// hkErrStream
struct S5fb50_ErrStream
{
    void* unk00;
    void* unk04;
    void* unk08;
};
struct S5fb50_Error
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int id, unsigned int msgId, const char* desc, const char* file, int line);
};

class S5fb50_MoppVm
{
  public:
    S5fb50_Array* m_pPrimitiveInfoArray;
    int unk04;
    int unk08;
    int unk0c;
    static inline int read24(const unsigned char* PC)
    {
        int v = (PC[0] << 16) + (PC[1] << 8) + PC[2];
        return v;
    }
    inline void AddHit(unsigned int key, const unsigned int properties[1])
    {
        m_pPrimitiveInfoArray->AllocatePair().ID = key;
    }
};

class S5fb50_SphereQueryObject : public S5fb50_MoppVm
{
  public:
    S5fb50_Sphere m_pSphere;
    __forceinline int checkCollision(const S5fb50_Aabb& aabb, const S5fb50_Query* query, const unsigned char* PC)
    {
        S5fb50_Vector4 center;
        center.setAdd4(aabb.m_kMinimumCorner, aabb.m_kMaximumCorner);
        S5fb50_Vector4 extent;
        extent.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
        center.sub4(m_pSphere.getPosition());
        center.setAbs4(center);
        S5fb50_Vector4 nearest;
        nearest.setMin4(center, extent);
        S5fb50_Vector4 diff;
        diff.setSub4(nearest, center);
        float distance = diff.lengthSquared3();
        float radius2 = m_pSphere.getRadius() * m_pSphere.getRadius();
        if (distance > radius2)
        {
            return 0;
        }
        S5fb50_Vector4 farthest;
        farthest.setAdd4(center, extent);
        if (farthest.lengthSquared3() < radius2)
        {
            reinterpret_cast<::MoppFindAllVirtualMachine *>(this)->FUN_00e66600((const ::MoppState *)(query), PC);
            reinterpret_cast<::MoppFindAllVM *>(this)->FUN_00e66290((const ::MoppQueryState *)(query), PC);
            return 1;
        }
        return 2;
    }
};

class S5fb50_FloatAabbVm : public S5fb50_MoppVm
{
  public:
    struct TempAabb : public S5fb50_Aabb
    {
        TempAabb()
        {}
    };
    float m_vRayDirectionVector;
    int unk14;
    int unk18;
    int unk1c;
    S5fb50_SphereQueryObject m_kSphereQueryObject;

    void FUN_00e5fb50(const S5fb50_Query* query, const unsigned char* PC, TempAabb& aabb);
};

// @fnv 0x00e5fb50
void S5fb50_FloatAabbVm::FUN_00e5fb50(const S5fb50_Query* query, const unsigned char* PC, TempAabb& aabb)
{
    S5fb50_Query localQuery;
    while (1)
    {
        int command = PC[0];
        TempAabb tempAabb;
        int offsetR;
        int offsetL;
        switch (command)
        {
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c: {
            offsetR = PC[3];
            PC += 4;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            FUN_00e5fb50(query, PC, tempAabb);
            PC += offsetR;
            continue;
        }
        case 0x10:
        case 0x11:
        case 0x12: {
            const int dim = command - 0x10;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            offsetR = PC[1];
            offsetL = PC[2];
            aabb.m_kMaximumCorner(dim) =
                float((offsetR << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            tempAabb.m_kMinimumCorner(dim) =
                float((offsetL << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            offsetL = 0;
            offsetR = PC[3];
            PC += 4;
            goto do_compare;
        }
        case 0x20:
        case 0x21:
        case 0x22: {
            const int dim = command - 0x20;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            offsetL = PC[1];
            offsetR = offsetL + 1;
            offsetL <<= query->m_iIndex;
            offsetR <<= query->m_iIndex;
            offsetL += query->m_offset[dim];
            offsetR += query->m_offset[dim];
            tempAabb.m_kMinimumCorner(dim) = float(offsetL) * m_vRayDirectionVector;
            aabb.m_kMaximumCorner(dim) = float(offsetR) * m_vRayDirectionVector;
            offsetL = 0;
            offsetR = PC[2];
            PC += 3;
            goto do_compare;
        }
        case 0x23:
        case 0x24:
        case 0x25: {
            const int dim = command - 0x23;
            tempAabb.m_kMinimumCorner = aabb.m_kMinimumCorner;
            tempAabb.m_kMaximumCorner = aabb.m_kMaximumCorner;
            offsetR = PC[1];
            offsetL = PC[2];
            aabb.m_kMaximumCorner(dim) =
                float((offsetR << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            tempAabb.m_kMinimumCorner(dim) =
                float((offsetL << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            offsetL = (PC[3] << 8) + PC[4];
            offsetR = (PC[5] << 8) + PC[6];
            PC += 7;
        }
        do_compare: {
            while (1)
            {
                const int command2 = PC[offsetL];
                if (command2 < 0x26 || command2 > 0x2b)
                {
                    break;
                }
                if (command2 >= 0x29)
                {
                    const int dim = command2 - 0x29;
                    aabb.m_kMinimumCorner(dim) = float(read24(PC + offsetL + 1)) * m_vRayDirectionVector;
                    aabb.m_kMaximumCorner(dim) = float(read24(PC + offsetL + 4)) * m_vRayDirectionVector;
                    offsetL += 7;
                }
                else
                {
                    const int dim = command2 - 0x26;
                    aabb.m_kMinimumCorner(dim) =
                        float(((PC + offsetL)[1] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    aabb.m_kMaximumCorner(dim) =
                        float(((PC + offsetL)[2] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    offsetL += 3;
                }
            }
            while (1)
            {
                const int command2 = PC[offsetR];
                if (command2 < 0x26 || command2 > 0x2b)
                {
                    break;
                }
                if (command2 >= 0x29)
                {
                    const int dim = command2 - 0x29;
                    tempAabb.m_kMinimumCorner(dim) = float(read24(PC + offsetR + 1)) * m_vRayDirectionVector;
                    tempAabb.m_kMaximumCorner(dim) = float(read24(PC + offsetR + 4)) * m_vRayDirectionVector;
                    offsetR += 7;
                }
                else
                {
                    const int dim = command2 - 0x26;
                    tempAabb.m_kMinimumCorner(dim) =
                        float(((PC + offsetR)[1] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    tempAabb.m_kMaximumCorner(dim) =
                        float(((PC + offsetR)[2] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
                    offsetR += 3;
                }
            }
            const int hitR = m_kSphereQueryObject.checkCollision(tempAabb, query, PC + offsetR);
            const int hitL = m_kSphereQueryObject.checkCollision(aabb, query, PC + offsetL);
            if (hitR != 2)
            {
                if (hitL != 2)
                {
                    return;
                }
                PC += offsetL;
                continue;
            }
            if (hitL != 2)
            {
                aabb.m_kMinimumCorner = tempAabb.m_kMinimumCorner;
                aabb.m_kMaximumCorner = tempAabb.m_kMaximumCorner;
                PC += offsetR;
                continue;
            }
            FUN_00e5fb50(query, PC + offsetR, tempAabb);
            PC += offsetL;
            continue;
        }
        case 0x29:
        case 0x2a:
        case 0x2b: {
            const int dim = command - 0x29;
            aabb.m_kMinimumCorner(dim) = float(read24(PC + 1)) * m_vRayDirectionVector;
            aabb.m_kMaximumCorner(dim) = float(read24(PC + 4)) * m_vRayDirectionVector;
            PC += 7;
            goto doCut;
        }
        case 0x26:
        case 0x27:
        case 0x28: {
            const int dim = command - 0x26;
            aabb.m_kMinimumCorner(dim) =
                float((PC[1] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            aabb.m_kMaximumCorner(dim) =
                float((PC[2] << query->m_iIndex) + query->m_offset[dim]) * m_vRayDirectionVector;
            PC += 3;
        }
        doCut: {
            if (PC[0] >= 0x26 && PC[0] <= 0x2b)
            {
                continue;
            }
            const int hit = m_kSphereQueryObject.checkCollision(aabb, query, PC);
            if (hit == 2)
            {
                continue;
            }
            return;
        }
        case 5: {
            offsetL = PC[1];
            PC += 2;
            PC += offsetL;
            continue;
        }
        case 6: {
            offsetR = PC[1];
            offsetL = PC[2];
            PC += 3;
            PC += (offsetR << 8) + offsetL;
            continue;
        }
        case 7: {
            offsetR = PC[1];
            const int mid = PC[2];
            offsetL = PC[3];
            PC += 4;
            PC += (offsetR << 16) + (mid << 8) + offsetL;
            continue;
        }
        case 1:
        case 2:
        case 3:
        case 4: {
            const int shift = command;
            localQuery.m_offset[0] = (PC[1] << query->m_iIndex) + query->m_offset[0];
            localQuery.m_offset[1] = (PC[2] << query->m_iIndex) + query->m_offset[1];
            localQuery.m_offset[2] = (PC[3] << query->m_iIndex) + query->m_offset[2];
            localQuery.m_iIndex = query->m_iIndex - shift;
            for (int i = 0; i < 1; i++)
            {
                localQuery.m_kProperties[i] = query->m_kProperties[i];
            }
            localQuery.m_uiPropertyCount = query->m_uiPropertyCount;
            query = &localQuery;
            PC += 4;
            continue;
        }
        case 9: {
            const unsigned int offset = PC[1];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_uiPropertyCount += offset;
            PC += 2;
            continue;
        }
        case 10: {
            const unsigned int offset = (PC[1] << 8) + PC[2];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_uiPropertyCount += offset;
            PC += 3;
            continue;
        }
        case 11: {
            const unsigned int offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_uiPropertyCount = offset;
            PC += 5;
            continue;
        }
        case 0:
            return;
        case 0x50:
            offsetL = PC[1];
            goto add_Terminal;
        case 0x51:
            offsetR = PC[1];
            offsetR <<= 8;
            offsetL = PC[2];
            offsetL += offsetR;
            goto add_Terminal;
        case 0x52:
            offsetL = PC[1];
            offsetL <<= 16;
            offsetR = PC[2];
            offsetR <<= 8;
            offsetR += PC[3];
            offsetL += offsetR;
            goto add_Terminal;
        case 0x53:
            offsetL = PC[1];
            offsetL <<= 24;
            offsetR = PC[2];
            offsetR <<= 16;
            offsetL += offsetR;
            offsetR = PC[3];
            offsetL += PC[4];
            offsetR <<= 8;
            offsetL += offsetR;
            goto add_Terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            offsetL = command - 0x30;
        add_Terminal:
            offsetL += query->m_uiPropertyCount;
            AddHit(offsetL, query->m_kProperties);
            return;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            const int property = PC[0] - 0x60;
            const unsigned int value = PC[1];
            PC += 2;
            localQuery.m_kProperties[property] = value;
        }
        propertyCopy: {
            const unsigned int prop = localQuery.m_kProperties[0];
            if (query != &localQuery)
            {
                localQuery = *query;
                query = &localQuery;
            }
            localQuery.m_kProperties[0] = prop;
            continue;
        }
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67: {
            const int property = PC[0] - 0x64;
            const unsigned int value = (PC[1] << 8) + PC[2];
            localQuery.m_kProperties[property] = value;
            PC += 3;
            goto propertyCopy;
        }
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b: {
            const int property = PC[0] - 0x68;
            const unsigned int value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            localQuery.m_kProperties[property] = value;
            PC += 5;
            goto propertyCopy;
        }
        default:
            do
            {
                char buf[512];
                S5fb50_ErrStream ostr;
                new ((void *)&(ostr)) ::FUN_00cb1600(buf, sizeof(buf));
                reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0(
                    "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
                if ((*reinterpret_cast<::S5fb50_Error * *>(&::DAT_01268360))->message(
                        3, 0x1298fedd, buf,
                        "d:\\build\\20091222_000100_AiAnBeClDePh\\Source\\Physics/Internal/Collide/Mopp/Machine/hkpMoppUsingFloatAabbVirtualMachine.inl",
                        301))
                {
                    __debugbreak();
                }
                reinterpret_cast<struct ::FUN_00cc00e0 *>(&(ostr))->FUN_00cc00e0::~FUN_00cc00e0();
            } while (0);
            continue;
        }
    }
}
