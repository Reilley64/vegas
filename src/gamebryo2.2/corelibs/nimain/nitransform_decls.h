// gamebryo2.2/corelibs/nimain/nitransform_decls.h: declares NiPoint3, NiColor, NiBinaryStream, NiStream, NiTransform
#ifndef NITRANSFORM_DECLS_H
#define NITRANSFORM_DECLS_H
#include "fnv/decl/S_00a59a30_Matrix3.h"
class NiStream;
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
class NiStream;
class NiColor
{
  public:
    float r, g, b;
    void LoadBinary(NiStream&);
public:
    void SaveBinary(::NiStream &);
};
class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    void ResetToIdentity()
    {
        m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
    }
public:
    bool operator==(const ::ThreeByThreeMatrix &) const;
};
struct NiBinaryStream
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* write)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data)
    {
        unsigned int size = 4;
        position += read(this, data, 4, &size, 1);
    }
};
class NiStream
{
  public:
    char pad[0x24c];
    NiBinaryStream* input;
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    void ResetToIdentity();
    void LoadBinary(NiStream&);
};
#endif