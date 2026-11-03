
// src/gamebryo2.2/corelibs/nianimation/nianimationsdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nianimationsdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/ActorManagerPacket.h"
#include "fnv/decl/NiStream.h"
#include "fnv/symbols_00a2f000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a32000.h"
#include "fnv/symbols_00a35000.h"
#include "fnv/symbols_00a36000.h"
#include "fnv/symbols_00a39000.h"
#include "fnv/symbols_00a3b000.h"
#include "fnv/symbols_00a3c000.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00a3f000.h"
#include "fnv/symbols_00a40000.h"
#include "fnv/symbols_00a41000.h"
#include "fnv/symbols_00a42000.h"
#include "fnv/symbols_00a43000.h"
#include "fnv/symbols_00a44000.h"
#include "fnv/symbols_00a45000.h"
#include "fnv/symbols_00a46000.h"
#include "fnv/symbols_00a47000.h"
#include "fnv/symbols_00a48000.h"
#include "fnv/symbols_00a49000.h"
#include "fnv/symbols_00a4b000.h"
#include "fnv/symbols_00a4c000.h"
#include "fnv/symbols_00a4d000.h"
#include "fnv/symbols_00a4e000.h"
#include "fnv/symbols_00a4f000.h"
#include "fnv/symbols_00a50000.h"
#include "fnv/symbols_00a51000.h"
#include "fnv/symbols_00a52000.h"
#include "fnv/symbols_00a53000.h"
#include "fnv/symbols_00a55000.h"
#include "fnv/symbols_00a56000.h"
#include "fnv/symbols_00a63000.h"
#include "fnv/symbols_01095000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011f3000.h"
void __cdecl ClearNodeList();
void __cdecl ClearGlobalStrings();
void __cdecl ResetRegistry();

static const char s_sz00[] = "NiAlphaController";
static const char s_sz01[] = "NiBlendAccumTransformInterpolator";
static const char s_sz02[] = "NiBlendBoolInterpolator";
static const char s_sz03[] = "NiBlendColorInterpolator";
static const char s_sz04[] = "NiBlendFloatInterpolator";
static const char s_sz05[] = "NiBlendPoint3Interpolator";
static const char s_sz06[] = "NiBlendQuaternionInterpolator";
static const char s_sz07[] = "NiBlendTransformInterpolator";
static const char s_sz08[] = "NiBoneLODController";
static const char s_sz09[] = "NiBoolData";
static const char s_sz10[] = "NiBoolInterpolator";
static const char s_sz11[] = "NiBoolTimelineInterpolator";
static const char s_sz12[] = "NiBSplineBasisData";
static const char s_sz13[] = "NiBSplineData";
static const char s_sz14[] = "NiBSplineColorInterpolator";
static const char s_sz15[] = "NiBSplineCompColorInterpolator";
static const char s_sz16[] = "NiBSplineCompFloatInterpolator";
static const char s_sz17[] = "NiBSplineCompPoint3Interpolator";
static const char s_sz18[] = "NiBSplineCompTransformInterpolator";
static const char s_sz19[] = "NiBSplineFloatInterpolator";
static const char s_sz20[] = "NiBSplinePoint3Interpolator";
static const char s_sz21[] = "NiBSplineTransformInterpolator";
static const char s_sz22[] = "NiColorData";
static const char s_sz23[] = "NiColorExtraDataController";
static const char s_sz24[] = "NiColorInterpolator";
static const char s_sz25[] = "NiControllerManager";
static const char s_sz26[] = "NiControllerSequence";
static const char s_sz27[] = "NiFlipController";
static const char s_sz28[] = "NiFloatData";
static const char s_sz29[] = "NiFloatExtraDataController";
static const char s_sz30[] = "NiFloatInterpolator";
static const char s_sz31[] = "NiFloatsExtraDataController";
static const char s_sz32[] = "NiFloatsExtraDataPoint3Controller";
static const char s_sz33[] = "NiGeomMorpherController";
static const char s_sz34[] = "NiKeyframeController";
static const char s_sz35[] = "NiKeyframeData";
static const char s_sz36[] = "NiKeyframeManager";
static const char s_sz37[] = "NiLightColorController";
static const char s_sz38[] = "NiLightDimmerController";
static const char s_sz39[] = "NiLookAtController";
static const char s_sz40[] = "NiLookAtInterpolator";
static const char s_sz41[] = "NiMaterialColorController";
static const char s_sz42[] = "NiMorphData";
static const char s_sz43[] = "NiMultiTargetTransformController";
static const char s_sz44[] = "NiPathController";
static const char s_sz45[] = "NiPathInterpolator";
static const char s_sz46[] = "NiPoint3Interpolator";
static const char s_sz47[] = "NiPosData";
static const char s_sz48[] = "NiQuaternionInterpolator";
static const char s_sz49[] = "NiRollController";
static const char s_sz50[] = "NiRotData";
static const char s_sz51[] = "NiSequence";
static const char s_sz52[] = "NiSequenceStreamHelper";
static const char s_sz53[] = "NiStringPalette";
static const char s_sz54[] = "NiTextKeyExtraData";
static const char s_sz55[] = "NiTextureTransformController";
static const char s_sz56[] = "NiTransformController";
static const char s_sz57[] = "NiTransformData";
static const char s_sz58[] = "NiTransformInterpolator";
static const char s_sz59[] = "NiUVController";
static const char s_sz60[] = "NiUVData";
static const char s_sz61[] = "NiVisController";
static const char s_sz62[] = "BSAnimNotes";
static const char s_sz63[] = "BSGrabIKNote";
static const char s_sz64[] = "BSLookIKNote";
static const char s_sz65[] = "BSRotAccumTransfInterpolator";
static const char s_sz66[] = "BSTreadTransfInterpolator";
static const char s_sz67[] = "BSBlendTreadTransfInterpolator";
static const char s_sz68[] = "BSMultiTargetTreadTransfController";
static const char s_sz69[] = "BSFrustumFOVController";
static const char s_sz70[] = "NiVisData";
extern const char g_szShutdownEnd[] = "";

// @fnv 0x00a2de70
void __cdecl ShutdownAnimationClasses()
{
    if (!::DAT_011f369d)
        return;
    ::DAT_011f369d = false;
    ::fnv_00a63520::FUN_00a63520(s_sz00);
    ::fnv_00a63520::FUN_00a63520(s_sz01);
    ::fnv_00a63520::FUN_00a63520(s_sz02);
    ::fnv_00a63520::FUN_00a63520(s_sz03);
    ::fnv_00a63520::FUN_00a63520(s_sz04);
    ::fnv_00a63520::FUN_00a63520(s_sz05);
    ::fnv_00a63520::FUN_00a63520(s_sz06);
    ::fnv_00a63520::FUN_00a63520(s_sz07);
    ::fnv_00a63520::FUN_00a63520(s_sz08);
    ::fnv_00a63520::FUN_00a63520(s_sz09);
    ::fnv_00a63520::FUN_00a63520(s_sz10);
    ::fnv_00a63520::FUN_00a63520(s_sz11);
    ::fnv_00a63520::FUN_00a63520(s_sz12);
    ::fnv_00a63520::FUN_00a63520(s_sz13);
    ::fnv_00a63520::FUN_00a63520(s_sz14);
    ::fnv_00a63520::FUN_00a63520(s_sz15);
    ::fnv_00a63520::FUN_00a63520(s_sz16);
    ::fnv_00a63520::FUN_00a63520(s_sz17);
    ::fnv_00a63520::FUN_00a63520(s_sz18);
    ::fnv_00a63520::FUN_00a63520(s_sz19);
    ::fnv_00a63520::FUN_00a63520(s_sz20);
    ::fnv_00a63520::FUN_00a63520(s_sz21);
    ::fnv_00a63520::FUN_00a63520(s_sz22);
    ::fnv_00a63520::FUN_00a63520(s_sz23);
    ::fnv_00a63520::FUN_00a63520(s_sz24);
    ::fnv_00a63520::FUN_00a63520(s_sz25);
    ::fnv_00a63520::FUN_00a63520(s_sz26);
    ::fnv_00a63520::FUN_00a63520(s_sz27);
    ::fnv_00a63520::FUN_00a63520(s_sz28);
    ::fnv_00a63520::FUN_00a63520(s_sz29);
    ::fnv_00a63520::FUN_00a63520(s_sz30);
    ::fnv_00a63520::FUN_00a63520(s_sz31);
    ::fnv_00a63520::FUN_00a63520(s_sz32);
    ::fnv_00a63520::FUN_00a63520(s_sz33);
    ::fnv_00a63520::FUN_00a63520(s_sz34);
    ::fnv_00a63520::FUN_00a63520(s_sz35);
    ::fnv_00a63520::FUN_00a63520(s_sz36);
    ::fnv_00a63520::FUN_00a63520(s_sz37);
    ::fnv_00a63520::FUN_00a63520(s_sz38);
    ::fnv_00a63520::FUN_00a63520(s_sz39);
    ::fnv_00a63520::FUN_00a63520(s_sz40);
    ::fnv_00a63520::FUN_00a63520(s_sz41);
    ::fnv_00a63520::FUN_00a63520(s_sz42);
    ::fnv_00a63520::FUN_00a63520(s_sz43);
    ::fnv_00a63520::FUN_00a63520(s_sz44);
    ::fnv_00a63520::FUN_00a63520(s_sz45);
    ::fnv_00a63520::FUN_00a63520(s_sz46);
    ::fnv_00a63520::FUN_00a63520(s_sz47);
    ::fnv_00a63520::FUN_00a63520(s_sz48);
    ::fnv_00a63520::FUN_00a63520(s_sz49);
    ::fnv_00a63520::FUN_00a63520(s_sz50);
    ::fnv_00a63520::FUN_00a63520(s_sz51);
    ::fnv_00a63520::FUN_00a63520(s_sz52);
    ::fnv_00a63520::FUN_00a63520(s_sz53);
    ::fnv_00a63520::FUN_00a63520(s_sz54);
    ::fnv_00a63520::FUN_00a63520(s_sz55);
    ::fnv_00a63520::FUN_00a63520(s_sz56);
    ::fnv_00a63520::FUN_00a63520(s_sz57);
    ::fnv_00a63520::FUN_00a63520(s_sz58);
    ::fnv_00a63520::FUN_00a63520(s_sz59);
    ::fnv_00a63520::FUN_00a63520(s_sz60);
    ::fnv_00a63520::FUN_00a63520(s_sz61);
    ::fnv_00a63520::FUN_00a63520(s_sz62);
    ::fnv_00a63520::FUN_00a63520(s_sz63);
    ::fnv_00a63520::FUN_00a63520(s_sz64);
    ::fnv_00a63520::FUN_00a63520(s_sz65);
    ::fnv_00a63520::FUN_00a63520(s_sz66);
    ::fnv_00a63520::FUN_00a63520(s_sz67);
    ::fnv_00a63520::FUN_00a63520(s_sz68);
    ::fnv_00a63520::FUN_00a63520(s_sz69);
    ::fnv_00a63520::FUN_00a63520(s_sz70);
    ::fnv_00a63540::RemovePostProcess((void (*)(void *))(((void (&)())::FUN_00a42c80)));
    ClearNodeList();
    ClearGlobalStrings();
    ResetRegistry();
}

  // NiAlphaController
  // NiBlendAccumTransformInterpolator
  // NiBlendBoolInterpolator
  // NiBlendColorInterpolator
  // NiBlendFloatInterpolator
  // NiBlendPoint3Interpolator
  // NiBlendQuaternionInterpolator
  // NiBlendTransformInterpolator
  // NiBoneLODController
  // NiBoolData
  // NiBoolInterpolator
  // NiBoolTimelineInterpolator
  // NiBSplineBasisData
  // NiBSplineData
  // NiBSplineColorInterpolator
  // NiBSplineCompColorInterpolator
  // NiBSplineCompFloatInterpolator
  // NiBSplineCompPoint3Interpolator
  // NiBSplineCompTransformInterpolator
  // NiBSplineFloatInterpolator
  // NiBSplinePoint3Interpolator
  // NiBSplineTransformInterpolator
  // NiColorData
  // NiColorExtraDataController
  // NiColorInterpolator
  // NiControllerManager
  // NiControllerSequence
  // NiFlipController
  // NiFloatData
  // NiFloatExtraDataController
  // NiFloatInterpolator
  // NiFloatsExtraDataController
  // NiFloatsExtraDataPoint3Controller
  // NiGeomMorpherController
extern const char DAT_01095cfc[];  // NiKeyframeController
extern const char DAT_01095cec[];  // NiKeyframeData
  // NiKeyframeManager
  // NiLightColorController
  // NiLightDimmerController
  // NiLookAtController
  // NiLookAtInterpolator
  // NiMaterialColorController
  // NiMorphData
  // NiMultiTargetTransformController
  // NiPathController
  // NiPathInterpolator
  // NiPoint3Interpolator
  // NiPosData
  // NiQuaternionInterpolator
  // NiRollController
  // NiRotData
  // NiSequence
  // NiSequenceStreamHelper
  // NiStringPalette
  // NiTextKeyExtraData
  // NiTextureTransformController
  // NiTransformController
  // NiTransformData
  // NiTransformInterpolator
  // NiUVController
  // NiUVData
  // NiVisController
  // BSAnimNotes
  // BSGrabIKNote
  // BSLookIKNote
  // BSRotAccumTransfInterpolator
  // BSTreadTransfInterpolator
  // BSBlendTreadTransfInterpolator
  // BSMultiTargetTreadTransfController
  // BSFrustumFOVController
extern const char DAT_01095a04[];  // NiVisData
// @fnv 0x00a2d8a0
void FUN_00a2d8a0()
{
    if (!DAT_011f369d)
    {
        DAT_011f369d = true;
        ::NiStream::RegisterObjectLoader(::g_011f4084_arg0, (NiObject *(*)())(((void (&)())::CreateFloatInterpController)));
        ::NiStream::RegisterObjectLoader(::g_011f371c_arg0, (NiObject *(*)())(((void (&)())::fnv_00a39700::FUN_00a39700)));
        ::NiStream::RegisterObjectLoader(::g_011f407c_arg0, (NiObject *(*)())(((void (&)())::FUN_00a565c0)));
        ::NiStream::RegisterObjectLoader(::g_011f4074_arg0, (NiObject *(*)())(((void (&)())::CreateBlendColorInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f3e58_arg0, (NiObject *(*)())(((void (&)())::CreateNiBlendFloatInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f406c_arg0, (NiObject *(*)())(((void (&)())::FUN_00a55a80)));
        ::NiStream::RegisterObjectLoader(::g_011f4064_arg0, (NiObject *(*)())(((void (&)())::FUN_00a55470)));
        ::NiStream::RegisterObjectLoader(::g_011f3e64_arg0, (NiObject *(*)())(((void (&)())::FUN_00a409d0)));
        ::NiStream::RegisterObjectLoader(::g_011f405c_arg0, (NiObject *(*)())(((void (&)())::CreateBoneLODController)));
        ::NiStream::RegisterObjectLoader(::g_011f4054_arg0, (NiObject *(*)())(((void (&)())::fnv_00a537f0::FUN_00a537f0)));
        ::NiStream::RegisterObjectLoader(::g_011f404c_arg0, (NiObject *(*)())(((void (&)())::CreateNiKeyBasedInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f4044_arg0, (NiObject *(*)())(((void (&)())::CreateBoolInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f403c_arg0, (NiObject *(*)())(((void (&)())::CreateNiSplineImpl)));
        ::NiStream::RegisterObjectLoader(::g_011f4034_arg0, (NiObject *(*)())(((void (&)())::FUN_00a51e10)));
        ::NiStream::RegisterObjectLoader(::g_011f402c_arg0, (NiObject *(*)())(((void (&)())::FUN_00a51c60)));
        ::NiStream::RegisterObjectLoader(::g_011f4024_arg0, (NiObject *(*)())(((void (&)())::CreateSplineCompColorInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f401c_arg0, (NiObject *(*)())(((void (&)())::FUN_00a51620)));
        ::NiStream::RegisterObjectLoader(::g_011f4014_arg0, (NiObject *(*)())(((void (&)())::CreateComp4)));
        ::NiStream::RegisterObjectLoader(::g_011f4004_arg0, (NiObject *(*)())(((void (&)())::CreateEvaluator)));
        ::NiStream::RegisterObjectLoader(::g_011f3ffc_arg0, (NiObject *(*)())(((void (&)())::FUN_00a50ad0)));
        ::NiStream::RegisterObjectLoader(::g_011f3ff4_arg0, (NiObject *(*)())(((void (&)())::FUN_00a50840)));
        ::NiStream::RegisterObjectLoader(::g_011f3fe4_arg0, (NiObject *(*)())(((void (&)())::fnv_00a50180::FUN_00a50180)));
        ::NiStream::RegisterObjectLoader(::g_011f3750_arg0, (NiObject *(*)())(((void (&)())::fnv_00a3d150::CreateNiColorData)));
        ::NiStream::RegisterObjectLoader(::g_011f3fdc_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4fac0)));
        ::NiStream::RegisterObjectLoader(::g_011f3730_arg0, (NiObject *(*)())(((void (&)())::FUN_00a3c130)));
        ::NiStream::RegisterObjectLoader(::g_011f36ac_arg0, (NiObject *(*)())(((void (&)())::FUN_00a2f6c0)));
        ::NiStream::RegisterObjectLoader(::g_011f36dc_arg0, (NiObject *(*)())(((void (&)())::FUN_00a326c0)));
        ::NiStream::RegisterObjectLoader(::g_011f3fd4_arg0, (NiObject *(*)())(((void (&)())::CreateNiFlipController)));
        ::NiStream::RegisterObjectLoader(::g_011f3748_arg0, (NiObject *(*)())(((void (&)())::fnv_00a3cd00::CreateNiFloatData)));
        ::NiStream::RegisterObjectLoader(::g_011f3e6c_arg0, (NiObject *(*)())(((void (&)())::fnv_00a411f0::FUN_00a411f0)));
        ::NiStream::RegisterObjectLoader(::g_011f3738_arg0, (NiObject *(*)())(((void (&)())::CreateNiFloatInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f3fcc_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4f000)));
        ::NiStream::RegisterObjectLoader(::g_011f3fc4_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4ecd0)));
        ::NiStream::RegisterObjectLoader(::g_011f3728_arg0, (NiObject *(*)())(((void (&)())::FUN_00a3b550)));
        ::NiStream::RegisterObjectLoader(DAT_01095cfc, (NiObject *(*)())(((void (&)())::FUN_00a36810)));
        ::NiStream::RegisterObjectLoader(DAT_01095cec, (NiObject *(*)())(((void (&)())::fnv_00a4e040::FUN_00a4e040)));
        ::NiStream::RegisterObjectLoader(::g_011f3fb4_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4db60)));
        ::NiStream::RegisterObjectLoader(::g_011f3fa8_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4d500)));
        ::NiStream::RegisterObjectLoader(::g_011f3fa0_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4d0d0)));
        ::NiStream::RegisterObjectLoader(::g_011f3f98_arg0, (NiObject *(*)())(((void (&)())::CreateMorphData)));
        ::NiStream::RegisterObjectLoader(::g_011f3f90_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4c5a0)));
        ::NiStream::RegisterObjectLoader(::g_011f3f88_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4b790)));
        ::NiStream::RegisterObjectLoader(::g_011f3e74_arg0, (NiObject *(*)())(((void (&)())::CreateA51BF0)));
        ::NiStream::RegisterObjectLoader(::g_011f36bc_arg0, (NiObject *(*)())(((void (&)())::fnv_00a30330::CreateCtl)));
        ::NiStream::RegisterObjectLoader(::g_011f3f80_arg0, (NiObject *(*)())(((void (&)())::FUN_00a4b270)));
        ::NiStream::RegisterObjectLoader(::g_011f3e48_arg0, (NiObject *(*)())(((void (&)())::CreateA51BF0Base)));
        ::NiStream::RegisterObjectLoader(::g_011f3f70_arg0, (NiObject *(*)())(((void (&)())::FUN_00a49a30)));
        ::NiStream::RegisterObjectLoader(::g_011f3f68_arg0, (NiObject *(*)())(((void (&)())::FUN_00a49020)));
        ::NiStream::RegisterObjectLoader(::g_011f3f60_arg0, (NiObject *(*)())(((void (&)())::CreateNiQuaternionInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f3f58_arg0, (NiObject *(*)())(((void (&)())::FUN_00a48750)));
        ::NiStream::RegisterObjectLoader(::g_011f3f50_arg0, (NiObject *(*)())(((void (&)())::FUN_00a48110)));
        ::NiStream::RegisterObjectLoader(::g_011f3f48_arg0, (NiObject *(*)())(((void (&)())::fnv_00a47f20::FUN_00a47f20)));
        ::NiStream::RegisterObjectLoader(::g_011f3f38_arg0, (NiObject *(*)())(((void (&)())::FUN_00a47380)));
        ::NiStream::RegisterObjectLoader(::g_011f3f30_arg0, (NiObject *(*)())(((void (&)())::FUN_00a47150)));
        ::NiStream::RegisterObjectLoader(::g_011f3f28_arg0, (NiObject *(*)())(((void (&)())::FUN_00a46b70)));
        ::NiStream::RegisterObjectLoader(::g_011f3f20_arg0, (NiObject *(*)())(((void (&)())::FUN_00a46950)));
        ::NiStream::RegisterObjectLoader(::g_011f36ec_arg0, (NiObject *(*)())(((void (&)())::FUN_00a36810)));
        ::NiStream::RegisterObjectLoader(::g_011f3fbc_arg0, (NiObject *(*)())(((void (&)())::fnv_00a4e040::FUN_00a4e040)));
        ::NiStream::RegisterObjectLoader(::g_011f3e50_arg0, (NiObject *(*)())(((void (&)())::fnv_00a403f0::FUN_00a403f0)));
        ::NiStream::RegisterObjectLoader(::g_011f3f18_arg0, (NiObject *(*)())(((void (&)())::FUN_00a45f50)));
        ::NiStream::RegisterObjectLoader(::g_011f3f10_arg0, (NiObject *(*)())(((void (&)())::fnv_00a44ff0::CreateControllerAllocation)));
        ::NiStream::RegisterObjectLoader(::g_011f3f08_arg0, (NiObject *(*)())(((void (&)())::FUN_00a44f10)));
        ::NiStream::RegisterObjectLoader(::g_011f3f00_arg0, (NiObject *(*)())(((void (&)())::FUN_00a44940)));
        ::NiStream::RegisterObjectLoader(::g_011f3ef0_arg0, (NiObject *(*)())(((void (&)())::FUN_00a44380)));
        ::NiStream::RegisterObjectLoader(::g_011f3ee8_arg0, (NiObject *(*)())(((void (&)())::fnv_00a43fb0::CreateLookIKNote)));
        ::NiStream::RegisterObjectLoader(::g_011f3ee0_arg0, (NiObject *(*)())(((void (&)())::CreateRotAccumTransfInterpolator)));
        ::NiStream::RegisterObjectLoader(::g_011f3ed8_arg0, (NiObject *(*)())(((void (&)())::CreateDerivedA43370)));
        ::NiStream::RegisterObjectLoader(::g_011f3ed0_arg0, (NiObject *(*)())(((void (&)())::FUN_00a42f90)));
        ::NiStream::RegisterObjectLoader(::g_011f36e4_arg0, (NiObject *(*)())(((void (&)())::sa359d0::FUN_00a359d0)));
        ::NiStream::RegisterObjectLoader(::g_011f3ec8_arg0, (NiObject *(*)())(((void (&)())::FUN_00a42ee0)));
        ::NiStream::RegisterObjectLoader(DAT_01095a04, (NiObject *(*)())(((void (&)())::fnv_00a537f0::FUN_00a537f0)));
        ::NiStream::RegisterPostProcess((void (*)(NiStream &, NiObject *))(((void (&)())::FUN_00a42c80)));
        ::ActorManagerPacket::InitializePoint3();
    }
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nianimationsdm.inc"
