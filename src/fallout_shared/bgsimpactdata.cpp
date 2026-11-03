// fallout_shared/bgsimpactdata.cpp: BGSImpactData, SelfX, OpaqueData (14 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00589f50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0056a000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011cd000.h"
#include "bgsimpactdata.h"
#include <string.h>
#include <malloc.h>

static const char s_textureSetWarning[] = "MASTERFILE: Unable to find texture set (%08X) on impact data %s (%08X).";
static const char s_soundWarning[] = "MASTERFILE: Unable to find sound (%08X) on impact data %s (%08X).";

// @fnv 0x0058db40
BGSImpactData::BGSImpactData()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_IPCT_ID)));
    ResetFormData();
}

// @fnv 0x0058dc90
void BGSImpactData::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
    Data.m_fEffectDuration = 0.25f;
    Data.m_eOrientation = BGSImpactData__ORIENTATION_ORIENT_PROJ_REFLECT;
    Data.m_fAngleThreshold = 15.0f;
    Data.m_fPlacementRadius = 16.0f;
    m_pDecalTextureSet = 0;
    m_pPrimaryImpactSound = 0;
    m_pSecondaryImpactSound = 0;
    Data.m_eSoundLevel = SOUND_LEVEL_SOUND_LEVEL_NORMAL;
}

struct FUN_0058dbe0_class
{
    void FUN_0058dc10();
    void* Free(unsigned int flags);
};
struct FUN_00483630_Base : public TESForm
{
    virtual ~FUN_00483630_Base();
};
struct FUN_00483710_Member : public DecalData
{
    ~FUN_00483710_Member();
};
struct FUN_0058dc10 : public FUN_00483630_Base, public TESModel
{
    BGSImpactData__IMPACT_DATA_DATA Data;
    BGSTextureSet* m_pDecalTextureSet;
    TESSound* m_pPrimaryImpactSound;
    TESSound* m_pSecondaryImpactSound;
    FUN_00483710_Member ImpactDecalInfo;
    virtual ~FUN_0058dc10();
};
// Calls FUN_0058dc10, then deletes this if the low bit of flags is set, and returns this.
// @fnv 0x0058dbe0
void* FUN_0058dbe0_class::Free(unsigned int flags)
{
    reinterpret_cast<::FUN_0058dc10 *>(this)->FUN_0058dc10::~FUN_0058dc10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// The destructor body is empty; the class inherits TESForm and TESModel and contains impact data and decal-related fields.
// @fnv 0x0058dc10
FUN_0058dc10::~FUN_0058dc10()
{}

extern const char DAT_011862fc[];


struct FUN_005054b0_shell
{
};

struct FUN_005932b0_decal
{
    void FUN_005932b0(FUN_005932b0_decal* source);
};

struct FUN_0058dd10_shell : public TESForm
{
    void* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float unk30;
    unsigned char unk34;
    unsigned char unk35;
    unsigned char unk36;
    unsigned char unk37;
    float unk38;
    float unk3C;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char unk42;
    unsigned char unk43;
    unsigned char unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    void* unk48;
    void* unk4C;
    void* unk50;
    FUN_005932b0_decal unk54;

    void FUN_0058dd10(int arg);
};

// @fnv 0x0058dd10
void FUN_0058dd10_shell::FUN_0058dd10(int arg)
{
    FUN_0058dd10_shell* source =
        reinterpret_cast<FUN_0058dd10_shell*>(dynamic_cast<::BGSImpactData *>(reinterpret_cast<::TESForm *>(arg)));

    if (source == 0)
        return;

    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005054b0_shell*>(this)))->FUN_004851b0(source);
    ::__memcpy(reinterpret_cast<char*>(&this->unk30), reinterpret_cast<char*>(&source->unk30), 0x18);
    reinterpret_cast<::DecalData *>((&this->unk54))->Copy((::DecalData *)(::FUN_005932b0_decal *)(&source->unk54));
    unk48 = source->unk48;
    unk4C = source->unk4C;
    unk50 = source->unk50;
}

struct FUN_005e79a0_t
{
};
struct FUN_005932e0_shell
{
    bool Compare(void*);
};
struct FUN_0058de80_shell
{
};
struct FUN_0058dda0_shell : public BGSImpactData
{
    bool IsDifferentFrom(TESForm* apCompare);
};

struct FUN_0058de80_class
{
    bool IsFlagSet();
};
// Returns true if apCompare is not BGSImpactData or a checked comparison reports a difference.
// @fnv 0x0058dda0
bool FUN_0058dda0_shell::IsDifferentFrom(TESForm* apCompare)
{
    BGSImpactData* pOther = dynamic_cast<BGSImpactData*>(apCompare);
    if (!pOther)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pOther))
        return true;
    if (memcmp((char*)&this->Data, (char*)&pOther->Data, 0x18) != 0)
        return true;
    if (!reinterpret_cast<::FUN_0058de80_class *>((((FUN_0058de80_shell*)this)))->IsFlagSet() &&
        ((FUN_005932e0_shell*)&this->ImpactDecalInfo.Data.m_fDecalMinWidth)->Compare((char*)&pOther->ImpactDecalInfo))
        return true;
    if (m_pDecalTextureSet != pOther->m_pDecalTextureSet)
        return true;
    if (m_pPrimaryImpactSound != pOther->m_pPrimaryImpactSound)
        return true;
    if (m_pSecondaryImpactSound != pOther->m_pSecondaryImpactSound)
        return true;
    return false;
}

// @fnv 0x0058de80
bool FUN_0058de80_class::IsFlagSet()
{
    return (reinterpret_cast<unsigned char*>(this)[0x44] & 1) ? true : false;
}

struct TagX
{
};
class SelfX
{
  public:
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    void FUN_0058e250();
};
// Calls FUN_00401080 with TagX() for each listed member.
// @fnv 0x0058e250
void SelfX::FUN_0058e250()
{
    ::FUN_00401080((int *)(void *)(&m00));
    ::FUN_00401080((int *)(void *)(&m14));
    ::FUN_00401080((int *)(void *)(&m1c));
    ::FUN_00401080((int *)(void *)(&m20));
    ::FUN_00401080((int *)(void *)(&m04));
    ::FUN_00401080((int *)(void *)(&m08));
    ::FUN_00401080((int *)(void *)(&m0c));
    ::FUN_00401080((int *)(void *)(&m18));
    ::FUN_00401080((int *)(void *)(&m24));
    ::FUN_00401080((int *)(void *)(&m28));
    ::FUN_00401080((int *)(void *)(&m2c));
    ::FUN_00401080((int *)(void *)(&m30));
    ::FUN_00401080((int *)(void *)(&m34));
}

template <int N> struct EndianSizeTag
{
};

struct OpaqueData
{
    void SwapEndian();
};
// Loads a BGSImpactData record from a TESFile, reading the DATA chunk (old or new layout), editor ID, OBND, model, decal texture set and sound references.
// @fnv 0x0058dea0
bool BGSImpactData::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((static_cast<TESFileFormInt*>(file)))->FUN_00472660() != ENUM_FORM_ID_IPCT_ID)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    if (file->IsEndianConversionRequired())
        reinterpret_cast<::OpaqueData *>(&(Data))->SwapEndian();
    int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C444F4D:  // MODL
        case 0x54444F4D:  // MODT
            TESModel::LoadModelData(static_cast<TESModel*>(this), file);
            break;
        case 0x41544144:  // DATA
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(file)))->FUN_00403570() < 10)
            {
                BGSImpactData__OLD_IMPACT_DATA_DATA oldData;
                memset(&oldData, 0, sizeof(oldData));
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &oldData, sizeof(oldData));
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::SelfX *>(&(oldData))->FUN_0058e250();
                memset(&Data, 0, sizeof(Data));
                Data.m_fEffectDuration = oldData.m_fEffectDuration;
                Data.m_eOrientation = oldData.m_eOrientation;
                Data.m_fAngleThreshold = oldData.m_fAngleThreshold;
                Data.m_fPlacementRadius = oldData.m_fPlacementRadius;
                Data.m_eSoundLevel = oldData.m_eSoundLevel;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_fDecalMinWidth = oldData.m_fDecalMinWidth;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_fDecalMaxWidth = oldData.m_fDecalMaxWidth;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_fDecalMinHeight = oldData.m_fDecalMinHeight;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_fDecalMaxHeight = oldData.m_fDecalMaxHeight;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_fProjectionDepth = oldData.m_fProjectionDepth;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_fShininess = oldData.m_fShininess;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_fParallaxScale = oldData.m_fParallaxScale;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->m_ucParallaxPasses = oldData.m_ucParallaxPasses;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->cFlags = oldData.cFlags;
                ((::ImpactDecalData *)(new ((void *)&(ImpactDecalInfo)) ::Vec3()))->iColor = oldData.iColor;
            }
            else
            {
                memset(&Data, 0, sizeof(Data));
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &Data, sizeof(Data));
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::OpaqueData *>(&(Data))->SwapEndian();
            }
            break;
        case 0x54444F44:  // DODT
            ImpactDecalInfo.Load(file);
            break;
        case 0x4D414E44:  // DNAM
        {
            unsigned int textureSetID = 0;
            file->GetChunkData(&textureSetID);
            reinterpret_cast<::ValueModifierEffect *>(this)->SetActorValue((::ActorValue::Index)(reinterpret_cast<BGSTextureSet*>(textureSetID)));
            break;
        }
        case 0x4D414E53:  // SNAM
        {
            unsigned int sound1ID = 0;
            file->GetChunkData(&sound1ID);
            reinterpret_cast<::FUN_00589f50_shell *>(this)->SetSound(reinterpret_cast<TESSound*>(sound1ID));
            break;
        }
        case 0x314D414E:  // NAM1
        {
            unsigned int sound2ID = 0;
            file->GetChunkData(&sound2ID);
            SetSound2(reinterpret_cast<TESSound*>(sound2ID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
// Calls BSEndian on this object at byte offsets 0, 4, 8, 12, and 16.
// @fnv 0x0058e3a0
void OpaqueData::SwapEndian()
{
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 4));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 8));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 12));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 16));
}

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct FUN_004891d0_obj
{
};

struct FUN_00485e00_shell
{
};

struct FUN_00593320_shell
{
    void FUN_00593320(void*);
};

struct FUN_0058e450_shell
{
    unsigned char padding[0x48];
    TESForm* m_pDecalTextureSet;
    TESForm* m_pPrimaryImpactSound;
    TESForm* m_pSecondaryImpactSound;

    void FUN_0058e450();
};


// Calls base helpers, processes bytes at offset 0x30, and passes non-null form IDs to _FUN_00485910.
// @fnv 0x0058e450
void FUN_0058e450_shell::FUN_0058e450()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    reinterpret_cast<::FUN_004891d0_cls *>((reinterpret_cast<FUN_004891d0_obj*>(reinterpret_cast<unsigned char*>(this) + 0x18)))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::OpaqueData *>((reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x30)))->SwapEndian();
    }

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20(
        (const void *)(reinterpret_cast<int>(reinterpret_cast<unsigned char*>(this) + 0x30)), 0x18);

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::OpaqueData *>((reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x30)))->SwapEndian();
    }

    if (!reinterpret_cast<::FUN_0058de80_class *>((reinterpret_cast<FUN_0058de80_shell*>(this)))->IsFlagSet())
    {
        reinterpret_cast<FUN_00593320_shell*>(reinterpret_cast<unsigned char*>(this) + 0x54)
            ->FUN_00593320(reinterpret_cast<void*>(0x54444f44));
    }

    {
        unsigned int itempint;

        if (m_pDecalTextureSet)
        {
            itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pDecalTextureSet))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e44, itempint);
        }
    }

    {
        unsigned int itempint;

        if (m_pPrimaryImpactSound)
        {
            itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pPrimaryImpactSound))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e53, itempint);
        }
    }

    {
        unsigned int itempint;

        if (m_pSecondaryImpactSound)
        {
            itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pSecondaryImpactSound))->FUN_0084e3a0()));
            ::FUN_00485910(0x314d414e, itempint);
        }
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct TESQuest;
struct TopicInfo_Ext
{
    TESQuest* GetParentQuest();
    void FUN_005932b0(DecalData*);
};
void* FUN_0056a8c0();
struct DecalDataCopy
{
};

struct FUN_0058e730Class
{
    void CopyDecalData();
};
// Resolves the texture set and two sound form IDs, warns on failed lookups, then copies decal data from the texture set and marks the form initialized.
// @fnv 0x0058e560
void BGSImpactData::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    unsigned int formID = reinterpret_cast<unsigned int>(m_pDecalTextureSet);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pDecalTextureSet = dynamic_cast<BGSTextureSet*>(::FUN_004839c0(formID));
        if (m_pDecalTextureSet)
        {
            // Texture set resolved.
        }
        else
            ::FUN_005b5e40();
    }
    formID = reinterpret_cast<unsigned int>(m_pPrimaryImpactSound);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pPrimaryImpactSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (m_pPrimaryImpactSound)
        {
            // Sound resolved.
        }
        else
            ::FUN_005b5e40();
    }
    formID = reinterpret_cast<unsigned int>(m_pSecondaryImpactSound);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pSecondaryImpactSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (m_pSecondaryImpactSound)
        {
            // Sound resolved.
        }
        else
            ::FUN_005b5e40();
    }
    reinterpret_cast<::FUN_0058e730Class *>(this)->CopyDecalData();
    SetInitializationState(true);
}

// When the flag is set, copies data into offset 0x54 from a source selected by whether GetParentQuest() returns non-null.
// @fnv 0x0058e730
void FUN_0058e730Class::CopyDecalData()
{
    if (reinterpret_cast<::FUN_0058de80_class *>((reinterpret_cast<TopicInfo_Ext*>(this)))->IsFlagSet())
    {
        if (reinterpret_cast<TopicInfo_Ext*>(this)->GetParentQuest())
        {
            reinterpret_cast<::DecalData *>((reinterpret_cast<DecalDataCopy*>(reinterpret_cast<char*>(this) + 0x54)))->Copy(reinterpret_cast<DecalData*>(
                    FUN_0056a880(reinterpret_cast<char*>(reinterpret_cast<TopicInfo_Ext*>(this)->GetParentQuest()))));
        }
        else
        {
            reinterpret_cast<::DecalData *>((reinterpret_cast<DecalDataCopy*>(reinterpret_cast<char*>(this) + 0x54)))->Copy(reinterpret_cast<DecalData*>(FUN_0056a8c0()));
        }
    }
}

struct GlobalObject_0045cfe0
{
};

struct FUN_0058e790_S
{
    int GetGlobalValue();
};

// Returns the int value of one of three global objects selected by the member at offset 0x40.
// @fnv 0x0058e790
int FUN_0058e790_S::GetGlobalValue()
{
    int result = 0;
    switch (*(int*)((char*)this + 0x40))
    {
    case 2:
        result = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cd3b4))))));
        break;
    case 1:
        result = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cd538))))));
        break;
    case 0:
        result = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cdde0))))));
        break;
    }
    return result;
}
