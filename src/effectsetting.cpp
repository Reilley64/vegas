// effectsetting.cpp: EffectSetting, EndianSwappableData, EffectSettingList, EffT (41 functions)

#include <new>
#include <cmath>
#include <cstdint>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "effectsetting_decls.h"
#include "fnv/decl/FUN_00482cb0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00472000.h"

// Load and the save writer keep form IDs in the form pointer fields until InitItem resolves them.
template <class T> static unsigned int FormIDInField(T* apField)
{
    return static_cast<unsigned int>(reinterpret_cast<std::uintptr_t>(apField));
}

template <class T> static T* FormIDAsField(std::uintptr_t auiFormID)
{
    return reinterpret_cast<T*>(auiFormID);
}

// Compares the effect name with name case-insensitively and, if they differ, sets the full name to name.
// @fnv 0x00408570
void EffectSetting::UpdateEffectName(const char* name)
{
    int comparison = reinterpret_cast<::B408A80String *>((void *)(void *)&(const ::BSStringT<char> &)((*(::BSStringT<char> *)(reinterpret_cast<::FUN_004046b0_cls *>((void *)this)->AssignFromSub({})))))->FUN_00408a80(name, true);
    if (comparison)
        SetFullName(name);
}

// @fnv 0x00408880
bool EffectSetting::HasEffectID()
{
    return m_iEffectID > 0;
}

// @fnv 0x004088a0
bool EffectSetting::UsesAssociatedActorValue()
{
    return m_iEffectID < 0;
}

// @fnv 0x00408a20
bool EffectSetting::HasNoAssociatedActorValue()
{
    return m_iActorValue < 0;
}

// @fnv 0x004088c0
int EffectSetting::FUN_004088c0()
{
    if (m_iActorValue < 0)
        --m_iActorValue;
    else
        ++m_iActorValue;
    return m_iActorValue;
}
// Sets or clears the given EffectFlag bit in data.iFlags according to value.
// @fnv 0x00407e00
void EffectSetting::SetFlag(EffectFlag flag, bool value)
{
    value ? data.iFlags |= flag : data.iFlags &= ~flag;
}
// @fnv 0x00408970
int EffectSetting::QueueAssociatedItem()
{
    if (m_iActorValue > 0)
        ::FUN_005b5e40();
    else
        --m_iActorValue;
    return m_iActorValue;
}
// @fnv 0x004089c0
int EffectSetting::NormalizeEffectLoadedCount()
{
    m_iActorValue = (int)FUN_00408820((float)m_iActorValue);
    return m_iActorValue;
}

struct FUN_004077c0_shell : public TESForm
{
    bool FUN_004077c0();
};

// @fnv 0x004077c0
bool FUN_004077c0_shell::FUN_004077c0()
{
    return (this->m_uiFormFlags & 0x4000) ? true : false;
}

struct FUN_004077e0_shell : public EffectSetting
{
    void* FUN_004077e0();
};

// @fnv 0x004077e0
void* FUN_004077e0_shell::FUN_004077e0()
{
    return reinterpret_cast<char*>(&this->counterEffects);
}

struct FUN_00407820_shell : public EffectSetting
{
    TESEffectShader* FUN_00407820();
};

// @fnv 0x00407820
TESEffectShader* FUN_00407820_shell::FUN_00407820()
{
    return this->data.m_pEffectShader;
}

struct FUN_004078a0_shell : public EffectSetting
{
    void SetEffectID(int);
};

// @fnv 0x004078a0
void FUN_004078a0_shell::SetEffectID(int aeID)
{
    *(int*)&this->data.m_eEffectTypeItem = aeID;
}

struct FUN_00408680_shell : public EffectSetting
{
    bool HasAllFlags(unsigned int);
};

// @fnv 0x00408680
bool FUN_00408680_shell::HasAllFlags(unsigned int aiFlags)
{
    return (this->data.iFlags & aiFlags) == aiFlags;
}

struct FUN_004086e0_shell : public EffectSetting
{
    int UpdateCounter();
};

// Increments or decrements the counter at offset 0xac depending on its sign, then returns the new value.
// @fnv 0x004086e0
int FUN_004086e0_shell::UpdateCounter()
{
    if (this->m_iEffectID < 0)
    {
        this->m_iEffectID -= 1;
    }
    else
    {
        this->m_iEffectID += 1;
    }
    return this->m_iEffectID;
}

struct FUN_00408790_shell : public EffectSetting
{
    int FUN_00408790();
};

// If the associated-item count at offset 0xac is positive, logs a warning; otherwise decrements it, and returns the count.
// @fnv 0x00408790
int FUN_00408790_shell::FUN_00408790()
{
    if (this->m_iEffectID > 0)
    {
        ::FUN_005b5e40();
    }
    else
    {
        this->m_iEffectID = this->m_iEffectID - 1;
    }
    return this->m_iEffectID;
}

// @fnv 0x00408820
double FUN_00408820(float fValue)
{
    return std::abs(fValue);
}


// @fnv 0x00408860
float FUN_00408860(float afValue)
{
    return (float)::std::fabs((double)afValue);
}


// @fnv 0x00408b20
int __cdecl FUN_00408b20(const char* apString1, const char* apString2)
{
    return ::std::strcmp(apString1, apString2);
}

struct FUN_004ee4b0_shell : public EffectSetting
{
    void FUN_004ee4b0(float);
};

// @fnv 0x004ee4b0
void FUN_004ee4b0_shell::FUN_004ee4b0(float afBaseCost)
{
    this->data.m_fBaseCost = afBaseCost;
}

struct FUN_00591300_shell : public TESFullName
{
    void FUN_00591300();
};

// @fnv 0x00591300
void FUN_00591300_shell::FUN_00591300()
{
    this->m_kName.~BSStringT<char>();
}

struct FUN_00810570_shell : public EffectSetting
{
    void SetAssociatedActorValue(int);
};

// @fnv 0x00810570
void FUN_00810570_shell::SetAssociatedActorValue(int aeAssociatedActorValue)
{
    this->data.m_iAssociatedActorValue = aeAssociatedActorValue;
}

struct FUN_00857230_shell : public EffectSetting
{
    void SetSound(TESSound*);
};

// @fnv 0x00857230
void FUN_00857230_shell::SetSound(TESSound* apValue)
{
    this->data.m_pContactSound = apValue;
}

struct FUN_008ce390_shell : public EffectSetting
{
    TESSound* FUN_008ce390();
};
// Resolves the effect's associated item, light, sounds and shaders by form ID, warns on missing forms, and marks the item initialized.
// @fnv 0x00407e50
void EffectSetting::InitItem()
{
    unsigned int formID;
    if (GetInitialized())
        return;
    if (::IsArchetypeFlagSet((::EffectSetting *)this) && !GetFlag(0x180000))
    {
        unsigned int associatedID = FormIDInField(data.m_pAssociatedForm);
        if (associatedID)
        {
            ::ResolveFormID(&associatedID, GetFile(-1));
            data.m_pAssociatedForm = ::FUN_004839c0(associatedID);
            if (!data.m_pAssociatedForm)
                ::FUN_005b5e40();
        }
    }
    else
        data.m_pAssociatedForm = 0;
    formID = FormIDInField(data.apTargetLight);
    if (formID)
    {
        ::ResolveFormID(&formID, GetFile(-1));
        data.apTargetLight = dynamic_cast<TESObjectLIGH*>(::FUN_004839c0(formID));
        if (!data.apTargetLight)
            ::FUN_005b5e40();
    }
    formID = FormIDInField(data.m_pCastSound);
    if (formID)
    {
        ::ResolveFormID(&formID, GetFile(-1));
        data.m_pCastSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!data.m_pCastSound)
            ::FUN_005b5e40();
    }
    formID = FormIDInField(data.m_pBoltSound);
    if (formID)
    {
        ::ResolveFormID(&formID, GetFile(-1));
        data.m_pBoltSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!data.m_pBoltSound)
            ::FUN_005b5e40();
    }
    formID = FormIDInField(data.m_pContactSound);
    if (formID)
    {
        ::ResolveFormID(&formID, GetFile(-1));
        data.m_pContactSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!data.m_pContactSound)
            ::FUN_005b5e40();
    }
    formID = FormIDInField(data.m_pAreaEffectSound);
    if (formID)
    {
        ::ResolveFormID(&formID, GetFile(-1));
        data.m_pAreaEffectSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!data.m_pAreaEffectSound)
            ::FUN_005b5e40();
    }
    formID = FormIDInField(data.m_pEffectShader);
    if (formID)
    {
        ::ResolveFormID(&formID, GetFile(-1));
        data.m_pEffectShader = dynamic_cast<TESEffectShader*>(::FUN_004839c0(formID));
        if (!data.m_pEffectShader)
            ::FUN_005b5e40();
    }
    formID = FormIDInField(data.m_pEnchantEffectShader);
    if (formID)
    {
        ::ResolveFormID(&formID, GetFile(-1));
        data.m_pEnchantEffectShader = dynamic_cast<TESEffectShader*>(::FUN_004839c0(formID));
        if (!data.m_pEnchantEffectShader)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}

// @fnv 0x008ce390
TESSound* FUN_008ce390_shell::FUN_008ce390()
{
    return this->data.m_pAreaEffectSound;
}

struct S
{
    void FUN_00407230();
    void* DestroyIfFlagged(unsigned int);
};

// Replaces the short value pointed to by p with the result of FUN_00ec3bda applied to it.
// @fnv 0x00407a90
void __cdecl FUN_00407a90(short* psValue)
{
    short* tmp = psValue;
    *tmp = fnv::crt::byteswap_ushort(*tmp);
}

struct FUN_00408550_Cls
{
    char _pad[0x6C];
    short _v;
    int GetShortValue();
};
// @fnv 0x00408550
int FUN_00408550_Cls::GetShortValue()
{
    return _v;
}

struct S3e60
{
    bool FUN_00403e60(unsigned int);
};
struct S86a0
{
    int FUN_004086a0();
};
// @fnv 0x004086a0
int S86a0::FUN_004086a0()
{
    return (((S3e60*)this)->FUN_00403e60(0x2000000) ? 2 : 0) + (((S3e60*)this)->FUN_00403e60(0x4000000) ? 1 : 0);
}

struct Unk00408730
{
    int ClampCounterTowardZero();
};
// Steps the int at offset 0xAC one unit toward zero and returns the resulting value.
// @fnv 0x00408730
int Unk00408730::ClampCounterTowardZero()
{
    if (*(int*)((char*)this + 0xAC) < 0)
        *(int*)((char*)this + 0xAC) = *(int*)((char*)this + 0xAC) + 1;
    else if (*(int*)((char*)this + 0xAC) > 0)
        *(int*)((char*)this + 0xAC) = *(int*)((char*)this + 0xAC) - 1;
    return *(int*)((char*)this + 0xAC);
}

struct FUN_004087e0_Shell
{
    int FUN_004087e0();
};
// Converts the int at offset 0xac to float, passes it to FUN_00408820, stores the result back at 0xac and returns it.
// @fnv 0x004087e0
int FUN_004087e0_Shell::FUN_004087e0()
{
    *(int*)((char*)this + 0xac) = (int)FUN_00408820((float)*(int*)((char*)this + 0xac));
    return *(int*)((char*)this + 0xac);
}

struct Holder00408910
{
    char pad[0xA8];
    int valA8;
    int StepTowardZero();
};
// Moves valA8 one step toward zero (increments if negative, decrements if positive) and returns it.
// @fnv 0x00408910
int Holder00408910::StepTowardZero()
{
    if (valA8 < 0)
        valA8++;
    else if (valA8 > 0)
        valA8--;
    return valA8;
}

struct FUN_00408a00_Struct
{
    int _pad[42];
    int _val;
    bool IsPositive();
};
// @fnv 0x00408a00
bool FUN_00408a00_Struct::IsPositive()
{
    return _val > 0;
}

struct Dummy00501c30
{
    bool FUN_00501c30(const char*);
};
struct S501c60
{
    bool IsNotOne(const char*);
};
struct FUN_00501c90_shell : BSStringT<char>
{
    int CompareString(BSStringT<char> const* arString, bool abIgnoreCase);
};
// Returns the negation of IsNotOne for the given string argument.
// @fnv 0x00501c30
bool Dummy00501c30::FUN_00501c30(const char* pcString)
{
    return !reinterpret_cast<::S501c60 *>(this)->IsNotOne(pcString);
}
// Returns true when CompareString called with the string and 1 returns zero.
// @fnv 0x00501c60
bool S501c60::IsNotOne(const char* a)
{
    return !reinterpret_cast<::FUN_00501c90_shell *>((this))->CompareString((const ::BSStringT<char> *)(a), 1);
}
// @fnv 0x00501c90
int FUN_00501c90_shell::CompareString(BSStringT<char> const* apString, bool abIgnoreCase)
{
    return reinterpret_cast<::B408A80String *>((void *)this)->FUN_00408a80(apString->pString, abIgnoreCase);
}

struct TESChallenge
{
};

struct LowProcess
{
    void SetPackageObjectType(int value);
public:
    int GetPackageObjectType();
};

struct TESGrass
{
    float GetLowestAllowedSlope();
};

struct IMH
{
};

struct TargetDoorController
{
};

class TargetDoorController;
struct MiddleHighProcess
{
    void AddDeferredHideLimb(TargetDoorController* value);
public:
    void SetFaceAnimationData(::TargetDoorController *);
};

struct Date
{
};

struct PlayerQuestData
{
};

struct TES
{
};

struct FUN_00407860_class
{
    void FUN_00407860(float value);
};

struct FUN_00407880_Class
{
    void FUN_00407880(float value);
};

struct PathingRequest
{
    float GetCenterRadius();
    void SetCenterRadius(float value);
};

struct S3c60
{
};

struct FUN_009e3360_Class
{
    void SetMode(unsigned int value);
};

struct TESDataHandler
{
    unsigned int GetNextID();
};

struct DH : public TESDataHandler
{
};


struct FUN_005e78f0_t
{
};

struct EffectSettingAux
{
};

struct TESEffectShaderAux
{
};

struct FUN_00408600_class : public EffectSetting
{
    void CopyValuesFromList(void* value);
};


struct FUN_00407600_class : public EffectSetting
{
    void CopyFromEffectSetting(TESForm* apCopy);
};

// Copies fields from an EffectSetting into this object, assigning a new ref ID when this form is non-temporary and has no form ID.
// @fnv 0x00407600
void FUN_00407600_class::CopyFromEffectSetting(TESForm* apCopy)
{
    EffectSetting* psetting = dynamic_cast<EffectSetting*>(apCopy);
    if (!psetting)
        return;

    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005e78f0_t*>(this)))->FUN_004851b0(apCopy);
    reinterpret_cast<LowProcess*>(this)->SetPackageObjectType(
        reinterpret_cast<::LowProcess *>((reinterpret_cast<TESChallenge*>(psetting)))->GetPackageObjectType());
    reinterpret_cast<::FUN_004ee4b0_shell *>((reinterpret_cast<EffectSettingAux*>(this)))->FUN_004ee4b0(reinterpret_cast<TESGrass*>(psetting)->GetLowestAllowedSlope());
    reinterpret_cast<::FUN_00810570_shell *>((reinterpret_cast<EffectSettingAux*>(this)))->SetAssociatedActorValue(psetting->data.m_iAssociatedActorValue);
    reinterpret_cast<MiddleHighProcess*>(this)->AddDeferredHideLimb(
        reinterpret_cast<TargetDoorController*>(((int)(::FUN_0070ec90((char *)(reinterpret_cast<EffectSettingAux*>(psetting)))))));
    reinterpret_cast<::MiddleHighProcess *>((reinterpret_cast<PlayerQuestData*>(this)))->SetFaceAnimationData(
        (::TargetDoorController *)(::Date *)(reinterpret_cast<Date*>(((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<TES*>(psetting)))->GetBaseTexture())))));
    reinterpret_cast<FUN_00407860_class*>(this)->FUN_00407860(GetField90Float(reinterpret_cast<char*>(psetting)));
    reinterpret_cast<FUN_00407880_Class*>(this)->FUN_00407880(
        reinterpret_cast<::FUN_00644930_shell *>((reinterpret_cast<TESEffectShaderAux*>(psetting)))->FUN_00644930());
    reinterpret_cast<PathingRequest*>(this)->SetCenterRadius(
        reinterpret_cast<PathingRequest*>(psetting)->GetCenterRadius());
    reinterpret_cast<::FUN_004078a0_shell *>((reinterpret_cast<EffectSettingAux*>(this)))->SetEffectID(reinterpret_cast<::EffectSetting *>((reinterpret_cast<S3c60*>(psetting)))->GetArchetype());
    data.m_pAssociatedForm = psetting->data.m_pAssociatedForm;
    reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>(this)->FUN_0057bd60((::fnv_0057bd60::MobileObject *)(::TESObjectLIGH *)(((::TESObjectLIGH *)(reinterpret_cast<::FUN_004fd380_shell *>((psetting))->FUN_004fd380()))));
    reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound((::TESSound *)(::TESEffectShader *)(reinterpret_cast<::FUN_00407820_shell *>((psetting))->FUN_00407820()));
    data.m_pEnchantEffectShader = psetting->data.m_pEnchantEffectShader;
    reinterpret_cast<::FUN_008ac890_shell *>(this)->SetWaterForm((::TESWaterForm *)(::TESSound *)(psetting->GetCastSound()));
    SetBoltSound(((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(psetting)))));
    reinterpret_cast<::FUN_00857230_shell *>(this)->SetSound(psetting->GetHitSound());
    data.m_pAreaEffectSound = psetting->data.m_pAreaEffectSound;
    reinterpret_cast<FUN_00408600_class*>(this)->CopyValuesFromList(
        reinterpret_cast<::FUN_004077e0_shell *>((reinterpret_cast<TESDataHandler*>(psetting)))->FUN_004077e0());

    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0() && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)this)->FUN_0084e3a0())) == 0)
        SetRefID(g_dataHandler->GetNextID(), true);
}


struct EndianSwappableData
{
    void SwapEndianFields();
};
// Loads an EffectSetting record from a TESFile, dispatching on chunk IDs to read editor ID, name, description, texture, model, data and counter effects.
// @fnv 0x00407ac0
bool EffectSetting::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660() != 16)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int chunk;
    while ((chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:  // FULL
            ::ReadFullName(this, file);
            break;
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x54444f4d:  // MODT
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144:  // DATA
            memset(&data, 0, sizeof(data));
            data.fSpeed = 1.0f;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::EndianSwappableData *>(&(data))->SwapEndianFields();
            SetFlag(PLAYER_KNOWS, false);
            break;
        case 0x45435345:  // ESCE
        {
            struct CounterEffectReference
            {
                unsigned int formID;
                EffectSetting* effect;
            } counterRef;
            file->GetChunkData(&counterRef.formID);
            if (file->IsEndianConversionRequired())
                ::FUN_00401080((int *)(unsigned int *)(&counterRef.formID));
            ::ResolveFormID((unsigned int *)&(counterRef.formID), file);
            counterRef.effect = dynamic_cast<EffectSetting*>(::FUN_004839c0(counterRef.formID));
            if (counterRef.effect)
            {
                counterEffects.AddHead(counterRef.effect);
                data.m_sCounterEffectCount = counterEffects.ItemsInList();
            }
            else
                ::FUN_005b5e40();
        }
        break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Byte-swaps the 4-byte fields at offsets 0x00-0x40 and the 2-byte field at 0x14 of this object via BSEndian.
// @fnv 0x004078c0
void EndianSwappableData::SwapEndianFields()
{
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x00)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x04)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x44)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x08)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x0C)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x10)));
    ::FUN_00407a90((short *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x14)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x18)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x1C)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x20)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x24)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x28)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x2C)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x30)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x34)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x38)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x3C)));
    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)((unsigned char*)this + 0x40)));
}

struct EffectSettingList : public BSSimpleList<EffectSetting*>
{
    ~EffectSettingList();
};

class FormBase
{
  public:
    virtual ~FormBase();
    virtual void ClearData();
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
};

class FUN_00407230 : public FormBase, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
  public:
    bool(__cdecl* m_pEffectSettingCallback)(EffectSetting*, void*);
    void* m_pPredicateData;
    EffectSetting__EffectSettingData data;
    EffectSettingList counterEffects;
    int m_iActorValue;
    int m_iEffectID;
    ~FUN_00407230();
};
// @fnv 0x00407200
void* S::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00407230 *>(this)->FUN_00407230::~FUN_00407230();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00407230
FUN_00407230::~FUN_00407230()
{
    ClearData();
}

EffectSettingList::~EffectSettingList()
{}

struct SubListA0
{
    void AddItem(EffectSetting** item);
};

// Clears the counter effects, then copies each non-null effect from the source list into them and counts them.
// @fnv 0x00408600
void FUN_00408600_class::CopyValuesFromList(void* pSourceList)
{
    EffectSetting* val;
    reinterpret_cast<::FileMatchList *>(&counterEffects)->RemoveAll();
    data.m_sCounterEffectCount = 0;
    for (BSSimpleList<EffectSetting*>* cur = (BSSimpleList<EffectSetting*>*)pSourceList; cur != 0 && (val = *((EffectSetting **)(new ((void *)(cur)) ::Vec3()))) != 0;
         cur = ((BSSimpleList<EffectSetting*> *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        reinterpret_cast<SubListA0*>(&counterEffects)->AddItem(&val);
        data.m_sCounterEffectCount++;
    }
}

struct ListT
{
};
struct EffT
{
    char pad00[0xa0];
    ListT m_a0;
    bool IsDifferentFrom(void* param);
};

// @fnv 0x004082f0
bool EffT::IsDifferentFrom(void* pObject)
{
    EffT* other = (EffT*)dynamic_cast<::EffectSetting *>(reinterpret_cast<::TESForm *>(pObject));
    if (other == 0)
        return 1;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(pObject)))
        return 1;
    if (reinterpret_cast<::LowProcess *>(this)->GetPackageObjectType() != reinterpret_cast<::LowProcess *>((other))->GetPackageObjectType() || !(((double)(reinterpret_cast<::TESGrass *>(this)->GetLowestAllowedSlope())) == ((double)(reinterpret_cast<::TESGrass *>((other))->GetLowestAllowedSlope()))) ||
        (reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()) != (reinterpret_cast<::InterfaceManager *>((other))->FUN_00586150()) || (reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>(this)->FUN_005f5f80()) != (reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((other))->FUN_005f5f80()) ||
        (::FUN_0070ec90((char *)this)) != (::FUN_0070ec90((char *)(other))) || (reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()) != (reinterpret_cast<::BSShaderNoLightingProperty *>((other))->GetBaseTexture()) ||
        (reinterpret_cast<::FUN_004fd380_shell *>(this)->FUN_004fd380()) != (reinterpret_cast<::FUN_004fd380_shell *>((other))->FUN_004fd380()) || (reinterpret_cast<::FUN_00407820_shell *>(this)->FUN_00407820()) != (reinterpret_cast<::FUN_00407820_shell *>((other))->FUN_00407820()) ||
        ((int)(reinterpret_cast<::TESPackage *>(this)->GetRefCount())) != ((int)(reinterpret_cast<::TESPackage *>((other))->GetRefCount())) || !(((double)(reinterpret_cast<::PathingRequest *>(this)->GetCenterRadius())) == ((double)(reinterpret_cast<::PathingRequest *>((other))->GetCenterRadius()))) ||
        (reinterpret_cast<::EffectSetting *>(this)->GetCastSound()) != (reinterpret_cast<::EffectSetting *>((other))->GetCastSound()) || (::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)this)) != (::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(other))) ||
        (reinterpret_cast<::EffectSetting *>(this)->GetHitSound()) != (reinterpret_cast<::EffectSetting *>((other))->GetHitSound()) || (reinterpret_cast<::FUN_008ce390_shell *>(this)->FUN_008ce390()) != (reinterpret_cast<::FUN_008ce390_shell *>((other))->FUN_008ce390()) ||
        reinterpret_cast<::FUN_00408550_Cls *>(this)->GetShortValue() != reinterpret_cast<::FUN_00408550_Cls *>((other))->GetShortValue() || reinterpret_cast<::EffectSetting *>(this)->GetArchetype() != reinterpret_cast<::EffectSetting *>((other))->GetArchetype())
        return 1;
    ListT* pa4 = &m_a0;
    ListT* pbX = &other->m_a0;
    while (pa4 && pbX)
    {
        EffectSetting* av = *((EffectSetting **)(new ((void *)(pa4)) ::Vec3()));
        EffectSetting* bv5 = *((EffectSetting **)(new ((void *)(pbX)) ::Vec3()));
        if (av != bv5)
            return 1;
        pa4 = ((::ListT *)(reinterpret_cast<::Callees *>((pa4))->FUN_00726070()));
        pbX = ((::ListT *)(reinterpret_cast<::Callees *>((pbX))->FUN_00726070()));
    }
    return 0;
}

enum
{
    CHUNK_ICON = 0x4E4F4349,
    CHUNK_MODL = 0x4C444F4D,
    CHUNK_MODT = 0x54444F4D,
    CHUNK_DATA = 0x41544144,
    CHUNK_ESCE = 0x45435345
};

// @fnv 0x00407300
void EffectSetting::FUN_00407300()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(this)->FUN_00487010();
    reinterpret_cast<::FUN_00482cb0_shell *>(this)->FUN_00482cb0();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(this)->FUN_0048e370(CHUNK_ICON);
    reinterpret_cast<::FUN_004891d0_cls *>(this)->WriteToBuffer((char *)(CHUNK_MODL), (void *)(CHUNK_MODT));

    TESSound* pkCastSound = data.m_pCastSound;
    data.m_pCastSound = FormIDAsField<TESSound>(data.m_pCastSound ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.m_pCastSound)->FUN_0084e3a0()) : 0);
    TESSound* pkBoltSound = data.m_pBoltSound;
    data.m_pBoltSound = FormIDAsField<TESSound>(data.m_pBoltSound ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.m_pBoltSound)->FUN_0084e3a0()) : 0);
    TESSound* m_pContactSound = data.m_pContactSound;
    data.m_pContactSound = FormIDAsField<TESSound>(data.m_pContactSound ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.m_pContactSound)->FUN_0084e3a0()) : 0);
    TESSound* m_pAreaEffectSound = data.m_pAreaEffectSound;
    data.m_pAreaEffectSound = FormIDAsField<TESSound>(data.m_pAreaEffectSound ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.m_pAreaEffectSound)->FUN_0084e3a0()) : 0);
    TESEffectShader* pkEffectShaderSave = data.m_pEffectShader;
    data.m_pEffectShader = FormIDAsField<TESEffectShader>(data.m_pEffectShader ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.m_pEffectShader)->FUN_0084e3a0()) : 0);
    TESEffectShader* pkEnchantEffect = data.m_pEnchantEffectShader;
    data.m_pEnchantEffectShader = FormIDAsField<TESEffectShader>(data.m_pEnchantEffectShader ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.m_pEnchantEffectShader)->FUN_0084e3a0()) : 0);
    TESObjectLIGH* pkLight = data.apTargetLight;
    data.apTargetLight = FormIDAsField<TESObjectLIGH>(data.apTargetLight ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.apTargetLight)->FUN_0084e3a0()) : 0);
    TESForm* savedPAssociatedItemOriginal = data.m_pAssociatedForm;
    data.m_pAssociatedForm = FormIDAsField<TESForm>(data.m_pAssociatedForm ? static_cast<unsigned int>(reinterpret_cast<::FUN_0084e3a0_Class *>(data.m_pAssociatedForm)->FUN_0084e3a0()) : 0);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::EndianSwappableData *>(&(data))->SwapEndianFields();
    ::AppendChunk(CHUNK_DATA, &data, sizeof(data));
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::EndianSwappableData *>(&(data))->SwapEndianFields();

    data.m_pCastSound = pkCastSound;
    data.m_pBoltSound = pkBoltSound;
    data.m_pContactSound = m_pContactSound;
    data.m_pAreaEffectSound = m_pAreaEffectSound;
    data.m_pEffectShader = pkEffectShaderSave;
    data.m_pEnchantEffectShader = pkEnchantEffect;
    data.apTargetLight = pkLight;
    data.m_pAssociatedForm = savedPAssociatedItemOriginal;

    EffectSetting* savedPkEffect;
    for (BSSimpleList<EffectSetting*>* pkIter = &counterEffects; pkIter && (savedPkEffect = (*((::EffectSetting **)(new ((void *)(pkIter)) ::Vec3())))) != 0;
         pkIter = ((::BSSimpleList< ::EffectSetting *> *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070())))
        ::FUN_00485910(CHUNK_ESCE, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(savedPkEffect))->FUN_0084e3a0())));

    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct BEB3890Body
{
    int unk00;
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
    float m_fBoundRadius;
};

static const float NI_INFINITY = 3.402823466e+38f;

class BEB3890Base
{
  public:
    BEB3890Base(float fA, float fB, float fC, int iD);
    virtual ~BEB3890Base();

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
};

class FUN_00eb3890_cls : public BEB3890Base
{
  public:
    FUN_00eb3890_cls(BEB3890Body* pkBodyA, BEB3890Body* pkBodyB, float fA, float fB, float fC, int iD);
    virtual ~FUN_00eb3890_cls();

    BEB3890Body* m_pkBodyA;
    BEB3890Body* m_pkBodyB;
    float m_fInvRadiusSq;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

// @fnv 0x00eb3890
FUN_00eb3890_cls::FUN_00eb3890_cls(BEB3890Body* pkBodyA, BEB3890Body* pkBodyB, float fA, float fB, float fC, int iD)
    : BEB3890Base(fA, fB, fC, iD), m_pkBodyA(pkBodyA), m_pkBodyB(pkBodyB)
{
    m_fInvRadiusSq = 1.0f / (pkBodyB->m_fBoundRadius * pkBodyB->m_fBoundRadius);
    m_fVectorY = NI_INFINITY;
    m_fVectorZ = NI_INFINITY;
    m_fScalarPart = NI_INFINITY;
}
