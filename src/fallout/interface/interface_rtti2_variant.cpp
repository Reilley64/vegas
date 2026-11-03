// src/fallout/interface/interface_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Menu). The skeleton of src/fallout/interface/interface.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00706d90_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_007dd090__StatsMenuImpl.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004ee000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00772000.h"
#include "fnv/symbols_0077f000.h"
#include "fnv/symbols_00788000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "interface_rebase_packet.h"
class TESWorldSpace;
class Menu;
class TESForm;
class TESObjectREFR;
class NiControllerSequence;
class BSSystemUtility
{
  public:
    static int s_iUpdateEnabled;
};
class Interface
{
  public:
    static const char* GetInterfaceName();
    static float GetFirstInterfaceFloat();
    static float UpdateInterfaceState();
    static float GetThirdInterfaceFloat();
    static float GetFourthInterfaceFloat();
    static bool IsInterfaceOpen();
    static float GetInterfaceFloat();
    static Tile* GetPrimaryInterfaceTile();
    static Tile* GetSecondaryInterfaceTile();
    static NiNode* GetInterfaceNode();
    static bool IsAnyMenuOpen();

    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
    static bool IsInterfaceActive();

    enum enumMenus
    {
        eNoMenu = 0,
        eMainFour = 1,
        eOtherRoot = 2,
        eConsoleMenu = 3,
        eFirstMenu = 1001,
        eMessageMenu = 1001,
        eInventoryMenu = 1002,
        eStatsMenu = 1003,
        eHUDMainMenu = 1004,
        eLoadingMenu = 1007,
        eContainerMenu = 1008,
        eDialogMenu = 1009,
        eSleepWaitMenu = 1012,
        eStartMenu = 1013,
        eLockPickMenu = 1014,
        eQuantityMenu = 1016,
        eAudioMenu = 1017,
        eVideoMenu = 1018,
        eGameplayMenu = 1020,
        eMapMenu = 1023,
        eBookMenu = 1026,
        eLevelUpMenu = 1027,
        eBirthSignMenu = 1029,
        eRepairMenu = 1035,
        eRaceSexMenu = 1036,
        eCreditsMenu = 1047,
        eCharGenMenu = 1048,
        eTextEditMenu = 1051,
        eBarterMenu = 1053,
        eSurgeryMenu = 1054,
        eHackingMenu = 1055,
        eVATSMenu = 1056,
        eComputersMenu = 1057,
        eRepairServicesMenu = 1058,
        eTutorialMenu = 1059,
        eSPECIALBookMenu = 1060,
        eItemModMenu = 1061,
        eLoveTesterMenu = 1074,
        eCompanionWheelMenu = 1075,
        eTraitSelectMenu = 1076,
        eRecipeMenu = 1077,
        eSlotMachineMenu = 1080,
        eBlackJackMenu = 1081,
        eRouletteMenu = 1082,
        eCaravanMenu = 1083,
        eTraitMenu = 1084,
        eLastMenu = 1084
    };
    static void Init(bool);
    static void RefreshInterfaceState();
    static void SetQuestTarget(TESForm*, bool);
    static bool IsPipBoyOpen();
    static bool GetStatsMenuVisible();
    static bool IsGamePaused();
    static bool ContainerIsRecipe();
    static bool ContainerIsBarter();
    static void SetLookAtReference(TESObjectREFR*);
    static bool PlayNifSounds(NiControllerSequence*);
    static Menu* GetMenuById(int);
    static void SetHUDVisible(bool);
    static void SetTileFormattedText(Tile*, int, const char*, ...);
};
#include "interface_rebase_closure_rtti2_interface.h"
const char kMeshesFolder[] = "Meshes";
unsigned int FUN_00702440();

__if_not_exists(::StatsMenu::IsMenuVisible)
{
    class StatsMenu : public ::Menu
    {
    public:
    void UpdateActorValueTiles();
};
}
struct StatsMenuCalls704e10
{
};

struct MenuLookup704
{
};

struct InterfaceGate704
{
  public:
};
bool __cdecl FUN_00702680(int, int);

// @fnv 0x00704e10
void __cdecl FUN_00704e10(int id)
{
    if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())) && reinterpret_cast<::FUN_009373f0_shell *>((((InterfaceGate704*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_009373f0())
    {
        bool b = FUN_00702680(0x3eb, 0xb);
        if (b)
        {
            ::Menu* menu = ((::Menu *)(::FUN_00a09030(0x3eb)));
            ::StatsMenu* result = menu ? dynamic_cast< ::StatsMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((((MenuLookup704*)menu)))->FUN_00a03c90()) : 0;
            if (result)
            {
                if (id == 0x4d)
                {
                    reinterpret_cast<::StatsMenu *>((reinterpret_cast<StatsMenuCalls704e10*>(result)))->UpdateActorValueTiles();
                }
                else
                {
                    reinterpret_cast<::fnv_007dd090::StatsMenuImpl *>((reinterpret_cast<StatsMenuCalls704e10*>(result)))->UpdateStatEntry(id);
                }
            }
        }
    }
}
