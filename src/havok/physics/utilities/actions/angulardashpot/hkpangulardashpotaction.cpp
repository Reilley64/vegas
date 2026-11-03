
// src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include <xmmintrin.h>
#include "havok/hkpAngularDashpotAction.h"

#include "fnv/symbols_simd.h"

struct hkQuaternionD4DB
{
    __m128 m_vec;
};


class FUN_00cf4d80
{
  public:
    FUN_00cf4d80(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw();
    virtual ~FUN_00cf4d80() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned long m_ulUserData;
    const char* m_name;
    void* m_pEntityA;
    void* m_pEntityB;
};

class FUN_00d4dbe0 : public FUN_00cf4d80
{
  public:
    FUN_00d4dbe0(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw();
    virtual ~FUN_00d4dbe0() throw();

    hkQuaternionD4DB m_rotation;
    float m_fSpringStrength;
    float m_fMotorDamping;
    int unk38, unk3C;
};

// @fnv 0x00d4dbe0
FUN_00d4dbe0::FUN_00d4dbe0(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw()
    : FUN_00cf4d80(pkEntityA, pkEntityB, ulUserData), m_fSpringStrength(0.1f), m_fMotorDamping(0.01f)
{
    m_rotation.m_vec = DAT_010c71b0;
}

namespace fnv_00d4dc30 {
class hkMemoryAllocatorD4DC
{
  public:
    virtual ~hkMemoryAllocatorD4DC() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterD4DC
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4DC* m_pStreamAllocator;
    hkMemoryAllocatorD4DC& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4DC& __cdecl FUN_00c85750();

struct __declspec(align(16)) hkVector4D4DC
{
    __m128 m_vComponents;
    void operator=(const hkVector4D4DC& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkpEntityPairD4DC
{
    void* m_pEntityA;
    void* m_pEntityB;
};

struct hkpConstraintInputD4DC
{
    hkpEntityPairD4DC* m_pair;
    int m_type;
};

class hkReferencedObjectD4DC
{
  public:
    virtual ~hkReferencedObjectD4DC() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(size_t uiSize)
    {
        hkReferencedObjectD4DC* pkObj =
            static_cast<hkReferencedObjectD4DC*>(FUN_00c85750().heap().AllocateMemoryBlock(uiSize));
        pkObj->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObj;
    }
    static void operator delete(void* p) throw();
};

class FUN_00d4dbe0 : public hkReferencedObjectD4DC
{
  public:
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4D4DC m_kAxisEndPoints;
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    int unk38;
    int unk3C;

    FUN_00d4dbe0(void* pvEntityA, void* pvEntityB, int iUserData) throw();
    virtual ~FUN_00d4dbe0() throw();
};

class hkpConstraintTemplateD4DC
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_ulUserData;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4D4DC m_kAxisEndPoints;
    float m_kMinimumCorner;
    float m_kMaximumCorner;

    FUN_00d4dbe0* FUN_00d4dc30(const hkpConstraintInputD4DC& kA, const hkpConstraintInputD4DC& kB);
};

// Returns null unless kA.m_type is 2 and kB.m_type is 0; otherwise creates a FUN_00d4dbe0 from kA's entity pair and copies axis end points and min/max corners.
// @fnv 0x00d4dc30
FUN_00d4dbe0* hkpConstraintTemplateD4DC::FUN_00d4dc30(const hkpConstraintInputD4DC& kA,
                                                      const hkpConstraintInputD4DC& kB)
{
    if (kA.m_type != 2)
        return 0;
    if (kB.m_type != 0)
        return 0;
    FUN_00d4dbe0* pkResult = new FUN_00d4dbe0(kA.m_pair->m_pEntityA, kA.m_pair->m_pEntityB, m_ulUserData);
    pkResult->m_kAxisEndPoints = m_kAxisEndPoints;
    pkResult->m_kMinimumCorner = m_kMinimumCorner;
    pkResult->m_kMaximumCorner = m_kMaximumCorner;
    return pkResult;
}
}  // namespace fnv_00d4dc30

// Moved from hkpangulardashpotaction_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/C74C20Quat.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_01017000.h"

typedef hkpAngularDashpotAction DashpotActionBaseD4DCB0;
typedef hkReferencedObject DashpotReferencedBaseD4DCB0;

namespace AngularDashpotApplyD4DCB0 {

typedef __m128 DashpotQuadD4DCB0;

static __forceinline DashpotQuadD4DCB0 splat(const float& x)
{
    DashpotQuadD4DCB0 t = _mm_load_ss(&x);
    return _mm_shuffle_ps(t, t, 0);
}

extern const float DAT_01017d00 = 0.001f;

static const DashpotQuadD4DCB0 DashpotNegXY = {{-0.0f, -0.0f, -0.0f, 0.0f}};
static const DashpotQuadD4DCB0 DashpotNegAll = {{-0.0f, -0.0f, -0.0f, -0.0f}};

struct S00d4dcb0_DashpotInputRec
{
    unsigned int unk00;
    unsigned int unk04;
    float m_stepDt;
};

struct S00d4dcb0_FUN_00c66320_shell
{
    DashpotQuadD4DCB0 m_vec;
};

struct S00d4dcb0_DashpotVObjRec
{
    virtual void virt00();
    virtual void virt04();
    virtual void virt08();
    virtual void virt0c();
    virtual void virt10();
    virtual void virt14();
    virtual void virt18();
    virtual void virt1c();
    virtual void virt20();
    virtual void virt24();
    virtual void virt28();
    virtual void virt2c();
    virtual void virt30();
    virtual void virt34();
    virtual void virt38();
    virtual void virt3c();
    virtual void virt40();
    virtual void virt44();
    virtual void virt48();
    virtual void virt4c();
    virtual void virt50();
    virtual void virt54(const void* arg);
};

struct S00d4dcb0_DashpotEntRec : public DashpotReferencedBaseD4DCB0
{
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    S00d4dcb0_DashpotVObjRec unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    DashpotQuadD4DCB0 unk160;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    DashpotQuadD4DCB0 unk1C0;
};

class S00d4dcb0_DashpotAct_shell : public DashpotActionBaseD4DCB0
{
  public:
    void FUN_00d4dcb0(const S00d4dcb0_DashpotInputRec& input);
};

// @fnv 0x00d4dcb0
void S00d4dcb0_DashpotAct_shell::FUN_00d4dcb0(const S00d4dcb0_DashpotInputRec& input)
{
    float w = input.m_stepDt * DAT_010179e0;
    S00d4dcb0_DashpotEntRec* aEnt = (S00d4dcb0_DashpotEntRec*)m_pEntityA;
    S00d4dcb0_DashpotEntRec* bEnt = (S00d4dcb0_DashpotEntRec*)m_pEntityB;
    struct S00d4dcb0_Vectors
    {
        S00d4dcb0_FUN_00c66320_shell qprod;
        DashpotQuadD4DCB0 tmp;
    } v;
    S00d4dcb0_FUN_00c66320_shell* __restrict quat = &v.qprod;
    ::fnv_00c66320::FUN_00c66320((__m128 *)(quat), (void *)(&bEnt->unk160), (const __m128 *)(const __m128 *)((DashpotQuadD4DCB0*)&m_rotation), {});

    v.tmp = _mm_xor_ps(v.qprod.m_vec, DashpotNegXY);
    ::fnv_00c66320::FUN_00c66320((__m128 *)(quat), (void *)(&aEnt->unk160), (const __m128 *)(const __m128 *)(&v.tmp), {});
    v.tmp = _mm_sub_ps(aEnt->unk1C0, bEnt->unk1C0);

    float t = reinterpret_cast<::C74C20Quat *>((quat))->GetAngle();

    DashpotQuadD4DCB0 corr = _mm_setzero_ps();
    if (t > DAT_01017d00)
        corr = _mm_mul_ps(splat(t), quat->m_vec);

    DashpotQuadD4DCB0 strength, damping;
    {
        float ws0 = w * m_fSpringStrength;
        strength = _mm_load_ss(&ws0);
    }
    {
        float ws1 = w * m_fMotorDamping;
        damping = _mm_load_ss(&ws1);
    }
    union S00d4dcb0_Impulse
    {
        DashpotQuadD4DCB0 v;
    };
    S00d4dcb0_Impulse impulse;
    DashpotQuadD4DCB0& sum = impulse.v;
    sum = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(damping, damping, 0), v.tmp),
                     _mm_mul_ps(_mm_shuffle_ps(strength, strength, 0), corr));

    reinterpret_cast<::hkpEntityC9C *>((bEnt))->FUN_00c9c1d0();
    bEnt->unkE0.virt54(&sum);
    sum = _mm_xor_ps(sum, DashpotNegAll);
    reinterpret_cast<::hkpEntityC9C *>((aEnt))->FUN_00c9c1d0();
    aEnt->unkE0.virt54(&sum);
}

}
