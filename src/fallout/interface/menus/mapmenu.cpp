// fallout/interface/menus/mapmenu.cpp: MapMenu, Interface, InsertBox, TileImage and more (116 functions)

#include <new>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/B93BE30ProcessManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/BGSQuestObjective.h"
#include "fnv/decl/BGSTalkingActivator.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/C77a400.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00438f30_Class.h"
#include "fnv/decl/FUN_0043a2e0_host.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00461150_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/FUN_00517fd0_shell.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00569060_shell.h"
#include "fnv/decl/FUN_0057b4b0_shell.h"
#include "fnv/decl/FUN_00586400_shell.h"
#include "fnv/decl/FUN_00586440_shell.h"
#include "fnv/decl/FUN_005884e0_owner.h"
#include "fnv/decl/FUN_00588e40_shell.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005cbb70_shell.h"
#include "fnv/decl/FUN_005def70_Class.h"
#include "fnv/decl/FUN_005e8d40_shell.h"
#include "fnv/decl/FUN_005e9300_Host.h"
#include "fnv/decl/FUN_005ec330_shell.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_006a1b60_Class.h"
#include "fnv/decl/FUN_006ad180_Cls.h"
#include "fnv/decl/FUN_0070ec70_class.h"
#include "fnv/decl/FUN_0070f690_Class.h"
#include "fnv/decl/FUN_0071aa60_class.h"
#include "fnv/decl/FUN_007242c0_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007700d0_cls.h"
#include "fnv/decl/FUN_0077a450_class.h"
#include "fnv/decl/FUN_00799dc0_class.h"
#include "fnv/decl/FUN_007a6310_cls.h"
#include "fnv/decl/FUN_007a63f0_shell.h"
#include "fnv/decl/FUN_007a80e0_cls.h"
#include "fnv/decl/FUN_007fa0f0_Class.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00952d60_stand.h"
#include "fnv/decl/FUN_00952f90_cls.h"
#include "fnv/decl/FUN_00966a50_Class.h"
#include "fnv/decl/FUN_00966bb0_shell.h"
#include "fnv/decl/FUN_009ff600_shell.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a013d0_shell.h"
#include "fnv/decl/FUN_00a01440_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a03d40_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a07ed0_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a23390_t.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad8650_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad88b0_h.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FlagS.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/ItemCounter.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Mid83b9a0.h"
#include "fnv/decl/MyHack.h"
#include "fnv/decl/NavMeshListNode.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/Obj_009529d0.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/PerkEntryConditionSet.h"
#include "fnv/decl/PlayerMarkerOwner.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/ReputationTracker.h"
#include "fnv/decl/S006950d0.h"
#include "fnv/decl/S5460.h"
#include "fnv/decl/S_00a04150_Class.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/StringHolder.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575d10__FUN_00575d10_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00578870__FUN_00578870_Class.h"
#include "fnv/decl/fnv_007a1c30__FUN_007a1c30_holder.h"
#include "fnv/decl/fnv_007a2070__ClearList.h"
#include "fnv/decl/fnv_007a6480__FUN_007a6480_cls.h"
#include "fnv/decl/fnv_007a6920__ScrollList.h"
#include "fnv/decl/fnv_007a71b0__FUN_007a71b0_cls.h"
#include "fnv/decl/fnv_007a73e0__HighlightList.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0093d660__TravelObject.h"
#include "fnv/decl/fnv_00952ba0__PlayerCharacterStandIn.h"
#include "fnv/decl/fnv_009ff690__ReleaseTile.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a07c60__FUN_00a07c60_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1b020__FUN_00a1b020_t.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/fnv_00ad7c00__FUN_00ad7c00.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/q72__Menu.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_004fe000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00556000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a6000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005cb000.h"
#include "fnv/symbols_005eb000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_00798000.h"
#include "fnv/symbols_00799000.h"
#include "fnv/symbols_0079a000.h"
#include "fnv/symbols_0079b000.h"
#include "fnv/symbols_0079c000.h"
#include "fnv/symbols_0079f000.h"
#include "fnv/symbols_007a1000.h"
#include "fnv/symbols_007fa000.h"
#include "fnv/symbols_00832000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_00ad8000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01056000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_01071000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f6000.h"
#include "mapmenu_decls.h"

// @fnv 0x007a1930
template <> void ListBox<TESQuest*>::ClearSelection(bool notify)
{
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950((unsigned int)(0), notify);
}

// @fnv 0x00a20610
void TileImage::SetTexture(NiAVObject* image)
{
    int unused1, unused2;
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(this)->FUN_00a01350(0xfcc, (char *)(""), true);
    texture = image;
    reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x30);
}

// Initializes the MapMenu by caching tile IDs for its UI elements and resetting its member fields to default values.
// @fnv 0x00796740
MapMenu::MapMenu()
{
    DAT_011da354 = Tile::GetTraitID("_Title");
    DAT_011da358 = Tile::GetTraitID("_Value");
    DAT_011da360 = Tile::GetTraitID("_CurrentTab");
    DAT_011da348 = Tile::GetTraitID("_selected");
    DAT_011da344 = Tile::GetTraitID("_TextAlpha");
    DAT_011da350 = Tile::GetTraitID("_x");
    DAT_011da34c = Tile::GetTraitID("_y");
    DAT_011da35c = Tile::GetTraitID("_Magnification");
    m_fMapRotation = 0.0f;
    m_bMapMenuActive = true;
    m_pkActiveSoundList = 0;
    m_bMapListUpdatePending = false;
    m_pSecondMapReference = 0;
    m_iMapDisplayMode = 36;
    m_kPlayerWorldPosition = NiPoint3::ZERO;
    m_pCurrentMapSpace = 0;
    m_pCurrentMapForm = 0;
    m_pMapTile = 0;
    m_pSelectedQuest = 0;
    m_pSelectedNote = 0;
    pAdjustNorthRotationCell = 0;
    m_pSelectedMarkerTile = 0;
    m_uiMapState = 0;
    m_fSavedMusicVolume = ::FUN_00453a70()->GetMusicVolume();
    m_pSelectedMapMarkerInfo = 0;
    m_uiMapMarkerCount = 0;
    m_pFirstMapReference = 0;
    m_bNeedsMapUpdate = true;
    m_pCurrentWorldspace = 0;
    m_bLocalMapMode = false;
}

// @fnv 0x00796a40
int MapMenu::GetClass()
{
    return 0x3FF;
}

struct FUN_00796f40_shell : public Tile
{
    void SetFlag8000(bool);
};

// Sets or clears bit 0x8000 in the flags field at offset 0x30 of this Tile based on abOn.
// @fnv 0x00796f40
void FUN_00796f40_shell::SetFlag8000(bool abOn)
{
    abOn ? *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30) |= 0x8000
         : *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30) &= ~0x8000;
}

struct FUN_00798400_shell : public PlayerCharacter
{
    TESObjectREFR* FUN_00798400();
};
// @fnv 0x0079f640
void MapMenu::SetMapPositionToPlayer()
{
    if (DAT_011da368 && reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400())
    {
        TESObjectREFR* ref = reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400();
        DAT_011da368->m_kPlayerWorldPosition = *ref->GetPos();
        DAT_011da368->m_pCurrentMapSpace = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400()))->FUN_00575d70()));
        if (!DAT_011da368->m_pCurrentMapSpace)
            DAT_011da368->m_pCurrentMapSpace = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400()))->GetTarget()));
    }
}

// @fnv 0x00798400
TESObjectREFR* FUN_00798400_shell::FUN_00798400()
{
    return *(TESObjectREFR**)((char*)this + 0x6f4);
}

struct FUN_0079c090_shell : public MapMenu
{
    void FUN_0079c090();
};

// Clears the float at offset 0x88 and sets the tile at offset 0x68 to value 0xfa3 with 0.
// @fnv 0x0079c090
void FUN_0079c090_shell::FUN_0079c090()
{
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x88) = 0.0f;
    (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x68))->Set(0xfa3, 0);
}

// If DAT_011da368 is set, calls Set on the Tile at offset 0x30 with DAT_011da35c and afMagnification.
// @fnv 0x007a1820
void __cdecl FUN_007a1820(float afMagnification)
{
    if (DAT_011da368)
    {
        reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)((char*)DAT_011da368 + 0x30))))->FUN_00a012d0(DAT_011da35c, afMagnification, true);
    }
}

// If DAT_011da368 is set, calls Set on the Tile at offset 0x38 with DAT_011da35c and afMagnification.
// @fnv 0x007a1850
void __cdecl FUN_007a1850(float afMagnification)
{
    if (DAT_011da368)
    {
        reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)((char*)DAT_011da368 + 0x38))))->FUN_00a012d0(DAT_011da35c, afMagnification, true);
    }
}

extern int DAT_01075530;

struct Dummy_007a1a70
{
    void* vtable;
};

// Sets the object's vtable to DAT_01075530 and calls FUN_007a63f0 with 0, 0, returning the object.
// @fnv 0x007a1a70
Dummy_007a1a70* FUN_007a1a70(Dummy_007a1a70* pThis)
{
    pThis->vtable = &DAT_01075530;
    reinterpret_cast<::FUN_007a63f0_shell *>((pThis))->FUN_007a63f0(0, 0);
    return pThis;
}

struct NiTexture;
struct FUN_009c8640_shell : public TileShaderProperty
{
    NiTexture* FUN_009c8640();
};
// @fnv 0x007a1670
void MapMenu::OpenMap()
{
    if (Interface::GetSelectedTargetIndex(Interface::Map) && DAT_011da368->m_iMapDisplayMode == 33)
        return;
    if (DAT_011da368)
    {
        NiAVObject* node =
            ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[4]))->FUN_0056c7f0())) ? ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[4]))->FUN_0056c7f0()))))->FUN_0045bc00(0))) : 0;
        TileShaderProperty* property =
            node ? reinterpret_cast<TileShaderProperty*>(((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))))) : 0;
        if (property && reinterpret_cast<::FUN_009c8640_shell *>((property))->FUN_009c8640())
        {
            property->FUN_00bb7a10(0);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[4]))->FUN_00a01350(0xfcc, (char *)(""), true);
            DAT_011da36c = true;
        }
    }
}
// @fnv 0x007a1490
void MapMenu::UpdateMapPosition()
{
    if (DAT_011da368)
    {
        NiNode* localNode = ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[2]))->FUN_0056c7f0()));
        if (!localNode)
            return;
        for (unsigned int i = 0; i < localNode->FUN_0043b480(); ++i)
        {
            NiAVObject* child = localNode->GetAt(i);
            if (child)
                localNode->RemoveObject(child);
        }
        reinterpret_cast<::S_00a04150_Class *>((DAT_011da368->m_pTiles[2]))->FUN_00a04150();
        DAT_011da368->m_pTiles[2]->Set(0xfa3, 0);
        DAT_011da368->m_pTiles[3]->Set(0xfa3, 0);
        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((DAT_011da368->m_pTiles[3]))->RemoveFadeItemsForTile(0xff5);
        reinterpret_cast<::FileMatchList *>(&(DAT_011da368->LocalMapMarkerList))->RemoveAll();
        reinterpret_cast<::S_00a04150_Class *>((DAT_011da368->m_pTiles[4]))->FUN_00a04150();
        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((DAT_011da368->m_pTiles[5]))->RemoveFadeItemsForTile(0xff5);
        reinterpret_cast<::FileMatchList *>(&(DAT_011da368->m_kMapMarkerList))->RemoveAll();
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(DAT_011da368->m_kMapMarkerTiles))->Clear(true);
        DAT_011da368->m_uiMapMarkerCount = 0;
        DAT_011da368->m_pMapTile = 0;
        NiAVObject* node = ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[16]))->FUN_0056c7f0()))
                               ? ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[16]))->FUN_0056c7f0()))))->FUN_0045bc00(0)))
                               : 0;
        TileShaderProperty* property =
            node ? reinterpret_cast<TileShaderProperty*>(((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))))) : 0;
        if (property && reinterpret_cast<::FUN_009c8640_shell *>((property))->FUN_009c8640())
        {
            property->FUN_00bb7a10(0);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[16]))->FUN_00a01350(0xfcc, (char *)(""), true);
        }
        reinterpret_cast<::FUN_0079c090_shell *>((DAT_011da368))->FUN_0079c090();
    }
}

// @fnv 0x009c8640
NiTexture* FUN_009c8640_shell::FUN_009c8640()
{
    return (NiTexture*)(const char*)(*(BSStringT<char>*)((char*)this + 0x60));
}

void UpdateWaveAnimation(MapMenu*);
void UpdateHolotapePlayback(MapMenu*);
struct A7d
{
};
struct C7d
{
};
struct NoteReadState
{
};

// Updates the map menu: toggles the playing item, handles map input modes, moves the highlight, marks notes read, and refreshes the menu.
// @fnv 0x0079a130
void UpdateMapMenu(MapMenu* menu)
{
    unsigned int i;
    Tile* pcurrTile;
    float fhighlightX;
    float fhighlightY;
    BGSNote* pcurrNote;

    if (Interface::GetSelectedTargetIndex((Interface::enumMenus)0x3f5) && menu->m_pkActiveSoundList &&
        reinterpret_cast<::SoundPlaybackHandle *>(&((*(::SoundPlaybackHandle *)(new ((void *)(menu->m_pkActiveSoundList)) ::Vec3()))))->IsPlaying())
    {
        reinterpret_cast<::FUN_00ad88b0_h *>((&(*(::SoundPlaybackHandle *)(new ((void *)(menu->m_pkActiveSoundList)) ::Vec3()))))->FUN_00ad88b0();
        DAT_011da36f = true;
        DAT_011da40c = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    }
    else if (!Interface::GetSelectedTargetIndex((Interface::enumMenus)0x3f5) &&
             !Interface::GetSelectedTargetIndex((Interface::enumMenus)0x3e9) && menu->m_pkActiveSoundList &&
             DAT_011da36f)
    {
        reinterpret_cast<::FUN_00ad8830_shell *>(&((*(::SoundPlaybackHandle *)(new ((void *)(menu->m_pkActiveSoundList)) ::Vec3()))))->FUN_00ad8830(false);
        DAT_011da36f = false;
        menu->m_iMapSelectionIndex += reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011da40c;
    }

    if (!((::FOPipboyManager *)(::fnv_00705990::FUN_00705990()))->IsUnk28Set())
        return;

    if (Interface::GetSelectedTargetIndex(Interface::Map))
    {
        switch (DAT_011da368->m_iMapDisplayMode)
        {
        case 0x20:
            if ((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011da3b8)).Bool()->b && ((bool)(::GetByteAtOffsetB9((void *)(((::FOPipboyManager *)(::fnv_00705990::FUN_00705990())))))))
            {
                DAT_011da368->m_uiMapMarkerCount = 0;
                for (i = 0; i < 25; i++)
                    ::FUN_0079ffb0(false);
            }
        case 0x21:
            if (!FUN_004b71d0())
            {
                fhighlightX = reinterpret_cast<::MyHack *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007697f0() - reinterpret_cast<::FUN_00a013d0_shell *>((((A7d*)((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((menu->m_pTiles[6]))->FUN_0045cd60())))))->GetTotalFloat();
                fhighlightY =
                    ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->GetScaledValue() - reinterpret_cast<::FUN_00a01440_shell *>((((C7d*)((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((menu->m_pTiles[6]))->FUN_0045cd60())))))->GetAccumulatedFloat();
                if (fhighlightX < ::_DAT_01012060 || fhighlightY < ::_DAT_01012060 || fhighlightX > DAT_01074f68 ||
                    fhighlightY > 500.0)
                {
                    reinterpret_cast<::FUN_00a012d0_t *>((((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(0xfa9, 255.0f, true);
                }
                else
                {
                    reinterpret_cast<::FUN_00a012d0_t *>((((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(0xfa9, 0.0f, true);
                    if (reinterpret_cast<::ButtonDevice *>((((::InputManager *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()))))->FUN_00a23a50(1, 1) &&
                        !reinterpret_cast<::HotkeyWheelDisplay *>((((::InputManager *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()))))->SetHotkeyItem(0xe, 1))
                        menu->HandleSelection(0xc, 0);
                }
                fhighlightX -= menu->m_pTiles[6]->GetFloat(0xfb1) / 2.0;
                fhighlightY -= menu->m_pTiles[6]->GetFloat(0xfb0) / 2.0;
                reinterpret_cast<::FUN_00a012d0_t *>((menu->m_pTiles[6]))->FUN_00a012d0(0xfa1, fhighlightX, true);
                reinterpret_cast<::FUN_00a012d0_t *>((menu->m_pTiles[6]))->FUN_00a012d0(0xfa2, fhighlightY, true);
                reinterpret_cast<::FUN_00799dc0_class *>((menu))->UpdateMapHighlight();
            }
            break;
        case 0x23:
            if (menu->m_uiMapState)
            {
                if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - menu->m_uiMapState >= ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d47bc))))))->f * 1000.0)
                {
                    pcurrNote = menu->m_pSelectedNote;
                    pcurrTile = 0;
                    if (FUN_004b71d0() || !menu->m_pSelectedNote)
                        pcurrNote = menu->m_kNoteListBox.GetSelectedData();
                    pcurrTile = ((::Tile *)(reinterpret_cast<::Owner *>(&(menu->m_kNoteListBox))->FindItemData((int *)&(pcurrNote))));
                    if (pcurrNote && pcurrTile)
                    {
                        reinterpret_cast<::FUN_00a012d0_t *>((pcurrTile))->FUN_00a012d0(DAT_011da344, 128.0f, true);
                        reinterpret_cast<::FUN_005e9300_Host *>((((NoteReadState*)pcurrNote)))->SetRead(true);
                        menu->m_uiMapState = 0;
                    }
                }
            }
            break;
        case 0x24:
            if (FUN_00798440())
                UpdateWaveAnimation(menu);
            else
                reinterpret_cast<::FUN_0079c090_shell *>((menu))->FUN_0079c090();
            break;
        }
        DAT_011da408 = false;
    }
    else if (!DAT_011da408 && !FUN_004b71d0() && menu->m_iMapDisplayMode <= 0x21)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(0xfa9, 255.0f, true);
        DAT_011da408 = true;
    }

    if (menu->m_bMapListUpdatePending || menu->m_pkActiveSoundList)
        UpdateHolotapePlayback(menu);
}

struct FUN_007240c0
{
    FUN_007240c0();
    virtual void vfn();
};
struct SL
{
    SL();
    ~SL();
    int a, b;
};
struct FUN_007a1c90 : public FUN_007240c0, public SL
{
    int f0c, f10, f14, f18;
    short f1c;
    float f20, f24, f28;
    short f2c;
    FUN_007a1c90();
    virtual void vfn();
};
// Zeroes the list box fields, clears the selected tile, and calls AddToHeadList on this.
// @fnv 0x007a1c90
FUN_007a1c90::FUN_007a1c90()
{
    f14 = 0;
    f10 = 0;
    f0c = 0;
    f18 = 0;
    f2c = 0;
    f1c = 0;
    f28 = 0.0f;
    f24 = 0.0f;
    f20 = 0.0f;
    reinterpret_cast<::FlagS *>((reinterpret_cast<ListBox<TESQuest*>*>(this)))->FUN_007a1950((unsigned int)(0), true);
    ::AddToHeadList((int *)(void *)(this));
}

extern bool DAT_011da36d;
extern int DAT_011da360;
extern SettingT_GameSettingCollection_* DAT_011a03e4[];
int sprintf_s(char*, unsigned int, const char*, ...);
int _stricmp(const char*, const char*);
void FUN_00798840();
void FUN_00798710();

struct FUN_0053d280_shell
{
};
struct FUN_0083b9a0_shell
{
};
struct FUN_007a19a0_shell
{
};
struct FUN_007a1ac0_shell
{
};
struct FUN_007a2e30_shell
{
};
struct FUN_007a5730_shell
{
    void FUN_007a5730(bool (*)(TESChallenge*));
};

struct MapMenuClick : public MapMenu
{
    void FUN_00796fd0(int, Tile*);
};

extern bool DAT_011dd434;

// @fnv 0x00798440
bool FUN_00798440()
{
    return DAT_011dd434;
}


// If the global MapMenu exists and its field at offset 0x90 equals a1, resets that field to 0.
// @fnv 0x0079b430
void __cdecl FUN_0079b430(int aiValue)
{
    if (DAT_011da368 && *(int*)((char*)DAT_011da368 + 0x90) == aiValue)
    {
        *(int*)((char*)DAT_011da368 + 0x90) = 0;
    }
}


// @fnv 0x0079be80
void FUN_0079be80(Tile* pThis)
{
    pThis->Set(DAT_011da348, 0);
}


// @fnv 0x0079c070
unsigned int __cdecl FUN_0079c070()
{
    return DAT_011dd42c;
}


// @fnv 0x0079c080
BSSimpleList<unsigned int>* __cdecl FUN_0079c080()
{
    return &(*reinterpret_cast<::BSSimpleList<unsigned int> *>(&::g_011dd59c));
}

extern int DAT_011da35c;

// Returns the float setting at DAT_011da35c from DAT_011da368's tile, or 1.0f when DAT_011da368 is null.
// @fnv 0x007a17a0
float __cdecl GetMapMenuFloatSetting()
{
    float result;
    if (DAT_011da368)
        result = ((Tile*)*(void**)((void**)DAT_011da368 + 0x30 / 4))->GetFloat(DAT_011da35c);
    else
        result = 1.0f;
    return result;
}

struct FUN_00798420_shell
{
    char bUnk7d;
    char GetUnk7d();
};

// @fnv 0x00798420
char FUN_00798420_shell::GetUnk7d()
{
    return ((char*)this)[0x7d];
}

extern float DAT_01074f70;
extern float DAT_01074f74;

struct FUN_0079a610_shell
{
    void* fields[16];
    void* m_tile;
    void UpdateControllerTiles(bool abHas360Controller);
};

// When a 360 controller is present, sets tiles 0xFA1 and 0xFA2 on m_tile to the two global float values.
// @fnv 0x0079a610
void FUN_0079a610_shell::UpdateControllerTiles(bool abHas360Controller)
{
    if (abHas360Controller)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<Tile*>(m_tile)))->FUN_00a012d0(0xFA1, DAT_01074f74, true);
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<Tile*>(m_tile)))->FUN_00a012d0(0xFA2, DAT_01074f70, true);
    }
}

struct FUN_0079bc30_shell
{
    void* GetOffset6BC();
};

// @fnv 0x0079bc30
void* FUN_0079bc30_shell::GetOffset6BC()
{
    return reinterpret_cast<char*>(this) + 0x6BC;
}

struct FUN_0079f620_shell
{
    void* GetOffsetPointer();
};

// @fnv 0x0079f620
void* FUN_0079f620_shell::GetOffsetPointer()
{
    return reinterpret_cast<char*>(this) + 0x6F8;
}

struct FUN_00796a50_shell
{
    void FUN_00796a80();
    void* FUN_00796a50(unsigned int);
};
struct Unk00796f90
{
    char _pad[0x28];
    int _arr[0x16];
    bool HasNoZeroEntries();
};
// Returns false if any of the 0x16 ints in _arr is zero, otherwise returns true.
// @fnv 0x00796f90
bool Unk00796f90::HasNoZeroEntries()
{
    int i;
    for (i = 0; i < 0x16; ++i)
    {
        if (_arr[i] == 0)
            return false;
    }
    return true;
}

extern double const DAT_0106e7f8;
struct S
{
    float GetScaledValue();
};
// Returns the float at offset 0x4B0 multiplied by DAT_0106e7f8 and divided by the result of FUN_004dc200().
// @fnv 0x007983c0
float S::GetScaledValue()
{
    return (float)(*(float*)((char*)this + 0x4B0) * DAT_0106e7f8 / FUN_004dc200());
}

struct FUN_00798480_This
{
    void FUN_00798480(int aiID, Tile* apTarget);
};
// For ID 4, reads floats 4001 and 4002 from the Tile at offset 0x38 and stores them at offsets 0x120 and 0x124.
// @fnv 0x00798480
void FUN_00798480_This::FUN_00798480(int aiID, Tile* apTarget)
{
    if (aiID == 4)
    {
        *(float*)((char*)this + 0x120) = (*(Tile**)((char*)this + 0x38))->GetFloat(4001);
        *(float*)((char*)this + 0x124) = (*(Tile**)((char*)this + 0x38))->GetFloat(4002);
    }
}

struct MagicTarget;
struct MagicCaster_shell
{
    MagicTarget* FUN_0044edb0();
};
// Returns true if a1 is non-null and the MagicTarget at DAT_011da368+0xCC differs from a1's FUN_0044edb0() result.
// @fnv 0x0079bc50
bool FUN_0079bc50(MagicCaster_shell* pMagicCaster)
{
    return pMagicCaster && *(MagicTarget**)((char*)DAT_011da368 + 0xCC) != pMagicCaster->FUN_0044edb0();
}

struct RefH
{
};
// Returns true if p is null, disabled, or its object reference passes IsRadioStationTalkingActivator with 0.
// @fnv 0x0079be30
bool FUN_0079be30(RefH* apRef)
{
    return apRef == 0 || reinterpret_cast<::TESForm *>((apRef))->GetDisabled() || ::fnv_004fee60::IsRadioStationTalkingActivator((::fnv_004fee60::TESForm *)(void *)(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))));
}

struct Helper007fa0f0
{
};
// If DAT_011da368 is set, calls SetValue on the PipboyManager with the value at DAT_011da368+0x80 minus 0x20 and a.
// @fnv 0x0079c340
void FUN_0079c340(bool a)
{
    if (DAT_011da368)
        reinterpret_cast<::FUN_007fa0f0_Class *>((((Helper007fa0f0*)((Interface*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->GetPipboyManager())))->SetValue(*(int*)((char*)DAT_011da368 + 0x80) - 0x20, a);
}

struct GlobalObject_0045cfe0
{
};
struct DAT_011da368_tag
{
    char _pad[0x128];
    unsigned int f;
};
// @fnv 0x007a1750
bool FUN_007a1750()
{
    return (*reinterpret_cast<::DAT_011da368_tag * *>(&::DAT_011da368)) != 0 && (*reinterpret_cast<::DAT_011da368_tag * *>(&::DAT_011da368))->f < *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) * *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))));
}

namespace fnv_007a17e0 {
struct S011da368
{
    char pad[56];
    Tile* tile;
};
// Returns the tile's float value for DAT_011da35c when _DAT_011da368 is set, otherwise returns 1.0f.
// @fnv 0x007a17e0
float GetTileFloatOrDefault()
{
    float fValue;
    if ((*reinterpret_cast<::fnv_007a17e0::S011da368 * *>(&::DAT_011da368)))
        fValue = (*reinterpret_cast<::fnv_007a17e0::S011da368 * *>(&::DAT_011da368))->tile->GetFloat(DAT_011da35c);
    else
        fValue = 1.0f;
    return fValue;
}
}  // namespace fnv_007a17e0

struct FUN_007a5a30_Host
{
    char _pad[12];
    Tile* tileAtC;
    void FUN_007a5a30(bool);
};
// Calls Set on tileAtC with value 0xFA3 and the given bool.
// @fnv 0x007a5a30
void FUN_007a5a30_Host::FUN_007a5a30(bool a1)
{
    tileAtC->Set(0xFA3, a1);
}

struct S007a6280
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5(int);
    unsigned int FUN_007a6280();
};
struct FUN_007312e0_shell : Tile
{
    void FUN_007312e0();
};

// @fnv 0x007312e0
void FUN_007312e0_shell::FUN_007312e0()
{
    *(float*)((char*)this + 0x24) = *(TileListBoxCalls**)((char*)this + 0x10)
                                        ? ((TileListBoxCalls**)((char*)this + 0x10))[0]->GetFloat(0xfac)
                                        : -1.0f;
    *(float*)((char*)this + 0x28) =
        *(TileListBoxCalls**)((char*)this + 0x14)
            ? ((TileListBoxCalls**)((char*)this + 0x14))[0]->GetFloat(Tile::GetTraitID("_current_value"))
            : -1.0f;
}

struct FUN_0079b800_shell
{
    bool IsFlagSet();
};

// @fnv 0x0079b800
bool FUN_0079b800_shell::IsFlagSet()
{
    return *(const unsigned short*)((const char*)this + 0x5c) & 4;
}

extern int DAT_01075530;

struct FUN_007a1aa0_shell : public BSSimpleArray<BSStringT<char>, 1024>
{
    void FUN_007a1aa0();
};

// @fnv 0x007a1aa0
void FUN_007a1aa0_shell::FUN_007a1aa0()
{
    *reinterpret_cast<int**>(this) = &DAT_01075530;
    reinterpret_cast<::fnv_007a1c30::FUN_007a1c30_holder *>(this)->ClearBuffer(true);
}

struct VATSMenu
{
    int FUN_007a7830();
    void* fields[13];
};
// Returns v5 called with the result of FUN_007a7830(0) minus one.
// @fnv 0x007a6280
unsigned int S007a6280::FUN_007a6280()
{
    return v5(reinterpret_cast<::VATSMenu *>(this)->FUN_007a7830() - 1);
}
extern int DAT_011da4a8;
extern int DAT_011da4ac;
extern const char $SG7947[];
// @fnv 0x007a7830
int VATSMenu::FUN_007a7830()
{
    static int numFiltered = ::FUN_00a00940($SG7947, -1);
    return ::GetRaceCount((char *)this) - (unsigned int)((Tile*)fields[3])->GetFloat(numFiltered);
}

namespace fnv_006f49c0 {
struct PathingPath
{
    void Clear();
    float CalculatePathDistance();
    void* __vecDelDtor(unsigned int);
    char Spaces[16];
    char Doors[16];
    NiPoint3 Start;
    NiPoint3 End;
};
struct FUN_006f49c0_shell : public PathingPath
{
    float GetPathLength();
};

struct Pt
{
    float x, y, z;
};
struct NiPoint3Ex : Pt
{
    NiPoint3Ex operator-(const NiPoint3&) const;
};
struct DoorRef
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
    virtual const NiPoint3Ex* GetPos();
};
struct DoorEntry
{
    DoorRef* door;
    NiPoint3 pos;
};
struct ArrHelper
{
};
struct ArrSI
{
};
struct S006949d0
{
    DoorEntry* GetFirst();
    DoorEntry* FUN_006cedb0();
};

// @fnv 0x006f49c0
float FUN_006f49c0_shell::GetPathLength()
{
    float ftotalLength = 0.0f;
    unsigned int i;
    if (reinterpret_cast<::FUN_0076b610_Class *>((void *)(((ArrHelper*)Spaces)))->FUN_0076b610())
        return -1.0f;
    if (reinterpret_cast<::FUN_0076b610_Class *>((void *)(((ArrHelper*)Doors)))->FUN_0076b610())
        return reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_006f49c0::Pt &)((((const NiPoint3Ex&)End) - Start)))->ComputeMagnitude();
    ftotalLength += reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_006f49c0::Pt &)((*((S006949d0*)Doors)->GetFirst()->door->GetPos() - Start)))->ComputeMagnitude();
    for (i = 1; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)Doors)))->GetName())); i++)
        ftotalLength +=
            reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_006f49c0::Pt &)((*((::fnv_006f49c0::DoorEntry *)(reinterpret_cast<::FUN_00558dd0_class *>((((S006949d0*)Doors)))->FUN_00558dd0(i)))->door->GetPos() - ((::fnv_006f49c0::DoorEntry *)(reinterpret_cast<::FUN_00558dd0_class *>((((S006949d0*)Doors)))->FUN_00558dd0(i - 1)))->pos)))->ComputeMagnitude();
    ftotalLength += reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_006f49c0::Pt &)((((const NiPoint3Ex&)End) - ((S006949d0*)Doors)->FUN_006cedb0()->pos)))->ComputeMagnitude();
    return ftotalLength;
}
}  // namespace fnv_006f49c0

namespace fnv_00798a00 {
struct PlayerTargetLocation
{
    char data[0x34];
};
struct FUN_00456540_shell : public PlayerTargetLocation
{
    FUN_00456540_shell();
};
struct FUN_0093be30_shell
{
};
struct DAT_011da368_shell
{
    char data[0x118];
    PlayerTargetLocation* ms_pInventoryMenu;
};
// @fnv 0x00798a00
void FUN_00798a00()
{
    if ((*reinterpret_cast<::fnv_00798a00::DAT_011da368_shell * *>(&::DAT_011da368)) && (*reinterpret_cast<::fnv_00798a00::DAT_011da368_shell * *>(&::DAT_011da368))->ms_pInventoryMenu)
    {
        FUN_00456540_shell* loc = new FUN_00456540_shell;
        *(PlayerTargetLocation**)(loc->data + 0x30) = (*reinterpret_cast<::fnv_00798a00::DAT_011da368_shell * *>(&::DAT_011da368))->ms_pInventoryMenu;
        reinterpret_cast<::B93BE30ProcessManager *>(((*reinterpret_cast<::fnv_00798a00::FUN_0093be30_shell * *>(&::_g_thePlayer))))->FUN_0093be30((::B93BE30Request *)(loc));
        (*reinterpret_cast<::fnv_00798a00::DAT_011da368_shell * *>(&::DAT_011da368))->ms_pInventoryMenu = 0;
    }
}
}  // namespace fnv_00798a00

struct DialogMenuAudioCalls
{
public:
    void EnableAudio();
};
struct BSAudioStatics
{
};
struct FUN_00798ad0_shell : public MapMenu
{
    void StopHolotapeAudio();
};
namespace fnv_0079b8e0 {
namespace S {
struct BSSimpleList
{
    bool _ref_008256d0();
};
struct RegionObjectEntry
{
};
struct BSAudio
{
    void* GetAudioBackendData();
};
}
struct BGSQuestObjective
{
};
struct FNStub
{
};
struct FUN_006317a0_struct
{
};
struct FUN_0079bc30_shell
{
};
struct IMStandIn
{
};
struct MagicCaster_shell;
struct InterfaceManager;
extern float DAT_01074ffc;
struct ListBoxS
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void V4();
    virtual void A5();
    virtual void A6();
    virtual void V7();
    virtual void V8(bool(__cdecl*)(void*));
    Tile* FUN_007a44e0(BGSQuestObjective*, const char*, int, int);
    Tile* InsertTileFromTemplate(TESQuest*, const char*, int, int);
    void FUN_007a2350(bool);
    void ApplyObjectiveFilter(bool(__cdecl*)(MagicCaster_shell*));
};
struct FUN_0079b8e0_shell
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void V4(int, Tile*);
    void UpdateQuestObjectiveList();
};

// @fnv 0x0079b8e0
void FUN_0079b8e0_shell::UpdateQuestObjectiveList()
{
    ((ListBoxS*)((char*)this + 0x130))->V7();
    ((ListBoxS*)((char*)this + 0x1c0))->V7();
    S::BSSimpleList* pobjectiveList;
    for (pobjectiveList = (S::BSSimpleList*)reinterpret_cast<::FUN_0079bc30_shell *>((((FUN_0079bc30_shell*)(*reinterpret_cast<void * *>(&::_g_thePlayer)))))->GetOffset6BC();
         pobjectiveList && !pobjectiveList->_ref_008256d0(); pobjectiveList = ((::fnv_0079b8e0::S::BSSimpleList *)(reinterpret_cast<::Callees *>((pobjectiveList))->FUN_00726070())))
    {
        TESQuest* pQuest =
            (TESQuest*)((S::BSAudio*)*((int *)(new ((void *)(((S::RegionObjectEntry*)pobjectiveList))) ::Vec3())))->GetAudioBackendData();
        if (reinterpret_cast<::BGSQuestObjective *>((void *)(((BGSQuestObjective*)*((int *)(new ((void *)(((S::RegionObjectEntry*)pobjectiveList))) ::Vec3())))))->GetDisplayed())
        {
            Tile* pTile =
                ((ListBoxS*)((char*)this + 0x1c0))
                    ->FUN_007a44e0(
                        (BGSQuestObjective*)*((int *)(new ((void *)(((S::RegionObjectEntry*)pobjectiveList))) ::Vec3())),
                        reinterpret_cast<::FUN_005ec330_shell *>((((BGSQuestObjective*)*((int *)(new ((void *)(((S::RegionObjectEntry*)pobjectiveList))) ::Vec3())))))->GetPromptText(),
                        0, 0);
            reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)reinterpret_cast<::FUN_006317a0_struct *>((((FUN_006317a0_struct*)((char*)pTile + 4))))->AddEight((int)((::fnv_0079b8e0::S::BSSimpleList *)(reinterpret_cast<::Callees *>((((S::BSSimpleList*)((char*)pTile + 4))))->FUN_00726070()))))))->FUN_00a012d0(0xfba, DAT_01074ffc, true);
            pTile->Set(Tile::GetTraitID("_ShowEmptyMarker"), 1);
            pTile->Set(Tile::GetTraitID("_enabled"), 0);
            if (reinterpret_cast<::BGSQuestObjective *>((void *)(((BGSQuestObjective*)*((int *)(new ((void *)(((S::RegionObjectEntry*)pobjectiveList))) ::Vec3())))))->GetCompleted())
            {
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(DAT_011da344, 128.0f, true);
                pTile->Set(DAT_011da348, 1);
            }
            else if (reinterpret_cast<::FUN_0059e400_shell *>((pQuest))->FUN_0059e400())
            {
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(DAT_011da344, 128.0f, true);
            }
            else
            {
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(DAT_011da344, 255.0f, true);
            }
            if (!((::Tile *)(reinterpret_cast<::Owner *>((((ListBox<BGSNote*>*)((char*)this + 0x130))))->FindItemData((int *)&((BGSNote*&)pQuest)))))
            {
                Tile* pTile = ((ListBoxS*)((char*)this + 0x130))
                                  ->InsertTileFromTemplate(
                                      pQuest, (const char*)((void *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)pQuest + 0x30))))->FUN_00408da0())), 0, 0);
                pTile->Set(0xfaa, 0x17);
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(DAT_011da344, reinterpret_cast<::FUN_0059e400_shell *>((pQuest))->FUN_0059e400() ? 128.0f : 255.0f, true);
                if (pQuest == (TESQuest*)::FUN_005cbb50((char*)(*reinterpret_cast<void * *>(&::_g_thePlayer))))
                    pTile->Set(DAT_011da348, 1);
            }
        }
    }
    ((ListBoxS*)((char*)this + 0x1c0))->V8(((bool (&)(void *))::FUN_0079bc90));
    ((ListBoxS*)((char*)this + 0x130))->V8(((bool (&)(void *))::FUN_0079bc90));
    ((ListBoxS*)((char*)this + 0x130))->FUN_007a2350(true);
    if (::FUN_005cbb50((char*)(*reinterpret_cast<void * *>(&::_g_thePlayer))))
    {
        Tile* pactiveQuestTile;
        {
            BGSNote* pactive = (BGSNote*)::FUN_005cbb50((char*)(*reinterpret_cast<void * *>(&::_g_thePlayer)));
            pactiveQuestTile = ((::Tile *)(reinterpret_cast<::Owner *>((((ListBox<BGSNote*>*)((char*)this + 0x130))))->FindItemData((int *)&(pactive))));
        }
        V4(0x17, pactiveQuestTile);
        if (::FUN_004b71d0())
        {
            reinterpret_cast<::FocusManager *>((((IMStandIn*)((::fnv_0079b8e0::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860((::FocusTile *)((int)pactiveQuestTile), 0xfc3, 1);
            ((ListBoxS*)((char*)this + 0x130))->V4();
        }
    }
    else
    {
        ((ListBoxS*)((char*)this + 0x1c0))->ApplyObjectiveFilter(((bool (&)(fnv_0079b8e0::MagicCaster_shell *))::FUN_0079bc50));
    }
}
}  // namespace fnv_0079b8e0

struct FUN_004a0c90_shell
{
    unsigned int field0;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    unsigned int field4;
    unsigned int field5;
    unsigned int field6;
    unsigned int field7;
    unsigned int field8;
    void FUN_004a0c90(float);
};

struct TESObjectCELL_Ext
{
    float FUN_00555ad0();
    void FUN_00555b10(NiPoint3 const& source, NiPoint3& destination, bool invert);
};



// @fnv 0x00555b10
void TESObjectCELL_Ext::FUN_00555b10(NiPoint3 const& source, NiPoint3& destination, bool invert)
{
    FUN_004a0c90_shell shell;
    float f = this->FUN_00555ad0() * (invert ? -1.0f : 1.0f);

    if (f != 0.0)
    {
        shell = (*reinterpret_cast<::FUN_004a0c90_shell *>(&::DAT_011a9448));
        shell.FUN_004a0c90(f);
        destination = (*(::NiPoint3 *)(::FUN_004b3ae0((::NiPoint3 *)&(source), (*(const ::NiPoint3 *)(reinterpret_cast<float const*>(&shell))), {})));
    }
    else
    {
        destination = source;
    }
}

class TESReputation
{
  public:
    const char* FUN_00616710();
};


// Looks up the positive and negative reputation indices and returns the title string from the 4x4 table of game settings.
// @fnv 0x00616710
const char* TESReputation::FUN_00616710()
{
    char cPosIndex;
    char cNegIndex;
    SettingT_GameSettingCollection_* pRepTitles[4][4] = {{&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbce4)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbd28)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbbb0)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbc08))},
                                                         {&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbd74)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbbf0)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbc60)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbb2c))},
                                                         {&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbc40)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cba88)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbb58)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbbd8))},
                                                         {&(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbcfc)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbd84)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbb04)), &(*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cba0c))}};

    cPosIndex = 0;
    cNegIndex = 0;
    cPosIndex = ((int)(reinterpret_cast<::ReputationTracker *>((this))->GetReputationRank(1)));
    cNegIndex = ((int)(reinterpret_cast<::ReputationTracker *>((this))->GetReputationRank(0)));
    return ((const char *)(reinterpret_cast<::StartMenu *>((pRepTitles[cNegIndex][cPosIndex]))->GetMenuTitle()));
}

struct S006949d0
{
    char pad[8];
    int count;  // +0x8
    void FUN_006cedb0();
};

// @fnv 0x006cedb0
void S006949d0::FUN_006cedb0()
{
    reinterpret_cast<::FUN_00558dd0_class *>(this)->FUN_00558dd0(count - 1);
}

namespace fnv_0079b460 {
struct FUN_007a59a0_Host
{
    void FUN_007a59a0(bool);
};

struct FUN_007a30e0_Host
{
    void FUN_007a30e0(bool);
};

struct FUN_007a5a30_Host
{
};

struct FUN_0079b460_shell : public MapMenu
{
    void FUN_0079b460(bool);
};

extern const char $SG3295[];

// @fnv 0x0079b460
void FUN_0079b460_shell::FUN_0079b460(bool abToggle)
{
    Tile* pchallengeText;

    if (abToggle)
        DAT_011da36d = !DAT_011da36d;

    reinterpret_cast<FUN_007a59a0_Host*>(reinterpret_cast<char*>(this) + 0x1f0)->FUN_007a59a0(DAT_011da36d);
    reinterpret_cast<::FUN_007a5a30_Host *>((reinterpret_cast<FUN_007a5a30_Host*>(reinterpret_cast<char*>(this) + 0x1f0)))->FUN_007a5a30(DAT_011da36d);

    reinterpret_cast<FUN_007a30e0_Host*>(reinterpret_cast<char*>(this) + 0x160)->FUN_007a30e0(!DAT_011da36d);
    reinterpret_cast<::FUN_007a5a30_Host *>((reinterpret_cast<FUN_007a5a30_Host*>(reinterpret_cast<char*>(this) + 0x160)))->FUN_007a5a30(!DAT_011da36d);

    (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x5c))->Set(0xfa3, 1);

    if (abToggle)
    {
        pchallengeText =
            reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>(((*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x5c))))->FUN_00a03da0((char *)("MM_DataText"));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pchallengeText))->FUN_00a01350(0xfc4, (char *)($SG3295), true);
    }

    if (DAT_011da36d)
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<Tile**>(reinterpret_cast<char*>(::DAT_011da368) + 0x70))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d2d18))))->GetMenuTitle()))), true);
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(::DAT_011da368) + 0x7c))->Set(0xfa3, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x7c))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((DAT_011a03e4[::DAT_011da36e]))->GetMenuTitle()))), true);
    }
    else
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<Tile**>(reinterpret_cast<char*>(::DAT_011da368) + 0x70))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d2a78))))->GetMenuTitle()))), true);
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(::DAT_011da368) + 0x58))->Set(0xfaf, 1);
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(::DAT_011da368) + 0x7c))->Set(0xfa3, 0);
    }

    if (abToggle)
        reinterpret_cast<::MapMenu *>(this)->FUN_0079af30();
}
}  // namespace fnv_0079b460

namespace fnv_0079b720 {
struct TESChallenge
{
    TESObjectREFR* GetProgressValue();
};

struct FUN_0079b800_shell
{
};

struct FUN_005def70_Class
{
};


// @fnv 0x0079b720
bool __cdecl FUN_0079b720(TESChallenge* challenge)
{
    bool result = true;
    {
        int challengeType;

        if ((*reinterpret_cast<int *>(&::DAT_011da368)) != 0)
        {
            if (((int)(::FUN_005a60d0((const char *)(challenge)))) != 0)
                result = true;
        }

        challengeType = ((int)(reinterpret_cast<::FUN_006a1b60_Class *>((challenge))->GetField54()));

        if ((int)challenge->GetProgressValue() <= 0)
        {
            if (!reinterpret_cast<::FUN_0079b800_shell *>((((FUN_0079b800_shell*)challenge)))->IsFlagSet())
            {
                if (reinterpret_cast<::FUN_005def70_Class *>((((FUN_005def70_Class*)challenge)))->FUN_005def70() == 0)
                    return true;
            }
        }

        if (::DAT_011da36e == 0)
        {
            if (challengeType == 2 || challengeType == 0 || challengeType == 1)
                return false;
        }

        if (::DAT_011da36e == 1)
        {
            if (challengeType == 3 || challengeType == 8)
                return false;
        }

        if (::DAT_011da36e == 2)
        {
            if (challengeType == 11 || challengeType == 10 || challengeType == 9 || challengeType == 6 ||
                challengeType == 5 || challengeType == 4 || challengeType == 12 || challengeType == 13)
                return false;
        }

        return result;
    }
}
}  // namespace fnv_0079b720

struct MobileObject
{
};

struct FUN_0079bd70_data
{
    Tile* pTile;
    MobileObject* pMobileObject;
};


// @fnv 0x0079bd70
int __cdecl CompareMobileObjects(FUN_0079bd70_data* pFirst, FUN_0079bd70_data* pSecond)
{
    int result = 0;

    if (pFirst->pTile->GetFloat(DAT_011da344) == 255.0 && pFirst->pTile->GetFloat(DAT_011da344) != 255.0)
    {
        result = -1;
    }
    else if (pFirst->pTile->GetFloat(DAT_011da344) != 255.0 && pFirst->pTile->GetFloat(DAT_011da344) == 255.0)
    {
        result = 1;
    }
    else
    {
        result = FUN_00408b20(reinterpret_cast<::FUN_0055d520_shell *>((pFirst->pMobileObject))->FUN_0055d520(), reinterpret_cast<::FUN_0055d520_shell *>((pSecond->pMobileObject))->FUN_0055d520());
    }

    return result;
}

extern double DAT_01075008;
extern double DAT_01075010;

struct FUN_0079c380_shell : TESObjectREFR
{
    NiPoint3* GetMarkerPosition(NiPoint3* result, NiPoint3 position, TESWorldSpace* worldSpace);
};

// @fnv 0x0079c380
NiPoint3* FUN_0079c380_shell::GetMarkerPosition(NiPoint3* result, NiPoint3 position, TESWorldSpace* worldSpace)
{
    NiPoint3 markerPosition;

    if (worldSpace != 0 && *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x80) == 0x21)
    {
        reinterpret_cast<::FUN_00588e40_shell *>((worldSpace))->TransformWorldPoint((::Pt3 *)&(position), false);
    }

    markerPosition.x = (position.x - *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xe8)) /
                       (*reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xf0) -
                        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xe8));

    markerPosition.y = (position.y - *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xec)) /
                       (*reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xf4) -
                        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0xec));

    markerPosition.z = 0.0f;

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x80) == 0x21)
    {
        markerPosition.x = markerPosition.x * DAT_01075010 + DAT_01075008;
        markerPosition.y = markerPosition.y * DAT_01075010 + DAT_01075008;
    }

    *result = markerPosition;
    return result;
}

struct FUN_007a86b0_Item
{
    char data[8];
};

struct FUN_007a63b0_holder
{
    void FUN_007a63b0(FUN_007a86b0_Item*, unsigned int);
};

struct FUN_006f3170_Class
{
    bool FUN_006f3170(void);
};

struct FUN_00869600_Class
{
    unsigned int FUN_00869600(void);
};

struct FUN_006c8a30_Class
{
};

struct FUN_00692480
{
    virtual void FUN_00692480_dummy(void);
    virtual FUN_007a86b0_Item* FUN_00692480_alloc(unsigned int);

    void Method(char*, char*, unsigned int);
};

struct FUN_007a1b10_shell
{
    virtual void FUN_007a1b10_dummy(void);
    virtual FUN_007a86b0_Item* FUN_007a1b10_alloc(unsigned int);

    FUN_007a86b0_Item* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void RemoveAt(unsigned int, bool);
};

// @fnv 0x007a1b10
void FUN_007a1b10_shell::RemoveAt(unsigned int aiIndex, bool abShrink)
{
    unsigned int inewSize;
    FUN_007a86b0_Item* pnewBuffer;

    if (abShrink && reinterpret_cast<FUN_006f3170_Class*>(this)->FUN_006f3170())
    {
        inewSize = reinterpret_cast<FUN_00869600_Class*>(this)->FUN_00869600();
        pnewBuffer = this->FUN_007a1b10_alloc(inewSize);

        reinterpret_cast<FUN_00692480*>(this)->Method(reinterpret_cast<char*>(pnewBuffer),
                                                      reinterpret_cast<char*>(this->pBuffer), aiIndex);

        reinterpret_cast<FUN_007a63b0_holder*>(this)->FUN_007a63b0(this->pBuffer + aiIndex, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(reinterpret_cast<char*>(pnewBuffer + aiIndex),
                                                      reinterpret_cast<char*>(this->pBuffer + aiIndex + 1),
                                                      this->iSize - 1);

        ::FUN_006a8500((::DummyClass_006a8500 *)(reinterpret_cast<FUN_006c8a30_Class*>(this)));
        this->pBuffer = pnewBuffer;
        this->SimpleArrayStorage = inewSize;
    }
    else
    {
        reinterpret_cast<FUN_007a63b0_holder*>(this)->FUN_007a63b0(this->pBuffer + aiIndex, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(reinterpret_cast<char*>(this->pBuffer + aiIndex),
                                                      reinterpret_cast<char*>(this->pBuffer + aiIndex + 1),
                                                      this->iSize - aiIndex - 1);
    }

    this->iSize = this->iSize - 1;
}

struct FUN_007a4c50_shell
{
    void* fields[3];
    Tile* m_pListTile;
    void SetEnabledTrait(bool);
};

// Sets the _enabled trait on the Tile to abVal using the cached trait index.
// @fnv 0x007a4c50
void FUN_007a4c50_shell::SetEnabledTrait(bool abVal)
{
    static int enabledTrait = ::FUN_00a00940("_enabled", -1);
    m_pListTile->Set(enabledTrait, abVal);
}

namespace fnv_007a6a50 {
class VATSMenu
{
  public:
};

class FUN_007a6a50_shell : public VATSMenu
{
  public:
    void* vptr;
    char padding[8];
    Tile* m_pListTile;

    unsigned int GetUnfilteredCount();
};

// @fnv 0x007a6a50
unsigned int FUN_007a6a50_shell::GetUnfilteredCount()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);

    return ::GetRaceCount((char *)this) - (unsigned int)m_pListTile->GetFloat(numFiltered);
}
}  // namespace fnv_007a6a50

struct FNVEmitter;
struct FNVLinkedNode
{
};
struct FNVLinkedList
{
};
struct FNVElement
{
    int data0;
    int data4;
    FNVElement();
};
struct FNVEmitter
{
    FNVEmitter* FUN_00586390(int type);
    FNVElement* GetOrCreateElement(bool createNew);
};

// Returns an existing element from the type-2 emitter when not creating new, otherwise allocates one, registers it, and propagates it to linked emitters.
// @fnv 0x005882a0
FNVElement* FNVEmitter::GetOrCreateElement(bool createNew)
{
    FNVElement* result = 0;
    if (FUN_00586390(2) && !createNew)
    {
        result = FUN_00586390(2)->GetOrCreateElement(false);
    }
    else
    {
        result = new FNVElement;
        reinterpret_cast<::FUN_005884e0_owner *>(this)->FUN_005884e0((::TESObjectREFR *)(result));
        if (!createNew)
        {
            FNVLinkedNode* node = ((::FNVLinkedNode *)(::FUN_00460140((int)((*reinterpret_cast<::FNVLinkedList * *>(&::g_dataHandler))))));
            while (node)
            {
                FNVEmitter* emitter = *((::FNVEmitter **)(new ((void *)(node)) ::Vec3()));
                if (emitter && emitter->FUN_00586390(2) == this)
                {
                    reinterpret_cast<::FUN_005884e0_owner *>((emitter))->FUN_005884e0((::TESObjectREFR *)(result));
                }
                node = ((::FNVLinkedNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            }
        }
    }
    return result;
}

struct HandlerRegistration
{
    unsigned int id;
    unsigned int status;
    void* handler;
    HandlerRegistration* next;
    ~HandlerRegistration();
};
struct HandlerArgument
{
    unsigned int type;
    unsigned int data;
    unsigned int flags;
    HandlerArgument(int value);
    ~HandlerArgument();
};
struct QueueOwner
{
    unsigned int state;
    unsigned int capacity;
    unsigned int flags;
    HandlerRegistration* first;
    void ClearQueue();
};
// @fnv 0x00798bf0
void MapMenu::StopMapMenuSounds()
{
    if (DAT_011da368)
    {
        if (DAT_011da368->m_pkActiveSoundList && reinterpret_cast<::SoundPlaybackHandle *>(&((*(::SoundPlaybackHandle *)(new ((void *)(DAT_011da368->m_pkActiveSoundList)) ::Vec3()))))->IsPlaying())
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*(::SoundPlaybackHandle *)(new ((void *)(DAT_011da368->m_pkActiveSoundList)) ::Vec3()))))->FUN_00ad88f0();
        reinterpret_cast<::QueueOwner *>(&(DAT_011da368->m_kSoundList))->ClearQueue();
        reinterpret_cast<::fnv_007a1c30::FUN_007a1c30_holder *>(&(DAT_011da368->SubtitlesToShow))->ClearBuffer(true);
        DAT_011da368->m_pkActiveSoundList = 0;
        DAT_011da368->m_fMapZoom = 0.0f;
        DAT_011da368->m_iMapSelectionIndex = 0;
        DAT_011da368->m_bMapListUpdatePending = false;
    }
}
// @fnv 0x00798ad0
void FUN_00798ad0_shell::StopHolotapeAudio()
{
    if (m_pkActiveSoundList && reinterpret_cast<::SoundPlaybackHandle *>(&((*(::SoundPlaybackHandle *)(new ((void *)(m_pkActiveSoundList)) ::Vec3()))))->IsPlaying())
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*(::SoundPlaybackHandle *)(new ((void *)(m_pkActiveSoundList)) ::Vec3()))))->FUN_00ad88f0();
    reinterpret_cast<::QueueOwner *>(&(m_kSoundList))->ClearQueue();
    reinterpret_cast<::fnv_007a1c30::FUN_007a1c30_holder *>(&(SubtitlesToShow))->ClearBuffer(true);
    m_pkActiveSoundList = 0;
    m_fMapZoom = 0.0f;
    m_iMapSelectionIndex = 0;
    m_bMapListUpdatePending = false;
    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyHolotapeStop", 0x121)))->FUN_00ad8830(false);
    reinterpret_cast<::FUN_00ad8650_cls *>((reinterpret_cast<DialogMenuAudioCalls*>(::FUN_00453a70())))->FUN_00ad8650();
    ::BSAudio::DeactivateAudio();
}
// Deletes every node in the linked list, nulling each node's next pointer, then calls FUN_00418900 with a HandlerArgument(0).
// @fnv 0x0076b7a0
void QueueOwner::ClearQueue()
{
    while (first != 0)
    {
        HandlerRegistration* next = first->next;
        first->next = 0;
        delete first;
        first = next;
    }
    reinterpret_cast<::SoundPlaybackHandle *>(this)->operator=((const ::SoundPlaybackHandle &)((const ::HandlerArgument &)(HandlerArgument(0))));
}

struct MenuBase0
{
    virtual ~MenuBase0();
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
struct Snd98
{
    ~Snd98();
    int a0;
    int a4;
    int a8;
    int ac;
};
struct SubA8
{
    ~SubA8();
    int a0;
    int a4;
    int a8;
    int ac;
};
struct RefList
{
    ~RefList();
    int a0;
    int a4;
public:
    bool FUN_005f65d0(void **);
};
struct LB130
{
    ~LB130();
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
};
struct LB160
{
    ~LB160();
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
};
struct LB190
{
    ~LB190();
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
};
struct LB1C0
{
    ~LB1C0();
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
};
struct LB1F0
{
    ~LB1F0();
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
};
struct Dbg220
{
    ~Dbg220();
    int a0;
    int a4;
    int a8;
    int ac;
};
struct FUN_00796a80 : MenuBase0
{
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
    Snd98 m98;
    SubA8 mA8;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    RefList mD8;
    RefList mE0;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    LB130 m130;
    LB160 m160;
    LB190 m190;
    LB1C0 m1C0;
    LB1F0 m1F0;
    Dbg220 m220;
    virtual ~FUN_00796a80();
};
// Calls FUN_00796a80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00796a50
void* FUN_00796a50_shell::FUN_00796a50(unsigned int flags)
{
    reinterpret_cast<::FUN_00796a80 *>(this)->FUN_00796a80::~FUN_00796a80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Clears the global DAT_011da368 to zero when this menu object is destroyed.
// @fnv 0x00796a80
FUN_00796a80::~FUN_00796a80()
{
    DAT_011da368 = 0;
}

class B799100SpellList
{
  public:
};

class B799100ActiveEffect
{
  public:
};

class B799100EffectNode
{
  public:
};

class B799100MagicTarget
{
  public:
};

class B799100State
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
    B799100ActiveEffect* m_pkFoundEffect;
};


// @fnv 0x00799100
void __cdecl FUN_00799100(void* pvUnused, B799100MagicTarget* pkTarget)
{
    if (!(*reinterpret_cast<::B799100State * *>(&::DAT_011da368))->m_pkFoundEffect && pkTarget && !reinterpret_cast<::BGSQuestObjective *>((pkTarget))->GetCompleted())
    {
        for (B799100EffectNode* pkIter = ((::B799100EffectNode *)(reinterpret_cast<::NonActorMagicTarget *>((pkTarget))->GetActiveEffectList()));
             !(*reinterpret_cast<::B799100State * *>(&::DAT_011da368))->m_pkFoundEffect && pkIter && *((::B799100ActiveEffect **)(new ((void *)(pkIter)) ::Vec3())); pkIter = ((::B799100EffectNode *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070())))
        {
            B799100ActiveEffect* pkEffect = *((::B799100ActiveEffect **)(new ((void *)(pkIter)) ::Vec3()));
            if (reinterpret_cast<::PerkEntryConditionSet *>((((::B799100SpellList *)(reinterpret_cast<::BaseProcess *>((pkEffect))->GetCurrentProcessData()))))->ContainsTrait((::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::RegionObjectEntry *>((pkEffect))->GetReference(0)))), {}))
                (*reinterpret_cast<::B799100State * *>(&::DAT_011da368))->m_pkFoundEffect = pkEffect;
        }
    }
}

class B79B820Tile
{
  public:
};

class B79B820SoundFile
{
  public:
};

struct B79B820Form
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B79B820SoundFile m_kSoundFile;
};

struct B79B820Item
{
    B79B820Tile* m_pkTile;
    B79B820Form* m_pkForm;
};



// Compares two items by a tile float value (128/255 ordering) or, otherwise, by their sound file names via FUN_00408b20.
// @fnv 0x0079b820
int __cdecl CompareItems(B79B820Item* pkA, B79B820Item* pkB)
{
    int iResult = 0;
    float fA5 = reinterpret_cast<::TileListBoxCalls *>((pkA->m_pkTile))->GetFloat(::DAT_011da344);
    float fB5 = reinterpret_cast<::TileListBoxCalls *>((pkB->m_pkTile))->GetFloat(::DAT_011da344);
    if (fA5 == 128.0 && fB5 == 255.0)
        iResult = 1;
    else if (fA5 == 255.0 && fB5 == 128.0)
        iResult = -1;
    else
        iResult = FUN_00408b20(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)&(pkA->m_pkForm->m_kSoundFile))->FUN_00408da0())), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)&(pkB->m_pkForm->m_kSoundFile))->FUN_00408da0())));
    return iResult;
}

class FUN_00a011b0_owner_b9258
{
  public:
};


// Compares two objects by a value at DAT_011da344, falling back to the value at 0xfac, returning -1, 0 or 1.
// @fnv 0x0079bc90
int __cdecl FUN_0079bc90(FUN_00a011b0_owner_b9258** apFirst, FUN_00a011b0_owner_b9258** apSecond)
{
    int result2 = 0;
    float f3 = reinterpret_cast<::TileListBoxCalls *>(((*apFirst)))->GetFloat(DAT_011da344);
    float f2 = reinterpret_cast<::TileListBoxCalls *>(((*apSecond)))->GetFloat(DAT_011da344);
    if (f3 == DAT_0102e430 && f2 == DAT_0101e568)
    {
        result2 = 1;
    }
    else if (f3 == DAT_0101e568 && f2 == DAT_0102e430)
    {
        result2 = -1;
    }
    else
    {
        float g1 = reinterpret_cast<::TileListBoxCalls *>(((*apFirst)))->GetFloat(0xfac);
        float g3 = reinterpret_cast<::TileListBoxCalls *>(((*apSecond)))->GetFloat(0xfac);
        if (g1 < g3)
        {
            result2 = -1;
        }
        else if (g1 > g3)
        {
            result2 = 1;
        }
    }
    return result2;
}

extern const double DAT_01075020;
extern const double DAT_01075018;

struct FUN_0079c450_shell : public MapMenu
{
    NiPoint3 FUN_0079c450(NiPoint3 position, TESWorldSpace* worldSpace);
};

// @fnv 0x0079c450
NiPoint3 FUN_0079c450_shell::FUN_0079c450(NiPoint3 position, TESWorldSpace* worldSpace)
{
    NiPoint3 pos = position;
    NiPoint3 result;

    if (*(int*)((char*)this + 0x80) == 0x21)
    {
        pos.x = (float)(pos.x * DAT_01075020 - DAT_01075018);
        pos.y = (float)(pos.y * DAT_01075020 - DAT_01075018);
    }

    result.x = (m_kMapMaximumPoint.x - m_kMapMinimumPoint.x) * pos.x + m_kMapMinimumPoint.x;
    result.y = (m_kMapMaximumPoint.y - m_kMapMinimumPoint.y) * pos.y + m_kMapMinimumPoint.y;
    result.z = 0.0f;

    if (worldSpace != 0 && *(int*)((char*)this + 0x80) == 0x21)
    {
        reinterpret_cast<::FUN_00588e40_shell *>((worldSpace))->TransformWorldPoint((::Pt3 *)&(result), true);
    }

    return result;
}

struct FUN_007a1ac0_Entry
{
    unsigned int unk00;
    unsigned int unk04;
};

struct FUN_007a1ac0_cls
{
    unsigned int unk00;
    FUN_007a1ac0_Entry* m_04;
    unsigned int FUN_007a1ac0(BSStringT<char>& s);
};

// Gets an index, marks the entry at m_04[idx] with flag 1, stores s into that entry, and returns the index.
// @fnv 0x007a1ac0
unsigned int FUN_007a1ac0_cls::FUN_007a1ac0(BSStringT<char>& aString)
{
    unsigned int uiIndex = reinterpret_cast<::S5460 *>(this)->FUN_00845460();
    reinterpret_cast<::FUN_007a6310_cls *>(this)->ConstructElements((int)(&m_04[uiIndex]), 1);
    reinterpret_cast<::FUN_00501c10_cls *>(&(m_04[uiIndex]))->CallAndReturnSelf((int)&(aString));
    return uiIndex;
}

struct SpawnedSub
{
    ~SpawnedSub();
};


struct FUN_007a1d60_cls
{
    virtual ~FUN_007a1d60_cls();
    SpawnedSub m_04;
};

// Runs Cleanup, then frees the object with SpawnedFree.
// @fnv 0x007a1d60
FUN_007a1d60_cls::~FUN_007a1d60_cls()
{
    reinterpret_cast<::fnv_007a2070::ClearList *>(this)->FUN_007a2070();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

struct LBValue
{
};

struct LBTile
{
};

struct LBMenu
{
};


struct LBItem
{
    Tile* tile;
    int object;
    char isFilteredOut;
    LBItem(Tile* t, int* o);
};

struct Tile;
struct LBList
{
    LBItem* item;
    LBList* next;
public:
    void *FindItemData(::Tile *);
};

struct LBox
{
    virtual void vfn_00();
    LBList list;
    LBTile* parentTile;
    Tile* selected;
    Tile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    Tile* AddItem(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate);
};


struct HighlightValue
{
};

struct HighlightTile : public Tile
{
};


struct FUN_007a6c80_shell
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0C;
    HighlightTile* unk10;
    void UpdateHighlightBox();
};

// Sets the highlight_y and selected_height values on unk0C and shows or hides the lb_highlight_box tile edges depending on unk10's speech challenge failure state.
// @fnv 0x007a6c80
void FUN_007a6c80_shell::UpdateHighlightBox()
{
    static int iHighlightY = FUN_00a00940("_highlight_y", -1);
    static int iSelectedHeight = FUN_00a00940("_selected_height", -1);

    if (unk0C)
    {
        if (unk10)
        {
            HighlightValue* pHighlightY = (HighlightValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((unk0C))->FUN_00a00f30(iHighlightY)));
            HighlightValue* pSelectedHeight = (HighlightValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((unk0C))->FUN_00a00f30(iSelectedHeight)));
            reinterpret_cast<::AGOwner *>((pHighlightY))->FUN_00a09130(2000, unk10, 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pHighlightY))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((pSelectedHeight))->FUN_00a09130(2000, unk10, 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pSelectedHeight))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((unk10))->GetSpeechChallengeFailure())
            {
                HighlightTile* pBox = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(unk0C), "lb_highlight_box")));
                if (pBox)
                {
                    HighlightTile* pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("top"))));
                    if (pSide)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                        pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                        pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                        pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pBox))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((pBox))->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* pBox = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(unk0C), "lb_highlight_box")));
                if (pBox)
                {
                    HighlightTile* pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("top"))));
                    if (pSide)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                        pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                        pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                        pSide = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pSide))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pBox))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((pBox))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            unk0C->Set(iHighlightY, -1);
            unk0C->Set(iSelectedHeight, 0);
        }
    }
}


struct ScrollListHost
{
    int unk00;
    int unk04;
    int unk08;
    Tile* pListTile;
    int unk10;
    Tile* pCountTile;
    int unk18;
    int unk1c;
    float fTotalHeight;
    void FUN_007a7080();
};

// Computes a scroll count from the list tile's float value and total height, sets _scroll_delta on the list tile and _number_of_items on the count tile.
// @fnv 0x007a7080
void ScrollListHost::FUN_007a7080()
{
    if (pListTile)
    {
        float m_fGlyphExtent = pListTile->GetFloat(0xfb0);
        int iCount = 1;
        if (fTotalHeight > 0.0 && m_fGlyphExtent > 0.0)
        {
            if (fTotalHeight > m_fGlyphExtent)
            {
                iCount =
                    FUN_00647b70((int)FUN_004e4430(reinterpret_cast<::fnv_007a6a50::FUN_007a6a50_shell *>(this)->GetUnfilteredCount() * (fTotalHeight - m_fGlyphExtent) / fTotalHeight) + 1, 2);
            }
            if (iCount > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((pListTile))->FUN_00a012d0(Tile::GetTraitID("_scroll_delta"), (fTotalHeight - m_fGlyphExtent) / (iCount - 1), true);
            }
        }
        if (pCountTile)
        {
            pCountTile->Set(Tile::GetTraitID("_number_of_items"), iCount);
        }
    }
}

struct EntryTarget
{
    void Notify(int id, unsigned int value);
};

struct EntryItem
{
    EntryTarget* target;
    unsigned int unk04;
    unsigned char flag;
};

struct EntryNode
{
    EntryItem* item;
    EntryNode* next;

};

struct FUN_007a78e0_cls
{
    int unk00;
    EntryNode m_kNode;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short m_1c;
    float m_20;

    void ProcessEntries();
};


struct ListScrollHost
{
    int unk00;
    int unk04;
    int unk08;
    Tile* scrollBar;
    int unk10;
    Tile* itemCountTile;
    int unk18;
    int unk1c;
    float visibleHeight;
    void FUN_007a8580();
};
// @fnv 0x007a5230
Tile* LBox::AddItem(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate)
{
    if (parentTile && (templateName || altTemplate))
    {
        Tile* newTile =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((LBMenu*)reinterpret_cast<::FUN_00a03c90_shell *>((parentTile))->FUN_00a03c90())))->FUN_00a1ddb0((::Tile *)(parentTile), (char *)(altTemplate ? altTemplate : templateName), (::Tile *)(0));
        if (!((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((newTile))->FUN_00a00f30(0xfaa))))
            newTile->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((newTile))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (sortFunc)
        {
            reinterpret_cast<::FUN_00470440 *>(&(list))->FUN_007a7eb0((::BGSPerkEntry *)(::LBItem *)(new LBItem(newTile, &item)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(sortFunc));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_007a80e0_cls *>(this)->InitSceneNodes();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(list))->FUN_00905820((void *)&(const ::LBItem *const &)(new LBItem(newTile, &item)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(newTile));
                reinterpret_cast<::ListScrollHost *>(this)->FUN_007a8580();
            }
            newTile->Set(0xfac, itemCount++);
        }
        if (::GetRaceCount((char *)this) == 1)
        {
            if (reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > ::_DAT_01012060)
            {
                LBValue* value = ((::LBValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((parentTile))->FindTraitValue(0xfb0)));
                reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
                reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, newTile, 0xfb0);
                reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
                reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
            }
        }
        return newTile;
    }
    else
    {
        return 0;
    }
}

// @fnv 0x007a8580
void ListScrollHost::FUN_007a8580()
{
    if (scrollBar)
    {
        float fValue = scrollBar->GetFloat(0xfb0);
        int iVisibleItemCount = 1;
        if (visibleHeight > _DAT_01012060 && fValue > _DAT_01012060)
        {
            if (visibleHeight > fValue)
            {
                iVisibleItemCount =
                    FUN_00647b70((int)FUN_004e4430(reinterpret_cast<::ItemCounter *>(this)->FUN_007a8030() * (visibleHeight - fValue) / visibleHeight) + 1, 2);
            }
            if (iVisibleItemCount > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((scrollBar))->FUN_00a012d0(Tile::GetTraitID("_scroll_delta"), (visibleHeight - fValue) / (iVisibleItemCount - 1),
                               true);
            }
        }
        if (itemCountTile)
        {
            itemCountTile->Set(Tile::GetTraitID("_number_of_items"), iVisibleItemCount);
        }
    }
}


template <> void ListBox<BGSQuestObjective*>::ClearSelection(bool);
template <> void ListBox<BGSNote*>::ClearSelection(bool);

// Loads map_menu.xml, stores the resulting MapMenu in DAT_011da368, initializes its marker lists and tiles, and returns the menu tile or 0 on failure.
// @fnv 0x00796b90
Tile* __cdecl FUN_00796b90()
{
    InterfaceManager* interfaceManager = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    Menu* oldMenu = ((::Menu *)(::FUN_00a09030(0x3ff)));
    if (oldMenu)
    {
        delete oldMenu;
    }
    Tile* menuTile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((interfaceManager->FUN_00586150()))->FUN_00a01b00((void *)("Data\\Menus\\Main\\map_menu.xml"));
    DAT_011da368 = (MapMenu*)reinterpret_cast<::FUN_00a03c90_shell *>((menuTile))->FUN_00a03c90();
    ::fnv_00a1ca20::RemoveMenuEntries("Data\\Menus\\Main\\map_menu.xml", DAT_011da368);
    if (DAT_011da368 && DAT_011da368->GetID() == 0x3ff)
    {
        ::FUN_00867a20((void *)(DAT_011da368));
        reinterpret_cast<::FUN_00a1dc70_shell *>((DAT_011da368))->FUN_00a1dc70((TileMenu*)menuTile, false);
        DAT_011da368 = DAT_011da368;
        if (!reinterpret_cast<::Unk00796f90 *>((DAT_011da368))->HasNoZeroEntries())
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (menuTile->GetFloat(0xfa7) == 6006.0 || menuTile->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((menuTile))->FUN_00a012d0(0xfad, Tile::GetInterfaceScale(), true);
        reinterpret_cast<::TutorialMessageGate718 *>(&(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->tutorials))->FUN_00718630(0x1a, FUN_00720df0(), 0x200);
        Interface::SetTileFormattedText(DAT_011da368->m_pTiles[17], 0x20, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d38ac))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d204c))))->GetMenuTitle())),
                                        ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d5020))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d28a4))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d4aec))))->GetMenuTitle())), 0);
        DAT_011da368->m_kQuestListBox.Initialize(DAT_011da368->m_pTiles[7], "MM_ListMarkerTemplate");
        DAT_011da368->m_kQuestListBox.ClearSelection(false);
        DAT_011da368->m_kObjectiveListBox.Initialize(DAT_011da368->m_pTiles[15], "MM_ListMarkerTemplate");
        DAT_011da368->m_kObjectiveListBox.ClearSelection(false);
        DAT_011da368->m_kNoteListBox.Initialize(DAT_011da368->m_pTiles[8], "MM_ListMarkerTemplate");
        DAT_011da368->m_kNoteListBox.ClearSelection(false);
        DAT_011da368->m_kChallengeListBox.Initialize(DAT_011da368->m_pTiles[19], "MM_ListMarkerTemplate");
        DAT_011da368->m_kMapMarkerListBox.Initialize(DAT_011da368->m_pTiles[10], "MM_ListMarkerTemplate");
        NiAVObject* object = ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[16]))->FUN_0056c7f0()))
                                 ? ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[16]))->FUN_0056c7f0()))))->FUN_0045bc00(0)))
                                 : 0;
        TileShaderProperty* property = object ? (TileShaderProperty*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(((unsigned int)(::FUN_00438220()))))) : 0;
        if (property)
            reinterpret_cast<::FUN_007700d0_cls *>((property))->set(true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[6]))->FUN_00a01350(FUN_00a00940("_Title", -1), (char *)(""), true);
        reinterpret_cast<::FUN_00796f40_shell *>((DAT_011da368->m_pTiles[5]))->SetFlag8000(true);
        reinterpret_cast<::FUN_00796f40_shell *>((DAT_011da368->m_pTiles[3]))->SetFlag8000(true);
        ::MapMenu::UpdateMapPosition();
        DAT_011da368->Menu::SetMenuVisibility(true);
        return menuTile;
    }
    else if (DAT_011da368 && ((::Tile *)(reinterpret_cast<::Callees *>((DAT_011da368))->FUN_00726070())))
    {
        delete DAT_011da368;
    }
    return 0;
}

struct MenuInterfaceCalls
{
};
struct MapTileCalls
{
};
// @fnv 0x00798710
void __cdecl FUN_00798710()
{
    if (!ConsumeByteAtE4())
    {
        reinterpret_cast<::FUN_0070f690_Class *>((((MenuInterfaceCalls*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->HandleCallbackOrStore(::fnv_00798a00::FUN_00798a00);
    }
    else
    {
        DAT_011da368->m_pSecondMapReference = 0;
    }
    if (!FUN_004b71d0())
    {
        reinterpret_cast<::FUN_00a012d0_t *>((((MapTileCalls*)DAT_011da368->m_pTiles[6])))->FUN_00a012d0(4001, reinterpret_cast<::MyHack *>((((MenuInterfaceCalls*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_007697f0() -
                                     reinterpret_cast<::FUN_00a013d0_shell *>((((A7d*)((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((DAT_011da368->m_pTiles[6]))->FUN_0045cd60())))))->GetTotalFloat() -
                                     reinterpret_cast<::TileListBoxCalls *>((((MapTileCalls*)DAT_011da368->m_pTiles[6])))->GetFloat(4017) / 2.0, {});
        reinterpret_cast<::FUN_00a012d0_t *>((((MapTileCalls*)DAT_011da368->m_pTiles[6])))->FUN_00a012d0(4002, reinterpret_cast<::S *>((((MenuInterfaceCalls*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->GetScaledValue() -
                                     reinterpret_cast<::FUN_00a01440_shell *>((((C7d*)((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((DAT_011da368->m_pTiles[6]))->FUN_0045cd60())))))->GetAccumulatedFloat() -
                                     reinterpret_cast<::TileListBoxCalls *>((((MapTileCalls*)DAT_011da368->m_pTiles[6])))->GetFloat(4016) / 2.0, {});
    }
    DAT_011da368->m_pTiles[6]->Set(4003, 1);
}


struct MapMenuMarkerCalls : public MapMenu
{
};

struct PlayerMarkerCalls : public PlayerCharacter
{
};

class TESDescription
{
  public:
    virtual ~TESDescription();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual const char* GetDescription(TESForm* apParent = 0, unsigned int auiChunkID = 0x43534544);
};

class TESFullName
{
  public:
    virtual ~TESFullName();
    virtual void vfn_04();
    virtual void vfn_08();
    int unk04;
    int unk08;
};

class TESChallengePrimary : public TESForm
{
  public:
    int unk10;
    int unk14;
};

class TESChallenge : public TESChallengePrimary, public TESFullName, public TESDescription
{
  public:
    int GetProgressValue();
public:
    int GetStartsLocked();
};

class FontManager
{
  public:
    static FontManager* Instance();
};

struct FUN_00a01290_shell
{
    void SetTraitAndReset(int, float);
};

int __cdecl FUN_00a01860(const char*);

struct MapMenu_Shell : public MapMenu
{
    void UpdateChallengeText(TESChallenge* apChallenge);
};

// Fills the MM_DataText tile with the challenge's name, progress/threshold and description, then sizes the MM_TextScrollbar from the text height.
// @fnv 0x007991b0
void MapMenu_Shell::UpdateChallengeText(TESChallenge* apChallenge)
{
    float height8;
    char buffer_[512];
    float kScrollDelta;
    Tile* scrollbarTile7;
    Tile* dataTextTile_2;
    float fUnk218;

    dataTextTile_2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((m_pTiles[13]))->FUN_00a03da0((char *)("MM_DataText"));
    scrollbarTile7 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((m_pTiles[13]))->FUN_00a03da0((char *)("MM_TextScrollbar"));
    kScrollDelta = scrollbarTile7->GetFloat(FUN_00a01860("_ScrollDelta"));
    fUnk218 = 0.0f;
    m_pTiles[13]->Set(FUN_00a01860("_ItemType"), 1);

    ::FUN_00406d00(buffer_, 0x200, "%s\n%d\\%d\n\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((apChallenge))->FUN_00408da0())),
              MinInt(apChallenge->GetProgressValue(), reinterpret_cast<::LowProcess *>((apChallenge))->GetPackageObjectType()), reinterpret_cast<::LowProcess *>((apChallenge))->GetPackageObjectType(),
              apChallenge->GetDescription(0, 0x43534544));

    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((dataTextTile_2))->FUN_00a01350(0xfc4, (char *)(buffer_), true);

    height8 = reinterpret_cast<::fnv_00a1b020::FUN_00a1b020_t *>((FontManager::Instance()))->FUN_00a1b020(buffer_, 1, 400.0f, 0).y;
    fUnk218 = height8 - ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((dataTextTile_2))->FUN_0045cd60()))->GetFloat(0xfb0);
    fUnk218 = FUN_00404010(0.0f, fUnk218);

    reinterpret_cast<::FUN_00a012d0_t *>((scrollbarTile7))->FUN_00a012d0(FUN_00a01860("_number_of_items"), FUN_004e4430(fUnk218 / kScrollDelta) + 1.0, true);
    reinterpret_cast<::FUN_00a012d0_t *>((scrollbarTile7))->FUN_00a012d0(FUN_00a01860("_current_value"), 0.0f, false);
    ((FUN_00a01290_shell*)scrollbarTile7)->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
}

struct WidgetTile
{
    void SetTraitAndReset(int before, float value);
    void SetTraitAndReset(int before);
};
struct WidgetSource
{
};
struct WorldInput
{
};
struct UIManager
{
};
struct Clock
{
};
struct Metrics
{
};
struct ElementList
{
};
struct CollectionHolder
{
    int unk0;
    ElementList list;
};
struct Controller
{
    virtual void FUN_V0();
    virtual void FUN_V4();
    virtual void FUN_V8();
    virtual void FUN_HandleState(int mode, int arg);
    int unknown_4;
    int unknown_8;
    int unknown_c;
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
    CollectionHolder* history;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    WidgetSource* source;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int mode;
    WidgetTile* current;
    int unknown_88;
    int unknown_8c;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
    int unknown_a0;
    int unknown_a4;
    int unknown_a8;
    int unknown_ac;
    int unknown_b0;
    int unknown_b4;
    int unknown_b8;
    int unknown_bc;
    int unknown_c0;
    int unknown_c4;
    int unknown_c8;
    int unknown_cc;
    int unknown_d0;
    int unknown_d4;
    int unknown_d8;
    int unknown_dc;
    int unknown_e0;
    int unknown_e4;
    int unknown_e8;
    int unknown_ec;
    int unknown_f0;
    int unknown_f4;
    int unknown_f8;
    int unknown_fc;
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
    Clock clock;
    bool HandleInputCommand(int command, int ignored);
};

bool __cdecl FUN_00702450(int code);
int __cdecl FUN_00a01860(const void* key);
int __cdecl FUN_00a01860(const void* key, float value);
int __cdecl FUN_00ec62c0();

extern const double DAT_010745f8;
extern const double DAT_01074f38;
extern const double DAT_01074f30;
extern const double DAT_0102fc70;
extern int DAT_011da404;
extern const char DAT_01074ec8[];

struct DateCalendar
{
    BSStringT<char> FormatDate();
};
struct RenderState
{
};
struct MenuRefresh : MapMenu
{
};
int TraitID(const char*);
// @fnv 0x0079aba0
void FUN_0079aba0()
{
    if (DAT_011da368 && reinterpret_cast<::FOPipboyManager *>((((::RenderState *)(::fnv_00705990::FUN_00705990()))))->IsUnk28Set())
    {
        BSStringT<char> text;
        float hour = reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::DateCalendar *>(&::g_011de7b8))))->GetGameTime();
        int minutes = (hour - (int)hour) * 60.0;
        ::FUN_00406f60((::FUN_00406f90_this *)&(text), "%s, %d:%02d", (const char*)(*reinterpret_cast<::DateCalendar *>(&::g_011de7b8)).FormatDate(), (int)hour, minutes);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[1]))->FUN_00a01350(0xfc4, (char *)((const char*)text), true);
        reinterpret_cast<::fnv_00578870::FUN_00578870_Class *>((::_g_thePlayer))->FUN_00578870((::fnv_00578870::BSStr &)(text));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[0]))->FUN_00a01350(0xfc4, (char *)((const char*)text), true);
        if (FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011c3cb4))))->GetMenuTitle())), "ENGLISH"))
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[11]))->FUN_00a01350(TraitID("_Title_1"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d1da8))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[11]))->FUN_00a01350(TraitID("_Title_2"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3f64))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[11]))->FUN_00a01350(TraitID("_Title_3"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d45f4))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[11]))->FUN_00a01350(TraitID("_Title_4"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3414))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[11]))->FUN_00a01350(TraitID("_Title_5"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d2f10))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((DAT_011da368->m_pTiles[11]))->FUN_00a00f30(DAT_011da354)))))->FUN_00a09410(true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[12]))->FUN_00a01350(TraitID("_Title_1"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3180))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[12]))->FUN_00a01350(TraitID("_Title_2"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d4cfc))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[12]))->FUN_00a01350(TraitID("_Title_3"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d27a8))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[12]))->FUN_00a01350(TraitID("_Title_4"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3798))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[12]))->FUN_00a01350(TraitID("_Title_5"), (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3210))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((DAT_011da368->m_pTiles[12]))->FUN_00a00f30(DAT_011da354)))))->FUN_00a09410(true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::TileFloatList *>((DAT_011da368->m_pTiles[17]))->FUN_00a03eb0(0x24)))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d4aec))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::Tile *)(reinterpret_cast<::Callees *>((DAT_011da368))->FUN_00726070()))))->FUN_00a03da0((char *)("MM_Headline_Title"))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d21e4))))->GetMenuTitle()))), true);
        }
        reinterpret_cast<::MapMenu *>((((MenuRefresh*)DAT_011da368)))->FUN_0079af30();
    }
}

class NoteName
{
  public:
      // TESFullName::GetFullName
};
class NoteData : public BGSNote
{
  public:
    int unk00[18];
    NoteName m_kName;  // +0x48
};
class NoteTile
{
  public:
};
class NotesListBox
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void FreeAllTiles();  // +0x1c
};
class NoteSource
{
  public:
};
int __cdecl FUN_00a01860(const char* pcTrait);

class NotesMapMenu
{
  public:
    int unk00[22];
    NoteTile* m_pkNotesTile;  // +0x58
    int unk5c[12];
    bool m_bShowingAllNotes;  // +0x8c
    char unk8d[0xd3];
    NotesListBox m_kNotesList;  // +0x160

    void RefreshNotesList();
};

class Quest79B;

class QuestNode79B
{
  public:
};

class Target79B
{
  public:
};

class Player79B
{
  public:
};


class Menu79B
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
    bool m_bHidden;
};


// Returns false if the menu is hidden or if the target's quest list contains the player's active quest; otherwise returns true.
// @fnv 0x0079b390
bool __cdecl FUN_0079b390(Target79B* pkTarget)
{
    bool bResult = true;
    if ((*reinterpret_cast<::Menu79B * *>(&::DAT_011da368)) && !(*reinterpret_cast<::Menu79B * *>(&::DAT_011da368))->m_bHidden)
    {
        for (QuestNode79B* pkNode = ((::QuestNode79B *)(reinterpret_cast<::BGSExplosion *>((pkTarget))->FUN_004fadc0())); pkNode && *((::Quest79B **)(new ((void *)(pkNode)) ::Vec3())); pkNode = ((::QuestNode79B *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())))
        {
            if (*((::Quest79B **)(new ((void *)(pkNode)) ::Vec3())) == ((::Quest79B *)(::FUN_005cbb50((char *)((*reinterpret_cast<::Player79B * *>(&::_g_thePlayer)))))))
                bResult = false;
        }
    }
    else if ((*reinterpret_cast<::Menu79B * *>(&::DAT_011da368)) && (*reinterpret_cast<::Menu79B * *>(&::DAT_011da368))->m_bHidden)
    {
        bResult = false;
    }
    return bResult;
}

struct FullName600
{
};
struct Challenge600
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FullName600 name;
};
struct Node600
{
};
struct Handler600
{
};
struct Tile600
{
};
struct List600
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void Clear();
    virtual void Sort(int(__cdecl*)(Challenge600*, Challenge600*));
};
struct Target600
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
    List600 list;
    void RefreshChallengeList();
};
// @fnv 0x0079b600
void Target600::RefreshChallengeList()
{
    list.Clear();
    Node600* node = ((::Node600 *)(reinterpret_cast<::FUN_00461150_shell *>(((*reinterpret_cast<::Handler600 * *>(&::g_dataHandler))))->FUN_00461150()));
    Challenge600* item = 0;
    while (node)
    {
        item = ((::Challenge600 *)(new ((void *)(node)) ::Vec3()));
        if (item && (!reinterpret_cast<::TESChallenge *>((item))->GetStartsLocked() || ((int)(::FUN_005a60d0((const char *)(item))))))
        {
            Tile600* tile = ((::Tile600 *)(reinterpret_cast<::LBox *>(&(list))->AddItem((int)(item), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(item->name))->FUN_00408da0())), (int (*)(LBItem *, LBItem *))(0), (const char *)(0))));
            reinterpret_cast<::Tile *>((tile))->Set(0xfaa, 0x18);
            reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(DAT_011da344, ((int)(::FUN_005a6150((const unsigned char *)(item)))) ? 128.0f : 255.0f, true);
        }
        node = ((::Node600 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_007a5730_shell *>(&(list))->FUN_007a5730(((bool (&)(TESChallenge *))::fnv_0079b720::FUN_0079b720));
    list.Sort(((int (&)(Challenge600 *, Challenge600 *))::CompareItems));
}

namespace fnv_0079bea0 {


struct RadioEntry
{
};
struct RadioTile : Tile
{
};
struct UIRecord : BSStringT<char>
{
};
struct RadioList
{
    void** vtable;
    void* FUN_007a3820(RadioEntry*, unsigned int, int, int);
    void FUN_007a3d20(bool (*)(RefH*));
};
typedef void(* RadioMethod)(RadioList*);
typedef void(* RadioCallback)(RadioList*, void*);
struct FUN_0079bea0_Shell : MapMenu
{
    void RefreshRadioList();
};
// @fnv 0x0079bea0
void FUN_0079bea0_Shell::RefreshRadioList()
{
    UIRecord record;
    ::BGSTalkingActivator::FindRadioStations((::TESObjectREFR *)((*reinterpret_cast<int *>(&::_g_thePlayer))), (::BSSimpleList< ::TESObjectREFR *> *)(void *)(&record), (::BSSimpleList<float> *)(0));
    ((RadioMethod)((RadioList*)&m_kMapMarkerListBox)->vtable[7])((RadioList*)&m_kMapMarkerListBox);
    for (BSSimpleList<unsigned int>* node = ::FUN_0079c080(); node && ((unsigned int)(new ((void *)(node)) ::Vec3())); node = ((::BSSimpleList<unsigned int> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        RadioTile* tile =
            (RadioTile*)((RadioList*)&m_kMapMarkerListBox)
                ->FUN_007a3820((RadioEntry*)((unsigned int)(new ((void *)(node)) ::Vec3())), ((unsigned int)(reinterpret_cast<::FUN_0055d520_shell *>((((RadioEntry*)((unsigned int)(new ((void *)(node)) ::Vec3())))))->FUN_0055d520())), 0, 0);
        tile->Set(0xfaa, 0x19);
        reinterpret_cast<::Tile *>((tile))->SetName((const char *)(((unsigned int)(reinterpret_cast<::FUN_0055d520_shell *>((((RadioEntry*)((unsigned int)(new ((void *)(node)) ::Vec3())))))->FUN_0055d520()))));
        tile->Set(::DAT_011da348, ::FUN_0079c070() && ((unsigned int)(new ((void *)(node)) ::Vec3())) == *(unsigned int*)::FUN_0079c070());
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(::DAT_011da344, reinterpret_cast<::RefList *>(&(record))->FUN_005f65d0((void **)(unsigned int *)(&((unsigned int)(new ((void *)(node)) ::Vec3())))) ? ::DAT_01023cd8 : ::DAT_0101e704, true);
    }
    ((RadioList*)&m_kMapMarkerListBox)->FUN_007a3d20(&::FUN_0079be30);
    ((RadioCallback)((RadioList*)&m_kMapMarkerListBox)->vtable[8])((RadioList*)&m_kMapMarkerListBox,
                                                                   (void*)&::CompareMobileObjects);
    reinterpret_cast<::FileMatchList *>(&(record))->RemoveAll();
}
}  // namespace fnv_0079bea0

struct AnimationRef
{
    void* ptr;
    AnimationRef(void*);
    ~AnimationRef();
};
struct WaveProperty
{
};
struct WaveMenu : MapMenu
{
    void UpdateWaveAnimation();
};
extern float DAT_011da414;
extern unsigned int DAT_011da418;
// Drives a wave property's animation over 750ms, stepping DAT_011da414 every 10ms and picking a random direction label when done.
// @fnv 0x0079c0c0
void WaveMenu::UpdateWaveAnimation()
{
    const int duration9 = 750;
    const int interval5 = 10;
    char buffer_[64];
    NiAVObject* object =
        ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[16]))->FUN_0056c7f0())) ? ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((DAT_011da368->m_pTiles[16]))->FUN_0056c7f0()))))->FUN_0045bc00(0))) : 0;
    WaveProperty* property = object ? (WaveProperty*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(((unsigned int)(::FUN_00438220()))))) : 0;
    if (!property)
        return;
    if (m_fMapRotation == 0.0)
    {
        AnimationRef reference2(0);
        ::FUN_00406d00(buffer_, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d505c))))->GetMenuTitle())), reinterpret_cast<::FUN_00a011f0_shell *>((m_pTiles[16]))->FUN_00a011f0(0xfd2));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((DAT_011da368->m_pTiles[16]))->FUN_00a01350(0xfcc, (char *)(buffer_), true);
        m_fMapRotation = (float)((unsigned int)(::FUN_00457fe0()));
        m_pTiles[16]->Set(0xfa3, 1);
    }
    if (((unsigned int)(::FUN_00457fe0())) - DAT_011da418 >= interval5)
    {
        reinterpret_cast<::FUN_0077a450_class *>((property))->SetFloats(DAT_011da414, 0.0f);
        DAT_011da414 = DAT_011da414 + 0.1f;
        if (DAT_011da414 > 1.0)
            DAT_011da414 = DAT_011da414 - 1.0;
        DAT_011da418 = ((unsigned int)(::FUN_00457fe0()));
    }
    if ((float)((unsigned int)(::FUN_00457fe0())) - m_fMapRotation >= duration9)
    {
        unsigned int directionTmp = DialogueRandom() % 3;
        if (directionTmp == 0)
            ::TaskQueueInterface::CopyStringToBuffer(buffer_, 64, "Forward");
        else if (directionTmp == 1)
            ::TaskQueueInterface::CopyStringToBuffer(buffer_, 64, "Backward");
        else
            ::TaskQueueInterface::CopyStringToBuffer(buffer_, 64, "Left");
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[16]))->FUN_00a01350(0xfd2, (char *)(buffer_), true);
        m_fMapRotation = 0.0f;
    }
}

struct ZoomPoint
{
    float x, y;
    ZoomPoint(float, float);
};
struct ZoomUpdate
{
    float time;
    bool a, b;
    int flags;
    ZoomUpdate(float, bool, bool);
};
struct ZoomData
{
    void Mark(int);
};
struct ZoomObject
{
    void Position(float, float, float);
};
struct ZoomNode
{
};

struct ZoomSetting
{
};
struct ZoomInt
{
};
struct ZoomTES
{
};
struct ZoomPip
{
    void Animate(int, float, float, bool);
};
struct ZoomInterface
{
};
extern int DAT_011da35c;
bool FUN_007a1750();
struct ZoomMenu
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
    int page;
    Tile* tile;
    void FUN_0079c5a0(bool, float);
};
struct PlayerMapView : PlayerCharacter
{
    TESWorldSpace* FUN_00575d70();
};
struct DoorBaseView
{
    int GetFormType();
};
struct DoorInfoView
{
};
struct MarkerRefView : TESObjectREFR
{
};
struct NiPoint2_helper
{
    float x, y;
    NiPoint2_helper(float, float);
};
struct MarkerChildren
{
};
struct MarkerTileView
{
    int unk00;
    MarkerChildren children;
};
struct MapView : MapMenu
{
    void UpdateLocalMap();
    void FUN_0079dbb0();
};
// Computes the local map's world bounds from the player position or parent cell, updates the map view, and places door markers on the map tile.
// @fnv 0x0079d410
void MapView::UpdateLocalMap()
{
    TESWorldSpace* b = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((PlayerMapView*)::_g_thePlayer)))->FUN_00575d70()));
    TESObjectCELL* a = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((::_g_thePlayer))->GetTarget()));
    NiPoint3 c = *::_g_thePlayer->GetPos();
    pAdjustNorthRotationCell = reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((PlayerMapView*)::_g_thePlayer)))->FUN_00575d10() ? a : 0;
    if (pAdjustNorthRotationCell)
    {
        NiPoint3 b = c;
        ((TESObjectCELL_Ext*)pAdjustNorthRotationCell)->FUN_00555b10(c, b, true);
        int e = ((::FUN_00406d90(b.x) - 2048) >> 12) - (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
        int d = ((::FUN_00406d90(b.y) - 2048) >> 12) - (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
        NiPoint3 a((float)((e << 12) + 2048), (float)(((d + *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) - 1) << 12) + 2048), 0.0f);
        NiPoint3 c((float)(((e + *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) - 1) << 12) + 2048), (float)((d << 12) + 2048), 0.0f);
        m_kMapMinimumPoint = (const NiPoint2&)NiPoint2_helper(a.x, a.y + 4096.0);
        m_kMapMaximumPoint = (const NiPoint2&)NiPoint2_helper(c.x + 4096.0, c.y);
    }
    else
    {
        int e = ((::FUN_00406d90(c.x)) >> 12) - (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
        int d = ((::FUN_00406d90(c.y)) >> 12) - (*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) >> 1);
        NiPoint3 a((float)(e << 12), (float)((d + *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) - 1) << 12), 0.0f);
        NiPoint3 b((float)((e + *((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))) - 1) << 12), (float)(d << 12), 0.0f);
        m_kMapMinimumPoint = (const NiPoint2&)NiPoint2_helper(a.x, a.y + 4096.0);
        m_kMapMaximumPoint = (const NiPoint2&)NiPoint2_helper(b.x + 4096.0, b.y);
    }
    reinterpret_cast<::ZoomMenu *>(this)->FUN_0079c5a0(true, 1.0f);
    if (b)
        m_pCurrentMapForm = b;
    else
        m_pCurrentMapForm = a;
    if (m_pCurrentMapForm)
    {
        if (reinterpret_cast<::FUN_0076b610_Class *>(&(((MarkerTileView*)m_pTiles[2])->children))->FUN_0076b610())
        {
            for (BSSimpleList<TESObjectREFR*>* node = &LocalMapMarkerList; node && ((::TESObjectREFR *)(new ((void *)(node)) ::Vec3()));
                 node = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                MarkerRefView* e = (MarkerRefView*)((::TESObjectREFR *)(new ((void *)(node)) ::Vec3()));
                DoorBaseView* a = ((::DoorBaseView *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((e))->FUN_007af430()))->GetFormType() == 28 ? ((::DoorBaseView *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((e))->FUN_007af430())) : 0;
                NiPoint3 d = *e->GetPos();
                if (reinterpret_cast<::FUN_00477ba0_shell *>((e))->FUN_00477ba0() || reinterpret_cast<::FUN_0057b4b0_shell *>((e))->FUN_0057b4b0() || (!a || reinterpret_cast<::FUN_00517fd0_shell *>((a))->IsFlag4Set()))
                    continue;
                if (pAdjustNorthRotationCell)
                    ((TESObjectCELL_Ext*)pAdjustNorthRotationCell)->FUN_00555b10(d, d, true);
                float c = 255.0f;
                NiPoint3 b = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(d)), (::NiPoint3)(0), {})));
                if (m_bNeedsMapUpdate)
                    c = (float)(::FUN_00556870((float *)&(d)) / 4.0 * c);
                if (c > 0.0 && b.x >= 0.0 && b.x <= 1.0 && b.y >= 0.0 && b.y <= 1.0)
                {
                    Tile* g = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MapView*)DAT_011da368)))->FUN_00a1ddb0(m_pTiles[2], (char *)("MapMarkerTemplate"), (::Tile *)(false));
                    DoorInfoView* f = ((::DoorInfoView *)(reinterpret_cast<::TESObjectREFR *>((e))->GetExtraRadioData()));
                    g->Set(4010, 26);
                    reinterpret_cast<::FUN_00a012d0_t *>((g))->FUN_00a012d0(DAT_011da350, b.x, true);
                    reinterpret_cast<::FUN_00a012d0_t *>((g))->FUN_00a012d0(DAT_011da34c, b.y, true);
                    reinterpret_cast<::FUN_00a012d0_t *>((g))->FUN_00a012d0(4009, c, true);
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((g))->FUN_00a01350(4044, (char *)("Interface\\Icons\\Local Map\\icon_local_door.dds"), true);
                    if (f)
                    {
                        BSStringT<char> locationName;
                        reinterpret_cast<::FUN_0043a2e0_host *>((f))->SetString((::BSStr *)&(locationName));
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((g))->FUN_00a01350(FUN_00a00940("_LocationName", -1), (char *)((const char*)locationName), true);
                    }
                }
            }
        }
        FUN_0079dbb0();
    }
    m_pTiles[2]->Set(4003, 1);
    m_pTiles[3]->Set(4003, 1);
}

namespace MapMarkerUpdate {
struct Point
{
    float x, y, z;
    Point()
    {}
    Point(float, float, float);
};
struct Reference;
struct TargetPtr
{
};
struct SearchHit
{
};
struct HitList
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
    SearchHit** FUN_006cedb0();
};
struct SearchResults
{
    int unk00, unk04, unk08, unk0c;
    HitList hits;
    SearchResults();
    ~SearchResults();
};
struct Origin
{
    float x, y, z;
    Origin(Reference*);
};
struct Query
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
    Query();
    Query(Reference*);
    ~Query();
};
struct World
{
};
struct Reference
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
    virtual const Point& Position();
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
    virtual float Heading(int);
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
    Reference* marker;
    void* FUN_00575d70();
};
struct Tile
{
};
struct Menu
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
    Tile* localMarker;
    int unk038;
    Tile* worldMarker;
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
    int mode;
    Tile* map;
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
    Reference* target;
    int unk118;
    World* world;
    void FUN_0079e0a0();
    void UpdateMapMarkers();
    void FUN_0079f6f0();
    void UpdateQuestMarker();
    void FUN_0079dbb0();
};
// @fnv 0x0079dbb0
void Menu::FUN_0079dbb0()
{
    Tile* tile = mode == 33 ? worldMarker : localMarker;
    {
        Point point(::fnv_00c88020::DAT_01016248, ::fnv_00c88020::DAT_01016248, 0.0f);
        if (mode == 33 && reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>(((*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer))))->FUN_00575d10())
        {
            target = (*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer))->marker;
            if (!target)
            {
                SearchResults results;
                Origin origin((*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer)));
                if (::FUN_006d4d20((::LocS *)&(const ::MapMarkerUpdate::Query &)(Query((*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer)))), (::LocS *)&(const ::MapMarkerUpdate::Query &)(Query()), &results, 3, 0.0f, (::PathingActorData *)(&origin), 2))
                {
                    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(results.hits))->GetName())) > 0)
                        target = ((::MapMarkerUpdate::Reference *)(::FUN_00559450((int *)(((::MapMarkerUpdate::TargetPtr *)(reinterpret_cast<::TESObjectREFR *>(((*results.hits.FUN_006cedb0())))->GetExtraRadioData()))))));
                    if (!target)
                        target = (*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer));
                }
            }
        }
        else
            target = (*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer));
        if (target)
        {
            Point position = target->Position();
            if (world)
                reinterpret_cast<::TESObjectCELL_Ext *>((world))->FUN_00555b10((const ::NiPoint3 &)(position), (::NiPoint3 &)(position), 1);
            point = (*(::MapMarkerUpdate::Point *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::MapMarkerUpdate::Point &)(position)), (::NiPoint3)(((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((target))->FUN_00575d70()))), {})));
            reinterpret_cast<::Tile *>((tile))->Set(4003, 1);
            reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(::DAT_011da350, point.x, 1);
            reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(::DAT_011da34c, point.y, 1);
            float angle = -(*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer))->Heading(0) - ::DAT_010290d0;
            angle -= reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>(((*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer))))->FUN_00575d10() ? reinterpret_cast<::TESObjectCELL_Ext *>((((::MapMarkerUpdate::World *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_00555ad0() : 0.0f;
            reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4090, angle, 1);
        }
        else
            reinterpret_cast<::Tile *>((tile))->Set(4003, 0);
        if (!reinterpret_cast<::FUN_00a07ed0_shell *>((tile))->FUN_00a07ed0(4085))
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((tile))->StartFade(4085, ::DAT_0101e704, ::DAT_01023cd8, 1.0f, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((map))->FUN_00a012d0(
            4001, ((double)(reinterpret_cast<::TileListBoxCalls *>((((::MapMarkerUpdate::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((map))->FUN_0045cd60()))))->GetFloat(4017))) / ::DAT_01011590 - ((double)(reinterpret_cast<::TileListBoxCalls *>((map))->GetFloat(4017))) * point.x, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((map))->FUN_00a012d0(
            4002, ((double)(reinterpret_cast<::TileListBoxCalls *>((((::MapMarkerUpdate::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((map))->FUN_0045cd60()))))->GetFloat(4016))) / ::DAT_01011590 - ((double)(reinterpret_cast<::TileListBoxCalls *>((map))->GetFloat(4016))) * point.y, 0);
        FUN_0079e0a0();
        UpdateMapMarkers();
        if (((::MapMarkerUpdate::Reference *)(reinterpret_cast<::FUN_00798400_shell *>(((*reinterpret_cast<::MapMarkerUpdate::Reference * *>(&::_g_thePlayer))))->FUN_00798400())))
        {
            FUN_0079f6f0();
            UpdateQuestMarker();
        }
    }
}
}

namespace fnv_0079e0a0 {
struct MarkerTile;
struct MarkerChildren
{
    MarkerTile* FUN_0057c730(MarkerTile*&);
};
struct MarkerTile
{
    virtual ~MarkerTile();
    MarkerChildren children;
};
struct QuestTargetOps
{
};
struct QuestNode
{
};
struct PlayerQuestOps
{
};
struct RefMapOps
{
    TESWorldSpace* FUN_00575d70();
};
struct SettingQuestOps
{
    SETTING_VALUE* FUN_00408d60();
};
extern const char markerWorld[], markerLocal[], markerTexture[];
struct MarkerValue
{
};
struct MarkerTileOps
{
};
struct MarkerMap : MapMenu
{
    TESObjectREFR* SelectTarget(TESObjectREFR*, PathingPath*);
    void FUN_0079f8d0(TESObjectREFR*, TESObjectREFR*, PathingPath*, int);
    void FUN_0079e0a0();
};
// @fnv 0x0079e0a0
void MarkerMap::FUN_0079e0a0()
{
    MarkerTile* tile = ((::fnv_0079e0a0::MarkerTile *)(reinterpret_cast<::TileFloatList *>((((MarkerTile*)m_pMapTile)))->FUN_00a03eb0(27)));
    while (tile)
    {
        ((MarkerTile*)m_pMapTile)->children.FUN_0057c730(tile);
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>((tile))->FUN_009ff690();
        delete tile;
        tile = ((::fnv_0079e0a0::MarkerTile *)(reinterpret_cast<::TileFloatList *>((((MarkerTile*)m_pMapTile)))->FUN_00a03eb0(27)));
    }
    tile = ((::fnv_0079e0a0::MarkerTile *)(reinterpret_cast<::TileFloatList *>((((MarkerTile*)m_pMapTile)))->FUN_00a03eb0(29)));
    while (tile)
    {
        ((MarkerTile*)m_pMapTile)->children.FUN_0057c730(tile);
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>((tile))->FUN_009ff690();
        delete tile;
        tile = ((::fnv_0079e0a0::MarkerTile *)(reinterpret_cast<::TileFloatList *>((((MarkerTile*)m_pMapTile)))->FUN_00a03eb0(29)));
    }
    for (QuestNode* node = ((::fnv_0079e0a0::QuestNode *)(reinterpret_cast<::fnv_00952ba0::PlayerCharacterStandIn *>((((PlayerQuestOps*)::_g_thePlayer)))->FUN_00952ba0()));
         (*reinterpret_cast<::fnv_0079e0a0::SettingQuestOps *>(&::g_011e07f0)).FUN_00408d60()->b && node && *((::fnv_0079e0a0::QuestTargetOps **)(new ((void *)(node)) ::Vec3())); node = ((::fnv_0079e0a0::QuestNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        TESObjectREFR* reference = reinterpret_cast<::RegionObjectEntry *>(((*((::fnv_0079e0a0::QuestTargetOps **)(new ((void *)(node)) ::Vec3())))))->GetReference(true);
        TESObjectREFR* target = m_iMapDisplayMode == 33
                                    ? SelectTarget(reference, ((::PathingPath *)(::FUN_00460140((int)((*((::fnv_0079e0a0::QuestTargetOps **)(new ((void *)(node)) ::Vec3()))))))))
                                    : reinterpret_cast<::FUN_005cbb70_shell *>(((*((::fnv_0079e0a0::QuestTargetOps **)(new ((void *)(node)) ::Vec3())))))->FUN_005cbb70();
        if (target)
        {
            if (m_iMapDisplayMode == 33)
                FUN_0079f8d0(m_pFirstMapReference, target, ((::PathingPath *)(::FUN_00460140((int)((*((::fnv_0079e0a0::QuestTargetOps **)(new ((void *)(node)) ::Vec3()))))))), 29);
        }
        else if (reference && ((m_iMapDisplayMode == 33 && !reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((RefMapOps*)reference)))->FUN_00575d10()) ||
                               (m_iMapDisplayMode == 32 && ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())) == ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((::_g_thePlayer))->GetTarget())))))
        {
            target = reinterpret_cast<::RegionObjectEntry *>(((*((::fnv_0079e0a0::QuestTargetOps **)(new ((void *)(node)) ::Vec3())))))->GetReference(true);
        }
        if (target)
        {
            NiPoint3 position = *target->GetPos();
            NiPoint3 mapPosition;
            if (pAdjustNorthRotationCell)
                reinterpret_cast<::TESObjectCELL_Ext *>((pAdjustNorthRotationCell))->FUN_00555b10(position, position, true);
            mapPosition = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(position)), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((RefMapOps*)target)))->FUN_00575d70()))), {})));
            {
                Tile* value = 0;
                if (m_iMapDisplayMode == 33)
                    value = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MarkerMap*)DAT_011da368)))->FUN_00a1ddb0(m_pMapTile, (char *)(markerWorld), (::Tile *)(0));
                else
                    value = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MarkerMap*)DAT_011da368)))->FUN_00a1ddb0(m_pMapTile, (char *)(markerLocal), (::Tile *)(0));
                reinterpret_cast<::FUN_00a012d0_t *>((value))->FUN_00a012d0(DAT_011da350, mapPosition.x, true);
                reinterpret_cast<::FUN_00a012d0_t *>((value))->FUN_00a012d0(DAT_011da34c, mapPosition.y, true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((value))->FUN_00a01350(0xfcc, (char *)(markerTexture), true);
                reinterpret_cast<::Tile *>((((MarkerTileOps*)value)))->Set(0xfaa, 27);
                MarkerValue* marker = ((::fnv_0079e0a0::MarkerValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((MarkerTileOps*)value)))->FUN_00a00f30(0xff5)));
                reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((marker))->RemoveFromReactions();
                reinterpret_cast<::AGOwner *>((marker))->FUN_00a09130(2000, m_iMapDisplayMode == 33 ? m_pTiles[5] : m_pTiles[3], 0xff5);
                reinterpret_cast<::fnv_00a09410::EvalValue *>((marker))->FUN_00a09410(0);
            }
        }
    }
}
}  // namespace fnv_0079e0a0

#include <stdio.h>

struct TeleportPathHelper
{
    BSSimpleArray<TESObjectREFR*> references;
    BSSimpleArray<TESObjectCELL*> cells;
    NiPoint3 start, end;
    TeleportPathHelper();
    ~TeleportPathHelper();
};
struct QuestMarkerNode
{
};
struct MarkerPlayer
{
};
struct MarkerReference : TESObjectREFR
{
    TESWorldSpace* FUN_00575d70();
};
struct MarkerTile : Tile
{
};
struct MarkerMenu : MapMenu
{
    void UpdateQuestMarkers();
};
// Handles a UI input command: updates property widgets from world input, adjusts the current tile, and dispatches mode changes and history actions.
// @fnv 0x00799790
bool Controller::HandleInputCommand(int command, int ignored)
{
    if (!FUN_00702450(0x3ff) || !reinterpret_cast<::FOPipboyManager *>((((::UIManager *)(::fnv_00705990::FUN_00705990()))))->IsUnk28Set())
        return false;
    bool changed = false;
    if (FUN_00702450(0x3ff))
    {

        if (FUN_00709d40())
        {
            WidgetTile* selectedProperty = ((::WidgetTile *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::WorldInput * *>(&::g_osGlobals))))->FUN_00877720()));
            int valueY = 0x7fff;
            int valueX = 0;
            int selected = 0;
            if (mode == 0x20 || mode == 0x21)
            {
                float value = 0.0f;
                selected = reinterpret_cast<::FUN_00a23390_t *>((((::WidgetTile *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::WorldInput * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState({}, {});
                if (FUN_00408820((float)selected) <= DAT_010718f0)
                    selected = 0;
                if (selected != 0)
                {
                    value = (float)FUN_00408820((float)((double)selected / ::DAT_01029790));
                    reinterpret_cast<::ZoomMenu *>(this)->FUN_0079c5a0(selected > 0, (float)(1.0 + (double)value * DAT_01074f38));
                    changed = true;
                }
            }
            valueX = reinterpret_cast<::FUN_00a23390_t *>((((::WidgetTile *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::WorldInput * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState({}, {});
            selected = reinterpret_cast<::FUN_00a23390_t *>((((::WidgetTile *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::WorldInput * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState({}, {});
            if (FUN_00408820((float)valueX) <= DAT_010745f8)
                valueX = 0;
            if (FUN_00408820((float)selected) <= DAT_010745f8)
                selected = 0;
            switch (mode)
            {
            case 0x20:
            case 0x21:
                if (current)
                {
                    if (valueX || selected)
                    {
                        reinterpret_cast<::FUN_00a012d0_t *>((current))->FUN_00a012d0(0xfea, 1.0f, 1);
                        reinterpret_cast<::FUN_00a012d0_t *>((current))->FUN_00a012d0(0xfeb, 1.0f, 1);
                        reinterpret_cast<::FUN_00a01290_shell *>((current))->SetTraitAndReset(0xfee, (float)((double)valueX * DAT_01074f30 / ::DAT_01029790));
                        reinterpret_cast<::FUN_00a01290_shell *>((current))->SetTraitAndReset(0xfef, (float)((double)selected * DAT_0102fc70 / ::DAT_01029790));
                        changed = true;
                    }
                    else
                    {
                        reinterpret_cast<::FUN_00a012d0_t *>((current))->FUN_00a012d0(0xfea, DAT_01012054, 1);
                        reinterpret_cast<::FUN_00a012d0_t *>((current))->FUN_00a012d0(0xfeb, DAT_01012054, 1);
                    }
                    reinterpret_cast<::FUN_00799dc0_class *>(this)->UpdateMapHighlight();
                }
                break;
            case 0x22:
            case 0x23: {
                WidgetTile* item =
                    mode == 0x22 ? (WidgetTile*)((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(clock))->FUN_00825c00())) : ((::WidgetTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((source))->FUN_00a03da0((char *)(DAT_01074ec8))));
                if (item && ((double)(reinterpret_cast<::TileListBoxCalls *>((item))->GetFloat(0xfa3))) != ::_DAT_01012060)
                {
                    int direction = 0;
                    if (selected)
                        direction = (selected < 0) ? 1 : -1;
                    if (direction)
                    {
                        if (!DAT_011da404 || (double)(unsigned)(((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::Clock *>(&::g_timeGlobal))))->FUN_00825c00())) - DAT_011da404) >
                                                 (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Metrics *>(&::g_011d8b88)))))))
                        {
                            int before = FUN_00a01860(::str_010702d8);
                            int property = (int)((double)(reinterpret_cast<::TileListBoxCalls *>((item))->GetFloat(before)));
                            reinterpret_cast<::FUN_00a012d0_t *>((item))->FUN_00a012d0(before, (float)(property + direction), 0);
                            if ((double)property != ((double)(reinterpret_cast<::TileListBoxCalls *>((item))->GetFloat(before))))
                            {
                                reinterpret_cast<::FUN_00a01290_shell *>((item))->SetTraitAndReset(FUN_00a01860(::DAT_01070250), 1.0f);
                            }
                            DAT_011da404 = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::Clock *>(&::g_timeGlobal))))->FUN_00825c00()));
                            changed = true;
                        }
                    }
                }
                break;
            }
            }
        }
        switch (command)
        {
        case 0xd:
            ::s717280::FUN_00717280(0x24);
            ::sleep704::FUN_007048f0(1, 0, 1);
            changed = true;
            break;
        case 0xe:
            ::s717280::FUN_00717280(0x24);
            ::ShowStatsMenu(1, 0);
            changed = true;
            break;
        case 9:
            if (mode == 0x21)
            {
                int cursor = ::FUN_00559450((int *)&(history->list));
                while (cursor != 0)
                {
                    int value = *reinterpret_cast<::ListStandIn *>(&(history->list))->FUN_0057cbe0((int **)(int *)(&cursor));
                    if (reinterpret_cast<::FUN_00a01230_shell *>((((WidgetTile*)value)))->IsTraitNonZero(DAT_011da348))
                    {
                        FUN_HandleState(0x1a, value);
                        changed = true;
                        cursor = 0;
                    }
                }
            }
            break;
        case 0xf:
        case 0x10:
            if (mode == 0x20 || mode == 0x21)
            {
                reinterpret_cast<::ZoomMenu *>(this)->FUN_0079c5a0(command == 0x10, DAT_01018204);
                changed = true;
            }
            break;
        case 3:
        case 4: {
            mode += (command == 4) ? -1 : 1;
            mode = mode > 0x24 ? 0x20 : mode;
            mode = mode < 0x20 ? 0x24 : mode;
            FUN_HandleState(mode, 0);
            changed = true;
            break;
        }
        }
    }
    return changed;
}
// Zooms the map tile by a factor, updates its scale and position, rescales grid children on page 32, plays the zoom sound and finishes the menu.
// @fnv 0x0079c5a0
void ZoomMenu::FUN_0079c5a0(bool inward, float factor)
{
    if (!tile || (page == 32 && FUN_007a1750()))
        return;
    bool _changed = true;
    float scale2 = (inward ? factor : 1.0 / factor) * tile->GetFloat(DAT_011da35c);
    ZoomPoint centerVal(((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile))->FUN_0045cd60()))->GetFloat(0xfb1) / 2.0 - tile->GetFloat(0xfa1),
                        ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile))->FUN_0045cd60()))->GetFloat(0xfb0) / 2.0 - tile->GetFloat(0xfa2));
    if (page == 32)
    {
        float fraction7 = 0.0f;
        scale2 = FUN_00404010(FUN_0040ebd0(scale2, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1251))))))),
                              *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1250)))))));
        fraction7 = (scale2 - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1250))))))) /
                    (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1251)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1250)))))));
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4100,
                  (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1252)))))) +
                      ((double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1253)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1252))))))) *
                          fraction7,
                  true);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4101,
                  (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1254)))))) +
                      ((double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1255)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1254))))))) *
                          fraction7,
                  true);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4102,
                  (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1256)))))) +
                      ((double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1257)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1256))))))) *
                          fraction7,
                  true);
    }
    else
    {
        float unusedDimension = 0.0f;
        scale2 = FUN_00404010(FUN_0040ebd0(scale2, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1243))))))),
                              *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1242)))))));
        unusedDimension = (scale2 - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1242))))))) /
                          (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1243)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1242)))))));
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4100,
                  (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1244)))))) +
                      ((double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1245)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1244))))))) *
                          unusedDimension,
                  true);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4101,
                  (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1246)))))) +
                      ((double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1247)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1246))))))) *
                          unusedDimension,
                  true);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(4102,
                  (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1248)))))) +
                      ((double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1249)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::originalRuntimeFloatSetting1248))))))) *
                          unusedDimension,
                  true);
    }
    _changed = scale2 != tile->GetFloat(DAT_011da35c);
    reinterpret_cast<::FUN_006ad180_Cls *>(&(centerVal))->Scale(tile->GetFloat(0xfcd) * scale2 / tile->GetFloat(0xfb1));
    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(DAT_011da35c, scale2, true);
    if (page == 32)
    {
        ZoomNode* nodeB = reinterpret_cast<ZoomNode*>(((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((tile))->FUN_0056c7f0())));
        unsigned int gridA = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ZoomInt *>(&::g_011c63cc))))));
        for (unsigned int index_ = 0; nodeB && index_ < gridA * gridA; index_++)
        {
            ZoomObject* child4 = ((::ZoomObject *)(reinterpret_cast<::NiNode *>((nodeB))->GetAt(index_)));
            if (child4)
            {
                float dimensionB = (((void *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::ZoomTES * *>(&::g_TES))))->GetPrevPath())) ? 2048 : 1024) * scale2;
                float otherFraction6 = dimensionB / 16.0;
                reinterpret_cast<::FUN_00440490_shell *>((child4))->FUN_00440490(scale2);
                reinterpret_cast<::FUN_004bc1f0_S *>((child4))->FUN_004bc1f0((index_ % gridA) * dimensionB + dimensionB / 2.0, 0.0f,
                                 (index_ / gridA) * dimensionB + dimensionB / 2.0 - gridA * dimensionB);
                ZoomUpdate updateB(0.0f, false, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((child4))->FUN_00a59c60((int)&(updateB));
                ((::ZoomData *)(::fnv_005495f0::FUN_005495f0((const char *)(child4))))->Mark(0x4000);
            }
        }
    }
    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfa1, ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile))->FUN_0045cd60()))->GetFloat(0xfb1) / 2.0 - centerVal.x - tile->GetFloat(0xfee), false);
    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfa2, ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile))->FUN_0045cd60()))->GetFloat(0xfb0) / 2.0 - centerVal.y - tile->GetFloat(0xfef), false);
    if (_changed)
    {
        float amount5 = (factor - 1.0) / 0.14300000667572021;
        ((::ZoomPip *)(reinterpret_cast<::Interface *>((((::ZoomInterface *)(::fnv_004b7210::FUN_004b7210()))))->GetPipboyManager()))->Animate(0, inward ? -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::g_011db2f0)))))) * amount5 : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::g_011db2f0)))))) * amount5,
                                       *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZoomSetting *>(&::g_011db358)))))) * 2, true);
    }
    reinterpret_cast<::MarkerMenu *>(this)->UpdateQuestMarkers();
}
namespace fnv_0079ea30 {
extern "C" int sprintf(char*, const char*, ...);
TESWorldSpace* FUN_00575d70(TESObjectREFR*);

class TeleportPathHelper
{
  public:
    TeleportPathHelper();
    ~TeleportPathHelper();
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28;
    int unk2c, unk30, unk34;
};

class TESObjectREFRExt : public TESObjectREFR
{
  public:
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool ShouldHide(int reason);
};

struct PlayerCharacterExt : public PlayerCharacter
{
};

struct TileEx;
struct TileChildrenList
{
    void FUN_0057c730(TileEx**);
};

struct TileEx
{
    virtual ~TileEx();
    TileChildrenList children;
};

struct MapMenuExt : public MapMenu
{
    void UpdateMapMarkers();
};

// Clears the map marker tiles, then iterates the player's map markers and creates quest marker tiles for each visible destination.
// @fnv 0x0079ea30
void MapMenuExt::UpdateMapMarkers()
{
    BSSimpleList<TESObjectREFR*>* headX;
    TileEx* element = ((::fnv_0079ea30::TileEx *)(reinterpret_cast<::TileFloatList *>((((TileEx*)m_pMapTile)))->FUN_00a03eb0(0x25)));
    while (element)
    {
        ((TileEx*)m_pMapTile)->children.FUN_0057c730(&element);
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>((element))->FUN_009ff690();
        delete element;
        element = ((::fnv_0079ea30::TileEx *)(reinterpret_cast<::TileFloatList *>((((TileEx*)m_pMapTile)))->FUN_00a03eb0(0x25)));
    }

    element = ((::fnv_0079ea30::TileEx *)(reinterpret_cast<::TileFloatList *>((((TileEx*)m_pMapTile)))->FUN_00a03eb0(0x26)));
    while (element)
    {
        ((TileEx*)m_pMapTile)->children.FUN_0057c730(&element);
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>((element))->FUN_009ff690();
        delete element;
        element = ((::fnv_0079ea30::TileEx *)(reinterpret_cast<::TileFloatList *>((((TileEx*)m_pMapTile)))->FUN_00a03eb0(0x26)));
    }

    headX = ((::BSSimpleList< ::TESObjectREFR *> *)(::FUN_005eb7e0((void *)(((PlayerCharacterExt*)::_g_thePlayer)))));
    while (headX)
    {
        TESObjectREFR* kPRef = ((::TESObjectREFR *)(new ((void *)(headX)) ::Vec3()));
        TeleportPathHelper pathX;

        if (m_iMapDisplayMode == 0x21)
        {
            reinterpret_cast<::FUN_00952d60_stand *>((((PlayerCharacterExt*)::_g_thePlayer)))->FUN_00952d60(kPRef, (::PathingPath *)(::fnv_0079ea30::TeleportPathHelper *)(&pathX), 1);
        }

        TESObjectREFR* dest = (m_iMapDisplayMode == 0x21) ? GetTeleportDestination(kPRef, (PathingPath*)&pathX) : kPRef;

        if ((dest == 0 || ((TESObjectREFRExt*)dest)->ShouldHide(0)) ||
            (m_iMapDisplayMode == 0x20 && ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((kPRef))->GetTarget())) != ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((::_g_thePlayer))->GetTarget())) &&
             ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((kPRef))->FUN_00575d70())) != ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((::_g_thePlayer))->FUN_00575d70()))))
        {
            headX = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((headX))->FUN_00726070()));
            continue;
        }

        float deltaA = reinterpret_cast<::RefS *>((((TESObjectREFRExt*)kPRef)))->FUN_005723b0((::RefS *)(::_g_thePlayer), 0, 0);
        if (deltaA < ::DAT_01016968 && m_iMapDisplayMode == 0x21)
        {
            headX = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((headX))->FUN_00726070()));
            continue;
        }

        if (kPRef != 0)
        {
            if ((m_iMapDisplayMode == 0x21 && !reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((TESObjectREFRExt*)kPRef)))->FUN_00575d10()) ||
                (m_iMapDisplayMode == 0x20 && ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((kPRef))->GetTarget())) == ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((::_g_thePlayer))->GetTarget()))))
            {
                dest = kPRef;
            }
        }

        if (dest != 0)
        {
            NiPoint3 kPos12 = *dest->GetPos();
            NiPoint3 pos2B = kPos12;
            if (m_iMapDisplayMode == 0x21)
            {
                pos2B.y -= 1024.0;
            }
            else
            {
                pos2B.y -= 128.0;
            }

            NiPoint3 pt1A;
            NiPoint3 kPt22;

            if (pAdjustNorthRotationCell)
            {
                reinterpret_cast<::TESObjectCELL_Ext *>((pAdjustNorthRotationCell))->FUN_00555b10(kPos12, kPos12, true);
            }

            pt1A = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(kPos12)), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((dest))->FUN_00575d70()))), {})));
            kPt22 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(pos2B)), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((dest))->FUN_00575d70()))), {})));

            Tile* pStyleVal = (m_iMapDisplayMode == 0x21) ? m_pTiles[5] : m_pTiles[3];
            Tile* ui_ = 0;
            Tile* newTile = 0;

            if (m_iMapDisplayMode == 0x21)
            {
                ui_ = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MapMenuExt*)DAT_011da368)))->FUN_00a1ddb0(m_pMapTile, (char *)("WorldMapQuestMarkerTemplate"), (::Tile *)(0));
            }
            else
            {
                ui_ = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MapMenuExt*)DAT_011da368)))->FUN_00a1ddb0(m_pMapTile, (char *)("LocalMapQuestMarkerTemplate"), (::Tile *)(0));
            }

            reinterpret_cast<::FUN_00a012d0_t *>((ui_))->FUN_00a012d0(DAT_011da350, pt1A.x, true);
            reinterpret_cast<::FUN_00a012d0_t *>((ui_))->FUN_00a012d0(DAT_011da34c, pt1A.y, true);

            char buf[64];
            sprintf(buf, "%s Marker", reinterpret_cast<::FUN_0055d520_shell *>((((TESObjectREFRExt*)dest)))->FUN_0055d520());
            reinterpret_cast<::Tile *>((((TileEx*)ui_)))->SetName(buf);

            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ui_))->FUN_00a01350(0xfcc, (char *)("glow_hud_compass_landmark.dds"), true);
            ui_->Set(0xfaa, 0x1a);
            reinterpret_cast<::FUN_00a012d0_t *>((ui_))->FUN_00a012d0(0xfad, 5.0f, true);

            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ui_))->FUN_00a01350(FUN_00a00940("_LocationName", -1), (char *)("Companion"), true);

            LBValue* val_ec = (LBValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((ui_))->FUN_00a00f30(0xff5)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((val_ec))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((val_ec))->FUN_00a09130(0x7d0, pStyleVal, 0xff5);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((val_ec))->FUN_00a09410(0);

            float fadeXX = m_pMapTile->GetFloat(0xfb1);
            float kScaleY = m_pMapTile->GetFloat(0xfb0);
            fadeXX *= kPt22.x;
            kScaleY *= kPt22.y;

            newTile = ::fnv_00a00c20::FUN_00a00c20(0x387);
            newTile->Init(m_pMapTile, reinterpret_cast<::FUN_0055d520_shell *>((((TESObjectREFRExt*)kPRef)))->FUN_0055d520(), 0);
            reinterpret_cast<::FUN_00a012d0_t *>((newTile))->FUN_00a012d0(DAT_011da350, kPt22.x, true);
            reinterpret_cast<::FUN_00a012d0_t *>((newTile))->FUN_00a012d0(DAT_011da34c, kPt22.y, true);
            reinterpret_cast<::Tile *>((((TileEx*)newTile)))->SetName(reinterpret_cast<::FUN_0055d520_shell *>((((TESObjectREFRExt*)dest)))->FUN_0055d520());

            reinterpret_cast<::FUN_00a012d0_t *>((newTile))->FUN_00a012d0(0xfa1, fadeXX, true);
            reinterpret_cast<::FUN_00a012d0_t *>((newTile))->FUN_00a012d0(0xfa2, kScaleY, true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((newTile))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::FUN_0055d520_shell *>((((TESObjectREFRExt*)kPRef)))->FUN_0055d520()), true);
            reinterpret_cast<::FUN_00a012d0_t *>((newTile))->FUN_00a012d0(0xfba, 200.0f, true);
            newTile->Set(0xfaa, 0x26);
            reinterpret_cast<::FUN_00a012d0_t *>((newTile))->FUN_00a012d0(0xfad, 2.0f, true);
            newTile->Set(0xfa3, 1);
            newTile->Set(0xfb7, 2);
            newTile->Set(0xfb9, 2);
            reinterpret_cast<::FUN_00a012d0_t *>((newTile))->FUN_00a012d0(0xfb0, 60.0f, true);
            reinterpret_cast<::FUN_00a07530_shell *>((((TileEx*)newTile)))->FUN_00a07530(2);

            LBValue* xVal = (LBValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((newTile))->FUN_00a00f30(0xfa1)));
            LBValue* valY = (LBValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((newTile))->FUN_00a00f30(0xfa2)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((xVal))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((xVal))->FUN_00a09130(0x7d0, ui_, 0xfa1);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((xVal))->FUN_00a09410(0);

            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((valY))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((valY))->FUN_00a09130(0x7d0, ui_, 0xfa2);
            reinterpret_cast<::P03Value *>((valY))->AppendFloatAction(0x7d1, 60.0f);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((valY))->FUN_00a09410(0);

            val_ec = (LBValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((newTile))->FUN_00a00f30(0xff5)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((val_ec))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((val_ec))->FUN_00a09130(0x7d0, pStyleVal, 0xff5);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((val_ec))->FUN_00a09410(0);
        }

        headX = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((headX))->FUN_00726070()));
    }
}
}  // namespace fnv_0079ea30

struct QuestMapPlayer : PlayerCharacter
{
    TESWorldSpace* FUN_00575d70();
};
struct QuestMapReference : TESObjectREFR
{
    TESWorldSpace* FUN_00575d70();
};
struct QuestMapMenu : MapMenu
{
    void FUN_0079f8d0(TESObjectREFR*, TESObjectREFR*, void*, int);
    void UpdateQuestMarker();
};
// Pick the target for a reference: the last enabled entry's target, the default target, or the reference itself.

class F7E0Ref
{
  public:
};

struct F7E0Flag
{
    bool m_bEnableState;
};

class F7E0FlagList
{
  public:
    F7E0Flag* GetAt(int iIndex);
};

class F7E0TargetList
{
  public:
};

class F7E0Data : public F7E0FlagList
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    F7E0TargetList m_kTargets;
};

class F7E0Picker
{
  public:
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
    F7E0Ref* m_pkDefault;

    F7E0Ref* SelectTarget(F7E0Ref* pkRef, F7E0Data* pkData);
};
// Iterates quest marker nodes, creates a map tile per reference, positions and configures it, and links a name tile when the marker name differs.
// @fnv 0x0079e470
void MarkerMenu::UpdateQuestMarkers()
{
    QuestMarkerNode* p = ((::QuestMarkerNode *)(::FUN_005eb7e0((void *)(((MarkerPlayer*)::_g_thePlayer)))));
    MarkerTile* a;
    while (p)
    {
        MarkerReference* aMap = (MarkerReference*)((::TESObjectREFR *)(new ((void *)(p)) ::Vec3()));
        TeleportPathHelper aArea;
        if (m_iMapDisplayMode == 33)
            reinterpret_cast<::FUN_00952d60_stand *>((((MarkerPlayer*)::_g_thePlayer)))->FUN_00952d60(aMap, (::PathingPath *)(::TeleportPathHelper *)(&aArea), 1);
        MarkerReference* aFirst = m_iMapDisplayMode == 33 ? (MarkerReference*)((::TESObjectREFR *)(reinterpret_cast<::F7E0Picker *>(this)->SelectTarget((::F7E0Ref *)(aMap), (::F7E0Data *)(::TeleportPathHelper *)(&aArea)))) : aMap;
        a = aFirst ? ((::MarkerTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((MarkerTile*)m_pMapTile)))->FUN_00a03da0((char *)(reinterpret_cast<::FUN_0055d520_shell *>((aFirst))->FUN_0055d520())))) : 0;
        if (a && reinterpret_cast<::FUN_00a011f0_shell *>((a))->FUN_00a011f0(0xfc4) && !FUN_00404dc0(reinterpret_cast<::FUN_0055d520_shell *>((aMap))->FUN_0055d520(), reinterpret_cast<::FUN_00a011f0_shell *>((a))->FUN_00a011f0(0xfc4)))
        {
            char markerName[64];
            sprintf(markerName, "%s Marker", aFirst ? reinterpret_cast<::FUN_0055d520_shell *>((aFirst))->FUN_0055d520() : 0);
            MarkerTile* aB = aFirst ? ((::MarkerTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((MarkerTile*)m_pMapTile)))->FUN_00a03da0((char *)(markerName)))) : 0;
            NiPoint3 _point2 = *aFirst->GetPos();
            NiPoint3 _pos2 = _point2;
            if (m_iMapDisplayMode == 33)
                _pos2.y -= 1024.0;
            else
                _pos2.y -= 128.0;
            NiPoint3 aCollision;
            NiPoint3 aOffset;
            if (pAdjustNorthRotationCell)
                reinterpret_cast<::TESObjectCELL_Ext *>((pAdjustNorthRotationCell))->FUN_00555b10(_point2, _point2, true);
            aCollision = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(_point2)), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((aFirst))->FUN_00575d70()))), {})));
            aOffset = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(_pos2)), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((aFirst))->FUN_00575d70()))), {})));
            float _target = reinterpret_cast<::TileListBoxCalls *>((((MarkerTile*)m_pMapTile)))->GetFloat(0xfb1);
            float _scale = reinterpret_cast<::TileListBoxCalls *>((((MarkerTile*)m_pMapTile)))->GetFloat(0xfb0);
            _target *= aOffset.x;
            _scale *= aOffset.y;
            float fX7 = _target;
            float fY3 = _scale;
            reinterpret_cast<::FUN_00a012d0_t *>((a))->FUN_00a012d0(DAT_011da350, aOffset.x, true);
            reinterpret_cast<::FUN_00a012d0_t *>((a))->FUN_00a012d0(DAT_011da34c, aOffset.y, true);
            reinterpret_cast<::FUN_00a012d0_t *>((a))->FUN_00a012d0(0xfa1, fX7, true);
            reinterpret_cast<::FUN_00a012d0_t *>((a))->FUN_00a012d0(0xfa2, fY3, true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((a))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::FUN_0055d520_shell *>((aMap))->FUN_0055d520()), true);
            reinterpret_cast<::FUN_00a012d0_t *>((a))->FUN_00a012d0(0xfba, 200.0f, true);
            a->Set(0xfaa, 38);
            reinterpret_cast<::FUN_00a012d0_t *>((a))->FUN_00a012d0(0xfad, 2.0f, true);
            a->Set(0xfa3, 1);
            a->Set(0xfae, 1);
            a->Set(0xfb7, 2);
            a->Set(0xfb9, 2);
            reinterpret_cast<::FUN_00a012d0_t *>((a))->FUN_00a012d0(0xfb0, 60.0f, true);
            if (aB)
            {
                LBValue* aCreated = (LBValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((a))->FUN_00a00f30(0xfa1)));
                LBValue* aCacheObject = (LBValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((a))->FUN_00a00f30(0xfa2)));
                reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((aCreated))->RemoveFromReactions();
                reinterpret_cast<::AGOwner *>((aCreated))->FUN_00a09130(0x7d0, aB, 0xfa1);
                reinterpret_cast<::fnv_00a09410::EvalValue *>((aCreated))->FUN_00a09410(0);
                reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((aCacheObject))->RemoveFromReactions();
                reinterpret_cast<::AGOwner *>((aCacheObject))->FUN_00a09130(0x7d0, aB, 0xfa2);
                reinterpret_cast<::P03Value *>((aCacheObject))->AppendFloatAction(0x7d1, 60.0f);
                reinterpret_cast<::fnv_00a09410::EvalValue *>((aCacheObject))->FUN_00a09410(0);
            }
            reinterpret_cast<::FUN_00a07530_shell *>((a))->FUN_00a07530(0x3ff);
        }
        p = ((::QuestMarkerNode *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
    }
}
// @fnv 0x0079f360
void QuestMapMenu::UpdateQuestMarker()
{
    TESObjectREFR* reference = m_iMapDisplayMode == 33
                                   ? ((::TESObjectREFR *)(reinterpret_cast<::F7E0Picker *>(this)->SelectTarget((::F7E0Ref *)(::TESObjectREFR *)(reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400()),
                                                  (::F7E0Data *)(::PathingPath *)((PathingPath*)((FUN_0079f620_shell*)::_g_thePlayer)->GetOffsetPointer()))))
                                   : ((::TESObjectREFR *)(reinterpret_cast<::C77a400 *>((((QuestMapPlayer*)::_g_thePlayer)))->GetFirstOrFallback()));
    if (reference)
    {
        if (m_iMapDisplayMode == 33)
            FUN_0079f8d0(m_pFirstMapReference, reference, ((FUN_0079f620_shell*)::_g_thePlayer)->GetOffsetPointer(), 30);
    }
    else if (reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400())
    {
        if ((m_iMapDisplayMode == 33 && !reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((QuestMapReference*)reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400())))->FUN_00575d10()) ||
            (m_iMapDisplayMode == 32 && ((void *)(reinterpret_cast<::LowProcess *>((((QuestMapReference*)reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400())))->GetTarget())) ==
                                            ((void *)(reinterpret_cast<::LowProcess *>((((QuestMapPlayer*)::_g_thePlayer)))->GetTarget()))))
            reference = reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400();
    }
    if (reference)
    {
        NiPoint3 position;
        NiPoint3 mapPosition;
        position = *reference->GetPos();
        if (pAdjustNorthRotationCell)
            reinterpret_cast<::TESObjectCELL_Ext *>((pAdjustNorthRotationCell))->FUN_00555b10(position, position, true);
        mapPosition = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(position)), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((QuestMapReference*)reference)))->FUN_00575d70()))), {})));
        {
            Tile* parent = m_iMapDisplayMode == 33 ? m_pTiles[5] : m_pTiles[3];
            {
                Tile* marker = 0;
                if (m_iMapDisplayMode == 33)
                    marker =
                        reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((LBMenu*)DAT_011da368)))->FUN_00a1ddb0((::Tile *)(::LBTile *)((LBTile*)m_pMapTile), (char *)("WorldMapQuestMarkerTemplate"), (::Tile *)(0));
                else
                    marker =
                        reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((LBMenu*)DAT_011da368)))->FUN_00a1ddb0((::Tile *)(::LBTile *)((LBTile*)m_pMapTile), (char *)("LocalMapQuestMarkerTemplate"), (::Tile *)(0));
                reinterpret_cast<::FUN_00a012d0_t *>((marker))->FUN_00a012d0(DAT_011da350, mapPosition.x, true);
                reinterpret_cast<::FUN_00a012d0_t *>((marker))->FUN_00a012d0(DAT_011da34c, mapPosition.y, true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((marker))->FUN_00a01350(0xfcc, (char *)("glow_hud_compass_pc_marker.dds"), true);
                marker->Set(0xfaa, 28);
                reinterpret_cast<::FUN_00a012d0_t *>((marker))->FUN_00a012d0(0xfad, 5.0f, true);
                {
                    LBValue* value = (LBValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((marker))->FUN_00a00f30(0xff5)));
                    reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
                    reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(2000, parent, 0xff5);
                    reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
                }
            }
        }
    }
}

// Returns the last flagged target from pkData's target list when pkRef is persistent, else m_pkDefault or pkRef; returns 0 for empty data.
// @fnv 0x0079f7e0
F7E0Ref* F7E0Picker::SelectTarget(F7E0Ref* pkRef, F7E0Data* pkData)
{
    F7E0Ref* pkResult = 0;
    if (!pkData || (!((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((pkData))->GetName())) && !((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkData->m_kTargets))->GetName()))))
    {
        pkResult = 0;
    }
    else if (pkRef && reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((pkRef))->FUN_00575d10())
    {
        bool bFound = false;
        for (int i = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((pkData))->GetName())) - 1; !bFound && i >= 0; i--)
        {
            if (pkData->GetAt(i)->m_bEnableState && (unsigned int)i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkData->m_kTargets))->GetName())))
            {
                pkResult = ((::F7E0Ref *)(reinterpret_cast<::FUN_00558dd0_class *>((void *)&(pkData->m_kTargets))->FUN_00558dd0(i)));
                bFound = true;
            }
        }
        if (!bFound)
            pkResult = m_pkDefault;
    }
    else
    {
        pkResult = pkRef;
    }
    return pkResult;
}

namespace fnv_0079f8d0 {
struct RefHandle053
{
};
struct Ref053 : TESObjectREFR
{
};
struct PathArray053
{
    TESObjectREFR** data;
    unsigned int size, capacity, grow;
};
class PathingPath
{
  public:
    int unk00, unk04, unk08, unk0c;
    PathArray053 refs;
};
struct Menu053
{
};
struct Value053
{
};
struct Tile053 : Tile
{
};
struct NiPoint2_helper
{
    float x, y;
    NiPoint2_helper(float, float);
};
double __cdecl ForwardFloatAndInt(float, int);
struct Map053 : MapMenu
{
    void FUN_0079f8d0(TESObjectREFR*, TESObjectREFR*, PathingPath*, int);
};
// @fnv 0x0079f8d0
void Map053::FUN_0079f8d0(TESObjectREFR* start, TESObjectREFR* end, PathingPath* path, int id)
{
    if (!start || !end || !path)
        return;
    BSSimpleList<Tile*> first;
    NiPoint3 endPos = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(*start->GetPos())), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((start))->FUN_00575d70()))), {})));
    Tile* width;
    NiPoint3 height = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(*end->GetPos())), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((end))->FUN_00575d70()))), {})));
    Tile* startPos = 0;
    width = 0;
    startPos = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((Menu053*)DAT_011da368)))->FUN_00a1ddb0(m_pMapTile, (char *)("WaypointTemplate"), (::Tile *)(0));
    reinterpret_cast<::FUN_00a012d0_t *>((startPos))->FUN_00a012d0(DAT_011da350, endPos.x, true);
    reinterpret_cast<::FUN_00a012d0_t *>((startPos))->FUN_00a012d0(DAT_011da34c, endPos.y, true);
    startPos->Set(0xfaa, id);
    reinterpret_cast<::FUN_00a012d0_t *>((startPos))->FUN_00a012d0(0xfa9, 0.0f, true);
    if (((TESForm*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((RefH*)start))->FUN_007af430())))->GetFormType() == 0x1c &&
        reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((Ref053*)((::TESObjectREFR *)(::FUN_00559450((int *)(((::fnv_0079f8d0::RefHandle053 *)(reinterpret_cast<::TESObjectREFR *>((((Ref053*)start)))->GetExtraRadioData())))))))))->FUN_00575d10())
        startPos->Set(0x1004, 1);
    reinterpret_cast<::Callees *>(&(first))->FUN_00905820((void *)&(startPos));
    int waypoints = 0;
    float last;
    int begin = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(path->refs))->GetName())) - 1;
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(path->refs))->GetName())); i++)
    {
        if (((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(i))) == start ||
            ((::TESObjectREFR *)(::FUN_00559450((int *)(((::fnv_0079f8d0::RefHandle053 *)(reinterpret_cast<::TESObjectREFR *>((((Ref053*)((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(i))))))->GetExtraRadioData())))))) == start)
            waypoints = i + 1;
        if (((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(i))) == end ||
            ((::TESObjectREFR *)(::FUN_00559450((int *)(((::fnv_0079f8d0::RefHandle053 *)(reinterpret_cast<::TESObjectREFR *>((((Ref053*)((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(i))))))->GetExtraRadioData())))))) == end)
            begin = i - 1;
    }
    for (int j = waypoints; j <= begin; j++)
    {
        TESObjectREFR* ref = !reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((Ref053*)((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(j))))))->FUN_00575d10() ? ((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(j))) : 0;
        if (!ref)
            ref = ((::TESObjectREFR *)(::FUN_00559450((int *)(((::fnv_0079f8d0::RefHandle053 *)(reinterpret_cast<::TESObjectREFR *>((((Ref053*)((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(j))))))->GetExtraRadioData()))))));
        if (ref && !reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((Ref053*)ref)))->FUN_00575d10())
        {
            Tile* middle = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((Menu053*)DAT_011da368)))->FUN_00a1ddb0(m_pMapTile, (char *)("WaypointTemplate"), (::Tile *)(0));
            NiPoint3 middlePos = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(*ref->GetPos())), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((ref))->FUN_00575d70()))), {})));
            reinterpret_cast<::FUN_00a012d0_t *>((middle))->FUN_00a012d0(DAT_011da350, middlePos.x, true);
            reinterpret_cast<::FUN_00a012d0_t *>((middle))->FUN_00a012d0(DAT_011da34c, middlePos.y, true);
            middle->Set(0xfaa, id);
            if (reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((Ref053*)((::TESObjectREFR *)(::FUN_00559450((int *)(((::fnv_0079f8d0::RefHandle053 *)(reinterpret_cast<::TESObjectREFR *>((((Ref053*)((::TESObjectREFR *)(reinterpret_cast<::FUN_00558dd0_class *>(&(path->refs))->FUN_00558dd0(j))))))->GetExtraRadioData())))))))))->FUN_00575d10())
                middle->Set(0x1004, 1);
            reinterpret_cast<::Callees *>(&(first))->FUN_00905820((void *)&(middle));
        }
    }
    width = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((Menu053*)DAT_011da368)))->FUN_00a1ddb0(m_pMapTile, (char *)("WaypointTemplate"), (::Tile *)(0));
    reinterpret_cast<::FUN_00a012d0_t *>((width))->FUN_00a012d0(DAT_011da350, height.x, true);
    reinterpret_cast<::FUN_00a012d0_t *>((width))->FUN_00a012d0(DAT_011da34c, height.y, true);
    width->Set(0xfaa, id);
    reinterpret_cast<::FUN_00a012d0_t *>((width))->FUN_00a012d0(0xfa9, 0.0f, true);
    reinterpret_cast<::Callees *>(&(first))->FUN_00905820((void *)&(width));
    last = m_pMapTile ? m_pMapTile->GetFloat(0xfcd) : 0.0f;
    float finish = m_pMapTile ? m_pMapTile->GetFloat(0xfce) : 0.0f;
    for (BSSimpleList<Tile*>* node = &first; node && ((::Tile *)(new ((void *)(node)) ::Vec3())) && ((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())); node = ((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        Tile* line = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((Menu053*)DAT_011da368)))->FUN_00a1ddb0(((::Tile *)(new ((void *)(node)) ::Vec3())), (char *)("PathLineTemplate"), (::Tile *)(0));
        NiPoint2_helper b(((::Tile *)(new ((void *)(node)) ::Vec3()))->GetFloat(DAT_011da350), ((::Tile *)(new ((void *)(node)) ::Vec3()))->GetFloat(DAT_011da34c));
        NiPoint2_helper a(((::Tile *)(new ((void *)(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))) ::Vec3()))->GetFloat(DAT_011da350),
                          ((::Tile *)(new ((void *)(((::BSSimpleList< ::Tile *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))) ::Vec3()))->GetFloat(DAT_011da34c));
        line->Set(0xfaa, id);
        reinterpret_cast<::FUN_00a012d0_t *>((line))->FUN_00a012d0(0x1004,
                  ::FUN_004579e0(ForwardFloatAndInt((a.x - b.x) * last, 2) + ForwardFloatAndInt((a.y - b.y) * finish, 2)),
                  true);
        reinterpret_cast<::FUN_00a012d0_t *>((line))->FUN_00a012d0(0xffa, -::FUN_004b5550(a.y - b.y, a.x - b.x), true);
        if (reinterpret_cast<::FUN_00a01230_shell *>((((::fnv_0079f8d0::Value053 *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Tile053*)line)))->FUN_0045cd60()))))->IsTraitNonZero({}))
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((line))->FUN_00a01350(0xfcc, (char *)("Interface\\Worldmap\\waypoint_path_interior.dds"), true);
    }
}
}  // namespace fnv_0079f8d0

struct InsertTile;
struct InsertAction
{
};
struct CloneTile
{
};
struct InsertTile
{
};
struct FUN_007a62e0
{
    InsertTile* tile;
    void* data;
    unsigned int flags;
    FUN_007a62e0(InsertTile*, void* const&);
};
typedef int(__cdecl* InsertCompare)(FUN_007a62e0*, FUN_007a62e0*);
struct InsertList
{
    unsigned int first, last;
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct ListInserter
{
    unsigned int unk00;
    InsertList items;
    InsertTile* root;
    unsigned int unk10, unk14;
    const char* templateName;
    unsigned short nextID, unk1e;
    InsertTile* InsertTileFromTemplate(void*, const char*, InsertCompare, const char*);
};
// @fnv 0x007a1dd0
InsertTile* ListInserter::InsertTileFromTemplate(void* data, const char* text, InsertCompare compare,
                                                 const char* source)
{
    if (root && (templateName || source))
    {
        InsertTile* pTile = ((::InsertTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::CloneTile *)(reinterpret_cast<::FUN_00a03c90_shell *>((root))->FUN_00a03c90()))))->FUN_00a1ddb0({}, {}, {})));
        InsertAction* action;
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((pTile))->FUN_00a00f30(0xfaa))
            reinterpret_cast<::Tile *>((pTile))->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTile))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>(&(items))->FUN_007a7eb0((::BGSPerkEntry *)(::FUN_007a62e0 *)(new FUN_007a62e0(pTile, data)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::fnv_007a6480::FUN_007a6480_cls *>(this)->FUN_007a6480();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(items))->FUN_00905820((void *)&(const ::FUN_007a62e0 *const &)(new FUN_007a62e0(pTile, data)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(pTile));
                reinterpret_cast<::fnv_007a6920::ScrollList *>(this)->FUN_007a6920();
            }
            reinterpret_cast<::Tile *>((pTile))->Set(0xfac, nextID++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((root))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > 0.0)
        {
            action = ((::InsertAction *)(reinterpret_cast<::FUN_00a00e90_shell *>((root))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((action))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((action))->FUN_00a09130(2000, (::Tile *)(pTile), 0xfb0);
            reinterpret_cast<::P03Value *>((action))->AppendFloatAction(2003, reinterpret_cast<::TileListBoxCalls *>((root))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((action))->FUN_00a09410(0);
        }
        return pTile;
    }
    else
        return 0;
}

struct MyTile;
struct MyValue
{
};
struct MyTile
{
};
struct MyMaker
{
};
struct MyParent
{
};
struct MyItem
{
    MyTile* tile;
    int object;
    char isFilteredOut;
    MyItem(MyTile* t, int* o);
};
struct MyList
{
    MyItem* item;
    MyList* next;
};

struct MyBox
{
    virtual void vfn_00();
    MyList list;
    MyParent* parentTile;
    MyTile* selected;
    MyTile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    MyTile* CreateListItem(int item, const char* text, int (*sortFunc)(MyItem*, MyItem*), const char* altTemplate);
};

struct NoteFilterTile : Tile
{
};
struct NoteFilterItem
{
    NoteFilterTile* tile;
    BGSNote* note;
    bool filtered;
};
struct NoteFilterList
{
    NoteFilterItem* item;
    NoteFilterList* next;
};
struct NoteFilterBox : NoteFilterList
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual NoteFilterTile* GetTile(int, bool);
    NoteFilterTile* parent;
    NoteFilterTile* selected;
    Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    float height;
    NoteFilterTile* FUN_007a6220();
    void ApplyNoteFilter(bool (*filter)(BGSNote*));
};
// @fnv 0x00796fd0
void MapMenuClick::FUN_00796fd0(int aiID, Tile* apTarget)
{
    if (apTarget == 0 && aiID >= 0 && aiID < 22)
        apTarget = m_pTiles[aiID];

    switch (aiID)
    {
    case 23:
        if (m_kQuestListBox.GetSelectedData() && !reinterpret_cast<::FUN_0059e400_shell *>((m_kQuestListBox.GetSelectedData()))->FUN_0059e400())
        {
            reinterpret_cast<::Obj_009529d0 *>((::_g_thePlayer))->FUN_009529d0((int)(m_kQuestListBox.GetSelectedData()));
            ::FUN_00706f30(3);
            reinterpret_cast<::MapMenu *>(this)->FUN_0079af30();
        }
        break;
    case 24:
        if (!DAT_011da36d)
        {
            SoundPlaybackHandle hsndHandle;
            BGSNote* pnote = ((::BGSNote *)(reinterpret_cast<::LBList *>(&(m_kNoteListBox))->FindItemData(apTarget)));
            bool bisSoundNote = reinterpret_cast<::FUN_005e8d40_shell *>((pnote))->GetNoteType() == 0 || reinterpret_cast<::FUN_005e8d40_shell *>((pnote))->GetNoteType() == 3;
            if (pnote && (!FUN_004b71d0() || bisSoundNote))
            {
                bool bnoteMatch = pnote == m_pSelectedNote;
                Tile* poldSelectedTile;
                bool bsoundStopped = false;
                poldSelectedTile = ((::Tile *)(reinterpret_cast<::Owner *>(&(m_kNoteListBox))->FindItemData((int *)&(m_pSelectedNote))));
                if (poldSelectedTile)
                    poldSelectedTile->Set(DAT_011da348, 0);
                if (!bnoteMatch || (bisSoundNote && !m_pkActiveSoundList))
                {
                    SelectNote(pnote);
                    apTarget->Set(DAT_011da348, 1);
                    m_pSelectedNote = pnote;
                    m_pTiles[13]->Set(0x1004, 1);
                }
                else
                {
                    m_pSelectedNote = 0;
                    m_pTiles[13]->Set(0x1004, 0);
                }
                if (m_pkActiveSoundList)
                {
                    reinterpret_cast<::FUN_00798ad0_shell *>(this)->StopHolotapeAudio();
                    bsoundStopped = true;
                }
                if (bisSoundNote && !((bool)(reinterpret_cast<::FUN_00798420_shell *>((pnote))->GetUnk7d())))
                {
                    reinterpret_cast<::FUN_00a012d0_t *>((apTarget))->FUN_00a012d0(DAT_011da344, 128.0f, true);
                    reinterpret_cast<::FUN_005e9300_Host *>((pnote))->SetRead(true);
                }
                if (bisSoundNote && (!bnoteMatch || !bsoundStopped))
                {
                    if (reinterpret_cast<::FUN_005e8d40_shell *>((pnote))->GetNoteType() == 0 && pnote->FUN_005e9100())
                    {
                        reinterpret_cast<::NavMeshListNode *>((((FUN_007a19a0_shell*)&m_kSoundList)))->FUN_007a19a0((::NavMeshPayload *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByFormID(
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pnote->FUN_005e9100()))->FUN_0084e3a0())), 0x101)));
                        m_bMapListUpdatePending = true;
                    }
                    else if (reinterpret_cast<::FUN_005e8d40_shell *>((pnote))->GetNoteType() == 3 && pnote->FUN_005e9240() && pnote->FUN_005e92a0())
                    {
                        Character* pVoiceNoteNPC = new Character(false);
                        pVoiceNoteNPC->NotifySaveLoadGameOfFormChange();
                        Conversation* pVoiceNoteConvo = 0;
                        reinterpret_cast<::Fn575690 *>((pVoiceNoteNPC))->FUN_00575690(pnote->FUN_005e92a0());
                        pVoiceNoteConvo = new Conversation(pVoiceNoteNPC, ::_g_thePlayer, pnote->FUN_005e9240());
                        reinterpret_cast<::Mid83b9a0 *>((((FUN_0083b9a0_shell*)pVoiceNoteConvo)))->FUN_0083b9a0();
                        if (((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((pVoiceNoteConvo))->GetActiveResponse())) &&
                            ((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((pVoiceNoteConvo))->GetActiveResponse()))->SelectDefaultResponseList())
                        {
                            do
                            {
                                reinterpret_cast<::FUN_007a1ac0_cls *>((((FUN_007a1ac0_shell*)&SubtitlesToShow)))->FUN_007a1ac0(
                                        (*(::BSStringT<char> *)(new ((void *)(((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((pVoiceNoteConvo))->GetActiveResponse()))->GetActiveResponse())) ::Vec3())));
                                reinterpret_cast<::FUN_0061f170_cls *>((((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((pVoiceNoteConvo))->GetActiveResponse()))))->FUN_0084e3a0()))))->FUN_0061f170((void *)(0), (::ArgObj *)(pVoiceNoteNPC));
                                hsndHandle = ::FUN_00453a70()->GetSoundHandleByFilePath(
                                    *((::BSStringT<char> *)(::FUN_00460140((int)(((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((pVoiceNoteConvo))->GetActiveResponse()))->GetActiveResponse())))), 0x105,
                                    0);
                                reinterpret_cast<::FUN_00ad89e0_shell *>(&(hsndHandle))->FUN_00ad89e0(0.9f);
                                reinterpret_cast<::NavMeshListNode *>((((FUN_007a19a0_shell*)&m_kSoundList)))->FUN_007a19a0((::NavMeshPayload *)&(hsndHandle));
                                reinterpret_cast<::FUN_0061f170_cls *>((((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((pVoiceNoteConvo))->GetActiveResponse()))))->FUN_0084e3a0()))))->FUN_0061f170((void *)(1), (::ArgObj *)(pVoiceNoteNPC));
                                m_bMapListUpdatePending = true;
                            } while (reinterpret_cast<::FUN_0083c7e0_shell *>((((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((pVoiceNoteConvo))->GetActiveResponse()))))->FUN_0083c7e0());
                        }
                        delete pVoiceNoteConvo;
                        delete pVoiceNoteNPC;
                    }
                    if (m_bMapListUpdatePending)
                    {
                        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyHolotapeStart", 0x121)))->FUN_00ad8830(false);
                        BSAudio::EnableAudio();
                        reinterpret_cast<::DialogMenuAudioCalls *>((::FUN_00453a70()))->EnableAudio();
                    }
                }
            }
        }
        break;
    case 25: {
        Tile* pcurrTile = m_kMapMarkerListBox.GetSelectedTile();
        if (pcurrTile->GetFloat(DAT_011da344) == 255.0)
        {
            bool bunselected = !reinterpret_cast<::FUN_00a01230_shell *>((pcurrTile))->IsTraitNonZero(DAT_011da348);
            reinterpret_cast<::FUN_0079c090_shell *>(this)->FUN_0079c090();
            reinterpret_cast<::LBList_7314c0 *>(&(m_kMapMarkerListBox))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(Tile *, TESObjectREFR *))::FUN_0079be80)), 0, 0x7fffffff);
            if (FUN_00798440())
                FalloutRadio::SetRadioEnabled(false);
            if (bunselected)
            {
                FalloutRadio::SetRadioEnabled(true);
                ::fnv_00832240::FUN_00832240((::fnv_00832240::RefView *)(::TESObjectREFR *)(m_kMapMarkerListBox.GetSelectedData()), false);
                pcurrTile->Set(DAT_011da348, 1);
            }
            reinterpret_cast<::MapMenu *>(this)->FUN_0079af30();
        }
    }
    break;
        break;
    case 18:
        if (m_iMapDisplayMode == 0x23)
            SetMapDisplayMode(true);
        break;
    case 12:
        switch (m_iMapDisplayMode)
        {
        case 0x23:
            if (!DAT_011da36d)
            {
                m_bMapMenuActive = !m_bMapMenuActive;
                reinterpret_cast<::NoteFilterBox *>((((FUN_007a2e30_shell*)&m_kNoteListBox)))->ApplyNoteFilter(((bool (&)(BGSNote *))::FUN_0079b390));
                m_pTiles[13]->Set(0xfa3, 0);
                m_pTiles[12]->Set(Tile::GetTraitID("_ShowingAllNotes"), m_bMapMenuActive);
            }
            else
            {
                if (++DAT_011da36e > 2)
                    DAT_011da36e = 0;
                ((FUN_007a5730_shell*)&m_kChallengeListBox)->FUN_007a5730(((bool (&)(TESChallenge *))::fnv_0079b720::FUN_0079b720));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[21]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((DAT_011a03e4[DAT_011da36e]))->GetMenuTitle()))), true);
                m_pTiles[20]->Set(0xfa3, 0);
                m_pTiles[13]->Set(0xfa3, 0);
            }
            break;
        case 0x20:
        case 0x21:
            if (m_pMapTile)
            {
                if (FUN_004b71d0())
                {
                    m_kPlayerWorldPosition =
                        NiPoint3(((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pMapTile))->FUN_0045cd60()))->GetFloat(0xfb1) / 2.0 - m_pMapTile->GetFloat(0xfa1),
                                 ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pMapTile))->FUN_0045cd60()))->GetFloat(0xfb0) / 2.0 - m_pMapTile->GetFloat(0xfa2), 0.0f);
                }
                else
                {
                    m_kPlayerWorldPosition =
                        NiPoint3(reinterpret_cast<::MyHack *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007697f0(), reinterpret_cast<::S *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->GetScaledValue(), 0.0f);
                    m_kPlayerWorldPosition.x -= reinterpret_cast<::FUN_00a013d0_shell *>((m_pMapTile))->GetTotalFloat();
                    m_kPlayerWorldPosition.y -= reinterpret_cast<::FUN_00a01440_shell *>((m_pMapTile))->GetAccumulatedFloat();
                }
                if (m_iMapDisplayMode == 0x20)
                {
                    m_pCurrentMapSpace = m_pCurrentMapForm;
                    m_kPlayerWorldPosition = reinterpret_cast<::FUN_0079c450_shell *>(this)->FUN_0079c450(
                        reinterpret_cast<::Point3_0053d280 *>((void *)(((const FUN_0053d280_shell*)&m_kPlayerWorldPosition)))->FUN_0053d280(m_pMapTile->GetFloat(0xfb1)),
                        m_pCurrentMapSpace->GetFormType() == kWorldSpace ? (TESWorldSpace*)m_pCurrentMapSpace : 0);
                    m_kPlayerWorldPosition = m_kPlayerWorldPosition;
                }
                else
                {
                    m_kPlayerWorldPosition = reinterpret_cast<::FUN_0079c450_shell *>(this)->FUN_0079c450(
                        reinterpret_cast<::Point3_0053d280 *>((void *)(((const FUN_0053d280_shell*)&m_kPlayerWorldPosition)))->FUN_0053d280(m_pMapTile->GetFloat(0xfb1)),
                        0);
                    m_pCurrentMapSpace = FUN_007984d0(m_kPlayerWorldPosition);
                    if (m_pCurrentMapSpace)
                        reinterpret_cast<::FUN_00588e40_shell *>((((TESWorldSpace*)m_pCurrentMapSpace)))->TransformWorldPoint((::Pt3 *)&(m_kPlayerWorldPosition), true);
                }
                if (pAdjustNorthRotationCell)
                    reinterpret_cast<::TESObjectCELL_Ext *>((pAdjustNorthRotationCell))->FUN_00555b10(m_kPlayerWorldPosition, m_kPlayerWorldPosition, false);
                m_pTiles[6]->Set(0xfa3, 0);
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIPopUpMapMarkerAdded ", 0x121)))->FUN_00ad8830(false);
                if (reinterpret_cast<::FUN_00798400_shell *>((::_g_thePlayer))->FUN_00798400())
                    ::fnv_00703e80::FUN_00703e80(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d4438))))->GetMenuTitle())), 0, 0, FUN_00798840, 0, 0x17, 0.0f, 0.0f,
                                                ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d4960))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d33a8))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d4f54))))->GetMenuTitle())), 0);
                else
                    ::fnv_00703e80::FUN_00703e80(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3a2c))))->GetMenuTitle())), 0, 0, FUN_00798840, 3, 0x17, 0.0f, 0.0f,
                                                ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d34f8))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3684))))->GetMenuTitle())), 0);
            }
            break;
        case 0x22:
            if (m_pSelectedMapMarkerInfo)
            {
                HandleSelection(0x21, 0);
                TESObjectREFR* ptargetRef = ((::TESObjectREFR *)(reinterpret_cast<::F7E0Picker *>(this)->SelectTarget((::F7E0Ref *)(::TESObjectREFR *)(m_pSelectedMapMarkerInfo->GetReference(true)),
                                                                   (::F7E0Data *)(::PathingPath *)(((::PathingPath *)(::FUN_00460140((int)(m_pSelectedMapMarkerInfo))))))));
                if (ptargetRef && m_pMapTile)
                {
                    NiPoint3 centerPoint = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(*ptargetRef->GetPos())), (::NiPoint3)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((ptargetRef))->FUN_00575d70()))), {})));
                    reinterpret_cast<::FUN_00a012d0_t *>((m_pMapTile))->FUN_00a012d0(0xfa1,
                                    ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pMapTile))->FUN_0045cd60()))->GetFloat(0xfb1) / 2.0 -
                                        m_pMapTile->GetFloat(0xfb1) * centerPoint.x,
                                    false);
                    reinterpret_cast<::FUN_00a012d0_t *>((m_pMapTile))->FUN_00a012d0(0xfa2,
                                    ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pMapTile))->FUN_0045cd60()))->GetFloat(0xfb0) / 2.0 -
                                        m_pMapTile->GetFloat(0xfb0) * centerPoint.y,
                                    false);
                }
            }
            break;
        }
        break;
    case 26:
        if (m_iMapDisplayMode == 0x21 &&
            (FUN_004b71d0() || (m_pMapTile && m_kMapOffset.x == m_pMapTile->GetFloat(0xfa1) &&
                                m_kMapOffset.y == m_pMapTile->GetFloat(0xfa2))) &&
            reinterpret_cast<::FUN_00a01230_shell *>((m_pTiles[11]))->IsTraitNonZero(0xfaf) && reinterpret_cast<::fnv_0093d660::TravelObject *>((::_g_thePlayer))->FUN_0093d660())
        {
            int imarkerCt = 0;
            BSSimpleList<TESObjectREFR*>* pcurrMarker;
            for (pcurrMarker = &m_kMapMarkerList; pcurrMarker && ((::TESObjectREFR *)(new ((void *)(pcurrMarker)) ::Vec3())) &&
                                                  imarkerCt <= apTarget->GetFloat(::FUN_00a00940("_MarkerIndex", -1));
                 pcurrMarker = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((pcurrMarker))->FUN_00726070())))
            {
                m_pSecondMapReference = ((::TESObjectREFR *)(new ((void *)(pcurrMarker)) ::Vec3()));
                imarkerCt++;
            }
            if (reinterpret_cast<::FUN_00569060_shell *>((m_pSecondMapReference))->FUN_00569060()->IsTravelLocation())
            {
                char strtemp[256];
                HandleMouseDown(aiID, apTarget);
                ::FUN_00406d00(strtemp, 256, "%s %s?", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d4a38))))->GetMenuTitle())),
                          reinterpret_cast<::StringHolder *>((reinterpret_cast<::FUN_00569060_shell *>((m_pSecondMapReference))->FUN_00569060()))->FUN_00438eb0());
                m_pTiles[6]->Set(0xfa3, 0);
                ::fnv_00703e80::FUN_00703e80(strtemp, 0, 0, FUN_00798710, 0, 0x17, 0.0f, 0.0f, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d34f8))))->GetMenuTitle())),
                                            ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3684))))->GetMenuTitle())), 0);
            }
            else
            {
                m_pSecondMapReference = 0;
            }
        }
        else if (m_iMapDisplayMode == 0x21 && !reinterpret_cast<::FUN_00a01230_shell *>((m_pTiles[11]))->IsTraitNonZero(0xfaf) &&
                 _stricmp(reinterpret_cast<::FUN_00a011f0_shell *>((apTarget))->FUN_00a011f0(::FUN_00a00940("_LocationName", -1)), "Companion"))
        {
            ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d48e8))))->GetMenuTitle()))), 2, (int)(0), (int)(0), 2.0f, false);
        }
        break;
    case 2:
    case 4:
        if (m_pSelectedMarkerTile)
            HandleSelection(0x1a, m_pSelectedMarkerTile);
        break;
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
        m_pTiles[17]->Set(DAT_011da360, aiID - 0x20);
        m_iMapDisplayMode = aiID;
        ((Interface*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))
            ->GetPipboyManager()
            ->StartBurst(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db458))))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db37c))))))->f, 0.5f);
        if (!FUN_00709d40() && aiID != 0x20 && aiID != 0x21)
            reinterpret_cast<::FUN_00a012d0_t *>((((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(0xfa9, 255.0f, true);
        m_pTiles[13]->Set(0xfa3, 0);
        m_pTiles[12]->Set(0xfaf, 1);
        ::FUN_0079aba0();
        if (((Interface*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->GetPipboyManager()->IsUnk28Set())
            ::FUN_0079c340(true);
        break;
    }
}
// @fnv 0x007a2e30
void NoteFilterBox::ApplyNoteFilter(bool (*filter)(BGSNote*))
{
    int filteredCount = 0;
    int selectedIndex = -1;
    static int numFiltered = FUN_00a00940("_num_filtered", -1);
    count = 0;
    height = 0.0f;
    for (NoteFilterList* node = this; node && ((::NoteFilterItem *)(new ((void *)(node)) ::Vec3())); node = ((::NoteFilterList *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        ((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->filtered = filter && filter(((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->note);
        if (((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->filtered)
        {
            if (((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->tile == selected)
            {
                selectedIndex = (int)reinterpret_cast<::TileListBoxCalls *>((((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->tile))->GetFloat(0xfac);
                selected = 0;
            }
            ((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->tile->Set(0xfac, -1);
            ++filteredCount;
        }
        else
        {
            if (selectedIndex >= 0 && count == selectedIndex)
                selected = ((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->tile;
            ((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->tile->Set(0xfac, count++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::NoteFilterItem *)(new ((void *)(node)) ::Vec3()))->tile));
        }
    }
    reinterpret_cast<::Tile *>((parent))->Set(numFiltered, filteredCount);
    reinterpret_cast<::ScrollListHost *>(this)->FUN_007a7080();
    if (!selected && selectedIndex >= 0)
        selected = GetTile(selectedIndex, false);
    if (!selected && selectedIndex >= 0)
        selected = FUN_007a6220();
    reinterpret_cast<::FUN_007a6c80_shell *>(this)->UpdateHighlightBox();
}


class Tile7A3
{
  public:
};

class MenuItem7A3
{
  public:
    void FUN_007a30e0(bool bEnabled);

    int unk00;
    int unk04;
    int unk08;
    Tile7A3* m_pkTile;
};
// @fnv 0x0079b240
void NotesMapMenu::RefreshNotesList()
{
    if (DAT_011da368)
    {
        int iUnusedCount = 0;
        m_kNotesList.FreeAllTiles();
        for (int i = 0; i < reinterpret_cast<::FUN_00966a50_Class *>(((*reinterpret_cast<::NoteSource * *>(&::_g_thePlayer))))->FUN_00966a50(); i++)
        {
            NoteData* pkNote = ((::NoteData *)(reinterpret_cast<::FUN_00966bb0_shell *>(((*reinterpret_cast<::NoteSource * *>(&::_g_thePlayer))))->GetItemAt(i)));
            NoteTile* pkTile2 = ((::NoteTile *)(reinterpret_cast<::MyBox *>(&(m_kNotesList))->CreateListItem((int)(pkNote), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pkNote->m_kName))->FUN_00408da0())), (int (*)(MyItem *, MyItem *))(0), (const char *)(0))));
            reinterpret_cast<::Tile *>((pkTile2))->Set(0xfaa, 0x18);
            reinterpret_cast<::FUN_00a012d0_t *>((pkTile2))->FUN_00a012d0(DAT_011da344, ((bool)(reinterpret_cast<::FUN_00798420_shell *>((pkNote))->GetUnk7d())) ? 128.0f : 255.0f, true);
        }
        reinterpret_cast<::MenuItem7A3 *>(&(m_kNotesList))->FUN_007a30e0(true);
        reinterpret_cast<::NoteFilterBox *>(&(m_kNotesList))->ApplyNoteFilter(((bool (&)(BGSNote *))::FUN_0079b390));
        reinterpret_cast<::Tile *>((m_pkNotesTile))->Set(FUN_00a01860("_ShowingAllNotes"), m_bShowingAllNotes);
        reinterpret_cast<::Tile *>((m_pkNotesTile))->Set(0xfaf, ((void *)(::FUN_005cbb50((char *)((*reinterpret_cast<::NoteSource * *>(&::_g_thePlayer)))))) != 0);
    }
}

// Sets the _enabled trait on the menu item's tile to the given boolean value.
// @fnv 0x007a30e0
void MenuItem7A3::FUN_007a30e0(bool bEnabled)
{
    static int s_iEnabledTrait = FUN_00a00940("_enabled", -1);
    reinterpret_cast<::Tile *>((m_pkTile))->Set(s_iEnabledTrait, bEnabled);
}

int FUN_00a01860(const char* apName);

struct ScrollTile_7a3580
{
};

struct MenuStandIn_7a3580
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(int aiValue);
};

struct TileStandIn_7a3580
{
};

struct IMStandIn_7a3580
{
    void Notify(ScrollTile_7a3580* apTile, int aiID, int aiArg);
};


struct ListBoxStandIn_7a3580
{
    virtual void SetSelected(ScrollTile_7a3580* apTile);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual ScrollTile_7a3580* GetTileAt(unsigned int auiIndex);

    int unk04;
    int unk08;
    TileStandIn_7a3580* pListTile;
    int unk10;
    ScrollTile_7a3580* m_pHighlightedTile;
    int unk18;
    int unk1c;
    int unk20;
    float fScrollPos;
    float fScrollValue;

    void UpdateScrollSelection(bool abArg);
};

// @fnv 0x007a3580
void ListBoxStandIn_7a3580::UpdateScrollSelection(bool abArg)
{
    ScrollTile_7a3580* pTile = 0;
    if (pListTile && m_pHighlightedTile)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((m_pHighlightedTile))->FUN_00a012d0(FUN_00a01860("_current_value"), fScrollValue, false);
        reinterpret_cast<::FUN_00a01290_shell *>((m_pHighlightedTile))->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
        pTile = GetTileAt((unsigned int)FUN_0040ebd0(fScrollPos, reinterpret_cast<::fnv_007a6a50::FUN_007a6a50_shell *>(this)->GetUnfilteredCount() - 1.0));
        reinterpret_cast<::FocusManager *>((((::IMStandIn_7a3580 *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00715860((::FocusTile *)(pTile), 0xfc3, abArg);
        SetSelected(pTile);
        if (!::FUN_004b71d0())
        {
            if (pTile)
            {
                ((::MenuStandIn_7a3580 *)(reinterpret_cast<::FUN_00a03c90_shell *>((((::TileStandIn_7a3580 *)(reinterpret_cast<::FUN_00a03d40_shell *>((pListTile))->FUN_00a03d40()))))->FUN_00a03c90()))->v14(reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfaa));
            }
            SetSelected(0);
        }
    }
}

struct InsertBox
{
    virtual void vfn_00();
    LBList list;
    LBTile* parentTile;
    Tile* selected;
    Tile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    Tile* FUN_007a3820(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate);
};
namespace fnv_007a44e0 {
struct InsertBox : LBox
{
    void FUN_007a7d80();
    Tile* FUN_007a44e0(int object, const char* text, int (*sort)(LBItem*, LBItem*), const char* alt);
};
// @fnv 0x007a44e0
Tile* InsertBox::FUN_007a44e0(int object, const char* text, int (*sort)(LBItem*, LBItem*), const char* alt)
{
    if (parentTile && (templateName || alt))
    {
        Tile* tile_2 = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((LBMenu*)reinterpret_cast<::FUN_00a03c90_shell *>((parentTile))->FUN_00a03c90())))->FUN_00a1ddb0((::Tile *)(parentTile), (char *)(alt ? alt : templateName), (::Tile *)(0));
        LBValue* value;
        if (!((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((tile_2))->FUN_00a00f30(0xfaa))))
            tile_2->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile_2))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (sort)
        {
            reinterpret_cast<::FUN_00470440 *>(&(list))->FUN_007a7eb0((::BGSPerkEntry *)(::LBItem *)(new LBItem(tile_2, &object)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(sort));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_007a78e0_cls *>(this)->ProcessEntries();
        }
        else
        {
            {
                reinterpret_cast<::Callees *>(&(list))->FUN_00905820((void *)&(const ::LBItem *const &)(new LBItem(tile_2, &object)));
                if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                {
                    reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile_2));
                    FUN_007a7d80();
                }
                tile_2->Set(0xfac, itemCount++);
            }
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > 0.0)
        {
            value = ((::LBValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((parentTile))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, tile_2, 0xfb0);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile_2;
    }
    else
        return 0;
}
}  // namespace fnv_007a44e0

struct FilterItem
{
    LBTile* tile;
    BGSQuestObjective* object;
    bool filtered;
};
struct FilterNode
{
    FilterItem* item;
    FilterNode* next;
};
struct FilterVirtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual LBTile* v5(int, bool);
};
struct FilterTile
{
};
struct FilterHost : FilterVirtual, FilterNode
{
    FilterTile* parent;
    LBTile* selected;
    LBTile* scroll;
    const char* templateName;
    unsigned short count;
    float height;
    void ApplyObjectiveFilter(bool (*predicate)(BGSQuestObjective*));
};
struct FilterItemTile
{
};
struct FUN_007a5730_node
{
};

struct FUN_007a5730_tile
{
};

struct FUN_007a5730_item
{
    FUN_007a5730_tile* tile;
    int object;
    unsigned char filtered;
};

struct FUN_007a5730_parent
{
    void Add(int, int);
};

struct FUN_007a5730_self
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual FUN_007a5730_tile* vfn_14(int, bool);
    void* headItem;
    void* headNext;
    FUN_007a5730_parent* parentTile;
    FUN_007a5730_tile* selected;
    int selIdx;
    int unk18;
    unsigned short count;
    float scroll;
    FUN_007a5730_tile* Pick();
};

int __cdecl Stamp();

struct FUN_007a6b00_item
{
    Tile* displayTile;
    unsigned int metadata04;
    unsigned char inactive;
};
struct FUN_007a6b00_listNode : SL
{
};
struct FUN_007a6b00_shell : FUN_007a1c90
{
    void AssignTileIndices();
};
// @fnv 0x007a2930
MyTile* MyBox::CreateListItem(int item, const char* text, int (*sortFunc)(MyItem*, MyItem*), const char* altTemplate)
{
    if (parentTile && (templateName || altTemplate))
    {
        MyTile* tile_2 =
            ((::MyTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::MyMaker *)(reinterpret_cast<::FUN_00a03c90_shell *>((parentTile))->FUN_00a03c90()))))->FUN_00a1ddb0({}, {}, {})));
        if (!((int)(reinterpret_cast<::FUN_00a00f30_shell *>((tile_2))->FUN_00a00f30(4010))))
            reinterpret_cast<::Tile *>((tile_2))->Set(4010, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile_2))->FUN_00a01350(4036, (char *)(text), 1);
        if (sortFunc)
        {
            reinterpret_cast<::FUN_00470440 *>(&(list))->FUN_007a7eb0((::BGSPerkEntry *)(::MyItem *)(new MyItem(tile_2, &item)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(sortFunc));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_007a6b00_shell *>(this)->AssignTileIndices();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(list))->FUN_00905820((void *)&(const ::MyItem *const &)(new MyItem(tile_2, &item)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile_2));
                reinterpret_cast<::ScrollListHost *>(this)->FUN_007a7080();
            }
            reinterpret_cast<::Tile *>((tile_2))->Set(4012, itemCount++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > _DAT_01012060)
        {
            MyValue* value = ((::MyValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((parentTile))->FindTraitValue(4016)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(2000, (::Tile *)(tile_2), 4016);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(2003, reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile_2;
    }
    else
    {
        return 0;
    }
}
// Resets f1c and f20, assigns sequential indices to active display tiles via Set(0xfac, ...), then calls FUN_007a7080 and UpdateHighlightBox.
// @fnv 0x007a6b00
void FUN_007a6b00_shell::AssignTileIndices()
{
    f1c = 0;
    f20 = 0.0f;
    for (FUN_007a6b00_listNode* node = reinterpret_cast<FUN_007a6b00_listNode*>(static_cast<SL*>(this));
         node != 0 && *((::FUN_007a6b00_item **)(new ((void *)(node)) ::Vec3())) != 0; node = ((::FUN_007a6b00_listNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        if ((*((::FUN_007a6b00_item **)(new ((void *)(node)) ::Vec3())))->inactive == 0)
        {
            (*((::FUN_007a6b00_item **)(new ((void *)(node)) ::Vec3())))->displayTile->Set(0xfac, static_cast<unsigned short>(f1c++));
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::FUN_007a6b00_item **)(new ((void *)(node)) ::Vec3())))->displayTile));
        }
    }
    reinterpret_cast<::ScrollListHost *>(this)->FUN_007a7080();
    reinterpret_cast<::FUN_007a6c80_shell *>(this)->UpdateHighlightBox();
}

struct Tile_00a011b0 : Tile
{
      // the tile's float value for a trait
};
struct FUN_007a7700_Menu
{
    char pad00[0xc];
    Tile_00a011b0* m_pHighlightedTile;
    char pad10[4];
    Tile* pItemCount;
    char pad18[8];
    float fScrollRange;
    void FUN_007a7700();
};
// Creates a tile for an item via the parent menu, sets its text and value, adds it to the list (sorted or appended), and updates the filtered-count value.
// @fnv 0x007a3820
Tile* InsertBox::FUN_007a3820(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* altTemplate)
{
    if (parentTile && (templateName || altTemplate))
    {
        Tile* tile =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((LBMenu*)reinterpret_cast<::FUN_00a03c90_shell *>((parentTile))->FUN_00a03c90())))->FUN_00a1ddb0((::Tile *)(parentTile), (char *)(altTemplate ? altTemplate : templateName), (::Tile *)(0));
        if (!((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0xfaa))))
            tile->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (sortFunc)
        {
            reinterpret_cast<::FUN_00470440 *>(&(list))->FUN_007a7eb0((::BGSPerkEntry *)(::LBItem *)(new LBItem(tile, &item)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(sortFunc));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::q72::Menu *>(this)->FUN_007a7260();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(list))->FUN_00905820((void *)&(const ::LBItem *const &)(new LBItem(tile, &item)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::FUN_007a7700_Menu *>(this)->FUN_007a7700();
            }
            tile->Set(0xfac, itemCount++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > _DAT_01012060)
        {
            LBValue* value = ((::LBValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((parentTile))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, tile, 0xfb0);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((parentTile))->GetFloat(FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}
// Computes the scroll page count from fScrollRange and the tile's page size, then stores _scroll_delta and _number_of_items on the tiles.
// @fnv 0x007a7700
void FUN_007a7700_Menu::FUN_007a7700()
{
    if (m_pHighlightedTile)
    {
        float fPageSize = reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(0xfb0);
        int iCount = 1;
        if (fScrollRange > 0.0 && fPageSize > 0.0)
        {
            if (fScrollRange > fPageSize)
                iCount =
                    FUN_00647b70((int)FUN_004e4430(((unsigned int)(reinterpret_cast<::fnv_007a71b0::FUN_007a71b0_cls *>(this)->FUN_007a71b0())) * (fScrollRange - fPageSize) / fScrollRange) + 1, 2);
            if (iCount > 1)
                reinterpret_cast<::FUN_00a012d0_t *>((m_pHighlightedTile))->FUN_00a012d0(Tile::GetTraitID("_scroll_delta"), (fScrollRange - fPageSize) / (iCount - 1),
                                        true);
        }
        if (pItemCount)
            pItemCount->Set(Tile::GetTraitID("_number_of_items"), iCount);
    }
}

struct SelectTile;
struct SelectAction
{
};
struct SelectTile
{
};
struct SelectionList
{
    unsigned int unk00, unk04, unk08;
    SelectTile* root;
    SelectTile* selected;
    void UpdateSelectionState();
};
// Updates the root tile's actions and child tiles based on whether a selected tile exists and whether it is enabled.
// @fnv 0x007a7a60
void SelectionList::UpdateSelectionState()
{
    static int DAT_011da4bc = FUN_00a00940(::str_0106f8c0, -1);
    static int DAT_011da4b8 = FUN_00a00940(::str_0106f8ac, -1);
    if (root)
    {
        if (selected)
        {
            SelectAction* first = ((::SelectAction *)(reinterpret_cast<::FUN_00a00f30_shell *>((root))->FUN_00a00f30(DAT_011da4bc)));
            SelectAction* second6 = ((::SelectAction *)(reinterpret_cast<::FUN_00a00f30_shell *>((root))->FUN_00a00f30(DAT_011da4b8)));
            reinterpret_cast<::AGOwner *>((first))->FUN_00a09130(2000, (::Tile *)(selected), 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((first))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((second6))->FUN_00a09130(2000, (::Tile *)(selected), 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((second6))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((selected))->GetSpeechChallengeFailure())
            {
                SelectTile* container = ((::SelectTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(root), ::str_0106f898)));
                if (container)
                {
                    SelectTile* part = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((container))->FUN_00a03da0((char *)(::str_0106f894))));
                    if (part)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((part))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((part))->FUN_00a07530(8);
                        part = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((container))->FUN_00a03da0((char *)(::str_0106f88c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((part))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((part))->FUN_00a07530(8);
                        part = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((container))->FUN_00a03da0((char *)(::str_0106f884))));
                        reinterpret_cast<::FUN_0071aa60_class *>((part))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((part))->FUN_00a07530(8);
                        part = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((container))->FUN_00a03da0((char *)(::str_0106f87c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((part))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((part))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((container))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((container))->FUN_00a07530(8);
                }
            }
            else
            {
                SelectTile* containerOff4 = ((::SelectTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(root), ::str_0106f898)));
                if (containerOff4)
                {
                    SelectTile* partOff3 = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((containerOff4))->FUN_00a03da0((char *)(::str_0106f894))));
                    if (partOff3)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((partOff3))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((partOff3))->FUN_00a07530(8);
                        partOff3 = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((containerOff4))->FUN_00a03da0((char *)(::str_0106f88c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((partOff3))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((partOff3))->FUN_00a07530(8);
                        partOff3 = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((containerOff4))->FUN_00a03da0((char *)(::str_0106f884))));
                        reinterpret_cast<::FUN_0071aa60_class *>((partOff3))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((partOff3))->FUN_00a07530(8);
                        partOff3 = ((::SelectTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((containerOff4))->FUN_00a03da0((char *)(::str_0106f87c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((partOff3))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((partOff3))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((containerOff4))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((containerOff4))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((root))->Set(DAT_011da4bc, -1);
            reinterpret_cast<::Tile *>((root))->Set(DAT_011da4b8, 0);
        }
    }
}


struct ScrollTile : public Tile
{
};

struct ScrollList
{
    int unk00;
    int unk04;
    int unk08;
    ScrollTile* m_pHighlightedTile;
    int unk10;
    Tile* pItemCount;
    int unk18;
    int unk1c;
    float fTotalHeight;
    void FUN_007a7d80();
};
// Resets m_1c and m_20, then for each entry with flag 0 notifies its target with 0xfac and an incrementing count, calls Notify2, then Finish1 and Finish2.
// @fnv 0x007a78e0
void FUN_007a78e0_cls::ProcessEntries()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (EntryNode* pNode = this ? &m_kNode : 0; pNode != 0 && ((::EntryItem *)(new ((void *)(pNode)) ::Vec3())) != 0; pNode = ((::EntryNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))
    {
        if (((::EntryItem *)(new ((void *)(pNode)) ::Vec3()))->flag == 0)
        {
            reinterpret_cast<::Tile *>((((::EntryItem *)(new ((void *)(pNode)) ::Vec3()))->target))->Set(0xfac, m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::EntryItem *)(new ((void *)(pNode)) ::Vec3()))->target));
        }
    }
    reinterpret_cast<::ScrollList *>(this)->FUN_007a7d80();
    reinterpret_cast<::SelectionList *>(this)->UpdateSelectionState();
}
// Marks each item filtered by predicate, hides filtered tiles, renumbers visible ones, updates the filtered count and reselects a tile.
// @fnv 0x007a49e0
void FilterHost::ApplyObjectiveFilter(bool (*predicate)(BGSQuestObjective*))
{
    int filteredCount = 0;
    int selectedIndex = -1;
    static int numFilteredTrait = FUN_00a00940("_num_filtered", -1);
    count = 0;
    height = 0.0f;
    for (FilterNode* node = this; node && ((::FilterItem *)(new ((void *)(node)) ::Vec3())); node = ((::FilterNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        ((::FilterItem *)(new ((void *)(node)) ::Vec3()))->filtered = predicate && predicate(((::FilterItem *)(new ((void *)(node)) ::Vec3()))->object);
        if (((::FilterItem *)(new ((void *)(node)) ::Vec3()))->filtered)
        {
            if (((::FilterItem *)(new ((void *)(node)) ::Vec3()))->tile == selected)
            {
                selectedIndex = (int)reinterpret_cast<::TileListBoxCalls *>((((::FilterItem *)(new ((void *)(node)) ::Vec3()))->tile))->GetFloat(0xfac);
                selected = 0;
            }
            reinterpret_cast<::Tile *>((((FilterItemTile*)((::FilterItem *)(new ((void *)(node)) ::Vec3()))->tile)))->Set(0xfac, -1);
            filteredCount++;
        }
        else
        {
            if (selectedIndex >= 0 && count == selectedIndex)
                selected = ((::FilterItem *)(new ((void *)(node)) ::Vec3()))->tile;
            reinterpret_cast<::Tile *>((((FilterItemTile*)((::FilterItem *)(new ((void *)(node)) ::Vec3()))->tile)))->Set(0xfac, count++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::FilterItem *)(new ((void *)(node)) ::Vec3()))->tile));
        }
    }
    reinterpret_cast<::Tile *>((parent))->Set(numFilteredTrait, filteredCount);
    reinterpret_cast<::ScrollList *>(this)->FUN_007a7d80();
    if (!selected && selectedIndex >= 0)
        selected = v5(selectedIndex, false);
    if (!selected && selectedIndex >= 0)
        selected = ((::LBTile *)(reinterpret_cast<::S007a6280 *>(this)->FUN_007a6280()));
    reinterpret_cast<::SelectionList *>(this)->UpdateSelectionState();
}

// Computes a scroll delta from the tile's float value and total height, stores it on the tile, and sets the item count on pItemCount.
// @fnv 0x007a7d80
void ScrollList::FUN_007a7d80()
{
    if (m_pHighlightedTile)
    {
        float m_fGlyphExtent = reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(0xfb0);
        int iCount = 1;
        if (fTotalHeight > ::_DAT_01012060 && m_fGlyphExtent > ::_DAT_01012060)
        {
            if (fTotalHeight > m_fGlyphExtent)
            {
                iCount =
                    FUN_00647b70((int)FUN_004e4430(((unsigned int)(reinterpret_cast<::VATSMenu *>(this)->FUN_007a7830())) * (fTotalHeight - m_fGlyphExtent) / fTotalHeight) + 1, 2);
            }
            if (iCount > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((m_pHighlightedTile))->FUN_00a012d0(Tile::GetTraitID("_scroll_delta"), (fTotalHeight - m_fGlyphExtent) / (iCount - 1),
                                        true);
            }
        }
        if (pItemCount)
        {
            pItemCount->Set(Tile::GetTraitID("_number_of_items"), iCount);
        }
    }
}

struct FUN_006f48b0
{
    int d[14];
    FUN_006f48b0();
    ~FUN_006f48b0();
};
typedef FUN_006f48b0 D6200Obj;
// Builds a D6200Obj via BuildPathWithDoors; on success writes o.GetPathLength() to out and returns true, otherwise writes 0.0f and returns false.
// @fnv 0x006d6200
bool __cdecl GetObjectFloat(void* apFirst, void* apSecond, float* pfResult)
{
    D6200Obj o;
    if (::BuildPathWithDoors((::Location *)(apFirst), (::Location *)(apSecond), (::Result *)(::FUN_006f48b0 *)(&o), 0, 1))
    {
        *pfResult = reinterpret_cast<::fnv_006f49c0::FUN_006f49c0_shell *>(&(o))->GetPathLength();
        return true;
    }
    else
    {
        *pfResult = 0.0f;
        return false;
    }
}

namespace n79 {
struct Item
{
    virtual ~Item();
};
struct ItemList
{
    void FUN_0057c730(Item** pp);
};
struct Mgr
{
    int m_iWordAt00;
    ItemList m_kNode;
};
}
class Owner79
{
  public:
    char pad[0x84];
    n79::Mgr* m_84;
    void FUN_0079f6f0();
};
// Reads a mode, updates the player/map marker accordingly, resets the marker position, and repositions the marker element unless a condition holds.
// @fnv 0x00798840
void FUN_00798840()
{
    char cMode = ConsumeByteAtE4();
    switch (cMode)
    {
    case 0:
    case 3:
        reinterpret_cast<::PlayerMarkerOwner *>((((PlayerMarkerCalls*)::_g_thePlayer)))->PlaceMarker(DAT_011da368->m_kPlayerWorldPosition, (::MarkerFormStub *)(DAT_011da368->m_pCurrentMapSpace));
        if (cMode == 0)
            reinterpret_cast<::Owner79 *>((((MapMenuMarkerCalls*)DAT_011da368)))->FUN_0079f6f0();
        reinterpret_cast<::QuestMapMenu *>((((MapMenuMarkerCalls*)DAT_011da368)))->UpdateQuestMarker();
        break;
    case 1:
        reinterpret_cast<::FUN_00952f90_cls *>((((PlayerMarkerCalls*)::_g_thePlayer)))->ClearHelper();
        reinterpret_cast<::Owner79 *>((((MapMenuMarkerCalls*)DAT_011da368)))->FUN_0079f6f0();
        break;
    }
    DAT_011da368->m_kPlayerWorldPosition = NiPoint3::ZERO;
    DAT_011da368->m_pCurrentMapSpace = 0;
    if (!FUN_004b71d0())
    {
        reinterpret_cast<::FUN_00a012d0_t *>((DAT_011da368->m_pTiles[6]))->FUN_00a012d0(0xfa1,
                                       (float)(reinterpret_cast<::MyHack *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007697f0() -
                                               reinterpret_cast<::FUN_00a013d0_shell *>((((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((DAT_011da368->m_pTiles[6]))->FUN_0045cd60()))))->GetTotalFloat() -
                                               DAT_011da368->m_pTiles[6]->GetFloat(0xfb1) / 2.0),
                                       true);
        reinterpret_cast<::FUN_00a012d0_t *>((DAT_011da368->m_pTiles[6]))->FUN_00a012d0(0xfa2,
                                       (float)(reinterpret_cast<::S *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->GetScaledValue() -
                                               reinterpret_cast<::FUN_00a01440_shell *>((((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((DAT_011da368->m_pTiles[6]))->FUN_0045cd60()))))->GetAccumulatedFloat() -
                                               DAT_011da368->m_pTiles[6]->GetFloat(0xfb0) / 2.0),
                                       true);
    }
    DAT_011da368->m_pTiles[6]->Set(0xfa3, 1);
}
// @fnv 0x0079f6f0
void Owner79::FUN_0079f6f0()
{
    n79::Item* p = ((::n79::Item *)(reinterpret_cast<::TileFloatList *>((m_84))->FUN_00a03eb0(0x1c)));
    if (p)
    {
        m_84->m_kNode.FUN_0057c730(&p);
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>((p))->FUN_009ff690();
        delete p;
    }
    p = ((::n79::Item *)(reinterpret_cast<::TileFloatList *>((m_84))->FUN_00a03eb0(0x1e)));
    while (p)
    {
        m_84->m_kNode.FUN_0057c730(&p);
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>((p))->FUN_009ff690();
        delete p;
        p = ((::n79::Item *)(reinterpret_cast<::TileFloatList *>((m_84))->FUN_00a03eb0(0x1e)));
    }
}

struct ListBoxEnable
{
    virtual void vfn_00();
    int unk04;
    int unk08;
    Tile* pParentTile;
    void FUN_007a2350(bool bEnabled);
};

// Stores bEnabled into pParentTile under the _enabled trait key.
// @fnv 0x007a2350
void ListBoxEnable::FUN_007a2350(bool bEnabled)
{
    static int kListBoxEnabled = ::FUN_00a00940("_enabled", -1);
    pParentTile->Set(kListBoxEnabled, bEnabled);
}

struct FUN_007a3d20_tile;

struct FUN_007a3d20_item
{
    FUN_007a3d20_tile* tile;
    int object;
    unsigned char isFilteredOut;
};

struct FUN_007a3d20_node
{
    FUN_007a3d20_item* item;
    FUN_007a3d20_node* next;
};

struct FUN_007a3d20_tile
{
};

struct FUN_007a3d20_parent
{
};

int __cdecl FUN_00ec62c0();

struct FUN_007a3d20_cls
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual FUN_007a3d20_tile* vfn14(int, int);

    FUN_007a3d20_node list;
    FUN_007a3d20_parent* parentTile;
    FUN_007a3d20_tile* selected;
    FUN_007a3d20_tile* scrollBar;
    const char* templateName;
    unsigned short itemCount;
    float unk20;

    void FUN_007a3d20(bool (*pfnFilter)(int));
    FUN_007a3d20_tile* FUN_007a6250();
};

// @fnv 0x007a3d20
void FUN_007a3d20_cls::FUN_007a3d20(bool (*pfnFilter)(int))
{
    int count = 0;
    int selIdx = -1;
    static int numFiltered = FUN_00a00940("_num_filtered", -1);

    this->itemCount = 0;
    this->unk20 = 0.0f;

    for (FUN_007a3d20_node* node = this ? &this->list : 0; node != 0 && *((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())) != 0;
         node = ((::FUN_007a3d20_node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        (*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->isFilteredOut = (pfnFilter != 0 && pfnFilter((*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->object)) ? 1 : 0;

        if ((*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->isFilteredOut)
        {
            if ((*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->tile == this->selected)
            {
                reinterpret_cast<::TileListBoxCalls *>(((*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac);
                selIdx = FUN_00ec62c0();
                this->selected = 0;
            }
            reinterpret_cast<::Tile *>(((*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->tile))->Set(0xfac, -1);
            count++;
        }
        else
        {
            if (selIdx >= 0 && this->itemCount == selIdx)
                this->selected = (*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->tile;
            reinterpret_cast<::Tile *>(((*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->tile))->Set(0xfac, this->itemCount++);
            reinterpret_cast<::VLList *>((this))->AccumulateTileHeight((::VLTile *)((*((::FUN_007a3d20_item **)(new ((void *)(node)) ::Vec3())))->tile));
        }
    }

    reinterpret_cast<::Tile *>((this->parentTile))->Set(numFiltered, count);
    reinterpret_cast<::FUN_007a7700_Menu *>((this))->FUN_007a7700();
    if (this->selected == 0 && selIdx >= 0)
        this->selected = this->vfn14(selIdx, 0);
    if (this->selected == 0 && selIdx >= 0)
        this->selected = this->FUN_007a6250();
    reinterpret_cast<::fnv_007a73e0::HighlightList *>((this))->FUN_007a73e0();
}


class TileOwnerW
{
  public:
    void FUN_007a59a0(bool bValue);

    char m_pad00[0xc];
    Tile* m_pkTile;
};

// Caches the trait index for "_enabled" and sets that trait on m_pkTile to bValue.
// @fnv 0x007a59a0
void TileOwnerW::FUN_007a59a0(bool abEnabled)
{
    static int s_iTrait = FUN_00a00940("_enabled", -1);
    m_pkTile->Set(s_iTrait, abEnabled);
}

struct AQ
{
};
struct BQ
{
};
struct CQ
{
};
struct RQ
{
};
struct OwnQ
{
    virtual void v0(), v1(), v2(), v3(), v4();
    virtual void Notify(int a, int b);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80,
        unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0,
        unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc, unk100,
        unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    BQ kB130;
    int unk134, unk138, unk13c, unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    AQ kA160;
    int unk164, unk168, unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c, unk190, unk194, unk198,
        unk19c, unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    CQ kC1c0;
    void HandleEvent(int iEvent, RQ* pRef);
};
// Dispatches iEvent to call member methods, update fields, or notify when pRef and kC1c0 return equal values.
// @fnv 0x00799690
void OwnQ::HandleEvent(int iEvent, RQ* pRef)
{
    switch (iEvent)
    {
    case 14:
        reinterpret_cast<::MenuItem7A3 *>(&(kA160))->FUN_007a30e0(1);
        break;
    case 15:
        reinterpret_cast<::ListBoxEnable *>(&(kB130))->FUN_007a2350(1);
        reinterpret_cast<::FUN_007a4c50_shell *>(&(kC1c0))->SetEnabledTrait(0);
        break;
        break;
    case 24:
        if (FUN_004b71d0() || !unk90)
            unk94 = 0;
        break;
    case -1:
        if (pRef && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((pRef))->FUN_0045cd60())) == ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(kC1c0))->FUN_00825c00())))
            Notify(0xf, 0);
        break;
    }
}

namespace fnv_0079a660 {
struct AMPoint
{
    float x, y, z;
};

class AMSoundHandle
{
  public:
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    AMSoundHandle(const AMSoundHandle& kOther);
    ~AMSoundHandle();
                // IsPlaying
                 // duration in ms
      // Play
};

struct AMSoundNode
{
      // GetItem
        // GetNext
};

class AMPlayer
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
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual const AMPoint& GetPosition();  // +0x1f4
};

class AMAudio
{
  public:
};

void FUN_00705210(const char* pcSubtitle, AMSoundHandle kHandle, AMPoint kPos, AMPlayer* pkSpeaker, int iFlag);
int FUN_00a01860(const char* pcTrait);

struct AMTimer
{
};
extern unsigned int DAT_011da410;
struct AMStringSetting
{
};

class AMTile
{
  public:
};

struct AMSubtitleText
{
};
struct AMSubtitles
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

class AMMenuView
{
  public:
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
    AMTile* m_pkInfoTile;  // +0x5c
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
    AMSoundNode m_kSounds;  // +0x98
    int unk09c;
    int unk0a0;
    int unk0a4;
    AMSubtitles m_kSubtitles;  // +0xa8
    AMSoundNode* m_pkCurrent;  // +0xb8
    bool m_bLoading;           // +0xbc
    unsigned char unk0bd;
    unsigned short unk0be;
    float m_fSoundVolume;        // +0xc0
    unsigned int m_uiStartTime;  // +0xc4
    float m_fFadeDuration;       // +0xc8

    void UpdateHolotapePlayback();
};

// Updates holotape playback state, displays remaining time on the info tile, and advances to the next subtitle when the current audio node finishes.
// @fnv 0x0079a660
void AMMenuView::UpdateHolotapePlayback()
{
    char acText[64];
    if (m_bLoading)
    {
        bool bAllReady = true;
        bool bNonePlayingOld = true;
        int iTotalLoc = 0;
        int iCount = 0;
        for (AMSoundNode* pkNode = &m_kSounds; pkNode; pkNode = ((::fnv_0079a660::AMSoundNode *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkNode))->FUN_0084e3a0())))
        {
            if (reinterpret_cast<::SoundPlaybackHandle *>((((::fnv_0079a660::AMSoundHandle *)(new ((void *)(pkNode)) ::Vec3()))))->IsValid())
            {
                bNonePlayingOld = false;
                if (!m_pkCurrent)
                    m_pkCurrent = pkNode;
                if (!::FUN_00ad8b30((unsigned int *)(((::fnv_0079a660::AMSoundHandle *)(new ((void *)(pkNode)) ::Vec3())))))
                    bAllReady = false;
                else
                {
                    iTotalLoc += ::FUN_00ad8b30((unsigned int *)(((::fnv_0079a660::AMSoundHandle *)(new ((void *)(pkNode)) ::Vec3()))));
                    iCount++;
                }
            }
        }
        if (bNonePlayingOld)
        {
            reinterpret_cast<::FUN_00798ad0_shell *>(this)->StopHolotapeAudio();
            reinterpret_cast<::fnv_00ad7c00::FUN_00ad7c00 *>((((::fnv_0079a660::AMAudio *)(::FUN_00453a70()))))->Set(m_fFadeDuration);
        }
        else if (bAllReady)
        {
            m_bLoading = false;
            m_fSoundVolume = (iCount - 1) * 500 + iTotalLoc;
            reinterpret_cast<::FUN_00ad8830_shell *>((((::fnv_0079a660::AMSoundHandle *)(new ((void *)(m_pkCurrent)) ::Vec3()))))->FUN_00ad8830(false);
            m_uiStartTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0079a660::AMTimer *>(&::g_timeGlobal))))->FUN_00825c00();
            FUN_00705210(((const char *)(::FUN_00559450((int *)(((::fnv_0079a660::AMSubtitleText *)(reinterpret_cast<::S006950d0 *>(&(m_kSubtitles))->GetElement(0))))))), *((::fnv_0079a660::AMSoundHandle *)(new ((void *)(m_pkCurrent)) ::Vec3())),
                         (*reinterpret_cast<::fnv_0079a660::AMPlayer * *>(&::_g_thePlayer))->GetPosition(), (*reinterpret_cast<::fnv_0079a660::AMPlayer * *>(&::_g_thePlayer)), 0);
            reinterpret_cast<::FUN_007a1b10_shell *>(&(m_kSubtitles))->RemoveAt(0, 1);
        }
    }
    else if (m_fSoundVolume > 0.0)
    {
        float fTimeOffset = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0079a660::AMTimer *>(&::g_timeGlobal))))->FUN_00825c00() - m_uiStartTime;
        int iRemaining = 0;
        fTimeOffset = ::FUN_0040ebd0(fTimeOffset, m_fSoundVolume);
        iRemaining = (int)(m_fSoundVolume - fTimeOffset);
        ::FUN_00406d00(acText, 0x40, "%02d:%02d:%01d %s", iRemaining / 60000, iRemaining % 60000 / 1000,
                     iRemaining % 1000 / 100, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0079a660::AMStringSetting *>(&::g_011d3960))))->GetMenuTitle())));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pkInfoTile))->FUN_00a01350(FUN_00a01860("_ItemStringInfo"), (char *)(acText), 1);
        reinterpret_cast<::FUN_00a012d0_t *>((m_pkInfoTile))->FUN_00a012d0(FUN_00a01860("_AudioFileCompletion"), fTimeOffset / m_fSoundVolume, 1);
    }
    if (m_pkCurrent && !reinterpret_cast<::SoundPlaybackHandle *>((((::fnv_0079a660::AMSoundHandle *)(new ((void *)(m_pkCurrent)) ::Vec3()))))->IsValid())
    {
        if (!DAT_011da410)
            DAT_011da410 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0079a660::AMTimer *>(&::g_timeGlobal))))->FUN_00825c00();
        if (((::fnv_0079a660::AMSoundNode *)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pkCurrent))->FUN_0084e3a0())) && reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_0079a660::AMTimer *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011da410 > 500)
        {
            m_pkCurrent = ((::fnv_0079a660::AMSoundNode *)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pkCurrent))->FUN_0084e3a0()));
            reinterpret_cast<::FUN_00ad8830_shell *>((((::fnv_0079a660::AMSoundHandle *)(new ((void *)(m_pkCurrent)) ::Vec3()))))->FUN_00ad8830(false);
            DAT_011da410 = 0;
            FUN_00705210(((const char *)(::FUN_00559450((int *)(((::fnv_0079a660::AMSubtitleText *)(reinterpret_cast<::S006950d0 *>(&(m_kSubtitles))->GetElement(0))))))), *((::fnv_0079a660::AMSoundHandle *)(new ((void *)(m_pkCurrent)) ::Vec3())),
                         (*reinterpret_cast<::fnv_0079a660::AMPlayer * *>(&::_g_thePlayer))->GetPosition(), (*reinterpret_cast<::fnv_0079a660::AMPlayer * *>(&::_g_thePlayer)), 1);
            reinterpret_cast<::FUN_007a1b10_shell *>(&(m_kSubtitles))->RemoveAt(0, 1);
        }
        else if (!((::fnv_0079a660::AMSoundNode *)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pkCurrent))->FUN_0084e3a0())))
        {
            ::FUN_00406d00(acText, 0x40, "00:00:0 %s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0079a660::AMStringSetting *>(&::g_011d3960))))->GetMenuTitle())));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pkInfoTile))->FUN_00a01350(FUN_00a01860("_ItemStringInfo"), (char *)(acText), 1);
            reinterpret_cast<::FUN_00a012d0_t *>((m_pkInfoTile))->FUN_00a012d0(FUN_00a01860("_AudioFileCompletion"), 1.0f, 1);
            reinterpret_cast<::Tile *>((m_pkInfoTile))->Set(0x1004, 0);
            reinterpret_cast<::FUN_00798ad0_shell *>(this)->StopHolotapeAudio();
        }
    }
}
}  // namespace fnv_0079a660


struct PipboyLookup_host
{
    int Query();
};

struct FUN_0079c5a0_host
{
};

struct FUN_0079c530_cls
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
    int m_i80;
    void FUN_0079c530(int a1, int a2);
};

// If m_i80 is 0x20 or 0x21, pushes a flag based on PipboyLookup Query divided by 0x78 compared to DAT_01012060, with value DAT_01056528.
// @fnv 0x0079c530
void FUN_0079c530_cls::FUN_0079c530(int aiUnused, int a2)
{
    if (m_i80 == 0x21 || m_i80 == 0x20)
    {
        reinterpret_cast<::ZoomMenu *>((reinterpret_cast<FUN_0079c5a0_host*>(this)))->FUN_0079c5a0(
            (double)(((int)(reinterpret_cast<::FUN_0070ec70_class *>((reinterpret_cast<PipboyLookup_host*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0070ec70())) / 0x78) > ::_DAT_01012060,
            ::runtimeFloatSettingDefault1085);
    }
}

namespace fnv_0079cdb0 {
struct MMMapData
{
    int iWidth;   // +0x00
    int iHeight;  // +0x04
    short sMinX;  // +0x08
    short sMinY;  // +0x0a
    short sMaxX;  // +0x0c
    short sMaxY;  // +0x0e
};

class MMTile
{
  public:
};

struct MMRefNode;
class MMWorld : public TESWorldSpace
{
  public:
};

struct MMWorldNode
{
};
struct MMWorldList
{
};

class MMRef;
struct MMRefNode
{
    ~MMRefNode();
};

struct MMParent
{
};
struct MMLocationName
{
};
struct MMMarkerData
{
    MMLocationName* FUN_0044edb0();
};

class MMRef
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
    virtual const NiPoint3& GetPos();  // +0x1f4
    MMParent* FUN_00575d70();
};

struct MMRefList
{
};

class MMMenu
{
  public:
    int unk000[14];
    MMTile* m_pkMapTile;  // +0x38
    int unk03c[39];
    MMRefList m_kMarkers;  // +0xd8
    int unk0dc[3];
    NiPoint2 m_kNWCorner;  // +0xe8
    NiPoint2 m_kSECorner;  // +0xf0
    int unk0f8[4];
    MMWorld* m_pkMapSpace;     // +0x108
    MMWorld* m_pkRootSpace;    // +0x10c
    bool m_bRootSpaceChanged;  // +0x110
    char unk111[3];
    int unk114;
    int unk118;
    void* m_pkNorthCell;  // +0x11c

    void RefreshMap();
};

struct MMPoint2
{
    float x, y;
    MMPoint2(float fX, float fY);
};

extern unsigned int DAT_011da370;
extern const char* DAT_011a0404[];

// Ensures root space and map data, updates tile dimensions, and populates marker list from root space references.
// @fnv 0x0079cdb0
void MMMenu::RefreshMap()
{
    MMMapData* pkData = m_pkRootSpace ? ((::fnv_0079cdb0::MMMapData *)(reinterpret_cast<::FUN_00586400_shell *>((m_pkRootSpace))->FUN_00586400())) : 0;
    if (!m_pkRootSpace || !pkData || !pkData->iWidth || !pkData->iHeight)
    {
        m_pkRootSpace = (MMWorld*)dynamic_cast<TESWorldSpace*>(::FUN_004839c0(0x3c));
        pkData = m_pkRootSpace ? ((::fnv_0079cdb0::MMMapData *)(reinterpret_cast<::FUN_00586400_shell *>((m_pkRootSpace))->FUN_00586400())) : 0;
        m_bRootSpaceChanged = true;
    }
    if (!m_pkRootSpace || !pkData || !pkData->iWidth || !pkData->iHeight)
    {
        m_pkRootSpace = *((::fnv_0079cdb0::MMWorld **)(new ((void *)(((::fnv_0079cdb0::MMWorldNode *)(::FUN_00460140((int)((*reinterpret_cast<::fnv_0079cdb0::MMWorldList * *>(&::g_dataHandler)))))))) ::Vec3()));
        pkData = m_pkRootSpace ? ((::fnv_0079cdb0::MMMapData *)(reinterpret_cast<::FUN_00586400_shell *>((m_pkRootSpace))->FUN_00586400())) : 0;
        m_bRootSpaceChanged = true;
    }
    m_pkMapSpace = m_pkRootSpace;
    m_pkNorthCell = 0;
    if (m_pkRootSpace && pkData)
    {
        if (DAT_011da36c || m_bRootSpaceChanged)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pkMapTile))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::FUN_00586440_shell *>((m_pkRootSpace))->FUN_00586440()), 1);
            reinterpret_cast<::Tile *>((m_pkMapTile))->Set(0xfcd, pkData->iWidth);
            reinterpret_cast<::Tile *>((m_pkMapTile))->Set(0xfce, pkData->iHeight);
            DAT_011da36c = false;
            m_bRootSpaceChanged = false;
        }
        reinterpret_cast<::ZoomMenu *>(this)->FUN_0079c5a0(1, 1.0f);
        *(MMPoint2*)&m_kNWCorner = MMPoint2(pkData->sMinX << 12, (pkData->sMinY << 12) + 0x1000);
        *(MMPoint2*)&m_kSECorner = MMPoint2((pkData->sMaxX << 12) + 0x1000, pkData->sMaxY << 12);
        if (!((::fnv_0079cdb0::MMTile *)(reinterpret_cast<::TileFloatList *>((m_pkMapTile))->FUN_00a03eb0(0x1a))))
        {
            MMRefNode* pkList = ((::fnv_0079cdb0::MMRefNode *)(reinterpret_cast<::FNVEmitter *>((m_pkRootSpace))->GetOrCreateElement(0)));
            DAT_011da370 = 0;
            for (MMRefNode* pkIter = pkList; pkIter && *((::fnv_0079cdb0::MMRef **)(new ((void *)(pkIter)) ::Vec3())); pkIter = ((::fnv_0079cdb0::MMRefNode *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070())))
            {
                MMRef* pkRef = *((::fnv_0079cdb0::MMRef **)(new ((void *)(pkIter)) ::Vec3()));
                NiPoint3 kPos = pkRef->GetPos();
                MMParent* pkSpace = ((::fnv_0079cdb0::MMParent *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pkRef))->FUN_00575d70()));
                while (pkSpace && ((::fnv_0079cdb0::MMParent *)(reinterpret_cast<::FUN_004fd380_shell *>((pkSpace))->FUN_004fd380())))
                    pkSpace = ((::fnv_0079cdb0::MMParent *)(reinterpret_cast<::FUN_004fd380_shell *>((pkSpace))->FUN_004fd380()));
                if (!reinterpret_cast<::MapMarkerData *>((((::fnv_0079cdb0::MMMarkerData *)(reinterpret_cast<::FUN_00569060_shell *>((pkRef))->FUN_00569060()))))->GetVisible() || reinterpret_cast<::TESForm *>((pkRef))->GetDisabled())
                    continue;
                if (pkSpace != (MMParent*)m_pkRootSpace)
                    continue;
                MMTile* pkMarkerEntry = ((::fnv_0079cdb0::MMTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MMMenu*)DAT_011da368)))->FUN_00a1ddb0((::Tile *)(m_pkMapTile), (char *)("MapMarkerTemplate"), (::Tile *)(0))));
                if (pkMarkerEntry)
                {
                    char acText[256];
                    NiPoint3 kMapPos = (*(::NiPoint3 *)(reinterpret_cast<::FUN_0079c380_shell *>(this)->GetMarkerPosition((*(::NiPoint3 * *)&(const ::NiPoint3 &)(kPos)), (::NiPoint3)(((::fnv_0079cdb0::MMParent *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pkRef))->FUN_00575d70()))), {})));
                    MMLocationName* pkName = ((::fnv_0079cdb0::MMMarkerData *)(reinterpret_cast<::FUN_00569060_shell *>((pkRef))->FUN_00569060()))->FUN_0044edb0();
                    if (pkName)
                    {
                        ::FUN_00406d00(acText, 0x100, "%s\n(%s)", reinterpret_cast<::StringHolder *>((((::fnv_0079cdb0::MMMarkerData *)(reinterpret_cast<::FUN_00569060_shell *>((pkRef))->FUN_00569060()))))->FUN_00438eb0(),
                                     reinterpret_cast<::TESReputation *>((pkName))->FUN_00616710());
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pkMarkerEntry))->FUN_00a01350(::FUN_00a00940("_LocationName", -1), (char *)(acText), 1);
                    }
                    else
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pkMarkerEntry))->FUN_00a01350(::FUN_00a00940("_LocationName", -1),
                                                    (char *)(reinterpret_cast<::StringHolder *>((((::fnv_0079cdb0::MMMarkerData *)(reinterpret_cast<::FUN_00569060_shell *>((pkRef))->FUN_00569060()))))->FUN_00438eb0()), 1);
                    reinterpret_cast<::Tile *>((pkMarkerEntry))->SetName(reinterpret_cast<::StringHolder *>((((::fnv_0079cdb0::MMMarkerData *)(reinterpret_cast<::FUN_00569060_shell *>((pkRef))->FUN_00569060()))))->FUN_00438eb0());
                    reinterpret_cast<::Tile *>((pkMarkerEntry))->Set(0xfaa, 0x1a);
                    reinterpret_cast<::FUN_00a012d0_t *>((pkMarkerEntry))->FUN_00a012d0(DAT_011da350, kMapPos.x, 1);
                    reinterpret_cast<::FUN_00a012d0_t *>((pkMarkerEntry))->FUN_00a012d0(DAT_011da34c, kMapPos.y, 1);
                    if (reinterpret_cast<::MapMarkerData *>((((::fnv_0079cdb0::MMMarkerData *)(reinterpret_cast<::FUN_00569060_shell *>((pkRef))->FUN_00569060()))))->IsTravelLocation())
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pkMarkerEntry))->FUN_00a01350(0xfcc, (char *)(DAT_011a0404[((int)(reinterpret_cast<::FUN_00438f30_Class *>((((::fnv_0079cdb0::MMMarkerData *)(reinterpret_cast<::FUN_00569060_shell *>((pkRef))->FUN_00569060()))))->FUN_00438f30()))]), 1);
                    else
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pkMarkerEntry))->FUN_00a01350(0xfcc, (char *)("Interface\\Icons\\World Map\\icon_map_undiscovered.dds"), 1);
                        reinterpret_cast<::Tile *>((pkMarkerEntry))->Set(0x1004, 0);
                    }
                    reinterpret_cast<::Tile *>((pkMarkerEntry))->Set(::FUN_00a00940("_MarkerIndex", -1), DAT_011da370);
                    reinterpret_cast<::Callees *>(&(m_kMarkers))->FUN_00905820(&pkRef);
                    DAT_011da370++;
                }
            }
            reinterpret_cast<::FileMatchList *>((pkList))->RemoveAll();
            delete pkList;
        }
        reinterpret_cast<::MapMarkerUpdate::Menu *>(this)->FUN_0079dbb0();
    }
}
}  // namespace fnv_0079cdb0

namespace fnv_007993d0 {
struct NoteTextSource
{
    virtual void unused00();
    virtual void unused04();
    virtual void unused08();
    virtual void unused0c();
    virtual const char* GetText(BGSNote*, unsigned int);
};
struct NoteTexture
{
};
struct NoteInput
{
};
struct NoteTile
{
    void SetTraitAndReset(int, float);
};
struct NoteExtent
{
    float x, y, z;
};
struct NoteFont
{
    NoteExtent* FUN_00a1b020(NoteExtent*, const char*, int, float, int);
};
int FUN_00a01860(const char*);
struct NoteSetting
{
};
struct NoteMenu
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
    NoteTile* noteTile;
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
    void SetNote(NoteInput*);
};
// Populates the note menu's data tile with text, image, or time-string content based on the note type, and configures the scrollbar for text overflow.
// @fnv 0x007993d0
void NoteMenu::SetNote(NoteInput* note)
{
    float textHeight2;
    NoteTile* textTile2;
    float scrollDelta;
    NoteTile* scrollbar2;
    float overflow3;
    NoteExtent extent4;
    char timeText2[64];
    switch (reinterpret_cast<::FUN_005e8d40_shell *>((note))->GetNoteType())
    {
    case 1:
        textTile2 = ((::fnv_007993d0::NoteTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((noteTile))->FUN_00a03da0((char *)("MM_DataText"))));
        scrollbar2 = ((::fnv_007993d0::NoteTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((noteTile))->FUN_00a03da0((char *)("MM_TextScrollbar"))));
        scrollDelta = reinterpret_cast<::TileListBoxCalls *>((scrollbar2))->GetFloat(FUN_00a01860("_ScrollDelta"));
        overflow3 = 0.0f;
        reinterpret_cast<::Tile *>((noteTile))->Set(FUN_00a01860("_ItemType"), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((textTile2))->FUN_00a01350(0xfc4, (char *)(((::fnv_007993d0::NoteTextSource *)(reinterpret_cast<::BGSNote *>((note))->GetNoteDescription()))->GetText((BGSNote*)note, 0x4d414e54)), true);
        textHeight2 =
            ((::fnv_007993d0::NoteFont *)(::FontManager::Instance()))
                ->FUN_00a1b020(&extent4, ((::fnv_007993d0::NoteTextSource *)(reinterpret_cast<::BGSNote *>((note))->GetNoteDescription()))->GetText((BGSNote*)note, 0x4d414e54), 1, 400.0f, 0)
                ->y;
        overflow3 = textHeight2 - reinterpret_cast<::TileListBoxCalls *>((((::fnv_007993d0::NoteTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((textTile2))->FUN_0045cd60()))))->GetFloat(0xfb0);
        overflow3 = ::FUN_00404010(0.0f, overflow3);
        reinterpret_cast<::FUN_00a012d0_t *>((scrollbar2))->FUN_00a012d0(FUN_00a01860("_number_of_items"), ::FUN_004e4430(overflow3 / scrollDelta) + 1.0, true);
        reinterpret_cast<::FUN_00a012d0_t *>((scrollbar2))->FUN_00a012d0(FUN_00a01860("_current_value"), 0.0f, false);
        reinterpret_cast<::FUN_00a01290_shell *>((scrollbar2))->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
        break;
    case 2:
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::fnv_007993d0::NoteTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((noteTile))->FUN_00a03da0((char *)("MM_DataImage"))))))->FUN_00a01350(0xfcc, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::fnv_007993d0::NoteTexture *)(reinterpret_cast<::BGSNote *>((note))->GetNoteTexture()))))->FUN_00408da0()))), true);
        reinterpret_cast<::Tile *>((noteTile))->Set(FUN_00a01860("_ItemType"), 2);
        break;
    case 0:
    case 3:
        reinterpret_cast<::Tile *>((noteTile))->Set(FUN_00a01860("_ItemType"), 3);
        if (!unkb8)
        {
            sprintf_s(timeText2, 64, "--:--:- %s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007993d0::NoteSetting *>(&::g_011d3960))))->GetMenuTitle())));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((noteTile))->FUN_00a01350(FUN_00a01860("_ItemStringInfo"), (char *)(timeText2), true);
            reinterpret_cast<::FUN_00a012d0_t *>((noteTile))->FUN_00a012d0(FUN_00a01860("_AudioFileCompletion"), 0.0f, true);
        }
        break;
    }
    reinterpret_cast<::Tile *>((noteTile))->Set(0xfa3, 1);
}
}  // namespace fnv_007993d0

struct TraitValue
{
};

struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0c;
    HighlightTile* unk10;
    void UpdateHighlight_007a8260();
};
// Applies filter to each item, marks filtered items, updates selection and counts, then refreshes and finishes the list.
// @fnv 0x007a5730
void FUN_007a5730_shell::FUN_007a5730(bool (*filter)(TESChallenge*))
{
    int filteredCount = 0;
    int selIdx = -1;
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    ((FUN_007a5730_self*)this)->count = 0;
    ((FUN_007a5730_self*)this)->scroll = 0.0f;
    FUN_007a5730_node* node = this ? (FUN_007a5730_node*)((char*)this + 4) : 0;
    for (; node && *((::FNVEmitter **)(new ((void *)(node)) ::Vec3())); node = ((::FUN_007a5730_node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        ((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->filtered =
            (filter && filter((TESChallenge*)((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->object)) ? 1 : 0;
        if (((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->filtered)
        {
            if (((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->tile == ((FUN_007a5730_self*)this)->selected)
            {
                reinterpret_cast<::TileListBoxCalls *>((((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac);
                selIdx = Stamp();
                ((FUN_007a5730_self*)this)->selected = 0;
            }
            reinterpret_cast<::Tile *>((((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->tile))->Set(0xfac, -1);
            filteredCount++;
        }
        else
        {
            if (selIdx >= 0 && ((FUN_007a5730_self*)this)->count == selIdx)
                ((FUN_007a5730_self*)this)->selected = ((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->tile;
            reinterpret_cast<::Tile *>((((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->tile))->Set(0xfac, ((FUN_007a5730_self*)this)->count++);
            reinterpret_cast<::VLList *>((((FUN_007a5730_self*)this)))->AccumulateTileHeight((::VLTile *)(((FUN_007a5730_item*)*((::FNVEmitter **)(new ((void *)(node)) ::Vec3())))->tile));
        }
    }
    reinterpret_cast<::Tile *>((((FUN_007a5730_self*)this)->parentTile))->Set(numFiltered, filteredCount);
    reinterpret_cast<::ListScrollHost *>((((FUN_007a5730_self*)this)))->FUN_007a8580();
    if (((FUN_007a5730_self*)this)->selected == 0 && selIdx >= 0)
        ((FUN_007a5730_self*)this)->selected = ((FUN_007a5730_self*)this)->vfn_14(selIdx, false);
    if (((FUN_007a5730_self*)this)->selected == 0 && selIdx >= 0)
        ((FUN_007a5730_self*)this)->selected = ((FUN_007a5730_self*)this)->Pick();
    reinterpret_cast<::HighlightList *>((((FUN_007a5730_self*)this)))->UpdateHighlight_007a8260();
}
// Sets two traits on unk0c and applies the speech challenge failure flag to the named highlight box and its edges.
// @fnv 0x007a8260
void HighlightList::UpdateHighlight_007a8260()
{
    static int highlightY = FUN_00a00940("_highlight_y", -1);
    static int selectedHeight = FUN_00a00940("_selected_height", -1);
    if (unk0c)
    {
        if (unk10)
        {
            TraitValue* valueHeight = (TraitValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((unk0c))->FUN_00a00f30(highlightY)));
            TraitValue* valueY = (TraitValue*)((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((unk0c))->FUN_00a00f30(selectedHeight)));
            reinterpret_cast<::AGOwner *>((valueHeight))->FUN_00a09130(2000, unk10, 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((valueHeight))->FUN_00a09410(false);
            reinterpret_cast<::AGOwner *>((valueY))->FUN_00a09130(2000, unk10, 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((valueY))->FUN_00a09410(false);
            if (reinterpret_cast<::Tile *>((unk10))->GetSpeechChallengeFailure())
            {
                HighlightTile* box = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(unk0c), "lb_highlight_box")));
                if (box)
                {
                    HighlightTile* edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("top"))));
                    if (edge)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((box))->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* box = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(unk0c), "lb_highlight_box")));
                if (box)
                {
                    HighlightTile* edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("top"))));
                    if (edge)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((box))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            unk0c->Set(highlightY, -1);
            unk0c->Set(selectedHeight, 0);
        }
    }
}

namespace fnv_00798cb0 {
extern int DAT_011da400;
extern char str_010739a0[];
extern int FUN_00a01860(const char*);
struct SelectedIndex
{
};
struct QuestSelection
{
};
struct MapEnterNoteSelection : ListBox<BGSNote*>
{
};
struct MapEnterObjectiveSelection : ListBox<BGSQuestObjective*>
{
};
struct Burst
{
    void FUN_007f8610(int, float, float, int);
};
struct Proxy
{
    Burst* FUN_00704370();
};
struct ClickVtable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(int, Tile*);
};
struct Reconstruction798cb0 : MapMenu
{
    void FUN_00798cb0(int, Tile*);
};
// Handles codes 23–25 for list selections and updates the selected index, with additional handling for codes 14, 15, and -1.
// @fnv 0x00798cb0
void Reconstruction798cb0::FUN_00798cb0(int aiEventCode, Tile* tile)
{
    int index = 0;
    BGSNote* challenge;
    TESChallenge* note;
    switch (aiEventCode)
    {
    case 23:
        if (tile)
        {
            m_pSelectedQuest = ((::TESQuest *)(reinterpret_cast<::LBList *>(&(m_kQuestListBox))->FindItemData(tile)));
            reinterpret_cast<::FilterHost *>(&(m_kObjectiveListBox))->ApplyObjectiveFilter((bool (*)(BGSQuestObjective*))((void (&)(Tile *, BGSQuestObjective *))::FUN_0079bc50));
            index = tile ? (int)tile->GetFloat(0xfac) : 0;
            m_pTiles[13]->Set(Tile::GetTraitID(str_010739a0), 4);
            m_pTiles[13]->Set(0xfa3, 1);
            m_pSelectedMapMarkerInfo = 0;
            reinterpret_cast<::LBList_7314c0 *>(&(m_kObjectiveListBox))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(Tile *, BGSQuestObjective *))::FUN_00799100)), 0, 0x7fffffff);
            m_pTiles[12]->Set(0xfaf, m_pSelectedMapMarkerInfo != 0);
            m_pTiles[11]->Set(0xfaf, m_pSelectedQuest && !reinterpret_cast<::FUN_0059e400_shell *>((m_pSelectedQuest))->FUN_0059e400() ? 1 : 0);
        }
        break;
    case 24:
        if (!DAT_011da36d)
        {
            challenge = ((::BGSNote *)(reinterpret_cast<::LBList *>(&(m_kNoteListBox))->FindItemData(tile)));
            index = m_kNoteListBox.GetSelectedTile() ? (int)m_kNoteListBox.GetSelectedTile()->GetFloat(0xfac) : 0;
            if (FUN_004b71d0() || (challenge && !m_pSelectedNote))
                reinterpret_cast<::fnv_007993d0::NoteMenu *>(this)->SetNote((::fnv_007993d0::NoteInput *)(challenge));
            if (!reinterpret_cast<::FUN_005e8d40_shell *>((challenge))->GetNoteType() || reinterpret_cast<::FUN_005e8d40_shell *>((challenge))->GetNoteType() == 3)
            {
                m_pTiles[13]->Set(0x1004, challenge == m_pSelectedNote && m_pkActiveSoundList ? 1 : 0);
            }
            else if (!((bool)(reinterpret_cast<::FUN_00798420_shell *>((challenge))->GetUnk7d())))
            {
                m_uiMapState = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
            }
        }
        else
        {
            note = ((::TESChallenge *)(reinterpret_cast<::LBList *>(&(m_kChallengeListBox))->FindItemData(tile)));
            if (FUN_004b71d0() || note)
                reinterpret_cast<::MapMenu_Shell *>(this)->UpdateChallengeText(note);
            m_pTiles[13]->Set(0xfa3, 1);
            ::FUN_00706f30(4);
        }
        break;
    case 25:
        index = m_kMapMarkerListBox.GetSelectedTile() ? (int)m_kMapMarkerListBox.GetSelectedTile()->GetFloat(0xfac) : 0;
        break;
    case 14:
        reinterpret_cast<::MenuItem7A3 *>((((MapEnterNoteSelection*)&m_kNoteListBox)))->FUN_007a30e0(false);
        break;
    case 15:
        reinterpret_cast<::ListBoxEnable *>((((QuestSelection*)&m_kQuestListBox)))->FUN_007a2350(false);
        reinterpret_cast<::FUN_007a4c50_shell *>((((MapEnterObjectiveSelection*)&m_kObjectiveListBox)))->SetEnabledTrait(true);
        break;
    case -1:
        if (tile && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((SelectedIndex*)tile)))->FUN_0045cd60())) == reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((TimeGlobal*)&m_kObjectiveListBox)))->FUN_00825c00())
            ((ClickVtable*)this)->v10(15, 0);
        break;
    }
    if (DAT_011da400 != index && (aiEventCode == 23 || aiEventCode == 24 || aiEventCode == 25))
    {
        ((::fnv_00798cb0::Burst *)(reinterpret_cast<::Interface *>((((Proxy*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->GetPipboyManager()))
            ->FUN_007f8610(0, DAT_011da400 < index ? ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db2f0))))))->f : -((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db2f0))))))->f,
                           ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db358))))))->f, 1);
        DAT_011da400 = index;
    }
}
}  // namespace fnv_00798cb0
