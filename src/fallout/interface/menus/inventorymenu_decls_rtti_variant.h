// Private constructor declarations; field layouts follow the canonical PC headers.
#ifndef FNV_INVENTORYMENU_DECLS_H
#define FNV_INVENTORYMENU_DECLS_H

#include <stddef.h>
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedureActivateObject.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/HWShell.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/ThiS.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00719000.h"
#include "fnv/symbols_00782000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#define FNV_CTOR_JOIN_(a, b) a##b
#define FNV_CTOR_JOIN(a, b) FNV_CTOR_JOIN_(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_CTOR_JOIN(fnv_layout_check_, __LINE__)[(c) ? 1 : -1]
class Tile;
class TileMenu;
class Tile__TileTemplate;
class InventoryStackRecord;
class TESBoundObject;
class ListBoxItem_ItemChange___;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    void AddHead(T&);
};
class Menu
{
  public:
    Menu();
    virtual ~Menu();
    virtual void SetTile(unsigned int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleClick(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void PostDragTileChange(unsigned int, Tile*, Tile*);
    virtual void PreDragTileChange(unsigned int, Tile*, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void OnClickHeld(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual unsigned int GetID();
    void SetMenuVisibility(bool);
    TileMenu* pMenu;
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId;
    int m_iSecondaryValue;
    bool m_bIsSpecial;
    bool m_bVisible;
    int m_iMenuId;
    int m_eFadeState;
};
class ListBoxBase
{
  public:
    virtual void vfn_00();
    virtual Tile* vfn_04();
};
class InventoryMenu__sPageState
{
  public:
    int m_iSelectedItemIndex;  // +0x0
    int m_iScrollOffset;       // +0x4
};

class ListBox_ItemChange___ : public ListBoxBase
{
  public:
    ListBox_ItemChange___();
    ~ListBox_ItemChange___();
    void Initialize(Tile*, const char*);
    void FUN_007a1930(bool);
    BSSimpleList<ListBoxItem_ItemChange___*> bSSimpleList_ListBoxItem_ItemChange______Component;  // +0x4
    Tile* m_pListTile;                                                                            // +0xC
    Tile* m_pSelectedTile;                                                                        // +0x10
    Tile* m_pHighlightedTile;                                                                     // +0x14
    const char* pTemplateName;                                                                    // +0x18
    unsigned short m_usSelectedIndex;                                                             // +0x1C
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned char layoutPadding2E[2];
};

class HotkeyWheelDisplay
{
  public:
    HotkeyWheelDisplay();
    ~HotkeyWheelDisplay();
    bool GetVisible();
    void SetVisible(bool);
    void Initialize(Tile*);
    Tile* m_pWheelTile;                  // +0x0
    Tile* m_ppHotkeySlotTiles[8];  // +0x4
    bool m_bHasHotkeySelection;    // +0x24
    unsigned char layoutPadding25[3];
    int m_iTileValueIdAtOffset28;  // +0x28
    int m_iTileValueIdAtOffset2C;  // +0x2C
    int m_iTileValueIdAtOffset30;  // +0x30
public:
    int SetHotkeyItem(int, int);
};

class InventoryMenu : public Menu
{
  public:
    InventoryMenu();
    virtual ~InventoryMenu();
    static int ms_iValueTileID;
    static int ms_iItemTypeTileID;
    static int ms_iCurrentTabTileID;
    static int ms_iKeyringOpenTileID;
    Tile* m_pTiles[23];                              // +0x28
    int m_iCurrentTab;                               // +0x84
    InventoryMenu__sPageState m_kPageStates[6];      // +0x88
    ListBox_ItemChange___ m_kItemList;               // +0xB8
    HotkeyWheelDisplay m_kMenuData;                        // +0xE8
    BSSimpleList<TESBoundObject*> m_kHotkeyObjects;  // +0x11C
    int GetClass();
    void UpdateDialog();
    static Tile* Create();
    static int FUN_0077ff80();
    bool FUN_0077ff90();
    static InventoryMenu* ms_pInventoryMenu;
    static InventoryStackRecord* ms_pActionPointSource;
    void AssignTileByID(int id, Tile* tile);
};

FNV_STATIC_ASSERT(sizeof(InventoryMenu) == 0x124);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_iCurrentTab) == 0x84);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kPageStates) == 0x88);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kItemList) == 0xB8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kMenuData) == 0xE8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kHotkeyObjects) == 0x11C);

class Tile
{
  public:
    void Set(int, int);
    static float GetInterfaceScale();
};
class TileListBoxCalls : public Tile
{
  public:
    float GetFloat(int);
};
class FOPipboyManager
{
  public:
    bool IsUnk28Set();
};
enum ENUM_FORM_ID;
class TESForm
{
  public:
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
  public:
    static const int kArmor = 25;
    static const int kWeapon = 40;
    ENUM_FORM_ID GetFormType() const;
};
class TESBoundObject : public TESForm
{
};
class TESObjectARMO : public TESBoundObject
{
  public:
};
class InventoryStackRecord
{
  public:
public:
    static float GetConditionPercent(float);
public:
    void *GetPayloadAddress();
};
class InputManager
{
  public:
};
class OSGlobals
{
  public:
};
class ActorValueOwner
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual float GetActorValue(int);
};
class PlayerCharacter
{
  public:
    unsigned char layoutPadding00[0xa4];
    ActorValueOwner actorValueOwner;
};
class FOPipboyManager;
class Interface
{
  public:
    enum enumMenus
    {
        kInventory = 1002
    };
    static bool GetSelectedTargetIndex(enumMenus);
    static void SetTileFormattedText(Tile*, int, const char*, ...);
public:
    ::FOPipboyManager *GetPipboyManager();
};
class InterfaceManager
{
  public:
    class TutorialState
    {
      public:
    };
    unsigned char layoutPadding00[0x4d4];
    TutorialState tutorialManager;
    Tile* FUN_00586150();
};
class InventoryMenuSetting
{
  public:
};
extern bool DAT_011d9f38;
#endif
