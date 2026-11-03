
// src/havok/common/visualize/shape/hkdisplaysphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <xmmintrin.h>
#include "fnv_simd.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00e0a000.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/symbols_01268000.h"


struct hkVector4
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return fnv_simd_as<float>(m_vComponents)[i];
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct __declspec(align(16)) hkVec4f
{
    float x, y, z, w;
};


struct FUN_008cd6a0_Class
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        float* d = &m_kColumn0(0);
        d[0] = 1.0f;
        d[5] = 1.0f;
        d[10] = 1.0f;
        m_vTranslation.setZero4();
    }
};

struct hkReferencedObject
{
    virtual void vf0();
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObject()
    {
        m_sReferenceCount = 1;
    }
};

struct __declspec(align(16)) ShapeBase : hkReferencedObject
{
    int m_ulUserData;
    FUN_008cd6a0_Class m_kMotionTransform;
    int m_type;

    ShapeBase()
    {
        m_ulUserData = 0;
        m_type = 1;
        m_kMotionTransform.setIdentity();
    }
};

struct __declspec(align(16)) FUN_00e0af50 : ShapeBase
{
    hkVec4f m_vec;
    int m_kPointA;
    int m_kPointB;

    FUN_00e0af50(const hkVec4f& v, int a, int b);
};

// @fnv 0x00e0af50
FUN_00e0af50::FUN_00e0af50(const hkVec4f& aVec, int a, int b)
{
    m_vec = aVec;
    m_kPointA = a;
    m_kPointB = b;
    FUN_008cd6a0_Class& t = m_kMotionTransform;
    reinterpret_cast<::RotationRows *>(&(t))->FUN_00cb2d90(&DAT_012683b0);
    t.m_vTranslation = *(const hkVector4*)&aVec;
}

// @fnv 0x00e0af40
void FUN_00e0af40(int a, int b)
{}


void* FUN_00c85750(void);

struct AllocatorHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

struct SubdivVecArray
{
    hkVector4* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};

struct SubdivTri
{
    int a;
    int b;
    int c;
    int d;
};

struct SubdivTriArray
{
    SubdivTri* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};

struct SubdivMesh
{
    SubdivVecArray m_verts;
    SubdivTriArray m_tris;
};

static __forceinline void SubdivMidpoint(__m128* dst, __m128 m, const float* pw)
{
    __m128 zero = _mm_set_ss(0.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 three = _mm_set_ss(3.0f);
    _mm_store_ps((float*)dst, m);
    __m128 sq = _mm_mul_ps(m, m);
    __m128 yy = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(yy, sq));
    __m128 r = _mm_rsqrt_ss(len2);
    __m128 nr = _mm_mul_ss(_mm_mul_ss(len2, r), r);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, nr));
    inv = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), inv);
    __m128 n = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m);
    _mm_store_ps((float*)dst, n);
    _mm_store_ps((float*)dst, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(pw), _mm_load_ss(pw), 0), n));
}
struct OutputPair
{
    __m128 first;
    __m128 second;
};
static __forceinline void SecondMidpoint(OutputPair* dst, __m128 m, const float* pw)
{
    __m128 zero = _mm_set_ss(0.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 three = _mm_set_ss(3.0f);
    dst->second = m;
    __m128 sq = _mm_mul_ps(m, m);
    __m128 yy = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(yy, sq));
    __m128 r = _mm_rsqrt_ss(len2);
    __m128 nr = _mm_mul_ss(_mm_mul_ss(len2, r), r);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, nr));
    inv = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), inv);
    __m128 n = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m);
    dst->second = n;
    dst->second = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(pw), _mm_load_ss(pw), 0), dst->second);
}

template <class Array> static __forceinline void SubdivExpand(Array* array, int amount)
{
    AllocatorHolder* holder = (AllocatorHolder*)FUN_00c85750();
    void* alloc = holder->m_pAllocator;
    int need = array->m_uiItemCount + amount;
    int cap = array->m_capFlags & 0x3fffffffu;
    if (cap < need)
    {
        int newCap = cap + cap;
        if (need < newCap)
            need = newCap;
        ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(array), need, 16);
    }
    array->m_uiItemCount += amount;
}

// @fnv 0x00e0afe0
void __cdecl FUN_00e0afe0(SubdivMesh* self, int idx, float w, float t)
{
    if (t == 0.0f)
    {
        return;
    }

    for (;;)
    {
        int oldV = self->m_verts.m_uiItemCount;
        int oldT = self->m_tris.m_uiItemCount;
        SubdivExpand(&self->m_verts, 3);
        SubdivExpand(&self->m_tris, 3);

        SubdivTri* original = &self->m_tris.m_data[idx];
        hkVector4* V = self->m_verts.m_data;
        const __m128& p0 = V[original->a].m_vComponents;
        const __m128& p1 = V[original->b].m_vComponents;
        const __m128& p2 = V[original->c].m_vComponents;

        __m128* mid = &V[oldV].m_vComponents;
        __m128* mid2 = &V[oldV + 2].m_vComponents;
        SubdivMidpoint(mid, _mm_add_ps(p1, p0), &w);
        SecondMidpoint((OutputPair*)mid, _mm_add_ps(p2, p1), &w);
        SubdivMidpoint(mid2, _mm_add_ps(p2, p0), &w);

        SubdivTri* T = self->m_tris.m_data;
        SubdivTri* T0 = &T[oldT];
        SubdivTri* T2 = &T[oldT + 2];
        T0->a = original->a;
        T0->b = oldV;
        T0->c = oldV + 2;
        *(volatile int*)&T0[1].a = oldV;
        T0[1].b = original->b;
        T0[1].c = oldV + 1;
        T2->a = oldV + 2;
        T2->b = oldV + 1;
        T2->c = original->c;
        original->a = oldV;
        original->b = oldV + 1;
        original->c = oldV + 2;

        double t1 = t - 1.0;
        FUN_00e0afe0(self, oldT, w, t1);
        FUN_00e0afe0(self, oldT + 1, w, t1);
        FUN_00e0afe0(self, oldT + 2, w, t1);
        t = t1;
        if (t == 0.0f)
        {
            break;
        }
    }
}


extern "C" void _ReadWriteBarrier();

extern double DAT_010ea650;
extern double DAT_010ea648;

struct SphereBuildAllocator
{
    virtual ~SphereBuildAllocator();
    virtual void* Alloc(int size);
};

struct SphereBuildMemory
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    SphereBuildAllocator* m_10;
};

SphereBuildMemory* __cdecl FUN_00c85750();

struct SphereBuildVertex
{
    ::__m128 q;
    __forceinline void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
};

struct SphereBuildVertices
{
    SphereBuildVertex* volatile m_pData;
    int m_iArrayLength;
    int m_iCap;
};

struct SphereBuildFace
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

inline void SphereBuildSetFace(SphereBuildFace* f, int a, int b, intptr_t c)
{
    f->m_00 = a;
    f->m_04 = b;
    f->m_08 = c;
    f->m_0c = -1;
}

struct SphereBuildFaces
{
    SphereBuildFace* m_pData;
    intptr_t m_iArrayLength;
    int m_iCap;
};

struct SphereBuildGeometry
{
    SphereBuildVertices verts;
    SphereBuildFaces faces;
};


struct SphereMeshBuilder
{
    int m_00;
    int m_04;
    SphereBuildGeometry* m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    float m_6c;
    void FUN_00e0b360();
};

// @fnv 0x00e0b360
__declspec(noinline) void SphereMeshBuilder::FUN_00e0b360()
{
    SphereBuildMemory* holder = FUN_00c85750();
    SphereBuildGeometry* raw = (SphereBuildGeometry*)holder->m_10->Alloc(0x18);
    SphereBuildGeometry* geo;
    SphereBuildVertex* zero;
    if (raw)
    {
        raw->verts.m_pData = 0;
        raw->verts.m_iArrayLength = 0;
        raw->verts.m_iCap = (int)0x80000000;
        zero = (SphereBuildVertex* const&)raw->verts.m_pData;
        raw->faces.m_pData = (SphereBuildFace*)zero;
        raw->faces.m_iArrayLength = (intptr_t)zero;
        raw->faces.m_iCap = (int)0x80000000;
        geo = raw;
    }
    else
    {
        geo = 0;
        zero = 0;
    }
    m_08 = geo;
    _ReadWriteBarrier();
    float v = m_6c;
    float s = (float)(v * DAT_010ea650);
    float t = (float)(v * DAT_010ea648);
    _ReadWriteBarrier();
    SphereBuildMemory* vertexHolder = FUN_00c85750();
    SphereBuildAllocator* va = vertexHolder->m_10;
    _ReadWriteBarrier();
    if ((geo->verts.m_iCap & 0x3fffffff) < 12)
    {
        int nc = (geo->verts.m_iCap & 0x3fffffff) + (geo->verts.m_iCap & 0x3fffffff);
        if (nc <= 12)
            nc = 12;
        ::FUN_00c908c0((::SpawnedObject *)(va), (::SpawnedArray *)(void *)(&geo->verts), nc, 0x10);
    }
    geo->verts.m_iArrayLength = 12;
    ((SphereBuildVertex* const&)geo->verts.m_pData)[0].set(-s, 0.0f, t, 0.0f);
    geo->verts.m_pData[1].set(s, 0.0f, t, 0.0f);
    {
        SphereBuildVertex* dst = (SphereBuildVertex* const&)geo->verts.m_pData + 2;
        __assume(((uintptr_t)dst & 15) == 0);
        dst->set(-s, 0.0f, -t, 0.0f);
    }
    geo->verts.m_pData[3].set(s, 0.0f, -t, 0.0f);
    geo->verts.m_pData[4].set(0.0f, t, s, 0.0f);
    geo->verts.m_pData[5].set(0.0f, t, -s, 0.0f);
    geo->verts.m_pData[6].set(0.0f, -t, s, 0.0f);
    geo->verts.m_pData[7].set(0.0f, -t, -s, 0.0f);
    geo->verts.m_pData[8].set(t, s, 0.0f, 0.0f);
    geo->verts.m_pData[9].set(-t, s, 0.0f, 0.0f);
    ((SphereBuildVertex* const&)geo->verts.m_pData)[10].set(t, -s, 0.0f, 0.0f);
    geo->verts.m_pData[11].q = _mm_setr_ps(-t, -s, 0.0f, 0.0f);
    SphereBuildFaces* fv = &((SphereBuildGeometry*)m_08)->faces;
    SphereBuildMemory* faceHolder = FUN_00c85750();
    SphereBuildAllocator* fa = faceHolder->m_10;
    _ReadWriteBarrier();
    if ((fv->m_iCap & 0x3fffffff) < 20)
    {
        int nc2 = (fv->m_iCap & 0x3fffffff) + (fv->m_iCap & 0x3fffffff);
        if (nc2 <= 20)
            nc2 = 20;
        ::FUN_00c908c0((::SpawnedObject *)(fa), (::SpawnedArray *)(fv), nc2, 0x10);
    }
    fv->m_iArrayLength = 20;
    SphereBuildSetFace(fv->m_pData + 0, 1, 4, (intptr_t)zero);
    SphereBuildSetFace(fv->m_pData + 1, 4, 9, (intptr_t)zero);
    SphereBuildSetFace(fv->m_pData + 2, 4, 5, 9);
    SphereBuildSetFace(fv->m_pData + 3, 8, 5, 4);
    SphereBuildSetFace(fv->m_pData + 4, 1, 8, 4);
    SphereBuildSetFace(fv->m_pData + 5, 1, 10, 8);
    SphereBuildSetFace(fv->m_pData + 6, 10, 3, 8);
    SphereBuildSetFace(fv->m_pData + 7, 8, 3, 5);
    SphereBuildSetFace(fv->m_pData + 8, 3, 2, 5);
    SphereBuildSetFace(fv->m_pData + 9, 3, 7, 2);
    SphereBuildSetFace(fv->m_pData + 10, 3, 10, 7);
    SphereBuildSetFace(fv->m_pData + 11, 10, 6, 7);
    SphereBuildSetFace(fv->m_pData + 12, 6, 11, 7);
    SphereBuildSetFace(fv->m_pData + 13, 6, 0, 11);
    SphereBuildSetFace(fv->m_pData + 14, 6, 1, 0);
    SphereBuildSetFace(fv->m_pData + 15, 10, 1, 6);
    SphereBuildSetFace(fv->m_pData + 16, 11, 0, 9);
    SphereBuildSetFace(fv->m_pData + 17, 2, 11, 9);
    SphereBuildSetFace(fv->m_pData + 18, 5, 2, 9);
    SphereBuildSetFace(fv->m_pData + 19, 11, 2, 7);
    for (int i = 0; i < 20; ++i)
        ::FUN_00e0afe0((::SubdivMesh *)(m_08), i, v, 2.0f);
}

#include "generated/data/havok/common/visualize/shape/hkdisplaysphere.inc"
