// fallout_shared/bgsradiation_decls.h: declares NiAVObject, BGSDehydrationStage, BSShaderPPLightingProperty, BGSImpactData, BGSCameraPath
#ifndef FNV_BGS_RADIATION_DECLS_H
#define FNV_BGS_RADIATION_DECLS_H

#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00592000.h"
#include "fnv/symbols_011ca000.h"
class TESFile;
class SpellItem;
class BGSRadiationStage;
class NiNode;
class NiAVObject
{
  public:
};
class BGSDehydrationStage
{
  public:
    static BGSDehydrationStage** AllocateStageArray(unsigned int count);
    void FUN_0050f9a0(SpellItem*);
};
class NiTexture;
class BSShaderPPLightingProperty
{
  public:
    NiTexture* GetNormalMapTexture();
};
extern unsigned int DAT_011ca87c;
void InsertRadiationStage(BGSRadiationStage* stage);
extern "C" void* __cdecl __RTDynamicCast(void* source, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
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
class PerkEntryConditionSet;
class BGSCameraPath
{
  public:
    PerkEntryConditionSet* GetConditions();
};
class FUN_005a71d0
{
  public:
};
#endif
