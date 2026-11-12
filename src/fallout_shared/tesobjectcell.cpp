#include "fnv/native_fixed_string.h"
#include "AutoMemContext.h"
// fallout_shared/tesobjectcell.cpp: TESObjectCELL, Owner, Cell, hkpEntityListener and more (325 functions)

#include "fnv/save_load_game_view.h"
#include "fnv/game_timer.h"
#include "fnv_result_slot.h"
#include <bit>
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <new>
#include <cstring>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/Arr86.h"
#include "fnv/decl/B445670Loader.h"
#include "fnv/decl/B49F8F0Allocator.h"
#include "fnv/decl/B5695A0Ref.h"
#include "fnv/decl/B5729E0Ref.h"
#include "fnv/decl/B9A0Ref.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSA_.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/BoxInput.h"
#include "fnv/decl/C420410ExtraList.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellLighting__Cell.h"
#include "fnv/decl/CellMopp_00621e80.h"
#include "fnv/decl/CellQ.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/Cell_Sub.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DecalListManager.h"
#include "fnv/decl/Dfcfa0Manager.h"
#include "fnv/decl/ExtraList420.h"
#include "fnv/decl/ExtraSave__ExtraList.h"
#include "fnv/decl/FUN_00401280_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_004121b0_shell.h"
#include "fnv/decl/FUN_00413fc0_Class.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00418690_shell.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00419ad0_shell.h"
#include "fnv/decl/FUN_0041aed0_shell.h"
#include "fnv/decl/FUN_0041bce0_class.h"
#include "fnv/decl/FUN_0041c160_Class.h"
#include "fnv/decl/FUN_0041c6f0_class.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_0041e130_shell.h"
#include "fnv/decl/FUN_0041fbe0_shell.h"
#include "fnv/decl/FUN_00420100_cls.h"
#include "fnv/decl/FUN_00420810_shell.h"
#include "fnv/decl/FUN_004208b0_cls.h"
#include "fnv/decl/FUN_00420ba0_Class.h"
#include "fnv/decl/FUN_00420bc0_cls.h"
#include "fnv/decl/FUN_00420e00_cls.h"
#include "fnv/decl/FUN_00421820_Class.h"
#include "fnv/decl/FUN_00421850_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00421e10_shell.h"
#include "fnv/decl/FUN_00422120_shell.h"
#include "fnv/decl/FUN_00422150_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_004396b0_class.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00439f90_shell.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_00444ed0_shell.h"
#include "fnv/decl/FUN_00448a60_struct.h"
#include "fnv/decl/FUN_00450fd0_class.h"
#include "fnv/decl/FUN_004512a0_shell.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_004523c0_shell.h"
#include "fnv/decl/FUN_00452440_shell.h"
#include "fnv/decl/FUN_00452e50_class.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00454380_Class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00454b30_class.h"
#include "fnv/decl/FUN_00456630_Class.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_0045c4c0_cls.h"
#include "fnv/decl/FUN_0045c9a0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045ce40_class.h"
#include "fnv/decl/FUN_00460340_shell.h"
#include "fnv/decl/FUN_00461310_shell.h"
#include "fnv/decl/FUN_00461c20_Holder.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00464df0_shell.h"
#include "fnv/decl/FUN_004705c0_cls.h"
#include "fnv/decl/FUN_00472150_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_00472fe0_cls.h"
#include "fnv/decl/FUN_00473310_cls.h"
#include "fnv/decl/FUN_004734d0_shell.h"
#include "fnv/decl/FUN_00476ae0_class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047cdb0_shell.h"
#include "fnv/decl/FUN_00483d20_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00484d20_Class.h"
#include "fnv/decl/FUN_00484d40_Host.h"
#include "fnv/decl/FUN_004854e0_shell.h"
#include "fnv/decl/FUN_00485b60.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004893c0_class.h"
#include "fnv/decl/FUN_00497280_shell.h"
#include "fnv/decl/FUN_0049ee60_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004a1040_Helper.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_004ebbc0_shell.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f5f80_cls.h"
#include "fnv/decl/FUN_004f6640_cls.h"
#include "fnv/decl/FUN_00502180_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0050d1d0_class.h"
#include "fnv/decl/FUN_0050d1f0_Class.h"
#include "fnv/decl/FUN_0050d210_Class.h"
#include "fnv/decl/FUN_0050d230_class.h"
#include "fnv/decl/FUN_00518080_shell.h"
#include "fnv/decl/FUN_005194d0_shell_base.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00526ae0_class.h"
#include "fnv/decl/FUN_005271b0_Class.h"
#include "fnv/decl/FUN_00546bf0_class.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_00549610_Class.h"
#include "fnv/decl/FUN_005516c0.h"
#include "fnv/decl/FUN_00555bc0_shell.h"
#include "fnv/decl/FUN_00558600_Class.h"
#include "fnv/decl/FUN_005593a0_cls.h"
#include "fnv/decl/FUN_00559810.h"
#include "fnv/decl/FUN_00559900_Struct.h"
#include "fnv/decl/FUN_00559a70_Class.h"
#include "fnv/decl/FUN_00559bc0_cls.h"
#include "fnv/decl/FUN_00559c90_Class.h"
#include "fnv/decl/FUN_0055f5b0_Class.h"
#include "fnv/decl/FUN_00564e60_shell.h"
#include "fnv/decl/FUN_00564f00_shell.h"
#include "fnv/decl/FUN_00568680_shell.h"
#include "fnv/decl/FUN_00569060_shell.h"
#include "fnv/decl/FUN_005694c0_shell.h"
#include "fnv/decl/FUN_00569580_shell.h"
#include "fnv/decl/FUN_0056a380_shell.h"
#include "fnv/decl/FUN_0057a2f0_shell.h"
#include "fnv/decl/FUN_0057a370_shell.h"
#include "fnv/decl/FUN_005831d0_shell.h"
#include "fnv/decl/FUN_00583270_cls.h"
#include "fnv/decl/FUN_00586020_shell.h"
#include "fnv/decl/FUN_00587e40_shell.h"
#include "fnv/decl/FUN_0058f080.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f9ad0_shell.h"
#include "fnv/decl/FUN_005f9af0_shell.h"
#include "fnv/decl/FUN_0061f8e0_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00622590_Owner.h"
#include "fnv/decl/FUN_006242a0_cls.h"
#include "fnv/decl/FUN_006242f0_shell.h"
#include "fnv/decl/FUN_006299c0_cls.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_0069bca0_class.h"
#include "fnv/decl/FUN_006c0f10_shell.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_00740940_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0078d200_cls.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865e70_shell.h"
#include "fnv/decl/FUN_00881c90_cls.h"
#include "fnv/decl/FUN_008a5cf0_shell.h"
#include "fnv/decl/FUN_008d0370_shell.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00931e80_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0096aaf0_shell.h"
#include "fnv/decl/FUN_009707f0_shell.h"
#include "fnv/decl/FUN_0099e040_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00aa54a0_s.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00ad9030_shell.h"
#include "fnv/decl/FUN_00b8c830_class.h"
#include "fnv/decl/FUN_00c39a80_cls.h"
#include "fnv/decl/FUN_00c3e750_Class.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/FUN_00c5b5d0_class.h"
#include "fnv/decl/FUN_00c66fb0_Class.h"
#include "fnv/decl/FUN_00c6a620_cls.h"
#include "fnv/decl/Fade.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/GlobalObject_0045cf30.h"
#include "fnv/decl/Hold580.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder00420dd0.h"
#include "fnv/decl/Holder4523e0.h"
#include "fnv/decl/ImageSpaceManager.h"
#include "fnv/decl/ImpactSwapMaps.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LoadedReferenceMap.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Map6920.h"
#include "fnv/decl/Matrix161.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NavRenderX.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/Obj554720.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/Own60.h"
#include "fnv/decl/Owner5b.h"
#include "fnv/decl/OwnerC5.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/RectangleClip.h"
#include "fnv/decl/Ref5699.h"
#include "fnv/decl/Ref56B0.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/RegionMatch.h"
#include "fnv/decl/RenderTask.h"
#include "fnv/decl/Root.h"
#include "fnv/decl/S00416a30.h"
#include "fnv/decl/S00416a70.h"
#include "fnv/decl/S00551440.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/S5460.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/SLGameShell.h"
#include "fnv/decl/ST_00849cc0.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/S_004e46b0_Cls.h"
#include "fnv/decl/S_004ed780.h"
#include "fnv/decl/S_0050de20_Class.h"
#include "fnv/decl/S_00a592c0_Matrix3.h"
#include "fnv/decl/S_00c5ae70_Class.h"
#include "fnv/decl/S_00c5b140.h"
#include "fnv/decl/S_00c5ba50_Class.h"
#include "fnv/decl/S_00c90db0_Foo.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "fnv/decl/Sky.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/SwapBlock.h"
#include "fnv/decl/TESBuffer45130.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESContainer.h"
#include "fnv/decl/TESFormSortProxy.h"
#include "fnv/decl/TESObjectCELL_Ext.h"
#include "fnv/decl/TESObjectREFR569.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TriHack.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/WorldReader.h"
#include "fnv/decl/extra421__E4List.h"
#include "fnv/decl/fnv_00404f70__FUN_00404f70_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00411ec0__FUN_00411ec0_shell.h"
#include "fnv/decl/fnv_00412380__FUN_00412380_shell.h"
#include "fnv/decl/fnv_004169f0__BSOcclusionPlane_Fake.h"
#include "fnv/decl/fnv_00418550__FUN_00418550_cls.h"
#include "fnv/decl/fnv_0041b8d0__FUN_0041b8d0_shell.h"
#include "fnv/decl/fnv_0041ba60__FUN_0041ba60_shell.h"
#include "fnv/decl/fnv_0041c290__FUN_0041c290_shell.h"
#include "fnv/decl/fnv_0041c490__FUN_0041c490_cls.h"
#include "fnv/decl/fnv_004207b0__FUN_004207e0Class.h"
#include "fnv/decl/fnv_00420f00__FUN_00420f00_shell.h"
#include "fnv/decl/fnv_00421400__FUN_00421400.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_00454b10__TESObjectCELL.h"
#include "fnv/decl/fnv_00454c20__RecentItems.h"
#include "fnv/decl/fnv_0047ce10__OwnerShell.h"
#include "fnv/decl/fnv_0047d680__FUN_0047d680_shell.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_004c3380__FUN_004c3380_shell.h"
#include "fnv/decl/fnv_0050ebf0__FUN_0050ebf0_shell.h"
#include "fnv/decl/fnv_005340e0__TESObjectLAND.h"
#include "fnv/decl/fnv_00559ad0__FUN_00559ad0_Class.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_005656d0__Thing.h"
#include "fnv/decl/fnv_00565870__FUN_00565870_shell.h"
#include "fnv/decl/fnv_00567dd0__FUN_00567dd0_shell.h"
#include "fnv/decl/fnv_00569990__TargetClass.h"
#include "fnv/decl/fnv_00569ae0__XActor.h"
#include "fnv/decl/fnv_0056a250__FUN_0056a250_shell.h"
#include "fnv/decl/fnv_0056f700__Ref.h"
#include "fnv/decl/fnv_00572380__Fn572380.h"
#include "fnv/decl/fnv_005728c0__FUN_005728c0_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00587760__FUN_00587760_shell.h"
#include "fnv/decl/fnv_00631540__TargetClass.h"
#include "fnv/decl/fnv_006c0c30__Mgr006c0c30.h"
#include "fnv/decl/fnv_006c1cb0__Call_006c0c80.h"
#include "fnv/decl/fnv_006fd010__FUN_006fd010_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008492b0__FUN_008492b0_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0086ff70__Main86.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_0096dcb0__Owner96.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00b5ddf0__LocalTarget.h"
#include "fnv/decl/fnv_00c5aef0__FUN_00c5aef0_cls.h"
#include "fnv/decl/fnv_00c5b370__ItemQueue.h"
#include "fnv/decl/fnv_00c93820__hkpWorldC938.h"
#include "fnv/decl/fnv_00c93860__hkpWorldXc93860.h"
#include "fnv/decl/fnv_00c93a20__hkpWorldXc93a20.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/s005468d0__Owner.h"
#include "fnv/decl/xLand.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00421000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00452000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00456000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00486000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004bc000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_004e2000.h"
#include "fnv/symbols_004e7000.h"
#include "fnv/symbols_004e9000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00538000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_00544000.h"
#include "fnv/symbols_00545000.h"
#include "fnv/symbols_00546000.h"
#include "fnv/symbols_00547000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_0054a000.h"
#include "fnv/symbols_0054d000.h"
#include "fnv/symbols_0054e000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_00550000.h"
#include "fnv/symbols_00551000.h"
#include "fnv/symbols_00552000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00554000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00565000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_00586000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00600000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_00665000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_006c1000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00878000.h"
#include "fnv/symbols_00879000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00950000.h"
#include "fnv/symbols_00993000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00aff000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b54000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00b57000.h"
#include "fnv/symbols_00b5a000.h"
#include "fnv/symbols_00c66000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_00fff000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_0118b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ab000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"
#include "tesobjectcell_packet.h"
#include <malloc.h>
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00547440_Class.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00759d80_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_0041c390__ExtraDataList2.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0058f180__FUN_0058f180.h"
#include "fnv/decl/loader__List.h"
#include "fnv/symbols_0041c000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/decl/FUN_004867a0_cls.h"
#include "fnv/decl/FUN_00557760_cls.h"
#include "fnv/decl/NavShell2.h"
#include "fnv/decl/fnv_00565480__RefPersistsStandin.h"
#include "fnv/decl/n547__Cell.h"
#include "fnv/decl/Cls.h"
#include "fnv/decl/FUN_00421a70_shell.h"
#include "fnv/decl/FUN_0085f850_class.h"
#include "fnv/decl/FUN_008727b0_Class.h"
#include "fnv/decl/Manager859.h"
#include "fnv/decl/SaveLoadGame_8495d0.h"
#include "fnv/decl/fnv_00416be0__ResolveExtraOwner.h"
#include "fnv/decl/fnv_00858730__FUN_00858730_shell.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/decl/fnv_00569ac0__FUN_00569ac0_shell.h"
#include "fnv/decl/fnv_00587870__OverlapHolder.h"
#include "fnv/decl/B56B250Ref.h"
#include "fnv/decl/FUN_005651e0_shell.h"
#include "fnv/decl/LodGrid.h"
#include "fnv/decl/ML.h"
#include "fnv/decl/Ref3.h"
#include "tesobjectcell_packet_decl_tesobjectcell.h"
#include "fnv/decl/Actor_0087f4a0.h"
#include "fnv/decl/B572270Object.h"
#include "fnv/decl/FUN_0041de40_class.h"
#include "fnv/decl/FUN_0041df90_shell.h"
#include "fnv/decl/FUN_0041dfd0_Shell.h"
#include "fnv/decl/FUN_0041e310_shell.h"
#include "fnv/decl/FUN_0042cde0_shell.h"
#include "fnv/decl/FUN_0042e250_shell.h"
#include "fnv/decl/FUN_00452370_shell.h"
#include "fnv/decl/FUN_00477090_Owner.h"
#include "fnv/decl/FUN_00484580_shell.h"
#include "fnv/decl/FUN_00484610_shell.h"
#include "fnv/decl/FUN_00526120_shell.h"
#include "fnv/decl/FUN_00565450_shell.h"
#include "fnv/decl/FUN_00569250_shell.h"
#include "fnv/decl/FUN_0056ae60_Class.h"
#include "fnv/decl/s577de0__Owner.h"
#include "fnv/symbols_00475000.h"
#include "fnv/symbols_00526000.h"
#include "fnv/symbols_005ac000.h"
#include <xmmintrin.h>
#include <cmath>
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_00b5a9a0_List.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/symbols_01203000.h"
#include "fnv/decl/CellShell.h"
#include "fnv/decl/FUN_00453490_shell.h"
#include "tesobjectcell_packet_rtti2_tesobjectcell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_00519500_class.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_005725f0_shell.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_0063c690_shell.h"
#include "fnv/decl/FUN_00644950_shell.h"
#include "fnv/decl/FUN_0087abb0_shell.h"
#include "fnv/decl/FUN_0087b400_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00885a30_Class.h"
#include "fnv/decl/InventoryMove.h"
#include "fnv/decl/KillActor.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/WorldSpaceRefShell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_005692a0__FUN_005692a0_shell.h"
#include "fnv/decl/fnv_0063b630__SkyHelper.h"
#include "fnv/decl/fnv_0063bab0__FUN_0063bab0_shell.h"
#include "fnv/decl/fnv_0087aad0__FUN_0087aad0_s.h"
#include "fnv/symbols_00548000.h"
#include "fnv/symbols_00555000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011f6000.h"
#include "tesobjectcell_packet_rtti_variant.h"
#include "fnv/decl/FUN_00484150_shell.h"
#include "tesobjectcell_packet_rtti_variant_decl_tesobjectcell_rtti_variant.h"

const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";

// Returns true if the cell's extra data list contains extra data of type 9, otherwise false.
// @fnv 0x00551620
bool TESObjectCELL::HasCellExtraData()
{
    if (reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(&(extraDataList))->FUN_00410220(9))
        return true;
    return false;
}

// @fnv 0x0054ddd0
TESWorldSpace* TESObjectCELL::GetParentWorldSpace()
{
    TESWorldSpace* result = 0;
    if (!IsCellInterior())
        result = worldSpace;
    return result;
}

// @fnv 0x00541ac0
void TESObjectCELL::CellRefLockEnter()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(refListLock))->FUN_0040fbf0((char *)(kTESObjectCELLCellRefLockEnter));
}

// Removes non-persistent cell data, deletes cellData, clears the lighting template and unknownDC.
// @fnv 0x00541b00
void TESObjectCELL::ClearData()
{
    reinterpret_cast<::FUN_004120b0_shell *>(&(extraDataList))->FUN_004120b0();
    if (IsCellInterior())
    {
        void* data = cellData;
        ::FUN_00401030(data);
    }
    else
    {
        void* data = cellData;
        ::FUN_00401030(data);
    }
    cellData = 0;
    SetLightingTemplate(0);
    unknownDC = 0;
}

// @fnv 0x00543c30
unsigned char TESObjectCELL::GetField24()
{
    return field24;
}

// @fnv 0x00542d20
unsigned char TESObjectCELL::FUN_00542d20()
{
    return field619;
}

// @fnv 0x005454d0
void* TESObjectCELL::FUN_005454d0()
{
    return field760;
}

// @fnv 0x00552bb0
unsigned char TESObjectCELL::FUN_00552bb0()
{
    return field210;
}

// @fnv 0x00553b90
unsigned char TESSound::GetField45()
{
    return field45;
}

// @fnv 0x0054f4c0
void* FUN_0054f4c0()
{
    return DAT_011ca438;
}

// @fnv 0x0054f4f0
NiAVObject* FUN_0054f4f0()
{
    return g_011deda4.operator->();
}

// @fnv 0x00462270
TESRecordHeader* TESFile::GetRecordHeader()
{
    return reinterpret_cast<TESRecordHeader*>(pad + 0x240);
}

// @fnv 0x009185e0
unsigned int PlayerMover::GetActorStateFlags()
{
    return moveMode;
}

// @fnv 0x004503f0
int TESObjectCELL::GetCellStandValue()
{
    return ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(reinterpret_cast<SettingT_GameSettingCollection_*>(this)))))->i;
}

// @fnv 0x005497a0
NiAVObject* TESObjectCELL::GetDynamicNode()
{
    return GetCellChildAt(4);
}

// Deletes each BGSPerkEntry in audioMarkers, clears the list, and resets audioMarkerCount to 0.
// @fnv 0x00947d10
void TESObjectCELL::ClearAudioMarkers()
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&audioMarkers);
    while (node)
    {
        BGSPerkEntry* item = (node->item);
        delete item;
        node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>(&(audioMarkers))->RemoveAll();
    audioMarkerCount = 0;
}

struct FUN_004610d0_shell : public TESObjectCELL
{
    ExtraDataList* GetExtraDataList();
};
// @fnv 0x00546c20
BGSEncounterZone* TESObjectCELL::FindEncounterZone() const
{
    BGSEncounterZone* zone =
        reinterpret_cast<::FUN_00421c30_shell *>((void *)(reinterpret_cast<ExtraDataList*>(
            ((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(const_cast<TESObjectCELL*>(this))))->GetExtraDataList())))))->FUN_00421c30();
    if (!zone && const_cast<TESObjectCELL*>(this)->GetParentWorldSpace())
        zone = ((::BGSEncounterZone *)(std::uintptr_t)(reinterpret_cast<::FUN_00458400_cls *>((void *)(const_cast<TESObjectCELL*>(this)->GetParentWorldSpace()))->GetFieldD0()));
    return zone;
}
// Returns the owner from the extra data list, falling back to the encounter zone's parent when no owner is set.
// @fnv 0x00546a40
TESForm* DoorCell::GetOwner()
{
    TESForm* owner =
        reinterpret_cast<::FUN_00418660_shell *>((reinterpret_cast<ExtraDataList*>(((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->GetExtraDataList())))))->FUN_00418660();
    if (!owner)
    {
        BGSEncounterZone* zone = reinterpret_cast<TESObjectCELL*>(this)->FindEncounterZone();
        if (zone && zone != TESObjectREFR::GetDefaultEncounterZone())
            owner = reinterpret_cast<TESForm*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(zone)))->FUN_009611e0())));
    }
    return owner;
}

// @fnv 0x004610d0
ExtraDataList* FUN_004610d0_shell::GetExtraDataList()
{
    return &this->extraDataList;
}


// @fnv 0x004b5a80
void* __cdecl FUN_004b5a80(const void* apBody)
{
    return ((void *)(::DeallocateIfPresent((::TESSound *)(apBody))));
}

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
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

class NiNode;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(const NiPointer<T>&);
    ~NiPointer();
    NiPointer<T>& operator=(T*);
};
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer(NiAVObject* p);
    ~NiPointer();
    NiPointer<NiAVObject>& operator=(NiAVObject* p);
};


struct SettingFloatHelper : SettingT_GameSettingCollection_
{
};

// @fnv 0x00541b80
void FUN_00541b80()
{
    NiPoint3 center;
    *(int*)&center.x = (*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
    *(int*)&center.y = ::_DAT_011f4270;
    *(int*)&center.z = ::_DAT_011f4274;
    DAT_011ca08c = 0;
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011ca0d8)) = ((::NiNode *)(::FUN_00554010((const class ::FUN_006815c0 *)(::NiPoint3 *)(&center))));
    if (*((float *)&(::FUN_00403e20((float *)(((SettingFloatHelper*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting37))))))) > DAT_01016968)
    {
        reinterpret_cast<::S_004ed780 *>((((SettingFloatHelper*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting37)))))->FUN_004ed780(g_011c7b14_arg1);
    }
}

struct FUN_00544390_shell : public TESObjectCELL
{
    void SetFlag40(bool);
};

// Sets or clears bit 0x40 in the byte at offset 0x24, then calls the virtual at vtable offset 0x48 with argument 2.
// @fnv 0x00544390
void FUN_00544390_shell::SetFlag40(bool abVal)
{
    if (abVal)
        this->field24 |= 0x40;
    else
        this->field24 &= ~0x40;
    (*(void(**)(TESObjectCELL*, int))(*(char**)this + 0x48))(this, 2);
}

struct FUN_005445d0_shell : public TESObjectCELL
{
    void* FUN_005445d0();
};
// Returns the x coordinate of the exterior cell data, or 0 if the cell has no exterior data.
// @fnv 0x00544c30
int TESObjectCELL::GetCellGridX()
{
    ExteriorCellData* data = ((::ExteriorCellData *)(reinterpret_cast<::FUN_005445d0_shell *>(this)->FUN_005445d0()));
    if (data)
        return data->x;
    return 0;
}
// Returns the y coordinate of the exterior cell data, or 0 if the cell has no exterior data.
// @fnv 0x00544c60
int TESObjectCELL::GetCellGridY()
{
    ExteriorCellData* data = ((::ExteriorCellData *)(reinterpret_cast<::FUN_005445d0_shell *>(this)->FUN_005445d0()));
    if (data)
        return data->y;
    return 0;
}

// @fnv 0x005445d0
void* FUN_005445d0_shell::FUN_005445d0()
{
    if (IsCellInterior())
        return 0;
    return cellData;
}

struct FUN_00544600_shell : public TESObjectCELL
{
    void* FUN_00544600();
};

// @fnv 0x00544600
void* FUN_00544600_shell::FUN_00544600()
{
    if (!IsCellInterior())
        return 0;
    return cellData;
}

struct FUN_00544630_shell : public TESObjectCELL
{
    void ResetCellData();
};


struct InteriorData
{
    char pad[0x2c];
    InteriorData();
};

class PathingActorData
{
  public:
    char pad[0xc];
    PathingActorData();
};

// @fnv 0x00544630
void FUN_00544630_shell::ResetCellData()
{
    if (cellData)
    {
        if (IsCellInterior())
            delete (InteriorData*)cellData;
        else
            delete (PathingActorData*)cellData;
        cellData = 0;
    }

    if (IsCellInterior())
        cellData = new InteriorData();
    else
        cellData = new PathingActorData();
}

// @fnv 0x00544750
NiNode* GetCellNode(TESObjectCELL* pThis)
{
    InteriorCellData* pData = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((pThis))->FUN_00544600()));
    if (pData)
    {
        if (pThis->FUN_00558b80(1) && pThis->GetLightingTemplate())
        {
            return ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((NiAVObject*)pThis->GetLightingTemplate())))->FUN_009611e0()));
        }
        else
        {
            return *(NiNode**)pData;
        }
    }
    return 0;
}

class BGSTerrainManager
{
  public:
    unsigned int GetMinLevel();
};

// Returns the interior cell's minimum level from the terrain manager if available, otherwise from the interior data, or 0 if there is no interior data.
// @fnv 0x00544830
unsigned int GetCellMinLevel(TESObjectCELL* apCell)
{
    InteriorCellData* interiorData = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((apCell))->FUN_00544600()));
    if (interiorData)
    {
        if (apCell->FUN_00558b80(2) && apCell->GetLightingTemplate())
        {
            return ((BGSTerrainManager*)apCell->GetLightingTemplate())->GetMinLevel();
        }
        else
        {
            return interiorData->unk04;
        }
    }
    return 0;
}

struct NiStream;
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};
struct FUN_00544890_shell : public TESObjectCELL
{
    void FUN_00544890(NiColor*);
};

unsigned int GetCellMinLevel(TESObjectCELL* thisPtr);

// Reads a packed color from the cell via GetCellMinLevel and writes its red, green and blue bytes into acolColor as normalized floats.
// @fnv 0x00544890
void FUN_00544890_shell::FUN_00544890(NiColor* acolColor)
{
    unsigned int iColor = GetCellMinLevel(this);
    acolColor->r = (unsigned char)(iColor & 0xFF) / 255.0;
    acolColor->g = (unsigned char)(((unsigned short)iColor >> 8) & 0xFF) / 255.0;
    acolColor->b = (unsigned char)((iColor >> 16) & 0xFF) / 255.0;
}

namespace fnv_00544910 {
struct InteriorData
{
    void Endian();
    unsigned int m_uiAmbientColor;
    unsigned int m_uiDirectionalColor;
    unsigned int m_uiFogColor;
    float m_fFogNear;
    float m_fFogFar;
    unsigned int m_uiDirectionalRotationXY;
    unsigned int m_uiDirectionalRotationZ;
    float m_fDirectionalFade;
    float m_fFogClipDistance;
    float m_fFogPower;
    unsigned int m_uiTrailingValue;
};
struct FUN_00544910_shell : public TESObjectCELL
{
    unsigned int FUN_00544910();
};

struct BGSMessageInitAccess
{
  public:
};

// @fnv 0x00544910
unsigned int FUN_00544910_shell::FUN_00544910()
{
    InteriorData* pdata = (InteriorData*)((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600()));
    if (pdata)
    {
        if (FUN_00558b80(0x20) && GetLightingTemplate())
        {
            return reinterpret_cast<::BGSMessageInitAccess *>((((BGSMessageInitAccess*)GetLightingTemplate())))->GetIconFormID();
        }
        else
        {
            return pdata->m_uiDirectionalRotationXY;
        }
    }
    return 0;
}
}  // namespace fnv_00544910

namespace fnv_00544970 {
struct InteriorData
{
    void Endian();
    unsigned int m_uiAmbientColor;
    unsigned int m_uiDirectionalColor;
    unsigned int m_uiFogColor;
    float m_fFogNear;
    float m_fFogFar;
    unsigned int m_uiDirectionalRotationXY;
    unsigned int m_uiDirectionalRotationZ;
    float m_fDirectionalFade;
    float m_fFogClipDistance;
    float m_fFogPower;
    unsigned int m_uiTrailingValue;
};
struct FUN_00544970_shell : public TESObjectCELL
{
    unsigned int FUN_00544970();
};

class Script
{
  public:
    char* GetData();
};

// @fnv 0x00544970
unsigned int FUN_00544970_shell::FUN_00544970()
{
    InteriorData* pdata = (InteriorData*)((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600()));
    if (pdata)
    {
        if (FUN_00558b80(0x20) && GetLightingTemplate())
        {
            return (unsigned int)((Script*)GetLightingTemplate())->GetData();
        }
        return pdata->m_uiDirectionalRotationZ;
    }
    return 0;
}
}  // namespace fnv_00544970


// @fnv 0x005449d0
int FUN_005449d0(TESObjectCELL* self)
{
    InteriorCellData* data = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((self))->FUN_00544600()));
    if (data)
    {
        if (self->FUN_00558b80(4) && self->GetLightingTemplate())
        {
            return ((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((self->GetLightingTemplate()))->FUN_007af430()));
        }
        return data->unk08;
    }
    return 0;
}

namespace fnv_00544a30 {
struct NiStream;
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};
struct FUN_00544a30_shell : public TESObjectCELL
{
    void FUN_00544a30(NiColor*);
};

unsigned int FUN_005449d0(void* pThis);

// Reads a packed color from the cell via FUN_005449d0 and writes its red, green and blue bytes into acolColor as floats scaled by 1/255.
// @fnv 0x00544a30
void FUN_00544a30_shell::FUN_00544a30(NiColor* acolColor)
{
    unsigned int iColor = FUN_005449d0(this);
    acolColor->r = (unsigned char)(iColor & 0xFF) / 255.0;
    acolColor->g = (unsigned char)(((unsigned short)iColor >> 8) & 0xFF) / 255.0;
    acolColor->b = (unsigned char)((iColor >> 16) & 0xFF) / 255.0;
}
}  // namespace fnv_00544a30

class TESGlobalValueReader
{
  public:
};

// @fnv 0x00544ab0
float FUN_00544ab0(TESObjectCELL* apCell)
{
    InteriorCellData* data = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((apCell))->FUN_00544600()));
    if (data)
    {
        if (apCell->FUN_00558b80(8) && apCell->GetLightingTemplate())
        {
            return reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)apCell->GetLightingTemplate())))->FUN_00526ac0();
        }
        return data->unk0c;
    }
    return 0.0f;
}


// @fnv 0x00544b10
float FUN_00544b10(TESObjectCELL* pthis)
{
    InteriorCellData* data = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((pthis))->FUN_00544600()));
    if (data)
    {
        if (pthis->FUN_00558b80(0x10) && pthis->GetLightingTemplate())
        {
            return reinterpret_cast<::FUN_00526ae0_class *>((pthis->GetLightingTemplate()))->FUN_00526ae0();
        }
        return data->unk10;
    }
    return 0.0f;
}

struct TESObjectREFR_GetScale : TESObjectREFR
{
};

// @fnv 0x00544b70
float FUN_00544b70(TESObjectCELL* cell)
{
    InteriorCellData* interior = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((cell))->FUN_00544600()));
    if (interior)
    {
        if (cell->FUN_00558b80(0x100) && cell->GetLightingTemplate())
            return reinterpret_cast<::TESObjectREFR *>((reinterpret_cast<TESObjectREFR_GetScale*>(cell->GetLightingTemplate())))->GetScale();
        return *reinterpret_cast<float*>(reinterpret_cast<char*>(interior) + 0x24);
    }
    return 1.0f;
}

struct FUN_005452c0_shell : public TESObjectCELL
{
    void RegisterReferenceInCell(TESObjectREFR*);
};

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
};

template <class K, class V> class NiTPointerMap
{
  public:
    void SetAt(K, V);
};

template <> class BSSimpleList<char const*>
{
  public:
    void AddHead(char const*&);
};

extern double DAT_0102ed48;

struct VClass0c
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual unsigned int vfn_0c();
};

struct VClass1d0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual VClass0c* vfn_1d0();
};

// @fnv 0x005452c0
void FUN_005452c0_shell::RegisterReferenceInCell(TESObjectREFR* apRef)
{
    if (this->pRenderData == 0 || !apRef ||
        !reinterpret_cast<VClass1d0*>(apRef)->vfn_1d0())
        return;

    reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(
        (char*)this->pRenderData + 0xc)))->FUN_00844700(reinterpret_cast<std::uintptr_t>(apRef), reinterpret_cast<VClass1d0*>(apRef)->vfn_1d0()->vfn_0c());

    if (reinterpret_cast<::fnv_0050ebf0::FUN_0050ebf0_shell *>((((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))))->FUN_0050ebf0() > DAT_0102ed48)
    {
        reinterpret_cast<BSSimpleList<char const*>*>((char*)this->pRenderData +
                                                     4)
            ->AddHead(*(char const**)&apRef);
    }
}

// Returns a pointer to the object at offset 0x5c of the field at param_1+0xc4, or null if that field is zero.
// @fnv 0x00545710
void* FUN_00545710(std::intptr_t param_1)
{
    if (*(int*)(param_1 + 0xc4) != 0)
        return (void*)(*(char**)(param_1 + 0xc4) + 0x5c);
    return 0;
}

struct FUN_00545cb0_shell : public TESObjectCELL
{
    NiNode* FUN_00545cb0();
};
// @fnv 0x00456fc0
NiAVObject* TESObjectCELL::GetCellChildAt(int index)
{
    NiNode* node = reinterpret_cast<::FUN_00545cb0_shell *>(this)->FUN_00545cb0();
    return node ? node->GetAt(index) : 0;
}

template <class T> class BSStringT
{
  public:
    operator const char*() const;
};

// @fnv 0x00545cb0
NiNode* FUN_00545cb0_shell::FUN_00545cb0()
{
    NiNode* pNode = 0;
    if (((BSStringT<char>*)this->pRenderData) != 0)
    {
        pNode = reinterpret_cast<NiNode*>(const_cast<char*>(
            static_cast<const char*>(*((BSStringT<char>*)this->pRenderData))));
    }
    return pNode;
}

struct FUN_00546780_shell : public NiAVObject
{
    void FUN_00546780(bool);
};

struct TaskQueueInterface
{
  public:
    static ::TaskQueueInterface *GetSingleton();
public:
    void QueueActorDisarm(bool);
public:
    void SetTaskFlag2000(bool);
public:
    void SetTaskFlag_005468b0(bool);
};

class ImageSpaceModifierInstanceDOF
{
  public:
};

struct NiAVObject_CreateBoundIfNone_Accessor : public NiAVObject
{
};

// @fnv 0x00546780
void FUN_00546780_shell::FUN_00546780(bool abVal)
{
    reinterpret_cast<::FUN_0043b370_cls *>((reinterpret_cast<TaskQueueInterface*>(this)))->FUN_0043b370(abVal, 0x800);
    reinterpret_cast<::NiAVObject *>((reinterpret_cast<NiAVObject_CreateBoundIfNone_Accessor*>(this)))->EnsureWorldBound();
    if (abVal)
    {
        reinterpret_cast<::FUN_0063f790_shell *>(((*reinterpret_cast<ImageSpaceModifierInstanceDOF**>(reinterpret_cast<char*>(this) + 0x20))))->FUN_0063f790(1.0f);
    }
}

struct NiBoundH
{
    void NiBound();
};
struct S
{
    S* InitBound(unsigned short a, unsigned short b);
};
// @fnv 0x00546890
S* S::InitBound(unsigned short a, unsigned short b)
{
    ::FUN_006240d0((void *)(((NiBoundH*)this)));
    return this;
}

namespace fnv_005468f0 {

// @fnv 0x005468f0
bool __cdecl FUN_005468f0(int aiNode)
{
    return ((*reinterpret_cast<unsigned int *>(&::DAT_011ca08c)) & (1 << aiNode)) ? true : false;
}
}  // namespace fnv_005468f0

namespace fnv_00546910 {
struct NiNodeX;
struct NiPointerX
{
    NiPointerX& operator=(NiNodeX*);
};
struct S
{
    char pad[0x4c];
    NiPointerX p;
    void FUN_00546910(NiNodeX* n);
};
// @fnv 0x00546910
void S::FUN_00546910(NiNodeX* apNode)
{
    p = apNode;
}
}  // namespace fnv_00546910

namespace fnv_00546930 {
template <typename T> struct BSStringT
{
    operator const char*() const;
};

struct FUN_00546930_Class
{
    char pad[0x4c];
    BSStringT<char> str;
};

// @fnv 0x00546930
const char* FUN_00546930(FUN_00546930_Class* pThis)
{
    return pThis->str;
}
}  // namespace fnv_00546930

struct TESGlobal;
struct FUN_00546aa0_shell : public TESObjectCELL
{
    TESGlobal* FUN_00546aa0();
};


// @fnv 0x00546aa0
TESGlobal* FUN_00546aa0_shell::FUN_00546aa0()
{
    return reinterpret_cast<::FUN_00418690_shell *>((((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESDataHandler*)this)))->GetExtraDataList()))))->FUN_00418690();
}

struct FUN_00546af0_shell : public TESObjectCELL
{
    unsigned int FUN_00546af0();
};


// @fnv 0x00546af0
unsigned int FUN_00546af0_shell::FUN_00546af0()
{
    return ((unsigned int)(reinterpret_cast<::FUN_00421820_Class *>((((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->GetExtraDataList()))))->FUN_00421820()));
}

class BGSAcousticSpace;
struct FUN_00547590_shell : public TESObjectCELL
{
    BGSAcousticSpace* FUN_00547590();
};


// @fnv 0x00547590
BGSAcousticSpace* FUN_00547590_shell::FUN_00547590()
{
    return ((::BGSAcousticSpace *)(std::uintptr_t)(reinterpret_cast<::FUN_0041c160_Class *>((((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESDataHandler*)this)))->GetExtraDataList()))))->FUN_0041c160()));
}

class BGSImpactData;
class TESForm;
struct ImpactSwap
{
    void Save();
    void Load(TESFile*);
    void InitItem(TESForm*);
    bool Compare(ImpactSwap*);
    BGSImpactData* GetSwappedImpactData(int, BGSImpactData*);
    void SetSwappedImpactData(int, BGSImpactData*, BGSImpactData*);
    void RemoveSwappedImpactData(int, BGSImpactData*);
    char* GetAltFootstepMaterialName(int);
    void* __vecDelDtor(unsigned int);
    char m_pData[48];
    char m_acAltFootstepMaterialNames[300];
};
struct FUN_00547610_shell : public TESObjectCELL
{
    ImpactSwap* GetImpactSwap();
};

ImpactSwap* FUN_0041c460(void* pThis);

// @fnv 0x00547610
ImpactSwap* FUN_00547610_shell::GetImpactSwap()
{
    ImpactSwap* pswap = 0;
    if (IsCellInterior())
    {
        pswap = FUN_0041c460(((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESDataHandler*)this)))->GetExtraDataList())));
    }
    return pswap;
}

struct BGSLoadFormBuffer;
struct BGSPlaceableWater;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
class NiTexture;
struct SpellItem;
class TESBoundObject;
class TESForm;
struct TESWaterForm;
struct WaterShaderSettings;
struct blob8
{
    char b[8];
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
class TESFullName : public BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
public:
    void SetFullName(const char *);
};
struct TESAttackDamageForm : public BaseFormComponent
{
    virtual unsigned short GetAttackDamage();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned short GetAttackDamage(TESForm*);
    void SetAttackDamage(unsigned short);
    void* __vecDelDtor(unsigned int);
    unsigned short m_usAttackDamage;
    char _pad_6[2];
};
struct FUN_00547770_shell : public TESObjectCELL
{
    TESWaterForm* FUN_00547770();
};

class TESSound;
class TESSound;
class EffectSetting
{
  public:
    TESSound* GetCastSound();
public:
    ::TESSound *GetHitSound();
};



// @fnv 0x00548720
bool FUN_00548720(void* pThis)
{
    return ((int)(reinterpret_cast<::FUN_00450fd0_class *>((pThis))->GetByteAtOffset38())) == 2;
}

namespace fnv_005495d0 {
struct FUN_005495d0_shell : public TESObjectCELL
{
    NiNode* FUN_005495d0();
};

template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x005495d0
NiNode* FUN_005495d0_shell::FUN_005495d0()
{
    return (NiNode*)this->pCellNode;
}
}  // namespace fnv_005495d0


// Returns true only when all four checks on pThis return false.
// @fnv 0x00549630
bool FUN_00549630(void* pThis)
{
    return !reinterpret_cast<::FUN_0050d1d0_class *>((pThis))->IsFlag8Set() && !reinterpret_cast<::FUN_0050d1f0_Class *>((pThis))->FUN_0050d1f0() && !reinterpret_cast<::FUN_0050d210_Class *>((pThis))->IsFlag80Set() && !reinterpret_cast<::FUN_0050d230_class *>((pThis))->FUN_0050d230();
}

class BSXFlags
{
  public:
};

// @fnv 0x00549690
bool HasFlagOne(const BSXFlags* pThis)
{
    return reinterpret_cast<::FUN_00448a60_struct *>((void *)(pThis))->GetMaskedValue(1) != 0;
}

struct FUN_0054a050_shell : public TESObjectCELL
{
    NiNode* FUN_0054a050();
};

// @fnv 0x0054a050
NiNode* FUN_0054a050_shell::FUN_0054a050()
{
    return (NiNode*)GetCellChildAt(0);
}

// @fnv 0x0054aa60
NiAVObject* FUN_0054aa60(TESObjectCELL* apCell)
{
    return apCell->GetCellChildAt(3);
}


struct FUN_0054ad60_Arg
{
    int val;
};

struct FUN_0054ad60_This
{
    int count;
    void* hSemaphore;
    int maxCount;
};

// Stores the initial count and max count (count + 1) and creates a semaphore handle from them.
// @fnv 0x0054ad60
FUN_0054ad60_This* FUN_0054ad60(FUN_0054ad60_This* pThis, FUN_0054ad60_Arg aInitialCount)
{
    pThis->count = aInitialCount.val;
    pThis->maxCount = aInitialCount.val + 1;
    pThis->hSemaphore = CreateSemaphoreA(0, pThis->count, pThis->maxCount, 0);
    return pThis;
}

class TESObjectSTAT;
struct RefStub
{
    void* FUN_00569080();
};
struct NodeStub
{
};
struct ListStub
{
    void AddHead(RefStub**);
};
struct FUN_0054b8c0_shell : public TESObjectCELL
{
    void AddStaticRefsToList(BSSimpleList<const char*>* list);
};
struct FUN_0054b950_shell : public TESObjectCELL
{
    void FUN_0054b950(bool);
};

class TESForm;
class TESObjectCELL;
struct BGSSaveLoadGame
{
  public:
public:
    void FormReconstructionMap(::TESObjectCELL *);
public:
    void HasFormChanges(::TESForm *);
};

struct RefObj
{
    void FUN_00579ac0(bool);
};



struct FUN_0054de10_shell : public TESObjectCELL
{
    void FUN_0054de10(TESWorldSpace*);
};

// @fnv 0x0054de10
void FUN_0054de10_shell::FUN_0054de10(TESWorldSpace* apWorld)
{
    if (!IsCellInterior())
        worldSpace = apWorld;
}

// @fnv 0x0054de40
void* FUN_0054de40(TESObjectCELL* apCell)
{
    void* result = 0;
    if (apCell->IsCellInterior())
    {
        result = apCell->worldSpace;
    }
    return result;
}

namespace fnv_0054deb0 {
struct InteriorData
{
    void Endian();
    unsigned int m_uiAmbientColor;
    unsigned int m_uiDirectionalColor;
    unsigned int m_uiFogColor;
    float m_fFogNear;
    float m_fFogFar;
    unsigned int m_uiDirectionalRotationXY;
    unsigned int m_uiDirectionalRotationZ;
    float m_fDirectionalFade;
    float m_fFogClipDistance;
    float m_fFogPower;
    unsigned int m_uiTrailingValue;
};
struct FUN_0054deb0_shell : public TESObjectCELL
{
    unsigned int FUN_0054deb0();
};

// @fnv 0x0054deb0
unsigned int FUN_0054deb0_shell::FUN_0054deb0()
{
    unsigned int iretval = 0;
    if (IsCellInterior())
    {
        InteriorData* pdata = reinterpret_cast<InteriorData*>(((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600())));
        if (pdata)
        {
            iretval = pdata->m_uiTrailingValue;
        }
    }
    return iretval;
}
}  // namespace fnv_0054deb0

namespace fnv_0054def0 {
struct ICD
{
    char pad[0x28];
    int v;
};
struct S
{
    void SetInteriorDataValue(std::intptr_t a);
};
// @fnv 0x0054def0
void S::SetInteriorDataValue(std::intptr_t aiValue)
{
    if (reinterpret_cast<::TESObjectCELL *>((void *)this)->IsCellInterior())
    {
        ICD* d = ((::fnv_0054def0::ICD *)(reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600()));
        if (d)
            d->v = aiValue;
    }
}
}  // namespace fnv_0054def0

struct FUN_00550890_shell : public TESDataHandler
{
    void SetBoolAt61a(bool);
};

// @fnv 0x00550890
void FUN_00550890_shell::SetBoolAt61a(bool abNewbool)
{
    *((bool*)((char*)this + 0x61a)) = abNewbool;
}

struct FUN_00551420_shell : public TESObjectCELL
{
    bool FUN_00551420();
};

// @fnv 0x00551420
bool FUN_00551420_shell::FUN_00551420()
{
    if (this->field24 & 0x10)
        return true;
    else
        return false;
}

namespace fnv_00552470 {
struct S
{
    void FUN_00552470();
};
// @fnv 0x00552470
void S::FUN_00552470()
{
    reinterpret_cast<::FUN_00456630_Class *>(this)->FUN_00456630(0x100000);
}
}  // namespace fnv_00552470

// @fnv 0x00552490
bool FUN_00552490(bool* pThis)
{
    return pThis[0x41];
}

struct FUN_00552900_shell : public TESObjectCELL
{
    void FUN_00552900(bool);
};

class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
public:
    bool GetInitialized() const;
public:
    bool GetDisabled() const;
public:
    void SetInitializationState(bool);
public:
    void LoadGame(void *);
public:
    ::TESFile *GetFile(int);
};
// Returns a TESWaterForm from the data handler, else from the world space, else the global default, and substitutes the cast sound if the cell check passes.
// @fnv 0x00547770
TESWaterForm* FUN_00547770_shell::FUN_00547770()
{
    TESWaterForm* pretwater = reinterpret_cast<::FUN_0041e130_shell *>((((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->GetExtraDataList()))))->FUN_0041e130();
    if (!pretwater)
    {
        TESWorldSpace* pworld = GetParentWorldSpace();
        if (pworld)
            pretwater = FUN_00586070(pworld);
    }
    if (!pretwater)
        pretwater = ::DAT_011ca53c;
    if (pretwater)
    {
        if (reinterpret_cast<::TESForm *>((this))->GetInitialized())
        {
            if (reinterpret_cast<EffectSetting*>(pretwater)->GetCastSound())
                pretwater =
                    reinterpret_cast<TESWaterForm*>(reinterpret_cast<EffectSetting*>(pretwater)->GetCastSound());
        }
    }
    return pretwater;
}

class Pathing
{
  public:
};

namespace {
struct VCallC8
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
    virtual void v50(bool);
};
}

// @fnv 0x00552900
void FUN_00552900_shell::FUN_00552900(bool abAltered)
{
    reinterpret_cast<::fnv_00484730::FUN_00484730_shell *>((reinterpret_cast<TESForm*>(this)))->FUN_00484730(abAltered);
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(reinterpret_cast<TESForm*>(this)))->FUN_004077c0() && reinterpret_cast<::FUN_00460340_shell *>((reinterpret_cast<Pathing*>(this)))->FUN_00460340() &&
        !IsCellInterior())
    {
        TESWorldSpace* pWorld = GetParentWorldSpace();
        if (pWorld)
        {
            reinterpret_cast<VCallC8*>(pWorld)->v50(true);
        }
    }
}

class TESBoundObject;
struct ScriptLocals
{
    TESBoundObject* GetLocalData();
};
class Script
{
  public:
    void GetLocalData();
};
struct FUN_00c93820_stub
{
};
struct FUN_006299c0_stub
{
};
struct FUN_005533f0_cls
{
    char pad[0x70];
    FUN_006299c0_stub sub;
    void FUN_005533f0(std::uintptr_t a);
};
// @fnv 0x005533f0
void FUN_005533f0_cls::FUN_005533f0(std::uintptr_t uiValue)
{
    TESBoundObject* p = ((ScriptLocals*)this)->GetLocalData();
    if (p)
    {
        ((Script*)this)->GetLocalData();
        reinterpret_cast<::fnv_00c93820::hkpWorldC938 *>((((FUN_00c93820_stub*)p)))->FUN_00c93820((::fnv_00c93820::hkpEntityListenerC938 *)(uiValue));
        ((Script*)this)->GetLocalData();
    }
    reinterpret_cast<::FUN_006299c0_cls *>(&(sub))->FUN_006299c0((std::intptr_t)(&uiValue));
}

namespace fnv_00553440 {
struct TESBoundObjectX;
struct ScriptLocalsX
{
};
struct ScriptX
{
};
struct ObjX
{
};
struct S
{
    void FUN_00553440(std::intptr_t a);
};
// @fnv 0x00553440
void S::FUN_00553440(std::intptr_t aiArg)
{
    TESBoundObjectX* o = ((::fnv_00553440::TESBoundObjectX *)(reinterpret_cast<::ScriptLocals *>((((ScriptLocalsX*)this)))->GetLocalData()));
    if (o)
    {
        reinterpret_cast<::Script *>((((ScriptX*)this)))->GetLocalData();
        reinterpret_cast<::fnv_00c93a20::hkpWorldXc93a20 *>((((ObjX*)o)))->FUN_00c93a20((::fnv_00c93a20::hkpEntityListenerXc93a20 *)(aiArg));
        reinterpret_cast<::Script *>((((ScriptX*)this)))->GetLocalData();
    }
}
}  // namespace fnv_00553440

namespace fnv_00553480 {
class TESBoundObject;
struct ScriptLocals
{
};
class Script
{
};
struct FUN_005533f0_stub
{
};
struct FUN_00c93860_stub
{
};
struct FUN_00553480_cls
{
    char pad[0x20];
    char* field20;
    void FUN_00553480(char* a);
};
// @fnv 0x00553480
void FUN_00553480_cls::FUN_00553480(char* a)
{
    reinterpret_cast<::FUN_005533f0_cls *>((((FUN_005533f0_stub*)this)))->FUN_005533f0((std::uintptr_t)(a));
    TESBoundObject* p = ((::fnv_00553480::TESBoundObject *)(reinterpret_cast<::ScriptLocals *>((((ScriptLocals*)this)))->GetLocalData()));
    if (p)
    {
        reinterpret_cast<::Script *>((((Script*)this)))->GetLocalData();
        reinterpret_cast<::fnv_00c93860::hkpWorldXc93860 *>((((FUN_00c93860_stub*)p)))->FUN_00c93860((::fnv_00c93860::hkpEntityListenerXc93860 *)(char *)(a ? a + 0x14 : 0));
        reinterpret_cast<::Script *>((((Script*)this)))->GetLocalData();
    }
    field20 = a;
}
}  // namespace fnv_00553480

struct _Helper_005534f0
{
    char _pad[0x28];
    void* m_kListener;
    void FUN_005534f0(void* apListener);
};

// @fnv 0x005534f0
void _Helper_005534f0::FUN_005534f0(void* apListener)
{
    reinterpret_cast<::FUN_005533f0_cls *>(this)->FUN_005533f0((std::uintptr_t)(apListener));
    m_kListener = apListener;
}

void FUN_00553540(void* pThis);

// @fnv 0x00553520
void FUN_00553520(void* pThis)
{
    FUN_00553540(pThis);
}

struct M1
{
    int x;
    ~M1();
};
struct B1
{
    virtual ~B1();
    char pad[0x54];
};
struct FUN_00553540 : B1
{
    M1 m58;
    M1 m5c;
    char pad2[0xc];
    M1 m6c;
    ~FUN_00553540();
};
// Destructor for FUN_00553540; destroys the M1 members m58, m5c and m6c.
// @fnv 0x00553540
FUN_00553540::~FUN_00553540()
{}

struct NiStream;
struct NiMemObject
{
    char _pad_0[1];
};
using ::AutoMemContext;
class NiTransform
{
  public:
    void ResetToIdentity();
    void Invert(NiTransform*);
    void CalculateInverse(NiTransform*);
    bool IsIdentity();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char m_kOrientation[48];
    char m_kTranslation[12];
    float m_fScale;
};
struct FUN_005535f0_shell : public TESObjectCELL
{
    void FUN_005535f0();
};

namespace Local {
enum MEM_CONTEXT
{
};

using ::AutoMemContext;

struct ThreeByThreeMatrix
{
    float d[9];
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class NiTransform
{
  public:
    NiTransform();
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
}

class bhkWorld;
class NiQuaternion
{
  public:
    static const NiQuaternion IDENTITY;
};

struct CellMopp
{
};



// @fnv 0x005535f0
void FUN_005535f0_shell::FUN_005535f0()
{
    bhkWorld* pw = ((::bhkWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((this))->FUN_004543c0()));
    int ix = GetCellGridX();
    int iy = GetCellGridY();
    CellMopp* pcm = ::GetCellMopp((char *)(::TESObjectCELL *)(this));
    if (pw && pcm)
    {
        Local::AutoMemContext tempMemContext(
            (Local::MEM_CONTEXT)16, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp",
            15014);
        Local::NiTransform org;
        org.m_fScale = 1.0f;
        org.m_kOrientation = (*reinterpret_cast<::Local::ThreeByThreeMatrix *>(&::DAT_011a9448));
        org.m_kTranslation.x = (float)((ix << 12) + DAT_01016968);
        org.m_kTranslation.y = (float)((iy << 12) + DAT_01016968);
        org.m_kTranslation.z = 0.0f;
        reinterpret_cast<::FUN_00622590_Owner *>((pcm))->PlaceGridObjects((::FUN_0056d2c0_Class *)(pw), (const ::NiPoint3 *)&(org.m_kTranslation), (std::intptr_t)&(NiQuaternion::IDENTITY));
    }
}

namespace fnv_00553820 {
int _FNV_GetFormType(void*);

class NavMeshVertexMap
{
  public:
};

template <class K, class V> class NiTPointerMap
{
  public:
    void GetNext(void*&, K&, V&);
};

struct FUN_00553820_Obj
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
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool v100();
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
};

// @fnv 0x00553820
void FUN_00553820(TESObjectCELL* pThis)
{
    if (::FUN_00450ff0(pThis) && pThis->pRenderData != 0)
    {
        void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((NavMeshVertexMap*)((char*)pThis->pRenderData + 0xc))))->GetFirstPos();
        while (pos)
        {
            FUN_00553820_Obj* key = 0;
            void* val = 0;
            reinterpret_cast<::C6b7f20_Map *>((((NiTPointerMap<unsigned int, void*>*)((char*)pThis->pRenderData + 0xc))))->FUN_006b7f20((::C6b7f20_Node **)&(pos), (unsigned int *)&((unsigned int&)key), (void **)&(val));
            if (!key->v100() && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((key))->FUN_007af430())) && _FNV_GetFormType(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((key))->FUN_007af430()))) != 0x25)
            {
                key->v1e0();
            }
        }
    }
}
}  // namespace fnv_00553820

// Returns pThis[0x68] when bit 2 of the field at offset 0x48 is set, otherwise returns 0.
// @fnv 0x00553b60
char FUN_00553b60(char* pThis)
{
    return (*(unsigned int*)(pThis + 0x48) & 2) ? pThis[0x68] : 0;
}

struct SoundDataDummy
{
    int f0;
    unsigned int f4;
    char pad[0x24 - 8];
};

struct TESSound_caller
{
};

struct FUN_00553bb0_caller
{
    char pad[0x1c];
    TESSound_caller* sound;
    bool FUN_00553bb0();
};

// Returns true when sound is non-null and the flag bit 2 is set in the value returned by sound->CopyBig().
// @fnv 0x00553bb0
bool FUN_00553bb0_caller::FUN_00553bb0()
{
    return (sound && ((*(::SoundDataDummy *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).f4 & 2)) ? true : false;
}

class Actor;
class SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
class NiQuaternion;
class TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct FUN_00555a50_shell : public TESObjectCELL
{
    void FUN_00555a50(BGSLoadFormBuffer*);
};

struct MagicProjectile
{
    void Process(BGSLoadFormBuffer*);
};
struct BGSChangeFlags_s
{
    char b[4];
};
struct FUN_00555be0_stub : public TESObjectCELL
{
    void FUN_00555be0();
};
struct TESObjectCELL_s
{
    void SetDetachTime(unsigned int, bool);
};
// @fnv 0x00555a50
void FUN_00555a50_shell::FUN_00555a50(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>((((MagicProjectile*)this)))->FUN_004534f0((std::uintptr_t)(apLoadGameBuffer));
    this->ucCellFlags25 = 0;
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((((BGSChangeFlags_s*)&ResultSlot(apLoadGameBuffer->GetOldChangeFlags()))))->FUN_004280f0(0x80000000))
        ((FUN_00555be0_stub*)this)->FUN_00555be0();
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((((BGSChangeFlags_s*)&ResultSlot(apLoadGameBuffer->GetOldChangeFlags()))))->FUN_004280f0(0x40000000))
        ((TESObjectCELL_s*)this)->SetDetachTime(0, false);
}

struct TESObjectREFR_GetFlags_Helper : public TESObjectREFR
{
    unsigned int GetFlags()
    {
        return 0;
    }
};

// @fnv 0x00558200
unsigned int FUN_00558200(char* this_ptr)
{
    return ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_Helper*)(this_ptr + 0x38))))->GetName()));
}

class NavMeshTriangle
{
  public:
    void Clear();
    bool HasEdgeExtraInfo();
    bool IsPreferred();
    void TogglePreferred();
    bool IsWaterTriangle();
    void ToggleWater();
    bool IsNoLargeCreature();
    void ToggleNoLargeCreature();
    void GetVerts(unsigned short*, unsigned short*, unsigned short*);
    void GetTris(unsigned short*, unsigned short*, unsigned short*);
    void SetVerts(unsigned short, unsigned short, unsigned short);
    void SetTris(unsigned short, unsigned short, unsigned short);
    void SetFlag(int);
    unsigned int GetTriangleFlags();
    void SetTriangleFlags(unsigned int);
    unsigned short GetVert(unsigned int);
    void SetVert(unsigned int, unsigned short);
    unsigned short GetTri(unsigned int);
    void SetTri(unsigned int, unsigned short);
    bool EdgeHasExtraInfo(int);
    unsigned short GetEdgeExtraInfoValue(int);
    void SetEdgeExtraInfo(int, unsigned short);
    void ClearEdgeExtraInfo(int);
    bool HasDoorPortal();
    bool IsEdgeConnected(int);
    unsigned short GetTriOrExtraInfo(int);
    void SetTriOrExtraInfo(int, unsigned short);
    unsigned short GetObjectCount();
    void SetObjectCount(unsigned short);
    void ClearObjectCount();
    static bool HasCover(unsigned int);
    bool HasCover();
    bool HasCoverEdge0();
    bool HasCoverEdge1();
    static bool HasCoverOrWallFlags(unsigned int);
    bool HasCoverOrWallFlags();
    bool HasCoverOrWallEdge0();
    bool HasCoverOrWallEdge1();
    bool IsWall(unsigned short);
    bool IsEdgeOpen(unsigned short);
    unsigned short GetEdgeCover(unsigned short);
    bool GetEdgeSides(unsigned short, bool*, bool*);
    static void GetEdgeCoverData(unsigned int, unsigned short, unsigned short*, bool*, bool*);
    void GetEdgeCoverData(unsigned short, unsigned short*, bool*, bool*);
    void ClearCover();
    static void SetEdgeCover(unsigned int*, unsigned short, unsigned short, bool, bool);
    void SetEdgeCover(unsigned short, unsigned short, bool, bool);
    int Rotate(int);
    bool ConvertCoverEdgeFormat();
    static unsigned int GetCoverLevel(float, bool, bool);
    static float GetCoverHeight(unsigned int);
    void Endian();
    char Vertices[6];
    char Triangles[6];
    unsigned int m_uiTriangleFlags;
};
struct FUN_005582d0_shell : public NavMeshTriangle
{
    unsigned short FUN_005582d0(unsigned int);
};

// @fnv 0x005582d0
unsigned short FUN_005582d0_shell::FUN_005582d0(unsigned int aiVertIndex)
{
    return ((unsigned short*)Vertices)[aiVertIndex];
}

struct NiNode_00558310 : NiNode
{
};

// @fnv 0x00558310
NiAVObject* FUN_00558310(NiNode_00558310* pThis)
{
    return ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((pThis))->FUN_0045bc00(0)));
}

struct BGSLightingTemplate;
struct FUN_00558b40_shell : public TESObjectCELL
{
    BGSLightingTemplate* GetLightingTemplate();
};

// @fnv 0x00558b40
BGSLightingTemplate* FUN_00558b40_shell::GetLightingTemplate()
{
    return this->pLightingTemplate;
}

namespace fnv_00558b60 {
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
class TESBoundObject;
class TESForm;
struct blob8
{
    char b[8];
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_00558b60_shell : public TESObjectCELL
{
    void FUN_00558b60(BGSLightingTemplate*);
};

// @fnv 0x00558b60
void FUN_00558b60_shell::FUN_00558b60(BGSLightingTemplate* apTemplate)
{
    this->pLightingTemplate = reinterpret_cast<::BGSLightingTemplate*>(apTemplate);
}
}  // namespace fnv_00558b60

struct FUN_00558b80_shell : public TESObjectCELL
{
    bool FUN_00558b80(unsigned int);
};
// Returns the interior cell's clip distance, or a value from GetLightingTemplate() when flag 0x80 is set; returns 0.0f if there is no interior data.
// @fnv 0x00544bd0
float TESObjectCELL::GetInteriorLightValue()
{
    InteriorCellData* data = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600()));
    if (data)
    {
        if (reinterpret_cast<::FUN_00558b80_shell *>(this)->FUN_00558b80(0x80) && ((::CellLightingTemplate *)(reinterpret_cast<::FUN_00558b40_shell *>(this)->GetLightingTemplate())))
            return reinterpret_cast<::BGSImpactData *>((((::CellLightingTemplate *)(reinterpret_cast<::FUN_00558b40_shell *>(this)->GetLightingTemplate()))))->FUN_009a9350();
        return data->clipDist;
    }
    return 0.0f;
}

// @fnv 0x00558b80
bool FUN_00558b80_shell::FUN_00558b80(unsigned int aiFlag)
{
    return (this->unknownDC & aiFlag) ? true : false;
}

namespace fnv_00558c90 {
struct FUN_00558c90_shell : public TESObjectCELL
{
    void FUN_00558c90();
};

int _FNV_GetFormType(void* pThis);

class TESForm
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_3a();
    virtual void vfn_3b();
    virtual void vfn_3c();
    virtual void vfn_3d();
    virtual void vfn_3e();
    virtual void vfn_3f();
    virtual bool vfn_40();
};

// @fnv 0x00558c90
void FUN_00558c90_shell::FUN_00558c90()
{
    TESForm* pref = 0;
    void* preflist = this->FUN_009604f0();
    while (preflist && *((void **)((void *)(preflist))))
    {
        pref = (TESForm*)*((void **)((void *)(preflist)));
        if (!pref->vfn_40() && _FNV_GetFormType(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pref))->FUN_007af430()))) != 0x1c && reinterpret_cast<::FUN_00549580_shell *>((pref))->FUN_00549580())
        {
            if (reinterpret_cast<::FUN_00545cb0_shell *>((this))->FUN_00545cb0())
            {
                ::FUN_00c6a270((std::intptr_t)((NiAVObject*)reinterpret_cast<::FUN_00545cb0_shell *>((this))->FUN_00545cb0()), true, true, 1);
            }
        }
        preflist = reinterpret_cast<::Callees *>((preflist))->FUN_00726070();
    }
}
}  // namespace fnv_00558c90

namespace fnv_00559490 {
struct S
{
    char pad[0xe];
    unsigned short v;
    void FUN_00559490(unsigned short a);
};
// @fnv 0x00559490
void S::FUN_00559490(unsigned short ausValue)
{
    v = ausValue;
}
}  // namespace fnv_00559490

struct Node
{
    char pad[8];
    int v;
};
struct FUN_005597d0_shell
{
    void FUN_005597d0(int* e);
};
// Gets a Node via FUN_0049fa80, stores the int pointed to by e into its v field, then passes the node to FUN_00559a70.
// @fnv 0x005597d0
void FUN_005597d0_shell::FUN_005597d0(int* piValue)
{
    Node* n = ((::Node *)(reinterpret_cast<::FUN_004705c0_cls *>(this)->FUN_004705c0()));
    n->v = *piValue;
    reinterpret_cast<::FUN_00559a70_Class *>(this)->FUN_00559a70(n);
}

struct FUN_0057c850_item
{
    FUN_0057c850_item* next;
    void* key;
    bool val;
};
struct FUN_0057c850_cls
{
    virtual void v0();
    virtual unsigned int v1(void* key);
    virtual bool v2(void* key, void* other);
    int pad;
    FUN_0057c850_item** table;
    bool FUN_0057c850(void* key, bool* val);
};
// @fnv 0x0057c850
bool FUN_0057c850_cls::FUN_0057c850(void* key, bool* pbVal)
{
    unsigned int uiIndex = v1(key);
    FUN_0057c850_item* pkItem = table[uiIndex];
    while (pkItem)
    {
        if (v2(key, pkItem->key))
        {
            *pbVal = pkItem->val;
            return true;
        }
        pkItem = pkItem->next;
    }
    return false;
}

class ActorCombatGroup;

template <class T> class NiTMallocInterface
{
  public:
    static T* __cdecl Allocate(unsigned short auiCount);
    static void __cdecl Deallocate(T* pArray);
};

struct NiTArray_CombatGroup
{
    void* vtbl;
    ActorCombatGroup** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

// @fnv 0x00600bc0
void CompactArray(NiTArray_CombatGroup* pThis)
{
    if (pThis->m_usESize == pThis->m_usSize)
        return;

    if (pThis->m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < pThis->m_usSize; i++)
        {
            if (pThis->m_pBase[i] != 0)
            {
                if (pThis->m_pBase[j] != pThis->m_pBase[i])
                    pThis->m_pBase[j] = pThis->m_pBase[i];
                j++;
            }
        }
    }

    ActorCombatGroup** pOldBase = pThis->m_pBase;
    pThis->m_usSize = pThis->m_usESize;
    pThis->m_usMaxSize = pThis->m_usSize;

    if (pThis->m_usMaxSize > 0)
    {
        pThis->m_pBase = NiTMallocInterface<ActorCombatGroup*>::Allocate(pThis->m_usMaxSize);
        for (unsigned short i = 0; i < pThis->m_usSize; i++)
        {
            pThis->m_pBase[i] = pOldBase[i];
        }
    }
    else
    {
        pThis->m_pBase = 0;
    }

    ::FUN_004ede70(pOldBase);
}

struct Modifier
{
  public:
};


// @fnv 0x00703980
void FUN_00703980()
{
    if (((::Modifier *)(::fnv_004b7210::FUN_004b7210())) && static_cast<unsigned char>(((char)(reinterpret_cast<::FUN_009373f0_shell *>((((::Modifier *)(::fnv_004b7210::FUN_004b7210()))))->FUN_009373f0()))))
        ::FUN_007160b0((::InterfaceManager *)(::Modifier *)(((::Modifier *)(::fnv_004b7210::FUN_004b7210()))));
}

struct IOManager;
struct NiRenderer
{
  public:
};

void FUN_00c3e310(IOManager*);
void __cdecl FUN_008781e0(int);
void __cdecl FUN_00703980();

// @fnv 0x00878160
void __cdecl FUN_00878160(char* aFreeData, bool abLockRenderer, bool abRunHeapClean, bool abArg4)
{
    FUN_00c3e310(::DAT_01202d98);
    if (abArg4)
    {
        aFreeData[5] = ::fnv_00652160::FUN_00652160();
    }
    else
    {
        aFreeData[5] = abArg4;
    }
    if (abLockRenderer)
    {
        ::FUN_004a0370((char *)(FUN_0043c4b0()));
    }
    aFreeData[3] = abLockRenderer;
    aFreeData[4] = abRunHeapClean;
    *(unsigned int*)(aFreeData + 8) = ((unsigned int)(::FUN_008781f0()));
    FUN_008781e0(0x7FFFFFFF);
    FUN_00703980();
}

struct bhkEntityListener_shell
{
    int pad0;
    int pad1;
    bool bEnabled;
    void FUN_00937090(bool abTF);
};

// @fnv 0x00937090
void bhkEntityListener_shell::FUN_00937090(bool abTF)
{
    bEnabled = abTF;
}

struct FUN_009604f0_shell : public TESObjectCELL
{
    void* FUN_009604f0();
};
// Locks the cell, walks its node list, and adds refs whose object reference is DAT_011ca228 to the given list.
// @fnv 0x0054b8c0
void FUN_0054b8c0_shell::AddStaticRefsToList(BSSimpleList<const char*>* list)
{
    if (list)
    {
        this->CellRefLockEnter();
        NodeStub* node = (NodeStub*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>((this))->FUN_009604f0()));
        while (node)
        {
            RefStub* ref = *((::RefStub **)((void *)(node)));
            if (ref)
            {
                if (((::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == ::DAT_011ca228)
                {
                    void* tmp = ref->FUN_00569080();
                    if (tmp)
                        ((ListStub*)list)->AddHead(&ref);
                }
            }
            node = ((::NodeStub *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)(this));
    }
}
// @fnv 0x0054b950
void FUN_0054b950_shell::FUN_0054b950(bool abAttach)
{
    if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004226e0() && !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((::g_BGSSaveLoadGame))->FUN_0042ce10())
    {
        CellRefLockEnter();
        BSSimpleList<BGSPerkEntry*>* pCurrentElementNext = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (pCurrentElementNext)
        {
            RefObj* pcurrentObj = *((::RefObj **)(&pCurrentElementNext->item));
            pCurrentElementNext = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
            if (pcurrentObj && reinterpret_cast<::FUN_0057a2f0_shell *>((pcurrentObj))->FUN_0057a2f0() && (!abAttach || reinterpret_cast<::FUN_0057a370_shell *>((pcurrentObj))->FUN_0057a370()))
            {
                pcurrentObj->FUN_00579ac0(abAttach);
            }
        }
        ::FUN_00541ae0((char *)this);
    }
}

// @fnv 0x009604f0
void* FUN_009604f0_shell::FUN_009604f0()
{
    return (char*)&this->kObjectList;
}

// @fnv 0x009938b0
unsigned int FUN_009938b0(const unsigned short* pThis)
{
    return pThis[6];
}

namespace fnv_009d9f20 {
struct BSPortalGraph;
struct FUN_009d9f20_shell : public TESObjectCELL
{
    BSPortalGraph* FUN_009d9f20();
};

template <typename T> class BSStringT
{
  public:
    operator const char*() const;
};

// @fnv 0x009d9f20
BSPortalGraph* FUN_009d9f20_shell::FUN_009d9f20()
{
    return (BSPortalGraph*)this->pPortalGraph;
}
}  // namespace fnv_009d9f20

struct FUN_00c3e310_shell : public TESObjectCELL
{
    void FUN_00c3e310();
};


// If FUN_00c3e750 returns true and the function pointer at offset 0x7c is set, calls that callback.
// @fnv 0x00c3e310
void FUN_00c3e310_shell::FUN_00c3e310()
{
    if (reinterpret_cast<::FUN_00c3e750_Class *>((this))->FUN_00c3e750() && *(void (**)(void))&this->unk7c)
        (*(void (**)(void))&this->unk7c)();
}

struct GO
{
    char b[4];
    GO(intptr_t);
    ~GO();
};
struct SL
{
    char b[8];
    SL();
    ~SL();
};
struct FUN_00558d40
{
    char b[16];
    FUN_00558d40(int);
    ~FUN_00558d40();
};
struct FUN_00558d70
{
    char b[16];
    FUN_00558d70(int);
    ~FUN_00558d70();
};
struct FUN_00558da0
{
    char b[16];
    FUN_00558da0(int);
    ~FUN_00558da0();
};
struct FUN_00544f60 : public GO
{
    SL a;
    FUN_00558d40 b;
    FUN_00558d70 c;
    FUN_00558d40 d;
    FUN_00558da0 e;
    SL f;
    SL g;
    SL h;
    FUN_00544f60();
};
// Constructs the object, initializing base GO with 0 and members b, c, d, e with 0x25.
// @fnv 0x00544f60
FUN_00544f60::FUN_00544f60() : GO(0), b(0x25), c(0x25), d(0x25), e(0x25)
{}

struct FUN_005496b0_shell : public TESObjectCELL
{
    void FUN_005496b0(TESObjectREFR*, NiNode*);
};

struct NiNodeV
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
    virtual void InsertChild(NiAVObject*);
};
struct RefA
{
};
struct ShadowSceneNode
{
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};
struct DetailedActorPathHandler
{
};
struct RefH
{
};
struct G2
{
    void AddHead(RefStub**);
};
struct Shell54ca00 : TESObjectCELL
{
    void FUN_0054ca00(G2* apList);
};
// Locks cell refs, walks the node list, and prepends each non-deleted, enabled ref that passes FUN_00568680 to apList.
// @fnv 0x0054ca00
void Shell54ca00::FUN_0054ca00(G2* apList)
{
    if (apList)
    {
        CellRefLockEnter();
        NodeStub* node = (NodeStub*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (node)
        {
            RefStub* ref = *((::RefStub **)((void *)(node)));
            if (ref && reinterpret_cast<::FUN_00568680_shell *>((((RefH*)ref)))->FUN_00568680() && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(((RefH*)ref)))->FUN_00440d80() && !reinterpret_cast<::TESForm *>((((RefH*)ref)))->GetDisabled())
                apList->AddHead(&ref);
            node = ((::NodeStub *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)this);
    }
}

struct FUN_00550280_shell : public TESObjectCELL
{
    bool FUN_00550280(TESFile*);
};

struct S54deb0
{
};
struct FileH
{
    unsigned int GetFormID();
};
struct DoorH
{
};
struct WorldH
{
};
// @fnv 0x00550280
bool FUN_00550280_shell::FUN_00550280(TESFile* apFile)
{
    unsigned int ioffset;
    if (apFile && reinterpret_cast<::TESFile *>((((FileH*)apFile)))->IsMasterFile())
    {
        if (IsCellInterior())
        {
            ioffset = reinterpret_cast<::fnv_0054deb0::FUN_0054deb0_shell *>((((S54deb0*)this)))->FUN_0054deb0();
            if (ioffset)
                reinterpret_cast<::TESOffsetWorker *>((((FileH*)apFile)))->FUN_004723a0(ioffset);
        }
        else
        {
            void* pworld;
            pworld = ((void *)(reinterpret_cast<::TESObjectCELL *>((((DoorH*)this)))->GetParentWorldSpace()));
            if (pworld)
                reinterpret_cast<::WorldReader *>((((WorldH*)pworld)))->SeekToCellInWorld((::FileReader *)(apFile), GetCellGridX(), GetCellGridY());
        }
        if (reinterpret_cast<::FUN_00472660_shell *>((((FileH*)apFile)))->FUN_00472660() == 0x39 && ((std::uintptr_t)(reinterpret_cast<::MiddleHighProcess *>((((FileH*)apFile)))->GetFaceGenHeadNode())) == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0())))
            return true;
    }
    return false;
}

struct TESRace;
struct SrcList;
struct FormS
{
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
// @fnv 0x005504e0
int GetSourceFileCount(FormS* p)
{
    return ((BSSimpleListTESRaceSize*)((::SrcList *)(::FUN_00460140((std::intptr_t)(p)))))->GetSize();
}

namespace fnv_005575d0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
class Script;
class TESBoundObject;
class TESForm;
class TESFullName;
class TESModel;
class TESModelTextureSwap;
class TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_005575d0_shell : public TESObjectCELL
{
    void UpdateNavMeshObstacles();
};

class TESObjectREFR;
struct RefStub;
int _FNV_GetFormType(void*);
struct NodeStub
{
};
typedef bool(* VFn)(RefStub*);
struct RefStub
{
    virtual void v0();
};
struct TESObjectDOOR;
struct NavMeshObstacleManager
{
};
struct BGSOpenCloseForm
{
    static int __cdecl GetOpenState(TESObjectREFR*);
};
// @fnv 0x005575d0
void FUN_005575d0_shell::UpdateNavMeshObstacles()
{
    NodeStub* pCurrentElementNext;
    CellRefLockEnter();
    pCurrentElementNext = (NodeStub*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pCurrentElementNext)
    {
        RefStub* pref = *((::fnv_005575d0::RefStub **)((void *)(pCurrentElementNext)));
        if (pref)
        {
            if ((*(VFn**)pref)[0x15c / 4](pref))
                reinterpret_cast<::fnv_006c0c30::Mgr006c0c30 *>((((::fnv_005575d0::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0c30((::fnv_006c0c30::Actor *)(::fnv_005575d0::TESObjectREFR *)((TESObjectREFR*)pref));
            if (_FNV_GetFormType((void*)((reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pref))->FUN_007af430()))) == 0x1c)
            {
                if (BGSOpenCloseForm::GetOpenState((TESObjectREFR*)pref) == 1)
                {
                    TESObjectDOOR* pdoor = (TESObjectDOOR*)((reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pref))->FUN_007af430()));
                    if (!reinterpret_cast<::FUN_00518080_shell *>((pdoor))->FUN_00518080())
                        reinterpret_cast<::fnv_006c0c30::Mgr006c0c30 *>((((::fnv_005575d0::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0c30((::fnv_006c0c30::Actor *)(::fnv_005575d0::TESObjectREFR *)((TESObjectREFR*)pref));
                }
                else
                {
                    reinterpret_cast<::FUN_006c0f10_shell *>((((::fnv_005575d0::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->UpdateDoorObstacle((::TESObjectREFR *)(::fnv_005575d0::TESObjectREFR *)((TESObjectREFR*)pref));
                }
            }
        }
        pCurrentElementNext = ((::fnv_005575d0::NodeStub *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_005575d0

struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct MapItem62d0
{
    MapItem62d0* next;
    void* key;
    void* val;
};
struct Map62d0
{
    virtual void v0();
    virtual unsigned int Hash(void*);
    unsigned int size;
    MapItem62d0** table;
    void FUN_00559120(MapItem62d0*& pos, void*& key, Helper62d0& val);
public:
    bool FUN_006c62d0(std::uintptr_t, void **);
};
// Reads the current map entry's key and value, then advances pos to the next entry in the chain or the next non-empty table slot, or null.
// @fnv 0x00559120
void Map62d0::FUN_00559120(MapItem62d0*& pos, void*& key, Helper62d0& val)
{
    MapItem62d0* item = pos;
    key = item->key;
    val = item->val;
    if (item->next)
    {
        pos = item->next;
        return;
    }
    unsigned int i = Hash(item->key);
    i = i + 1;
    for (; i < size; i++)
    {
        item = table[i];
        if (item)
        {
            pos = item;
            return;
        }
    }
    pos = 0;
}

struct ScrapHeapBuffer
{
    ScrapHeapBuffer();
    ~ScrapHeapBuffer();
};
struct FUN_00559b40
{
    virtual ~FUN_00559b40();
    unsigned int size;
    void* data;
    int pad;
    char flag;
    FUN_00559b40(int);
};
struct FUN_005595e0 : public FUN_00559b40
{
    ScrapHeapBuffer heap;
    FUN_005595e0(unsigned int uiHashSize, bool abClearOnDestruct);
    virtual ~FUN_005595e0();
};
// @fnv 0x005595e0
FUN_005595e0::FUN_005595e0(unsigned int uiHashSize, bool abClearOnDestruct) : FUN_00559b40(0)
{
    size = uiHashSize;
    flag = abClearOnDestruct;
    unsigned int isize = uiHashSize << 2;
    data = reinterpret_cast<::FUN_00aa54a0_s *>(&(heap))->FUN_00aa54a0(isize, DAT_010a2720);
    ::FUN_00403d30(data, 0, isize);
}

namespace sh {
struct ScrapHeapBuffer
{
    int d;
    ~ScrapHeapBuffer();
};
}
struct FUN_005596a0
{
    virtual ~FUN_005596a0();
};
struct FUN_005596e0 : public FUN_005596a0
{
    int f4;
    int f8;
    int fc;
    bool f10;
    sh::ScrapHeapBuffer m14;
    virtual ~FUN_005596e0();
};
// If f10 is set, calls FUN_00559bc0, then clears f8, fc and f4.
// @fnv 0x005596e0
FUN_005596e0::~FUN_005596e0()
{
    if (f10)
        reinterpret_cast<::FUN_00559bc0_cls *>(this)->FUN_00559bc0();
    f8 = 0;
    fc = 0;
    f4 = 0;
}

namespace fnv_00545a30 {
struct FUN_00545a30_shell : public TESObjectCELL
{
    void AttachOrphanedChildren();
};

struct SpArr
{
};
struct Flt : public SpArr
{
    operator unsigned int() const;
};
struct GO : public Flt
{
    void* m_ptr;
    GO(int);
    ~GO();
};

struct MapX
{
};

struct MapHolder
{
    char pad[0x3c];
    MapX map;
};

struct NiNodeVtbl
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual unsigned int AttachChildInAvailableSlot(unsigned int, int);
};

// @fnv 0x00545a30
void FUN_00545a30_shell::AttachOrphanedChildren()
{
    NiNode* pparent = (NiNode*)((TESObjectCELL*)this)->GetCellChildAt(7);
    if (pparent && ((MapHolder*)this->pRenderData))
    {
        void* iter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((((MapHolder*)this->pRenderData))->map))->GetFirstPos();
        while (iter)
        {
            GO spnode(0);
            unsigned int pref = 0;
            reinterpret_cast<::Map62d0 *>(&((((MapHolder*)this->pRenderData))->map))->FUN_00559120((::MapItem62d0 *&)(iter), (void *&)(pref), (::Helper62d0 &)(spnode));
            if ((unsigned int)spnode && !((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((NiAVObject*)spnode.m_ptr)))->FUN_009611e0())))
            {
                ((NiNodeVtbl*)pparent)->AttachChildInAvailableSlot((unsigned int)spnode, 1);
            }
        }
    }
}
}  // namespace fnv_00545a30

struct BSPortalGraph;
struct FUN_00545b30_shell : public TESObjectCELL
{
    BSPortalGraph* GetPortalGraph();
};

struct BSFadeNode
{
    char pad[0x78];
public:
    void SetRange(float, float);
};

struct FUN_00c5a9d0 : BSFadeNode
{
    FUN_00c5a9d0();
};

struct Flt
{
    operator unsigned int() const;
};

struct NP : Flt
{
    NP& operator=(void*);
};


// @fnv 0x00545b30
BSPortalGraph* FUN_00545b30_shell::GetPortalGraph()
{
    if (!(*(NP*)&this->pPortalGraph).operator unsigned int())
    {
        if (((TESObjectCELL*)this)->IsCellInterior())
        {
            *(NP*)&this->pPortalGraph = new FUN_00c5a9d0();
        }
        else
        {
            *(NP*)&this->pPortalGraph = ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_005831d0_shell *>((((TESObjectCELL*)this)->GetParentWorldSpace()))->GetOrCreateObject()));
        }
    }
    return (BSPortalGraph*)this->pPortalGraph;
}

struct G7d1
{
};

struct GlobalObjectO2_0045cf30
{
    G7d1 m_g7d1;
};

GlobalObjectO2_0045cf30 g_01267b28;

// @fnv 0x00454ae0
void __cdecl FUN_00454ae0()
{
    reinterpret_cast<::GlobalObject_0045cf30 *>(&(g_01267b28.m_g7d1))->GetBoolValue();
}

struct FUN_005422b0Class
{
    void FUN_005422b0();
    void FUN_00559460();
};

// @fnv 0x005422b0
void FUN_005422b0Class::FUN_005422b0()
{
    FUN_00559460();
}

struct FUN_005443e0_class
{
    unsigned char IsAnyConditionTrue();
};

struct FUN_00546a00Class
{
    void ClearFieldA4();
};

// @fnv 0x00546a00
void FUN_00546a00Class::ClearFieldA4()
{
    *(int*)((char*)this + 0xa4) = 0;
}

struct FUN_00546a20Class
{
    void ClearField();
};

// @fnv 0x00546a20
void FUN_00546a20Class::ClearField()
{
    ((int*)this)[0x28] = 0;
}


// @fnv 0x0054f4b0
unsigned char FUN_0054f4b0()
{
    return DAT_011ad7b4;
}


// @fnv 0x0054f4d0
void __cdecl SetByteAtOffset1B(unsigned char ucValue)
{
    *(unsigned char*)((char*)FUN_00664840(1) + 0x1b) = ucValue;
}


// @fnv 0x00552380
unsigned int FUN_00552380()
{
    return (*reinterpret_cast<unsigned int *>(&::DAT_011d5c44));
}

namespace fnv_005524d0 {
struct GlobalObjectO2_0045cf30
{
    unsigned char* GetLifeStateControlFlag(void);
};

GlobalObjectO2_0045cf30 g_01267c24;

// @fnv 0x005524d0
unsigned char FUN_005524d0()
{
    return *g_01267c24.GetLifeStateControlFlag();
}
}  // namespace fnv_005524d0

namespace fnv_005526d0 {
struct TaskQueueInterface
{
    void SetEnabledFlag(bool enabled);
};

// @fnv 0x005526d0
void TaskQueueInterface::SetEnabledFlag(bool enabled)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(enabled, 0x400000);
}
}  // namespace fnv_005526d0

struct FUN_00552da0_class
{
    char m[0x26];
    char bUnk26;
    char GetUnk26();
};

// @fnv 0x00552da0
char FUN_00552da0_class::GetUnk26()
{
    return bUnk26;
}

namespace fnv_005535c0 {
struct FUN_00553540
{
    virtual ~FUN_00553540();
    void* FUN_005535c0(unsigned int flags);
};


// @fnv 0x005535c0
void* FUN_00553540::FUN_005535c0(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_00553540 *>(this)->::FUN_00553540::~FUN_00553540();
    if (flags & 1)
        ::FUN_00538eb0((::Prm *)(::fnv_005535c0::FUN_00553540 *)(this));
    return this;
}
}  // namespace fnv_005535c0


struct FUN_00557d10_Class
{
    bool FUN_00557d10();
};

// @fnv 0x00557d10
bool FUN_00557d10_Class::FUN_00557d10()
{
    if (((int)(reinterpret_cast<::FUN_00450fd0_class *>((this))->GetByteAtOffset38())))
        return true;
    else
        return false;
}

struct FUN_00558c60Class
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0C;
    int m_0x10;
    int m_0x14;
    int m_0x18;
    int m_0x1C;
    int m_0x20;
    int m_0x24;
    int m_0x28;
    int m_0x2C;
    int m_0x30;
    int m_0x34;
    int m_0x38;
    int m_0x3C;
    int m_0x40;
    int m_0x44;
    int m_0x48;
    int m_0x4C;
    int m_0x50;
    int m_0x54;
    int m_0x58;
    int m_0x5C;
    int m_0x60;
    int* m_0x64;
    void FUN_00558c60(int a1);
};

// Stores the given int into the object pointed to by m_0x64, if that pointer is non-null.
// @fnv 0x00558c60
void FUN_00558c60Class::FUN_00558c60(int aiValue)
{
    if (m_0x64 != 0)
    {
        *m_0x64 = aiValue;
    }
}

extern int DAT_0102f338;

struct FUN_005590b0_S
{
};

struct FUN_00558da0_S : FUN_005590b0_S
{
    int* m_iWordAt00;
    FUN_00558da0_S* FUN_00558da0(int param_2);
};

namespace fnv_00559780 {
struct ScrapHeapBuffer
{
};


class FUN_00559780
{
  public:
    void CellRefLockEnter();
};

// @fnv 0x00559780
void FUN_00559780::CellRefLockEnter()
{
    reinterpret_cast<::FUN_00aa54a0_s *>((((ScrapHeapBuffer*)((char*)this + 0x14))))->FUN_00aa54a0(0xc, ::DAT_010a2720);
}
}  // namespace fnv_00559780

struct NiTListItem
{
    NiTListItem* m_pNext;
};

struct NiTPointerListBaseRaw
{
    NiTListItem* m_pHead;
    NiTListItem* m_pTail;
    NiTListItem* m_pDummy;
    void FUN_00559c30();
};

// @fnv 0x00559c30
void NiTPointerListBaseRaw::FUN_00559c30()
{
    NiTListItem* pkNode = m_pHead;
    while (pkNode)
    {
        NiTListItem* pkOld = pkNode;
        pkNode = pkNode->m_pNext;
        reinterpret_cast<::FUN_00559c90_Class *>(this)->FUN_00559c90(pkOld);
    }
    m_pDummy = 0;
    m_pHead = 0;
    m_pTail = 0;
}


// Shifts a and b right by 5 to cell coordinates and returns TESWorldSpace_GetKeyForCellCoord of them.
// @fnv 0x00544280
int GetCellCoordKey(int aiX, int aiY)
{
    int iKey;
    short s3 = (short)(aiX >> 5);
    short s2 = (short)(aiY >> 5);
    iKey = ::PackShortPair(s3, s2);
    return iKey;
}


// @fnv 0x005442c0
int FUN_005442c0(int a1, int a2)
{
    short v6 = a1 >> 3;
    short v2 = a2 >> 3;
    int v3 = PackShortPair(v6, v2);
    return v3;
}

struct FUN_00548700_Class
{
    unsigned int _0x00;
    unsigned int _0x04;
    unsigned int _0x08;
    bool FUN_00548700() const;
};

// @fnv 0x00548700
bool FUN_00548700_Class::FUN_00548700() const
{
    return (_0x08 & 0x10000000) ? true : false;
}

struct CheckWithinMultiBoundTask
{
    void FUN_0054ab60();
    void* FUN_0054ab30(unsigned int flags);
};


class NiRenderTargetGroup;
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup();
public:
    static void EndAllAndResetRendererState();
};
bool __cdecl FUN_00b6b7d0(NiRenderTargetGroup*, int);

// Gets the render target group from texture (or null if texture is null) and forwards it with arg to FUN_00b6b7d0, returning its result.
// @fnv 0x0054ede0
bool __cdecl FUN_0054ede0(BSRenderedTexture* texture, int arg)
{
    NiRenderTargetGroup* group;
    if (texture)
        group = texture->GetGroup();
    else
        group = 0;
    return FUN_00b6b7d0(group, arg);
}

struct FUN_00557aa0_Class
{
    void FUN_00557aa0();
};

// If the byte at offset 0xce is clear, sets it to 1, clears the byte at 0xcf and zeroes the float at 0xc8; otherwise returns early.
// @fnv 0x00557aa0
void FUN_00557aa0_Class::FUN_00557aa0()
{
    if (*(unsigned char*)(this + 0xce))
    {
        return;
    }
    *(unsigned char*)(this + 0xce) = 1;
    *(unsigned char*)(this + 0xcf) = 0;
    *(float*)(this + 0xc8) = 0.0f;
}

struct FUN_00557d30_class
{
    char m_d0[0xd0];
    char m_flag;
    char FUN_00557d30();
};
// @fnv 0x00557d30
char FUN_00557d30_class::FUN_00557d30()
{
    return m_flag;
}

namespace fnv_00558fb0 {
void* __cdecl _NiMalloc(unsigned int);
struct NiTMapItem
{
    void* m_ppVirtualMethodTable;
    int m_uiItemCount;
    void* m_data;
    int m_iElementCount;
    void* FUN_00558fb0(int count);
};
// @fnv 0x00558fb0
void* NiTMapItem::FUN_00558fb0(int count)
{
    m_ppVirtualMethodTable = (void*)&DAT_0102f378;
    m_uiItemCount = count;
    m_iElementCount = 0;
    unsigned int size = m_uiItemCount * 4;
    m_data = _NiMalloc(size);
    memset(m_data, 0, m_uiItemCount * 4);
    return this;
}
}  // namespace fnv_00558fb0

struct FUN_00544300_Class
{
    char pad1[0x24];
    unsigned char m_24;
    void FUN_00544300(bool a1);
};

// Sets or clears bit 0 of m_24 according to a1.
// @fnv 0x00544300
void FUN_00544300_Class::FUN_00544300(bool abSet)
{
    if (abSet)
        m_24 |= 1;
    else
        m_24 &= ~1;
}

struct FUN_00544420_StandIn
{
    char pad[0x24];
    unsigned char f24;
    bool FUN_00544420();
};
// Returns 1 if IsFlag20Set or FUN_00544420 succeeds, otherwise returns 0.
// @fnv 0x005443e0
unsigned char FUN_005443e0_class::IsAnyConditionTrue()
{
    if (((unsigned char)(reinterpret_cast<::FUN_00502180_shell *>(this)->IsFlag20Set())))
        return 1;
    if (((unsigned char)(reinterpret_cast<::FUN_00544420_StandIn *>(this)->FUN_00544420())))
        return 1;
    return 0;
}

// @fnv 0x00544420
bool FUN_00544420_StandIn::FUN_00544420()
{
    return f24 & 0x40;
}

struct ArrSI
{
public:
    char HasFlag80000();
};

struct FUN_00544490_Class
{
    unsigned char FUN_00544490();
};

// @fnv 0x00544490
unsigned char FUN_00544490_Class::FUN_00544490()
{
    unsigned int flags = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName()));
    if (flags & 0x20000)
        return 1;
    return 0;
}

struct FUN_00546950_Class
{
    char pad[0x244];
    int m_uiInitializationFlags;
    bool FUN_00546950() const;
};

// @fnv 0x00546950
bool FUN_00546950_Class::FUN_00546950() const
{
    return (m_uiInitializationFlags & 0x10) ? true : false;
}

namespace fnv_00546c70 {
struct Calendar
{
};
extern Calendar g_calendar;

struct TESObjectCELL_s
{
    void SetDetachTime(unsigned int, bool);
    void FUN_00546c70();
};

// @fnv 0x00546c70
void TESObjectCELL_s::FUN_00546c70()
{
    unsigned int hours = reinterpret_cast<::Calendar *>(&(g_calendar))->GetGameHoursPassed();
    SetDetachTime(hours, false);
}
}  // namespace fnv_00546c70

class ExtraDataList;
struct FUN_0041c290_shell
{
};

struct FUN_00547750_shell : public TESDataHandler
{
    void FUN_00547750(std::intptr_t a);
};

// Calls SetImageSpaceExtra on the TESImageSpaceModifierList obtained from GetTESImageSpaceModifierList, passing a.
// @fnv 0x00547750
void FUN_00547750_shell::FUN_00547750(std::intptr_t a)
{
    reinterpret_cast<::fnv_0041c290::FUN_0041c290_shell *>((((FUN_0041c290_shell*)((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList())))))->SetImageSpaceExtra((::fnv_0041c290::TESImageSpace *)(a));
}

struct FNStub
{
    const char* GetFullName(void);
};

struct FUN_00548210_Class
{
    char pad[0xd4];
    FNStub m_stub;
    const char* FUN_00548210();
};

// @fnv 0x00548210
const char* FUN_00548210_Class::FUN_00548210()
{
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(m_stub))->FUN_00408da0()));
}

struct FUN_005495a0Class
{
    char pad_a8[0xa8];
    short m_a8;  // +0xa8
    short m_aa;  // +0xaa
    bool FUN_005495a0();
};

// Returns whether m_a8 is less than or equal to m_aa.
// @fnv 0x005495a0
bool FUN_005495a0Class::FUN_005495a0()
{
    return m_a8 <= m_aa;
}

struct FUN_0054b800_class
{
    void FUN_0054b800();
};
// Clears the two floats at offsets 0xb8 and 0xb4 to zero and calls FUN_00476ae0 with 0.
// @fnv 0x0054b800
void FUN_0054b800_class::FUN_0054b800()
{
    *(float*)((char*)this + 0xb8) = 0.0f;
    *(float*)((char*)this + 0xb4) = 0.0f;
    reinterpret_cast<::FUN_00476ae0_class *>(this)->FUN_00476ae0(0);
}

struct FUN_0054da00_class
{
    void FUN_0054da00();
};
// @fnv 0x0054da00
void FUN_0054da00_class::FUN_0054da00()
{
    reinterpret_cast<::FUN_00559810 *>(this)->::FUN_00559810::~FUN_00559810();
}

struct FUN_0054de80Class : public TESObjectCELL
{
    void FUN_0054de80(int value);
};

// @fnv 0x0054de80
void FUN_0054de80Class::FUN_0054de80(int value)
{
    if (IsCellInterior())
        *(int*)((char*)&this->worldSpace) = value;
}

struct FUN_005524b0_class
{
    unsigned char GetByteAtOffset8C();
};

// @fnv 0x005524b0
unsigned char FUN_005524b0_class::GetByteAtOffset8C()
{
    return ((const unsigned char*)this)[0x8c];
}

extern int DAT_0102f2f8;

struct FUN_00558d40_class
{
    void* m_p;
    void FUN_00558eb0(int a);
    FUN_00558d40_class* FUN_00558d40(int a);
};

extern int DAT_0102f318;
struct FUN_00558d70_Class
{
    int* vfn;
    FUN_00558d70_Class* FUN_00558d70(int a);
};
// Calls FUN_00558fb0 with a, sets vfn to DAT_0102f318, and returns this.
// @fnv 0x00558d70
FUN_00558d70_Class* FUN_00558d70_Class::FUN_00558d70(int a)
{
    reinterpret_cast<::fnv_00558fb0::NiTMapItem *>(this)->FUN_00558fb0(a);
    vfn = &DAT_0102f318;
    return this;
}

struct FUN_00558dd0_class
{
    int m_iWordAt00;
    intptr_t m_iWordAt04;
    intptr_t FUN_00558dd0(unsigned int index);
};

// @fnv 0x00558dd0
intptr_t FUN_00558dd0_class::FUN_00558dd0(unsigned int index)
{
    return this->m_iWordAt04 + index * 16;
}

class hkReferencedObject
{
};
struct FUN_00558e80_Class
{
    hkReferencedObject* m_pObject;
    void ReleaseObject();
};
// Removes a reference from m_pObject if set, then clears the pointer.
// @fnv 0x00558e80
void FUN_00558e80_Class::ReleaseObject()
{
    if (m_pObject)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pObject))->FUN_00c905b0();
    m_pObject = 0;
}

extern "C" void _NiFreeAlias(void*);
struct MyMap
{
};
extern int DAT_0102f358;
struct FUN_00558f80
{
    void* vtbl;
    int a;
    void* b;
    void Init();
};
// Sets vtbl to DAT_0102f358, clears the map contents, and frees b via _NiFreeAlias.
// @fnv 0x00558f80
void FUN_00558f80::Init()
{
    vtbl = (void*)&DAT_0102f358;
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)this)))->FUN_00438af0();
    _NiFreeAlias(b);
}

namespace fnv_00559080 {
struct MyMap
{
};
void __cdecl NiFreeAlias(void*);
struct FUN_00559080 : MyMap
{
    void* vtbl;
    int unused;
    void* ptr;
    void Init();
};
// Sets vtbl to DAT_0102f378, calls RemoveAll, then frees ptr via NiFreeAlias.
// @fnv 0x00559080
void FUN_00559080::Init()
{
    vtbl = &::fnv_00558fb0::DAT_0102f378;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    NiFreeAlias(ptr);
}
}  // namespace fnv_00559080

extern int DAT_0102f3c0;

struct FUN_005594b0_class
{
    void* vtable;
    FUN_005594b0_class* Construct(int a, int b);
};

// Calls FUN_00559ad0 with the two arguments, sets the vtable to DAT_0102f3c0, and returns this.
// @fnv 0x005594b0
FUN_005594b0_class* FUN_005594b0_class::Construct(int aiArg1, int aiArg2)
{
    new ((void *)this) ::fnv_00559ad0::FUN_00559ad0_Class(aiArg1, aiArg2);
    vtable = &DAT_0102f3c0;
    return this;
}

namespace fnv_005597a0 {
struct ScrapHeapBuffer
{
};
struct FUN_005597a0_Class
{
    void ClearAndDeallocate(void* arg);
};
// @fnv 0x005597a0
void FUN_005597a0_Class::ClearAndDeallocate(void* arg)
{
    ((char*)arg)[8] = 0;
    reinterpret_cast<::SHStub *>((((ScrapHeapBuffer*)((char*)this + 0x14))))->FUN_00aa5610(arg);
}
}  // namespace fnv_005597a0

namespace fnv_004695a0 {
struct FileH
{
};
struct TESSaveLoadGame
{
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_004695a0_rec
{
    unsigned int a;
    unsigned int b;
    unsigned int auiFormId;
    unsigned int uiType;
};
struct FUN_004695a0_t : public TESObjectCELL
{
    bool FUN_004695a0(FileH* apFile, FUN_004695a0_rec* apRec);
};

// @fnv 0x004695a0
bool FUN_004695a0_t::FUN_004695a0(FileH* apFile, FUN_004695a0_rec* apRec)
{
    bool bretval = true;
    if (apFile && !reinterpret_cast<::TESFile *>((apFile))->IsMasterFile() && !(g_TESSaveLoadGame && reinterpret_cast<::FUN_0047c850 *>((g_TESSaveLoadGame))->EvaluateCondition()))
        return true;
    if (apRec)
    {
        switch (apRec->uiType)
        {
        case 4:
        case 5:
        case 9:
            bretval = false;
            break;
        }
        if (bretval && g_TESSaveLoadGame && reinterpret_cast<::FUN_0047c850 *>((g_TESSaveLoadGame))->EvaluateCondition())
        {
            switch (::FindFormEnumIndex(apRec->auiFormId))
            {
            case 0x3:
            case 0x4:
            case 0x5:
            case 0x7:
            case 0x9:
            case 0xa:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
            case 0xf:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x1b:
            case 0x1c:
            case 0x1d:
            case 0x20:
            case 0x21:
            case 0x23:
            case 0x24:
            case 0x25:
            case 0x26:
            case 0x27:
            case 0x2c:
            case 0x2d:
            case 0x2f:
            case 0x30:
            case 0x31:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x45:
            case 0x46:
            case 0x48:
            case 0x49:
            case 0x4a:
            case 0x4b:
            case 0x4c:
            case 0x4d:
            case 0x4e:
            case 0x4f:
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            case 0x58:
            case 0x5b:
            case 0x5c:
            case 0x61:
            case 0x66:
            case 0x6f:
            case 0x70:
                bretval = false;
                break;
            }
        }
    }
    return bretval;
}
}  // namespace fnv_004695a0

struct FUN_0041c360_class
{
    unsigned int FUN_0041c360();
};
struct FUN_00547650_class
{
    unsigned int FUN_00547650();
};
// @fnv 0x00547650
unsigned int FUN_00547650_class::FUN_00547650()
{
    unsigned int result =
        reinterpret_cast<FUN_0041c360_class*>(((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESDataHandler*)this)))->GetExtraDataList())))->FUN_0041c360();
    return result;
}

namespace fnv_0054ae30 {
struct Flt
{
    void* p;
    operator unsigned int();
};
struct BSOcclusionPlane
{
};
struct FUN_005496b0_shell
{
};
struct FUN_0054acf0
{
    Flt m_pSceneObject;
    Flt m_pParent;
    unsigned int uiFlags;
    FUN_0054acf0();
    ~FUN_0054acf0();
};
struct MapX
{
};

// @fnv 0x0054ae30
void FUN_0054ae30()
{
    void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((*reinterpret_cast<::fnv_0054ae30::MapX *>(&::g_011ca0f4))))->GetFirstPos();
    while (pos)
    {
        unsigned int key = 0;
        FUN_0054acf0 data;
        reinterpret_cast<::FUN_005593a0_cls *>(&((*reinterpret_cast<::fnv_0054ae30::MapX *>(&::g_011ca0f4))))->FUN_005593a0((::ItemNode **)&(pos), (int *)&(key), (::FUN_00559900_Struct *)&(data));
        if (data.m_pSceneObject &&
            ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((NiAVObject*)data.m_pSceneObject.p)))->FUN_009611e0())) != (NiNode*)data.m_pParent.p)
        {
            TESObjectREFR* pref = ::FUN_0056f930((NiAVObject*)data.m_pSceneObject.p);
            if (pref && ((std::uintptr_t)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)pref)))->GetTarget())))
                reinterpret_cast<::FUN_005496b0_shell *>((((FUN_005496b0_shell*)((reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)pref)))->GetTarget())))))->FUN_005496b0(pref, (NiNode*)data.m_pParent.p);
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>(&((*reinterpret_cast<::fnv_0054ae30::MapX *>(&::g_011ca0f4))))->FUN_00438af0();
}
}  // namespace fnv_0054ae30

namespace fnv_0054c740 {
struct FUN_0054c740_shell : public TESObjectCELL
{
    bool FUN_0054c740(bool, bool);
};

struct RefH
{
};
struct RefA
{
};
struct MobileObjectExt
{
};
struct FUN_0056a380_cls
{
};
struct Interface
{
};
struct RefListOps
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};

// @fnv 0x0054c740
bool FUN_0054c740_shell::FUN_0054c740(bool bIgnore3D, bool bIgnoreActors)
{
    bool bquit = false;
    CellRefLockEnter();
    BSSimpleList<BGSPerkEntry*>* pCurrentElementNext = 0;
    if (this->pRenderData)
        pCurrentElementNext = (BSSimpleList<BGSPerkEntry*>*)((char*)this->pRenderData + 0x4c);
    else if (bIgnore3D)
        pCurrentElementNext = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pCurrentElementNext)
    {
        TESObjectREFR* pref = (TESObjectREFR*)(pCurrentElementNext->item);
        pCurrentElementNext = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        if (pref)
        {
            if ((bIgnore3D || ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((RefA*)pref)))->FUN_0043fcd0())) || reinterpret_cast<::TESForm *>((((RefH*)pref)))->GetDisabled()) &&
                reinterpret_cast<::fnv_00565870::FUN_00565870_shell *>((((MobileObjectExt*)pref)))->FUN_00565870() && !bIgnore3D)
            {
                bquit = true;
                break;
            }
        }
    }
    if (this->pRenderData && !bquit && !::FUN_00702360())
    {
        BSSimpleList<BGSPerkEntry*>* pCurrentElementNext =
            (BSSimpleList<BGSPerkEntry*>*)((char*)this->pRenderData + 0x54);
        BSSimpleList<BGSPerkEntry*>* pPrevNode = 0;
        while (pCurrentElementNext && !((RefListOps*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)(pCurrentElementNext->item);
            if (!((bool)(reinterpret_cast<::FUN_0056a380_shell *>((((FUN_0056a380_cls*)pref)))->FUN_0056a380())))
            {
                if (pPrevNode)
                {
                    reinterpret_cast<::ItemChangeListNode *>((((RefListOps*)pPrevNode)))->FUN_00905330((::InventoryStackRecord *const &)(pref));
                    pCurrentElementNext = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((pPrevNode))->FUN_00726070()));
                }
                else
                {
                    ((RefListOps*)pCurrentElementNext)->FUN_0063f7b0();
                }
            }
            else
            {
                pPrevNode = pCurrentElementNext;
                pCurrentElementNext = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
            }
        }
    }
    ::FUN_00541ae0((char *)this);
    return bquit;
}
}  // namespace fnv_0054c740

namespace fnv_00550c60 {
struct PackedRecordData;
class Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
class ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
class TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
class TESBoundObject;
class TESContainer;
struct TESFaction;
class TESForm;
struct TESLevItem;
struct TESLevSpell;
class TESObject;
class TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
class TESObjectWEAP;
class TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_00550c60_shell : public TESObjectCELL
{
    void RecalcLeveledActorBases(bool);
};

struct FUN_00550c60_AB
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~FUN_00550c60_AB();
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
    virtual bool vf8();
};
struct FUN_00550c60_Ref
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
    virtual void v1cc(int, int);
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool v22c(int);
};

struct FUN_00550c60_List
{
    bool _ref_008256d0();
};
struct Calendar
{
};
extern Calendar g_calendar;
struct RefH
{
};
struct TESActorBaseData
{
};
struct FUN_00881c90_cls
{
};
struct FUN_00550c60_RefFns
{
};
// @fnv 0x00550c60
void FUN_00550c60_shell::RecalcLeveledActorBases(bool abAllowRecalc)
{
    FUN_00550c60_List* pCurrentElementNext;
    unsigned int uiCurrentTime;
    CellRefLockEnter();
    uiCurrentTime = reinterpret_cast<::Calendar *>(&(g_calendar))->GetGameHoursPassed();
    pCurrentElementNext = (FUN_00550c60_List*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
    {
        bool badvanced = false;
        FUN_00550c60_Ref* pref = *((::fnv_00550c60::FUN_00550c60_Ref **)((void *)(pCurrentElementNext)));
        pCurrentElementNext = ((::fnv_00550c60::FUN_00550c60_List *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        if (((::fnv_00550c60::FUN_00550c60_AB *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((FUN_00550c60_RefFns*)pref)))->FUN_007af430()))->vf8() && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(((RefH*)pref)))->FUN_00440d80() &&
            !pref->v22c(0))
        {
            Actor* pactor = (Actor*)pref;
            FUN_00550c60_AB* porigbase = ((::fnv_00550c60::FUN_00550c60_AB *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((FUN_00550c60_RefFns*)pref)))->FUN_007af430()));
            {
                FUN_00550c60_AB* pNewBase = ((::fnv_00550c60::FUN_00550c60_AB *)(std::uintptr_t)(::FUN_004216f0((BaseExtraList*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((((FUN_00550c60_RefFns*)pref)))->FUN_005d43c0())))));
                if (pNewBase && pNewBase != porigbase)
                {
                    if (reinterpret_cast<::FUN_00881c90_cls *>((((FUN_00881c90_cls*)pactor)))->IsExpired(uiCurrentTime))
                    {
                        pref->v1cc(0, 0);
                        reinterpret_cast<::Fn575690 *>((((FUN_00550c60_RefFns*)pref)))->FUN_00575690((TESBoundObject*)pNewBase);
                        reinterpret_cast<::Ref56B0 *>((((FUN_00550c60_RefFns*)pref)))->FUN_0056b020(0, 0);
                        delete porigbase;
                        porigbase = pNewBase;
                        pNewBase = 0;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            if (reinterpret_cast<::FUN_0047cdb0_shell *>((((TESActorBaseData*)((char*)porigbase + 0x30))))->FUN_0047cdb0())
                reinterpret_cast<::fnv_0047ce10::OwnerShell *>((((TESActorBaseData*)((char*)porigbase + 0x30))))->FUN_0047ce10((::fnv_0047ce10::RefShell *)(::TESObjectREFR *)((TESObjectREFR*)pref));
        }
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_00550c60

namespace fnv_00552570 {
struct GO
{
    void* p;
    ~GO();
};
struct Flt : GO
{
    operator unsigned int();
};
struct SpObst : Flt
{
    SpObst(unsigned int*);
};
struct QueuedAttachList
{
};
struct BSSpinLockU
{
};
struct DetailedActorPathHandler
{
    void HandleReferenceUpdate(TESObjectREFR*, bool, bool);
};
struct BSOcclusionPlane
{
};
struct QueuedAttachObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10();
    bool FUN_005526b0();
};

// @fnv 0x00552570
void FUN_00552570()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011ca1a0))))->FUN_0040fbf0((char *)(0));
    while (!reinterpret_cast<::ObsList *>(&((*reinterpret_cast<::fnv_00552570::QueuedAttachList *>(&::g_011ca174))))->FUN_004a4460())
    {
        SpObst attachdata(((unsigned int *)((void *)&((*reinterpret_cast<::fnv_00552570::QueuedAttachList *>(&::g_011ca174))))));
        reinterpret_cast<::DecalListManager *>(&((*reinterpret_cast<::fnv_00552570::QueuedAttachList *>(&::g_011ca174))))->PopHead();
        ::UpdateSceneGraph((NiAVObject*)attachdata.p);
        if ((unsigned int)attachdata && ((QueuedAttachObj*)attachdata.p)->v10() &&
            ((QueuedAttachObj*)attachdata.p)->FUN_005526b0())
        {
            TESObjectREFR* pref = ::FUN_0056f930((NiAVObject*)attachdata.p);
            if (pref && ((::fnv_00552570::DetailedActorPathHandler *)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)pref)))->GetTarget())))
            {
                ((::fnv_00552570::DetailedActorPathHandler *)(reinterpret_cast<::LowProcess *>((void *)(((BSOcclusionPlane*)pref)))->GetTarget()))->HandleReferenceUpdate(pref, true, false);
                reinterpret_cast<::fnv_005526d0::TaskQueueInterface *>((((QueuedAttachObj*)attachdata.p)))->SetEnabledFlag(0);
            }
        }
    }
    reinterpret_cast<::RecursiveSpinLock *>((((BSSpinLockU*)&(*reinterpret_cast<::RecursiveSpinLock *>(&::g_011ca1a0)))))->FUN_0040fba0();
}
}  // namespace fnv_00552570

namespace fnv_00553bf0 {
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float Length() const;
};
struct SeqObj
{
};
struct MobileObjectProcessArray
{
};
struct ScriptS
{
};
struct Obj553
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
    virtual void v115();
    virtual void* v116();
};
struct LItem_006815c0
{
};
struct LEmpty_008256d0
{
    bool _ref_008256d0();
};
struct S00553bf0
{
    bool FUN_00553bf0(ScriptS* apPick, NiPoint3* apPos, std::intptr_t aiArg, float afDist);
};

// @fnv 0x00553bf0
bool S00553bf0::FUN_00553bf0(ScriptS* apPick, NiPoint3* apPos, std::intptr_t aiArg, float afDist)
{
    bool bResult = false;
    if (apPick)
    {
        BSSimpleList<Obj553*>* pIter = ((::BSSimpleList< ::fnv_00553bf0::Obj553 *> *)(::FUN_00545710((std::intptr_t)this)));
        while (pIter && !((LEmpty_008256d0*)pIter)->_ref_008256d0())
        {
            Obj553* pObj = *((::fnv_00553bf0::Obj553 **)((void *)(((LItem_006815c0*)pIter))));
            if (pObj->v116())
            {
                if (::fnv_004b2800::PickObjectsInRadius((::fnv_004b2800::NiPick *)(apPick), (*(const ::NiPoint3 *)(apPos)), (*(const ::NiPoint3 *)(aiArg)), afDist, (::NiAVObject *)(void *)(pObj->v116())))
                {
                    NiPoint3 kPos = (*(::fnv_00553bf0::NiPoint3 *)(reinterpret_cast<::TESTopicInfoData *>((((::fnv_00553bf0::SeqObj *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((void *)(((::fnv_00553bf0::MobileObjectProcessArray *)(reinterpret_cast<::BGSCameraPath *>((apPick))->GetConditions()))))->FUN_00968670(0)))))->GetLinkToList()));
                    if (reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_00553bf0::NiPoint3 &)((kPos - *apPos)))->ComputeMagnitude() < afDist)
                    {
                        bResult = true;
                        break;
                    }
                }
            }
            pIter = ((::BSSimpleList< ::fnv_00553bf0::Obj553 *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
    }
    return bResult;
}
}  // namespace fnv_00553bf0

namespace fnv_00555740 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
class BaseFormComponent;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
class TESBoundObject;
class TESForm;
struct blob8
{
    char b[8];
};
struct FUN_00555740_shell : public TESObjectCELL
{
    void FUN_00555740(BGSLoadFormBuffer*);
};

class FormChangeMask
{
  public:
    unsigned int flags;
    FormChangeMask(unsigned int);
};
struct BGSLoadGameBuffer
{
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    FormChangeMask GetChangeFlags();
    void ReadTypedData(void*, unsigned int);
};
class TESForm
{
  public:
    virtual void LoadGame(void*);
};
struct SeenData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct IntSeenData : public SeenData
{
    char pad[0x20];
    IntSeenData();
};
struct FUN_0087a100 : public SeenData
{
    char pad[0x28];
    FUN_0087a100(char, char);
};
struct FUN_00555bc0_shell
{
};
struct FUN_00421940_s
{
};
struct FUN_00546bf0_s
{
};
struct FullNameEx
{
    void SetFullName(const char*);
};

// Loads a cell's flags, seen data, full name and owner from a save buffer according to the change flags.
// @fnv 0x00555740
void FUN_00555740_shell::FUN_00555740(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::TESForm *>((((TESForm*)this)))->LoadGame(apLoadGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555740::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags()))->FUN_004280f0(2))
    {
        unsigned char ctempCellFlags = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ctempCellFlags), 1);
        field24 = (field24 & 0x9f) | (ctempCellFlags & 0x60);
        padToExtraData2[0] = ctempCellFlags & 0x9f;
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555740::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags()))->FUN_004280f0(0x80000000))
    {
        SeenData* pseen = ((::fnv_00555740::SeenData *)(reinterpret_cast<::FUN_00555bc0_shell *>((((FUN_00555bc0_shell*)this)))->FindSeenData()));
        if (!pseen)
        {
            pseen = IsCellInterior() ? (SeenData*)new FUN_0087a100(0, 0) : (SeenData*)new IntSeenData();
            reinterpret_cast<::extra421::E4List *>((((FUN_00421940_s*)((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESDataHandler*)this)))->GetExtraDataList())))))->FUN_00421940((::extra421::E4Object *)(pseen));
        }
        pseen->LoadGame(apLoadGameBuffer);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555740::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags()))->FUN_004280f0(4))
    {
        char pfullname[260];
        reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((apLoadGameBuffer))->FUN_008649a0(pfullname);
        reinterpret_cast<::TESFullName *>((((FullNameEx*)this->kFullName)))->SetFullName(pfullname);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555740::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags()))->FUN_004280f0(8))
    {
        TESForm* powner = 0;
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&powner));
        reinterpret_cast<::FUN_00546bf0_class *>((((FUN_00546bf0_s*)this)))->FUN_00546bf0((std::intptr_t)(powner));
    }
}
}  // namespace fnv_00555740

void __cdecl FUN_005586c0(int);
struct Proxy00557d50
{
    void FUN_00557d50();
};
struct FUN_00557da0
{
    char _00[0x18];
    void(__cdecl* f18)(int);
    int f1c;
    FUN_00557da0();
};
namespace fnv_00547250 {
struct BSMultiBound;
struct BSMultiBoundNode;
struct BSMultiBoundRoom;
struct BSNiNode;
struct BSOcclusionPlane;
struct CloningProcess;
class NiCullingProcess;
struct NiObject;
struct NiStream;
struct NiUpdateData;
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
struct LoadedCellData
{
    void* __vecDelDtor(unsigned int);
    char m_abyData00[4];
    char m_abyData04[8];
    char m_abyData0C[16];
    char m_abyData1C[16];
    char m_abyData2C[16];
    char m_abyData3C[16];
    char m_abyData4C[8];
    char m_abyData54[8];
    char m_abyData5C[8];
};
struct FUN_00547250_shell : public TESObjectCELL
{
    bool CheckWaterHeight(void*, float*);
};

struct _LODMultType
{
    enum Type
    {
        kNone
    };
};
struct BSFadeNode
{
    _LODMultType::Type GetLODMultType() const;
};
struct MobileObjectCellAccess
{
};
class RecipeCraftingInfo
{
  public:
    float x, y, z;
};
struct TESRecipe
{
};
struct PathingLocation
{
  public:
    float x, y, z;
};
struct PathingRequest
{
};
struct Model
{
};
struct BSFaceGenNiNode
{
};
struct WaterRefObj;
struct WaterRefNode_00547250
{
};

struct AV3D
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiNode* IsSceneNode();
};
struct AVChild
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual struct MBNode* IsMultiBoundNode();
};
struct MBShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual int GetType();
};
struct MBNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual bool WithinBounds(NiPoint3*);
};
struct WaterRefObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual AV3D* Get3D();
    virtual void v1d4();
    virtual void GetBoundsMaximum(NiPoint3*);
    virtual void GetBoundsMinimum(NiPoint3*);
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual NiPoint3* GetPos();
};
// @fnv 0x00547250
bool FUN_00547250_shell::CheckWaterHeight(void* apPos, float* afHeight)
{
    bool bhitWater = false;
    if (IsCellInterior() && !reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(((MobileObjectCellAccess*)this)))->FUN_004518e0())
    {
        *afHeight = ::DAT_01015f5c;
        return false;
    }
    *afHeight = reinterpret_cast<::FUN_005471e0_shell *>((this))->FUN_005471e0();
    NiPoint3 pt = *(const NiPoint3*)apPos;
    LoadedCellData* ploadedData = (LoadedCellData*)((BSFadeNode*)this)->GetLODMultType();
    if (ploadedData)
    {
        BSSimpleList<TESObjectREFR*>* pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)ploadedData->m_abyData5C;
        while (pCurrentElementNext && *((::fnv_00547250::WaterRefObj **)((void *)(reinterpret_cast<WaterRefNode_00547250*>(pCurrentElementNext)))))
        {
            WaterRefObj* pwaterRef = *((::fnv_00547250::WaterRefObj **)((void *)(reinterpret_cast<WaterRefNode_00547250*>(pCurrentElementNext))));
            NiPoint3 max;
            NiPoint3 min;
            pwaterRef->GetBoundsMaximum(&min);
            pwaterRef->GetBoundsMinimum(&max);
            NiPoint3 angle = *(NiPoint3*)((::fnv_00547250::RecipeCraftingInfo *)(reinterpret_cast<::TESRecipe *>((((TESRecipe*)pwaterRef)))->GetData()));
            MBNode* pnode = ((AVChild*)pwaterRef->Get3D()->IsSceneNode()->GetAt(0))->IsMultiBoundNode();
            if (pnode)
            {
                MBShape* pshape = (MBShape*)((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(((Model*)((void *)(reinterpret_cast<::BSFaceGenNiNode *>((((BSFaceGenNiNode*)pnode)))->GetAnimationData())))))));
                if (pshape->GetType() == 1)
                    pt.z = ((::fnv_00547250::PathingLocation *)(::GetOffsetC((std::intptr_t)(((PathingRequest*)pshape)))))->z;
                if (pshape->GetType() == 2)
                    pt.z = ((::fnv_00547250::PathingLocation *)(::GetOffsetC((std::intptr_t)(((PathingRequest*)pshape)))))->z;
                if (pnode->WithinBounds(&pt))
                {
                    float fheight = pwaterRef->GetPos()->z;
                    if (fheight > *afHeight)
                        *afHeight = fheight;
                    bhitWater = true;
                }
            }
            pCurrentElementNext = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        }
    }
    return bhitWater;
}
}  // namespace fnv_00547250

namespace fnv_00550340 {
struct FormS;
class TESForm
{
  public:
    void Revert(unsigned int);
};
struct FileH
{
};
struct FUN_008256d0_list
{
    bool FUN_008256d0();
};
struct FUN_00464df0_shell
{
};
struct FUN_004734d0_shell
{
};
struct FUN_00551420_shell
{
};
struct S00551440
{
};
struct FUN_00550500_t
{
    bool FUN_00550500(TESFile*);
};
struct S004534f0
{
};
struct TESSaveLoadGame
{
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
namespace cellfn {
}
struct TESFileTS
{
};
struct CellVT
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
};

struct FUN_00550340_t : TESObjectCELL
{
    bool FUN_00550340();
};

// @fnv 0x00550340
bool FUN_00550340_t::FUN_00550340()
{
    bool brestoreLoading;
    unsigned int ifilecount;
    bool bretval;

    if (reinterpret_cast<::FUN_00551420_shell *>((((FUN_00551420_shell*)this)))->FUN_00551420())
        return true;
    bretval = true;
    ifilecount = ::GetSourceFileCount((::FormS *)(::fnv_00550340::FormS *)((FormS*)this));
    for (unsigned int i = 0; i < ifilecount; i++)
    {
        TESFile* pfile;
        pfile = reinterpret_cast<::TESFile *>((((TESFileTS*)reinterpret_cast<::TESForm *>((((TESForm*)this)))->GetFile(i))))->GetParentTESFile();
        if (pfile && reinterpret_cast<::TESFile *>((((FileH*)pfile)))->IsMasterFile())
        {
            unsigned int ioffset;
            bool bload;
            bload = false;
            ioffset = (unsigned int)(std::uintptr_t)(((::fnv_00550340::FUN_008256d0_list *)(reinterpret_cast<::FUN_00464df0_shell *>((((FUN_00464df0_shell*)pfile)))->FUN_00464df0()))->FUN_008256d0()
                                         ? ::FUN_0054de40((TESObjectCELL*)this)
                                         : 0);
            if (ioffset)
            {
                if (reinterpret_cast<::TESOffsetWorker *>((((FileH*)pfile)))->FUN_004723a0(ioffset))
                    bload = true;
            }
            else
            {
                if (reinterpret_cast<::FUN_004734d0_shell *>((((FUN_004734d0_shell*)pfile)))->FUN_004734d0((::TESForm *)(::fnv_00550340::TESForm *)((TESForm*)this)))
                    bload = true;
            }
            if (bload)
            {
                if (!((FUN_00550500_t*)this)->FUN_00550500(pfile))
                    bretval = false;
            }
            else
            {
                bretval = false;
            }
        }
        else
        {
            if (((int)(reinterpret_cast<::FUN_00450fd0_class *>(((void*)this))->GetByteAtOffset38())) <= 2 && !IsCellInterior())
                bretval = false;
        }
    }
    if (bretval)
        reinterpret_cast<::S00551440 *>((((S00551440*)this)))->FUN_00551440(true);
    else
        return bretval;
    brestoreLoading = reinterpret_cast<::FUN_0047c850 *>((g_TESSaveLoadGame))->EvaluateCondition();
    reinterpret_cast<::FUN_004534f0_shell *>((((S004534f0*)g_TESSaveLoadGame)))->FUN_004534f0(!brestoreLoading);
    ((CellVT*)this)->v22();
    reinterpret_cast<::FUN_004534f0_shell *>((((S004534f0*)g_TESSaveLoadGame)))->FUN_004534f0(brestoreLoading);
    return bretval;
}
}  // namespace fnv_00550340

namespace fnv_00558ba0 {
struct BGSPerkEntry
{
    virtual ~BGSPerkEntry();
    std::intptr_t GetInnerValue();
};
struct FUN_00558ba0_shell : public TESObjectCELL
{
    void FUN_00558ba0(std::intptr_t mask);
};
extern TESObjectCELL* _g_thePlayer;
// @fnv 0x00558ba0
void FUN_00558ba0_shell::FUN_00558ba0(std::intptr_t mask)
{
    BGSPerkEntry* item3 = 0;
    BSSimpleList<BGSPerkEntry*>* list = ((::BSSimpleList< ::fnv_00558ba0::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>((this))->FUN_009604f0()));
    while (list && (list->item))
    {
        item3 = (list->item);
        if (item3->GetInnerValue() == mask)
            reinterpret_cast<::FUN_00558c60Class *>((item3))->FUN_00558c60(0);
        list = ((::BSSimpleList< ::fnv_00558ba0::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
    if (reinterpret_cast<BGSPerkEntry*>(_g_thePlayer)->GetInnerValue() == mask)
        reinterpret_cast<::FUN_00558c60Class *>((reinterpret_cast<BGSPerkEntry*>(_g_thePlayer)))->FUN_00558c60(0);
}
}  // namespace fnv_00558ba0

namespace fnv_0049f210 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct S5460
{
    unsigned int FUN_00978bc0();
};
struct FUN_0049f8f0_class
{
    void ConstructEntries(int, unsigned int);
};
struct FUN_0049f210_class
{
    void* pad0;
    char* pItems;
    unsigned int FUN_00978bc0();
    void ConstructEntries(int, unsigned int);
    unsigned int AddItem(const NiPoint3& kPos);
};
// @fnv 0x0049f210
unsigned int FUN_0049f210_class::AddItem(const NiPoint3& kPos)
{
    unsigned int uiIndex = reinterpret_cast<::S5460 *>(this)->FUN_00978bc0();
    reinterpret_cast<::B49F8F0Allocator *>(this)->ConstructEntries((::B49F8F0Entry *)(pItems + uiIndex * 12), 1);
    *(NiPoint3*)(pItems + uiIndex * 12) = kPos;
    return uiIndex;
}
}  // namespace fnv_0049f210

int __cdecl GetCellCoordKey(int, int);

struct FUN_005441b0_S
{
    unsigned int FUN_0084e3a0();
    unsigned int FUN_005441b0();
};

// @fnv 0x005441b0
unsigned int FUN_005441b0_S::FUN_005441b0()
{
    unsigned int iblockkey = 0;
    if (!reinterpret_cast<::TESObjectCELL *>((void *)this)->IsCellInterior())
        iblockkey = GetCellCoordKey(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY());
    else
        iblockkey = (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) & 0x00ffffffu) % 10;
    return iblockkey;
}

int __cdecl FUN_005442c0(int, int);
struct ref_0084e3a0
{
};
struct FUN_00544210_shell
{
    unsigned int FUN_00544210();
};
// @fnv 0x00544210
unsigned int FUN_00544210_shell::FUN_00544210()
{
    unsigned int iblockkey = 0;
    if (!((TESObjectCELL*)this)->IsCellInterior())
        iblockkey = FUN_005442c0(((TESObjectCELL*)this)->GetCellGridX(), ((TESObjectCELL*)this)->GetCellGridY());
    else
    {
        iblockkey = (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ref_0084e3a0*)this)))->FUN_0084e3a0())) & 0x00ffffffu) % 100;
        iblockkey = iblockkey / 10;
    }
    return iblockkey;
}

struct FUN_00586210_shell
{
    bool HasFlag2();
};
struct DoorCellWS
{
};
struct FUN_00544520_shell
{
    bool FUN_00544520();
};
// @fnv 0x00544520
bool FUN_00544520_shell::FUN_00544520()
{
    bool result = false;
    if ((reinterpret_cast<TESObjectCELL*>(this)->field24 & 4) != 0)
        result = true;
    if (reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
        result = !result;
    if (result)
        return true;
    TESWorldSpace* space = reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<DoorCellWS*>(this)))->GetParentWorldSpace();
    if (space)
        return reinterpret_cast<FUN_00586210_shell*>(space)->HasFlag2();
    return false;
}

struct FUN_00544c90_shell : TESObjectCELL
{
    void SetExteriorCellCoordinates(int a, int b);
};
// If the cell has no exterior data, returns; otherwise stores a and b into the exterior data's x and y fields.
// @fnv 0x00544c90
void FUN_00544c90_shell::SetExteriorCellCoordinates(int aiX, int aiY)
{
    if (IsCellInterior())
        return;
    ExteriorCellData* data = ((::ExteriorCellData *)(reinterpret_cast<::FUN_005445d0_shell *>(this)->FUN_005445d0()));
    if (data)
    {
        data->x = aiX;
        data->y = aiY;
    }
}

struct MapH
{
};
struct RefList
{
};
struct FUN_00545360_StandIn : public TESObjectCELL
{
    void FUN_00545360(std::uintptr_t key);
};
// @fnv 0x00545360
void FUN_00545360_StandIn::FUN_00545360(std::uintptr_t key)
{
    if (pRenderData)
    {
        reinterpret_cast<::NiTMap_S *>((((MapH*)((char*)(MapH*)pRenderData + 0xc))))->RemoveKey(key);
        reinterpret_cast<::ItemChangeListNode *>((((RefList*)((char*)(MapH*)pRenderData + 4))))->FUN_00905330((::InventoryStackRecord *const &)(key));
    }
}

namespace fnv_00546970 {
struct FUN_0041b8d0_shell
{
};
struct FUN_0041b9a0_shell
{
};
struct FUN_004512a0_shell
{
};
struct FUN_00546a00Class
{
};
struct FUN_00546a20Class
{
};
struct FUN_006242f0_shell
{
};
struct ScriptLocals
{
};

struct FUN_00546970Class : FUN_004512a0_shell, FUN_00546a00Class, FUN_00546a20Class
{
    void ClearCellData();
    void FUN_00546970();
};

// @fnv 0x00546970
void FUN_00546970Class::FUN_00546970()
{
    void* pObject = ((void *)(std::uintptr_t)(reinterpret_cast<::B9A0Ref *>((((FUN_0041b9a0_shell*)((char*)this + 0x28))))->GetExtraHandleCount()));
    if (pObject && (*reinterpret_cast<void * *>(&::DAT_011ca088)))
        reinterpret_cast<::FUN_006242f0_shell *>((((FUN_006242f0_shell*)(*reinterpret_cast<void * *>(&::DAT_011ca088)))))->NotifyListener(((void *)(reinterpret_cast<::ScriptLocals *>((((ScriptLocals*)pObject)))->GetLocalData())));
    reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(1);
    ClearCellData();
    reinterpret_cast<::fnv_0041b8d0::FUN_0041b8d0_shell *>((((FUN_0041b8d0_shell*)((char*)this + 0x28))))->SetHavokWorld((::fnv_0041b8d0::bhkWorld *)(0));
    reinterpret_cast<::FUN_00546a00Class *>((((FUN_00546a00Class*)((char*)this))))->ClearFieldA4();
    reinterpret_cast<::FUN_00546a20Class *>((((FUN_00546a20Class*)((char*)this))))->ClearField();
    reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(0);
    ((unsigned char*)this)[0xd1] = 0;
}
}  // namespace fnv_00546970

struct TESClimate;
struct BaseExtraList2
{
    int FUN_0041c260();
};
struct FUN_00585fe0_shell
{
    TESClimate* FUN_00585fe0();
};
struct FUN_00454b10_shell
{
};
struct FUN_005475b0_shell
{
    TESClimate* FUN_005475b0();
};

// @fnv 0x005475b0
TESClimate* FUN_005475b0_shell::FUN_005475b0()
{
    if (reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
    {
        if (!((bool)(reinterpret_cast<::fnv_00454b10::TESObjectCELL *>((reinterpret_cast<FUN_00454b10_shell*>(this)))->GetFakeExterior())))
            return 0;
        else
            return reinterpret_cast<TESClimate*>(
                reinterpret_cast<BaseExtraList2*>(
                    ((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->GetExtraDataList())))
                    ->FUN_0041c260());
    }
    else
    {
        return reinterpret_cast<FUN_00585fe0_shell*>(reinterpret_cast<TESObjectCELL*>(this)->GetParentWorldSpace())
            ->FUN_00585fe0();
    }
}

namespace fnv_0054acf0 {
struct GO
{
    int a;
    GO(int);
    ~GO();
};
struct FUN_0054acf0 : GO
{
    GO b;
    unsigned char c;
    FUN_0054acf0();
};
// Initializes the base GO with 0, the member GO b with 0, and sets c to 1.
// @fnv 0x0054acf0
FUN_0054acf0::FUN_0054acf0() : GO(0), b(0)
{
    c = 1;
}
}  // namespace fnv_0054acf0

extern unsigned int _data_011c16bc;
struct SpObst
{
    unsigned int a;
    SpObst(unsigned int*);
    ~SpObst();
};
struct FUN_0054adb0 : SpObst
{
    SpObst b;
    unsigned char c;
    FUN_0054adb0(unsigned int*);
};
// Constructs the object from p: initialises the SpObst base and member b from p and p+1, and sets c from byte 8 of p.
// @fnv 0x0054adb0
FUN_0054adb0::FUN_0054adb0(unsigned int* auiData) : SpObst(auiData), b(auiData + 1)
{
    c = ((unsigned char*)auiData)[8];
}

// @fnv 0x0054fb20
float FUN_0054fb20(float x1, float y1, float x2, float y2)
{
    float a = x1 - x2;
    float b = y1 - y2;
    a = a * a;
    b = b * b;
    return FUN_004019b0(a + b);
}

namespace fnv_00550200 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_00550200 : TESObjectCELL
{
    bool IsPointInCell(const NiPoint3& point);
};

// @fnv 0x00550200
bool FUN_00550200::IsPointInCell(const NiPoint3& point)
{
    if (IsCellInterior())
        return false;
    int iX = ::FUN_00406d90(point.x);
    int iY = ::FUN_00406d90(point.y);
    if ((iX >> 12) != GetCellGridX())
        return false;
    if ((iY >> 12) != GetCellGridY())
        return false;
    return true;
}
}  // namespace fnv_00550200

namespace fnv_00555570 {
class TESForm
{
  public:
    void Revert(unsigned int flags);
};

struct TESSaveLoadGame
{
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00555be0_stub
{
    void FUN_00555be0();
};

struct FUN_00555570_cell
{
    char pad[0x25];
    unsigned char field25;
    void FUN_00555be0();
    void SetDetachTime(unsigned int a, bool b);
    void FUN_00555570(unsigned int flags);
};

// @fnv 0x00555570
void FUN_00555570_cell::FUN_00555570(unsigned int flags)
{
    reinterpret_cast<::FUN_004534f0_shell *>((reinterpret_cast<TESForm*>(this)))->FUN_004534f0(flags);
    if (reinterpret_cast<::FUN_0055f5b0_Class *>((g_TESSaveLoadGame))->FUN_0055f5b0())
    {
        field25 = 0;
    }
    if (flags & 0x80000000)
    {
        reinterpret_cast<::FUN_00555be0_stub *>(this)->FUN_00555be0();
    }
    if (flags & 0x40000000)
    {
        SetDetachTime(0, false);
    }
}
}  // namespace fnv_00555570

struct FUN_00557ae0_obj
{
};
struct FUN_00453980_shell
{
    unsigned int GetGlobalInt();
};
struct FUN_00459470_Class
{
    FUN_00557ae0_obj* FUN_00459470(int);
};
struct FUN_00557be0_shell
{
    void FUN_00557be0();
};

struct FUN_00557d50
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    FUN_00557d50();
};
// Calls FUN_00557d50 on this, then sets f18 to FUN_005586c0 and f1c to 0.
// @fnv 0x00557da0
FUN_00557da0::FUN_00557da0()
{
    new ((void *)(((Proxy00557d50*)this))) ::FUN_00557d50();
    f18 = FUN_005586c0;
    f1c = 0;
}

// @fnv 0x00557d50
FUN_00557d50::FUN_00557d50()
{
    a = 0x4b0;
    b = 0xc3500;
    c = 0x64;
    d = 0xf;
    e = 0xffffffff;
    f = 8;
}

extern int DAT_0102f358;
void* __cdecl _NiMalloc(unsigned int);
struct FUN_00558eb0
{
    int* pvt;
    unsigned int size;
    void* pMap;
    unsigned int mSize;
    FUN_00558eb0(unsigned int iSize);
};
// Calls FUN_00558eb0 with a, sets m_p to DAT_0102f2f8, and returns this.
// @fnv 0x00558d40
FUN_00558d40_class* FUN_00558d40_class::FUN_00558d40(int a)
{
    new ((void *)this) ::FUN_00558eb0(a);
    m_p = &DAT_0102f2f8;
    return this;
}

// Stores the size, allocates size*4 zeroed bytes for pMap, and sets mSize to 0.
// @fnv 0x00558eb0
FUN_00558eb0::FUN_00558eb0(unsigned int iSize)
{
    pvt = &DAT_0102f358;
    size = iSize;
    mSize = 0;
    unsigned int uiByteCount = size << 2;
    pMap = _NiMalloc(uiByteCount);
    ::FUN_00403d30(pMap, 0, size << 2);
}

struct FUN_005590b0_s
{
    void* m_vtbl;
    unsigned int m_uiItemCount;
    void* m_data;
    unsigned int m_iElementCount;
    void* InitArray(unsigned int aCount);
};
// @fnv 0x00558da0
FUN_00558da0_S* FUN_00558da0_S::FUN_00558da0(int param_2)
{
    reinterpret_cast<::FUN_005590b0_s *>(this)->InitArray(param_2);
    m_iWordAt00 = &DAT_0102f338;
    return this;
}

void* __cdecl _NiMalloc(unsigned int aSize);
// Sets the vtable, stores aCount and zeroes a newly allocated aCount*4-byte buffer.
// @fnv 0x005590b0
void* FUN_005590b0_s::InitArray(unsigned int aCount)
{
    m_vtbl = &DAT_0102f398;
    m_uiItemCount = aCount;
    m_iElementCount = 0;
    unsigned int aSize = m_uiItemCount * 4;
    m_data = _NiMalloc(aSize);
    ::FUN_00403d30(m_data, 0, m_uiItemCount * 4);
    return this;
}

struct FUN_00544340_Class : public TESObjectCELL
{
    void FUN_00544340(bool set);
};

// Sets or clears bit 0x20 in the byte at offset 0x24, then calls the virtual function at vtable offset 0x48 with argument 2.
// @fnv 0x00544340
void FUN_00544340_Class::FUN_00544340(bool set)
{
    if (set)
        field24 |= 0x20;
    else
        field24 &= ~0x20;
    (*(void(**)(void*, int))(*(char**)this + 0x48))(this, 2);
}

struct FUN_00544440_Class : public TESObjectCELL
{
    void FUN_00544440(bool set);
};

// Sets or clears bit 0 of the byte at offset 0x25, then calls the virtual function at vtable offset 0x48 with argument 2.
// @fnv 0x00544440
void FUN_00544440_Class::FUN_00544440(bool set)
{
    if (set)
        ucCellFlags25 |= 1;
    else
        ucCellFlags25 &= ~1;
    (*(void(**)(void*, int))(*(char**)this + 0x48))(this, 2);
}


struct FUN_005417e0_class
{
    void* FUN_005417e0(unsigned int flags);
};

struct FUN_00541a30_StandIn
{
    void FUN_00541a60();
    void* FUN_00541a30(unsigned int flags);
};


namespace fnv_00543df0 {
struct FormRecordHeader
{
    unsigned int form;
    unsigned int pad0004;
    unsigned int flags;
    unsigned int iFormID;
};

unsigned int kGroupFormType;

struct DoorCellStandIn
{
};

struct FUN_004854e0_shell
{
};

struct FUN_00485b60
{
};

struct CellH
{
};

struct FUN_005441b0_S
{
};

struct FUN_00544210_shell
{
};

struct WorldSpaceVirtual
{
    virtual void f000()
    {}
    virtual void f001()
    {}
    virtual void f002()
    {}
    virtual void f003()
    {}
    virtual void f004()
    {}
    virtual void f005()
    {}
    virtual void f006()
    {}
    virtual void f007()
    {}
    virtual void f008()
    {}
    virtual void f009()
    {}
    virtual void f010()
    {}
    virtual void f011()
    {}
    virtual void f012()
    {}
    virtual void f013()
    {}
    virtual void f014()
    {}
    virtual void f015()
    {}
    virtual void f016()
    {}
    virtual void f017()
    {}
    virtual void f018()
    {}
    virtual void f019()
    {}
    virtual void f020()
    {}
    virtual void f021()
    {}
    virtual void f022()
    {}
    virtual void f023()
    {}
    virtual void f024()
    {}
    virtual void f025()
    {}
    virtual void f026()
    {}
    virtual void f027()
    {}
    virtual void f028()
    {}
    virtual void f029()
    {}
    virtual void f030()
    {}
    virtual void f031()
    {}
    virtual void f032()
    {}
    virtual void f033()
    {}
    virtual void f034()
    {}
    virtual void f035()
    {}
    virtual void f036()
    {}
    virtual void f037()
    {}
    virtual void f038()
    {}
    virtual void f039()
    {}
    virtual void f040()
    {}
    virtual void f041()
    {}
    virtual void f042()
    {}
    virtual void f043()
    {}
    virtual void f044()
    {}
    virtual void f045()
    {}
    virtual void f046()
    {}
    virtual void f047()
    {}
    virtual void f048()
    {}
    virtual void f049()
    {}
    virtual void f050()
    {}
    virtual void f051()
    {}
    virtual void f052()
    {}
    virtual void f053()
    {}
    virtual void f054()
    {}
    virtual void f055()
    {}
    virtual void f056()
    {}
    virtual void f057()
    {}
    virtual void f058()
    {}
    virtual void f059()
    {}
    virtual void f060()
    {}
    virtual void f061()
    {}
    virtual void f062()
    {}
    virtual void f063()
    {}
    virtual void f064()
    {}
    virtual void f065()
    {}
    virtual void f066()
    {}
    virtual void f067()
    {}

    virtual bool FUN(FormRecordHeader* form, bool allowParentGroups, bool currentOnly)
    {
        return false;
    }
};

struct FUN_00543df0_StandIn
{
    bool IsGroupFormAllowed(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly);
};

// @fnv 0x00543df0
bool FUN_00543df0_StandIn::IsGroupFormAllowed(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval = false;
    TESWorldSpace* pparentworld;

    if (apGroupFORM && apGroupFORM->form == kGroupFormType)
    {
        pparentworld = reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<DoorCellStandIn*>(this)))->GetParentWorldSpace();

        switch (apGroupFORM->iFormID)
        {
        case 0:
            if (abAllowParentGroups)
            {
                if (reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
                    bretval = reinterpret_cast<::FUN_004854e0_shell *>((reinterpret_cast<FUN_004854e0_shell*>(this)))->IsGroupFormOfType(
                        (::FormRecordHeader *)(apGroupFORM), abAllowParentGroups, abCurrentOnly);
                else
                    bretval = reinterpret_cast<WorldSpaceVirtual*>(pparentworld)
                                  ->FUN(apGroupFORM, abAllowParentGroups, abCurrentOnly);
            }
            break;

        case 1:
            if (!reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior() &&
                reinterpret_cast<::FUN_00485b60 *>((reinterpret_cast<FUN_00485b60*>(pparentworld)))->FUN_00485be0(apGroupFORM->flags) &&
                (abAllowParentGroups || reinterpret_cast<::FUN_005516c0 *>((reinterpret_cast<CellH*>(this)))->IsCellPersistent()))
                bretval = true;
            break;

        case 2:
        case 4:
            if (!reinterpret_cast<::FUN_005516c0 *>((reinterpret_cast<CellH*>(this)))->IsCellPersistent() && abAllowParentGroups &&
                apGroupFORM->flags == reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<FUN_005441b0_S*>(this)))->FUN_005441b0())
                bretval = true;
            break;

        case 3:
        case 5:
            if (!reinterpret_cast<::FUN_005516c0 *>((reinterpret_cast<CellH*>(this)))->IsCellPersistent() &&
                apGroupFORM->flags == reinterpret_cast<::FUN_00544210_shell *>((reinterpret_cast<FUN_00544210_shell*>(this)))->FUN_00544210())
                bretval = true;
            break;
        }
    }

    return bretval;
}
}  // namespace fnv_00543df0

namespace fnv_00543f50 {
struct FormRecordHeader
{
    unsigned int form;
    unsigned int length;
    unsigned int flags;
    unsigned int iFormID;
    unsigned int m_uiVersionControlInfo;
};

struct TESFileGroup
{
    void* GroupData;
    unsigned int unknown04;
    unsigned int flags;
    unsigned int type;
};

unsigned int kGroupFormType;

struct FUN_005441b0_S
{
};

struct FUN_00544210_shell
{
};

struct CellH
{
};

struct DoorCellAccess
{
};

struct RefAccess
{
};

struct CellStandIn : public TESObjectCELL
{
    void BuildParentGroupForm(FormRecordHeader* apOutGroupFORM, TESFileGroup* apParentGroup);
};

// Fills apOutGroupFORM with a group form type, an ID and a flags value chosen from this cell's state and the parent group's type and flags.
// @fnv 0x00543f50
void CellStandIn::BuildParentGroupForm(FormRecordHeader* apOutGroupFORM, TESFileGroup* apParentGroup)
{
    if (apOutGroupFORM != 0)
    {
        apOutGroupFORM->form = 0;

        if (!IsCellInterior())
        {
            if (apParentGroup != 0)
            {
                switch (apParentGroup->type)
                {
                case 0:
                    if (apParentGroup->flags == *(const unsigned int*)str_01187314)
                    {
                        apOutGroupFORM->form = ::fnv_00543df0::kGroupFormType;
                        apOutGroupFORM->iFormID = 1;
                        apOutGroupFORM->flags =
                            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<RefAccess*>(reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<DoorCellAccess*>(this)))->GetParentWorldSpace())))->FUN_0084e3a0()));
                        apOutGroupFORM->length = 0;
                        apOutGroupFORM->m_uiVersionControlInfo = 0;
                    }
                    break;

                case 1:
                    if (apParentGroup->flags ==
                        ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<RefAccess*>(reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<DoorCellAccess*>(this)))->GetParentWorldSpace())))->FUN_0084e3a0())))
                    {
                        if (!reinterpret_cast<::FUN_005516c0 *>((reinterpret_cast<CellH*>(this)))->IsCellPersistent())
                        {
                            apOutGroupFORM->form = ::fnv_00543df0::kGroupFormType;
                            apOutGroupFORM->iFormID = 4;
                            apOutGroupFORM->flags = reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<FUN_005441b0_S*>(this)))->FUN_005441b0();
                            apOutGroupFORM->length = 0;
                            apOutGroupFORM->m_uiVersionControlInfo = 0;
                        }
                    }
                    break;

                case 4:
                    if (apParentGroup->flags == reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<FUN_005441b0_S*>(this)))->FUN_005441b0())
                    {
                        if (!reinterpret_cast<::FUN_005516c0 *>((reinterpret_cast<CellH*>(this)))->IsCellPersistent())
                        {
                            apOutGroupFORM->form = ::fnv_00543df0::kGroupFormType;
                            apOutGroupFORM->iFormID = 5;
                            apOutGroupFORM->flags = reinterpret_cast<::FUN_00544210_shell *>((reinterpret_cast<FUN_00544210_shell*>(this)))->FUN_00544210();
                            apOutGroupFORM->length = 0;
                            apOutGroupFORM->m_uiVersionControlInfo = 0;
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            if (apParentGroup == 0)
            {
                apOutGroupFORM->form = ::fnv_00543df0::kGroupFormType;
                apOutGroupFORM->iFormID = 0;
                apOutGroupFORM->flags = *(const unsigned int*)(*reinterpret_cast<const char (*)[]>(&::DAT_011872b4));
                apOutGroupFORM->length = 0;
                apOutGroupFORM->m_uiVersionControlInfo = 0;
            }
            else
            {
                switch (apParentGroup->type)
                {
                case 0:
                    if (apParentGroup->flags == *(const unsigned int*)(*reinterpret_cast<const char (*)[]>(&::DAT_011872b4)))
                    {
                        apOutGroupFORM->form = ::fnv_00543df0::kGroupFormType;
                        apOutGroupFORM->iFormID = 2;
                        apOutGroupFORM->flags = reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<FUN_005441b0_S*>(this)))->FUN_005441b0();
                        apOutGroupFORM->length = 0;
                        apOutGroupFORM->m_uiVersionControlInfo = 0;
                    }
                    break;

                case 2:
                    if (apParentGroup->flags == reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<FUN_005441b0_S*>(this)))->FUN_005441b0())
                    {
                        apOutGroupFORM->form = ::fnv_00543df0::kGroupFormType;
                        apOutGroupFORM->iFormID = 3;
                        apOutGroupFORM->flags = reinterpret_cast<::FUN_00544210_shell *>((reinterpret_cast<FUN_00544210_shell*>(this)))->FUN_00544210();
                        apOutGroupFORM->length = 0;
                        apOutGroupFORM->m_uiVersionControlInfo = 0;
                    }
                    break;
                }
            }
        }
    }
}
}  // namespace fnv_00543f50

struct FUN_005451d0_StandIn
{
    void* FUN_005451d0(unsigned int flags);
    void FUN_00545200();
};


// Calls FUN_00545200, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x005451d0
void* FUN_005451d0_StandIn::FUN_005451d0(unsigned int flags)
{
    FUN_00545200();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00545200 {
struct GO
{
    void* pData;
    ~GO();
};

struct ListX
{
    void* pData;
    unsigned int count;
    ~ListX();
};

struct FUN_00558f20
{
    void* pData;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    ~FUN_00558f20();
};

struct FUN_00559020
{
    void* pData;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    ~FUN_00559020();
};

struct FUN_005591d0
{
    void* pData;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    ~FUN_005591d0();
};

struct FUN_00545200 : public GO
{
    ListX list04;
    FUN_00558f20 member0c;
    FUN_00559020 member1c;
    FUN_00558f20 member2c;
    FUN_005591d0 member3c;
    ListX list4c;
    ListX list54;
    ListX list5c;

    ~FUN_00545200();
};

// Destructor for the object; the body is empty, so member destructors run implicitly.
// @fnv 0x00545200
FUN_00545200::~FUN_00545200()
{}
}  // namespace fnv_00545200

namespace fnv_00545560 {
struct G2
{
    void AddHead(std::intptr_t*);
};

struct FUN_00545560Class
{
    unsigned char pad[0xc4];
    void* p;

    void FUN_00545560(std::intptr_t);
};

// If p is set, calls AddHead on the G2 object at p+0x4c with the address of arg.
// @fnv 0x00545560
void FUN_00545560Class::FUN_00545560(std::intptr_t iValue)
{
    if (p)
        reinterpret_cast<G2*>(reinterpret_cast<unsigned char*>(p) + 0x4c)->AddHead(&iValue);
}
}  // namespace fnv_00545560

namespace fnv_00545590 {
struct RefList
{
};

struct FUN_00545590_Owner
{
    unsigned char padding[0x4c];
    RefList list;
};

struct FUN_00545590_Class
{
    unsigned char padding[0xc4];
    FUN_00545590_Owner* owner;

    void FUN_00545590(unsigned int* value);
};

// If owner is set, forwards value to the owner's list via FUN_00905330.
// @fnv 0x00545590
void FUN_00545590_Class::FUN_00545590(unsigned int* value)
{
    if (owner)
        reinterpret_cast<::ItemChangeListNode *>(&(owner->list))->FUN_00905330((::InventoryStackRecord *const &)(reinterpret_cast<unsigned int&>(value)));
}
}  // namespace fnv_00545590

namespace fnv_005456b0 {
struct G2
{
    void AddHead(std::intptr_t*);
};

struct FUN_005456b0StandIn
{
    char pad_0000[0xC4];
    G2* pG2;

    void AddValueToHead(std::intptr_t);
};

// If pG2 is non-null, calls AddHead on the G2 at offset 0x5C of pG2, passing the address of value.
// @fnv 0x005456b0
void FUN_005456b0StandIn::AddValueToHead(std::intptr_t value)
{
    if (pG2 != 0)
        reinterpret_cast<G2*>(reinterpret_cast<char*>(pG2) + 0x5C)->AddHead(&value);
}
}  // namespace fnv_005456b0

class FUN_00905330ContNode
{
  public:
};

class FUN_00905330RefList
{
  public:
    unsigned char padding[0x5c];
    FUN_00905330ContNode node;
};

class FUN_005456e0StandIn
{
  public:
    void FUN_005456e0(std::intptr_t);

  private:
    unsigned char padding[0xc4];
    FUN_00905330RefList* pRefList;
};

// If pRefList is set, forwards the address of value to the node's FUN_00905330 method.
// @fnv 0x005456e0
void FUN_005456e0StandIn::FUN_005456e0(std::intptr_t value)
{
    if (pRefList)
        reinterpret_cast<::ItemChangeListNode *>(&(pRefList->node))->FUN_00905330((*(::InventoryStackRecord *const *)(&value)));
}

namespace fnv_00545c10 {
class GO
{
  public:
    operator unsigned int() const;
    void operator=(void* value);
};

class NiAdditionalGeometryData
{
  public:
    static void* __cdecl GetShadowSceneNodeForIndex(int index);
};

struct FUN_00454b30_class
{
};

struct FUN_00b5ddf0_class
{
    void FUN_00b5ddf0(int value);
};

struct FUN_00583270_class
{
};

struct FUN_00545c10_class
{
    char padToGO[0xD4];
    GO go;

    void ClearAdditionalGeometryData();
};

// @fnv 0x00545c10
void FUN_00545c10_class::ClearAdditionalGeometryData()
{
    if (go.operator unsigned int())
    {
        if (((TESObjectCELL*)this)->IsCellInterior())
        {
            if (reinterpret_cast<unsigned int>(
                    reinterpret_cast<::FUN_00454b30_class *>((reinterpret_cast<FUN_00454b30_class*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))->FUN_00454b30()) == go.operator unsigned int())
            {
                reinterpret_cast<::fnv_00b5ddf0::LocalTarget *>((reinterpret_cast<FUN_00b5ddf0_class*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))->FUN_00b5ddf0((::fnv_00b5ddf0::LocalContext *)(0));
            }
        }

        go.operator=(0);

        if (((TESObjectCELL*)this)->GetParentWorldSpace())
        {
            reinterpret_cast<::FUN_00583270_cls *>((reinterpret_cast<FUN_00583270_class*>(((TESObjectCELL*)this)->GetParentWorldSpace())))->FUN_00583270();
        }
    }
}
}  // namespace fnv_00545c10

namespace fnv_00546b10 {
struct BGSSaveLoadGame
{
  public:
};


struct FUN_00421850_shell
{
};

struct FUN_00546b10_virtuals
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18(unsigned int value);
    virtual void f19(unsigned int value);
};

struct FUN_00546b10_class : public TESObjectCELL
{
    void UpdateCellExtraData(BSExtraData* value, bool flag);
};

// @fnv 0x00546b10
void FUN_00546b10_class::UpdateCellExtraData(BSExtraData* pExtraData, bool flag)
{
    if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00546b10::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() || pExtraData == 0 || flag)
    {
        reinterpret_cast<::FUN_00421850_shell *>((reinterpret_cast<FUN_00421850_shell*>(((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->GetExtraDataList())))))->FUN_00421850(pExtraData);
    }

    if (pExtraData != 0)
    {
        reinterpret_cast<FUN_00546b10_virtuals*>(this)->f18(0x40000000);

        if (!reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
        {
            int x = reinterpret_cast<TESObjectCELL*>(this)->GetCellGridX();
            int y = reinterpret_cast<TESObjectCELL*>(this)->GetCellGridY();

            if (x <= 127 && x >= -128 && y <= 127 && y >= -128)
            {
                reinterpret_cast<FUN_00546b10_virtuals*>(this)->f18(0x20000000);
            }
            else
            {
                reinterpret_cast<FUN_00546b10_virtuals*>(this)->f18(0x10000000);
            }
        }
    }
    else
    {
        reinterpret_cast<FUN_00546b10_virtuals*>(this)->f19(0x70000000);
    }
}
}  // namespace fnv_00546b10

struct FUN_0041c580_Class
{
};

struct FUN_005477f0_Class : public TESObjectCELL
{
    int FUN_005477f0(std::intptr_t arg1, std::intptr_t arg2);
};

// @fnv 0x005477f0
int FUN_005477f0_Class::FUN_005477f0(std::intptr_t arg1, std::intptr_t arg2)
{
    if (IsCellInterior())
        return 0;

    return ((int)(reinterpret_cast<::Hold580 *>((reinterpret_cast<FUN_0041c580_Class*>(
               ((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->GetExtraDataList())))))->GetExtraDataNameAndPtr((const char **)(arg1), (unsigned int **)(arg2))));
}

namespace fnv_00548740 {
class TESForm
{
  public:
};

struct CellH
{
};

struct BSOcclusionPlane
{
};

struct LLD_Cell
{
    void RemoveReference(TESObjectREFR* reference);
};

struct G2
{
    void AddHead(int* value);
};

struct ObjectReferenceHelper
{
};

struct ExtraDataListHelper
{
};

struct TESDataHandlerHelper
{
};

struct TESObjectREFRHelper : public TESObjectREFR
{
};

struct AddLightHelper
{
};

struct VirtualSlots
{
    virtual void slot0()
    {}
    virtual void slot1()
    {}
    virtual void slot2()
    {}
    virtual void slot3()
    {}
    virtual void slot4()
    {}
    virtual void slot5()
    {}
    virtual void slot6()
    {}
    virtual void slot7()
    {}
    virtual void slot8()
    {}
    virtual void slot9()
    {}
    virtual void slot10()
    {}
    virtual void slot11()
    {}
    virtual void slot12()
    {}
    virtual void slot13()
    {}
    virtual void slot14()
    {}
    virtual void slot15()
    {}
    virtual void slot16()
    {}
    virtual void slot17()
    {}
    virtual void slot18()
    {}
    virtual void slot19()
    {}
    virtual void slot20()
    {}
    virtual void slot21()
    {}
    virtual void slot22()
    {}
    virtual void slot23()
    {}
    virtual void slot24()
    {}
    virtual void slot25()
    {}
    virtual void slot26()
    {}
    virtual void slot27()
    {}
    virtual void slot28()
    {}
    virtual void slot29()
    {}
    virtual void slot30()
    {}
    virtual void slot31()
    {}
    virtual void slot32()
    {}
    virtual void slot33()
    {}
    virtual void slot34()
    {}
    virtual void slot35()
    {}
    virtual void slot36()
    {}
    virtual void slot37()
    {}
    virtual void slot38()
    {}
    virtual void slot39()
    {}
    virtual void slot40()
    {}
    virtual void slot41()
    {}
    virtual void slot42()
    {}
    virtual void slot43()
    {}
    virtual void slot44()
    {}
    virtual void slot45()
    {}
    virtual void slot46()
    {}
    virtual void slot47()
    {}
    virtual void slot48()
    {}
    virtual void slot49()
    {}
    virtual void slot50(int value)
    {}
    virtual void slot51()
    {}
    virtual void slot52()
    {}
    virtual void slot53()
    {}
    virtual void slot54()
    {}
    virtual void slot55()
    {}
    virtual void slot56()
    {}
    virtual void slot57()
    {}
    virtual void slot58()
    {}
    virtual void slot59()
    {}
    virtual void slot60()
    {}
    virtual void slot61()
    {}
    virtual void slot62()
    {}
    virtual void slot63()
    {}
    virtual void slot64()
    {}
    virtual void slot65()
    {}
    virtual void slot66()
    {}
    virtual void slot67()
    {}
    virtual void slot68()
    {}
    virtual void slot69()
    {}
    virtual void slot70()
    {}
    virtual void slot71()
    {}
    virtual void slot72()
    {}
    virtual void slot73()
    {}
    virtual void slot74()
    {}
    virtual void slot75()
    {}
    virtual void slot76()
    {}
    virtual void slot77()
    {}
    virtual void slot78()
    {}
    virtual void slot79()
    {}
    virtual void slot80()
    {}
    virtual void slot81()
    {}
    virtual void slot82()
    {}
    virtual void slot83()
    {}
    virtual void slot84()
    {}
    virtual void slot85()
    {}
    virtual void slot86()
    {}
    virtual void slot87()
    {}
    virtual void slot88()
    {}
    virtual void slot89()
    {}
    virtual void slot90()
    {}
    virtual void slot91()
    {}
    virtual void slot92()
    {}
    virtual void slot93()
    {}
    virtual void slot94()
    {}
    virtual void slot95()
    {}
    virtual void slot96()
    {}
    virtual void slot97()
    {}
    virtual void slot98()
    {}
    virtual void slot99()
    {}
    virtual void slot100()
    {}
    virtual void slot101()
    {}
    virtual void slot102()
    {}
    virtual void slot103()
    {}
    virtual void slot104()
    {}
    virtual void slot105()
    {}
    virtual void slot106()
    {}
    virtual void slot107()
    {}
    virtual void slot108()
    {}
    virtual void slot109()
    {}
    virtual void slot110()
    {}
    virtual void slot111()
    {}
    virtual void slot112()
    {}
    virtual void slot113()
    {}
    virtual void slot114()
    {}
    virtual void slot115()
    {}
    virtual void slot116()
    {}
    virtual void slot117()
    {}
    virtual void slot118()
    {}
    virtual void slot119()
    {}
    virtual void slot120()
    {}
    virtual void slot121()
    {}
    virtual void slot122()
    {}
    virtual void slot123()
    {}
    virtual void slot124()
    {}
    virtual void slot125()
    {}
    virtual void slot126()
    {}
    virtual void slot127()
    {}
    virtual void slot128()
    {}
    virtual void slot129()
    {}
    virtual void slot130()
    {}
    virtual void slot131()
    {}
    virtual void slot132()
    {}
    virtual void slot133()
    {}
    virtual void slot134()
    {}
    virtual void slot135()
    {}
    virtual void slot136()
    {}
    virtual void slot137()
    {}
    virtual void slot138(TESObjectCELL* cell)
    {}
};

class DH;

struct FUN_00548740_Cell : public TESObjectCELL
{
    void FUN_00548740(TESObjectREFR* apRef);
};

// @fnv 0x00548740
void FUN_00548740_Cell::FUN_00548740(TESObjectREFR* apRef)
{
    if (!apRef || !((::fnv_00548740::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<ObjectReferenceHelper*>(apRef)))->FUN_007af430())))
        return;

    if (reinterpret_cast<::FUN_005516c0 *>((reinterpret_cast<CellH*>(this)))->IsCellPersistent())
    {
        TESObjectCELL::CellRefLockEnter();
        reinterpret_cast<G2*>(((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0())))->AddHead(reinterpret_cast<int*>(&apRef));
        ::FUN_00541ae0((char *)this);

        reinterpret_cast<::FUN_0041d390_shell *>((reinterpret_cast<ExtraDataListHelper*>(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reinterpret_cast<TESObjectREFRHelper*>(apRef)))->FUN_005d43c0())))))->FUN_0041d390(this);

        if (!reinterpret_cast<::FUN_004516b0_shell *>((reinterpret_cast<TESDataHandlerHelper*>((*reinterpret_cast<::fnv_00548740::DH * *>(&::g_dataHandler)))))->FUN_004516b0())
            reinterpret_cast<VirtualSlots*>(this)->slot50(1);

        return;
    }

    LLD_Cell* pOldParent;
    pOldParent = reinterpret_cast<LLD_Cell*>((reinterpret_cast<::LowProcess *>((void *)(reinterpret_cast<BSOcclusionPlane*>(apRef)))->GetTarget()));

    if (pOldParent)
        pOldParent->RemoveReference(apRef);

    TESObjectCELL::CellRefLockEnter();
    reinterpret_cast<G2*>(((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0())))->AddHead(reinterpret_cast<int*>(&apRef));
    reinterpret_cast<VirtualSlots*>(apRef)->slot138(this);
    ::FUN_00541ae0((char *)this);

    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(reinterpret_cast<TESForm*>(apRef)))->FUN_004077c0() &&
        !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((reinterpret_cast<TESObjectREFRHelper*>(apRef)))->FUN_005653d0() &&
        !reinterpret_cast<::FUN_004516b0_shell *>((reinterpret_cast<TESDataHandlerHelper*>((*reinterpret_cast<::fnv_00548740::DH * *>(&::g_dataHandler)))))->FUN_004516b0())
        reinterpret_cast<VirtualSlots*>(this)->slot50(1);

    reinterpret_cast<::fnv_005728c0::FUN_005728c0_shell *>((reinterpret_cast<AddLightHelper*>(apRef)))->FUN_005728c0(0);
}
}  // namespace fnv_00548740

struct FUN_0096dcb0_shell
{
};


struct FUN_0054af80_shell : public TESObjectCELL
{
    void LockAndProcessPerks();
};

// Enters the cell ref lock, processes the perk entry list from FUN_009604f0, then leaves the lock.
// @fnv 0x0054af80
void FUN_0054af80_shell::LockAndProcessPerks()
{
    CellRefLockEnter();
    reinterpret_cast<::fnv_0096dcb0::Owner96 *>(&((*reinterpret_cast<::FUN_0096dcb0_shell *>(&::g_011e0e80))))->UpdateActorsFromList((::fnv_0096dcb0::FUN_0096a2d0 *)(::BSSimpleList< ::BGSPerkEntry *> *)(((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))));
    ::FUN_00541ae0((char *)this);
}

namespace fnv_0054e750 {
class GO
{
  public:
    int value;
    GO(int);
    ~GO();
    void operator=(void*);
    operator unsigned int() const;
};

class Helper62d0
{
  public:
    void* operator=(void const*);
};

class TextureReceiver
{
  public:
    void FUN_0054e710();
};

struct FUN_0054e750Class : public TESObjectCELL
{
  public:
    void FUN_0054f500(void*, unsigned int, GO*);
    void FUN_0054e750(void*, unsigned int, Helper62d0*);
};

// @fnv 0x0054e750
void FUN_0054e750Class::FUN_0054e750(void* arg1, unsigned int arg2, Helper62d0* pOut)
{
    GO result(0);
    const char* name = "GetInteriorLocalMapTexture";
    if (IsCellInterior())
    {
        GO texture(0);
        this->FUN_0054f500(arg1, arg2, &texture);
        result.operator=(((::fnv_0054e750::TextureReceiver *)(std::uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((reinterpret_cast<TextureReceiver*>(texture.operator unsigned int())))->FUN_004bc320(0))));
        reinterpret_cast<TextureReceiver*>(texture.operator unsigned int())->FUN_0054e710();
    }
    pOut->operator=(&result);
}
}  // namespace fnv_0054e750

struct FormRecordHeader
{
    unsigned int form;
    unsigned int pad1;
    unsigned int pad2;
    unsigned int iFormID;
};

struct TESFile_Helper
{
};

struct TESFile_NextGroup
{
};

struct TESFile_GetTESForm
{
};

unsigned int kGroupFormType;

// Checks that apFile's record header is a CELL record, walks its groups, and returns true if a form with type 0x42 is found.
// @fnv 0x00550f60
bool FUN_00550f60(TESFile* apFile)
{
    FormRecordHeader* pRecordHeader;
    bool bretval;

    if (!apFile)
        return false;

    pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
    if (pRecordHeader->form != *reinterpret_cast<const unsigned int*>("CELL:"))
        return false;

    if (!reinterpret_cast<::FUN_00472150_shell *>((reinterpret_cast<TESFile_Helper*>(apFile)))->FUN_00472150(true))
        return false;

    pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
    if (!::FUN_00554810((::Obj5548 *)(pRecordHeader)))
        return false;

    if (!reinterpret_cast<::FUN_00472150_shell *>((reinterpret_cast<TESFile_Helper*>(apFile)))->FUN_00472150(true))
        return false;

    pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
    if (!::FUN_00554810((::Obj5548 *)(pRecordHeader)))
        return false;

    if (pRecordHeader->form != ::fnv_00543df0::kGroupFormType)
        return false;

    if (pRecordHeader->iFormID == 8)
    {
        reinterpret_cast<::TESFile *>((reinterpret_cast<TESFile_NextGroup*>(apFile)))->IsGroupOpen();
        pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
        if (!::FUN_00554810((::Obj5548 *)(pRecordHeader)))
            return false;
    }

    if (pRecordHeader->iFormID != 9)
        return false;

    reinterpret_cast<::FUN_00472150_shell *>((reinterpret_cast<TESFile_Helper*>(apFile)))->FUN_00472150(true);
    bretval = false;

    while (::FUN_005548a0(((unsigned int)(reinterpret_cast<::FUN_00472660_shell *>((reinterpret_cast<TESFile_GetTESForm*>(apFile)))->FUN_00472660()))))
    {
        if (((unsigned int)(reinterpret_cast<::FUN_00472660_shell *>((reinterpret_cast<TESFile_GetTESForm*>(apFile)))->FUN_00472660())) == 0x42)
        {
            bretval = true;
            break;
        }

        reinterpret_cast<::FUN_00472150_shell *>((reinterpret_cast<TESFile_Helper*>(apFile)))->FUN_00472150(true);
    }

    return bretval;
}

struct NiUpdateData
{
    float fTime;
    bool bFlag1;
    bool bFlag2;
    int iPadding;

    NiUpdateData(float time, bool flag1, bool flag2);
};

struct _FakeNiAVObject
{
    virtual void FUN_01() = 0;
    virtual void FUN_02() = 0;
    virtual void FUN_03() = 0;
    virtual NiNode* GetNode() = 0;
    virtual void FUN_05() = 0;
    virtual void FUN_06() = 0;
    virtual void FUN_07() = 0;
    virtual void FUN_08() = 0;
    virtual void FUN_09() = 0;
    virtual void FUN_10() = 0;
    virtual void FUN_11() = 0;
    virtual void FUN_12() = 0;
    virtual NiNode* GetUpdateNode() = 0;
};

struct _FakeNiNode
{
    unsigned int FUN_0043b480();
};

struct NN_00605d70
{
    void Update(const NiUpdateData& data);
};


void __cdecl UpdateSceneGraph(NiAVObject* object);

// @fnv 0x005526f0
void __cdecl UpdateSceneGraph(NiAVObject* object)
{
    if (object)
    {
        NiNode* node = reinterpret_cast<_FakeNiAVObject*>(object)->GetNode();
        if (node)
        {
            unsigned int count = reinterpret_cast<_FakeNiNode*>(node)->FUN_0043b480();
            for (unsigned int i = 0; i < count; ++i)
                UpdateSceneGraph(node->GetAt(i));
        }
        else
        {
            NiNode* updateNode = reinterpret_cast<_FakeNiAVObject*>(object)->GetUpdateNode();
            if (updateNode)
            {
                NiUpdateData updateData(::fnv_00563f30::DAT_011c3c08, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NN_00605d70*>(updateNode)))->FUN_00a59c60((std::intptr_t)&(updateData));
            }
        }
    }
}

namespace fnv_00555630 {
class FNStub
{
  public:
    char* GetFullName();
};

class FormChangeMask
{
  public:
    FormChangeMask(unsigned int value) : m_uiFilterValue(value)
    {}
    FormChangeMask(const FormChangeMask& rhs) : m_uiFilterValue(rhs.m_uiFilterValue)
    {}

    operator bool() const;

  private:
    unsigned int m_uiFilterValue;
};

class SaveFormIDHelper
{
  public:
};

struct BGSLoadFormBuffer : public SaveFormIDHelper
{
  public:
    FormChangeMask GetChangeFlags();
};

class BGSSaveGameBuffer : public BGSLoadFormBuffer
{
  public:
};

struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
  public:
};

class SeenData
{
  public:
    virtual void FUN_0()
    {}
    virtual void FUN_1()
    {}
    virtual void FUN_2()
    {}
    virtual void Save(BGSSaveFormBuffer*)
    {}
};

class FUN_00484d60_holder
{
  public:
};

class FUN_00555bc0_shell
{
  public:
};

struct FUN_00555630_holder : public DoorCell
{
    void FUN_00555630(BGSSaveFormBuffer*);
};

// Saves the cell's flags, seen data, full name and owner to the save buffer when the corresponding change flags are set.
// @fnv 0x00555630
void FUN_00555630_holder::FUN_00555630(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned char ctempCellFlags;

    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged((::BGSSaveFormBuffer *)(apSaveGameBuffer));

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555630::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags()))->FUN_004280f0(2))
    {
        ctempCellFlags = (unsigned char)(reinterpret_cast<::TESObjectCELL*>(this)->field24 & 0x60);
        ctempCellFlags |= reinterpret_cast<::TESObjectCELL*>(this)->ucCellFlags25;
        reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&ctempCellFlags, 1, 0);
    }

    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555630::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags()))->FUN_004280f0(0x80000000))
    {
        ((::fnv_00555630::SeenData *)(reinterpret_cast<::FUN_00555bc0_shell *>((reinterpret_cast<FUN_00555bc0_shell*>(this)))->FindSeenData()))->Save(apSaveGameBuffer);
    }

    {
        const char* pfullname;
        TESForm* powner;

        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555630::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags()))->FUN_004280f0(4))
        {
            pfullname = ((char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(reinterpret_cast<::TESObjectCELL*>(this)->kFullName)))->FUN_00408da0()));
            reinterpret_cast<::FUN_00865e70_shell *>((apSaveGameBuffer))->FUN_00865e70(pfullname, 0);
        }

        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_00555630::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags()))->FUN_004280f0(8))
        {
            powner = reinterpret_cast<DoorCell*>(this)->GetOwner();
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(powner), 0);
        }
    }
}
}  // namespace fnv_00555630

namespace fnv_005578f0 {
struct NiFixedStr
{
    operator char const*();
};

struct SeqObj
{
};

struct _FakeNiNode
{
    unsigned int FUN_0043b480();
};

extern char str_0102f154[];

struct FUN_005578f0_Node
{
    virtual void D00() = 0;
    virtual void D01() = 0;
    virtual void D02() = 0;
    virtual void D03() = 0;
    virtual void D04() = 0;
    virtual void D05() = 0;
    virtual void D06() = 0;
    virtual void D07() = 0;
    virtual void D08() = 0;
    virtual void D09() = 0;
    virtual void D10() = 0;
    virtual void D11() = 0;
    virtual void D12() = 0;
    virtual void D13() = 0;
    virtual void D14() = 0;
    virtual void D15() = 0;
    virtual void D16() = 0;
    virtual void D17() = 0;
    virtual void D18() = 0;
    virtual void D19() = 0;
    virtual void D20() = 0;
    virtual void D21() = 0;
    virtual void D22() = 0;
    virtual void D23() = 0;
    virtual void D24() = 0;
    virtual void D25() = 0;
    virtual void D26() = 0;
    virtual void D27() = 0;
    virtual void D28() = 0;
    virtual void D29() = 0;
    virtual void D30() = 0;
    virtual void D31() = 0;
    virtual void D32() = 0;
    virtual void D33() = 0;
    virtual void D34() = 0;
    virtual void D35() = 0;
    virtual void D36() = 0;
    virtual void D37() = 0;
    virtual void D38() = 0;
    virtual void D39() = 0;
    virtual void D40() = 0;
    virtual void D41() = 0;
    virtual void D42() = 0;
    virtual void D43() = 0;
    virtual void D44() = 0;
    virtual void D45() = 0;
    virtual void D46() = 0;
    virtual void D47() = 0;
    virtual void D48() = 0;
    virtual void D49() = 0;
    virtual void D50() = 0;
    virtual void D51() = 0;
    virtual void D52() = 0;
    virtual void D53() = 0;
    virtual void D54() = 0;
    virtual void D55() = 0;
    virtual void D56() = 0;
    virtual void D57() = 0;
    virtual void D58() = 0;
    virtual void D59() = 0;
    virtual void RemoveLocationMarker(unsigned int index)
    {}
};

struct FUN_005578f0_Class
{
    void FUN_005578f0();
};

// @fnv 0x005578f0
void FUN_005578f0_Class::FUN_005578f0()
{
    NiNode* pmarkerNode = reinterpret_cast<NiNode*>(::FUN_00524cf0(reinterpret_cast<TESObjectCELL*>(this)));
    unsigned int i;

    if (!pmarkerNode)
    {
    }
    else
    {
        for (i = 0; i < reinterpret_cast<_FakeNiNode*>(pmarkerNode)->FUN_0043b480(); ++i)
        {
            NiAVObject* pChild = pmarkerNode->GetAt(i);
            if (pChild)
            {
                const char* pChildName = (*(::fnv_005578f0::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((reinterpret_cast<SeqObj*>(pChild)))->GetLinkToList())).operator char const*();
                if (pChildName)
                {
                    if (!::FUN_00408b20(pChildName, str_0102f154))
                    {
                        reinterpret_cast<FUN_005578f0_Node*>(pmarkerNode)->RemoveLocationMarker(i);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_005578f0


struct FUN_00558df0_StandIn
{
    void FUN_00558f20();
    void* FUN_00558df0(unsigned int flags);
};


struct FUN_00558e20_StandIn
{
    void* FUN_00558e20(unsigned int flags);
    void FUN_00559020();
};


struct FUN_00558e50_StandIn
{
    void FUN_005591d0();
    void* FUN_00558e50(unsigned int flags);
};

namespace fnv_0062d640 {
struct ArrSI
{
    unsigned int GetFlags(void);
};

struct hkpEntity : ArrSI
{
};

struct hkpEntityListener
{
    virtual void FUN_004f0000(hkpEntity*);
    virtual void FUN_004f0004(hkpEntity*);
    virtual void FUN_004f0008(hkpEntity*);

    void NotifyEntityIfFlagged(hkpEntity*);
};

unsigned int ArrSI::GetFlags(void)
{
    return 0;
}

void hkpEntityListener::FUN_004f0000(hkpEntity*)
{}

void hkpEntityListener::FUN_004f0004(hkpEntity*)
{}

void hkpEntityListener::FUN_004f0008(hkpEntity*)
{}

// If entity->GetFlags() is nonzero, calls FUN_004f0008 then FUN_004f0004 on the entity.
// @fnv 0x0062d640
void hkpEntityListener::NotifyEntityIfFlagged(hkpEntity* entity)
{
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((entity))->GetName())) != 0)
    {
        FUN_004f0008(entity);
        FUN_004f0004(entity);
    }
}
}  // namespace fnv_0062d640

struct SubObj_0045c9a0
{
};

class GuardedSubHolder
{
  public:
    char pad[0x20];
    SubObj_0045c9a0* sub;
    int FUN_00535af0(int arg);
};

// If sub is non-null and arg is less than 4, forwards arg to sub's GetCellNodeAt and returns its result; otherwise returns 0.
// @fnv 0x00535af0
int GuardedSubHolder::FUN_00535af0(int arg)
{
    std::intptr_t result = 0;
    if (this->sub != 0 && arg < 4)
    {
        result = ((std::intptr_t)(reinterpret_cast<::FUN_0045c9a0_shell *>((this->sub))->GetCellNodeAt(arg)));
    }
    return result;
}

struct CellFileStub;
struct CellFormStub
{
};
struct CellGroupHeader
{
    unsigned int type;
    unsigned int size;
    unsigned int label;
    unsigned int groupType;
    unsigned int stamp;
    unsigned int unk14;
};
struct CellFileStub
{
};
struct CellRefNodeStub
{
    bool IsEmpty8256d0();
};
struct CellVTableStub
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
    virtual void v10();
    virtual void v11();
};
extern unsigned int kGroupFormType;

struct FUN_00541e80_shell : public TESObjectCELL
{
    bool SaveCellToFile(CellFileStub* file);
};

struct CellData20;

struct ParamCls
{
  public:
};

struct CellData20
{
  public:
    void* m_ptr;
    unsigned int m_zeroA;
    unsigned int m_result;
    unsigned int m_six;
    unsigned int m_zeroB;
};

struct CellX
{
  public:
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
    virtual void v10();
    virtual void v11();
    unsigned int FUN_0084e3a0();
    bool ProcessCell(ParamCls* param);
};

bool FUN_00425fd0(void* pThis);
void* FUN_0054ddd0(void* pThis);

// @fnv 0x005444c0
bool FUN_005444c0(TESObjectCELL* pThis)
{
    unsigned int flags;
    void* holder;
    if (reinterpret_cast<::TESObjectCELL *>((pThis))->IsCellInterior() != 0)
    {
        flags = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pThis))->GetName()));
        if ((flags & 0x80000) != 0)
        {
            return true;
        }
    }
    else
    {
        holder = ((void *)(reinterpret_cast<::TESObjectCELL *>((pThis))->GetParentWorldSpace()));
        if (holder != 0)
        {
            return ((bool)(reinterpret_cast<::ArrSI *>((holder))->HasFlag80000()));
        }
    }
    return false;
}

struct CellFlagHolder
{
    char unk00[8];
    signed char unk08;
};

struct FUN_00544590_cls : public TESObjectCELL
{
    bool FUN_00544590(unsigned int bit);
};

// Returns true if the flag holder's byte at offset 8 has the bit for the given index set, otherwise false.
// @fnv 0x00544590
bool FUN_00544590_cls::FUN_00544590(unsigned int bit)
{
    CellFlagHolder* holder = (CellFlagHolder*)reinterpret_cast<::FUN_005445d0_shell *>(this)->FUN_005445d0();
    if (holder != 0)
    {
        int mask = 1 << bit;
        if ((holder->unk08 & mask) != 0)
        {
            return true;
        }
    }
    return false;
}

struct FUN_005454f0_cls;

struct CellRefResolver
{
};

struct CellRefProbe
{
    int Probe();
};

struct CellRefLookup
{
};

struct CellRefAttach
{
    void Attach(void* ref);
};

struct FUN_005454f0_cls
{
    char pad00[0xc4];
    void* m_pC4;
    void FUN_005454f0(void* ref);
};

// If m_pC4 is set, resolves ref and attaches it to the +0x2c list when its probe equals 0x1e, otherwise attaches the looked-up pointer to the +0x1c list.
// @fnv 0x005454f0
void FUN_005454f0_cls::FUN_005454f0(void* ref)
{
    if (m_pC4 != 0)
    {
        if (((CellRefProbe*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((CellRefResolver*)ref)))->FUN_007af430())))->Probe() == 0x1e)
        {
            reinterpret_cast<::NiTMap_S *>((((CellRefAttach*)((char*)m_pC4 + 0x2c))))->RemoveKey((std::uintptr_t)(ref));
        }
        else
        {
            void* p = ((void *)(reinterpret_cast<::FUN_00569580_shell *>((((CellRefLookup*)ref)))->GetOwnerForm()));
            if (p != 0)
            {
                reinterpret_cast<::NiTMap_S *>((((CellRefAttach*)((char*)m_pC4 + 0x1c))))->RemoveKey((std::uintptr_t)(p));
            }
        }
    }
}

struct FUN_005455c0_ref;
struct FUN_005455c0_node;
struct FUN_005455c0_item
{
    unsigned int m_00;
};
struct FUN_005455c0_ref
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual void* v48(unsigned int flags);
};
struct FUN_005455c0_node
{
    unsigned char FUN_008256d0();
    FUN_005455c0_item* FUN_006815c0();
    void FUN_005ae3d0(FUN_005455c0_ref** arg);
};
class FUN_005455c0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    char* m_c4;
    void FUN_005455c0(FUN_005455c0_ref* ref);
};

// @fnv 0x005455c0
void FUN_005455c0_cls::FUN_005455c0(FUN_005455c0_ref* ref)
{
    if (m_c4 != 0)
    {
        FUN_005455c0_node* cur = (FUN_005455c0_node*)(m_c4 + 0x54);
        FUN_005455c0_node* prev = 0;
        while (cur != 0 && !cur->FUN_008256d0())
        {
            if (((::FUN_005455c0_item *)((void *)(cur)))->m_00 == (std::uintptr_t)ref)
            {
                return;
            }
            prev = cur;
            cur = ((::FUN_005455c0_node *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
        }
        ref->v48(0x4000000);
        if (prev != 0)
        {
            reinterpret_cast<::Callees *>((prev))->FUN_00905820(&ref);
        }
        else
        {
            ((FUN_005455c0_node*)(m_c4 + 0x54))->FUN_005ae3d0(&ref);
        }
    }
}

struct NiPoint3S
{
    float x;
    float y;
    float z;
};
struct Mat9S
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
};

struct FaceAnimData;
struct FaceGenNode;

struct AnimController
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual int GetType();
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
    virtual void SetTarget(void* target);
};

struct FaceAnimData
{
    void SetController(AnimController* c);
};

struct FaceGenNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual void Update();
    int n04;
    int n08;
    int n0c;
    int n10;
    int n14;
    int n18;
    int n1c;
    int n20;
    int n24;
    int n28;
    int n2c;
    int n30;
    int n34;
    int n38;
    int n3c;
    int n40;
    int n44;
    int n48;
    int n4c;
    int n50;
    int n54;
    int n58;
    int n5c;
    int n60;
    int n64;
    int n68;
    int n6c;
    int n70;
    int n74;
    int n78;
    int n7c;
    int n80;
    int n84;
    int n88;
    int n8c;
    int n90;
    int n94;
    int n98;
    int n9c;
    int na0;
    int na4;
    int na8;
    int nac;
    int nb0;
    FaceGenNode();
};

struct Primitive
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual AnimController* CreateController(NiPoint3S* pt);
};

struct ModelHolder
{
    FaceGenNode* GetNode();
};

struct RefForm;

struct NodePtr
{
    FaceGenNode* obj;
    NodePtr(FaceGenNode* p);
    ~NodePtr();
};

struct NodeList
{
};

struct CellUnkC4
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
    NodeList list;
};

struct RefForm
{
    virtual void r000();
    virtual void r004();
    virtual void r008();
    virtual void r00c();
    virtual void r010();
    virtual void r014();
    virtual void r018();
    virtual void r01c();
    virtual void r020();
    virtual void r024();
    virtual void r028();
    virtual void r02c();
    virtual void r030();
    virtual void r034();
    virtual void r038();
    virtual void r03c();
    virtual void r040();
    virtual void r044();
    virtual void r048();
    virtual void r04c();
    virtual void r050();
    virtual void r054();
    virtual void r058();
    virtual void r05c();
    virtual void r060();
    virtual void r064();
    virtual void r068();
    virtual void r06c();
    virtual void r070();
    virtual void r074();
    virtual void r078();
    virtual void r07c();
    virtual void r080();
    virtual void r084();
    virtual void r088();
    virtual void r08c();
    virtual void r090();
    virtual void r094();
    virtual void r098();
    virtual void r09c();
    virtual void r0a0();
    virtual void r0a4();
    virtual void r0a8();
    virtual void r0ac();
    virtual void r0b0();
    virtual void r0b4();
    virtual void r0b8();
    virtual void r0bc();
    virtual void r0c0();
    virtual void r0c4();
    virtual void r0c8();
    virtual void r0cc();
    virtual void r0d0();
    virtual void r0d4();
    virtual void r0d8();
    virtual void r0dc();
    virtual void r0e0();
    virtual void r0e4();
    virtual void r0e8();
    virtual void r0ec();
    virtual void r0f0();
    virtual void r0f4();
    virtual void r0f8();
    virtual void r0fc();
    virtual void r100();
    virtual void r104();
    virtual void r108();
    virtual void r10c();
    virtual void r110();
    virtual void r114();
    virtual void r118();
    virtual void r11c();
    virtual void r120();
    virtual void r124();
    virtual void r128();
    virtual void r12c();
    virtual void r130();
    virtual void r134();
    virtual void r138();
    virtual void r13c();
    virtual void r140();
    virtual void r144();
    virtual void r148();
    virtual void r14c();
    virtual void r150();
    virtual void r154();
    virtual void r158();
    virtual void r15c();
    virtual void r160();
    virtual void r164();
    virtual void r168();
    virtual void r16c();
    virtual void r170();
    virtual void r174();
    virtual void r178();
    virtual void r17c();
    virtual void r180();
    virtual void r184();
    virtual void r188();
    virtual void r18c();
    virtual void r190();
    virtual void r194();
    virtual void r198();
    virtual void r19c();
    virtual void r1a0();
    virtual void r1a4();
    virtual void r1a8();
    virtual void r1ac();
    virtual void r1b0();
    virtual void r1b4();
    virtual void r1b8();
    virtual void r1bc();
    virtual void r1c0();
    virtual void r1c4();
    virtual void r1c8();
    virtual void r1cc();
    virtual void r1d0();
    virtual void r1d4();
    virtual void r1d8();
    virtual void r1dc();
    virtual void r1e0();
    virtual void r1e4();
    virtual void r1e8();
    virtual void r1ec();
    virtual void r1f0();
    Mat9S GetRotationMatrix();
    virtual void* GetTarget();
};

struct RefForm2 : RefForm
{
};


struct CellLike
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
    CellUnkC4* unkC4;
    FaceGenNode* GetOrCreateFaceGenNode(RefForm* ref);
};

// @fnv 0x00545740
FaceGenNode* CellLike::GetOrCreateFaceGenNode(RefForm* ref)
{
    if (!unkC4 || !ref || !reinterpret_cast<::FUN_00439f90_shell *>((ref))->FUN_00439f90())
        return 0;
    FaceGenNode* node5 = ((::FaceGenNode *)(reinterpret_cast<::ExtraList420 *>((((::ModelHolder *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00420ed0()));
    FaceAnimData* data3 = 0;
    if (!node5)
    {
        if (((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<void * *>(&::DAT_011ca238)))
        {
            node5 = ((::FaceGenNode *)(reinterpret_cast<::Ref5699 *>((ref))->FUN_005699b0()));
            if (!node5)
                return 0;
            data3 = ((::FaceAnimData *)(reinterpret_cast<::BSFaceGenNiNode *>((node5))->GetAnimationData()));
        }
        else
        {
            node5 = new FaceGenNode();
            data3 = ((::FaceAnimData *)(reinterpret_cast<::TESObjectREFR569 *>((ref))->FUN_00569920()));
            reinterpret_cast<::BSFaceGenNiNode *>((node5))->SetAnimationData((::BSFaceGenAnimationData *)(data3));
        }
    }
    else
    {
        data3 = ((::FaceAnimData *)(reinterpret_cast<::BSFaceGenNiNode *>((node5))->GetAnimationData()));
    }
    AnimController* ctrl = ((::AnimController *)(::fnv_0043b230::FUN_0043b230((const char *)(data3))));
    if (!ctrl)
    {
        Primitive* prim = ((::Primitive *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::ModelHolder *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041fbe0()));
        if (prim)
        {
            NiPoint3S pt3 = *((const ::NiPoint3S *)(reinterpret_cast<::TESRecipe *>((ref))->GetData()));
            ctrl = prim->CreateController(&pt3);
            data3->SetController(ctrl);
        }
    }
    if (ctrl)
    {
        ctrl->SetTarget(ref->GetTarget());
        if (ctrl->GetType() == 2)
        {
            reinterpret_cast<::FUN_004396b0_class *>((ctrl))->FUN_004396b0((const ::Mat9 &)((const ::Mat9S &)(ref->GetRotationMatrix())));
        }
        reinterpret_cast<::BSFaceGenNiNode *>((node5))->SetAnimationData((::BSFaceGenAnimationData *)(data3));
        reinterpret_cast<::Map6920 *>(&(unkC4->list))->FUN_006c6920((std::uintptr_t)(ref), (*(::NiPointer< ::NiAVObject> *)&(const ::NodePtr &)(node5)));
    }
    node5->Update();
    return node5;
}

struct FUN_00440640
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    ~FUN_00440640();
};
struct FUN_0045cec0
{
    unsigned int value;
    ~FUN_0045cec0();
};
struct FUN_0054ab60 : FUN_00440640
{
    FUN_0045cec0 member1c;
    FUN_0045cec0 member20;
    ~FUN_0054ab60();
};
// Calls FUN_0054ab60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0054ab30
void* CheckWithinMultiBoundTask::FUN_0054ab30(unsigned int flags)
{
    reinterpret_cast<::FUN_0054ab60 *>(this)->::FUN_0054ab60::~FUN_0054ab60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destroys the object, releasing its two member objects and the base class.
// @fnv 0x0054ab60
FUN_0054ab60::~FUN_0054ab60()
{}

struct BaseFormDC
{
    int FUN_00401170();
};

struct ReferenceDC
{
};

struct ReferenceNodeDC
{
    ReferenceDC** FUN_006815c0();
};

struct ReferenceCollectorDC
{
    void FUN_005ae3d0(ReferenceDC**);
};


struct FUN_0054dcf0_shell : TESObjectCELL
{
    void CollectCellReferences(ReferenceCollectorDC* collector);
};

// @fnv 0x0054dcf0
void FUN_0054dcf0_shell::CollectCellReferences(ReferenceCollectorDC* collector)
{
    if (collector != 0)
    {
        CellRefLockEnter();
        ReferenceNodeDC* node = reinterpret_cast<ReferenceNodeDC*>(((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0())));
        while (node != 0)
        {
            ReferenceDC* reference = *((::ReferenceDC **)((void *)(node)));
            if (reference != 0)
            {
                if (!((unsigned char)(reinterpret_cast<::TESForm *>((reference))->GetDisabled())))
                {
                    if (!((unsigned char)(reinterpret_cast<::FUN_00440d80_shell *>((reference))->FUN_00440d80())))
                    {
                        BaseFormDC* baseForm = ((::BaseFormDC *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
                        if (baseForm->FUN_00401170() == 0x1c && baseForm != (*reinterpret_cast<::BaseFormDC * *>(&::DAT_011ca258)))
                        {
                            BaseFormDC* currentForm = ((::BaseFormDC *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
                            if (((std::uintptr_t)(reinterpret_cast<::TESObjectREFR *>((reference))->GetExtraRadioData())) || ((unsigned char)(reinterpret_cast<::FUN_005194d0_shell_base *>((currentForm))->FUN_005194d0())))
                            {
                                collector->FUN_005ae3d0(&reference);
                            }
                        }
                    }
                }
            }
            node = ((::ReferenceNodeDC *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)this);
    }
}

extern int DAT_0102f024;
struct CellHandleData
{
};
struct CellHandle
{
    void* object;
    void FUN_00633c90(int value);
    void FUN_0066b0d0(int value);
    void FUN_0045cec0();
    CellHandle(int value)
    {
        FUN_00633c90(value);
    }
    ~CellHandle()
    {
        FUN_0045cec0();
    }
};
struct CellTypedHandle : CellHandle
{
    void* typeData;
    CellTypedHandle(int value) : CellHandle(value)
    {}
    void FUN_006e5cc0(CellTypedHandle* other);
};
struct CellHandleProvider
{
    bool FUN_00425fd0();
    void FUN_0054e640(CellTypedHandle* result);
};
struct FUN_0054e710_elem
{
    int m_v;
    void Method(int flag);
};

struct FUN_0054e710_cls
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
    FUN_0054e710_elem m_pElements[4];

    void FUN_0054e710();
};

// Calls Method(0) on each of the four elements in the array.
// @fnv 0x0054e710
void FUN_0054e710_cls::FUN_0054e710()
{
    for (int i = 0; i < 4; i++)
    {
        m_pElements[i].Method(0);
    }
}

// Stand-in for the cell's extra-data list: SetStringExtra attaches a named
// extra to the list.
struct CellExtraList
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

// Stand-in for the cell object: the extra data list starts at offset 0x28.
struct FUN_00551650_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    CellExtraList extraDataList;
    bool FUN_00551650(const char* name);
};


// If FUN_0044a670(name) returns non-zero, calls extraDataList.SetStringExtra(name); always returns true.
// @fnv 0x00551650
bool FUN_00551650_cls::FUN_00551650(const char* name)
{
    if (((int)(::FUN_0044a670(name))) != 0)
    {
        reinterpret_cast<::FUN_0041c6f0_class *>(&(extraDataList))->SetStringExtra(name);
    }
    return true;
}

struct SceneNode
{
    unsigned int FUN_0043b480();
};
struct SceneChild
{
    bool FUN_00552470();
};
struct SceneController
{
};
struct SceneEntity
{
    virtual void UnkVirtual00();
    virtual void UnkVirtual01();
    virtual void UnkVirtual02();
    virtual void UnkVirtual03();
    virtual void UnkVirtual04();
    virtual void UnkVirtual05();
    virtual void UnkVirtual06();
    virtual void UnkVirtual07();
    virtual void UnkVirtual08();
    virtual void UnkVirtual09();
    virtual void UnkVirtual0a();
    virtual void UnkVirtual0b();
    virtual void UnkVirtual0c();
    virtual void UnkVirtual0d();
    virtual void UnkVirtual0e();
    virtual void UnkVirtual0f();
    virtual void UnkVirtual10();
    virtual void UnkVirtual11();
    virtual void UnkVirtual12();
    virtual void UnkVirtual13();
    virtual void UnkVirtual14();
    virtual void UnkVirtual15();
    virtual void UnkVirtual16();
    virtual void UnkVirtual17();
    virtual void UnkVirtual18();
    virtual void UnkVirtual19();
    virtual void UnkVirtual1a();
    virtual void UnkVirtual1b();
    virtual void UnkVirtual1c();
    virtual void UnkVirtual1d();
    virtual void UnkVirtual1e();
    virtual void UnkVirtual1f();
    virtual void UnkVirtual20();
    virtual void UnkVirtual21();
    virtual void UnkVirtual22();
    virtual void UnkVirtual23();
    virtual void UnkVirtual24();
    virtual void UnkVirtual25();
    virtual void UnkVirtual26();
    virtual void UnkVirtual27();
    virtual void UnkVirtual28();
    virtual void UnkVirtual29();
    virtual void UnkVirtual2a();
    virtual void UnkVirtual2b();
    virtual void UnkVirtual2c();
    virtual void UnkVirtual2d();
    virtual void UnkVirtual2e();
    virtual void UnkVirtual2f();
    virtual void UnkVirtual30();
    virtual void UnkVirtual31();
    virtual void UnkVirtual32();
    virtual void UnkVirtual33();
    virtual void UnkVirtual34();
    virtual void UnkVirtual35();
    virtual void UnkVirtual36();
    virtual void UnkVirtual37();
    virtual void UnkVirtual38();
    virtual void UnkVirtual39();
    virtual void UnkVirtual3a();
    virtual void UnkVirtual3b();
    virtual void UnkVirtual3c();
    virtual void UnkVirtual3d();
    virtual void UnkVirtual3e();
    virtual void UnkVirtual3f();
    virtual bool IsEligibleForUpdate();
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unka0;
    void* unka4;
    void* unka8;
    SceneController* controller;
};
// Iterates the node's children; for each eligible entity whose controller passes the checks, calls SetTlsValueAndReset with 2.
// @fnv 0x00552390
void __cdecl FUN_00552390(SceneNode* root)
{
    for (unsigned int index = 0; index < root->FUN_0043b480(); ++index)
    {
        SceneChild* child = ((::SceneChild *)(reinterpret_cast<::NiNode *>((root))->GetAt(index)));
        if (child != 0)
        {
            SceneEntity* entity = ((::SceneEntity *)(::FUN_0056f930((::NiAVObject *)(child))));
            if (entity != 0 && entity->IsEligibleForUpdate())
            {
                SceneEntity* candidate = entity;
                if (candidate->controller != 0 && ::FUN_00552490((bool *)(candidate->controller)) &&
                    !((bool)(reinterpret_cast<::FUN_005524b0_class *>((candidate->controller))->GetByteAtOffset8C())) && !child->FUN_00552470() && !reinterpret_cast<::MobileObject *>((candidate))->IsInDialogueWithPlayer())
                {
                    ::SetTlsValueAndReset((std::intptr_t)(child), 2);
                }
            }
        }
    }
}

struct Guard
{
    void* m_ptr;
    Guard(void* param);
    ~Guard();
};

struct LockA
{
};

struct Owner
{
};


Guard::Guard(void* param)
{}
Guard::~Guard()
{}

// Acquires DAT_011ca1a0, calls DAT_011ca174.Method with a Guard wrapping param, then releases the lock.
// @fnv 0x005524f0
void __cdecl RunWithLock(void* param)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::LockA *>(&::g_011ca1a0))))->FUN_0040fbf0((char *)(0));
    {
        Guard guard(param);
        reinterpret_cast<::fnv_00631540::TargetClass *>(&((*reinterpret_cast<::Owner *>(&::g_011ca174))))->FUN_00631540((*(const ::NiPointer< ::NiNode> *)(&guard)));
    }
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::LockA *>(&::g_011ca1a0))))->FUN_0040fba0();
}

struct FUN_005526b0_cls
{
    int unk00;
    void FUN_005526b0();
};

// @fnv 0x005526b0
void FUN_005526b0_cls::FUN_005526b0()
{
    reinterpret_cast<::FUN_00456630_Class *>(this)->FUN_00456630(0x400000);
}

struct FUN_00552840_local
{
    FUN_00552840_local(float f, int i, int j);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00552840_obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0(FUN_00552840_local* p);
};

struct FUN_00552840_iter
{
};

struct FUN_00552840_holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00552840_iter m_iter;
};


struct FUN_00552840_cls
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
    FUN_00552840_holder* m_c4;
    void FUN_00552840();
};

// @fnv 0x00552840
void FUN_00552840_cls::FUN_00552840()
{
    FUN_00552840_local zeroArg(0.0f, 0, 0);
    FUN_00552840_obj* a = ((::FUN_00552840_obj *)(reinterpret_cast<::TESObjectCELL *>((this))->GetDynamicNode()));
    if (a != 0)
    {
        a->vfn_c0(&zeroArg);
    }
    if (m_c4 != 0)
    {
        void* cur = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_c4->m_iter))->GetFirstPos();
        while (cur != 0)
        {
            unsigned int x5 = 0;
            FUN_00552840_obj* x1c = 0;
            reinterpret_cast<::C6b7f20_Map *>(&(m_c4->m_iter))->FUN_006b7f20((::C6b7f20_Node **)(void **)(&cur), &x5, (void **)(::FUN_00552840_obj **)(&x1c));
            if (x1c != 0 && ((::FUN_00552840_obj *)(reinterpret_cast<::FUN_009611e0_shell *>((x1c))->FUN_009611e0())) != a)
            {
                x1c->vfn_c0(&zeroArg);
            }
        }
    }
}

struct CellTarget;
struct FinalActor
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00c();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01c();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02c();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03c();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04c();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05c();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06c();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07c();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08c();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09c();
    virtual void unk0a0();
    virtual void unk0a4();
    virtual void unk0a8();
    virtual void unk0ac();
    virtual void unk0b0();
    virtual void unk0b4();
    virtual void unk0b8();
    virtual void unk0bc();
    virtual void unk0c0();
    virtual void unk0c4();
    virtual void unk0c8();
    virtual void unk0cc();
    virtual void unk0d0();
    virtual void unk0d4();
    virtual void unk0d8();
    virtual void unk0dc();
    virtual void unk0e0();
    virtual void unk0e4();
    virtual void Finalize(void*);
};
struct WorldManager552
{
    FinalActor* FUN_0084e3a0();
};
extern WorldManager552* DAT_011dea10;
struct State552
{
};
struct Checker552
{
};
struct Updater552
{
};
struct Portal552
{
};
struct Temp552
{
};
struct CellTarget
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
    char unkd0;
    bool loaded;
    void FUN_0054ba80(int);
    bool FUN_00425fd0();
    void FUN_005577b0(int);
    void ProcessPerkEntries();
    int FUN_0084e3a0();
    void FUN_00552bd0(bool);
};
struct NiPick;

struct FUN_00553d00_shell : public TESObjectCELL
{
    bool PickChildNodes(NiPick* pick, int a2, int a3, float a4, char mask);
};

// Tests the pick against child nodes 0-4 and 7 of the cell according to the mask bits, returning true if any test succeeds.
// @fnv 0x00553d00
bool FUN_00553d00_shell::PickChildNodes(NiPick* pick, int a2, int a3, float a4, char mask)
{
    bool result = false;
    if (pick && mask)
    {
        bool bA = (mask & 1) ? true : false;
        bool bB = (mask & 2) ? true : false;
        bool b4 = (mask & 4) ? true : false;
        bool b8 = (mask & 8) ? true : false;
        bool bHitDetected = (mask & 0x10) ? true : false;
        if (bA)
        {
            if (::FUN_004b2780(pick, a2, a3, a4, (std::intptr_t)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(0)), false))
                result = true;
        }
        if (bB)
        {
            if (::FUN_004b2780(pick, a2, a3, a4, (std::intptr_t)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(1)), false))
                result = true;
        }
        if (b4)
        {
            if (::FUN_004b2780(pick, a2, a3, a4, (std::intptr_t)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(2)), false))
                result = true;
        }
        if (b8)
        {
            if (::FUN_004b2780(pick, a2, a3, a4, (std::intptr_t)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(3)), false))
                result = true;
        }
        if (bHitDetected)
        {
            if (::FUN_004b2780(pick, a2, a3, a4, (std::intptr_t)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(4)), false))
                result = true;
        }
        if (b8 || bHitDetected)
        {
            if (::FUN_004b2780(pick, a2, a3, a4, (std::intptr_t)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(7)), false))
                result = true;
        }
    }
    return result;
}

struct AVObj557;
struct Node557;
struct Form557;
struct Stat557;

struct AVObj557
{
};

struct Node557
{
    unsigned int FUN_0043b480();
};

struct Form557
{
    unsigned int FNV_GetFormType();
};

struct RefVTable_1d0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual AVObj557* Get3D();
};

struct Ref557 : RefVTable_1d0
{
};



struct CellStub
{
    void FUN_00557990(bool show, int type);
};

// @fnv 0x00557990
void CellStub::FUN_00557990(bool show, int type)
{
    Node557* node = ((::Node557 *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(7)));
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); i++)
        {
            AVObj557* child = ((::AVObj557 *)(reinterpret_cast<::NiNode *>((node))->GetAt(i)));
            if (child)
            {
                Node557* subNode = (Node557*)child;
                for (unsigned int j = 0; j < subNode->FUN_0043b480(); j++)
                {
                    child = ((::AVObj557 *)(reinterpret_cast<::NiNode *>((subNode))->GetAt(j)));
                    if (child)
                    {
                        Ref557* ref = ((::Ref557 *)(::FUN_0056f930((::NiAVObject *)(child))));
                        if (ref)
                        {
                            bool handled = false;
                            switch (type)
                            {
                            case 4: {
                                Form557* pBaseForm = ((::Form557 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
                                if (pBaseForm->FNV_GetFormType() != 0x1e && pBaseForm != (Form557*)(*reinterpret_cast<::Stat557 * *>(&::DAT_011ca234)))
                                {
                                    reinterpret_cast<::TaskQueueInterface *>((ref->Get3D()))->QueueActorDisarm(show);
                                }
                                break;
                            }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern void* DAT_011dea3c;

struct FUN_00557c40_vt
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* v04();
};

struct FUN_00557c40_cls
{
    char pad000[0xc8];
    float unkC8;
    unsigned char unkCC;
    unsigned char unkCD;
    unsigned char unkCE;
    unsigned char unkCF;
    unsigned char unkD0;
    void FUN_00557c40();
};

int Obj_Query(void* obj);

// Resets the object's fields, then walks its node list and processes each item whose object query returns 6, finally calling ResetB.
// @fnv 0x00557c40
void FUN_00557c40_cls::FUN_00557c40()
{
    if (unkCF != 0)
    {
        unkCF = 1;
    }
    unkCE = 0;
    unkC8 = DAT_0118b694;
    unkD0 = 0;
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    void* node = reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0();
    while (node != 0)
    {
        void* item = *(void**)((void *)((void *)(node)));
        node = reinterpret_cast<::Callees *>((node))->FUN_00726070();
        if (item != 0 && item != DAT_011dea3c)
        {
            FUN_00557c40_vt* p = (FUN_00557c40_vt*)((::FUN_00557c40_vt *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((item))->FUN_0043fcd0()));
            if (p != 0)
            {
                void* r = p->v04();
                if (r != 0)
                {
                    if (Obj_Query(r) == 6)
                    {
                        reinterpret_cast<::FUN_0054b800_class *>((r))->FUN_0054b800();
                    }
                }
            }
        }
    }
    ::FUN_00541ae0((char *)this);
}


struct SpawnedVecA
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
    void FUN_006815c0();
};

struct SpawnedVecB
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
    void FUN_006815c0();
    void FUN_0043f8d0(void* out, void* in);
};

struct SpawnedVecC
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
};


// @fnv 0x00558330
bool __cdecl FUN_00558330(std::intptr_t a1, std::intptr_t a2, std::intptr_t a3)
{
    bool ok5 = true;
    int i = 0x2d;
    int kTmp;
    int j_;
    SpawnedVecA a7;
    int m2;
    SpawnedVecB b_;
    SpawnedVecC c;
    for (kTmp = 0; kTmp < 3; kTmp++)
    {
        reinterpret_cast<::FUN_00524ac0_shell *>(&(a7))->FUN_00524ac0((float)(i * ::DAT_01023128));
        i -= 0x2d;
        j_ = 0;
        for (m2 = 0; m2 < 8; m2++)
        {
            reinterpret_cast<::FUN_004a0c90_shell *>(&(b_))->FUN_004a0c90((float)(j_ * ::DAT_01023128));
            j_ += 0x2d;
            b_.FUN_0043f8d0(&c, &a7);
            if (!((unsigned char)(::fnv_00558430::UpdateAndCheckBudget(a1, (const ::NiPoint3 *)(a2), (const ::fnv_00558430::ThreeByThreeMatrix *)(void *)(&c), (::SpawnedVecC *)(a3)))))
            {
                ok5 = false;
            }
        }
    }
    return ok5;
}

namespace fnv_00558c30 {
struct Inner
{
    int m_iValue;
};

struct Owner
{
  public:
    char m_00[0x64];
    Inner* m_pkInner;
    int GetInnerValue();
};

// Returns the inner object's value if the pointer is set, otherwise 0.
// @fnv 0x00558c30
int Owner::GetInnerValue()
{
    return m_pkInner ? m_pkInner->m_iValue : 0;
}
}  // namespace fnv_00558c30

struct FUN_00558f20_base
{
    virtual ~FUN_00558f20_base();
    int unk04;
};

struct FUN_00558f20_cls : FUN_00558f20_base
{
    virtual ~FUN_00558f20_cls();
};
// Calls FUN_00558f20, then deallocates this object if bit 0 of flags is set, and returns this.
// @fnv 0x00558df0
void* FUN_00558df0_StandIn::FUN_00558df0(unsigned int flags)
{
    reinterpret_cast<::FUN_00558f20_cls *>(this)->::FUN_00558f20_cls::~FUN_00558f20_cls();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}

// @fnv 0x00558f20
FUN_00558f20_cls::~FUN_00558f20_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct Base_559020
{
    virtual ~Base_559020();
    int unk04;
    int unk08;
};

class FUN_00559020_cls : public Base_559020
{
  public:
    int unk0C;

    virtual ~FUN_00559020_cls();
};
// Calls FUN_00559020, then frees this object via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00558e20
void* FUN_00558e20_StandIn::FUN_00558e20(unsigned int flags)
{
    reinterpret_cast<::FUN_00559020_cls *>(this)->::FUN_00559020_cls::~FUN_00559020_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor of FUN_00559020_cls that calls FUN_00438af0 before the base destructor runs.
// @fnv 0x00559020
FUN_00559020_cls::~FUN_00559020_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_00559230
{
    virtual ~FUN_00559230();
};
struct FUN_005591d0 : FUN_00559230
{
    virtual ~FUN_005591d0();
};
// Calls FUN_005591d0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00558e50
void* FUN_00558e50_StandIn::FUN_00558e50(unsigned int flags)
{
    reinterpret_cast<::FUN_005591d0 *>(this)->::FUN_005591d0::~FUN_005591d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x005591d0
FUN_005591d0::~FUN_005591d0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_005594e0_node
{
    FUN_005594e0_node* m_pkNext;
    unsigned int m_uiKey;
    void* m_pkValue;
};

struct FUN_005594e0_cls
{
    virtual void FUN_005594e0_v0();
    virtual unsigned int FUN_005594e0_hash(unsigned int key);
    virtual bool FUN_005594e0_match(unsigned int key, unsigned int nodeKey);
    virtual void FUN_005594e0_init(FUN_005594e0_node* node, unsigned int key, bool flag);
    virtual void FUN_005594e0_remove(FUN_005594e0_node* node);
    virtual FUN_005594e0_node* FUN_005594e0_alloc();
    unsigned int m_uiHashSize;
    FUN_005594e0_node** m_ppkHashTable;
    unsigned int m_uiCount;
    void FUN_005594e0(std::uintptr_t key, bool flag);
};

// @fnv 0x005594e0
void FUN_005594e0_cls::FUN_005594e0(std::uintptr_t key, bool flag)
{
    unsigned int index = FUN_005594e0_hash(key);
    FUN_005594e0_node* item = m_ppkHashTable[index];
    unsigned int n = 0;
    while (item != 0)
    {
        n++;
        if (FUN_005594e0_match(key, item->m_uiKey))
        {
            FUN_005594e0_remove(item);
            FUN_005594e0_init(item, key, flag);
            return;
        }
        item = item->m_pkNext;
    }
    item = FUN_005594e0_alloc();
    FUN_005594e0_init(item, key, flag);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_uiCount++;
}

namespace fnv_00585e00 {
struct LinkOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int flag);
};

class LinkProbe
{
  public:
    void* Owner();
    unsigned char Check();
};

class LinkRegistry
{
  public:
};

class LinkSink
{
  public:
};

extern LinkProbe* DAT_011de45c;

class FUN_00585e00_cls
{
  public:
    void FUN_00585e00(std::intptr_t arg);
};

// @fnv 0x00585e00
void FUN_00585e00_cls::FUN_00585e00(std::intptr_t pProbe)
{
    LinkProbe* probe;
    LinkOwner* o3;
    std::intptr_t copy;
    if (pProbe != 0 && ((void *)(reinterpret_cast<::TESObjectCELL *>((((LinkProbe*)pProbe)))->GetParentWorldSpace())) == this)
    {
        probe = ((::fnv_00585e00::LinkProbe *)(reinterpret_cast<::TESForm *>((((LinkProbe*)pProbe)))->GetFile(-1)));
        if (probe == 0 || ((unsigned char)(reinterpret_cast<::TESFile *>((probe))->IsMasterFile())))
        {
            reinterpret_cast<::TESObjectCELL *>((((LinkProbe*)pProbe)))->RemoveNonPersistentRefs();
            reinterpret_cast<::FUN_008d0370_shell *>((DAT_011de45c))->FUN_008d0370((::TESForm *)(pProbe));
            if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::fnv_00585e00::LinkRegistry * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((LinkProbe*)pProbe)))->FUN_0084e3a0()))))
            {
                reinterpret_cast<::SLGameShell *>(((*reinterpret_cast<::fnv_00585e00::LinkSink * *>(&::g_BGSSaveLoadGame))))->FUN_00849730((::TESForm *)(pProbe), 0);
            }
            reinterpret_cast<::fnv_00587760::FUN_00587760_shell *>((this))->RemoveCellFromMap((::TESObjectCELL *)(pProbe));
            copy = pProbe;
            o3 = (LinkOwner*)copy;
            (o3 != 0) ? o3->v4(1) : 0;
        }
        else
        {
            reinterpret_cast<::TESObjectCELL *>((((LinkProbe*)pProbe)))->RemoveNonPersistentRefs();
        }
    }
}
}  // namespace fnv_00585e00

class Base_b5143
{
  public:
    unsigned int m_00;
    ~Base_b5143();
};

class Sub_b5143
{
  public:
    unsigned int m_00;
    ~Sub_b5143();
};

class FUN_006208d0_cls : public Base_b5143
{
  public:
    Sub_b5143 m_04;
    ~FUN_006208d0_cls();
};

// Destructor for the class; destroys the embedded Sub_b5143 member and the base.
// @fnv 0x006208d0
FUN_006208d0_cls::~FUN_006208d0_cls()
{}

struct WorkerMobile
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
    virtual bool v63();
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
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual bool v152();
    int FUN_00931850();
};
struct WorkerList
{
    WorkerMobile** FUN_006815c0();
};
struct WorkerLock
{
};
extern WorkerMobile* g_thePlayer;
struct WorkerQueue
{
};
struct WorkerManager
{
    int unk00;
    WorkerQueue queue;
    void ProcessWorkerList(WorkerList*, bool);
};
// @fnv 0x0096e150
void WorkerManager::ProcessWorkerList(WorkerList* pWorkerList, bool enabled)
{
    WorkerList* start = pWorkerList;
    while (pWorkerList && *((::WorkerMobile **)((void *)(pWorkerList))))
    {
        WorkerMobile* actor = 0;
        if ((*((::WorkerMobile **)((void *)(pWorkerList))))->v63())
            actor = *((::WorkerMobile **)((void *)(pWorkerList)));
        pWorkerList = ((::WorkerList *)(reinterpret_cast<::Callees *>((pWorkerList))->FUN_00726070()));
        if (actor)
        {
            if (enabled)
            {
                if (reinterpret_cast<::FUN_00440d80_shell *>((actor))->FUN_00440d80() || reinterpret_cast<::TESForm *>((actor))->GetDisabled())
                {
                    if (((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && reinterpret_cast<::FUN_0078d200_cls *>(&((*reinterpret_cast<::WorkerLock *>(&::DAT_011f11a0))))->FUN_0078d200())
                    {
                        reinterpret_cast<::FUN_0096aaf0_shell *>(&(queue))->FUN_0096aaf0((std::intptr_t)(actor), actor->FUN_00931850());
                        reinterpret_cast<::FUN_00931e80_shell *>((actor))->DeleteAndClear();
                        reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::WorkerLock *>(&::DAT_011f11a0))))->FUN_0040fba0();
                    }
                }
                else
                {
                    if (actor != g_thePlayer && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && !actor->v152())
                        pWorkerList = start;
                }
            }
            else
            {
                reinterpret_cast<::ProcessLists *>(this)->AddMobileObjectToList((::MobileObject *)(actor));
            }
        }
    }
}

struct TypeForm
{
    unsigned int FUN_00401170();
};
struct ReferenceView
{
};
struct RefBucket
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
};
extern const char DAT_0102cf28[];
struct CollectionView
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    RefBucket all, unk30, unk48, doors, actors, special, animated;
    void FUN_00526f20(ReferenceView*);
};
// @fnv 0x00557470
void TESObjectCELL::ClearCellReferenceList()
{
    CellRefLockEnter();
    BSSimpleList<BGSPerkEntry*>* node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (node)
    {
        BGSPerkEntry* reference = (node->item);
        if (reference)
            reinterpret_cast<::CollectionView *>((DAT_011c95c8))->FUN_00526f20((::ReferenceView *)(reference));
        node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}
// @fnv 0x00526f20
void CollectionView::FUN_00526f20(ReferenceView* reference)
{
    Local::AutoMemContext p((Local::MEM_CONTEXT)44, true, DAT_0102cf28, 104);
    unsigned int a = ((::TypeForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170();
    if (::TESContainer::IsValidContainerType((unsigned char)a))
    {
        reinterpret_cast<::LoadedReferenceMap *>(&(all))->AddReference((::TESObjectREFR *)(reference));
        RefBucket* bucket = ((::RefBucket *)(reinterpret_cast<::FUN_005271b0_Class *>(this)->GetFieldByType(a)));
        if (bucket)
            reinterpret_cast<::LoadedReferenceMap *>((bucket))->AddReference((::TESObjectREFR *)(reference));
    }
    if (a == 0x1b)
        reinterpret_cast<::LoadedReferenceMap *>(&(doors))->AddReference((::TESObjectREFR *)(reference));
    if (a == 0x2a || a == 0x2b)
        reinterpret_cast<::LoadedReferenceMap *>(&(actors))->AddReference((::TESObjectREFR *)(reference));
    if (((::TypeForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<::TypeForm * *>(&::DAT_011ca264)))
        reinterpret_cast<::LoadedReferenceMap *>(&(special))->AddReference((::TESObjectREFR *)(reference));
    if (a == 0x51 && ((std::uintptr_t)(reinterpret_cast<::TESObjectREFR *>((reference))->GetExtraData(0x5d))))
        reinterpret_cast<::LoadedReferenceMap *>(&(special))->AddReference((::TESObjectREFR *)(reference));
    if (a == 0x1c && ((std::uintptr_t)(reinterpret_cast<::TESObjectREFR *>((reference))->GetExtraRadioData())))
        reinterpret_cast<::LoadedReferenceMap *>(&(animated))->AddReference((::TESObjectREFR *)(reference));
}

struct CellBase
{
    virtual ~CellBase();
    int unk04, unk08, unk0c, unk10, unk14;
};
struct CellSecondary
{
    virtual ~CellSecondary();
    int unk1c, unk20, unk24;
};
struct OwnedLighting
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~OwnedLighting();
};
struct OwnedData
{
    ~OwnedData();
};
struct BoneTransformData
{
    virtual ~BoneTransformData();
    void Clear();
};
struct CellExtra
{
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    ~CellExtra();
};
struct CellList
{
    int unk58, unk5c;
    ~CellList();
};
struct CellLock
{
    int unkac, unkb0;
    ~CellLock();
};
struct CellRef
{
    int value;
    ~CellRef();
};
struct ParentWorld
{
};
struct GameState
{
};
class FUN_00541810_cls : public CellBase, public CellSecondary
{
  public:
    virtual ~FUN_00541810_cls();
    CellExtra extra;
    int unk48;
    OwnedLighting* lighting;
    int unk50, unk54;
    CellList list;
    int unk60;
    OwnedData* data;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    CellLock lock;
    CellRef refb4, refb8, refbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0;
    CellRef refd4;
    void Clear();
};
class LockedRef;
class LockHolder
{
  public:
    void FUN_0066b0d0(int flag);
};
class LockedRef
{
  public:
};
class ObjBase
{
  public:
    virtual void* vScalarDelete(unsigned int flags);
};

void __cdecl FUN_00541cd0();

// @fnv 0x00541c00
void __cdecl FUN_00541c00()
{
    if ((*reinterpret_cast<::ObjBase * *>(&::DAT_011ca088)) != 0)
    {
        reinterpret_cast<::FUN_006242f0_shell *>(((*reinterpret_cast<::ObjBase * *>(&::DAT_011ca088))))->NotifyListener(((void *)(reinterpret_cast<::ScriptLocals *>((((::LockedRef *)(::FUN_00559450((int *)(reinterpret_cast<LockHolder*>(&(*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011ca0d8)))))))))->GetLocalData())));
        ObjBase* a = (*reinterpret_cast<::ObjBase * *>(&::DAT_011ca088));
        ObjBase* b5 = a;
        void* res3;
        if (b5 != 0)
        {
            res3 = b5->vScalarDelete(1);
        }
        else
        {
            res3 = 0;
        }
        (*reinterpret_cast<::ObjBase * *>(&::DAT_011ca088)) = 0;
    }
    reinterpret_cast<LockHolder*>(&(*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011ca0d8)))->FUN_0066b0d0(0);
    FUN_00541cd0();
}

struct SaveFile
{
};
struct SaveRef
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual bool Precedes(SaveRef* other);
    void Save(SaveFile* file);
};
struct RefNode
{
    bool Empty();
};
struct RefArray
{
    unsigned int data, size, capacity, grow;
    RefArray(int initial, int mode);
    ~RefArray();
    SaveRef** At(int index);
};
struct FUN_00542040_cls
{
    void FUN_00542040(SaveFile* file);
};
// @fnv 0x00541e80
bool FUN_00541e80_shell::SaveCellToFile(CellFileStub* file)
{
    if (reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
        return false;

    bool bSave;
    CellRefNodeStub* node_2;
    CellFormStub* ref;
    CellFileStub* refFile5;
    CellGroupHeader header8;
    bSave = false;
    CellRefLockEnter();
    if (reinterpret_cast<::TESFile *>((file))->IsMasterFile() || reinterpret_cast<::FUN_00460340_shell *>(this)->FUN_00460340())
    {
        bSave = true;
    }
    else
    {
        node_2 = ((::CellRefNodeStub *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (node_2 && !node_2->IsEmpty8256d0())
        {
            ref = *((::CellFormStub **)((void *)(node_2)));
            node_2 = ((::CellRefNodeStub *)(reinterpret_cast<::Callees *>((node_2))->FUN_00726070()));
            refFile5 = ((::CellFileStub *)(reinterpret_cast<::TESForm *>((ref))->GetFile(-1)));
            if (refFile5 == file || !refFile5 || reinterpret_cast<::FUN_00460340_shell *>((ref))->FUN_00460340())
            {
                bSave = true;
                break;
            }
        }
    }
    ::FUN_00541ae0((char *)this);

    if (!bSave)
        return false;

    ((CellVTableStub*)this)->v11();
    reinterpret_cast<::FUN_00472fe0_cls *>((file))->RunProbe((::Fun472Param *)(::TESObjectCELL *)(this));

    header8.type = ::fnv_00543df0::kGroupFormType;
    header8.groupType = 6;
    header8.label = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    header8.size = 0;
    header8.stamp = 0;
    reinterpret_cast<::FUN_00473310_cls *>((file))->SpawnObject((std::uintptr_t)(&header8));
    if (!reinterpret_cast<::TESFile *>((file))->IsMasterFile() || ((::CellFileStub *)(reinterpret_cast<::TESForm *>(this)->GetFile(0))) == file)
        reinterpret_cast<::FUN_00542040_cls *>(this)->FUN_00542040((::SaveFile *)(file));
    return true;
}
// @fnv 0x00541fd0
bool CellX::ProcessCell(ParamCls* param)
{
    this->v11();
    reinterpret_cast<::FUN_00472fe0_cls *>((param))->RunProbe((::Fun472Param *)(::CellX *)(this));
    CellData20 d;
    void* reserved;
    d.m_ptr = (*reinterpret_cast<void * *>(&::fnv_00543df0::kGroupFormType));
    d.m_six = 6;
    d.m_result = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()));
    d.m_zeroA = 0;
    d.m_zeroB = 0;
    reinterpret_cast<::FUN_00473310_cls *>((param))->SpawnObject((std::uintptr_t)(&d));
    reinterpret_cast<::FUN_00542040_cls *>((this))->FUN_00542040((::SaveFile *)(param));
    return true;
}
// @fnv 0x00542040
void FUN_00542040_cls::FUN_00542040(SaveFile* file)
{
    RefArray refs(0, 1);
    reinterpret_cast<::ViewerStrings *>(&(refs))->SetSize(50);
    reinterpret_cast<::fnv_00559490::S *>(&(refs))->FUN_00559490(50);
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    RefNode* node = ((::RefNode *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (node && !node->Empty())
    {
        SaveRef* ref = *((::SaveRef **)((void *)(node)));
        node = ((::RefNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        bool aKeep = true;
        if (reinterpret_cast<::FUN_004077c0_shell *>((ref))->FUN_004077c0())
            aKeep = false;
        if (reinterpret_cast<::FUN_00440d80_shell *>((ref))->FUN_00440d80())
        {
            SaveFile* origin = ((::SaveFile *)(reinterpret_cast<::TESForm *>((ref))->GetFile(0)));
            if (origin && !reinterpret_cast<::TESFile *>((origin))->IsMasterFile())
                aKeep = false;
        }
        if (file != ((::SaveFile *)(reinterpret_cast<::TESForm *>((ref))->GetFile(-1))) && !reinterpret_cast<::FUN_00460340_shell *>((ref))->FUN_00460340())
            aKeep = false;
        if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((ref))->FUN_005653d0() && !reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
            aKeep = false;
        if (aKeep)
            reinterpret_cast<::Arr86 *>(&(refs))->AddAtFirstFreeSlot((*(::BGSAddonNode * *)(&ref)));
    }
    ::FUN_00541ae0((char *)this);
    ::CompactArray((::NiTArray_CombatGroup *)&(refs));
    int count = ((int)(::FUN_009938b0((const unsigned short *)&(refs))));
    for (int i = 0; i < count; ++i)
    {
        SaveRef* first = *refs.At(i);
        for (int j = i + 1; j < count; ++j)
        {
            SaveRef* second = *refs.At(j);
            if (second->Precedes(first))
            {
                reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(refs))->SetAt(i, (*(char * *)(&second)));
                reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(refs))->SetAt(j, (*(char * *)(&first)));
                first = second;
            }
        }
    }
    for (int k = 0; k < count; ++k)
    {
        SaveRef* entry = *refs.At(k);
        if (entry)
            reinterpret_cast<::FUN_00483d20_shell *>((entry))->SaveIfNotTemporary((::TESFile *)(file));
    }
}

extern int DAT_01183028;

struct CellDataBlock;
struct PtrPair
{
    void* first;
    void* second;
};
struct ExtraListPair
{
};
struct CellSubMember
{
    virtual void Reset();
    virtual void Clear();
    virtual void CopyFrom(CellSubMember* other);
};
struct CellLightingTemplate;

struct CellState
{
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
    CellDataBlock* cellData;
    int field4C;
    float field50;
    int field54;
    CellSubMember member58;
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
    int fieldCC;
    int fieldD0;
    int fieldD4;
    int fieldD8;
    unsigned int fieldDC;

    bool FUN_00425fd0();
    void CopyFromCell(TESForm* form);
};

// Casts form to a CellState and copies its data, lighting template, member58 and related fields into this CellState.
// @fnv 0x00543ab0
void CellState::CopyFromCell(TESForm* form)
{
    CellState* cell = (CellState*)dynamic_cast<::TESObjectCELL *>(reinterpret_cast<::TESForm *>(form));
    if (!cell)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0((TESForm*)cell);
    reinterpret_cast<::fnv_00411ec0::FUN_00411ec0_shell *>((((::ExtraListPair *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00411ec0((::ExtraDataList *)(::ExtraListPair *)(((::ExtraListPair *)(reinterpret_cast<::FUN_004610d0_shell *>((cell))->GetExtraDataList()))));
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        delete cellData;
    }
    else
    {
        delete cellData;
    }
    cellData = 0;
    reinterpret_cast<::FUN_00461310_shell *>(this)->SetByteAt24(reinterpret_cast<::TESObjectCELL *>((cell))->GetField24());
    field50 = cell->field50;
    reinterpret_cast<::FUN_00544630_shell *>(this)->ResetCellData();
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        PtrPair interior;
        interior.first = reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600();
        interior.second = reinterpret_cast<::FUN_00544600_shell *>((cell))->FUN_00544600();
        if (interior.first && interior.second)
            ::__memcpy(interior.first, interior.second, 0x2c);
    }
    else
    {
        PtrPair exterior;
        exterior.first = reinterpret_cast<::FUN_005445d0_shell *>(this)->FUN_005445d0();
        exterior.second = reinterpret_cast<::FUN_005445d0_shell *>((cell))->FUN_005445d0();
        if (exterior.first && exterior.second)
            ::__memcpy(exterior.first, exterior.second, 0x0c);
    }
    reinterpret_cast<::fnv_00558b60::FUN_00558b60_shell *>(this)->FUN_00558b60((::fnv_00558b60::BGSLightingTemplate *)(void *)(((::CellLightingTemplate *)(reinterpret_cast<::FUN_00558b40_shell *>((cell))->GetLightingTemplate()))));
    fieldDC = reinterpret_cast<::FUN_00497280_shell *>((cell))->GetFieldAt124();
    member58.CopyFrom(&cell->member58);
}

template <class T> class NiPtr545
{
  public:
    T* m_pObject;
    NiPtr545(T* p);
    ~NiPtr545();
    operator T*() const;
};

struct AnimData545
{
};
struct AnimNode545
{
};
struct MapKey545
{
};

struct Map545
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct Owner545;
struct Handler545
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual void Detach(Owner545* owner);
};
struct Owner545
{
};

struct CellData545
{
    NiPtr545<Owner545> owner;
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
    Map545 map;
    BSSimpleList<int> list4C;
    BSSimpleList<int> list54;
    ~CellData545();
};

struct Cell545030
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    CellData545* pData;
    void ClearCellData();
};
// Calls FUN_00541810, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005417e0
void* FUN_005417e0_class::FUN_005417e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00541810_cls *>(this)->::FUN_00541810_cls::~FUN_00541810_cls();

    if (flags & 1)
    {
        ::FUN_00401030(this);
    }

    return this;
}
// Destructor: prepares, clears and frees lighting, data and scene unless persistent, removes from world, then finishes, releases and cleans up.
// @fnv 0x00541810
FUN_00541810_cls::~FUN_00541810_cls()
{
    reinterpret_cast<::fnv_00545c10::FUN_00545c10_class *>(this)->ClearAdditionalGeometryData();
    if (!reinterpret_cast<::FUN_004077c0_shell *>(this)->FUN_004077c0())
    {
        Clear();
        if (lighting)
        {
            delete lighting;
            lighting = 0;
        }
        if (data)
        {
            delete data;
            data = 0;
        }
        BoneTransformData* scene = ((::BoneTransformData *)(std::uintptr_t)(reinterpret_cast<::FUN_0041bce0_class *>(&(extra))->FUN_0041bce0()));
        if (scene)
        {
            reinterpret_cast<::FUN_004f6640_cls *>((scene))->FUN_004f6640();
            delete scene;
        }
    }
    if (!reinterpret_cast<::FUN_004226e0_shell *>((reinterpret_cast<GameState*>((*reinterpret_cast<::Checker552 * *>(&::g_dataHandler)))))->FUN_004226e0())
    {
        ParentWorld* world = ((::ParentWorld *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()));
        if (world)
            reinterpret_cast<::fnv_00587760::FUN_00587760_shell *>((world))->RemoveCellFromMap((::TESObjectCELL *)(void *)(this));
    }
    reinterpret_cast<::Cell545030 *>(this)->ClearCellData();
    ::ClearGlobalIfMatches((std::intptr_t)(this));
    reinterpret_cast<::TESObjectCELL *>(this)->ClearData();
}

// @fnv 0x00545030
void Cell545030::ClearCellData()
{
    if (pData)
    {
        reinterpret_cast<::FileMatchList *>(&(pData->list4C))->RemoveAll();
        reinterpret_cast<::FileMatchList *>(&(pData->list54))->RemoveAll();
        void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(pData->map))->GetFirstPos();
        while (pos)
        {
            NiPtr545<AnimNode545> node(0);
            MapKey545* key = 0;
            reinterpret_cast<::Map62d0 *>(&(pData->map))->FUN_00559120((::MapItem62d0 *&)(pos), (void *&)(key), (::Helper62d0 &)(node));
            if (key && node)
            {
                AnimData545* pAnimData = ((::AnimData545 *)(reinterpret_cast<::BSFaceGenNiNode *>((((AnimNode545*)node)))->GetAnimationData()));
                if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((pAnimData))->FUN_00726070())) == 2)
                    reinterpret_cast<::fnv_00569990::TargetClass *>((key))->FUN_00569990();
            }
        }
        if (pData->owner)
        {
            reinterpret_cast<::fnv_00545c10::FUN_00545c10_class *>(this)->ClearAdditionalGeometryData();
            Handler545* handler = ((::Handler545 *)(reinterpret_cast<::FUN_009611e0_shell *>((((Owner545*)pData->owner)))->FUN_009611e0()));
            if (handler)
                handler->Detach(pData->owner);
        }
        delete pData;
        pData = 0;
    }
}

struct RefList;

struct FUN_00545670_vobj
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
    virtual void v13(unsigned int flags);
};

struct FUN_00545670_cls
{
    char pad[0xc4];
    char* m_c4;
    void FUN_00545670(void* obj);
};

// @fnv 0x00545670
void FUN_00545670_cls::FUN_00545670(void* pObject)
{
    if (m_c4 != 0)
    {
        reinterpret_cast<::ItemChangeListNode *>((((RefList*)(m_c4 + 0x54))))->FUN_00905330((::InventoryStackRecord *const &)(reinterpret_cast<unsigned int&>(pObject)));
    }
    ((FUN_00545670_vobj*)pObject)->v13(0x4000000);
}

extern void* __cdecl FUN_00aa13e0(unsigned int);
extern char DAT_0102ed50;
using FUN_00404eb0 = ::AutoMemContext;
struct Widget
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void Attach(Widget*, int);
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
    void FUN_005468d0(int);
};
struct FUN_00a5ecb0 : Widget
{
    FUN_00a5ecb0(int);
};
struct FUN_00c46970 : Widget
{
    int unkac, unkb0;
    FUN_00c46970();
    void FUN_005468d0(int);
};
struct FUN_00c35e00
{
    void* vfptr;
    int unk04, unk08, unk0c;
    FUN_00c35e00();
    void FUN_004addc0(void*);
};
struct FUN_00c37ec0
{
    void* vfptr;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    FUN_00c37ec0();
};
struct WidgetSlot
{
    Widget* pointer;
    void FUN_0066b0d0(Widget*);
};
struct ManagerResult
{
    int unk00;
};
struct GlobalManager
{
};

struct ScaleVector
{
    float a, b, d;
    void FUN_0043d410(float, unsigned char = 0, unsigned char = 0);
};
struct TemporaryName
{
    int unk00;
    TemporaryName(const char*);
    ~TemporaryName();
};
struct FUN_00545cf0_Cls
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
    WidgetSlot m_mainB4;
    WidgetSlot m_secondaryB8;
    int unkBC, unkC0;
    WidgetSlot* m_parentC4;
    int unkC8, unkCC;
    unsigned char unkD0, m_enabledD1, unkD2, unkD3;
    void FUN_00552dc0();
    Widget* GetOrCreateWidget();
};
// Returns the widget from FUN_00545cb0, building and attaching its child widgets if absent, then ensures a manager result item exists and returns the widget.
// @fnv 0x00545cf0
Widget* FUN_00545cf0_Cls::GetOrCreateWidget()
{
    Widget* a;
    FUN_00404eb0 b(0x1a, 1, &(*reinterpret_cast<char *>((void *)&::str_0102ed68)), 0xd84);
    Widget* c;
    ManagerResult* d;
    ScaleVector e;
    a = ((::Widget *)(reinterpret_cast<::FUN_00545cb0_shell *>(this)->FUN_00545cb0()));
    if (!a)
    {
        reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(2);
        m_enabledD1 = 0;
        a = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00440460_S *>((a))->FUN_00440460((const ::V3 *)(const void *)(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO))));
        reinterpret_cast<::FUN_0043fa80_s *>((a))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<::Local::ThreeByThreeMatrix *>(&::DAT_011a9448)))));
        reinterpret_cast<::TaskQueueInterface *>((a))->SetTaskFlag2000(1);
        reinterpret_cast<::FUN_00546780_shell *>((a))->FUN_00546780(1);
        Widget* current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(0))));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag_005468b0(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(1))));
        a->Attach(current, 1);
        c = current;
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(9))));
        c->Attach(current, 1);
        m_mainB4.FUN_0066b0d0(current);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(10))));
        c->Attach(current, 1);
        m_secondaryB8.FUN_0066b0d0(current);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(2))));
        a->Attach(current, 1);
        for (int i = 0; i < 4; ++i)
        {
            FUN_00c46970* pConfigWidget = new FUN_00c46970();
            reinterpret_cast<::s005468d0::Owner *>((pConfigWidget))->FUN_005468d0(1);
            FUN_00c35e00* page = new FUN_00c35e00();
            FUN_00c37ec0* list = new FUN_00c37ec0();
            page->FUN_004addc0(list);
            reinterpret_cast<::BSFaceGenNiNode *>((pConfigWidget))->SetAnimationData((::BSFaceGenAnimationData *)(page));
            current->Attach(pConfigWidget, 1);
        }
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(3))));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(0);
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(5))));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(6))));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(7))));
        a->Attach(current, 1);
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        reinterpret_cast<::FUN_00546780_shell *>((current))->FUN_00546780(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->SetTaskFlag2000(1);
        reinterpret_cast<::TaskQueueInterface *>((current))->QueueActorDisarm(((unsigned char)(::fnv_005468f0::FUN_005468f0(8))));
        a->Attach(current, 1);
        a->Attach(current, 1);

        e.FUN_0043d410(0.0f);
        reinterpret_cast<::FUN_00a59c60_cls *>((a))->FUN_00a59c60((std::intptr_t)(&e));
        reinterpret_cast<::Cell_Sub *>(this)->FUN_00544ce0();
        m_parentC4->FUN_0066b0d0(a);
        reinterpret_cast<::fnv_00545a30::FUN_00545a30_shell *>(this)->AttachOrphanedChildren();
        FUN_00552dc0();
        if (!((unsigned char)(reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((((GlobalManager*)(*reinterpret_cast<::Updater552 * *>(&::g_BGSSaveLoadGame)))))->FUN_0042ce10())))
        {
            unsigned char saved = ((unsigned char)(reinterpret_cast<::FUN_004623f0_shell *>((((GlobalManager*)(*reinterpret_cast<::Updater552 * *>(&::g_BGSSaveLoadGame)))))->FUN_004623f0(0)));
            reinterpret_cast<::BGSSaveLoadGame *>((((GlobalManager*)(*reinterpret_cast<::Updater552 * *>(&::g_BGSSaveLoadGame)))))->FormReconstructionMap((::TESObjectCELL *)(void *)(this));
            if (!((unsigned char)(reinterpret_cast<::FUN_00546950_Class *>((((GlobalManager*)(*reinterpret_cast<::Updater552 * *>(&::g_BGSSaveLoadGame)))))->FUN_00546950())))
                reinterpret_cast<::fnv_008492b0::FUN_008492b0_shell *>((((GlobalManager*)(*reinterpret_cast<::Updater552 * *>(&::g_BGSSaveLoadGame)))))->ResetLoadBuffers(0);
            reinterpret_cast<::FUN_004623f0_shell *>((((GlobalManager*)(*reinterpret_cast<::Updater552 * *>(&::g_BGSSaveLoadGame)))))->FUN_004623f0(saved);
        }
        reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(3);
    }
    d = ((::ManagerResult *)(reinterpret_cast<::FUN_00545b30_shell *>(this)->GetPortalGraph()));
    if (!((std::uintptr_t)(::fnv_00546930::FUN_00546930((::fnv_00546930::FUN_00546930_Class *)(d)))))
    {
        Widget* item = new FUN_00a5ecb0(0);
        ::AssignFixedString((char *)(item), (std::intptr_t)(&ResultSlot(TemporaryName(&DAT_0102ed50))), {});
        reinterpret_cast<::fnv_00546910::S *>((d))->FUN_00546910((::fnv_00546910::NiNodeX *)(item));
    }

    return a;
}

struct CellInput
{
    bool FUN_00425fd0();
};
struct FUN_00438170
{
    unsigned int field00;
    FUN_00438170(const char*);
    ~FUN_00438170();
};
void* __cdecl FUN_00a7fc00(const FUN_00438170&, int, int, void*, void*, int, int, int);
extern int DAT_011ab3cc;
extern const char str_0102edac[];
struct LockedRect
{
    int field00;
    char* field04;
};
struct ExtraOut
{
};
struct DeviceTexture
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual int LockRect(int, LockedRect*, void*, int);
};
struct RenderData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual int GetHeight();
    virtual DeviceTexture* GetTexture();
};
// @fnv 0x00547830
int __cdecl CreateAndClearRenderTarget(CellInput* cell, RenderData** ppOutput, LockedRect** ppLockedRect)
{
    *ppOutput = 0;
    if (!cell || reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior() || !((void *)(::FUN_004bc3f0())))
        return false;
    DAT_011f4ac0 = true;
    DAT_011ab3c8 = 50;
    DAT_011ab3c4 = false;
    *ppOutput = (RenderData*)FUN_00a7fc00(FUN_00438170(str_0102edac), 64, 64, FUN_0043c4b0(), &DAT_011ab3cc, 0, 0, 0);
    DAT_011f4ac0 = false;
    DAT_011ab3c4 = true;
    reinterpret_cast<::fnv_0041c490::FUN_0041c490_cls *>((((ExtraOut*)reinterpret_cast<::FUN_004610d0_shell *>((cell))->GetExtraDataList())))->FUN_0041c490(true, (::fnv_0041c490::NiRenderedTexture *)(*ppOutput), (::fnv_0041c490::_D3DLOCKED_RECT **)(ppLockedRect));
    RenderData* data2 = ((::RenderData *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>(((*ppOutput)))->GetCurrentMoveModeType()));
    DeviceTexture* texture4 = data2->GetTexture();
    texture4->LockRect(0, *ppLockedRect, 0, 0);
    int count3 = (*ppLockedRect)->field00 * (*ppOutput)->GetHeight();
    char* pixels2 = (*ppLockedRect)->field04;
    for (int i2 = 0; i2 < count3; ++i2)
        pixels2[i2] = 0;
    return 1;
}

class C5479C0WorldSpace;

struct C5479C0Grid
{
    int unk00;
    unsigned char* m_pcData;
};

class C5479C0Renderer
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void Attach(int iArg1, C5479C0Grid* pkGrid, int iArg2, int iArg3);
};

class C5479C0Object3D
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual C5479C0Renderer* GetRenderer();
};

class C5479C0Land
{
  public:
    C5479C0Object3D* Get3D();
};

class C5479C0List
{
  public:
};

class C5479C0Cell
{
  public:
};

class C5479C0DataHandler
{
  public:
    C5479C0Cell* GetContainingCell(int iX, int iY, C5479C0WorldSpace* pkWorldSpace, bool bLoad);
};



class C5479C0Manager
{
  public:

    void SetGridDataByte(int iX, int iY, C5479C0Grid** ppkGrid, int iIndex, unsigned char ucValue);
};

// @fnv 0x005479c0
void C5479C0Manager::SetGridDataByte(int iX, int iY, C5479C0Grid** ppkGrid, int iIndex, unsigned char ucValue)
{
    C5479C0Cell* pkTargetCell = 0;
    unsigned char* pcData = 0;
    C5479C0Land* pkL = 0;

    if (!*ppkGrid)
    {
        pkTargetCell = ((::C5479C0Cell *)(reinterpret_cast<::FUN_00461c20_Holder *>(((*reinterpret_cast<::C5479C0DataHandler * *>(&::g_dataHandler))))->GetOrCreateCell(iX, iY, (::TESWorldSpace *)(::C5479C0WorldSpace *)(((::C5479C0WorldSpace *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))), false)));
        if (pkTargetCell)
        {
            reinterpret_cast<::Hold580 *>((((::C5479C0List *)(reinterpret_cast<::FUN_004610d0_shell *>((pkTargetCell))->GetExtraDataList()))))->GetExtraDataNameAndPtr((const char **)(::C5479C0Land **)(&pkL), (unsigned int **)(ppkGrid));
            if (!pkL)
                ::CreateAndClearRenderTarget((::CellInput *)(pkTargetCell), (::RenderData **)(::C5479C0Land **)(&pkL), (::LockedRect **)(ppkGrid));
        }
        else
        {
            return;
        }
    }

    if (*ppkGrid)
    {
        if (!(*ppkGrid)->m_pcData)
        {
            C5479C0Object3D* pk3D = ((::C5479C0Object3D *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((pkL))->GetCurrentMoveModeType()));
            C5479C0Renderer* pkRenderer = pk3D->GetRenderer();
            pkRenderer->Attach(0, *ppkGrid, 0, 0);
        }
        pcData = (*ppkGrid)->m_pcData;
        if (pcData[iIndex])
            pcData[iIndex] = 0xff;
        else
            pcData[iIndex] = ucValue;
    }
}

namespace fnv_005497c0 {
struct NiBound
{
    char pad[0x10];
};
struct FUN_006815c0
{
};

struct Inner52
{
    int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
};
struct FUN_0045c620
{
    FUN_0045c620();
    int pad00[27];
    Inner52 arr;
    unsigned char t0;
    unsigned char t1;
    unsigned char t2;
    unsigned char flagA3;
    void* iter;
};

struct ItemObj
{
};
struct VObj
{
    virtual void vph0();
    virtual void vph1();
    virtual void vph2();
    virtual void vph3();
    virtual void vph4();
    virtual void vph5();
    virtual void vph6();
    virtual void vph7();
    virtual void vph8();
    virtual void vph9();
    virtual void vph10();
    virtual void vph11();
    virtual void vph12();
    virtual void vph13();
    virtual void vph14();
    virtual void vph15();
    virtual void vph16();
    virtual void vph17();
    virtual void vph18();
    virtual void vph19();
    virtual void vph20();
    virtual void vph21();
    virtual void vph22();
    virtual void vph23();
    virtual void vph24();
    virtual void vph25();
    virtual void vph26();
    virtual void vph27();
    virtual void vph28();
    virtual void vph29();
    virtual void vph30();
    virtual void vph31();
    virtual void vph32();
    virtual void vph33();
    virtual void vph34();
    virtual void vph35();
    virtual void vph36();
    virtual void vph37();
    virtual void vph38();
    virtual void vph39();
    virtual void vph40();
    virtual void vph41();
    virtual void vph42();
    virtual void vph43();
    virtual void vph44();
    virtual void vph45();
    virtual void vph46();
    virtual void vph47();
    virtual void vph48();
    virtual void vph49();
    virtual void vph50();
    virtual void vph51();
    virtual void vph52();
    virtual void vph53();
    virtual void vph54();
    virtual void f_dc(void* b, int a);
    virtual void vph56();
    virtual void vph57();
    virtual void f_e8(void* b);
    virtual void vph59();
    virtual void vph60();
    virtual void vph61();
    virtual void vph62();
    virtual void vph63();
    virtual unsigned char f100();
    virtual void* f104();
    virtual unsigned char f108(NiPoint3* p);
    virtual void vph67();
    virtual int f110(void* b);
};
struct P2Obj;
struct AObj
{
    virtual void vph0();
    virtual void vph1();
    virtual void vph2();
    virtual void vph3();
    virtual void vph4();
    virtual void vph5();
    virtual void vph6();
    virtual void vph7();
    virtual void vph8();
    virtual void vph9();
    virtual void vph10();
    virtual void vph11();
    virtual void vph12();
    virtual void vph13();
    virtual void vph14();
    virtual void vph15();
    virtual void vph16();
    virtual void vph17();
    virtual void vph18();
    virtual void vph19();
    virtual void vph20();
    virtual void vph21();
    virtual void vph22();
    virtual void vph23();
    virtual void vph24();
    virtual void vph25();
    virtual void vph26();
    virtual void vph27();
    virtual void vph28();
    virtual void vph29();
    virtual void vph30();
    virtual void vph31();
    virtual void vph32();
    virtual void vph33();
    virtual void vph34();
    virtual void vph35();
    virtual void vph36();
    virtual void vph37();
    virtual void vph38();
    virtual void vph39();
    virtual void vph40();
    virtual void vph41();
    virtual void vph42();
    virtual void vph43();
    virtual void vph44();
    virtual void vph45();
    virtual void vph46();
    virtual void vph47();
    virtual void vph48();
    virtual void vph49();
    virtual void vph50();
    virtual void vph51();
    virtual void vph52();
    virtual void vph53();
    virtual void vph54();
    virtual void vph55();
    virtual void vph56();
    virtual void vph57();
    virtual void vph58();
    virtual void vph59();
    virtual void vph60();
    virtual void vph61();
    virtual void vph62();
    virtual void vph63();
    virtual unsigned char f100();
    virtual void vph65();
    virtual void vph66();
    virtual void vph67();
    virtual void vph68();
    virtual void vph69();
    virtual void vph70();
    virtual void vph71();
    virtual void vph72();
    virtual void vph73();
    virtual void vph74();
    virtual void vph75();
    virtual void vph76();
    virtual void vph77();
    virtual void vph78();
    virtual void vph79();
    virtual void vph80();
    virtual void vph81();
    virtual void vph82();
    virtual void vph83();
    virtual void vph84();
    virtual void vph85();
    virtual void vph86();
    virtual void vph87();
    virtual void vph88();
    virtual void vph89();
    virtual void vph90();
    virtual void vph91();
    virtual void vph92();
    virtual void vph93();
    virtual void vph94();
    virtual void vph95();
    virtual void vph96();
    virtual void vph97();
    virtual void vph98();
    virtual void vph99();
    virtual void vph100();
    virtual void vph101();
    virtual void vph102();
    virtual void vph103();
    virtual void vph104();
    virtual void vph105();
    virtual void vph106();
    virtual void vph107();
    virtual void vph108();
    virtual void vph109();
    virtual void vph110();
    virtual void vph111();
    virtual void vph112();
    virtual void vph113();
    virtual void vph114();
    virtual void vph115();
    virtual P2Obj* f1d0();
};
struct P2Obj
{
};
struct FUN_0043d450_Owner
{
};
struct FUN_009611e0_shell
{
};
struct CellMirror
{
    char pad00[0xc4];
    char* f_c4;
};
struct FGModelMap
{
};
class ActiveEffect;
struct NonActorMagicTarget
{
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
};
class BSPortalGraph
{
  public:
};
struct HighActorCullerCell
{
};
struct ArrHelper
{
};
struct BSMultiBoundRoom
{
};
struct TESObjectREFR_GetFlags_caller
{
};
struct ListStandIn
{
};
struct SSNode
{
};
struct FUN_0045c4c0_cls
{
};

class AnimIdle;
}  // namespace fnv_005497c0
template <> class NiPointer<fnv_005497c0::AnimIdle>
{
  public:
    fnv_005497c0::AnimIdle* m_pObject;
    NiPointer(fnv_005497c0::AnimIdle* p);
    ~NiPointer();
    fnv_005497c0::AnimIdle* operator->() const;
};
namespace fnv_005497c0 {

struct BSOcclusionPlane
{
};
struct FUN_00422120_shell
{
};
ExtraDataList* FUN_005d43c0(TESObjectREFR* p1);

struct FUN_005497c0_shell : public TESObjectCELL
{
    bool FUN_005497c0(AObj* p1, P2Obj* p2, std::intptr_t p3, unsigned char* p4, unsigned char p5);
};
// @fnv 0x005497c0
bool FUN_005497c0_shell::FUN_005497c0(AObj* apRefr, P2Obj* apTarget, std::intptr_t p3, unsigned char* apbHandled,
                                      unsigned char p5)
{
    VObj* kIter_;
    ItemObj* item;
    bool foundFirst9;
    bool foundSecond3;
    bool usePt;
    NiPoint3 point;
    BSPortalGraph* graphH;
    BSPortalGraph* graph;
    point = *(NiPoint3*)((void *)((void *)(((FUN_006815c0*)((::fnv_005497c0::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((((FUN_0043d450_Owner*)apTarget)))->FUN_0043d450()))))));
    usePt = false;
    if (((::fnv_005497c0::BSOcclusionPlane *)(reinterpret_cast<::FUN_00422120_shell *>((((FUN_00422120_shell*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(((TESObjectREFR*)apRefr))->FUN_005d43c0())))))->FUN_00422120())) != 0)
    {
        point = *(NiPoint3*)((::NiPoint3 *)(reinterpret_cast<::TESTopicInfoData *>((((::fnv_005497c0::BSOcclusionPlane *)(reinterpret_cast<::FUN_00422120_shell *>((((FUN_00422120_shell*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(((TESObjectREFR*)apRefr))->FUN_005d43c0())))))->FUN_00422120()))))->GetLinkToList()));
        usePt = true;
    }
    NiPointer<AnimIdle> objTmp(0);
    reinterpret_cast<::Map62d0 *>((((FGModelMap*)(((CellMirror*)this)->f_c4 + 0x3c))))->FUN_006c62d0((std::uintptr_t)((void*)p3), (void **)&(*(GO*)&objTmp));
    if ((VObj*)(void*)objTmp.operator->() == 0 || ((VObj*)(void*)objTmp.operator->())->f104() == 0)
    {
        return false;
    }
    if (p5)
    {
        if (!reinterpret_cast<::FUN_0076b610_Class *>((void *)(((ArrHelper*)((::BSSimpleList< ::fnv_005497c0::ActiveEffect *> *)(reinterpret_cast<::NonActorMagicTarget *>((((NonActorMagicTarget*)((::fnv_005497c0::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((HighActorCullerCell*)this)))->FUN_009d9f20())))))->GetActiveEffectList())))))->FUN_0076b610())
        {
            if (!apRefr->f100())
            {
                graphH = ((::fnv_005497c0::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((HighActorCullerCell*)this)))->FUN_009d9f20()));
                reinterpret_cast<::Owner5b *>((graphH))->FUN_00c5b1c0((::RefObj5b *)(apTarget));
                if (reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0() != 0)
                {
                    if (!::FUN_008c7aa0())
                    {
                        ((VObj*)(void*)reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0())->f_e8(apTarget);
                    }
                    else
                    {
                        ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)(0));
                    }
                }
            }
            else
            {
                if (!::FUN_008c7aa0())
                {
                    ((VObj*)(void*)((FUN_0054a050_shell*)this)->FUN_0054a050())->f_dc(apTarget, 1);
                }
                else
                {
                    ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)(((FUN_0054a050_shell*)this)->FUN_0054a050()));
                }
            }
            *apbHandled = 1;
            return true;
        }
    }
    if ((VObj*)(void*)objTmp.operator->() != 0)
    {
        if (((VObj*)(void*)objTmp.operator->())->f108(&point) ||
            (p5 && ((VObj*)(void*)objTmp.operator->())->f110(((::fnv_005497c0::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((((FUN_0043d450_Owner*)apTarget)))->FUN_0043d450())))))
        {
            reinterpret_cast<::fnv_00569ae0::XActor *>((apRefr))->FUN_00569ae0((::fnv_00569ae0::FUN_00439f90_shell *)(p3));
            if (p5)
            {
                if (*apbHandled)
                {
                    if (!apRefr->f100())
                    {
                        graph = ((::fnv_005497c0::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((HighActorCullerCell*)this)))->FUN_009d9f20()));
                        reinterpret_cast<::Owner5b *>((graph))->FUN_00c5b1c0((::RefObj5b *)(apTarget));
                        if (reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0() != 0)
                        {
                            if (!::FUN_008c7aa0())
                            {
                                ((VObj*)(void*)reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0())->f_e8(apTarget);
                            }
                            else
                            {
                                ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)(0));
                            }
                        }
                    }
                    else
                    {
                        if (!::FUN_008c7aa0())
                        {
                            ((VObj*)(void*)((FUN_0054a050_shell*)this)->FUN_0054a050())->f_dc(apTarget, 1);
                        }
                        else
                        {
                            ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)(((FUN_0054a050_shell*)this)->FUN_0054a050()));
                        }
                    }
                    return true;
                }
            }
            kIter_ = (VObj*)((VObj*)(void*)objTmp.operator->())->f104();
            if (usePt)
            {
                reinterpret_cast<::FUN_00c39a80_cls *>((kIter_))->FUN_00c39a80((std::uintptr_t)(((::fnv_005497c0::BSOcclusionPlane *)(reinterpret_cast<::FUN_00422120_shell *>((((FUN_00422120_shell*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(((TESObjectREFR*)apRefr))->FUN_005d43c0())))))->FUN_00422120()))));
                return true;
            }
            foundSecond3 = 0;
            foundFirst9 = 0;
            if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_caller*)reinterpret_cast<::BSMultiBoundRoom *>((((BSMultiBoundRoom*)kIter_)))->FUN_006ab360())))->GetName())) > 0)
            {
                FUN_0045c620 big4;
                big4.arr = *(Inner52*)::FUN_00461130((std::intptr_t)apTarget);
                big4.flagA3 = 0;
                big4.iter = ((NiPointer<AnimIdle>*)reinterpret_cast<::BSMultiBoundRoom *>((((BSMultiBoundRoom*)kIter_)))->FUN_006ab360())->operator->();
                item = 0;
                while (!!big4.iter)
                {
                    ItemObj* p = (ItemObj*)*(
                        reinterpret_cast<::ListStandIn *>((((ListStandIn*)reinterpret_cast<::BSMultiBoundRoom *>((((BSMultiBoundRoom*)kIter_)))->FUN_006ab360())))->FUN_0057cbe0((int**)&big4.iter));
                    if (p != 0)
                    {
                        bool found3 = false;
                        if (big4.flagA3)
                        {
                            found3 = reinterpret_cast<::RectangleClip *>((((SSNode*)p)))->FUN_00c33cf0((::ClipVolume *)(void *)(&big4), 0, *(NiPoint3*)&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO)));
                        }
                        else
                        {
                            found3 = ((bool)(reinterpret_cast<::BoxInput *>((p))->FUN_00c34890((const ::SphereInput *)(void *)(((::fnv_005497c0::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((((FUN_0043d450_Owner*)apTarget)))->FUN_0043d450()))))));
                        }
                        if (found3)
                        {
                            if (foundFirst9 == 0)
                            {
                                item = p;
                                foundFirst9 = 1;
                            }
                            else
                            {
                                foundSecond3 = 1;
                                if (reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0() !=
                                    (std::uintptr_t)(void*)this->GetDynamicNode())
                                {
                                    if (!apRefr->f100())
                                    {
                                        if (!apRefr->f100())
                                        {
                                            BSPortalGraph* graph9 = ((::fnv_005497c0::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((HighActorCullerCell*)this)))->FUN_009d9f20()));
                                            reinterpret_cast<::Owner5b *>((graph9))->FUN_00c5b1c0((::RefObj5b *)(apTarget));
                                            if (reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0() != 0)
                                            {
                                                if (!::FUN_008c7aa0())
                                                {
                                                    ((VObj*)(void*)reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0())
                                                        ->f_e8(apTarget);
                                                }
                                                else
                                                {
                                                    ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)(0));
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (!::FUN_008c7aa0())
                                            {
                                                ((VObj*)(void*)((FUN_0054a050_shell*)this)->FUN_0054a050())
                                                    ->f_dc(apTarget, 1);
                                            }
                                            else
                                            {
                                                ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)(((FUN_0054a050_shell*)this)->FUN_0054a050()));
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
                if (foundFirst9)
                {
                    if (!foundSecond3)
                    {
                        if (reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apRefr->f1d0())))->FUN_009611e0() !=
                            (int)reinterpret_cast<::FUN_0045c4c0_cls *>((((FUN_0045c4c0_cls*)item)))->FUN_0045c4c0())
                        {
                            {
                                BSPortalGraph* graph;
                                graph = ((::fnv_005497c0::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((HighActorCullerCell*)this)))->FUN_009d9f20()));
                                NiPointer<AnimIdle> obj2(0);
                                reinterpret_cast<::fnv_00c5b370::ItemQueue *>((graph))->FUN_00c5b370((::fnv_00c5b370::RefObject *)(apTarget));
                                if (!::FUN_008c7aa0())
                                {
                                    ((VObj*)(void*)(std::uintptr_t)reinterpret_cast<::FUN_0045c4c0_cls *>((((FUN_0045c4c0_cls*)item)))->FUN_0045c4c0())->f_dc(apTarget, 1);
                                }
                                else
                                {
                                    ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)((void*)(std::uintptr_t)reinterpret_cast<::FUN_0045c4c0_cls *>((((FUN_0045c4c0_cls*)item)))->FUN_0045c4c0()));
                                }
                            }
                        }
                    }
                }
            }
            if (!foundFirst9)
            {
                if (reinterpret_cast<::FUN_009611e0_shell *>((((FUN_009611e0_shell*)apTarget)))->FUN_009611e0() != (std::uintptr_t)(VObj*)(void*)objTmp.operator->())
                {
                    {
                        BSPortalGraph* graph;
                        graph = ((::fnv_005497c0::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((HighActorCullerCell*)this)))->FUN_009d9f20()));
                        NiPointer<AnimIdle> _obj3(0);
                        reinterpret_cast<::fnv_00c5b370::ItemQueue *>((graph))->FUN_00c5b370((::fnv_00c5b370::RefObject *)(apTarget));
                        if (!::FUN_008c7aa0())
                        {
                            ((VObj*)(void*)objTmp.operator->())->f_dc(apTarget, 1);
                        }
                        else
                        {
                            ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(apRefr), (::NiNode *)(void *)((VObj*)(void*)objTmp.operator->()));
                        }
                    }
                }
            }
            *apbHandled = 1;
            if (!p5 || foundSecond3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
endFalse:
    return false;
}
}  // namespace fnv_005497c0

struct Obj;
struct Ref;
struct Extra;
struct Plane;
struct Graph;
struct Obj
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
    virtual void Attach(Obj*, bool);
    virtual void v0e0();
    virtual void v0e4();
    virtual void Detach(Obj*);
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual Obj* IsSceneNode();
    Ref* Owner();
};
struct Form
{
    unsigned int Type();
};
struct Ref
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
    virtual Obj* Get3D();
    bool Test2(Ref*);
    void Update(Ref*);
};
struct Plane
{
};
struct Link
{
};
struct Extra
{
    Obj* Find(Ref*);
};
struct Ptr
{
    Obj* ptr;
    Ptr(Obj*);
    ~Ptr();
    operator Obj*() const;
    Ptr& operator=(Obj*);
};
struct VisitMap
{
    virtual ~VisitMap();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    VisitMap(unsigned int, bool);
};

struct Map
{
};
struct Loaded
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    Map map;
};
struct List
{
    operator void*() const;
};
struct Graph
{
};
struct Task
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    Task(Ref*, Obj*);
};
struct Item;
struct Manager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual void Queue(Task*);
public:
    void FUN_00b6da10(::Item *);
};
struct Settings
{
};
extern Form* markerA;
extern Form* markerB;
extern Ref* player;
struct Pending
{
};
struct Cell
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    Loaded* loaded;
    void UpdateRefPlacement(Ref*, bool, bool);
};
// Attaches the reference's NiAVObject to apParent (or detaches it), updates the path handler and shadow scene node, then releases the cell lock.
// @fnv 0x005496b0
void FUN_005496b0_shell::FUN_005496b0(TESObjectREFR* apRef, NiNode* apParent)
{
    NiAVObject* pnewchild;
    if (!apRef || !((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((RefA*)apRef)))->FUN_0043fcd0())))
        return;
    CellRefLockEnter();
    pnewchild = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((RefA*)apRef)))->FUN_0043fcd0()));
    if (apParent)
    {
        ((void(*)(NiNode*, NiAVObject*, int))(*(void***)apParent)[0xdc / 4])(apParent, pnewchild, 1);
    }
    else if (((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((pnewchild))->FUN_009611e0())))
    {
        ((NiNodeV*)((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((pnewchild))->FUN_009611e0())))->InsertChild(pnewchild);
    }
    if (!apParent || ((NiAVObject*)apParent != GetDynamicNode() &&
                      !((int(*)(NiNode*))(*(void***)apParent)[0x14 / 4])(apParent)))
        reinterpret_cast<::Cell *>((((DetailedActorPathHandler*)this)))->UpdateRefPlacement((::Ref *)(apRef), true, false);
    reinterpret_cast<::S00b5d9f0_Owner *>((NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->FUN_00b5d9f0(
        (::S00b5d9f0_Obj *)(::NiAVObject *)(((NiAVObject * (*)(TESObjectREFR*))(*(void***)apRef)[0x1d0 / 4])(apRef)), false);
    ::FUN_00541ae0((char *)this);
}

// Checks the reference against markers and settings, tries linked and map nodes to attach its 3D, and falls back to graph planes or default nodes.
// @fnv 0x0054a070
void Cell::UpdateRefPlacement(Ref* ref, bool force, bool skip)
{
    if (!ref || !ref->Get3D())
        return;
    if (((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<::Form * *>(&::DAT_011ca23c)) || ((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<::Form * *>(&::DAT_011ca238)) || ((::Obj *)(reinterpret_cast<::FUN_009611e0_shell *>((ref->Get3D()))->FUN_009611e0())) == ((::Obj *)(reinterpret_cast<::TESObjectCELL *>(this)->GetDynamicNode())))
        return;
    bool enabled = false;
    bool foundUnused = false;
    bool seenFlag;
    bool blocked2;
    if (((bool)(reinterpret_cast<::GlobalObject_0045cf30 *>(&((*reinterpret_cast<::Settings *>(&::g_011ca118))))->GetBoolValue())) && ref && !((::Ref *)(reinterpret_cast<::FUN_00421e10_shell *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00421e10())))
    {
        switch (((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->Type())
        {
        case 42:
        case 43:
        case 44:
        case 45:
        case 51:
        case 81:
            break;
        default:
            enabled = true;
        }
    }
    if (enabled || force)
    {
        Ptr object10(ref->Get3D());
        if (ref == player)
            object10 = ((::Obj *)(::FUN_00950be0((bool *)(player))));
        bool success4 = false;
        seenFlag = false;
        blocked2 = false;
        VisitMap visited3(37, false);
        Ref* linked30 = ((::Ref *)(reinterpret_cast<::FUN_00421e10_shell *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00421e10()));
        if (linked30 && !skip)
        {
            reinterpret_cast<::FUN_005594e0_cls *>(&(visited3))->FUN_005594e0((std::uintptr_t)(linked30), true);
            success4 = reinterpret_cast<::fnv_005497c0::FUN_005497c0_shell *>(this)->FUN_005497c0((::fnv_005497c0::AObj *)(ref), (::fnv_005497c0::P2Obj *)(::Obj *)(object10), (std::intptr_t)(linked30), (unsigned char *)(bool *)(&blocked2), skip);
            if (!success4)
            {
                Link* link = ((::Link *)(reinterpret_cast<::fnv_004207b0::FUN_004207e0Class *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((linked30))->FUN_005d43c0()))))->FUN_004207b0()));
                while (link)
                {
                    Ref* owner = *((::Ref **)((void *)(link)));
                    if (owner)
                    {
                        Ref* candidate = ((::Ref *)(std::uintptr_t)(reinterpret_cast<::FUN_00420bc0_cls *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((owner))->FUN_005d43c0()))))->FUN_00420bc0(false)));
                        if (candidate)
                        {
                            reinterpret_cast<::FUN_005594e0_cls *>(&(visited3))->FUN_005594e0((std::uintptr_t)(candidate), true);
                            success4 = reinterpret_cast<::fnv_005497c0::FUN_005497c0_shell *>(this)->FUN_005497c0((::fnv_005497c0::AObj *)(ref), (::fnv_005497c0::P2Obj *)(::Obj *)(object10), (std::intptr_t)(candidate), (unsigned char *)(bool *)(&blocked2), skip);
                        }
                        if (!success4)
                        {
                            candidate = ((::Ref *)(std::uintptr_t)(reinterpret_cast<::FUN_00420bc0_cls *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((owner))->FUN_005d43c0()))))->FUN_00420bc0(true)));
                            if (candidate)
                            {
                                success4 = reinterpret_cast<::fnv_005497c0::FUN_005497c0_shell *>(this)->FUN_005497c0((::fnv_005497c0::AObj *)(ref), (::fnv_005497c0::P2Obj *)(::Obj *)(object10), (std::intptr_t)(candidate), (unsigned char *)(bool *)(&blocked2), skip);
                                reinterpret_cast<::FUN_005594e0_cls *>(&(visited3))->FUN_005594e0((std::uintptr_t)(candidate), true);
                            }
                        }
                    }
                    link = ((::Link *)(reinterpret_cast<::Callees *>((link))->FUN_00726070()));
                }
            }
        }
        void* pos33 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(loaded->map))->GetFirstPos();
        while (pos33 && !success4)
        {
            Ptr nodeTmp(0);
            Ref* key33 = 0;
            reinterpret_cast<::Map62d0 *>(&(loaded->map))->FUN_00559120((::MapItem62d0 *&)(pos33), (void *&)(key33), (::Helper62d0 &)(nodeTmp));
            if (key33 && (Obj*)nodeTmp && !reinterpret_cast<::FUN_0057c850_cls *>(&(visited3))->FUN_0057c850(key33, &seenFlag))
            {
                if (!enabled && force && !((Obj*)nodeTmp)->IsSceneNode())
                    continue;
                Ref* owner = ((::Ref *)(reinterpret_cast<::BSFaceGenNiNode *>((((Obj*)nodeTmp)))->GetAnimationData()));
                if (owner)
                {
                    if (reinterpret_cast<::B5695A0Ref *>((ref))->FUN_005695a0((::B5695A0Camera *)(owner)) && !force)
                    {
                        Obj* target = ((::Extra *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()))->Find(key33);
                        if (target)
                        {
                            target->Attach(ref->Get3D(), true);
                            success4 = true;
                            reinterpret_cast<::fnv_00569ae0::XActor *>((ref))->FUN_00569ae0((::fnv_00569ae0::FUN_00439f90_shell *)(key33));
                        }
                    }
                    else
                    {
                        if (((Obj*)nodeTmp)->IsSceneNode())
                        {
                            if (reinterpret_cast<::fnv_005497c0::FUN_005497c0_shell *>(this)->FUN_005497c0((::fnv_005497c0::AObj *)(ref), (::fnv_005497c0::P2Obj *)(::Obj *)(object10), (std::intptr_t)(key33), (unsigned char *)(bool *)(&blocked2), skip))
                            {
                                success4 = true;
                                break;
                            }
                        }
                        else
                        {
                            if (ref->Test2(owner))
                            {
                                reinterpret_cast<::FUN_00844700_Class *>(&((*reinterpret_cast<::Pending *>(&::g_011ca0e0))))->FUN_00844700((std::uintptr_t)(ref), (std::uintptr_t)(key33));
                                Obj* original9 = ref->Get3D();
                                Task* taskA = new Task(key33, original9);
                                (*reinterpret_cast<::Manager * *>(&::DAT_01202d98))->Queue(taskA);
                                Graph* graph8 = ((::Graph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
                                Ptr unused(0);
                                reinterpret_cast<::fnv_00c5b370::ItemQueue *>((graph8))->FUN_00c5b370((::fnv_00c5b370::RefObject *)(::Obj *)(ref->Get3D()));
                            }
                        }
                    }
                }
            }
        }
        if (!success4 && !blocked2)
        {
            Graph* graph8 = ((::Graph *)(reinterpret_cast<::FUN_00545b30_shell *>(this)->GetPortalGraph()));
            void* iter6 = (void*)*((::List *)(reinterpret_cast<::NonActorMagicTarget *>((graph8))->GetActiveEffectList()));
            Plane* selected6 = 0;
            bool contains8 = false;
            bool multiple3 = false;
            bool any5 = false;
            Obj* original9 = ref->Get3D();
            while (iter6 && !multiple3)
            {
                Plane* plane = ((::Plane *)(reinterpret_cast<::ListStandIn *>((((::List *)(reinterpret_cast<::NonActorMagicTarget *>((graph8))->GetActiveEffectList()))))->FUN_0057cbe0((int **)&(iter6))));
                contains8 = ((bool)(reinterpret_cast<::BoxInput *>((plane))->FUN_00c34890((const ::SphereInput *)(void *)(((void *)(reinterpret_cast<::FUN_0043d450_Owner *>((original9))->FUN_0043d450()))))));
                if (contains8)
                {
                    if (!any5)
                    {
                        any5 = true;
                        selected6 = plane;
                    }
                    else
                    {
                        selected6 = 0;
                        multiple3 = true;
                    }
                }
            }
            if (selected6)
            {
                Ptr unused(0);
                reinterpret_cast<::fnv_00c5b370::ItemQueue *>((graph8))->FUN_00c5b370((::fnv_00c5b370::RefObject *)(original9));
                if (!FUN_008c7aa0())
                    ((::Obj *)(std::uintptr_t)(reinterpret_cast<::FUN_0045c4c0_cls *>((selected6))->FUN_0045c4c0()))->Attach(original9, true);
                else
                    ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(ref), (::NiNode *)(::Obj *)(((::Obj *)(std::uintptr_t)(reinterpret_cast<::FUN_0045c4c0_cls *>((selected6))->FUN_0045c4c0()))));
                success4 = true;
            }
            else
            {
                if (multiple3)
                {
                    if (((::Obj *)(reinterpret_cast<::FUN_009611e0_shell *>((original9))->FUN_009611e0())) != ((::Obj *)(reinterpret_cast<::TESObjectCELL *>(this)->GetDynamicNode())) && !ref->IsActor())
                    {
                        if (!ref->IsActor())
                        {
                            Graph* graph2 = ((::Graph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
                            reinterpret_cast<::Owner5b *>((graph2))->FUN_00c5b1c0((::RefObj5b *)(original9));
                            if (((::Obj *)(reinterpret_cast<::FUN_009611e0_shell *>((original9))->FUN_009611e0())))
                            {
                                if (!FUN_008c7aa0())
                                    ((::Obj *)(reinterpret_cast<::FUN_009611e0_shell *>((original9))->FUN_009611e0()))->Detach(original9);
                                else
                                    ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(ref), (::NiNode *)(::Obj *)(0));
                            }
                        }
                        else
                        {
                            if (!FUN_008c7aa0())
                                ((::Obj *)(reinterpret_cast<::FUN_0054a050_shell *>(this)->FUN_0054a050()))->Attach(original9, true);
                            else
                                ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(ref), (::NiNode *)(::Obj *)(((::Obj *)(reinterpret_cast<::FUN_0054a050_shell *>(this)->FUN_0054a050()))));
                        }
                    }
                    success4 = true;
                }
            }
        }
        if (!success4 && !blocked2)
        {
            if (ref->IsActor())
            {
                if (!FUN_008c7aa0())
                    ((::Obj *)(reinterpret_cast<::FUN_0054a050_shell *>(this)->FUN_0054a050()))->Attach(ref->Get3D(), true);
                else
                    ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(ref), (::NiNode *)(::Obj *)(((::Obj *)(reinterpret_cast<::FUN_0054a050_shell *>(this)->FUN_0054a050()))));
            }
            else
            {
                if (!FUN_008c7aa0())
                    ((::Obj *)(::FUN_0054aa60((::TESObjectCELL *)this)))->Attach(ref->Get3D(), true);
                else
                    ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(ref), (::NiNode *)(::Obj *)(((::Obj *)(::FUN_0054aa60((::TESObjectCELL *)this)))));
            }
        }
    }
    if (((::Plane *)(reinterpret_cast<::FUN_00422120_shell *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00422120())) && !((::Ref *)(reinterpret_cast<::FUN_00421e10_shell *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00421e10())))
    {
        Graph* graph8 = ((::Graph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
        reinterpret_cast<::S_00c5ae70_Class *>((graph8))->FUN_00c5ae70((std::intptr_t)(((::Plane *)(reinterpret_cast<::FUN_00422120_shell *>((((::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00422120()))));
    }
}

struct IOTask
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    IOTask(int n);
    virtual void v0();
    ~IOTask();
};
struct S_0054aa80_Src
{
};
struct FUN_0054aa80 : IOTask
{
    S_0054aa80_Src* unk18;
    NiPointer<NiAVObject> unk1c;
    NiPointer<NiAVObject> unk20;
    char unk24;
    FUN_0054aa80(S_0054aa80_Src* a, NiAVObject* b);
};
// Initializes an IOTask with task count 4, stores the source and object pointers, and assigns the source's FUN_00569920 result to unk20.
// @fnv 0x0054aa80
FUN_0054aa80::FUN_0054aa80(S_0054aa80_Src* pSource, NiAVObject* pObject)
    : IOTask(4), unk18(pSource), unk1c(pObject), unk20(0)
{
    unk24 = 0;
    unk20 = ((::NiAVObject *)(reinterpret_cast<::TESObjectREFR569 *>((pSource))->FUN_00569920()));
}

struct FUN_0096e150_shell
{
};

struct FUN_0054af40_cls : public TESObjectCELL
{
    void FUN_0054af40(unsigned char flag);
};

// Calls FUN_00541ac0, passes the result of FUN_009604f0(flag) to ProcessWorkerList on DAT_011e0e80, then calls FUN_00541ae0.
// @fnv 0x0054af40
void FUN_0054af40_cls::FUN_0054af40(unsigned char flag)
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    reinterpret_cast<::WorkerManager *>((((FUN_0096e150_shell*)&(*reinterpret_cast<::FUN_0096dcb0_shell *>(&::g_011e0e80)))))->ProcessWorkerList((::WorkerList *)(void *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()), {});
    ::FUN_00541ae0((char *)this);
}

struct Ref54;
struct Changes54;
struct Extra54 : ExtraDataList
{
};
struct Object54
{
    unsigned int FNV_GetFormType();
};
struct Ref54
{
    Extra54* FUN_005d43c0() const;
};
struct FUN_00410360 : Extra54
{
    FUN_00410360();
};
struct FUN_0096a2d0
{
    Extra54* item;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    void AddHead(Extra54** value);
};
struct FUN_004bc550
{
    FUN_0096a2d0* extraLists;
    int count;
    Object54* object;
    FUN_004bc550(Object54* object, int count);
};
struct Changes54
{
    void FUN_004d26d0(void* destination, Ref54* reference, bool flag);
};
struct Destination54
{
};
struct Node54
{
};
struct Cell54 : TESObjectCELL
{
    void FUN_0054b260(Ref54* actor, Destination54* destination);
};
// Locks the cell, iterates its references and hands each eligible one to destination via FUN_004c3380 or FUN_004d26d0, then unlocks.
// @fnv 0x0054b260
void Cell54::FUN_0054b260(Ref54* actor, Destination54* destination)
{
    if (!destination || !actor)
        return;
    Ref54* container = ((::Ref54 *)(reinterpret_cast<::fnv_00421400::FUN_00421400 *>((((::Extra54 *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(actor))->FUN_005d43c0()))))->GetMerchantContainer()));
    CellRefLockEnter();
    Node54* node = (Node54*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (node && *((::Ref54 **)((void *)(node))))
    {
        Ref54* reference;
        {
            Changes54* changes = 0;
            reference = *((::Ref54 **)((void *)(node)));
            {
                Extra54* extra = 0;
                if (!reinterpret_cast<::TESForm *>((reference))->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(reference))->FUN_00440d80() && reinterpret_cast<::OwnerLookupView *>((reference))->FUN_00567790() &&
                    reinterpret_cast<::OwnershipReferenceView *>((reference))->FUN_005785e0((::Actor *)(actor), false) && reference != container)
                {
                    if (reference != container)
                    {
                        Object54* object = ((::Object54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
                        {
                            FUN_004bc550* entry = 0;
                            switch (object->FNV_GetFormType())
                            {
                            case 0x73:
                                if (((::Extra54 *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(reference))->FUN_005d43c0())))
                                    reinterpret_cast<::FUN_00419ad0_shell *>((((::Extra54 *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(reference))->FUN_005d43c0()))))->FUN_00419ad0(1);
                                // Fall through to construct the inventory entry.
                            case 0x18:
                            case 0x19:
                            case 0x1a:
                            case 0x1d:
                            case 0x1e:
                            case 0x1f:
                            case 0x28:
                            case 0x29:
                            case 0x2e:
                            case 0x2f:
                            case 0x32:
                            case 0x67:
                            case 0x6c:
                            case 0x74:
                                entry = new FUN_004bc550(((::Object54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())), 0);
                                if (!entry->extraLists)
                                    entry->extraLists = new FUN_0096a2d0;
                                extra = new FUN_00410360;
                                reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((extra))->FUN_00412380((::ExtraDataList *)(::Extra54 *)(((::Extra54 *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(reference))->FUN_005d43c0()))));
                                reinterpret_cast<::fnv_00418550::FUN_00418550_cls *>((extra))->SetOriginalReference((::fnv_00418550::TESObjectREFR *)(reference));
                                reinterpret_cast<::FUN_0041aed0_shell *>((extra))->FUN_0041aed0();
                                entry->extraLists->AddHead(&extra);
                                reinterpret_cast<::CombatProcedure *>((entry))->Initialize((::CombatController *)(std::uintptr_t)(reinterpret_cast<::FUN_00418770_shell *>((((::Extra54 *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(reference))->FUN_005d43c0()))))->FUN_00418770()));
                                reinterpret_cast<::fnv_004c3380::FUN_004c3380_shell *>((destination))->FUN_004c3380((::InventoryStackRecord *)(entry), true);
                                break;
                            case 0x1b:
                                changes = ((::Changes54 *)(reinterpret_cast<::ExtraDataList *>((((::Extra54 *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(reference))->FUN_005d43c0()))))->GetContainerChangeData()));
                                if (changes)
                                    changes->FUN_004d26d0(destination, reference, false);
                                break;
                            }
                        }
                    }
                }
            }
        }
        node = ((::Node54 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}

struct X54
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual FUN_0054b800_class* GetObject();
};
struct Refr54
{
    X54* FUN_0043fcd0();
    virtual void vt0();
    virtual void vt1();
    virtual void vt2();
    virtual void vt3();
    virtual void vt4();
    virtual void vt5();
    virtual void vt6();
    virtual void vt7();
    virtual void vt8();
    virtual void vt9();
    virtual void vt10();
    virtual void vt11();
    virtual void vt12();
    virtual void vt13();
    virtual void vt14();
    virtual void vt15();
    virtual void vt16();
    virtual void vt17();
    virtual void vt18();
    virtual void vt19();
    virtual void vt20();
    virtual void vt21();
    virtual void vt22();
    virtual void vt23();
    virtual void vt24();
    virtual void vt25();
    virtual void vt26();
    virtual void vt27();
    virtual void vt28();
    virtual void vt29();
    virtual void vt30();
    virtual void vt31();
    virtual void vt32();
    virtual void vt33();
    virtual void vt34();
    virtual void vt35();
    virtual void vt36();
    virtual void vt37();
    virtual void vt38();
    virtual void vt39();
    virtual void vt40();
    virtual void vt41();
    virtual void vt42();
    virtual void vt43();
    virtual void vt44();
    virtual void vt45();
    virtual void vt46();
    virtual void vt47();
    virtual void vt48();
    virtual void vt49();
    virtual void vt50();
    virtual void vt51();
    virtual void vt52();
    virtual void vt53();
    virtual void vt54();
    virtual void vt55();
    virtual void vt56();
    virtual void vt57();
    virtual void vt58();
    virtual void vt59();
    virtual void vt60();
    virtual void vt61();
    virtual void vt62();
    virtual void vt63();
    virtual void vt64();
    virtual void vt65();
    virtual void vt66();
    virtual void vt67();
    virtual void vt68();
    virtual void vt69();
    virtual void vt70();
    virtual void vt71();
    virtual void vt72();
    virtual void vt73();
    virtual void vt74();
    virtual void vt75();
    virtual void vt76();
    virtual void vt77();
    virtual void vt78();
    virtual void vt79();
    virtual void vt80();
    virtual void vt81();
    virtual void vt82();
    virtual void vt83();
    virtual void vt84();
    virtual void vt85();
    virtual void vt86();
    virtual void vt87();
    virtual void vt88();
    virtual void vt89();
    virtual void vt90();
    virtual void vt91();
    virtual void vt92();
    virtual void vt93();
    virtual void vt94();
    virtual void vt95();
    virtual void vt96();
    virtual void vt97();
    virtual void vt98();
    virtual void vt99();
    virtual void vt100();
    virtual void vt101();
    virtual void vt102();
    virtual void vt103();
    virtual void vt104();
    virtual void vt105();
    virtual void vt106();
    virtual void vt107();
    virtual void vt108();
    virtual void vt109();
    virtual void vt110();
    virtual void vt111();
    virtual void vt112();
    virtual void vt113();
    virtual void vt114();
    virtual void RemoveCell(int a, int b);
};

extern Refr54* g_011dea3c;

struct Claim54b750
{
    void ProcessRefrList();
};

// @fnv 0x0054b750
void Claim54b750::ProcessRefrList()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    reinterpret_cast<::fnv_00545c10::FUN_00545c10_class *>(this)->ClearAdditionalGeometryData();
    void* node = reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0();
    while (node != 0)
    {
        Refr54* refr = (Refr54*)*((::RefObj **)((void *)(node)));
        node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (refr != 0 && refr != g_011dea3c)
        {
            X54* extra = ((::X54 *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((refr))->FUN_0043fcd0()));
            if (extra != 0)
            {
                FUN_0054b800_class* obj = extra->GetObject();
                if (obj != 0)
                {
                    obj->FUN_0054b800();
                }
            }
            refr->RemoveCell(0, 0);
        }
    }
    ::FUN_00541ae0((char *)this);
}

struct FormType
{
    unsigned int FUN_00401170();
};

struct FUN_0054bb90_shell : TESObjectCELL
{
    unsigned int CountReferencesWithFormType30();
};

// Locks cell references, walks the node list, and counts references whose object form type is 30, then unlocks and returns the count.
// @fnv 0x0054bb90
unsigned int FUN_0054bb90_shell::CountReferencesWithFormType30()
{
    CellRefLockEnter();
    unsigned int count = 0;
    NodeStub* node = (NodeStub*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));

    while (node)
    {
        RefStub* reference = *((::RefStub **)((void *)(node)));
        node = ((::NodeStub *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (reference)
        {
            switch (((FormType*)((::TESObjectSTAT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())))->FUN_00401170())
            {
            case 30:
                count++;
                break;
            }
        }
    }
    ::FUN_00541ae0((char *)this);
    return count;
}

namespace fnv_0054bc10 {
struct AnimData
{
    unsigned char FUN_00549580();
};
struct Resource
{
    Resource* FUN_00586170();
    void FUN_006fcfa0();
    void FUN_00929260();
};
struct RefEx : VClass1d0
{
};
struct CellStub
{
    Resource* FUN_0054ddd0();
    Resource* FUN_0054ddd0(RefEx* reference, bool flag);
    Resource* FUN_0054ddd0(bool flag);
    void ProcessCellReferences();
};
// @fnv 0x0054bc10
void CellStub::ProcessCellReferences()
{
    reinterpret_cast<::FUN_0054af40_cls *>(this)->FUN_0054af40(false);
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    NodeStub* pNode = ((::NodeStub *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pNode != 0)
    {
        RefEx* reference = reinterpret_cast<RefEx*>(*((::RefStub **)((void *)(pNode))));
        if (reference != 0)
        {
            reinterpret_cast<::fnv_0056f700::Ref *>((reference))->FUN_0056f700();
            if (((unsigned char)(reinterpret_cast<::FUN_00549580_shell *>((((::fnv_0054bc10::AnimData *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))))->FUN_00549580())))
            {
                if (reference->vfn_1d0())
                {
                    if (((::fnv_0054bc10::Resource *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())) != 0)
                    {
                        reinterpret_cast<::Dfcfa0Manager *>((((::fnv_0054bc10::Resource *)(reinterpret_cast<::TESWorldSpace *>((((::fnv_0054bc10::Resource *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->GetWorldTerrainManager()))))->FUN_006fcfa0({}, {});
                        reinterpret_cast<::MiddleHighProcess *>((((::fnv_0054bc10::Resource *)(reinterpret_cast<::TESWorldSpace *>((((::fnv_0054bc10::Resource *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->GetWorldTerrainManager()))))->FUN_00929260({});
                    }
                }
            }
        }
        pNode = ((::NodeStub *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_0054bc10

namespace fnv_0054c030 {
struct RotationPoint
{
    float x, y, z;
    RotationPoint();
    RotationPoint(float, float, float);
    RotationPoint FUN_0053d280(float) const;
};
struct RotationForm
{
    int FUN_00401170();
};
struct RotationList;
struct RotationExtra
{
};
struct RotationReference
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
    virtual const char* Name();
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
    virtual RotationPoint Position();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const RotationPoint& Rotation();
    RotationExtra* FUN_005d43c0(int);
    unsigned int FUN_0084e3a0();
};
struct RotationList
{
    RotationReference** FUN_006815c0();
};
struct RotationCell : RotationReference
{
    void FUN_0054cfd0(RotationPoint&, RotationPoint&);
    void ComputeCellRotationCenter(RotationPoint&);
};
extern const double DAT_0102efb8;
extern const char DAT_0102ef68[], DAT_0102ef18[], DAT_0102ee68[];
double FUN_00408840(float);
// Resets output, iterates the cell's reference list to gather rotation bounds, logs and resets outliers, and stores the midpoint of the min/max rotations.
// @fnv 0x0054c030
void RotationCell::ComputeCellRotationCenter(RotationPoint& aRotationCenter)
{
    aRotationCenter = (*reinterpret_cast<const ::fnv_0054c030::RotationPoint *>((void *)&::NiPoint3::ZERO));
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    int count = 0;
    RotationPoint minimum(::DAT_01016970, ::DAT_01016970, ::DAT_01016970);
    RotationPoint aMaximum(::DAT_0102efc4, ::DAT_0102efc4, ::DAT_0102efc4);
    RotationList* cursorB = ((::fnv_0054c030::RotationList *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (cursorB)
    {
        RotationReference* ref = *((::fnv_0054c030::RotationReference **)((void *)(cursorB)));
        if (ref && ((::fnv_0054c030::RotationForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())))
        {
            bool include = true;
            switch (((::fnv_0054c030::RotationForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FUN_00401170())
            {
            case 30:
            case 42:
            case 43:
            case 44:
            case 45:
                include = false;
                break;
            default: {
                bool different = false;
                if (count)
                {
                    RotationPoint midpoint3 = (*(::fnv_0054c030::RotationPoint *)(reinterpret_cast<::Point3Offset *>((void *)&(minimum))->ProjectileLaunched((::NiPoint3 *)&(aMaximum), {}))).FUN_0053d280(::DAT_010162c0);
                    RotationPoint delta;
                    delta = (*(::fnv_0054c030::RotationPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(midpoint3))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(ref->Rotation())))));
                    different = FUN_00408840(delta.x) > ::FUN_004587d0(DAT_0102efc0) ||
                                FUN_00408840(delta.y) > ::FUN_004587d0(DAT_0102efc0) ||
                                FUN_00408840(delta.z) > ::FUN_004587d0(DAT_0102efc0);
                }
                if (FUN_00408840(ref->Rotation().x) > DAT_0102efb8 || FUN_00408840(ref->Rotation().y) > DAT_0102efb8 ||
                    different)
                {
                    bool reset = true;
                    if (((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((((::fnv_0054c030::RotationExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_00410220({}))))
                    {
                        ::FUN_005b5e40();
                        reinterpret_cast<::Reference *>((ref))->FUN_00575830((::Position *)&(const ::fnv_0054c030::RotationPoint &)(ref->Position()));
                        if (different)
                        {
                            RotationPoint midpoint2 = (*(::fnv_0054c030::RotationPoint *)(reinterpret_cast<::Point3Offset *>((void *)&(minimum))->ProjectileLaunched((::NiPoint3 *)&(aMaximum), {}))).FUN_0053d280(::DAT_010162c0);
                            RotationPoint delta2;
                            delta2 = (*(::fnv_0054c030::RotationPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(midpoint2))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(ref->Rotation())))));
                            different = FUN_00408840(delta2.x) > ::FUN_004587d0(DAT_0102efc0) ||
                                        FUN_00408840(delta2.y) > ::FUN_004587d0(DAT_0102efc0) ||
                                        FUN_00408840(delta2.z) > ::FUN_004587d0(DAT_0102efc0);
                        }
                        if (FUN_00408840(ref->Rotation().x) < DAT_0102efb8 &&
                            FUN_00408840(ref->Rotation().y) < DAT_0102efb8 && !different)
                            reset = false;
                    }
                    if (reset)
                    {
                        ::FUN_005b5e40();
                        RotationPoint position;
                        RotationPoint rotation_;
                        FUN_0054cfd0(position, rotation_);
                        reinterpret_cast<::Reference *>((ref))->FUN_00575830((::Position *)&(position));
                        include = false;
                    }
                }
            }
            break;
            }
            if (include)
            {
                minimum.x = ::FUN_0040ebd0(minimum.x, ref->Rotation().x);
                minimum.y = ::FUN_0040ebd0(minimum.y, ref->Rotation().y);
                minimum.z = ::FUN_0040ebd0(minimum.z, ref->Rotation().z);
                aMaximum.x = ::FUN_00404010(aMaximum.x, ref->Rotation().x);
                aMaximum.y = ::FUN_00404010(aMaximum.y, ref->Rotation().y);
                aMaximum.z = ::FUN_00404010(aMaximum.z, ref->Rotation().z);
                ++count;
            }
        }
        cursorB = ((::fnv_0054c030::RotationList *)(reinterpret_cast<::Callees *>((cursorB))->FUN_00726070()));
    }
    if (count > 0)
    {
        RotationPoint span = (*(::fnv_0054c030::RotationPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(aMaximum))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(minimum)))));
        if (span.x > ::FUN_004587d0(DAT_0102efc0) || span.y > ::FUN_004587d0(DAT_0102efc0) ||
            span.z > ::FUN_004587d0(DAT_0102efc0))
        {
            ::FUN_005b5e40();
        }
        aRotationCenter = (*(::fnv_0054c030::RotationPoint *)(reinterpret_cast<::Point3Offset *>((void *)&(minimum))->ProjectileLaunched((::NiPoint3 *)&(aMaximum), {}))).FUN_0053d280(::DAT_010162c0);
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_0054c030

struct MoveWorld;
struct MovePosition
{
    float x;
    float y;
    float z;
};
struct MoveRef
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual unsigned int FormId();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual const MovePosition& Position();
    const char* FUN_0084e3a0();
};
struct MoveNode
{
    MoveRef** FUN_006815c0();
};
struct MoveCell
{
    void MoveReferencesToWorldCells(MoveWorld*);
};
struct MoveWorld : MoveRef
{
};
// Iterates the cell's references, converts each position to cell coordinates, and adds each reference to the matching cell in the given world, logging failures.
// @fnv 0x0054c8c0
void MoveCell::MoveReferencesToWorldCells(MoveWorld* world)
{

    if (world && reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
    {
        reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
        MoveNode* node = ((::MoveNode *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (node)
        {
            MoveRef* ref = *((::MoveRef **)((void *)(node)));
            if (ref)
            {
                int x = FUN_00406d90(ref->Position().x) >> 12;
                int y = FUN_00406d90(ref->Position().y) >> 12;
                MoveCell* cell = ((::MoveCell *)(reinterpret_cast<::TESWorldSpace *>((world))->GetCellAtGridPosition(x, y)));
                if (cell)
                {
                    reinterpret_cast<::CellView *>((cell))->FUN_00548230((::RefView *)(ref), false);
                }
                else
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            node = ((::MoveNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)this);
    }
}

namespace fnv_0054cd20 {
struct FormX
{
    int GetFormKind();
};

struct RefX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~RefX();
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
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void Disable(bool arg);
};

struct ListX
{
    bool IsEmpty();
    void RemoveHead();
};

struct DH
{
};

extern RefX* g_thePlayer;

struct CellX : public TESObjectCELL
{
    void Prepare();
    void ProcessCellRefs();
};

// @fnv 0x0054cd20
void CellX::ProcessCellRefs()
{
    CellRefLockEnter();
    Prepare();
    this->unka8 = 0;
    ListX* list = ((::fnv_0054cd20::ListX *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (list && !list->IsEmpty())
    {
        RefX* ref = *((::fnv_0054cd20::RefX **)((void *)(list)));
        if (ref != g_thePlayer)
        {
            bool skip = false;
            if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent() && (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)) && !reinterpret_cast<::FUN_004226e0_shell *>((((DH*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->FUN_004226e0())
                skip = true;
            if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((ref))->FUN_005653d0() && !reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && !skip)
            {
                if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
                    delete ref;
                else
                    ref->Disable(false);
            }
            else
            {
                if (((::fnv_0054cd20::FormX *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) && ((::fnv_0054cd20::FormX *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->GetFormKind() == 0x23)
                {
                    FormX* space = ((::fnv_0054cd20::FormX *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
                    if (reinterpret_cast<::FUN_00452440_shell *>((space))->FUN_00452440())
                        reinterpret_cast<::fnv_00558ba0::FUN_00558ba0_shell *>(this)->FUN_00558ba0((std::intptr_t)(ref));
                }
                ::FUN_00867f90((::GcRef *)(ref));
            }
            ((::fnv_0054cd20::ListX *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))->RemoveHead();
        }
        else
        {
            ((::fnv_0054cd20::ListX *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))->RemoveHead();
            ref->Disable(false);
        }
        list = ((::fnv_0054cd20::ListX *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_0054cd20

struct RefEntry;
struct RefObject
{
};
struct RefWrapper
{
    RefObject* reference;
};
struct RefEntry
{
    bool FUN_008256d0();
    RefWrapper* FUN_006815c0();
};
struct CellRefScan
{
    RefObject* FindFirstRefByType(std::intptr_t typeId, bool filtered);
};
// Scans the cell's ref entries and returns the first reference whose type matches typeId, optionally skipping filtered ones.
// @fnv 0x0054cf20
RefObject* CellRefScan::FindFirstRefByType(std::intptr_t typeId, bool filtered)
{
    if (!typeId)
        return 0;
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    RefEntry* current = ((::RefEntry *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    int itemType;
    RefObject* reference;
    while (current && !current->FUN_008256d0())
    {
        reference = ((::RefWrapper *)((void *)(current)))->reference;
        itemType = ((int)(std::uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
        current = ((::RefEntry *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
        if (itemType && (!filtered || !reinterpret_cast<::FUN_00440d80_shell *>((reference))->FUN_00440d80()) && itemType == typeId)
        {
            ::FUN_00541ae0((char *)this);
            return reference;
        }
    }
    ::FUN_00541ae0((char *)this);
    return 0;
}

struct MarkerBase
{
    int FUN_00401170();
};
struct MarkerData;
struct MarkerRef
{
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
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual NiPoint3* Position();
    NiPoint3* FUN_00430830();
};
struct MarkerData
{
};
struct MarkerList
{
    bool _ref_008256d0();
};
struct MarkerLand
{
};
struct MarkerCell : TESObjectCELL
{
    void FUN_0054d090(NiPoint3* position, NiPoint3* angle);
    bool FUN_00425fd0();
    bool FUN_00550200(NiPoint3*);
};
class Point54D
{
  public:
    float x, y, z;

    Point54D operator-(const Point54D& pt) const;
    float SqrLength() const;
};

class Form54D
{
  public:
    int GetFormType();
};


class Ref54D
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
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual const Point54D& GetPos();

};

class RefNode54D
{
  public:
};

class RefArray54D
{
  public:
};

class Cell54D
{
  public:

    unsigned int FUN_0054dc00(const Point54D& kPos, float fRadius, RefArray54D* pkResults);
};

// @fnv 0x0054dc00
unsigned int Cell54D::FUN_0054dc00(const Point54D& kPos, float afRadius, RefArray54D* pkResults)
{
    if (!pkResults)
        return 0;

    float fRadiusSqr = afRadius * afRadius;
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    RefNode54D* pkNode = ((::RefNode54D *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pkNode)
    {
        Ref54D* pkRef = *((::Ref54D **)((void *)(pkNode)));
        if (pkRef && !reinterpret_cast<::FUN_00437b90_shell *>((pkRef))->FUN_00437b90())
        {
            Form54D* pkBase = ((::Form54D *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkRef))->FUN_007af430()));
            if (pkBase->GetFormType() == 0x1c && pkBase != (*reinterpret_cast<::Form54D * *>(&::DAT_011ca258)) && ((std::uintptr_t)(reinterpret_cast<::TESObjectREFR *>((pkRef))->GetExtraRadioData())))
            {
                Point54D kDiff = kPos - pkRef->GetPos();
                if (reinterpret_cast<::TESCombatStyle *>((void *)&(kDiff))->UpdateCombatStyle() < fRadiusSqr)
                    reinterpret_cast<::FUN_00438690 *>((pkResults))->FUN_007cb2e0((unsigned int *)&(pkRef));
            }
        }
        pkNode = ((::RefNode54D *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
    return ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pkResults))->GetName()));
}

struct RenderPoint
{
    float x, y, z;
};
struct RenderMatrix
{
    RenderMatrix();
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct RenderFrustum
{
    RenderFrustum(bool);
    float left, right, top, bottom, nearDist, farDist;
    bool ortho;
};
struct RenderUpdate
{
    RenderUpdate(float, bool, bool);
    float time;
    bool a, b;
    int flags;
};
struct RenderObject
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
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
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void Attach(RenderObject*, bool);
    virtual void slote0();
    virtual void slote4();
    virtual void Detach(RenderObject*);
    void Update(RenderUpdate&);
};
struct RenderCamera : RenderObject
{
    RenderCamera();
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
};
struct RenderNode : RenderObject
{
    RenderNode(unsigned short);
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
};
struct RenderPtr
{
    RenderObject* ptr;
    RenderPtr(RenderObject*);
    ~RenderPtr();
    operator RenderObject*();
    RenderPtr& operator=(RenderObject*);
    RenderPtr& operator=(const RenderPtr&);
};
struct RenderRange
{
    float low, high;
    RenderRange();
};
struct RenderRangeSource
{
    RenderRange* FUN_0053f440();
};
struct RenderSource
{
    int a, b;
};
struct RenderSky
{
};
RenderObject* __cdecl FUN_00450b80(int);

unsigned char __cdecl FUN_0054f4b0();
struct CellRenderer
{
    void FUN_0054e830(RenderObject*, RenderPtr*);
    void BuildExteriorCameraScene(RenderPtr*);
};
struct Pt2
{
    float x;
    float y;
};

float FUN_0054fb20(float x1, float y1, float x2, float y2);

struct ThisC
{
    float FUN_0054fb70(Pt2* p);
};

// @fnv 0x0054fb70
float ThisC::FUN_0054fb70(Pt2* pPoint)
{
    int a = reinterpret_cast<::TESObjectCELL *>((this))->GetCellGridX();
    int b5 = reinterpret_cast<::TESObjectCELL *>((this))->GetCellGridY();
    float fA3 = (float)(a << 12);
    float fAhi = fA3 + 4096.0;
    float fB = (float)(b5 << 12);
    float fBhi = fB + 4096.0;
    if (pPoint->x < fA3)
    {
        if (pPoint->y > fBhi)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fA3, fBhi);
        }
        else if (pPoint->y < fB)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fA3, fB);
        }
        else
        {
            return fA3 - pPoint->x;
        }
    }
    else if (pPoint->x > fAhi)
    {
        if (pPoint->y > fBhi)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fAhi, fBhi);
        }
        else if (pPoint->y < fB)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fAhi, fB);
        }
        else
        {
            return fA3 - pPoint->x;
        }
    }
    else
    {
        if (pPoint->y > fBhi)
        {
            return pPoint->y - fBhi;
        }
        else if (pPoint->y < fB)
        {
            return fB - pPoint->y;
        }
        else
        {
            return 0.0f;
        }
    }
}

struct RegionEntry;
struct RegionNode
{
};
struct RegionData;
struct RegionBoundary
{
};
struct BoundaryNode
{
};
struct RegionEntry
{
};
struct RegionData
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int GetType();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual bool IsValid();
};
struct RegionQueryForm
{
    unsigned int FUN_0084e3a0();
};
struct RegionQuery
{
    virtual int GetType();
    virtual RegionQueryForm* GetForm();
    virtual void slot2();
    virtual RegionQueryForm* GetSecondary();
};
struct RegionAnswer
{
    bool FUN_004f6e60();
};
struct RegionDataRecord
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
    virtual RegionAnswer* FindPair(unsigned int, unsigned int);
    virtual RegionAnswer* FindQuery(RegionQuery*, bool, bool);
};
struct RegionDataManager
{
    virtual void slot0();
    virtual void slot1();
    virtual RegionDataRecord* GetRecord2(RegionData*);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual RegionDataRecord* GetRecord6(RegionData*);
};
struct RegionLoadHandler
{
};
struct RegionListHeader
{
    int header;
};
struct RegionList : RegionListHeader, RegionNode
{
};
struct RegionCell
{
    float FUN_0054fd70(void*, int, RegionQuery*);
};
// @fnv 0x0054fd70
float RegionCell::FUN_0054fd70(void* point, int kind, RegionQuery* query)
{
    RegionNode* a = ((::RegionList *)(reinterpret_cast<::TESObjectCELL *>(this)->GetRegionList(true)));
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || !a)
        return 0.0f;
    int eb = -1;
    float f = 3.402823466e+38F;
    float s;
    float h;
    RegionData* i;
    BoundaryNode* p;
    RegionDataRecord* cf;
    RegionDataRecord* b;
    RegionQuery* q;
    while (a && ((::RegionEntry *)((void *)(a))))
    {
        if (reinterpret_cast<::FUN_00440d80_shell *>((((::RegionEntry *)((void *)(a)))))->FUN_00440d80())
        {
            a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
            continue;
        }
        s = 0.0f;
        i = ((::RegionData *)(reinterpret_cast<::GList *>((((::RegionData *)(reinterpret_cast<::FUN_009611e0_shell *>((((::RegionEntry *)((void *)(a)))))->FUN_009611e0()))))->FUN_004f35b0({})));
        if (!i || !i->IsValid())
        {
            a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
            continue;
        }
        if (reinterpret_cast<::PatrolActorPackageData *>((i))->IsPatrolling())
        {
            if (((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((i))->FUN_005bb4d0())) <= eb)
            {
                a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
                continue;
            }
        }
        else if (eb >= 0)
        {
            a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
            continue;
        }
        p = ((::BoundaryNode *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>((((::RegionEntry *)((void *)(a)))))->GetMinLevel()));
        while (p && ((::RegionBoundary *)((void *)(p))))
        {
            if (s > 0.0)
                break;
            h = reinterpret_cast<::RegionMatch *>((((::RegionBoundary *)((void *)(p)))))->ComputeRegionValue((::RegionPointMatch *)(point), (float)((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RegionBoundary *)((void *)(p)))))->FUN_007af430())));
            if (h > 1.0)
                h = 1.0f;
            s = FUN_00404010(s, h);
            p = ((::BoundaryNode *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
        }
        if (s <= 0.0)
        {
            a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
            continue;
        }
        if (reinterpret_cast<::PatrolActorPackageData *>((i))->IsPatrolling())
        {
            f = 3.402823466e+38F;
            eb = ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((i))->FUN_005bb4d0()));
        }
        if (i->GetType() == 2 && query && query->GetForm() && query->GetType() == 0)
        {
            cf = ((::RegionDataManager *)(reinterpret_cast<::FUN_00740940_shell *>((((RegionLoadHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetRegionDataManager()))->GetRecord2(i);
            if (!cf->FindQuery(query, true, false)->FUN_004f6e60())
            {
                a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
                continue;
            }
        }
        else if (i->GetType() == 6 && query && query->GetForm() && query->GetType() == 1)
        {
            b = ((::RegionDataManager *)(reinterpret_cast<::FUN_00740940_shell *>((((RegionLoadHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetRegionDataManager()))->GetRecord6(i);
            q = query;
            if (!((std::uintptr_t)(reinterpret_cast<::FUN_004f5f80_cls *>((b->FindPair(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((q->GetForm()))->FUN_0084e3a0())), q->GetSecondary() ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((q->GetSecondary()))->FUN_0084e3a0())) : -1)))->FUN_004f5f80({}, {}))))
            {
                a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
                continue;
            }
        }
        while (p && ((::RegionBoundary *)((void *)(p))))
        {
            h = reinterpret_cast<::RegionMatch *>((((::RegionBoundary *)((void *)(p)))))->ComputeRegionValue((::RegionPointMatch *)(point), (float)((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RegionBoundary *)((void *)(p)))))->FUN_007af430())));
            if (h > 1.0)
                h = 1.0f;
            s = FUN_00404010(s, h);
            p = ((::BoundaryNode *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
        }
        f = FUN_0040ebd0(f, s);
        a = ((::RegionNode *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
    }
    if (f < 0.0)
        f = 0.0f;
    if (f > 1.0)
        f = 0.0f;
    return f;
}

struct TESRecordHeader
{
    unsigned int type;
    unsigned int size;
};
// Scans the current group record for a record whose masked form ID matches formID, advancing through the file and returning whether it was found.
// @fnv 0x00550e10
bool HasFormInGroup(TESFile* file, unsigned int formID)
{
    if (!file)
        return false;
    TESRecordHeader* size = file->GetRecordHeader();
    if (size->type != DAT_011872b4)
        return false;
    if (!reinterpret_cast<::FUN_00472150_shell *>((((TESFile_Helper*)file)))->FUN_00472150(true))
        return false;
    size = file->GetRecordHeader();
    if (size->type != ::fnv_00543df0::kGroupFormType)
        return false;
    unsigned int uiGroupSize = size->size - 0x18;
    if (!reinterpret_cast<::FUN_00472150_shell *>((((TESFile_Helper*)file)))->FUN_00472150(true))
        return false;
    size = file->GetRecordHeader();
    formID &= 0xffffff;
    bool header = false;
    unsigned int found = 0;
    while (!header && found < uiGroupSize)
    {
        if (size->type != ::fnv_00543df0::kGroupFormType)
        {
            std::uintptr_t current = ((std::uintptr_t)(reinterpret_cast<::MiddleHighProcess *>((((FileH*)file)))->GetFaceGenHeadNode())) & 0xffffff;
            if (current == formID)
                header = true;
            else
            {
                found += size->size;
                found += 0x18;
            }
        }
        else
            found += 0x18;
        if (!header)
        {
            if (!reinterpret_cast<::FUN_00472150_shell *>((((TESFile_Helper*)file)))->FUN_00472150(true))
                return false;
            size = file->GetRecordHeader();
        }
    }
    return header;
}

struct CellLabel : VCallC8
{
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
    virtual unsigned int v76();

    bool FUN_00425fd0();
    CellLabel* FUN_0054ddd0();
    void FUN_00551790(char* destination);
};

extern const char DAT_0102f0d8[];
extern const char DAT_0102f0a8[];
extern const char DAT_0102f088[];

// @fnv 0x00551790
void CellLabel::FUN_00551790(char* destination)
{
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        ::FUN_00406f60((::FUN_00406f90_this *)(destination), DAT_0102f0d8, v76(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0())));
    }
    else
    {
        CellLabel* worldSpace = ((::CellLabel *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()));
        if (worldSpace)
        {
            ::FUN_00406f60((::FUN_00406f90_this *)(destination), DAT_0102f0a8, v76(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0())), reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY(),
                         worldSpace->v76(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((worldSpace))->FUN_0084e3a0())));
        }
        else
        {
            ::FUN_00406f60((::FUN_00406f90_this *)(destination), DAT_0102f088, v76(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0())), reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY());
        }
    }
}


struct Ctrl_552790
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
    virtual void Update37(const NiUpdateData& data);
};

struct Node_552790;

struct AVObj_552790
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node_552790* IsNode3();
};

struct Node_552790 : public AVObj_552790
{
    unsigned int GetArrayCount();
};

// If apObject is non-null, updates its controller via Update37 and recursively processes each child returned by IsNode3/GetAt.
// @fnv 0x00552790
void __cdecl UpdateControllersRecursive(AVObj_552790* apObject)
{
    if (apObject)
    {
        Ctrl_552790* h = ((::Ctrl_552790 *)(reinterpret_cast<::MyHost *>((apObject))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<void * *>(&::g_011f3728))))));
        if (h)
        {
            NiUpdateData kData(::fnv_00563f30::DAT_011c3c08, true, false);
            h->Update37(kData);
        }
        Node_552790* p = apObject->IsNode3();
        if (p)
        {
            unsigned int e = p->GetArrayCount();
            unsigned int j;
            for (j = 0; j < e; ++j)
            {
                UpdateControllersRecursive(((::AVObj_552790 *)(reinterpret_cast<::NiNode *>((p))->GetAt(j))));
            }
        }
    }
}

struct CellCaster553
{
};

struct CellWorld553
{
    void FUN_00454380(bool bValue);
};

struct CellMopp553
{
};

struct CellRef553
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
    virtual void Update3D();
};

struct CellRefNode553
{
    CellRef553*& FUN_006815c0();
};


struct FUN_00553700_shell : public TESObjectCELL
{
    void UpdateCell();
};

bool FUN_00425fd0(FUN_00553700_shell* pkCell);

namespace fnv_005546a0 {
struct TargetObj
{
};

struct GlobalManager
{
};

// Creates a memory context, resolves the object for param_1 via g_011ca0d8 and calls its FUN_00554720 method.
// @fnv 0x005546a0
void __cdecl FUN_005546a0(void* param_1)
{
    Local::AutoMemContext ctx((Local::MEM_CONTEXT)0x10, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp", 15451);
    reinterpret_cast<::Obj554720 *>((((::fnv_005546a0::TargetObj *)(::FUN_00559450((int *)(((GlobalManager*)&(*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011ca0d8)))))))))->FUN_00554720(*(const ::NiPoint3 *)nullptr);
}
}  // namespace fnv_005546a0

struct SaveGameRecordWriter
{
    unsigned int Position();
    void Write(void*, int);
};
struct LogSetting
{
    bool* Bool();
};
struct FullNameAccess
{
    const char* GetFullName();
};
struct OwnerAccess
{
};
struct SaveVirtual
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Save(int);
};
struct FormVirtual
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
    virtual const char* Description();
};
struct RecordFlags
{
    unsigned int value;
};
struct LogRecord
{
    unsigned int id;
    unsigned char kind;
    unsigned char flags;
};
struct CellSave
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FullNameAccess fullName;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned char flags24;
    unsigned char flags25;
    void Write(const void*, int);
    SaveVirtual* Extra();
    void SaveCell(unsigned int changes);
};
// Writes the cell's change flags, extra data, full name and owner to the save stream, optionally logging the block size and patching the block header.
// @fnv 0x00554d30
void CellSave::SaveCell(unsigned int changes)
{

    {
        unsigned int cellID;
        {
            char* blockStart;
            {
                unsigned short blockSize;
                {
                    char* start;
                    {
                        unsigned int marker;
                        {
                            unsigned char cellFlags;
                            {
                                const char* name;
                                {
                                    unsigned char length;
                                    {
                                        unsigned int ownerID;
                                        {
                                            OwnerAccess* owner;
                                            {
                                                LogRecord* record;
                                                {
                                                    char* end;
                                                    {
                                                        FormVirtual* form;
                                                        {
                                                            char* finalPos;
                                                            {
                                                                char* beginPos;
                                                                if (changes & 0x40000000)
                                                                {
                                                                    cellID = reinterpret_cast<::FUN_00546af0_shell *>(this)->FUN_00546af0();
                                                                    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)(&cellID), 4);
                                                                }
                                                                reinterpret_cast<::PC7d *>(this)->FUN_00484c20(changes);
                                                                blockSize = 0;
                                                                blockStart = 0;
                                                                start = reinterpret_cast<SaveLoadGameView*>((g_TESSaveLoadGame))->pBufferCursor;
                                                                if (*reinterpret_cast<LogSetting&>(g_011de4e8).Bool())
                                                                    start = reinterpret_cast<SaveLoadGameView*>((g_TESSaveLoadGame))->pBufferCursor;
                                                                if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
                                                                {
                                                                    marker = 0x424c4f4b;
                                                                    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&marker, 4);
                                                                    blockStart = reinterpret_cast<SaveLoadGameView*>((g_TESSaveLoadGame))->pBufferCursor;
                                                                    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&blockSize, 2);
                                                                }
                                                                if (changes & 2)
                                                                {
                                                                    cellFlags = flags24 & 0x60;
                                                                    cellFlags |= flags25;
                                                                    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)(&cellFlags), 1);
                                                                }
                                                                if (changes & 0x80000000)
                                                                    ((::SaveVirtual *)(reinterpret_cast<::FUN_00555bc0_shell *>(this)->FindSeenData()))->Save(0);
                                                                if (changes & 4)
                                                                {
                                                                    name = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(fullName))->FUN_00408da0()));
                                                                    length = ::FUN_0044a670(name);
                                                                    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)(&length), 1);
                                                                    if (length)
                                                                        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)(name), length);
                                                                }
                                                                if (changes & 8)
                                                                {
                                                                    owner = ((::OwnerAccess *)(reinterpret_cast<::DoorCell *>(this)->GetOwner()));
                                                                    ownerID = 0;
                                                                    if (owner)
                                                                        ownerID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((owner))->FUN_0084e3a0()));
                                                                    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((std::intptr_t)(&ownerID), 4);
                                                                }
                                                                if (*reinterpret_cast<LogSetting&>(g_011de4e8).Bool())
                                                                {
                                                                    end = reinterpret_cast<SaveLoadGameView*>((g_TESSaveLoadGame))->pBufferCursor;
                                                                    record = ((::LogRecord *)(reinterpret_cast<::EffectSetting *>((g_TESSaveLoadGame))->GetHitSound()));
                                                                    if (record)
                                                                    {
                                                                        form = ((::FormVirtual *)(::FUN_004839c0(record->id)));
                                                                        ::FUN_0040fbe0();
                                                                    }
                                                                    else
                                                                    {
                                                                        ::FUN_0040fbe0();
                                                                    }
                                                                }
                                                                if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
                                                                {
                                                                    finalPos = reinterpret_cast<SaveLoadGameView*>((g_TESSaveLoadGame))->pBufferCursor;
                                                                    beginPos = blockStart;
                                                                    if (finalPos > beginPos + 0xffff)
                                                                        ::FUN_005b5e40(
                                                                            );
                                                                    *(unsigned short*)blockStart =
                                                                        (unsigned short)(finalPos - beginPos);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

namespace CellLoad {
struct Form
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
    virtual const char* Name();
};
struct Header
{
    unsigned int id;
    unsigned char type, payload0, payload1, payload2, payload3, version;
};
struct Stream
{
};
extern Stream* DAT_011de45c;
struct Data
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Load(unsigned int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};
struct Interior : Data
{
    int unk24, unk28;
    Interior(int, int);
};
struct Exterior : Data
{
    Exterior();
};
struct Ref
{
};
struct String
{
    int unk00, unk04, unk08;
};
struct Cell
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    String name;
    unsigned char flags, otherFlags;
    bool FUN_00425fd0();
    void LoadChanged(unsigned int, int);
};
// Applies changed-field flags to a cell: reads flags, linked ref, extra data, name and a value from the stream, then reports any size mismatch.
// @fnv 0x00554fd0
void Cell::LoadChanged(unsigned int auiChangedFlags, int file)
{
    if (reinterpret_cast<::FUN_008df040_shell *>((DAT_011de45c))->FUN_008df040() >= 90 && (auiChangedFlags & 0x40000000))
    {
        std::uintptr_t id;
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&id, 4);
        reinterpret_cast<::FUN_00421850_shell *>((((::CellLoad::Ref *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00421850((::BSExtraData *)(id));
    }
    {
        reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>(this)->FUN_00484c50(auiChangedFlags, file);
        unsigned short usChunkSize = 0;
        unsigned int start = 0;
        if (reinterpret_cast<::FUN_00862110_cls *>((DAT_011de45c))->FUN_00862110())
        {
            unsigned int uiChunkTag;
            reinterpret_cast<::FUN_008579e0_shell *>((DAT_011de45c))->FUN_008579e0(&uiChunkTag, 4);
            if (uiChunkTag != 0x424c4f4b)
            {
                Header* header = ((::CellLoad::Header *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(DAT_011de45c))));
                if (header)
                {
                    Form* form = ((::CellLoad::Form *)(::FUN_004839c0(header->id)));
                    ::FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015718)), ::str_0102ed68, 0x3d9d, header->id, form->Name(), header->version,
                                 *(unsigned int*)&header->payload0);
                }
                else
                    ::FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_010156a8)), ::str_0102ed68, 0x3d9d, reinterpret_cast<::FUN_008df040_shell *>((DAT_011de45c))->FUN_008df040());
            }
            start = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((DAT_011de45c))->FUN_00825c00();
            reinterpret_cast<::FUN_008579e0_shell *>((DAT_011de45c))->FUN_008579e0(&usChunkSize, 2);
        }
        if (auiChangedFlags & 2)
        {
            unsigned char value;
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&value, 1);
            flags = (flags & 0x9f) | (value & 0x60);
            otherFlags = value & 0x9f;
        }
        if (auiChangedFlags & 0x80000000)
        {
            Data* data = ((::CellLoad::Data *)(reinterpret_cast<::FUN_00555bc0_shell *>(this)->FindSeenData()));
            if (!data)
            {
                if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
                    data = new Interior(0, 0);
                else
                    data = new Exterior;
                reinterpret_cast<::extra421::E4List *>((((::CellLoad::Ref *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00421940((::extra421::E4Object *)(data));
            }
            data->Load(0xffff);
        }
        if (reinterpret_cast<::FUN_008df040_shell *>((DAT_011de45c))->FUN_008df040() < 90 && (auiChangedFlags & 0x40000000))
        {
            unsigned int uiLinkedRefId2;
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&uiLinkedRefId2, 4);
            reinterpret_cast<::FUN_00421850_shell *>((((::CellLoad::Ref *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00421850((::BSExtraData *)(std::uintptr_t)(uiLinkedRefId2));
        }
        if (auiChangedFlags & 4)
        {
            char text[260];
            memset(text, 0, 260);
            unsigned char size;
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&size, 1);
            if (size)
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(text, size);
            reinterpret_cast<::TESFullName *>(&(name))->SetFullName(text);
        }
        if (auiChangedFlags & 8)
        {
            unsigned int uiValue;
            reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40((unsigned int *)(void *)(&uiValue), 4);
            reinterpret_cast<::FUN_00546bf0_class *>(this)->FUN_00546bf0(uiValue);
        }
        if (reinterpret_cast<::FUN_00862110_cls *>((DAT_011de45c))->FUN_00862110())
        {
            unsigned int end = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((DAT_011de45c))->FUN_00825c00();
            Header* pEndHeader = ((::CellLoad::Header *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(DAT_011de45c))));
            if (pEndHeader)
            {
                Form* pEndForm = ((::CellLoad::Form *)(::FUN_004839c0(pEndHeader->id)));
                if (end > start + usChunkSize)
                    ::FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015588)), end - (start + usChunkSize), ::str_0102ed68, 0x3dd5, pEndHeader->id,
                                 pEndForm->Name(), pEndHeader->version, *(unsigned int*)&pEndHeader->payload0);
                else if (end < start + usChunkSize)
                    ::FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015500)), start + usChunkSize - end, ::str_0102ed68, 0x3dd5, pEndHeader->id,
                                 pEndForm->Name(), pEndHeader->version, *(unsigned int*)&pEndHeader->payload0);
            }
            else
            {
                if (end > start + usChunkSize)
                    ::FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_010154a0)), end - (start + usChunkSize), ::str_0102ed68, 0x3dd5,
                                 reinterpret_cast<::FUN_008df040_shell *>((DAT_011de45c))->FUN_008df040());
                else if (end < start + usChunkSize)
                    ::FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015440)), start + usChunkSize - end, ::str_0102ed68, 0x3dd5,
                                 reinterpret_cast<::FUN_008df040_shell *>((DAT_011de45c))->FUN_008df040());
            }
        }
    }
}
}

struct FUN_004610d0_Obj
{
};

struct FUN_00421940_Obj
{
};

struct FUN_00555be0_Virtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C(unsigned int value);
};

// @fnv 0x00555be0
void FUN_00555be0_stub::FUN_00555be0()
{
    reinterpret_cast<::extra421::E4List *>((reinterpret_cast<FUN_00421940_Obj*>(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<FUN_004610d0_Obj*>(this)))->GetExtraDataList())))->FUN_00421940((::extra421::E4Object *)(0));

    ucCellFlags25 &= 0xFFFFFFFEu;

    reinterpret_cast<FUN_00555be0_Virtual*>(this)->vf4C(0x80000000u);
}

struct FUN_00557ae0_Av
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual BSFadeNode* unk10();
};

struct FUN_0043fcd0_Obj
{
    FUN_00557ae0_Av* FUN_0043fcd0();
};

struct FUN_006815c0_Obj
{
    void** FUN_006815c0();
};

struct FUN_00726070_Obj
{
};

struct FUN_007058c0_Obj
{
    int FUN_007058c0() const;
};

struct FUN_0099e040_Obj
{
};

extern void* DAT_011dea3c;
void FUN_00476ab0(BSFadeNode* p);

struct FUN_00557ae0_shell : public TESObjectCELL
{
    void FUN_00557ae0();
};
// @fnv 0x00557be0
void FUN_00557be0_shell::FUN_00557be0()
{
    for (unsigned int i = 0; i < ((FUN_00453980_shell*)g_TES)->GetGlobalInt(); i++)
    {
        FUN_00557ae0_obj* obj = ((FUN_00459470_Class*)g_TES)->FUN_00459470(i);
        if (obj)
            reinterpret_cast<::FUN_00557ae0_shell *>((obj))->FUN_00557ae0();
    }
}

// @fnv 0x00557ae0
void FUN_00557ae0_shell::FUN_00557ae0()
{
    CellRefLockEnter();
    BSSimpleList<BGSPerkEntry*>* node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (node)
    {
        void* item = *((void **)((void *)(((FUN_006815c0_Obj*)node))));
        node = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((FUN_00726070_Obj*)node)))->FUN_00726070()));
        if (item && item != DAT_011dea3c)
        {
            FUN_00557ae0_Av* obj = ((::FUN_00557ae0_Av *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((FUN_0043fcd0_Obj*)item)))->FUN_0043fcd0()));
            if (obj)
            {
                BSFadeNode* pFadeNode = obj->unk10();
                if (pFadeNode)
                {
                    if (((FUN_007058c0_Obj*)pFadeNode)->FUN_007058c0() == 6 ||
                        reinterpret_cast<::FUN_0099e040_shell *>((((FUN_0099e040_Obj*)pFadeNode)))->FUN_0099e040() > 599.9f)
                    {
                        FUN_00476ab0(pFadeNode);
                        ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(pFadeNode), 1.0f);
                    }
                }
            }
        }
    }
    fUnkC8 = 1.2f;
    aucUnkCC[4] = 1;
    aucUnkCC[2] = 0;
    aucUnkCC[3] = 0;
    aucUnkCC[6] = 1;
    ::FUN_00541ae0((char *)this);
}

namespace fnv_00557dd0 {
namespace render_test {
struct FUN_00557da0
{
    unsigned a, b, c, d, e, f;
    void(__cdecl* callback)(int);
    int data;
    FUN_00557da0();
};
}
struct RenderVec
{
    float x, y, z;
    void FUN_006815c0();
};
struct RenderMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void FUN_006815c0();
};
struct RenderNode
{
    void Update(const NiUpdateData&);
};
struct RenderRoot
{
};
struct RenderMesh
{
    RenderVec FUN_00558220(unsigned short);
};
struct NavMeshPtr
{
    RenderMesh* value;
    ~NavMeshPtr();
    RenderMesh* FUN_00458b50();
};
struct RenderMeshes
{
    NavMeshPtr FUN_00464f60(unsigned);
};
struct RenderCell : TESObjectCELL
{
};
struct RenderBound
{
    RenderVec& FUN_006815c0();
};
struct RenderObjectNode : VClass0c
{
    RenderVec& FUN_0045bb80();
};
struct RenderReference : VClass1d0
{
    RenderObjectNode* vfn_1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual RenderVec& v1f4();
};
struct RenderRefList
{
    unsigned FUN_005ae380();
    bool FUN_008256d0();
    RenderReference** FUN_006815c0();
};
extern RenderReference* pPlayer;
// Tests navmesh triangles or reference positions in a cell against the renderer, restoring the camera transform and warning on failure.
// @fnv 0x00557dd0
void FUN_00557dd0(RenderCell* cell, render_test::FUN_00557da0* options, bool all)
{
    if (!cell || !reinterpret_cast<::FUN_00545cb0_shell *>((cell))->FUN_00545cb0())
        return;
    bool testData = true;
    render_test::FUN_00557da0 kUpdateData;
    if (!options)
        options = &kUpdateData;
    RenderVec bResult;
    RenderMatrix kRotationBasis;
    RenderRoot* kPosition = ((::fnv_00557dd0::RenderRoot *)(::FUN_0045c670()));
    bResult = (*(::fnv_00557dd0::RenderVec *)&(reinterpret_cast<::NiAVObject *>((((::fnv_00557dd0::RenderNode *)(::FUN_00558310((::NiNode_00558310 *)(kPosition))))))->FUN_0043c490()));
    kRotationBasis = (*(::fnv_00557dd0::RenderMatrix *)(::FUN_006a9540((char *)(((::fnv_00557dd0::RenderNode *)(::FUN_00558310((::NiNode_00558310 *)(kPosition))))))));
    if (all)
    {
        RenderMeshes* meshes = ((::fnv_00557dd0::RenderMeshes *)(std::uintptr_t)(::FUN_0070ec90((char *)(cell))));
        if (meshes && reinterpret_cast<::FUN_00620b80_shell *>((meshes))->GetReferenceFlags())
        {
            unsigned count = 0;
            for (unsigned i = 0; i < reinterpret_cast<::FUN_00620b80_shell *>((meshes))->GetReferenceFlags(); i++)
            {
                NavMeshPtr mesh = meshes->FUN_00464f60(i);
                count += ::FUN_00558200((char *)(((::fnv_00557dd0::RenderMesh *)(::FUN_00559450((int *)&(mesh))))));
            }
            ::FUN_005b5e40();
            for (unsigned j = 0; j < reinterpret_cast<::FUN_00620b80_shell *>((meshes))->GetReferenceFlags(); j++)
            {
                NavMeshPtr mesh2 = meshes->FUN_00464f60(j);
                if (mesh2.FUN_00458b50())
                {
                    unsigned triangles = ::FUN_00558200((char *)(((::fnv_00557dd0::RenderMesh *)(::FUN_00559450((int *)&(mesh2))))));
                    for (unsigned k = 0; k < triangles; k++)
                    {
                        RenderVec pos = ((::fnv_00557dd0::RenderMesh *)(::FUN_00559450((int *)&(mesh2))))->FUN_00558220((unsigned short)k);
                        pos.z += 118.0;
                        if (!FUN_00558330((std::intptr_t)cell, (std::intptr_t)&pos, (std::intptr_t)options))
                            testData = false;
                    }
                }
            }
        }
        else
        {
            ::FUN_005b5e40();
            RenderRefList* refs = (RenderRefList*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>((cell))->FUN_009604f0()));
            while (refs && !refs->FUN_008256d0())
            {
                RenderReference* pos = *((::fnv_00557dd0::RenderReference **)((void *)(refs)));
                refs = ((::fnv_00557dd0::RenderRefList *)(reinterpret_cast<::Callees *>((refs))->FUN_00726070()));
                RenderVec ref = pos->v1f4();
                if (pos->vfn_1d0())
                    ref = (*(::fnv_00557dd0::RenderVec *)((void *)(((::fnv_00557dd0::RenderBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((pos->vfn_1d0()))->FUN_0043d450())))));
                if (!FUN_00558330((std::intptr_t)cell, (std::intptr_t)&ref, (std::intptr_t)options))
                    testData = false;
            }
        }
    }
    else
    {
        if (!FUN_00558330((std::intptr_t)cell, (std::intptr_t)&pPlayer->vfn_1d0()->FUN_0045bb80(), (std::intptr_t)options))
            testData = false;
    }
    reinterpret_cast<::FUN_00440460_S *>((((::fnv_00557dd0::RenderNode *)(::FUN_00558310((::NiNode_00558310 *)(kPosition))))))->FUN_00440460((const ::V3 *)&(bResult));
    reinterpret_cast<::FUN_0043fa80_s *>((((::fnv_00557dd0::RenderNode *)(::FUN_00558310((::NiNode_00558310 *)(kPosition))))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(kRotationBasis));
    NiUpdateData pRoot(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_00557dd0::RenderNode *)(::FUN_00558310((::NiNode_00558310 *)(kPosition))))))->FUN_00a59c60((std::intptr_t)&(pRoot));
    if (!testData)
        ::FUN_005b5e40();
}
}  // namespace fnv_00557dd0

namespace fnv_00558430 {
struct ThreeByThreeMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

struct NiAVObject_Shell : public NiAVObject
{
    void Update(NiUpdateData& data);
};


class OSGlobals
{
};
extern OSGlobals* g_osGlobals;

struct FUN_00558690
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int unk18;
    NiPoint3 pt;
    ThreeByThreeMatrix mat;

    FUN_00558690();
};

struct FUN_00558600_obj
{
};

struct NiRenderer_Shell : public NiRenderer
{
};

struct ShadowSceneNode_Shell : public ShadowSceneNode
{
};
ShadowSceneNode* __cdecl FUN_00450b80(int);

// Updates a node's transform, measures timing and renderer stats, compares them against limit, and invokes limit's callback when any stat exceeds it.
// @fnv 0x00558430
bool UpdateAndCheckBudget(int a1, const NiPoint3* apPosition, const ThreeByThreeMatrix* apRotation, SpawnedVecC* limit)
{
    NiNode_00558310* node2 = ((::NiNode_00558310 *)(::FUN_0045c670()));
    reinterpret_cast<::FUN_00440460_S *>((((NiAVObject_Shell*)FUN_00558310(node2))))->FUN_00440460((const ::V3 *)&(*apPosition));
    reinterpret_cast<::FUN_0043fa80_s *>((((NiAVObject_Shell*)FUN_00558310(node2))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(apRotation)));
    NiUpdateData updateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiAVObject_Shell*)FUN_00558310(node2))))->FUN_00a59c60((std::intptr_t)&(updateData));
    unsigned int startTick3 = ((unsigned int)(::FUN_00457fe0()));
    reinterpret_cast<::fnv_0086ff70::Main86 *>((g_osGlobals))->FUN_0086ff70();
    unsigned int dummy4 = 0;
    FUN_00558690 s;
    s.unk10 = ((unsigned int)(::FUN_00457fe0())) - startTick3;
    reinterpret_cast<::FUN_00558600_Class *>((((::fnv_00558430::FUN_00558600_obj *)(reinterpret_cast<::TESRegionDataMap *>((((NiRenderer_Shell*)FUN_0043c4b0())))->GetRegionMapName()))))->FUN_00558600((int *)(unsigned int *)(&s.unk00), (int *)(unsigned int *)(&dummy4), (int *)(unsigned int *)(&s.unk04), (int *)(unsigned int *)(&dummy4), (int *)(unsigned int *)(&dummy4), (int *)(unsigned int *)(&dummy4), (int *)(unsigned int *)(&dummy4), (int *)(unsigned int *)(&dummy4), (int *)(unsigned int *)(&dummy4), (int *)(unsigned int *)(&dummy4),
                       (int *)(unsigned int *)(&dummy4));
    s.unk0c = ((unsigned short)(::FUN_00b5ac60((::FUN_00b5ac60_self *)(((ShadowSceneNode_Shell*)FUN_00450b80(0))), {})));
    bool bCondition = false;
    if (s.unk00 > limit->unk00)
        bCondition = true;
    else if (s.unk04 > limit->unk04)
        bCondition = true;
    else if (s.unk08 > limit->unk08)
        bCondition = true;
    else if (s.unk0c > limit->unk0c)
        bCondition = true;
    else if (s.unk14 > limit->unk14)
        bCondition = true;
    else if (s.unk10 > limit->unk10)
        bCondition = true;

    if (bCondition && limit->unk18)
    {
        s.unk18 = a1;
        s.pt = *apPosition;
        s.mat = *apRotation;
        ((void (*)(FUN_00558690*, unsigned int))limit->unk18)(&s, limit->unk1c);
    }
    return !bCondition;
}
}  // namespace fnv_00558430

int __cdecl CreateDirectoryChecked(const char*);
struct StatsCell
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual const char* EditorID();
    bool FUN_00425fd0();
    StatsCell* FUN_0054ddd0();
    unsigned int FUN_0084e3a0();
};
extern StatsCell* DAT_011ca218;
struct StatsMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
struct RenderStats
{
    int geometryCount, triangleCount, newPassCount, activeLights, count;
    unsigned int flags;
    StatsCell* cell;
    float x, y, z;
    StatsMatrix rotation;
};
struct BSFile
{
    virtual ~BSFile();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetEndian(int, unsigned int);
    virtual void v18();
    virtual void v1c();
    virtual void Seek(int, int);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void Write(const char*, int);
    unsigned int position, bufferSize, bufferPosition, bytesRead;
    void* buffer;
    void* handle;
    unsigned int mode, flags, error;
    char filename[260];
    unsigned int unk12c, unk130, unk134, unk138, unk13c, unk140;
    unsigned int unk144, unk148, unk14c, unk150, unk154;
    BSFile(const char*, int, unsigned int, bool);
};
// Writes a cell's render statistics (camera position/rotation, geometry, triangle, pass and light counts) to a per-cell RTF text file.
// @fnv 0x005586e0
void __cdecl WriteRenderStatsFile(RenderStats* stats)
{
    if (!stats)
    {
        DAT_011ca218 = 0;
        return;
    }
    CreateDirectoryChecked("RTF");
    const char* directory = ".\\RTF\\";
    float fRotX;
    {
        char filename[260];
        char line[260];
        {
            float rz;
            {
                float fRotY;
                {
                    BSFile* file;
                    if (reinterpret_cast<::TESObjectCELL *>((stats->cell))->IsCellInterior())
                    {
                        FUN_00406d00(filename, 260, "%sINT-%s.txt", directory, stats->cell->EditorID());
                    }
                    else
                    {
                        StatsCell* world = ((::StatsCell *)(reinterpret_cast<::TESObjectCELL *>((stats->cell))->GetParentWorldSpace()));
                        if (*((const char *)(reinterpret_cast<::FUN_00401280_Class *>((stats->cell))->FUN_00401280())))
                        {
                            FUN_00406d00(filename, 260, "%sEXT-%s-(%i, %i)-%s.txt", directory, world->EditorID(),
                                         reinterpret_cast<::TESObjectCELL *>((stats->cell))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((stats->cell))->GetCellGridY(),
                                         stats->cell->EditorID());
                        }
                        else
                        {
                            FUN_00406d00(filename, 260, "%sEXT-%s-(%i, %i).txt", directory, world->EditorID(),
                                         reinterpret_cast<::TESObjectCELL *>((stats->cell))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((stats->cell))->GetCellGridY());
                        }
                    }
                    file = 0;
                    if (DAT_011ca218 != stats->cell)
                    {
                        FUN_00aff0b0(filename);
                        file = new BSFile(filename, 1, 0x4000, false);
                        file->Seek(0, 0);
                        file->SetEndian(0, (*reinterpret_cast<unsigned int *>(&::DAT_010a2480)));
                        FUN_00406d00(
                            line, 260,
                            "cell ID\tcamera pos\tcamera rot\tgeom count\ttri count\tnew pass count\tactive lights\r\n");
                        file->Write(line, ((int)(::FUN_0044a670(line))));
                        DAT_011ca218 = stats->cell;
                    }
                    else
                    {
                        file = new BSFile(filename, 2, 0x4000, false);
                        file->Seek(0, 0);
                    }
                    reinterpret_cast<::S_00a592c0_Matrix3 *>(&(stats->rotation))->DecomposeToEulerAngles((*(float *)(&fRotX)), (*(float *)(&fRotY)), (*(float *)(&rz)));
                    FUN_00406d00(line, 260, "(%08X)\t(%.2f, %.2f, %.2f)\t(%.2f, %.2f, %.2f)\t%i\t%i\t%i\t%i\t%i\r\n",
                                 ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((stats->cell))->FUN_0084e3a0())), stats->x, stats->y, stats->z, fRotX * 57.2957763671875,
                                 fRotY * 57.2957763671875, rz * 57.2957763671875, stats->count, stats->geometryCount,
                                 stats->triangleCount, stats->newPassCount, stats->activeLights);
                    file->Write(line, ((int)(::FUN_0044a670(line))));
                    delete file;
                }
            }
        }
    }
}

struct ObstacleMapValue
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char unk08;
    ObstacleMapValue(const ObstacleMapValue& other);
    ~ObstacleMapValue();
    ObstacleMapValue& operator=(const ObstacleMapValue& other);
};

struct ObstacleMapItem
{
    ObstacleMapItem* m_pkNext;
    unsigned int m_key;
    ObstacleMapValue m_val;
};

class ObstacleMap
{
  public:
    virtual ~ObstacleMap();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2);
    virtual void SetValue(ObstacleMapItem* item, unsigned int key, ObstacleMapValue val);
    virtual void ClearValue(ObstacleMapItem* item);
    virtual ObstacleMapItem* NewItem();

    unsigned int m_uiHashSize;
    ObstacleMapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    void SetOrInsertValue(std::uintptr_t key, ObstacleMapValue val);
};

// Looks up the key in the hash bucket, updates the matching item's value, or inserts a new item at the bucket head and increments the count.
// @fnv 0x00559260
void ObstacleMap::SetOrInsertValue(std::uintptr_t key, ObstacleMapValue val)
{
    unsigned int index = KeyToHashIndex(key);
    ObstacleMapItem* item = m_ppkHashTable[index];
    int count = 0;
    while (item)
    {
        count++;
        if (IsKeysEqual(key, item->m_key))
        {
            reinterpret_cast<::FUN_00559900_Struct *>((void *)&(const ::ObstacleMapValue &)(item->m_val))->AssignFrom((const ::FUN_00559900_Struct &)(val));
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    SetValue(item, key, val);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_uiCount++;
}

namespace fnv_004375c0 {
struct Entry;
template <class T> struct SL
{
    T item;
    SL* next;
    T& FUN_006815c0();
    void FUN_0063f7b0();
    ~SL();
};
void FUN_00401030(void*);
struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
    int u4, u8;
};
struct FUN_004375c0 : FUN_0040ecb0
{
    SL<Entry*>* m_kNode;
    virtual ~FUN_004375c0();
};
// @fnv 0x004375c0
FUN_004375c0::~FUN_004375c0()
{
    SL<Entry*>* list = m_kNode;
    while (list && ((::fnv_004375c0::Entry *)((void *)(list))))
    {
        Entry* e = ((::fnv_004375c0::Entry *)((void *)(list)));
        list->FUN_0063f7b0();
        delete e;
    }
    delete m_kNode;
}
}  // namespace fnv_004375c0

namespace fnv_0054cfd0 {
struct NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3(float x, float y, float z);
};


class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};


class TESObjectCELL_Ext
{
  public:
    void FUN_0054cfd0(NiPoint3* a, NiPoint3* b);
};

// @fnv 0x0054cfd0
void TESObjectCELL_Ext::FUN_0054cfd0(NiPoint3* pCenter, NiPoint3* b)
{
    *pCenter = NiPoint3((float)((reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() << 12) + 0x800), (float)((reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() << 12) + 0x800), 0.0f);
    *b = (*reinterpret_cast<::fnv_0054cfd0::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    if (*(*reinterpret_cast<::fnv_0054cfd0::GlobalObject_0045cf30 *>(&::g_011ca0a8)).Bool())
    {
        if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
            return;
    }
    reinterpret_cast<::fnv_00550340::FUN_00550340_t *>(this)->FUN_00550340();
    reinterpret_cast<::MarkerCell *>(this)->FUN_0054d090((::NiPoint3 *)(pCenter), (::NiPoint3 *)(b));
}
}  // namespace fnv_0054cfd0

class FormStub;
  // LookupFormByID

class SkyObjectBase
{
  public:
};

class LinkedFormOwner : public SkyObjectBase
{
  public:
    void UpdateLinkedForm(unsigned int uiFlags, int iArg);
};
// @fnv 0x005555d0
void LinkedFormOwner::UpdateLinkedForm(unsigned int uiFlags, int iArg)
{
    reinterpret_cast<::FUN_008d0600_s *>(this)->FUN_008d0600(uiFlags, iArg);
    if (uiFlags & 8)
    {
        FormStub* pkForm = ((::FormStub *)(reinterpret_cast<::DoorCell *>(this)->GetOwner()));
        if (pkForm)
        {
            unsigned int auiFormId = (unsigned int)(std::uintptr_t)pkForm;
            pkForm = ((::FormStub *)(::FUN_004839c0(auiFormId)));
            reinterpret_cast<::FUN_00546bf0_class *>(this)->FUN_00546bf0((std::intptr_t)(pkForm));
        }
    }
}

namespace fnv_00548880 {
struct FNV_Ref;
struct FNV_Form;
struct FNV_Node;
struct FNV_Sub;
struct FNV_Render;
struct FNV_Primitive;
struct FNV_Scene;
struct FNV_Effects;
struct FNV_SceneObject;
struct FNV_Flags;

struct NiPoint3
{
    float x, y, z;
};
struct NiPoint2
{
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float, float);
};
struct ThreeByThreeMatrix
{
    float m[9];
};


class NiMemObject
{
  public:
};

extern void* DAT_011dea10;
extern FNV_Ref* DAT_011dea3c;

extern const char DAT_0102ede0[];
extern const char DAT_0102edc4[];

struct FNV_Indicator
{
    unsigned char* FUN_00408d60();
};

struct FNV_GlobalCheck
{
};

struct FNV_SaveLoad
{
};

struct FNV_TESResult
{
    void FUN_004e46b0();
};

struct FNV_TES
{
};

struct FNV_WorldEntity
{
};

struct FNV_World
{
};

struct FNV_Node
{
    FNV_Node* FUN_00586170(FNV_Ref*, int);
    FNV_Node* FUN_00586170(int);
    void FUN_006fcfa0();
    void FUN_00929260();
    FNV_Flags* FUN_00a5bdd0(void*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual FNV_Render* v10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void vdc(void*);
};

struct FNV_Form
{
    int FUN_00401170();
    bool FUN_00549580();
    bool FUN_00549630();
};

struct FNV_Sub
{
};

struct FNV_Render
{
    void FUN_00476ab0();
    FNV_Node* FUN_00545960(void*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual FNV_Render* v10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void vb8(void*);
};

struct FNV_Primitive
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void* v14(NiPoint3*);
    virtual void v_18();
    virtual void* v1c();
};

struct ClassEC : public NiMemObject
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
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    ClassEC();
};

struct BSMultiBound : public NiMemObject
{
    int unk04;
    int unk08;
    int unk0c;
    BSMultiBound();
    void FUN_004addc0(void*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v90(void*);
};

struct ClassC4 : public NiMemObject
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
    ClassC4(FNV_SceneObject*);
};

struct ClassFC : public NiMemObject
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
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    ClassFC();
};

struct CellOffsets
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
    short unkA8;
    short unkAA;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    float unkC8;
    short unkCC;
    char unkCE;
    char unkCF;
    char unkD0;
};

struct FNV_Scene
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void vdc(void*, int);
};

struct FNV_Effects
{
};

struct FNV_Flags
{
};

struct FNV_SceneObject
{
};

struct FNV_LinkedDest
{
};

struct FNV_Ref
{
    void* FUN_0043fcd0();
    void* FUN_00575d70();
    FNV_Sub* FUN_005d43c0();
    NiPoint3* FUN_00430830();
    int FUN_005699b0();
    bool FUN_004077c0();
    bool FUN_00444ed0();
    bool FUN_005694c0();
    bool FUN_00564e60();
    bool FUN_00564f00();
    ThreeByThreeMatrix FUN_0056fa00();
    FNV_Render* FUN_008d6f30();
    unsigned int FUN_0084e3a0();
    void* FUN_00950bb0(int, int);
    FNV_Render* FUN_00950bb0(int);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual bool v100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual void v_130();
    virtual void v_134();
    virtual void v_138();
    virtual void v_13c();
    virtual void v_140();
    virtual void v_144();
    virtual void v_148();
    virtual void v_14c();
    virtual void v_150();
    virtual void v_154();
    virtual void v_158();
    virtual void v_15c();
    virtual void v_160();
    virtual void v_164();
    virtual void v_168();
    virtual void v_16c();
    virtual void v_170();
    virtual void v_174();
    virtual void v_178();
    virtual void v_17c();
    virtual void v_180();
    virtual void v_184();
    virtual void v_188();
    virtual void v_18c();
    virtual void v_190();
    virtual void v_194();
    virtual void v_198();
    virtual void v_19c();
    virtual void v_1a0();
    virtual void v_1a4();
    virtual void v_1a8();
    virtual void v_1ac();
    virtual void* v1b0(int, int);
    virtual void v_1b4();
    virtual void v_1b8();
    virtual void v_1bc();
    virtual void v_1c0();
    virtual void v_1c4();
    virtual void v_1c8();
    virtual void v_1cc();
    virtual FNV_Node* v1d0();
    virtual void v_1d4();
    virtual void v_1d8();
    virtual void v_1dc();
    virtual void v_1e0();
    virtual void v_1e4();
    virtual void v_1e8();
    virtual void v_1ec();
    virtual void v_1f0();
    virtual void* v1f4();
    virtual void v_1f8();
    virtual void v_1fc();
    virtual void v_200();
    virtual void v_204();
    virtual void v_208();
    virtual void v_20c();
    virtual void v_210();
    virtual void v_214();
    virtual void v_218();
    virtual void v_21c();
    virtual void v_220();
    virtual bool v224();
};

struct FNV_Cell : TESObjectCELL
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual void v_100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual const char* cv130();
    void FUN_00548880(FNV_Ref*, int);
    bool FUN_00425fd0();
    unsigned int FUN_0084e3a0();
    void FUN_005453b0(FNV_Ref*);
};

extern "C"
{
    void __cdecl FUN_004e46b0();
    void __cdecl FUN_00476ab0(void*);
}

// Places a reference into the cell by selecting a node based on the reference's form type and attaching it to the scene graph.
// @fnv 0x00548880
void FNV_Cell::FUN_00548880(FNV_Ref* reference, int unused)
{
    FNV_Node* Dir2;
    bool Diff5 = false;
    if (reference == 0 || ((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((reference))->FUN_0043fcd0())) == 0)
    {
        return;
    }

    if (reinterpret_cast<::FUN_00549580_shell *>((((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))))->FUN_00549580())
    {
        FNV_Node* Diff6 = (FNV_Node*)((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((reference))->FUN_00575d70()));
        if (Diff6)
        {
            reinterpret_cast<::Dfcfa0Manager *>((((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESWorldSpace *>((Diff6))->GetWorldTerrainManager()))))->FUN_006fcfa0({}, {});
            reinterpret_cast<::MiddleHighProcess *>((((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESWorldSpace *>((Diff6))->GetWorldTerrainManager()))))->FUN_00929260({});
        }
    }

    if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) != 0 && ((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() == 0x23)
    {
        reinterpret_cast<::FUN_0045ce40_class *>((((FNV_TES*)DAT_011dea10)))->FUN_0045ce40();
        if (((::fnv_00548880::FNV_WorldEntity *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((((::fnv_00548880::FNV_World *)(reinterpret_cast<::FUN_004543c0_cls *>(this)->FUN_004543c0()))))->GetCurrentMoveModeType())))
        {
            reinterpret_cast<::bhkEntityListener_shell *>((((::fnv_00548880::FNV_WorldEntity *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((((::fnv_00548880::FNV_World *)(reinterpret_cast<::FUN_004543c0_cls *>(this)->FUN_004543c0()))))->GetCurrentMoveModeType()))))->FUN_00937090(1);
        }
        if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && !reinterpret_cast<::fnv_004518e0::TESObjectCELL *>(this)->FUN_004518e0())
        {
            ::FUN_005b5e40();
            if (!*(*reinterpret_cast<::fnv_00548880::FNV_Indicator *>(&::g_011c7adc)).FUN_00408d60())
            {
                return;
            }
        }
    }

    Dir2 = 0;
    if (reference->v100())
    {
        Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(0)));
    }
    else if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<::fnv_00548880::FNV_Form * *>(&::DAT_011ca230)))
    {
        Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(1)));
    }
    else if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<::fnv_00548880::FNV_Form * *>(&::DAT_011ca238)))
    {
        if (reinterpret_cast<::FUN_00420810_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00420810())
        {
            FNV_Effects* EndLocTmp;
            FNV_Render* EndLoc2;
            void* EntryLoc9;
            std::intptr_t Diff;
            if (!((::fnv_00548880::FNV_Render *)(reinterpret_cast<::ExtraList420 *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00420ed0())))
            {
                Diff = ((std::intptr_t)(reinterpret_cast<::Ref5699 *>((reference))->FUN_005699b0()));
                if (!Diff)
                {
                    BSMultiBound* Dir9;
                    ClassEC* Dir5;
                    NiPoint3 DiffB = *((::fnv_00548880::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((reference))->GetData()));
                    EntryLoc9 = ((::fnv_00548880::FNV_Primitive *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041fbe0()))->v14(&DiffB);
                    Dir5 = new ClassEC();
                    Dir9 = new BSMultiBound();
                    reinterpret_cast<::BSFaceGenNiNode *>((Dir5))->SetAnimationData((::BSFaceGenAnimationData *)(Dir9));
                    Dir9->FUN_004addc0(EntryLoc9);
                    Dir9->v90(reference->v1f4());
                    reinterpret_cast<::fnv_00420f00::FUN_00420f00_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00420f00(Dir5);
                }
            }
            EndLoc2 = ((::fnv_00548880::FNV_Render *)(reinterpret_cast<::ExtraList420 *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00420ed0()));
            ((::fnv_00548880::FNV_Render *)(::fnv_0043b230::FUN_0043b230((const char *)(((::fnv_00548880::FNV_Render *)(reinterpret_cast<::BSFaceGenNiNode *>((EndLoc2))->GetAnimationData()))))))->vb8(reference->v1f4());
            EndLocTmp = ((::fnv_00548880::FNV_Effects *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
            reinterpret_cast<::fnv_00c5aef0::FUN_00c5aef0_cls *>((EndLocTmp))->FUN_00c5aef0((::fnv_00c5aef0::RefQ *)(EndLoc2));
        }
        Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(1)));
    }
    else if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<::fnv_00548880::FNV_Form * *>(&::DAT_011ca23c)) && !reinterpret_cast<::FUN_004077c0_shell *>((reference))->FUN_004077c0())
    {
        if (!((int)(reinterpret_cast<::Holder00420dd0 *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00420dd0())))
        {
            FNV_Primitive* LeftX = ((::fnv_00548880::FNV_Primitive *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041fbe0()));
            FNV_SceneObject* EntryLoc7 = (FNV_SceneObject*)LeftX->v1c();
            if (EntryLoc7)
            {
                FNV_Ref** EntryLocVal;
                ClassC4* DiffA;
                int Diff_2;
                FNV_Effects* DiffX;
                reinterpret_cast<::fnv_004169f0::BSOcclusionPlane_Fake *>((EntryLoc7))->FUN_004169f0((*(const ::fnv_004169f0::NiPoint3 *)(reference->v1f4())));
                reinterpret_cast<::S00416a70 *>((EntryLoc7))->FUN_00416a70((::M00416a70 *)&(const ::fnv_00548880::ThreeByThreeMatrix &)(reference->FUN_0056fa00()));
                reinterpret_cast<::FUN_00420e00_cls *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00420e00(EntryLoc7);
                DiffA = new ClassC4(EntryLoc7);
                ::AssignFixedString((char *)(DiffA), (std::intptr_t)&(const ::NiFixedString &)(NiFixedString(DAT_0102edc4)), {});
                reinterpret_cast<::FUN_00549610_Class *>((EntryLoc7))->FUN_00549610(DiffA);
                DiffX = ((::fnv_00548880::FNV_Effects *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
                ((::fnv_00548880::FNV_Scene *)(::fnv_00546930::FUN_00546930((::fnv_00546930::FUN_00546930_Class *)(DiffX))))->vdc(DiffA, 1);
                EntryLocVal = ((::fnv_00548880::FNV_Ref **)(std::uintptr_t)(reinterpret_cast<::C420410ExtraList *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00420410()));
                if (EntryLocVal)
                {
                    for (Diff_2 = 0; Diff_2 < 2; ++Diff_2)
                    {
                        if (EntryLocVal && EntryLocVal[Diff_2])
                        {
                            std::intptr_t Diff4 = ((std::intptr_t)(reinterpret_cast<::Ref5699 *>((EntryLocVal[Diff_2]))->FUN_005699b0()));
                            if (!Diff4)
                            {
                                Diff4 = ((std::intptr_t)(reinterpret_cast<::Ref5699 *>((((::fnv_00548880::FNV_Ref *)(std::uintptr_t)(reinterpret_cast<::FUN_004208b0_cls *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((EntryLocVal[Diff_2]))->FUN_005d43c0()))))->FUN_004208b0()))))->FUN_005699b0()));
                            }
                            if (Diff4)
                            {
                                reinterpret_cast<::FUN_004ed8c0_shell *>((((::fnv_00548880::FNV_LinkedDest *)(reinterpret_cast<::BSMultiBoundRoom *>((((FNV_LinkedDest*)Diff4)))->FUN_006ab360()))))->FUN_004ed8c0({});
                                if (Diff_2 == 0)
                                {
                                    reinterpret_cast<::FUN_009707f0_shell *>((((FNV_Render*)EntryLoc7)))->FUN_009707f0(Diff4);
                                }
                                else
                                {
                                    reinterpret_cast<::FUN_00420ba0_Class *>((((FNV_Render*)EntryLoc7)))->FUN_00420ba0(Diff4);
                                }
                            }
                        }
                        else
                        {
                            FNV_Effects* ExitLoc5 = ((::fnv_00548880::FNV_Effects *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
                            reinterpret_cast<::S_00c5b140 *>((ExitLoc5))->FUN_00c5b140((void *)(EntryLoc7));
                        }
                    }
                }
            }
        }
        Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(6)));
    }
    else if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<::fnv_00548880::FNV_Form * *>(&::DAT_011ca234)))
    {
        NiPoint3 Diff3;
        FNV_Primitive* Diff9;
        ClassFC* Diff7;
        Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(5)));
        Diff7 = (ClassFC*)((void *)(reinterpret_cast<::FUN_00422120_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00422120()));
        if (!Diff7)
        {
            Diff7 = new ClassFC();
            reinterpret_cast<::FUN_00422150_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00422150((::BSOcclusionPlane *)(Diff7));
        }
        reinterpret_cast<::S00416a70 *>((Diff7))->FUN_00416a70((::M00416a70 *)&(const ::fnv_00548880::ThreeByThreeMatrix &)(reference->FUN_0056fa00()));
        reinterpret_cast<::fnv_004169f0::BSOcclusionPlane_Fake *>((Diff7))->FUN_004169f0((*(const ::fnv_004169f0::NiPoint3 *)(reference->v1f4())));
        Diff9 = ((::fnv_00548880::FNV_Primitive *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041fbe0()));
        if (Diff9)
        {
            Diff3 = std::bit_cast<::fnv_00548880::NiPoint3>(reinterpret_cast<::FUN_00413fc0_Class *>((Diff9))->GetRadii());
            NiPoint2 DiffVal(Diff3.x, Diff3.z);
            reinterpret_cast<::S00416a30 *>((Diff7))->FUN_00416a30((::P00416a30 *)(::fnv_00548880::NiPoint2 *)(&DiffVal));
        }
    }
    else if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<::fnv_00548880::FNV_Form * *>(&::DAT_011ca240)))
    {
        Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(8)));
    }
    else if (reinterpret_cast<::FUN_00444ed0_shell *>((reference))->FUN_00444ed0() && ((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() == 0x1e)
    {
        Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::fnv_005495d0::FUN_005495d0_shell *>(this)->FUN_005495d0()));
        if (!::FUN_00549630((void *)(((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())))))
        {
            reinterpret_cast<::FUN_005452c0_shell *>(this)->RegisterReferenceInCell((::TESObjectREFR *)(reference));
        }
    }
    else if (reinterpret_cast<::FUN_00444ed0_shell *>((reference))->FUN_00444ed0() || ((::fnv_00548880::FNV_Primitive *)(reinterpret_cast<::FUN_0041fbe0_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041fbe0())))
    {
        switch (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170())
        {
        case 0xe:
            Dir2 = ((::fnv_00548880::FNV_Node *)(::fnv_005495f0::FUN_005495f0((const char *)this)));
            break;
        default:
            Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(1)));
            break;
        }
    }
    else if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() == 0xd)
    {
        Dir2 = ((::fnv_00548880::FNV_Node *)(::fnv_005495f0::FUN_005495f0((const char *)this)));
    }
    else
    {
        void* a1cTmp;
        FNV_Flags* Dir7;
        FNV_Flags* Dir3;
        if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() == 0x25)
        {
            reinterpret_cast<::FUN_005452c0_shell *>(this)->RegisterReferenceInCell((::TESObjectREFR *)(reference));
        }
        else if (reference->v224())
        {
            Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(4)));
        }
        else if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) && ((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() == 0x1e &&
                 !::FUN_00549630((void *)(((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())))))
        {
            reinterpret_cast<::FUN_005452c0_shell *>(this)->RegisterReferenceInCell((::TESObjectREFR *)(reference));
        }
        else
        {
            Dir3 = (FNV_Flags*)((::fnv_00548880::FNV_Flags *)(reinterpret_cast<::NiAVObject *>((((FNV_Node*)reference->v1d0())))->GetExtraData((*(const ::NiFixedString *)(((void *)&(::FUN_00448a80())))))));
            if (Dir3)
            {
                Dir7 = Dir3;
                if (::HasFlagOne((const ::BSXFlags *)(Dir7)))
                {
                    if (::fnv_00565580::FUN_00565580((::fnv_00565580::NiAVObject *)(void *)(reference->v1d0())))
                    {
                        Diff5 = true;
                        reinterpret_cast<::FUN_005452c0_shell *>(this)->RegisterReferenceInCell((::TESObjectREFR *)(reference));
                    }
                }
            }
        }
        if (!Dir2 && ((bool)(reinterpret_cast<::GlobalObject_0045cf30 *>(&((*reinterpret_cast<::fnv_00548880::FNV_GlobalCheck *>(&::g_011ca118))))->GetBoolValue())))
        {
            a1cTmp = ((void *)(reinterpret_cast<::FUN_00421e10_shell *>((((::fnv_00548880::FNV_Sub *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00421e10()));
            if (a1cTmp)
            {
                Dir2 = ((::fnv_00548880::FNV_Render *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget()))->FUN_00545960(a1cTmp);
            }
        }
        if (!Dir2)
        {
            Dir2 = ((::fnv_00548880::FNV_Node *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(3)));
        }
    }

    if (reinterpret_cast<::FUN_005694c0_shell *>((reference))->FUN_005694c0())
    {
        FUN_005453b0(reference);
    }
    if (((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() == 0x23)
    {
        reinterpret_cast<::fnv_005456b0::FUN_005456b0StandIn *>(this)->AddValueToHead((std::intptr_t)(reference));
        reinterpret_cast<::S_004e46b0_Cls *>((((::fnv_00548880::FNV_TESResult *)(std::uintptr_t)(::FUN_0070ec90((char *)(((FNV_TES*)DAT_011dea10)))))))->FUN_004e46b0({});
    }

    if (Dir2)
    {
        FNV_Render* EntryLoc;
        FNV_Render* Diff2;
        if (reference == DAT_011dea3c)
        {
            Dir2->vdc(((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00950bb0_shell *>((DAT_011dea3c))->FUN_00950bb0(0))));
            reinterpret_cast<::FUN_00a5a040_Class *>((((::fnv_00548880::FNV_Render *)(std::uintptr_t)(reinterpret_cast<::FUN_00950bb0_shell *>((DAT_011dea3c))->FUN_00950bb0(0)))))->FUN_00a5a040();
            Diff2 = ((::fnv_00548880::FNV_Render *)(std::uintptr_t)(reinterpret_cast<::FUN_00950bb0_shell *>((DAT_011dea3c))->FUN_00950bb0(0)))->v10();
            if (Diff2)
                Diff2->FUN_00476ab0();
            Dir2->vdc(((void *)(std::uintptr_t)(reinterpret_cast<::FUN_00950bb0_shell *>((DAT_011dea3c))->FUN_00950bb0(1))));
            reinterpret_cast<::FUN_00a5a040_Class *>((((::fnv_00548880::FNV_Render *)(std::uintptr_t)(reinterpret_cast<::FUN_00950bb0_shell *>((DAT_011dea3c))->FUN_00950bb0(1)))))->FUN_00a5a040();
        }
        else
        {
            if (!::FUN_008c7aa0())
            {
                reinterpret_cast<::FUN_005496b0_shell *>(this)->FUN_005496b0((::TESObjectREFR *)(reference), (::NiNode *)(Dir2));
            }
            else
            {
                ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(reference), (::NiNode *)(Dir2));
            }

            EntryLoc = ((FNV_Render*)((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((reference))->FUN_0043fcd0())))->v10();
            if (EntryLoc)
            {
                if (reinterpret_cast<::FUN_00549580_shell *>((((::fnv_00548880::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))))->FUN_00549580())
                {
                    reinterpret_cast<::FUN_0049ee60_shell *>((EntryLoc))->FUN_0049ee60(1);
                }
                else if (reinterpret_cast<::FUN_00564e60_shell *>((reference))->FUN_00564e60())
                {
                    reinterpret_cast<::FUN_00705b10_Dummy *>((EntryLoc))->Set(6);
                }
                else if (reinterpret_cast<::FUN_00564f00_shell *>((reference))->FUN_00564f00())
                {
                    reinterpret_cast<::FUN_00705b10_Dummy *>((EntryLoc))->Set(10);
                    reinterpret_cast<::BSFadeNode *>((EntryLoc))->SetRange(::DAT_01016970, ::DAT_01016970);
                }
                if (::Interface::IsGamePaused() || reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((((FNV_SaveLoad*)(*reinterpret_cast<void * *>(&::g_BGSSaveLoadGame)))))->FUN_0042ce10())
                {
                    EntryLoc->FUN_00476ab0();
                    ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(EntryLoc), 1.0f);
                    ((CellOffsets*)this)->unkC8 = ::DAT_0118b694;
                    ((CellOffsets*)this)->unkCE = 0;
                    ((CellOffsets*)this)->unkCF = 0;
                    ((CellOffsets*)this)->unkD0 = 1;
                }
                else
                {
                    reinterpret_cast<::Fade *>((EntryLoc))->UpdateFade((::Fade *)(void *)(((::fnv_00548880::FNV_Render *)(reinterpret_cast<::BSFaceGenNiNode *>((((::fnv_00548880::FNV_Render *)(::FUN_0045c670()))))->GetAnimationData()))), {});
                }
                if (((CellOffsets*)this)->unkAA > 0 && reinterpret_cast<::FUN_005495a0Class *>(this)->FUN_005495a0() && reinterpret_cast<::FUN_00557d10_Class *>(this)->FUN_00557d10())
                {
                    reinterpret_cast<::FUN_00557aa0_Class *>(this)->FUN_00557aa0();
                }
            }
        }
    }
}
}  // namespace fnv_00548880

namespace fnv_0054ca90 {
struct Ref;
struct Extra
{
};
struct Ref
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
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void clear(int);
    bool FUN_00564e60();
    void* FUN_00567d20();
    Extra* FUN_005d43c0();
    bool FUN_004077c0();
};
struct Handler
{
};
struct Loaded
{
};
struct State
{
};
struct Owner
{
};
struct List
{
};
struct Cell
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
    virtual void dirty(int);
    char pad[0xa4];
    unsigned short count;
    char pad2[0x1a];
    void* data;
    Owner* FUN_0054ddd0();
    void FUN_0054ca90(Ref* ref);
};
// @fnv 0x0054ca90
void Cell::FUN_0054ca90(Ref* ref)
{
    if (!ref)
        return;
    if (reinterpret_cast<::FUN_00564e60_shell *>((ref))->FUN_00564e60())
        --count;
    if (!ref->FUN_00567d20() && !reinterpret_cast<::FUN_004516b0_shell *>(((*(Handler**)&(*reinterpret_cast<char *>(&::g_dataHandler)))))->FUN_004516b0())
    {
        if (((void *)(reinterpret_cast<::TESObjectCELL *>(this)->FindEncounterZone())))
            reinterpret_cast<::fnv_00567dd0::FUN_00567dd0_shell *>((ref))->FUN_00567dd0((::fnv_00567dd0::BGSEncounterZone *)(void *)(((void *)(reinterpret_cast<::TESObjectCELL *>(this)->FindEncounterZone()))));
        else
            reinterpret_cast<::fnv_00567dd0::FUN_00567dd0_shell *>((ref))->FUN_00567dd0((::fnv_00567dd0::BGSEncounterZone *)(void *)(((void *)(::TESObjectREFR::GetDefaultEncounterZone()))));
    }
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    reinterpret_cast<::ItemChangeListNode *>((((::fnv_0054ca90::List *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))))->FUN_00905330((*(::InventoryStackRecord *const *)(&ref)));
    ::FUN_00541ae0((char *)this);
    if (::FUN_00450ff0((void *)this) || reinterpret_cast<::FUN_004523c0_shell *>(this)->FUN_004523c0())
        reinterpret_cast<::BGSLoadedReferenceCollection *>((((Loaded*)DAT_011c95c8)))->FUN_005270b0((::TESObjectREFR *)(ref));
    if (data)
    {
        bool enabled = false;
        enabled = reinterpret_cast<::FUN_004121b0_shell *>(((*(State**)&(*reinterpret_cast<char *>(&::g_BGSSaveLoadGame)))))->FUN_004121b0();
        if (enabled || reinterpret_cast<::fnv_005656d0::Thing *>((ref))->FUN_005656d0())
            reinterpret_cast<::fnv_00545590::FUN_00545590_Class *>(this)->FUN_00545590((unsigned int *)(ref));
        if (reinterpret_cast<::fnv_0056a250::FUN_0056a250_shell *>((ref))->FUN_0056a250())
            reinterpret_cast<::FUN_00545670_cls *>(this)->FUN_00545670(ref);
        reinterpret_cast<::FUN_00545360_StandIn *>(this)->FUN_00545360((std::uintptr_t)(ref));
        reinterpret_cast<::FUN_005454f0_cls *>(this)->FUN_005454f0(ref);
    }
    if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
    {
        reinterpret_cast<::FUN_0041d390_shell *>((((::fnv_0054ca90::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0041d390((::TESObjectCELL *)(0));
        Owner* owner = ((::fnv_0054ca90::Owner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()));
        if (owner)
            reinterpret_cast<::FUN_00587e40_shell *>((owner))->FUN_00587e40((::TESObjectREFR *)(ref));
    }
    else
    {
        ref->clear(0);
        if (((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == *(void**)&(*reinterpret_cast<char *>(&::DAT_011ca234)))
        {
            Ref** ppLinks = ((::fnv_0054ca90::Ref **)(std::uintptr_t)(reinterpret_cast<::FUN_00420100_cls *>((((::fnv_0054ca90::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->GetValue76()));
            if (ppLinks)
            {
                for (int i = 0; i < 4; ++i)
                {
                    if (ppLinks[i])
                    {
                        Ref** ppBack = ((::fnv_0054ca90::Ref **)(std::uintptr_t)(reinterpret_cast<::FUN_00420100_cls *>((((::fnv_0054ca90::Extra *)(reinterpret_cast<::FUN_005d43c0_ *>((ppLinks[i]))->FUN_005d43c0()))))->GetValue76()));
                        if (ppBack)
                        {
                            for (int j = 0; j < 4; ++j)
                            {
                                if (ppBack[j] == ref)
                                    ppBack[j] = 0;
                            }
                        }
                    }
                }
            }
        }
        if (!reinterpret_cast<::FUN_004077c0_shell *>((ref))->FUN_004077c0() && !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((ref))->FUN_005653d0() && !reinterpret_cast<::FUN_004226e0_shell *>(((*(Handler**)&(*reinterpret_cast<char *>(&::g_dataHandler)))))->FUN_004226e0())
            dirty(1);
    }
}
}  // namespace fnv_0054ca90

namespace fnv_00550500 {
struct TESRecordHeader;
struct File;
struct List;

struct TESRecordHeader
{
    unsigned int sig;
    unsigned int unk4;
    unsigned int flags;
    unsigned int type;
};

struct List
{
    bool FUN_008256d0();
};

struct File
{
    unsigned int GetFormID();
};

struct Handler
{
};

struct SaveLoad
{
};

struct Cell
{
    unsigned int FUN_0084e3a0();
    bool FUN_00550500(File* file);
};



// Loads this cell's record from the save file, validating group headers and constructing referenced objects, returning whether all constructions succeeded.
// @fnv 0x00550500
bool Cell::FUN_00550500(File* file)
{
    if (!file)
        return false;
    if (!reinterpret_cast<::TESFile *>((file))->IsMasterFile())
        return true;
    TESRecordHeader* hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
    if (hdr4->sig == ::DAT_011872b4)
    {
        if (((std::uintptr_t)(reinterpret_cast<::MiddleHighProcess *>((file))->GetFaceGenHeadNode())) != ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())))
            return false;
        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
        hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
        if (!::FUN_00554810((::Obj5548 *)(hdr4)))
            return true;
        if (hdr4->sig != ::fnv_00543df0::kGroupFormType || hdr4->type != 6)
            return false;
        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
        hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
        if (hdr4->sig != ::fnv_00543df0::kGroupFormType)
            return false;
        if (hdr4->type == 8)
        {
            reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
            hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
            if (!::FUN_00554810((::Obj5548 *)(hdr4)))
                return true;
        }
    }
    if (hdr4->sig != ::fnv_00543df0::kGroupFormType)
        return false;
    if (hdr4->type != 9)
        return false;
    if (reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true))
        hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
    else
        hdr4 = 0;
    (*reinterpret_cast<::fnv_00550500::Cell * *>(&::DAT_011c3f30)) = this;
    reinterpret_cast<::FUN_00550890_shell *>(((*reinterpret_cast<::fnv_00550500::Handler * *>(&::g_dataHandler))))->SetBoolAt61a(true);
    if (hdr4 && hdr4->sig == ::fnv_00543df0::kGroupFormType && hdr4->type == 9)
    {
        if (reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true))
            hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
        else
            hdr4 = 0;
    }
    ::FUN_005516a0(true);
    bool saved = reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::fnv_00550500::SaveLoad * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(false);
    bool ok5 = true;
    while (hdr4 && ::FUN_005548a0(::FindFormEnumIndex(hdr4->sig)))
    {
        unsigned int id4 = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::MiddleHighProcess *>((file))->GetFaceGenHeadNode()));
        if (::TESWorldSpace::IsFormIDOwnedByFile(id4, (::TESFile *)(file)))
        {
            void* p2 = ((void *)(::FUN_004839c0(id4)));
            bool b6 = false;
            if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00550500::SaveLoad * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                b6 = reinterpret_cast<::ST_00849cc0 *>(((*reinterpret_cast<::fnv_00550500::SaveLoad * *>(&::g_BGSSaveLoadGame))))->FUN_00849cc0(id4);
            bool b2 = false;
            if (reinterpret_cast<::TESFile *>((file))->IsMasterFile() && !((::fnv_00550500::List *)(reinterpret_cast<::FUN_00464df0_shell *>((file))->FUN_00464df0()))->FUN_008256d0() &&
                (((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()))->flags & 0x20) != 0)
                b2 = true;
            if (!p2 && !b6 && !b2)
            {
                if (!reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_00550500::Handler * *>(&::g_dataHandler))))->ConstructObject((::TESFile *)(file), false, (::TESForm *)(p2), false))
                    ok5 = false;
            }
        }
        if (reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true))
            hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
        else
            hdr4 = 0;
        if (hdr4 && hdr4->sig == ::fnv_00543df0::kGroupFormType && hdr4->type == 9 && hdr4->flags == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())))
        {
            if (reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true))
                hdr4 = ((::fnv_00550500::TESRecordHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
            else
                hdr4 = 0;
        }
    }
    ::FUN_005516a0(false);
    reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::fnv_00550500::SaveLoad * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(saved);
    (*reinterpret_cast<::fnv_00550500::Cell * *>(&::DAT_011c3f30)) = 0;
    reinterpret_cast<::FUN_00550890_shell *>(((*reinterpret_cast<::fnv_00550500::Handler * *>(&::g_dataHandler))))->SetBoolAt61a(false);
    return ok5;
}
}  // namespace fnv_00550500

namespace fnv_00552970 {
// 0x00552970  unit_9e852b306d07.cpp  /MT /Od /Oy- /GS /EHsc /Gy
using AutoMemHelper = ::AutoMemContext;

struct ShNiVt
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
    virtual void v55(void* idleForm, bool queued);
};

struct ShWorld
{
    void FUN_00454380(bool flag);
};

struct ShCell
{
};

struct ShPortalGraph
{
    void FUN_00b5ddf0(void* graph5);
};

struct ShSceneNode
{
    void FUN_00b5ddf0(void* graph5);
};

struct ShNavMgr
{
    void FUN_006c1170();
};

struct FUN_00552970_Call
{
    int field00;
    char pad04[0xcd];
    unsigned char fieldD1;

    void FUN_0054ba80(int flag);
    void FUN_005577b0(int flag);
    void UpdateCellScene(NiNode* node);
};

unsigned char FUN_00454ae0();
ShSceneNode* FUN_00450b80(int mode);

struct NavMeshObstacleManager
{
    void FUN_006c1170();
};

// @fnv 0x00552970
void FUN_00552970_Call::UpdateCellScene(NiNode* node)
{
    AutoMemHelper helper2(0x1a, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp",
                          0x395d);
    std::intptr_t v = ((std::intptr_t)(reinterpret_cast<::FUN_00545cf0_Cls *>(this)->GetOrCreateWidget()));
    reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(5);
    ((ShNiVt*)node)->v55((void*)v, 1);
    void* world = reinterpret_cast<::FUN_004543c0_cls *>(this)->FUN_004543c0();
    if (world)
    {
        if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
            reinterpret_cast<::FUN_005535f0_shell *>(this)->FUN_005535f0();
        reinterpret_cast<::FUN_00454380_Class *>((((ShWorld*)world)))->FUN_00454380(::FUN_00456c70() == 0);
        reinterpret_cast<::Root *>((((ShWorld*)world)))->SetProcessEnabled(FUN_00454ae0());
    }
    FUN_0054ba80(1);
    FUN_005577b0(1);
    reinterpret_cast<::FUN_0054b950_shell *>(this)->FUN_0054b950(1);
    if (reinterpret_cast<::TESObjectCELL *>((((ShCell*)((void *)(::FUN_00552ba0())))))->FUN_00552bb0())
        reinterpret_cast<::NavRenderX *>((((ShCell*)((void *)(::FUN_00552ba0())))))->FUN_006a37a0((::CellX *)(void *)(this), 1);
    reinterpret_cast<::TESObjectCELL *>(this)->ClearCellReferenceList();
    reinterpret_cast<::fnv_005575d0::FUN_005575d0_shell *>(this)->UpdateNavMeshObstacles();
    ::FUN_006c1170((char *)(((ShNavMgr*)((::fnv_00552970::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager())))));
    void* graph5 = ((void *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
    reinterpret_cast<::fnv_00b5ddf0::LocalTarget *>((((ShSceneNode*)FUN_00450b80(0))))->FUN_00b5ddf0((::fnv_00b5ddf0::LocalContext *)(graph5));
    if (!reinterpret_cast<::FUN_00c5b5d0_class *>((((ShPortalGraph*)graph5)))->FUN_00c5b5d0())
    {
        reinterpret_cast<::Owner5b *>((((ShPortalGraph*)graph5)))->FUN_00c5b1c0((::RefObj5b *)(void *)(((void *)(reinterpret_cast<::TESObjectCELL *>(this)->GetDynamicNode()))));
        reinterpret_cast<::Owner5b *>((((ShPortalGraph*)graph5)))->FUN_00c5b1c0((::RefObj5b *)(void *)(((void *)(reinterpret_cast<::FUN_0054a050_shell *>(this)->FUN_0054a050()))));
        reinterpret_cast<::Owner5b *>((((ShPortalGraph*)graph5)))->FUN_00c5b1c0((::RefObj5b *)(void *)(((void *)(reinterpret_cast<::S_FUN_0045bc00 *>((((ShSceneNode*)FUN_00450b80(0))))->FUN_0045bc00(5)))));
    }
    ((ShNiVt*)((void *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(6))))->v55(((void *)(::fnv_00546930::FUN_00546930((::fnv_00546930::FUN_00546930_Class *)(((ShPortalGraph*)graph5))))), 1);
    reinterpret_cast<::OwnerC5 *>((((ShPortalGraph*)graph5)))->FUN_00c5b9a0((::NavObject *)(void *)(((void *)(::FUN_0054aa60((::TESObjectCELL *)this)))));
    reinterpret_cast<::OwnerC5 *>((((ShPortalGraph*)graph5)))->FUN_00c5b9a0((::NavObject *)(void *)(((void *)(reinterpret_cast<::FUN_0054a050_shell *>(this)->FUN_0054a050()))));
    reinterpret_cast<::OwnerC5 *>((((ShPortalGraph*)graph5)))->FUN_00c5b9a0((::NavObject *)(void *)(((void *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(2)))));
    reinterpret_cast<::OwnerC5 *>((((ShPortalGraph*)graph5)))->FUN_00c5b9a0((::NavObject *)(void *)(((void *)(::FUN_00524cf0((::TESObjectCELL *)this)))));
    fieldD1 = 0;
}
}  // namespace fnv_00552970

namespace fnv_005538e0 {
struct Vec5538
{
    float x, y, z;
};
struct Sound5538
{
    unsigned int FUN_0084e3a0();
};
struct Ref5538
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
    virtual void v115();
    virtual NiAVObject* node();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Vec5538* pos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool active();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool check(int);
};
struct List5538
{
    Ref5538*& FUN_006815c0();
};
struct Handle5538
{
    unsigned int a, b, c;
    ~Handle5538();
};
struct Audio5538
{
    Handle5538 FUN_00ad73b0(unsigned int, unsigned int);
};
struct Player5538
{
};
struct Cell5538
{
    void PlayCellSoundEffects();
};
// Iterates the cell's references and plays a positional sound for each eligible reference within range of the player.
// @fnv 0x005538e0
void Cell5538::PlayCellSoundEffects()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    if (::FUN_00450ff0((void *)this))
    {
        List5538* list3 = ((::fnv_005538e0::List5538 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (list3 && ((::fnv_005538e0::Ref5538 *)((void *)(list3))))
        {
            Ref5538* ref = ((::fnv_005538e0::Ref5538 *)((void *)(list3)));
            if (ref && !reinterpret_cast<::TESForm *>((ref))->GetDisabled() && !reinterpret_cast<::FUN_00477ba0_shell *>((ref))->FUN_00477ba0() && reinterpret_cast<::FUN_00553bb0_caller *>((ref))->FUN_00553bb0() &&
                (!ref->active() || !ref->check(0)))
            {
                Sound5538* sound4 = ((::fnv_005538e0::Sound5538 *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>((ref))->GetMinLevel()));
                if (sound4 && ::RandomBoolean(((signed char)(::FUN_00553b60((char *)(sound4)))) / *(double*)&DAT_010179e0) && *::FUN_00511840((char *)(sound4)))
                {
                    unsigned int range = reinterpret_cast<::TESSound *>((sound4))->GetField45() * 100;
                    float distance = reinterpret_cast<::RefS *>(((*(Player5538**)&DAT_011dea3c)))->FUN_005723b0((::RefS *)(ref), 0, 0);
                    if (range > (unsigned int)distance)
                    {
                        Handle5538 a2 = ((::fnv_005538e0::Audio5538 *)(::FUN_00453a70()))->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((sound4))->FUN_0084e3a0())), 0x2102);
                        if (ref->node())
                            reinterpret_cast<::FUN_00ad8f20_shell *>(&(a2))->FUN_00ad8f20(ref->node());
                        Vec5538 position4 = *ref->pos();
                        reinterpret_cast<::FUN_00ad8b60_h *>(&(a2))->FUN_00ad8b60(position4.x, position4.y, position4.z);
                        reinterpret_cast<::FUN_00ad9030_shell *>(&(a2))->FUN_00ad9030(0xc0);
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(a2))->FUN_00ad8830(false);
                    }
                }
            }
            list3 = ((::fnv_005538e0::List5538 *)(reinterpret_cast<::Callees *>((list3))->FUN_00726070()));
        }
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_005538e0

namespace fnv_005574d0 {
class BGSPerkEntry;

class BGSLoadedReferenceCollection;  // already defined by pack header


struct S_005270b0_Coll
{
};

struct S_00549580_Owner
{
    bool FUN_00549580();
};

struct S_00586170_Result
{
    void FUN_006fcfa0();
    void FUN_00929260();
};

struct S_00575d70_Owner
{
    S_00586170_Result* FUN_00586170(BGSPerkEntry* entry);
    S_00586170_Result* FUN_00586170(BGSPerkEntry* entry, unsigned int flag);
    S_00586170_Result* FUN_00586170(unsigned int flag);
};

class BGSPerkEntry
{
  public:
    S_00575d70_Owner* FUN_00575d70();
};

struct S_011dea10_Owner
{
};
extern S_011dea10_Owner* DAT_011dea10;

class S_005574d0_Owner
{
  public:
    void ProcessPerkEntries();
};

// @fnv 0x005574d0
void S_005574d0_Owner::ProcessPerkEntries()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    BSSimpleList<BGSPerkEntry*>* list = ((::BSSimpleList< ::fnv_005574d0::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (list != 0)
    {
        BGSPerkEntry* entry = (list->item);
        if (entry != 0)
        {
            reinterpret_cast<::BGSLoadedReferenceCollection *>((((S_005270b0_Coll*)(*reinterpret_cast<::fnv_005574d0::BGSLoadedReferenceCollection * *>(&::DAT_011c95c8)))))->FUN_005270b0((::TESObjectREFR *)(entry));
            if (((std::uintptr_t)(reinterpret_cast<::BGSCameraPath *>((DAT_011dea10))->GetPrevPath())) == 0 && ((std::uintptr_t)(reinterpret_cast<::EffectSetting *>((DAT_011dea10))->GetHitSound())) != 0 &&
                reinterpret_cast<::FUN_00549580_shell *>((((::fnv_005574d0::S_00549580_Owner *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((entry))->FUN_007af430()))))->FUN_00549580())
            {
                S_00575d70_Owner* refs = ((::fnv_005574d0::S_00575d70_Owner *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((entry))->FUN_00575d70()));
                if (refs != 0)
                {
                    if (!reinterpret_cast<::TESForm *>((entry))->GetDisabled())
                    {
                        reinterpret_cast<::fnv_006fd010::FUN_006fd010_shell *>((((::fnv_005574d0::S_00586170_Result *)(reinterpret_cast<::TESWorldSpace *>((refs))->GetWorldTerrainManager()))))->RunAndDispatch({});
                    }
                    else
                    {
                        reinterpret_cast<::Dfcfa0Manager *>((((::fnv_005574d0::S_00586170_Result *)(reinterpret_cast<::TESWorldSpace *>((refs))->GetWorldTerrainManager()))))->FUN_006fcfa0({}, {});
                    }
                    reinterpret_cast<::MiddleHighProcess *>((((::fnv_005574d0::S_00586170_Result *)(reinterpret_cast<::TESWorldSpace *>((refs))->GetWorldTerrainManager()))))->FUN_00929260({});
                }
            }
        }
        list = ((::BSSimpleList< ::fnv_005574d0::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_005574d0

namespace fnv_005596a0 {

class FUN_005596a0
{
  public:
    virtual ~FUN_005596a0();
    int unk04;
    void* unk08;
};

// Destructor that frees the heap block stored in unk08 if it is non-null.
// @fnv 0x005596a0
FUN_005596a0::~FUN_005596a0()
{
    if (unk08)
    {
        void* block = unk08;
        operator delete(block);
    }
}
}  // namespace fnv_005596a0

struct Base5415
{
    virtual void slot0();
    char field04[0x14];
    Base5415();
    ~Base5415();
};
struct Name5415
{
    virtual void slotName();
    char field04[8];
    Name5415();
    ~Name5415();
};
struct Extra5415
{
    char field00[0x20];
    Extra5415();
    ~Extra5415();
};
struct Texture5415
{
    virtual void slot0();
    char field04[8];
    Texture5415();
    ~Texture5415();
};
struct List805415
{
    void* field00;
    void* field04;
    List805415();
};
struct ListAC5415
{
    void* field00;
    void* field04;
    ListAC5415();
    ~ListAC5415();
};
struct Ref5415
{
    void* field00;
    Ref5415(int);
    ~Ref5415();
    void FUN_0066b0d0(void*);
};
struct FUN_005415b0 : Base5415, Name5415
{
    virtual void slot0();
    unsigned char field24, field25, field26, field27;
    Extra5415 field28;
    unsigned field48, field4c;
    float field50;
    unsigned char field54;
    char field55[3];
    Texture5415 field58;
    unsigned field64;
    char field68[0x18];
    List805415 field80;
    char field88[0x18];
    unsigned fielda0, fielda4;
    unsigned short fielda8, fieldaa;
    ListAC5415 fieldac;
    Ref5415 fieldb4, fieldb8, fieldbc;
    unsigned fieldc0, fieldc4;
    float fieldc8;
    unsigned char fieldcc, fieldcd, fieldce, fieldcf, fieldd0, fieldd1, fieldd2, fieldd3;
    Ref5415 fieldd4;
    unsigned fieldd8, fielddc;
    FUN_005415b0();
};
// Sets several fields to default values and calls helper and member functions during construction.
// @fnv 0x005415b0
FUN_005415b0::FUN_005415b0() : fieldb4(0), fieldb8(0), fieldbc(0), fieldd4(0)
{
    field24 = 0;
    field26 = 0;
    fielddc = 0x9f;
    fieldd8 = 0;
    field48 = 0;
    field4c = 0;
    field50 = 3.4028234663852886e+38f;
    field64 = 0;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x39);
    fieldc0 = 0;
    field25 = 0;
    fieldc4 = 0;
    fielda4 = 0;
    fielda0 = 0;
    fielda8 = 0;
    fieldaa = 0;
    fieldc8 = 0.0f;
    fieldcc = 0;
    fieldcd = 0;
    field54 = 0;
    fieldcf = 0;
    fieldce = 0;
    fieldd0 = 0;
    fieldd1 = 0;
    fieldd2 = 0;
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
    fieldd4.FUN_0066b0d0(0);
    field58.slot0();
}

using Mem960 = ::AutoMemContext;
struct LandscapeColorData;
class TESObjectLAND
{
  public:
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
    TESObjectLAND();
public:
    bool FUN_0053f180(const ::LandscapeColorData &, float &);
};
struct CellH
{
};
struct S00546fb0_Cell
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
    TESObjectLAND* field4c;
    TESObjectLAND* FUN_00546fb0();
};
// @fnv 0x0054d090
void MarkerCell::FUN_0054d090(NiPoint3* position, NiPoint3* angle)
{
    CellRefLockEnter();
    MarkerRef* fallback = 0;
    MarkerRef* markerD = 0;
    MarkerRef* markerB = 0;
    MarkerRef* hasPosition = 0;
    MarkerList* markerC;
    MarkerRef* node = 0;
    bool markerA = false;
    markerC = (MarkerList*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (markerC && !markerC->_ref_008256d0())
    {
        MarkerRef* ref = *((::MarkerRef **)((void *)(markerC)));
        if (!reinterpret_cast<::FUN_00440d80_shell *>((ref))->FUN_00440d80())
        {
            if (!markerB && ((::MarkerBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<::MarkerBase * *>(&::DAT_011ca24c)) &&
                (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(ref->Position())))))
                markerB = ref;
            if (!fallback && ((::MarkerBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<::MarkerBase * *>(&::DAT_011ca244)) &&
                (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(ref->Position())))))
                fallback = ref;
            if (!markerD && ((::MarkerBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<::MarkerBase * *>(&::DAT_011ca248)) &&
                (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(ref->Position())))))
                markerD = ref;
            if (!markerA)
            {
                MarkerData* data = ((::MarkerData *)(reinterpret_cast<::TESObjectREFR *>((ref))->GetExtraRadioData()));
                if (data && ((::MarkerRef *)(::FUN_00559450((int *)(data)))))
                {
                    data = ((::MarkerData *)(reinterpret_cast<::TESObjectREFR *>((((::MarkerRef *)(::FUN_00559450((int *)(data))))))->GetExtraRadioData()));
                    if (data)
                    {
                        NiPoint3 point = *((::NiPoint3 *)(reinterpret_cast<::BaseProcess *>((data))->GetCurrentProcessData()));
                        if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(&point))))
                        {
                            *position = point;
                            markerA = true;
                        }
                    }
                }
            }
            if (!hasPosition && ((::MarkerBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FUN_00401170() == 32 &&
                (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(ref->Position())))))
                hasPosition = ref;
            if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(ref->Position()))))
                node = ref;
        }
        markerC = ((::MarkerList *)(reinterpret_cast<::Callees *>((markerC))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
    if (markerB)
    {
        *position = *markerB->Position();
        *angle = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((markerB))->GetData()));
    }
    else if (markerD)
    {
        *position = *markerD->Position();
        *angle = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((markerD))->GetData()));
    }
    else if (fallback)
    {
        *position = *fallback->Position();
    }
    else if (!markerA)
    {
        if (hasPosition)
            *position = *hasPosition->Position();
        else if (node)
            *position = *node->Position();
    }
    if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        MarkerLand* land = ((::MarkerLand *)(reinterpret_cast<::S00546fb0_Cell *>(this)->FUN_00546fb0()));
        if (land)
        {
            float water = 0.0f;
            reinterpret_cast<::TESObjectLAND *>((land))->FUN_0053f180((*(const ::LandscapeColorData *)(position)), (*(float *)(&water)));
            float height = reinterpret_cast<::FUN_005471e0_shell *>(this)->FUN_005471e0();
            if (water < height)
                water = height;
            if (water > position->z)
                position->z = water;
        }
    }
}
// Builds a CellTypedHandle from DAT_0102f024, optionally filling it from a child handle, and copies it into result.
// @fnv 0x0054e640
void CellHandleProvider::FUN_0054e640(CellTypedHandle* result)
{
    CellTypedHandle current(0);
    current.typeData = &DAT_0102f024;
    if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        CellHandle child(0);
        reinterpret_cast<::CellRenderer *>(this)->BuildExteriorCameraScene((::RenderPtr *)(::CellHandle *)(&child));
        current.FUN_0066b0d0(((int)(reinterpret_cast<::FUN_004bc320_shell *>((((::CellHandleData *)(::FUN_00559450((int *)&(child))))))->FUN_004bc320({}))));
        reinterpret_cast<::FUN_0054e710_cls *>((((::CellHandleData *)(::FUN_00559450((int *)&(child))))))->FUN_0054e710();
    }
    result->FUN_006e5cc0(&current);
}
// @fnv 0x0054ee80
void CellRenderer::BuildExteriorCameraScene(RenderPtr* output)
{
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        *output = 0;
        return;
    }
    RenderObject* scene5 = FUN_00450b80(0);
    RenderRange range3;
    RenderPoint position9 = *(RenderPoint*)&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
    RenderMatrix _dx;
    reinterpret_cast<::Matrix161 *>(&(_dx))->FUN_00a59540(-1.57079637f, -1.57079637f, 1.57079637f);
    RenderFrustum _bA(false);
    _bA.nearDist = 100.0f;
    _bA.ortho = true;
    RenderSource sourcePos_;
    range3 = *((::RenderRangeSource *)(reinterpret_cast<::S00546fb0_Cell *>(this)->FUN_00546fb0()))->FUN_0053f440();
    const int center7 = 2176;
    position9.x = float((reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() << 12) + center7);
    position9.y = float((reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() << 12) + center7) - 32.0;
    position9.z = range3.high + 20000.0;
    _bA.left = -2176.0f;
    _bA.right = 2176.0f;
    _bA.top = 2176.0f;
    _bA.bottom = -2176.0f;
    _bA.farDist = position9.z - range3.low + 10.0;
    RenderPtr camera_2(new RenderCamera);
    RenderPtr nodeB(new RenderNode(0));
    ((RenderObject*)nodeB)->Attach(camera_2, true);
    reinterpret_cast<::FUN_00440460_S *>((((RenderObject*)nodeB)))->FUN_00440460((const ::V3 *)&(position9));
    scene5->Attach(nodeB, true);
    reinterpret_cast<::FUN_0043fa80_s *>((((RenderObject*)camera_2)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(_dx));
    reinterpret_cast<::NiCamera *>((((RenderObject*)camera_2)))->UpdateViewFrustum((const ::NiFrustum &)(_bA));
    RenderUpdate updateNodeTmp(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((RenderObject*)nodeB)))->FUN_00a59c60((std::intptr_t)&(updateNodeTmp));
    RenderUpdate updateCameraVal(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((RenderObject*)camera_2)))->FUN_00a59c60((std::intptr_t)&(updateCameraVal));
    ::SetByteAtOffset1B(true);
    ::fnv_006652e0::FUN_006652e0((::fnv_006652e0::NiAVObject *)(::RenderObject *)(camera_2), true);
    reinterpret_cast<::CellQ *>(this)->FUN_005570d0();
    bool _bp = false, _m4 = false, _fB = false;
    RenderObject* _ok = ((::RenderObject *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(0)));
    if (_ok)
    {
        _bp = reinterpret_cast<::FUN_00456630_helper *>((_ok))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((_ok))->QueueActorDisarm(true);
    }
    RenderObject* _b8 = ((::RenderObject *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(1)));
    if (_b8)
    {
        _m4 = reinterpret_cast<::FUN_00456630_helper *>((_b8))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((_b8))->QueueActorDisarm(true);
    }
    RenderObject* _ch = ((::RenderObject *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(2)));
    if (_ch)
    {
        _fB = reinterpret_cast<::FUN_00456630_helper *>((_ch))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((_ch))->QueueActorDisarm(true);
    }
    RenderObject* _f8 = ((::RenderObject *)(reinterpret_cast<::StrOwner *>((((::RenderSky *)(::Sky::GetInstance()))))->FUN_007fa950()));
    bool _ap = false;
    if (_f8)
    {
        _ap = reinterpret_cast<::FUN_00456630_helper *>((_f8))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((_f8))->QueueActorDisarm(true);
    }
    RenderObject* extraNodeA = (RenderObject*)FUN_0054f4f0();
    bool _b4 = false;
    if (_f8)
    {
        _b4 = reinterpret_cast<::FUN_00456630_helper *>((extraNodeA))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((extraNodeA))->QueueActorDisarm(true);
    }
    bool _m2 = false;
    RenderObject* other_ = (RenderObject*)FUN_0054f4c0();
    if (other_)
    {
        _m2 = reinterpret_cast<::FUN_00456630_helper *>((other_))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((other_))->QueueActorDisarm(true);
    }
    unsigned char oldState7 = FUN_0054f4b0();
    FUN_004e20b0(0);
    RenderPtr _p1(0);
    FUN_0054e830(camera_2, &_p1);
    FUN_004e20b0(oldState7);
    if (other_)
        reinterpret_cast<::TaskQueueInterface *>((other_))->QueueActorDisarm(_m2);
    if (extraNodeA)
        reinterpret_cast<::TaskQueueInterface *>((extraNodeA))->QueueActorDisarm(_b4);
    if (_f8)
        reinterpret_cast<::TaskQueueInterface *>((_f8))->QueueActorDisarm(_ap);
    if (_ok)
        reinterpret_cast<::TaskQueueInterface *>((_ok))->QueueActorDisarm(_bp);
    if (_b8)
        reinterpret_cast<::TaskQueueInterface *>((_b8))->QueueActorDisarm(_m4);
    if (_ch)
        reinterpret_cast<::TaskQueueInterface *>((_ch))->QueueActorDisarm(_fB);
    ::fnv_006652e0::FUN_006652e0((::fnv_006652e0::NiAVObject *)(::RenderObject *)(((::RenderObject *)(::FUN_00524c90()))), true);
    ::SetByteAtOffset1B(false);
    reinterpret_cast<::CellQ *>(this)->FUN_005570d0();
    scene5->Detach(nodeB);
    nodeB = 0;
    camera_2 = 0;
    *output = _p1;
}
// @fnv 0x00546fb0
TESObjectLAND* S00546fb0_Cell::FUN_00546fb0()
{
    if (((TESObjectCELL*)this)->IsCellInterior() || reinterpret_cast<::FUN_005516c0 *>((((CellH*)this)))->IsCellPersistent())
        return 0;
    if (!field4c)
    {
        Mem960 ctx(0x1b, 1, ::str_0102ed68, 0xfb6);
        field4c = new TESObjectLAND;
        reinterpret_cast<::fnv_005340e0::TESObjectLAND *>((field4c))->FUN_005340e0((::fnv_005340e0::TESObjectCELL *)(::TESObjectCELL *)((TESObjectCELL*)this));
    }
    return field4c;
}

namespace fnv_00547ad0 {
struct MaskPixels
{
    int iBytesPerPixel;
    unsigned char* pPixels;
};

struct MaskSurface
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
    virtual long LockRect(unsigned int auiLevel, MaskPixels* apLocked, void* apRect, unsigned int auiFlags);
};

struct MaskRenderData
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual MaskSurface* FUN_vt9c();
};

struct MaskTexture
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual int FUN_vt98();
};

struct CellLand
{
};

struct CellName
{
};

struct MaskGridPos
{
    float x, y;
};

struct MaskCellPos
{
    MaskGridPos kGrid;
    int iPad08[0x12];
    MaskCellPos();
};

struct MaskWorldPos
{
    float x, y, z;
};

struct CellGrid
{
};

struct MaskLock
{
};

extern bool DAT_011ca090;
float __cdecl FUN_00476b70(float afMin, float afMax);

struct CellMask : TESObjectCELL
{
    bool FUN_00425fd0();
    CellName* FUN_0054ddd0();
    void FUN_00547ad0(MaskWorldPos kPos, unsigned int uiRadius, int aiUnused);
};


// Writes values based on distance from kPos into the cell texture and neighboring cell textures within the processed radius.
// @fnv 0x00547ad0
void CellMask::FUN_00547ad0(MaskWorldPos kPos, unsigned int uiRadius, int aiUnused)
{
    if (DAT_011ca090)
        return;
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || !*reinterpret_cast<::FUN_00548210_Class *>((((::fnv_00547ad0::CellName *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->FUN_00548210())
        return;
    if (((bool)(::FUN_00452480())))
        ::fnv_00665610::FUN_00665610();
    MaskTexture* pTexture = 0;
    MaskPixels* pPixels = 0;
    MaskTexture* pNorthOld = 0;
    MaskTexture* pSouthCur = 0;
    MaskTexture* pEast = 0;
    MaskTexture* pWestNew = 0;
    MaskTexture* pNorthEastTmp = 0;
    MaskTexture* pNorthWestOut = 0;
    MaskTexture* pSouthEastResult = 0;
    MaskTexture* pSouthWestInfo = 0;
    reinterpret_cast<::Hold580 *>((((::fnv_00547ad0::CellLand *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->GetExtraDataNameAndPtr((const char **)(::fnv_00547ad0::MaskTexture **)(&pTexture), (unsigned int **)(::fnv_00547ad0::MaskPixels **)(&pPixels));
    if (uiRadius == 0 || uiRadius > 0x400 || uiRadius < 0)
        uiRadius = 300;
    if (!pTexture)
        ::CreateAndClearRenderTarget((::CellInput *)(::fnv_00547ad0::CellMask *)(this), (::RenderData **)(::fnv_00547ad0::MaskTexture **)(&pTexture), (::LockedRect **)(::fnv_00547ad0::MaskPixels **)(&pPixels));
    MaskCellPos kCellPosPos;
    if (!((::fnv_00547ad0::CellGrid *)(reinterpret_cast<::S00546fb0_Cell *>(this)->FUN_00546fb0())) || !reinterpret_cast<::xLand *>((((::fnv_00547ad0::CellGrid *)(reinterpret_cast<::S00546fb0_Cell *>(this)->FUN_00546fb0()))))->FUN_0053b550((*(::xCoordData *)(&kCellPosPos)), (*(const ::xPoint3 *)(&kPos)), 0))
        return;
    MaskGridPos kCenterData = kCellPosPos.kGrid;
    kCenterData.x = kCenterData.x / 64.0;
    kCenterData.y = kCenterData.y / 64.0;
    uiRadius >>= 6;
    int iIndexCount = 0;
    if (pTexture)
    {
        ::FUN_004a0370((char *)(((::fnv_00547ad0::MaskLock *)(::FUN_0043c4b0()))));
        if (pPixels->pPixels == 0)
        {
            MaskRenderData* pRenderData = ((::fnv_00547ad0::MaskRenderData *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((pTexture))->GetCurrentMoveModeType()));
            if (pRenderData)
            {
                MaskSurface* pSurface = pRenderData->FUN_vt9c();
                pSurface->LockRect(0, pPixels, 0, 0);
            }
        }
        unsigned char* pDataVal = pPixels->pPixels;
        int iWidthNew = pTexture->FUN_vt98();
        int iRowBytesRes = pPixels->iBytesPerPixel * iWidthNew;
        unsigned char ucValue = 0;
        int iHorizontalPixelCenterObj = (int)kCenterData.x;
        int iCenterPixelY = (int)kCenterData.y;
        float fDistOut;
        for (int y = iCenterPixelY - uiRadius; y < iCenterPixelY + uiRadius; y++)
        {
            for (int x = iHorizontalPixelCenterObj - uiRadius; x < iHorizontalPixelCenterObj + uiRadius; x++)
            {
                fDistOut =
                    ::FUN_004019b0((kCenterData.x - x) * (kCenterData.x - x) + (kCenterData.y - y) * (kCenterData.y - y));
                if (uiRadius >= fDistOut)
                {
                    iIndexCount = y * iWidthNew + x;
                    ucValue = (unsigned char)(255.0 - FUN_00476b70(0.0f, 55.0f) - fDistOut / uiRadius * 60.0);
                    if (y < 64 && y >= 0 && x < 64 && x >= 0)
                    {
                        if (pDataVal[iIndexCount])
                            pDataVal[iIndexCount] = 0xff;
                        else
                            pDataVal[iIndexCount] = ucValue;
                    }
                    else if (y >= 64 && x < 0)
                    {
                        iIndexCount = (y - 64) * iWidthNew + x + 64;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() - 1, reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() + 1, (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pNorthWestOut), iIndexCount, ucValue);
                    }
                    else if (y >= 64 && x >= 64)
                    {
                        iIndexCount = (y - 64) * iWidthNew + x - 64;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() + 1, reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() + 1, (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pNorthEastTmp), iIndexCount, ucValue);
                    }
                    else if (y < 0 && x < 0)
                    {
                        iIndexCount = (y + 64) * iWidthNew + x + 64;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() - 1, reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() - 1, (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pSouthWestInfo), iIndexCount, ucValue);
                    }
                    else if (y < 0 && x >= 64)
                    {
                        iIndexCount = (y + 64) * iWidthNew + x - 64;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() + 1, reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() - 1, (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pSouthEastResult), iIndexCount,
                                        ucValue);
                    }
                    else if (y >= 64)
                    {
                        iIndexCount = (y - 64) * iWidthNew + x;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() + 1, (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pNorthOld), iIndexCount, ucValue);
                    }
                    else if (y < 0)
                    {
                        iIndexCount = (y + 64) * iWidthNew + x;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() - 1, (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pSouthCur), iIndexCount, ucValue);
                    }
                    else if (x >= 64)
                    {
                        iIndexCount = y * iWidthNew + x - 64;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() + 1, reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY(), (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pEast), iIndexCount, ucValue);
                    }
                    else if (x < 0)
                    {
                        iIndexCount = y * iWidthNew + x + 64;
                        reinterpret_cast<::C5479C0Manager *>(this)->SetGridDataByte(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() - 1, reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY(), (::C5479C0Grid **)(::fnv_00547ad0::MaskTexture **)(&pWestNew), iIndexCount, ucValue);
                    }
                }
            }
        }
        reinterpret_cast<::fnv_004a03c0::DD *>((((::fnv_00547ad0::MaskLock *)(::FUN_0043c4b0()))))->FUN_004a03c0();
    }
}
}  // namespace fnv_00547ad0

namespace fnv_0054e830 {
struct C0054e830;

class NP
{
  public:
    void* m;
    NP(void*);
    ~NP();
    void Reset(void*);
    NP& operator=(NP const&);
    operator void*() const;
};

using AutoMemHelper = ::AutoMemContext;

class CullProc
{
  public:
    void* m;
    CullProc(void*);
    ~CullProc();
};

struct ImageSpaceEffectParam
{
  public:
    float a;
    float b;
    float c;
    float d;
    ImageSpaceEffectParam(float, float, float, float);
};

class VT
{
  public:
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
    virtual void v43(ImageSpaceEffectParam&);
    virtual void v44();
    virtual void v45(ImageSpaceEffectParam&);
};

class TexMgr
{
  public:
    void* M4(void*, int, int, int);
};

class BSA
{
  public:
    char pad[0x280];
    BSA(int, int, int);
};

struct ShadowSceneNode
{
  public:
};

class AVObj
{
  public:
};

class ImageSpaceEffect;

struct ImageSpaceManager
{
  public:
};

class RenderedTexture
{
  public:
    void* GetGroup();
};

class Ctx
{
  public:
};

ShadowSceneNode* FUN_00450b80(unsigned int);
void FUN_00b6b8d0(int, void*);
void FUN_00b6bee0(void*, void*, void*);
void FUN_00b6b840();

struct Pad40
{
    int a[10];
};

struct C0054e830
{
    void FUN_0054e830(void*, NP*);
};

// Renders a shadow into a texture using a shadow scene node and image space effect, then restores the previous state.
// @fnv 0x0054e830
void C0054e830::FUN_0054e830(void* arg1, NP* apOutTexture)
{
    Pad40 holder, buf2, reserve, tempArea, workBuf;
    AutoMemHelper acc(0xe, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp", 0x2251);
    NP ctx(((void *)(::FUN_00b4f5c0())));
    CullProc chi(0);
    NP next(0);
    NP group(0);
    NP p4(0);
    ImageSpaceEffect* pip;
    p4.Reset(((void *)(reinterpret_cast<::Pool *>((((::fnv_0054e830::TexMgr *)(::FUN_004a0ea0()))))->FUN_00b6e110((std::uintptr_t)(((::fnv_0054e830::VT *)(::FUN_004a0e90()))), 0x1e, 0, 0, 0))));
    group.Reset(((::fnv_0054e830::TexMgr *)(::FUN_004a0ea0()))->M4(((::fnv_0054e830::VT *)(::FUN_004a0e90())), 0x1c, 0, 0));
    if ((void*)group && (void*)p4)
    {
        ImageSpaceEffectParam dst(0.0f, 0.0f, 0.0f, 0.0f);
        ((::fnv_0054e830::VT *)(::FUN_004a0e90()))->v45(dst);
        ImageSpaceEffectParam src(0.0f, 0.0f, 0.0f, 1.0f);
        ((::fnv_0054e830::VT *)(::FUN_004a0e90()))->v43(src);
        ShadowSceneNode* pf = FUN_00450b80(0);
        unsigned char l3 = reinterpret_cast<::FUN_005f9ad0_shell *>((pf))->FUN_005f9ad0();
        reinterpret_cast<::FUN_005f9af0_shell *>((pf))->SetCreatureType(1);
        bool b2 = ::FUN_004e9510();
        AVObj* a1 = ((::fnv_0054e830::AVObj *)(::FUN_004e7ff0()));
        bool v1 = false;
        bool rho = true;
        if (a1)
        {
            v1 = reinterpret_cast<::FUN_00456630_helper *>((a1))->FUN_00456610();
            reinterpret_cast<::TaskQueueInterface *>((a1))->QueueActorDisarm(1);
        }
        rho = ((bool)(::FUN_0054ee20({})));
        ::FUN_0054ee60(0);
        if (b2)
        {
            FUN_00b6b8d0(7, ((RenderedTexture*)(void*)p4)->GetGroup());
        }
        else
        {
            ::FUN_0054ede0((::BSRenderedTexture *)(void *)((void*)p4), 7);
        }
        NP q2(new BSA(0x63, 1, 0x2f7));
        reinterpret_cast<::BSA_ *>((((BSA*)(void*)q2)))->FUN_004a1020(pf);
        reinterpret_cast<::FUN_004a0fd0_shell *>(&(chi))->FUN_004a0fd0((::NiNode *)(void *)((void*)q2));
        reinterpret_cast<::FUN_004a1040_Helper *>((((BSA*)(void*)q2)))->Set(9);
        reinterpret_cast<::FUN_00c4f270_Class *>(&(chi))->FUN_00c4f270(3);
        FUN_00b6bee0(arg1, pf, &chi);
        reinterpret_cast<::FUN_00c4f2d0_class *>(&(chi))->FUN_00c4f2d0();
        if (((void *)(reinterpret_cast<::TESObjectCELL *>((this))->GetCellChildAt(6))))
        {
            reinterpret_cast<::FUN_00c4f270_Class *>(&(chi))->FUN_00c4f270(1);
            FUN_00b6bee0(arg1, ((void *)(reinterpret_cast<::TESObjectCELL *>((this))->GetCellChildAt(6))), &chi);
            reinterpret_cast<::FUN_00c4f2d0_class *>(&(chi))->FUN_00c4f2d0();
        }
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(arg1), (::BSShaderAccumulator *)(void *)((void*)q2), 0);
        reinterpret_cast<::FUN_004a0fd0_shell *>(&(chi))->FUN_004a0fd0((::NiNode *)(void *)(0));
        q2.Reset(0);
        if (b2)
        {
            ::BSRenderedTexture::EndAllAndResetRendererState();
        }
        else
        {
            FUN_00b6b840();
        }
        ::FUN_0054ee60(rho);
        if (a1)
        {
            reinterpret_cast<::TaskQueueInterface *>((a1))->QueueActorDisarm(v1);
        }
        if (b2)
        {
            FUN_00b6b8d0(7, ((RenderedTexture*)(void*)group)->GetGroup());
        }
        else
        {
            ::FUN_0054ede0((::BSRenderedTexture *)(void *)((void*)group), 7);
        }
        pip = ((::fnv_0054e830::ImageSpaceEffect *)(reinterpret_cast<::FUN_004ebbc0_shell *>((((ImageSpaceManager*)((::fnv_0054e830::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270())))))->FUN_004ebbc0(0xe)));
        reinterpret_cast<::FUN_00b8c830_class *>((((ImageSpaceManager*)((::fnv_0054e830::ImageSpaceManager *)(::ImageSpaceManager::FUN_004e3270())))))->RenderWithTextures((::HolderForAccum *)(pip), (std::intptr_t)(((::fnv_0054e830::VT *)(::FUN_004a0e90()))), (::BSRenderedTexture *)(void *)((void*)p4), (::BSRenderedTexture *)(void *)((void*)group), 0, 0);
        if (b2)
        {
            ::BSRenderedTexture::EndAllAndResetRendererState();
        }
        else
        {
            FUN_00b6b840();
        }
        reinterpret_cast<::FUN_005f9af0_shell *>((pf))->SetCreatureType(l3);
        reinterpret_cast<::FUN_008a5cf0_shell *>((((Ctx*)((void *)(::FUN_00b4f5c0())))))->SetFlag86(true);
        ((::fnv_0054e830::VT *)(::FUN_004a0e90()))->v43(dst);
    }
    reinterpret_cast<::Manager *>((((::fnv_0054e830::TexMgr *)(::FUN_004a0ea0()))))->FUN_00b6da10((::Item *)(void *)((void*)p4));
    *apOutTexture = group;
    ::FUN_00b54ac0((::NiTexture *)(void *)((void*)ctx));
}
}  // namespace fnv_0054e830

namespace CellShadow {

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};

struct NiPoint2
{
    float x, y;
    NiPoint2();
};

struct ThreeByThreeMatrix
{
    float m[9];
    ThreeByThreeMatrix();
    ThreeByThreeMatrix FUN_0043f8d0(const ThreeByThreeMatrix& arOther) const;
};

struct NiFrustum
{
    float fLeft, fRight, fTop, fBottom, fNear, fFar;
    bool bOrtho;
    NiFrustum(bool abOrtho);
};

struct NiBound
{
    float fData[4];
    NiPoint3* FUN_006815c0();
};

struct NiUpdateData
{
    float fTime;
    int iFlags[2];
    NiUpdateData(float afTime, bool abUpdateControllers, bool abUpdateGeometry);
};

struct SceneObject
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void AttachChildInAvailableSlot(SceneObject* apChild, int aiFirstAvailable);
    virtual void v38();
    virtual void v39();
    virtual void InsertChild(SceneObject* apChild);

};

struct FUN_00a712f0 : SceneObject
{
    char pad04[0x110];
    FUN_00a712f0();
};

struct FUN_00a5ecb0 : SceneObject
{
    char pad04[0xa8];
    FUN_00a5ecb0(int aiChildren);
};

struct ScenePtr
{
    SceneObject* pObject;
    ScenePtr(SceneObject* apObject);
    ~ScenePtr();
    ScenePtr& operator=(SceneObject* apObject);
    ScenePtr& operator=(const ScenePtr& arOther);
    SceneObject* operator->() const;
    operator SceneObject*() const;
};

struct CullObject
{
};

struct RefObject
{
    NiPoint3* FUN_00430830();
};

struct StaticForm;

extern float DAT_0102f060;
extern float DAT_0102f05c;
extern const double DAT_0102f080;

SceneObject* __cdecl FUN_00450b80(int aiUnk);

struct Cell
{
    bool FUN_00425fd0();
    void FUN_0054f500(int aiGridX, int aiGridY, ScenePtr* apOut);
};

// @fnv 0x0054f500
void Cell::FUN_0054f500(int aiGridX, int aiGridY, ScenePtr* apOut)
{
    if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() || !((::CellShadow::SceneObject *)(reinterpret_cast<::FUN_00545cb0_shell *>(this)->FUN_00545cb0())))
    {
        *apOut = (SceneObject*)0;
        return;
    }
    SceneObject* pShadowRootEntry = FUN_00450b80(0);
    NiPoint2 kZRange;
    NiPoint3 kOrthoPos = (*reinterpret_cast<::CellShadow::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    ThreeByThreeMatrix kRotateLoc;
    reinterpret_cast<::Matrix161 *>(&(kRotateLoc))->FUN_00a59540(-::runtimeInitializationFloat1460 / ::DAT_01011590, -::runtimeInitializationFloat1460 / ::DAT_01011590, ::runtimeInitializationFloat1460 / ::DAT_01011590);
    NiFrustum kFrustumLocal(false);
    kFrustumLocal.fNear = ::DAT_01016410;
    kFrustumLocal.bOrtho = true;
    NiBound kBound = *((::CellShadow::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((((::CellShadow::SceneObject *)(reinterpret_cast<::FUN_00545cb0_shell *>(this)->FUN_00545cb0()))))->FUN_0043d450()));
    kZRange.x = ((::CellShadow::NiPoint3 *)((void *)&(kBound)))->z - reinterpret_cast<::Twin_0084d030 *>(&(kBound))->GetStoredFloatValue();
    kZRange.y = ((::CellShadow::NiPoint3 *)((void *)&(kBound)))->z + reinterpret_cast<::Twin_0084d030 *>(&(kBound))->GetStoredFloatValue();
    int iHalfSizeIn = 0x880;
    kOrthoPos.x = (float)((aiGridX << 12) + 0x1080);
    kOrthoPos.y = (float)((aiGridY << 12) + 0x1080);
    kOrthoPos.z = kZRange.y + DAT_0102f080;
    reinterpret_cast<::TESObjectCELL_Ext *>(this)->FUN_00555b10((const ::NiPoint3 &)(kOrthoPos), (::NiPoint3 &)(kOrthoPos), false);
    kFrustumLocal.fLeft = DAT_0102f060;
    kFrustumLocal.fRight = DAT_0102f05c;
    kFrustumLocal.fTop = DAT_0102f05c;
    kFrustumLocal.fBottom = DAT_0102f060;
    kFrustumLocal.fFar = kOrthoPos.z - kZRange.x + ::DAT_0102f078;
    ScenePtr spCameraTmp(new FUN_00a712f0());
    ScenePtr spNodeSample(new FUN_00a5ecb0(0));
    spNodeSample->AttachChildInAvailableSlot(spCameraTmp, 1);
    reinterpret_cast<::FUN_00440460_S *>(((spNodeSample).operator->()))->FUN_00440460((const ::V3 *)&(kOrthoPos));
    pShadowRootEntry->AttachChildInAvailableSlot(spNodeSample, 1);
    float fZRotationItem = 0.0f;
    RefObject* pMarkerTmp = ((::CellShadow::RefObject *)(reinterpret_cast<::CellRefScan *>(this)->FindFirstRefByType((std::intptr_t)((*reinterpret_cast<::CellShadow::StaticForm * *>(&::DAT_011ca254))), 1)));
    if (pMarkerTmp)
        fZRotationItem = ((::CellShadow::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((pMarkerTmp))->GetData()))->z;
    if (fZRotationItem != ::_DAT_01012060)
    {
        ThreeByThreeMatrix kZRotate = (*reinterpret_cast<::CellShadow::ThreeByThreeMatrix *>(&::DAT_011a9448));
        reinterpret_cast<::FUN_004a0c90_shell *>(&(kZRotate))->FUN_004a0c90(fZRotationItem);
        kRotateLoc = kZRotate.FUN_0043f8d0(kRotateLoc);
    }
    reinterpret_cast<::FUN_0043fa80_s *>(((spCameraTmp).operator->()))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(kRotateLoc));
    reinterpret_cast<::NiCamera *>(((spCameraTmp).operator->()))->UpdateViewFrustum((const ::NiFrustum &)(kFrustumLocal));
    NiUpdateData kNodeUpdate(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((spNodeSample).operator->()))->FUN_00a59c60((std::intptr_t)&(kNodeUpdate));
    NiUpdateData kLocalCameraUpdate(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((spCameraTmp).operator->()))->FUN_00a59c60((std::intptr_t)&(kLocalCameraUpdate));
    bool bCulled0Cur = false;
    bool bCulled1In = false;
    CullObject* pObject0Ptr = ((::CellShadow::CullObject *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(0)));
    if (pObject0Ptr)
    {
        bCulled0Cur = reinterpret_cast<::FUN_00456630_helper *>((pObject0Ptr))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((pObject0Ptr))->QueueActorDisarm(true);
    }
    CullObject* pObject1 = ((::CellShadow::CullObject *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(1)));
    if (pObject1)
    {
        bCulled1In = reinterpret_cast<::FUN_00456630_helper *>((pObject1))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((pObject1))->QueueActorDisarm(true);
    }
    CullObject* pObject6 = ((::CellShadow::CullObject *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(6)));
    CullObject* pPlayerObjectBase = ((::CellShadow::CullObject *)(::FUN_004e7ff0()));
    bool bPlayerCulled = false;
    if (pPlayerObjectBase)
    {
        bPlayerCulled = reinterpret_cast<::FUN_00456630_helper *>((pPlayerObjectBase))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((pPlayerObjectBase))->QueueActorDisarm(true);
    }
    bool bOldState = ((bool)(::FUN_0054f4b0()));
    ::FUN_004e20b0(false);
    ScenePtr spResultValue(0);
    reinterpret_cast<::fnv_0054e830::C0054e830 *>(this)->FUN_0054e830(spCameraTmp, (::fnv_0054e830::NP *)&(spResultValue));
    ::FUN_004e20b0(bOldState);
    if (pPlayerObjectBase)
        reinterpret_cast<::TaskQueueInterface *>((pPlayerObjectBase))->QueueActorDisarm(bPlayerCulled);
    if (pObject0Ptr)
        reinterpret_cast<::TaskQueueInterface *>((pObject0Ptr))->QueueActorDisarm(bCulled0Cur);
    if (pObject1)
        reinterpret_cast<::TaskQueueInterface *>((pObject1))->QueueActorDisarm(bCulled1In);
    pShadowRootEntry->InsertChild(spNodeSample);
    spNodeSample = (SceneObject*)0;
    spCameraTmp = (SceneObject*)0;
    *apOut = spResultValue;
}

}

struct Obj5548
{
    unsigned int m_uiType;
    int unk04[2];
    unsigned int m_uiKind;
};

namespace o5548 {
}


// Returns true if pkObj's type matches DAT_01187020 and its kind is 6, 8, or 9, otherwise delegates to FUN_005548a0 with the form enum index.
// @fnv 0x00554810
bool __cdecl FUN_00554810(Obj5548* pkObj)
{
    bool bResult = false;
    if (pkObj)
    {
        if (pkObj->m_uiType == ::fnv_00543df0::kGroupFormType)
        {
            switch (pkObj->m_uiKind)
            {
            case 6:
            case 8:
            case 9:
                bResult = true;
                break;
            }
        }
        else
        {
            bResult = ::FUN_005548a0(FindFormEnumIndex(pkObj->m_uiType));
        }
    }
    return bResult;
}

namespace fnv_00555c20 {
struct NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3(float fx, float fy, float afDepth);
    bool operator==(const NiPoint3& other);
};
struct NiPoint2
{
  public:
    float x;
    float y;
    NiPoint2(float fx, float fy);
};
struct CellS;
struct WorldS
{
};
struct CellS
{
    WorldS* FUN_0054ddd0();
};
struct PlayerS
{
    CellS* FUN_008d6f30();
};
struct SettingS
{
};
extern PlayerS* DAT_011dea3c;
bool FUN_00425fd0(CellS* cell);

// Snaps a copy of the player's position to the grid and, when it matches the prior value, updates lighting in the current cell and selected neighboring cells.
// @fnv 0x00555c20
void FUN_00555c20()
{
    static NiPoint3 lastPos(::DAT_01016970, ::DAT_01016970, ::DAT_01016970);
    if (DAT_011dea3c)
    {
        NiPoint3 pos2 = *((::fnv_00555c20::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((DAT_011dea3c))->GetAddTopicList()));
        ::SnapToGridCell((::NiPoint3 &)(pos2));
        if (reinterpret_cast<::NiPlane *>((void *)&(const ::fnv_00555c20::NiPoint3 &)(pos2))->operator==((const ::NiPlane &)(lastPos)))
        {
            lastPos = pos2;
            CellS* cellB = ((::fnv_00555c20::CellS *)(reinterpret_cast<::LowProcess *>((DAT_011dea3c))->GetTarget()));
            if (cellB)
            {
                if (!reinterpret_cast<::TESObjectCELL *>((cellB))->IsCellInterior())
                {
                    CellS* cells9[4];
                    memset(cells9, 0, 16);
                    cells9[0] = cellB;
                    WorldS* world = ((::fnv_00555c20::WorldS *)(reinterpret_cast<::TESObjectCELL *>((cellB))->GetParentWorldSpace()));
                    if (world)
                    {
                        int cellX = ::FUN_00406d90(pos2.x) >> 12;
                        int cellY3 = ::FUN_00406d90(pos2.y) >> 12;
                        NiPoint2 lowPt2((float)(cellX << 12), (float)(cellY3 << 12));
                        NiPoint2 highPt5((float)((cellX << 12) + 4096.0), (float)((cellY3 << 12) + 4096.0));
                        int dxTmp = 0;
                        int dy4 = 0;
                        if (lowPt2.x >= pos2.x - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00555c20::SettingS *>(&::originalRuntimeFloatSetting37)))))))
                        {
                            dxTmp = -1;
                        }
                        else if (pos2.x + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00555c20::SettingS *>(&::originalRuntimeFloatSetting37)))))) >= highPt5.x)
                        {
                            dxTmp = 1;
                        }
                        if (lowPt2.y >= pos2.y - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00555c20::SettingS *>(&::originalRuntimeFloatSetting37)))))))
                        {
                            dy4 = -1;
                        }
                        else if (pos2.y + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00555c20::SettingS *>(&::originalRuntimeFloatSetting37)))))) >= highPt5.y)
                        {
                            dy4 = 1;
                        }
                        int count3 = 1;
                        if (dxTmp != 0)
                        {
                            cells9[count3++] = ((::fnv_00555c20::CellS *)(reinterpret_cast<::TESWorldSpace *>((world))->GetCellAtGridPosition(cellX + dxTmp, cellY3)));
                        }
                        if (dy4 != 0)
                        {
                            cells9[count3++] = ((::fnv_00555c20::CellS *)(reinterpret_cast<::TESWorldSpace *>((world))->GetCellAtGridPosition(cellX, cellY3 + dy4)));
                        }
                        if (dxTmp != 0 && dy4 != 0)
                        {
                            cells9[count3++] = ((::fnv_00555c20::CellS *)(reinterpret_cast<::TESWorldSpace *>((world))->GetCellAtGridPosition(cellX + dxTmp, cellY3 + dy4)));
                        }
                    }
                    for (int i2 = 0; i2 < 4; i2++)
                    {
                        if (cells9[i2] != 0)
                        {
                            reinterpret_cast<::CellLighting::Cell *>((cells9[i2]))->UpdateLightingAtPoint((const ::CellLighting::Vec3 *)(::fnv_00555c20::NiPoint3 *)(&pos2));
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    reinterpret_cast<::CellLighting::Cell *>((cellB))->UpdateLightingAtPoint((const ::CellLighting::Vec3 *)(::fnv_00555c20::NiPoint3 *)(&pos2));
                }
            }
        }
    }
}
}  // namespace fnv_00555c20

struct FUN_0042f830
{
    ~FUN_0042f830();
};
struct FUN_00541a60 : FUN_0042f830
{
    ~FUN_00541a60();
};
// Calls FUN_00541a60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00541a30
void* FUN_00541a30_StandIn::FUN_00541a30(unsigned int flags)
{
    reinterpret_cast<::FUN_00541a60 *>(this)->::FUN_00541a60::~FUN_00541a60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Calls FUN_0069bca0; the base class destructor runs after this destructor body.
// @fnv 0x00541a60
FUN_00541a60::~FUN_00541a60()
{
    reinterpret_cast<::FUN_0069bca0_class *>(this)->FUN_0069bca0();
}

namespace s5447b0 {

struct Color
{
    float r;
    float g;
    float b;
};

struct Owner
{
    void FUN_005447b0(Color* pkColor);
};

// Splits the value from GetCellNode into three low-order bytes and stores them as normalized r, g, and b values.
// @fnv 0x005447b0
void Owner::FUN_005447b0(Color* pkColor)
{
    unsigned int uiPackedColor = ((unsigned int)(std::uintptr_t)(::GetCellNode((::TESObjectCELL *)this)));
    pkColor->r = (unsigned char)(uiPackedColor & 0xff) / 255.0;
    pkColor->g = (unsigned char)(((unsigned short)uiPackedColor >> 8) & 0xff) / 255.0;
    pkColor->b = (unsigned char)((uiPackedColor >> 16) & 0xff) / 255.0;
}

}

namespace fnv_005453b0 {
struct FNV_Ref;
struct FNV_Form;
struct FNV_Node;
struct FNV_Sub;
struct FNV_Render;
struct FNV_Flags;
struct NiPoint3;
struct ThreeByThreeMatrix;
struct FNV_Target;
struct FNV_Form
{
    int FUN_00401170();
    bool FUN_00549580();
    bool FUN_00549630();
};
struct FNV_Node
{
    FNV_Node* FUN_00586170(FNV_Ref*, int);
    FNV_Node* FUN_00586170(int);
    void FUN_006fcfa0();
    void FUN_00929260();
    FNV_Flags* FUN_00a5bdd0(void*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual unsigned int v_c();
    virtual FNV_Render* v10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void vdc(void*);
};
struct FNV_Ref
{
    void* FUN_0043fcd0();
    void* FUN_00575d70();
    FNV_Sub* FUN_005d43c0();
    NiPoint3* FUN_00430830();
    int FUN_005699b0();
    bool FUN_004077c0();
    bool FUN_00444ed0();
    bool FUN_005694c0();
    bool FUN_00564e60();
    bool FUN_00564f00();
    ThreeByThreeMatrix FUN_0056fa00();
    FNV_Render* FUN_008d6f30();
    unsigned int FUN_0084e3a0();
    void* FUN_00950bb0(int, int);
    FNV_Render* FUN_00950bb0(int);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual bool v100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual void v_130();
    virtual void v_134();
    virtual void v_138();
    virtual void v_13c();
    virtual void v_140();
    virtual void v_144();
    virtual void v_148();
    virtual void v_14c();
    virtual void v_150();
    virtual void v_154();
    virtual void v_158();
    virtual void v_15c();
    virtual void v_160();
    virtual void v_164();
    virtual void v_168();
    virtual void v_16c();
    virtual void v_170();
    virtual void v_174();
    virtual void v_178();
    virtual void v_17c();
    virtual void v_180();
    virtual void v_184();
    virtual void v_188();
    virtual void v_18c();
    virtual void v_190();
    virtual void v_194();
    virtual void v_198();
    virtual void v_19c();
    virtual void v_1a0();
    virtual void v_1a4();
    virtual void v_1a8();
    virtual void v_1ac();
    virtual void* v1b0(int, int);
    virtual void v_1b4();
    virtual void v_1b8();
    virtual void v_1bc();
    virtual void v_1c0();
    virtual void v_1c4();
    virtual void v_1c8();
    virtual void v_1cc();
    virtual FNV_Node* v1d0();
    virtual void v_1d4();
    virtual void v_1d8();
    virtual void v_1dc();
    virtual void v_1e0();
    virtual void v_1e4();
    virtual void v_1e8();
    virtual void v_1ec();
    virtual void v_1f0();
    virtual void* v1f4();
    virtual void v_1f8();
    virtual void v_1fc();
    virtual void v_200();
    virtual void v_204();
    virtual void v_208();
    virtual void v_20c();
    virtual void v_210();
    virtual void v_214();
    virtual void v_218();
    virtual void v_21c();
    virtual void v_220();
    virtual bool v224();
};
struct FNV_Target
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual FNV_Node* v_c0();
};
struct FNV_Map
{
    int table;
    int size;
    int count;
    int extra;
};
struct FNV_Registration
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FNV_Map others;
    FNV_Map doors;
};
struct CellOffsets
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
    short unkA8;
    short unkAA;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    FNV_Registration* unkc4;
    float unkC8;
    short unkCC;
    char unkCE;
    char unkCF;
    char unkD0;
    void FUN_005453b0(FNV_Ref* reference);
};

extern FNV_Ref* DAT_011dea3c;

// Registers a reference in the cell's door or other maps, copying material properties and setting property values when the reference is not a door.
// @fnv 0x005453b0
void CellOffsets::FUN_005453b0(FNV_Ref* reference)
{
    if (!unkc4 || !reference || !reference->v1d0())
        return;
    FNV_Node* object = reference->v1d0();
    if (((::fnv_005453b0::FNV_Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170() == 0x1e)
    {
        reinterpret_cast<::FUN_00844700_Class *>(&(unkc4->doors))->FUN_00844700((std::uintptr_t)reference, object->v_c());
    }
    else
    {
        ::CopyMaterialPropertyRecursive((::Walker *)(object));
        reinterpret_cast<::FUN_00a5a040_Class *>((object))->FUN_00a5a040();
        FNV_Target* target = ((::fnv_005453b0::FNV_Target *)(reinterpret_cast<::FUN_00569580_shell *>((reference))->GetOwnerForm()));
        if (!target)
            target = ((::fnv_005453b0::FNV_Target *)(reinterpret_cast<::TESObjectCELL *>((DAT_011dea3c))->FUN_005454d0()));
        if (target)
        {
            FNV_Node* node = target->v_c0();
            if (node)
            {
                void* property = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(2)));
                ::SetPropertyValueRecursive((::B55480AVObject *)(object), (int)(node));
                reinterpret_cast<::FUN_00844700_Class *>(&(unkc4->others))->FUN_00844700((std::uintptr_t)target, (std::uintptr_t)reference);
            }
        }
    }
}
}  // namespace fnv_005453b0


struct FormX
{
};
struct ItemX
{
};
struct NodeX
{
    ItemX** FUN_006815c0();
};
struct ListArg
{
    void FUN_005ae3d0(ItemX** pp);
};
struct FUN_0054b830_cls
{
    void FUN_0054b830(ListArg* pOut);
};

// For each item whose form matches DAT_011ca224 and whose map pointer is non-null, passes its address to pOut->FUN_005ae3d0.
// @fnv 0x0054b830
void FUN_0054b830_cls::FUN_0054b830(ListArg* pOut)
{
    if (pOut != 0)
    {
        reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
        NodeX* pNode = ((::NodeX *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (pNode != 0)
        {
            ItemX* pItem = *((::ItemX **)((void *)(pNode)));
            if (pItem != 0)
            {
                if (((::FormX *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pItem))->FUN_007af430())) == (*reinterpret_cast<void * *>(&::DAT_011ca224)))
                {
                    void* pMap = ((void *)(reinterpret_cast<::FUN_00569060_shell *>((pItem))->FUN_00569060()));
                    if (pMap != 0)
                    {
                        pOut->FUN_005ae3d0(&pItem);
                    }
                }
            }
            pNode = ((::NodeX *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)this);
    }
}

namespace s54ba00 {

class Actor
{
};

struct Node
{
    Actor** FUN_006815c0();
};

struct Owner
{
    void FUN_0054ba00();
};

// Iterates linked nodes, and for each actor that passes FUN_0057a2f0, calls FUN_00579ac0 with the result of FUN_0057a370.
// @fnv 0x0054ba00
void Owner::FUN_0054ba00()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    Node* pkNode = ((::s54ba00::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pkNode)
    {
        Actor* pkActor = *((::s54ba00::Actor **)((void *)(pkNode)));
        pkNode = ((::s54ba00::Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        if (pkActor && reinterpret_cast<::FUN_0057a2f0_shell *>((pkActor))->FUN_0057a2f0())
            reinterpret_cast<::RefObj *>((pkActor))->FUN_00579ac0(reinterpret_cast<::FUN_0057a370_shell *>((pkActor))->FUN_0057a370());
    }
    ::FUN_00541ae0((char *)this);
}

}

namespace s54ba80 {

class Actor
{
};

struct Node
{
    Actor** FUN_006815c0();
};

struct Owner
{
    void FUN_0054ba80(bool bEnable);
};

// Iterates the node list and calls FUN_005728c0 or FUN_005729e0 on each non-null actor depending on bEnable.
// @fnv 0x0054ba80
void Owner::FUN_0054ba80(bool bEnable)
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    Node* pkNode = ((::s54ba80::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pkNode)
    {
        Actor* pkActor = *((::s54ba80::Actor **)((void *)(pkNode)));
        pkNode = ((::s54ba80::Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        if (pkActor)
        {
            if (bEnable)
                reinterpret_cast<::fnv_005728c0::FUN_005728c0_shell *>((pkActor))->FUN_005728c0(0);
            else
                reinterpret_cast<::B5729E0Ref *>((pkActor))->FUN_005729e0(0);
        }
    }
    ::FUN_00541ae0((char *)this);
}

}

namespace s54baf0 {

struct Package;

struct Form
{
    int FUN_00401170();
};

struct Process
{
};

class Actor
{
  public:
    Process* FUN_005d43c0();
};

struct Node
{
    Actor** FUN_006815c0();
};

struct Owner
{
    void FUN_0054baf0();
};

// For actors whose form type is 0x1e, obtains a package and, when non-null, passes it with 0 to FUN_0050de20.
// @fnv 0x0054baf0
void Owner::FUN_0054baf0()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    Node* pkNode = ((::s54baf0::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pkNode)
    {
        Actor* pkActor = *((::s54baf0::Actor **)((void *)(pkNode)));
        pkNode = ((::s54baf0::Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        if (pkActor)
        {
            switch (((::s54baf0::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkActor))->FUN_007af430()))->FUN_00401170())
            {
            case 0x1e:
                Package* pkPackage = ((::s54baf0::Package *)(reinterpret_cast<::Holder *>((((::s54baf0::Process *)(reinterpret_cast<::FUN_005d43c0_ *>((pkActor))->FUN_005d43c0()))))->FUN_00418250()));
                if (pkPackage)
                    reinterpret_cast<::S_0050de20_Class *>((((::s54baf0::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkActor))->FUN_007af430()))))->FUN_0050de20((::S_0050de20_A *)(pkPackage), 0);
            }
        }
    }
    ::FUN_00541ae0((char *)this);
}

}

namespace s54cee0 {

struct Entry
{
    int* FUN_006815c0();
};

struct Owner
{
    int FUN_0054cee0();
};

// Calls FUN_00541ac0, reads the int returned through the entry's FUN_006815c0 pointer, then calls FUN_00541ae0 and returns it.
// @fnv 0x0054cee0
int Owner::FUN_0054cee0()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    int iResult = *((int *)((void *)(((::s54cee0::Entry *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0())))));
    ::FUN_00541ae0((char *)this);
    return iResult;
}

}

namespace s54da20 {

struct Position
{
};


class Actor
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual Position* GetPosition();
};

struct Node
{
    bool FUN_008256d0();
    Actor** FUN_006815c0();
};

typedef bool (*ActorCallback)(Actor* pkActor, void* pvContext);

struct Owner
{
    bool FUN_0054da20(Position* pkCenter1, float fRadius1, Position* pkCenter2, float fRadius2,
                      ActorCallback pfnCallback, void* pvContext);
};

// Iterates actors in the owner's node list, calling pfnCallback for those within both spheres, stopping early if the callback returns true.
// @fnv 0x0054da20
bool Owner::FUN_0054da20(Position* pkCenter1, float fRadius1, Position* pkCenter2, float fRadius2,
                         ActorCallback pfnCallback, void* pvContext)
{
    if (!pfnCallback)
        return false;
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    Node* pkNode = ((::s54da20::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pkNode && !pkNode->FUN_008256d0())
    {
        Actor* pkActor = *((::s54da20::Actor **)((void *)(pkNode)));
        pkNode = ((::s54da20::Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        if (fRadius1 == 3.402823466e+38F || ((int)(::FUN_004b5440((*(const ::NiPoint3 *)(pkActor->GetPosition())), (*(const ::NiPoint3 *)(pkCenter1)), fRadius1))) < 0)
        {
            if (fRadius2 == 3.402823466e+38F || (fRadius1 == fRadius2 && reinterpret_cast<::NiPoint3 *>((pkCenter1))->FUN_004390c0((*(const ::NiPoint3 *)(pkCenter2)))) ||
                ((int)(::FUN_004b5440((*(const ::NiPoint3 *)(pkActor->GetPosition())), (*(const ::NiPoint3 *)(pkCenter2)), fRadius2))) < 0)
            {
                if (pfnCallback(pkActor, pvContext))
                {
                    ::FUN_00541ae0((char *)this);
                    return false;
                }
            }
        }
    }
    ::FUN_00541ae0((char *)this);
    return true;
}

}

namespace fnv_0054db50 {

struct FormX
{
    int FUN_00401170();
};
struct ItemX
{
};
struct NodeX
{
    ItemX** FUN_006815c0();
};
struct ListArg
{
};
struct FUN_0054db50_cls
{
    void FUN_0054db50(ListArg* pOut);
};

// Iterates a linked list of ItemX nodes, filtering by form type 0x1c and a flag, and appends matching items to pOut.
// @fnv 0x0054db50
void FUN_0054db50_cls::FUN_0054db50(ListArg* pOut)
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    NodeX* pNode = ((::fnv_0054db50::NodeX *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pNode != 0)
    {
        ItemX* pItem = *((::fnv_0054db50::ItemX **)((void *)(pNode)));
        if (pItem != 0)
        {
            if (!reinterpret_cast<::TESForm *>((pItem))->GetDisabled())
            {
                if (!reinterpret_cast<::FUN_00440d80_shell *>((pItem))->FUN_00440d80())
                {
                    FormX* pForm = ((::fnv_0054db50::FormX *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pItem))->FUN_007af430()));
                    if (pForm->FUN_00401170() == 0x1c)
                    {
                        if (pForm != (*reinterpret_cast<void * *>(&::DAT_011ca258)))
                        {
                            if (((std::uintptr_t)(reinterpret_cast<::TESObjectREFR *>((pItem))->GetExtraRadioData())))
                            {
                                reinterpret_cast<::FUN_00438690 *>((pOut))->FUN_007cb2e0((unsigned int *)(::fnv_0054db50::ItemX **)(&pItem));
                            }
                        }
                    }
                }
            }
        }
        pNode = ((::fnv_0054db50::NodeX *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_0054db50

class bhkFilter
{
  public:
    int m_type;
    int GetType();
};

class bhkWorldObject
{
  public:
    bhkFilter GetFilter();
};

class bhkWorld
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAc();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBc();
    virtual void vC0();
    virtual void vC4();
    virtual bool FUN_00c8(TESObjectREFR* refr);
public:
    void FUN_00c68a00(bool);
};
// @fnv 0x00553700
void FUN_00553700_shell::UpdateCell()
{
    if (reinterpret_cast<::TESObjectCELL *>((this))->IsCellInterior())
    {
        CellWorld553* pkWorld = ((::CellWorld553 *)(reinterpret_cast<::FUN_004543c0_cls *>((this))->FUN_004543c0()));
        if (pkWorld)
        {
            reinterpret_cast<::FUN_00454380_Class *>((pkWorld))->FUN_00454380(false);
            reinterpret_cast<::Root *>((pkWorld))->SetProcessEnabled(false);
            if (((::CellCaster553 *)(reinterpret_cast<::FUN_0045cd60_shell *>((pkWorld))->FUN_0045cd60())))
            {
                CellCaster553* pkCaster = ((::CellCaster553 *)(reinterpret_cast<::FUN_0045cd60_shell *>((pkWorld))->FUN_0045cd60()));
                reinterpret_cast<::FUN_0061f8e0_shell *>((pkCaster))->FUN_0061f8e0(true);
                reinterpret_cast<::FUN_004893c0_class *>((pkCaster))->FUN_004893c0(false);
            }
        }
    }
    else
    {
        CellMopp553* pMopp = ((::CellMopp553 *)(::GetCellMopp((char *)(::FUN_00553700_shell *)(this))));
        if (pMopp)
            reinterpret_cast<::CellMopp_00621e80 *>((pMopp))->FUN_00621e80();
        CellRefLockEnter();
        CellRefNode553* pkNodeCur = ((::CellRefNode553 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (pkNodeCur)
        {
            CellRef553* pkRef = ((::CellRef553 *)((void *)(pkNodeCur)));
            pkNodeCur = ((::CellRefNode553 *)(reinterpret_cast<::Callees *>((pkNodeCur))->FUN_00726070()));
            if (pkRef)
                pkRef->Update3D();
        }
        CellWorld553* pkCellWorld3 = ((::CellWorld553 *)(reinterpret_cast<::FUN_004543c0_cls *>((this))->FUN_004543c0()));
        if (pkCellWorld3)
        {
            CellCaster553* pkWorldCaster = ((::CellCaster553 *)(reinterpret_cast<::FUN_0045cd60_shell *>((pkCellWorld3))->FUN_0045cd60()));
            reinterpret_cast<::FUN_004893c0_class *>((pkWorldCaster))->FUN_004893c0(false);
        }
        if (((bool)(reinterpret_cast<::FUN_00552da0_class *>((DAT_011de134))->GetUnk26())))
            reinterpret_cast<::bhkWorld *>((pkCellWorld3))->FUN_00c68a00(false);
        ::FUN_00541ae0((char *)this);
    }
}

class CellBhk
{
  public:
};

class RefrThing
{
  public:
};


struct FUN_00553ee0_shell
{
    void* FUN_00553ee0(TESObjectREFR* refr);
};

// If the cell's bhkWorld contains refr and its object's filter type is 0x11, returns the cell's NiNode; otherwise returns null or FUN_00c66fb0's result.
// @fnv 0x00553ee0
void* FUN_00553ee0_shell::FUN_00553ee0(TESObjectREFR* refr)
{
    bhkWorld* world = ((::bhkWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((CellBhk*)this)))->FUN_004543c0()));

    if (world)
    {
        if (world->FUN_00c8(refr))
        {
            std::intptr_t value7 = ((std::intptr_t)(::FUN_00c66fd0((::BhkPickData *)(((RefrThing*)refr)))));
            bhkWorldObject* object = (bhkWorldObject*)::FUN_004b5a80((const void *)(value7));

            if (object && reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::bhkFilter &)(object->GetFilter()))->FUN_0043b4d0() == 0x11)
                return reinterpret_cast<::FUN_00545cb0_shell *>((((CellBhk*)this)))->FUN_00545cb0();

            return reinterpret_cast<::FUN_00c66fb0_Class *>((((RefrThing*)refr)))->FUN_00c66fb0();
        }
    }
    return 0;
}

namespace s5573e0 {

class Process
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int IsActive();

    void FUN_00476ab0();
};


class Actor
{
  public:
    Process* FUN_0043fcd0();
};

struct Node
{
    Actor** FUN_006815c0();
};

struct Owner
{
    void FUN_005573e0();
};

// Visits each node's actor and, when its process is active, calls FUN_00476ab0 and FUN_00b6bb30 with 1.0f.
// @fnv 0x005573e0
void Owner::FUN_005573e0()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    Node* pkNode = ((::s5573e0::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (pkNode)
    {
        Actor* pkActor = *((::s5573e0::Actor **)((void *)(pkNode)));
        if (pkActor)
        {
            Process* pkProcess = ((::s5573e0::Process *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((pkActor))->FUN_0043fcd0()));
            if (pkProcess && pkProcess->IsActive())
            {
                Process* pkHigh = pkProcess;
                pkHigh->FUN_00476ab0();
                ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(pkHigh), 1.0f);
            }
        }
        pkNode = ((::s5573e0::Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}

}

namespace fnv_005577b0 {
struct FNV_Node;
struct FNV_Node
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual TESObjectREFR* v_c();
};
struct FNV_Ref
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual bool v100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual void v_130();
    virtual void v_134();
    virtual void v_138();
    virtual void v_13c();
    virtual void v_140();
    virtual void v_144();
    virtual void v_148();
    virtual void v_14c();
    virtual void v_150();
    virtual void v_154();
    virtual void v_158();
    virtual void v_15c();
    virtual void v_160();
    virtual void v_164();
    virtual void v_168();
    virtual void v_16c();
    virtual void v_170();
    virtual void v_174();
    virtual void v_178();
    virtual void v_17c();
    virtual void v_180();
    virtual void v_184();
    virtual void v_188();
    virtual void v_18c();
    virtual void v_190();
    virtual void v_194();
    virtual void v_198();
    virtual void v_19c();
    virtual void v_1a0();
    virtual void v_1a4();
    virtual void v_1a8();
    virtual void v_1ac();
    virtual void* v1b0(int, int);
    virtual void v_1b4();
    virtual void v_1b8();
    virtual void v_1bc();
    virtual void v_1c0();
    virtual void v_1c4();
    virtual void v_1c8();
    virtual void v_1cc();
    virtual FNV_Node* v1d0();
    virtual void v_1d4();
    virtual void v_1d8();
    virtual void v_1dc();
    virtual void v_1e0();
    virtual void v_1e4();
    virtual void v_1e8();
    virtual void v_1ec();
    virtual void v_1f0();
    virtual void* v1f4();
    virtual void v_1f8();
    virtual void v_1fc();
    virtual void v_200();
    virtual void v_204();
    virtual void v_208();
    virtual void v_20c();
    virtual void v_210();
    virtual void v_214();
    virtual void v_218();
    virtual void v_21c();
    virtual void v_220();
    virtual bool v224();
};
struct RefNode
{
    FNV_Ref** FUN_006815c0();
};
struct FNV_Cell : TESObjectCELL
{
    void FUN_005577b0(bool);
};

// Iterates the cell's reference list and calls FUN_00578060 or FUN_00578170 on each valid reference's node based on the enable flag.
// @fnv 0x005577b0
void FNV_Cell::FUN_005577b0(bool enable)
{
    CellRefLockEnter();
    if (enable)
    {
        RefNode* node = ((::fnv_005577b0::RefNode *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (node)
        {
            FNV_Ref* reference = *((::fnv_005577b0::FNV_Ref **)((void *)(node)));
            node = ((::fnv_005577b0::RefNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            if (reference && reinterpret_cast<::Holder4523e0 *>((reference))->FUN_004523e0(2) && reference->v1d0())
            {
                ::FUN_00578060((::NodeView *)(::TESObjectREFR *)(reference->v1d0()->v_c()));
            }
        }
    }
    else
    {
        RefNode* node2 = ((::fnv_005577b0::RefNode *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (node2)
        {
            FNV_Ref* reference2 = *((::fnv_005577b0::FNV_Ref **)((void *)(node2)));
            node2 = ((::fnv_005577b0::RefNode *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070()));
            if (reference2 && reinterpret_cast<::Holder4523e0 *>((reference2))->FUN_004523e0(2) && reference2->v1d0())
            {
                ::fnv_00578170::FUN_00578170((::NiNode *)(::TESObjectREFR *)(reference2->v1d0()->v_c()));
            }
        }
    }
    ::FUN_00541ae0((char *)this);
}
}  // namespace fnv_005577b0

namespace fnv_0054abd0 {
struct CountingSemaphore
{
    int a, b, c;
};
struct FUN_0054ad60 : CountingSemaphore
{
    FUN_0054ad60(int);
    ~FUN_0054ad60();
};
namespace N {
class TESObjectREFR
{
};
}
struct GO
{
    void* p;
    void operator=(void*);
};
struct FUN_0054acf0
{
    GO spChild;
    GO m_pParent;
    int iFlags;
    FUN_0054acf0();
    ~FUN_0054acf0();
};
struct FUN_0054adb0
{
    GO spChild;
    GO m_pParent;
    int iFlags;
    FUN_0054adb0(const FUN_0054acf0&);
    ~FUN_0054adb0();
};
struct MapH
{
};
// Records or removes the parent node for a reference's NiAVObject in g_011ca0f4 under a counting semaphore.
// @fnv 0x0054abd0
void __cdecl FUN_0054abd0(TESObjectREFR* apRef, NiNode* apParent)
{
    if (!apRef || !((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((N::TESObjectREFR*)apRef)))->FUN_0043fcd0())))
        return;
    static FUN_0054ad60 kLock(1);
    reinterpret_cast<::SemaphoreWaitReceiver *>(&(kLock))->FUN_004424e0();
    NiAVObject* pnewchild = ((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((N::TESObjectREFR*)apRef)))->FUN_0043fcd0()));
    if (((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((pnewchild))->FUN_009611e0())) == apParent)
    {
        reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::fnv_0054abd0::MapH *>(&::g_011ca0f4))))->RemoveKey((std::uintptr_t)pnewchild);
    }
    else
    {
        FUN_0054acf0 attachdata;
        attachdata.m_pParent = apParent;
        attachdata.spChild = pnewchild;
        reinterpret_cast<::ObstacleMap *>(&((*reinterpret_cast<::fnv_0054abd0::MapH *>(&::g_011ca0f4))))->SetOrInsertValue((std::uintptr_t)(pnewchild), (*(::ObstacleMapValue *)&(const ::fnv_0054abd0::FUN_0054adb0 &)(attachdata)));
    }
    reinterpret_cast<::FUN_00442550_shell *>(&(kLock))->ReleaseAndInitScriptRunLock();
}
}  // namespace fnv_0054abd0

#include <float.h>
struct PortalVisitPoint
{
    float x, y, z;
    PortalVisitPoint();
};
struct PortalVisitCell;
struct PortalVisitRef;
typedef bool(__cdecl* PortalVisitCallback)(PortalVisitRef*, void*);
struct PortalVisitWorld
{
    void ProcessCellsInRadius(const PortalVisitPoint&, float, const PortalVisitPoint&, float, PortalVisitCallback,
                              void*);
};
struct PortalVisitForm
{
    int FUN_00401170();
};
struct PortalVisitDoor
{
};
struct PortalVisitRef
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
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
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual PortalVisitPoint& GetPosition();
};
struct PortalVisitItem
{
    PortalVisitRef*& FUN_006815c0();
};
struct PortalVisitCell
{
    bool FUN_00425fd0();
};
struct PortalVisitList
{
    void* head;
    void* tail;
    unsigned count;
    PortalVisitList();
    ~PortalVisitList();
    int FUN_0049c680(PortalVisitCell* const&, int);
};
extern float portalVisitRemaining;
// Recursively visits refs in a cell within two radii, invoking callback and following doors to process linked cells.
// @fnv 0x0054d4b0
bool __cdecl FUN_0054d4b0(PortalVisitCell* cell, const PortalVisitPoint& origin, float range,
                          const PortalVisitPoint& other, float otherRange, PortalVisitCallback callback, void* context)
{
    if (cell)
        reinterpret_cast<::TESObjectCELL *>((cell))->CellRefLockEnter();
    static PortalVisitList visited;
    static PortalVisitPoint nearestPosition;
    static int depth = 0;
    static PortalVisitWorld* nearestWorld = 0;
    bool stop4 = false;
    if (!depth)
    {
        nearestPosition = (*reinterpret_cast<::PortalVisitPoint *>((void *)&::NiPoint3::ZERO));
        nearestWorld = 0;
        portalVisitRemaining = FLT_MAX;
    }
    if (cell && callback)
    {
        ++depth;
        reinterpret_cast<::FUN_005597d0_shell *>(&(visited))->FUN_005597d0((int *)&(reinterpret_cast<void*&>(cell)));
        PortalVisitList deferred;
        PortalVisitItem* item3 = ((::PortalVisitItem *)(reinterpret_cast<::FUN_009604f0_shell *>((cell))->FUN_009604f0()));
        while (item3 && !stop4)
        {
            PortalVisitRef* ref = ((::PortalVisitRef *)((void *)(item3)));
            item3 = ((::PortalVisitItem *)(reinterpret_cast<::Callees *>((item3))->FUN_00726070()));
            if (ref)
            {
                if (range == double(FLT_MAX) || ((int)(::FUN_004b5440((const ::NiPoint3 &)(ref->GetPosition()), (const ::NiPoint3 &)(origin), range))) < 0)
                {
                    if (otherRange == double(FLT_MAX) || (range == otherRange && reinterpret_cast<::NiPoint3 *>((void *)&(origin))->FUN_004390c0((const ::NiPoint3 &)(other))) ||
                        ((int)(::FUN_004b5440((const ::NiPoint3 &)(ref->GetPosition()), (const ::NiPoint3 &)(other), otherRange))) < 0)
                    {
                        if (callback(ref, context))
                            stop4 = true;
                        if (((::PortalVisitForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FUN_00401170() == 28 && ((::PortalVisitForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) != (*reinterpret_cast<::PortalVisitForm * *>(&::DAT_011ca258)))
                        {
                            PortalVisitDoor* door = ((::PortalVisitDoor *)(reinterpret_cast<::TESObjectREFR *>((ref))->GetExtraRadioData()));
                            if (door)
                            {
                                PortalVisitWorld* world = ((::PortalVisitWorld *)(reinterpret_cast<::TeleportableReference *>((door))->GetTeleportWorldspace()));
                                PortalVisitCell* target2 = ((::PortalVisitCell *)(reinterpret_cast<::TeleportableReference *>((door))->FUN_0043a2b0()));
                                if (target2 && !reinterpret_cast<::TESObjectCELL *>((target2))->IsCellInterior())
                                    target2 = 0;
                                if (world)
                                {
                                    float remaining = FLT_MAX;
                                    if (range != double(FLT_MAX))
                                    {
                                        float distance = range - reinterpret_cast<::fnv_00572380::Fn572380 *>((ref))->FUN_00572380((::fnv_00572380::NiP3Sub *)&(origin));
                                        if (distance < remaining)
                                            remaining = distance;
                                    }
                                    if (otherRange != double(FLT_MAX) && otherRange != range)
                                    {
                                        float distance = otherRange - reinterpret_cast<::fnv_00572380::Fn572380 *>((ref))->FUN_00572380((::fnv_00572380::NiP3Sub *)&(other));
                                        if (distance < remaining)
                                            remaining = distance;
                                    }
                                    if (!nearestWorld || remaining > portalVisitRemaining)
                                    {
                                        portalVisitRemaining = remaining;
                                        nearestPosition = (*(::PortalVisitPoint *)(reinterpret_cast<::BaseProcess *>((door))->GetCurrentProcessData()));
                                        nearestWorld = world;
                                    }
                                }
                                else if (target2 && !visited.FUN_0049c680(target2, 0))
                                    reinterpret_cast<::FUN_005597d0_shell *>(&(deferred))->FUN_005597d0((int *)&(reinterpret_cast<void*&>(ref)));
                            }
                        }
                    }
                }
            }
        }
        void* cursor3 = ((void *)(::FUN_00559450((int *)&(deferred))));
        while (cursor3 && !stop4)
        {
            PortalVisitRef* ref = ((::PortalVisitRef *)(reinterpret_cast<::ListStandIn *>(&(deferred))->FUN_0057cbe0((int **)&(cursor3))));
            if (ref)
            {
                float remaining = FLT_MAX;
                if (range != double(FLT_MAX))
                {
                    float distance = range - reinterpret_cast<::fnv_00572380::Fn572380 *>((ref))->FUN_00572380((::fnv_00572380::NiP3Sub *)&(origin));
                    if (distance < remaining)
                        remaining = distance;
                }
                if (otherRange != double(FLT_MAX) && otherRange != range)
                {
                    float distance = otherRange - reinterpret_cast<::fnv_00572380::Fn572380 *>((ref))->FUN_00572380((::fnv_00572380::NiP3Sub *)&(other));
                    if (distance < remaining)
                        remaining = distance;
                }
                PortalVisitDoor* door = ((::PortalVisitDoor *)(reinterpret_cast<::TESObjectREFR *>((ref))->GetExtraRadioData()));
                if (!FUN_0054d4b0(((::PortalVisitCell *)(reinterpret_cast<::TeleportableReference *>((door))->FUN_0043a2b0())), (*(::PortalVisitPoint *)(reinterpret_cast<::BaseProcess *>((door))->GetCurrentProcessData())), remaining, other, FLT_MAX, callback,
                                  context))
                    stop4 = true;
            }
        }
        --depth;
    }
    if (!depth)
    {
        reinterpret_cast<::NiTPointerListBaseRaw *>(&(visited))->FUN_00559c30();
        if (!stop4 && nearestWorld)
        {
            nearestWorld->ProcessCellsInRadius(nearestPosition, portalVisitRemaining, other, FLT_MAX, callback,
                                               context);
            stop4 = true;
        }
    }
    if (cell)
        ::FUN_00541ae0((char *)(cell));
    return !stop4;
}

namespace fnv_00552dc0 {
void* __cdecl FUN_00aa13e0(unsigned int);
struct ChildGeometryBase;


using ScopedCellOperation = ::AutoMemContext;
struct FourFloatVector
{
    float x, y, z, w;
    FourFloatVector(float, float, float, float);
};
struct Rotation
{
    float matrix[16];
    float homogeneous;
};
struct __declspec(align(16)) SceneInitializer
{
    SceneInitializer();
    ~SceneInitializer();
    unsigned int state00, state04, state08, state0c;
    Rotation rotation;
    float scale;
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
    char unk88[8];
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
};
struct SpatialNode
{
    void FUN_00454380(bool bValue);
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
    static void* operator new(std::size_t);
    static void operator delete(void*);
    SpatialNode(SceneInitializer*);
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0c();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1c();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2c();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3c();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4c();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5c();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6c();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7c();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8c();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9c();
    virtual void Va0();
    virtual void Va4();
    virtual void Va8();
    virtual void Vac();
    virtual void Vb0();
    virtual void Vb4();
    virtual void Vb8();
    virtual void Vbc();
    virtual void Vc0();
    virtual void Vc4();
};
struct ChildGeometryHead
{
    int unk00;
    int unk04;
};
struct ChildGeometryBase
{
    int unk08;
};
struct ChildGeometry : ChildGeometryHead, ChildGeometryBase
{
    ChildGeometry();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};
struct MaterialProperty
{
    MaterialProperty();
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
};
struct FogProperty
{
    FogProperty(float);
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
};
struct AlphaProperty
{
    AlphaProperty();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct RenderPolicy
{
    RenderPolicy();
};
struct FUN_006815c0_Position
{
    float x, y, z;
    FUN_006815c0_Position();
};
struct ActiveRegistry
{
    ActiveRegistry();
    int unk00;
    int unk04;
};
struct RefList
{
};
struct Shadow
{
    Shadow();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct CellProxy : TESObjectCELL
{
    bool FUN_00425fd0();
    void FUN_00454380(bool);
    void FUN_00552dc0();
};
bool __cdecl FUN_00454ae0();
void* __cdecl FUN_00aa13e0(unsigned int);

// Creates and configures a SpatialNode when the cell has none, then creates and stores a Shadow when the cell has none.
// @fnv 0x00552dc0
void CellProxy::FUN_00552dc0()
{
    SpatialNode* root = ((::fnv_00552dc0::SpatialNode *)(reinterpret_cast<::FUN_004543c0_cls *>(this)->FUN_004543c0()));
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && root == 0)
    {
        ScopedCellOperation guard(0x10, true, ::str_0102ed68, 0x3a3f);
        SceneInitializer init;
        reinterpret_cast<::AlignedVector *>(&(init.rotation))->FUN_004a3f10((*(const ::AlignedVector *)(&ResultSlot(FourFloatVector(0.0f, 0.0f, ::runtimeInitializationFloat2390, 0.0f)))));
        reinterpret_cast<::S_00c90db0_Foo *>(&(init))->FUN_00c90db0(::fnv_0054c030::DAT_0102efc0);
        init.scale = 1.0f;
        root = new SpatialNode(&init);
        reinterpret_cast<::Script *>((root))->GetLocalData();
        reinterpret_cast<::fnv_00553480::FUN_00553480_cls *>((root))->FUN_00553480((char *)(::fnv_00552dc0::ChildGeometryBase *)(new ChildGeometry()));
        reinterpret_cast<::_Helper_005534f0 *>((root))->FUN_005534f0(new MaterialProperty());
        if (reinterpret_cast<::fnv_004518e0::TESObjectCELL *>(this)->FUN_004518e0())
        {
            reinterpret_cast<::FUN_00c6a620_cls *>((root))->SetField(new FogProperty(reinterpret_cast<::FUN_005471e0_shell *>(this)->FUN_005471e0()));
        }
        reinterpret_cast<::fnv_00553440::S *>((root))->FUN_00553440((std::intptr_t)(((void *)(::FUN_00453720()))));
        reinterpret_cast<::FUN_005533f0_cls *>((root))->FUN_005533f0((std::uintptr_t)(new AlphaProperty()));
        if ((*reinterpret_cast<unsigned int *>(&::DAT_011ca088)) == 0)
        {
            (*reinterpret_cast<void **>(&::DAT_011ca088)) = new ActiveRegistry();
        }
        reinterpret_cast<::FUN_006242a0_cls *>((((ActiveRegistry*)(*reinterpret_cast<void **>(&::DAT_011ca088)))))->NotifyActivation((::ActivationListener *)(void *)(((void *)(reinterpret_cast<::ScriptLocals *>((root))->GetLocalData()))));
        FUN_006815c0_Position pos;
        reinterpret_cast<::fnv_0054c030::RotationCell *>(this)->ComputeCellRotationCenter((*(::fnv_0054c030::RotationPoint *)(&pos)));
        ::FUN_00c68750((const ::SourcePoint *)(root));
        reinterpret_cast<::Root *>((root))->SetProcessEnabled(FUN_00454ae0());
        reinterpret_cast<::fnv_0041b8d0::FUN_0041b8d0_shell *>((((RefList*)&extraDataList)))->SetHavokWorld((::fnv_0041b8d0::bhkWorld *)(root));
        reinterpret_cast<::Script *>((root))->GetLocalData();
        root->Vc4();
        reinterpret_cast<::FUN_00454380_Class *>((root))->FUN_00454380(!((bool)(::FUN_00456c70())));
    }
    {
        Shadow* pkShadow = ((::fnv_00552dc0::Shadow *)(::GetCellMopp((char *)this)));
        if (!pkShadow)
        {
            ScopedCellOperation guard(0x10, true, ::str_0102ed68, 0x3a91);
            pkShadow = new Shadow();
            reinterpret_cast<::fnv_0041ba60::FUN_0041ba60_shell *>((((RefList*)&extraDataList)))->SetCellMopp((::fnv_0041ba60::CellMopp *)(pkShadow));
        }
    }
}
}  // namespace fnv_00552dc0

namespace fnv_00545960 {
struct G
{
    void* p;
    G(int);
    ~G();
    void FUN_0066b0d0(void* x);
};
struct Inner
{
};
struct A
{
};
struct S
{
    char pad[0xc4];
    Inner* m;
    void* FUN_00545960(A* a);
};
// Calls Inner::FUN_006c62d0 on m with a and a G buffer, falling back to FUN_00545740 on failure, then returns the G result.
// @fnv 0x00545960
void* S::FUN_00545960(A* a)
{
    if (m == 0 || a == 0 || !((unsigned char)(reinterpret_cast<::FUN_00439f90_shell *>((a))->FUN_00439f90())))
        return 0;
    G g(0);
    if (!((unsigned char)(reinterpret_cast<::Map62d0 *>((((Inner*)((char*)m + 0x3c))))->FUN_006c62d0((std::uintptr_t)(a), (void **)(::fnv_00545960::G *)(&g)))) || !((void *)(::FUN_00559450((int *)&(g)))))
        g.FUN_0066b0d0(((void *)(reinterpret_cast<::CellLike *>(this)->GetOrCreateFaceGenNode((::RefForm *)(a)))));
    return ((void *)(::FUN_00559450((int *)&(g))));
}
}  // namespace fnv_00545960

namespace fnv_00554b90 {
struct FUN_00484bf0_shell
{
};

struct SeenData_Stub
{
    virtual void v00();
    virtual void v04();
    virtual unsigned short FUN_08(int);
};

union SETTING_VALUE;
struct GlobalObject_0045cf30
{
    bool* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

struct TESSaveLoadGame
{
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct TESForm_Stub
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual const char* GetEditorID();
};


struct FUN_00554b90_shell : public TESObjectCELL
{
    unsigned short FUN_00554b90(unsigned int flags);
};

// Computes the total byte size needed to save this cell, adding sizes for optional fields selected by flags and logging the result when a debug global is set.
// @fnv 0x00554b90
unsigned short FUN_00554b90_shell::FUN_00554b90(unsigned int flags)
{
    unsigned short uSize = 0;
    if (flags & 0x40000000)
        uSize += 4;
    uSize += reinterpret_cast<::FUN_00484bf0_shell *>((((FUN_00484bf0_shell*)this)))->FUN_00484bf0(flags);
    unsigned short uBaseSize2 = uSize;
    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        uSize += 4;
        uSize += 2;
    }
    if (flags & 2)
        uSize += 1;
    if (flags & 0x80000000)
        uSize += ((::fnv_00554b90::SeenData_Stub *)(reinterpret_cast<::FUN_00555bc0_shell *>(this)->FindSeenData()))->FUN_08(0);
    if (flags & 4)
    {
        uSize += 1;
        uSize += ::FUN_0044a670(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)this->kFullName)))->FUN_00408da0())));
    }
    if (flags & 8)
        uSize += 4;
    if (*g_011de4e8.Bool())
    {
        void* pObj4 = ((void *)(reinterpret_cast<::EffectSetting *>((g_TESSaveLoadGame))->GetHitSound()));
        if (pObj4)
        {
            TESForm_Stub* pForm = (TESForm_Stub*)::FUN_004839c0(*(unsigned int*)pObj4);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return uSize;
}
}  // namespace fnv_00554b90

class Actor;
struct CellOwnerCheck : public TESObjectCELL
{
    bool FUN_00546ca0(Actor*);
};

struct FNV_Ref;


class TESNPC : public TESBoundObject
{
  public:
    virtual ~TESNPC();
};

struct TESFaction : TESForm
{
    virtual ~TESFaction();
};

struct FUN_00546ac0_shell
{
    int FUN_00546ac0();
};

struct TESActorBaseData
{
};

struct CellOwnerNpcView
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
    TESActorBaseData actorBase;
};

// Returns true when the actor matches the owner NPC or its faction rank meets the rank returned by FUN_00546ac0.
// @fnv 0x00546ca0
bool CellOwnerCheck::FUN_00546ca0(Actor* apActor)
{
    bool bHasResultObj = false;
    TESForm* powner = ((DoorCell*)this)->GetOwner();
    if (powner)
    {
        typedef bool(* Fn218)(Actor*);
        if (!((Fn218*)(*(void**)apActor))[0x218 / 4](apActor))
        {
            return bHasResultObj;
        }
        TESNPC* pnpc = dynamic_cast<TESNPC*>(powner);
        if (pnpc)
        {
            if (pnpc == (TESNPC*)((reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((CellLightingTemplate*)apActor))->FUN_007af430())))
            {
                bHasResultObj = true;
            }
        }
        else
        {
            TESFaction* pfaction = dynamic_cast<TESFaction*>(powner);
            if (pfaction)
            {
                int irank = ((FUN_00546ac0_shell*)this)->FUN_00546ac0();
                TESNPC* pactnpc =
                    dynamic_cast<TESNPC*>((TESBoundObject*)((reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((CellLightingTemplate*)apActor))->FUN_007af430())));
                int iactrank =
                    reinterpret_cast<::fnv_0047d680::FUN_0047d680_shell *>(&(((CellOwnerNpcView*)pactnpc)->actorBase))->GetFactionRank((::fnv_0047d680::TESFaction *)(pfaction), apActor == (Actor*)DAT_011dea3c);
                if (iactrank >= irank)
                {
                    bHasResultObj = true;
                }
            }
        }
    }
    return bHasResultObj;
}

namespace fnv_00546ee0 {
class TESActorBase;
class TESFaction;
class type_info;

extern type_info DAT_01183028;
extern type_info DAT_01183a1c;
extern type_info DAT_01184704;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, const void*, const void*, int);

struct CellOwnerRankData
{
};

struct CellOwnerNPCView
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    CellOwnerRankData actorData;
};

struct CellOwnerCheck : public TESObjectCELL
{
    bool FUN_00546ee0(TESActorBase*);
};

// Returns true when apActorBase matches the owner NPC or its faction rank meets the rank returned by FUN_00546ac0.
// @fnv 0x00546ee0
bool CellOwnerCheck::FUN_00546ee0(TESActorBase* apActorBase)
{
    bool bHasResultObj = false;
    TESForm* powner = ((DoorCell*)this)->GetOwner();
    if (powner)
    {
        CellOwnerNPCView* pnpc = (CellOwnerNPCView*)dynamic_cast<::TESNPC *>(reinterpret_cast<::TESForm *>(powner));
        if (pnpc)
        {
            if (pnpc == (CellOwnerNPCView*)apActorBase)
                bHasResultObj = true;
        }
        else
        {
            TESFaction* pfaction = (TESFaction*)dynamic_cast<::TESFaction *>(reinterpret_cast<::TESForm *>(powner));
            if (pfaction)
            {
                int irank = reinterpret_cast<::FUN_00546ac0_shell *>(this)->FUN_00546ac0();
                CellOwnerNPCView* pactnpc =
                    (CellOwnerNPCView*)FUN_00ec43fb(apActorBase, 0, &(*reinterpret_cast<::fnv_00546ee0::type_info *>(&::DAT_011846e8)), &DAT_01183a1c, 0);
                if (pactnpc)
                {
                    int iactrank = reinterpret_cast<::fnv_0047d680::FUN_0047d680_shell *>(&(pactnpc->actorData))->GetFactionRank((::fnv_0047d680::TESFaction *)(pfaction), false);
                    if (iactrank >= irank)
                        bHasResultObj = true;
                }
            }
        }
    }
    return bHasResultObj;
}
}  // namespace fnv_00546ee0

class Actor;
struct BGSSaveFormBuffer;
class SaveLoadFile;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct ThreeByThreeMatrix;
struct NiPoint3;
class NiQuaternion;
class TESBoundObject;
class TESForm;
struct hkVector4;

struct CellInitLoadView : public TESObjectCELL
{
    void FUN_005559d0(BGSLoadFormBuffer*);
};

struct CellInitLoadBaseView
{
};

struct FUN_00546bf0_stub
{
};
// Calls the base load method, then resolves and passes the owner form when change flag 8 is set.
// @fnv 0x005559d0
void CellInitLoadView::FUN_005559d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>((((CellInitLoadBaseView*)this)))->FUN_004534f0((std::uintptr_t)(apLoadGameBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((((BGSChangeFlags_s*)&ResultSlot(apLoadGameBuffer->GetChangeFlags()))))->FUN_004280f0(8))
    {
        TESForm* powner = ((DoorCell*)this)->GetOwner();
        if (powner)
        {
            powner = powner ? ::FUN_004839c0((unsigned int)(std::uintptr_t)(powner)) : 0;
            reinterpret_cast<::FUN_00546bf0_class *>((((FUN_00546bf0_stub*)this)))->FUN_00546bf0((std::intptr_t)(powner));
        }
    }
}

struct Call_006c0c80
{
};

class NavMeshObstacleManager : public Call_006c0c80
{
  public:
};

class TESBoundObject;
unsigned int _FNV_GetFormType(TESForm* form);

struct CellObstacleVirtualBase
{
    virtual unsigned char f01()
    {
        return 0;
    }
    virtual unsigned char f02()
    {
        return 0;
    }
    virtual unsigned char f03()
    {
        return 0;
    }
    virtual unsigned char f04()
    {
        return 0;
    }
    virtual unsigned char f05()
    {
        return 0;
    }
    virtual unsigned char f06()
    {
        return 0;
    }
    virtual unsigned char f07()
    {
        return 0;
    }
    virtual unsigned char f08()
    {
        return 0;
    }
    virtual unsigned char f09()
    {
        return 0;
    }
    virtual unsigned char f10()
    {
        return 0;
    }
    virtual unsigned char f11()
    {
        return 0;
    }
    virtual unsigned char f12()
    {
        return 0;
    }
    virtual unsigned char f13()
    {
        return 0;
    }
    virtual unsigned char f14()
    {
        return 0;
    }
    virtual unsigned char f15()
    {
        return 0;
    }
    virtual unsigned char f16()
    {
        return 0;
    }
    virtual unsigned char f17()
    {
        return 0;
    }
    virtual unsigned char f18()
    {
        return 0;
    }
    virtual unsigned char f19()
    {
        return 0;
    }
    virtual unsigned char f20()
    {
        return 0;
    }
    virtual unsigned char f21()
    {
        return 0;
    }
    virtual unsigned char f22()
    {
        return 0;
    }
    virtual unsigned char f23()
    {
        return 0;
    }
    virtual unsigned char f24()
    {
        return 0;
    }
    virtual unsigned char f25()
    {
        return 0;
    }
    virtual unsigned char f26()
    {
        return 0;
    }
    virtual unsigned char f27()
    {
        return 0;
    }
    virtual unsigned char f28()
    {
        return 0;
    }
    virtual unsigned char f29()
    {
        return 0;
    }
    virtual unsigned char f30()
    {
        return 0;
    }
    virtual unsigned char f31()
    {
        return 0;
    }
    virtual unsigned char f32()
    {
        return 0;
    }
    virtual unsigned char f33()
    {
        return 0;
    }
    virtual unsigned char f34()
    {
        return 0;
    }
    virtual unsigned char f35()
    {
        return 0;
    }
    virtual unsigned char f36()
    {
        return 0;
    }
    virtual unsigned char f37()
    {
        return 0;
    }
    virtual unsigned char f38()
    {
        return 0;
    }
    virtual unsigned char f39()
    {
        return 0;
    }
    virtual unsigned char f40()
    {
        return 0;
    }
    virtual unsigned char f41()
    {
        return 0;
    }
    virtual unsigned char f42()
    {
        return 0;
    }
    virtual unsigned char f43()
    {
        return 0;
    }
    virtual unsigned char f44()
    {
        return 0;
    }
    virtual unsigned char f45()
    {
        return 0;
    }
    virtual unsigned char f46()
    {
        return 0;
    }
    virtual unsigned char f47()
    {
        return 0;
    }
    virtual unsigned char f48()
    {
        return 0;
    }
    virtual unsigned char f49()
    {
        return 0;
    }
    virtual unsigned char f50()
    {
        return 0;
    }
    virtual unsigned char f51()
    {
        return 0;
    }
    virtual unsigned char f52()
    {
        return 0;
    }
    virtual unsigned char f53()
    {
        return 0;
    }
    virtual unsigned char f54()
    {
        return 0;
    }
    virtual unsigned char f55()
    {
        return 0;
    }
    virtual unsigned char f56()
    {
        return 0;
    }
    virtual unsigned char f57()
    {
        return 0;
    }
    virtual unsigned char f58()
    {
        return 0;
    }
    virtual unsigned char f59()
    {
        return 0;
    }
    virtual unsigned char f60()
    {
        return 0;
    }
    virtual unsigned char f61()
    {
        return 0;
    }
    virtual unsigned char f62()
    {
        return 0;
    }
    virtual unsigned char f63()
    {
        return 0;
    }
    virtual unsigned char f64()
    {
        return 0;
    }
    virtual unsigned char f65()
    {
        return 0;
    }
    virtual unsigned char f66()
    {
        return 0;
    }
    virtual unsigned char f67()
    {
        return 0;
    }
    virtual unsigned char f68()
    {
        return 0;
    }
    virtual unsigned char f69()
    {
        return 0;
    }
    virtual unsigned char f70()
    {
        return 0;
    }
    virtual unsigned char f71()
    {
        return 0;
    }
    virtual unsigned char f72()
    {
        return 0;
    }
    virtual unsigned char f73()
    {
        return 0;
    }
    virtual unsigned char f74()
    {
        return 0;
    }
    virtual unsigned char f75()
    {
        return 0;
    }
    virtual unsigned char f76()
    {
        return 0;
    }
    virtual unsigned char f77()
    {
        return 0;
    }
    virtual unsigned char f78()
    {
        return 0;
    }
    virtual unsigned char f79()
    {
        return 0;
    }
    virtual unsigned char f80()
    {
        return 0;
    }
    virtual unsigned char f81()
    {
        return 0;
    }
    virtual unsigned char f82()
    {
        return 0;
    }
    virtual unsigned char f83()
    {
        return 0;
    }
    virtual unsigned char f84()
    {
        return 0;
    }
    virtual unsigned char f85()
    {
        return 0;
    }
    virtual unsigned char f86()
    {
        return 0;
    }
    virtual unsigned char f87()
    {
        return 0;
    }
};

struct CellObstacleVirtual : public CellObstacleVirtualBase
{
    virtual unsigned char Check()
    {
        return 0;
    }
};

struct FUN_00551110_Cell : public TESObjectCELL
{
  public:
    void FUN_005576c0();
};
// @fnv 0x00552bd0
void CellTarget::FUN_00552bd0(bool reset)
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    int p = ((int)(reinterpret_cast<::FUN_00450fd0_class *>(this)->GetByteAtOffset38()));
    if (p == 6 || p == 5)
    {
        reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(4);
        reinterpret_cast<::FUN_00557c40_cls *>(this)->FUN_00557c40();
        reinterpret_cast<::B445670Loader *>(((*reinterpret_cast<::WorldManager552 * *>(&::g_modelLoader))))->FUN_00445670((::B445670Cell *)(::CellTarget *)(this));
        reinterpret_cast<::FUN_00452e50_class *>((DAT_011dea10))->FUN_00452e50();
        FUN_0054ba80(0);
        if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
            reinterpret_cast<::fnv_00454c20::RecentItems *>((DAT_011dea10))->FUN_00454c20(this);
        else
            reinterpret_cast<::TESBuffer45130 *>((DAT_011dea10))->FUN_00455130((::TESObjectCELL *)(::CellTarget *)(this));
        if (reset)
            reinterpret_cast<::FUN_00553700_shell *>(this)->UpdateCell();
        FUN_005577b0(0);
        void* h = ((void *)(reinterpret_cast<::FUN_00545cf0_Cls *>(this)->GetOrCreateWidget()));
        ((::FinalActor *)(reinterpret_cast<::FUN_0084e3a0_Class *>((DAT_011dea10))->FUN_0084e3a0()))->Finalize(h);
        ProcessPerkEntries();
        reinterpret_cast<::FUN_00551110_Cell *>(this)->FUN_005576c0();
        reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(3);
        loaded = true;
        if (!((bool)(reinterpret_cast<::FUN_00552da0_class *>((DAT_011de134))->GetUnk26())))
            reinterpret_cast<::FUN_0054af40_cls *>(this)->FUN_0054af40(true);
        reinterpret_cast<::fnv_00546c70::TESObjectCELL_s *>(this)->FUN_00546c70();
        reinterpret_cast<::FUN_0054b950_shell *>(this)->FUN_0054b950(false);
        reinterpret_cast<::RenderTask *>((((::Temp552 *)(::FUN_00552ba0()))))->UpdateChildByKey({});
        if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::Checker552 * *>(&::g_dataHandler))))->IsRenderTargetId(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))
            reinterpret_cast<::BGSSaveLoadGame *>(((*reinterpret_cast<::Updater552 * *>(&::g_BGSSaveLoadGame))))->HasFormChanges((::TESForm *)(::CellTarget *)(this));
        reinterpret_cast<::FUN_00452e50_class *>((DAT_011dea10))->FUN_00452e50();
        Portal552* a = ((::Portal552 *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>(this)->FUN_009d9f20()));
        reinterpret_cast<::S_00c5ba50_Class *>((a))->FUN_00c5ba50((std::uintptr_t)(((void *)(::FUN_0054aa60((::TESObjectCELL *)this)))));
        reinterpret_cast<::S_00c5ba50_Class *>((a))->FUN_00c5ba50((std::uintptr_t)(((void *)(reinterpret_cast<::FUN_0054a050_shell *>(this)->FUN_0054a050()))));
        reinterpret_cast<::S_00c5ba50_Class *>((a))->FUN_00c5ba50((std::uintptr_t)(((void *)(reinterpret_cast<::TESObjectCELL *>(this)->GetCellChildAt(2)))));
        reinterpret_cast<::S_00c5ba50_Class *>((a))->FUN_00c5ba50((std::uintptr_t)(((void *)(::FUN_00524cf0((::TESObjectCELL *)this)))));
    }
    ::FUN_00541ae0((char *)this);
}

// Iterates a BGSPerkEntry list and calls NavMeshObstacleManager methods based on Check() and whether the referenced form type is 0x1C.
// @fnv 0x005576c0
void FUN_00551110_Cell::FUN_005576c0()
{
    CellRefLockEnter();

    BSSimpleList<BGSPerkEntry*>* perkList = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (perkList)
    {
        BGSPerkEntry* perk = (perkList->item);
        if (perk)
        {
            if (reinterpret_cast<CellObstacleVirtual*>(perk)->Check())
            {
                reinterpret_cast<::fnv_006c1cb0::Call_006c0c80 *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c0c80((::fnv_006c1cb0::TESObjectREFR *)(::TESObjectREFR *)(reinterpret_cast<TESObjectREFR*>(perk)));
            }

            if (_FNV_GetFormType(reinterpret_cast<TESForm*>(
                    ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<TESObjectREFR*>(perk)))->FUN_007af430())))) == 0x1C)
            {
                reinterpret_cast<::Own60 *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c1060((::s60::Ref *)(::TESObjectREFR *)(reinterpret_cast<TESObjectREFR*>(perk)));
            }
        }

        perkList = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((perkList))->FUN_00726070()));
    }

    ::FUN_00541ae0((char *)this);
}

class Actor;
class TESFaction;
__if_exists(::TESBoundObject::~TESBoundObject)
{
    using ::TESBoundObject;
}
__if_exists(::TESNPC::~TESNPC)
{
    using ::TESNPC;
}
class TESBoundObject;
class TESNPC;
__if_not_exists(TESBoundObject::~TESBoundObject)
{
    class TESBoundObject
    {
      public:
        virtual ~TESBoundObject();
    };
}
__if_not_exists(TESNPC::~TESNPC)
{
    class TESNPC
    {
    };
}
class type_info;
__if_not_exists(DAT_01183028)
{
    extern const type_info DAT_01183028;
}
__if_not_exists(DAT_01183a1c)
{
    extern const type_info DAT_01183a1c;
}
__if_not_exists(DAT_01184704)
{
    extern const type_info DAT_01184704;
}
__if_not_exists(_g_thePlayer)
{
    extern void* _g_thePlayer;
}

struct TrespassCellView : TESObjectCELL
{
    bool FUN_00546da0(Actor*);
};
struct TrespassActorDataView
{
};
struct TrespassNpcView
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
    TrespassActorDataView actorData;
};
struct TrespassPublicView
{
};
struct TrespassGlobalView
{
};
struct TrespassRankView
{
};
struct TrespassReferenceView
{
};

struct TrespassActorView
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
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
    virtual bool V218();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual bool V304();
};

// Returns false when the initial actor check fails; otherwise checks ownership, public status, actor references, and faction rank.
// @fnv 0x00546da0
bool TrespassCellView::FUN_00546da0(Actor* apActor)
{
    bool bHasResultObj = false;
    if (((TrespassActorView*)apActor)->V304())
        return false;
    TESForm* powner = ((DoorCell*)this)->GetOwner();
    if (powner && !reinterpret_cast<::FUN_005443e0_class *>((((TrespassPublicView*)this)))->IsAnyConditionTrue())
    {
        if (((void *)(reinterpret_cast<::FUN_00546aa0_shell *>((((TrespassGlobalView*)this)))->FUN_00546aa0())) || !((TrespassActorView*)apActor)->V218())
            return bHasResultObj;
        TrespassNpcView* pnpc = (TrespassNpcView*)dynamic_cast<::TESNPC *>(reinterpret_cast<::TESForm *>(powner));
        if (pnpc)
        {
            if (pnpc != (TrespassNpcView*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TrespassReferenceView*)apActor)))->FUN_007af430())))
                bHasResultObj = true;
        }
        else
        {
            TESFaction* pfaction = (TESFaction*)dynamic_cast<::TESFaction *>(reinterpret_cast<::TESForm *>(powner));
            if (pfaction)
            {
                int irank = reinterpret_cast<::FUN_00546ac0_shell *>((((TrespassRankView*)this)))->FUN_00546ac0();
                TrespassNpcView* pactnpc =
                    (TrespassNpcView*)dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TrespassReferenceView*)apActor)))->FUN_007af430())));
                int iactrank = reinterpret_cast<::fnv_0047d680::FUN_0047d680_shell *>(&(pactnpc->actorData))->GetFactionRank((::fnv_0047d680::TESFaction *)(pfaction), apActor == (void*)_g_thePlayer);
                if (iactrank < irank)
                    bHasResultObj = true;
            }
        }
    }
    return bHasResultObj;
}

namespace fnv_00541ce0 {
struct FUN_004855a0
{
};

struct DoorPart30
{
    unsigned int unk00, unk04, unk08;
};

struct FUN_00485680
{
};

struct FUN_0058f080
{
    void Save();
};

using ::ImpactSwap;
using ::FUN_0041c460;

struct ExtraDataListSave_standin
{
};

struct CellSaveInteriorData
{
};



struct _ref_0084e3a0_standin
{
};

struct CellSaveTexture
{
    unsigned int FUN_0048cee0();
};

struct CellSaveFields
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorPart30 fullName;
    unsigned char flags, unk25;
    unsigned short unk26;
    ExtraDataList extras;
    unsigned int unk48, unk4c;
    float waterHeight;
    unsigned int unk54;
    CellSaveTexture texture;
};

void __cdecl _FUN_00485910(int, int);
void __cdecl _FUN_00485910(int, unsigned int);
void __cdecl _FUN_00485910(int, float);

struct CellSaveShell : public TESObjectCELL
{
    void FUN_00541ce0();
};

// Writes the cell's save data, including interior/exterior data, lighting, water height, texture, and extra data list.
// @fnv 0x00541ce0
void CellSaveShell::FUN_00541ce0()
{
    unsigned int imageSpaceModifier;
    ExteriorCellData* interiorData;
    ImpactSwap* lightingData;
    InteriorCellData* pInteriorData;

    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(&(reinterpret_cast<CellSaveFields*>(this)->fullName))->FUN_00487010();
    ::FUN_004858f0(0x41544144, this->field24);

    if (this->IsCellInterior())
    {
        pInteriorData = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((this))->FUN_00544600()));
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::SwapBlock *>((reinterpret_cast<CellSaveInteriorData*>(pInteriorData)))->SwapBytes();

        ::AppendChunk(0x4c4c4358, pInteriorData, 0x2c);

        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::SwapBlock *>((reinterpret_cast<CellSaveInteriorData*>(pInteriorData)))->SwapBytes();

        lightingData = FUN_0041c460(((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((reinterpret_cast<TESDataHandler*>(this)))->GetExtraDataList())));
        if (lightingData)
            reinterpret_cast<::FUN_0058f080 *>((reinterpret_cast<FUN_0058f080*>(lightingData)))->Save();
    }
    else
    {
        interiorData = ((::ExteriorCellData *)(reinterpret_cast<::FUN_005445d0_shell *>((this))->FUN_005445d0()));
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>((reinterpret_cast<S_00462230*>(interiorData)))->FUN_00462230();

        ::AppendChunk(0x434c4358, interiorData, 0xc);

        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>((reinterpret_cast<S_00462230*>(interiorData)))->FUN_00462230();
    }

    imageSpaceModifier =
        ((::CellLightingTemplate *)(reinterpret_cast<::FUN_00558b40_shell *>((this))->GetLightingTemplate()))
            ? reinterpret_cast<unsigned int>(
                  ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<_ref_0084e3a0_standin*>(((::CellLightingTemplate *)(reinterpret_cast<::FUN_00558b40_shell *>((this))->GetLightingTemplate())))))->FUN_0084e3a0())))
            : 0;

    ::FUN_00485910(0x504d544c, imageSpaceModifier);
    ::FUN_00485910(0x4d414e4c, this->unknownDC);
    ::FUN_00485910(0x574c4358, reinterpret_cast<CellSaveFields*>(this)->waterHeight);

    ::FUN_004856f0((void *)(0x4d414e58), ((char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(reinterpret_cast<CellSaveFields*>(this)->texture))->FUN_00408da0())),
                 (void *)(std::uintptr_t)(reinterpret_cast<CellSaveFields*>(this)->texture.FUN_0048cee0() + 1));

    reinterpret_cast<::ExtraSave::ExtraList *>((reinterpret_cast<ExtraDataListSave_standin*>(&this->extraDataList)))->WriteToSave();
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

}

class TESChildCell
{
  public:
    virtual void* GetContainingCell();
};
namespace fnv_00543230 {
using ::TESForm;
using ::TESObjectCELL;
using ::TESChildCell;
using ::FUN_00425fd0;
using ::FUN_0054ddd0;
struct CellSaveFormID
{
    unsigned int FUN_0084e3a0();
};
struct CellSaveBlock
{
};
struct CellSaveSubblock
{
};
struct S00543230_CellOrder;
struct S00543230_CellOrder
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual bool LessThan(TESForm*);
    bool FUN_00543230(TESForm* form);
};
struct S00543230_FormTypeOrder
{
    int FUN_00401170();
};
// Applies cell-specific ordering checks for selected form types and falls back to FUN_00484020 for others.
// @fnv 0x00543230
bool S00543230_CellOrder::FUN_00543230(TESForm* form)
{
    bool result = false;
    switch (reinterpret_cast<S00543230_FormTypeOrder*>(form)->FUN_00401170())
    {
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x69: {
        TESChildCell* child = dynamic_cast<TESChildCell*>(form);
        if (child->GetContainingCell() == this)
            result = true;
        else
            result = LessThan(static_cast<TESForm*>(child->GetContainingCell()));
        break;
    }
    case 0x41:
        if (!reinterpret_cast<::TESObjectCELL *>((this))->IsCellInterior())
            result = static_cast<S00543230_CellOrder*>(((void *)(reinterpret_cast<::TESObjectCELL *>((this))->GetParentWorldSpace())))->LessThan(form);
        else
            result = true;
        break;
    case 0x39: {
        S00543230_CellOrder* other = reinterpret_cast<S00543230_CellOrder*>(dynamic_cast<TESObjectCELL*>(form));
        if (other)
        {
            if (reinterpret_cast<::TESObjectCELL *>((this))->IsCellInterior() && !reinterpret_cast<::TESObjectCELL *>((other))->IsCellInterior())
                result = true;
            else if (reinterpret_cast<::TESObjectCELL *>((this))->IsCellInterior() == reinterpret_cast<::TESObjectCELL *>((other))->IsCellInterior())
            {
                bool comparePosition = true;
                if (!reinterpret_cast<::TESObjectCELL *>((this))->IsCellInterior())
                {
                    S00543230_CellOrder* world = static_cast<S00543230_CellOrder*>(((void *)(reinterpret_cast<::TESObjectCELL *>((this))->GetParentWorldSpace())));
                    S00543230_CellOrder* otherWorld = static_cast<S00543230_CellOrder*>(((void *)(reinterpret_cast<::TESObjectCELL *>((other))->GetParentWorldSpace())));
                    if (world != otherWorld)
                    {
                        result = world->LessThan(reinterpret_cast<TESForm*>(otherWorld));
                        comparePosition = false;
                    }
                    else if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent() != reinterpret_cast<::FUN_005516c0 *>((other))->IsCellPersistent())
                    {
                        if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
                            result = true;
                        else
                            result = false;
                        comparePosition = false;
                    }
                }
                if (comparePosition)
                {
                    if (reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<CellSaveBlock*>(this)))->FUN_005441b0() <
                        reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<CellSaveBlock*>(other)))->FUN_005441b0())
                        result = true;
                    else if (reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<CellSaveBlock*>(this)))->FUN_005441b0() ==
                             reinterpret_cast<::FUN_005441b0_S *>((reinterpret_cast<CellSaveBlock*>(other)))->FUN_005441b0())
                    {
                        if (reinterpret_cast<::FUN_00544210_shell *>((reinterpret_cast<CellSaveSubblock*>(this)))->FUN_00544210() <
                            reinterpret_cast<::FUN_00544210_shell *>((reinterpret_cast<CellSaveSubblock*>(other)))->FUN_00544210())
                            result = true;
                        else if (reinterpret_cast<::FUN_00544210_shell *>((reinterpret_cast<CellSaveSubblock*>(this)))->FUN_00544210() ==
                                 reinterpret_cast<::FUN_00544210_shell *>((reinterpret_cast<CellSaveSubblock*>(other)))->FUN_00544210())
                        {
                            if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<CellSaveFormID*>(this)))->FUN_0084e3a0())) <
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<CellSaveFormID*>(other)))->FUN_0084e3a0())))
                                result = true;
                        }
                    }
                }
            }
        }
        break;
    }
    default:
        result = reinterpret_cast<::TESFormSortProxy *>(this)->IsLessThan(form);
        break;
    }
    return result;
}

}

namespace fnv_00543c50 {
using ::TESForm;
using ::TESObjectCELL;
using ::TESDataHandler;
using ::CellLightingTemplate;
using ::InteriorCellData;
using ::ExteriorCellData;
using ::BSSimpleList;
using ::TESImageSpaceModifier;
struct FUN_00497280_shell
{
};

struct FUN_005e79a0_t
{
};

struct FUN_004127e0_shell
{
    bool FUN_004127e0(BSSimpleList<TESImageSpaceModifier*>* otherList);
};

struct CellCompareComponent
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual bool Compare(void* otherData);
};

struct CellCompareFields
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    float waterHeight;
    unsigned int field54;
    CellCompareComponent component;
};

struct CellCompareView : public TESObjectCELL
{
    bool FUN_00543c50(TESForm* apCompare);
};


// Returns true when a checked cell field, data block, image space modifier list, or component comparison reports a difference.
// @fnv 0x00543c50
bool CellCompareView::FUN_00543c50(TESForm* apCompare)
{
    TESForm* pCompareCell;

    pCompareCell = reinterpret_cast<TESForm*>(dynamic_cast<TESObjectCELL*>(apCompare));

    if (!pCompareCell)
    {
        return true;
    }

    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pCompareCell))
    {
        return true;
    }

    if ((signed char)reinterpret_cast<::TESObjectCELL *>((this))->GetField24() != (signed char)reinterpret_cast<::TESObjectCELL *>((((CellCompareView*)pCompareCell)))->GetField24())
    {
        return true;
    }

    if (this->unknownDC != reinterpret_cast<::FUN_00497280_shell *>((((FUN_00497280_shell*)pCompareCell)))->GetFieldAt124())
    {
        return true;
    }

    if (((::CellLightingTemplate *)(reinterpret_cast<::FUN_00558b40_shell *>((this))->GetLightingTemplate())) != ((::CellLightingTemplate *)(reinterpret_cast<::FUN_00558b40_shell *>((((CellCompareView*)pCompareCell)))->GetLightingTemplate())))
    {
        return true;
    }

    if (((CellCompareFields*)this)->waterHeight != ((CellCompareFields*)pCompareCell)->waterHeight)
    {
        return true;
    }

    if (this->IsCellInterior())
    {
        InteriorCellData* pdata;
        InteriorCellData* pCompareData;

        pdata = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((this))->FUN_00544600()));
        pCompareData = ((::InteriorCellData *)(reinterpret_cast<::FUN_00544600_shell *>((((TESObjectCELL*)pCompareCell)))->FUN_00544600()));

        if (pdata && pCompareData && std::memcmp(pdata, pCompareData, 0x2c) != 0)
        {
            return true;
        }
    }
    else
    {
        ExteriorCellData* pdata;
        ExteriorCellData* pCompareData;

        pdata = ((::ExteriorCellData *)(reinterpret_cast<::FUN_005445d0_shell *>((this))->FUN_005445d0()));
        pCompareData = ((::ExteriorCellData *)(reinterpret_cast<::FUN_005445d0_shell *>((((TESObjectCELL*)pCompareCell)))->FUN_005445d0()));

        if (pdata && pCompareData && std::memcmp(pdata, pCompareData, 0xc) != 0)
        {
            return true;
        }
    }

    if (((FUN_004127e0_shell*)((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESDataHandler*)this)))->GetExtraDataList())))
            ->FUN_004127e0(((::BSSimpleList< ::TESImageSpaceModifier *> *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESDataHandler*)pCompareCell)))->GetExtraDataList()))))
    {
        return true;
    }

    if (((CellCompareFields*)this)->component.Compare(&((CellCompareFields*)pCompareCell)->component))
    {
        return true;
    }

    return false;
}

}

__if_exists(::TESImageSpace)
{
    using ::TESImageSpace;
}
__if_not_exists(::TESImageSpace)
{
    class TESImageSpace : public TESForm
    {
    };
}
namespace cell547 {
struct C5Region
{
};
struct C5Cell
{
    bool FUN_00425fd0();
    C5Region* FUN_0054ddd0();
    TESImageSpace* FUN_00547680();
};
}
using namespace cell547;

typedef TESForm*(__cdecl* GetFormFn)(unsigned int);

// Returns the cell image space, falling back to a region image space or form 0x160/0x161 depending on cell state.
// @fnv 0x00547680
TESImageSpace* C5Cell::FUN_00547680()
{
    TESImageSpace* m_pImageSpace = ((::TESImageSpace *)(std::uintptr_t)(reinterpret_cast<::FUN_00547650_class *>(this)->FUN_00547650()));
    if (!m_pImageSpace && !reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && ((::cell547::C5Region *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())))
    {
        m_pImageSpace = ((::TESImageSpace *)(reinterpret_cast<::FUN_00586020_shell *>((((::cell547::C5Region *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->GetWorldSpaceOrParentWorld()));
    }
    if (!m_pImageSpace && reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && !((bool)(reinterpret_cast<::fnv_00454b10::TESObjectCELL *>(this)->GetFakeExterior())))
    {
        m_pImageSpace = dynamic_cast<TESImageSpace*>(((GetFormFn)((FormStub *(&)(unsigned int))::FUN_004839c0))(0x160));
    }
    else if (!m_pImageSpace)
    {
        m_pImageSpace = dynamic_cast<TESImageSpace*>(((GetFormFn)((FormStub *(&)(unsigned int))::FUN_004839c0))(0x161));
    }
    return m_pImageSpace;
}

NiAVObject* FUN_0054f4f0();

// ---- candidate ----
struct SL_ctx2
{
    int item;
    SL_ctx2* next;
};

class AnimGroup
{
  public:
};

class NiControllerSequence
{
  public:
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void v24(void* p);
};

class TESAnimGroup;

class BSAnimGroupSequence : public NiControllerSequence
{
public:
    ::TESAnimGroup *GetAnimGroup() const;
};

class Holder_ctx2
{
  public:
    Holder_ctx2(int, int);
    virtual ~Holder_ctx2();
    char** GetFlag(unsigned int i);
    int m0, m1, m2;
};

struct Q1
{
    int v;
    int q0;
    int q1;
    int r0;
    int r1;
    int r2;
};

struct Q2
{
    const char* msg;
    int r0;
};

struct Q3
{
    int kind;
    int kind2;
    int r0;
};

struct Q4
{
    NiControllerSequence* ref;
    int r0;
    int r1;
    int r2;
    int r3;
    int r4;
};

extern void*(* DAT_00fdf28c)(int, int, int, void*);

class LockCtx
{
  public:
    char pad[0xc];
    int m_iThirdValue;
    void FUN_004d8b90(int arg1, NiControllerSequence* arg2);
};

// @fnv 0x004d8b90
void LockCtx::FUN_004d8b90(int arg1, NiControllerSequence* arg2)
{
    if (arg2)
    {
        Q1 k;
        Q2 ba;
        Q3 b;
        Q4 q;
        Holder_ctx2* f = new Holder_ctx2(0x80, 0x80);
        const char* s;
        k.q0 = 0xffff0002;
        k.q1 = 0x27;
        q.ref = arg2;
        s = 0;
        switch (((int)(reinterpret_cast<::LowProcess *>((arg2))->GetActiveCombatTarget())))
        {
        case 0:
            s = "INACTIVE";
            break;
        case 1:
            s = "ANIMATING";
            break;
        case 2:
            s = "EASEIN";
            break;
        case 3:
            s = "EASEOUT";
            break;
        case 4:
            s = "TRANSSOURCE";
            break;
        case 5:
            s = "TRANSDEST";
            break;
        case 6:
            s = "MORPHSOURCE";
            break;
        }
        BSAnimGroupSequence* cf = dynamic_cast<BSAnimGroupSequence*>(arg2);
        bool p;
        bool h;
        bool a;
        h = false;
        a = false;
        p = false;
        if (cf)
        {
            h = ((bool)(reinterpret_cast<::FUN_00759d80_Class *>((((::AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((cf))->GetAnimGroup()))))->FUN_00759d80()));
            a = ((bool)(::GetMaxOfTwoBytes((unsigned char *)(((::AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((cf))->GetAnimGroup()))))));
            p = ((bool)(::GetMaxByte((unsigned char *)(((::AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((cf))->GetAnimGroup()))))));
        }
        char eb[0x100];
        if (h)
        {
            ::FUN_00406d00(eb, 0x100, "%s: %s, Count: %d, Blend: %0.2f", ((::SL_ctx2 *)(reinterpret_cast<::TESTopicInfoData *>((arg2))->GetLinkToList()))->item, s,
                      ((char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((arg2))->FUN_0084e3a0())), (double)h / 30.0);
        }
        else if (a || p)
        {
            ::FUN_00406d00(eb, 0x100, "%s: %s, Count: %d, BlendIn: %0.2f, BlendOut: %0.2f", ((::SL_ctx2 *)(reinterpret_cast<::TESTopicInfoData *>((arg2))->GetLinkToList()))->item,
                      s, ((char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((arg2))->FUN_0084e3a0())), (double)a / 30.0, (double)p / 30.0);
        }
        else
        {
            ::FUN_00406d00(eb, 0x100, "%s: %s, Count: %d", ((::SL_ctx2 *)(reinterpret_cast<::TESTopicInfoData *>((arg2))->GetLinkToList()))->item, s, ((char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((arg2))->FUN_0084e3a0())));
        }
        ba.msg = ((const char *)(::FUN_00464f30((std::intptr_t)(eb))));
        b.kind = 5;
        b.kind2 = b.kind;
        k.v = arg1;
        k.v = (int)DAT_00fdf28c(m_iThirdValue, 0x1100, 0, &k.v);
        arg1 = k.v;
        arg2->v24(f);
        unsigned int i;
        for (i = 0; i < reinterpret_cast<::FUN_00658930_class *>((f))->GetShortAtOffsetA(); i++)
        {
            ba.msg = ((const char *)(::FUN_00464f30((std::intptr_t)(*f->GetFlag(i)))));
            b.kind = 6;
            b.kind2 = b.kind;
            DAT_00fdf28c(m_iThirdValue, 0x1100, 0, &k.v);
        }
        ::FUN_005e03d0((::NiTArray_Layout *)(f));
        delete f;
    }
}

struct CellFile
{
    void ReadChunkInt(void*);
};

struct CellForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
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
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void LoadBound(CellFile*);
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void SetEditorId(char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};

struct CellFullName
{
    virtual void Slot0();
    unsigned int stringData, stringLength;
};

struct FUN_0058efd0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
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
    FUN_0058efd0();
};

struct CellExtra_ctx2
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};

struct CellString
{
    unsigned int data, size;
};

struct CellExterior
{
};

struct CellInterior
{
};

struct CellEnvironment
{
};

struct CellLoader : CellForm, CellFullName
{
    unsigned char flags;
    unsigned char unk25, unk26, unk27;
    CellExtra_ctx2 extra;
    unsigned int unk48, unk4c, waterHeight, unk54;
    CellString name;
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
    unsigned int lightingTemplate, lightingInheritance;
    bool FUN_005422d0(CellFile* file);
};

// @fnv 0x005422d0
bool CellLoader::FUN_005422d0(CellFile* file)
{
    unsigned char formTypeSlot15 = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formTypeSlot15 != 0x39)
        return false;
    void* savedSourceSlot15 = 0;
    if (reinterpret_cast<::TESFile *>((file))->IsMasterFile())
        savedSourceSlot15 = ((void *)(std::uintptr_t)(reinterpret_cast<::TESFile *>((file))->GetOffset()));
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        int chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0();
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorId = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorId), 512);
            SetEditorId(editorId);
            break;
        }
        case 0x444e424f:  // OBND
        {
            LoadBound(file);
            break;
        }
        case 0x4c4c5546:  // FULL
        {
            ::ReadFullName((::TESFullName *)(::CellFullName *)(static_cast<CellFullName*>(this)), (::TESFile *)(file));
            break;
        }
        case 0x41505058:  // XPPA
        case 0x42475258:  // XRGB
        case 0x424c4758:  // XGLB
        case 0x424d4c58:  // XLMB
        case 0x434d4158:  // XAMC
        case 0x434f4c58:  // XLOC
        case 0x43524d58:  // XMRC
        case 0x44415258:  // XRAD
        case 0x44455358:  // XSED
        case 0x44475258:  // XRGD
        case 0x444f4c58:  // XLOD
        case 0x444f5058:  // XPOD
        case 0x44504158:  // XAPD
        case 0x44524f58:  // XORD
        case 0x44525058:  // XPRD
        case 0x44525358:  // XSRD
        case 0x45535558:  // XUSE
        case 0x46525358:  // XSRF
        case 0x47484358:  // XCHG
        case 0x47525458:  // XTRG
        case 0x49435058:  // XPCI
        case 0x494d4558:  // XEMI
        case 0x49525458:  // XTRI
        case 0x4b4e5258:  // XRNK
        case 0x4b524d41:  // AMRK
        case 0x4b524d4d:  // MMRK
        case 0x4b524d58:  // XMRK
        case 0x4c444558:  // XEDL
        case 0x4c455458:  // XTEL
        case 0x4c4f5358:  // XSOL
        case 0x4c535058:  // XPSL
        case 0x4c545058:  // XPTL
        case 0x4d414e52:  // RNAM
        case 0x4d434358:  // XCCM
        case 0x4d434c58:  // XLCM
        case 0x4d494358:  // XCIM
        case 0x4d495458:  // XTIM
        case 0x4d4c4358:  // XCLM
        case 0x4d525058:  // XPRM
        case 0x4d545258:  // XRTM
        case 0x4e535058:  // XPSN
        case 0x4e574f58:  // XOWN
        case 0x4e5a4558:  // XEZN
        case 0x4f424d58:  // XMBO
        case 0x4f445258:  // XRDO
        case 0x4f4d4358:  // XCMO
        case 0x4f4f5258:  // XROO
        case 0x4f544158:  // XATO
        case 0x50424d58:  // XMBP
        case 0x50434f58:  // XOCP
        case 0x50444e58:  // XNDP
        case 0x504c4358:  // XCLP
        case 0x504c4858:  // XHLP
        case 0x50534558:  // XESP
        case 0x50564e58:  // XNVP
        case 0x52424d58:  // XMBR
        case 0x52434158:  // XACR
        case 0x52434458:  // XDCR
        case 0x524b4c58:  // XLKR
        case 0x524c4358:  // XCLR
        case 0x524d5258:  // XRMR
        case 0x52504158:  // XAPR
        case 0x52575058:  // XPWR
        case 0x53414358:  // XCAS
        case 0x53424958:  // XIBS
        case 0x53445258:  // XRDS
        case 0x53524858:  // XHRS
        case 0x54434158:  // XACT
        case 0x54454358:  // XCET
        case 0x544c4858:  // XHLT
        case 0x544c5758:  // XWLT
        case 0x544d4158:  // XAMT
        case 0x544d4358:  // XCMT
        case 0x544e4358:  // XCNT
        case 0x54574358:  // XCWT
        case 0x57544c58:  // XLTW
        {
            reinterpret_cast<::loader::List *>(&(extra))->LoadExtraData((::loader::File *)(file), this);
            break;
        }
        case 0x574c4358:  // XCLW
        {
            file->ReadChunkInt(&waterHeight);
            break;
        }
        case 0x46504d49:  // IMPF
        case 0x53504d49:  // IMPS
        {
            ::FUN_0058efd0* imageSpace = ((::FUN_0058efd0 *)(std::uintptr_t)(::FUN_0041c460((::BaseExtraList *)(((::CellExtra_ctx2 *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))));
            if (!imageSpace)
            {
                imageSpace = new ::FUN_0058efd0;
                reinterpret_cast<::fnv_0041c390::ExtraDataList2 *>((((::CellExtra_ctx2 *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_0041c390(imageSpace);
            }
            reinterpret_cast<::fnv_0058f180::FUN_0058f180 *>((imageSpace))->Load((::TESFile *)(file));
            break;
        }
        case 0x504d544c:  // LTMP
        {
            unsigned int templateId = 0;
            file->ReadChunkInt(&templateId);
            lightingTemplate = templateId;
            break;
        }
        case 0x4d414e58:  // XNAM
        {
            unsigned int textSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            if (textSize)
            {
                char* text = (char*)_alloca(textSize);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), textSize);
                reinterpret_cast<::TESFullName *>(&(name))->SetFullName(text);
            }
            break;
        }
        case 0x4d414e4c:  // LNAM
        {
            file->ReadChunkInt(&lightingInheritance);
            break;
        }
        case 0x41544144:  // DATA
        {
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 4)
            {
                unsigned int oldFlags = 0;
                file->ReadChunkInt(&oldFlags);
                flags = (unsigned char)oldFlags;
            }
            else
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&flags), 1);
            if (!(flags & 1))
                flags |= 2;
            if ((flags & 1) && (flags & 0x80))
                reinterpret_cast<::FUN_00547440_Class *>(this)->FUN_00547440(DAT_01016970);
            if (!((bool)(reinterpret_cast<::TESObjectCELL *>(((*reinterpret_cast<::CellEnvironment * *>(&::g_dataHandler))))->FUN_00542d20())))
                flags &= ~0x40;
            reinterpret_cast<::FUN_00544630_shell *>(this)->ResetCellData();
            if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && savedSourceSlot15)
                reinterpret_cast<::fnv_0054def0::S *>(this)->SetInteriorDataValue((std::intptr_t)(savedSourceSlot15));
            break;
        }
        case 0x434c4358:  // XCLC
        {
            CellExterior* exterior = ((::CellExterior *)(reinterpret_cast<::FUN_005445d0_shell *>(this)->FUN_005445d0()));
            if (exterior)
            {
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired() && reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() != 12)
                    reinterpret_cast<::S_00462230 *>((exterior))->FUN_00462230();
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(exterior), 12);
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                    reinterpret_cast<::S_00462230 *>((exterior))->FUN_00462230();
            }
            break;
        }
        case 0x4c4c4358:  // XCLL
        {
            CellInterior* interior = ((::CellInterior *)(reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600()));
            if (interior)
            {
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired() && reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() != 44)
                    reinterpret_cast<::SwapBlock *>((interior))->SwapBytes();
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(interior), 44);
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                    reinterpret_cast<::SwapBlock *>((interior))->SwapBytes();
            }
            break;
        }
        }
    } while (reinterpret_cast<::TESFile *>((file))->NextChunk());
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(false);
    return true;
}

NiAVObject* FUN_0054f4f0();

struct TESForm_ctx3
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual TESForm_ctx3* DuplicateForm(bool abCreateEditorID, void* apCopyMap);
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
    virtual void v50(bool);
};

struct TESObjectLAND_ctx3
{
};

class NavMesh
{
};

struct Flt_ctx3
{
    operator unsigned int();
};

struct NavMeshPtr : Flt_ctx3
{
    NavMesh* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NavMeshPtr&);
};

template <class T> struct NiPointer_ctx3
{
    T* m_pObject;
    NiPointer_ctx3(const NavMeshPtr&);
    ~NiPointer_ctx3();
};

struct NavMeshCollection
{
    char data[0x10];
    NavMeshCollection();
    NavMeshPtr GetNavMeshAt(unsigned int);
};


struct S004867a0
{
};

struct CellX_ctx3
{
};

struct CellH_ctx3
{
};

struct RefX
{
};

struct TempIsTemp
{
};

struct SL_ctx3
{
    void* m_item;
    void* m_next;
    SL_ctx3();
};

struct ListX : SL_ctx3
{
    ~ListX();
};

struct List_009e03e0
{
};

struct G2_ctx3
{
    void AddHead(int*);
};

struct LNode
{
    bool FUN_008256d0();
};

struct FUN_005436e0_shell : TESObjectCELL
{
    TESForm_ctx3* FUN_005436e0(bool abCreateEditorID, void* apCopyMap);
};

// @fnv 0x005436e0
TESForm_ctx3* FUN_005436e0_shell::FUN_005436e0(bool abCreateEditorID, void* apCopyMap)
{
    TESObjectCELL* pdupcell = 0;
    if (IsCellInterior())
    {
    }
    else
    {
        BSSimpleList<TESObjectREFR*>* pCurrentElementNext;
        pdupcell = dynamic_cast<TESObjectCELL*>(((::TESForm_ctx3 *)(reinterpret_cast<::FUN_004867a0_cls *>((((S004867a0*)this)))->FUN_004867a0((void *)(false), apCopyMap))));
        TESObjectLAND_ctx3* pland;
        pland = *(TESObjectLAND_ctx3**)&this->unk4c;
        if (pland)
        {
            TESObjectLAND_ctx3* pdupland = dynamic_cast<TESObjectLAND_ctx3*>(((TESForm_ctx3*)pland)->DuplicateForm(false, apCopyMap));
            if (pdupland)
            {
                reinterpret_cast<::n547::Cell *>((((CellX_ctx3*)pdupcell)))->SetObj((::n547::Obj *)(pdupland));
                reinterpret_cast<::fnv_005340e0::TESObjectLAND *>((pdupland))->FUN_005340e0((::fnv_005340e0::TESObjectCELL *)(pdupcell));
                ((TESForm_ctx3*)pdupland)->v50(true);
            }
        }
        if (*(NavMeshCollection**)&this->unk64)
        {
            reinterpret_cast<::FUN_00557760_cls *>((((CellX_ctx3*)pdupcell)))->SetHelper((::Helper_cls *)(::NavMeshCollection *)(new NavMeshCollection));
            NavMeshPtr spmesh;
            for (unsigned int i = 0; i < ((int)(reinterpret_cast<::FUN_00620b80_shell *>((*(NavMeshCollection**)&this->unk64))->GetReferenceFlags())); i++)
            {
                NavMesh* pmesh = (*(NavMeshCollection**)&this->unk64)->GetNavMeshAt(i).m_pObject;
                if (pmesh && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(((RefH*)pmesh)))->FUN_00440d80())
                {
                    NavMesh* pdupMesh = dynamic_cast<NavMesh*>(((TESForm_ctx3*)pmesh)->DuplicateForm(false, apCopyMap));
                    if (pdupMesh)
                    {
                        *(TESObjectCELL**)((char*)pdupMesh + 0x24) = pdupcell;
                        spmesh = *(NavMeshPtr*)&ResultSlot(::MakeNavMeshPointer((::NavMesh *)(pdupMesh)));
                        reinterpret_cast<::NavShell2 *>(((*(NavMeshCollection**)&pdupcell->unk64)))->FUN_00469500((*(::NavMeshPtr *)&(const ::NiPointer_ctx3< ::NavMesh> &)(spmesh)));
                    }
                }
            }
        }
        CellRefLockEnter();
        ListX templist;
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((void **)((void *)(((LNode*)pCurrentElementNext))));
            if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(((TempIsTemp*)pref)))->FUN_004077c0())
            {
                if (IsCellInterior() || reinterpret_cast<::FUN_005516c0 *>((((CellH_ctx3*)this)))->IsCellPersistent() || !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((((RefX*)pref)))->FUN_005653d0())
                    ((G2_ctx3*)&templist)->AddHead((int*)&pref);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((::LNode *)(reinterpret_cast<::Callees *>((((LNode*)pCurrentElementNext)))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)this);
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)&templist;
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((void **)((void *)(((LNode*)pCurrentElementNext))));
            TESObjectREFR* pdupref = dynamic_cast<TESObjectREFR*>(((TESForm_ctx3*)pref)->DuplicateForm(false, apCopyMap));
            if (pdupref)
            {
                reinterpret_cast<::fnv_00565480::RefPersistsStandin *>((((RefX*)pdupref)))->FUN_00565480(reinterpret_cast<::FUN_005516c0 *>((((CellH_ctx3*)pdupcell)))->IsCellPersistent());
                reinterpret_cast<::CellView *>((((CellX_ctx3*)pdupcell)))->FUN_00548230((::RefView *)(pdupref), false);
                ((TESForm_ctx3*)pdupref)->v50(true);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((::LNode *)(reinterpret_cast<::Callees *>((((LNode*)pCurrentElementNext)))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>((((List_009e03e0*)&templist)))->RemoveAll();
    }
    return (TESForm_ctx3*)pdupcell;
}

NiAVObject* FUN_0054f4f0();

class TESForm_ctx4
{
  public:
    virtual ~TESForm_ctx4();
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
public:
    ::TESFile *GetFile(int);
};

class BGSLightingTemplate : public TESForm_ctx4
{
  public:
    virtual ~BGSLightingTemplate();
};

namespace CellLoading {

struct Cell;
struct Reference;
struct Node;
struct Pointer;

struct Name
{
    unsigned int unk0, unk4;
};
struct Extra
{
};

struct Vector
{
    float x, y, z;
};
struct Extras
{
};

struct Reference
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

    virtual void Load();

    virtual void slot8c();

    virtual void slot90();

    virtual void slot94();

    virtual void slot98();

    virtual void slot9c();

    virtual void slota0();

    virtual void slota4();

    virtual void slota8();

    virtual void slotac();

    virtual void slotb0();

    virtual void slotb4();

    virtual void slotb8();

    virtual void slotbc();

    virtual void slotc0();

    virtual void slotc4();

    virtual void slotc8();

    virtual void slotcc();

    virtual void slotd0();

    virtual void slotd4();

    virtual void slotd8();

    virtual void slotdc();

    virtual void slote0();

    virtual void slote4();

    virtual void slote8();

    virtual void slotec();

    virtual void slotf0();

    virtual void slotf4();

    virtual void slotf8();

    virtual void slotfc();

    virtual void slot100();

    virtual void slot104();

    virtual void slot108();

    virtual void slot10c();

    virtual void slot110();

    virtual void slot114();

    virtual void slot118();

    virtual void slot11c();

    virtual void slot120();

    virtual void slot124();

    virtual void slot128();

    virtual void slot12c();

    virtual const char* Name();

};

struct Node
{
    bool FUN_008256d0();
};

struct Pointer
{
    Reference* object;
    Reference* FUN_00458b50();
    ~Pointer();
};
struct Collection
{
    Pointer FUN_00464f60(unsigned int);
};

struct World
{
};

struct Manager
{
};

extern char DAT_0102ece8, DAT_0102ec58, DAT_0102ebd0, DAT_0102eb60, DAT_0102eb10, DAT_01183028, DAT_0118a8d0;


struct Cell : Reference
{

    unsigned int unk4, unk8, unkc, unk10, unk14;
    CellLoading::Name editorName;
    unsigned int unk20, unk24;
    Extra extra;

    void FUN_00542d40();
};

// @fnv 0x00542d40
void Cell::FUN_00542d40()
{

    if (!reinterpret_cast<::TESForm_ctx4 *>(this)->GetInitialized())
    {

        int saved = ::FUN_0046e8a0();
        ::FUN_0043b2b0(1);
        ::FUN_004fffe0(0);
        reinterpret_cast<::fnv_00416be0::ResolveExtraOwner *>(&(extra))->FUN_00416be0((::TESForm *)(::CellLoading::Cell *)(this));
        if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
            reinterpret_cast<::TESFullName *>(&(editorName))->SetFullName((const char *)(0));
        reinterpret_cast<::TESForm_ctx4 *>(this)->SetInitializationState(1);

        if (((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(editorName))->FUN_00408da0())) && std::strlen(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(editorName))->FUN_00408da0()))) > 33)
            ::FUN_005b5e40();

        ::FUN_0043b2b0(0);
        int errors = ::FUN_0046e8a0();
        ::FUN_004fffe0(saved);

        if (errors)
        {
            Cell* other = ((::CellLoading::Cell *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()));
            if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
            {
                if (other)
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
                ::FUN_005b5e40();
        }

        if (((std::uintptr_t)(reinterpret_cast<::FUN_00558b40_shell *>(this)->GetLightingTemplate())))
        {
            unsigned int handle = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::FUN_00558b40_shell *>(this)->GetLightingTemplate()));
            ::ResolveFormID(&handle, (::TESFile *)(((reinterpret_cast<::TESForm_ctx4 *>(this)->GetFile(-1)))));
            BGSLightingTemplate* resolved = dynamic_cast<BGSLightingTemplate*>(::FUN_004839c0(handle));
            reinterpret_cast<::fnv_00558b60::FUN_00558b60_shell *>(this)->FUN_00558b60((::fnv_00558b60::BGSLightingTemplate *)(resolved));
            if (!resolved && handle)
                ::FUN_005b5e40();
        }
    }

    bool oldState = reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(false);
    Node* node = ((::CellLoading::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    Node* previous = 0;

    while (node && !node->FUN_008256d0())
    {
        Reference* reference = *((::CellLoading::Reference **)((void *)(node)));
        if (!reinterpret_cast<::TESForm_ctx4 *>((reference))->GetInitialized())
        {
            reference->Load();
            reinterpret_cast<::fnv_00858730::FUN_00858730_shell *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_00858730((::TESForm *)(reference));
            reinterpret_cast<::SaveLoadGame_8495d0 *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->ApplyUnloadedChanges((::TESForm *)(reference));
        }

        if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<void * *>(&::DAT_011ca254)))
            reinterpret_cast<::FUN_00421a70_shell *>((((::CellLoading::Extras *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00421a70(((::CellLoading::Vector *)(reinterpret_cast<::TESRecipe *>((reference))->GetData()))->z * ::DAT_0101a6b0);

        if (!reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent() && ((::CellLoading::Cell *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())) != this)
        {
            if (previous)
                node = ((::CellLoading::Node *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            else
                node = ((::CellLoading::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        }
        else
        {
            previous = node;
            node = ((::CellLoading::Node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }

    if (((::CellLoading::Collection *)(std::uintptr_t)(::FUN_0070ec90((char *)this))))
    {
        for (unsigned int i = 0; i < reinterpret_cast<::FUN_00620b80_shell *>((((::CellLoading::Collection *)(std::uintptr_t)(::FUN_0070ec90((char *)this)))))->GetReferenceFlags(); i++)
        {
            Pointer item = ((::CellLoading::Collection *)(std::uintptr_t)(::FUN_0070ec90((char *)this)))->FUN_00464f60(i);
            ((::CellLoading::Reference *)(::FUN_00559450((int *)&(item))))->Load();
            reinterpret_cast<::SaveLoadGame_8495d0 *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->ApplyUnloadedChanges((::TESForm *)(::CellLoading::Reference *)(item.FUN_00458b50()));
        }
    }

    reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(oldState);

    if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
    {
        reinterpret_cast<::Manager859 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_00859690((::Cell859 *)(::CellLoading::Cell *)(this));
        if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && ((bool)(reinterpret_cast<::FUN_008727b0_Class *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_008727b0())))
        {
            bool state = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
            reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
            reinterpret_cast<::Cls *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_00858af0((::EntryListNode *)(0), (::Entry *)(0), 0);
            reinterpret_cast<::FUN_0085f850_class *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_0085f850(0);
            reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(state);
        }
    }
}

}

NiAVObject* FUN_0054f4f0();

class Cell_Sub_ctx;

class FUN_00544f60_ctx
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    BSSimpleList<TESObjectREFR*> list4C;
    BSSimpleList<TESObjectREFR*> list54;
    int unk5c, unk60;

    FUN_00544f60_ctx();
};

struct CellC4Holder
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c;
    int f60, f64, f68, f6c, f70, f74, f78, f7c;
    int f80, f84, f88, f8c, f90, f94, f98, f9c;
    int fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc;
    int fc0;
    FUN_00544f60_ctx* unkC4;
};

class BGSSaveLoadGame_ctx
{
  public:
};

class TESForm_ctx
{
  public:
};

class FUN_00569ac0_shell
{
  public:
};

class FUN_005656d0_shell
{
  public:
};

class FUN_0056a250_shell
{
  public:
};

class FUN_00545740_shell
{
  public:
};

class FUN_00545960_shell
{
  public:
};

class FUN_00587870_shell
{
  public:
};

class BSSimpleList_standin
{
  public:
    void FUN_0063f7b0();
};

class PolymorphicRef
{
  public:
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
};

class CellSubTarget
{
  public:
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
    virtual void Unk_37(CellSubTarget* a, int val);
};

class Cell_Sub_ctx : public TESObjectCELL
{
  public:
    void FUN_00544ce0();
};

// @fnv 0x00544ce0
void Cell_Sub_ctx::FUN_00544ce0()
{
    if (((CellC4Holder*)this)->unkC4 == 0)
    {
        ((CellC4Holder*)this)->unkC4 = new FUN_00544f60_ctx();
    }
    CellRefLockEnter();
    BSSimpleList<TESObjectREFR*> localList9;
    BSSimpleList<TESObjectREFR*>* iter = (BSSimpleList<TESObjectREFR*>*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (iter != 0 && !iter->FUN_008256d0())
    {
        TESObjectREFR* item5 = (iter->item);
        iter = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)(((TESForm_ctx*)item5)))->FUN_00440d80() || reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((::g_BGSSaveLoadGame))->FUN_0042ce10())
        {
            if (((::FUN_00439f90_shell*)item5)->FUN_00439f90())
            {
                reinterpret_cast<::CellLike *>((((FUN_00545740_shell*)this)))->GetOrCreateFaceGenNode((::RefForm *)(item5));
                if (reinterpret_cast<::fnv_00569ac0::FUN_00569ac0_shell *>((((FUN_00569ac0_shell*)item5)))->FUN_00569ac0())
                {
                    localList9.AddHead(item5);
                }
            }
            else
            {
                if (!((PolymorphicRef*)item5)->Unk_40())
                {
                    if (reinterpret_cast<::fnv_005656d0::Thing *>((((FUN_005656d0_shell*)item5)))->FUN_005656d0())
                    {
                        ((CellC4Holder*)this)->unkC4->list4C.AddHead(item5);
                    }
                }
                if (reinterpret_cast<::fnv_0056a250::FUN_0056a250_shell *>((((FUN_0056a250_shell*)item5)))->FUN_0056a250())
                {
                    ((CellC4Holder*)this)->unkC4->list54.AddHead(item5);
                }
            }
        }
    }
    ::FUN_00541ae0((char *)this);
    while (!localList9.FUN_008256d0())
    {
        TESObjectREFR* item3 = (localList9.item);
        ((BSSimpleList_standin*)&localList9)->FUN_0063f7b0();
        TESObjectREFR* other = reinterpret_cast<::fnv_00569ac0::FUN_00569ac0_shell *>((((FUN_00569ac0_shell*)item3)))->FUN_00569ac0();
        CellSubTarget* a8 = (CellSubTarget*)reinterpret_cast<::fnv_00545960::S *>((((FUN_00545960_shell*)this)))->FUN_00545960((::fnv_00545960::A *)(item3));
        CellSubTarget* b2 = (CellSubTarget*)reinterpret_cast<::fnv_00545960::S *>((((FUN_00545960_shell*)this)))->FUN_00545960((::fnv_00545960::A *)(other));
        if (a8 != b2)
        {
            b2->Unk_37(a8, 1);
        }
    }
    TESWorldSpace* extra9 = GetParentWorldSpace();
    if (extra9 != 0)
    {
        iter = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::fnv_00587870::OverlapHolder *>((((FUN_00587870_shell*)extra9)))->FUN_00587870((::fnv_00587870::CellH *)(::TESObjectCELL *)(this))));
        while (iter != 0 && !iter->FUN_008256d0())
        {
            reinterpret_cast<::CellLike *>((((FUN_00545740_shell*)this)))->GetOrCreateFaceGenNode((::RefForm *)((iter->item)));
            iter = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        }
    }
}

NiAVObject* FUN_0054f4f0();

class TES
{
  public:
};

struct ModelLoader
{
};

class TESBoundObject_decl : public TESForm
{
};

class TESObjectSTAT : public TESBoundObject_decl
{
};

// TESObjectREFR virtual slots used below, as in the original unit's declaration (Set3D at slot 115, GetNiNode at 116).
struct RefSlotView
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
    virtual void Set3D(NiNode* node, bool queue);
    virtual NiNode* GetNiNode();
};

// @fnv 0x005571a0
void TESObjectCELL::FUN_005571a0(bool active)
{
    CellRefLockEnter();
    void* list = ((void *)(reinterpret_cast<::LodGrid *>((((::TES *)::g_TES)))->FUN_00458be0((::LodCell *)(::TESObjectCELL *)(this), (::LodPoint *)(0))));
    BSSimpleList<TESObjectREFR*>* terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (terrain)
    {
        TESObjectREFR* reference = (terrain->item);
        if (reference && (((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == DAT_011ca238 || ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == DAT_011ca230))
        {
            if (!((RefSlotView*)reference)->GetNiNode() || reinterpret_cast<::FUN_005651e0_shell *>((reference))->FUN_005651e0())
            {
                if (!reinterpret_cast<::TESForm *>(reference)->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((reference))->FUN_00440d80() && (!active || reinterpret_cast<::B56B250Ref *>((reference))->FUN_0056b250()))
                    reinterpret_cast<::ML *>((::g_modelLoader))->FUN_00444850((::Ref *)(reference), (std::intptr_t)(list), 1);
            }
            else
            {
                if (reinterpret_cast<::TESForm *>(reference)->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((reference))->FUN_00440d80())
                    ((RefSlotView*)reference)->Set3D(0, true);
            }
        }
        terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((terrain))->FUN_00726070()));
    }
    terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (terrain)
    {
        TESObjectREFR* other = (terrain->item);
        if (other && ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((other))->FUN_007af430())) != DAT_011ca238 && ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((other))->FUN_007af430())) != DAT_011ca230)
        {
            if (!((RefSlotView*)other)->GetNiNode() || reinterpret_cast<::FUN_005651e0_shell *>((other))->FUN_005651e0())
            {
                if (!reinterpret_cast<::TESForm *>(other)->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((other))->FUN_00440d80() && (!active || reinterpret_cast<::B56B250Ref *>((other))->FUN_0056b250()))
                    reinterpret_cast<::ML *>((::g_modelLoader))->FUN_00444850((::Ref *)(other), (std::intptr_t)(list), 1);
            }
            else
            {
                if (reinterpret_cast<::TESForm *>(other)->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((other))->FUN_00440d80())
                    ((RefSlotView*)other)->Set3D(0, false);
            }
        }
        terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((terrain))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}

NiAVObject* FUN_0054f4f0();

struct ExpiredRefPosition3
{
    float x, y, z;
};

class TESBoundObject_iso
{
  public:
    virtual ~TESBoundObject_iso();
    int FUN_00401170();
};

struct BGSSaveLoadGame_iso
{
};

struct RefNode_iso;

struct RefrShell;

struct ExtraShell;

struct ZoneShell
{
};

struct Modelish
{
};

struct RefNode_iso
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};

struct Inner3c
{
    virtual void v0();
    virtual bool v1();
};

class IngredientItem : public TESBoundObject_iso
{
  public:
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

    Inner3c m3c;
};

struct Obj34
{
};

struct ExtraShell : public ExtraDataList
{
};

struct RefrShell : public TESObjectREFR
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
    virtual void V49(int a);
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
    virtual bool V64();
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
    virtual bool V88();
    virtual void v89();
    virtual void v90();
    virtual ExpiredRefPosition3 V91();
    virtual void V92(ExpiredRefPosition3* p);
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void V130(bool b);
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool V139(int a);
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void* V165();
    virtual void* V166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void V201(int a, int b, int c);
    ZoneShell* FUN_00567d20();
    void FUN_00575700(ExpiredRefPosition3 p);
};

struct Calendar_iso
{
public:
    unsigned int GetGameHoursPassed();
};

struct DHShell : public TESDataHandler
{
};

struct CellShell_iso : public FUN_00546af0_shell
{
    bool FUN_0054df30();
};

// @fnv 0x0054df30
bool CellShell_iso::FUN_0054df30()
{
    if (((unsigned char)(reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((g_BGSSaveLoadGame))->FUN_0042ce10())))
        return false;
    unsigned long _type;
    bool _changed;
    bool _allowed;
    ZoneShell* _special;
    unsigned int _oldState;
    RefNode_iso* _item;
    bool _done;
    _oldState = reinterpret_cast<::Calendar_iso *>(&((*reinterpret_cast<::Calendar_iso *>(&::g_011de7b8))))->GetGameHoursPassed();
    _changed = 0;
    _done = 0;
    _type = FUN_00546af0();
    if (_type == 0)
    {
        CellRefLockEnter();
        RefNode_iso* a;
        a = ((::RefNode_iso *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        for (; 0 != a && !a->FUN_008256d0();)
        {
            RefrShell* flag6;
            flag6 = *((::RefrShell **)((void *)(a)));
            a = ((::RefNode_iso *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
            switch (((::TESBoundObject_iso *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((flag6))->FUN_007af430()))->FUN_00401170())
            {
            case 0x1b:
                if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((flag6))->FUN_005653d0())
                {
                    flag6->V130(!reinterpret_cast<::FUN_0056ae60_Class *>((flag6))->FUN_0056ae60());
                }
                break;
            case 0x2a:
            case 0x2b:
                if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((flag6))->FUN_005653d0())
                {
                    RefrShell* c;
                    c = flag6;
                    if (reinterpret_cast<::FUN_00881c90_cls *>((c))->IsExpired(_oldState))
                    {
                        flag6->V130(!reinterpret_cast<::FUN_0056ae60_Class *>((flag6))->FUN_0056ae60());
                    }
                }
                break;
            }
        }
        ::FUN_00541ae0((char *)this);
        return true;
    }
    _allowed = 0;
    _special = ((::ZoneShell *)(reinterpret_cast<::TESObjectCELL *>(this)->FindEncounterZone()));
    if (_type == 0xffffffff)
    {
        _changed = 1;
        _done = 1;
        _allowed = 1;
    }
    else
    {
        if (_oldState - _type > ((unsigned int)(::fnv_00526100::FUN_00526100())))
            _allowed = 1;
        if (0 != _special)
        {
            if (::FUN_005262a0((::BGSEncounterZone *)(_special)))
                _changed = reinterpret_cast<::FUN_00526120_shell *>((_special))->FUN_00526120(this);
            else
                _changed = 0;
        }
        else
        {
            _changed = _allowed;
        }
    }
    CellRefLockEnter();
    {
        _item = ((::RefNode_iso *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        for (; 0 != _item && !_item->FUN_008256d0();)
        {
            RefrShell* refr2;
            refr2 = *((::RefrShell **)((void *)(_item)));
            _item = ((::RefNode_iso *)(reinterpret_cast<::Callees *>((_item))->FUN_00726070()));
            if (_done && reinterpret_cast<::BSShaderRenderUtility *>((((DHShell*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((refr2))->FUN_0084e3a0()))))
            {
                if (!refr2->V88() && !reinterpret_cast<::s577de0::Owner *>((refr2))->FUN_00577de0())
                    refr2->V49(1);
                continue;
            }
            RefrShell* cnt;
            cnt = 0;
            if (refr2->V64())
                cnt = refr2;
            if (0 != cnt)
            {
                if (!reinterpret_cast<::FUN_00881c90_cls *>((cnt))->IsExpired(_oldState))
                    continue;
            }
            else
            {
                if (_allowed)
                {
                    if (reinterpret_cast<::FUN_00452370_shell *>((refr2))->FUN_00452370())
                    {
                        Obj34* v;
                        v = ((::Obj34 *)(::FUN_00475400(((::TESBoundObject_iso *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr2))->FUN_007af430())))));
                        reinterpret_cast<::FUN_00477090_Owner *>((v))->UpdateSoundLevel((::FUN_00477090_Ref *)(refr2));
                        if (!!((void *)(reinterpret_cast<::FUN_0042e250_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))))->FUN_0042e250())))
                            reinterpret_cast<::FUN_00484610_shell *>((refr2))->SetFlag2000(true);
                    }
                }
                ZoneShell* q;
                q = refr2->FUN_00567d20();
                if (q != _special)
                {
                    if (q)
                    {
                        if (!::FUN_005262a0((::BGSEncounterZone *)(q)))
                            continue;
                    }
                }
                else
                {
                    if (!_changed)
                        continue;
                }
            }
            if (0 != cnt)
            {
                if (reinterpret_cast<::Actor_0087f4a0 *>((cnt))->FUN_0087f4a0())
                {
                    cnt->V201(1, 0, 0);
                    RefNode_iso* i;
                    i = ((::RefNode_iso *)(reinterpret_cast<::FUN_0041df90_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041df90()));
                    if (0 != i)
                    {
                        for (; 0 != i && !i->FUN_008256d0();)
                        {
                            RefrShell* tmp;
                            tmp = *((::RefrShell **)((void *)(i)));
                            reinterpret_cast<::FUN_0041de40_class *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((tmp))->FUN_005d43c0()))))->FUN_0041de40((::TESObjectREFR *)(0));
                            if (!tmp->V88())
                                reinterpret_cast<::B572270Object *>((tmp))->FUN_00572270();
                            i->FUN_0063f7b0();
                        }
                        reinterpret_cast<::FUN_0041dfd0_Shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041dfd0();
                    }
                    ExpiredRefPosition3 b;
                    cnt->V92(&b);
                    bool s;
                    s = 0;
                    if (cnt->V166() == this)
                    {
                        s = 1;
                    }
                    else
                    {
                        if (cnt->V165() == ((void *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())))
                        {
                            if (reinterpret_cast<::fnv_00550200::FUN_00550200 *>(this)->IsPointInCell((*(const ::fnv_00550200::NiPoint3 *)(&b))))
                                s = 1;
                        }
                    }
                    if (s)
                    {
                        reinterpret_cast<::Reference *>((cnt))->FUN_00575830((::Position *)(::ExpiredRefPosition3 *)(&b));
                        cnt->FUN_00575700(cnt->V91());
                    }
                }
                else
                {
                    if (cnt->V139(0))
                    {
                        if (!cnt->V88() && !reinterpret_cast<::s577de0::Owner *>((cnt))->FUN_00577de0())
                        {
                            reinterpret_cast<::B572270Object *>((cnt))->FUN_00572270();
                            RefrShell* x;
                            x = ((::RefrShell *)(reinterpret_cast<::FUN_0041e310_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041e310()));
                            if (!!x)
                                reinterpret_cast<::B572270Object *>((x))->FUN_00572270();
                        }
                        RefNode_iso* p;
                        p = ((::RefNode_iso *)(reinterpret_cast<::FUN_0041df90_shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041df90()));
                        if (!!p)
                        {
                            for (; p && !p->FUN_008256d0();)
                            {
                                RefrShell* y;
                                y = *((::RefrShell **)((void *)(p)));
                                reinterpret_cast<::FUN_0041de40_class *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((y))->FUN_005d43c0()))))->FUN_0041de40((::TESObjectREFR *)(0));
                                if (!y->V88())
                                    reinterpret_cast<::B572270Object *>((y))->FUN_00572270();
                                p->FUN_0063f7b0();
                            }
                            reinterpret_cast<::FUN_0041dfd0_Shell *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((cnt))->FUN_005d43c0()))))->FUN_0041dfd0();
                        }
                    }
                }
            }
            else
            {
                switch (((::TESBoundObject_iso *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr2))->FUN_007af430()))->FUN_00401170())
                {
                case 0x1b:
                    if (reinterpret_cast<::FUN_0056ae60_Class *>((refr2))->FUN_0056ae60())
                    {
                        refr2->V130(0);
                        if (!!((::Modelish *)(reinterpret_cast<::ExtraDataList *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))))->GetContainerChangeData())))
                        {
                            if (!reinterpret_cast<::FUN_0042cde0_shell *>((((::Modelish *)(reinterpret_cast<::ExtraDataList *>((((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))))->GetContainerChangeData()))))->FUN_0042cde0())
                                reinterpret_cast<::FUN_00569250_shell *>((refr2))->FUN_00569250();
                        }
                    }
                    break;
                case 0x26:
                    reinterpret_cast<::FUN_00484580_shell *>((refr2))->FUN_00484580(false);
                    break;
                case 0x1d:
                    if (reinterpret_cast<::FUN_00440d80_shell *>((refr2))->FUN_00440d80() && !reinterpret_cast<::FUN_00565450_shell *>((refr2))->FUN_00565450() && !refr2->V88())
                    {
                        IngredientItem* j;
                        j = dynamic_cast<IngredientItem*>(((::TESBoundObject_iso *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr2))->FUN_007af430())));
                        if (0 != j)
                        {
                            if (j->m3c.v1())
                                refr2->V49(0);
                        }
                    }
                    break;
                }
            }
            ::FUN_005ac190((::TESObjectREFR *)(refr2), (::ExtraDataList *)(::ExtraShell *)(((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))));
            ::FUN_005ac750((::TESForm *)(refr2), (::ExtraDataList *)(::ExtraShell *)(((::ExtraShell *)(reinterpret_cast<::FUN_005d43c0_ *>((refr2))->FUN_005d43c0()))), 0x80000000);
        }
    }
    ::FUN_00541ae0((char *)this);
    reinterpret_cast<::fnv_00546b10::FUN_00546b10_class *>(this)->UpdateCellExtraData((::BSExtraData *)(0), false);
    return _changed;
}

NiAVObject* FUN_0054f4f0();

struct FUN_00b5a9a0_Node
{
    void* m_pListObject;
    void* m_pNext;
    unsigned int m_uiCount;
};

struct FUN_00b5a9a0_List_o2
{
    FUN_00b5a9a0_Node* m_pHead;
    FUN_00b5a9a0_Node* m_pTail;
    unsigned int m_uiCount;
    void FUN_00b5a9a0(FUN_00b5a9a0_Node* node);
};

// @fnv 0x00b5a9a0
void FUN_00b5a9a0_List_o2::FUN_00b5a9a0(FUN_00b5a9a0_Node* node)
{
    node->m_pListObject = 0;
    node->m_pNext = m_pTail;
    if (m_pTail)
    {
        m_pTail->m_pListObject = node;
        ++m_uiCount;
        m_pTail = node;
    }
    else
    {
        ++m_uiCount;
        m_pHead = node;
        m_pTail = node;
    }
}

struct FUN_00bb39e0_shell
{
    int m_00;
    int m_04;
    void* m_08;
    void FUN_00bb39e0(const void* src, unsigned int count);
};

// @fnv 0x00bb39e0
void FUN_00bb39e0_shell::FUN_00bb39e0(const void* src, unsigned int count)
{
    if (src && m_08)
    {
        if (count)
        {
            if (count >= 192)
                count = 192;
            std::memmove(m_08, src, count * 4);
            if (count < 192)
                std::memset((char*)m_08 + count * 4, 0, (192 - count) * 4);
        }
    }
}

NiAVObject* FUN_0054f4f0();

struct FUN_00b5a9a0_Node_o2_od_oy_noo2
{
    void* m_pListObject;
    void* m_pNext;
    unsigned int m_uiCount;
};

struct FUN_00b5a9a0_List_o2_od_oy_noo2
{
    FUN_00b5a9a0_Node_o2_od_oy_noo2* m_pHead;
    FUN_00b5a9a0_Node_o2_od_oy_noo2* m_pTail;
    unsigned int m_uiCount;
    void FUN_00b5a9a0(FUN_00b5a9a0_Node_o2_od_oy_noo2* node);
};

void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

void* __cdecl _fnv_zlib_memset(void* ptr, int value, unsigned int count);

struct FUN_00bb39e0_shell_o2_od_oy_noo2
{
    int m_00;
    int m_04;
    void* m_08;
    void FUN_00bb39e0(const void* src, unsigned int count);
};

struct FUN_004a3c90
{
    __m128 m_00;
    FUN_004a3c90(const FUN_004a3c90& src);
};

// @fnv 0x004a3c90
FUN_004a3c90::FUN_004a3c90(const FUN_004a3c90& src)
{
    m_00 = src.m_00;
}

struct FUN_005532a0_cls
{
    __m128 m_v;
    FUN_005532a0_cls* FUN_005532a0(float a1, float a2, float a3, float a4);
};

// @fnv 0x005532a0
FUN_005532a0_cls* FUN_005532a0_cls::FUN_005532a0(float a1, float a2, float a3, float a4)
{
    m_v = _mm_setr_ps(a1, a2, a3, a4);
    return this;
}

NiAVObject* FUN_0054f4f0();

inline double NiAbs(float fValue)
{
    return (float)std::fabs(fValue);
}

inline float NiFunc(float fValue)
{
    return (float)std::cos(fValue);
}

__forceinline double AbsRef(const float& value)
{
    return (float)std::fabs(value);
}
__forceinline float ComputeAbs(const float& y)
{
    float arg1 = y;
    float context = AbsRef(arg1);
    return context;
}

struct NiPoint3_ob1
{
    float x, y, z;
    NiPoint3_ob1()
    {}
    NiPoint3_ob1(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    void Set(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3_ob1 operator-(float f) const
    {
        return NiPoint3_ob1(x - f, y - f, z - f);
    }
};

struct NiPoint3Ex : NiPoint3_ob1
{
    NiPoint3Ex operator-(const NiPoint3_ob1& b) const
    {
        NiPoint3Ex result;
        result.x = x - b.x;
        result.y = y - b.y;
        result.z = z - b.z;
        return result;
    }
};

struct FUN_004b4600_Class
{
    void FUN_004b4600();
};

struct M_004b4500 : FUN_004b4600_Class
{
    union
    {
        struct
        {
            float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        };
        float entry[3][3];
    };
    M_004b4500 Inverse()
    {
        M_004b4500 inverse;
        if (!reinterpret_cast<::ThreeByThreeMatrix *>(this)->Inverse((*(::ThreeByThreeMatrix *)(&inverse))))
            inverse.FUN_004b4600();
        return inverse;
    }
    NiPoint3_ob1 FUN_004b4500(const NiPoint3_ob1* p)
    {
        NiPoint3_ob1 result;
        result.x = m00 * p->x + m01 * p->y + m02 * p->z;
        result.y = m10 * p->x + m11 * p->y + m12 * p->z;
        result.z = m20 * p->x + m21 * p->y + m22 * p->z;
        return result;
    }
};

struct SphereInput : NiPoint3Ex
{
    float radius;
};

struct BoxInput_ob1
{
    unsigned int kind;
    unsigned int flags;
    NiPoint3_ob1 center;
    float halfWidth;
    float halfDepth;
    M_004b4500 rotation;
    unsigned char FUN_00c34890(const SphereInput* sphere);
};

// @fnv 0x00c34890
unsigned char BoxInput_ob1::FUN_00c34890(const SphereInput* sphere)
{
    float halfA;
    M_004b4500 rotationB = rotation.Inverse();
    NiPoint3_ob1 point7 = rotationB.FUN_004b4500(&ResultSlot(*sphere - center));
    NiPoint3_ob1 bound;
    float radius6;
    {
        point7.x = NiAbs(point7.x);
        point7.y = NiAbs(point7.y);
        point7.z = NiAbs(point7.z);
        radius6 = sphere->radius;
        reinterpret_cast<::FUN_00416870_t *>(&(bound))->FUN_00416870(point7.x - radius6, point7.y - radius6, point7.z - radius6);
    }
    if (!(bound.x <= halfWidth) || !(bound.z <= halfDepth) || !(bound.y <= 0.0))
        return false;
    halfA = radius6 * NiFunc(ComputeAbs(bound.y) / radius6);
    return (point7.x - halfA <= halfWidth && point7.y - halfA <= halfDepth) ? 1 : 0;
}

extern int(* DAT_00fdf1c0)(void*);

extern int(* DAT_00fdf1c4)(void*);

class NiRefObject
{
  public:
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        DAT_00fdf1c0(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!DAT_00fdf1c4(&m_uiRefCount))
            DeleteThis();
    }
};

template <class T> struct NiPointer_ob1
{
    T* m_pObject;
    NiPointer_ob1(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer_ob1(const NiPointer_ob1& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_ob1()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer_ob1& FUN_0066b0d0(T* pObject);
};

template <class T> struct NiTListItem_ob1
{
    NiTListItem_ob1* m_pkNext;
    NiTListItem_ob1* m_pkPrev;
    T m_element;
};

typedef NiTListItem_ob1<NiPointer_ob1<NiRefObject> > Item_ob1;

struct NiTPointerAllocator
{
    unsigned int m_uiCount;
};

struct NiTPointerListBase_ob1
{
    Item_ob1* m_pkHead;
    Item_ob1* m_pkTail;
    NiTPointerAllocator m_kItemCount;
    NiPointer_ob1<NiRefObject> FUN_00c5c160();
    NiPointer_ob1<NiRefObject> FUN_00c5c290();
    void DeleteItem(Item_ob1* pkItem)
    {
        int unused[5];  // compiled-out debug locals of the inlined helper
        pkItem->m_element.FUN_0066b0d0(0);
        reinterpret_cast<::FUN_0045cee0_shell *>(&(m_kItemCount))->FUN_0045cee0(pkItem);
        m_kItemCount.m_uiCount--;
    }
    NiPointer_ob1<NiRefObject> FUN_00c5bfb0(Item_ob1*& kPos);
};

// @fnv 0x00c5bfb0
NiPointer_ob1<NiRefObject> NiTPointerListBase_ob1::FUN_00c5bfb0(Item_ob1*& kPos)
{
    Item_ob1* pkNode = kPos;
    if (pkNode == m_pkHead)
    {
        kPos = pkNode->m_pkNext;
        return FUN_00c5c160();
    }
    if (pkNode == m_pkTail)
    {
        kPos = 0;
        return FUN_00c5c290();
    }
    Item_ob1* pkPrev = pkNode->m_pkPrev;
    Item_ob1* pkNext = pkNode->m_pkNext;
    kPos = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    NiPointer_ob1<NiRefObject> element = pkNode->m_element;
    DeleteItem(pkNode);
    return element;
}

// Removes the item at position through 0x00c5bfb0 and releases the returned pointer, for units whose
// layout_support.h declares NiTPointerListBase as a template.
void RemovePointerListPos(void* list, void*& position)
{
    reinterpret_cast<NiTPointerListBase_ob1*>(list)->FUN_00c5bfb0(*reinterpret_cast<Item_ob1**>(&position));
}

struct RefObj5b
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class SmartPtr5b
{
  public:
    T* m_pObject;

    SmartPtr5b(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SmartPtr5b()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    SmartPtr5b& FUN_006e5cc0(const SmartPtr5b& rhs)
    {
        if (m_pObject != rhs.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = rhs.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ListItem5b
{
    ListItem5b* m_pNext;
    ListItem5b* m_pListObject;
    SmartPtr5b<RefObj5b> m_element;
};

struct Alloc5b
{
};

struct List5b
{
    ListItem5b* m_pHead;
    ListItem5b* m_pTail;
    Alloc5b m_kItemCount;

    ListItem5b* GetHeadPos() const
    {
        return m_pHead;
    }
    RefObj5b* GetNext(ListItem5b*& pos) const
    {
        RefObj5b* const& e = pos->m_element.m_pObject;
        pos = pos->m_pNext;
        return e;
    }


    void AddHead(const SmartPtr5b<RefObj5b>& element)
    {
        ListItem5b* pkNode = ((::ListItem5b *)(reinterpret_cast<::FUN_0043a010_shell *>(&(m_kItemCount))->FUN_0043a010()));
        pkNode->m_element.FUN_006e5cc0(element);
        reinterpret_cast<::FUN_00b5a9a0_List *>(this)->FUN_00b5a9a0((::FUN_00b5a9a0_Node *)(pkNode));
    }

    SmartPtr5b<RefObj5b> FUN_00c5bfb0(ListItem5b*& pos);
};

struct Owner5b_ob1
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
    List5b m_list50;
    List5b m_list5c;
    void FUN_00c5b1c0(RefObj5b* p);
};

// @fnv 0x00c5b1c0
void Owner5b_ob1::FUN_00c5b1c0(RefObj5b* p)
{
    if (!p)
        return;
    EnterCriticalSection(&(*reinterpret_cast<::_RTL_CRITICAL_SECTION *>(&::DAT_01203328)));
    ListItem5b* pos = m_list50.GetHeadPos();
    while (pos)
    {
        RefObj5b* cur = m_list50.GetNext(pos);
        if (cur == p)
            break;
    }
    if (!pos)
    {
        m_list50.AddHead(p);
        pos = m_list5c.GetHeadPos();
        while (pos)
        {
            ListItem5b* saved2 = pos;
            RefObj5b* cur = m_list5c.GetNext(pos);
            if (cur == p)
            {
                m_list5c.FUN_00c5bfb0(saved2);
            }
        }
    }
    LeaveCriticalSection(&(*reinterpret_cast<::_RTL_CRITICAL_SECTION *>(&::DAT_01203328)));
}

namespace fnv_00c5b370 {

struct RefObject
{
    virtual ~RefObject();
    virtual void DeleteThis();
    long refCount;

    inline void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    inline void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer_ob1
{
  public:
    T* m_p;
    inline NiPointer_ob1(T* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    inline ~NiPointer_ob1()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    inline operator T*() const
    {
        return m_p;
    }
    inline NiPointer_ob1& operator=(const NiPointer_ob1& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};

struct ItemNode
{
    ItemNode* next;
    ItemNode* prev;
    NiPointer_ob1<RefObject> item;
};

struct NodePool
{
};

struct ItemList
{
    int unk00;
    int unk04;
    NodePool pool;
    inline void AddTail(const NiPointer_ob1<RefObject>& ref)
    {
        ItemNode* pNode = ((::fnv_00c5b370::ItemNode *)(reinterpret_cast<::FUN_0043a010_shell *>(&(pool))->FUN_0043a010()));
        pNode->item = ref;
        reinterpret_cast<::FUN_00b5a9a0_List *>(this)->FUN_00b5a9a0((::FUN_00b5a9a0_Node *)(pNode));
    }
};

struct PendingList
{
    ItemNode* head;
    NiPointer_ob1<RefObject> FUN_00c5bfb0(ItemNode** iter);
    inline ItemNode* GetHead() const
    {
        return head;
    }
    inline NiPointer_ob1<RefObject>& GetNext(ItemNode*& iter)
    {
        NiPointer_ob1<RefObject>& item = iter->item;
        iter = iter->next;
        return item;
    }
};


struct ItemQueue_ob1
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
    PendingList pending;
    int unk54;
    int unk58;
    ItemList items;
    void FUN_00c5b370(RefObject* obj);
};

// @fnv 0x00c5b370
void ItemQueue_ob1::FUN_00c5b370(RefObject* obj)
{
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&::DAT_01203328));
    items.AddTail(obj);
    RefObject* p;
    ItemNode* it;
    ItemNode* cur;
    it = pending.GetHead();
    while (it)
    {
        cur = it;
        p = pending.GetNext(it);
        if (p == obj)
        {
            pending.FUN_00c5bfb0(&cur);
            break;
        }
    }
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&::DAT_01203328));
}
}

NiAVObject* FUN_0054f4f0();

class TESFormB54
{
  public:
    int FUN_00401170();
};

class TESObjectREFRB54
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool IsVf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual int IsVf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual bool IsVf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void Vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void Vf260();
};

class Actor : public TESObjectREFRB54
{
};

struct NiPoint3B54
{
    NiPoint3B54(float fX, int iY, int iZ);
    float x, y, z;
};

struct ControllerB54
{
};

struct NodeB54
{
};

class SceneB54;

struct ManagerB54
{
};

struct SettingsB54
{
};

struct ModeB54
{
};

struct ProcessListB54
{
};

struct LoaderB54
{
};

class SceneB54
{
  public:
    void FUN_0054bcf0(bool bArg);
};

// @fnv 0x0054bcf0
void SceneB54::FUN_0054bcf0(bool bArg)
{
    ControllerB54* pController2 = ((::ControllerB54 *)(reinterpret_cast<::FUN_00545cf0_Cls *>(this)->GetOrCreateWidget()));
    reinterpret_cast<::fnv_0054c740::FUN_0054c740_shell *>(this)->FUN_0054c740(0, 0);
    bool bState5 = reinterpret_cast<::CellShell *>(this)->FUN_0054df30();
    reinterpret_cast<::fnv_00550c60::FUN_00550c60_shell *>(this)->RecalcLeveledActorBases(bState5);
    if (reinterpret_cast<::FUN_00453490_shell *>((((ManagerB54*)((::ManagerB54 *)::g_TES))))->FUN_00453490((::TESObjectCELL *)(::SceneB54 *)(this)))
    {
        if (pController2)
        {
            NiPoint3B54 kPoint_(0.0f, 0, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((pController2))->FUN_00a59c60((std::intptr_t)(&kPoint_));
        }
        reinterpret_cast<::fnv_0054bc10::CellStub *>(this)->ProcessCellReferences();
    }
    else
    {
        reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
        int iPass4;
        void* pCell9 = ((void *)(reinterpret_cast<::LodGrid *>((((ManagerB54*)((::ManagerB54 *)::g_TES))))->FUN_00458be0((::LodCell *)(::SceneB54 *)(this), (::LodPoint *)(0))));
        NodeB54* pNode5 = ((::NodeB54 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        int iCountA = 0;
        iPass4 = 0;
        while (iPass4 < 2 && pNode5)
        {
            TESObjectREFRB54* pRef = *((::TESObjectREFRB54 **)((void *)(pNode5)));
            pNode5 = ((::NodeB54 *)(reinterpret_cast<::Callees *>((pNode5))->FUN_00726070()));
            if (!pNode5)
            {
                iPass4++;
                if (iPass4 < 2)
                    pNode5 = ((::NodeB54 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
            }
            if (pRef)
            {
                bool bSpecial_2 = ((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) &&
                                  (((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) == (*reinterpret_cast<::TESFormB54 * *>(&::DAT_011ca238)) || ((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) == (*reinterpret_cast<::TESFormB54 * *>(&::DAT_011ca230)));
                if (iPass4 == 0 && !bSpecial_2)
                    continue;
                if (iPass4 == 1 && bSpecial_2)
                    continue;
                iCountA++;
                if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::SettingsB54 * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                {
                    ::FUN_005ac190((::TESObjectREFR *)(pRef), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((pRef))->FUN_005d43c0()));
                    ::FUN_005ac750((::TESForm *)(pRef), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((pRef))->FUN_005d43c0()), 0x1000);
                }
                bool bDisabled4 = false;
                bDisabled4 = reinterpret_cast<::TESForm *>((pRef))->GetDisabled();
                if (!bDisabled4 && !reinterpret_cast<::FUN_00440d80_shell *>((pRef))->FUN_00440d80())
                {
                    if (pRef->IsVf100() && (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::ModeB54 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() || reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::ModeB54 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition()))
                    {
                        Actor* pActor7 = ((Actor*)(reinterpret_cast< ::TESObjectREFR*>(pRef)));
                        if (pActor7)
                        {
                            pActor7->Vf240();
                            reinterpret_cast<::ProcessLists *>((((ProcessListB54*)&(*reinterpret_cast<::ProcessListB54 *>(&::g_011e0e80)))))->RemoveMobileObjectFromList((::MobileObject *)(pActor7));
                        }
                    }
                    else if (pRef->IsVf224())
                    {
                        TESObjectREFRB54* pTarget = pRef;
                        pTarget->Vf260();
                    }
                    reinterpret_cast<::ML *>((((LoaderB54*)(*reinterpret_cast<::LoaderB54 * *>(&::g_modelLoader)))))->FUN_00444850((::Ref *)(pRef), (std::intptr_t)(pCell9), 0);
                    if (pRef->IsVf1d0())
                    {
                        bool bProcess3 = true;
                        if (((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430()))->FUN_00401170() == 0x23)
                        {
                            TESFormB54* pBase2 = ((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430()));
                            if (reinterpret_cast<::FUN_00452440_shell *>((pBase2))->FUN_00452440())
                                bProcess3 = false;
                        }
                        if (bProcess3)
                            reinterpret_cast<::fnv_00548880::FNV_Cell *>(this)->FUN_00548880((::fnv_00548880::FNV_Ref *)(pRef), 0);
                    }
                }
            }
        }
        ::FUN_00541ae0((char *)this);
    }
    if (bArg)
        reinterpret_cast<::FUN_005535f0_shell *>(this)->FUN_005535f0();
    reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(6);
}

NiAVObject* FUN_0054f4f0();

class CellView_rtti;

class BSExtraData
{
  public:
    virtual ~BSExtraData();
    unsigned char type;
    unsigned char unknown05, unknown06, unknown07;
    BSExtraData* next;
};

struct FUN_0040f410 : BSExtraData
{
    unsigned int references;
    FUN_0040f410();
};

struct ExtraListAccess548 : ExtraDataList
{
};

class BaseProcess;

class MobileObject_rtti : public TESObjectREFR
{
  public:
    int FUN_00931850();
};

struct RefList548
{
    TESObjectREFR* item;
    RefList548* next;
};

class GlobalObject_0096d020
{
  public:
};

struct Cell548 : TESObjectCELL
{
    void FUN_00551480(bool RetainReference);
};

class RefView : public TESObjectREFR
{
  public:
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual bool IsActor();  // +0x100
    virtual void v0x41();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void Unk_1c4();  // +0x1c4
    virtual void v072();
    virtual void Unk_1cc(int iA, int iB);  // +0x1cc
    virtual void* GetNode3D();             // +0x1d0
    virtual void v0x75();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void SetParentCell(CellView_rtti* pkCell);  // +0x228
    virtual void v0x8b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void Unk_240();  // +0x240
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();  // +0x24c

      // GetDisabled
      // GetParentCell
};

class RefExtra
{
  public:
};

struct RefList_rtti
{
    void FUN_005ae3d0(RefView*& rpkRef);  // AddHead
      // IsInList
public:
    bool FUN_005f65d0(void **);
};

class CellNavHandler
{
  public:
};

class CellDataHandler
{
  public:
};

class CellTES
{
  public:
};

class CellPlayer
{
  public:
};

// IsSleepingOrResting
class CellSaveLoad
{
  public:
};

class CellModelLoader
{
  public:
};

class CellProcessLists
{
  public:
};

class CellNodeMap
{
  public:
};

class CellTaskQueue
{
  public:
};

class CellView_rtti
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void Unk_0c8(int iValue);  // +0xc8
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
    unsigned short m_usPersistentCount;  // +0xa8
    unsigned short unkaa;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    void* m_pkNavMeshes;  // +0xc4

      // CellRefLockEnter
      // CellRefLockLeave
      // RemoveReference
      // IsInterior
    void FUN_00548230(RefView* pkRef, bool bArg);
};

class TESForm_rtti
{
  public:
    virtual ~TESForm_rtti();
    int GetFormType();
public:
    bool GetDisabled() const;
};

// @fnv 0x00548230
void CellView_rtti::FUN_00548230(RefView* pkRef, bool bArg)
{
    if (!pkRef || !((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkRef))->FUN_007af430())))
        return;
    if (reinterpret_cast<::FUN_00564e60_shell *>((pkRef))->FUN_00564e60() && !reinterpret_cast<::TESForm_rtti *>((pkRef))->GetDisabled())
        m_usPersistentCount++;
    if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
    {
        reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
        ((::RefList_rtti *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))->FUN_005ae3d0(pkRef);
        ::FUN_00541ae0((char *)this);
        reinterpret_cast<::FUN_0041d390_shell *>((((::RefExtra *)(reinterpret_cast<::FUN_005d43c0_ *>((pkRef))->FUN_005d43c0()))))->FUN_0041d390((::TESObjectCELL *)(::CellView_rtti *)(this));
        CellNavHandler* pkHandler = ((::CellNavHandler *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()));
        if (pkHandler)
            reinterpret_cast<::WorldSpaceRefShell *>((pkHandler))->FUN_00587d10((::TESObjectREFR *)(pkRef));
        if (!reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::CellDataHandler * *>(&::g_dataHandler))))->FUN_004516b0())
            Unk_0c8(1);
        return;
    }
    CellView_rtti* pkOldCell = ((::CellView_rtti *)(reinterpret_cast<::LowProcess *>((pkRef))->GetTarget()));
    if (pkOldCell)
        reinterpret_cast<::fnv_0054ca90::Cell *>((pkOldCell))->FUN_0054ca90((::fnv_0054ca90::Ref *)(pkRef));
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    ((::RefList_rtti *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()))->FUN_005ae3d0(pkRef);
    pkRef->SetParentCell(this);
    ::FUN_00541ae0((char *)this);
    if (::FUN_00450ff0((void *)this))
        reinterpret_cast<::CollectionView *>((DAT_011c95c8))->FUN_00526f20((::ReferenceView *)(::BGSPerkEntry *)((BGSPerkEntry*)pkRef));
    if (m_pkNavMeshes)
    {
        if ((!pkRef->IsActor() || reinterpret_cast<::TESForm_rtti *>((pkRef))->GetDisabled()) && reinterpret_cast<::fnv_005656d0::Thing *>((pkRef))->FUN_005656d0())
            reinterpret_cast<::fnv_00545560::FUN_00545560Class *>(this)->FUN_00545560((std::intptr_t)(pkRef));
        if (reinterpret_cast<::fnv_0056a250::FUN_0056a250_shell *>((pkRef))->FUN_0056a250())
            reinterpret_cast<::FUN_005455c0_cls *>(this)->FUN_005455c0((::FUN_005455c0_ref *)(pkRef));
    }
    if (!reinterpret_cast<::TESForm_rtti *>((pkRef))->GetDisabled() && pkRef->GetNode3D())
    {
        MobileObject_rtti* pkMobile = ((MobileObject_rtti*)(static_cast<TESObjectREFR*>(pkRef)));
        if (!pkMobile)
            pkRef->Unk_1c4();
    }
    bool bHandled = false;
    if (!reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::CellDataHandler * *>(&::g_dataHandler))))->FUN_004516b0() && !bHandled && !reinterpret_cast<::FUN_00437b90_shell *>((pkRef))->FUN_00437b90())
    {
        void* pvNode = pkRef->GetNode3D();
        if (reinterpret_cast<::TESCallHelper *>((((::CellTES *)::g_TES)))->IsCellBuffered((::TESObjectCELL *)(::CellView_rtti *)(this), 0))
        {
            bool bQueue = false;
            if (pvNode)
                reinterpret_cast<::fnv_00548880::FNV_Cell *>(this)->FUN_00548880((::fnv_00548880::FNV_Ref *)(pkRef), bArg);
            else
            {
                if (!pkRef->IsActor())
                    bQueue = true;
                else if (!reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::CellPlayer * *>(&::_g_thePlayer))))->IsSleepingOrResting() && !::FUN_00548720((void *)this))
                    bQueue = true;
                if (bQueue)
                {
                    if (pkRef->IsActor() && (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellSaveLoad * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() || reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellSaveLoad * *>(&::g_TESSaveLoadGame))))->EvaluateCondition()))
                    {
                        if (::FUN_00450ff0((void *)this) || reinterpret_cast<::FUN_004523c0_shell *>(this)->FUN_004523c0())
                            pkRef->Unk_240();
                        else
                            pkRef->Unk_24c();
                    }
                    reinterpret_cast<::ML *>(((*reinterpret_cast<::CellModelLoader * *>(&::g_modelLoader))))->FUN_00444850((::Ref *)(pkRef), reinterpret_cast<::LodGrid *>((((::CellTES *)::g_TES)))->FUN_00458be0((::LodCell *)(::CellView_rtti *)(this), (::LodPoint *)(0)), {});
                }
            }
            if (!bQueue && pkRef->IsActor())
                reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::CellProcessLists *>(&::g_011e0e80))))->AddMobileObjectToList((::MobileObject *)(pkRef));
        }
        else
        {
            reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::CellNodeMap *>(&::g_011ca0f4))))->RemoveKey((std::uintptr_t)(pkRef->GetNode3D()));
            if (pkRef->IsActor() && !reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::CellPlayer * *>(&::_g_thePlayer))))->IsSleepingOrResting() && !reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellSaveLoad * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
            {
                if (!FUN_008c7aa0())
                    pkRef->Unk_1cc(0, 0);
                else
                    reinterpret_cast<::FUN_0087b400_shell *>((((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b400((::TESObjectREFR *)(pkRef));
            }
        }
    }
    reinterpret_cast<::fnv_005728c0::FUN_005728c0_shell *>((pkRef))->FUN_005728c0(0);
    if (!reinterpret_cast<::TESObjectCELL *>((((::CellView_rtti *)(reinterpret_cast<::LowProcess *>((pkRef))->GetTarget()))))->IsCellInterior())
    {
        if (reinterpret_cast<::FUN_00548700_Class *>((pkRef))->FUN_00548700() && !reinterpret_cast<::RefList_rtti *>(&((*reinterpret_cast<::RefList_rtti *>(&::g_011ca13c))))->FUN_005f65d0((void **)&(pkRef)))
            (*reinterpret_cast<::RefList_rtti *>(&::g_011ca13c)).FUN_005ae3d0(pkRef);
        if (reinterpret_cast<::FUN_00885a30_Class *>((pkRef))->IsFlag20000000Set() && !reinterpret_cast<::RefList_rtti *>(&((*reinterpret_cast<::RefList_rtti *>(&::g_011ca144))))->FUN_005f65d0((void **)&(pkRef)))
            (*reinterpret_cast<::RefList_rtti *>(&::g_011ca144)).FUN_005ae3d0(pkRef);
    }
}

class TESObject : public TESForm_rtti
{
};

class TESBoundObject_rtti : public TESObject
{
};

class TESObjectDOOR : public TESBoundObject_rtti
{
  public:
};

class ReferenceList
{
  public:
    TESObjectREFR* item;
    ReferenceList* next;
    ReferenceList();
    ~ReferenceList();
    bool IsEmpty();
    TESObjectREFR*& GetItem();
    ReferenceList* GetNext();
    void Append(TESObjectREFR*& reference);
};

// Verified native methods use only their typed receiver in ECX.
// @fnv 0x0054afb0
TESObjectREFR* __cdecl FUN_0054afb0(TESForm_rtti* source, TESForm_rtti* destination, void* context)
{
    TESObjectREFR* result = 0;
    if (source && destination && context && source != destination)
    {
        unsigned int countB = 0;
        ReferenceList candidatesVal;
        ReferenceList* cursor4 = 0;
        TESWorldSpace* world = 0;
        TESObjectCELL* cellVal = dynamic_cast<TESObjectCELL*>(source);
        TESObjectCELL* lockedCellVal = 0;
        if (cellVal)
        {
            cursor4 = ((::ReferenceList *)(reinterpret_cast<::FUN_009604f0_shell *>((cellVal))->FUN_009604f0()));
            lockedCellVal = cellVal;
        }
        else
        {
            world = dynamic_cast<TESWorldSpace*>(source);
            if (world && ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((world))->GetPrevPath())))
            {
                cursor4 = ((::ReferenceList *)(reinterpret_cast<::FUN_009604f0_shell *>((((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((world))->GetPrevPath()))))->FUN_009604f0()));
                lockedCellVal = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((world))->GetPrevPath()));
            }
        }
        lockedCellVal->CellRefLockEnter();
        while (cursor4 && !cursor4->IsEmpty())
        {
            TESObjectREFR* reference = ((::TESObjectREFR *)((void *)(cursor4)));
            if (((::TESBoundObject_rtti *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->GetFormType() == 28 && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(reference))->FUN_00440d80() && !reinterpret_cast<::TESForm_rtti *>((reference))->GetDisabled() &&
                !reinterpret_cast<::FUN_00477ba0_shell *>((reference))->FUN_00477ba0())
            {
                TESObjectDOOR* door = dynamic_cast<TESObjectDOOR*>(((::TESBoundObject_rtti *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())));
                if (door && reinterpret_cast<::FUN_005194d0_shell_base *>((door))->FUN_005194d0() && reinterpret_cast<::FUN_00519500_class *>((door))->HasEntry((std::intptr_t)(destination)) && !((void *)(reinterpret_cast<::TESObjectREFR *>((reference))->GetExtraRadioData())))
                {
                    candidatesVal.Append(reference);
                    ++countB;
                }
            }
            cursor4 = ((::ReferenceList *)(reinterpret_cast<::Callees *>((cursor4))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)(lockedCellVal));
        if (countB > 0 && !candidatesVal.IsEmpty())
        {
            unsigned int selectedX = GetRandomNumberInRange(0, countB);
            unsigned int index2 = 0;
            cursor4 = &candidatesVal;
            while (cursor4 && !cursor4->IsEmpty())
            {
                if (index2 == selectedX)
                {
                    result = ((::TESObjectREFR *)((void *)(cursor4)));
                    break;
                }
                else
                {
                    ++index2;
                    cursor4 = ((::ReferenceList *)(reinterpret_cast<::Callees *>((cursor4))->FUN_00726070()));
                }
            }
            reinterpret_cast<::FileMatchList *>(&(candidatesVal))->RemoveAll();
        }
    }
    return result;
}

class Actor_rtti : public MobileObject_rtti
{
  public:
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual void slot_130();
    virtual void slot_134();
    virtual void slot_138();
    virtual void slot_13c();
    virtual void slot_140();
    virtual void slot_144();
    virtual void slot_148();
    virtual void slot_14c();
    virtual void slot_150();
    virtual void slot_154();
    virtual void slot_158();
    virtual void slot_15c();
    virtual void slot_160();
    virtual void slot_164();
    virtual void slot_168();
    virtual void slot_16c();
    virtual void slot_170();
    virtual void slot_174();
    virtual void slot_178();
    virtual void slot_17c();
    virtual void slot_180();
    virtual void slot_184();
    virtual void slot_188();
    virtual void slot_18c();
    virtual void slot_190();
    virtual void slot_194();
    virtual void slot_198();
    virtual void slot_19c();
    virtual void slot_1a0();
    virtual void slot_1a4();
    virtual void slot_1a8();
    virtual void slot_1ac();
    virtual void slot_1b0();
    virtual void slot_1b4();
    virtual void slot_1b8();
    virtual void slot_1bc();
    virtual void slot_1c0();
    virtual void slot_1c4();
    virtual void slot_1c8();
    virtual void slot_1cc();
    virtual void slot_1d0();
    virtual void slot_1d4();
    virtual void slot_1d8();
    virtual void slot_1dc();
    virtual void slot_1e0();
    virtual void slot_1e4();
    virtual void slot_1e8();
    virtual void slot_1ec();
    virtual void slot_1f0();
    virtual void slot_1f4();
    virtual void slot_1f8();
    virtual void slot_1fc();
    virtual void slot_200();
    virtual void slot_204();
    virtual void slot_208();
    virtual void slot_20c();
    virtual void slot_210();
    virtual void slot_214();
    virtual void slot_218();
    virtual void slot_21c();
    virtual void slot_220();
    virtual void slot_224();
    virtual void slot_228();
    virtual bool FUN_virtual22c(int);
    virtual void slot_230();
    virtual void slot_234();
    virtual void slot_238();
    virtual void slot_23c();
    virtual void slot_240();
    virtual void slot_244();
    virtual void slot_248();
    virtual void slot_24c();
    virtual void slot_250();
    virtual void slot_254();
    virtual void slot_258();
    virtual void slot_25c();
    virtual void slot_260();
    virtual void slot_264();
    virtual void slot_268();
    virtual void slot_26c();
    virtual void slot_270();
    virtual void slot_274();
    virtual void slot_278();
    virtual void slot_27c();
    virtual void slot_280();
    virtual void slot_284();
    virtual void slot_288();
    virtual void slot_28c();
    virtual void slot_290();
    virtual void slot_294();
    virtual void slot_298();
    virtual void slot_29c();
    virtual void slot_2a0();
    virtual void slot_2a4();
    virtual void slot_2a8();
    virtual void slot_2ac();
    virtual void slot_2b0();
    virtual void slot_2b4();
    virtual void slot_2b8();
    virtual void slot_2bc();
    virtual void slot_2c0();
    virtual void slot_2c4();
    virtual void slot_2c8();
    virtual void slot_2cc();
    virtual void slot_2d0();
    virtual void slot_2d4();
    virtual void slot_2d8();
    virtual void slot_2dc();
    virtual void slot_2e0();
    virtual void slot_2e4();
    virtual void slot_2e8();
    virtual void slot_2ec();
    virtual void slot_2f0();
    virtual void slot_2f4();
    virtual void slot_2f8();
    virtual void slot_2fc();
    virtual void slot_300();
    virtual void slot_304();
    virtual void slot_308();
    virtual void slot_30c();
    virtual void slot_310();
    virtual void slot_314();
    virtual void slot_318();
    virtual void slot_31c();
    virtual void slot_320();
    virtual void slot_324();
    virtual void slot_328();
    virtual void slot_32c();
    virtual void slot_330();
    virtual void slot_334();
    virtual void slot_338();
    virtual void slot_33c();
    virtual void slot_340();
    virtual void slot_344();
    virtual void slot_348();
    virtual void slot_34c();
    virtual void slot_350();
    virtual void slot_354();
    virtual void slot_358();
    virtual void slot_35c();
    virtual void slot_360();
    virtual void slot_364();
    virtual void slot_368();
    virtual void slot_36c();
    virtual void slot_370();
    virtual void slot_374();
    virtual void slot_378();
    virtual void slot_37c();
    virtual void slot_380();
    virtual void slot_384();
    virtual void slot_388();
    virtual void slot_38c();
    virtual void slot_390();
    virtual void slot_394();
    virtual void slot_398();
    virtual void slot_39c();
    virtual void slot_3a0();
    virtual void slot_3a4();
    virtual void slot_3a8();
    virtual void slot_3ac();
    virtual void slot_3b0();
    virtual void slot_3b4();
    virtual void slot_3b8();
    virtual void slot_3bc();
    virtual void slot_3c0();
    virtual void slot_3c4();
    virtual void slot_3c8();
    virtual void slot_3cc();
    virtual void slot_3d0();
    virtual void slot_3d4();
    virtual void slot_3d8();
    virtual void slot_3dc();
    virtual void slot_3e0();
    virtual void slot_3e4();
    virtual void slot_3e8();
    virtual void slot_3ec();
    virtual void slot_3f0();
    virtual void slot_3f4();
    virtual void slot_3f8();
    virtual void slot_3fc();
    virtual void slot_400();
    virtual void slot_404();
    virtual void slot_408();
    virtual void slot_40c();
    virtual void slot_410();
    virtual void slot_414();
    virtual void slot_418();
    virtual void slot_41c();
    virtual void slot_420();
    virtual void FUN_virtual424(TESObjectREFR*, int, int, int, int, int, int, int);
    virtual void slot_428();
    virtual void slot_42c();
    virtual void slot_430();
    virtual void slot_434();
    virtual void slot_438();
    virtual void slot_43c();
    virtual void slot_440();
    virtual void slot_444();
    virtual void slot_448();
    virtual void slot_44c();
    virtual void slot_450();
    virtual void slot_454();
    virtual void slot_458();
    virtual void slot_45c();
    virtual void FUN_virtual460(TESObjectREFR*, float);
};

struct ContainerChanges550
{
};

struct ExtraListAccess550 : ExtraDataList
{
};

struct ReferenceAccess550 : TESObjectREFR
{
};

struct RefList550
{
    TESObjectREFR* item;
    RefList550* next;
};

struct Cell550 : TESObjectCELL
{
    void FUN_0054b5b0();
};

// @fnv 0x0054b5b0
void Cell550::FUN_0054b5b0()
{
    CellRefLockEnter();
    RefList550* position = ((::RefList550 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (position)
    {
        TESObjectREFR* reference = ((::TESObjectREFR *)((void *)(position)));
        if (reference && reference != (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))
        {
            Actor_rtti* actor = ((Actor_rtti*)(reference));
            ContainerChanges550* changes =
                ((::ContainerChanges550 *)(reinterpret_cast<::ExtraDataList *>((static_cast<ExtraListAccess550*>(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((static_cast<ReferenceAccess550*>(reference)))->FUN_005d43c0())))))->GetContainerChangeData()));
            if (changes)
                reinterpret_cast<::InventoryMove *>((changes))->FUN_004ce380((::MoveOwner *)(reference), (::MoveOwner *)((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer))), false, false, true, false, -1, (::MoveFilter *)(0));
            if (actor && !reinterpret_cast<::TESForm_rtti *>((actor))->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((actor))->FUN_00440d80())
                actor->FUN_virtual460((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)), 10.0f);
            if (actor && !reinterpret_cast<::FUN_0087f3d0_shell *>((actor))->FUN_0087f3d0() && !reinterpret_cast<::TESForm_rtti *>((actor))->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((actor))->FUN_00440d80() &&
                !actor->FUN_virtual22c(0))
            {
                actor->FUN_virtual424((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)), 0, 0, 0, 0, 0, 1, 0);
                reinterpret_cast<::KillActor *>((actor))->FUN_0089d900(0, 0.0f);
            }
            if (((void *)(reinterpret_cast<::FUN_00569160_shell *>((static_cast<ReferenceAccess550*>(reference)))->FUN_00569160())))
                reinterpret_cast<::fnv_005692a0::FUN_005692a0_shell *>((static_cast<ReferenceAccess550*>(reference)))->FUN_005692a0();
            ::fnv_00555c20::FUN_00555c20();
        }
        position = ((::RefList550 *)(reinterpret_cast<::Callees *>((position))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}

// ExtraCell3D owns the reference count associated with the cell's loaded 3D.


// @fnv 0x00551480
void Cell548::FUN_00551480(bool RetainReference)
{
    FUN_0040f410* extra = static_cast<FUN_0040f410*>(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(&(extraDataList))->FUN_00410220(9));
    if (!extra && RetainReference)
    {
        extra = new FUN_0040f410;
        reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>((static_cast<ExtraListAccess548*>(&extraDataList)))->FUN_0040ff60(extra);
        CellRefLockEnter();
        RefList548* position = ((::RefList548 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (position && ((::TESObjectREFR *)((void *)(position))))
        {
            MobileObject_rtti* mobile = ((MobileObject_rtti*)(((::TESObjectREFR *)((void *)(position)))));
            position = ((::RefList548 *)(reinterpret_cast<::Callees *>((position))->FUN_00726070()));
            if (mobile && !reinterpret_cast<::TESForm_rtti *>((mobile))->GetDisabled() && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture())) && mobile->FUN_00931850() == 3)
                reinterpret_cast<::ProcessLists *>(&(g_011e0e80))->AddMobileObjectToList((::MobileObject *)(mobile));
        }
        ::FUN_00541ae0((char *)this);
    }
    if (extra)
    {
        if (RetainReference)
            extra->references++;
        else
            extra->references--;
        if (!extra->references)
            reinterpret_cast<::FUN_00410020_t *>((static_cast<ExtraListAccess548*>(&extraDataList)))->FUN_00410020(extra, true);
    }
}

class TESWeather : public TESForm_rtti
{
};

class NiUpdateData_rtti
{
  public:
    float m_fTime;
    unsigned short unk04;
    bool m_bQueueShadow;
    bool m_bQueueAnim;
    bool m_bUpdateShadow;
    unsigned char unk09;
    unsigned short unk0a;
    NiUpdateData_rtti(float fTime, bool m_bUpdateEnabled, bool bThreaded);
};

class NodeView
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void UpdateDownwardPass(NiUpdateData_rtti& kData, unsigned int uiFlags);  // +0xa8
};

class SceneRoot
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void Unk_0c4();  // +0xc4
};

class RefNodeView
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual NodeView* GetNode3D();  // +0x1d0
};

struct RefNodeList
{
    RefNodeView* m_pkItem;
    RefNodeList* m_pkNext;
    bool FUN_008256d0();           // IsEmpty
      // GetItem
       // GetNext
};

class FormTypeView
{
  public:
    int FUN_00401170();
};

// GetFormType
class KeyRefView
{
  public:
};

struct NiColor_rtti
{
    float r, g, b;
};

class LightForm
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual NiColor_rtti* GetColor();  // +0xc0
    int FUN_00401170();           // GetFormType
      // packed RGB
};

class BaseLight
{
  public:
    int FUN_00401170();
};

struct SkyColorData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

class Sky_rtti
{
  public:
public:
    static ::Sky_rtti *GetInstance();
};

class PointLightNode
{
  public:
};

class PointLightPtr
{
  public:
};

class MapRefView
{
  public:
};

class PlayerLightView
{
  public:
};

template <class K, class V> struct CellRefMap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* FUN_004b9ba0();                                    // GetFirstPos
    void FUN_006b7f20(void*& rpvPos, K& rkKey, V& rkValue);  // GetNext
};

struct CellLoadedData
{
    int unk00;
    RefNodeList kRefs;                              // +0x04
    CellRefMap<KeyRefView*, NodeView*> kActors;     // +0x0c
    CellRefMap<LightForm*, NiColor_rtti*> kColors;       // +0x1c
    CellRefMap<MapRefView*, void*> kMapReferences;  // +0x2c
};

struct CellIntSetting
{
};

struct CellFloatSetting
{
};

struct CellTimer
{
};

extern float DAT_0118b698;

extern float DAT_0102f0e4;

class ManagedTaskQueue : public CellTaskQueue
{
  public:
};

class CellShadowScene
{
  public:
};

class CellWaterView
{
  public:
};

class CellWaterOwner
{
  public:
};

class CellUpdateView
{
  public:
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
    short unka8;
    short m_sRefCount;  // +0xaa
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    CellLoadedData* m_pkLoaded;  // +0xc4
    float m_fWaterTimer;         // +0xc8
    unsigned short unkcc;
    bool m_bWaterCE;  // +0xce
    bool m_bWaterCF;  // +0xcf
    bool m_bWaterD0;  // +0xd0
    bool unkd1;
    bool m_bWaterD2;  // +0xd2

    void FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded);
};

// @fnv 0x00551890
void CellUpdateView::FUN_00551890(float fTimeSinceScaleStart, bool bSkipLoaded)
{
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && ::FUN_00450ff0((void *)this))
    {
        SceneRoot* pkRoot = ((::SceneRoot *)(reinterpret_cast<::FUN_004543c0_cls *>(this)->FUN_004543c0()));
        if (pkRoot)
            pkRoot->Unk_0c4();
    }
    bool bThreaded = false;
    if (FUN_008c7aa0())
        bThreaded = true;
    NodeView* pkDynamic = ((::NodeView *)(reinterpret_cast<::TESObjectCELL *>(this)->GetDynamicNode()));
    if (pkDynamic && !bSkipLoaded)
    {
        NiUpdateData_rtti kData(fTimeSinceScaleStart, false, bThreaded);
        pkDynamic->UpdateDownwardPass(kData, 0);
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CellIntSetting *>(&::g_011c3ea4)))))) > 1)
        {
            reinterpret_cast<::fnv_0087aad0::FUN_0087aad0_s *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087aad0((std::intptr_t)(pkDynamic));
            if (bThreaded && kData.m_bQueueShadow)
                ::RunWithLock(pkDynamic);
            if (bThreaded && kData.m_bQueueAnim)
                reinterpret_cast<::FUN_0087abb0_shell *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087abb0((::G00559a40 *)(pkDynamic));
        }
    }
    if (m_sRefCount > 0 && reinterpret_cast<::FUN_005495a0Class *>(this)->FUN_005495a0() && reinterpret_cast<::FUN_00557d10_Class *>(this)->FUN_00557d10())
        reinterpret_cast<::FUN_00557aa0_Class *>(this)->FUN_00557aa0();
    if (m_bWaterD2 && ((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())) && ((int)(reinterpret_cast<::FUN_00450fd0_class *>(this)->GetByteAtOffset38())) == 6)
    {
        m_bWaterD0 = true;
        m_bWaterCE = false;
        m_bWaterCF = false;
        if (((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())))
            reinterpret_cast<::MiddleHighProcess *>((((::CellWaterView *)(reinterpret_cast<::TESWorldSpace *>((((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->GetWorldTerrainManager()))))->FUN_00929260(1);
        m_bWaterD2 = false;
    }
    if (m_bWaterCE)
    {
        if (DAT_0118b698 * DAT_0118b694 <= m_fWaterTimer)
        {
            if (((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace())) && !m_bWaterD0)
                reinterpret_cast<::MiddleHighProcess *>((((::CellWaterView *)(reinterpret_cast<::TESWorldSpace *>((((::CellWaterOwner *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()))))->GetWorldTerrainManager()))))->FUN_00929260(1);
            m_bWaterD0 = true;
            m_bWaterCE = false;
            m_bWaterCF = false;
        }
        m_fWaterTimer += ::fnv::timer::Seconds();
    }
    if (m_pkLoaded)
    {
        if (bSkipLoaded)
        {
            RefNodeList* pkIter = &m_pkLoaded->kRefs;
            while (pkIter && !pkIter->FUN_008256d0())
            {
                RefNodeView* pkRef = *((::RefNodeView **)((void *)(pkIter)));
                NodeView* pkNode = pkRef->GetNode3D();
                pkIter = ((::RefNodeList *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
                if (pkNode)
                {
                    NiUpdateData_rtti kNodeData(fTimeSinceScaleStart, false, bThreaded);
                    pkNode->UpdateDownwardPass(kNodeData, 0);
                    if (kNodeData.m_bUpdateShadow)
                        reinterpret_cast<::S00b5d9f0_Owner *>((((::CellShadowScene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(pkNode), 1);
                    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CellIntSetting *>(&::g_011c3ea4)))))) > 1)
                    {
                        reinterpret_cast<::fnv_0087aad0::FUN_0087aad0_s *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087aad0((std::intptr_t)(pkNode));
                        if (bThreaded && kNodeData.m_bQueueShadow)
                            ::RunWithLock(pkNode);
                        if (bThreaded && kNodeData.m_bQueueAnim)
                            reinterpret_cast<::FUN_0087abb0_shell *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087abb0((::G00559a40 *)(pkNode));
                    }
                }
            }
        }
        else
        {
            void* pvPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_pkLoaded->kActors))->GetFirstPos();
            while (pvPos)
            {
                KeyRefView* pkKeyNew = 0;
                NodeView* pkActorNode = 0;
                reinterpret_cast<::C6b7f20_Map *>(&(m_pkLoaded->kActors))->FUN_006b7f20((::C6b7f20_Node **)&(pvPos), (unsigned int *)&(pkKeyNew), (void **)&(pkActorNode));
                if (pkActorNode && ((::NodeView *)(reinterpret_cast<::FUN_009611e0_shell *>((pkActorNode))->FUN_009611e0())) != pkDynamic)
                {
                    if (((::FormTypeView *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkKeyNew))->FUN_007af430()))->FUN_00401170() == 0x25 && !::FUN_004b5fc0((::NiAVObject *)(pkActorNode), (::NiCamera *)(FUN_00552380())))
                        continue;
                    NiUpdateData_rtti kActorData(fTimeSinceScaleStart, false, bThreaded);
                    pkActorNode->UpdateDownwardPass(kActorData, 0);
                    if (kActorData.m_bUpdateShadow)
                        reinterpret_cast<::S00b5d9f0_Owner *>((((::CellShadowScene *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(pkActorNode), 1);
                    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CellIntSetting *>(&::g_011c3ea4)))))) > 1)
                    {
                        reinterpret_cast<::fnv_0087aad0::FUN_0087aad0_s *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087aad0((std::intptr_t)(pkActorNode));
                        if (bThreaded && kActorData.m_bQueueShadow)
                            ::RunWithLock(pkActorNode);
                        if (bThreaded && kActorData.m_bQueueAnim)
                            reinterpret_cast<::FUN_0087abb0_shell *>((((ManagedTaskQueue*)((::CellTaskQueue *)(::TaskQueueInterface::GetSingleton())))))->FUN_0087abb0((::G00559a40 *)(pkActorNode));
                    }
                }
            }
            pvPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_pkLoaded->kColors))->GetFirstPos();
            while (pvPos)
            {
                LightForm* pkForm = 0;
                NiColor_rtti* pkUnused = 0;
                reinterpret_cast<::C6b7f20_Map *>(&(m_pkLoaded->kColors))->FUN_006b7f20((::C6b7f20_Node **)&(pvPos), (unsigned int *)&(pkForm), (void **)&(pkUnused));
                if (pkForm)
                {
                    NiColor_rtti* pkColorPos = pkForm->GetColor();
                    switch (pkForm->FUN_00401170())
                    {
                    case 0x1e: {
                        LightForm* pkLightTmp = pkForm;
                        unsigned int uiColor = reinterpret_cast<::FUN_005e3fc0_shell *>((pkLightTmp))->Get();
                        float fScale = DAT_0102f0e4;
                        pkColorPos->r = (unsigned char)(uiColor & 0xff) * fScale;
                        pkColorPos->g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                        pkColorPos->b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                        break;
                    }
                    case 0x37: {
                        LightForm* pkRegion = pkForm;
                        TESWeather* pkWeather = ((::TESWeather *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((pkRegion))->GetCurrentMoveModeType()));
                        if (!pkWeather)
                            pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                        if (pkWeather)
                        {
                            Sky_rtti* pkSky = ::Sky_rtti::GetInstance();
                            SkyColorData kSkyDataOut;
                            float fBlendRes;
                            int iIndexNew;
                            reinterpret_cast<::fnv_0063b630::SkyHelper *>((pkSky))->FUN_0063b630((::fnv_0063b630::SkyInterpolationData *)(::SkyColorData *)(&kSkyDataOut), pkWeather, 1.0f, (int *)(float *)(&fBlendRes), &iIndexNew);
                            reinterpret_cast<::fnv_0063bab0::FUN_0063bab0_shell *>((pkSky))->FUN_0063bab0(&kSkyDataOut, pkWeather, (::TESWeather *)(0), 4, (int *)(float *)(&fBlendRes), &iIndexNew);
                            float fValue = reinterpret_cast<::FUN_00644950_shell *>((pkSky))->FUN_00644950() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellFloatSetting *>(&::g_011ccccc))))));
                            reinterpret_cast<::FUN_0063c690_shell *>((pkSky))->FUN_0063c690((float *)(pkColorPos), (::SkyColors *)(::SkyColorData *)(&kSkyDataOut), fValue);
                        }
                        break;
                    }
                    }
                }
            }
            pvPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_pkLoaded->kMapReferences))->GetFirstPos();
            while (pvPos)
            {
                MapRefView* pkLightRefTmp = 0;
                void* pvLightData = 0;
                reinterpret_cast<::C6b7f20_Map *>(&(m_pkLoaded->kMapReferences))->FUN_006b7f20((::C6b7f20_Node **)&(pvPos), (unsigned int *)&(pkLightRefTmp), (void **)&(pvLightData));
                if (pvLightData)
                {
                    NiColor_rtti kColor = *(const NiColor_rtti*)&DAT_011a9b7c;
                    LightForm* pkSource = ((::LightForm *)(reinterpret_cast<::FUN_00569580_shell *>((pkLightRefTmp))->GetOwnerForm()));
                    if (!pkSource)
                        pkSource = ((::LightForm *)(reinterpret_cast<::TESObjectCELL *>((((PlayerLightView*)(*reinterpret_cast<::CellPlayer * *>(&::_g_thePlayer)))))->FUN_005454d0()));
                    if (pkSource)
                    {
                        switch (pkSource->FUN_00401170())
                        {
                        case 0x1e: {
                            LightForm* pkLightTmp = pkSource;
                            unsigned int uiColor = reinterpret_cast<::FUN_005e3fc0_shell *>((pkLightTmp))->Get();
                            float fScale = DAT_0102f0e4;
                            kColor.r = (unsigned char)(uiColor & 0xff) * fScale;
                            kColor.g = (unsigned char)(((unsigned short)uiColor >> 8) & 0xff) * fScale;
                            kColor.b = (unsigned char)((uiColor >> 16) & 0xff) * fScale;
                            break;
                        }
                        case 0x37: {
                            LightForm* pkRegion = pkSource;
                            TESWeather* pkWeather = ((::TESWeather *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((pkRegion))->GetCurrentMoveModeType()));
                            if (!pkWeather)
                                pkWeather = dynamic_cast<TESWeather*>(FUN_004839c0(0x15e));
                            if (pkWeather)
                            {
                                Sky_rtti* pkSky = ::Sky_rtti::GetInstance();
                                SkyColorData kSkyDataOut;
                                float fBlendRes;
                                int iIndexNew;
                                reinterpret_cast<::fnv_0063b630::SkyHelper *>((pkSky))->FUN_0063b630((::fnv_0063b630::SkyInterpolationData *)(::SkyColorData *)(&kSkyDataOut), pkWeather, 1.0f, (int *)(float *)(&fBlendRes), &iIndexNew);
                                reinterpret_cast<::fnv_0063bab0::FUN_0063bab0_shell *>((pkSky))->FUN_0063bab0(&kSkyDataOut, pkWeather, (::TESWeather *)(0), 4, (int *)(float *)(&fBlendRes), &iIndexNew);
                                float fValue = reinterpret_cast<::FUN_00644950_shell *>((pkSky))->FUN_00644950() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellFloatSetting *>(&::g_011ccccc))))));
                                reinterpret_cast<::FUN_0063c690_shell *>((pkSky))->FUN_0063c690((float *)(::NiColor_rtti *)(&kColor), (::SkyColors *)(::SkyColorData *)(&kSkyDataOut), fValue);
                            }
                            break;
                        }
                        }
                    }
                    if (((::BaseLight *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkLightRefTmp))->FUN_007af430()))->FUN_00401170() == 0x1e)
                    {
                        BaseLight* pkBaseRes = ((::BaseLight *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkLightRefTmp))->FUN_007af430()));
                        unsigned int uiBaseColor = reinterpret_cast<::FUN_005e3fc0_shell *>((pkBaseRes))->Get();
                        float m_fThirdCreatureStatCur = DAT_0102f0e4;
                        kColor.r *= (unsigned char)(uiBaseColor & 0xff) * m_fThirdCreatureStatCur;
                        kColor.g *=
                            (unsigned char)(((unsigned short)uiBaseColor >> 8) & 0xff) * m_fThirdCreatureStatCur;
                        kColor.b *= (unsigned char)((uiBaseColor >> 16) & 0xff) * m_fThirdCreatureStatCur;
                        PointLightPtr* pkLightPtrCur = ((::PointLightPtr *)(reinterpret_cast<::FUN_005725f0_shell *>((pkLightRefTmp))->FUN_005725f0()));
                        if (pkLightPtrCur && ((::PointLightNode *)(::FUN_00559450((int *)(pkLightPtrCur)))))
                            reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((::PointLightNode *)(::FUN_00559450((int *)(pkLightPtrCur))))))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(kColor));
                    }
                }
            }
        }
    }
}

NiAVObject* FUN_0054f4f0();

class CellView_rtti_decl;

class MobileObject_rtti_decl : public TESObjectREFR
{
};

class RefView_rtti_decl : public TESObjectREFR
{
  public:
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual bool IsActor();  // +0x100
    virtual void v0x41();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void Unk_1c4();  // +0x1c4
    virtual void v072();
    virtual void Unk_1cc(int iA, int iB);  // +0x1cc
    virtual void* GetNode3D();             // +0x1d0
    virtual void v0x75();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void SetParentCell(CellView_rtti_decl* pkCell);  // +0x228
    virtual void v0x8b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void Unk_240();  // +0x240
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();  // +0x24c

      // GetDisabled
      // GetParentCell
};

class RefExtra_rtti_decl
{
  public:
};

struct RefList_rtti_decl
{
    void FUN_005ae3d0(RefView_rtti_decl*& rpkRef);  // AddHead
      // IsInList
public:
    bool FUN_005f65d0(void **);
};

class CellNavHandler_rtti_decl
{
  public:
};

class CellDataHandler_rtti_decl
{
  public:
};

class CellTES_rtti_decl
{
  public:
};

class CellPlayer_rtti_decl
{
  public:
};

// IsSleepingOrResting
class CellSaveLoad_rtti_decl
{
  public:
};

class CellModelLoader_rtti_decl
{
  public:
};

class CellProcessLists_rtti_decl
{
  public:
};

class CellNodeMap_rtti_decl
{
  public:
};

class CellTaskQueue_rtti_decl
{
  public:
};

class CellView_rtti_decl
{
  public:
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void Unk_0c8(int iValue);  // +0xc8
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
    unsigned short m_usPersistentCount;  // +0xa8
    unsigned short unkaa;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    void* m_pkNavMeshes;  // +0xc4

      // CellRefLockEnter
      // CellRefLockLeave
      // RemoveReference
      // IsInterior
    void FUN_00548230(RefView_rtti_decl* pkRef, bool bArg);
};

enum ENUM_FORM_ID;

class TESForm_rtti_decl
{
  public:
    virtual ~TESForm_rtti_decl();
public:
    ::ENUM_FORM_ID GetFormType() const;
public:
    bool GetDisabled() const;
};

class TESObject_rtti_decl : public TESForm_rtti_decl
{
};

class TESBoundObject_rtti_decl : public TESObject_rtti_decl
{
};

class TESObjectDOOR_rtti_decl : public TESBoundObject_rtti_decl
{
  public:
};

class ReferenceList_rtti_decl
{
  public:
    TESObjectREFR* item;
    ReferenceList_rtti_decl* next;
    ReferenceList_rtti_decl();
    ~ReferenceList_rtti_decl();
    bool IsEmpty();
    TESObjectREFR*& GetItem();
    ReferenceList_rtti_decl* GetNext();
    void Append(TESObjectREFR*& reference);
};

// Verified native methods use only their typed receiver in ECX.

struct FormGroupQuery
{
    unsigned int tag, unk04, value, kind;
};

// TESObjectCELL virtual slot used below, as in the original unit's declaration (MatchForm at slot 15).
struct CellSlotView
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual bool MatchForm(void* form);
};

// @fnv 0x005434d0
bool TESObjectCELL::FUN_005434d0(FormGroupQuery* group)
{

    bool matched = false;

    if (group && group->tag == ::fnv_00543df0::kGroupFormType)
    {

        switch (group->kind)
        {

        case 0:
            matched = reinterpret_cast<::FUN_00484150_shell *>(this)->IsFormTypeBelowThreshold((::FormRecordHeader *)(group));
            break;

        case 2:

            if (IsCellInterior() && reinterpret_cast<::FUN_005441b0_S *>(this)->FUN_005441b0() < group->value)

                matched = true;

            break;

        case 3:

            if (IsCellInterior() && reinterpret_cast<::FUN_00544210_shell *>(this)->FUN_00544210() < group->value)

                matched = true;

            break;

        case 6:
        case 8:
        case 9: {

            TESObjectCELL* cell = dynamic_cast<TESObjectCELL*>(FUN_004839c0(group->value));

            if (cell)

                matched = ((CellSlotView*)this)->MatchForm(cell);

            break;
        }

        case 4:

            if (!IsCellInterior())
            {

                if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
                    matched = true;

                else if (reinterpret_cast<::FUN_005441b0_S *>(this)->FUN_005441b0() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 5:

            if (!IsCellInterior())
            {

                if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
                    matched = true;

                else if (reinterpret_cast<::FUN_00544210_shell *>(this)->FUN_00544210() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 1:

            if (!IsCellInterior())
            {

                TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(FUN_004839c0(group->value));

                if (world)

                    matched = ((CellSlotView*)this)->MatchForm(world);
            }
            else
                matched = true;

            break;

        case 7:
            matched = true;
            break;
        }
    }

    return matched;
}

#include "generated/data/fallout_shared/tesobjectcell.inc"
#include "generated/data/fallout_shared/tesobjectcell_ctx2_variant.inc"
#include "generated/data/fallout_shared/tesobjectcell_rtti_variant.inc"
