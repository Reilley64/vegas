// fallout_shared/tesloadscreentype_decls.h: declares LoadScreenTypeData, BGSImpactData, TESLoadScreenType
#ifndef TESLOADSCREENTYPE_DECLS_H
#define TESLOADSCREENTYPE_DECLS_H

#include <malloc.h>
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "TESForm.h"
class LoadScreenTypeData
{
  public:
    unsigned char bytes[88];
};
class BGSImpactData
{
  public:
    char _pdbpad_1[47];
    char Data_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};
class TESLoadScreenType : public TESForm
{
  public:
    LoadScreenTypeData data;
    bool Load(TESFile* file);
};
#pragma intrinsic(_alloca)
#endif
