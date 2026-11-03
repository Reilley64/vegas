
// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <xmmintrin.h>
#include "fnv_simd.h"
#include <cmath>
#include "fnv/decl/FUN_00cb20b0_shell.h"
#include "fnv/decl/FUN_00de87c0_class.h"
#include "fnv/decl/MProduct.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0104d000.h"
struct FUN_00de8f30_Class
{
    float m_data[16];
    void TransposeTo(float* dst);
};

// @fnv 0x00de8f30
void FUN_00de8f30_Class::TransposeTo(float* afOut)
{
    afOut[0] = m_data[0];
    afOut[4] = m_data[1];
    afOut[8] = m_data[2];
    afOut[12] = m_data[3];
    afOut[1] = m_data[4];
    afOut[5] = m_data[5];
    afOut[9] = m_data[6];
    afOut[13] = m_data[7];
    afOut[2] = m_data[8];
    afOut[6] = m_data[9];
    afOut[10] = m_data[10];
    afOut[14] = m_data[11];
    afOut[3] = m_data[12];
    afOut[7] = m_data[13];
    afOut[11] = m_data[14];
    afOut[15] = m_data[15];
}

struct FUN_00de8f10_Class
{
    float m_data[16];
    void FUN_00de8f10();
};

// @fnv 0x00de8f10
void FUN_00de8f10_Class::FUN_00de8f10()
{
    m_data[11] = 0.0f;
    m_data[7] = 0.0f;
    m_data[3] = 0.0f;
    m_data[15] = 1.0f;
}

struct FUN_00de8fa0_Class
{
    float m_data[16];
    void FUN_00de8fa0(const float* src);
};

// Copies 16 floats from src into m_data in transposed order (row/column swap).
// @fnv 0x00de8fa0
void FUN_00de8fa0_Class::FUN_00de8fa0(const float* src)
{
    m_data[0] = src[0];
    m_data[1] = src[4];
    m_data[2] = src[8];
    m_data[3] = src[12];
    m_data[4] = src[1];
    m_data[5] = src[5];
    m_data[6] = src[9];
    m_data[7] = src[13];
    m_data[8] = src[2];
    m_data[9] = src[6];
    m_data[10] = src[10];
    m_data[11] = src[14];
    m_data[12] = src[3];
    m_data[13] = src[7];
    m_data[14] = src[11];
    m_data[15] = src[15];
}

struct FUN_00de9010_Class
{
    float m_data[16];
    void CopyTo(float* dst);
};

// Copies the 16 floats in m_data into the destination array.
// @fnv 0x00de9010
void FUN_00de9010_Class::CopyTo(float* afOut)
{
    *afOut = m_data[0];
    afOut[1] = m_data[1];
    afOut[2] = m_data[2];
    afOut[3] = m_data[3];
    afOut[4] = m_data[4];
    afOut[5] = m_data[5];
    afOut[6] = m_data[6];
    afOut[7] = m_data[7];
    afOut[8] = m_data[8];
    afOut[9] = m_data[9];
    afOut[10] = m_data[10];
    afOut[11] = m_data[11];
    afOut[12] = m_data[12];
    afOut[13] = m_data[13];
    afOut[14] = m_data[14];
    afOut[15] = m_data[15];
}

struct FUN_00de9080_Class
{
    float m_data[16];
    void CopyFromFloats(const float* src);
};
// Copies 16 floats from src into m_data.
// @fnv 0x00de9080
void FUN_00de9080_Class::CopyFromFloats(const float* apSource)
{
    m_data[0] = apSource[0];
    m_data[1] = apSource[1];
    m_data[2] = apSource[2];
    m_data[3] = apSource[3];
    m_data[4] = apSource[4];
    m_data[5] = apSource[5];
    m_data[6] = apSource[6];
    m_data[7] = apSource[7];
    m_data[8] = apSource[8];
    m_data[9] = apSource[9];
    m_data[10] = apSource[10];
    m_data[11] = apSource[11];
    m_data[12] = apSource[12];
    m_data[13] = apSource[13];
    m_data[14] = apSource[14];
    m_data[15] = apSource[15];
}


#include "fnv/symbols_simd.h"

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};

struct hkMatrix4
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
    void FUN_00de8e50(const hkMatrix4& b);
    void operator=(const hkMatrix4& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_kColumn3 = o.m_kColumn3;
    }
};

struct FUN_00de90f0_Class
{
    __m128 rows[4];
    void FUN_00de90f0(const __m128* source);
};
// Copies four __m128 rows from source into rows, then forces the fourth component of each row to 0,0,0,1.
// @fnv 0x00de90f0
void FUN_00de90f0_Class::FUN_00de90f0(const __m128* source)
{
    rows[0] = source[0];
    rows[1] = source[1];
    rows[2] = source[2];
    rows[3] = source[3];
    volatile float* pfValues = (volatile float*)this;
    pfValues[3] = 0.0f;
    pfValues[7] = 0.0f;
    pfValues[11] = 0.0f;
    pfValues[15] = 1.0f;
}

struct CB20B0_Class
{
};
struct Matrix44_shell
{
    float m_data[16];
    void FUN_00de9130(CB20B0_Class* dst);
};
// @fnv 0x00de9130
void Matrix44_shell::FUN_00de9130(CB20B0_Class* dst)
{
    reinterpret_cast<::FUN_00cb20b0_shell *>((dst))->FUN_00cb20b0((const ::Matrix44 *)(void *)(this));
}

struct Owner
{
    __m128 row00;
    __m128 row10;
    __m128 row20;
    __m128 row30;
    void FUN_00de8c50(const __m128* source, float value);
};

struct SourceBlockCDF
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
};
struct TargetBlockCDF
{
};
struct FUN_00cdf230_cls
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
    SourceBlockCDF m_kSource;
    TargetBlockCDF m_kRoomNode;
    void FUN_00cdf230(intptr_t iArg);
};
// @fnv 0x00cdf230
void FUN_00cdf230_cls::FUN_00cdf230(intptr_t iArg)
{
    reinterpret_cast<::MProduct *>(&(m_kRoomNode))->FUN_00cd55b0((*(const ::MProduct *)(&m_kSource)), (*(const ::MProduct *)(iArg)));
}


struct Row
{
    __m128 v;
    void operator+=(const Row& o)
    {
        __m128 t = o.v;
        v = _mm_add_ps(t, v);
    }
};

struct MatR
{
    Row m_row0;
    Row m_row1;
    Row m_row2;
    Row m_row3;
    const MatR* Add(const MatR* other);
};

// Adds each of other's four rows into this matrix's matching rows and returns other.
// @fnv 0x00de8c90
const MatR* MatR::Add(const MatR* other)
{
    m_row0 += other->m_row0;
    m_row1 += other->m_row1;
    m_row2 += other->m_row2;
    m_row3 += other->m_row3;
    return other;
}


__declspec(align(16)) struct S00de9270_Vec
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

struct S00de9270_Mat
{
    S00de9270_Vec m_r0;
    S00de9270_Vec m_r1;
    S00de9270_Vec m_r2;
    S00de9270_Vec m_r3;
};

struct FUN_00de8910_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de8910(float s);
};

struct FUN_00de8da0_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
};

__declspec(noinline) void FUN_00de8910_Class::FUN_00de8910(float s)
{
    unk00 = s;
    unsigned u = (unsigned)(int)s;
    unk04 = (float)(int)(u / 10u);
}

struct S00de9270_cls
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de9270(void* dst, const S00de9270_Mat* src);
};


struct MatrixSubtract : hkMatrix4
{
    const hkMatrix4* FUN_00de8ce0(const hkMatrix4* rhs);
};

// Subtracts the four columns of rhs from this matrix using SSE and returns rhs.
// @fnv 0x00de8ce0
const hkMatrix4* MatrixSubtract::FUN_00de8ce0(const hkMatrix4* rhs)
{
    *(__m128*)&m_kColumn0 = _mm_sub_ps(*(const __m128*)&m_kColumn0, *(const __m128*)&rhs->m_kColumn0);
    *(__m128*)&m_kColumn1 = _mm_sub_ps(*(const __m128*)&m_kColumn1, *(const __m128*)&rhs->m_kColumn1);
    *(__m128*)&m_kColumn2 = _mm_sub_ps(*(const __m128*)&m_kColumn2, *(const __m128*)&rhs->m_kColumn2);
    *(__m128*)&m_kColumn3 = _mm_sub_ps(*(const __m128*)&m_kColumn3, *(const __m128*)&rhs->m_kColumn3);
    return rhs;
}


struct C
{
    __m128 m_00;
    __m128 m_10;
    __m128 m_20;
    __m128 m_30;
    const __m128* FUN_00de8d30(const __m128* s);
};

// @fnv 0x00de8d30
const __m128* C::FUN_00de8d30(const __m128* apVector)
{
    __m128 v = *apVector;
    m_00 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_00);
    v = *apVector;
    m_10 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_10);
    v = *apVector;
    m_20 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_20);
    v = *apVector;
    m_30 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m_30);
    return apVector;
}


struct Matrix4Q
{
    hkVector4 row0;
    hkVector4 row1;
    hkVector4 row2;
    hkVector4 row3;

    Matrix4Q(const Matrix4Q& value)
    {
        *(__m128*)&row0 = *(const __m128*)&value.row0;
        *(__m128*)&row1 = *(const __m128*)&value.row1;
        *(__m128*)&row2 = *(const __m128*)&value.row2;
        *(__m128*)&row3 = *(const __m128*)&value.row3;
    }

    __declspec(noinline) void SwapFields(hkMatrix4* context);
};

void Matrix4Q::SwapFields(hkMatrix4* context)
{
    __m128* vectors = reinterpret_cast<__m128*>(this);
    __m128 low01 = _mm_unpacklo_ps(vectors[0], vectors[1]);
    __m128 high01 = _mm_unpackhi_ps(vectors[0], vectors[1]);
    __m128 low23 = _mm_unpacklo_ps(vectors[2], vectors[3]);
    __m128 high23 = _mm_unpackhi_ps(vectors[2], vectors[3]);
    vectors[0] = _mm_movelh_ps(low01, low23);
    vectors[1] = _mm_movehl_ps(low23, low01);
    vectors[2] = _mm_movelh_ps(high01, high23);
    vectors[3] = _mm_movehl_ps(high23, high01);
}

__forceinline float Dot4(const float* left, const float* right)
{
    __m128 first = *reinterpret_cast<const __m128*>(left);
    __m128 second = *reinterpret_cast<const __m128*>(right);
    __m128 product = _mm_mul_ps(first, second);
    __m128 halves = _mm_add_ps(_mm_shuffle_ps(product, product, 0x4e), product);
    __m128 sum = _mm_add_ps(_mm_shuffle_ps(halves, halves, 0xb1), halves);
    float scalar;
    _mm_store_ss(&scalar, sum);
    return scalar;
}

struct MatrixPointerQ
{
    const Matrix4Q* volatile value;
};
struct Matrix4V
{
    void FUN_00de8da0(const Matrix4Q* left, MatrixPointerQ right);
};
// @fnv 0x00de8e50
void hkMatrix4::FUN_00de8e50(const hkMatrix4& b)
{
    hkMatrix4 t;
    reinterpret_cast<::Matrix4V *>(&(t))->FUN_00de8da0((const ::Matrix4Q *)&(*this), (*(::MatrixPointerQ *)&(b)));
    *this = t;
}

// Stores the matrix product formed by dotting each row of right with each column of left.
// @fnv 0x00de8da0
void Matrix4V::FUN_00de8da0(const Matrix4Q* left, MatrixPointerQ right)
{
    Matrix4Q columns(*left);
    reinterpret_cast<::FUN_00de87c0_class *>(&(columns))->SwapFields();
    float* destination = reinterpret_cast<float*>(this);
    const float* input = reinterpret_cast<const float*>(right.value);
    for (int row = 0; row != 4; ++row)
    {
        for (int column = 0; column != 4; ++column)
        {
            destination[row * 4 + column] =
                Dot4(input + row * 4, reinterpret_cast<const float*>(&columns) + column * 4);
        }
    }
}


struct FUN_00de8ea0_cls
{
    float m_data[16];

    int FUN_00de8ea0();
};

// Compares four selected values with two constants, then returns whether the first three absolute differences are at most DAT_01011d78.
// @fnv 0x00de8ea0
int FUN_00de8ea0_cls::FUN_00de8ea0()
{
    __m128 column = _mm_setr_ps(m_data[3], m_data[7], m_data[11], m_data[15]);
    __m128 ref = _mm_setr_ps(::DAT_01011d78, ::DAT_01011d78, ::DAT_01011d78, DAT_01012068);
    __m128 diff = _mm_sub_ps(column, ref);
    __m128 absDiff = _mm_and_ps(diff, ::DAT_01017d10);
    __m128 bound = _mm_set_ps1(::DAT_01011d78);
    __m128 cmp = _mm_cmple_ps(absDiff, bound);
    int mask = _mm_movemask_ps(cmp) & 7;
    return mask == 7;
}


class S00de9140_SimdReal
{
  public:
    __forceinline S00de9140_SimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __m128 m_vValue;
};

class S00de9140_Vector4
{
  public:
    __forceinline S00de9140_Vector4()
    {}
    __forceinline S00de9140_Vector4(const S00de9140_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const S00de9140_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setMul4(const S00de9140_SimdReal& r, const S00de9140_Vector4& v)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
    }
    __forceinline void add4(const S00de9140_Vector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setMul4(const S00de9140_Vector4& a, const S00de9140_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const S00de9140_Vector4& x, const S00de9140_Vector4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setBroadcast(const S00de9140_Vector4& v, int i)
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
    float& operator()(int i)
    {
        return ((float*)&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __m128 m_vComponents;
};

class S00de9140_Matrix4
{
  public:
    S00de9140_Vector4 m_kColumn0;
    S00de9140_Vector4 m_kColumn1;
    S00de9140_Vector4 m_kColumn2;
    S00de9140_Vector4 m_kColumn3;

    __forceinline S00de9140_Matrix4()
    {}
    __forceinline S00de9140_Vector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline const S00de9140_Vector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    __forceinline const float& operator()(int r, int c) const
    {
        return getColumn(c)(r);
    }
    __forceinline void operator=(const S00de9140_Matrix4& a)
    {
        m_kColumn0 = a.getColumn(0);
        m_kColumn1 = a.getColumn(1);
        m_kColumn2 = a.getColumn(2);
        m_kColumn3 = a.getColumn(3);
    }

    void FUN_00de88a0(const S00de9140_SimdReal& s, const S00de9140_Matrix4& m);
    int FUN_00de8910(float epsilon);

    __forceinline void transformPosition(const S00de9140_Vector4& positionIn, S00de9140_Vector4& positionOut) const
    {
        S00de9140_Vector4 xb;
        xb.setBroadcast(positionIn, 0);
        S00de9140_Vector4 yb;
        yb.setBroadcast(positionIn, 1);
        S00de9140_Vector4 zb;
        zb.setBroadcast(positionIn, 2);

        S00de9140_Vector4 t0;
        t0.setMul4(xb, m_kColumn0);
        t0.addMul4(yb, m_kColumn1);
        t0.addMul4(zb, m_kColumn2);
        t0.add4(m_kColumn3);

        positionOut = t0;
    }

    __forceinline void transformDirection(const S00de9140_Vector4& directionIn, S00de9140_Vector4& directionOut) const
    {
        S00de9140_Vector4 xb;
        xb.setBroadcast(directionIn, 0);
        S00de9140_Vector4 yb;
        yb.setBroadcast(directionIn, 1);
        S00de9140_Vector4 zb;
        zb.setBroadcast(directionIn, 2);

        S00de9140_Vector4 t0;
        t0.setMul4(xb, m_kColumn0);
        t0.addMul4(yb, m_kColumn1);
        t0.addMul4(zb, m_kColumn2);

        directionOut = t0;
    }

    __forceinline void setMulAffine(const S00de9140_Matrix4& a, const S00de9140_Matrix4& b)
    {
        S00de9140_Vector4 col0;
        a.transformDirection(b.m_kColumn0, col0);
        S00de9140_Vector4 col1;
        a.transformDirection(b.m_kColumn1, col1);
        S00de9140_Vector4 col2;
        a.transformDirection(b.m_kColumn2, col2);
        S00de9140_Vector4 col3;
        a.transformPosition(b.m_kColumn3, col3);

        m_kColumn0 = col0;
        m_kColumn1 = col1;
        m_kColumn2 = col2;
        m_kColumn3 = col3;
    }

    void FUN_00de9140(const S00de9140_Matrix4& a, const S00de9140_Matrix4& b);
};

__declspec(noinline) void S00de9140_Matrix4::FUN_00de88a0(const S00de9140_SimdReal& s, const S00de9140_Matrix4& m)
{
    m_kColumn0.setMul4(s, m.m_kColumn0);
    m_kColumn1.setMul4(s, m.m_kColumn1);
    m_kColumn2.setMul4(s, m.m_kColumn2);
    m_kColumn3.setMul4(s, m.m_kColumn3);
}

// @fnv 0x00de9140
void S00de9140_Matrix4::FUN_00de9140(const S00de9140_Matrix4& a, const S00de9140_Matrix4& b)
{
    S00de9140_Matrix4 bInv = b;
    bInv.FUN_00de8910(1.192092896e-07f);
    setMulAffine(a, bInv);
}

static __forceinline float zvalue(const S00de9140_Vector4& v)
{
    return fnv_simd_as<float>(v.m_vComponents)[2];
}
static __forceinline float scalarIdentity(float x)
{
    return x;
}
struct S00de8910_Work_b10903
{
    hkVector4 invDetVec;
    hkMatrix4 adj;
};

// @fnv 0x00de8910
int S00de9140_Matrix4::FUN_00de8910(float epsilon)
{
    const S00de9140_Vector4& column2 = m_kColumn2;
    const float& val2x = fnv_simd_as<float>(column2.m_vComponents)[0];
    const float& val2y = fnv_simd_as<float>(column2.m_vComponents)[1];
    const float& val2z = fnv_simd_as<float>(column2.m_vComponents)[2];
    const float& val2w = fnv_simd_as<float>(column2.m_vComponents)[3];

    float s0 =
        -((*(const volatile float*)&fnv_simd_as<float>(m_kColumn0.m_vComponents)[1]) * fnv_simd_as<float>(m_kColumn1.m_vComponents)[0]) +
        fnv_simd_as<float>(m_kColumn0.m_vComponents)[0] * fnv_simd_as<float>(m_kColumn1.m_vComponents)[1];
    float s1 = -((*(const volatile float*)&fnv_simd_as<float>(m_kColumn0.m_vComponents)[1]) * val2x) +
               (*(const volatile float*)&val2y) * fnv_simd_as<float>(m_kColumn0.m_vComponents)[0];
    float s2 =
        -((*(const volatile float*)&fnv_simd_as<float>(m_kColumn0.m_vComponents)[1]) * fnv_simd_as<float>(m_kColumn3.m_vComponents)[0]) +
        fnv_simd_as<float>(m_kColumn0.m_vComponents)[0] * fnv_simd_as<float>(m_kColumn3.m_vComponents)[1];
    float s3 = -(val2x * fnv_simd_as<float>(m_kColumn1.m_vComponents)[1]) + val2y * fnv_simd_as<float>(m_kColumn1.m_vComponents)[0];
    float s4 = -(fnv_simd_as<float>(m_kColumn3.m_vComponents)[0] * fnv_simd_as<float>(m_kColumn1.m_vComponents)[1]) +
               fnv_simd_as<float>(m_kColumn3.m_vComponents)[1] * fnv_simd_as<float>(m_kColumn1.m_vComponents)[0];
    float s5 = -(fnv_simd_as<float>(m_kColumn3.m_vComponents)[0] * val2y) + val2x * fnv_simd_as<float>(m_kColumn3.m_vComponents)[1];

    float c0 = -(fnv_simd_as<float>(m_kColumn1.m_vComponents)[2] * fnv_simd_as<float>(m_kColumn0.m_vComponents)[3]) +
               fnv_simd_as<float>(m_kColumn1.m_vComponents)[3] * fnv_simd_as<float>(m_kColumn0.m_vComponents)[2];
    float c1 = val2w * fnv_simd_as<float>(m_kColumn0.m_vComponents)[2] -
               (*(const volatile float*)&fnv_simd_as<float>(m_kColumn0.m_vComponents)[3]) * (float)(+val2z);
    float c2 = -(fnv_simd_as<float>(m_kColumn3.m_vComponents)[2] * fnv_simd_as<float>(m_kColumn0.m_vComponents)[3]) +
               fnv_simd_as<float>(m_kColumn3.m_vComponents)[3] * fnv_simd_as<float>(m_kColumn0.m_vComponents)[2];
    float c3 = -((*(const volatile float*)&fnv_simd_as<float>(m_kColumn1.m_vComponents)[3]) * (*(const volatile float*)&val2z)) +
               val2w * fnv_simd_as<float>(m_kColumn1.m_vComponents)[2];
    float c4 = -(fnv_simd_as<float>(m_kColumn3.m_vComponents)[2] * fnv_simd_as<float>(m_kColumn1.m_vComponents)[3]) +
               (*(const volatile float*)&fnv_simd_as<float>(m_kColumn3.m_vComponents)[3]) * fnv_simd_as<float>(m_kColumn1.m_vComponents)[2];
    float c5 = -(fnv_simd_as<float>(m_kColumn3.m_vComponents)[2] * (*(const volatile float*)&val2w)) +
               (*(const volatile float*)&fnv_simd_as<float>(m_kColumn3.m_vComponents)[3]) * (float)(double)val2z;

    S00de8910_Work_b10903 w;
    float det = (float)(s0)*c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
    float invDet = 1.0f / det;

    *(__m128*)&w.invDetVec = _mm_load_ss(&invDet);
    if ((float)fabs(det) <= epsilon)
    {
        return 1;
    }

    w.adj.m_kColumn0.x = fnv_simd_as<float>(m_kColumn1.m_vComponents)[1] * c5 - scalarIdentity(val2y) * c4 +
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[1] * c3;
    w.adj.m_kColumn0.y = -(*(const volatile float*)&fnv_simd_as<float>(m_kColumn0.m_vComponents)[1]) * c5 + val2y * c2 -
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[1] * c1;
    w.adj.m_kColumn0.z = -fnv_simd_as<float>(m_kColumn1.m_vComponents)[1] * c2 +
                         (*(const volatile float*)&fnv_simd_as<float>(m_kColumn0.m_vComponents)[1]) * c4 +
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[1] * scalarIdentity(c0);
    w.adj.m_kColumn0.w = fnv_simd_as<float>(m_kColumn1.m_vComponents)[1] * c1 -
                         (*(const volatile float*)&fnv_simd_as<float>(m_kColumn0.m_vComponents)[1]) * c3 - val2y * c0;

    w.adj.m_kColumn1.x =
        -fnv_simd_as<float>(m_kColumn1.m_vComponents)[0] * c5 + val2x * c4 - fnv_simd_as<float>(m_kColumn3.m_vComponents)[0] * c3;
    w.adj.m_kColumn1.y =
        fnv_simd_as<float>(m_kColumn0.m_vComponents)[0] * c5 - val2x * c2 + fnv_simd_as<float>(m_kColumn3.m_vComponents)[0] * c1;
    w.adj.m_kColumn1.z = -fnv_simd_as<float>(m_kColumn0.m_vComponents)[0] * c4 + fnv_simd_as<float>(m_kColumn1.m_vComponents)[0] * c2 -
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[0] * c0;
    w.adj.m_kColumn1.w =
        fnv_simd_as<float>(m_kColumn0.m_vComponents)[0] * c3 - fnv_simd_as<float>(m_kColumn1.m_vComponents)[0] * c1 + val2x * c0;

    w.adj.m_kColumn2.x =
        fnv_simd_as<float>(m_kColumn1.m_vComponents)[3] * s5 - val2w * s4 + fnv_simd_as<float>(m_kColumn3.m_vComponents)[3] * s3;
    w.adj.m_kColumn2.y =
        -fnv_simd_as<float>(m_kColumn0.m_vComponents)[3] * s5 + val2w * s2 - (float)(fnv_simd_as<float>(m_kColumn3.m_vComponents)[3]) * s1;
    w.adj.m_kColumn2.z = fnv_simd_as<float>(m_kColumn0.m_vComponents)[3] * s4 - fnv_simd_as<float>(m_kColumn1.m_vComponents)[3] * s2 +
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[3] * s0;
    w.adj.m_kColumn2.w =
        -fnv_simd_as<float>(m_kColumn0.m_vComponents)[3] * s3 + fnv_simd_as<float>(m_kColumn1.m_vComponents)[3] * s1 - val2w * s0;

    w.adj.m_kColumn3.x = -fnv_simd_as<float>(m_kColumn1.m_vComponents)[2] * s5 + zvalue(m_kColumn2) * s4 -
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[2] * s3;
    w.adj.m_kColumn3.y = fnv_simd_as<float>(m_kColumn0.m_vComponents)[2] * s5 - *(&fnv_simd_as<float>(m_kColumn2.m_vComponents)[2]) * s2 +
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[2] * s1;
    w.adj.m_kColumn3.z = -fnv_simd_as<float>(m_kColumn0.m_vComponents)[2] * s4 + fnv_simd_as<float>(m_kColumn1.m_vComponents)[2] * s2 -
                         fnv_simd_as<float>(m_kColumn3.m_vComponents)[2] * s0;
    w.adj.m_kColumn3.w =
        fnv_simd_as<float>(m_kColumn0.m_vComponents)[2] * s3 - fnv_simd_as<float>(m_kColumn1.m_vComponents)[2] * s1 + (float)(+val2z) * s0;

    FUN_00de88a0(*(const S00de9140_SimdReal*)&w.invDetVec, *(const S00de9140_Matrix4*)&w.adj);
    return 0;
}


class S00de92d0_SimdReal
{
  public:
    __forceinline S00de92d0_SimdReal(const __m128& x) : m_vValue(x)
    {}
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

class S00de92d0_Vector4
{
  public:
    __forceinline S00de92d0_Vector4()
    {}
    __forceinline void operator=(const S00de92d0_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float a, float b, float c, float d = 0)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setMul4(const S00de92d0_Vector4& a, const S00de92d0_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const S00de92d0_Vector4& x, const S00de92d0_Vector4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setBroadcast(const S00de92d0_Vector4& v, int i)
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
    __forceinline S00de92d0_SimdReal getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __m128 m_vComponents;
};

enum S00de92d0_Result
{
    S00de92d0_SUCCESS = 0,
    S00de92d0_FAILURE = 1
};

class S00de92d0_Matrix3
{
  public:
    S00de92d0_Vector4 m_kColumn0;
    S00de92d0_Vector4 m_kColumn1;
    S00de92d0_Vector4 m_kColumn2;

    __forceinline S00de92d0_Matrix3()
    {}
    __forceinline S00de92d0_Vector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline const S00de92d0_Vector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
    __forceinline void setRows(const S00de92d0_Vector4& r0, const S00de92d0_Vector4& r1, const S00de92d0_Vector4& r2)
    {
        getColumn(0).set(r0(0), r1(0), r2(0));
        getColumn(1).set(r0(1), r1(1), r2(1));
        getColumn(2).set(r0(2), r1(2), r2(2));
    }
    S00de92d0_Result FUN_00cd4f10(float epsilon);
    __forceinline void multiplyVector(const S00de92d0_Vector4& v, S00de92d0_Vector4& resultOut) const
    {
        S00de92d0_Vector4 xb;
        xb.setBroadcast(v, 0);
        S00de92d0_Vector4 yb;
        yb.setBroadcast(v, 1);
        S00de92d0_Vector4 zb;
        zb.setBroadcast(v, 2);

        S00de92d0_Vector4 t0;
        t0.setMul4(xb, m_kColumn0);
        t0.addMul4(yb, m_kColumn1);
        t0.addMul4(zb, m_kColumn2);

        resultOut = t0;
    }
};

class S00de92d0_GeometryProcessing
{
  public:
    static bool __cdecl FUN_00de92d0(const S00de92d0_Vector4& p0, const S00de92d0_Vector4& p1,
                                     const S00de92d0_Vector4& p2, S00de92d0_Vector4& intersection);
};

// @fnv 0x00de92d0
bool __cdecl S00de92d0_GeometryProcessing::FUN_00de92d0(const S00de92d0_Vector4& p0, const S00de92d0_Vector4& p1,
                                                        const S00de92d0_Vector4& p2, S00de92d0_Vector4& intersection)
{
    S00de92d0_Matrix3 m;
    S00de92d0_Vector4 d;
    d.set(-p0.getSimdAt(3), -p1.getSimdAt(3), -p2.getSimdAt(3), 0.0f);
    m.setRows(p0, p1, p2);
    if (m.FUN_00cd4f10(1.192092896e-07f) == S00de92d0_SUCCESS)
    {
        m.multiplyVector(d, intersection);
        return true;
    }
    return false;
}

// Copies four __m128 rows from source into row00..row30, then calls FUN_00de8910 with value.
// @fnv 0x00de8c50
void Owner::FUN_00de8c50(const __m128* apRows, float value)
{
    row00 = apRows[0];
    row10 = apRows[1];
    row20 = apRows[2];
    row30 = apRows[3];
    reinterpret_cast<::S00de9140_Matrix4 *>(this)->FUN_00de8910(value);
}
// Copies the matrix into a local, passes its first row to FUN_00de8910, then passes the local data to FUN_00de8da0 for writing to dst.
// @fnv 0x00de9270
void S00de9270_cls::FUN_00de9270(void* dst, const S00de9270_Mat* src)
{
    S00de9270_Mat matTmp;
    *(__m128*)&matTmp.m_r0 = *(const __m128*)&src->m_r0;
    *(__m128*)&matTmp.m_r1 = *(const __m128*)&src->m_r1;
    *(__m128*)&matTmp.m_r2 = *(const __m128*)&src->m_r2;
    *(__m128*)&matTmp.m_r3 = *(const __m128*)&src->m_r3;

    FUN_00de8910_Class* row = (FUN_00de8910_Class*)&matTmp.m_r0;
    reinterpret_cast<::S00de9140_Matrix4 *>((row))->FUN_00de8910(::DAT_0104da4c);

    reinterpret_cast<::Matrix4V *>((((FUN_00de8da0_Class*)this)))->FUN_00de8da0((const ::Matrix4Q *)(dst), ::MatrixPointerQ{(const ::Matrix4Q*)&matTmp.m_r0});
}
