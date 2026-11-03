
// src/havok/physics/utilities/actions/spring/hkpspringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/spring/hkpspringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include <cstring>
#include "fnv/decl/FUN_00c7f690_cls.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01269000.h"
#include "havok/hkpSpringAction.h"


// @fnv 0x00cf4ef0
int* __cdecl FUN_00cf4ef0()
{
    return &(*reinterpret_cast<int *>(&::g_01269168));
}


struct hkShape00D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x47];
    hkShape00D4F0()
    {
        m_type = 2;
    }
};

struct hkShape90D4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape90D4F0()
    {
        m_type = 9;
    }
};

struct hkShape9CD4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape9CD4F0()
    {
        m_type = 8;
    }
};

struct hkShapeA8D4F0
{
    unsigned short m_type;
    unsigned short unk02;
    hkShapeA8D4F0()
    {
        m_type = 7;
    }
};

struct hkShapeB0D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x37];
    hkShapeB0D4F0()
    {
        m_type = 4;
    }
};

struct hkShape120D4F0
{
    unsigned short m_type;
    hkShape120D4F0()
    {
        m_type = 12;
    }
};

class FUN_00d4f000
{
  public:
    hkShape00D4F0 m_s00;
    hkShape90D4F0 m_s90;
    hkShape9CD4F0 m_s9C;
    hkShapeA8D4F0 m_sA8;
    hkShapeA8D4F0 m_sAC;
    hkShapeB0D4F0 m_sB0;
    hkShape120D4F0 m_s120;

    FUN_00d4f000() throw();
};

// Constructs the object by initialising its embedded shape members; the zero-fill branch is never taken because pcBegin equals pcEnd.
// @fnv 0x00d4f000
FUN_00d4f000::FUN_00d4f000() throw()
{
    char* pcBegin = (char*)&m_sB0;
    char* pcEnd = (char*)&m_sB0;
    if (pcBegin < pcEnd)
        std::memset(pcBegin, 0, pcEnd - pcBegin);
}

struct FUN_00cf4d80
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
    float m_fMass;
    float m_fSpringConstant;
    float m_fDamping;
    bool m_bModifierActive;
    bool m_bEnableState;
    FUN_00cf4d80(void* a, void* b, unsigned long c);
};
extern int DAT_010d08f4;
struct FUN_00d4d340 : FUN_00cf4d80
{
    FUN_00d4d340(void* a, void* b, unsigned long c);
};
// Calls the base constructor, sets the vtable, m_fMass to 1.0, spring constant and damping from globals, and sets both bool flags to true.
// @fnv 0x00d4d340
FUN_00d4d340::FUN_00d4d340(void* a, void* b, unsigned long c) : FUN_00cf4d80(a, b, c)
{
    float* __restrict pf = &m_fSpringConstant;
    m_fMass = 1.0f;
    *pf = DAT_01013974;
    *(int* __restrict*)this = &DAT_010d08f4;
    m_fDamping = DAT_0101e2bc;
    *(volatile bool*)&m_bModifierActive = true;
    *(volatile bool*)&m_bEnableState = true;
}



struct hkSimdRealD4D3
{
    __m128 m_vValue;

    hkSimdRealD4D3(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkTransformD4D3;

struct hkVector4D4D3
{
    __m128 m_vComponents;

    void setSub4(const hkVector4D4D3& a, const hkVector4D4D3& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD4D3 length3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
    }
};

struct hkTransformD4D3
{
    hkVector4D4D3 m_rotation[3];
    hkVector4D4D3 m_vTranslation;
};

struct hkpEntityD4D3
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    unsigned int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    hkTransformD4D3 m_kMotionTransform;
};

class hkBaseObjectD4D3
{
  public:
    virtual ~hkBaseObjectD4D3() throw();
};

class hkpStiffSpringWrapperD4D3 : public hkBaseObjectD4D3
{
  public:
    void UpdatePivotsAndRestLength(const hkVector4D4D3& kPivotAW, const hkVector4D4D3& kPivotBW);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntityD4D3* m_pEntityA;
    hkpEntityD4D3* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4D4D3 m_kPivotInA;
    hkVector4D4D3 m_kPivotInB;
    float m_fSpringRestLength;
};

// Transforms world-space pivots into local entity space, then stores their 3D distance as the spring rest length.
// @fnv 0x00d4d390
void hkpStiffSpringWrapperD4D3::UpdatePivotsAndRestLength(const hkVector4D4D3& kPivotAW, const hkVector4D4D3& kPivotBW)
{
    hkpEntityD4D3* pkA = m_pEntityA;
    hkpEntityD4D3* pkB = m_pEntityB;
    reinterpret_cast<::FUN_00c7f690_cls *>(&(m_kPivotInA))->FUN_00c7f690((const ::S_00c7f690_M *)&(pkA->m_kMotionTransform), (const ::S_00c7f690_V *)&(kPivotAW));
    reinterpret_cast<::FUN_00c7f690_cls *>(&(m_kPivotInB))->FUN_00c7f690((const ::S_00c7f690_M *)&(pkB->m_kMotionTransform), (const ::S_00c7f690_V *)&(kPivotBW));
    hkVector4D4D3 kDiff;
    kDiff.setSub4(kPivotAW, kPivotBW);
    m_fSpringRestLength = kDiff.length3();
}

namespace fnv_00d4d410 {


struct hkSimdRealD4D41
{
    __m128 m_vValue;

    hkSimdRealD4D41(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkTransformD4D41;

struct hkVector4D4D41
{
    __m128 m_vComponents;

    hkVector4D4D41()
    {}
    hkVector4D4D41(const hkVector4D4D41& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D4D41& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void FUN_00c7f640(const hkTransformD4D41& kT, const hkVector4D4D41& kV);
    void setSub4(const hkVector4D4D41& a, const hkVector4D4D41& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD4D41 length3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
    }
};

struct hkTransformD4D41
{
    hkVector4D4D41 m_rotation[3];
    hkVector4D4D41 m_vTranslation;
};

struct hkpEntityD4D41
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    unsigned int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    hkTransformD4D41 m_kMotionTransform;
};

class hkBaseObjectD4D41
{
  public:
    virtual ~hkBaseObjectD4D41() throw();
};

class hkpStiffSpringWrapperD4D41 : public hkBaseObjectD4D41
{
  public:
    void SetPivots(const hkVector4D4D41& kPivotA, const hkVector4D4D41& kPivotB);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntityD4D41* m_pEntityA;
    hkpEntityD4D41* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4D4D41 m_kPivotInA;
    hkVector4D4D41 m_kPivotInB;
    float m_fSpringRestLength;
};

// Stores the given pivot vectors and computes the spring rest length from the world-space distance between the two pivots.
// @fnv 0x00d4d410
void hkpStiffSpringWrapperD4D41::SetPivots(const hkVector4D4D41& kPivotA, const hkVector4D4D41& kPivotB)
{
    hkpEntityD4D41* pkA = m_pEntityA;
    hkpEntityD4D41* pkB = m_pEntityB;
    m_kPivotInA = kPivotA;
    m_kPivotInB = kPivotB;
    hkVector4D4D41 kPivotAW;
    kPivotAW.FUN_00c7f640(pkA->m_kMotionTransform, kPivotA);
    hkVector4D4D41 kPivotBW;
    kPivotBW.FUN_00c7f640(pkB->m_kMotionTransform, kPivotB);
    hkVector4D4D41 kDiff;
    kDiff.setSub4(kPivotAW, kPivotBW);
    m_fSpringRestLength = kDiff.length3();
}
}  // namespace fnv_00d4d410

namespace fnv_00d4d4a0 {

struct hkVector4D4A0
{
    __m128 m_vComponents;

    void operator=(const hkVector4D4A0& value)
    {
        m_vComponents = value.m_vComponents;
    }
};

struct hkMemoryAllocatorD4A0
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct hkMemoryRouterD4A0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkMemoryAllocatorD4A0* m_pStreamAllocator;

    hkMemoryAllocatorD4A0& heap() const
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterD4A0* __cdecl FUN_00c85750();

struct hkpEntityPairD4A0
{
    void* m_pEntityA;
    void* m_pEntityB;
};

struct hkpCloneArgD4A0
{
    hkpEntityPairD4A0* m_kActorEntries;
    int m_type;
};

struct S00d4d4a0_Obj
{
    static void* operator new(size_t size)
    {
        S00d4d4a0_Obj* memory = reinterpret_cast<S00d4d4a0_Obj*>(FUN_00c85750()->heap().AllocateMemoryBlock(size));
        memory->m_usMemSizeAndFlags = static_cast<unsigned short>(size);
        return memory;
    }

    S00d4d4a0_Obj* FUN_00d4d340(void* entityA, void* entityB, void* data);

    S00d4d4a0_Obj* FUN_00d4d4a0(const hkpCloneArgD4A0& argA, const hkpCloneArgD4A0& argB) const;

    unsigned int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* unk08;
    void* unk0C;
    void* m_ulUserData;
    void* unk14;
    void* m_pEntityA;
    void* m_pEntityB;
    hkVector4D4A0 m_kLastForce;
    hkVector4D4A0 m_kPivotInA;
    hkVector4D4A0 m_kPivotInB;
    float m_fRestLength;
    float m_fSpringStrength;
    float m_fMotorDamping;
    unsigned char m_bSpringEnabled;
    unsigned char m_bElastic;
    unsigned short unk5E;
};

// Returns null unless argA.m_type is 2 and argB.m_type is 0; else builds a copy on argA's entity pair and copies pivots, rest length, spring, damping and flags.
// @fnv 0x00d4d4a0
S00d4d4a0_Obj* S00d4d4a0_Obj::FUN_00d4d4a0(const hkpCloneArgD4A0& argA, const hkpCloneArgD4A0& argB) const
{
    if (argA.m_type != 2)
        return 0;

    if (argB.m_type != 0)
        return 0;

    S00d4d4a0_Obj* clone = new S00d4d4a0_Obj;

    clone = ((::fnv_00d4d4a0::S00d4d4a0_Obj *)(new ((void *)(clone)) ::FUN_00d4d340(argA.m_kActorEntries->m_pEntityA, argA.m_kActorEntries->m_pEntityB, (unsigned long)(m_ulUserData))));

    clone->m_kPivotInA = m_kPivotInA;
    clone->m_kPivotInB = m_kPivotInB;
    clone->m_fRestLength = m_fRestLength;
    clone->m_fSpringStrength = m_fSpringStrength;
    clone->m_fMotorDamping = m_fMotorDamping;
    clone->m_bSpringEnabled = m_bSpringEnabled;
    clone->m_bElastic = m_bElastic;

    return clone;
}
}  // namespace fnv_00d4d4a0

// Moved from hkpspringaction_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_01017000.h"
int* __cdecl FUN_00cf4ef0();
void* __cdecl _fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiNumBytes);

struct __declspec(align(16)) SpringVector
{
    __m128 q;
    __m128 get() const
    {
        return q;
    }
    void set(__m128 v)
    {
        q = v;
    }
    void FUN_00c7f640(const void* transform, const hkVector4* local);
};
struct SpringMotion
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void apply(float dt, const hkVector4* force, const SpringVector* point);
};
class hkpEntity
{
  public:
    unsigned unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    SpringMotion motion;
    unsigned unkE4, unkE8, unkEC;
    hkTransform transform;
    void FUN_00ca0c40(const SpringVector* point, SpringVector* velocity);
    void ApplyForceAtPoint(float dt, const hkVector4& force, const SpringVector& point)
    {
        reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
        motion.apply(dt, &force, &point);
    }
};
struct SpringStep
{
    float unk00, unk04, deltaTime;
};
struct SpringAction : hkpSpringAction
{
    void FUN_00d4d530(const SpringStep& step);
};
static __m128 dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    y = _mm_add_ss(y, p);
    z = _mm_add_ss(z, y);
    return z;
}
static float SpringLength3(__m128 v)
{
    float r;
    _mm_store_ss(&r, _mm_sqrt_ss(dot3(v, v)));
    return r;
}
static float SpringDot3(__m128 a, __m128 b)
{
    float r;
    _mm_store_ss(&r, dot3(a, b));
    return r;
}
static __m128 SpringSplat(float v)
{
    __m128 s = _mm_set_ss(v);
    return _mm_shuffle_ps(s, s, 0);
}
static __m128 SpringSplatRef(const float& v)
{
    __m128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
static __m128 SpringSplatMem(float v)
{
    __m128 s = _mm_load_ss(&v);
    return _mm_shuffle_ps(s, s, 0);
}
static __m128 broadcast(float v)
{
    return _mm_load_ps1(&v);
}
// @fnv 0x00d4d530
void SpringAction::FUN_00d4d530(const SpringStep& step)
{
    hkpEntity* a = m_pEntityA;
    hkpEntity* b = m_pEntityB;
    SpringVector pointA, pointB, direction, velocityA, velocityB;
    pointA.FUN_00c7f640(&a->transform, &m_kPositionA);
    pointB.FUN_00c7f640(&b->transform, &m_kPositionB);
    float tolerance = ::AngularDashpotApplyD4DCB0::DAT_01017d00;
    __m128 displacement = _mm_sub_ps(pointB.get(), pointA.get());
    float length = SpringLength3(displacement);
    if (tolerance > length)
        return;
    direction.set(_mm_mul_ps(broadcast(1.0f / length), displacement));
    if (!m_bSpringEnabled && length < m_fRestLength)
        return;
    if (!m_bElastic && length > m_fRestLength)
        return;
    a->FUN_00ca0c40(&pointA, &velocityA);
    b->FUN_00ca0c40(&pointB, &velocityB);
    float force = (length - m_fRestLength) * m_fSpringStrength +
                  m_fMotorDamping * SpringDot3(_mm_sub_ps(velocityB.get(), velocityA.get()), direction.get());
    _mm_store_ps(&m_kLastForce.x, _mm_mul_ps(SpringSplatRef(-force), direction.get()));
    b->ApplyForceAtPoint(step.deltaTime, m_kLastForce, pointB);
    _mm_store_ps(&m_kLastForce.x, _mm_mul_ps(SpringSplatRef(force), direction.get()));
    a->ApplyForceAtPoint(step.deltaTime, m_kLastForce, pointA);
}
