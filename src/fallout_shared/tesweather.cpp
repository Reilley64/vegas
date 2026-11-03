// fallout_shared/tesweather.cpp: TESWeather, TESWeather__WeatherSoundList, TESWeather__WeatherSound, WeatherSave and more (13 functions)

#include <new>
#include <cstring>
#include "fnv/decl/B8AD00Header.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00581fb0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "tesweather_decls.h"

// @fnv 0x005807f0
TESWeather::TESWeather()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x35))));
    ResetFormData();
}

// @fnv 0x00581b40
void TESWeather::ResetFormData()
{
    m_iCloudLayerCount = 3;
    memset(m_auiWeatherColors, 0, sizeof(m_auiWeatherColors));
    memset(m_aucWeatherFlags, 0, sizeof(m_aucWeatherFlags));
    memset(m_afFogDistances, 0, sizeof(m_afFogDistances));
    m_afFogDistances[4] = 1.0F;
    m_afFogDistances[5] = 1.0F;
    memset(m_aucCloudLayerSpeeds, 0, sizeof(m_aucCloudLayerSpeeds));
    memset(m_auiCloudLayerColors, 0, sizeof(m_auiCloudLayerColors));
}

// @fnv 0x00581b00
void TESWeather::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    TESImageSpaceModifiableCountForm_6_::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x00581be0
void TESWeather::ClearData()
{
    soundList.ClearWeatherSounds();
}

// @fnv 0x00581c00
void TESWeather::MakeDefault()
{
    m_iCloudLayerCount = 3;
    reinterpret_cast<::TESFullName *>(&(m_kCloudLayerTextures[0]))->SetFullName("Sky\\WastelandCloudCloudyUpper01.dds");
    reinterpret_cast<::TESFullName *>(&(m_kCloudLayerTextures[1]))->SetFullName("Sky\\WastelandCloudHorizon01.dds");
    reinterpret_cast<::TESFullName *>(&(m_kCloudLayerTextures[2]))->SetFullName("Sky\\WastelandCloudCloudyLower01.dds");
    m_aucCloudLayerSpeeds[0] = 0x33;
    m_auiCloudLayerColors[0][0] = 0x5B4B46;
    m_auiCloudLayerColors[0][1] = 0x9B9B9B;
    m_auiCloudLayerColors[0][2] = 0x6C5953;
    m_auiCloudLayerColors[0][3] = 0x1C140F;
    m_aucWeatherFlags[0] = 0x33;
    m_aucWeatherFlags[3] = 0xFF;
    m_aucWeatherFlags[4] = 0xFF;
    m_aucWeatherFlags[5] = 0xFF;
    m_aucWeatherFlags[6] = 0x00;
    m_aucWeatherFlags[7] = 0xFF;
    m_aucWeatherFlags[8] = 0x00;
    m_aucWeatherFlags[9] = 0xFF;
    m_aucWeatherFlags[10] = 0x32;
    m_aucWeatherFlags[11] = 0x00;
    m_afFogDistances[2] = 27852.8F;
    m_afFogDistances[0] = 27852.8F;
    m_afFogDistances[3] = 163840.0F;
    m_afFogDistances[1] = 163840.0F;
    m_afFogDistances[5] = 1.0F;
    m_afFogDistances[4] = 1.0F;
    m_auiWeatherColors[7][0] = 0x846C66;
    m_auiWeatherColors[0][0] = 0x846C66;
    m_auiWeatherColors[7][1] = 0x71533E;
    m_auiWeatherColors[0][1] = 0x71533E;
    m_auiWeatherColors[7][4] = 0x71533E;
    m_auiWeatherColors[0][4] = 0x71533E;
    m_auiWeatherColors[7][2] = 0x846D66;
    m_auiWeatherColors[0][2] = 0x846D66;
    m_auiWeatherColors[7][3] = 0x100A05;
    m_auiWeatherColors[0][3] = 0x100A05;
    m_auiWeatherColors[7][5] = 0x100A05;
    m_auiWeatherColors[0][5] = 0x100A05;
    m_auiWeatherColors[8][0] = 0x5F6DB6;
    m_auiWeatherColors[1][0] = 0x5F6DB6;
    m_auiWeatherColors[8][1] = 0xD19A83;
    m_auiWeatherColors[1][1] = 0xD19A83;
    m_auiWeatherColors[8][4] = 0xD19A83;
    m_auiWeatherColors[1][4] = 0xD19A83;
    m_auiWeatherColors[8][2] = 0x5782A8;
    m_auiWeatherColors[1][2] = 0x5782A8;
    m_auiWeatherColors[8][3] = 0x261B0F;
    m_auiWeatherColors[1][3] = 0x261B0F;
    m_auiWeatherColors[8][5] = 0x261B0F;
    m_auiWeatherColors[1][5] = 0x261B0F;
    m_auiWeatherColors[3][0] = 0x252212;
    m_auiWeatherColors[3][1] = 0x857065;
    m_auiWeatherColors[3][4] = 0x857065;
    m_auiWeatherColors[3][2] = 0x35221A;
    m_auiWeatherColors[3][3] = 0x281C15;
    m_auiWeatherColors[3][5] = 0x281C15;
    m_auiWeatherColors[4][0] = 0x79A5FF;
    m_auiWeatherColors[4][1] = 0xCAEDFF;
    m_auiWeatherColors[4][4] = 0xCAEDFF;
    m_auiWeatherColors[4][2] = 0x499AE2;
    m_auiWeatherColors[4][3] = 0x764D34;
    m_auiWeatherColors[4][5] = 0x764D34;
    m_auiWeatherColors[5][0] = 0x779FF2;
    m_auiWeatherColors[5][1] = 0xBED9DE;
    m_auiWeatherColors[5][4] = 0xBED9DE;
    m_auiWeatherColors[5][2] = 0x9DBDFF;
    m_auiWeatherColors[5][3] = 0x000000;
    m_auiWeatherColors[5][5] = 0x000000;
}

// Deletes each TESWeather__WeatherSound in the list, then clears the list with RemoveAll.
// @fnv 0x00581f50
void TESWeather__WeatherSoundList::ClearWeatherSounds()
{
    BSSimpleList<TESWeather__WeatherSound*>* iter = this;
    while (iter && ((::TESWeather__WeatherSound *)(new ((void *)(iter)) ::Vec3())))
    {
        TESWeather__WeatherSound* sound = ((::TESWeather__WeatherSound *)(new ((void *)(iter)) ::Vec3()));
        ::FUN_00401030(sound);
        iter = ((::BSSimpleList< ::TESWeather__WeatherSound *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>(this)->RemoveAll();
}
// @fnv 0x00580990
bool TESWeather::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x35)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    unsigned int uiChunkID;
    while (uiChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (uiChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x44414900: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::FUN_00581fb0_Class *>(this)->FUN_00581fb0(0, formID);
            break;
        }
        case 0x44414901:
        case 0x4d414e4d:  // MNAM
        {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::FUN_00581fb0_Class *>(this)->FUN_00581fb0(1, formID);
            break;
        }
        case 0x44414902: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::FUN_00581fb0_Class *>(this)->FUN_00581fb0(2, formID);
            break;
        }
        case 0x44414903: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::FUN_00581fb0_Class *>(this)->FUN_00581fb0(3, formID);
            break;
        }
        case 0x44414904: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::FUN_00581fb0_Class *>(this)->FUN_00581fb0(4, formID);
            break;
        }
        case 0x44414905: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::FUN_00581fb0_Class *>(this)->FUN_00581fb0(5, formID);
            break;
        }
        case 0x44414906: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::FUN_00581fb0_Class *>(this)->FUN_00581fb0(6, formID);
            break;
        }
        case 0x4d414e43:  // CNAM
            ::TESTexture::ReadTextureData(&m_kCloudLayerTextures[1], file);
            break;
        case 0x4d414e44:  // DNAM
            ::TESTexture::ReadTextureData(&m_kCloudLayerTextures[0], file);
            break;
        case 0x4d414e41:  // ANAM
            ::TESTexture::ReadTextureData(&m_kCloudLayerTextures[2], file);
            break;
        case 0x4d414e42:  // BNAM
            ::TESTexture::ReadTextureData(&m_kCloudLayerTextures[3], file);
            break;
        case 0x4d414e45:  // ENAM (legacy fifth texture)
            ::TESTexture::ReadTextureData(&m_kCloudLayerTextures[4], file);
            break;
            // Retained empty legacy branches present in the original loader.
            break;
            break;
            break;
        case 0x4d414e4f:  // ONAM
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_aucCloudLayerSpeeds), sizeof(m_aucCloudLayerSpeeds));
            break;
        case 0x4d414e50:  // PNAM
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == sizeof(m_auiCloudLayerColors))
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_auiCloudLayerColors), sizeof(m_auiCloudLayerColors));
            else if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 64)
            {
                unsigned int oldCloudColors[4][4];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(oldCloudColors), sizeof(oldCloudColors));
                for (int layer = 0; layer < 4; ++layer)
                    for (int time = 0; time < 4; ++time)
                        m_auiCloudLayerColors[layer][time] = oldCloudColors[layer][time];
            }
            if (file->IsEndianConversionRequired())
                for (int layer = 0; layer < 4; ++layer)
                    for (int time = 0; time < 6; ++time)
                        ::FUN_00401080((int *)(unsigned int *)(&m_auiCloudLayerColors[layer][time]));
            break;
        case 0x4c444f4d:  // MODL
            TESModel::LoadModelData(&m_kWeatherModel, file);
            break;
        case 0x304d414e:  // NAM0
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == sizeof(m_auiWeatherColors))
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_auiWeatherColors), sizeof(m_auiWeatherColors));
            else if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 160)
            {
                unsigned int oldColors[10][4];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(oldColors), sizeof(oldColors));
                for (int color = 0; color < 10; ++color)
                    for (int time = 0; time < 4; ++time)
                        m_auiWeatherColors[color][time] = oldColors[color][time];
            }
            if (file->IsEndianConversionRequired())
                for (int color = 0; color < 10; ++color)
                    for (int time = 0; time < 6; ++time)
                        ::FUN_00401080((int *)(unsigned int *)(&m_auiWeatherColors[color][time]));
            break;
        case 0x41544144:  // DATA
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == sizeof(m_aucWeatherFlags))
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_aucWeatherFlags), sizeof(m_aucWeatherFlags));
            else if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 12)
            {
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_aucWeatherFlags), 12);
                memset(&m_aucWeatherFlags[12], 255, 3);
            }
            break;
        case 0x4d414e46:  // FNAM
        {
            int count = 6;
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() != sizeof(m_afFogDistances))
                count -= 2;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_afFogDistances), sizeof(m_afFogDistances));
            if (file->IsEndianConversionRequired())
                for (int i = 0; i < count; ++i)
                    ::FUN_00401080((int *)(float *)(&m_afFogDistances[i]));
            break;
        }
        case 0x4d414e48:  // HNAM
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_afHdrParameters), sizeof(m_afHdrParameters));
            if (file->IsEndianConversionRequired())
                for (int i = 0; i < 14; ++i)
                    ::FUN_00401080((int *)(float *)(&m_afHdrParameters[i]));
            break;
        case 0x4d414e49:  // INAM
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_akImageSpaceModifierParameters), sizeof(m_akImageSpaceModifierParameters));
            if (file->IsEndianConversionRequired())
                for (int i = 0; i < 2; ++i)
                    reinterpret_cast<::B8AD00Header *>(&(m_akImageSpaceModifierParameters[i]))->SwapEndian();
            break;
        case 0x4d414e4c:  // LNAM
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_iCloudLayerCount), sizeof(m_iCloudLayerCount));
            if (file->IsEndianConversionRequired())
                ::FUN_00401080(&m_iCloudLayerCount);
            break;
        case 0x4d414e53:  // SNAM
        {
            TESWeather__WeatherSound* sound = new TESWeather__WeatherSound;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(sound), sizeof(TESWeather__WeatherSound));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::S_00462230 *>((sound))->FUN_00462230();
            ::ResolveFormID((unsigned int *)&(sound->formID), file);
            reinterpret_cast<::Callees *>(&(soundList))->FUN_00905820((void *)&(sound));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005813b0
TESWeather__WeatherSound::TESWeather__WeatherSound()
{
    memset(this, 0, sizeof(*this));
}

struct FUN_005808b0_shell
{
    void FUN_005808e0();
    void* DestroyIfFlagged(unsigned int);
};
class W5808E0FormBase : public TESForm
{
  public:
    virtual ~W5808E0FormBase();
};

class FUN_005808e0 : public W5808E0FormBase, public TESImageSpaceModifiableCountForm_6_
{
  public:
    TESTexture1024 m_kCloudLayerTextures[4];
    unsigned char m_aucCloudLayerSpeeds[4];
    unsigned int m_auiCloudLayerColors[4][6];
    TESModel m_kWeatherModel;
    unsigned char m_aucWeatherFlags[15];
    unsigned char ucUnusedEF;
    float m_afFogDistances[6];
    unsigned int m_auiWeatherColors[10][6];
    TESWeather__WeatherSoundList soundList;
    float m_afHdrParameters[14];
    ImageSpaceModifierParameterData m_akImageSpaceModifierParameters[2];
    int m_iCloudLayerCount;

    virtual ~FUN_005808e0();
    virtual void ClearData();
};
// Calls FUN_005808e0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x005808b0
void* FUN_005808b0_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_005808e0 *>(this)->FUN_005808e0::~FUN_005808e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x005808e0
FUN_005808e0::~FUN_005808e0()
{
    ClearData();
}

struct FUN_004855a0_shell
{
};
struct FUN_00485680_shell
{
};
class FUN_00582040_Class : public TESImageSpaceModifiableCountForm_6_
{
  public:
    void ReleaseSoundSlots();
};
struct FUN_0048e370_holder
{
};
struct FUN_004891d0_holder
{
};
class WeatherSave : public TESForm, public FUN_00582040_Class
{
  public:
    TESTexture1024 m_kCloudLayerTextures[4];
    unsigned char m_aucCloudLayerSpeeds[4];
    unsigned int m_auiCloudLayerColors[4][6];
    TESModel m_kWeatherModel;
    unsigned char m_aucWeatherFlags[15];
    unsigned char ucUnusedEF;
    float m_afFogDistances[6];
    unsigned int m_auiWeatherColors[10][6];
    TESWeather__WeatherSoundList soundList;
    float m_afHdrParameters[14];
    ImageSpaceModifierParameterData m_akImageSpaceModifierParameters[2];
    int m_iCloudLayerCount;
    void FUN_005813d0();
};
// @fnv 0x005813d0
void WeatherSave::FUN_005813d0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0_shell*>(this)))->FUN_004855a0();
    FUN_00582040_Class::ReleaseSoundSlots();
    unsigned int auiChunkIds[8] = {0x4d414e44, 0x4d414e43, 0x4d414e41, 0x4d414e42,
                                   0x4d414e45, 0x4d414e47, 0x4d414e4a, 0x4d414e4b};
    for (int i = 0; i < m_iCloudLayerCount; ++i)
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_holder*>(&m_kCloudLayerTextures[i])))->FUN_0048e370(auiChunkIds[i]);
    reinterpret_cast<::FUN_004891d0_cls *>((reinterpret_cast<FUN_004891d0_holder*>(&m_kWeatherModel)))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    FUN_00485910(0x4d414e4c, m_iCloudLayerCount);
    ::FUN_004856f0((void *)(0x4d414e4f), m_aucCloudLayerSpeeds, (void *)(4));
    ::FUN_00485710((void *)(0x4d414e50), &m_auiCloudLayerColors[0][0], (void *)(24));
    ::FUN_00485710((void *)(0x304d414e), &m_auiWeatherColors[0][0], (void *)(60));
    ::FUN_00485710((void *)(0x4d414e46), reinterpret_cast<unsigned int*>(m_afFogDistances), (void *)(6));
    if (((bool)(::FUN_00401500())))
    {
        for (unsigned int j = 0; j < 2; ++j)
            reinterpret_cast<::B8AD00Header *>(&(m_akImageSpaceModifierParameters[j]))->SwapEndian();
    }
    ::AppendChunk(0x4d414e49, m_akImageSpaceModifierParameters, 304);
    if (((bool)(::FUN_00401500())))
    {
        for (unsigned int k = 0; k < 2; ++k)
            reinterpret_cast<::B8AD00Header *>(&(m_akImageSpaceModifierParameters[k]))->SwapEndian();
    }
    ::FUN_004856f0((void *)(0x41544144), m_aucWeatherFlags, (void *)(15));
    for (BSSimpleList<TESWeather__WeatherSound*>* node = &soundList; node && ((::TESWeather__WeatherSound *)(new ((void *)(node)) ::Vec3())); node = ((::BSSimpleList< ::TESWeather__WeatherSound *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>((((::TESWeather__WeatherSound *)(new ((void *)(node)) ::Vec3()))))->FUN_00462230();
        ::AppendChunk(0x4d414e53, ((::TESWeather__WeatherSound *)(new ((void *)(node)) ::Vec3())), 8);
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>((((::TESWeather__WeatherSound *)(new ((void *)(node)) ::Vec3()))))->FUN_00462230();
    }
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680_shell*>(this)))->FUN_00485680();
}

class TESRegionData;

template <> class BSSimpleList<TESRegionData*>
{
  public:
    TESRegionData* m_item;
    BSSimpleList<TESRegionData*>* m_pkNext;
    unsigned int ItemsInList();
};

class FUN_005e79a0_t
{
  public:
};

class WeatherEq : public TESWeather
{
  public:
    bool IsDifferentFrom(TESForm* pOther);
};

// @fnv 0x00581880
bool WeatherEq::IsDifferentFrom(TESForm* pOther)
{
    TESWeather* other = dynamic_cast<TESWeather*>(pOther);
    if (!other)
        return 1;
    BSSimpleList<TESRegionData*>* otherList3 = (BSSimpleList<TESRegionData*>*)&other->soundList;
    BSSimpleList<TESRegionData*>* thisList2 = (BSSimpleList<TESRegionData*>*)&this->soundList;
    if (otherList3->ItemsInList() == thisList2->ItemsInList())
    {
        while (otherList3 != 0 && thisList2 != 0 && ((::TESRegionData *)(new ((void *)(otherList3)) ::Vec3())) != 0 && ((::TESRegionData *)(new ((void *)(thisList2)) ::Vec3())) != 0)
        {
            if (memcmp(((::TESRegionData *)(new ((void *)(otherList3)) ::Vec3())), ((::TESRegionData *)(new ((void *)(thisList2)) ::Vec3())), 8) != 0)
                return 1;
            otherList3 = ((::BSSimpleList< ::TESRegionData *> *)(reinterpret_cast<::Callees *>((otherList3))->FUN_00726070()));
            thisList2 = ((::BSSimpleList< ::TESRegionData *> *)(reinterpret_cast<::Callees *>((thisList2))->FUN_00726070()));
        }
    }
    else
    {
        return 1;
    }
    if (this->m_iCloudLayerCount == other->m_iCloudLayerCount)
    {
        for (int i3 = 0; i3 < this->m_iCloudLayerCount; ++i3)
        {
            if (m_kCloudLayerTextures[i3].CompareWithBase(&other->m_kCloudLayerTextures[i3]))
                return 1;
        }
    }
    else
    {
        return 1;
    }
    return reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(other) || m_kWeatherModel.CompareWithBase(&other->m_kWeatherModel) ||
           memcmp(this->m_aucWeatherFlags, other->m_aucWeatherFlags, 15) != 0 ||
           memcmp(this->m_auiWeatherColors, other->m_auiWeatherColors, 240) != 0 ||
           memcmp(this->m_afFogDistances, other->m_afFogDistances, 24) != 0 ||
           memcmp(this->m_aucCloudLayerSpeeds, other->m_aucCloudLayerSpeeds, 4) != 0 ||
           memcmp(this->m_auiCloudLayerColors, other->m_auiCloudLayerColors, 96) != 0 ||
           memcmp(this->m_akImageSpaceModifierParameters, other->m_akImageSpaceModifierParameters, 304) != 0;
}

#include <string.h>
struct FUN_004b0680
{
    unsigned int formID;
    unsigned int type;
    FUN_004b0680(unsigned int formID, unsigned int type);
};

class WeatherCopy : public TESWeather
{
  public:
    void FUN_00581630(TESForm* source);
};

// Copies weather data from a source TESWeather into this WeatherCopy, including cloud layers, model, flags, colors, fog, image space modifiers, and sound list.
// @fnv 0x00581630
void WeatherCopy::FUN_00581630(TESForm* source)
{
    TESWeather* weather = dynamic_cast<TESWeather*>(source);
    if (!weather)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(weather);
    m_iCloudLayerCount = weather->m_iCloudLayerCount;
    for (int i = 0; i < m_iCloudLayerCount; ++i)
        m_kCloudLayerTextures[i].CopyFromBase(&weather->m_kCloudLayerTextures[i]);
    m_kWeatherModel.CopyFromBase(&weather->m_kWeatherModel);
    memcpy(m_aucCloudLayerSpeeds, weather->m_aucCloudLayerSpeeds, 4);
    memcpy(m_auiCloudLayerColors, weather->m_auiCloudLayerColors, 96);
    memcpy(m_aucWeatherFlags, weather->m_aucWeatherFlags, 15);
    memcpy(m_auiWeatherColors, weather->m_auiWeatherColors, 240);
    memcpy(m_afFogDistances, weather->m_afFogDistances, 24);
    memcpy(m_akImageSpaceModifierParameters, weather->m_akImageSpaceModifierParameters, 304);
    reinterpret_cast<::FileMatchList *>(&(soundList))->RemoveAll();
    for (BSSimpleList<TESWeather__WeatherSound*>* node = &weather->soundList; node && ((::TESWeather__WeatherSound *)(new ((void *)(node)) ::Vec3()));
         node = ((::BSSimpleList< ::TESWeather__WeatherSound *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        TESWeather__WeatherSound* sound = reinterpret_cast<TESWeather__WeatherSound*>(
            new FUN_004b0680(((::TESWeather__WeatherSound *)(new ((void *)(node)) ::Vec3()))->formID, ((::TESWeather__WeatherSound *)(new ((void *)(node)) ::Vec3()))->type));
        reinterpret_cast<::Callees *>(&(soundList))->FUN_00905820((void *)&(sound));
    }
}
