
// src/havok/common/base/math/qstransform/hkqstransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/qstransform/hkqstransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00d72000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/FUN_00cb2050_cls.h"
#include "fnv/decl/MProduct.h"
#include "fnv/decl/RotationRows.h"
struct Matrix
{
    float values[12];
    bool* HasFiniteValues(bool* output);
};

// Checks the 12 matrix values (skipping indices 3 and 11) for infinite/NaN exponents and writes the result to output.
// @fnv 0x00ce50e0
bool* Matrix::HasFiniteValues(bool* pbFinite)
{
    for (int index = 0; index < 12; ++index)
    {
        if (index != 3 && index != 11)
        {
            union FloatBits
            {
                float value;
                unsigned int bits;
            } valueBits;
            valueBits.value = values[index];
            if ((valueBits.bits & 0x7f800000) == 0x7f800000)
            {
                *pbFinite = false;
                return pbFinite;
            }
        }
    }
    *pbFinite = true;
    return pbFinite;
}

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
struct S_00ce5070_Vector4
{
    __m128 m_vComponents;
};


struct S_00ce5070_Rotation
{
    S_00ce5070_Vector4 m_kColumn0;
    S_00ce5070_Vector4 m_kColumn1;
    S_00ce5070_Vector4 m_kColumn2;
};

struct S_00ce5070_Transform
{
    S_00ce5070_Rotation m_rotation;
    S_00ce5070_Vector4 m_vTranslation;
};

struct S_00ce5070_Quaternion
{
    S_00ce5070_Vector4 m_vec;
};

struct S_00ce5070_QsTransform
{
    S_00ce5070_Vector4 m_vTranslation;
    S_00ce5070_Quaternion m_rotation;
    S_00ce5070_Vector4 m_vScale;

    void FUN_00ce5070(const S_00ce5070_Transform& t);
};

// Copies rotation and translation from a Transform into the QsTransform, and sets scale to the constant DAT_010c7170.
// @fnv 0x00ce5070
void S_00ce5070_QsTransform::FUN_00ce5070(const S_00ce5070_Transform& akTransform)
{
    reinterpret_cast<::FUN_00827200_class *>(&(m_rotation))->FUN_00cb26e0((int)&(akTransform.m_rotation));
    m_vTranslation.m_vComponents = akTransform.m_vTranslation.m_vComponents;
    m_vScale.m_vComponents = (*reinterpret_cast<const ::S_00ce5070_Vector4 *>(&::DAT_010c7170)).m_vComponents;
}

class CB2FC0Object
{
  public:
};

class FUN_00ce50b0_cls
{
  public:
    void FUN_00ce50b0(CB2FC0Object* target);
};

// @fnv 0x00ce50b0
void FUN_00ce50b0_cls::FUN_00ce50b0(CB2FC0Object* target)
{
    Matrix* self = (Matrix*)this;
    reinterpret_cast<::RotationRows *>((target))->FUN_00cb2d90(&self->values[4]);
    __m128 vMatrix = _mm_load_ps(self->values);
    _mm_store_ps((float*)((char*)target + 0x30), vMatrix);
}

struct __declspec(align(16)) Vector
{
    float x, y, z, w;
};
struct FUN_008cd6a0_Class
{
    Vector row0, row1, row2;
};
struct FUN_00cdf250_class
{
    Vector row0, row1, row2;
};
struct TransformMatrix
{
    Vector row0, row1, row2, row3;
};
struct Transform
{
    Vector position;
    float rotationX, rotationY, rotationZ, rotationW;
    float scaleX, scaleY, scaleZ;
    void FUN_00ce51f0(int);
};
// Builds a matrix from rotation, scale, and position, then passes out to FUN_00cb2050.
// @fnv 0x00ce51f0
void Transform::FUN_00ce51f0(int out)
{
    FUN_008cd6a0_Class rotMatrix;
    reinterpret_cast<::RotationRows *>(&(rotMatrix))->FUN_00cb2d90(&rotationX);
    FUN_00cdf250_class scaleMatrix;
    *(__m128*)&scaleMatrix.row0 = _mm_setzero_ps();
    scaleMatrix.row0.x = scaleX;
    *(__m128*)&scaleMatrix.row1 = _mm_setzero_ps();
    scaleMatrix.row1.y = scaleY;
    *(__m128*)&scaleMatrix.row2 = _mm_setzero_ps();
    scaleMatrix.row2.z = scaleZ;
    FUN_00cdf250_class combinedMatrix;
    reinterpret_cast<::MProduct *>(&(combinedMatrix))->FUN_00cd55b0((*(const ::MProduct *)((int*)&rotMatrix)), (*(const ::MProduct *)((int)&scaleMatrix)));
    TransformMatrix resultMatrix;
    *(__m128*)&resultMatrix.row0 = *(__m128*)&combinedMatrix.row0;
    *(__m128*)&resultMatrix.row1 = *(__m128*)&combinedMatrix.row1;
    *(__m128*)&resultMatrix.row2 = *(__m128*)&combinedMatrix.row2;
    *(__m128*)&resultMatrix.row3 = *(__m128*)&position;
    reinterpret_cast<::FUN_00cb2050_cls *>(&(resultMatrix))->FUN_00cb2050((::FUN_00cb2050_cls *)(out));
}

struct S_00ce5290_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};

struct S_00ce5290_Bool
{
    char m_cBooleanValue;
    S_00ce5290_Bool(bool b)
    {
        m_cBooleanValue = b;
    }
};

struct S_00ce5290_Result
{
    S_00ce5290_Vector4 m_v0;
    S_00ce5290_Vector4 m_v1;
    S_00ce5290_Vector4 m_v2;
    char unk30;
    char unk31;
    short unk32;
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
};

void FUN_00d72e90(const void* input, S_00ce5290_Result* out);

struct S_00ce5290
{
    S_00ce5290_Vector4 m_v0;
    S_00ce5290_Vector4 m_v1;
    S_00ce5290_Vector4 m_v2;
    S_00ce5290_Bool SetFromInput(const void* input);
};

// Calls FUN_00d72e90 to compute a result from input, copies the three vector fields into m_v0, m_v1, m_v2, and returns whether res.unk31 is zero.
// @fnv 0x00ce5290
S_00ce5290_Bool S_00ce5290::SetFromInput(const void* input)
{
    __declspec(align(16)) S_00ce5290_Result result;
    FUN_00d72e90(input, &result);
    m_v0.q() = result.m_v0.q();
    m_v1.q() = result.m_v1.q();
    m_v2.q() = result.m_v2.q();
    return result.unk31 == 0;
}
extern "C" void _ReadWriteBarrier();


struct hkBool5120
{
    char m_cBooleanValue;
    hkBool5120(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkVector4_5120
{
    __m128 m_vComponents;
};

struct hkQsTransform5120
{
    hkVector4_5120 m_vTranslation;
    hkVector4_5120 m_rotation;
    hkVector4_5120 m_vScale;
    hkBool5120 FUN_00ce5120(const hkQsTransform5120& other, float epsilon) const;
};

// @fnv 0x00ce5120
hkBool5120 hkQsTransform5120::FUN_00ce5120(const hkQsTransform5120& other, float epsilon) const
{
    __m128 eps = _mm_set1_ps(epsilon);
    __m128 absMask = *(const __m128*)(*reinterpret_cast<const unsigned int (*)[4]>((void *)&::DAT_01017d10));
    __m128 t = _mm_and_ps(_mm_sub_ps(m_vTranslation.m_vComponents, other.m_vTranslation.m_vComponents), absMask);
    if ((_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) != 7)
        return false;
    t = _mm_and_ps(_mm_sub_ps(m_vScale.m_vComponents, other.m_vScale.m_vComponents), absMask);
    if ((_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) != 7)
        return false;
    __m128 rot = m_rotation.m_vComponents;
    _ReadWriteBarrier();
    t = other.m_rotation.m_vComponents;
    __m128 p = _mm_mul_ps(t, rot);
    __m128 s = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
    s = _mm_add_ps(_mm_shuffle_ps(s, s, 0xb1), s);
    float dot;
    _mm_store_ss(&dot, s);
    if (dot < 0.0f)
    {
        __m128 m1 = _mm_load_ss(&DAT_01012054);
        rot = _mm_mul_ps(_mm_shuffle_ps(m1, m1, 0), rot);
    }
    t = _mm_and_ps(_mm_sub_ps(rot, t), absMask);
    return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
}
