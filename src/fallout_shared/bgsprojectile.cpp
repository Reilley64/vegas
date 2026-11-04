// fallout_shared/bgsprojectile.cpp: BGSProjectile, BGSProjectileFloatNode, ProjShell, ProjectileSave (22 functions)

#include <cstring>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00402d50.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_004078a0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_0049ee60_shell.h"
#include "fnv/decl/FUN_004b0ba0_cls.h"
#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_004fd3a0_shell.h"
#include "fnv/decl/FUN_004fd4f0_Class.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_009d9f00_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/ModelForm0050fbf0.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0050ee50__CloneObject17.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b0000.h"
#include "fnv/symbols_004ea000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "bgsprojectile_decls.h"
#include "fnv/symbols_00472000.h"

// @fnv 0x004fd090
void BGSProjectile::ClearData()
{
    reinterpret_cast<::FUN_00402d50 *>(&(m_kProjectileModel))->FUN_00402d50::~FUN_00402d50();
}

// If newValue is nonzero, sets value, or copies this node into a new node inserted after it and sets value.
// @fnv 0x004ff980
void BGSProjectileFloatNode::AddHead(const float& newValue)
{
    if (newValue == 0.0)
        return;
    {
        if (value != 0.0)
        {
            BGSProjectileFloatNode* inserted = new BGSProjectileFloatNode(*this);
            inserted->next = next;
            next = inserted;
            value = newValue;
        }
        else
        {
            value = newValue;
        }
    }
}
// @fnv 0x004fce60
BGSProjectile::BGSProjectile()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_PROJ_ID)));
    ResetFormData();
}
// @fnv 0x004fd0c0
void BGSProjectile::InitItem()
{
    if (GetInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    unsigned int formID;
    formID = (unsigned int)(std::uintptr_t)((::TESObjectLIGH *)(reinterpret_cast<::FUN_004fd380_shell *>((reinterpret_cast<EffectSetting*>(this)))->FUN_004fd380()));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>((reinterpret_cast<EffectSetting*>(this)))->FUN_0057bd60(
            (::fnv_0057bd60::MobileObject *)(::TESObjectLIGH *)(dynamic_cast<TESObjectLIGH*>(::FUN_004839c0(formID))));
    }
    formID = (unsigned int)(std::uintptr_t)((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((reinterpret_cast<TESChallenge*>(this)))->FUN_004fd3a0()));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<TESObjectACTI*>(this)->SetLoopingSound(
            reinterpret_cast<TESSound*>(dynamic_cast<TESObjectLIGH*>(::FUN_004839c0(formID))));
    }
    formID = (unsigned int)(std::uintptr_t)((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(reinterpret_cast<EffectSetting*>(this)))));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(
            reinterpret_cast<TESSound*>(dynamic_cast<BGSExplosion*>(::FUN_004839c0(formID))));
    }
    formID = (unsigned int)(std::uintptr_t)reinterpret_cast<EffectSetting*>(this)->GetHitSound();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<::FUN_00857230_shell *>((reinterpret_cast<EffectSetting*>(this)))->SetSound(
            dynamic_cast<TESSound*>(::FUN_004839c0(formID)));
    }
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetArchetype();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<::FUN_004078a0_shell *>((reinterpret_cast<EffectSetting*>(this)))->SetEffectID(
            (std::intptr_t)dynamic_cast<TESSound*>(::FUN_004839c0(formID)));
    }
    formID = (unsigned int)(std::uintptr_t)reinterpret_cast<InterfaceManager*>(this)->FUN_00586150();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<::FUN_00810570_shell *>((reinterpret_cast<EffectSetting*>(this)))->SetAssociatedActorValue(
            (std::intptr_t)dynamic_cast<TESSound*>(::FUN_004839c0(formID)));
    }
    formID = (unsigned int)(std::uintptr_t)((::Tile *)(reinterpret_cast<::MagicProjectile *>((reinterpret_cast<InterfaceManager*>(this)))->FUN_004fd400()));
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<InterfaceManager*>(this)->FUN_00500a20(
            reinterpret_cast<Tile*>(dynamic_cast<TESObjectWEAP*>(::FUN_004839c0(formID))));
    }
    if (!FUN_004fd360())
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(0);
    SetInitializationState(true);
}
// @fnv 0x004fcc00
ProjectileProperties* FUN_004fcc00(ProjectileProperties* pThis)
{
    pThis->InitializeDefaults();
    return pThis;
}

struct FUN_004fcc20_shell : public ProjectileProperties
{
    void InitializeDefaults();
};
// @fnv 0x004fd050
void BGSProjectile::ResetFormData()
{
    reinterpret_cast<::FUN_004fcc20_shell *>((reinterpret_cast<ProjectileProperties*>(((::BSSimpleList< ::TESRace *> *)(::FUN_004ea950((std::intptr_t)(reinterpret_cast<TESDataHandler*>(this))))))))->InitializeDefaults();
    reinterpret_cast<TESModelVTable*>(&m_kProjectileModel)->Slot0();
    m_eSoundLevel = 1;
}


// @fnv 0x004fcc20
void FUN_004fcc20_shell::InitializeDefaults()
{
    *(int*)((char*)this + 0x00) = 0x10000;
    this->m_fGravity = 0.0f;
    this->m_fSpeed = 1000.0f;
    this->m_fRange = DAT_01022958;
    this->m_fTracerChance = 0.0f;
    this->m_fExplosionProximity = 0.0f;
    this->m_fExplosionTimer = 0.0f;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x28) = 0;
    this->m_fMuzzleFlashDuration = 0.0f;
    this->m_fFadeDuration = 0.5f;
    this->m_fImpactForce = 0.0f;
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x40) = 0;
    this->m_fRotationX = 0.0f;
    this->m_fRotationY = 0.0f;
    this->m_fRotationZ = 0.0f;
    this->m_fBouncyMult = 1.0f;
}

struct BGSProjectile_GetFlag_Helper : public BGSProjectile
{
};

struct FUN_004fd420_shell : public BGSProjectile
{
    bool FUN_004fd420(int);
};
// @fnv 0x004fd360
bool BGSProjectile::FUN_004fd360()
{
    return reinterpret_cast<::FUN_004fd420_shell *>((void *)(((const BGSProjectile_GetFlag_Helper*)this)))->FUN_004fd420(2);
}

// @fnv 0x004fd420
bool FUN_004fd420_shell::FUN_004fd420(int aeFlag)
{
    return (*(int*)((::BSSimpleList< ::TESRace *> *)(::FUN_004ea950((std::intptr_t)(((TESDataHandler*)this))))) & aeFlag) ? true : false;
}

struct FUN_00821640_shell : public TESObjectWEAP
{
    float FUN_00821640();
};

// @fnv 0x00821640
float FUN_00821640_shell::FUN_00821640()
{
    return *(float*)((char*)this + 0x134);
}

struct FUN_004fcf50_shell
{
    void FUN_004fcf80();
    void* DestroyIfFlagged(unsigned int);
};
namespace fnv_004fe080 {
struct FUN_004fd4f0_Class
{
};
struct TESCreature
{
};
struct TESObjectWEAP_Ext : TESObjectWEAP
{
    int GetClipRounds(bool);
};
struct BGSProjectile_GetFlag_Helper
{
};
struct FUN_004fe080_shell : BGSProjectile
{
    int GetProjectileCloneCount(TESObjectWEAP* apSourceWeapon);
};

// @fnv 0x004fe080
int FUN_004fe080_shell::GetProjectileCloneCount(TESObjectWEAP* apSourceWeapon)
{
    int icloneCount = 5;
    if (reinterpret_cast<::FUN_004fd4f0_Class *>((((FUN_004fd4f0_Class*)this)))->FUN_004fd4f0() == 0x40000 ||
        reinterpret_cast<::FUN_004fd4f0_Class *>((((FUN_004fd4f0_Class*)this)))->FUN_004fd4f0() == 0x100000 ||
        reinterpret_cast<::FUN_004fd4f0_Class *>((((FUN_004fd4f0_Class*)this)))->FUN_004fd4f0() == 0x80000)
    {
        icloneCount = 0;
    }
    else if (apSourceWeapon)
    {
        int iprojectiles = (int)reinterpret_cast<::FUN_00821640_shell *>((((TESCreature*)apSourceWeapon)))->FUN_00821640() *
                           reinterpret_cast<::TESObjectWEAP *>((((TESObjectWEAP_Ext*)apSourceWeapon)))->GetDamageForActor(false, false, 0);
        int iprojectilesPerSecond7 = iprojectiles * 3;
        if (reinterpret_cast<::FUN_004fd4f0_Class *>((((FUN_004fd4f0_Class*)this)))->FUN_004fd4f0() != 0x20000)
            iprojectilesPerSecond7 =
                ::MinInt(iprojectilesPerSecond7, ((TESObjectWEAP_Ext*)apSourceWeapon)->GetClipRounds(false));
        if (reinterpret_cast<::FUN_004fd420_shell *>((void *)(((BGSProjectile_GetFlag_Helper*)this)))->FUN_004fd420(0x100))
            iprojectilesPerSecond7 *= 4;
        icloneCount = iprojectilesPerSecond7;
    }
    return icloneCount;
}
}  // namespace fnv_004fe080

template <int N> struct EndianSizeTag
{
    unsigned char value;
};


struct FUN_004fccf0_shell : ::ProjectileProperties
{
    void SwapEndianFields();
};
// @fnv 0x004fd6f0
bool BGSProjectile::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x33)
        return false;

    reinterpret_cast<BGSProjectileVTable*>(this)->Slot6();
    reinterpret_cast<::S00485110 *>((reinterpret_cast<TESForm*>(this)))->CallWithThis((::T00485110 *)(file));
    reinterpret_cast<TESForm*>(this)->SetInitializationState(false);

    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {

        switch (chunkID)
        {
        case 0x44494445: {
            char* buffer = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            reinterpret_cast<BGSProjectileVTable*>(this)->SetEditorID(buffer);
            break;
        }
        case 0x444E424F:
            reinterpret_cast<BGSProjectileVTable*>(this)->LoadBoundChunk(file);
            break;
        case 0x4C4C5546:
            ::ReadFullName(static_cast<TESFullName*>(this), file);
            break;
        case 0x4C444F4D:
        case 0x54444F4D: {
            TESModel::LoadModelData(static_cast<TESModel*>(this), file);
            break;
        }
        case 0x44545344:
        case 0x54534544: {
            ::FUN_004781e0(static_cast<BGSDestructibleObjectForm*>(this), file);
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, &Data, 0x54);
            break;
        case 0x314D414E: {
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
            {
                char* buffer = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0);
                reinterpret_cast<TESModelVTable*>(&m_kProjectileModel)->LoadRawChunk(buffer);
            }
            break;
        }
        case 0x324D414E:
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
                ::FUN_004893e0(&m_kProjectileModel, file);
            break;
        case 0x4D414E56: {
            unsigned int soundLevel;
            file->GetChunkData(&soundLevel);
            if (soundLevel > 3)
                m_eSoundLevel = 1;
            else
                m_eSoundLevel = soundLevel;
            break;
        }
        }

        if (chunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_004fccf0_shell *>(&(Data))->SwapEndianFields();
        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x004fccf0
void FUN_004fccf0_shell::SwapEndianFields()
{
    ::FUN_00401080((int *)(unsigned char *)(reinterpret_cast<unsigned char*>(this)));
    ::FUN_00401080((int *)(unsigned char *)&this->m_fGravity);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fSpeed);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fRange);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fTracerChance);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fExplosionProximity);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fExplosionTimer);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fMuzzleFlashDuration);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fFadeDuration);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fImpactForce);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fRotationX);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fRotationY);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fRotationZ);
    ::FUN_00401080((int *)(unsigned char *)&this->m_fBouncyMult);
}


struct FUN_005e78f0_t
{
};

struct FUN_004fdcf0_subobject
{
    virtual void FUN_004fdcf0_dummy1();
    virtual void FUN_004fdcf0_dummy2();
    virtual void FUN_004fdcf0_copy(FUN_004fdcf0_subobject*);
};

struct FUN_004fdcf0_shell : BGSProjectile
{
    void CopyFromProjectile(TESForm*);
};

// @fnv 0x004fdcf0
void FUN_004fdcf0_shell::CopyFromProjectile(TESForm* apCopy)
{
    BGSProjectile* pcopy;

    pcopy = dynamic_cast<BGSProjectile*>(apCopy);
    if (!pcopy)
        return;

    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);

    ((FUN_004fdcf0_subobject*)&this->m_kProjectileModel)->FUN_004fdcf0_copy((FUN_004fdcf0_subobject*)&pcopy->m_kProjectileModel);

    *(unsigned int*)&this->m_eSoundLevel = *(unsigned int*)&pcopy->m_eSoundLevel;

    __memcpy(((::BSSimpleList< ::TESRace *> *)(::FUN_004ea950((std::intptr_t)(((TESDataHandler*)this))))), ((::BSSimpleList< ::TESRace *> *)(::FUN_004ea950((std::intptr_t)(((TESDataHandler*)pcopy))))), 0x54);
}

struct FUN_005e79a0_t
{
  public:
};

struct BSFadeNode
{
  public:
    unsigned int FUN_009ad610();
};

struct FUN_004fdd80_field
{
  public:
    virtual void FUN_004fdd80_v1();
    virtual void FUN_004fdd80_v2();
    virtual void FUN_004fdd80_v3();
    virtual bool FUN_004fdd80_v4(void* pObject);
};


struct FUN_004fdd80_shell : public BGSProjectile
{
  public:
    bool IsNotEqual(TESForm* apCompare);
};

// Compares this projectile against apCompare: returns true if the cast fails or any of several fields differ, false if all match.
// @fnv 0x004fdd80
bool FUN_004fdd80_shell::IsNotEqual(TESForm* apCompare)
{
    BGSProjectile* pcomp = dynamic_cast<BGSProjectile*>(apCompare);

    if (!pcomp)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pcomp))
        return true;

    if (std::memcmp(reinterpret_cast<const void*>(reinterpret_cast<char*>(&this->Data)),
                ((::BSSimpleList< ::TESRace *> *)(::FUN_004ea950((std::intptr_t)(reinterpret_cast<TESDataHandler*>(pcomp))))), 0x54) != 0)
        return true;

    if (reinterpret_cast<FUN_004fdd80_field*>(&this->m_kProjectileModel)
            ->FUN_004fdd80_v4(reinterpret_cast<char*>(&pcomp->m_kProjectileModel)))
        return true;

    if (*reinterpret_cast<unsigned int*>(&this->m_eSoundLevel) !=
        reinterpret_cast<BSFadeNode*>(pcomp)->FUN_009ad610())
        return true;

    return false;
}

struct FUN_004fcf80_Primary
{
    virtual ~FUN_004fcf80_Primary();
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
};

struct FUN_004fcf80_Base30
{
    virtual ~FUN_004fcf80_Base30();
    int unk04;
    int unk08;
};

struct FUN_004fcf80_Base3c
{
    virtual ~FUN_004fcf80_Base3c();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FUN_004fcf80_Base54
{
    virtual void unk00();
};

struct FUN_004fcf80_Base58
{
    virtual ~FUN_004fcf80_Base58();
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
};

struct FUN_004fcf80_Member
{
    ~FUN_004fcf80_Member();
    int unk00;
};

struct FUN_004fcf80 : FUN_004fcf80_Primary,
                      FUN_004fcf80_Base30,
                      FUN_004fcf80_Base3c,
                      FUN_004fcf80_Base54,
                      FUN_004fcf80_Base58
{
    FUN_004fcf80_Member m_b4;
    virtual ~FUN_004fcf80();
};
// Calls FUN_004fcf80, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x004fcf50
void* FUN_004fcf50_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004fcf80 *>(this)->FUN_004fcf80::~FUN_004fcf80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004fcf80
FUN_004fcf80::~FUN_004fcf80()
{
    reinterpret_cast<::BGSProjectile *>(this)->ClearData();
}

struct CloningProcess
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float fScale;
    CloningProcess(float afScale);
    ~CloningProcess();
};

struct ProjNiObject
{
};

struct ProjFlagHolder
{
};

struct ProjResult
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual ProjFlagHolder* v10();
};

struct ProjBase;

struct ProjRef
{
};

struct ProjBase
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual ProjNiObject* Get3D(ProjRef* apRef);
};

struct ProjBaseHolder
{
};

struct ProjDataHandler
{
};

struct ProjSaveLoad
{
};

struct ProjCache
{
};

struct ProjShell : ProjBase
{
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    unsigned int uiFlags;
    ProjResult* CreateOrClone(ProjRef* apRef, bool abVal);
};

// Creates or clones a ProjResult for apRef depending on the object type and reference state, then sets a flag on the result if present.
// @fnv 0x004fd510
ProjResult* ProjShell::CreateOrClone(ProjRef* apRef, bool abVal)
{
    ProjResult* pResult4 = 0;
    if (apRef)
    {
        switch (((unsigned int)(reinterpret_cast<::FUN_004fd4f0_Class *>(this)->FUN_004fd4f0())))
        {
        case 0x40000:
        case 0x100000:
            pResult4 = ((::ProjResult *)(reinterpret_cast<::fnv_0050ee50::CloneObject17 *>(this)->FUN_0050ee50((::TESObjectREFR *)(apRef), true)));
            break;
        default: {
            ProjRef* pRef8 = apRef;
            if (pRef8 && ((::ProjBaseHolder *)(std::uintptr_t)(reinterpret_cast<::FUN_009d9f00_Class *>((pRef8))->FUN_009d9f00())) && ((::ProjBase *)(reinterpret_cast<::Twin_0044ddc0 *>((((::ProjBaseHolder *)(std::uintptr_t)(reinterpret_cast<::FUN_009d9f00_Class *>((pRef8))->FUN_009d9f00()))))->GetName())))
            {
                ProjNiObject* pNodeVal = ((::ProjBase *)(reinterpret_cast<::Twin_0044ddc0 *>((((::ProjBaseHolder *)(std::uintptr_t)(reinterpret_cast<::FUN_009d9f00_Class *>((pRef8))->FUN_009d9f00()))))->GetName()))->Get3D(0);
                CloningProcess kCloningA(1.0f);
                if (pNodeVal)
                    pResult4 = (ProjResult*)((void *)(reinterpret_cast<::A5D2C0Object *>((pNodeVal))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&kCloningA)))));
            }
            else
            {
                ProjNiObject* p3D = Get3D(apRef);
                if (p3D && reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::ProjDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apRef))->FUN_0084e3a0()))) && !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::ProjSaveLoad * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                {
                    pResult4 = ((::ProjResult *)(std::uintptr_t)(reinterpret_cast<::FUN_004b0ba0_cls *>((((::ProjCache *)(::GetOrCreateInstance(true)))))->FUN_004b0ba0((std::uintptr_t)(p3D))));
                }
                if (!pResult4)
                {
                    pResult4 = ((::ProjResult *)(reinterpret_cast<::fnv_0050ee50::CloneObject17 *>(this)->FUN_0050ee50((::TESObjectREFR *)(apRef), abVal)));
                    if (p3D)
                        reinterpret_cast<::ModelForm0050fbf0 *>(this)->FUN_0050fbf0((::PlayerCharacter *)(apRef));
                }
            }
        }
        }
    }
    if (pResult4 && pResult4->v10())
        reinterpret_cast<::FUN_0049ee60_shell *>((pResult4->v10()))->FUN_0049ee60(true);
    return pResult4;
}

struct S_004fdfb0_Model : TESModel
{
    int FUN_0048cee0();
};
struct S_004fdfb0_Sub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
};
struct S_004fdfb0_Obj
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    S_004fdfb0_Sub sub64;
};
struct S_004fdfb0_Mgr
{
};
struct S_004fdfb0_Preload
{
    virtual void PreloadModels(int a, int b);
};
struct S_004fdfb0_Proj : TESBoundObject, TESFullName, S_004fdfb0_Model, S_004fdfb0_Preload, BGSDestructibleObjectForm
{
    ProjectileProperties Data;
    S_004fdfb0_Model m_kProjectileModel;
    int m_eSoundLevel;
    virtual void PreloadModels(int a, int b);
};

// @fnv 0x004fdfb0
void S_004fdfb0_Proj::PreloadModels(int a, int b)
{
    if (FUN_0048cee0())
    {
        reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::S_004fdfb0_Mgr * *>(&::g_modelLoader))))->FUN_00443d30((std::uintptr_t)(this), a, b, ::FUN_0045c6b0((::TESForm_0045c6b0 *)(::S_004fdfb0_Proj *)(this)), 1, 0, 0);
    }
    if (m_kProjectileModel.FUN_0048cee0())
    {
        reinterpret_cast<::QueueModelHolder *>(((*reinterpret_cast<::S_004fdfb0_Mgr * *>(&::g_modelLoader))))->FUN_00443d30((std::uintptr_t)(&m_kProjectileModel), a, b, 3, 1, 0, 0);
    }
    if (((::S_004fdfb0_Obj *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)this))))
    {
        ((::S_004fdfb0_Obj *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)this)))->sub64.v4(a, b);
    }
}

struct FUN_004fe160_sub
{
    int FUN_00401170();
};

struct FUN_004fe160_cls : ::BGSProjectile
{
    int GetFlaggedValue(unsigned char flag);
};

// Returns the value from the sub-object at offset 0xac, adding the result of GetEffectValue(2, 0) when flag is set.
// @fnv 0x004fe160
int FUN_004fe160_cls::GetFlaggedValue(unsigned char abAddExtra)
{
    if (abAddExtra)
    {
        return (unsigned char)reinterpret_cast<::FUN_004bcf60_shell *>(this)->GetEffectValue(2, 0) +
               reinterpret_cast<FUN_004fe160_sub*>(&this->Data.m_fRotationZ)->FUN_00401170();
    }
    else
    {
        return reinterpret_cast<FUN_004fe160_sub*>(&this->Data.m_fRotationZ)->FUN_00401170();
    }
}

struct FUN_004fe1d0_cls
{
    int GetKindCode();
};

// Maps the value returned by GetKind() to a code (0x3d-0x40, 0x69), returning 0 for any other kind.
// @fnv 0x004fe1d0
int FUN_004fe1d0_cls::GetKindCode()
{
    switch (reinterpret_cast<::FUN_004fd4f0_Class *>(this)->FUN_004fd4f0())
    {
    case 0x10000:
        return 0x3d;
    case 0x20000:
        return 0x3e;
    case 0x40000:
        return 0x3f;
    case 0x80000:
        return 0x40;
    case 0x100000:
        return 0x69;
    default:
        return 0;
    }
}

struct SaveRef
{
};
struct SaveComponent
{
    int Length();
};
struct SaveModel
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* Text();
};
struct ProjectileSave
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    SaveRef* field70;
    SaveRef* field74;
    int field78;
    int field7c;
    int field80;
    SaveRef* field84;
    SaveRef* field88;
    int field8c;
    int field90;
    int field94;
    SaveRef* field98;
    SaveRef* field9c;
    SaveRef* fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    int fieldb4;
    int fieldb8;
    int fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    void WriteProjectileSave();
};
// @fnv 0x004fda00
void ProjectileSave::WriteProjectileSave()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((SaveComponent*)&field30)))->FUN_00487010();
    reinterpret_cast<::FUN_004891d0_cls *>((((SaveComponent*)&field3c)))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    reinterpret_cast<::FUN_00477f20_shell *>((((SaveComponent*)&field58)))->FUN_00477f20();
    SaveRef* saved70 = field70;
    field70 = field70 ? ((::SaveRef *)(reinterpret_cast<::FUN_0084e3a0_Class *>((field70))->FUN_0084e3a0())) : 0;
    SaveRef* saved74 = field74;
    field74 = field74 ? ((::SaveRef *)(reinterpret_cast<::FUN_0084e3a0_Class *>((field74))->FUN_0084e3a0())) : 0;
    SaveRef* saved84 = field84;
    field84 = field84 ? ((::SaveRef *)(reinterpret_cast<::FUN_0084e3a0_Class *>((field84))->FUN_0084e3a0())) : 0;
    SaveRef* savedVal = field88;
    field88 = field88 ? ((::SaveRef *)(reinterpret_cast<::FUN_0084e3a0_Class *>((field88))->FUN_0084e3a0())) : 0;
    SaveRef* saved4 = field98;
    field98 = field98 ? ((::SaveRef *)(reinterpret_cast<::FUN_0084e3a0_Class *>((field98))->FUN_0084e3a0())) : 0;
    SaveRef* saved9c5 = field9c;
    field9c = field9c ? ((::SaveRef *)(reinterpret_cast<::FUN_0084e3a0_Class *>((field9c))->FUN_0084e3a0())) : 0;
    SaveRef* saveda7 = fielda0;
    fielda0 = fielda0 ? ((::SaveRef *)(reinterpret_cast<::FUN_0084e3a0_Class *>((fielda0))->FUN_0084e3a0())) : 0;
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_004fccf0_shell *>((((SaveComponent*)&field60)))->SwapEndianFields();
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20(&field60, 0x54);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_004fccf0_shell *>((((SaveComponent*)&field60)))->SwapEndianFields();
    field70 = saved70;
    field74 = saved74;
    field84 = saved84;
    field88 = savedVal;
    field98 = saved4;
    field9c = saved9c5;
    fielda0 = saveda7;
    if (!((SaveComponent*)&fieldb4)->Length())
    {
        ::FUN_004856f0((void *)(0x314d414e), ((SaveModel*)&fieldb4)->Text(), (void *)(std::uintptr_t)(((SaveComponent*)&fieldb4)->Length() + 1));
    }
    else
    {
        reinterpret_cast<::FUN_004891d0_cls *>((((SaveComponent*)&fieldb4)))->WriteToBuffer((char *)(0x314d414e), (void *)(0x324d414e));
    }
    ::FUN_00485910(0x4d414e56, fieldcc);
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

// Adjustor thunk for FUN_004fe250: "sub ecx, 0x3c; jmp DestroyIfFlagged".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function that a
// class inherits from a secondary base: the thunk converts the secondary base
// sub-object pointer (this + 0x3c) back into the derived object pointer
// (sub ecx, 0x3c) and then tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 14 int members (4 + 14 * 4 = 0x3c
// bytes).  Both bases declare the same virtual function, the derived class
// redeclares it and defines only its constructor, which is what makes the
// compiler emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_004fe250();
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
    virtual void FUN_004fe250();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fe250
    virtual void FUN_004fe250();
};

Derived::Derived()
{}
