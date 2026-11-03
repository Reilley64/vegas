// fallout_shared/tesimagespacemodifier.cpp: TESImageSpaceModifier, RgbaColor, ImageSpaceModifierEffectData, NiColorInterpolator and more (37 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0052ce20_shell.h"
#include "fnv/decl/FUN_0052cfc0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a3cc80_shell.h"
#include "fnv/decl/FUN_00a3d120_shell.h"
#include "fnv/decl/FUN_00b8af10_shell.h"
#include "fnv/decl/FUN_00b8af40_shell.h"
#include "fnv/decl/FUN_00b8af60_shell.h"
#include "fnv/decl/FUN_00b8af90_shell.h"
#include "fnv/decl/FUN_00b8afb0_shell.h"
#include "fnv/decl/FUN_00b8afe0_shell.h"
#include "fnv/decl/FUN_00b8b760_cls.h"
#include "fnv/decl/FUN_00b8cb30_cls.h"
#include "fnv/decl/FUN_00b8cc20_class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00b8b8d0__ImageSpaceDistanceEffect.h"
#include "fnv/decl/fnv_anon_tile__NiPoint2_Sub.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b8b000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011f3000.h"
#include "tesimagespacemodifier_decls.h"
// @fnv 0x0052bd40
void TESImageSpaceModifier::ResetFormData()
{
    int i, j, kKey;
    memset(&Data, 0, sizeof(Data));
    Data.m_bOverride = false;
    Data.fDuration = 1.0f;
    Data.m_bUseRadialBlur = false;
    Data.m_kRadialBlurCenter = NiPoint2(0.5f, 0.5f);
    Data.m_bUseEffectEntries = false;
    Data.m_ucEffectMode = 0;
    for (i = 0; i < 21; ++i)
        for (j = 0; j < 2; ++j)
        {
            Data.m_auiKeyframeCountsByTypeAndChannel[i][j] = 2;
            pEffectEntryTable[i][j] = new TimedFloatKey[2];
            for (kKey = 0; kKey < 2; ++kKey)
            {
                reinterpret_cast<::FUN_0052ce20_shell *>(&(pEffectEntryTable[i][j][kKey]))->FUN_0052ce20(DAT_0118aba0[kKey]);
                reinterpret_cast<::FUN_004f5d90_shell *>(&(pEffectEntryTable[i][j][kKey]))->FUN_004f5d90(DAT_0118aba8[j]);
            }
            m_akFloatInterpolators[i][j].SetAnimationKeys(
                pEffectEntryTable[i][j], Data.m_auiKeyframeCountsByTypeAndChannel[i][j], AnimationKey::LINKEY);
        }
    Data.m_uiEffectEntryCountFirst = 2;
    pFirstEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pFirstEffectRecordArray[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_0052cfc0_Class *>(&(pFirstEffectRecordArray[i]))->FUN_0052cfc0((::FUN_0052cfc0_Rect *)&(const ::RgbaColor &)(RgbaColor(1.0f, 1.0f, 1.0f, 0.0f)));
    }
    m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, Data.m_uiEffectEntryCountFirst,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTwelfth = 2;
    pSecondEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pSecondEffectRecordArray[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_0052cfc0_Class *>(&(pSecondEffectRecordArray[i]))->FUN_0052cfc0((::FUN_0052cfc0_Rect *)&(const ::RgbaColor &)(RgbaColor(1.0f, 1.0f, 1.0f, 0.0f)));
    }
    m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, Data.m_uiEffectEntryCountTwelfth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSecond = 2;
    pSecondEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pSecondEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pSecondEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, Data.m_uiEffectEntryCountSecond,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThird = 2;
    pThirdEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pThirdEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pThirdEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, Data.m_uiEffectEntryCountThird, AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFourth = 2;
    pTenthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pTenthEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pTenthEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, Data.m_uiEffectEntryCountFourth,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFifth = 2;
    pEleventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pEleventhEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pEleventhEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, Data.m_uiEffectEntryCountFifth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSixth = 2;
    pTwelfthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pTwelfthEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pTwelfthEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, Data.m_uiEffectEntryCountSixth,
                                                AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTenth = 2;
    pFourthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pFourthEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pFourthEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, Data.m_uiEffectEntryCountTenth,
                                               AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEleventh = 2;
    pFifthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pFifthEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pFifthEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, Data.m_uiEffectEntryCountEleventh,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSeventh = 2;
    pSeventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pSeventhEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pSeventhEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, Data.m_uiEffectEntryCountSeventh,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEighth = 2;
    pEighthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pEighthEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pEighthEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, Data.m_uiEffectEntryCountEighth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountNinth = 2;
    pNinthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pNinthEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pNinthEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, Data.m_uiEffectEntryCountNinth,
                                               AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThirteenth = 2;
    pSixthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        reinterpret_cast<::FUN_0052ce20_shell *>(&(pSixthEffectEntries[i]))->FUN_0052ce20(DAT_0118aba0[i]);
        reinterpret_cast<::FUN_004f5d90_shell *>(&(pSixthEffectEntries[i]))->FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, Data.m_uiEffectEntryCountThirteenth,
                                               AnimationKey::LINKEY);
    pIntroSound = 0;
    pOutroSound = 0;
}

// @fnv 0x00531720
void TESImageSpaceModifier::Apply(float startTime, float strength, NiAVObject* target)
{
    float effectTime;
    if (Data.m_bOverride)
        effectTime = (DAT_011c96fc - startTime) / Data.fDuration;
    else
        effectTime = 0.0f;
    FUN_005330e0(effectTime, 0.0f, 1.0f);
    ImageSpaceManager* pManager = ImageSpaceManager::FUN_004e3270();
    float pfParameterValues[2];
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 2; ++j)
            m_akFloatInterpolators[i][j].Update(effectTime, 0, pfParameterValues[j]);
        if (i >= 0 && i <= 13)
            reinterpret_cast<::FUN_00b8cb30_cls *>((pManager))->FUN_00b8cb30(1, i, pfParameterValues, strength);
        if (i >= 14 && i <= 16)
            reinterpret_cast<::FUN_00b8cb30_cls *>((pManager))->FUN_00b8cb30(0, i - 14, pfParameterValues, strength);
        if (i >= 17 && i <= 20)
            reinterpret_cast<::FUN_00b8cb30_cls *>((pManager))->FUN_00b8cb30(3, i - 17, pfParameterValues, strength);
    }
    RgbaColor kCurrentColor(0.0f, 0.0f, 0.0f, 0.0f);
    m_kColorInterpolatorOne.Update(effectTime, 0, kCurrentColor);
    kCurrentColor.a *= strength;
    FUN_005330e0(kCurrentColor.a, 0.0f, 1.0f);
    pManager->ApplyTintColorParamModifier(kCurrentColor);
    m_kColorInterpolatorTwo.Update(effectTime, 0, kCurrentColor);
    kCurrentColor.a *= strength;
    FUN_005330e0(kCurrentColor.a, 0.0f, 1.0f);
    pManager->SetFadeColorParamModifier(kCurrentColor);
    float interpolatedBlur;
    m_kFloatInterpolatorOne.Update(effectTime, 0, interpolatedBlur);
    float localDouble;
    m_kFloatInterpolatorTwo.Update(effectTime, 0, localDouble);
    float interpolatedRadialBlurStrength;
    m_kFloatInterpolatorNine.Update(effectTime, 0, interpolatedRadialBlurStrength);
    float fRadialBlurRampupResult;
    m_kFloatInterpolatorTen.Update(effectTime, 0, fRadialBlurRampupResult);
    float radialBlurStartOutput;
    m_kFloatInterpolatorEleven.Update(effectTime, 0, radialBlurStartOutput);
    float fRadialBlurRampDownSample;
    m_kFloatInterpolatorThree.Update(effectTime, 0, fRadialBlurRampDownSample);
    float radialBlurDownStartParameter;
    m_kFloatInterpolatorFour.Update(effectTime, 0, radialBlurDownStartParameter);
    float sampledDepthOfFieldStrength;
    m_kFloatInterpolatorFive.Update(effectTime, 0, sampledDepthOfFieldStrength);
    float fDepthOfFieldDistanceOutput;
    m_kFloatInterpolatorSix.Update(effectTime, 0, fDepthOfFieldDistanceOutput);
    float fCurrentDepthOfFieldRange;
    m_kFloatInterpolatorSeven.Update(effectTime, 0, fCurrentDepthOfFieldRange);
    float motionBlurSample;
    m_kFloatInterpolatorEight.Update(effectTime, 0, motionBlurSample);
    interpolatedBlur *= strength;
    FUN_005330e0(interpolatedBlur, 0.0f, ::g_011c76e8_arg1);
    reinterpret_cast<::FUN_00b8af10_shell *>((pManager))->RaiseHighestBlurRadius(interpolatedBlur);
    reinterpret_cast<::FUN_00b8afb0_shell *>((pManager))->FUN_00b8afb0(localDouble * strength);
    if (Data.m_bUseRadialBlur && target)
    {
        target->UpdateWorldBound();
        reinterpret_cast<::FUN_00b8b760_cls *>((pManager))->FUN_00b8b760(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult,
                               radialBlurStartOutput, fRadialBlurRampDownSample, radialBlurDownStartParameter,
                               (int)&((*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(target))->FUN_0043d450()))));
    }
    else if (Data.m_bUseRadialBlur)
        pManager->SetRadialBlurParameters(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult,
                                          radialBlurStartOutput, fRadialBlurRampDownSample,
                                          radialBlurDownStartParameter, NiPoint2(0.5f, 0.5f));
    else
        pManager->SetRadialBlurParameters(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult,
                                          radialBlurStartOutput, fRadialBlurRampDownSample,
                                          radialBlurDownStartParameter, Data.m_kRadialBlurCenter);
    if (Data.m_bUseEffectEntries && target)
    {
        target->UpdateWorldBound();
        reinterpret_cast<::fnv_00b8b8d0::ImageSpaceDistanceEffect *>((pManager))->SetDistanceEffect(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f,
                                    (const ::fnv_00b8b8d0::Point3 *)&((*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(target))->FUN_0043d450()))));
    }
    else if (Data.m_bUseEffectEntries)
        pManager->SetDepthOfFieldParameters(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f, 0.0f,
                                            1.0f);
    else
        pManager->SetDepthOfFieldParameters(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f,
                                            fDepthOfFieldDistanceOutput, fCurrentDepthOfFieldRange);
    reinterpret_cast<::FUN_00b8af60_shell *>((pManager))->RaiseBlurRadius(motionBlurSample);
}

// @fnv 0x00531d20
void TESImageSpaceModifier::EvaluateInterpolators(float startTime, float strength)
{
    float effectTime;
    if (Data.m_bOverride)
        effectTime = (DAT_011c96fc - startTime) / Data.fDuration;
    else
        effectTime = 0.0f;
    ImageSpaceManager* pManager = ImageSpaceManager::FUN_004e3270();
    float pfParameterValues[2];
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 2; ++j)
            m_akFloatInterpolators[i][j].Update(effectTime, 0, pfParameterValues[j]);
        if (i >= 0 && i <= 13)
            reinterpret_cast<::FUN_00b8cc20_class *>((pManager))->AccumulateComponentValues(1, i, pfParameterValues, strength);
        if (i >= 14 && i <= 16)
            reinterpret_cast<::FUN_00b8cc20_class *>((pManager))->AccumulateComponentValues(0, i - 14, pfParameterValues, strength);
        if (i >= 17 && i <= 20)
            reinterpret_cast<::FUN_00b8cc20_class *>((pManager))->AccumulateComponentValues(3, i - 17, pfParameterValues, strength);
    }
    RgbaColor kCurrentColor(0.0f, 0.0f, 0.0f, 0.0f);
    m_kColorInterpolatorOne.Update(effectTime, 0, kCurrentColor);
    kCurrentColor.FUN_005321d0(strength);
    pManager->ApplyTintColorParamModifierWeather(kCurrentColor);
    m_kColorInterpolatorTwo.Update(effectTime, 0, kCurrentColor);
    kCurrentColor.FUN_005321d0(strength);
    pManager->ApplyFadeColorParamModifierWeather(kCurrentColor);
    float interpolatedBlur;
    m_kFloatInterpolatorOne.Update(effectTime, 0, interpolatedBlur);
    float localDouble;
    m_kFloatInterpolatorTwo.Update(effectTime, 0, localDouble);
    float interpolatedRadialBlurStrength;
    m_kFloatInterpolatorNine.Update(effectTime, 0, interpolatedRadialBlurStrength);
    float fRadialBlurRampupResult;
    m_kFloatInterpolatorTen.Update(effectTime, 0, fRadialBlurRampupResult);
    float radialBlurStartOutput;
    m_kFloatInterpolatorEleven.Update(effectTime, 0, radialBlurStartOutput);
    float fRadialBlurRampDownSample;
    m_kFloatInterpolatorThree.Update(effectTime, 0, fRadialBlurRampDownSample);
    float radialBlurDownStartParameter;
    m_kFloatInterpolatorFour.Update(effectTime, 0, radialBlurDownStartParameter);
    float sampledDepthOfFieldStrength;
    m_kFloatInterpolatorFive.Update(effectTime, 0, sampledDepthOfFieldStrength);
    float fDepthOfFieldDistanceOutput;
    m_kFloatInterpolatorSix.Update(effectTime, 0, fDepthOfFieldDistanceOutput);
    float fCurrentDepthOfFieldRange;
    m_kFloatInterpolatorSeven.Update(effectTime, 0, fCurrentDepthOfFieldRange);
    float motionBlurSample;
    m_kFloatInterpolatorEight.Update(effectTime, 0, motionBlurSample);
    reinterpret_cast<::FUN_00b8af40_shell *>((pManager))->FUN_00b8af40(interpolatedBlur * strength);
    reinterpret_cast<::FUN_00b8afe0_shell *>((pManager))->AddDoubleVision(localDouble * strength);
    pManager->ApplyRadialBlurParamModifierWeather(interpolatedRadialBlurStrength * strength, fRadialBlurRampupResult * strength,
                           radialBlurStartOutput * strength, fRadialBlurRampDownSample * strength,
                           radialBlurDownStartParameter * strength, Data.m_kRadialBlurCenter * strength);
    pManager->ApplyDepthOfFieldParamModifierWeather(sampledDepthOfFieldStrength * strength, Data.m_ucEffectMode, 0.0f,
                           fDepthOfFieldDistanceOutput * strength, fCurrentDepthOfFieldRange * strength);
    reinterpret_cast<::FUN_00b8af90_shell *>((pManager))->FUN_00b8af90(motionBlurSample * strength);
}

// Sets the form type to IMAD, calls the initializer, and if this is the global instance DAT_011c9750 calls the second initializer.
// @fnv 0x0052b8f0
TESImageSpaceModifier::TESImageSpaceModifier()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_IMAD_ID)));
    ResetFormData();
    if (this == &(*reinterpret_cast<::TESImageSpaceModifier *>(&::g_011c9750)))
        NotifySaveLoadGameOfFormChange();
}
// @fnv 0x0052d260
void TESImageSpaceModifier::ClearData()
{
    for (int i = 0; i < 21; ++i)
        for (int j = 0; j < 2; ++j)
            reinterpret_cast<::FORenderedMenu *>(&(m_akFloatInterpolators[i][j]))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    m_kColorInterpolatorOne.SetColorData(0);
    m_kColorInterpolatorTwo.SetColorData(0);
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorOne))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorTwo))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorNine))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorTen))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorEleven))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorThree))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorFour))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorFive))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorSix))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorSeven))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    reinterpret_cast<::FORenderedMenu *>(&(m_kFloatInterpolatorEight))->SetDefaultTexture((::NiTexture *)(::NiFloatData *)(0));
    TESForm::ClearData();
    pIntroSound = 0;
    pOutroSound = 0;
}
// @fnv 0x0052d3d0
void TESImageSpaceModifier::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    unsigned int formID = (unsigned int)pIntroSound;
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pIntroSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pIntroSound)
            ::FUN_005b5e40();
    }
    formID = (unsigned int)pOutroSound;
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pOutroSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pOutroSound)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}
// @fnv 0x005316c0
bool TESImageSpaceModifier::IsExpired(float startTime)
{
    if (!Data.m_bOverride)
        return false;
    if (startTime < -10000.0)
        return false;
    return DAT_011c96fc - startTime > Data.fDuration;
}
// @fnv 0x005330a0
void TESImageSpaceModifier::InitializeModifierData()
{
    InitializeComponent();
    Data.m_bOverride = true;
    reinterpret_cast<::FUN_004f5d90_shell *>((pThirdEffectEntries))->FUN_004f5d90(0.005f);
}

// Multiplies the r, g, b and a components by scale and returns a reference to this object.
// @fnv 0x005321d0
RgbaColor& RgbaColor::FUN_005321d0(float scale)
{
    r *= scale;
    g *= scale;
    b *= scale;
    a *= scale;
    return *this;
}
// @fnv 0x0052bad0
TESImageSpaceModifier::ImageSpaceModifierEffectData::ImageSpaceModifierEffectData()
{}
// @fnv 0x0052d3b0
void NiColorInterpolator::SetColorData(NiColorData* apColorData)
{
    reinterpret_cast<TESImageSpaceColorDataPointer&>(m_spColorData) = apColorData;
}
// @fnv 0x00532fd0
NiPoint2 operator*(float scale, const NiPoint2& arPoint)
{
    return arPoint * scale;
}
// @fnv 0x00532ff0
TESImageSpaceModifier* GetDefaultImageSpaceModifier()
{
    return &(*reinterpret_cast<::TESImageSpaceModifier *>(&::g_011c9750));
}

struct NiStream;
struct blob12
{
    char b[12];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
struct ThreeByThreeMatrix
{
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

// Multiplies the point pt by the 3x3 matrix mat and stores the result in pOut, returning pOut.
// @fnv 0x004b3ae0
NiPoint3* FUN_004b3ae0(NiPoint3* pOut, const NiPoint3& pt, const float* mat)
{
    ((void(*)(NiPoint3*, float, float, float))(&NiPoint3::ComponentProduct))(
        pOut, pt.x * mat[0] + pt.y * mat[3] + pt.z * mat[6], pt.x * mat[1] + pt.y * mat[4] + pt.z * mat[7],
        pt.x * mat[2] + pt.y * mat[5] + pt.z * mat[8]);
    return pOut;
}

// @fnv 0x0052baf0
void ConstructFloatInterpolator(NiFloatInterpolator* pThis)
{
    pThis->NiFloatInterpolator::NiFloatInterpolator(0);
}

struct NiMemObject
{
    char _pad_0[1];
};

struct Obj52 : NiMemObject
{
    void* FUN_0052cf90(unsigned int);
    static void operator delete(void*, unsigned int);
};
// Calls FUN_00a3cc80, deletes this with size 0x18 when flags has bit 0 set, and returns this.
// @fnv 0x0052cf90
void* Obj52::FUN_0052cf90(unsigned int flags)
{
    reinterpret_cast<::FUN_00a3cc80_shell *>(this)->FUN_00a3cc80();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x18);
    return this;
}

namespace fnv_0052d130 {
struct Obj52 : NiMemObject
{
    void* FUN_0052d130(unsigned int);
    static void operator delete(void*, unsigned int);
};
// Calls FUN_00a3cc80, then deletes this with size 0x18 when flags has bit 0 set, and returns this.
// @fnv 0x0052d130
void* Obj52::FUN_0052d130(unsigned int flags)
{
    reinterpret_cast<::FUN_00a3d120_shell *>(this)->DestroyColorData();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x18);
    return this;
}
}  // namespace fnv_0052d130

// Clamps the float pointed to by aVal to the range [aMin, aMax], writing the bound back when it is out of range.
// @fnv 0x005330e0
void __cdecl FUN_005330e0(float* aVal, float aMin, float aMax)
{
    if (*aVal > aMax)
        *aVal = aMax;
    else if (*aVal < aMin)
        *aVal = aMin;
}

struct GlobalObjectO2_00a7b610;

struct FUN_0052cf80_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};

// @fnv 0x0052cf80
GlobalObjectO2_00a7b610* FUN_0052cf80_shell::GetGlobalObject()
{
    return &::g_011f3748;
}

namespace fnv_0052d120 {
struct NiRTTI;


struct NiColorData
{
    NiRTTI* GetRTTI() const;
};

// @fnv 0x0052d120
NiRTTI* NiColorData::GetRTTI() const
{
    return &(*reinterpret_cast<::fnv_0052d120::NiRTTI *>(&::g_011f3750));
}
}  // namespace fnv_0052d120

struct GlobalObject_0052b8f0
{
    ~GlobalObject_0052b8f0();
    void* Destroy(unsigned int flags);
};


struct FUN_00533060_shell
{
    void* FUN_00533060(void** a, void** b, char* c);
};
// @fnv 0x00533060
void* FUN_00533060_shell::FUN_00533060(void** apFirst, void** apSecond, char* c)
{
    *apFirst = *(void**)((char*)this + 8);
    *apSecond = *(void**)((char*)this + 0x10);
    *c = *(char*)((char*)this + 0x14);
    return *(void**)((char*)this + 0xc);
}

namespace fnv_00533000 {
struct Flt
{
    operator unsigned int();
};
struct FUN_00533060_shell
{
};
struct FUN_00533000_shell
{
    char _pad[16];
    Flt m_kHandle;
    void* FUN_00533000(void**, void**, char*);
};
// If the stored pointer is non-null, forwards to FUN_00533060; otherwise zeroes the three output pointers and returns null.
// @fnv 0x00533000
void* FUN_00533000_shell::FUN_00533000(void** a, void** b, char* c)
{
    if ((unsigned int)m_kHandle)
        return reinterpret_cast<::FUN_00533060_shell *>((((FUN_00533060_shell*)(unsigned int)m_kHandle)))->FUN_00533060(a, b, c);
    *a = 0;
    *b = 0;
    *c = 0;
    return 0;
}
}  // namespace fnv_00533000

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_0052bb70
{
    virtual ~FUN_0052bb70();
    char pad[0x20];
};

struct FUN_0052bbd0 : Base5a
{
    char pad[0x110];
    NiFloatInterpolator m_akFloatInterpolators[21][2];
    NiFloatInterpolator m_kFloatInterpolatorOne, m_kFloatInterpolatorTwo;
    FUN_0052bb70 m_kColorInterpolatorOne, m_kColorInterpolatorTwo;
    NiFloatInterpolator m_kFloatInterpolatorNine, m_kFloatInterpolatorTen, m_kFloatInterpolatorEleven,
        m_kFloatInterpolatorThree, m_kFloatInterpolatorFour;
    NiFloatInterpolator m_kFloatInterpolatorFive, m_kFloatInterpolatorSix, m_kFloatInterpolatorSeven,
        m_kFloatInterpolatorEight;
    ~FUN_0052bbd0();
};
// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0052baa0
void* GlobalObject_0052b8f0::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_0052bbd0 *>(this)->FUN_0052bbd0::~FUN_0052bbd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls TESImageSpaceModifier::ClearData on this object.
// @fnv 0x0052bbd0
FUN_0052bbd0::~FUN_0052bbd0()
{
    ((TESImageSpaceModifier*)this)->TESImageSpaceModifier::ClearData();
}

struct FUN_00532e40_s
{
    float x;
    float y;
    float z;
    float w;
    FUN_00532e40_s* AddDelta(FUN_00532e40_s* result, float* delta);
};

// @fnv 0x00532e40
FUN_00532e40_s* FUN_00532e40_s::AddDelta(FUN_00532e40_s* result, float* delta)
{
    FUN_00532e40_s temp = *this;
    temp.x += delta[0];
    temp.y += delta[1];
    temp.z += delta[2];
    temp.w += delta[3];
    *result = temp;
    return result;
}

struct FUN_00532ec0_v4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00532ec0
{
    FUN_00532ec0_v4* SUB(FUN_00532ec0_v4* result, const FUN_00532ec0_v4& sub);
};
// Subtracts the components of sub from this vector and stores the result in result, returning result.
// @fnv 0x00532ec0
FUN_00532ec0_v4* FUN_00532ec0::SUB(FUN_00532ec0_v4* result, const FUN_00532ec0_v4& sub)
{
    FUN_00532ec0_v4 tmp = *(FUN_00532ec0_v4*)this;
    tmp.x -= sub.x;
    tmp.y -= sub.y;
    tmp.z -= sub.z;
    tmp.w -= sub.w;
    *result = tmp;
    return result;
}

struct FUN_0052ed90_shell
{
};

struct FUN_005e79a0_t
{
};

struct FUN_005310b0_shell
{
    bool FUN_005310b0(TESForm* form);
};

int __cdecl _memcmp(const void* left, const void* right, unsigned int count);
void* __cdecl FUN_00ec43fb(void* object, unsigned int type, void* data, const void* typeInfo, unsigned char option);

struct FUN_00531490_shell
{
    void SwapEndian();
};
// Loads an IMAD record: reads the header, EDID/OBND/DNAM chunks and per-chunk arrays of entries, converting endianness and filling the linked lists.
// @fnv 0x0052d510
bool TESImageSpaceModifier::Load(TESFile* file)
{
    bool loadedData;
    unsigned char form = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (form != ENUM_FORM_ID_IMAD_ID)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    loadedData = false;
    while (int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_DNAM_ID:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), sizeof(Data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00531490_shell *>(&(Data))->SwapEndian();
            loadedData = true;
            break;
        case CHUNK_ID_BNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountSecond;
            pSecondEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pSecondEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSecondEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_VNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountThird;
            pThirdEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pThirdEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pThirdEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_RNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountFourth;
            pTenthEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pTenthEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pTenthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_SNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountFifth;
            pEleventhEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEleventhEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pEleventhEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_UNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountSixth;
            pTwelfthEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pTwelfthEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pTwelfthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM1_ID: {
            unsigned int count = Data.m_uiEffectEntryCountTenth;
            pFourthEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pFourthEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pFourthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM2_ID: {
            unsigned int count = Data.m_uiEffectEntryCountEleventh;
            pFifthEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pFifthEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pFifthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_TNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountFirst;
            pFirstEffectRecordArray = new AlphaColor[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pFirstEffectRecordArray), count * sizeof(AlphaColor));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pFirstEffectRecordArray;
                for (unsigned int i = 0; i < count * sizeof(AlphaColor) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM3_ID: {
            unsigned int count = Data.m_uiEffectEntryCountTwelfth;
            pSecondEffectRecordArray = new AlphaColor[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pSecondEffectRecordArray), count * sizeof(AlphaColor));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSecondEffectRecordArray;
                for (unsigned int i = 0; i < count * sizeof(AlphaColor) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_WNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountSeventh;
            pSeventhEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pSeventhEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSeventhEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_XNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountEighth;
            pEighthEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEighthEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pEighthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_YNAM_ID: {
            unsigned int count = Data.m_uiEffectEntryCountNinth;
            pNinthEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pNinthEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pNinthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_NAM4_ID: {
            unsigned int count = Data.m_uiEffectEntryCountThirteenth;
            pSixthEffectEntries = new TimedFloatKey[count];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pSixthEffectEntries), count * sizeof(TimedFloatKey));
            if (file->IsEndianConversionRequired())
            {
                unsigned int* words = (unsigned int*)pSixthEffectEntries;
                for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                    ::FUN_00401080((int *)(unsigned int *)(&words[i]));
            }
            m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, count, AnimationKey::LINKEY);
            break;
        }
        case CHUNK_ID_RDSD_ID: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            pIntroSound = (TESSound*)sound;
            break;
        }
        case CHUNK_ID_RDSI_ID: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            pOutroSound = (TESSound*)sound;
            break;
        }
        default:
            if (chunk >= 0x44414900 && chunk <= 0x444149ff)
            {
                unsigned int count;
                int column;
                int row = chunk & 0x3f;
                column = (chunk & 0xc0) >> 6;
                count = Data.m_auiKeyframeCountsByTypeAndChannel[row][column];
                pEffectEntryTable[row][column] = new TimedFloatKey[count];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEffectEntryTable[row][column]), count * sizeof(TimedFloatKey));
                if (file->IsEndianConversionRequired())
                {
                    unsigned int* words = (unsigned int*)pEffectEntryTable[row][column];
                    for (unsigned int i = 0; i < count * sizeof(TimedFloatKey) / sizeof(unsigned int); ++i)
                        ::FUN_00401080((int *)(unsigned int *)(&words[i]));
                }
                m_akFloatInterpolators[row][column].SetAnimationKeys(pEffectEntryTable[row][column], count,
                                                                     AnimationKey::LINKEY);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x00531490
void FUN_00531490_shell::SwapEndian()
{
    int j;
    int i;

    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 4)));

    for (j = 0; j < 21; ++j)
    {
        for (i = 0; i < 2; ++i)
        {
            ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 8 + j * 8 + i * 4)));
        }
    }

    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xb4)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xb8)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xb0)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xec)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xbc)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xc0)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xc4)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xe4)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xe8)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xcc)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xd0)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xd4)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xd8)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xdc)));
    ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xf0)));
}

struct FUN_0045cec0
{
    ~FUN_0045cec0();
};

struct FUN_00a3ca30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~FUN_00a3ca30();
};

struct FUN_0052bb10 : public FUN_00a3ca30
{
    FUN_0045cec0 unk10;

    ~FUN_0052bb10();
};

FUN_0045cec0::~FUN_0045cec0()
{}

FUN_00a3ca30::~FUN_00a3ca30()
{}

// @fnv 0x0052bb10
FUN_0052bb10::~FUN_0052bb10()
{}

namespace Real {
struct InterpolatorBase
{
    unsigned int referenceCount;
    unsigned int flags;
    float lastTime;
    float currentTime;
    float startTime;
    float endTime;
    void* controller;
    ~InterpolatorBase();
};
struct ColorDataReference
{
    void* colorData;
    ~ColorDataReference();
};
struct FUN_0052bb70 : InterpolatorBase
{
    ColorDataReference colorData;
    ~FUN_0052bb70();
};
// Destructor for an interpolator that owns a ColorDataReference; the body is empty.
// @fnv 0x0052bb70
FUN_0052bb70::~FUN_0052bb70()
{}
}

struct SpawnedObject
{
    void Method(float* pOut, float f);
};

// @fnv 0x00532f40
float* __cdecl FUN_00532f40(float* pOut, float f, SpawnedObject* pObj)
{
    pObj->Method(pOut, f);
    return pOut;
}

struct FUN_00532f60_vec4
{
    float x;
    float y;
    float z;
    float w;
};

class FUN_00532f60_cls
{
  public:
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    FUN_00532f60_vec4* ScaleVector4(FUN_00532f60_vec4* out, float scale);
};

// Multiplies the four floats of this object by scale and writes the result to out, returning out.
// @fnv 0x00532f60
FUN_00532f60_vec4* FUN_00532f60_cls::ScaleVector4(FUN_00532f60_vec4* out, float scale)
{
    FUN_00532f60_vec4 vecScaled = *(FUN_00532f60_vec4*)this;
    vecScaled.x *= scale;
    vecScaled.y *= scale;
    vecScaled.z *= scale;
    vecScaled.w *= scale;
    *out = vecScaled;
    return out;
}

struct xA
{
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
    virtual int GetA(int i);
    virtual void v0e4();
    virtual void v0e8();
    virtual int GetB(int i);
    int m_kNextStreamField[5];
};

struct xB : xA
{
    int m_aiExtra[3];
};

struct xSkyX
{
    char _pad000[0x28];
    int m_aiA[21][2];
    int m_i0d0;
    int m_i0d4;
    int m_i0d8;
    int m_i0dc;
    int m_i0e0;
    int m_i0e4;
    char _pad0e8[0xc];
    int m_i0f4;
    int m_i0f8;
    int m_i0fc;
    char _pad100[0x4];
    int m_i104;
    int m_i108;
    int m_i10c;
    int m_i110;
    xA m_akObj[21][2];
    xA m_k504;
    xA m_k51c;
    xB m_k534;
    xB m_k558;
    xA m_k57c;
    xA m_k594;
    xA m_k5ac;
    xA m_k5c4;
    xA m_k5dc;
    xA m_k5f4;
    xA m_k60c;
    xA m_k624;
    xA m_k63c;
    int m_aiB[21][2];
    int m_i6fc;
    int m_i700;
    int m_i704;
    int m_i708;
    int m_i70c;
    int m_i710;
    int m_i714;
    int m_i718;
    int m_i71c;
    int m_i720;
    int m_i724;
    int m_i728;
    int m_i72c;
    void CacheObjectValues();
};
// Looks up the TESImageSpaceModifier matching form, updates both objects, and returns false only if all compared fields and arrays are identical.
// @fnv 0x005310b0
bool FUN_005310b0_shell::FUN_005310b0(TESForm* form)
{
    FUN_005310b0_shell* imageSpaceModifier;
    int i;
    int j;

    imageSpaceModifier =
        static_cast<FUN_005310b0_shell*>(FUN_00ec43fb(form, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &typeid(TESImageSpaceModifier), 0));

    if (!imageSpaceModifier)
        return true;

    reinterpret_cast<::xSkyX *>((reinterpret_cast<FUN_0052ed90_shell*>(this)))->CacheObjectValues();
    reinterpret_cast<::xSkyX *>((reinterpret_cast<FUN_0052ed90_shell*>(imageSpaceModifier)))->CacheObjectValues();

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1c) !=
        *reinterpret_cast<int*>(reinterpret_cast<char*>(imageSpaceModifier) + 0x1c))
        return true;

    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) !=
        *reinterpret_cast<int*>(reinterpret_cast<char*>(imageSpaceModifier) + 0x18))
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(reinterpret_cast<TESForm*>(imageSpaceModifier)))
        return true;

    if (_memcmp(reinterpret_cast<char*>(this) + 0x20, reinterpret_cast<char*>(imageSpaceModifier) + 0x20, 0xf4))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x6fc),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x6fc),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xd4) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x700),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x700),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xd8) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x704),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x704),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xd0) * 0x14))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x708),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x708),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10c) * 0x14))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x70c),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x70c),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xdc) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x710),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x710),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xe0) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x714),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x714),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xe4) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x718),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x718),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x104) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x71c),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x71c),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x108) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x720),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x720),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xf4) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x724),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x724),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xf8) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x728),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x728),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xfc) * 8))
        return true;

    if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x72c),
                *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x72c),
                *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x110) * 8))
        return true;

    for (i = 0; i < 0x15; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            if (_memcmp(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x654 + i * 8 + j * 4),
                        *reinterpret_cast<void**>(reinterpret_cast<char*>(imageSpaceModifier) + 0x654 + i * 8 + j * 4),
                        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x28 + i * 8 + j * 4) * 8))
                return true;
        }
    }

    return false;
}

// Copies GetA(0) and GetB(0) from each m_akObj entry and each m_k* object into the parallel m_aiA/m_aiB and m_i* fields.
// @fnv 0x0052ed90
void xSkyX::CacheObjectValues()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            m_aiA[i][j] = m_akObj[i][j].GetA(0);
            m_aiB[i][j] = m_akObj[i][j].GetB(0);
        }
    }
    m_i0d4 = m_k504.GetA(0);
    m_i6fc = m_k504.GetB(0);
    m_i0d8 = m_k51c.GetA(0);
    m_i700 = m_k51c.GetB(0);
    m_i0d0 = m_k534.GetA(0);
    m_i704 = m_k534.GetB(0);
    m_i10c = m_k558.GetA(0);
    m_i708 = m_k558.GetB(0);
    m_i0dc = m_k57c.GetA(0);
    m_i70c = m_k57c.GetB(0);
    m_i0e0 = m_k594.GetA(0);
    m_i710 = m_k594.GetB(0);
    m_i0e4 = m_k5ac.GetA(0);
    m_i714 = m_k5ac.GetB(0);
    m_i104 = m_k5c4.GetA(0);
    m_i718 = m_k5c4.GetB(0);
    m_i108 = m_k5dc.GetA(0);
    m_i71c = m_k5dc.GetB(0);
    m_i0f4 = m_k5f4.GetA(0);
    m_i720 = m_k5f4.GetB(0);
    m_i0f8 = m_k60c.GetA(0);
    m_i724 = m_k60c.GetB(0);
    m_i0fc = m_k624.GetA(0);
    m_i728 = m_k624.GetB(0);
    m_i110 = m_k63c.GetA(0);
    m_i72c = m_k63c.GetB(0);
}

struct FUN_004855a0_shell
{
};
struct FUN_00485680_shell
{
};
struct FUN_0052f250_shell : TESImageSpaceModifier
{
    void WriteToStream();
};
// Serializes the image space modifier: writes a header, then each data array (endian-swapped when needed) with its tag, plus intro/outro sound form IDs.
// @fnv 0x0052f250
void FUN_0052f250_shell::WriteToStream()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    reinterpret_cast<::xSkyX *>((((FUN_0052ed90_shell*)this)))->CacheObjectValues();
    if (((bool)(::FUN_00401500())))
        ((FUN_00531490_shell*)&Data)->SwapEndian();
    ::AppendChunk(0x4d414e44, &Data, 0xf4);
    if (((bool)(::FUN_00401500())))
        ((FUN_00531490_shell*)&Data)->SwapEndian();
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountSecond / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSecondEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e42, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountThird / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pThirdEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e56, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 20;
        unsigned int count = size * Data.m_uiEffectEntryCountFirst / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pFirstEffectRecordArray, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e54, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 20;
        unsigned int count = size * Data.m_uiEffectEntryCountTwelfth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSecondEffectRecordArray, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x334d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountFourth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pTenthEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e52, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountFifth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pEleventhEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e53, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountSixth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pTwelfthEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e55, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountTenth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pFourthEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x314d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountEleventh / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pFifthEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x324d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountSeventh / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSeventhEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e57, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountEighth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pEighthEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e58, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountNinth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pNinthEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x4d414e59, dataTmp, count * 4);
        delete[] dataTmp;
    }
    {
        unsigned int size = 8;
        unsigned int count = size * Data.m_uiEffectEntryCountThirteenth / 4;
        unsigned int* dataTmp = new unsigned int[count];
        __memcpy(dataTmp, pSixthEffectEntries, count * 4);
        if (((bool)(::FUN_00401500())))
            for (unsigned int idx = 0; idx < count; idx++)
                ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
        ::AppendChunk(0x344d414e, dataTmp, count * 4);
        delete[] dataTmp;
    }
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 2; j++)
        {
            unsigned int tag = 0x44414900 | i | (j << 6);
            unsigned int size = 8;
            unsigned int count2 = size * Data.m_auiKeyframeCountsByTypeAndChannel[i][j] / 4;
            unsigned int* dataTmp = new unsigned int[count2];
            __memcpy(dataTmp, pEffectEntryTable[i][j], count2 * 4);
            if (((bool)(::FUN_00401500())))
                for (unsigned int idx = 0; idx < count2; idx++)
                    ::FUN_00401080((int *)(unsigned int *)(dataTmp + idx));
            ::AppendChunk(tag, dataTmp, count2 * 4);
            delete[] dataTmp;
        }
    if (pIntroSound)
    {
        unsigned int intro = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pIntroSound))->FUN_0084e3a0()));
        ::FUN_00485910(0x44534452, intro);
    }
    if (pOutroSound)
    {
        unsigned int outro = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pOutroSound))->FUN_0084e3a0()));
        ::FUN_00485910(0x49534452, outro);
    }
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

extern char _DAT_011862b8;
struct PassPtr
{
    TESImageSpaceModifier* value;
};
extern "C" void FUN_004851b0(TESImageSpaceModifier*, PassPtr);
struct CopyBaseShell
{
    void FUN_004851b0(TESImageSpaceModifier*);
};
struct TESImageSpaceModifierCopy : TESImageSpaceModifier
{
    void FUN_00530160(TESForm*);
};
// Looks up a TESImageSpaceModifier by form, clears this object's data, then copies its sounds, Data struct and all list arrays into newly allocated storage.
// @fnv 0x00530160
void TESImageSpaceModifierCopy::FUN_00530160(TESForm* form)
{
    unsigned int count;
    TESImageSpaceModifier* source = (TESImageSpaceModifier*)FUN_00ec43fb(form, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &_DAT_011862b8, 0);
    if (!source)
        return;
    reinterpret_cast<::xSkyX *>((source))->CacheObjectValues();
    reinterpret_cast<::FormCloneOperation *>((this))->FUN_004851b0((*(void * *)&(const ::PassPtr &)(*(PassPtr*)&source)));
    ClearData();
    pIntroSound = source->pIntroSound;
    pOutroSound = source->pOutroSound;
    ::__memcpy(&Data, &source->Data, sizeof(Data));
    count = Data.m_uiEffectEntryCountSecond;
    pSecondEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pSecondEffectEntries, source->pSecondEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountThird;
    pThirdEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pThirdEffectEntries, source->pThirdEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountFirst;
    pFirstEffectRecordArray = new AlphaColor[count];
    ::__memcpy(pFirstEffectRecordArray, source->pFirstEffectRecordArray, count * sizeof(AlphaColor));
    m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountTwelfth;
    pSecondEffectRecordArray = new AlphaColor[count];
    ::__memcpy(pSecondEffectRecordArray, source->pSecondEffectRecordArray, count * sizeof(AlphaColor));
    m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountFourth;
    pTenthEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pTenthEffectEntries, source->pTenthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountFifth;
    pEleventhEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pEleventhEffectEntries, source->pEleventhEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountSixth;
    pTwelfthEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pTwelfthEffectEntries, source->pTwelfthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountTenth;
    pFourthEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pFourthEffectEntries, source->pFourthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountEleventh;
    pFifthEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pFifthEffectEntries, source->pFifthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountSeventh;
    pSeventhEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pSeventhEffectEntries, source->pSeventhEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountEighth;
    pEighthEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pEighthEffectEntries, source->pEighthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountNinth;
    pNinthEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pNinthEffectEntries, source->pNinthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, count, AnimationKey::LINKEY);
    count = Data.m_uiEffectEntryCountThirteenth;
    pSixthEffectEntries = new TimedFloatKey[count];
    ::__memcpy(pSixthEffectEntries, source->pSixthEffectEntries, count * sizeof(TimedFloatKey));
    m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, count, AnimationKey::LINKEY);
    {
        int j;
        for (int i = 0; i < 21; ++i)
        {
            for (j = 0; j < 2; ++j)
            {
                count = Data.m_auiKeyframeCountsByTypeAndChannel[i][j];
                pEffectEntryTable[i][j] = new TimedFloatKey[count];
                ::__memcpy(pEffectEntryTable[i][j], source->pEffectEntryTable[i][j], count * sizeof(TimedFloatKey));
                m_akFloatInterpolators[i][j].SetAnimationKeys(pEffectEntryTable[i][j], count, AnimationKey::LINKEY);
            }
        }
    }
}

struct BlendColor
{
    float r, g, b, a;
    BlendColor(float, float, float, float);
    BlendColor FUN_00532ec0(const BlendColor&) const;
};
BlendColor FUN_00532f40(float, const BlendColor&);
struct BlendPoint
{
    float x, y;
    BlendPoint();
    BlendPoint(float, float);
    BlendPoint FUN_004dfe30(const BlendPoint&) const;
};
BlendPoint FUN_00532fd0(float, const BlendPoint&);
struct BlendImageManager : ImageSpaceManager
{
};
TESImageSpaceModifier* FUN_00532ff0();
// Interpolates two TESImageSpaceModifiers by blend and strength and pushes the blended values into the ImageSpaceManager.
// @fnv 0x00532220
void BlendImageSpaceModifiers(float blend, TESImageSpaceModifier* pPreviousModifier,
                              TESImageSpaceModifier* pNextModifier, float previousStrength, float nextStrength,
                              NiAVObject* previousTarget, NiAVObject* nextTarget)
{
    if (!pPreviousModifier)
        pPreviousModifier = FUN_00532ff0();
    if (!pNextModifier)
        pNextModifier = FUN_00532ff0();
    float time = 0.0f;
    BlendImageManager* manager4 = (BlendImageManager*)ImageSpaceManager::FUN_004e3270();
    float strength_15 = previousStrength + blend * (nextStrength - previousStrength);
    float values[2];
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            float first, second6;
            pPreviousModifier->m_akFloatInterpolators[i][j].Update(time, 0, first);
            pNextModifier->m_akFloatInterpolators[i][j].Update(time, 0, second6);
            values[j] = first + blend * (second6 - first);
        }
        if (i >= 0 && i <= 13)
            reinterpret_cast<::FUN_00b8cb30_cls *>((manager4))->FUN_00b8cb30(1, i, values, strength_15);
        if (i >= 14 && i <= 16)
            reinterpret_cast<::FUN_00b8cb30_cls *>((manager4))->FUN_00b8cb30(0, i - 14, values, strength_15);
        if (i >= 17 && i <= 20)
            reinterpret_cast<::FUN_00b8cb30_cls *>((manager4))->FUN_00b8cb30(3, i - 17, values, strength_15);
    }
    BlendColor color(0, 0, 0, 0), aFirstColor(0, 0, 0, 0), secondColor(0, 0, 0, 0);
    pPreviousModifier->m_kColorInterpolatorOne.Update(time, 0, (RgbaColor&)aFirstColor);
    pNextModifier->m_kColorInterpolatorOne.Update(time, 0, (RgbaColor&)secondColor);
    color = (*(::BlendColor *)(reinterpret_cast<::FUN_00532e40_s *>((void *)&(aFirstColor))->AddDelta((::FUN_00532e40_s *)&(const ::BlendColor &)(FUN_00532f40(blend, (*(::BlendColor *)(reinterpret_cast<::FUN_00532ec0 *>((void *)&(secondColor))->SUB((::FUN_00532ec0_v4 *)&(aFirstColor), *(const ::FUN_00532ec0_v4 *)nullptr))))), {})));
    color.a *= strength_15;
    FUN_005330e0(color.a, 0.0f, 1.0f);
    manager4->ApplyTintColorParamModifier((RgbaColor&)color);
    pPreviousModifier->m_kColorInterpolatorTwo.Update(time, 0, (RgbaColor&)aFirstColor);
    pNextModifier->m_kColorInterpolatorTwo.Update(time, 0, (RgbaColor&)secondColor);
    color = (*(::BlendColor *)(reinterpret_cast<::FUN_00532e40_s *>((void *)&(aFirstColor))->AddDelta((::FUN_00532e40_s *)&(const ::BlendColor &)(FUN_00532f40(blend, (*(::BlendColor *)(reinterpret_cast<::FUN_00532ec0 *>((void *)&(secondColor))->SUB((::FUN_00532ec0_v4 *)&(aFirstColor), *(const ::FUN_00532ec0_v4 *)nullptr))))), {})));
    color.a *= strength_15;
    FUN_005330e0(color.a, 0.0f, 1.0f);
    manager4->SetFadeColorParamModifier((RgbaColor&)color);
    float firstValue, secondValue3;
    pPreviousModifier->m_kFloatInterpolatorOne.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorOne.Update(time, 0, secondValue3);
    float blur2 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorTwo.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorTwo.Update(time, 0, secondValue3);
    float doubleVision = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorNine.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorNine.Update(time, 0, secondValue3);
    float kRadialStrength = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorTen.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorTen.Update(time, 0, secondValue3);
    float radialRampUp_19 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorEleven.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorEleven.Update(time, 0, secondValue3);
    float radialStart_8 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorThree.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorThree.Update(time, 0, secondValue3);
    float radialRampDown_15 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorFour.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorFour.Update(time, 0, secondValue3);
    float radialDownStart_3 = firstValue + blend * (secondValue3 - firstValue);
    pPreviousModifier->m_kFloatInterpolatorFive.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorFive.Update(time, 0, secondValue3);
    float depthStrength_4 = firstValue + blend * (secondValue3 - firstValue);
    float firstDepthDistance_, secondDepthDistance, firstDepthRange_2, secondDepthRange_12;
    pPreviousModifier->m_kFloatInterpolatorSix.Update(time, 0, firstDepthDistance_);
    pNextModifier->m_kFloatInterpolatorSix.Update(time, 0, secondDepthDistance);
    pPreviousModifier->m_kFloatInterpolatorSeven.Update(time, 0, firstDepthRange_2);
    pNextModifier->m_kFloatInterpolatorSeven.Update(time, 0, secondDepthRange_12);
    pPreviousModifier->m_kFloatInterpolatorEight.Update(time, 0, firstValue);
    pNextModifier->m_kFloatInterpolatorEight.Update(time, 0, secondValue3);
    float motion_24 = firstValue + blend * (secondValue3 - firstValue);
    blur2 *= strength_15;
    FUN_005330e0(blur2, 0.0f, 7.0f);
    reinterpret_cast<::FUN_00b8af10_shell *>((manager4))->RaiseHighestBlurRadius(blur2);
    reinterpret_cast<::FUN_00b8afb0_shell *>((manager4))->FUN_00b8afb0(doubleVision * strength_15);
    BlendPoint aFirstCenter(0.5f, 0.5f), secondCenter5(0.5f, 0.5f), center7;
    if (pPreviousModifier->Data.m_bUseRadialBlur && previousTarget)
    {
        previousTarget->UpdateWorldBound();
        ::FUN_00b8b1c0((int)(manager4), (int)&((*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(previousTarget))->FUN_0043d450()))));
    }
    if (pNextModifier->Data.m_bUseRadialBlur && nextTarget)
    {
        previousTarget->UpdateWorldBound();
        ::FUN_00b8b1c0((int)(manager4), (int)&((*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(nextTarget))->FUN_0043d450()))));
    }
    if (!pPreviousModifier->Data.m_bUseRadialBlur)
        aFirstCenter = (const BlendPoint&)pPreviousModifier->Data.m_kRadialBlurCenter;
    if (!pNextModifier->Data.m_bUseRadialBlur)
        secondCenter5 = (const BlendPoint&)pNextModifier->Data.m_kRadialBlurCenter;
    center7 = aFirstCenter.FUN_004dfe30(FUN_00532fd0(blend, (*(::BlendPoint *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)&(secondCenter5))->Subtract((::NiPoint2 *)&(aFirstCenter), *(const ::NiPoint2 *)nullptr)))));
    manager4->SetRadialBlurParameters(kRadialStrength * strength_15, radialRampUp_19, radialStart_8, radialRampDown_15,
                                      radialDownStart_3, (const NiPoint2&)center7);
    BlendPoint firstDepthB(0, 0), secondDepth(0, 0), depth5;
    if (pPreviousModifier->Data.m_bUseEffectEntries && previousTarget)
    {
        previousTarget->UpdateWorldBound();
        ::fnv_00b8bb70::FUN_00b8bb70((::fnv_00b8bb70::NiPoint3 *)(manager4), (float *)&((*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(previousTarget))->FUN_0043d450()))));
    }
    if (pNextModifier->Data.m_bUseEffectEntries && nextTarget)
    {
        nextTarget->UpdateWorldBound();
        ::fnv_00b8bb70::FUN_00b8bb70((::fnv_00b8bb70::NiPoint3 *)(manager4), (float *)&((*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(nextTarget))->FUN_0043d450()))));
    }
    if (!pPreviousModifier->Data.m_bUseEffectEntries)
        firstDepthB = BlendPoint(firstDepthDistance_, firstDepthRange_2);
    if (!pNextModifier->Data.m_bUseEffectEntries)
        secondDepth = BlendPoint(secondDepthDistance, secondDepthRange_12);
    depth5 = firstDepthB.FUN_004dfe30(FUN_00532fd0(blend, (*(::BlendPoint *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)&(secondDepth))->Subtract((::NiPoint2 *)&(firstDepthB), *(const ::NiPoint2 *)nullptr)))));
    manager4->SetDepthOfFieldParameters(depthStrength_4 * strength_15,
                                        blend < 0.5 ? pPreviousModifier->Data.m_ucEffectMode
                                                    : pNextModifier->Data.m_ucEffectMode,
                                        0.0f, depth5.x, depth5.y);
    reinterpret_cast<::FUN_00b8af60_shell *>((manager4))->RaiseBlurRadius(motion_24);
}
