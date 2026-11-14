// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSMATRIX_H
#define FNV_BSMATRIX_H

#include "layout_support.h"
class SwizzledMatrix;
class FourByFourMatrix;
class FourComponentNumericValue;
class FourComponentNumericValue
{
  public:
    union
    {                                     // overlapping CodeView storage
        float m_afComponents[4];          // +0x0, 16 bytes
        unsigned int m_auiComponents[4];  // +0x0, 16 bytes
        struct
        {
            float x;  // +0x0, 4 bytes
            float y;  // +0x4, 4 bytes
            float z;  // +0x8, 4 bytes
            float w;  // +0xC, 4 bytes
        };
        float v[4];         // +0x0, 16 bytes
        unsigned int u[4];  // +0x0, 16 bytes
    };
};
class FourByFourMatrix
{
  public:
    union
    {                                    // overlapping CodeView storage
        FourComponentNumericValue r[4];  // +0x0, 64 bytes
        struct
        {
            float _11;  // +0x0, 4 bytes
            float _12;  // +0x4, 4 bytes
            float _13;  // +0x8, 4 bytes
            float _14;  // +0xC, 4 bytes
            float _21;  // +0x10, 4 bytes
            float _22;  // +0x14, 4 bytes
            float _23;  // +0x18, 4 bytes
            float _24;  // +0x1C, 4 bytes
            float _31;  // +0x20, 4 bytes
            float _32;  // +0x24, 4 bytes
            float _33;  // +0x28, 4 bytes
            float _34;  // +0x2C, 4 bytes
            float _41;  // +0x30, 4 bytes
            float _42;  // +0x34, 4 bytes
            float _43;  // +0x38, 4 bytes
            float _44;  // +0x3C, 4 bytes
        };
        float m[4][4];  // +0x0, 64 bytes
    };
    // FourByFourMatrix
    // operator()
    // FourByFourMatrix& __cdecl FourByFourMatrix::*(const FourByFourMatrix&)
    // FourByFourMatrix& __cdecl FourByFourMatrix::*(const FourByFourMatrix&)
    // FourByFourMatrix __cdecl FourByFourMatrix::*(const FourByFourMatrix&)
};
class SwizzledMatrix : public FourByFourMatrix
{
  public:
    // base FourByFourMatrix at +0x0, size 64
    // SwizzledMatrix
    // SwizzledMatrix __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // SwizzledMatrix& __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // SwizzledMatrix& __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // SetUnswizzled
    // void __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
};
#endif
