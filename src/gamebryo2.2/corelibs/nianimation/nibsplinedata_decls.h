// gamebryo2.2/corelibs/nianimation/nibsplinedata_decls.h: declares NiBSplineBasis_float_3_, NiBSplineBasisData, NiBinaryStream, NiStream, NiObject and more
#ifndef FNV_NIBSPLINEDATA_DECLS_H
#define FNV_NIBSPLINEDATA_DECLS_H

#include "fnv/decl/CubicSplineBasis.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a62660_cls.h"
#include "fnv/symbols_00aa1000.h"
#include "NiRefObject.h"

class NiBSplineBasis_float_3_
{
  public:
    int count;
    float weights[4];
};
class NiBSplineBasisData
{
  public:
};
struct NiStream;
class NiBinaryStream;

typedef unsigned int(__cdecl* NiBinaryStreamRead)(NiBinaryStream*, void*, unsigned int, const unsigned int&,
                                                  unsigned int);
typedef unsigned int(__cdecl* NiBinaryStreamWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*,
                                                   unsigned int);
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    NiBinaryStreamRead m_pfnRead;
    NiBinaryStreamWrite m_pfnWrite;
};
struct NiStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned char m_opaque004[0x248];
    NiBinaryStream* m_pUnderlyingStream;
};
struct NiObject : public NiRefObject
{
};
class __declspec(novtable) NiBSplineData : public NiObject
{
  public:
    float* m_pfControlPoints;
    short* m_psCompactControlPoints;
    unsigned int m_uiControlPointCount;
    unsigned int m_uiCompactControlPointCount;
    void CalculateSplineValue(float, float*, unsigned int, NiBSplineBasisData*, unsigned int, float, float);
    virtual void LoadBinary(NiStream& stream);
};

void __cdecl FUN_00a89650(const short*, unsigned int, float, float, float*, unsigned int);
#endif
