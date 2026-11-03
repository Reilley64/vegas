// Unit-local PC header for fallout_shared/tesweather.cpp.
// TESTexture1024, TESModel, FileEntryList, ImageSpaceModifierParameterData,
// constructor/method declarations added so this TU can bind the real
// call targets. PC TESWeather ends at +0x36C: the constructor builds no
#ifndef FNV_TESWEATHER_UNIT_H
#define FNV_TESWEATHER_UNIT_H

#include <cstring>
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESTexture.h"

class BSFileEntry;
class TESImageSpaceModifier;
class TESModel;
class TESWeather;
class TESWeather__WeatherSound;
class TESWeather__WeatherSoundList;

void __cdecl operator delete(void* ptr);

class TESImageSpaceModifiableCountForm_6_ : public BaseFormComponent
{
  public:
    TESImageSpaceModifier* m_pImageSpaceModifier[6];  // +0x4, 24 bytes
    TESImageSpaceModifiableCountForm_6_();
    void InitItem(TESForm* form);
};

class TESTexture1024 : public TESTexture
{
  public:
    TESTexture1024();
    ~TESTexture1024();
    void SetTexture(const char* texturePath);
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
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    TESModel();
};

class ImageSpaceModifierParameterData
{
  public:
    float m_afFirstParameterSet[15];        // +0x0, 60 bytes
    float m_afSecondParameterSet[3];        // +0x3C, 12 bytes
    float m_afThirdParameterSet[3];         // +0x48, 12 bytes
    float m_afFourthParameterSet[4];        // +0x54, 16 bytes
    float m_afColorAndAlphaParameters[12];  // +0x64, 48 bytes
    unsigned int ShaderConstantData;        // +0x94, 4 bytes
};

// Scaffold exposing TESForm::IsFormInitialized, which the task closure
// TESForm.h does not declare (cf. TESFormInitFlag in bgsimpactdata.h).
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
};

class TESWeather__WeatherSoundList : public BSSimpleList<TESWeather__WeatherSound*>
{
  public:
    TESWeather__WeatherSoundList();
    void ClearWeatherSounds();
};

class TESWeather : public TESForm, public TESImageSpaceModifiableCountForm_6_
{
  public:
    TESTexture1024 m_kCloudLayerTextures[4];   // +0x34, 48 bytes
    unsigned char m_aucCloudLayerSpeeds[4];    // +0x64, 4 bytes
    unsigned int m_auiCloudLayerColors[4][6];  // +0x68, 96 bytes
    TESModel m_kWeatherModel;                  // +0xC8, 24 bytes
    unsigned char m_aucWeatherFlags[15];       // +0xE0, 15 bytes
    unsigned char layoutPaddingEF[1];
    float m_afFogDistances[6];                                            // +0xF0, 24 bytes
    unsigned int m_auiWeatherColors[10][6];                               // +0x108, 240 bytes
    TESWeather__WeatherSoundList soundList;                               // +0x1F8, 8 bytes
    float m_afHdrParameters[14];                                          // +0x200, 56 bytes
    ImageSpaceModifierParameterData m_akImageSpaceModifierParameters[2];  // +0x238, 304 bytes
    int m_iCloudLayerCount;                                               // +0x368, 4 bytes
    TESWeather();
    void ResetFormData();
    void InitItem();
    void ClearData();
    void MakeDefault();
};
#endif
