// fallout_shared/bgsexplosion.cpp: BGSExplosion, EffectSetting, ScalarHelper, BGSExplosionCompare and more (22 functions)

#include <cstdint>
#include <cstring>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTalkingActivator.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fb970_class.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00516bf0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/IntFieldContainer.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0050ee50__CloneObject17.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fa000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "bgsexplosion_types_BGSExplosion.h"
#include "bgsexplosion_decls.h"
#include "fnv/symbols_00472000.h"

// Clears the explosion's field to 0 and calls InitExplosionData on the object returned by FUN_004fadc0.
// @fnv 0x004fade0
void BGSExplosion::ResetFormData()
{
    m_pExplosionBoundObject = 0;
    ::InitExplosionData((::BGSExplosionData_init *)(FUN_004fadc0()));
}

// @fnv 0x004fabf0
BGSExplosion::BGSExplosion()
    : TESBoundObject(), TESFullName(), TESModel(), TESEnchantableForm(), BGSPreloadable(), TESImageSpaceModifiableForm()
{
    ::FUN_004faa00((::ExplosionEffectSettings *)&(Data));
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x51)));
    ResetFormData();
    reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00((*(int *)&(const ::MagicSystem__CastingType &)((MagicSystem__CastingType)2)));
}
// @fnv 0x004fae10
void BGSExplosion::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;

    unsigned int formID = (unsigned int)(std::uintptr_t)(reinterpret_cast<EffectSetting*>(this)->GetCastSound());
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<::FUN_008ac890_shell *>((reinterpret_cast<EffectSetting*>(this)))->SetWaterForm(
            (::TESWaterForm *)(::TESSound *)(reinterpret_cast<TESSound*>(dynamic_cast<TESObjectLIGH*>(::FUN_004839c0(formID)))));
    }

    formID = (unsigned int)(std::uintptr_t)(((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(reinterpret_cast<EffectSetting*>(this))))));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(
            dynamic_cast<TESSound*>(::FUN_004839c0(formID)));
    }

    formID = reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<::BGSTalkingActivator *>(this)->SetVoiceType((::BGSVoiceType *)(::TESSound *)(dynamic_cast<TESSound*>(::FUN_004839c0(formID))));
    }

    formID = (unsigned int)(std::uintptr_t)(((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>(this)->FUN_00516bf0())));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        FUN_004fb0b0(dynamic_cast<BGSImpactDataSet*>(::FUN_004839c0(formID)));
        if (!((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>(this)->FUN_00516bf0())))
            ::FUN_005b5e40();
    }

    formID = (unsigned int)(std::uintptr_t)(m_pExplosionBoundObject);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pExplosionBoundObject = dynamic_cast<TESBoundObject*>(::FUN_004839c0(formID));
        if (!m_pExplosionBoundObject)
            ::FUN_005b5e40();
    }

    TESImageSpaceModifiableForm::InitItem(this);
    TESEnchantableForm::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x004fb0d0
bool BGSExplosion::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x51)
        return false;

    ClearData();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);

    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4d414e45:
        case 0x4d544945: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            reinterpret_cast<CombatProcedure*>(static_cast<TESEnchantableForm *>(this))
                ->Initialize(reinterpret_cast<CombatController*>(value));
            break;
        }
        case 0x4d414e41:
        case 0x544d4145: {
            unsigned short amount = 0;
            reinterpret_cast<::FUN_00472840_impl *>((reinterpret_cast<TESFileChunkData16*>(file)))->ReadChunkData(&amount);
            reinterpret_cast<::TESEnchantableForm *>(this)->SetFormEnchantmentAmount(amount);
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, &Data, 0x34);
            break;
        case 0x4d414e4d: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            reinterpret_cast<CombatProcedure*>(static_cast<TESImageSpaceModifiableForm *>(this))
                ->Initialize(reinterpret_cast<CombatController*>(value));
            break;
        }
        case 0x4d414e49: {
            unsigned int value = 0;
            file->GetChunkData(&value);
            m_pExplosionBoundObject = reinterpret_cast<TESBoundObject*>(value);
            break;
        }
        }

        if (chunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<::IntFieldContainer *>((reinterpret_cast<EndianConvertibleData*>(&Data)))->SwapAllFields();

        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x004fb090
void EffectSetting::SetBoltSound(TESSound* sound)
{
    bgsexplosion_boltSound = sound;
}

// @fnv 0x004fb0b0
void BGSExplosion::FUN_004fb0b0(BGSImpactDataSet* apImpactDataSet)
{
    Data.m_pImpactDataSet = apImpactDataSet;
}

// @fnv 0x004fb070
TESSound* EffectSetting::GetCastSound()
{
    return bgsexplosion_castSound;
}

// @fnv 0x004fadc0
ExplosionEffectSettings* BGSExplosion::FUN_004fadc0()
{
    return &Data;
}

// @fnv 0x004faa00
ExplosionEffectSettings* FUN_004faa00(ExplosionEffectSettings* pThis)
{
    ::InitExplosionData((::BGSExplosionData_init *)(pThis));
    return pThis;
}

struct BGSExplosionData_init
{
    float f0;   // 0x00
    float f1;   // 0x04
    float f2;   // 0x08
    int i3;     // 0x0c
    int i4;     // 0x10
    int i5;     // 0x14
    float f6;   // 0x18
    int i7;     // 0x1c
    int i8;     // 0x20
    float f9;   // 0x24
    float f10;  // 0x28
    float f11;  // 0x2c
    int i12;    // 0x30
};

// Zeroes the float and int fields of the explosion data and sets i12 to 1.
// @fnv 0x004faa20
void InitExplosionData(BGSExplosionData_init* pThis)
{
    pThis->f0 = 0.0f;
    pThis->f1 = 0.0f;
    pThis->f2 = 0.0f;
    pThis->f9 = 0.0f;
    pThis->f10 = 0.0f;
    pThis->f11 = 0.0f;
    pThis->i3 = 0;
    pThis->i4 = 0;
    pThis->i5 = 0;
    pThis->f6 = 0.0f;
    pThis->i7 = 0;
    pThis->i8 = 0;
    pThis->i12 = 1;
}

struct ScalarHelper
{
    void* FUN_004facf0(unsigned int);
};
int __cdecl FUN_0058e8f0(int);
struct Proxy804
{
    BGSImpactData* FUN_004fb7a0(int);
};
// @fnv 0x004fb7a0
BGSImpactData* Proxy804::FUN_004fb7a0(int a)
{
    return reinterpret_cast<::BGSImpactDataSet *>(this)->GetImpactDataForMaterial(FUN_0058e8f0(a));
}

struct FUN_004fb7a0_obj
{
};
struct FUN_004fb7d0_shell
{
    intptr_t FUN_004fb7d0(int);
};
// If the explosion object returned by FUN_00516bf0 exists, forwards a to its FUN_004fb7a0 and returns the result; otherwise returns 0.
// @fnv 0x004fb7d0
intptr_t FUN_004fb7d0_shell::FUN_004fb7d0(int a)
{
    std::intptr_t result = 0;
    if (((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>((((BGSExplosion*)this)))->FUN_00516bf0())))
        result = ((std::intptr_t)(reinterpret_cast<::Proxy804 *>((((FUN_004fb7a0_obj*)((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>((((BGSExplosion*)this)))->FUN_00516bf0())))))->FUN_004fb7a0(a)));
    return result;
}

struct FUN_00477950_shell : public BGSExplosion
{
    bool HasAnyFlags(unsigned int mask);
};

// @fnv 0x00477950
bool FUN_00477950_shell::HasAnyFlags(unsigned int mask)
{
    return (FUN_004fadc0()->iFlags & mask) ? true : false;
}

struct FUN_005e79a0_t
{
};

struct EffectSettingShell : EffectSetting
{
    TESObjectLIGH* GetLight();
};

struct BGSExplosionCompare : BGSExplosion
{
    bool CompareTo(TESForm* form);
};

// @fnv 0x004fb610
bool BGSExplosionCompare::CompareTo(TESForm* form)
{
    BGSExplosion* pOther = dynamic_cast<BGSExplosion*>(form);
    if (!pOther)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pOther))
        return true;
    if (memcmp((char*)&this->Data, pOther->FUN_004fadc0(), 0x34))
        return true;
    if (reinterpret_cast<EffectSettingShell*>(this)->GetLight() !=
        reinterpret_cast<EffectSettingShell*>(pOther)->GetLight())
        return true;
    return false;
}

struct GlobalObject_0045cfe0
{
};
struct GlobalObject2_0040c150
{
};
GlobalObject2_0040c150 g_011cd3b4;
GlobalObject2_0040c150 g_011cd538;
GlobalObject2_0040c150 g_011cdde0;
struct FUN_004fb810_shell : ::BGSExplosion
{
    int* FUN_004fb810();
};
// @fnv 0x004fb810
int* FUN_004fb810_shell::FUN_004fb810()
{
    std::intptr_t result = 0;
    switch (*reinterpret_cast<int*>(&this->Data.m_eSoundLevel))
    {
    case 2:
        result = ((int *)&(::FUN_0043d4d0((int *)(((GlobalObject_0045cfe0*)&g_011cd3b4)))))[0];
        break;
    case 1:
        result = ((int *)&(::FUN_0043d4d0((int *)(((GlobalObject_0045cfe0*)&g_011cd538)))))[0];
        break;
    case 0:
        result = ((int *)&(::FUN_0043d4d0((int *)(((GlobalObject_0045cfe0*)&g_011cdde0)))))[0];
        break;
    }
    return (int*)result;
}

struct FUN_004855a0
{
};

struct DoorPart30
{
};

struct FUN_004891d0_obj
{
};

struct FUN_0047bd70_shell
{
    void FUN_0047bd70();
};

struct FUN_00487450_shell
{
    void FUN_00487450();
};

struct FUN_00485680
{
};

struct FUN_00485e00_shell
{
};

struct FUN_004fd380_shell
{
    TESObjectLIGH* FUN_004fd380();
};


struct FUN_004fb3b0_shell : ::BGSExplosion
{
    void FUN_004fb3b0();
};

// @fnv 0x004fb3b0
void FUN_004fb3b0_shell::FUN_004fb3b0()
{
    TESSound* psaveLight;
    TESSound* psaveSound2;
    unsigned int itempint;
    BGSImpactDataSet* psaveImpact;
    unsigned int psaveSound1;

    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<DoorPart30*>(static_cast<TESFullName *>(this))))->FUN_00487010();
    reinterpret_cast<::FUN_004891d0_cls *>((reinterpret_cast<FUN_004891d0_obj*>(static_cast<TESModel *>(this))))->WriteToBuffer((char *)(0x4C444F4D), (void *)(0x54444F4D));
    reinterpret_cast<FUN_0047bd70_shell*>(static_cast<TESEnchantableForm *>(this))->FUN_0047bd70();
    reinterpret_cast<FUN_00487450_shell*>(static_cast<TESImageSpaceModifiableForm *>(this))->FUN_00487450();

    psaveLight = reinterpret_cast<EffectSetting*>(this)->GetCastSound();
    reinterpret_cast<::FUN_008ac890_shell *>((reinterpret_cast<EffectSetting*>(this)))->SetWaterForm(
        (::TESWaterForm *)(::TESSound *)(reinterpret_cast<TESSound*>(reinterpret_cast<EffectSetting*>(this)->GetCastSound()
                                        ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<EffectSetting*>(this)->GetCastSound()))->FUN_0084e3a0()))
                                        : 0)));

    psaveSound2 = ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(reinterpret_cast<EffectSetting*>(this)))));
    reinterpret_cast<EffectSetting*>(this)->SetBoltSound(
        reinterpret_cast<TESSound*>(((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(reinterpret_cast<EffectSetting*>(this)))))
                                        ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(reinterpret_cast<EffectSetting*>(this)))))))->FUN_0084e3a0()))
                                        : 0));

    itempint = reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags();
    reinterpret_cast<::BGSTalkingActivator *>((reinterpret_cast<BGSExplosion*>(this)))->SetVoiceType((::BGSVoiceType *)(::TESSound *)(reinterpret_cast<TESSound*>(
        reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags()
            ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(reinterpret_cast<PlayerMover*>(this)->GetActorStateFlags())))->FUN_0084e3a0()))
            : 0)));

    psaveImpact = ((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>((reinterpret_cast<BGSExplosion*>(this)))->FUN_00516bf0()));
    reinterpret_cast<BGSExplosion*>(this)->FUN_004fb0b0(
        reinterpret_cast<BGSImpactDataSet*>(((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>((reinterpret_cast<BGSExplosion*>(this)))->FUN_00516bf0()))
                                                ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>((reinterpret_cast<BGSExplosion*>(this)))->FUN_00516bf0()))))->FUN_0084e3a0()))
                                                : 0));

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::IntFieldContainer *>((reinterpret_cast<EndianConvertibleData*>(&this->Data.fForce)))->SwapAllFields();

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20(
        reinterpret_cast<EndianConvertibleData*>(&this->Data.fForce), 0x34);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::IntFieldContainer *>((reinterpret_cast<EndianConvertibleData*>(&this->Data.fForce)))->SwapAllFields();

    reinterpret_cast<::FUN_008ac890_shell *>((reinterpret_cast<EffectSetting*>(this)))->SetWaterForm((::TESWaterForm *)(psaveLight));
    reinterpret_cast<EffectSetting*>(this)->SetBoltSound(psaveSound2);
    reinterpret_cast<::BGSTalkingActivator *>((reinterpret_cast<BGSExplosion*>(this)))->SetVoiceType((::BGSVoiceType *)(::TESSound *)(reinterpret_cast<TESSound*>(itempint)));
    reinterpret_cast<BGSExplosion*>(this)->FUN_004fb0b0(psaveImpact);

    if (reinterpret_cast<FUN_004fd380_shell*>(this)->FUN_004fd380())
    {
        psaveSound1 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FUN_004fd380_shell*>(this)->FUN_004fd380()))->FUN_0084e3a0()));
        ::FUN_00485910(0x4D414E49, psaveSound1);
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

class FUN_004fad20_cls : public TESBoundObject,
                         public TESFullName,
                         public TESModel,
                         public TESEnchantableForm,
                         public BGSPreloadable,
                         public TESImageSpaceModifiableForm
{
  public:
    virtual ~FUN_004fad20_cls();
};
// Calls FUN_004fad20, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004facf0
void* ScalarHelper::FUN_004facf0(unsigned int flags)
{
    reinterpret_cast<::FUN_004fad20_cls *>(this)->FUN_004fad20_cls::~FUN_004fad20_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Empty destructor for a class deriving from TESBoundObject, TESFullName, TESModel, TESEnchantableForm, BGSPreloadable and TESImageSpaceModifiableForm.
// @fnv 0x004fad20
FUN_004fad20_cls::~FUN_004fad20_cls()
{}

class TESFormFB6
{
  public:
    virtual ~TESFormFB6();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

class TESSoundFileFB6
{
  public:
    virtual ~TESSoundFileFB6();
    unsigned int GetSoundFileLength() const;

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class AttachHandlerFB6
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void Attach(int iA, int iB);
};

class AttachOwnerFB6
{
  public:
    virtual ~AttachOwnerFB6();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class AttachTargetFB6 : public AttachOwnerFB6, public AttachHandlerFB6
{
};

class LoaderClientFB6
{
  public:
    virtual void unkv00();
    virtual void AttachSoundAndTarget(int iA, int iB);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

class ExplosionFB6;

class ModelLoaderFB6
{
  public:
};



class ExplosionFB6 : public TESFormFB6, public TESSoundFileFB6, public LoaderClientFB6
{
  public:
    virtual void AttachSoundAndTarget(int iA, int iB);

    AttachTargetFB6* m_pkTarget;
};

// If this explosion has a sound file, queues it with the model loader, attaches m_pkTarget, and queues the default explosion's sound file if it has one.
// @fnv 0x004fb6a0
void ExplosionFB6::AttachSoundAndTarget(int iA, int iB)
{
    if (GetSoundFileLength())
        reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelLoaderFB6 * *>(&::g_modelLoader))))->FUN_00443d30((std::uintptr_t)(this), iA, iB, ::FUN_0045c6b0((::TESForm_0045c6b0 *)(::TESFormFB6 *)(this)), true, 0, 0);

    if (m_pkTarget)
        m_pkTarget->Attach(iA, iB);

    if ((*reinterpret_cast<::ExplosionFB6 * *>(&::DAT_011ca284)) && (*reinterpret_cast<::ExplosionFB6 * *>(&::DAT_011ca284))->GetSoundFileLength())
        reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::ModelLoaderFB6 * *>(&::g_modelLoader))))->FUN_00443d30((std::uintptr_t)((*reinterpret_cast<::ExplosionFB6 * *>(&::DAT_011ca284))), iA, iB, ::FUN_0045c6b0((::TESForm_0045c6b0 *)(::TESFormFB6 *)(this)), true, 0, 0);
}

class FNVArg
{
  public:
};

class FNVSub
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
};

struct FNVGlobal
{
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
    FNVSub m_3c;
};

class FNVFactory
{
  public:
};

class FNVRes
{
  public:
};

class FNVGuard
{
  public:
    FNVGuard(float f);
    ~FNVGuard();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};


struct FUN_004fb880_cls
{
    int ApplyOrCreateResult(FNVArg* a1, unsigned char a2);
};

// If the argument is not flagged, delegates to Helper; otherwise creates a result via g_pFactory and applies it with a guard, returning the result.
// @fnv 0x004fb880
int FUN_004fb880_cls::ApplyOrCreateResult(FNVArg* a1, unsigned char a2)
{
    std::intptr_t iResult = 0;
    unsigned char flagTmp = 0;
    {
        FNVArg* arg = a1;
        if (!((bool)(reinterpret_cast<::FUN_004fb970_class *>((arg))->GetByteAtOffsetD9())))
        {
            iResult = ((std::intptr_t)(reinterpret_cast<::fnv_0050ee50::CloneObject17 *>(this)->FUN_0050ee50((::TESObjectREFR *)(a1), a2)));
        }
        else
        {
            void* obj = (*reinterpret_cast<::FNVGlobal * *>(&::DAT_011ca284))->m_3c.v5();
            FNVRes* pRes = (FNVRes*)((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::FNVFactory * *>(&::g_modelLoader))))->FUN_00447080((char *)(obj), 0, 1, 0, 0, 0)));
            FNVGuard guard3(1.0f);
            if (pRes != 0)
            {
                iResult = ((std::intptr_t)(reinterpret_cast<::A5D2C0Object *>((pRes))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&guard3)))));
            }
        }
        return iResult;
    }
}

struct BaseDtor_b4673
{
    virtual void unk00();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    ~BaseDtor_b4673();
};

struct MemberDtor_b4673
{
    virtual void unk00();
    int m_04;
    ~MemberDtor_b4673();
};

struct FUN_004fc270 : BaseDtor_b4673, MemberDtor_b4673
{
    virtual void unk30();
    ~FUN_004fc270();
};

// Destructor of FUN_004fc270; the body is empty and the base and member destructors run implicitly.
// @fnv 0x004fc270
FUN_004fc270::~FUN_004fc270()
{}

#include <string.h>
struct FUN_005e78f0_t
{
};
struct EffectSetting_shell : EffectSetting
{
    TESObjectLIGH* GetLight();
};
struct BGSExplosion_shell : BGSExplosion
{
    void FUN_004fb5a0(TESForm* apCopy);
};
// Copies explosion data from apCopy into this, including base fields, a 0x34-byte block, and the associated light.
// @fnv 0x004fb5a0
void BGSExplosion_shell::FUN_004fb5a0(TESForm* apCopy)
{
    BGSExplosion* pcopy = dynamic_cast<BGSExplosion*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
    memcpy(FUN_004fadc0(), pcopy->FUN_004fadc0(), 0x34);
    reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>((((EffectSetting_shell*)this)))->FUN_0057bd60((::fnv_0057bd60::MobileObject *)(::TESObjectLIGH *)(((EffectSetting_shell*)pcopy)->GetLight()));
}

// sub ecx,0x3c; jmp FUN_004facf0  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x3c)
struct PrimaryBase
{
    virtual void FUN_004fb9f0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

struct SecondaryBase
{
    virtual void FUN_004fb9f0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fb9f0
    virtual void FUN_004fb9f0();
};

Derived::Derived()
{}

#include "generated/data/fallout_shared/bgsexplosion.inc"
