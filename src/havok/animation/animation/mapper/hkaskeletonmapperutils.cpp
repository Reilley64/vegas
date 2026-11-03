
// src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapperutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/AttributeFormatter.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/Matrix.h"
#include "fnv/decl/Quat74.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cdd000.h"
#include "fnv/symbols_00cde000.h"
#include "fnv/decl/QuatResult.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00ce5000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
struct CE5F90QsTransform
{
    float m_vTranslation[4];
    float m_rotation[4];
    float m_vScale[4];
};


// @fnv 0x00ce5f90
void __cdecl FUN_00ce5f90(CE5F90QsTransform* out, const CE5F90QsTransform* poseA, short boneA,
                          const CE5F90QsTransform* poseB, short boneB, intptr_t mode, float weightA, float weightB)
{
    ::fnv_00ce5a70::FUN_00ce5a70(out, &poseA[boneA], &poseB[boneB], mode, weightA, weightB);
}

#include <xmmintrin.h>

struct __declspec(align(16)) VertexRecord
{
    __m128 m_kPathOffset;
    int m_ai10;
    int m_ai14;
    int m_ai18;
    int m_ai1c;
    int m_ai20;
    int m_ai24;
    int m_ai28;
    int m_ai2c;
};

// Computes the min and max of m_kPathOffset across aiCount VertexRecord entries, storing results in apMin and apMax.
// @fnv 0x00ce5560
void __cdecl FUN_00ce5560(const VertexRecord* apVertices, int aiCount, __m128* apMin, __m128* apMax)
{
    *apMin = _mm_set1_ps(DAT_0104da48);
    *apMax = _mm_set1_ps(DAT_0104e148);

    for (int i = 0; i < aiCount; i++)
    {
        __m128 kForMin = apVertices[i].m_kPathOffset;
        *apMin = _mm_min_ps(*apMin, kForMin);
        __m128 kForMax = apVertices[i].m_kPathOffset;
        *apMax = _mm_max_ps(*apMax, kForMax);
    }
}

namespace fnv_00ce55d0 {


typedef float hkReal;


struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline hkReal length3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        hkReal r;
        _mm_store_ss(&r, _mm_sqrt_ss(len2));
        return r;
    }
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;

    __forceinline void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.m_vComponents = (*reinterpret_cast<__m128 *>((void *)&::DAT_010c71b0));
        m_vScale.SetAllComponents(1.0f);
    }
};

struct ScaleParams
{
    int m_iValueAfterFlags;
    int m_sBoneA;
    int m_sBoneB;
    hkReal m_scaleA;
    hkReal m_scaleB;
};


// Computes scale factors for two poses based on ScaleParams mode, storing results in outA and outB.
// @fnv 0x00ce55d0
void __cdecl FUN_00ce55d0(const ScaleParams* params, int unused, const hkQsTransformq* poseA, int numBonesA,
                          const hkQsTransformq* poseB, int numBonesB, hkQsTransformq* outA, hkQsTransformq* outB)
{
    outA->setIdentity();
    outB->setIdentity();

    if (params->m_iValueAfterFlags == 0)
    {
        hkVector4q minA, maxA, minB, maxB;
        ::FUN_00ce5560((const ::VertexRecord *)(poseA), numBonesA, (::__m128 *)&(minA), (::__m128 *)&(maxA));
        ::FUN_00ce5560((const ::VertexRecord *)(poseB), numBonesB, (::__m128 *)&(minB), (::__m128 *)&(maxB));
        hkVector4q extA;
        extA.setSub4(maxA, minA);
        hkVector4q extB;
        extB.setSub4(maxB, minB);
        hkReal lenA = extA.length3();
        hkReal lenB = extB.length3();
        hkReal fScaleA = lenB / lenA * params->m_scaleB / params->m_scaleA;
        hkReal fScaleB = lenA / lenB * params->m_scaleA / params->m_scaleB;
        outA->m_vScale.SetAllComponents(fScaleA);
        outB->m_vScale.SetAllComponents(fScaleB);
    }
    else if (params->m_iValueAfterFlags == 1)
    {
        hkReal lenA = poseA[params->m_sBoneA].m_vTranslation.length3();
        hkReal lenB = poseB[params->m_sBoneB].m_vTranslation.length3();
        hkReal fScaleA = lenB / lenA * params->m_scaleB / params->m_scaleA;
        hkReal fScaleB = lenA / lenB * params->m_scaleA / params->m_scaleB;
        outA->m_vScale.SetAllComponents(fScaleA);
        outB->m_vScale.SetAllComponents(fScaleB);
    }
    else
    {
        outA->m_vScale.SetAllComponents(params->m_scaleB / params->m_scaleA);
        outB->m_vScale.SetAllComponents(params->m_scaleA / params->m_scaleB);
    }
}
}  // namespace fnv_00ce55d0

#include <math.h>
#include "fnv/symbols_simd.h"
struct ThresholdState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float threshold;
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
    int mode;
};

struct ValueSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

extern "C" float __cdecl GetAngle();
typedef float(* ReadValue)(void*);

// Returns 1 if state->mode is not 1, otherwise returns whether the larger absolute angle of first or second is at most state->threshold.
// @fnv 0x00ce57c0
unsigned char __cdecl FUN_00ce57c0(ThresholdState* state, void* unused1, void* unused2, ValueSource* first,
                                   ValueSource* second)
{
    if (state->mode != 1)
        return 1;

    float a = fabs(reinterpret_cast<ReadValue>(GetAngle)(reinterpret_cast<char*>(first) + 0x10));
    float b = fabs(reinterpret_cast<ReadValue>(GetAngle)(reinterpret_cast<char*>(second) + 0x10));
    float fMaxAngle = a > b ? a : b;
    return static_cast<unsigned char>(fMaxAngle <= state->threshold);
}

namespace fnv_00ce5e60 {


typedef float hkReal;
typedef short hkInt16;

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

union hkVector4q
{
    hkVector4f m_vec;
    __m128 m_vComponents;
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;
};

struct hkaSkeletonq
{
    int m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    const char* m_name;
    hkInt16* m_kParentIndices;
};

extern hkVector4q DAT_010c71e0;

static __forceinline __m128 hkDot3v(__m128 a, __m128 b)
{
    __m128 x2 = _mm_mul_ps(a, b);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy);
}

static __forceinline __m128 hkCross(__m128 a, __m128 b)
{
    __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}

static __forceinline void hkSetRotatedDir(hkVector4q& out, const hkVector4q& quat, const hkVector4q& dir)
{
    __m128 q = quat.m_vComponents;
    __m128 d = dir.m_vComponents;
    __m128 qreal = _mm_shuffle_ps(q, q, 0xff);
    __m128 q2minus1 = _mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0.m_vComponents);
    __m128 ret = _mm_mul_ps(d, q2minus1);
    __m128 imagDotDir = hkDot3v(quat.m_vComponents, dir.m_vComponents);
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), q));
    __m128 imagCrossDir = hkCross(q, d);
    ret = _mm_add_ps(ret, _mm_mul_ps(imagCrossDir, qreal));
    out.m_vComponents = _mm_add_ps(ret, ret);
}

static __forceinline hkReal hkLength3(const hkVector4q& v)
{
    __m128 l2 = hkDot3v(v.m_vComponents, v.m_vComponents);
    hkReal r;
    _mm_store_ss(&r, _mm_sqrt_ss(l2));
    return r;
}

// Walks the parent chain from bone to ancestor, rotating the accumulated position, adding translations, and summing their lengths.
// @fnv 0x00ce5e60
void FUN_00ce5e60(const hkaSkeletonq* apSkeleton, const hkQsTransformq* poses, hkInt16 ancestor, hkInt16 bone,
                  hkReal* pfLengthOut, hkVector4q* posOut)
{
    *pfLengthOut = 0.0f;
    posOut->m_vComponents = _mm_setzero_ps();
    for (hkInt16 b = bone; b > ancestor; b = apSkeleton->m_kParentIndices[b])
    {
        const hkQsTransformq& t = poses[b];
        hkVector4q tmp;
        tmp.m_vec = posOut->m_vec;
        hkSetRotatedDir(*posOut, t.m_rotation, tmp);
        posOut->m_vComponents = _mm_add_ps(posOut->m_vComponents, t.m_vTranslation.m_vComponents);
        *pfLengthOut += hkLength3(t.m_vTranslation);
    }
}
}  // namespace fnv_00ce5e60

namespace fnv_00ce5fe0 {


typedef float hkReal;
typedef short hkInt16;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void operator=(const hkQuaternion& q)
    {
        m_vec.m_vComponents = q.m_vec.m_vComponents;
    }
    void FUN_00cd9d10(const hkVector4& from, const hkVector4& to);
};

struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};

struct hkaSkeleton;

struct BonePairInfo
{
    hkInt16 m_boneA0;
    hkInt16 m_boneA1;
    hkInt16 m_boneB0;
    hkInt16 m_boneB1;
    int unk08;
    int unk0C;
    hkVector4 m_offset;
    hkVector4 unk20;
    hkVector4 unk30;
    hkQuaternion m_rotation;
    hkQuaternion m_relRotation;
    hkVector4 m_vScale;
};


// Fills out with bone indices, offset, rotation, scale, and relative rotation derived from two skeleton bone pairs.
// @fnv 0x00ce5fe0
void FUN_00ce5fe0(const void* data, const hkaSkeleton* skelA, const hkQsTransform* poseA, hkInt16 boneA0,
                  hkInt16 boneA1, const hkaSkeleton* skelB, const hkQsTransform* poseB, hkInt16 boneB0, hkInt16 boneB1,
                  BonePairInfo* out)
{
    out->m_boneA0 = boneA0;
    out->m_boneA1 = boneA1;
    out->m_boneB0 = boneB0;
    out->m_boneB1 = boneB1;
    ::FUN_00ce5f90((::CE5F90QsTransform *)(data), (const ::CE5F90QsTransform *)(poseA), boneA0, (const ::CE5F90QsTransform *)(poseB), boneB0, (intptr_t)(&out->m_offset), 1e-5f, 1.0f);

    hkReal lenA;
    hkReal lenB;
    hkVector4 dirA;
    hkVector4 dirB;
    ::fnv_00ce5e60::FUN_00ce5e60((const ::fnv_00ce5e60::hkaSkeletonq *)(skelA), (const ::fnv_00ce5e60::hkQsTransformq *)(poseA), boneA0, boneA1, &lenA, (::fnv_00ce5e60::hkVector4q *)(::fnv_00ce5fe0::hkVector4 *)(&dirA));
    ::fnv_00ce5e60::FUN_00ce5e60((const ::fnv_00ce5e60::hkaSkeletonq *)(skelB), (const ::fnv_00ce5e60::hkQsTransformq *)(poseB), boneB0, boneB1, &lenB, (::fnv_00ce5e60::hkVector4q *)(::fnv_00ce5fe0::hkVector4 *)(&dirB));

    dirA.normalize3();
    dirB.normalize3();

    hkQuaternion rot;
    rot.FUN_00cd9d10(dirB, dirA);
    out->m_rotation = rot;
    lenA = 1.0f / lenA;
    out->m_vScale.m_vComponents = _mm_set_ps1(lenA);
    reinterpret_cast<::QuatResult *>(&(out->m_relRotation))->FUN_00c74b70((const float *)&(poseA[boneA1].m_rotation), (const float *)&(poseB[boneB1].m_rotation));
}
}  // namespace fnv_00ce5fe0

typedef unsigned int size_t;


struct hkMemoryAllocator;

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocator* m_pStreamAllocator;
};


struct HkElem8
{
    int a;
    int b;
};

template <typename T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            dst[i] = src[i];
        }
    }

    __forceinline void constructWithCopy(T* dst, int n, const T* src)
    {
        for (int i = 0; i < n; i++)
        {
            new (dst + i) T(src[i]);
        }
    }

    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newCap = n < cap2 ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(::hkMemoryAllocator *)(&alloc), (::SpawnedArray *)(void *)(this), newCap, sizeof(T));
        }
    }

    __forceinline void copyFromArray(hkMemoryAllocator& alloc, const HkArray& a)
    {
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        copy(m_data, a.m_data, copiedSize);
        constructWithCopy(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline HkArray& operator=(const HkArray& other)
    {
        copyFromArray(static_cast<hkMemoryRouterStub*>(::FUN_00c85750())->heap(), other);
        return *this;
    }
};

struct FUN_00ce9580
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    float unk10;
    HkArray<HkElem8> arr14;
    HkArray<HkElem8> arr20;
    HkArray<HkElem8> arr2C;
    char unk38;
    char unk39;
    struct Tail
    {
        int unk3C;
        int unk40;
        int unk44;
        int unk48;
        int unk4C;
        int unk50;
    } tail;

    FUN_00ce9580(const FUN_00ce9580& other);
};

// Copies scalar fields and tail from other, then deep-copies the three HkArray<HkElem8> members via their operator=.
// @fnv 0x00ce9580
FUN_00ce9580::FUN_00ce9580(const FUN_00ce9580& other)
    : unk00(other.unk00), unk04(other.unk04), unk08(other.unk08), unk0C(other.unk0C), unk10(other.unk10), arr14(),
      arr20(), arr2C(), unk38(other.unk38), unk39(other.unk39), tail(other.tail)
{
    arr14 = other.arr14;
    arr20 = other.arr20;
    arr2C = other.arr2C;
}


extern "C" void _ReadBarrier();
struct hkStringPtr
{
    const char* m_pcText;
};
struct hkaBone
{
    hkStringPtr m_name;
    char m_bLockTranslation;
};
template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};
struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
};
struct hkaSkeleton : hkReferencedObject
{
    hkStringPtr m_name;
    hkArray<short> m_kParentIndices;
    hkArray<hkaBone> m_kBones;
};
struct __declspec(align(16)) MapperQsTransform
{
    float translation[4];
    float rotation[4];
    float scale[4];
};
struct hkaSkeletonMapperDataSimpleMapping
{
    short m_sBoneA;
    short m_sBoneB;
    MapperQsTransform transform;
};
struct hkaSkeletonMapperData
{
    hkaSkeleton* m_pSkeletonA;
    hkaSkeleton* m_pSkeletonB;
    hkArray<hkaSkeletonMapperDataSimpleMapping> m_kSimpleMappings;
};
struct hkOstream : hkReferencedObject
{
    void* m_pStreamWriter;
    hkOstream(char* buf, int bufLen);
    virtual ~hkOstream();
    hkOstream& operator<<(const char* str);
    hkOstream& operator<<(const hkStringPtr& str);
};
struct hkError
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void message(int kind, int id, const char* text, const char* file, int line);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void beginSection(int id, const char* name);
    virtual void endSection();
};
// @fnv 0x00ce5840
int __cdecl FUN_00ce5840(hkaSkeletonMapperData* mapping)
{
    int i = 0;
    int count = mapping->m_kSimpleMappings.GetLogicalSize();
    hkaSkeleton* skelA = mapping->m_pSkeletonA;
    int numBonesA = skelA->m_kBones.GetLogicalSize();
    hkaSkeleton* skelB = mapping->m_pSkeletonB;
    int numBonesB = skelB->m_kBones.GetLogicalSize();
    int rootA = numBonesA;
    _ReadBarrier();
    int rootB;
    if (count > 0)
    {
        do
        {
            hkaSkeletonMapperDataSimpleMapping* current = &mapping->m_kSimpleMappings[i];
            if (current->m_sBoneA < rootA)
            {
                rootB = current->m_sBoneB;
                if (rootB < numBonesB)
                {
                    rootA = current->m_sBoneA;
                    goto found;
                }
                else
                {
                    char buf[512];
                    hkOstream os(buf, 512);
                    reinterpret_cast<::SinkOwner *>((void *)&(os))->FUN_00cc01c0("Invalid mapping - cannot lock translation based on it");
                    (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba782a, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 767);
                    return 1;
                }
            }
        } while (++i < count);
        rootB = numBonesB;
    }
    else
    {
        rootB = numBonesB;
    }
found:
    if (rootA == skelA->m_kBones.GetLogicalSize())
    {
        char buf[512];
        hkOstream os(buf, 512);
        reinterpret_cast<::SinkOwner *>((void *)&(os))->FUN_00cc01c0("Invalid mapping - cannot lock translations based on it");
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba782a, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 776);
        return 1;
    }
    (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->beginSection(0x87e5654e, "lockTranslationsAutomatically");
    {
        char buf[512];
        hkOstream os(buf, 512);
        reinterpret_cast<::AttributeFormatter *>((void *)(reinterpret_cast<::SinkOwner *>((void *)(reinterpret_cast<::AttributeFormatter *>((void *)(reinterpret_cast<::SinkOwner *>((void *)&(os))->FUN_00cc01c0("Locking translations in skeleton ")))->WriteName((::NameReference *)&(skelA->m_name))))->FUN_00cc01c0(" from bone ")))->WriteName((::NameReference *)&(skelA->m_kBones[rootA].m_name));
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(0, -1, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 784);
    }
    for (int i = 0; i < skelA->m_kBones.GetLogicalSize(); ++i)
    {
        skelA->m_kBones[i].m_bLockTranslation = (i > rootA);
    }
    {
        char buf[512];
        hkOstream os(buf, 512);
        reinterpret_cast<::AttributeFormatter *>((void *)(reinterpret_cast<::SinkOwner *>((void *)(reinterpret_cast<::AttributeFormatter *>((void *)(reinterpret_cast<::SinkOwner *>((void *)&(os))->FUN_00cc01c0("Locking translations in skeleton ")))->WriteName((::NameReference *)&(skelB->m_name))))->FUN_00cc01c0(" from bone ")))->WriteName((::NameReference *)&(skelB->m_kBones[rootB].m_name));
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(0, -1, buf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 793);
    }
    for (int i = 0; i < skelB->m_kBones.GetLogicalSize(); ++i)
    {
        skelB->m_kBones[i].m_bLockTranslation = (i > rootB);
    }
    (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->endSection();
    return 0;
}
void __cdecl FUN_00ce5a70(CE5F90QsTransform* out, const CE5F90QsTransform* a, const CE5F90QsTransform* b, int mode,
                          float weightA, float weightB);
void __cdecl FUN_00ce5f90(CE5F90QsTransform* out, const CE5F90QsTransform* poseA, short boneA,
                          const CE5F90QsTransform* poseB, short boneB, intptr_t mode, float weightA, float weightB);
extern const __m128 DAT_010c71e0;
extern const __m128 DAT_010c71b0;
extern const __m128 DAT_010c7170;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c4c10;

__forceinline __m128 hkQuadRecip(__m128 r)
{
    __m128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}

class HkSimd
{
  public:
    HkSimd(const __m128& x) : m_vValue(x)
    {}
    HkSimd(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    HkSimd()
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

struct HkQuat;

class HkVec4
{
  public:
    __forceinline void operator=(const HkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const __m128& v)
    {
        m_vComponents = v;
    }
    __forceinline __m128& getQuad()
    {
        return m_vComponents;
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vComponents;
    }

    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    __forceinline void SetAllComponents(const HkSimd& a)
    {
        m_vComponents = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
    }
    __forceinline void setAdd4(const HkVec4& v0, const HkVec4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const HkVec4& v0, const HkVec4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void sub4(const HkVec4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setMul4(const HkVec4& a, const HkVec4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const HkSimd& r, const HkVec4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    __forceinline void addMul4(const HkVec4& x, const HkVec4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const HkVec4& a, const HkVec4& x, const HkVec4& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setCross(const HkVec4& v0, const HkVec4& v1)
    {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setNeg4(const HkVec4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setNeg3(const HkVec4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00);
    }
    __forceinline void setXYZ0(const HkVec4& xyz)
    {
        m_vComponents = _mm_and_ps(xyz, DAT_010c4c10);
    }
    __forceinline void setXYZW(const HkVec4& xyz, const HkVec4& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setReciprocal4(const HkVec4& vec)
    {
        m_vComponents = hkQuadRecip(vec.m_vComponents);
    }
    __forceinline void setReciprocal3(const HkVec4& v)
    {
        HkVec4 v1111;
        v1111.getQuad() = DAT_010c7170;
        HkVec4 tmp;
        tmp.setXYZW(v, v1111);
        setReciprocal4(tmp);
    }
    __forceinline void setBroadcast(const HkVec4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    __forceinline void broadcast(int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline HkSimd getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline HkSimd dot3(const HkVec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline HkSimd lengthSquared3() const
    {
        return this->dot3(*this);
    }
    __forceinline void SetRotatedDirection(const HkQuat& quat, const HkVec4& direction);
    __forceinline void setRotatedInverseDir(const HkQuat& quat, const HkVec4& direction);

  private:
    __m128 m_vComponents;

  public:
    operator __m128() const
    {
        return m_vComponents;
    }
};

struct HkQuat
{
    inline HkQuat()
    {}
    inline void operator=(const HkQuat& q)
    {
        m_vec = q.m_vec;
    }
    __forceinline const HkVec4& getImag() const
    {
        return m_vec;
    }
    inline void setIdentity()
    {
        m_vec.getQuad() = DAT_010c71b0;
    }
    inline void SetConjugate(const HkQuat& q)
    {
        m_vec.setNeg3(q.getImag());
    }
    inline void FUN_00c66320(const HkQuat& q0, const HkQuat& q1)
    {
        HkVec4 vec;
        vec.setCross(q0.getImag(), q1.getImag());
        vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
        vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
        HkVec4 dot;
        dot.SetAllComponents(q0.m_vec.dot3(q1.m_vec));
        HkVec4 w;
        w.setMul4(q0.m_vec, q1.m_vec);
        w.sub4(dot);
        m_vec.setXYZW(vec, w);
    }
    HkVec4 m_vec;
};

__forceinline void HkVec4::SetRotatedDirection(const HkQuat& quat, const HkVec4& direction)
{
    HkVec4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    HkVec4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    HkVec4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    HkVec4 ret;
    ret.setMul4(direction, q2minus1);
    HkVec4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());
    HkVec4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

__forceinline void HkVec4::setRotatedInverseDir(const HkQuat& quat, const HkVec4& direction)
{
    HkVec4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    HkVec4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    HkVec4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    HkVec4 ret;
    ret.setMul4(direction, q2minus1);
    HkVec4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());
    HkVec4 imagCrossDir;
    imagCrossDir.setCross(direction, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

struct HkQs
{
    __forceinline HkQs()
    {}
    __forceinline HkQs(const HkQs& t)
    {
        m_vTranslation = t.m_vTranslation;
        m_rotation = t.m_rotation;
        m_vScale = t.m_vScale;
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.setIdentity();
        m_vScale.SetAllComponents(1.0f);
    }
    __forceinline const HkVec4& getTranslation() const
    {
        return m_vTranslation;
    }
    __forceinline void SetConjugate(const HkQs& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        HkVec4 invScale;
        invScale.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(invScale);
    }
    __forceinline void SetProduct(const HkQs& aTb, const HkQs& bTc)
    {
        HkVec4 extraTrans;
        extraTrans.SetRotatedDirection(aTb.m_rotation, bTc.m_vTranslation);
        m_vTranslation.setAdd4(aTb.m_vTranslation, extraTrans);
        m_rotation.FUN_00c66320(aTb.m_rotation, bTc.m_rotation);
        m_vScale.setMul4(aTb.m_vScale, bTc.m_vScale);
    }
    __forceinline void SetMulInverse(const HkQs& a, const HkQs& b)
    {
        HkQs h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
    HkVec4 m_vTranslation;
    HkQuat m_rotation;
    HkVec4 m_vScale;
};

class HkBoolean
{
  public:
    inline HkBoolean()
    {}
    inline HkBoolean(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline HkBoolean& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }

  private:
    char m_cBooleanValue;
};

template <typename E, typename S> class HkEnumValue
{
  public:
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    void operator=(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    HkBoolean operator==(E e) const
    {
        return m_kStorage == static_cast<S>(e);
    }
    S m_kStorage;
};

__forceinline intptr_t __cdecl hkByteOffset(const void* base, const void* pntr)
{
    return intptr_t(pntr) - intptr_t(base);
}

template <typename TYPE> __forceinline TYPE* __cdecl hkAddOffset(TYPE* base, long offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

template <typename TYPE> class HkPad
{
  public:
    __forceinline HkPad()
    {}
    __forceinline HkPad(TYPE e) : m_kStorage(e)
    {}
    __forceinline void operator=(TYPE e)
    {
        m_kStorage = e;
    }
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }
    __forceinline TYPE operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE m_kStorage;
};

template <typename T> struct HkSizeOf
{
    enum
    {
        val = sizeof(T)
    };
};

struct HkHeap
{
    __declspec(nothrow) virtual void slot00() throw();
    __declspec(nothrow) virtual void slot04() throw();
    __declspec(nothrow) virtual void slot08() throw();
    __declspec(nothrow) virtual void slot0c() throw();
    __declspec(nothrow) virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename TYPE> inline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = HkSizeOf<TYPE>::val;
        ReturnMemory(p, numElem * sizeof(TYPE));
    }
};

class HkStack
{
  public:
    __forceinline void* allocateStack(int numBytes, const char* what);
    __forceinline void deallocateStack(void* p);
    __forceinline intptr_t getFreeStackSize()
    {
        return int(hkByteOffset(m_next, m_kRayEnd));
    }

  protected:
    HkPad<void*> m_next;
    HkPad<void*> m_kRayStart;
    HkPad<void*> m_kRayEnd;
};

__forceinline void* HkStack::allocateStack(int numBytes, const char* what)
{
    if (numBytes > getFreeStackSize())
    {
    }
    void* current = m_next;
    m_next = hkAddOffset(current, numBytes);
    return current;
}

void HkStack::deallocateStack(void* p)
{
    m_next = p;
}

class HkRouter
{
  public:
    inline HkStack& stack()
    {
        return m_aiEntries;
    }
    inline HkHeap& temp()
    {
        return *m_pTemp;
    }
    inline HkHeap& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    HkStack m_aiEntries;
    HkHeap* m_pTemp;
    HkHeap* m_pStreamAllocator;
};

template <typename TYPE> __forceinline TYPE* __cdecl hkAllocStack(int n, const char* what = 0)
{
    HkRouter& mem = (*static_cast<HkRouter*>(::FUN_00c85750()));
    return static_cast<TYPE*>(
        mem.stack().allocateStack((((n * HkSizeOf<TYPE>::val) + ((128) - 1)) & (~((128) - 1))), what));
}

template <typename TYPE> __forceinline void __cdecl hkFreeStack(TYPE* ptr)
{
    (*static_cast<HkRouter*>(::FUN_00c85750())).stack().deallocateStack(static_cast<void*>(ptr));
}

struct HkHeapAllocator
{
    HkHeap& get(const void*)
    {
        return (*static_cast<HkRouter*>(::FUN_00c85750())).heap();
    }
};

template <typename T> struct HkArrayElement
{
    T value;
    __forceinline HkArrayElement()
    {}
    __forceinline HkArrayElement(const T& v) : value(v)
    {}
    static __forceinline void* operator new(size_t, void* p)
    {
        return p;
    }
    static __forceinline void operator delete(void*, void*)
    {}
};

template <bool N> struct HkTraitBool
{
    typedef HkTraitBool<N> type;
    enum
    {
        result = N
    };
};
typedef HkTraitBool<true> HkPodTag;
typedef HkTraitBool<false> HkClassTag;
template <typename T> struct HkPodTrait : public HkTraitBool<false>
{
};
template <> struct HkPodTrait<short> : public HkPodTag
{
};
template <> struct HkPodTrait<HkQs> : public HkPodTag
{
};

class HkArrUtil
{
  public:
    template <typename T> static __forceinline void construct(T* t, int n, HkPodTag);
    template <typename T> static __forceinline void construct(T* t, int n, HkClassTag);
    template <typename T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, HkPodTag);
    template <typename T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, HkClassTag);
    template <typename T> static __forceinline void destruct(T* t, int n, HkPodTag);
    template <typename T> static __forceinline void destruct(T* t, int n, HkClassTag);
    template <typename T> static __forceinline void constructWithArray(T* t, int n, const T* tcopy, HkPodTag);
    template <typename T> static __forceinline void constructWithArray(T* t, int n, const T* tcopy, HkClassTag);
};

template <typename T> __forceinline void HkArrUtil::construct(T* t, int n, HkPodTag)
{}

template <typename T> __forceinline void HkArrUtil::construct(T* t, int n, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) HkArrayElement<T>;
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithCopy(T* t, int n, const T& tcopy, HkPodTag)
{
    for (int i = 0; i < n; ++i)
    {
        t[i] = tcopy;
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithCopy(T* t, int n, const T& tcopy, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) HkArrayElement<T>(tcopy);
    }
}

template <typename T> __forceinline void HkArrUtil::destruct(T* t, int n, HkPodTag)
{}

template <typename T> __forceinline void HkArrUtil::destruct(T* t, int n, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        static_cast<T*>(t)[i].~T();
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithArray(T* t, int n, const T* tcopy, HkPodTag)
{
    for (int i = 0; i < n; ++i)
    {
        t[i] = tcopy[i];
    }
}

template <typename T> __forceinline void HkArrUtil::constructWithArray(T* t, int n, const T* tcopy, HkClassTag)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) HkArrayElement<T>(tcopy[i]);
    }
}

template <typename T> class HkArrBase
{
  public:
    __forceinline HkArrBase();
    __forceinline ~HkArrBase()
    {}
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline void clear()
    {
        HkArrUtil::destruct(m_data, m_iElementCount, typename HkPodTrait<T>::type());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(HkHeap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void _pushBack(HkHeap& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(T));
        }
        HkArrUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename HkPodTrait<T>::type());
        m_iElementCount++;
    }
    __forceinline void GrowArrayCapacity(HkHeap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(HkHeap& alloc, int n, const T& fill)
    {
        GrowArrayCapacity(alloc, n);
        HkArrUtil::destruct(m_data + n, m_iElementCount - n, typename HkPodTrait<T>::type());
        HkArrUtil::constructWithCopy(m_data + m_iElementCount, n - m_iElementCount, fill, typename HkPodTrait<T>::type());
        m_iElementCount = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        HkArrUtil::destruct(m_data + n, m_iElementCount - n, typename HkPodTrait<T>::type());
        HkArrUtil::construct(m_data + m_iElementCount, n - m_iElementCount, typename HkPodTrait<T>::type());
        m_iElementCount = n;
    }
    __forceinline T& _expandOne(HkHeap& alloc)
    {
        if (m_iElementCount == getCapacity())
        {
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(T));
        }
        HkArrUtil::construct(m_data + m_iElementCount, 1, typename HkPodTrait<T>::type());
        return m_data[m_iElementCount++];
    }
    __forceinline T& back()
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline const T& back() const
    {
        return m_data[m_iElementCount - 1];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline const T* begin() const
    {
        return m_data;
    }
    static __forceinline void __cdecl copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            dst[i] = src[i];
        }
    }

  protected:
    __forceinline HkArrBase<T>& copyFromArray(HkHeap& alloc, const HkArrBase<T>& a, HkClassTag)
    {
        int oldSize = m_iElementCount;
        int newSize = a.GetLogicalSize();
        int copiedSize = newSize > oldSize ? oldSize : newSize;
        GrowArrayCapacity(alloc, newSize);
        HkArrUtil::destruct(m_data + newSize, oldSize - newSize, HkClassTag());
        copy(m_data, a.m_data, copiedSize);
        HkArrUtil::constructWithArray(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize, HkClassTag());
        m_iElementCount = newSize;
        return *this;
    }

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
__forceinline HkArrBase<T>::HkArrBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
{}

template <typename T> class HkArr : public HkArrBase<T>
{
  public:
    __forceinline HkArr() : HkArrBase<T>()
    {}
    __forceinline ~HkArr();
    __forceinline HkArr& operator=(const HkArrBase<T>& a);
    __forceinline HkArr& operator=(const HkArr& a);
    __forceinline void ClearAndRelease()
    {
        HkArrBase<T>::_clearAndDeallocate(HkHeapAllocator().get(this));
    }
    __forceinline void AddBack(const T& e)
    {
        HkArrBase<T>::_pushBack(HkHeapAllocator().get(this), e);
    }
    __forceinline void SetSizeAndGrow(int size, const T& fill)
    {
        HkArrBase<T>::_setSize(HkHeapAllocator().get(this), size, fill);
    }
    __forceinline T& AllocatePair()
    {
        return HkArrBase<T>::_expandOne(HkHeapAllocator().get(this));
    }
};

template <typename T> __forceinline HkArr<T>::~HkArr()
{
    ClearAndRelease();
}

template <typename T> class HkLocalArr : public HkArr<T>
{
  public:
    __forceinline HkLocalArr(int capacity)
    {
        this->m_data = hkAllocStack<T>(capacity);
        this->m_iCapacityState = capacity | HkArr<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline HkBoolean wasReallocated() const
    {
        return m_pStackAllocation != this->m_data;
    }
    __forceinline ~HkLocalArr()
    {
        if (!wasReallocated())
        {
            HkArr<T>::clear();
        }
        hkFreeStack<T>(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

class HkBaseObj
{
  public:
    __forceinline virtual ~HkBaseObj()
    {}
};

class HkRefObj : public HkBaseObj
{
  public:
    __forceinline HkRefObj()
    {}
    __declspec(nothrow) virtual ~HkRefObj() throw()
    {}
    __declspec(nothrow) virtual const void* GetClassType() const throw();
    __declspec(nothrow) virtual void CalcContentStatistics(void* collector, const void* cls) const throw();
    unsigned short m_usMemSizeAndFlags;
    mutable short m_sReferenceCount;
};

class HkStrPtr
{
  public:
    enum StringFlags
    {
        OWNED_FLAG = 0x1,
    };
    __declspec(nothrow) HkStrPtr() throw();
    __declspec(nothrow) HkStrPtr(const char* string) throw();
    __declspec(nothrow) HkStrPtr(const HkStrPtr& strRef) throw();
    __declspec(nothrow) ~HkStrPtr() throw();
    __declspec(nothrow) HkStrPtr& operator=(const char* s) throw();
    __declspec(nothrow) HkStrPtr& operator=(const HkStrPtr& s) throw();
    inline const char* cString() const;
    inline operator const char*() const;

  private:
    const char* m_pcText;
};

inline const char* HkStrPtr::cString() const
{
    return reinterpret_cast<char*>((uintptr_t)(m_pcText) & ~OWNED_FLAG);
}

class HkBone
{
  public:
    __forceinline HkBone() : m_bLockTranslation(false)
    {}
    __forceinline HkBone(const HkBone& other)
    {
        *this = other;
    }
    __forceinline HkBone& operator=(const HkBone& other)
    {
        if (this == &other)
        {
            return *this;
        }
        m_name = other.m_name;
        m_bLockTranslation = other.m_bLockTranslation;
        return *this;
    }

  public:
    HkStrPtr m_name;
    HkBoolean m_bLockTranslation;
};

template <class TYPE> class HkRef
{
  public:
    __forceinline void operator=(TYPE* e)
    {
        if (e)
        {
            reinterpret_cast<::FUN_00c90510_class *>((void *)(e))->FUN_00c90510();
        }
        if (m_pRetainedObject)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pRetainedObject))->FUN_00c905b0();
        }
        m_pRetainedObject = e;
    }
    TYPE* m_pRetainedObject;
};

class HkLocalFrame;

class HkSkeleton : public HkRefObj
{
  public:
    struct LocalFrameOnBone
    {
        HkRef<HkLocalFrame> m_pLocalFrame;
        int m_iBoneIndex;
    };
    __forceinline HkSkeleton()
    {}
    HkStrPtr m_name;
    HkArr<short> m_kParentIndices;
    HkArr<HkBone> m_kBones;
    HkArr<HkQs> m_kReferencePose;
    HkArr<HkStrPtr> m_kBoneNames;
    HkArr<LocalFrameOnBone> m_kLocalFrames;
};

__forceinline hkError& hkErrorInstance()
{
    return *(*reinterpret_cast<::hkError * *>(&::DAT_01268360));
}

class FUN_00cc00e0 : public HkRefObj
{
  public:
    __declspec(nothrow) ~FUN_00cc00e0() throw();

  protected:
    void* m_pStreamWriter;
};

class FUN_00cb1600 : public FUN_00cc00e0
{
  public:
    __declspec(nothrow) FUN_00cb1600(void* buf, int bufSize) throw();
};

typedef int(__cdecl* HkCompareFunc)(const char*, const char*);

struct HkUserChain
{
    const char* m_kRayStart;
    const char* m_kRayEnd;
};

struct HkUserMapping
{
    ~HkUserMapping() throw()
    {}
    const char* m_pBoneNameA;
    const char* m_pBoneNameB;
};

enum HkMappingType
{
    HK_RAGDOLL_MAPPING = 0,
    HK_RETARGETING_MAPPING = 1
};

struct HkSimpleMapping
{
    HkSimpleMapping()
    {
        m_sBoneA = 0;
        m_sBoneB = 0;
        m_kAFromBTransform.setIdentity();
    }
    short m_sBoneA;
    short m_sBoneB;
    HkQs m_kAFromBTransform;
};

struct HkChainMapping
{
    HkChainMapping()
    {
        m_sStartBoneA = 0;
        m_sEndBoneA = 0;
        m_sStartBoneB = 0;
        m_sEndBoneB = 0;
        m_kStartAFromBTransform.setIdentity();
        m_kEndAFromBTransform.setIdentity();
    }
    short m_sStartBoneA;
    short m_sEndBoneA;
    short m_sStartBoneB;
    short m_sEndBoneB;
    HkQs m_kStartAFromBTransform;
    HkQs m_kEndAFromBTransform;
};

struct HkMotionParams
{
    __declspec(nothrow) void __cdecl FUN_00ce55d0(HkMappingType type, const HkQs* poseAMS, int numBonesA,
                                                  const HkQs* poseBMS, int numBonesB, HkQs& aMotionOut,
                                                  HkQs& bMotionOut) throw();
    int m_iValueAfterFlags;
    int m_iFirstMotionBoneIndex;
    int m_iSecondMotionBoneIndex;
    float m_fFirstMotionParameter;
    float m_fSecondMotionParameter;
};

struct HkMapperParams
{
    __declspec(noinline) HkMapperParams(const HkMapperParams& other) throw()
        : m_pSkeletonA(other.m_pSkeletonA), m_pSkeletonB(other.m_pSkeletonB), m_kBoneNameCompareFunction(other.m_kBoneNameCompareFunction),
          m_fFirstMappingTolerance(other.m_fFirstMappingTolerance),
          m_fSecondMappingTolerance(other.m_fSecondMappingTolerance), m_bFirstMappingOption(other.m_bFirstMappingOption),
          m_bSecondMappingOption(other.m_bSecondMappingOption), m_eMappingType(other.m_eMappingType),
          m_kMotionParams(other.m_kMotionParams)
    {
        m_kUserChainList = other.m_kUserChainList;
        m_kFirstUserMappingList = other.m_kFirstUserMappingList;
        m_kSecondUserMappingList = other.m_kSecondUserMappingList;
    }
    __declspec(noinline) ~HkMapperParams() throw()
    {}
    const HkSkeleton* m_pSkeletonA;
    const HkSkeleton* m_pSkeletonB;
    HkCompareFunc m_kBoneNameCompareFunction;
    float m_fFirstMappingTolerance;
    float m_fSecondMappingTolerance;
    HkArr<HkUserChain> m_kUserChainList;
    HkArr<HkUserMapping> m_kFirstUserMappingList;
    HkArr<HkUserMapping> m_kSecondUserMappingList;
    HkBoolean m_bFirstMappingOption;
    HkBoolean m_bSecondMappingOption;
    HkEnumValue<HkMappingType, int> m_eMappingType;
    HkMotionParams m_kMotionParams;
};

struct HkMapperData
{
    HkRef<const HkSkeleton> m_pSkeletonA;
    HkRef<const HkSkeleton> m_pSkeletonB;
    HkArr<HkSimpleMapping> m_kSimpleMappings;
    HkArr<HkChainMapping> m_kChainMappings;
    HkArr<short> m_kUnmappedBones;
    HkQs m_kExtractedMotionMapping;
    HkBoolean m_bKeepUnmappedLocal;
    HkEnumValue<HkMappingType, int> m_eMappingType;
};

struct Match
{
    int m_sBoneA;
    int m_sBoneB;
};

__declspec(nothrow) void __cdecl FUN_00ce5f90(HkMappingType type, const HkQs* poseA, short boneA, const HkQs* poseB,
                                              short boneB, HkQs& mapOut, float tolerance = 1.0e-5f,
                                              float defaultScale = 1.0f) throw();
__declspec(nothrow) void __cdecl FUN_00ce5fe0(HkMappingType type, const HkSkeleton* skeletonA, const HkQs* poseA,
                                              short startA, short endA, const HkSkeleton* skeletonB, const HkQs* poseB,
                                              short startB, short endB, HkChainMapping& mapAFromBOut) throw();

__forceinline bool __cdecl checkRotation(const HkMapperParams& params, short boneA, short boneB,
                                         const HkQs& aToBTransform, const HkQs& bToATransform)
{
    return true;
}

// @fnv 0x00ce61c0
__declspec(nothrow) void __cdecl FUN_00ce61c0(const HkMapperParams& originalParams, HkMapperData& originalAToB,
                                              HkMapperData& originalBToA) throw()
{
    hkErrorInstance().beginSection(0x54e4323e, "hkaSkeletonMapperUtils::createMapping");

    bool switchedOrder = false;
    HkMapperParams params(originalParams);

    if (params.m_eMappingType == HK_RAGDOLL_MAPPING &&
        originalParams.m_pSkeletonA->m_kBones.GetLogicalSize() > originalParams.m_pSkeletonB->m_kBones.GetLogicalSize())
    {
        params.m_pSkeletonA = originalParams.m_pSkeletonB;
        params.m_pSkeletonB = originalParams.m_pSkeletonA;

        params.m_kFirstUserMappingList = originalParams.m_kSecondUserMappingList;
        params.m_kSecondUserMappingList = originalParams.m_kFirstUserMappingList;

        switchedOrder = true;
    }

    HkMapperData& aToB = switchedOrder ? originalBToA : originalAToB;
    HkMapperData& bToA = switchedOrder ? originalAToB : originalBToA;

    const int numBonesA = params.m_pSkeletonA->m_kBones.GetLogicalSize();
    const int numBonesB = params.m_pSkeletonB->m_kBones.GetLogicalSize();

    HkLocalArr<HkQs> modelPoseA(numBonesA);
    modelPoseA.setSizeUnchecked(numBonesA);
    ::CallWithGlobal(numBonesA, (intptr_t)(params.m_pSkeletonA->m_kParentIndices.begin()),
                 (intptr_t)(params.m_pSkeletonA->m_kReferencePose.begin()), (intptr_t)(modelPoseA.begin()));

    HkLocalArr<HkQs> modelPoseB(numBonesB);
    modelPoseB.setSizeUnchecked(numBonesB);
    ::CallWithGlobal(numBonesB, (intptr_t)(params.m_pSkeletonB->m_kParentIndices.begin()),
                 (intptr_t)(params.m_pSkeletonB->m_kReferencePose.begin()), (intptr_t)(modelPoseB.begin()));

    const HkQs* poseA = (params.m_eMappingType == HK_RAGDOLL_MAPPING) ? modelPoseA.begin()
                                                                      : params.m_pSkeletonA->m_kReferencePose.begin();
    const HkQs* poseB = (params.m_eMappingType == HK_RAGDOLL_MAPPING) ? modelPoseB.begin()
                                                                      : params.m_pSkeletonB->m_kReferencePose.begin();

    const int UNMATCHED = -1;
    const int INCHAIN = -2;

    HkLocalArr<short> map_AtoB(numBonesA);
    map_AtoB.SetSizeAndGrow(numBonesA, UNMATCHED);
    HkLocalArr<short> map_BtoA(numBonesB);
    map_BtoA.SetSizeAndGrow(numBonesB, UNMATCHED);

    aToB.m_eMappingType = params.m_eMappingType;
    bToA.m_eMappingType = params.m_eMappingType;

    aToB.m_pSkeletonA = params.m_pSkeletonA;
    aToB.m_pSkeletonB = params.m_pSkeletonB;

    bToA.m_pSkeletonA = params.m_pSkeletonB;
    bToA.m_pSkeletonB = params.m_pSkeletonA;

    {
        const int numMappings = params.m_kFirstUserMappingList.GetLogicalSize();
        for (int i = 0; i < numMappings; i++)
        {
            const HkUserMapping& mapping = params.m_kFirstUserMappingList[i];

            const short boneIn = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonA), mapping.m_pBoneNameA, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));
            const short boneOut = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonB), mapping.m_pBoneNameB, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));

            if (boneIn != -1 && boneOut != -1)
            {
                HkSimpleMapping simpleMapping;
                simpleMapping.m_sBoneA = boneIn;
                simpleMapping.m_sBoneB = boneOut;

                FUN_00ce5f90(params.m_eMappingType, poseA, boneIn, poseB, boneOut, simpleMapping.m_kAFromBTransform,
                             params.m_fFirstMappingTolerance, params.m_fSecondMappingTolerance);

                aToB.m_kSimpleMappings.AddBack(simpleMapping);

                map_BtoA[boneOut] = boneIn;
            }
            else
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't find bones for mapping (")))))->FUN_00cc01c0(mapping.m_pBoneNameA)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(mapping.m_pBoneNameB)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 127);
                }
                else
                    ;
            }
        }
    }

    {
        const int numMappings = params.m_kSecondUserMappingList.GetLogicalSize();
        for (int i = 0; i < numMappings; i++)
        {
            const HkUserMapping& mapping = params.m_kSecondUserMappingList[i];

            const short boneIn = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonB), mapping.m_pBoneNameA, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));
            const short boneOut = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonA), mapping.m_pBoneNameB, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));

            if (boneIn != -1 && boneOut != -1)
            {
                HkSimpleMapping simpleMapping;
                simpleMapping.m_sBoneA = boneIn;
                simpleMapping.m_sBoneB = boneOut;

                FUN_00ce5f90(params.m_eMappingType, poseB, boneIn, poseA, boneOut, simpleMapping.m_kAFromBTransform);

                bToA.m_kSimpleMappings.AddBack(simpleMapping);

                map_AtoB[boneOut] = boneIn;
            }
            else
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't find bones for mapping (")))))->FUN_00cc01c0(mapping.m_pBoneNameA)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(mapping.m_pBoneNameB)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 158);
                }
                else
                    ;
            }
        }
    }

    if (params.m_eMappingType == HK_RAGDOLL_MAPPING)
    {
        const int numChains = params.m_kUserChainList.GetLogicalSize();
        for (int i = 0; i < numChains; i++)
        {
            const HkUserChain& chain = params.m_kUserChainList[i];

            short startChainA = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonA), chain.m_kRayStart, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));
            short endChainA = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonA), chain.m_kRayEnd, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));

            short startChainB = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonB), chain.m_kRayStart, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));
            short endChainB = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonB), chain.m_kRayEnd, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));

            if (startChainA < 0 && startChainB < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chain.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chain.m_kRayEnd)))))->FUN_00cc01c0("). Start bone not found in either skeleton.");
                    hkErrorInstance().message(1, 0x38521c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 185);
                }
                else
                    ;
                continue;
            }

            if (endChainA < 0 && endChainB < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chain.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chain.m_kRayEnd)))))->FUN_00cc01c0("). End bone not found in either skeleton.");
                    hkErrorInstance().message(1, 0x38521c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 191);
                }
                else
                    ;
                continue;
            }

            if (startChainA < 0)
                startChainA = map_BtoA[startChainB];
            if (endChainA < 0)
                endChainA = map_BtoA[endChainB];
            if (startChainB < 0)
                startChainB = map_AtoB[startChainA];
            if (endChainB < 0)
                endChainB = map_AtoB[endChainA];

            HkArr<short> chainA;
            HkArr<short> chainB;
            const HkBoolean chainAok = (*(::HkBoolean *)(::WalkChainUntilLimit((unsigned char *)&(*params.m_pSkeletonA), (::ScanRec *)(startChainA), endChainA, (short)&(chainA), {})));
            const HkBoolean chainBok = (*(::HkBoolean *)(::WalkChainUntilLimit((unsigned char *)&(*params.m_pSkeletonB), (::ScanRec *)(startChainB), endChainB, (short)&(chainB), {})));

            if (!chainAok || !chainBok)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chain.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chain.m_kRayEnd)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c63, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 210);
                }
                else
                    ;
                continue;
            }

            const int chainLengthA = chainA.GetLogicalSize();
            const int chainLengthB = chainB.GetLogicalSize();

            if (chainLengthA < 2 || chainLengthB < 2)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chain.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chain.m_kRayEnd)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 220);
                }
                else
                    ;
                continue;
            }

            for (int a = 1; a < chainLengthA - 1; a++)
            {
                if (map_AtoB[chainA[a]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chain.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chain.m_kRayEnd)))))->FUN_00cc01c0(")");
                        hkErrorInstance().message(1, 0xabba1c65, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  230);
                    }
                    else
                        ;
                    continue;
                }
            }

            for (int b = 1; b < chainLengthB - 1; b++)
            {
                if (map_BtoA[chainB[b]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chain.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chain.m_kRayEnd)))))->FUN_00cc01c0(")");
                        hkErrorInstance().message(1, 0xabba1c66, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  239);
                    }
                    else
                        ;
                    continue;
                }
            }

            {
                if (1)
                {
                    char reportBuf[512];
                    FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                    reinterpret_cast<::AttributeFormatter *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::AttributeFormatter *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Creating chain ")))))->WriteName((::NameReference *)&(params.m_pSkeletonA->m_kBones[startChainA].m_name))))))->FUN_00cc01c0(" - ")))))->WriteName((::NameReference *)&(params.m_pSkeletonA->m_kBones[endChainA].m_name));
                    hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 249);
                }
                else
                    ;

                const HkQs& transformStartA = modelPoseA[startChainA];
                const HkQs& transformStartB = modelPoseB[startChainB];
                const HkQs& transformEndA = modelPoseA[endChainA];
                const HkQs& transformEndB = modelPoseB[endChainB];

                {
                    HkChainMapping chainMappingAtoB;

                    chainMappingAtoB.m_sStartBoneA = startChainA;
                    chainMappingAtoB.m_sEndBoneA = endChainA;
                    chainMappingAtoB.m_sStartBoneB = startChainB;
                    chainMappingAtoB.m_sEndBoneB = endChainB;
                    chainMappingAtoB.m_kEndAFromBTransform.SetMulInverse(transformEndA, transformEndB);
                    chainMappingAtoB.m_kStartAFromBTransform.SetMulInverse(transformStartA, transformStartB);

                    aToB.m_kChainMappings.AddBack(chainMappingAtoB);
                }

                {
                    HkChainMapping chainMappingBtoA;

                    chainMappingBtoA.m_sStartBoneA = startChainB;
                    chainMappingBtoA.m_sEndBoneA = endChainB;
                    chainMappingBtoA.m_sStartBoneB = startChainA;
                    chainMappingBtoA.m_sEndBoneB = endChainA;
                    chainMappingBtoA.m_kEndAFromBTransform.SetMulInverse(transformEndB, transformEndA);
                    chainMappingBtoA.m_kStartAFromBTransform.SetMulInverse(transformStartB, transformStartA);

                    bToA.m_kChainMappings.AddBack(chainMappingBtoA);
                }

                for (int a = 1; a < chainLengthA - 1; a++)
                {
                    map_AtoB[chainA[a]] = INCHAIN;
                }
                for (int b = 1; b < chainLengthB - 1; b++)
                {
                    map_BtoA[chainB[b]] = INCHAIN;
                }
            }
        }
    }
    else
    {
        const int numChains = params.m_kUserChainList.GetLogicalSize();

        for (int i = 0; i < numChains / 2; i++)
        {
            const HkUserChain& chainA = params.m_kUserChainList[i * 2];
            const HkUserChain& chainB = params.m_kUserChainList[i * 2 + 1];

            short startChainA = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonA), chainA.m_kRayStart, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));
            short endChainA = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonA), chainA.m_kRayEnd, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));

            short startChainB = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonB), chainB.m_kRayStart, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));
            short endChainB = ::FindIndexByKey((::S_00cdd390_Table *)&(*params.m_pSkeletonB), chainB.m_kRayEnd, (int (*)(const void *, const void *))(params.m_kBoneNameCompareFunction));

            if (startChainA < 0 || endChainA < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainA.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainA.m_kRayEnd)))))->FUN_00cc01c0("). Start or end bone not found.");
                    hkErrorInstance().message(1, 0xabbaa938, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 325);
                }
                else
                    ;
                continue;
            }

            if (startChainB < 0 || endChainB < 0)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainB.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainB.m_kRayEnd)))))->FUN_00cc01c0("). Start or end bone not found.");
                    hkErrorInstance().message(1, 0xabbaa938, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 331);
                }
                else
                    ;
                continue;
            }

            HkArr<short> chainABones;
            HkArr<short> chainBBones;
            const HkBoolean chainAok = (*(::HkBoolean *)(::WalkChainUntilLimit((unsigned char *)&(*params.m_pSkeletonA), (::ScanRec *)(startChainA), endChainA, (short)&(chainABones), {})));
            const HkBoolean chainBok = (*(::HkBoolean *)(::WalkChainUntilLimit((unsigned char *)&(*params.m_pSkeletonB), (::ScanRec *)(startChainB), endChainB, (short)&(chainBBones), {})));

            if (!chainAok)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainA.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainA.m_kRayEnd)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c63, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 343);
                }
                else
                    ;
                continue;
            }

            if (!chainBok)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainB.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainB.m_kRayEnd)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1c63, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 349);
                }
                else
                    ;
                continue;
            }

            const int chainLengthA = chainABones.GetLogicalSize();
            const int chainLengthB = chainBBones.GetLogicalSize();

            if (chainLengthA < 2)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainA.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainA.m_kRayEnd)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1d64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 359);
                }
                else
                    ;
                continue;
            }

            if (chainLengthB < 2)
            {
                if (1)
                {
                    char assertBuf[512];
                    FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainB.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainB.m_kRayEnd)))))->FUN_00cc01c0(")");
                    hkErrorInstance().message(1, 0xabba1d64, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 366);
                }
                else
                    ;
                continue;
            }

            for (int a = 0; a < chainLengthA; a++)
            {
                if (map_AtoB[chainABones[a]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainA.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainA.m_kRayEnd)))))->FUN_00cc01c0(")  Perhaps a bone is mapped twice?");
                        hkErrorInstance().message(1, 0xabba1d65, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  376);
                    }
                    else
                        ;
                    continue;
                }
            }

            for (int b = 0; b < chainLengthB; b++)
            {
                if (map_BtoA[chainBBones[b]] != UNMATCHED)
                {
                    if (1)
                    {
                        char assertBuf[512];
                        FUN_00cb1600 ostr(assertBuf, sizeof(assertBuf));
                        reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Couldn't make a chain (")))))->FUN_00cc01c0(chainB.m_kRayStart)))))->FUN_00cc01c0(" - ")))))->FUN_00cc01c0(chainB.m_kRayEnd)))))->FUN_00cc01c0(")  Perhaps a bone is mapped twice?");
                        hkErrorInstance().message(1, 0xabba1d66, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp",
                                                  385);
                    }
                    else
                        ;
                    continue;
                }
            }

            {
                if (1)
                {
                    char reportBuf[512];
                    FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                    reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Creating chains: ")))))->FUN_00cc01c0("( ")))))->FUN_00cc01c0(chainA.m_kRayStart)))))->FUN_00cc01c0(", ")))))->FUN_00cc01c0(chainA.m_kRayEnd)))))->FUN_00cc01c0(" )   ( ")))))->FUN_00cc01c0(chainB.m_kRayStart)))))->FUN_00cc01c0(", ")))))->FUN_00cc01c0(chainB.m_kRayEnd)))))->FUN_00cc01c0(" )");
                    hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 397);
                }
                else
                    ;

                HkChainMapping chainMappingAFromB;
                HkChainMapping chainMappingBFromA;

                FUN_00ce5fe0(params.m_eMappingType, params.m_pSkeletonA, poseA, startChainA, endChainA,
                             params.m_pSkeletonB, poseB, startChainB, endChainB, chainMappingAFromB);

                FUN_00ce5fe0(params.m_eMappingType, params.m_pSkeletonB, poseB, startChainB, endChainB,
                             params.m_pSkeletonA, poseA, startChainA, endChainA, chainMappingBFromA);

                bToA.m_kChainMappings.AddBack(chainMappingBFromA);
                aToB.m_kChainMappings.AddBack(chainMappingAFromB);

                for (int a = 0; a < chainLengthA; a++)
                {
                    map_AtoB[chainABones[a]] = INCHAIN;
                }
                for (int b = 0; b < chainLengthB; b++)
                {
                    map_BtoA[chainBBones[b]] = INCHAIN;
                }
            }
        }
    }

    if (params.m_bFirstMappingOption)
    {
        HkArr<Match> matches;

        HkCompareFunc compare;
        if (params.m_kBoneNameCompareFunction)
        {
            compare = params.m_kBoneNameCompareFunction;
        }
        else
        {
            if (params.m_eMappingType == HK_RAGDOLL_MAPPING && params.m_fFirstMappingTolerance > 0.0f)
            {
                compare = 0;
            }
            else
            {
                compare = ((int (&)(const char *, const char *) noexcept)::fnv_00cb0fe0::CompareStringsCaseInsensitive);
            }
        }

        const HkSimd tolSqrd = params.m_fFirstMappingTolerance * params.m_fFirstMappingTolerance;

        for (int idxA = 0; idxA < numBonesA; idxA++)
        {
            if (compare)
            {
                for (int idxB = 0; idxB < numBonesB; idxB++)
                {
                    const char* nameA = params.m_pSkeletonA->m_kBones[idxA].m_name;
                    const char* nameB = params.m_pSkeletonB->m_kBones[idxB].m_name;

                    if (compare(nameA, nameB) == 0)
                    {
                        Match& match = matches.AllocatePair();
                        match.m_sBoneA = idxA;
                        match.m_sBoneB = idxB;
                    }
                }
            }
            else
            {
                const HkQs& transformA = modelPoseA[idxA];
                float shortest = 100000.0f;
                int shortestIndex = -1;
                for (int idxB = 0; idxB < numBonesB; idxB++)
                {
                    const HkQs& transformB = modelPoseB[idxB];

                    HkVec4 dif;
                    dif.setSub4(transformA.getTranslation(), transformB.getTranslation());
                    const float ls = dif.lengthSquared3();
                    if (ls < shortest)
                    {
                        shortest = ls;
                        shortestIndex = idxB;
                    }
                }
                if (shortest < tolSqrd)
                {
                    Match& match = matches.AllocatePair();
                    match.m_sBoneA = idxA;
                    match.m_sBoneB = shortestIndex;
                }
            }
        }

        const int numMatches = matches.GetLogicalSize();

        for (int i = 0; i < numMatches; i++)
        {
            const short boneA = (short)matches[i].m_sBoneA;
            const short boneB = (short)matches[i].m_sBoneB;

            if (map_AtoB[boneA] != UNMATCHED || map_BtoA[boneB] != UNMATCHED)
            {
                continue;
            }

            {
                HkSimpleMapping simpleMappingAtoB;
                simpleMappingAtoB.m_sBoneA = boneA;
                simpleMappingAtoB.m_sBoneB = boneB;

                const char* boneAName = params.m_pSkeletonA->m_kBones[boneA].m_name;
                const char* boneBName = params.m_pSkeletonB->m_kBones[boneB].m_name;

                FUN_00ce5f90(params.m_eMappingType, poseA, boneA, poseB, boneB, simpleMappingAtoB.m_kAFromBTransform,
                             params.m_fFirstMappingTolerance, 1.0f);

                aToB.m_kSimpleMappings.AddBack(simpleMappingAtoB);
            }

            {
                HkSimpleMapping simpleMappingBtoA;
                simpleMappingBtoA.m_sBoneA = boneB;
                simpleMappingBtoA.m_sBoneB = boneA;

                const char* boneAName = params.m_pSkeletonA->m_kBones[boneA].m_name;
                const char* boneBName = params.m_pSkeletonB->m_kBones[boneB].m_name;

                FUN_00ce5f90(params.m_eMappingType, poseB, boneB, poseA, boneA, simpleMappingBtoA.m_kAFromBTransform,
                             params.m_fFirstMappingTolerance, 1.0f);

                bToA.m_kSimpleMappings.AddBack(simpleMappingBtoA);
            }

            checkRotation(params, boneA, boneB, aToB.m_kSimpleMappings.back().m_kAFromBTransform,
                          bToA.m_kSimpleMappings.back().m_kAFromBTransform);

            map_AtoB[boneA] = boneB;
            map_BtoA[boneB] = boneA;

            if (1)
            {
                char reportBuf[512];
                FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                reinterpret_cast<::AttributeFormatter *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Matching ")))))->WriteName((::NameReference *)&(params.m_pSkeletonA->m_kBones[boneA].m_name));
                hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 561);
            }
            else
                ;
        }
    }

    if (params.m_bSecondMappingOption)
    {
        for (int boneA = 0; boneA < numBonesA; boneA++)
        {
            if (map_AtoB[boneA] < 0)
            {
                continue;
            }

            const short endChainA = (short)boneA;
            const short endChainB = map_AtoB[boneA];

            short startChainA = params.m_pSkeletonA->m_kParentIndices[boneA];

            while (startChainA != -1 && UNMATCHED == map_AtoB[startChainA])
            {
                startChainA = params.m_pSkeletonA->m_kParentIndices[startChainA];
            }

            if (-1 == startChainA || INCHAIN == map_AtoB[startChainA])
            {
                continue;
            }

            const short startChainB = map_AtoB[startChainA];

            HkArr<short> chainA;
            HkArr<short> chainB;
            const HkBoolean chainAok = (*(::HkBoolean *)(::WalkChainUntilLimit((unsigned char *)&(*params.m_pSkeletonA), (::ScanRec *)(startChainA), endChainA, (short)&(chainA), {})));
            const HkBoolean chainBok = (*(::HkBoolean *)(::WalkChainUntilLimit((unsigned char *)&(*params.m_pSkeletonB), (::ScanRec *)(startChainB), endChainB, (short)&(chainB), {})));

            if (!chainAok || !chainBok)
            {
                continue;
            }

            const int chainLengthA = chainA.GetLogicalSize();
            const int chainLengthB = chainB.GetLogicalSize();

            if (chainLengthA == 2 && chainLengthB == 2)
            {
                continue;
            }

            {
                bool ok = true;
                for (int b = 1; b < chainLengthB - 1; b++)
                {
                    if (map_BtoA[chainB[b]] != UNMATCHED)
                    {
                        ok = false;
                        continue;
                    }
                }
                if (!ok)
                {
                    continue;
                }
            }

            {
                if (1)
                {
                    char reportBuf[512];
                    FUN_00cb1600 ostr(reportBuf, sizeof(reportBuf));
                    reinterpret_cast<::AttributeFormatter *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::AttributeFormatter *>(&((*(class class ::FUN_00cc00e0 *)(reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0("Creating chain ")))))->WriteName((::NameReference *)&(params.m_pSkeletonA->m_kBones[startChainA].m_name))))))->FUN_00cc01c0(" - ")))))->WriteName((::NameReference *)&(params.m_pSkeletonA->m_kBones[endChainA].m_name));
                    hkErrorInstance().message(0, -1, reportBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", 637);
                }
                else
                    ;

                const HkQs& transformStartA = modelPoseA[startChainA];
                const HkQs& transformStartB = modelPoseB[startChainB];
                const HkQs& transformEndA = modelPoseA[endChainA];
                const HkQs& transformEndB = modelPoseB[endChainB];

                {
                    HkChainMapping chainMappingAtoB;

                    chainMappingAtoB.m_sStartBoneA = startChainA;
                    chainMappingAtoB.m_sEndBoneA = endChainA;
                    chainMappingAtoB.m_sStartBoneB = startChainB;
                    chainMappingAtoB.m_sEndBoneB = endChainB;
                    chainMappingAtoB.m_kEndAFromBTransform.SetMulInverse(transformEndA, transformEndB);
                    chainMappingAtoB.m_kStartAFromBTransform.SetMulInverse(transformStartA, transformStartB);

                    aToB.m_kChainMappings.AddBack(chainMappingAtoB);
                }

                {
                    HkChainMapping chainMappingBtoA;

                    chainMappingBtoA.m_sStartBoneA = startChainB;
                    chainMappingBtoA.m_sEndBoneA = endChainB;
                    chainMappingBtoA.m_sStartBoneB = startChainA;
                    chainMappingBtoA.m_sEndBoneB = endChainA;
                    chainMappingBtoA.m_kEndAFromBTransform.SetMulInverse(transformEndB, transformEndA);
                    chainMappingBtoA.m_kStartAFromBTransform.SetMulInverse(transformStartB, transformStartA);

                    bToA.m_kChainMappings.AddBack(chainMappingBtoA);
                }

                for (int a = 1; a < chainLengthA - 1; a++)
                {
                    map_AtoB[chainA[a]] = INCHAIN;
                }
                for (int b = 1; b < chainLengthB - 1; b++)
                {
                    map_BtoA[chainB[b]] = INCHAIN;
                }
            }
        }
    }

    for (int b = 0; b < numBonesB; b++)
    {
        if (UNMATCHED == map_BtoA[b])
        {
            aToB.m_kUnmappedBones.AddBack((short)b);
        }
    }

    for (int a = 0; a < numBonesA; a++)
    {
        if (UNMATCHED == map_AtoB[a])
        {
            bToA.m_kUnmappedBones.AddBack((short)a);
        }
    }

    aToB.m_bKeepUnmappedLocal = true;
    bToA.m_bKeepUnmappedLocal = true;

    originalAToB.m_kExtractedMotionMapping.setIdentity();
    originalBToA.m_kExtractedMotionMapping.setIdentity();

    if (params.m_eMappingType == HK_RETARGETING_MAPPING)
    {
        params.m_kMotionParams.FUN_00ce55d0(params.m_eMappingType, modelPoseA.begin(), numBonesA, modelPoseB.begin(),
                                           numBonesB, originalAToB.m_kExtractedMotionMapping,
                                           originalBToA.m_kExtractedMotionMapping);
    }

    hkErrorInstance().endSection();
}namespace fnv_00ce5a70 {


extern const __m128 DAT_010c71e0;
extern const __m128 DAT_010c7170;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010c4c00;
extern const __m128 DAT_010c4c10;

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
};

struct HkQuat;
struct HkVec
{
    __m128 m;
    __forceinline void setRotatedInverseDir(const HkQuat& q, const HkVec& v);
    __forceinline void SetRotatedDirection(const HkQuat& q, const HkVec& v);
    __forceinline void setReciprocal3(const HkVec& v);
    __forceinline float length3() const;
};
struct HkQuat
{
    HkVec v;
    void FUN_00c66320(const HkQuat& a, const HkQuat& b) throw();
};
struct HkQs
{
    HkVec m_vTranslation;
    HkQuat m_rotation;
    HkVec m_vScale;
    __forceinline void SetConjugate(const HkQs& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.m = _mm_xor_ps(m_vTranslation.m, DAT_010c44d0);
        m_rotation.v.m = _mm_xor_ps(t.m_rotation.v.m, DAT_010c4c00);
        m_vScale.setReciprocal3(t.m_vScale);
    }
    __forceinline void SetProduct(const HkQs& a, const HkQs& b)
    {
        m_vTranslation.SetRotatedDirection(a.m_rotation, b.m_vTranslation);
        m_vTranslation.m = _mm_add_ps(m_vTranslation.m, a.m_vTranslation.m);
        m_rotation.FUN_00c66320(a.m_rotation, b.m_rotation);
        m_vScale.m = _mm_mul_ps(b.m_vScale.m, a.m_vScale.m);
    }
};

static __forceinline __m128 dot3_from_prod(__m128 prod)
{
    __m128 y = _mm_shuffle_ps(prod, prod, 0x55);
    __m128 d = _mm_add_ss(y, prod);
    __m128 z = _mm_shuffle_ps(prod, prod, 0xAA);
    return _mm_add_ss(z, d);
}

__forceinline void HkVec::setRotatedInverseDir(const HkQuat& quat, const HkVec& vec)
{
    __m128 q = quat.v.m;
    __m128 v = vec.m;
    __m128 qw = _mm_shuffle_ps(quat.v.m, quat.v.m, 0xFF);
    __m128 prod = _mm_mul_ps(v, q);
    __m128 dot = dot3_from_prod(prod);
    __m128 v_yzx = _mm_shuffle_ps(v, v, 0xC9);
    __m128 q_zxy = _mm_shuffle_ps(q, q, 0xD2);
    __m128 cross = _mm_mul_ps(v_yzx, q_zxy);
    __m128 v_zxy = _mm_shuffle_ps(v, v, 0xD2);
    __m128 q_yzx = _mm_shuffle_ps(q, q, 0xC9);
    cross = _mm_sub_ps(cross, _mm_mul_ps(v_zxy, q_yzx));
    cross = _mm_mul_ps(cross, qw);
    __m128 qw2 = _mm_mul_ps(qw, qw);
    qw2 = _mm_add_ps(qw2, DAT_010c71e0);
    __m128 term = _mm_mul_ps(qw2, v);
    __m128 qdot = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    term = _mm_add_ps(term, qdot);
    term = _mm_add_ps(cross, term);
    m = _mm_add_ps(term, term);
}

__forceinline void HkVec::SetRotatedDirection(const HkQuat& quat, const HkVec& vec)
{
    __m128 q = quat.v.m;
    __m128 v = vec.m;
    __m128 qw = _mm_shuffle_ps(quat.v.m, quat.v.m, 0xFF);
    __m128 prod = _mm_mul_ps(v, q);
    __m128 dot = dot3_from_prod(prod);
    __m128 q_zxy = _mm_shuffle_ps(q, q, 0xD2);
    __m128 v_yzx = _mm_shuffle_ps(v, v, 0xC9);
    __m128 cross = _mm_mul_ps(v_yzx, q_zxy);
    __m128 v_zxy = _mm_shuffle_ps(v, v, 0xD2);
    __m128 q_yzx = _mm_shuffle_ps(q, q, 0xC9);
    cross = _mm_sub_ps(_mm_mul_ps(v_zxy, q_yzx), cross);
    cross = _mm_mul_ps(cross, qw);
    __m128 qw2 = _mm_mul_ps(qw, qw);
    qw2 = _mm_add_ps(qw2, DAT_010c71e0);
    __m128 term = _mm_mul_ps(qw2, v);
    __m128 qdot = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    term = _mm_add_ps(term, qdot);
    term = _mm_add_ps(cross, term);
    m = _mm_add_ps(term, term);
}

static __forceinline HkVec quadReciprocal(const HkVec& v)
{
    HkVec result;
    __m128 r = _mm_rcp_ps(v.m);
    __m128 e = _mm_mul_ps(r, v.m);
    e = _mm_mul_ps(e, r);
    result.m = _mm_sub_ps(_mm_add_ps(r, r), e);
    return result;
}
__forceinline void HkVec::setReciprocal3(const HkVec& vec)
{
    __m128 s = vec.m;
    __m128 ones = DAT_010c7170;
    __m128 hi = _mm_unpackhi_ps(s, ones);
    __m128 mixed = _mm_shuffle_ps(s, hi, 0xC4);
    HkVec v;
    v.m = mixed;
    HkVec result = quadReciprocal(v);
    m = _mm_and_ps(result.m, DAT_010c4c10);
}

__forceinline float HkVec::length3() const
{
    __m128 v = m;
    __m128 sq = _mm_mul_ps(v, v);
    __m128 d = dot3_from_prod(sq);
    d = _mm_sqrt_ss(d);
    float out;
    _mm_store_ss(&out, d);
    return out;
}

__declspec(noinline) void HkQuat::FUN_00c66320(const HkQuat& a, const HkQuat& b) throw()
{
    __m128 av = a.v.m, bv = b.v.m;
    __m128 ax = _mm_shuffle_ps(av, av, 0), ay = _mm_shuffle_ps(av, av, 0x55);
    __m128 az = _mm_shuffle_ps(av, av, 0xaa), aw = _mm_shuffle_ps(av, av, 0xff);
    __m128 bx = _mm_shuffle_ps(bv, bv, 0), by = _mm_shuffle_ps(bv, bv, 0x55);
    __m128 bz = _mm_shuffle_ps(bv, bv, 0xaa), bw = _mm_shuffle_ps(bv, bv, 0xff);
    __m128 x = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(ay, bz), _mm_mul_ps(az, by)), _mm_mul_ps(aw, bx)),
                          _mm_mul_ps(bw, ax));
    __m128 y = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(az, bx), _mm_mul_ps(ax, bz)), _mm_mul_ps(aw, by)),
                          _mm_mul_ps(bw, ay));
    __m128 z = _mm_add_ps(_mm_add_ps(_mm_sub_ps(_mm_mul_ps(ax, by), _mm_mul_ps(ay, bx)), _mm_mul_ps(aw, bz)),
                          _mm_mul_ps(bw, az));
    __m128 sum = _mm_add_ps(_mm_add_ps(_mm_mul_ps(ay, by), _mm_mul_ps(ax, bx)), _mm_mul_ps(az, bz));
    __m128 w = _mm_sub_ps(_mm_mul_ps(aw, bw), sum);
    __m128 xy = _mm_unpacklo_ps(x, y), zw = _mm_unpacklo_ps(z, w);
    v.m = _mm_movelh_ps(xy, zw);
}

static __forceinline void warnAlways(int id, const char* text, int line)
{
    char assertBuf[512];
    hkOstream ostr(assertBuf, 512);
    reinterpret_cast<::SinkOwner *>((void *)&(ostr))->FUN_00cc01c0(text);
    (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, id, assertBuf, ".\\Mapper\\hkaSkeletonMapperUtils.cpp", line);
}

// @fnv 0x00ce5a70
void __cdecl FUN_00ce5a70(CE5F90QsTransform* mappingType, const CE5F90QsTransform* poseA,
                          const CE5F90QsTransform* poseB, intptr_t outputAddress, float tolerance, float defaultScale)
{
    intptr_t type = reinterpret_cast<intptr_t>(mappingType);
    CE5F90QsTransform* mapOut = reinterpret_cast<CE5F90QsTransform*>(outputAddress);
    HkQs* a = (HkQs*)poseA;
    HkQs* b = (HkQs*)poseB;
    HkQs* out = (HkQs*)mapOut;

    if (type == 0)
    {
        HkQs inverse;
        inverse.SetConjugate(*a);
        out->SetProduct(inverse, *b);
    }
    else if (type == 1)
    {
        if (tolerance < 0.0f)
        {
            warnAlways(0xabba39c3, "Tolerance must be positive", 846);
        }
        float lenA = a->m_vTranslation.length3();
        float lenB = b->m_vTranslation.length3();
        bool aZero = lenA <= tolerance;
        bool bZero = lenB <= tolerance;
        float scale;
        switch (aZero || bZero)
        {
        case false:
            scale = lenB / lenA;
            break;
        default:
            if (aZero != bZero)
            {
                warnAlways(
                    0xabba2b94,
                    "Attempt to map a zero length bone to a non-zero length bone.  This may result in poor accuracy.",
                    860);
            }
            scale = defaultScale;
            break;
        }
        __m128 sv = _mm_load_ss(&scale);
        sv = _mm_shuffle_ps(sv, sv, 0);
        out->m_vScale.m = sv;
        reinterpret_cast<::Quat74 *>(&(out->m_rotation))->FUN_00c74ac0((const ::Quat74 &)(b->m_rotation), (const ::Quat74 &)(a->m_rotation));
        float neg = -scale;
        __m128 ns = _mm_load_ss(&neg);
        ns = _mm_shuffle_ps(ns, ns, 0);
        __m128 tr = _mm_mul_ps(ns, a->m_vTranslation.m);
        tr = _mm_add_ps(tr, b->m_vTranslation.m);
        out->m_vTranslation.m = tr;
    }
    else
    {
        warnAlways(0xabbaef91, "Unsupported mapping type", 876);
    }

    hkBool valid;
    if (!((::fnv_00ce5a70::hkBool *)(reinterpret_cast<::Matrix *>((void *)(out))->HasFiniteValues((bool *)(::fnv_00ce5a70::hkBool *)(&valid))))->m_cBooleanValue)
    {
        warnAlways(0xabba10fc, "Mapping is invalid", 881);
    }
}
}

#include "generated/data/havok/animation/animation/mapper/hkaskeletonmapperutils.inc"
