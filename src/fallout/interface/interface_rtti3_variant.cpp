// src/fallout/interface/interface_rtti3_variant.cpp - RTTI variant unit built 2026-11-01 from TODAY's src/fallout/interface/interface.cpp (skeleton; namespace blocks of integrated candidates out) with
// Menu, VATSMenu polymorphic, so dynamic_cast on them compiles next to the file's own names (0x00705780).


#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AlphaInterface.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellHandleProvider.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/Description.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_00457ba0_class.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00460fb0_class.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004bd570_this.h"
#include "fnv/decl/FUN_004bd740_stand.h"
#include "fnv/decl/FUN_004bd820_stand.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fe160_cls.h"
#include "fnv/decl/FUN_00514450_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00529ea0_shell.h"
#include "fnv/decl/FUN_0054dcf0_shell.h"
#include "fnv/decl/FUN_00555bc0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00717600_shell.h"
#include "fnv/decl/FUN_007a1400_class.h"
#include "fnv/decl/FUN_007a1430_Class.h"
#include "fnv/decl/FUN_007a1450_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0087f6c0_Class.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a087d0_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1db20_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/FaderManager.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/Holder007ab9a0.h"
#include "fnv/decl/InputPoller.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeValueShell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/MapView.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/PackageEx.h"
#include "fnv/decl/RecursiveSpinLock.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/StatsMenu.h"
#include "fnv/decl/SubtitleHUD.h"
#include "fnv/decl/SystemColorManager.h"
#include "fnv/decl/TESBipedModelForm.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TESObjectCELL_Ext.h"
#include "fnv/decl/TESObjectWEAP.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESWeightForm.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Target556ef0.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TileShaderProperty.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00439390__NiObjectNET.h"
#include "fnv/decl/fnv_004431f0__p07__DelStandIn.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_00503a70__AmmoEffectList503.h"
#include "fnv/decl/fnv_0054e750__FUN_0054e750Class.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575d10__FUN_00575d10_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00714d90__FUN_00714d90_shell.h"
#include "fnv/decl/fnv_00714fd0__FUN_00714fd0_shell.h"
#include "fnv/decl/fnv_00716320__FUN_00716320_shell.h"
#include "fnv/decl/fnv_007181d0__FUN_007181d0_shell.h"
#include "fnv/decl/fnv_007187a0__TutorialState.h"
#include "fnv/decl/fnv_0075c280__InventoryMenu.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_007dcc80__FUN_007dcc80_StandIn.h"
#include "fnv/decl/fnv_007f8a80__FOPipboyManagerPC.h"
#include "fnv/decl/fnv_009ed0d0__SelfQ.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_004d1000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004de000.h"
#include "fnv/symbols_004ee000.h"
#include "fnv/symbols_00556000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00663000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_00754000.h"
#include "fnv/symbols_00757000.h"
#include "fnv/symbols_0075b000.h"
#include "fnv/symbols_00771000.h"
#include "fnv/symbols_00772000.h"
#include "fnv/symbols_00773000.h"
#include "fnv/symbols_0077f000.h"
#include "fnv/symbols_00782000.h"
#include "fnv/symbols_00784000.h"
#include "fnv/symbols_00788000.h"
#include "fnv/symbols_0078e000.h"
#include "fnv/symbols_0079b000.h"
#include "fnv/symbols_0079f000.h"
#include "fnv/symbols_007a1000.h"
#include "fnv/symbols_007a8000.h"
#include "fnv/symbols_007aa000.h"
#include "fnv/symbols_007ab000.h"
#include "fnv/symbols_007ac000.h"
#include "fnv/symbols_007b6000.h"
#include "fnv/symbols_007cb000.h"
#include "fnv/symbols_007df000.h"
#include "fnv/symbols_007e6000.h"
#include "fnv/symbols_007eb000.h"
#include "fnv/symbols_007f6000.h"
#include "fnv/symbols_00879000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01047000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011ff000.h"
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
class FOPipboyManager;
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
public:
    ::FOPipboyManager *GetPipboyManager();
};
#include "interface_rebase_closure_rtti3_interface.h"
const char kMeshesFolder[] = "Meshes";
unsigned int FUN_00702440();
struct FUN_00424940_shell : public InterfaceManager
{
    char FUN_00424940();
};
extern bool DAT_011c70ed;
extern bool DAT_011c70ee;
struct ListStandIn
{
    int* FUN_0057cbe0(int** pos);
};
struct FUN_00644640_shell : public InterfaceManager
{
    bool FUN_00644640();
};
class Modifier
{
  public:
};
struct FUN_007023a0_shell : public InterfaceManager
{
    bool FUN_007023a0();
};
struct FUN_00702940_cls
{
    char pad[0x148];
    char field_148;
    void SetField148(char val);
};
struct FUN_00703060_shell : public InterfaceManager
{
    void FUN_00703060(bool);
};
struct FUN_00705b10_Dummy
{
    char pad[0xc4];
    int val;
    void Set(int a);
};
struct DummyVtable_00705e30
{
    virtual ~DummyVtable_00705e30();
};
class MapMenu
{
  public:
public:
    static void StopMapMenuSounds();
};
struct Dummy_007069f0
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3(int, int) = 0;
    void FUN_007069f0(int a1);
};
class InventoryMenu
{
  public:
    char pad00[0x5c];
    Tile* pTile5C;
    char pad60[0x24];
    int iTab84;
    static InventoryMenu* ms_pInventoryMenu;
    static int ms_iCurrentTabTileID;
};
struct Tile_Set_Helper : public Tile
{
};
struct BGSNote;
struct BGSQuestObjective;
struct TESChallenge;
struct TESQuest;
struct RegionObjectEntry;
struct TESWorldSpace;
struct PathingPath;
struct blob12
{
    char b[12];
};
class MapMenu;
struct TutorialManagerLayout
{
    struct Entry
    {
        unsigned int b0 : 1;
        unsigned int b1 : 1;
        unsigned int pad : 6;
        unsigned int rest : 24;
    };
    Entry entries[0x29];
    unsigned int unkA4;
    unsigned int unkA8;
};
struct FUN_00706cb0_shell : public InterfaceManager
{
    void ResetFieldBC();
};
class BSFaceGenAnimationData;
class BSFaceGenNiNode
{
  public:
};
class NiAVObject_Attach : public NiAVObject
{
  public:
};
struct FUN_00706d90_shell : public InterfaceManager
{
    bool FUN_00706d90();
};
struct DummyRTG_00706e90
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
    virtual unsigned int GetWidth(unsigned int);
    virtual unsigned int GetHeight(unsigned int);
};
struct DummyRenderer_00706e90
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
    virtual DummyRTG_00706e90* GetDefaultRenderTargetGroup();
};
void FUN_00706f70();
struct FUN_00714d90_struct
{
};
struct InterfaceManager_PopFromEnterStack_helper
{
};
struct IMStandIn
{
};
Tile* FUN_00707040();
void FUN_00707050(Tile* apTile);
void FUN_00707080(Menu* apMenu);
class TESResponse
{
  public:
};
Tile* GetNextTile();
class ModelLoader
{
  public:
};
struct S_004431f0
{
};
extern S_004431f0* DAT_011d890c;
struct FUN_00707950_shell : public InterfaceManager
{
    void SetNeed(bool);
};
struct FUN_007079f0_shell : public InterfaceManager
{
    bool FUN_007079f0();
};
class FORenderedMenu;
float FUN_00707b60();
extern int DAT_011d89a0;
extern int DAT_011d89a4;
extern int DAT_011d89ac;
void __cdecl FUN_00709a90();
class TESRace;
template <> class BSSimpleList<TESRace*>
{
  public:
    int GetSize();
};
struct StrHelper
{
    operator const char*() const;
};
struct StrOwner
{
    int pad;
    StrHelper s;
    const char* FUN_007fa950();
};
struct FUN_009373f0_shell : public InterfaceManager
{
    bool FUN_009373f0();
};
struct InterfaceManager;
class PlayerCharacter;
struct MobileObject;
struct DialogH
{
};
struct MapMenuH
{
};
struct StatsMenuH
{
};
struct fnv_007aa480
{
};
struct FocusH
{
    void FocusOnActor(MobileObject*, float, bool);
};
struct Im7181
{
};
void FUN_00705780();
void FUN_0083e510();
struct InterfaceManager;
struct NavMesh;
struct S3de0
{
};
struct TESAmmoInitCalls
{
};
struct FUN_00706cb0_shell2
{
};
struct QuantityData
{
};
class MenuFade : public Menu
{
  public:
};
class InterfaceManagerPC
{
  public:
};
bool __cdecl FUN_00702680(Interface::enumMenus aeMenuID, unsigned int abFadeStatesThatCountAsVisible);
extern char DAT_0119f349;
void __cdecl FUN_00704130();
class MapMenu;
void __cdecl FUN_00704470(int arg);
class ContainerMenu
{
  public:
};
struct GlobalObject_0045cfe0
{
};
void FUN_00763ff0();
class MapMenu;
char FUN_00706830();
struct FUN_005e3fc0_shell
{
    unsigned int Get();
};
struct FUN_00709920_Class
{
    const char* FUN_00709920();
};
class Tile;
class TileRect
{
  public:
    const char* FUN_00709970();
};
class TileMenu
{
  public:
    const char* FUN_00709a50();
};
bool IsSomethingZero();
extern "C" char __cdecl GetInterfaceManagerResult();
struct TESSaveLoadGame
{
};
struct FUN_00406f90_this
{
    int FUN_00406f90(char const*, char*);
};
struct UnnamedClass_00705dd0
{
    char _pad[0x9c];
    Tile* m_9c;
    int FUN_00705dd0();
};
struct FORenderedTerminal
{
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_00706810_Class
{
    int __thiscall FUN_00706810();
};
struct Dummy00712450
{
};
class FUN_004b7210_class;
class FUN_004b7210_class
{
  public:
};
struct StubMenu
{
};
struct StubTile
{
};
struct StubPipboy
{
};
struct StubIM
{
};
bool __cdecl MenuVisible(int aiID, unsigned int auFade);
struct TerminalBase
{
    int unk00;
    ~TerminalBase();
};
struct TerminalMember
{
    ~TerminalMember();
};
struct FUN_007060d0_cls : TerminalBase
{
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
    TerminalMember m_kMemberDescriptor;
    ~FUN_007060d0_cls();
};
class B706130Node;
class B706130Tile
{
  public:
};
class B706130Pick
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    B706130Pick();


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
};
class B706130Manager
{
  public:
};
class B706130Setting
{
  public:
    unsigned char* Bool();
};
class FUN_00707870_Temp
{
  public:
    float m_v;
    FUN_00707870_Temp(float f);
    ~FUN_00707870_Temp();
};
struct FUN_00707870_Owner
{
};
struct FUN_00707870_Target
{
};
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int uExitCode);
extern "C" void __debugbreak();
void FUN_00703fd0();
void FUN_0086a530();
struct Player;
struct Helper;
struct ActiveObject
{
};
struct InterfaceObject
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Release();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual ActiveObject* CurrentObject();
};
struct DialogObject
{
};
struct Helper
{
};
extern DialogObject* __cdecl FUN_00ec43fb(Helper*, int, void*, void*, int);
struct Player
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Unknown010();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual void Unknown159();
    virtual void Unknown160();
    virtual void Unknown161();
    virtual void Unknown162();
    virtual void Unknown163();
    virtual void Unknown164();
    virtual void Unknown165();
    virtual void Unknown166();
    virtual void Unknown167();
    virtual void Unknown168();
    virtual void Unknown169();
    virtual void Unknown170();
    virtual void Unknown171();
    virtual void Unknown172();
    virtual void Unknown173();
    virtual void Unknown174();
    virtual void Unknown175();
    virtual void Unknown176();
    virtual void Unknown177();
    virtual void Unknown178();
    virtual void Unknown179();
    virtual void Unknown180();
    virtual void Unknown181();
    virtual void Unknown182();
    virtual void Unknown183();
    virtual void Unknown184();
    virtual void Unknown185();
    virtual void Unknown186();
    virtual void Unknown187();
    virtual void Unknown188();
    virtual void ActivateInterface(Helper*, int, int);
    void OpenDialogMenu();
};
struct TileListAccess
{
};
struct VisibilityTile : Tile
{
};
struct VisibilityManager
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    BSSimpleList<Tile*> visibilityQueue;
};
struct NiNodeCull
{
};
struct TileChildList : NiTPointerList_Tile___
{
};
struct TileEx : Tile
{
};
struct IMMenuOpen : InterfaceManager
{
};
void __cdecl FUN_00703100();
#include <stdarg.h>
struct HWND__;
struct WinPoint
{
    long x, y;
};
struct WinMessage
{
    HWND__* hwnd;
    unsigned int message, wParam;
    long lParam;
    unsigned int time;
    WinPoint pt;
};
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(WinMessage*, HWND__*, unsigned int, unsigned int,
                                                            unsigned int);
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const WinMessage*);
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const WinMessage*);
struct InterfaceControl
{
};
class InputManager
{
  public:
};
class OSGlobals
{
  public:
};
struct MenuProxy
{
};
struct TileProxy
{
};
struct PipProxy
{
};
struct InterfaceProxy
{
};
struct DecompScopeGuard
{
    int m_00;
    DecompScopeGuard(int a, int b, const char* file, int line);
    ~DecompScopeGuard();
};
struct DecompArg12
{
    int m_00;
    int m_04;
    int m_08;
    DecompArg12(const DecompArg12& src);
    ~DecompArg12();
};
struct DecompVec3
{
    int m_00;
    int m_04;
    int m_08;
};
struct DecompTarget
{
};
struct FUN_0047ee30_shell : public InterfaceManager
{
};
// If FUN_004b7210 returns a non-null object whose FUN_009373f0 is true, returns its GetAssistance result; otherwise returns -1.
// @fnv 0x00705c70
extern "C" char __cdecl GetInterfaceManagerResult()
{
    if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())) && reinterpret_cast<FUN_009373f0_shell*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->FUN_009373f0())
    {
        return ((char)(reinterpret_cast<::TESAIForm *>((reinterpret_cast<FUN_0047ee30_shell*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->GetAssistance()));
    }
    return -1;
}
struct FloatValue
{
};
struct Data
{
};
struct Root : InterfaceManager
{
    Data data;
};
struct Buffer
{
};
char GetStatsMenuPage();
unsigned char FUN_007824b0();
float GetMapMenuFloatSetting();
struct FUN_00703960_Class
{
    void __thiscall SetByteAtOffsetEC(char param);
};
class TESForm;
class TESGlobal;
class Setting;
struct FUN_00401170_s
{
};
class TESGlobal : public TESForm
{
  public:
};
class Setting
{
  public:
};
extern Setting* DAT_0119b354[];
extern Setting* DAT_0119b35c[];
extern Setting* DAT_0119b364[];
struct Player_StandIn : public PlayerCharacter
{
};
void __cdecl GetControlLabel(int a1, char* a2, bool a3);
int __cdecl strcpy_s(char* apDest, unsigned int auiDestSize, const char* apSrc);
int __cdecl _stricmp(const char* apStr1, const char* apStr2);
class NiStream
{
  public:
    virtual ~NiStream();
    char fileName[260];
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
};
class BSStream : public NiStream
{
  public:
    BSStream();
    virtual ~BSStream();
};
class Model
{
  public:
    unsigned int unk00, unk04, unk08, unk0C;
    Model(const char*, BSStream*, bool, bool);
};
struct Loader_S
{
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NONE
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
class B7AB690FullName
{
  public:
};
class TESNPC : public TESBoundObject
{
  public:
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
    B7AB690FullName m_kFullName;
};
class B7AB690Player
{
  public:
};
class B7AB690SettingString
{
  public:
};
void __cdecl FUN_007ab7c0();
class B7AB690Menu
{
  public:
    B7AB690Menu();
    virtual ~B7AB690Menu();

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
class FUN_007ab690_cls : public B7AB690Menu
{
  public:
    FUN_007ab690_cls();
    virtual ~FUN_007ab690_cls();


    TESNPC* m_pkNPC;
};
struct InterfaceManagerPCMine : InterfaceManager
{
};
struct TESObjectREFRMine : TESObjectREFR
{
};
struct MgrQ
{
};
namespace sleep704 {
struct M70Tile
{
};
struct M70Menu
{
};
struct M70Trait
{
};
struct M70Hud
{
};
struct M70Player
{
};
bool FUN_00702680(int id, int a);

// @fnv 0x007048f0
void FUN_007048f0(bool show, bool fade, bool reset)
{
    M70Menu* pMenu3eb;
    M70Menu* pMenu3ea;
    M70Menu* pMenu40bB;
    M70Menu* aPMenu425;
    M70Menu* pMenu3ff8;
    bool bOpen;

    if (((::sleep704::M70Player *)(::fnv_004b7210::FUN_004b7210())) && reinterpret_cast<::FUN_009373f0_shell *>((((::sleep704::M70Player *)(::fnv_004b7210::FUN_004b7210()))))->FUN_009373f0())
    {
        pMenu3eb = ((::sleep704::M70Menu *)(::FUN_00a09030(0x3eb)));
        pMenu3ea = ((::sleep704::M70Menu *)(::FUN_00a09030(0x3ea)));
        pMenu40bB = ((::sleep704::M70Menu *)(::FUN_00a09030(0x40b)));
        aPMenu425 = ((::sleep704::M70Menu *)(::FUN_00a09030(0x425)));
        pMenu3ff8 = ((::sleep704::M70Menu *)(::FUN_00a09030(0x3ff)));
        bOpen = FUN_00702680(0x3ea, fade ? 0xb : 0);
        if (show)
        {
            if (!pMenu3ea)
            {
                pMenu3ea = ((::sleep704::M70Menu *)(::fnv_007048c0::CreateInventoryMenuIfModifierKey()));
            }
            if (!bOpen)
            {
                if (pMenu3eb)
                {
                    reinterpret_cast<::FUN_00a1d910_shell *>((((::sleep704::M70Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu3eb))->FUN_00a03c90()))))->FUN_00a1d910();
                    ::FUN_00704390();
                }
                if (pMenu3ff8)
                {
                    reinterpret_cast<::FUN_00a1d910_shell *>((((::sleep704::M70Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu3ff8))->FUN_00a03c90()))))->FUN_00a1d910();
                }
                if (pMenu40bB)
                {
                    reinterpret_cast<::FUN_00a1d910_shell *>((((::sleep704::M70Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu40bB))->FUN_00a03c90()))))->FUN_00a1d910();
                    ::fnv_007b6fb0::ResetRepairMenu();
                }
                if (aPMenu425)
                {
                    reinterpret_cast<::FUN_00a1d910_shell *>((((::sleep704::M70Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((aPMenu425))->FUN_00a03c90()))))->FUN_00a1d910();
                    ::fnv_007846a0::ResetItemModMenu();
                }
                if (pMenu3ea)
                {
                    reinterpret_cast<::FUN_00a1db20_shell *>((((::sleep704::M70Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu3ea))->FUN_00a03c90()))))->FUN_00a1db20();
                }
            }
            if (pMenu3ea)
            {
                ::FUN_00782a90();
                reinterpret_cast<::Tile *>((((::sleep704::M70Trait *)(reinterpret_cast<::InterfaceManager *>((((::sleep704::M70Player *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00586150()))))->Set(0x1771, 0x3ea);
            }
            if (reset)
            {
                reinterpret_cast<::fnv_007f8a80::FOPipboyManagerPC *>((((::sleep704::M70Hud *)(reinterpret_cast<::Interface *>((((::sleep704::M70Player *)(::fnv_004b7210::FUN_004b7210()))))->GetPipboyManager()))))->FUN_007f8a80();
                reinterpret_cast<::FOPipboyManager *>((((::sleep704::M70Hud *)(reinterpret_cast<::Interface *>((((::sleep704::M70Player *)(::fnv_004b7210::FUN_004b7210()))))->GetPipboyManager()))))->ActivateButton(2);
            }
            if (reinterpret_cast<::FOPipboyManager *>((((::sleep704::M70Hud *)(reinterpret_cast<::Interface *>((((::sleep704::M70Player *)(::fnv_004b7210::FUN_004b7210()))))->GetPipboyManager()))))->IsUnk28Set())
            {
                ::FUN_00782470(0);
            }
        }
        else if (!show && bOpen && pMenu3ea)
        {
            reinterpret_cast<::FUN_00a1d910_shell *>((((::sleep704::M70Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu3ea))->FUN_00a03c90()))))->FUN_00a1d910();
            ::UpdateCurrentValue();
        }
    }
}
}
struct BaseMenu
{
    BaseMenu();
    ~BaseMenu();
    virtual void vfunc();
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
};
struct RenderedPoint
{
    RenderedPoint();
    float x;
    float y;
    float z;
};
struct NodeHandle
{
    NodeHandle(int);
};
struct FUN_00705fe0 : BaseMenu
{
    RenderedPoint pt;
    NodeHandle node;

    FUN_00705fe0();
};
struct FUN_00709930
{
    virtual ~FUN_00709930();
};
// Candidate for FUN_0079ffb0 (claim clm_f5183b6336444303ae13, 0x0079ffb0, 5190 bytes)
// World-map tile mesh build / screenshot dump; param_1 != 0 selects the dump path.
// Builds on the packet's best prior attempt; corrected constructors, calls and local layout.
// Packet flags: /MT /Od /Oy- /GS /EHsc /Gy /GF. Entry ABI: __cdecl, caller pops.
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);
namespace points {
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
    FUN_006815c0(float, float, float);
    void FUN_0063c8a0(const FUN_006815c0*);
};
}
typedef points::FUN_006815c0 NiPt3;
namespace uvs {
struct FUN_006815c0
{
    float u, v;
    FUN_006815c0();
    FUN_006815c0(float, float);
};
}
typedef uvs::FUN_006815c0 NiPt2;
struct FUN_004a7800
{
    float r, g, b, a;
    FUN_004a7800();
    FUN_004a7800(float, float, float, float);
};
typedef FUN_004a7800 NiCol;
// object reached from DAT_011dea3c through virtual slot 0x1f4 (index 125, __thiscall)
struct C125
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
    virtual void* v125();
};
// object with virtual name accessor at slot 0x130 (index 76, __thiscall)
struct C76a
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
    virtual unsigned int v076();
};
struct C76b
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
    virtual unsigned int v076(int, int);
};
struct C76c
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
    virtual unsigned int v076(int);
};
// object with virtual slot 0xdc (index 55, __thiscall, callee pops 8)
struct C55
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
    virtual void v055(void*, int);
};
// object with virtual slot 0x9c (index 39, __thiscall, callee pops 4)
struct C39
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
    virtual unsigned int v039(int);
};
// chain objects reached through DAT_011dea3c members
struct Local12;
struct Mesh34;
struct V3Maker;
struct ChainObj
{
    void FUN_00a59c60(V3Maker*);
};
struct Mesh34
{
};
struct ObjD_11dea3c
{
};
// path-name providers on the object at DAT_011dea10
struct PathSrc
{
};
// object at [[DAT_011da368]+0x30]
struct Tile30
{
};
// small local-object stand-ins (methods invoked with ecx = local)
struct V3Maker
{
    float x, y, z;
    NiPt3& FUN_00416870(float x, float y, float z);
    NiPt2& FUN_00452dc0(float u, float v);
    NiCol& FUN_00414430(float a, float b, float c, float d);
    void FUN_0063c8a0(NiPt3* p);
};
struct ColorMaker
{
    float r, g, b, a;
    NiCol& FUN_00414430(float, float, float, float);
};
struct UvMaker
{
    float u, v;
    NiPt2& FUN_00452dc0(float, float);
};
struct Obj16
{
    struct FloatColor
    {
        float r, g, b, a;
    } c;
    Obj16(float, float, float, float);
};
struct Local12
{
    unsigned int value;
    Local12(int);
    ~Local12();
    void FUN_0066b0d0(int);
};
// mesh/material stand-ins
struct ObjD4
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjD4(unsigned short, void*, void*, void*, void*, int, int, unsigned int, void*, int, int, int, int);
};
struct ObjB0
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjB0(bool);
};
struct Obj1C
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Obj1C();
};
// map-menu state global, fields at their offsets
struct MapMenuR6
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
    void* tile_30;
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
    unsigned int field_84;
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
    unsigned int field_e0;
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
    unsigned int field_128;
    unsigned char field_12c;
};
// free helpers; conventions read from add esp evidence
extern "C" void __stdcall FUN_00401050(void*, unsigned int, unsigned int, void*);
extern "C" void __cdecl FUN_006815c0();
extern "C" void __cdecl FUN_004a7800();
extern "C" void* __cdecl FUN_00ec62c0();
struct ColorSource
{
};
extern "C" void __fastcall FUN_00719060(void*);
/* ecx = FUN_00718b60 result */
extern "C" void __fastcall FUN_00a59c60(void*);
/* ecx = FUN_0056c7f0 result */
struct GObj
{
};
/* object at 0x11c63cc */
// globals read/written here
struct Position
{
    float x, y, z;
};
struct RenderColor
{
    unsigned int r, g, b, a;
};
extern char DAT_01075520[];
extern char DAT_01075508[];
extern char DAT_010754f0[];
extern char DAT_010754d4[];
extern char DAT_010754ac[];
extern char DAT_01075490[];
extern char DAT_01075468[];
namespace s7094f0 {

struct Lock
{
};

struct InterfaceManagerView
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
    int m_iModalCount;

};

struct NameMenu
{
    NameMenu(int iArg0, int iArg1);


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
    int unk3c;
};

struct NameTile
{
    NameTile();


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
    int unk28;
};



static const char s_szPlayerNameEntryMenu[] = "Player Name Entry Menu";

// @fnv 0x007094f0
void FUN_007094f0()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::s7094f0::Lock *>(&::g_011d89c0))))->FUN_0040fbf0((char *)(0));
    if ((*reinterpret_cast<int *>(&::g_011d8950)) && (!((::s7094f0::InterfaceManagerView *)(::fnv_004b7210::FUN_004b7210()))->m_iModalCount || (*reinterpret_cast<int *>(&::g_011d8950)) == 6 || (*reinterpret_cast<int *>(&::g_011d8950)) == 7))
    {
        bool bPickResultFound = false;
        switch ((*reinterpret_cast<int *>(&::g_011d8950)))
        {
        case 1:
            bPickResultFound = ::FUN_00704ed0((*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011d8954)), ::DAT_011d8964) ? 1 : 0;
            break;
        case 2:
            bPickResultFound = ::fnv_00705ec0::FUN_00705ec0((*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011d8954)));
            break;
        case 3:
            bPickResultFound = ::FUN_00706130((int)((*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011d8954))));
            break;
        case 4:
            if (!reinterpret_cast<::FUN_007023a0_shell *>((((::s7094f0::InterfaceManagerView *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007023a0())
                bPickResultFound = ((int)(::fnv_00705070::FUN_00705070((*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011d8954)), (void *)(::DAT_011d8958), (void *)(::DAT_011d895c)))) ? 1 : 0;
            break;
        case 5:
            bPickResultFound = ((int)(::GetOrCreateMenuTile(::DAT_011d8960))) ? 1 : 0;
            break;
        case 6:
            bPickResultFound = ::InitStartMenu(1, 0);
            if (bPickResultFound)
                ::fnv_00771700::FUN_00771700(4);
            break;
        case 7:
            bPickResultFound = ::fnv_007a8ba0::FUN_007a8ba0();
            break;
        case 8:
            bPickResultFound = ::DestroyCompanionWheelMenu((int)(dynamic_cast<Actor*>((*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011d8954)))));
            break;
        case 9: {
            NameMenu* pkNameMenu = new NameMenu(0, 0);
            NameTile* pkTile = new NameTile;
            reinterpret_cast<::FUN_00a087d0_shell *>((pkNameMenu))->FUN_00a087d0((::Tile *)(((int)(reinterpret_cast<::InterfaceManager *>((((::s7094f0::InterfaceManagerView *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00586150()))), {});
            reinterpret_cast<::Tile *>((pkNameMenu))->SetName(s_szPlayerNameEntryMenu);
            reinterpret_cast<::FUN_00a1dc70_shell *>((pkTile))->FUN_00a1dc70((::TileMenu *)(pkNameMenu), 1);
            reinterpret_cast<::FUN_00409480_shell *>((pkNameMenu))->FUN_00409480((::TESActorBase *)(pkTile));
            bPickResultFound = true;
        }
        }
        if (bPickResultFound)
        {
            (*reinterpret_cast<int *>(&::g_011d8950)) = 0;
            (*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011d8954)) = 0;
        }
    }
    if ((*reinterpret_cast<int *>(&::g_011d8998)) && (!((::s7094f0::InterfaceManagerView *)(::fnv_004b7210::FUN_004b7210()))->m_iModalCount || (*reinterpret_cast<int *>(&::g_011d8998)) == 6 || (*reinterpret_cast<int *>(&::g_011d8998)) == 7))
    {
        bool bDone2 = false;
        switch ((*reinterpret_cast<int *>(&::g_011d8998)))
        {
        case 7:
            bDone2 = ::fnv_007a8ba0::FUN_007a8ba0();
        }
        if (bDone2)
        {
            (*reinterpret_cast<int *>(&::g_011d8998)) = 0;
            ::DAT_011d899c = 0;
        }
    }
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::s7094f0::Lock *>(&::g_011d89c0))))->FUN_0040fba0();
}

}
struct DisplayTile;
struct DisplayItem;
struct DisplayForm;
struct DisplayPlayer;
struct DisplayList
{
    DisplayTile** FUN_00683520(void**);
    void** FUN_006815c0();
};
struct DisplayName
{
};
struct DisplayTile
{
    int unk00;
    DisplayList children;
};
struct DisplayEffects
{
    int unk00;
    DisplayList effects;
};
struct DisplayItem
{
};
struct DisplayForm
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

    DisplayName name;
    bool FUN_0040e210(int);
};
struct DisplayProcess
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

    virtual DisplayItem* Weapon();
    virtual DisplayItem* Ammo();
};
struct ActorValues
{
    int unk00;
};
struct DisplayPlayerPrefix
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
};
struct DisplayPlayer : DisplayPlayerPrefix, ActorValues
{
};
struct DisplayInventory
{
};
struct DisplaySetting
{
};
struct ArmorFlags
{
};
class TESObjectARMO : public TESBoundObject
{
  public:
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

    ArmorFlags armorFlags;
};
struct DisplayDescription
{

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* Text(int, int);
};
struct DescriptionForm
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

    DisplayDescription description;
};
struct EffectPrefix
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
};
struct EffectForm : EffectPrefix, DisplayEffects
{
};
struct EnchantPrefix
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
};
struct EnchantForm : EnchantPrefix, DisplayEffects
{
    bool FUN_0040e210(int);
};
extern DisplaySetting *DAT_0118a644, *DAT_0118a648, *DAT_0118a640;
extern char DAT_0106ed0c[], DAT_0106ecfc[], DAT_0106ece0[], DAT_0106ecd8[], DAT_0106ecd0[], DAT_01030018[];

class VATSMenu : public Menu
{
};
// @fnv 0x00705780
void __cdecl FUN_00705780()
{
    if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())) && reinterpret_cast<FUN_009373f0_shell*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->FUN_009373f0())
    {
        Tile* pTile = (Tile*)((::TileProxy *)(::FUN_00a09030(Interface::eVATSMenu)));
        VATSMenu* pVATSMenuInstance = pTile ? dynamic_cast<VATSMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((void *)(pTile))->FUN_00a03c90()) : 0;
        if (pVATSMenuInstance)
            ShutdownVats();
    }
}
