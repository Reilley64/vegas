// fallout_shared/bgsplaceablewater_decls.h: declares TESWaterForm, BGSImpactData, TESFileFormVersion, TESFileGetChunkData
#ifndef FNV_BGSPLACEABLEWATER_DECLS_H
#define FNV_BGSPLACEABLEWATER_DECLS_H


#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_011ca000.h"
#include "TESForm.h"

struct TESWaterForm : public TESForm
{
  private:
    char _pdbpad_18[20];
    bool m_bNeedsUpdate;
    char _pdbpad_2d[3];
    char m_pRenderedTexture[4];
    char m_kTextureScrollLayer0[16];
    char m_kTextureScrollLayer1[16];
    char m_kTextureScrollLayer2[16];
    char m_kNoiseMapTexture[12];
    unsigned char m_ucOpacity;
    unsigned char cFlags;
    char _pdbpad_72[2];
    char m_kMaterialId[8];
    void* m_pWaterSound;
    void* m_pWaterForm;
    char Data[196];
    char m_apWaterForms[12];
    int m_iCurrentTextureSelection1;
    int m_iCurrentTextureSelection2;
    unsigned int m_uiNoiseFrequencyX;
    unsigned int m_uiNoiseFrequencyY;
    int m_iNoiseOctaveCount;
    float m_fNoiseAmplitude;
    float m_fNoiseLacunarity;
    float fSideOffset;
    float m_fDistanceScale;
    void* m_pWaterSpell;
    char m_kNoiseTextureData[4];
    void* m_pPlaceableAutoWater;
    void* m_pPlaceableWater;
    int m_iRadiationMagnitude;
    int m_iHealthMagnitude;
    bool m_bResetNoiseTextures;
    char _pdbpad_191[3];
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
