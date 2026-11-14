// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITEXTURETRANSFORM_H
#define FNV_NITEXTURETRANSFORM_H

#include "layout_support.h"
struct ThreeByThreeMatrix;
struct NiPoint2;
class NiPoint4;
class TextureMapTransform;
class FourComponentNumericValue;
enum NiTextureTransform__TransformMethod
{
    NiTextureTransform__TransformMethod_MAYA_DEPRECATED_TRANSFORM = 0,
    NiTextureTransform__TransformMethod_MAX_TRANSFORM = 1,
    NiTextureTransform__TransformMethod_MAYA_TRANSFORM = 2
};
struct NiPoint2
{
  public:
    float x;  // +0x0, 4 bytes
    float y;  // +0x4, 4 bytes
    // NiPoint2
    // operator[]
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&)
    // operator-
    // operator*
    // NiPoint2 __cdecl NiPoint2::*(float)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&, const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*(const NiPoint2&)
    // float __cdecl NiPoint2::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiPoint2::*(const char*)
};
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
class NiPoint4
{
  public:
    union
    {                                             // overlapping CodeView storage
        FourComponentNumericValue m_kComponents;  // +0x0, 16 bytes
        float m_afExtents[4];                     // +0x0, 16 bytes
    };
    // NiPoint4
    // bool __cdecl NiPoint4::*(const NiPoint4&)
    // void __cdecl NiPoint4::*()
    // Set
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // NiPoint4 __cdecl NiPoint4::*(NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(NiPoint4*, unsigned int, NiPoint3*)
};
struct ThreeByThreeMatrix
{
  public:
    NiPoint4 m_afEntries[3];  // +0x0, 48 bytes
    // GetRow
    // SetRow
    // GetCol
    // SetCol
    // operator*
    // Inverse
};
class TextureMapTransform
{
  public:
    NiPoint2 m_kTranslate;     // +0x0, 8 bytes
    float m_fRotation;         // +0x8, 4 bytes
    NiPoint2 m_kScaleFactors;  // +0xC, 8 bytes
    NiPoint2 m_kCenter;        // +0x14, 8 bytes
    bool m_bTransform;         // +0x1C, 1 bytes
    unsigned char layoutPadding1D[3];
    ThreeByThreeMatrix m_kTransformMatrix;                            // +0x20, 48 bytes
    NiTextureTransform__TransformMethod m_eTransformMethod;  // +0x50, 4 bytes
    unsigned char layoutPadding54[12];
    TextureMapTransform(const NiPoint2& translate, const NiPoint2& rotate, const NiPoint2& scale, const NiPoint2& center,
                       NiTextureTransform__TransformMethod method) throw();
    void UpdateFromPair(const NiPoint2& value);
    void SetValue(float value);
    void FUN_00a462b0(const NiPoint2& value);
};
#endif
