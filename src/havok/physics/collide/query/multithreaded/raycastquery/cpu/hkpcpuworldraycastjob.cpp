
// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/symbols_00e2b000.h"
#include "fnv/symbols_010db000.h"
#include "fnv/symbols_0126e000.h"
struct ValueHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char value;
    unsigned char* CopyValue(unsigned char* output);
};

// @fnv 0x00df8910
unsigned char* ValueHolder::CopyValue(unsigned char* output)
{
    *output = value;
    return output;
}

struct S_00df8990_Obj;


struct S_00df8990_Obj
{
    void InvokeCallback(void* a, void* b);
};

// @fnv 0x00df8990
void S_00df8990_Obj::InvokeCallback(void* a, void* b)
{
    DAT_0126ec04(a, b, this);
}

struct S_00df8d60_Bool
{
    char m_cBooleanValue;
    S_00df8d60_Bool()
    {}
};
struct S_00df8d60_Data
{
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    char unk4;
    signed char unk5;
};
struct S_00df8d60
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    float unk14;
    float FUN_00df8d60(const S_00df8d60_Data* data, int unused);
};
struct ParamBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_iValue;
};

struct Container
{
};

struct FUN_00df8db0_cls
{
    int unk00;
    int unk04;
    int unk08;
    float m_fResult;

    float GetResult(ParamBlock* apParam);
};

extern int DAT_0101e594;

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00df8960_cls
{
    const void* m_vptr;

    FUN_00df8960_cls* FUN_00df8960(unsigned char acFlags);
};

// Sets the vtable pointer and, when bit 0 of acFlags is set, frees this 0x1c-byte object through the allocator from FUN_00c85750.
// @fnv 0x00df8960
FUN_00df8960_cls* FUN_00df8960_cls::FUN_00df8960(unsigned char acFlags)
{
    m_vptr = &DAT_0101e594;
    if (acFlags & 1)
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, 0x1c);
    }
    return this;
}

struct AdjustedBase
{
};

struct AdjustOwner
{
    void* FUN_00df8d90(void* apFirst, int aiSecond);
};

struct FUN_00df8dd0_Param
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_i0c;
};

struct FUN_00df8dd0_helper
{
};

struct FUN_00df8dd0_cls
{
    int unk00;
    int unk04;
    float m_f08;

    float FUN_00df8dd0(FUN_00df8dd0_Param* p);
};

namespace fnv_00df9470 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct BaseA
{
    virtual ~BaseA()
    {}
};

struct BaseB
{
    virtual ~BaseB()
    {}
};

struct BaseC
{
    virtual ~BaseC()
    {}
};

struct BaseD
{
    virtual ~BaseD()
    {}
};

class MultiBaseOwner : public BaseA, public BaseB, public BaseC, public BaseD
{
  public:
    MultiBaseOwner* FUN_00df9470(unsigned char acFlags);
};

// Destructs the object, then, if bit 0 of acFlags is set, frees it through the allocator obtained from FUN_00c85750, and returns this.
// @fnv 0x00df9470
MultiBaseOwner* MultiBaseOwner::FUN_00df9470(unsigned char acFlags)
{
    this->MultiBaseOwner::~MultiBaseOwner();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, 0x80);
    }
    return this;
}
}  // namespace fnv_00df9470

struct DF8930Primary
{
    virtual void vfunc00();
    virtual void FUN_00df8930();

    int unk04;
    int unk08;
};

struct DF8930Secondary
{
    virtual void FUN_00df8930();
};

struct DF8930Object : DF8930Primary, DF8930Secondary
{
    DF8930Object();

// @fnv 0x00df8930
    virtual void FUN_00df8930();
};

DF8930Object::DF8930Object()
{}

// Adjustor thunk for a secondary base of a multiply-inherited class.
//
// The original bytes at 0x00df8950 are
//     sub ecx, 8
//     jmp 0xdf9470
// i.e. the compiler-generated "[thunk]: Derived::FUN_00df8950`adjustor{8}'"
// that MSVC emits for the per-base vftable of the SECONDARY base: the
// secondary base subobject lives 8 bytes into the most-derived object, so
// the thunk has to move "this" back by 8 before tail-jumping into the
// most-derived implementation.
//
// The most-derived implementation of FUN_00df8950 is only DECLARED here (it
// lives in another translation unit of the game), so the tail jump stays an
// undefined external and the linker/checker resolves it from the original.

struct NiObjectBase
{
    NiObjectBase();
    virtual void FUN_00df8950(int flag);
    int unk04;
};

struct NiExtraDataBase
{
    NiExtraDataBase();
    virtual void FUN_00df8950(int flag);
};

class Derived : public NiObjectBase, public NiExtraDataBase
{
  public:
    Derived();
// @fnv 0x00df8950
    virtual void FUN_00df8950(int flag);
};

NiObjectBase::NiObjectBase()
{}
NiExtraDataBase::NiExtraDataBase()
{}
Derived::Derived()
{}

#include <xmmintrin.h>
struct S_00df8990_Obj;

struct Source
{
    __m128 m_v00;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned char m_20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int unk38;
    unsigned char m_3c;
};

struct Spawned
{
    unsigned int m_00;
    float m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    Spawned(unsigned int first, unsigned int last)
        : m_00((unsigned int)DAT_010dbb04), m_04(1.0f), m_08(first), m_0c(first), m_10(last), m_14(0), m_18(0)
    {}
};

struct SubBase
{
    unsigned value;
};
struct Leading
{
    unsigned a, b, c, d;
};
struct WithSub : Leading, SubBase
{
};

struct Output
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    WithSub* m_10;
    unsigned int unk14;
    unsigned int unk18;
    Source* m_1c;
    Source* m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int m_50;
    SubBase* m_54;
    unsigned int unk58;
    unsigned int unk5c;
    Spawned* m_60;
};

struct Local
{
    union
    {
        __m128 m_vector;
        float elements[4];
    };
    unsigned int m_10;
    unsigned int* m_pSub;
    unsigned int m_18;
    unsigned int m_1c;
};

struct Interface
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
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c(void* a, Output* b, unsigned int c);
};

// Fills out from src, builds a Local, constructs a Spawned in spawned if src->m_3c is set, writes fields of src->m_30's block, then calls iface->v5c.
// @fnv 0x00df89b0
void __cdecl FUN_00df89b0(Interface* apInterface, Source* apSource, Output* apOutput, Spawned* spawned)
{
    Local local;

    local.m_pSub = &apSource->m_10;
    local.m_18 = 0x10;
    local.m_1c = 0;
    local.m_10 = 1;
    local.m_vector = apSource->m_v00;

    apOutput->m_20 = apSource;
    apOutput->m_50 = apSource->m_24;
    apOutput->m_24 = apSource->m_30;
    apOutput->m_28 = apSource->m_30;
    apOutput->m_1c = apSource;

    if (apSource->m_20)
        apOutput->m_54 = static_cast<SubBase*>(apOutput->m_10);
    else
        apOutput->m_54 = 0;

    float one = 1.0f;

    if (apSource->m_3c != 0)
    {
        apOutput->m_60 = new (spawned) Spawned(apSource->m_30, apSource->m_34);
        DAT_0126ec04 = ((void (&)(void *, void *, S_00df8990_Obj *))::FUN_00e2b9b0);
    }
    else
        apOutput->m_60 = 0;

    unsigned int* target = (unsigned int*)apSource->m_30;
    *(float*)&target[4] = one;
    target[5] = 0xffffffffu;
    target[8] = 0xffffffffu;
    target[0x14] = 0;
    target[0x10] = 0;

    apInterface->v5c(&local, apOutput, 0);
}

struct hkRotation;
struct hkTransform;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& b);
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);
    __forceinline void _setTransformedInversePos(const hkTransform& t, const hkVector4& b);
};

struct hkRotation
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    const __m128 c1 = _mm_load_ps(&r.m_kColumn1.m_vComponents[0]);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    __m128 c0 = r.m_kColumn0.m_vComponents;
    __m128 c1 = r.m_kColumn1.m_vComponents;
    __m128 c2 = r.m_kColumn2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    tmp = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
    __m128 t2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(t2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4::_setTransformedInversePos(const hkTransform& t, const hkVector4& b)
{
    hkVector4 d;
    d.setSub4(b, t.m_vTranslation);
    _setRotatedInverseDir(t.m_rotation, d);
}

struct WorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
};

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct hkpCdBody;

struct __declspec(align(16)) ShapeRayCastOutput
{
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1C;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4C;
};

struct WorldRayCastOutput : ShapeRayCastOutput
{
    const hkpCdBody* m_pRootCollidable;
    int unk54;
    int unk58;
    int unk5C;
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    hkBool& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

struct hkpRayHitCollector
{
    int unk00;
    float m_fEarlyOutHitFraction;
    int unk08;
    int unk0C;
    int unk10;
    int m_iValueAtOffset14;
};

struct hkpShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual hkBool RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
    virtual void castRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
};

struct hkpRayCollidableFilter
{
    virtual void v00();
    virtual hkBool IsCollisionEnabled(const WorldRayCastInput& input, const hkpCdBody& collidable) const;
};

struct hkpCollisionFilter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkpRayCollidableFilter m_rayCollidableFilter;
};

struct HitList
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
    int m_pRayCursor;
    int m_iElementCount;
    char unk3C;
    char m_earlyOutOnFirstHit;
    char unk3E;
    char unk3F;
};

__forceinline void memCpy16NonEmpty(void*, const void*, int);
struct RayCaster_00df8aa0 : S_00df8d60
{
    S_00df8d60_Bool FUN_00df8aa0(const void* data);
    hkBool m_bHit;
    char unk19;
    char unk1A;
    char unk1B;
    HitList* m_kHits;
    const WorldRayCastInput* m_pRayCastInput;
    WorldRayCastOutput* m_akRayOutputs;
    WorldRayCastOutput* m_pHitBufferEnd;
    int unk2C;
    ShapeRayCastQuery m_kShapeRayInput;
    hkpRayHitCollector* m_kCollector;
    int unk64;
    int unk68;
    int unk6C;
    hkVector4 m_earlyOutHitFractionVec;

    __forceinline S_00df8d60_Bool castBody(const void* data)
    {

        RayCaster_00df8aa0* self = this;
        const hkpCdBody* body = (const hkpCdBody*)data;
        const hkpShape* shape = body->m_pCollisionShape;

        S_00df8d60_Bool result;
        result.m_cBooleanValue = 0;
        if (!shape || !reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(self->filter()->m_rayCollidableFilter.IsCollisionEnabled(*self->m_pRayCastInput, *body)))->FUN_005609f0())
        {
            return result;
        }

        const hkTransform& t = *body->m_pMotionState;
        self->m_kShapeRayInput.m_vFrom._setTransformedInversePos(t, self->m_pRayCastInput->m_vFrom);
        self->m_kShapeRayInput.m_vTo._setTransformedInversePos(t, self->m_pRayCastInput->m_vTo);

        ShapeRayCastOutput output;
        output.m_fHitFraction = self->unk14;
        output.m_iExtraInfo = -1;
        output.m_uiShapeKeys[0] = -1;
        output.m_uiShapeKeyIndex = 0;

        if (!self->m_kCollector)
        {
            hkBool hit = shape->RayCast(self->m_kShapeRayInput, output);
            result.m_cBooleanValue = hit.m_cBooleanValue;
            if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(hit))->FUN_005609f0())
            {
                return result;
            }
            {
                float fraction;
                WorldRayCastOutput* slot = self->getOutputSlot(output.m_fHitFraction, fraction);
                if (slot)
                {
                    output.m_vHitNormal._setRotatedDir(t.m_rotation, output.m_vHitNormal);
                    memCpy16NonEmpty(slot, &output, sizeof(WorldRayCastOutput) / 16);
                    slot->m_pRootCollidable = body;
                    if (self->m_kHits->m_earlyOutOnFirstHit)
                    {
                        output.m_fHitFraction = 0.0f;
                    }
                    self->unk14 = (self->m_kHits->m_pRayCursor == 1) ? output.m_fHitFraction : fraction;
                    self->m_bHit = true;
                    self->m_earlyOutHitFractionVec.m_vComponents = _mm_set_ps1(self->unk14);
                }
            }
            return result;
        }
        shape->castRayWithCollector(self->m_kShapeRayInput, *body, *self->m_kCollector);
        self->m_kHits->m_iElementCount = self->m_kCollector->m_iValueAtOffset14;
        self->m_earlyOutHitFractionVec.m_vComponents = _mm_set_ps1(self->m_kCollector->m_fEarlyOutHitFraction);
        return result;
    }

    const hkpCollisionFilter* filter() const
    {
        return (const hkpCollisionFilter*)unk10;
    }

    __forceinline WorldRayCastOutput* getOutputSlot(float hitFraction, float& oldFraction)
    {
        int size = m_kHits->m_iElementCount;
        WorldRayCastOutput* entry = m_akRayOutputs;
        if (size < m_kHits->m_pRayCursor)
        {
            WorldRayCastOutput* slot = m_pHitBufferEnd;
            oldFraction = 1.0f;
            m_kHits->m_iElementCount = size + 1;
            m_pHitBufferEnd++;
            return slot;
        }
        WorldRayCastOutput* slot = entry;
        entry++;
        if (1 < size)
        {
            size--;
            do
            {
                if (entry->m_fHitFraction > slot->m_fHitFraction)
                {
                    slot = entry;
                }
                entry++;
            } while (--size);
        }
        if (hitFraction < slot->m_fHitFraction)
        {
            oldFraction = slot->m_fHitFraction;
            return slot;
        }
        return 0;
    }
};
// @fnv 0x00df8d60
float S_00df8d60::FUN_00df8d60(const S_00df8d60_Data* data, int unused)
{
    reinterpret_cast<::RayCaster_00df8aa0 *>(this)->FUN_00df8aa0((const char*)data + data->unk5);
    return unk14;
}
// @fnv 0x00df8db0
float FUN_00df8db0_cls::GetResult(ParamBlock* apParam)
{
    int iOut;
    Container* pContainer = (Container*)((char*)this - 8);
    reinterpret_cast<::RayCaster_00df8aa0 *>((pContainer))->FUN_00df8aa0(&iOut);
    return m_fResult;
}
// @fnv 0x00df8d90
void* AdjustOwner::FUN_00df8d90(void* apFirst, int aiSecond)
{
    reinterpret_cast<::RayCaster_00df8aa0 *>((((AdjustedBase*)((char*)this - 4))))->FUN_00df8aa0(apFirst);
    return apFirst;
}
// @fnv 0x00df8dd0
float FUN_00df8dd0_cls::FUN_00df8dd0(FUN_00df8dd0_Param* pParam)
{
    reinterpret_cast<::RayCaster_00df8aa0 *>((((FUN_00df8dd0_helper*)((char*)this - 12))))->FUN_00df8aa0(&pParam);
    return m_f08;
}

__forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* src32 = (const unsigned int*)src;
    unsigned int* dst32 = (unsigned int*)dst;
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        dst32 += 4;
        src32 += 4;
    } while (--numQuads > 0);
}

// Delegates to castBody to test a collision body against the ray and record any hit in the output buffer.
// @fnv 0x00df8aa0
S_00df8d60_Bool RayCaster_00df8aa0::FUN_00df8aa0(const void* apBody)
{
    return castBody(apBody);
}

// Moved from hkpcpuworldraycastjob_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/LunaOwner.h"
#include "fnv/decl/RayCaster_00df8aa0.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00df8000.h"
#include "fnv/symbols_00e2a000.h"
#include "fnv/symbols_00e2c000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010cc000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_simd.h"
namespace fnv_00df8df0 {
#include <windows.h>
#include <xmmintrin.h>

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern const char DAT_010dbb0c[];
struct __declspec(align(16)) Vec
{
    float x, y, z, w;
};
struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, int) throw();
};
struct Pool
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    Allocator* allocator;
};
static __forceinline Pool* pool()
{
    return (Pool*)static_cast<AudioHolder*>(::FUN_00c85750());
}
struct Finalizer
{
};
struct Header
{
    int unk00, unk04, unk08, type;
};
struct Vertex
{
    Vec position, bounds, extra0, extra1;
};
struct PartVectors
{
    Vec position, bounds;
};
struct PartInfo
{
    __forceinline void copyTo(unsigned char& t, int& p) const;
    unsigned char tag, tag1, tag2, tag3;
    unsigned int property;
    int unk08, unk0c;
};
struct FacePart : PartVectors, PartInfo
{
};
struct FaceParts
{
    FacePart parts[4];
};
struct FaceInfo
{
    int count, unkc4;
    int values[4];
    int unkd8, unkdc;
    int outputs[4];
    unsigned int flags, unkf4, unkf8, unkfc;
};
struct Face : FaceParts, FaceInfo
{
};
__forceinline void PartInfo::copyTo(unsigned char& t, int& p) const
{
    t = tag;
    p = property;
}
struct MeshRequest
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    Header* header;
    int unk20;
    Vertex* vertices;
    int vertexCount;
    Face* faces;
    int faceCount;
    void* shapeBuilder;
    void* passA;
    void* passB;
    void* finalPass;
};
struct OutputVertex
{
    Vec position, inverse;
};
struct VertexBuffer
{
    OutputVertex* data;
    int count, capacity;
    OutputVertex* storage;
    __forceinline void Init(int n) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        Pool* p = pool();
        OutputVertex* memory = (OutputVertex*)p->cursor;
        p->cursor = (unsigned char*)memory + ((n * 32 + 127) & ~127);
        data = memory;
        capacity = n | 0x80000000;
        storage = memory;
        Allocator* a = *(Allocator* volatile*)&pool()->allocator;
        int old = capacity & 0x3fffffff;
        if (old < n)
        {
            int next = old * 2;
            if (n >= next)
                next = n;
            ::FUN_00c908c0((::SpawnedObject *)(a), (::SpawnedArray *)(void *)(&data), next, 32);
        }
    }
    __forceinline void Clear() throw()
    {
        OutputVertex* saved = storage;
        if (saved == data)
            count = 0;
        pool()->cursor = (unsigned char*)saved;
        Allocator* a = *(Allocator* volatile*)&pool()->allocator;
        count = 0;
        if ((capacity & 0x80000000u) == 0)
            a->Free(data, (capacity & 0x3fffffff) * 32);
    }
};
union QueryScratch
{
    VertexBuffer vertices;
    Vec range;
};
struct __declspec(align(16)) Field
{
    const void* name0;
    const void* name1;
    const void* name2;
    const void* name3;
    int option;
    float weight;
    unsigned char dirty;
    unsigned char selected;
    short option1a;
    int unused1c;
    Vec vector20, vector30, vector40;
    int property50, property54, property58, property5c, flags60, flags64, flags68, flags6c;
    Vec vector70;
    __forceinline void Init() throw()
    {
        name0 = &(*reinterpret_cast<const char *>(&::DAT_010dbaf8));
        name1 = &(*reinterpret_cast<const char *>(&::DAT_010dbae4));
        name2 = &(*reinterpret_cast<const char *>(&::DAT_010dbad8));
        name3 = &(*reinterpret_cast<const char *>(&::DAT_010dbacc));
        weight = 1.0f;
        property50 = 0;
        property54 = 0;
        flags60 = 0;
        dirty = 0;
    }
    __forceinline void Reset() throw()
    {
        name3 = &(*reinterpret_cast<const char *>(&::DAT_010ccfac));
        name2 = &(*reinterpret_cast<const char *>(&::DAT_010ccfa0));
        *(const void* volatile*)&name1 = &(*reinterpret_cast<const char *>(&::DAT_010ccf8c));
        *(const void* volatile*)&name0 = &(*reinterpret_cast<const char *>(&::DAT_010c3bb8));
    }
};
struct State
{
    const void* type;
    float weight;
    int a, b, c, d, e;
    __forceinline void Init() throw()
    {
        type = &(*reinterpret_cast<const char *>(&::DAT_010dbb04));
        weight = 1.0f;
        a = 0;
        b = 0;
        c = 1;
        d = 0;
        e = 0;
    }
};
union SharedState
{
    Vec unit;
    State state;
};
struct __declspec(align(16)) Converted
{
    Vec position, bounds;
    unsigned char tag;
    unsigned char tag1, tag2, tag3;
    int property, unk28, unk2c;
    int value, kind, output;
    unsigned char flags, flags1;
    short flags2;
};

struct SimdValue
{
    __m128 v;
    __forceinline void sub(const SimdValue& a, const SimdValue& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    __forceinline void eq(const SimdValue& a, const __m128& b)
    {
        v = _mm_cmpeq_ps(a.v, b);
    }
    __forceinline void select(const SimdValue& a, const __m128& b, const SimdValue& c)
    {
        v = _mm_or_ps(_mm_and_ps(c.v, b), _mm_andnot_ps(c.v, a.v));
    }
};
struct TraceEntry
{
    const char* label;
    unsigned int stamp;
    unsigned int info;
};
struct TraceContext
{
    void* unk00;
    TraceEntry* head;
    void* unk08;
    TraceEntry* end;
};
// @fnv 0x00df8df0
void __cdecl FUN_00df8df0(void* result, MeshRequest* request)
{
    {
        TraceContext* t = (TraceContext*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        TraceEntry* p = t->head;
        if (p < t->end)
        {
            p->label = DAT_010dbb0c;
            _ReadWriteBarrier();
            volatile unsigned int tick = (unsigned int)__rdtsc();
            p->stamp = tick;
            t->head = p + 1;
        }
    }
    union CountTemps
    {
        unsigned char* destination;
        int count;
        volatile unsigned int stamp;
    } iteration;
    union
    {
        int queryType;
        FaceInfo* queryFaces;
    };
    union
    {
        int queryRemaining;
        void* queryFinal;
    };
    union
    {
        Vertex* querySource;
        int* queryOutputs;
    };
    QueryScratch scratch;
    SharedState shared;
    State finalState;
    Field field;
    Field fields[4];
    if (request->shapeBuilder == 0)
    {
        queryType = request->header->type;
        querySource = request->vertices;
        int count = request->vertexCount;
        VertexBuffer& vertices = scratch.vertices;
        vertices.Init(count);
        vertices.count = count;
        fields[0].Init();
        fields[1].Init();
        fields[2].Init();
        fields[3].Init();
        Pool* p = pool();
        iteration.destination = p->cursor;
        p->cursor = iteration.destination + 128;
        if (count > 0)
        {
            Vertex* v = querySource;
            unsigned int offset = 0;
            queryRemaining = count;
            do
            {
                OutputVertex* out = (OutputVertex*)((char*)vertices.data + offset);
                *(__m128*)&out->position = *(__m128*)&v->position;
                SimdValue width;
                width.sub(*(SimdValue*)&v->bounds, *(SimdValue*)&v->position);
                SimdValue eq;
                eq.eq(width, (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
                SimdValue selected;
                selected.select(width, ::DAT_010c7170, eq);
                __m128 value = selected.v;
                __m128 high = _mm_unpackhi_ps(value, ::DAT_010c7170);
                value = _mm_shuffle_ps(value, high, 0xc4);
                __m128 reciprocal = _mm_rcp_ps(value);
                __m128 product = _mm_mul_ps(reciprocal, value);
                product = _mm_mul_ps(product, reciprocal);
                reciprocal = _mm_sub_ps(_mm_add_ps(reciprocal, reciprocal), product);
                *(__m128*)&out->inverse = _mm_or_ps(_mm_andnot_ps(eq.v, reciprocal), _mm_and_ps(eq.v, ::DAT_010cd670));
                offset += 32;
                ++v;
            } while (--queryRemaining != 0);
        }
        *(__m128*)&shared.unit = _mm_set1_ps(::DAT_01012068);
        Field* __restrict at = fields;
        queryRemaining = 4;
        do
        {
            *(__m128*)&at->vector70 = *(__m128*)&shared.unit;
            at->option = queryType;
            ++at;
        } while (queryRemaining-- != 1);
        ::fnv_00e2c8a0::FUN_00e2c8a0((::fnv_00e2c8a0::Owner *)(request->passA), (int)(vertices.data), (int)(querySource), queryType, (int)(fields), (int)(iteration.destination), count);
        ::FUN_00e2cc30((::SplitInput *)(request->passB), (int)(vertices.data), (int)(querySource), queryType, (int)(fields), (int)(iteration.destination), count);
        pool()->cursor = iteration.destination;
        Field* end = fields + 4;
        int remaining = 3;
        do
        {
            --end;
            end->Reset();
        } while (--remaining >= 0);
        vertices.Clear();
        queryFinal = request->finalPass;
        Vertex* source = request->vertices;
        finalState.Init();
        int remainingVertices = request->vertexCount;
        if (remainingVertices > 0)
        {
            iteration.count = remainingVertices;
            do
            {
                ::FUN_00e2abf0(queryFinal, (::S_00df8990_Obj *)(source), queryType, (::CastOutput *)(void *)(&finalState));
                ++source;
            } while (--iteration.count != 0);
        }
        int remainingFaces = request->faceCount;
        Face* face = request->faces;
        if (remainingFaces > 0)
        {
            iteration.count = remainingFaces;
            do
            {
                *(__m128*)&scratch.range = *(__m128*)&shared.unit;
                ::FUN_00e2b070((const ::Input *)(request->passA), (::BundleCommand *)(face), (void *)(queryType), (*(::RayVector *)(&scratch.range)), (void *)(0), (void *)(0), (void *)(0), (void *)(0), (int *)(0));
                ::FUN_00e2b510((::Owner *)(request->passB), (::RayBatch *)(face), queryType, (*(__m128 *)(&scratch.range)));
                ::FUN_00e2acf0(queryFinal, (::InputStruct *)(face), (void *)(queryType), (float *)(void *)(&scratch.range));
                ++face;
            } while (--iteration.count != 0);
        }
    }
    else
    {
        field.Init();
        field.option = request->header->type;
        Vertex* vertex = request->vertices;
        shared.state.Init();
        iteration.count = 0;
        if (request->vertexCount > 0)
            do
            {
                field.weight = 1.0f;
                field.dirty = 0;
                ::FUN_00df89b0((::Interface *)(request->shapeBuilder), (::Source *)(vertex), (::Output *)(void *)(&field), (::Spawned *)(void *)(&shared.state));
                ++vertex;
                ++iteration.count;
            } while (iteration.count < request->vertexCount);
        int bundleCount = request->faceCount;
        Face* bundles = request->faces;
        __assume(bundles != 0);
        if (bundleCount > 0)
        {
            queryFaces = bundles;
            queryRemaining = bundleCount;
            do
            {
                iteration.count = 0;
                if (queryFaces->count > 0)
                {
                    Face* inputs = &static_cast<Face&>(*queryFaces);
                    __assume(inputs != 0);

                    do
                    {

                        Converted converted;
                        Converted& c = converted;
                        __m128 position = *(__m128*)&(inputs->parts[iteration.count]).position;
                        (inputs->parts[iteration.count]).copyTo(c.tag, c.property);
                        c.value = queryFaces->values[iteration.count];
                        c.flags = (unsigned char)queryFaces->flags;
                        *(__m128*)&c.position = position;
                        __m128 bounds = *(__m128*)&(inputs->parts[iteration.count]).bounds;
                        c.flags1 = 0;
                        *(__m128*)&c.bounds = bounds;
                        c.kind = 1;
                        c.output = 0;
                        field.weight = 1.0f;
                        field.dirty = 0;
                        ::FUN_00df89b0((::Interface *)(request->shapeBuilder), (::Source *)(void *)(&c), (::Output *)(void *)(&field), (::Spawned *)(void *)(&shared.state));
                        queryFaces->outputs[iteration.count] = c.output;
                        ++iteration.count;
                    } while (iteration.count < queryFaces->count);
                }
                queryFaces = reinterpret_cast<FaceInfo*>(reinterpret_cast<Face*>(queryFaces) + 1);
            } while (--queryRemaining != 0);
        }
    }
    {
        TraceContext* t = (TraceContext*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        TraceEntry* p = t->head;
        if (p < t->end)
        {
            p->label = ::DAT_010c41f8;
            _ReadWriteBarrier();
            iteration.stamp = (unsigned int)__rdtsc();
            p->stamp = iteration.stamp;
            t->head = p + 1;
        }
    }
    reinterpret_cast<::LunaOwner *>((((Finalizer*)result)))->ProcessCallback((intptr_t)(request), (intptr_t)(request), 0);
}
}  // namespace fnv_00df8df0
#include "generated/data/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob_gs_ehsc_nogs_noehsc_variant.inc"
