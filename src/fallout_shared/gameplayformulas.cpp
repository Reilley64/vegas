
// fallout_shared/gameplayformulas.cpp
// ActorValueUtility::ConvertActorValue (0x00648b50).
//
// XP thresholds come from two SettingT<GameSettingCollection> globals
// (iXPBase / iXPBumpBase). The canonical Setting.h omits the vanilla value
// accessors, so the needed declarations are authored locally for this TU,
// following the accepted actionpoints.cpp precedent.

#include <cstdint>
#include "fnv/decl/FUN_00476b90_shell.h"
#include "fnv/decl/TypeCheck646.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004dd000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
union SETTING_VALUE
{
  public:
    const char* str;  // +0x0
    int i;            // +0x0
    unsigned int u;   // +0x0
    float f;          // +0x0
    bool b;           // +0x0
    char c;           // +0x0
    unsigned char h;  // +0x0
};

struct GameSettingCollection
{
};

class SettingT_GameSettingCollection_
{
  public:
    SettingT_GameSettingCollection_();
    ~SettingT_GameSettingCollection_();
};


class ActorValueUtility
{
  public:
    static int ConvertActorValue(int aiLevel);
};

// Returns 0 for levels <= 1, otherwise sums iXPBase plus repeated iXPBump increments across levels up to aiLevel - 1.
// @fnv 0x00648b50
int ActorValueUtility::ConvertActorValue(int aiLevel)
{
    if (aiLevel <= 1)
        return 0;
    int iTotal = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d03e8))))))->i;
    int iBase = iTotal;
    int iBump = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d0ae4))))))->i;
    for (int i = 1; i < aiLevel - 1; ++i)
    {
        iBase += iBump;
        iTotal += iBase;
    }
    return iTotal;
}

// @fnv 0x005be4d0
int FUN_005be4d0(char* pThis)
{
    return *(int*)(pThis + 0x7b8);
}

class SettingT_GameSettingCollection_2
{
  public:
};

class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};



// @fnv 0x00647c00
float __cdecl ComputeItemValue(float afItemValue, float afItemHealthPercent)
{
    float fvalue = afItemValue;
    float fcondition = afItemHealthPercent / 10.0;
    if (fcondition < 0.0)
    {
        fcondition = 10.0f;
    }
    if (fvalue > 0.0)
    {
        fvalue = (1.0 - ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(((SettingT_GameSettingCollection_2*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting870)))))))->f) * fvalue *
                     ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(((SettingT_GameSettingCollection_2*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting868)))))))->f *
                     ::fnv_004dd130::FUN_004dd130(fcondition,
                                  ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(((SettingT_GameSettingCollection_2*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting869)))))))->f) +
                 fvalue * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(((SettingT_GameSettingCollection_2*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting870)))))))->f;
    }
    return ((double)(::FUN_00408860(fvalue))) >= 1.0 ? InventoryStackRecord::RoundToNearestStep(fvalue, 1.0f) : fvalue;
}

template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting830;

// @fnv 0x00647f00
float __cdecl FUN_00647f00(void* apActor, void* apWeapon, void* pArmor, bool abNoWeapon, bool abIsNpc,
                           bool abIsSneaking, bool abOverEncumbered)
{
    float runSpeed = 0.0f;
    runSpeed += ::FUN_00647d10((::ActorValueOwner *)(apActor), (::TESObjectWEAP *)(apWeapon), (::TESObjectARMO *)(pArmor), abIsSneaking, abNoWeapon, abIsNpc, abOverEncumbered);
    runSpeed *= ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting830))))->f;
    return runSpeed;
}


struct SettingT_GameSettingCollection__Float_Access : public SettingT_GameSettingCollection_
{
};

// Returns the sum of the base float setting and aiEndurance multiplied by the per-point float setting.
// @fnv 0x00648a10
float __cdecl FUN_00648a10(intptr_t aiEndurance)
{
    return ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(((SettingT_GameSettingCollection__Float_Access*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting861)))))))->f +
           (float)aiEndurance *
               ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(((SettingT_GameSettingCollection__Float_Access*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting862)))))))->f;
}

double __cdecl _floor(float);

// Computes a floored value from aiIntelligence and DAT_01011588 plus 10, adding 1 when aiLevel is even and aiIntelligence is odd.
// @fnv 0x00648c10
int __cdecl ComputeIntelligenceResult(int aiIntelligence, int aiLevel)
{
    float fresult = (double)aiIntelligence * DAT_01011588 + 10.0;
    int iresult = _floor(fresult);
    if (aiLevel % 2 == 0 && aiIntelligence % 2 == 1)
    {
        iresult += 1;
    }
    return iresult;
}


// @fnv 0x00647f50
float __cdecl FUN_00647f50(void* apActor, void* apWeapon, void* pArmor, bool abIsNpc, bool abIsSneaking,
                           bool abOverEncumbered)
{
    float runSpeed = ::FUN_00647d10((::ActorValueOwner *)(apActor), (::TESObjectWEAP *)(apWeapon), (::TESObjectARMO *)(pArmor), false, abIsNpc, abIsSneaking, abOverEncumbered);
    return runSpeed;
}


// @fnv 0x00648d70
void __cdecl ComputeInjuryEffectScalars(float* afResistanceTime, float* afMagnitude, float* afMouseScalar,
                                        float afInjuryPercent, float afPainPercent, int aiMedicineSkill)
{
    *afResistanceTime =
        (float)(aiMedicineSkill / g_d100 * DAT_0104ee98 + (1.0 - afInjuryPercent) * 0.20000000298023224 +
                (1.0 - afPainPercent) * 0.10000000149011612);
    *afMagnitude = (float)((g_d100 - aiMedicineSkill) / g_d100 * DAT_0104ee98 + afInjuryPercent * 0.20000000298023224 +
                           afPainPercent * 0.10000000149011612);
    *afMouseScalar = (float)(aiMedicineSkill / g_d100 * DAT_0104ee98 + (1.0 - afInjuryPercent) * 0.20000000298023224 +
                             (1.0 - afPainPercent) * 0.10000000149011612);
}


// @fnv 0x00648e10
float ScaleByConstant(float afValue)
{
    return static_cast<float>(afValue * DAT_01012638);
}


// @fnv 0x00648e30
float ScaleLimbWoundPercent(float afLimbWoundPercent)
{
    return static_cast<float>(afLimbWoundPercent * DAT_01011588);
}

namespace ActorValue {
enum Index
{
    kNone = -1
};
}
class ActorValueOwner
{
  public:
    virtual float GetBaseActorValue(ActorValue::Index aeActorValueIndex);
    virtual int GetBaseActorValueI(ActorValue::Index aeActorValueIndex);
    virtual int GetActorValueI(ActorValue::Index aeActorValueIndex);
    virtual float GetActorValue(ActorValue::Index aeActorValueIndex);
};
struct Setting_S
{
};
class TESObjectWEAP
{
  public:
    int GetWeaponType() const;
};
class TESObjectARMO
{
  public:
    unsigned char GetArmorType();
};
struct CombatDamageCalculator
{
    static float __cdecl GetActorValueMultiplier(ActorValueOwner*, ActorValue::Index, bool);
};

// @fnv 0x00647d10
float FUN_00647d10(ActorValueOwner* pActor, TESObjectWEAP* pWeapon, TESObjectARMO* pArmor, bool bSneaking,
                   bool bIsPlayer, bool bScoped, bool bIgnoreSkill)
{
    float fMult = 0.0f;
    if (pArmor)
    {
        unsigned char ucWeight = pArmor->GetArmorType();
        if (ucWeight == 1)
            fMult += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting827))))));
        else if (ucWeight == 2)
            fMult += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting826))))));
    }
    if (pWeapon && !bIsPlayer && reinterpret_cast<::TypeCheck646 *>((pWeapon))->FUN_00646cb0())
    {
        if (pWeapon->GetWeaponType() == 8 || pWeapon->GetWeaponType() == 9)
            fMult += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting829))))));
        else if (pWeapon->GetWeaponType() != 2)
            fMult += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting828))))));
    }
    float fPenalty = (1.0f - CombatDamageCalculator::GetActorValueMultiplier(pActor, (ActorValue::Index)0x1d, false)) +
                     (1.0f - CombatDamageCalculator::GetActorValueMultiplier(pActor, (ActorValue::Index)0x1e, false));
    float fBase = 1.0f;
    if (fPenalty == 1.0)
        fBase = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1087))))));
    else if (fPenalty == 2.0)
        fBase = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1088))))));
    if (!bIgnoreSkill && pActor->GetActorValueI((ActorValue::Index)0x48))
        fBase = 1.0f;
    float fResult = pActor->GetActorValue((ActorValue::Index)0x15) * 1.1;
    float fCrippled = fResult * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting833)))))) * fBase;
    float fSkill = fCrippled;
    if (bScoped && bIsPlayer)
        fSkill *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting831))))));
    fSkill = (1.0f - fMult) * fSkill;
    if (bSneaking)
        fSkill *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting832))))));
    if (fSkill < ::_DAT_01012060)
        return 0.0f;
    return fSkill;
}

namespace fnv_00648090 {
struct Setting_S
{
};
class InventoryStackRecord
{
};

// @fnv 0x00648090
float ComputeSkillValue(int aiSkill, float afA, float afB, int* apResult)
{
    float fMaxBonus;
    float fTotal = 0.0f;
    afA = afA / 10.0;
    afB = afB / 10.0;
    fMaxBonus = (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting941)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting940))))))) * aiSkill / ::g_d100;
    float fSkillValue = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting942)))))) * ::FUN_0040ebd0(afA, afB);
    float fMin = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting943)))))) +
                 (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting944)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting943))))))) * aiSkill / 100.0f;
    float fSkillBonus = ::FUN_00404010(afA, afB);
    fTotal = fSkillBonus + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting940)))))) + fMaxBonus + fSkillValue;
    if (apResult)
    {
        if ((int)::InventoryStackRecord::RoundToNearestStep(fTotal * ::g_d100, 1.0f) <=
            (int)::InventoryStackRecord::RoundToNearestStep(fSkillBonus * ::g_d100, 1.0f))
            *apResult = (int)((fSkillBonus + (double)0.1f - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting943))))))) * ::g_d100 /
                              (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting944)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648090::Setting_S *>(&::originalRuntimeFloatSetting943))))))));
    }
    return fTotal * 10.0;
}
}  // namespace fnv_00648090

#include "bscore/bsrandom.h"

// @fnv 0x00648fa0
void ComputeMedicineHealing(float& afLimbHealPercent, float& afHealthDamagePercent, int aiMedicineSkill,
                            bool abMorphineUsed, float afWoundPercent)
{
    afLimbHealPercent = MersenneTwister::GetRandomGenerator()->FUN_00476b90(0.0f, aiMedicineSkill * g_d100 / g_d100 *
                                                                      (1.0 + abMorphineUsed * DAT_01011588));
    afHealthDamagePercent = MersenneTwister::GetRandomGenerator()->FUN_00476b90(
        0.0f, (aiMedicineSkill - g_d100) / g_d100 * ((afWoundPercent - g_d100) / g_d100) * g_d100 *
                  (1.0 - abMorphineUsed * DAT_01011588));
}

float __cdecl FUN_00647f00(void*, void*, void*, bool, bool, bool, bool);
// Calls FUN_00647f00 with the given actor, weapon, armor and flags, passing false for the sixth argument, and returns the resulting swim speed.
// @fnv 0x00647f90
float __cdecl GetSwimSpeed(void* apActor, void* apWeapon, void* pArmor, bool abNoWeapon, bool abIsNpc,
                           bool abOverEncumbered)
{
    float swimSpeed;
    swimSpeed = FUN_00647f00(apActor, apWeapon, pArmor, abNoWeapon, abIsNpc, false, abOverEncumbered);
    return swimSpeed;
}

namespace fnv_00648a50 {
struct Setting_S
{
};
template <typename T> class SettingT : public Setting_S
{
};
// @fnv 0x00648a50
float GetScaledLevelValue(int aiLevel)
{
    return (double)aiLevel * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648a50::SettingT< ::GameSettingCollection> *>(&::originalRuntimeFloatSetting863))))));
}
}  // namespace fnv_00648a50

namespace fnv_00648b00 {
struct Setting_S
{
};
// @fnv 0x00648b00
float __cdecl ScaleFloatSetting(float afValue, bool abApplySettings)
{
    float result = afValue / ::DAT_01012640;
    if (abApplySettings)
    {
        result = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648b00::Setting_S *>(&::originalRuntimeFloatSetting1092)))))) / ::DAT_01012640 +
                 result * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648b00::Setting_S *>(&::originalRuntimeFloatSetting1093))))));
    }
    return result;
}
}  // namespace fnv_00648b00

int __cdecl ComputeIntelligenceResult(int, int);
struct Dummy648bc0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int func1c(int);
    virtual void f8();
    virtual void f9();
    virtual unsigned short func28();
};
// Calls func1c(9), passes the result and 10 to MinInt, then passes that and func28() to ComputeIntelligenceResult and returns the result.
// @fnv 0x00648bc0
int __cdecl FUN_00648bc0(Dummy648bc0* apDummy)
{
    int v;
    v = ComputeIntelligenceResult(MinInt(apDummy->func1c(9), 10), apDummy->func28());
    return v;
}

namespace fnv_00648d30 {
struct Setting_S
{
};
// @fnv 0x00648d30
int FUN_00648d30(int aiPlayerSkill, int aiLockLevelMax)
{
    return ::FUN_00647b70(::MinInt(aiPlayerSkill - aiLockLevelMax + (int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00648d30::Setting_S *>(&::originalRuntimeFloatSetting1069)))))), 100), 0);
}
}  // namespace fnv_00648d30

// @fnv 0x00647cf0
float ConvertUIntToFloat(unsigned int auiValue)
{
    return (float)auiValue;
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting839;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting840;

// @fnv 0x00647fd0
float __cdecl FUN_00647fd0(ActorValueOwner* actor)
{
    float result;        // Actor-value coefficient.
    float scale = 0.0f;  // Running interpolated output.
    result = (float)(actor->GetActorValue((ActorValue::Index)21) * 0.01);
    scale = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting839))))->f;
    scale += (((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting840))))->f - ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting839))))->f) * result;
    if (scale < ::_DAT_01012060)
        return 0.0f;
    return scale;
}


// Computes two values from afBase, afDivisor and game settings, then applies type-dependent multipliers and flags to both.
// @fnv 0x006482f0
void __cdecl ComputeDerivedValues(float* afValue1, float* afValue2, float afDivisor, float afBase, int aiType,
                                  bool abFlag1, float afMult1, float afMult2, float afMult3, bool abFlag2)
{
    *afValue1 = ::fnv_004dd130::FUN_004dd130(afBase * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting947))))->f / afDivisor, 1.0 / (((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting1209))))->f + 1.0));
    *afValue2 = *afValue1 / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting947))))->f / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting1115))))->f;

    switch (aiType)
    {
    case 1:
        if (!abFlag1 && !abFlag2)
        {
            *afValue1 += afMult1 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting948))))->f * *afValue1;
            *afValue2 += afMult1 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting949))))->f * *afValue2;
        }
    case 2:
        if (abFlag1 && !abFlag2)
        {
            *afValue1 += afMult2 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting952))))->f * *afValue1;
            *afValue2 += afMult2 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting953))))->f * *afValue2;
        }
        break;
    case 5:
        if (abFlag1 && !abFlag2)
        {
            *afValue1 += afMult2 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting952))))->f * *afValue1 + afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue1;
            *afValue2 += afMult2 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting953))))->f * *afValue2 + afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue2;
        }
        else
        {
            *afValue1 += afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue1;
            *afValue2 += afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue2;
        }
    case 3:
        *afValue1 += afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue1;
        *afValue2 += afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue2;
        break;
    case 4:
        if (!abFlag1 && !abFlag2)
        {
            *afValue1 += *afValue1 * afMult1 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting948))))->f + *afValue2 * afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f;
            *afValue2 += *afValue2 * afMult1 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting949))))->f + *afValue2 * afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f;
        }
        else
        {
            *afValue1 += afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue1;
            *afValue2 += afMult3 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting950))))->f * *afValue2;
        }
        break;
    }
}


// Divides afValue by afDivisor and a runtime setting into pfResult, then adds scaled adjustments selected by aiType and the two flags.
// @fnv 0x00648620
void __cdecl ComputeScaledResult(float* pfResult, float afDivisor, float afValue, int aiType, bool abFlagA,
                                 float afScaleA, float afScaleB, float afScaleC, bool abFlagB)
{
    *pfResult = afValue / afDivisor / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1115))))));
    switch (aiType)
    {
    case 1:
        if (!abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleA * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting954))))));
        }
    case 2:
        if (abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleB * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting956))))));
        }
        break;
    case 3:
        *pfResult += *pfResult * afScaleC * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting955))))));
        break;
    case 5:
        if (abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleB * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting956)))))) +
                         *pfResult * afScaleC * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting955))))));
        }
        else
        {
            *pfResult += *pfResult * afScaleC * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting955))))));
        }
        break;
    case 4:
        if (!abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleA * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting954)))))) +
                         *pfResult * afScaleC * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting955))))));
        }
        else
        {
            *pfResult += *pfResult * afScaleC * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting955))))));
        }
        break;
    }
}

namespace fnv_00648810 {

// Computes a value from a and b via FUN_004dd130 and applies per-kind setting-based multipliers to it, writing the result to out.
// @fnv 0x00648810
void __cdecl ComputeSettingAdjustedValue(float* pfResult, float afDivisor, float afDividend, int kind, bool flag,
                                         float x, float y, float z, bool other)
{
    *pfResult = ::fnv_004dd130::FUN_004dd130((afDividend / afDivisor) / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting1115))))->f,
                             1.0f / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting1209))))->f);

    switch (kind)
    {
    case 1:
        if (!flag && !other)
            *pfResult = *pfResult + (*pfResult * x) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting957))))->f;
    case 2:
        if (flag && !other)
            *pfResult = *pfResult + (*pfResult * y) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting959))))->f;
        break;
    case 3:
        *pfResult = *pfResult + (*pfResult * z) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting958))))->f;
        break;
    case 5:
        if (flag && !other)
            *pfResult = *pfResult + (((*pfResult * y) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting959))))->f) * z) *
                                        ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting958))))->f;
        else
            *pfResult = *pfResult + (*pfResult * z) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting958))))->f;
        break;
    case 4:
        if (!flag && !other)
            *pfResult = *pfResult + (((*pfResult * x) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting957))))->f) * z) *
                                        ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting958))))->f;
        else
            *pfResult = *pfResult + (*pfResult * z) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting958))))->f;
        break;
    }
}
}  // namespace fnv_00648810

namespace fnv_00648a80 {
template <class T> class SettingT
{
};
// @fnv 0x00648a80
float ComputeSettingLerp(float fValue)
{
    if (fValue > ::FUN_00403e20((float*)&(*reinterpret_cast<::fnv_00648a80::SettingT< ::GameSettingCollection> *>(&::originalRuntimeFloatSetting1089))))
        return 0.0f;
    float fRatio = 1.0f - fValue / ::FUN_00403e20((float*)&(*reinterpret_cast<::fnv_00648a80::SettingT< ::GameSettingCollection> *>(&::originalRuntimeFloatSetting1089)));
    float fLerp = ::FUN_00403e20((float*)&(*reinterpret_cast<::fnv_00648a80::SettingT< ::GameSettingCollection> *>(&::originalRuntimeFloatSetting1090))) +
                  (::FUN_00403e20((float*)&(*reinterpret_cast<::fnv_00648a80::SettingT< ::GameSettingCollection> *>(&::originalRuntimeFloatSetting1091))) -
                   ::FUN_00403e20((float*)&(*reinterpret_cast<::fnv_00648a80::SettingT< ::GameSettingCollection> *>(&::originalRuntimeFloatSetting1090)))) *
                      fRatio;
    return fLerp;
}
}  // namespace fnv_00648a80

class Setting648
{
  public:
};


// Returns the sum of two setting values, with the second multiplied by fValue times 10.0f.
// @fnv 0x00648050
float __cdecl FUN_00648050(float fValue)
{
    return ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting648 *>(&::g_011d05ec))))))->f + ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting648 *>(&::g_011d0fd8))))))->f * (fValue * 10.0f);
}

class SettingD8230
{
  public:
};



// Computes a level-scaled multiplier from base/max settings and difficulty, clamps it to a minimum of 1.0, and returns the integer result.
// @fnv 0x00648230
int __cdecl GetLevelAdjustedMult(int iLevel, float fDiff, float fMult)
{
    int iResult = 0;
    float fValue = 0.0f;
    float fLevelValue =
        ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD8230 *>(&::originalRuntimeFloatSetting943)))) + (::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD8230 *>(&::originalRuntimeFloatSetting944)))) - ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD8230 *>(&::originalRuntimeFloatSetting943))))) * iLevel / 100.0f;
    fDiff = fDiff / 10.0;
    fValue = ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingD8230 *>(&::g_011d1158)))) * fMult * ((fLevelValue - fDiff) / 10.0);
    if (fValue > 0.5)
        iResult = FUN_00647b70((int)::InventoryStackRecord::RoundToNearestStep(fValue, 1.0f), 1);
    return iResult;
}

namespace fnv_00649050 {
struct Setting_S
{
    float fValue;
};
struct originalRuntimeFloatSetting1295_t
{
};
// Computes buy and sell price multipliers from skill-based float settings and writes them to the output pointers.
// @fnv 0x00649050
void FUN_00649050(int iSkill, float* pfBuyMult, float* pfSellMult)
{
    *pfBuyMult = ((::fnv_00649050::Setting_S *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00649050::originalRuntimeFloatSetting1295_t *>(&::originalRuntimeFloatSetting864))))))->fValue + ((::fnv_00649050::Setting_S *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00649050::originalRuntimeFloatSetting1295_t *>(&::originalRuntimeFloatSetting866))))))->fValue * iSkill / 100.0f;
    *pfSellMult = ((::fnv_00649050::Setting_S *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00649050::originalRuntimeFloatSetting1295_t *>(&::originalRuntimeFloatSetting865))))))->fValue + ((::fnv_00649050::Setting_S *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00649050::originalRuntimeFloatSetting1295_t *>(&::originalRuntimeFloatSetting867))))))->fValue * iSkill / 100.0f;
}
}  // namespace fnv_00649050
