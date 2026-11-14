// fallout_shared/teswaterform.cpp: TESWaterForm, BGSPlaceableWater, WaterShaderSettings, Holder and more (27 functions)

#include <new>
#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0047ff50_class.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fc360_shell.h"
#include "fnv/decl/FUN_004fc380_shell.h"
#include "fnv/decl/FUN_004fc3a0_shell.h"
#include "fnv/decl/FUN_004fc3c0_shell.h"
#include "fnv/decl/FUN_004fc3e0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004fc450__FUN_004fc450_shell.h"
#include "fnv/decl/fnv_00580540__FUN_00580540_t.h"
#include "fnv/decl/fnv_00580560__FUN_004fc990_t.h"
#include "fnv/decl/fnv_00580580__FUN_00580580_t.h"
#include "fnv/decl/fnv_005805a0__FUN_005805a0_t.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01031000.h"
#include "teswaterform_decls.h"
#include "teswaterform_types_TESWaterForm.h"
#include "fnv/water/placeable_water.h"
#include "fnv/water/water_form.h"

// Initializes the object's fields with default constants and global values.
// @fnv 0x0057e9c0
void WaterShaderSettings::Initialize()
{
    SplatterSettings = ::DAT_0101e2bc;
    m_fSecondParameter = DAT_010249d8;
    m_fThirdParameter = 0.5f;
    m_fFourthSetting = 1.0f;
    SevenFloatParameterData = DAT_0101b268;
    SevenFloatParameters = 0.5f;
    SevenFloatData = DAT_010313d4;
    m_fEighthParameter = 0.0f;
    FiveFloatAndTwoUnsignedIntegerRecord = 0.0f;
    FourFloatAndThreeUnsignedIntegerRecord = 0.0f;
    WaterFogSettings = 1.0f;
    fUnderwaterFogDistNear = 0.0f;
    fUnderwaterFogDistFar = DAT_01013974;
    fUnderwaterFogAmount = 1.0f;
    FloatColorSettingsRecord = 0x00808000;
    ShaderColorParameterBlock = 0x00190000;
    ColorSettingsRecord = 0x00FFFFFF;
    SplatterColorSettings = ::DAT_0101e2bc;
    SplatterScalarSettings = DAT_01018180;
    SplatterFloatSettings = DAT_010231a4;
    SplatterParameterSet = DAT_010162c0;
    SplatterTimingSettings = 0.01f;
    SevenFloatRecordWithGlobals = DAT_010231a8;
    SevenFloatRecordWithStepAndGlobals = DAT_01018180;
    SevenFloatRecordWithStep = DAT_010231a4;
    SevenFloatFormatBlock = 10.0f;
    SevenFloatRecordWithUnitValue = DAT_010181bc;
    m_fWaterFogParameter1 = 0.0f;
    m_fValueBeforeWaterFogSettings = 0.0f;
    SevenFloatParameterSet = 1.0f;
    WaterFogParameterData = DAT_01013d84;
    m_fWaterParameter1 = 100.0f;
    m_fWaterParameter2 = 100.0f;
    m_fWaterParameter3 = 100.0f;
    WaterShaderProperties = DAT_0101b2d0;
    m_fShininess = 100.0f;
    WaterShaderParameters = 1.0f;
    MaterialParametersWithLeadingFloat = DAT_01022958;
    MaterialParameters = 1.0f;
}

// The form factory does not see the complete type, so the owner sizes the
// allocation. TESWaterForm::TESWaterForm has no definition; the recipe binds
// the name to 0x0057eba0. See docs/water-form-storage.md.
::TESWaterForm* fnv::water::NewWaterForm()
{
    return new TESWaterForm;
}

// @fnv 0x0057f8b0
void TESWaterForm::InitItem()
{
    if (GetInitialized())
        return;
    unsigned int id = (unsigned int)(std::uintptr_t)m_pWaterSound;
    if (id)
    {
        ::ResolveFormID((unsigned int *)&(id), GetFile(-1));
        m_pWaterSound = dynamic_cast<TESSound*>(::FUN_004839c0(id));
        if (!m_pWaterSound)
            ::FUN_005b5e40();
    }
    id = (unsigned int)(std::uintptr_t)m_pWaterSpell;
    if (id)
    {
        ::ResolveFormID((unsigned int *)&(id), GetFile(-1));
        m_pWaterSpell = dynamic_cast<SpellItem*>(::FUN_004839c0(id));
        if (!m_pWaterSpell)
            ::FUN_005b5e40();
        if (m_pWaterSpell && !m_pWaterSpell->IsEmpty())
        {
            WaterEffectList* node = m_pWaterSpell;
            EffectItem* radiation = 0;
            EffectItem* health = 0;
            while (node && (!radiation || !health))
            {
                EffectItem* effect = ((::EffectItem *)((void *)(node)));
                if (effect->GetAffectedActorValue() == 54 && reinterpret_cast<::S3e60 *>((((::EffectSetting *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((effect))->FUN_00825c00()))))->FUN_00403e60(4))
                {
                    radiation = effect;
                    m_iRadiationMagnitude = reinterpret_cast<::FUN_00404390_shell *>((radiation))->FUN_00404390();
                }
                else if (effect->GetAffectedActorValue() == 16 && !reinterpret_cast<::S3e60 *>((((::EffectSetting *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((effect))->FUN_00825c00()))))->FUN_00403e60(4))
                {
                    health = effect;
                    m_iHealthMagnitude = reinterpret_cast<::FUN_00404390_shell *>((health))->FUN_00404390();
                }
                node = static_cast<WaterEffectList*>(((::BSSimpleList< ::EffectItem *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())));
            }
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        id = (unsigned int)(std::uintptr_t)m_apWaterForms[i];
        if (id)
        {
            ::ResolveFormID((unsigned int *)&(id), GetFile(-1));
            m_apWaterForms[i] = dynamic_cast<TESWaterForm*>(::FUN_004839c0(id));
            if (!m_apWaterForms[i])
                ::FUN_005b5e40();
        }
    }
    SetInitializationState(true);
}

struct FUN_0057eef0_shell : public TESWaterForm
{
    WaterShaderSettings* FUN_0057eef0();
};
// @fnv 0x0057ef10
void TESWaterForm::ResetFormData()
{
    m_ucOpacity = 0x4B;
    cFlags = 0;
    m_pWaterSound = 0;
    reinterpret_cast<::TextString *>(&(m_kMaterialId))->FUN_004037f0(0, 0);
    reinterpret_cast<::FUN_0057eef0_shell *>(this)->FUN_0057eef0()->Initialize();

    for (int i = 0; i < 3; ++i)
        m_apWaterForms[i] = 0;
}

// @fnv 0x0057eef0
WaterShaderSettings* FUN_0057eef0_shell::FUN_0057eef0()
{
    return &Data;
}

struct FUN_0057f890_shell : public TESWaterForm
{
    void FUN_0057f890(SpellItem*);
};

// @fnv 0x0057f890
void FUN_0057f890_shell::FUN_0057f890(SpellItem* apSpellItem)
{
    m_pWaterSpell = apSpellItem;
}

struct FUN_0057fed0 : TESWaterForm
{
    SpellItem* GetMember();
};

// @fnv 0x0057fed0
SpellItem* FUN_0057fed0::GetMember()
{
    return m_pWaterSpell;
}

struct FUN_0057fef0_shell : TESWaterForm
{
    void FUN_0057fef0(const char* name);
};

// @fnv 0x0057fef0
void FUN_0057fef0_shell::FUN_0057fef0(const char* name)
{
    reinterpret_cast<::TextString *>(&(m_kMaterialId))->FUN_004037f0(name, 0);
}

struct FUN_00580060_shell : TESWaterForm
{
    bool FUN_00580060();
};

// @fnv 0x00580060
bool FUN_00580060_shell::FUN_00580060()
{
    if (this->cFlags & 1)
        return true;
    return false;
}

class TESModel
{
  public:
    unsigned int GetModelLength() const;
};

struct FUN_00580080_shell : TESWaterForm
{
    unsigned int FUN_00580080();
};

// @fnv 0x00580080
unsigned int FUN_00580080_shell::FUN_00580080()
{
    return ((TESModel*)&this->m_kNoiseMapTexture)->GetModelLength();
}

struct FNStub
{
};

struct FUN_005800a0_shell : TESWaterForm
{
    char const* FUN_005800a0() const;
};

// @fnv 0x005800a0
char const* FUN_005800a0_shell::FUN_005800a0() const
{
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((FNStub*)&this->m_kNoiseMapTexture)))->FUN_00408da0()));
}

struct NP
{
    NP& operator=(void*);
};

struct FUN_005800c0_shell : TESWaterForm
{
    void SetNP(void* arg);
};

// @fnv 0x005800c0
void FUN_005800c0_shell::SetNP(void* apValue)
{
    *reinterpret_cast<NP*>(&m_kNoiseTextureData) = apValue;
}

class FormChangeMask
{
  public:
    unsigned int uiFlags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
struct FUN_00865df0_buf : BGSLoadFormBuffer
{
};
struct FUN_005806e0_s
{
    char pad[0x80];
    void* m_pWaterForm;
    void FUN_005806e0(FUN_00865df0_buf* apSaveGameBuffer);
};
// @fnv 0x005806e0
void FUN_005806e0_s::FUN_005806e0(FUN_00865df0_buf* apSaveGameBuffer)
{
    reinterpret_cast<::FakeForm *>(this)->SaveIfChanged((::BGSSaveFormBuffer *)(apSaveGameBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags(0x80000000)))->FUN_004280f0(0x80000000))
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pWaterForm), 0);
}

namespace fnv_005807a0 {
class FormChangeMask
{
  public:
    unsigned int m_flags;
    __forceinline operator bool() const
    {
        return m_flags != 0;
    }
};

struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int) const;
};

struct FUN_005807a0_shell : TESWaterForm
{
    void FUN_005807a0(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x005807a0
void FUN_005807a0_shell::FUN_005807a0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((std::uintptr_t)apLoadGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_005807a0::FormChangeMask &)(apLoadGameBuffer->GetOldChangeFlags(0x80000000)))->FUN_004280f0(0x80000000))
        *(void**)&this->m_pWaterForm = 0;
}
}  // namespace fnv_005807a0

struct FUN_004fc990_t
{
    void FUN_004fc990(int, bool);
};
struct FUN_005802f0_shell
{
    void FUN_005802f0(bool abFlag);
};
// @fnv 0x005802f0
void FUN_005802f0_shell::FUN_005802f0(bool abFlag)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x20, abFlag);
}

struct BGSLoadGameBuffer : public BGSLoadFormBuffer
{
};

struct FUN_00580730_shell : public TESWaterForm
{
    void FUN_00580730(BGSLoadGameBuffer* apLoadGameBuffer);
};

// @fnv 0x00580730
void FUN_00580730_shell::FUN_00580730(BGSLoadGameBuffer* apLoadGameBuffer)
{
    TESForm::LoadGame(apLoadGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x80000000)))->FUN_004280f0(0x80000000))
        m_pWaterForm = dynamic_cast<TESWaterForm*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0()));
}

struct Flt
{
    operator std::uintptr_t() const;
};
struct Holder : TESWaterForm
{
    const char* FUN_0057fda0();
public:
    void FUN_00485680();
};
// Returns the stored string pointer if the field is nonzero, otherwise an empty string literal.
// @fnv 0x0057fda0
const char* Holder::FUN_0057fda0()
{
    Flt& kHandle = *reinterpret_cast<Flt*>(&m_kMaterialId);
    return kHandle ? (const char*)(std::uintptr_t)kHandle : "";
}

struct FUN_00580100_obj : TESWaterForm
{
    float FUN_00580100();
};
// @fnv 0x00580100
float FUN_00580100_obj::FUN_00580100()
{
    return m_ucOpacity / g_d100;
}

struct FUN_004855a0_standin
{
};
struct FUN_00485680_standin
{
};
struct FUN_00487010_shell
{
    void FUN_00487010();
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct S7010
{
};

struct FUN_0057fbf0_shell : public TESWaterForm
{
    void SaveWaterForm();
};

struct FUN_0057ff10_shell : public TESWaterForm
{
    bool FUN_0057ff10(TESForm* apCompare);
};

class TESPackage
{
  public:
    unsigned int GetRefCount();
};

struct FUN_005e79a0_t
{
};

struct FUN_0057ff10_texture
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool operator==(FUN_0057ff10_texture*);
};


// @fnv 0x0057ff10
bool FUN_0057ff10_shell::FUN_0057ff10(TESForm* apCompare)
{
    TESWaterForm* pcomp;

    pcomp = dynamic_cast<TESWaterForm*>(apCompare);
    if (pcomp == 0)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcomp))
        return true;

    if (this->cFlags != pcomp->cFlags)
        return true;

    if (this->m_ucOpacity != pcomp->m_ucOpacity)
        return true;

    if (std::memcmp(reinterpret_cast<::FUN_0057eef0_shell *>(this)->FUN_0057eef0(), reinterpret_cast<::FUN_0057eef0_shell *>((pcomp))->FUN_0057eef0(), 0xc4) != 0)
        return true;

    if (((FUN_0057ff10_texture*)&this->m_kNoiseMapTexture)->operator==((FUN_0057ff10_texture*)&pcomp->m_kNoiseMapTexture))
        return true;

    if (((TESPackage*)this)->GetRefCount() != ((TESPackage*)pcomp)->GetRefCount())
        return true;

    if (((Holder*)this)->FUN_0057fda0() != ((Holder*)pcomp)->FUN_0057fda0())
        return true;

    if (((FUN_0057fed0*)this)->GetMember() != ((FUN_0057fed0*)pcomp)->GetMember())
        return true;

    if (std::memcmp((char*)&this->m_apWaterForms, (char*)&pcomp->m_apWaterForms, 0xc) != 0)
        return true;

    return false;
}

struct FUN_00580310_t
{
    void SetFlag400(bool);
};

struct FUN_005802d0_shell
{
    void FUN_005802d0(bool);
};

struct FUN_00580130_shell : public TESWaterForm
{
    BGSPlaceableWater* FUN_00580130();
};


// Returns the BGSPlaceableWater stored at offset 0x180, creating and initialising it with editor ID "PlaceableAutoWater" if it is null.
// @fnv 0x00580130
BGSPlaceableWater* FUN_00580130_shell::FUN_00580130()
{
    char ptempname[260];

    if (this->m_pPlaceableAutoWater == 0)
    {
        this->m_pPlaceableAutoWater = fnv::water::NewPlaceableWater();

        fnv::water::PlaceableWaterForm(this->m_pPlaceableAutoWater)
            ->NotifySaveLoadGameOfFormChange();

        reinterpret_cast<::fnv_004fc450::FUN_004fc450_shell *>(((this->m_pPlaceableAutoWater)))->FUN_004fc450(true);

        reinterpret_cast<FUN_00580310_t*>(this->m_pPlaceableAutoWater)
            ->SetFlag400(true);

        reinterpret_cast<::FUN_004fc3a0_shell *>(((this->m_pPlaceableAutoWater)))->FUN_004fc3a0(true);

        reinterpret_cast<FUN_005802d0_shell*>(
            this->m_pPlaceableAutoWater)
            ->FUN_005802d0(true);

        reinterpret_cast<FUN_005802f0_shell*>(
            this->m_pPlaceableAutoWater)
            ->FUN_005802f0(true);

        ::FUN_00406d00(ptempname, 0x104, "PlaceableAutoWater");

        fnv::water::PlaceableWaterForm(this->m_pPlaceableAutoWater)
            ->SetEditorID_AtRuntime(ptempname);

        fnv::water::SetOwningWater(this->m_pPlaceableAutoWater, this);
    }

    return this->m_pPlaceableAutoWater;
}

namespace fnv_00580330 {
struct FUN_005802d0_shell
{
};

struct FUN_00580330_shell : public ::TESWaterForm
{
    BGSPlaceableWater* FUN_00580330();
};


// @fnv 0x00580330
BGSPlaceableWater* FUN_00580330_shell::FUN_00580330()
{
    char ptempname[260];

    if (m_pPlaceableWater == 0)
    {
        m_pPlaceableWater = fnv::water::NewPlaceableWater();

        fnv::water::PlaceableWaterForm(m_pPlaceableWater)->NotifySaveLoadGameOfFormChange();

        reinterpret_cast<::fnv_005805a0::FUN_005805a0_t *>((m_pPlaceableWater))->SetFlag8000000(true);
        reinterpret_cast<::FUN_004fc360_shell *>((m_pPlaceableWater))->FUN_004fc360(true);
        reinterpret_cast<::FUN_004fc3e0_shell *>((m_pPlaceableWater))->FUN_004fc3e0(false);
        reinterpret_cast<::fnv_00580540::FUN_00580540_t *>((m_pPlaceableWater))->SetValue(false);
        reinterpret_cast<::FUN_004fc380_shell *>((m_pPlaceableWater))->FUN_004fc380(false);
        reinterpret_cast<::FUN_004fc3a0_shell *>((m_pPlaceableWater))->FUN_004fc3a0(true);

        reinterpret_cast<::FUN_005802d0_shell *>((reinterpret_cast<FUN_005802d0_shell*>(m_pPlaceableWater)))->FUN_005802d0(true);

        reinterpret_cast<FUN_005802f0_shell*>(m_pPlaceableWater)->FUN_005802f0(false);

        reinterpret_cast<::FUN_004fc3c0_shell *>((m_pPlaceableWater))->FUN_004fc3c0(true);
        reinterpret_cast<::fnv_00580560::FUN_004fc990_t *>((m_pPlaceableWater))->SetFlag80(false);
        reinterpret_cast<::fnv_00580580::FUN_00580580_t *>((m_pPlaceableWater))->SetFlag100(false);

        ::FUN_00406d00(ptempname, 0x104, "PlaceableLODWater");

        fnv::water::PlaceableWaterForm(m_pPlaceableWater)->SetEditorID_AtRuntime(ptempname);

        fnv::water::SetOwningWater(m_pPlaceableWater, this);
    }

    return m_pPlaceableWater;
}
}  // namespace fnv_00580330

struct FUN_0057ee10_Primary
{
    virtual ~FUN_0057ee10_Primary();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct FUN_0057ee10_Base18
{
    virtual ~FUN_0057ee10_Base18();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_0057ee10_Base24
{
    virtual ~FUN_0057ee10_Base24();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_0057ee10_Sub30
{
    ~FUN_0057ee10_Sub30();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
};

struct FUN_0057ee10_Sub64
{
    ~FUN_0057ee10_Sub64();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_0057ee10_Sub74
{
    ~FUN_0057ee10_Sub74();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
};
struct FUN_0057ee10_Sub17c
{
    ~FUN_0057ee10_Sub17c();
    void Unk_Init(unsigned int arg);
    unsigned int unk04;
};

struct FUN_0057ee10 : FUN_0057ee10_Primary, FUN_0057ee10_Base18, FUN_0057ee10_Base24
{
    FUN_0057ee10_Sub30 m_30;
    FUN_0057ee10_Sub64 m_64;
    FUN_0057ee10_Sub74 m_74;
    FUN_0057ee10_Sub17c m_17c;
    virtual ~FUN_0057ee10();
};

// Destructor that resets the m_17c sub-object by calling Unk_Init(0).
// @fnv 0x0057ee10
FUN_0057ee10::~FUN_0057ee10()
{
    m_17c.Unk_Init(0);
}

struct WaterFullNameBase
{
    WaterFullNameBase();
    ~WaterFullNameBase();
    virtual void Init();
    unsigned int nameData;
    unsigned int nameLength;
};
struct WaterAttackBase
{
    WaterAttackBase();
    ~WaterAttackBase();
    virtual void Init();
    unsigned short damage;
    unsigned short reserved;
    bool needUpdate;
};
struct WaterPointer
{
    WaterPointer(int);
    ~WaterPointer();
    void* object;
};
struct WaterColor
{
    WaterColor(float, float, float, float);
    float r, g, b, a;
};
struct WaterTexture
{
    WaterTexture();
    ~WaterTexture();
    virtual void Init();
    unsigned int nameData;
    unsigned int nameLength;
    unsigned char alpha, flags;
};
struct WaterString
{
    WaterString();
    ~WaterString();
    unsigned int data;
    unsigned int length;
};
struct FUN_0057e9a0 : WaterShaderSettings
{
    FUN_0057e9a0();
};
struct FUN_0057eba0 : TESForm, WaterFullNameBase, WaterAttackBase
{
    WaterPointer normalMap;
    WaterColor scroll0, scroll1, scroll2;
    WaterTexture texture;
    WaterString material;
    void* sound;
    void* remapped;
    FUN_0057e9a0 shader;
    void* weather0;
    void* weather1;
    void* weather2;
    int select01, select02;
    unsigned int frequencyX, frequencyY;
    int octaves;
    float amplitude, lacunarity, bias, gain;
    void* spell;
    WaterPointer noiseTexture;
    void* autoWater;
    void* lodWater;
    int radiation, health;
    bool reset;
    FUN_0057eba0();
    virtual ~FUN_0057eba0();
};
// @fnv 0x0057eba0
FUN_0057eba0::FUN_0057eba0()
    : normalMap(0), scroll0(0.0f, 0.0f, 0.0f, 0.0f), scroll1(0.0f, 0.0f, 0.0f, 0.0f), scroll2(0.0f, 0.0f, 0.0f, 0.0f),
      noiseTexture(0)
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x4e)));
    reinterpret_cast<::TESWaterForm *>(this)->ResetFormData();
    select01 = 0;
    select02 = 0;
    frequencyX = 9;
    frequencyY = 9;
    octaves = 4;
    amplitude = 0.5f;
    lacunarity = 2.0f;
    bias = 0.5f;
    gain = 0.5f;
    spell = 0;
    needUpdate = true;
    reset = false;
    autoWater = 0;
    lodWater = 0;
    radiation = 0;
    health = 0;
    remapped = 0;
}

struct ByteArg
{
    unsigned char c;
};
struct F3a0 : WaterShaderSettings
{
    void FUN_0057f3a0();
};
// Reads a TESWaterForm record from file: checks form type 78, loads the header, then processes chunks (EDID, OBND, FULL, DATA, DNAM, etc.) into the form's fields.
// @fnv 0x0057ef80
bool TESWaterForm::Load(TESFile* file)
{
    unsigned char ucFormType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (ucFormType != 78)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    unsigned int uiChunkID;
    while ((uiChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch ((int)uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x41544144: {
            unsigned int uiAddedSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() - reinterpret_cast<::FUN_00486620_shell *>(this)->FUN_00486620();
            if (!uiAddedSize)
            {
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, 0, 0);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::F3a0 *>(&(Data))->FUN_0057f3a0();
            }
            else
            {
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, &Data, 196);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::F3a0 *>(&(Data))->FUN_0057f3a0();
                Data.m_fWaterParameter1 = 100.0f;
                Data.m_fWaterParameter2 = 100.0f;
                Data.m_fWaterParameter3 = 100.0f;
                Data.m_fWaterParameter4 = 1.0f;
                Data.m_fWaterParameter5 = 0.5f;
                Data.m_fWaterParameter6 = 0.25f;
                reinterpret_cast<::FUN_0047ff50_class *>(this)->FUN_0047ff50(0);
            }
            break;
        }
        case 0x4d414e44:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), 196);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::F3a0 *>(&(Data))->FUN_0057f3a0();
            break;
        case 0x4d414e4e:
            ::TESTexture::ReadTextureData(&m_kNoiseMapTexture, file);
            break;
        case 0x4d414e41:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_ucOpacity), 1);
            break;
        case 0x4d414e46:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&cFlags), 1);
            break;
        case 0x4d414e53: {
            unsigned int shader = 0;
            file->GetChunkData(&shader);
            reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader((TESEffectShader*)(std::uintptr_t)shader);
            break;
        }
        case 0x4d414e58: {
            unsigned int spell = 0;
            file->GetChunkData(&spell);
            reinterpret_cast<::FUN_0057f890_shell *>(this)->FUN_0057f890((SpellItem*)(std::uintptr_t)spell);
            break;
        }
        case 0x4d414e4d: {
            char* material = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(material), 0);
            reinterpret_cast<::TextString *>(&(m_kMaterialId))->FUN_004037f0(material, 0);
            break;
        }
        case 0x4d414e47:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_apWaterForms), 12);
            if (file->IsEndianConversionRequired())
            {
                for (int i = 0; i < 3; ++i)
                    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)&m_apWaterForms[i]));
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
// Serializes the water form: writes name, model, flags, form IDs, and a 0xc4-byte Data block, swapping endianness when needed.
// @fnv 0x0057fbf0
void FUN_0057fbf0_shell::SaveWaterForm()
{
    unsigned int auiFormIds[3];
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_standin*)this)))->FUN_004855a0();
    ((FUN_00487010_shell*)static_cast<TESFullName *>(this))->FUN_00487010();
    ::FUN_004856f0((void *)(0x4d414e4e), (void*)((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((FNStub*)&this->m_kNoiseMapTexture)))->FUN_00408da0())),
                 (void *)(std::uintptr_t)(((TESModel*)&this->m_kNoiseMapTexture)->GetModelLength() + 1));
    FUN_004858f0(0x4d414e41, m_ucOpacity);
    FUN_004858f0(0x4d414e46, cFlags);
    ::FUN_004856f0((void *)(0x4d414e4d), (void*)((Holder*)this)->FUN_0057fda0(), (void *)(std::uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)&this->m_kMaterialId)))->FUN_004048e0())) + 1));
    if (m_pWaterSound)
    {
        unsigned int itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWaterSound))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, itempint);
    }
    if (m_pWaterSpell)
    {
        unsigned int itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWaterSpell))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e58, itempint);
    }
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::F3a0 *>(&(Data))->FUN_0057f3a0();
    ::AppendChunk(0x4d414e44, &Data, 0xc4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::F3a0 *>(&(Data))->FUN_0057f3a0();
    for (int i = 0; i < 3; i++)
    {
        if (m_apWaterForms[i])
            auiFormIds[i] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_apWaterForms[i]))->FUN_0084e3a0()));
        else
            auiFormIds[i] = 0;
    }
    ::FUN_00485710((void *)(0x4d414e47), auiFormIds, (void *)(3));
    reinterpret_cast<::Holder *>((((FUN_00485680_standin*)this)))->FUN_00485680();
}
// @fnv 0x0057f3a0
void F3a0::FUN_0057f3a0()
{
    ::FUN_00401080((int *)(void *)((char*)this + 0x0));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fSecondParameter));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fThirdParameter));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fFourthSetting));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatParameterData));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatParameters));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatData));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fEighthParameter));
    ::FUN_00401080((int *)(void *)((char*)&this->FiveFloatAndTwoUnsignedIntegerRecord));
    ::FUN_00401080((int *)(void *)((char*)&this->FourFloatAndThreeUnsignedIntegerRecord));
    ::FUN_00401080((int *)(void *)((char*)&this->FloatColorSettingsRecord));
    ::FUN_00401080((int *)(void *)((char*)&this->ShaderColorParameterBlock));
    ::FUN_00401080((int *)(void *)((char*)&this->ColorSettingsRecord));
    ::FUN_00401080((int *)(void *)((char*)&this->SplatterColorSettings));
    ::FUN_00401080((int *)(void *)((char*)&this->SplatterScalarSettings));
    ::FUN_00401080((int *)(void *)((char*)&this->SplatterFloatSettings));
    ::FUN_00401080((int *)(void *)((char*)&this->SplatterParameterSet));
    ::FUN_00401080((int *)(void *)((char*)&this->SplatterTimingSettings));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatRecordWithGlobals));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatRecordWithStepAndGlobals));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatRecordWithStep));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatFormatBlock));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatRecordWithUnitValue));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatParameterSet));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatParameterCollection));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatParameterGroup));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatValues));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatSet));
    ::FUN_00401080((int *)(void *)((char*)&this->SevenFloatBlock));
    ::FUN_00401080((int *)(void *)((char*)&this->WaterFogParameters));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fWaterFogParameter1));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fValueBeforeWaterFogSettings));
    ::FUN_00401080((int *)(void *)((char*)&this->WaterFogSettings));
    ::FUN_00401080((int *)(void *)((char*)&this->WaterFogParameterData));
    ::FUN_00401080((int *)(void *)((char*)&this->fUnderwaterFogAmount));
    ::FUN_00401080((int *)(void *)((char*)&this->fUnderwaterFogDistNear));
    ::FUN_00401080((int *)(void *)((char*)&this->fUnderwaterFogDistFar));
    ::FUN_00401080((int *)(void *)((char*)&this->WaterShaderProperties));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fShininess));
    ::FUN_00401080((int *)(void *)((char*)&this->WaterShaderParameters));
    ::FUN_00401080((int *)(void *)((char*)&this->MaterialParametersWithLeadingFloat));
    ::FUN_00401080((int *)(void *)((char*)&this->MaterialParameters));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fWaterParameter1));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fWaterParameter2));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fWaterParameter3));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fWaterParameter4));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fWaterParameter5));
    ::FUN_00401080((int *)(void *)((char*)&this->m_fWaterParameter6));
}

struct FUN_006e5cc0_Class
{
    void FUN_006e5cc0(void* a1);
};
struct FUN_005800e0_shell : TESWaterForm
{
    void FUN_005800e0(FUN_006e5cc0_Class* a1);
};
// @fnv 0x005800e0
void FUN_005800e0_shell::FUN_005800e0(FUN_006e5cc0_Class* a1)
{
    a1->FUN_006e5cc0((char*)&this->m_kNoiseTextureData);
}

#include <string.h>

struct FUN_005e78f0_t
{
};
struct WaterEffectSetting : public TESWaterForm
{
    void FUN_0057fde0(TESForm* apCopy);
};
// Copies water effect settings from apCopy into this, including flags, opacity, shader, spell item, and noise map texture.
// @fnv 0x0057fde0
void WaterEffectSetting::FUN_0057fde0(TESForm* apCopy)
{
    TESWaterForm* pcopy = dynamic_cast<TESWaterForm*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005e78f0_t*>(this)))->FUN_004851b0(pcopy);
    this->cFlags = pcopy->cFlags;
    this->m_ucOpacity = pcopy->m_ucOpacity;
    memcpy(reinterpret_cast<::FUN_0057eef0_shell *>((this))->FUN_0057eef0(), reinterpret_cast<::FUN_0057eef0_shell *>((pcopy))->FUN_0057eef0(), 0xc4);
    reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader(
        reinterpret_cast<TESEffectShader*>(reinterpret_cast<TESPackage*>(pcopy)->GetRefCount()));
    reinterpret_cast<::FUN_0057f890_shell *>((this))->FUN_0057f890(reinterpret_cast<FUN_0057fed0*>(pcopy)->GetMember());
    memcpy(reinterpret_cast<unsigned char*>(&this->m_apWaterForms), reinterpret_cast<unsigned char*>(&pcopy->m_apWaterForms), 0xc);
    this->m_kNoiseMapTexture.CopyFromBase(
        static_cast<BaseFormComponent *>(&pcopy->m_kNoiseMapTexture));
    reinterpret_cast<FUN_0057fef0_shell*>(this)->FUN_0057fef0(reinterpret_cast<Holder*>(pcopy)->FUN_0057fda0());
}

#include "generated/data/fallout_shared/teswaterform.inc"
