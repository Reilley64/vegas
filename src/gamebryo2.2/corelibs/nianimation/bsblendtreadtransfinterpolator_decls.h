// gamebryo2.2/corelibs/nianimation/bsblendtreadtransfinterpolator_decls.h: declares NiBlendInterpolator, BSBlendTreadTransfInterpolator
#ifndef BSBLENDTREADTRANSFINTERPOLATOR_DECLS_H
#define BSBLENDTREADTRANSFINTERPOLATOR_DECLS_H

#include "fnv/decl/FUN_00a37260_shell.h"
struct NiObjectNET;
class NiQuatTransform;
class NiBlendInterpolator
{
  public:
    virtual ~NiBlendInterpolator();
    unsigned int m_uiRefCount;
    float m_fLastTime;
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
};
class BSBlendTreadTransfInterpolator : public NiBlendInterpolator
{
  public:
    virtual bool Update(float, NiObjectNET*, NiQuatTransform&);
    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiQuatTransform&);
};
#endif
