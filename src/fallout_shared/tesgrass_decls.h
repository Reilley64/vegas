// fallout_shared/tesgrass_decls.h: declares TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject, FileEntryList and more
#ifndef FNV_TESGRASS_DECLS_H
#define FNV_TESGRASS_DECLS_H

#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "layout_support.h"
class BSFileEntry;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESGrass__GRASS_DATA;
class TESModel;
class TESFormList;
class FileEntryList;
enum TESGrass__GRASS_WATER_STATE
{
    TESGrass__GRASS_WATER_STATE_GWS_ABOVE_ONLY_ATLEAST = 0,
    TESGrass__GRASS_WATER_STATE_GWS_ABOVE_ONLY_ATMOST = 1,
    TESGrass__GRASS_WATER_STATE_GWS_BELOW_ONLY_ATLEAST = 2,
    TESGrass__GRASS_WATER_STATE_GWS_BELOW_ONLY_ATMOST = 3,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATLEAST = 4,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATMOST = 5,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATMOST_ABOVE = 6,
    TESGrass__GRASS_WATER_STATE_GWS_BOTH_ATMOST_BELOW = 7,
    TESGrass__GRASS_WATER_STATE_GWS_COUNT = 8
};
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
class TESModel : public BaseFormComponent
{
  public:
    static void LoadModelData(TESModel* model, TESFile* file);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
class TESGrass__GRASS_DATA
{
  public:
    void ResetGrassData();
    unsigned char m_ucDensity;   // +0x0, 1 bytes
    unsigned char m_ucMinSlope;  // +0x1, 1 bytes
    unsigned char m_ucMaxSlope;  // +0x2, 1 bytes
    unsigned char layoutPadding3[1];
    unsigned short m_usUnitsFromSurface;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    TESGrass__GRASS_WATER_STATE m_eWaterState;  // +0x8, 4 bytes
    float m_fPositionRange;                     // +0xC, 4 bytes
    float m_fHeightRange;                       // +0x10, 4 bytes
    float m_fWavePeriod;                        // +0x14, 4 bytes
    float m_fWavePhase;                         // +0x18, 4 bytes
    char cFlags;                                // +0x1C, 1 bytes
    unsigned char layoutPadding1D[3];
};
class TESGrass : public TESBoundObject, public TESModel
{
  public:
    void InitItem();
    void ResetFormData();
    bool Load(TESFile* file);
    unsigned char GetMinimumSlopeDegrees();
    float GetLowestAllowedSlope();
    TESGrass__GRASS_DATA Data;  // +0x48, 32 bytes
};
// The shared chunk reader is bound under this canonical alias.
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
extern "C" void* __cdecl memset(void* data, int value, unsigned int size);
#endif
