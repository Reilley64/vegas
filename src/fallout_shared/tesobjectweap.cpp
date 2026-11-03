// fallout_shared/tesobjectweap.cpp: TESObjectWEAP, TransHolder, Weapon, WeaponCopyAccess and more (72 functions)

#include <cstdint>
#include <new>
#include <cstring>
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BipedAnim.h"
#include "fnv/decl/CalcActor.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/Controller.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00402d50.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00424940_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004600d0_shell.h"
#include "fnv/decl/FUN_0046e8c0_class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00474a80_Class.h"
#include "fnv/decl/FUN_00474bc0_shell.h"
#include "fnv/decl/FUN_00474d60_shell.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00479350_shell.h"
#include "fnv/decl/FUN_0047a240_shell.h"
#include "fnv/decl/FUN_0047bd70_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00485e00_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_00489240_Class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_0048ea80_Class.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004ab500_shell.h"
#include "fnv/decl/FUN_004ad010_shell.h"
#include "fnv/decl/FUN_004ad030_shell.h"
#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/FUN_004bd570_this.h"
#include "fnv/decl/FUN_004bd8d0_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00501c90_shell.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0051f4b0_shell.h"
#include "fnv/decl/FUN_0051f4d0_class.h"
#include "fnv/decl/FUN_0051f4f0_Class.h"
#include "fnv/decl/FUN_0051f530_class.h"
#include "fnv/decl/FUN_005224c0_Class.h"
#include "fnv/decl/FUN_005224e0_class.h"
#include "fnv/decl/FUN_00524b40_class.h"
#include "fnv/decl/FUN_00524b60_shell.h"
#include "fnv/decl/FUN_00525430_Class.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_006d6d90_shell.h"
#include "fnv/decl/FUN_006e4fb0_shell.h"
#include "fnv/decl/FUN_008126e0_shell.h"
#include "fnv/decl/FUN_008133b0_class.h"
#include "fnv/decl/FUN_00821680_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_008bbc10_shell.h"
#include "fnv/decl/FUN_008d8a60_Class.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009c8b90_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder009807f0.h"
#include "fnv/decl/ListHolder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/Proxy804.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/RotationMatrix.h"
#include "fnv/decl/S0047b8a0.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_0048cca0.h"
#include "fnv/decl/S_009c8c40.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/Shell474af0.h"
#include "fnv/decl/Standin77900.h"
#include "fnv/decl/TESAmmoInitCalls.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESPackageShell.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_007e6580.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0048e9b0__TESValueForm.h"
#include "fnv/decl/fnv_0048e9e0__TESValueForm.h"
#include "fnv/decl/fnv_0048ea10__TESValueForm.h"
#include "fnv/decl/fnv_0048ea40__TESValueForm.h"
#include "fnv/decl/fnv_004994f0__FUN_004994f0_shell.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_00676140__FUN_00676140_shell.h"
#include "fnv/decl/fnv_0067ff10__FUN_0067ff10_Class.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00567000.h"
#include "fnv/symbols_0059a000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_0083a000.h"
#include "fnv/symbols_00950000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_009bc000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00c55000.h"
#include "fnv/symbols_00c58000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "tesobjectweap_decls.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/symbols_00472000.h"
#include <math.h>
// Resets the weapon's data block to defaults, initializes embedded sub-structures, sets casting type and sound level, and flags a reload-anim condition.
// @fnv 0x0051ddf0
void TESObjectWEAP::ResetFormData()
{
    memset(&data,0,sizeof(data));
    data.m_ucAmmoUse = 1;
    data.m_fOverrideActionPoints = 5.0f;
    data.m_fMinimumSpread = 0.0f;
    data.fBodyPartChance = 10.0f;
    data.m_fUnknownFloat = 1.0f;
    data.m_ucBaseVATSChance = 5;
    data.m_ucReloadAnimation = 0;
    data.m_ucAttackAnimation = 255;
    data.m_ucGripAnimation = 255;
    data.pProjectile = 0;
    data.m_ucProjectileCount = 1;
    data.m_fMinimumRange = 500.0f;
    data.m_fMaximumRange = 2000.0f;
    data.m_eHitBehavior = WEAPONHITBEHAVIOR_WHB_NORMAL;
    data.m_fLeftRumbleMotorStrength = 0.0f;
    data.m_fRightRumbleMotorStrength = 0.5f;
    data.m_fRumbleDuration = 1.0f;
    data.m_fOverrideDamageToWeaponMultiplier = 0.33f;
    data.m_fAttackShotsPerSecond = 1.0f;
    data.m_eWeaponSkill = (ActorValue__Index)45;
    data.m_fLimbDamageMultiplier = 1.0f;
    data.m_fSightUsage = 0.0f;
    data.m_eResistanceType = (ActorValue__Index)-1;
    data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
    data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
    data.m_uiStrengthRequirement = 0;
    data.m_uiSkillRequirement = 0;
    data.m_fModValueA1 = 0.0f;
    data.m_fModValueA2 = 0.0f;
    data.m_fModValueA3 = 0.0f;
    data.m_fModValueB1 = 0.0f;
    data.m_fModValueB2 = 0.0f;
    data.m_fModValueB3 = 0.0f;
    data.m_fKillImpulse = 1.0f;
    data.m_ucPowerAttackAnimationOverride = 255;
    data.m_cReloadAnimationMod = -1;
    data.m_cUnknownByte = -1;
    m_kCriticalData.m_usCriticalDamage = 0;
    m_kCriticalData.m_fCriticalChanceMultiplier = 1.0f;
    m_kCriticalData.m_bEffectOnDeath = true;
    m_kCriticalData.pEffect = 0;
    m_kVATSData.m_fSkill = 0.0f;
    m_kVATSData.m_fDamageMultiplier = 0.0f;
    m_kVATSData.m_pVATSAttackSpell = 0;
    m_kVATSData.m_fActionPointCost = 0.0f;
    m_kVATSData.bSilent = true;
    m_kVATSData.m_bModRequired = false;
    m_pWeaponEffectShader = 0;
    m_pWeaponSound1 = 0;
    m_pWeaponSound2 = 0;
    m_pWeaponSound3 = 0;
    m_pWeaponSound4 = 0;
    m_pWeaponSound5 = 0;
    m_pWeaponSound6 = 0;
    m_pWeaponSound7 = 0;
    m_pWeaponSound8 = 0;
    m_pWeaponUnequipSound = 0;
    m_pWeaponEquipSound = 0;
    m_pWeaponPickupSound = 0;
    m_pWeaponDropSound = 0;
    m_pImpactDataSet = 0;
    p1stPersonObject = 0;
    p1stPersonMod1Object = 0;
    p1stPersonMod2Object = 0;
    p1stPersonMod3Object = 0;
    p1stPersonMod12Object = 0;
    p1stPersonMod13Object = 0;
    p1stPersonMod23Object = 0;
    p1stPersonMod123Object = 0;
    m_pWeaponMod1 = 0;
    m_pWeaponMod2 = 0;
    m_pWeaponMod3 = 0;
    m_kModel.Init();
    m_kModel1stPerson.Init();
    m_kModel3rdPerson.Init();
    m_kWeaponModTextureSwap1.Init();
    m_kWeaponModTextureSwap2.Init();
    m_kWeaponModTextureSwap3.Init();
    m_kWeaponModTextureSwap4.Init();
    m_kWeaponModTextureSwap5.Init();
    m_kWeaponModTextureSwap6.Init();
    m_kWeaponModTextureSwap7.Init();
    reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00((*(int *)&(const ::MagicSystem__CastingType &)(MagicSystem__CastingType_WHEN_STRIKES)));
    m_eSoundLevel = SOUND_LEVEL_SOUND_LEVEL_NORMAL;
    m_bHasReloadAnimation = false;
    if(GetReloadAnim(false) >= 196) m_bHasReloadAnimation = true;
}

// @fnv 0x0051d770
TESObjectWEAP::TESObjectWEAP()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_WEAP_ID)));
    ResetFormData();
}

// @fnv 0x0051e300
void TESObjectWEAP::ClearData()
{
    reinterpret_cast<::FUN_00402d50 *>(&(m_kModel))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kModel1stPerson))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kModel3rdPerson))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kWeaponModTextureSwap1))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kWeaponModTextureSwap2))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kWeaponModTextureSwap3))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kWeaponModTextureSwap4))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kWeaponModTextureSwap5))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kWeaponModTextureSwap6))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::FUN_00402d50 *>(&(m_kWeaponModTextureSwap7))->FUN_00402d50::~FUN_00402d50();
    reinterpret_cast<::TextString *>(&(m_kEmbeddedWeaponNodeName))->FUN_004037f0(0,0);
    reinterpret_cast<::TextString *>(&(VATSAttackName))->FUN_004037f0(0,0);
}

// @fnv 0x00525510
void TESObjectWEAP::QueueResourceLoad(int priority, QueuedFile* file, bool includeScope)
{
    if(m_kModel.GetModelLength())
        reinterpret_cast<::QueueModelHolder *>((g_modelLoader))->FUN_00443d30((int)(&m_kModel),priority,(int)(file),false,true,false,false);
    if(includeScope && reinterpret_cast<::FUN_004ad010_shell *>(this)->IsFlag4Set() && m_kModel1stPerson.GetModelLength())
        reinterpret_cast<::QueueModelHolder *>((g_modelLoader))->FUN_00443d30((int)(&m_kModel1stPerson),priority,(int)(file),::FUN_0045c6b0((::TESForm_0045c6b0 *)(::TESObject *)(this)),true,false,false);
    if(((::BGSProjectile *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(0))))) ((::BGSProjectile *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(0))))->QueueResourceLoad(priority,file);
    if(m_pImpactDataSet) m_pImpactDataSet->QueueResourceLoad(priority,file);
}

// @fnv 0x009b6600
ActorValue__Index TESObjectWEAP::GetResistance()
{
    return data.m_eResistanceType;
}

// @fnv 0x0051e2a0
int TESObjectWEAP::GetReloadAnim(bool modValue) {
    if (modValue) {
        if (data.m_cReloadAnimationMod != 255) {
            return data.m_cReloadAnimationMod + 177;
        } else {
            return data.m_ucReloadAnimation + 177;
        }
    } else {
        return data.m_ucReloadAnimation + 177;
    }
}

struct FUN_0051f570_shell : public TESObjectWEAP {
    void SetEffectShader(TESEffectShader*);
};

// @fnv 0x0051f570
void FUN_0051f570_shell::SetEffectShader(TESEffectShader* apEffect)
{
    m_pWeaponEffectShader = apEffect;
}

struct FUN_005214d0_shell : public TESObjectWEAP {
    void SetFirstPersonModObject(unsigned char, TESObjectSTAT*);
};

// Stores apObject into the first-person mod object slot selected by the bitmask iModSlots (bits 1, 2 and 4).
// @fnv 0x005214d0
void FUN_005214d0_shell::SetFirstPersonModObject(unsigned char iModSlots, TESObjectSTAT* apObject)
{
    if (iModSlots & 1) {
        if (iModSlots & 2) {
            if (iModSlots & 4)
                p1stPersonMod123Object = apObject;
            else
                p1stPersonMod12Object = apObject;
        } else {
            if (iModSlots & 4)
                p1stPersonMod13Object = apObject;
            else
                p1stPersonMod1Object = apObject;
        }
    } else if (iModSlots & 2) {
        if (iModSlots & 4)
            p1stPersonMod23Object = apObject;
        else
            p1stPersonMod2Object = apObject;
    } else if (iModSlots & 4) {
        p1stPersonMod3Object = apObject;
    }
}

struct FUN_005215a0_shell : public TESObjectWEAP {
    TESSound* FUN_005215a0(bool);
};

// Returns one of two TESSound pointers depending on bModSound.
// @fnv 0x005215a0
TESSound* FUN_005215a0_shell::FUN_005215a0(bool bModSound)
{
    if (bModSound)
        return m_pWeaponEquipSound;
    else
        return m_pWeaponSound1;
}

struct FUN_005215d0_shell : public TESObjectWEAP {
    void FUN_005215d0(TESSound*);
};

// @fnv 0x005215d0
void FUN_005215d0_shell::FUN_005215d0(TESSound* apSnd)
{
    m_pWeaponSound1 = apSnd;
}

struct FUN_005215f0_shell : public TESObjectWEAP {
    void FUN_005215f0(TESSound*);
};

// @fnv 0x005215f0
void FUN_005215f0_shell::FUN_005215f0(TESSound* apSnd)
{
    m_pWeaponSound2 = apSnd;
}

struct FUN_00521610_shell : public TESObjectWEAP {
    void FUN_00521610(TESSound*);
};

// @fnv 0x00521610
void FUN_00521610_shell::FUN_00521610(TESSound* apSnd)
{
    m_pWeaponEquipSound = apSnd;
}

struct FUN_00521650_shell : public TESObjectWEAP {
    void FUN_00521650(TESSound*);
};

// @fnv 0x00521650
void FUN_00521650_shell::FUN_00521650(TESSound* apSnd)
{
    m_pWeaponSound4 = apSnd;
}

struct FUN_00521670_shell : public TESObjectWEAP {
    void FUN_00521670(TESSound*);
};

// @fnv 0x00521670
void FUN_00521670_shell::FUN_00521670(TESSound* apSnd)
{
    m_pWeaponSound5 = apSnd;
}

struct FUN_005216b0_shell : public TESObjectWEAP {
    void FUN_005216b0(TESSound*);
};

// @fnv 0x005216b0
void FUN_005216b0_shell::FUN_005216b0(TESSound* apSnd)
{
    m_pWeaponSound7 = apSnd;
}

struct FUN_005216d0_shell : public TESObjectWEAP {
    void FUN_005216d0(TESSound*);
};

// @fnv 0x005216d0
void FUN_005216d0_shell::FUN_005216d0(TESSound* apSnd)
{
    m_pWeaponSound8 = apSnd;
}

struct FUN_005216f0_shell : public TESObjectWEAP {
    void FUN_005216f0(TESSound*);
};

// @fnv 0x005216f0
void FUN_005216f0_shell::FUN_005216f0(TESSound* apSnd)
{
    m_pWeaponUnequipSound = apSnd;
}

struct NiPoint3;
struct NiStream;
struct blob48 { char b[48]; };
struct blob64 { char b[64]; };
struct ThreeByThreeMatrix {
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
struct FUN_00524ac0_shell : public ThreeByThreeMatrix {
    void FUN_00524ac0(float);
};

void __cdecl FUN_004169a0(float, float &, float &);

// Builds a rotation matrix about the X axis from the sine and cosine of the given angle.
// @fnv 0x00524ac0
void FUN_00524ac0_shell::FUN_00524ac0(float afAngle)
{
    float sn, cs;
    FUN_004169a0(afAngle, sn, cs);

    *(float*)&m_afEntries[0] = 1.0f;
    *(float*)&m_afEntries[4] = 0.0f;
    *(float*)&m_afEntries[8] = 0.0f;
    *(float*)&m_afEntries[12] = 0.0f;
    *(float*)&m_afEntries[16] = cs;
    *(float*)&m_afEntries[20] = sn;
    *(float*)&m_afEntries[24] = 0.0f;
    *(float*)&m_afEntries[28] = -sn;
    *(float*)&m_afEntries[32] = cs;
}

struct TESObjectCELL {
    NiAVObject* GetCellChildAt(int);
};

// @fnv 0x00524cf0
NiAVObject* FUN_00524cf0(TESObjectCELL* apCell)
{
    return apCell->GetCellChildAt(1);
}

// @fnv 0x00524d10
bool FUN_00524d10(bool* pThis)
{
    return pThis[0x64b];
}

namespace fnv_00524d70 {
struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct ActorValueOwner;
struct ActorCombatEntry;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct MusicMarkerReference;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSNote;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSQuestObjective;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct BipedActor;
struct CombatGroupCollection;
struct CellMopp;
struct NiNodeBooleanState;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialoguePackage;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct BooleanIntegerAccessor;
struct FurnitureRelatedType;
struct BooleanFloatQuery;
struct IDebugText;
struct ImageSpaceModifierInstanceDOF;
struct ImageSpaceModifierInstanceDRB;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicShaderHitEffect;
struct MagicTarget;
struct MapMarkerData;
struct MediaLocationController;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct PlayerTargetLocation;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct IntegerPairPointerRecord;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESCaravanCard;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESGlobal;
struct TESIdleForm;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectDOOR;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESPackage;
struct TESQuest;
struct PlayerQuestData;
struct TESRace;
struct TESRegion;
struct TESRegionList;
struct TESReputation;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct PathingPath;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkMouseSpringAction;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4 { char b[4]; };
struct blob12 { char b[12]; };
struct blob16 { char b[16]; };
struct blob48 { char b[48]; };

extern blob12 NiPoint3_ZERO;

// @fnv 0x00524d70
void FUN_00524d70(char* this_ptr)
{
    *(int*)(this_ptr + 0xd2c) = 0;
    *(blob12*)(this_ptr + 0xd30) = NiPoint3_ZERO;
}
}  // namespace fnv_00524d70

struct BSFaceGenAnimationData;
struct BSFaceGenNiNode { BSFaceGenAnimationData* GetAnimationData(); };
struct Flt {  };
struct GlobalObject_00633c90 { char pad[4]; };
// @fnv 0x00524c90
BSFaceGenAnimationData* FUN_00524c90()
{
    return ((BSFaceGenNiNode*)(((::BSFaceGenNiNode *)(::FUN_00559450((int *)(((Flt*)&::g_011deb7c)))))))->GetAnimationData();
}

struct FUN_00522440_shell
{
    int GetValueByFlag(bool bUse);
};

// Returns the int at offset 0x244 when bUse is true, otherwise the int at offset 0x220.
// @fnv 0x00522440
int FUN_00522440_shell::GetValueByFlag(bool bUse)
{
    if (bUse)
    {
        return *(int*)((char*)this + 0x244);
    }
    else
    {
        return *(int*)((char*)this + 0x220);
    }
}

struct FUN_00522500_shell
{
    char pad[0x234];
    unsigned int field234;
    unsigned int GetField234();
};

// @fnv 0x00522500
unsigned int FUN_00522500_shell::GetField234()
{
    return field234;
}

struct FUN_00522520_shell
{
    int GetField238();
};

// @fnv 0x00522520
int FUN_00522520_shell::GetField238()
{
    return *(int*)((char*)this + 0x238);
}

struct FUN_00522560_shell
{
    int FUN_00522560(bool param);
};

// Returns 2 when param is true, otherwise returns the int stored at offset 0x364 of this object.
// @fnv 0x00522560
int FUN_00522560_shell::FUN_00522560(bool abReturnTwo)
{
    if (abReturnTwo)
        return 2;
    else
        return *(int*)((char*)this + 0x364);
}

class BGSLoadFormBuffer;

struct FUN_0048ea80_t {
    void FUN_0048ea80(BGSLoadFormBuffer* b);
};

void FUN_0048ea80_t::FUN_0048ea80(BGSLoadFormBuffer* b) {}

struct FUN_00523120_shell : public TESForm {
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// @fnv 0x00523120
void FUN_00523120_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    reinterpret_cast<::FUN_0048ea80_Class *>((reinterpret_cast<FUN_0048ea80_t*>(reinterpret_cast<char*>(this) + 0x84)))->FUN_0048ea80(buffer);
}


// @fnv 0x00524cb0
void* FUN_00524cb0()
{
    return (*reinterpret_cast<void * *>(&::DAT_011c621c));
}

struct NiFixedString;

// @fnv 0x00524cc0
NiFixedString* FUN_00524cc0()
{
    return ::DAT_011c6220;
}

struct FUN_00524d30_shell {
    void SetByteAtOffset1F8(char arg);
};

// @fnv 0x00524d30
void FUN_00524d30_shell::SetByteAtOffset1F8(char acValue) {
    ((char*)this)[0x1f8] = acValue;
}

struct FUN_00525be0_shell
{
    char GetByteAtOffsetB0();
};
// @fnv 0x00525b20
unsigned char TESObjectWEAP::GetDamageForActor(bool includeMods, bool ignoreAmmo, Actor* actor)
{
    unsigned char count = data.m_ucProjectileCount;
    if(!ignoreAmmo && ((::TESAmmo *)(reinterpret_cast<::AmmoOwner *>(this)->FUN_00525980((::AmmoActor *)(actor)))) && ((unsigned char)(reinterpret_cast<::FUN_00525be0_shell *>((((::TESAmmo *)(reinterpret_cast<::AmmoOwner *>(this)->FUN_00525980((::AmmoActor *)(actor))))))->GetByteAtOffsetB0())) > 0)
        count = ((unsigned char)(reinterpret_cast<::FUN_00525be0_shell *>((((::TESAmmo *)(reinterpret_cast<::AmmoOwner *>(this)->FUN_00525980((::AmmoActor *)(actor))))))->GetByteAtOffsetB0())) * reinterpret_cast<::FUN_00524b60_shell *>(this)->GetByteAt102();
    if(includeMods) count += reinterpret_cast<::FUN_004bcf60_shell *>(this)->GetEffectValue((*(int *)&(const ::WEAPON_MOD_EFFECT &)(WEAPON_MOD_EFFECT_WEAPON_MOD_SPLIT_BEAM)),0);
    return count;
}

// @fnv 0x00525be0
char FUN_00525be0_shell::GetByteAtOffsetB0()
{
    return *reinterpret_cast<char*>(reinterpret_cast<unsigned char*>(this) + 0xb0);
}

struct FUN_00645c60_shell
{
    virtual float GetField178Float() const;
};

// @fnv 0x00645c60
float FUN_00645c60_shell::GetField178Float() const
{
    return *reinterpret_cast<const float*>(reinterpret_cast<const unsigned char*>(this) + 0x178);
}

struct FUN_008bffa0_shell
{
    int GetField228();
};

// @fnv 0x008bffa0
int FUN_008bffa0_shell::GetField228()
{
    return *(int*)((char*)this + 0x228);
}

struct FUN_0051f5f0_shell
{
    unsigned int GetByteAt11D();
};

// @fnv 0x0051f5f0
unsigned int FUN_0051f5f0_shell::GetByteAt11D()
{
    return ((unsigned char*)this)[0x11d];
}

struct FUN_0051f610_shell {
    unsigned int GetByteAtOffset101();
};

// @fnv 0x0051f610
unsigned int FUN_0051f610_shell::GetByteAtOffset101()
{
    return ((unsigned char*)this)[0x101];
}

struct FUN_00521580_shell {
    char m_011e; // placeholder
    void FUN_00521580(bool bVal);
};

// @fnv 0x00521580
void FUN_00521580_shell::FUN_00521580(bool bVal)
{
    *(char*)((char*)this + 0x11E) = bVal;
}

struct FUN_00522540_shell {
    int GetField23C();
};

// @fnv 0x00522540
int FUN_00522540_shell::GetField23C()
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x23c);
}

namespace fnv_00522c00 {
struct Flt {
    operator unsigned int() const;
};

struct FUN_00522c00_shell {
    unsigned int FUN_00522c00();
};

// @fnv 0x00522c00
unsigned int FUN_00522c00_shell::FUN_00522c00()
{
    if (((unsigned char)(reinterpret_cast<::FUN_0046e8c0_class *>(this)->FUN_0046e8c0())))
    {
        return reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x35c)->operator unsigned int();
    }
    return 0;
}
}  // namespace fnv_00522c00

struct TESFormStub {
};

struct TESValueFormStub {
};

struct FUN_005230b0_shell {
    TESFormStub m_stub;
    char m_auiShapeKeys[0x84 - sizeof(TESFormStub)];
    TESValueFormStub m_valueStub;
    void FUN_005230b0(unsigned int, unsigned int);
};

// Calls FUN_00484c50 on the TESFormStub member and FUN_0048ea10 on the TESValueFormStub member, forwarding a and b to both.
// @fnv 0x005230b0
void FUN_005230b0_shell::FUN_005230b0(unsigned int auiArg1, unsigned int auiArg2)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>(&(m_stub))->FUN_00484c50(auiArg1, auiArg2);
    reinterpret_cast<::fnv_0048ea10::TESValueForm *>(&(m_valueStub))->FUN_0048ea10(auiArg1, auiArg2);
}

struct BGSSaveFormBuffer;

struct FUN_00484d60_holder {
};
struct FUN_0048ea40_holder {
};

struct FUN_005230f0_shell : TESObjectWEAP {
    void FUN_005230f0(BGSSaveFormBuffer* buffer);
};

// @fnv 0x005230f0
void FUN_005230f0_shell::FUN_005230f0(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged(buffer);
    reinterpret_cast<::fnv_0048ea40::TESValueForm *>((reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x84)))->FUN_0048ea40((::fnv_0048ea40::BGSSaveFormBuffer *)(buffer));
}

struct FUN_00524cd0_shell
{
    unsigned char GetByteAt0D();
};

// @fnv 0x00524cd0
unsigned char FUN_00524cd0_shell::GetByteAt0D()
{
    return ((unsigned char*)this)[0x0d];
}

struct FUN_00524d50_shell
{
    char GetByteAtOffset1F8();
};

// @fnv 0x00524d50
char FUN_00524d50_shell::GetByteAtOffset1F8()
{
    return ((char*)this)[0x1f8];
}

struct FUN_0051dad0_This {
    void FUN_0051db00();
    void* FUN_0051dad0(unsigned int);
};
struct FUN_004fb7a0_obj {  };
struct FUN_00522ba0_obj { int FUN_00522ba0(int); };
// If the object at offset 0x24C is non-null, forwards a1 to its FUN_004fb7a0 and returns the result; otherwise returns 0.
// @fnv 0x00522ba0
int FUN_00522ba0_obj::FUN_00522ba0(int a1)
{
    int val = 0;
    if (*reinterpret_cast<FUN_004fb7a0_obj**>(reinterpret_cast<char*>(this) + 0x24C) != 0)
        val = ((int)(reinterpret_cast<::Proxy804 *>(((*reinterpret_cast<FUN_004fb7a0_obj**>(reinterpret_cast<char*>(this) + 0x24C))))->FUN_004fb7a0(a1)));
    return val;
}

namespace fnv_00522be0 {
struct Flt { operator unsigned int(); };
struct FUN_00522be0_shell {
    unsigned int FUN_00522be0();
};
// @fnv 0x00522be0
unsigned int FUN_00522be0_shell::FUN_00522be0()
{
    return ((Flt*)((char*)this + 0x368))->operator unsigned int();
}
}  // namespace fnv_00522be0

struct FUN_0051b070_shell {   };
struct FUN_00523080_shell { void FUN_00523080(unsigned int); };
// Forwards aiFlags to FUN_00484c20 on this and to FUN_0048e9e0 on the object at offset 0x84.
// @fnv 0x00523080
void FUN_00523080_shell::FUN_00523080(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>((((FUN_0051b070_shell*)this)))->FUN_00484c20(aiFlags);
    reinterpret_cast<::fnv_0048e9e0::TESValueForm *>((((FUN_0051b070_shell*)((char*)this + 0x84))))->FUN_0048e9e0(aiFlags);
}

struct FUN_00524b80_This : TESObjectWEAP { float FUN_00524b80(bool); };
// Returns the weapon's spread at offset 0x104, reduced by the weapon-mod decrease-spread effect when bModValue is set.
// @fnv 0x00524b80
float FUN_00524b80_This::FUN_00524b80(bool abApplyMod)
{
	if (abApplyMod)
		return FUN_00404010(0.0f, *(float*)((char*)this + 0x104) - reinterpret_cast<::FUN_004bcf60_shell *>(this)->GetEffectValue((*(int *)&(const ::WEAPON_MOD_EFFECT &)(WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_SPREAD)), 0));
	else
		return *(float*)((char*)this + 0x104);
}

struct FUN_00524be0_shell : TESObjectWEAP { float FUN_00524be0(bool); };
// Returns the weapon's spread at offset 0x108, reduced by the weapon-mod decrease-spread effect when bModValue is set.
// @fnv 0x00524be0
float FUN_00524be0_shell::FUN_00524be0(bool abApplyMod)
{
	if (abApplyMod)
		return FUN_00404010(0.0f, *(float *)((char *)this + 0x108) - reinterpret_cast<::FUN_004bcf60_shell *>(this)->GetEffectValue((*(int *)&(const ::WEAPON_MOD_EFFECT &)(WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_SPREAD)), 0));
	else
		return *(float *)((char *)this + 0x108);
}

namespace fnv_00524c40 {
struct NiPoint3 { float x; float y; float z; NiPoint3 operator+(NiPoint3 const &) const; NiPoint3 operator*(float) const; };
struct ThreeByThreeMatrix { float m[9]; NiPoint3 operator*(NiPoint3 const &) const; };
struct TransHolder { ThreeByThreeMatrix rot; NiPoint3 pos; float scl; NiPoint3 FUN_00524c40(NiPoint3 const &) const; };
// Applies the holder's rotation and scale to a point, then adds its position offset.
// @fnv 0x00524c40
NiPoint3 TransHolder::FUN_00524c40(NiPoint3 const &aPoint) const
{
    return (rot * aPoint) * scl + pos;
}
}  // namespace fnv_00524c40

struct Unk005256b0 {
    const char* GetProjectileNodeName();
};
// Returns the result of FUN_00522c00 if FUN_0046e8c0 and FUN_00522c00 succeed and the string is non-empty, otherwise "ProjectileNode".
// @fnv 0x005256b0
const char* Unk005256b0::GetProjectileNodeName()
{
    return reinterpret_cast<::FUN_0046e8c0_class *>(this)->FUN_0046e8c0() && ((const char *)(reinterpret_cast<::fnv_00522c00::FUN_00522c00_shell *>(this)->FUN_00522c00())) && *((const char *)(reinterpret_cast<::fnv_00522c00::FUN_00522c00_shell *>(this)->FUN_00522c00())) ? ((const char *)(reinterpret_cast<::fnv_00522c00::FUN_00522c00_shell *>(this)->FUN_00522c00())) : "ProjectileNode";
}

struct SceneObjectLookup {  };
struct UnkClass25700 {  NiAVObject* FUN_00525700(NiAVObject*); };
// @fnv 0x00525700
NiAVObject* UnkClass25700::FUN_00525700(NiAVObject* apObject)
{
    NiAVObject* pFoundObject;
    const char* pNodeName;
    pNodeName = reinterpret_cast<::Unk005256b0 *>((this))->GetProjectileNodeName();
    pFoundObject = ::FUN_004aae30(apObject, (::NiFixedString *)(pNodeName));
    if (pFoundObject == 0)
        pFoundObject = ::FUN_004aae30(apObject, (::NiFixedString *)("##ProjectileNode"));
    return pFoundObject;
}

struct S_00522470
{
    char pad0[0x224];
    void* p224;
    char pad1[0x20];
    void* p248;
    void* GetPointerByFlag(bool);
};
// Returns p248 when the flag is true, otherwise returns p224.
// @fnv 0x00522470
void* S_00522470::GetPointerByFlag(bool a)
{
    if (a)
        return p248;
    else
        return p224;
}

struct S522c30
{
    unsigned char _pad[0x11F];
    unsigned char field_11F;
    int FUN_00522c30();
};
// Returns -1 unless FUN_0046e8c0 succeeds, otherwise field_11F + 0x19 clamped to at most 0x1F.
// @fnv 0x00522c30
int S522c30::FUN_00522c30()
{
    int model = -1;
    if (reinterpret_cast<::FUN_0046e8c0_class *>(this)->FUN_0046e8c0())
    {
        model = field_11F + 0x19;
        if (model >= 0x20)
            model = 0x1F;
    }
    return model;
}

struct FUN_00484bf0 {
    unsigned short GetSaveSize(unsigned int);
};
struct FUN_0048e9b0 {
    unsigned short GetSaveSize(unsigned int);
};

struct FUN_00523020_shell {
    FUN_00484bf0 m_iWordAt00;
    unsigned char pad1[0x83];
    FUN_0048e9b0 m_cByteAtOffset1;
    unsigned short GetSaveSize(unsigned int aiFlags);
};

// Returns the sum of the save sizes reported by the two embedded objects for the given flags.
// @fnv 0x00523020
unsigned short FUN_00523020_shell::GetSaveSize(unsigned int aiFlags)
{
    unsigned short usSize = 0;
    usSize += reinterpret_cast<::FUN_00484bf0_shell *>(&(m_iWordAt00))->FUN_00484bf0(aiFlags);
    usSize += reinterpret_cast<::fnv_0048e9b0::TESValueForm *>(&(m_cByteAtOffset1))->FUN_0048e9b0(aiFlags);
    return usSize;
}

struct ModelPathIface {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual char* GetModelFilePath();
};
struct FUN_00522df0_shell : public TESObjectWEAP {
    int FUN_00446390();
    TESModel* GetModelForModFlags(unsigned char acModFlags, bool abNoWorldModel);
};

// @fnv 0x00522df0
TESModel* FUN_00522df0_shell::GetModelForModFlags(unsigned char acModFlags, bool abNoWorldModel)
{
    TESModel* m_kModelObjectsItem = 0;
    if (FUN_00446390() == 0 && !abNoWorldModel)
    {
        if (*((ModelPathIface*)&m_kModel3rdPerson)->GetModelFilePath())
            return &m_kModel3rdPerson;
        else
            return this;
    }
    if (acModFlags & 1)
    {
        if (acModFlags & 2)
        {
            if (acModFlags & 4)
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap7)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap7;
            }
            else
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap4)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap4;
            }
        }
        else
        {
            if (acModFlags & 4)
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap5)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap5;
            }
            else
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap1)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap1;
            }
        }
    }
    else
    {
        if (acModFlags & 2)
        {
            if (acModFlags & 4)
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap6)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap6;
            }
            else
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap2)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap2;
            }
        }
        else if (acModFlags & 4)
        {
            if (*((ModelPathIface*)&m_kWeaponModTextureSwap3)->GetModelFilePath())
                m_kModelObjectsItem = &m_kWeaponModTextureSwap3;
        }
    }
    if (!m_kModelObjectsItem || ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) == 0x1735d4)
        m_kModelObjectsItem = this;
    return m_kModelObjectsItem;
}

struct FUN_00525450_shell {
    void QueueModelsForLoad(int, class QueuedFile*);
};

// @fnv 0x00525450
void FUN_00525450_shell::QueueModelsForLoad(int aiIndex, class QueuedFile* apFile)
{
    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x104)->GetModelLength())
        reinterpret_cast<::QueueModelHolder *>((g_modelLoader))->FUN_00443d30((int)(reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x104)), aiIndex, (int)(apFile), 0, true, false, false);
    if (((::BGSProjectile *)(reinterpret_cast<::Thing *>((reinterpret_cast<TESObjectWEAP*>(reinterpret_cast<char*>(this) - 0xcc)))->GetOrFallback((int)(0)))))
        reinterpret_cast<TESModel*>(static_cast<BGSPreloadable *>((::BGSProjectile *)(reinterpret_cast<::Thing *>((reinterpret_cast<TESObjectWEAP*>(reinterpret_cast<char*>(this) - 0xcc)))->GetOrFallback((int)(0)))))->vfn_10(aiIndex, apFile);
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x180))
        reinterpret_cast<TESModelTextureSwap*>(reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x180)) + 0x18)->vfn_10(aiIndex, apFile);
}

struct GlobalObject_0045cfe0 {  };
struct FUN_00525620_shell { int GetStateValue(bool a, bool b); };
// Reads a state value from offset 0x364, overridden to 2 or 1 by the flags, and returns the int from the matching global.
// @fnv 0x00525620
int FUN_00525620_shell::GetStateValue(bool abForceState2, bool abForceState1)
{
    int r7 = 0;
    int s = *(int*)((char*)this + 0x364);
    if (abForceState2) s = 2;
    if (abForceState1) s = 1;
    switch (s) {
    case 2: r7 = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cd3b4)))))); break;
    case 1: r7 = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cd538)))))); break;
    case 0: r7 = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cdde0)))))); break;
    }
    return r7;
}

struct FUN_0051db00 :
    public TESBoundObject,
    public TESFullName,
    public TESModelTextureSwap,
    public TESIcon,
    public TESScriptableForm,
    public TESEnchantableForm,
    public TESValueForm,
    public TESWeightForm,
    public TESHealthForm,
    public TESAttackDamageForm,
    public BGSAmmoForm,
    public BGSClipRoundsForm,
    public BGSDestructibleObjectForm,
    public BGSRepairItemList,
    public BGSEquipType,
    public BGSPreloadable,
    public BGSMessageIcon,
    public BGSBipedModelList,
    public BGSPickupPutdownSounds
{
    WeaponProperties data;
    WeaponCriticalData m_kCriticalData;
    TESModel m_kModel;
    TESModel m_kModel1stPerson;
    TESModel m_kModel3rdPerson;
    TESEffectShader* m_pWeaponEffectShader;
    TESSound* m_pWeaponSound1;
    TESSound* m_pWeaponSound2;
    TESSound* m_pWeaponSound3;
    TESSound* m_pWeaponSound4;
    TESSound* m_pWeaponSound5;
    TESSound* m_pWeaponSound6;
    TESSound* m_pWeaponSound7;
    TESSound* m_pWeaponSound8;
    TESSound* m_pWeaponUnequipSound;
    TESSound* m_pWeaponEquipSound;
    TESSound* m_pWeaponPickupSound;
    TESSound* m_pWeaponDropSound;
    BGSImpactDataSet* m_pImpactDataSet;
    TESObjectSTAT* p1stPersonObject;
    TESObjectSTAT* p1stPersonMod1Object;
    TESObjectSTAT* p1stPersonMod2Object;
    TESObjectSTAT* p1stPersonMod3Object;
    TESObjectSTAT* p1stPersonMod12Object;
    TESObjectSTAT* p1stPersonMod23Object;
    TESObjectSTAT* p1stPersonMod13Object;
    TESObjectSTAT* p1stPersonMod123Object;
    TESModelTextureSwap m_kWeaponModTextureSwap1;
    TESModelTextureSwap m_kWeaponModTextureSwap2;
    TESModelTextureSwap m_kWeaponModTextureSwap3;
    TESModelTextureSwap m_kWeaponModTextureSwap4;
    TESModelTextureSwap m_kWeaponModTextureSwap5;
    TESModelTextureSwap m_kWeaponModTextureSwap6;
    TESModelTextureSwap m_kWeaponModTextureSwap7;
    TESObjectIMOD* m_pWeaponMod1;
    TESObjectIMOD* m_pWeaponMod2;
    TESObjectIMOD* m_pWeaponMod3;
    BSStringT<char> m_kEmbeddedWeaponNodeName;
    SOUND_LEVEL m_eSoundLevel;
    BSStringT<char> VATSAttackName;
    WeaponVATSData m_kVATSData;
    bool m_bHasReloadAnimation;
    unsigned char layoutPadding385[3];

    ~FUN_0051db00();
};
// Calls FUN_0051db00 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0051dad0
void* FUN_0051dad0_This::FUN_0051dad0(unsigned int flags)
{
    reinterpret_cast<::FUN_0051db00 *>((this))->FUN_0051db00::~FUN_0051db00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that clears the weapon's data via TESObjectWEAP::ClearData.
// @fnv 0x0051db00
FUN_0051db00::~FUN_0051db00()
{
    reinterpret_cast<TESObjectWEAP*>(this)->TESObjectWEAP::ClearData();
}

class FUN_0051f590_cls {
public:
    unsigned int m_000;
    unsigned int m_004;
    unsigned int m_008;
    unsigned int m_00C;
    unsigned int m_010;
    unsigned int m_014;
    unsigned int m_018;
    unsigned int m_01C;
    unsigned int m_020;
    unsigned int m_024;
    unsigned int m_028;
    unsigned int m_02C;
    unsigned int m_030;
    unsigned int m_034;
    unsigned int m_038;
    unsigned int m_03C;
    unsigned int m_040;
    unsigned int m_044;
    unsigned int m_048;
    unsigned int m_04C;
    unsigned int m_050;
    unsigned int m_054;
    unsigned int m_058;
    unsigned int m_05C;
    unsigned int m_060;
    unsigned int m_064;
    unsigned int m_068;
    unsigned int m_06C;
    unsigned int m_070;
    unsigned int m_074;
    unsigned int m_078;
    unsigned int m_07C;
    unsigned int m_080;
    unsigned int m_084;
    unsigned int m_088;
    unsigned int m_08C;
    unsigned int m_090;
    unsigned int m_094;
    unsigned int m_098;
    unsigned int m_09C;
    unsigned int m_0A0;
    unsigned int m_0A4;
    unsigned int m_0A8;
    unsigned int m_0AC;
    unsigned int m_0B0;
    unsigned int m_0B4;
    unsigned int m_0B8;
    unsigned int m_0BC;
    unsigned int m_0C0;
    unsigned int m_0C4;
    unsigned int m_0C8;
    unsigned int m_0CC;
    unsigned int m_0D0;
    unsigned int m_0D4;
    unsigned int m_0D8;
    unsigned int m_0DC;
    unsigned int m_0E0;
    unsigned int m_0E4;
    unsigned int m_0E8;
    unsigned int m_0EC;
    unsigned int m_0F0;
    unsigned int m_0F4;
    unsigned int m_0F8;
    unsigned int m_0FC;
    unsigned int m_100;
    unsigned int m_104;
    unsigned int m_108;
    unsigned int m_10C;
    unsigned int m_110;
    unsigned int m_114;
    unsigned int m_118;
    unsigned int m_11C;
    unsigned int m_120;
    unsigned int m_124;
    unsigned int m_128;
    unsigned int m_flags;
    void SetFlag2(bool abSet);
};
// @fnv 0x0051e420
void TESObjectWEAP::InitItem()
{
    if(reinterpret_cast<::TESForm *>((void *)this)->GetInitialized()) return;
    BGSBipedModelList::InitItem(this);
    TESScriptableForm::InitItem(this);
    TESEnchantableForm::InitItem(this);
    reinterpret_cast<::FUN_00474bc0_shell *>(this)->CompareAmmo((::BaseFormComponent *)(::TESForm *)(this));
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BGSRepairItemList::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    unsigned int formID = (unsigned int)((::BGSProjectile *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(0))));
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        reinterpret_cast<::FUN_0051f4b0_shell *>(this)->FUN_0051f4b0((int)(dynamic_cast<BGSProjectile*>(::FUN_004839c0(formID))));
        if(!((::BGSProjectile *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(0))))) ::FUN_005b5e40();
    }
    formID = (unsigned int)((::TESEffectShader *)(reinterpret_cast<::TESDataHandler *>(this)->GetCompiledFileCount()));
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        reinterpret_cast<::FUN_0051f570_shell *>(this)->SetEffectShader(dynamic_cast<TESEffectShader*>(::FUN_004839c0(formID)));
        if(!((::TESEffectShader *)(reinterpret_cast<::TESDataHandler *>(this)->GetCompiledFileCount()))) ::FUN_005b5e40();
    }
    formID = (unsigned int)((::SpellItem *)(reinterpret_cast<::FUN_0051f4d0_class *>(this)->GetField1CC()));
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        reinterpret_cast<::FUN_0051f4f0_Class *>(this)->FUN_0051f4f0((int)(dynamic_cast<SpellItem*>(::FUN_004839c0(formID))));
        if(!((::SpellItem *)(reinterpret_cast<::FUN_0051f4d0_class *>(this)->GetField1CC()))) ::FUN_005b5e40();
    }
    formID = (unsigned int)((::SpellItem *)(reinterpret_cast<::HighProcess *>(this)->GetMobileObject()));
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        reinterpret_cast<::FUN_0051f530_class *>(this)->FUN_0051f530((int)(dynamic_cast<SpellItem*>(::FUN_004839c0(formID))));
        if(!((::SpellItem *)(reinterpret_cast<::HighProcess *>(this)->GetMobileObject()))) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound1;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound1 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound1) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound2;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound2 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound2) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound3;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound3 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound3) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound4;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound4 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound4) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound5;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound5 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound5) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound6;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound6 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound6) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound7;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound7 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound7) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponSound8;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponSound8 = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponSound8) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponUnequipSound;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponUnequipSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponUnequipSound) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponEquipSound;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponEquipSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponEquipSound) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponPickupSound;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponPickupSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponPickupSound) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponDropSound;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponDropSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if(!m_pWeaponDropSound) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pImpactDataSet;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pImpactDataSet = dynamic_cast<BGSImpactDataSet*>(::FUN_004839c0(formID));
        if(!m_pImpactDataSet) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonObject;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonObject = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonObject) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonMod1Object;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonMod1Object = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonMod1Object) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonMod2Object;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonMod2Object = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonMod2Object) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonMod3Object;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonMod3Object = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonMod3Object) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonMod12Object;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonMod12Object = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonMod12Object) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonMod13Object;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonMod13Object = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonMod13Object) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonMod23Object;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonMod23Object = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonMod23Object) ::FUN_005b5e40();
    }
    formID = (unsigned int)p1stPersonMod123Object;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        p1stPersonMod123Object = dynamic_cast<TESObjectSTAT*>(::FUN_004839c0(formID));
        if(!p1stPersonMod123Object) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponMod1;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponMod1 = dynamic_cast<TESObjectIMOD*>(::FUN_004839c0(formID));
        if(!m_pWeaponMod1) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponMod2;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponMod2 = dynamic_cast<TESObjectIMOD*>(::FUN_004839c0(formID));
        if(!m_pWeaponMod2) ::FUN_005b5e40();
    }
    formID = (unsigned int)m_pWeaponMod3;
    if(formID) {
        ::ResolveFormID((unsigned int *)&(formID),GetFile(-1));
        m_pWeaponMod3 = dynamic_cast<TESObjectIMOD*>(::FUN_004839c0(formID));
        if(!m_pWeaponMod3) ::FUN_005b5e40();
    }
    if(data.fSpeed <= 0.0) data.fSpeed = 1.0f;
    if(data.m_fAnimationAttackMultiplier <= 0.0) data.m_fAnimationAttackMultiplier = 1.0f;
    if((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011c94d0)).Bool()->b) reinterpret_cast<::FUN_0051f590_cls *>(this)->SetFlag2(true);
    m_bHasReloadAnimation = false;
    if(data.m_ucReloadAnimation >= 19) m_bHasReloadAnimation = true;
    SetInitializationState(true);
}

// @fnv 0x0051f590
void FUN_0051f590_cls::SetFlag2(bool abSet)
{
    abSet ? (m_flags |= 2) : (m_flags &= 0xfffffffd);
}

typedef unsigned int UInt32;




struct BSString
{
    char* pString;
    unsigned short len;
    unsigned short max;
};

struct FullName { char pad[0xc];  };
struct ModelSwap { char pad[0x20];   };
struct Icon { char pad[0xc];  };
struct Scriptable { char pad[0xc];  };
struct Enchantable { char pad[0x30];  };
struct ValueForm { char pad[0x10];  };
struct WeightForm { char pad[0x8];  };
struct HealthForm { char pad[0x8];  };
struct AttackDamage { char pad[0xc];  };
struct MessageFullNameRecord { char pad[0x10];  };
struct AmmoForm { char pad[0x8];  };
struct ClipRounds { char pad[0xc];  };
struct WeapData { char pad[0x24]; TESForm* pProjectile; char pad2[0xa4];  };
struct CritData { char pad[0xc]; TESForm* pEffect;  };
struct Model { char pad[0x18];  };
struct ModModel { char pad[0x20];  };
struct VATSData { TESForm* pEffect; char pad[0x10];  };

struct Weapon
{
    char pad000[0x30];
    FullName fullName;          // 0x30
    ModelSwap model;            // 0x3c
    Icon icon;                  // 0x5c
    Scriptable script;          // 0x68
    Enchantable enchant;        // 0x74
    ValueForm value;            // 0xa4
    WeightForm weight;          // 0xb4
    HealthForm health;          // 0xbc
    AttackDamage damage;        // 0xc4
    MessageFullNameRecord messageIcon;    // 0xd0
    AmmoForm ammo;              // 0xe0
    ClipRounds clip;            // 0xe8
    WeapData data;              // 0xf4
    CritData crit;              // 0x1c0
    Model shellModel;           // 0x1d0
    Model scopeModel;           // 0x1e8
    Model worldModel;           // 0x200
    TESForm* m_pWeaponEffectShader;      // 0x218
    TESForm* m_pWeaponSound1;      // 0x21c
    TESForm* m_pWeaponSound2;     // 0x220
    TESForm* m_pWeaponSound3;    // 0x224
    TESForm* m_pWeaponSound4;       // 0x228
    TESForm* pAttackFail;       // 0x22c
    TESForm* pMeleeBlock;       // 0x230
    TESForm* m_pIdleForm;             // 0x234
    TESForm* pEquip;            // 0x238
    TESForm* pUnEquip;          // 0x23c
    TESForm* pSilenced;         // 0x240
    TESForm* pSilenced2;        // 0x244
    TESForm* pSilenced2D;       // 0x248
    TESForm* pImpact;           // 0x24c
    TESForm* p1st;              // 0x250
    TESForm* p1st1;             // 0x254
    TESForm* p1st2;             // 0x258
    TESForm* p1st3;             // 0x25c
    TESForm* p1st12;            // 0x260
    TESForm* p1st23;            // 0x264
    TESForm* p1st13;            // 0x268
    TESForm* p1st123;           // 0x26c
    ModModel mod1;              // 0x270
    ModModel mod2;              // 0x290
    ModModel mod3;              // 0x2b0
    ModModel mod12;             // 0x2d0
    ModModel mod13;             // 0x2f0
    ModModel mod23;             // 0x310
    ModModel mod123;            // 0x330
    TESForm* pMod1;             // 0x350
    TESForm* pMod2;             // 0x354
    TESForm* pMod3;             // 0x358
    BSString embeddedNode;      // 0x35c
    UInt32 soundLevel;          // 0x364
    BSString vatsAttackName;    // 0x368
    VATSData vats;              // 0x370

    void Save();
};

struct StringCopyAccess : BSStringT<char> {
};
struct StackWord { unsigned int word; };
struct WeaponCopyAccess;
struct WeaponCopyAccess : TESObjectWEAP {
    void CopyFromWeapon(unsigned int id);
    SOUND_LEVEL FUN_00522560(bool);
    unsigned int FUN_00401170();
};
// Copies weapon data, strings, mods, sounds and flags from the weapon with the given id into this object.
// @fnv 0x00522020
void WeaponCopyAccess::CopyFromWeapon(unsigned int id)
{
    WeaponCopyAccess* source = (WeaponCopyAccess*)dynamic_cast<::TESObjectWEAP *>(reinterpret_cast<::TESForm *>(id));
    if (source == 0) return;
    {
        reinterpret_cast<::FormCloneOperation *>((this))->FUN_004851b0((*(void * *)&(const ::StackWord &)(*(StackWord*)&id)));
        m_kModel.CopyFromBase(&source->m_kModel);
        reinterpret_cast<::TextString *>((((StringCopyAccess*)&m_kEmbeddedWeaponNodeName)))->FUN_004037f0(
            ((const char *)(::FUN_00559450((int *)(((StringCopyAccess*)&source->m_kEmbeddedWeaponNodeName))))), {});
        reinterpret_cast<::TextString *>((((StringCopyAccess*)&VATSAttackName)))->FUN_004037f0(
            ((const char *)(::FUN_00559450((int *)(((StringCopyAccess*)&source->VATSAttackName))))), {});
        m_kModel3rdPerson.CopyFromBase(&source->m_kModel3rdPerson);
        m_kModel1stPerson.CopyFromBase(&source->m_kModel1stPerson);
        reinterpret_cast<::FUN_0051f570_shell *>(this)->SetEffectShader(((::TESEffectShader *)(reinterpret_cast<::TESDataHandler *>((source))->GetCompiledFileCount())));
        reinterpret_cast<::MiddleHighProcess *>(this)->SetFaceGenHeadNode((::BSFaceGenNiNode *)(void *)(((void *)(reinterpret_cast<::MiddleHighProcess *>((source))->GetFaceGenHeadNode()))));
        reinterpret_cast<::MiddleHighProcess *>(this)->SetAnimationNode((::NiAVObject *)(::BGSImpactDataSet *)(((::BGSImpactDataSet *)(reinterpret_cast<::MiddleHighProcess *>((source))->GetAnimationObject()))));
        reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(1, reinterpret_cast<::FUN_004ab500_shell *>((source))->GetModSlotStat(1));
        reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(2, reinterpret_cast<::FUN_004ab500_shell *>((source))->GetModSlotStat(2));
        reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(3, reinterpret_cast<::FUN_004ab500_shell *>((source))->GetModSlotStat(3));
        reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(4, reinterpret_cast<::FUN_004ab500_shell *>((source))->GetModSlotStat(4));
        reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(5, reinterpret_cast<::FUN_004ab500_shell *>((source))->GetModSlotStat(5));
        reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(6, reinterpret_cast<::FUN_004ab500_shell *>((source))->GetModSlotStat(6));
        reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(7, reinterpret_cast<::FUN_004ab500_shell *>((source))->GetModSlotStat(7));
        reinterpret_cast<::TESObjectWEAP *>(this)->SetModItem(1, ((::TESObjectIMOD *)(reinterpret_cast<::FUN_004bd570_this *>((source))->FUN_004bd570(1))));
        reinterpret_cast<::TESObjectWEAP *>(this)->SetModItem(2, ((::TESObjectIMOD *)(reinterpret_cast<::FUN_004bd570_this *>((source))->FUN_004bd570(2))));
        reinterpret_cast<::TESObjectWEAP *>(this)->SetModItem(4, ((::TESObjectIMOD *)(reinterpret_cast<::FUN_004bd570_this *>((source))->FUN_004bd570(4))));
        m_kWeaponModTextureSwap1.CopyFromBase(&source->m_kWeaponModTextureSwap1);
        m_kWeaponModTextureSwap2.CopyFromBase(&source->m_kWeaponModTextureSwap2);
        m_kWeaponModTextureSwap3.CopyFromBase(&source->m_kWeaponModTextureSwap3);
        m_kWeaponModTextureSwap4.CopyFromBase(&source->m_kWeaponModTextureSwap4);
        m_kWeaponModTextureSwap5.CopyFromBase(&source->m_kWeaponModTextureSwap5);
        m_kWeaponModTextureSwap6.CopyFromBase(&source->m_kWeaponModTextureSwap6);
        m_kWeaponModTextureSwap7.CopyFromBase(&source->m_kWeaponModTextureSwap7);
        memcpy(&data, &source->data, sizeof(data));
        memcpy(&m_kCriticalData, &source->m_kCriticalData, sizeof(m_kCriticalData));
        memcpy(&m_kVATSData, &source->m_kVATSData, sizeof(m_kVATSData));
        reinterpret_cast<::FUN_005215d0_shell *>(this)->FUN_005215d0(reinterpret_cast<::FUN_005215a0_shell *>((source))->FUN_005215a0(false));
        reinterpret_cast<::FUN_005215f0_shell *>(this)->FUN_005215f0(((::TESSound *)(reinterpret_cast<::FUN_00522440_shell *>((source))->GetValueByFlag(false))));
        reinterpret_cast<::MiddleHighProcess *>(this)->SetBoundingBox((::BSBound *)(::TESSound *)(((::TESSound *)(reinterpret_cast<::S_00522470 *>((source))->GetPointerByFlag(false)))));
        reinterpret_cast<::FUN_00521650_shell *>(this)->FUN_00521650(((::TESSound *)(reinterpret_cast<::FUN_008bffa0_shell *>((source))->GetField228())));
        SetMeleeBlockSound(((::TESSound *)(reinterpret_cast<::FUN_005224e0_class *>((source))->GetField230())));
        reinterpret_cast<::FUN_00521670_shell *>(this)->FUN_00521670(((::TESSound *)(reinterpret_cast<::FUN_005224c0_Class *>((source))->GetField22C())));
        reinterpret_cast<::FUN_005216b0_shell *>(this)->FUN_005216b0(((::TESSound *)(reinterpret_cast<::FUN_00522500_shell *>((source))->GetField234())));
        reinterpret_cast<::FUN_005216d0_shell *>(this)->FUN_005216d0(((::TESSound *)(reinterpret_cast<::FUN_00522520_shell *>((source))->GetField238())));
        reinterpret_cast<::FUN_005216f0_shell *>(this)->FUN_005216f0(((::TESSound *)(reinterpret_cast<::FUN_00522540_shell *>((source))->GetField23C())));
        reinterpret_cast<::FUN_00521610_shell *>(this)->FUN_00521610(((::TESSound *)(reinterpret_cast<::MiddleHighProcess *>((source))->RefreshActorRuntimeData())));
        reinterpret_cast<::MiddleHighProcess *>(this)->SetKnockdownStage((int)(((::TESSound *)(reinterpret_cast<::FUN_008d8a60_Class *>((source))->GetField244()))));
        reinterpret_cast<::MiddleHighProcess *>(this)->AttachFaceGenerationNode((::BSFaceGenNiNode *)(::TESSound *)(((::TESSound *)(reinterpret_cast<::MiddleHighProcess *>((source))->GetFacialAnimationNode()))));
        m_eSoundLevel = source->FUN_00522560(false);
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(source->FUN_00401170());
    }
}

struct FUN_00522d80_virtual_object {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual char* v05();
};

struct FUN_00522d80_shell {
    unsigned char field00[0x3C];
    FUN_00522d80_virtual_object field3C;
    unsigned char field40[0x1C0];
    FUN_00522d80_virtual_object field200;

    FUN_00522d80_virtual_object* FUN_00522d80();
};

// Returns field200 if its v05()[0] is nonzero, otherwise returns field3C (or null if this is null).
// @fnv 0x00522d80
FUN_00522d80_virtual_object* FUN_00522d80_shell::FUN_00522d80() {
    FUN_00522d80_virtual_object* result = 0;

    if (field200.v05()[0] != 0) {
        result = &field200;
    }

    if (result == 0) {
        result = this ? &field3C : 0;
    }

    return result;
}

struct ConversionTag {};
struct ResetAccess {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fieldB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    void FUN_00520ff0();
};
// Reads a weapon record from the file: validates form type 40, then dispatches each chunk to its loader and fixes up invalid weapon data.
// @fnv 0x0051f630
bool TESObjectWEAP::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if(formType != 40) return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    CHUNK_ID chunk;
    while((chunk = (CHUNK_ID)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0) {
        switch(chunk) {
        case 0x44494445: // EDID
        {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID),512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f: // OBND
        {
            readOBNDSubRecord(file);
            break;
        }
        case 0x4c4c5546: // FULL
        {
            ::ReadFullName(this,file);
            break;
        }
        case 0x44444f4d: // MODD
        case 0x44534f4d: // MOSD
        case 0x4c444f4d: // MODL
        case 0x54444f4d: // MODT
        {
            TESModel::LoadModelData(this,file);
            break;
        }
        case 0x53444f4d: // MODS
        {
            unsigned int textureSwapSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            void* textureSwaps = _alloca(textureSwapSize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureSwaps),textureSwapSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureSwaps,textureSwapSize,reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570());
            break;
        }
        case 0x4e4f4349: // ICON
        {
            TESTexture::ReadTextureData(this,file);
            break;
        }
        case 0x4f43494d: // MICO
        {
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this),file);
            break;
        }
        case 0x49524353: // SCRI
        {
            Script* script = (Script*)0;
            file->GetChunkData((unsigned int*)&script);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(script));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x4d544945: // EITM
        case 0x4d414e45: // ENAM
        {
            EnchantmentItem* enchantment = (EnchantmentItem*)0;
            file->GetChunkData((unsigned int*)&enchantment);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(enchantment));
            break;
        }
        case 0x4d414e41: // ANAM
        case 0x544d4145: // EAMT
        {
            unsigned short enchantmentAmount = 0;
            reinterpret_cast<::FUN_00472840_impl *>((((TESFileChunkData16*)file)))->ReadChunkData(&enchantmentAmount);
            reinterpret_cast<::TESEnchantableForm *>(this)->SetFormEnchantmentAmount(enchantmentAmount);
            break;
        }
        case 0x304d414e: // NAM0
        {
            TESAmmo* ammo = (TESAmmo*)0;
            file->GetChunkData((unsigned int*)&ammo);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(ammo));
            break;
        }
        case 0x44545344: // DSTD
        case 0x54534544: // DEST
        {
            ::FUN_004781e0(this,file);
            break;
        }
        case 0x4c504552: // REPL
        {
            BGSListForm* repairList = (BGSListForm*)0;
            file->GetChunkData((unsigned int*)&repairList);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(repairList));
            break;
        }
        case 0x50595445: // ETYP
        {
            BGSEquipType__EQUIP_TYPE equipType = (BGSEquipType__EQUIP_TYPE)0;
            file->GetChunkData((unsigned int*)&equipType);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((*(::CombatController * *)&(equipType)));
            break;
        }
        case 0x4c504942: // BIPL
        {
            BGSListForm* bipedList = (BGSListForm*)0;
            file->GetChunkData((unsigned int*)&bipedList);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(bipedList));
            break;
        }
        case 0x4d414e59: // YNAM
        {
            TESSound* pickupSound = (TESSound*)0;
            file->GetChunkData((unsigned int*)&pickupSound);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(pickupSound));
            break;
        }
        case 0x4d414e5a: // ZNAM
        {
            TESSound* putdownSound = (TESSound*)0;
            file->GetChunkData((unsigned int*)&putdownSound);
            reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(putdownSound));
            break;
        }
        case 0x41544144: // DATA
        {
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file,0,0);
            break;
        }
        case 0x4d414e44: // DNAM
        {
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 12) {
                memset(&data,0,sizeof(data));
                data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
                data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data),reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                if(file->IsEndianConversionRequired()) reinterpret_cast<::ResetAccess *>(&(data))->FUN_00520ff0();
                if(data.m_ucAttackAnimation < 168 && data.m_ucAttackAnimation >= 56) {
                    data.m_ucAttackAnimation += 18;
                    if(data.m_ucAttackAnimation < 168 && data.m_ucAttackAnimation >= 86) data.m_ucAttackAnimation += 6;
                }
            } else if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 14) {
                memset(&data,0,sizeof(data));
                data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
                data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data),reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                if(file->IsEndianConversionRequired()) reinterpret_cast<::ResetAccess *>(&(data))->FUN_00520ff0();
                if(data.m_ucAttackAnimation < 168 && data.m_ucAttackAnimation >= 86) data.m_ucAttackAnimation += 6;
            } else {
                memset(&data,0,sizeof(data));
                data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
                data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data),sizeof(data));
                if(file->IsEndianConversionRequired()) reinterpret_cast<::ResetAccess *>(&(data))->FUN_00520ff0();
                if(data.m_fLimbDamageMultiplier <= 0.0) data.m_fLimbDamageMultiplier = 1.0f;
                switch(data.m_ucGripAnimation) {
                case 230: case 231: case 232: case 233: case 234: case 235: case 255: break;
                default: data.m_ucGripAnimation = 255; break;
                }
                if(!::FUN_0047f060((*(int *)&(data.m_eWeaponSkill)))) data.m_eWeaponSkill = (ActorValue__Index)45;
                if(!FUN_0066eba0(data.m_eResistanceType) && data.m_eResistanceType != -1) data.m_eResistanceType = (ActorValue__Index)-1;
            }
            break;
        }
        case 0x4d414e57: // WNAM
        {
            TESObjectSTAT* firstPersonObject0 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject0);
            reinterpret_cast<::MiddleHighProcess *>(this)->SetAnimationNode((::NiAVObject *)(firstPersonObject0));
            break;
        }
        case 0x314d4e57: // WNM1
        {
            TESObjectSTAT* firstPersonObject1 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject1);
            reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(1,firstPersonObject1);
            break;
        }
        case 0x324d4e57: // WNM2
        {
            TESObjectSTAT* firstPersonObject2 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject2);
            reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(2,firstPersonObject2);
            break;
        }
        case 0x334d4e57: // WNM3
        {
            TESObjectSTAT* firstPersonObject3 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject3);
            reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(3,firstPersonObject3);
            break;
        }
        case 0x344d4e57: // WNM4
        {
            TESObjectSTAT* firstPersonObject4 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject4);
            reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(4,firstPersonObject4);
            break;
        }
        case 0x354d4e57: // WNM5
        {
            TESObjectSTAT* firstPersonObject5 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject5);
            reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(5,firstPersonObject5);
            break;
        }
        case 0x364d4e57: // WNM6
        {
            TESObjectSTAT* firstPersonObject6 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject6);
            reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(6,firstPersonObject6);
            break;
        }
        case 0x374d4e57: // WNM7
        {
            TESObjectSTAT* firstPersonObject7 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject7);
            reinterpret_cast<::FUN_005214d0_shell *>(this)->SetFirstPersonModObject(7,firstPersonObject7);
            break;
        }
        case 0x31494d57: // WMI1
        {
            TESObjectIMOD* modItem1 = 0;
            file->GetChunkData((unsigned int*)&modItem1);
            reinterpret_cast<::TESObjectWEAP *>(this)->SetModItem(1,modItem1);
            break;
        }
        case 0x32494d57: // WMI2
        {
            TESObjectIMOD* modItem2 = 0;
            file->GetChunkData((unsigned int*)&modItem2);
            reinterpret_cast<::TESObjectWEAP *>(this)->SetModItem(2,modItem2);
            break;
        }
        case 0x33494d57: // WMI3
        {
            TESObjectIMOD* modItem3 = 0;
            file->GetChunkData((unsigned int*)&modItem3);
            reinterpret_cast<::TESObjectWEAP *>(this)->SetModItem(4,modItem3);
            break;
        }
        case 0x314d414e: // NAM1
        case 0x32444f4d: // MOD2
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath0 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath0),0);
                m_kModel.SetModelFilePath(modelPath0);
            } else m_kModel.SetModelFilePath(0);
            break;
        }
        case 0x54324f4d: // MO2T
        {
            ::FUN_004893e0(&m_kModel,file);
            break;
        }
        case 0x33444f4d: // MOD3
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath1 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath1),0);
                m_kModel1stPerson.SetModelFilePath(modelPath1);
            } else m_kModel1stPerson.SetModelFilePath(0);
            break;
        }
        case 0x54334f4d: // MO3T
        {
            ::FUN_004893e0(&m_kModel1stPerson,file);
            break;
        }
        case 0x34444f4d: // MOD4
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath2 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath2),0);
                m_kModel3rdPerson.SetModelFilePath(modelPath2);
            } else m_kModel3rdPerson.SetModelFilePath(0);
            break;
        }
        case 0x54344f4d: // MO4T
        {
            ::FUN_004893e0(&m_kModel3rdPerson,file);
            break;
        }
        case 0x3144574d: // MWD1
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath3 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath3),0);
                m_kWeaponModTextureSwap1.SetModelFilePath(modelPath3);
            } else m_kWeaponModTextureSwap1.SetModelFilePath(0);
            break;
        }
        case 0x3154574d: // MWT1
        {
            ::FUN_004893e0(&m_kWeaponModTextureSwap1,file);
            break;
        }
        case 0x3244574d: // MWD2
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath4 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath4),0);
                m_kWeaponModTextureSwap2.SetModelFilePath(modelPath4);
            } else m_kWeaponModTextureSwap2.SetModelFilePath(0);
            break;
        }
        case 0x3254574d: // MWT2
        {
            ::FUN_004893e0(&m_kWeaponModTextureSwap2,file);
            break;
        }
        case 0x3444574d: // MWD4
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath5 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath5),0);
                m_kWeaponModTextureSwap3.SetModelFilePath(modelPath5);
            } else m_kWeaponModTextureSwap3.SetModelFilePath(0);
            break;
        }
        case 0x3454574d: // MWT4
        {
            ::FUN_004893e0(&m_kWeaponModTextureSwap3,file);
            break;
        }
        case 0x3344574d: // MWD3
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath6 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath6),0);
                m_kWeaponModTextureSwap4.SetModelFilePath(modelPath6);
            } else m_kWeaponModTextureSwap4.SetModelFilePath(0);
            break;
        }
        case 0x3354574d: // MWT3
        {
            ::FUN_004893e0(&m_kWeaponModTextureSwap4,file);
            break;
        }
        case 0x3544574d: // MWD5
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath7 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath7),0);
                m_kWeaponModTextureSwap5.SetModelFilePath(modelPath7);
            } else m_kWeaponModTextureSwap5.SetModelFilePath(0);
            break;
        }
        case 0x3554574d: // MWT5
        {
            ::FUN_004893e0(&m_kWeaponModTextureSwap5,file);
            break;
        }
        case 0x3644574d: // MWD6
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath8 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath8),0);
                m_kWeaponModTextureSwap6.SetModelFilePath(modelPath8);
            } else m_kWeaponModTextureSwap6.SetModelFilePath(0);
            break;
        }
        case 0x3654574d: // MWT6
        {
            ::FUN_004893e0(&m_kWeaponModTextureSwap6,file);
            break;
        }
        case 0x3744574d: // MWD7
        {
            if(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()) {
                char* modelPath9 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(modelPath9),0);
                m_kWeaponModTextureSwap7.SetModelFilePath(modelPath9);
            } else m_kWeaponModTextureSwap7.SetModelFilePath(0);
            break;
        }
        case 0x3754574d: // MWT7
        {
            ::FUN_004893e0(&m_kWeaponModTextureSwap7,file);
            break;
        }
        case 0x44534645: // EFSD
        {
            TESEffectShader* scopeEffect = 0;
            file->GetChunkData((unsigned int*)&scopeEffect);
            reinterpret_cast<::FUN_0051f570_shell *>(this)->SetEffectShader(scopeEffect);
            break;
        }
        case 0x4d414e4e: // NNAM
        {
            char* embeddedWeaponNodeText = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(embeddedWeaponNodeText),0);
            reinterpret_cast<::TextString *>(&(m_kEmbeddedWeaponNodeName))->FUN_004037f0(embeddedWeaponNodeText,0);
            break;
        }
        case 0x4d4e4156: // VANM
        {
            char* vATSAttackNameText = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(vATSAttackNameText),0);
            reinterpret_cast<::TextString *>(&(VATSAttackName))->FUN_004037f0(vATSAttackNameText,0);
            break;
        }
        case 0x54445243: // CRDT
        {
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kCriticalData),sizeof(m_kCriticalData));
            if(file->IsEndianConversionRequired()) reinterpret_cast<::FUN_00535aa0_Class *>(&(m_kCriticalData))->FUN_00535aa0();
            break;
        }
        case 0x53544156: // VATS
        {
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kVATSData),sizeof(m_kVATSData));
            if(file->IsEndianConversionRequired()) reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>(&(m_kVATSData))->FUN_0067ff10();
            break;
        }
        case 0x4d414e49: // INAM
        {
            BGSImpactDataSet* impactDataSet = 0;
            file->GetChunkData((unsigned int*)&impactDataSet);
            reinterpret_cast<::MiddleHighProcess *>(this)->SetFaceGenHeadNode((::BSFaceGenNiNode *)(impactDataSet));
            break;
        }
        case 0x4d414e53: // SNAM
        {
            TESSound* attackSound = 0;
            file->GetChunkData((unsigned int*)&attackSound);
            if(reinterpret_cast<::FUN_005215a0_shell *>(this)->FUN_005215a0(false)) reinterpret_cast<::FUN_005215f0_shell *>(this)->FUN_005215f0(attackSound);
            else reinterpret_cast<::FUN_005215d0_shell *>(this)->FUN_005215d0(attackSound);
            break;
        }
        case 0x4d414e58: // XNAM
        {
            TESSound* attackSound2 = 0;
            file->GetChunkData((unsigned int*)&attackSound2);
            reinterpret_cast<::MiddleHighProcess *>(this)->SetBoundingBox((::BSBound *)(attackSound2));
            break;
        }
        case 0x374d414e: // NAM7
        {
            TESSound* attackLoop = 0;
            file->GetChunkData((unsigned int*)&attackLoop);
            reinterpret_cast<::FUN_00521650_shell *>(this)->FUN_00521650(attackLoop);
            break;
        }
        case 0x4d414e54: // TNAM
        {
            TESSound* attackFail = 0;
            file->GetChunkData((unsigned int*)&attackFail);
            reinterpret_cast<::FUN_00521670_shell *>(this)->FUN_00521670(attackFail);
            break;
        }
        case 0x364d414e: // NAM6
        {
            TESSound* meleeBlock = 0;
            file->GetChunkData((unsigned int*)&meleeBlock);
            SetMeleeBlockSound(meleeBlock);
            break;
        }
        case 0x4d414e55: // UNAM
        {
            TESSound* idleSound = 0;
            file->GetChunkData((unsigned int*)&idleSound);
            reinterpret_cast<::FUN_005216b0_shell *>(this)->FUN_005216b0(idleSound);
            break;
        }
        case 0x394d414e: // NAM9
        {
            TESSound* equipSound = 0;
            file->GetChunkData((unsigned int*)&equipSound);
            reinterpret_cast<::FUN_005216d0_shell *>(this)->FUN_005216d0(equipSound);
            break;
        }
        case 0x384d414e: // NAM8
        {
            TESSound* unequipSound = 0;
            file->GetChunkData((unsigned int*)&unequipSound);
            reinterpret_cast<::FUN_005216f0_shell *>(this)->FUN_005216f0(unequipSound);
            break;
        }
        case 0x31534d57: // WMS1
        {
            TESSound* modAttackSound = 0;
            file->GetChunkData((unsigned int*)&modAttackSound);
            if(((::TESSound *)(reinterpret_cast<::MiddleHighProcess *>(this)->RefreshActorRuntimeData()))) reinterpret_cast<::MiddleHighProcess *>(this)->SetKnockdownStage((int)(modAttackSound));
            else reinterpret_cast<::FUN_00521610_shell *>(this)->FUN_00521610(modAttackSound);
            break;
        }
        case 0x32534d57: // WMS2
        {
            TESSound* modDistantAttackSound = 0;
            file->GetChunkData((unsigned int*)&modDistantAttackSound);
            reinterpret_cast<::MiddleHighProcess *>(this)->AttachFaceGenerationNode((::BSFaceGenNiNode *)(modDistantAttackSound));
            break;
        }
        case 0x4d414e56: // VNAM
        {
            unsigned int soundLevel;
            file->GetChunkData(&soundLevel);
            if(soundLevel > 3) m_eSoundLevel = SOUND_LEVEL_SOUND_LEVEL_NORMAL;
            else m_eSoundLevel = (SOUND_LEVEL)soundLevel;
            break;
        }
        }
        if(!file->NextChunk()) break;
    }
    if(!GetDamageForActor(false,true,0) && ((::BGSProjectile *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(0))))) reinterpret_cast<::FUN_00521580_shell *>(this)->FUN_00521580(1);
    if(data.eType >= 14) {
        ::FUN_005b5e40();
        data.eType = 0;
    }
    return true;
}
// @fnv 0x00521730
void Weapon::Save()
{
    UInt32 savedProj;
    UInt32 savedVats;
    UInt32 savedCrit;

    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(&(fullName))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>(&(model))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::FUN_00489240_Class *>(&(model))->FUN_00489240(0x44444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(&(icon))->FUN_0048e370(0x4e4f4349);
    reinterpret_cast<::FUN_0047a240_shell *>(&(messageIcon))->FUN_0047a240(0x4f43494d);
    reinterpret_cast<::S_0048cca0 *>(&(script))->FUN_0048cca0();
    reinterpret_cast<::FUN_0047bd70_shell *>(&(enchant))->FUN_0047bd70();
    reinterpret_cast<::Shell474af0 *>(&(value))->FUN_00474af0();
    reinterpret_cast<::FUN_00477f20_shell *>(&(weight))->FUN_00477f20();
    reinterpret_cast<::S0047b8a0 *>(&(health))->FUN_0047b8a0();
    reinterpret_cast<::FUN_00479350_shell *>(&(damage))->FUN_00479350();
    reinterpret_cast<::FUN_00474d60_shell *>(&(ammo))->FUN_00474d60();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>(&(clip))->LogFormIDs();
    reinterpret_cast<::FUN_004891d0_cls *>(&(shellModel))->WriteToBuffer((char *)(0x32444f4d), (void *)(0x54324f4d));
    if (reinterpret_cast<::FUN_004ad010_shell *>(this)->IsFlag4Set()) {
        reinterpret_cast<::FUN_004891d0_cls *>(&(scopeModel))->WriteToBuffer((char *)(0x33444f4d), (void *)(0x54334f4d));
        if (m_pWeaponEffectShader) {
            UInt32 a = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWeaponEffectShader))->FUN_0084e3a0()));
            ::FUN_00485910(0x44534645, a);
        }
    }
    reinterpret_cast<::FUN_004891d0_cls *>(&(worldModel))->WriteToBuffer((char *)(0x34444f4d), (void *)(0x54344f4d));
    reinterpret_cast<::FUN_0048a520_shell *>(&(mod1))->ProcessAndFreeData(0x3144574d, 0x3154574d, 0x53444f4d);
    reinterpret_cast<::FUN_0048a520_shell *>(&(mod2))->ProcessAndFreeData(0x3244574d, 0x3254574d, 0x53444f4d);
    reinterpret_cast<::FUN_0048a520_shell *>(&(mod3))->ProcessAndFreeData(0x3444574d, 0x3454574d, 0x53444f4d);
    reinterpret_cast<::FUN_0048a520_shell *>(&(mod12))->ProcessAndFreeData(0x3344574d, 0x3354574d, 0x53444f4d);
    reinterpret_cast<::FUN_0048a520_shell *>(&(mod13))->ProcessAndFreeData(0x3544574d, 0x3554574d, 0x53444f4d);
    reinterpret_cast<::FUN_0048a520_shell *>(&(mod23))->ProcessAndFreeData(0x3644574d, 0x3654574d, 0x53444f4d);
    reinterpret_cast<::FUN_0048a520_shell *>(&(mod123))->ProcessAndFreeData(0x3744574d, 0x3754574d, 0x53444f4d);
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(embeddedNode))->FUN_004048e0())))
        ::FUN_004856f0((void *)(0x4d414e4e), (void *)(((const char *)(::FUN_00559450((int *)&(embeddedNode))))), (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(embeddedNode))->FUN_004048e0())) + 1));
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(vatsAttackName))->FUN_004048e0())))
        ::FUN_004856f0((void *)(0x4d4e4156), (void *)(((const char *)(::FUN_00559450((int *)&(vatsAttackName))))), (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(vatsAttackName))->FUN_004048e0())) + 1));
    if (pImpact) { UInt32 b = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pImpact))->FUN_0084e3a0())); ::FUN_00485910(0x4d414e49, b); }
    if (p1st) { UInt32 c = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st))->FUN_0084e3a0())); ::FUN_00485910(0x4d414e57, c); }
    if (p1st1) { UInt32 d = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st1))->FUN_0084e3a0())); ::FUN_00485910(0x314d4e57, d); }
    if (p1st2) { UInt32 e = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st2))->FUN_0084e3a0())); ::FUN_00485910(0x324d4e57, e); }
    if (p1st3) { UInt32 f = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st3))->FUN_0084e3a0())); ::FUN_00485910(0x344d4e57, f); }
    if (p1st12) { UInt32 g = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st12))->FUN_0084e3a0())); ::FUN_00485910(0x334d4e57, g); }
    if (p1st23) { UInt32 h = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st23))->FUN_0084e3a0())); ::FUN_00485910(0x364d4e57, h); }
    if (p1st13) { UInt32 i = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st13))->FUN_0084e3a0())); ::FUN_00485910(0x354d4e57, i); }
    if (p1st123) { UInt32 j = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p1st123))->FUN_0084e3a0())); ::FUN_00485910(0x374d4e57, j); }
    if (pMod1) { UInt32 k = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pMod1))->FUN_0084e3a0())); ::FUN_00485910(0x31494d57, k); }
    if (pMod2) { UInt32 l = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pMod2))->FUN_0084e3a0())); ::FUN_00485910(0x32494d57, l); }
    if (pMod3) { UInt32 m = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pMod3))->FUN_0084e3a0())); ::FUN_00485910(0x33494d57, m); }
    if (m_pWeaponSound1) { UInt32 n = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWeaponSound1))->FUN_0084e3a0())); ::FUN_00485910(0x4d414e53, n); }
    if (m_pWeaponSound2) { UInt32 o = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWeaponSound2))->FUN_0084e3a0())); ::FUN_00485910(0x4d414e53, o); }
    if (m_pWeaponSound3) { UInt32 p = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWeaponSound3))->FUN_0084e3a0())); ::FUN_00485910(0x4d414e58, p); }
    if (m_pWeaponSound4) { UInt32 q = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWeaponSound4))->FUN_0084e3a0())); ::FUN_00485910(0x374d414e, q); }
    if (pAttackFail) { UInt32 r = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pAttackFail))->FUN_0084e3a0())); ::FUN_00485910(0x4d414e54, r); }
    if (pMeleeBlock) { UInt32 s = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pMeleeBlock))->FUN_0084e3a0())); ::FUN_00485910(0x364d414e, s); }
    if (m_pIdleForm) { UInt32 t = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pIdleForm))->FUN_0084e3a0())); ::FUN_00485910(0x4d414e55, t); }
    if (pEquip) { UInt32 u = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pEquip))->FUN_0084e3a0())); ::FUN_00485910(0x394d414e, u); }
    if (pUnEquip) { UInt32 v = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pUnEquip))->FUN_0084e3a0())); ::FUN_00485910(0x384d414e, v); }
    if (pSilenced) { UInt32 w = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSilenced))->FUN_0084e3a0())); ::FUN_00485910(0x31534d57, w); }
    if (pSilenced2) { UInt32 x = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSilenced2))->FUN_0084e3a0())); ::FUN_00485910(0x31534d57, x); }
    if (pSilenced2D) { UInt32 y = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSilenced2D))->FUN_0084e3a0())); ::FUN_00485910(0x32534d57, y); }

    reinterpret_cast<::FUN_00485e00_shell *>(this)->FUN_00485e00();

    savedCrit = (UInt32)data.pProjectile;
    data.pProjectile = (TESForm*)(data.pProjectile ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((data.pProjectile))->FUN_0084e3a0())) : 0);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::ResetAccess *>(&(data))->FUN_00520ff0();
    ::AppendChunk(0x4d414e44, &data, 0xcc);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::ResetAccess *>(&(data))->FUN_00520ff0();

    savedProj = (UInt32)crit.pEffect;
    crit.pEffect = (TESForm*)(crit.pEffect ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((crit.pEffect))->FUN_0084e3a0())) : 0);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00535aa0_Class *>(&(crit))->FUN_00535aa0();
    ::AppendChunk(0x54445243, &crit, 0x10);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00535aa0_Class *>(&(crit))->FUN_00535aa0();

    savedVats = (UInt32)vats.pEffect;
    vats.pEffect = (TESForm*)(vats.pEffect ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((vats.pEffect))->FUN_0084e3a0())) : 0);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>(&(vats))->FUN_0067ff10();
    ::AppendChunk(0x53544156, &vats, 0x14);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>(&(vats))->FUN_0067ff10();

    ::FUN_00485910(0x4d414e56, soundLevel);

    data.pProjectile = (TESForm*)savedCrit;
    crit.pEffect = (TESForm*)savedProj;
    vats.pEffect = (TESForm*)savedVats;
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}
// Calls SwapField on most of the object's int fields, skipping field00, field0C, field20, field24, field28, fieldA4 and fieldAC.
// @fnv 0x00520ff0
void ResetAccess::FUN_00520ff0() {
    ::FUN_00401080(&field04);
    ::FUN_00401080(&field08);
    ::FUN_00401080(&field10);
    ::FUN_00401080(&field14);
    ::FUN_00401080(&field18);
    ::FUN_00401080(&field1C);
    ::FUN_00401080(&field2C);
    ::FUN_00401080(&field30);
    ::FUN_00401080(&field34);
    ::FUN_00401080(&field38);
    ::FUN_00401080(&field3C);
    ::FUN_00401080(&field40);
    ::FUN_00401080(&field44);
    ::FUN_00401080(&field48);
    ::FUN_00401080(&field4C);
    ::FUN_00401080(&field50);
    ::FUN_00401080(&field54);
    ::FUN_00401080(&field58);
    ::FUN_00401080(&field5C);
    ::FUN_00401080(&field60);
    ::FUN_00401080(&field64);
    ::FUN_00401080(&field68);
    ::FUN_00401080(&field6C);
    ::FUN_00401080(&field70);
    ::FUN_00401080(&field74);
    ::FUN_00401080(&field78);
    ::FUN_00401080(&field7C);
    ::FUN_00401080(&field80);
    ::FUN_00401080(&field84);
    ::FUN_00401080(&field88);
    ::FUN_00401080(&field8C);
    ::FUN_00401080(&field90);
    ::FUN_00401080(&field94);
    ::FUN_00401080(&field98);
    ::FUN_00401080(&field9C);
    ::FUN_00401080(&fieldA0);
    ::FUN_00401080(&fieldA8);
    ::FUN_00401080(&fieldC8);
    ::FUN_00401080(&fieldB0);
    ::FUN_00401080(&fieldB4);
    ::FUN_00401080(&fieldB8);
    ::FUN_00401080(&fieldBC);
    ::FUN_00401080(&fieldC0);
    ::FUN_00401080(&fieldC4);
}

struct WeaponCompareAccess : TESObjectWEAP {
    bool IsDifferentFrom(TESForm*);
};
struct WeaponStringCompare {
};
// Compares this weapon against another TESObjectWEAP across many fields and accessors, returning true on the first difference or when the form is not a weapon.
// @fnv 0x00522590
bool WeaponCompareAccess::IsDifferentFrom(TESForm* form) {
    WeaponCompareAccess* other = (WeaponCompareAccess*)dynamic_cast<TESObjectWEAP*>(form);
    if (!other) return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(other)) return true;
    if (m_kModel.CompareWithBase(&other->m_kModel)) return true;
    if (m_kModel3rdPerson.CompareWithBase(&other->m_kModel3rdPerson)) return true;
    if (m_kWeaponModTextureSwap1.CompareWithBase(&other->m_kWeaponModTextureSwap1)) return true;
    if (m_kWeaponModTextureSwap2.CompareWithBase(&other->m_kWeaponModTextureSwap2)) return true;
    if (m_kWeaponModTextureSwap3.CompareWithBase(&other->m_kWeaponModTextureSwap3)) return true;
    if (m_kWeaponModTextureSwap4.CompareWithBase(&other->m_kWeaponModTextureSwap4)) return true;
    if (m_kWeaponModTextureSwap5.CompareWithBase(&other->m_kWeaponModTextureSwap5)) return true;
    if (m_kWeaponModTextureSwap6.CompareWithBase(&other->m_kWeaponModTextureSwap6)) return true;
    if (m_kWeaponModTextureSwap7.CompareWithBase(&other->m_kWeaponModTextureSwap7)) return true;
    if (m_kModel1stPerson.CompareWithBase(&other->m_kModel1stPerson)) return true;
    if (((::TESEffectShader *)(reinterpret_cast<::TESDataHandler *>(this)->GetCompiledFileCount())) != ((::TESEffectShader *)(reinterpret_cast<::TESDataHandler *>((other))->GetCompiledFileCount()))) return true;
    if (((void *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetFaceGenHeadNode())) != ((void *)(reinterpret_cast<::MiddleHighProcess *>((other))->GetFaceGenHeadNode()))) return true;
    if (((void *)(reinterpret_cast<::MiddleHighProcess *>(this)->GetAnimationObject())) != ((void *)(reinterpret_cast<::MiddleHighProcess *>((other))->GetAnimationObject()))) return true;
    if (((void *)(reinterpret_cast<::FUN_004ab500_shell *>(this)->GetModSlotStat(1))) != ((void *)(reinterpret_cast<::FUN_004ab500_shell *>((other))->GetModSlotStat(1)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004ab500_shell *>(this)->GetModSlotStat(2))) != ((void *)(reinterpret_cast<::FUN_004ab500_shell *>((other))->GetModSlotStat(2)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004ab500_shell *>(this)->GetModSlotStat(3))) != ((void *)(reinterpret_cast<::FUN_004ab500_shell *>((other))->GetModSlotStat(3)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004ab500_shell *>(this)->GetModSlotStat(4))) != ((void *)(reinterpret_cast<::FUN_004ab500_shell *>((other))->GetModSlotStat(4)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004ab500_shell *>(this)->GetModSlotStat(5))) != ((void *)(reinterpret_cast<::FUN_004ab500_shell *>((other))->GetModSlotStat(5)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004ab500_shell *>(this)->GetModSlotStat(6))) != ((void *)(reinterpret_cast<::FUN_004ab500_shell *>((other))->GetModSlotStat(6)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004ab500_shell *>(this)->GetModSlotStat(7))) != ((void *)(reinterpret_cast<::FUN_004ab500_shell *>((other))->GetModSlotStat(7)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004bd570_this *>(this)->FUN_004bd570(1))) != ((void *)(reinterpret_cast<::FUN_004bd570_this *>((other))->FUN_004bd570(1)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004bd570_this *>(this)->FUN_004bd570(2))) != ((void *)(reinterpret_cast<::FUN_004bd570_this *>((other))->FUN_004bd570(2)))) return true;
    if (((void *)(reinterpret_cast<::FUN_004bd570_this *>(this)->FUN_004bd570(4))) != ((void *)(reinterpret_cast<::FUN_004bd570_this *>((other))->FUN_004bd570(4)))) return true;
    if (reinterpret_cast<::FUN_00501c90_shell *>((((WeaponStringCompare*)&m_kEmbeddedWeaponNodeName)))->CompareString(&other->m_kEmbeddedWeaponNodeName, true)) return true;
    if (reinterpret_cast<::FUN_00501c90_shell *>((((WeaponStringCompare*)&VATSAttackName)))->CompareString(&other->VATSAttackName, true)) return true;
    if (memcmp(&data, reinterpret_cast<::FUN_006e4fb0_shell *>((other))->GetOffsetF4(), 0xcc)) return true;
    if (memcmp(&m_kCriticalData, &other->m_kCriticalData, 0x10)) return true;
    if (memcmp(&m_kVATSData, &other->m_kVATSData, 0x14)) return true;
    if (reinterpret_cast<::FUN_005215a0_shell *>(this)->FUN_005215a0(false) != reinterpret_cast<::FUN_005215a0_shell *>((other))->FUN_005215a0(false)) return true;
    if (reinterpret_cast<::FUN_00522440_shell *>(this)->GetValueByFlag(false) != reinterpret_cast<::FUN_00522440_shell *>((other))->GetValueByFlag(false)) return true;
    if (((int)(reinterpret_cast<::S_00522470 *>(this)->GetPointerByFlag(false))) != ((int)(reinterpret_cast<::S_00522470 *>((other))->GetPointerByFlag(false)))) return true;
    if (reinterpret_cast<::FUN_008bffa0_shell *>(this)->GetField228() != reinterpret_cast<::FUN_008bffa0_shell *>((other))->GetField228()) return true;
    if (((int)(reinterpret_cast<::FUN_005224c0_Class *>(this)->GetField22C())) != ((int)(reinterpret_cast<::FUN_005224c0_Class *>((other))->GetField22C()))) return true;
    if (((int)(reinterpret_cast<::FUN_005224e0_class *>(this)->GetField230())) != ((int)(reinterpret_cast<::FUN_005224e0_class *>((other))->GetField230()))) return true;
    if (((int)(reinterpret_cast<::FUN_00522500_shell *>(this)->GetField234())) != ((int)(reinterpret_cast<::FUN_00522500_shell *>((other))->GetField234()))) return true;
    if (reinterpret_cast<::FUN_00522520_shell *>(this)->GetField238() != reinterpret_cast<::FUN_00522520_shell *>((other))->GetField238()) return true;
    if (reinterpret_cast<::FUN_00522540_shell *>(this)->GetField23C() != reinterpret_cast<::FUN_00522540_shell *>((other))->GetField23C()) return true;
    if (((::TESSound *)(reinterpret_cast<::MiddleHighProcess *>(this)->RefreshActorRuntimeData())) != ((::TESSound *)(reinterpret_cast<::MiddleHighProcess *>((other))->RefreshActorRuntimeData()))) return true;
    if (((int)(reinterpret_cast<::FUN_008d8a60_Class *>(this)->GetField244())) != ((int)(reinterpret_cast<::FUN_008d8a60_Class *>((other))->GetField244()))) return true;
    if (((int)(reinterpret_cast<::MiddleHighProcess *>(this)->GetFacialAnimationNode())) != ((int)(reinterpret_cast<::MiddleHighProcess *>((other))->GetFacialAnimationNode()))) return true;
    if (m_eSoundLevel != reinterpret_cast<::FUN_00522560_shell *>((other))->FUN_00522560(false)) return true;
    return false;
}

struct NiPoint3 { float x; float y; float z; public:
    float ComputeMagnitude() const;
};
struct WeapNode {  };
struct WeapProcess {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual WeapNode* GetWeaponNode(void*);
};
class TESObjectREFR {
public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void* GetNiNode();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void* GetBipedRoot();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual WeapNode* Get3D();
};
class Actor : public TESObjectREFR {
public:
};
struct Biped;
class PlayerCharacter : public Actor {
public:
public:
    ::Biped *FUN_00950b00(bool);
};
struct WeapAimShell : public TESObjectWEAP {
    int FUN_00446390();
    NiPoint3 FUN_005257a0(TESObjectREFR* ref);
};

// Returns the reference's position raised by its height, or the world position of its weapon or 3D node when a process exists.
// @fnv 0x005257a0
NiPoint3 WeapAimShell::FUN_005257a0(TESObjectREFR* ref)
{
    Actor* actor2 = ref->IsActor() ? (Actor*)ref : 0;
    WeapProcess* process = actor2 ? ((::WeapProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(actor2))->GetBaseTexture())) : 0;
    bool isPlayer_2 = actor2 == ::_g_thePlayer;
    NiPoint3 pos5 = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((ref))->GetAddTopicList()));
    if (actor2)
        pos5.z += reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(actor2))->GetActorHeight();
    WeapNode* node9 = 0;
    if (actor2 && process && (FUN_00446390() == 10 || FUN_00446390() == 11 || FUN_00446390() == 12 || FUN_00446390() == 13)) {
        void* biped = isPlayer_2 ? ((void *)(::_g_thePlayer->FUN_00950b00(reinterpret_cast<::FUN_004eaf60_shell *>((::_g_thePlayer))->FUN_004eaf60()))) : actor2->GetBipedRoot();
        WeapNode* weapNode = process->GetWeaponNode(biped);
        if (weapNode)
            pos5 = *((::NiPoint3 *)(::FUN_0045bb80((int)(weapNode))));
    } else {
        if (process)
            node9 = ref->Get3D();
        else
            node9 = ((::WeapNode *)(reinterpret_cast<::UnkClass25700 *>(this)->FUN_00525700((::NiAVObject *)(void *)(isPlayer_2 ? ((void *)(::FUN_00950be0((bool *)(::_g_thePlayer)))) : ref->GetNiNode()))));
        if (node9)
            pos5 = *((::NiPoint3 *)(::FUN_0045bb80((int)(node9))));
    }
    return pos5;
}

struct CombatSettingF
{
};

struct CombatExplosion
{
};

struct CombatProjectile
{
};

struct CombatWeapon
{
	int GetWeaponType();
	int FUN_00522c80();
};

// @fnv 0x00522c80
int CombatWeapon::FUN_00522c80()
{
	switch (GetWeaponType())
	{
	case 0:
	case 1:
	case 2:
		return 2;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 13:
		{
			CombatProjectile* pkProjectile = ((::CombatProjectile *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(0))));
			if (pkProjectile && ((::CombatExplosion *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(pkProjectile))))
				&& reinterpret_cast<::PathingRequest *>((((::CombatExplosion *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(pkProjectile))))))->GetTargetRadius() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatSettingF *>(&::originalRuntimeFloatSetting353))))))
				&& reinterpret_cast<::Standin77900 *>((((::CombatExplosion *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(pkProjectile))))))->FUN_00477900() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatSettingF *>(&::originalRuntimeFloatSetting354)))))))
			{
				return 0;
			}
			return 1;
		}
	case 10:
		return 3;
	case 11:
	case 12:
		return 4;
	default:
		::FUN_005b5e40();
		return 2;
	}
}

struct TESObjectCELL;
struct NiFixedString;
struct BSFaceGenAnimationData;
BSFaceGenAnimationData* __cdecl FUN_00524c90();
NiAVObject* FUN_00524cf0(TESObjectCELL*);
NiFixedString* __cdecl FUN_00524cc0();

struct FirePoint {
 float x,y,z;
 FirePoint(); FirePoint(float,float,float);
 FirePoint operator*(float) const;
 FirePoint operator+(const FirePoint&) const;
 FirePoint operator-(const FirePoint&) const;
 FirePoint& operator*=(float);
};
struct FireNode; struct FireProcess; struct FireExtra; struct FirePackage; struct FireRef;
struct FireNode {
 virtual void unused000();
 virtual void unused004();
 virtual void unused008();
 virtual FireNode* node();
 virtual void unused010();
 virtual void unused014();
 virtual void unused018();
 virtual void unused01c();
 virtual void unused020();
 virtual void unused024();
 virtual void unused028();
 virtual void unused02c();
 virtual void unused030();
 virtual void unused034();
 virtual void unused038();
 virtual void unused03c();
 virtual void unused040();
 virtual void unused044();
 virtual void unused048();
 virtual void unused04c();
 virtual void unused050();
 virtual void unused054();
 virtual void unused058();
 virtual void unused05c();
 virtual void unused060();
 virtual void unused064();
 virtual void unused068();
 virtual void unused06c();
 virtual void unused070();
 virtual void unused074();
 virtual void unused078();
 virtual void unused07c();
 virtual void unused080();
 virtual void unused084();
 virtual void unused088();
 virtual void unused08c();
 virtual void unused090();
 virtual void unused094();
 virtual void unused098();
 virtual FireNode* find(void*);
 virtual void unused0a0();
 virtual void unused0a4();
 virtual void unused0a8();
 virtual void unused0ac();
 virtual void unused0b0();
 virtual void unused0b4();
 virtual void unused0b8();
 virtual void unused0bc();
 virtual void unused0c0();
 virtual void unused0c4();
 virtual void unused0c8();
 virtual void unused0cc();
 virtual void unused0d0();
 virtual void unused0d4();
 virtual void unused0d8();
 virtual void attach(FireNode*,bool);
 virtual void unused0e0();
 virtual void unused0e4();
 virtual void detach(FireNode*);
};
struct FireExtra {
 TESForm* CurrentObject();
};
struct FirePackage {
};
struct FireRef {
 virtual void unused000();
 virtual void unused004();
 virtual void unused008();
 virtual void unused00c();
 virtual void unused010();
 virtual void unused014();
 virtual void unused018();
 virtual void unused01c();
 virtual void unused020();
 virtual void unused024();
 virtual void unused028();
 virtual void unused02c();
 virtual void unused030();
 virtual void unused034();
 virtual void unused038();
 virtual void unused03c();
 virtual void unused040();
 virtual void unused044();
 virtual void unused048();
 virtual void unused04c();
 virtual void unused050();
 virtual void unused054();
 virtual void unused058();
 virtual void unused05c();
 virtual void unused060();
 virtual void unused064();
 virtual void unused068();
 virtual void unused06c();
 virtual void unused070();
 virtual void unused074();
 virtual void unused078();
 virtual void unused07c();
 virtual void unused080();
 virtual void unused084();
 virtual void unused088();
 virtual void unused08c();
 virtual void unused090();
 virtual void unused094();
 virtual void unused098();
 virtual void unused09c();
 virtual void unused0a0();
 virtual void unused0a4();
 virtual void unused0a8();
 virtual void unused0ac();
 virtual void unused0b0();
 virtual void unused0b4();
 virtual void unused0b8();
 virtual void unused0bc();
 virtual void unused0c0();
 virtual void unused0c4();
 virtual void unused0c8();
 virtual void unused0cc();
 virtual void unused0d0();
 virtual void unused0d4();
 virtual void unused0d8();
 virtual void unused0dc();
 virtual void unused0e0();
 virtual void unused0e4();
 virtual void unused0e8();
 virtual void unused0ec();
 virtual void unused0f0();
 virtual void unused0f4();
 virtual void unused0f8();
 virtual void unused0fc();
 virtual bool isActor();
 virtual void unused104();
 virtual void unused108();
 virtual void unused10c();
 virtual void unused110();
 virtual void unused114();
 virtual void unused118();
 virtual void unused11c();
 virtual void unused120();
 virtual void unused124();
 virtual void unused128();
 virtual void unused12c();
 virtual void unused130();
 virtual void unused134();
 virtual void unused138();
 virtual void unused13c();
 virtual void unused140();
 virtual void unused144();
 virtual void unused148();
 virtual void unused14c();
 virtual void unused150();
 virtual void unused154();
 virtual void unused158();
 virtual void unused15c();
 virtual void unused160();
 virtual void unused164();
 virtual void unused168();
 virtual void unused16c();
 virtual void unused170();
 virtual void unused174();
 virtual void unused178();
 virtual void unused17c();
 virtual void unused180();
 virtual void unused184();
 virtual void unused188();
 virtual void unused18c();
 virtual void remove(TESForm*,int,bool);
 virtual void unused194();
 virtual void unused198();
 virtual void unused19c();
 virtual void unused1a0();
 virtual void unused1a4();
 virtual void unused1a8();
 virtual void unused1ac();
 virtual void unused1b0();
 virtual void unused1b4();
 virtual void unused1b8();
 virtual void unused1bc();
 virtual void unused1c0();
 virtual void unused1c4();
 virtual void unused1c8();
 virtual void unused1cc();
 virtual FireNode* root();
 virtual void unused1d4();
 virtual void unused1d8();
 virtual void unused1dc();
 virtual void unused1e0();
 virtual struct FireAnim* anim();
 virtual void unused1e8();
 virtual void* biped();
 virtual void unused1f0();
 virtual void unused1f4();
 virtual void unused1f8();
 virtual void unused1fc();
 virtual void unused200();
 virtual void unused204();
 virtual void unused208();
 virtual FireNode* muzzle();
 virtual void unused210();
 virtual void unused214();
 virtual void unused218();
 virtual void unused21c();
 virtual void unused220();
 virtual void unused224();
 virtual void unused228();
 virtual void unused22c();
 virtual void unused230();
 virtual void unused234();
 virtual void unused238();
 virtual void unused23c();
 virtual void unused240();
 virtual void unused244();
 virtual void unused248();
 virtual void unused24c();
 virtual void unused250();
 virtual void unused254();
 virtual void unused258();
 virtual void unused25c();
 virtual void unused260();
 virtual void unused264();
 virtual void unused268();
 virtual void unused26c();
 virtual void unused270();
 virtual void unused274();
 virtual void unused278();
 virtual void unused27c();
 virtual void unused280();
 virtual void unused284();
 virtual void unused288();
 virtual void unused28c();
 virtual void unused290();
 virtual void unused294();
 virtual void unused298();
 virtual void unused29c();
 virtual void unused2a0();
 virtual void unused2a4();
 virtual void unused2a8();
 virtual void unused2ac();
 virtual void unused2b0();
 virtual void unused2b4();
 virtual void unused2b8();
 virtual float heading(int);
 virtual void unused2c0();
 virtual void unused2c4();
 virtual void unused2c8();
 virtual void unused2cc();
 virtual void unused2d0();
 virtual void unused2d4();
 virtual void unused2d8();
 virtual void unused2dc();
 virtual void unused2e0();
 virtual void unused2e4();
 virtual void unused2e8();
 virtual void unused2ec();
 virtual void unused2f0();
 virtual void unused2f4();
 virtual void unused2f8();
 virtual void unused2fc();
 virtual void unused300();
 virtual void unused304();
 virtual void unused308();
 virtual void unused30c();
 virtual void unused310();
 virtual void unused314();
 virtual void unused318();
 virtual void unused31c();
 virtual void unused320();
 virtual void unused324();
 virtual void unused328();
 virtual void unused32c();
 virtual void unused330();
 virtual void unused334();
 virtual void unused338();
 virtual void unused33c();
 virtual void unused340();
 virtual void unused344();
 virtual void unused348();
 virtual void unused34c();
 virtual void unused350();
 virtual void unused354();
 virtual void unused358();
 virtual void unused35c();
 virtual bool state();
 virtual void unused364();
 virtual void unused368();
 virtual void unused36c();
 virtual void unused370();
 virtual void unused374();
 virtual void unused378();
 virtual void unused37c();
 virtual void unused380();
 virtual void unused384();
 virtual void unused388();
 virtual void unused38c();
 virtual void unused390();
 virtual void unused394();
 virtual void unused398();
 virtual void unused39c();
 virtual void unused3a0();
 virtual void unused3a4();
 virtual void unused3a8();
 virtual void unused3ac();
 virtual void unused3b0();
 virtual void unused3b4();
 virtual void unused3b8();
 virtual void unused3bc();
 virtual void unused3c0();
 virtual void unused3c4();
 virtual void kick(FireExtra*,float,int);
 virtual void unused3cc();
 virtual void unused3d0();
 virtual void unused3d4();
 virtual void unused3d8();
 virtual void unused3dc();
 virtual void unused3e0();
 virtual void unused3e4();
 virtual void unused3e8();
 virtual void unused3ec();
 virtual void count(int);
 virtual void unused3f4();
 virtual void unused3f8();
 virtual void unused3fc();
 virtual void unused400();
 virtual void unused404();
 virtual void unused408();
 virtual void unused40c();
 virtual void unused410();
 virtual void unused414();
 virtual void unused418();
 virtual void unused41c();
 virtual void unused420();
 virtual void unused424();
 virtual struct FireTarget* target();
 int field004;
 int field008;
 int field00c;
 int field010;
 int field014;
 int field018;
 int field01c;
 int field020;
 int field024;
 int field028;
 int field02c;
 int field030;
 int field034;
 int field038;
 int field03c;
 int field040;
 int field044;
 int field048;
 int field04c;
 int field050;
 int field054;
 int field058;
 int field05c;
 int field060;
 int field064;
 int field068;
 int field06c;
 int field070;
 int field074;
 int field078;
 int field07c;
 int field080;
 int field084;
 int field088;
 int field08c;
 int field090;
 int field094;
 int field098;
 int field09c;
 int field0a0;
 int field0a4;
 int field0a8;
 int field0ac;
 int field0b0;
 int field0b4;
 int field0b8;
 int field0bc;
 int field0c0;
 int field0c4;
 int field0c8;
 int field0cc;
 int field0d0;
 int field0d4;
 int field0d8;
 int field0dc;
 int field0e0;
 int field0e4;
 int field0e8;
 int field0ec;
 int field0f0;
 int field0f4;
 int field0f8;
 int field0fc;
 int field100;
 int field104;
 int field108;
 int field10c;
 int field110;
 int field114;
 int field118;
 int field11c;
 int field120;
 int field124;
 int field128;
 int field12c;
 int field130;
 int field134;
 int field138;
 int field13c;
 int field140;
 int field144;
 int field148;
 int field14c;
 int field150;
 int field154;
 int field158;
 int field15c;
 int field160;
 int field164;
 int field168;
 int field16c;
 int field170;
 int field174;
 int field178;
 int field17c;
 int field180;
 int field184;
 int field188;
 int field18c;
 int field190;
 int field194;
 int field198;
 int field19c;
 int field1a0;
  
};
struct FireProcess {
 virtual void unused000();
 virtual void unused004();
 virtual void unused008();
 virtual void unused00c();
 virtual void unused010();
 virtual void unused014();
 virtual void unused018();
 virtual void unused01c();
 virtual void unused020();
 virtual void unused024();
 virtual void unused028();
 virtual void unused02c();
 virtual void unused030();
 virtual void unused034();
 virtual void unused038();
 virtual void unused03c();
 virtual void unused040();
 virtual void unused044();
 virtual void unused048();
 virtual void unused04c();
 virtual void unused050();
 virtual void unused054();
 virtual void unused058();
 virtual void unused05c();
 virtual void unused060();
 virtual void unused064();
 virtual void unused068();
 virtual void unused06c();
 virtual void unused070();
 virtual void unused074();
 virtual void unused078();
 virtual void unused07c();
 virtual void unused080();
 virtual void unused084();
 virtual void unused088();
 virtual void unused08c();
 virtual void unused090();
 virtual void unused094();
 virtual void unused098();
 virtual void unused09c();
 virtual void unused0a0();
 virtual void unused0a4();
 virtual void unused0a8();
 virtual void unused0ac();
 virtual void unused0b0();
 virtual void unused0b4();
 virtual void unused0b8();
 virtual void unused0bc();
 virtual void unused0c0();
 virtual void unused0c4();
 virtual void unused0c8();
 virtual void unused0cc();
 virtual void unused0d0();
 virtual void unused0d4();
 virtual void unused0d8();
 virtual void unused0dc();
 virtual void unused0e0();
 virtual void unused0e4();
 virtual void unused0e8();
 virtual void unused0ec();
 virtual void unused0f0();
 virtual void unused0f4();
 virtual void unused0f8();
 virtual void unused0fc();
 virtual void unused100();
 virtual void unused104();
 virtual void unused108();
 virtual void unused10c();
 virtual void unused110();
 virtual void unused114();
 virtual void unused118();
 virtual void unused11c();
 virtual void unused120();
 virtual void unused124();
 virtual void unused128();
 virtual void unused12c();
 virtual void unused130();
 virtual void unused134();
 virtual void unused138();
 virtual void unused13c();
 virtual void unused140();
 virtual void unused144();
 virtual FireExtra* extra();
 virtual FireExtra* weapons();
 virtual void unused150();
 virtual void unused154();
 virtual void unused158();
 virtual void unused15c();
 virtual void unused160();
 virtual void unused164();
 virtual void unused168();
 virtual void unused16c();
 virtual void unused170();
 virtual void unused174();
 virtual void unused178();
 virtual void unused17c();
 virtual void unused180();
 virtual void unused184();
 virtual void unused188();
 virtual void unused18c();
 virtual FireNode* muzzle(void*);
 virtual void unused194();
 virtual void unused198();
 virtual void unused19c();
 virtual void unused1a0();
 virtual void unused1a4();
 virtual void unused1a8();
 virtual void unused1ac();
 virtual void unused1b0();
 virtual void unused1b4();
 virtual void unused1b8();
 virtual void unused1bc();
 virtual void unused1c0();
 virtual void unused1c4();
 virtual void unused1c8();
 virtual void unused1cc();
 virtual void unused1d0();
 virtual void unused1d4();
 virtual void unused1d8();
 virtual void unused1dc();
 virtual void unused1e0();
 virtual void unused1e4();
 virtual void unused1e8();
 virtual void unused1ec();
 virtual void unused1f0();
 virtual void unused1f4();
 virtual void unused1f8();
 virtual void unused1fc();
 virtual void unused200();
 virtual void unused204();
 virtual void unused208();
 virtual void unused20c();
 virtual void unused210();
 virtual void unused214();
 virtual void unused218();
 virtual void unused21c();
 virtual void unused220();
 virtual void unused224();
 virtual void unused228();
 virtual void unused22c();
 virtual void unused230();
 virtual void unused234();
 virtual void unused238();
 virtual void unused23c();
 virtual void unused240();
 virtual void unused244();
 virtual void unused248();
 virtual void unused24c();
 virtual void unused250();
 virtual void unused254();
 virtual void unused258();
 virtual void unused25c();
 virtual void unused260();
 virtual void unused264();
 virtual void unused268();
 virtual void unused26c();
 virtual void unused270();
 virtual struct FireList* data();
 virtual void unused278();
 virtual FirePackage* package();
 virtual void unused280();
 virtual void unused284();
 virtual void unused288();
 virtual void unused28c();
 virtual void unused290();
 virtual void unused294();
 virtual void unused298();
 virtual void unused29c();
 virtual void unused2a0();
 virtual void unused2a4();
 virtual void unused2a8();
 virtual void unused2ac();
 virtual void unused2b0();
 virtual void unused2b4();
 virtual void unused2b8();
 virtual void unused2bc();
 virtual void unused2c0();
 virtual void unused2c4();
 virtual void unused2c8();
 virtual void unused2cc();
 virtual void unused2d0();
 virtual void unused2d4();
 virtual void unused2d8();
 virtual void unused2dc();
 virtual void unused2e0();
 virtual void unused2e4();
 virtual void unused2e8();
 virtual void unused2ec();
 virtual void unused2f0();
 virtual void unused2f4();
 virtual void unused2f8();
 virtual void unused2fc();
 virtual void unused300();
 virtual void unused304();
 virtual void unused308();
 virtual void unused30c();
 virtual void unused310();
 virtual void unused314();
 virtual void unused318();
 virtual void unused31c();
 virtual void unused320();
 virtual void unused324();
 virtual void unused328();
 virtual void unused32c();
 virtual void unused330();
 virtual void unused334();
 virtual void unused338();
 virtual void unused33c();
 virtual void unused340();
 virtual void unused344();
 virtual void unused348();
 virtual void unused34c();
 virtual void unused350();
 virtual void unused354();
 virtual void unused358();
 virtual void unused35c();
 virtual void unused360();
 virtual void unused364();
 virtual void unused368();
 virtual void unused36c();
 virtual void unused370();
 virtual void unused374();
 virtual void unused378();
 virtual void unused37c();
 virtual void unused380();
 virtual void unused384();
 virtual void unused388();
 virtual void unused38c();
 virtual void unused390();
 virtual void unused394();
 virtual void unused398();
 virtual void unused39c();
 virtual void unused3a0();
 virtual void unused3a4();
 virtual void unused3a8();
 virtual void unused3ac();
 virtual void unused3b0();
 virtual void unused3b4();
 virtual void unused3b8();
 virtual void unused3bc();
 virtual void unused3c0();
 virtual void unused3c4();
 virtual void unused3c8();
 virtual void unused3cc();
 virtual void unused3d0();
 virtual void unused3d4();
 virtual void unused3d8();
 virtual void unused3dc();
 virtual void unused3e0();
 virtual void unused3e4();
 virtual void unused3e8();
 virtual void unused3ec();
 virtual void unused3f0();
 virtual void unused3f4();
 virtual void unused3f8();
 virtual void unused3fc();
 virtual void unused400();
 virtual void unused404();
 virtual void unused408();
 virtual void unused40c();
 virtual void unused410();
 virtual void unused414();
 virtual void unused418();
 virtual void unused41c();
 virtual void unused420();
 virtual void unused424();
 virtual void unused428();
 virtual float spread();
 virtual void unused430();
 virtual void unused434();
 virtual void unused438();
 virtual void unused43c();
 virtual unsigned char shots();
 virtual void unused444();
 virtual void shotsCount(int);
};
struct FireFormCheck {
 virtual void slot000();
 virtual void slot004();
 virtual void slot008();
 virtual void slot00c();
 virtual void slot010();
 virtual void slot014();
 virtual void slot018();
 virtual void slot01c();
 virtual void slot020();
 virtual void slot024();
 virtual void slot028();
 virtual void slot02c();
 virtual void slot030();
 virtual void slot034();
 virtual void slot038();
 virtual void slot03c();
 virtual void slot040();
 virtual void slot044();
 virtual void slot048();
 virtual void slot04c();
 virtual void slot050();
 virtual void slot054();
 virtual void slot058();
 virtual void slot05c();
 virtual void slot060();
 virtual void slot064();
 virtual void slot068();
 virtual void slot06c();
 virtual void slot070();
 virtual void slot074();
 virtual void slot078();
 virtual void slot07c();
 virtual void slot080();
 virtual void slot084();
 virtual void slot088();
 virtual void slot08c();
 virtual void slot090();
 virtual void slot094();
 virtual void slot098();
 virtual void slot09c();
 virtual void slot0a0();
 virtual void slot0a4();
 virtual void slot0a8();
 virtual void slot0ac();
 virtual void slot0b0();
 virtual void slot0b4();
 virtual void slot0b8();
 virtual void slot0bc();
 virtual void slot0c0();
 virtual void slot0c4();
 virtual void slot0c8();
 virtual void slot0cc();
 virtual void slot0d0();
 virtual void slot0d4();
 virtual void slot0d8();
 virtual void slot0dc();
 virtual void slot0e0();
 virtual bool bound();
};
struct FireAmmo : TESAmmo {
   
};
struct FireAnim {  };
struct AmmoComponentAccess : BGSAmmoForm { TESAmmo* GetAmmoHelper(); };
struct FireWeapon : TESObjectWEAP {

 void FUN_00523150(FireRef*);
 int GetWeaponType() const;
  
 void FUN_00524db0(FireRef*);
   
};
struct FireString { int GetModelLength(); };
struct FireVats {
  
  
};
FirePoint* FireRefPosition(FireRef*);
struct FirePositionRef {   };
struct FireFace {
};
struct FireTransform { FirePoint FUN_00524c40(const FirePoint&); };

struct FireSetting {  unsigned char* Bool(); };
struct FireSmart {
 FireNode* ptr;
 FireSmart(FireNode*); ~FireSmart();
 operator FireNode*() const;
 FireSmart& operator=(FireNode*);
};
struct FireColor { float r,g,b,a; FireColor(float,float,float,float); };
struct FireMatrix { float xx,xy,xz,yx,yy,yz,zx,zy,zz; FireMatrix();  };
struct FireUpdate { float time; bool a,b; int flags; FireUpdate(float,bool,bool); };
void* FUN_00524cb0();

struct FireTarget {  };
struct FireList {
 virtual void ReportDiagnostic(); virtual void unused4(); virtual int type();
};
struct FireRefData {
  
};


FirePoint ComputeTrajectory(FireRef*,FireRef*,int,FireRefData*,float,bool);
FirePoint GetTargetLocationWithOffset(FireRef*,bool);
void FUN_004169a0(float,float&,float&);
struct FireControls {  };
struct FireOS {  };
struct FireAmmoFlag {  };


struct WeaponAmmoView { int field000; int field004; int field008; int field00c; int field010; int field014; int field018; int field01c; int field020; int field024; int field028; int field02c; int field030; int field034; int field038; int field03c; int field040; int field044; int field048; int field04c; int field050; int field054; int field058; int field05c; int field060; int field064; int field068; int field06c; int field070; int field074; int field078; int field07c; int field080; int field084; int field088; int field08c; int field090; int field094; int field098; int field09c; int field0a0; FireAmmoFlag ammoForm; };
struct FireShot { int id; int field04; unsigned char ammo, special,field0a,field0b; FireRef* target; };
struct FireUse {   };
extern float DAT_011c9508;
float FireCos(float);

// Fires the weapon for the given reference: resolves ammo and muzzle, computes spread and aim, spawns projectiles per shot, and updates ammo counts and recoil.
// @fnv 0x00523150
void FireWeapon::FUN_00523150(FireRef* reference) {
 if (reference) {
  FireRef* actor19 = reference->isActor() ? reference : 0;
  if (actor19 == (*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))) {
   FireAmmo* ammo3 = (FireAmmo*)((::TESAmmo *)(reinterpret_cast<::AmmoOwner *>(this)->FUN_00525980((::AmmoActor *)(::Actor *)((Actor*)(*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))));
   if (ammo3) {
    TESForm* removed32 = 0;
    TESForm* effect7 = ((::TESForm *)(::GetFieldBC((::FUN_0097ae90_Class *)(ammo3))));
    float chance1 = reinterpret_cast<::FUN_006d6d90_shell *>((ammo3))->FUN_006d6d90();
    ::ApplyPerkModifiers(57,(::Actor *)((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))),this,&chance1);
    float roll4 = (float)(DialogueRandom()%100);
    if (effect7 && roll4 <= chance1) {
     if (((FireFormCheck*)effect7)->bound()) removed32 = effect7;
     if (removed32) {
      TESFullName* fullName1 = dynamic_cast<TESFullName*>(effect7);
      (*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))->remove(removed32,0,true);
     }
    }
   }
  }
  if (actor19 && actor19->field1a0) return;
  bool player12 = actor19 == (*reinterpret_cast<::FireRef * *>(&::_g_thePlayer));
  struct FireShot* shot16 = 0;
  FireProcess* process39 = actor19 ? ((::FireProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor19))->GetBaseTexture())) : 0;
  const int unusedResult10 = 0;
  FireExtra* extra13 = process39 ? process39->extra() : 0;
  FirePoint position6 = actor19 ? *((::FirePoint *)(reinterpret_cast<::TESTopicInfo *>((((FirePositionRef*)reference)))->GetAddTopicList())) + (*reinterpret_cast<::FirePoint *>((void *)&::DAT_011a9484)) * 96.0f : *((::FirePoint *)(reinterpret_cast<::TESTopicInfo *>((((FirePositionRef*)reference)))->GetAddTopicList()));
  float pitch37 = actor19 ? reinterpret_cast<::MobileObject *>((actor19))->GetLooking() : (*(const ::FirePoint *)(reinterpret_cast<::TESRecipe *>((void *)(((FirePositionRef*)reference)))->GetData())).x;
  float yaw21 = actor19 ? actor19->heading(0) : (*(const ::FirePoint *)(reinterpret_cast<::TESRecipe *>((void *)(((FirePositionRef*)reference)))->GetData())).z;
  FireNode* muzzle11 = 0;
  if (process39 && (GetWeaponType()==10 || GetWeaponType()==11 || GetWeaponType()==12 || GetWeaponType()==13)) {
   float unusedPad[18];
   if (player12 && process39 && process39->weapons() && ((int)(reinterpret_cast<::Callees *>((process39->weapons()))->FUN_00726070()))>1) {
    muzzle11 = process39->muzzle(((void *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->FUN_00950b00(reinterpret_cast<::FUN_004eaf60_shell *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->FUN_004eaf60()))));
    if (muzzle11 && muzzle11->node() && ((::FireNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((muzzle11->node()))->FUN_0045bc00(0)))) reinterpret_cast<::TaskQueueInterface *>((((::FireNode *)(reinterpret_cast<::NiNode *>((muzzle11->node()))->GetAt(0)))))->QueueActorDisarm(true);
   }
   muzzle11 = process39->muzzle(actor19->biped());
   if (muzzle11) position6 = *((::FirePoint *)(::FUN_0045bb80((int)(muzzle11))));
   if (player12) ::fnv_00524d70::FUN_00524d70((char *)((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))));
  } else {
   if (process39) muzzle11 = reference->muzzle();
   else muzzle11 = ((::FireNode *)(reinterpret_cast<::UnkClass25700 *>(this)->FUN_00525700((::NiAVObject *)(::FireNode *)(player12 ? ((::FireNode *)(::FUN_00950be0((bool *)((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer)))))) : reference->root()))));
   if (muzzle11) {
    position6 = *((::FirePoint *)(::FUN_0045bb80((int)(muzzle11))));
    if (((int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::FireVats *>(&::g_011f2250))))->GetName()))!=4 && actor19==(*reinterpret_cast<::FireRef * *>(&::_g_thePlayer)) && reinterpret_cast<::FUN_008bbc10_shell *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->FUN_008bbc10() && ((::FireString *)(reinterpret_cast<::FUN_00504e60_shell *>(this)->FUN_00504e60()))->GetModelLength()) {
     bool useFace2 = false;
     if (reinterpret_cast<::FUN_004ad030_shell *>(this)->GetFlag()) {
      FireProcess* faceProcess = ((::FireProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->GetBaseTexture()));
      if (faceProcess && faceProcess->extra() && reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((faceProcess->extra()))->HasEffect(14)) useFace2 = true;
     } else useFace2 = true;
     FireFace* face31 = (FireFace*)FUN_00524c90();
     if (useFace2 && face31) {
      static FirePoint offset(0.0f,-5.0f,0.0f);
      position6 = ((::FireTransform *)(::FUN_00461130((int)(face31))))->FUN_00524c40(offset);
     }
    }
    if (reference && reference==(*reinterpret_cast<::FireRef * *>(&::_g_thePlayer)) && !::FUN_00524d10((bool *)((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))) {
     yaw21 = (*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))->heading(0);
     pitch37 = reinterpret_cast<::MobileObject *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->GetLooking();
    } else {
     float roll4;
     reinterpret_cast<::RotationMatrix *>((((FireNode*)((::FirePoint *)(::FUN_00461130((int)(muzzle11)))))))->FUN_00a59400((*(float *)(&yaw21)),(*(float *)(&pitch37)),(*(float *)(&roll4)));
    }
    if (*(*reinterpret_cast<::FireSetting *>(&::g_011c94a0)).Bool()) {
     FireNode* root = muzzle11->node();
     if (!root) root = ((::FireNode *)(reinterpret_cast<::FUN_009611e0_shell *>((muzzle11))->FUN_009611e0()))->node();
     if (root) {
      FireSmart marker(root->find(FUN_00524cb0()));
      if (!(FireNode*)marker) {
       FireColor color(1,0,0,1);
       marker = ((::FireNode *)(::fnv_00c584a0::FUN_00c584a0(1,1,4096.0f,10,10,(::fnv_00c584a0::MeshColor *)(::FireColor *)(&color))));
       ::AssignFixedString((char *)(((FireNode*)marker)), (int)(FUN_00524cb0()), {});
       FireMatrix rotation;
       reinterpret_cast<::FUN_00524ac0_shell *>(&(rotation))->FUN_00524ac0(1.57079637f);
       reinterpret_cast<::FUN_0043fa80_s *>((((FireNode*)marker)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
       ::fnv_004b6e90::AttachLightingPropertyRecursive((::NiAVObject *)(::FireNode *)(marker));
       ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::FireNode *)(marker),0,0);
       root->attach(marker,true);
       reinterpret_cast<::FUN_00a5a040_Class *>((((FireNode*)marker)))->FUN_00a5a040();
       FireUpdate update(0,false,false);
       reinterpret_cast<::FUN_00a59c60_cls *>((((FireNode*)marker)))->FUN_00a59c60((std::intptr_t)&(update));
      }
     }
    }
    ::PlayWeaponSound((::Weap *)(::FireWeapon *)(this),(::VObj1d0 *)(reference),(::ListObj *)(muzzle11),player12);
   }
  }

  float accuracy5 = actor19 ? reinterpret_cast<::CalcActor *>((actor19))->GetCachedSpeed(1) : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FireSetting *>(&::g_011ce23c))))));
  bool modSpread31 = false;
  if (actor19 && ((::FireProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor19))->GetBaseTexture())) && extra13 && reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((extra13))->HasEffect(3)) modSpread31 = true;
  float spread50 = (reinterpret_cast<::FUN_00524b80_This *>(this)->FUN_00524b80(modSpread31) + reinterpret_cast<::FUN_00524be0_shell *>(this)->FUN_00524be0(modSpread31)*accuracy5) * 0.01745329238474369;
  if (actor19 && ((::FireProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor19))->GetBaseTexture()))) {
   spread50 = ::ComputeAmmoEffectValue(3,(::AmmoEffectList *)(void *)(((::TESAmmo *)(reinterpret_cast<::AmmoOwner *>(this)->FUN_00525980((::AmmoActor *)(::Actor *)((Actor*)actor19)))) ? reinterpret_cast<::TESAmmoInitCalls *>((((FireAmmo*)((::TESAmmo *)(reinterpret_cast<::AmmoOwner *>(this)->FUN_00525980((::AmmoActor *)(::Actor *)((Actor*)actor19)))))))->FUN_00923000() : 0),spread50);
  }
  float processSpread1 = 0;
  FireTarget* target20 = 0;
  if (!player12 && actor19) {
   FirePoint targetPosition;
   target20 = actor19->target();
   if (target20) {
    if (!reinterpret_cast<::Holder009807f0 *>((target20))->CallHelperFoo((int)(&targetPosition),(int)(&position6))) {
     if (::FUN_004c0bf0((::TESObjectWEAP *)this)) reinterpret_cast<::fnv_004994f0::FUN_004994f0_shell *>((actor19->anim()))->FUN_004994f0(4,false);
     return;
    }
    FirePoint direction = targetPosition-position6;
    yaw21 = ::GetAngleFromVector((*(const ::NiPoint3 *)(&direction)));
    pitch37 = -FUN_004b54c0(direction.z/reinterpret_cast<::NiPoint3 *>((void *)&(direction))->ComputeMagnitude());
    if (*(*reinterpret_cast<::FireSetting *>(&::g_011c94b0)).Bool()) {
     FireNode* cellNode = (FireNode*)FUN_00524cf0((TESObjectCELL*)((void *)(reinterpret_cast<::LowProcess *>((actor19))->GetTarget())));
     if (cellNode) {
      FireSmart cellMarker31(cellNode->find((void*)FUN_00524cc0()));
      if ((FireNode*)cellMarker31) ((::FireNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((FireNode*)cellMarker31)))->FUN_009611e0()))->detach(cellMarker31);
      FireColor cellColor14(0,1,0,1);
      cellMarker31 = ((::FireNode *)(::FUN_00c55d50((::Point3 *)(::FirePoint *)(&position6),(::Point3 *)(::FirePoint *)(&targetPosition),0.5f,0.5f,0.5f,0.5f,(::FilterData *)(::FireColor *)(&cellColor14),(::FilterData *)(0))));
      ::AssignFixedString((char *)(((FireNode*)cellMarker31)), (int)((void*)FUN_00524cc0()), {});
      cellNode->attach(cellMarker31,true);
      reinterpret_cast<::FUN_00a5a040_Class *>((((FireNode*)cellMarker31)))->FUN_00a5a040();
      FireUpdate cellUpdate73(0,false,false);
      reinterpret_cast<::FUN_00a59c60_cls *>((((FireNode*)cellMarker31)))->FUN_00a59c60((std::intptr_t)&(cellUpdate73));
     }
    }
   } else if (process39 && process39->package() && reinterpret_cast<struct ::FUN_0041ca90 *>((process39->package()))->get()==16) {
    FireList* data = process39->data();
    if (data) {
     FireList* list = data;
     FireRef* packageTarget = ((::FireRef *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
     if (!packageTarget) return;
     bool lob = false;
     FireRefData* projectile = ((::FireRefData *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(0))));
     if (projectile) {
      float speed = ::GetFloatAtOffset68((const char *)(projectile))*(lob ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FireSetting *>(&::originalRuntimeFloatSetting375)))))) : 1.0f);
      targetPosition = ComputeTrajectory(actor19,packageTarget,0,projectile,speed,lob);
     } else targetPosition = GetTargetLocationWithOffset(packageTarget,true);
     FirePoint direction = targetPosition-position6;
     if (((::FireRef *)(reinterpret_cast<::fnv_00676140::FUN_00676140_shell *>((process39->package()))->FUN_00676140((::MobileObject *)(actor19))))==packageTarget) {
      direction.z=0;
      FUN_004169a0(actor19->heading(0),direction.x,direction.y);
      reinterpret_cast<::MyPoint439180 *>((void *)&(const ::FirePoint &)(direction))->FUN_00439180(512.0f);
      targetPosition=position6+direction;
     }
     yaw21=::GetAngleFromVector((*(const ::NiPoint3 *)(&direction)));
     pitch37=-FUN_004b54c0(direction.z/reinterpret_cast<::NiPoint3 *>((void *)&(direction))->ComputeMagnitude());
    }
   }
   float aim = reinterpret_cast<::CalcActor *>((actor19))->GetCachedSpeed(2);
   spread50 += aim * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FireSetting *>(&::originalRuntimeFloatSetting393)))))) * 0.01745329238474369;
   processSpread1 = ((::FireProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor19))->GetBaseTexture()))->spread();
   spread50 += processSpread1;
  }
  if ((reference==(*reinterpret_cast<::FireRef * *>(&::_g_thePlayer)) && process39 && process39->weapons()) || reinterpret_cast<::FUN_00474a80_Class *>(&(((WeaponAmmoView*)this)->ammoForm))->FUN_00474a80()) {
   if (!FUN_00702360()) {
    FireControls* controls = ((::FireControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::FireOS * *>(&::g_osGlobals))))->FUN_00877720()));
    if (reinterpret_cast<::FUN_008133b0_class *>(this)->GetFloatAt144()>0.0) reinterpret_cast<::Controller *>((controls))->FUN_00a255b0(::FUN_00567470((char *)this),reinterpret_cast<::FUN_00821680_Class *>(this)->FUN_00821680(),(int)(reinterpret_cast<::FUN_008133b0_class *>(this)->GetFloatAt144()*1000.0),0,0,0,0);
    if (reinterpret_cast<::FUN_008133b0_class *>(this)->GetFloatAt144()>0.0) reinterpret_cast<::Controller *>((controls))->FUN_00a255b0(0.5f,1.0f,330,0,0,0,0);
   }
  }


  char shots14 = process39 ? process39->shots() : 1;
  bool split2 = false;
  if (extra13) split2 = reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((extra13))->HasEffect(12);
  if (split2) spread50 *= reinterpret_cast<::FUN_004bcf60_shell *>(this)->GetEffectValue(12,1);
  int projectileCount11 = GetDamageForActor(false,false,(Actor*)actor19) * shots14;
  int usedAmmo26=unusedResult10;
  FireSmart lastNode23(0);
  if (((int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::FireVats *>(&::g_011f2250))))->GetName()))==4 && actor19==(*reinterpret_cast<::FireRef * *>(&::DAT_011f21f0))) shot16=((::FireShot *)(reinterpret_cast<::ListHolder *>(&((*reinterpret_cast<::FireVats *>(&::g_011f2250))))->FUN_009c71c0()));
  bool aimed26=false;
  unsigned char specialFlag19=0;
  FirePackage* package3 = actor19 ? ((::FirePackage *)(reinterpret_cast<::FUN_009344a0_shell *>((actor19))->FUN_009344a0())) : 0;
  if (package3) {
   FireUse* use=((::FireUse *)(reinterpret_cast<::TESPackageShell *>((package3))->FUN_006758f0()));
   if (use) { aimed26=((bool)(reinterpret_cast<::FUN_00424940_shell *>((use))->FUN_00424940())); specialFlag19=reinterpret_cast<::FUN_00524cd0_shell *>((use))->GetByteAt0D(); }
  }
  bool specialAmmo35=false;
  if (shot16 && shot16->special && FUN_0066dde0(shot16->id)) specialAmmo35=true;
  if (actor19 && process39) process39->shotsCount(projectileCount11);
  bool vatTarget22=false;
  FireRef* aimTarget25=0;
  if (shot16 && actor19 && (actor19==(*reinterpret_cast<::FireRef * *>(&::DAT_011f21e8)) || actor19==(*reinterpret_cast<::FireRef * *>(&::DAT_011f21ec)))) {
   vatTarget22=true; aimed26=true; aimTarget25=shot16->target;
  }
  if (aimed26 && !vatTarget22) {
   FireList* data=process39->data();
   if (data && data->type()==16) {
    FireList* list=data;
    aimTarget25=((::FireRef *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
   }
  }
  while (shots14) {
   bool useSpecial62 = specialAmmo35 && ((DAT_011c9508<0.0 && shot16->special>0) || !shot16->ammo);
   bool firstProjectile43=true;
   FireRefData* spawned19=0;
   unsigned char count3=GetDamageForActor(split2,false,(Actor*)actor19);
   while (count3) {
    float shotPitch5=pitch37;
    float shotYaw16=yaw21;
    float pitchOffset13=0;
    float yawOffset5=0;
    if (!aimed26) {
     float radius=RandomFloat(0,spread50);
     float angle=RandomFloat(0,6.28318548f);
     pitchOffset13=FUN_004e44b0(angle)*radius;
     yawOffset5=FireCos(angle)*radius;
     shotPitch5+=pitchOffset13;
     shotYaw16+=yawOffset5;
    }
    FireRef* shooter2=0;
    if (reference->isActor()) shooter2=reference;
    spawned19=((::FireRefData *)(::CreateProjectile((::P062Ammo *)(::FireRefData *)(((::FireRefData *)(reinterpret_cast<::Thing *>(this)->GetOrFallback((int)(shooter2))))),(::P062Object *)(reference),(::P062Object *)(target20),(::P062Object *)(::FireWeapon *)(this),(*(::NiPoint3 *)&(const ::FirePoint &)(position6)),shotYaw16,shotPitch5,lastNode23,(int)(aimTarget25),aimed26,(bool)(specialFlag19 || useSpecial62),yawOffset5,pitchOffset13,(void *)(0))));
    if (shot16 && (shot16->ammo || shot16->special) && FUN_0066dde0(shot16->id) && !useSpecial62) {
     if (!reinterpret_cast<::FUN_00524b40_class *>(this)->FUN_00524b40() || (!((int)(reinterpret_cast<::BGSTerrainManager *>(&((*reinterpret_cast<::FireVats *>(&::g_011f2250))))->GetMinLevel())) && reinterpret_cast<::FUN_00524b40_class *>(this)->FUN_00524b40())) reinterpret_cast<::FUN_009c8b90_cls *>(&((*reinterpret_cast<::FireVats *>(&::g_011f2250))))->FUN_009c8b90((::FUN_009c8b90_arg *)(spawned19));
    }
    if (!firstProjectile43) reinterpret_cast<::FUN_008126e0_shell *>((spawned19))->SetWhich(0);
    else firstProjectile43=false;
    --count3;
   }
   if (!useSpecial62) ++usedAmmo26;
   if (shot16 && (shot16->ammo || shot16->special) && FUN_0066dde0(shot16->id)) {
    if (useSpecial62 && shot16->special) --shot16->special;
    else {
     int ammoPerShot=reinterpret_cast<::FUN_00524b60_shell *>(this)->GetByteAt102();
     if (ammoPerShot<1) ammoPerShot=1;
     shot16->ammo-=ammoPerShot;
    }
    float ratio=*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FireSetting *>(&::originalRuntimeFloatSetting538))))))/FUN_00404010(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FireSetting *>(&::originalRuntimeFloatSetting538)))))),*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FireSetting *>(&::originalRuntimeFloatSetting539)))))));
    DAT_011c9508+=ratio;
    if (DAT_011c9508>=ratio) DAT_011c9508-=1.0;
    if (!useSpecial62 && !shot16->ammo) reinterpret_cast<::S_009c8c40 *>(&((*reinterpret_cast<::FireVats *>(&::g_011f2250))))->SetValue((int)(spawned19));
   }
   --shots14;
  }
  if (actor19) {
   int savedAmmo=0;
   if (actor19==(*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))) {
    FireProcess* playerProcess=((::FireProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->GetBaseTexture()));
    if (playerProcess && playerProcess->extra()) {
     float chance1=0;
     if (reinterpret_cast<::FUN_004bd8d0_shell *>((playerProcess->extra()))->FUN_004bd8d0(5,&chance1)) {
      reinterpret_cast<::FUN_00524d30_shell *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->SetByteAtOffset1F8(reinterpret_cast<::FUN_00524d50_shell *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->GetByteAtOffset1F8()+usedAmmo26);
      const int threshold=4;
      if (reinterpret_cast<::FUN_00524d50_shell *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->GetByteAtOffset1F8()>=threshold) {
       reinterpret_cast<::FUN_00524d30_shell *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->SetByteAtOffset1F8(reinterpret_cast<::FUN_00524d50_shell *>(((*reinterpret_cast<::FireRef * *>(&::_g_thePlayer))))->GetByteAtOffset1F8()-threshold);
       savedAmmo=1;
      }
     }
    }
   }
   actor19->count(usedAmmo26-savedAmmo);
  }
  if ((process39 && GetWeaponType()==10) || GetWeaponType()==11 || GetWeaponType()==12 || GetWeaponType()==13) {
   if (!process39->weapons() || ((int)(reinterpret_cast<::Callees *>((process39->weapons()))->FUN_00726070()))<=0) reinterpret_cast<::BipedAnim *>((actor19))->AttachFaceGenNode();
   else if (muzzle11) {
    FireNode* child=((::FireNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((muzzle11->node()))->FUN_0045bc00(0)));
    if (child) reinterpret_cast<::TaskQueueInterface *>((child))->QueueActorDisarm(true);
   }
  }
  lastNode23=0;
  switch (GetWeaponType()) {
   case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    if (actor19 && actor19->state() && process39 && process39->extra() && !reinterpret_cast<::FUN_0046e8c0_class *>(this)->FUN_0046e8c0()) {
     float recoil=::FUN_00646260((::Actor *)(actor19));
     actor19->kick(((::FireProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor19))->GetBaseTexture()))->extra(),recoil,0);
    }
    break;
  }
  if (reinterpret_cast<::FUN_00524b40_class *>(this)->FUN_00524b40()) FUN_00524db0(reference);

 }
}

// @fnv 0x004169a0
void __cdecl FUN_004169a0(float fRadians, float& fSin, float& fCos)
{
    float s, c;
    __asm {
        fld fRadians
        fsincos
        fstp c
        fstp s
    }
    fSin = s;
    fCos = c;
}

namespace fnv_00524db0 {
struct P12 {
    float x, y, z;
};
struct Mat36 { float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
struct Sub461130 {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    P12* FUN_004b4500(P12*, P12*);
};
struct GetterBase {  };
struct NodeObj : GetterBase {  };
struct BSFaceGenAnimationData : GetterBase {};
struct SubA {
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual int vfn_14();
    unsigned int FUN_0048cee0();
};
struct Param {
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3a();
    virtual void Unk_3b();
    virtual void Unk_3c();
    virtual void Unk_3d();
    virtual void Unk_3e();
    virtual void Unk_3f();
    virtual bool Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4a();
    virtual void Unk_4b();
    virtual void Unk_4c();
    virtual void Unk_4d();
    virtual void Unk_4e();
    virtual void Unk_4f();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5a();
    virtual void Unk_5b();
    virtual void Unk_5c();
    virtual void Unk_5d();
    virtual void Unk_5e();
    virtual void Unk_5f();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6a();
    virtual void Unk_6b();
    virtual void Unk_6c();
    virtual void Unk_6d();
    virtual void Unk_6e();
    virtual void Unk_6f();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void* Unk_74();
};
struct SettingObj {  };
struct Obj2250 {  };
extern char DAT_0102cb00;
void* __cdecl FUN_00aa13e0(unsigned int);
struct XObj {
    
    void* pEffect; void* pSource; void* pTransform; unsigned int flags; float intensity; float x; float y; float z; unsigned int lifetime;
    XObj(void*, float, int, Param*, P12*, Mat36*, P12*, P12*, float, int, int);
};
struct ThisObj {
    void FUN_00524db0(Param* param);
};

// Creates an XObj using node data, settings, and a call on param when the conditions pass.
// @fnv 0x00524db0
void ThisObj::FUN_00524db0(Param* param)
{
    if (param != 0) {
    if (param->Unk_40()) {
    if (((::fnv_00524db0::SubA *)(reinterpret_cast<::FUN_004600d0_shell *>((this))->FUN_004600d0()))->FUN_0048cee0() > 0) {
    if (!((bool)(::FUN_00525420()))) {
    P12 bufC3;
    P12 tempBCz;
    XObj* qB7;
    XObj* qA7;
    float _fa8;
    P12 vecA0;
    P12 temp6;
    float f8c2;
    P12 ob88;
    float f7c5;
    float f9;
    P12 obj14;
    int dword4;
    P12 point1;
    Mat36 matTmp;
    P12 obj34;
    bool flag7;
    P12 aVec24;
    NodeObj* node3;
    Param* paramHome8;
    void* pR;
    paramHome8 = param;
    pR = (paramHome8 == (*reinterpret_cast<::fnv_00524db0::Param * *>(&::_g_thePlayer))) ? ((void *)(::FUN_00950be0((bool *)((*reinterpret_cast<::fnv_00524db0::Param * *>(&::_g_thePlayer)))))) : paramHome8->Unk_74();
    node3 = ((::fnv_00524db0::NodeObj *)(::FUN_004aae30((::NiAVObject *)(pR), (::NiFixedString *)((const char*)&DAT_0102cb00))));
    if (node3 != 0) {
    flag7 = true;
    if (!::FUN_004b61d0((*(::NiPoint3 *)&(const ::fnv_00524db0::P12 &)(*((::fnv_00524db0::P12 *)(::FUN_0045bb80((int)(node3)))))), (::NiCamera *)(::fnv_00524db0::BSFaceGenAnimationData *)(((::fnv_00524db0::BSFaceGenAnimationData *)(::FUN_00524c90()))), ::DAT_0101e704))
        flag7 = false;
    reinterpret_cast<::FUN_00439ef0_class *>((((::fnv_00524db0::P12 *)(::FUN_0045bb80((int)(node3))))))->FUN_00439ef0((::NiPoint3 *)(::fnv_00524db0::P12 *)(&aVec24), (*(const ::NiPoint3 *)(((::fnv_00524db0::P12 *)(::FUN_0045bb80((int)(((::fnv_00524db0::BSFaceGenAnimationData *)(::FUN_00524c90())))))))));
    if (((double)(reinterpret_cast<::NiPoint3 *>(&(aVec24))->ComputeMagnitude())) > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting640)))))))
        flag7 = false;
    if (flag7) {
    dword4 = ((::fnv_00524db0::SubA *)(reinterpret_cast<::FUN_004600d0_shell *>((this))->FUN_004600d0()))->vfn_14();
    point1 = *((::fnv_00524db0::P12 *)(::FUN_0045bb80((int)(node3))));
    matTmp = *(Mat36*)((::fnv_00524db0::Sub461130 *)(::FUN_00461130((int)(node3))));
    reinterpret_cast<::FUN_00439f50_class *>((((::fnv_00524db0::Sub461130 *)(::FUN_00461130((int)(node3))))))->FUN_00439f50(2, (::NiPoint3 *)(::fnv_00524db0::P12 *)(&obj34));
    f7c5 = -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting638))))));
    f9 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting638))))));
    reinterpret_cast<::FUN_0063c8a0_shell *>(&(obj34))->FUN_0063c8a0(((::fnv_00524db0::P12 *)(reinterpret_cast<::FUN_00416870_t *>(&(tempBCz))->FUN_00416870(::RandomFloat(f7c5, f9), ::RandomFloat(f7c5, f9), ::RandomFloat(f7c5, f9)))));
    reinterpret_cast<::MyPoint439180 *>(&(obj34))->FUN_00439180(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting636)))))));
    if (((int)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((paramHome8))->FUN_009306d0()))) {
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&ob88)), (*(const ::hkVector4 *)(((int)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((paramHome8))->FUN_009306d0())) + 0x4f0)));
        reinterpret_cast<::FUN_0063c8a0_shell *>(&(obj34))->FUN_0063c8a0(&ob88);
    }
    vecA0 = (*reinterpret_cast<::fnv_00524db0::P12 *>(&::DAT_011a946c));
    _fa8 = -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting639))))));
    f8c2 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting639))))));
    reinterpret_cast<::MyPoint439180 *>(&(vecA0))->FUN_00439180(1.0f + ::RandomFloat(_fa8, f8c2));
    ::FUN_00525340((float *)(::fnv_00524db0::P12 *)(&vecA0));
    reinterpret_cast<::FUN_00416870_t *>(&(temp6))->FUN_00416870(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting635)))))) * vecA0.x, 0.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting635)))))) * vecA0.z);
    obj14 = *((::fnv_00524db0::Sub461130 *)(::FUN_00461130((int)(node3))))->FUN_004b4500(&bufC3, &temp6);
    if (paramHome8 == (*reinterpret_cast<::fnv_00524db0::Param * *>(&::_g_thePlayer)) && !reinterpret_cast<::FUN_004eaf60_shell *>(((*reinterpret_cast<::fnv_00524db0::Param * *>(&::_g_thePlayer))))->FUN_004eaf60() && !reinterpret_cast<::FUN_00525430_Class *>(&((*reinterpret_cast<::fnv_00524db0::Obj2250 *>(&::g_011f2250))))->FUN_00525430()) {
        qA7 = new XObj(((void *)(reinterpret_cast<::LowProcess *>((param))->GetTarget())), ::FUN_0040ebd0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting637)))))), ::DAT_010162c0), dword4, param, &point1, &matTmp, &obj34, &obj14, 1.0f, 0, 1);
        reinterpret_cast<::Twin_007e6580 *>((qA7))->SetIsForegroundEffect(1);
    } else {
        qB7 = new XObj(((void *)(reinterpret_cast<::LowProcess *>((param))->GetTarget())), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00524db0::SettingObj *>(&::originalRuntimeFloatSetting637)))))), dword4, param, &point1, &matTmp, &obj34, &obj14, 1.0f, 0, 1);
    }
    }
    }
    }
    }
    }
    }
}
}  // namespace fnv_00524db0

// sub ecx, 0x3c ; jmp target  --  MSVC virtual adjustor thunk.
// The thunk converts the pointer to the second base sub-object back into a
// pointer to the complete object before jumping to the implementation.
struct PrimaryBase
{
    virtual void FUN_00525c00();
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
    virtual void FUN_00525c00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00525c00
    virtual void FUN_00525c00();
};

Derived::Derived()
{}

static float NI_HALF_PI;

float FUN_00a811f0(float y, float x);

inline float NiASin(float fValue)
{
    if (-1.0f < fValue)
    {
        if (fValue < 1.0f)
            return float(asin(fValue));
        else
            return NI_HALF_PI;
    }
    else
    {
        return -NI_HALF_PI;
    }
}

struct RotationMatrix_o2
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    bool FUN_00a59400(float& x, float& y, float& z);
};

// @fnv 0x00a59400
bool RotationMatrix_o2::FUN_00a59400(float& x, float& y, float& z)
{
    y = -NiASin(m21);
    if (y < NI_HALF_PI)
    {
        if (y > -NI_HALF_PI)
        {
            x = -FUN_00a811f0(-m01, m11);
            z = -FUN_00a811f0(-m20, m22);
            return true;
        }
        else
        {
            float fRmY = FUN_00a811f0(m02, m00);
            z = 0.0f;
            x = fRmY - z;
            return false;
        }
    }
    else
    {
        float fRpY = FUN_00a811f0(m02, m00);
        z = 0.0f;
        x = z - fRpY;
        return false;
    }
}

#include "generated/data/fallout_shared/tesobjectweap.inc"
