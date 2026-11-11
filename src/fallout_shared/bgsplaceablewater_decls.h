// fallout_shared/bgsplaceablewater_decls.h: declares TESWaterForm, BGSImpactData, TESFileFormVersion, TESFileGetChunkData
#ifndef FNV_BGSPLACEABLEWATER_DECLS_H
#define FNV_BGSPLACEABLEWATER_DECLS_H


#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_011ca000.h"
#include "TESForm.h"

// This unit names the water form and casts to it. It reads no member; the
// complete type is the owner's, in teswaterform_types_TESWaterForm.h.
struct TESWaterForm : public TESForm
{
};

class BGSImpactData
{
  public:
    char _pdbpad_1[47];
    char Data_db_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};

class TESFileFormVersion
{
  public:
};

class TESFileGetChunkData : public TESFile
{
  public:
};


#endif
