// fallout/ai/mobileobject.cpp: MobileObject, Actor, TESObjectREFR, VTableHelper and more (95 functions)

#include "fnv/simple_list_node_view.h"
#include "fnv/game_timer.h"
#include "fnv/package_fields.h"
#include "fnv/result_slot.h"
#include <intrin.h>
#include <new>
#include <cmath>
#include "fnv/decl/ActorDeletionQueue.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/AimController_c70060.h"
#include "fnv/decl/B61F2B0Object.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BipedAnim.h"
#include "fnv/decl/C6760Ref.h"
#include "fnv/decl/C6E030Holder.h"
#include "fnv/decl/C70B60Character.h"
#include "fnv/decl/C70CharacterController.h"
#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CharacterProbeLocal.h"
#include "fnv/decl/DummyFlagsShell.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_0042e130_shell.h"
#include "fnv/decl/FUN_0042ede0_shell.h"
#include "fnv/decl/FUN_0042efe0_cls.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004572e0_shell.h"
#include "fnv/decl/FUN_0045cbc0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004d5a90_Class.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_0050ea10_class.h"
#include "fnv/decl/FUN_00516bf0_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_0055f5b0_Class.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00575770_shell.h"
#include "fnv/decl/FUN_005757d0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005c0860Class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00629650_Class.h"
#include "fnv/decl/FUN_00629670_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00672dd0_shell.h"
#include "fnv/decl/FUN_00672fc0_shell.h"
#include "fnv/decl/FUN_0067a690_shell.h"
#include "fnv/decl/FUN_0067efd0_shell.h"
#include "fnv/decl/FUN_00693d50_shell.h"
#include "fnv/decl/FUN_00810660_Class.h"
#include "fnv/decl/FUN_008126e0_shell.h"
#include "fnv/decl/FUN_0083de40_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_0087eeb0_shell.h"
#include "fnv/decl/FUN_0087f390_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_0088b0a0_c.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00953ce0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009b28a0_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89b0_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8be0_shell.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00b4e030_shell.h"
#include "fnv/decl/FUN_00c6e280_cls.h"
#include "fnv/decl/FUN_00c6ffc0_Class.h"
#include "fnv/decl/FakeCell.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Holder0042f780.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LipSyncAnimation.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/PD_.h"
#include "fnv/decl/PackageEx.h"
#include "fnv/decl/PackageTargetRecord.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/Ref3.h"
#include "fnv/decl/Ref55F5.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/Refr_s.h"
#include "fnv/decl/RemOwner.h"
#include "fnv/decl/RotationOwner.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S00561730_Vector.h"
#include "fnv/decl/S005620e0_Object.h"
#include "fnv/decl/S5757a0.h"
#include "fnv/decl/SLGameShell.h"
#include "fnv/decl/S_8c4f10_Cls.h"
#include "fnv/decl/SaveReference.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/T_.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/VectorSourceB00.h"
#include "fnv/decl/bhkCharacterListener.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_0055a2f0__FUN_0055a2f0.h"
#include "fnv/decl/fnv_0055e940__SaveReference.h"
#include "fnv/decl/fnv_0055ec40__LoadObject.h"
#include "fnv/decl/fnv_0055f240__FUN_0055f240_Class.h"
#include "fnv/decl/fnv_0055f780__C0055f780.h"
#include "fnv/decl/fnv_005623d0__RefX.h"
#include "fnv/decl/fnv_00562660__FUN_00562660_shell.h"
#include "fnv/decl/fnv_005627c0__FUN_005627c0_shell.h"
#include "fnv/decl/fnv_005629a0__Ref.h"
#include "fnv/decl/fnv_00564930__FUN_00564930_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_0057ace0__FUN_0057ace0_shell.h"
#include "fnv/decl/fnv_0057ad20__FUN_0057ad20_shell.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_005de0f0__FUN_005de0f0_shell.h"
#include "fnv/decl/fnv_00671d30__FUN_00671d30_shell.h"
#include "fnv/decl/fnv_00671e10__FUN_00671e10_shell.h"
#include "fnv/decl/fnv_0067a1b0__FUN_0067a1b0_shell.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0080fb00__FUN_0080fb00_Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008a0b10__FUN_008a0b10_shell.h"
#include "fnv/decl/fnv_008b8f90__TaskOwner.h"
#include "fnv/decl/fnv_00905f30__S_00905f30_Owner.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00967730__RelationOwner.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00adbfd0__FUN_00adbfd0_cls.h"
#include "fnv/decl/fnv_00adc050__FUN_00adc050_cls.h"
#include "fnv/decl/s008e2680__Owner.h"
#include "fnv/decl/s54baf0__Owner.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004d5000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c0000.h"
#include "fnv/symbols_005d1000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006d9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00838000.h"
#include "fnv/symbols_0087e000.h"
#include "fnv/symbols_0089d000.h"
#include "fnv/symbols_008a2000.h"
#include "fnv/symbols_008a5000.h"
#include "fnv/symbols_008b1000.h"
#include "fnv/symbols_008c1000.h"
#include "fnv/symbols_00930000.h"
#include "fnv/symbols_00933000.h"
#include "fnv/symbols_00935000.h"
#include "fnv/symbols_00936000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00ad8000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011a2000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011b0000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/TopicMethods.h"
#include <cstdint>
#include <cstddef>
#include "fnv/decl/BGSProjectile.h"
#include "fnv/decl/FUN_00407860_class.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_0056e120_shell.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/decl/FUN_00810510_Class.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_00810590_Class.h"
#include "fnv/decl/FUN_008105c0_Class.h"
#include "fnv/decl/FUN_008105e0_Class.h"
#include "fnv/decl/FUN_00810640_class.h"
#include "fnv/decl/FUN_00812870_t.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_00966980_shell.h"
#include "fnv/decl/FUN_009ae4a0_class.h"
#include "fnv/decl/FUN_009beae0_class.h"
#include "fnv/decl/Getter_9b8.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S_00c6d7a0_Obj.h"
#include "fnv/decl/V.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_00810610__FUN_00810610_Class.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004ba000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_0057b000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_00a58000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011ce000.h"
#include <xmmintrin.h>
#include <windows.h>
#include "fnv/decl/C70940Obj.h"
#include "fnv/decl/CacObj.h"
#include "fnv/decl/CharProxy.h"
#include "fnv/decl/CharacterProxy.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/FUN_006212c0_shell.h"
#include "fnv/decl/FUN_00933810.h"
#include "fnv/decl/FUN_00c6cc10_cls.h"
#include "fnv/decl/FUN_00c6cef0_cls.h"
#include "fnv/decl/FUN_00c6d120_cls.h"
#include "fnv/decl/FUN_00c6d150_class.h"
#include "fnv/decl/FUN_00cac110_Class.h"
#include "fnv/decl/FUN_00cac920_Class.h"
#include "fnv/decl/Holder00807080.h"
#include "fnv/decl/fnv_00c70bd0__FUN_00c70bd0_cls.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpCharacterStateView.h"
#include "fnv/symbols_0049e000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00ca9000.h"
#include "fnv/symbols_00cac000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_simd.h"
class ExtraDismemberedLimbs;
class bhkCharacterController;
#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "mobileobject_private/mobileobject_types_TESPackage.h"
#include "mobileobject_private/mobileobject_interface.h"

// @fnv 0x00931d30
void MobileObject::AdvanceMovement(float delta)
{
    SetFurnitureHeading(GetCurrentTargetDistance(false) + delta);
}

// @fnv 0x00931d70
float MobileObject::GetLooking() const
{
    return (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)this)->GetData())).x;
}

// Returns true if the interface is in dialogue and the stored object pointer is non-null and its check returns true.
// @fnv 0x00933840
bool MobileObject::IsInDialogueWithPlayer() const
{
    if (Interface::IsInDialog() && m_pBaseProcess && m_pBaseProcess->IsDetectionEnabled())
        return true;
    return false;
}

// @fnv 0x009316c0
void MobileObject::ProcessAnimation()
{
    reinterpret_cast<::s56ae10::Owner *>(this)->FUN_0056ae10((intptr_t)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((void *)this)->FUN_00575d70()))), (intptr_t)(GetParentCell()), (intptr_t)&(*GetPos()), (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)this)->GetData())).z);
}

// Returns true if the current package exists and its pack type is IN_GAME_DIALOGUE, otherwise false.
// @fnv 0x009336c0
bool MobileObject::IsCombatStateActive() const
{
    TESPackage* package = reinterpret_cast<::FUN_009344a0_shell *>((void *)this)->FUN_009344a0();
    if (package && package->GetPackType() == _PackageType::IN_GAME_DIALOGUE)
        return true;
    else
        return false;
}

// Returns false when flags contains any bit that is also set in the masked-out bits, otherwise true.
// @fnv 0x008b0190
bool Actor::IsVisible(int flags)
{
    return (flags & ~(m_iActorStateValue & flags)) ? false : true;
}

// @fnv 0x0087d810
void Actor::SetActorEssentialState(int value)
{
    ActorProjectileState = value;
}

#include "../../../include/BSAudio.h"
#include "../../../include/SoundPlaybackHandle.h"

// Looks up a sound form by editor name, gets a sound handle by form ID, optionally positions and attaches it to the node, sets volume to 1.0 and plays it.
// @fnv 0x00933270
SoundPlaybackHandle MobileObject::PlaySoundByEditorName(const char* editorName, bool loop, unsigned int flags, bool)
{
    SoundPlaybackHandle soundHandle;
    if (GetNiNode())
    {
        // TESSound's evidenced primary TESForm base is at offset zero.
        TESForm* sound = reinterpret_cast<TESForm*>((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->GetSoundByEditorID(editorName));
        if (sound)
        {
            soundHandle = ::FUN_00453a70()->GetSoundHandleByFormID(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((sound))->FUN_0084e3a0())), flags);
            if (flags & 2)
            {
                NiPoint3 position = *GetPos();
                reinterpret_cast<::FUN_00ad8b60_h *>(&(soundHandle))->FUN_00ad8b60(position.x, position.y, position.z);
                reinterpret_cast<::FUN_00ad8f20_shell *>(&(soundHandle))->FUN_00ad8f20(reinterpret_cast<NiAVObject*>(GetNiNode()));
            }
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(soundHandle))->FUN_00ad89e0(1.0f);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(soundHandle))->FUN_00ad8830(loop);
        }
    }
    return soundHandle;
}

#include "mobileobject_private/mobileobject_packet.h"
// @fnv 0x004b9930
bool MobileObject::GetCharControllerFlag() const
{
    return !(*reinterpret_cast<const unsigned char*>((void *)&this->m_ucFormType));
}
// @fnv 0x00920fb0
void Actor::SetCurrentSitSleepState(SIT_SLEEP_STATE state)
{
    m_eSitSleepState = state;
}
// Checks the reference's ExtraDismemberedLimbs extra data and returns whether the given limb is dismembered.
// @fnv 0x00573090
bool TESObjectREFR::IsLimbMissing(int limb)
{
    ExtraDismemberedLimbs* extra = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))->GetDismemberedLimbs();
    if (!extra)
        return false;
    return reinterpret_cast<::FUN_004303e0_Class *>((extra))->IsBitSet(limb);
}
// @fnv 0x009307d0
bool MobileObject::IsActorDead()
{
    MobileObjectRemovalState state;
    state.removed = false;
    state.controller = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (state.controller)
    {
        reinterpret_cast<::FUN_00c6ffc0_Class *>((state.controller))->FUN_00c6ffc0();
        reinterpret_cast<::C70CharacterController *>((state.controller))->FUN_00c70c90((::WorldProxy *)(0));
        state.removed = true;
    }
    return state.removed;
}
// Copies the x, y and z components of point into the first three elements of output and sets the fourth element to 0.0f, then returns output.
// @fnv 0x00553fc0
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController* output, const NiPoint3& point)
{
    output->GetVectorElement(0) = point.x;
    output->GetVectorElement(1) = point.y;
    output->GetVectorElement(2) = point.z;
    output->GetVectorElement(3) = 0.0f;
    return output;
}

class NiAVObject;
struct FourComponentNumericValue;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
class hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
struct FUN_004a3eb0_shell : public BhkPickData
{
    void FUN_004a3eb0(void*);
};

struct __declspec(align(16)) hkVector4
{
    char m_vComponents[16];
    hkVector4();
};


struct FUN_004a3f40_helper
{
};

// @fnv 0x004a3eb0
void FUN_004a3eb0_shell::FUN_004a3eb0(void* arTo)
{
    hkVector4 hkv;
    reinterpret_cast<::PD_ *>((((FUN_004a3f40_helper*)this)))->FUN_004a3f40((void *)&((*(::hkVector4 *)&(::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(hkv), (const ::fnv_004a3e00::NiPoint3 &)(*(const NiPoint3*)arTo))))));
}

extern int DAT_0108a490;
extern int DAT_0108a49c;

// @fnv 0x0092eb50
void* FUN_0092eb50(char* this_ptr)
{
    new ((void *)(((TESObjectREFR*)this_ptr))) ::fnv_0055a2f0::FUN_0055a2f0();
    *(int**)(this_ptr + 0x00) = &DAT_0108a49c;
    *(int**)(this_ptr + 0x18) = &DAT_0108a490;
    *(int*)(this_ptr + 0x6c) = 0;
    *(int*)(this_ptr + 0x68) = 0;
    *(int*)(this_ptr + 0x70) = 0;
    *(char*)(this_ptr + 0x7c) = 1;
    *(char*)(this_ptr + 0x7d) = 0;
    *(char*)(this_ptr + 0x7e) = 0;
    *(char*)(this_ptr + 0x84) = -1;
    *(char*)(this_ptr + 0x85) = 0;
    *(char*)(this_ptr + 0x7f) = 1;
    *(char*)(this_ptr + 0x80) = 1;
    *(char*)(this_ptr + 0x86) = 1;
    *(char*)(this_ptr + 0x81) = 0;
    *(char*)(this_ptr + 0x82) = 0;
    *(char*)(this_ptr + 0x87) = 0;
    *(float*)(this_ptr + 0x78) = 0.0f;
    *(char*)(this_ptr + 0x83) = 0;
    return this_ptr;
}


struct VTableHelper
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
    virtual int v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual bool v230();
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
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void* v4c8();
    void FUN_00931b60(float fAngleDifference);
    unsigned int pad04[0xa];
    float unk2c;
};

// @fnv 0x00931b60
void VTableHelper::FUN_00931b60(float afAngle)
{
    if (((Actor*)this)->m_pBaseProcess)
    {
        if (this->v230())
            return;

        switch (this->v214())
        {
        case 4:
        case 5:
        case 9:
        case 10:
            if (((VTableHelper*)((Actor*)this)->m_pBaseProcess)->v4c8() && this->v100())
                return;
            break;
        }
    }

    afAngle = WrapAngle(afAngle);
    if (this->v100() && reinterpret_cast<::FUN_0087eeb0_shell *>((this))->FUN_0087eeb0())
    {
        afAngle = afAngle - this->unk2c;
        while (afAngle < DAT_0101ff58)
            afAngle = afAngle + 6.2831854820251465;
        while (afAngle >= 3.1415927410125732)
            afAngle = afAngle - 6.2831854820251465;
        reinterpret_cast<::S5757a0 *>((this))->FUN_005757a0(afAngle);
    }
    else
    {
        reinterpret_cast<::FUN_005757d0_shell *>((this))->FUN_005757d0(afAngle);
    }
}

struct FUN_00931d90_shell : public MobileObject
{
    void ClampLookAngle(float);
};

struct SettingT_GameSettingCollection_
{
};
extern const float DAT_0108a7f8;
extern const double DAT_0108a7f0;
extern const float DAT_0108a7ec;
struct ST_00931d90
{
};
// Clamps afAngle between a lower limit and a per-actor-type maximum derived from a game setting, then applies it via FUN_00575770.
// @fnv 0x00931d90
void FUN_00931d90_shell::ClampLookAngle(float afAngle)
{
    float fMaxAngle = DAT_0108a7f8;
    if (IsActor())
    {
        TESObjectREFR* pactor = this;
        switch ((int)pactor->Unk_85())
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            fMaxAngle = *(float*)((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting231)))))) * DAT_01023128;
            break;
        }
    }
    if (afAngle < DAT_0108a7f0)
        reinterpret_cast<::FUN_00575770_shell *>((((ST_00931d90*)this)))->FUN_00575770(DAT_0108a7ec);
    else if (afAngle > fMaxAngle)
        reinterpret_cast<::FUN_00575770_shell *>((((ST_00931d90*)this)))->FUN_00575770(fMaxAngle);
    else
        reinterpret_cast<::FUN_00575770_shell *>((((ST_00931d90*)this)))->FUN_00575770(afAngle);
}

struct FUN_00931e50_shell : public MobileObject
{
    void AddModAngle(float);
};

struct ST_00931e50
{
};
// Adds afModAngle to the object's looking angle and passes the result to ClampLookAngle.
// @fnv 0x00931e50
void FUN_00931e50_shell::AddModAngle(float afModAngle)
{
    reinterpret_cast<::FUN_00931d90_shell *>((((ST_00931e50*)this)))->ClampLookAngle(GetLooking() + afModAngle);
}

struct FUN_00931e80_shell : public MobileObject
{
    void DeleteAndClear();
};

// @fnv 0x00931e80
void FUN_00931e80_shell::DeleteAndClear()
{
    delete m_pBaseProcess;
    m_pBaseProcess = 0;
}

struct FUN_00931fb0_shell : public MobileObject
{
    void FUN_00931fb0(bool);
};
// Calls TESObjectREFR::Revert, reverts the stored reference if present, then resets the object's state flags and values to defaults.
// @fnv 0x00932f60
void MobileObject::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_005629a0::Ref *>(this)->FUN_005629a0((::fnv_005629a0::LoadBuffer *)(buffer));
    if (m_pBaseProcess)
        m_pBaseProcess->Revert(buffer);
    reinterpret_cast<::FUN_00931fb0_shell *>(this)->FUN_00931fb0(false);
    m_cCharacterValue = -1;
    m_bNinthFlag = false;
    m_bFirstFlag = true;
    m_bFourthBooleanValue = true;
    m_bFifthFlag = true;
    m_bSecondBooleanValue = false;
    m_bThirdFlag = false;
    m_bTenthFlag = true;
    ProcessReferenceState = 0.0f;
    ReferenceMobileState = 0.0f;
    m_bEighthFlag = false;
}

struct Helper_00629670
{
};

// @fnv 0x00931fb0
void FUN_00931fb0_shell::FUN_00931fb0(bool abTF)
{
    bhkCharacterController* pcon = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (pcon)
    {
        reinterpret_cast<::FUN_00629670_Class *>((reinterpret_cast<Helper_00629670*>(reinterpret_cast<char*>(pcon) + 0x410)))->FUN_00629670(0x800, abTF);
    }
}

namespace fnv_00932d60 {
struct ActorCause;
struct AlchemyItem;
struct BGSProjectile;
struct BGSSaveFormBuffer;
class SaveLoadFile;
struct CombatController;
struct EnchantmentItem;
class InventoryStackRecord;
class NiAVObject;
struct ThreeByThreeMatrix;
class NiQuaternion;
class Projectile;
struct ProjectileAuxiliaryData;
struct ProjectileSupportData;
class TESBoundObject;
struct TESFaction;
class TESFile;
class TESObjectWEAP;
struct BhkPickData;
struct bhkRigidBody;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
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
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
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
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
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
struct FUN_00932d60_shell : public MobileObject
{
    void FUN_00932d60(BGSLoadFormBuffer*);
};

class RecursiveSpinLock
{
  public:
};

struct BGSSaveLoadGame
{
  public:
};

class Calendar
{
  public:
};

class ProcessLists
{
  public:
    void AddMobileObjectToList(MobileObject*);
    void RemoveMobileObjectFromList(MobileObject*);
};

class ActorDeletionQueue
{
  public:
};

class TESResponse
{
  public:
};

class ActiveEffect
{
  public:
};

struct Actor_Accessor : public Actor
{
};

struct TESObjectREFR_Accessor : public TESObjectREFR
{
    void FUN_009319c0(int);
};



// @fnv 0x00932d60
void FUN_00932d60_shell::FUN_00932d60(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_005627c0::FUN_005627c0_shell *>((((TESObjectREFR_Accessor*)this)))->FUN_005627c0((::fnv_005627c0::BGSLoadFormBuffer *)(apLoadGameBuffer));
    if (m_pBaseProcess != 0)
    {
        m_pBaseProcess->ApplyLoadBuffer(reinterpret_cast< ::BGSLoadFormBuffer*>(apLoadGameBuffer));
        if (reinterpret_cast<::FUN_00437b90_shell *>((((Actor_Accessor*)this)))->FUN_00437b90())
        {
            reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_00932d60::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
            reinterpret_cast<::ActorDeletionQueue *>((((ActorDeletionQueue*)&(*reinterpret_cast<::fnv_00932d60::ProcessLists *>(&::g_011e0e80)))))->FUN_0096d470(this, (intptr_t)((::fnv_00932d60::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)m_pBaseProcess)))->FUN_0045cd60())));
            delete m_pBaseProcess;
            reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_00932d60::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();
            m_pBaseProcess = 0;
        }
        else if (((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((TESObjectREFR_Accessor*)this)))->FUN_0043fcd0())) == 0 && (PlayerCharacter*)this != ::_g_thePlayer &&
                 (((::fnv_00932d60::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)m_pBaseProcess)))->FUN_0045cd60())) == 0 ||
                  (intptr_t)((::fnv_00932d60::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)m_pBaseProcess)))->FUN_0045cd60())) == 1))
        {
            PROCESS_TYPE edesiredProcessLevel = GetProcessTier();
            if (edesiredProcessLevel == PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW ||
                edesiredProcessLevel == PROCESS_TYPE_PROCESS_TYPE_LOW)
            {
                if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00932d60::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                {
                    if (edesiredProcessLevel == PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW)
                        Unk_92();
                    else
                        Unk_91();
                    reinterpret_cast<::FUN_00693d50_shell *>((((ActiveEffect*)m_pBaseProcess)))->FUN_00693d50(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::fnv_00932d60::Calendar *>(&::g_011de7b8))))->GetGameTime() - 0.5);
                    (*reinterpret_cast<::fnv_00932d60::ProcessLists *>(&::g_011e0e80)).RemoveMobileObjectFromList(this);
                }
                else
                {
                    (*reinterpret_cast<::fnv_00932d60::ProcessLists *>(&::g_011e0e80)).AddMobileObjectToList(this);
                }
            }
        }
    }
    if (!*((unsigned char*)&this->m_bFifthFlag) && !((intptr_t)(reinterpret_cast<::FUN_0042ede0_shell *>((void *)(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0042ede0())))
    {
        ::FUN_00936ac0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())), 1);
    }
    if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00932d60::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() && !reinterpret_cast<::FUN_00437b90_shell *>((((Actor_Accessor*)this)))->FUN_00437b90())
    {
        ((TESObjectREFR_Accessor*)this)->FUN_009319c0(GetProcessTier());
    }
}
}  // namespace fnv_00932d60

struct FUN_009333e0_shell : public MobileObject
{
    void FUN_009333e0(bool);
};

class MagicCaster;
class MobileObject;
struct ProcessLists
{
    void AddMobileObjectToList(MobileObject*);
public:
    void RemoveMobileObjectFromList(::MobileObject *);
};
struct ST_009333e0
{
    void FUN_0092ed60(bool);
};
// @fnv 0x009333e0
void FUN_009333e0_shell::FUN_009333e0(bool abDeleted)
{
    reinterpret_cast<::fnv_00564930::FUN_00564930_shell *>((((ST_009333e0*)this)))->FUN_00564930(abDeleted);
    (*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)).AddMobileObjectToList(this);
    if (abDeleted)
    {
        bool bcaster = dynamic_cast<MagicCaster*>((MobileObject*)this) || ((bool)(::FUN_00933480(this)));
        ((ST_009333e0*)this)->FUN_0092ed60(bcaster);
        (*(void(**)(void*))(*(intptr_t*)this + 0x2fc))(this);
    }
}


struct MobileObject_Helper : public MobileObject
{
    void SetAccumulate(int);
    void FUN_00936aa0(bool);
};

void SetAccumulate(MobileObject_Helper*, int, int);
void FUN_00936aa0(MobileObject_Helper*, int, bool);

// Looks up the form for the given id; if it is a mobile object, either clears its flag or calls SetAccumulate and FUN_00936aa0 with abSucceeded.
// @fnv 0x00936a20
void __cdecl HandleMobileObjectResult(void* apContext, bool abSucceeded)
{
    MobileObject* pactor;
    uintptr_t iactorid = (uintptr_t)apContext;
    TESForm* pform = ::FUN_004839c0(iactorid);
    if (pform && pform->IsMobileObject())
    {
        pactor = (MobileObject*)pform;
        if (!pactor)
        {
            return;
        }
        if (!pactor->m_bEighthFlag)
        {
            ((void(*)(MobileObject*, int))SetAccumulate)(pactor, 0);
            ((void(*)(MobileObject*, bool))FUN_00936aa0)(pactor, abSucceeded);
        }
        else
        {
            pactor->m_bEighthFlag = false;
        }
    }
}

struct FUN_00931620_shell : public MobileObject
{
    void FUN_00931620(NiPoint3*);
};

struct V3;
struct FUN_00440460_S
{
public:
    void FUN_00440460(const ::V3 *);
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_0087cee0_shell
{
    bool FUN_0087cee0();
};
struct SetLoc_S
{
};
struct CharCtl_S
{
};

// Sets the reference location from arVel, then forwards arVel to the character controller and to the object at offset 0x64 when its float at 0x14 is non-zero.
// @fnv 0x00931620
void FUN_00931620_shell::FUN_00931620(NiPoint3* arVel)
{
    reinterpret_cast<::Reference *>((reinterpret_cast<SetLoc_S*>(this)))->FUN_00575830((::Position *)&(*arVel));
    bhkCharacterController* pcon = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (pcon)
    {
        reinterpret_cast<::S005620e0_Object *>((reinterpret_cast<CharCtl_S*>(pcon)))->FUN_005620e0((const ::S005620e0_Source *)(arVel));
        reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((reinterpret_cast<CharCtl_S*>(pcon)))->FUN_0080fb00((intptr_t)(FUN_00458b20()));
        FUN_005d10f0(reinterpret_cast<const char*>(pcon));
        reinterpret_cast<FUN_0087cee0_shell*>(pcon)->FUN_0087cee0();
        reinterpret_cast<::C6E030Holder *>((reinterpret_cast<CharCtl_S*>(pcon)))->ResetState();
    }
    if (*(int*)((char*)this + 0x64) && (unsigned int)*(Flt*)(*(char**)&this->m_pRenderData + 0x14))
    {
        reinterpret_cast<FUN_00440460_S*>((unsigned int)*(Flt*)(*(char**)&this->m_pRenderData + 0x14))->FUN_00440460((const ::V3 *)(arVel));
    }
}

namespace fnv_009334b0 {
struct FUN_009334b0_shell : public MobileObject
{
    int GetCellLoadState();
};

struct BGSSaveLoadGame
{
};
struct TESSaveLoadGame
{
};
class PlayerCharacter
{
  public:
    bool IsSleepingOrResting();
};
struct TES
{
};
struct ModelLoader
{
    bool FUN_00445750(void*);
};
struct MobileStandIn
{
    unsigned int GetCurrentProcessLevel();
    TESObjectCELL* GetTarget();
};
struct CellStandIn
{
};
// Returns a state code based on save-loading, sleeping/resting, the target cell, model loading and cell checks.
// @fnv 0x009334b0
int FUN_009334b0_shell::GetCellLoadState()
{
    TESObjectCELL* pTargetCell;
    if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::fnv_009334b0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && (*reinterpret_cast<::fnv_009334b0::PlayerCharacter * *>(&::_g_thePlayer))->IsSleepingOrResting())
        return ((MobileStandIn*)this)->GetCurrentProcessLevel();
    pTargetCell = ((MobileStandIn*)this)->GetTarget();
    if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_009334b0::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() || ((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((MobileStandIn*)this)))->FUN_0043fcd0())) ||
        (*reinterpret_cast<::fnv_009334b0::ModelLoader * *>(&::g_modelLoader))->FUN_00445750(this))
    {
        if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_009334b0::TES * *>(&::g_TES))))->IsCellBuffered(pTargetCell, true))
            return 0;
        else if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_009334b0::TES * *>(&::g_TES))))->IsCellBuffered(pTargetCell, false))
            return 1;
    }
    if ((pTargetCell && reinterpret_cast<::TESObjectCELL *>((((CellStandIn*)pTargetCell)))->HasCellExtraData()) || reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_009334b0::TES * *>(&::g_TES))))->IsCellBuffered(pTargetCell, false))
        return 2;
    return 3;
}
}  // namespace fnv_009334b0

class FUN_0092f140_shell
{
    unsigned int m_field_0xd2c;

  public:
    uintptr_t GetFieldD2C();
    unsigned int pad04[0x34a];
    unsigned int unkd2c;
};

// @fnv 0x0092f140
uintptr_t FUN_0092f140_shell::GetFieldD2C()
{
    return this->unkd2c;
}


// @fnv 0x009304a0
int __cdecl FUN_009304a0()
{
    return DAT_011a2fe0;
}

struct DummyFlags
{
public:
    int FUN_0088b0c0();
};

// @fnv 0x00930570
int HasFlag40000(DummyFlags* this_)
{
    return ((int)(reinterpret_cast<::bhkCharacterListener *>((((DummyFlags*)((char*)this_ + 0x410))))->FUN_00621270(0x40000))) != 0;
}

// @fnv 0x00930600
void SetField558(void* thisPtr, float value)
{
    *(float*)((char*)thisPtr + 0x558) = value;
}

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

// @fnv 0x004d5ad0
bool BuildLipPath(BSStringT<char>& path)
{
    char fileName[260];
    TaskQueueInterface::CopyStringToBuffer(fileName, 260, ((const char *)(::FUN_00559450((int *)&(path)))));
    {
        char* dot = FUN_0040ab30(fileName, '.');
        if (!dot)
            return false;
        *dot = 0;
    }
    ::FUN_00406f60((::FUN_00406f90_this *)&(path), "%s.lip", fileName);
    return true;
}

struct FUN_00810f90_shell
{
    void SetFlag4000(bool flag);
};

// Sets or clears bit 0x4000 in the first int of this object based on flag.
// @fnv 0x00810f90
void FUN_00810f90_shell::SetFlag4000(bool abSet)
{
    if (abSet)
        ((int*)this)[0] |= 0x4000;
    else
        ((int*)this)[0] &= ~0x4000;
}

struct FUN_0092ec10_shell
{
    void* FUN_0092ec40();
    void* DestroyIfFlagged(unsigned int flags);
};


extern "C"
{
}

struct FUN_00930620_shell
{
    void FUN_00930620();
    unsigned int pad00[0x14c];
    float unk530;
};

// @fnv 0x00930620
void FUN_00930620_shell::FUN_00930620()
{
    this->unk530 = DAT_011b014c;
}

struct FUN_0083b9a0_shell
{
};
struct FUN_009edd80;
struct FUN_00967730_shell
{
};

struct FUN_009edd80 : public TESPackage
{
    SoundPlaybackHandle kSound;
    intptr_t iUnk8C;
    float m_fPackageValue;
    int iUnk94;
    bool bUnk98;
    int iUnk9C;
    bool bUnkA0;
    FUN_0083b9a0_shell* pTopic;
    int iUnkA8;
    int iUnkAC;
    Actor* m_pDialogueSpeaker;
    Actor* pTarget;
    int iUnkB8;
    bool bUnkBC;
    bool bUnkBD;
    bool bUnkBE;
    bool bUnkBF;
    bool bUnkC0;
    bool bUnkC1;
    bool bUnkC2;
    int iUnkC4;
    int iUnkC8;
    bool bUnkCC;
    FUN_009edd80(FUN_0083b9a0_shell* apTopic, Actor* apSpeaker, Actor* apTarget, int aiUnk, bool abUnkBD, bool abUnkA0);
    virtual ~FUN_009edd80();
};

struct FUN_00672850_shell : TESPackage
{
    float GetPackageFloatValue();
};

// Returns 1.0f unless the pack type is 0xf or 0x1c, in which case it returns the float at offset 4 of the package stored at this+0x28.
// @fnv 0x00672850
float FUN_00672850_shell::GetPackageFloatValue()
{
    float result = 1.0f;
    if (GetPackType() == 0xf || GetPackType() == 0x1c)
    {
        TESPackage* pkg = *(TESPackage**)&this->m_pPackageData;
        if (pkg)
            result = *(float*)((char*)pkg + 4);
    }
    return result;
}

namespace fnv_009304b0 {
struct DummyFlags
{
    int HasFlag20();
};

// @fnv 0x009304b0
int DummyFlags::HasFlag20()
{
    return ((int)(reinterpret_cast<::bhkCharacterListener *>(this)->FUN_00621270(0x20))) != 0;
}
}  // namespace fnv_009304b0

class TESObject
{
  public:
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual bool AtA0();
};
struct FUN_0056f6b0_t
{
    bool HasNextWithAtA0();
};
// Returns true if GetNext() is non-null and the next object's AtA0() is also true.
// @fnv 0x0056f6b0
bool FUN_0056f6b0_t::HasNextWithAtA0()
{
    return ((::TESObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject*)this)))->FUN_007af430())) && ((::TESObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject*)this)))->FUN_007af430()))->AtA0();
}

struct StandIn_00672760 : public TESPackage
{
    TESPackage* FUN_00672760();
};
// If the package type is 0xF or 0x1C, returns the TESPackage stored at offset 8 of the object at this+0x28; otherwise returns null.
// @fnv 0x00672760
TESPackage* StandIn_00672760::FUN_00672760()
{
    TESPackage* result = 0;
    if (GetPackType() == 0xF || GetPackType() == 0x1C)
    {
        void* tmp = *(void**)&this->m_pPackageData;
        if (tmp)
        {
            result = *(TESPackage**)((char*)tmp + 8);
        }
    }
    return result;
}

struct Unk80f760
{
    NiPoint3* GetZeroPoint(NiPoint3* p);
};
// Writes NiPoint3::ZERO into the output NiPoint3 and returns it.
// @fnv 0x0080f760
NiPoint3* Unk80f760::GetZeroPoint(NiPoint3* apPoint)
{
    *apPoint = NiPoint3::ZERO;
    return apPoint;
}

namespace fnv_00810ff0 {
struct Flt
{
    operator unsigned int() const;
};
struct Unk626
{
    void FUN_00626cb0(int);
};
struct Ths810
{
    char pad[0x594];
    Flt f;
    void FUN_00810ff0(intptr_t);
};
// If the stored Flt value is non-zero, treats it as an Unk626 and calls FUN_00626cb0 with a.
// @fnv 0x00810ff0
void Ths810::FUN_00810ff0(intptr_t a)
{
    if ((unsigned int)f)
        ((Unk626*)(uintptr_t)f)->FUN_00626cb0(a);
}
}  // namespace fnv_00810ff0

struct Holder_00884aa0
{
    intptr_t UpdateControllerScale();
    int FUN_00884aa0();
};
// Calls UpdateControllerScale; if it returns nonzero, calls FUN_00838780 with this and 0, then returns that result.
// @fnv 0x00884aa0
int Holder_00884aa0::FUN_00884aa0()
{
    int result = 0;
    result = UpdateControllerScale();
    if (result)
    {
        ::FUN_00838780((::TESObjectREFR *)(::Holder_00884aa0 *)(this));
    }
    return result;
}

namespace fnv_008a0270 {
struct PC7d;
struct FUN_008a0270_t
{
    bool FUN_008a0270(bool);
    char pad00[0x104];
    bool unk104;
    char pad105[0x22];
    bool unk127;
};
// Returns false for the player; otherwise returns the flag at offset 0x104 when offset 0x68 is nonzero, unless 0x104, abFlag and 0x127 are all set.
// @fnv 0x008a0270
bool FUN_008a0270_t::FUN_008a0270(bool abFlag)
{
    if ((PC7d*)this == (*reinterpret_cast<::fnv_008a0270::PC7d * *>(&::_g_thePlayer)))
        return false;
    if (*(int*)((char*)this + 0x68) != 0)
    {
        if (this->unk104 && abFlag && this->unk127)
            return false;
        return this->unk104;
    }
    return false;
}
}  // namespace fnv_008a0270

namespace fnv_0092f1c0 {
struct Process_Shell_0x10
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void VirtualMethod_10(void*);
};

struct TESChallenge
{
    TESObjectREFR* GetProgressValue();
};

struct ExtraDataList_Shell
{
};

struct ActorDeletionQueue
{
};

struct ProcessLists
{
};


struct FUN_0092f1c0_shell : MobileObject
{
    void FUN_0092f1c0(bool m_bChangeDetected);
};

// @fnv 0x0092f1c0
void FUN_0092f1c0_shell::FUN_0092f1c0(bool abUnused)
{
    Unk_50();

    if (m_pBaseProcess)
    {
        ((Process_Shell_0x10*)m_pBaseProcess)->VirtualMethod_10(this);
    }

    if (((bool)(::FUN_00574900((const unsigned char *)this))) && !IsCombatStateActive())
    {
        TESObjectREFR* refr = ((TESChallenge*)this)->GetProgressValue();
        if (refr)
        {
            reinterpret_cast<::FUN_0042e130_shell *>((((ExtraDataList_Shell*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((refr))->FUN_005d43c0())))))->FUN_0042e130();
        }

        reinterpret_cast<::ActorDeletionQueue *>((((ActorDeletionQueue*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_0096d470(this, 0);
        reinterpret_cast<::ProcessLists *>((((ProcessLists*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->AddMobileObjectToList(this);
    }
}
}  // namespace fnv_0092f1c0

namespace fnv_009305a0 {
struct DummyFlags
{
};
struct FUN_009305a0_Holder
{
    char _pad[0x410];
    DummyFlags m410;
    bool FUN_009305a0();
};
// @fnv 0x009305a0
bool FUN_009305a0_Holder::FUN_009305a0()
{
    return ((int)(reinterpret_cast<::bhkCharacterListener *>(&(m410))->FUN_00621270(0x2000000))) != 0;
}
}  // namespace fnv_009305a0

namespace fnv_00934f90 {
class TESObject
{
};
class TESObjectREFR;
struct BGSTalkingActivator
{
};
struct FUN_00934f90_shell
{
    char _pad[0x6c];
    TESObject* _ptr;
    void* GetTempRefOrSelf(unsigned int, void**);
};
// Stores this into out, then returns the temp ref of the next TESObject if it has one, otherwise returns this.
// @fnv 0x00934f90
void* FUN_00934f90_shell::GetTempRefOrSelf(unsigned int, void** out)
{
    *out = this;
    BGSTalkingActivator* tmp = (BGSTalkingActivator*)((uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((_ptr))->FUN_007af430()));
    if (((::fnv_00934f90::TESObjectREFR *)(reinterpret_cast<::FUN_00516bf0_shell *>((void *)(tmp))->FUN_00516bf0())))
    {
        return ((::fnv_00934f90::TESObjectREFR *)(reinterpret_cast<::FUN_00516bf0_shell *>((void *)(tmp))->FUN_00516bf0()));
        goto done;
    }
    return this;
done:;
}
}  // namespace fnv_00934f90

struct FUN_009bc8c0_shell
{
    bool FUN_009bc8c0();
};
// @fnv 0x009bc8c0
bool FUN_009bc8c0_shell::FUN_009bc8c0()
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(this)))->FUN_0084e3a0()))))
        return true;
    else
        return false;
}

struct FUN_0080f790_shell : public TESObjectREFR
{
    float GetAngleZOnReference(int dummy);
};

// @fnv 0x0080f790
float FUN_0080f790_shell::GetAngleZOnReference(int dummy)
{
    return (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)this)->GetData())).z;
}

struct S0092f160;
struct P0092f160
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void f265();
    virtual void f266();
    virtual void f267();
    virtual void f268();
    virtual void f269();
    virtual void f270();
    virtual void f271();
    virtual void f272();
    virtual void f273();
    virtual void f274();
    virtual void f275();
    virtual void f276();
    virtual void f277();
    virtual void f278();
    virtual void f279();
    virtual void f280();
    virtual void f281();
    virtual void f282();
    virtual void f283();
    virtual void f284();
    virtual void f285();
    virtual void f286();
    virtual void f287();
    virtual void f288();
    virtual void f289();
    virtual void f290();
    virtual void f291();
    virtual void f292();
    virtual void f293();
    virtual void f294();
    virtual void f295();
    virtual void f296();
    virtual void f297();
    virtual void f298();
    virtual void f299();
    virtual void f300();
    virtual void f301();
    virtual bool Talk(S0092f160*);
};
struct S0092f160
{
    char _pad[0x68];
    P0092f160* proc;
    bool FUN_0092f160();
};
// Calls Talk on the proc object, passing this, and returns its result.
// @fnv 0x0092f160
bool S0092f160::FUN_0092f160()
{
    return proc->Talk(this);
}

struct Unk68
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
};
struct FUN_0092f190_shell
{
    char pad[0x68];
    Unk68* ptr;
    void FUN_0092f190();
};
// If ptr is non-null, calls its v10 method.
// @fnv 0x0092f190
void FUN_0092f190_shell::FUN_0092f190()
{
    if (ptr != 0)
        ptr->v10();
}

struct FUN_00629670_T
{
};

struct FUN_00930540_shell
{
    char pad[0x410];
    FUN_00629670_T m_410;
    void FUN_00930540(unsigned char param);
};

// Forwards the given byte and the constant 0x100 to the member's FUN_00629670.
// @fnv 0x00930540
void FUN_00930540_shell::FUN_00930540(unsigned char abValue)
{
    reinterpret_cast<::FUN_00629670_Class *>(&(m_410))->FUN_00629670(0x100, abValue);
}

namespace fnv_009305d0 {
class DummyFlags
{
  public:
};

class FUN_009305d0_shell
{
    char pad[0x410];
    DummyFlags m_flags;

  public:
    bool FUN_009305d0();
};

// @fnv 0x009305d0
bool FUN_009305d0_shell::FUN_009305d0()
{
    return ((int)(reinterpret_cast<::bhkCharacterListener *>(&(m_flags))->FUN_00621270(0x4000000))) != 0;
}
}  // namespace fnv_009305d0

class TESObjectCELL;

struct TES
{
};

class PatrolActorPackageData;
struct LowProcess
{
    TESObjectCELL* GetTarget();
public:
    void SetPackageObjectType(intptr_t);
    intptr_t GetPackageObjectType();
    ::TESObjectREFR *GetActiveCombatTarget();
    ::PatrolActorPackageData *GetCurrentPackageData();
    void SetCurrentBoundObject(::TESBoundObject *);
    void SetCurrentCombatTarget(::TESObjectREFR *);
    void ClearData();
    float GetActorTimeDelta(::Actor *);
    int GetActorValue(::TESActorBase *, ::ActorValue::Index, ::Actor *);
    float GetCurrentActorValue(::TESActorBase *, ::ActorValue::Index, ::Actor *);
    void HandlePackageChange(::LowProcess *);
    bool CanRunPackage(::TESPackage *, bool);
    void ProcessAcquire(::Actor *);
    void UpdateTargetFromPackage();
    bool CanProcessActor(::Actor *, bool);
    void SetFlag40(int);
    static bool HandlePackageLocationLoaded(::TESObjectREFR *, intptr_t);
    static bool HandlePackageTargetLoaded(::TESObjectREFR *, intptr_t);
    void LoadGame(::BGSLoadFormBuffer *);
    void InitLoadGame(::BGSLoadFormBuffer *);
    void Revert(::BGSLoadFormBuffer *);
    void ProcessPatrol(::Actor *);
    void HandlePatrolArrival(::Actor *, ::PatrolActorPackageData *);
    float GetCurrentDetectionAmount();
};

struct TESResponse
{
};

struct Vtable_Shell
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
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    // Slot 116 = 0x1d0
    virtual int VirtualMethod_1d0();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    // Slot 144 = 0x240
    virtual void VirtualMethod_240();
};

struct FUN_00931880_shell : MobileObject
{
    bool FUN_00931880();
};

// @fnv 0x00931880
bool FUN_00931880_shell::FUN_00931880()
{
    bool result = true;

    if (((Vtable_Shell*)this)->VirtualMethod_1d0())
    {
        if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->IsCellBuffered(((LowProcess*)this)->GetTarget(), true))
        {
            if (((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)m_pBaseProcess)))->FUN_0045cd60())))
            {
                ((Vtable_Shell*)this)->VirtualMethod_240();
            }
            else
            {
                delete this;
                result = false;
            }
        }
    }

    return result;
}

namespace fnv_00931920 {
class TESObjectCELL;

struct TES
{
};

struct LowProcess
{
    TESObjectCELL* GetTarget();
};

struct TESResponse
{
};

struct Vtable_Shell
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
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    // Slot 116 = 0x1d0
    virtual int VirtualMethod_1d0();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    // Slot 144 = 0x240
    virtual void VirtualMethod_240();
};

struct FUN_00931920_shell : MobileObject
{
    bool CheckTargetAndDelete(bool bCheck);
};

// @fnv 0x00931920
bool FUN_00931920_shell::CheckTargetAndDelete(bool bCheck)
{
    bool result = true;

    if (((Vtable_Shell*)this)->VirtualMethod_1d0())
    {
        if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_00931920::TES * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(::fnv_00931920::TESObjectCELL *)(((LowProcess*)this)->GetTarget()), bCheck))
        {
            if (((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)m_pBaseProcess)))->FUN_0045cd60())))
            {
                ((Vtable_Shell*)this)->VirtualMethod_240();
            }
            else
            {
                delete this;
                result = false;
            }
        }
    }

    return result;
}
}  // namespace fnv_00931920

struct Process_Shell
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
    virtual void v074();
    virtual void v075();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
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
    virtual void v12a();
    virtual void v12b();
    virtual void v12c();
    virtual void v12d();
    virtual void v12e();
    virtual void v12f();
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
    virtual void v13a();
    virtual void v13b();
    virtual void v13c();
    virtual void v13d();
    virtual void v13e();
    virtual void v13f();
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
    virtual void v14a();
    virtual void v14b();
    virtual void v14c();
    virtual void v14d();
    virtual void v14e();
    virtual void v14f();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    // Slot 344 = 0x560
    virtual void VirtualMethod_560(unsigned int, unsigned int, void*);
};

struct Refr_Vtable_Shell
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
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    // Slot 115 = 0x1cc
    virtual void VirtualMethod_1cc(int, int);
};

struct FUN_00932490_shell : MobileObject
{
    void SetProcessFlags(unsigned int aiFlags, unsigned int aiOldFlags);
};

// @fnv 0x00932490
void FUN_00932490_shell::SetProcessFlags(unsigned int aiFlags, unsigned int aiOldFlags)
{
    reinterpret_cast<::Ref55F5 *>(this)->FUN_0055f5f0(aiFlags, aiOldFlags);

    if (m_pBaseProcess)
    {
        ((Process_Shell*)m_pBaseProcess)->VirtualMethod_560(aiFlags, aiOldFlags, this);
    }

    if ((aiFlags & 0) || (aiOldFlags & 0))
    {
        if (GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
        {
            ((Refr_Vtable_Shell*)this)->VirtualMethod_1cc(0, 1);
        }
    }
}

struct Vt_009358f0
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
    virtual void Target();
};
struct FUN_009358f0_Host
{
    char _pad[0x68];
    Vt_009358f0* p;
    void InvokeTarget();
};
// Calls the Target virtual method on the object pointed to by p.
// @fnv 0x009358f0
void FUN_009358f0_Host::InvokeTarget()
{
    p->Target();
}

namespace fnv_009319c0 {
struct FUN_009319c0_shell : public MobileObject
{
    bool FUN_009319c0(int);
};

class RecursiveSpinLock
{
};
struct ActorDeletionQueue
{
};
struct TESResponse
{
};
struct Base_0092c950
{
    Base_0092c950();
    virtual ~Base_0092c950();
    char pad[0xb0];
};
struct FUN_009319c0_vt
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
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual bool StartHigh();
    virtual bool StartLow();
    virtual bool StartMiddleLow();
    virtual bool StartMiddleHigh();
};

// Locks, deletes the queued object at offset 0x68 and enqueues its response when level is -1; otherwise allocates it and dispatches a start method by level.
// @fnv 0x009319c0
bool FUN_009319c0_shell::FUN_009319c0(int aeProcessLevel)
{
    bool bresult = false;
    if (aeProcessLevel == -1)
    {
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_009319c0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
        if (*(Base_0092c950**)&this->m_pBaseProcess)
        {
            bresult = true;
            reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::fnv_009319c0::ActorDeletionQueue *>(&::g_011e0e80))))->FUN_0096d470(this, ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)*(Base_0092c950**)&this->m_pBaseProcess)))->FUN_0045cd60())));
            delete *(Base_0092c950**)&this->m_pBaseProcess;
            *(Base_0092c950**)&this->m_pBaseProcess = 0;
        }
        reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_009319c0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();
    }
    else
    {
        if (!*(Base_0092c950**)&this->m_pBaseProcess)
            *(Base_0092c950**)&this->m_pBaseProcess = new Base_0092c950();
        if (GetCurrentProcessLevel() != aeProcessLevel)
        {
            switch (aeProcessLevel)
            {
            case 0:
                bresult = ((FUN_009319c0_vt*)this)->StartHigh();
                break;
            case 1:
                bresult = ((FUN_009319c0_vt*)this)->StartMiddleHigh();
                break;
            case 2:
                bresult = ((FUN_009319c0_vt*)this)->StartMiddleLow();
                break;
            case 3:
                bresult = ((FUN_009319c0_vt*)this)->StartLow();
                break;
            }
        }
    }
    return bresult;
}
}  // namespace fnv_009319c0

namespace fnv_00932520 {
class TESSound;
class TESObjectCELL;
class bhkWorld;

struct FUN_0055f780_cls
{
};
struct LowProcess
{
    TESSound* GetTarget();
};
struct FUN_005c0860Class
{
};
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
struct CharCtl_S
{
};
class RecursiveSpinLock
{
};
struct TESResponse
{
};
class ActiveEffect
{
};
struct Calendar
{
};
struct ActorDeletionQueue
{
};
struct ProcessLists
{
};
struct FUN_00577330_cls
{
};

struct Proc_00932520
{
    virtual ~Proc_00932520();
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
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564(unsigned int aiFlags, unsigned int aiOldFlags, MobileObject* obj);
};

struct FUN_00932520_shell : MobileObject
{
    void UpdateFlags(unsigned int aiFlags, unsigned int aiOldFlags);
};

// Calls the base flag update, then updates the character controller or actor deletion queue depending on the actor state and flags.
// @fnv 0x00932520
void FUN_00932520_shell::UpdateFlags(unsigned int aiFlags, unsigned int aiOldFlags)
{
    reinterpret_cast<::fnv_0055f780::C0055f780 *>((((FUN_0055f780_cls*)this)))->FUN_0055f780(aiFlags, aiOldFlags);
    Actor* pactor = dynamic_cast<Actor*>(static_cast<MobileObject*>(this));
    if (pactor && (reinterpret_cast<::FUN_004f8960_shell *>((pactor))->FUN_004f8960() == 2 || reinterpret_cast<::FUN_004f8960_shell *>((pactor))->FUN_004f8960() == 1))
    {
        Unk_A8();
    }
    else if (aiFlags & 6)
    {
        bhkCharacterController* pcon = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
        if (pcon && ((LowProcess*)this)->GetTarget())
            reinterpret_cast<::C70CharacterController *>((pcon))->FUN_00c70c90((::WorldProxy *)((intptr_t)((::fnv_00932520::bhkWorld *)(reinterpret_cast<::FUN_004543c0_cls *>(((TESObjectCELL*)((LowProcess*)this)->GetTarget()))->FUN_004543c0()))));
        if (pcon && !reinterpret_cast<::FUN_005c0860Class *>((((FUN_005c0860Class*)pcon)))->FUN_005c0860())
        {
            NiPoint3 pos = *((TopicH*)this)->GetAddTopicList();
            reinterpret_cast<::S005620e0_Object *>((((CharCtl_S*)pcon)))->FUN_005620e0((const ::S005620e0_Source *)(void *)(&pos));
        }
    }
    if (*(Proc_00932520**)&this->m_pBaseProcess)
    {
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_00932520::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
        if (reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80() || GetDisabled())
        {
            reinterpret_cast<::ActorDeletionQueue *>((((ActorDeletionQueue*)&(*reinterpret_cast<::fnv_00932520::ProcessLists *>(&::g_011e0e80)))))->FUN_0096d470(this, ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)*(Proc_00932520**)&this->m_pBaseProcess)))->FUN_0045cd60())));
            delete *(Proc_00932520**)&this->m_pBaseProcess;
            *(Proc_00932520**)&this->m_pBaseProcess = 0;
        }
        else if (!((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((FUN_00577330_cls*)this)))->FUN_0043fcd0())) && this != (*reinterpret_cast<::MobileObject * *>(&::_g_thePlayer)) &&
                 (!((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)*(Proc_00932520**)&this->m_pBaseProcess)))->FUN_0045cd60())) ||
                  ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)*(Proc_00932520**)&this->m_pBaseProcess)))->FUN_0045cd60())) == 1))
        {
            Unk_92();
            reinterpret_cast<::FUN_00693d50_shell *>((((ActiveEffect*)*(Proc_00932520**)&this->m_pBaseProcess)))->FUN_00693d50(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::fnv_00932520::Calendar *>(&::g_011de7b8))))->GetGameTime() - 0.5);
            reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::fnv_00932520::ProcessLists *>(&::g_011e0e80))))->RemoveMobileObjectFromList(this);
        }
        reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_00932520::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();
        if (*(Proc_00932520**)&this->m_pBaseProcess)
            (*(Proc_00932520**)&this->m_pBaseProcess)->v564(aiFlags, aiOldFlags, this);
    }
}
}  // namespace fnv_00932520

namespace fnv_00932a00 {
struct AlchemyItem;
class SaveLoadFile;
struct EnchantmentItem;
class NiAVObject;
struct ThreeByThreeMatrix;
class NiQuaternion;
class TESBoundObject;
struct bhkRigidBody;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
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
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
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
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
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
struct FUN_00932a00_shell : public MobileObject
{
    void FUN_00932a00(BGSLoadFormBuffer*);
};

struct ProcLoad_00932a00
{
    virtual void pv000();
    virtual void pv001();
    virtual void pv002();
    virtual void pv003();
    virtual void pv004();
    virtual void pv005();
    virtual void pv006();
    virtual void pv007();
    virtual void pv008();
    virtual void pv009();
    virtual void pv010();
    virtual void pv011();
    virtual void pv012();
    virtual void pv013();
    virtual void pv014();
    virtual void pv015();
    virtual void pv016();
    virtual void pv017();
    virtual void pv018();
    virtual void pv019();
    virtual void pv020();
    virtual void pv021();
    virtual void pv022();
    virtual void pv023();
    virtual void pv024();
    virtual void pv025();
    virtual void pv026();
    virtual void pv027();
    virtual void pv028();
    virtual void pv029();
    virtual void pv030();
    virtual void pv031();
    virtual void pv032();
    virtual void pv033();
    virtual void pv034();
    virtual void pv035();
    virtual void pv036();
    virtual void pv037();
    virtual void pv038();
    virtual void pv039();
    virtual void pv040();
    virtual void pv041();
    virtual void pv042();
    virtual void pv043();
    virtual void pv044();
    virtual void pv045();
    virtual void pv046();
    virtual void pv047();
    virtual void pv048();
    virtual void pv049();
    virtual void pv050();
    virtual void pv051();
    virtual void pv052();
    virtual void pv053();
    virtual void pv054();
    virtual void pv055();
    virtual void pv056();
    virtual void pv057();
    virtual void pv058();
    virtual void pv059();
    virtual void pv060();
    virtual void pv061();
    virtual void pv062();
    virtual void pv063();
    virtual void pv064();
    virtual void pv065();
    virtual void pv066();
    virtual void pv067();
    virtual void pv068();
    virtual void pv069();
    virtual void pv070();
    virtual void pv071();
    virtual void pv072();
    virtual void pv073();
    virtual void pv074();
    virtual void pv075();
    virtual void pv076();
    virtual void pv077();
    virtual void pv078();
    virtual void pv079();
    virtual void pv080();
    virtual void pv081();
    virtual void pv082();
    virtual void pv083();
    virtual void pv084();
    virtual void pv085();
    virtual void pv086();
    virtual void pv087();
    virtual void pv088();
    virtual void pv089();
    virtual void pv090();
    virtual void pv091();
    virtual void pv092();
    virtual void pv093();
    virtual void pv094();
    virtual void pv095();
    virtual void pv096();
    virtual void pv097();
    virtual void pv098();
    virtual void pv099();
    virtual void pv100();
    virtual void pv101();
    virtual void pv102();
    virtual void pv103();
    virtual void pv104();
    virtual void pv105();
    virtual void pv106();
    virtual void pv107();
    virtual void pv108();
    virtual void pv109();
    virtual void pv110();
    virtual void pv111();
    virtual void pv112();
    virtual void pv113();
    virtual void pv114();
    virtual void pv115();
    virtual void pv116();
    virtual void pv117();
    virtual void pv118();
    virtual void pv119();
    virtual void pv120();
    virtual void pv121();
    virtual void pv122();
    virtual void pv123();
    virtual void pv124();
    virtual void pv125();
    virtual void pv126();
    virtual void pv127();
    virtual void pv128();
    virtual void pv129();
    virtual void pv130();
    virtual void pv131();
    virtual void pv132();
    virtual void pv133();
    virtual void pv134();
    virtual void pv135();
    virtual void pv136();
    virtual void pv137();
    virtual void pv138();
    virtual void pv139();
    virtual void pv140();
    virtual void pv141();
    virtual void pv142();
    virtual void pv143();
    virtual void pv144();
    virtual void pv145();
    virtual void pv146();
    virtual void pv147();
    virtual void pv148();
    virtual void pv149();
    virtual void pv150();
    virtual void pv151();
    virtual void pv152();
    virtual void pv153();
    virtual void pv154();
    virtual void pv155();
    virtual void pv156();
    virtual void pv157();
    virtual void pv158();
    virtual void pv159();
    virtual void pv160();
    virtual void pv161();
    virtual void pv162();
    virtual void pv163();
    virtual void pv164();
    virtual void pv165();
    virtual void pv166();
    virtual void pv167();
    virtual void pv168();
    virtual void pv169();
    virtual void pv170();
    virtual void pv171();
    virtual void pv172();
    virtual void pv173();
    virtual void pv174();
    virtual void pv175();
    virtual void pv176();
    virtual void pv177();
    virtual void pv178();
    virtual void pv179();
    virtual void pv180();
    virtual void pv181();
    virtual void pv182();
    virtual void pv183();
    virtual void pv184();
    virtual void pv185();
    virtual void pv186();
    virtual void pv187();
    virtual void pv188();
    virtual void pv189();
    virtual void pv190();
    virtual void pv191();
    virtual void pv192();
    virtual void pv193();
    virtual void pv194();
    virtual void pv195();
    virtual void pv196();
    virtual void pv197();
    virtual void pv198();
    virtual void pv199();
    virtual void pv200();
    virtual void pv201();
    virtual void pv202();
    virtual void pv203();
    virtual void pv204();
    virtual void pv205();
    virtual void pv206();
    virtual void pv207();
    virtual void pv208();
    virtual void pv209();
    virtual void pv210();
    virtual void pv211();
    virtual void pv212();
    virtual void pv213();
    virtual void pv214();
    virtual void pv215();
    virtual void pv216();
    virtual void pv217();
    virtual void pv218();
    virtual void pv219();
    virtual void pv220();
    virtual void pv221();
    virtual void pv222();
    virtual void pv223();
    virtual void pv224();
    virtual void pv225();
    virtual void pv226();
    virtual void pv227();
    virtual void pv228();
    virtual void pv229();
    virtual void pv230();
    virtual void pv231();
    virtual void pv232();
    virtual void pv233();
    virtual void pv234();
    virtual void pv235();
    virtual void pv236();
    virtual void pv237();
    virtual void pv238();
    virtual void pv239();
    virtual void pv240();
    virtual void pv241();
    virtual void pv242();
    virtual void pv243();
    virtual void pv244();
    virtual void pv245();
    virtual void pv246();
    virtual void pv247();
    virtual void pv248();
    virtual void pv249();
    virtual void pv250();
    virtual void pv251();
    virtual void pv252();
    virtual void pv253();
    virtual void pv254();
    virtual void pv255();
    virtual void pv256();
    virtual void pv257();
    virtual void pv258();
    virtual void pv259();
    virtual void pv260();
    virtual void pv261();
    virtual void pv262();
    virtual void pv263();
    virtual void pv264();
    virtual void pv265();
    virtual void pv266();
    virtual void pv267();
    virtual void pv268();
    virtual void pv269();
    virtual void pv270();
    virtual void pv271();
    virtual void pv272();
    virtual void pv273();
    virtual void pv274();
    virtual void pv275();
    virtual void pv276();
    virtual void pv277();
    virtual void pv278();
    virtual void pv279();
    virtual void pv280();
    virtual void pv281();
    virtual void pv282();
    virtual void pv283();
    virtual void pv284();
    virtual void pv285();
    virtual void pv286();
    virtual void pv287();
    virtual void pv288();
    virtual void pv289();
    virtual void pv290();
    virtual void pv291();
    virtual void pv292();
    virtual void pv293();
    virtual void pv294();
    virtual void pv295();
    virtual void pv296();
    virtual void pv297();
    virtual void pv298();
    virtual void pv299();
    virtual void pv300();
    virtual void pv301();
    virtual void pv302();
    virtual void pv303();
    virtual void pv304();
    virtual void pv305();
    virtual void pv306();
    virtual void pv307();
    virtual void pv308();
    virtual void pv309();
    virtual void pv310();
    virtual void pv311();
    virtual void pv312();
    virtual void pv313();
    virtual void pv314();
    virtual void pv315();
    virtual void pv316();
    virtual void pv317();
    virtual void pv318();
    virtual void pv319();
    virtual void pv320();
    virtual void pv321();
    virtual void pv322();
    virtual void pv323();
    virtual void pv324();
    virtual void pv325();
    virtual void pv326();
    virtual void pv327();
    virtual void pv328();
    virtual void pv329();
    virtual void pv330();
    virtual void pv331();
    virtual void pv332();
    virtual void pv333();
    virtual void pv334();
    virtual void pv335();
    virtual void pv336();
    virtual void pv337();
    virtual void pv338();
    virtual void pv339();
    virtual void pv340();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct FUN_00932a00_t : public MobileObject
{
    void FUN_00932a00(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x00932a00
void FUN_00932a00_t::FUN_00932a00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    char cprocessLevel = -1;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)&cprocessLevel), 1);
    reinterpret_cast<::fnv_009319c0::FUN_009319c0_shell *>(this)->FUN_009319c0(cprocessLevel);
    reinterpret_cast<::fnv_005623d0::RefX *>(this)->ApplyChanges((::fnv_005623d0::ChangeX *)(apLoadGameBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_cCharacterValue)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bNinthFlag)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bFirstFlag)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bFourthBooleanValue)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bFifthFlag)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bSecondBooleanValue)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bThirdFlag)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bTenthFlag)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->ProcessReferenceState)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->ReferenceMobileState)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bSixthFlag)), 1);
    if (apLoadGameBuffer->GetVersion() >= 8)
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)&this->m_bEighthFlag)), 1);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int*)((char*)this + 0x6c));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int*)((char*)this + 0x70));
    if (*(ProcLoad_00932a00**)&this->m_pBaseProcess)
        (*(ProcLoad_00932a00**)&this->m_pBaseProcess)->LoadGame(apLoadGameBuffer);
}
}  // namespace fnv_00932a00

namespace fnv_00932b70 {
struct AlchemyItem;
class SaveLoadFile;
struct EnchantmentItem;
class NiAVObject;
struct ThreeByThreeMatrix;
class NiQuaternion;
class TESBoundObject;
struct bhkRigidBody;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
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
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
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
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
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
struct FUN_00932b70_shell : public MobileObject
{
    void FUN_00932b70(BGSLoadFormBuffer*);
};

struct S_00562660
{
};
struct S_009319c0
{
};
struct RefX
{
};
struct RefA
{
};
struct TESResponse
{
};
struct Base_0092c950
{
    Base_0092c950();
    char pad[0xb4];
};
TESForm* GetFormByID(unsigned int);
struct Proc_00932b70
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
    virtual void v165();
    virtual void v166();
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
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void InitLoadGame(BGSLoadFormBuffer*);
};
struct Ref_00932b70
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual void r64();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual void r76();
    virtual void r77();
    virtual void r78();
    virtual void r79();
    virtual void r80();
    virtual void r81();
    virtual void r82();
    virtual void r83();
    virtual void r84();
    virtual void r85();
    virtual void r86();
    virtual void r87();
    virtual void r88();
    virtual void r89();
    virtual void r90();
    virtual void r91();
    virtual void r92();
    virtual void r93();
    virtual void r94();
    virtual void r95();
    virtual void r96();
    virtual void r97();
    virtual void r98();
    virtual void r99();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void AnimateNiNode();
    virtual void r114();
    virtual void Set3D(NiNode*, bool);
    virtual NiNode* GetNiNode();
    virtual void r117();
    virtual void r118();
    virtual void r119();
    virtual void r120();
    virtual void r121();
    virtual void r122();
    virtual void r123();
    virtual void r124();
    virtual void r125();
    virtual void r126();
    virtual void r127();
    virtual void r128();
    virtual void r129();
    virtual void r130();
    virtual void r131();
    virtual void r132();
    virtual void r133();
    virtual void r134();
    virtual void r135();
    virtual void r136();
    virtual bool Unk_89();
};

// @fnv 0x00932b70
void FUN_00932b70_shell::FUN_00932b70(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00562660::FUN_00562660_shell *>((((S_00562660*)this)))->FUN_00562660((::fnv_00562660::BGSLoadFormBuffer *)(apLoadGameBuffer));
    this->m_pLinkedReference =
        this->m_pLinkedReference
            ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0(*(unsigned int*)((char*)this + 0x6c)))
            : 0;
    this->m_pMobileObject =
        this->m_pMobileObject
            ? dynamic_cast<MobileObject*>(::FUN_004839c0(*(unsigned int*)((char*)this + 0x70)))
            : 0;
    if (*(Proc_00932b70**)&this->m_pBaseProcess)
        (*(Proc_00932b70**)&this->m_pBaseProcess)->InitLoadGame(apLoadGameBuffer);
    if (((Ref_00932b70*)this)->GetNiNode() && !((Ref_00932b70*)this)->Unk_89() && !((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
        ((Ref_00932b70*)this)->AnimateNiNode();
    if (!*(void**)&this->m_pBaseProcess && !reinterpret_cast<::FUN_00437b90_shell *>((((RefX*)this)))->FUN_00437b90())
    {
        *(Base_0092c950**)&this->m_pBaseProcess = new Base_0092c950;
        reinterpret_cast<::fnv_009319c0::FUN_009319c0_shell *>((((S_009319c0*)this)))->FUN_009319c0(GetProcessTier());
    }
    if (((::fnv_00932b70::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((RefA*)this)))->FUN_0043fcd0())))
    {
        if (!*(void**)&this->m_pBaseProcess || ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>(((*(TESResponse**)&this->m_pBaseProcess)))->FUN_0045cd60())) == 3 ||
            ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>(((*(TESResponse**)&this->m_pBaseProcess)))->FUN_0045cd60())) == 2)
            ((Ref_00932b70*)this)->Set3D(0, true);
    }
}
}  // namespace fnv_00932b70

struct FUN_00933150_shell : TESObjectREFR
{
    SoundPlaybackHandle PlaySoundByFormID(unsigned int formID, bool loop, unsigned int flags, bool follow);
};

// Looks up a sound handle by form ID, positions it at this reference's position when flags has bit 2 and a node exists, then plays it and returns the handle.
// @fnv 0x00933150
SoundPlaybackHandle FUN_00933150_shell::PlaySoundByFormID(unsigned int formID, bool loop, unsigned int flags, bool follow)
{
    SoundPlaybackHandle sound;
    sound = ::FUN_00453a70()->GetSoundHandleByFormID(formID, flags);
    if (((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) && (flags & 2))
    {
        NiPoint3 position = *GetPos();
        reinterpret_cast<::FUN_00ad8b60_h *>(&(sound))->FUN_00ad8b60(position.x, position.y, position.z);
        reinterpret_cast<::FUN_00ad8f20_shell *>(&(sound))->FUN_00ad8f20(reinterpret_cast<NiAVObject*>(((intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))));
    }
    reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(loop);
    return sound;
}

struct ActorValueInfo;
struct BGSLoadFormBuffer;
class BGSPerk;
struct FormRecordHeader;
struct TESFileGroup;
class TESResponseList;
class TESActorBase;
struct TESTopicInfoData;
class TESFile;
class TESQuest;
struct TopicInfoData;
class TESTopicInfo : public TESForm
{
  public:
    virtual void __vslot_10();
    virtual void Save();
    virtual bool Load(TESFile*);
    virtual void Copy(TESForm*);
    virtual void InitItem();
    virtual void ResetFormData();
    virtual void ClearData();
    void SetOwnerTopic(TESTopic*);
    virtual void SetAltered(bool);
    virtual bool CopyTopicData(FormRecordHeader*);
    virtual bool CopyTopicData(TESForm*);
    virtual bool LoadTopicInfoData(FormRecordHeader*, bool, bool);
    virtual void CreateGroupData(FormRecordHeader*, TESFileGroup*);
    virtual void SerializeTopicInfoData(void*);
    int GetTopicType();
    int GetNextSpeaker();
    void SetNextSpeaker(int);
    void SetInfoIndex(unsigned short);
    void SetConditionList(PerkEntryConditionSet*);
    void* GetAddTopicList();
    bool InAddTopicList(TESTopic*);
    void FormatDebugInfo(void*, bool);
    void SetOwnerQuest(TESQuest*);
    bool IsGoodbye();
    void SetGoodbye(bool);
    void SetRandomEnd(bool);
    bool IsSayOnce();
    void SetSayOnce(bool);
    bool IsInfoRefusal();
    void SetInfoRefusal(bool);
    bool IsRunImmediately();
    void SetRunImmediately(bool);
    bool IsRunRumorResults();
    void SetRunRumorResults(bool);
    bool IsSpeechChallenge();
    void SetSpeechChallenge(bool);
    void SetSayOnceADay(bool);
    bool IsAlwaysDarkened();
    void SetAlwaysDarkened(bool);
    int GetDummyNodeState();
    void SetDummyNodeState(int);
    void SetTopicInfoData(TESTopicInfoData*);
    void* GetPrompt();
    void SetPrompt(char*);
    ActorValueInfo* GetActorValue();
    BGSPerk* GetPerk();
    TESForm* GetPerkSkillStat();
    int GetDifficultyLevel();
    void SetDifficultyLevel(int);
    void CloneResponseList(TESResponseList*);
    Script* GetResultScript(intptr_t);
    unsigned int GetTempDataOffset();
    void SetTempDataOffset(unsigned int);
    bool IsInfoValidForDialogue(bool*, TESQuest*, TESObjectREFR*, TESObjectREFR*);
    bool IsInfoValidForDialogue(TESQuest*, TESObjectREFR*, TESObjectREFR*);
    void HyperLinkCompile(char*);
    void RemoveHyperLinks();
    void AppendTopicInfo(int, TESObjectREFR*);
    void AddTopicList();
    bool SaidOnce();
    void SetSaidOnce();
    void ResetSaidOnceFlags();
    bool IsValidSaveID(bool);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void LoadGame(unsigned int, unsigned int);
    virtual void Revert(BGSLoadFormBuffer*);
    virtual void Revert(unsigned int);
    TESResponseList* DuplicateResponseList(TESResponseList*);
    void ClearResponses();
    void ResetResponseList();
    TopicInfoData* GetData();
    static void AddTopicInfoToSortedList(TESTopicInfo*, void*);
    static bool CompareTopicInfos(TESTopicInfo*, TESTopicInfo*);
    PerkEntryConditionSet m_kInfoConditions;
    unsigned short m_uiInfoIndex;
    bool m_bGoodbye;
    char m_Data[4];
    char _pad_27[1];
    char m_kPrompt[8];
    char m_kAddTopicList[8];
    TESTopicInfoData* m_pResponseData;
    TESActorBase* m_pDialogueSpeaker;
    TESForm* m_pPerkSkillStat;
    int m_eDifficultyLevel;
    TESQuest* m_pOwnerQuest;
    unsigned long m_ulTopicFlags;
};
struct FUN_00934250_shell : public MobileObject
{
    void FUN_00934250();
};

struct FUN_0042edb0_shell
{
    void FUN_0042edb0();
};
struct FUN_0057bd40_shell
{
    TESTopic* FUN_0057bd40();
};
struct SC_008c48d0
{
};
struct FUN_008a5530_shell
{
    void FUN_008a5530();
};
struct XActor
{
    TESTopicInfo* FUN_00934430();
};
struct Character;
struct RunResultScript_helper
{
};
struct SetSayToTopic_helper
{
};
class PlayerCharacter
{
  public:
};
// @fnv 0x00934250
void FUN_00934250_shell::FUN_00934250()
{
    BaseProcess* pProcess = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)this)))->GetBaseTexture()));
    if (pProcess && reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::SoundPlaybackHandle &)(pProcess->GetActorSoundHandle(0)))->IsValid())
    {
        TESTopicInfo* pTopicInfo = ((XActor*)this)->FUN_00934430();
        TESTopic* pMenuTopicEntry = ((FUN_0057bd40_shell*)this)->FUN_0057bd40();
        reinterpret_cast<::fnv_0057ad20::FUN_0057ad20_shell *>((((SetSayToTopic_helper*)this)))->FUN_0057ad20((::fnv_0057ad20::TESTopic *)(::TESTopic *)(0));
        ((FUN_0042edb0_shell*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0())))->FUN_0042edb0();
        if (pTopicInfo)
        {
            if (!FUN_00579200((char const*)pTopicInfo))
                reinterpret_cast<::FUN_0061f170_cls *>((((RunResultScript_helper*)pTopicInfo)))->FUN_0061f170((void *)(1), (::ArgObj *)(::Character *)((Character*)this));
            ::FUN_005ac750((::TESForm *)(pMenuTopicEntry), ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0())), 0x40000);
            *((unsigned char*)&this->m_bEighthFlag) = 1;
            ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)this)))->GetBaseTexture()))->SetCombatEnabled(false);
        }
        *((unsigned char*)&this->m_cCharacterValue) = 0xff;
        pProcess->StopActorSound(0);
        pProcess->SetCombatAlerted(false);
        reinterpret_cast<::FUN_00953ce0_Class *>((_g_thePlayer))->FUN_00953ce0();
    }
    *((unsigned char*)&this->m_bFifthFlag) = 1;
    *((unsigned char*)&this->m_bFourthBooleanValue) = 1;
    if (!((bool)(::FUN_00574900((const unsigned char *)this))) && GetNiNode())
    {
        Actor* pactor = (Actor*)this;
        ((FUN_008a5530_shell*)pactor)->FUN_008a5530();
    }
}

namespace fnv_009c45d0 {
class RecursiveSpinLock
{
};
struct TES
{
};
struct TESResponse
{
};
struct LowProcess
{
    TESSound* GetTarget();
};
struct ActorDeletionQueue
{
};
struct Loader_S
{
    bool FUN_00445750(void*);
};
struct BGSSaveLoadGame_S
{
};
struct ProcessDel
{
    virtual ~ProcessDel();
};
struct FUN_009c45d0_t : public MobileObject
{
    bool FUN_009c45d0();
};
struct MobileVtbl
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
    virtual void MarkForDeletion(bool);
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
    virtual int V1D0();
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
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void V240();
    virtual void p145();
    virtual void p146();
    virtual void V24C();
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
    virtual void V2A0();
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
    virtual void V2FC();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p200();
    virtual bool V324();
};

// Compares the current level with a level derived from cell load state and switches, queues for deletion, or resets the object accordingly.
// @fnv 0x009c45d0
bool FUN_009c45d0_t::FUN_009c45d0()
{
    bool result2 = true;
    int curLevel3 = *(TESResponse**)&this->m_pBaseProcess ? ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>(((*(TESResponse**)&this->m_pBaseProcess)))->FUN_0045cd60())) : 3;
    int iNewLevel = 3;
    bool bLoadedTmp = ((MobileVtbl*)this)->V324();
    TESObjectCELL* cellVal = (TESObjectCELL*)((LowProcess*)this)->GetTarget();
    if (((MobileVtbl*)this)->V1D0() || (*reinterpret_cast<::fnv_009c45d0::Loader_S * *>(&::g_modelLoader))->FUN_00445750(this))
    {
        if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_009c45d0::TES * *>(&::g_TES))))->IsCellBuffered(cellVal, true))
        {
            iNewLevel = 0;
        }
        else if (bLoadedTmp && reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_009c45d0::TES * *>(&::g_TES))))->IsCellBuffered(cellVal, false))
        {
            iNewLevel = 1;
        }
    }
    if (curLevel3 != iNewLevel)
    {
        if (iNewLevel == 0)
        {
            ((MobileVtbl*)this)->V240();
        }
        else if (iNewLevel == 1)
        {
            ((MobileVtbl*)this)->V24C();
        }
        else if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))
        {
            if (bLoadedTmp)
            {
                reinterpret_cast<::SLGameShell *>(((*reinterpret_cast<::fnv_009c45d0::BGSSaveLoadGame_S * *>(&::g_BGSSaveLoadGame))))->FUN_00849730((::TESForm *)(void *)(this), 0);
            }
            ((MobileVtbl*)this)->MarkForDeletion(true);
            result2 = false;
        }
        else
        {
            intptr_t lvl = ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>(((*(TESResponse**)&this->m_pBaseProcess)))->FUN_0045cd60()));
            reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_009c45d0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
            reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::fnv_009c45d0::ActorDeletionQueue *>(&::g_011e0e80))))->FUN_0096d470(this, lvl);
            delete *(ProcessDel**)&this->m_pBaseProcess;
            *(ProcessDel**)&this->m_pBaseProcess = 0;
            reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_009c45d0::RecursiveSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();
            ((MobileVtbl*)this)->V2A0();
            ((MobileVtbl*)this)->V2FC();
        }
    }
    return result2;
}
}  // namespace fnv_009c45d0

namespace fnv_0092f260 {
struct AlchemyItem;
struct EnchantmentItem;
class NiAVObject;
struct NiStream;
class TESBoundObject;
struct bhkRigidBody;
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
    void SetZRotation(float);
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
struct FUN_0092f260_shell : public MobileObject
{
    bhkCharacterController* FUN_0092f260(float, NiPoint3*, unsigned int);
};

class PlayerCharacter;
class TES;
struct FUN_00440460_S
{
};
struct SetLoc_S
{
};
extern double DAT_0108a7a0;
extern unsigned int DAT_011e054c;

struct Setting_S
{
};
struct GlobalObject2_0040c150
{
};
struct Twin_0084d030
{
};
extern Setting_S DAT_01267bd4;

struct hkpCharacterContext
{
};
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
struct LowProcess
{
    TESObjectCELL* GetTarget();
    TESObjectCELL* GetCurrentBoundObject();
};
struct MobileObject_Helper
{
};
struct TESWaterHelper
{
};
struct FUN_0080f790_S
{
};
struct FUN_008846e0_shell
{
};
struct Act_009e3520
{
};
struct FUN_008b8f90_S
{
};

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float, float, float);
    NiPoint3 operator+(const NiPoint3&) const;
};
class NiPoint3_ext : public NiPoint3
{
  public:
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3_ext& operator+=(const NiPoint3&);
};
struct TESAngleHelper
{
    void SetReferencePosition(NiPoint3Ex);
};

struct NiMatrix3PC
{
    float m_afEntries[3][3];
    NiPoint3 operator*(const NiPoint3&) const;
};

class BSFadeNode;
struct NiAVObjectVT
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual BSFadeNode* vfn_10();
};
struct FUN_00b4e030_S
{
};
const NiPoint3& FUN_0045bb80(void*);
struct FUN_00561730_S
{
};

struct PathingLocation
{
    char data[0x28];
    PathingLocation(TESObjectREFR*);
    ~PathingLocation();
};

struct __declspec(align(16)) hkQuaternion
{
    float m_vec[4];
    void FUN_00cb2450(void*, float);
};
struct __declspec(align(16)) hkVector4
{
    float m_vComponents[4];
};

struct MovementPose
{
    float fMoveElapsedTime;
    NiPoint3 Angle;
    NiPoint3 DeltaMove;
    unsigned int iMoveDir;
    float fSpeed;
    bool bFlag;
};
void* FUN_009304d0(MovementPose*);

struct FUN_0088b0a0_c
{
    void set(int);
};
struct CharFlags
{
};
struct bhkCharControllerVT
{
    virtual void vt00();
    virtual void vt01();
    virtual void vt02();
    virtual void vt03();
    virtual void vt04();
    virtual void vt05();
    virtual void vt06();
    virtual void vt07();
    virtual void vt08();
    virtual void vt09();
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
    virtual void vfn_C8(MovementPose* apMoveData);
    int FUN_00621ad0();
};
struct MobileObjectVT
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
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual bool vfn_224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void vfn_2A8(NiPoint3* apPos);
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual float vfn_2BC(bool abFlag);
    virtual void v2C0();
    virtual void vfn_2C4(float afValue);
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual bool vfn_2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual bool vfn_38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44C();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45C();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46C();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47C();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48C();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49C();
    virtual void v4A0();
    virtual void v4A4();
    virtual void v4A8();
    virtual void v4AC();
    virtual void v4B0();
    virtual bool vfn_4B4();
};

// @fnv 0x0092f260
bhkCharacterController* FUN_0092f260_shell::FUN_0092f260(float afDeltaTime, NiPoint3* arDeltaMove,
                                                         unsigned int aiMoveDir)
{
    Actor* pactor = ((MobileObject*)this)->IsActor() ? (Actor*)this : 0;
    bhkCharacterController* pcon = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((((MobileObject*)this)))->FUN_009306d0()));
    bool bisProjectile = ((MobileObjectVT*)this)->vfn_224();
    if (pactor && pactor->GetActorValue((ActorValue::Index)0x33) > 0)
        afDeltaTime /= ::FUN_00716440();

    NiPoint3 pos = *((TopicH*)this)->GetAddTopicList();
    !std::isnan(arDeltaMove->x) && !std::isnan(arDeltaMove->y) && !std::isnan(arDeltaMove->z);

    float fanglex = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(((MobileObject*)this)))->GetData())).x;
    float fangley = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(((MobileObject*)this)))->GetData())).y;
    float fanglez = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(((MobileObject*)this)))->GetData())).z;
    if (fanglex == ::_DAT_010231b0 || std::isnan(fanglex) || !std::isfinite(fanglex) || fangley == ::_DAT_010231b0 ||
        std::isnan(fangley) || !std::isfinite(fangley) || fanglez == ::_DAT_010231b0 || std::isnan(fanglez) ||
        !std::isfinite(fanglez))
    {
        ::FUN_005b5e40();
        ((TESAngleHelper*)this)->SetReferencePosition(NiPoint3Ex(0, 0, 0));
    }

    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0092f260::GlobalObject2_0040c150 *>(&::g_011e05b4)))))))
    {
        unsigned int iFrameCounter = ((unsigned int)(::FUN_009304a0()));
        if (DAT_011e054c != iFrameCounter)
        {
            if (iFrameCounter % (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0092f260::GlobalObject2_0040c150 *>(&::g_011e05b4)))))) + 1))
                DAT_011e0550 = true;
            else
                DAT_011e0550 = false;
            DAT_011e054c = iFrameCounter;
        }
        if (DAT_011e0550 && ((bool)(reinterpret_cast<::DummyFlags *>((((bhkCharControllerVT*)pcon)))->FUN_0088b0c0())))
        {
            NiMatrix3PC rot;
            if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
                reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(reinterpret_cast<::FUN_0080f790_shell *>((((FUN_0080f790_S*)this)))->GetAngleZOnReference(false));
            else
                reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
            *arDeltaMove = rot * *arDeltaMove;
            pos = (const NiPoint3Ex&)reinterpret_cast<::NiAVObject *>((((NiAVObjectVT*)((MobileObject*)this)->GetNiNode())))->FUN_0043c490() + *arDeltaMove;
            reinterpret_cast<::FUN_00440460_S *>((((FUN_00440460_S*)((MobileObject*)this)->GetNiNode())))->FUN_00440460((const ::V3 *)(const ::NiPoint3 *)(&pos));
            return pcon;
        }
        else
        {
            NiPoint3 largeDelta =
                (const NiPoint3_ext&)reinterpret_cast<::NiAVObject *>((((NiAVObjectVT*)((MobileObject*)this)->GetNiNode())))->FUN_0043c490() -
                *((MobileObject*)this)->GetPos();
            NiMatrix3PC rot;
            if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
                reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(reinterpret_cast<::FUN_0080f790_shell *>((((FUN_0080f790_S*)this)))->GetAngleZOnReference(false));
            else
                reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::fnv_0092f260::NiPoint3_ext &)(*(NiPoint3_ext*)arDeltaMove))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)((*(::fnv_0092f260::NiMatrix3PC *)(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(rot))->FUN_004b45b0({}))) * largeDelta));
        }
    }

    bool bdynamicMotionActor = pactor ? ((MobileObjectVT*)pactor)->vfn_4B4() : false;
    unsigned int uiSitState = ((MobileObject*)this)->Unk_85();
    bool bsittingCheckSupport = uiSitState && pcon && ((int)(reinterpret_cast<::S00561730_Vector *>((((::fnv_0092f260::FUN_00561730_S *)(::FUN_0089d600((char *)(pcon))))))->FUN_00561730((const ::S00561730_Vector *)(void *)(::FUN_00458b20()), 0.001f)));
    bool bshouldSitStateUpdate = !uiSitState || bsittingCheckSupport;
    NiPoint3 diff = (const NiPoint3_ext&)*((MobileObject*)this)->GetPos() - FUN_0045bb80(((void *)(::FUN_00524c90())));
    float flengthSqr = reinterpret_cast<::TESCombatStyle *>((void *)&(diff))->UpdateCombatStyle();
    bool bisImmobile = pactor ? (((bool)(reinterpret_cast<::FUN_00437bd0_stub *>((pactor))->FUN_00437bd0())) || pactor->Unk_8B(false) ||
                                 ((MobileObjectVT*)pactor)->vfn_2E8() || pactor->Unk_8C())
                              : false;

    if (flengthSqr > *((float *)&(::FUN_00403e20((float *)&(DAT_01267bd4)))) && !((MobileObjectVT*)this)->vfn_224() && !bdynamicMotionActor &&
        !bisImmobile && (MobileObject*)this != (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
    {
        NiPoint3 tmpLoc = pos;
        NiPoint3 tmpMove = *arDeltaMove;
        NiMatrix3PC rot;
        if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
            reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(reinterpret_cast<::FUN_0080f790_shell *>((((FUN_0080f790_S*)this)))->GetAngleZOnReference(false));
        else
            reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
        tmpMove = rot * tmpMove;
        reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::fnv_0092f260::NiPoint3_ext &)((NiPoint3_ext&)tmpLoc))->FUN_0063c8a0((void *)&(tmpMove));
        TESWorldSpace* pws = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((void *)(((MobileObject*)this)))->FUN_00575d70()));
        TESObjectCELL* pCell = ((LowProcess*)this)->GetTarget();
        float fheightNavMesh;
        if (::FUN_006d97b0((*(const ::NiPoint3 *)(&tmpLoc)), pCell, pws, &fheightNavMesh))
        {
            if (pcon && ::FUN_005c0880((char *)(pcon)) == 5)
            {
                if (*(float*)(*(char**)&this->m_pRenderData + 8) == ::DAT_010241b0)
                    *(float*)(*(char**)&this->m_pRenderData + 8) =
                        reinterpret_cast<::FUN_0045cbc0_shell *>((((TESWaterHelper*)(*reinterpret_cast<::fnv_0092f260::TES * *>(&::g_TES)))))->GetCellHeightAtPosition((const ::NiPoint3 *)&(*((MobileObject*)this)->GetPos()), (::CellView *)(0));
                float fheightWater = reinterpret_cast<::FUN_0057b0a0_shell *>((void *)(((MobileObject_Helper*)this)))->FUN_0057b0a0();
                if (fheightWater == ::DAT_010241b0)
                {
                    if (pcon)
                    {
                        if (reinterpret_cast<::FUN_0087f390_shell *>(((MobileObject*)this))->FUN_0087f390())
                            reinterpret_cast<::FUN_0088b0a0_c *>((((FUN_0088b0a0_c*)pcon)))->set(2);
                        else
                            reinterpret_cast<::FUN_0088b0a0_c *>((((FUN_0088b0a0_c*)pcon)))->set(0);
                        tmpLoc.z = fheightNavMesh;
                    }
                }
                else if (tmpLoc.z > fheightWater)
                {
                    tmpLoc.z = fheightWater;
                }
                else if (tmpLoc.z < fheightNavMesh && fheightNavMesh < fheightWater)
                {
                    tmpLoc.z = fheightNavMesh;
                }
            }
            else if (!uiSitState && !bsittingCheckSupport)
            {
                tmpLoc.z = fheightNavMesh;
            }
            if (pcon && ((bhkCharControllerVT*)pcon)->FUN_00621ad0() && !((bool)(::HasFlag40000((::DummyFlags *)(((bhkCharControllerVT*)pcon))))) &&
                (reinterpret_cast<::fnv_009305a0::FUN_009305a0_Holder *>((((bhkCharControllerVT*)pcon)))->FUN_009305a0() || reinterpret_cast<::fnv_009305a0::FUN_009305a0_Holder *>((((bhkCharControllerVT*)pcon)))->FUN_009305a0() ||
                 ::FUN_008a5170((const ::_Dummy_008a5170 *)(::fnv_0092f260::CharFlags *)((CharFlags*)((char*)pcon + 0x410)))))
            {
                NiPoint3 hitNormal;
                PathingLocation kPathingLocation((TESObjectREFR*)this);
                ::GetPathingLocationNormal((*(::PathingLocation *)(&kPathingLocation)), (*(::NiPoint3 *)(&hitNormal)));
                hkVector4 kSupportNormal;
                ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kSupportNormal), (const ::fnv_004a3e00::NiPoint3 &)(hitNormal));
                reinterpret_cast<::T_ *>((((bhkCharControllerVT*)pcon)))->ForwardToMember((intptr_t)(&kSupportNormal));
                reinterpret_cast<::FUN_00930620_shell *>((((bhkCharControllerVT*)pcon)))->FUN_00930620();
                reinterpret_cast<::CharacterProbeLocal *>((((bhkCharControllerVT*)pcon)))->FUN_00c6e820();
                reinterpret_cast<::AimController_c70060 *>((((bhkCharControllerVT*)pcon)))->FUN_00c70060();
                float fzAngle = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(((MobileObject*)this)))->GetData())).z;
                hkQuaternion kQuat;
                ::FUN_006240d0(&kQuat);
                kQuat.FUN_00cb2450((char*)pcon + 0x4c0, -fzAngle);
                reinterpret_cast<::RotationOwner *>((((bhkCharControllerVT*)pcon)))->FUN_00c6e420((::FUN_005611c0_t *)(::fnv_0092f260::hkQuaternion *)(&kQuat));
            }
            ((MobileObjectVT*)this)->vfn_2A8(&tmpLoc);
            if (pcon && ::FUN_005c0880((char *)(pcon)) == 2)
                reinterpret_cast<::s008e2680::Owner *>((((bhkCharControllerVT*)pcon)))->FUN_008e2680(false);
            return pcon;
        }
    }

    if (bshouldSitStateUpdate)
    {
        if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
            reinterpret_cast<::FUN_00629670_Class *>((((CharFlags*)((char*)pcon + 0x410))))->FUN_00629670(0x8000000, bdynamicMotionActor);
        if (pcon && !((MobileObject*)this)->Unk_8B(true))
        {
            MovementPose kMoveData;
            FUN_009304d0(&kMoveData);
            kMoveData.fMoveElapsedTime = afDeltaTime;
            kMoveData.Angle = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(((MobileObject*)this)))->GetData()));
            kMoveData.DeltaMove = *arDeltaMove;
            kMoveData.iMoveDir = aiMoveDir;
            kMoveData.bFlag = true;
            if ((MobileObject*)this != (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)) && pactor)
            {
                NiAVObject* pNode = (NiAVObject*)((MobileObject*)this)->GetNiNode();
                BSFadeNode* pfadeNode = pNode ? ((NiAVObjectVT*)pNode)->vfn_10() : 0;
                kMoveData.bFlag =
                    pfadeNode ? reinterpret_cast<::FUN_00b4e030_shell *>((((FUN_00b4e030_S*)pfadeNode)))->IsWithinFadeDistance((::NiCamera *)(void *)(((void *)(::FUN_00524c90()))), 0.8f) : true;
            }
            if (reinterpret_cast<::DummyFlagsShell *>((((bhkCharControllerVT*)pcon)))->FUN_00621240() && !bsittingCheckSupport)
            {
                NiPoint3 oldPos;
                NiMatrix3PC rot;
                if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
                    reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(reinterpret_cast<::FUN_0080f790_shell *>((((FUN_0080f790_S*)this)))->GetAngleZOnReference(false));
                else
                    reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
                *arDeltaMove = rot * *arDeltaMove;
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::fnv_0092f260::NiPoint3_ext &)((NiPoint3_ext&)pos))->FUN_0063c8a0((void *)&(*arDeltaMove));
                reinterpret_cast<::VectorSourceB00 *>((((bhkCharControllerVT*)pcon)))->FUN_00812b00(&oldPos);
                *arDeltaMove = (const NiPoint3_ext&)pos - oldPos;
                kMoveData.DeltaMove = (*(::fnv_0092f260::NiMatrix3PC *)(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(rot))->FUN_004b45b0({}))) * *arDeltaMove;
            }
            if (reinterpret_cast<::fnv_009305a0::FUN_009305a0_Holder *>((((bhkCharControllerVT*)pcon)))->FUN_009305a0() || reinterpret_cast<::fnv_009305d0::FUN_009305d0_shell *>((((bhkCharControllerVT*)pcon)))->FUN_009305d0())
            {
                reinterpret_cast<::FUN_00629650_Class *>((((CharFlags*)((char*)pcon + 0x410))))->FUN_00629650(0);
                ::SetField558((void *)(((bhkCharControllerVT*)pcon)), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0092f260::Setting_S *>(&::g_011e0574)))))) * ::fnv::timer::Seconds());
            }
            if (pactor && (reinterpret_cast<::FUN_008846e0_shell *>((((FUN_008846e0_shell*)pactor)))->GetVtbl20Result() & 0x3f))
                kMoveData.fSpeed = reinterpret_cast<::fnv_008a0b10::FUN_008a0b10_shell *>((((Act_009e3520*)pactor)))->FUN_008a0b10();
            else
                kMoveData.fSpeed = 0;
            if (bdynamicMotionActor &&
                ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)) || !((MobileObjectVT*)pactor)->vfn_38C()))
                reinterpret_cast<::C70B60Character *>((((bhkCharControllerVT*)pcon)))->FUN_00c70b60((::C70B60UpdateData *)(::fnv_0092f260::MovementPose *)(&kMoveData), (MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)));
            else
                ((bhkCharControllerVT*)pcon)->vfn_C8(&kMoveData);
            if (((bool)(reinterpret_cast<::fnv_009304b0::DummyFlags *>((((CharFlags*)((char*)pcon + 0x410))))->HasFlag20())))
            {
                NiPoint3 newPos;
                reinterpret_cast<::VectorSourceB00 *>((((bhkCharControllerVT*)pcon)))->FUN_00812b00(&newPos);
                float flift = ::FUN_004587d0(reinterpret_cast<::FUN_00c6e280_cls *>((pcon))->GetSettingFloat()) * 2.0f;
                newPos.z += flift;
                ((MobileObjectVT*)this)->vfn_2A8(&newPos);
            }
            if (!reinterpret_cast<::DummyFlagsShell *>((((bhkCharControllerVT*)pcon)))->FUN_00621240())
            {
                reinterpret_cast<::VectorSourceB00 *>((((bhkCharControllerVT*)pcon)))->FUN_00812b00(&pos);
                if (::FUN_008a5170((const ::_Dummy_008a5170 *)(::fnv_0092f260::CharFlags *)((CharFlags*)((char*)pcon + 0x410))) && !bdynamicMotionActor)
                    ((MobileObjectVT*)this)->vfn_2C4(kMoveData.Angle.z);
                if (reinterpret_cast<::TESCombatStyle *>((void *)&ResultSlot((const NiPoint3_ext&)pos - *((MobileObject*)this)->GetPos()))->UpdateCombatStyle() > DAT_0108a7a0)
                {
                    pos = *((MobileObject*)this)->GetPos();
                    ((MobileObjectVT*)this)->vfn_2A8(&pos);
                }
                float fheight = 0;
                if (!((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((LowProcess*)(*reinterpret_cast<::fnv_0092f260::TES * *>(&::g_TES)))))->GetPrevPath())))
                {
                    reinterpret_cast<::FUN_004572e0_shell *>((((TESWaterHelper*)(*reinterpret_cast<::fnv_0092f260::TES * *>(&::g_TES)))))->GetLandHeightAt((*(const ::NiPoint3 *)(&pos)), (*(float *)(&fheight)));
                    if (fheight - pos.z > ::DAT_0101db88)
                    {
                        pos.z = fheight;
                        ((MobileObjectVT*)this)->vfn_2A8(&pos);
                    }
                }
            }
            if (pactor)
                reinterpret_cast<::fnv_008b8f90::TaskOwner *>((((FUN_008b8f90_S*)pactor)))->ProcessTargets();
        }
        else
        {
            NiMatrix3PC rot;
            if (((MobileObjectVT*)this)->vfn_224())
            {
                reinterpret_cast<::FUN_00524ac0_shell *>(&(rot))->FUN_00524ac0(((MobileObject*)this)->GetLooking());
                *arDeltaMove = rot * *arDeltaMove;
            }
            if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
                reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(reinterpret_cast<::FUN_0080f790_shell *>((((FUN_0080f790_S*)this)))->GetAngleZOnReference(false));
            else
                reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
            *arDeltaMove = rot * *arDeltaMove;
            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::fnv_0092f260::NiPoint3_ext &)((NiPoint3_ext&)pos))->FUN_0063c8a0((void *)&(*arDeltaMove));
        }
    }
    else if (((MobileObject*)this)->Unk_8B(false) && !bdynamicMotionActor)
    {
        NiMatrix3PC rot;
        if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
            reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(reinterpret_cast<::FUN_0080f790_shell *>((((FUN_0080f790_S*)this)))->GetAngleZOnReference(false));
        else
            reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
        *arDeltaMove = rot * *arDeltaMove;
        reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::fnv_0092f260::NiPoint3_ext &)((NiPoint3_ext&)pos))->FUN_0063c8a0((void *)&(*arDeltaMove));
    }

    if (uiSitState || bsittingCheckSupport)
    {
        MovementPose kMoveData;
        FUN_009304d0(&kMoveData);
        kMoveData.fMoveElapsedTime = afDeltaTime;
        kMoveData.Angle = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(((MobileObject*)this)))->GetData()));
        kMoveData.DeltaMove = *arDeltaMove;
        kMoveData.iMoveDir = aiMoveDir;
        kMoveData.bFlag = true;
        if (!bsittingCheckSupport)
            reinterpret_cast<::C70B60Character *>((((bhkCharControllerVT*)pcon)))->FUN_00c70b60((::C70B60UpdateData *)(::fnv_0092f260::MovementPose *)(&kMoveData), false);
        if (bsittingCheckSupport)
        {
            reinterpret_cast<::FUN_00930540_shell *>((((bhkCharControllerVT*)pcon)))->FUN_00930540(true);
            reinterpret_cast<::s008e2680::Owner *>((((bhkCharControllerVT*)pcon)))->FUN_008e2680(false);
        }
        NiMatrix3PC rot;
        if ((MobileObject*)this == (MobileObject*)(*reinterpret_cast<::fnv_0092f260::PlayerCharacter * *>(&::_g_thePlayer)))
            reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(reinterpret_cast<::FUN_0080f790_shell *>((((FUN_0080f790_S*)this)))->GetAngleZOnReference(false));
        else
            reinterpret_cast<::FUN_004a0c90_shell *>(&(rot))->FUN_004a0c90(((MobileObjectVT*)this)->vfn_2BC(false));
        *arDeltaMove = rot * *arDeltaMove;
        reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::fnv_0092f260::NiPoint3_ext &)((NiPoint3_ext&)pos))->FUN_0063c8a0((void *)&(*arDeltaMove));
    }

    reinterpret_cast<::Reference *>((((SetLoc_S*)this)))->FUN_00575830((::Position *)&(pos));
    return pcon;
}
}  // namespace fnv_0092f260

struct TopicInfoVisitRecord
{
    TESTopicInfo* pInfo;
    int iDate;
    float fHour;
};
class BSExtraData
{
  public:
    virtual ~BSExtraData();
    unsigned char m_ucExtraDataType;
    BSExtraData* pNext;
};
union UTSO_SettingValue
{
    bool b;
    char c;
    int i;
    unsigned int u;
    float f;
    char* s;
};
template <class Collection> class UTSO_SettingT
{
  public:
    UTSO_SettingValue* Float();
};
struct ExtraSayTopicInfoOnceADay : public BSExtraData
{
    BSSimpleList<TopicInfoVisitRecord*>* pList;
};
class DialogueResponse;
class DialogueItem
{
  public:
    TESObjectREFR* FUN_005e3fa0();
public:
    ::DialogueResponse *GetActiveResponse();
};

struct FUN_00935ae0_t : public MobileObject
{
    void FUN_00935ae0();
};

// Removes and deletes each stored say-once topic info whose date and hour have already passed relative to the current game date and time.
// @fnv 0x00935ae0
void FUN_00935ae0_t::FUN_00935ae0()
{
    ExtraSayTopicInfoOnceADay* pextra9 = 0;
    BSSimpleList<TopicInfoVisitRecord*>* pList;

    if (((bool)(::FUN_00574900((const unsigned char *)this))))
        pextra9 = ((::ExtraSayTopicInfoOnceADay *)(reinterpret_cast<::FUN_0042efe0_cls *>((void *)(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((((DialogueItem*)this)->FUN_005e3fa0()))->FUN_005d43c0()))))->FUN_0042efe0()));
    else
        pextra9 = ((::ExtraSayTopicInfoOnceADay *)(reinterpret_cast<::FUN_0042efe0_cls *>((void *)(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0042efe0()));
    if (pextra9)
    {
        pList = pextra9->pList;
        while (pList && ((::TopicInfoVisitRecord *)(((::Vec3 *)(void *)(pList)))))
        {
            int icurrentyear;
            float fhour2;
            TopicInfoVisitRecord* psayonceinfo6 = ((::TopicInfoVisitRecord *)(((::Vec3 *)(void *)(pList))));
            int icurrentmonth3;
            int iday_;
            float fcurrenthourB;
            int imonth2;
            int iyear7;
            bool aBremove = false;
            int icurrentday5;
            fhour2 = psayonceinfo6->fHour + ((::UTSO_SettingValue *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UTSO_SettingT< ::GameSettingCollection> *>(&::originalRuntimeFloatSetting1061))))))->f;
            iday_ = psayonceinfo6->iDate & 0x1ff;
            imonth2 = (psayonceinfo6->iDate & 0x1e00) >> 9;
            iyear7 = (psayonceinfo6->iDate & 0x7ffe000) >> 13;
            icurrentmonth3 = DAT_011a39c4;
            icurrentday5 = DAT_011e0360;
            icurrentyear = DAT_011e035c;
            fcurrenthourB = DAT_011e0358;
            if (fhour2 > 23.0 || icurrentday5 > iday_ || icurrentmonth3 > imonth2 || icurrentyear > iyear7)
            {
                if (fhour2 > 23.0)
                {
                    fhour2 = fhour2 - 23.0;
                    if (fcurrenthourB >= fhour2 &&
                        (icurrentday5 > iday_ || icurrentmonth3 > imonth2 || icurrentyear > iyear7))
                        aBremove = true;
                }
                else
                {
                    if (fcurrenthourB <= fhour2)
                        aBremove = true;
                }
            }
            else
            {
                if (fcurrenthourB >= fhour2)
                    aBremove = true;
            }
            if (aBremove)
            {
                reinterpret_cast<::ItemChangeListNode *>((pList))->FUN_00905330((::InventoryStackRecord *const &)(psayonceinfo6));
                delete psayonceinfo6;
                pList = pextra9->pList;
            }
            else
            {
                pList = ((::BSSimpleList< ::TopicInfoVisitRecord *> *)(reinterpret_cast<::SimpleListNodeView *>((pList))->m_pkNext));
            }
        }
    }
}

class ActorCause
{
  public:
    void IncRefCount();
    unsigned int DecRefCount();
};

struct TESCombatStyle;

struct FUN_009b3490_shell
{
    ~FUN_009b3490_shell();
};

struct BSSimpleList_standin
{
    bool _ref_008256d0();
    void _ref_0063f7b0();
};

struct FUN_008d8b80Class
{
    TESObjectREFR* FUN_008d8b80();
};

namespace p07 {
struct DelStandIn
{
    ~DelStandIn();
};
}

class TESCreature
{
};

struct FUN_009c4da0_shell
{
    void ClearCombatStyleAndActorCause();
};

// @fnv 0x009c4da0
void FUN_009c4da0_shell::ClearCombatStyleAndActorCause()
{
    while (!((BSSimpleList_standin*)((char*)this + 0x88))->_ref_008256d0())
    {
        delete *((::FUN_009b3490_shell **)(((::Vec3 *)(void *)(((BSSimpleList_standin*)((char*)this + 0x88))))));
        ((BSSimpleList_standin*)((char*)this + 0x88))->_ref_0063f7b0();
    }

    reinterpret_cast<::Holder0042f780 *>((((NiPointer<ActorCause>*)((char*)this + 0x120))))->FUN_0042f780((::AC_0042f730 *)(::ActorCause *)(0));

    if (((FUN_008d8b80Class*)this)->FUN_008d8b80())
    {
        delete (p07::DelStandIn*)((FUN_008d8b80Class*)this)->FUN_008d8b80();
        reinterpret_cast<::FUN_008126e0_shell *>((((TESCreature*)this)))->SetWhich((int)(0));
    }
}

struct FUN_0055e730_shell
{
};

struct FUN_00931ff0_shell : public MobileObject
{
    unsigned short FUN_00931ff0(unsigned int aiFlags);
};

// @fnv 0x00931ff0
unsigned short FUN_00931ff0_shell::FUN_00931ff0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += 1;
    isize += reinterpret_cast<::SaveReference *>((((FUN_0055e730_shell*)this)))->FUN_0055e730(aiFlags);
    if (m_pBaseProcess)
        isize += m_pBaseProcess->GetSaveSize(aiFlags, this);
    return isize;
}

namespace fnv_00932880 {
struct BGSSaveFormBuffer;

class TESResponse
{
  public:
};

class SaveFormIDHelper
{
  public:
};

struct BGSSaveFormBuffer : public SaveFormIDHelper
{
  public:
};

struct V0
{
    virtual void m0()
    {}
    virtual void m1()
    {}
    virtual void m2()
    {}
    virtual void m3()
    {}
    virtual void m4()
    {}
    virtual void m5()
    {}
    virtual void m6()
    {}
    virtual void m7()
    {}
    virtual void m8()
    {}
    virtual void m9()
    {}
};

struct V1 : public V0
{
    virtual void m10()
    {}
    virtual void m11()
    {}
    virtual void m12()
    {}
    virtual void m13()
    {}
    virtual void m14()
    {}
    virtual void m15()
    {}
    virtual void m16()
    {}
    virtual void m17()
    {}
    virtual void m18()
    {}
    virtual void m19()
    {}
};

struct V2 : public V1
{
    virtual void m20()
    {}
    virtual void m21()
    {}
    virtual void m22()
    {}
    virtual void m23()
    {}
    virtual void m24()
    {}
    virtual void m25()
    {}
    virtual void m26()
    {}
    virtual void m27()
    {}
    virtual void m28()
    {}
    virtual void m29()
    {}
};

struct V3 : public V2
{
    virtual void m30()
    {}
    virtual void m31()
    {}
    virtual void m32()
    {}
    virtual void m33()
    {}
    virtual void m34()
    {}
    virtual void m35()
    {}
    virtual void m36()
    {}
    virtual void m37()
    {}
    virtual void m38()
    {}
    virtual void m39()
    {}
};

struct V4 : public V3
{
    virtual void m40()
    {}
    virtual void m41()
    {}
    virtual void m42()
    {}
    virtual void m43()
    {}
    virtual void m44()
    {}
    virtual void m45()
    {}
    virtual void m46()
    {}
    virtual void m47()
    {}
    virtual void m48()
    {}
    virtual void m49()
    {}
};

struct V5 : public V4
{
    virtual void m50()
    {}
    virtual void m51()
    {}
    virtual void m52()
    {}
    virtual void m53()
    {}
    virtual void m54()
    {}
    virtual void m55()
    {}
    virtual void m56()
    {}
    virtual void m57()
    {}
    virtual void m58()
    {}
    virtual void m59()
    {}
};

struct V6 : public V5
{
    virtual void m60()
    {}
    virtual void m61()
    {}
    virtual void m62()
    {}
    virtual void m63()
    {}
    virtual void m64()
    {}
    virtual void m65()
    {}
    virtual void m66()
    {}
    virtual void m67()
    {}
    virtual void m68()
    {}
    virtual void m69()
    {}
};

struct V7 : public V6
{
    virtual void m70()
    {}
    virtual void m71()
    {}
    virtual void m72()
    {}
    virtual void m73()
    {}
    virtual void m74()
    {}
    virtual void m75()
    {}
    virtual void m76()
    {}
    virtual void m77()
    {}
    virtual void m78()
    {}
    virtual void m79()
    {}
};

struct V8 : public V7
{
    virtual void m80()
    {}
    virtual void m81()
    {}
    virtual void m82()
    {}
    virtual void m83()
    {}
    virtual void m84()
    {}
    virtual void m85()
    {}
    virtual void m86()
    {}
    virtual void m87()
    {}
    virtual void m88()
    {}
    virtual void m89()
    {}
};

struct V9 : public V8
{
    virtual void m90()
    {}
    virtual void m91()
    {}
    virtual void m92()
    {}
    virtual void m93()
    {}
    virtual void m94()
    {}
    virtual void m95()
    {}
    virtual void m96()
    {}
    virtual void m97()
    {}
    virtual void m98()
    {}
    virtual void m99()
    {}
};

struct V10 : public V9
{
    virtual void m100()
    {}
    virtual void m101()
    {}
    virtual void m102()
    {}
    virtual void m103()
    {}
    virtual void m104()
    {}
    virtual void m105()
    {}
    virtual void m106()
    {}
    virtual void m107()
    {}
    virtual void m108()
    {}
    virtual void m109()
    {}
};

struct V11 : public V10
{
    virtual void m110()
    {}
    virtual void m111()
    {}
    virtual void m112()
    {}
    virtual void m113()
    {}
    virtual void m114()
    {}
    virtual void m115()
    {}
    virtual void m116()
    {}
    virtual void m117()
    {}
    virtual void m118()
    {}
    virtual void m119()
    {}
};

struct V12 : public V11
{
    virtual void m120()
    {}
    virtual void m121()
    {}
    virtual void m122()
    {}
    virtual void m123()
    {}
    virtual void m124()
    {}
    virtual void m125()
    {}
    virtual void m126()
    {}
    virtual void m127()
    {}
    virtual void m128()
    {}
    virtual void m129()
    {}
};

struct V13 : public V12
{
    virtual void m130()
    {}
    virtual void m131()
    {}
    virtual void m132()
    {}
    virtual void m133()
    {}
    virtual void m134()
    {}
    virtual void m135()
    {}
    virtual void m136()
    {}
    virtual void m137()
    {}
    virtual void m138()
    {}
    virtual void m139()
    {}
};

struct V14 : public V13
{
    virtual void m140()
    {}
    virtual void m141()
    {}
    virtual void m142()
    {}
    virtual void m143()
    {}
    virtual void m144()
    {}
    virtual void m145()
    {}
    virtual void m146()
    {}
    virtual void m147()
    {}
    virtual void m148()
    {}
    virtual void m149()
    {}
};

struct V15 : public V14
{
    virtual void m150()
    {}
    virtual void m151()
    {}
    virtual void m152()
    {}
    virtual void m153()
    {}
    virtual void m154()
    {}
    virtual void m155()
    {}
    virtual void m156()
    {}
    virtual void m157()
    {}
    virtual void m158()
    {}
    virtual void m159()
    {}
};

struct V16 : public V15
{
    virtual void m160()
    {}
    virtual void m161()
    {}
    virtual void m162()
    {}
    virtual void m163()
    {}
    virtual void m164()
    {}
    virtual void m165()
    {}
    virtual void m166()
    {}
    virtual void m167()
    {}
    virtual void m168()
    {}
    virtual void m169()
    {}
};

struct V17 : public V16
{
    virtual void m170()
    {}
    virtual void m171()
    {}
    virtual void m172()
    {}
    virtual void m173()
    {}
    virtual void m174()
    {}
    virtual void m175()
    {}
    virtual void m176()
    {}
    virtual void m177()
    {}
    virtual void m178()
    {}
    virtual void m179()
    {}
};

struct V18 : public V17
{
    virtual void m180()
    {}
    virtual void m181()
    {}
    virtual void m182()
    {}
    virtual void m183()
    {}
    virtual void m184()
    {}
    virtual void m185()
    {}
    virtual void m186()
    {}
    virtual void m187()
    {}
    virtual void m188()
    {}
    virtual void m189()
    {}
};

struct V19 : public V18
{
    virtual void m190()
    {}
    virtual void m191()
    {}
    virtual void m192()
    {}
    virtual void m193()
    {}
    virtual void m194()
    {}
    virtual void m195()
    {}
    virtual void m196()
    {}
    virtual void m197()
    {}
    virtual void m198()
    {}
    virtual void m199()
    {}
};

struct V20 : public V19
{
    virtual void m200()
    {}
    virtual void m201()
    {}
    virtual void m202()
    {}
    virtual void m203()
    {}
    virtual void m204()
    {}
    virtual void m205()
    {}
    virtual void m206()
    {}
    virtual void m207()
    {}
    virtual void m208()
    {}
    virtual void m209()
    {}
};

struct V21 : public V20
{
    virtual void m210()
    {}
    virtual void m211()
    {}
    virtual void m212()
    {}
    virtual void m213()
    {}
    virtual void m214()
    {}
    virtual void m215()
    {}
    virtual void m216()
    {}
    virtual void m217()
    {}
    virtual void m218()
    {}
    virtual void m219()
    {}
};

struct V22 : public V21
{
    virtual void m220()
    {}
    virtual void m221()
    {}
    virtual void m222()
    {}
    virtual void m223()
    {}
    virtual void m224()
    {}
    virtual void m225()
    {}
    virtual void m226()
    {}
    virtual void m227()
    {}
    virtual void m228()
    {}
    virtual void m229()
    {}
};

struct V23 : public V22
{
    virtual void m230()
    {}
    virtual void m231()
    {}
    virtual void m232()
    {}
    virtual void m233()
    {}
    virtual void m234()
    {}
    virtual void m235()
    {}
    virtual void m236()
    {}
    virtual void m237()
    {}
    virtual void m238()
    {}
    virtual void m239()
    {}
};

struct V24 : public V23
{
    virtual void m240()
    {}
    virtual void m241()
    {}
    virtual void m242()
    {}
    virtual void m243()
    {}
    virtual void m244()
    {}
    virtual void m245()
    {}
    virtual void m246()
    {}
    virtual void m247()
    {}
    virtual void m248()
    {}
    virtual void m249()
    {}
};

struct V25 : public V24
{
    virtual void m250()
    {}
    virtual void m251()
    {}
    virtual void m252()
    {}
    virtual void m253()
    {}
    virtual void m254()
    {}
    virtual void m255()
    {}
    virtual void m256()
    {}
    virtual void m257()
    {}
    virtual void m258()
    {}
    virtual void m259()
    {}
};

struct V26 : public V25
{
    virtual void m260()
    {}
    virtual void m261()
    {}
    virtual void m262()
    {}
    virtual void m263()
    {}
    virtual void m264()
    {}
    virtual void m265()
    {}
    virtual void m266()
    {}
    virtual void m267()
    {}
    virtual void m268()
    {}
    virtual void m269()
    {}
};

struct V27 : public V26
{
    virtual void m270()
    {}
    virtual void m271()
    {}
    virtual void m272()
    {}
    virtual void m273()
    {}
    virtual void m274()
    {}
    virtual void m275()
    {}
    virtual void m276()
    {}
    virtual void m277()
    {}
    virtual void m278()
    {}
    virtual void m279()
    {}
};

struct V28 : public V27
{
    virtual void m280()
    {}
    virtual void m281()
    {}
    virtual void m282()
    {}
    virtual void m283()
    {}
    virtual void m284()
    {}
    virtual void m285()
    {}
    virtual void m286()
    {}
    virtual void m287()
    {}
    virtual void m288()
    {}
    virtual void m289()
    {}
};

struct V29 : public V28
{
    virtual void m290()
    {}
    virtual void m291()
    {}
    virtual void m292()
    {}
    virtual void m293()
    {}
    virtual void m294()
    {}
    virtual void m295()
    {}
    virtual void m296()
    {}
    virtual void m297()
    {}
    virtual void m298()
    {}
    virtual void m299()
    {}
};

struct V30 : public V29
{
    virtual void m300()
    {}
    virtual void m301()
    {}
    virtual void m302()
    {}
    virtual void m303()
    {}
    virtual void m304()
    {}
    virtual void m305()
    {}
    virtual void m306()
    {}
    virtual void m307()
    {}
    virtual void m308()
    {}
    virtual void m309()
    {}
};

struct V31 : public V30
{
    virtual void m310()
    {}
    virtual void m311()
    {}
    virtual void m312()
    {}
    virtual void m313()
    {}
    virtual void m314()
    {}
    virtual void m315()
    {}
    virtual void m316()
    {}
    virtual void m317()
    {}
    virtual void m318()
    {}
    virtual void m319()
    {}
};

struct V32 : public V31
{
    virtual void m320()
    {}
    virtual void m321()
    {}
    virtual void m322()
    {}
    virtual void m323()
    {}
    virtual void m324()
    {}
    virtual void m325()
    {}
    virtual void m326()
    {}
    virtual void m327()
    {}
    virtual void m328()
    {}
    virtual void m329()
    {}
};

struct V330 : public V32
{
    virtual void m330()
    {}
    virtual void m331()
    {}
    virtual void m332()
    {}
    virtual void m333()
    {}
    virtual void m334()
    {}
    virtual void m335()
    {}
    virtual void m336()
    {}
    virtual void m337()
    {}
    virtual void m338()
    {}
    virtual void SaveGame(BGSSaveFormBuffer*);
};

struct FUN_00932880_shell
{
    unsigned char pad00[0x68];
    TESResponse* m_pBaseProcess;
    void* m_pLinkedReference;
    void* m_pMobileObject;
    int field74;
    int field78;
    unsigned char field7c;
    unsigned char field7d;
    unsigned char field7e;
    unsigned char field7f;
    unsigned char field80;
    unsigned char field81;
    unsigned char pad82;
    unsigned char field83;
    unsigned char field84;
    unsigned char field85;
    unsigned char field86;

    void FUN_00932880(BGSSaveFormBuffer*);
};

// @fnv 0x00932880
void FUN_00932880_shell::FUN_00932880(BGSSaveFormBuffer* pSaveGameBuffer)
{
    char cprocessLevel = -1;

    if (m_pBaseProcess)
        cprocessLevel = ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60()));

    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&cprocessLevel, 1, 0);
    reinterpret_cast<::Refr_s *>((this))->FUN_00562230((::BGSSaveFormBuffer *)(pSaveGameBuffer));
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field84, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field85, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field7c, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field7f, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field80, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field7d, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field7e, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field86, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field74, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field78, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field81, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pSaveGameBuffer))->FUN_00865e50(&field83, 1, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pLinkedReference), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pMobileObject), 0);

    if (m_pBaseProcess)
        reinterpret_cast<V330*>(m_pBaseProcess)->SaveGame(pSaveGameBuffer);
}
}  // namespace fnv_00932880

class B5725B0Form
{
  public:
    int GetFormType();

    bool FUN_005725b0();
};

// Returns true when GetFormType() is one of 0x3d, 0x3e, 0x3f, 0x40 or 0x69, otherwise false.
// @fnv 0x005725b0
bool B5725B0Form::FUN_005725b0()
{
    switch (GetFormType())
    {
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x69:
        return true;
    }
    return false;
}

struct Gen_vec3_local
{
    float x;
    float y;
    float z;
};

struct Gen_probe_target
{
};

class FUN_00576470_cls
{
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
    virtual Gen_vec3_local* v1f4();
    Gen_probe_target* FUN_008d6f30();
    bool ProbeAndApplyHeight();
};

// Gets a probe target, tests the object's position against it, and if it hits, stores the returned height in z and applies the position.
// @fnv 0x00576470
bool FUN_00576470_cls::ProbeAndApplyHeight()
{
    bool result2 = false;
    Gen_probe_target* pProbeTarget = this->FUN_008d6f30();
    if (pProbeTarget != 0)
    {
        Gen_vec3_local v2 = *this->v1f4();
        float f;
        if (reinterpret_cast<::FakeCell *>((pProbeTarget))->FUN_005547c0((*(const ::NiPoint3 *)(&v2)), (*(float *)(&f))))
        {
            v2.z = f;
            reinterpret_cast<::Reference *>((this))->FUN_00575830((::Position *)(::Gen_vec3_local *)(&v2));
            result2 = true;
        }
    }
    return result2;
}

class E6C0Node
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
    virtual void SetVisible(int iValue);

    void* GetData();
};


class E6C0Owner
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
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void Refresh();

    E6C0Node* GetNode();
    void SetShown(bool bShow);
};

// Gets the node; if showing, makes it visible, sets its data to 1 and refreshes, otherwise calls FUN_00c6ffc0 on it and hides.
// @fnv 0x0081e6c0
void E6C0Owner::SetShown(bool bShow)
{
    E6C0Node* pkNode = ((::E6C0Node *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (pkNode)
    {
        if (bShow)
        {
            pkNode->SetVisible(0);
            CopyBlock48(((void *)(reinterpret_cast<::FUN_00810660_Class *>((pkNode))->FUN_00810660())), (const void*)1);
            Refresh();
        }
        else
        {
            reinterpret_cast<::FUN_00c6ffc0_Class *>((pkNode))->FUN_00c6ffc0();
            reinterpret_cast<::MagicProjectile *>(this)->FUN_0081e730();
        }
    }
}

struct SpinLockStub
{
};

struct ProcessStub
{
    virtual ~ProcessStub();
};

struct RefStub;
struct ProcessListsStub
{
};

struct DataHandlerStub
{
};

struct FormStub
{
    virtual ~FormStub();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct ChildCellStub
{
    virtual void* GetPersistentCell();
};

struct RefStub : FormStub, ChildCellStub
{
    virtual ~RefStub();
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    void* m_pOwningCell;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
};

struct FUN_0092ec40 : RefStub
{
    ProcessStub* m_pBaseProcess;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    bool m_bFirstFlag;
    bool m_bSecondBooleanValue;
    bool m_bThirdFlag;
    bool m_bFourthBooleanValue;
    bool m_bFifthFlag;
    bool m_bSixthFlag;
    bool m_bSeventhFlag;
    bool m_bEighthFlag;
    char m_cCharacterValue;
    bool m_bNinthFlag;
    bool m_bTenthFlag;
    bool m_bThirdActorFlag;
    virtual ~FUN_0092ec40();
};
// Calls FUN_0092ec40, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0092ec10
void* FUN_0092ec10_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0092ec40 *>(this)->FUN_0092ec40::~FUN_0092ec40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0092ec40
FUN_0092ec40::~FUN_0092ec40()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::SpinLockStub *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
    if (!reinterpret_cast<::FUN_004077c0_shell *>(this)->FUN_004077c0())
    {
        reinterpret_cast<::ProcessLists *>(&((*reinterpret_cast<::ProcessListsStub *>(&::g_011e0e80))))->RemoveMobileObjectFromList((::MobileObject *)(::RefStub *)(this));
        if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler))))->FUN_004226e0())
        {
            reinterpret_cast<::C6760Ref *>(this)->FUN_00576760();
        }
        if (m_pBaseProcess)
        {
            reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::ProcessListsStub *>(&::g_011e0e80))))->FUN_0096d470((::MobileObject *)(::RefStub *)(this), ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60())));
        }
    }
    delete m_pBaseProcess;
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::SpinLockStub *>(&::DAT_011f11a0))))->FUN_0040fba0();
    if (m_bSixthFlag)
    {
        m_pOwningCell = 0;
    }
}


struct FUN_009304d0_shell
{
    float unk00;
    NiPoint3 unk04;
    NiPoint3 unk10;
    unsigned int unk1c;
    float unk20;
    bool unk24;

    void* FUN_009304d0();
};

// Initialises the object's fields: zeroes unk00 and unk20, copies DAT_011f426c into unk04 and unk10, sets unk24 to true, and returns this.
// @fnv 0x009304d0
void* FUN_009304d0_shell::FUN_009304d0()
{
    unk00 = 0.0f;
    unk04 = ::NiPoint3::ZERO;
    unk10 = ::NiPoint3::ZERO;
    unk20 = 0.0f;
    unk24 = true;
    return this;
}

struct FUN_00931cc0_obj
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
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual NiPoint3* v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4(float f);
    void FUN_00931cc0(FUN_00931cc0_obj* other);
};

// Computes the distance between this object's and other's v1F4 points and passes it to v2C4.
// @fnv 0x00931cc0
void FUN_00931cc0_obj::FUN_00931cc0(FUN_00931cc0_obj* other)
{
    NiPoint3 offset = *other->v1F4() - *v1F4();
    float dist = GetDirectionAngle(&offset);
    v2C4(dist);
}

struct CastType;
struct CastObject;
struct BaseCast;
struct World;
struct NodeList;
struct FieldData
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
    float angle;
};
struct CastObject
{
};
struct PointerView
{
};
struct NodeList
{
};
struct World
{
};
struct SubObject
{
};
struct ParentView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual SubObject* f39(NiFixedString*);
};
struct AngleView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual ParentView* f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual float f175(int);

    float GetAdjustedAngle();
};
// @fnv 0x00936da0
float AngleView::GetAdjustedAngle()
{
    float angle = f175(0);
    if (f64() && reinterpret_cast<::FUN_0087eeb0_shell *>(this)->FUN_0087eeb0())
    {
        ParentView* parent = f116();
        if (parent)
        {
            SubObject* sub = parent->f39(FUN_0087e9a0());
            if (sub)
            {
                CastObject* base;
                BaseCast* collision = ((::BaseCast *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((sub))->FUN_006838b0()));
                base = ((::CastObject *)(::FUN_00653270((const ::NiRTTI *)(const ::CastType *)(&(*reinterpret_cast<::CastType *>(&::g_01267e64))), (::NiObject *)(collision))));
                if (base)
                {
                    World* list = ((::World *)(::fnv_006fa820::FUN_006fa820((const char *)(base))));
                    NodeList* world = ((::NodeList *)(reinterpret_cast<::NonActorMagicTarget *>((list))->GetActiveEffectList()));
                    while (world && ((::BaseCast *)(::FUN_00559450((int *)(((::PointerView *)(((::Vec3 *)(void *)(world)))))))))
                    {
                        CastObject* body = ((::CastObject *)(::FUN_00653270((const ::NiRTTI *)(const ::CastType *)(&(*reinterpret_cast<::CastType *>(&::g_012683ec))), (::NiObject *)(::BaseCast *)(((::BaseCast *)(::FUN_00559450((int *)(((::PointerView *)(((::Vec3 *)(void *)(world))))))))))));
                        world = ((::NodeList *)(reinterpret_cast<::Callees *>((world))->FUN_00726070()));
                        if (body)
                        {
                            angle -= ((::FieldData *)(reinterpret_cast<::FUN_00620b80_shell *>((body))->GetReferenceFlags()))->angle;
                            angle = WrapAngle(angle);
                            break;
                        }
                    }
                }
            }
        }
    }
    return angle;
}

struct VoiceString
{
};
struct VoiceResponse
{
};
struct VoiceInfo
{
};
struct VoiceItem
{
    void FUN_0083c7b0();
};
struct VoiceTopic
{
};
struct VoiceForm
{
    int FUN_00401170();
};
struct VoiceNode
{
    const NiPoint3& FUN_0045bb80();
};
struct VoiceFile
{
    ~VoiceFile();
};
struct VoiceAudio
{
    SoundPlaybackHandle FUN_00ad7480(const char*, unsigned int, void*);
};
void __cdecl FUN_00705210(const char*, SoundPlaybackHandle, NiPoint3, void*, bool);
struct VoiceSetting
{
    bool* FUN_00408d60();
};
struct VoiceSoundMethods
{
};
struct VoiceHost
{
    char pad04[0x8];
    unsigned int iFormID;

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
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual VoiceNode* GetNode();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const NiPoint3& GetPosition();
    SoundPlaybackHandle PlayVoiceTopic(VoiceTopic*, void*, bool, bool, bool, void*, bool);
};
// @fnv 0x00578a80
SoundPlaybackHandle VoiceHost::PlayVoiceTopic(VoiceTopic* topic, void* listener, bool force, bool bUseAlternateFlags,
                                        bool bComputeDuration, void* unused, bool finalFlag)
{
    SoundPlaybackHandle pItem;
    float extra = 0.0f;
    VoiceItem* time = ((::VoiceItem *)(reinterpret_cast<::FUN_0061b320_shell *>((topic))->FUN_0061b320((::TESObjectREFR *)(void *)(this), (::TESObjectREFR *)(listener), (::TESTopic *)(void *)(0), 0, false)));
    float flags = 0.0f;
    reinterpret_cast<::fnv_0057ad20::FUN_0057ad20_shell *>(this)->FUN_0057ad20((::fnv_0057ad20::TESTopic *)(topic));
    unsigned int kSound = 0;
    VoiceForm* pForm;
    if (((::VoiceForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) && ((::VoiceForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->FUN_00401170() == 0x16)
        pForm = ((::VoiceForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
    if (time)
    {
        VoiceInfo* pInfo = ((::VoiceInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((time))->FUN_0084e3a0()));
        reinterpret_cast<::fnv_0057ace0::FUN_0057ace0_shell *>(this)->FUN_0057ace0((::fnv_0057ace0::TESTopicInfo *)(pInfo));
        if (pInfo)
        {
            reinterpret_cast<::FUN_0061f170_cls *>((pInfo))->FUN_0061f170((void *)(0), (::ArgObj *)(void *)(this));
            reinterpret_cast<::TESTopicInfo *>((pInfo))->AddTopicList();
        }
        time->FUN_0083c7b0();
        VoiceResponse* pResponse = ((::VoiceResponse *)(reinterpret_cast<::DialogueItem *>((time))->GetActiveResponse()));
        if (pResponse)
        {
            if (((const char *)(::FUN_00559450((int *)(((::VoiceString *)(::FUN_00460140((intptr_t)(pResponse)))))))))
            {
                char path[512];
                ::TaskQueueInterface::CopyStringToBuffer(path, 512, ((const char *)(::FUN_00559450((int *)(((::VoiceString *)(::FUN_00460140((intptr_t)(pResponse)))))))));
                if (bComputeDuration)
                {
                    VoiceFile* file = 0;
                    BSStringT<char> name;
                    reinterpret_cast<::TextString *>(&(name))->FUN_004037f0(path, 512);
                    if (BuildLipPath(name))
                    {
                        file = ((::VoiceFile *)(::LoadBGSTerrainManager((const ::NiPointer< ::NiNode> &)(name))));
                        if (file)
                        {
                            flags = ((unsigned int)(::FUN_00559450((int *)(file)))) / 30.0;
                            delete file;
                        }
                    }
                }
                if (force || !GetNode())
                {
                    if (bUseAlternateFlags)
                        pItem = ((::VoiceAudio *)(::FUN_00453a70()))->FUN_00ad7480(path, kSound | 0x101, 0);
                    else
                        pItem = ((::VoiceAudio *)(::FUN_00453a70()))->FUN_00ad7480(path, kSound | 0x105, 0);
                }
                else
                {
                    if (bUseAlternateFlags)
                        pItem = ((::VoiceAudio *)(::FUN_00453a70()))->FUN_00ad7480(path, kSound | 0x102, 0);
                    else
                        pItem = ((::VoiceAudio *)(::FUN_00453a70()))->FUN_00ad7480(path, kSound | 0x106, 0);
                }
                if (!force && GetNode())
                {
                    NiPoint3 position = GetNode()->FUN_0045bb80();
                    reinterpret_cast<::FUN_00ad8b60_h *>(&(pItem))->FUN_00ad8b60(position.x, position.y, position.z);
                    reinterpret_cast<::FUN_00ad8be0_shell *>((((VoiceSoundMethods*)&pItem)))->FUN_00ad8be0(FUN_005790b0(), FUN_005790d0());
                    reinterpret_cast<::FUN_00ad8f20_shell *>(&(pItem))->FUN_00ad8f20((NiAVObject*)GetNode());
                }
                reinterpret_cast<::FUN_00ad8830_shell *>(&(pItem))->FUN_00ad8830(false);
                reinterpret_cast<::SoundPlaybackHandle *>((((VoiceSoundMethods*)&pItem)))->SetCompletionCallback((void (*)(void *, bool))(((void (&)(void *, unsigned int))::fnv_005790f0::FUN_005790f0)), ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())));
            }
            else if (pInfo)
                ::fnv_005790f0::FUN_005790f0((this)->iFormID);
            if (*(*reinterpret_cast<::VoiceSetting *>(&::g_011d8928)).FUN_00408d60() || (IsActor() && ::FUN_008c1bc0((intptr_t)this)))
            {
                if (flags <= 0.0)
                    flags = 2.0f;
                FUN_00705210(((const char *)(::FUN_00559450((int *)(((::VoiceString *)(((::Vec3 *)(void *)(pResponse)))))))), pItem, GetPosition(), listener, finalFlag);
            }
        }
    }
    if (flags <= 0.0)
        flags = 2.0f;
    return pItem;
}

class TESObjectCELL;

struct ProcessStandIn
{
};

struct LoaderStandIn
{
    bool IsQueued(void* ref);
};

struct TESStandIn
{
};

struct RefStandIn;

struct LinkStandIn
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
    RefStandIn* unk28;
};

struct RefStandIn
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual ~RefStandIn();
    TESObjectCELL* GetParentCell();
};


struct ActorStandIn : RefStandIn
{
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
    virtual int IsPersistentStandIn();
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
    virtual void MoveToHighStandIn();
    virtual void v244();
    virtual void v248();
    virtual void MoveToLowStandIn();

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
    ProcessStandIn* unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    LinkStandIn* unk88;
    int unk8C;

    bool UpdateProcessLevel();
};

// Compares the actor's current process level with a desired level derived from its cell and moves it high/low, or deletes it when the level is not applicable.
// @fnv 0x008cdbf0
bool ActorStandIn::UpdateProcessLevel()
{
    bool bResult = true;
    bool bLowOnly5 = false;
    intptr_t iCurLevel4 = ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((unk68))->FUN_0045cd60()));
    int iWantLevel = 3;
    TESObjectCELL* pCell4 = GetParentCell();
    if (unk8C == 2 && unk88 && unk88->unk28)
    {
        if (unk88->unk28 == (RefStandIn*)::_g_thePlayer)
        {
            if (iCurLevel4)
                MoveToHighStandIn();
            return true;
        }
        else
        {
            pCell4 = unk88->unk28->GetParentCell();
        }
    }
    if (IsPersistentStandIn() || (*reinterpret_cast<::LoaderStandIn * *>(&::g_modelLoader))->IsQueued(this))
    {
        if (reinterpret_cast<::TESCallHelper *>((((TESStandIn*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->IsCellBuffered(pCell4, true))
            iWantLevel = 0;
        else if (reinterpret_cast<::TESCallHelper *>((((TESStandIn*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->IsCellBuffered(pCell4, false))
            iWantLevel = 1;
    }
    if (unk8C == 0)
        bLowOnly5 = true;
    if (iCurLevel4 == iWantLevel)
        return true;
    switch (iWantLevel)
    {
    case 0:
        MoveToHighStandIn();
        break;
    case 1:
        if (!bLowOnly5)
        {
            MoveToLowStandIn();
            break;
        }
    default:
        delete this;
        bResult = false;
    }
    return bResult;
}

struct ProcessShim
{
    virtual ~ProcessShim();
    virtual void v1(BaseProcess* previous);
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
    int unknown_004;
    int unknown_008;
    int unknown_00c;
    int unknown_010;
    int unknown_014;
    int unknown_018;
    int unknown_01c;
    int unknown_020;
    int unknown_024;
    int unknown_028;
    int unknown_02c;
    int unknown_030;
    int unknown_034;
    int unknown_038;
    int unknown_03c;
    int unknown_040;
    int unknown_044;
    int unknown_048;
    int unknown_04c;
    int unknown_050;
    int unknown_054;
    int unknown_058;
    int unknown_05c;
    int unknown_060;
    int unknown_064;
    int unknown_068;
    int unknown_06c;
    int unknown_070;
    int unknown_074;
    int unknown_078;
    int unknown_07c;
    int unknown_080;
    int unknown_084;
    int unknown_088;
    int unknown_08c;
    int unknown_090;
    int unknown_094;
    int unknown_098;
    int unknown_09c;
    int unknown_0a0;
    int unknown_0a4;
    int unknown_0a8;
    int unknown_0ac;
    int unknown_0b0;
    int unknown_0b4;
    int unknown_0b8;
    int unknown_0bc;
    int unknown_0c0;
    int unknown_0c4;
    int unknown_0c8;
    int unknown_0cc;
    int unknown_0d0;
    int unknown_0d4;
    int unknown_0d8;
    int unknown_0dc;
    int unknown_0e0;
    int unknown_0e4;
    int unknown_0e8;
    int unknown_0ec;
    int unknown_0f0;
    int unknown_0f4;
    int unknown_0f8;
    int unknown_0fc;
    int unknown_100;
    int unknown_104;
    int unknown_108;
    int unknown_10c;
    int unknown_110;
    int unknown_114;
    int unknown_118;
    int unknown_11c;
    int unknown_120;
    int unknown_124;
    int unknown_128;
    int unknown_12c;
    int unknown_130;
    int unknown_134;
    int unknown_138;
    int unknown_13c;
    int unknown_140;
    int unknown_144;
    int unknown_148;
    int unknown_14c;
    int unknown_150;
    int unknown_154;
    int unknown_158;
    int unknown_15c;
    int unknown_160;
    int unknown_164;
    int unknown_168;
    int unknown_16c;
    int unknown_170;
    int unknown_174;
    int unknown_178;
    int unknown_17c;
    int unknown_180;
    int unknown_184;
    int unknown_188;
    int unknown_18c;
    int unknown_190;
    int unknown_194;
    int unknown_198;
    int unknown_19c;
    int unknown_1a0;
    int unknown_1a4;
    int unknown_1a8;
    int unknown_1ac;
    int unknown_1b0;
    int unknown_1b4;
    int unknown_1b8;
    int unknown_1bc;
    int unknown_1c0;
    int unknown_1c4;
    int unknown_1c8;
    int unknown_1cc;
    int unknown_1d0;
    int unknown_1d4;
    int unknown_1d8;
    int unknown_1dc;
    int unknown_1e0;
    int unknown_1e4;
    int unknown_1e8;
    int unknown_1ec;
    int unknown_1f0;
    int unknown_1f4;
    int unknown_1f8;
    int unknown_1fc;
    int unknown_200;
    int unknown_204;
    int unknown_208;
    int unknown_20c;
    int unknown_210;
    int unknown_214;
    int unknown_218;
    int unknown_21c;
    int unknown_220;
    int unknown_224;
    int unknown_228;
    int unknown_22c;
    int unknown_230;
    int unknown_234;
    int unknown_238;
    int unknown_23c;
    int unknown_240;
    int unknown_244;
    int unknown_248;
    int unknown_24c;
    int unknown_250;
    int unknown_254;
    int unknown_258;
};
struct FUN_00913fe0 : ProcessShim
{
    FUN_00913fe0();
};
struct ProcessListsExtra
{
};
struct MobileObjectVT
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
    virtual void v127(int value);
};
struct FUN_008cf8f0_shell : MobileObject
{
    bool SwitchProcess();
};
// @fnv 0x008cf8f0
bool FUN_008cf8f0_shell::SwitchProcess()
{
    if (m_pBaseProcess && ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((ProcessShim*)m_pBaseProcess)))->FUN_0045cd60())) == 1)
        return true;
    intptr_t type = ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((((ProcessShim*)m_pBaseProcess)))->FUN_0045cd60()));
    reinterpret_cast<::ActorDeletionQueue *>((((ProcessListsExtra*)&(*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)))))->FUN_0096d470(this, type);
    FUN_00913fe0* process = new FUN_00913fe0();
    process->v1(m_pBaseProcess);
    delete ((ProcessShim*)m_pBaseProcess);
    m_pBaseProcess = (BaseProcess*)process;
    reinterpret_cast<::Host096d450 *>((((ProcessListsExtra*)&(*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)))))->FUN_0096d450(this, 1, 0, 0, (::MobileObject *)(0));
    ((MobileObjectVT*)this)->v127(0);
    ((ProcessShim*)m_pBaseProcess)->v18();
    return true;
}

struct Obj930A
{
};
struct ActorV_S
{
};
struct FUN_00c6d4b0_Class
{
    void FUN_00c6d4b0(float);
};
// @fnv 0x00930640
intptr_t Holder_00884aa0::UpdateControllerScale()
{
    bhkCharacterController* controller = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((reinterpret_cast<Obj930A*>(this)))->FUN_009306d0()));
    if (controller)
    {
        float scale =
            FUN_00403e20((float*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting847))) * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((reinterpret_cast<ActorV_S*>(this)))->FUN_00567400();
        if (::FUN_009306b0(controller))
        {
            scale = scale * FUN_00403e20((float*)&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting848)));
        }
        reinterpret_cast<FUN_00c6d4b0_Class*>(controller)->FUN_00c6d4b0(scale);
    }
    return (intptr_t)controller;
}

struct WorkerSaveLoad
{
};
struct WorkerSpinLock
{
};
struct WorkerDeleteQueue
{
};

struct WorkerMobile : MobileObject
{
    int FUN_00931850();
    void FUN_00932750(unsigned int);
};
// @fnv 0x00932750
void WorkerMobile::FUN_00932750(unsigned int flags)
{
    if (flags & 0x20)
    {
        reinterpret_cast<::BipedAnim *>(this)->AttachFaceGenNode();
        reinterpret_cast<::TESForm *>(this)->ClearData();
        reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(0);
        reinterpret_cast<::TESForm *>(this)->ClearData();
    }
    reinterpret_cast<::fnv_0055f240::FUN_0055f240_Class *>(this)->FUN_0055f240(flags);
    if (m_pBaseProcess)
        m_pBaseProcess->Revert(flags, this);
    if (reinterpret_cast<::FUN_0055f5b0_Class *>(((*reinterpret_cast<::WorkerSaveLoad * *>(&::g_TESSaveLoadGame))))->FUN_0055f5b0() && reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::WorkerSaveLoad * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && m_pBaseProcess &&
        (reinterpret_cast<::TESForm *>(this)->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>(this)->FUN_00440d80()))
    {
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::WorkerSpinLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
        reinterpret_cast<::ActorDeletionQueue *>((((WorkerDeleteQueue*)&(*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)))))->FUN_0096d470(this, FUN_00931850());
        delete m_pBaseProcess;
        m_pBaseProcess = 0;
        reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::WorkerSpinLock *>(&::DAT_011f11a0))))->FUN_0040fba0();
    }
}

class Conversation
{
  public:
    Character* conversation;
    PlayerCharacter* listener;
    TESTopic* topic;
    Conversation(Character*, PlayerCharacter*, TESTopic*);
};
struct FUN_00670b30
{
    int type;
    TESObjectREFR* reference;
    float radius;
    FUN_00670b30();
    ~FUN_00670b30();
};
struct PackageTargetObj
{
    int type;
    TESObjectREFR* reference;
    int count;
    float radius;
    PackageTargetObj();
    ~PackageTargetObj();
};
struct PackageMethods
{
};
struct DialogueHost : TESObjectREFR
{
    BaseProcess* process;
    virtual void slot_90();
    virtual void slot_91();
    virtual void slot_92();
    virtual void slot_93();
    virtual void slot_94();
    virtual void slot_95();
    virtual void slot_96();
    virtual void slot_97();
    virtual void slot_98();
    virtual void slot_99();
    virtual void slot_9a();
    virtual void slot_9b();
    virtual void slot_9c();
    virtual void slot_9d();
    virtual void slot_9e();
    virtual void slot_9f();
    virtual void slot_a0();
    virtual void slot_a1();
    virtual void slot_a2();
    virtual void slot_a3();
    virtual void slot_a4();
    virtual void slot_a5();
    virtual void slot_a6();
    virtual void slot_a7();
    virtual void slot_a8();
    virtual void slot_a9();
    virtual void slot_aa();
    virtual void slot_ab();
    virtual void slot_ac();
    virtual void slot_ad();
    virtual void slot_ae();
    virtual void slot_af();
    virtual void slot_b0();
    virtual void slot_b1();
    virtual void slot_b2();
    virtual void slot_b3();
    virtual void slot_b4();
    virtual void slot_b5();
    virtual void slot_b6();
    virtual void slot_b7();
    virtual void slot_b8();
    virtual void slot_b9();
    virtual void slot_ba();
    virtual void slot_bb();
    virtual void slot_bc();
    virtual void SetDialoguePackage(FUN_009edd80*, bool, bool);
    virtual void slot_be();
    virtual void slot_bf();
    virtual MobileObject* GetDialogueSpeaker(MobileObject*, int*);
    int FUN_00931850();
    bool FUN_00934fd0(MobileObject* target, int p2, int p3, int p4, int p5, bool refresh, TESTopic* topic, int p8,
                      int p9);
};
struct DialogueLocation : FUN_00670b30
{
};
struct FUN_0067f030
{
    int type;
    TESObjectREFR* reference;
    float radius;
    FUN_0067f030();
};
struct B9B1450ModelLoader
{
    bool FUN_00445750(TESObjectREFR* pkRef);
};

class FUN_009b1450_Mobile : public MobileObject
{
  public:
    bool FUN_009b1450();
};

// @fnv 0x009b1450
bool FUN_009b1450_Mobile::FUN_009b1450()
{
    bool bResult = true;
    int eCurrent = (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60()));
    int eDesired2 = 3;
    TESObjectCELL* pkCell = GetParentCell();
    if ((GetNiNode() || (*reinterpret_cast<::B9B1450ModelLoader * *>(&::g_modelLoader))->FUN_00445750(this)) && reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->IsCellBuffered(pkCell, true))
        eDesired2 = 0;
    if (eCurrent != eDesired2)
    {
        if (eDesired2 == 0)
        {
        }
        else
        {
            delete this;
            bResult = false;
        }
    }
    return bResult;
}

class MiddleHighProcess : public BaseProcess
{
  public:
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
    MiddleHighProcess();
public:
    bool IsActorInCombat();
public:
    void SetFaceAnimationData(::TargetDoorController *);
    ::FurnitureMark *GetFurnitureMarkerData();
    ::NiAVObject *GetSceneRoot();
    void SetCurrentIdle(::TESIdleForm *);
    ::BooleanFloatQuery *RefreshActorRuntimeData();
    void SetAnimationNode(::NiAVObject *);
    ::BSFaceGenNiNode *GetFacialAnimationNode();
    void SetBoundingBox(::BSBound *);
    bool IsAnimationPlaying();
    ::Animation *GetAnimation();
    void AssignEffectShader(::TESEffectShader *);
    void SetSelectedMagicItem(::MagicItem *);
    void SetMagicTarget(::MagicTarget *);
    bool ResetAlertState();
    bool GetProcessState();
    void AddDeferredHideLimb(::TargetDoorController *);
    void SetKnockdownStage(int);
    void AttachFaceGenerationNode(::BSFaceGenNiNode *);
    ::BSFaceGenNiNode *GetFaceGenHeadNode();
    void SetFaceGenHeadNode(::BSFaceGenNiNode *);
    ::NiAVObject *GetAnimationObject();
    float GetLightIntensity();
    void FUN_00929260(unsigned char);
    ::BSBound *GetObjectBounds();
};
struct ProcessLock
{
};
struct QueueReplacement
{
};
struct FUN_009c4920_shell : public MobileObject
{
    bool ReplaceProcessWithMiddleHigh();
};
// @fnv 0x009c4920
bool FUN_009c4920_shell::ReplaceProcessWithMiddleHigh()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::ProcessLock *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
    if (m_pBaseProcess)
    {
        PROCESS_TYPE level = (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60()));
        reinterpret_cast<::ActorDeletionQueue *>((((QueueReplacement*)&(*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)))))->FUN_0096d470(this, (*(int *)&(level)));
    }
    BaseProcess* process = new MiddleHighProcess;
    process->Copy(m_pBaseProcess);
    delete m_pBaseProcess;
    m_pBaseProcess = process;
    reinterpret_cast<::Host096d450 *>((((QueueReplacement*)&(*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)))))->FUN_0096d450(this, 1, false, false, (::MobileObject *)(0));
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::ProcessLock *>(&::DAT_011f11a0))))->FUN_0040fba0();
    return true;
}

struct AnimPoint
{
    float x, y, z;
};
struct Audio277
{
    SoundPlaybackHandle FUN_00ad7480(int, unsigned int, int);
};
struct Owner277
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
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual NiAVObject* v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual AnimPoint* GetPosition();
    SoundPlaybackHandle PlaySoundAtOwner(int aiID, bool abFlag, unsigned int auiFlags);
};

// @fnv 0x00933010
SoundPlaybackHandle Owner277::PlaySoundAtOwner(int aiID, bool abFlag, unsigned int auiFlags)
{
    SoundPlaybackHandle kHandle;
    kHandle = ((::Audio277 *)(::FUN_00453a70()))->FUN_00ad7480(aiID, auiFlags, 0);
    if (v1D0() && (auiFlags & 2))
    {
        AnimPoint kPos = *GetPosition();
        reinterpret_cast<::FUN_00ad8b60_h *>(&(kHandle))->FUN_00ad8b60(kPos.x, kPos.y, kPos.z);
        reinterpret_cast<::FUN_00ad8f20_shell *>(&(kHandle))->FUN_00ad8f20(v1D0());
    }
    reinterpret_cast<::FUN_00ad8830_shell *>(&(kHandle))->FUN_00ad8830(abFlag);
    return kHandle;
}

namespace fnv_009320e0 {
class HighProcess : public BaseProcess
{
  public:
    HighProcess();
    int unk_hp_000;
    int unk_hp_001;
    int unk_hp_002;
    int unk_hp_003;
    int unk_hp_004;
    int unk_hp_005;
    int unk_hp_006;
    int unk_hp_007;
    int unk_hp_008;
    int unk_hp_009;
    int unk_hp_010;
    int unk_hp_011;
    int unk_hp_012;
    int unk_hp_013;
    int unk_hp_014;
    int unk_hp_015;
    int unk_hp_016;
    int unk_hp_017;
    int unk_hp_018;
    int unk_hp_019;
    int unk_hp_020;
    int unk_hp_021;
    int unk_hp_022;
    int unk_hp_023;
    int unk_hp_024;
    int unk_hp_025;
    int unk_hp_026;
    int unk_hp_027;
    int unk_hp_028;
    int unk_hp_029;
    int unk_hp_030;
    int unk_hp_031;
    int unk_hp_032;
    int unk_hp_033;
    int unk_hp_034;
    int unk_hp_035;
    int unk_hp_036;
    int unk_hp_037;
    int unk_hp_038;
    int unk_hp_039;
    int unk_hp_040;
    int unk_hp_041;
    int unk_hp_042;
    int unk_hp_043;
    int unk_hp_044;
    int unk_hp_045;
    int unk_hp_046;
    int unk_hp_047;
    int unk_hp_048;
    int unk_hp_049;
    int unk_hp_050;
    int unk_hp_051;
    int unk_hp_052;
    int unk_hp_053;
    int unk_hp_054;
    int unk_hp_055;
    int unk_hp_056;
    int unk_hp_057;
    int unk_hp_058;
    int unk_hp_059;
    int unk_hp_060;
    int unk_hp_061;
    int unk_hp_062;
    int unk_hp_063;
    int unk_hp_064;
    int unk_hp_065;
    int unk_hp_066;
    int unk_hp_067;
    int unk_hp_068;
    int unk_hp_069;
    int unk_hp_070;
    int unk_hp_071;
    int unk_hp_072;
    int unk_hp_073;
    int unk_hp_074;
    int unk_hp_075;
    int unk_hp_076;
    int unk_hp_077;
    int unk_hp_078;
    int unk_hp_079;
    int unk_hp_080;
    int unk_hp_081;
    int unk_hp_082;
    int unk_hp_083;
    int unk_hp_084;
    int unk_hp_085;
    int unk_hp_086;
    int unk_hp_087;
    int unk_hp_088;
    int unk_hp_089;
    int unk_hp_090;
    int unk_hp_091;
    int unk_hp_092;
    int unk_hp_093;
    int unk_hp_094;
    int unk_hp_095;
    int unk_hp_096;
    int unk_hp_097;
    int unk_hp_098;
    int unk_hp_099;
    int unk_hp_100;
    int unk_hp_101;
    int unk_hp_102;
    int unk_hp_103;
    int unk_hp_104;
    int unk_hp_105;
    int unk_hp_106;
    int unk_hp_107;
    int unk_hp_108;
    int unk_hp_109;
    int unk_hp_110;
    int unk_hp_111;
    int unk_hp_112;
    int unk_hp_113;
    int unk_hp_114;
    int unk_hp_115;
    int unk_hp_116;
    int unk_hp_117;
    int unk_hp_118;
    int unk_hp_119;
    int unk_hp_120;
    int unk_hp_121;
    int unk_hp_122;
    int unk_hp_123;
    int unk_hp_124;
    int unk_hp_125;
    int unk_hp_126;
    int unk_hp_127;
    int unk_hp_128;
    int unk_hp_129;
    int unk_hp_130;
    int unk_hp_131;
    int unk_hp_132;
    int unk_hp_133;
    int unk_hp_134;
    int unk_hp_135;
    int unk_hp_136;
    int unk_hp_137;
    int unk_hp_138;
    int unk_hp_139;
    int unk_hp_140;
    int unk_hp_141;
    int unk_hp_142;
    int unk_hp_143;
    int unk_hp_144;
    int unk_hp_145;
    int unk_hp_146;
    int unk_hp_147;
    int unk_hp_148;
    int unk_hp_149;
    int unk_hp_150;
    int unk_hp_151;
    int unk_hp_152;
    int unk_hp_153;
    int unk_hp_154;
    int unk_hp_155;
    int unk_hp_156;
    int unk_hp_157;
    int unk_hp_158;
    int unk_hp_159;
    int unk_hp_160;
    int unk_hp_161;
    int unk_hp_162;
    int unk_hp_163;
    int unk_hp_164;
    int unk_hp_165;
    int unk_hp_166;
    int unk_hp_167;
    int unk_hp_168;
    int unk_hp_169;
    int unk_hp_170;
    int unk_hp_171;
    int unk_hp_172;
    int unk_hp_173;
    int unk_hp_174;
    int unk_hp_175;
    int unk_hp_176;
    int unk_hp_177;
    int unk_hp_178;
    int unk_hp_179;
    int unk_hp_180;
    int unk_hp_181;
    int unk_hp_182;
    int unk_hp_183;
    int unk_hp_184;
    int unk_hp_185;
    int unk_hp_186;
    int unk_hp_187;
    int unk_hp_188;
    int unk_hp_189;
    int unk_hp_190;
    int unk_hp_191;
    int unk_hp_192;
    int unk_hp_193;
    int unk_hp_194;
    int unk_hp_195;
    int unk_hp_196;
    int unk_hp_197;
    int unk_hp_198;
    int unk_hp_199;
    int unk_hp_200;
    int unk_hp_201;
    int unk_hp_202;
    int unk_hp_203;
    int unk_hp_204;
    int unk_hp_205;
    int unk_hp_206;
    int unk_hp_207;
    int unk_hp_208;
    int unk_hp_209;
    int unk_hp_210;
    int unk_hp_211;
    int unk_hp_212;
    int unk_hp_213;
    int unk_hp_214;
    int unk_hp_215;
    int unk_hp_216;
    int unk_hp_217;
    int unk_hp_218;
    int unk_hp_219;
    int unk_hp_220;
    int unk_hp_221;
    int unk_hp_222;
    int unk_hp_223;
    int unk_hp_224;
    int unk_hp_225;
    int unk_hp_226;
    int unk_hp_227;
    int unk_hp_228;
    int unk_hp_229;
    int unk_hp_230;
    int unk_hp_231;
    int unk_hp_232;
    int unk_hp_233;
    int unk_hp_234;
    int unk_hp_235;
    int unk_hp_236;
    int unk_hp_237;
    int unk_hp_238;
    int unk_hp_239;
    int unk_hp_240;
    int unk_hp_241;
    int unk_hp_242;
    int unk_hp_243;
    int unk_hp_244;
    int unk_hp_245;
    int unk_hp_246;
    int unk_hp_247;
    int unk_hp_248;
    int unk_hp_249;
    int unk_hp_250;
    int unk_hp_251;
    int unk_hp_252;
    int unk_hp_253;
    int unk_hp_254;
    int unk_hp_255;
    int unk_hp_256;
    int unk_hp_257;
    int unk_hp_258;
    int unk_hp_259;
    int unk_hp_260;
    int unk_hp_261;
    int unk_hp_262;
    int unk_hp_263;
    int unk_hp_264;
    int unk_hp_265;
    int unk_hp_266;
    int unk_hp_267;
    int unk_hp_268;
    int unk_hp_269;
    int unk_hp_270;
};

class MiddleHighProcess : public BaseProcess
{
  public:
    MiddleHighProcess();
    int unk_mhp_000;
    int unk_mhp_001;
    int unk_mhp_002;
    int unk_mhp_003;
    int unk_mhp_004;
    int unk_mhp_005;
    int unk_mhp_006;
    int unk_mhp_007;
    int unk_mhp_008;
    int unk_mhp_009;
    int unk_mhp_010;
    int unk_mhp_011;
    int unk_mhp_012;
    int unk_mhp_013;
    int unk_mhp_014;
    int unk_mhp_015;
    int unk_mhp_016;
    int unk_mhp_017;
    int unk_mhp_018;
    int unk_mhp_019;
    int unk_mhp_020;
    int unk_mhp_021;
    int unk_mhp_022;
    int unk_mhp_023;
    int unk_mhp_024;
    int unk_mhp_025;
    int unk_mhp_026;
    int unk_mhp_027;
    int unk_mhp_028;
    int unk_mhp_029;
    int unk_mhp_030;
    int unk_mhp_031;
    int unk_mhp_032;
    int unk_mhp_033;
    int unk_mhp_034;
    int unk_mhp_035;
    int unk_mhp_036;
    int unk_mhp_037;
    int unk_mhp_038;
    int unk_mhp_039;
    int unk_mhp_040;
    int unk_mhp_041;
    int unk_mhp_042;
    int unk_mhp_043;
    int unk_mhp_044;
    int unk_mhp_045;
    int unk_mhp_046;
    int unk_mhp_047;
    int unk_mhp_048;
    int unk_mhp_049;
    int unk_mhp_050;
    int unk_mhp_051;
    int unk_mhp_052;
    int unk_mhp_053;
    int unk_mhp_054;
    int unk_mhp_055;
    int unk_mhp_056;
    int unk_mhp_057;
    int unk_mhp_058;
    int unk_mhp_059;
    int unk_mhp_060;
    int unk_mhp_061;
    int unk_mhp_062;
    int unk_mhp_063;
    int unk_mhp_064;
    int unk_mhp_065;
    int unk_mhp_066;
    int unk_mhp_067;
    int unk_mhp_068;
    int unk_mhp_069;
    int unk_mhp_070;
    int unk_mhp_071;
    int unk_mhp_072;
    int unk_mhp_073;
    int unk_mhp_074;
    int unk_mhp_075;
    int unk_mhp_076;
    int unk_mhp_077;
    int unk_mhp_078;
    int unk_mhp_079;
    int unk_mhp_080;
    int unk_mhp_081;
    int unk_mhp_082;
    int unk_mhp_083;
    int unk_mhp_084;
    int unk_mhp_085;
    int unk_mhp_086;
    int unk_mhp_087;
    int unk_mhp_088;
    int unk_mhp_089;
    int unk_mhp_090;
    int unk_mhp_091;
    int unk_mhp_092;
    int unk_mhp_093;
    int unk_mhp_094;
    int unk_mhp_095;
    int unk_mhp_096;
    int unk_mhp_097;
    int unk_mhp_098;
    int unk_mhp_099;
    int unk_mhp_100;
    int unk_mhp_101;
    int unk_mhp_102;
    int unk_mhp_103;
    int unk_mhp_104;
    int unk_mhp_105;
    int unk_mhp_106;
    int unk_mhp_107;
    int unk_mhp_108;
    int unk_mhp_109;
    int unk_mhp_110;
    int unk_mhp_111;
    int unk_mhp_112;
    int unk_mhp_113;
    int unk_mhp_114;
    int unk_mhp_115;
    int unk_mhp_116;
    int unk_mhp_117;
    int unk_mhp_118;
    int unk_mhp_119;
    int unk_mhp_120;
    int unk_mhp_121;
    int unk_mhp_122;
    int unk_mhp_123;
    int unk_mhp_124;
    int unk_mhp_125;
    int unk_mhp_126;
    int unk_mhp_127;
    int unk_mhp_128;
    int unk_mhp_129;
    int unk_mhp_130;
    int unk_mhp_131;
    int unk_mhp_132;
    int unk_mhp_133;
    int unk_mhp_134;
    int unk_mhp_135;
    int unk_mhp_136;
    int unk_mhp_137;
    int unk_mhp_138;
};

class FUN_0092c950 : public BaseProcess
{
  public:
    FUN_0092c950();
    int unk_mlp_000;
    int unk_mlp_001;
    int unk_mlp_002;
    int unk_mlp_003;
    int unk_mlp_004;
    int unk_mlp_005;
    int unk_mlp_006;
    int unk_mlp_007;
    int unk_mlp_008;
    int unk_mlp_009;
    int unk_mlp_010;
    int unk_mlp_011;
    int unk_mlp_012;
    int unk_mlp_013;
    int unk_mlp_014;
    int unk_mlp_015;
    int unk_mlp_016;
    int unk_mlp_017;
    int unk_mlp_018;
    int unk_mlp_019;
    int unk_mlp_020;
    int unk_mlp_021;
    int unk_mlp_022;
    int unk_mlp_023;
    int unk_mlp_024;
    int unk_mlp_025;
    int unk_mlp_026;
    int unk_mlp_027;
    int unk_mlp_028;
    int unk_mlp_029;
    int unk_mlp_030;
    int unk_mlp_031;
    int unk_mlp_032;
    int unk_mlp_033;
    int unk_mlp_034;
    int unk_mlp_035;
    int unk_mlp_036;
    int unk_mlp_037;
};

class FUN_00906dc0 : public BaseProcess
{
  public:
    FUN_00906dc0();
    int unk_lp_000;
    int unk_lp_001;
    int unk_lp_002;
    int unk_lp_003;
    int unk_lp_004;
    int unk_lp_005;
    int unk_lp_006;
    int unk_lp_007;
    int unk_lp_008;
    int unk_lp_009;
    int unk_lp_010;
    int unk_lp_011;
    int unk_lp_012;
    int unk_lp_013;
    int unk_lp_014;
    int unk_lp_015;
    int unk_lp_016;
    int unk_lp_017;
    int unk_lp_018;
    int unk_lp_019;
    int unk_lp_020;
    int unk_lp_021;
    int unk_lp_022;
    int unk_lp_023;
    int unk_lp_024;
    int unk_lp_025;
    int unk_lp_026;
    int unk_lp_027;
    int unk_lp_028;
    int unk_lp_029;
    int unk_lp_030;
    int unk_lp_031;
    int unk_lp_032;
};

class ProcessVTableFix
{
  public:
    virtual void v_000();
    virtual void v_001();
    virtual void v_002();
    virtual void v_003();
    virtual void v_004();
    virtual void v_005();
    virtual void v_006();
    virtual void v_007();
    virtual void v_008();
    virtual void v_009();
    virtual void v_010();
    virtual void v_011();
    virtual void v_012();
    virtual void v_013();
    virtual void v_014();
    virtual void v_015();
    virtual void v_016();
    virtual void v_017();
    virtual void v_018();
    virtual void v_019();
    virtual void v_020();
    virtual void v_021();
    virtual void v_022();
    virtual void v_023();
    virtual void v_024();
    virtual void v_025();
    virtual void v_026();
    virtual void v_027();
    virtual void v_028();
    virtual void v_029();
    virtual void v_030();
    virtual void v_031();
    virtual void v_032();
    virtual void v_033();
    virtual void v_034();
    virtual void v_035();
    virtual void v_036();
    virtual void v_037();
    virtual void v_038();
    virtual void v_039();
    virtual void v_040();
    virtual void v_041();
    virtual void v_042();
    virtual void v_043();
    virtual void v_044();
    virtual void v_045();
    virtual void v_046();
    virtual void v_047();
    virtual void v_048();
    virtual void v_049();
    virtual void v_050();
    virtual void v_051();
    virtual void v_052();
    virtual void v_053();
    virtual void v_054();
    virtual void v_055();
    virtual void v_056();
    virtual void v_057();
    virtual void v_058();
    virtual void v_059();
    virtual void v_060();
    virtual void v_061();
    virtual void v_062();
    virtual void v_063();
    virtual void v_064();
    virtual void v_065();
    virtual void v_066();
    virtual void v_067();
    virtual void v_068();
    virtual void v_069();
    virtual void v_070();
    virtual void v_071();
    virtual void v_072();
    virtual void v_073();
    virtual void v_074();
    virtual void v_075();
    virtual void v_076();
    virtual void v_077();
    virtual void v_078();
    virtual void v_079();
    virtual void v_080();
    virtual void v_081();
    virtual void v_082();
    virtual void v_083();
    virtual void v_084();
    virtual void v_085();
    virtual void v_086();
    virtual void v_087();
    virtual void v_088();
    virtual void v_089();
    virtual void v_090();
    virtual void v_091();
    virtual void v_092();
    virtual void v_093();
    virtual void v_094();
    virtual void v_095();
    virtual void v_096();
    virtual void v_097();
    virtual void v_098();
    virtual void v_099();
    virtual void v_100();
    virtual void v_101();
    virtual void v_102();
    virtual void v_103();
    virtual void v_104();
    virtual void v_105();
    virtual void v_106();
    virtual void v_107();
    virtual void v_108();
    virtual void v_109();
    virtual void v_110();
    virtual void v_111();
    virtual void v_112();
    virtual void v_113();
    virtual void v_114();
    virtual void v_115();
    virtual void v_116();
    virtual void v_117();
    virtual void v_118();
    virtual void v_119();
    virtual void v_120();
    virtual void v_121();
    virtual void v_122();
    virtual void v_123();
    virtual void v_124();
    virtual void v_125();
    virtual void v_126();
    virtual void v_127();
    virtual void v_128();
    virtual void v_129();
    virtual void v_130();
    virtual void v_131();
    virtual void v_132();
    virtual void v_133();
    virtual void v_134();
    virtual void v_135();
    virtual void v_136();
    virtual void v_137();
    virtual void v_138();
    virtual void v_139();
    virtual void v_140();
    virtual void v_141();
    virtual void v_142();
    virtual void v_143();
    virtual void v_144();
    virtual void v_145();
    virtual void v_146();
    virtual void v_147();
    virtual void v_148();
    virtual void v_149();
    virtual void v_150();
    virtual void v_151();
    virtual void v_152();
    virtual void v_153();
    virtual void v_154();
    virtual void v_155();
    virtual void v_156();
    virtual void v_157();
    virtual void v_158();
    virtual void v_159();
    virtual void v_160();
    virtual void v_161();
    virtual void v_162();
    virtual void v_163();
    virtual void v_164();
    virtual void v_165();
    virtual void v_166();
    virtual void v_167();
    virtual void v_168();
    virtual void v_169();
    virtual void v_170();
    virtual void v_171();
    virtual void v_172();
    virtual void v_173();
    virtual void v_174();
    virtual void v_175();
    virtual void v_176();
    virtual void v_177();
    virtual void v_178();
    virtual void v_179();
    virtual void v_180();
    virtual void v_181();
    virtual void v_182();
    virtual void v_183();
    virtual void v_184();
    virtual void v_185();
    virtual void v_186();
    virtual void v_187();
    virtual void v_188();
    virtual void v_189();
    virtual void v_190();
    virtual void v_191();
    virtual void v_192();
    virtual void v_193();
    virtual void v_194();
    virtual void v_195();
    virtual void v_196();
    virtual void v_197();
    virtual void v_198();
    virtual void v_199();
    virtual void v_200();
    virtual void v_201();
    virtual void v_202();
    virtual void v_203();
    virtual void v_204();
    virtual void v_205();
    virtual void v_206();
    virtual void v_207();
    virtual void v_208();
    virtual void v_209();
    virtual void v_210();
    virtual void v_211();
    virtual void v_212();
    virtual void v_213();
    virtual void v_214();
    virtual void v_215();
    virtual void v_216();
    virtual void v_217();
    virtual void v_218();
    virtual void v_219();
    virtual void v_220();
    virtual void v_221();
    virtual void v_222();
    virtual void v_223();
    virtual void v_224();
    virtual void v_225();
    virtual void v_226();
    virtual void v_227();
    virtual void v_228();
    virtual void v_229();
    virtual void v_230();
    virtual void v_231();
    virtual void v_232();
    virtual void v_233();
    virtual void v_234();
    virtual void v_235();
    virtual void v_236();
    virtual void v_237();
    virtual void v_238();
    virtual void v_239();
    virtual void v_240();
    virtual void v_241();
    virtual void v_242();
    virtual void v_243();
    virtual void v_244();
    virtual void v_245();
    virtual void v_246();
    virtual void v_247();
    virtual void v_248();
    virtual void v_249();
    virtual void v_250();
    virtual void v_251();
    virtual void v_252();
    virtual void v_253();
    virtual void v_254();
    virtual void v_255();
    virtual void v_256();
    virtual void v_257();
    virtual void v_258();
    virtual void v_259();
    virtual void v_260();
    virtual void v_261();
    virtual void v_262();
    virtual void v_263();
    virtual void v_264();
    virtual void v_265();
    virtual void v_266();
    virtual void v_267();
    virtual void v_268();
    virtual void v_269();
    virtual void v_270();
    virtual void v_271();
    virtual void v_272();
    virtual void v_273();
    virtual void v_274();
    virtual void v_275();
    virtual void v_276();
    virtual void v_277();
    virtual void v_278();
    virtual void v_279();
    virtual void v_280();
    virtual void v_281();
    virtual void v_282();
    virtual void v_283();
    virtual void v_284();
    virtual void v_285();
    virtual void v_286();
    virtual void v_287();
    virtual void v_288();
    virtual void v_289();
    virtual void v_290();
    virtual void v_291();
    virtual void v_292();
    virtual void v_293();
    virtual void v_294();
    virtual void v_295();
    virtual void v_296();
    virtual void v_297();
    virtual void v_298();
    virtual void v_299();
    virtual void v_300();
    virtual void v_301();
    virtual void v_302();
    virtual void v_303();
    virtual void v_304();
    virtual void v_305();
    virtual void v_306();
    virtual void v_307();
    virtual void v_308();
    virtual void v_309();
    virtual void v_310();
    virtual void v_311();
    virtual void v_312();
    virtual void v_313();
    virtual void v_314();
    virtual void v_315();
    virtual void v_316();
    virtual void v_317();
    virtual void v_318();
    virtual void v_319();
    virtual void v_320();
    virtual void v_321();
    virtual void v_322();
    virtual void v_323();
    virtual void v_324();
    virtual void v_325();
    virtual void v_326();
    virtual void v_327();
    virtual void v_328();
    virtual void v_329();
    virtual void v_330();
    virtual void v_331();
    virtual void v_332();
    virtual void v_333();
    virtual void v_334();
    virtual void v_335();
    virtual void v_336();
    virtual void v_337();
    virtual void v_338();
    virtual void v_339();
    virtual void v_340();
    virtual void v_341();
    virtual void Method_0x558(void* arg1, void* arg2, MobileObject* actor);
};

class Host096d450
{
  public:
};

class ActorDeletionQueue
{
  public:
};

struct GlobalLock_011f11a0
{
};


class TES
{
  public:
};

class FUN_009320e0_class : public Actor
{
  public:
    void SetProcessLevel(void* arg1, void* arg2);
};

// @fnv 0x009320e0
void FUN_009320e0_class::SetProcessLevel(void* arg1, void* arg2)
{
    char processType;
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&processType, 1);
    switch (processType)
    {
    case PROCESS_TYPE_PROCESS_TYPE_NONE:
        if (m_pBaseProcess)
        {
            reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_009320e0::GlobalLock_011f11a0 *>(&::DAT_011f11a0))))->FUN_0040fbf0((char *)(0));
            reinterpret_cast<::ActorDeletionQueue *>((((ActorDeletionQueue*)&(*reinterpret_cast<void * *>(&::g_011e0e80)))))->FUN_0096d470(this, (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60())));
            delete m_pBaseProcess;
            reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_009320e0::GlobalLock_011f11a0 *>(&::DAT_011f11a0))))->FUN_0040fba0();
            m_pBaseProcess = 0;
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_HIGH:
        if (m_pBaseProcess)
        {
            if ((*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60())) != PROCESS_TYPE_PROCESS_TYPE_HIGH)
            {
                StartHighProcess();
            }
        }
        else
        {
            m_pBaseProcess = new HighProcess();
            reinterpret_cast<::Host096d450 *>((((Host096d450*)&(*reinterpret_cast<void * *>(&::g_011e0e80)))))->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_HIGH, false, false, (::MobileObject *)(false));
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH:
        if (m_pBaseProcess)
        {
            if ((*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60())) != PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH)
            {
                Unk_93();
            }
        }
        else
        {
            m_pBaseProcess = new MiddleHighProcess();
            reinterpret_cast<::Host096d450 *>((((Host096d450*)&(*reinterpret_cast<void * *>(&::g_011e0e80)))))->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_MIDDLE_HIGH, false, false, (::MobileObject *)(false));
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW:
        if (m_pBaseProcess)
        {
            if ((*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60())) != PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW)
            {
                Unk_92();
            }
        }
        else
        {
            m_pBaseProcess = new FUN_0092c950();
            reinterpret_cast<::Host096d450 *>((((Host096d450*)&(*reinterpret_cast<void * *>(&::g_011e0e80)))))->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_MIDDLE_LOW, false, false, (::MobileObject *)(false));
        }
        break;
    case PROCESS_TYPE_PROCESS_TYPE_LOW:
        if (m_pBaseProcess)
        {
            if ((*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60())) != PROCESS_TYPE_PROCESS_TYPE_LOW)
            {
                Unk_91();
            }
        }
        else
        {
            m_pBaseProcess = new FUN_00906dc0();
            reinterpret_cast<::Host096d450 *>((((Host096d450*)&(*reinterpret_cast<void * *>(&::g_011e0e80)))))->FUN_0096d450(this, PROCESS_TYPE_PROCESS_TYPE_LOW, false, false, (::MobileObject *)(false));
        }
        break;
    }

    if (GetNiNode())
    {
        if (!reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_009320e0::TES * *>(&::g_TES))))->IsCellBuffered(GetParentCell(), 0) || processType != 0)
        {
            Set3D(0, true);
        }
    }

    reinterpret_cast<::fnv_0055ec40::LoadObject *>(this)->FUN_0055ec40((uintptr_t)(arg1), (uintptr_t)(arg2));

    if (m_pBaseProcess)
    {
        ((ProcessVTableFix*)m_pBaseProcess)->Method_0x558(arg1, arg2, this);
    }
}
}  // namespace fnv_009320e0

namespace fnv_009339a0 {
struct GlobalObject_0041a250
{
    int unk00, unk04, unk08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    void FUN_00418900(const GlobalObject_0041a250&);
};
struct Audio
{
    GlobalObject_0041a250 FUN_00ad73b0(unsigned, unsigned);
};
struct Obj;
extern Obj* DAT_011dea3c;
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
    virtual Obj* v1e4();
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
    virtual Obj* v22c();
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
    virtual void v268(float);
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual float v284(void*);
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8(float);
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318(float);
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
    unsigned char unk7C;
    unsigned char unk7D;
    unsigned char unk7E;
    unsigned char unk7F;
    unsigned char unk80;
    unsigned char unk81;
    unsigned char unk82;
    unsigned char unk83;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    intptr_t unk94;
    GlobalObject_0041a250 PlaySoundByFormID(unsigned, int, unsigned, int);
    Obj* FUN_008d6f30();
    void FUN_009339a0(float, Obj*, bool);
};
// @fnv 0x009339a0
void Obj::FUN_009339a0(float delta, Obj* target, bool skip)
{
    Obj* data7 = v1e4();
    Obj* actor_ = 0;
    Obj* form4 = ((::fnv_009339a0::Obj *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v22c();
    if (form4 && reinterpret_cast<struct ::FUN_0041ca90 *>((form4))->get() == 28)
        actor_ = form4;
    bool aUnused4 = false;
    bool changedVal = false;
    if (target && ((::fnv_009339a0::Obj *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())) && unk7C)
    {
        GlobalObject_0041a250 sound;
        changedVal = true;
        (*reinterpret_cast<::fnv_009339a0::Obj * *>(&::DAT_011e0548)) = this;
        unk7D = 1;
        bool pending = true;
        if (((::fnv_009339a0::Obj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target))->FUN_007af430())))
        {
            unsigned id2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_009339a0::Obj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target))->FUN_007af430()))))->FUN_0084e3a0()));
            GlobalObject_0041a250 _other;
            if (((intptr_t)(reinterpret_cast<::DialogueItem *>(this)->FUN_005e3fa0())))
            {
                intptr_t progressA = ((intptr_t)(reinterpret_cast<::DialogueItem *>(this)->FUN_005e3fa0()));
                reinterpret_cast<::SoundPlaybackHandle *>(&(_other))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_009339a0::GlobalObject_0041a250 &)(((::fnv_009339a0::Audio *)(::FUN_00453a70()))->FUN_00ad73b0(id2, 0x105))));
                reinterpret_cast<::FUN_00ad8830_shell *>(&(_other))->FUN_00ad8830(false);
            }
            else
            {
                reinterpret_cast<::SoundPlaybackHandle *>(&(_other))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_009339a0::GlobalObject_0041a250 &)(PlaySoundByFormID(id2, 0, 0x40000102, 1))));
            }
            Audio* manager4 = ((::fnv_009339a0::Audio *)(::FUN_00ad9060()));
            reinterpret_cast<::fnv_00adbfd0::FUN_00adbfd0_cls *>((manager4))->FUN_00adbfd0((intptr_t)(((void *)(::FUN_00559450((int *)&(_other))))), {}, {});
            pending = false;
            unk7F = 0;
            unk7C = 0;
        }
        if (pending & unk7F)
        {
            float volumeA = v284(((void *)(::FUN_00559450((int *)(((::fnv_009339a0::Obj *)(::FUN_00460140((intptr_t)(target)))))
                ))));
            Audio* manager3 = ((::fnv_009339a0::Audio *)(::FUN_00ad9060()));
            reinterpret_cast<::fnv_00adbfd0::FUN_00adbfd0_cls *>((manager3))->FUN_00adbfd0((intptr_t)(((void *)(::FUN_00559450((int *)&(sound))))), {}, {});
            unk80 = 0;
            ((::fnv_009339a0::Obj *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v318(volumeA);
        }
    }
    if (!skip)
        v268(delta);
    v140();
    if (!skip)
        v2f8(delta);
    if (changedVal && actor_)
        actor_->unk94 = (intptr_t)this;
    Obj* item_ = FUN_008d6f30();
    if (item_)
        reinterpret_cast<::s54baf0::Owner *>((item_))->FUN_0054baf0();
    v178();
}
}  // namespace fnv_009339a0

class TESObjectCELL;

class GlobalE3D0
{
  public:
};

namespace GlobalsE3D0 {
extern GlobalE3D0* DAT_011dea10;
}
using GlobalsE3D0::DAT_011dea10;

class FUN_0081e3d0_C
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual ~FUN_0081e3d0_C();

    TESObjectCELL* FUN_008d6f30();
    bool FUN_0081e3d0();
};

// @fnv 0x0081e3d0
bool FUN_0081e3d0_C::FUN_0081e3d0()
{
    bool bResult = true;
    if (!reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::GlobalE3D0 * *>(&::g_TES))))->IsCellBuffered(FUN_008d6f30(), 1))
    {
        delete this;
        bResult = false;
    }
    return bResult;
}

template <> NiPointer<bhkCharacterController>::NiPointer(bhkCharacterController*);
template <> NiPointer<bhkCharacterController>::NiPointer(const NiPointer<bhkCharacterController>&);
template <> NiPointer<bhkCharacterController>::~NiPointer();
struct OwnerBase
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
    virtual bool v2a0();
};
struct Owner : OwnerBase
{
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
    BaseProcess* m_pBaseProcess;
    bool ReleaseCharacterController();
};
// Calls v2a0, then if m_pBaseProcess is set, assigns a null bhkCharacterController to it and returns the result of v2a0.
// @fnv 0x00930810
bool Owner::ReleaseCharacterController()
{
    bool result = v2a0();
    if (m_pBaseProcess)
        m_pBaseProcess->AssignCharacterController(NiPointer<bhkCharacterController>(0));
    return result;
}

class xProc
{
  public:
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
    virtual void Reset();
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
    virtual class xActorD* GetTarget();
    virtual void SetTarget(class xActorD* p);
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
    virtual void Refresh();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual int GetStateX();
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
    virtual void SetDialogue(class xActorD* p, int i);
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
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
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void SetPartner(class xActorD* p);
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void SetTalking(int i);
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void ClearPartner(class xActorD* p);
    void Update();
};
struct xInfo
{
    void* GetTarget();
};
class xConv
{
  public:
    int m_ai[3];
    xConv(class xActorD* pA, class xActorD* pB, void* pTopic);
};
class xPkg
{
  public:
    int m_ai[0x34];
    xPkg(xConv* pConv, class xActorD* pA, class xActorD* pB, int i, bool b1, bool b2);
    void SetTarget(void* p);
};
class xActorD
{
  public:
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
    virtual void v138();
    virtual bool IsBusyX(int i);
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
    virtual void v165();
    virtual void v166();
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
    virtual void AddPackage(class xPkg* p, int a, int b);
    int m_aiPad[0x19];
    xProc* m_pkProc;
    xPkg* GetCurrentPackage();
    bool StartConversation(xInfo* pInfo);
};

class FUN_00932070_MobileObject : public MobileObject
{
  public:
    void SaveProcess(unsigned int saveID);
};

// Saves the base process level and calls SaveGame on m_pBaseProcess with the given saveID.
// @fnv 0x00932070
void FUN_00932070_MobileObject::SaveProcess(unsigned int saveID)
{
    char level = -1;
    if (m_pBaseProcess)
    {
        level = (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60()));
    }
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&level, 1);
    reinterpret_cast<::fnv_0055e940::SaveReference *>(this)->FUN_0055e940(saveID);
    if (m_pBaseProcess)
    {
        m_pBaseProcess->SaveGame(saveID, this);
    }
}


class MagicProjectileTarget
{
  public:
};

class MagicProjectileRef
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void vff4();
    virtual void vff8();
    virtual void vffc();
    virtual void vf100();
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
    virtual void vf1d0();
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
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual void vf304();
    virtual void vf308();
    virtual void vf30c();
    virtual void vf310();
    virtual void vf314();
    virtual void vf318();
    virtual void vf31c();
    virtual void vf320();
    virtual void vf324();
    virtual void vf328();
    virtual void vf32c();
    virtual void vf330();
    virtual void vf334();
    virtual void vf338();
    virtual void vf33c();
    virtual void vf340();
    virtual void vf344();
    virtual void vf348();
    virtual void vf34c();
    virtual void vf350();
    virtual void vf354();
    virtual void vf358();
    virtual void vf35c();
    virtual void vf360();
    virtual void vf364();
    virtual void vf368();
    virtual void vf36c();
    virtual void vf370();
    virtual void vf374();
    virtual void vf378();
    virtual void vf37c();
    virtual void vf380();
    virtual void vf384();
    virtual void vf388();
    virtual void vf38c();
    virtual void vf390();
    virtual void vf394();
    virtual void vf398();
    virtual void vf39c();
    virtual void vf3a0();
    virtual void vf3a4();
    virtual void vf3a8();
    virtual void vf3ac();
    virtual void vf3b0();
    virtual void vf3b4();
    virtual void vf3b8();
    virtual void vf3bc();
    virtual void vf3c0();
    virtual void vf3c4();
    virtual void vf3c8();
    virtual void vf3cc();
    virtual void vf3d0();
    virtual void vf3d4();
    virtual void vf3d8();
    virtual void vf3dc();
    virtual void vf3e0();
    virtual void vf3e4();
    virtual void vf3e8();
    virtual void vf3ec();
    virtual void vf3f0();
    virtual void vf3f4();
    virtual void vf3f8();
    virtual void vf3fc();
    virtual void vf400();
    virtual void vf404();
    virtual void vf408();
    virtual void vf40c();
    virtual void vf410();
    virtual void vf414();
    virtual void vf418();
    virtual void vf41c();
    virtual void vf420();
    virtual void vf424();
    virtual void vf428();
    virtual void vf42c();
    virtual void vf430();
    virtual void vf434();
    virtual void vf438();
    virtual void vf43c();
    virtual void vf440();
    virtual void vf444();
    virtual void vf448();
    virtual void vf44c();
    virtual void vf450();
    virtual void vf454();
    virtual void vf458();
    virtual void vf45c();
    virtual void vf460();
    virtual void vf464();
    virtual void vf468();
    virtual void vf46c();
    virtual void vf470();
    virtual void vf474();
    virtual void vf478();
    virtual void vf47c();
    virtual void vf480();
    virtual void vf484();
    virtual void vf488();
    virtual void vf48c();
    virtual void vf490();
    virtual void vf494();
    virtual void vf498();
    virtual void vf49c();
    virtual void vf4a0();
    virtual void vf4a4();
    virtual void vf4a8();
    virtual void vf4ac();
    virtual void vf4b0();
    virtual void vf4b4();
    virtual void vf4b8();
    virtual void vf4bc();
    virtual void vf4c0();
    virtual void vf4c4();
    virtual void vf4c8();
    virtual void vf4cc();
    virtual void vf4d0();
    virtual void vf4d4();
    virtual void vf4d8();
    virtual void vf4dc();
    virtual void vf4e0();
    virtual void vf4e4();
    virtual void vf4e8();
    virtual void vf4ec();
    virtual void vf4f0();
    virtual void vf4f4();
    virtual void vf4f8();
    virtual void vf4fc();
    virtual void vf500();
    virtual void vf504();
    virtual void vf508();
    virtual void vf50c();
    virtual void vf510();
    virtual void vf514();
    virtual void vf518();
    virtual void vf51c();
    virtual void vf520();
    virtual void vf524();
    virtual void vf528();
    virtual void vf52c();
    virtual void vf530();
    virtual void vf534();
    virtual void vf538();
    virtual void vf53c();
    virtual void vf540();
    virtual void vf544();
    virtual void vf548();
    virtual void vf54c();
    virtual void vf550();
    virtual void vf554();
    virtual void vf558();
    virtual void vf55c();
    virtual void vf560();
    virtual void vf564();
    virtual void vf568();
    virtual void vf56c();
    virtual void vf570();
    virtual void vf574();
    virtual void vf578();
    virtual void vf57c();
    virtual void vf580();
    virtual void vf584();
    virtual void vf588();
    virtual void vf58c();
    virtual void vf590();
    virtual void vf594();
    virtual void vf598();
    virtual void vf59c();
    virtual void vf5a0();
    virtual void vf5a4();
    virtual void vf5a8();
    virtual void vf5ac();
    virtual void vf5b0();
    virtual void vf5b4();
    virtual void vf5b8();
    virtual void vf5bc();
    virtual void vf5c0();
    virtual void vf5c4();
    virtual void vf5c8();
    virtual void vf5cc();
    virtual void vf5d0();
    virtual void vf5d4();
    virtual void vf5d8();
    virtual void vf5dc();
    virtual void vf5e0();
    virtual void vf5e4();
    virtual void vf5e8();
    virtual void vf5ec();
    virtual MagicProjectileTarget* vf5f0();
};

class MagicProjectileObject
{
  public:
    void* vtbl00;
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
    MagicProjectileRef* unk68;

    NiPoint3 FUN_0056fb10();
    NiPoint3 FUN_00933630();
};

// @fnv 0x00933630
NiPoint3 MagicProjectileObject::FUN_00933630()
{
    if (unk68 && unk68->vf5f0())
    {
        MagicProjectileTarget* target = unk68->vf5f0();
        reinterpret_cast<::FUN_0050ea10_class *>((void *)(target))->FUN_0050ea10((*reinterpret_cast<::NiPoint3 *>(&::g_011e05d0)));
        return (*reinterpret_cast<::NiPoint3 *>(&::g_011e05d0));
    }
    return FUN_0056fb10();
}

struct Mid83b9a0
{
    int _pad[2];
    Mid83b9a0* _p8;
    bool FUN_0083b9a0();
};
// @fnv 0x009edd80
FUN_009edd80::FUN_009edd80(FUN_0083b9a0_shell* apTopic, Actor* apSpeaker, Actor* apTarget, int aiUnk, bool abUnkBD,
                           bool abUnkA0)
{
    pTopic = apTopic;
    if (apTopic)
        reinterpret_cast<::Mid83b9a0 *>((pTopic))->FUN_0083b9a0();
    iUnkA8 = 0;
    iUnkAC = 0;
    m_fPackageValue = 0.0f;
    m_pDialogueSpeaker = apSpeaker;
    pTarget = apTarget;
    m_pDialogueSpeaker->Unk_80(0);
    iUnk8C = 0;
    iUnk94 = 0;
    bUnkBD = abUnkBD;
    bUnk98 = false;
    bUnkBE = false;
    bUnkBF = false;
    bUnkC0 = false;
    bUnkBC = true;
    bUnkC1 = false;
    iUnk9C = 0;
    reinterpret_cast<::fnv_00967730::RelationOwner *>((((FUN_00967730_shell*)::_g_thePlayer)))->FUN_00967730((::fnv_00967730::RefDistance *)(apSpeaker), (::fnv_00967730::RefDistance *)(apTarget), (::fnv_00967730::Relationship *)(::FUN_009edd80 *)(this));
    iUnkC4 = 0;
    iUnkC8 = 50;
    iUnkB8 = aiUnk;
    bUnkA0 = abUnkA0;
    bUnkC2 = false;
    bUnkCC = true;
}
// @fnv 0x00934fd0
bool DialogueHost::FUN_00934fd0(MobileObject* target, int aiUnused2, int aiUnused3, int aiUnused4, int aiUnused5,
                                bool refresh, TESTopic* topic, int aiUnused8, int aiUnused9)
{
    if (FUN_00931850() || ((DialogueHost*)target)->FUN_00931850())
        return false;
    TESPackage* context = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)this)))->GetBaseTexture()))->GetCurrentPackage();
    Conversation* speaker = 0;
    if (!target || (target->Unk_85() != 0 && target->Unk_85() != 4 && target->Unk_85() != 9))
        return false;
    MobileObject* conversation = (MobileObject*)this;
    int previous = 0;
    if (((bool)(::FUN_00574900((const unsigned char *)(((MobileObject*)this))))))
        conversation = GetDialogueSpeaker(target, &previous);
    if (target != (MobileObject*)::_g_thePlayer)
        speaker = new Conversation((Character*)conversation, (PlayerCharacter*)target, topic);
    reinterpret_cast<::FUN_00934250_shell *>(this)->FUN_00934250();
    process->StopRunOncePackage();
    if (target == (MobileObject*)::_g_thePlayer || reinterpret_cast<::Mid83b9a0 *>((speaker))->FUN_0083b9a0())
    {
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)this)))->GetBaseTexture()))->SetProcessReference((MobileObject*)this);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)this)))->GetBaseTexture()))->ClearCachedTargetReferences(true);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)this)))->GetBaseTexture()))->ClearHighProcessState(target);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(target))->GetBaseTexture()))->ClearCachedTargetReferences(true);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(target))->GetBaseTexture()))->ClearHighProcessState(this);
        FUN_009edd80* location =
            new FUN_009edd80((FUN_0083b9a0_shell*)speaker, (Actor*)this, (Actor*)target, previous, true, true);
        location->iUnk8C = (intptr_t)topic;
        if (context)
            reinterpret_cast<::fnv_0067a1b0::FUN_0067a1b0_shell *>((((PackageMethods*)location)))->FUN_0067a1b0(context);
        reinterpret_cast<::PackageEx *>((((PackageMethods*)location)))->SetPackageType(28);
        reinterpret_cast<::TESPackage *>((((PackageMethods*)location)))->SetMustReachLocation(true);
        reinterpret_cast<::TESPackage *>((((PackageMethods*)location)))->SetMustComplete(true);
        FUN_00670b30* package = (FUN_00670b30*)new FUN_0067f030;
        reinterpret_cast<::LocationDescriptor *>((package))->FUN_0067f3c0(target);
        reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((((PackageMethods*)location)))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(package));
        delete package;
        PackageTargetObj* destination = new PackageTargetObj;
        reinterpret_cast<::FUN_00672fc0_shell *>((((PackageMethods*)location)))->FUN_00672fc0((::PackageTargetRecord *)(destination));
        delete destination;
        reinterpret_cast<::TESPackage *>((((PackageMethods*)location)))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(10));
        reinterpret_cast<::PackageTargetRecord *>((((::PackageTargetObj *)(reinterpret_cast<::Script *>((((PackageMethods*)location)))->GetData()))))->SetTargetKind((::PACK_TARG_TYPE)(0));
        reinterpret_cast<::PackageTargetRecord *>((((::PackageTargetObj *)(reinterpret_cast<::Script *>((((PackageMethods*)location)))->GetData()))))->SetTargetObjectReference(target);
        if (Unk_85() == 4)
            reinterpret_cast<::TESRegionGrassObject *>((((::PackageTargetObj *)(reinterpret_cast<::Script *>((((PackageMethods*)location)))->GetData()))))->AssignLandTexture((::TESLandTexture *)(200));
        else
            reinterpret_cast<::TESRegionGrassObject *>((((::PackageTargetObj *)(reinterpret_cast<::Script *>((((PackageMethods*)location)))->GetData()))))->AssignLandTexture((::TESLandTexture *)(90));
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)this)))->GetBaseTexture()))->ResetPackageState();
        SetDialoguePackage(location, false, true);
        if (refresh)
            ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)this)))->GetBaseTexture()))->SetProcessTarget((MobileObject*)this, 1);
        return true;
    }
    return false;
}
// On success, builds a package from pInfo, updates process state, and adds packages for the actors when applicable.
// @fnv 0x00935480
bool xActorD::StartConversation(xInfo* pInfo)
{
    int qrEZrs = ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->GetStateX();
    xConv* qsSDDgz = 0;
    xActorD* qfTOqo = m_pkProc->GetTarget();
    if (qfTOqo != (*reinterpret_cast<::xActorD * *>(&::_g_thePlayer)))
        qsSDDgz = new xConv(this, qfTOqo, 0);
    reinterpret_cast<::FUN_00934250_shell *>(this)->FUN_00934250();
    m_pkProc->Refresh();
    if (qfTOqo == (*reinterpret_cast<::xActorD * *>(&::_g_thePlayer)) || reinterpret_cast<::Mid83b9a0 *>((qsSDDgz))->FUN_0083b9a0())
    {
        if (!reinterpret_cast<::FUN_0067a690_shell *>((pInfo))->HasFlag100000())
        {
            ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->SetTalking(1);
            ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->SetPartner(qfTOqo);
            ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((qfTOqo))->GetBaseTexture()))->SetTalking(1);
            ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((qfTOqo))->GetBaseTexture()))->SetPartner(this);
        }
        xPkg* qxQHW = new xPkg(qsSDDgz, this, qfTOqo, 0, 0, ((intptr_t)(reinterpret_cast<::BGSCameraPath *>((pInfo))->GetPrevPath())) == 0);
        if (pInfo)
            reinterpret_cast<::fnv_0067a1b0::FUN_0067a1b0_shell *>((qxQHW))->FUN_0067a1b0((::TESPackage *)(pInfo));
        reinterpret_cast<::PackageEx *>((qxQHW))->SetPackageType(0x1c);
        reinterpret_cast<::TESPackage *>((qxQHW))->SetMustReachLocation(::FUN_008b1ff0((const char *)(pInfo)));
        reinterpret_cast<::TESPackage *>((qxQHW))->SetMustComplete(reinterpret_cast<::FUN_0067efd0_shell *>((pInfo))->FUN_0067efd0());
        reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((qxQHW))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(void *)(((void *)(reinterpret_cast<::PackageFields *>((pInfo))->pLocation))));
        reinterpret_cast<::fnv_00671e10::FUN_00671e10_shell *>((qxQHW))->FUN_00671e10((::fnv_00671e10::LocationDescriptor *)(void *)(((void *)(reinterpret_cast<::FUN_00672dd0_shell *>((pInfo))->FUN_00672dd0()))));
        reinterpret_cast<::FUN_00672fc0_shell *>((qxQHW))->FUN_00672fc0((::PackageTargetRecord *)(void *)(((void *)(reinterpret_cast<::Script *>((pInfo))->GetData()))));
        reinterpret_cast<::TESPackage *>((qxQHW))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(10));
        ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->Reset();
        AddPackage(qxQHW, 0, 1);
        reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>(this)->FUN_0057bd60((::fnv_0057bd60::MobileObject *)(qfTOqo));
        m_pkProc->SetTarget(qfTOqo);
        reinterpret_cast<::TESForm *>((m_pkProc))->ClearData();
        reinterpret_cast<::TESForm *>((m_pkProc))->ClearData();
        if (qfTOqo != (*reinterpret_cast<::xActorD * *>(&::_g_thePlayer)) && qfTOqo != this)
        {
            ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((qfTOqo))->GetBaseTexture()))->ClearPartner(qfTOqo);
            qfTOqo->AddPackage(((::xPkg *)(reinterpret_cast<::FUN_009344a0_shell *>(this)->FUN_009344a0())), 0, 1);
            ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((qfTOqo))->GetBaseTexture()))->SetTarget(qfTOqo);
            reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>((qfTOqo))->FUN_0057bd60((::fnv_0057bd60::MobileObject *)(::xActorD *)(this));
        }
        else if (!qfTOqo->IsBusyX(0))
            ((::xProc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->SetDialogue(this, 3);
        return true;
    }
    return false;
}
// Sets _p8 to this, then returns whether the value pointed to by _ref_006815c0() is non-zero.
// @fnv 0x0083b9a0
bool Mid83b9a0::FUN_0083b9a0()
{
    _p8 = this;
    return _p8 && *((int *)(((::Vec3 *)(void *)(_p8)))) ? 1 : 0;
}

namespace fnv_009344d0 {
// Based on the earlier contributor's candidate; call contracts reconstructed from the target.
struct SoundRef
{
    unsigned int id;
    int unk04;
    int unk08;
    SoundRef(const SoundRef&);
    ~SoundRef();
    SoundRef& operator=(const SoundRef&);
    SoundRef& FUN_00418900(const SoundRef&);
};
struct FUN_0040c0e0
{
    char* data;
    unsigned short length;
    unsigned short capacity;
    FUN_0040c0e0(const char*);
    ~FUN_0040c0e0();
};
struct Package
{
};
struct Item
{
    ~Item();
    int FUN_004d5850(int);
};
struct ActorObject;
struct Process
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
    virtual void v17(ActorObject*, int, int, int, int, int);
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
    virtual void v85(int);
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
    virtual void v165();
    virtual void v166();
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
    virtual void v187(unsigned int);
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
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220(int);
    virtual void v221(int);
    virtual unsigned char v222();
    virtual Item* v223();
    virtual void v224(int);
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292(int, SoundRef);
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452();
    virtual void v453();
    virtual void v454();
    virtual void v455();
    virtual void v456();
    virtual void v457();
    virtual void v458();
    virtual void v459();
    virtual void v460();
    virtual void v461();
    virtual void v462();
    virtual void v463();
    virtual void v464();
    virtual void v465(Item*);
    virtual Item* v466();
    virtual void v467(int);
};
struct ActorObject
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
    virtual unsigned char v63();
    virtual unsigned char v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73(void*);
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
    virtual ActorObject* v110(int);
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual int v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const struct Point* v125();
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
    virtual void v165();
    virtual void v166();
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
    virtual void v181(unsigned int);
    virtual void v182();
    virtual void v183(unsigned int);
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
    Process* process;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    unsigned char flag7c;
    unsigned char flag7d;
    __forceinline Process* GetProcess()
    {
        return (Process*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)this)))->GetBaseTexture()));
    }
    float FUN_009344d0(const char*, SoundRef*, unsigned int, unsigned int, int, int, int, ActorObject*, unsigned char,
                       unsigned char, unsigned char, unsigned char, unsigned char);
};
struct Point
{
    float x, y, z;
};
struct Node
{
};
struct Setting
{
};
struct EventManager
{
};
struct Audio
{
    SoundRef FUN_00ad7480(const char*, unsigned int, int);
};
typedef void(__cdecl* SoundCallback)(void*, unsigned int);
struct AudioManager
{
};
struct Clock
{
};
struct PlayerCharacter_ext : public PlayerCharacter
{
};
extern char str_01084d70;
// Creates and queues a named sound, configures playback parameters, and returns a computed float.
// @fnv 0x009344d0
float ActorObject::FUN_009344d0(const char* apSoundName, SoundRef* apSoundRef, unsigned int arg3, unsigned int arg4,
                                int duration, int target, int otherTarget, ActorObject* other, unsigned char update,
                                unsigned char playerSound, unsigned char arg11, unsigned char arg12,
                                unsigned char force)
{
    AudioManager* mgr;
    int activeVal;
    unsigned char playFlag;
    {
        Item* curItem;

        if (!::FUN_00574900((const unsigned char *)this))
            return 0.0f;
        {
            char text[512];
            float elapsed = 0.0f;
            FUN_0040c0e0 callState2(apSoundName);
            curItem = ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v223();
            ActorObject* isPlayer = 0;
            v181(arg3);
            v183(arg4);
            if (apSoundName == 0)
                return 0.0f;
            ::TaskQueueInterface::CopyStringToBuffer(text, 512, apSoundName);
            reinterpret_cast<::FUN_00934250_shell *>(this)->FUN_00934250();
            unsigned char child = (unsigned char)(int)(this == (void*)_g_thePlayer);
            float active = 0.0f;
            float timeMs;
            playFlag = child ? (unsigned char)1 : playerSound;
            if (((double)(reinterpret_cast<::RefS *>(this)->FUN_005723b0((::RefS *)(_g_thePlayer), 0, 0))) < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_009344d0::Setting *>(&::g_011cd378)))))) &&
                (!child || (child && reinterpret_cast<::FUN_004eaf60_shell *>((((PlayerCharacter_ext*)_g_thePlayer)))->FUN_004eaf60())))
                isPlayer = v110(0);
            if (!curItem)
            {
                if (arg12 && !((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v222())
                {
                    if (::BuildLipPath((::BSStringT<char> &)(callState2)))
                    {
                        if (arg11)
                        {
                            ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v220(1);
                            ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v85(1);
                            reinterpret_cast<::fnv_00905f30::S_00905f30_Owner *>(&((*reinterpret_cast<::fnv_009344d0::EventManager *>(&::fnv_008a20d0::g_011f11e0))))->StartLipSyncTask((::fnv_00905f30::S_00905f30_Actor *)(::fnv_009344d0::ActorObject *)(this), ((const char *)(::FUN_00559450((int *)&(callState2)))));
                            return 0.0f;
                        }
                        else
                        {
                            curItem = ((::fnv_009344d0::Item *)(::LoadBGSTerrainManager((const ::NiPointer< ::NiNode> &)(callState2))));
                            if (!curItem)
                                ::DAT_011d951c = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009344d0::Setting *>(&::originalRuntimeFloatSetting1221))))));
                            ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v220(0);
                        }
                    }
                }
                else
                {
                    ActorObject* found;
                    found = v110(0);
                    if (found)
                        found->v73(&str_01084d70);
                    if (((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v222())
                    {
                        ::SetFormAccumulate((this)->unk0c);
                        ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v221(0);
                    }
                }
            }
            activeVal = v121();
            if (activeVal)
            {
                if (activeVal)
                {
                    unsigned int a = target;
                    if (target || force)
                        process->v17(this, a, (!!target) + 2, 0, 1, 1);
                }
                if (other && other != this && (other->v63() || other->v64()))
                {
                    ActorObject* tmp = other;
                    unsigned char next = 1;
                    if (tmp->v64())
                    {
                        ActorObject* c = tmp;
                        Package* kIter = ((::fnv_009344d0::Package *)(reinterpret_cast<::FUN_009344a0_shell *>((c))->FUN_009344a0()));
                        if (kIter && ((intptr_t)(reinterpret_cast<::BGSCameraPath *>((kIter))->GetPrevPath())))
                            next = 0;
                    }
                    if (otherTarget || next)
                        ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((tmp))->GetBaseTexture()))->v17(tmp, otherTarget, (otherTarget != 0) + 2, 0, 1, 1);
                }
            }
            if (curItem)
            {
                active = (float)((double)((unsigned int)(::FUN_00559450((int *)(curItem)))) / ::DAT_0101db88);
                reinterpret_cast<::LipSyncAnimation *>((curItem))->ApplyToAnimationData((::BSFaceGenAnimationData *)(isPlayer), ::DAT_0101df44);
            }
            if (update && ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))
                ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v187(arg3);
            unsigned int flagsZ = 0x104;
            Node* node2 = (Node*)((void *)(reinterpret_cast<::DialogueItem *>(this)->FUN_005e3fa0()));
            if (node2 && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((node2))->FUN_007af430())))
            {
                void* space1 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((node2))->FUN_007af430()));
            }
            if (!playFlag)
                flagsZ |= 2;
            else
                flagsZ |= 1;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_009344d0::SoundRef &)(*apSoundRef))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_009344d0::SoundRef &)(((::fnv_009344d0::Audio *)(::FUN_00453a70()))->FUN_00ad7480(text, flagsZ, 0))));
            mgr = ((::fnv_009344d0::AudioManager *)(::FUN_00ad9060()));
            ActorObject* kSource;
            kSource = this;
            if (other && other->v64())
                kSource = other;
            reinterpret_cast<::fnv_00adc050::FUN_00adc050_cls *>((mgr))->FUN_00adc050(((unsigned int)(::FUN_00559450((int *)(apSoundRef)))), (intptr_t)(((void (&)(void *, unsigned int))::SetFormAccumulate)), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((kSource))->FUN_0084e3a0())));
            if (!playFlag)
            {
                Point pos = *v125();
                reinterpret_cast<::FUN_00ad8be0_shell *>((apSoundRef))->FUN_00ad8be0(::FUN_005790b0(), ::FUN_005790d0());
                reinterpret_cast<::FUN_00ad8b60_h *>((apSoundRef))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                reinterpret_cast<::FUN_00ad8f20_shell *>((apSoundRef))->FUN_00ad8f20((::NiAVObject *)(void *)(v116()));
            }
            else
                reinterpret_cast<::FUN_00ad89b0_shell *>((apSoundRef))->SetStaticAttenuation((int)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009344d0::Setting *>(&::g_011e060c)))))) * ::g_d100));
            if (curItem)
            {
                timeMs = (float)((((double)(reinterpret_cast<::FUN_004d5a90_Class *>((curItem))->GetNegativeMagnitude())) + ((double)(::fnv_008a2d20::FUN_008a2d20()))) * ::DAT_01017b70);
                reinterpret_cast<::SoundPlaybackHandle *>((apSoundRef))->SchedulePlayback((int)timeMs, 0);
                elapsed = (float)(((double)(reinterpret_cast<::FUN_004d5a90_Class *>((curItem))->GetNegativeMagnitude())) + ((double)(::fnv_008a2d20::FUN_008a2d20())));
                if (active > ::_DAT_01012060)
                    elapsed += active;
                else if (::FUN_00ad8b30((unsigned int *)(apSoundRef)))
                    elapsed = (float)(::FUN_00ad8b30((unsigned int *)(apSoundRef)) / ::DAT_01017b70 + elapsed);
                else
                    elapsed = (float)((double)duration * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009344d0::Setting *>(&::originalRuntimeFloatSetting184)))))) + elapsed);
                ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v467(((int)(::fnv::timer::Time())) + (int)timeMs);
                ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v465(curItem);
            }
            else
            {
                reinterpret_cast<::SoundPlaybackHandle *>((apSoundRef))->SchedulePlayback(1, 0);
                elapsed = (float)((double)duration * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009344d0::Setting *>(&::originalRuntimeFloatSetting184)))))));
            }
            if (flag7d)
                flag7c = 0;
            ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v292(0, *apSoundRef);
            if (curItem)
            {
                if (curItem != ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v466())
                {
                    delete curItem;
                }
                ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v224(0);
                ((::fnv_009344d0::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->v220(0);
            }
            return elapsed;
        }
    }
}
}  // namespace fnv_009344d0

namespace fnv_0092ed60 {

class FNVPoly
{
  public:
    virtual void unk_000();
    virtual void unk_001();
    virtual void unk_002();
    virtual void unk_003();
    virtual void unk_004();
    virtual void unk_005();
    virtual void unk_006();
    virtual void unk_007();
    virtual void unk_008();
    virtual void unk_009();
    virtual void unk_00a();
    virtual void unk_00b();
    virtual void unk_00c();
    virtual void unk_00d();
    virtual void unk_00e();
    virtual void unk_00f();
    virtual void unk_010();
    virtual void unk_011();
    virtual void unk_012();
    virtual void unk_013();
    virtual void unk_014();
    virtual void unk_015();
    virtual void unk_016();
    virtual void unk_017();
    virtual void unk_018();
    virtual void unk_019();
    virtual void unk_01a();
    virtual void unk_01b();
    virtual void unk_01c();
    virtual void unk_01d();
    virtual void unk_01e();
    virtual void unk_01f();
    virtual void unk_020();
    virtual void unk_021();
    virtual void unk_022();
    virtual void unk_023();
    virtual void unk_024();
    virtual void unk_025();
    virtual void unk_026();
    virtual void unk_027();
    virtual void unk_028();
    virtual void unk_029();
    virtual void unk_02a();
    virtual void unk_02b();
    virtual void unk_02c();
    virtual void unk_02d();
    virtual void unk_02e();
    virtual void unk_02f();
    virtual void unk_030();
    virtual void unk_031();
    virtual void unk_032();
    virtual void unk_033();
    virtual void unk_034();
    virtual void unk_035();
    virtual void unk_036();
    virtual void unk_037();
    virtual void unk_038();
    virtual void unk_039();
    virtual void unk_03a();
    virtual void unk_03b();
    virtual void unk_03c();
    virtual void unk_03d();
    virtual void unk_03e();
    virtual void unk_03f();
    virtual bool vIsActor();
    virtual void unk_041();
    virtual void unk_042();
    virtual void unk_043();
    virtual void unk_044();
    virtual void unk_045();
    virtual void unk_046();
    virtual void unk_047();
    virtual void unk_048();
    virtual void unk_049();
    virtual void unk_04a();
    virtual void unk_04b();
    virtual void unk_04c();
    virtual void unk_04d();
    virtual void unk_04e();
    virtual void unk_04f();
    virtual void unk_050();
    virtual void unk_051();
    virtual void unk_052();
    virtual void unk_053();
    virtual void unk_054();
    virtual void unk_055();
    virtual void unk_056();
    virtual void unk_057();
    virtual void unk_058();
    virtual void unk_059();
    virtual void unk_05a();
    virtual void unk_05b();
    virtual void unk_05c();
    virtual void unk_05d();
    virtual void unk_05e();
    virtual void unk_05f();
    virtual void unk_060();
    virtual void unk_061();
    virtual void unk_062();
    virtual void unk_063();
    virtual void unk_064();
    virtual void unk_065();
    virtual void* v198();
    virtual unsigned int v19c();
    virtual void unk_068();
    virtual void unk_069();
    virtual void unk_06a();
    virtual void unk_06b();
    virtual void unk_06c();
    virtual void unk_06d();
    virtual void unk_06e();
    virtual void unk_06f();
    virtual void unk_070();
    virtual void unk_071();
    virtual void unk_072();
    virtual void unk_073();
    virtual void unk_074();
    virtual void unk_075();
    virtual void unk_076();
    virtual void unk_077();
    virtual void unk_078();
    virtual void unk_079();
    virtual void unk_07a();
    virtual void unk_07b();
    virtual void unk_07c();
    virtual void unk_07d();
    virtual void unk_07e();
    virtual void unk_07f();
    virtual void unk_080();
    virtual void unk_081();
    virtual void unk_082();
    virtual void unk_083();
    virtual void unk_084();
    virtual void unk_085();
    virtual void unk_086();
    virtual void unk_087();
    virtual bool v220();
    virtual bool v224();
    virtual void unk_08a();
    virtual void unk_08b();
    virtual void unk_08c();
    virtual void unk_08d();
    virtual void unk_08e();
    virtual void unk_08f();
    virtual void unk_090();
    virtual void unk_091();
    virtual void unk_092();
    virtual void unk_093();
    virtual void unk_094();
    virtual void unk_095();
    virtual void unk_096();
    virtual void unk_097();
    virtual void unk_098();
    virtual void unk_099();
    virtual void unk_09a();
    virtual void unk_09b();
    virtual void unk_09c();
    virtual void unk_09d();
    virtual void unk_09e();
    virtual void unk_09f();
    virtual void unk_0a0();
    virtual void unk_0a1();
    virtual void unk_0a2();
    virtual void unk_0a3();
    virtual void unk_0a4();
    virtual void unk_0a5();
    virtual void unk_0a6();
    virtual void unk_0a7();
    virtual void unk_0a8();
    virtual void unk_0a9();
    virtual void unk_0aa();
    virtual void unk_0ab();
    virtual void unk_0ac();
    virtual void unk_0ad();
    virtual void unk_0ae();
    virtual void unk_0af();
    virtual void unk_0b0();
    virtual void unk_0b1();
    virtual void unk_0b2();
    virtual void unk_0b3();
    virtual void unk_0b4();
    virtual void unk_0b5();
    virtual void unk_0b6();
    virtual void unk_0b7();
    virtual void unk_0b8();
    virtual void unk_0b9();
    virtual void unk_0ba();
    virtual void unk_0bb();
    virtual void unk_0bc();
    virtual void unk_0bd();
    virtual void unk_0be();
    virtual void unk_0bf();
    virtual void unk_0c0();
    virtual void unk_0c1();
    virtual void unk_0c2();
    virtual void unk_0c3();
    virtual void unk_0c4();
    virtual void v314(void*);
    virtual void unk_0c6();
    virtual void unk_0c7();
    virtual void unk_0c8();
    virtual void unk_0c9();
    virtual void unk_0ca();
    virtual void unk_0cb();
    virtual void unk_0cc();
    virtual void unk_0cd();
    virtual void unk_0ce();
    virtual void unk_0cf();
    virtual void unk_0d0();
    virtual void unk_0d1();
    virtual void unk_0d2();
    virtual void unk_0d3();
    virtual void unk_0d4();
    virtual void unk_0d5();
    virtual void unk_0d6();
    virtual void unk_0d7();
    virtual void unk_0d8();
    virtual void unk_0d9();
    virtual void unk_0da();
    virtual void unk_0db();
    virtual void unk_0dc();
    virtual void unk_0dd();
    virtual void unk_0de();
    virtual void unk_0df();
    virtual void unk_0e0();
    virtual void unk_0e1();
    virtual void unk_0e2();
    virtual void unk_0e3();
    virtual void unk_0e4();
    virtual void unk_0e5();
    virtual void unk_0e6();
    virtual void unk_0e7();
    virtual void unk_0e8();
    virtual void unk_0e9();
    virtual void unk_0ea();
    virtual void unk_0eb();
    virtual void unk_0ec();
    virtual void unk_0ed();
    virtual void unk_0ee();
    virtual void unk_0ef();
    virtual void unk_0f0();
    virtual void unk_0f1();
    virtual void unk_0f2();
    virtual void unk_0f3();
    virtual unsigned int v3d0();
    virtual void v3d4(unsigned int);
    virtual void unk_0f6();
    virtual void unk_0f7();
    virtual void unk_0f8();
    virtual void unk_0f9();
    virtual void unk_0fa();
    virtual void unk_0fb();
    virtual void unk_0fc();
    virtual void unk_0fd();
    virtual void unk_0fe();
    virtual void unk_0ff();
    virtual void unk_100();
    virtual void unk_101();
    virtual void unk_102();
    virtual void unk_103();
    virtual void unk_104();
    virtual void unk_105();
    virtual void unk_106();
    virtual void unk_107();
    virtual void unk_108();
    virtual void unk_109();
    virtual void unk_10a();
    virtual void unk_10b();
    virtual void unk_10c();
    virtual void unk_10d();
    virtual void unk_10e();
    virtual void unk_10f();
    virtual void unk_110();
    virtual void unk_111();
    virtual void unk_112();
    virtual void unk_113();
    virtual void unk_114();
    virtual void unk_115();
    virtual void unk_116();
    virtual void unk_117();
    virtual void unk_118();
    virtual void unk_119();
    virtual void unk_11a();
    virtual void unk_11b();
    virtual void unk_11c();
    virtual void unk_11d();
    virtual void unk_11e();
    virtual void unk_11f();
    virtual void unk_120();
    virtual void unk_121();
    virtual void unk_122();
    virtual void unk_123();
    virtual void unk_124();
    virtual void unk_125();
    virtual void unk_126();
    virtual void unk_127();
    virtual void unk_128();
    virtual void unk_129();
    virtual void unk_12a();
    virtual void unk_12b();
    virtual void unk_12c();
    virtual void unk_12d();
    virtual void unk_12e();
    virtual void unk_12f();
    virtual void unk_130();
    virtual void unk_131();
    virtual void unk_132();
    virtual void unk_133();
    virtual void unk_134();
    virtual void unk_135();
    virtual void unk_136();
    virtual void unk_137();
    virtual void unk_138();
    virtual void unk_139();
    virtual void unk_13a();
    virtual void unk_13b();
    virtual void unk_13c();
    virtual void unk_13d();
    virtual void unk_13e();
    virtual void unk_13f();
    virtual void unk_140();
    virtual void unk_141();
    virtual void unk_142();
    virtual void unk_143();
    virtual void unk_144();
    virtual void unk_145();
    virtual void unk_146();
    virtual void unk_147();
    virtual void unk_148();
    virtual void unk_149();
    virtual void unk_14a();
    virtual void unk_14b();
    virtual void unk_14c();
    virtual void unk_14d();
    virtual void unk_14e();
    virtual void unk_14f();
    virtual void unk_150();
    virtual void unk_151();
    virtual void unk_152();
    virtual void unk_153();
    virtual void unk_154();
    virtual void unk_155();
    virtual void unk_156();
    virtual void unk_157();
    virtual void unk_158();
    virtual void unk_159();
    virtual void unk_15a();
    virtual void unk_15b();
    virtual void unk_15c();
    virtual void unk_15d();
    virtual void unk_15e();
    virtual void unk_15f();
    virtual void unk_160();
    virtual void unk_161();
    virtual void unk_162();
    virtual void unk_163();
    virtual void unk_164();
    virtual void unk_165();
    virtual void unk_166();
    virtual void unk_167();
    virtual void unk_168();
    virtual void unk_169();
    virtual void unk_16a();
    virtual void unk_16b();
    virtual void unk_16c();
    virtual void unk_16d();
    virtual void unk_16e();
    virtual void unk_16f();
    virtual void unk_170();
    virtual void unk_171();
    virtual void unk_172();
    virtual void unk_173();
    virtual void unk_174();
    virtual void unk_175();
    virtual void unk_176();
    virtual void unk_177();
    virtual void unk_178();
    virtual void unk_179();
    virtual void unk_17a();
    virtual void unk_17b();
    virtual void unk_17c();
    virtual void unk_17d();
    virtual void unk_17e();
    virtual void unk_17f();
    virtual void unk_180();
    virtual void unk_181();
    virtual void unk_182();
    virtual void unk_183();
    virtual void unk_184();
    virtual void unk_185();
    virtual void unk_186();
    virtual void unk_187();
    virtual void unk_188();
    virtual void unk_189();
    virtual void unk_18a();
    virtual void unk_18b();
    virtual void unk_18c();
    virtual void unk_18d();
    virtual void unk_18e();
    virtual void unk_18f();
    virtual void unk_190();
    virtual void unk_191();
    virtual void unk_192();
    virtual void unk_193();
    virtual void unk_194();
    virtual void unk_195();
    virtual void unk_196();
    virtual void unk_197();
    virtual void unk_198();
    virtual void v664(void*);
};
class BSShaderNoLightingProperty
{
  public:
};
class FNVTreeRoot;
class FUN_005be5c0_shell
{
  public:
};
class TopicInfoArray : public FUN_005be5c0_shell
{
  public:
};
class FNVTreeRoot
{
  public:
    TopicInfoArray* FUN_00717e50();
};

class FNVReferenceActions
{
  public:
};
class FUN_009b28a0_t
{
  public:
};
class FUN_0092f140_shell
{
  public:
};
class FNVCurrent : public TESObjectREFR
{
  public:
    void FUN_0092ed60(bool);
};
// Iterates topic arrays and the player, calling refresh actions and clearing matching flags on other references.
// @fnv 0x0092ed60
void FNVCurrent::FUN_0092ed60(bool refresh)
{
    TopicInfoArray* topicInfoArray = reinterpret_cast<FNVTreeRoot*>(&(*reinterpret_cast<int *>(&::g_011e0e80)))->FUN_00717e50();
    TESObjectREFR* index = 0;
    unsigned int array = 0;
    for (; array < reinterpret_cast<::FUN_005be5c0_shell *>((topicInfoArray))->FUN_005be5c0(0); ++array)
    {
        index = ((::TESObjectREFR *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((topicInfoArray))->FUN_00968670(array)));
        if (index != this)
        {
            if (index->IsActor())
            {
                TESObjectREFR* first = index;

                ((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>(first)))->GetBaseTexture()))->v664(this);
                if (refresh)
                {
                    reinterpret_cast<::S_8c4f10_Cls *>((reinterpret_cast<FNVReferenceActions*>(first)))->FUN_008c4f10(
                        (intptr_t)(reinterpret_cast<FNVPoly*>(this)->v198()));
                }

                if (((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>(first)))->GetBaseTexture()))->v3d0() ==
                    reinterpret_cast<FNVPoly*>(this)->v19c())
                {

                    ((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>(first)))->GetBaseTexture()))->v3d4(0);
                }
            }
            else if (reinterpret_cast<FNVPoly*>(index)->v224())
            {
                TESObjectREFR* other = index;
                reinterpret_cast<::RemOwner *>((reinterpret_cast<FNVReferenceActions*>(other)))->FUN_009c4c80((::RemForm *)(void *)(this));
            }
            else if (reinterpret_cast<FNVPoly*>(index)->v220())
            {
                TESObjectREFR* other = index;
                reinterpret_cast<::FUN_009b28a0_t *>((reinterpret_cast<FUN_009b28a0_t*>(other)))->FUN_009b28a0((uintptr_t)(this));
            }
            else if (refresh)
            {
                void* mobile = dynamic_cast<::MagicProjectile *>(reinterpret_cast<::MobileObject *>(index));
                if (mobile)
                {

                    reinterpret_cast<FNVPoly*>(mobile)->v314(reinterpret_cast<FNVPoly*>(this)->v198());
                }
            }
        }
    }
    {
        unsigned int offset = reinterpret_cast<::fnv_005de0f0::FUN_005de0f0_shell *>((topicInfoArray))->FUN_005de0f0(1);
        for (; offset < reinterpret_cast<::FUN_005be5c0_shell *>((topicInfoArray))->FUN_005be5c0(1); ++offset)
        {
            index = ((::TESObjectREFR *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((topicInfoArray))->FUN_00968670(offset)));
            if (index != this)
            {
                Actor* target = dynamic_cast<Actor*>(reinterpret_cast<MobileObject*>(index));
                if (target)
                {
                    if (refresh)
                    {

                        reinterpret_cast<::S_8c4f10_Cls *>((reinterpret_cast<FNVReferenceActions*>(target)))->FUN_008c4f10(
                            (intptr_t)(reinterpret_cast<FNVPoly*>(this)->v198()));
                    }

                    if (((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>(target)))->GetBaseTexture()))->v3d0() ==
                        reinterpret_cast<FNVPoly*>(this)->v19c())
                    {

                        ((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>(target)))->GetBaseTexture()))->v3d4(0);
                    }
                }
                else if (refresh)
                {
                    void* mobile2 = dynamic_cast<::MagicProjectile *>(reinterpret_cast<::MobileObject *>(index));
                    if (mobile2)
                    {

                        reinterpret_cast<FNVPoly*>(mobile2)->v314(reinterpret_cast<FNVPoly*>(this)->v198());
                    }
                }
            }
        }
    }
    if ((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
    {
        if (((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetBaseTexture())))
        {

            ((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetBaseTexture()))->v664(this);
        }
        if (refresh)
        {

            reinterpret_cast<::S_8c4f10_Cls *>((reinterpret_cast<FNVReferenceActions*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->FUN_008c4f10((intptr_t)(reinterpret_cast<FNVPoly*>(this)->v198()));
        }
        if (((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetBaseTexture())))
        {

            if (((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetBaseTexture()))->v3d0() ==
                reinterpret_cast<FNVPoly*>(this)->v19c())
            {

                ((::fnv_0092ed60::FNVPoly *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<BSShaderNoLightingProperty*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetBaseTexture()))->v3d4(0);
            }
        }
        if ((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)) && ((void *)(reinterpret_cast<::FUN_0092f140_shell *>((reinterpret_cast<FUN_0092f140_shell*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetFieldD2C())) == this)
        {
            ::fnv_00524d70::FUN_00524d70((char *)(reinterpret_cast<FUN_0092f140_shell*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))));
        }
    }
}
}  // namespace fnv_0092ed60

extern int DAT_0118a690;
void* __cdecl FNV_DynamicCast(void*, int, void*, void*, int);
// @fnv 0x00933480
int FUN_00933480(void* apObject)
{
    return FNV_DynamicCast(apObject, 0, &::DAT_01183028, &DAT_0118a690, 0) != 0;
}


struct UnkCallee
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4(int, int);
};
struct UnkRet
{
    char _0[16];
    UnkCallee* p10;
};
struct UnkHolder
{
    char _0[12];
    volatile int mC;
    volatile int m10;
    volatile int m14;
    UnkRet* FUN_00c85750();
    void FUN_00c72210();
};
// @fnv 0x00c72210
void UnkHolder::FUN_00c72210()
{
    UnkRet* r = FUN_00c85750();
    UnkCallee* c = r->p10;
    int v = m14;
    m10 = 0;
    if ((v & (int)0x80000000) == 0)
    {
        int off = (v & 0x3fffffff) * 8;
        c->F4(mC, off);
    }
    m14 = (int)0x80000000;
    mC = 0;
}


struct bhkWorldObject;
class NiAVObject;
struct bhkCollisionObject
{
public:
    static ::bhkCollisionObject *GetFromNiAVObject(::NiAVObject *);
};
struct bhkRigidBody_shell
{
    int FUN_00517630();
};
struct FNV_ALIGN(16) bhkUnaryAction
{
    char buf[16];
    bhkUnaryAction();
    void Set(float, float, float, float);
};
struct Vec3Arg
{
};
class NiNode
{
  public:
    unsigned int FUN_0043b480();
public:
    ::NiAVObject *GetAt(unsigned int);
};

// NiAVObject as far as FUN_0062b930 uses it: vtable slot 3 returns the object as a node, or null.
struct SceneNodeQuery
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual NiNode* IsSceneNode();
};
// @fnv 0x0062b930
void __cdecl FUN_0062b930(NiAVObject* apObject, Vec3Arg* apVec, bool abFlag)
{
    if (apObject)
    {
        bhkCollisionObject* j = ::bhkCollisionObject::GetFromNiAVObject(apObject);
        if (j)
        {
            bhkRigidBody_shell* e = (bhkRigidBody_shell*)((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(j))));
            if (e)
            {
                int c = e->FUN_00517630();
                if (((bool)(::FUN_00c8cce0(&c))))
                {
                    bhkUnaryAction l;
                    l.Set(*((float *)&(reinterpret_cast<::bhkCharacterController *>((apVec))->GetVectorElement(0))), *((float *)&(reinterpret_cast<::bhkCharacterController *>((apVec))->GetVectorElement(1))), *((float *)&(reinterpret_cast<::bhkCharacterController *>((apVec))->GetVectorElement(2))), 0.0f);
                    if (!abFlag)
                    {
                        reinterpret_cast<::V *>(&(l))->FUN_00553f70((*(const ::V *)(((void *)&(::fnv_00560d80::FUN_00560d80((void *)(e)))))));
                    }
                    reinterpret_cast<::S *>((e))->FUN_00561690((std::intptr_t)(&l));
                }
            }
        }
        NiNode* k = reinterpret_cast<SceneNodeQuery*>(apObject)->IsSceneNode();
        if (k)
        {
            for (unsigned int ba = 0; ba < k->FUN_0043b480(); ba++)
            {
                NiAVObject* b = k->GetAt(ba);
                FUN_0062b930(b, apVec, abFlag);
            }
        }
    }
}

struct xFilter
{
    xFilter(int, unsigned int, int);
    unsigned int m_uiFilterValue;
};
struct xDH;
struct xCinfoSub
{
    int m_q[12];
};
struct __declspec(align(16)) xCinfo
{
    xCinfo();
    ~xCinfo();
    unsigned int m_uiFilterInfo;
    int m_pCollisionShape;
    int m_pad08[6];
    xCinfoSub m_20;
    int m_pad50[4];
};
struct xNiAlloc
{
};
struct xShape : xNiAlloc
{
    xShape(float, bool);
    int m_auiShapeKeys[5];
};
struct xBody : xNiAlloc
{
    xBody(xCinfo*);
    int m_auiShapeKeys[6];
};
struct xNode;
struct xWorld;
struct xCell;
struct xBodyV
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
    virtual void FUN_9c(xWorld*);
};

struct xPtr
{
    bool operator==(xNode*) const;
    void FUN_0066b0d0(void*);
    xBodyV* operator->();
    void* m_p;
};
struct xDHOwner
{
};
struct xRef
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
    virtual xDHOwner* FUN_1d0();
    char m_pad04[0x9c];
    xPtr m_a0;
    void FUN_009ae280();
};

// @fnv 0x009ae280
void xRef::FUN_009ae280()
{
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::xPtr &)(m_a0))->operator==((int)(0)) && ((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
    {
        xCinfo CINFO;
        xShape* SHAPE = new xShape(reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930(), true);
        CINFO.m_pCollisionShape = ::FUN_004ae750(SHAPE);
        CINFO.m_uiFilterInfo = ((unsigned int)(::FUN_00559450((int *)&ResultSlot(xFilter(0x29, ::FUN_005dbe10(), 0)))));
        if (FUN_1d0())
            reinterpret_cast<::FUN_009ae4a0_class *>(&(CINFO.m_20))->FUN_009ae4a0(((::xDH *)(::FUN_00461130((intptr_t)(FUN_1d0())))));
        else
            reinterpret_cast<::FUN_0056e120_shell *>(&(CINFO.m_20))->FUN_0056e120();
        m_a0.FUN_0066b0d0(new xBody(&CINFO));
        m_a0->FUN_9c(((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())));
    }
}
class Point9BE
{
  public:
    Point9BE();
    Point9BE(float fX, float fY, float fZ);
    float x, y, z;
};

class Matrix9BE
{
  public:
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

class hkVector4_9BE
{
  public:
    hkVector4_9BE();
    hkVector4_9BE(float fX, float fY, float fZ, float fW);
    __m128 m_vComponents;
};

class Filter9BE
{
  public:
    Filter9BE();
    unsigned int m_uiBits;
};

class Node9BE;

class Entity9BE
{
  public:
};

class WorldObject9BE
{
  public:
    Filter9BE GetFilter();
};

class CollisionObject9BE
{
  public:
};

class NiNode9BE;

class Node9BE
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual NiNode9BE* IsSceneNode();
    const Matrix9BE& GetRotate();
};

class NiNode9BE : public Node9BE
{
  public:
    Node9BE* GetAt(unsigned int uiIndex);
};

class Shape9BE
{
  public:
    Shape9BE(float fRadius, int iType);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class World9BE
{
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
    virtual void HandleNode(Node9BE* pkNode, int iA, int iB, unsigned int uiFilterInfo, int iC);
};

class ControllerInfo9BE
{
  public:
    ControllerInfo9BE(int iType);
    ~ControllerInfo9BE();
    __m128 m_q00;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
    __m128 m_qb0;
};

class Actor9BE;

class Controller9BE
{
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
    virtual void SetState(int iState);
    static void* operator new(std::size_t uiSize);
    static void operator delete(void* pvMem);
    Controller9BE(ControllerInfo9BE& kInfo, Actor9BE* pkActor);
    World9BE* GetWorld();
    Filter9BE GetFilter();
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
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
};

class ControllerPtr9BE
{
  public:
    ControllerPtr9BE(Controller9BE* pkController);
    ControllerPtr9BE(const ControllerPtr9BE& kOther);
    ~ControllerPtr9BE();
    Controller9BE* m_pPointer;
};

class Process9BE
{
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
    virtual void SetController(ControllerPtr9BE spController);
};

class Middle9BE
{
  public:
};

class Perks9BE
{
  public:
    virtual void v00();
    virtual void v04();
    virtual int GetLevel(int iPerk);
};

class Target9BE
{
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
    virtual Node9BE* Get3D();
    Filter9BE GetFilter();
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
    Perks9BE m_kPerks;
};

class Base9BE
{
  public:
};

class Actor9BE
{
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
    virtual Node9BE* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Point9BE* GetPos();
    void FUN_009be0a0();
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
    Process9BE* m_pkProcess;
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
    Target9BE* m_pkTarget;
};

class Setting9BE
{
  public:
};
extern const float g_fMaxValue9BE;


// @fnv 0x009be0a0
void Actor9BE::FUN_009be0a0()
{
    Node9BE* pkNode = Get3D();
    if (!pkNode || !m_pkProcess || ((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60())))
        return;
    Middle9BE* pkMiddle = ((::Middle9BE *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    World9BE* pkWorld = pkMiddle ? ((::World9BE *)(reinterpret_cast<::FUN_004543c0_cls *>((pkMiddle))->FUN_004543c0())) : 0;
    if (pkWorld)
    {
        if (reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(8))
        {
            ::FUN_00c6a0b0((::NiAVObject *)(pkNode), 0, 1, 0);
            ::FUN_00c6a350((::NiAVObject *)(pkNode), 4, 1, 0, 1);
            return;
        }
        CollisionObject9BE* pkCollision = ((::CollisionObject9BE *)(::FUN_004a8b00((::BGSBodyPart *)(pkNode))));
        WorldObject9BE* pkWorldObject = 0;
        Entity9BE* pkEntity = 0;
        if (reinterpret_cast<::FUN_00444d00_Class *>(this)->FUN_00444d00(4))
        {
            ::FUN_00c6a350((::NiAVObject *)(::Node9BE *)(Get3D()), 1, 1, 0, 1);
            if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce308)))))) != 0.0)
            {
                if (reinterpret_cast<::FUN_006d2c20_Class *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetFloatAtOffsetB0() > 0.0)
                    ::SetSelectionValue((intptr_t)(pkNode), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce308)))))) * reinterpret_cast<::FUN_006d2c20_Class *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetFloatAtOffsetB0(), 1, 0);
                else
                    ::SetSelectionValue((intptr_t)(pkNode), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce308)))))), 1, 0);
            }
            if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce5e8)))))) != 0.0)
                ::ApplyCollisionObjectCount((::NiAVObject *)(pkNode), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9BE *>(&::g_011ce5e8)))))), 1, 0);
            ::TraverseObject((::C6A2E0AVObject *)(pkNode), (void *)(6), 0, 1, 0);
            if (((::Target9BE *)(::FUN_00874480((char *)this))))
            {
                if (((::Target9BE *)(::FUN_00874480((char *)this)))->IsActor())
                {
                    Target9BE* pkOwner = ((::Target9BE *)(::FUN_00874480((char *)this)));
                    ::FUN_00c6a3d0(pkNode, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter9BE &)(pkOwner->GetFilter()))->FUN_004a3a20(), 1, 0);
                }
                else
                {
                    CollisionObject9BE* pkOwnerCollision = ((::CollisionObject9BE *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::Node9BE *)(((::Target9BE *)(::FUN_00874480((char *)this)))->Get3D()))));
                    WorldObject9BE* pkOwnerObject = pkOwnerCollision ? ((::WorldObject9BE *)(::fnv_006fa820::FUN_006fa820((const char *)(pkOwnerCollision)))) : 0;
                    if (pkOwnerObject)
                        ::FUN_00c6a3d0(pkNode, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter9BE &)(pkOwnerObject->GetFilter()))->FUN_004a3a20(), 1, 0);
                }
            }
            pkWorld->HandleNode(pkNode, 1, 1, 0, 0);
            if (pkCollision)
            {
                pkWorldObject = ((::WorldObject9BE *)(::FUN_004b5a80(((::Entity9BE *)(reinterpret_cast<::FUN_00620b80_shell *>((((::WorldObject9BE *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision))))))->GetReferenceFlags())))));
            }
            else if (pkNode->IsSceneNode())
            {
                NiNode9BE* pkParent = (NiNode9BE*)pkNode;
                if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pkParent))->FUN_00453470())))
                {
                    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pkParent))->FUN_00453470())); i++)
                    {
                        Node9BE* pkChild = ((::Node9BE *)(reinterpret_cast<::NiNode *>((pkParent))->GetAt(i)));
                        pkCollision = ((::CollisionObject9BE *)(::FUN_004a8b00((::BGSBodyPart *)(pkChild))));
                        if (pkCollision)
                        {
                            pkWorldObject = ((::WorldObject9BE *)(::FUN_004b5a80(((::Entity9BE *)(reinterpret_cast<::FUN_00620b80_shell *>((((::WorldObject9BE *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision))))))->GetReferenceFlags())))));
                            break;
                        }
                    }
                }
            }
            if (pkWorldObject && reinterpret_cast<::BGSProjectile *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88e0())
            {
                pkEntity = ((::Entity9BE *)(reinterpret_cast<::FUN_00620b80_shell *>((pkWorldObject))->GetReferenceFlags()));
                Point9BE kIntersectionOffset(reinterpret_cast<::FUN_00812870_t *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetUnka4(), reinterpret_cast<::LowProcess *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetCurrentDetectionAmount(), reinterpret_cast<::Getter_9b8 *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88c0());
                Point9BE kMotionVelocity;
                hkVector4_9BE kHkVelocity;
                Matrix9BE kRot = Get3D()->GetRotate();
                ::FUN_00a582f0((const float *)&(kRot), (const float *)&(const ::Point9BE &)(Point9BE(0.0f, 0.0f, 0.0f)), 1, (const ::Point314 *)&(kIntersectionOffset), (::Point314 *)&(kMotionVelocity));
                reinterpret_cast<::bhkUnaryAction *>(&(kHkVelocity))->Set(kMotionVelocity.x, kMotionVelocity.y, kMotionVelocity.z, 0.0f);
                reinterpret_cast<::FUN_00561800_Class *>((pkEntity))->FUN_00561800((::FUN_00561730_Obj *)&(kHkVelocity));
            }
            return;
        }
        Controller9BE* pkController = ((::Controller9BE *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
        if (!pkController)
        {
            ControllerInfo9BE kInfo(1);
            reinterpret_cast<::FUN_00857230_shell *>(&(kInfo))->SetSound((::TESSound *)(pkWorld));
            reinterpret_cast<::FUN_00810550_class *>(&(kInfo))->FUN_00810550(1.0f);
            reinterpret_cast<::FUN_008ac890_shell *>(&(kInfo))->SetWaterForm((::TESWaterForm *)(pkNode));
            reinterpret_cast<::FUN_00810510_Class *>(&(kInfo))->FUN_00810510((*(const ::NiPoint3 *)(GetPos())));
            if (reinterpret_cast<::BGSProjectile *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_009b88e0())
                reinterpret_cast<::FUN_008105c0_Class *>(&(kInfo))->SetPointer(new Shape9BE(1.0f, 1));
            else
                reinterpret_cast<::FUN_008105c0_Class *>(&(kInfo))->SetPointer(new Shape9BE(0.1f, 1));
            reinterpret_cast<::FUN_009beae0_class *>(&(kInfo))->SetByte95(0);
            reinterpret_cast<::FUN_00810530_c *>(&(kInfo))->FUN_00810530(0);
            float m_fGlyphExtent = reinterpret_cast<::FUN_00966980_shell *>((((::Base9BE *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_00966980();
            if (m_pkTarget && m_pkTarget->IsActor())
            {
                Target9BE* pkTarget = m_pkTarget;
                reinterpret_cast<::FUN_00810590_Class *>(&(kInfo))->FUN_00810590(6, reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::Filter9BE &)(pkTarget->GetFilter()))->FUN_004a3a20());
                if (pkTarget->m_kPerks.GetLevel(0x33) > 0)
                    m_fGlyphExtent *= 1.0f / FUN_00716440();
            }
            reinterpret_cast<::FUN_00407860_class *>(&(kInfo))->FUN_00407860(m_fGlyphExtent);
            reinterpret_cast<::FUN_00810570_shell *>(&(kInfo))->SetAssociatedActorValue(6);
            pkController = new Controller9BE(kInfo, this);
            reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((pkController))->FUN_00810610(((bool)(::FUN_00525420())));
            reinterpret_cast<::FUN_008105e0_Class *>((pkController))->FUN_008105e0(1);
            hkVector4_9BE kUp(-g_fMaxValue9BE, 0.0f, 0.0f, 0.0f);
            reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((pkController))->FUN_0080fb00((intptr_t)&(kUp));
            m_pkProcess->SetController(pkController);
            reinterpret_cast<::FUN_00810640_class *>((pkController))->FUN_00810640((intptr_t)(this));
            ::FUN_00c6a0b0((::NiAVObject *)(pkNode), 0, 1, 0);
        }
        if (pkController)
        {
            if (pkMiddle)
                ::FUN_0057b1d0((char *)(pkController), reinterpret_cast<::FUN_005471e0_shell *>((pkMiddle))->FUN_005471e0());
            else
                ::FUN_0057b1d0((char *)(pkController), ::DAT_01015f5c);
            World9BE* pkOldWorld = pkController->GetWorld();
            reinterpret_cast<::C70CharacterController *>((pkController))->FUN_00c70c90((::WorldProxy *)(pkWorld));
            Node9BE* pkOldNode = ((::Node9BE *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660()));
            bool bReset = true;
            if (pkOldNode != pkNode)
            {
                reinterpret_cast<::S_00c6d7a0_Obj *>((pkController))->FUN_00c6d7a0((intptr_t)(pkNode));
                if (pkWorld && ::FUN_004bae00((const char *)(pkWorld)))
                {
                    pkController->SetState(0);
                    ::CopyBlock48(((::Node9BE *)(reinterpret_cast<::FUN_00810660_Class *>((pkController))->FUN_00810660())), (const void *)(1));
                }
                ::FUN_00c6a350((::NiAVObject *)(pkNode), 4, 1, 0, 1);
                bReset = true;
            }
            Point9BE kPos = *GetPos();
            if (pkOldWorld != pkWorld)
            {
                if (pkOldWorld)
                    ::FUN_00c69ee0((::NiAVObject *)(pkNode), 1, 0);
                kPos.z += 8.0;
                bReset = true;
            }
            if (pkWorld)
            {
                reinterpret_cast<::S005620e0_Object *>((pkController))->FUN_005620e0((const ::S005620e0_Source *)&(kPos));
                if (bReset)
                {
                    Filter9BE kFilter = pkController->GetFilter();
                    unsigned int uiFilterInfo = reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(kFilter))->FUN_004a3a20();
                    pkWorld->HandleNode(pkNode, 1, 0, uiFilterInfo, 0);
                }
                else
                {
                    ::FUN_00c69f50((::S_00c69f50_Obj *)(pkNode), 1, 0);
                }
            }
        }
    }
}


extern const char str_010c4ad8[], str_010c4ac0[];
extern "C" void _ReadWriteBarrier();
extern float DAT_01267bc4;
extern float DAT_01267bb0;
struct Point { float x,y,z;
    __forceinline Point() {}
    __forceinline Point(float fX,float fY,float fZ) { x=fX; y=fY; z=fZ; }
    __forceinline Point operator/(float fScalar) const { float fInvScalar=1.0f/fScalar; return Point(x*fInvScalar,y*fInvScalar,z*fInvScalar); }
    __forceinline Point operator*(float fScalar) const { return Point(fScalar*x,fScalar*y,fScalar*z); }
    __forceinline Point& operator+=(const Point& rhs) { x=(float)(rhs.x+x);y=(float)(rhs.y+y);z=(float)(rhs.z+z);return *this; }
    __forceinline Point& operator*=(float factor) { x=factor*x;y=factor*y;z=factor*z;return *this; }
};
__forceinline void AddMovement(Point& out,const Point& rhs){out.x=(float)(rhs.x+out.x);out.y=(float)(rhs.y+out.y);out.z=(float)(rhs.z+out.z);}

struct S00c73170_Flags { unsigned int value; __forceinline void Or(unsigned int m) { value |= m; } __forceinline void Clear(unsigned int m) { value &= ~m; } __forceinline void Set(unsigned int m, bool on) { if (on) Or(m); else Clear(m); } __forceinline bool Bit(int n) const { return (value >> n) & 1; } };
class S00c73170_Bool { public: __forceinline S00c73170_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); } __forceinline operator bool() const { return m_cBooleanValue != 0; } char m_cBooleanValue; };
struct TraceEntry {
    const char* label; unsigned long tick; unsigned long unused;
    __forceinline void setTime() {
        unsigned int ticks;
        ticks = (unsigned int)__rdtsc();
        tick=ticks;
    }
};
template<typename T> class S00c73170_Pad { public: __forceinline T& val() { return m_kStorage; } __forceinline const T& val() const { return m_kStorage; } __forceinline void operator=(const T& p) { m_kStorage = p; } T m_kStorage; };
struct TraceBuffer {
    S00c73170_Pad<char*> m_kRayStart, m_kRayEnd, m_pRayCursor, m_pCurrentCommand;
    static __forceinline TraceBuffer& GetMonitorStream() { return *(TraceBuffer*)TlsGetValue(DAT_0126835c); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline S00c73170_Bool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }
};
__forceinline void Trace(const char* label) {
    TraceBuffer& mStream = TraceBuffer::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        TraceEntry* h = reinterpret_cast<TraceEntry*>(mStream.GetStreamEnd());
        h->label=label;
        h->setTime();
        mStream.setEnd((char*)(h+1));
    }
}

class S00c73170_Real {
public:
    __forceinline S00c73170_Real(const __m128& x) : m_vValue(x) {}
    __forceinline S00c73170_Real(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __m128 m_vValue;
};
class S00c73170_Vec {
public:
    __forceinline S00c73170_Vec() {}
    __forceinline S00c73170_Vec(const S00c73170_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void operator=(const S00c73170_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    __forceinline const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void setAll3(float a) { m_vComponents = _mm_set_ps1(a); }
    __forceinline void setSub4(const S00c73170_Vec& a, const S00c73170_Vec& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAdd4(const S00c73170_Vec& a, const S00c73170_Vec& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAbs4(const S00c73170_Vec& v) { m_vComponents = _mm_and_ps(v.m_vComponents, ::DAT_01017d10); }
    __forceinline void setNeg4(const S00c73170_Vec& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, ::DAT_010c44d0); }
    __forceinline void setMul4(const S00c73170_Vec& a, const S00c73170_Vec& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMul4(const S00c73170_Real& r, const S00c73170_Vec& v) { m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents); }
    __forceinline void addMul4(const S00c73170_Real& r, const S00c73170_Vec& v) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents)); }
    __forceinline void addMul4(const S00c73170_Vec& x, const S00c73170_Vec& y) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents)); }
    __forceinline void setAddMul4(const S00c73170_Vec& a, const S00c73170_Vec& x, const S00c73170_Vec& y) { m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents)); }
    __forceinline void setCross(const S00c73170_Vec& v0, const S00c73170_Vec& v1) {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline S00c73170_Real dot3(const S00c73170_Vec& a) const {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00c73170_Real length3() const {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        __m128 lenSq = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
        return _mm_sqrt_ss(lenSq);
    }
    __forceinline bool equals3(const S00c73170_Vec& v, float epsilon = 1e-3f) const {
        S00c73170_Vec t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        S00c73170_Vec epsilon_v;
        epsilon_v.setAll3(epsilon);
        return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 7) == 7;
    }
    __forceinline bool equals4(const S00c73170_Vec& v, float epsilon = 1e-3f) const {
        S00c73170_Vec t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        S00c73170_Vec epsilon_v;
        epsilon_v.setAll3(epsilon);
        return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 15) == 15;
    }
    __forceinline bool equalsV(__m128 v, float epsilon = 1e-3f) const { S00c73170_Vec t; t.m_vComponents=_mm_sub_ps(m_vComponents,v); t.setAbs4(t); S00c73170_Vec epsilon_v; epsilon_v.setAll3(epsilon); return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 15) == 15; }
    __forceinline void SetRotatedDirection(const S00c73170_Vec& quat, const S00c73170_Vec& direction);
    __m128 m_vComponents;
};
__forceinline void S00c73170_Vec::SetRotatedDirection(const S00c73170_Vec& quat, const S00c73170_Vec& direction) {
    S00c73170_Vec minusHalf; minusHalf.m_vComponents = ::DAT_010c71e0;
    S00c73170_Vec qreal; qreal.m_vComponents = _mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xff);
    S00c73170_Vec q2minus1; q2minus1.setAddMul4(minusHalf, qreal, qreal);
    S00c73170_Vec ret; ret.setMul4(direction, q2minus1);
    S00c73170_Vec imagDotDir; imagDotDir.m_vComponents = quat.dot3(direction).m_vValue;
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    ret.addMul4(imagDotDir, quat);
    S00c73170_Vec imagCrossDir; imagCrossDir.setCross(quat, direction);
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}
__forceinline const S00c73170_Vec& S00c73170_Zero() { return reinterpret_cast<const S00c73170_Vec&>((*reinterpret_cast<::__m128 *>(&::DAT_01267e30))); }
__forceinline void SetInt(int& out,int v){out=v;}
__forceinline bool EqualsV(__m128 a, __m128 b, float epsilon = 1e-3f) { S00c73170_Vec t; t.m_vComponents=_mm_sub_ps(b,a); t.setAbs4(t); S00c73170_Vec epsilon_v; epsilon_v.setAll3(epsilon); return (_mm_movemask_ps(_mm_cmple_ps(t.m_vComponents, epsilon_v.m_vComponents)) & 15) == 15; }
__forceinline void ScaleV(float scale,Point& out,const Point& input){out.x=scale*input.x;out.y=scale*input.y;out.z=scale*input.z;}
struct MovementInput {
    float dt, angle, unk08, speed;
    Point displacement; unsigned int unk1c;
    float scale; bool active;
};
struct Rotation {
    S00c73170_Vec q;
    void FUN_00cb2450(const S00c73170_Vec* axis, float angle);
};
struct State {
    unsigned int unk00;
};
struct Action {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void update(void*);
};
struct ActionSet {  };
struct RefObj {  };
struct S00c73170_RefPtr { RefObj* m_p; __forceinline void Clear() { if(m_p) reinterpret_cast<::hkReferencedObjectC905 *>((m_p))->FUN_00c905b0(); m_p=0; } };
struct BooleanFloatQuery {
    S00c73170_Vec normal, position;
    unsigned int material, unk24;
    struct Block32 { unsigned int a,b,c,d,e,f,g,h; } info;
    unsigned int object, unk4c;
    Block32 extra;
};
struct HitArray { BooleanFloatQuery* data; int size; unsigned int capacity; __forceinline void Append(const BooleanFloatQuery* src); };
struct Body {
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
    int mode;
};
struct Gravity {     unsigned int unk000;
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
    float acceleration;
};
struct AllocatorHolder { unsigned int unk00,unk04,unk08,unk0c; void* allocator; };
__forceinline void HitArray::Append(const BooleanFloatQuery* src) {
    AllocatorHolder* holder=(AllocatorHolder*)::FUN_00c85750();
    if(size==(capacity&0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(holder->allocator),(::AudioStream *)(::HitArray *)(this),0x70);
    BooleanFloatQuery* dst=data+size;
    if(dst) {
        dst->normal=src->normal;dst->position=src->position;
        dst->material=src->material;dst->unk24=src->unk24;
        dst->info=src->info;
        dst->object=src->object;dst->unk4c=src->unk4c;
        dst->extra=src->extra;
    }
    ++size;
}
struct Inspect { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,count; };
struct ReadyInterface {
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
    virtual int Ready();
};
struct MovementController {
        unsigned int unk000;
    unsigned int unk004;
    Body* body;
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
    State state;
    unsigned int unk3e4;
    unsigned int unk3e8;
    ActionSet* actions;
    unsigned int actionIndex;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    S00c73170_Flags fl;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    float value430;
    unsigned int value434;
    unsigned int value438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    S00c73170_Vec value450;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned char byte478,unk479,unk47a,unk47b;
    unsigned int unk47c;
    unsigned int value480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    S00c73170_Vec value4a0;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    S00c73170_Vec axis;
    S00c73170_Vec normal;
    unsigned int value4e0;
    unsigned int unk4e4;
    float time4e8;
    float inverse4ec;
    S00c73170_Vec velocity;
    S00c73170_Vec extraVelocity;
    S00c73170_Vec desiredVelocity;
    unsigned int value520;
    float value524;
    float value528;
    float value52c;
    float value530;
    unsigned int unk534;
    float value538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    float scale568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    float value578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    S00c73170_RefPtr ref630;
    float value634;
    S00c73170_RefPtr ref638;
    HitArray hits;
    void SubtractVectors(S00c73170_Vec*);
    Inspect* FUN_00621ad0();
};
// @fnv 0x00c73170
extern "C" int FUN_00c73170(MovementController* self, void*, MovementInput* in) {
    int result=0;
    struct SpeedTrace { float value; } speedTrace;
    Rotation rot;
    if (::FUN_00ca9600((char *)&(self->state))==4) {
        Trace(str_010c4ad8);
        Point temp;
        {
        S00c73170_Vec position;
        self->SubtractVectors(&position);
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&temp)),(*(const ::hkVector4 *)(&position)));
        }
        AddMovement(temp,in->displacement);
        reinterpret_cast<::S005620e0_Object *>((self))->FUN_005620e0((const ::S005620e0_Source *)(::Point *)(&temp));
        ((::Action *)(reinterpret_cast<::hkpCharacterStateView *>((self->actions))->FUN_00cbc510(self->actionIndex)))->update(self);
        Point* v;
        if(in->dt>0) {
            ScaleV(1.0f/in->dt,temp,in->displacement);
            v=&temp;
        } else v=&(*reinterpret_cast<::Point *>((void *)&::NiPoint3::ZERO));
        double x=v->x;
        _ReadWriteBarrier();
        double scale=::DAT_01267bcc;
        self->velocity(0)=x*scale;
        self->velocity(1)=v->y*scale;
        self->velocity(2)=v->z*scale;
        self->velocity(3)=0;
        Trace(::DAT_010c41f8);
        return 0;
    }
    self->fl.Clear(0xc0);
    reinterpret_cast<::fnv_00c70bd0::FUN_00c70bd0_cls *>((self))->ClearList();
    self->ref630.Clear();
    self->value634=0;
    self->ref638.Clear();
    self->scale568=in->scale/DAT_01267bc4;
    float dt=in->dt;
    int ready=((ReadyInterface*)self)->Ready();
    bool skip=in->dt<=DAT_01032980 || !ready;
    if(!skip) {
    if(self->fl.Bit(22)) {
        if(self->FUN_00621ad0()->count>0) goto done;
        self->fl.Clear(0x400000);
    }
    bool idle=::AreVectorsEqual((const float *)(::Point *)(&in->displacement),(const float *)(::Point *)(&(*reinterpret_cast<::Point *>((void *)&::NiPoint3::ZERO))),DAT_010181bc);
    bool mode20=self->fl.Bit(20);
    bool mode19=self->fl.Bit(19);
    if(!idle) { reinterpret_cast<::FUN_00c6d150_class *>((self))->FUN_00c6d150(); self->value528=0;self->value52c=0; }
    idle &= self->extraVelocity.equals3(S00c73170_Zero());
    if(!idle) self->fl.Or(8); else self->fl.Clear(8);
    Trace(str_010c4ac0);
    {
    S00c73170_Vec negAxis;
    reinterpret_cast<::C70940Obj *>((self))->FUN_00c70940(dt);
    self->value434=0x24; self->value438=0;
    float speed=reinterpret_cast<::FUN_00c6cc10_cls *>((self))->Evaluate(in->speed,in->dt);
    in->speed=speed;
    rot.FUN_00cb2450(&self->axis,-speed);
    self->time4e8=in->dt;
    self->inverse4ec=1.0f/in->dt;
    Point* displacement=&in->displacement;
    {
        Point tempStore=*displacement;
        Point& temp=tempStore;
        if(!((unsigned char)(::FUN_009306b0((::bhkCharacterController *)(self)))) && !self->fl.Bit(11)) temp.z=0;
        temp.y=temp.y;
        float& reciprocal=speedTrace.value;
        reciprocal=self->inverse4ec;
        temp*=reciprocal;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&self->desiredVelocity)),(*(const ::fnv_004a3e00::NiPoint3 *)(&temp)));
    }
    if(((unsigned char)(reinterpret_cast<::FUN_00c6d120_cls *>((self))->FUN_00c6d120())) && in->angle!=0) {
        S00c73170_Vec axisAngle; axisAngle.set(-1.0f,0.0f,0.0f,0.0f);
        Rotation q;
        q.FUN_00cb2450(&axisAngle,in->angle);
        self->desiredVelocity.SetRotatedDirection(q.q,self->desiredVelocity);
    }
    float* stepOut=&self->value578;*stepOut=self->value538;
    S00c73170_Vec down; down.set(0.0f,-1.0f,0.0f,0.0f);
    negAxis.setNeg4(self->axis);
    if(self->fl.Bit(25) || self->fl.Bit(26) || self->fl.Bit(0)) reinterpret_cast<::RotationOwner *>((self))->FUN_00c6e420((::FUN_005611c0_t *)(::Rotation *)(&rot));
    S00c73170_Vec rotated; rotated.SetRotatedDirection(rot.q,down);
    if(!idle || !rotated.equals3(self->normal)) self->value530=::DAT_011b014c;
    Body* savedBody=self->body;
    self->normal=rotated;
    if(mode19) {
        self->velocity=*((::S00c73170_Vec *)(reinterpret_cast<::Holder00807080 *>((self))->FUN_00807080()));
        self->value4a0=S00c73170_Zero();
        Trace(str_010c4ad8);
        ((::Action *)(reinterpret_cast<::FUN_00933810 *>((self))->Method()))->update(self);
        Trace(::DAT_010c41f8);
        reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((self))->FUN_0080fb00((intptr_t)(&self->velocity));
        reinterpret_cast<::CharProxy *>((self))->FUN_00c72250(self->time4e8);
    } else {
        (*reinterpret_cast<::Gravity * *>(&::DAT_01267bb4))=0;
        self->velocity=*((::S00c73170_Vec *)(reinterpret_cast<::Holder00807080 *>((self))->FUN_00807080()));
        if(idle && ::FUN_00ca9600((char *)&(self->state))!=2) self->velocity(2)=0;
        if(in->active || ::FUN_00ca9600((char *)&(self->state))!=0 || !reinterpret_cast<::NiPoint3 *>((void *)(displacement))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<::Point *>((void *)&::NiPoint3::ZERO)))) || self->value450.equals4(S00c73170_Zero())) {
            self->fl.Clear(0x600);
            self->fl.Or(0x10000);
            reinterpret_cast<::CharacterProbeLocal *>((self))->FUN_00c6e820();
            reinterpret_cast<::FUN_00c6cef0_cls *>((self))->CallTargetWithArgs((intptr_t)(&negAxis),(intptr_t)(&self->value480));
            self->fl.Clear(0x10000);
            bool contact=self->value480==2 && !self->byte478;
            if(self->fl.value&0x2000) {
                if(!(contact || self->fl.Bit(9)) || self->velocity(2)<=0) { self->fl.Clear(0x2000); contact=false; }
                else {
                    S00c73170_Vec v=self->velocity;
                    float length=v.length3();
                    if(length>0) {
                        S00c73170_Real inv=1.0f/length;
                        if(contact && self->fl.Bit(9) && self->value450(2)>=self->value430) {
                            S00c73170_Vec dir; dir.setMul4(inv,v);
                            float dot=dir.dot3(self->value450);
                            if(dot<=::DAT_0103c7c8) self->fl.Clear(0x2000);
                        }
                    }
                    contact=false;
                }
            } else contact|=self->fl.Bit(9);
            self->fl.Set(0x100,contact);
        }
        Trace(str_010c4ad8);
        ((::Action *)(reinterpret_cast<::hkpCharacterStateView *>((self->actions))->FUN_00cbc510(self->actionIndex)))->update(self);
        Trace(::DAT_010c41f8);
        if(self->body) reinterpret_cast<::CacObj *>((self->body))->FUN_00cac960((const ::CacV4 *)(::S00c73170_Vec *)(&self->velocity));
        bool changed=true;
        if(idle && ::FUN_00ca9600((char *)&(self->state))!=2 && (::FUN_00ca9600((char *)&(self->state))!=5 || self->velocity(2)==0) && ((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))))->size<=self->hits.size) {
            changed=false;
            for(int i=0;!changed;++i) {
                HitArray* loopArray=((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))));
                if(i>=loopArray->size) break;
 HitArray* currentArray=((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))));
 if(!EqualsV(currentArray->data[i].normal.m_vComponents,self->hits.data[i].normal.m_vComponents)) changed=true;
 else {
 currentArray=((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))));
 BooleanFloatQuery* previous=&self->hits.data[i];
 S00c73170_Vec pos=self->hits.data[i].position;
 if(!pos.equals4(currentArray->data[i].position) ||
                       previous->material!=((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))))->data[i].material) changed=true;
                    else {
                        BooleanFloatQuery& previousObject=self->hits.data[i];
                        if(previousObject.object!=((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))))->data[i].object) changed=true;
                    }
                }
            }
        }
        if(changed) {
            if(mode20) savedBody->mode=1;
            else savedBody->mode=4;
            reinterpret_cast<::CharacterProxy *>((self))->FUN_00c6cf30((uintptr_t)(&self->value4e0));
            savedBody->mode=4;
        } else {
            self->velocity=S00c73170_Zero();
            if(self->body) reinterpret_cast<::CacObj *>((self->body))->FUN_00cac960((const ::CacV4 *)(::S00c73170_Vec *)(&self->velocity));
        }
        if((*reinterpret_cast<::Gravity * *>(&::DAT_01267bb4)) && !(self->fl.value&0x2000)) {
            reinterpret_cast<::FUN_00cac110_Class *>((self))->FUN_00cac110();
            Body* target=((::Body *)(::FUN_004ae750((void *)(self))));
            S00c73170_Vec position=*((::S00c73170_Vec *)(reinterpret_cast<::CpuObject *>((target))->FUN_00cac910()));
            float gravity=(*reinterpret_cast<::Gravity * *>(&::DAT_01267bb4))->acceleration*self->time4e8;
            position(2)=self->value578+DAT_01267bb0+gravity;
            reinterpret_cast<::FUN_00cac920_Class *>((target))->FUN_00cac920(&position);
            position(2)=gravity+DAT_01267bb0;
            reinterpret_cast<::FUN_00cac110_Class *>((self))->FUN_00cac110();
        }
        self->value520=11;
        int size=((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))))->size;
        int n=size>5?5:size;
        for(int i=0;i<n;++i) {
            if(i<self->hits.size) reinterpret_cast<::FUN_006212c0_shell *>(&(self->hits.data[i]))->FUN_006212c0((void *)(&((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))))->data[i]));
            else {
                self->hits.Append(&((::HitArray *)(::FUN_00cac900((::SomeClass *)(savedBody))))->data[i]);
            }
        }
    }
    }
    if(self->fl.Bit(25) || self->fl.Bit(26)) reinterpret_cast<::AimController_c70060 *>((self))->FUN_00c70060();
    if(self->fl.value&0xc0) SetInt(result,2);
    Trace(::DAT_010c41f8);
    if(self->value524>0) {
        float remaining=self->value524-dt;
        self->value524=remaining;
        if(remaining<=0) { self->value524=0; self->extraVelocity.setZero4(); }
    }
    if(self->value530>0) self->value530-=dt;
    self->fl.Clear(0x1000);
    done: ;
    }
    return result;
}
#include "generated/data/fallout/ai/mobileobject.inc"
#include "generated/data/fallout/ai/mobileobject_o2_variant_od_oy_noo2_variant.inc"
#include "generated/data/fallout/ai/mobileobject_o2_variant_rtm_variant.inc"
