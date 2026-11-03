
// src/fallout/interface/menus/inventorymenu_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESBoundObject). The skeleton of src/fallout/interface/menus/inventorymenu.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include <new>
#include "fnv/decl/ActorGoldQuery.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedureActivateObject.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00418ba0_shell.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004bd820_stand.h"
#include "fnv/decl/FUN_004bddd0_shell.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_0073ac90_shell.h"
#include "fnv/decl/FUN_007e0230.h"
#include "fnv/decl/FUN_007fa0f0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_008a0c20_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008d8160_Class.h"
#include "fnv/decl/FUN_008d85e0_Class.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FunctionOwner.h"
#include "fnv/decl/HWShell.h"
#include "fnv/decl/Host_004d4b00.h"
#include "fnv/decl/Inv4c6ba0.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/InventoryListBox.h"
#include "fnv/decl/ItemChange_004be200.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/ListBoxImpl.h"
#include "fnv/decl/ListBox_71a.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThiS.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004d4bd0__InventoryChangeFilterHost.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_009614b0__Player.h"
#include "fnv/decl/fnv_00967b70__Cls.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/list71a__L71Menu.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00479000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00719000.h"
#include "fnv/symbols_0077f000.h"
#include "fnv/symbols_00780000.h"
#include "fnv/symbols_00782000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_0104f000.h"
#include "fnv/symbols_01050000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "inventorymenu_decls_rtti_variant.h"
static const int kGetClassValue = 1002;
static const int kNumTiles = 23;
struct StatsMenu
{
    static StatsMenu* ms_pInventoryMenu;
    unsigned char m_bHealingMode;  // +0x2a0
};
struct FUN_00780be0_shell
{
    unsigned char m_0x00;  // +0x00
    unsigned char m_0x01;  // +0x01
    unsigned char m_0x02;  // +0x02
    unsigned char m_0x03;  // +0x03
    unsigned char m_0x04;  // +0x04
    unsigned char m_0x05;  // +0x05
    unsigned char m_0x06;  // +0x06
    unsigned char m_0x07;  // +0x07
    unsigned char m_0x08;  // +0x08
    unsigned char m_0x09;  // +0x09
    unsigned char m_0x0a;  // +0x0a
    unsigned char m_0x0b;  // +0x0b
    unsigned char m_0x0c;  // +0x0c
    unsigned char m_0x0d;  // +0x0d
    unsigned char m_0x0e;  // +0x0e
    unsigned char m_0x0f;  // +0x0f
    unsigned char m_0x10;  // +0x10
    unsigned char m_0x11;  // +0x11
    unsigned char m_0x12;  // +0x12
    unsigned char m_0x13;  // +0x13
    void SetByte13(unsigned char value);
};
struct FUN_0077fb50_shell
{
    void* Destroy(unsigned int flags);
};
struct TGF
{
};
void __cdecl FUN_00780c00(Tile* pTile);
struct FUN_00781b10_shell
{
    void ClearActionPointSource();
};
struct FUN_00781620_shell : public InventoryMenu
{
    void FUN_00781620(int aiID, Tile* apTarget);
};
struct ProxyPipboy
{
};
struct ProxyMgr
{
};
unsigned char FUN_007824b0();
struct FUN_007832e0_class
{
    void FUN_007832e0(float, float);
};
struct FUN_00726070_shell
{
};
struct FUN_004bddd0_t
{
};
struct FUN_00781860_shell
{
};
struct FUN_00781680_shell : public InventoryMenu
{
    void FUN_00781680();
};
struct GlobalObject_0040c150 : public InventoryMenuSetting
{
};
extern InventoryMenuSetting* DAT_011d5178;
struct FUN_007823d0_listbox
{
    virtual void FUN_007823d0_first() = 0;
    virtual int FUN_007823d0_second() = 0;
};
struct FUN_007823d0_shell : public InventoryMenu
{
    bool HandleInventoryButton(int aiButton, float afValue);
};
struct XExtra
{
};
struct ExtraDataList : XExtra
{
};
struct GO
{
    operator unsigned int() const;
};
struct Ref006815c0
{
};
struct NiPoint3
{
    int x;
    int y;
    int z;
public:
    static const ::NiPoint3 ZERO;
};
struct PlayerCharacterShell
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void DropInventoryObject(TESBoundObject*, ExtraDataList*, int, NiPoint3*, bool) = 0;
};
void __cdecl DropInventoryItem(int aiAmountChosen);
struct MenuBase_0077fb80
{
    virtual ~MenuBase_0077fb80();
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
struct ListBox_0077fb80
{
    ~ListBox_0077fb80();
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
};
struct HotKeys_0077fb80
{
    ~HotKeys_0077fb80();
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
};
struct List_0077fb80
{
    ~List_0077fb80();
    int unk00;
    int unk04;
};
class FUN_0077fb80_cls : public MenuBase_0077fb80
{
  public:
    virtual ~FUN_0077fb80_cls();
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
    int m_iCurrentTab;
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
    ListBox_0077fb80 m_b8;
    HotKeys_0077fb80 m_e8;
    List_0077fb80 m_11c;
};
class FUN_0077ffd0_menu
{
  public:
};
class FUN_0077ffd0_obj
{
  public:
};
class FUN_0077ffd0_list
{
  public:
};
class FUN_0077ffd0_lbx
{
  public:
    virtual void vfn_00();
    virtual Tile* vfn_04(int);
};
int __cdecl FUN_00ec62c0();
struct InputInterface
{
    virtual int Reserved0();
    virtual int Reserved1();
    virtual int GetFirstValue(int index);
    virtual int Reserved3();
    virtual int Reserved4();
    virtual int Reserved5();
    virtual int Reserved6();
    virtual int GetSecondValue(int index);
};
bool __cdecl FUN_00780f70();
namespace InventorySelection {
struct Item;
struct Form;
struct Tile
{
};
struct TileRef
{
};
struct TileHolder
{
    unsigned int unk0;
    TileRef tile;
};
struct List
{
    virtual void slot0();
    virtual Tile* Value(int);
    Item* FUN_007a1910();
};
struct Entry
{
};
struct Form
{
    int FUN_00401170();
};
struct Item
{
};
struct Player
{
};
struct Setting
{
};
struct Camera
{
    void FUN_007f8610(int, float, float, bool);
};
struct Interface
{
};
extern Setting* DAT_011d5168;
extern int DAT_011d9f34;
extern float DAT_01072e3c, DAT_01073af0;
extern double DAT_01073ae8, DAT_01073ae0;
extern const char DAT_0106eb24[], DAT_01073aac[];
void* FUN_00479430(Form*);
void FUN_00406d50(char*, unsigned int, const char*);
struct Menu
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
    TileHolder* icon;
    Tile* button;
    unsigned int unk44;
    Tile* label;
    unsigned int unk4c;
    unsigned int unk50;
    Tile* description;
    Tile* stats;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    Tile* ammoLabel;
    unsigned int unk7c;
    Tile* ammoCount;
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
    List list;
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
    Entry entry;
    void UpdateItemDisplay(int, Tile*);
};
// @fnv 0x00780ff0
void Menu::UpdateItemDisplay(int action, Tile* changed)
{
    if (action == 29)
    {
        (*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource)) = list.FUN_007a1910();
        if ((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource)))
        {
            int selectedSlot11 = (int)reinterpret_cast<::TileListBoxCalls *>((list.Value(0xfac)))->GetFloat({});
            if (DAT_011d9f34 != selectedSlot11)
            {
                ((::InventorySelection::Camera *)(reinterpret_cast<::Interface *>((((::InventorySelection::Interface *)(::fnv_004b7210::FUN_004b7210()))))->GetPipboyManager()))->FUN_007f8610(
                    0, DAT_011d9f34 < selectedSlot11 ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::InventorySelection::Setting *>(&::g_011db2f0)))))) : -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::InventorySelection::Setting *>(&::g_011db2f0)))))),
                    *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::InventorySelection::Setting *>(&::g_011db358)))))), 1);
                DAT_011d9f34 = selectedSlot11;
            }
            float threshold = DAT_0102f0f8;
            if (((::InventorySelection::Form *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))->FUN_00401170() == 24)
                threshold = ::DAT_0101b268;
            if (reinterpret_cast<::FUN_004bcdb0_shell *>(((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))))->FUN_004bcdb0(1) >= threshold)
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((label))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventorySelection::Setting *>(&::g_011d3dcc))))->GetMenuTitle()))), 1);
            else
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((label))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventorySelection::Setting *>(&::g_011d1f2c))))->GetMenuTitle()))), 1);
            ::FUN_00707e30((::DisplayItem *)((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))), (::DisplayTile *)(stats));
            reinterpret_cast<::Tile *>((stats))->Set(0xfa3, 1);
            reinterpret_cast<::Tile *>((((::InventorySelection::Tile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(DAT_011d9ebc, reinterpret_cast<::fnv_00967b70::Cls *>(((*reinterpret_cast<::InventorySelection::Player * *>(&::_g_thePlayer))))->FUN_00967b70((::fnv_00967b70::ArgObj *)((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource)))));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((description))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::ItemChange_004be200 *>(((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))))->GetIconFilename((::TESObjectREFR *)(0))), 1);
            Form* ammo = 0;
            if (((::InventorySelection::Form *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))->FUN_00401170() == 40)
            {
                ammo = ((::InventorySelection::Form *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ammoLabel))->FUN_00a01350(0xfcc, (char *)(::GetWeaponSkillIconPath((int)(((void *)(reinterpret_cast<::FUN_008d85e0_Class *>((ammo))->GetUnk15C()))))), 1);
                char countText[128];
                ::FUN_00406d00(countText, 128, DAT_01020764, ((int)(reinterpret_cast<::FUN_008d8160_Class *>((ammo))->GetField1BC())));
                if (ammoCount)
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ammoCount))->FUN_00a01350(0xfc4, (char *)(countText), 1);
            }
            if (!::FUN_00408b20(reinterpret_cast<::FUN_00a011f0_shell *>((description))->FUN_00a011f0(0xfcc), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventorySelection::Setting *>(&::g_011d33f0))))->GetMenuTitle()))))
            {
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            else if (((::InventorySelection::Form *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))->FUN_00401170() == 41)
            {
                float heightSlot1 = DAT_01073af0;
                float width = DAT_0104f754;
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfa1, heightSlot1 + DAT_01073ae8, 1);
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfb1, width + DAT_01073ae0, 1);
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfb0, width + DAT_01073ae0, 1);
            }
            else
            {
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                reinterpret_cast<::FUN_00a012d0_t *>((description))->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            reinterpret_cast<::FUN_00a07530_shell *>((description))->FUN_00a07530(17);
            char path[260];
            ::TaskQueueInterface::CopyStringToBuffer(path, 260, DAT_0106eb24);
            unsigned int prefixLengthSlot0 = ::FUN_0044a670(path);
            FUN_00406d50(path, 260, ::fnv_00479540::GetMenuIconName((int)(FUN_00479430(((::InventorySelection::Form *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::InventorySelection::Item * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))))));
            if (::FUN_0044a670(path) > prefixLengthSlot0)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*((::InventorySelection::Tile **)(reinterpret_cast<::FUN_0073ac90_shell *>(&(icon->tile))->FUN_0073ac90())))))->FUN_00a01350(0xfcc, (char *)(path), 1);
                reinterpret_cast<::Tile *>(((*((::InventorySelection::Tile **)(reinterpret_cast<::FUN_0073ac90_shell *>(&(icon->tile))->FUN_0073ac90())))))->Set(0xfa3, 1);
            }
            else
                reinterpret_cast<::Tile *>(((*((::InventorySelection::Tile **)(reinterpret_cast<::FUN_0073ac90_shell *>(&(icon->tile))->FUN_0073ac90())))))->Set(0xfa3, 0);
            if (!reinterpret_cast<::HotkeyWheelDisplay *>(&(entry))->GetVisible())
                reinterpret_cast<::Tile *>((description))->Set(0xfa3, 1);
            reinterpret_cast<::FUN_00781680_shell *>(this)->FUN_00781680();
        }
    }
    else if (action == 30)
    {
        reinterpret_cast<::FUN_00781b10_shell *>(this)->ClearActionPointSource();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((description))->FUN_00a01350(0xfcc, (char *)(DAT_01073aac), 1);
        if (!reinterpret_cast<::HotkeyWheelDisplay *>(&(entry))->GetVisible())
            reinterpret_cast<::Tile *>((description))->Set(0xfa3, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((button))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((DAT_011d5168))->GetMenuTitle()))), 1);
        reinterpret_cast<::Tile *>((button))->Set(0xfaf, 1);
    }
}
}

struct Form
{
};
struct Extra
{
};
struct ExtraNode
{
};
struct Entry
{
    ~Entry();
    void* FUN_004459e0(int);
};
struct EntryListNode
{
    Entry* item;
    EntryListNode* next;
    EntryListNode();
    ~EntryListNode();
    void FUN_0063f7b0();
};
struct Changes
{
};
struct InventoryCheck
{
    bool FUN_00781860(Entry* entry);
};
struct ItemLabelSource : InventoryStackRecord
{
};
class Actor;
class TESAmmo;
struct TESObjectWEAP
{
};
struct ItemLabelPlayer
{
};
struct ItemLabelChildren
{
};
struct ItemLabelTile : Tile
{
    int tileHeader;
    ItemLabelChildren children;
};

struct TileS
{
};
struct MenuTileObj
{
};
struct ListNodeObj
{
    unsigned char FUN_008256d0();
};
struct LbObj
{
    virtual void q0(int);
    virtual void q1();
    virtual void q2();
    virtual void RunFourthVirtual();
    virtual void InvokeFifthVirtualFunction();
    virtual void q5();
    virtual void RunSeventhVirtualOperation();
    virtual void q7();
    virtual void q8(int);
};
struct InvObj
{
    virtual void mq0();
    virtual void mq1();
    virtual void mq2();
    virtual void mq3();
    virtual void mq4();
    virtual void mq5(int, void*);
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    TileS* t28;
    TileS* t2c;
    TileS* t30;
    TileS* t34;
    int f38;
    TileS* t3c;
    int f40;
    TileS* t44;
    TileS* t48;
    TileS* t4c;
    int unknown_50;
    int unknown_54;
    int unknown_58;
    int unknown_5c;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;
    int unknown_70;
    TileS* t74;
    int f78;
    TileS* t7c;
    int unknown_80;
    int unknown_84;
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
    LbObj lb;
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
    ListNodeObj listHead;
};
struct InvChangesObj
{
};
struct FUN_0096a2d0
{
    void* m_item;
    FUN_0096a2d0* m_next;
    FUN_0096a2d0();
    ~FUN_0096a2d0();
};
struct ActorAV
{
    virtual int q0();
    virtual int q1();
    virtual int q2(int);
    virtual float RunFourthVirtual(int);
    virtual int InvokeFifthVirtualFunction();
    virtual int q5();
    virtual int RunSeventhVirtualOperation();
    virtual int q7(int);
};
struct ProcObj
{
    virtual int p0();
    virtual int p1();
    virtual int p2();
    virtual int p3();
    virtual int p4();
    virtual int p5();
    virtual int p6();
    virtual int p7();
    virtual int p8();
    virtual int p9();
    virtual int p10();
    virtual int p11();
    virtual int p12();
    virtual int p13();
    virtual int p14();
    virtual int p15();
    virtual int p16();
    virtual int p17();
    virtual int p18();
    virtual int p19();
    virtual int p20();
    virtual int p21();
    virtual int p22();
    virtual int p23();
    virtual int p24();
    virtual int p25();
    virtual int p26();
    virtual int p27();
    virtual int p28();
    virtual int p29();
    virtual int p30();
    virtual int p31();
    virtual int p32();
    virtual int p33();
    virtual int p34();
    virtual int p35();
    virtual int p36();
    virtual int p37();
    virtual int p38();
    virtual int p39();
    virtual int p40();
    virtual int p41();
    virtual int p42();
    virtual int p43();
    virtual int p44();
    virtual int p45();
    virtual int p46();
    virtual int p47();
    virtual int p48();
    virtual int p49();
    virtual int p50();
    virtual int p51();
    virtual int p52();
    virtual int p53();
    virtual int p54();
    virtual int p55();
    virtual int p56();
    virtual int p57();
    virtual int p58();
    virtual int p59();
    virtual int p60();
    virtual int p61();
    virtual int p62();
    virtual int p63();
    virtual int p64();
    virtual int p65();
    virtual int p66();
    virtual int p67();
    virtual int p68();
    virtual int p69();
    virtual int p70();
    virtual int p71();
    virtual int p72();
    virtual int p73();
    virtual int p74();
    virtual int p75();
    virtual int p76();
    virtual int p77();
    virtual int p78();
    virtual int p79();
    virtual int p80();
    virtual int p81();
    virtual int q82();
};
struct PlayerShell
{
};
struct RenderedObj
{
};
struct FloatSettingObj
{
};
struct IntSettingObj
{
};
struct SoundHolder
{
};
class TESFullName
{
  public:
    virtual void tf0();
};

struct ItemObj
{
};

int __cdecl FUN_00406d50(char*, unsigned int, const char*);

static const char kStr_IM_Headline_Title[] = "IM_Headline_Title";
// @fnv 0x00782a90
void FUN_00782a90()
{
    ListNodeObj* pInventoryChangeNode;
    int el;
    InvChangesObj* ea;
    int df;
    int cn;
    int ck;
    int ca;
    float bn;
    float bl;
    char ba[64];
    int ak;
    if ((*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)) && reinterpret_cast<::FOPipboyManager *>((((RenderedObj*)((void *)(::fnv_00705990::FUN_00705990())))))->IsUnk28Set())
    {
        ea = (InvChangesObj*)((::Changes *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(::_g_thePlayer))));
        ca = FUN_00406d90(((ActorAV*)&::_g_thePlayer->actorValueOwner)->RunFourthVirtual(0x12));
        ak = (int)(*((float *)&(::FUN_00403e20((float *)(((FloatSettingObj*)&(*reinterpret_cast<int *>(&::originalRuntimeFloatSetting1016))))))));
        if (ca > ak)
            ca = ak;
        FUN_00406d00(ba, 0x40, "%d", ca);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t30))->FUN_00a01350(::InventoryMenu::ms_iValueTileID, (char *)(ba), true);
        bl = (float)FUN_00406d90(((ActorAV*)&::_g_thePlayer->actorValueOwner)->RunFourthVirtual(0x4c));
        cn = ((::ProcObj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((PlayerShell*)::_g_thePlayer)))->GetBaseTexture()))->q82();
        ck = 0;
        if (cn)
            ck = (int)((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(((void*)cn))->GetName()));
        else
            ck = ((int)(::FUN_004839c0(0x1f4)));
        bn = 0.0f;
        ::ApplyPerkModifiers(0x38, (::Actor *)(::_g_thePlayer), ::_g_thePlayer, ck, &bn);
        FUN_00406d00(ba, 0x40, "%1.1f", (double)(bl + bn));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t7c))->FUN_00a01350(::InventoryMenu::ms_iValueTileID, (char *)(ba), true);
        if (reinterpret_cast<::ActorGoldQuery *>((((PlayerShell*)::_g_thePlayer)))->FUN_00891d70() > *((int *)&(::FUN_0043d4d0((int *)(((IntSettingObj*)&(*reinterpret_cast<int *>(&::g_011d3a08))))))))
            FUN_00406d00(ba, 0x40, "%d+", *((int *)&(::FUN_0043d4d0((int *)(((IntSettingObj*)&(*reinterpret_cast<int *>(&::g_011d3a08))))))));
        else
            FUN_00406d00(ba, 0x40, "%d", reinterpret_cast<::ActorGoldQuery *>((((PlayerShell*)::_g_thePlayer)))->FUN_00891d70());
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t28))->FUN_00a01350(::InventoryMenu::ms_iValueTileID, (char *)(ba), true);
        FUN_00406d00(ba, 0x40, "%d/%d", ((ActorAV*)&::_g_thePlayer->actorValueOwner)->q2(0x2e),
                     (int)(reinterpret_cast<::FUN_008a0c20_shell *>((((PlayerShell*)::_g_thePlayer)))->FUN_008a0c20()));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t34))->FUN_00a01350(::InventoryMenu::ms_iValueTileID, (char *)(ba), true);
        FUN_00406d00(ba, 0x40, "%d/%d", ((ActorAV*)&::_g_thePlayer->actorValueOwner)->q2(0x10),
                     ((ActorAV*)&::_g_thePlayer->actorValueOwner)->q7(0x10));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t2c))->FUN_00a01350(::InventoryMenu::ms_iValueTileID, (char *)(ba), true);
        if (FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011c3cb4)))))->GetMenuTitle())), "ENGLISH"))
        {
            el = (int)((void *)(::FUN_00a01860("_Title")));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->t44))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d2a18)))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->t48))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d4f60)))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->t4c))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d35d0)))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->t74))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d2eb0)))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::TileS *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::MenuTileObj *)(reinterpret_cast<::Callees *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))))->FUN_00726070()))))->FUN_00a03da0((char *)(kStr_IM_Headline_Title))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d4378)))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t30))->FUN_00a01350(el, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t7c))->FUN_00a01350(el, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d396c))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->t28))->FUN_00a01350(el, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d25b0)))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->t34))->FUN_00a01350(el, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d1e60)))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->t2c))->FUN_00a01350(el, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d300c)))))->GetMenuTitle()))), true);
        }
        reinterpret_cast<::Tile *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->t3c))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((((::MenuTileObj *)(reinterpret_cast<::Callees *>((((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))))->FUN_00726070()))))->Set(::InventoryMenu::ms_iKeyringOpenTileID, 0);
        ((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->mq5(0x1d, 0);
        if (((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->listHead.FUN_008256d0() == 0 && ea)
        {
            UpdateCurrentValue();
            ((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->lb.q0(0);
            for (pInventoryChangeNode = (ListNodeObj*)&((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->listHead;
                 pInventoryChangeNode && *((void **)(new ((void *)(pInventoryChangeNode)) ::Vec3()));
                 pInventoryChangeNode = ((::ListNodeObj *)(reinterpret_cast<::Callees *>((pInventoryChangeNode))->FUN_00726070())))
            {
                {
                    char bo[128];
                    void* bb;
                    int as;
                    ListNodeObj* am;
                    FUN_0096a2d0 ah;
                    reinterpret_cast<::Host_004d4b00 *>((ea))->FindEntriesByType((int)(*((void **)(new ((void *)(pInventoryChangeNode)) ::Vec3()))), (::Output_004d4b00 *)(void *)(&ah));
                    reinterpret_cast<::FunctionOwner *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                        ->lb))->FUN_0071a200((int)(*((void **)(new ((void *)(pInventoryChangeNode)) ::Vec3()))));
                    for (am = (ListNodeObj*)&ah; am && *((void **)(new ((void *)(am)) ::Vec3())); am = ((::ListNodeObj *)(reinterpret_cast<::Callees *>((am))->FUN_00726070())))
                    {
                        bb = dynamic_cast<TESFullName*>(
                            (TESBoundObject*)(void*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((InventoryStackRecord*)*((void **)(new ((void *)(am)) ::Vec3())))))->GetName())));
                        as = (int)FUN_0044a670(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((SoundHolder*)bb)))->FUN_00408da0())));
                        ::TaskQueueInterface::CopyStringToBuffer(bo, 0x80, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((SoundHolder*)bb)))->FUN_00408da0())));
                        if (reinterpret_cast<::FUN_004bd820_stand *>((((ItemObj*)*((void **)(new ((void *)(am)) ::Vec3())))))->FUN_004bd820())
                            FUN_00406d50(bo, 0x80, "+");
                        reinterpret_cast<::list71a::L71Menu *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                            ->lb))->FUN_0071a320((int)(*((void **)(new ((void *)(am)) ::Vec3()))), bo, (int (*)(list71a::L71Item *, list71a::L71Item *))(void *)((void*)&((void (&)())::fnv_007824e0::FUN_007824e0)), (::list71a::L71Tile *)(0));
                    }
                }
            }
            reinterpret_cast<::LBList_7314c0 *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->lb))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void *)((void*)&UpdateItemLabel), 0, 0x7fffffff);
            reinterpret_cast<::ListBox_71a *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->lb))->UpdateItems();
            reinterpret_cast<::LBList_7314c0 *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->lb))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void *)((void*)&FUN_00780c00), -1, 0x7fffffff);
            reinterpret_cast<::FileMatchList *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->listHead))->RemoveAll();
        }
        else
        {
            reinterpret_cast<::InventoryListBox *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                ->lb))->PopulateInventoryList((::InventoryOwner *)(::_g_thePlayer), (bool (*)(InventoryEntry *))(0), 0, (void (*)(Tile *, InventoryEntry *))(void *)((void*)&UpdateItemLabel), 0, 0);
            if (ea)
            {
                if (((int)(reinterpret_cast<::Inv4c6ba0 *>((ea))->FindFirstItemOfType(0x2e, &df))))
                {
                    TileS* tt;
                    tt = ((::TileS *)(reinterpret_cast<::list71a::L71Menu *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
                             ->lb))->FUN_0071a320(0, ((const char *)(reinterpret_cast<::StartMenu *>((((InventoryMenuSetting*)&(*reinterpret_cast<int *>(&::g_011d3b20)))))->GetMenuTitle())), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
                    reinterpret_cast<::Tile *>((tt))->Set(0xfaa, 0x1e);
                }
            }
            reinterpret_cast<::ListBoxImpl *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->lb))->ApplyFilter((bool (*)(void *))(void *)((void*)&((void (&)())::FUN_00782620)));
            reinterpret_cast<::LBList_7314c0 *>(&(((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->lb))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void *)((void*)&FUN_00780c00), -1, 0x7fffffff);
            ((InvObj*)(void*)(unsigned int)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->lb.q8((int)&((void (&)())::fnv_007824e0::FUN_007824e0));
        }
        ((FUN_00781b10_shell*)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->ClearActionPointSource();
        FUN_007800c0();
    }
}
