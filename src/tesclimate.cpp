// tesclimate.cpp: TESClimate, ClimateCopy (12 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005825a0_shell.h"
#include "fnv/decl/FUN_00582690_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_005b5000.h"
#include "tesclimate_types.h"
#include <string.h>
#include <new>

// @fnv 0x0052aaa0
TESClimate::TESClimate()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x36))));
    ResetFormData();
}

#include <malloc.h>
// @fnv 0x0052ac90
bool TESClimate::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x36)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x54534c57: {
            int warnings = ::FUN_0046e8a0();
            ::FUN_0043b2b0(true);
            TESWeatherList::LoadWeatherEntries(&weatherList, file, this);
            ::FUN_0043b2b0(false);
            if (::FUN_0046e8a0() > warnings)
                ::FUN_005b5e40();
        }
        break;
        case 0x4d414e46:
        case 0x4d414e47:
        case 0x4d414e48:
        case 0x4d414e49:
        case 0x4d414e4a:
        case 0x4d414e4b:
        case 0x4d414e4c:
        case 0x4d414e4d:
        case 0x4d414e4e:
        case 0x4d414e4f:
        case 0x4d414e50:
            if (chunk - 0x4d414e46 < 2)
                TESTexture::ReadTextureData(&m_kSunTextures[chunk - 0x4d414e46], file);
            break;
        case 0x4c444f4d:
            TESModel::LoadModelData(&m_kStarsModel, file);
            break;
        case 0x4d414e54:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_ucTimeSettings), 6);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_0052b260_shell : public TESClimate
{
    void FUN_0052b260(bool);
};

// Sets or clears bit 0x80 of the byte at offset 0x55 on this TESClimate based on abUses.
// @fnv 0x0052b260
void FUN_0052b260_shell::FUN_0052b260(bool abUses)
{
    abUses ? *(unsigned char*)((char*)this + 0x55) |= 0x80 : *(unsigned char*)((char*)this + 0x55) &= ~0x80;
}

struct FUN_0052b2c0_shell : public TESClimate
{
    void FUN_0052b2c0(bool);
};

// Sets or clears bit 0x40 in the byte at offset 0x55 of this TESClimate based on abUses.
// @fnv 0x0052b2c0
void FUN_0052b2c0_shell::FUN_0052b2c0(bool abUses)
{
    abUses ? *(unsigned char*)((char*)this + 0x55) |= 0x40 : *(unsigned char*)((char*)this + 0x55) &= ~0x40;
}

struct FUN_0052ab50_shell
{
    void FUN_0052ab80();
    void* FUN_0052ab50(unsigned int flags);
};
struct FUN_0052ac50_shell : public TESClimate
{
    void FUN_0052ac50(unsigned int);
};
// @fnv 0x0052ac20
void TESClimate::ResetFormData()
{
    memset(m_ucTimeSettings, 0, sizeof(m_ucTimeSettings));
    reinterpret_cast<::FUN_0052ac50_shell *>(this)->FUN_0052ac50(3);
}
// @fnv 0x0052b0f0
void TESClimate::MakeDefault()
{
    reinterpret_cast<::TESFullName *>(&(m_kSunTextures[0]))->SetFullName("Sky\\Sun.dds");
    reinterpret_cast<::TESFullName *>(&(m_kSunTextures[1]))->SetFullName("Sky\\SunGlare.dds");
    m_kStarsModel.SetModelFilePath("Sky\\Stars.nif");
    m_ucTimeSettings[0] = 36;
    m_ucTimeSettings[1] = 42;
    m_ucTimeSettings[2] = 108;
    m_ucTimeSettings[3] = 114;
    m_ucTimeSettings[4] = 0;
    reinterpret_cast<::FUN_0052b260_shell *>(this)->FUN_0052b260(true);
    reinterpret_cast<::FUN_0052b2c0_shell *>(this)->FUN_0052b2c0(true);
    reinterpret_cast<::FUN_0052ac50_shell *>(this)->FUN_0052ac50(3);
    reinterpret_cast<::FileMatchList *>(&(weatherList))->RemoveAll();
    WeatherEntry* weather = new WeatherEntry;
    weather->m_pWeatherObject = dynamic_cast<TESWeather*>(::FUN_004839c0(0x15e));
    weather->m_uiWeatherChance = 100;
    if (weather->m_pWeatherObject)
        weatherList.AddHead(weather);
    else
    {
        delete weather;
        ::FUN_005b5e40();
    }
}

// @fnv 0x0052ac50
void FUN_0052ac50_shell::FUN_0052ac50(unsigned int auiDays)
{
    *(unsigned char*)((char*)this + 0x55) =
        (*(unsigned char*)((char*)this + 0x55) & 0xC0) | MinInt(auiDays, 0xFFFFFF3F);
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_0048e370_obj
{
};
struct FUN_004891d0_obj
{
};
void __cdecl WriteWeatherList(unsigned int);
struct FUN_0052ae80_shell
{
    void Init();
};
// @fnv 0x0052ae80
void FUN_0052ae80_shell::Init()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    ((void(*)(void*, unsigned int))WriteWeatherList)((char*)this + 0x30, 0x54534c57);
    int i = 0;
    for (; i < 2; ++i)
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)((char*)this + 0x38 + i * 0xc))))->FUN_0048e370(0x4d414e46 + i);
    reinterpret_cast<::FUN_004891d0_cls *>((((FUN_004891d0_obj*)((char*)this + 0x18))))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    ::FUN_004856f0((void *)(0x4d414e54), (char*)this + 0x50, (void *)(6));
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e79a0_t
{
    bool IsClimateDifferent(TESForm* form);
};

struct FUN_0052afe0_compare_t
{
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    virtual bool FUN_00000008(void* other);
    virtual bool FUN_0000000c(void* other);
};

struct FUN_00582690_weather_t
{
};

// @fnv 0x0052afe0
bool FUN_005e79a0_t::IsClimateDifferent(TESForm* apCompare)
{
    int iIndex;
    TESClimate* i = dynamic_cast<TESClimate*>(apCompare);

    if (!i)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((this))->FUN_00485270(i))
        return true;

    for (iIndex = 0; iIndex < 2; ++iIndex)
    {
        if (((FUN_0052afe0_compare_t*)((unsigned char*)this + 0x38 + iIndex * 0xc))
                ->FUN_0000000c((void*)((unsigned char*)i + 0x38 + iIndex * 0xc)))
            return true;
    }

    if (((FUN_0052afe0_compare_t*)((unsigned char*)this + 0x18))->FUN_0000000c((void*)((unsigned char*)i + 0x18)))
        return true;

    if (reinterpret_cast<::FUN_00582690_shell *>((((FUN_00582690_weather_t*)((unsigned char*)this + 0x30))))->IsDifferentFrom((TESWeatherList*)((unsigned char*)i + 0x30)))
        return true;

    if (memcmp((void*)((unsigned char*)this + 0x50), (void*)((unsigned char*)i + 0x50), 6) != 0)
        return true;

    return false;
}

struct FUN_0052ab80_base
{
    virtual ~FUN_0052ab80_base();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct FUN_0052ab80 : public FUN_0052ab80_base
{
    TESModel m_kStarsModel;
    TESWeatherList weatherList;
    TESTexture m_kSunTextures[2];

    virtual ~FUN_0052ab80();
};
// Calls FUN_0052ab80, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x0052ab50
void* FUN_0052ab50_shell::FUN_0052ab50(unsigned int flags)
{
    reinterpret_cast<::FUN_0052ab80 *>(this)->FUN_0052ab80::~FUN_0052ab80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0052ab80
FUN_0052ab80::~FUN_0052ab80()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

class ClimateCopy : public TESClimate
{
  public:
    void FUN_0052af10(TESForm*);
};

class WeatherListCopy : public TESWeatherList
{
  public:
};

// Copies climate data from a source TESForm into this ClimateCopy, including weather list, sun textures, stars model, and time settings.
// @fnv 0x0052af10
void ClimateCopy::FUN_0052af10(TESForm* source)
{
    TESClimate* climate;
    climate = dynamic_cast<TESClimate*>(source);
    if (!climate)
        return;

    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(climate);
    reinterpret_cast<::FUN_005825a0_shell *>(&(static_cast<WeatherListCopy&>(weatherList)))->CopyWeatherList(&climate->weatherList, false);

    {
        int i;
        for (i = 0; i < 2; ++i)
            m_kSunTextures[i].CopyFromBase(&climate->m_kSunTextures[i]);
    }

    m_kStarsModel.CopyFromBase(&climate->m_kStarsModel);
    memcpy(m_ucTimeSettings, climate->m_ucTimeSettings, 6);
}
