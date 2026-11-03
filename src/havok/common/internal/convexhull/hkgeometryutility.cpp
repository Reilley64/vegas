
// src/havok/common/internal/convexhull/hkgeometryutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkgeometryutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv_simd.h"
#include "fnv/decl/FUN_00d5d660_cls.h"
#include "fnv/symbols_00d5c000.h"
#include "fnv/symbols_01011000.h"
#include <xmmintrin.h>
#include <cmath>
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/decl/FUN_00cb21e0_shell.h"
#include "fnv/decl/hkMatrix3.h"
#include "fnv/symbols_01071000.h"
#include <new>
#include "fnv/decl/D76250Shape.h"
#include "fnv/decl/FUN_00cce530.h"
#include "fnv/decl/FUN_00d74d40_cls.h"
#include "fnv/decl/FUN_00d76990_Class.h"
#include "fnv/decl/H77ConvexHull.h"
#include "fnv/decl/S_00d76410_Builder.h"
#include "fnv/decl/fnv_00d76940__FUN_00d76940_cls.h"
#include "fnv/decl/fnv_00d76ca0__FUN_00d76ca0.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d5a000.h"
#include "fnv/symbols_00dd6000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_0106e000.h"
struct FUN_00d5a5e0_ctxA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;

};

struct FUN_00d5a5e0_ctxB
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

};

// Initializes two context objects, looks up a1 in the first, and if found calls SetB with 0 and a2, then finishes.
// @fnv 0x00d5a5e0
void __cdecl InitAndSetB(void* a1, intptr_t a2)
{
    FUN_00d5a5e0_ctxB b;
    FUN_00d5a5e0_ctxA a;

    new ((void *)&(a)) ::fnv_00d76ca0::FUN_00d76ca0();
    reinterpret_cast<::FUN_00d74d40_cls *>(&(b))->FUN_00d74d40();
    b.m_00 = 1;
    if (reinterpret_cast<::H77ConvexHull *>(&(a))->FUN_00d77200((*(const ::H77StridedVertices *)(a1)), (intptr_t)(&b)) != -1)
    {
        reinterpret_cast<::S_00d76410_Builder *>(&(a))->FUN_00d76410(0, (*(::S_00d76410_Geometry *)(a2)));
    }
    reinterpret_cast<::fnv_00d76940::FUN_00d76940_cls *>(&(a))->FUN_00d76940();
}

struct FUN_00d5a630_ctxA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;

};

struct FUN_00d5a630_ctxB
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

};


// Initialises two context objects, sets a flag, looks up a1 in the first context and, if found, applies a2 and a3 and a float constant before finishing.
// @fnv 0x00d5a630
void __cdecl FUN_00d5a630(void* a1, intptr_t a2, intptr_t a3)
{
    FUN_00d5a630_ctxB b;
    FUN_00d5a630_ctxA a;

    new ((void *)&(a)) ::fnv_00d76ca0::FUN_00d76ca0();
    reinterpret_cast<::FUN_00d74d40_cls *>(&(b))->FUN_00d74d40();
    b.m_00 = 1;
    if (reinterpret_cast<::H77ConvexHull *>(&(a))->FUN_00d77200((*(const ::H77StridedVertices *)(a1)), (intptr_t)(&b)) != -1)
    {
        reinterpret_cast<::S_00d76410_Builder *>(&(a))->FUN_00d76410(0, (*(::S_00d76410_Geometry *)(a2)));
        reinterpret_cast<::FUN_00d76990_Class *>(&(a))->SetValue(DAT_0106ea1c, 0);
        reinterpret_cast<::D76250Shape *>(&(a))->CopyVerticesToArray((*(::D76250VectorArray *)(a3)));
    }
    reinterpret_cast<::fnv_00d76940::FUN_00d76940_cls *>(&(a))->FUN_00d76940();
}

struct S_00d5a6b0_Elem
{
    float x;
    float y;
    float z;
    float w;
};

struct S_00d5a6b0_Array
{
    S_00d5a6b0_Elem* m_data;
    int m_iElementCount;
};

// Subtracts val from the w component of every element in the array.
// @fnv 0x00d5a6b0
void SubtractFromW(S_00d5a6b0_Array* pArray, float val)
{
    for (int i = 0; i < pArray->m_iElementCount; ++i)
        pArray->m_data[i].w -= val;
}

struct D5C110Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct D5C110MemoryRouter
{
    intptr_t unk00;
    int unk04;
    int unk08;
    int unk0C;
    D5C110Allocator* m_pStreamAllocator;

    D5C110Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D5C110MemoryRouter& __cdecl FUN_00c85750();

struct D5C110Vector4
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

// hkArray<hkVector4> without a destructor (Havok was built without EH): explicit cleanup.
struct D5C110VertexArray
{
    D5C110Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D5C110VertexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        D5C110Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(D5C110Vector4));
    }
};

struct D5C110StridedVertices
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};

struct D5C110Geometry
{
    int unk00;
    int m_iStridedVertexCount;
    int unk08;
    int unk0C;
    int m_iTriangleCount;
};


// @fnv 0x00d5c110
void __cdecl BuildGeometryFromShape(const void* shape, D5C110Geometry& aGeometry)
{
    D5C110VertexArray vertices;
    ::ProcessArg((::Arg *)(shape), (intptr_t)&(vertices));
    if (vertices.m_iElementCount > 0)
    {
        D5C110StridedVertices stridedVertices;
        stridedVertices.m_iStridedVertexCount = vertices.m_iElementCount;
        stridedVertices.m_kVertices = &vertices.m_data->m_uiX;
        stridedVertices.m_iVertexStride = sizeof(D5C110Vector4);
        ::InitAndSetB((void *)&(stridedVertices), (intptr_t)&(aGeometry));
    }
    else
    {
        aGeometry.m_iTriangleCount = 0;
        aGeometry.m_iStridedVertexCount = 0;
    }
    vertices.ClearAndRelease();
}

struct D5C110VertexArray;

// @fnv 0x00d5a6a0
void __cdecl FUN_00d5a6a0(const void* shape, D5C110VertexArray& vertices)
{
    ::ProcessArg((::Arg *)(shape), (intptr_t)&(vertices));
}

#include <math.h>
struct S00d5ad60_cls
{
    float m_f00;
    unsigned char S00d5ad60_call(float* other, float threshold);
};

// Returns whether the absolute difference between m_f00 and *other is less than threshold.
// @fnv 0x00d5ad60
static __declspec(noinline) unsigned char FUN_00d5ad60(S00d5ad60_cls* self, float* other, float threshold)
{
    float d = *other - self->m_f00;
    d = fabs(d);
    return d < threshold;
}

unsigned char S00d5ad60_cls::S00d5ad60_call(float* other, float threshold)
{
    return FUN_00d5ad60(this, other, threshold);
}

#ifndef _INCLUDED_MM2

#include "fnv/symbols_simd.h"
#endif
#ifndef _INCLUDED_MM2

#endif
extern float DAT_01011d78;

// Checks whether the maximum absolute value of pVec[0..2] differs from 1.0 by less than fTol.
// @fnv 0x00d5ad90
static __declspec(noinline) int FUN_00d5ad90(const float* pVec, float fTol)
{
    float a2 = fabs(pVec[2]);
    float a1 = fabs(pVec[1]);
    float a0 = fabs(pVec[0]);
    __m128 v = _mm_setr_ps(a0, a1, a2, DAT_01011d78);
    float fMaxAbs = (fnv_simd_as<float>(v)[0] > fnv_simd_as<float>(v)[1]) ? fnv_simd_as<float>(v)[0] : fnv_simd_as<float>(v)[1];
    if (fnv_simd_as<float>(v)[2] > fMaxAbs)
        fMaxAbs = fnv_simd_as<float>(v)[2];
    float fDeviation = fabs((float)(fMaxAbs - 1.0));
    if (fDeviation < fTol)
        return 1;
    return 0;
}

int __cdecl S00d5ad90_Wrap(const float* pVec, float fTol)
{
    return FUN_00d5ad90(pVec, fTol);
}

struct S00d5c060_Src
{
    char* m_pData;
    int m_uiItemCount;
    int m_iElementIndex;
};

struct S00d5c060_Vec3
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    unsigned int unk0C;
};

struct __declspec(align(16)) S00d5c060_Result
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

char* __cdecl AllocateWithHeader(D5C110Allocator* alloc, intptr_t size);
char* __cdecl FUN_00c856c0(D5C110Allocator* owner, char* data);

// Allocates a buffer, copies vertex coordinates from src->m_pData into it, and passes it to FUN_00d5beb0 to produce a result.
// @fnv 0x00d5c060
S00d5c060_Result FUN_00d5c060(const S00d5c060_Src* src, float scale)
{
    S00d5c060_Result result;
    int count = src->m_uiItemCount;
    char* data = AllocateWithHeader(&FUN_00c85750().heap(), count * 16);
    int quad = src->m_iElementIndex / 4;
    S00d5c060_Vec3* d = (S00d5c060_Vec3*)data;
    for (int i = 0; i < src->m_uiItemCount; ++i)
    {
        d[i].m_uiX = ((const float*)src->m_pData)[i * quad];
        d[i].m_uiY = ((const float*)src->m_pData)[i * quad + 1];
        d[i].m_uiZ = ((const float*)src->m_pData)[i * quad + 2];
    }
    ::FUN_00d5beb0((::__m128 *)(::S00d5c060_Result *)(&result), (::MyPoint *)(data), src->m_uiItemCount, 0, scale);
    FUN_00c856c0(&FUN_00c85750().heap(), data);
    return result;
}

namespace fnv_00d5d270 {
#ifndef _INCLUDED_MM2

#endif
#ifndef _INCLUDED_MM2

#endif

extern float DAT_01011d78;
extern float DAT_01012068;
extern "C" int ae60_mix(intptr_t);
extern "C" void _ReadWriteBarrier(void);

struct S4
{
    intptr_t v;
    S4(intptr_t x) : v(x)
    {}
};

struct ObbVec
{
    __m128 q;
    float x() const
    {
        return fnv_simd_as<float>(q)[0];
    }
    float y() const
    {
        return fnv_simd_as<float>(q)[1];
    }
    float z() const
    {
        return fnv_simd_as<float>(q)[2];
    }
};

struct ObbRot
{
    ObbVec c0;
    ObbVec c1;
    ObbVec c2;
};

struct ObbXf
{
    ObbVec c0;
    ObbVec c1;
    ObbVec c2;
    ObbVec c3;
};

struct ObbFrame
{
    ObbVec ext1;
    ObbVec ext0;
    ObbVec ctr1;
    ObbVec ctr0;
    ObbRot rot0;
    ObbRot rot1;
    ObbRot cov;
};

struct ObbTri
{
    int i0;
    int i1;
    int i2;
    int i3;
};

struct ObbGeom
{
    ObbVec* verts;
    int numVerts;
    int vcap;
    ObbTri* tris;
    int numTris;
    int tcap;

    ObbGeom() : verts(0), numVerts(0), vcap(0x80000000), tris(0), numTris(0), tcap(0x80000000)
    {}
};

struct ObbArr
{
    ObbVec* m_data;
    int m_iElementCount;
    int m_cap;
    char* m_pTrailingData;

    ObbArr() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
};

struct ObbFlag
{
    char c;
};

void __cdecl FUN_00d5c1a0(void*, int, int, void*, void*, ObbFlag);
void __cdecl FUN_00d5ac50(void*, void*, void*, void*, void*);

static __declspec(noinline) void FUN_00d5ae60(const char* verts, const char* mat, int count, int stride, S4 extents,
                                              S4 center)
{
    int n = count / 3;
    const char* p = verts;
    const char* end = p + n * 16;
    float acc = 0;
    while (p != end)
    {
        acc += *(const float*)p + *(const float*)mat;
        p += 16;
    }
    n = ae60_mix(n) + n;
    *(float*)extents.v = acc + *(const float*)(mat + 16) + (float)n;
    *(int*)center.v = stride;
}

static __declspec(noinline) float FUN_00d5b990(S4 verts, S4 count, S4 src, int steps, int stride, char* dest)
{
    *(int*)dest = stride + steps;
    intptr_t acc = verts.v + count.v + src.v + steps + stride + (intptr_t)dest;
    return (float)(acc + ae60_mix(acc));
}

// Computes the oriented bounding box of a shape's triangle vertices, writing the half-extents and transform to outExt and outXf.
// @fnv 0x00d5d270
void FUN_00d5d270(const void* shape, ObbVec* outExt, ObbXf* outXf, int mode)
{
    ObbGeom geom;
    ::InitAndSetB((void *)&(*(const D5C110StridedVertices*)shape), (intptr_t)&(*(D5C110Geometry*)&geom));

    int nStack = geom.numTris * 3;
    ObbArr arr;
    D5C110MemoryRouter& router = FUN_00c85750();
    char* start = (char*)router.unk00;
    router.unk00 = (intptr_t)(start + ((nStack * 16 + 0x7f) & ~0x7f));
    arr.m_cap = nStack | 0x80000000;
    arr.m_data = (ObbVec*)start;
    arr.m_pTrailingData = start;

    int total = geom.numTris * 3;
    D5C110Allocator& heap = FUN_00c85750().heap();
    if ((arr.m_cap & 0x3fffffff) < total)
    {
        int cap = (arr.m_cap & 0x3fffffff) * 2;
        if (total >= cap)
            cap = total;
        ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap), (::SpawnedArray *)(void *)(&arr.m_data), cap, 16);
    }
    arr.m_iElementCount = total;

    for (int i = 0; i < geom.numTris; i++)
    {
        arr.m_data[i * 3 + 0].q = geom.verts[geom.tris[i].i0].q;
        arr.m_data[i * 3 + 1].q = geom.verts[geom.tris[i].i1].q;
        arr.m_data[i * 3 + 2].q = geom.verts[geom.tris[i].i2].q;
    }

    if (reinterpret_cast<::ObbInput *>((&geom))->FUN_00d5c6d0((*(::ObbVec *)(outExt)), (*(::ObbXf *)(outXf)), ::DAT_01013ea4))
    {
        char* saved = arr.m_pTrailingData;
        if (saved == (char*)arr.m_data)
            arr.m_iElementCount = 0;
        FUN_00c85750().unk00 = (intptr_t)saved;
        D5C110Allocator& alloc = FUN_00c85750().heap();
        arr.m_iElementCount = 0;
        if ((arr.m_cap & 0x80000000) == 0)
            alloc.ReturnMemory(arr.m_data, (arr.m_cap & 0x3fffffff) * 16);
        arr.m_cap = 0x80000000;
        arr.m_data = 0;
        reinterpret_cast<::FUN_00cce530 *>(&(geom))->FUN_00cce530::~FUN_00cce530();
        return;
    }

    const char* data = (const char*)arr.m_data;
    int count = arr.m_iElementCount;

    ObbFrame f;
    f.rot0.c0.q = _mm_setr_ps(DAT_01012068, DAT_01011d78, DAT_01011d78, DAT_01011d78);
    f.rot0.c1.q = _mm_setr_ps(DAT_01011d78, DAT_01012068, DAT_01011d78, DAT_01011d78);
    f.rot0.c2.q = _mm_setr_ps(DAT_01011d78, DAT_01011d78, DAT_01012068, DAT_01011d78);

    FUN_00d5ae60(data, (const char*)&f.rot0, count, 16, S4((intptr_t)&f.ext0), S4((intptr_t)&f.ctr0));
    float vol0 = f.ext0.y() * f.ext0.x() * f.ext0.z();
    ObbFlag flag;
    flag.c = 0;
    FUN_00d5c1a0((void*)data, count, 16, &f.cov, &f.ctr1, flag);
    char ok;
    FUN_00d5ac50(&ok, &f.cov, &f.rot1.c0, &f.rot1.c1, &f.rot1.c2);
    FUN_00d5ae60(data, (const char*)&f.rot1, count, 16, S4((intptr_t)&f.ext1), S4((intptr_t)&f.ctr1));
    float vol1 = f.ext1.y() * f.ext1.x() * f.ext1.z();

    if (mode == 2)
    {
        vol0 = FUN_00d5b990(S4((intptr_t)data), S4(count), S4((intptr_t)&f.rot0), 20, 16, (char*)&f.rot0);
        FUN_00d5ae60(data, (const char*)&f.rot0, count, 16, S4((intptr_t)&f.ext0), S4((intptr_t)&f.ctr0));
        vol1 = FUN_00d5b990(S4((intptr_t)data), S4(count), S4((intptr_t)&f.rot1), 20, 16, (char*)&f.rot1);
        FUN_00d5ae60(data, (const char*)&f.rot1, count, 16, S4((intptr_t)&f.ext1), S4((intptr_t)&f.ctr1));
    }

    __m128 vPickedCtr;
    ObbRot* pickedRot;
    if (vol0 < vol1)
    {
        vPickedCtr = f.ctr0.q;
        pickedRot = &f.rot0;
        outExt->q = f.ext0.q;
    }
    else
    {
        vPickedCtr = f.ctr1.q;
        pickedRot = &f.rot1;
        outExt->q = f.ext1.q;
    }
    __m128 vCol0 = pickedRot->c0.q;
    __m128 vCol1 = pickedRot->c1.q;
    __m128 vCol2 = pickedRot->c2.q;
    _ReadWriteBarrier();
    outXf->c0.q = vCol0;
    outXf->c1.q = vCol1;
    outXf->c2.q = vCol2;
    outXf->c3.q = vPickedCtr;

    char* saved = arr.m_pTrailingData;
    if (saved == (char*)arr.m_data)
        arr.m_iElementCount = 0;
    FUN_00c85750().unk00 = (intptr_t)saved;
    D5C110Allocator& alloc2 = FUN_00c85750().heap();
    arr.m_iElementCount = 0;
    if ((arr.m_cap & 0x80000000) == 0)
        alloc2.ReturnMemory(arr.m_data, (arr.m_cap & 0x3fffffff) * 16);
    arr.m_cap = 0x80000000;
    arr.m_data = 0;
    reinterpret_cast<::FUN_00cce530 *>(&(geom))->FUN_00cce530::~FUN_00cce530();
}
}  // namespace fnv_00d5d270


struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct MyPoint
{
    __m128 v;
};

// FUN_00d5bb10, FUN_00d5bb80 and FUN_00d5bce0 are stand-ins: the real 2-, 3- and 4-point sphere builders live
// elsewhere. Their bodies only keep the static calling sequence the original uses; FUN_00d5beb0 is the function compared.
static __declspec(noinline) Vec4* FUN_00d5bb10(Vec4* res, Vec4* p0, Vec4* p1, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(intptr_t)p1;
    res->w = a.y;
    return res;
}

static __declspec(noinline) Vec4* FUN_00d5bb80(Vec4* res, Vec4* p0, Vec4* p1, Vec4* p2, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(intptr_t)p1 + (float)(intptr_t)p2;
    res->w = a.y;
    return res;
}

static __declspec(noinline) Vec4* FUN_00d5bce0(Vec4* res, Vec4* p0, Vec4* p1, Vec4* p2, Vec4* p3, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(intptr_t)p1 + (float)(intptr_t)p2 + (float)(intptr_t)p3;
    res->w = a.y;
    return res;
}

// Moves points whose XYZ distance from out exceeds out[3] to the front, then recurses on the preceding points.
// @fnv 0x00d5beb0
__m128* __cdecl FUN_00d5beb0(__m128* apResult, MyPoint* apPoints, int count, int depth, float t)
{
    Vec4 rTempA;
    Vec4 rTempB;
    Vec4 rTempC;

    switch (depth)
    {
    case 0:
        *(__m128*)&rTempA = _mm_setzero_ps();
        rTempA.w = DAT_01012054;
        *apResult = *(__m128*)&rTempA;
        break;
    case 1:
        *(__m128*)&rTempA = apPoints[-1].v;
        rTempA.w = t;
        *apResult = *(__m128*)&rTempA;
        break;
    case 2:
        *apResult = *(__m128*)FUN_00d5bb10(&rTempA, (Vec4*)&apPoints[-1], (Vec4*)&apPoints[-2], t);
        break;
    case 3:
        *apResult =
            *(__m128*)FUN_00d5bb80(&rTempB, (Vec4*)&apPoints[-1], (Vec4*)&apPoints[-2], (Vec4*)&apPoints[-3], t);
        break;
    default:
        *apResult = *(__m128*)FUN_00d5bce0(&rTempC, (Vec4*)&apPoints[-1], (Vec4*)&apPoints[-2], (Vec4*)&apPoints[-3],
                                           (Vec4*)&apPoints[-4], t);
        return apResult;
    }

    for (int i = 0; i < count; ++i)
    {
        __m128 rDiff = _mm_sub_ps(apPoints[i].v, *apResult);
        __m128 rSq = _mm_mul_ps(rDiff, rDiff);
        __m128 rShuf1 = _mm_shuffle_ps(rSq, rSq, 0x55);
        __m128 rShuf2 = _mm_shuffle_ps(rSq, rSq, 0xaa);
        __m128 sum = _mm_add_ss(rShuf1, rSq);
        sum = _mm_add_ss(rShuf2, sum);
        float dist;
        _mm_store_ss(&dist, _mm_sqrt_ss(sum));

        if (dist > ((const float*)apResult)[3])
        {
            for (int iSwap = i; iSwap > 0; --iSwap)
            {
                rTempA = *(Vec4*)&apPoints[iSwap];
                apPoints[iSwap].v = apPoints[iSwap - 1].v;
                apPoints[iSwap - 1].v = *(__m128*)&rTempA;
            }

            *apResult = *FUN_00d5beb0((__m128*)&rTempB, apPoints + 1, i, depth + 1, t);
        }
    }

    return apResult;
}


class ObbScalar
{
    __m128 val;

  public:
    __forceinline ObbScalar(__m128 x) : val(x)
    {}
    __forceinline ObbScalar(float x) : val(_mm_load_ss(&x))
    {}
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(val, val, 0);
    }
    __forceinline __m128 quad() const
    {
        return val;
    }
    __forceinline operator float() const
    {
        float x;
        _mm_store_ss(&x, val);
        return x;
    }
};
class ObbAxis
{
    __m128 val;

  public:
    __forceinline ObbAxis()
    {}
    __forceinline ObbAxis(const ObbAxis& a) : val(a.val)
    {}
    __forceinline void operator=(const ObbAxis& a)
    {
        val = a.val;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&val)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&val)[i];
    }
    __forceinline void addScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_add_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline void subtractScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_sub_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline ObbScalar dot(const ObbAxis& a) const
    {
        __m128 p = _mm_mul_ps(val, a.val);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }
    __forceinline void cross(const ObbAxis& a, const ObbAxis& b)
    {
        __m128 u = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xc9), _mm_shuffle_ps(b.val, b.val, 0xd2));
        __m128 v = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xd2), _mm_shuffle_ps(b.val, b.val, 0xc9));
        val = _mm_sub_ps(u, v);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_load_ss(&kHalf), three = _mm_load_ss(&kThree), zero = _mm_load_ss(&kZero);
        __m128 d = dot(*this).quad();
        __m128 mask = _mm_cmpeq_ss(d, zero);
        __m128 r = _mm_rsqrt_ss(d);
        __m128 q = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(d, r), r)));
        __m128 inv = _mm_andnot_ps(mask, q);
        val = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), val);
    }
    static const float kHalf, kThree, kZero;
};
const float ObbAxis::kHalf = 0.5f, ObbAxis::kThree = 3.0f, ObbAxis::kZero = 0.0f;
struct ObbWord
{
    intptr_t v;
    ObbWord(intptr_t x) : v(x)
    {}
    operator int() const
    {
        return v;
    }
};

extern "C" int obbMix(int);
static __declspec(noinline) void FUN_00d5ae60(const float* verts, int count, int stride, ObbWord ext,
                                              const ObbAxis* axes, ObbWord pos)
{
    int triangles = count / 3;
    const float* p = verts;
    const float* end = p + triangles * 4;
    float sum = 0.0f;
    while (p != end)
    {
        sum += p[0] + axes[0](0);
        p += 4;
    }
    int total = obbMix(triangles) + triangles;
    ((ObbAxis*)ext.v)->operator()(0) = sum + axes[1](0) + (float)total;
    ((ObbAxis*)pos.v)->operator()(0) = (float)stride;
}

static __declspec(noinline) float FUN_00d5b0c0(const float* verts, int count, int stride, const ObbAxis* axes)
{
    ObbAxis tmp[3];
    tmp[0] = axes[0];
    tmp[1] = axes[1];
    tmp[0].normalize();
    float projection = axes[0].dot(axes[1]);
    tmp[1].subtractScaled(projection, axes[0]);
    tmp[1].normalize();
    tmp[2].cross(axes[0], axes[1]);
    tmp[2].normalize();
    ObbAxis position, extents;
    FUN_00d5ae60(verts, count, stride, ObbWord((intptr_t)&extents), tmp, ObbWord((intptr_t)&position));
    return extents(1) * extents(0) * extents(2);
}
static __declspec(noinline) void FUN_00d5b440(const ObbAxis* axes, ObbAxis* direction, float step, ObbAxis* out)
{
    for (int i = 0; i < 2; ++i)
    {
        out[i] = axes[i];
        out[i].addScaled(step, direction[i]);
    }
    out[0].normalize();
    float projection = out[0].dot(out[1]);
    out[1].subtractScaled(projection, out[0]);
    out[1].normalize();
    out[2].cross(out[0], out[1]);
    out[2].normalize();
}
inline float obbRoot(float f)
{
    return (float)sqrt((double)f);
}
// Finds the OBB step size along direction that minimizes the OBB volume using golden-section search, returning -1.0f on failure.
// @fnv 0x00d5b640
static __declspec(noinline) float FUN_00d5b640(const float* apVertices, int numVertices, int aiStride,
                                               const ObbAxis* axes, float afStep, ObbAxis* direction, int maxIter)
{
    float fb = 0;
    float fc = 0;
    float a = 0;
    float fa = FUN_00d5b0c0(apVertices, numVertices, aiStride, axes);
    ObbAxis tempAxes[3];
    FUN_00d5b440(axes, direction, afStep, tempAxes);
    float fTempVol = FUN_00d5b0c0(apVertices, numVertices, aiStride, tempAxes);
    float b, c;
    if (fTempVol < fa)
    {
        b = afStep;
        fb = fTempVol;
        c = b;
        for (int i = 0; i < maxIter; i++)
        {
            c *= double(1.2f);
            FUN_00d5b440(axes, direction, c, tempAxes);
            fc = FUN_00d5b0c0(apVertices, numVertices, aiStride, tempAxes);
            if (fb < fc)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (i == maxIter - 1)
                return c;
        }
    }
    else
    {
        c = afStep;
        fc = fTempVol;
        b = c;
        for (int i = 0; i < maxIter; i++)
        {
            b = (a + b) * 0.5;
            FUN_00d5b440(axes, direction, b, tempAxes);
            fb = FUN_00d5b0c0(apVertices, numVertices, aiStride, tempAxes);
            if (fb < fa && fb < fc)
                break;
            if (i == maxIter - 1)
                return -1.0f;
        }
    }
    if (a > b || b > c || fa < fb || fc < fb)
        return -1.0f;
    const float GoldenRatio = (3.0 - obbRoot(5.0f)) * 0.5;
    float fLenLeft, fLenRight, x, fx;
    for (int i = 0; i < maxIter; i++)
    {
        fLenLeft = b - a;
        fLenRight = c - b;
        if (fLenLeft > fLenRight)
        {
            x = b - GoldenRatio * fLenLeft;
            FUN_00d5b440(axes, direction, x, tempAxes);
            fx = FUN_00d5b0c0(apVertices, numVertices, aiStride, tempAxes);
            if (fx < fb)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + GoldenRatio * fLenRight;
            FUN_00d5b440(axes, direction, x, tempAxes);
            fx = FUN_00d5b0c0(apVertices, numVertices, aiStride, tempAxes);
            if (fx < fb)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}
const float* volatile obbVerts;
const ObbAxis* volatile obbAxes;
ObbAxis* volatile obbDir;
volatile int obbCount, obbStride, obbIter;
volatile float obbStep, obbAnswer;
void obbCaller()
{
    obbAnswer = FUN_00d5b640(obbVerts, obbCount, obbStride, obbAxes, obbStep, obbDir, obbIter);
}


extern const float DAT_010d1018 = 0.0000011920928955078125f;

struct S4
{
    int v;
    S4(int x) : v(x)
    {}
};

class AxisScalar
{
    __m128 value;

  public:
    AxisScalar(__m128 q) : value(q)
    {}
    AxisScalar(float f) : value(_mm_load_ss(&f))
    {}
    __forceinline __m128 quad() const
    {
        return value;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};

class Axis
{
    __m128 value;

  public:
    void operator=(const Axis& other)
    {
        value = other.value;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&value)[i];
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(float f)
    {
        AxisScalar s(f);
        value = s.splat();
    }
    __forceinline void mul4(const AxisScalar& s)
    {
        value = _mm_mul_ps(value, s.splat());
    }
    __forceinline void setMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_mul_ps(s.splat(), v.value);
    }
    __forceinline void addMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void subMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void setAdd4(const Axis& a, const Axis& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setSub4(const Axis& a, const Axis& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setCross(const Axis& a, const Axis& b)
    {
        __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline AxisScalar dot3(const Axis& v) const
    {
        __m128 product = _mm_mul_ps(value, v.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    }
    __forceinline AxisScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline AxisScalar lengthInverse3() const
    {
        const __m128 h = _mm_set_ss(0.5f);
        const __m128 t = _mm_set_ss(3.0f);
        const __m128 z = _mm_set_ss(0.0f);
        __m128 square = dot3(*this).quad();
        __m128 mask = _mm_cmpeq_ss(square, z);
        __m128 inv = _mm_rsqrt_ss(square);
        __m128 correction = _mm_mul_ss(_mm_mul_ss(h, inv), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(square, inv), inv)));
        return _mm_andnot_ps(mask, correction);
    }
    __forceinline void normalize3()
    {
        __m128 scale = lengthInverse3().splat();
        value = _mm_mul_ps(scale, value);
    }
};

__forceinline float axisSqrt(float f)
{
    AxisScalar s(f);
    return AxisScalar(_mm_sqrt_ss(s.quad()));
}
__forceinline float axisInvSqrt(float f)
{
    return 1.0f / axisSqrt(f);
}

static __declspec(noinline) void FUN_00d5ae60(const float* data, int count, int stride, Axis& size, const Axis* axes,
                                              Axis& center)
{
    Axis lower;
    lower.SetAllComponents(3.40282e38f);
    Axis upper;
    upper.SetAllComponents(-3.40282e38f);
    const float* vertex = data;
    for (int tri = 0; tri < count / 3; ++tri)
    {
        Axis point;
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
    }
    Axis midpoint;
    midpoint.setAdd4(upper, lower);
    midpoint.mul4(0.5f);
    size.setSub4(upper, lower);
    size.mul4(0.5f);
    center.setMul4(midpoint(0), axes[0]);
    center.addMul4(midpoint(1), axes[1]);
    center.addMul4(midpoint(2), axes[2]);
}

static __declspec(noinline) float FUN_00d5b0c0(const float* data, int count, int stride, const Axis* axes)
{
    Axis adjusted[3];
    adjusted[0] = axes[0];
    adjusted[1] = axes[1];
    adjusted[0].normalize3();
    float projection = axes[0].dot3(axes[1]);
    adjusted[1].subMul4(projection, axes[0]);
    adjusted[1].normalize3();
    adjusted[2].setCross(axes[0], axes[1]);
    adjusted[2].normalize3();
    Axis center;
    Axis size;
    FUN_00d5ae60(data, count, stride, size, adjusted, center);
    return size(0) * size(1) * size(2);
}

static __declspec(noinline) void FUN_00d5b2a0(const float* data, int count, int stride, const Axis* axes, float delta,
                                              Axis* direction)
{
    Axis changed[3];
    changed[0] = axes[0];
    changed[1] = axes[1];
    float base = FUN_00d5b0c0(data, count, stride, axes);
    float invDelta = 1 / delta;
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            changed[row](col) += delta;
            float volume = FUN_00d5b0c0(data, count, stride, changed);
            direction[row](col) = (volume - base) * invDelta;
            changed[row](col) = axes[row](col);
        }
        direction[row].mul4(-1.0f);
    }
    float normSquared = direction[0].lengthSquared3() + direction[1].lengthSquared3();
    if (normSquared > 1.0)
    {
        float invNorm = axisInvSqrt(normSquared);
        direction[0].mul4(invNorm);
        direction[1].mul4(invNorm);
    }
}

static __declspec(noinline) void FUN_00d5b440(const Axis* input, Axis* direction, float step, Axis* output)
{
    for (int axis = 0; axis < 2; ++axis)
    {
        output[axis] = input[axis];
        output[axis].addMul4(step, direction[axis]);
    }
    output[0].normalize3();
    float projection = output[0].dot3(output[1]);
    output[1].subMul4(projection, output[0]);
    output[1].normalize3();
    output[2].setCross(output[0], output[1]);
    output[2].normalize3();
}

static __declspec(noinline) float FUN_00d5b640(const float* data, int count, int stride, const Axis* axes, float start,
                                               Axis* direction, int limit)
{
    float fb = 0, fc = 0;
    float a = 0;
    float fa = FUN_00d5b0c0(data, count, stride, axes);
    Axis changed[3];
    FUN_00d5b440(axes, direction, start, changed);
    float trial = FUN_00d5b0c0(data, count, stride, changed);
    float b, c;
    if (fa > trial)
    {
        b = start;
        fb = trial;
        c = b;
        for (int iter = 0; iter < limit; ++iter)
        {
            c *= 1.2f;
            FUN_00d5b440(axes, direction, c, changed);
            fc = FUN_00d5b0c0(data, count, stride, changed);
            if (fc > fb)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (iter == limit - 1)
                return c;
        }
    }
    else
    {
        c = start;
        fc = trial;
        b = c;
        for (int iter = 0; iter < limit; ++iter)
        {
            b = (a + b) * 0.5;
            FUN_00d5b440(axes, direction, b, changed);
            fb = FUN_00d5b0c0(data, count, stride, changed);
            if (fa > fb && fc > fb)
                break;
            if (iter == limit - 1)
                return -1.0f;
        }
    }
    if (!(a <= b && b <= c && fb <= fa && fb <= fc))
        return -1.0f;
    const float golden = (3.0 - axisSqrt(5.0f)) * 0.5;
    for (int iter = 0; iter < limit; ++iter)
    {
        float ab = b - a;
        float bc = c - b;
        float x, fx;
        if (bc < ab)
        {
            x = b - golden * ab;
            FUN_00d5b440(axes, direction, x, changed);
            fx = FUN_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + golden * bc;
            FUN_00d5b440(axes, direction, x, changed);
            fx = FUN_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}

// Iteratively adjusts the axes to reduce the measured volume using a finite-difference direction and golden-section search.
// @fnv 0x00d5b990
static __declspec(noinline) float FUN_00d5b990(const float* data, int count, int stride, const Axis* apInitialAxes,
                                               Axis* apResultAxes, int aiMaxIterations)
{
    float delta = 0.0001f;
    float step = 0.001f;
    float volume = FUN_00d5b0c0(data, count, stride, apInitialAxes);
    apResultAxes[0] = apInitialAxes[0];
    apResultAxes[1] = apInitialAxes[1];
    apResultAxes[2] = apInitialAxes[2];
    Axis previous[3];
    Axis direction[2];
    for (int iter = 0; iter < aiMaxIterations; ++iter)
    {
        previous[0] = apResultAxes[0];
        previous[1] = apResultAxes[1];
        previous[2] = apResultAxes[2];
        FUN_00d5b2a0(data, count, stride, apResultAxes, delta, direction);
        step = FUN_00d5b640(data, count, stride, apResultAxes, step, direction, aiMaxIterations);
        if (step < 0.0)
            break;
        FUN_00d5b440(apResultAxes, direction, step, apResultAxes);
        float lastVolume = volume;
        volume = FUN_00d5b0c0(data, count, stride, apResultAxes);
        if (lastVolume < volume)
        {
            volume = lastVolume;
            apResultAxes[0] = previous[0];
            apResultAxes[1] = previous[1];
            apResultAxes[2] = previous[2];
            break;
        }
        if (step < DAT_010d1018)
            break;
    }
    return volume;
}

const float* volatile probeData;
int volatile probeCount, probeStride, probeLimit;
Axis* volatile probeAxes;
Axis* volatile probeOutput;
volatile float probeSink;
void runProbe()
{
    probeSink = FUN_00d5b990(probeData, probeCount, probeStride, probeAxes, probeOutput, probeLimit);
}


namespace MeanCovIntrinsics {
}
struct MeanCovObbVec
{
    __m128 q;
    float& operator[](int i)
    {
        return ((float*)this)[i];
    }
    const float& operator[](int i) const
    {
        return ((const float*)this)[i];
    }
    float get(int i) const
    {
        return ((const float*)this)[i];
    }
    const float& ref(int i) const
    {
        return ((const float*)&q)[i];
    }
    __forceinline void setAdd(const MeanCovObbVec& x, const MeanCovObbVec& y)
    {
        q = _mm_add_ps(x.q, y.q);
    }
    __forceinline void addL(const MeanCovObbVec& x)
    {
        _mm_store_ps(
            (float*)this, _mm_add_ps(x.q, _mm_load_ps((const float*)this)));
    }
    __forceinline void addR(const MeanCovObbVec& x)
    {
        _mm_store_ps(
            (float*)this, _mm_add_ps(_mm_load_ps((const float*)this), x.q));
    }
    inline void addLi(const MeanCovObbVec& x)
    {
        _mm_store_ps(
            (float*)this, _mm_add_ps(x.q, _mm_load_ps((const float*)this)));
    }
    __forceinline void addV(__m128 x)
    {
        _mm_store_ps(
            (float*)this, _mm_add_ps(x, _mm_load_ps((const float*)this)));
    }
    __forceinline void setAddS(const MeanCovObbVec& x, const MeanCovObbVec& y)
    {
        _mm_store_ps((float*)this, _mm_add_ps(x.q, y.q));
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void load(const float* p)
    {
        set(p[0], p[1], p[2], 0.0f);
    }
};
struct MeanCovObbRot
{
    MeanCovObbVec c0, c1, c2;
    float& at(int row, int col)
    {
        return ((float*)this)[col * 4 + row];
    }
};
struct MeanCovObbFlag
{
    char c;
};
struct MeanCovObbStride
{
    int v;
};
struct MeanCovTrivialElements
{
};
struct MeanCovArrayLifecycle
{
    template <class T> static __forceinline void construct(T*, int, MeanCovTrivialElements)
    {}
    template <class T> static __forceinline void destruct(T*, int, MeanCovTrivialElements)
    {}
};
struct MeanCovArrayHeap
{
    __forceinline D5C110Allocator& get(const void*)
    {
        return FUN_00c85750().heap();
    }
};
template <class T> class MeanCovArrayBase
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline MeanCovArrayBase() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    __forceinline ~MeanCovArrayBase()
    {}
    __forceinline int capacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void reserve(D5C110Allocator& heap, int count)
    {
        int oldCapacity = capacity();
        if (oldCapacity < count)
        {
            int doubled = oldCapacity * 2;
            int chosen = count < doubled ? doubled : count;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap), (::SpawnedArray *)(void *)(this), chosen, sizeof(T));
        }
    }
    __forceinline T* expand(D5C110Allocator& heap, int count)
    {
        int previous = m_iElementCount;
        reserve(heap, m_iElementCount + count);
        MeanCovArrayLifecycle::construct(m_data + m_iElementCount, count, MeanCovTrivialElements());
        m_iElementCount += count;
        return m_data + previous;
    }
    __forceinline void clear()
    {
        MeanCovArrayLifecycle::destruct(m_data, m_iElementCount, MeanCovTrivialElements());
        m_iElementCount = 0;
    }
    __forceinline void release(D5C110Allocator& heap)
    {
        clear();
        if (!(m_cap & 0x80000000))
            heap.ReturnMemory(m_data, capacity() * sizeof(T));
        m_data = 0;
        m_cap = 0x80000000;
    }
};
template <class T, class Heap = MeanCovArrayHeap> class MeanCovTypedArray : public MeanCovArrayBase<T>
{
  public:
    __forceinline MeanCovTypedArray() : MeanCovArrayBase<T>()
    {}
    __forceinline ~MeanCovTypedArray()
    {
        ClearAndRelease();
    }
    __forceinline T* expandBy(int count)
    {
        return MeanCovArrayBase<T>::expand(Heap().get(this), count);
    }
    __forceinline void ClearAndRelease()
    {
        MeanCovArrayBase<T>::release(Heap().get(this));
    }
};
typedef MeanCovTypedArray<MeanCovObbVec> MeanCovObbArr;
struct MeanCovObbRandom
{
    int seed0, seed1;
};
static __forceinline __m128 MeanCovsplat(float x)
{
    __m128 r = _mm_load_ss(&x);
    return _mm_shuffle_ps(r, r, 0);
}
static __forceinline float MeanCovarea(__m128 e0, __m128 e1)
{
    __m128 t0 = _mm_shuffle_ps(e0, e0, 0xd2);
    __m128 t1 = _mm_shuffle_ps(e1, e1, 0xc9);
    __m128 p1 = _mm_mul_ps(t1, t0);
    __m128 u0 = _mm_shuffle_ps(e0, e0, 0xc9);
    __m128 u1 = _mm_shuffle_ps(e1, e1, 0xd2);
    __m128 cross = _mm_sub_ps(_mm_mul_ps(u1, u0), p1);
    __m128 sq = _mm_mul_ps(cross, cross);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    __m128 root = _mm_sqrt_ss(sum);
    float len;
    _mm_store_ss(&len, root);
    return len * 0.5;
}
// @fnv 0x00d5c1a0
extern "C" __declspec(noinline) void __cdecl FUN_00d5c1a0(const void* vertices, int count, MeanCovObbStride stride,
                                                          MeanCovObbRot* covariance, MeanCovObbVec* center,
                                                          MeanCovObbFlag perturb)
{
    int j, k;
    int n = count / 3;
    float totalArea = 0;
    MeanCovObbVec zero;
    zero.q = _mm_setzero_ps();
    MeanCovObbVec weighted;
    weighted.q = _mm_setzero_ps();
    MeanCovObbArr centroids;
    MeanCovObbVec* all = centroids.expandBy(n);
    covariance->c0.q = zero.q;
    covariance->c1.q = zero.q;
    covariance->c2.q = zero.q;
    const char* p = (const char*)vertices;
    for (int t = 0; t < n; t++)
    {
        MeanCovObbVec* centroid = &all[t];
        MeanCovObbVec a, b, c;
        a.load((const float*)p);
        p += stride.v;
        b.load((const float*)p);
        p += stride.v;
        c.load((const float*)p);
        p += stride.v;
        __m128 av = a.q;
        __m128 bv = b.q;
        float triangleArea;
        if (perturb.c)
        {
            MeanCovObbRandom random;
            random.seed0 = count;
            random.seed1 = count;
            MeanCovObbVec delta;
            reinterpret_cast<::FUN_00d5d660_cls *>(&(random))->NextFloat4((float *)&(delta));
            MeanCovObbVec moved;
            moved.q = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(MeanCovsplat(0.01f), delta.q), av), bv);
            MeanCovObbVec edge;
            edge.q = _mm_sub_ps(av, c.q);
            triangleArea = MeanCovarea(moved.q, edge.q);
        }
        else
        {
            MeanCovObbVec moved;
            moved.q = _mm_sub_ps(av, bv);
            MeanCovObbVec edge;
            edge.q = _mm_sub_ps(av, c.q);
            triangleArea = MeanCovarea(moved.q, edge.q);
        }
        if (triangleArea > 0)
        {
            totalArea += triangleArea;
            centroid->q = _mm_mul_ps(_mm_add_ps(_mm_add_ps(bv, av), c.q),
                                     MeanCovsplat(1.0f / 3.0f));
            {
                __m128 sa = MeanCovsplat(triangleArea);
                weighted.q = _mm_add_ps(_mm_mul_ps(sa, centroid->q), weighted.q);
            }
            const float* cj = (const float*)centroid;
            for (int j = 0; j < 3; j++, cj++)
            {
                for (int k = 0; k < 3; k++)
                {
                    covariance->at(j, k) +=
                        (9.0 * all[t][j] * all[t][k] + a[j] * a[k] + b.get(k) * b[j] + c.get(k) * c[j]) * triangleArea;
                }
            }
        }
        else
        {
            centroid->q = _mm_add_ps(bv, av);
            _mm_store_ps((float*)&all[t], _mm_add_ps(c.q, all[t].q));
            {
                __m128 s3 = MeanCovsplat(1.0f / 3.0f);
                _mm_store_ps((float*)centroid,
                                                _mm_mul_ps(s3, _mm_load_ps((const float*)centroid)));
            }
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    covariance->at(j, k) += b.get(k) * b[j] + a[j] * a[k] + c[k] * c[j];
                }
            }
        }
    }
    if (totalArea <= 0)
    {
        center->q = zero.q;
        covariance->c0.q = zero.q;
        covariance->c1.q = zero.q;
        covariance->c2.q = zero.q;
        covariance->c0[0] = 1;
        covariance->c1[1] = 1;
        covariance->c2[2] = 1;
    }
    else
    {
        float inv = 1.0f / totalArea;
        weighted.q = _mm_mul_ps(MeanCovsplat(inv), weighted.q);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                covariance->at(j, k) = covariance->at(j, k) / 12.0 - (weighted[j] * weighted[k]) * totalArea;
            }
        }
        center->q = weighted.q;
    }
}struct S_00d5ac50_R
{
    char v;
    S_00d5ac50_R()
    {}
};

struct __declspec(align(16)) S_00d5ac50_V
{
    float x, y, z, w;
};

struct S_00d5ac50_M
{
    S_00d5ac50_V c0, c1, c2;
};


S_00d5ac50_R FUN_00d5a6e0(S_00d5ac50_M& m, int iters);

static __forceinline __m128& S_q(S_00d5ac50_V& v)
{
    return reinterpret_cast<__m128&>(v);
}

static __forceinline void S_set(S_00d5ac50_V& v, float x, float y, float z, float w)
{
    S_q(v) = _mm_setr_ps(x, y, z, w);
}

// @fnv 0x00d5ac50
S_00d5ac50_R FUN_00d5ac50(S_00d5ac50_M& m, S_00d5ac50_V* p0, S_00d5ac50_V* p1, S_00d5ac50_V* p2)
{
    S_00d5ac50_R r = FUN_00d5a6e0(m, 30);
    S_00d5ac50_V& o0 = *p0;
    S_00d5ac50_V& o1 = *p1;
    S_00d5ac50_V& o2 = *p2;
    if (r.v == 0)
    {
        S_set(o0, 1.0f, 0.0f, 0.0f, 0.0f);
        S_set(o1, 0.0f, 1.0f, 0.0f, 0.0f);
        S_set(o2, 0.0f, 0.0f, 1.0f, 0.0f);
        return r;
    }
    S_q(o0) = S_q(m.c0);
    S_q(o1) = S_q(m.c1);
    S_q(o2) = S_q(m.c2);
    __m128 b = S_q(o1);
    __m128 a = S_q(o0);
    __m128 cr = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                           _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    __m128 pr = _mm_mul_ps(cr, S_q(o2));
    float det;
    _mm_store_ss(&det, _mm_add_ss(_mm_shuffle_ps(pr, pr, 0xaa), _mm_add_ss(_mm_shuffle_ps(pr, pr, 0x55), pr)));
    if (det < 0.0f)
    {
        S_q(o2) = _mm_xor_ps(S_q(o2), ::DAT_010c44d0);
    }
    return r;
}

struct S00d5bb80_hkSimdReal
{
    __m128 m_vValue;
    S00d5bb80_hkSimdReal(__m128 x) : m_vValue(x)
    {}
    S00d5bb80_hkSimdReal(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct S00d5bb80_hkVector4
{
    __m128 m_vComponents;
    void setSub4(const S00d5bb80_hkVector4& a, const S00d5bb80_hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const S00d5bb80_hkVector4& v1, const S00d5bb80_hkVector4& v2)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    S00d5bb80_hkSimdReal lengthSquared3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
    S00d5bb80_hkSimdReal length3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2)));
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void addMul4(const S00d5bb80_hkSimdReal& r, const S00d5bb80_hkVector4& a)
    {
        m_vComponents =
            _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents));
    }
    void mul4(const S00d5bb80_hkSimdReal& r)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, _mm_shuffle_ps(r.m_vValue, r.m_vValue, 0));
    }
    void setAdd4(const S00d5bb80_hkVector4& a, const S00d5bb80_hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const S00d5bb80_hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    float& operator()(int i)
    {
        return ((float*)this)[i];
    }
};

struct S00d5bb80_hkSphere
{
    S00d5bb80_hkVector4 m_pos;
};

// @fnv 0x00d5bb80
static __declspec(noinline) S00d5bb80_hkSphere
    FUN_00d5bb80(const S00d5bb80_hkVector4& a, const S00d5bb80_hkVector4& b, const S00d5bb80_hkVector4& c, float radius)
{
    S00d5bb80_hkVector4 ab;
    ab.setSub4(b, a);
    S00d5bb80_hkVector4 ac;
    ac.setSub4(c, a);
    S00d5bb80_hkVector4 center = a;
    S00d5bb80_hkVector4 n;
    n.setCross(ab, ac);
    float inv = 0.5 / float(n.lengthSquared3());
    S00d5bb80_hkVector4 c1;
    c1.setCross(n, ab);
    S00d5bb80_hkVector4 c2;
    c2.setCross(ac, n);
    S00d5bb80_hkVector4 t;
    t.setZero4();
    t.addMul4(ac.lengthSquared3(), c1);
    t.addMul4(ab.lengthSquared3(), c2);
    t.mul4(inv);
    float len = t.length3();
    S00d5bb80_hkSphere s;
    s.m_pos.setAdd4(center, t);
    s.m_pos(3) = len + radius;
    return s;
}


struct BoundsVector
{

    union
    {

        __m128 packed;

        float component[4];
    };
};

static __forceinline __m128 SplatScalar(float value)
{

    __m128 scalar = _mm_load_ss(&value);

    return _mm_shuffle_ps(scalar, scalar, 0);
}

static __forceinline __m128 LengthSquared3(__m128 v)
{

    __m128 sq = _mm_mul_ps(v, v);

    return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
}

struct d5Vec4
{
    float v[4];
};

class hkSimdRealX
{

  public:
    __forceinline hkSimdRealX(const __m128& x) : m_vValue(x)
    {}

    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

    __m128 m_vValue;
};

struct hkVec4X
{

    __m128 m_vComponents;

    __forceinline hkSimdRealX lengthSquared3() const
    {
        return LengthSquared3(m_vComponents);
    }

    __forceinline void mul4(float s)
    {
        m_vComponents = _mm_mul_ps(SplatScalar(s), m_vComponents);
    }
};

// @fnv 0x00d5b2a0
static __declspec(noinline) void FUN_00d5b2a0(intptr_t a1, int a2, int a3, float d, intptr_t outI, const float* p)

{

    __declspec(align(16)) d5Vec4 columns[3];

    float* tmp = columns[0].v;

    *(__m128*)&tmp[0] = _mm_load_ps(p);

    *(__m128*)&tmp[4] = _mm_load_ps(p + 4);

    float first = FUN_00d5b0c0((const BoundsVector*)p, a3, (const char*)a1, a2);

    float invD = 1.0f / d;

    float* out = (float*)outI;

    for (int i = 0; i < 2; i++)

    {

        for (int k = 0; k < 3; k++)

        {

            columns[i].v[k] = d + columns[i].v[k];

            out[i * 4 + k] = (FUN_00d5b0c0((const BoundsVector*)tmp, a3, (const char*)a1, a2) - first) * invD;

            columns[i].v[k] = p[i * 4 + k];
        }

        __m128 sc = _mm_load_ss(&DAT_01012054);
        sc = _mm_shuffle_ps(sc, sc, 0);

        *(__m128*)&out[i * 4] = _mm_mul_ps(sc, *(__m128*)&out[i * 4]);
    }

    {

        hkVec4X* o = (hkVec4X*)out;

        const float len2 = o[0].lengthSquared3() + o[1].lengthSquared3();

        if (len2 > 1.0f)

        {

            float invv = 1.0f / (float)sqrt(len2);

            o[0].mul4(invv);

            o[1].mul4(invv);
        }
    }
}


struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};static __forceinline float RowLen(const float* r)
{
    __m128 v = _mm_load_ps(r);
    __m128 sq = _mm_mul_ps(v, v);
    __m128 a = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 b = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 s = _mm_add_ss(a, sq);
    __m128 t = _mm_add_ss(b, s);
    __m128 len = _mm_sqrt_ss(t);
    float out;
    _mm_store_ss(&out, len);
    return out;
}
static __forceinline float ScalarSqrt(float x)
{
    return sqrt(x);
}
static __forceinline float ScalarAbs(float x)
{
    return fabs(x);
}

static __forceinline int S00d5a6e0_FindCol(const float* sub, int start)
{
    int i;
    for (i = start; i <= 1; i++)
    {
        if (ScalarAbs(sub[i]) < 1e-6f)
            break;
    }
    return i;
}

// @fnv 0x00d5a6e0
hkBool __cdecl FUN_00d5a6e0(float m[3][4], int maxIterations)
{
    float maxLen = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        float len = RowLen(m[i]);
        if (len > maxLen)
            maxLen = len;
    }
    if (maxLen != 0.0f)
    {
        float* p = &m[2][0];
        int j = 3;
        do
        {
            p[-8] /= maxLen;
            p[-4] /= maxLen;
            *p /= maxLen;
            p++;
        } while (--j);
    }
    float fG, fR, fSin, fCos, fP, fF, fB;
    float afDiag[3];
    float afSubDiag[3];
    if (m[2][0] != 0.0f)
    {
        afDiag[0] = m[0][0];
        afSubDiag[2] = 0.0f;
        float fLen = ScalarSqrt(m[1][0] * m[1][0] + m[2][0] * m[2][0]);
        float v0 = m[1][0] / fLen;
        float v1 = m[2][0] / fLen;
        float q = v1 * (m[2][2] - m[1][1]) + 2.0f * v0 * m[2][1];
        afDiag[1] = m[1][1] + q * v1;
        afDiag[2] = m[2][2] - q * v1;
        afSubDiag[0] = fLen;
        afSubDiag[1] = m[2][1] - v0 * q;
        m[0][0] = 1.0f;
        m[1][0] = 0.0f;
        m[2][0] = 0.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][1] = v0;
        m[2][1] = v1;
        m[1][2] = v1;
        m[2][2] = -v0;
    }
    else
    {
        afDiag[0] = m[0][0];
        afDiag[1] = m[1][1];
        afDiag[2] = m[2][2];
        afSubDiag[0] = m[1][0];
        afSubDiag[1] = m[2][1];
        afSubDiag[2] = 0.0f;
        __m128 zero = _mm_setzero_ps();
        _mm_store_ps(&m[0][0], zero);
        _mm_store_ps(&m[1][0], zero);
        _mm_store_ps(&m[2][0], zero);
        m[0][0] = 1.0f;
        m[1][1] = 1.0f;
        m[2][2] = 1.0f;
    }
    for (int iRow = 0; iRow < 3; iRow++)
    {
        int iIter;
        for (iIter = 0; iIter < maxIterations; iIter++)
        {
            int iCol = S00d5a6e0_FindCol(afSubDiag, iRow);
            if (iCol == iRow)
                break;
            fG = (afDiag[iRow + 1] - afDiag[iRow]) / (2.0f * afSubDiag[iRow]);
            fR = ScalarSqrt((float)((double)(fG * fG) + 1.0));
            if (fG < 0.0f)
                fG = (afDiag[iCol] - afDiag[iRow]) + afSubDiag[iRow] / (fG - fR);
            else
                fG = (afDiag[iCol] - afDiag[iRow]) + afSubDiag[iRow] / (fG + fR);
            fSin = 1.0f;
            fCos = 1.0f;
            fP = 0.0f;
            for (int iM = iCol - 1; iM >= iRow; iM--)
            {
                fF = fSin * afSubDiag[iM];
                fB = fCos * afSubDiag[iM];
                if (ScalarAbs(fF) > ScalarAbs(fG))
                {
                    float ratio = -fG / fF;
                    fSin = (float)(-1.0 / ScalarSqrt((float)((double)(ratio * ratio) + 1.0)));
                    fCos = ratio * fSin;
                    fSin = -fSin;
                    afSubDiag[iM + 1] = fF / fSin;
                }
                else
                {
                    float ratio = -fF / fG;
                    fCos = (float)(-1.0 / ScalarSqrt((float)((double)(ratio * ratio) + 1.0)));
                    fSin = ratio * fCos;
                    fCos = -fCos;
                    afSubDiag[iM + 1] = fG / fCos;
                }
                fG = afDiag[iM + 1] - fP;
                fR = (afDiag[iM] - fG) * fSin + 2.0f * fB * fCos;
                fP = fSin * fR;
                afDiag[iM + 1] = fG + fP;
                fG = fCos * fR - fB;

                for (int j = 0; j < 3; ++j)
                {
                    fR = m[iM + 1][j];
                    m[iM + 1][j] = fSin * m[iM][j] + fCos * fR;
                    m[iM][j] = fCos * m[iM][j] - fSin * fR;
                }
            }
            afDiag[iRow] -= fP;
            afSubDiag[iRow] = fG;
            afSubDiag[iCol] = 0.0f;
        }
        if (iIter == maxIterations)
            return false;
    }
    return true;
}


class S00d5ae60_SimdReal
{
  public:
    S00d5ae60_SimdReal(const __m128& x) : m_vValue(x)
    {}
    S00d5ae60_SimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
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

  private:
    __m128 m_vValue;
};

class S00d5ae60_Vector4
{
  public:
    inline void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    inline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    inline void setAdd4(const S00d5ae60_Vector4& v0, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setSub4(const S00d5ae60_Vector4& v0, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void mul4(const S00d5ae60_SimdReal& s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    inline void setMul4(const S00d5ae60_SimdReal& r, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    inline void addMul4(const S00d5ae60_SimdReal& r, const S00d5ae60_Vector4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    inline S00d5ae60_SimdReal dot3(const S00d5ae60_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    inline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    inline const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[a];
    }

    __m128 m_vComponents;
};

template <typename T> inline T* S00d5ae60_addByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

// @fnv 0x00d5ae60
static __declspec(noinline) void FUN_00d5ae60(const float* verts, int numVerts, int striding,
                                              S00d5ae60_Vector4& halfExtents, const S00d5ae60_Vector4* axes,
                                              S00d5ae60_Vector4& center)
{
    S00d5ae60_Vector4 minV;
    minV.SetAllComponents(1.3611281e+38f);
    S00d5ae60_Vector4 maxV;
    maxV.SetAllComponents(-1.3611281e+38f);

    const float* v = verts;
    for (int i = 0; i < numVerts / 3; i++)
    {
        S00d5ae60_Vector4 p;
        p.set(v[0], v[1], v[2], 0.0f);
        v = S00d5ae60_addByteOffset(const_cast<float*>(v), striding);
        for (int k = 0; k < 3; k++)
        {
            float d = axes[k].dot3(p);
            if (d < minV(k))
                minV(k) = d;
            if (d > maxV(k))
                maxV(k) = d;
        }
        p.set(v[0], v[1], v[2], 0.0f);
        v = S00d5ae60_addByteOffset(const_cast<float*>(v), striding);
        for (int k = 0; k < 3; k++)
        {
            float d = axes[k].dot3(p);
            if (d < minV(k))
                minV(k) = d;
            if (d > maxV(k))
                maxV(k) = d;
        }
        p.set(v[0], v[1], v[2], 0.0f);
        v = S00d5ae60_addByteOffset(const_cast<float*>(v), striding);
        for (int k = 0; k < 3; k++)
        {
            float d = axes[k].dot3(p);
            if (d < minV(k))
                minV(k) = d;
            if (d > maxV(k))
                maxV(k) = d;
        }
    }

    S00d5ae60_Vector4 c;
    c.setAdd4(maxV, minV);
    c.mul4(0.5f);
    halfExtents.setSub4(maxV, minV);
    halfExtents.mul4(0.5f);
    center.setMul4(c(0), axes[0]);
    center.addMul4(c(1), axes[1]);
    center.addMul4(c(2), axes[2]);
}
static unsigned char FUN_00d5ad60(S00d5ad60_cls* self, float* other, float threshold);
namespace BoxGeometrySse {
}


extern const double DAT_010d1020;


struct ObbVec
{

    __m128 q;

    float x() const
    {
        return fnv_simd_as<float>(q)[0];
    }

    float y() const
    {
        return fnv_simd_as<float>(q)[1];
    }

    float z() const
    {
        return fnv_simd_as<float>(q)[2];
    }

    void FUN_00c7f640(const void* transform, const ObbVec* v) throw();

    void FUN_00c7f700(const void* transform, const ObbVec* v) throw();
};

struct ObbRot
{

    ObbVec c0, c1, c2;

};

struct ObbXf
{

    ObbVec c0, c1, c2, c3;

};
struct ObbVec;
struct ObbXf;


struct ObbInput
{
    ObbVec* data;
    int size;
    int cap;
    bool __cdecl FUN_00d5c6d0(ObbVec& halfExtents, ObbXf& output, float tolerance) const;
};

struct ObbStride
{
    const ObbVec* data;
    int size;
    int stride;
};

struct ObbAllocator
{

    virtual void unk00();

    virtual void unk04();

    virtual void unk08();

    virtual void* allocate(int& n) throw();

    virtual void free(void* p, int n) throw();
};

namespace FitMemory {

struct Router
{

    int unk00, unk04, unk08, unk0c;

    ObbAllocator* m_pStreamAllocator;

    ObbAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

Router& FUN_00c85750() throw();

}


ObbVec* __cdecl hlpC(ObbVec* out, const ObbStride*, float) throw();

struct ObbArray
{

    ObbVec* data;
    int size;
    int cap;

    ObbArray() throw() : data(0), size(0), cap(0x80000000)
    {}

    ~ObbArray() throw()
    {

        ObbAllocator& a = FitMemory::FUN_00c85750().heap();

        size = 0;

        if ((cap & 0x80000000) == 0)
            a.free(data, (cap & 0x3fffffff) * 16);

        data = 0;
        cap = 0x80000000;
    }

    void push(const ObbVec& v) throw()
    {

        ObbAllocator& a = FitMemory::FUN_00c85750().heap();

        if (size == (cap & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&a), (::AudioStream *)(void *)(this), 16);

        _mm_store_ps((float*)&data[size], v.q);

        ++size;
    }
};

struct ObbScratch
{

    ObbVec* data;
    int& cap;

    ObbScratch(int count, int& capacityOut) throw() : cap(capacityOut)
    {

        FitMemory::FUN_00c85750();

        FitMemory::FUN_00c85750();

        ObbAllocator& a = FitMemory::FUN_00c85750().heap();

        if (count > 0)
        {

            int n = count * 16;

            data = (ObbVec*)a.allocate(n);

            int capacity = n / 16;

            if (capacity)
                cap = capacity;

            else
                cap = 0x80000000;
        }
    }

    ~ObbScratch() throw()
    {

        ObbAllocator& a = FitMemory::FUN_00c85750().heap();

        if ((cap & 0x80000000) == 0)
            a.free(data, (cap & 0x3fffffff) * 16);
    }
};

static __m128 dot3(__m128 a, __m128 b)
{

    __m128 p = _mm_mul_ps(a, b);

    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}

static float dotf(__m128 a, __m128 b)
{
    float f;
    _mm_store_ss(&f, dot3(a, b));
    return f;
}

static __m128 normalizeScale(__m128 v)
{

    __m128 s = dot3(v, v);

    __m128 r = _mm_rsqrt_ss(s);

    __m128 mask = _mm_cmpeq_ss(s, _mm_load_ss(&::DAT_01011d78));

    __m128 three = _mm_set_ss(DAT_01017718);

    __m128 half = _mm_load_ss(&::fnv_00c88020::DAT_01016248);

    return _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(s, r), r))));
}

static __forceinline unsigned char hlpA(const float* a, const float* b, float eps)
{
    return (FUN_00d5ad60)((S00d5ad60_cls*)a, (float*)b, eps);
}

static __declspec(noinline) bool hlpB(const ObbVec* v, float eps) throw()
{

    float x = (float)fabs(v->x()), y = (float)fabs(v->y()), z = (float)fabs(v->z());

    float m = x > y ? x : y;

    m = m > z ? m : z;

    return (float)fabs(m - 1.0) < eps;
}

// @fnv 0x00d5c6d0
bool __cdecl ObbInput::FUN_00d5c6d0(ObbVec& halfExtents, ObbXf& output, float tolerance) const
{

    const ObbInput& input = *this;

    ObbVec sphere;

    {

        ObbVec temp;

        ObbStride strided;

        strided.size = input.size;

        strided.stride = 16;

        strided.data = input.data;

        sphere.q = hlpC(&temp, &strided, DAT_010718c0)->q;
    }

    int scratchCapacity;

    ObbScratch scratch(8, scratchCapacity);

    ObbArray selected;

    int count = input.size;

    for (int i = 0; i < count; i++)
    {

        __m128 diff = _mm_sub_ps(input.data[i].q, sphere.q);

        float distance;

        _mm_store_ss(&distance, _mm_sqrt_ss(dot3(diff, diff)));

        float error = distance - fnv_simd_as<float>(sphere.q)[3];

        error = (float)fabs(error);

        if (error < tolerance)
            selected.push(input.data[i]);
    }

    if (selected.size != 8)
        return false;

    for (int i = 0; i < 8; i++)
        scratch.data[i].q = selected.data[i].q;

    ObbVec a;

    {
        ObbVec x = scratch.data[0];
        ObbVec y = scratch.data[1];
        a.q = _mm_sub_ps(x.q, y.q);
    }

    ObbVec b;

    {
        ObbVec x = scratch.data[0];
        ObbVec y = scratch.data[2];
        b.q = _mm_sub_ps(x.q, y.q);
    }

    for (int i = 3; i < 8; i++)
    {

        ObbVec d = scratch.data[0];

        d.q = _mm_sub_ps(d.q, scratch.data[i].q);

        if (dotf(d.q, d.q) < dotf(a.q, a.q))
        {

            if (dotf(a.q, a.q) < dotf(b.q, b.q))
                b.q = a.q;

            a.q = d.q;
        }
        else if (dotf(d.q, d.q) < dotf(b.q, b.q))
            b.q = d.q;
    }

    float perpendicular;

    _mm_store_ss(&perpendicular, dot3(b.q, a.q));

    if (perpendicular > 0.00001f)
        return false;

    __m128 cross = _mm_sub_ps(

        _mm_mul_ps(_mm_shuffle_ps(b.q, b.q, 0xd2), _mm_shuffle_ps(a.q, a.q, 0xc9)),

        _mm_mul_ps(_mm_shuffle_ps(b.q, b.q, 0xc9), _mm_shuffle_ps(a.q, a.q, 0xd2)));

    __m128 na = normalizeScale(a.q), nb = normalizeScale(b.q), nc = normalizeScale(cross);

    ObbRot rotation;

    rotation.c0.q = _mm_mul_ps(_mm_shuffle_ps(na, na, 0), a.q);

    rotation.c1.q = _mm_mul_ps(_mm_shuffle_ps(nb, nb, 0), b.q);

    rotation.c2.q = _mm_mul_ps(_mm_shuffle_ps(nc, nc, 0), cross);

    reinterpret_cast<::hkMatrix3 *>(&(rotation))->FUN_00cd4f10(DAT_01013ea4);

    ObbVec* vertex = scratch.data;

    for (int i = 0; i < 8; ++i, ++vertex)
        vertex->FUN_00c7f700(&rotation, vertex);

    float minX = scratch.data[0].x(), maxX = scratch.data[0].x();

    float minY = scratch.data[0].y(), maxY = scratch.data[0].y();

    float minZ = scratch.data[0].z(), maxZ = scratch.data[0].z();

    for (int i = 1; i < 8; i++)
    {

        if (minX > scratch.data[i].x())
            minX = scratch.data[i].x();

        else if (maxX < scratch.data[i].x())
            maxX = scratch.data[i].x();

        if (minY > scratch.data[i].y())
            minY = scratch.data[i].y();

        else if (maxY < scratch.data[i].y())
            maxY = scratch.data[i].y();

        if (minZ > scratch.data[i].z())
            minZ = scratch.data[i].z();

        else if (maxZ < scratch.data[i].z())
            maxZ = scratch.data[i].z();
    }

    for (int i = 0; i < 8; i++)
    {

        if ((!hlpA(&fnv_simd_as<float>(scratch.data[i].q)[0], &minX, ::AngularDashpotApplyD4DCB0::DAT_01017d00) &&

             !hlpA(&fnv_simd_as<float>(scratch.data[i].q)[0], &maxX, ::AngularDashpotApplyD4DCB0::DAT_01017d00)) ||

            (!hlpA(&fnv_simd_as<float>(scratch.data[i].q)[1], &minY, ::AngularDashpotApplyD4DCB0::DAT_01017d00) &&

             !hlpA(&fnv_simd_as<float>(scratch.data[i].q)[1], &maxY, ::AngularDashpotApplyD4DCB0::DAT_01017d00)) ||

            (!hlpA(&fnv_simd_as<float>(scratch.data[i].q)[2], &minZ, ::AngularDashpotApplyD4DCB0::DAT_01017d00) &&

             !hlpA(&fnv_simd_as<float>(scratch.data[i].q)[2], &maxZ, ::AngularDashpotApplyD4DCB0::DAT_01017d00)))
            return false;
    }

    fnv_simd_as<float>(halfExtents.q)[0] = maxX - minX;

    fnv_simd_as<float>(halfExtents.q)[1] = maxY - minY;

    fnv_simd_as<float>(halfExtents.q)[2] = maxZ - minZ;

    __m128 h = _mm_load_ss(&::fnv_00c88020::DAT_01016248);
    halfExtents.q = _mm_mul_ps(_mm_shuffle_ps(h, h, 0), halfExtents.q);

    float cx = (float)((maxX + minX) * 0.5), cy = (float)((maxY + minY) * 0.5), cz = (float)((maxZ + minZ) * 0.5);

    ObbVec center;

    center.q = _mm_mul_ps(_mm_setr_ps(cx, cy, cz, 0.0f),
                          _mm_shuffle_ps(_mm_load_ss(&DAT_01012054), _mm_load_ss(&DAT_01012054), 0));

    ObbXf inverse;

    inverse.c0.q = rotation.c0.q;

    inverse.c1.q = rotation.c1.q;

    inverse.c2.q = rotation.c2.q;

    inverse.c3 = center;

    reinterpret_cast<::FUN_00cb21e0_shell *>(&(output))->FUN_00cb21e0((const ::Matrix44 *)(const ::ObbXf *)(&inverse));

    if (hlpB(&rotation.c0, tolerance) && hlpB(&rotation.c1, tolerance) && hlpB(&rotation.c2, tolerance))
    {

        halfExtents.FUN_00c7f700(&output, &halfExtents);

        fnv_simd_as<float>(halfExtents.q)[3] = 0;

        halfExtents.q = _mm_and_ps(halfExtents.q, DAT_01017d10);

        rotation.c0.q = _mm_setzero_ps();
        fnv_simd_as<float>(rotation.c0.q)[0] = 1;

        rotation.c1.q = _mm_setzero_ps();
        fnv_simd_as<float>(rotation.c1.q)[1] = 1;

        rotation.c2.q = _mm_setzero_ps();
        fnv_simd_as<float>(rotation.c2.q)[2] = 1;

        output.c0.q = rotation.c0.q;

        output.c1.q = rotation.c1.q;

        output.c2.q = rotation.c2.q;
    }

    reinterpret_cast<::FUN_00cb21e0_shell *>(&(inverse))->FUN_00cb21e0((const ::Matrix44 *)(const ::ObbXf *)(&output));

    for (int i = 0; i < input.size; i++)
    {

        ObbVec transformed;

        transformed.FUN_00c7f640(&inverse, &input.data[i]);

        for (int j = 0; j < 3; j++)
        {

            float d = (float)fabs(fnv_simd_as<float>(transformed.q)[j]);

            if (d > fnv_simd_as<float>(halfExtents.q)[j] * DAT_010d1020)
                return false;
        }
    }

    return true;
}

extern "C" void _ReadWriteBarrier();

static __forceinline __m128 DotThree(__m128 left, __m128 right)
{

    __m128 product = _mm_mul_ps(left, right);

    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);

    return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
}

template <bool Initialize>

static __forceinline void NormalizeThree(BoundsVector& output, __m128 value, __m128& zero, __m128& three, __m128& half)
{

    __m128 length = DotThree(value, value);

    __m128 reciprocal = _mm_rsqrt_ss(length);

    if (Initialize)
    {

        zero = _mm_set_ss(::DAT_01011d78);

        three = _mm_set_ss(DAT_01017718);

        half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
    }

    __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(length, reciprocal), reciprocal));

    __m128 scale = _mm_mul_ss(_mm_mul_ss(half, reciprocal), correction);

    scale = _mm_andnot_ps(_mm_cmpeq_ss(length, zero), scale);

    output.packed = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(&scale)), scale, 0), value);
}

// @fnv 0x00d5b0c0
static __declspec(noinline) float FUN_00d5b0c0(const BoundsVector* input, int stride, const char* vertices, int count)
{

    // The zero comparison mask is dead when the bounds helper writes the extents.

    BoundsVector axes[3], halfExtents, center;

    __m128 first = input[0].packed;

    __m128 half, three;

    __m128 second = input[1].packed;

    NormalizeThree<true>(axes[0], first, halfExtents.packed, three, half);

    float projection = _mm_cvtss_f32(DotThree(second, first));

    second =
        _mm_sub_ps(second, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&projection), _mm_load_ss(&projection), 0), first));

    // Keep the projection work ahead of the next normalization.

    _ReadWriteBarrier();

    NormalizeThree<false>(axes[1], second, halfExtents.packed, three, half);

    _ReadWriteBarrier();

    __m128 sourceSecond = input[1].packed;

    __m128 cross = _mm_sub_ps(

        _mm_mul_ps(_mm_shuffle_ps(sourceSecond, sourceSecond, 0xd2), _mm_shuffle_ps(first, first, 0xc9)),

        _mm_mul_ps(_mm_shuffle_ps(sourceSecond, sourceSecond, 0xc9), _mm_shuffle_ps(first, first, 0xd2)));

    NormalizeThree<false>(axes[2], cross, halfExtents.packed, three, half);

    FUN_00d5ae60(axes, vertices, count, stride, &halfExtents, &center);

    return halfExtents.component[0] * halfExtents.component[1] * halfExtents.component[2];
}

class Lane
{
  public:
    Lane(const __m128& x) : m_vValue(x)
    {}
    Lane(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    __m128 m_vValue;
};

class StepAxis
{
  public:
    StepAxis()
    {}
    StepAxis(const StepAxis& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const StepAxis& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void addMul4(const Lane& r, const StepAxis& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void subMul4(const Lane& r, const StepAxis& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void setCross(const StepAxis& a, const StepAxis& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline Lane dot3(const StepAxis& a) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline Lane lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = dot3(*this).getQuad();
        const __m128 isZero = _mm_cmpeq_ss(len2, zero);
        const __m128 guess = _mm_rsqrt_ss(len2);
        const __m128 better =
            _mm_mul_ss(_mm_mul_ss(half, guess), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, guess), guess)));
        return _mm_andnot_ps(isZero, better);
    }
    __forceinline void normalize3()
    {
        __m128 inv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(inv, m_vComponents);
    }

  private:
    __m128 m_vComponents;
};

// @fnv 0x00d5b440
static __declspec(noinline) void FUN_00d5b440(const StepAxis* axesIn, StepAxis* direction, float stepLength,
                                              StepAxis* axesOut)
{
    for (int i = 0; i < 2; i++)
    {
        axesOut[i] = axesIn[i];
        axesOut[i].addMul4(stepLength, direction[i]);
    }
    axesOut[0].normalize3();
    float dotProd = axesOut[0].dot3(axesOut[1]);
    axesOut[1].subMul4(dotProd, axesOut[0]);
    axesOut[1].normalize3();
    axesOut[2].setCross(axesOut[0], axesOut[1]);
    axesOut[2].normalize3();
}

class Scalar
{
  public:
    Scalar(const __m128& x) : m_vValue(x)
    {}
    Scalar(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    __m128 m_vValue;
};

class Point
{
  public:
    Point()
    {}
    Point(const Point& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const Point& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setSub4(const Point& a, const Point& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const Point& a, const Point& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const Scalar& r, const Point& v)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
    }
    __forceinline void addMul4(const Scalar& r, const Point& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void setCross(const Point& a, const Point& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline Scalar dot3(const Point& a) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline Scalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline Scalar length3() const
    {
        return _mm_sqrt_ss(dot3(*this).getQuad());
    }

  private:
    __m128 m_vComponents;
};

class Ball
{
  public:
    inline Ball(const Point& pt, float radius)
    {
        m_pos = pt;
        m_pos(3) = radius;
    }
    Point m_pos;
};

// @fnv 0x00d5bce0
static __declspec(noinline) Ball
    FUN_00d5bce0(const Point& pA, const Point& pB, const Point& pC, const Point& pD, float slack)
{
    Point b;
    b.setSub4(pB, pA);
    Point c;
    c.setSub4(pC, pA);
    Point d;
    d.setSub4(pD, pA);
    float det =
        b(0) * (c(1) * d(2) - c(2) * d(1)) - b(1) * (c(0) * d(2) - c(2) * d(0)) + b(2) * (c(0) * d(1) - c(1) * d(0));
    Point acc;
    acc.setZero4();
    Point cr;
    cr.setCross(b, c);
    acc.addMul4(d.lengthSquared3(), cr);
    cr.setCross(d, b);
    acc.addMul4(c.lengthSquared3(), cr);
    cr.setCross(c, d);
    acc.addMul4(b.lengthSquared3(), cr);
    float scale = 0.5 / det;
    acc.setMul4(scale, acc);
    Point center;
    center.setAdd4(pA, acc);
    float radius = acc.length3();
    return Ball(center, radius + slack);
}

static __declspec(noinline) Vec4* FUN_00d5bb10(Vec4* res, Vec4* p0, Vec4* p1, float t);

namespace sphere_pair_build {

struct Scalar
{
    __m128 q;
    Scalar()
    {}
    Scalar(__m128 v) : q(v)
    {}
    explicit Scalar(const float& v) : q(_mm_load_ss(&v))
    {}
    __m128 spread() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
    float get() const
    {
        float r;
        _mm_store_ss(&r, q);
        return r;
    }
    Scalar root() const
    {
        return Scalar(_mm_sqrt_ss(q));
    }
};

struct Vector
{
    __m128 q;
    void multiply(const Scalar& v)
    {
        q = _mm_mul_ps(v.spread(), q);
    }
    Scalar dot(const Vector& v) const
    {
        __m128 sq = _mm_mul_ps(q, v.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        return Scalar(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xy));
    }
    Scalar norm() const
    {
        return dot(*this).root();
    }
    float length() const
    {
        return norm().get();
    }
    void setSub(const Vector& a, const Vector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    void setAdd(const Vector& a, const Vector& b)
    {
        q = _mm_add_ps(a.q, b.q);
    }
};

}

// @fnv 0x00d5bb10
__declspec(noinline) Vec4* FUN_00d5bb10(Vec4* result, Vec4* first, Vec4* second, float radius)
{
    using namespace sphere_pair_build;
    const Vector* a = reinterpret_cast<const Vector*>(first);
    Vector* __restrict out = reinterpret_cast<Vector*>(result);
    const Vector* b = reinterpret_cast<const Vector*>(second);
    const Vector& base = *a;
    Vector delta;
    delta.setSub(*b, base);
    Scalar half(::fnv_00c88020::DAT_01016248);
    delta.multiply(half);
    float distance = delta.length();
    out->setAdd(base, delta);
    fnv_simd_as<float>(out->q)[3] = distance + radius;
    return result;
}

#include "generated/data/havok/common/internal/convexhull/hkgeometryutility.inc"
