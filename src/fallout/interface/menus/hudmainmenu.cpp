// fallout/interface/menus/hudmainmenu.cpp: HUDMainMenu, HUDMainMenuS, Interface, TESSound and more (82 functions)

#include <windows.h>
#include <new>
#include <cstdio>
#include "fnv/decl/ActorInventoryQueryViews__ActorQuery.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/AudioClass_ae5680.h"
#include "fnv/decl/B63E00Owner.h"
#include "fnv/decl/B8C4890Actor.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSProjectile.h"
#include "fnv/decl/BSAudio_.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C77a400.h"
#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CamLook.h"
#include "fnv/decl/ChallengeManager.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/CombatProcedureActivateObject.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FNVSearchOwner.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_0041df00_shell.h"
#include "fnv/decl/FUN_0041e310_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043a2e0_host.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0046f070_shell.h"
#include "fnv/decl/FUN_00474a80_Class.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0047bcf0_class.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004b55c0_class.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004bcf00_stand.h"
#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_004c94d0_shell.h"
#include "fnv/decl/FUN_004fe160_cls.h"
#include "fnv/decl/FUN_00501270_shell.h"
#include "fnv/decl/FUN_00501ae0_shell.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_005098e0_Object.h"
#include "fnv/decl/FUN_00524b60_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00569060_shell.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b460_shell.h"
#include "fnv/decl/FUN_00595d10_shell.h"
#include "fnv/decl/FUN_005a03f0_obj.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005cbb70_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_005ec330_shell.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_007023a0_shell.h"
#include "fnv/decl/FUN_00703be0_Class.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_0073ac90_shell.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00778950_Class.h"
#include "fnv/decl/FUN_0077a450_class.h"
#include "fnv/decl/FUN_007eb8d0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00885560_shell.h"
#include "fnv/decl/FUN_00894900_shell.h"
#include "fnv/decl/FUN_008a16d0_shell.h"
#include "fnv/decl/FUN_008bbc10_shell.h"
#include "fnv/decl/FUN_008bc700_shell.h"
#include "fnv/decl/FUN_00948030_Class.h"
#include "fnv/decl/FUN_00953c20_shell.h"
#include "fnv/decl/FUN_00953c50_Class.h"
#include "fnv/decl/FUN_00967090_t.h"
#include "fnv/decl/FUN_009781a0_shell.h"
#include "fnv/decl/FUN_009d9f00_Class.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a074d0_shell.h"
#include "fnv/decl/FUN_00a07ed0_shell.h"
#include "fnv/decl/FUN_00a1db20_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00aa4db0_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad88b0_h.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FontManager.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/HWShell.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/HotkeyWheelUpdate.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/InventoryChangesIter.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ItemChangeValueShell.h"
#include "fnv/decl/ItemChange_004be200.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LockExtraData.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/MapMarkerData.h"
#include "fnv/decl/MarkerRef.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiPoint3Interpolator.h"
#include "fnv/decl/NiSourceTexture.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/PlayerCharShell.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/RepairMenu.h"
#include "fnv/decl/RockItAmmoCountDetail__PlayerView.h"
#include "fnv/decl/S148c0.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/Sf030.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/StringHolder.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESObjectCELL_Ext.h"
#include "fnv/decl/TESObjectDOOR.h"
#include "fnv/decl/TESWeightForm.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/Wheel.h"
#include "fnv/decl/XPMenu.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_00568cb0__FUN_00568cb0_shell.h"
#include "fnv/decl/fnv_005691b0__P01RefA.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575590__Thing.h"
#include "fnv/decl/fnv_00579280__ReferenceView.h"
#include "fnv/decl/fnv_005de0f0__FUN_005de0f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_007fd640__FUN_007fd640Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_008a6840__FUN_008a6840_shell.h"
#include "fnv/decl/fnv_008bb650__PlayerView.h"
#include "fnv/decl/fnv_008be7a0__FloatValueProvider.h"
#include "fnv/decl/fnv_008c4330__FUN_008c4330_cls.h"
#include "fnv/decl/fnv_00950110__FUN_00950110_pc.h"
#include "fnv/decl/fnv_00952ba0__PlayerCharacterStandIn.h"
#include "fnv/decl/fnv_00963eb0__PlayerView.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00973710__Shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a07c60__FUN_00a07c60_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/fnv_00a07f30__FUN_00a07f30_shell.h"
#include "fnv/decl/fnv_00a07fc0__FUN_00a07fc0_shell.h"
#include "fnv/decl/fnv_00a1b020__FUN_00a1b020_t.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/fnv_00a328b0__SeqExt.h"
#include "fnv/decl/s55d310__Owner.h"
#include "fnv/decl/xRefr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_004d1000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005cb000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00719000.h"
#include "fnv/symbols_0076b000.h"
#include "fnv/symbols_00770000.h"
#include "fnv/symbols_00771000.h"
#include "fnv/symbols_00772000.h"
#include "fnv/symbols_00773000.h"
#include "fnv/symbols_00774000.h"
#include "fnv/symbols_00775000.h"
#include "fnv/symbols_00778000.h"
#include "fnv/symbols_00779000.h"
#include "fnv/symbols_0077a000.h"
#include "fnv/symbols_0077b000.h"
#include "fnv/symbols_0077f000.h"
#include "fnv/symbols_007eb000.h"
#include "fnv/symbols_007f0000.h"
#include "fnv/symbols_007f4000.h"
#include "fnv/symbols_007f5000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_01035000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_0104f000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_01071000.h"
#include "fnv/symbols_01073000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011a5000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01203000.h"
#include "HUDMainMenu.h"

static const int kGetClassValue = 1004;

// m_pTiles is addressed by 1-based tile ID; slot 0 is the menu root.
enum
{
    kTileIDMax = 86
};

// @fnv 0x0076bdc0
int HUDMainMenu::GetClass()
{
    return kGetClassValue;
}

// Stores apTile in the tile array at index aTileID when aTileID is in the range 1..kTileIDMax.
// @fnv 0x0076bdd0
void HUDMainMenu::AssignTileByID(int aTileID, Tile* apTile)
{
    if (aTileID > 0 && aTileID <= kTileIDMax)
    {
        m_pTiles[aTileID] = apTile;
    }
}

class NiAVObject;
class NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
public:
    ::NiAVObject *GetAt(unsigned int);
};
struct NodeArg
{
    NiNode* n;
};
// @fnv 0x007700b0
void FUN_007700b0(char* self, NodeArg aNodeArg)
{
    ((NiPointer<NiNode>*)(self + 0x64))->operator=(aNodeArg.n);
}

struct FUN_007700d0_cls
{
    char pad[0x91];
    bool val;
    void set(bool b);
};

// @fnv 0x007700d0
void FUN_007700d0_cls::set(bool abValue)
{
    val = abValue;
}

struct FUN_00771540_shell : public HUDMainMenu
{
    void UpdateActorValueMeter(int);
};

struct AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetCurrent(int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float GetBase(int);
};

struct PlayerDummy
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
    virtual bool v139(int);
    char pad[0xa0];
    AVOwner avOwner;
};

class PlayerCharacter;


struct HUDMainMenu_WithPme : public HUDMainMenu
{
    static HUDMainMenu* g_pHudMainMenuInstance;
};

// @fnv 0x00771540
void FUN_00771540_shell::UpdateActorValueMeter(int aeActorValue)
{
    switch (aeActorValue)
    {
    case 16: {
        float fbase = ((PlayerDummy*)::_g_thePlayer)->avOwner.GetBase(16);
        if (fbase != ::_DAT_01012060)
        {
            fbase = FUN_00404010(0.0f, ((PlayerDummy*)::_g_thePlayer)->avOwner.GetCurrent(16)) / fbase;
        }
        if (fbase > 1.0)
        {
            fbase = 1.0f;
        }
        if (!((PlayerDummy*)::_g_thePlayer)->v139(0))
        {
            ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[1]), fbase, 0, 1, 0);
        }
        else
        {
            ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[1]), fbase, 0, 0, 0);
        }
        break;
    }
    case 12: {
        float fbase = FUN_00404010(0.0f, ((PlayerDummy*)::_g_thePlayer)->avOwner.GetBase(12));
        if (fbase != ::_DAT_01012060)
        {
            fbase = FUN_00404010(0.0f, ((PlayerDummy*)::_g_thePlayer)->avOwner.GetCurrent(12)) / fbase;
        }
        ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(m_pTiles[7]), FUN_0040ebd0(fbase, 1.0f), 1, 0, 0);
        break;
    }
    }
}

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
struct BGSImpactDataSet;
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
struct BaseFormComponent;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
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
struct HWND__;
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
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESCaravanCard;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCLOT;
struct TESObjectDOOR;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESQuest;
struct PlayerQuestData;
struct TESRace;
struct TESRegion;
struct TESRegionList;
struct TESReputation;
struct TESSkill;
struct TESSound;
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

// @fnv 0x007721a0
NiAVObject* FUN_007721a0(char* thisPtr)
{
    return *(NiAVObject**)(thisPtr + 0xe34);
}

namespace fnv_007735d0 {
struct Tile
{
    bool ContainsTrait(int);
};
struct StrOp
{
    operator void*() const;
};
struct Lst
{
};
extern HUDMainMenu* g_pHudMainMenuInstance;
// @fnv 0x007735d0
bool FUN_007735d0(unsigned char* self)
{
    if (!self[0x260])
        return false;
    void* xelem = (void*)(*(StrOp*)((char*)*(void**)&g_pHudMainMenuInstance->m_pTiles[14] + 4));
    Tile* pq = 0;
    while (xelem)
    {
        pq = (Tile*)*((void **)(reinterpret_cast<::ListStandIn *>((((Lst*)((char*)*(void**)&g_pHudMainMenuInstance->m_pTiles[14] + 4))))->FUN_0057cbe0((int **)&(xelem))));
        if (pq->ContainsTrait(0xfa3))
            return true;
    }
    self[0x260] = 0;
    return false;
}
}  // namespace fnv_007735d0

namespace fnv_00773650 {
struct Tile
{
    bool ContainsTrait(int);
};
struct StrOp
{
    operator void*() const;
};
struct Lst
{
};
extern HUDMainMenu* g_pHudMainMenuInstance;
// @fnv 0x00773650
bool FUN_00773650(unsigned char* self)
{
    if (!self[0x261])
        return false;
    void* xelem = (void*)(*(StrOp*)((char*)*(void**)&g_pHudMainMenuInstance->m_pTiles[13] + 4));
    Tile* pq = 0;
    while (xelem)
    {
        pq = (Tile*)*((void **)(reinterpret_cast<::ListStandIn *>((((Lst*)((char*)*(void**)&g_pHudMainMenuInstance->m_pTiles[13] + 4))))->FUN_0057cbe0((int **)&(xelem))));
        if (pq->ContainsTrait(0xfa3))
            return true;
    }
    self[0x261] = 0;
    return false;
}
}  // namespace fnv_00773650

struct BGSQuestObjective
{
    bool HasFlag();
};
struct Node
{
    bool _ref_008256d0();
};
struct Script
{
};
struct PM
{
};
extern HUDMainMenu* g_pHudMainMenuInstance;
// @fnv 0x007736d0
void __cdecl FUN_007736d0(Script* script)
{
    if (!g_pHudMainMenuInstance)
        return;
    if (script && !::fnv_00773650::FUN_00773650((unsigned char *)(((PM*)g_pHudMainMenuInstance))) && ((Node*)&g_pHudMainMenuInstance->m_kQuestObjectives[0])->_ref_008256d0())
    {
        Node* pNode = ((::Node *)(reinterpret_cast<::FUN_005d43e0_shell *>((script))->FUN_005d43e0()));
        while (pNode && !pNode->_ref_008256d0())
        {
            if ((*((::BGSQuestObjective **)(new ((void *)(pNode)) ::Vec3())))->HasFlag() && !(*((::BGSQuestObjective **)(new ((void *)(pNode)) ::Vec3())))->HasFlag())
                ::FUN_0077a5b0(reinterpret_cast<::FUN_005ec330_shell *>(((*((::BGSQuestObjective **)(new ((void *)(pNode)) ::Vec3())))))->GetPromptText(), 0, 1);
            pNode = ((::Node *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
    }
}

namespace fnv_00774800 {
struct Tile
{
    void Set(int, int);
};

// Calls Tile::Set with a fixed first argument and a second argument chosen by the brightness value.
// @fnv 0x00774800
void __cdecl FUN_00774800(Tile* apTile, int aeBrightness)
{
    switch (aeBrightness)
    {
    case 2:
        apTile->Set(0xff5, 0xff);
        break;
    case 1:
    case 3:
        apTile->Set(0xff5, 0xaf);
        break;
    case 4:
        apTile->Set(0xff5, 0x2c);
    case 5:
        apTile->Set(0xff5, 100);
        break;
    default:
        bool bhighDef = true;
        apTile->Set(0xff5, bhighDef ? 0xff : 0xaf);
        break;
    }
}
}  // namespace fnv_00774800

namespace fnv_007748b0 {
struct Tile
{
    void Set(int, int);
};

extern HUDMainMenu* DAT_011d96c0;

// @fnv 0x007748b0
void __cdecl UpdateMeterTile(Tile* apTile, float afMeterPercent, int aeJustify, int aiMinTicks, int iNumPixelShift)
{
    static int s_iTotalWidth = ::FUN_00a00940("_TotalWidth", -1);
    static int s_iImageWidth = ::FUN_00a00940("_ImageWidth", -1);
    static int s_iOriginalX = ::FUN_00a00940("_OriginalX", -1);

    if (apTile && DAT_011d96c0)
    {
        if (afMeterPercent > 1.0)
            afMeterPercent = 1.0f;
        else if (afMeterPercent < 0.0)
            afMeterPercent = 0.0f;

        int imeterWidth = static_cast<int>(reinterpret_cast<::TileListBoxCalls *>((apTile))->GetFloat(s_iTotalWidth));
        int iimageWidth = static_cast<int>(reinterpret_cast<::TileListBoxCalls *>((apTile))->GetFloat(s_iImageWidth));
        int inewX;
        int inewWidth;

        if (aeJustify == 2)
            inewWidth =
                static_cast<int>((imeterWidth * (afMeterPercent >= 0.0 ? afMeterPercent : 0.0f)) / (iimageWidth * 2)) *
                (iimageWidth * 2);
        else
            inewWidth =
                static_cast<int>((imeterWidth * (afMeterPercent >= 0.0 ? afMeterPercent : 0.0f)) / iimageWidth) *
                iimageWidth;

        if (inewWidth < iimageWidth * aiMinTicks)
            inewWidth = iimageWidth * aiMinTicks;

        inewX = static_cast<int>(reinterpret_cast<::TileListBoxCalls *>((apTile))->GetFloat(s_iOriginalX));
        if (aeJustify == 1)
            inewX -= inewWidth;
        else if (aeJustify == 2)
            inewX -= inewWidth / 2;

        inewX += iNumPixelShift;

        apTile->Set(0xfb1, inewWidth);
        apTile->Set(0xfa1, inewX);
    }
}
}  // namespace fnv_007748b0

struct FUN_00775670_shell : public HUDMainMenu
{
    void FUN_00775670();
};

class Tile
{
  public:
    void Set(int, int);
    void Set(int, char const*, bool);
public:
    void SetName(const char *);
public:
    void Set(int, unsigned int);
public:
    static float GetInterfaceScale();
};

class Interface
{
  public:
    enum enumMenus
    {
        kMenu_0 = 0
    };
    static bool __cdecl IsMenuActive(enumMenus, unsigned int);
};

extern HUDMainMenu* HUDMainMenu_pme;

// @fnv 0x00775670
void FUN_00775670_shell::FUN_00775670()
{
    if (!Interface::IsMenuActive((Interface::enumMenus)0x3f5, 0))
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((HUDMainMenu_pme->m_pTiles[28]))->FUN_00a01350(0xfc4, (char *)(::DAT_01020770), true);
    }
    HUDMainMenu_pme->m_pTiles[28]->Set(0xfa3, 0);
    m_pCurrentSubtitle = 0;
}

class BSExtraData;
class ExtraRadioData;
struct TESObjectREFR
{
public:
    ::BSExtraData *GetExtraData(unsigned char) const;
public:
    ::ExtraRadioData *GetExtraRadioData();
};


// @fnv 0x00778930
int GetExtraDataShort(const TESObjectREFR* pThis)
{
    return reinterpret_cast<::FUN_00418770_shell *>((void *)(((const ::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(pThis))->FUN_005d43c0()))))->FUN_00418770();
}

namespace fnv_00778b80 {
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

struct NiPoint3_helper : NiPoint3
{
};

struct PlayerCharacter
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
    virtual float GetLookingZAngle(int);
};

extern double DAT_010734f8;

// @fnv 0x00778b80
float __cdecl ComputeObjectAngleDelta(NiPoint3 apObjectLoc, NiPoint3 apPlayerLoc)
{
    float fangledelta;
    NiPoint3 movedir = (*(::fnv_00778b80::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(((NiPoint3_helper&)apObjectLoc)))->FUN_00439ef0((::NiPoint3 *)&(apPlayerLoc), *(const ::NiPoint3 *)nullptr)));
    float ftargetangle = ::GetAngleFromVector((const ::NiPoint3 &)(movedir));
    fangledelta = 0.0f;
    fangledelta = ftargetangle - (*reinterpret_cast<::fnv_00778b80::PlayerCharacter * *>(&::_g_thePlayer))->GetLookingZAngle(0);
    if (fangledelta <= ::DAT_0101ff58)
    {
        fangledelta += 6.2831854820251465;
    }
    else if (fangledelta > 3.1415927410125732)
    {
        fangledelta = 6.2831854820251465 - fangledelta;
    }
    fangledelta *= ::DAT_0102f248;
    fangledelta *= DAT_010734f8;
    return fangledelta;
}
}  // namespace fnv_00778b80

void* __cdecl operator new(unsigned int);
extern int DAT_011d96ac;

class ActorTaskManager
{
  public:
    void WaitForTasksDuringRendering(void);
};

class AnimIdle
{
  public:
};

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
public:
    void QueueActorDisarm(bool);
};

extern ActorTaskManager g_011d9730;

struct HUDMainMenu_pme_access : public HUDMainMenu
{
    static HUDMainMenu* g_pHudMainMenuInstance;
};

struct QuestObjective_local
{
    char m_kName[0x104];
    bool m_bCompleted;
    bool m_bDisplayed;
};

// @fnv 0x0077a5b0
void __cdecl FUN_0077a5b0(const char* apObjectiveName, bool abCompleted, bool abReminder)
{
    if (HUDMainMenu_pme_access::g_pHudMainMenuInstance && apObjectiveName)
    {
        reinterpret_cast<::GlobalObject_0044fae0 *>(&(g_011d9730))->FUN_004538a0(0);
        DAT_011d96ac = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00()));
        QuestObjective_local* pObjective = new QuestObjective_local;
        TaskQueueInterface::CopyStringToBuffer(pObjective->m_kName, 0x104, apObjectiveName);
        pObjective->m_bCompleted = abCompleted;
        pObjective->m_bDisplayed = abReminder;
        ((BSSimpleList<const char*>*)HUDMainMenu_pme_access::g_pHudMainMenuInstance->m_kQuestObjectives)
            ->AddHead((const char*&)pObjective);
        g_011d9730.WaitForTasksDuringRendering();
    }
}

struct QuestUpdateManager
{
    static void SetCustomQuestText(char*, char*, int, int, int, int, char*);
    void* GetQuestNamesItem();
    bool IsQuestNamesEmpty();
    static void AddQuestNamesHead(void*);
    static void AddQuestNamesTail(void*);
    void RemoveQuestNamesHead();
    void RemoveQuestNamesAll();
    static int SortQuestNamesByPriorityFunction(void*, void*);
    char _pad_0[1];
};
struct FUN_0077b2a0_shell : public QuestUpdateManager
{
    void* GetQuestNamesHead();
};

extern int g_011d970c;

// @fnv 0x0077b2a0
void* FUN_0077b2a0_shell::GetQuestNamesHead()
{
    return *((void **)(new ((void *)(&g_011d970c)) ::Vec3()));
}

namespace fnv_0077b2c0 {
struct QuestUpdateManager
{
    static void SetCustomQuestText(char*, char*, int, int, int, int, char*);
    void* GetQuestNamesItem();
    bool IsQuestNamesEmpty();
    static void AddQuestNamesHead(void*);
    static void AddQuestNamesTail(void*);
    void RemoveQuestNamesHead();
    void RemoveQuestNamesAll();
    static int SortQuestNamesByPriorityFunction(void*, void*);
    char _pad_0[1];
};
struct FUN_0077b2c0_shell : public QuestUpdateManager
{
    bool FUN_0077b2c0();
};

extern int g_011d970c;
bool _ref_008256d0(void* pThis);

// @fnv 0x0077b2c0
bool FUN_0077b2c0_shell::FUN_0077b2c0()
{
    return _ref_008256d0(&g_011d970c);
}
}  // namespace fnv_0077b2c0

namespace fnv_0077f3c0 {
struct NiAVObject
{
};
struct NiNode
{
};
struct StrOp
{
    operator const char*() const;
};
extern HUDMainMenu* g_pHudMainMenuInstance;
extern StrOp g_011d9770;
// If the HUD menu and node exist, stores visible in the menu and sets the node's app-culled flag to its inverse.
// @fnv 0x0077f3c0
void __cdecl SetHudVisible(bool visible)
{
    if (g_pHudMainMenuInstance && (const char*)g_011d9770)
    {
        if (((::fnv_0077f3c0::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((((NiNode*)(const char*)g_011d9770)))->FUN_0045bc00(0))))
        {
            g_pHudMainMenuInstance->m_bHudModeActive = visible;
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)(const char*)g_011d9770)))->QueueActorDisarm(!visible);
        }
    }
}
}  // namespace fnv_0077f3c0

namespace fnv_0077f500 {
struct Tile
{
    void Set(int, int);
};
struct TList
{
    void* GetBegin() const;
    Tile** GetNext(void*&);
};
struct StrOp
{
    operator void*() const;
};
struct Lst
{
};
struct Q
{
    void FUN_0077b2e0();
    void ClearGlobalList();
};
extern HUDMainMenu* g_pHudMainMenuInstance;
extern Q* DAT_011d96bc;
// Clears each tile in the HUD list via Set(0xfa3, 0), then, unless the menu state is 5, drains and deallocates queued items and calls ClearGlobalList.
// @fnv 0x0077f500
void ResetHudTiles(void* self)
{
    Tile* tile;
    void* pIter = (void*)(*(StrOp*)((char*)*(void**)&g_pHudMainMenuInstance->m_pTiles[14] + 4));
    tile = 0;
    while (pIter)
    {
        tile = (Tile*)*((void **)(reinterpret_cast<::ListStandIn *>((((Lst*)((char*)*(void**)&g_pHudMainMenuInstance->m_pTiles[14] + 4))))->FUN_0057cbe0((int **)&(pIter))));
        if (tile)
            reinterpret_cast<::Tile *>((tile))->Set(0xfa3, 0);
    }
    if (g_pHudMainMenuInstance->m_eHudMenuMode != 5)
    {
        while (reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead())
        {
            void* item = reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead();
            {
                void* pItemCopy = item;
                ::FUN_00401030(pItemCopy);
            }
            DAT_011d96bc->FUN_0077b2e0();
        }
        DAT_011d96bc->ClearGlobalList();
    }
}
}  // namespace fnv_0077f500

namespace fnv_00773050 {
struct Tile
{
    void Set(int, int);
};

extern HUDMainMenu* DAT_011d96c0;

// @fnv 0x00773050
void __cdecl ResetHUDMainMenu()
{
    Tile* ptile;
    HUDMainMenu* pmenu;

    ptile = reinterpret_cast<Tile*>(((::Menu *)(::FUN_00a09030(::FUN_00706f20()))));
    if (!ptile || !reinterpret_cast<::FUN_00a03c90_shell *>((ptile))->FUN_00a03c90())
        return;

    pmenu = reinterpret_cast<HUDMainMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((ptile))->FUN_00a03c90());
    pmenu->m_pTargetActor = 0;
    pmenu->m_uiHudValueSecondAfterActor = 0;
    pmenu->m_iHudValueFirstAfterUnsignedValues = -1;
    pmenu->m_iHudValueSecondAfterUnsignedValues = -1;
    pmenu->m_bHudAnimationActive = false;
    pmenu->m_pTiles[50]->Set(0xfa3, 0);
    pmenu->m_bSequenceActive = false;
    DAT_011d96c0->m_pTiles[44]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[45]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[46]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[47]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[48]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[49]->Set(0xfa3, 0);
    DAT_011a010c = 1;
    DAT_011d96c0->m_bQuestObjectiveUpdatesEnabled = true;
}
}  // namespace fnv_00773050

struct FUN_00525430_Class
{
    int mField0;
    int mField4;
    int mMode;
    bool FUN_00525430();
};

// @fnv 0x00525430
bool FUN_00525430_Class::FUN_00525430()
{
    return mMode != 0;
}

struct Flt
{
    operator unsigned int(void) const;
};

struct FUN_00772820
{
    unsigned int Get();
};

// @fnv 0x00772820
unsigned int FUN_00772820::Get()
{
    return *reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xcc);
}

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& pt) const;
public:
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

// Computes the angle from aStart to aDest using the direction vector, wraps it, and scales it by DAT_0102f248.
// @fnv 0x00772840
float __cdecl GetAngleBetweenPoints(const NiPoint3& aStart, const NiPoint3& aDest)
{
    float fretangle = 0.0f;
    NiPoint3 direction = aDest - aStart;
    if (direction.y != ::_DAT_01012060)
    {
        float ftan = direction.x / direction.y;
        fretangle = ::FUN_004b1460(ftan);
        if (direction.y < ::_DAT_01012060)
            fretangle += (double)3.1415927f;
    }
    else if (direction.x < ::_DAT_01012060)
    {
        fretangle = 3.1415927f;
    }
    fretangle = WrapAngle(fretangle);
    return fretangle * DAT_0102f248;
}

namespace fnv_00772c30 {
class Tile
{
  public:
    void Set(int trait, int value);
    void Set(int trait, const char* value, bool propagate);
};
extern HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x00772c30
void __cdecl SetHoldText(const char* pText)
{
    static int iHoldTrait = ::FUN_00a01860("_Hold");
    if (pText && reinterpret_cast<::TileListBoxCalls *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[16])))->GetFloat(4009) == ::_DAT_01012060 &&
        reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[16])))->FUN_00a07fc0(4009))
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[15])))->FUN_00a01350(4036, (char *)(pText), true);
        reinterpret_cast<::Tile *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[15])))->Set(::FUN_00a01860("_Hold"), 1);
    }
}
}  // namespace fnv_00772c30

static HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x007732b0
int __cdecl GetHUDMainMenuValue()
{
    if (!g_pHudMainMenuInstance)
        return 0;
    return *(int*)((char*)g_pHudMainMenuInstance + 0x21c);
}

struct FUN_007735b0_class
{
    unsigned char GetByteAt5F8();
};

// @fnv 0x007735b0
unsigned char FUN_007735b0_class::GetByteAt5F8()
{
    return *(unsigned char*)((char*)this + 0x5f8);
}

class SoundPlaybackHandle
{
  public:
    unsigned int uiSoundID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& rhs);
    ~SoundPlaybackHandle();
    bool IsValid();
    bool StopWithFade(unsigned int uiMilliseconds);
public:
    bool IsValid() const;
};
class BSAudio
{
  public:
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* pEditorID, unsigned int uiFlags);
};
struct HUDMainMenuS
{
    void FUN_007737c0(float afDrinkinRads, float afStandinRads);
};
extern HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x007738c0
void __cdecl UpdateRadiationHUD(float afDrinkinRads, float afStandinRads)
{
    float ftotalRads = afDrinkinRads + afStandinRads;
    if (g_pHudMainMenuInstance)
    {
        if (ftotalRads > ::_DAT_01012060)
        {
            if (!((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))->IsValid() && afStandinRads > ::_DAT_01012060)
            {
                *(SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac) =
                    ::FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyRadiationTestLP", 0x11);
                reinterpret_cast<::FUN_00ad8830_shell *>((((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))))->FUN_00ad8830(false);
            }
            ((HUDMainMenuS*)g_pHudMainMenuInstance)->FUN_007737c0(afDrinkinRads, afStandinRads);
        }
        else if (((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))->IsValid())
        {
            ((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))->StopWithFade(500);
        }
    }
}

namespace fnv_00773e90 {
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_00773e90_shell : public HUDMainMenu
{
    void FUN_00773e90(Tile*, float, bool);
};

struct Tile
{
    void Set(int trait, int value);
    void Set(int trait, float value, bool propagate);
};
struct Setting_S
{
};
struct AnimIdle
{
};
extern bool DAT_011d9afc;
extern unsigned int DAT_011d9b00;
extern float DAT_011d9b04;
void __cdecl FUN_005330e0(float& value, float fMin, float fScaledValue);

// Sets the tile's trait 4084 and alpha 4009 from afCurrValue thresholds, and when bResetValues advances DAT_011d9b04 by a fade step clamped to 128..255.
// @fnv 0x00773e90
void FUN_00773e90_shell::FUN_00773e90(Tile* apTile, float afCurrValue, bool bResetValues)
{
    float fAlphaFadeSpeed = 0.5f;
    if (afCurrValue >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00773e90::Setting_S *>(&::originalRuntimeFloatSetting808)))))))
    {
        reinterpret_cast<::Tile *>((apTile))->Set(4084, 2);
        reinterpret_cast<::FUN_00a012d0_t *>((apTile))->FUN_00a012d0(4009, DAT_011d9b04, true);
    }
    else if (afCurrValue >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00773e90::Setting_S *>(&::originalRuntimeFloatSetting809)))))))
    {
        reinterpret_cast<::Tile *>((apTile))->Set(4084, 2);
        reinterpret_cast<::Tile *>((apTile))->Set(4009, 255);
    }
    else if (afCurrValue >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00773e90::Setting_S *>(&::originalRuntimeFloatSetting810)))))))
    {
        reinterpret_cast<::Tile *>((apTile))->Set(4084, 1);
        reinterpret_cast<::Tile *>((apTile))->Set(4009, 255);
    }
    else if (afCurrValue >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00773e90::Setting_S *>(&::originalRuntimeFloatSetting811)))))))
    {
        reinterpret_cast<::Tile *>((apTile))->Set(4084, 1);
        reinterpret_cast<::Tile *>((apTile))->Set(4009, 124);
    }
    else
    {
        reinterpret_cast<::Tile *>((apTile))->Set(4084, 1);
        reinterpret_cast<::Tile *>((apTile))->Set(4009, 0);
    }
    if (bResetValues)
    {
        unsigned int iLastHardcoreFadeTimeLocal = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_00773e90::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00()));
        unsigned int iCurrTimeDiff = iLastHardcoreFadeTimeLocal - DAT_011d9b00;
        DAT_011d9b00 = iLastHardcoreFadeTimeLocal;
        if (DAT_011d9afc)
            DAT_011d9b04 -= iCurrTimeDiff * fAlphaFadeSpeed;
        else
            DAT_011d9b04 += iCurrTimeDiff * fAlphaFadeSpeed;
        if (DAT_011d9b04 >= 255.0)
            DAT_011d9afc = true;
        if (DAT_011d9b04 <= 128.0)
            DAT_011d9afc = false;
        FUN_005330e0(DAT_011d9b04, 128.0f, 255.0f);
    }
}
}  // namespace fnv_00773e90


struct FUN_00775210_cls
{
    FUN_00775210_cls* FUN_00775210();
};

// @fnv 0x00775210
FUN_00775210_cls* FUN_00775210_cls::FUN_00775210()
{
    new ((void *)((void*)((char*)this + 0x10c))) ::Vec3();
    return this;
}

namespace fnv_00778990 {
class Tile
{
  public:
    void Set(int trait, const char* value, bool propagate);
};
struct Actor
{
};
struct PC7d : Actor
{
};
struct StartMenu
{
    const char* GetMenuTitle();
};
extern HUDMainMenu* g_pHudMainMenuInstance;

// Computes radiation magnitude from the player's resistance and perk modifiers, formats it, and sets the info label and value tiles.
// @fnv 0x00778990
void __cdecl UpdateRadiationInfo(int aiRadiationAmount, int aiInfoLabel, int aiInfoValue)
{
    char str[260];
    float fmodifiedMagnitude;
    float fresistance = reinterpret_cast<::fnv_008c4330::FUN_008c4330_cls *>(((*reinterpret_cast<::fnv_00778990::PC7d * *>(&::_g_thePlayer))))->FUN_008c4330();
    float feffectivenessMult = 1.0f;
    ::ApplyPerkModifiers(0x1a, (::Actor *)((*reinterpret_cast<::fnv_00778990::PC7d * *>(&::_g_thePlayer))), &feffectivenessMult);
    fresistance *= feffectivenessMult;
    fmodifiedMagnitude = aiRadiationAmount * fresistance;
    ::std::sprintf(str, "%i",
             (fmodifiedMagnitude > ::_DAT_01012060 && fmodifiedMagnitude < 1.0) ? 1 : (int)fmodifiedMagnitude);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((g_pHudMainMenuInstance->m_pTiles[aiInfoLabel]))->FUN_00a01350(4036, (char *)(str), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((g_pHudMainMenuInstance->m_pTiles[aiInfoValue]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00778990::StartMenu *>(&::g_011d30c0))))->GetMenuTitle()))), true);
}
}  // namespace fnv_00778990

struct GlobalObject2_0040c150
{
};
class TESActorBase;
struct Actor
{
public:
    ::TESActorBase *GetActorBase();
public:
    bool IsSneaking();
};
struct PC7d : Actor
{
};
class ActorValueOwner
{
  public:
    virtual int GetBaseActorValueInt(int eAV);
    virtual float GetBaseActorValue(int eAV);
    virtual int GetActorValueInt(int eAV);
    virtual float GetActorValue(int eAV);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
struct LevelUpEntry
{
    int iLevel;
    int iXP;
    int iParam;
};
struct G2
{
    void AddHead(LevelUpEntry*& item);
};

// If the player's level is below the threshold and the HUD flag is unset, allocates a LevelUpEntry with the level, XP and param and adds it to the HUD list.
// @fnv 0x0077c440
void QueueLevelUpNotification(int param)
{
    int level = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))))->FUN_0087f9f0();
    if (level < *((int *)&(::FUN_0043d4d0((int *)&(::g_011d0c60)))) && !g_pHudMainMenuInstance->m_bSequenceActive)
    {
        LevelUpEntry* entry = new LevelUpEntry;
        entry->iParam = param;
        entry->iLevel = level;
        entry->iXP = (int)((ActorValueOwner*)((char*)(*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)) + 0xa4))->GetActorValue(0x18);
        ((G2*)&g_pHudMainMenuInstance->m_kXPUpdates[0])->AddHead(entry);
    }
}

namespace fnv_0077da30 {
static HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x0077da30
void __cdecl FUN_0077da30()
{
    if (g_pHudMainMenuInstance)
        g_pHudMainMenuInstance->m_bSequenceActive = 0;
    ::fnv_00773050::DAT_011a010c = 1;
}
}  // namespace fnv_0077da30

struct TESSound
{
    bool FUN_0077eac0();
};

struct DataHandler
{
};


// @fnv 0x0077eac0
bool TESSound::FUN_0077eac0()
{
    return !reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())));
}

namespace fnv_0077f5e0 {
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_0077f5e0_shell : public HUDMainMenu
{
    void ResetWaitTiles();
};

struct Tile
{
    void Set(int, int);
    void Set(int, float, bool);
};
template <class T> struct NiTListItem;
template <class T> struct NiTPointerList
{
    T& GetPrev(NiTListItem<T>*& rkPos);
};
struct TileReference
{
    Tile* pTile;
};
bool _ref_008256d0(void* pThis);
extern HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x0077f5e0
void FUN_0077f5e0_shell::ResetWaitTiles()
{
    void* xchildIter = reinterpret_cast<::Callees *>(((char*)g_pHudMainMenuInstance->m_pTiles[13] + 4))->FUN_00726070();
    Tile* ptile = 0;
    while (xchildIter)
    {
        ptile = ((NiTPointerList<Tile*>*)((char*)g_pHudMainMenuInstance->m_pTiles[13] + 4))->GetPrev((NiTListItem<Tile*>*&)xchildIter);
        if (ptile)
        {
            reinterpret_cast<::Tile *>((ptile))->Set(0xfa3, 0);
            reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xfa9, 0.0f, true);
            reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(::FUN_00a01860("_WaitComplete"), 0.0f, true);
            reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(::FUN_00a01860("_HoldTime"), 0.0f, true);
        }
    }
    if (g_pHudMainMenuInstance->m_eHudMenuMode != 5)
    {
        void* pCurrentElementNext = &g_pHudMainMenuInstance->m_kQuestObjectives;
        while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
        {
            delete (TileReference*)*((void **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
            pCurrentElementNext = reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070();
        }
        reinterpret_cast<::FileMatchList *>((&g_pHudMainMenuInstance->m_kQuestObjectives))->RemoveAll();
    }
}
}  // namespace fnv_0077f5e0

namespace fnv_0077f890 {
class Tile
{
  public:
    void Set(int trait, float value, bool propagate);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
struct HUDMainMenuS
{
    void ShiftTileValues(int aishift);
};

// Adds aishift to trait 4001 of four Tile objects at offsets 0x50, 0x54, 0x4c and 0x180 and sets the results with propagation.
// @fnv 0x0077f890
void HUDMainMenuS::ShiftTileValues(int aishift)
{
    reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)((char*)this + 0x50))))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[10])))->GetFloat(4001) + aishift, true);
    reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)((char*)this + 0x54))))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[11])))->GetFloat(4001) + aishift, true);
    reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)((char*)this + 0x4c))))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[9])))->GetFloat(4001) + aishift, true);
    reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)((char*)this + 0x180))))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>(((*(Tile**)&g_pHudMainMenuInstance->m_pTiles[86])))->GetFloat(4001) + aishift, true);
}
}  // namespace fnv_0077f890

struct GameTimerRecord
{
    void Update();
    float GetSeconds();
    float GetUnmodifiedSeconds();
    unsigned int GetTime();
    unsigned int GetStartTime();
    void ClampAt(unsigned int);
    bool QEnabled();
    bool GetSecondsIsZero();
    static void SetGlobalTimeMultiplierCache();
    void RestoreGlobalTimeMultiplierCache();
    static float QGlobalTimeMultiplier();
    static float QGlobalTimeMultiplierTarget();
    static void UpdateGlobalTimeMultiplier();
    void SetUseGlobalTimeMultiplierTarget(bool);
    bool QUseGlobalTimeMultiplierTarget();
    float GetRealTimeSeconds();
    void Enable();
    void Disable();
    void Init(unsigned int);
    unsigned char m_ucFirstTimerByte;
    char _pad_1[3];
    float m_fFirstTimerValue;
    float m_fSecondTimerValue;
    float fTimeSinceScaleStart;
    float m_fFourthTimerValue;
    unsigned int m_uiFirstTimerValue;
    unsigned int m_uiSecondTimerValue;
    bool m_bFirstTimerFlag;
    bool m_bSecondTimerFlag;
    char _pad_1e[2];
};
struct FUN_00aa4ee0_shell : public GameTimerRecord
{
    void FUN_00aa4ee0();
};

struct FUN_00aa4ee0_t : public GameTimerRecord
{
    void FUN_00aa4ee0(unsigned int aiTime);
};

// @fnv 0x00aa4ee0
void FUN_00aa4ee0_t::FUN_00aa4ee0(unsigned int aiTime)
{
    unsigned int iscaleTime = aiTime - m_uiSecondTimerValue;
    if ((bool)(m_ucFirstTimerByte ? 0 : 1))
    {
        if (m_fFirstTimerValue != ::_DAT_01012060)
        {
            m_fSecondTimerValue += m_fFirstTimerValue;
            unsigned int iclampTicks = (unsigned int)m_fSecondTimerValue;
            m_fSecondTimerValue -= iclampTicks;
            iscaleTime = m_uiFirstTimerValue + iclampTicks;
            fTimeSinceScaleStart = m_fFirstTimerValue * (double)0.001f;
        }
        else
        {
            unsigned int uiDelta;
            if (!(uiDelta = iscaleTime - m_uiFirstTimerValue))
            {
                m_bSecondTimerFlag = true;
                uiDelta = 1;
            }
            else
            {
                m_bSecondTimerFlag = false;
                if (uiDelta > 166)
                    uiDelta = 166;
            }
            if (uiDelta < 10)
            {
                unsigned int uiSleep = 10 - uiDelta;
                Sleep(uiSleep);
                uiDelta = 10;
            }
            fTimeSinceScaleStart = uiDelta * (double)0.001f;
        }
        m_uiFirstTimerValue = iscaleTime;
        m_fFourthTimerValue = fTimeSinceScaleStart;
        fTimeSinceScaleStart *= DAT_011ac3a0;
    }
    else
    {
        fTimeSinceScaleStart = 0.0f;
    }
}

struct FUN_00770070_Class
{
    int m_kPointA[11];
    int m_kPointB[82];
    bool HasAllTiles();
};

// @fnv 0x00770070
bool FUN_00770070_Class::HasAllTiles()
{
    for (int i = 1; i < 86; ++i)
    {
        if (m_kPointB[i - 1] == 0)
            return false;
    }
    return true;
}

struct FUN_007737a0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    bool HasFlag(unsigned int mask);
};

// @fnv 0x007737a0
bool FUN_007737a0_Class::HasFlag(unsigned int mask)
{
    return (m_20 & mask) ? true : false;
}

extern int g_011d970c;

struct FUN_009ca410_shell_base
{
    void FUN_0063f7b0();
};

struct FUN_0077b2e0_shell : public FUN_009ca410_shell_base
{
    void FUN_0077b2e0();
};

// @fnv 0x0077b2e0
void FUN_0077b2e0_shell::FUN_0077b2e0()
{
    reinterpret_cast<FUN_009ca410_shell_base*>(&g_011d970c)->FUN_0063f7b0();
}

struct List_009e03e0
{
    void RemoveAll();
};
extern int g_011d970c;

struct FUN_0077f5c0_Class
{
    void ClearGlobalList();
};

// @fnv 0x0077f5c0
void FUN_0077f5c0_Class::ClearGlobalList()
{
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)&g_011d970c)))->RemoveAll();
}

void __cdecl FUN_0076be30();

struct FUN_0076be00_Class
{
    void FUN_0076be30();
    void* DestroyIfFlagged(unsigned int flags);
};

namespace fnv_007728f0 {
struct TileValues_007728f0
{
    enum TILE_FADE_CONTROL_TYPE
    {
        FADE_TYPE_0
    };
    void Set(int trait, int value);
    void Set(int trait, unsigned int value);
    void Set(int trait, const char* value, bool propagate);
};
struct Setting_S
{
};
extern Setting_S g_011d9774;
struct RegionDisplayInfo
{
    unsigned int uiRegionID;
    char m_kName[260];
    bool bShowOnce;
};
extern unsigned int DAT_011d9aec;
struct AnimIdle
{
};
extern HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x007728f0
void __cdecl ShowRegionData(const RegionDisplayInfo* aRegionData)
{
    if (!g_pHudMainMenuInstance)
        return;
    if (g_pHudMainMenuInstance && (!aRegionData->bShowOnce || aRegionData->uiRegionID != DAT_011d9aec))
    {
        if (aRegionData->bShowOnce)
            DAT_011d9aec = aRegionData->uiRegionID;
        bool bshowRegion =
            reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])))->GetFloat(4009) == ::_DAT_01012060 ||
            !::FUN_00408b20(aRegionData->m_kName,
                          reinterpret_cast<::FUN_00a011f0_shell *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])))->FUN_00a011f0(4036));
        if (aRegionData->m_kName[0] &&
            reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[16])))->GetFloat(4009) == ::_DAT_01012060 &&
            reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[16])))->FUN_00a07fc0(4009))
        {
            reinterpret_cast<::Tile *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])))->Set(::FUN_00a01860("_Hold"), 0);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])))->FUN_00a01350(4036, (char *)(aRegionData->m_kName), true);
            if (!bshowRegion)
            {
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])))->StartFade(4009, 0.0f, *((float *)&(::FUN_00403e20((float *)&(g_011d9774)))) * 255.0, 2.0f, (*(int *)&(const ::fnv_007728f0::TileValues_007728f0::TILE_FADE_CONTROL_TYPE &)(TileValues_007728f0::FADE_TYPE_0)));
                reinterpret_cast<::Tile *>((reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])))->Set(4100, (unsigned int)((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_007728f0::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00())));
            }
        }
    }
}
}  // namespace fnv_007728f0

namespace fnv_00778a90 {
extern "C" int __cdecl sprintf(char*, const char*, ...);
struct Tile
{
    void Set(int, const char*, bool);
};
struct StartMenu
{
    const char* GetMenuTitle();
};
struct GlobalObject_011d300c
{
    const char* GetMenuTitle();
};
extern Tile** _pme;
extern char $SG7674[];
// @fnv 0x00778a90
void __cdecl UpdateHealthInfoTiles(int aiHealth, int aiInfoLabel, int aiInfoValue)
{
    char str[260];
    sprintf(str, $SG7674, aiHealth);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Tile**)((char*)_pme + 0x28))[aiInfoLabel]))->FUN_00a01350(0xfc4, (char *)(str), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Tile**)((char*)_pme + 0x28))[aiInfoValue]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00778a90::GlobalObject_011d300c *>(&::g_011d300c))))->GetMenuTitle()))), true);
}
}  // namespace fnv_00778a90

namespace fnv_0077f420 {
struct Tile
{
    void Set(int, int);
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
extern Tile* _pme;

// Stores the global time at offset 0x24c and, if the flag at 0x1bc is set, calls Set(0xfa3, 1) on the tile at 0x170 or 0x154 depending on bFlag.
// @fnv 0x0077f420
void __cdecl FUN_0077f420(bool bFlag)
{
    *(unsigned int*)((char*)_pme + 0x24c) = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&((*reinterpret_cast<::fnv_0077f420::GameTimerRecord *>(&::g_timeGlobal))))->FUN_00825c00();
    if (*(unsigned int*)((char*)_pme + 0x1bc) & 1)
    {
        if (bFlag)
            reinterpret_cast<::Tile *>(((*(Tile**)((char*)_pme + 0x170))))->Set(0xfa3, 1);
        else
            reinterpret_cast<::Tile *>(((*(Tile**)((char*)_pme + 0x154))))->Set(0xfa3, 1);
    }
}
}  // namespace fnv_0077f420

namespace fnv_0077f490 {
struct Tile
{
    void Set(int, int);
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
extern char* _pme;

// Stores the current time at _pme+0x250 and, when bit 8 of _pme+0x1bc is set, calls Set(0xfa3, 1) on the tile at _pme+0x174 or _pme+0x158 depending on bFlag.
// @fnv 0x0077f490
void __cdecl UpdateTileOnFlag(bool abUseFirstTile)
{
    *(unsigned int*)(_pme + 0x250) = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&((*reinterpret_cast<::fnv_0077f490::GameTimerRecord *>(&::g_timeGlobal))))->FUN_00825c00();
    if (*(unsigned int*)(_pme + 0x1bc) & 8)
    {
        if (abUseFirstTile)
            reinterpret_cast<::Tile *>((((Tile*)(*(unsigned int*)(_pme + 0x174)))))->Set(0xfa3, 1);
        else
            reinterpret_cast<::Tile *>((((Tile*)(*(unsigned int*)(_pme + 0x158)))))->Set(0xfa3, 1);
    }
}
}  // namespace fnv_0077f490

struct GetModHelper_4bcf00
{
    unsigned char padding[0x1a0];
};

struct TESObjectWEAP : public GetModHelper_4bcf00
{
    unsigned char padding[4];
    float ammoRegenRate;
    float FUN_00709430(bool bModValue);
public:
    float GetWeightForForm(bool);
};

// @fnv 0x00709430
float TESObjectWEAP::FUN_00709430(bool bModValue)
{
    if (bModValue)
    {
        return reinterpret_cast<::FUN_004bcf60_shell *>(this)->GetEffectValue(6, 0) + ammoRegenRate;
    }
    else
    {
        return ammoRegenRate;
    }
}

struct MarkerVector
{
    float x, y, z;
    MarkerVector operator-(const MarkerVector& other) const;
};
struct TargetMarker
{
    int unk000;
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
    MarkerVector position;
    int priority;
};
struct MarkerArray
{
    unsigned int GetSize();
    TargetMarker*& GetAt(unsigned int index);
};
struct MarkerPlayer
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
    virtual const MarkerVector& GetPosition();
};
float __cdecl ForwardFloatAndInt(float base, int exponent);
struct HUDTargetSelector : HUDMainMenu
{
    TargetMarker* FindTargetMarker();
};
// @fnv 0x00775230
TargetMarker* HUDTargetSelector::FindTargetMarker()
{
    TargetMarker* selected3 = 0;
    float best3 = DAT_01016970;
    MarkerVector player = (*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer))->GetPosition();
    for (unsigned int index = 0; index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<MarkerArray*>(m_kSubtitleArray)))->GetName())); ++index)
    {
        float distance =
            reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::MarkerVector &)((reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index)->position - player)))->UpdateCombatStyle();
        if ((!selected3 && distance <= ForwardFloatAndInt(DAT_01013d84, 2)) ||
            (selected3 && distance < best3 &&
             reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index)->priority >= selected3->priority) ||
            reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index)->priority == 0x7fffffff)
        {
            selected3 = reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index);
            best3 = distance;
        }
    }
    return selected3;
}

struct PointX
{
    float x, y, z;
};

struct TileX
{

    void Set(int aeID, int aiValue);

    void Set(int aeID, const char* apValue, bool abPropagate);

    void Set(int aeID, float afValue, bool abPropagate);



    void Refresh(int aiArg);
};

struct SettingX
{


};

struct StringX
{

    char* pString;

    unsigned short usLen, usMax;

    StringX();

    StringX(const char* apString);

    ~StringX();

    StringX& operator=(const StringX& arString);

    unsigned int Length();

};

class TESForm
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

    virtual struct ModelListX* GetModelList();

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

    virtual struct PointX* GetPos();

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

    virtual bool IsCreature();

    virtual void v228();

    virtual bool IsDead(bool abArg);

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

    virtual bool IsInCombat(bool abArg);

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

    virtual float GetDistanceScale(int aiArg);

    int GetFormType();







public:
    bool GetDisabled() const;
};

class TESBoundObject : public TESForm
{
};

class TESObjectACTI : public TESBoundObject
{

  public:
    StringX GetActivateText();
};

struct FormTypeX
{
    int GetFormType();
};

struct AmmoX : public TESForm
{
    char _pad04[0x7c];
    FormTypeX kSub;
};

struct AIFormX
{

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();

    virtual bool IsEssential();
};

struct ActorBaseX : public TESForm
{
    char _pad04[0x2c];
    AIFormX kAI;
};

struct ModelListX
{
};

struct WeaponX : public TESForm
{
};

struct KeyX;

struct LockX
{

    int iLevel;

    KeyX* pKey;


};

struct DetectX
{
    int iLevel;
    bool bDetected;
};

struct ExtraListX;

struct ExtraListListX
{

    ExtraListX* pItem;

    ExtraListListX* pNext;

    ExtraListListX();

    void AddHead(ExtraListX* const& arItem);
};

struct EntryX
{

    ExtraListListX* pList;

    int iCount;

    TESForm* pType;

    EntryX(TESForm* apType, int aiCount);

    EntryX(const EntryX& arEntry);

    ~EntryX();


    float GetValue();

};

struct NameHolderX
{
};

struct ExtraNameX
{
    char _pad[0x18];
    StringX kName;
};

struct PerceivedX
{
    class RefX* pActor;
    bool bVisible;
};

struct PerceivedListX
{

    bool IsEmpty();


};

struct InputX
{
};

struct OSX
{
};

struct SoundX
{
};

struct FontX
{


    PointX GetSize(const char* apText, int aiFont, float afWidth, int aiArg);
};

class RefX : public TESForm
{

  public:



























    TESForm* GetLoadedForm();





};

struct ActivateDataX
{
    int a, b, c, d;
    ActivateDataX(unsigned char acFlags);
};

struct ExtraListX
{



};

struct HUDX
{

    char _pad00[0x28];

    TileX* m_pTiles[87];

    char _pad184[0x34];

    RefX* m_pCrosshairReference;

    char _pad1bc[0x60];

    RefX* m_pTargetActor;
};

extern HUDX* xpHUD;




extern bool xbFlagBA, xbFlagB9, xbFlagBB, xbFlagC5;

extern char xszName[0x104];

extern char xszLock[0x104];

extern char xszValue[8];

extern char xszWeight[8];




extern SettingX xsLockAlpha, xsActTake;




int __cdecl xGetHUDMode();









int __cdecl xGetOpenState(RefX* apRef);













int __cdecl xstrcat_s(char* apBuf, unsigned int auiSize, const char* apSrc);

static const char s_szConsoleButton[] = "_xbox_button";
static const char s_lit0[] = "[%s - %s]";
static const char s_lit1[] = "[";
static const char s_lit2[] = "]";
static const char s_lit3[] = "%s %s %s";
static const char s_lit4[] = "%s (%d)";
static const char s_lit5[] = "";
static const char s_lit6[] = "_line_alpha";
static const char s_lit7[] = ")";
static const char s_lit8[] = "_PCButtonText";
static const char s_lit9[] = "%.0f";
static const char s_lit10[] = "%.1f";
static const char s_lit11[] = "--";
static const char s_lit12[] = "button_text";
static const char s_lit13[] = "_y";
extern const char s_litEnd[] = "";

// Updates the HUD activate prompt for apRef: sets name, action, lock, weight/value and button text, and toggles the related tiles.
// @fnv 0x00775a00
bool UpdateActivatePrompt(RefX* apRef, int aiUnused, bool abForce)
{
    NameHolderX* qrUCJDN;
    int qBLsiu;
    RefX* qAXSCg;
    float qbfQdhM;
    float qXMUYT;
    TESForm* qpia;
    TESForm* qJDuOZ;
    int qxQHW;
    TESForm* qfTOqo;
    float qRZyE;
    RefX* qydrGv;
    bool qbdXUOW;
    bool qzYzlc;
    float qYvToq;
    bool qODE;
    float qkPflib;
    int qjThF;
    TESForm* qrBzVM;
    bool qZgNzZy;
    TESForm* qnEqwa;
    ModelListX* qyFp;
    bool qGTHx;
    int qYdAnhh;
    bool qxDeKK;
    TESForm* qidnYUK;
    bool qIpA;
    float qZWI;
    bool qQMZREG;
    TESForm* qAhbO;
    int qOPw;
    LockX* qYvz;
    int qYePyBl;
    RefX* qtOMjSX;
    RefX* qqtISP;
    bool qQGWBE;
    TESForm* qxWmVch;
    bool qArxcFu;
    if (!xpHUD || !(*reinterpret_cast<::RefX * *>(&::_g_thePlayer)))
        return false;
    if (apRef == (*reinterpret_cast<::RefX * *>(&::_g_thePlayer)))
        apRef = 0;
    if (!abForce && apRef == xpHUD->m_pCrosshairReference)
    {
        if (xbFlagBA && xbFlagB9)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 2);
        }
        else if (!apRef || (apRef->IsActor() && !reinterpret_cast<::FUN_008bc700_shell *>((apRef))->FUN_008bc700((::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))))
        {
            if (!apRef)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
                reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
            }
            xbFlagBB = false;
            if (xGetHUDMode() == 2)
                reinterpret_cast<::Tile *>((xpHUD->m_pTiles[62]))->Set(0xfa3, 1);
        }
        return false;
    }
    qydrGv = apRef;
    qGTHx = apRef ? apRef->IsActor() : false;
    qidnYUK = apRef ? ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())) : 0;
    qIpA = apRef ? ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetFormType() == 0x17 : false;
    if (apRef && apRef != xpHUD->m_pCrosshairReference)
    {
        if (qGTHx && reinterpret_cast<::Actor *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->IsSneaking())
        {
            if (!reinterpret_cast<::MiddleHighProcess *>((qydrGv))->IsActorInCombat())
            {
                reinterpret_cast<::fnv_00963eb0::PlayerView *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->SetEffectValue((void *)(0xc), 10.0f, (::fnv_00963eb0::EffectSource *)(0));
                reinterpret_cast<::FUN_009781a0_shell *>(&((*reinterpret_cast<::SoundX *>(&::g_011e0e80))))->FUN_009781a0();
            }
        }
        else if (!qGTHx)
        {
            LockX* pLockInner = ((::LockX *)(reinterpret_cast<::FUN_00569160_shell *>((apRef))->FUN_00569160()));
            if (qIpA)
            {
                if (!reinterpret_cast<::FUN_00501ae0_shell *>((qidnYUK))->FUN_00501ae0((::TESObjectREFR *)(apRef)) && reinterpret_cast<::OwnerLookupView *>((apRef))->FUN_00567790())
                {
                    reinterpret_cast<::fnv_00963eb0::PlayerView *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->SetEffectValue((void *)(0xb), 10.0f, (::fnv_00963eb0::EffectSource *)(0));
                    reinterpret_cast<::FUN_009781a0_shell *>(&((*reinterpret_cast<::SoundX *>(&::g_011e0e80))))->FUN_009781a0();
                }
            }
            else if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetFormType() == 0x1b && reinterpret_cast<::OwnerLookupView *>((apRef))->FUN_00567790())
            {
                int qSVM = reinterpret_cast<::fnv_00575590::Thing *>((apRef))->FUN_00575590(0, 1);
                if (qSVM > 0 && pLockInner && reinterpret_cast<::LockExtraData *>((pLockInner))->IsLocked())
                {
                    if (!pLockInner->pKey || reinterpret_cast<::CombatState *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->GetInventoryItemCount((::TESForm *)(pLockInner->pKey)) <= 0)
                    {
                        reinterpret_cast<::fnv_00963eb0::PlayerView *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->SetEffectValue((void *)(0xb), 10.0f, (::fnv_00963eb0::EffectSource *)(0));
                        reinterpret_cast<::FUN_009781a0_shell *>(&((*reinterpret_cast<::SoundX *>(&::g_011e0e80))))->FUN_009781a0();
                    }
                }
            }
            else if (pLockInner && reinterpret_cast<::LockExtraData *>((pLockInner))->IsLocked() && reinterpret_cast<::OwnerLookupView *>((apRef))->FUN_00567790())
            {
                if (!pLockInner->pKey || reinterpret_cast<::CombatState *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->GetInventoryItemCount((::TESForm *)(pLockInner->pKey)) <= 0)
                {
                    reinterpret_cast<::fnv_00963eb0::PlayerView *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->SetEffectValue((void *)(0xb), 10.0f, (::fnv_00963eb0::EffectSource *)(0));
                    reinterpret_cast<::FUN_009781a0_shell *>(&((*reinterpret_cast<::SoundX *>(&::g_011e0e80))))->FUN_009781a0();
                }
            }
        }
        else
        {
            reinterpret_cast<::B63E00Owner *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00963e00((void *)(0xc), 0);
            reinterpret_cast<::B63E00Owner *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00963e00((void *)(0xb), 0);
        }
    }
    else
    {
        reinterpret_cast<::B63E00Owner *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00963e00((void *)(0xc), 0);
        reinterpret_cast<::B63E00Owner *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00963e00((void *)(0xb), 0);
    }
    if (!apRef || !abForce)
        xpHUD->m_pCrosshairReference = apRef;
    if ((!abForce && !apRef) || !apRef || (reinterpret_cast<::FUN_00477ba0_shell *>((apRef))->FUN_00477ba0() && !qGTHx))
    {
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[32]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[34]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[35]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[36]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[37]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[38]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[39]))->Set(0xfa3, 0);
        if (!xbFlagBA)
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
        xbFlagBB = false;
        if (xGetHUDMode() == 2)
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[62]))->Set(0xfa3, 1);
        return true;
    }
    qYdAnhh = 0;
    qjThF = reinterpret_cast<::fnv_00579280::ReferenceView *>((apRef))->FUN_00579280();
    if ((apRef && qjThF == 5) || qjThF == 3)
    {
        int iResult = 0;
        ActivateDataX kData(0xff);
        if (!reinterpret_cast<::MarkerRef *>((apRef))->FUN_005686b0((*(const ::MarkerPoint *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))->GetPos())), 1, 1, (::MarkerOutput *)(::ActivateDataX *)(&kData), (unsigned int *)(int *)(&iResult), 1))
            return false;
    }
    qxWmVch = 0;
    qfTOqo = 0;
    qrBzVM = 0;
    qbdXUOW = qydrGv && ((::DetectX *)(reinterpret_cast<::FUN_00967090_t *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00967090((::Actor *)(qydrGv)))) && ((::DetectX *)(reinterpret_cast<::FUN_00967090_t *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00967090((::Actor *)(qydrGv))))->bDetected;
    if (qjThF || qbdXUOW)
    {
        if (reinterpret_cast<::xRefr *>((apRef))->FUN_00579690() && (!qGTHx || !reinterpret_cast<::MiddleHighProcess *>((apRef))->IsActorInCombat()))
        {
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 2);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1005)), true);
        }
        else if (qbdXUOW)
        {
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 2);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
        }
        else if (!qGTHx || !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((apRef))->FUN_00493bb0())))
        {
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1005)), true);
        }
        else
        {
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
        }
    }
    else
    {
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
    }
    qOPw = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetFormType();
    switch (qOPw)
    {
    case 0x20:
    case 0x21:
    case 0x25:
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[32]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[21]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[22]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[23]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[34]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[35]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[36]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[37]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[38]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[39]))->Set(0xfa3, 0);
        return true;
        break;
    case 0x33:
        if (((::EntryX *)(reinterpret_cast<::FUN_009d9f00_Class *>((apRef))->FUN_009d9f00())) && ((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>((((::EntryX *)(reinterpret_cast<::FUN_009d9f00_Class *>((apRef))->FUN_009d9f00()))))->GetName()))->GetFormType() != 0x1f)
            break;
        if (apRef->GetFormType() == 0x3d)
        {
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[32]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[21]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[22]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[23]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[34]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[35]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[36]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[37]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[38]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[39]))->Set(0xfa3, 0);
            return true;
            break;
        }
    case 0x1f:
    case 0x23:
    case 0x2f:
    case 0x67:
        qYdAnhh |= 0xfc;
        break;
    case 0x28:
        qxWmVch = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()));
        if (reinterpret_cast<::FUN_0047bcf0_class *>((qxWmVch))->IsFlag80Clear())
            qYdAnhh |= 0xfc;
        break;
    case 0x18:
        qfTOqo = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()));
        qYdAnhh |= 0xfc;
        break;
    case 0x29:
        qrBzVM = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()));
        if (((bool)(reinterpret_cast<::FUN_004c94d0_shell *>((void *)(qrBzVM))->GetFlag())))
            qYdAnhh |= 0xfc;
        break;
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1b:
    case 0x1c:
    case 0x27:
    case 0x2a:
    case 0x2b:
        break;
    case 0x1e:
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1004)), true);
        if (!reinterpret_cast<::FUN_0046f070_shell *>((((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))))->FUN_0046f070())
            return true;
        qYdAnhh |= 0xfc;
        break;
    default:
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
    }
    qrUCJDN = ((::NameHolderX *)(reinterpret_cast<::TESObjectREFR *>((apRef))->GetExtraRadioData()));
    qYvz = ((::LockX *)(reinterpret_cast<::FUN_00569160_shell *>((apRef))->FUN_00569160()));
    qpia = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()));
    qJDuOZ = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()));
    qxQHW = 0;
    qZgNzZy = false;
    if (qOPw != 0x1c && qOPw != 0x1b)
    {
        qZgNzZy = true;
    }
    else if (qOPw == 0x1c && ::TESObjectDOOR::ProcessDoorActivation((::TESObjectREFR *)(apRef), (::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))), 0, 1))
    {
        qZgNzZy = true;
    }
    else if (qOPw == 0x1b)
    {
        if (!qYvz || !reinterpret_cast<::LockExtraData *>((qYvz))->IsLocked() || (qYvz->pKey && reinterpret_cast<::ActorInventoryQueryViews::ActorQuery *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00891db0((::TESBoundObject *)(qYvz->pKey), 0, 1, 0, (*(int *)(&qxQHW)))))
            qZgNzZy = true;
    }
    qYePyBl = qIpA ? reinterpret_cast<::FUN_00501270_shell *>((qidnYUK))->FUN_005011a0((::TESObjectREFR *)(apRef)) : 0;
    qzYzlc = reinterpret_cast<::PlayerCharShell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->GetTerminalAccessResult((::TESObjectREFR *)(apRef)) == 2 || reinterpret_cast<::PlayerCharShell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->GetTerminalAccessResult((::TESObjectREFR *)(apRef)) == 3 || reinterpret_cast<::PlayerCharShell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->GetTerminalAccessResult((::TESObjectREFR *)(apRef)) == 4;
    if ((qIpA && qzYzlc) || reinterpret_cast<::FUN_0057b460_shell *>((apRef))->FUN_0057b460() || (qYvz && reinterpret_cast<::LockExtraData *>((qYvz))->IsLocked()))
    {
        int qpydTG = 0;
        if (qIpA)
            qpydTG = qYePyBl;
        else
            qpydTG = ::LockExtraData::ConvertLockLevel(reinterpret_cast<::fnv_005691b0::P01RefA *>((apRef))->FUN_005691b0());
        qpydTG = ::MinInt(::FUN_00647b70(qpydTG, 0), 5);
        int qOHwfb = qpydTG;
        int qQZbH;
        bool qpqRa = qYvz && qYvz->pKey && reinterpret_cast<::ActorInventoryQueryViews::ActorQuery *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00891db0((::TESBoundObject *)(qYvz->pKey), 0, 1, 0, (*(int *)(&qQZbH)));
        if (qYvz && reinterpret_cast<::LockExtraData *>((qYvz))->MeetsMinimumLockLevel())
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[33]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d2f28))))->GetMenuTitle()))), true);
            reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[33]))->FUN_00a012d0(0xfa9, *((float *)&(::FUN_00403e20((float *)&(xsLockAlpha)))) * 255.0, true);
        }
        else if (reinterpret_cast<::FUN_0057b460_shell *>((apRef))->FUN_0057b460())
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[33]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d44d4))))->GetMenuTitle()))), true);
            reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[33]))->FUN_00a012d0(0xfa9, *((float *)&(::FUN_00403e20((float *)&(xsLockAlpha)))) * 255.0, true);
        }
        else if (((qOPw == 0x1c || qOPw == 0x1b) && (!qZgNzZy || qpqRa)) || qOPw == 0x17)
        {
            if (qpqRa)
            {
                ::FUN_00406d00(xszLock, 0x104, s_lit0, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d2454))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d3be0))))->GetMenuTitle())));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[33]))->FUN_00a01350(0xfc4, (char *)(xszLock), true);
            }
            else if (qOHwfb == 5)
            {
                ::TaskQueueInterface::CopyStringToBuffer(xszLock, 0x104, s_lit1);
                xstrcat_s(xszLock, 0x104, ((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_01184a98))[qOHwfb]))->GetMenuTitle())));
                xstrcat_s(xszLock, 0x104, s_lit2);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[33]))->FUN_00a01350(0xfc4, (char *)(xszLock), true);
            }
            else
            {
                ::FUN_00406d00(xszLock, 0x104, s_lit0, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d2454))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_01184a98))[qOHwfb]))->GetMenuTitle())));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[33]))->FUN_00a01350(0xfc4, (char *)(xszLock), true);
            }
            reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[33]))->FUN_00a012d0(0xfa9, *((float *)&(::FUN_00403e20((float *)&(xsLockAlpha)))) * 255.0, true);
        }
        else
        {
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xfa9, 0);
        }
    }
    else
    {
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xfa9, 0);
    }
    qArxcFu = false;
    qtOMjSX = ((::RefX *)(reinterpret_cast<::FUN_0041e310_shell *>((((::ExtraListX *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(apRef))->FUN_005d43c0()))))->FUN_0041e310()));
    if (qtOMjSX && ((void *)(reinterpret_cast<::s55d310::Owner *>((qtOMjSX))->FUN_0055d310())) && reinterpret_cast<::fnv_00575590::Thing *>((qtOMjSX))->FUN_00575590(0, 0) <= 0)
        qArxcFu = true;
    qAXSCg = ((::RefX *)(reinterpret_cast<::FUN_0041df00_shell *>((((::ExtraListX *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(apRef))->FUN_005d43c0()))))->FUN_0041df00()));
    if (!qAXSCg && ((((void *)(reinterpret_cast<::s55d310::Owner *>((apRef))->FUN_0055d310())) && reinterpret_cast<::fnv_00575590::Thing *>((apRef))->FUN_00575590(0, 0) <= 0) || qArxcFu) &&
        (!qGTHx || apRef->IsDead(true)))
    {
        reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[34]))->FUN_00a012d0(0xfa9, *((float *)&(::FUN_00403e20((float *)&(xsLockAlpha)))) * 255.0, true);
    }
    else
    {
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[34]))->Set(0xfa9, 0);
    }
    qYvToq = (*reinterpret_cast<::RefX * *>(&::_g_thePlayer))->GetDistanceScale(0) * 57.2957763671875;
    qZWI = 0.0f;
    if (xpHUD->m_pTargetActor)
        qZWI = ::GetAngleBetweenPoints((const ::NiPoint3 &)(*(*reinterpret_cast<::RefX * *>(&::_g_thePlayer))->GetPos()), (const ::NiPoint3 &)(*xpHUD->m_pTargetActor->GetPos()));
    qQMZREG = xpHUD->m_pTargetActor && !xpHUD->m_pTargetActor->IsDead(false) && !reinterpret_cast<::FUN_00477ba0_shell *>((xpHUD->m_pTargetActor))->FUN_00477ba0() &&
              xbFlagC5 && xpHUD->m_pTargetActor == qydrGv;
    if (apRef)
    {
        RefX* pCreature = apRef->IsCreature() ? apRef : 0;
        if (pCreature && ((::EntryX *)(reinterpret_cast<::FUN_009d9f00_Class *>((pCreature))->FUN_009d9f00())))
        {
            ::TaskQueueInterface::CopyStringToBuffer(xszName, 0x104, ::FUN_00482720(((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>((((::EntryX *)(reinterpret_cast<::FUN_009d9f00_Class *>((pCreature))->FUN_009d9f00()))))->GetName()))));
        }
        else if (pCreature && ((::TESForm *)(reinterpret_cast<::FUN_00476c90_Class *>((pCreature))->FUN_00476c90())))
        {
            TESForm* pWeapon = ((::TESForm *)(reinterpret_cast<::FUN_00476c90_Class *>((pCreature))->FUN_00476c90()));
            if (((::TESForm *)(reinterpret_cast<::Thing *>((pWeapon))->GetOrFallback(0))) && ((::TESForm *)(reinterpret_cast<::MagicProjectile *>((((::TESForm *)(reinterpret_cast<::Thing *>((pWeapon))->GetOrFallback(0)))))->FUN_004fd400())))
                pWeapon = ((::TESForm *)(reinterpret_cast<::MagicProjectile *>((((::TESForm *)(reinterpret_cast<::Thing *>((pWeapon))->GetOrFallback(0)))))->FUN_004fd400()));
            ::TaskQueueInterface::CopyStringToBuffer(xszName, 0x104, ::FUN_00482720(pWeapon));
        }
        else
        {
            ::TaskQueueInterface::CopyStringToBuffer(xszName, 0x104, reinterpret_cast<::FUN_0055d520_shell *>((apRef))->FUN_0055d520());
        }
    }
    else
    {
        xszName[0] = 0;
    }
    qQGWBE = ((int)(reinterpret_cast<::FUN_00953c20_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00953c20())) > 0;
    if (xszName[0])
    {
        if (qrUCJDN)
        {
            StringX qhQRuW;
            reinterpret_cast<::FUN_0043a2e0_host *>((qrUCJDN))->SetString((::BSStr *)&(qhQRuW));
            char qWHpEvQ[0x104];
            ::FUN_00406d00(qWHpEvQ, 0x104, s_lit3, xszName, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d3738))))->GetMenuTitle())), ((const char *)(::FUN_00559450((int *)&(qhQRuW)))));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[32]))->FUN_00a01350(0xfc4, (char *)(qWHpEvQ), true);
            qYdAnhh |= 4;
        }
        else if ((!qGTHx || !(qydrGv == xpHUD->m_pTargetActor || reinterpret_cast<::FUN_008bc700_shell *>((qydrGv))->FUN_008bc700((::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))) || !qQGWBE ||
                  qydrGv->IsDead(false)) &&
                 !qQMZREG)
        {
            bool bShow = true;
            if (reinterpret_cast<::FUN_00418770_shell *>((((::ExtraListX *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(apRef))->FUN_005d43c0()))))->FUN_00418770() == 1)
            {
                if (qGTHx)
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[32]))->FUN_00a01350(0xfc4, (char *)(xszName), true);
                }
                else if ((qrBzVM && ((bool)(reinterpret_cast<::FUN_004c94d0_shell *>((void *)(qrBzVM))->GetFlag()))) || (qxWmVch && reinterpret_cast<::FUN_0047bcf0_class *>((qxWmVch))->IsFlag80Clear()) || (!qxWmVch && !qrBzVM))
                {
                    if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetFormType() == 0x29 &&
                        ((AmmoX*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())))->kSub.GetFormType() > 1)
                    {
                        char szCount[0x104];
                        ::FUN_00406d00(szCount, 0x104, s_lit4, xszName, ::GetExtraDataShort((const ::TESObjectREFR *)(apRef)));
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[32]))->FUN_00a01350(0xfc4, (char *)(szCount), true);
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[32]))->FUN_00a01350(0xfc4, (char *)(xszName), true);
                    }
                }
                else
                {
                    bShow = false;
                }
            }
            else
            {
                char szCount[0x104];
                ::FUN_00406d00(szCount, 0x104, s_lit4, xszName, reinterpret_cast<::FUN_00418770_shell *>((((::ExtraListX *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(apRef))->FUN_005d43c0()))))->FUN_00418770());
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[32]))->FUN_00a01350(0xfc4, (char *)(szCount), true);
            }
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[21]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[22]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((xpHUD->m_pTiles[23]))->Set(0xfa3, 0);
            if (bShow)
                qYdAnhh |= 4;
        }
    }
    else
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[32]))->FUN_00a01350(0xfc4, (char *)(::DAT_01020770), true);
    }
    qBLsiu = reinterpret_cast<::fnv_00579280::ReferenceView *>((apRef))->FUN_00579280();
    qxDeKK = false;
    if (qGTHx)
    {
        PerceivedListX* pNode = ((::PerceivedListX *)(reinterpret_cast<::FUN_00595d10_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00595d10()));
        while (pNode && !pNode->IsEmpty())
        {
            PerceivedX* pData = ((::PerceivedX *)(new ((void *)(pNode)) ::Vec3()));
            if (pData->pActor == qydrGv && pData->bVisible)
            {
                qxDeKK = true;
                break;
            }
            pNode = ((::PerceivedListX *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
    }
    if (apRef && !qQMZREG)
    {
        if (!(qBLsiu == 7 && qGTHx && (qxDeKK || qydrGv == xpHUD->m_pTargetActor || reinterpret_cast<::FUN_008bc700_shell *>((qydrGv))->FUN_008bc700((::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))) &&
              (qydrGv->IsInCombat(false) || reinterpret_cast<::FUN_00894900_shell *>((qydrGv))->FUN_00894900() || qxDeKK)) &&
            !reinterpret_cast<::FUN_00477ba0_shell *>((apRef))->FUN_00477ba0())
        {
            ExtraNameX* pExtraName = ((::ExtraNameX *)(reinterpret_cast<::TESObjectREFR *>((apRef))->GetExtraData(0x53)));
            StringX kName(s_lit5);
            if (pExtraName)
                reinterpret_cast<::FUN_00501c10_cls *>((void *)&(const ::StringX &)(kName))->CallAndReturnSelf((int)&(pExtraName->kName));
            if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(kName))->FUN_004048e0())) == 0)
            {
                TESObjectACTI* pActi = dynamic_cast<TESObjectACTI*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())));
                if (pActi)
                    reinterpret_cast<::FUN_00501c10_cls *>((void *)&(const ::StringX &)(kName))->CallAndReturnSelf((int)&(const ::StringX &)(pActi->GetActivateText()));
            }
            if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(kName))->FUN_004048e0())) > 0)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(kName))))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[32]))->FUN_00a01350(0xfc4, (char *)(s_lit5), true);
                qYdAnhh |= 2;
            }
            else if (qBLsiu == 1 && reinterpret_cast<::xRefr *>((apRef))->FUN_00579690())
            {
                if (qGTHx && reinterpret_cast<::MiddleHighProcess *>((qydrGv))->IsActorInCombat())
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_011d5160))[7]))->GetMenuTitle()))), true);
                }
                else if (qOPw == 0x2a)
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d3708))))->GetMenuTitle()))), true);
                }
                else if (qOPw == 0x2b)
                {
                    if (((::ActorBaseX *)(reinterpret_cast<::Actor *>((qydrGv))->GetActorBase()))->kAI.IsEssential())
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d3708))))->GetMenuTitle()))), true);
                    else
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d4f48))))->GetMenuTitle()))), true);
                }
                else
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d4f48))))->GetMenuTitle()))), true);
                }
                qYdAnhh |= 2;
            }
            else if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())) == (*reinterpret_cast<::TESForm * *>(&::DAT_011ca27c)) || ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())) == (*reinterpret_cast<::TESForm * *>(&::DAT_011ca280)) ||
                     (qBLsiu == 2 && (qOPw == 0x2a || qOPw == 0x2b)))
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d38dc))))->GetMenuTitle()))), true);
                qYdAnhh |= 2;
            }
            else if (qBLsiu == 8 && qOPw == 0x1c && !reinterpret_cast<::FUN_0057b460_shell *>((apRef))->FUN_0057b460())
            {
                bool bOpen = xGetOpenState(apRef) == 1 || xGetOpenState(apRef) == 2;
                if (qYvz && reinterpret_cast<::LockExtraData *>((qYvz))->IsLocked() && !reinterpret_cast<::OwnershipReferenceView *>((apRef))->FUN_005785e0((::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))), true) && !qZgNzZy)
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d45a0))))->GetMenuTitle()))), true);
                }
                else
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(bOpen ? ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d22b0))))->GetMenuTitle())) : ((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_011d5160))[qBLsiu]))->GetMenuTitle()))), true);
                }
                qYdAnhh |= 2;
            }
            else if (qBLsiu == 4 && qOPw == 0x2b)
            {
                qYdAnhh &= ~3;
            }
            else if (qBLsiu == 6)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_011d5160))[1]))->GetMenuTitle()))), true);
                qYdAnhh |= 2;
            }
            else if (qBLsiu != 0 && qBLsiu < 0x14 && !reinterpret_cast<::FUN_0057b460_shell *>((apRef))->FUN_0057b460())
            {
                if (!(qBLsiu == 1 && qGTHx && reinterpret_cast<::Actor *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->IsSneaking() && reinterpret_cast<::FUN_0087f3d0_shell *>((qydrGv))->FUN_0087f3d0()))
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_011d5160))[qBLsiu]))->GetMenuTitle()))), true);
                    qYdAnhh |= 2;
                }
            }
            else if (apRef->IsCreature() && reinterpret_cast<::BGSProjectile *>((void *)(((::ActorBaseX *)(reinterpret_cast<::Actor *>((apRef))->GetActorBase()))))->GetExplosionProximity() != 0.0)
            {
                if (!reinterpret_cast<::FUN_00444d00_Class *>((apRef))->FUN_00444d00(0x200))
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d3588))))->GetMenuTitle()))), true);
                else
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_011d5160))[1]))->GetMenuTitle()))), true);
                qYdAnhh |= 2;
                reinterpret_cast<::Tile *>((xpHUD->m_pTiles[51]))->Set(0xff4, 1);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[51]))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[51]))->FUN_00a011f0(0x1005)), true);
            }
            reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[29]))->FUN_00a012d0(::FUN_00a01860(s_lit6), *((float *)&(::FUN_00403e20((float *)&(xsLockAlpha)))) * 255.0, true);
            if (!::FUN_004b71d0())
            {
                unsigned char cButton = reinterpret_cast<::FUN_00703be0_Class *>((((::InputX *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OSX * *>(&::g_osGlobals))))->FUN_00877720()))))->GetByteAt(5, 0);
                if (cButton < 0xeeu && (*reinterpret_cast<SettingX * (*)[]>(&::DAT_011d52f0))[cButton])
                {
                    char szButton[0x20];
                    ::TaskQueueInterface::CopyStringToBuffer(szButton, 0x20, ((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<SettingX * (*)[]>(&::DAT_011d52f0))[cButton]))->GetMenuTitle())));
                    xstrcat_s(szButton, 0x20, s_lit7);
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(::FUN_00a01860(s_lit8), (char *)(szButton), true);
                }
                else
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[29]))->FUN_00a01350(::FUN_00a01860(s_lit8), (char *)(s_lit5), true);
                }
            }
            else
            {
                unsigned char cPadButton = reinterpret_cast<::FUN_00703be0_Class *>((((::InputX *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OSX * *>(&::g_osGlobals))))->FUN_00877720()))))->GetByteAt(5, 3);
                switch (cPadButton)
                {
                case 0x10:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0xd);
                    break;
                case 0x11:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0xe);
                    break;
                case 0xf:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0xf);
                    break;
                case 0xe:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0x10);
                    break;
                case 8:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0x11);
                    break;
                case 9:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0x12);
                    break;
                case 0xa:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 9);
                    break;
                case 0xb:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0xa);
                    break;
                case 0xc:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0xb);
                    break;
                case 0xd:
                    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(::FUN_00a01860(s_szConsoleButton), 0xc);
                    break;
                }
            }
        }
    }
    qqtISP = apRef->IsCreature() ? apRef : 0;
    qODE = qqtISP && ((::EntryX *)(reinterpret_cast<::FUN_009d9f00_Class *>((qqtISP))->FUN_009d9f00()));
    qnEqwa = qqtISP ? ((::TESForm *)(reinterpret_cast<::FUN_00476c90_Class *>((qqtISP))->FUN_00476c90())) : 0;
    qAhbO = qnEqwa && ::FUN_004c0bf0((::TESObjectWEAP *)(qnEqwa)) ? qnEqwa : 0;
    EntryX qsSDDgz(qODE ? *((::EntryX *)(reinterpret_cast<::FUN_009d9f00_Class *>((qqtISP))->FUN_009d9f00())) : EntryX(qAhbO ? qAhbO : ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())), 0));
    if (!qsSDDgz.pList)
        qsSDDgz.pList = new ExtraListListX();
    qsSDDgz.pList->AddHead(((::ExtraListX *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(apRef))->FUN_005d43c0())));
    qyFp = 0;
    switch (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetFormType())
    {
    case 0x15:
        qyFp = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetModelList();
        break;
    case 0x23:
        qyFp = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetModelList();
        break;
    }
    if (qyFp)
    {
        int qSVM = ((int)(reinterpret_cast<::FUN_00778950_Class *>((qyFp))->GetField188()));
        int qOFvKuu = ::GetField18C((char *)(qyFp));
        int qmgeiw = 0;
        int qeJKl = 0x23;
        int qGfbX = 0x24;
        ::fnv_00778a90::UpdateHealthInfoTiles(qOFvKuu, qeJKl, qGfbX);
        qeJKl = qeJKl == 0x23 ? 0x25 : qeJKl;
        qGfbX = qGfbX == 0x24 ? 0x26 : qGfbX;
        qmgeiw++;
        ::fnv_00778990::UpdateRadiationInfo(qSVM, qeJKl, qGfbX);
        qeJKl = qeJKl == 0x23 ? 0x25 : qeJKl;
        qGfbX = qGfbX == 0x24 ? 0x26 : qGfbX;
        qmgeiw++;
        qYdAnhh |= 0xfc;
    }
    else
    {
        float fValue = reinterpret_cast<::ItemChangeValueShell *>(&(qsSDDgz))->FUN_004bd400();
        if (fValue > 0.0)
        {
            if (fValue >= 1.0)
                ::FUN_00406d00(xszValue, 8, s_lit9, fValue);
            else
                ::FUN_00406d00(xszValue, 8, s_lit10, fValue);
        }
        else
        {
            ::TaskQueueInterface::CopyStringToBuffer(xszValue, 8, s_lit11);
        }
        float fWeight = 0.0f;
        if (((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>(&(qsSDDgz))->GetName()))->GetFormType() == 0x28)
        {
            WeaponX* pType = (WeaponX*)((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>(&(qsSDDgz))->GetName()));
            fWeight = reinterpret_cast<::TESObjectWEAP *>((pType))->GetWeightForForm(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>(&(qsSDDgz))->HasEffect(4))));
            if (fWeight >= 10.0)
            {
                float fMult = 1.0f;
                ::ApplyPerkModifiers(0x49, (::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))), &fMult);
                fWeight = fWeight * fMult;
            }
        }
        else
        {
            fWeight = ::TESWeightForm::GetWeightForForm(((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>(&(qsSDDgz))->GetName())), ::FUN_004d1360((char *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer)))));
        }
        if (fWeight > 0.0)
            ::FUN_00406d00(xszWeight, 8, s_lit10, fWeight);
        else
            ::TaskQueueInterface::CopyStringToBuffer(xszWeight, 8, s_lit11);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[35]))->FUN_00a01350(0xfc4, (char *)(xszWeight), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[36]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d2aa8))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[37]))->FUN_00a01350(0xfc4, (char *)(xszValue), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((xpHUD->m_pTiles[38]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d26a0))))->GetMenuTitle()))), true);
    }
    static TileX* s_pButtonText = ((::TileX *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(xpHUD->m_pTiles[68]), s_lit12)));
    if ((reinterpret_cast<::xRefr *>((apRef))->FUN_00579690() && (!qGTHx || !reinterpret_cast<::MiddleHighProcess *>((apRef))->IsActorInCombat())) ||
        (qGTHx && (reinterpret_cast<::FUN_008bc700_shell *>((apRef))->FUN_008bc700((::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer)))) || qxDeKK)))
    {
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[30]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[31]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[32]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[34]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[35]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[36]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[37]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[38]))->Set(0xff4, 2);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[39]))->Set(0xff4, 2);
    }
    else
    {
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[30]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[31]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[32]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[34]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[35]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[36]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[37]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[38]))->Set(0xff4, 1);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[39]))->Set(0xff4, 1);
    }
    s_pButtonText->Refresh(8);
    qbfQdhM = reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[32]))->GetFloat(0x100c);
    PointX qrEZrs =
        ((::FontX *)(::FontManager::Instance()))->GetSize(reinterpret_cast<::FUN_00a011f0_shell *>((xpHUD->m_pTiles[32]))->FUN_00a011f0(0xfc4), (int)reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[32]))->GetFloat(0xfb9),
                                   reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[32]))->GetFloat(0xfba), 0);
    qRZyE = qrEZrs.y;
    qXMUYT = reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[29]))->GetFloat(0x1004);
    qkPflib = qXMUYT - (qRZyE - qbfQdhM);
    reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[29]))->FUN_00a012d0(::FUN_00a01860(s_lit13), qkPflib, true);
    reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[32]))->FUN_00a012d0(0xfa2, reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[29]))->GetFloat(0xfb0) + qkPflib, true);
    reinterpret_cast<::FUN_00a012d0_t *>((xpHUD->m_pTiles[69]))->FUN_00a012d0(
        0xfa2, reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[68]))->GetFloat(0xfa2) + qkPflib - reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[69]))->GetFloat(0xfb0) - 50.0, true);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[29]))->Set(0xfa3, qYdAnhh & 2);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[32]))->Set(0xfa3, (qYdAnhh & 4) > 0);
    if (qYdAnhh & 6)
    {
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[21]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[22]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((xpHUD->m_pTiles[23]))->Set(0xfa3, 0);
    }
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[33]))->Set(0xfa3, (qYdAnhh & 4) > 0);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[34]))->Set(0xfa3, (qYdAnhh & 4) > 0 && reinterpret_cast<::TileListBoxCalls *>((xpHUD->m_pTiles[33]))->GetFloat(0xfa9) == 0.0);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[35]))->Set(0xfa3, (qYdAnhh & 8) > 0);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[36]))->Set(0xfa3, (qYdAnhh & 0x10) > 0);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[37]))->Set(0xfa3, (qYdAnhh & 0x20) > 0);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[38]))->Set(0xfa3, (qYdAnhh & 0x40) > 0);
    reinterpret_cast<::Tile *>((xpHUD->m_pTiles[39]))->Set(0xfa3, (qYdAnhh & 0x80) > 0);
    return true;
}

struct CamRect
{
    float l, r, t, b;
    CamRect(float al, float ar, float at, float ab);
};
struct CamFrustum
{
    float l, r, t, b, n, f;
    bool ortho;
    CamFrustum(bool abOrtho);
};
struct CamPoint3
{
    float x, y, z;
    CamPoint3(float ax, float ay, float az);
};
struct CamUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    int unk08;
    CamUpdateData(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};
struct CamObj
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
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    CamObj();
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
};
struct FovSource
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
    virtual float GetFov();
};
struct FloatSetting
{
};

struct CamBuilder
{
    CamObj* FUN_0077ee50();
};

// Allocates a CamObj, sets its viewport, FOV-derived frustum, LOD adjust, look-at, scale and updates it, then returns it.
// @fnv 0x0077ee50
CamObj* CamBuilder::FUN_0077ee50()
{
    CamObj* pCamera = new CamObj;
    CamRect port2(0.0f, 1.0f, 1.0f, 0.0f);
    if (::DAT_011f9426)
    {
        port2 = (*reinterpret_cast<::CamRect *>(&::DAT_011ad840));
    }
    reinterpret_cast<::_Cam_00712e60 *>((pCamera))->FUN_00712e60((const ::_Rect16_00712e60 &)(port2));
    CamFrustum _frustum(false);
    _frustum.f = ((::FovSource *)(::FUN_0045c670()))->GetFov();
    _frustum.n = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_01203144))))));
    reinterpret_cast<::FUN_00507700_cls *>((pCamera))->FUN_00507700(_frustum.f / _frustum.n);
    float fAspect2 = (double)(::DAT_011f9426 ? ::DAT_011f9434 : FUN_004dc200()) / (double)((int)(::FUN_004dc1f0()));
    float fScale = 0.75f;
    float fAngle2 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_01203150)))))) * 0.01745329238474369 * 0.15000000596046448;
    _frustum.l = -FUN_0057dd70(fAngle2) * fScale;
    _frustum.r = FUN_0057dd70(fAngle2) * fScale;
    _frustum.b = -FUN_0057dd70(fAngle2) * fAspect2 * fScale;
    _frustum.t = FUN_0057dd70(fAngle2) * fAspect2 * fScale;
    _frustum.ortho = false;
    reinterpret_cast<::NiCamera *>((pCamera))->UpdateViewFrustum((const ::NiFrustum &)(_frustum));
    reinterpret_cast<::CamLook *>((pCamera))->SetLookAt((const ::CamPoint &)((const ::CamPoint3 &)(CamPoint3(0.0f, 0.0f, 1.0f))), (const ::CamPoint &)((const ::CamPoint3 &)(CamPoint3(0.0f, 0.0f, 1.0f))));
    reinterpret_cast<::FUN_00733fd0_shell *>((pCamera))->FUN_00733fd0(1.0f);
    CamUpdateData updateData3(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((pCamera))->FUN_00a59c60((int)&(updateData3));
    return pCamera;
}

struct FUN_0077f2f0_vt55
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
    virtual void v55(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

struct FUN_0077f2f0_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    unsigned int F48cee0();
};

struct FUN_0077f2f0_loc
{
    int m_00;
    int m_04;
    int m_08;
    void Init(float f, int a, int b);
};

struct FUN_0077f2f0_mgr
{
};

extern int DAT_011d96c0;
extern char DAT_011d9770;


// @fnv 0x0077f2f0
void FUN_0077f2f0(FUN_0077f2f0_obj* pObject)
{
    FUN_0077f2f0_vt55* vt;
    FUN_0077f2f0_loc loc;
    if (DAT_011d96c0 != 0)
    {
        if (((::FUN_0077f2f0_vt55 *)(::FUN_00559450((int *)(((FUN_0077f2f0_mgr*)&DAT_011d9770))))) != 0)
        {
            ::fnv_0077f270::FUN_0077f270();
            if (pObject != 0)
            {
                if (pObject->F48cee0() > 0)
                {
                    vt = ((::FUN_0077f2f0_vt55 *)(::FUN_00559450((int *)(((FUN_0077f2f0_mgr*)&DAT_011d9770)))));
                    vt->v55(((int)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((((FUN_0077f2f0_mgr*)(*reinterpret_cast<void * *>(&::g_modelLoader)))))->FUN_00447080({}, {}, {}, {}, {}, {}))), pObject->v5(), 0, 1, 0, 0, 0, 1);
                    reinterpret_cast<::TaskQueueInterface *>((((::FUN_0077f2f0_vt55 *)(::FUN_00559450((int *)(((FUN_0077f2f0_mgr*)&DAT_011d9770)))))))->QueueActorDisarm(1);
                    new ((void *)&(loc)) ::NiUpdateData(0.0f, 0, 0);
                    reinterpret_cast<::FUN_00a59c60_cls *>((((::FUN_0077f2f0_vt55 *)(::FUN_00559450((int *)(((FUN_0077f2f0_mgr*)&DAT_011d9770)))))))->FUN_00a59c60((int)(&loc));
                }
            }
        }
    }
}

struct NiNode_st;
struct GlobalObject_00633c90
{
    void* m_p;
    operator NiNode_st*() const;
    GlobalObject_00633c90& operator=(NiNode_st* p);
};
extern GlobalObject_00633c90 g_011d9770;
extern GlobalObject_00633c90 g_011d975c;
extern int g_011d96bc;

class ShadowSceneNode
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
    virtual void SetNode(NiNode_st* p);
};

struct OwnedObj
{
    virtual ~OwnedObj();
};
struct PmeAccess
{
};

struct MsgItem
{
    int unk00;
};
struct HudList
{
    MsgItem* m_item;
    HudList* m_pkNext;
    ~HudList();
    void RemoveHead();
};
struct HudSubtitles
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~HudSubtitles();
};
struct HudSound
{
    int unk00;
    int unk04;
    int unk08;
    ~HudSound();
};
struct HudWheel
{
    int unk00;
    ~HudWheel();
};

struct HudMenuBase
{
    virtual ~HudMenuBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct FUN_0076be30 : public HudMenuBase
{
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
    HudList m_kMessageList;
    int unk194;
    HudSubtitles m_kSubtitleArray;
    int unk1A8;
    HudSound m_kTargetDisplayData;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    HudWheel m_kMenuData;
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
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    HudList m_kQuestObjectives;
    int unk260;
    HudList m_kXPUpdates;
    HudList m_kRadiationUpdates;
    int unk274;
    virtual ~FUN_0076be30();
};
// Calls FUN_0076be30, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x0076be00
void* FUN_0076be00_Class::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0076be30 *>(this)->FUN_0076be30::~FUN_0076be30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Releases the owned HUD object, resets the node and HUD globals, deletes all queued message items, and clears HUDMainMenu_pme.
// @fnv 0x0076be30
FUN_0076be30::~FUN_0076be30()
{
    delete ((::OwnedObj *)(reinterpret_cast<::Callees *>((((PmeAccess*)HUDMainMenu_pme)))->FUN_00726070()));
    ::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)->SetNode(g_011d9770);
    g_011d9770 = 0;
    g_011d975c = 0;
    g_011d96bc = 0;
    while (((::MsgItem *)(new ((void *)&(m_kMessageList)) ::Vec3())))
    {
        MsgItem* pItem = ((::MsgItem *)(new ((void *)&(m_kMessageList)) ::Vec3()));
        delete pItem;
        m_kMessageList.RemoveHead();
    }
    HUDMainMenu_pme = 0;
}

struct ActorStand
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
    ActorValueOwner avOwner;
};
struct TESObjectREFR_GetFlags_Helper
{
};
class ActorPackageContext;
struct BaseProcess
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void vfunc53();
    virtual void vfunc54();
    virtual void vfunc55();
    virtual void vfunc56();
    virtual void vfunc57();
    virtual void vfunc58();
    virtual void vfunc59();
    virtual void vfunc60();
    virtual void vfunc61();
    virtual void vfunc62();
    virtual void vfunc63();
    virtual void vfunc64();
    virtual void vfunc65();
    virtual void vfunc66();
    virtual void vfunc67();
    virtual void vfunc68();
    virtual void vfunc69();
    virtual void vfunc70();
    virtual void vfunc71();
    virtual void vfunc72();
    virtual void vfunc73();
    virtual void vfunc74();
    virtual void vfunc75();
    virtual void vfunc76();
    virtual void vfunc77();
    virtual void vfunc78();
    virtual void vfunc79();
    virtual void vfunc80();
    virtual void vfunc81();
    virtual TESObjectREFR_GetFlags_Helper* GetRef();
public:
    ::ActorPackageContext *GetCurrentProcessData();
};
class SoundPlaybackHandle;
struct MobileObject
{
public:
    ::SoundPlaybackHandle PlaySoundByEditorName(const char *, bool, unsigned int, bool);
};
// Returns the actor's value 76 clamped to at least zero, adjusted by perk modifiers 58 and 56, or 0.0 if either argument is null.
// @fnv 0x007700f0
float __cdecl GetActorValueWithPerkModifiers(MobileObject* pMobileObject, Actor* pActor)
{
    if (pMobileObject == 0 || pActor == 0)
    {
        return 0.0f;
    }
    float baseValue = FUN_00404010(((ActorStand*)pActor)->avOwner.GetActorValue(76), 0.0f);
    BaseProcess* proc = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pMobileObject))->GetBaseTexture()));
    TESObjectREFR_GetFlags_Helper* target = proc->GetRef();
    unsigned int result;
    if (target != 0)
    {
        result = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((target))->GetName()));
    }
    else
    {
        result = DAT_011ca278;
    }
    unsigned int modFlags = result;
    float fPenalty = 0.0f;
    ::ApplyPerkModifiers(58, (Actor*)pMobileObject, modFlags, pActor, &fPenalty);
    float fAdd = 0.0f;
    ::ApplyPerkModifiers(56, pActor, (Actor*)pMobileObject, modFlags, &fAdd);
    baseValue = baseValue - fPenalty + fAdd;
    baseValue = FUN_00404010(0.0f, baseValue);
    return baseValue;
}

class GlobalObject_0040c150
{
  public:
    const char* FUN_00403df0();
};

struct HMValueOwner
{
    virtual int GetBaseActorValueInt(int eAV);
    virtual float GetBaseActorValue(int eAV);
    virtual int GetActorValueInt(int eAV);
};

struct HMTarget
{
};

struct HMTimer
{
};


struct FUN_007701e0_shell : public HUDMainMenu
{
    void UpdateTargetInfo(HMTarget* apTarget);
};

// @fnv 0x007701e0
void FUN_007701e0_shell::UpdateTargetInfo(HMTarget* apTarget)
{
    float fCurrentAmountNext;
    float fPlayerDist;
    float ratio;
    float fShowInfo;
    {
        char acBuffer[256];
        float maxHealth = (float)((HMValueOwner*)((char*)apTarget + 0xa4))->GetBaseActorValueInt(0x10);
        fCurrentAmountNext = (float)((HMValueOwner*)((char*)apTarget + 0xa4))->GetActorValueInt(0x10);
        fPlayerDist = ::GetActorValueWithPerkModifiers((::MobileObject *)(::_g_thePlayer), (::Actor *)(apTarget));
        ratio = 0.0f;
        if (maxHealth > 0.0)
        {
            ratio = fCurrentAmountNext / maxHealth;
        }
        static float fLastRatio = ratio;
        if (fLastRatio != ratio)
        {
            m_uiHudValueFirstAfterActor = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HMTimer*)m_cBuffer)))->FUN_00825c00();
            fLastRatio = ratio;
        }
        if (reinterpret_cast<::FUN_00477ba0_shell *>((apTarget))->FUN_00477ba0())
        {
            ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(m_pTiles[22]), 0.0f, 2, 0, 0);
        }
        else if (!((PlayerDummy*)apTarget)->v139(0))
        {
            ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(m_pTiles[22]), ratio, 2, 1, 0);
        }
        else
        {
            ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(m_pTiles[22]), ratio, 2, 0, 0);
        }
        fShowInfo = 0.0f;
        ::ApplyPerkModifiers(0x2f, (::Actor *)(::_g_thePlayer), &fShowInfo);
        if (fShowInfo > 0.0)
        {
            ::std::sprintf(acBuffer, "%s\n %s:%d %s:%.2f", reinterpret_cast<::FUN_0055d520_shell *>((apTarget))->FUN_0055d520(), ((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d50b0))->GetMenuTitle())), (int)fCurrentAmountNext,
                    ((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d396c))->GetMenuTitle())), fPlayerDist);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((HUDMainMenu_pme->m_pTiles[23]))->FUN_00a01350(0xfc4, (char *)(acBuffer), true);
        }
        else
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((HUDMainMenu_pme->m_pTiles[23]))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::FUN_0055d520_shell *>((apTarget))->FUN_0055d520()), true);
        }
    }
}

struct HUDTime
{
};
struct HUDFloatSetting
{
    float* FUN_00403e20();
};
struct HUDIntSetting
{
};
extern HUDFloatSetting DAT_011d9774;
struct HUDMode
{
};
struct HUDDetection
{
    int value;
    bool detected;
    bool ignored;
};
struct HUDDetectionList
{
    bool FUN_008256d0();
};
struct HUDActor : RefX
{
};
struct HUDTile : TileX
{
};
struct HUDSubtitle
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
    unsigned time;
    float duration;
};
struct HUDMessage
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
    float duration;
};
struct HUDSubtitleList
{
    HUDSubtitle** FUN_00877a30(unsigned);
};
struct HUDMessageList
{
    int FUN_005ae380();
};
float __cdecl FUN_00408840(float);
int __cdecl FUN_00458030();
extern bool DAT_011d96c5, DAT_011d97c0;
extern float DAT_011d979c;
extern const char DAT_01073474[];
extern const double DAT_01073480;
struct HUDUpdate : HUDMainMenu
{
    void FUN_00770430();
    void FUN_0077da60();
    void UpdateCompassMarkers();
    void UpdateQuestNotification();
    void UpdateRadMeter();
    void FUN_007756e0();
};
struct MarkerData772
{
};
struct MarkerRef772
{
};
struct MarkerEvent772
{
    MarkerRef772* reference;
    bool active;
    bool force;
};
extern MarkerRef772* DAT_011d9af0;
struct Setting772
{
    float* FUN_00403e20(float, bool);
};
extern Setting772 g_011d9774;
struct Tile772
{
};
// @fnv 0x00772aa0
void __cdecl UpdateMapMarkerHUD(MarkerEvent772* event)
{
    if (!HUDMainMenu_pme)
        return;
    if (event->active && event->reference != DAT_011d9af0)
    {
        DAT_011d9af0 = event->reference;
        if (event->reference && ((::MarkerData772 *)(reinterpret_cast<::FUN_00569060_shell *>((event->reference))->FUN_00569060())))
        {
            if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((Tile772*)HUDMainMenu_pme->m_pTiles[16])))->FUN_00a07fc0(0xfa9) &&
                reinterpret_cast<::TileListBoxCalls *>((((Tile772*)HUDMainMenu_pme->m_pTiles[16])))->GetFloat(0xfa9) == 0.0)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Tile772*)HUDMainMenu_pme->m_pTiles[16])))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::StringHolder *>((((::MarkerData772 *)(reinterpret_cast<::FUN_00569060_shell *>((event->reference))->FUN_00569060()))))->FUN_00438eb0()), true);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((Tile772*)HUDMainMenu_pme->m_pTiles[16])))->StartFade(0xfa9, 0.0f, (float)(*((float *)&(::FUN_00403e20((float *)&(g_011d9774)))) * 255.0), {}, {});
                reinterpret_cast<::Tile *>((((Tile772*)HUDMainMenu_pme->m_pTiles[16])))->Set(0x1004, ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00())));
            }
            reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((((Tile772*)HUDMainMenu_pme->m_pTiles[15])))->RemoveFadeItemsForTile(0xfa9);
            reinterpret_cast<::FUN_00a012d0_t *>((((Tile772*)HUDMainMenu_pme->m_pTiles[15])))->FUN_00a012d0(0xfa9, 0.0f, true);
        }
    }
    else if (!event->active && event->reference == DAT_011d9af0)
    {
        DAT_011d9af0 = 0;
    }
    else if (event->force)
    {
        DAT_011d9af0 = event->reference;
    }
}

class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
class GlobalObject_00709f00 : public GlobalObject_0045cf30
{
};
extern GlobalObject_00709f00 g_011d8a0c;
struct HealthActor : RefX
{
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
    ActorValueOwner actorValues;
};
struct FUN_00a01230_shell : Tile
{
    bool IsTraitNonZero(int trait);
};
struct FUN_00a07530_shell : Tile
{
    void FUN_00a07530(int flags);
};
struct TargetHealthTile : Tile
{
};
struct TargetHealthHUD : HUDMainMenu
{
};
extern bool DAT_011d96ba;
extern bool DAT_011d96b9;

// @fnv 0x00772d10
void __cdecl UpdateTargetHealthHUD(HealthActor* target, unsigned char enabled)
{
    bool isHostile = false;
    {
        bool isDead = true;
        if (target && HUDMainMenu_pme && !*g_011d8a0c.Bool() && enabled &&
            (!*g_011d898c.Bool() || !reinterpret_cast<::FUN_008bbc10_shell *>((((HealthActor*)::_g_thePlayer)))->FUN_008bbc10()))
        {
            HealthActor* actor;
            {
                TESBoundObject* baseObject = ((::TESBoundObject *)(reinterpret_cast<::fnv_00579280::ReferenceView *>((target))->FUN_00579280()));
                actor = target->IsActor() ? target : 0;
                isDead = actor && actor->IsDead(false);
                if (actor && ((((::DetectX *)(reinterpret_cast<::FUN_00967090_t *>((((HealthActor*)::_g_thePlayer)))->FUN_00967090((::Actor *)(actor)))) &&
                               ((::DetectX *)(reinterpret_cast<::FUN_00967090_t *>((((HealthActor*)::_g_thePlayer)))->FUN_00967090((::Actor *)(actor))))->bDetected) ||
                              reinterpret_cast<::FUN_008bc700_shell *>((actor))->FUN_008bc700((Actor*)::_g_thePlayer)))
                {
                    isHostile = true;
                }
                bool show = actor && !isDead && !actor->IsDead(false) &&
                            actor->actorValues.GetActorValueInt(16) < actor->actorValues.GetBaseActorValueInt(16) &&
                            !((FUN_00a01230_shell*)HUDMainMenu_pme->m_pTiles[32])->IsTraitNonZero(4003);
                if (show)
                {
                    ::fnv_00773190::FUN_00773190((::fnv_00773190::EnemyRefV *)(actor));
                    HUDMainMenu_pme->m_pTiles[21]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[22]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[23]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[23]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[62]->Set(4084, isHostile ? 2 : 1);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[21])->FUN_00a07530(8);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[22])->FUN_00a07530(8);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[23])->FUN_00a07530(8);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[23])->FUN_00a07530(8);
                    reinterpret_cast<::FUN_007701e0_shell *>((((TargetHealthHUD*)HUDMainMenu_pme)))->UpdateTargetInfo((::HMTarget *)(actor));
                }
            }
        }
        else if (reinterpret_cast<::TileListBoxCalls *>((((TargetHealthTile*)HUDMainMenu_pme->m_pTiles[62])))->GetFloat(4084) == 1.0)
        {
            HUDMainMenu_pme->m_pTiles[21]->Set(4003, 0);
            HUDMainMenu_pme->m_pTiles[22]->Set(4003, 0);
            HUDMainMenu_pme->m_pTiles[23]->Set(4003, 0);
        }
        DAT_011d96ba = !isDead && isHostile;
        DAT_011d96b9 = static_cast<int>(enabled);
    }
}

namespace fnv_00773190 {
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
struct EnemyListCount
{
};
extern HUDMainMenu* HUDMainMenu_pme;
struct EnemyActorV
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
    virtual bool IsHostile();
};
struct EnemyRefV
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
    virtual bool IsUnseen(int iArg);
};
struct EnemyTimer
{
};
// Selects the enemy reference to show in the HUD, sets its name text, and refreshes the timer and its value.
// @fnv 0x00773190
void FUN_00773190(EnemyRefV* pkRef)
{
    if (*(*reinterpret_cast<::fnv_00773190::GlobalObject_0045cf30 *>(&::g_011e0988)).Bool())
        return;
    if (pkRef && pkRef->IsUnseen(0))
        return;
    if (!HUDMainMenu_pme)
        return;
    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((EnemyListCount*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->GetName())) == 4)
        HUDMainMenu_pme->m_pTargetActor =
            (::DAT_011f21cc && ((EnemyActorV*)::DAT_011f21cc)->IsHostile()) ? ::DAT_011f21cc : 0;
    else
        HUDMainMenu_pme->m_pTargetActor = pkRef;
    if (HUDMainMenu_pme->m_pTargetActor)
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((HUDMainMenu_pme->m_pTiles[23]))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::FUN_0055d520_shell *>((((EnemyRefV*)HUDMainMenu_pme->m_pTargetActor)))->FUN_0055d520()), true);
        reinterpret_cast<::GameTimerRecord *>((((EnemyTimer*)HUDMainMenu_pme->m_cBuffer)))->Update();
        HUDMainMenu_pme->m_uiHudValueFirstAfterActor = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((EnemyTimer*)HUDMainMenu_pme->m_cBuffer)))->FUN_00825c00();
    }
}
}  // namespace fnv_00773190

struct RadiationTile
{
};
struct RandomGenerator
{
};
// @fnv 0x007737c0
void HUDMainMenuS::FUN_007737c0(float afDrinkinRads, float afStandinRads)
{
    float totalRads = afDrinkinRads + afStandinRads;
    if (afDrinkinRads > ::_DAT_01012060)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])))->FUN_00a012d0(0x100a, (float)((double)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::RandomGenerator *>(&::g_timeGlobal))))->FUN_00825c00() + ::DAT_01073490), 1);
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])))->FUN_00a012d0(0x1009, totalRads, 1);
        reinterpret_cast<::Tile *>((reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])))->Set(0x100b, 1);
    }
    else if (afStandinRads > ::_DAT_01012060)
    {
        if (((double)(reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])))->GetFloat(0x100a))) <=
            (double)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::RandomGenerator *>(&::g_timeGlobal))))->FUN_00825c00())
        {
            reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])))->FUN_00a012d0(0x1009, totalRads, 1);
        }
    }
}

struct HudTile
{
};

struct HudSetting
{
};

struct HudPlayerBase
{
    virtual void v0();
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
};

struct HudPlayer : public HudPlayerBase, public ActorValueOwner
{
};

struct HudMenuShell : public HUDMainMenu
{
    void UpdateCrippleMeters(bool abShow);
};

extern HUDMainMenu* g_pHUDMainMenu;

// @fnv 0x007739f0
void HudMenuShell::UpdateCrippleMeters(bool abShow)
{
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HudTile*)g_pHUDMainMenu->m_pTiles[85])))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::HudSetting *>(&::g_011d4d74))))->GetMenuTitle()))), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HudTile*)g_pHUDMainMenu->m_pTiles[84])))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::HudSetting *>(&::g_011d3e74))))->GetMenuTitle()))), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HudTile*)g_pHUDMainMenu->m_pTiles[79])))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::HudSetting *>(&::g_011d1f08))))->GetMenuTitle()))), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HudTile*)g_pHUDMainMenu->m_pTiles[81])))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::HudSetting *>(&::g_011d37c8))))->GetMenuTitle()))), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HudTile*)g_pHUDMainMenu->m_pTiles[80])))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::HudSetting *>(&::g_011d246c))))->GetMenuTitle()))), true);

    int iCrippled3 = 0;
    float fHead = ::CombatDamageCalculator::GetActorValueMultiplier((*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer)), (::ActorValue::Index)(0x1b), 0);
    if (fHead == ::_DAT_01012060)
        iCrippled3++;
    float fTorso5 = ::CombatDamageCalculator::GetActorValueMultiplier((*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer)), (::ActorValue::Index)(0x1d), 0);
    if (fTorso5 == ::_DAT_01012060)
        iCrippled3++;
    float fRightArm = ::CombatDamageCalculator::GetActorValueMultiplier((*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer)), (::ActorValue::Index)(0x1e), 0);
    if (fRightArm == ::_DAT_01012060)
        iCrippled3++;
    float fLeftArm = ::CombatDamageCalculator::GetActorValueMultiplier((*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer)), (::ActorValue::Index)(0x1c), 0);
    if (fLeftArm == ::_DAT_01012060)
        iCrippled3++;
    float fPerception = ::CombatDamageCalculator::GetActorValueMultiplier((*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer)), (::ActorValue::Index)(0x19), 0);
    if (fPerception == ::_DAT_01012060)
        iCrippled3++;
    float fEndurance8 = ::CombatDamageCalculator::GetActorValueMultiplier((*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer)), (::ActorValue::Index)(0x1a), 0);
    if (fEndurance8 == ::_DAT_01012060)
        iCrippled3++;

    float _fPenalty = 0.0f;
    if (iCrippled3 >= 4)
        _fPenalty = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::HudSetting *>(&::originalRuntimeFloatSetting808)))))) + ::g_01012070;
    else if (iCrippled3 >= 3)
        _fPenalty = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::HudSetting *>(&::originalRuntimeFloatSetting809)))))) + ::g_01012070;
    else if (iCrippled3 >= 2)
        _fPenalty = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::HudSetting *>(&::originalRuntimeFloatSetting810)))))) + ::g_01012070;
    else if (iCrippled3 >= 1)
        _fPenalty = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::HudSetting *>(&::originalRuntimeFloatSetting811)))))) + ::g_01012070;

    reinterpret_cast<::fnv_00773e90::FUN_00773e90_shell *>(this)->FUN_00773e90((::fnv_00773e90::Tile *)(g_pHUDMainMenu->m_pTiles[84]), (float)(*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer))->GetActorValueInt(0x36), false);
    reinterpret_cast<::fnv_00773e90::FUN_00773e90_shell *>(this)->FUN_00773e90((::fnv_00773e90::Tile *)(g_pHUDMainMenu->m_pTiles[85]), _fPenalty, !abShow);
    if (!abShow)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((((HudTile*)g_pHUDMainMenu->m_pTiles[79])))->FUN_00a012d0(4009, 0.0f, true);
        reinterpret_cast<::FUN_00a012d0_t *>((((HudTile*)g_pHUDMainMenu->m_pTiles[80])))->FUN_00a012d0(4009, 0.0f, true);
        reinterpret_cast<::FUN_00a012d0_t *>((((HudTile*)g_pHUDMainMenu->m_pTiles[81])))->FUN_00a012d0(4009, 0.0f, true);
    }
    else
    {
        reinterpret_cast<::fnv_00773e90::FUN_00773e90_shell *>(this)->FUN_00773e90((::fnv_00773e90::Tile *)(g_pHUDMainMenu->m_pTiles[79]), (float)(*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer))->GetActorValueInt(0x49), false);
        reinterpret_cast<::fnv_00773e90::FUN_00773e90_shell *>(this)->FUN_00773e90((::fnv_00773e90::Tile *)(g_pHUDMainMenu->m_pTiles[80]), (float)(*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer))->GetActorValueInt(0x4b), false);
        reinterpret_cast<::fnv_00773e90::FUN_00773e90_shell *>(this)->FUN_00773e90((::fnv_00773e90::Tile *)(g_pHUDMainMenu->m_pTiles[81]), (float)(*reinterpret_cast<::HudPlayer * *>(&::_g_thePlayer))->GetActorValueInt(0x4a), true);
    }
}

namespace fnv_00774090 {
struct RadTile
{
    void Set(int, int);
    void Set(int, const char*, bool);
};
struct RadTime
{
};
struct RadProcess
{
};
extern RadProcess DAT_011e0e80;
extern int DAT_011a0120;
extern float DAT_011d979c;
extern char DAT_011d9b08[260];
struct RadOwner
{
    virtual void v0();
    virtual void v1();
    virtual int GetValue(int);
};
struct RadPlayer
{
    int unk000;
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
    RadOwner owner;
};
struct RadHUD : HUDMainMenu
{
    void UpdateRadMeter();
};
// Updates the radiation meter HUD tiles: reads the player's rad level, animates the needle and angle tiles, and sets the +N rad text when low or recently changed.
// @fnv 0x00774090
void RadHUD::UpdateRadMeter()
{
    bool recent;
    bool low;
    float delta;
    delta = 0.0f;
    recent = reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->GetFloat(0x100a) > reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_00774090::RadTime *>(&::g_timeGlobal))))->FUN_00825c00();
    low = reinterpret_cast<::FUN_005098e0_Object *>(&((*reinterpret_cast<::fnv_00774090::RadProcess *>(&::g_011e0e80))))->IsFlagged();
    if (!low && !recent && DAT_011a0120 == 4)
        return;
    bool previousAngle = false;
    if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->FUN_00a07fc0(0xfa9) &&
        reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->GetFloat(0xfa9) == 0.0 &&
        reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->FUN_00a07fc0(0xfa9) &&
        reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->GetFloat(0xfa9) == 0.0 &&
        reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->FUN_00a07fc0(0xfa9) &&
        reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->GetFloat(0xfa9) == 0.0 &&
        reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[20])))->FUN_00a07fc0(0xfa9) &&
        reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[20])))->GetFloat(0xfa9) == 0.0)
        DAT_011a0120 = 4;
    if ((DAT_011a0120 == 4 || DAT_011a0120 == 2) && (low || recent))
    {
        DAT_011a0120 = 8;
        previousAngle = true;
    }
    float high = 15.0f;
    float unused = 315.0f;
    float active = 0.0f;
    float currentAngle;
    bool showing;
    {
        float change = 0.0f;
        currentAngle = 0.0f;
        showing = reinterpret_cast<::FUN_00a01230_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->IsTraitNonZero(0x100b) || recent;
        if (low || recent || previousAngle)
        {
            float value = (float)((RadPlayer*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))->owner.GetValue(54);
            bool updateText = false;
            if (low || previousAngle || showing)
            {
                updateText = true;
                change = reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->GetFloat(0x1009);
                active = ::LinearInterpolate(high, unused, 0.0f, 1000.0f,
                                           FUN_00404010(FUN_0040ebd0(value - change, 1000.0f), 0.0f));
            }
            if ((recent && previousAngle) || showing || low)
            {
                updateText = true;
                currentAngle =
                    ::LinearInterpolate(high, unused, 0.0f, 1000.0f, FUN_00404010(FUN_0040ebd0(value, 1000.0f), 0.0f));
            }
            if (updateText)
            {
                ::FUN_00406d00(DAT_011d9b08, 260, "+%i", ::FUN_00647b70(1, (int)change));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->FUN_00a01350(0xfc4, (char *)(DAT_011d9b08), true);
            }
        }
        if (previousAngle)
        {
            DAT_011a0120 = 8;
            reinterpret_cast<::FUN_00a012d0_t *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->FUN_00a012d0(0xfa1, FUN_0040ebd0(low ? currentAngle : active, unused), true);
            HUDMainMenu_pme->m_pTiles[61]->Set(0xfa3, 1);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->GetFloat(0xfa9), DAT_011d979c, 0.25f,
                            0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->GetFloat(0xfa9), DAT_011d979c, 0.25f,
                            0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->GetFloat(0xfa9), DAT_011d979c, 0.25f,
                            0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[20])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[20])))->GetFloat(0xfa9), DAT_011d979c, 0.25f,
                            0);
        }
        else if (low)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->FUN_00a012d0(0xfa1, FUN_0040ebd0(currentAngle, unused), true);
        }
        if (showing)
        {
            HUDMainMenu_pme->m_pTiles[19]->Set(0x100b, 0);
            reinterpret_cast<::FUN_00a012d0_t *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->FUN_00a012d0(0x1004, FUN_0040ebd0(currentAngle, unused), true);
            float duration = ::LinearInterpolate(1.5f, 3.0f, 0.0f, 50.0f, FUN_0040ebd0(50.0f, change));
            float start = reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->GetFloat(0xfa1);
            float finish = FUN_00404010(reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->GetFloat(0x1004), high);
            if (!low)
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->StartFade(0xfa1, start, finish, duration, 0);
        }
        if (!low && !recent)
        {
            DAT_011a0120 = 2;
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->GetFloat(0xfa9), 0.0f, 0.25f, 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[18])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->GetFloat(0xfa9), 0.0f, 0.25f, 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[19])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->GetFloat(0xfa9), 0.0f, 0.25f, 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((RadTile*)HUDMainMenu_pme->m_pTiles[20])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((RadTile*)HUDMainMenu_pme->m_pTiles[17])))->GetFloat(0xfa9), 0.0f, 0.25f, 0);
        }
    }
}
}  // namespace fnv_00774090

struct BarTile;
struct BarChildren
{
    BarTile** GetFirst();
};
struct BarTile
{
    int unk00;
    BarChildren children;
    float GetValue(int);
};

// Clamps current and target to 0..1, computes tile widths and x positions from traits, and sets width/x on both tiles, animating the right tile if needed.
// @fnv 0x00774b00
void UpdateBarWidths(BarTile* apLeftTile, BarTile* apRightTile, float current, float target, int alignment, int minimum)
{
    static int totalTrait = ::FUN_00a00940("_TotalWidth", -1);
    static int imageTrait = ::FUN_00a00940("_ImageWidth", -1);
    static int xTrait = ::FUN_00a00940("_OriginalX", -1);
    static int brightnessTrait = ::FUN_00a00940("_Brightness", -1);
    if (apLeftTile && apRightTile && HUDMainMenu_pme)
    {
        if (current > 1.0)
            current = 1.0f;
        else if (current < 0.0)
            current = 0.0f;
        if (target > 1.0)
            target = 1.0f;
        else if (target < 0.0)
            target = 0.0f;
        int total = (int)reinterpret_cast<::TileListBoxCalls *>((apLeftTile))->GetFloat(totalTrait);
        int image6 = (int)reinterpret_cast<::TileListBoxCalls *>((apLeftTile))->GetFloat(imageTrait);
        int width3;
        int targetWidthTmp;
        if (alignment == 2)
        {
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / (2 * image6)) * (2 * image6);
            targetWidthTmp = (int)(total * target / (2 * image6)) * (2 * image6);
        }
        else
        {
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / image6) * image6;
            targetWidthTmp = (int)(total * target / image6) * image6;
        }
        if (alignment == 2)
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / (2 * image6)) * (2 * image6);
        else
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / image6) * image6;
        int xpos6 = (int)reinterpret_cast<::TileListBoxCalls *>((apLeftTile))->GetFloat(xTrait);
        if (alignment == 1)
            xpos6 -= width3;
        else if (alignment == 2)
            xpos6 -= width3 / 2;
        int remainderTmp = targetWidthTmp;
        int otherX = (int)reinterpret_cast<::TileListBoxCalls *>((apRightTile))->GetFloat(xTrait);
        if (alignment == 1)
        {
            remainderTmp -= width3;
            otherX = xpos6 - remainderTmp;
            remainderTmp = MinInt(remainderTmp, (int)reinterpret_cast<::TileListBoxCalls *>((apRightTile))->GetFloat(xTrait) - otherX);
        }
        else if (alignment == 0)
        {
            otherX += width3;
        }
        else if (alignment == 2)
        {
            otherX -= targetWidthTmp / 2;
            remainderTmp = xpos6 - otherX;
            BarTile* child2 = *((::BarTile **)(reinterpret_cast<::FUN_0073ac90_shell *>(&(apRightTile->children))->FUN_0073ac90()));
            reinterpret_cast<::Tile *>((child2))->Set(0xfb1, remainderTmp);
            reinterpret_cast<::Tile *>((child2))->Set(0xfa1, xpos6 + width3);
            if (!reinterpret_cast<::FUN_00a07ed0_shell *>((child2))->FUN_00a07ed0(0xfa9))
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((child2))->StartFade(0xfa9, 0.0f, 255.0f, 1.0f, 1);
        }
        if (width3 == 0 && remainderTmp < image6 * minimum)
            remainderTmp = image6 * minimum;
        reinterpret_cast<::Tile *>((apLeftTile))->Set(0xfb1, width3);
        reinterpret_cast<::Tile *>((apLeftTile))->Set(0xfa1, xpos6);
        reinterpret_cast<::Tile *>((apRightTile))->Set(0xfb1, remainderTmp);
        reinterpret_cast<::Tile *>((apRightTile))->Set(0xfa1, otherX);
        if (!reinterpret_cast<::FUN_00a07ed0_shell *>((apRightTile))->FUN_00a07ed0(0xfa9))
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((apRightTile))->StartFade(0xfa9, 0.0f, 255.0f, 1.0f, 1);
    }
}

struct MessageEntry
{
    char text[260];
    char icon[260];
    char sound[260];
    float duration;
};
struct MessageList
{
    bool Empty();
    void Head(MessageEntry*&);
};
struct MessageTile
{
    void Set(int, const char*, bool);
};
struct MessageHUD
{
    int unk000;
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
    MessageList messages;
    bool AddMessage(const char*, unsigned int, const char*, const char*, float, bool);
};
struct SoundHandleMsg
{
    unsigned int id;
    bool success;
    unsigned int state;
    ~SoundHandleMsg();
};
struct AudioMsg
{
    SoundHandleMsg Get(const char*, unsigned int);
};
struct TilesMsg
{
    int unk000;
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
    MessageTile* icon;
    MessageTile* text;
};
extern TilesMsg* messageHUD;
// @fnv 0x00775380
bool MessageHUD::AddMessage(const char* text, unsigned int kind, const char* icon, const char* sound, float duration,
                            bool immediate)
{
    bool result = false;
    if (text)
    {
        MessageEntry* entry = new MessageEntry;
        ::TaskQueueInterface::CopyStringToBuffer(entry->text, 260, text);
        entry->duration = duration;
        if (icon && *icon)
            ::TaskQueueInterface::CopyStringToBuffer(entry->icon, 260, icon);
        else
        {
            switch (kind)
            {
            case 1:
                ::TaskQueueInterface::CopyStringToBuffer(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds");
                break;
            case 2:
                ::TaskQueueInterface::CopyStringToBuffer(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds");
                break;
            case 0:
                ::TaskQueueInterface::CopyStringToBuffer(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds");
                break;
            case 3:
                ::TaskQueueInterface::CopyStringToBuffer(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_in_pain.dds");
                break;
            }
        }
        if (sound)
            ::TaskQueueInterface::CopyStringToBuffer(entry->sound, 260, sound);
        else
            entry->sound[0] = 0;
        if (messages.Empty())
        {
            reinterpret_cast<::Callees *>(&(messages))->FUN_00905820((void *)&(entry));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((messageHUD->text))->FUN_00a01350(0xfc4, (char *)(((::MessageEntry *)(new ((void *)&(messages)) ::Vec3()))->text), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((messageHUD->icon))->FUN_00a01350(0xfcc, (char *)(((::MessageEntry *)(new ((void *)&(messages)) ::Vec3()))->icon), true);
            if (sound)
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundHandleMsg &)(((::AudioMsg *)(::FUN_00453a70()))->Get(sound, 0x121)))->FUN_00ad8830(false);
        }
        else
        {
            MessageList* tail = &messages;
            while (((::MessageList *)(reinterpret_cast<::Callees *>((tail))->FUN_00726070())))
                tail = ((::MessageList *)(reinterpret_cast<::Callees *>((tail))->FUN_00726070()));
            if (::FUN_00408b20(((::MessageEntry *)(new ((void *)(tail)) ::Vec3()))->text, entry->text))
            {
                if (immediate)
                {
                    ((::MessageEntry *)(new ((void *)&(messages)) ::Vec3()))->duration = 0.0f;
                    messages.Head(entry);
                }
                else
                    reinterpret_cast<::Callees *>(&(messages))->FUN_00905820((void *)&(entry));
            }
            else
                delete entry;
        }
        result = true;
    }
    return result;
}

namespace fnv_007756e0 {
class HUDMainMenu__MessageData
{
  public:
    char cMessage[0x104];
    char cIconPath[0x104];
    char cSoundPath[0x104];
    float fDisplayTime;
};

class TileStub
{
  public:
    void Set(int aiID, const char* apValue, bool abPropagate);
};

class PlayerCharacter
{
  public:
};

struct HUDTimerStub
{
    unsigned int GetTime();
};

extern HUDMainMenu* HUDMainMenu_pme;
extern PlayerCharacter* _g_thePlayer;
extern float g_fHUDMessageFadeTime;

struct HUDMainMenuMessages : public HUDMainMenu
{
    void FUN_007756e0();
};

typedef BSSimpleList<HUDMainMenu__MessageData*> MessageList;

// @fnv 0x007756e0
void HUDMainMenuMessages::FUN_007756e0()
{
    if (((MessageList*)m_kMessageList)->IsEmpty())
        return;
    MessageList* pIter = (MessageList*)m_kMessageList;
    while (pIter)
    {
        HUDMainMenu__MessageData* pMsg = ((::fnv_007756e0::HUDMainMenu__MessageData *)(new ((void *)(pIter)) ::Vec3()));
        if (pMsg && !::FUN_00408b20(pMsg->cMessage, reinterpret_cast<::FUN_00a011f0_shell *>((((TileStub*)HUDMainMenu_pme->m_pTiles[26])))->FUN_00a011f0(0xfc4)))
        {
            HUDMainMenu__MessageData* pOld = pMsg;
            reinterpret_cast<::ItemChangeListNode *>((((MessageList*)m_kMessageList)))->FUN_00905330((::InventoryStackRecord *const &)(pMsg));
            delete pOld;
            if (!((MessageList*)m_kMessageList)->IsEmpty())
            {
                if (((::fnv_007756e0::HUDMainMenu__MessageData *)(new ((void *)(((MessageList*)m_kMessageList))) ::Vec3()))->cSoundPath[0])
                {
                    reinterpret_cast<::MobileObject *>(((*reinterpret_cast<::fnv_007756e0::PlayerCharacter * *>(&::_g_thePlayer))))->PlaySoundByEditorName(((::fnv_007756e0::HUDMainMenu__MessageData *)(new ((void *)(((MessageList*)m_kMessageList))) ::Vec3()))->cSoundPath, 0, 0x121, 0);
                }
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TileStub*)HUDMainMenu_pme->m_pTiles[26])))->FUN_00a01350(0xfc4, (char *)(((::fnv_007756e0::HUDMainMenu__MessageData *)(new ((void *)(((MessageList*)m_kMessageList))) ::Vec3()))->cMessage), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TileStub*)HUDMainMenu_pme->m_pTiles[25])))->FUN_00a01350(0xfcc, (char *)(((::fnv_007756e0::HUDMainMenu__MessageData *)(new ((void *)(((MessageList*)m_kMessageList))) ::Vec3()))->cIconPath), true);
                m_uiMessageCount = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTimerStub*)m_cBuffer)))->FUN_00825c00();
            }
            else
            {
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((TileStub*)HUDMainMenu_pme->m_pTiles[26])))->StartFade(0xfa9, g_fHUDMessageFadeTime, 0.0f, ::g_011c7200_arg1, 0);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((TileStub*)HUDMainMenu_pme->m_pTiles[25])))->StartFade(0xfa9, g_fHUDMessageFadeTime, 0.0f, ::g_011c7200_arg1, 0);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((TileStub*)HUDMainMenu_pme->m_pTiles[27])))->StartFade(0xfa9, g_fHUDMessageFadeTime, 0.0f, ::g_011c7200_arg1, 0);
                m_uiMessageCount = 0;
            }
            return;
        }
        pIter = ((::BSSimpleList< ::fnv_007756e0::HUDMainMenu__MessageData *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
}
}  // namespace fnv_007756e0

namespace fnv_00778c20 {
extern const char str_01073500[];
struct IntSetting179
{
};
struct TimeGlobal
{
};
extern float DAT_011d979c;
struct Tile179
{
};
// @fnv 0x00778c20
void FUN_00778c20(Tile179* tile, float value, float limit)
{
    static int trait = ::FUN_00a00940(str_01073500, -1);
    int actual = ::FUN_0077f9c0(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d1d54)))))));
    int lower = ::FUN_0077f9c0(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d30d8)))))));
    int low = ::FUN_0077f9c0(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d4d44)))))));
    if (value > actual)
        value = (float)actual;
    else if (value < lower)
        value = (float)lower;
    float state;
    bool rate = value < low;
    float high;
    float alpha = reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(trait);
    state = 0.0f;
    if (rate)
        state = ::LinearInterpolate((float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d3c94)))))), (float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d30f0)))))), (float)low,
                                  (float)lower, value);
    else
        state = ::LinearInterpolate((float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d2bd4)))))), (float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d3c94)))))), (float)actual,
                                  (float)low, value);
    float middle = 0.0f;
    if (alpha == 0.0)
        middle = DAT_011d979c != 0.0
                     ? reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4009) + state * limit / DAT_011d979c * reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_00778c20::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue()
                     : 0.0;
    else if (alpha == 1.0)
        middle = DAT_011d979c != 0.0
                     ? reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4009) - state * limit / DAT_011d979c * reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_00778c20::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue()
                     : 0.0;
    else if (alpha == 3.0)
        middle = DAT_011d979c;
    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4009, middle, true);
    high = reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4009);
    if (high > limit)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4009, limit, true);
        reinterpret_cast<::Tile *>((tile))->Set(trait, 3);
    }
    else if (high < 0.0)
    {
        float delay = 0.0f;
        if (rate)
            delay = ::LinearInterpolate((float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d46cc)))))), (float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d3924)))))), (float)low,
                                      (float)lower, value);
        else
            delay = ::LinearInterpolate((float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d24f0)))))), (float)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00778c20::IntSetting179 *>(&::g_011d46cc)))))),
                                      (float)actual, (float)low, value);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4009, 0.0f, true);
        reinterpret_cast<::Tile *>((tile))->Set(trait, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4110, reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_00778c20::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() + delay, true);
    }
    else if (reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4110) < reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_00778c20::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() && alpha == 3.0)
    {
        reinterpret_cast<::Tile *>((tile))->Set(trait, 1);
    }
}
}  // namespace fnv_00778c20

namespace fnv_0077a650 {
#include <ctype.h>

struct QSound
{
    unsigned int id;
    bool success;
    unsigned int state;
    QSound();
    ~QSound();
    QSound& operator=(const QSound&);
};
struct QAudio
{
    QSound FUN_00ad7550(const char*, unsigned int);
};
struct QSetting
{
    const char* FUN_00403df0();
    float* FUN_00403e20();
};
struct QTile
{
    int value;
    struct List
    {
        QTile** FUN_0073ac90();
        QTile** FUN_0073ac90(int);
    } children;
    void Set(int, int);
    void Set(int, float, bool);
    void Set(int, const char*, bool);
};
struct QName
{
};
struct QQuest
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c, field20, field24, field28, field2c;
    QName name;
};
struct QEntry
{
    QQuest* quest;
    int kind;
    char title[260];
    char text[260];
    int alignment, field214, titleFont, textFont;
    char sound[260];
};
struct QManager
{
};
extern QManager* DAT_011d96bc;
struct QInterface
{
};
bool FUN_00702680(int, unsigned int);
bool FUN_00702450(int);
struct QFlags
{
};
struct QTime
{
};
struct QFont
{
};
extern const char DAT_0106f370[], DAT_01073700[], DAT_010736b0[], DAT_01073640[], DAT_01073624[];
struct QObjectives
{
    bool FUN_008256d0();
};
struct QHud : HUDMainMenu
{
    void UpdateQuestNotification();
    void UpdateTileAnimations(Tile*);
    void UpdateQuestMenu(Tile*);
};
// Shows the pending quest-notification entry: picks its sound, sets title/text tiles, lays out characters, then clears the entry and refreshes the HUD tiles.
// @fnv 0x0077a650
void QHud::UpdateQuestNotification()
{
    int aProcess;
    char aPoint4[260];
    int aOwnList;
    int aOverrideFlagA;
    float aOverrideFlag3;
    QTile* aLocation;
    PointX aData7;
    int aCount1;
    int aBy;
    unsigned int aAlternate;
    int aActor;
    int a6;
    int _unused;
    bool _y;
    if (!DAT_011d96c0 || m_eHudMenuMode == 7 || m_eHudMenuMode == 9 || m_eHudMenuMode == 8 ||
        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077a650::QTime *>(&::g_timeGlobal))))->FUN_00825c00() - (unsigned int)DAT_011d96ac < 2000)
        return;
    _y = ::FUN_007178a0();
    if (!::fnv_007735d0::FUN_007735d0((unsigned char *)this) && !reinterpret_cast<::fnv_0077b2c0::FUN_0077b2c0_shell *>((DAT_011d96bc))->FUN_0077b2c0() &&
        !(::fnv_00773650::FUN_00773650((unsigned char *)this) &&
          reinterpret_cast<::TileListBoxCalls *>((((::fnv_0077a650::QTile **)(reinterpret_cast<::FUN_0073ac90_shell *>(&(((QTile*)HUDMainMenu_pme->m_pTiles[13])->children))->FUN_0073ac90()))[0]))->GetFloat(4009) != 0.0) &&
        (!reinterpret_cast<::FUN_007023a0_shell *>((((::fnv_0077a650::QInterface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007023a0() || FUN_00702680(1009, 0) || ::fnv_00703d50::FUN_00703d50()) && !((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::fnv_0077a650::QFlags *>(&::g_011f2250))))->GetName())))
    {
        m_bQuestObjectiveUpdatePending = true;
        QEntry* aShared;
        QSound aRepair;
        if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 0)
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_0077a650::QSound &)(aRepair))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_0077a650::QSound &)(((::fnv_0077a650::QAudio *)(::FUN_00453a70()))->FUN_00ad7550(DAT_0106f370, 289))));
        else if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 3)
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_0077a650::QSound &)(aRepair))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_0077a650::QSound &)(((::fnv_0077a650::QAudio *)(::FUN_00453a70()))->FUN_00ad7550(((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->sound, 289))));
        else
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_0077a650::QSound &)(aRepair))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_0077a650::QSound &)(((::fnv_0077a650::QAudio *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01073700, 289))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(aRepair))->FUN_00ad8830(false);
        aBy = 0;
        aAlternate = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077a650::QTime *>(&::g_timeGlobal))))->FUN_00825c00();
        aLocation = ((::fnv_0077a650::QTile **)(reinterpret_cast<::FUN_0073ac90_shell *>(&(((QTile*)HUDMainMenu_pme->m_pTiles[14])->children))->FUN_0073ac90()))[0];
        if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((aLocation))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0077a650::QSetting *>(&::g_011d282c))))->GetMenuTitle()))), true);
        else if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 2)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((aLocation))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0077a650::QSetting *>(&::g_011d27c0))))->GetMenuTitle()))), true);
        else if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 1)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((aLocation))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0077a650::QSetting *>(&::g_011d237c))))->GetMenuTitle()))), true);
        else if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 3)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((aLocation))->FUN_00a01350(4036, (char *)(((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->title), true);
        else
            ::FUN_005b5e40();
        reinterpret_cast<::Tile *>((aLocation))->Set(4003, 1);
        reinterpret_cast<::Tile *>((aLocation))->Set(4009, 0);
        aActor = 7;
        if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 3 && ((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->titleFont != -1)
            aActor = ((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->titleFont;
        reinterpret_cast<::Tile *>((aLocation))->Set(4025, aActor);
        {
            PointX aImpact;
            reinterpret_cast<::fnv_00a1b020::FUN_00a1b020_t *>((((::fnv_0077a650::QFont *)(::FontManager::Instance()))))->FUN_00a1b020((const char *)(::PointX *)(&aImpact), (int)(reinterpret_cast<::FUN_00a011f0_shell *>((aLocation))->FUN_00a011f0(4036)),
                                                (int)reinterpret_cast<::TileListBoxCalls *>((aLocation))->GetFloat(4025), reinterpret_cast<::TileListBoxCalls *>((aLocation))->GetFloat(4026));
            aBy = (int)aImpact.x;
            reinterpret_cast<::FUN_00a012d0_t *>((aLocation))->FUN_00a012d0(4002, (float)-(aImpact.y + 15.0), true);
            a6 = 1;
            aOverrideFlag3 = 0.0f;
            aProcess = (int)::InterfaceManager::UpdateInterfaceState();
            aCount1 = (int)::FUN_007177c0();
            _unused = aProcess - 2 * aCount1;
            if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 3)
            {
                switch (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->alignment)
                {
                case 0:
                    a6 = 1;
                    aOverrideFlag3 = 0.0f;
                    break;
                case 1:
                    a6 = 2;
                    aOverrideFlag3 = 0.5f;
                    break;
                case 2:
                    a6 = 4;
                    aOverrideFlag3 = 1.0f;
                    break;
                default:
                    ::FUN_005b5e40();
                    a6 = 1;
                    aOverrideFlag3 = 0.0f;
                    break;
                }
                reinterpret_cast<::FUN_00a012d0_t *>((aLocation))->FUN_00a012d0(4001, (_unused - aBy / 2) * aOverrideFlag3, true);
                reinterpret_cast<::Tile *>((aLocation))->Set(4023, a6);
            }
            reinterpret_cast<::Tile *>((aLocation))->Set(4100, aAlternate);
            reinterpret_cast<::FUN_00a012d0_t *>((aLocation))->FUN_00a012d0(4101, (float)(aAlternate + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0077a650::QSetting *>(&::originalRuntimeFloatSetting1235)))))) * 1000.0), true);
            ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(aLocation), 0);
            if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 1)
                reinterpret_cast<::fnv_0077f5e0::FUN_0077f5e0_shell *>(this)->ResetWaitTiles();

            {
                int aGy;
                void* aInv;
                if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 3)
                    ::TaskQueueInterface::CopyStringToBuffer(aPoint4, 260, ((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->text);
                else
                    ::TaskQueueInterface::CopyStringToBuffer(aPoint4, 260, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->quest->name))->FUN_00408da0())));
                for (unsigned int i = 0; i < 260; i++)
                    aPoint4[i] = (char)toupper(aPoint4[i]);
                aGy = 32;
                aOwnList = ((int)(::FUN_0044a670(aPoint4)));
                if (aOwnList >= 32)
                    for (int i = 32; i >= 0; i--)
                        if (aPoint4[i] == ' ')
                        {
                            aGy = i;
                            break;
                        }
                aActor = 8;
                if (((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->kind == 3 && ((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->textFont != -1)
                    aActor = ((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()))->textFont;
                reinterpret_cast<::fnv_00a1b020::FUN_00a1b020_t *>((((::fnv_0077a650::QFont *)(::FontManager::Instance()))))->FUN_00a1b020((const char *)(::PointX *)(&aData7), (int)(aPoint4), aActor, DAT_01016970);
                aOverrideFlagA = (int)((_unused - (1.0f + aOverrideFlag3) * aData7.x) * aOverrideFlag3);
                aInv = ((void *)(::FUN_00559450((int *)&(((QTile*)HUDMainMenu_pme->m_pTiles[14])->children))));
                {
                    QTile* aEffect;
                    if (aInv)
                        aEffect = ((::fnv_0077a650::QTile *)(reinterpret_cast<::ListStandIn *>(&(((QTile*)HUDMainMenu_pme->m_pTiles[14])->children))->FUN_0057cbe0((int **)&(aInv))));
                    for (int index = 0; aPoint4[index]; index++)
                    {
                        QTile* tile = 0;
                        {
                            if (aInv)
                                tile = ((::fnv_0077a650::QTile *)(reinterpret_cast<::ListStandIn *>(&(((QTile*)HUDMainMenu_pme->m_pTiles[14])->children))->FUN_0057cbe0((int **)&(aInv))));
                            else
                                continue;
                            char character[2];
                            {
                                character[0] = aPoint4[index];
                                character[1] = 0;
                                if (aGy + 1 == index)
                                    aOverrideFlagA =
                                        (int)((_unused - (1.0f + aOverrideFlag3) * aData7.x) * aOverrideFlag3);
                                reinterpret_cast<::Tile *>((tile))->Set(4025, aActor);
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(4036, (char *)(character), true);
                                reinterpret_cast<::Tile *>((tile))->Set(4003, 1);
                                reinterpret_cast<::Tile *>((tile))->Set(4009, 0);
                                reinterpret_cast<::Tile *>((tile))->Set(4001, aOverrideFlagA);
                                PointX size;
                                reinterpret_cast<::fnv_00a1b020::FUN_00a1b020_t *>((((::fnv_0077a650::QFont *)(::FontManager::Instance()))))->FUN_00a1b020((const char *)(::PointX *)(&size), (int)(character), (int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4025),
                                                                    reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4026));
                                if (index <= aGy)
                                    reinterpret_cast<::Tile *>((tile))->Set(4002, 0);
                                else
                                    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4002, (float)(size.y + 5.0), true);
                                aAlternate += (unsigned int)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0077a650::QSetting *>(&::originalRuntimeFloatSetting1236)))))) * 1000.0);
                                reinterpret_cast<::Tile *>((tile))->Set(4100, aAlternate);
                                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4101, (float)(aAlternate + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0077a650::QSetting *>(&::originalRuntimeFloatSetting1235)))))) * 1000.0), true);
                                ::FUN_0040fbe0();
                                ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(tile), 0);
                                aOverrideFlagA += (int)size.x;
                                if (reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4001) + size.x > aBy)
                                    aBy = (int)(reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4001) + size.x);
                            }
                        }
                    }
                }
            }
        }
        aShared = ((::fnv_0077a650::QEntry *)(reinterpret_cast<::FUN_0077b2a0_shell *>((DAT_011d96bc))->GetQuestNamesHead()));
        delete aShared;
        reinterpret_cast<::FUN_0077b2e0_shell *>((DAT_011d96bc))->FUN_0077b2e0();
        UpdateTileAnimations(HUDMainMenu_pme->m_pTiles[14]);
    }
    if (::fnv_007735d0::FUN_007735d0((unsigned char *)this))
        UpdateTileAnimations(HUDMainMenu_pme->m_pTiles[14]);
    else if (!FUN_00702450(1048))
    {
        if ((::fnv_00773650::FUN_00773650((unsigned char *)this) || !((QObjectives*)m_kQuestObjectives)->FUN_008256d0()) && !::fnv_007735d0::FUN_007735d0((unsigned char *)this))
            UpdateQuestMenu(HUDMainMenu_pme->m_pTiles[13]);
    }
}
}  // namespace fnv_0077a650

namespace fnv_0077b300 {
struct Pt3
{
    float x;
    float y;
    float z;
    Pt3 operator-(const Pt3& o) const;
    float Length() const;
};
namespace std {
float abs(float f);
}
struct RefX
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
    virtual Pt3* GetPos();
};

// Compares the distances from the player to the positions of two RefX objects, returning 1, -1 or 0.
// @fnv 0x0077b300
int __cdecl FUN_0077b300(RefX** apRefA, RefX** apRefB)
{
    if (apRefA && *apRefA && apRefB && *apRefB)
    {
        Pt3 playerPos4 = *((RefX*)(*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)))->GetPos();
        Pt3 posA = *(*apRefA)->GetPos();
        float distA_ = std::abs(reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_0077b300::Pt3 &)((posA - playerPos4)))->UpdateCombatStyle());
        Pt3 posB2 = *(*apRefB)->GetPos();
        float distB7 = std::abs(reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_0077b300::Pt3 &)((posB2 - playerPos4)))->UpdateCombatStyle());
        if (distA_ > distB7)
            return 1;
        if (distA_ < distB7)
            return -1;
    }
    return 0;
}
}  // namespace fnv_0077b300

namespace fnv_0077c170 {
struct AnimatedTile;
struct TileList
{
};
struct AnimatedTile
{
    int tileType;
    TileList children;
};
extern SettingX DAT_011d9774;
extern const char str_01073724[];
struct TileAnimationUpdater
{
    void UpdateTileAnimations(AnimatedTile* root);
};
// @fnv 0x0077c170
void TileAnimationUpdater::UpdateTileAnimations(AnimatedTile* pRootTile)
{
    if (reinterpret_cast<::TileListBoxCalls *>((pRootTile))->GetFloat(0xfb6) > 0.0)
    {
        void* tile = ((void *)(::FUN_00559450((int *)&(((AnimatedTile*)HUDMainMenu_pme->m_pTiles[13])->children))));
        AnimatedTile* pChild = 0;
        while (tile)
        {
            pChild = ((::fnv_0077c170::AnimatedTile *)(reinterpret_cast<::ListStandIn *>(&(((AnimatedTile*)HUDMainMenu_pme->m_pTiles[13])->children))->FUN_0057cbe0((int **)&(tile))));
            if (pChild)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((pChild))->FUN_00a012d0(0xfa9, 0.0f, true);
                reinterpret_cast<::Tile *>((pChild))->Set(::FUN_00a01860(str_01073724), 0);
            }
        }
        tile = ((void *)(::FUN_00559450((int *)&(pRootTile->children))));
        pChild = 0;
        while (tile)
        {
            pChild = ((::fnv_0077c170::AnimatedTile *)(reinterpret_cast<::ListStandIn *>(&(pRootTile->children))->FUN_0057cbe0((int **)&(tile))));
            if (pChild && reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0x1004) > 0.0 &&
                (unsigned int)((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00())) > reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0x1004))
            {
                reinterpret_cast<::Tile *>((pChild))->SetName(reinterpret_cast<::FUN_00a011f0_shell *>((pChild))->FUN_00a011f0(0xfc4));
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((pChild))->StartFade(0xfa9, 0.0f, (float)(255.0 * *((float *)&(::FUN_00403e20((float *)&(DAT_011d9774))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting1233)))))), 0);
                reinterpret_cast<::Tile *>((pChild))->Set(0x1004, 0);
            }
            else if (pChild && reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0x1005) > 0.0 &&
                     (unsigned int)((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00())) > reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0x1005))
            {
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((pChild))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0xfa9) > 175.0 ? reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0xfa9) : 175.0f,
                                  0.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting1234)))))), 0);
                reinterpret_cast<::Tile *>((pChild))->Set(0x1005, 0);
            }
            else if (pChild && reinterpret_cast<::fnv_00a07f30::FUN_00a07f30_shell *>((pChild))->GetTraitFloat(0xfa9) == 0.0 && reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0xfa9) == 0.0 &&
                     reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0x1005) == 0.0)
            {
                reinterpret_cast<::Tile *>((pChild))->Set(0xfa3, 0);
            }
        }
    }
}
}  // namespace fnv_0077c170

struct BreathPoint
{
    float x, y, z;
};
struct BreathProcess
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
    virtual float GetBreath();
};
struct BreathPlayer
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
    virtual BreathPoint* GetPosition();
    float GetValue();
};
extern float DAT_011d979c;
struct BreathUpdate
{
    float time;
    bool controllers;
    bool threaded;
    int flags;
    BreathUpdate(float, bool, bool);
};
struct BreathObject
{
};
struct BreathNode
{
};
struct BreathTile
{
    BreathNode* Node();
};
struct BreathSequence
{
    void Set(float, bool);
};
struct BreathHUD
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
    BreathTile* tile;
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
    BreathSequence* sequence;
    void FUN_0077e4f0();
};
// @fnv 0x0077e4f0
void BreathHUD::FUN_0077e4f0()
{
    float aWater = reinterpret_cast<::FUN_00885560_shell *>(((*reinterpret_cast<::BreathPlayer * *>(&::_g_thePlayer))))->GetWaterDepthAtPoint((*reinterpret_cast<::BreathPlayer * *>(&::_g_thePlayer))->GetPosition()->z, (::TESObjectCELL *)(void *)(((void *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::BreathPlayer * *>(&::_g_thePlayer))))->GetTarget()))));
    bool submergedA = aWater >= 0.009999999776482582;
    bool deep4 = aWater >= 0.875;
    float aMaximum = ::FUN_00648a10((int)reinterpret_cast<::fnv_008be7a0::FloatValueProvider *>(((*reinterpret_cast<::BreathPlayer * *>(&::_g_thePlayer))))->FUN_008be7a0());
    float fraction = ((::BreathProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::BreathPlayer * *>(&::_g_thePlayer))))->GetBaseTexture())) ? ((::BreathProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::BreathPlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetBreath() / aMaximum : 100.0;
    float visible = reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(4009);
    if (deep4)
    {
        if (visible == 0.0)
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((tile))->StartFade(4009, 0.0f, DAT_011d979c, ::fnv_00c88020::DAT_01016248, 0);
    }
    else if (visible > 0.0 && reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((tile))->FUN_00a07fc0(4009))
    {
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((tile))->StartFade(4009, DAT_011d979c, 0.0f, ::fnv_00c88020::DAT_01016248, 0);
    }
    if (sequence && visible > 0.0)
    {
        BreathUpdate update(0.0f, true, false);
        reinterpret_cast<::fnv_00a328b0::SeqExt *>((sequence))->FUN_00a328b0(reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100() + fraction * (reinterpret_cast<::FUN_00759450_shell *>((sequence))->FUN_00759450() - reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100()), false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::BreathObject *)(reinterpret_cast<::NiNode *>((((::BreathNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((tile))->FUN_0056c7f0()))))->GetAt(0)))))->FUN_00a59c60((int)&(update));
    }
}

namespace fnv_0077e750 {
struct CompassBase
{
};
struct CompassReference : TESForm
{
};
struct CompassArray
{
};
struct CompassArrayOwner
{
};
struct CompassSetting
{
    float* FUN_00403e20();
};
extern CompassSetting g_011d9774;
struct CompassUpdate
{
    float time;
    bool updateControllers;
    bool multithreaded;
    int flags;
};
struct CompassNode
{
};
struct CompassTile
{
};
struct CompassTileList
{
};
struct CompassTileOwner
{
    int flags;
    CompassTileList tiles;
};
struct CompassPoint
{
    float x, y, z;
    CompassPoint operator-(const CompassPoint&) const;
};
struct CompassCameraModel
{
    CompassPoint FUN_0045bba0();
};
struct CompassCamera
{
};
struct CompassHUD : HUDMainMenu
{
    void UpdateCompassMarkers();
};
// @fnv 0x0077e750
void CompassHUD::UpdateCompassMarkers()
{
    CompassReference* reference_2 = 0;
    CompassTile* h;
    void* position = ((void *)(::FUN_00559450((int *)&(((CompassTileOwner*)m_pTiles[73])->tiles))));
    for (unsigned int index = reinterpret_cast<::fnv_005de0f0::FUN_005de0f0_shell *>((((::fnv_0077e750::CompassArray *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_0077e750::CompassArrayOwner *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005de0f0({});
         index < reinterpret_cast<::FUN_005be5c0_shell *>((((::fnv_0077e750::CompassArray *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_0077e750::CompassArrayOwner *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0({}); ++index)
    {
        reference_2 = ((::fnv_0077e750::CompassReference *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::fnv_0077e750::CompassArray *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_0077e750::CompassArrayOwner *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({})));
        if (reference_2 && !reinterpret_cast<::FUN_00576d30_shell *>((reference_2))->FUN_00576d30() && !reinterpret_cast<::FUN_00440d80_shell *>((reference_2))->FUN_00440d80() &&
            !reinterpret_cast<::TESForm *>((reference_2))->GetDisabled() && reference_2->GetFormType() == 62 && reference_2->IsCreature())
        {
            if (reference_2 && !reinterpret_cast<::TESSound *>((reference_2))->FUN_0077eac0() && ((void *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::fnv_0077e750::CompassBase *)(reinterpret_cast<::Actor *>((reference_2))->GetActorBase())))))) &&
                reinterpret_cast<::BGSProjectile *>((((::fnv_0077e750::CompassBase *)(reinterpret_cast<::Actor *>((reference_2))->GetActorBase()))))->GetExplosionProximity() == 0.0 &&
                ((double)(reinterpret_cast<::NiPoint3 *>((void *)&(const ::fnv_0077e750::CompassPoint &)((*(CompassPoint*)reference_2->GetPos() - *(CompassPoint*)(*reinterpret_cast<::fnv_0077e750::CompassReference * *>(&::_g_thePlayer))->GetPos())))->ComputeMagnitude())) <
                    *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0077e750::CompassSetting *>(&::originalRuntimeFloatSetting1232)))))))
            {
                if (position)
                {
                    h = ((::fnv_0077e750::CompassTile *)(reinterpret_cast<::ListStandIn *>(&(((CompassTileOwner*)m_pTiles[73])->tiles))->FUN_0057cbe0((int **)&(position))));
                    if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((h))->FUN_00a07fc0(4009) && reinterpret_cast<::TileListBoxCalls *>((h))->GetFloat(4009) == 0.0)
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((h))->StartFade(4009, 0.0f, (float)(*((float *)&(::FUN_00403e20((float *)&(g_011d9774)))) * 255.0), 0.5f, false);
                }
                else
                {
                    continue;
                }
                float angle2 =
                    ::GetDirectionAngle((const ::NiPoint3 *)&(const ::fnv_0077e750::CompassPoint &)(*(CompassPoint*)reference_2->GetPos() - *(CompassPoint*)(*reinterpret_cast<::fnv_0077e750::CompassReference * *>(&::_g_thePlayer))->GetPos()));
                float angle5 = ::GetDirectionAngle((const ::NiPoint3 *)&(const ::fnv_0077e750::CompassPoint &)(((::fnv_0077e750::CompassCameraModel *)(reinterpret_cast<::BSFaceGenNiNode *>((((CompassCamera*)((::FovSource *)(::FUN_0045c670())))))->GetAnimationData()))->FUN_0045bba0()));
                reinterpret_cast<::NiAVObject *>((((::fnv_0077e750::CompassNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((h))->FUN_0056c7f0()))))->SetLocalRotation(angle5 - angle2, 0.0f, 1.0f, 0.0f);
                CompassUpdate updated5;
                new ((void *)&(updated5)) ::NiUpdateData(0.0f, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0077e750::CompassNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((h))->FUN_0056c7f0()))))->FUN_00a59c60((int)&(updated5));
            }
        }
    }
    while (position)
    {
        CompassTile* remaining = ((::fnv_0077e750::CompassTile *)(reinterpret_cast<::ListStandIn *>(&(((CompassTileOwner*)m_pTiles[73])->tiles))->FUN_0057cbe0((int **)&(position))));
        if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((remaining))->FUN_00a07fc0(4009) && reinterpret_cast<::TileListBoxCalls *>((remaining))->GetFloat(4009) > 0.0)
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((remaining))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((remaining))->GetFloat(4009), 0.0f, 0.5f, false);
    }
}
}  // namespace fnv_0077e750

namespace fnv_0077eaf0 {
// UpdateStatsMenu v01 - full one-pass transcription from packet decode, worker8
struct Node77
{
};
struct ScriptObj
{
};
extern float DAT_011d979c;
extern const char* DAT_011a00c4[];
extern const char str_01073868[];
struct Tile77
{
};
struct FirstSrc
{
    virtual void firstSlot0();
    virtual void firstSlot1();
    virtual Node77* GetFirst();
};
struct AVSrc
{
    virtual void avSlot0();
    virtual void avSlot1();
    virtual void avSlot2();
    virtual float GetCurrent(int);
    virtual void avSlot4();
    virtual void avSlot5();
    virtual void avSlot6();
    virtual void avSlot7();
    virtual float GetBase(int);
};
struct PlayerC
{
    int m_00[37];
    FirstSrc m_94;
    int m_98[3];
    AVSrc m_av;
};
struct MenuC
{
    int m_00[10];
    Tile77* m_tiles[52];
    Tile77* m_face;
    void UpdateStatsMenu();
};
// @fnv 0x0077eaf0
void MenuC::UpdateStatsMenu()
{
    char buf[260];
    int result = 0;
    {
        int val;
        Node77* mag;
        float condition;
        float d;
        int t;
        float state;
        for (mag = (*reinterpret_cast<::fnv_0077eaf0::PlayerC * *>(&::_g_thePlayer))->m_94.GetFirst(); mag && *((void **)(new ((void *)(mag)) ::Vec3())); mag = ((::fnv_0077eaf0::Node77 *)(reinterpret_cast<::Callees *>((mag))->FUN_00726070())))
        {
            if (((int)(reinterpret_cast<::BGSMessageInitAccess *>((((ScriptObj*)*((void **)(new ((void *)(mag)) ::Vec3())))))->GetIconFormID())) == 10)
                result = 10;
        }
        if (result == 0)
        {
            condition = (*reinterpret_cast<::fnv_0077eaf0::PlayerC * *>(&::_g_thePlayer))->m_av.GetBase(0x10);
            d = condition - (*reinterpret_cast<::fnv_0077eaf0::PlayerC * *>(&::_g_thePlayer))->m_av.GetCurrent(0x10);
            result = (int)((d / condition) * 5.0);
            if (result < 0)
                result = 0;
            if (result > 4)
                result = 4;
        }
        ::FUN_00406d00(buf, 0x104, str_01073868, result);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_face))->FUN_00a01350(0xfcc, (char *)(buf), true);
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_face))->StartFade(0xfa9, 0.0f, DAT_011d979c, 5.0f, 4);
        val = 0x35;
        for (t = 0x19; t < 0x1f; ++t, ++val)
        {
            state = (*reinterpret_cast<::fnv_0077eaf0::PlayerC * *>(&::_g_thePlayer))->m_av.GetCurrent(t) / 100.0;
            ::FUN_00406d00(buf, 0x104,
                         state > ::_DAT_01012060 ? "Interface\\Stats\\%s.dds" : "Interface\\Stats\\%s_broken.dds",
                         DAT_011a00c4[t]);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_tiles[val]))->FUN_00a01350(0xfcc, (char *)(buf), true);
            if (state == ::_DAT_01012060)
            {
                reinterpret_cast<::Tile *>((m_tiles[val]))->Set(0xff4, 2);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_tiles[val]))->StartFade(0xfa9, 0.0f, DAT_011d979c, 5.0f, 3);
            }
            else
            {
                reinterpret_cast<::Tile *>((m_tiles[val]))->Set(0xff4, 1);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_tiles[val]))->StartFade(0xfa9, 0.0f, DAT_011d979c, 5.0f, 4);
            }
        }
    }
}
}  // namespace fnv_0077eaf0

namespace fnv_0077f0d0 {
extern float g_fUpdate_011a0140;

struct FaceAnimData_0077f0d0
{
    void IncRefCount();
    void DecRefCount();
};

struct SceneNode_0077f0d0
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
    virtual void AttachNode(NiNode* apNode, int aiFlag);
};

struct Renderer_0077f0d0
{
};

struct SceneGraphRoot_0077f0d0
{
};

struct FaceGenNode_0077f0d0
{
};

struct IfaceMgr_0077f0d0
{
    NiNode* GetNode();
};

extern NiPointer<NiNode> g_011d9770;
extern NiPointer<FaceAnimData_0077f0d0> g_011d975c;
extern HUDMainMenu* HUDMainMenu_pme;


// Attaches the face node to scene node 1 if needed, begins the face-gen scene graph, updates and renders the face animation data, then ends the scene.
// @fnv 0x0077f0d0
void RenderFaceGenScene()
{
    if (!g_011d9770 || (HUDMainMenu_pme && !HUDMainMenu_pme->m_bHudModeActive))
        return;
    if (!reinterpret_cast<::FUN_00453470_shell *>((((::fnv_0077f0d0::SceneNode_0077f0d0 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)))))->FUN_00453470())
        ((::fnv_0077f0d0::SceneNode_0077f0d0 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)))->AttachNode(g_011d9770, 1);
    reinterpret_cast<::S148c0 *>((((::fnv_0077f0d0::Renderer_0077f0d0 *)(::FUN_0043c4b0()))))->FUN_007148c0(0, 4);
    FaceGenNode_0077f0d0* pFaceGen5 = ((::fnv_0077f0d0::FaceGenNode_0077f0d0 *)(::FUN_0045c670()));
    SceneGraphRoot_0077f0d0* pRoot4 = ((::fnv_0077f0d0::SceneGraphRoot_0077f0d0 *)(reinterpret_cast<::MiddleLowProcess *>((pFaceGen5))->GetProcessInteger()));
    reinterpret_cast<::FUN_00c4f270_Class *>((pRoot4))->FUN_00c4f270(1);
    FaceAnimData_0077f0d0* pGlobalForm = g_011d975c;
    ::UpdateCameraFrustum((::NiCamera *)(pGlobalForm), g_fUpdate_011a0140);
    NiPointer<NiNode> m_pController(((::NiNode *)(reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((((::fnv_0077f0d0::IfaceMgr_0077f0d0 *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007fd640())));
    reinterpret_cast<::FUN_004a0fd0_shell *>((pRoot4))->FUN_004a0fd0(m_pController);
    FaceAnimData_0077f0d0* pData = pGlobalForm ? pGlobalForm : ((::fnv_0077f0d0::FaceAnimData_0077f0d0 *)(reinterpret_cast<::BSFaceGenNiNode *>((pFaceGen5))->GetAnimationData()));
    ::FUN_00b6bee0(pData, ((::fnv_0077f0d0::SceneNode_0077f0d0 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))), (::BSShaderAccumulator *)(pRoot4));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(pData), (::BSShaderAccumulator *)(::NiNode *)(m_pController), 0);
    reinterpret_cast<::FUN_004a0fd0_shell *>((pRoot4))->FUN_004a0fd0(0);
    m_pController = 0;
    reinterpret_cast<::FUN_00c4f2d0_class *>((pRoot4))->FUN_00c4f2d0();
}
}  // namespace fnv_0077f0d0

namespace fnv_0077f270 {
struct Node_77f270
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
    virtual void DetachChild58(void* child);
    void* GetAt(unsigned int idx);
};

struct Ptr_77f270
{
    Node_77f270* m_pObject;
    operator Node_77f270*() const;
    Node_77f270* operator->() const;
};

struct HUD_77f270
{
    int unk[127];
    bool b1fc;
};

extern Ptr_77f270 g_011d9770;

// If HUDMainMenu_pme and g_011d9770 exist and the node has a child at index 0, detaches that child and clears b1fc on the HUD menu.
// @fnv 0x0077f270
void __cdecl FUN_0077f270()
{
    if (HUDMainMenu_pme && (Node_77f270*)g_011d9770 && ((void *)(reinterpret_cast<::S_FUN_0045bc00 *>((((Node_77f270*)g_011d9770)))->FUN_0045bc00(0))))
    {
        ((Node_77f270*)g_011d9770)->DetachChild58(((void *)(reinterpret_cast<::NiNode *>((((Node_77f270*)g_011d9770)))->GetAt(0))));
        ((HUD_77f270*)HUDMainMenu_pme)->b1fc = false;
    }
}
}  // namespace fnv_0077f270

struct xSize
{
    float x, y, z;
};
struct xTile
{
};
struct xTileList
{
    xTile*& FUN_00683520(void*&);
    xTile*& FUN_0073ac90();
};
struct xHolder
{
    int m_iWordAt00;
    xTileList m_iWordAt04;
};
struct xPME
{
    int m_auiShapeKeys[0x5c / 4];
    xHolder* m_5c;
};
extern xPME* xg_pme_11d96c0;
struct xQObj
{
    char m_pText[0x104];
    bool m_104;
    bool m_105;
};
struct xQNode
{
    bool FUN_008256d0();
    void* m_iWordAt00;
    void* m_iWordAt04;
};
struct xFontMgr
{
    xSize FUN_00a1b020(const char*, int, float, int);
};
struct xSound
{
    ~xSound();
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xAudio
{
    xSound FUN_00ad7550(const char*, unsigned int);
};
struct xStrSetting
{
    const char* FUN_00403df0();
};
struct xFltSetting
{
    float* FUN_00403e20();
};
extern float xg_f_11d979c;
int xStrcat(char*, unsigned int, const char*);

static const char s_szIsReminder[] = "_IsReminder";
static const char s_szFilled[] = "Interface\\Shared\\Marker\\glow_square_filled_small.dds";
static const char s_szSquare[] = "Interface\\Shared\\Marker\\glow_square_small.dds";
static const char s_szObjFmt[] = "obj_%d";
static const char s_szQuestUpdate[] = "UIQuestUpdate";
static const char s_szWaitComplete[] = "_WaitComplete";
static const char s_szHoldTime[] = "_HoldTime";
extern const char s_litEnd77b430[] = "";

struct xQuestMenu
{
    int m_auiShapeKeys[0x258 / 4];
    xQNode m_258;
    char m_260;
    bool m_261;
    void UpdateQuestMenu(xHolder*);
};

// Populates quest menu tiles from the quest node list, positions them, and drives their fade-in/out animations.
// @fnv 0x0077b430
void xQuestMenu::UpdateQuestMenu(xHolder* HOLDER)
{
    int qrEZrs = (int)((double)(::InterfaceManager::UpdateInterfaceState()));
    bool qfTOqo = false;
    if (!::fnv_00773650::FUN_00773650((unsigned char *)this))
    {
        xQNode* qArxcFu = &m_258;
        void* qAhbO = ((void *)(::FUN_00559450((int *)&(xg_pme_11d96c0->m_5c->m_iWordAt04))));
        for (int SKIPA = 0; SKIPA < 0x1f; SKIPA++)
            reinterpret_cast<::ListStandIn *>(&(xg_pme_11d96c0->m_5c->m_iWordAt04))->FUN_0057cbe0((int **)&(qAhbO));
        void* qxQHW = reinterpret_cast<::Callees *>(&(xg_pme_11d96c0->m_5c->m_iWordAt04))->FUN_00726070();
        while (qArxcFu && !qArxcFu->FUN_008256d0() && qAhbO)
        {
            bool qHVMR = !::fnv_00773650::FUN_00773650((unsigned char *)this);
            bool qxWmVch =
                qHVMR ? false
                      : reinterpret_cast<::FUN_00a01230_shell *>((((::xTile *)(reinterpret_cast<::FUN_0073ac90_shell *>(&(xg_pme_11d96c0->m_5c->m_iWordAt04))->FUN_0073ac90()))))->IsTraitNonZero(::FUN_00a01860(s_szIsReminder));
            bool qJDuOZ = (*((::xQObj **)(new ((void *)(qArxcFu)) ::Vec3())))->m_105;
            if (!qHVMR && qxWmVch && !qJDuOZ)
            {
                qArxcFu = ((::xQNode *)(reinterpret_cast<::Callees *>((qArxcFu))->FUN_00726070()));
                continue;
            }
            if (!qHVMR && !qxWmVch && qJDuOZ)
            {
                qArxcFu = ((::xQNode *)(reinterpret_cast<::Callees *>((qArxcFu))->FUN_00726070()));
                continue;
            }
            m_261 = true;
            qfTOqo = true;
            xTile* qQMZREG = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qAhbO);
            xTile* qDdzMIp = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qxQHW);
            if ((*((::xQObj **)(new ((void *)(qArxcFu)) ::Vec3())))->m_104)
            {
                char LINE[0x104];
                ::TaskQueueInterface::CopyStringToBuffer(LINE, 0x104, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::xStrSetting *>(&::g_011d1d60))))->GetMenuTitle())));
                xStrcat(LINE, 0x104, (*((::xQObj **)(new ((void *)(qArxcFu)) ::Vec3())))->m_pText);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qQMZREG))->FUN_00a01350(0xfc4, (char *)(LINE), true);
                reinterpret_cast<::Tile *>((qQMZREG))->Set(::FUN_00a01860(s_szIsReminder), qJDuOZ);
                reinterpret_cast<::Tile *>((qQMZREG))->Set(0x1007, 1);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qDdzMIp))->FUN_00a01350(0xfcc, (char *)(s_szFilled), true);
            }
            else
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qQMZREG))->FUN_00a01350(0xfc4, (char *)((*((::xQObj **)(new ((void *)(qArxcFu)) ::Vec3())))->m_pText), true);
                reinterpret_cast<::Tile *>((qQMZREG))->Set(0x1007, 0);
                reinterpret_cast<::Tile *>((qQMZREG))->Set(::FUN_00a01860(s_szIsReminder), qJDuOZ);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qDdzMIp))->FUN_00a01350(0xfcc, (char *)(s_szSquare), true);
            }
            reinterpret_cast<::FUN_00a012d0_t *>((qDdzMIp))->FUN_00a012d0(0xfa1, reinterpret_cast<::TileListBoxCalls *>((qQMZREG))->GetFloat(0xfa1) - 20.0, true);
            reinterpret_cast<::Tile *>((qDdzMIp))->Set(0xfa3, 1);
            reinterpret_cast<::Tile *>((qQMZREG))->Set(0xfb9, 7);
            reinterpret_cast<::Tile *>((qQMZREG))->Set(0xfa3, 1);
            reinterpret_cast<::Tile *>((qQMZREG))->Set(0xfa9, 0);
            reinterpret_cast<::Tile *>((qQMZREG))->Set(0xfba, qrEZrs / 3);
            int qaGEwZ = 0;
            char NAME[0x104];
            ::FUN_00406d00(NAME, 0x104, s_szObjFmt, qaGEwZ++);
            reinterpret_cast<::Tile *>((qQMZREG))->SetName(NAME);
            ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(qQMZREG), 0);
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::xSound &)(((::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szQuestUpdate, 0x121)))->FUN_00ad8830(false);
            reinterpret_cast<::ItemChangeListNode *>((qArxcFu))->FUN_00905330((*(::InventoryStackRecord *const *)(((::xQObj **)(new ((void *)(qArxcFu)) ::Vec3())))));
        }
    }
    if (qfTOqo)
    {
        void* qQGWBE = ((void *)(::FUN_00559450((int *)&(xg_pme_11d96c0->m_5c->m_iWordAt04))));
        void* qZWI = reinterpret_cast<::Callees *>(&(xg_pme_11d96c0->m_5c->m_iWordAt04))->FUN_00726070();
        for (int SKIPB = 0; SKIPB < 0x1f; SKIPB++)
            xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qZWI);
        int qkJsUdT = 0;
        int qpia = 0;
        while (qQGWBE && qpia < 0x20)
        {
            qpia++;
            xTile* qXMUYT = ((::xTile *)(reinterpret_cast<::ListStandIn *>(&(HOLDER->m_iWordAt04))->FUN_0057cbe0((int **)&(qQGWBE))));
            xTile* qIpA = ((::xTile *)(reinterpret_cast<::ListStandIn *>(&(HOLDER->m_iWordAt04))->FUN_0057cbe0((int **)&(qZWI))));
            if (qXMUYT && reinterpret_cast<::FUN_00a01230_shell *>((qXMUYT))->IsTraitNonZero(0xfa3))
            {
                reinterpret_cast<::Tile *>((qXMUYT))->Set(0xfa2, qkJsUdT);
                reinterpret_cast<::Tile *>((qIpA))->Set(0xfa2, qkJsUdT + 3);
                xSize SZ = ((::xFontMgr *)(::FontManager::Instance()))->FUN_00a1b020(
                    reinterpret_cast<::FUN_00a011f0_shell *>((qXMUYT))->FUN_00a011f0(0xfc4), (int)reinterpret_cast<::TileListBoxCalls *>((qXMUYT))->GetFloat(0xfb9), reinterpret_cast<::TileListBoxCalls *>((qXMUYT))->GetFloat(0xfba), 0);
                qkJsUdT += (int)SZ.y;
            }
        }
    }
    static int s_iWait = ::FUN_00a00940(s_szWaitComplete, -1);
    void* qSVM = ((void *)(::FUN_00559450((int *)&(HOLDER->m_iWordAt04))));
    void* qdqWL = reinterpret_cast<::Callees *>(&(HOLDER->m_iWordAt04))->FUN_00726070();
    for (int SKIPC = 0; SKIPC < 0x1f; SKIPC++)
        xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qdqWL);
    int qpTd = 0;
    xTile* qpqRa[4];
    xTile* qsSDDgz[4];
    qpqRa[0] = 0;
    qpqRa[1] = 0;
    qpqRa[2] = 0;
    qpqRa[3] = 0;
    qsSDDgz[0] = 0;
    qsSDDgz[1] = 0;
    qsSDDgz[2] = 0;
    qsSDDgz[3] = 0;
    int qvyWyw = 0;
    while (qSVM && qpTd < 4 && qvyWyw < 0x20)
    {
        qvyWyw++;
        xTile* qbfQdhM = ((::xTile *)(reinterpret_cast<::ListStandIn *>(&(HOLDER->m_iWordAt04))->FUN_0057cbe0((int **)&(qSVM))));
        xTile* qidnYUK = ((::xTile *)(reinterpret_cast<::ListStandIn *>(&(HOLDER->m_iWordAt04))->FUN_0057cbe0((int **)&(qdqWL))));
        if (reinterpret_cast<::FUN_00a01230_shell *>((qbfQdhM))->IsTraitNonZero(0xfa3))
        {
            if (qpTd > 0 && qpqRa[qpTd] == qsSDDgz[qpTd - 1])
                break;
            qsSDDgz[qpTd] = qidnYUK;
            qpqRa[qpTd] = qbfQdhM;
            qpTd++;
        }
    }
    if (qpqRa[0])
    {
        if (reinterpret_cast<::TileListBoxCalls *>((qpqRa[0]))->GetFloat(s_iWait) == 0.0)
        {
            reinterpret_cast<::Tile *>((qpqRa[0]))->Set(s_iWait, 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[0]))->StartFade(0xfa9, 0.0f, xg_f_11d979c, 0.5f, 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[0]))->StartFade(s_iWait, 0.0f, 1.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011d4cc0)))))) * 3.0, 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qsSDDgz[0]))->StartFade(0xfa9, 0.0f, xg_f_11d979c, 0.5f, 0);
            if (qpqRa[1])
            {
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[1]))->StartFade(s_iWait, 0.0f, 1.0f, 1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011d4cc0)))))), 0);
                if (qpqRa[2])
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[2]))->StartFade(s_iWait, 0.0f, 1.0f, 2.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011d4cc0)))))), 0);
            }
        }
        else if (reinterpret_cast<::TileListBoxCalls *>((qpqRa[0]))->GetFloat(s_iWait) == 1.0)
        {
            static int s_iHold = ::FUN_00a00940(s_szHoldTime, -1);
            if (reinterpret_cast<::TileListBoxCalls *>((qpqRa[0]))->GetFloat(s_iHold) == 0.0)
            {
                reinterpret_cast<::Tile *>((qpqRa[0]))->Set(s_iHold, 0);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[0]))->StartFade(s_iHold, 0.0f, 1.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1240)))))), 0);
            }
            else if (reinterpret_cast<::TileListBoxCalls *>((qpqRa[0]))->GetFloat(s_iHold) == 1.0)
            {
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[0]))->StartFade(0xfa9, xg_f_11d979c, 0.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1238)))))), 0);
                reinterpret_cast<::Tile *>((qpqRa[0]))->Set(s_iWait, 2);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qsSDDgz[0]))->StartFade(0xfa9, xg_f_11d979c, 0.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1238)))))), 0);
            }
        }
        else if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((qpqRa[0]))->FUN_00a07fc0(0xfa9) && reinterpret_cast<::TileListBoxCalls *>((qpqRa[0]))->GetFloat(0xfa9) == 0.0)
        {
            if (qpqRa[1])
            {
                int qxDeKK = (int)(reinterpret_cast<::TileListBoxCalls *>((qpqRa[1]))->GetFloat(0xfa2) - reinterpret_cast<::TileListBoxCalls *>((qpqRa[0]))->GetFloat(0xfa2));
                qSVM = ((void *)(::FUN_00559450((int *)&(HOLDER->m_iWordAt04))));
                xTile* qAXSCg = 0;
                if (qSVM)
                    qAXSCg = ((::xTile *)(reinterpret_cast<::ListStandIn *>(&(HOLDER->m_iWordAt04))->FUN_0057cbe0((int **)&(qSVM))));
                while (qSVM)
                {
                    qAXSCg = ((::xTile *)(reinterpret_cast<::ListStandIn *>(&(HOLDER->m_iWordAt04))->FUN_0057cbe0((int **)&(qSVM))));
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qAXSCg))->StartFade(0xfa2, reinterpret_cast<::TileListBoxCalls *>((qAXSCg))->GetFloat(0xfa2), reinterpret_cast<::TileListBoxCalls *>((qAXSCg))->GetFloat(0xfa2) - qxDeKK,
                                      *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1239)))))), 0);
                }
            }
            if (qpqRa[3])
                reinterpret_cast<::Tile *>((qpqRa[3]))->Set(s_iWait, 1);
            reinterpret_cast<::Tile *>((qpqRa[0]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((qsSDDgz[0]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((qpqRa[0]))->Set(s_iWait, 0);
            qpqRa[0] = 0;
        }
        if (qpqRa[1] && reinterpret_cast<::TileListBoxCalls *>((qpqRa[1]))->GetFloat(s_iWait) == 1.0 && reinterpret_cast<::TileListBoxCalls *>((qpqRa[1]))->GetFloat(0xfa9) == 0.0)
        {
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[1]))->StartFade(0xfa9, 0.0f, xg_f_11d979c, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1237)))))), 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qsSDDgz[1]))->StartFade(0xfa9, 0.0f, xg_f_11d979c, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1237)))))), 0);
        }
        if (qpqRa[2] && reinterpret_cast<::TileListBoxCalls *>((qpqRa[2]))->GetFloat(s_iWait) == 1.0 && reinterpret_cast<::TileListBoxCalls *>((qpqRa[2]))->GetFloat(0xfa9) == 0.0)
        {
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qpqRa[2]))->StartFade(0xfa9, 0.0f, xg_f_11d979c, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1237)))))), 0);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((qsSDDgz[2]))->StartFade(0xfa9, 0.0f, xg_f_11d979c, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1237)))))), 0);
        }
    }
}

#include <float.h>
struct TESAmmo : TESBoundObject
{
    const char* FUN_00772820();
};
struct AmmoPlayer;
struct AmmoWeapon;
struct AmmoInventory
{
};
struct AmmoFlags
{
};
struct AmmoWeapon
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    AmmoFlags flags;
    int FUN_00446390();
};
struct AmmoExtra
{
};
struct AmmoData
{
};
struct AmmoProvider
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
    virtual AmmoExtra* GetLoadedForm();
    virtual AmmoData* GetAmmo();
};
struct AmmoPlayer
{
};
struct AmmoSetting
{
    float* FUN_00403e20();
};
extern AmmoSetting ammoSetting;
struct AmmoTile
{
};
struct AmmoHUD
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    AmmoTile* tiles[87];
    void UpdateAmmoHUD();
};
extern AmmoHUD* ammoHUD;
extern bool ammoNameShowing, ammoFlashDirection;
extern float ammoLastCurrent, ammoLastTotal, ammoLastCondition;
extern AmmoWeapon* ammoLastWeapon;
extern char ammoName[260], ammoSpecialName[260], ammoCountText[260];
// Updates ammo HUD tiles with ammo text, counts, and a condition bar animation using the current weapon and ammo data.
// @fnv 0x007721c0
void AmmoHUD::UpdateAmmoHUD()
{
    if ((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer)) && ((::AmmoProvider *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer))))->GetBaseTexture())))
    {
        float flashTime_ = *((float *)&(::FUN_00403e20((float *)&(ammoSetting)))) * 255.0;
        AmmoExtra* extra9 = ((::AmmoProvider *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetLoadedForm();
        static float timer = flashTime_;
        ::FUN_00406d00(ammoName, 260, ::DAT_01019f08, ::DAT_01011584);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tiles[77]))->FUN_00a01350(4036, (char *)(ammoName), true);
        if (extra9)
        {
            AmmoWeapon* weapon5 = ((::AmmoWeapon *)(reinterpret_cast<::Twin_0044ddc0 *>((extra9))->GetName()));
            float current4 = 0.0f;
            float total2 = 0.0f;
            switch (weapon5->FUN_00446390())
            {
            case 10:
            case 11:
            case 12:
            case 13:
                current4 = reinterpret_cast<::FUN_00524b60_shell *>((weapon5))->GetByteAt102();
                total2 =
                    reinterpret_cast<::FUN_004c8f30_shell *>((((::AmmoInventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer))))))))->FUN_004c8f30((int)(reinterpret_cast<TESBoundObject*>(weapon5))) - current4;
                break;
            default: {
                AmmoData* data3 = ((::AmmoProvider *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetAmmo();
                TESAmmo* ammo_ = 0;
                if (data3 && ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((data3))->GetName())))
                    ammo_ = dynamic_cast<TESAmmo*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((data3))->GetName())));
                if (ammo_)
                {
                    const char* name = ((const char *)(reinterpret_cast<::FUN_00772820 *>((ammo_))->Get()));
                    ::FUN_00406d00(ammoSpecialName, 260, ::DAT_01019f08, name ? name : ::DAT_01011584);
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tiles[77]))->FUN_00a01350(4036, (char *)(ammoSpecialName), true);
                    if (name)
                    {
                        if (!ammoNameShowing)
                        {
                            reinterpret_cast<::fnv_0077f890::HUDMainMenuS *>(this)->ShiftTileValues(-50);
                            ammoNameShowing = true;
                        }
                    }
                    else if (ammoNameShowing)
                    {
                        reinterpret_cast<::fnv_0077f890::HUDMainMenuS *>(this)->ShiftTileValues(50);
                        ammoNameShowing = false;
                    }
                }
                bool useInventory5 = true;
                if (reinterpret_cast<::TESObjectWEAP *>((weapon5))->FUN_00709430(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((extra9))->HasEffect(6)) > 0.0)
                {
                    total2 = reinterpret_cast<::FUN_004fe160_cls *>((weapon5))->GetFlaggedValue(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((extra9))->HasEffect(2));
                    useInventory5 = false;
                }
                if (((::TESBoundObject *)(reinterpret_cast<::AmmoOwner *>((weapon5))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer)))))) && data3)
                {
                    current4 = ((int)(reinterpret_cast<::Callees *>((data3))->FUN_00726070()));
                    if (useInventory5)
                        total2 =
                            reinterpret_cast<::FUN_004c8f30_shell *>((((::AmmoInventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer))))))))->FUN_004c8f30((int)(((::TESBoundObject *)(reinterpret_cast<::AmmoOwner *>((weapon5))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer)))))))) - current4;
                }
                else if (reinterpret_cast<::FUN_00474a80_Class *>(&(weapon5->flags))->FUN_00474a80())
                {
                    current4 = reinterpret_cast<::RockItAmmoCountDetail::PlayerView *>(((*reinterpret_cast<::AmmoPlayer * *>(&::_g_thePlayer))))->FUN_00969040();
                    total2 = current4;
                }
            }
            break;
            }
            if (::FUN_006450c0((::TESObjectWEAP *)(weapon5)))
                reinterpret_cast<::Tile *>((tiles[12]))->Set(4003, 0);
            else if (ammoLastCurrent != current4 || ammoLastTotal != total2 || ammoLastWeapon != weapon5)
            {
                ::FUN_00406d00(ammoCountText, 260, ::UNK_010714ec, (int)current4, (int)total2);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tiles[12]))->FUN_00a01350(4036, (char *)(ammoCountText), true);
                reinterpret_cast<::Tile *>((tiles[12]))->Set(4003, 1);
                ammoLastCurrent = current4;
                ammoLastTotal = total2;
            }
            if (ammoLastWeapon != weapon5)
            {
                reinterpret_cast<::Tile *>((tiles[9]))->Set(4003, 1);
                reinterpret_cast<::Tile *>((tiles[10]))->Set(4003, 1);
                reinterpret_cast<::Tile *>((tiles[11]))->Set(4003, 1);
                reinterpret_cast<::Tile *>((tiles[86]))->Set(4003, 1);
                ammoLastWeapon = weapon5;
                if (ammoNameShowing)
                    reinterpret_cast<::fnv_0077f890::HUDMainMenuS *>(this)->ShiftTileValues(50);
                ammoNameShowing = false;
            }
            float ammoValue2 = reinterpret_cast<::FUN_004bcdb0_shell *>((extra9))->FUN_004bcdb0(0);
            float conditionA = reinterpret_cast<::FUN_004bcdb0_shell *>((extra9))->FUN_004bcdb0(1);
            if (conditionA < 25.0)
            {
                ::FUN_005330e0(&timer, 0.0f, flashTime_);
                if (timer == 0.0 || timer == flashTime_)
                    ammoFlashDirection = !ammoFlashDirection;
                if (ammoFlashDirection)
                    timer -= flashTime_ / 255.0 * 10.0;
                else
                    timer += flashTime_ / 255.0 * 10.0;
            }
            else
                timer = flashTime_;
            reinterpret_cast<::FUN_00a012d0_t *>((tiles[10]))->FUN_00a012d0(4009, timer, true);
            if (ammoLastCondition != conditionA)
            {
                float value5 = reinterpret_cast<::FUN_004bcdb0_shell *>((extra9))->FUN_004bcdb0(0);
                float base2 = reinterpret_cast<::FUN_004bcf00_stand *>((weapon5))->GetModdedValue(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((extra9))->HasEffect(10));
                ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(tiles[10]), ::FUN_0040ebd0(1.0f, ::FUN_00404010(0.0f, value5 / base2)), 0, 0, ammoNameShowing ? -50 : 0);
                ammoLastCondition = conditionA;
            }
        }
        else
        {
            ammoLastCurrent = FLT_MIN;
            ammoLastTotal = FLT_MIN;
            ammoLastWeapon = 0;
            ammoLastCondition = FLT_MIN;
            reinterpret_cast<::Tile *>((ammoHUD->tiles[12]))->Set(4003, 0);
            reinterpret_cast<::Tile *>((tiles[10]))->Set(4003, 0);
            reinterpret_cast<::Tile *>((tiles[11]))->Set(4003, 0);
            reinterpret_cast<::Tile *>((ammoHUD->tiles[9]))->Set(4003, 0);
            reinterpret_cast<::Tile *>((tiles[86]))->Set(4003, 0);
        }
    }
}

#include <math.h>
namespace fnv_00779070 {
extern "C" float __cdecl fabsf(float);
struct CompassPoint
{
    float x, y, z;
    CompassPoint operator-(const CompassPoint& arPt) const;
    float Length() const;
};
struct CompassTile;
struct CompassInfo
{
};
struct CompassProcess
{
};
struct CompassAV
{
    virtual void v0();
    virtual void v1();
    virtual int GetValue(int aiAV);
};
struct CompassList;
struct CompassRef
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
    virtual void SetFlag(unsigned int aFlag);
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
    virtual void* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const CompassPoint* GetPos();
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
    virtual bool IsDead(bool abCheck);
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
    virtual float GetAngleZ(int aiUnk);
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
    virtual void RewardXP(int aiXP);
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
    CompassAV kAV;
    int GetFormType();
};
struct CompassMarker
{
    CompassInfo* pInfo;
    CompassRef* pRef;
};
struct CompassQuestTarget
{
};
struct CompassActor
{
    CompassRef* pActor;
    bool m_bIsEnemy;
    bool bHidden;
};
struct CompassEvent
{
    CompassRef* pRef;
    bool bSkip;
    bool bNew;
};
struct CompassList
{
    bool IsEmpty();
    unsigned int Count();
    void Sort(int(__cdecl* apFunc)(void*, void*));
};
struct CompassNode;
struct CompassTiles
{
    TileX** NextQuestTile(CompassNode** appIter);
};
struct CompassTileList
{
    int unk00;
    CompassTiles kTiles;
};
struct CompassArrow
{
};
struct CompassMode
{
    int GetMode();
};
struct CompassMovie
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual CompassArrow* GetArrow();
};
struct CompassSetting
{
    bool* Bool();
};
struct CompassFlags
{
};
extern CompassSetting DAT_011d9774;
extern float DAT_011d979c;
extern bool DAT_011d96c4;

// Updates compass tile positions, visibility, and fade for map markers, quest targets, the player marker, and nearby actors.
// @fnv 0x00779070
void __cdecl FUN_00779070(CompassMovie* apMovie, CompassTileList* apMapTiles, CompassTileList* apQuestTiles,
                          CompassTileList* apActorTiles)
{
    static int iDistanceID = ::FUN_00a00940("_Distance", -1);
    static int iHeadingID = ::FUN_00a00940("_Heading", -1);
    static int iAlphaDownID = ::FUN_00a00940("_AlphaDown", -1);
    float fAngleDeg =
        (((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))->GetAngleZ(0) + reinterpret_cast<::TESObjectCELL_Ext *>((((::fnv_00779070::CompassProcess *)(reinterpret_cast<::LowProcess *>((((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->GetTarget()))))->FUN_00555ad0()) *
        57.2957763671875;
    float fRatio = ::LinearInterpolate(0, 1, 0, 360, fAngleDeg - (int)(fabsf(fAngleDeg) / 360.0) * 360);
    float fPathHeading = fRatio - 0.15000000596046448;
    if (apMovie->GetArrow())
        reinterpret_cast<::FUN_0077a450_class *>((apMovie->GetArrow()))->SetFloats(fPathHeading < 0.0 ? fPathHeading + 1.0 : fPathHeading, 0);
    CompassList* pEntryList = ((::fnv_00779070::CompassList *)(reinterpret_cast<::FUN_00948030_Class *>((((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->FUN_00948030()));
    CompassPoint kPt = *((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))->GetPos();
    TileX* pTileElem = 0;
    float fFadeStart = HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList * 0.800000011920929 * 2.0;
    float m_fGlyphWidthInPixels = HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList * 2.0;
    float fAlpha = (!((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::fnv_00779070::CompassFlags *>(&::g_011f2250))))->GetName())) ? *((float *)&(::FUN_00403e20((float *)&(DAT_011d9774)))) : 1.0f) * 255.0;
    int iFlag = 1;
    CompassNode* pWalk = ((::fnv_00779070::CompassNode *)(::FUN_00559450((int *)&(apMapTiles->kTiles))));
    CompassList* pLandmarkIterator = pEntryList;
    bool bOnce = true;
    bool bCompassReferenceDead = ((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))->IsDead(false);
    int iFarDst = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::g_011d12cc))))));
    iFarDst = iFarDst * iFarDst;
    while (pLandmarkIterator && *((void **)(new ((void *)(pLandmarkIterator)) ::Vec3())))
    {
        CompassMarker* pCompassMarker = (CompassMarker*)*((void **)(new ((void *)(pLandmarkIterator)) ::Vec3()));
        pLandmarkIterator = ((::fnv_00779070::CompassList *)(reinterpret_cast<::Callees *>((pLandmarkIterator))->FUN_00726070()));
        if (reinterpret_cast<::TESForm *>((pCompassMarker->pRef))->GetDisabled())
            continue;
        CompassPoint kPosition = *pCompassMarker->pRef->GetPos();
        float fLen = fabsf(reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_00779070::CompassPoint &)((kPosition - kPt)))->UpdateCombatStyle());
        if (fLen > iFarDst)
            continue;
        bool bDiscovered = false;
        bool bVisible = reinterpret_cast<::MapMarkerData *>((pCompassMarker->pInfo))->IsTravelLocation();
        float fRadius = reinterpret_cast<::fnv_00568cb0::FUN_00568cb0_shell *>((pCompassMarker->pRef))->FUN_00568cb0();
        fRadius = fRadius * fRadius;
        if (fLen < fRadius)
        {
            if (!reinterpret_cast<::MapMarkerData *>((pCompassMarker->pInfo))->GetVisible())
            {
                bDiscovered = true;
                reinterpret_cast<::MapMarkerData *>((pCompassMarker->pInfo))->SetVisible(true);
                pCompassMarker->pRef->SetFlag(0x80000000);
            }
            if (!bVisible)
            {
                bDiscovered = true;
                reinterpret_cast<::MapMarkerData *>((pCompassMarker->pInfo))->SetTravelLocation(true);
                pCompassMarker->pRef->SetFlag(0x80000000);
            }
        }
        if (!bCompassReferenceDead)
        {
            CompassEvent kEvent;
            kEvent.pRef = pCompassMarker->pRef;
            kEvent.bSkip = false;
            if (bDiscovered)
            {
                ::FUN_0076b960(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::g_011d2208))))->GetMenuTitle())), reinterpret_cast<::StringHolder *>((pCompassMarker->pInfo))->FUN_00438eb0(), 1, 0, -1, -1, "UIPopUpQuestNew");
                ::ChallengeManager::UpdateChallengeProgress((::CHALLENGE_TYPE)(4), 1, (::TESForm *)(pCompassMarker->pRef), (::TESForm *)(pCompassMarker->pRef), 0, 0, 0);
                ::TopicMenuController::IncrementMiscStat(true);
                ((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))->RewardXP(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::g_011d0364)))))));
                kEvent.bSkip = false;
                kEvent.bNew = true;
            }
            else if (bVisible)
            {
                kEvent.bSkip = fLen < fRadius;
                kEvent.bNew = false;
            }
            if (!kEvent.bSkip)
                ::UpdateMapMarkerHUD((::MarkerEvent772 *)(::fnv_00779070::CompassEvent *)(&kEvent));
            else if (bOnce && bDiscovered)
            {
                ::UpdateMapMarkerHUD((::MarkerEvent772 *)(::fnv_00779070::CompassEvent *)(&kEvent));
                bOnce = false;
            }
        }
        if (pWalk)
        {
            pTileElem = *((::TileX **)(reinterpret_cast<::ListStandIn *>(&(apMapTiles->kTiles))->FUN_0057cbe0((int **)(::fnv_00779070::CompassNode **)(&pWalk))));
            if (bVisible)
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTileElem))->FUN_00a01350(4044, (char *)("Interface\\HUD\\glow_hud_compass_landmark_discovered.dds"), true);
            else
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTileElem))->FUN_00a01350(4044, (char *)("Interface\\HUD\\glow_hud_compass_landmark.dds"), true);
        }
        else
            continue;
        if (pTileElem)
        {
            float fMapAngle = ::fnv_00778b80::ComputeObjectAngleDelta((*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kPosition)), (*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kPt)));
            if (fabsf(fMapAngle) < HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
            {
                float fMapX = ::LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                                -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                                HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fMapAngle);
                reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(iHeadingID, fMapX, true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(iDistanceID, fLen, true);
                reinterpret_cast<::Tile *>((pTileElem))->Set(4003, 1);
                if (fMapX > fFadeStart)
                    reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(4009, ::LinearInterpolate(1, 0, fFadeStart, m_fGlyphWidthInPixels, fMapX) * fAlpha, true);
                else if (fLen < 10000.0)
                    ::fnv_00778c20::FUN_00778c20((::fnv_00778c20::Tile179 *)(pTileElem), fLen, DAT_011d979c);
                else
                    reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(4009, fAlpha, true);
            }
            else
                reinterpret_cast<::Tile *>((pTileElem))->Set(4003, 0);
        }
    }
    while (pWalk)
    {
        TileX* pMapRest = *((::TileX **)(reinterpret_cast<::ListStandIn *>(&(apMapTiles->kTiles))->FUN_0057cbe0((int **)(::fnv_00779070::CompassNode **)(&pWalk))));
        reinterpret_cast<::Tile *>((pMapRest))->Set(4003, 0);
    }
    HUDMainMenu_pme->m_pRegionObjectListObj = ((::fnv_00779070::CompassList *)(reinterpret_cast<::fnv_00952ba0::PlayerCharacterStandIn *>((((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->FUN_00952ba0()));
    pWalk = ((::fnv_00779070::CompassNode *)(reinterpret_cast<::Callees *>(&(apQuestTiles->kTiles))->FUN_00726070()));
    CompassList* pQuestIt = (CompassList*)HUDMainMenu_pme->m_pRegionObjectListObj;
    float fObjRad = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::g_011d0bd8))))));
    fObjRad = fObjRad * fObjRad;
    while (pQuestIt && *((void **)(new ((void *)(pQuestIt)) ::Vec3())))
    {
        bool bSpecial = false;
        CompassQuestTarget* pTarget = (CompassQuestTarget*)*((void **)(new ((void *)(pQuestIt)) ::Vec3()));
        pQuestIt = ((::fnv_00779070::CompassList *)(reinterpret_cast<::Callees *>((pQuestIt))->FUN_00726070()));
        CompassRef* pRef = ((::fnv_00779070::CompassRef *)(reinterpret_cast<::FUN_005cbb70_shell *>((pTarget))->FUN_005cbb70()));
        if (pRef && pRef->GetFormType() == 28)
            bSpecial = true;
        if (pRef && *(*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::g_011e07f0)).Bool())
        {
            CompassPoint kQuestPos = *pRef->GetPos();
            float fTgtDst = fabsf(reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_00779070::CompassPoint &)((kQuestPos - kPt)))->UpdateCombatStyle());
            float fQuestOpacity = fAlpha;
            if (fTgtDst != 0.0)
                fQuestOpacity =
                    ::LinearInterpolate(fAlpha / 2.0, fAlpha, ((double)(::FUN_0040ebd0(fTgtDst, fObjRad))) / fObjRad, 0, fTgtDst);
            if (pWalk)
            {
                pTileElem = *apQuestTiles->kTiles.NextQuestTile(&pWalk);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTileElem))->FUN_00a01350(4044, (char *)("Interface\\HUD\\glow_hud_compass_objective_marker.dds"), true);
            }
            else
                continue;
            if (pTileElem)
            {
                float fQuestAngle = ::fnv_00778b80::ComputeObjectAngleDelta((*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kQuestPos)), (*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kPt)));
                if (fQuestAngle > HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
                    fQuestAngle = HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList;
                else if (fQuestAngle < -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
                    fQuestAngle = -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList;
                float fX = ::LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                             -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                             HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fQuestAngle);
                if (fFadeStart + 70.0 < fX)
                    fX = fFadeStart + 70.0;
                reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(iHeadingID, fX, true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(iDistanceID, fTgtDst, true);
                reinterpret_cast<::Tile *>((pTileElem))->Set(4003, 1);
                if (((int)(reinterpret_cast<::ActorMover *>((((::fnv_00779070::CompassMode *)(reinterpret_cast<::FUN_00a03c90_shell *>((apMovie))->FUN_00a03c90()))))->GetCurrentMoveModeType())) == 1)
                {
                    if (!bSpecial)
                        ::fnv_00778c20::FUN_00778c20((::fnv_00778c20::Tile179 *)(pTileElem), fTgtDst, DAT_011d979c);
                    else
                        reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(4009, fAlpha, true);
                }
            }
        }
    }
    if (((::fnv_00779070::CompassRef *)(reinterpret_cast<::C77a400 *>((((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->GetFirstOrFallback())) && pWalk)
    {
        pTileElem = *apQuestTiles->kTiles.NextQuestTile(&pWalk);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTileElem))->FUN_00a01350(4044, (char *)("Interface\\HUD\\glow_hud_compass_pc_marker.dds"), true);
        if (pTileElem)
        {
            CompassPoint kPCPos = *((::fnv_00779070::CompassRef *)(reinterpret_cast<::C77a400 *>((((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->GetFirstOrFallback()))->GetPos();
            kPCPos.z = kPt.z;
            float fPCDist = fabsf(reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_00779070::CompassPoint &)((kPCPos - kPt)))->UpdateCombatStyle());
            float fPCAngle = ::fnv_00778b80::ComputeObjectAngleDelta((*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kPCPos)), (*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kPt)));
            if (fabsf(fPCAngle) < HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
            {
                float fPCX = ::LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                               -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                               HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fPCAngle);
                reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(iHeadingID, fPCX, true);
                reinterpret_cast<::Tile *>((pTileElem))->Set(4003, 1);
                if (fPCX > fFadeStart)
                {
                    float fPCOpacity = ::LinearInterpolate(fAlpha, 0, fFadeStart, m_fGlyphWidthInPixels, fPCX);
                    ::fnv_00778c20::FUN_00778c20((::fnv_00778c20::Tile179 *)(pTileElem), fPCDist, fPCOpacity);
                }
                else
                    ::fnv_00778c20::FUN_00778c20((::fnv_00778c20::Tile179 *)(pTileElem), fPCDist, DAT_011d979c);
            }
            else
                reinterpret_cast<::Tile *>((pTileElem))->Set(4003, 0);
        }
    }
    while (pWalk)
    {
        TileX* pQuestRest = *apQuestTiles->kTiles.NextQuestTile(&pWalk);
        reinterpret_cast<::Tile *>((pQuestRest))->Set(4003, 0);
    }
    DAT_011d96c4 = false;
    pWalk = ((::fnv_00779070::CompassNode *)(::FUN_00559450((int *)&(apActorTiles->kTiles))));
    CompassList* pActors = ((::fnv_00779070::CompassList *)(reinterpret_cast<::FUN_00595d10_shell *>((((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->FUN_00595d10()));
    bool bSneakOn = reinterpret_cast<::TESObjectCELL *>((((::fnv_00779070::CompassProcess *)(reinterpret_cast<::LowProcess *>((((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->GetTarget()))))->IsCellInterior();
    float fStealthDst = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::originalRuntimeFloatSetting87))))));
    fStealthDst = fStealthDst * fStealthDst;
    float fWalkDst = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::originalRuntimeFloatSetting101)))))) * *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::originalRuntimeFloatSetting87))))));
    fWalkDst = fWalkDst * fWalkDst;
    unsigned int uiShown = pActors->Count();
    if (pActors->Count() > (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::g_011d32d0)))))))
    {
        reinterpret_cast<::ItemChangeList *>((pActors))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(((int (&)(void *, void *))::fnv_0077b300::FUN_0077b300)));
        uiShown = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00779070::CompassSetting *>(&::g_011d32d0))))));
    }
    while (pActors && !pActors->IsEmpty() && uiShown)
    {
        uiShown = uiShown - 1;
        CompassActor* pActor = (CompassActor*)*((void **)(new ((void *)(pActors)) ::Vec3()));
        if (!pActor || pActor->bHidden || !pActor->pActor->Get3D() || !((::fnv_00779070::CompassProcess *)(reinterpret_cast<::LowProcess *>((pActor->pActor))->GetTarget())) ||
            !::FUN_00450ff0((void *)(((::fnv_00779070::CompassProcess *)(reinterpret_cast<::LowProcess *>((pActor->pActor))->GetTarget())))))
        {
            pActors = ((::fnv_00779070::CompassList *)(reinterpret_cast<::Callees *>((pActors))->FUN_00726070()));
            continue;
        }
        if (pActor->pActor->kAV.GetValue(49) || pActor->pActor->kAV.GetValue(48))
        {
            float fPerk = 0;
            ::ApplyPerkModifiers(69, (::Actor *)(::fnv_00779070::CompassRef *)((CompassRef*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer))), &fPerk);
            if (fPerk <= 0.0)
            {
                pActors = ((::fnv_00779070::CompassList *)(reinterpret_cast<::Callees *>((pActors))->FUN_00726070()));
                continue;
            }
        }
        CompassPoint kActorPt = *pActor->pActor->GetPos();
        float fActorDist = fabsf(reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::fnv_00779070::CompassPoint &)((kActorPt - kPt)))->UpdateCombatStyle());
        if ((bSneakOn && fActorDist > fStealthDst) || (!bSneakOn && fActorDist > fWalkDst))
        {
            pActors = ((::fnv_00779070::CompassList *)(reinterpret_cast<::Callees *>((pActors))->FUN_00726070()));
            continue;
        }
        if (fActorDist < iFarDst)
        {
            if (pWalk)
            {
                pTileElem = *((::TileX **)(reinterpret_cast<::ListStandIn *>(&(apActorTiles->kTiles))->FUN_0057cbe0((int **)(::fnv_00779070::CompassNode **)(&pWalk))));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTileElem))->FUN_00a01350(4044, (char *)("Interface\\HUD\\glow_hud_tick_mark.dds"), true);
            }
            else
                continue;
            if (pTileElem)
            {
                float fActorAngle = ::fnv_00778b80::ComputeObjectAngleDelta((*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kActorPt)), (*(::fnv_00778b80::NiPoint3 *)&(const ::fnv_00779070::CompassPoint &)(kPt)));
                if (fabsf(fActorAngle) < HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
                {
                    float fActorX = ::LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                                      -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                                      HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fActorAngle);
                    reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(iHeadingID, fActorX + 2.0, true);
                    reinterpret_cast<::Tile *>((pTileElem))->Set(4003, 1);
                    if (pActor->m_bIsEnemy)
                    {
                        reinterpret_cast<::Tile *>((pTileElem))->Set(4084, 2);
                        DAT_011d96c4 = true;
                    }
                    else
                        reinterpret_cast<::Tile *>((pTileElem))->Set(4084, 1);
                    if (fActorX > fFadeStart)
                        reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(4009, ::LinearInterpolate(fAlpha, 0, fFadeStart, m_fGlyphWidthInPixels, fActorX), true);
                    else
                        reinterpret_cast<::FUN_00a012d0_t *>((pTileElem))->FUN_00a012d0(4009, fAlpha, true);
                }
                else
                    reinterpret_cast<::Tile *>((pTileElem))->Set(4003, 0);
            }
        }
        pActors = ((::fnv_00779070::CompassList *)(reinterpret_cast<::Callees *>((pActors))->FUN_00726070()));
    }
    while (pWalk)
    {
        TileX* pActorRest = *((::TileX **)(reinterpret_cast<::ListStandIn *>(&(apActorTiles->kTiles))->FUN_0057cbe0((int **)(::fnv_00779070::CompassNode **)(&pWalk))));
        reinterpret_cast<::Tile *>((pActorRest))->Set(4003, 0);
    }
}
}  // namespace fnv_00779070

namespace fnv_00771700 {
class VisibilityTile
{
  public:
};
class NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class VisibilityPlayer
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
    virtual int GetMode();
};

class VisibilityHUD : public HUDMainMenu
{
  public:
};
struct VisibilityMode
{
};
class InterfaceManager
{
  public:
};
struct SndX
{
    bool IsValid();
};
extern HUDMainMenu* HUDMainMenu_pme;
extern VisibilityPlayer* _g_thePlayer;
extern NiPointer<NiNode> DAT_011d9770;
extern bool DAT_011d96bb;
extern const double DAT_01073488;

// Selects a HUD mode from the requested value and player state, then updates HUD flags, tile traits, and a sound handle.
// @fnv 0x00771700
void __cdecl FUN_00771700(int aiMenuMode)
{
    if (!HUDMainMenu_pme)
        return;
    int state = aiMenuMode;
    if (((int)(reinterpret_cast<::ActorMover *>((((VisibilityHUD*)HUDMainMenu_pme)))->GetCurrentMoveModeType())) != 1)
        reinterpret_cast<::FUN_00a1db20_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00a1db20();
    if (state == 1)
    {
        int iMenuId = ::fnv_007023c0::FUN_007023c0();
        switch (iMenuId)
        {
        case 1002:
        case 1003:
        case 1014:
        case 1023:
        case 1035:
        case 1061:
            state = 3;
            break;
        case 1013:
            state = 4;
            break;
        case 1007:
            state = 5;
            break;
        case 0:
        case 1004:
            if ((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))->GetMode() == 4 || (*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))->GetMode() == 9)
                state = 11;
            else if ((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))->GetMode())
                state = 10;
            else if (((int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::fnv_00771700::VisibilityMode *>(&::g_011f2250))))->GetName())) == 4)
                state = 8;
            else if (reinterpret_cast<::FUN_005a03f0_obj *>(((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))))->FUN_005a03f0(1))
                FUN_00771700(12);
            else if (reinterpret_cast<::FUN_008bbc10_shell *>(((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))))->FUN_008bbc10())
                state = 22;
            else
                state = 2;
            break;
        case 1009:
            state = 6;
            break;
        case 1056:
            state = 7;
            break;
        case 1008:
            state = 9;
            break;
        case 1012:
            state = 11;
            break;
        case 1055:
            state = 15;
        case 1057:
            state = 16;
        }
    }
    if (state == 22 && DAT_011d9770 && ((::fnv_00771700::NiNode *)(reinterpret_cast<::S_FUN_0045bc00 *>(((DAT_011d9770).operator->()))->FUN_0045bc00(0))) && reinterpret_cast<::FUN_008a16d0_shell *>(((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))))->FUN_008a16d0())
        state = 23;
    if (state != 24 && state != 4 && state != 5 && reinterpret_cast<::FUN_005a03f0_obj *>(((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))))->FUN_005a03f0(1))
    {
        if (::FUN_00719ae0((void *)(((::fnv_00771700::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))
            state = 2;
        else if (state == 6)
            state = 6;
        else
            state = 12;
    }
    switch (state)
    {
    case 2:
    case 13:
    case 20:
    case 22:
        if (reinterpret_cast<::FUN_005a03f0_obj *>(((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer))))->FUN_005a03f0(32))
            HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1fdff;
        else
            HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1ffff;
        ::HUDMainMenu::RefreshTargetDisplay();
        break;
    case 3:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x100;
        break;
    case 4:
    case 5:
    case 14:
    case 17:
    case 18:
    case 21:
    case 24:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0;
        break;
    case 19:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0;
        break;
    case 25:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0;
        break;
    case 9:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1000;
        break;
    case 12:
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1514;
        break;
    case 6:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1110;
        break;
    case 7:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x100;
        break;
    case 8:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x108;
        break;
    case 23:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 8;
        break;
    case 11:
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x11fff;
        break;
    case 10:
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x11dbf;
        break;
    case 15:
    case 16:
        reinterpret_cast<::FUN_00775670_shell *>((((VisibilityHUD*)HUDMainMenu_pme)))->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1010;
    }
    HUDMainMenu_pme->m_iHudValueFirstBeforeMode &= HUDMainMenu_pme->m_iHudValueSecondBeforeMode;
    if (DAT_011d96bb)
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode &= ~8;
    if ((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer)) && ((::fnv_00771700::NiNode *)(::FUN_007721a0((char *)((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer)))))) && !::FUN_00524d10((bool *)((*reinterpret_cast<::fnv_00771700::VisibilityPlayer * *>(&::_g_thePlayer)))))
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode &= ~64;
    if (state == 6)
    {
        float scopeY = reinterpret_cast<::TileListBoxCalls *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])))->GetFloat(4103);
        reinterpret_cast<::FUN_00a012d0_t *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])))->FUN_00a012d0(4002, scopeY - DAT_01073488, true);
    }
    else
    {
        float normalY = reinterpret_cast<::TileListBoxCalls *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])))->GetFloat(4103);
        reinterpret_cast<::FUN_00a012d0_t *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])))->FUN_00a012d0(4002, normalY, true);
    }
    if (HUDMainMenu_pme->m_eHudMenuMode != 23 && state == 23)
        ::fnv_0077f3c0::SetHudVisible(true);
    else if (HUDMainMenu_pme->m_eHudMenuMode == 23 && state != 23)
        ::fnv_0077f3c0::SetHudVisible(false);
    HUDMainMenu_pme->m_eHudMenuMode = state;
    if (HUDMainMenu_pme->m_eHudMenuMode != 20 && HUDMainMenu_pme->m_eHudMenuMode != 6 &&
        HUDMainMenu_pme->m_eHudMenuMode != 2 && HUDMainMenu_pme->m_eHudMenuMode != 5 &&
        HUDMainMenu_pme->m_eHudMenuMode != 14 && HUDMainMenu_pme->m_eHudMenuMode != 17 &&
        HUDMainMenu_pme->m_eHudMenuMode != 9 && HUDMainMenu_pme->m_eHudMenuMode != 11 &&
        HUDMainMenu_pme->m_eHudMenuMode != 18 && HUDMainMenu_pme->m_eHudMenuMode != 19 &&
        HUDMainMenu_pme->m_eHudMenuMode != 25)
        HUDMainMenu_pme->m_bQuestObjectiveUpdatesEnabled = true;
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[59])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[60])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x2);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[61])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x4);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[62])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x8);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[63])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x10);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[64])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x20);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[65])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x40);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[66])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x80);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[67])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x100);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[68])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x200);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[69])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x400);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[70])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x800);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1000);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[72])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x2000);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[73])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x4000);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[74])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x8000);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[77])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[78])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x10000);
    reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[86])))->Set(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1);

    if (!(HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 1))
    {
        reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[75])))->Set(4003, 0);
        reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[82])))->Set(4003, 0);
    }
    if (!(HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 8))
    {
        reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[76])))->Set(4003, 0);
        reinterpret_cast<::Tile *>((((VisibilityTile*)HUDMainMenu_pme->m_pTiles[83])))->Set(4003, 0);
    }
    if (reinterpret_cast<::SoundPlaybackHandle *>((((SndX*)HUDMainMenu_pme->m_kTargetDisplayData)))->IsValid())
    {
        if (HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 4)
            reinterpret_cast<::FUN_00ad8830_shell *>((((SndX*)HUDMainMenu_pme->m_kTargetDisplayData)))->FUN_00ad8830(false);
        else
            reinterpret_cast<::FUN_00ad88b0_h *>((((SndX*)HUDMainMenu_pme->m_kTargetDisplayData)))->FUN_00ad88b0();
    }
}
}  // namespace fnv_00771700

namespace fnv_0077da60 {
class HotkeyTile
{
  public:
};

struct HotkeyWheel
{
};

struct HotkeyItem
{
    ~HotkeyItem();
};

struct HotkeyList
{
};

struct HUDPlayer
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
    virtual void v74();
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
    virtual bool FUN_vt22c(int aiMode);
};

struct HUDInterface
{
};

struct HUDInput
{
};

struct HUDGlobals
{
};

struct HUDTimer
{
};

struct HUDSetting
{
    float* FUN_00403e20();
};

extern bool DAT_011d9e90;
extern int DAT_011d9e8c;
extern int DAT_011a0124;

class InterfaceManager;

static const char s_szNameCount[] = "%s (%d)";
static const char s_szIconVisible[] = "_IconVisible";
static const char s_szIconFilename[] = "_IconFilename";
static const char s_szBlank[] = " ";

struct HUDHotkeys : HUDMainMenu
{
    void FUN_0077da60();
};

// Updates hotkey wheel selection, tile labels, and icon visibility based on input state and timer thresholds.
// @fnv 0x0077da60
void HUDHotkeys::FUN_0077da60()
{
    if (!reinterpret_cast<::FUN_007023a0_shell *>((((HUDInterface*)((::fnv_0077da60::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_007023a0() && !(*reinterpret_cast<::fnv_0077da60::HUDPlayer * *>(&::_g_thePlayer))->FUN_vt22c(0) &&
        !reinterpret_cast<::FUN_005a03f0_obj *>(((*reinterpret_cast<::fnv_0077da60::HUDPlayer * *>(&::_g_thePlayer))))->FUN_005a03f0(4))
    {
        if (::FUN_004b71d0())
        {
            int iSelected = reinterpret_cast<::HWShell *>((((HotkeyWheel*)m_kMenuData)))->FUN_00701bd0(-1);
            if (!DAT_011d9e90 && iSelected >= 0)
            {
                reinterpret_cast<::HotkeyWheelUpdate *>((((HotkeyWheel*)m_kMenuData)))->FUN_007017b0();
                DAT_011d9e90 = true;
                DAT_011d9e8c = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077da60::HUDTimer *>(&::g_timeGlobal))))->FUN_00825c00();
            }
            if (DAT_011d9e90)
            {
                if (iSelected >= 0)
                {
                    if (DAT_011d9e8c > 0 &&
                        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077da60::HUDTimer *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011d9e8c > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0077da60::HUDSetting *>(&::originalRuntimeFloatSetting1225)))))) * 1000.0 &&
                        !reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->GetVisible())
                    {
                        reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->SetVisible(true);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[44])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[45])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[46])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[47])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[48])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[49])))->Set(0xfa3, 0);
                    }
                    if (reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->GetVisible() && iSelected != DAT_011a0124)
                    {
                        HotkeyList* pListOld = ((::fnv_0077da60::HotkeyList *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::fnv_0077da60::HUDPlayer * *>(&::_g_thePlayer))))));
                        HotkeyItem* pFinalItem = pListOld ? ((::fnv_0077da60::HotkeyItem *)(reinterpret_cast<::InventoryChangesIter *>((pListOld))->FindEntryWithExtraListType(iSelected))) : 0;
                        bool bHasIcon = false;
                        const char* pIcon = 0;
                        char acNameVal[260];
                        if (pFinalItem)
                        {
                            pIcon = reinterpret_cast<::ItemChange_004be200 *>((pFinalItem))->GetIconFilename((::TESObjectREFR *)(0));
                            if (pIcon)
                                bHasIcon = true;
                            if (((int)(reinterpret_cast<::Callees *>((pFinalItem))->FUN_00726070())) > 1)
                                ::FUN_00406d00(acNameVal, 260, s_szNameCount, reinterpret_cast<::FUN_004be2d0_shell *>((pFinalItem))->GetTargetFullName(),
                                             ((int)(reinterpret_cast<::Callees *>((pFinalItem))->FUN_00726070())));
                            else
                                ::TaskQueueInterface::CopyStringToBuffer(acNameVal, 260, reinterpret_cast<::FUN_004be2d0_shell *>((pFinalItem))->GetTargetFullName());
                            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HotkeyTile*)m_pTiles[41])))->FUN_00a01350(0xfc4, (char *)(acNameVal), true);
                            reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[41])))->Set(0xfa3, 1);
                        }
                        else
                        {
                            reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[41])))->Set(0xfa3, 0);
                        }
                        if (!bHasIcon)
                        {
                            reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[40])))->Set(::FUN_00a01860(s_szIconVisible), 0);
                        }
                        else
                        {
                            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HotkeyTile*)m_pTiles[40])))->FUN_00a01350(::FUN_00a01860(s_szIconFilename), (char *)(pIcon), true);
                            reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[40])))->Set(::FUN_00a01860(s_szIconVisible), 1);
                        }
                        DAT_011a0124 = iSelected;
                        delete pFinalItem;
                    }
                }
                else
                {
                    reinterpret_cast<::Wheel *>((((HotkeyWheel*)m_kMenuData)))->FUN_00701e80();
                    reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->SetVisible(false);
                    reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[41])))->Set(0xfa3, 0);
                    DAT_011d9e8c = 0;
                    DAT_011d9e90 = false;
                    DAT_011a0124 = -1;
                }
            }
        }
        else
        {
            for (int i = 0; i < reinterpret_cast<::CombatProcedureActivateObject *>((((HotkeyWheel*)m_kMenuData)))->FUN_006e4ba0(); i++)
            {
                if (reinterpret_cast<::HotkeyWheelDisplay *>((((::fnv_0077da60::HUDInput *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0077da60::HUDGlobals * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(i + 0x11, 1))
                {
                    if (i == 1)
                    {
                        reinterpret_cast<::FUN_0061cc40_shell *>((((HotkeyWheel*)m_kMenuData)))->FUN_0061cc40(i);
                        continue;
                    }
                    HotkeyList* pHotkeys = ((::fnv_0077da60::HotkeyList *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::fnv_0077da60::HUDPlayer * *>(&::_g_thePlayer))))));
                    HotkeyItem* pEntry = 0;
                    bool bIconTmp = false;
                    DAT_011d9e8c = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077da60::HUDTimer *>(&::g_timeGlobal))))->FUN_00825c00();
                    reinterpret_cast<::HWShell *>((((HotkeyWheel*)m_kMenuData)))->FUN_00701bd0(i);
                    pEntry = pHotkeys ? ((::fnv_0077da60::HotkeyItem *)(reinterpret_cast<::InventoryChangesIter *>((pHotkeys))->FindEntryWithExtraListType(i))) : 0;
                    const char* pIconPathOld = 0;
                    char acLabel[260];
                    if (pEntry)
                    {
                        pIconPathOld = reinterpret_cast<::ItemChange_004be200 *>((pEntry))->GetIconFilename((::TESObjectREFR *)(0));
                        if (pIconPathOld)
                            bIconTmp = true;
                        if (((int)(reinterpret_cast<::Callees *>((pEntry))->FUN_00726070())) > 1)
                            ::FUN_00406d00(acLabel, 260, s_szNameCount, reinterpret_cast<::FUN_004be2d0_shell *>((pEntry))->GetTargetFullName(), ((int)(reinterpret_cast<::Callees *>((pEntry))->FUN_00726070())));
                        else
                            ::TaskQueueInterface::CopyStringToBuffer(acLabel, 260, reinterpret_cast<::FUN_004be2d0_shell *>((pEntry))->GetTargetFullName());
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HotkeyTile*)m_pTiles[41])))->FUN_00a01350(0xfc4, (char *)(acLabel), true);
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HotkeyTile*)m_pTiles[41])))->FUN_00a01350(0xfc4, (char *)(s_szBlank), true);
                    }
                    if (!bIconTmp)
                    {
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[40])))->Set(::FUN_00a01860(s_szIconVisible), 0);
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((HotkeyTile*)m_pTiles[40])))->FUN_00a01350(::FUN_00a01860(s_szIconFilename), (char *)(pIconPathOld), true);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[40])))->Set(::FUN_00a01860(s_szIconVisible), 1);
                    }
                    delete pEntry;
                }
                else if (reinterpret_cast<::HotkeyWheelDisplay *>((((::fnv_0077da60::HUDInput *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0077da60::HUDGlobals * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(i + 0x11, 0))
                {
                    if (!reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->GetVisible() && DAT_011d9e8c > 0 &&
                        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077da60::HUDTimer *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011d9e8c > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0077da60::HUDSetting *>(&::originalRuntimeFloatSetting1225)))))) * 1000.0 && i != 1)
                    {
                        reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->SetVisible(true);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[41])))->Set(0xfa3, 1);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[44])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[45])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[46])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[47])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[48])))->Set(0xfa3, 0);
                        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[49])))->Set(0xfa3, 0);
                    }
                    if (reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->GetVisible())
                        DAT_011d9e8c = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077da60::HUDTimer *>(&::g_timeGlobal))))->FUN_00825c00();
                }
                else if (reinterpret_cast<::HotkeyWheelDisplay *>((((::fnv_0077da60::HUDInput *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0077da60::HUDGlobals * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(i + 0x11, 2))
                {
                    reinterpret_cast<::Wheel *>((((HotkeyWheel*)m_kMenuData)))->FUN_00701e80();
                    if (!reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->GetVisible())
                        DAT_011d9e8c = 0;
                }
            }
            if (reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->GetVisible() && DAT_011d9e8c > 0 &&
                reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0077da60::HUDTimer *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011d9e8c > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0077da60::HUDSetting *>(&::originalRuntimeFloatSetting1224)))))) * 1000.0)
            {
                reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[41])))->Set(0xfa3, 0);
                reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->SetVisible(false);
                DAT_011d9e8c = 0;
            }
        }
    }
    else
    {
        DAT_011d9e8c = 0;
        reinterpret_cast<::HotkeyWheelDisplay *>((((HotkeyWheel*)m_kMenuData)))->SetVisible(false);
        reinterpret_cast<::Tile *>((((HotkeyTile*)m_pTiles[41])))->Set(0xfa3, 0);
    }
}
}  // namespace fnv_0077da60

class Tile_traitSetter
{
  public:
};

struct HUDMainMenuEx : public HUDMainMenu
{
    void FUN_00775920();
};

extern HUDMainMenuEx* HUDMainMenu_pSingleton;

// Sets trait 4009 to afScale * 255.0 on HUD main menu tiles with indices outside the listed exclusions.
// @fnv 0x0077e430
void __cdecl FUN_0077e430(float afScale)
{
    if (HUDMainMenu_pSingleton)
    {
        HUDMainMenu_pSingleton->FUN_00775920();
        for (int i = 1; i < 59; i++)
        {
            switch (i)
            {
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 24:
            case 25:
            case 26:
            case 27:
            case 44:
            case 50:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
            case 58:
                break;
            default:
                reinterpret_cast<::FUN_00a012d0_t *>((((Tile_traitSetter*)HUDMainMenu_pSingleton->m_pTiles[i])))->FUN_00a012d0(4009, afScale * 255.0, true);
                break;
            }
        }
    }
}

struct VATSCreatePointX
{
    float x, y, z;
    VATSCreatePointX& operator*=(float afScale);
    VATSCreatePointX& operator+=(const VATSCreatePointX& arPoint);
    VATSCreatePointX operator-(const VATSCreatePointX& arPoint) const;
};
struct VATSCreateMatrixX
{
    float m[9];
};
struct VATSCreateNodeArgX;
struct VATSCreateTexX;
struct VATSCreateTileX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual VATSCreateNodeArgX* GetNode();
    void Set(int aeID, float afValue, bool abPropagate);
    void Set(int aeID, const char* apValue, bool abPropagate);
};
struct VATSCreateTileMenuX : public VATSCreateTileX
{
};
struct VATSCreateLoaderX
{
};
struct VATSCreateMenuX
{
    virtual ~VATSCreateMenuX();
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
    virtual int GetID();
};
struct VATSCreateActionListX
{
    void Initialize(VATSCreateTileX* apTile, const char* apTemplate);
};
struct VATSCreateLimbX
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    int m_iLimbIndex;
};
template <class T> struct VATSCreateListX
{
    T item;
    VATSCreateListX* next;
    bool IsEmpty();
    T& GetItem();
    VATSCreateListX* GetNext();
    void FUN_00905330(T const& arItem);
    void Sort(int (*apCompare)(void*, void*));
    void RemoveAll();
};
struct VATSCreateRefX;
struct VATSCreateVATSTargetX
{
    VATSCreateRefX* pRef;
    int iType;
    VATSCreateListX<VATSCreateLimbX*> kLimbs;
    int iPad10;
    float m_fTargetAngle;
    float fAngleDifference;
    float fDistance;
    bool bVisible;
};
struct VATSCreateVATSMenuX : public VATSCreateMenuX
{
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
    VATSCreateTileX* m_pTiles[29];
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    bool bDebounce;
    unsigned char unk0ad;
    unsigned char unk0ae;
    unsigned char unk0af;
    VATSCreateActionListX kActions;
    unsigned char unk0b1;
    unsigned char unk0b2;
    unsigned char unk0b3;
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
    unsigned char unk0dc;
    float m_fOverrideActionPoints;
    float m_fValue1;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned char unk0f8;
    bool m_bStateFlag1;
    bool m_bStateFlag2;
    bool m_bStateFlag3;
    unsigned int unk0fc;
    VATSCreateLimbX* m_pTargetChance;
    unsigned int unk104;
    unsigned int unk108;
    bool m_bStateFlag5;
    bool m_bStateFlag9;
    bool m_bAdditionalStateFlag;
    bool m_bStateFlag10;
    bool m_bStateFlag6;
    unsigned char unk111;
    unsigned char unk112;
    unsigned char unk113;
    unsigned int m_uiTargetCount;
    bool b118;
};
struct VATSCreateBaseFormX
{
    int iDummy;
};
struct VATSCreateFormX : public VATSCreateBaseFormX
{
};
struct VATSCreateWeaponX : public VATSCreateBaseFormX
{
    int GetWeaponType() const;
};
struct VATSCreateFormListHeadX
{
    bool IsInList(VATSCreateBaseFormX* const& arForm);
};
struct VATSCreateFormListX
{
};
struct VATSCreateNodeArgX
{
};
struct VATSCreateNode3DX
{
};
struct VATSCreateProcX
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
    virtual VATSCreateFormX* GetEquippedWeapon();
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
    virtual bool IsInDialogue();
};
struct VATSCreateAVOwnerX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float GetActorValue(int aeAV);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual float GetBaseActorValue(int aeAV);
};
struct VATSCreateRefX
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
    virtual void* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const VATSCreatePointX& GetPos();
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
    virtual bool IsMobile();
    virtual void v228();
    virtual bool IsDead(int aiArg);
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
    virtual float GetRange(int aiArg);
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
    virtual int GetMobileType();
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
    VATSCreateAVOwnerX kAVOwner;
};
struct VATSCreateEffectFormX
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
    virtual bool IsValid();
};
struct VATSCreateDataHandlerX
{
};
struct VATSCreateTESX
{
};
struct VATSCreateVATSX
{
};
struct VATSCreateSettingX
{
};
struct VATSCreateHUDManagerX
{
};
struct VATSCreateInterfaceMgrX
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
    VATSCreateHUDManagerX kHUD;
};
struct VATSCreateAudioX
{
};
struct VATSCreateCalendarX
{
};
struct VATSCreateTimerX
{
};
struct VATSCreateFixedStringX
{
    char* m_kHandle;
    VATSCreateFixedStringX(const char* apString);
    ~VATSCreateFixedStringX();
};
struct VATSCreateFormatPrefsX
{
    int a, b, c;
};
struct VATSCreateSourceTextureX
{
};
template <class T> struct VATSCreatePtrX
{
    T* m_pObject;
    VATSCreatePtrX(int aiNull);
    ~VATSCreatePtrX();
    VATSCreatePtrX& operator=(T* apObject);
    operator T*() const;
};
struct VATSCreateStringX
{
    char* pData;
    unsigned short usLen;
    unsigned short usMax;
    VATSCreateStringX();
    ~VATSCreateStringX();
};
struct VATSCreateBSSoundHandleX
{
    unsigned int uiSoundID;
    bool m_bLooping;
    int eState;
    VATSCreateBSSoundHandleX();
    ~VATSCreateBSSoundHandleX();
    VATSCreateBSSoundHandleX& operator=(const VATSCreateBSSoundHandleX& arHandle);
};
struct VATSCreateAudioMgrX
{
};

extern bool VATSCreateDAT_011db0b1, VATSCreateDAT_011db0cc;
extern VATSCreateEffectFormX* VATSCreateDAT_011db0ac;
extern VATSCreateEffectFormX* VATSCreateDAT_011db0b4;
extern const double VATSCreateDAT_01035810;

bool VATSCreateFUN_00702450(int aiMenu);
float VATSCreateFUN_00408840(float afValue);

extern "C" void* __cdecl xRTDynamicCast(void* apObject, long alVfDelta, void* apSrcType, void* apDstType,
                                        int aiIsReference);
extern char xRTTI_VATSMenu[];

// Validates VATS targets, loads the VATS menu XML, builds HUD tiles, and initializes the VATS menu state.
// @fnv 0x007e9200
bool FUN_007e9200()
{
    float qfTOqo;
    VATSCreateFormListX* qsSDDgz;
    VATSCreateTileX* qrEZrs;
    VATSCreateFormListX* qpqRa;
    VATSCreateMenuX* qSVM;
    VATSCreateWeaponX* qdqWL;
    VATSCreateInterfaceMgrX* qpTd;
    ::DAT_011db0b2 = 0;
    ::DAT_011db0b3 = 0;
    VATSCreateDAT_011db0b1 = 0;
    qrEZrs = ((::VATSCreateTileX *)(::FUN_00a09030(::FUN_007eb8c0())));
    (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4)) = (VATSCreateVATSMenuX*)((::VATSCreateMenuX *)(reinterpret_cast<::FUN_00a03c90_shell *>((qrEZrs))->FUN_00a03c90()));
    if ((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4)) || VATSCreateFUN_00702450(0x3f4))
    {
        return false;
    }
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150))))->RemoveAll();
    ::FUN_007f52c0();
    qsSDDgz = ((::VATSCreateFormListX *)(::FUN_004839c0(0x1770bc)));
    {
        VATSCreateListX<VATSCreateVATSTargetX*>* qxQHW = &(*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150));
        while (qxQHW && !qxQHW->IsEmpty())
        {
            VATSCreateFormX* qArxcFu = 0;
            if (((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef->IsActor())
            {
                qArxcFu = ((::VATSCreateFormX *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef))->FUN_007af430()));
            }
            VATSCreateRefX* qGfbX = ((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef->IsActor() ? ((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef : 0;
            VATSCreateRefX* qJDuOZ = ((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef->IsMobile() ? ((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef : 0;
            bool qAhbO = false;
            if (qJDuOZ && qJDuOZ->GetMobileType() == 4)
            {
                VATSCreateRefX* qpia = qJDuOZ;
                if (::FUN_00472380((int)(qpia)) == 3 || ::FUN_00472380((int)(qpia)) == 4)
                {
                    qAhbO = true;
                }
            }
            if ((((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef->IsActor() && ((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef->IsDead(0)) ||
                (qsSDDgz && qArxcFu && reinterpret_cast<::RefList *>((((::VATSCreateFormListHeadX *)(reinterpret_cast<::BGSCameraPath *>((qsSDDgz))->GetConditions()))))->FUN_005f65d0((void **)&(qArxcFu))) || (qGfbX && reinterpret_cast<::FUN_005a2030_shell *>((void *)(qGfbX))->FUN_005a2030()) ||
                qAhbO)
            {
                if ((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21cc)) == ((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))->pRef)
                {
                    (*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21cc)) = 0;
                }
                reinterpret_cast<::ItemChangeListNode *>((qxQHW))->FUN_00905330((::InventoryStackRecord *const &)(((::VATSCreateVATSTargetX *)(new ((void *)(qxQHW)) ::Vec3()))));
            }
            qxQHW = ((::VATSCreateListX< ::VATSCreateVATSTargetX *> *)(reinterpret_cast<::Callees *>((qxQHW))->FUN_00726070()));
        }
    }
    if ((*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150)).IsEmpty())
    {
        if (::DAT_011f21d1)
        {
            reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))))->FUN_00950110(1);
        }
        return false;
    }
    qdqWL = 0;
    if ((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer)) && ((::VATSCreateProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))))->GetBaseTexture())))
    {
        qdqWL = ((::VATSCreateProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetEquippedWeapon()
                    ? ((::VATSCreateWeaponX *)(reinterpret_cast<::Twin_0044ddc0 *>((((::VATSCreateProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetEquippedWeapon()))->GetName()))
                    : 0;
        if (((::VATSCreateProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))))->GetBaseTexture()))->IsInDialogue())
        {
            return false;
        }
    }
    qpqRa = ((::VATSCreateFormListX *)(::FUN_004839c0(0x174256)));
    if (qdqWL && qpqRa && reinterpret_cast<::RefList *>((((::VATSCreateFormListHeadX *)(reinterpret_cast<::BGSCameraPath *>((qpqRa))->GetConditions()))))->FUN_005f65d0((void **)&(qdqWL)))
    {
        return false;
    }
    if (!(*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21cc)))
    {
        (*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21cc)) = ((::VATSCreateVATSTargetX *)(new ((void *)&((*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150)))) ::Vec3()))->pRef;
    }
    qpTd = ((::VATSCreateInterfaceMgrX *)(::fnv_004b7210::FUN_004b7210()));
    qfTOqo = ::Tile::GetInterfaceScale();
    qrEZrs = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::VATSCreateLoaderX *)(reinterpret_cast<::InterfaceManager *>((qpTd))->FUN_00586150()))))->FUN_00a01b00((void *)("Data\\Menus\\VATS_menu.xml"))));
    qSVM = ((::VATSCreateMenuX *)(reinterpret_cast<::FUN_00a03c90_shell *>((qrEZrs))->FUN_00a03c90()));
    if (qSVM && qSVM->GetID() == ::FUN_007eb8c0())
    {
        char qbfQdhM;
        VATSCreateAudioMgrX* qXMUYT;
        float qzYzlc;
        float qYvToq;
        float qODE;
        VATSCreatePointX qkPflib;
        int qjThF;
        int qrBzVM;
        char qZgNzZy;
        VATSCreateTileX* qnEqwa;
        float qyFp;
        VATSCreateListX<VATSCreateVATSTargetX*>* qGTHx;
        int qYdAnhh;
        int qxDeKK;
        int qidnYUK;
        VATSCreateTileX* qIpA;
        float qZWI;
        VATSCreateListX<VATSCreateVATSTargetX*>* qOHwfb;
        int qOPw;
        VATSCreateWeaponX* qYvz;
        float qYePyBl;
        bool qtOMjSX;
        int qqtISP;
        VATSCreateTileX* qQGWBE;
        VATSCreateTileX* qLCwQ;
        char qRFOo;
        float qOSGSW;
        float qsCroYH;
        float qOqnE;
        VATSCreateTileX* qoPB;
        VATSCreateFormX* qMBds;
        int qkJsUdT;
        reinterpret_cast<::FUN_00a1dc70_shell *>((qSVM))->FUN_00a1dc70((::TileMenu *)(::VATSCreateTileMenuX *)((VATSCreateTileMenuX*)xRTDynamicCast(qrEZrs, 0, (*reinterpret_cast<char (*)[]>((void *)&::DAT_0119f4cc)), (*reinterpret_cast<char (*)[]>((void *)&::DAT_0119f49c)), 0)), 0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4)) = (VATSCreateVATSMenuX*)xRTDynamicCast(qSVM, 0, (*reinterpret_cast<char (*)[]>((void *)&::DAT_0119f34c)), xRTTI_VATSMenu, 0);
        qOSGSW = 0.0f;
        ::ApplyPerkModifiers(0x1c, (::Actor *)((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))), &qOSGSW);
        qZWI = 0.0f;
        ::ApplyPerkModifiers(0x29, (::Actor *)((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))), &qZWI);
        qsCroYH = ::RandomFloat(0.0f, 1.0f);
        qOqnE = 1.0 - qZWI * ::DAT_01011588;
        if (qOSGSW > 0 && qsCroYH <= qOqnE)
        {
            if (!VATSCreateDAT_011db0ac)
            {
                VATSCreateEffectFormX* qAXSCg = ((::VATSCreateEffectFormX *)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(7))));
                if (qAXSCg && qAXSCg->IsValid())
                {
                    VATSCreateDAT_011db0ac = qAXSCg;
                }
            }
            if (qOSGSW != 0 && VATSCreateDAT_011db0ac)
            {
                VATSCreateNode3DX* qbdXUOW = (VATSCreateNode3DX*)(*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))->Get3D();
                VATSCreatePointX qmgeiw = (*reinterpret_cast<const ::VATSCreatePointX *>((void *)&::NiPoint3::ZERO));
                VATSCreateMatrixX qBLsiu = (*(const ::VATSCreateMatrixX *)(::FUN_006a9540((char *)(qbdXUOW))));
                VATSCreatePointX qCTa = (*(const ::VATSCreatePointX *)&(reinterpret_cast<::NiAVObject *>((qbdXUOW))->FUN_0043c490()));
                qmgeiw.x = reinterpret_cast<::FUN_004b55c0_class *>((void *)&(qBLsiu))->GetFloatAt(0, 1);
                qmgeiw.y = reinterpret_cast<::FUN_004b55c0_class *>((void *)&(qBLsiu))->GetFloatAt(1, 1);
                qmgeiw.z = reinterpret_cast<::FUN_004b55c0_class *>((void *)&(qBLsiu))->GetFloatAt(2, 1);
                reinterpret_cast<::MyPoint439180 *>((void *)&(const ::VATSCreatePointX &)(qmgeiw))->FUN_00439180(::g_011d97a8_arg1);
                reinterpret_cast<::NiPoint3 *>((void *)&(const ::VATSCreatePointX &)(qCTa))->Subtract((const ::NiPoint3 &)(qmgeiw));
                (*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21e8)) = ((::VATSCreateRefX *)(reinterpret_cast<::HandlerView *>(((*reinterpret_cast<::VATSCreateDataHandlerX * *>(&::g_dataHandler))))->PlaceObjectReference(
                    (::TESBoundObject *)(VATSCreateDAT_011db0ac), (::NiPoint3 *)&(qCTa), (::NiPoint3 *)&((*reinterpret_cast<const ::VATSCreatePointX *>((void *)&::NiPoint3::ZERO))), (::TESObjectCELL *)(((int)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::VATSCreateTESX * *>(&::g_TES))))->GetPrevPath()))),
                    (::TESWorldSpace *)(void *)(((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::VATSCreateTESX * *>(&::g_TES))))->GetHitSound()))), (::TESObjectREFR *)(0), (const char *)(0), (::TESForm *)(0))));
                reinterpret_cast<::fnv_008a6840::FUN_008a6840_shell *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21e8))))->FUN_008a6840(1);
                reinterpret_cast<::Sf030 *>((((::VATSCreateProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21e8))))->GetBaseTexture()))))->FUN_008ff030((::Actor *)((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21e8))));
                reinterpret_cast<::B8C4890Actor *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21e8))))->SetProcessValue(0.0f);
            }
        }
        else if (qZWI > 0)
        {
            if (!VATSCreateDAT_011db0b4)
            {
                VATSCreateEffectFormX* qrUCJDN = ((::VATSCreateEffectFormX *)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x16))));
                if (qrUCJDN && qrUCJDN->IsValid())
                {
                    VATSCreateDAT_011db0b4 = qrUCJDN;
                }
            }
            if (qZWI != 0 && VATSCreateDAT_011db0b4)
            {
                VATSCreateNode3DX* qydrGv = (VATSCreateNode3DX*)(*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))->Get3D();
                VATSCreatePointX qISe = (*reinterpret_cast<const ::VATSCreatePointX *>((void *)&::NiPoint3::ZERO));
                VATSCreateMatrixX qpydTG = (*(const ::VATSCreateMatrixX *)(::FUN_006a9540((char *)(qydrGv))));
                VATSCreatePointX qXUDve = (*(const ::VATSCreatePointX *)&(reinterpret_cast<::NiAVObject *>((qydrGv))->FUN_0043c490()));
                qISe.x = reinterpret_cast<::FUN_004b55c0_class *>((void *)&(qpydTG))->GetFloatAt(0, 1);
                qISe.y = reinterpret_cast<::FUN_004b55c0_class *>((void *)&(qpydTG))->GetFloatAt(1, 1);
                qISe.z = reinterpret_cast<::FUN_004b55c0_class *>((void *)&(qpydTG))->GetFloatAt(2, 1);
                reinterpret_cast<::MyPoint439180 *>((void *)&(const ::VATSCreatePointX &)(qISe))->FUN_00439180(::g_011d97a8_arg1);
                reinterpret_cast<::NiPoint3 *>((void *)&(const ::VATSCreatePointX &)(qXUDve))->Subtract((const ::NiPoint3 &)(qISe));
                (*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21ec)) = ((::VATSCreateRefX *)(reinterpret_cast<::HandlerView *>(((*reinterpret_cast<::VATSCreateDataHandlerX * *>(&::g_dataHandler))))->PlaceObjectReference(
                    (::TESBoundObject *)(VATSCreateDAT_011db0b4), (::NiPoint3 *)&(qXUDve), (::NiPoint3 *)&((*reinterpret_cast<const ::VATSCreatePointX *>((void *)&::NiPoint3::ZERO))), (::TESObjectCELL *)(((int)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::VATSCreateTESX * *>(&::g_TES))))->GetPrevPath()))),
                    (::TESWorldSpace *)(void *)(((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::VATSCreateTESX * *>(&::g_TES))))->GetHitSound()))), (::TESObjectREFR *)(0), (const char *)(0), (::TESForm *)(0))));
                reinterpret_cast<::fnv_008a6840::FUN_008a6840_shell *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21ec))))->FUN_008a6840(1);
                reinterpret_cast<::Sf030 *>((((::VATSCreateProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21ec))))->GetBaseTexture()))))->FUN_008ff030((::Actor *)((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21ec))));
                reinterpret_cast<::B8C4890Actor *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21ec))))->SetProcessValue(0.0f);
            }
        }
        qODE = 0.0f;
        ::ApplyPerkModifiers(0x1d, (::Actor *)((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))), &qODE);
        if (qODE > 0)
        {
            VATSCreateDAT_011db0b0 = 1;
        }
        else
        {
            VATSCreateDAT_011db0b0 = 0;
        }
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTargetChance = 0;
        reinterpret_cast<::Callees *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00726070();
        ::fnv_00a04200::FUN_00a04200(0);
        reinterpret_cast<::ItemChangeList *>(&((*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(((int (&)(void *, void *))::CompareByHeadingToPlayer)));
        qOHwfb = &(*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150));
        qYePyBl = (*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))->GetRange(0) * ::DAT_0102f248;
        qkPflib = (*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))->GetPos();
        if (qOHwfb && !qOHwfb->IsEmpty())
        {
            (*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21cc)) = ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->pRef;
        }
        while (qOHwfb && !qOHwfb->IsEmpty())
        {
            float qhQRuW;
            float qRZyE;
            float qQUDQ;
            if (!((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->pRef || !((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->pRef->Get3D())
            {
                VATSCreateListX<VATSCreateVATSTargetX*>* qOFvKuu = ((::VATSCreateListX< ::VATSCreateVATSTargetX *> *)(reinterpret_cast<::Callees *>((qOHwfb))->FUN_00726070()));
                reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150))))->FUN_00905330((::InventoryStackRecord *const &)(((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))));
                qOHwfb = qOFvKuu;
                continue;
            }
            {
                qRZyE = ::GetAngleBetweenPoints((const ::NiPoint3 &)(qkPflib), (const ::NiPoint3 &)(((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->pRef->GetPos()));
                qhQRuW = VATSCreateFUN_00408840(qYePyBl - qRZyE);
                qQUDQ = ::FastSqrt((const float *)&(const ::VATSCreatePointX &)(qkPflib - ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->pRef->GetPos()));
                ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->m_fTargetAngle =
                    (float)(VATSCreateDAT_01035810 / (qQUDQ > 0 ? qQUDQ : 0.001) +
                            (180.0 - (qhQRuW > 180.0 ? ::DAT_0103c348 - qhQRuW : qhQRuW)) / 180.0);
                qhQRuW = VATSCreateFUN_00408840((float)(qhQRuW > 180.0 ? ::DAT_0103c348 - qhQRuW : qhQRuW));
                ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->fAngleDifference = qhQRuW;
                ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->fDistance = qQUDQ;
                qOHwfb = ((::VATSCreateListX< ::VATSCreateVATSTargetX *> *)(reinterpret_cast<::Callees *>((qOHwfb))->FUN_00726070()));
            }
        }
        qOHwfb = &(*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150));
        qyFp = 0.0f;
        qGTHx = 0;
        qtOMjSX = false;
        while (qOHwfb && !qOHwfb->IsEmpty())
        {
            if ((((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->m_fTargetAngle > qyFp && !qtOMjSX) ||
                (((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->fAngleDifference < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011cfec4)))))) && ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->bVisible &&
                 (!qGTHx || ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->fDistance < ((::VATSCreateVATSTargetX *)(new ((void *)(qGTHx)) ::Vec3()))->fDistance)))
            {
                if (((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->fAngleDifference < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011cfec4)))))))
                {
                    qtOMjSX = true;
                }
                qyFp = ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->m_fTargetAngle;
                qGTHx = qOHwfb;
                (*reinterpret_cast<::VATSCreateRefX * *>(&::DAT_011f21cc)) = ((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->pRef;
                VATSCreateListX<VATSCreateLimbX*>* qZNIZJV = &((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->kLimbs;
                (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTargetChance = ((::VATSCreateLimbX *)(new ((void *)(qZNIZJV)) ::Vec3()));
                while (qZNIZJV && !qZNIZJV->IsEmpty())
                {
                    if (((::VATSCreateVATSTargetX *)(new ((void *)(qOHwfb)) ::Vec3()))->iType == 1 && ((::VATSCreateLimbX *)(new ((void *)(qZNIZJV)) ::Vec3()))->m_iLimbIndex == 1)
                    {
                        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTargetChance = ((::VATSCreateLimbX *)(new ((void *)(qZNIZJV)) ::Vec3()));
                    }
                    qZNIZJV = ((::VATSCreateListX< ::VATSCreateLimbX *> *)(reinterpret_cast<::Callees *>((qZNIZJV))->FUN_00726070()));
                }
            }
            qOHwfb = ((::VATSCreateListX< ::VATSCreateVATSTargetX *> *)(reinterpret_cast<::Callees *>((qOHwfb))->FUN_00726070()));
        }
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->b118 = 0;
        reinterpret_cast<::ItemChangeList *>(&((*reinterpret_cast<::VATSCreateListX< ::VATSCreateVATSTargetX *> *>(&::g_011db150))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(((int (&)(void *, void *))::FUN_007f0500)));
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->bDebounce = 1;
        reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::VATSCreateVATSX *>(&::g_011f2250))))->CreateObject(1, 0);
        qYdAnhh = ::InterfaceManager::UpdateInterfaceState();
        qjThF = ::FUN_00715da0();
        qqtISP = ::FUN_007177c0();
        qxDeKK = ::fnv_00717820::FUN_00717820();
        qOPw = ::FUN_00a00940("_OriginalX", -1);
        qkJsUdT = ::FUN_00a00940("_TotalWidth", -1);
        qrBzVM = ::FUN_00a00940("_ImageWidth", -1);
        reinterpret_cast<::BSAudio_ *>((((::VATSCreateAudioX *)(::FUN_00453a70()))))->FUN_007eb8a0();
        qnEqwa = ((::VATSCreateTileX *)(::FUN_007f4890((::Tile *)(::VATSCreateTileX *)(((::VATSCreateTileX *)(::FUN_00a09030(0x420)))), "ActionPoints")));
        if (!qnEqwa)
        {
            return false;
        }
        reinterpret_cast<::FUN_00a012d0_t *>((qnEqwa))->FUN_00a012d0(0xfa1, (float)((qYdAnhh - qqtISP * 2) - reinterpret_cast<::TileListBoxCalls *>((qnEqwa))->GetFloat(0xfb1) + ::DAT_0101db88), 1);
        reinterpret_cast<::FUN_00a012d0_t *>((qnEqwa))->FUN_00a012d0(0xfa2, (float)((qjThF - qxDeKK * 2) - reinterpret_cast<::TileListBoxCalls *>((qnEqwa))->GetFloat(0xfb0)), 1);
        reinterpret_cast<::Tile *>((qnEqwa))->Set(0xfa8, 1);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[7] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qnEqwa), "template_right_bracket")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[7])
        {
            return false;
        }
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[7]), 2);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[7]))->Set(0xfa1, -0x25);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[8] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qnEqwa), "template_meter")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[8])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[8]))->Set(qOPw, 0x146);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[8]))->Set(0xfa2, 0x29);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[8]))->Set(0xfad, 5);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[8]), 3);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[9] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qnEqwa), "template_meter")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[9])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[9]))->Set(qOPw, 0x146);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[9]))->Set(0xfa2, 0x29);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[9]))->Set(0xfa9, 0x80);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[9]), 3);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[10] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qnEqwa), "template_justify_right_text")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[10])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[10]))->Set(0xfa1, 0x13b);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[10]))->Set(0xfa2, 8);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[10]), 0);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[10]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d3e8c))))->GetMenuTitle()))), 1);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[11] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qnEqwa), "template_justify_right_text")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[11])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[11]))->Set(0xfa1, 0x10e);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[11]))->Set(0xfa2, 8);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[11]), 0);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[11]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d1d90))))->GetMenuTitle()))), 1);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[11]))->Set(0xfa3, 0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qnEqwa), "template_justify_right_text")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12]))->Set(0xfa1, 0x13b);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12]))->Set(0xfa2, 0x50);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12]))->Set(0xfb9, 7);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12]), 0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[13] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qnEqwa), "template_justify_right_text")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[13])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[13]))->Set(0xfa1, 0x50);
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[13]))->FUN_00a012d0(0xfa2, reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12]))->GetFloat(0xfa2), 1);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[13]))->Set(0xfb9, 7);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[13]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d4da4))))->GetMenuTitle()))), 1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[13]), 0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14] = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((qSVM))->FUN_00a1ddb0((::Tile *)(qnEqwa), (char *)("template_meter"), (::Tile *)(0))));
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14]))->Set(qOPw, 0x5a);
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14]))->FUN_00a012d0(
            0xfa2, (float)(reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12]))->GetFloat(0xfa2) + 3.0), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14]))->FUN_00a01350(0xfcc, (char *)("Interface\\VATS\\vats_bar.dds"), 1);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14]))->Set(qkJsUdT, 0x3c);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14]))->Set(qrBzVM, 1);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14]))->Set(0xfb8, 0xc8);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[14]), 3);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[15] = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((qSVM))->FUN_00a1ddb0((::Tile *)(qnEqwa), (char *)("template_meter_background"), (::Tile *)(0))));
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[15]))->FUN_00a012d0(
            0xfa2, (float)(reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[12]))->GetFloat(0xfa2) + 3.0), 1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[15]), 4);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_fValue1 =
            ::FUN_00404010(0.0f, ::FUN_00404010((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))->kAVOwner.GetBaseActorValue(0xc),
                                                                (*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))->kAVOwner.GetActorValue(0xc)));
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_fOverrideActionPoints =
            ::FUN_00404010(0.0f, (*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))->kAVOwner.GetActorValue(0xc));
        ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[8]),
                               (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_fOverrideActionPoints / (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_fValue1, 1,
                               0, 0);
        ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[9]),
                               (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_fOverrideActionPoints / (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_fValue1, 1,
                               0, 0);
        qLCwQ = ((::VATSCreateTileX *)(::FUN_007f4890((::Tile *)(::VATSCreateTileX *)(((::VATSCreateTileX *)(::FUN_00a09030(0x420)))), "HitPoints")));
        if (!qLCwQ)
        {
            return false;
        }
        reinterpret_cast<::Tile *>((qLCwQ))->Set(0xfa1, qqtISP * 2 + 10);
        reinterpret_cast<::FUN_00a012d0_t *>((qLCwQ))->FUN_00a012d0(0xfa2, (float)((qjThF - qxDeKK * 2) - reinterpret_cast<::TileListBoxCalls *>((qLCwQ))->GetFloat(0xfb0)), 1);
        reinterpret_cast<::Tile *>((qLCwQ))->Set(0xfa8, 1);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[16] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qLCwQ), "template_left_bracket")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[16])
        {
            return false;
        }
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[16]), 2);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[17] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qLCwQ), "template_meter")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[17])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[17]))->Set(qOPw, 0x14);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[17]))->Set(0xfa2, 0x29);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[17]), 3);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[18] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qLCwQ), "template_justify_right_text")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[18])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[18]))->Set(0xfa1, 0x35);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[18]))->Set(0xfa2, 8);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[18]), 0);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[18]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d300c))))->GetMenuTitle()))), 1);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[22] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qLCwQ), "template_compass_window")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[22])
        {
            return false;
        }
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[19] =
            ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[22]), "template_compass_icon_group")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[19])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[19]))->Set(0xfa2, 0x1e);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[20] =
            ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[22]), "template_compass_icon_group")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[20])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[20]))->Set(0xfa2, 0x1e);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[21] =
            ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[22]), "template_compass_icon_group")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[21])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[21]))->Set(0xfa2, 10);
        for (int qfpzU = 0; qfpzU < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d32d0)))))); qfpzU++)
        {
            VATSCreateTileX* qXSF =
                ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00a1ddb0((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[21]), (char *)("compass_npc_icon"), (::Tile *)(0))));
        }
        for (int qgqKr = 0; qgqKr < 10; qgqKr++)
        {
            VATSCreateTileX* qBMjHz = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00a1ddb0((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[20]),
                                                                           (char *)("template_compass_icon_quest"), (::Tile *)(0))));
        }
        qQGWBE = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00a1ddb0((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[20]),
                                                      (char *)("template_compass_icon_player"), (::Tile *)(0))));
        for (int qoqcoe = 0; qoqcoe < 10; qoqcoe++)
        {
            VATSCreateTileX* qVCM = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00a1ddb0((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[19]),
                                                                         (char *)("template_compass_icon_marker"), (::Tile *)(0))));
        }
        qoPB = ((::VATSCreateTileX *)(::FUN_007f4890((::Tile *)(::VATSCreateTileX *)(((::VATSCreateTileX *)(::FUN_00a09030(0x420)))), "EnemyHealth")));
        if (!qoPB)
        {
            return false;
        }
        reinterpret_cast<::FUN_00a012d0_t *>((qoPB))->FUN_00a012d0(0xfa1, (float)(qYdAnhh / 2 - reinterpret_cast<::TileListBoxCalls *>((qoPB))->GetFloat(0xfb1) / 2.0), 1);
        reinterpret_cast<::Tile *>((qoPB))->Set(0xfa2, qjThF - qxDeKK * 2 - 0x58);
        reinterpret_cast<::Tile *>((qoPB))->Set(0xff4, 2);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[23] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qoPB), "template_warning_background")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[23])
        {
            return false;
        }
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[23]))->FUN_00a012d0(0xfb1, reinterpret_cast<::TileListBoxCalls *>((qoPB))->GetFloat(0xfb1), 1);
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[23]))->FUN_00a012d0(0xfb0, (float)(reinterpret_cast<::TileListBoxCalls *>((qoPB))->GetFloat(0xfb0) + ::DAT_01020998), 1);
        reinterpret_cast<::Callees *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00726070();
        ::fnv_00a04200::FUN_00a04200(0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[24] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qoPB), "template_enemy_health_bracket")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[24])
        {
            return false;
        }
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[24]), 1);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[24]))->Set(0xfa3, 1);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[25] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qoPB), "template_meter")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[25])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[25]))->Set(qOPw, 0xab);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[25]))->Set(qkJsUdT, 0xf0);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[25]))->Set(0xfa2, 3);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[25]), 3);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[25]))->Set(0xfa3, 1);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qoPB), "template_meter")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27]))->Set(qOPw, 0xab);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27]))->Set(qkJsUdT, 0xf0);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27]))->Set(0xfa2, 3);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27]), 3);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27]))->Set(0xfa3, 0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[26] =
            ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[27]), "template_meter")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[26])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[26]))->Set(qOPw, 0xaf);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[26]))->Set(qkJsUdT, 0xf0);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[26]))->Set(0xfa2, 3);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[26]), 3);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[26]))->Set(0xfa3, 0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[28] = ((::VATSCreateTileX *)(::FUN_007f4830((::Tile *)(qoPB), "template_justify_center_text")));
        if (!(*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[28])
        {
            return false;
        }
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[28]))->Set(0xfa1, 0xaa);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[28]))->Set(0xfa2, 0x23);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[28]))->Set(0xfba, 0x15e);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[28]), 0);
        VATSCreatePtrX<VATSCreateTexX> qxWmVch(0);
        qxWmVch = ((::VATSCreateTexX *)(::NiSourceTexture::Create(
            (const ::NiFixedString &)((const ::VATSCreateFixedStringX &)(VATSCreateFixedStringX("Textures\\Interface\\HUD\\hud_compass_alphamap.dds"))), (::NiTexture__FormatPrefs &)((*reinterpret_cast<::VATSCreateFormatPrefsX *>(&::DAT_011a9598))), 1, 0)));
        ::FUN_007700b0((char *)((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[22]->GetNode()), (::NodeArg)(qxWmVch));
        reinterpret_cast<::FUN_007700d0_cls *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[22]->GetNode()))->set(1);
        if (!reinterpret_cast<::FUN_007eb8d0_Class *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->HasAllSlotsSet((int *)(void *)(&qidnYUK)))
        {
            ::FUN_0040fbe0(
                );
            ::fnv_007037e0::FUN_007037e0();
            return false;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((qrEZrs))->GetFloat(0xfa7) == ::DAT_010704f0 || reinterpret_cast<::TileListBoxCalls *>((qrEZrs))->GetFloat(0xfa7) == ::DAT_010704e8)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((qrEZrs))->FUN_00a012d0(0xfad, qfTOqo, 1);
        }
        VATSCreateStringX qQMZREG;
        qzYzlc = reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::VATSCreateCalendarX *>(&::g_011de7b8))))->GetGameTime();
        qRFOo = qzYzlc;
        qZgNzZy = (qzYzlc - qRFOo) * ::DAT_01012638;
        qbfQdhM = qRFOo < 1.0 ? 12.0 : (qRFOo > 12.0 ? qRFOo - 12.0 : qRFOo);
        VATSCreateDAT_011a0b70 = -1;
        ::DAT_011a59f0 = 0x19;
        reinterpret_cast<::fnv_008bb650::PlayerView *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))))->SetActiveState(0, 0, 0);
        VATSCreateDAT_011db0cc = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->kActions.Initialize((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[0], "queued_action");
        qXMUYT = ((::VATSCreateAudioMgrX *)(::FUN_00ad9060()));
        VATSCreateBSSoundHandleX qDdzMIp;
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::VATSCreateBSSoundHandleX &)(qDdzMIp))->operator=((const ::SoundPlaybackHandle &)((const ::VATSCreateBSSoundHandleX &)((*(::VATSCreateBSSoundHandleX *)(reinterpret_cast<::AudioClass_ae5680 *>((qXMUYT))->ResolveAudioHandle((::Handle_ae5680 *)("UIVATSEnter"), 0x121, {}))))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(qDdzMIp))->FUN_00ad8830(0);
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag5 = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag9 = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bAdditionalStateFlag = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag1 = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag2 = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag10 = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag6 = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag3 = 0;
        (*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_uiTargetCount = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::VATSCreateTimerX *>(&::g_timeGlobal))))->FUN_00825c00()));
        qMBds = ((::VATSCreateProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VATSCreateRefX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetEquippedWeapon();
        qYvz = qMBds ? ((::VATSCreateWeaponX *)(reinterpret_cast<::Twin_0044ddc0 *>((qMBds))->GetName())) : 0;
        if (!qYvz || ::FUN_006450c0((::TESObjectWEAP *)(qYvz)) || qYvz->GetWeaponType() == 10)
        {
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[5]))->Set(0xfa3, 0);
        }
        reinterpret_cast<::TutorialMessageGate718 *>(&(((::VATSCreateInterfaceMgrX *)(::fnv_004b7210::FUN_004b7210()))->kHUD))->FUN_00718630(::FUN_00709d40() ? 0x1b : 0x15, ::FUN_007eb8c0(),
                                                    0x200);
        qYvToq = ::GetObjectValue((::SpawnedObject *)(qYvz));
        if ((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_fOverrideActionPoints < qYvToq)
        {
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[6]))->Set(0xfaf, 0);
        }
        if (::FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011c3cb4))))->GetMenuTitle())), ::DAT_01018348))
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[6]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d5080))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[3]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d26f4))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[4]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d21c0))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[5]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d2b74))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::VATSCreateTileX *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00726070()))))->FUN_00a03da0((char *)("Target_button"))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::VATSCreateSettingX *>(&::g_011d4d38))))->GetMenuTitle()))), 1);
        }
        qIpA = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::VATSCreateTileX *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00726070()))))->FUN_00a03da0((char *)("BodyPart_button"))));
        if (qIpA)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qIpA))->FUN_00a01350(::FUN_00a01860("_xbox_button"), (char *)("&xbuttonls;"), 1);
            reinterpret_cast<::Tile *>((qIpA))->Set(::FUN_00a01860("_xbox_button"), 0x11);
        }
        qIpA = ((::VATSCreateTileX *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::VATSCreateTileX *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::VATSCreateVATSMenuX * *>(&::DAT_011db0d4))))->FUN_00726070()))))->FUN_00a03da0((char *)("Target_button"))));
        if (qIpA)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((qIpA))->FUN_00a01350(::FUN_00a01860("_xbox_button"), (char *)("&xbuttonrs;"), 1);
            reinterpret_cast<::Tile *>((qIpA))->Set(::FUN_00a01860("_xbox_button"), 0x12);
        }
        ::FUN_007eb920((::WeaponPrompt *)(qYvz));
        reinterpret_cast<::Menu *>((qSVM))->SetMenuVisibility(0);
        return true;
    }
    else if (qSVM && ((::VATSCreateTileX *)(reinterpret_cast<::Callees *>((qSVM))->FUN_00726070())))
    {
        delete qSVM;
    }
    return false;
}

struct SneakPlayer
{
};
struct SneakStringSetting
{
    const char* FUN_00403df0();
};
struct SneakFloatSetting
{
    float* FUN_00403e20();
};
__if_not_exists(GlobalObject_0040c150::GlobalObject_0040c150)
{
    class GlobalObject_0040c150
    {
      public:
        const char* FUN_00403df0();
    };
}
__if_not_exists(GlobalObject_004de370::GlobalObject_004de370)
{
    class GlobalObject_004de370
    {
      public:
        float* FUN_00403e20();
    };
}
__if_not_exists(g_011d4804)
{
    extern GlobalObject_0040c150 g_011d4804;
}
__if_not_exists(g_011d4eb8)
{
    extern GlobalObject_0040c150 g_011d4eb8;
}
__if_not_exists(g_011d2490)
{
    extern GlobalObject_0040c150 g_011d2490;
}
__if_not_exists(g_011d27b4)
{
    extern GlobalObject_0040c150 g_011d27b4;
}
__if_not_exists(g_011d9774)
{
    extern GlobalObject_004de370 g_011d9774;
}
__if_not_exists(_g_thePlayer)
{
    extern PlayerCharacter* _g_thePlayer;
}
__if_not_exists(HUDMainMenu_pme)
{
    extern HUDMainMenu* HUDMainMenu_pme;
}
struct SneakProcess
{
    int GetHighestDetectionValue(PlayerCharacter*, int);
};
__if_not_exists(ProcessLists::ProcessLists)
{
    class ProcessLists
    {
      public:
        int GetHighestDetectionValue(PlayerCharacter*, int);
    };
}
__if_not_exists(DAT_011e0e80)
{
    extern ProcessLists DAT_011e0e80;
}
struct InteractionTile
{
};
struct HUDInteraction : HUDMainMenu
{
    void FUN_007732d0();
};
// @fnv 0x00770430
void HUDUpdate::FUN_00770430()
{
    if (!(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)) || !((int)(reinterpret_cast<::LowProcess *>((((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->GetTarget())))
        return;
    reinterpret_cast<::GameTimerRecord *>((((HUDTime*)m_cBuffer)))->Update();
    ::fnv_00779070::FUN_00779070((::fnv_00779070::CompassMovie *)(m_pTiles[6]), (::fnv_00779070::CompassTileList *)(m_pTiles[3]), (::fnv_00779070::CompassTileList *)(m_pTiles[4]), (::fnv_00779070::CompassTileList *)(m_pTiles[5]));
    FUN_0077da60();
    reinterpret_cast<::AmmoHUD *>(this)->UpdateAmmoHUD();
    UpdateCompassMarkers();
    reinterpret_cast<::RepairMenu *>(this)->UpdateRepairList();
    static unsigned lastUpdate = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTime*)m_cBuffer)))->FUN_00825c00();
    if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTime*)m_cBuffer)))->FUN_00825c00() - lastUpdate < 200)
        return;
    if (m_iHudValueFirstAfterUnsignedValues == -1 ||
        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00() - m_iHudValueFirstAfterUnsignedValues > 1000)
    {
        m_iHudValueFirstAfterUnsignedValues = -1;
        reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[75])))->Set(4003, 0);
        reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[82])))->Set(4003, 0);
    }
    if (m_iHudValueSecondAfterUnsignedValues == -1 ||
        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00() - m_iHudValueSecondAfterUnsignedValues > 1000)
    {
        m_iHudValueSecondAfterUnsignedValues = -1;
        reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[76])))->Set(4003, 0);
        reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[83])))->Set(4003, 0);
    }
    lastUpdate = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTime*)m_cBuffer)))->FUN_00825c00();
    int f = (int)FUN_00715da0(), h = (int)::InterfaceManager::UpdateInterfaceState();
    int cf = (int)FUN_007177c0(), p = (int)::fnv_00717820::FUN_00717820();
    reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])))->Set(4001, 2 * cf + 10);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])))->FUN_00a012d0(4002, f - 2 * p - reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])))->GetFloat(4016), true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])))->FUN_00a012d0(4001, h - 2 * cf - reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])))->GetFloat(4017) + ::DAT_0101db88, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])))->FUN_00a012d0(4002, f - 2 * p - reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])))->GetFloat(4016), true);
    reinterpret_cast<::FUN_00a07530_shell *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])))->FUN_00a07530(1);
    reinterpret_cast<::FUN_00a07530_shell *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])))->FUN_00a07530(1);
    reinterpret_cast<::FUN_00771540_shell *>(this)->UpdateActorValueMeter(16);
    reinterpret_cast<::FUN_00771540_shell *>(this)->UpdateActorValueMeter(12);
    reinterpret_cast<::BreathHUD *>(this)->FUN_0077e4f0();
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[86])))->FUN_00a012d0(4009, DAT_011d979c, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[78])))->FUN_00a012d0(4009, DAT_011d979c, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[75])))->FUN_00a012d0(4009, DAT_011d979c, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[82])))->FUN_00a012d0(4009, DAT_011d979c, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[83])))->FUN_00a012d0(4009, DAT_011d979c, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[76])))->FUN_00a012d0(4009, DAT_011d979c, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[77])))->FUN_00a012d0(4009, DAT_011d979c, true);
    if (reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->GetFloat(4009) > 0.0 &&
        reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->FUN_00a07fc0(4009) &&
        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00() - reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->GetFloat(4100) > DAT_01073480)
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->GetFloat(4009), 0.0f, ::DAT_010162c0, 0);
    if (reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])))->GetFloat(4009) > 0.0 &&
        reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])))->FUN_00a07fc0(4009) &&
        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00() - reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])))->GetFloat(4100) > DAT_01073480)
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])))->StartFade(4009, *((float *)&(::FUN_00403e20((float *)&(DAT_011d9774)))) * ::DAT_0101e568, 0.0f, ::DAT_010162c0, 0);
    if (reinterpret_cast<::FUN_00a01230_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->IsTraitNonZero(::FUN_00a01860(DAT_01073474)) &&
        reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[64])))->GetFloat(4003) != 0.0 &&
        reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])))->GetFloat(4009) == 0.0 &&
        reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])))->FUN_00a07fc0(4009))
    {
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->StartFade(4009, 0.0f, *((float *)&(::FUN_00403e20((float *)&(DAT_011d9774)))) * ::DAT_0101e568, ::DAT_010162c0, 0);
        reinterpret_cast<::Tile *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->Set(4100, reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00());
        reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])))->Set(::FUN_00a01860(DAT_01073474), 0);
    }
    if (reinterpret_cast<::Actor *>((((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->IsSneaking())
        reinterpret_cast<::HUDInteraction *>(this)->FUN_007732d0();
    else if (reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])))->GetFloat(4009) > 0.0 &&
             reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])))->FUN_00a07fc0(4009))
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])))->GetFloat(4009), 0.0f, ::fnv_00c88020::DAT_01016248, 0);
    if (HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 18 && HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 19)
        UpdateQuestNotification();
    reinterpret_cast<::XPMenu *>(this)->FUN_0077c4e0();
    UpdateRadMeter();
    reinterpret_cast<::HudMenuShell *>(this)->UpdateCrippleMeters(::FUN_004d1360((char *)(((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer))))));
    DAT_011d96c5 = false;
    if (m_pTargetActor)
    {
        HUDDetectionList* list = ((::HUDDetectionList *)(reinterpret_cast<::FUN_00595d10_shell *>((((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->FUN_00595d10()));
        while (list && !list->FUN_008256d0())
        {
            HUDDetection* detection = *((::HUDDetection **)(new ((void *)(list)) ::Vec3()));
            if ((void*)detection->value == m_pTargetActor && detection->detected && !detection->ignored)
            {
                DAT_011d96c5 = true;
                break;
            }
            list = ((::HUDDetectionList *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        }
    }
    bool a = false;
    float eb = ((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))->GetDistanceScale(0) * DAT_0102f248;
    float s = 0.0f;
    if (m_pTargetActor)
        s = GetAngleBetweenPoints(*(NiPoint3*)((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))->GetPos(),
                                  *(NiPoint3*)((HUDActor*)m_pTargetActor)->GetPos());
    bool i = (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTime*)m_cBuffer)))->FUN_00825c00() - m_uiHudValueFirstAfterActor >
                  (unsigned)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::HUDFloatSetting *>(&::originalRuntimeFloatSetting689)))))) * ::DAT_01017b70) &&
              !(FUN_00408840(eb - s) < DAT_010357e8))
                 ? 0
                 : 1;
    if (((int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::HUDMode *>(&::g_011f2250))))->GetName())) == 4)
    {
        if ((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) && (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))->IsActor() && !(*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))->IsDead(false))
        {
            a = true;
            ::fnv_00773190::FUN_00773190((::fnv_00773190::EnemyRefV *)(::RefX *)((RefX*)(*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))));
        }
    }
    else if (m_pTargetActor && !((HUDActor*)m_pTargetActor)->IsDead(false) &&
             !reinterpret_cast<::FUN_00477ba0_shell *>((((HUDActor*)m_pTargetActor)))->FUN_00477ba0() && DAT_011d96c5 &&
             !reinterpret_cast<::FUN_00a01230_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[29])))->IsTraitNonZero(4003) &&
             !reinterpret_cast<::FUN_00a01230_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[32])))->IsTraitNonZero(4003) &&
             reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[62])))->GetFloat(4084) == 2.0 && i)
    {
        a = true;
        UpdateActivatePrompt((RefX*)m_pCrosshairReference, 0, true);
    }
    else if (reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[62])))->GetFloat(4084) == 2.0)
    {
        reinterpret_cast<::Tile *>((((TileX*)m_pTiles[21])))->Set(4003, 0);
        reinterpret_cast<::Tile *>((((TileX*)m_pTiles[22])))->Set(4003, 0);
        reinterpret_cast<::Tile *>((((TileX*)m_pTiles[23])))->Set(4003, 0);
    }
    if (a)
    {
        bool hostile = false;
        if (m_pTargetActor && ((((::HUDDetection *)(reinterpret_cast<::FUN_00967090_t *>((((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->FUN_00967090((::Actor *)(m_pTargetActor)))) &&
                                ((::HUDDetection *)(reinterpret_cast<::FUN_00967090_t *>((((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer)))))->FUN_00967090((::Actor *)(m_pTargetActor))))->detected) ||
                               reinterpret_cast<::FUN_008bc700_shell *>((((HUDActor*)m_pTargetActor)))->FUN_008bc700((::Actor *)((*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer))))))
            hostile = true;
        reinterpret_cast<::Tile *>((((TileX*)m_pTiles[21])))->Set(4003, 1);
        reinterpret_cast<::Tile *>((((TileX*)m_pTiles[22])))->Set(4003, 1);
        reinterpret_cast<::Tile *>((((TileX*)m_pTiles[23])))->Set(4003, 1);
        reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[62])))->Set(4084, hostile ? 2 : 1);
        reinterpret_cast<::FUN_00a07530_shell *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[21])))->FUN_00a07530(8);
        reinterpret_cast<::FUN_00a07530_shell *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[22])))->FUN_00a07530(8);
        reinterpret_cast<::FUN_00a07530_shell *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[23])))->FUN_00a07530(8);
        reinterpret_cast<::FUN_00a07530_shell *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[23])))->FUN_00a07530(8);
    }
    if (m_pTargetActor && (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((HUDActor*)m_pTargetActor)))->FUN_00493bb0())) || ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::HUDMode *>(&::g_011f2250))))->GetName())) == 4))
        reinterpret_cast<::FUN_007701e0_shell *>(this)->UpdateTargetInfo((::HMTarget *)(m_pTargetActor));
    if (m_pCrosshairReference && DAT_011d97c0 != reinterpret_cast<::xRefr *>((((HUDActor*)m_pCrosshairReference)))->FUN_00579690())
    {
        DAT_011d97c0 = reinterpret_cast<::xRefr *>((((HUDActor*)m_pCrosshairReference)))->FUN_00579690();
        UpdateActivatePrompt((RefX*)m_pCrosshairReference, 0, true);
    }
    if (m_bHudAnimationActive &&
        reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00() - m_uiHudValueSecondAfterActor > (unsigned)(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::HUDIntSetting *>(&::g_011d2220)))))) * 1000) &&
        HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 18 && HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 19)
    {
        m_uiHudValueSecondAfterActor = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00();
        FUN_007736d0(((::Script *)(::FUN_005cbb50((char *)(((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer))))))));
    }
    else if (m_uiHudValueSecondAfterActor == 0 && FUN_00458030() == 2)
    {
        m_uiHudValueSecondAfterActor = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::HUDTime *>(&::g_timeGlobal))))->FUN_00825c00();
        FUN_007736d0(((::Script *)(::FUN_005cbb50((char *)(((HUDActor*)(*reinterpret_cast<::MarkerPlayer * *>(&::_g_thePlayer))))))));
        m_bQuestObjectiveUpdatesEnabled = false;
    }
    {
        unsigned k;
        HUDMessage* l;
        if (m_bQuestObjectiveUpdatesEnabled)
        {
            ::fnv_0077f500::ResetHudTiles((void *)this);
            reinterpret_cast<::fnv_0077f5e0::FUN_0077f5e0_shell *>(this)->ResetWaitTiles();
            m_bQuestObjectiveUpdatesEnabled = false;
        }
        else if (!reinterpret_cast<::FUN_0076b610_Class *>((((HUDSubtitleList*)m_kSubtitleArray)))->FUN_0076b610())
        {
            for (k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((HUDSubtitleList*)m_kSubtitleArray)))->GetName())); ++k)
            {
                if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTime*)m_cBuffer)))->FUN_00825c00() -
                        (*((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k))->time >=
                    (*((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k))->duration * ::DAT_01017b70)
                {
                    if (*((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k) == m_pCurrentSubtitle)
                        reinterpret_cast<::FUN_00775670_shell *>(this)->FUN_00775670();
                    HUDSubtitle* j = *((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k);
                    FUN_00401030(j);
                    reinterpret_cast<::FUN_006bf8f0_Class *>((((HUDSubtitleList*)m_kSubtitleArray)))->FUN_006bf8f0(k, true);
                    --k;
                }
            }
            if (!m_pCurrentSubtitle)
            {
                m_pCurrentSubtitle = ((::HUDSubtitle *)(reinterpret_cast<::HUDTargetSelector *>(this)->FindTargetMarker()));
                if (m_pCurrentSubtitle)
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[28])))->FUN_00a01350(4036, (char *)((const char*)m_pCurrentSubtitle), true);
                    reinterpret_cast<::Tile *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[28])))->Set(4003, 1);
                }
            }
        }
        if (((HUDMessageList*)m_kMessageList)->FUN_005ae380() &&
            reinterpret_cast<::FUN_00a01230_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[67])))->IsTraitNonZero(4003))
        {
            if (reinterpret_cast<::TileListBoxCalls *>((((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[27])))->GetFloat(4009) == 0.0)
            {
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[27])))->StartFade(4009, 0.0f, DAT_011d979c, ::g_011c7200_arg1, 0);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[25])))->StartFade(4009, 0.0f, DAT_011d979c, ::g_011c7200_arg1, 0);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[26])))->StartFade(4009, 0.0f, DAT_011d979c, ::g_011c7200_arg1, 0);
            }
            if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[27])))->FUN_00a07fc0(4009))
            {
                l = *((::HUDMessage **)(new ((void *)(((HUDMessageList*)m_kMessageList))) ::Vec3()));
                if (!m_uiMessageCount)
                    m_uiMessageCount = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTime*)m_cBuffer)))->FUN_00825c00();
                if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((HUDTime*)m_cBuffer)))->FUN_00825c00() - m_uiMessageCount >= l->duration * ::DAT_01017b70)
                    FUN_007756e0();
            }
        }
    }
    DAT_011d979c = *((float *)&(::FUN_00403e20((float *)&(DAT_011d9774)))) * ::DAT_0101e568;
}
// Updates HUD tile 24 using player state, a process count, and string and float settings.
// @fnv 0x007732d0
void HUDInteraction::FUN_007732d0()
{
    bool blocked = false;
    {
        bool active = false;
        if (((bool)(reinterpret_cast<::FUN_00953c50_Class *>((((SneakPlayer*)_g_thePlayer)))->FUN_00953c50((char *)(bool *)(&blocked)))) || blocked)
        {
            reinterpret_cast<::Tile *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->Set(0xff4, 2);
            if (blocked)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((SneakStringSetting*)&g_011d4804)))->GetMenuTitle()))), true);
            }
            else
            {
                active = true;
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((SneakStringSetting*)&g_011d4eb8)))->GetMenuTitle()))), true);
            }
        }
        else if (reinterpret_cast<::FUN_007735b0_class *>((((SneakPlayer*)_g_thePlayer)))->GetByteAt5F8())
        {
            reinterpret_cast<::Tile *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->Set(0xff4, 2);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((SneakStringSetting*)&g_011d4804)))->GetMenuTitle()))), true);
        }
        else
        {
            int count = reinterpret_cast<::fnv_00973710::Shell *>((((SneakProcess*)&DAT_011e0e80)))->GetHighestDetectionValue((::fnv_00973710::ActorX *)(_g_thePlayer), 0);
            reinterpret_cast<::Tile *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->Set(0xff4, 1);
            active = false;
            if (count > 0)
            {
                if (!reinterpret_cast<::FUN_007735b0_class *>((((SneakPlayer*)_g_thePlayer)))->GetByteAt5F8())
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((SneakStringSetting*)&g_011d2490)))->GetMenuTitle()))), true);
            }
            else
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((SneakStringSetting*)&g_011d27b4)))->GetMenuTitle()))), true);
            }
        }
        if (active && !reinterpret_cast<::FUN_00a01230_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->IsTraitNonZero(0x1004))
        {
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->StartFade(0xfa9, 0.0f, *((float *)&(::FUN_00403e20((float *)(((SneakFloatSetting*)&g_011d9774))))) * 255.0, 0.5f, 2);
        }
        else if ((!active && reinterpret_cast<::FNVSearchOwner *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->FindValueByKey(0xfa9) == 2) ||
                 (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->FUN_00a07fc0(0xfa9) &&
                  reinterpret_cast<::TileListBoxCalls *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->GetFloat(0xfa9) !=
                      *((float *)&(::FUN_00403e20((float *)(((SneakFloatSetting*)&g_011d9774))))) * 255.0))
        {
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->GetFloat(0xfa9),
                               *((float *)&(::FUN_00403e20((float *)(((SneakFloatSetting*)&g_011d9774))))) * 255.0, 0.5f, 0);
        }
        reinterpret_cast<::Tile *>((((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])))->Set(0x1004, active);
    }
}

class ClearMessagesTile
{
  public:
};
struct ClearMessagesList
{
    bool FUN_008256d0();
};
extern HUDMainMenu* HUDMainMenu_pme;
struct HUDClearMessages : HUDMainMenu
{
    void FUN_00775920();
};

// @fnv 0x00775920
void HUDClearMessages::FUN_00775920()
{
    ClearMessagesList* list = (ClearMessagesList*)m_kMessageList;
    while (list && !list->FUN_008256d0())
    {
        void* message = *((void **)(new ((void *)(list)) ::Vec3()));
        FUN_00401030(message);
        list = ((::ClearMessagesList *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>((((ClearMessagesList*)m_kMessageList)))->RemoveAll();
    reinterpret_cast<::FUN_00a012d0_t *>((((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[27])))->FUN_00a012d0(4009, 0.0f, true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[26])))->FUN_00a01350(4036, (char *)(::DAT_01020770), true);
    reinterpret_cast<::FUN_00a012d0_t *>((((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[26])))->FUN_00a012d0(4009, 0.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[25])))->FUN_00a012d0(4009, 0.0f, true);
    reinterpret_cast<::FUN_00775670_shell *>(this)->FUN_00775670();
}

struct VisibilityController
{
};
struct VisibilityTile;
struct VisibilityChildren
{
};
struct VisibilityTile
{
    void* vtable;
    VisibilityChildren children;
    const char* FUN_00700300();
};

// Recursively visits child tiles, then conditionally sets a trait derived from `_360Controller` and applies flag value 4.
// @fnv 0x00719580
void __cdecl FUN_00719580(VisibilityTile* pTile)
{
    VisibilityTile* pChild = 0;
    void* pos = ((void *)(::FUN_00559450((int *)&(pTile->children))));
    while (pos)
    {
        pChild = ((::VisibilityTile *)(reinterpret_cast<::ListStandIn *>(&(pTile->children))->FUN_0057cbe0((int **)&(pos))));
        FUN_00719580(pChild);
    }
    if (!FUN_00408b20(pTile->FUN_00700300(), "xbox_button") || !FUN_00408b20(pTile->FUN_00700300(), "PCShortcutLabel"))
    {
        reinterpret_cast<::Tile *>((pTile))->Set(FUN_00a01860("_360Controller"), ((::VisibilityController *)(::fnv_004b7210::FUN_004b7210()))->FUN_004b71d0());
        reinterpret_cast<::FUN_00a074d0_shell *>((pTile))->FUN_00a074d0(4);
    }
}

#include "generated/data/fallout/interface/menus/hudmainmenu.inc"
