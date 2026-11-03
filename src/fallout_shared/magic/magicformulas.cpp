// fallout_shared/magic/magicformulas.cpp: FlaggedData (10 functions)

#include <cstdint>
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dd000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011d1000.h"
#include "magicformulas_packet.h"
// @fnv 0x0040e210
int FlaggedData::ContainsAnyFlag(unsigned int mask)
{
    return (flags & mask) != 0;
}
// Returns the result of FUN_00874480 on the object from FUN_004b7210 when it exists and its GetIndex is nonzero, otherwise 0.
// @fnv 0x00703350
intptr_t FlaggedData::GetPlayerValue()
{
    if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())) && ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((reinterpret_cast<QuestStage*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_009373f0())))
        return ::FUN_00874480((char *)(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))));
    return 0;
}

struct Setting_S
{
};

// Computes an effect cost from base cost, area, duration and magnitude, applying area, duration and magnitude modifiers and a range-target multiplier.
// @fnv 0x006490b0
float __cdecl CalcEffectCost(float afBaseEffectCost, int aiArea, int aiDuration, int aiMagnitude, bool abIsRangeTarget)
{
    float fdurationModifier;
    float fmagnitudeModifier;
    float fareaModifier;
    float fbaseCost;
    fareaModifier = FUN_00404010(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1114)))))) * (float)aiArea, 1.0f);
    fdurationModifier =
        afBaseEffectCost * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1115)))))) * (aiDuration == 0 ? 1.0f : (float)aiDuration);
    fmagnitudeModifier =
        aiMagnitude == 0 ? 1.0f : ::fnv_004dd130::FUN_004dd130((float)aiMagnitude, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1209)))))));
    fbaseCost = fareaModifier * fdurationModifier * fmagnitudeModifier;
    return (abIsRangeTarget ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1116)))))) : 1.0f) * fbaseCost;
}

// @fnv 0x006494b0
float FUN_006494b0(float afA, float afB)
{
    return ::fnv_004dd130::FUN_004dd130(afA, afB);
}

// Returns 0 if either input is at least g_d100, otherwise computes 1 - ((1 - a/g_d100) * (b/g_d100) + a/g_d100).
// @fnv 0x006492a0
float FUN_006492a0(float a, float b)
{
    if (a >= g_d100 || b >= g_d100)
        return 0.0f;
    float fResult;
    {
        float fNormA = a / g_d100;
        float fNormB = b / g_d100;
        fResult = 1.0f - ((1.0f - fNormA) * fNormB + fNormA);
    }
    return fResult;
}

struct GlobalObject_0045cfe0
{
};
// Scales afMagnitude by a runtime float setting and returns true if the result reaches the global int threshold or is at least aiTargetLevel.
// @fnv 0x006494d0
bool FUN_006494d0(int aiTargetLevel, float afMagnitude)
{
    float fScaledMagnitude;
    fScaledMagnitude = afMagnitude * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1183))))));
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011d1a14)))))) <= fScaledMagnitude)
        return true;
    else
        return aiTargetLevel <= fScaledMagnitude;
}

struct GlobalObject_0040e0b0
{
};

// @fnv 0x00649300
float ComputeBlastPower(int aiCost, int aiAgility, float afDistance, int aiLuck, int aiArea, float afFatiguePercentage)
{
    float fblastPower = 0.0f;
    float fdistanceRatio = 0.0f;
    if (aiAgility > 0)
    {
        fdistanceRatio = afDistance / (float)aiAgility;
        fdistanceRatio = fdistanceRatio * fdistanceRatio;
        fdistanceRatio = 1.0f - fdistanceRatio;
    }
    else
    {
        fdistanceRatio = 1.0f;
    }
    fblastPower =
        *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1133)))))) * fdistanceRatio * aiCost + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1132))))));
    float fLuck = (float)aiLuck;
    fblastPower = fblastPower - fLuck * *((float *)&(::FUN_00403e20((float *)&(::g_011d1cd0))));
    return fblastPower;
}

float FUN_006494b0(float f, float g);

// Returns 0 outside [afStart, afEnd]; otherwise scales afBase by a curve from afTime, afSkill and settings, with flag-dependent multipliers.
// @fnv 0x00649390
float __cdecl FUN_00649390(float afBase, float afTime, float afStart, float afEnd, bool abFlag1, float afSkill,
                           bool abFlag2)
{
    if (afTime < afStart || afTime > afEnd)
        return 0.0f;
    float fRatio9;
    float fFlag2Mult_;
    const float fMid = 12.0f;
    float fFlag1Mult4;
    {
        float fResult;
        float fSkillMult;
        if (afTime > fMid)
            fRatio9 = (fMid - afTime) / (fMid - afEnd);
        else
            fRatio9 = (fMid - afTime) / (fMid - afStart);
        fRatio9 = 1.0f - FUN_006494b0(fRatio9, 4.0f);
        fSkillMult = (1.0f - *((float *)&(::FUN_00403e20((float *)&(::g_011d1938))))) * afSkill + *((float *)&(::FUN_00403e20((float *)&(::g_011d1938))));
        fFlag1Mult4 = !abFlag1 ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1161)))))) : 1.0f;
        fFlag2Mult_ = abFlag2 ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1160)))))) : 1.0f;
        fResult = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1159)))))) * afBase * fRatio9 * fSkillMult * fFlag2Mult_ * fFlag1Mult4;
        return fResult;
    }
}

class GameSettingCollection;
union SETTING_VALUE
{
    float value;
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1117;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1118;

// Multiplies param_1 by the sum of two runtime float settings, the second weighted by one minus param_2 divided by g_d100.
// @fnv 0x00649180
float __cdecl ScaleBySettingBlend(float afValue, int aiPercent)
{
    float quotient = (float)(aiPercent / g_d100);
    float result = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1117))))->value +
                   (1.0f - quotient) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1118))))->value;
    return afValue * result;
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1119;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1120;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1121;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1122;
// Computes a band index from a linear combination of two global floats and argument, returning 0 to 4 based on which setting threshold it falls below.
// @fnv 0x006491d0
int GetBandIndex(float afValue)
{
    float f = *((float *)&(::FUN_00403e20((float *)&(::g_011d158c)))) + *((float *)&(::FUN_00403e20((float *)&(::g_011d1b98)))) * afValue;
    int r;
    if (f < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1119))))->value)
    {
        r = 0;
    }
    else
    {
        int b;
        if (f < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1120))))->value)
        {
            b = 1;
        }
        else
        {
            int c;
            if (f < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1121))))->value)
            {
                c = 2;
            }
            else
            {
                int d;
                if (f < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1122))))->value)
                    d = 3;
                else
                    d = 4;
                c = d;
            }
            b = c;
        }
        r = b;
    }
    return r;
}
