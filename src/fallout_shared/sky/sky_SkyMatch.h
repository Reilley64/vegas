// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_FALLOUT_SHARED_SKY_SKY_MATCH_H
#define FNV_FALLOUT_SHARED_SKY_SKY_MATCH_H

#include "layout_support.h"
class NiNode;
template <class T> class BSSimpleList;
class Atmosphere;
class BSMultiBoundNode;
class Clouds;
class ImageSpaceModifierInstanceForm;
class Moon;
class NiColor;
class Precipitation;
class Sky;
class SkySound;
class SkyTextureManager;
class Stars;
class Sun;
class TESClimate;
class TESWeather;
enum Sky__SKY_MODE
{
    Sky__SKY_MODE_SM_NONE = 0,
    Sky__SKY_MODE_SM_INTERIOR = 1,
    Sky__SKY_MODE_SM_FAKEEXTERIOR = 2,
    Sky__SKY_MODE_SM_FULL = 3,
    Sky__SKY_MODE_SM_COUNT = 4
};
class NiColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    // void __cdecl NiColor::*(float, float, float)
    // bool __cdecl NiColor::*(const NiColor&)
    // bool __cdecl NiColor::*(const NiColor&)
    // NiColor __cdecl NiColor::*(const NiColor&)
    // operator-
    // operator*
    // operator/
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // NiColor& __cdecl NiColor::*(const NiColor&)
    // operator*=
    // operator/=
    // void __cdecl NiColor::*()
    // void __cdecl NiColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiColor::*(const char*)
    // float __cdecl NiColor::*()
    // void __cdecl NiColor::*()
};
class SkyTextureManager
{
  public:
    // void __cdecl SkyTextureManager::*(NiPointer<NiTexture>*, const char*)
};
class Sky
{
  public:
    void** m_ppVirtualMethodTable;                          // +0x0, 4 bytes
    NiPointer<BSMultiBoundNode> m_pRootNode;  // +0x4, 4 bytes
    NiPointer<NiNode> m_pSkyNode;             // +0x8, 4 bytes
    TESClimate* m_pCurrentClimate;            // +0xC, 4 bytes
    TESWeather* m_pRegionWeather;             // +0x10, 4 bytes
    TESWeather* m_pPreviousWeather;           // +0x14, 4 bytes
    TESWeather* m_pQueuedWeather;             // +0x18, 4 bytes
    TESWeather* m_pOverrideWeather;           // +0x1C, 4 bytes
    Atmosphere* m_pAtmosphere;                // +0x20, 4 bytes
    Stars* m_pStars;                          // +0x24, 4 bytes
    Sun* m_pSun;                              // +0x28, 4 bytes
    Clouds* m_pClouds;                        // +0x2C, 4 bytes
    Moon* m_pPrimaryMoon;                     // +0x30, 4 bytes
    Moon* m_pSecondaryMoon;                   // +0x34, 4 bytes
    Precipitation* m_pPrecipitation;          // +0x38, 4 bytes
    NiColor m_kSkyColors[10];                 // +0x3C, 120 bytes
    NiColor m_kSunlightColor;                 // +0xB4, 12 bytes
    NiColor m_kSkyColor;                      // +0xC0, 12 bytes
    float m_fCurrentWeatherBlend;             // +0xCC, 4 bytes
    float m_fTargetWeatherBlend;              // +0xD0, 4 bytes
    float m_fCloudLayerAlpha[4];              // +0xD4, 16 bytes
    float m_fFogNearDistance;                 // +0xE4, 4 bytes
    float m_fFogPower;                        // +0xE8, 4 bytes
    float m_fFogFarDistance;                  // +0xEC, 4 bytes
    float fWeatherChance;                     // +0xF0, 4 bytes
    float m_fWeatherBlend;                    // +0xF4, 4 bytes
    Sky__SKY_MODE eMode;                      // +0xF8, 4 bytes
    BSSimpleList<SkySound*>* m_pSkySounds;    // +0xFC, 4 bytes
    float m_fWeatherFade;                     // +0x100, 4 bytes
    unsigned int SkySoundData;                // +0x104, 4 bytes
    unsigned int m_uiSkyFourthValue;          // +0x108, 4 bytes
    float SkyTextureState;                    // +0x10C, 4 bytes
    float m_fValueBeforeSkyTextureManager;    // +0x110, 4 bytes
    SkyTextureManager SkyController;          // +0x114, 1 bytes
    unsigned char layoutPadding115[3];
    unsigned int uiFlags;                                                 // +0x118, 4 bytes
    ImageSpaceModifierInstanceForm* m_pFirstImageSpaceModifierInstance;   // +0x11C, 4 bytes
    ImageSpaceModifierInstanceForm* m_pSecondImageSpaceModifierInstance;  // +0x120, 4 bytes
    ImageSpaceModifierInstanceForm* m_pLastWeatherImageSpaceModifier;     // +0x124, 4 bytes
    ImageSpaceModifierInstanceForm* m_pLastWeatherImageSpaceModifier2;    // +0x128, 4 bytes
    float SkyEnvironmentController;                                       // +0x12C, 4 bytes
    float SkyImageSpaceTransitionData;                                    // +0x130, 4 bytes
    float SkyImageSpaceBlendData;                                         // +0x134, 4 bytes
    Sky();
    static Sky* GetInstance();
    bool IsRaining();

  private:
    static Sky* pInstance;

  public:
    // Sky* __cdecl Sky::*()
    // void __cdecl Sky::*()
    // NiNode* __cdecl Sky::*()
    // NiNode* __cdecl Sky::*()
    // Atmosphere* __cdecl Sky::*()
    // Stars* __cdecl Sky::*()
    // Sun* __cdecl Sky::*()
    // Clouds* __cdecl Sky::*()
    // Moon* __cdecl Sky::*()
    // Moon* __cdecl Sky::*()
    // Precipitation* __cdecl Sky::*()
    // float __cdecl Sky::*()
    // Sky::SKY_MODE __cdecl Sky::*()
    // NiFogProperty* __cdecl Sky::*()
    // NiDirectionalLight* __cdecl Sky::*()
    // TESClimate* __cdecl Sky::*()
    // TESWeather* __cdecl Sky::*()
    // TESWeather* __cdecl Sky::*()
    // float __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // const NiColor& __cdecl Sky::*()
    // float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // const float* __cdecl Sky::*()
    // const float __cdecl Sky::*()
    // const float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // float __cdecl Sky::*()
    // SkyTextureManager* __cdecl Sky::*()
    // void __cdecl Sky::*(float)
    // void __cdecl Sky::*(Sky::SKY_MODE)
    // void __cdecl Sky::*()
    // void __cdecl Sky::*(bool)
    // void __cdecl Sky::*(bool)
    // void __cdecl Sky::*(BSMultiBoundNode*, BSFogProperty*)
    // void __cdecl Sky::*(float)
    // void __cdecl Sky::*(float)
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*(float)
    // void __cdecl Sky::*(TESClimate*, bool)
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*(TESWeather*, bool)
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*(const TESWeather*)
    // void __cdecl Sky::*()
    // bool __cdecl Sky::*(unsigned int, const TESWeather*)
    // unsigned short __cdecl Sky::*()
    // SaveGame
    // LoadGame
    // ChangeObjectColor
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*()
    // void __cdecl Sky::*(bool)
    // Sky& __cdecl Sky::*(const Sky&)
    // void __cdecl Sky::*()
};
#endif
