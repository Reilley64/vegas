
// src/gamebryo2.2/corelibs/niparticle/niparticlesdm.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/niparticlesdm.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/C217F0Modifier.h"
#include "fnv/decl/FUN_00c2b970_Class.h"
#include "fnv/decl/NiStream.h"
#include "fnv/symbols_00a63000.h"
#include "fnv/symbols_00c1b000.h"
#include "fnv/symbols_00c1c000.h"
#include "fnv/symbols_00c1f000.h"
#include "fnv/symbols_00c20000.h"
#include "fnv/symbols_00c22000.h"
#include "fnv/symbols_00c24000.h"
#include "fnv/symbols_00c25000.h"
#include "fnv/symbols_00c26000.h"
#include "fnv/symbols_00c27000.h"
#include "fnv/symbols_00c28000.h"
#include "fnv/symbols_00c29000.h"
#include "fnv/symbols_00c2a000.h"
#include "fnv/symbols_00c2b000.h"
#include "fnv/symbols_00c2c000.h"
#include "fnv/symbols_00c2d000.h"
#include "fnv/symbols_00c2e000.h"
#include "fnv/symbols_00c2f000.h"
#include "fnv/symbols_00c30000.h"
#include "fnv/symbols_01202000.h"
void __cdecl DestroyManager();

static const char s_sz00[] = "NiMeshParticleSystem";
static const char s_sz01[] = "NiMeshPSysData";
static const char s_sz02[] = "NiParticleSystem";
static const char s_sz03[] = "NiPSysAirFieldAirFrictionCtlr";
static const char s_sz04[] = "NiPSysAirFieldInheritVelocityCtlr";
static const char s_sz05[] = "NiPSysAirFieldModifier";
static const char s_sz06[] = "NiPSysAirFieldSpreadCtlr";
static const char s_sz07[] = "NiPSysAgeDeathModifier";
static const char s_sz08[] = "NiPSysBombModifier";
static const char s_sz09[] = "NiPSysBoundUpdateModifier";
static const char s_sz10[] = "NiPSysBoxEmitter";
static const char s_sz11[] = "NiPSysColliderManager";
static const char s_sz12[] = "NiPSysColorModifier";
static const char s_sz13[] = "NiPSysCylinderEmitter";
static const char s_sz14[] = "NiPSysData";
static const char s_sz15[] = "NiPSysDragFieldModifier";
static const char s_sz16[] = "NiPSysDragModifier";
static const char s_sz17[] = "NiPSysEmitterCtlr";
static const char s_sz18[] = "NiPSysEmitterCtlrData";
static const char s_sz19[] = "NiPSysEmitterDeclinationCtlr";
static const char s_sz20[] = "NiPSysEmitterDeclinationVarCtlr";
static const char s_sz21[] = "NiPSysEmitterInitialRadiusCtlr";
static const char s_sz22[] = "NiPSysEmitterLifeSpanCtlr";
static const char s_sz23[] = "NiPSysEmitterPlanarAngleCtlr";
static const char s_sz24[] = "NiPSysEmitterPlanarAngleVarCtlr";
static const char s_sz25[] = "NiPSysEmitterSpeedCtlr";
static const char s_sz26[] = "NiPSysFieldAttenuationCtlr";
static const char s_sz27[] = "NiPSysFieldMagnitudeCtlr";
static const char s_sz28[] = "NiPSysFieldMaxDistanceCtlr";
static const char s_sz29[] = "NiPSysGravityModifier";
static const char s_sz30[] = "NiPSysGravityFieldModifier";
static const char s_sz31[] = "NiPSysGravityStrengthCtlr";
static const char s_sz32[] = "NiPSysGrowFadeModifier";
static const char s_sz33[] = "NiPSysInitialRotAngleCtlr";
static const char s_sz34[] = "NiPSysInitialRotAngleVarCtlr";
static const char s_sz35[] = "NiPSysInitialRotSpeedCtlr";
static const char s_sz36[] = "NiPSysInitialRotSpeedVarCtlr";
static const char s_sz37[] = "NiPSysMeshEmitter";
static const char s_sz38[] = "NiPSysMeshUpdateModifier";
static const char s_sz39[] = "NiPSysModifierActiveCtlr";
static const char s_sz40[] = "NiPSysPlanarCollider";
static const char s_sz41[] = "NiPSysPositionModifier";
static const char s_sz42[] = "NiPSysRadialFieldModifier";
static const char s_sz43[] = "NiPSysResetOnLoopCtlr";
static const char s_sz44[] = "NiPSysRotationModifier";
static const char s_sz45[] = "NiPSysSpawnModifier";
static const char s_sz46[] = "NiPSysSphereEmitter";
static const char s_sz47[] = "NiPSysSphericalCollider";
static const char s_sz48[] = "NiPSysTurbulenceFieldModifier";
static const char s_sz49[] = "NiPSysUpdateCtlr";
static const char s_sz50[] = "NiPSysVortexFieldModifier";
static const char g_szShutdownEnd[] = "";

// @fnv 0x00c1a7d0
void __cdecl FUN_00c1a7d0()
{
    if (!::DAT_012024d0)
        return;
    ::DAT_012024d0 = false;
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
    DestroyManager();
}

#include <windows.h>
typedef void* (*S_00c1aa00_CreateFunc)();

void* FUN_00c21e90();
void* CreateAirTmp();
void* CreateColorModifier();
void* FUN_00c1fbf0();
void* FUN_00c2c080();
void* FUN_00c2a2b0();
void* FUN_00c23b20();

bool DAT_012024d0;
DWORD DAT_012024dc;

// Registers particle system class factories with FUN_00a64900 and stores the calling thread ID in DAT_012024dc.
// @fnv 0x00c1aa00
void RegisterParticleSystems()
{
    if (DAT_012024d0)
        return;
    DAT_012024d0 = true;

    ::NiStream::RegisterObjectLoader("NiMeshParticleSystem", (NiObject *(*)())(FUN_00c21e90));
    ::NiStream::RegisterObjectLoader("NiMeshPSysData", (NiObject *(*)())(((void *(&)())::CreateNiMeshPSysData)));
    ::NiStream::RegisterObjectLoader("NiParticleSystem", (NiObject *(*)())(((void *(&)())::FUN_00c1b7f0)));
    ::NiStream::RegisterObjectLoader("NiPSysAirFieldAirFrictionCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c30790::FUN_00c30790)));
    ::NiStream::RegisterObjectLoader("NiPSysAirFieldInheritVelocityCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c30600::FUN_00c30600)));
    ::NiStream::RegisterObjectLoader("NiPSysAirFieldModifier", (NiObject *(*)())(CreateAirTmp));
    ::NiStream::RegisterObjectLoader("NiPSysAirFieldSpreadCtlr", (NiObject *(*)())(((void *(&)())::FUN_00c2f3a0)));
    ::NiStream::RegisterObjectLoader("NiPSysAgeDeathModifier", (NiObject *(*)())(((void *(&)())::FUN_00c2ef20)));
    ::NiStream::RegisterObjectLoader("NiPSysBombModifier", (NiObject *(*)())(((void *(&)())::FUN_00c2e4c0)));
    ::NiStream::RegisterObjectLoader("NiPSysBoundUpdateModifier", (NiObject *(*)())(((void *(&)())::CreateNiPSysModC2D)));
    ::NiStream::RegisterObjectLoader("NiPSysBoxEmitter", (NiObject *(*)())(((void *(&)())::FUN_00c20350)));
    ::NiStream::RegisterObjectLoader("NiPSysColliderManager", (NiObject *(*)())(((void *(&)())::FUN_00c2d5b0)));
    ::NiStream::RegisterObjectLoader("NiPSysColorModifier", (NiObject *(*)())(CreateColorModifier));
    ::NiStream::RegisterObjectLoader("NiPSysCylinderEmitter", (NiObject *(*)())(FUN_00c1fbf0));
    ::NiStream::RegisterObjectLoader("NiPSysData", (NiObject *(*)())(((void *(&)())::FUN_00c24da0)));
    ::NiStream::RegisterObjectLoader("NiPSysDragFieldModifier", (NiObject *(*)())(((void *(&)())::FUN_00c2c7b0)));
    ::NiStream::RegisterObjectLoader("NiPSysDragModifier", (NiObject *(*)())(FUN_00c2c080));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterCtlr", (NiObject *(*)())(((void *(&)())::CreateNiPSysEmitterCtlrC1C5)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterCtlrData", (NiObject *(*)())(((void *(&)())::FUN_00c2ba60)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterDeclinationCtlr", (NiObject *(*)())(((void *(&)())::FUN_00c2b970_Class::FUN_00c2b970)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterDeclinationVarCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c2b870::FUN_00c2b870)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterInitialRadiusCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c2b720::FUN_00c2b720)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterLifeSpanCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c2b620::FUN_00c2b620)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterPlanarAngleCtlr", (NiObject *(*)())(((void *(&)())::CreatePSysFactoryObjectB52)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterPlanarAngleVarCtlr", (NiObject *(*)())(((void *(&)())::CreatePSysFactoryObject)));
    ::NiStream::RegisterObjectLoader("NiPSysEmitterSpeedCtlr", (NiObject *(*)())(((void *(&)())::CreateParticleEmitterAllocation)));
    ::NiStream::RegisterObjectLoader("NiPSysFieldAttenuationCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c2b200::FUN_00c2b200)));
    ::NiStream::RegisterObjectLoader("NiPSysFieldMagnitudeCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c2b110::FUN_00c2b110)));
    ::NiStream::RegisterObjectLoader("NiPSysFieldMaxDistanceCtlr", (NiObject *(*)())(((void *(&)())::FUN_00c2b010)));
    ::NiStream::RegisterObjectLoader("NiPSysGravityModifier", (NiObject *(*)())(((void *(&)())::FUN_00c22ad0)));
    ::NiStream::RegisterObjectLoader("NiPSysGravityFieldModifier", (NiObject *(*)())(((void *(&)())::CreateGravityFieldModifier)));
    ::NiStream::RegisterObjectLoader("NiPSysGravityStrengthCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c2a870::FUN_00c2a870)));
    ::NiStream::RegisterObjectLoader("NiPSysGrowFadeModifier", (NiObject *(*)())(FUN_00c2a2b0));
    ::NiStream::RegisterObjectLoader("NiPSysInitialRotAngleCtlr", (NiObject *(*)())(((void *(&)())::CreateParticleObjectFactory)));
    ::NiStream::RegisterObjectLoader("NiPSysInitialRotAngleVarCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c2a050::FUN_00c2a050)));
    ::NiStream::RegisterObjectLoader("NiPSysInitialRotSpeedCtlr", (NiObject *(*)())(((void *(&)())::CreateParticleFactoryObject)));
    ::NiStream::RegisterObjectLoader("NiPSysInitialRotSpeedVarCtlr", (NiObject *(*)())(((void *(&)())::CreateC29E50Object)));
    ::NiStream::RegisterObjectLoader("NiPSysMeshEmitter", (NiObject *(*)())(((void *(&)())::CreateNiPSysMeshEmitterObject)));
    ::NiStream::RegisterObjectLoader("NiPSysMeshUpdateModifier", (NiObject *(*)())(((void *(&)())::C217F0Modifier::CreateModifier)));
    ::NiStream::RegisterObjectLoader("NiPSysModifierActiveCtlr", (NiObject *(*)())(((void *(&)())::fnv_00c29d00::FUN_00c29d00)));
    ::NiStream::RegisterObjectLoader("NiPSysPlanarCollider", (NiObject *(*)())(((void *(&)())::fnv_00c29af0::FUN_00c29af0)));
    ::NiStream::RegisterObjectLoader("NiPSysPositionModifier", (NiObject *(*)())(((void *(&)())::fnv_00c28b20::FUN_00c28b20)));
    ::NiStream::RegisterObjectLoader("NiPSysRadialFieldModifier", (NiObject *(*)())(((void *(&)())::FUN_00c28570)));
    ::NiStream::RegisterObjectLoader("NiPSysResetOnLoopCtlr", (NiObject *(*)())(((void *(&)())::FUN_00c283b0)));
    ::NiStream::RegisterObjectLoader("NiPSysRotationModifier", (NiObject *(*)())(((void *(&)())::FUN_00c20640)));
    ::NiStream::RegisterObjectLoader("NiPSysSpawnModifier", (NiObject *(*)())(FUN_00c23b20));
    ::NiStream::RegisterObjectLoader("NiPSysSphereEmitter", (NiObject *(*)())(((void *(&)())::FUN_00c1fff0)));
    ::NiStream::RegisterObjectLoader("NiPSysSphericalCollider", (NiObject *(*)())(((void *(&)())::CreateCollider)));
    ::NiStream::RegisterObjectLoader("NiPSysTurbulenceFieldModifier", (NiObject *(*)())(((void *(&)())::FUN_00c27350)));
    ::NiStream::RegisterObjectLoader("NiPSysUpdateCtlr", (NiObject *(*)())(((void *(&)())::FUN_00c270f0)));
    ::NiStream::RegisterObjectLoader("NiPSysVortexFieldModifier", (NiObject *(*)())(((void *(&)())::FUN_00c26790)));
    ::NiStream::RegisterObjectLoader("BSStripParticleSystem", (NiObject *(*)())(((void *(&)())::FUN_00c25820)));
    ::NiStream::RegisterObjectLoader("BSStripPSysData", (NiObject *(*)())(((void *(&)())::CreateFUN_00c24c90)));

    DAT_012024dc = GetCurrentThreadId();
}
