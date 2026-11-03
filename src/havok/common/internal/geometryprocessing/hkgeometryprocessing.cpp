
// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv_simd.h"
#include <cstddef>
#include <new>
#include "fnv/decl/FUN_00d9be30_class.h"
#include "fnv/decl/FUN_00e241a0_cls.h"
#include "fnv/decl/HostE10.h"
#include "fnv/decl/MapD9.h"
#include "fnv/decl/S_00d9d650_Tree.h"
#include "fnv/decl/S_e1ce10_Mesh.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/Z_E15E50.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d1d000.h"
#include "fnv/symbols_00dea000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_00cbf000.h"
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include "fnv/decl/FnvCpu_FUN_00d76d80_CpuOwner.h"
#include "fnv/decl/FUN_00d5d660_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00de9000.h"
#include "fnv/symbols_00ded000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_010cd000.h"
#include "fnv/symbols_010d0000.h"
#include "fnv/symbols_010d9000.h"
#include "fnv/symbols_01267000.h"
extern int DAT_010d9fc4;

struct FUN_00dee620
{
    void* m_pVTable;
    FUN_00dee620(int testFlag);
};

// @fnv 0x00dee620
FUN_00dee620::FUN_00dee620(int aiFlags)
{
    m_pVTable = &DAT_010d9fc4;
    if (aiFlags & 1)
        ::FUN_00401030(this);
}

// Forwards the four pointers to FUN_00dedf10 with two trailing int arguments set to 0.
// @fnv 0x00dee5f0
void __cdecl FUN_00dee5f0(void* first, void* second, void* third, void* fourth)
{
    ::FUN_00dedf10((*(const ::Sdedf10_Geometry *)(first)), (intptr_t)(second), (*(::Sdedf10_Array< ::Sdedf10_Vector4, ::Sdedf10_TypeIsPod> *)(third)), (intptr_t)(fourth), 0, (const ::Sdedf10_IFunction *)(0));
}

struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float FUN_00dee6b0(int testFlag);
};
// @fnv 0x00dee6b0
float FUN_00dee6b0_Class::FUN_00dee6b0(int testFlag)
{
    return unk04;
}


struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00dee6c0_cls
{
    intptr_t m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};

// Sets the vtable pointer and, when acFlags has bit 0 set, frees this 0x40-byte object through the allocator from FUN_00c85750.
// @fnv 0x00dee6c0
FUN_00dee6c0_cls* FUN_00dee6c0_cls::FUN_00dee6c0(unsigned char acFlags)
{
    m_vptr = (intptr_t)&DAT_010cd664;
    if (acFlags & 1)
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, 0x40);
    }
    return this;
}


struct VectorComponentValue
{
    __m128 m_vValue;

    VectorComponentValue()
    {}
    VectorComponentValue(const __m128& r) : m_vValue(r)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

__forceinline VectorComponentValue operator/(const VectorComponentValue& a, const VectorComponentValue& b)
{
    return _mm_div_ss(a.m_vValue, b.m_vValue);
}

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void sub4(const hkVector4& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        m_vComponents =
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2))),
                       _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1))));
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& r)
    {
        m_vComponents =
            _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        return _mm_add_ss(z, xySum);
    }
    __forceinline VectorComponentValue lengthSquared3() const
    {
        return dot3(*this);
    }
};


// Computes the squared distance from point a to the segment bc, clamping the projection parameter to [0,1] and storing it in out.
// @fnv 0x00de94b0
float __cdecl FUN_00de94b0(const hkVector4& a, const hkVector4& b, const hkVector4& c, float* pfT)
{
    hkVector4 d1;
    d1.setSub4(b, a);
    hkVector4 vSegmentVec;
    vSegmentVec.setSub4(c, b);
    const VectorComponentValue fLenSq = vSegmentVec.lengthSquared3();
    const VectorComponentValue num = _mm_sub_ss(::DAT_010c7160, vSegmentVec.dot3(d1).m_vValue);
    const float t = num / fLenSq;
    *pfT = t;
    if (t < 0.0f)
    {
        *pfT = 0.0f;
    }
    else if (t > 1.0f)
    {
        *pfT = 1.0f;
    }
    hkVector4 v;
    v.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_load_ps1(pfT), vSegmentVec.m_vComponents), d1.m_vComponents);
    return v.lengthSquared3();
}

namespace fnv_00dea810 {


struct hkVector4Comparisonq
{
    __m128 m_uiMask;
};
struct hkVector4q
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline hkVector4Comparisonq compareLessThan4(const hkVector4q& a) const
    {
        hkVector4Comparisonq c;
        c.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
        return c;
    }
    __forceinline void setSelect4(const hkVector4Comparisonq& comp, const hkVector4q& trueValue,
                                  const hkVector4q& falseValue)
    {
        m_vComponents = _mm_or_ps(_mm_and_ps(comp.m_uiMask, trueValue.m_vComponents),
                                  _mm_andnot_ps(comp.m_uiMask, falseValue.m_vComponents));
    }
    template <int I> __forceinline void setBroadcast(const hkVector4q& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (I << 6) | (I << 4) | (I << 2) | I);
    }
    __forceinline float& operator()(int i)
    {
        return fnv_simd_as<float>(m_vComponents)[i];
    }
};

struct hkFourTransposedPointsq
{
    hkVector4q m_kVertices[3];
};

struct FourPointsArray
{
    hkFourTransposedPointsq* m_data;
    int m_iElementCount;
};


// Finds the vertex with the maximum dot product against direction, stores it in supportingVertexOut, and packs vertexId into the w component.
// @fnv 0x00dea810
void __cdecl FUN_00dea810(const FourPointsArray& rotatedVertices, const hkVector4q& direction,
                          hkVector4q& supportingVertexOut)
{

    hkVector4q vBestDot;
    vBestDot.set(::DAT_0104e148, ::DAT_0104e148, ::DAT_0104e148, ::DAT_0104e148);
    hkVector4q vCurIndices;
    vCurIndices = (*reinterpret_cast<::fnv_00dea810::hkVector4q *>((void *)&::DAT_010d9fe0));
    hkVector4q vBestIndices;
    vBestIndices.setZero4();

    int i = 0;
    const hkFourTransposedPointsq* p = rotatedVertices.m_data;
    hkVector4q vDirX;
    vDirX.setBroadcast<0>(direction);
    hkVector4q vDirY;
    vDirY.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0x55);
    hkVector4q vDirZ;
    vDirZ.setBroadcast<2>(direction);

    {
        for (; i < rotatedVertices.m_iElementCount * 4; i += 4)
        {
            hkVector4q x;
            x.setMul4(vDirX, p->m_kVertices[0]);
            hkVector4q y;
            y.setMul4(vDirY, p->m_kVertices[1]);
            hkVector4q z;
            z.setMul4(vDirZ, p->m_kVertices[2]);
            hkVector4q dot;
            dot.setAdd4(x, y);
            dot.add4(z);
            hkVector4Comparisonq comp = vBestDot.compareLessThan4(dot);
            vBestDot.setSelect4(comp, dot, vBestDot);
            vBestIndices.setSelect4(comp, vCurIndices, vBestIndices);
            vCurIndices.add4((*reinterpret_cast<::fnv_00dea810::hkVector4q *>((void *)&::DAT_010d0fa0)));
            ++p;
        }
    }

    int a = (vBestDot(0) > vBestDot(1)) ? 0 : 1;
    int b = (vBestDot(2) > vBestDot(3)) ? 2 : 3;
    int best = (vBestDot(a) > vBestDot(b)) ? a : b;
    int vertexId = (int)vBestIndices(best);

    const hkFourTransposedPointsq& f = rotatedVertices.m_data[(unsigned int)vertexId >> 2];
    int c = vertexId & 3;
    supportingVertexOut.set(fnv_simd_as<float>(f.m_kVertices[0].m_vComponents)[c], fnv_simd_as<float>(f.m_kVertices[1].m_vComponents)[c],
                            fnv_simd_as<float>(f.m_kVertices[2].m_vComponents)[c], 0.0f);
    *(int*)&supportingVertexOut(3) = vertexId | 0x3f000000;
}
}  // namespace fnv_00dea810

extern __m128 DAT_010c71d0;

struct FUN_00dee640_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_vec10;
    float m_fDist20;
    int unk24;
    int unk28;
    int unk2C;
    void* m_pTag30;
    float UpdateNearestDistance(void* pair);
};

// Computes the squared distance from m_vec10 to the midpoint of the pair and updates m_fDist20 and m_pTag30 when it is smaller.
// @fnv 0x00dee640
float FUN_00dee640_cls::UpdateNearestDistance(void* pair)
{
    const __m128* ab = (const __m128*)pair;
    __m128 vMidpoint = _mm_mul_ps(_mm_add_ps(ab[0], ab[1]), DAT_010c71d0);
    __m128 d = _mm_sub_ps(m_vec10, vMidpoint);
    d = _mm_mul_ps(d, d);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    float fDistSq;
    _mm_store_ss(&fDistSq, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), xy));
    if (fDistSq < m_fDist20)
    {
        m_fDist20 = fDistSq;
        m_pTag30 = pair;
    }
    return 1.0f;
}


struct Vertex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    __m128 m_vHitNormal;
};

struct Triangle
{
    unsigned int unk00;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    unsigned int unk20;
};

struct Edge
{
    Triangle* m_pkTriangle;
    uintptr_t m_uiEdgeIndex;

    Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    Edge(uintptr_t uid)
    {
        m_uiEdgeIndex = uid & 3;
        m_pkTriangle = (Triangle*)(uid & ~3u);
    }
    uintptr_t uid() const
    {
        return (uintptr_t)m_pkTriangle + m_uiEdgeIndex;
    }
    Edge link() const
    {
        return Edge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]);
    }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
    void bindSafe(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        if (other.m_pkTriangle)
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};

struct PendingBlock
{
    unsigned int unk00;
    unsigned int unk04;
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
    int m_40;
    int m_44;
    unsigned int unk48;
    unsigned int unk4C;
};

struct Sub08_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Vertex* PushFront(PendingBlock* out);
};

struct Sub20_cls
{
    Triangle* FUN_00e241a0(Triangle* node);
};

struct FUN_00e19200_cls
{
    unsigned int unk00;
    unsigned int unk04;
    Sub08_cls m_08;
    Sub20_cls m_20;
    void FUN_00e19200(Triangle* a, const __m128* b, int c);
};

// Creates a new vertex from b, assigns it to three triangles, and rewires their edge links to split t0.
// @fnv 0x00e19200
void FUN_00e19200_cls::FUN_00e19200(Triangle* apTriangle, const __m128* b, int aiUnused)
{
    PendingBlock stBlock;
    stBlock.m_40 = -1;
    stBlock.m_44 = -1;
    Vertex* v = m_08.PushFront(&stBlock);
    v->m_vHitNormal = (*reinterpret_cast<::__m128 *>(&::DAT_01267e30));
    v->m_vContactPosition = *b;
    Triangle* pTriangle1 = m_20.FUN_00e241a0(apTriangle);
    Triangle* pTriangle2 = m_20.FUN_00e241a0(apTriangle);
    apTriangle->m_kVertices[0] = v;
    pTriangle1->m_kVertices[1] = v;
    pTriangle2->m_kVertices[2] = v;
    Edge(pTriangle1, 2).bindSafe(Edge(apTriangle, 2).link());
    Edge(pTriangle2, 0).bindSafe(Edge(apTriangle, 0).link());
    Edge(apTriangle, 0).bind(Edge(pTriangle2, 1));
    Edge(pTriangle1, 0).bind(Edge(pTriangle2, 2));
    Edge(pTriangle1, 1).bind(Edge(apTriangle, 2));
}

namespace fnv_00dea6b0 {


struct S00dea6b0_Vec
{
    __m128 m_vComponents;

    void setSub4(const S00dea6b0_Vec& a, const S00dea6b0_Vec& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const S00dea6b0_Vec& v1, const S00dea6b0_Vec& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    float dot3(const S00dea6b0_Vec& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 res = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        float r;
        _mm_store_ss(&r, res);
        return r;
    }
};

// Checks if point p lies inside triangle abc by verifying the dot product of each edge cross product with the triangle normal is at least tol.
// @fnv 0x00dea6b0
bool __cdecl FUN_00dea6b0(const S00dea6b0_Vec& p, const S00dea6b0_Vec& a, const S00dea6b0_Vec& b,
                          const S00dea6b0_Vec& c, float afTolerance)
{
    S00dea6b0_Vec ab;
    ab.setSub4(b, a);
    S00dea6b0_Vec vEdgeAC;
    vEdgeAC.setSub4(c, a);
    S00dea6b0_Vec n;
    n.setCross(ab, vEdgeAC);
    {
        S00dea6b0_Vec e0;
        e0.setSub4(a, p);
        S00dea6b0_Vec e1;
        e1.setSub4(b, p);
        S00dea6b0_Vec cr;
        cr.setCross(e0, e1);
        if (cr.dot3(n) < afTolerance)
            return false;
    }
    {
        S00dea6b0_Vec e0;
        e0.setSub4(b, p);
        S00dea6b0_Vec e1;
        e1.setSub4(c, p);
        S00dea6b0_Vec cr;
        cr.setCross(e0, e1);
        if (cr.dot3(n) < afTolerance)
            return false;
    }
    {
        S00dea6b0_Vec e0;
        e0.setSub4(c, p);
        S00dea6b0_Vec e1;
        e1.setSub4(a, p);
        S00dea6b0_Vec cr;
        cr.setCross(e0, e1);
        if (cr.dot3(n) < afTolerance)
            return false;
    }
    return true;
}
}  // namespace fnv_00dea6b0


struct CubeVector
{
    __m128 lanes;
    __forceinline void sum(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_add_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void difference(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_sub_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void scale(const __m128& k)
    {
        lanes = _mm_mul_ps(k, lanes);
    }
    __forceinline int longestAxis() const
    {
        CubeVector magnitude;
        magnitude.lanes = _mm_and_ps(lanes, DAT_01017d10);
        const float* p = (const float*)&magnitude.lanes;
        if (p[0] < p[1])
            return p[1] < p[2] ? 2 : 1;
        return p[0] < p[2] ? 2 : 0;
    }
    __forceinline float component(int i) const
    {
        return ((const float*)&lanes)[i];
    }
};
struct CubeBox
{
    CubeVector lower;
    CubeVector upper;
    __forceinline void center(CubeVector& dst) const
    {
        dst.sum(lower, upper);
        dst.scale(DAT_010c71d0);
    }
    __forceinline void extent(CubeVector& dst) const
    {
        dst.difference(upper, lower);
        dst.scale(DAT_010c71d0);
    }
};

// Sets lower and upper from the center using the signed extent component with greatest magnitude on x, y, or z.
// @fnv 0x00de9590
void __cdecl FUN_00de9590(CubeBox* box)
{
    CubeVector center;
    CubeVector extent;
    box->extent(extent);
    box->center(center);
    float size = extent.component(extent.longestAxis());
    CubeVector vRadius;
    vRadius.lanes = _mm_setr_ps(size, size, size, DAT_01011d78);
    box->lower.difference(center, vRadius);
    box->upper.sum(center, vRadius);
}

#include <math.h>
extern const float DAT_0104da4c = 1.1920928955078125e-7f;


// Computes the closest distance between two line segments defined by start and end points, writing clamped parameters to the output pointers.
// @fnv 0x00dea450
float __cdecl FUN_00dea450(const hkVector4& firstStart, const hkVector4& firstEnd, const hkVector4& secondStart,
                           const hkVector4& secondEnd, float* firstParameter, float* secondParameter)
{
    hkVector4 firstDirection;
    firstDirection.setSub4(firstEnd, firstStart);
    hkVector4 separation;
    separation.setSub4(secondStart, firstStart);
    hkVector4 secondDirection;
    secondDirection.setSub4(secondEnd, secondStart);
    float crossDot = firstDirection.dot3(secondDirection);
    float firstOffset = separation.dot3(firstDirection);
    float secondOffset = separation.dot3(secondDirection);
    float firstSquare = firstDirection.lengthSquared3();
    float secondSquare = secondDirection.lengthSquared3();
    float determinant = secondSquare * firstSquare - crossDot * crossDot;
    float magnitude = (float)fabs(determinant);
    if (magnitude > DAT_0104da4c)
    {
        float numerator = firstSquare * secondOffset - crossDot * firstOffset;
        float parameter = -numerator / determinant;
        float clamped = parameter < 0.0f ? 0.0f : (parameter > 1.0f ? 1.0f : parameter);
        *secondParameter = clamped;
        hkVector4 point;
        point.setAddMul4(secondStart, secondDirection, VectorComponentValue(_mm_load_ss(secondParameter)));
        hkVector4 offset;
        offset.setSub4(firstStart, point);
        VectorComponentValue squaredLength = firstDirection.lengthSquared3();
        VectorComponentValue projected = offset.dot3(firstDirection);
        VectorComponentValue s =
            _mm_sub_ss(::DAT_010c7160, _mm_div_ss(projected.m_vValue, squaredLength.m_vValue));
        float rawFirst = s;
        float firstClamped = rawFirst < 0.0f ? 0.0f : (rawFirst > 1.0f ? 1.0f : rawFirst);
        *firstParameter = firstClamped;
        hkVector4 difference;
        difference.m_vComponents =
            _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(*firstParameter), firstDirection.m_vComponents),
                                  firstStart.m_vComponents),
                       point.m_vComponents);
        VectorComponentValue result = _mm_sqrt_ss(difference.dot3(difference).m_vValue);
        return result;
    }
    *secondParameter = 0.0f;
    *firstParameter = 0.0f;
    return ::DAT_0104da48;
}

struct Vec4
{
    __m128 value;
};
// @fnv 0x00de9b90
Vec4 __cdecl FUN_00de9b90(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d)
{
    __m128 scale = _mm_load_ss(&::DAT_0101622c);
    __m128 cv = c.value;
    __m128 dv = d.value;
    __m128 bv = b.value;
    __m128 cd = _mm_add_ps(cv, dv);
    __m128 av = a.value;
    __m128 ab = _mm_add_ps(av, bv);
    __m128 sum = _mm_add_ps(cd, ab);
    scale = _mm_shuffle_ps(scale, scale, 0);
    Vec4 result;
    result.value = _mm_mul_ps(sum, scale);
    return result;
}


class ScalarValue
{
    __m128 value;

  public:
    ScalarValue()
    {}
    ScalarValue(const __m128& x) : value(x)
    {}
    ScalarValue(float x) : value(_mm_load_ss(&x))
    {}
    operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline const __m128& lanes() const
    {
        return value;
    }
    __forceinline __m128 spread() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
inline ScalarValue operator+(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_add_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator/(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_div_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator-(const ScalarValue& x)
{
    return _mm_sub_ss(::DAT_010c7160, x.lanes());
}

class GeomVector
{
  public:
    __m128 data;
    GeomVector()
    {}
    GeomVector(const __m128& x) : data(x)
    {}
    __forceinline GeomVector(const GeomVector& x) : data(x.data)
    {}
    __forceinline void operator=(const GeomVector& x)
    {
        data = x.data;
    }
    __forceinline void difference(const GeomVector& x, const GeomVector& y)
    {
        data = _mm_sub_ps(x.data, y.data);
    }
    __forceinline void cross(const GeomVector& x, const GeomVector& y)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xc9), _mm_shuffle_ps(y.data, y.data, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xd2), _mm_shuffle_ps(y.data, y.data, 0xc9));
        data = _mm_sub_ps(first, second);
    }
    __forceinline ScalarValue dot(const GeomVector& x) const
    {
        __m128 product = _mm_mul_ps(data, x.data);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline ScalarValue magnitude() const
    {
        return _mm_sqrt_ss(dot(*this).lanes());
    }
    __forceinline ScalarValue inverseMagnitude() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 squared = dot(*this).lanes();
        const __m128 empty = _mm_cmpeq_ss(squared, zero);
        const __m128 estimate = _mm_rsqrt_ss(squared);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
        return _mm_andnot_ps(empty, refined);
    }
    __forceinline void normalize()
    {
        __m128 scale = inverseMagnitude().spread();
        data = _mm_mul_ps(scale, data);
    }
    __forceinline float& component(int i)
    {
        return ((float*)&data)[i];
    }
    __forceinline ScalarValue selected(int i) const
    {
        switch (i)
        {
        case 0:
            return data;
        case 1:
            return _mm_shuffle_ps(data, data, 0x55);
        case 2:
            return _mm_shuffle_ps(data, data, 0xaa);
        default:
            return _mm_shuffle_ps(data, data, 0xff);
        }
    }
    __forceinline void addScaled(const GeomVector& base, const GeomVector& direction, const ScalarValue& scale)
    {
        data = _mm_add_ps(base.data, _mm_mul_ps(scale.spread(), direction.data));
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        data = _mm_setr_ps(x, y, z, w);
    }
    __forceinline ScalarValue sum() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(data, data, 0x55), data);
        return _mm_add_ss(_mm_shuffle_ps(data, data, 0xaa), xy);
    }
    __forceinline void scale(const ScalarValue& x)
    {
        data = _mm_mul_ps(x.spread(), data);
    }
};
static __forceinline GeomVector offsetCross(const GeomVector& origin, const GeomVector& a, const GeomVector& b)
{
    GeomVector first;
    first.difference(a, origin);
    GeomVector second;
    second.difference(b, origin);
    GeomVector result;
    result.cross(first, second);
    return result;
}
static __forceinline GeomVector makePlane(const GeomVector& a, const GeomVector& b, const GeomVector& c,
                                          bool normalized)
{
    GeomVector result = offsetCross(a, b, c);
    if (normalized)
        result.normalize();
    result.component(3) = -result.dot(a);
    return result;
}
static __forceinline float doubleArea(const GeomVector& origin, const GeomVector& a, const GeomVector& b)
{
    return offsetCross(origin, a, b).magnitude();
}

// Computes the squared distance from a point to a triangle, returning the closest normal and optional barycentric weights.
// @fnv 0x00de9f10
float __cdecl FUN_00de9f10(const GeomVector& point, const GeomVector& a, const GeomVector& b, const GeomVector& c,
                           GeomVector& normal, GeomVector* weights)
{
    GeomVector plane = makePlane(a, b, c, true);
    float distance = plane.dot(point) + plane.selected(3);
    GeomVector projected;
    projected.addScaled(point, plane, -distance);
    if (offsetCross(projected, a, b).dot(plane) > 0 && offsetCross(projected, b, c).dot(plane) > 0 &&
        offsetCross(projected, c, a).dot(plane) > 0)
    {
        normal = plane;
        if (weights)
        {
            weights->set(doubleArea(projected, b, c), doubleArea(projected, c, a), doubleArea(projected, a, b), 0);
            ScalarValue sum = weights->sum();
            if (sum > DAT_0104da4c)
                weights->scale(ScalarValue(::DAT_01012068) / sum);
            else
                weights->set(::DAT_0106c2e0, ::DAT_0106c2e0, ::DAT_0106c2e0, 0);
        }
        if (distance < 0)
            normal.scale(DAT_01012054);
        return distance * distance;
    }
    else
    {
        GeomVector normals[3];
        float fractions[3];
        float distances[3];
        distances[0] = ::FUN_00de9e10((float *)&(point), (float *)&(a), (float *)&(b), (float *)&(normals[0]), &fractions[0]);
        distances[1] = ::FUN_00de9e10((float *)&(point), (float *)&(b), (float *)&(c), (float *)&(normals[1]), &fractions[1]);
        distances[2] = ::FUN_00de9e10((float *)&(point), (float *)&(c), (float *)&(a), (float *)&(normals[2]), &fractions[2]);
        int edge =
            distances[0] < distances[1] ? (distances[0] < distances[2] ? 0 : 2) : (distances[1] < distances[2] ? 1 : 2);
        normal = normals[edge];
        if (weights)
        {
            switch (edge)
            {
            case 0:
                weights->set(1 - fractions[0], fractions[0], 0, 0);
                break;
            case 1:
                weights->set(0, 1 - fractions[1], fractions[1], 0);
                break;
            case 2:
                weights->set(fractions[2], 0, 1 - fractions[2], 0);
                break;
            }
        }
        return distances[edge];
    }
}

#include <float.h>

struct S00dea980_Vec
{
    __m128 m_vComponents;
};

inline __m128 S00dea980_cross(__m128 a, __m128 b)
{
    __m128 b_yzx = _mm_shuffle_ps(b, b, 0xc9);
    __m128 a_zxy = _mm_shuffle_ps(a, a, 0xd2);
    __m128 a_yzx = _mm_shuffle_ps(a, a, 0xc9);
    __m128 prod1 = _mm_mul_ps(b_yzx, a_zxy);
    __m128 b_zxy = _mm_shuffle_ps(b, b, 0xd2);
    __m128 prod2 = _mm_mul_ps(b_zxy, a_yzx);
    return _mm_sub_ps(prod2, prod1);
}

inline __m128 S00dea980_len2m(__m128 v)
{
    __m128 m = _mm_mul_ps(v, v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), s);
}

inline __m128 S00dea980_hadd(__m128 v)
{
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s);
}

inline float S00dea980_f(__m128 v)
{
    float s;
    _mm_store_ss(&s, v);
    return s;
}

// @fnv 0x00dea980
float FUN_00dea980(const S00dea980_Vec* apFirst, const S00dea980_Vec* apSecond, const S00dea980_Vec* apThird)
{
    __m128 vFirst = apFirst->m_vComponents;
    __m128 v1 = apSecond->m_vComponents;
    __m128 v2 = apThird->m_vComponents;

    __m128 eSecondFirst = _mm_sub_ps(v1, vFirst);
    __m128 eThirdFirst = _mm_sub_ps(v2, vFirst);

    __m128 cr = S00dea980_cross(eSecondFirst, eThirdFirst);

    float fCrossLength = S00dea980_f(_mm_sqrt_ss(S00dea980_len2m(cr)));
    float fSqrtThree = (float)sqrt(3.0);
    float num = fSqrtThree * (fCrossLength * 2.0f);

    float fLenSqThirdFirst = S00dea980_f(S00dea980_len2m(eThirdFirst));
    float fLenSqSecondThird = S00dea980_f(S00dea980_len2m(_mm_sub_ps(v1, v2)));
    float fLenSqFirstSecond;
    _mm_store_ss(&fLenSqFirstSecond, S00dea980_len2m(_mm_sub_ps(vFirst, v1)));

    __m128 vLengthsSq = _mm_setr_ps(fLenSqFirstSecond, fLenSqSecondThird, fLenSqThirdFirst, 0.0f);
    __m128 vDenominator = S00dea980_hadd(vLengthsSq);

    if (S00dea980_f(vDenominator) > FLT_EPSILON)
    {
        return S00dea980_f(_mm_div_ss(_mm_load_ss(&num), vDenominator));
    }

    return 0.0f;
}

static __forceinline void medianInterpolate(hkVector4& result, const hkVector4& first, const hkVector4& second,
                                            const VectorComponentValue& fraction)
{
    __m128 weight = _mm_shuffle_ps(fraction.m_vValue, fraction.m_vValue, 0);
    __m128 complement = _mm_sub_ps(DAT_010ec7f0, weight);
    result.m_vComponents =
        _mm_add_ps(_mm_mul_ps(complement, first.m_vComponents), _mm_mul_ps(weight, second.m_vComponents));
}
// Interpolates between first and second using a fraction loaded from DAT_01016248.
// @fnv 0x00de9b10
hkVector4 __cdecl FUN_00de9b10(const hkVector4& first, const hkVector4& second)
{
    hkVector4 result;
    medianInterpolate(result, first, second, VectorComponentValue(_mm_load_ss(&::fnv_00c88020::DAT_01016248)));
    return result;
}


struct CentroidVector
{
    __m128 value;
};

// @fnv 0x00de9b50
CentroidVector __cdecl FUN_00de9b50(const CentroidVector* apCentroidA, const CentroidVector* apCentroidB,
                                    const CentroidVector* apCentroidC)
{
    __m128 vSum = _mm_load_ps((const float*)&apCentroidA->value);
    __m128 scale = _mm_load_ss(&::DAT_0106c2e0);
    __m128 vb = _mm_load_ps((const float*)&apCentroidB->value);

    vSum = _mm_add_ps(vSum, vb);

    __m128 vc = _mm_load_ps((const float*)&apCentroidC->value);
    vSum = _mm_add_ps(vSum, vc);
    vSum = _mm_mul_ps(vSum, _mm_shuffle_ps(scale, scale, 0));

    CentroidVector result;
    result.value = vSum;
    return result;
}


struct Sdedf10_PlacementArg;

struct Sdedf10_TypeIsPod
{
};
struct Sdedf10_TypeIsClass
{
};

struct Sdedf10_Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
class Sdedf10_MemoryRouter
{
  public:
    static Sdedf10_MemoryRouter& __cdecl GetMonitorStream()
    {
        return *static_cast<Sdedf10_MemoryRouter*>(::FUN_00c85750());
    }
    __forceinline Sdedf10_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  private:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    Sdedf10_Allocator* m_pStreamAllocator;
};
__forceinline Sdedf10_Allocator& Sdedf10_heap()
{
    return Sdedf10_MemoryRouter::GetMonitorStream().heap();
}


template <typename T> __forceinline void Sdedf10_construct(T* t, int n, Sdedf10_TypeIsPod)
{}
template <typename T> __forceinline void Sdedf10_destruct(T* t, int n, Sdedf10_TypeIsPod)
{}
template <typename T> __forceinline void Sdedf10_constructWithCopy(T* t, int n, const T& tcopy, Sdedf10_TypeIsPod)
{
    for (int i = 0; i < n; ++i)
    {
        t[i] = tcopy;
    }
}
template <typename T> __forceinline void Sdedf10_constructWithCopy(T* t, int n, const T& tcopy, Sdedf10_TypeIsClass)
{
    for (int i = 0; i < n; ++i)
    {
        new (reinterpret_cast<Sdedf10_PlacementArg*>(t + i)) T(tcopy);
    }
}

template <typename T, typename Tag> struct Sdedf10_ArrayBase
{
    enum
    {
        CAPACITY_MASK = 0x3FFFFFFF,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline Sdedf10_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline ~Sdedf10_ArrayBase()
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void clear()
    {
        Sdedf10_destruct(m_data, m_iElementCount, Sdedf10_TypeIsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(Sdedf10_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void _reserveExactly(Sdedf10_Allocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), n, sizeof(T));
        }
    }
    __forceinline void GrowArrayCapacity(Sdedf10_Allocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void _pushBack(Sdedf10_Allocator& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(T));
        }
        Sdedf10_constructWithCopy(m_data + m_iElementCount, 1, t, Tag());
        m_iElementCount++;
    }
    __forceinline void _setSize(Sdedf10_Allocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        Sdedf10_destruct(m_data + n, m_iElementCount - n, Sdedf10_TypeIsPod());
        Sdedf10_construct(m_data + m_iElementCount, n - m_iElementCount, Sdedf10_TypeIsPod());
        m_iElementCount = n;
    }
};

template <typename T, typename Tag = Sdedf10_TypeIsPod> struct Sdedf10_Array : Sdedf10_ArrayBase<T, Tag>
{
    __forceinline Sdedf10_Array()
    {}
    __forceinline ~Sdedf10_Array()
    {
        this->_clearAndDeallocate(Sdedf10_heap());
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->_setSize(Sdedf10_heap(), n);
    }
    __forceinline void reserveExactly(int n)
    {
        this->_reserveExactly(Sdedf10_heap(), n);
    }
    __forceinline void AddBack(const T& t)
    {
        this->_pushBack(Sdedf10_heap(), t);
    }
};

class Sdedf10_SimdReal
{
  public:
    __forceinline Sdedf10_SimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline ::__m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    ::__m128 m_vValue;
};

class Sdedf10_Vector4
{
  public:
    __forceinline Sdedf10_Vector4()
    {}
    __forceinline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    __forceinline void add4(const Sdedf10_Vector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setAdd4(const Sdedf10_Vector4& a, const Sdedf10_Vector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setSub4(const Sdedf10_Vector4& a, const Sdedf10_Vector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const Sdedf10_SimdReal& s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    ::__m128 m_vComponents;
};

class Sdedf10_Aabb
{
  public:
    __forceinline static void* __cdecl operator new(std::size_t, Sdedf10_PlacementArg* p) throw()
    {
        return p;
    }
    __forceinline static void __cdecl operator delete(void*, Sdedf10_PlacementArg*) throw()
    {}
    __forceinline Sdedf10_Aabb()
    {}
    Sdedf10_Vector4 m_kMinimumCorner;
    Sdedf10_Vector4 m_kMaximumCorner;
};

__forceinline void Sdedf10_calcAabb(const Sdedf10_Vector4& center, float innerRadius, Sdedf10_Aabb& aabbOut)
{
    Sdedf10_Vector4 ir;
    ir.SetAllComponents(innerRadius);
    aabbOut.m_kMinimumCorner.setSub4(center, ir);
    aabbOut.m_kMaximumCorner.setAdd4(center, ir);
    aabbOut.m_kMinimumCorner(3) = 0;
    aabbOut.m_kMaximumCorner(3) = 0;
}

struct Sdedf10_IFunction
{
    __forceinline Sdedf10_IFunction()
    {}
    virtual ~Sdedf10_IFunction()
    {}
    virtual float evaluate(const Sdedf10_Vector4&) const = 0;
};

struct Sdedf10_ConstFunction : Sdedf10_IFunction
{
    Sdedf10_ConstFunction(const float& value) : m_uiFilterValue(value)
    {}
    float evaluate(const Sdedf10_Vector4&) const
    {
        return m_uiFilterValue;
    }
    float m_uiFilterValue;
};

struct Sdedf10_PseudoRandom
{
    __forceinline Sdedf10_PseudoRandom(int s)
    {
        m_uiState = (unsigned int)s;
        m_pTileTemplate = m_uiState;
    }
    unsigned int m_uiState;
    unsigned int m_pTileTemplate;
};

struct Sdedf10_Geometry;
struct Sdedf10_Transform;

struct __declspec(align(16)) Sdedf10_Mesh
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;

    Sdedf10_Mesh();
    ~Sdedf10_Mesh();
};

struct Sdedf10_NodeManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ~Sdedf10_NodeManager();
};

struct Sdedf10_TreeNode
{
    Sdedf10_Aabb m_iBufferSize;
    void* m_ulUserData;
    template <typename T> __forceinline T getLeafData() const
    {
        return reinterpret_cast<T>(m_ulUserData);
    }
};

class Sdedf10_Tree
{
  public:
    Sdedf10_Tree();
    virtual ~Sdedf10_Tree()
    {
        reinterpret_cast<::FUN_00d9be30_class *>(this)->FUN_00d9be30();
    }
    void clear();

    Sdedf10_TreeNode* m_pAabbRootNode;
    unsigned int m_usManagerValue;
    int m_iNodeCount;
    Sdedf10_NodeManager m_kNodeManager;
    Sdedf10_Vector4 m_kAabbMin;
    Sdedf10_Vector4 m_kAabbMaximum;
    Sdedf10_Vector4 m_kAabbScale;
    Sdedf10_Vector4 m_kAabbInverseScale;
};

struct Sdedf10_Collector
{
    __forceinline Sdedf10_Collector()
    {}
    virtual ~Sdedf10_Collector()
    {}
    virtual float GetHitDistance(const Sdedf10_TreeNode* leaf) = 0;
};

struct Sdedf10_ClosestPointCollector : Sdedf10_Collector
{
    __forceinline Sdedf10_ClosestPointCollector(const Sdedf10_Vector4& point, float initDistanceSquared)
        : m_kPoint(point), m_fValue(initDistanceSquared)
    {}
    virtual ~Sdedf10_ClosestPointCollector()
    {}
    virtual float GetHitDistance(const Sdedf10_TreeNode* leaf) = 0;

    Sdedf10_Vector4 m_kPoint;
    float m_fValue;
};

struct Sdedf10_NearestFeaturePolicy : Sdedf10_ClosestPointCollector
{
    __forceinline Sdedf10_NearestFeaturePolicy(const Sdedf10_Vector4& point, float maxDistance)
        : Sdedf10_ClosestPointCollector(point, maxDistance), m_nearest(0)
    {}
    virtual ~Sdedf10_NearestFeaturePolicy()
    {}
    virtual float GetHitDistance(const Sdedf10_TreeNode* leaf);

    const Sdedf10_TreeNode* m_nearest;
};


// @fnv 0x00dedf10
bool __cdecl FUN_00dedf10(const Sdedf10_Geometry& geometry, intptr_t numPoints, Sdedf10_Array<Sdedf10_Vector4>& points,
                          intptr_t maxIterations, int seed, const Sdedf10_IFunction* densityFunction)
{
    static Sdedf10_ConstFunction unityFunction(1);
    Sdedf10_PseudoRandom rng(seed);
    if (!densityFunction)
    {
        densityFunction = &unityFunction;
    }

    Sdedf10_Mesh mesh;
    reinterpret_cast<::S_e1ce10_Mesh *>(&(mesh))->FUN_00e1ce10((const ::S_e1ce10_Geometry &)(geometry), (const ::S_e1ce10_Transform &)((*reinterpret_cast<const ::Sdedf10_Transform *>(&::DAT_01268370))), -1);
    reinterpret_cast<::HostE10 *>(&(mesh))->FUN_00e11e10();
    reinterpret_cast<::Z_E15E50 *>(&(mesh))->FUN_00e15e50();

    const int base = points.GetLogicalSize();
    if (!::FUN_00dedbb0((::Owner *)&(mesh), numPoints, (::Vec4Array *)&(points), (::Obj *)&(rng)))
    {
        return false;
    }

    if (maxIterations > 0)
    {
        Sdedf10_Vector4* pts = &points[base];
        Sdedf10_Array<unsigned int> leaves;
        Sdedf10_Tree tree;
        leaves.SetSizeAndGrow(numPoints);
        Sdedf10_Array<Sdedf10_Aabb, Sdedf10_TypeIsClass> aabbs;
        Sdedf10_Array<void*> datas;
        for (int i = 0; i < numPoints; ++i)
        {
            Sdedf10_Aabb box;
            Sdedf10_calcAabb(pts[i], 0, box);
            aabbs.AddBack(box);
            datas.AddBack(&pts[i]);
            const float w = densityFunction->evaluate(pts[i]);
            pts[i].mul4(w);
            pts[i](3) = w;
        }
        reinterpret_cast<::S_00d9d650_Tree *>(&(tree))->BuildTree((const ::S_00d9d650_Aabb *)(::Sdedf10_Aabb *)(aabbs.begin()), (const int *)(void **)(datas.begin()), aabbs.GetLogicalSize(), (::S_00d9d650_Array<int> &)(leaves));

        Sdedf10_Array<Sdedf10_Vector4> samples;
        const intptr_t doubled = numPoints * 2;
        const intptr_t numSamples = doubled < 0x100 ? 0x100 : (doubled > 0x2000 ? 0x2000 : doubled);
        samples.reserveExactly(numSamples);

        for (int iter = 0; iter < maxIterations; ++iter)
        {
            samples.clear();
            if (!::FUN_00dedbb0((::Owner *)&(mesh), numSamples, (::Vec4Array *)&(samples), (::Obj *)&(rng)))
            {
                return false;
            }
            for (int j = 0; j < samples.GetLogicalSize(); ++j)
            {
                Sdedf10_NearestFeaturePolicy policy(samples[j], 3.40282e38f);
                ::FUN_00d1dbb0((::AabbTree *)(&tree), (const ::VectorQ &)(samples[j]), (::ClosestCollector *)(::Sdedf10_Collector *)(&policy));
                if (policy.m_nearest)
                {
                    Sdedf10_Vector4* target = policy.m_nearest->getLeafData<Sdedf10_Vector4*>();
                    const float w = densityFunction->evaluate(samples[j]);
                    samples[j].mul4(w);
                    samples[j](3) = w;
                    target->add4(samples[j]);
                }
            }
            for (int k = 0; k < numPoints; ++k)
            {
                const float invW = 1.0f / pts[k](3);
                pts[k].mul4(invW);
                Sdedf10_Aabb box;
                Sdedf10_calcAabb(pts[k], 0, box);
                reinterpret_cast<::MapD9 *>(&(tree))->FUN_00d9be50(leaves[k], (const ::Block32 *)&(box));
                const float w = densityFunction->evaluate(pts[k]);
                pts[k].mul4(w);
                pts[k](3) = w;
            }
        }
    }
    return true;
}
struct Vector3
{
    float x, y, z;
};

// @fnv 0x00de98c0
void FUN_00de98c0(const Vector3* v, __m128* out)
{
    float ly = v->y;
    float lx = v->x;
    float a = (((double)(::Atan2(ly, lx))) * 2) / 3.1415927410125732;
    float b;
    if (v->z < 0)
    {
        float r = (float)(v->z + 1.0);
        r = (float)sqrt(r);
        if (a >= 0)
        {
            if (a <= 1)
            {
                a = 1.0 - a * r;
                b = 2.0 - r - a;
            }
            else
            {
                a = (2.0 - a) * r - 1.0;
                b = 2.0 - r + a;
            }
        }
        else if (a >= -1.0f)
        {
            a = a * r + 1.0;
            b = r - 2.0 + a;
        }
        else
        {
            a = (a + 2.0) * r - 1.0;
            b = r - 2.0 - a;
        }
    }
    else
    {
        float r = (float)(1.0 - v->z);
        r = (float)sqrt(r);
        if (a >= 0)
        {
            if (a < 1)
            {
                b = a * r;
                a = r - b;
            }
            else
            {
                b = (2.0 - a) * r;
                a = b - r;
            }
        }
        else if (a > -1.0f)
        {
            b = a * r;
            a = r + b;
        }
        else
        {
            b = (a + 2.0) * -r;
            a = -(r + b);
        }
    }
    a = (float)((a + 1.0) * 0.5);
    b = (float)((b + 1.0) * 0.5);
    *out = _mm_setr_ps(a, b, 0, 0);
}

struct Interval
{
    VectorComponentValue m_kMinimumCorner;
    VectorComponentValue m_kMaximumCorner;
};

static __forceinline void projectTriangle(const hkVector4* tri, const hkVector4& axis, Interval& out)
{
    out.m_kMaximumCorner = tri[0].dot3(axis);
    out.m_kMinimumCorner = out.m_kMaximumCorner;
    for (int i = 1; i < 3; i++)
    {
        VectorComponentValue d = tri[i].dot3(axis);
        if (d < out.m_kMinimumCorner)
        {
            out.m_kMinimumCorner = d;
        }
        else if (d > out.m_kMaximumCorner)
        {
            out.m_kMaximumCorner = d;
        }
    }
}

static __forceinline bool isSeparatingAxis(const hkVector4* triA, const hkVector4* triB, const hkVector4& axis,
                                           Interval& a, Interval& b)
{
    projectTriangle(triA, axis, a);
    projectTriangle(triB, axis, b);
    return a.m_kMinimumCorner > b.m_kMaximumCorner || a.m_kMaximumCorner < b.m_kMinimumCorner;
}

static __forceinline void calcEdgeAxis(const hkVector4& a0, const hkVector4& a1, const hkVector4& b0,
                                       const hkVector4& b1, hkVector4& axis)
{
    hkVector4 ea;
    ea.setSub4(a1, a0);
    hkVector4 eb;
    eb.setSub4(b1, b0);
    axis.setCross(ea, eb);
}

// @fnv 0x00deab10
int __cdecl FUN_00deab10(const hkVector4* triA, const hkVector4* triB)
{
    hkVector4 axis;
    Interval a;
    Interval b;
    {
        hkVector4 e0;
        e0.setSub4(triA[1], triA[0]);
        hkVector4 e1;
        e1.setSub4(triA[2], triA[0]);
        axis.setCross(e0, e1);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        hkVector4 e0;
        e0.setSub4(triB[1], triB[0]);
        hkVector4 e1;
        e1.setSub4(triB[2], triB[0]);
        axis.setCross(e0, e1);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[0], triA[1], triB[0], triB[1], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[0], triA[1], triB[1], triB[2], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[0], triA[1], triB[2], triB[0], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[1], triA[2], triB[0], triB[1], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[1], triA[2], triB[1], triB[2], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[1], triA[2], triB[2], triB[0], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[2], triA[0], triB[0], triB[1], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[2], triA[0], triB[1], triB[2], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        calcEdgeAxis(triA[2], triA[0], triB[2], triB[0], axis);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[0], triB[0]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[0], triB[1]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[0], triB[2]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[1], triB[0]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[1], triB[1]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[1], triB[2]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[2], triB[0]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[2], triB[1]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    {
        axis.setSub4(triA[2], triB[2]);
        if (isSeparatingAxis(triA, triB, axis, a, b))
        {
            return 0;
        }
    }
    return 1;
}

struct Point4;
struct __declspec(align(16)) Point4
{
    float x, y, z, w;
    __forceinline Point4()
    {
        *this = (*reinterpret_cast<::Point4 *>(&::DAT_01267e30));
    }
};
struct VertexArray
{
    Point4* data;
    int size;
    int capacity;
};
struct FourPoints
{
    Point4 x, y, z;
    __forceinline void transpose(const Point4* p)
    {
        _mm_store_ps(&x.x, _mm_setr_ps(p[0].x, p[1].x, p[2].x, p[3].x));
        _mm_store_ps(&y.x, _mm_setr_ps(p[0].y, p[1].y, p[2].y, p[3].y));
        _mm_store_ps(&z.x, _mm_setr_ps(p[0].z, p[1].z, p[2].z, p[3].z));
    }
};
struct FourPointArray
{
    FourPoints* data;
    int size;
    int capacity;
};
// @fnv 0x00dedcf0
void __cdecl FUN_00dedcf0(const VertexArray& vertices, FourPointArray& output)
{
    Point4 points[4];
    int used = 0;
    int count = (vertices.size + 3) >> 2;
    AudioHolder* holder = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* allocator = holder->m_pAllocator;
    int start = output.size;
    int required = start + count;
    int capacity = output.capacity & 0x3fffffff;
    if (capacity < required)
    {
        int grown = required >= capacity * 2 ? required : capacity * 2;
        ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(void *)(&output), grown, sizeof(FourPoints));
    }
    output.size += count;
    FourPoints* destination = output.data + start;
    int vertexCount = vertices.size;
    for (int i = 0; i < vertexCount; ++i)
    {
        _mm_store_ps(&points[used++].x, _mm_load_ps(&vertices.data[i].x));
        if (used == 4)
        {
            destination->transpose(points);
            used = 0;
            ++destination;
        }
    }
    if (used)
    {
        for (int i = used; i < 4;)
            _mm_store_ps(&points[i++].x, _mm_load_ps(&points[0].x));
        destination->transpose(points);
    }
}
struct __declspec(align(16)) S_V4
{
    union
    {
        __m128 q;
        float data[4];
        struct
        {
            float x, y, z, w;
        };
    };
    void FUN_00c7f700(const struct S_Rot* r, const S_V4* v);
    S_V4()
    {}
    S_V4(const S_V4& o)
    {
        _mm_store_ps(&x, _mm_load_ps(&o.x));
    }
    S_V4& operator=(const S_V4& o)
    {
        _mm_store_ps(&x, _mm_load_ps(&o.x));
        return *this;
    }
};

static __forceinline void perpendicular(S_V4& out, const S_V4& src, S_V4& scratch)
{
    float a = fabs(src.x);
    float b = fabs(src.y);
    float c = fabs(src.z);
    int i = 0, j = 1, k = 2;
    if (b < a)
    {
        a = b;
        j = 0;
        i = 1;
    }
    if (c < a)
    {
        k = i;
    }
    _mm_store_ps(&out.x, _mm_setzero_ps());
    out.data[j] = src.data[k];
    out.data[k] = -src.data[j];
    scratch = out;
    __m128 m = _mm_load_ps(&scratch.x);
    __m128 sq = _mm_mul_ps(m, m);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sum);
    float len;
    _mm_store_ss(&len, sum);
    if (len != 0.0f)
    {
        float inv = 1.0f / (float)sqrt(len);
        _mm_store_ps(&out.x, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&inv), _mm_load_ss(&inv), 0), m));
    }
}

struct S_Rot
{
    S_V4 r0;
    S_V4 r1;
    S_V4 r2;
    S_V4 translation;
};

struct S_Body
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    S_V4 velocity;
    S_V4 axis;  // 0xe0
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int type;
};

struct S_Self
{
    int unk00;
    int unk04;
    S_Body* body;
};

struct AxisOwner : S_Self
{
    S_V4 FUN_00d76d90();
};

// @fnv 0x00d76d90
S_V4 AxisOwner::FUN_00d76d90()
{
    S_V4 out;
    _mm_store_ps(&out.x, _mm_setzero_ps());
    S_V4 zero;
    _mm_store_ps(&zero.x, _mm_setzero_ps());
    S_Body* bd = body;
    switch (bd->type)
    {
    case 1: {
        perpendicular(out, bd->velocity, zero);
        break;
    }
    case 2:
        out = bd->axis;
        break;
    case 3: {
        float d[4];
        S_Rot rot;
        reinterpret_cast<::FnvCpu_FUN_00d76d80_CpuOwner *>(this)->FUN_00d76d80();
        int idx;
        if (d[0] < d[1])
            idx = (d[2] > d[0]) ? 0 : 2;
        else
            idx = (d[2] > d[1]) ? 1 : 2;
        S_V4 v;
        v = zero;
        ((float*)&v)[idx] = 1.0f;
        out.FUN_00c7f700(&rot, &v);
        break;
    }
    }
    out.w = 0;
    return out;
}struct SphereInput276
{
    float a, b;
};
struct __declspec(align(16)) SphereOutput276
{
    __m128 value;
};
// @fnv 0x00de9650
extern "C" void FUN_00de9650(SphereInput276* in, SphereOutput276* out)
{
    float u = 2.0 * in->a - 1.0;
    float v = 2.0 * in->b - 1.0;
    float sum = u + v;
    float difference = v - u;
    float radius, sign, angle;
    if (v >= 0.0f)
    {
        if (u >= 0.0f)
        {
            if (sum <= 1.0f)
            {
                radius = sum;
                sign = 1.0f;
                angle = v / radius;
            }
            else
            {
                radius = 2.0 - sum;
                sign = -1.0f;
                angle = (1.0f - u) / radius;
            }
        }
        else
        {
            if (difference <= 1.0f)
            {
                radius = difference;
                sign = 1.0f;
                angle = 1.0f - u / radius;
            }
            else
            {
                radius = 2.0 - difference;
                sign = -1.0f;
                angle = 1.0f + (1.0f - v) / radius;
            }
        }
    }
    else
    {
        if (u < 0.0f)
        {
            if (sum >= -1.0f)
            {
                radius = -sum;
                sign = 1.0f;
                angle = 2.0 - v / radius;
            }
            else
            {
                radius = sum + 2.0;
                sign = -1.0f;
                angle = 2.0 + (1.0f + u) / radius;
            }
        }
        else
        {
            if (difference >= -1.0f)
            {
                radius = -difference;
                sign = 1.0f;
                angle = 3.0 + u / radius;
            }
            else
            {
                radius = difference + 2.0;
                sign = -1.0f;
                angle = 3.0 + (1.0f + v) / radius;
            }
        }
    }
    if (radius == 0.0f)
        angle = 0.0f;
    else
        angle *= 1.5707963705062866;
    float squared = radius * radius;
    float radialSquared = 2.0 - squared;
    float radialRoot = (float)sqrt(radialSquared);
    radius = radialRoot * radius;
    float cosine = (float)cos(angle);
    float x = cosine * radius;
    float sine = (float)sin(angle);
    float z = sine * radius;
    float y = (1.0f - squared) * sign;
    out->value = _mm_setr_ps(x, z, y, 0.0f);
}

extern "C" void _ReadBarrier();

__declspec(align(16)) struct Vec4Pair
{
    Vec4 a;
    Vec4 b;
};

struct Vec4Array
{
    Vec4* m_00;
    int m_04;
    unsigned int m_08;
};

struct Owner
{
    void FUN_00e11530(Vec4Pair* out);
    float FUN_00e13660(Vec4* p, Vec4* q, unsigned char* ok);
};

struct Obj
{
};


// @fnv 0x00dedbb0
bool __cdecl FUN_00dedbb0(Owner* self, intptr_t count, Vec4Array* out, Obj* obj)
{
    Vec4Pair pair;
    Vec4 scratch;
    Vec4 delta;
    Vec4 base;
    Vec4 cur;
    intptr_t limit;
    unsigned char flag;
    int tries;

    self->FUN_00e11530(&pair);
    base = pair.a;
    _mm_store_ps((float*)(void*)&delta,
                 _mm_sub_ps(_mm_load_ps((const float*)&pair.b), _mm_load_ps((const float*)&pair.a)));
    tries = 0;
    limit = count * 8;
    while (count != 0)
    {
        cur = (*reinterpret_cast<::Vec4 *>(&::DAT_01267e30));
        flag = 1;
        reinterpret_cast<::FUN_00d5d660_cls *>((obj))->NextFloat4((float *)(::Vec4 *)(&cur));
        _mm_store_ps((float*)(void*)&cur, _mm_add_ps(_mm_mul_ps(*(__m128*)&cur, *(__m128*)&delta), *(__m128*)&base));
        self->FUN_00e13660(&cur, &scratch, &flag);
        if (flag != 0)
        {
            fnv_simd_as<float>(cur.value)[3] = 1.0f;
            AudioHolder* holder = static_cast<AudioHolder*>(::FUN_00c85750());
            if (out->m_04 == (int)(out->m_08 & 0x3fffffff))
            {
                ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(out), 0x10);
            }
            Vec4* __restrict dst = out->m_00 + out->m_04;
            _mm_store_ps((float*)dst, _mm_load_ps((const float*)&cur));
            count--;
            _ReadBarrier();
            out->m_04++;
            tries = 0;
        }
        else
        {
            tries++;
            if (tries > limit)
            {
                break;
            }
        }
    }
    return count == 0;
}

// @fnv 0x00de9e10
float __cdecl FUN_00de9e10(float* arg1, float* arg2, float* arg3, float* result, float* optionalResult)
{
    __m128 b = _mm_load_ps(arg2);
    __m128 a = _mm_load_ps(arg1);
    __m128 d1 = _mm_sub_ps(b, a);
    __m128 c = _mm_load_ps(arg3);
    __m128 d2 = _mm_sub_ps(c, b);
    __m128 n2 = _mm_mul_ps(d2, d2);
    __m128 m = _mm_mul_ps(d2, d1);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), xy);
    __m128 num = _mm_sub_ss(_mm_load_ps((*reinterpret_cast<float (*)[4]>(&::DAT_010c7160))), sum);
    __m128 nxy = _mm_add_ss(_mm_shuffle_ps(n2, n2, 0x55), n2);
    __m128 nsum = _mm_add_ss(_mm_shuffle_ps(n2, n2, 0xaa), nxy);
    float t;
    _mm_store_ss(&t, _mm_div_ss(num, nsum));
    float k = t < 0.0f ? 0.0f : t > 1.0f ? 1.0f : t;
    __m128 factor = _mm_load_ss(&k);
    __m128 v = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), d2), d1);
    __m128 neg = _mm_load_ss(&::DAT_01012054);
    _mm_store_ps(result, _mm_mul_ps(_mm_shuffle_ps(neg, neg, 0), v));
    if (optionalResult)
        *optionalResult = k;
    __m128 sq = _mm_mul_ps(v, v);
    __m128 sqxy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 sqsum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sqxy);
    _mm_store_ss(&k, sqsum);
    return k;
}

#include "generated/data/havok/common/internal/geometryprocessing/hkgeometryprocessing.inc"
