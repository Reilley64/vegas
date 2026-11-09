#include "AutoMemContext.h"
// fallout/misc/main.cpp: Interface, SomeClass, BSFadeNodeCuller, Mover and more (192 functions)
#include "fnv/av_object_fields.h"
#include "fnv/game_timer.h"
#include "fnv/vats_camera_data_view.h"
#include "fnv/dx9_renderer_view.h"
#include "fnv/simple_list_node_view.h"
#include <cstdint>
#include <windows.h>
#include <shellapi.h>
#include <new>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A6A0Sun.h"
#include "fnv/decl/AIThreadManager.h"
#include "fnv/decl/ActorReferenceArray.h"
#include "fnv/decl/ActorSpellView.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/AddonOwner.h"
#include "fnv/decl/AudioManager.h"
#include "fnv/decl/AutoMemContext.h"
#include "fnv/decl/B87F200Projectile.h"
#include "fnv/decl/B9BB10Effect.h"
#include "fnv/decl/BB97550Shader.h"
#include "fnv/decl/BEC16D0MoviePlayerThread.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDehydrationStage.h"
#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/BGSSaveLoadManager.h"
#include "fnv/decl/BSA_.h"
#include "fnv/decl/BSFileCache.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/BSRenderStateManager.h"
#include "fnv/decl/BSShaderInitializer.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSSysInfoSystemUtility.h"
#include "fnv/decl/BSTempEffectSimpleDecal.h"
#include "fnv/decl/BSTreeManager.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/BatchTES.h"
#include "fnv/decl/BipedNodeNames.h"
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/C52020Obj.h"
#include "fnv/decl/C5E0200File.h"
#include "fnv/decl/C7D1360Actor.h"
#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/ChallengeManager.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/ControlGraph.h"
#include "fnv/decl/DerivedImageSpaceManager.h"
#include "fnv/decl/EffectProcessLists.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/EffectSettingCollection.h"
#include "fnv/decl/FM7.h"
#include "fnv/decl/FOPipboyManager.h"
#include "fnv/decl/FOVATSEffectManager_008019d0.h"
#include "fnv/decl/FOVATSEffectManager_00801a60.h"
#include "fnv/decl/FUN_00404f00_shell.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00424940_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_00450770.h"
#include "fnv/decl/FUN_00450c50_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004539a0_cls.h"
#include "fnv/decl/FUN_00454b30_class.h"
#include "fnv/decl/FUN_00455640_shell.h"
#include "fnv/decl/FUN_00456520_Class.h"
#include "fnv/decl/FUN_00456630_Class.h"
#include "fnv/decl/FUN_0045c4c0_cls.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00461bc0_cls.h"
#include "fnv/decl/FUN_00461c20_Holder.h"
#include "fnv/decl/FUN_00465040_shell.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004ba7d0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_004dc020_Class.h"
#include "fnv/decl/FUN_004dc540_shell.h"
#include "fnv/decl/FUN_004e2120_s.h"
#include "fnv/decl/FUN_004e2190_shell.h"
#include "fnv/decl/FUN_004e6560_class.h"
#include "fnv/decl/FUN_004e6580_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004ebbc0_shell.h"
#include "fnv/decl/FUN_004f00e0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00525430_Class.h"
#include "fnv/decl/FUN_00546780_shell.h"
#include "fnv/decl/FUN_00547590_shell.h"
#include "fnv/decl/FUN_005477f0_Class.h"
#include "fnv/decl/FUN_00548210_Class.h"
#include "fnv/decl/FUN_00559a70_Class.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005621d0_shell.h"
#include "fnv/decl/FUN_00565730_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005b8fc0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005bf820_Class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005dc960_shell.h"
#include "fnv/decl/FUN_005e01b0_shell.h"
#include "fnv/decl/FUN_005f9ad0_shell.h"
#include "fnv/decl/FUN_005f9af0_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_00642860_Class.h"
#include "fnv/decl/FUN_00642890_Class.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00678ce0_shell.h"
#include "fnv/decl/FUN_00688430_shell.h"
#include "fnv/decl/FUN_006a61b0_cls.h"
#include "fnv/decl/FUN_006c07d0_shell.h"
#include "fnv/decl/FUN_006ff860_Class.h"
#include "fnv/decl/FUN_006ff880_Class.h"
#include "fnv/decl/FUN_007013e0_shell.h"
#include "fnv/decl/FUN_00711e00_StandIn.h"
#include "fnv/decl/FUN_007123f0_shell.h"
#include "fnv/decl/FUN_00718ab0_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007d6bd0_Class.h"
#include "fnv/decl/FUN_007fa990_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0086a830_S.h"
#include "fnv/decl/FUN_0086c160.h"
#include "fnv/decl/FUN_00876a00_Class.h"
#include "fnv/decl/FUN_00876a20_shell.h"
#include "fnv/decl/FUN_00877e10_Class.h"
#include "fnv/decl/FUN_00878080_Class.h"
#include "fnv/decl/FUN_008783c0.h"
#include "fnv/decl/FUN_008784d0.h"
#include "fnv/decl/FUN_0087a6b0_shell.h"
#include "fnv/decl/FUN_0087a6d0_shell.h"
#include "fnv/decl/FUN_0087a710_shell.h"
#include "fnv/decl/FUN_0087a790_class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bbc10_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008c51c0_shell.h"
#include "fnv/decl/FUN_008c73a0_shell.h"
#include "fnv/decl/FUN_008c78c0_Class.h"
#include "fnv/decl/FUN_008c7990_Class.h"
#include "fnv/decl/FUN_008ca300_shell.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_008d6f50_Class.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_0093bea0_cls.h"
#include "fnv/decl/FUN_009481d0_Owner.h"
#include "fnv/decl/FUN_00950090_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00967ae0_cls.h"
#include "fnv/decl/FUN_0096c970_shell.h"
#include "fnv/decl/FUN_0096cfa0_cls.h"
#include "fnv/decl/FUN_00991500_shell.h"
#include "fnv/decl/FUN_00991dc0_shell.h"
#include "fnv/decl/FUN_009b4440_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a23e10_Class.h"
#include "fnv/decl/FUN_00a24180_shell.h"
#include "fnv/decl/FUN_00a257c0_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a693e0_cls.h"
#include "fnv/decl/FUN_00a6fdb0_t.h"
#include "fnv/decl/FUN_00a87900_class.h"
#include "fnv/decl/FUN_00aa47c0_Class.h"
#include "fnv/decl/FUN_00ad8740_shell.h"
#include "fnv/decl/FUN_00afdc60.h"
#include "fnv/decl/FUN_00b00df0_cls.h"
#include "fnv/decl/FUN_00b012f0_shell.h"
#include "fnv/decl/FUN_00b5aac0_shell.h"
#include "fnv/decl/FUN_00b5ac90_t.h"
#include "fnv/decl/FUN_00b5b010_cls.h"
#include "fnv/decl/FUN_00b630c0_class.h"
#include "fnv/decl/FUN_00b631d0_cls.h"
#include "fnv/decl/FUN_00b63a90_cls.h"
#include "fnv/decl/FUN_00b65660_StandIn.h"
#include "fnv/decl/FUN_00b6dd00_Owner.h"
#include "fnv/decl/FUN_00b8d020_class.h"
#include "fnv/decl/FUN_00b9fba0_s.h"
#include "fnv/decl/FUN_00ba02b0_Class.h"
#include "fnv/decl/FUN_00ba2fa0_C.h"
#include "fnv/decl/FUN_00ba3770_struct.h"
#include "fnv/decl/FUN_00bb8140_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/FUN_00c5b5a0_cls.h"
#include "fnv/decl/FUN_00c5b5d0_class.h"
#include "fnv/decl/FUN_00ec17c0_Class.h"
#include "fnv/decl/FUN_00ec29b0_class.h"
#include "fnv/decl/FaderManager.h"
#include "fnv/decl/FileFinderImpl.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/GameTimerRecord.h"
#include "fnv/decl/GarbageCollector.h"
#include "fnv/decl/GraphicsRenderer.h"
#include "fnv/decl/Grid.h"
#include "fnv/decl/H_00ba3840.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/ImageSpaceModifierInstanceForm.h"
#include "fnv/decl/InputPlayer.h"
#include "fnv/decl/InputPoller.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/Lists970d50.h"
#include "fnv/decl/LoadingMenu.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/MenuStub.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiParallelUpdateTaskManager.h"
#include "fnv/decl/NiScreenElementsDataShell.h"
#include "fnv/decl/NiTPointerListBase.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/Owner4a4.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/PLStub.h"
#include "fnv/decl/PathManager.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/PerfMgr.h"
#include "fnv/decl/PerformanceTimerManager.h"
#include "fnv/decl/PluginListReader.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/ProcessOwner_j61.h"
#include "fnv/decl/PtrArrayView.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/ReloadManager.h"
#include "fnv/decl/S0042fa20.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S148c0.h"
#include "fnv/decl/S4.h"
#include "fnv/decl/S457d70.h"
#include "fnv/decl/S4eb0.h"
#include "fnv/decl/S694a0.h"
#include "fnv/decl/SPShader.h"
#include "fnv/decl/SSN.h"
#include "fnv/decl/SSN_cand.h"
#include "fnv/decl/S_006c0900.h"
#include "fnv/decl/S_Cls.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/S_ad8700.h"
#include "fnv/decl/SceneUpdate__World.h"
#include "fnv/decl/ScreenCustomSplatter.h"
#include "fnv/decl/ScreenSplatter.h"
#include "fnv/decl/ScriptLocals.h"
#include "fnv/decl/ScriptPool.h"
#include "fnv/decl/ShadowSceneLight.h"
#include "fnv/decl/ShadowSceneNode.h"
#include "fnv/decl/ShadowSceneNodeX.h"
#include "fnv/decl/ShadowUpdate_b9e.h"
#include "fnv/decl/Shell451.h"
#include "fnv/decl/Shell_006eb980.h"
#include "fnv/decl/Sky.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TES.h"
#include "fnv/decl/TESFileArray.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskOwnerTarget.h"
#include "fnv/decl/TaskThreadManager.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TexturePool.h"
#include "fnv/decl/ThreadCoordinator_ba2f30.h"
#include "fnv/decl/ThreadStageSignalDetail__RenderingStageController.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/VATSRender.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WS458200_Shell.h"
#include "fnv/decl/WaterTextureLoader.h"
#include "fnv/decl/WaterUpdate.h"
#include "fnv/decl/WorldCellLoader.h"
#include "fnv/decl/Zt5TES.h"
#include "fnv/decl/_dummy_476a80.h"
#include "fnv/decl/fn_00c51f20__Owner.h"
#include "fnv/decl/fnv_00404f70__FUN_00404f70_shell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00439390__NiObjectNET.h"
#include "fnv/decl/fnv_00448420__ModelLoader.h"
#include "fnv/decl/fnv_00451530__FUN_00451530_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_00454450__ReloadManager.h"
#include "fnv/decl/fnv_00455490__Q455490TES.h"
#include "fnv/decl/fnv_00457070__FUN_00457070_shell.h"
#include "fnv/decl/fnv_0045a1e0__Target45.h"
#include "fnv/decl/fnv_0045a370__TextureLoader.h"
#include "fnv/decl/fnv_0045bc80__ThisC.h"
#include "fnv/decl/fnv_00461ae0__FUN_00461ae0_shell.h"
#include "fnv/decl/fnv_00463070__FUN_00463070_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0049ede0__FUN_0049ede0_shell.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_004bc450__FUN_004bc450_S.h"
#include "fnv/decl/fnv_004e65d0__S_004e65d0.h"
#include "fnv/decl/fnv_004e6620__WaterCleanup.h"
#include "fnv/decl/fnv_004e9530__NiRenderer.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_0054cfd0__TESObjectCELL_Ext.h"
#include "fnv/decl/fnv_00550200__FUN_00550200.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_0063a630__ThisCls.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_006c09f0__ManagerView.h"
#include "fnv/decl/fnv_006c3640__C006c3640.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0084a840__FUN_0084a840_shell.h"
#include "fnv/decl/fnv_0086c880__FUN_0086c880.h"
#include "fnv/decl/fnv_0087a6f0__FUN_0087a6f0_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008a8150__FUN_008a8150_shell.h"
#include "fnv/decl/fnv_008a8870__HA.h"
#include "fnv/decl/fnv_008b6200__FUN_008b6200.h"
#include "fnv/decl/fnv_008ca070__Obj.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_0095ee80__FUN_0095ee80_Class.h"
#include "fnv/decl/fnv_00964260__SelActor.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_0096c860__FUN_0096c860_shell.h"
#include "fnv/decl/fnv_0096d810__FUN_0096d810_shell.h"
#include "fnv/decl/fnv_0096eb40__FUN_0096eb40_cls.h"
#include "fnv/decl/fnv_00978550__FUN_00978550_shell.h"
#include "fnv/decl/fnv_00979260__Projectile.h"
#include "fnv/decl/fnv_00991600__FUN_00991600_shell.h"
#include "fnv/decl/fnv_009d9f20__FUN_009d9f20_shell.h"
#include "fnv/decl/fnv_00afdda0__PathList.h"
#include "fnv/decl/fnv_00b5cbd0__ShadowSceneNode_Self.h"
#include "fnv/decl/fnv_00b5d300__OwnerD.h"
#include "fnv/decl/fnv_00b5e870__Self.h"
#include "fnv/decl/fnv_00b63b90__FUN_00b63b90_class.h"
#include "fnv/decl/fnv_00b64570__DepthAccumulator.h"
#include "fnv/decl/fnv_00b651e0__Sh651_Batch.h"
#include "fnv/decl/fnv_00b9dfc0__ShadowSceneLightDecompile.h"
#include "fnv/decl/fnv_00c3dbf0__IOManager.h"
#include "fnv/decl/fnv_00ec25e0__FUN_00ec25e0_cls.h"
#include "fnv/decl/s005468d0__Owner.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040d000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045a000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_0045d000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0049f000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b4000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004b8000.h"
#include "fnv/symbols_004bc000.h"
#include "fnv/symbols_004da000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004de000.h"
#include "fnv/symbols_004e0000.h"
#include "fnv/symbols_004e1000.h"
#include "fnv/symbols_004e2000.h"
#include "fnv/symbols_004e6000.h"
#include "fnv/symbols_004e9000.h"
#include "fnv/symbols_004ec000.h"
#include "fnv/symbols_0050e000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00526000.h"
#include "fnv/symbols_00546000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_0054a000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_00552000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00564000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_0057a000.h"
#include "fnv/symbols_0057c000.h"
#include "fnv/symbols_005a3000.h"
#include "fnv/symbols_005a9000.h"
#include "fnv/symbols_005aa000.h"
#include "fnv/symbols_005ae000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_005ba000.h"
#include "fnv/symbols_005bf000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_005d2000.h"
#include "fnv/symbols_005d4000.h"
#include "fnv/symbols_00622000.h"
#include "fnv/symbols_00626000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_00665000.h"
#include "fnv/symbols_00683000.h"
#include "fnv/symbols_006a2000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_006d0000.h"
#include "fnv/symbols_006da000.h"
#include "fnv/symbols_006ff000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00710000.h"
#include "fnv/symbols_00713000.h"
#include "fnv/symbols_00714000.h"
#include "fnv/symbols_00762000.h"
#include "fnv/symbols_00772000.h"
#include "fnv/symbols_00794000.h"
#include "fnv/symbols_007a1000.h"
#include "fnv/symbols_007c9000.h"
#include "fnv/symbols_007fd000.h"
#include "fnv/symbols_007ff000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00832000.h"
#include "fnv/symbols_00866000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00868000.h"
#include "fnv/symbols_00869000.h"
#include "fnv/symbols_0086a000.h"
#include "fnv/symbols_0086b000.h"
#include "fnv/symbols_0086c000.h"
#include "fnv/symbols_0086d000.h"
#include "fnv/symbols_0086e000.h"
#include "fnv/symbols_0086f000.h"
#include "fnv/symbols_00870000.h"
#include "fnv/symbols_00871000.h"
#include "fnv/symbols_00872000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_00876000.h"
#include "fnv/symbols_00877000.h"
#include "fnv/symbols_00878000.h"
#include "fnv/symbols_0096c000.h"
#include "fnv/symbols_00990000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a0d000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_00a24000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00a62000.h"
#include "fnv/symbols_00a81000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_00aa4000.h"
#include "fnv/symbols_00aa7000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_00b01000.h"
#include "fnv/symbols_00b4d000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b54000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00b57000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00b60000.h"
#include "fnv/symbols_00b63000.h"
#include "fnv/symbols_00b65000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00b80000.h"
#include "fnv/symbols_00b8a000.h"
#include "fnv/symbols_00b8b000.h"
#include "fnv/symbols_00b97000.h"
#include "fnv/symbols_00b98000.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_00ba9000.h"
#include "fnv/symbols_00bad000.h"
#include "fnv/symbols_00bc2000.h"
#include "fnv/symbols_00c3a000.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_00c5d000.h"
#include "fnv/symbols_00c66000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0105b000.h"
#include "fnv/symbols_01082000.h"
#include "fnv/symbols_011a2000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011af000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d7000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f8000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_011ff000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01201000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
#include "main.h"
#include "fnv/decl/FUN_00b63e90_cls.h"
#include <stdio.h>

// The camera of a rendered menu (FORenderedMenu), read by 0x008b6200.
struct RenderedMenuCameraView
{
    char pad00[0x24];
    NiCamera* camera;
};

// The scene graph node of a menu, read by 0x0056c7f0.
struct MenuNodeView
{
    char pad00[0x2c];
    NiNode* pNode;
};

// The leading OSGlobals members: state flags, the main window and the process instance.
struct OSGlobalsView
{
    bool flags[8];
    HWND window;
    HINSTANCE instance;
};


// @fnv 0x004dc310
bool __cdecl FUN_004dc310()
{
    return DAT_011c70cc >= 2;
}


// Creates a new SceneGraph named "Menu" and stores it in the global NiPointer g_011dee84.
// @fnv 0x004dc5c0
void FUN_004dc5c0()
{
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011dee84)) = reinterpret_cast<NiNode*>(new SceneGraph("Menu", true, 0));
}

struct Node
{
    char pad[8];
    int v;
};
struct FUN_004ed8c0_shell
{
    void FUN_004ed8c0(int* e);
};
// Gets a Node via FUN_0049fa80, stores the int pointed to by e into its v field, then passes the node to FUN_00559a70.
// @fnv 0x004ed8c0
void FUN_004ed8c0_shell::FUN_004ed8c0(int* piValue)
{
    Node* n = ((::Node *)(reinterpret_cast<::ScriptPool *>(this)->FUN_0049fa80()));
    n->v = *piValue;
    reinterpret_cast<::FUN_00559a70_Class *>(this)->FUN_00559a70(n);
}

struct BGSAddonNode;
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int FUN_00877a50(unsigned int&);
};
struct S86
{
    char p[0xad4];
    Idx86 i;
    char q[0xae4 - 0xad5];
    Arr86 a;
    unsigned int FUN_0086bae0(unsigned int key, BGSAddonNode* node);
};
// @fnv 0x0086bae0
unsigned int S86::FUN_0086bae0(unsigned int key, BGSAddonNode* node)
{
    unsigned int idx = i.FUN_00877a50(key);
    a.SetAt(idx, node);
    return idx;
}

namespace fnv_0086bbd0 {
struct BGSAddonNode;
struct Arr86
{
    void SetAt(unsigned int, BGSAddonNode*&);
};
struct Idx86
{
    unsigned int FUN_00877a50(unsigned int&);
};
struct S86b
{
    char p[0xaf4];
    Idx86 i;
    char q[0xb04 - 0xaf5];
    Arr86 a;
    unsigned int FUN_0086bbd0(unsigned int key, BGSAddonNode* node);
};
// @fnv 0x0086bbd0
unsigned int S86b::FUN_0086bbd0(unsigned int key, BGSAddonNode* node)
{
    unsigned int idx = i.FUN_00877a50(key);
    a.SetAt(idx, node);
    return idx;
}
}  // namespace fnv_0086bbd0

struct Dummy_0086bce0
{
};

// @fnv 0x0086bce0
void __cdecl FUN_0086bce0(intptr_t aiValue)
{
    if ((*reinterpret_cast<::Dummy_0086bce0 * *>(&::g_fileFinder)))
        reinterpret_cast<::fnv_00afdda0::PathList *>(((*reinterpret_cast<::Dummy_0086bce0 * *>(&::g_fileFinder))))->FUN_00afdda0((const char *)(aiValue));
}

void __cdecl FUN_0086bd90(void(__cdecl*)());

// @fnv 0x0086bd70
void __cdecl FUN_0086bd70()
{
    FUN_0086bd90(((void (&)())::FUN_00b013f0));
}

// @fnv 0x0086bda0
void FUN_0086bda0(intptr_t param_1)
{
    if (*(int*)(param_1 + 0x5c) == 1 || *(int*)(param_1 + 0x5c) == 2)
    {
        *(int*)(param_1 + 0x5c) = 3;
    }
}

class BGSLoadGameBuffer;

class Interface
{
  public:
public:
    static void Init(bool);
public:
    static void RefreshInterfaceState();
public:
    static bool IsGamePaused();
public:
    static bool IsInterfaceActive();
public:
    static float GetInterfaceFloat();
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
public:
    void UpdateMagicTempEffects(float);
public:
    void UpdateFollowerTempList();
public:
    void UpdateInterfaceTempEffects(float);
};

class GlobalObject_0044f440
{
  public:
};

class GlobalObject_0045cf30
{
};

void __cdecl FUN_0086bff0(void(__cdecl*)());

extern GlobalObject_0044f440 g_011deb70;
extern GlobalObject_0044f440 g_011dec18;
extern GlobalObject_0045cf30 g_011ded68;
extern GlobalObject_0045cf30 g_011deea8;

extern unsigned char DAT_011f9443;
extern float DAT_011f9480;
extern float DAT_011f9484;

// @fnv 0x0086bf70
void __cdecl FUN_0086bf70()
{
    ::FUN_0040fbe0();
    FUN_005c5a60(0);
    FUN_0086bff0(((void (&)())::FUN_0086a480));
    ::FUN_0086c000(*reinterpret_cast<ProcessLists*>(&g_011ded68)->GetLifeStateControlFlag());
    DAT_011f9443 = *reinterpret_cast<ProcessLists*>(&g_011deea8)->GetLifeStateControlFlag();
    DAT_011f9484 = reinterpret_cast<::FUN_00450410_Class *>(&(g_011dec18))->FUN_00450410();
    DAT_011f9480 = reinterpret_cast<::FUN_00450410_Class *>(&(g_011deb70))->FUN_00450410();
}

namespace fnv_0086d490 {
struct NiPoint3_local
{
    int x, y, z;
};

class TESObjectREFR
{
  public:
    void SetReferencePosition(NiPoint3_local aPoint);
};

struct FUN_0086d490_class : public TESObjectREFR
{
    void impl(const NiPoint3_local& arPoint);
};

// @fnv 0x0086d490
void FUN_0086d490_class::impl(const NiPoint3_local& arPoint)
{
    SetReferencePosition(arPoint);
}
}  // namespace fnv_0086d490

const char* __cdecl FUN_0086d580();

// Calls FUN_004da670 with the window and the process instance; on failure formats an error message with FUN_0086d580, shows a MessageBoxA and calls ExitProcess(0).
// The leading fields of OSGlobals (include/OSGlobals.h).
struct OSGlobalsWindowView
{
    unsigned char flags[8];
    void* window;
    void* procInstance;
};

// @fnv 0x0086d500
void FUN_0086d500(OSGlobals* pThis)
{
    char buf[512];
    OSGlobalsWindowView* globals = reinterpret_cast<OSGlobalsWindowView*>(pThis);
    if (!::fnv_004da670::FUN_004da670(globals->window, globals->procInstance))
    {
        std::sprintf(buf, "Failed to initialize renderer.\n%s", FUN_0086d580());
        MessageBoxA(0, buf, "Fallout", 0);
        ExitProcess(0);
    }
}

class NiGeometryData;

class NiScreenElementsData
{
  public:
public:
    bool SetRectangle(int, float, float, float, float);
public:
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
};

class NiGeometry
{
  public:
};

struct FUN_0086e3f0_shell : public NiGeometry
{
    bool FUN_0086e3f0(unsigned short usNumVertices, unsigned short usNumTriangles, intptr_t ausTriList);
};

// Forwards the vertex count, triangle count and triangle list to the geometry data's FUN_00a87ae0 and returns its result.
// @fnv 0x0086e3f0
bool FUN_0086e3f0_shell::FUN_0086e3f0(unsigned short usNumVertices, unsigned short usNumTriangles, intptr_t ausTriList)
{
    return ((bool)(reinterpret_cast<::NiScreenElementsDataShell *>((((NiScreenElementsData*)((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)this))))))->FUN_00a87ae0(usNumVertices, usNumTriangles, (const unsigned short *)(ausTriList))));
}

namespace fnv_0086e420 {
struct NiGeometryData;
struct NiGeometry
{
};
struct NiScreenElementsData
{
};
struct FUN_0086e420_shell : NiGeometry
{
    void FUN_0086e420(int a, float b, float c, float d, float e);
};
// @fnv 0x0086e420
void FUN_0086e420_shell::FUN_0086e420(int a, float b, float c, float d, float e)
{
    reinterpret_cast<::NiScreenElementsData *>((((NiScreenElementsData*)((::fnv_0086e420::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)this))))))->SetRectangle(a, b, c, d, e);
}
}  // namespace fnv_0086e420

namespace fnv_0086e460 {
struct NiScreenElementsData
{
};
struct NiGeometry
{
};
struct FUN_0086e460_shell : public NiGeometry
{
    bool FUN_0086e460(int, unsigned short, float, float, float, float);
};
// Forwards the polygon, set and rectangle coordinates to the screen elements data returned by FUN_005495f0 and returns its result.
// @fnv 0x0086e460
bool FUN_0086e460_shell::FUN_0086e460(int iPolygon, unsigned short usSet, float fLeft, float fTop, float fRight,
                                      float fBottom)
{
    return reinterpret_cast<::NiScreenElementsData *>((((NiScreenElementsData*)((::fnv_0086e460::NiScreenElementsData *)(::fnv_005495f0::FUN_005495f0((const char *)this))))))->SetRectangleBounds(iPolygon, usSet, fLeft, fTop, fRight, fBottom);
}
}  // namespace fnv_0086e460

namespace fnv_0086e4b0 {
class NiGeometryData;

class NiGeometry
{
  public:
};

class NiScreenElementsData
{
  public:
};

// @fnv 0x0086e4b0
void FUN_0086e4b0(NiGeometry* apGeometry)
{
    reinterpret_cast<::FUN_00a87900_class *>((((NiScreenElementsData*)((::fnv_0086e4b0::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeometry)))))))->FUN_00a87900();
}
}  // namespace fnv_0086e4b0

class BSPackedTask;
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
public:
    void QueueActorDisarm(bool);
public:
    static ::TaskQueueInterface *GetSingleton();
public:
    void SetTaskFlag2000(bool);
public:
    static void ThreadProcessSecondaryInput();
public:
    static void ThreadProcessInput(unsigned int);
public:
    void ProcessTaskQueue();
public:
    void SetTaskFlag(bool);
    void QueueReferenceStateTask(bool);
    void FUN_004902f0(bool);
    void FUN_004ef970(bool);
    void SetTaskFlag_005468b0(bool);
    void FUN_00566930(bool);
    void FUN_00576640(bool);
    ::NiPoint3 &QueueActorAnimationTask(::NiPoint3 &);
    void FUN_00635fe0(bool);
    static void ProcessQueuedTask(const ::BSPackedTask &);
    void ProcessPackedTask(const ::BSPackedTask &);
    void FUN_0087e100(bool);
    void SetTaskFlag_008d6f10(bool);
};


// @fnv 0x0086e4e0
void __cdecl FUN_0086e4e0(const char* apPath)
{
    TaskQueueInterface::CopyStringToBuffer(DAT_011f9308, 0x104, apPath);
}


// @fnv 0x0086e520
void __cdecl FUN_0086e520(NiNode* apRenderer)
{
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::DAT_011f9508)) = apRenderer;
}

namespace fnv_0086e540 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};


// @fnv 0x0086e540
unsigned char FUN_0086e540()
{
    return *(*reinterpret_cast<::fnv_0086e540::ProcessLists *>(&::g_011c7154)).GetLifeStateControlFlag();
}
}  // namespace fnv_0086e540

namespace fnv_0086e560 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};


// @fnv 0x0086e560
unsigned char FUN_0086e560()
{
    return *(*reinterpret_cast<::fnv_0086e560::ProcessLists *>(&::g_011c7544)).GetLifeStateControlFlag();
}
}  // namespace fnv_0086e560

namespace fnv_0086e580 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};


// @fnv 0x0086e580
unsigned char FUN_0086e580()
{
    return *(*reinterpret_cast<::fnv_0086e580::ProcessLists *>(&::g_011c712c)).GetLifeStateControlFlag();
}
}  // namespace fnv_0086e580

namespace fnv_0086e5a0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};


// @fnv 0x0086e5a0
unsigned char FUN_0086e5a0()
{
    return *(*reinterpret_cast<::fnv_0086e5a0::ProcessLists *>(&::g_011c7180)).GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5a0

namespace fnv_0086e5c0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

// @fnv 0x0086e5c0
unsigned char FUN_0086e5c0()
{
    return *(*reinterpret_cast<::fnv_0086e5c0::ProcessLists *>(&::g_011c7368)).GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5c0

namespace fnv_0086e5e0 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

// @fnv 0x0086e5e0
unsigned char FUN_0086e5e0()
{
    return *(*reinterpret_cast<::fnv_0086e5e0::ProcessLists *>(&::g_011c7380)).GetLifeStateControlFlag();
}
}  // namespace fnv_0086e5e0

namespace fnv_0086e600 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};


// @fnv 0x0086e600
unsigned char FUN_0086e600()
{
    return *(*reinterpret_cast<::fnv_0086e600::ProcessLists *>(&::g_011c7550)).GetLifeStateControlFlag();
}
}  // namespace fnv_0086e600


// @fnv 0x0086e630
void FUN_0086e630(NiNode* apTreeNode)
{
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d86bc)) = apTreeNode;
}


// @fnv 0x0086ef40
void FUN_0086ef40()
{
    DAT_011f9138 = DAT_011f9138 + 1;
}

class TileMenu;
class StartMenu
{
  public:
    enum Flag
    {
    };
    bool IsFlagSet(Flag);
public:
    ::TileMenu *GetMenuTitle();
};


// @fnv 0x0086efa0
bool FUN_0086efa0()
{
    return (*reinterpret_cast<::StartMenu * *>(&::fnv_007d0700::DAT_011daac0)) && (*reinterpret_cast<::StartMenu * *>(&::fnv_007d0700::DAT_011daac0))->IsFlagSet((StartMenu::Flag)0x10000);
}

namespace fnv_0086f260 {
struct TG
{
};
struct PL
{
    unsigned char* GetLifeStateControlFlag();
};
struct GlobalA
{
};
struct SetA
{
};
struct BGSLoadFormBuffer
{
    void FUN_008a8150(unsigned char);
};
struct GameTimerRecord
{
    void Update();
};
struct Twin_0084d030
{
};
struct TESObjectREFR
{
};
struct Mover
{
    void FUN_0086f260();
};
// @fnv 0x0086f260
void Mover::FUN_0086f260()
{
    ::fnv::timer::SetUseGlobalMultiplierTarget(*(*reinterpret_cast<::fnv_0086f260::PL *>(&::g_011dedbc)).GetLifeStateControlFlag());
    if (!::DAT_011dea2b)
        ::FUN_00aa4e40();
    ::fnv::timer::Update();
    ::DAT_011afe60 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086f260::SetA *>(&::originalRuntimeFloatSetting807))))));
    ::FUN_00c66760(::fnv::timer::Seconds(), ((bool)(::FUN_00525420())), reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode == 4);
    ::FUN_0086f330();
    ::DAT_011dea30 =
        (float)(::DAT_011dea2b ? 0.0 : ::fnv::timer::Seconds() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086f260::SetA *>(&::g_011c5724)))))));
}
}  // namespace fnv_0086f260


// Fills the four-element DAT_011f940c array by calling DAT_011f91f0 for each index, or storing 0.0f when the function pointer is null.
// @fnv 0x0086f330
void FUN_0086f330()
{
    for (int i = 0; i < 4; i++)
    {
        (*reinterpret_cast<float (*)[4]>(&::DAT_011f940c))[i] = DAT_011f91f0 ? DAT_011f91f0(i) : 0.0f;
    }
}

namespace fnv_0086f390 {
struct FUN_0086f390_shell : public Main
{
    void FUN_0086f390();
    char pad01[0x6];
    unsigned char unk06;
};

struct PlayerCharacter
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual bool V8B(int);
};
struct TESObjectREFR
{
};
struct TimeGlobal
{
};
struct Interface
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
struct HotkeyWheelDisplay
{
    void FUN_00a253d0();
};
// @fnv 0x0086f390
void FUN_0086f390_shell::FUN_0086f390()
{
    reinterpret_cast<::InputPoller *>((((::fnv_0086f390::HotkeyWheelDisplay *)(::FUN_007fdf30()))))->FUN_00a23010();
    reinterpret_cast<::FUN_00a257c0_Class *>((((::fnv_0086f390::HotkeyWheelDisplay *)(::FUN_007fdf30()))))->FUN_00a257c0(::fnv::timer::UnmodifiedSeconds());
    if (!this->unk06 && !(*reinterpret_cast<::fnv_0086f390::PlayerCharacter * *>(&::_g_thePlayer))->V8B(0))
    {
        if ((reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode == 4 && !reinterpret_cast<::C7D1360Actor *>(((*reinterpret_cast<::fnv_0086f390::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_007d1360()) || ::FUN_00709bc0())
        {
            if (!Interface::IsMenuActive((Interface::enumMenus)0x3e9, 0) && !((bool)(::IsStartMenuFlag1Set())))
                ((::fnv_0086f390::HotkeyWheelDisplay *)(::FUN_007fdf30()))->FUN_00a253d0();
        }
    }
}
}  // namespace fnv_0086f390

struct FUN_0086f640_shell : public Main
{
    void FUN_0086f640();
};

class BSAudio
{
  public:
    void Update(bool);
public:
    void SetAudioState(unsigned int);
};

class FalloutRadio
{
  public:
    static bool __cdecl Update(bool);
public:
    static bool SetRadioEnabled(bool);
};

class FalloutAudioMedia
{
  public:
    static void __cdecl Update();
public:
    static void BeginMediaUpdate();
};

class SoundPlaybackManager
{
  public:
    static void __cdecl ProcessPendingSounds();
};

// @fnv 0x0086f640
void FUN_0086f640_shell::FUN_0086f640()
{
    ::FUN_00453a70()->Update(true);
    FalloutRadio::Update(false);
    ::UpdateMediaLocation();
    SoundPlaybackManager::ProcessPendingSounds();
}

struct FUN_0086f670_shell : public Main
{
    void FUN_0086f670();
};

extern unsigned char DAT_012682f8;
extern unsigned char DAT_011df678;
extern unsigned char DAT_011dea2a;
class TES;


// @fnv 0x0086f670
void FUN_0086f670_shell::FUN_0086f670()
{
    DAT_012682f8 = 0;
    DAT_011df678 = 0;
    DAT_011dea2a = 0;
    ::fnv_005a38e0::FUN_005a38e0();
    reinterpret_cast<::fnv_00455490::Q455490TES *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00455490();
}

// @fnv 0x0086f840
bool FUN_0086f840(char* pThis)
{
    return *(bool*)(pThis + 0x16c);
}


// Returns the byte at offset 0x131 of the object pointed to by DAT_011d9510, or false if that pointer is null.
// @fnv 0x0086f860
bool FUN_0086f860()
{
    return DAT_011d9510 ? DAT_011d9510[0x131] : false;
}

struct FUN_0086f890_shell : public Main
{
    void FUN_0086f890();
    unsigned char pad00[0x7];
    unsigned char unk07;
};

struct GlobalObject2_0040c150
{
};



// @fnv 0x0086f890
void FUN_0086f890_shell::FUN_0086f890()
{
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) == 1)
    {
        reinterpret_cast<::fnv_0096eb40::FUN_0096eb40_cls *>((&(*reinterpret_cast<int *>(&::g_011e0e80))))->FUN_0096eb40();
    }

    if ((!DAT_011dea2b || DAT_011dea2d) && !DAT_011dea2e && !unk07)
    {
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) == 1)
        {
            reinterpret_cast<::TaskOwnerTarget *>((&DAT_011e0fe0))->FUN_008c94e0();
            reinterpret_cast<::FUN_00991dc0_shell *>((BGSSaveLoadGlobalDataWorldspacePtr))->FUN_00991dc0();
        }
        reinterpret_cast<::fnv_0096d810::FUN_0096d810_shell *>((&(*reinterpret_cast<int *>(&::g_011e0e80))))->FUN_0096d810();
    }
    else if (DAT_011dea2b || unk07)
    {
        reinterpret_cast<::fnv_00964260::SelActor *>((::_g_thePlayer))->FUN_00964260();
    }
}

void __cdecl FUN_007027e0();
void __cdecl FUN_00702810();
void __cdecl FUN_00702840();

// @fnv 0x0086fd70
void FUN_0086fd70(void* pThis)
{
    ::fnv_007027e0::FUN_007027e0();
    ::fnv_00702810::FUN_00702810();
    ::fnv_00702840::FUN_00702840();
}

extern float DAT_011c96fc;

// @fnv 0x0086ff50
void __cdecl FUN_0086ff50(float afDelta)
{
    DAT_011c96fc += afDelta;
}

namespace fnv_008705d0 {
struct GlobalObject2_0040c150
{
};



// Calls FUN_0086f640, FUN_0086f890, then FUN_00552570 if *g_011c3ea4.Int() > 1, and finally FUN_0086f670 on pThis.
// @fnv 0x008705d0
void FUN_008705d0(void* pThis)
{
    reinterpret_cast<::FUN_0086f640_shell *>((pThis))->FUN_0086f640();
    reinterpret_cast<::FUN_0086f890_shell *>((pThis))->FUN_0086f890();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_008705d0::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
    {
        ::fnv_00552570::FUN_00552570();
    }
    reinterpret_cast<::FUN_0086f670_shell *>((pThis))->FUN_0086f670();
}
}  // namespace fnv_008705d0

namespace fnv_00870610 {
struct FUN_00870610_shell : public Main
{
    void FUN_00870610();
};

class GlobalObject2_0040c150
{
  public:
};

class TaskQueueInterface
{
  public:
};

class DebugText
{
  public:
};


void FUN_00870680(void*);

// @fnv 0x00870610
void FUN_00870610_shell::FUN_00870610()
{
    ::fnv_005aa720::FUN_005aa720();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00870610::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
    {
        reinterpret_cast<::FUN_0087a710_shell *>((((::fnv_00870610::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087a710();
        reinterpret_cast<::TaskQueueInterface *>((((::fnv_00870610::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton()))))->ProcessTaskQueue();
        reinterpret_cast<::fnv_0087a6f0::FUN_0087a6f0_shell *>((((::fnv_00870610::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087a6f0();
    }
    ::s7094f0::FUN_007094f0();
    ::FUN_00870680(((void *)(::fnv_004b7210::FUN_004b7210())));
    reinterpret_cast<::AudioManager *>((((::fnv_00870610::DebugText *)(::FUN_00a0d9e0(true)))))->FUN_00a0e770();
}
}  // namespace fnv_00870610

void __cdecl FUN_00706320(int);

// The object FUN_00870680 takes, as far as it reads it.
struct FUN_00870680_Object
{
    char pad00[0x4cc];
    unsigned char unk4cc;
};

// If unk4cc is set, calls FUN_00706320(0) and clears it.
// @fnv 0x00870680
void FUN_00870680(void* param_1)
{
    if (static_cast<FUN_00870680_Object*>(param_1)->unk4cc)
    {
        FUN_00706320(0);
        static_cast<FUN_00870680_Object*>(param_1)->unk4cc = 0;
    }
}

namespace fnv_008706b0 {
struct BSRenderedTexture;
struct FUN_008706b0_shell : public Main
{
    void FUN_008706b0(BSRenderedTexture*, bool, bool);
};

struct P3
{
    float x, y, z;
};
struct ShadowSceneNode
{
};
struct NiNode
{
    const P3& FUN_0045bb80() const;
};
struct BSFaceGenAnimationData : public NiNode
{
};
struct BSFaceGenNiNode
{
    BSFaceGenAnimationData* GetAnimationData();
};
struct NiAdditionalGeometryData
{
};
struct Interface
{
    enum enumMenus
    {
        MENU_DUMMY
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
struct MainStub
{
    void FUN_008707c0(BSRenderedTexture*, bool);
    void FUN_00870a00(BSRenderedTexture*, bool);
    void FUN_00870bd0(BSRenderedTexture*, bool);
};
// @fnv 0x008706b0
void FUN_008706b0_shell::FUN_008706b0(BSRenderedTexture* pTexture, bool bCheckMenu, bool bFlag)
{
    bool f = ::FUN_00870770((const char *)(((::fnv_008706b0::ShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))));
    ::FUN_00870790((::_Fake_FUN_00870790 *)(((::fnv_008706b0::ShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))), 
        (*(::NiPoint3 *)&(const ::fnv_008706b0::P3 &)(((::fnv_008706b0::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData()->FUN_0045bb80())));
    if (bCheckMenu && !Interface::IsMenuActive((Interface::enumMenus)0x3f5, 0))
        ((MainStub*)this)->FUN_008707c0(pTexture, f);
    else if (f)
        ((MainStub*)this)->FUN_00870a00(pTexture, bFlag);
    else
        ((MainStub*)this)->FUN_00870bd0(pTexture, bFlag);
}
}  // namespace fnv_008706b0

// @fnv 0x00870770
bool FUN_00870770(const char* pThis)
{
    return *(const bool*)(pThis + 0x131);
}

struct NiStream;
struct blob12
{
    char b[12];
};

struct _Fake_FUN_00870790
{
    char pad[0x1f0];
    NiPoint3 pos;
};

// Stores aPosition into the pos field of the object at offset 0x1f0.
// @fnv 0x00870790
void FUN_00870790(_Fake_FUN_00870790* pThis, NiPoint3 aPosition)
{
    pThis->pos = aPosition;
}

// Returns whether the float at offset 0x70 of pThis is greater than zero.
// @fnv 0x00871220
bool FUN_00871220(char* pObject)
{
    return *(float*)(pObject + 0x70) > 0.0;
}

struct NiNode871
{
};
struct GO871
{
    operator NiNode871*() const;
};
// Returns false if g_011c7810 is null, otherwise returns whether its FUN_00453470 result is greater than zero.
// @fnv 0x00871260
bool FUN_00871260()
{
    if (!(NiNode871*)(*reinterpret_cast<::GO871 *>(&::g_011c7810)))
        return false;
    return ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((((NiNode871*)(*reinterpret_cast<::GO871 *>(&::g_011c7810)))))->FUN_00453470())) > 0;
}

namespace fnv_00871a10 {
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};


// @fnv 0x00871a10
unsigned char FUN_00871a10()
{
    return *(*reinterpret_cast<::fnv_00871a10::ProcessLists *>(&::g_011c74d4)).GetLifeStateControlFlag();
}
}  // namespace fnv_00871a10

// @fnv 0x00871a30
std::intptr_t FUN_00871a30(std::intptr_t param_1)
{
    return param_1 + 0x88;
}

namespace fnv_00871c90 {
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct HotkeyWheelDisplay
{
};
struct GameTimerRecord
{
};
struct GlobalObject_0045cf30
{
};
struct TimeGlobal
{
};
void FUN_00a237b0(HotkeyWheelDisplay*);
void FUN_00a253d0(HotkeyWheelDisplay*);
struct FUN_00871c90_shell
{
    char pad[3];
    bool f;
    void FUN_00871c90(bool b);
};
// @fnv 0x00871c90
void FUN_00871c90_shell::FUN_00871c90(bool abEnabled)
{
    if (*((ProcessLists*)&(*reinterpret_cast<::fnv_00871c90::GlobalObject_0045cf30 *>(&::g_011deed8)))->GetLifeStateControlFlag())
        abEnabled = 1;
    if (((::fnv_00871c90::HotkeyWheelDisplay *)(::FUN_007fdf30())))
    {
        FUN_00a237b0(((::fnv_00871c90::HotkeyWheelDisplay *)(::FUN_007fdf30())));
        reinterpret_cast<::InputPoller *>((((::fnv_00871c90::HotkeyWheelDisplay *)(::FUN_007fdf30()))))->FUN_00a23010();
        FUN_00a253d0(((::fnv_00871c90::HotkeyWheelDisplay *)(::FUN_007fdf30())));
    }
    if (abEnabled)
        ::fnv::timer::Resume();
    else
        ::fnv::timer::Pause();
    f = abEnabled;
}
}  // namespace fnv_00871c90

struct O872
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int FUN_00872370(unsigned int i);
};
// Returns the virtual call result of the element at index i, or 0 when that element is null.
// @fnv 0x00872370
int S872::FUN_00872370(unsigned int uiIndex)
{
    return h[uiIndex] ? ((O872*)h[uiIndex])->vf() : 0;
}

namespace fnv_008723d0 {
struct O872
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual int vf();
};
struct H872
{
    int pad;
    operator O872*() const;
};
struct S872
{
    char p[0x30];
    H872 h[1];
    int FUN_008723d0(unsigned int i);
};
// Returns the result of the virtual call on the object at index i, or 0 if that slot is null.
// @fnv 0x008723d0
int S872::FUN_008723d0(unsigned int uiIndex)
{
    return h[uiIndex] ? ((O872*)h[uiIndex])->vf() : 0;
}
}  // namespace fnv_008723d0

struct FUN_00874460_cls
{
    char pad[0xc0];
    int m_field_c0;
    void set(intptr_t v);
};

// @fnv 0x00874460
void FUN_00874460_cls::set(intptr_t aiValue)
{
    m_field_c0 = aiValue;
}

// @fnv 0x00874480
intptr_t FUN_00874480(char* pThis)
{
    return *(int*)(pThis + 0xfc);
}

// @fnv 0x00874670
void* FUN_00874670(char* pThis)
{
    return pThis + 0x138;
}

// @fnv 0x00874900
float FUN_00874900(const char* pThis)
{
    return *(const float*)(pThis + 0x674);
}

namespace fnv_00874ac0 {
struct FUN_00874ac0_shell : public Main
{
    void FUN_00874ac0(bool);
};

struct StrG
{
    operator const char*() const;
};
enum BSRENDERSTATE_LOCK
{
    BSRS_LOCK_DUMMY
};
struct BSRenderStateManager
{
};
struct BSRenderedTexture
{
    static void EndAllAndResetRendererState();
};
struct KFModel
{
};
struct ShadowLightData : public KFModel
{
};
struct Interface
{
};
// @fnv 0x00874ac0
void FUN_00874ac0_shell::FUN_00874ac0(bool b)
{
    void* seq = ((void *)(reinterpret_cast<::TESRegionDataMap *>((((::fnv_00874ac0::ShadowLightData *)(::fnv_00705910::FUN_00705910()))))->GetRegionMapName()));
    if (seq)
    {
        BSRenderedTexture::EndAllAndResetRendererState();
        ::BSRenderStateManager::SetColorWriteMask(0, (*(::BSRENDERSTATE_LOCK *)&(const ::fnv_00874ac0::BSRENDERSTATE_LOCK &)((BSRENDERSTATE_LOCK)1)));
        reinterpret_cast<::VATSRender *>((((::fnv_00874ac0::ShadowLightData *)(::fnv_00705910::FUN_00705910()))))->FUN_00800f30((::RenderTexture *)((const char*)(*reinterpret_cast<::fnv_00874ac0::StrG *>(&::g_011deb38))), 0, 0, 1, 7, 0);
        ::FUN_004eced0(1);
        reinterpret_cast<::VATSRender *>((((::fnv_00874ac0::ShadowLightData *)(::fnv_00705910::FUN_00705910()))))->FUN_00800f30((::RenderTexture *)((const char*)(*reinterpret_cast<::fnv_00874ac0::StrG *>(&::g_011deb38))), 0, 0, 0, 1, 1);
    }
}
}  // namespace fnv_00874ac0

struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct blob16
{
    char b[16];
};
enum ImageSpaceManager__ImageSpaceEffectEnum;
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void CreateMenuBackgroundGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
public:
    static ::ImageSpaceManager *FUN_004e3270();
public:
    bool IsEffectActive(::ImageSpaceManager__ImageSpaceEffectEnum);
};
struct FUN_00874b50_shell : public Main
{
    void FUN_00874b50(BSRenderedTexture*, bool, unsigned int);
};

struct NiRenderTargetGroup;
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup(void);
public:
    static void EndAllAndResetRendererState();
};

void* __cdecl FUN_004a0e90(void);

// @fnv 0x00874b50
void FUN_00874b50_shell::FUN_00874b50(BSRenderedTexture* apRenderTexture, bool abMultiSampleEnabled,
                                      unsigned int auiClearMode)
{
    if (FUN_004e9510())
    {
        ImageSpaceManager* apImagespaceManager = ::ImageSpaceManager::FUN_004e3270();
        void* apRenderer = FUN_004a0e90();
        ::FUN_00b6b8d0(auiClearMode, apRenderTexture->GetGroup());
    }
}

namespace fnv_00874b90 {
struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void CreateMenuBackgroundGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
struct FUN_00874b90_shell : public Main
{
    void FUN_00874b90(ImageSpaceManager*, GraphicsRenderer*, bool, BSRenderedTexture*);
};

struct StrG
{
    operator const char*() const;
};
enum BSRENDERSTATE_LOCK
{
    BSRS_LOCK_DUMMY
};
struct BSRenderStateManager
{
};
struct ISMStub
{
};
// @fnv 0x00874b90
void FUN_00874b90_shell::FUN_00874b90(ImageSpaceManager* pManager, GraphicsRenderer* r, bool c, BSRenderedTexture* d)
{
    if ((const char*)(*reinterpret_cast<::fnv_00874b90::StrG *>(&::g_011ded3c)))
    {
        ::BSRenderStateManager::SetColorWriteMask(7, (*(::BSRENDERSTATE_LOCK *)&(const ::fnv_00874b90::BSRENDERSTATE_LOCK &)((BSRENDERSTATE_LOCK)1)));
        ::BSRenderStateManager::SetDepthBufferEnabled(false, (*(::BSRENDERSTATE_LOCK *)&(const ::fnv_00874b90::BSRENDERSTATE_LOCK &)((BSRENDERSTATE_LOCK)1)));
        reinterpret_cast<::BB97550Shader *>((((ISMStub*)pManager)))->FUN_00b97550(0x22, (std::intptr_t)(r), (intptr_t)((const char*)(*reinterpret_cast<::fnv_00874b90::StrG *>(&::g_011ded3c))), c ? 0u : (uintptr_t)d, 0, 1);
        ::FUN_00714ae0(1);
        ::FUN_004eced0(1);
    }
}
}  // namespace fnv_00874b90

struct _Fake_FUN_008750e0
{
    char pad[0x1e4];
    NiPoint3 kIntersectionOffset;
    void FUN_008750e0(NiPoint3 a_kOffset);
};

// Stores the given NiPoint3 offset into the object's point field.
// @fnv 0x008750e0
void _Fake_FUN_008750e0::FUN_008750e0(NiPoint3 a_kOffset)
{
    kIntersectionOffset = a_kOffset;
}

namespace fnv_00876d20 {
class StartMenu
{
  public:
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};

class GlobalObject2_0040c150
{
  public:
};



// @fnv 0x00876d20
void __cdecl FUN_00876d20()
{
    ::FUN_00af43a0(*(*reinterpret_cast<::fnv_00876d20::ProcessLists *>(&::g_011dee3c)).GetLifeStateControlFlag(), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00876d20::StartMenu *>(&::g_011c4030))))->GetMenuTitle()))), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00876d20::StartMenu *>(&::g_011deb94))))->GetMenuTitle()))), 0x200000);
    ::FUN_00af4460(*(*reinterpret_cast<::fnv_00876d20::ProcessLists *>(&::g_011debdc)).GetLifeStateControlFlag());
    ::FUN_00af4470(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00876d20::GlobalObject2_0040c150 *>(&::g_011deb24)))))), *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00876d20::GlobalObject2_0040c150 *>(&::g_011deaa0)))))), *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00876d20::GlobalObject2_0040c150 *>(&::g_011dec40)))))));
    ::FUN_00af4490(*(*reinterpret_cast<::fnv_00876d20::ProcessLists *>(&::g_011dec4c)).GetLifeStateControlFlag(), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00876d20::StartMenu *>(&::g_011dec68))))->GetMenuTitle())));
    ::fnv_00af4550::FUN_00af4550();
}
}  // namespace fnv_00876d20

namespace fnv_00877430 {
struct FUN_00877430_shell : public Main
{
    void FUN_00877430();
};

struct StrG
{
    operator const char*() const;
};
struct BSRenderedTexture;
struct BSTextureManager
{
};
struct ImageSpaceManager
{
};
BSTextureManager* FUN_004a0ea0(const char*);
// @fnv 0x00877430
void FUN_00877430_shell::FUN_00877430()
{
    if ((const char*)(*reinterpret_cast<::fnv_00877430::StrG *>(&::g_011ded3c)))
    {
        reinterpret_cast<::Manager *>((FUN_004a0ea0((const char*)(*reinterpret_cast<::fnv_00877430::StrG *>(&::g_011ded3c)))))->FUN_00b6da10({});
        *(NiPointer<NiNode>*)&(*reinterpret_cast<::fnv_00877430::StrG *>(&::g_011ded3c)) = (NiNode*)0;
        reinterpret_cast<::FUN_007123f0_shell *>((((::fnv_00877430::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_007123f0(0.0f);
        reinterpret_cast<::S4 *>((((::fnv_00877430::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_007123a0(0);
    }
    ::DAT_011dea29 = false;
}
}  // namespace fnv_00877430

struct Controls;
struct FUN_00877720_shell : public Main
{
    Controls* FUN_00877720();
};


// @fnv 0x00877720
Controls* FUN_00877720_shell::FUN_00877720()
{
    return ((::Controls *)(::FUN_007fdf30()));
}

struct FUN_00936aa0_shell
{
    char pad[0x85];
    bool f;
    void FUN_00936aa0(bool b);
};
// @fnv 0x00936aa0
void FUN_00936aa0_shell::FUN_00936aa0(bool abValue)
{
    f = abValue;
}

struct Dummy_00a239e0
{
    int FUN_00a239e0(int a2);
    unsigned int pad00[0x6c9];
    int unk1b24;
    int unk1b28;
    int unk1b2c;
};

// Returns the int stored at offset 0x1B24, 0x1B28 or 0x1B2C of this object depending on a2 (1, 2 or 3), otherwise 0.
// @fnv 0x00a239e0
int Dummy_00a239e0::FUN_00a239e0(int aiIndex)
{
    switch (aiIndex)
    {
    case 1:
        return this->unk1b24;
    case 2:
        return this->unk1b28;
    case 3:
        return this->unk1b2c;
    default:
        return 0;
    }
}

namespace fnv_0086fbe0 {
struct TES
{
    bool FUN_00451530();
};
struct TopicH
{
};
struct BGSCameraPath
{
};
struct RefrHelper
{
};
struct PC7d;
struct MainStandIn
{
    char pad[7];
    bool flag7;
    void FUN_0086fbe0();
};
// @fnv 0x0086fbe0
void MainStandIn::FUN_0086fbe0()
{
    if (!::DAT_011dea2b && !::DAT_011d8907 && !flag7)
    {
        reinterpret_cast<::TES *>(((*reinterpret_cast<::fnv_0086fbe0::TES * *>(&::g_TES))))->FindCellAtPosition(((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((((TopicH*)(*reinterpret_cast<::fnv_0086fbe0::PC7d * *>(&::_g_thePlayer)))))->GetAddTopicList())), true);
        if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(((*reinterpret_cast<::fnv_0086fbe0::TES * *>(&::g_TES))))->FUN_00451530() && !((::fnv_0086fbe0::BGSCameraPath *)(reinterpret_cast<::BGSCameraPath *>((((BGSCameraPath*)(*reinterpret_cast<::fnv_0086fbe0::TES * *>(&::g_TES)))))->GetPrevPath())))
        {
            if (((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((RefrHelper*)(*reinterpret_cast<::fnv_0086fbe0::PC7d * *>(&::_g_thePlayer)))))->FUN_00575d70())) == ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_0086fbe0::TES * *>(&::g_TES))))->GetHitSound())))
            {
            }
        }
    }
}
}  // namespace fnv_0086fbe0

struct Flt
{
    operator unsigned int() const;
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct Obj008731d0
{
    char pad0[8];
    Helper62d0 h;
    char pad1[0x20 - 9];
    void* f;
    void FUN_008731d0();
};
// If the pointer field f is non-null, assigns it to the helper member h.
// @fnv 0x008731d0
void Obj008731d0::FUN_008731d0()
{
    if (*(Flt*)&f)
        h = f;
}

namespace fnv_008749b0 {
struct NiRenderer;
struct BSRenderedTexture;
struct BSTextureManager
{
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct Flt
{
    operator unsigned int() const;
};
struct KFModel
{
};
struct VATSEffect
{
    bool FUN_00874aa0();
};
struct Interface
{
};
BSTextureManager* FUN_004a0ea0();

// @fnv 0x008749b0
bool FUN_008749b0(void* self)
{
    bool bissuedVATSQuery = false;
    if (((void *)(reinterpret_cast<::TESRegionDataMap *>((((KFModel*)((::fnv_008749b0::VATSEffect *)(::fnv_00705910::FUN_00705910())))))->GetRegionMapName())))
    {
        if (!(unsigned int)*(Flt*)&(*reinterpret_cast<::fnv_008749b0::NP_0081c630 *>(&::g_011deb38)))
        {
            (*reinterpret_cast<::fnv_008749b0::NP_0081c630 *>(&::g_011deb38)) = ((::fnv_008749b0::BSRenderedTexture *)(reinterpret_cast<::Pool *>((FUN_004a0ea0()))->FUN_00b6e110((std::uintptr_t)(((::fnv_008749b0::NiRenderer *)(::FUN_0043c4b0()))), 0x2f, 0, (unsigned int)(0), 0)));
        }
        if (!(unsigned int)*(Flt*)((::fnv_008749b0::VATSEffect *)(::fnv_00705910::FUN_00705910())) && (unsigned int)*(Flt*)&(*reinterpret_cast<::fnv_008749b0::NP_0081c630 *>(&::g_011deb38)) &&
            ((void *)(reinterpret_cast<::TESRegionDataMap *>((((KFModel*)((::fnv_008749b0::VATSEffect *)(::fnv_00705910::FUN_00705910())))))->GetRegionMapName())) &&
            ((::fnv_008749b0::VATSEffect *)(::fnv_00705910::FUN_00705910()))->FUN_00874aa0())
        {
            reinterpret_cast<::VATSRender *>((((::fnv_008749b0::VATSEffect *)(::fnv_00705910::FUN_00705910()))))->FUN_00800f30((::RenderTexture *)((uintptr_t)*(Flt*)&(*reinterpret_cast<::fnv_008749b0::NP_0081c630 *>(&::g_011deb38))), 0, 1, 0, 7, 0);
            reinterpret_cast<::VATSRender *>((((::fnv_008749b0::VATSEffect *)(::fnv_00705910::FUN_00705910()))))->FUN_00800f30((::RenderTexture *)((uintptr_t)*(Flt*)&(*reinterpret_cast<::fnv_008749b0::NP_0081c630 *>(&::g_011deb38))), 1, 1, 0, 1, 1);
            bissuedVATSQuery = true;
        }
    }
    return bissuedVATSQuery;
}
}  // namespace fnv_008749b0

struct Arr
{
    unsigned int GetSize(void);
    unsigned int* GetAt(int);
};

struct SomeClass
{
    int m_ucUnknownByte[0xad4 / 4];
    Arr m_aiIndexedValues;
    int FUN_0086bb70(unsigned int value);
};

// @fnv 0x0086bb70
int SomeClass::FUN_0086bb70(unsigned int value)
{
    for (int i = 0; i < reinterpret_cast<::FUN_00658930_class *>(&(m_aiIndexedValues))->GetShortAtOffsetA(); i++)
    {
        if (*m_aiIndexedValues.GetAt(i) == value)
            return i;
    }
    return -1;
}


// @fnv 0x0086bcc0
void FUN_0086bcc0(unsigned char value)
{
    ::DAT_011f4448 = value;
}

void* DAT_011f6e08;

// @fnv 0x0086bcd0
void FUN_0086bcd0(void* obj)
{
    DAT_011f6e08 = obj;
}

extern int DAT_011f6224;

// @fnv 0x0086bd90
void FUN_0086bd90(int value)
{
    DAT_011f6224 = value;
}

struct GlobalObject_0083b5e0
{
    void RemoveAll();
};


// @fnv 0x0086bdd0
void FUN_0086bdd0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(&(::g_011dd948))->FUN_00438af0();
}

extern double(__cdecl* DAT_011f9134)(void*);

// @fnv 0x0086bde0
void FUN_0086bde0(double(__cdecl* value)(void*))
{
    DAT_011f9134 = value;
}


// @fnv 0x0086be80
void FUN_0086be80(int value)
{
    DAT_011d5c44 = value;
}

extern NiNode* DAT_011d59ec;

// @fnv 0x0086be90
void FUN_0086be90(NiNode* value)
{
    DAT_011d59ec = value;
}

extern bool DAT_011a31f4;

// @fnv 0x0086bea0
void FUN_0086bea0(bool value)
{
    DAT_011a31f4 = value;
}

struct GlobalObject_00633c90
{
    GlobalObject_00633c90& operator=(void*);
};


// Clears the three global objects by assigning null to g_011d86bc, g_011d86a8 and g_011d8690.
// @fnv 0x0086beb0
void FUN_0086beb0()
{
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d86bc)) = 0;
    ::g_011d86a8 = 0;
    ::g_011d8690 = 0;
}

struct FUN_0086bf40
{
    void* DeleteThis(unsigned int flags);
};

// Calls FUN_0086c880, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0086bf40
void* FUN_0086bf40::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::fnv_0086c880::FUN_0086c880 *>(this)->fnv_0086c880::FUN_0086c880::~FUN_0086c880();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


// @fnv 0x0086d470
int __cdecl FUN_0086d470()
{
    return DAT_011dea18;
}

extern int DAT_01202e98;

// @fnv 0x0086d480
int* __cdecl FUN_0086d480()
{
    return &DAT_01202e98;
}

namespace fnv_0086d580 {

// @fnv 0x0086d580
int* __cdecl FUN_0086d580()
{
    return &(*reinterpret_cast<int *>(&::DAT_011c6fc8));
}
}  // namespace fnv_0086d580

class NiAVObject;

// @fnv 0x0086e4d0
void FUN_0086e4d0(unsigned int(__cdecl* apObjectTypeFunc)(NiAVObject*))
{
    DAT_011f91ec = apObjectTypeFunc;
}

extern bool DAT_011f91de;

// @fnv 0x0086e500
void FUN_0086e500(bool abSeparateAmbientLight)
{
    DAT_011f91de = abSeparateAmbientLight;
}


// @fnv 0x0086e510
void FUN_0086e510(unsigned char value)
{
    (*reinterpret_cast<unsigned char *>(&::DAT_011f91dd)) = value;
}


// @fnv 0x0086e620
void FUN_0086e620(void* apLODTreeParent)
{
    (*reinterpret_cast<void **>(&::g_pkB58070Root)) = apLODTreeParent;
}


// @fnv 0x0086ef30
void FUN_0086ef30()
{
    DAT_012677a2 = 0;
}


// @fnv 0x0086ef60
unsigned char FUN_0086ef60()
{
    return DAT_011f4461;
}


// @fnv 0x0086ef90
void FUN_0086ef90()
{
    DAT_01267c1c = 0.0f;
}

namespace fnv_0086efe0 {
struct SettingFloat
{
};
struct TESWorldSpace
{
    enum PARENT_USE_FLAG
    {
        USE_LAND = 1
    };
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG flag);
};
struct TES
{
};
struct ActorS
{
};
struct PC7d : ActorS
{
};

struct FUN_0086efe0_t
{
    void FUN_0086efe0();
};

// @fnv 0x0086efe0
void FUN_0086efe0_t::FUN_0086efe0()
{
    if (((bool)(::FUN_00525420())))
    {
        ::FUN_0086f160(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011dec24)))))));
        ::FUN_0086f170(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011deb10)))))));
        ::FUN_0086f180(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011ded8c)))))));
    }
    else if (((::fnv_0086efe0::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_0086efe0::TES * *>(&::g_TES))))->GetHitSound())) && ((::fnv_0086efe0::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_0086efe0::TES * *>(&::g_TES))))->GetHitSound()))->GetParentWorld(TESWorldSpace::USE_LAND))
    {
        ::FUN_0086f160(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011dec7c)))))));
        ::FUN_0086f170(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011dee54)))))));
        ::FUN_0086f180(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011ded98)))))));
    }
    else if ((*reinterpret_cast<::fnv_0086efe0::PC7d * *>(&::_g_thePlayer)) && ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_0086efe0::PC7d * *>(&::_g_thePlayer))))->GetTarget())) && reinterpret_cast<::TESObjectCELL *>((((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_0086efe0::PC7d * *>(&::_g_thePlayer))))->GetTarget()))))->IsCellInterior())
    {
        ::FUN_0086f160(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011dea80)))))));
        ::FUN_0086f170(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011deddc)))))));
        ::FUN_0086f180(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086efe0::SettingFloat *>(&::g_011decc8)))))));
    }
    else
    {
        ::FUN_0086f160(1.0f);
        ::FUN_0086f170(1.0f);
        ::FUN_0086f180(1.0f);
    }
}
}  // namespace fnv_0086efe0

extern float DAT_011ad804;

// @fnv 0x0086f160
void FUN_0086f160(float value)
{
    DAT_011ad804 = value;
}

extern float DAT_011ad800;

// @fnv 0x0086f170
void FUN_0086f170(float value)
{
    DAT_011ad800 = value;
}

extern float DAT_011ad7fc;

// @fnv 0x0086f180
void FUN_0086f180(float value)
{
    DAT_011ad7fc = value;
}

extern float DAT_011c40ec;

// @fnv 0x0086f830
void FUN_0086f830(float value)
{
    DAT_011c40ec = value;
}


// @fnv 0x0086fba0
void FUN_0086fba0(unsigned char value)
{
    (*reinterpret_cast<unsigned char *>(&::DAT_011dcfa6)) = value;
}

class BGSAcousticSpace;
extern BGSAcousticSpace* DAT_011dcfb8;

// @fnv 0x0086fbb0
void FUN_0086fbb0(BGSAcousticSpace* value)
{
    DAT_011dcfb8 = value;
}

namespace fnv_0086fc60 {
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
struct FUN_0086fc60_shell : public Main
{
    void FUN_0086fc60();
};

struct GlobalObject2_0040c150
{
};
struct Twin_0084d030
{
};
struct ProcessListsH
{
};
struct NiUpdateDataH
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
};
class TES
{
  public:
};
struct SceneGraphH
{
};
// @fnv 0x0086fc60
void FUN_0086fc60_shell::FUN_0086fc60()
{
    NiUpdateDataH UpdateData;
    if ((!::DAT_011dea2b || ::FrameUpdate::DAT_011dea2c || ::DAT_011dea2d) && !*((bool*)this + 7))
    {
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086fc60::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
        {
            reinterpret_cast<::EffectProcessLists *>(&((*reinterpret_cast<::fnv_0086fc60::ProcessListsH *>(&::g_011e0e80))))->FUN_009746c0(::fnv::timer::Seconds());
        }
        else
        {
            reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::fnv_0086fc60::ProcessListsH *>(&::g_011e0e80))))->UpdateInterfaceTempEffects(::fnv::timer::Seconds());
        }
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086fc60::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) == 1 && !::DAT_011dea2b)
        {
            reinterpret_cast<::Zt5TES *>(((*reinterpret_cast<::fnv_0086fc60::TES * *>(&::g_TES))))->FUN_00453550(::DAT_011dea30);
        }
        else
        {
            reinterpret_cast<::Zt5TES *>(((*reinterpret_cast<::fnv_0086fc60::TES * *>(&::g_TES))))->FUN_004537c0();
        }
        new ((void *)&(UpdateData)) ::NiUpdateData(::DAT_011dea30, true, false);
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086fc60::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
        {
            reinterpret_cast<::ProcessOwner_j61 *>((((::fnv_0086fc60::SceneGraphH *)(::FUN_0045a190()))))->FUN_00c50610(&UpdateData);
        }
        else
        {
            reinterpret_cast<::ProcessOwner_j61 *>((((::fnv_0086fc60::SceneGraphH *)(::FUN_0045a190()))))->FUN_00c50610(&UpdateData);
        }
    }
}
}  // namespace fnv_0086fc60

extern unsigned char DAT_0118abb0;

// @fnv 0x0086ff40
unsigned char __cdecl FUN_0086ff40()
{
    return DAT_0118abb0;
}

extern char DAT_01189184;

// @fnv 0x008705c0
char __cdecl FUN_008705c0()
{
    return DAT_01189184;
}


// @fnv 0x008709f0
unsigned char FUN_008709f0()
{
    return DAT_011f91a4;
}

struct HWND__;
struct Controls
{
};
struct InterfaceH
{
    static bool GetSelectedTargetIndex(int menu);
};
void __cdecl FUN_00706230(int x, int y);

struct FUN_00871d10_t
{
    bool FUN_00871d10(int x, int y);
    unsigned int pad00[0x2];
    void* unk08;
};

// @fnv 0x00871d10
bool FUN_00871d10_t::FUN_00871d10(int x, int y)
{
    if (GetActiveWindow() != *(HWND__**)&this->unk08)
        return false;
    if (!::FUN_00702360() || !((int)(reinterpret_cast<::FUN_00711e00_StandIn *>((((::Controls *)(::FUN_007fdf30()))))->FUN_00711e00())))
        return false;
    if (!InterfaceH::GetSelectedTargetIndex(0x41e))
        ::fnv_00703080::FUN_00703080((float)(x / (double)((int)(::FUN_004dc1f0()))), (float)(y / (double)FUN_004dc200()));
    else
        FUN_00706230(x, y);
    return true;
}

namespace fnv_008727d0 {
struct FUN_008727d0_shell : public Main
{
    void FUN_008727d0();
};

struct BSFaceGenAnimationData;
struct ShadowSceneNode
{
};
struct NiAdditionalGeometryData
{
};
struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct MobileObjectCellAccess
{
};
struct WaterZoneManager
{
    int m_uiPathPointIndex;
};
struct TES
{
};
struct FUN_004e2120_s
{
    void f(bool);
};
struct FUN_004e2190_shell
{
    FUN_004e2120_s* FUN_004e2190();
};
struct MTRenderingSystem_Helper
{
};
struct TaskThreadManager : MTRenderingSystem_Helper
{
};

// @fnv 0x008727d0
void FUN_008727d0_shell::FUN_008727d0()
{
    if (*(*reinterpret_cast<::fnv_008727d0::ProcessLists *>(&::g_011c7adc)).GetLifeStateControlFlag())
    {
        int isavemaxaniso = ::DAT_011a9608;
        ::DAT_011a9608 = 1;
        if (!::fnv_005468f0::FUN_005468f0(11) &&
            (!((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_008727d0::TES * *>(&::g_TES))))->GetPrevPath())) || reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(((MobileObjectCellAccess*)((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_008727d0::TES * *>(&::g_TES))))->GetPrevPath())))))->FUN_004518e0()))
        {
            ShadowSceneNode* pscene = ((::fnv_008727d0::ShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
            bool bwasLightUpdateDisabled = ((bool)(reinterpret_cast<::FUN_005f9ad0_shell *>((pscene))->FUN_005f9ad0()));
            reinterpret_cast<::FUN_005f9af0_shell *>((pscene))->SetCreatureType(1);
            reinterpret_cast<::WaterUpdate *>((((::fnv_008727d0::WaterZoneManager *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_008727d0::TES * *>(&::g_TES))))))))->FUN_004e1bc0((::WaterCamera *)(::fnv_008727d0::BSFaceGenAnimationData *)(((::fnv_008727d0::BSFaceGenAnimationData *)(::FUN_00524c90()))), pscene);
            reinterpret_cast<::FUN_005f9af0_shell *>((pscene))->SetCreatureType(bwasLightUpdateDisabled);
        }
        else
        {
            ::DAT_011ff104 = false;
            ((::fnv_008727d0::WaterZoneManager *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_008727d0::TES * *>(&::g_TES))))))->m_uiPathPointIndex = 0;
            reinterpret_cast<::FUN_004e2120_s *>((((::fnv_008727d0::FUN_004e2120_s *)(reinterpret_cast<::FUN_004e2190_shell *>(((*reinterpret_cast<::fnv_008727d0::FUN_004e2190_shell * *>(&::g_osGlobals))))->FUN_004e2190()))))->f(false);
            DAT_011ff8c4 = false;
            ::FUN_00872930(0);
        }
        ::DAT_011a9608 = isavemaxaniso;
    }
    for (int i = ((::fnv_008727d0::WaterZoneManager *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_008727d0::TES * *>(&::g_TES))))))->m_uiPathPointIndex + 1; i < 17; i++)
    {
        reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_008727d0::TaskThreadManager *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, i);
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_008727d0::TaskThreadManager *)(::TaskThreadManager::GetSingleton()))), (void *)(1), i, {});
    }
}
}  // namespace fnv_008727d0


// @fnv 0x00872930
void FUN_00872930(unsigned char value)
{
    DAT_011c7a59 = value;
}

extern bool DAT_011f9fc3;
extern bool DAT_011f9fc4;

// @fnv 0x00872dd0
void __cdecl FUN_00872dd0(bool abFlag1, bool abFlag2)
{
    DAT_011f9fc3 = abFlag1;
    DAT_011f9fc4 = abFlag2;
}

struct GlobalObjectO2_00a7b610
{
};

class BSFadeNodeCuller
{
  public:
    GlobalObjectO2_00a7b610* FUN_00872ef0();
};

// @fnv 0x00872ef0
GlobalObjectO2_00a7b610* BSFadeNodeCuller::FUN_00872ef0()
{
    return &::g_01201f7c;
}

namespace fnv_00872f00 {
struct BSFadeNodeCuller
{
    void FUN_00872f30();
    void* FUN_00872f00(unsigned int flags);
};


// Calls FUN_00872f30, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00872f00
void* BSFadeNodeCuller::FUN_00872f00(unsigned int flags)
{
    FUN_00872f30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00872f00

struct FUN_00874650Class
{
    char FUN_00874650();
    char pad00[0x1dc];
    char unk1dc;
    char pad1dd[0x3];
};

// @fnv 0x00874650
char FUN_00874650Class::FUN_00874650()
{
    return this->unk1dc;
}

namespace fnv_00874690 {
class GlobalObject_00633c90
{
  public:
    void* operator->() const;
};

GlobalObject_00633c90 g_011c7840;

// @fnv 0x00874690
void FUN_00874690()
{
    (*reinterpret_cast<::fnv_00874690::GlobalObject_00633c90 *>(&::g_011c7840)).operator->();
}
}  // namespace fnv_00874690

namespace fnv_008746b0 {
struct GlobalObject_00633c90
{
    operator unsigned int() const;
    int* operator->() const;
};


// @fnv 0x008746b0
int* FUN_008746b0()
{
    return (*reinterpret_cast<::fnv_008746b0::GlobalObject_00633c90 *>(&::g_011c781c)).operator->();
}
}  // namespace fnv_008746b0

extern int DAT_011ff0f0;

// @fnv 0x008746c0
void FUN_008746c0()
{
    DAT_011ff0f0 = 0;
}

struct BSTextureManager
{
    enum RenderTargetType
    {
    };
};

struct BSRenderedTexture;

struct ImageSpaceTexture
{
    void FUN_008748d0();
    char pad00[0x7c];
    unsigned int unk7c;
};

// @fnv 0x008748d0
void ImageSpaceTexture::FUN_008748d0()
{
    reinterpret_cast<::H_00ba3840 *>(&this->unk7c)->FUN_00ba3840((*(int *)&(const ::BSTextureManager::RenderTargetType &)((BSTextureManager::RenderTargetType)0x27)));
    reinterpret_cast<::FUN_00ba3770_struct *>(&this->unk7c)->FUN_00ba3770();
}

using AutoMemHelper = ::AutoMemContext;
struct BSRenderedTexture;
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
class BSRenderedTexture;
class NiCamera;
struct BSShaderAccumulator
{
public:
    void SetupDepth(::NiCamera *, ::NiCamera *, ::BSRenderedTexture *);
};

struct FUN_00874920_t
{
    void FUN_00874920(BSShaderAccumulator* apShaderAccum, BSRenderedTexture* apRenderTexture);
};

// Gets the face-gen scene node and passes its animation data with the render texture to the shader accumulator.
// @fnv 0x00874920
void FUN_00874920_t::FUN_00874920(BSShaderAccumulator* apShaderAccum, BSRenderedTexture* apRenderTexture)
{
    BSFaceGenNiNode* pscene;
    AutoMemHelper tempMemContext(0x27, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x20d5);
    pscene = ((::BSFaceGenNiNode *)(::FUN_0045c670()));
    reinterpret_cast<::fnv_00b64570::DepthAccumulator *>((apShaderAccum))->FUN_00b64570((::NiCamera *)(void *)(pscene->GetAnimationData()), (::fnv_00b64570::TextureView *)(apRenderTexture));
}

struct FUN_00a235d0_class
{
    int FUN_00a235d0(int a1, int a2);
};

// @fnv 0x00a235d0
int FUN_00a235d0_class::FUN_00a235d0(int a1, int a2)
{
    return 1;
}

struct FUN_00a236b0_Class
{
    int FUN_00a236b0(int index);
};

// @fnv 0x00a236b0
int FUN_00a236b0_Class::FUN_00a236b0(int index)
{
    return *(int*)(this + 0x1764 + index * 0x2c);
}

struct FUN_0086ba60_Class
{
    bool FUN_0086ba60(void* a1, void* a2);
    unsigned int pad00[0x80];
    void* unk200;
};

// Returns true if the pointer stored at offset 0x200 of this object equals a2.
// @fnv 0x0086ba60
bool FUN_0086ba60_Class::FUN_0086ba60(void* apUnused, void* a2)
{
    if (this->unk200 == a2)
        return true;
    return false;
}

namespace fnv_0086bb20 {
struct SomeClass
{
    bool FUN_0086bb20(uintptr_t index);
    char pad00[0xad4];
    ::PtrArrayView unkad4;
    char padad5[0xf];
    ::PtrArrayView unkae4;
};

// Looks up index via FUN_0086bb70; if found, removes that entry from the lists unkad4 and unkae4 and returns true, else false.
// @fnv 0x0086bb20
bool SomeClass::FUN_0086bb20(uintptr_t index)
{
    int result = reinterpret_cast<::SomeClass *>(this)->FUN_0086bb70(index);
    if (result == -1)
        return false;
    unkad4.FUN_009e98d0(result);
    unkae4.FUN_009e98d0(result);
    return true;
}
}  // namespace fnv_0086bb20

struct TESGrass
{
    unsigned char GetMinimumSlopeDegrees(void);
};

struct BSSystemUtility
{
    static BSSystemUtility* ms_pSystemUtility;
public:
    static void GetRandomGenerator();
};

// @fnv 0x0086bdf0
char FUN_0086bdf0()
{
    int result;
    if (BSSystemUtility::ms_pSystemUtility && ((TESGrass*)BSSystemUtility::ms_pSystemUtility)->GetMinimumSlopeDegrees())
        result = 1;
    else
        result = 0;
    return (char)result;
}

// Returns the smaller of the two arguments, comparing the float against the double and returning it as a double.
// @fnv 0x008731a0
double FUN_008731a0(double adValue, float afValue)
{
    double d;
    if (afValue > adValue)
        d = adValue;
    else
        d = afValue;
    return d;
}

namespace fnv_008746a0 {
struct Flt
{
    operator unsigned int(void);
};


// @fnv 0x008746a0
void FUN_008746a0()
{
    (*reinterpret_cast<::fnv_008746a0::Flt *>(&::g_011c7810)).operator unsigned int();
}
}  // namespace fnv_008746a0

struct FUN_00874aa0_Class
{
    char FUN_00874aa0();
    char pad00[0x118];
    char unk118;
    char pad119[0x3];
};

// @fnv 0x00874aa0
char FUN_00874aa0_Class::FUN_00874aa0()
{
    return this->unk118;
}

struct FUN_008776e0
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    void SetFlags();
};

// @fnv 0x008776e0
void FUN_008776e0::SetFlags()
{
    b2 = 0;
    b5 = 0;
}

struct SoundPlaybackHandle
{
    bool StopWithFade(unsigned int);
    bool FUN_00877700();
    char pad00[0x77c];
    unsigned int unk77c;
};

// @fnv 0x00877700
bool SoundPlaybackHandle::FUN_00877700()
{
    return reinterpret_cast<SoundPlaybackHandle*>(&unk77c)->StopWithFade(0x3e8);
}

struct FUN_0086ef70_Class
{
    char FUN_0086ef70();
    char pad00[0x52];
    char unk52;
    char pad53[0x1];
};

// @fnv 0x0086ef70
char FUN_0086ef70_Class::FUN_0086ef70()
{
    return this->unk52;
}

struct FUN_0086fbc0_Class
{
    char m_05f9;
    void FUN_0086fbc0(char value);
    char pad01[0x5f8];
    char unk5f9;
    char pad5fa[0x2];
};

// @fnv 0x0086fbc0
void FUN_0086fbc0_Class::FUN_0086fbc0(char value)
{
    this->unk5f9 = value;
}

struct FUN_008727b0_Class
{
    char FUN_008727b0() const;
    unsigned int pad00[0x8];
    int unk20;
};
// @fnv 0x008727b0
char FUN_008727b0_Class::FUN_008727b0() const
{
    return *(int*)&this->unk20 != 0;
}

extern "C" void __cdecl FUN_00a693e0();

struct FUN_00872f30_class
{
    void FUN_00a693e0();
    void FUN_00872f30();
};

// @fnv 0x00872f30
void FUN_00872f30_class::FUN_00872f30()
{
    reinterpret_cast<::FUN_00a693e0_cls *>(this)->FUN_00a693e0();
}

namespace fnv_00875bd0 {
struct Flt
{
    operator unsigned int();
};

struct FUN_00875bd0_Class
{
    void* FUN_00875bd0(int idx);
    unsigned int pad00[0x3d];
    void* unkf4;
};

// @fnv 0x00875bd0
void* FUN_00875bd0_Class::FUN_00875bd0(int aiIndex)
{
    return (&this->unkf4)[aiIndex];
}
}  // namespace fnv_00875bd0

struct FUN_00456630_helper
{
    void FUN_00876810();
public:
    bool FUN_00456610();
};

// @fnv 0x00876810
void FUN_00456630_helper::FUN_00876810()
{
    reinterpret_cast<::FUN_00456630_Class *>(this)->FUN_00456630(0x800);
}

namespace fnv_00876830 {
struct BSRenderedTexture
{
    void FUN_00876830(int, std::intptr_t);
};

// @fnv 0x00876830
void BSRenderedTexture::FUN_00876830(int, std::intptr_t)
{
    ::BSRenderedTexture::EndAllAndResetRendererState();
}
}  // namespace fnv_00876830

struct FUN_00877a50Class
{
    unsigned char _pad_000a[0xa];
    unsigned short m_000a;
    void FUN_00877a50(int param_2);
};

// Calls FUN_00877e10 with m_000a and param_2.
// @fnv 0x00877a50
void FUN_00877a50Class::FUN_00877a50(int param_2)
{
    reinterpret_cast<::FUN_00877e10_Class *>(this)->FUN_00877e10(m_000a, param_2);
}

// The 8-byte entries FUN_00a23490 indexes.
struct FUN_00a23490_Entry
{
    int unk00;
    int unk04;
};

struct FUN_00a23490_Class
{
    int FUN_00a23490(int a, unsigned int b);
    char pad00[0x18b8];
    FUN_00a23490_Entry unk18b8[1];
};

// Returns whether the bit at position b is set in entry a of unk18b8.
// @fnv 0x00a23490
int FUN_00a23490_Class::FUN_00a23490(int aiIndex, unsigned int auiBit)
{
    return (1 << auiBit) & unk18b8[aiIndex].unk00;
}

// The 0x2c-byte records FUN_00a23690 and FUN_00a236d0 index.
struct FUN_00a23690_Record
{
    int unk00;
    int unk04;
    int unk08;
    int pad0c[0x8];
};

struct FUN_00a23690_class
{
    int FUN_00a23690(int index);
    char pad00[0x1760];
    FUN_00a23690_Record unk1760[1];
};

// @fnv 0x00a23690
int FUN_00a23690_class::FUN_00a23690(int index)
{
    return unk1760[index].unk00;
}

struct FUN_00a236d0_class
{
    int FUN_00a236d0(int index);
    char pad00[0x1760];
    FUN_00a23690_Record unk1760[1];
};

// @fnv 0x00a236d0
int FUN_00a236d0_class::FUN_00a236d0(int index)
{
    return unk1760[index].unk08;
}


struct FUN_0086bd40_class
{
    void* FUN_0086bd40(unsigned int flags);
};

// @fnv 0x0086bd40
void* FUN_0086bd40_class::FUN_0086bd40(unsigned int flags)
{
    reinterpret_cast<::FileFinderImpl *>(this)->FileFinderImpl::~FileFinderImpl();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_0086bee0_class
{
    void* FUN_0086bee0(unsigned int flags);
};

// @fnv 0x0086bee0
void* FUN_0086bee0_class::FUN_0086bee0(unsigned int flags)
{
    reinterpret_cast<::FUN_00450770 *>(this)->FUN_00450770::~FUN_00450770();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl FUN_00700650();
struct FUN_0086bf10
{
    void FUN_00700650();
    void* DeleteThis(unsigned int flags);
};
// Calls FUN_00700650, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0086bf10
void* FUN_0086bf10::DeleteThis(unsigned int flags)
{
    reinterpret_cast<::PerfMgr *>(this)->FUN_00700650();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0086f6a0 {
struct ActiveEffect;
struct Actor;
struct ActorCause;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSRenderedTexture;
struct BSShaderNoLightingProperty;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct NiCamera;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct NiTexture;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct ShadowSceneNode;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct Tile;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct FUN_0086f6a0_shell : public Main
{
    void FUN_0086f6a0();
};

template <int N> struct FUN_0086f6a0_vs : FUN_0086f6a0_vs<N - 1>
{
    virtual void vf(int (*)[N + 1]);
};
template <> struct FUN_0086f6a0_vs<0>
{
    virtual void vf0();
};
struct FUN_0086f6a0_mob : FUN_0086f6a0_vs<63>
{
    virtual bool IsSlot64();
};
struct FUN_0086f6a0_act : FUN_0086f6a0_vs<256>
{
    virtual void Slot257(float);
};
struct FOPipboyManager
{
};
struct GlobalObject_0045cfe0
{
};
struct GlobalObject2_0040c150;
struct TaskQueueInterface
{
};
struct FUN_0087a6b0_shell
{
};
struct FUN_0087a6d0_shell
{
};
struct Interface
{
};
struct DialogH
{
};
struct Twin_0084d030
{
};
struct ProcessLists
{
};
struct FUN_0096c970_shell
{
};
struct FUN_00991600_t
{
};
struct GameTimerRecord;

// @fnv 0x0086f6a0
void FUN_0086f6a0_shell::FUN_0086f6a0()
{
    FOPipboyManager* ppipboy;
    FUN_0086f6a0_mob* pmob;
    FUN_0086f6a0_act* pact;
    if (::fnv_007050d0::FUN_007050d0() && !::fnv_00703d50::FUN_00703d50() && !::FUN_0086f860())
    {
        pmob = ((::fnv_0086f6a0::FUN_0086f6a0_mob *)(::FUN_007624d0()));
        if (pmob && pmob->IsSlot64())
        {
            pact = (FUN_0086f6a0_act*)pmob;
            pact->Slot257(0.0f);
        }
    }
    reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::fnv_0086f6a0::ProcessLists *>(&::g_011e0e80))))->UpdateMagicTempEffects(0.0f);
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086f6a0::GlobalObject_0045cfe0 *>(&::g_011c3ea4)))))) > 1)
        reinterpret_cast<::FUN_0096c970_shell *>((((FUN_0096c970_shell*)&(*reinterpret_cast<::fnv_0086f6a0::ProcessLists *>(&::g_011e0e80)))))->FUN_0096c970();
    else
        reinterpret_cast<::fnv_0096c860::FUN_0096c860_shell *>(&((*reinterpret_cast<::fnv_0086f6a0::ProcessLists *>(&::g_011e0e80))))->FUN_0096c860();
    ::FUN_0096c710((::ProcessLists *)(::fnv_0086f6a0::ProcessLists *)(&(*reinterpret_cast<::fnv_0086f6a0::ProcessLists *>(&::g_011e0e80))));
    reinterpret_cast<::PLStub *>(&((*reinterpret_cast<::fnv_0086f6a0::ProcessLists *>(&::g_011e0e80))))->FUN_009781d0(::fnv::timer::Seconds());
    ppipboy = ((::fnv_0086f6a0::FOPipboyManager *)(::fnv_00705990::FUN_00705990()));
    if (::FUN_0086f840((char*)ppipboy))
        reinterpret_cast<::FUN_007fa990_cls *>((ppipboy))->FUN_007fa990();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086f6a0::GlobalObject_0045cfe0 *>(&::g_011c3ea4)))))) > 1)
    {
        ::fnv_0054ae30::FUN_0054ae30();
        reinterpret_cast<::FUN_0087a6d0_shell *>((((FUN_0087a6d0_shell*)((::fnv_0086f6a0::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6d0();
        reinterpret_cast<::FUN_0087a790_class *>((((::fnv_0086f6a0::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087a790();
        ::fnv_00552570::FUN_00552570();
        ::FUN_0086f830(::fnv_00563f30::DAT_011c3c08);
        reinterpret_cast<::FUN_0087a6b0_shell *>((((FUN_0087a6b0_shell*)((::fnv_0086f6a0::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087a6b0();
    }
    ::TaskQueueInterface::ThreadProcessInput(*((int *)&(::FUN_0043d4d0((int *)(((GlobalObject_0045cfe0*)&(*reinterpret_cast<::fnv_0086f6a0::GlobalObject2_0040c150 *>(&::g_011d10d4))))))));
    ::TaskQueueInterface::ThreadProcessSecondaryInput();
    reinterpret_cast<::fnv_00991600::FUN_00991600_shell *>(((*reinterpret_cast<::fnv_0086f6a0::FUN_00991600_t * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00991600(::DAT_011dea2b || ::DAT_011dea2d || *((bool*)this + 7));
}
}  // namespace fnv_0086f6a0

namespace fnv_0086fd90 {
struct FUN_0086fd90_shell : public Main
{
    void FUN_0086fd90(bool);
};

struct Twin_0084d030
{
};
struct GameTimerRecord : Twin_0084d030
{
};
struct ImageSpaceManager
{
    void BeginParamModifiers();
};
struct ISMI_0086fd90
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool IsExpired();
    virtual void Update();
    int iPad4;
    bool bActive;
};
struct Flt
{
    operator unsigned int();
};
struct GO
{
    GO(ISMI_0086fd90*);
    ~GO();
    void* p;
};
struct ISMList_0086fd90
{
    Flt& FUN_006815c0();
};
struct TES
{
};
// @fnv 0x0086fd90
void FUN_0086fd90_shell::FUN_0086fd90(bool abAdvanceTime)
{
    ::FUN_00b8b500((void *)(((::fnv_0086fd90::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))), {});
    reinterpret_cast<::ImageSpaceManager *>((((::fnv_0086fd90::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))))->BeginParamModifiers();
    if (abAdvanceTime)
        ::FUN_0086ff50(::fnv::timer::Seconds());
    ISMList_0086fd90* pModifierList = ((::fnv_0086fd90::ISMList_0086fd90 *)(reinterpret_cast<::TESObjectTREE *>(((*reinterpret_cast<::fnv_0086fd90::TES * *>(&::g_TES))))->GetData()));
    int iActiveCount = 0;
    int iactiveWeatherCount = 0;
    while (pModifierList)
    {
        ISMI_0086fd90* pModifier = (ISMI_0086fd90*)(uintptr_t)(*(::fnv_0086fd90::Flt *)(&reinterpret_cast<::SimpleListNodeView*>(pModifierList)->m_item));
        if (pModifier)
        {
            if (pModifier->bActive)
                ++iActiveCount;
            if (pModifier->IsExpired())
            {
                reinterpret_cast<::ListReader *>((pModifierList))->FUN_00631620((const ::NodeValue &)((const ::fnv_0086fd90::GO &)(pModifier)));
                continue;
            }
            else if (::FUN_0086ff40())
            {
                pModifier->Update();
                if (reinterpret_cast<::Twin_0084d030 *>((((Twin_0084d030*)pModifier)))->GetStoredFloatValue() > 0.0 && pModifier->bActive)
                    ++iactiveWeatherCount;
            }
        }
        pModifierList = ((::fnv_0086fd90::ISMList_0086fd90 *)(reinterpret_cast<::Callees *>((pModifierList))->FUN_00726070()));
        if (iActiveCount == 4)
        {
            if (!iactiveWeatherCount)
                ::FUN_00b8aea0((char *)(((::fnv_0086fd90::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))));
            reinterpret_cast<::DerivedImageSpaceManager *>((((::fnv_0086fd90::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_00b8ccb0();
            iActiveCount = 0;
        }
    }
    reinterpret_cast<::FUN_00b8d020_class *>((((::fnv_0086fd90::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_00b8d020();
    ::FUN_00b8b440((char *)(((::fnv_0086fd90::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()))), false, {});
}
}  // namespace fnv_0086fd90

namespace fnv_008746d0 {
struct BSRenderedTexture;
struct NiStream;
struct RgbaColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, RgbaColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, RgbaColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
    float a;
};
struct FUN_008746d0_shell : public Main
{
    char pad00[0x90];
    ::BSShaderAccumulator* pFirstPersonAccumulator;
    void FUN_008746d0(BSRenderedTexture*);
};

struct NiNode;
struct NiRenderTargetGroup;
struct NiColor;
struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float r, g, b, a;
};
struct NiAVObject
{
};
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup();
};
struct ImageSpaceTexture
{
    BSRenderedTexture* FUN_008748d0();
};
struct S4
{
};
struct FUN_004a0fd0_shell
{
};
struct MiddleLowProcess
{
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct SceneGraph_008746d0
{
};
struct PC_00605d70
{
};
struct FUN_008bbc10_shell
{
};
struct Flt
{
    operator unsigned int();
};
struct BSShaderManager
{
};
struct BSShaderRenderUtility
{
    static void SetRenderCamera(void*, unsigned int, bool);
};
struct BSRenderStateManager
{
};
struct Renderer_008746d0
{
    virtual void rv00();
    virtual void rv01();
    virtual void rv02();
    virtual void rv03();
    virtual void rv04();
    virtual void rv05();
    virtual void rv06();
    virtual void rv07();
    virtual void rv08();
    virtual void rv09();
    virtual void rv10();
    virtual void rv11();
    virtual void rv12();
    virtual void rv13();
    virtual void rv14();
    virtual void rv15();
    virtual void rv16();
    virtual void rv17();
    virtual void rv18();
    virtual void rv19();
    virtual void rv20();
    virtual void rv21();
    virtual void rv22();
    virtual void rv23();
    virtual void rv24();
    virtual void rv25();
    virtual void rv26();
    virtual void rv27();
    virtual void rv28();
    virtual void rv29();
    virtual void rv30();
    virtual void rv31();
    virtual void rv32();
    virtual void rv33();
    virtual void rv34();
    virtual void rv35();
    virtual void rv36();
    virtual void rv37();
    virtual void rv38();
    virtual void rv39();
    virtual void rv40();
    virtual void rv41();
    virtual void rv42();
    virtual void SetBackgroundColor(ImageSpaceEffectParam*);
    virtual void SetBackgroundColorRGB(NiColor*);
    virtual void GetBackgroundColor(ImageSpaceEffectParam*);
};
Renderer_008746d0* __cdecl FUN_004a0e90();
// @fnv 0x008746d0
void FUN_008746d0_shell::FUN_008746d0(BSRenderedTexture* apRenderTexture)
{
    S4* pimagespacemanager = ((::fnv_008746d0::S4 *)(::ImageSpaceManager::FUN_004e3270()));
    Renderer_008746d0* prenderer = FUN_004a0e90();
    NiNode* pscenegraph = ((::fnv_008746d0::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PC_00605d70*)::_g_thePlayer)))->FUN_00950bb0(true)));
    SceneGraph_008746d0* p1stperson3d = ((::fnv_008746d0::SceneGraph_008746d0 *)(::FUN_0045c670()));
    FUN_004a0fd0_shell* pculler = ((::fnv_008746d0::FUN_004a0fd0_shell *)(reinterpret_cast<::SceneGraph *>(p1stperson3d)->cullingProcess));
    bool m_kFieldAfterWeaponFlags = reinterpret_cast<::FUN_008bbc10_shell *>((((FUN_008bbc10_shell*)::_g_thePlayer)))->FUN_008bbc10();
    BSRenderedTexture* p1stpersonBuffer = 0;
    ImageSpaceEffectParam savedBackground(0.0f, 0.0f, 0.0f, 0.0f);
    if (m_kFieldAfterWeaponFlags)
    {
        p1stpersonBuffer = ((::fnv_008746d0::ImageSpaceTexture *)(reinterpret_cast<::FUN_004ebbc0_shell *>((pimagespacemanager))->FUN_004ebbc0(4)))->FUN_008748d0();
        ::BSRenderedTexture::EndAllAndResetRendererState();
        prenderer->GetBackgroundColor(&savedBackground);
        prenderer->SetBackgroundColorRGB(&(*reinterpret_cast<::fnv_008746d0::NiColor *>(&::DAT_011f4998)));
        ::FUN_00b6b8d0(1, (::NiRenderTargetGroup *)(::fnv_008746d0::NiRenderTargetGroup *)(p1stpersonBuffer->GetGroup()));
    }
    else
    {
        ::BSRenderStateManager::SetColorWriteMask(0, (::BSRENDERSTATE_LOCK)(1));
    }
    NiAVObject* p1stPersonNode = (NiAVObject*)pscenegraph;
    bool bwas1stPersonCulled = reinterpret_cast<::FUN_00456630_helper *>((p1stPersonNode))->FUN_00456610();
    reinterpret_cast<::TaskQueueInterface *>((p1stPersonNode))->QueueActorDisarm(false);
    reinterpret_cast<::C52020Obj *>((p1stperson3d))->FUN_00c52020(::FUN_00874900((const char *)(::fnv_008746d0::PC_00605d70 *)((PC_00605d70*)::_g_thePlayer)), 0, (::C52020Obj *)(0), 0);
    ::BSShaderManager::SetFOV(::FUN_00874900((const char *)(::fnv_008746d0::PC_00605d70 *)((PC_00605d70*)::_g_thePlayer)));
    reinterpret_cast<::FUN_004a0fd0_shell *>((pculler))->FUN_004a0fd0((::NiNode *)(pFirstPersonAccumulator));
    ::FUN_00b6bee0(((BSFaceGenNiNode*)p1stperson3d)->GetAnimationData(), p1stPersonNode, (::BSShaderAccumulator *)(pculler));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(void *)(((BSFaceGenNiNode*)p1stperson3d)->GetAnimationData()),
                                           pFirstPersonAccumulator, false);
    reinterpret_cast<::FUN_004a0fd0_shell *>((pculler))->FUN_004a0fd0((::NiNode *)(0));
    reinterpret_cast<::C52020Obj *>((p1stperson3d))->FUN_00c52020(::FUN_00710ab0((::FUN_00710ab0_Class *)(::fnv_008746d0::PC_00605d70 *)((PC_00605d70*)::_g_thePlayer)), 0, (::C52020Obj *)(0), 0);
    ::BSShaderManager::SetFOV(::FUN_00710ab0((::FUN_00710ab0_Class *)(::fnv_008746d0::PC_00605d70 *)((PC_00605d70*)::_g_thePlayer)));
    reinterpret_cast<::TaskQueueInterface *>((p1stPersonNode))->QueueActorDisarm(bwas1stPersonCulled);
    if (m_kFieldAfterWeaponFlags)
    {
        prenderer->SetBackgroundColor(&savedBackground);
        ::BSRenderedTexture::EndAllAndResetRendererState();
    }
    else
    {
        ::FUN_004eced0(1);
    }
}
}  // namespace fnv_008746d0

namespace fnv_00875e40 {
class NiCamera;
class BSRenderedTexture;
using AutoMemHelper = ::AutoMemContext;
struct ArrSI
{
};
struct NiObjectCopyInfo
{
    int a, b, c, d;
    NiObjectCopyInfo(unsigned int flags);
    ~NiObjectCopyInfo();
};
struct FUN_00875e40_Clone
{
    virtual ~FUN_00875e40_Clone();
};
struct FUN_00875e40_Src
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual FUN_00875e40_Clone* Clone(NiObjectCopyInfo& info);
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct FUN_00710ab0_Class;
struct BSShaderManager
{
};
struct BSShaderAccumulator
{
};
struct FUN_00875e40_shell
{
    void FUN_00875e40(BSShaderAccumulator* pAccum, BSRenderedTexture* pTexture);
};

// Clones the scene graph's animation data as a camera, sets FOV and depth via pAccum->SetupDepth, then deletes the cloned camera.
// @fnv 0x00875e40
void FUN_00875e40_shell::FUN_00875e40(BSShaderAccumulator* pAccum, BSRenderedTexture* pTexture)
{
    BSFaceGenNiNode* pkSceneGraph = (BSFaceGenNiNode*)::FUN_0045c670();
    if (reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode != 4)
        reinterpret_cast<::C52020Obj *>((pkSceneGraph))->FUN_00c52020(::FUN_00710ab0((::FUN_00710ab0_Class *)(::fnv_00875e40::FUN_00710ab0_Class *)((FUN_00710ab0_Class*)::_g_thePlayer)), 0, (::C52020Obj *)(void *)(0), 0);
    ::BSShaderManager::SetFOV(::FUN_00710ab0((::FUN_00710ab0_Class *)(::fnv_00875e40::FUN_00710ab0_Class *)((FUN_00710ab0_Class*)::_g_thePlayer)));
    {
        NiObjectCopyInfo kInfo(0x101);
        FUN_00875e40_Clone* pkCamera = ((FUN_00875e40_Src*)pkSceneGraph->GetAnimationData())->Clone(kInfo);
        if (reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode != 4)
            reinterpret_cast<::C52020Obj *>((pkSceneGraph))->FUN_00c52020(::FUN_00874900((const char*)::_g_thePlayer), 0, (::C52020Obj *)(pkCamera), 0);
        AutoMemHelper kMemHelper(0x27, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x234c);
        reinterpret_cast<::BSShaderAccumulator *>((pAccum))->SetupDepth((::NiCamera *)(::fnv_00875e40::NiCamera *)((NiCamera*)pkSceneGraph->GetAnimationData()), (::NiCamera *)(::fnv_00875e40::NiCamera *)((NiCamera*)pkCamera), (::BSRenderedTexture *)(pTexture));
        delete pkCamera;
    }
}
}  // namespace fnv_00875e40

namespace fnv_00875fa0 {
struct BSFaceGenNiNode
{
    void* GetAnimationData(void);
};
struct Param00875fa0
{
};
struct Outer00875fa0
{
    void FUN_00875fa0(Param00875fa0*, void*);
};
// Calls FUN_0045c670 to get a BSFaceGenNiNode, then passes its animation data and b to FUN_00b651e0 on a.
// @fnv 0x00875fa0
void Outer00875fa0::FUN_00875fa0(Param00875fa0* pParam, void* b)
{
    BSFaceGenNiNode* tmp = (BSFaceGenNiNode*)::FUN_0045c670();
    reinterpret_cast<::fnv_00b651e0::Sh651_Batch *>((pParam))->FUN_00b651e0((::fnv_00b651e0::ShCamera *)(void *)(tmp->GetAnimationData()), (::fnv_00b651e0::ShManager *)(b));
}
}  // namespace fnv_00875fa0

namespace fnv_00876850 {
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderType;
struct GeometryDeviceType;
struct ShaderComRelatedType;
struct ComRenderSupportType;
struct ComGraphicsSupportType;
struct COMBaseInterface;
struct GeometryBufferData;
struct VertexBufferBlock;
struct GeometryRelatedType;
struct NiIBBlock;
struct NiDX9BufferManager;
struct NiDX9VertexDeclaration;
struct Direct3DRenderState;
struct NiDX9TextureData;
struct Direct3D9RenderSystem;
struct COMUnknownInterface;
struct RenderableGeometry;
struct ImageSpaceEffectRenderer;
struct Direct3D;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct NiBillboardNode;
struct NiCamera;
struct RgbaColor;
struct NiDirectionalLight;
struct NiNode;
struct NiPick;
struct NiPoint2;
struct NiScreenElements;
struct NiTexture;
struct NiTriShape;
struct GraphicsRenderer;
struct Sky;
struct Sun;
struct Direct3DRendererType;
struct _D3DCAPS9;
struct _D3DDEVICE_CREATION_PARAMETERS;
struct _D3DDISPLAYMODE;
struct _D3DGAMMARAMP;
struct _D3DPRESENT_PARAMETERS_;
struct Direct3DPresentationType;
struct _D3DRASTER_STATUS;
struct Direct3DViewportSupportType;
struct _D3DVIEWPORT9;
struct Direct3DStructure;
struct FourComponentNumericValue;
struct tagRECT;
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void CreateMenuBackgroundGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    char m_kRadialBlurCenter[8];
    char m_kWeatherRadialBlurCenter[8];
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    char m_kRadialBlurOrigin[8];
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
struct FUN_00876850_shell : public Main
{
    void FUN_00876850(BSRenderedTexture*, ImageSpaceManager*, GraphicsRenderer*, Sun*);
    char pad00[0x88];
    Flt unk88;
    char pad89[0xb];
    Flt unk94;
};

struct Dev9
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100(int, int, int, int);
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104(int);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00b65660_s
{
};
struct FUN_00b630c0_s
{
};
void* __cdecl FUN_004a0e90();
struct BSTextureManager
{
};
BSTextureManager* FUN_004a0ea0();
struct FUN_004dc020_Class
{
    Dev9* FUN_004dc020();
};
struct S5;
struct S4
{
};
struct FUN_00876a00_Class
{
};
struct FUN_00642890_Class
{
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct GO
{
    void operator=(void*);
};
struct MiddleLowProcess
{
};
struct ArrSI
{
};
struct FUN_004d61b0
{
    char pad[0x30];
    FUN_004d61b0(HINSTANCE, HWND, unsigned int, const char*, unsigned int, unsigned int, int, int);
};

// @fnv 0x00876850
void FUN_00876850_shell::FUN_00876850(BSRenderedTexture* apRenderTexture, ImageSpaceManager* apImagespaceManager,
                                      GraphicsRenderer* apRenderer, Sun* apSun)
{
    Dev9* pd3ddevice;
    NiCullingProcess* apCuller;
    std::uintptr_t apSceneGraph;
    apSceneGraph = ::FUN_0045c670();
    apCuller = reinterpret_cast<::SceneGraph *>(apSceneGraph)->cullingProcess;
    if (apSun)
        reinterpret_cast<::FUN_00642890_Class *>((((FUN_00642890_Class*)apSun)))->FUN_00642890();
    ::FUN_00ba9420((const ::Source215 *)(void *)(((BSFaceGenNiNode*)apSceneGraph)->GetAnimationData()));
    if (apRenderTexture)
        reinterpret_cast<::Manager *>((FUN_004a0ea0()))->FUN_00b6da10((::Item *)(apRenderTexture));
    reinterpret_cast<::FUN_00b65660_StandIn *>(((FUN_00b65660_s*)(uintptr_t)unk88))->FUN_00b65660();
    reinterpret_cast<::FUN_00b630c0_class *>(((FUN_00b630c0_s*)(uintptr_t)unk94))->FUN_00b630c0();
    ::FUN_00b540b0();
    ::FUN_00b4f510();
    reinterpret_cast<::FUN_00876a00_Class *>((((FUN_00876a00_Class*)((::fnv_00876850::S5 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((((S4*)apImagespaceManager)))->FUN_004ebbc0(4))))))->FUN_00876a00();
    if (::DAT_011f9440)
        ::FUN_00bad4a0();
    pd3ddevice = ((::fnv_00876850::Dev9 *)(reinterpret_cast<::NiDX9RendererView *>(FUN_004a0e90())->m_pkD3DDevice9));
    pd3ddevice->v104(0);
    pd3ddevice->v100(0, 0, 0, 0);
    if (((intptr_t)(::FUN_00683a60())))
        ::FUN_00714900();
    if ((unsigned int)(*reinterpret_cast<::fnv_00876850::Flt *>(&::DAT_011fa008)))
    {
        new FUN_004d61b0(reinterpret_cast<::OSGlobalsView *>(this)->instance, reinterpret_cast<::OSGlobalsView *>(this)->window, (unsigned int)(*reinterpret_cast<::fnv_00876850::Flt *>(&::DAT_011fa008)),
                         "Render Passes", 0x80000000, 0x80000000, 800, 600);
        (GO&)(*reinterpret_cast<::fnv_00876850::Flt *>(&::DAT_011fa008)) = 0;
    }
    ::fnv_00b988e0::FUN_00b988e0();
}
}  // namespace fnv_00876850

namespace fnv_00877260 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
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
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
using ::AutoMemContext;

class GridCell;
class NiNode;
class IOManager;
class TESObjectREFR;
class ThreeByThreeMatrix
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct M3 : public ThreeByThreeMatrix
{
};
struct V3;
class NiAVObject
{
  public:
};
class NiNode
{
  public:
    void Update(const NiUpdateData& kData);
};
struct NiNode_00558310;
struct FUN_0056fa00_S
{
    M3 FUN_0056fa00();
};
class TES
{
  public:
};
struct CP_008c48d0
{
};
struct GlobalObject_0045cfe0
{
};
struct FUN_0054cfd0_S
{
};
struct FUN_00548230_S
{
};
struct FUN_00456520_Class
{
    void FUN_00456520();
};
using AutoMemHelper = ::AutoMemContext;
struct PC_00605d70
{
};
class NiAdditionalGeometryData
{
  public:
};
struct FUN_00b5cbd0_S
{
};
struct FUN_00565730_S
{
};
struct FUN_00440460_S
{
};
struct UpdData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    void NiUpdateData(float, bool, bool);
};
class PlayerVT
{
  public:
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void SetPositionV(::NiPoint3* apPos);
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void SetZRotV(float afZ);
};

// @fnv 0x00877260
void __cdecl FUN_00877260(::NiPoint3 apos)
{
    TESObjectCELL* pcell = (TESObjectCELL*)((reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)::g_TES)))->GetPrevPath()));
    UpdData UpdateData;
    ::NiPoint3 rot = ::NiPoint3::ZERO;
    if (!pcell)
    {
        pcell = *(TESObjectCELL**)((::fnv_00877260::GridCell *)(reinterpret_cast<::TES *>((((TES*)::g_TES)))->FUN_00457050((unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00877260::GlobalObject_0045cfe0 *>(&::g_011c63cc)))))) >> 1, (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00877260::GlobalObject_0045cfe0 *>(&::g_011c63cc)))))) >> 1)));
    }
    if (pcell)
    {
        reinterpret_cast<::fnv_0054cfd0::TESObjectCELL_Ext *>((((FUN_0054cfd0_S*)pcell)))->FUN_0054cfd0((::fnv_0054cfd0::NiPoint3 *)(::NiPoint3 *)(&apos), (::fnv_0054cfd0::NiPoint3 *)(::NiPoint3 *)(&rot));
    }
    (*reinterpret_cast<::fnv_00877260::PlayerVT * *>(&::_g_thePlayer))->SetZRotV(rot.z);
    (*reinterpret_cast<::fnv_00877260::PlayerVT * *>(&::_g_thePlayer))->SetPositionV(&apos);
    if (pcell)
    {
        reinterpret_cast<::CellView *>((((FUN_00548230_S*)pcell)))->FUN_00548230((::RefView *)(::fnv_00877260::TESObjectREFR *)((TESObjectREFR*)(*reinterpret_cast<::fnv_00877260::PlayerVT * *>(&::_g_thePlayer))), false);
        reinterpret_cast<::FUN_00456520_Class *>((((FUN_00456520_Class*)(*reinterpret_cast<::fnv_00877260::IOManager * *>(&::DAT_01202d98)))))->FUN_00456520();
        AutoMemHelper tempMemContext(0x34, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp",
                                     0x2612);
        reinterpret_cast<::FUN_00a5a040_Class *>((((NiAVObject*)((::fnv_00877260::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PC_00605d70*)(*reinterpret_cast<::fnv_00877260::PlayerVT * *>(&::_g_thePlayer)))))->FUN_00950bb0(false))))))->FUN_00a5a040();
        reinterpret_cast<::fnv_00b5cbd0::ShadowSceneNode_Self *>((((FUN_00b5cbd0_S*)((::fnv_00877260::NiAVObject *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))))->FUN_00b5cbd0(((::fnv_00877260::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PC_00605d70*)(*reinterpret_cast<::fnv_00877260::PlayerVT * *>(&::_g_thePlayer)))))->FUN_00950bb0(false))));
    }
    reinterpret_cast<::FUN_00565730_shell *>((((FUN_00565730_S*)(*reinterpret_cast<::fnv_00877260::PlayerVT * *>(&::_g_thePlayer)))))->FUN_00565730();
    reinterpret_cast<::FUN_00440460_S *>((((FUN_00440460_S*)((::fnv_00877260::NiAVObject *)(::FUN_00558310((::NiNode_00558310 *)(::fnv_00877260::NiNode_00558310 *)((NiNode_00558310*)::FUN_0045c670())))))))->FUN_00440460((const ::V3 *)(const ::fnv_00877260::V3 *)((const V3*)&apos));
    reinterpret_cast<::FUN_0043fa80_s *>((((::fnv_00877260::NiAVObject *)(::FUN_00558310((::NiNode_00558310 *)(::fnv_00877260::NiNode_00558310 *)((NiNode_00558310*)::FUN_0045c670()))))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((const ::fnv_00877260::ThreeByThreeMatrix &)(((FUN_0056fa00_S*)(*reinterpret_cast<::fnv_00877260::PlayerVT * *>(&::_g_thePlayer)))->FUN_0056fa00())));
    new ((void *)&(UpdateData)) ::NiUpdateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiNode*)((::fnv_00877260::NiAVObject *)(::FUN_00558310((::NiNode_00558310 *)(::fnv_00877260::NiNode_00558310 *)((NiNode_00558310*)::FUN_0045c670())))))))->FUN_00a59c60((std::intptr_t)&(*(NiUpdateData*)&UpdateData));
}
}  // namespace fnv_00877260

struct GlobalObject_00869b10
{
};

struct FUN_0086bc10_t
{
    char pad[0xaf4];
    GlobalObject_00869b10 a;
    char pad2[0xb04 - 0xaf4 - 1];
    GlobalObject_00869b10 b;
    int FUN_0086bc60(int);
    bool FUN_0086bc10(intptr_t);
};

// Looks up arg via FUN_0086bc60; if found, removes that index from a and b and returns true, otherwise returns false.
// @fnv 0x0086bc10
bool FUN_0086bc10_t::FUN_0086bc10(intptr_t arg)
{
    int idx = FUN_0086bc60(arg);
    if (idx == -1)
        return false;
    reinterpret_cast<::PtrArrayView *>(&(a))->FUN_009e98d0(idx);
    reinterpret_cast<::PtrArrayView *>(&(b))->FUN_009e98d0(idx);
    return true;
}

namespace fnv_0086bc60 {
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};

struct FUN_0086bc60_t
{
    char m_data[0xaf4];
    Arr arr;
    int FUN_0086bc60(int value);
};

// Searches arr for the first element equal to value and returns its index, or -1 if not found.
// @fnv 0x0086bc60
int FUN_0086bc60_t::FUN_0086bc60(int value)
{
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_00658930_class *>(&(arr))->GetShortAtOffsetA(); i++)
    {
        if (*arr.GetAt(i) == value)
            return i;
    }
    return -1;
}
}  // namespace fnv_0086bc60

namespace fnv_00872940 {
struct S148c0
{
};

struct ImageSpaceManager
{
};

struct BSRenderedTexture
{
};

struct NiParallelUpdateTaskManager
{
};

struct Interface
{
  public:
    enum enumMenus
    {
        MENU_ID_0x3f6 = 0x3f6,
        MENU_ID_0x41e = 0x41e,
        MENU_ID_0x424 = 0x424,
        MENU_ID_0x432 = 0x432,
        MENU_ID_0x438 = 0x438,
        MENU_ID_0x439 = 0x439,
        MENU_ID_0x43a = 0x43a,
        MENU_ID_0x43b = 0x43b
    };

    static bool __cdecl IsMenuActive(enumMenus menuID, unsigned int parameter);
};



struct MainTarget
{
    int FUN_00872f50(S148c0* prenderer, BSRenderedTexture* apDestination, int parameter, bool bmultiSampleEnabled);
    void FUN_00875fd0(bool bmultiSampleEnabled, int result, S148c0* prenderer, BSRenderedTexture* apDestination);

    void FUN_00872940(BSRenderedTexture* apDestination);
};

// @fnv 0x00872940
void MainTarget::FUN_00872940(BSRenderedTexture* apDestination)
{
    S148c0* prenderer = ((::fnv_00872940::S148c0 *)(::FUN_0043c4b0()));
    ImageSpaceManager* pimagespacemanager = ((::fnv_00872940::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()));
    const bool bmultiSampleEnabled = ::FUN_004dc310();
    intptr_t result;

    reinterpret_cast<::NiParallelUpdateTaskManager *>((reinterpret_cast<NiParallelUpdateTaskManager*>(this)))->SetupTaskWorkers();

    result = FUN_00872f50(prenderer, apDestination, 0, bmultiSampleEnabled);

    reinterpret_cast<::fnv_00874b90::FUN_00874b90_shell *>(this)->FUN_00874b90((::fnv_00874b90::ImageSpaceManager *)(pimagespacemanager), (::fnv_00874b90::GraphicsRenderer *)(prenderer), bmultiSampleEnabled, (::fnv_00874b90::BSRenderedTexture *)(apDestination));

    if (Interface::IsMenuActive(Interface::MENU_ID_0x41e, 0))
        ::FUN_00709ae0();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x3f6, 0))
        ::FUN_00709af0();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x438, 0))
        ::FUN_00709b00();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x439, 0))
        ::FUN_00709b10();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x43a, 0))
        ::FUN_00709b20();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x43b, 0))
        ::FUN_00709b30();

    if (Interface::IsMenuActive(Interface::MENU_ID_0x432, 0))
        ::FUN_007948d0();

    if (::FUN_008709f0())
    {
        FUN_00875fd0(bmultiSampleEnabled, result, prenderer, apDestination);
    }
    else if (apDestination)
    {
        reinterpret_cast<::fnv_00876830::BSRenderedTexture *>(this)->FUN_00876830(bmultiSampleEnabled, (std::intptr_t)(apDestination));
    }

    reinterpret_cast<::fnv_00876850::FUN_00876850_shell *>(this)->FUN_00876850((::fnv_00876850::BSRenderedTexture *)(result), (::fnv_00876850::ImageSpaceManager *)(pimagespacemanager), (::fnv_00876850::GraphicsRenderer *)(prenderer), (::fnv_00876850::Sun *)(0));

    if (Interface::IsMenuActive(Interface::MENU_ID_0x424, 0))
        ::FUN_007c9ca0();
}
}  // namespace fnv_00872940

class FUN_004505a0_target
{
  public:
    int Get();
};

class FUN_004505a0_cls
{
  public:
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
    FUN_004505a0_target* m_28;
    intptr_t FUN_004505a0();
};

// Returns the result of calling Get on m_28 if it is non-null, otherwise returns 0.
// @fnv 0x004505a0
intptr_t FUN_004505a0_cls::FUN_004505a0()
{
    return (m_28 != 0) ? ((intptr_t)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((m_28))->FUN_006838b0())) : 0;
}

// FUN_0086ba90 candidate
struct OffScreenFrameHost
{
    virtual bool v00();
    virtual bool v01();
    virtual bool v02();
    virtual bool v03();
    virtual bool v04();
    virtual bool v05();
    virtual bool v06();
    virtual bool v07();
    virtual bool v08();
    virtual bool v09();
    virtual bool v0A();
    virtual bool v0B();
    virtual bool v0C();
    virtual bool v0D();
    virtual bool v0E();
    virtual bool v0F();
    virtual bool v10();
    virtual bool v11();
    virtual bool v12();
    virtual bool v13();
    virtual bool v14();
    virtual bool v15();
    virtual bool v16();
    virtual bool v17();
    virtual bool v18();
    virtual bool v19();
    virtual bool v1A();
    virtual bool v1B();
    virtual bool v1C();
    virtual bool v1D();
    virtual bool v1E();
    virtual bool v1F();
    virtual bool v20();
    virtual bool v21();
    virtual bool v22();
    virtual bool v23();
    virtual bool v24();
    virtual bool v25();
    virtual bool v26();
    virtual bool v27();
    virtual bool v28();
    virtual bool v29();
    virtual bool v2A();
    virtual bool v2B();
    virtual bool v2C();
    virtual bool v2D();
    virtual bool v2E();
    virtual bool v2F();
    virtual bool v30();
    virtual bool v31();
    virtual bool v32();
    virtual bool v33();
    virtual bool v34();
    virtual bool v35();
    virtual bool v36();
    virtual bool v37();
    virtual bool v38();
    virtual bool v39();
    virtual bool v3A();
    virtual bool v3B();
    virtual bool v3C();
    virtual bool v3D();
    virtual bool v3E();
    virtual bool v3F();
    virtual bool v40();
    virtual bool v41();
    virtual bool v42();
    virtual bool v43();
    virtual bool v44();
    virtual bool v45();
    virtual bool v46();
    virtual bool v47();
    virtual bool v48();
    virtual bool v49();
    virtual bool v4A();
    virtual bool v4B();
    virtual bool v4C();
    virtual bool v4D();
    virtual bool v4E();
    virtual bool v4F();
    virtual bool v50();
    virtual bool v51();
    virtual bool v52();
    virtual bool v53();
    virtual bool v54();
    virtual bool v55();
    virtual bool v56();
    virtual bool v57();
    virtual bool v58();
    virtual bool v59();
    virtual bool v5A();
    virtual bool v5B();
    virtual bool v5C();
    virtual bool v5D();
    virtual bool v5E();
    virtual bool v5F();
    virtual bool v60();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int m_200;
    bool FUN_0086ba90();
};
// Calls FUN_0086ba60 with "EndOffScreenFrame" and flags 2, then v60; on success clears m_200 and returns true.
// @fnv 0x0086ba90
bool OffScreenFrameHost::FUN_0086ba90()
{
    if (!reinterpret_cast<::FUN_0086ba60_Class *>(this)->FUN_0086ba60((void *)("EndOffScreenFrame"), (void *)(2)))
    {
        return false;
    }
    if (!v60())
    {
        return false;
    }
    m_200 = 0;
    return true;
}

class Sky86B
{
  public:
    virtual ~Sky86B();

};

class SkyOwner86B
{
  public:
    void FUN_0086be30();
};

// Deletes the Sky86B singleton instance and clears its static pointer.
// @fnv 0x0086be30
void SkyOwner86B::FUN_0086be30()
{
    delete (*reinterpret_cast<::Sky86B * *>(&::Sky::pInstance));
    (*reinterpret_cast<::Sky86B * *>(&::Sky::pInstance)) = 0;
}

class C86D4C0Timer
{
  public:
    int unk00;
    float m_fInterval;

    void FUN_0086d4c0(unsigned int uiFrequency);
};

// Stores the timer interval as 1000 divided by uiFrequency, or 0 when uiFrequency is zero.
// @fnv 0x0086d4c0
void C86D4C0Timer::FUN_0086d4c0(unsigned int uiFrequency)
{
    m_fInterval = uiFrequency ? 1000.0 / uiFrequency : 0.0;
}

class B86F190Process
{
  public:
    bool FUN_00483710();
};

class B86F190Actor
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void* GetNiNode();

    int FUN_00931850();
};

class B86F190ActorList
{
  public:
    B86F190Actor* GetAt(unsigned int uiIndex);
};

class B86F190Manager
{
  public:
};

extern bool g_bB86F190Pending;

class B86F190Owner
{
  public:
    void FUN_0086f190();
};

// @fnv 0x0086f190
void B86F190Owner::FUN_0086f190()
{
    if (::DAT_011dea2b)
    {
        if (g_bB86F190Pending)
        {
            B86F190ActorList* pkList = ((::B86F190ActorList *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::B86F190Manager *>(&::g_011e0e80))))->GetCurrentProcessData()));
            B86F190Actor* pkActor = 0;
            for (unsigned int i = 0; i < reinterpret_cast<::FUN_005be5c0_shell *>((pkList))->FUN_005be5c0(0); i++)
            {
                pkActor = ((::B86F190Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((pkList))->FUN_00968670(i)));
                if (pkActor && !pkActor->FUN_00931850() && pkActor->GetNiNode())
                {
                    B86F190Process* pkProcess = ((::B86F190Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture()));
                    reinterpret_cast<::TESForm *>((pkProcess))->ClearData();
                }
            }
            reinterpret_cast<::TESForm *>((((::B86F190Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<B86F190Actor*>(::_g_thePlayer)))->GetBaseTexture()))))->ClearData();
        }
        g_bB86F190Pending = false;
    }
    else
    {
        g_bB86F190Pending = true;
    }
}


struct FUN_00872ed0_shell
{
    void FUN_00872ed0(int param_1);
};

// @fnv 0x00872ed0
void FUN_00872ed0_shell::FUN_00872ed0(int aiUnused)
{
    DebugBreak();
}

struct Point3Ctor
{
    float x;
    float y;
    float z;
    Point3Ctor(float fX, float fY, float fZ);
};

struct ScaleSource
{
};


extern NiPoint3 DAT_012003e0;

// Compares the object's current scale vectors against stored ones, sets DAT_012003cc when any component ratio exceeds 1.1, and stores the new vectors.
// @fnv 0x008744a0
void __cdecl FUN_008744a0(ScaleSource* apScaleSource)
{
    if (apScaleSource == 0)
    {
        (*reinterpret_cast<::NiPoint3 *>(&::DAT_012003d4)) = ::DAT_011a9490;
        (*reinterpret_cast<bool *>(&::DAT_012003cc)) = false;
        return;
    }
    NiPoint3 kCurA = *((::NiPoint3 *)(::FUN_0045bb80((intptr_t)(apScaleSource))));
    NiPoint3 kCurB = reinterpret_cast<::NiAVObject *>((void *)(apScaleSource))->GetWorldTranslation();
    NiPoint3 kDiffA_2 = kCurA - DAT_012003e0;
    NiPoint3 kDiffB5 = kCurB - (*reinterpret_cast<::NiPoint3 *>(&::DAT_012003d4));
    Point3Ctor kRatioA(kDiffA_2.x / DAT_012003e0.x, kDiffA_2.y / DAT_012003e0.y, kDiffA_2.z / DAT_012003e0.z);
    Point3Ctor kRatioB4(kDiffB5.x / (*reinterpret_cast<::NiPoint3 *>(&::DAT_012003d4)).x, kDiffB5.y / (*reinterpret_cast<::NiPoint3 *>(&::DAT_012003d4)).y, kDiffB5.z / (*reinterpret_cast<::NiPoint3 *>(&::DAT_012003d4)).z);
    if (kRatioA.x > 1.1 || kRatioA.y > 1.1 || kRatioA.z > 1.1 || kRatioB4.x > 1.1 || kRatioB4.y > 1.1 ||
        kRatioB4.z > 1.1)
    {
        (*reinterpret_cast<bool *>(&::DAT_012003cc)) = true;
    }
    else
    {
        (*reinterpret_cast<bool *>(&::DAT_012003cc)) = false;
    }
    DAT_012003e0 = kCurA;
    (*reinterpret_cast<::NiPoint3 *>(&::DAT_012003d4)) = kCurB;
}

struct FlagBlock_a234c0
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
    unsigned char flags[0x20];
};

struct FlagPair_a234c0
{
    FlagBlock_a234c0 first;
    FlagBlock_a234c0 second;
};

struct FlagOwner_a234c0
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
    FlagPair_a234c0 pairs[4];

    int FUN_00a234c0(int index, int bit, int mode);
};

// Compares the 0x80 bit of flags[bit] in the first and second flag blocks of pairs[index] according to mode and returns 1 if the mode's condition holds.
// @fnv 0x00a234c0
int FlagOwner_a234c0::FUN_00a234c0(int index, int bit, int mode)
{
    FlagBlock_a234c0* first = &pairs[index].first;
    FlagBlock_a234c0* second6 = &pairs[index].second;
    int result5 = 0;
    switch (mode)
    {
    case 0:
        if (first->flags[bit] & 0x80)
            result5 = 1;
        break;
    case 1:
        if (!(second6->flags[bit] & 0x80) && (first->flags[bit] & 0x80))
            result5 = 1;
        break;
    case 2:
        if (!(first->flags[bit] & 0x80) && (second6->flags[bit] & 0x80))
            result5 = 1;
        break;
    case 3:
        if ((first->flags[bit] & 0x80) != (second6->flags[bit] & 0x80))
            result5 = 1;
        break;
    }
    return result5;
}

struct FUN_00a235f0_Row
{
    unsigned int m_value00;
    unsigned int m_value01;
    unsigned int m_value02;
    unsigned int m_value03;
    unsigned int m_value04;
    unsigned int m_value05;
    unsigned int m_value06;
    unsigned int m_value07;
    unsigned int m_value08;
    unsigned int m_value09;
    unsigned int m_value10;
    unsigned int m_value11;
    unsigned int m_value12;
    unsigned int m_value13;
    unsigned int m_value14;
    unsigned int m_value15;
    unsigned int m_value16;
    unsigned int m_value17;
    unsigned int m_value18;
    unsigned int m_value19;
    unsigned int m_value20;
    unsigned int m_value21;
    unsigned int m_value22;
    unsigned int m_value23;
    unsigned int m_value24;
    unsigned int m_value25;
    unsigned int m_value26;
    unsigned int m_value27;
    unsigned int m_value28;
    unsigned int m_value29;
    unsigned int m_value30;
    unsigned int m_value31;
    unsigned int m_field80;
    unsigned int m_field84;
    unsigned int m_field88;
    unsigned int m_field8c;
    unsigned int m_field90;
    unsigned int m_field94;
    unsigned int m_field98;
    unsigned int m_field9c;
};

struct FUN_00a235f0_Class
{
    unsigned int m_field00;
    unsigned int m_field04;
    unsigned int m_field08;
    unsigned int m_field0c;
    unsigned int m_field10;
    unsigned int m_field14;
    unsigned int m_field18;
    unsigned int m_field1c;
    unsigned int m_field20;
    unsigned int m_field24;
    unsigned int m_field28;
    unsigned int m_field2c;
    unsigned int m_field30;
    FUN_00a235f0_Row m_row;

    int FUN_00a235f0(int param_1, int param_2);
};

// Reads a 32-bit value from the row at offset param_1*0xa0+0x34, returns -1 if its low 16 bits are 0xffff, else value/0x1194+0x20.
// @fnv 0x00a235f0
int FUN_00a235f0_Class::FUN_00a235f0(int aiRowIndex, int aiColumnIndex)
{
    unsigned int* row = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + aiRowIndex * 0xa0 + 0x34);
    int value = static_cast<int>(row[aiColumnIndex + 8]);

    if (static_cast<unsigned short>(value & 0xffff) == 0xffff)
        return -1;

    return value / 0x1194 + 0x20;
}

struct FUN_00a23650_entry
{
    unsigned int m_flags;
    char unk04[0x244 - 4];
};

struct FUN_00a23650_cls
{
    char unk000[0x558];
    FUN_00a23650_entry m_entries[1];
    int FUN_00a23650(int index);
};

// Reads the byte at bits 8-15 of the flags of the entry at index and returns 2 for that case, otherwise -1.
// @fnv 0x00a23650
int FUN_00a23650_cls::FUN_00a23650(int index)
{
    switch ((unsigned char)((m_entries[index].m_flags >> 8) & 0xff))
    {
    case 2:
        return 2;
    }
    return -1;
}

struct FUN_00a236f0_data
{
    unsigned int m_iElementCount;
    unsigned int m_flags;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

class FUN_00a236f0_item
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int code, void* data);
};

class FUN_00a236f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00a236f0_item* m_items[1];
    void FUN_00a236f0(int index, int a2, int a3);
};

// Builds a data block with the given values and dispatches it to the item at index via v06 with code 4.
// @fnv 0x00a236f0
void FUN_00a236f0_cls::FUN_00a236f0(int index, int aiValue1, int aiValue2)
{
    FUN_00a236f0_item* pItem = m_items[index];
    FUN_00a236f0_data data;
    data.m_iElementCount = 0x18;
    data.m_flags = 0x10;
    data.unk0C = 0;
    data.unk08 = 0;
    data.unk10 = aiValue1;
    data.unk14 = aiValue2;
    pItem->v06(4, &data);
}

struct DIPROPHEADER
{
    DWORD dwSize;
    DWORD dwHeaderSize;
    DWORD dwObj;
    DWORD dwHow;
};
struct DIPROPDWORD
{
    DIPROPHEADER diph;
    DWORD dwData;
};
struct InputDevice
{
    virtual unsigned int QueryInterface(void*, void**);
    virtual unsigned int AddRef();
    virtual unsigned int Release();
    virtual unsigned int GetCapabilities(void*);
    virtual unsigned int EnumObjects(void*, void*, DWORD);
    virtual unsigned int GetProperty(const void*, DIPROPHEADER*);
    virtual unsigned int SetProperty(const void*, const DIPROPHEADER*);
};
struct InputManager
{
    int unk00;
    int unk04;
    int unk08;
    InputDevice* devices[1];
    void FUN_00a23750(int index, float value);
};
// Scales value by 10000 and sets property 5 on the input device at index via SetProperty.
// @fnv 0x00a23750
void InputManager::FUN_00a23750(int index, float value)
{
    InputDevice* device = devices[index];
    DIPROPDWORD property;
    property.diph.dwSize = sizeof(DIPROPDWORD);
    property.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    property.diph.dwHow = 0;
    property.diph.dwObj = 0;
    property.dwData = (int)(value * 10000.0);
    device->SetProperty((const void*)5, &property.diph);
}

class A237F0Object
{
  public:
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
    void* m_pResource;

    int FUN_00a237f0(intptr_t iKey);
};

struct FUN_00a23820_tmp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00a23820_callee
{
  public:
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual int Unk_0A(int size, FUN_00a23820_tmp* out, int* flag, int zero);
};

class FUN_00a23820_cls
{
  public:
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
    FUN_00a23820_callee* m_pCallee;
    int FUN_00a23820(int* out);
};
// @fnv 0x00a237f0
int A237F0Object::FUN_00a237f0(intptr_t iKey)
{
    if (m_pResource && reinterpret_cast<::FUN_00a23820_cls *>(this)->FUN_00a23820((int *)(iKey)) == 1)
        return 1;
    return 0;
}

// Calls m_pCallee->Unk_0A with size 0x14 and, on success with flag set, writes tmp.unk00 to out and returns 2 or 1 depending on bit 0x80 of tmp.unk04.
// @fnv 0x00a23820
int FUN_00a23820_cls::FUN_00a23820(int* piOut)
{
    int pad;
    if ((m_pCallee != 0) != false)
    {
        int flag = 1;
        int r;
        FUN_00a23820_tmp tmp;
        if (m_pCallee->Unk_0A(0x14, &tmp, &flag, 0) == 0 && flag != 0)
        {
            r = ((tmp.unk04 & 0x80) != 0 ? -1 : 0) + 2;
            *piOut = tmp.unk00;
            return r;
        }
    }
    return 0;
}

typedef unsigned short WORD245;
typedef unsigned long DWORD245;

class InputManager245
{
  public:
    int FUN_00a24560(int iControlSlot, unsigned char ucKey, int iState);

    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C;
    int unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C;
    int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C;
    int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C;
    int unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC;
    int unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C;
    int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C;
    int unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C;
    int unk01A0, unk01A4, unk01A8, unk01AC, unk01B0, unk01B4, unk01B8, unk01BC;
    int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC;
    int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C;
    int unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C;
    int unk0260, unk0264, unk0268, unk026C, unk0270, unk0274, unk0278, unk027C;
    int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC;
    int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC;
    int unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C;
    int unk0320, unk0324, unk0328, unk032C, unk0330, unk0334, unk0338, unk033C;
    int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C;
    int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C;
    int unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC;
    int unk03E0, unk03E4, unk03E8, unk03EC, unk03F0, unk03F4, unk03F8, unk03FC;
    int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C;
    int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C;
    int unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C;
    int unk04A0, unk04A4, unk04A8, unk04AC, unk04B0, unk04B4, unk04B8, unk04BC;
    int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC;
    int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C;
    int unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C;
    int unk0560, unk0564, unk0568, unk056C, unk0570, unk0574, unk0578, unk057C;
    int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC;
    int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC;
    int unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C;
    int unk0620, unk0624, unk0628, unk062C, unk0630, unk0634, unk0638, unk063C;
    int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C;
    int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C;
    int unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC;
    int unk06E0, unk06E4, unk06E8, unk06EC, unk06F0, unk06F4, unk06F8, unk06FC;
    int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C;
    int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C;
    int unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C;
    int unk07A0, unk07A4, unk07A8, unk07AC, unk07B0, unk07B4, unk07B8, unk07BC;
    int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC;
    int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C;
    int unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C;
    int unk0860, unk0864, unk0868, unk086C, unk0870, unk0874, unk0878, unk087C;
    int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC;
    int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC;
    int unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C;
    int unk0920, unk0924, unk0928, unk092C, unk0930, unk0934, unk0938, unk093C;
    int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C;
    int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C;
    int unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC;
    int unk09E0, unk09E4, unk09E8, unk09EC, unk09F0, unk09F4, unk09F8, unk09FC;
    int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C;
    int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C;
    int unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C;
    int unk0AA0, unk0AA4, unk0AA8, unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C;
    int unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C;
    int unk0B60, unk0B64, unk0B68, unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C;
    int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC;
    int unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C;
    int unk0C20, unk0C24, unk0C28, unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C;
    int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C;
    int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C;
    int unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC;
    int unk0CE0, unk0CE4, unk0CE8, unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C;
    int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C;
    int unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C;
    int unk0DA0, unk0DA4, unk0DA8, unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C;
    int unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C;
    int unk0E60, unk0E64, unk0E68, unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C;
    int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC;
    int unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C;
    int unk0F20, unk0F24, unk0F28, unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C;
    int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C;
    int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C;
    int unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC;
    int unk0FE0, unk0FE4, unk0FE8, unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C;
    int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C;
    int unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C;
    int unk10A0, unk10A4, unk10A8, unk10AC, unk10B0, unk10B4, unk10B8, unk10BC;
    int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC;
    int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C;
    int unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C;
    int unk1160, unk1164, unk1168, unk116C, unk1170, unk1174, unk1178, unk117C;
    int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC;
    int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC;
    int unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C;
    int unk1220, unk1224, unk1228, unk122C, unk1230, unk1234, unk1238, unk123C;
    int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C;
    int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C;
    int unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC;
    int unk12E0, unk12E4, unk12E8, unk12EC, unk12F0, unk12F4, unk12F8, unk12FC;
    int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C;
    int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C;
    int unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C;
    int unk13A0, unk13A4, unk13A8, unk13AC, unk13B0, unk13B4, unk13B8, unk13BC;
    int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC;
    int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C;
    int unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C;
    int unk1460, unk1464, unk1468, unk146C, unk1470, unk1474, unk1478, unk147C;
    int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC;
    int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC;
    int unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C;
    int unk1520, unk1524, unk1528, unk152C, unk1530, unk1534, unk1538, unk153C;
    int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C;
    int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C;
    int unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC;
    int unk15E0, unk15E4, unk15E8, unk15EC, unk15F0, unk15F4, unk15F8, unk15FC;
    int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C;
    int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C;
    int unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C;
    int unk16A0, unk16A4, unk16A8, unk16AC, unk16B0, unk16B4, unk16B8, unk16BC;
    int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC;
    int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C;
    int unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C;
    int unk1760, unk1764, unk1768, unk176C, unk1770, unk1774, unk1778, unk177C;
    int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC;
    int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC;
    int unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C;
    int unk1820, unk1824, unk1828, unk182C, unk1830, unk1834, unk1838, unk183C;
    int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C;
    int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C;
    int unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC;
    int unk18E0, unk18E4, unk18E8, unk18EC, unk18F0;
    int m_iNumJoysticks;
};

// Dispatches a key/button state query to the keyboard, mouse, other, or joystick handlers based on the device id, returning 0 for unknown devices.
// @fnv 0x00a24560
int InputManager245::FUN_00a24560(int iControlSlot, unsigned char ucKeyCode, int iState)
{
    switch (iControlSlot)
    {
    case 0xff:
        return 0;
    case 0:
        return reinterpret_cast<::FUN_00a24180_shell *>(this)->FUN_00a24180(ucKeyCode, iState);
    case 1:
        return reinterpret_cast<::ButtonDevice *>(this)->FUN_00a23a50(ucKeyCode, iState);
    case 3:
        return reinterpret_cast<::FUN_00a23e10_Class *>(this)->FUN_00a23e10(ucKeyCode, iState);
    }

    if (iControlSlot - 2 >= m_iNumJoysticks)
        return 0;

    if (ucKeyCode < 0x20)
    {
        return reinterpret_cast<::FlagOwner_a234c0 *>(this)->FUN_00a234c0(iControlSlot - 2, ucKeyCode, iState);
    }
    else
    {
        int iPOV = reinterpret_cast<::FUN_00a235f0_Class *>(this)->FUN_00a235f0(iControlSlot - 2, ((WORD245)((((DWORD245)(ucKeyCode)) >> 16) & 0xffff)));
        int iValue = ((WORD245)(((DWORD245)(ucKeyCode)) & 0xffff));
        if (iPOV == iValue)
            return 1;
    }
    return 0;
}

struct FUN_00ec1800_cls
{
    unsigned int unk00;
    unsigned int unk04;
    HANDLE hObject;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    bool m_bQueryPending;
    void FUN_00ec1800();
};


// @fnv 0x00ec1800
void FUN_00ec1800_cls::FUN_00ec1800()
{
    if (hObject != 0)
    {
        m_bQueryPending = true;
        WaitForSingleObject(hObject, 0xffffffffu);
        hObject = 0;
        m_bQueryPending = false;
    }
}

class Menu
{
  public:
    virtual ~Menu();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual unsigned int GetID();
};
class SPECIALBookMenu : public Menu
{
};
class LoveTesterMenu : public Menu
{
};
class TileList
{
  public:
    void* GetHeadPos() const;
    Tile* Remove(Tile*&);
};
class Tile
{
  public:
    virtual ~Tile();
    TileList children;
};
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};
void __cdecl FUN_007c6120();
void __cdecl FUN_007917a0();

// Enables detach, walks the root tile's children and removes tiles by menu ID, calling handlers for the book and love tester menus, then disables detach.
// @fnv 0x00706320
void __cdecl FUN_00706320(int)
{
    ::fnv_007a2070::s_bAllowDetach = true;
    Tile* root = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->FUN_00586150();
    {
        void* position = root->children.GetHeadPos();
        while (position)
        {
            Tile* tile = ((::Tile *)(reinterpret_cast<::ListStandIn *>(&(root->children))->FUN_0057cbe0((int **)&(position))));
            if (tile && reinterpret_cast<::FUN_00a03c90_shell *>((tile))->FUN_00a03c90())
            {
                unsigned int id = reinterpret_cast<::FUN_00a03c90_shell *>((tile))->FUN_00a03c90()->GetID();
                switch (id)
                {
                case 1002:
                case 1003:
                case 1004:
                case 1007:
                case 1023:
                case 1035:
                case 1061:
                    break;
                case 1060: {
                    SPECIALBookMenu* pBookMenu = tile ? dynamic_cast<SPECIALBookMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((tile))->FUN_00a03c90()) : 0;
                    if (pBookMenu)
                        FUN_007c6120();
                    delete root->children.Remove(tile);
                    break;
                }
                case 1074: {
                    LoveTesterMenu* pLoveMenu = tile ? dynamic_cast<LoveTesterMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((tile))->FUN_00a03c90()) : 0;
                    if (pLoveMenu)
                        FUN_007917a0();
                    delete root->children.Remove(tile);
                    break;
                }
                case 1013:
                    if (((bool)(::IsStartMenuFlag1Set())))
                    {
                        delete root->children.Remove(tile);
                    }
                    break;
                default:
                    delete root->children.Remove(tile);
                    break;
                }
            }
        }
    }
    ::fnv_007a2070::s_bAllowDetach = false;
}

struct Manager86
{
    virtual void First();
    virtual void Second();
    virtual void Stop();
};
struct Device86
{
    virtual int QueryInterface(void*, void*);
    virtual int AddRef();
    virtual int Release();
    virtual int TestCooperativeLevel();
};
struct Rect86
{
    int left;
    int top;
    int right;
    int bottom;
};
struct Point86
{
    float x;
    float y;
    float z;
    void FUN_00416870(float, float, float);
};
struct Receiver86
{

    void FUN_0066b0d0(int);
    void FUN_00b6da10(int);
    void FUN_00448420();
    void FUN_008c73a0();
    Receiver86* FUN_008d8520();
    void FUN_0086be30();
    void FUN_006c0900();
    void* FUN_0086bee0(unsigned int);
    void* FUN_0086bf10(unsigned int);
    void* FUN_0086bf40(unsigned int);
    void FUN_006eb980();
    void* FUN_00717e50();
    void FUN_005e01b0(void*);
    void FUN_0086bb20(void*);
    void FUN_0086bc10(void*);
    int FUN_00aa47c0(void*, int);

    void FUN_0086bda0();
    Receiver86* FUN_00460140();
    int* FUN_006815c0();
    void FUN_00458200(int);
    void ClearIdleAnims();
    void FUN_008a8150(int);
    void FUN_00970d50();
    void FUN_004614e0();
    void FUN_007d6bd0(int);
    void FUN_00483710();
    void FUN_004f15a0(int);
    int FUN_008d6f30();
    void FUN_004650a0(int);
    void FUN_00ec1800();
    void FUN_00456520();
    int FUN_0044ddc0();
    unsigned char FUN_00451530();
    intptr_t FUN_00559450();
    Device86* FUN_004dc020();
    void FUN_0086ba10();
    void FUN_0086ba90();
    void FUN_0086e650();
    void FUN_00ad8740();
    void FUN_00ad8700();
    void FUN_00ad7740(int);
    unsigned int FUN_0044edb0();
    Receiver86* FUN_004e2190();
    void FUN_00b63620();
    void FUN_004a4340();
    void FUN_008026b0();
    bool FUN_005dc960();
    unsigned char FUN_00678ce0();
    void FUN_008774a0(int);

    void FUN_00b012f0(const char*, const char*);
    void FUN_004a0370();
    void FUN_0086bbd0(void*, int);
    void FUN_0086bae0(void*, int);
    void FUN_004a03c0();
    void FUN_00ec16d0(const char*, int, int, int, int, float);
    void FUN_0086cf20(Receiver86*);
    int FUN_006629f0();
    void FUN_006eb8c0();
    void FUN_006c07d0();
    void FUN_008c7290();
    void FUN_0086d500();
    void FUN_0086d590();
    void FUN_00871c90(int);

    Receiver86* FUN_008526c0();
    void FUN_004fb090(void*);
    void FUN_006ecd40(int(__cdecl*)(...));
    void FUN_006ff880(int);
    void FUN_005e0200(const void*);
};
struct Setting86
{
    unsigned char* FUN_00408d60() throw();
    const char* FUN_00403df0() throw();
};
struct SystemInfo86
{
    unsigned int architecture;
    void* pageSize;
    void* minAddress;
    void* maxAddress;
    unsigned int mask;
    unsigned int processors;
    unsigned int type;
    unsigned int granularity;
    unsigned short level;
    unsigned short revision;
};
using Context86 = ::AutoMemContext;
struct Text86
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void FUN_008783c0(void*);
    void FUN_008784d0();
};
struct WindowClass86
{
    unsigned int style;
    void* procedure;
    int classExtra;
    int windowExtra;
    unsigned int instance;
    unsigned int icon;
    unsigned int cursor;
    unsigned int background;
    unsigned int menu;
    char* className;
};
struct Message86
{
    unsigned int window;
    unsigned int id;
    unsigned int wparam;
    unsigned int lparam;
    unsigned int time;
    int x;
    int y;
};
typedef int(__cdecl* code)(...);

int __cdecl FUN_00408d60(...);
Receiver86* __cdecl FUN_00af2640();
int __cdecl FUN_004fb090(...);
int __cdecl FUN_008526c0(...);
int __cdecl FUN_006ecd40(...);
int __cdecl FUN_0086bde0(...);
int __cdecl FUN_0086bcd0(...);
int __cdecl FUN_0086bcc0(...);
int __cdecl FUN_00404eb0(...);
int __cdecl FUN_00404f70(...);

int __cdecl FUN_006ff880(...);
int __cdecl FUN_005e0200(...);
Receiver86* __cdecl FUN_0044f560(...);
int __cdecl FUN_00406d50(...);
Receiver86* __cdecl FUN_004de490(...);
int __cdecl FUN_00404ee0(...);
int __cdecl FUN_00403df0(...);
int __cdecl FUN_00b012f0(...);

int __cdecl FUN_0086bce0(...);
int __cdecl FUN_0086bda0(...);

int __cdecl FUN_0086d500(...);
int __cdecl FUN_004a0370(...);
int __cdecl FUN_0086bbd0(...);
int __cdecl FUN_0086bae0(...);
int __cdecl FUN_0086d590(...);
int __cdecl FUN_00871c90(...);
int __cdecl FUN_004a03c0(...);
int __cdecl FUN_00ec16d0(...);
int __cdecl FUN_0086cf20(...);
int __cdecl FUN_006629f0(...);
int __cdecl FUN_0086be90(...);
int __cdecl FUN_0086be80(...);
int __cdecl FUN_008c7290(...);
int __cdecl FUN_006eb8c0(...);
int __cdecl FUN_006c07d0(...);
int __cdecl FUN_00416870(...);
int __cdecl FUN_00460140(...);
int __cdecl FUN_006815c0(...);
int __cdecl FUN_00458200(...);
int __cdecl ClearIdleAnims(...);
int __cdecl FUN_008a8150(...);
int __cdecl FUN_00970d50(...);
int __cdecl FUN_004614e0(...);
int __cdecl FUN_007d6bd0(...);
int __cdecl FUN_00483710(...);
int __cdecl FUN_004f15a0(...);
int __cdecl FUN_008d6f30(...);
int __cdecl FUN_004650a0(...);
int __cdecl FUN_00ec1800(...);
int __cdecl FUN_00456520(...);
int __cdecl FUN_0044ddc0(...);
int __cdecl FUN_00451530(...);
int __cdecl FUN_00559450(...);
int __cdecl FUN_004dc020(...);
int __cdecl FUN_0086ba10(...);
int __cdecl FUN_0086ba90(...);
int __cdecl FUN_0086e650(...);
int __cdecl FUN_00ad8740(...);
int __cdecl FUN_00ad7740(...);
int __cdecl FUN_0044edb0(...);
int __cdecl FUN_00ad8700(...);
int __cdecl FUN_004e2190(...);
int __cdecl FUN_00b63620(...);
Receiver86* __cdecl FUN_0049fef0();
int __cdecl FUN_004a4340(...);
int __cdecl FUN_008026b0(...);
int __cdecl FUN_005dc960(...);
int __cdecl FUN_00678ce0(...);
int __cdecl FUN_008774a0(...);
int __cdecl FUN_00706320(...);
Receiver86* __cdecl FUN_004a0ea0();
int __cdecl FUN_00b6da10(...);
int __cdecl FUN_0066b0d0(...);
int __cdecl FUN_0086bea0(...);
int __cdecl FUN_00448420(...);
int __cdecl FUN_008c73a0(...);
int __cdecl FUN_008d8520(...);
int __cdecl FUN_0086be30(...);
int __cdecl FUN_006c0900(...);
int __cdecl FUN_0086bee0(...);
int __cdecl FUN_006eb980(...);
int __cdecl FUN_00717e50(...);
int __cdecl FUN_005e01b0(...);
int __cdecl FUN_0086bb20(...);
int __cdecl FUN_0086bc10(...);
int __cdecl FUN_00aa47c0(...);

extern unsigned int _DAT_011c16bc;
extern char str_01082ab8[];
extern char str_01082a7c[];
extern char str_0104df38[];
extern unsigned char UNK_01082a38;
extern unsigned char UNK_01082a28;
extern unsigned char UNK_01082a10;
extern unsigned char UNK_01082a00;
extern unsigned char UNK_010829b4;
extern unsigned char UNK_01082990;
extern unsigned char UNK_01082978;
extern unsigned char UNK_0108295c;
extern unsigned int _DAT_011c3f2c;
extern unsigned char UNK_0108293c;
extern unsigned char UNK_01082924;
extern unsigned char UNK_01082910;
extern unsigned char UNK_010828fc;
extern unsigned char UNK_010828ec;
extern char str_01082a48[];



// Creates the game window and subsystems, runs the message/render loop until exit, then tears everything down and returns 0.
// @fnv 0x0086a850
int FUN_0086a850(HINSTANCE param_1, HINSTANCE param_2, char* param_3, int param_4)

{
    RECT inactiveRect3;
    unsigned int inactiveStyle3;
    RECT activeRect5;
    unsigned int activeStyle1;
    int deviceStatus13;
    char launchPath0[260];
    HINSTANCE shellResult10;
    unsigned short* option6;
    int argumentIndex33;
    int argumentCount8;
    unsigned short** arguments5;
    unsigned char enableMemory0;
    Point86 position25;
    SYSTEM_INFO systemInfo7;
    unsigned int startupState3;
    WNDCLASSA windowClass10;
    MSG message0;
    Context86 memoryContext11;
    Text86 shutdownText46;
    HWND gameWindow3;
    char path2[260];
    HWND window1;
    HANDLE mutex17;
    RECT windowRect0;
    unsigned char paused1;
    uintptr_t startupFlags3;
    HWND existingWindow30;

    mutex17 = CreateMutexA(0, 0, str_01082ab8);
    if (GetLastError() == 0xb7)
    {
        MessageBoxA(0, str_01082a7c, str_0104df38, 0);
        return 0;
    }
    if (GetSystemMetrics(0x1000))
    {
        MessageBoxA(0, str_01082a48, str_0104df38, 0);
        return 0;
    }
    {
        {
            enableMemory0 = 0;
            enableMemory0 = 1;
            ::FUN_00c3bd30(enableMemory0, *(*reinterpret_cast<::Setting86 *>(&::g_011dec88)).FUN_00408d60(), *(*reinterpret_cast<::Setting86 *>(&::g_011dee20)).FUN_00408d60(),
                         *(*reinterpret_cast<::Setting86 *>(&::g_011ded74)).FUN_00408d60(), (uintptr_t)(((int (&)(...))::FUN_0086a580)));
            ::FUN_00c3bb90((const char *)(unsigned char *)(&UNK_01082a38));
            ::fnv_00c3bbe0::FUN_00c3bbe0((const char *)(unsigned char *)(&UNK_01082a28));
            ::FUN_00c3bc30((const char *)(unsigned char *)(&UNK_01082a10));
            ::fnv_00c3bc80::FUN_00c3bc80((const char *)(unsigned char *)(&UNK_01082a00));
            GetSystemInfo(&systemInfo7);
            *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) = systemInfo7.dwNumberOfProcessors;
            ::BGSSaveLoadManager::GetSaveDirectory(path2);
            if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) == 1)
            {
                *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) = 2;
            }
            existingWindow30 = FindWindowA(_DAT_011a2fe8, 0);
            if (existingWindow30 != 0)
            {
                SetForegroundWindow(existingWindow30);
                return 0;
            }
            {
                int result5;
                Receiver86* globalsToDelete3;
                Receiver86* globalsDeleteTarget3;
                Receiver86* interfaceToDelete85;
                Receiver86* interfaceDeleteTarget24;
                Receiver86* tesToDelete37;
                Receiver86* tesDeleteTarget23;
                Receiver86* interfaceAllocation2;
                Receiver86* newInterface17;
                Receiver86* globalsAllocation7;
                Receiver86* newGlobals20;
                Receiver86* fileAllocation4;
                Receiver86* fileSystem2;
                int shellExitResult20;
                ::FUN_004b4a30(_DAT_011a2fe8);
                reinterpret_cast<::EffectSetting *>((FUN_00af2640()))->SetBoltSound((::TESSound *)(void *)(&(*reinterpret_cast<unsigned char *>(&::RunModeSwitch))));
                reinterpret_cast<::CombatProcedure *>((FUN_00af2640()->FUN_008526c0()))->Initialize((::CombatController *)(((int (&)(...))::FUN_0086a020)));
                ::FUN_00aa20b0((void *)(0));
                ::FUN_00c5d4e0();
                ::BipedNodeNames::InitializeMultiBounds();
                ::FUN_00a1c6f0();
                ::BSShaderInitializer::InitializeMultiBounds();
                ::FUN_0045b020();
                ::fnv_00404f30::FUN_00404f30(0x3b);
                FUN_0086bde0(((int (&)(...))::FUN_0086a050));
                FUN_0086bcd0(&(*reinterpret_cast<unsigned char *>(&::SetFlagOnVirtualResult)));
                FUN_0086bcc0(1);
                ::FUN_00c3a6d0();
                FUN_0086bd70();
                memoryContext11.Enter(0x10, 1, (char *)(void *)(&(*reinterpret_cast<unsigned char *>((void *)&::DAT_010829c4))), 0x8e0);
                ::FUN_00453720();
                memoryContext11.Leave();
                memoryContext11.Enter(0xf, 1, (char *)(void *)(&(*reinterpret_cast<unsigned char *>((void *)&::DAT_010829c4))), 0x8e6);
                ::fnv_00a61ad0::FUN_00a61ad0();
                memoryContext11.Leave();
                ::GetDebugFlags();
                argumentCount8 = 0;
                arguments5 = (unsigned short**)CommandLineToArgvW(GetCommandLineW(), &argumentCount8);
                if (arguments5 != 0)
                {
                    for (argumentIndex33 = 0; argumentIndex33 < argumentCount8; argumentIndex33 = argumentIndex33 + 1)
                    {
                        if ((arguments5[argumentIndex33] != 0) && (*arguments5[argumentIndex33] == 0x2d))
                        {
                            option6 = arguments5[argumentIndex33] + 1;
                            if (fnv::crt::wcsicmp((const wchar_t *)(option6), (const wchar_t *)(&UNK_010829b4)) == 0)
                            {
                                reinterpret_cast<::FUN_006ff880_Class *>((((::Receiver86 *)(::FUN_006ff580()))))->FUN_006ff880(0);
                            }
                        }
                    }
                    LocalFree(arguments5);
                }
                reinterpret_cast<::C5E0200File *>((((::Receiver86 *)(::FUN_00877950()))))->FUN_005e0200((const char *)(const void *)(&UNK_01082990));
                reinterpret_cast<::C5E0200File *>((FUN_0044f560()))->FUN_005e0200((const char *)(path2));
                ::TaskQueueInterface::CopyStringToBuffer(path2, 0x104, (const char *)(((intptr_t)(::FUN_004dc110()))));
                FUN_00406d50(path2, 0x104, _DAT_011a2ff0);
                reinterpret_cast<::C5E0200File *>((FUN_004de490()))->FUN_005e0200((const char *)(path2));
                ::TaskQueueInterface::CopyStringToBuffer(path2, 0x104, (const char *)(((intptr_t)(::FUN_004dc110()))));
                FUN_00406d50(path2, 0x104, ::DAT_011a2ff8);
                reinterpret_cast<::C5E0200File *>((((::Receiver86 *)(::FUN_0045d180()))))->FUN_005e0200((const char *)(path2));
                reinterpret_cast<::C5E0200File *>((FUN_004de490()))->FUN_005e0200((const char *)(path2));
                if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) == 1)
                {
                    *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) = 2;
                }
                if (((unsigned char)(::fnv_004da570::FUN_004da570())))
                {
                    ::FUN_004da4d0(1);
                    ((::Manager86 *)&(::GetTaskletManager()))->Stop();
                    ::FUN_00876a70(launchPath0, 0x104);
                    FUN_00406d50(launchPath0, 0x104, &UNK_01082978);
                    shellResult10 = ShellExecuteA(0, 0, launchPath0, 0, 0, 1);
                    if (shellResult10 != 0)
                    {
                        shellExitResult20 = 0;
                        memoryContext11.Leave();
                        return shellExitResult20;
                    }
                }
                reinterpret_cast<::FUN_00b012f0_shell *>((((::Receiver86 *)&(::BSFileCache::GetRandomGenerator()))))->FUN_00b012f0((intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting86 *>(&::g_011dee78))))->GetMenuTitle()))), (intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting86 *>(&::g_011ded2c))))->GetMenuTitle()))));
                fileAllocation4 = (Receiver86*)::FUN_00401000(16);
                fileSystem2 = fileAllocation4
                                  ? ((::Receiver86 *)(new ((void *)(fileAllocation4)) ::FUN_00afdc60((intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting86 *>(&::g_011dece4))))->GetMenuTitle()))), *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting86 *>(&::g_011dee6c)))))), 0)))
                                  : 0;
                FUN_0086bce0(&(*reinterpret_cast<unsigned char *>((void *)&::g_011d21e4_arg1)));
                ::FUN_00c3bd30(enableMemory0, *(*reinterpret_cast<::Setting86 *>(&::g_011dec88)).FUN_00408d60(), *(*reinterpret_cast<::Setting86 *>(&::g_011dee20)).FUN_00408d60(),
                             *(*reinterpret_cast<::Setting86 *>(&::g_011ded74)).FUN_00408d60(), (uintptr_t)(((int (&)(...))::FUN_0086a580)));
                ::FUN_00c3bb90((const char *)(unsigned char *)(&UNK_01082a38));
                ::fnv_00c3bbe0::FUN_00c3bbe0((const char *)(unsigned char *)(&UNK_01082a28));
                ::FUN_00c3bc30((const char *)(unsigned char *)(&UNK_01082a10));
                ::fnv_00c3bc80::FUN_00c3bc80((const char *)(unsigned char *)(&UNK_01082a00));
                memoryContext11.Enter(0x18, 1, (char *)(void *)(&(*reinterpret_cast<unsigned char *>((void *)&::DAT_010829c4))), 0x992);
                ::FUN_0040fbe0();
                ((::Receiver86 *)&(::BSFileCache::GetRandomGenerator()))->FUN_0086bda0();
                memoryContext11.Leave();
                memoryContext11.Enter(0x13, 1, (char *)(void *)(&(*reinterpret_cast<unsigned char *>((void *)&::DAT_010829c4))), 0x99c);
                ::fnv_00876d20::FUN_00876d20();
                memoryContext11.Leave();
                windowClass10.style = 3;
                windowClass10.lpfnWndProc = reinterpret_cast<WNDPROC>(&::fnv_0086a0a0::FUN_0086a0a0);
                windowClass10.cbClsExtra = 0;
                windowClass10.cbWndExtra = 0;
                windowClass10.hInstance = param_1;
                windowClass10.hIcon = LoadIconA(param_1, MAKEINTRESOURCEA(0x65));
                windowClass10.hCursor = 0;
                windowClass10.hbrBackground = (HBRUSH)GetStockObject(4);
                windowClass10.lpszClassName = _DAT_011a2fe8;
                windowClass10.lpszMenuName = 0;
                RegisterClassA(&windowClass10);
                windowRect0.left = 0;
                windowRect0.top = 0;
                windowRect0.right = 0x140;
                windowRect0.bottom = 0xf0;
                AdjustWindowRect(&windowRect0, 0x10000000, 0);
                window1 = CreateWindowExA(0, _DAT_011a2fe8, _DAT_011a2fe8, 0x10000000, 0, 0,
                                          windowRect0.right - windowRect0.left, windowRect0.bottom - windowRect0.top, 0,
                                          0, param_1, 0);
                globalsAllocation7 = (Receiver86*)::FUN_00401000(0xa4);
                newGlobals20 = globalsAllocation7 ? ((::Receiver86 *)(new ((void *)(globalsAllocation7)) ::FUN_0086c160((void *)(std::uintptr_t)(window1), (void *)(std::uintptr_t)(param_1)))) : 0;
                (*reinterpret_cast<unsigned char * *>(&::g_osGlobals)) = (unsigned char*)newGlobals20;
                memoryContext11.Enter(0xd, 1, (char *)(void *)(&(*reinterpret_cast<unsigned char *>((void *)&::DAT_010829c4))), 0x9f8);
                interfaceAllocation2 = (Receiver86*)::FUN_00401000(8);
                newInterface17 = interfaceAllocation2 ? ((::Receiver86 *)(reinterpret_cast<::PerformanceTimerManager *>((interfaceAllocation2))->BeginFrame())) : 0;
                (*reinterpret_cast<uintptr_t *>(&::DAT_011d8804)) = (uintptr_t)newInterface17;
                memoryContext11.Leave();
                ::FUN_0040fbe0();
                ::FUN_0086d500(::g_osGlobals);
                ::DAT_011f4509 = 1;
                ((::Receiver86 *)(::FUN_0043c4b0()))->FUN_004a0370();
                reinterpret_cast<::fnv_0086bbd0::S86b *>((((::Receiver86 *)(::FUN_0043c4b0()))))->FUN_0086bbd0((uintptr_t)(&((int (&)(...))::fnv_005d4a40::FUN_005d4a40)), (::fnv_0086bbd0::BGSAddonNode *)(0));
                reinterpret_cast<::S86 *>((((::Receiver86 *)(::FUN_0043c4b0()))))->FUN_0086bae0((uintptr_t)(&(*reinterpret_cast<unsigned char *>(&::fnv_00872570::FUN_00872570))), (::BGSAddonNode *)(0));
                FUN_0086bf70();
                ((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))->FUN_0086d590();
                ::Interface::Init(1);
                ::FUN_006519f0();
                reinterpret_cast<::fnv_00871c90::FUN_00871c90_shell *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->FUN_00871c90(1);
                ::FUN_006a2920();
                ::FUN_0086c010();
                reinterpret_cast<::fnv_004a03c0::DD *>((((::Receiver86 *)(::FUN_0043c4b0()))))->FUN_004a03c0();
                ::FUN_00866ff0();
                reinterpret_cast<::BEC16D0MoviePlayerThread *>(((*reinterpret_cast<::Receiver86 * *>(&::DAT_0126fac4))))->FUN_00ec16d0((void *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting86 *>(&::g_011de72c))))->GetMenuTitle()))), 0, -1, 1, 1, 0.0f);
                memoryContext11.Leave();
                ((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))->FUN_0086cf20((Receiver86*)((::BSFaceGenNiNode *)(::FUN_0045c670())));
                FUN_0086be90(((Receiver86*)((::BSFaceGenNiNode *)(::FUN_0045c670())))->FUN_006629f0());
                FUN_0086be80(((Receiver86*)((::BSFaceGenNiNode *)(::FUN_0045c670())))->FUN_006629f0());
                if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
                {
                    reinterpret_cast<::AIThreadManager *>((((::Receiver86 *)(::FUN_00713d80()))))->StartRenderingTaskThread();
                }
                ::FUN_006d0870();
                reinterpret_cast<::PathManager *>((((::Receiver86 *)(::GetPathManager()))))->Initialize();
                if (*(*reinterpret_cast<::Setting86 *>(&::g_011d73e4)).FUN_00408d60())
                {
                    reinterpret_cast<::FUN_006c07d0_shell *>((((::Receiver86 *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c07d0();
                }
                ::ScreenSplatter::Init();
                ::ScreenCustomSplatter::Init();
                startupState3 = 0;
                startupFlags3 = 0;
                reinterpret_cast<::FUN_00416870_t *>(&(position25))->FUN_00416870(::g_011c7b14_arg1, ::g_011c7b14_arg1, ::DAT_0101e704);
                reinterpret_cast<::WS458200_Shell *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::g_TES)))))->FUN_00458200((::WS458200_World *)(*((intptr_t *)(&reinterpret_cast<::SimpleListNodeView*>((*reinterpret_cast<::Receiver86 * *>(&::g_dataHandler))->FUN_00460140())->m_item))));
                reinterpret_cast<::fnv_0095ee80::FUN_0095ee80_Class *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::_g_thePlayer)))))->ClearIdleAnims();
                reinterpret_cast<::fnv_008a8150::FUN_008a8150_shell *>(((*reinterpret_cast<::Receiver86 * *>(&::g_TESSaveLoadGame))))->FUN_008a8150(1);
                ::FUN_0040fbe0();
                reinterpret_cast<::Lists970d50 *>((((Receiver86*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_00970d50();
                reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::Receiver86 * *>(&::g_dataHandler))))->GetRegions();
                reinterpret_cast<::FUN_007d6bd0_Class *>(((*reinterpret_cast<::Receiver86 * *>(&::g_BGSSaveLoadGame))))->FUN_007d6bd0(1);
                ::FUN_0040fbe0();
                ::FUN_00876dd0((const char *)(startupFlags3), (::SLPoint3 *)(::Point86 *)(&position25));
                ::FUN_0040fbe0();
                ::fnv_00877260::FUN_00877260((*(::NiPoint3 *)&(const ::Point86 &)(position25)));
                ::Interface::RefreshInterfaceState();
                reinterpret_cast<::TESForm *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::_g_thePlayer)))))->ClearData();
                reinterpret_cast<::FUN_004f15a0_shell *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->FUN_004f15a0(1);
                ::FUN_00af4540();
                if (!((reinterpret_cast<::LowProcess *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::_g_thePlayer)))))->GetTarget())))
                {
                    reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::Receiver86 * *>(&::g_dataHandler))))->SetSaveLoadGameState(-1);
                    ::FUN_0040fbe0();
                    ::fnv_007053f0::FUN_007053f0();
                    reinterpret_cast<::FUN_00ec1800_cls *>(((*reinterpret_cast<::Receiver86 * *>(&::DAT_0126fac4))))->FUN_00ec1800();
                    ::FUN_0040fbe0();
                }
                else
                {
                    reinterpret_cast<::FUN_00ec1800_cls *>(((*reinterpret_cast<::Receiver86 * *>(&::DAT_0126fac4))))->FUN_00ec1800();
                }
                reinterpret_cast<::FUN_00456520_Class *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::DAT_01202d98)))))->FUN_00456520();
                ::FUN_0040fbe0();
                ::FUN_00403d30(&message0, 0, sizeof(message0));
                gameWindow3 = ((HWND)(reinterpret_cast<::Twin_0044ddc0 *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->GetName()));
                paused1 = '\0';
                while (true)
                {
                    while (PeekMessageA(&message0, 0, 0, 0, 1))
                    {
                        TranslateMessage(&message0);
                        DispatchMessageA(&message0);
                    }
                    if (GetActiveWindow() == gameWindow3 || ((unsigned char)(reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::g_TES)))))->FUN_00451530())) ||
                        (*reinterpret_cast<::Receiver86 *>(&::g_011deb30)).FUN_00559450() || *(*reinterpret_cast<::Setting86 *>(&::g_011deed8)).FUN_00408d60())
                    {
                        deviceStatus13 = ((::Device86 *)(reinterpret_cast<::NiDX9RendererView *>(::FUN_0043c4b0())->m_pkD3DDevice9))->TestCooperativeLevel();
                        if (deviceStatus13 < 0)
                        {
                            ((::Receiver86 *)(::FUN_0043c4b0()))->FUN_0086ba10();
                            reinterpret_cast<::OffScreenFrameHost *>((((::Receiver86 *)(::FUN_0043c4b0()))))->FUN_0086ba90();
                            Sleep(0x32);
                        }
                        else
                        {
                            ((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))->FUN_0086e650();
                        }
                        if (paused1 != '\0')
                        {
                            paused1 = '\0';
                            reinterpret_cast<::FUN_00ad8740_shell *>((((::Receiver86 *)(::FUN_00453a70()))))->FUN_00ad8740();
                            ::FUN_00830660();
                            ::FalloutRadio::Update(0);
                            reinterpret_cast<::BSAudio *>((((::Receiver86 *)(::FUN_00453a70()))))->Update(1);
                            if (FUN_00446e10())
                            {
                                activeRect5.left = 0;
                                activeRect5.top = 0;
                                activeRect5.right = ((int)(::FUN_004dc1f0()));
                                activeRect5.bottom = FUN_004dc200();
                                activeStyle1 = 0;
                                activeStyle1 = GetWindowLongA(window1, 0xfffffff0);
                                AdjustWindowRectEx(&activeRect5, activeStyle1, 0, 0);
                                SetWindowPos(window1, 0, activeRect5.left, activeRect5.bottom,
                                             activeRect5.right - activeRect5.left, activeRect5.top - activeRect5.bottom,
                                             0);
                            }
                        }
                        if (((paused1 == '\0') && (*(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)) != '\0')) && (deviceStatus13 >= 0))
                        {
                            ::BSSystemUtility::GetRandomGenerator();
                            *(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)) = '\0';
                        }
                    }
                    else
                    {
                        if (paused1 == '\0')
                        {
                            paused1 = '\x01';
                            if (!(unsigned char)FUN_0086bdf0())
                            {
                                if (GetCurrentThreadId() == ((uintptr_t)(reinterpret_cast<::MagicCaster_shell *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->FUN_0044edb0())))
                                {
                                    ::LoadingMenu::UpdateLoadingScreenThread();
                                    *(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)) = '\x01';
                                }
                            }
                            reinterpret_cast<::S_ad8700 *>((((::Receiver86 *)(::FUN_00453a70()))))->FUN_00ad8700();
                            ::FUN_00830640();
                            ::FalloutRadio::Update(0);
                            reinterpret_cast<::BSAudio *>((((::Receiver86 *)(::FUN_00453a70()))))->Update(1);
                            ::fnv_00b63620::FUN_00b63620((::fnv_00b63620::AccumStub *)(((::Receiver86 *)(reinterpret_cast<::FUN_004e2190_shell *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->FUN_004e2190()))));
                            reinterpret_cast<::Owner4a4 *>((FUN_0049fef0()))->FUN_004a4340();
                            reinterpret_cast<::Owner *>((((::Receiver86 *)(::fnv_00705910::FUN_00705910()))))->FUN_008026b0();
                            if (FUN_00446e10())
                            {
                                inactiveRect3.left = 0;
                                inactiveRect3.top = 0;
                                inactiveRect3.right = ((int)(::FUN_004dc1f0()));
                                inactiveRect3.bottom = FUN_004dc200();
                                inactiveStyle3 = 0;
                                inactiveStyle3 = GetWindowLongA(window1, 0xfffffff0);
                                AdjustWindowRectEx(&inactiveRect3, inactiveStyle3, 0, 0);
                                SetWindowPos(window1, 0, inactiveRect3.left, inactiveRect3.bottom,
                                             inactiveRect3.right - inactiveRect3.left,
                                             inactiveRect3.top - inactiveRect3.bottom, 0);
                            }
                        }
                        Sleep(0x32);
                    }
                    if (reinterpret_cast<::FUN_005dc960_shell *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->FUN_005dc960())
                        break;
                    if (((unsigned char)(reinterpret_cast<::FUN_00678ce0_shell *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->FUN_00678ce0())))
                    {
                        ((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))->FUN_008774a0(1);
                    }
                }
                reinterpret_cast<::FUN_004f15a0_shell *>((((Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals)))))->FUN_004f15a0(0);
                ::FUN_006ff620();
                ::fnv_00703610::FUN_00703610();
                FUN_00706320(0);
                if ((*reinterpret_cast<::Receiver86 *>(&::g_011ded3c)).FUN_00559450())
                {
                    reinterpret_cast<::Manager *>((FUN_004a0ea0()))->FUN_00b6da10((::Item *)((*reinterpret_cast<::Receiver86 *>(&::g_011ded3c)).FUN_00559450()));
                    (*reinterpret_cast<::Receiver86 *>(&::g_011ded3c)).FUN_0066b0d0(0);
                }
                if ((*reinterpret_cast<::Receiver86 *>(&::g_011dec64)).FUN_00559450())
                {
                    reinterpret_cast<::Manager *>((FUN_004a0ea0()))->FUN_00b6da10((::Item *)((*reinterpret_cast<::Receiver86 *>(&::g_011dec64)).FUN_00559450()));
                    (*reinterpret_cast<::Receiver86 *>(&::g_011dec64)).FUN_0066b0d0(0);
                }
                if ((*reinterpret_cast<::Receiver86 *>(&::g_011deb38)).FUN_00559450())
                {
                    reinterpret_cast<::Manager *>((FUN_004a0ea0()))->FUN_00b6da10((::Item *)((*reinterpret_cast<::Receiver86 *>(&::g_011deb38)).FUN_00559450()));
                    (*reinterpret_cast<::Receiver86 *>(&::g_011deb38)).FUN_0066b0d0(0);
                }
                FUN_0086bea0(0);
                if (((intptr_t)(::FUN_00683a60())))
                {
                    ::FUN_00a819e0();
                }
                reinterpret_cast<::fnv_00448420::ModelLoader *>(((*reinterpret_cast<::Receiver86 * *>(&::g_modelLoader))))->FUN_00448420();
                if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
                {
                    reinterpret_cast<::FUN_008c73a0_shell *>((((::Receiver86 *)(::FUN_00713d80()))))->FUN_008c73a0();
                }
                ::FUN_00867090();
                ::FUN_004dc560();
                ::fnv_004dc590::FUN_004dc590();
                ::fnv_00702330::FUN_00702330();
                if (((::Receiver86 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::g_TES)))))->GetBaseTexture())))
                {
                    reinterpret_cast<::SkyOwner86B *>((((::Receiver86 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Receiver86*)(*reinterpret_cast<uintptr_t *>(&::g_TES)))))->GetBaseTexture()))))->FUN_0086be30();
                }
                ::FUN_004e0800();
                ::FUN_004def20();
                ::FUN_007ffe00();
                ::FUN_00832010();
                ::FalloutAudioMedia::BeginMediaUpdate();
                ::FUN_0082f9c0();
                ((Manager86*)((::Receiver86 *)(::FUN_00453a70())))->Stop();
                ::FUN_0040fbe0();
                ::FUN_0049ff80();
                ::FUN_00622bc0();
                ::FUN_00626f10();
                if (*(*reinterpret_cast<::Setting86 *>(&::g_011d73e4)).FUN_00408d60())
                {
                    reinterpret_cast<::S_006c0900 *>((((::Receiver86 *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0900();
                }
                tesToDelete37 = (Receiver86*)(*reinterpret_cast<uintptr_t *>(&::g_TES));
                tesDeleteTarget23 = tesToDelete37;
                tesDeleteTarget23 ? reinterpret_cast<::FUN_0086bee0_class *>((tesDeleteTarget23))->FUN_0086bee0(1) : 0;
                FUN_0086beb0();
                reinterpret_cast<::Shell_006eb980 *>((((::Receiver86 *)(::GetPathManager()))))->FUN_006eb980();
                ::FUN_00651ab0();
                ::FUN_00990ff0();
                ((Manager86*)((::Manager86 *)&(::GetTaskletManager())))->Stop();
                ::FUN_00664940();
                ::FUN_00526eb0();
                ::FUN_00408de0();
                FUN_0086bdd0();
                interfaceToDelete85 = (Receiver86*)(*reinterpret_cast<uintptr_t *>(&::DAT_011d8804));
                interfaceDeleteTarget24 = interfaceToDelete85;
                interfaceDeleteTarget24 ? reinterpret_cast<::FUN_0086bf10 *>((interfaceDeleteTarget24))->DeleteThis(1) : 0;
                globalsToDelete3 = (Receiver86*)(*reinterpret_cast<unsigned char * *>(&::g_osGlobals));
                globalsDeleteTarget3 = globalsToDelete3;
                globalsDeleteTarget3 ? reinterpret_cast<::FUN_0086bf40 *>((globalsDeleteTarget3))->DeleteThis(1) : 0;
                (*reinterpret_cast<unsigned char * *>(&::g_osGlobals)) = (unsigned char*)0x0;
                ((Manager86*)((::Receiver86 *)&(::BSFileCache::GetRandomGenerator())))->Stop();
                reinterpret_cast<::FUN_005e01b0_shell *>((FUN_004de490()))->FUN_005e01b0((const char *)(void *)(((void *)(reinterpret_cast<::BaseProcess *>((FUN_004de490()))->GetCurrentProcessData()))));
                reinterpret_cast<::fnv_0086bb20::SomeClass *>((((::Receiver86 *)(::FUN_0043c4b0()))))->FUN_0086bb20((uintptr_t)(&(*reinterpret_cast<unsigned char *>(&::fnv_00872570::FUN_00872570))));
                reinterpret_cast<::FUN_0086bc10_t *>((((::Receiver86 *)(::FUN_0043c4b0()))))->FUN_0086bc10((intptr_t)(&((int (&)(...))::fnv_005d4a40::FUN_005d4a40)));
                ::FUN_006a29a0();
                ::fnv_00a62090::FUN_00a62090();
                ::FUN_00bc2960();
                ::FUN_004da4d0(1);
                FUN_0086bd00();
                ::FUN_0045b050();
                ::FUN_00c5d520();
                ::FUN_004b8cf0();
                ::FUN_00a1c790();
                ::fnv_00aa2170::FUN_00aa2170();
                new ((void *)&(shutdownText46)) ::FUN_008783c0((const char *)(void *)(&UNK_010828ec));
                reinterpret_cast<::FUN_00aa47c0_Class *>((((::Receiver86 *)(::FUN_00401020()))))->FUN_00aa47c0((intptr_t)(&shutdownText46), 0);
                result5 = 0;
                reinterpret_cast<::FUN_008784d0 *>(&(shutdownText46))->FUN_008784d0::~FUN_008784d0();
                memoryContext11.Leave();
                return result5;
            }
        }
    }
}

extern void* DAT_01082acc;

struct FUN_0086ba10_virtual
{
    virtual bool unk00();
    virtual bool unk01();
    virtual bool unk02();
    virtual bool unk03();
    virtual bool unk04();
    virtual bool unk05();
    virtual bool unk06();
    virtual bool unk07();
    virtual bool unk08();
    virtual bool unk09();
    virtual bool unk0a();
    virtual bool unk0b();
    virtual bool unk0c();
    virtual bool unk0d();
    virtual bool unk0e();
    virtual bool unk0f();
    virtual bool unk10();
    virtual bool unk11();
    virtual bool unk12();
    virtual bool unk13();
    virtual bool unk14();
    virtual bool unk15();
    virtual bool unk16();
    virtual bool unk17();
    virtual bool unk18();
    virtual bool unk19();
    virtual bool unk1a();
    virtual bool unk1b();
    virtual bool unk1c();
    virtual bool unk1d();
    virtual bool unk1e();
    virtual bool unk1f();
    virtual bool unk20();
    virtual bool unk21();
    virtual bool unk22();
    virtual bool unk23();
    virtual bool unk24();
    virtual bool unk25();
    virtual bool unk26();
    virtual bool unk27();
    virtual bool unk28();
    virtual bool unk29();
    virtual bool unk2a();
    virtual bool unk2b();
    virtual bool unk2c();
    virtual bool unk2d();
    virtual bool unk2e();
    virtual bool unk2f();
    virtual bool unk30();
    virtual bool unk31();
    virtual bool unk32();
    virtual bool unk33();
    virtual bool unk34();
    virtual bool unk35();
    virtual bool unk36();
    virtual bool unk37();
    virtual bool unk38();
    virtual bool unk39();
    virtual bool unk3a();
    virtual bool unk3b();
    virtual bool unk3c();
    virtual bool unk3d();
    virtual bool unk3e();
    virtual bool unk3f();
    virtual bool unk40();
    virtual bool unk41();
    virtual bool unk42();
    virtual bool unk43();
    virtual bool unk44();
    virtual bool unk45();
    virtual bool unk46();
    virtual bool unk47();
    virtual bool unk48();
    virtual bool unk49();
    virtual bool unk4a();
    virtual bool unk4b();
    virtual bool unk4c();
    virtual bool unk4d();
    virtual bool unk4e();
    virtual bool unk4f();
    virtual bool unk50();
    virtual bool unk51();
    virtual bool unk52();
    virtual bool unk53();
    virtual bool unk54();
    virtual bool unk55();
    virtual bool unk56();
    virtual bool unk57();
    virtual bool unk58();
    virtual bool unk59();
    virtual bool unk5a();
    virtual bool unk5b();
    virtual bool unk5c();
    virtual bool unk5d();
    virtual bool unk5e();
    virtual bool unk5f();
};

struct FUN_0086ba10_fields
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
};

struct FUN_0086ba10_target
{
    bool FUN_0086ba10();
};

// Calls FUN_0086ba60 with DAT_01082acc and 0, then unk5f; on success sets unk200 to 2 and returns true.
// @fnv 0x0086ba10
bool FUN_0086ba10_target::FUN_0086ba10()
{
    if (!reinterpret_cast<FUN_0086ba60_Class*>(this)->FUN_0086ba60(&DAT_01082acc, 0))
        return false;

    if (!reinterpret_cast<FUN_0086ba10_virtual*>(this)->unk5f())
        return false;

    reinterpret_cast<FUN_0086ba10_fields*>(this)->unk200 = 2;
    return true;
}


// If the global object pointer DAT_011f81dc is non-null, calls its FUN_0086bd40 method with 1.
// @fnv 0x0086bd00
void __cdecl FUN_0086bd00(void)
{
    if ((*reinterpret_cast<::FUN_0086bd40_class * *>(&::g_fileFinder)))
    {
        FUN_0086bd40_class* pObject = (*reinterpret_cast<::FUN_0086bd40_class * *>(&::g_fileFinder));
        FUN_0086bd40_class* pThis = pObject;

        {
            void* pResult;
            if (pThis)
            {
                pResult = pThis->FUN_0086bd40(1);
            }
            else
            {
                pResult = 0;
            }
        }
    }
}

using MemScope = ::AutoMemContext;
struct UpdateInfo
{
    float time;
    int flags;
    int unk08;
    UpdateInfo(float, bool, bool);
};
struct ScenePart
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual ScenePart* AsNode();
    void Update(UpdateInfo&);
};
struct SkyInit
{
};
int FUN_0086d470();
struct WorldInit
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    WorldInit(const char*, int, ScenePart*, SkyInit*, int);
};
struct TaskInit
{
};
void FUN_00526e10();
void FUN_00990f20();
struct InitSetting
{
    bool* Bool();
};
struct FileInit
{
};
struct HandlerInit
{
};
extern intptr_t DAT_011a2ffc;
int* FUN_0086d480();
struct PointInit
{
    float x, y, z;
    PointInit(float, float, float);
};
struct ValueInit
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct PlayerInit
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void Refresh();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void SetID(unsigned int, bool);
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void SetAngles(const PointInit&);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    ValueInit values;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    PlayerInit();
    void Position(const PointInit&);
};

class TESNPC : public TESForm
{
};
struct TimeInit
{
};
struct BootInit
{
    void FUN_0086cf20(ScenePart*);
};
// Initializes the game world, plugins, player, terrain, and scripts in sequence, logging each stage.
// @fnv 0x0086cf20
void BootInit::FUN_0086cf20(ScenePart* scene)
{
    MemScope memory5(10, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0xe4f);
    memory5.Enter(10, true, (char *)("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp"), 0xe51);
    DAT_011dea20 = ((::SkyInit *)(::Sky::GetInstance()));
    ::fnv_00877730::FUN_00877730();
    int mode = FUN_0086d470();
    ScenePart* root_2 = reinterpret_cast<::ScenePart *>(::DAT_011dea14);
    if (root_2)
    {
        ::FUN_00a89af0((std::intptr_t)(((::ScenePart *)(reinterpret_cast<::FUN_004505a0_cls *>((DAT_011dea20))->FUN_004505a0()))));
        ScenePart* child4 = ((::ScenePart *)(reinterpret_cast<::S_FUN_0045bc00 *>((root_2))->FUN_0045bc00(0)));
        root_2 = child4 ? child4->AsNode() : 0;
    }
    ::FUN_0040fbe0();
    (*reinterpret_cast<::WorldInit * *>(&::g_TES)) = new WorldInit("DATA\\", mode, root_2, DAT_011dea20, DAT_011dea1c);
    memory5.Leave();
    reinterpret_cast<::FUN_00450c50_Class *>(((*reinterpret_cast<::WorldInit * *>(&::g_TES))))->FUN_00450c50();
    ::FUN_0040fbe0();
    ::BSTreeManager::Create(false);
    ::FUN_0040fbe0();
    reinterpret_cast<::FUN_00b00df0_cls *>(&((*(::TaskInit *)&(::GetTaskletManager()))))->ReleaseAndSignal();
    FUN_00526e10();
    FUN_00990f20();
    memory5.Enter(25, true, (char *)("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp"), 0xe85);
    reinterpret_cast<::FUN_00a5a040_Class *>((scene))->FUN_00a5a040();
    UpdateInfo update9(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((scene))->FUN_00a59c60((std::intptr_t)&(update9));
    memory5.Leave();
    bool found3 = false;
    InitSetting* plugins3[10] = {&(*reinterpret_cast<::InitSetting *>(&::g_011debf0)), &(*reinterpret_cast<::InitSetting *>(&::g_011deb88)), &(*reinterpret_cast<::InitSetting *>(&::g_011decf8)), &(*reinterpret_cast<::InitSetting *>(&::g_011dee9c)), &(*reinterpret_cast<::InitSetting *>(&::g_011dec34)),
                                 &(*reinterpret_cast<::InitSetting *>(&::g_011dee0c)), &(*reinterpret_cast<::InitSetting *>(&::g_011ded14)), &(*reinterpret_cast<::InitSetting *>(&::g_011dee48)), &(*reinterpret_cast<::InitSetting *>(&::g_011dea70)), &(*reinterpret_cast<::InitSetting *>(&::g_011ded48))};
    for (int index2 = 0; index2 < 10; ++index2)
    {
        if (((const char *)(reinterpret_cast<::StartMenu *>((plugins3[index2]))->GetMenuTitle())) && strlen(((const char *)(reinterpret_cast<::StartMenu *>((plugins3[index2]))->GetMenuTitle()))))
        {
            FileInit* aFile = ((::FileInit *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::HandlerInit * *>(&::g_dataHandler))))->LookupTESFile(((const char *)(::FUN_00464f30((intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>((plugins3[index2]))->GetMenuTitle())))))))));
            if (aFile)
            {
                reinterpret_cast<::EffectSettingCollection *>((aFile))->InitializeCollection(true);
                found3 = true;
            }
        }
    }
    if (reinterpret_cast<::PluginListReader *>(this)->FUN_00872430((const char *)(int *)(FUN_0086d480()), (const char *)(DAT_011a2ffc)))
        found3 = true;
    if (!found3)
    {
        FileInit* _fallback = ((::FileInit *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::HandlerInit * *>(&::g_dataHandler))))->LookupTESFile("Fallout.esm")));
        if (_fallback)
            reinterpret_cast<::EffectSettingCollection *>((_fallback))->InitializeCollection(true);
    }
    memory5.Enter(52, true, (char *)("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp"), 0xecb);
    (*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer)) = new PlayerInit;
    (*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer))->SetID(20, true);
    memory5.Leave();
    ::FUN_0040fbe0();
    reinterpret_cast<::fnv_00463070::FUN_00463070_shell *>(((*reinterpret_cast<::HandlerInit * *>(&::g_dataHandler))))->LoadDataFiles(false);
    ::ChallengeManager::CheckCompletedChallenges();
    reinterpret_cast<::AddonOwner *>(((*reinterpret_cast<::WorldInit * *>(&::g_TES))))->FUN_00459f10();
    reinterpret_cast<::fnv_0045a370::TextureLoader *>(((*reinterpret_cast<::WorldInit * *>(&::g_TES))))->FUN_0045a370();
    if (*(*reinterpret_cast<::InitSetting *>(&::g_011c7adc)).Bool())
        reinterpret_cast<::WaterTextureLoader *>(((*reinterpret_cast<::WorldInit * *>(&::g_TES))))->LoadWaterTextures();
    reinterpret_cast<::fnv_0045a1e0::Target45 *>(((*reinterpret_cast<::WorldInit * *>(&::g_TES))))->QueueLoadForAll();
    ::BSTempEffectSimpleDecal::QueueDecalDataFile();
    ::FUN_0040fbe0();
    memory5.Enter(52, true, (char *)("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp"), 0xf00);
    {
        TESNPC* base2 = dynamic_cast<TESNPC*>(::FUN_004839c0(7));
        reinterpret_cast<::Fn575690 *>(((*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer))))->FUN_00575690(base2);
        (*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer))->SetAngles(PointInit(2048.0f, 2048.0f, 0.0f));
        reinterpret_cast<::fnv_0086d490::FUN_0086d490_class *>(((*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer))))->impl((const ::fnv_0086d490::NiPoint3_local &)((*reinterpret_cast<::PointInit *>((void *)&::NiPoint3::ZERO))));
        (*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer))->Refresh();
        reinterpret_cast<::ActorSpellView *>(((*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer))))->UpdateSpells(false);
        int healthB = (*reinterpret_cast<::PlayerInit * *>(&::_g_thePlayer))->values.Get(16);
        if (!healthB)
            ::FUN_0040fbe0();
    }
    ::FUN_0040fbe0();
    reinterpret_cast<::FUN_00465040_shell *>(((*reinterpret_cast<::HandlerInit * *>(&::g_dataHandler))))->InitAllScripts();
    if (reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::InitSetting *>(&::g_011dee60))))->GetCellStandValue() > 0 && reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::InitSetting *>(&::g_011dee60))))->GetCellStandValue() < 200)
        ::fnv::timer::SetFrequency(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::InitSetting *>(&::g_011dee60)))))));
}

namespace FrameUpdate {
struct Service;
struct Values
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct Service
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void Update();
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
    virtual void Advance(float);
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void* Position();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    Values values;
    bool FUN_00701450(bool);
    bool FUN_00451530();
    Service* FUN_00559450();
    int* FUN_0043d4d0();
    void FUN_00712e60(void*);
    int FUN_0044ddc0();
    void* FUN_006629f0();
    bool* FUN_00408d60();
    void* FUN_008d6f30();
};
Service* __cdecl FUN_00af2640();
Service* __cdecl FUN_004a0ea0();
Service* __cdecl FUN_0049fef0();
extern bool DAT_011deefc;
extern bool DAT_011c6fbb;
extern unsigned char DAT_011deef5;
extern float DAT_011a3010, DAT_011deef8;
struct MainLoop
{
    int unk00;
    char unk04, unk05, unk06;
    bool paused;
    void FUN_0086f940();
    void FUN_00483710();
    void FUN_00871dc0();
    void FUN_0086ff70();
    void FUN_0086e650();
};
// @fnv 0x0086e650
void MainLoop::FUN_0086e650()
{
    reinterpret_cast<::FUN_0086a830_S *>(this)->FUN_0086a830(DAT_011a3010);
    short key4;
    key4 = GetAsyncKeyState(9);
    if ((key4 >> 15) & 1)
    {
        key4 = GetAsyncKeyState(18);
        if ((key4 >> 15) & 1)
            return;
    }
    FUN_00af2640()->Update();
    ::DAT_011dea2b = ::FUN_00702360() || ::FUN_00709bc0();
    DAT_011dea2c = ::fnv_007050d0::FUN_007050d0();
    ::DAT_011dea2d = reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::DAT_011d8804))))->HasFader((::FADER_ENUM)(true));
    ::DAT_011dea2e = ::fnv_00703d50::FUN_00703d50();
    bool differentMenu = ((void *)(::FUN_00707ad0())) && ((void *)(::FUN_00707ad0())) != ((void *)(::fnv_00705990::FUN_00705990()));
    if (((signed char)(reinterpret_cast<::FUN_00424940_shell *>((((::FrameUpdate::Service *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00424940())) == 3 && !differentMenu)
        ::ActorReferenceArray::SetupActorReferences();
    FUN_0086f940();
    reinterpret_cast<::FUN_006ff860_Class *>((((::FrameUpdate::Service *)(::FUN_006ff580()))))->FUN_006ff860();
    reinterpret_cast<::fnv_0086fd90::FUN_0086fd90_shell *>(this)->FUN_0086fd90(!::DAT_011dea2b && !paused);
    ::DAT_011dea2b = ::FUN_00702360() || ::FUN_00709bc0();
    DAT_011dea2c = ::fnv_007050d0::FUN_007050d0();
    ::DAT_011dea2d = reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::DAT_011d8804))))->HasFader((::FADER_ENUM)(true));
    ::DAT_011dea2e = ::fnv_00703d50::FUN_00703d50();
    if (DAT_011deefc)
        ::fnv_006da7c0::FUN_006da7c0((::fnv_006da7c0::CellOps *)(void *)(((void *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::_g_thePlayer))))->GetTarget()))), (*(const ::NiPoint3 *)((*reinterpret_cast<::FrameUpdate::Service * *>(&::_g_thePlayer))->Position())), 2, 100);
    reinterpret_cast<::BGSSaveLoadManager *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::DAT_011de134))))->ProcessQueuedSaveLoad();
    ::FUN_0086ef30();
    ::FUN_0086ef90();
    reinterpret_cast<::B86F190Owner *>(this)->FUN_0086f190();
    reinterpret_cast<::TESForm *>(this)->ClearData();
    ::FUN_004e1610();
    ++::DAT_011a2fe0;
    DAT_011df674 = 0;
    if (!::DAT_011dea2b)
        ::FUN_0086ef40();
    reinterpret_cast<::fnv_0086f260::Mover *>(this)->FUN_0086f260();
    reinterpret_cast<::fnv_0086f390::FUN_0086f390_shell *>(this)->FUN_0086f390();
    reinterpret_cast<::fnv_00c3dbf0::IOManager *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::DAT_01202d98))))->FUN_00c3dbf0();
    if (!::FUN_0086efa0())
    {
        if (::FUN_0070edf0())
            ::LoadingMenu::UpdateLoadingScreenThread();
        else if (::Interface::IsInterfaceActive())
            reinterpret_cast<::S457d70 *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::g_TES))))->FUN_00457d70(0, (::Form457 *)(0), 0);
    }
    reinterpret_cast<::fnv_0086efe0::FUN_0086efe0_t *>(this)->FUN_0086efe0();
    reinterpret_cast<::FUN_00b6dd00_Owner *>((FUN_004a0ea0()))->FUN_00b6dd00((intptr_t)(((::FrameUpdate::Service *)(::FUN_00524c90()))), ::DAT_011dea2b);
    reinterpret_cast<::NiParallelUpdateTaskManager *>(this)->DispatchParallelUpdates();
    reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::DAT_011d8804))))->AdvanceFaders(true);
    if (!::DAT_011dea2b && !paused)
    {
        ::FUN_004e0110();
        ::FUN_004de600();
    }
    if (((intptr_t)(::FUN_00683a60())))
        ::FUN_00a81a20();
    if (!::DAT_011dea2b && !paused)
    {
        if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::g_TES))))->FUN_00451530() && !((bool)(reinterpret_cast<::FUN_0086ef70_Class *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::g_TES))))->FUN_0086ef70())))
            reinterpret_cast<::BatchTES *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::g_TES))))->FUN_004556d0(0);
        (*reinterpret_cast<::FrameUpdate::Service *>(&::g_011deb7c)).FUN_00559450()->Advance(::fnv::timer::Seconds());
        reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011de7b8))))->Update(::fnv::timer::Seconds());
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011c3ea4)))))) == 1)
            reinterpret_cast<::FUN_00455640_shell *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::g_TES))))->FUN_00455640();
    }
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::fnv_00978550::FUN_00978550_shell *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->FUN_00978550();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011c3ea4)))))) != 1)
    {
        if ((!::DAT_011dea2b || ::DAT_011dea2d) && !::DAT_011dea2e && !paused)
        {
            reinterpret_cast<::ActorReferenceArray *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->ResetActorReferences();
            reinterpret_cast<::fnv_0096eb40::FUN_0096eb40_cls *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->FUN_0096eb40();
            reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->UpdateFollowerTempList();
        }
    }
    else
    {
        if ((!::DAT_011dea2b || ::DAT_011dea2d) && !::DAT_011dea2e && !paused)
        {
            reinterpret_cast<::ActorReferenceArray *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->ResetActorReferences();
            reinterpret_cast<::FUN_008d0600_s *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->FUN_008d0600(0.0f, 0);
            reinterpret_cast<::fnv_0096eb40::FUN_0096eb40_cls *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->FUN_0096eb40();
            reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011e0e80))))->UpdateFollowerTempList();
        }
    }
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::DAT_011f11a0))))->FUN_0040fba0();
    reinterpret_cast<::FUN_00878080_Class *>((((::FrameUpdate::Service *)(::FUN_00446ef0()))))->FUN_00878080(true);
    if (((bool)(::FUN_0086ef60())))
        ::FUN_00a61cd0();
    ::GarbageCollector::Update();
    ::GarbageCollector::ClearTempEffects();
    ::fnv_006652e0::FUN_006652e0((::fnv_006652e0::NiAVObject *)(::FrameUpdate::Service *)(((::FrameUpdate::Service *)(::FUN_00524c90()))), ::DAT_011dea2b || paused);
    reinterpret_cast<::fnv_0086fbe0::MainStandIn *>(this)->FUN_0086fbe0();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011c3ea4)))))) == 1)
        ::FUN_0086fd70((void *)this);
    reinterpret_cast<::TESForm *>(this)->ClearData();
    ::FUN_0049fff0((::BGSDecalManager *)(FUN_0049fef0()));
    ((::FrameUpdate::Service *)(::FUN_00524c90()))->FUN_00712e60(&::DAT_011ad840);
    if (reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode != 4)
        reinterpret_cast<::C52020Obj *>((((::FrameUpdate::Service *)(::FUN_0045c670()))))->FUN_00c52020(::FUN_00710ab0((::FUN_00710ab0_Class *)((*reinterpret_cast<::FrameUpdate::Service * *>(&::_g_thePlayer)))), 0, (::C52020Obj *)(0), true);
    ::BSShaderManager::SetFOV(::FUN_00710ab0((::FUN_00710ab0_Class *)((*reinterpret_cast<::FrameUpdate::Service * *>(&::_g_thePlayer)))));
    void* sceneB = (*reinterpret_cast<::FrameUpdate::Service *>(&::g_011deb7c)).FUN_00559450()->FUN_006629f0();
    void* replacement5 = 0;
    reinterpret_cast<::fnv_0045bc80::ThisC *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::g_TES))))->FUN_0045bc80(true, true);
    reinterpret_cast<::FUN_00b5ac90_t *>((((::FrameUpdate::Service *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5ac90((::SSCamera *)(replacement5 ? replacement5 : sceneB));
    reinterpret_cast<::SceneUpdate::World *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::g_TES))))->FUN_0045b070((::SceneUpdate::View *)(replacement5 ? replacement5 : sceneB));
    bool update = (!::DAT_011dea2b || ::DAT_011dea2d) && !::DAT_011dea2e && !paused;
    if (update)
    {
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011c3ea4)))))) > 1)
        {
            ::AIThreadManager::SetThreadingEnabled(true);
            reinterpret_cast<::FUN_008c78c0_Class *>((((::FrameUpdate::Service *)(::FUN_00713d80()))))->FUN_008c78c0();
        }
        else
            reinterpret_cast<::fnv_008ca070::Obj *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::DAT_011e0fe0))))->FUN_008ca070();
    }
    reinterpret_cast<::fnv_0086fc60::FUN_0086fc60_shell *>(this)->FUN_0086fc60();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011c3ea4)))))) > 1 && !update)
    {
        ::FUN_0086fd70((void *)this);
        if (::FUN_00702360())
            ::fnv_007058e0::FUN_007058e0();
    }
    if (!paused)
        reinterpret_cast<::ScriptLocals *>((((::FrameUpdate::Service *)(::GetPathManager()))))->ProcessPendingTasks();
    reinterpret_cast<::FUN_006a61b0_cls *>((((::FrameUpdate::Service *)(::FUN_00552ba0()))))->FUN_006a61b0();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011c3ea4)))))) == 1)
    {
        if (*(*reinterpret_cast<::FrameUpdate::Service *>(&::g_011d73e4)).FUN_00408d60())
            reinterpret_cast<::fnv_006c3640::C006c3640 *>((((::FrameUpdate::Service *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c3640();
        reinterpret_cast<::FUN_00991500_shell *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00991500(::DAT_011dea2b || ::DAT_011dea2d || paused);
    }
    if (::FUN_00714a00())
        ::FUN_00a81a80();
    if (::fnv_007023c0::FUN_007023c0() == 0x3f4 && ::fnv_007056f0::FUN_007056f0())
        FUN_00871dc0();
    ::fnv_0057ab70::FUN_0057ab70();
    ::FUN_00b60040();
    int mode4 = ::fnv_0047e040::FUN_0047e040((float)(*reinterpret_cast<::FrameUpdate::Service * *>(&::_g_thePlayer))->values.Get(23));
    if (mode4 > 2)
    {
        if (mode4 == 3)
            mode4 = 0;
        else
            mode4 = 2;
    }
    FUN_0086ff70();
    ::fnv_008705d0::FUN_008705d0((void *)this);
    if (DAT_011c6fbb)
    {
        ::RecreateRenderDevice();
        DAT_011c6fbb = false;
    }
    if ((!::DAT_011dea2b || ::DAT_011dea2d) && !::DAT_011dea2e && !paused)
    {
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FrameUpdate::Service *>(&::g_011c3ea4)))))) > 1)
            reinterpret_cast<::FUN_008c7990_Class *>((((::FrameUpdate::Service *)(::FUN_00713d80()))))->FUN_008c7990();
        else
            reinterpret_cast<::FUN_008ca300_shell *>(&((*reinterpret_cast<::FrameUpdate::Service *>(&::DAT_011e0fe0))))->FUN_008ca300();
    }
    reinterpret_cast<::fnv_0086f6a0::FUN_0086f6a0_shell *>(this)->FUN_0086f6a0();
    reinterpret_cast<::fnv_00870610::FUN_00870610_shell *>(this)->FUN_00870610();
    if (((bool)(::FUN_0070ed10())))
    {
        ::FUN_0070ed20(0);
        ::fnv_00703e10::FUN_00703e10();
    }
    ::FUN_00a29680();
    ::FUN_005ae270();
    ::FUN_005a9d60();
    DAT_011deef8 += ::fnv::timer::Seconds();
    if (::FUN_00702360() || ((*reinterpret_cast<::FrameUpdate::Service * *>(&::_g_thePlayer)) && ((bool)(reinterpret_cast<::FUN_00950090_Class *>(((*reinterpret_cast<::FrameUpdate::Service * *>(&::_g_thePlayer))))->FUN_00950090()))) || DAT_011deef8 >= 45.0)
    {
        DAT_011deef8 = 0.0f;
        ::FUN_00aa7290(DAT_011deef5++);
        if (DAT_011deef5 == 256)
            DAT_011deef5 = 0;
    }
}
}

namespace fnv_008707c0 {
typedef ImageSpaceManager ISMgr;
struct Rend;
struct RootNode;
struct AnimData;
struct StrObj
{
    operator const char*() const;
};

struct MTHelper
{
};

struct RMenu
{
};

struct FNode
{
};
struct FGen
{
};
struct SSN
{
};

struct RenderMgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    void* name;

    void FUN_00871290();
    int FUN_00872f50(Rend* r, void* p1, bool p2, bool b);
    void FUN_00874c10();
    void FUN_00875110(Rend* r, RootNode* root, int z, int res);
    void FUN_00875bf0();
    void FUN_00875fd0(bool b, int res, Rend* r, void* p1);
    void FUN_008761e0(RootNode* root, Rend* r);

    void FUN_008707c0(void* p1, bool p2);
};

// Runs the render update: resets helpers, computes a result via FUN_00872f50, sets up a node when FUN_00705a00 is true, and dispatches the remaining render steps.
// @fnv 0x008707c0
void RenderMgr::FUN_008707c0(void* p1, bool p2)
{
    ISMgr* ism2 = ::ImageSpaceManager::FUN_004e3270();
    Rend* renderer = ((::fnv_008707c0::Rend *)(::FUN_0043c4b0()));
    bool flag_ = ::FUN_004dc310();
    RootNode* root2 = ((::fnv_008707c0::RMenu *)(::FUN_00707ad0())) ? ((::fnv_008707c0::RootNode *)(reinterpret_cast<::StrOwner *>((((::fnv_008707c0::RMenu *)(::FUN_00707ad0()))))->FUN_007fa950())) : 0;
    reinterpret_cast<::NiParallelUpdateTaskManager *>(this)->SetupTaskWorkers();
    for (int i4 = 1; i4 < 0x11; i4++)
    {
        reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_008707c0::MTHelper *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, i4);
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_008707c0::MTHelper *)(::TaskThreadManager::GetSingleton()))), (void *)(1), i4, {});
    }
    FUN_00871290();
    intptr_t res4 = FUN_00872f50(renderer, p1, p2, flag_);
    reinterpret_cast<::fnv_00874b90::FUN_00874b90_shell *>(this)->FUN_00874b90((::fnv_00874b90::ImageSpaceManager *)(ism2), (::fnv_00874b90::GraphicsRenderer *)(renderer), flag_, (::fnv_00874b90::BSRenderedTexture *)(p1));
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
        ::AIThreadManager::SetThreadingEnabled(0);
    reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_008707c0::MTHelper *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, 0x15);
    ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_008707c0::MTHelper *)(::TaskThreadManager::GetSingleton()))), (void *)(1), 0x15, {});
    if (::fnv_00705a00::FUN_00705a00())
    {
        AnimData* anim3 = ((::fnv_008707c0::AnimData *)(::FUN_00524c90()));
        FGen* fg7 = (FGen*)((::BSFaceGenNiNode *)(::FUN_0045c670()));
        FNode* pNode = ((::fnv_008707c0::FNode *)(reinterpret_cast<::SceneGraph *>(fg7)->cullingProcess));
        reinterpret_cast<::FUN_004a0fd0_shell *>((pNode))->FUN_004a0fd0((::NiNode *)(name));
        reinterpret_cast<::FUN_0041fd00_shell *>((pNode))->FUN_0041fd00((intptr_t)(anim3));
        reinterpret_cast<::fnv_00b5e870::Self *>((((::fnv_008707c0::SSN *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5e870((::fnv_00b5e870::ParamObj *)(pNode));
        FUN_00874c10();
        FUN_00875110(renderer, root2, 0, res4);
    }
    else
    {
        reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_008707c0::MTHelper *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, 0x16);
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_008707c0::MTHelper *)(::TaskThreadManager::GetSingleton()))), (void *)(1), 0x16, {});
    }
    FUN_00875bf0();
    if (::FUN_008709f0() && !p2)
    {
        FUN_00875fd0(flag_, res4, renderer, p1);
        if (root2)
            FUN_008761e0(root2, renderer);
    }
    else if (p1)
    {
        reinterpret_cast<::fnv_00876830::BSRenderedTexture *>(this)->FUN_00876830(flag_, (std::intptr_t)(p1));
    }
    reinterpret_cast<::fnv_00876850::FUN_00876850_shell *>(this)->FUN_00876850((::fnv_00876850::BSRenderedTexture *)(res4), (::fnv_00876850::ImageSpaceManager *)(ism2), (::fnv_00876850::GraphicsRenderer *)(renderer), (::fnv_00876850::Sun *)(0));
}
}  // namespace fnv_008707c0

struct RendererStub870;
struct ISManagerStub870;
struct RTexStub870;
struct TexStub870;

struct AVObjStub870
{
};
struct PlayerStub870
{
};

struct MenuStub870
{
};
struct RenderSysStub870
{
};


struct SceneRendererStub870
{
    TexStub870* GetTexture();
    void ShaderPassEntry(TexStub870* tex, bool draw, bool unk, bool x);
    void Finish1();
    void Composite(RendererStub870* renderer, int unk, TexStub870* tex, RTexStub870* rt);
    void RenderAlt(bool flag, RTexStub870* rt, RendererStub870* renderer, TexStub870* target);

    void FUN_00870a00(TexStub870* target, bool skip);
};

struct ShadowActor;
struct ShadowNode;
struct ShadowView;
struct ShadowMap;
struct ShadowVector
{
    float x, y, z;
};
struct ShadowBound
{
    float x, y, z, radius;
};
struct ShadowUpdate
{
    float time;
    int flags, frame;
    ShadowUpdate(float, bool, bool);
};
struct ShadowExtra
{
};
struct ShadowTransform
{
};
struct ShadowNode
{
    const ShadowVector& FUN_0045bb80();
};
struct ShadowView
{
};
struct ShadowScene
{
    ShadowTransform* FUN_006629f0();
};
struct ShadowMap
{
    void UpdateOutputLight(int, ShadowVector);
};
struct ShadowSystem
{
};
struct ShadowRenderer
{
};
struct ShadowTarget
{
};
struct ShadowEnvironment
{
};
struct ShadowIntSetting
{
    int* FUN_0043d4d0();
};
struct ShadowBoolSetting
{
    bool* FUN_00408d60();
};
struct ShadowLock
{
};
struct ShadowActors
{
};
extern bool DAT_011def08;
const double DAT_01021928 = 3.0;
const double DAT_01082cb0 = 0.05;
void FUN_005bf770(bool);
void FUN_00b4f570();
ShadowRenderer* FUN_004a0ea0(void*);
struct ShadowActor
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SlotAC();
    virtual void SlotB0();
    virtual void SlotB4();
    virtual void SlotB8();
    virtual void SlotBC();
    virtual void SlotC0();
    virtual void SlotC4();
    virtual void SlotC8();
    virtual void SlotCC();
    virtual void SlotD0();
    virtual void SlotD4();
    virtual void SlotD8();
    virtual void SlotDC();
    virtual void SlotE0();
    virtual void SlotE4();
    virtual void SlotE8();
    virtual void SlotEC();
    virtual void SlotF0();
    virtual void SlotF4();
    virtual void SlotF8();
    virtual void SlotFC();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10C();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11C();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12C();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13C();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14C();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15C();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16C();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17C();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18C();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19C();
    virtual void Slot1A0();
    virtual void Slot1A4();
    virtual void Slot1A8();
    virtual void Slot1AC();
    virtual void Slot1B0();
    virtual void Slot1B4();
    virtual void Slot1B8();
    virtual void Slot1BC();
    virtual void Slot1C0();
    virtual void Slot1C4();
    virtual void Slot1C8();
    virtual void Slot1CC();
    virtual ShadowNode* Get3D();
    virtual void Slot1D4();
    virtual void Slot1D8();
    virtual void Slot1DC();
    virtual void Slot1E0();
    virtual void Slot1E4();
    virtual void Slot1E8();
    virtual void Slot1EC();
    virtual void Slot1F0();
    virtual void Slot1F4();
    virtual void Slot1F8();
    virtual void Slot1FC();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20C();
    virtual void Slot210();
    virtual int GetState();
};
struct ShadowHost
{
    void FUN_00871290();
    void FUN_00871a50();
};
// Toggles shadow rendering based on two flags, builds the shadow map from actors, renders visible shadow maps up to a limit, and resets unused shadow targets.
// @fnv 0x00871290
void ShadowHost::FUN_00871290()
{
    if (((bool)(::fnv_005bf7b0::FUN_005bf7b0())) && ((bool)(::FUN_00525420())))
    {
        DAT_011def08 = ((bool)(::fnv_005bf7b0::FUN_005bf7b0()));
        FUN_005bf770(false);
        ShadowSystem* system = ((::ShadowSystem *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
        ::FUN_00b5b1f0((::ShadowSceneNode *)(system), {});
        reinterpret_cast<::TexturePool *>((FUN_004a0ea0(((void *)(::FUN_0043c4b0())))))->ResizeActivePool({}, {});
    }
    else if (DAT_011def08 && !((bool)(::FUN_00525420())))
    {
        DAT_011def08 = false;
        FUN_005bf770(true);
        int limit = ((intptr_t)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::ShadowEnvironment * *>(&::g_TES))))->GetPrevPath())) ? *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ShadowIntSetting *>(&::g_011c72d8)))))) : *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ShadowIntSetting *>(&::g_011c72e4))))));
        reinterpret_cast<::TexturePool *>((FUN_004a0ea0(((void *)(::FUN_0043c4b0())))))->ResizeActivePool({}, {});
    }
    if (((bool)(::fnv_005bf7b0::FUN_005bf7b0())) && ((bool)(::fnv_00871a10::FUN_00871a10())))
    {
        FUN_00b4f570();
        ShadowSystem* system = ((::ShadowSystem *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
        ::FUN_00b5b060((char *)(system), {});
        int limit = ((intptr_t)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::ShadowEnvironment * *>(&::g_TES))))->GetPrevPath())) ? *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ShadowIntSetting *>(&::g_011c72d8)))))) : *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ShadowIntSetting *>(&::g_011c72e4))))));
        reinterpret_cast<::TexturePool *>((FUN_004a0ea0(((void *)(::FUN_0043c4b0())))))->ResizeActivePool({}, {});
        if (!limit)
            reinterpret_cast<::ShadowSceneNode *>((system))->UpdateShadowLights();
        else
        {
            void* playerShadow32 = 0;
            int count33 = 0;
            if ((reinterpret_cast<::FUN_004eaf60_shell *>(((*reinterpret_cast<::ShadowActor * *>(&::_g_thePlayer))))->FUN_004eaf60() || ((bool)(reinterpret_cast<::FUN_00950090_Class *>(((*reinterpret_cast<::ShadowActor * *>(&::_g_thePlayer))))->FUN_00950090()))) && !reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::ShadowActor * *>(&::_g_thePlayer))))->FUN_008c51c0())
            {
                playerShadow32 = ((void *)(reinterpret_cast<::fnv_00b5cbd0::ShadowSceneNode_Self *>((system))->FUN_00b5cbd0(((::ShadowNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::ShadowActor * *>(&::_g_thePlayer))))->FUN_00950bb0(0))))));
                ++count33;
            }
            reinterpret_cast<::FUN_0040fbf0_shell *>(&(DAT_011f1180))->FUN_0040fbf0((char *)(0));
            ShadowActor** actors8 = ((::ShadowActor **)(::FUN_00871a30((intptr_t)(((ShadowActors*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))));
            int actorCount72 = ::FUN_00472380((intptr_t)(((ShadowActors*)&(*reinterpret_cast<int *>(&::g_011e0e80)))));
            for (int i = 0; i < actorCount72 && count33 < limit; ++i)
            {
                ShadowActor* actor = actors8[i];
                if (actor->Get3D() && reinterpret_cast<::FUN_009611e0_shell *>((actor->Get3D()))->FUN_009611e0() && reinterpret_cast<::B87F200Projectile *>((actor))->FUN_0087f200() &&
                    actor->GetState() != 4 && !reinterpret_cast<::FUN_008c51c0_shell *>((actor))->FUN_008c51c0())
                {
                    ShadowExtra* extra6 = ((::ShadowExtra *)(reinterpret_cast<::NiAVObject *>((actor->Get3D()))->GetExtraData((*(const ::NiFixedString *)(FUN_0050ea90())))));
                    ShadowVector dimensions4 = extra6 ? (*(const ::ShadowVector *)(reinterpret_cast<::BGSCameraPath *>((extra6))->GetConditions())) : (*reinterpret_cast<const ::ShadowVector *>((void *)&::NiPoint3::ZERO));
                    float maximum37 = FUN_00404010(FUN_00404010(dimensions4.x, dimensions4.y), dimensions4.z);
                    if (maximum37 * DAT_01021928 > reinterpret_cast<::Twin_0084d030 *>((((::ShadowBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((actor->Get3D()))->FUN_0043d450()))))->GetStoredFloatValue())
                    {
                        reinterpret_cast<::fnv_00b5cbd0::ShadowSceneNode_Self *>((system))->FUN_00b5cbd0(actor->Get3D());
                        ++count33;
                    }
                }
            }
            reinterpret_cast<::RecursiveSpinLock *>(&(DAT_011f1180))->FUN_0040fba0();
            reinterpret_cast<::SSN_cand *>((system))->FUN_00b5cde0((::MyShadowSceneLight *)(playerShadow32));
            ShadowNode* playerNode50 = ((::ShadowNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::ShadowActor * *>(&::_g_thePlayer))))->FUN_00950bb0(1)));
            if (playerNode50)
            {
                ShadowScene* scene9 = (ShadowScene*)((::BSFaceGenNiNode *)(::FUN_0045c670()));
                ShadowView* view8 = ((::ShadowView *)(reinterpret_cast<::SceneGraph *>(scene9)->cullingProcess));
                reinterpret_cast<::FUN_0041fd00_shell *>((view8))->FUN_0041fd00(reinterpret_cast<std::intptr_t>(scene9->FUN_006629f0()));
                reinterpret_cast<::S694a0 *>((view8))->FUN_00a694a0(((void *)&(reinterpret_cast<::NiCamera *>((scene9->FUN_006629f0()))->GetViewFrustum())));
                bool playerHidden14 = reinterpret_cast<::FUN_00456630_helper *>((playerNode50))->FUN_00456610();
                reinterpret_cast<::TaskQueueInterface *>((playerNode50))->QueueActorDisarm(true);
                ShadowNode* specialNode3 = ((::ShadowNode *)(::FUN_0054f4c0()));
                ::FUN_004e20b0(false);
                bool specialHidden29 = false;
                if (specialNode3)
                {
                    specialHidden29 = reinterpret_cast<::FUN_00456630_helper *>((specialNode3))->FUN_00456610();
                    if (!*(*reinterpret_cast<::ShadowBoolSetting *>(&::g_011c71dc)).FUN_00408d60())
                        reinterpret_cast<::TaskQueueInterface *>((specialNode3))->QueueActorDisarm(true);
                }
                ShadowMap* shadow4 = ((::ShadowMap *)(reinterpret_cast<::S_Cls *>((system))->FUN_00b5afc0()));
                intptr_t rendered62 = 0;
                while (shadow4)
                {
                    if (((::ShadowNode *)(::fnv_004e6540::FUN_004e6540((char *)(shadow4)))) && ((::ShadowNode *)(reinterpret_cast<::FUN_005bf820_Class *>((shadow4))->FUN_005bf820())))
                    {
                        if (!reinterpret_cast<::FUN_004e6580_shell *>((shadow4))->FUN_004e6580() && reinterpret_cast<::FUN_00456630_helper *>((((::ShadowNode *)(::fnv_004e6540::FUN_004e6540((char *)(shadow4))))))->FUN_00456610())
                        {
                            if (reinterpret_cast<::FUN_00456630_helper *>((((::ShadowNode *)(reinterpret_cast<::FUN_005bf820_Class *>((shadow4))->FUN_005bf820()))))->FUN_00456610())
                                reinterpret_cast<::B9BB10Effect *>((shadow4))->FUN_00b9bb10(0.0f, true);
                            else
                            {
                                if (rendered62 < limit)
                                    reinterpret_cast<::TaskQueueInterface *>((((::ShadowNode *)(::fnv_004e6540::FUN_004e6540((char *)(shadow4))))))->QueueActorDisarm(false);
                                reinterpret_cast<::B9BB10Effect *>((shadow4))->FUN_00b9bb10(0.0f, false);
                            }
                        }
                        if (rendered62 < limit && !reinterpret_cast<::FUN_00456630_helper *>((((::ShadowNode *)(::fnv_004e6540::FUN_004e6540((char *)(shadow4))))))->FUN_00456610() &&
                            !reinterpret_cast<::FUN_00456630_helper *>((((::ShadowNode *)(reinterpret_cast<::FUN_005bf820_Class *>((shadow4))->FUN_005bf820()))))->FUN_00456610())
                        {
                            ShadowBound bounds = *((::ShadowBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((((::ShadowNode *)(reinterpret_cast<::FUN_005bf820_Class *>((shadow4))->FUN_005bf820()))))->FUN_0043d450()));
                            shadow4->UpdateOutputLight(0, ((::ShadowNode *)(reinterpret_cast<::FUN_005bf820_Class *>((shadow4))->FUN_005bf820()))->FUN_0045bb80());
                            reinterpret_cast<::ShadowUpdate_b9e *>((shadow4))->FUN_00b9e970((::CameraCullView_b9e *)(view8));
                            if (((unsigned short)(reinterpret_cast<::FUN_004e6560_class *>((shadow4))->FUN_004e6560())) != 255 && reinterpret_cast<::fnv_00979260::Projectile *>((shadow4))->GetFirstLightParameter() >= DAT_01082cb0)
                            {
                                ++rendered62;
                                ShadowUpdate update53(0.0f, false, false);
                                reinterpret_cast<::FUN_00a59c60_cls *>((((::ShadowNode *)(::fnv_004e6540::FUN_004e6540((char *)(shadow4))))))->FUN_00a59c60((std::intptr_t)(&update53));
                                reinterpret_cast<::fnv_00b9dfc0::ShadowSceneLightDecompile *>((shadow4))->UpdateShadow(view8, (unsigned char *)(rendered62 - 1));
                                reinterpret_cast<::FUN_00b9fba0_s *>((shadow4))->FUN_00b9fba0();
                                void* renderer12 = ((void *)(reinterpret_cast<::FUN_00454b30_class *>((((::ShadowSystem *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00454b30()));
                                reinterpret_cast<::fnv_00b5d300::OwnerD *>((((::ShadowSystem *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5d300((::fnv_00b5d300::LightD *)(shadow4));
                                if (*(*reinterpret_cast<::ShadowBoolSetting *>(&::g_011c7664)).FUN_00408d60())
                                    reinterpret_cast<::ShadowSceneLight *>((shadow4))->AddObject((::NiAVObject *)(::ShadowNode *)(((::ShadowNode *)(reinterpret_cast<::FUN_005bf820_Class *>((shadow4))->FUN_005bf820()))));
                                reinterpret_cast<::FUN_00ba02b0_Class *>((shadow4))->FUN_00ba02b0();
                            }
                            else
                                reinterpret_cast<::TaskQueueInterface *>((((::ShadowNode *)(::fnv_004e6540::FUN_004e6540((char *)(shadow4))))))->QueueActorDisarm(true);
                        }
                        else
                            reinterpret_cast<::TaskQueueInterface *>((((::ShadowNode *)(::fnv_004e6540::FUN_004e6540((char *)(shadow4))))))->QueueActorDisarm(true);
                    }
                    shadow4 = ((::ShadowMap *)(reinterpret_cast<::FUN_00b5b010_cls *>((system))->FUN_00b5b010()));
                }
                while (rendered62 + 17 < 21)
                {
                    reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::ShadowTarget *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0({}, {});
                    ++rendered62;
                }
                if (specialNode3)
                    reinterpret_cast<::TaskQueueInterface *>((specialNode3))->QueueActorDisarm(specialHidden29);
                ::FUN_004e20b0(true);
                reinterpret_cast<::ShadowSceneNodeX *>((system))->FUN_00b5b880((void *)(view8));
                reinterpret_cast<::TaskQueueInterface *>((playerNode50))->QueueActorDisarm(playerHidden14);
            }
        }
    }
    else
    {
        for (int i = 17; i < 21; ++i)
        {
            reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::ShadowTarget *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0({}, {});
            ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::ShadowTarget *)(::TaskThreadManager::GetSingleton()))), {}, {}, {});
        }
    }
    FUN_00871a50();
}

namespace fnv_00871a50 {
extern bool __cdecl FUN_007079b0();
extern bool __cdecl FUN_00707b30();
extern bool __cdecl FUN_00702680(unsigned int, int);
struct RenderFlag
{
    bool* FUN_00408d60();
};
struct RenderNode
{
};
struct UiMenu
{
};
struct UiRenderer
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void Draw(RenderNode*, bool, int);
};
struct RenderHolder
{
    RenderNode* FUN_00559450();
    void FUN_0066b0d0(RenderNode*);
};
struct RenderTextureSource
{
};
extern RenderTextureSource* FUN_004a0ea0(void*, int, int, int, int);
struct HudRenderPass
{
    void FUN_00871a50();
};
// When the HUD conditions hold, ensures the render holder has a node, draws it via the UI renderer, and temporarily hides menu 1001's node while drawing.
// @fnv 0x00871a50
void HudRenderPass::FUN_00871a50()
{
    if (::FUN_00702360() && (*(*reinterpret_cast<::fnv_00871a50::RenderFlag *>(&::g_011db2cc)).FUN_00408d60() || *(*reinterpret_cast<::fnv_00871a50::RenderFlag *>(&::g_011d8ba0)).FUN_00408d60()) && ::FUN_007079b0())
    {
        AutoMemHelper kContext(13, true, ::DAT_010829c4, 0x1ade);
        bool wasActive = ::fnv_00705a00::FUN_00705a00();
        if (::FUN_00702360())
            ::fnv_007058e0::FUN_007058e0();
        if (!(*reinterpret_cast<::fnv_00871a50::RenderHolder *>(&::g_011dec64)).FUN_00559450())
            (*reinterpret_cast<::fnv_00871a50::RenderHolder *>(&::g_011dec64)).FUN_0066b0d0(((::fnv_00871a50::RenderNode *)(reinterpret_cast<::Pool *>((FUN_004a0ea0(((void *)(::FUN_0043c4b0())), 45, 0, 0, 0)))->FUN_00b6e110({}, {}, {}, {}, {}))));
        if (!wasActive)
            reinterpret_cast<::MenuStub *>((((::fnv_00871a50::RenderNode *)(::fnv_00705990::FUN_00705990()))))->FUN_007fae70(0);
        bool show = FUN_00707b30() || ((::fnv_00871a50::UiMenu *)(::FUN_00a09030(1001))) || ((::fnv_00871a50::UiMenu *)(::FUN_00a09030(1016))) || ((::fnv_00871a50::UiMenu *)(::FUN_00a09030(1059)));
        if (::FUN_007079b0() && show)
        {
            bool hide = wasActive && FUN_00702680(1001, 0);
            bool previous5 = 0;
            RenderNode* node_2 = 0;
            if (hide)
            {
                node_2 = ((::fnv_00871a50::RenderNode *)(reinterpret_cast<::MenuNodeView *>((::fnv_00871a50::UiMenu *)(::FUN_00a09030(1001)))->pNode));
                previous5 = reinterpret_cast<::FUN_00456630_helper *>((node_2))->FUN_00456610();
                reinterpret_cast<::TaskQueueInterface *>((node_2))->QueueActorDisarm(true);
            }

            ((::fnv_00871a50::UiRenderer *)(::FUN_00707ad0()))->Draw((*reinterpret_cast<::fnv_00871a50::RenderHolder *>(&::g_011dec64)).FUN_00559450(), true, 0);
            if (hide)
                reinterpret_cast<::TaskQueueInterface *>((node_2))->QueueActorDisarm(previous5);
        }
    }
    else if (::FUN_00702360())
        ::fnv_007058e0::FUN_007058e0();
}
}  // namespace fnv_00871a50

namespace fnv_00871dc0 {
struct RenderSurface
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual unsigned int Width(unsigned int);
    virtual unsigned int Height(unsigned int);
};
struct NiRenderer
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual RenderSurface* Target();
    void FUN_004a0370();
    void FUN_004a03c0();
};
struct MTRenderer
{
};
struct MenuTarget
{
};
struct MenuTargetPointer
{
    MenuTarget* value;
    MenuTarget* Get() const;
    void operator=(MenuTarget*);
};
struct TextureMgr
{
    void FUN_00b6da10(MenuTarget*);
};
TextureMgr* FUN_004a0ea0();
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Camera
{
    void FUN_00712e60(const Rect&);
};
struct Modifier;
struct InterfaceManager
{
};
bool FUN_00702680(int, unsigned int);
struct RenderMenu
{
};
struct BSCullingProcess
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    BSCullingProcess(void*);
    ~BSCullingProcess();
};
struct SceneObject
{
};
struct FUN_00871dc0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    MenuTargetPointer unk98;
    bool unk9c;
    void FUN_00871dc0();
};
// @fnv 0x00871dc0
void FUN_00871dc0_class::FUN_00871dc0()
{
    AutoMemHelper modifier(13, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 7193);
    if (!((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((::_g_thePlayer))->GetTarget())) || !::_g_thePlayer->GetNiNode())
        return;
    bool menu = ::DAT_011ad884;
    ::DAT_011ad884 = true;
    unk9c = true;
    ((::fnv_00871dc0::NiRenderer *)(::FUN_0043c4b0()))->FUN_004a0370();
    ::FUN_00a044f0();
    reinterpret_cast<::ThreadCoordinator_ba2f30 *>((((::fnv_00871dc0::MTRenderer *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba2f30();
    if ((*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)).Get())
        reinterpret_cast<::Manager *>((FUN_004a0ea0()))->FUN_00b6da10((::Item *)(::fnv_00871dc0::MenuTarget *)((*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)).Get()));
    (*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)) = ((::fnv_00871dc0::MenuTarget *)(reinterpret_cast<::Pool *>((FUN_004a0ea0()))->FUN_00b6e110((std::uintptr_t)(((::fnv_00871dc0::NiRenderer *)(::FUN_0043c4b0()))), 6, 0, 0, 0)));
    if (((::fnv_00871dc0::NiRenderer *)(::FUN_0043c4b0()))->Target()->Width(0) != ((unsigned int)(reinterpret_cast<::S872 *>(((*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)).Get()))->FUN_00872370(0))) ||
        ((::fnv_00871dc0::NiRenderer *)(::FUN_0043c4b0()))->Target()->Height(0) != ((unsigned int)(reinterpret_cast<::fnv_008723d0::S872 *>(((*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)).Get()))->FUN_008723d0(0))))
    {
        float x =
            ::FUN_0040ebd0((float)((::fnv_00871dc0::NiRenderer *)(::FUN_0043c4b0()))->Target()->Width(0) / (float)((unsigned int)(reinterpret_cast<::S872 *>(((*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)).Get()))->FUN_00872370(0))), 1.0f);
        float y =
            ::FUN_0040ebd0((float)((::fnv_00871dc0::NiRenderer *)(::FUN_0043c4b0()))->Target()->Height(0) / (float)((unsigned int)(reinterpret_cast<::fnv_008723d0::S872 *>(((*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)).Get()))->FUN_008723d0(0))), 1.0f);
        ((::fnv_00871dc0::Camera *)(::FUN_00524c90()))->FUN_00712e60(Rect(0, x, y, 0));
    }
    else if (::DAT_011f9426)
        ((::fnv_00871dc0::Camera *)(::FUN_00524c90()))->FUN_00712e60((*reinterpret_cast<::fnv_00871dc0::Rect *>(&::DAT_011ad840)));
    Modifier* mem = ((::fnv_00871dc0::Modifier *)(reinterpret_cast<::FUN_00718ab0_shell *>((((::fnv_00871dc0::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00718ab0()));
    ::ImageSpaceModifierInstanceForm::Stop((::TESImageSpaceModifier *)(::fnv_00871dc0::Modifier *)(((::fnv_00871dc0::Modifier *)(::FUN_005d2860()))));
    if (mem)
    {
        ::ImageSpaceModifierInstanceForm::Trigger((::TESImageSpaceModifier *)(mem), 1.0f, (::NiAVObject *)(void *)(0));
        reinterpret_cast<::fnv_0086fd90::FUN_0086fd90_shell *>(this)->FUN_0086fd90(0);
    }
    bool old = ::fnv_00705a00::FUN_00705a00();
    if (FUN_00702680(0x3f5, 0))
        old = false;
    reinterpret_cast<::fnv_008706b0::FUN_008706b0_shell *>(this)->FUN_008706b0((::fnv_008706b0::BSRenderedTexture *)(::fnv_00871dc0::MenuTarget *)((*reinterpret_cast<::fnv_00871dc0::MenuTargetPointer *>(&::g_011ded3c)).Get()), 0, old);
    if (FUN_00702680(0x40c, 0) && ((bool)(::IsStartMenuFlag1Set())))
    {
        BSCullingProcess cull(0);
        void* camera = ((void *)(reinterpret_cast<::RenderedMenuCameraView *>(::FUN_00707ad0())->camera));
        reinterpret_cast<::FUN_0041fd00_shell *>(&(cull))->FUN_0041fd00(reinterpret_cast<std::intptr_t>(camera));
        reinterpret_cast<::FUN_004a0fd0_shell *>(&(cull))->FUN_004a0fd0((::NiNode *)(::fnv_00871dc0::MenuTarget *)(unk98.Get()));
        reinterpret_cast<::BSA_ *>((((SceneObject*)unk98.Get())))->FUN_004a1020(((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))));
        ::FUN_00b6bee0(camera, ((void *)(reinterpret_cast<::TESRegionDataMap *>((((::fnv_00871dc0::RenderMenu *)(::FUN_00707ad0()))))->GetRegionMapName())), (::BSShaderAccumulator *)(::fnv_00871dc0::BSCullingProcess *)(&cull));
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(camera), (::BSShaderAccumulator *)(::fnv_00871dc0::MenuTarget *)(unk98.Get()), 0);
        reinterpret_cast<::FUN_004a0fd0_shell *>(&(cull))->FUN_004a0fd0((::NiNode *)(::fnv_00871dc0::MenuTarget *)(0));
    }
    if (mem)
    {
        ::ImageSpaceModifierInstanceForm::Stop((::TESImageSpaceModifier *)(mem));
        reinterpret_cast<::fnv_0086fd90::FUN_0086fd90_shell *>(this)->FUN_0086fd90(0);
    }
    reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_00871dc0::MTRenderer *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, 0x17);
    ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_00871dc0::MTRenderer *)(::TaskThreadManager::GetSingleton()))), (void *)(1), 0x17, {});
    reinterpret_cast<::FUN_00ba2fa0_C *>((((::fnv_00871dc0::MTRenderer *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba2fa0();
    ::DAT_011dea29 = true;
    ((::fnv_00871dc0::Camera *)(::FUN_00524c90()))->FUN_00712e60(Rect(0, 1, 1, 0));
    ::fnv_00a04500::FUN_00a04500();
    reinterpret_cast<::fnv_004a03c0::DD *>((((::fnv_00871dc0::NiRenderer *)(::FUN_0043c4b0()))))->FUN_004a03c0();
    unk9c = false;
    ::DAT_011ad884 = menu;
}
}  // namespace fnv_00871dc0

struct FUN_00872780_Class
{
    int unk00;
    int unk04;
    int unk08;
    FUN_008727b0_Class* callback;
    char FUN_00872780();
};
// Returns the result of calling callback->FUN_008727b0() if callback is set, otherwise returns 0.
// @fnv 0x00872780
char FUN_00872780_Class::FUN_00872780()
{
    return callback ? callback->FUN_008727b0() : static_cast<char>(0);
}

extern double DAT_01082d20;

struct NiRenderTargetGroup;
struct BSRenderedTexture;
struct TexObj
{
};

struct P1
{
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
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
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
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual NiRenderTargetGroup* GetRenderGroup();
};

struct Mgr
{
};
Mgr* FUN_004a0ea0(P1* a, int b, int c, int d, int e);

unsigned char FUN_008709f0();
double FUN_008731a0(double b, float a);

struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float a, float b, float c, float d);
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct _Rect16_00712e60
{
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct _Cam_00712e60
{
    void FUN_00712e60(const _Rect16_00712e60& r);
};

struct Host
{
    BSRenderedTexture* FUN_00872f50(P1* a1, BSRenderedTexture* a2, unsigned char a3, unsigned char a4);
};
// @fnv 0x00870a00
void SceneRendererStub870::FUN_00870a00(TexStub870* target, bool skip)
{
    RendererStub870* renderer2 = ((::RendererStub870 *)(::FUN_0043c4b0()));
    ISManagerStub870* ism = ((::ISManagerStub870 *)(::ImageSpaceManager::FUN_004e3270()));
    TexStub870* tex2 = 0;
    bool nodeFlag4 = reinterpret_cast<::FUN_00456630_helper *>((((::AVObjStub870 *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PlayerStub870*)::_g_thePlayer)))->FUN_00950bb0(true)))))->FUN_00456610();
    bool flagVal = ::FUN_004dc310();
    ::FUN_00b98480(1, 1);
    reinterpret_cast<::NiParallelUpdateTaskManager *>(this)->SetupTaskWorkers();
    tex2 = GetTexture();
    reinterpret_cast<::fnv_008727d0::FUN_008727d0_shell *>(this)->FUN_008727d0();
    bool checkXA = ::fnv_008749b0::FUN_008749b0((void *)this);
    reinterpret_cast<::ShadowHost *>(this)->FUN_00871290();
    RTexStub870* rt4 = ((::RTexStub870 *)(reinterpret_cast<::Host *>(this)->FUN_00872f50((::P1 *)(renderer2), (::BSRenderedTexture *)(target), 0, flagVal)));
    bool draw2 = !nodeFlag4 && !skip && !((void *)(reinterpret_cast<::TESRegionDataMap *>((((::MenuStub870 *)(::fnv_00705910::FUN_00705910()))))->GetRegionMapName())) && !::FUN_00705100();
    ShaderPassEntry(tex2, draw2, true, checkXA);
    if (draw2)
    {
        Finish1();
        reinterpret_cast<::FUN_00874b50_shell *>(this)->FUN_00874b50((::BSRenderedTexture *)(rt4), flagVal, 0);
        Composite(renderer2, 0, tex2, rt4);
    }
    else
    {
        reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::RenderSysStub870 *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, 0x16);
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::RenderSysStub870 *)(::TaskThreadManager::GetSingleton()))), (void *)(1), 0x16, {});
    }
    if (target)
        reinterpret_cast<::fnv_00876830::BSRenderedTexture *>(this)->FUN_00876830(flagVal, (std::intptr_t)(target));
    ::FUN_00714c20(1);
    if (FUN_008709f0())
    {
        RenderAlt(flagVal, rt4, renderer2, target);
    }
    else if (target)
    {
        reinterpret_cast<::fnv_00876830::BSRenderedTexture *>(this)->FUN_00876830(flagVal, (std::intptr_t)(target));
    }
    reinterpret_cast<::fnv_00876850::FUN_00876850_shell *>(this)->FUN_00876850((::fnv_00876850::BSRenderedTexture *)(rt4), (::fnv_00876850::ImageSpaceManager *)(ism), (::fnv_00876850::GraphicsRenderer *)(renderer2), (::fnv_00876850::Sun *)(0));
}

// @fnv 0x00872f50
BSRenderedTexture* Host::FUN_00872f50(P1* apSource, BSRenderedTexture* apFallbackTexture, unsigned char abSkipCreate,
                                      unsigned char abUseSourceGroup)
{
    BSRenderedTexture* tex = 0;
    if (FUN_008709f0() && !abSkipCreate)
    {
        AutoMemHelper helper(0x27, true, ::DAT_010829c4, 0x1e6d);
        tex = ((::BSRenderedTexture *)(reinterpret_cast<::Pool *>((FUN_004a0ea0(apSource, 4, 0, 0, 0)))->FUN_00b6e110({}, {}, {}, {}, {})));
        reinterpret_cast<::Obj008731d0 *>((((TexObj*)tex)))->FUN_008731d0();
        DAT_011f9438 = tex;
        if (reinterpret_cast<::GraphicsRenderer *>((apSource))->GetRenderTargetWidth() != ((unsigned int)(reinterpret_cast<::S872 *>((((TexObj*)tex)))->FUN_00872370(0))) ||
            reinterpret_cast<::GraphicsRenderer *>((apSource))->GetRenderTargetHeight() != ((unsigned int)(reinterpret_cast<::fnv_008723d0::S872 *>((((TexObj*)tex)))->FUN_008723d0(0))))
        {
            float fa;
            fa = (float)FUN_008731a0(
                (double)reinterpret_cast<::GraphicsRenderer *>((apSource))->GetRenderTargetWidth() * DAT_01082d20 / (double)((unsigned int)(reinterpret_cast<::S872 *>((((TexObj*)tex)))->FUN_00872370(0))), 1.0f);
            float fb;
            fb = (float)FUN_008731a0(
                (double)reinterpret_cast<::GraphicsRenderer *>((apSource))->GetRenderTargetHeight() * DAT_01082d20 / (double)((unsigned int)(reinterpret_cast<::fnv_008723d0::S872 *>((((TexObj*)tex)))->FUN_008723d0(0))), 1.0f);
            ImageSpaceEffectParam viewport(0.0f, fa, fb, 0.0f);
            ((::_Cam_00712e60 *)(::FUN_00524c90()))->FUN_00712e60(reinterpret_cast<const ::_Rect16_00712e60 &>(viewport));
        }
        ::FUN_00b6b8d0(7, tex->GetGroup());
    }
    else
    {
        AutoMemHelper helper(0x26, true, ::DAT_010829c4, 0x1e84);
        if (apFallbackTexture)
        {
            if (abUseSourceGroup)
            {
                ::FUN_00b6b8d0(7, apSource->GetRenderGroup());
            }
            else
            {
                ::FUN_00b6b8d0(7, apFallbackTexture->GetGroup());
            }
        }
        else
        {
            ::FUN_00b6b890(7, (int)(0));
        }
    }
    return tex;
}

namespace fnv_00874c10 {
struct BSFaceGenNiNode;

struct BSFaceGenAnimationData
{
};

struct TransformState
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    float tx, ty, tz;
    float scale;
};

struct AnimDataHelper
{
    void* FUN_004a0d10();
};

struct NiUpdateData
{
    float fTime;
    int b1;
    int b2;
    NiUpdateData(float time, int m_bUpdateEnabled, int bUpdateGeom);
};

struct NiPoint3WithNeg : public NiPoint3
{
};

struct NiNode
{
    void Update(NiUpdateData*);
};

struct PlayerObjectHelper
{
};

struct PlayerHelper
{
};

struct AudioGlobalHelper
{
};

struct CameraHelper
{
};

struct VATSHelper
{
};

struct BGSBodyPart
{
};

struct FORenderedMenu
{
};

struct MTRenderingSystem_Helper
{
};

struct ObjectA0
{
};

struct Object8C
{
};

template <class T> struct TargetPointer
{
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

struct NiRenderer
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual int v50();
    virtual int v51();
};

struct FaceGenHelper
{
};



struct MainShell
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    TargetPointer<Object8C> spObj8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    TargetPointer<ObjectA0> spObjA0;

    void FUN_00874c10();
};

// Updates the player's face gen node and render objects, toggling DAT_011de9d1 and submitting spObjA0/spObj8C to the rendering system.
// @fnv 0x00874c10
void MainShell::FUN_00874c10()
{
    AutoMemHelper memHelper5(0x34, 1, ::DAT_010829c4, 0x21b1);
    BSFaceGenNiNode* pFaceGenNode2 = ((::fnv_00874c10::BSFaceGenNiNode *)(::FUN_0045c670()));
    BSFaceGenAnimationData* pAnimData = ((::fnv_00874c10::BSFaceGenAnimationData *)(::FUN_00524c90()));
    NiNode* _pPlayerNode = ((::fnv_00874c10::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PlayerHelper*)::_g_thePlayer)))->FUN_00950bb0(1)));
    reinterpret_cast<::TaskQueueInterface *>((_pPlayerNode))->QueueActorDisarm(0);

    if ((*reinterpret_cast<unsigned char *>(&::DAT_011f9426)))
    {
        if (((::fnv_00874c10::NiRenderer *)(::FUN_0043c4b0()))->v51() == 0 || ((::fnv_00874c10::NiRenderer *)(::FUN_0043c4b0()))->v51() == ((::fnv_00874c10::NiRenderer *)(::FUN_0043c4b0()))->v50())
        {
            reinterpret_cast<::_Cam_00712e60 *>((((::fnv_00874c10::BSFaceGenAnimationData *)(::FUN_00524c90()))))->FUN_00712e60((*(const ::_Rect16_00712e60 *)(&(*reinterpret_cast<int *>(&::DAT_011ad840)))));
        }
    }

    reinterpret_cast<::C52020Obj *>((((FaceGenHelper*)pFaceGenNode2)))->FUN_00c52020(FUN_00874900((const char*)::_g_thePlayer), 0, (::C52020Obj *)(0), 0);

    if (((!reinterpret_cast<::FUN_00456630_helper *>((((::fnv_00874c10::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PlayerHelper*)::_g_thePlayer)))->FUN_00950bb0(0)))))->FUN_00456610() &&
          !reinterpret_cast<::FUN_00456630_helper *>((((::fnv_00874c10::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PlayerHelper*)::_g_thePlayer)))->FUN_00950bb0(1)))))->FUN_00456610() == 0) ||
         (!reinterpret_cast<::FUN_00456630_helper *>((((::fnv_00874c10::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PlayerHelper*)::_g_thePlayer)))->FUN_00950bb0(0)))))->FUN_00456610() == 0 &&
          !reinterpret_cast<::FUN_00456630_helper *>((((::fnv_00874c10::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PlayerHelper*)::_g_thePlayer)))->FUN_00950bb0(1)))))->FUN_00456610())) &&
        !reinterpret_cast<::FUN_005bb4d0_shell *>(((*reinterpret_cast<::fnv_00874c10::AudioGlobalHelper * *>(&::g_osGlobals))))->FUN_005bb4d0())
    {
        NiPoint3 pt_5c3 = (*(::NiPoint3 *)(reinterpret_cast<::P3 *>((void *)(((::fnv_00874c10::NiPoint3WithNeg *)(::FUN_0045bb80((intptr_t)(_pPlayerNode))))))->FUN_004a0bd0({})));
        NiUpdateData updateData7(0.0f, 0, 0);
        (*reinterpret_cast<unsigned char *>(&::SetRenderCamera::DAT_011de9d1)) = 1;

        reinterpret_cast<::FUN_00507700_cls *>(((spObjA0).operator->()))->FUN_00507700(reinterpret_cast<::NiCamera *>((((AnimDataHelper*)pAnimData)))->GetMaxFarNearRatio());
        reinterpret_cast<::NiCamera *>(((spObjA0).operator->()))->UpdateViewFrustum((*(const ::NiFrustum *)(((void *)&(reinterpret_cast<::NiCamera *>((((AnimDataHelper*)pAnimData)))->GetViewFrustum())))));
        reinterpret_cast<::_Cam_00712e60 *>(((spObjA0).operator->()))->FUN_00712e60((*(const ::_Rect16_00712e60 *)(((AnimDataHelper*)pAnimData)->FUN_004a0d10())));

        TransformState kTransform = *((::fnv_00874c10::TransformState *)(::FUN_00461130((intptr_t)(((AnimDataHelper*)pAnimData)))));
        reinterpret_cast<::FUN_004f00e0_shell *>(((spObjA0).operator->()))->FUN_004f00e0((void *)&(const ::NiPoint3 &)(*((::NiPoint3 *)(::FUN_0045bb80((intptr_t)((*reinterpret_cast<::fnv_00874c10::CameraHelper * *>(&::DAT_011e07d0)))))) + pt_5c3));
        reinterpret_cast<::FUN_00688430_shell *>(((spObjA0).operator->()))->FUN_00688430((::NineDwords688430 *)(::fnv_00874c10::TransformState *)(&kTransform));

        if (((::fnv_00874c10::PlayerObjectHelper *)(::FUN_007721a0((char *)(((PlayerHelper*)::_g_thePlayer))))) && !reinterpret_cast<::fnv_008a8870::HA *>((((PlayerHelper*)::_g_thePlayer)))->FUN_008a8870() &&
            !reinterpret_cast<::FUN_00525430_Class *>(&((*reinterpret_cast<::fnv_00874c10::VATSHelper *>(&::g_011f2250))))->FUN_00525430())
        {
            reinterpret_cast<::FUN_004f00e0_shell *>(((spObjA0).operator->()))->FUN_004f00e0((void *)&(const ::NiPoint3 &)(*((::NiPoint3 *)(::FUN_0045bb80((intptr_t)(((::fnv_00874c10::PlayerObjectHelper *)(::FUN_007721a0((char *)(((PlayerHelper*)::_g_thePlayer))))))))) + pt_5c3));
        }

        NiPoint3 pt_6c_ = *((::NiPoint3 *)&(reinterpret_cast<::NiAVObject *>((_pPlayerNode))->FUN_0043c490()));
        reinterpret_cast<::FUN_00440460_S *>((_pPlayerNode))->FUN_00440460((const ::V3 *)(const ::NiPoint3 *)(&NiPoint3::ZERO));
        reinterpret_cast<::FUN_00a59c60_cls *>((_pPlayerNode))->FUN_00a59c60((std::intptr_t)(&updateData7));
        reinterpret_cast<::FUN_00440460_S *>((_pPlayerNode))->FUN_00440460((const ::V3 *)(const ::NiPoint3 *)(&pt_6c_));

        BGSBodyPart* pBodyPart3 =
            reinterpret_cast<::FUN_00967ae0_cls *>((((PlayerHelper*)::_g_thePlayer)))->FUN_00967ae0() ? (pBodyPart3 = ((::fnv_00874c10::BGSBodyPart *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((((::fnv_00874c10::FORenderedMenu *)(::fnv_00705990::FUN_00705990()))))->FUN_006838b0()))) : 0;
        reinterpret_cast<::FUN_00546780_shell *>((_pPlayerNode))->FUN_00546780(1);

        if (pBodyPart3)
        {
            reinterpret_cast<::FUN_004f00e0_shell *>((pBodyPart3))->FUN_004f00e0((void *)&(const ::NiPoint3 &)(*((::NiPoint3 *)(::FUN_0045bb80((intptr_t)(pBodyPart3)))) - pt_5c3));
        }

        FUN_00870790((_Fake_FUN_00870790*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))), *((::NiPoint3 *)(::FUN_0045bb80((intptr_t)((spObjA0).operator->())))));
        ((_Fake_FUN_008750e0*)((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))->FUN_008750e0(pt_5c3);
    }
    else
    {
        (*reinterpret_cast<unsigned char *>(&::SetRenderCamera::DAT_011de9d1)) = 0;
    }

    if (((::fnv_00874c10::FORenderedMenu *)(::FUN_00707ad0())) && ((::fnv_00874c10::FORenderedMenu *)(::FUN_00707ad0())) != ((::fnv_00874c10::FORenderedMenu *)(::fnv_00705990::FUN_00705990())))
    {
    }
    else
    {
        ::AccumTaskDetail::FUN_00ba3390((::AccumTaskDetail::AccumTaskReceiver *)(((::fnv_00874c10::MTRenderingSystem_Helper *)(::TaskThreadManager::GetSingleton()))), spObjA0, (::AccumTaskDetail::NiRefObject *)(0), (::AccumTaskDetail::TaskArg1 *)(_pPlayerNode), (::AccumTaskDetail::NiRefObject *)(0), (void *)(0), spObj8C, (::AccumTaskDetail::NiRefObject *)(0), 0x16, 0, {});
    }
    reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_00874c10::MTRenderingSystem_Helper *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, 0x16);
}
}  // namespace fnv_00874c10

namespace SetRenderCamera {
struct Scene;
struct Context;
struct Pointer;
struct List;
struct Vec
{
    float x, y, z;
    Vec(float, float, float);
};
struct Rect
{
    float left, right, top, bottom;
    Rect(float, float, float, float);
};
struct Update
{
    float time;
    unsigned int flags, other;
    Update(float, int, int);
};
using Guard = ::AutoMemContext;
struct VecRef
{
};
struct Scene
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual Scene* Node();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual bool Active();
    virtual void slotc4();
    virtual void* Secondary();
    virtual void* Primary();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned short unk38;
    unsigned char visible, unk3b;
    void FUN_0049ed90(int);
    void* FUN_00b6b260();
    Scene* FUN_006629f0();
};
struct Output : Scene
{
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    Output(int, int, int);
};
void* FUN_00aa13e0(unsigned int);
struct Pointer
{
    Scene* value;
    Pointer(Scene*);
    Pointer(const Pointer&);
    ~Pointer();
    Scene* FUN_00559450();
    void FUN_0066b0d0(Scene*);
};
struct Context
{
};
struct List
{
    Pointer* FUN_006815c0();
};
struct ListRef
{
};
struct Mode
{
    int FUN_0044ddc0();
};
struct Player
{
};
bool FUN_007079b0();
struct Main
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    Pointer texture, surface;
    unsigned int unk90, unk94, unk98, unk9c;
    Pointer camera;
    void FUN_00875110(Scene*, Scene*, Scene*, Scene*);
};
// @fnv 0x00875110
void Main::FUN_00875110(Scene* root, Scene* firstPerson, Scene* extra, Scene* pass)
{
    Scene* renderSlot52 = ((::SetRenderCamera::Scene *)(::FUN_0045c670()));
    Context* contextSlot26 = ((::SetRenderCamera::Context *)(reinterpret_cast<::SceneGraph *>(renderSlot52)->cullingProcess));
    Scene* playerSceneSlot0 = ((::SetRenderCamera::Scene *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))->FUN_00950bb0(1)));
    reinterpret_cast<::TaskQueueInterface *>((playerSceneSlot0))->QueueActorDisarm(0);
    Scene* viewSlot23 = renderSlot52->FUN_006629f0();
    Scene* aliasSlot0 = playerSceneSlot0;
    ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::SetRenderCamera::Scene *)(::TaskThreadManager::GetSingleton()))), (void *)(1), 22, {});
    surface.FUN_00559450()->visible = 0;
    Guard guardSlot1(0x34, 1, ::DAT_010829c4, 0x221f);
    reinterpret_cast<::S148c0 *>((root))->FUN_007148c0(0, 4);
    if (::DAT_011f9426 && (!((::SetRenderCamera::Scene *)(::FUN_0043c4b0()))->Primary() || ((::SetRenderCamera::Scene *)(::FUN_0043c4b0()))->Primary() == ((::SetRenderCamera::Scene *)(::FUN_0043c4b0()))->Secondary()))
        reinterpret_cast<::_Cam_00712e60 *>((camera.FUN_00559450()))->FUN_00712e60((const ::_Rect16_00712e60 &)((*reinterpret_cast<::SetRenderCamera::Rect *>(&::DAT_011ad840))));
    else
        reinterpret_cast<::_Cam_00712e60 *>((camera.FUN_00559450()))->FUN_00712e60((const ::_Rect16_00712e60 &)((const ::SetRenderCamera::Rect &)(Rect(0, 1, 1, 0))));
    reinterpret_cast<::C52020Obj *>((renderSlot52))->FUN_00c52020(::FUN_00874900((const char *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer)))), 0, (::C52020Obj *)(0), 0);
    ::BSShaderManager::SetFOV(::FUN_00874900((const char *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer)))));
    reinterpret_cast<::NiCamera *>((camera.FUN_00559450()))->UpdateViewFrustum((*(const ::NiFrustum *)(((void *)&(reinterpret_cast<::NiCamera *>((viewSlot23))->GetViewFrustum())))));
    if (firstPerson)
    {
        reinterpret_cast<::MenuStub *>((((::SetRenderCamera::Scene *)(::FUN_00707ad0()))))->FUN_007fae70(0);
        reinterpret_cast<::TaskQueueInterface *>((firstPerson))->QueueActorDisarm(0);
        if (::FUN_007079b0())
        {
            if (::fnv_00705a00::FUN_00705a00() && reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))->FUN_008c51c0())
                reinterpret_cast<::TaskQueueInterface *>((((::SetRenderCamera::Scene *)(reinterpret_cast<::StrOwner *>((((::SetRenderCamera::Scene *)(::FUN_00707ad0()))))->FUN_007fa950()))))->QueueActorDisarm(1);
            Pointer tempTextureSlot13(new Output(99, 1, 759));
            reinterpret_cast<::FUN_00c4f270_Class *>((contextSlot26))->FUN_00c4f270(1);
            Scene* property = ((::SetRenderCamera::Scene *)(reinterpret_cast<::FUN_00a59d30_C *>((((::SetRenderCamera::Scene *)(reinterpret_cast<::StrOwner *>((((::SetRenderCamera::Scene *)(::FUN_00707ad0()))))->FUN_007fa950()))))->FUN_00a59d30((intptr_t)(((void *)(::FUN_0040df90()))))));
            if (property)
                reinterpret_cast<::FUN_0049ed90_shell *>((property))->FUN_0049ed90(0);
            reinterpret_cast<::MenuStub *>((((::SetRenderCamera::Scene *)(::FUN_00707ad0()))))->FUN_007fae70(0);
            reinterpret_cast<::FUN_004a0fd0_shell *>((contextSlot26))->FUN_004a0fd0((::NiNode *)(::SetRenderCamera::Scene *)(tempTextureSlot13.FUN_00559450()));
            if (::fnv_00705a00::FUN_00705a00() && reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))->FUN_008c51c0())
            {
                ::FUN_00b6bee0(camera.FUN_00559450(), ((::SetRenderCamera::Scene *)(reinterpret_cast<::fnv_00875bd0::FUN_00875bd0_Class *>((((::SetRenderCamera::Scene *)(::fnv_00705990::FUN_00705990()))))->FUN_00875bd0(0))), (::BSShaderAccumulator *)(contextSlot26));
                ::FUN_00b6bee0(camera.FUN_00559450(), ((::SetRenderCamera::Scene *)(reinterpret_cast<::fnv_00875bd0::FUN_00875bd0_Class *>((((::SetRenderCamera::Scene *)(::fnv_00705990::FUN_00705990()))))->FUN_00875bd0(1))), (::BSShaderAccumulator *)(contextSlot26));
                ::FUN_00b6bee0(camera.FUN_00559450(), ((::SetRenderCamera::Scene *)(reinterpret_cast<::fnv_00875bd0::FUN_00875bd0_Class *>((((::SetRenderCamera::Scene *)(::fnv_00705990::FUN_00705990()))))->FUN_00875bd0(2))), (::BSShaderAccumulator *)(contextSlot26));
            }
            ::FUN_00b6bee0(camera.FUN_00559450(), ((::SetRenderCamera::Scene *)(reinterpret_cast<::StrOwner *>((((::SetRenderCamera::Scene *)(::FUN_00707ad0()))))->FUN_007fa950())), (::BSShaderAccumulator *)(contextSlot26));
            ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(::SetRenderCamera::Scene *)(camera.FUN_00559450()), (::BSShaderAccumulator *)(::SetRenderCamera::Scene *)(tempTextureSlot13.FUN_00559450()), 0);
            reinterpret_cast<::FUN_004a0fd0_shell *>((contextSlot26))->FUN_004a0fd0((::NiNode *)(::SetRenderCamera::Scene *)(0));
            tempTextureSlot13.FUN_0066b0d0(0);
            reinterpret_cast<::FUN_00c4f2d0_class *>((contextSlot26))->FUN_00c4f2d0();
            if (::fnv_00705a00::FUN_00705a00() && reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))->FUN_008c51c0())
                reinterpret_cast<::TaskQueueInterface *>((((::SetRenderCamera::Scene *)(reinterpret_cast<::StrOwner *>((((::SetRenderCamera::Scene *)(::FUN_00707ad0()))))->FUN_007fa950()))))->QueueActorDisarm(0);
        }
    }
    if (((::SetRenderCamera::Scene *)(::FUN_00707ad0())) && ((::SetRenderCamera::Scene *)(::FUN_00707ad0())) != ((::SetRenderCamera::Scene *)(::fnv_00705990::FUN_00705990())))
    {
    }
    else if (!::fnv_00705a00::FUN_00705a00() || !reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))->FUN_008c51c0())
    {
        ::BSRenderStateManager::SetColorWriteMask(15, (::BSRENDERSTATE_LOCK)(1));
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::SetRenderCamera::Scene *)(::TaskThreadManager::GetSingleton()))), (void *)(1), 22, {});
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(::SetRenderCamera::Scene *)(camera.FUN_00559450()), (::BSShaderAccumulator *)(::SetRenderCamera::Scene *)(surface.FUN_00559450()), 0);
        ::FUN_004eced0(1);
        List* list = ((::SetRenderCamera::List *)&(reinterpret_cast<::NiAVObject *>(&((*reinterpret_cast<::SetRenderCamera::ListRef *>(&::g_011e0e80))))->FUN_0043c490()));
        if (list && !reinterpret_cast<::ObsList *>((list))->FUN_004a4460())
        {
            Vec offset(0, 0, 0);
            if (((::SetRenderCamera::Scene *)(::FUN_007721a0((char *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer)))))) && !reinterpret_cast<::fnv_008a8870::HA *>(((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))->FUN_008a8870() && !reinterpret_cast<::FUN_00525430_Class *>(&((*reinterpret_cast<::SetRenderCamera::Mode *>(&::g_011f2250))))->FUN_00525430())
                offset = ([&] { ::SetRenderCamera::Vec difference(0, 0, 0); reinterpret_cast<::FUN_00439ef0_class *>((((::SetRenderCamera::Vec *)(::FUN_0045bb80((intptr_t)(((::SetRenderCamera::Scene *)(::FUN_007721a0((char *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))))))))))->FUN_00439ef0((::NiPoint3 *)&difference, *(const ::NiPoint3 *)((::NiPoint3 *)&(*((::SetRenderCamera::Vec *)(::FUN_0045bb80((intptr_t)((*reinterpret_cast<::SetRenderCamera::Scene * *>(&::DAT_011e07d0))))))))); return difference; }());
            Scene* render2Slot14 = ((::SetRenderCamera::Scene *)(::FUN_0045c670()));
            Scene* view2Slot10 = render2Slot14->FUN_006629f0();
            Context* context2Slot0 = ((::SetRenderCamera::Context *)(reinterpret_cast<::SceneGraph *>(render2Slot14)->cullingProcess));
            Pointer texture2Slot11(texture);
            Vec savedPosSlot10 = *((::SetRenderCamera::Vec *)(::FUN_0045bb80((intptr_t)(view2Slot10))));
            reinterpret_cast<::FUN_004f00e0_shell *>((view2Slot10))->FUN_004f00e0((void *)&(const ::SetRenderCamera::Vec &)((*(::SetRenderCamera::Vec *)(reinterpret_cast<::Point3Offset *>(&(savedPosSlot10))->ProjectileLaunched((::NiPoint3 *)&(offset), {})))));
            reinterpret_cast<::FUN_004a0fd0_shell *>((context2Slot0))->FUN_004a0fd0((::NiNode *)(::SetRenderCamera::Scene *)(texture2Slot11.FUN_00559450()));
            reinterpret_cast<::FUN_00936aa0_shell *>((texture2Slot11.FUN_00559450()))->FUN_00936aa0(1);
            bool renderedSlot0 = false;
            while (list)
            {
                Scene* object = ((::SetRenderCamera::Pointer *)(&reinterpret_cast<::SimpleListNodeView*>(list)->m_item))->FUN_00559450();
                list = ((::SetRenderCamera::List *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                if (object && object->Active())
                {
                    renderedSlot0 = true;
                    reinterpret_cast<::TaskQueueInterface *>((object->Node()))->QueueActorDisarm(0);
                    ::FUN_00b6bee0(view2Slot10, object->Node(), (::BSShaderAccumulator *)(context2Slot0));
                    reinterpret_cast<::TaskQueueInterface *>((object->Node()))->QueueActorDisarm(1);
                }
            }
            if (renderedSlot0)
                ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(view2Slot10), (::BSShaderAccumulator *)(::SetRenderCamera::Scene *)(texture2Slot11.FUN_00559450()), 0);
            reinterpret_cast<::FUN_004a0fd0_shell *>((context2Slot0))->FUN_004a0fd0((::NiNode *)(::SetRenderCamera::Scene *)(0));
            reinterpret_cast<::FUN_00936aa0_shell *>((texture2Slot11.FUN_00559450()))->FUN_00936aa0(0);
            texture2Slot11.FUN_0066b0d0(0);
            reinterpret_cast<::FUN_004f00e0_shell *>((view2Slot10))->FUN_004f00e0((void *)&(savedPosSlot10));
        }
    }
    if (::FUN_005b9b00())
    {
        Guard guard2Slot0(0x27, 1, ::DAT_010829c4, 0x22b5);
        if (::fnv_00705a00::FUN_00705a00() && ::FUN_005b9b00() && reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer))))->FUN_008c51c0())
        {
            ::BSRenderedTexture::EndAllAndResetRendererState();
            ::FUN_00a29680();
            ::FUN_00b6b8d0(6, (::NiRenderTargetGroup *)(void *)(pass->FUN_00b6b260()));
            if (::DAT_011f9426)
                reinterpret_cast<::_Cam_00712e60 *>((((::SetRenderCamera::Scene *)(::FUN_00524c90()))))->FUN_00712e60((const ::_Rect16_00712e60 &)((*reinterpret_cast<::SetRenderCamera::Rect *>(&::DAT_011ad840))));
        }
        Scene* render3Slot0 = ((::SetRenderCamera::Scene *)(::FUN_0045c670()));
        reinterpret_cast<::fnv_00b64570::DepthAccumulator *>((surface.FUN_00559450()))->FUN_00b64570((::NiCamera *)(::SetRenderCamera::Scene *)(camera.FUN_00559450()), (::fnv_00b64570::TextureView *)(pass));
        reinterpret_cast<::FUN_00874b50_shell *>(this)->FUN_00874b50((::BSRenderedTexture *)(pass), 0, 0);
    }
    if (DAT_011de9d1)
    {
        Update update(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((aliasSlot0))->FUN_00a59c60((std::intptr_t)&(update));
        reinterpret_cast<::FUN_00546780_shell *>((aliasSlot0))->FUN_00546780(0);
        ::FUN_00870790((::_Fake_FUN_00870790 *)(((::SetRenderCamera::Scene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))), (*(::NiPoint3 *)&(const ::SetRenderCamera::Vec &)(*((::SetRenderCamera::Vec *)&(reinterpret_cast<::NiAVObject *>((((::SetRenderCamera::VecRef *)(reinterpret_cast<::FUN_009611e0_shell *>((viewSlot23))->FUN_009611e0()))))->FUN_0043c490())))));
        reinterpret_cast<::_Fake_FUN_008750e0 *>((((::SetRenderCamera::Scene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_008750e0((*(::NiPoint3 *)&(const ::SetRenderCamera::Vec &)((*reinterpret_cast<::SetRenderCamera::Vec *>((void *)&::NiPoint3::ZERO)))));
    }
    if (reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode != 4)
        reinterpret_cast<::C52020Obj *>((((::SetRenderCamera::Scene *)(::FUN_0045c670()))))->FUN_00c52020(::FUN_00710ab0((::FUN_00710ab0_Class *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer)))), 0, (::C52020Obj *)(0), 0);
    ::BSShaderManager::SetFOV(::FUN_00710ab0((::FUN_00710ab0_Class *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer)))));
    if (extra && !reinterpret_cast<::FUN_00456630_helper *>((((::SetRenderCamera::Scene *)(::fnv_0043b230::FUN_0043b230((const char *)(extra))))))->FUN_00456610())
    {
        bool previousSlot0 = reinterpret_cast<::FUN_00456630_helper *>((((::SetRenderCamera::Scene *)(::fnv_0043b230::FUN_0043b230((const char *)(extra))))))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((((::SetRenderCamera::Scene *)(::fnv_0043b230::FUN_0043b230((const char *)(extra))))))->QueueActorDisarm(0);
        Scene* render4Slot20 = ((::SetRenderCamera::Scene *)(::FUN_0045c670()));
        Scene* view4Slot48 = render4Slot20->FUN_006629f0();
        Context* context4 = ((::SetRenderCamera::Context *)(reinterpret_cast<::SceneGraph *>(render4Slot20)->cullingProcess));
        Pointer texture4(texture);
        reinterpret_cast<::FUN_004a0fd0_shell *>((context4))->FUN_004a0fd0((::NiNode *)(::SetRenderCamera::Scene *)(texture4.FUN_00559450()));
        reinterpret_cast<::FUN_00936aa0_shell *>((texture4.FUN_00559450()))->FUN_00936aa0(1);
        ::FUN_00b6bee0(view4Slot48, ((::SetRenderCamera::Scene *)(::fnv_0043b230::FUN_0043b230((const char *)(extra)))), (::BSShaderAccumulator *)(context4));
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(view4Slot48), (::BSShaderAccumulator *)(::SetRenderCamera::Scene *)(texture4.FUN_00559450()), 0);
        reinterpret_cast<::FUN_004a0fd0_shell *>((context4))->FUN_004a0fd0((::NiNode *)(::SetRenderCamera::Scene *)(0));
        reinterpret_cast<::FUN_00936aa0_shell *>((texture4.FUN_00559450()))->FUN_00936aa0(0);
        texture4.FUN_0066b0d0(0);
        reinterpret_cast<::TaskQueueInterface *>((((::SetRenderCamera::Scene *)(::fnv_0043b230::FUN_0043b230((const char *)(extra))))))->QueueActorDisarm(previousSlot0);
    }
    if (extra)
        reinterpret_cast<::A6A0Sun *>((extra))->FUN_006426a0((void *)(2), (::A6A0Target *)(::SetRenderCamera::Scene *)(texture.FUN_00559450()), (*reinterpret_cast<::SetRenderCamera::Pointer *>(&::g_011deb7c)).FUN_00559450()->FUN_006629f0());
    reinterpret_cast<::C52020Obj *>((renderSlot52))->FUN_00c52020(::FUN_00874900((const char *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer)))), 0, (::C52020Obj *)(0), 0);
    ::BSShaderManager::SetFOV(::FUN_00874900((const char *)((*reinterpret_cast<::SetRenderCamera::Player * *>(&::_g_thePlayer)))));
}
}

namespace fnv_00875fd0 {
struct SaveGameRenderState
{
};
bool __cdecl FUN_007079b0();
struct RenderEffectManager
{
};
struct AccumulatorPointer
{
    BSShaderAccumulator* FUN_00559450() const;
    void FUN_0066b0d0(BSShaderAccumulator*);
};
struct RenderedMenu
{
    virtual void UnkVirtual0();
    virtual void UnkVirtual1();
    virtual void UnkVirtual2();
    virtual void UnkVirtual3();
    virtual void UnkVirtual4();
    virtual void UnkVirtual5();
    virtual void UnkVirtual6();
    virtual void UnkVirtual7();
    virtual void UnkVirtual8();
    virtual void UnkVirtual9();
    virtual void UnkVirtual10();
    virtual float GetRenderScale();
};
struct TextureReturnManager
{
    void FUN_00b6da10(BSShaderAccumulator*);
};
TextureReturnManager* FUN_004a0ea0();
struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float left;
    float right;
    float top;
    float bottom;
};
struct ViewportCamera
{
};
struct FrameRenderer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    bool bSkipScene;
    void FUN_00875fd0(void*, void*, void*, void*);
};

// @fnv 0x00875fd0
void FrameRenderer::FUN_00875fd0(void* unused, void* renderer, void* scene, void* target)
{
    AutoMemHelper m_uiMemoryContext(39, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 9058);
    if (!FUN_004e9510())
        ::BSRenderedTexture::EndAllAndResetRendererState();
    if (!::fnv_00705a00::FUN_00705a00() && !::FUN_00702360() && !::Interface::IsGamePaused() && !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00875fd0::SaveGameRenderState * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() &&
        !reinterpret_cast<::FUN_005621d0_shell *>(((*reinterpret_cast<::fnv_00875fd0::SaveGameRenderState * *>(&::g_BGSSaveLoadGame))))->FUN_005621d0() && !bSkipScene)
        ::fnv_00702870::FUN_00702870();
    if ((*reinterpret_cast<::fnv_00875fd0::AccumulatorPointer *>(&::g_011deb38)).FUN_00559450())
        reinterpret_cast<::FOVATSEffectManager_00801a60 *>((((::fnv_00875fd0::RenderEffectManager *)(::fnv_00705910::FUN_00705910()))))->FUN_00801a60((intptr_t)(renderer), (intptr_t)((*reinterpret_cast<::fnv_00875fd0::AccumulatorPointer *>(&::g_011deb38)).FUN_00559450()), 0, 0);
    bool menuActive = ::FUN_007079b0() && !bSkipScene && ::DAT_011dea29;
    if (menuActive)
    {
        DAT_012005a2 = true;
        float renderScale = ((::fnv_00875fd0::RenderedMenu *)(::FUN_00707ad0()))->GetRenderScale();
        ::DAT_011add08 = renderScale;
    }
    (*reinterpret_cast<void * *>(&::DAT_011f917c)) = ((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData();
    ::FUN_00b55ac0(scene, renderer, target);
    if ((*reinterpret_cast<::fnv_00875fd0::AccumulatorPointer *>(&::g_011deb38)).FUN_00559450())
    {
        reinterpret_cast<::FOVATSEffectManager_008019d0 *>((((::fnv_00875fd0::RenderEffectManager *)(::fnv_00705910::FUN_00705910()))))->FUN_008019d0();
        reinterpret_cast<::Manager *>((FUN_004a0ea0()))->FUN_00b6da10((::Item *)(::BSShaderAccumulator *)((*reinterpret_cast<::fnv_00875fd0::AccumulatorPointer *>(&::g_011deb38)).FUN_00559450()));
        (*reinterpret_cast<::fnv_00875fd0::AccumulatorPointer *>(&::g_011deb38)).FUN_0066b0d0(0);
    }
    if (menuActive)
    {
        DAT_012005a2 = false;
        ::DAT_011add08 = 1.0f;
    }
    reinterpret_cast<::_Cam_00712e60 *>((((::fnv_00875fd0::ViewportCamera *)(::FUN_00524c90()))))->FUN_00712e60((const ::_Rect16_00712e60 &)((const ::fnv_00875fd0::ImageSpaceEffectParam &)(ImageSpaceEffectParam(0.0f, 1.0f, 1.0f, 0.0f))));
}
}  // namespace fnv_00875fd0

namespace fnv_008761e0 {
struct V876
{
    float x, y, z;
};
struct T876
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    V876 pos;
    float scale;
};
struct R876
{
    float l, r, t, b;
};
struct Camera876
{
    bool FUN_00876810();
    Camera876* FUN_006629f0();
    R876* FUN_004a0d10();
    void FUN_0049ed90(bool);
    Camera876* FUN_00559450();
    void* FUN_004bc320(int);
};
struct Player876
{
    Camera876* FUN_006629f0();
};
struct Global876
{
};
struct Input876
{
};
struct Mode876
{
};
struct Virtual876
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual int width();
    virtual int height();
};
struct Shell876
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    Camera876 a8c;
    int unk90;
    int unk94;
    Camera876 a98;
    int unk9c;
    Camera876 aa0;
    void FUN_008761e0(int, Input876*);
};
// Sets up the player camera and scene nodes, applies camera transforms and render passes, then restores the previous camera state.
// @fnv 0x008761e0
void Shell876::FUN_008761e0(int unused, Input876* input)
{
    Player876* p;
    R876 h;
    Camera876* a;
    Camera876* i;
    Camera876* s;
    Camera876* f;
    bool eb;
    V876 cf;
    Camera876* q;
    T876 b;
    T876 ba;
    bool k;
    int l;
    float c;
    float e;
    V876 j;
    p = (Player876*)((::BSFaceGenNiNode *)(::FUN_0045c670()));
    s = ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::SceneGraph *>(p)->cullingProcess));
    i = ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::RenderedMenuCameraView *>(::FUN_00707ad0())->camera));
    reinterpret_cast<::S148c0 *>((input))->FUN_007148c0(0, 4);
    f = ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::TESRegionDataMap *>((((::fnv_008761e0::Camera876 *)(::FUN_00707ad0()))))->GetRegionMapName()));
    reinterpret_cast<::BGSExplosion *>((s))->FUN_004fb0b0((::BGSImpactDataSet *)(true));
    new ((void *)&(cf)) ::NiUpdateData(0.0f, 0, 0);
    reinterpret_cast<::_dummy_476a80 *>(&(b))->FUN_00476a80();
    eb = f->FUN_00876810();
    a = i ? i : p->FUN_006629f0();

    if (reinterpret_cast<::FUN_00967ae0_cls *>(((*reinterpret_cast<::fnv_008761e0::Global876 * *>(&::_g_thePlayer))))->FUN_00967ae0())
    {
        ba = *((::fnv_008761e0::T876 *)(::FUN_006a9540((char *)(f))));
        reinterpret_cast<::FUN_00440460_S *>((f))->FUN_00440460((const ::V3 *)(::fnv_008761e0::V876 *)(&(*reinterpret_cast<::fnv_008761e0::V876 *>((void *)&::NiPoint3::ZERO))));
        reinterpret_cast<::FUN_00a59c60_cls *>((f))->FUN_00a59c60((std::intptr_t)(&cf));
        reinterpret_cast<::FUN_00440460_S *>((f))->FUN_00440460((const ::V3 *)(::fnv_008761e0::V876 *)(&ba.pos));
        reinterpret_cast<::NiTransform *>(&(b))->ResetToIdentity();
        if (a && ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::NiAVObjectFields *>(a)->m_pkParent)))
        {
            b = *((::fnv_008761e0::T876 *)(::FUN_006a9540((char *)(((::fnv_008761e0::Camera876 *)(reinterpret_cast<::NiAVObjectFields *>(a)->m_pkParent))))));
            reinterpret_cast<::FUN_00440460_S *>((((::fnv_008761e0::Camera876 *)(reinterpret_cast<::NiAVObjectFields *>(a)->m_pkParent))))->FUN_00440460((const ::V3 *)(::fnv_008761e0::V876 *)((V876*)((::fnv_008761e0::Camera876 *)(::FUN_0045bb80(reinterpret_cast<std::intptr_t>((*reinterpret_cast<::fnv_008761e0::Camera876 * *>(&::DAT_011e07d0))))))));
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_008761e0::Camera876 *)(reinterpret_cast<::NiAVObjectFields *>(a)->m_pkParent))))->FUN_00a59c60((std::intptr_t)(&cf));
        }

        ((::_Fake_FUN_008750e0 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->FUN_008750e0(*(NiPoint3*)((::fnv_008761e0::V876 *)(reinterpret_cast<::P3 *>((((::fnv_008761e0::Camera876 *)(::FUN_0045bb80((intptr_t)(f))))))->FUN_004a0bd0((::P3 *)(::fnv_008761e0::V876 *)(&j)))));
    }
    if (::fnv_00705a00::FUN_00705a00())
    {
        l = 0;
        k = reinterpret_cast<::FOPipboyManager *>((((::fnv_008761e0::Mode876 *)(::fnv_00705990::FUN_00705990()))))->FUN_007f8720(reinterpret_cast<::ButtonDevice *>((((::fnv_008761e0::Input876 *)(reinterpret_cast<::FUN_00877720_shell *>(this)->FUN_00877720()))))->FUN_00a23a50(0, 1) > 0, reinterpret_cast<::ButtonDevice *>((((::fnv_008761e0::Input876 *)(reinterpret_cast<::FUN_00877720_shell *>(this)->FUN_00877720()))))->FUN_00a23a50(0, 2) > 0,
                                         (*(float *)(&e)), (*(float *)(&c)), (*(int *)(&l)));
        ::FUN_00709b50(k, e, c, l);
    }
    i = i ? i : p->FUN_006629f0();
    if (!i)
        i = aa0.FUN_00559450();
    h = *i->FUN_004a0d10();
    if (::DAT_011f9426 && ((::fnv_008761e0::Virtual876 *)(::FUN_0043c4b0()))->height() == ((::fnv_008761e0::Virtual876 *)(::FUN_0043c4b0()))->width())
        reinterpret_cast<::_Cam_00712e60 *>((i))->FUN_00712e60((*(const ::_Rect16_00712e60 *)(&(*reinterpret_cast<::fnv_008761e0::R876 *>(&::DAT_011ad840)))));
    ::BSRenderStateManager::SetColorWriteMask(0, (::BSRENDERSTATE_LOCK)(1));
    reinterpret_cast<::FUN_0041fd00_shell *>((s))->FUN_0041fd00((intptr_t)(i));
    reinterpret_cast<::FUN_004a0fd0_shell *>((s))->FUN_004a0fd0((::NiNode *)(void *)(a8c.FUN_00559450()));
    reinterpret_cast<::BSA_ *>((a8c.FUN_00559450()))->FUN_004a1020(((::_Fake_FUN_008750e0 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))));
    ::FUN_00b6bee0(i, f, (::BSShaderAccumulator *)(s));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(i), (::BSShaderAccumulator *)(::fnv_008761e0::Camera876 *)(a8c.FUN_00559450()), 0);
    reinterpret_cast<::fnv_00b63b90::FUN_00b63b90_class *>((a8c.FUN_00559450()))->FUN_00b63b90(6);
    reinterpret_cast<::FUN_004a0fd0_shell *>((s))->FUN_004a0fd0((::NiNode *)(void *)(0));
    ::FUN_004eced0(1);
    q = ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::FUN_00a59d30_C *>((((::fnv_008761e0::Camera876 *)(reinterpret_cast<::StrOwner *>((((::fnv_008761e0::Camera876 *)(::FUN_00707ad0()))))->FUN_007fa950()))))->FUN_00a59d30((intptr_t)(((void *)(::FUN_0040df90()))))));
    if (q)
    {
        reinterpret_cast<::FUN_0049ed90_shell *>((q))->FUN_0049ed90(true);
        reinterpret_cast<::NiObjectNET *>((q))->FUN_00439340(6);
        reinterpret_cast<::fnv_00439390::NiObjectNET *>((q))->FUN_00439390(0);
        reinterpret_cast<::FUN_00a5a040_Class *>((((::fnv_008761e0::Camera876 *)(reinterpret_cast<::StrOwner *>((((::fnv_008761e0::Camera876 *)(::FUN_00707ad0()))))->FUN_007fa950()))))->FUN_00a5a040();
    }
    reinterpret_cast<::MenuStub *>((((::fnv_008761e0::Camera876 *)(::FUN_00707ad0()))))->FUN_007fae70((intptr_t)(((void *)(reinterpret_cast<::FUN_004bc320_shell *>(((*reinterpret_cast<::fnv_008761e0::Camera876 *>(&::g_011dec64)).FUN_00559450()))->FUN_004bc320(0)))));
    reinterpret_cast<::FUN_0041fd00_shell *>((s))->FUN_0041fd00((intptr_t)(i));
    reinterpret_cast<::FUN_004a0fd0_shell *>((s))->FUN_004a0fd0((::NiNode *)(void *)(a98.FUN_00559450()));
    ::FUN_00b97e30(0, 1);
    if (reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::fnv_008761e0::Global876 * *>(&::_g_thePlayer))))->FUN_008c51c0() && ::fnv_00705a00::FUN_00705a00())
    {
        ::FUN_00b6bee0(i, ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::fnv_00875bd0::FUN_00875bd0_Class *>((((::fnv_008761e0::Mode876 *)(::fnv_00705990::FUN_00705990()))))->FUN_00875bd0(0))), (::BSShaderAccumulator *)(s));
        ::FUN_00b6bee0(i, ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::fnv_00875bd0::FUN_00875bd0_Class *>((((::fnv_008761e0::Mode876 *)(::fnv_00705990::FUN_00705990()))))->FUN_00875bd0(1))), (::BSShaderAccumulator *)(s));
        ::FUN_00b6bee0(i, ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::fnv_00875bd0::FUN_00875bd0_Class *>((((::fnv_008761e0::Mode876 *)(::fnv_00705990::FUN_00705990()))))->FUN_00875bd0(2))), (::BSShaderAccumulator *)(s));
        ::FUN_00b97de0(0, 1);
    }
    ::FUN_00b6bee0(i, ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::StrOwner *>((((::fnv_008761e0::Camera876 *)(::FUN_00707ad0()))))->FUN_007fa950())), (::BSShaderAccumulator *)(s));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(i), (::BSShaderAccumulator *)(::fnv_008761e0::Camera876 *)(a98.FUN_00559450()), 0);
    ::FUN_00714a60(1);
    if (reinterpret_cast<::FUN_008c51c0_shell *>(((*reinterpret_cast<::fnv_008761e0::Global876 * *>(&::_g_thePlayer))))->FUN_008c51c0() && ::fnv_00705a00::FUN_00705a00())
        ::FUN_00714a40(1);
    reinterpret_cast<::FUN_004a0fd0_shell *>((s))->FUN_004a0fd0((::NiNode *)(void *)(0));
    reinterpret_cast<::MenuStub *>((((::fnv_008761e0::Camera876 *)(::FUN_00707ad0()))))->FUN_007fae70((int)(0));
    if (q)
        reinterpret_cast<::FUN_0049ed90_shell *>((q))->FUN_0049ed90(false);
    reinterpret_cast<::_Cam_00712e60 *>((i))->FUN_00712e60((*(const ::_Rect16_00712e60 *)(&h)));
    if (reinterpret_cast<::FUN_00967ae0_cls *>(((*reinterpret_cast<::fnv_008761e0::Global876 * *>(&::_g_thePlayer))))->FUN_00967ae0())
    {
        reinterpret_cast<::FUN_00a59c60_cls *>((f))->FUN_00a59c60((std::intptr_t)(&cf));
        reinterpret_cast<::FUN_00546780_shell *>((f))->FUN_00546780(eb);
        if (a && ((::fnv_008761e0::Camera876 *)(reinterpret_cast<::NiAVObjectFields *>(a)->m_pkParent)))
        {
            reinterpret_cast<::FUN_00440460_S *>((((::fnv_008761e0::Camera876 *)(reinterpret_cast<::NiAVObjectFields *>(a)->m_pkParent))))->FUN_00440460((const ::V3 *)(::fnv_008761e0::V876 *)(&b.pos));
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_008761e0::Camera876 *)(reinterpret_cast<::NiAVObjectFields *>(a)->m_pkParent))))->FUN_00a59c60((std::intptr_t)(&cf));
        }
        ((::_Fake_FUN_008750e0 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->FUN_008750e0(*(NiPoint3*)&(*reinterpret_cast<::fnv_008761e0::V876 *>((void *)&::NiPoint3::ZERO)));
    }
    reinterpret_cast<::BGSExplosion *>((s))->FUN_004fb0b0((::BGSImpactDataSet *)(false));
}
}  // namespace fnv_008761e0

struct SLPoint3
{
    float x;
    float y;
    float z;
};

struct SLWorldSpace;

struct SLCell
{
};

struct SLWorldSpace
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
    virtual const char* GetEditorID();

};

struct SLWorldSpaceList
{
    SLWorldSpace* pItem;
    SLWorldSpaceList* pNext;

    bool IsEmpty();
};

struct SLDataHandler
{
    SLWorldSpaceList* GetWorldSpaces();
    void FUN_004650a0(int aiValue);
};

struct SLSky
{
};

struct SLTES
{
};

struct SLSetting
{
};



// Resolves the starting cell from a name or the starting-cell INI settings, positions the player there, and warns if the cell cannot be found.
// @fnv 0x00876dd0
void __cdecl FUN_00876dd0(const char* apCellName, SLPoint3* apPos)
{
    SLCell* pCell4 = 0;
    bool bWarn = true;
    bool bLoad7 = true;

    if ((apCellName && ::FUN_0044a670(apCellName)) || strlen(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011ded5c))))->GetMenuTitle()))))
    {
        if (apCellName && ::FUN_0044a670(apCellName))
            pCell4 = ((::SLCell *)(reinterpret_cast<::fnv_00461ae0::FUN_00461ae0_shell *>(((*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))))->FUN_00461ae0(apCellName)));
        else
            pCell4 = ((::SLCell *)(reinterpret_cast<::fnv_00461ae0::FUN_00461ae0_shell *>(((*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))))->FUN_00461ae0(((const char *)(::FUN_00464f30((intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011ded5c))))->GetMenuTitle())))))))));
        if (!pCell4)
        {
            int iX = 0;
            int iY4 = 0;
            SLWorldSpace* pWorld8 = ((::SLWorldSpace *)(reinterpret_cast<::TESFileArray *>(((*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))))->FUN_00461cf0(
                (char *)(((const char *)(::FUN_00464f30((intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011ded5c))))->GetMenuTitle()))))))), &iX, &iY4)));
            if (pWorld8)
            {
                reinterpret_cast<::WS458200_Shell *>(((*reinterpret_cast<::SLTES * *>(&::g_TES))))->FUN_00458200((::WS458200_World *)(pWorld8));
                apPos->x = (iX << 12) + ::DAT_01016968;
                apPos->y = (iY4 << 12) + ::DAT_01016968;
                apPos->z = 0.0f;
                reinterpret_cast<::fnv_00454450::ReloadManager *>(((*reinterpret_cast<::SLTES * *>(&::g_TES))))->FUN_00454450((::fnv_00454450::ReloadPoint *)(apPos));
                pCell4 = ((::SLCell *)(reinterpret_cast<::FUN_00461c20_Holder *>(((*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))))->GetOrCreateCell(iX, iY4, (::TESWorldSpace *)(pWorld8), false)));
                bLoad7 = false;
            }
        }
    }
    else if (strlen(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011dee8c))))->GetMenuTitle()))) && strlen(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011debc4))))->GetMenuTitle()))))
    {
        int m_iGridPositionX = std::atoi(((const char *)(::FUN_00464f30((intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011dee8c))))->GetMenuTitle())))))));
        int iCellY8 = std::atoi(((const char *)(::FUN_00464f30((intptr_t)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011debc4))))->GetMenuTitle())))))));
        SLWorldSpace* pWorldA = *((::SLWorldSpace **)(&reinterpret_cast<::SimpleListNodeView*>((*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))->GetWorldSpaces())->m_item));
        SLWorldSpaceList* pIter_ = (*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))->GetWorldSpaces();
        while (pIter_ && !pIter_->IsEmpty())
        {
            SLWorldSpace* m_pContainingWorldspace = *((::SLWorldSpace **)(&reinterpret_cast<::SimpleListNodeView*>(pIter_)->m_item));
            if (!::FUN_00404dc0(m_pContainingWorldspace->GetEditorID(), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011deb48))))->GetMenuTitle()))))
            {
                pWorldA = m_pContainingWorldspace;
                break;
            }
            pIter_ = ((::SLWorldSpaceList *)(reinterpret_cast<::Callees *>((pIter_))->FUN_00726070()));
        }
        if (pWorldA)
        {
            pCell4 = ((::SLCell *)(reinterpret_cast<::WorldCellLoader *>((pWorldA))->FUN_00585b30(m_iGridPositionX, iCellY8)));
            if (!pCell4)
                pCell4 = ((::SLCell *)(reinterpret_cast<::FUN_00461c20_Holder *>(((*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))))->GetOrCreateCell(m_iGridPositionX, iCellY8, (::TESWorldSpace *)(pWorldA), true)));
        }
    }
    else
    {
        bWarn = false;
        bLoad7 = false;
    }

    if (bLoad7)
    {
        if (pCell4)
        {
            if (reinterpret_cast<::TESObjectCELL *>((pCell4))->IsCellInterior())
            {
                reinterpret_cast<::ReloadManager *>(((*reinterpret_cast<::SLTES * *>(&::g_TES))))->AttachScene((::ReloadScene *)(pCell4), (::ReloadPoint *)(apPos));
            }
            else
            {
                reinterpret_cast<::WS458200_Shell *>(((*reinterpret_cast<::SLTES * *>(&::g_TES))))->FUN_00458200((::WS458200_World *)(::SLWorldSpace *)(((::SLWorldSpace *)(reinterpret_cast<::TESObjectCELL *>((pCell4))->GetParentWorldSpace()))));
                apPos->x = (reinterpret_cast<::TESObjectCELL *>((pCell4))->GetCellGridX() << 12) + ::DAT_01016968;
                apPos->y = (reinterpret_cast<::TESObjectCELL *>((pCell4))->GetCellGridY() << 12) + ::DAT_01016968;
                apPos->z = 0.0f;
                reinterpret_cast<::fnv_00454450::ReloadManager *>(((*reinterpret_cast<::SLTES * *>(&::g_TES))))->FUN_00454450((::fnv_00454450::ReloadPoint *)(apPos));
            }
            bLoad7 = false;
        }
        else if (bWarn)
        {
            if (((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011ded5c))))->GetMenuTitle())) && *((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011ded5c))))->GetMenuTitle())))
            {
                ::FUN_005b5e40();
            }
            else if (((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011dee8c))))->GetMenuTitle())) && ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011debc4))))->GetMenuTitle())) && *((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011dee8c))))->GetMenuTitle())) &&
                     *((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011debc4))))->GetMenuTitle())))
            {
                if (((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011deb48))))->GetMenuTitle())) && *((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SLSetting *>(&::g_011deb48))))->GetMenuTitle())))
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
        reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::SLDataHandler * *>(&::g_dataHandler))))->SetSaveLoadGameState(-1);
        if (bLoad7)
        {
            reinterpret_cast<::Shell451 *>(((*reinterpret_cast<::SLTES * *>(&::g_TES))))->FUN_004515a0((::Point451 *)(apPos), true);
            reinterpret_cast<::FUN_004ba7d0_shell *>((((::SLSky *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::SLTES * *>(&::g_TES))))->GetName()))))->FUN_004ba7d0();
        }
    }
}

namespace fnv_008774a0 {
struct FUN_009611e0_ctrl
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058(void* apNode);
};

struct FUN_008774a0_node
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual FUN_008774a0_node* v003();
};

struct FUN_0054ca90_cell
{
};

struct FUN_008774a0_player
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115(int a1, int a2);
    FUN_0054ca90_cell* FUN_008d6f30();
};

struct FUN_007d6bd0_save
{
    bool FUN_007d6bd0(bool abFlag);
};

struct FUN_004539a0_tes
{
};

struct FUN_00ad8780_audio
{
};
struct FUN_006c09f0_mgr
{
};
struct FUN_00970d50_lists
{
    void FUN_00970d50();
};
struct FUN_004614e0_dh
{
    void FUN_004614e0();
};
struct FUN_00b631d0_obj
{
};

void FUN_00706320(int aiValue);


struct FUN_008774a0_shell
{
    void FUN_004f15a0(int aiValue);
    void FUN_008776e0();
    void FUN_008774a0(bool abFlag);
};


// @fnv 0x008774a0
void FUN_008774a0_shell::FUN_008774a0(bool abFlag)
{
    bool bState = reinterpret_cast<::PatrolActorPackageData *>(this)->IsPatrolling();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0);
    reinterpret_cast<::SoundPlaybackHandle *>(((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_player * *>(&::_g_thePlayer))))->FUN_00877700();
    bool bSaveFlag = reinterpret_cast<::FUN_007d6bd0_Class *>(((*reinterpret_cast<::fnv_008774a0::FUN_007d6bd0_save * *>(&::g_BGSSaveLoadGame))))->FUN_007d6bd0(false);
    reinterpret_cast<::BSAudio *>((((::fnv_008774a0::FUN_00ad8780_audio *)(::FUN_00453a70()))))->SetAudioState(-1);
    ::FalloutRadio::SetRadioEnabled(0);
    if (((::fnv_008774a0::FUN_0054ca90_cell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_player * *>(&::_g_thePlayer))))->GetTarget())))
        reinterpret_cast<::fnv_0054ca90::Cell *>((((::fnv_008774a0::FUN_0054ca90_cell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_player * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_0054ca90((::fnv_0054ca90::Ref *)((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_player * *>(&::_g_thePlayer))));

    FUN_008774a0_node* pNode = ((::fnv_008774a0::FUN_008774a0_node *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_player * *>(&::_g_thePlayer))))->FUN_00950bb0(true)));
    FUN_008774a0_node* pRoot = pNode ? pNode->v003() : 0;
    if (pRoot && ((::fnv_008774a0::FUN_009611e0_ctrl *)(reinterpret_cast<::FUN_009611e0_shell *>((pRoot))->FUN_009611e0())))
        ((::fnv_008774a0::FUN_009611e0_ctrl *)(reinterpret_cast<::FUN_009611e0_shell *>((pRoot))->FUN_009611e0()))->v058(pNode);
    pNode = ((::fnv_008774a0::FUN_008774a0_node *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_player * *>(&::_g_thePlayer))))->FUN_00950bb0(false)));
    pRoot = pNode ? pNode->v003() : 0;
    if (pRoot && ((::fnv_008774a0::FUN_009611e0_ctrl *)(reinterpret_cast<::FUN_009611e0_shell *>((pRoot))->FUN_009611e0())))
        ((::fnv_008774a0::FUN_009611e0_ctrl *)(reinterpret_cast<::FUN_009611e0_shell *>((pRoot))->FUN_009611e0()))->v058(pNode);

    reinterpret_cast<::FUN_004539a0_cls *>(((*reinterpret_cast<::fnv_008774a0::FUN_004539a0_tes * *>(&::g_TES))))->FUN_004539a0(0, 0);
    reinterpret_cast<::TESRecipe *>(((*reinterpret_cast<::fnv_008774a0::FUN_004539a0_tes * *>(&::g_TES))))->SetRequiredSkill((::ActorValue::Index)(0x7fffffff));
    reinterpret_cast<::FUN_0061cc40_shell *>(((*reinterpret_cast<::fnv_008774a0::FUN_004539a0_tes * *>(&::g_TES))))->FUN_0061cc40(0x7fffffff);
    reinterpret_cast<::fnv_006c09f0::ManagerView *>((((::fnv_008774a0::FUN_006c09f0_mgr *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c09f0();
    ::FUN_00868d70(0);
    ::FUN_00c459d0(0);
    (*reinterpret_cast<::fnv_008774a0::FUN_008774a0_player * *>(&::_g_thePlayer))->v115(0, 0);
    reinterpret_cast<::fnv_0084a840::FUN_0084a840_shell *>(((*reinterpret_cast<::fnv_008774a0::FUN_007d6bd0_save * *>(&::g_BGSSaveLoadGame))))->FUN_0084a840();
    reinterpret_cast<::Lists970d50 *>((((FUN_00970d50_lists*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_00970d50();
    reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_008774a0::FUN_004614e0_dh * *>(&::g_dataHandler))))->GetRegions();
    reinterpret_cast<::FUN_00b631d0_cls *>((((::fnv_008774a0::FUN_00b631d0_obj *)(::FUN_00b4f5c0()))))->FUN_00b631d0();
    ::FUN_0040fbe0();
    FUN_00706320(0);
    reinterpret_cast<::Target *>(((*reinterpret_cast<::fnv_008774a0::FUN_004539a0_tes * *>(&::g_TES))))->FUN_0045ac80();
    if (abFlag)
        ::fnv_007053f0::FUN_007053f0();
    reinterpret_cast<::FUN_007d6bd0_Class *>(((*reinterpret_cast<::fnv_008774a0::FUN_007d6bd0_save * *>(&::g_BGSSaveLoadGame))))->FUN_007d6bd0(bSaveFlag);
    reinterpret_cast<::FUN_008776e0 *>(((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_shell * *>(&::g_osGlobals))))->SetFlags();
    reinterpret_cast<::FUN_004f15a0_shell *>(((*reinterpret_cast<::fnv_008774a0::FUN_008774a0_shell * *>(&::g_osGlobals))))->FUN_004f15a0(bState);
}
}  // namespace fnv_008774a0

namespace fnv_00873200 {
// Scene traversal, visibility batching, and the main and auxiliary render passes.
// Local-name suffixes preserve the VC++ 2008 stack-slot allocation.

struct ViewNode;
struct ViewGeometry;
struct ViewList;
struct ViewHandle
{
    ViewNode* value;
    ViewNode* FUN_00559450();
};
struct ViewList
{
    void* FUN_00559450();
};
struct ViewNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ViewNode* AsNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void SetCamera(ViewNode* camera);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    bool m_38;
    unsigned char unk39;
    bool m_3a;
    ViewNode* FUN_006629f0();
    unsigned int FUN_0043b480();
    bool FUN_00c4f320(ViewGeometry*);
    int* FUN_0043d4d0();
};
struct ViewGeometry : ViewNode
{
};
// Stand-in for the NiTPointerListBase instance whose RemoveAll is 0x004ed900; the
// class template of that name in layout_support.h hides the non-template stand-in.
struct VisibleList_004ed900
{
    void FUN_004ed900();
};
struct VisibleList
{
    int unk00;
    int unk04;
    int unk08;
    VisibleList();
    ~VisibleList();
};
using MemoryContext = ::AutoMemContext;
struct LocalCull
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    LocalCull(void*);
    ~LocalCull();
};
struct RenderSystem
{
};
struct InterfaceSystem
{
};
ViewNode* FUN_00874690();
ViewNode* FUN_008746a0();
void* FUN_004a0e90();
struct MainView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    ViewHandle m_88;
    ViewHandle m_8c;
    int unk90;
    ViewHandle m_94;
    void FUN_00873200(ViewNode* listener, int unused, bool hide, bool drawInterface);
};
// Builds visible lists from the scene graph, renders the main view and secondary passes, and restores the saved visibility state.
// @fnv 0x00873200
void MainView::FUN_00873200(ViewNode* listener, int unused, bool hide, bool drawInterface)
{
    ViewNode* root3 = ((::fnv_00873200::ViewNode *)(::FUN_0045c670()));
    ViewNode* process = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::SceneGraph *>(root3)->cullingProcess));
    ViewNode* otherProcess;
    ViewNode* cameraX;
    void* renderer2;
    (*reinterpret_cast<::fnv_00873200::ViewNode * *>(&::DAT_011f9684)) = root3->FUN_006629f0();
    if (listener)
        reinterpret_cast<::FUN_00642860_Class *>((listener))->FUN_00642860();
    bool savedVisibility = reinterpret_cast<::FUN_00456630_helper *>((((::fnv_00873200::ViewNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00873200::ViewNode * *>(&::_g_thePlayer))))->FUN_00950bb0(true)))))->FUN_00456610();
    reinterpret_cast<::TaskQueueInterface *>((((::fnv_00873200::ViewNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00873200::ViewNode * *>(&::_g_thePlayer))))->FUN_00950bb0(true)))))->QueueActorDisarm(true);
    m_88.FUN_00559450()->m_38 = !hide;
    ViewNode* imageEffect5 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::FUN_004ebbc0_shell *>((((::fnv_00873200::ViewNode *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_004ebbc0(4)));
    m_88.FUN_00559450()->m_3a = !hide && ::FUN_00871220((char *)(imageEffect5));
    m_8c.FUN_00559450()->m_3a = !hide && ::FUN_00871220((char *)(imageEffect5));
    MemoryContext memory7(15, true, ::DAT_010829c4, 0x1eb7);
    cameraX = 0;
    cameraX = root3->FUN_006629f0();
    reinterpret_cast<::FUN_0041fd00_shell *>((process))->FUN_0041fd00((intptr_t)(cameraX));
    reinterpret_cast<::S694a0 *>((process))->FUN_00a694a0(((void *)&(reinterpret_cast<::NiCamera *>((cameraX))->GetViewFrustum())));
    reinterpret_cast<::FUN_004a0fd0_shell *>((process))->FUN_004a0fd0((::NiNode *)(::fnv_00873200::ViewNode *)(m_88.FUN_00559450()));
    // Partition visible objects between the two culling passes.
    if (::DAT_011f94b4)
    {
        VisibleList leftList2;
        VisibleList rightList4;
        VisibleList commonList3;
        ViewNode* graph = ((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
        ViewNode* node2 = 0;
        ViewNode* branch = 0;
        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((graph))->FUN_0045bc00(0)));
        if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
            reinterpret_cast<::FUN_004ed8c0_shell *>(&(commonList3))->FUN_004ed8c0((int *)&(node2));
        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((graph))->FUN_0045bc00(1)));
        if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
            reinterpret_cast<::FUN_004ed8c0_shell *>(&(commonList3))->FUN_004ed8c0((int *)&(node2));
        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((graph))->FUN_0045bc00(2)));
        if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
            branch = node2->AsNode();
        if (branch)
        {
            node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(0)));
            if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
                reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(node2));
            node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(1)));
            if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
                reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(node2));
            node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(2)));
            if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
                reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(node2));
        }
        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((graph))->FUN_0045bc00(3)));
        branch = node2->AsNode();
        // Exterior and interior scenes organize their child nodes differently.
        if (!((::fnv_00873200::ViewNode *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_00873200::ViewNode * *>(&::g_TES))))->GetPrevPath())))
        {
            if (branch && !reinterpret_cast<::FUN_00456630_helper *>((branch))->FUN_00456610())
            {
                for (int i = 0; i < branch->FUN_0043b480(); ++i)
                {
                    node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::NiNode *>((branch))->GetAt(i)));
                    if (node2)
                    {
                        ViewNode* section = node2->AsNode();
                        if (section && !reinterpret_cast<::FUN_00456630_helper *>((section))->FUN_00456610())
                        {
                            for (int j = 0; j < section->FUN_0043b480(); ++j)
                            {
                                ViewNode* item = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::NiNode *>((section))->GetAt(j)));
                                if (item)
                                {
                                    ViewNode* nested = item->AsNode();
                                    if (nested)
                                    {
                                        if (!reinterpret_cast<::FUN_00456630_helper *>((nested))->FUN_00456610())
                                        {
                                            int k = 0;
                                            if (j == 6)
                                                k = 1;
                                            for (; k < nested->FUN_0043b480(); ++k)
                                            {
                                                ViewNode* leaf = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::NiNode *>((nested))->GetAt(k)));
                                                if (leaf && !reinterpret_cast<::FUN_00456630_helper *>((leaf))->FUN_00456610())
                                                {
                                                    if (i % 2)
                                                        reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(leaf));
                                                    else
                                                        reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(leaf));
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (i % 2)
                                            reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(item));
                                        else
                                            reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(item));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (((bool)(reinterpret_cast<::FUN_00874650Class *>((((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00874650())))
            {
                node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(0)));
                if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
                    reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(node2));
                node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(1)));
                if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
                    reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(node2));
                node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(2)));
                if (node2)
                {
                    branch = node2->AsNode();
                    if (branch && !reinterpret_cast<::FUN_00456630_helper *>((branch))->FUN_00456610())
                    {
                        for (int outerIndex = 0; outerIndex < branch->FUN_0043b480(); ++outerIndex)
                        {
                            node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::NiNode *>((branch))->GetAt(outerIndex)));
                            if (node2 && outerIndex != 4 && outerIndex != 0)
                            {
                                ViewNode* section2 = node2->AsNode();
                                if (section2 && !reinterpret_cast<::FUN_00456630_helper *>((section2))->FUN_00456610())
                                {
                                    int childIndex = 0;
                                    if (outerIndex == 6)
                                        childIndex = 1;
                                    for (; childIndex < section2->FUN_0043b480(); ++childIndex)
                                    {
                                        ViewNode* leaf2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::NiNode *>((section2))->GetAt(childIndex)));
                                        if (leaf2 && !reinterpret_cast<::FUN_00456630_helper *>((leaf2))->FUN_00456610())
                                        {
                                            if (childIndex % 2)
                                                reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(leaf2));
                                            else
                                                reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(leaf2));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(2)));
                if (node2)
                {
                    branch = node2->AsNode();
                    if (branch && !reinterpret_cast<::FUN_00456630_helper *>((branch))->FUN_00456610())
                    {
                        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((branch))->FUN_0045bc00(7)));
                        if (node2)
                        {
                            branch = node2->AsNode();
                            if (branch)
                            {
                                for (int index3 = 0; index3 < branch->FUN_0043b480(); ++index3)
                                {
                                    ViewNode* leaf3 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::NiNode *>((branch))->GetAt(index3)));
                                    if (leaf3 && !reinterpret_cast<::FUN_00456630_helper *>((leaf3))->FUN_00456610())
                                    {
                                        if (index3 % 2)
                                            reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(leaf3));
                                        else
                                            reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(leaf3));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ViewNode* area = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::FUN_00454b30_class *>((((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00454b30()));
            ViewList* roomsTmp = area ? ((::fnv_00873200::ViewList *)(reinterpret_cast<::TESTopicInfo *>((area))->GetAddTopicList())) : 0;
            void* roomPosition4 = roomsTmp ? roomsTmp->FUN_00559450() : 0;
            int visibleCount = 0;
            while (roomPosition4)
            {
                ViewNode* room = ((::fnv_00873200::ViewHandle *)(reinterpret_cast<::ListStandIn *>((((::fnv_00873200::ViewList *)(reinterpret_cast<::TESTopicInfo *>((area))->GetAddTopicList()))))->FUN_0057cbe0((int **)(void **)(&roomPosition4))))->FUN_00559450();
                if (room && !reinterpret_cast<::FUN_0076b610_Class *>((((::fnv_00873200::ViewList *)(reinterpret_cast<::BSMultiBoundRoom *>((room))->FUN_006ab360()))))->FUN_0076b610())
                {
                    void* itemPosition = ((::fnv_00873200::ViewList *)(reinterpret_cast<::BSMultiBoundRoom *>((room))->FUN_006ab360()))->FUN_00559450();
                    while (itemPosition)
                    {
                        ViewNode* object = ((::fnv_00873200::ViewHandle *)(reinterpret_cast<::ListStandIn *>((((::fnv_00873200::ViewList *)(reinterpret_cast<::BSMultiBoundRoom *>((room))->FUN_006ab360()))))->FUN_0057cbe0((int **)(void **)(&itemPosition))))->value;
                        if (object && process->FUN_00c4f320(((::fnv_00873200::ViewGeometry *)(reinterpret_cast<::FUN_0045c4c0_cls *>((object))->FUN_0045c4c0()))))
                        {
                            ViewGeometry* geometry = ((::fnv_00873200::ViewGeometry *)(reinterpret_cast<::FUN_0045c4c0_cls *>((object))->FUN_0045c4c0()));
                            if (geometry)
                            {
                                if (::FUN_00874480((char *)(object)) && ((int)(reinterpret_cast<::FUN_009b4440_shell *>((object))->FUN_009b4440())))
                                {
                                    reinterpret_cast<::SPShader *>((((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5ba80((((::fnv_00873200::ViewNode *)(reinterpret_cast<::FUN_0084e3a0_Class *>((process))->FUN_0084e3a0()))), (::SPPass *)(object));
                                }
                                if (visibleCount % 2)
                                    reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(geometry));
                                else
                                    reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(geometry));
                                ++visibleCount;
                            }
                        }
                    }
                }
            }
            if (((bool)(reinterpret_cast<::FUN_00874650Class *>((((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00874650())))
            {
                void* objectPosition = ((::fnv_00873200::ViewList *)(reinterpret_cast<::NonActorMagicTarget *>((area))->GetActiveEffectList()))->FUN_00559450();
                while (objectPosition)
                {
                    ViewNode* object2 = ((::fnv_00873200::ViewHandle *)(reinterpret_cast<::ListStandIn *>((((::fnv_00873200::ViewList *)(reinterpret_cast<::NonActorMagicTarget *>((area))->GetActiveEffectList()))))->FUN_0057cbe0((int **)(void **)(&objectPosition))))->value;
                    if (object2 && process->FUN_00c4f320(((::fnv_00873200::ViewGeometry *)(reinterpret_cast<::FUN_0045c4c0_cls *>((object2))->FUN_0045c4c0()))))
                    {
                        ViewGeometry* geometry2 = ((::fnv_00873200::ViewGeometry *)(reinterpret_cast<::FUN_0045c4c0_cls *>((object2))->FUN_0045c4c0()));
                        if (geometry2)
                        {
                            if (visibleCount % 2)
                                reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(geometry2));
                            else
                                reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(geometry2));
                            ++visibleCount;
                        }
                    }
                }
            }
            ViewNode* extra6 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((::fnv_00873200::ViewNode *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>(((*reinterpret_cast<::fnv_00873200::ViewNode * *>(&::g_TES))))->FUN_00457070()))))->FUN_009d9f20()));
            if (extra6)
            {
                for (int extraIndex = 0; extraIndex < reinterpret_cast<::FUN_00c5b5d0_class *>((extra6))->FUN_00c5b5d0(); ++extraIndex)
                {
                    ViewNode* extraNode = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::FUN_00c5b5a0_cls *>((extra6))->FUN_00c5b5a0(extraIndex)));
                    if (extraNode)
                        reinterpret_cast<::FUN_004ed8c0_shell *>(&(commonList3))->FUN_004ed8c0((int *)&(extraNode));
                }
            }
        }
        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((graph))->FUN_0045bc00(4)));
        if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
            reinterpret_cast<::FUN_004ed8c0_shell *>(&(commonList3))->FUN_004ed8c0((int *)&(node2));
        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((graph))->FUN_0045bc00(5)));
        if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
            reinterpret_cast<::FUN_004ed8c0_shell *>(&(commonList3))->FUN_004ed8c0((int *)&(node2));
        node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((graph))->FUN_0045bc00(6)));
        if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
            reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(node2));
        for (int tailIndex = 7; tailIndex < graph->FUN_0043b480(); ++tailIndex)
        {
            node2 = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::NiNode *>((graph))->GetAt(tailIndex)));
            if (node2 && !reinterpret_cast<::FUN_00456630_helper *>((node2))->FUN_00456610())
            {
                if (tailIndex % 2)
                    reinterpret_cast<::FUN_004ed8c0_shell *>(&(leftList2))->FUN_004ed8c0((int *)&(node2));
                else
                    reinterpret_cast<::FUN_004ed8c0_shell *>(&(rightList4))->FUN_004ed8c0((int *)&(node2));
            }
        }
        reinterpret_cast<::FUN_0041fd00_shell *>((process))->FUN_0041fd00((intptr_t)(cameraX));
        reinterpret_cast<::fnv_00b5e870::Self *>((((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5e870((::fnv_00b5e870::ParamObj *)(process));
        if (((::fnv_00873200::ViewNode *)(::FUN_00874670((char *)(((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))))))
            reinterpret_cast<::ControlGraph *>((((::fnv_00873200::ViewNode *)(::FUN_00874670((char *)(((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))))))->FUN_00c49850();
        m_88.FUN_00559450()->SetCamera(cameraX);
        ::FUN_00b54ac0((::NiTexture *)(::fnv_00873200::ViewNode *)(m_88.FUN_00559450()));
        reinterpret_cast<::FUN_004dc540_shell *>((((::fnv_00873200::ViewNode *)(::FUN_0043c4b0()))))->FUN_004dc540((::NiAVObject *)(::fnv_00873200::ViewNode *)(m_88.FUN_00559450()));
        ::AccumTaskDetail::FUN_00ba3390((::AccumTaskDetail::AccumTaskReceiver *)(((::fnv_00873200::RenderSystem *)(::TaskThreadManager::GetSingleton()))), cameraX, (::AccumTaskDetail::NiRefObject *)(::fnv_00873200::ViewNode *)(((::fnv_00873200::ViewNode *)(::FUN_00874670((char *)(((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))))), (::AccumTaskDetail::TaskArg1 *)(0), (::AccumTaskDetail::NiRefObject *)(::fnv_00873200::VisibleList *)(&leftList2), (void *)(0), m_88.FUN_00559450(), (::AccumTaskDetail::NiRefObject *)(0),
                                     21, true, {});
        reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_00873200::RenderSystem *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0(0, 21);
        ::DAT_012722bc = 0;
        LocalCull localProcess(0);
        reinterpret_cast<::FUN_0041fd00_shell *>(&(localProcess))->FUN_0041fd00((intptr_t)(cameraX));
        reinterpret_cast<::FUN_004a0fd0_shell *>(&(localProcess))->FUN_004a0fd0((::NiNode *)(::fnv_00873200::ViewNode *)(m_88.FUN_00559450()));
        reinterpret_cast<::FUN_00874460_cls *>(&(localProcess))->set((intptr_t)(((::fnv_00873200::ViewNode *)(::FUN_00874670((char *)(((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))))));
        ::FUN_00b6bfc0(cameraX, (*(::PointerList6b *)(&rightList4)), (::Accumulator6b *)(::fnv_00873200::LocalCull *)(&localProcess));
        reinterpret_cast<::FUN_00874460_cls *>(&(localProcess))->set((int)(0));
        ::FUN_00b6bfc0(cameraX, (*(::PointerList6b *)(&commonList3)), (::Accumulator6b *)(::fnv_00873200::LocalCull *)(&localProcess));
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_00873200::RenderSystem *)(::TaskThreadManager::GetSingleton()))), (void *)(1), 21, {});
        reinterpret_cast<::NiTPointerListBaseRaw *>(&(leftList2))->FUN_004ed900();
        reinterpret_cast<::NiTPointerListBaseRaw *>(&(rightList4))->FUN_004ed900();
    }
    else
    {
        ::FUN_00b6bee0(cameraX, root3, (::BSShaderAccumulator *)(process));
    }
    // Finish the main scene and draw the requested interface layer.
    ::FUN_00b6ba20((::NiCamera *)(::fnv_00873200::ViewNode *)(root3->FUN_006629f0()), (::ShaderAccB6BA *)(::fnv_00873200::ViewNode *)(m_88.FUN_00559450()));
    if (drawInterface)
    {
        ::BSRenderStateManager::SetColorWriteMask(0, (::BSRENDERSTATE_LOCK)(1));
        reinterpret_cast<::VATSRender *>((((::fnv_00873200::InterfaceSystem *)(::fnv_00705910::FUN_00705910()))))->FUN_00800f30((::RenderTexture *)(0), 2, 1, 0, 0, 0);
        ::FUN_004eced0(1);
    }
    ::FUN_00b6b930((uintptr_t)(root3->FUN_006629f0()), (::FUN_00b6b930_Object *)(::fnv_00873200::ViewNode *)(m_88.FUN_00559450()));
    if (::DAT_011f94b4)
        ::FUN_00a89af0((std::intptr_t)(((::fnv_00873200::ViewNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))));
    reinterpret_cast<::FUN_004a0fd0_shell *>((process))->FUN_004a0fd0((::NiNode *)(::fnv_00873200::ViewNode *)(0));
    memory7.Leave();
    m_88.FUN_00559450()->m_38 = false;
    m_88.FUN_00559450()->m_3a = false;
    ::FUN_008746c0();
    // Render the auxiliary scene views through the secondary culling process.
    renderer2 = FUN_004a0e90();
    otherProcess = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::SceneGraph *>(((::fnv_00873200::ViewNode *)(::FUN_0045c670())))->cullingProcess));
    reinterpret_cast<::BGSExplosion *>((otherProcess))->FUN_004fb0b0((::BGSImpactDataSet *)(true));
    ::FUN_00b803b0((::Camera_00b803b0 *)(::fnv_00873200::ViewNode *)((*reinterpret_cast<::fnv_00873200::ViewHandle *>(&::g_011deb7c)).FUN_00559450()->FUN_006629f0()));
    reinterpret_cast<::FUN_0041fd00_shell *>((otherProcess))->FUN_0041fd00((intptr_t)(FUN_00874690()));
    reinterpret_cast<::FUN_004a0fd0_shell *>((otherProcess))->FUN_004a0fd0((::NiNode *)(::fnv_00873200::ViewNode *)(m_94.FUN_00559450()));
    ::FUN_00b6bee0(FUN_00874690(), ((::fnv_00873200::ViewNode *)(::fnv_005bac50::FUN_005bac50())), (::BSShaderAccumulator *)(otherProcess));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(::fnv_00873200::ViewNode *)(FUN_00874690()), (::BSShaderAccumulator *)(::fnv_00873200::ViewNode *)(m_94.FUN_00559450()), false);
    reinterpret_cast<::FUN_004a0fd0_shell *>((process))->FUN_004a0fd0((::NiNode *)(::fnv_00873200::ViewNode *)(0));
    reinterpret_cast<::BGSExplosion *>((otherProcess))->FUN_004fb0b0((::BGSImpactDataSet *)(false));
    ::FUN_008746c0();
    renderer2 = FUN_004a0e90();
    otherProcess = ((::fnv_00873200::ViewNode *)(reinterpret_cast<::SceneGraph *>(((::fnv_00873200::ViewNode *)(::FUN_0045c670())))->cullingProcess));
    reinterpret_cast<::BGSExplosion *>((otherProcess))->FUN_004fb0b0((::BGSImpactDataSet *)(true));
    ::FUN_00b803b0((::Camera_00b803b0 *)(::fnv_00873200::ViewNode *)((*reinterpret_cast<::fnv_00873200::ViewHandle *>(&::g_011deb7c)).FUN_00559450()->FUN_006629f0()));
    reinterpret_cast<::FUN_0041fd00_shell *>((otherProcess))->FUN_0041fd00((intptr_t)(((::fnv_00873200::ViewNode *)(::fnv_008746b0::FUN_008746b0()))));
    reinterpret_cast<::FUN_004a0fd0_shell *>((otherProcess))->FUN_004a0fd0((::NiNode *)(::fnv_00873200::ViewNode *)(m_94.FUN_00559450()));
    ::FUN_00b6bee0(((::fnv_00873200::ViewNode *)(::fnv_008746b0::FUN_008746b0())), FUN_008746a0(), (::BSShaderAccumulator *)(otherProcess));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(::fnv_00873200::ViewNode *)(((::fnv_00873200::ViewNode *)(::fnv_008746b0::FUN_008746b0()))), (::BSShaderAccumulator *)(::fnv_00873200::ViewNode *)(m_94.FUN_00559450()), false);
    reinterpret_cast<::FUN_004a0fd0_shell *>((process))->FUN_004a0fd0((::NiNode *)(::fnv_00873200::ViewNode *)(0));
    reinterpret_cast<::BGSExplosion *>((otherProcess))->FUN_004fb0b0((::BGSImpactDataSet *)(false));
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00873200::ViewNode *>(&::g_011c3ea4)))))) > 1)
        ::AIThreadManager::SetThreadingEnabled(0);
    if ((*reinterpret_cast<bool *>(&::DAT_011f94a9)))
        ::FUN_008744a0((::ScaleSource *)(::fnv_00873200::ViewNode *)(root3->FUN_006629f0()));
    if (listener)
        reinterpret_cast<::A6A0Sun *>((listener))->FUN_006426a0((void *)(true), (::A6A0Target *)(::fnv_00873200::ViewNode *)(m_88.FUN_00559450()), (*reinterpret_cast<::fnv_00873200::ViewHandle *>(&::g_011deb7c)).FUN_00559450()->FUN_006629f0());
    ::FUN_00872dd0(false, false);
    reinterpret_cast<::TaskQueueInterface *>((((::fnv_00873200::ViewNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00873200::ViewNode * *>(&::_g_thePlayer))))->FUN_00950bb0(true)))))->QueueActorDisarm(savedVisibility);
}
}  // namespace fnv_00873200

namespace fnv_00877730 {
struct GlobalObject_0045cf30;
class ImageSpaceManager;
using AutoMemHelper = ::AutoMemContext;
union SETTING_VALUE
{
    bool b;
    int i;
};

struct NiUpdateData
{
    NiUpdateData(float f, bool bb, bool g);
    float m_f;
    bool m_kPointB;
    bool m_g;
    bool flag06, flag07, flag08;
};

struct NiObject;
struct TESLevItem;
class NiNode
{
  public:
    void Update(const NiUpdateData& data);
};

struct GO00
{
    NiNode* FUN_00559450();
};
struct GO34
{
    NiNode* FUN_00559450();
};
struct GOa4
{
    NiNode* FUN_00559450();
};

class INISettingCollection;
template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};

struct ProcObj
{
    void* FUN_0045cd60();
};

struct ModelOps
{
};

struct FUN_0049ec80_Property : NiRefObject
{
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    unsigned int unknown14;
    unsigned short flags18;
    unsigned char alphaThreshold1a;
    unsigned char unknown1b;
    unsigned int unknown1c;
    unsigned int unknown20;
    FUN_0049ec80_Property();
    void FUN_0049ed90(bool b);
};
typedef FUN_0049ec80_Property NiAlphaProperty;
struct HostV
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37(void* p, int i);
};

struct LightShell
{
};

struct ISM2
{
};


// @fnv 0x00877730
void FUN_00877730()
{
    AutoMemHelper helper8(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\Main.cpp", 0x26bd);
    ::FUN_0040fbe0();
    reinterpret_cast<::fnv_0063a630::ThisCls *>(((*reinterpret_cast<::fnv_00877730::ProcObj * *>(&::DAT_011dea20))))->FUN_0063a630((::fnv_0063a630::NiNode *)(void *)((*reinterpret_cast<::fnv_00877730::GO34 *>(&::g_011deb34)).FUN_00559450()), (intptr_t)((*reinterpret_cast<::fnv_00877730::GO00 *>(&::g_011deb00)).FUN_00559450()));
    ((HostV*)(*reinterpret_cast<::fnv_00877730::GOa4 *>(&::g_011deda4)).FUN_00559450())->v37(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(((ModelOps*)(void*)((void *)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::fnv_00877730::ProcObj * *>(&::DAT_011dea20))))->FUN_0045cd60()))))))), 1);
    reinterpret_cast<::FUN_00b5aac0_shell *>((((LightShell*)((::fnv_00877730::LightShell *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))))->FUN_00b5aac0((::NiDirectionalLight *)(void *)((void*)((void *)(reinterpret_cast<::FUN_004505a0_cls *>(((*reinterpret_cast<::fnv_00877730::ProcObj * *>(&::DAT_011dea20))))->FUN_004505a0()))));
    reinterpret_cast<::FUN_00a5a040_Class *>(((*reinterpret_cast<::fnv_00877730::GO34 *>(&::g_011deb34)).FUN_00559450()))->FUN_00a5a040();
    ::FUN_00b8b200((bool)(((ISM2*)((::fnv_00877730::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270())))));
    if (((SettingT<INISettingCollection>*)&(*reinterpret_cast<::fnv_00877730::GlobalObject_0045cf30 *>(&::g_011deadc)))->Bool()->b)
    {
        NiAlphaProperty* obj = new NiAlphaProperty;
        reinterpret_cast<::FUN_0049ed90_shell *>((((NiAlphaProperty*)obj)))->FUN_0049ed90(true);
        reinterpret_cast<::fnv_0049ede0::FUN_0049ede0_shell *>((obj))->FUN_0049ede0(2);
        reinterpret_cast<::BGSDehydrationStage *>((obj))->FUN_0050f9a0((::SpellItem *)(0xff));
        reinterpret_cast<::FUN_00439410_cls *>(((*reinterpret_cast<::fnv_00877730::GO34 *>(&::g_011deb34)).FUN_00559450()))->FUN_00439410((::ArgObject *)(::fnv_00877730::NiObject *)((NiObject*)obj));
    }
    NiUpdateData upd1(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((*reinterpret_cast<::fnv_00877730::GO34 *>(&::g_011deb34)).FUN_00559450()))->FUN_00a59c60((std::intptr_t)&(upd1));
    reinterpret_cast<::FUN_00a5a040_Class *>(((*reinterpret_cast<::fnv_00877730::GOa4 *>(&::g_011deda4)).FUN_00559450()))->FUN_00a5a040();
    NiUpdateData updTmp(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((*reinterpret_cast<::fnv_00877730::GOa4 *>(&::g_011deda4)).FUN_00559450()))->FUN_00a59c60((std::intptr_t)&(updTmp));
    ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(void *)((*reinterpret_cast<::fnv_00877730::GO34 *>(&::g_011deb34)).FUN_00559450()), 0, 0);
    ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(void *)(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(((ModelOps*)(void*)((void *)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::fnv_00877730::ProcObj * *>(&::DAT_011dea20))))->FUN_0045cd60())))))))), 0, 0);
}
}  // namespace fnv_00877730

struct IDIDevice8
{
    virtual long QueryInterface(const void* riid, void** ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual long GetCapabilities(void* caps);
    virtual long EnumObjects(void* cb, void* ref, unsigned long flags);
    virtual long GetProperty(const void* guid, void* prop);
    virtual long SetProperty(const void* guid, const void* prop);
    virtual long Acquire();
    virtual long Unacquire();
    virtual long GetDeviceState(unsigned long cb, void* data);
    virtual long GetDeviceData(unsigned long cbObjectData, void* rgdod, unsigned long* pdwInOut,
                                         unsigned long flags);
};
struct DIDeviceOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    IDIDevice8* m_pDirectInputDevice;
    void FUN_00a237b0();
};
// @fnv 0x00a237b0
void DIDeviceOwner::FUN_00a237b0()
{
    if (m_pDirectInputDevice)
    {
        unsigned long dwItems = 0xffffffff;
        m_pDirectInputDevice->GetDeviceData(0x14, 0, &dwItems, 0);
    }
}

extern short DAT_011f35b0;
extern short DAT_011f35b2;
extern bool DAT_011f35c8;

struct FUN_00a23390_t
{
    int GetAxisState(int device, int axis);
};

// Returns the state of the specified controller axis, reading from per-device state or global fallback values for axes 7-10.
// @fnv 0x00a23390
int FUN_00a23390_t::GetAxisState(int device, int axis)
{
    int* pAxisState = (int*)((char*)this + device * 0xa0 + 0x34);
    switch (axis)
    {
    case 1:
        return pAxisState[0];
    case 2:
        return pAxisState[1];
    case 3:
        return pAxisState[2];
    case 4:
        return pAxisState[3];
    case 5:
        return pAxisState[4];
    case 6:
        return pAxisState[5];
    case 7:
        if (DAT_011f35c8)
            return DAT_011f35b0;
        break;
    case 8:
        if (DAT_011f35c8)
            return DAT_011f35b2;
        break;
    case 9:
        if (DAT_011f35c8)
            return DAT_011f35b4;
        break;
    case 10:
        if (DAT_011f35c8)
            return DAT_011f35b6;
        break;
    }
    return 0;
}

namespace sa238a0 {

extern unsigned char DAT_011a7440[256];
extern unsigned char DAT_011a7540[256];
extern unsigned char DAT_011a7640[256];
extern unsigned char DAT_011a7740[256];
extern unsigned char DAT_011a7840[256];
extern unsigned char DAT_011a7940[256];
extern unsigned char DAT_011a7a40[256];
extern unsigned char DAT_011a7b40[256];
extern unsigned char DAT_011a7c40[256];
extern unsigned char DAT_011a7d40[256];


struct CharTable
{
    int FUN_00a238a0(int iChar, int iMode);
};

// Bounds-checks iChar, then returns a byte from a 256-entry table selected by iMode and FUN_00a22cb0().
// @fnv 0x00a238a0
int CharTable::FUN_00a238a0(int iChar, int iMode)
{
    if (iChar < 0 || iChar > 0xff)
        return -1;
    if (iMode == 0xff)
        return DAT_011a7540[iChar];
    switch (((int)(::BSSysInfoSystemUtility::GetRandomGenerator())))
    {
    case 3:
        return iMode ? DAT_011a7b40[iChar] : DAT_011a7a40[iChar];
    case 4:
        return iMode ? DAT_011a7d40[iChar] : DAT_011a7c40[iChar];
    case 2:
        return iMode ? DAT_011a7940[iChar] : DAT_011a7840[iChar];
    case 1:
        return iMode ? DAT_011a7740[iChar] : DAT_011a7640[iChar];
    default:
        return iMode ? DAT_011a7540[iChar] : DAT_011a7440[iChar];
    }
}

}

namespace fnv_00872b00 {
struct ImageSpaceEffectParam
{
    float f0;
    float f4;
    float f8;
    float fC;
    ImageSpaceEffectParam(float a, float b, float c, float d);
};
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    int iFlags;
    NiUpdateData(float t, bool a, bool b);
};
struct ISMgr
{
};
struct ISHolder
{
};
struct StateObj
{
};
struct PlayerCharacter;
struct BSShaderManager
{
};
struct NiCamera;
struct NiAVObject
{
    void Update(NiUpdateData& d);
};
struct CamNode
{
    NiCamera* GetAnimationData();
};
struct CamNodePtr
{
    operator CamNode*() const;
};
struct NodePtr
{
    operator NiAVObject*() const;
};
struct BoolSetting
{
    bool* Bool();
};
struct CamWatcher
{
    int unk00;
    CamWatcher();
    ~CamWatcher();
};
extern unsigned char DAT_011f94a5;
struct Sky
{
    void* FUN_0045cd60();
};
struct TES
{
    Sky* FUN_008d8520();
};

struct MainX
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    bool bFlag9C;
    void* UpdateCamera();
};

// Applies image-space parameters, sets FOV, updates two scene objects from camera data, and returns a sky-provided pointer when conditions match.
// @fnv 0x00872b00
void* MainX::UpdateCamera()
{
    reinterpret_cast<::_Cam_00712e60 *>((((ISMgr*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))->FUN_00712e60((const ::_Rect16_00712e60 &)((*reinterpret_cast<::fnv_00872b00::ImageSpaceEffectParam *>(&::DAT_011ad840))));
    if (reinterpret_cast<::VATSCameraDataView *>(&::g_011f2250)->mode != 4)
    {
        reinterpret_cast<::C52020Obj *>((((ISHolder*)((::BSFaceGenNiNode *)(::FUN_0045c670())))))->FUN_00c52020(::FUN_00710ab0((::FUN_00710ab0_Class *)((*reinterpret_cast<::fnv_00872b00::PlayerCharacter * *>(&::_g_thePlayer)))), 0, (::C52020Obj *)(0), true);
    }
    ::BSShaderManager::SetFOV(::FUN_00710ab0((::FUN_00710ab0_Class *)((*reinterpret_cast<::fnv_00872b00::PlayerCharacter * *>(&::_g_thePlayer)))));
    if (bFlag9C)
    {
        reinterpret_cast<::_Cam_00712e60 *>((((ISMgr*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))->FUN_00712e60((const ::_Rect16_00712e60 &)((const ::fnv_00872b00::ImageSpaceEffectParam &)(ImageSpaceEffectParam(0.0f, 1.0f, 1.0f, 0.0f))));
    }
    NiCamera* pCamera = ((CamNode*)(*reinterpret_cast<::fnv_00872b00::CamNodePtr *>(&::g_011deb7c)))->GetAnimationData();
    NiCamera* pOverride6 = 0;
    if (*(*reinterpret_cast<::fnv_00872b00::BoolSetting *>(&::g_011ded80)).Bool())
    {
        static CamWatcher kWatcher;
        reinterpret_cast<::FUN_008d6f50_Class *>(&(kWatcher))->FUN_008d6f50((intptr_t)(pOverride6 ? pOverride6 : pCamera));
    }
    reinterpret_cast<::FUN_00440460_S *>((((NiAVObject*)(*reinterpret_cast<::fnv_00872b00::NodePtr *>(&::g_011deb34)))))->FUN_00440460((const ::V3 *)&(reinterpret_cast<::NiAVObject *>((((::fnv_00872b00::NiAVObject *)(::FUN_00558310((::NiNode_00558310 *)(((CamNode*)(*reinterpret_cast<::fnv_00872b00::CamNodePtr *>(&::g_011deb7c)))))))))->FUN_0043c490()));
    NiUpdateData kData5(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiAVObject*)(*reinterpret_cast<::fnv_00872b00::NodePtr *>(&::g_011deb34)))))->FUN_00a59c60((std::intptr_t)&(kData5));
    reinterpret_cast<::FUN_00440460_S *>((((NiAVObject*)(*reinterpret_cast<::fnv_00872b00::NodePtr *>(&::g_011deda4)))))->FUN_00440460((const ::V3 *)&(reinterpret_cast<::NiAVObject *>((((::fnv_00872b00::NiAVObject *)(::FUN_00558310((::NiNode_00558310 *)(((CamNode*)(*reinterpret_cast<::fnv_00872b00::CamNodePtr *>(&::g_011deb7c)))))))))->FUN_0043c490()));
    NiUpdateData kData2(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiAVObject*)(*reinterpret_cast<::fnv_00872b00::NodePtr *>(&::g_011deda4)))))->FUN_00a59c60((std::intptr_t)&(kData2));
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011f9fc0)))
    {
        (*reinterpret_cast<unsigned char *>(&::DAT_011f9fc0)) = 0;
        (*reinterpret_cast<unsigned char *>(&::DAT_011f9fc1)) = 1;
    }
    ::FUN_00872dd0(*(*reinterpret_cast<::fnv_00872b00::BoolSetting *>(&::g_011decd8)).Bool(), true);
    ::FUN_00872df0(*(*reinterpret_cast<::fnv_00872b00::BoolSetting *>(&::g_011deb60)).Bool());
    DAT_011f94a5 = 0;
    void* pResult = 0;
    if (((::fnv_00872b00::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_00872b00::TES * *>(&::g_TES))))->GetBaseTexture())) && ((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_00872b00::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_00872b00::TES * *>(&::g_TES))))->GetBaseTexture()))))->FUN_0045cd60())) &&
        (((int)(reinterpret_cast<::FUN_00476c90_Class *>((((::fnv_00872b00::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_00872b00::TES * *>(&::g_TES))))->GetBaseTexture()))))->FUN_00476c90())) == 3 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((((::fnv_00872b00::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_00872b00::TES * *>(&::g_TES))))->GetBaseTexture()))))->FUN_00476c90())) == 2))
    {
        pResult = ((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_00872b00::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_00872b00::TES * *>(&::g_TES))))->GetBaseTexture()))))->FUN_0045cd60()));
    }
    return pResult;
}
}  // namespace fnv_00872b00

namespace fnv_0086ff70 {
struct Main86 : Main
{
    void FUN_0086ff70();
};
struct Extra86
{
};
struct PlayerState86
{
    virtual bool vfn_000();
    virtual bool vfn_004();
    virtual bool vfn_008();
    virtual bool vfn_00c();
    virtual bool vfn_010();
    virtual bool vfn_014();
    virtual bool vfn_018();
    virtual bool vfn_01c();
    virtual bool vfn_020();
    virtual bool vfn_024();
    virtual bool vfn_028();
    virtual bool vfn_02c();
    virtual bool vfn_030();
    virtual bool vfn_034();
    virtual bool vfn_038();
    virtual bool vfn_03c();
    virtual bool vfn_040();
    virtual bool vfn_044();
    virtual bool vfn_048();
    virtual bool vfn_04c();
    virtual bool vfn_050();
    virtual bool vfn_054();
    virtual bool vfn_058();
    virtual bool vfn_05c();
    virtual bool vfn_060();
    virtual bool vfn_064();
    virtual bool vfn_068();
    virtual bool vfn_06c();
    virtual bool vfn_070();
    virtual bool vfn_074();
    virtual bool vfn_078();
    virtual bool vfn_07c();
    virtual bool vfn_080();
    virtual bool vfn_084();
    virtual bool vfn_088();
    virtual bool vfn_08c();
    virtual bool vfn_090();
    virtual bool vfn_094();
    virtual bool vfn_098();
    virtual bool vfn_09c();
    virtual bool vfn_0a0();
    virtual bool vfn_0a4();
    virtual bool vfn_0a8();
    virtual bool vfn_0ac();
    virtual bool vfn_0b0();
    virtual bool vfn_0b4();
    virtual bool vfn_0b8();
    virtual bool vfn_0bc();
    virtual bool vfn_0c0();
    virtual bool vfn_0c4();
    virtual bool vfn_0c8();
    virtual bool vfn_0cc();
    virtual bool vfn_0d0();
    virtual bool vfn_0d4();
    virtual bool vfn_0d8();
    virtual bool vfn_0dc();
    virtual bool vfn_0e0();
    virtual bool vfn_0e4();
    virtual bool vfn_0e8();
    virtual bool vfn_0ec();
    virtual bool vfn_0f0();
    virtual bool vfn_0f4();
    virtual bool vfn_0f8();
    virtual bool vfn_0fc();
    virtual bool vfn_100();
    virtual bool vfn_104();
    virtual bool vfn_108();
    virtual bool vfn_10c();
    virtual bool vfn_110();
    virtual bool vfn_114();
    virtual bool vfn_118();
    virtual bool vfn_11c();
    virtual bool vfn_120();
    virtual bool vfn_124();
    virtual bool vfn_128();
    virtual bool vfn_12c();
    virtual bool vfn_130();
    virtual bool vfn_134();
    virtual bool vfn_138();
    virtual bool vfn_13c();
    virtual bool vfn_140();
    virtual bool vfn_144();
    virtual bool vfn_148();
    virtual bool vfn_14c();
    virtual bool vfn_150();
    virtual bool vfn_154();
    virtual bool vfn_158();
    virtual bool vfn_15c();
    virtual bool vfn_160();
    virtual bool vfn_164();
    virtual bool vfn_168();
    virtual bool vfn_16c();
    virtual bool vfn_170();
    virtual bool vfn_174();
    virtual bool vfn_178();
    virtual bool vfn_17c();
    virtual bool vfn_180();
    virtual bool vfn_184();
    virtual bool vfn_188();
    virtual bool vfn_18c();
    virtual bool vfn_190();
    virtual bool vfn_194();
    virtual bool vfn_198();
    virtual bool vfn_19c();
    virtual bool vfn_1a0();
    virtual bool vfn_1a4();
    virtual bool vfn_1a8();
    virtual bool vfn_1ac();
    virtual bool vfn_1b0();
    virtual bool vfn_1b4();
    virtual bool vfn_1b8();
    virtual bool vfn_1bc();
    virtual bool vfn_1c0();
    virtual bool vfn_1c4();
    virtual bool vfn_1c8();
    virtual bool vfn_1cc();
    virtual int vfn_1d0();
};
struct PlayerContext86
{
};
struct Core86
{
    void FUN_004a0370();
    int FUN_004e9530();
    void FUN_004a03c0();
};
struct Input86
{
    bool FUN_00701450(int);
};
struct Topic86
{
    void FUN_004baf10();
};
struct Engine86
{
    Topic86* FUN_0044ddc0();
    void FUN_004baf10();
};
struct Global86
{
    int FUN_00559450();
    void FUN_0066b0d0(int);
};
struct Resource86
{
    void FUN_00c51f20();
};
struct Options86
{
    int* FUN_0043d4d0();
};
struct Frame86
{
    void FUN_0086d4c0(int);
};
struct Node86
{
    void FUN_00483710();
};
struct Sound86
{
};
struct GlobalText86
{
    int FUN_00403df0();
};
struct ControlItem86
{
    bool FUN_00a24660();
    bool FUN_00a24180();
};
struct Settings86
{
    int* FUN_0043d4d0();
};
struct Sink86
{
    void FUN_00701450(int);
};
struct ContextResult86
{
    bool FUN_004e9530();
};
struct MenuHandler86
{
    void FUN_0086d4c0(int);
};
struct Receiver86;
extern char __cdecl FUN_00702680(int, int);
extern bool __cdecl FUN_007079b0();
extern bool __cdecl FUN_007079b0(int);
extern void __cdecl FUN_0070edf0_unused();
extern void __cdecl FUN_00c51f20();
struct SwapMessage86
{
    void FUN_00b6da10();
};
extern SwapMessage86* FUN_004a0ea0(int);
extern void __cdecl FUN_00b6da10();
extern void __cdecl FUN_004da670();
extern char __cdecl FUN_00707000_unused();
extern bool DAT_011dea40;
extern int DAT_011def04, DAT_011dea44;
extern float DAT_011def00;
extern ControlItem86 DAT_011fdf30_dummy;
extern const char DAT_01082ca4[];
extern int DAT_011c6fb8_dummy;
extern int DAT_011dea40_dummy;
extern int DAT_011def04;
extern void __cdecl FUN_004ea970_set();
extern void __cdecl FUN_0045cd60();
extern void __cdecl FUN_00870680();
extern void __cdecl FUN_00702840();
extern void __cdecl FUN_00702810();
extern void __cdecl FUN_007027e0();
extern void __cdecl FUN_00878660();
extern void __cdecl FUN_004a03c0();
extern float __cdecl FUN_00450820();
extern void __cdecl FUN_00702840();
struct Control86
{
    int FUN_00a24660();
    int FUN_00a24180();
};
extern Control86* __cdecl FUN_007fdf30_control(int, int);
struct Receiver86;
extern int __cdecl FUN_004e3270_variant(int, int);
extern void __cdecl FUN_00450f90_variant(int);
extern int __cdecl FUN_004dc310_variant(int);
extern void __cdecl FUN_004ea970_variant();
extern void __cdecl FUN_00b6da10();
extern void __cdecl FUN_00c51f20();
extern void __cdecl FUN_004e9530_dummy();
extern int __cdecl FUN_0043c4b0_unused();
extern int __cdecl FUN_0044ddc0_unused();
extern void __cdecl FUN_007028b0_unused();
extern int __cdecl FUN_00559450_unused();
// Runs player, input, audio, and state update calls, then performs frame cleanup and resource updates.
// @fnv 0x0086ff70
void Main86::FUN_0086ff70()
{
    Core86* core = reinterpret_cast<Core86*>(((::fnv_0086ff70::Receiver86 *)(::FUN_0043c4b0())));
    core->FUN_004a0370();
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011d890a)))
    {
        (*reinterpret_cast<unsigned char *>(&::DAT_011d890a)) = 0;
        bool first = reinterpret_cast<::FUN_00456630_helper *>((reinterpret_cast<PlayerContext86*>(((::fnv_0086ff70::PlayerState86 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))))->FUN_00950bb0(1))))))->FUN_00456610();
        bool second = reinterpret_cast<::FUN_00456630_helper *>((reinterpret_cast<PlayerContext86*>(((::fnv_0086ff70::PlayerState86 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))))->FUN_00950bb0(0))))))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<PlayerContext86*>(((::fnv_0086ff70::PlayerState86 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))))->FUN_00950bb0(1))))))->QueueActorDisarm(1);
        reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<PlayerContext86*>(((::fnv_0086ff70::PlayerState86 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))))->FUN_00950bb0(0))))))->QueueActorDisarm(1);
        reinterpret_cast<::fnv_00871dc0::FUN_00871dc0_class *>(this)->FUN_00871dc0();
        reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<PlayerContext86*>(((::fnv_0086ff70::PlayerState86 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))))->FUN_00950bb0(1))))))->QueueActorDisarm(first);
        reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<PlayerContext86*>(((::fnv_0086ff70::PlayerState86 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))))->FUN_00950bb0(0))))))->QueueActorDisarm(second);
    }
    reinterpret_cast<::TESRegionDataMap *>((reinterpret_cast<Core86*>(((::fnv_0086ff70::Receiver86 *)(::FUN_0043c4b0())))))->GetRegionMapName();
    ::FUN_00a29680();
    ::FUN_0040fbe0();
    reinterpret_cast<::ThreadCoordinator_ba2f30 *>((((::fnv_0086ff70::Sound86 *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba2f30();
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011c6fb8)))
        ::ApplyGammaRamp();
    if (reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_0086ff70::Input86 * *>(&::DAT_011d8804))))->HasFader((::FADER_ENUM)(1)) || reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_0086ff70::Input86 * *>(&::DAT_011d8804))))->HasFader((::FADER_ENUM)(2)))
    {
        if (!DAT_011def04)
        {
            reinterpret_cast<::S457d70 *>(((*reinterpret_cast<::fnv_0086ff70::Engine86 * *>(&::g_TES))))->FUN_00457d70(0, (::Form457 *)(0), 0);
            ::FUN_0040fbe0();
            reinterpret_cast<::FUN_0096cfa0_cls *>((reinterpret_cast<Extra86*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096cfa0();
        }
        DAT_011def00 += ::fnv::timer::UnmodifiedSeconds();
        ++DAT_011def04;
        if (DAT_011def00 >= ::g_01012070 && DAT_011def04 >= 10)
        {
            reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_0086ff70::Input86 * *>(&::DAT_011d8804))))->StopFader((::FADER_ENUM)(1), 0);
            reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_0086ff70::Input86 * *>(&::DAT_011d8804))))->StopFader((::FADER_ENUM)(2), 0);
            reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::fnv_0086ff70::Node86 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(0);
            if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::fnv_0086ff70::Node86 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
            {
                reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::fnv_0086ff70::Node86 * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(0);
                reinterpret_cast<::TESForm *>(((*reinterpret_cast<::fnv_0086ff70::Node86 * *>(&::g_TESSaveLoadGame))))->ClearData();
            }
            reinterpret_cast<::fnv_00877430::FUN_00877430_shell *>(this)->FUN_00877430();
        }
    }
    else
    {
        DAT_011def00 = 0.0f;
        DAT_011def04 = 0;
    }
    int eventState = 0;
    if (!(*reinterpret_cast<unsigned char *>(&::DAT_011dea29)) && !::FUN_0070edf0() && (*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))->vfn_1d0() && !reinterpret_cast<::FM7 *>(((*reinterpret_cast<::fnv_0086ff70::Input86 * *>(&::DAT_011d8804))))->IsFaderActive(1))
    {
        if (!((reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_0086ff70::Engine86 * *>(&::g_TES))))->GetPrevPath())))
        {
            if (reinterpret_cast<::FUN_00548210_Class *>((((::fnv_0086ff70::Engine86 *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_0086ff70::Engine86 * *>(&::g_TES))))->GetHitSound()))))->FUN_00548210()[0] && ((::fnv_0086ff70::Topic86 *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_0086ff70::Engine86 * *>(&::g_TES))))->GetName())))
            {
                reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_0086ff70::Engine86 * *>(&::g_TES))))->GetName();
                if ((unsigned char)::FUN_008705c0())
                    reinterpret_cast<::Grid *>((((::fnv_0086ff70::Topic86 *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_0086ff70::Engine86 * *>(&::g_TES))))->GetName()))))->FUN_004baf10();
            }
        }
        reinterpret_cast<::fnv_008706b0::FUN_008706b0_shell *>(this)->FUN_008706b0((::fnv_008706b0::BSRenderedTexture *)(0), 0, 0);
    }
    else if ((::FUN_007079b0() || !::FUN_00702360()) && !(unsigned char)FUN_00702680(0x3f5, 0))
    {
        if ((*reinterpret_cast<::fnv_0086ff70::PlayerState86 * *>(&::_g_thePlayer))->vfn_1d0())
            reinterpret_cast<::fnv_008706b0::FUN_008706b0_shell *>(this)->FUN_008706b0((::fnv_008706b0::BSRenderedTexture *)(0), ::FUN_007079b0(), 0);
    }
    else
    {
        for (int i = 1; i < 23; ++i)
        {
            reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_0086ff70::Sound86 *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0({}, {});
            ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_0086ff70::Sound86 *)(::TaskThreadManager::GetSingleton()))), {}, {}, {});
        }
        reinterpret_cast<::fnv_00871a50::HudRenderPass *>(this)->FUN_00871a50();
        if ((unsigned char)FUN_00702680(0x41e, 0) || (unsigned char)FUN_00702680(0x3f6, 0) ||
            (unsigned char)FUN_00702680(0x424, 0) || (unsigned char)FUN_00702680(0x432, 0) ||
            (unsigned char)FUN_00702680(0x438, 0) || (unsigned char)FUN_00702680(0x439, 0) ||
            (unsigned char)FUN_00702680(0x43a, 0) || (unsigned char)FUN_00702680(0x43b, 0))
            reinterpret_cast<::fnv_00872940::MainTarget *>(this)->FUN_00872940((::fnv_00872940::BSRenderedTexture *)(0));
        else if ((*reinterpret_cast<::fnv_0086ff70::Global86 *>(&::g_011ded3c)).FUN_00559450())
            reinterpret_cast<::fnv_00874b90::FUN_00874b90_shell *>(this)->FUN_00874b90((::fnv_00874b90::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270()), {}, {}, {});
    }
    if (((bool)(::fnv_005d4a40::FUN_005d4a40())) == 1)
        ::FUN_00b55a10();
    ::FUN_00709b40();
    ::fnv_007028b0::RenderOrFallback(eventState, (*reinterpret_cast<::fnv_0086ff70::Global86 *>(&::g_011dec64)).FUN_00559450());
    reinterpret_cast<::FUN_00ba2fa0_C *>((((::fnv_0086ff70::Sound86 *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba2fa0();
    if ((*reinterpret_cast<::fnv_0086ff70::Global86 *>(&::g_011dec64)).FUN_00559450())
    {
        reinterpret_cast<::Manager *>((FUN_004a0ea0((*reinterpret_cast<::fnv_0086ff70::Global86 *>(&::g_011dec64)).FUN_00559450())))->FUN_00b6da10({});
        (*reinterpret_cast<::fnv_0086ff70::Global86 *>(&::g_011dec64)).FUN_0066b0d0(0);
    }
    if (reinterpret_cast<::HotkeyWheelDisplay *>((((::fnv_0086ff70::Control86 *)(::FUN_007fdf30()))))->SetHotkeyItem({}, {}))
    {
        if (reinterpret_cast<::FUN_00a24180_shell *>((((::fnv_0086ff70::Control86 *)(::FUN_007fdf30()))))->FUN_00a24180({}, {}) || DAT_011dea40)
        {
            DAT_011dea40 = !DAT_011dea40;
            if (DAT_011dea40)
            {
                DAT_011dea44 = 0;
                reinterpret_cast<::S0042fa20 *>(&((*reinterpret_cast<::fnv_0086ff70::Options86 *>(&::g_011deecc))))->FUN_0045ce80(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086ff70::Options86 *>(&::g_011deecc)))))) + 1);
                char outputDirectory[0x104];
                ::FUN_00406d00(outputDirectory, 0x104, DAT_01082ca4, ((intptr_t)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0086ff70::GlobalText86 *>(&::g_011deb04))))->GetMenuTitle())),
                             *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086ff70::Options86 *>(&::g_011deecc)))))));
                CreateDirectoryA(outputDirectory, 0);
                ::fnv::timer::SetFrequency(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086ff70::Options86 *>(&::g_011dee00)))))));
            }
            else
                ::fnv::timer::SetFrequency(0);
        }
        else
            ::SaveScreenshot((const char *)(0));
    }
    ::FUN_00c458f0();
    if (((int)(reinterpret_cast<::fnv_004e9530::NiRenderer *>((core))->FUN_004e9530())))
        ::TaskThreadManager::EndRenderingTaskThread();
    if (eventState)
    {
        reinterpret_cast<::Manager *>((FUN_004a0ea0(eventState)))->FUN_00b6da10({});
        eventState = 0;
    }
    reinterpret_cast<::fn_00c51f20::Owner *>((reinterpret_cast<Resource86*>((*reinterpret_cast<::fnv_0086ff70::Global86 *>(&::g_011deb7c)).FUN_00559450())))->FUN_00c51f20();
    reinterpret_cast<::fnv_004a03c0::DD *>((core))->FUN_004a03c0();
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0086ff70::Options86 *>(&::g_011c3ea4)))))) > 1)
        ::AIThreadManager::SetThreadingEnabled(0);
}
}  // namespace fnv_0086ff70

namespace fnv_00870bd0 {
struct FUN_00414430;
struct NiPoint2;
struct BSRenderedTexture;
struct ImageView;
struct ProjectionView;
struct RenderNode
{
};
struct ModelView
{
};
struct PlayerView
{
};
struct MenuView
{
};
struct WorldView
{
};
struct PointView
{
    const NiPoint3& FUN_0045bb80();
};
struct CameraView
{
    virtual void v0();
    virtual PointView* v1();
};
struct CameraHolder
{
    CameraView* FUN_0045cd60();
};
struct ProjectionResult
{
};
struct ProjectionView
{
    ProjectionResult* FUN_006629f0(const NiPoint3&, float&, float&, float&, float);
};
struct RenderView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43(void*);
};
struct EffectView
{
};
struct ImageView
{
};
struct ShaderView
{
};
struct ShaderHolder
{
    ShaderView* FUN_00559450();
};
struct SettingView
{
};
struct BoolSettingView
{
    bool* FUN_00408d60();
};
struct ToggleView
{
};
struct NiPoint2
{
    float x, y;
    NiPoint2(float, float);
};
struct FUN_00414430
{
    float a, b, c, d;
    FUN_00414430(float, float, float, float);
};
bool FUN_00709cb0();

struct RenderCoordinator
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84;
    ShaderHolder shaders;
    void FUN_00870bd0(intptr_t, bool);
};
// Renders the scene into a BSRenderedTexture, applying effects, post-processing, and camera projection based on the given argument and skip flag.
// @fnv 0x00870bd0
void RenderCoordinator::FUN_00870bd0(intptr_t arg, bool skip)
{
    RenderView* l = ((::fnv_00870bd0::RenderView *)(::FUN_0043c4b0()));
    ImageView* h = (ImageView*)((::fnv_00870bd0::ImageView *)(::ImageSpaceManager::FUN_004e3270()));
    ModelView* s = 0;
    bool p = reinterpret_cast<::FUN_00456630_helper *>((((::fnv_00870bd0::RenderNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00870bd0::PlayerView * *>(&::_g_thePlayer))))->FUN_00950bb0(true)))))->FUN_00456610();
    bool q = ::FUN_004dc310();
    reinterpret_cast<::NiParallelUpdateTaskManager *>(this)->SetupTaskWorkers();
    s = ((::fnv_00870bd0::ModelView *)(reinterpret_cast<::fnv_00872b00::MainX *>(this)->UpdateCamera()));
    reinterpret_cast<::fnv_008727d0::FUN_008727d0_shell *>(this)->FUN_008727d0();
    bool i = ::fnv_008749b0::FUN_008749b0((void *)this);
    reinterpret_cast<::ShadowHost *>(this)->FUN_00871290();
    BSRenderedTexture* j = ((::fnv_00870bd0::BSRenderedTexture *)(reinterpret_cast<::Host *>(this)->FUN_00872f50((::P1 *)(l), (::BSRenderedTexture *)(arg), 0, q)));
    reinterpret_cast<::fnv_00874ac0::FUN_00874ac0_shell *>(this)->FUN_00874ac0(i);
    reinterpret_cast<::FUN_00874b50_shell *>(this)->FUN_00874b50((::BSRenderedTexture *)(j), q, 5);
    bool cf = !p && !skip && !((reinterpret_cast<::TESRegionDataMap *>((((::fnv_00870bd0::MenuView *)(::fnv_00705910::FUN_00705910()))))->GetRegionMapName())) && !::FUN_00705100();
    bool a = false;
    if (cf && s)
    {
        a = reinterpret_cast<::FUN_00456630_helper *>((((::fnv_00870bd0::RenderNode *)(::fnv_0043b230::FUN_0043b230((const char *)(s))))))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((((::fnv_00870bd0::RenderNode *)(::fnv_0043b230::FUN_0043b230((const char *)(s))))))->QueueActorDisarm(true);
    }
    bool eb = true;
    if (::FUN_004de080())
        eb = false;
    bool e = FUN_00709cb0();
    if (e)
    {
        unsigned j = reinterpret_cast<::GraphicsRenderer *>((l))->GetRenderTargetWidth();
        unsigned c = reinterpret_cast<::GraphicsRenderer *>((l))->GetRenderTargetHeight();
        float l = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00870bd0::SettingView *>(&::g_011dea8c)))))) * ::Interface::GetInterfaceFloat() * 0.5;
        float e = j * l;
        float k = j - e;
        if (eb)
            ::FUN_00b4f540((unsigned)e, 0, (unsigned)k, c);
    }
    reinterpret_cast<::fnv_00873200::MainView *>(this)->FUN_00873200((::fnv_00873200::ViewNode *)(s), cf, 0, i);
    if (cf && s)
        reinterpret_cast<::TaskQueueInterface *>((((::fnv_00870bd0::RenderNode *)(::fnv_0043b230::FUN_0043b230((const char *)(s))))))->QueueActorDisarm(a);
    EffectView* k = ((::fnv_00870bd0::EffectView *)(reinterpret_cast<::FUN_004ebbc0_shell *>((h))->FUN_004ebbc0(4)));
    bool c = ::FUN_00871220((char *)(k));
    bool j7 = (reinterpret_cast<::ImageSpaceManager *>((h))->IsEffectActive((::ImageSpaceManager__ImageSpaceEffectEnum)(9)) && !((reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_00870bd0::WorldView * *>(&::g_TES))))->GetPrevPath())) && *(*reinterpret_cast<::fnv_00870bd0::BoolSettingView *>(&::g_011deadc)).FUN_00408d60()) ? true : false;
    const bool ba = false;
    const bool f = false;
    bool b = false;
    if ((c || ba || f) && cf)
    {
        b = true;
        reinterpret_cast<::fnv_008746d0::FUN_008746d0_shell *>(this)->FUN_008746d0((::fnv_008746d0::BSRenderedTexture *)(j));
        reinterpret_cast<::FUN_00874b50_shell *>(this)->FUN_00874b50((::BSRenderedTexture *)(j), q, 0);
    }
    if (::FUN_005b9b00() && ((unsigned int)(reinterpret_cast<::FUN_00b63a90_cls *>((shaders.FUN_00559450()))->SumItemSubValues())) > 0)
        reinterpret_cast<::FUN_00874920_t *>(this)->FUN_00874920((::BSShaderAccumulator *)(::fnv_00870bd0::ShaderView *)(shaders.FUN_00559450()), (::BSRenderedTexture *)(j));
    if (cf)
    {
        reinterpret_cast<::fnv_00874c10::MainShell *>(this)->FUN_00874c10();
        reinterpret_cast<::FUN_00874b50_shell *>(this)->FUN_00874b50((::BSRenderedTexture *)(j), q, 0);
        if (!b)
            ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_00870bd0::ToggleView *)(::TaskThreadManager::GetSingleton()))), {}, {}, {});
        reinterpret_cast<::SetRenderCamera::Main *>(this)->FUN_00875110((::SetRenderCamera::Scene *)(l), (::SetRenderCamera::Scene *)(0), (::SetRenderCamera::Scene *)(s), (::SetRenderCamera::Scene *)(j));
    }
    else
    {
        reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((((::fnv_00870bd0::ToggleView *)(::TaskThreadManager::GetSingleton()))))->FUN_00ba30f0({}, {});
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(((::fnv_00870bd0::ToggleView *)(::TaskThreadManager::GetSingleton()))), {}, {}, {});
    }
    if (c || ba)
        reinterpret_cast<::fnv_00875e40::FUN_00875e40_shell *>(this)->FUN_00875e40((::fnv_00875e40::BSShaderAccumulator *)(::fnv_00870bd0::ShaderView *)(shaders.FUN_00559450()), (::fnv_00875e40::BSRenderedTexture *)(j));
    if (f)
        reinterpret_cast<::fnv_00875fa0::Outer00875fa0 *>(this)->FUN_00875fa0((::fnv_00875fa0::Param00875fa0 *)(::fnv_00870bd0::ShaderView *)(shaders.FUN_00559450()), j);
    if (j7 && !((reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::fnv_00870bd0::WorldView * *>(&::g_TES))))->GetPrevPath())) && (*reinterpret_cast<::fnv_00870bd0::CameraHolder * *>(&::DAT_011dea20)) && ((::fnv_00870bd0::CameraView *)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::fnv_00870bd0::CameraHolder * *>(&::DAT_011dea20))))->FUN_0045cd60())))
    {
        NiPoint3 v = ((::fnv_00870bd0::CameraView *)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::fnv_00870bd0::CameraHolder * *>(&::DAT_011dea20))))->FUN_0045cd60()))->v1()->FUN_0045bb80();
        float w, u, n;
        w = u = n = 0.0f;
        ProjectionView* a = (ProjectionView*)((::fnv_00870bd0::ProjectionView *)(::FUN_0045c670()));
        bool f = reinterpret_cast<::FUN_00a6fdb0_t *>((a->FUN_006629f0(v, w, u, n, 0.00001f)))->ProjectPointToScreen(*(const ::NiPoint3 *)nullptr, *(float *)nullptr, *(float *)nullptr, *(float *)nullptr, {});
        ::FUN_00b8b1e0((const int *)(((ImageView*)((::fnv_00870bd0::ImageView *)(::ImageSpaceManager::FUN_004e3270())))));
    }
    if (::FUN_008709f0())
    {
        reinterpret_cast<::fnv_00875fd0::FrameRenderer *>(this)->FUN_00875fd0((void *)(q), j, l, (void *)(arg));
        if ((::FUN_00871260() || ::fnv_005bac20::FUN_005bac20()) && !::fnv_00705a00::FUN_00705a00())
            reinterpret_cast<::FUN_00876a20_shell *>(this)->FUN_00876a20((::FUN_00876a20_arg *)(l));
    }
    else if (arg)
        reinterpret_cast<::fnv_00876830::BSRenderedTexture *>(this)->FUN_00876830(q, arg);
    if (e)
    {
        if (eb)
            ::FUN_00b540d0();
        if (::FUN_004de080())
        {
            ((::fnv_00870bd0::RenderView *)(::FUN_0043c4b0()))->v43(&(*reinterpret_cast<int *>(&::DAT_011a9bd0)));
            FUN_00414430 param(0, 0, 0, 0);
            param.a = 0;
            param.b = 0.33f;
            param.c = 1;
            param.d = 0;
            reinterpret_cast<::S148c0 *>((((::fnv_00870bd0::RenderView *)(::FUN_0043c4b0()))))->FUN_007148c0((intptr_t)(&param), true);
            param.a = 0.66f;
            param.b = 1;
            param.c = 1;
            param.d = 0;
            reinterpret_cast<::S148c0 *>((((::fnv_00870bd0::RenderView *)(::FUN_0043c4b0()))))->FUN_007148c0((intptr_t)(&param), true);
        }
    }
    reinterpret_cast<::fnv_00876850::FUN_00876850_shell *>(this)->FUN_00876850((::fnv_00876850::BSRenderedTexture *)(j), (::fnv_00876850::ImageSpaceManager *)(h), (::fnv_00876850::GraphicsRenderer *)(l), (::fnv_00876850::Sun *)(s));
}
}  // namespace fnv_00870bd0

namespace fnv_00872570 {
struct HWND__;
class BGSMoviePlayer_ML
{
  public:
    void FUN_00ec1800();
};
struct RenderManager_ML
{
};
struct CellState_ML
{
    int unk00;
    int active;
};
struct CellUpdate_ML
{
};
struct GridCell_ML
{
    CellUpdate_ML* cell;
};
struct CellGrid_ML
{
};
struct WorldAudio_ML
{
};
class TES_ML
{
  public:
    CellGrid_ML* FUN_0044ddc0();
};
class OSGlobals_ML
{
  public:
    int unk00;
    int unk04;
    ::HWND window;
};
using WindowRect_ML = ::RECT;

namespace MainLoopGlobals {
extern "C" bool __cdecl FUN_0086bdf0();
}

// When active, waits for a condition and updates render, cell, and window state; otherwise, it performs audio-related calls.
// @fnv 0x00872570
bool __cdecl FUN_00872570(bool active)
{
    if (active)
    {
        while (!(unsigned char)MainLoopGlobals::FUN_0086bdf0())
            ::FUN_0040fca0(5);
        if (reinterpret_cast<::FUN_00ec17c0_Class *>(((*reinterpret_cast<::fnv_00872570::BGSMoviePlayer_ML * *>(&::DAT_0126fac4))))->FUN_00ec17c0())
        {
            reinterpret_cast<::FUN_00ec29b0_class *>(((*reinterpret_cast<::fnv_00872570::BGSMoviePlayer_ML * *>(&::DAT_0126fac4))))->FUN_00ec29b0();
            reinterpret_cast<::FUN_00ec1800_cls *>(((*reinterpret_cast<::fnv_00872570::BGSMoviePlayer_ML * *>(&::DAT_0126fac4))))->FUN_00ec1800();
        }
        if (((bool)(reinterpret_cast<::FUN_00872780_Class *>(((*reinterpret_cast<::fnv_00872570::BGSMoviePlayer_ML * *>(&::DAT_0126fac4))))->FUN_00872780())))
            reinterpret_cast<::fnv_00ec25e0::FUN_00ec25e0_cls *>(((*reinterpret_cast<::fnv_00872570::BGSMoviePlayer_ML * *>(&::DAT_0126fac4))))->FUN_00ec25e0();
        RenderManager_ML* renderer = ((::fnv_00872570::RenderManager_ML *)(::FUN_00b4f5c0()));
        if (renderer)
            reinterpret_cast<::FUN_00b631d0_cls *>((renderer))->FUN_00b631d0();
        {
            int count = reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_00872570::CellGrid_ML *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00872570::TES_ML * *>(&::g_TES))))->GetName()))))->FUN_0084e3a0();
            for (int x = 0; x < count; ++x)
            {
                for (int y = 0; y < count; ++y)
                {
                    CellUpdate_ML* cell = ((::fnv_00872570::GridCell_ML *)(reinterpret_cast<::TES *>(((*reinterpret_cast<::fnv_00872570::TES_ML * *>(&::g_TES))))->FUN_00457050(x, y)))->cell;
                    if (cell)
                    {
                        void* object;
                        CellState_ML* state;
                        reinterpret_cast<::FUN_005477f0_Class *>((cell))->FUN_005477f0((intptr_t)(&object), (intptr_t)(&state));
                        if (object && state && state->active)
                            state->active = 0;
                    }
                }
            }
            reinterpret_cast<::fnv_00877430::FUN_00877430_shell *>(((*reinterpret_cast<::fnv_00872570::OSGlobals_ML * *>(&::g_osGlobals))))->FUN_00877430();
            if (::FUN_00446e10())
            {
                long style;
                {
                    WindowRect_ML rectWindow;
                    rectWindow.left = 0;
                    rectWindow.top = 0;
                    rectWindow.right = ((long)(::FUN_004dc1f0()));
                    rectWindow.bottom = ((long)(::FUN_004dc200()));
                    style = 0;
                    style = GetWindowLongA((*reinterpret_cast<::fnv_00872570::OSGlobals_ML * *>(&::g_osGlobals))->window, -16);
                    AdjustWindowRectEx(&rectWindow, style, 0, 0);
                    SetWindowPos((*reinterpret_cast<::fnv_00872570::OSGlobals_ML * *>(&::g_osGlobals))->window, 0, rectWindow.left, rectWindow.bottom,
                                 rectWindow.right - rectWindow.left, rectWindow.top - rectWindow.bottom, 0);
                }
            }
        }
    }
    else
    {
        if ((*reinterpret_cast<unsigned char *>(&::DAT_011f941e)))
            ::FUN_00bad4a0();
        if (((::fnv_00872570::WorldAudio_ML *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_00872570::TES_ML * *>(&::g_TES)))))) && ::FUN_005d2a40())
        {
            reinterpret_cast<::fnv_004e6620::WaterCleanup *>((((::fnv_00872570::WorldAudio_ML *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_00872570::TES_ML * *>(&::g_TES))))))))->ReleaseWaterResources(1, 0);
            reinterpret_cast<::fnv_004e65d0::S_004e65d0 *>((((::fnv_00872570::WorldAudio_ML *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_00872570::TES_ML * *>(&::g_TES))))))))->FUN_004e65d0();
        }
    }
    return true;
}
}  // namespace fnv_00872570

#include <string.h>
namespace fnv_00a24830 {
struct DIGuid
{
    unsigned long Data1;
    unsigned short Data2, Data3;
    unsigned char Data4[8];
};
struct DIDEVICEOBJECTINSTANCEA;
struct DIDEVICEINSTANCEA
{
    unsigned long dwSize;
    DIGuid guidInstance, guidProduct;
    unsigned long dwDevType;
    char tszInstanceName[260], tszProductName[260];
    DIGuid guidFFDriver;
    unsigned short wUsagePage, wUsage;
};
struct DIDEVCAPS
{
    unsigned long dwSize, dwFlags, dwDevType, dwAxes, dwButtons, dwPOVs, dwFFSamplePeriod, dwFFMinTimeResolution,
        dwFirmwareRevision, dwHardwareRevision, dwFFDriverVersion;
};
struct IDirectInputDevice8A
{
    virtual long Q();
    virtual long A();
    virtual long R();
    virtual long GetCapabilities(DIDEVCAPS*);
    virtual long EnumObjects(int(*)(const DIDEVICEOBJECTINSTANCEA*, void*), void*, unsigned long);
    virtual long GetProperty();
    virtual long SetProperty();
    virtual long Acquire();
    virtual long Unacquire();
    virtual long GetDeviceState();
    virtual long GetDeviceData();
    virtual long SetDataFormat(const void*);
    virtual long SetEventNotification();
    virtual long SetCooperativeLevel(void*, unsigned long);
};
struct IDirectInput8A
{
    virtual long Q();
    virtual long A();
    virtual long R();
    virtual long CreateDevice(const DIGuid&, IDirectInputDevice8A**, void*);
};
extern const unsigned char DAT_01100ebc[];

struct JoystickCounts
{
    unsigned int axes, buttons;
};
struct InputOwner
{
    unsigned int unk00, unk04;
    IDirectInput8A* input;
    IDirectInputDevice8A* devices[8];
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    DIDEVICEINSTANCEA instances[8];
    DIDEVCAPS caps[8];
    JoystickCounts counters[8];
    unsigned int count;
};
// Accepts instances whose low device type byte is 20 or 21, creates a device, queries capabilities and object counts, and stores it.
// @fnv 0x00a24830
int FUN_00a24830(const DIDEVICEINSTANCEA* instance, void* context)
{
    InputOwner* manager = (InputOwner*)context;
    if ((unsigned char)(instance->dwDevType & 255) != 20 && (unsigned char)(instance->dwDevType & 255) != 21)
        return 1;
    DIDEVICEINSTANCEA* deviceOut = &manager->instances[manager->count];
    memcpy(deviceOut, instance, 0x244);
    IDirectInputDevice8A* saved;
    manager->input->CreateDevice(instance->guidInstance, &saved, 0);
    IDirectInputDevice8A* device = saved;
    device->SetCooperativeLevel(GetActiveWindow(), 6);
    device->SetDataFormat(DAT_01100ebc);
    DIDEVCAPS* caps = &manager->caps[manager->count];
    std::memset(caps, 0, 0x2c);
    manager->caps[manager->count].dwSize = 0x2c;
    device->GetCapabilities(&manager->caps[manager->count]);
    manager->counters[manager->count].axes = 0;
    manager->counters[manager->count].buttons = 0;
    device->EnumObjects(((int (&)(const fnv_00a24830::DIDEVICEOBJECTINSTANCEA *, void *))::MatchObjectGuids), &manager->counters[manager->count], 0);
    manager->devices[manager->count] = device;
    reinterpret_cast<::FUN_00a236f0_cls *>((manager))->FUN_00a236f0(manager->count, -100, 100);
    reinterpret_cast<::InputManager *>((manager))->FUN_00a23750(manager->count, 0.1f);
    manager->count++;
    if (manager->count == 8)
        return 0;
    return 1;
}
}  // namespace fnv_00a24830

namespace fnv_0086f940 {
class BGSAcousticSpace;
// Required virtual interface: the pack leaves the update slot untyped.
class PlayerUpdate : public TESObjectREFR
{
  public:
    virtual void StartHighProcess(void);
    virtual void Unk_91(void);
    virtual void Unk_92(void);
    virtual void Unk_93(void);
    virtual void Unk_94(void);
    virtual void Unk_95(void);
    virtual void Unk_96(void);
    virtual void Unk_97(void);
    virtual void Unk_98(void);
    virtual void Unk_99(void);
    virtual void Unk_9A(float arg0);
    virtual void Unk_9B(void);
    virtual void Unk_9C(void);
    virtual void Unk_9D(void);
    virtual void Unk_9E(void);
    virtual void Unk_9F(void* arg0);
    virtual void Unk_A0(void);
    virtual void Unk_A1(void);
    virtual void Unk_A2(void);
    virtual void Unk_A3(void* arg0, bool arg1);
    virtual void Unk_A4(void);
    virtual void Unk_A5(void);
    virtual void Unk_A6(void);
    virtual void Unk_A7(void);
    virtual void Unk_A8(void);
    virtual void Unk_A9(void);
    virtual void Unk_AA(NiPoint3& arg0);
    virtual void Unk_AB(NiPoint3& result);
    virtual void Unk_AC(void);
    virtual void Unk_AD(void);
    virtual void Unk_AE(void);
    virtual float GetCurrentTargetDistance(bool ignoreImmobile);
    virtual void Unk_B0(void);
    virtual void SetFurnitureHeading(float heading);
    virtual TESObjectREFR* GetCurrentTarget();
    virtual void Unk_B3(void);
    virtual void Unk_B4(void);
    virtual void Unk_B5(void);
    virtual void Unk_B6(void);
    virtual void SetActorEssentialState(int value);
    virtual void Unk_B8(void);
    virtual void Unk_B9(void);
    virtual bool Unk_BA();
    virtual void Unk_BB(void);
    virtual void Unk_BC(void);
    virtual void Unk_BD(void);
    virtual void Unk_BE(float delta);
};
struct PlayerCalls
{
};
struct CellCalls
{
};
struct DataHandlerCalls
{
};
struct Receiver86;
class WorldUpdateCalls
{
  public:
    bool FUN_00451530();
};
struct TimeGlobal
{
};
struct UpdateScale
{
};
struct RenderManager
{
};
struct PlayerUpdateState
{
    unsigned int updateFlags;
    unsigned short updateState;
    bool specialUpdate;
    unsigned char updateMode;
    void FUN_0086f940();
};

// Updates player state and may transfer the player to a destination cell when the current cell is exterior and a position check fails.
// @fnv 0x0086f940
void PlayerUpdateState::FUN_0086f940()
{
    bool bChanged;
    if (!reinterpret_cast<::FUN_0093bea0_cls *>((reinterpret_cast<PlayerCalls*>(::_g_thePlayer)))->FUN_0093bea0())
    {
        if (::DAT_011dea2b && !::FUN_00709bc0())
        {
            reinterpret_cast<::FUN_009481d0_Owner *>((reinterpret_cast<PlayerCalls*>(::_g_thePlayer)))->FUN_009481d0();
        }
        else if (specialUpdate)
        {
            if (::_g_thePlayer->GetNiNode())
            {
                reinterpret_cast<::InputPlayer *>((reinterpret_cast<PlayerCalls*>(::_g_thePlayer)))->FUN_009466d0(::fnv::timer::Seconds(), updateMode);
            }
        }
        else
        {
            if (::_g_thePlayer->GetNiNode())
            {
                ++::DAT_011e07a8;
                reinterpret_cast<PlayerUpdate*>(::_g_thePlayer)
                    ->Unk_BE(::fnv::timer::Seconds() * reinterpret_cast<::VATS *>(&((*reinterpret_cast<::fnv_0086f940::UpdateScale *>(&::g_011f2250))))->GetModeTimeMultiplier());
                --::DAT_011e07a8;
            }
            bChanged = false;
            TESObjectCELL* cell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((::_g_thePlayer))->GetTarget()));
            NiPoint3 position = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((reinterpret_cast<PlayerCalls*>(::_g_thePlayer)))->GetAddTopicList()));
            if (cell && !reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellCalls*>(cell)))->IsCellInterior() &&
                !reinterpret_cast<::fnv_00550200::FUN_00550200 *>((reinterpret_cast<CellCalls*>(cell)))->IsPointInCell((const ::fnv_00550200::NiPoint3 &)(position)))
            {
                TESObjectCELL* destination =
                    reinterpret_cast<::FUN_00461bc0_cls *>((reinterpret_cast<DataHandlerCalls*>((*reinterpret_cast<::fnv_0086f940::Receiver86 * *>(&::g_dataHandler)))))->FUN_00461bc0(position.x, position.y, reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellCalls*>(cell)))->GetParentWorldSpace(),
                                       true);
                if (destination)
                {
                    if (!::FUN_00450fb0((void *)(reinterpret_cast<CellCalls*>(destination))) &&
                        !::FUN_00450ff0((void *)(reinterpret_cast<CellCalls*>(destination))))
                    {
                        reinterpret_cast<::TES *>((reinterpret_cast<WorldUpdateCalls*>((*reinterpret_cast<unsigned int *>(&::g_TES)))))->FindCellAtPosition((const ::NiPoint3 *)&(position), true);
                        if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>((reinterpret_cast<WorldUpdateCalls*>((*reinterpret_cast<unsigned int *>(&::g_TES)))))->FUN_00451530())
                        {
                            reinterpret_cast<::S457d70 *>((reinterpret_cast<WorldUpdateCalls*>((*reinterpret_cast<unsigned int *>(&::g_TES)))))->FUN_00457d70(0, (::Form457 *)(0), 0);
                        }
                    }
                    ::FUN_0086fba0(1);
                    reinterpret_cast<::FUN_0086fbc0_Class *>((reinterpret_cast<PlayerCalls*>(::_g_thePlayer)))->FUN_0086fbc0(1);
                    reinterpret_cast<::CellView *>((reinterpret_cast<CellCalls*>(destination)))->FUN_00548230((::RefView *)(::_g_thePlayer), false);
                    ::FUN_0086fbb0((::BGSAcousticSpace *)(::fnv_0086f940::BGSAcousticSpace *)(((::fnv_0086f940::BGSAcousticSpace *)(reinterpret_cast<::FUN_00547590_shell *>((reinterpret_cast<CellCalls*>(destination)))->FUN_00547590()))));
                    reinterpret_cast<::FUN_0086fbc0_Class *>((reinterpret_cast<PlayerCalls*>(::_g_thePlayer)))->FUN_0086fbc0(0);
                    ::FUN_0086fba0(0);
                    RenderManager* manager = ((::fnv_0086f940::RenderManager *)(::FUN_00b4f5c0()));
                    if (manager)
                    {
                        ::FUN_00b655b0((::Self_00b655b0 *)(manager));
                    }
                }
                bChanged = true;
            }
        }
    }
}
}  // namespace fnv_0086f940

namespace fnv_0086d590 {
struct NiAVObject;
using AutoMemHelper = ::AutoMemContext;

struct NiFixedString
{
    int value;
    NiFixedString(const char*);
    ~NiFixedString();
    const char* FUN_00438170(const char*);
    void FUN_004381b0();
};
struct ResourceObject;
struct Resource
{
    ResourceObject* object;
    ResourceObject* FUN_00559450();
    void FUN_0066b0d0(void* item);
};
struct ResourceObject
{
    ResourceObject* FUN_006629f0();
    void FUN_005468d0(int);
    void SetDepthParams(float);
    void FUN_0049ed90(int);
    void FUN_004bc1f0(float, float, float);
    void FUN_004bc450(void*);
    void FUN_005b8fc0(int);
    void FUN_0060aeb0(int);
    void FUN_004f3200(int);
    int FUN_004bc320(int);
    void FUN_0086e3f0(int, int, int);
    void FUN_0086e420(int, float, float, float, float);
    void FUN_0086e4b0();
    void FUN_0086e460(int, int, float, float, float, float);
};
struct ModuleRoot
{
    virtual void virtual_00();
    virtual void virtual_04();
    virtual void virtual_08();
    virtual void virtual_0c();
    virtual void virtual_10();
    virtual void virtual_14();
    virtual void virtual_18();
    virtual void virtual_1c();
    virtual void virtual_20();
    virtual void virtual_24();
    virtual void virtual_28();
    virtual void virtual_2c();
    virtual void virtual_30();
    virtual void virtual_34();
    virtual void virtual_38();
    virtual void virtual_3c();
    virtual void virtual_40();
    virtual void virtual_44();
    virtual void virtual_48();
    virtual void virtual_4c();
    virtual void virtual_50();
    virtual void virtual_54();
    virtual void virtual_58();
    virtual void virtual_5c();
    virtual void virtual_60();
    virtual void virtual_64();
    virtual void virtual_68();
    virtual void virtual_6c();
    virtual void virtual_70();
    virtual void virtual_74();
    virtual void virtual_78();
    virtual void virtual_7c();
    virtual void virtual_80();
    virtual void virtual_84();
    virtual void virtual_88();
    virtual void virtual_8c();
    virtual void virtual_90();
    virtual void virtual_94();
    virtual void virtual_98();
    virtual void virtual_9c();
    virtual void virtual_a0();
    virtual void virtual_a4();
    virtual void virtual_a8();
    virtual void virtual_ac();
    virtual void virtual_b0();
    virtual void virtual_b4();
    virtual void virtual_b8();
    virtual void virtual_bc();
    virtual void virtual_c0();
    virtual void virtual_c4();
    virtual void virtual_c8();
    virtual void virtual_cc();
    virtual void virtual_d0();
    virtual void virtual_d4();
    virtual void virtual_d8();
    virtual void virtual_dc(void*, int);
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8(int, void*);
};

struct SceneObject : ModuleRoot
{
    SceneObject* FUN_00878610(const char*, int, int);
    void FUN_0086e420(float, float, float, float, int);
};
struct DataObject : ModuleRoot
{
    DataObject* FUN_00b5e0f0();
};
struct InputObject : ModuleRoot
{
    InputObject* FUN_00bb8180();
    InputObject* FUN_00c46970();
    InputObject* FUN_00a5ecb0(int);
    InputObject* FUN_00bc2980();
    InputObject* FUN_00c503d0();
    InputObject* FUN_00a87810(void*);
    InputObject* FUN_00a881e0(int, int, int, int, int, int, int, int, int);
    InputObject* FUN_00a75650();
    InputObject* FUN_00a6aa40();
    void FUN_005468d0(int);
    void FUN_004bc450(void*);
    void FUN_005b8fc0(int);
    void FUN_0060aeb0(int);
    void FUN_004f3200(int);
    void SetDepthParams(float);
    void FUN_0049ed90(int);
    void FUN_0086e3f0(int, int, int);
    void FUN_0086e420(int, float, float, float, float);
    void FUN_0086e4b0();
    void FUN_0086e460(int, int, float, float, float, float);
};
struct RenderSystem
{
    void FUN_0086d590();
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    int unknown_34;
    int unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int unknown_5c;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
    int unknown_84;
    Resource resource88;
    Resource resource8c;
    Resource resource90;
    Resource resource94;
    Resource resource98;
};

extern float DAT_011fd870;
extern const char str_01082c9c[];
extern const char str_01082c8c[];
extern const char str_01082c88[];
extern const char str_01082c80[];
extern const char str_01082c78[];
extern const char str_01082c68[];
extern const char str_01082c5c[];
extern const char str_01082c50[];
extern const char str_01082c40[];
extern const char str_01082c28[];


extern int FUN_004dc060(int);

extern void FUN_004bc1f0();
extern int FUN_004bc320(int);
extern void* __cdecl FUN_00aa13e0(unsigned int);
struct FUN_00b5e0f0 : NiMemObject
{
    FUN_00b5e0f0();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
    unsigned int unknown_b8;
    unsigned int unknown_bc;
    unsigned int unknown_c0;
    unsigned int unknown_c4;
    unsigned int unknown_c8;
    unsigned int unknown_cc;
    unsigned int unknown_d0;
    unsigned int unknown_d4;
    unsigned int unknown_d8;
    unsigned int unknown_dc;
    unsigned int unknown_e0;
    unsigned int unknown_e4;
    unsigned int unknown_e8;
    unsigned int unknown_ec;
    unsigned int unknown_f0;
    unsigned int unknown_f4;
    unsigned int unknown_f8;
    unsigned int unknown_fc;
    unsigned int unknown_100;
    unsigned int unknown_104;
    unsigned int unknown_108;
    unsigned int unknown_10c;
    unsigned int unknown_110;
    unsigned int unknown_114;
    unsigned int unknown_118;
    unsigned int unknown_11c;
    unsigned int unknown_120;
    unsigned int unknown_124;
    unsigned int unknown_128;
    unsigned int unknown_12c;
    unsigned int unknown_130;
    unsigned int unknown_134;
    unsigned int unknown_138;
    unsigned int unknown_13c;
    unsigned int unknown_140;
    unsigned int unknown_144;
    unsigned int unknown_148;
    unsigned int unknown_14c;
    unsigned int unknown_150;
    unsigned int unknown_154;
    unsigned int unknown_158;
    unsigned int unknown_15c;
    unsigned int unknown_160;
    unsigned int unknown_164;
    unsigned int unknown_168;
    unsigned int unknown_16c;
    unsigned int unknown_170;
    unsigned int unknown_174;
    unsigned int unknown_178;
    unsigned int unknown_17c;
    unsigned int unknown_180;
    unsigned int unknown_184;
    unsigned int unknown_188;
    unsigned int unknown_18c;
    unsigned int unknown_190;
    unsigned int unknown_194;
    unsigned int unknown_198;
    unsigned int unknown_19c;
    unsigned int unknown_1a0;
    unsigned int unknown_1a4;
    unsigned int unknown_1a8;
    unsigned int unknown_1ac;
    unsigned int unknown_1b0;
    unsigned int unknown_1b4;
    unsigned int unknown_1b8;
    unsigned int unknown_1bc;
    unsigned int unknown_1c0;
    unsigned int unknown_1c4;
    unsigned int unknown_1c8;
    unsigned int unknown_1cc;
    unsigned int unknown_1d0;
    unsigned int unknown_1d4;
    unsigned int unknown_1d8;
    unsigned int unknown_1dc;
    unsigned int unknown_1e0;
    unsigned int unknown_1e4;
    unsigned int unknown_1e8;
    unsigned int unknown_1ec;
    unsigned int unknown_1f0;
    unsigned int unknown_1f4;
    unsigned int unknown_1f8;
    unsigned int unknown_1fc;
};
struct BSFogProperty : NiMemObject
{
    BSFogProperty();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
};
struct FUN_00c46970 : NiMemObject
{
    FUN_00c46970();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
};
struct FUN_00a5ecb0 : NiMemObject
{
    FUN_00a5ecb0(unsigned int);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
};
struct FUN_00bc2980 : NiMemObject
{
    FUN_00bc2980();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
};
struct FUN_00c503d0 : NiMemObject
{
    FUN_00c503d0();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
};
struct FUN_00a87810 : NiMemObject
{
    FUN_00a87810(void*);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
    unsigned int unknown_94;
    unsigned int unknown_98;
    unsigned int unknown_9c;
    unsigned int unknown_a0;
    unsigned int unknown_a4;
    unsigned int unknown_a8;
    unsigned int unknown_ac;
    unsigned int unknown_b0;
    unsigned int unknown_b4;
    unsigned int unknown_b8;
    unsigned int unknown_bc;
    unsigned int unknown_c0;
};
struct FUN_00a881e0 : NiMemObject
{
    FUN_00a881e0(int, int, int, int, int, int, int, int, int);
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
};
struct FUN_00a75650 : NiMemObject
{
    FUN_00a75650();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
};
struct FUN_00a6aa40 : NiMemObject
{
    FUN_00a6aa40();
    unsigned int unknown_00;
    unsigned int unknown_04;
    unsigned int unknown_08;
    unsigned int unknown_0c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
};
struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool multithreaded;
    unsigned int unknown_08;
    NiUpdateData(float, bool, bool);
};
struct SettingView
{
};
extern const char str_0101fe78[];
// Creates a SceneGraph, associates resources and input objects, configures render state, and initializes additional scene objects.
// @fnv 0x0086d590
void RenderSystem::FUN_0086d590()
{
    // Memory context, scene root, and graph construction.
    AutoMemHelper h(25, 1, ::DAT_010829c4, 0xf4c);
    (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb7c)).FUN_0066b0d0(new SceneGraph(str_01082c9c, false, 0));

    DataObject* p = (DataObject*)new FUN_00b5e0f0;
    (::FUN_0086e520)(((::NiNode *)(::FUN_004bc3f0())));
    ::FUN_0086e4e0(str_01082c8c);
    ::InitRenderSystem();
    reinterpret_cast<::_Cam_00712e60 *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb7c)).FUN_00559450()->FUN_006629f0()))->FUN_00712e60((*(const ::_Rect16_00712e60 *)(&(*reinterpret_cast<int *>(&::DAT_011ad840)))));
    reinterpret_cast<::SSN *>((((ResourceObject*)p)))->FUN_0070b760(0);
    ::FUN_00b4f2f0(0, (::ShadowSceneNode *)(p));
    reinterpret_cast<::BSA_ *>((this->resource88.FUN_00559450()))->FUN_004a1020(p);
    reinterpret_cast<::BSA_ *>((this->resource8c.FUN_00559450()))->FUN_004a1020(p);
    reinterpret_cast<::BSA_ *>((this->resource90.FUN_00559450()))->FUN_004a1020(p);
    reinterpret_cast<::BSA_ *>((this->resource94.FUN_00559450()))->FUN_004a1020(p);
    reinterpret_cast<::BSA_ *>((this->resource98.FUN_00559450()))->FUN_004a1020((void*)((::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))));
    ::FUN_0086e500(0);
    ::FUN_0086e510(0);
    unsigned int f = (((bool)(::fnv_0086e540::FUN_0086e540())) == 1 ? 1u : 0u);
    f |= (((bool)(::fnv_0086e560::FUN_0086e560())) == 1 ? 2u : 0u);
    f |= (((bool)(::fnv_0086e5a0::FUN_0086e5a0())) == 1 ? 4u : 0u);
    f |= (((bool)(::fnv_0086e580::FUN_0086e580())) == 1 ? 8u : 0u);
    f |= 0x10;
    f |= (::FUN_004bc400() && FUN_004dc060(0) >= 2) ? 0x20 : 0;
    ::FUN_004bc3d0(f);
    unsigned int eb = ((bool)(::fnv_0086e5c0::FUN_0086e5c0())) ? 8 : 0;
    eb |= ((bool)(::fnv_0086e5e0::FUN_0086e5e0())) ? 2 : 0;
    DAT_011ad82c = eb;
    ::FUN_0086e4d0((unsigned int (*)(::NiAVObject *))(((unsigned int (&)(fnv_0086d590::NiAVObject *))::FUN_00564360)));
    DAT_011fd870 = 0.0f;
    (*reinterpret_cast<::fnv_0086d590::Resource *>(&::fnv_00b54630::CleanupState::DAT_011f95d8)).FUN_0066b0d0((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb7c)).FUN_00559450()->FUN_006629f0());
    ((ModuleRoot*)(*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb7c)).FUN_00559450())->virtual_dc(p, 1);

    (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb00)).FUN_0066b0d0((InputObject*)new BSFogProperty());
    reinterpret_cast<::FUN_0049ed90_shell *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb00)).FUN_00559450()))->FUN_0049ed90(1);
    reinterpret_cast<::FUN_00bb8140_shell *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb00)).FUN_00559450()))->SetDepthParams(1.0f);
    ::BSShaderManager::SetFogPropertyForIndex(0, (::BSFogProperty *)(void *)((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb00)).FUN_00559450()));

    (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb34)).FUN_0066b0d0((InputObject*)new FUN_00c46970());
    reinterpret_cast<::s005468d0::Owner *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb34)).FUN_00559450()))->FUN_005468d0(1);
    reinterpret_cast<::TaskQueueInterface *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb34)).FUN_00559450()))->SetTaskFlag2000(1);
    ::AssignFixedString((char *)((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb34)).FUN_00559450()), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c88)), {});
    p->virtual_f8(0, (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb34)).FUN_00559450());

    (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deda4)).FUN_0066b0d0((InputObject*)new FUN_00a5ecb0(0));
    reinterpret_cast<::FUN_00546780_shell *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deda4)).FUN_00559450()))->FUN_00546780(1);
    reinterpret_cast<::TaskQueueInterface *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deda4)).FUN_00559450()))->SetTaskFlag2000(1);
    ::AssignFixedString((char *)((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deda4)).FUN_00559450()), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_0101fe78)), {});
    p->virtual_f8(1, (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deda4)).FUN_00559450());
    ::FUN_004dc5c0();
    ::Main::CreateMenuSceneGraph();

    (*reinterpret_cast<::fnv_0086d590::InputObject * *>(&::DAT_011dea14)) = (InputObject*)new FUN_00bc2980();
    ::AssignFixedString((char *)((*reinterpret_cast<::fnv_0086d590::InputObject * *>(&::DAT_011dea14))), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c80)), {});
    p->virtual_f8(2, (*reinterpret_cast<::fnv_0086d590::InputObject * *>(&::DAT_011dea14)));

    // s is the active scene parent; a is its tree child.
    InputObject* s = (InputObject*)new FUN_00a5ecb0(0);
    reinterpret_cast<::FUN_00546780_shell *>((s))->FUN_00546780(1);
    reinterpret_cast<::TaskQueueInterface *>((s))->SetTaskFlag2000(1);
    ::AssignFixedString((char *)(s), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c78)), {});
    (*reinterpret_cast<::fnv_0086d590::InputObject * *>(&::DAT_011dea14))->virtual_dc(s, 1);

    const_cast<float &>(::DAT_011ad808) = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0086d590::SettingView *>(&::g_011dedc8))))));
    s = (InputObject*)new FUN_00a5ecb0(0);
    reinterpret_cast<::FUN_00546780_shell *>((s))->FUN_00546780(1);
    reinterpret_cast<::TaskQueueInterface *>((s))->SetTaskFlag2000(1);
    ::AssignFixedString((char *)(s), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c68)), {});
    (*reinterpret_cast<::fnv_0086d590::InputObject * *>(&::DAT_011dea14))->virtual_dc(s, 1);

    ::DAT_011dea1c = (intptr_t)(InputObject*)new FUN_00a5ecb0(0);
    reinterpret_cast<::FUN_00546780_shell *>((((InputObject*)::DAT_011dea1c)))->FUN_00546780(1);
    reinterpret_cast<::TaskQueueInterface *>((((InputObject*)::DAT_011dea1c)))->SetTaskFlag2000(1);
    ::AssignFixedString((char *)(((InputObject*)::DAT_011dea1c)), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c5c)), {});
    (*reinterpret_cast<::fnv_0086d590::InputObject * *>(&::DAT_011dea14))->virtual_dc((InputObject*)::DAT_011dea1c, 1);

    InputObject* a = (InputObject*)new FUN_00a5ecb0(0);
    reinterpret_cast<::FUN_00546780_shell *>((a))->FUN_00546780(1);
    reinterpret_cast<::TaskQueueInterface *>((a))->SetTaskFlag2000(1);
    ::AssignFixedString((char *)(a), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c50)), {});
    s->virtual_dc(a, 1);
    ::FUN_0086e620(a);
    (::FUN_0086e630)((NiNode*)a);

    ::DAT_011dea18 = (intptr_t)(InputObject*)new FUN_00a5ecb0(0);
    reinterpret_cast<::FUN_00546780_shell *>((((InputObject*)::DAT_011dea18)))->FUN_00546780(1);
    reinterpret_cast<::TaskQueueInterface *>((((InputObject*)::DAT_011dea18)))->SetTaskFlag2000(1);
    ::AssignFixedString((char *)(((InputObject*)::DAT_011dea18)), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c40)), {});
    p->virtual_f8(3, ((InputObject*)::DAT_011dea18));

    (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011ded58)).FUN_0066b0d0((InputObject*)new FUN_00c503d0());
    ::AssignFixedString((char *)((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011ded58)).FUN_00559450()), (intptr_t)&(const ::fnv_0086d590::NiFixedString &)(NiFixedString(str_01082c28)), {});
    p->virtual_f8(5, (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011ded58)).FUN_00559450());

    reinterpret_cast<::FUN_004bc1f0_S *>((((::fnv_0086d590::ResourceObject *)(::FUN_00558310((::NiNode_00558310 *)((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb7c)).FUN_00559450()))))))->FUN_004bc1f0(0.0f, 0.0f, ::DAT_0101e704);
    reinterpret_cast<::FUN_00a5a040_Class *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb7c)).FUN_00559450()))->FUN_00a5a040();
    NiUpdateData i(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011deb7c)).FUN_00559450()))->FUN_00a59c60((std::intptr_t)(&i));
    reinterpret_cast<::FUN_004dc540_shell *>((((::fnv_0086d590::DataObject *)(::FUN_0043c4b0()))))->FUN_004dc540((::NiAVObject *)(void *)(((void *)(::FUN_00b4f5c0()))));
    (*reinterpret_cast<unsigned char *>(&::DAT_011dea28)) = ::fnv_0086e600::FUN_0086e600();

    if (!(*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450())
    {
        (*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_0066b0d0((InputObject*)new FUN_00a87810(new FUN_00a881e0(0, 0, 1, 1, 1, 4, 1, 2, 1)));
        reinterpret_cast<::FUN_0086e3f0_shell *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()))->FUN_0086e3f0(4, 0, 0);
        reinterpret_cast<::fnv_0086e420::FUN_0086e420_shell *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()))->FUN_0086e420(0, 0.0f, 0.0f, 1.0f, 1.0f);
        ::fnv_0086e4b0::FUN_0086e4b0((::fnv_0086e4b0::NiGeometry *)((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()));
        reinterpret_cast<::fnv_0086e460::FUN_0086e460_shell *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()))->FUN_0086e460(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
        InputObject* p = (InputObject*)new FUN_00a75650();
        reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>((p))->FUN_004bc450((const ::fnv_004bc450::C3 *)(void *)((void*)&(*reinterpret_cast<int *>(&::DAT_011a9b7c))));
        reinterpret_cast<::FUN_00439410_cls *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()))->FUN_00439410((::ArgObject *)(p));
        InputObject* h = (InputObject*)new FUN_00a6aa40();
        reinterpret_cast<::FUN_005b8fc0_shell *>((h))->FUN_005b8fc0((::NiNode *)(((intptr_t)(reinterpret_cast<::FUN_004bc320_shell *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011ded3c)).FUN_00559450()))->FUN_004bc320(0)))));
        h->FUN_0060aeb0(0);
        h->FUN_004f3200(0);
        reinterpret_cast<::FUN_00439410_cls *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()))->FUN_00439410((::ArgObject *)(h));
        reinterpret_cast<::FUN_00a5a040_Class *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()))->FUN_00a5a040();
        NiUpdateData i(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>(((*reinterpret_cast<::fnv_0086d590::Resource *>(&::g_011dec94)).FUN_00559450()))->FUN_00a59c60((std::intptr_t)(&i));
    }
    ::fnv_0057cf00::UpdateTerrainLODMaxRange();
}
}  // namespace fnv_0086d590

struct S00875bf0_Cam875
{
};
struct S00875bf0_Color875
{
    float x, y, z, w;
    S00875bf0_Color875(float, float, float, float);
};
struct S00875bf0_Scene875
{
};
struct S00875bf0_Face875
{
};
struct FORenderedMenu
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};
struct S00875bf0_Ptr875
{
    void* FUN_00559450();
};
struct S00875bf0_Render875
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v30();
    virtual void* v31();
    virtual void* v32();
    virtual void* v33();
    virtual void* v34();
    virtual void* v35();
    virtual void* v36();
    virtual void* v37();
    virtual void* v38();
    virtual void* v39();
    virtual void* v40();
    virtual void* v41();
    virtual void* v42();
    virtual void* v43();
    virtual void* v44();
    virtual void* v45();
    virtual void* v46();
    virtual void* v47();
    virtual void* v48();
    virtual void* v49();
    virtual void* v50();
    virtual void* v51();
};
struct BSShaderManagerRenderMode
{
};
struct S00875bf0_BSA_
{
};
class ShadowSceneNode;
struct S00875bf0_FaceNode875
{
    void* GetAnimationData();
};
struct S00875bf0_Shell875
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S00875bf0_Ptr875 scene;
    void FUN_00875bf0();
};
// Sets up the face scene and camera, invokes rendering calls with the target scene, and restores the scene state.
// @fnv 0x00875bf0
void S00875bf0_Shell875::FUN_00875bf0()
{
    if (!(*reinterpret_cast<::Receiver86 *>(&::g_011deb38)).FUN_00559450() && ::FUN_00707ad0() && ::FUN_00707ad0() != ((::FORenderedMenu *)(::fnv_00705990::FUN_00705990())))
    {
        S00875bf0_FaceNode875* face = (S00875bf0_FaceNode875*)((::BSFaceGenNiNode *)(::FUN_0045c670()));
        S00875bf0_Scene875* scene = ((::S00875bf0_Scene875 *)(reinterpret_cast<::SceneGraph *>(((S00875bf0_Face875*)face))->cullingProcess));
        reinterpret_cast<::FUN_00c4f270_Class *>((scene))->FUN_00c4f270(1);
        S00875bf0_Cam875* camera = ((::S00875bf0_Cam875 *)(reinterpret_cast<::RenderedMenuCameraView *>(::FUN_00707ad0())->camera)) ? ((::S00875bf0_Cam875 *)(reinterpret_cast<::RenderedMenuCameraView *>(::FUN_00707ad0())->camera))
                                                                  : (S00875bf0_Cam875*)face->GetAnimationData();
        reinterpret_cast<::FUN_0041fd00_shell *>((scene))->FUN_0041fd00((intptr_t)(camera));
        reinterpret_cast<::FUN_004a0fd0_shell *>((scene))->FUN_004a0fd0((::NiNode *)(void *)(this->scene.FUN_00559450()));
        reinterpret_cast<::BSA_ *>((((S00875bf0_BSA_*)this->scene.FUN_00559450())))->FUN_004a1020(((::ShadowSystem *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))));
        if ((*reinterpret_cast<unsigned char *>(&::DAT_011f9426)) &&
            (!((S00875bf0_Render875*)((::Receiver86 *)(::FUN_0043c4b0())))->v51() ||
             ((S00875bf0_Render875*)((::Receiver86 *)(::FUN_0043c4b0())))->v51() == ((S00875bf0_Render875*)((::Receiver86 *)(::FUN_0043c4b0())))->v50()))
            reinterpret_cast<::_Cam_00712e60 *>((camera))->FUN_00712e60((const ::_Rect16_00712e60 &)((*reinterpret_cast<::S00875bf0_Color875 *>(&::DAT_011ad840))));
        else
            reinterpret_cast<::_Cam_00712e60 *>((camera))->FUN_00712e60((const ::_Rect16_00712e60 &)((const ::S00875bf0_Color875 &)(S00875bf0_Color875(0.0f, 1.0f, 1.0f, 0.0f))));
        ::FUN_00b6bee0(camera, ::FUN_00707ad0()->v2(), (::BSShaderAccumulator *)(scene));
        ::BSShaderManager::SetRenderMode(15);
        ::FUN_00b97e30(0, 1);
        ::BSRenderStateManager::SetColorWriteMask(8, (::BSRENDERSTATE_LOCK)(1));
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(camera), (::BSShaderAccumulator *)(void *)(this->scene.FUN_00559450()), 0);
        ::BSShaderManager::SetRenderMode(0);
        FUN_004eced0(1);
        FUN_00714a60(1);
        ::FUN_00b6bee0(camera, ::FUN_00707ad0()->v2(), (::BSShaderAccumulator *)(scene));
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(camera), (::BSShaderAccumulator *)(void *)(this->scene.FUN_00559450()), 0);
        reinterpret_cast<::FUN_004a0fd0_shell *>((scene))->FUN_004a0fd0((::NiNode *)(void *)(0));
        reinterpret_cast<::FUN_00c4f2d0_class *>((scene))->FUN_00c4f2d0();
    }
}


struct BSBatchRenderer__PassList
{
    unsigned int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

// The pass lists FUN_00b65660 resets: two groups of four.
struct BSBatchRendererPassListsView
{
    char pad00[0x9c];
    BSBatchRenderer__PassList unk9c[8];
};
// @fnv 0x00b65660
void FUN_00b65660_StandIn::FUN_00b65660()
{
    BSBatchRenderer__PassList* p = reinterpret_cast<BSBatchRendererPassListsView*>(this)->unk9c;
    for (int i = 0; i < 4; ++i, ++p)
    {
        reinterpret_cast<::FUN_00b63e90_cls *>(p)->ReleasePoolNodes();
        p->unk0c = p->unk04;
        p->unk04 = 0;
        p->unk08 = 0;
        p->unk10 = 0;
        reinterpret_cast<::FUN_00b63e90_cls *>(p + 4)->ReleasePoolNodes();
        p[4].unk0c = p[4].unk04;
        p[4].unk04 = 0;
        p[4].unk08 = 0;
        p[4].unk10 = 0;
    }
}

struct PluginListEntry
{
};
struct PluginListHandler
{
};
struct Receiver86;


// @fnv 0x00872430
bool PluginListReader::FUN_00872430(const char* pDir, const char* pName)
{
    char acPath[260];
    char acLine[512];
    FILE* pFile;
    {
        bool m_bHeaderParsed = false;
        ::TaskQueueInterface::CopyStringToBuffer(acPath, 260, pDir);
        strcat_s(acPath, 260, pName);
        pFile = fopen(acPath, DAT_01082cb8);
        if (pFile)
        {
            while (std::fgets(acLine, 512, (std::FILE *)(pFile)))
            {
                unsigned int uiLen = ::FUN_0044a670(acLine);
                if (acLine[0] != '#' && uiLen > 1)
                {
                    if (acLine[uiLen - 1] == '\n')
                        acLine[uiLen - 1] = 0;
                    TESFile* m_pFileEntry = reinterpret_cast<::TESDataHandler *>((((PluginListHandler*)(*reinterpret_cast<::Receiver86 * *>(&::g_dataHandler)))))->LookupTESFile(acLine);
                    if (m_pFileEntry)
                    {
                        reinterpret_cast<::EffectSettingCollection *>((((PluginListEntry*)m_pFileEntry)))->InitializeCollection(true);
                        m_bHeaderParsed = true;
                    }
                }
            }
            fclose(pFile);
        }
        return m_bHeaderParsed;
    }
}
#include "generated/data/fallout/misc/main.inc"
