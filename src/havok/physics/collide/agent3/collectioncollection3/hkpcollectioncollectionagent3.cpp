
// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "havok/hkMemoryRouter.h"
#include "havok/hkpCollisionDispatcher.h"
#include <new>
#include <xmmintrin.h>
#include "fnv/decl/FUN_00cfbd60_cls.h"
#include "fnv/symbols_00cbe000.h"
#include "fnv/symbols_00cf8000.h"
#include "fnv/symbols_00d34000.h"
#include "fnv/symbols_00d35000.h"
#include "fnv/symbols_00d36000.h"
#include "fnv/symbols_00d97000.h"
#include "fnv/symbols_00da3000.h"
#include "fnv/symbols_00da4000.h"
#include "fnv/symbols_00da6000.h"
#include "fnv/symbols_01267000.h"
struct FUN_00d36270_s {
    void* m_vt;
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
    void* m_g;
    void* m_h;
    void* m_i;
    void* m_iUnknownValue;
    void* m_k;
    unsigned char m_flag;
};

// Initializes the object's vtable and function pointers, clears several pointer fields to zero, and sets m_flag to 1.
// @fnv 0x00d36270
void FUN_00d36270(FUN_00d36270_s* self)
{
    self->m_vt = &((void (&)(void *, void *, void *))::InitAndReturnTail);
    self->m_k = &((void (&)(void *, void *, void *))::hkpCollectionCollectionAgent3::FUN_00d35770);
    self->m_iUnknownValue = 0;
    self->m_kPointB = 0;
    self->m_iThirdValue = 0;
    self->m_iFourthElementInteger = 0;
    self->m_usTrailingValue = 0;
    self->m_f = &((void (&)(void *, void *, void *))::FUN_00d34db0);
    self->m_g = &((void (&)(void *, void *, void *))::FUN_00d34d30);
    self->m_h = &((void (&)(void *, void *, void *))::ForwardCall);
    self->m_i = &((void (&)(void *, void *, void *))::FUN_00d34d80);
    self->m_kPointA = &((void (&)(void *, void *, void *))::FUN_00da6dc0);
    self->m_flag = 1;
}


// Calls FUN_00da35f0 with b, c, d and e, ignoring a.
// @fnv 0x00d34d80
void __cdecl FUN_00d34d80(void* apUnused, void* b, float afValue1, float afValue2, void* e)
{
    ::FUN_00da35f0((::Da35Stream ***)(b), afValue1, afValue2, (void **)(e));
}

struct FUN_00cf5830_cls {
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int unk10;
    unsigned short unk14;
    unsigned short m_16;

    int FUN_00cf5830();
};

// @fnv 0x00cf5830
int FUN_00cf5830_cls::FUN_00cf5830() {
    return m_0c - m_16;
}

struct __declspec(align(16)) D36270Data {
    void* vtable;
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
    void* g;
    void* h;
    void* i;
    void* j;
    void* k;
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
};
extern unsigned char DAT_01268ad5;
struct D362Script : public hkpCollisionDispatcher {
};
// @fnv 0x00d362c0
void FUN_00d362c0(D362Script* script) {
    D36270Data data;
    data.flag0 = 0; data.flag1 = 0; data.flag2 = 0;
    data.f = 0; data.g = 0; data.h = 0; data.i = 0; data.j = 0;
    ::FUN_00d36270((::FUN_00d36270_s *)(::D36270Data *)(&data));
    reinterpret_cast<::FUN_00cfbd60_cls *>((script))->AddEntry((::SrcRec *)(::D36270Data *)(&data), 8, 8);
    data.flag1 = 1; data.flag2 = 1;
    reinterpret_cast<::FUN_00cfbd60_cls *>((script))->AddEntry((::SrcRec *)(::D36270Data *)(&data), 7, 8);
    reinterpret_cast<::FUN_00cfbd60_cls *>((script))->AddEntry((::SrcRec *)(::D36270Data *)(&data), 8, 7);
    reinterpret_cast<::FUN_00cfbd60_cls *>((script))->AddEntry((::SrcRec *)(::D36270Data *)(&data), 7, 7);
    script->m_1e22 = 1;
    DAT_01268ad5 = 1;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern "C" const char str_010ceca8[];

struct S00d34d30_Obj
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(const char* s);
    virtual void m7();
};

// @fnv 0x00d34d30
void __cdecl FUN_00d34d30(void* a, void* b, void* c, void* d)
{
    S00d34d30_Obj* obj = (S00d34d30_Obj*)d;
    obj->m6(str_010ceca8);
    ::FUN_00d97250((::Hdr *)(b), (char **)(c), (::Logger *)(d));
    obj->m7();
}

struct Obj {
    virtual void* m00();
    virtual void* m04();
    virtual void* m08();
    virtual void* m0c();
    virtual void* m10();
};

struct Local {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    void* f4;
    void* f5;
    void* f6;
    void* f7;
};


// Fills a Local struct with a3 through a7 and the m10() results of the objects at a3 and a4, then calls FUN_00da4900 with a2 and the struct.
// @fnv 0x00d34db0
void __cdecl FUN_00d34db0(void* apUnused, void* a2, void* apFirstObj, void* apSecondObj, void* a5, void* a6, void* a7)
{
    Local s;
    void* pFirstObj = *(void**)apFirstObj;
    void* pSecondObj = *(void**)apSecondObj;

    s.f0 = apFirstObj;
    s.f1 = apSecondObj;
    s.f4 = a5;
    s.f5 = a6;
    s.f6 = a7;
    s.f2 = ((Obj*)pFirstObj)->m10();
    s.f3 = ((Obj*)pSecondObj)->m10();

    ::FUN_00da4900(a2, &s);
}

#include "fnv/symbols_simd.h"


  // AABB quantization clip max

typedef unsigned int hkpShapeKey;

struct hkFloat4
{
    float x;
    float y;
    float z;
    float w;
};

struct hkSimdRealq
{
    __m128 m_vValue;
};

struct hkVector4q
{
    __m128 m_vComponents;


    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAdd4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const hkVector4q& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }

    __forceinline void setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(reinterpret_cast<const float*>(&::DAT_010ec7f0)), t.m_vComponents), a.m_vComponents), _mm_mul_ps(t.m_vComponents, b.m_vComponents));
    }

    __forceinline void setAddMul4(const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& r)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents), a.m_vComponents);
    }

    __forceinline hkSimdRealq getSimdAt3() const
    {
        hkSimdRealq r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }

    __forceinline hkSimdRealq length3() const
    {
        const __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
        hkSimdRealq r;
        r.m_vValue = _mm_sqrt_ss(s);
        return r;
    }
};

union hkVector4u
{
    hkFloat4 m_f;
    hkVector4q m_v;
};

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

__forceinline void SetTransformedPoint(hkVector4q& out, const hkTransformq& t, const hkVector4q& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(b0, t.m_kColumn0.m_vComponents);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(b1, t.m_kColumn1.m_vComponents);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(b2, t.m_kColumn2.m_vComponents);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}

struct hkMotionStateq
{
    hkTransformq m_kMotionTransform;
    hkVector4q m_vCenterOfMass0;
    hkVector4q m_vCenterOfMass1;
    hkVector4q m_qRotation0;
    hkVector4q m_qRotation1;
    hkFloat4 m_vCenterOfMassLocal;
    hkVector4q m_kDeltaAngle;
};

struct SweptTransformSamples
{
    const hkMotionStateq* m_kMotionState;
    int unk04;
    int unk08;
    int unk0C;
    hkTransformq m_kTransforms[4];
    int m_numQsTransforms;
    int unk114;
    int unk118;
    int unk11C;
    hkTransformq m_kMotionTransform;
    hkTransformq m_shapeToMotion;
};


struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct hkAabbUint32
{
    unsigned int m_kMinimumCorner[3];
    union {
        struct { unsigned char m_ucExpansionMin[3]; unsigned char m_ucExpansionShift; };
        hkpShapeKey m_uiCollisionShapeKey;
    };
    union {
        unsigned int m_kMaximumCorner[4];
        struct { unsigned int m_maxX; unsigned int m_maxY; unsigned int m_maxZ;
                 unsigned char m_ucExpansionMax[3]; unsigned char m_expansionMaxXYZ; };
    };
};
typedef hkAabbUint32 hkAabbUint32Key;

struct hkpShapeBufferq
{
    int m_data[128];
};

class hkpShapeq
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, hkAabbq& out) const;
};

class hkpShapeContainerq
{
public:
    virtual void v00();
    virtual void v04();
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const;
    virtual void v10();
    virtual const hkpShapeq* GetShapeForKey(hkpShapeKey key, hkpShapeBufferq& buffer) const;
};

struct hkpCdBodyq
{
    const hkpShapeq* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyq* m_parent;

    __forceinline const hkpCdBodyq* getRootCollidable() const
    {
        const hkpCdBodyq* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return body;
    }
};

struct hkpCollisionQualityInfoq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iQualityInfoValue10;
};

struct hkpProcessCollisionInputq
{
    int unk00;
    int unk04;
    float m_fScalar;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4q m_kAabbMin;
    hkVector4q m_kAabbMaximum;
    hkVector4q m_kAabbScale;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkpCollisionQualityInfoq* m_pCollisionQualityInfo;
};


union hkVec4F
{
    __m128 m_vComponents;
    float m_f[4];
    __forceinline float operator()(int i) const { return m_f[i]; }
};

static __forceinline void convertToUint32WithClip(const hkVector4q& a, const hkVector4q& b, const hkVector4q& scale,
                                                  const __m128& maxVal, const __m128& minVal, unsigned int* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}


struct BoundingVolumeData : hkAabbUint32
{
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    hkAabbUint32* m_pChildShapeAabbs;
    hkpShapeKey* m_pChildShapeKeys;

    __forceinline bool isValid() const { return m_kMinimumCorner[0] <= m_kMaximumCorner[0]; }
};

struct hkpCollidableq : hkpCdBodyq
{
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BoundingVolumeData m_kBoundingVolumeData;
};


struct hkAabbUint32Less
{
    unsigned char m_unused;
};


static __forceinline void expandAabbUint32(hkAabbUint32Key* out, const hkAabbUint32* in)
{
    int shift = in->m_ucExpansionShift;
    unsigned int x = in->m_kMinimumCorner[0] - (in->m_ucExpansionMin[0] << shift);
    unsigned int y = in->m_kMinimumCorner[1] - (in->m_ucExpansionMin[1] << shift);
    unsigned int z = in->m_kMinimumCorner[2] - (in->m_ucExpansionMin[2] << shift);
    out->m_kMinimumCorner[0] = x;
    out->m_kMinimumCorner[1] = y;
    out->m_kMinimumCorner[2] = z;
    unsigned int maxX = in->m_kMaximumCorner[0] + (in->m_ucExpansionMax[0] << shift);
    unsigned int maxY = in->m_kMaximumCorner[1] + (in->m_ucExpansionMax[1] << shift);
    unsigned int maxZ = in->m_kMaximumCorner[2] + (in->m_ucExpansionMax[2] << shift);
    out->m_kMaximumCorner[0] = maxX;
    out->m_kMaximumCorner[1] = maxY;
    out->m_kMaximumCorner[2] = maxZ;
}

static __forceinline void copyCachedAabbs(const BoundingVolumeData& bvd, int useContinuous, hkAabbUint32Key* aabbsOut, int& numAabbs)
{
    const hkAabbUint32* childAabbs = bvd.m_pChildShapeAabbs;
            const hkpShapeKey* keys = bvd.m_pChildShapeKeys;
            hkAabbUint32Key* out = aabbsOut;
            for (int i = 0; i < bvd.m_uiNumChildShapeAabbs; i++)
            {
                if (useContinuous)
                {
                    expandAabbUint32(out, childAabbs);
                }
                else
                {
                    FUN_00cf8690(out, childAabbs);
                }
                numAabbs++;
                out->m_uiCollisionShapeKey = *keys++;
                childAabbs++;
                out++;
            }
}


typedef unsigned int hkUint32;

struct hkStringQ {
    static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
        hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
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
};

struct __declspec(align(16)) SortEntry {
    hkUint32 m_key;
    hkUint32 unk04;
    hkUint32 unk08;
    hkUint32 unk0C;
    hkUint32 unk10;
    hkUint32 unk14;
    hkUint32 unk18;
    hkUint32 unk1C;
    SortEntry() {}
    SortEntry(const SortEntry& o) { hkStringQ::memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
    void operator=(const SortEntry& o) { hkStringQ::memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
};

struct SortEntryLess {
    bool operator()(const SortEntry& a, const SortEntry& b) const { return a.m_key < b.m_key; }
};

// @fnv 0x00d351c0
int __cdecl FUN_00d351c0(const hkpCdBodyq* body, int useCache, const hkpShapeContainerq* container,
                         const hkpProcessCollisionInputq* input, hkAabbUint32Key* aabbsOut)
{
    SweptTransformSamples samples;
    hkpShapeBufferq shapeBuffer;

    const hkpCollisionQualityInfoq* quality = input->m_pCollisionQualityInfo;
    int useContinuous = quality->m_iQualityInfoValue10;
    int numAabbs = 0;

    if (!body->m_parent)
    {
        const hkpCdBodyq* rootBody = body;
        const hkpCollidableq* collidable = (const hkpCollidableq*)rootBody;
        const BoundingVolumeData& bvd = collidable->m_kBoundingVolumeData;
        const hkAabbUint32* childAabbs = bvd.m_pChildShapeAabbs;
        if (childAabbs && bvd.isValid())
        {
            if (!bvd.m_uiNumChildShapeAabbs)
            {
                return 0;
            }
            copyCachedAabbs(bvd, useContinuous, aabbsOut, numAabbs);
            if (!useContinuous)
            {
                goto done;
            }
            goto sortAabbs;
        }

        if (bvd.isValid() && useCache)
        {
            if (useContinuous)
            {
                expandAabbUint32(aabbsOut, &bvd);
                aabbsOut->m_uiCollisionShapeKey = 0;
                numAabbs = 1;
                goto done;
            }
            hkAabbUint32Key* volatile& rootOut = aabbsOut;
            FUN_00cf8690(rootOut, &bvd);
            volatile hkAabbUint32Key* output = rootOut;
            volatile int& resultCount = numAabbs;
            resultCount = 1;
            output->m_uiCollisionShapeKey = 0;
            return resultCount;
        }
    }

    if (useContinuous)
    {
        const hkpCdBodyq* root = body->getRootCollidable();
        const hkMotionStateq* motion = (const hkMotionStateq*)root->m_pMotionState;
        FUN_00cbec90(motion, &samples);
    }

    {
        hkpShapeKey key = container->GetFirstKey();
        if (key != hkpShapeKey(-1))
        {
        hkAabbUint32Key* out = aabbsOut;
        do
        {
            const hkpShapeq* child = container->GetShapeForKey(key, shapeBuffer);

            hkAabbq aabb;
            hkVector4q& boundMinimum = aabb.m_kMinimumCorner;
            hkVector4q& boundMaximum = aabb.m_kMaximumCorner;
            const void* motion = body->m_pMotionState;
            float tolerance = input->m_fScalar;
            child->getAabb(motion, tolerance, aabb);

            if (useContinuous)
            {
                hkVector4q minimum;
                minimum.m_vComponents = _mm_load_ps(reinterpret_cast<float*>(&boundMinimum.m_vComponents));
                hkVector4q half;
                half.m_vComponents = _mm_set_ps1(0.5f);

                hkVector4q halfExtents;
                halfExtents.setSub4(boundMaximum, minimum);
                halfExtents.mul4(half);

                hkVector4q center;
                center.setInterpolate4(boundMaximum, minimum, half);

                hkVector4q centerMotion;
                SetTransformedPoint(centerMotion, samples.m_shapeToMotion, center);
                hkVector4q centerWorld;
                SetTransformedPoint(centerWorld, samples.m_kMotionTransform, centerMotion);

                hkVector4q sweptMin;
                sweptMin.setMin4(center, centerWorld);
                hkVector4q sweptMax;
                sweptMax.setMax4(center, centerWorld);

                const hkMotionStateq* motionState = samples.m_kMotionState;
                hkVector4u comLocal;
                comLocal.m_f = motionState->m_vCenterOfMassLocal;

                for (int k = 0; k < samples.m_numQsTransforms; k++)
                {
                    hkVector4q relCenter;
                    relCenter.setSub4(centerMotion, comLocal.m_v);
                    hkVector4q p;
                    p.setAddMul4(comLocal.m_v, relCenter, samples.m_kTransforms[k].m_vTranslation.getSimdAt3());
                    hkVector4q pWorld;
                    SetTransformedPoint(pWorld, samples.m_kTransforms[k], p);
                    sweptMin.setMin4(sweptMin, pWorld);
                    sweptMax.setMax4(sweptMax, pWorld);
                }

                hkSimdRealq len = halfExtents.length3();
                hkVector4q radius;
                radius.m_vComponents = _mm_shuffle_ps(len.m_vValue, len.m_vValue, 0);
                hkVector4q expand;
                expand.setAddMul4(halfExtents, radius, motionState->m_kDeltaAngle.getSimdAt3());
                radius.setMin4(radius, expand);

                sweptMin.setSub4(sweptMin, radius);
                sweptMax.setAdd4(sweptMax, radius);
                boundMinimum.setMin4(sweptMin, sweptMin);
                boundMaximum.setMax4(sweptMax, sweptMax);
            }

            hkAabbUint32Key* cur = out++;
            __m128 maxVal = DAT_011b6d70;
            numAabbs++;
            const hkVector4q& scale = input->m_kAabbScale;
            const hkVector4q& offsetMin = input->m_kAabbMin;
            const hkVector4q& offsetMax = input->m_kAabbMaximum;
            hkVec4F convertedMin;
            convertedMin.m_vComponents = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(offsetMin.m_vComponents, boundMinimum.m_vComponents), scale.m_vComponents), maxVal), (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
            cur->m_kMinimumCorner[0] = fnv_FloatToInt(convertedMin(0));
            cur->m_kMinimumCorner[1] = fnv_FloatToInt(convertedMin(1));
            cur->m_kMinimumCorner[2] = fnv_FloatToInt(convertedMin(2));
            cur->m_kMinimumCorner[3] = fnv_FloatToInt(convertedMin(3));

            hkVec4F convertedMax;
            convertedMax.m_vComponents = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(boundMaximum.m_vComponents, offsetMax.m_vComponents), scale.m_vComponents), maxVal), (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
            cur->m_kMaximumCorner[0] = fnv_FloatToInt(convertedMax(0));
            cur->m_kMaximumCorner[1] = fnv_FloatToInt(convertedMax(1));
            cur->m_kMaximumCorner[2] = fnv_FloatToInt(convertedMax(2));
            cur->m_kMaximumCorner[3] = fnv_FloatToInt(convertedMax(3));


            cur->m_uiCollisionShapeKey = key;
            key = container->GetNextShapeKey(key);
        } while (key != hkpShapeKey(-1));
        }
    }

sortAabbs:
    hkAabbUint32Less comparator = {0};
    if (numAabbs > 1)
    {
        ::FUN_00d36360((::SortEntry *)(aabbsOut), 0, numAabbs - 1, (*(::SortEntryLess *)&(const ::hkAabbUint32Less &)(comparator)));
    }
done:
    return numAabbs;
}

template <typename T>
__forceinline void hkSwap(T& x, T& y)
{
    T t(y);
    y = x;
    x = t;
}

// Sorts pArr[d..h] in place with quicksort, using the middle element as pivot and the cmpLess comparator.
// @fnv 0x00d36360
void __cdecl FUN_00d36360(SortEntry* pArr, int aiLow, int aiHigh, SortEntryLess cmpLess)
{
    int i, j;
    SortEntry strPivot;
begin:
    j = aiHigh;
    i = aiLow;
    strPivot = pArr[(aiLow + aiHigh) >> 1];
    do
    {
        while (cmpLess(pArr[i], strPivot)) { i++; }
        while (cmpLess(strPivot, pArr[j])) { j--; }
        if (j >= i)
        {
            if (j != i)
            {
                hkSwap(pArr[i], pArr[j]);
            }
            j--;
            i++;
        }
    } while (i <= j);
    if (aiLow < j) FUN_00d36360(pArr, aiLow, j, cmpLess);
    if (i < aiHigh) { aiLow = i; goto begin; }
}

struct hkpAgent3ProcessInputq
{
    const hkpCdBodyq* m_pBodyA;
    const hkpCdBodyq* m_pBodyB;
    void* m_pContactManager;
    const hkpProcessCollisionInputq* m_pRayCastInput;
};
static __forceinline void interpolateCenter(hkVector4q& out, const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& t)
{
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, _mm_shuffle_ps(t.m_vValue,t.m_vValue,0)), a.m_vComponents), _mm_mul_ps(b.m_vComponents, _mm_shuffle_ps(t.m_vValue,t.m_vValue,0)));
}
static __forceinline void convertLowerCurrent(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                  const __m128& maxVal, const __m128& minVal, hkAabbUint32Key* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(offset.m_vComponents, in.m_vComponents);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out->m_kMinimumCorner[0] = fnv_FloatToInt(x(0));
    out->m_kMinimumCorner[1] = fnv_FloatToInt(x(1));
    out->m_kMinimumCorner[2] = fnv_FloatToInt(x(2));
    out->m_ucExpansionShift = fnv_FloatToInt(x(3));
}
static __forceinline void convertUpperCurrent(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                  const __m128& maxVal, const __m128& minVal, unsigned int* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(offset.m_vComponents, _mm_load_ps(reinterpret_cast<const float*>(&in.m_vComponents)));
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}

static __forceinline void quantizeAabb(const hkAabbq& aabb, const hkpProcessCollisionInputq* in, hkAabbUint32Key* out) {
 __m128 maxVal=DAT_011b6d70;
 convertLowerCurrent(aabb.m_kMinimumCorner,in->m_kAabbMin,in->m_kAabbScale,maxVal,(*reinterpret_cast<__m128 *>(&::DAT_01267e30)),out);
 convertUpperCurrent(aabb.m_kMaximumCorner,in->m_kAabbMaximum,in->m_kAabbScale,maxVal,(*reinterpret_cast<__m128 *>(&::DAT_01267e30)),out->m_kMaximumCorner);
}

// @fnv 0x00d34e10
void __cdecl FUN_00d34e10(const hkpAgent3ProcessInputq& input, const hkpShapeContainerq* container, const hkpCdBodyq* body,
                          const hkpShapeKey* keys, int numKeys, hkAabbUint32Key* __restrict aabbsOut)
{
    SweptTransformSamples samples;
    hkpShapeBufferq shapeBuffer;

    int useContinuous = input.m_pRayCastInput->m_pCollisionQualityInfo->m_iQualityInfoValue10;
    if (useContinuous)
    {
        FUN_00cbec90((const hkMotionStateq*)body->getRootCollidable()->m_pMotionState, &samples);
    }

    for (int i = 0; i < numKeys; i++)
    {
        hkpShapeKey key = keys[i];
        const hkpShapeq* child = container->GetShapeForKey(key, shapeBuffer);

        hkAabbq aabb;
        child->getAabb(body->m_pMotionState, input.m_pRayCastInput->m_fScalar, aabb);

        if (useContinuous)
        {
            hkSimdRealq half;
            half.m_vValue = _mm_set_ss(0.5f);

            hkVector4q halfExtents;
            halfExtents.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
            halfExtents.m_vComponents = _mm_mul_ps(halfExtents.m_vComponents, _mm_shuffle_ps(half.m_vValue,half.m_vValue,0));

            hkVector4q center;
            interpolateCenter(center, aabb.m_kMaximumCorner, aabb.m_kMinimumCorner, half);

            hkVector4q centerMotion;
            SetTransformedPoint(centerMotion, samples.m_shapeToMotion, center);
            hkVector4q centerWorld;
            SetTransformedPoint(centerWorld, samples.m_kMotionTransform, centerMotion);

            hkVector4q sweptMin;
            sweptMin.setMin4(center, centerWorld);
            hkVector4q sweptMax;
            sweptMax.setMax4(center, centerWorld);

            const hkMotionStateq* motionState = samples.m_kMotionState;
            hkVector4u comLocal;
            comLocal.m_f = motionState->m_vCenterOfMassLocal;

            for (int k = 0; k < samples.m_numQsTransforms; k++)
            {
                hkVector4q relCenter;
                relCenter.setSub4(centerMotion, comLocal.m_v);
                hkVector4q p;
                p.setAddMul4(comLocal.m_v, relCenter, samples.m_kTransforms[k].m_vTranslation.getSimdAt3());
                hkVector4q pWorld;
                SetTransformedPoint(pWorld, samples.m_kTransforms[k], p);
                sweptMin.setMin4(sweptMin, pWorld);
                sweptMax.setMax4(sweptMax, pWorld);
            }

            hkSimdRealq len = halfExtents.length3();
            hkVector4q radius;
            radius.m_vComponents = _mm_shuffle_ps(len.m_vValue, len.m_vValue, 0);
            hkVector4q expand;
            expand.setAddMul4(halfExtents, radius, motionState->m_kDeltaAngle.getSimdAt3());
            radius.setMin4(radius, expand);

            sweptMin.setSub4(sweptMin, radius);
            sweptMax.setAdd4(sweptMax, radius);
            aabb.m_kMinimumCorner.setMin4(sweptMin, sweptMin);
            aabb.m_kMaximumCorner.setMax4(sweptMax, sweptMax);
        }

        const hkpProcessCollisionInputq* in = input.m_pRayCastInput;
        hkAabbUint32Key* out = &aabbsOut[i];
        quantizeAabb(aabb,in,out);
        out->m_uiCollisionShapeKey = key;
    }
}

// Moved from hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHs-c- /Gy (unit lists /MT /O2 /GS- /EHs-c- /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00cb21e0_shell.h"
#include "fnv/symbols_00d2d000.h"
#include "fnv/symbols_00da5000.h"
#include "fnv/symbols_00db0000.h"
#include "fnv/symbols_01268000.h"
extern "C" void __cdecl FUN_00d35770(void*, void*, void*);
int __cdecl FUN_00d351c0(const hkpCdBodyq* body, int useCache, const hkpShapeContainerq* container, const hkpProcessCollisionInputq* input, hkAabbUint32Key* aabbsOut);
void __cdecl FUN_00d34e10(const hkpAgent3ProcessInputq& input, const hkpShapeContainerq* container, const hkpCdBodyq* body, const hkpShapeKey* keys, int numKeys, hkAabbUint32Key* __restrict aabbsOut);

typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32_S;
typedef uintptr_t hkUlong;
typedef intptr_t hkLong;
typedef size_t hk_size_t;
typedef hkReal hkTime;
__forceinline hkLong __cdecl hkGetByteOffset(const void*base,const void*pntr)
{
return hkLong(pntr)-hkLong(base);
}
template<typename TYPE>
__forceinline TYPE*__cdecl hkAddByteOffset(TYPE*base,hkLong offset)
{
return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset);
}
class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
operator ENUM()const
{
return static_cast<ENUM>(m_kStorage);
}
void operator=(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline TYPE operator->()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
template<typename T>struct TypeSizeConstant{enum{val=sizeof(T)};};
template<typename TYPE>
__forceinline TYPE*__cdecl hkAllocateStack(int n,const char*what=0)
{
return static_cast<TYPE*>(hkMemoryRouter::getInstance().allocateStack((((n*TypeSizeConstant<TYPE>::val)+((128)-1))&(~((128)-1)))));
}
template<typename TYPE>
__forceinline void __cdecl hkShrinkAllocatedStack(TYPE*ptr,int n)
{
hkMemoryRouter::getInstance().shrinkAllocatedStack(ptr,(((n*TypeSizeConstant<TYPE>::val)+((128)-1))&(~((128)-1))));
}
template<typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE*ptr)
{
hkMemoryRouter::getInstance().deallocateStack(ptr);
}
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline virtual ~hkBaseObject(){}
public:
__forceinline hkBaseObject(){}
};
class hkStatisticsCollector;
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};
template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;
struct RouterHeapAllocatorProvider
{
hkMemoryAllocator&get(const void*){return hkMemoryRouter::getInstance().heap();}
};
template<typename T>
class HavokElementArray
{
public:
typedef HavokElementArray<T>ThisType;
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline int GetLogicalSize()const;
protected:
__forceinline HavokElementArray<T>&copyFromArray(hkMemoryAllocator&,const HavokElementArray<T>&src,hkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
T*m_data;
int m_iElementCount;
int m_iCapacityState;
public:
HavokElementArray(FinishingFlag f){}
};
template<typename T,typename Allocator=RouterHeapAllocatorProvider>
class hkArray:public HavokElementArray<T>
{
public:
typedef Allocator AllocatorType;protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);};
template<typename T>
__forceinline int HavokElementArray<T>::GetLogicalSize()const
{
return m_iElementCount;
}

typedef __m128 hkQuadReal;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
namespace MathUtilities
{inline int __cdecl hkToIntFast(hkReal r){
int i;
i = fnv_FloatToInt(r);return i;
}
}
namespace MathUtilities {
template<typename T>
inline T __cdecl max2(T x,T y)
{
return x>y ? x:y;
}
}
class hkTransform;
struct hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void SetAllComponents(hkSimdRealParameter x);
__forceinline void add4(const hkVector4&a);
__forceinline void setAdd4(const hkVector4&a,const hkVector4&b);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void mul4(const hkVector4&a);
__forceinline void mul4(hkSimdRealParameter a);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void setInterpolate4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter t);
__forceinline void setNeg3(const hkVector4&v);
__forceinline void setMin4(const hkVector4&a,const hkVector4&b);
__forceinline void setMax4(const hkVector4&a,const hkVector4&b);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline VectorComponentValue length3()const;
__forceinline hkReal&operator()(int i);
__forceinline VectorComponentValue getSimdAt(int i)const;
__forceinline hkQuadReal&getQuad();
__forceinline const hkQuadReal&getQuad()const;
__forceinline static const hkVector4&__cdecl getZero();
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class hkQuaternion
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_vec;
protected:
void setFlippedRotation(const hkVector4&from);};
class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline hkVector4&getColumn(int i);
__forceinline const hkVector4&getColumn(int i)const;
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};
class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(){}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};
class hkSweptTransform
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline void _approxTransformAt(hkTime time,hkTransform&transformOut)const;
public:
hkVector4 m_vCenterOfMass0;
hkVector4 m_vCenterOfMass1;
hkQuaternion m_qRotation0;
hkQuaternion m_qRotation1;
hkVector4 m_vCenterOfMassLocal;};
inline hkQuadReal&hkVector4::getQuad()
{
return m_vComponents;
}
inline const hkQuadReal&hkVector4::getQuad()const
{
return m_vComponents;
}
inline void hkVector4::SetAllComponents(hkSimdRealParameter a)
{
m_vComponents=_mm_shuffle_ps(a.getQuad(),a.getQuad(),(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
inline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::mul4(const hkVector4&v)
{
m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setNeg3(const hkVector4&v)
{
static __declspec(align(16))const hkUint32_S negateMask[4]={0x80000000,0x80000000,0x80000000,0x00000000};
m_vComponents=_mm_xor_ps(v.m_vComponents,*(const hkQuadReal*)&negateMask);
}
inline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
static __declspec(align(16))const float cw[4]={1.0f,1.0f,1.0f,1.0f};
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(*(const hkQuadReal*)&cw,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}
inline void hkVector4::setMin4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_min_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::setMax4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_max_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline VectorComponentValue hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4::length3()const
{
return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline VectorComponentValue hkVector4::getSimdAt(int i)const
{
switch(i)
{
case 0:
return m_vComponents;
case 1:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
case 2:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
case 3:
default:
return _mm_shuffle_ps(m_vComponents,m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
inline const hkVector4&__cdecl hkVector4::getZero()
{
return (*reinterpret_cast<::hkVector4 *>(&::DAT_01267e30));
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkTransform::hkTransform(const hkTransform&t)
{
const hkVector4 r0=t.m_rotation.getColumn(0);
const hkVector4 r1=t.m_rotation.getColumn(1);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;}
class MemoryUtils
{
public:
enum ReplaceType
{
REPLACE_ONE,
REPLACE_ALL
};
template<int size>
static __forceinline void __cdecl memCpy16(void*dst,const void*src);
private:
static void copyAndReplace(char*dest,const char*orig,int origLen,const MemoryUtils&from,const MemoryUtils&to,const hkArray<int>&indices);};
class StringCursor
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
return*(*reinterpret_cast<::hkThreadLocalData< ::StringCursor *> *>(&::DAT_0126835c)).getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
public:
struct Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandFilterEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::CommandFilterEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
float m_uiFilterValue;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32_S m_uiStartTicks;
hkUint32_S m_uiEndTicks;
__forceinline void setTime();
};
struct TimedNameRecord:public StringCursor::CommandTimingEntry
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::TimedNameRecord));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pFirst;
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32_S ticks;
ticks = static_cast<unsigned int>(__rdtsc());
m_uiStartTicks=ticks;
}
class hkMotionState
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkSweptTransform&getSweptTransform()const;
protected:
hkTransform m_kMotionTransform;
class hkSweptTransform m_kSweptTransform;
public:
hkVector4 m_kDeltaAngle;
hkReal m_fObjectRadius;};
const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_kSweptTransform;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_kMinimumCorner;
hkVector4 m_kMaximumCorner;};
__declspec(align(16))struct hkAabbUint32_S
{
inline void operator=(const hkAabbUint32_S&other);
__declspec(align(16))hkUint32_S m_kMinimumCorner[3];
hkUint8 m_ucExpansionMin[3];
hkUint8 m_ucExpansionShift;
hkUint32_S m_kMaximumCorner[3];
hkUint8 m_ucExpansionMax[3];};
typedef hkUint16 hkContactPointId;
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
enum hkpBufferSize
{
HK_SHAPE_BUFFER_SIZE=512
};
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
class hkpShapeContainer;
typedef hkUint32_S hkpShapeKey_S;
class ShapeKeyCombination
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
hkpShapeKey_S m_uiShapeKeyA;
hkpShapeKey_S m_uiShapeKeyB;};
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline CollisionShapeType getType()const;
__forceinline void getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const;
virtual hkReal getMaximumProjection(const hkVector4&direction)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpShape::PhysicsShape));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<CollisionShapeType,hkUint32_S>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};
__declspec(align(16))class AlignedHkpShape:public hkpShape{
AlignedHkpShape();
};
CollisionShapeType hkpShape::getType()const
{
return static_cast<const AlignedHkpShape*>(this)->m_type;
}
void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}friend class hkpCollidable;__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
__forceinline const hkpCollidable*getRootCollidable()const;
__forceinline const hkpCdBody*getParent()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
__forceinline const hkMotionState*GetMotionState()const;
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey_S m_uiCollisionShapeKey;
const void*m_pMotionState;
const hkpCdBody*m_parent;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkMotionState*hkpCdBody::GetMotionState()const
{
return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
const hkpCollidable*hkpCdBody::getRootCollidable()const
{
const hkpCdBody*body=this;
while(body->m_parent)
{
body=body->m_parent;
}
return reinterpret_cast<const hkpCollidable*>(body);
}
const hkpCdBody*hkpCdBody::getParent()const
{
return m_parent;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
struct hkpCollisionDispatcher;
class hkpConstraintOwner;
struct CollisionAgentContext;
class hkpCollisionAgent;
struct FourByteState
{};
typedef void hkpAgentData;
struct AgentProcessingInput
{ValueWrapper<const hkpCdBody*>m_pBodyA;
ValueWrapper<const hkpCdBody*>m_pBodyB;
ValueWrapper<const hkpCdBody*>m_pAdditionalCollidableBody;
ValueWrapper<const GskAgentInput*>m_pRayCastInput;
ValueWrapper<hkpContactMgr*>m_pContactManager;
hkTransform m_kTransform;};
struct AgentSubtypeMarker:public AgentProcessingInput
{
ValueWrapper<hkReal>m_fSubtypeValue;
hkVector4 m_vSubtypePosition;};
namespace hkAgent3
{
typedef hkpAgentData*(__cdecl*CreateFunc)(const AgentProcessingInput&input,FourByteState*entry,hkpAgentData*agentData);
typedef void(__cdecl*DestroyFunc)(FourByteState*entry,hkpAgentData*agentData,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner,hkpCollisionDispatcher*dispatcher);
typedef hkpAgentData*(__cdecl*ProcessFunc)(const AgentSubtypeMarker&input,FourByteState*entry,hkpAgentData*agentData,hkVector4*separatingNormalOut,WorldOperationEntry&result);
typedef void(__cdecl*SepNormalFunc)(const AgentProcessingInput&input,FourByteState*entry,hkpAgentData*agentData,hkVector4&separatingNormalOut);
typedef hkpAgentData*(__cdecl*CleanupFunc)(FourByteState*entry,hkpAgentData*agentData,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
typedef void(__cdecl*RemovePointFunc)(FourByteState*entry,hkpAgentData*agentData,hkContactPointId idToRemove);
typedef void(__cdecl*CommitPotentialFunc)(FourByteState*entry,hkpAgentData*agentData,hkContactPointId iContactPointId);
typedef void(__cdecl*CreateZombieFunc)(FourByteState*entry,hkpAgentData*agentData,hkContactPointId idTobecomeZombie);
typedef void(__cdecl*UpdateFilterFunc)(FourByteState*entry,hkpAgentData*agentData,const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
typedef void(__cdecl*CalcStatisticsFunc)(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input,hkStatisticsCollector*collector);
typedef void(__cdecl*InvalidateTimFunc)(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input);
typedef void(__cdecl*WarpTimeFunc)(FourByteState*entry,hkpAgentData*agentData,hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);}
struct CollisionQualityInfo
{
__declspec(align(16))hkReal m_fMinimumCollisionSeparation;
hkReal m_fMinimumExtraSeparation;
hkReal m_fMaximumExtraSeparation;
hkReal m_fTimeOfImpactSeparation;
ValueWrapper<hkBool32>m_iQualityInfoValue10;};
class hkpCollisionFilter;
class hkpConvexListFilter;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;
ValueWrapper<const hkpCollisionFilter*>m_iFilter;
ValueWrapper<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
class hkpContactMgrFactory;
class hkpBroadPhaseHandle
{
public:
static const struct ClassMemberDescriptor Members[];
hkUint32_S m_iOwnerObjectOffset;public:
hkpBroadPhaseHandle(class FinishingFlag flag){}
};
class hkpTypedBroadPhaseHandle:public hkpBroadPhaseHandle
{
public:
static const struct ClassMemberDescriptor Members[];protected:
enum{OFFSET_INVALID=127};
public:
hkInt8 m_ucObjectQualityType;
hkUint32_S m_uiCollisionFilterData;};
class hkpCollidable:public hkpCdBody
{
public:
static const struct ClassMemberDescriptor Members[];
public:
__forceinline hkUint32_S GetFilterInfoForKey()const;
public:
struct BoundingVolumeData_S
{
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpCollidable::BoundingVolumeData_S));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
BoundingVolumeData_S();
BoundingVolumeData_S(class FinishingFlag flag);
__forceinline bool hasAllocations()const;
void deallocate();
void allocate(int numChildShapes);
__forceinline void invalidate(){m_kMinimumCorner[0]=1;m_kMaximumCorner[0]=0;}
__forceinline bool isValid()const{return m_kMinimumCorner[0]<=m_kMaximumCorner[0];}
public:
hkUint32_S m_kMinimumCorner[3];
hkUint8 m_ucExpansionMin[3];
hkUint8 m_ucExpansionShift;
hkUint32_S m_kMaximumCorner[3];
hkUint8 m_ucExpansionMax[3];
hkUint8 m_ucUnknownByte;
hkUint16 m_uiNumChildShapeAabbs;
hkUint16 m_uiCapacityChildShapeAabbs;
hkAabbUint32_S*m_pChildShapeAabbs;
hkpShapeKey_S*m_pChildShapeKeys;
};
protected:
hkInt8 m_iOwnerOffset;
public:
hkUint8 m_uiForceCollideOntoPpu;
class hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
public:
struct BoundingVolumeData_S m_kBoundingVolumeData;};
__forceinline bool hkpCollidable::BoundingVolumeData_S::hasAllocations()const
{
;
return 0 !=m_pChildShapeAabbs;
}
class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable ValueWrapper<CollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
namespace hkpCollectionCollectionAgent3
{
hkpAgentData*__cdecl FUN_00d35770(const AgentSubtypeMarker&input,FourByteState*entry,hkpAgentData*agentData,hkVector4*separatingNormal,WorldOperationEntry&result);
void __cdecl RegisterAgentFunctions(hkpCollisionDispatcher*dispatcher);
void __cdecl InitAgentFunc(hkpCollisionDispatcher::Agent3Funcs&f);
void __cdecl CleanupAgent(FourByteState*entry,hkpAgentData*agentData,const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
void __cdecl AddStat(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input,hkStatisticsCollector*collector);
void __cdecl RemovePoint(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input);
void __cdecl WarpTime(FourByteState*entry,hkpAgentData*agentData,hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
extern bool g_bCollisionAgentFlag;
}
class hkpShapeContainer
{
public:
static const struct ClassMemberDescriptor Members[];
enum ReferencePolicy
{
REFERENCE_POLICY_IGNORE,
REFERENCE_POLICY_INCREMENT
};
virtual ~hkpShapeContainer(){}
virtual int GetNumChildShapes()const;
virtual hkpShapeKey_S GetFirstKey()const=0;
virtual hkpShapeKey_S GetNextShapeKey(hkpShapeKey_S oldKey)const=0;
virtual hkUint32_S GetFilterInfoForKey(hkpShapeKey_S key)const;
virtual const hkpShape*GetShapeForKey(hkpShapeKey_S key,hkpShapeBuffer&buffer)const=0;};
class hkpShapeCollection:public hkpShape,public hkpShapeContainer
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkBool m_bDisableWelding;};
namespace hkBvTreeAgent3
{
hkpAgentData*__cdecl FUN_00d35770(const AgentSubtypeMarker&input,FourByteState*entry,hkpAgentData*agentData,hkVector4*separatingNormal,WorldOperationEntry&result);
void __cdecl RegisterAgentFunctions(hkpCollisionDispatcher*dispatcher);
void __cdecl InitAgentFunc(hkpCollisionDispatcher::Agent3Funcs&f);
void __cdecl CleanupAgent(FourByteState*entry,hkpAgentData*agentData,const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
void __cdecl AddStat(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input,hkStatisticsCollector*collector);
void __cdecl RemovePoint(FourByteState*entry,hkpAgentData*agentData,const CollisionAgentContext&input);
void __cdecl WarpTime(FourByteState*entry,hkpAgentData*agentData,hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
const hkpShapeContainer*__cdecl GetContainerFromBody(const hkpCdBody*body,hkpShapeBuffer&buffer);
}
struct AgentSectorPointerArray;
struct AgentSectorPointerArray
{};
enum{HK_MAX_NUM_HITS_PER_AABB_QUERY=4096};
struct ShapeKeyPair
{
hkUint32_S m_uiFirstShapeKey;
hkUint32_S m_uiSecondShapeKey;
};
class AabbCollisionPairGenerator
{
public:
struct KeyedAabb:public hkAabbUint32_S
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(AabbCollisionPairGenerator::KeyedAabb));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32_S&GetIteratorKey()
{
hkUint32_S*minP=m_kMinimumCorner;
return minP[3];
}
const hkUint32_S&GetIteratorKey()const
{
const hkUint32_S*minP=m_kMinimumCorner;
return minP[3];
}
__forceinline bool operator<(const AabbCollisionPairGenerator::KeyedAabb&aabb1)const{return this->m_kMinimumCorner[0]<aabb1.m_kMinimumCorner[0];}
void operator=(const KeyedAabb&other){MemoryUtils::memCpy16<sizeof(KeyedAabb)>(this,&other);}
void setEndMarker()
{
m_kMinimumCorner[0]=hkUint32_S(-1);
}
void set(const hkAabb&aabb,int key);
static __forceinline hkUint32_S yzDisjoint(const AabbCollisionPairGenerator::KeyedAabb&aabb,const AabbCollisionPairGenerator::KeyedAabb&other)
{
hkUint32_S yab=aabb.m_kMaximumCorner[1]-other.m_kMinimumCorner[1];
hkUint32_S yba=other.m_kMaximumCorner[1]-aabb.m_kMinimumCorner[1];
hkUint32_S zab=aabb.m_kMaximumCorner[2]-other.m_kMinimumCorner[2];
hkUint32_S zba=other.m_kMaximumCorner[2]-aabb.m_kMinimumCorner[2];
hkUint32_S combined=(yab | yba)|(zab | zba);
return combined&0x80000000;
}
};
};
class AabbUtil
{
public:
static void __cdecl ComputeAabb(const float*vertexArray,int numVertices,int striding,hkAabb&aabbOut);
public:
struct OffsetAabbSweepInput
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(AabbUtil::OffsetAabbSweepInput));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ValueWrapper<const hkMotionState*>m_kMotionState;
hkTransform m_kTransforms[4];
ValueWrapper<int>m_numQsTransforms;
hkTransform m_kFirstAdditionalTransform;
hkTransform m_kSecondAdditionalTransform;
};
static void __cdecl sweepOffsetAabb(const OffsetAabbSweepInput&input,const hkAabb&aabbIn,hkAabb&aabbOut);};
__forceinline void __cdecl AabbUtil::sweepOffsetAabb(const AabbUtil::OffsetAabbSweepInput&input,const hkAabb&aabbIn,hkAabb&aabbOut)
{
VectorComponentValue half(0.5f);
hkVector4 aabbHalfSize;aabbHalfSize.setSub4(aabbIn.m_kMaximumCorner,aabbIn.m_kMinimumCorner);aabbHalfSize.mul4(half);
hkVector4 aabbCenter;aabbCenter.setInterpolate4(aabbIn.m_kMaximumCorner,aabbIn.m_kMinimumCorner,half);
hkVector4 arm;arm._setTransformedPos(input.m_kSecondAdditionalTransform,aabbCenter);
hkVector4 min=aabbCenter;
hkVector4 max=aabbCenter;
{
hkVector4 p;p._setTransformedPos(input.m_kFirstAdditionalTransform,arm);
min.setMin4(min,p);
max.setMax4(max,p);
}
const hkVector4 centerOfMassLocal=input.m_kMotionState->getSweptTransform().m_vCenterOfMassLocal;
for(int i=0;i<input.m_numQsTransforms;i++)
{
hkVector4 extendedArm;
extendedArm.setSub4(arm,centerOfMassLocal);
extendedArm.mul4(input.m_kTransforms[i].getTranslation().getSimdAt(3));
extendedArm.add4(centerOfMassLocal);
hkVector4 p;p._setTransformedPos(input.m_kTransforms[i],extendedArm);
min.setMin4(min,p);
max.setMax4(max,p);
}
{
VectorComponentValue r=aabbHalfSize.length3();
hkVector4 radius;radius.SetAllComponents(r);
aabbHalfSize.addMul4(input.m_kMotionState->m_kDeltaAngle.getSimdAt(3),radius);
aabbHalfSize.setMin4(radius,aabbHalfSize);
}
aabbOut.m_kMinimumCorner.setSub4(min,aabbHalfSize);
aabbOut.m_kMaximumCorner.setAdd4(max,aabbHalfSize);
aabbOut.m_kMinimumCorner.setMin4(aabbIn.m_kMinimumCorner,aabbOut.m_kMinimumCorner);
aabbOut.m_kMaximumCorner.setMax4(aabbIn.m_kMaximumCorner,aabbOut.m_kMaximumCorner);}
class hkpListShape:public hkpShapeCollection
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkpListShape(const hkpShape*const*shapeArray,int numShapes,hkpShapeContainer::ReferencePolicy ref=hkpShapeContainer::REFERENCE_POLICY_INCREMENT);inline virtual int GetNumChildShapes()const{return m_kChildInfoList.GetLogicalSize()-m_usNumDisabledChildren;}
public:
friend class hkpListAgent;
hkArray<struct ChildInfo>m_kChildInfoList;
hkUint16 m_flags;
hkUint16 m_usNumDisabledChildren;
enum{MAX_DISABLED_CHILDREN=256};
hkUint32_S m_uiChildEnabledFlags[8];
protected:
void InitializeChildShapes(const hkpShape*const*shapeArray,int numShapes,const hkUint32_S*filterInfoArray=0,hkpShapeContainer::ReferencePolicy ref=hkpShapeContainer::REFERENCE_POLICY_INCREMENT);};
namespace AlgorithmUtilities
{template<typename T>
class less
{
public:
__forceinline hkBool32 operator()(const T&a,const T&b)
{
return(a<b);
}
};
template<typename T>
__forceinline void __cdecl quickSort(T*pArr,int iSize)
{
quickSort(pArr,iSize,less<T>());
}
template<typename T,typename L>
void __cdecl QuickSortSubrange(T*pArr,int d,int h,L cmpLess);}
namespace AlgorithmUtilities {
template<typename T,typename L>
void __cdecl quickSort(T*pArr,int iSize,L cmpLess)
{
if(iSize>1)
{
int low=0;
int high=iSize-1;
::FUN_00d36360((::SortEntry *)(pArr),low,high,(*(::SortEntryLess *)&(const ::AlgorithmUtilities::less< ::AabbCollisionPairGenerator::KeyedAabb> &)(cmpLess)));
}
}
}
namespace hkVector4Util_S
{
__forceinline void __cdecl convertToUint32WithClip(const hkVector4&in,const hkVector4&offset,const hkVector4&scale,const hkVector4&min,const hkVector4&max,hkUint32_S*out);
__forceinline void __cdecl convertAabbToUint32(const hkAabb&aabb,const hkVector4&offsetLow,const hkVector4&offsetHigh,const hkVector4&scale,hkAabbUint32_S&aabbOut);
__forceinline void __cdecl uncompressExpandedAabbUint32(const hkAabbUint32_S&unexpandedAabbInt,hkAabbUint32_S&expandedAabbOut);
}
inline void __cdecl hkVector4Util_S::convertToUint32WithClip(const hkVector4&in,const hkVector4&offset,const hkVector4&scale,const hkVector4&min,const hkVector4&max,hkUint32_S*out)
{
hkVector4 x;
x.setAdd4(in,offset);
x.mul4(scale);
x.setMin4(x,max);
x.setMax4(x,min);
out[0]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(0)));
out[1]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(1)));
out[2]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(2)));
out[3]=static_cast<hkUint32_S>(MathUtilities::hkToIntFast(x(3)));}
inline void __cdecl hkVector4Util_S::convertAabbToUint32(const hkAabb&aabb,const hkVector4&offsetLow,const hkVector4&offsetHigh,const hkVector4&scale,hkAabbUint32_S&aabbOut)
{
hkVector4 maxVal;maxVal.getQuad()=::DAT_011b6d70;
hkVector4Util_S::convertToUint32WithClip(aabb.m_kMinimumCorner,offsetLow,scale,hkVector4::getZero(),maxVal,aabbOut.m_kMinimumCorner);
hkVector4Util_S::convertToUint32WithClip(aabb.m_kMaximumCorner,offsetHigh,scale,hkVector4::getZero(),maxVal,aabbOut.m_kMaximumCorner);}
inline void __cdecl hkVector4Util_S::uncompressExpandedAabbUint32(const hkAabbUint32_S&unexpandedAabbInt,hkAabbUint32_S&expandedAabbOut)
{
int shift=unexpandedAabbInt.m_ucExpansionShift;
hkUint32_S mix=unexpandedAabbInt.m_kMinimumCorner[0]-(unexpandedAabbInt.m_ucExpansionMin[0]<<shift);
hkUint32_S miy=unexpandedAabbInt.m_kMinimumCorner[1]-(unexpandedAabbInt.m_ucExpansionMin[1]<<shift);
expandedAabbOut.m_kMinimumCorner[0]=mix;
expandedAabbOut.m_kMinimumCorner[1]=miy;
hkUint32_S maxx=unexpandedAabbInt.m_kMaximumCorner[0]+(unexpandedAabbInt.m_ucExpansionMax[0]<<shift);
expandedAabbOut.m_kMaximumCorner[0]=maxx;}
__forceinline void hkCollectionBvTreeAgent3_calcAabbs(const AgentSubtypeMarker&input,const hkpShapeContainer*container,const hkpCdBody*cdBody,const hkpShapeKey_S*hitList,int numHits,AabbCollisionPairGenerator::KeyedAabb*__restrict aabbsOut)
{
AabbUtil::OffsetAabbSweepInput sweepInput;
const int useContinuousPhysics=input.m_pRayCastInput->m_pCollisionQualityInfo->m_iQualityInfoValue10.val();
if(useContinuousPhysics)::FUN_00cbec90((const ::hkMotionStateq *)(const ::hkMotionState *)(cdBody->getRootCollidable()->GetMotionState()),(::SweptTransformSamples *)&(sweepInput));
for(int idx=0;idx<numHits;idx++)
{
hkpShapeKey_S key=hitList[idx];
hkpShapeBuffer shapeBuffer;
const hkpShape*child=container->GetShapeForKey(key,shapeBuffer);
hkAabb aabb;
child->getAabb(cdBody->getTransform(),input.m_pRayCastInput->m_fScalar,aabb);
if(useContinuousPhysics)AabbUtil::sweepOffsetAabb(sweepInput,aabb,aabb);
hkVector4Util_S::convertAabbToUint32(aabb,input.m_pRayCastInput->m_aiValues.m_kAabbMin,input.m_pRayCastInput->m_aiValues.m_kAabbMaximum,input.m_pRayCastInput->m_aiValues.m_kAabbScale,aabbsOut[idx]);
aabbsOut[idx].GetIteratorKey()=key;
}
}
static int GetChildAabbs(const hkpCdBody*cdBody,const hkpCdBody*overrideCdBody,const hkpShapeContainer*collection,const GskAgentInput&input,AabbCollisionPairGenerator::KeyedAabb*aabbs,int aabbsCapacity,int aabbBufferSize_usedOnSpu)
{
const int useContinuousPhysics=input.m_pCollisionQualityInfo->m_iQualityInfoValue10;
int numChildAabbs=0;
const hkpCollidable::BoundingVolumeData_S*bvData=0;
if(!cdBody->getParent()&&(bvData=&static_cast<const hkpCollidable*>(cdBody)->m_kBoundingVolumeData)->m_pChildShapeAabbs&&bvData->isValid())
{
if(!bvData->m_uiNumChildShapeAabbs)
{
return 0;
}
hkAabbUint32_S*childShapeAabbs=bvData->m_pChildShapeAabbs;
hkpShapeKey_S*childShapeKeys=bvData->m_pChildShapeKeys;
for(int i=0;i<bvData->m_uiNumChildShapeAabbs;i++)
{
AabbCollisionPairGenerator::KeyedAabb*aabbInt=&aabbs[i];
if(useContinuousPhysics){hkVector4Util_S::uncompressExpandedAabbUint32(*childShapeAabbs,*aabbInt);}
else{static_cast<hkAabbUint32_S&>(*aabbInt)=*childShapeAabbs;}
aabbInt->GetIteratorKey()=*childShapeKeys;
childShapeAabbs++;
childShapeKeys++;
numChildAabbs++;
}
if(!useContinuousPhysics)
{
goto DONT_SORT;
}
}
else if(bvData&&bvData->isValid()&&overrideCdBody)
{
;
AabbCollisionPairGenerator::KeyedAabb*aabbInt=aabbs;
;
const hkAabbUint32_S*bvDataAabb=reinterpret_cast<const hkAabbUint32_S*>(bvData);
if(useContinuousPhysics)
{
hkVector4Util_S::uncompressExpandedAabbUint32(*bvDataAabb,*aabbInt);
}
else
{
static_cast<hkAabbUint32_S&>(*aabbInt)=*bvDataAabb;
}
aabbInt->GetIteratorKey()=0;
numChildAabbs++;
goto DONT_SORT;
}
else
{
AabbUtil::OffsetAabbSweepInput sweepInput;
if(useContinuousPhysics)
{
::FUN_00cbec90((const ::hkMotionStateq *)(const ::hkMotionState *)(cdBody->getRootCollidable()->GetMotionState()),(::SweptTransformSamples *)&(sweepInput));
}
hkpShapeBuffer buffer;
for(hkpShapeKey_S key=collection->GetFirstKey();key !=0xffffffff;key=collection->GetNextShapeKey(key))
{
const hkpShape*child=collection->GetShapeForKey(key,buffer);
hkAabb aabb;
child->getAabb(cdBody->getTransform(),input.m_fScalar,aabb);
if(useContinuousPhysics)
{
AabbUtil::sweepOffsetAabb(sweepInput,aabb,aabb);
}
AabbCollisionPairGenerator::KeyedAabb*aabbInt=&aabbs[numChildAabbs++];
hkVector4Util_S::convertAabbToUint32(aabb,input.m_aiValues.m_kAabbMin,input.m_aiValues.m_kAabbMaximum,input.m_aiValues.m_kAabbScale,*aabbInt);
aabbInt->GetIteratorKey()=key;
}
}
DONT_SORT:
;}
// @fnv 0x00d35770
hkpAgentData*__cdecl hkpCollectionCollectionAgent3::FUN_00d35770(const AgentSubtypeMarker&input,FourByteState*entry,hkpAgentData*agentData,hkVector4*separatingNormal,WorldOperationEntry&output)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::TimedNameRecord*h=reinterpret_cast<StringCursor::TimedNameRecord*>(mStream.GetStreamEnd());h->m_pCommandName="L" "t" "CollColl3";h->m_pFirst="S" "t" "Init";h->setTime();mStream.setEnd((char*)(h+1));}};
AgentSectorPointerArray*agent1nTrack=reinterpret_cast<AgentSectorPointerArray*>(agentData);
const bool shapeAisCollection=!input.m_pRayCastInput->m_pCollisionDispatcher->hasAlternateType(input.m_pBodyA->getShape()->getType(),HK_SHAPE_BV_TREE);
const bool shapeBisCollection=!input.m_pRayCastInput->m_pCollisionDispatcher->hasAlternateType(input.m_pBodyB->getShape()->getType(),HK_SHAPE_BV_TREE);
bool treatAasCollection;
if(shapeAisCollection | shapeBisCollection)
{
treatAasCollection=shapeAisCollection;
if((shapeAisCollection&&input.m_pBodyA->getShape()->getType()!=HK_SHAPE_LIST)||(shapeBisCollection&&input.m_pBodyB->getShape()->getType()!=HK_SHAPE_LIST))
{
;
}
}
else
{
const bool bodyAHasCachedChildShapeAabbs=!input.m_pBodyA->m_parent&&static_cast<const hkpCollidable*>(input.m_pBodyA.val())->m_kBoundingVolumeData.m_pChildShapeAabbs;
const bool bodyBHasCachedChildShapeAabbs=!input.m_pBodyB->m_parent&&static_cast<const hkpCollidable*>(input.m_pBodyB.val())->m_kBoundingVolumeData.m_pChildShapeAabbs;
if(bodyAHasCachedChildShapeAabbs==bodyBHasCachedChildShapeAabbs)
{
hkpShapeBuffer tmpBufferA;const hkpShapeCollection*childCollectionA=((const ::hkpShapeCollection *)(::GetSpawnedObjectPointer((void **)(input.m_pBodyA.val()))));
hkpShapeBuffer tmpBufferB;const hkpShapeCollection*childCollectionB=((const ::hkpShapeCollection *)(::GetSpawnedObjectPointer((void **)(input.m_pBodyB.val()))));
const bool shapeAhasList=childCollectionA ? childCollectionA->getType()==HK_SHAPE_LIST:false;
const bool shapeBhasList=childCollectionB ? childCollectionB->getType()==HK_SHAPE_LIST:false;
if(shapeAhasList&&shapeBhasList)
{
treatAasCollection=static_cast<const hkpListShape*>(childCollectionA)->hkpListShape::GetNumChildShapes()<=static_cast<const hkpListShape*>(childCollectionB)->hkpListShape::GetNumChildShapes();
}
else if(shapeAhasList | shapeBhasList)
{
treatAasCollection=shapeAhasList;
}
else
{
treatAasCollection=input.m_pBodyA->GetMotionState()->m_fObjectRadius<=input.m_pBodyB->GetMotionState()->m_fObjectRadius;
;
}
}
else
{
treatAasCollection=bodyAHasCachedChildShapeAabbs;
}
}
hkpShapeBuffer bufferA;const hkpShapeContainer*shapeContainerA=hkBvTreeAgent3::GetContainerFromBody(input.m_pBodyA,bufferA);
hkpShapeBuffer bufferB;const hkpShapeContainer*shapeContainerB=hkBvTreeAgent3::GetContainerFromBody(input.m_pBodyB,bufferB);
ShapeKeyCombination*shapeKeyPairs=hkAllocateStack<ShapeKeyCombination>(HK_MAX_NUM_HITS_PER_AABB_QUERY,"ShapeKeyPairs");
int numShapeKeyPairs;
{
int numHitsFirst=0;
int numHitsSecond=0;
AabbCollisionPairGenerator::KeyedAabb*aabbsFirst;
AabbCollisionPairGenerator::KeyedAabb*aabbsSecond;
const hkpCdBody*firstCdBody;
{
const hkpCdBody*secondBody;
const hkpShapeContainer*secondContainer;
if(!(shapeAisCollection&shapeBisCollection))
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="S" "t" "queryTree";h->setTime();mStream.setEnd((char*)(h+1));}};
const hkpShapeContainer*firstContainer;
hkpShapeKey_S hitList[HK_MAX_NUM_HITS_PER_AABB_QUERY];
if(treatAasCollection)
{
;
hkTransform bTa;reinterpret_cast<::FUN_00cb21e0_shell *>(&(bTa))->FUN_00cb21e0((const ::Matrix44 *)&(input.m_kTransform));
numHitsFirst=::FUN_00d2d4f0(*input.m_pBodyA,*input.m_pBodyB,bTa,input.m_vSubtypePosition,*input.m_pRayCastInput,0,hitList,HK_MAX_NUM_HITS_PER_AABB_QUERY);
firstCdBody=input.m_pBodyB;
firstContainer=shapeContainerB;
secondBody=input.m_pBodyA;
secondContainer=shapeContainerA;
}
else
{
;
hkVector4 negLinearTimInfo;negLinearTimInfo.setNeg3(input.m_vSubtypePosition);
numHitsFirst=::FUN_00d2d4f0(*input.m_pBodyB,*input.m_pBodyA,input.m_kTransform,negLinearTimInfo,*input.m_pRayCastInput,0,hitList,HK_MAX_NUM_HITS_PER_AABB_QUERY);
firstCdBody=input.m_pBodyA;
firstContainer=shapeContainerA;
secondBody=input.m_pBodyB;
secondContainer=shapeContainerB;
}
aabbsFirst=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(numHitsFirst+4,"aabbsFirst");
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="S" "t" "ConvertHitlist";h->setTime();mStream.setEnd((char*)(h+1));}};
hkCollectionBvTreeAgent3_calcAabbs(input,firstContainer,firstCdBody,hitList,numHitsFirst,aabbsFirst);
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="S" "t" "SortHitList";h->setTime();mStream.setEnd((char*)(h+1));}};
AlgorithmUtilities::quickSort(aabbsFirst,numHitsFirst);
}
else
{
numHitsFirst=shapeContainerA->GetNumChildShapes();
{
const hkpCollidable*coll=static_cast<const hkpCollidable*>(input.m_pBodyA.val());
if(!coll->getParent()&&coll->m_kBoundingVolumeData.hasAllocations()&&coll->m_kBoundingVolumeData.isValid())
{
numHitsFirst=MathUtilities::max2(numHitsFirst,int(coll->m_kBoundingVolumeData.m_uiNumChildShapeAabbs));
}
}
int numHitsForAllocate=numHitsFirst;
const int numAabbsAllocated=numHitsForAllocate+4;
aabbsFirst=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(numAabbsAllocated,"aabbsFirst");
numHitsFirst=GetChildAabbs(input.m_pBodyA,input.m_pAdditionalCollidableBody,shapeContainerA,*input.m_pRayCastInput.val(),aabbsFirst,numHitsFirst,numAabbsAllocated*sizeof(AabbCollisionPairGenerator::KeyedAabb));
firstCdBody=input.m_pBodyA;
secondBody=input.m_pBodyB;
secondContainer=shapeContainerB;
}
if(numHitsFirst)
{
numHitsSecond=secondContainer->GetNumChildShapes();
{
const hkpCollidable*coll=static_cast<const hkpCollidable*>(secondBody);
if(!coll->getParent()&&coll->m_kBoundingVolumeData.hasAllocations()&&coll->m_kBoundingVolumeData.isValid())
{
numHitsSecond=MathUtilities::max2(numHitsSecond,int(coll->m_kBoundingVolumeData.m_uiNumChildShapeAabbs));
}
}
int numHitsForAllocate=numHitsSecond;
const int numAabbsAllocated=numHitsForAllocate+4;
aabbsSecond=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(numAabbsAllocated,"aabbsSecond");
;
numHitsSecond=GetChildAabbs(secondBody,0,secondContainer,*input.m_pRayCastInput.val(),aabbsSecond,numHitsSecond,numAabbsAllocated*sizeof(AabbCollisionPairGenerator::KeyedAabb));
}
else
{
numHitsSecond=0;
aabbsSecond=hkAllocateStack<AabbCollisionPairGenerator::KeyedAabb>(4,"aabbsSecond");
}
for(int i=numHitsFirst;i<numHitsFirst+4;i++){aabbsFirst[i].m_kMinimumCorner[0]=hkUint32_S(-1);}
for(int i=numHitsSecond;i<numHitsSecond+4;i++){aabbsSecond[i].m_kMinimumCorner[0]=hkUint32_S(-1);}
}
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="S" "t" "1-Axis";h->setTime();mStream.setEnd((char*)(h+1));}};
ValueWrapper<int>numPairsSkipped(0);
if(firstCdBody==input.m_pBodyA)
{
numShapeKeyPairs=::CollideSweepBounds((const ::SweepBounds *)(aabbsFirst),numHitsFirst,(const ::SweepBounds *)(aabbsSecond),numHitsSecond,reinterpret_cast<::SweepPair *>(shapeKeyPairs),HK_MAX_NUM_HITS_PER_AABB_QUERY-1,(int &)(numPairsSkipped));
}
else
{
numShapeKeyPairs=::CollideSweepBounds((const ::SweepBounds *)(aabbsSecond),numHitsSecond,(const ::SweepBounds *)(aabbsFirst),numHitsFirst,reinterpret_cast<::SweepPair *>(shapeKeyPairs),HK_MAX_NUM_HITS_PER_AABB_QUERY-1,(int &)(numPairsSkipped));
}
hkDeallocateStack(aabbsSecond);
hkDeallocateStack(aabbsFirst);
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="S" "t" "SortHits";h->setTime();mStream.setEnd((char*)(h+1));}};
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandFilterEntry*h=reinterpret_cast<StringCursor::CommandFilterEntry*>(mStream.GetStreamEnd());h->m_pCommandName="M" "i" "NumHits";h->m_uiFilterValue=float(numShapeKeyPairs);mStream.setEnd((char*)(h+1));}};
AlgorithmUtilities::quickSort(shapeKeyPairs,numShapeKeyPairs);
;
ShapeKeyCombination*pair=shapeKeyPairs+numShapeKeyPairs;
pair->m_uiShapeKeyA=0xffffffff;
pair->m_uiShapeKeyB=0xffffffff;
}
int total=numShapeKeyPairs+1;
if(total<HK_MAX_NUM_HITS_PER_AABB_QUERY)
{
hkShrinkAllocatedStack(shapeKeyPairs,total);
}
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="S" "t" "Narrow";h->setTime();mStream.setEnd((char*)(h+1));}};
if(!input.m_pAdditionalCollidableBody)
{
::FUN_00da5b80(*agent1nTrack,input,shapeContainerA,shapeContainerB,shapeKeyPairs,output);
}
else
{
hkpShapeKey_S*shapeKeys=hkAllocateStack<hkpShapeKey_S>(numShapeKeyPairs+1,"ShapeKeyPairs");
ShapeKeyCombination*fullShapeKeyPairs=shapeKeyPairs;
for(int i=0;i<=numShapeKeyPairs;i++)
{
shapeKeys[i]=fullShapeKeyPairs[i].m_uiShapeKeyB;
}
AgentSubtypeMarker modInput=input;
modInput.m_pBodyA=input.m_pAdditionalCollidableBody;
modInput.m_pAdditionalCollidableBody=0;
::fnv_00da4aa0::FUN_00da4aa0((::fnv_00da4aa0::Q30 &)(*agent1nTrack),(const ::fnv_00da4aa0::Q14 &)(modInput),(const ::fnv_00da4aa0::Q24 *)(shapeContainerB),shapeKeys,(::fnv_00da4aa0::Q6 &)(output));
hkDeallocateStack(shapeKeys);
}
hkDeallocateStack(shapeKeyPairs);
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return hkAddByteOffset(agentData,(((sizeof(AgentSectorPointerArray))+((16)-1))&(~((16)-1))));
}
#include "generated/data/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.inc"
