// fallout/interface/menus/inventorymenu.cpp: InventoryMenu, Interface, Menu, InventoryCheck and more (30 functions)

#include <new>
#include "fnv/decl/ActorSoundStub.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ChangesShell.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/CombatProcedureActivateObject.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00418ab0_shell.h"
#include "fnv/decl/FUN_00418b10_shell.h"
#include "fnv/decl/FUN_00418ba0_shell.h"
#include "fnv/decl/FUN_00480d90_shell.h"
#include "fnv/decl/FUN_004938c0_class.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004bd820_stand.h"
#include "fnv/decl/FUN_004bddd0_shell.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_004be580_class.h"
#include "fnv/decl/FUN_0058ff60_shell.h"
#include "fnv/decl/FUN_006044c0_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_007e0230.h"
#include "fnv/decl/FUN_007fa0f0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0088c650_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_008d8160_Class.h"
#include "fnv/decl/FUN_008d85e0_Class.h"
#include "fnv/decl/FUN_00950030_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/HWShell.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/ItemChange_004be200.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/ListBoxImpl.h"
#include "fnv/decl/OwnerObject.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThiS.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_004d4bd0__InventoryChangeFilterHost.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_009614b0__Player.h"
#include "fnv/decl/fnv_00967b70__Cls.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/s88c790__Actor.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00479000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00719000.h"
#include "fnv/symbols_0077f000.h"
#include "fnv/symbols_00780000.h"
#include "fnv/symbols_00782000.h"
#include "fnv/symbols_00784000.h"
#include "fnv/symbols_007ab000.h"
#include "fnv/symbols_007b7000.h"
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
#include "fnv/symbols_01072000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "inventorymenu_decls.h"

static const int kGetClassValue = 1002;

// @fnv 0x0077fb40
int InventoryMenu::GetClass()
{
    return kGetClassValue;
}

// m_pTiles holds kNumTiles (23) entries, so out-of-range tile ids are ignored.
static const int kNumTiles = 23;

// Stores tile in the tile array at index id when id is within the valid tile range.
// @fnv 0x007cb4e0
void InventoryMenu::AssignTileByID(int aiTileIndex, Tile* tile)
{
    if (aiTileIndex >= 0 && aiTileIndex < kNumTiles)
    {
        m_pTiles[aiTileIndex] = tile;
    }
}

// @fnv 0x0077fa00
InventoryMenu::InventoryMenu()
{
    ms_iValueTileID = ::FUN_00a01860("_Value");
    ms_iItemTypeTileID = ::FUN_00a01860("_ItemType");
    ms_iCurrentTabTileID = ::FUN_00a01860("_CurrentTab");
    ms_iKeyringOpenTileID = ::FUN_00a01860("_KeyringOpen");
    ::InventorySelection::DAT_011d9ebc = ::FUN_00a01860("_EquippableItem");
    for (int i = 0; i < 6; ++i)
    {
        m_kPageStates[i].m_iSelectedItemIndex = -1;
        m_kPageStates[i].m_iScrollOffset = 0;
    }
    m_iCurrentTab = 0;
}

// Handles hotkey selection for the inventory menu: toggles hotkey slots, shows messages for invalid items, and updates the item card display.
// @fnv 0x00781ba0
void InventoryMenu::UpdateDialog()
{
    if (!Interface::GetSelectedTargetIndex(Interface::kInventory) ||
        !((::FOPipboyManager *)(::fnv_00705990::FUN_00705990()))->IsUnk28Set())
        return;
    int iPage;
    int iHotkey;
    bool bHotkeySelected;
    int iIndex;
    if (FUN_004b71d0())
    {
        if (m_kMenuData.GetVisible())
        {
            m_pTiles[20]->Set(0xfa3, 0);
            m_pTiles[22]->Set(0xfa3, 0);
            iHotkey = reinterpret_cast<::HWShell *>(&(m_kMenuData))->FUN_00701bd0(-1);
            if (iHotkey >= 0)
            {
                DAT_011d9f38 = true;
            }
            else if (DAT_011d9f38)
            {
                if (ms_pActionPointSource && reinterpret_cast<::FUN_004bcdb0_shell *>((ms_pActionPointSource))->FUN_004bcdb0(true) == 0.0)
                {
                    ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d3810))))->GetMenuTitle()))), 0,
                                           (int)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"),
                                           (int)("UIVATSInsufficientAP"), 2.0f, false);
                }
                else if (!reinterpret_cast<::FUN_00a01230_shell *>((((::Tile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero(::InventorySelection::DAT_011d9ebc) ||
                         (ms_pActionPointSource &&
                          ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ms_pActionPointSource))->GetName()))->GetFormType() == TESForm::kArmor))
                {
                    ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d1e18))))->GetMenuTitle()))), 0,
                                           (int)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"),
                                           (int)("UIVATSInsufficientAP"), 2.0f, false);
                }
                else
                {
                    reinterpret_cast<::ThiS *>(&(m_kMenuData))->FUN_007019e0((::ObjRef *)(ms_pActionPointSource));
                    TESBoundObject* object = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ms_pActionPointSource))->GetName()));
                    m_kHotkeyObjects.AddHead(object);
                    UpdateItemList();
                    m_kMenuData.SetVisible(true);
                    m_pTiles[11]->Set(0xfa3, 0);
                }
                DAT_011d9f38 = false;
            }
        }
        else if (ms_pActionPointSource && ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ms_pActionPointSource))->GetName()))->GetFormType() == TESForm::kWeapon)
        {
            m_pTiles[20]->Set(0xfa3, 1);
            m_pTiles[22]->Set(0xfa3, 1);
            ::UpdateAnimationTileFade((::AnimationTile *)(::Tile *)(0), (::AnimationTile *)(::Tile *)(0), (::AnimationTile *)(m_pTiles[20]), (::AnimationReference *)(ms_pActionPointSource), true);
            ::UpdateAnimationTileFade((::AnimationTile *)(::Tile *)(0), (::AnimationTile *)(::Tile *)(0), (::AnimationTile *)(m_pTiles[22]), (::AnimationReference *)(ms_pActionPointSource), true);
        }
    }
    else
    {
        bHotkeySelected = false;
        if (ms_pActionPointSource && ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ms_pActionPointSource))->GetName()))->GetFormType() == TESForm::kWeapon)
        {
            m_pTiles[20]->Set(0xfa3, 1);
            m_pTiles[22]->Set(0xfa3, 1);
        }
        for (iIndex = 0; !bHotkeySelected && !reinterpret_cast<::FUN_00a01230_shell *>((((::Tile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero(ms_iKeyringOpenTileID) &&
                         iIndex < reinterpret_cast<::CombatProcedureActivateObject *>(&(m_kMenuData))->FUN_006e4ba0();
             ++iIndex)
        {
            if (reinterpret_cast<::HotkeyWheelDisplay *>((((::InputManager *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()))))->SetHotkeyItem(iIndex + 17, 1) ||
                (reinterpret_cast<::HotkeyWheelDisplay *>((((::InputManager *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()))))->SetHotkeyItem(iIndex + 17, 0) && iIndex != 1))
            {
                if (iIndex == 1)
                    continue;
                if (!m_kMenuData.GetVisible())
                {
                    m_kMenuData.SetVisible(true);
                    m_pTiles[11]->Set(0xfa3, 0);
                }
                else
                {
                    m_pTiles[20]->Set(0xfa3, 0);
                    m_pTiles[22]->Set(0xfa3, 0);
                }
                reinterpret_cast<::HWShell *>(&(m_kMenuData))->FUN_00701bd0(iIndex);
                bHotkeySelected = true;
            }
        }
        if (!bHotkeySelected && m_kMenuData.GetVisible())
        {
            m_kMenuData.SetVisible(false);
            if (m_kItemList.vfn_04())
                m_pTiles[11]->Set(0xfa3, 1);
        }
    }
    if (::FUN_00702360() && reinterpret_cast<::ButtonDevice *>((((::InputManager *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()))))->FUN_00a23a50(1, 1) && m_kItemList.vfn_04() &&
        !reinterpret_cast<::HotkeyWheelDisplay *>((((::InputManager *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()))))->SetHotkeyItem(14, 1))
        HandleClick(7, 0);
    iPage = ms_pInventoryMenu->m_iCurrentTab + 24;
    if (iPage == 24)
    {
        ::UpdateAnimationTileFade((::AnimationTile *)(m_pTiles[14]), (::AnimationTile *)(m_pTiles[15]), (::AnimationTile *)(m_pTiles[16]), (::AnimationReference *)(ms_pActionPointSource), false);
    }
    else if (iPage == 25)
    {
        ::UpdateAnimationTileFade(
            (::AnimationTile *)(::Tile *)(ms_pActionPointSource &&
                    ((float)(::FUN_004be060((void *)(static_cast<TESObjectARMO*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ms_pActionPointSource))->GetName()))))))) != 0.0
                ? m_pTiles[17]
                : 0),
            (::AnimationTile *)(::Tile *)(ms_pActionPointSource &&
                    ::FUN_004be180((char *)(static_cast<TESObjectARMO*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((ms_pActionPointSource))->GetName()))))) != 0.0
                ? m_pTiles[18]
                : 0),
            (::AnimationTile *)(::Tile *)(0), (::AnimationReference *)(ms_pActionPointSource), false);
    }
    reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[2]))->FUN_00a012d0(0xfa9, 0.0f, true);
    ::UpdateAnimationTileFade((::AnimationTile *)(::Tile *)(::_g_thePlayer->actorValueOwner.GetActorValue(18) != 0.0 ? m_pTiles[2] : 0),
                                          (::AnimationTile *)(m_pTiles[21]), (::AnimationTile *)(::Tile *)(0), (::AnimationReference *)(ms_pActionPointSource), false);
}

// Loads inventory_menu.xml, stores the InventoryMenu, initializes its list and title tiles, and returns the tile or 0 on failure.
// @fnv 0x0077fc10
Tile* InventoryMenu::Create()
{
    InterfaceManager* pMenuInterfaceManager = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    float m_fProjectionDepth = Tile::GetInterfaceScale();
    Menu* oldMenu = ((::Menu *)(::FUN_00a09030(FUN_0077ff80())));
    if (oldMenu)
        delete oldMenu;
    Tile* pTile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((pMenuInterfaceManager->FUN_00586150()))->FUN_00a01b00((void *)("Data\\Menus\\Main\\inventory_menu.xml"));
    ms_pInventoryMenu = static_cast<InventoryMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((pTile))->FUN_00a03c90());
    ::fnv_00a1ca20::RemoveMenuEntries("Data\\Menus\\Main\\inventory_menu.xml", ms_pInventoryMenu);
    if (ms_pInventoryMenu && ms_pInventoryMenu->GetID() == FUN_0077ff80())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((ms_pInventoryMenu))->FUN_00a1dc70(reinterpret_cast<TileMenu*>(pTile), false);
        ::FUN_00867a20((void *)(ms_pInventoryMenu));
        if (!ms_pInventoryMenu->FUN_0077ff90())
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (static_cast<TileListBoxCalls*>(pTile)->GetFloat(0xfa7) == 6006.0 ||
            static_cast<TileListBoxCalls*>(pTile)->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfad, Tile::GetInterfaceScale(), true);
        reinterpret_cast<::TutorialMessageGate718 *>(&(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->tutorialManager))->FUN_00718630(34, FUN_0077ff80(), 512);
        ms_pInventoryMenu->m_kItemList.Initialize(ms_pInventoryMenu->m_pTiles[4], "IM_InventoryListTemplate");
        ms_pInventoryMenu->m_kItemList.FUN_007a1930(false);
        Interface::SetTileFormattedText(ms_pInventoryMenu->m_pTiles[13], 24, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d29b8))))->GetMenuTitle())),
                                        ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d4d50))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d40b4))))->GetMenuTitle())),
                                        ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d2acc))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d3258))))->GetMenuTitle())), 0);
        ms_pInventoryMenu->m_kMenuData.Initialize(ms_pInventoryMenu->m_pTiles[5]);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ms_pInventoryMenu->m_pTiles[10]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d29f4))))->GetMenuTitle()))), true);
        int titleTrait = ::FUN_00a01860("_Title");
        if (ms_pInventoryMenu->m_pTiles[14])
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ms_pInventoryMenu->m_pTiles[14]))->FUN_00a01350(titleTrait, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d2c7c))))->GetMenuTitle()))), true);
        if (ms_pInventoryMenu->m_pTiles[15])
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ms_pInventoryMenu->m_pTiles[15]))->FUN_00a01350(titleTrait, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d412c))))->GetMenuTitle()))), true);
        if (ms_pInventoryMenu->m_pTiles[16])
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ms_pInventoryMenu->m_pTiles[16]))->FUN_00a01350(titleTrait, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d330c))))->GetMenuTitle()))), true);
        if (ms_pInventoryMenu->m_pTiles[17])
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ms_pInventoryMenu->m_pTiles[17]))->FUN_00a01350(titleTrait, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
        if (ms_pInventoryMenu->m_pTiles[18])
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((ms_pInventoryMenu->m_pTiles[18]))->FUN_00a01350(titleTrait, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d396c))))->GetMenuTitle()))), true);
        ms_pInventoryMenu->SetMenuVisibility(true);
        return pTile;
    }
    else
    {
        if (ms_pInventoryMenu && ((::Tile *)(reinterpret_cast<::Callees *>((ms_pInventoryMenu))->FUN_00726070())))
            delete ms_pInventoryMenu;
    }
    return 0;
}

// @fnv 0x0077ff80
int InventoryMenu::FUN_0077ff80()
{
    return kGetClassValue;
}

// Returns true only if every one of the kNumTiles tile pointers is non-null; otherwise returns false.
// @fnv 0x0077ff90
bool InventoryMenu::FUN_0077ff90()
{
    for (int i = 0; i < kNumTiles; ++i)
    {
        if (!m_pTiles[i])
            return false;
    }
    return true;
}

struct StatsMenu
{
    static StatsMenu* ms_pInventoryMenu;
    unsigned char m_bHealingMode;  // +0x2a0
};

// @fnv 0x00704390
void __cdecl FUN_00704390()
{
    if (StatsMenu::ms_pInventoryMenu != 0)
    {
        if (*(reinterpret_cast<unsigned char*>(StatsMenu::ms_pInventoryMenu) + 0x2a0) != 0)
        {
            reinterpret_cast<::FUN_007e0230 *>((StatsMenu::ms_pInventoryMenu))->RefreshHealingOptions();
        }
    }
}

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
    void __thiscall SetByte13(unsigned char value);
};

// @fnv 0x00780be0
void FUN_00780be0_shell::SetByte13(unsigned char value)
{
    m_0x13 = value;
}

struct FUN_0077fb50_shell
{
    void* __thiscall Destroy(unsigned int flags);
};
struct TGF
{
};
// Sets tile property 0xFA3 to whether the float from property 0xFAC is greater than or equal to _gModifierZero.
// @fnv 0x00780c00
void __cdecl FUN_00780c00(Tile* pTile)
{
    pTile->Set(0xFA3, reinterpret_cast<::TileListBoxCalls *>((void *)(((TGF*)pTile)))->GetFloat(0xFAC) >= ::_DAT_01012060);
}

struct FUN_00781b10_shell
{
    void __thiscall ClearActionPointSource();
};
struct FUN_00781620_shell : public InventoryMenu
{
    void __thiscall FUN_00781620(int aiID, Tile* apTarget);
};
// @fnv 0x00781620
void __thiscall FUN_00781620_shell::FUN_00781620(int aiID, Tile* apTarget)
{
    if (aiID == 0x1D || aiID == 0x1E)
    {
        if (!::FUN_004b71d0() || ::fnv_007023c0::FUN_007023c0() != 0x3F8)
            reinterpret_cast<FUN_00781b10_shell*>(this)->ClearActionPointSource();
        ((::Tile *)(reinterpret_cast<::Callees *>((this))->FUN_00726070()))->Set(::InventorySelection::DAT_011d9ebc, 0);
    }
}

struct ProxyPipboy
{
};
struct ProxyMgr
{
};
// @fnv 0x00782470
void FUN_00782470(bool a1)
{
    if (InventoryMenu::ms_pInventoryMenu)
        reinterpret_cast<::FUN_007fa0f0_Class *>((((::ProxyPipboy *)(reinterpret_cast<::Interface *>((((ProxyMgr*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->GetPipboyManager()))))->SetValue(InventoryMenu::ms_pInventoryMenu->m_iCurrentTab, a1);
}

// @fnv 0x007824b0
unsigned char FUN_007824b0()
{
    int currTab;
    if (InventoryMenu::ms_pInventoryMenu)
        currTab = ((unsigned char*)InventoryMenu::ms_pInventoryMenu)[0x84];
    else
        currTab = 0;
    return currTab;
}

// Returns 0 when a1 is non-null and its form type is 0x2E, otherwise returns 1.
// @fnv 0x00782810
unsigned char __cdecl IsNotFormType2E(void* a1)
{
    int v;
    if (a1)
        v = ((TESForm*)((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((a1))->GetName())))->GetFormType() != 0x2E;
    else
        v = 1;
    return v;
}

struct FUN_007832e0_class
{
    void FUN_007832e0(float, float);
};
struct FUN_00726070_shell
{
};

// @fnv 0x007800c0
void __cdecl FUN_007800c0()
{
    int iElementIndex;
    if (reinterpret_cast<::FUN_00a01230_shell *>((((::Tile *)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)InventoryMenu::ms_pInventoryMenu)))->FUN_00726070()))))->IsTraitNonZero(InventoryMenu::ms_iKeyringOpenTileID))
        iElementIndex = 5;
    else
        iElementIndex = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab;
    int iarg = iElementIndex;
    ((FUN_007832e0_class*)&InventoryMenu::ms_pInventoryMenu->m_kItemList)
        ->FUN_007832e0(InventoryMenu::ms_pInventoryMenu->m_kPageStates[iarg].m_iSelectedItemIndex,
                       InventoryMenu::ms_pInventoryMenu->m_kPageStates[iarg].m_iScrollOffset);
}

struct FUN_004bddd0_t
{
};

struct FUN_00781860_shell
{
};

struct FUN_00781680_shell : public InventoryMenu
{
    void __thiscall FUN_00781680();
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
    bool __thiscall HandleInventoryButton(int aiButton, float afValue);
};

// Handles inventory menu buttons 16 and 10 when the inventory interface is open, hiding a tile and returning whether the button was handled.
// @fnv 0x007823d0
bool __thiscall FUN_007823d0_shell::HandleInventoryButton(int aiButton, float afValue)
{
    bool bhandled;

    bhandled = false;

    if (Interface::GetSelectedTargetIndex(Interface::kInventory))
    {
        switch (aiButton)
        {
        case 16:
            reinterpret_cast<HotkeyWheelDisplay*>(reinterpret_cast<char*>(this) + 0xE8)->SetVisible(false);

            if (reinterpret_cast<FUN_007823d0_listbox*>(reinterpret_cast<char*>(this) + 0xB8)->FUN_007823d0_second())
            {
                (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x54))->Set(0xFA3, 1);
            }

            bhandled = true;
            break;

        case 10:
            HandleClick(0x0A, 0);
            bhandled = true;
            break;
        }
    }

    return bhandled;
}

namespace fnv_007824e0 {
template <class T> struct ListBoxItem
{
    int m_iValueAt00;
    T m_pInventoryEntryData;
};

struct FUN_004be2d0_shell
{
};

struct FUN_004bddd0_t
{
};


// @fnv 0x007824e0
int __cdecl FUN_007824e0(ListBoxItem<InventoryStackRecord*>* apItem1, ListBoxItem<InventoryStackRecord*>* apItem2)
{
    int iresult;

    if (apItem1->m_pInventoryEntryData == 0)
    {
        iresult = 1;
    }
    else if (apItem2->m_pInventoryEntryData == 0)
    {
        iresult = -1;
    }
    else if (::FUN_00408b20(
                 reinterpret_cast<char const*>(
                     ((const unsigned char *)(reinterpret_cast<::FUN_004be2d0_shell *>((reinterpret_cast<FUN_004be2d0_shell*>(apItem1->m_pInventoryEntryData)))->GetTargetFullName()))),
                 reinterpret_cast<char const*>(
                     ((const unsigned char *)(reinterpret_cast<::FUN_004be2d0_shell *>((reinterpret_cast<FUN_004be2d0_shell*>(apItem2->m_pInventoryEntryData)))->GetTargetFullName())))) == 0)
    {
        iresult = reinterpret_cast<::FUN_004bcdb0_shell *>((apItem1->m_pInventoryEntryData))->FUN_004bcdb0(0) >
                          reinterpret_cast<::FUN_004bcdb0_shell *>((apItem2->m_pInventoryEntryData))->FUN_004bcdb0(0)
                      ? -1
                      : (reinterpret_cast<::FUN_004bcdb0_shell *>((apItem1->m_pInventoryEntryData))->FUN_004bcdb0(0) <
                                 reinterpret_cast<::FUN_004bcdb0_shell *>((apItem2->m_pInventoryEntryData))->FUN_004bcdb0(0)
                             ? 1
                             : 0);

        if (iresult == 0)
        {
            if (reinterpret_cast<::FUN_004bddd0_shell *>((reinterpret_cast<FUN_004bddd0_t*>(apItem1->m_pInventoryEntryData)))->FUN_004bddd0(0))
            {
                iresult = -1;
            }
            else if (reinterpret_cast<::FUN_004bddd0_shell *>((reinterpret_cast<FUN_004bddd0_t*>(apItem2->m_pInventoryEntryData)))->FUN_004bddd0(0))
            {
                iresult = 1;
            }
        }
    }
    else
    {
        iresult = ::FUN_00408b20(
            reinterpret_cast<char const*>(
                ((const unsigned char *)(reinterpret_cast<::FUN_004be2d0_shell *>((reinterpret_cast<FUN_004be2d0_shell*>(apItem1->m_pInventoryEntryData)))->GetTargetFullName()))),
            reinterpret_cast<char const*>(
                ((const unsigned char *)(reinterpret_cast<::FUN_004be2d0_shell *>((reinterpret_cast<FUN_004be2d0_shell*>(apItem2->m_pInventoryEntryData)))->GetTargetFullName()))));
    }

    return iresult;
}
}  // namespace fnv_007824e0

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


// @fnv 0x00780c50
void __cdecl DropInventoryItem(int aiAmountChosen)
{
    ExtraDataList* pextra;
    TESBoundObject* pobjectRef;
    NiPoint3 dropPoint;

    dropPoint.x = (*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
    dropPoint.y = _DAT_011f4270;
    dropPoint.z = _DAT_011f4274;

    pobjectRef = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((InventoryMenu::ms_pActionPointSource))->GetName()));

    pextra = reinterpret_cast<GO*>(InventoryMenu::ms_pActionPointSource)->operator unsigned int()
                 ? *reinterpret_cast<ExtraDataList**>(
                       ((void *)(new ((void *)(reinterpret_cast<Ref006815c0*>(
                           reinterpret_cast<GO*>(InventoryMenu::ms_pActionPointSource)->operator unsigned int()))) ::Vec3())))
                 : 0;

    if (aiAmountChosen == 0)
        return;

    if (pextra && reinterpret_cast<::FUN_00418770_shell *>((pextra))->FUN_00418770() < aiAmountChosen)
        pextra = 0;

    reinterpret_cast<::fnv_009614b0::Player *>(((*reinterpret_cast<::PlayerCharacterShell * *>(&::_g_thePlayer))))->FUN_009614b0((::fnv_009614b0::Bound *)(pobjectRef), (::fnv_009614b0::V3 *)(::NiPoint3 *)(&dropPoint), 1, 1);
    (*reinterpret_cast<::PlayerCharacterShell * *>(&::_g_thePlayer))->DropInventoryObject(pobjectRef, pextra, aiAmountChosen, &dropPoint, false);

    if (InventoryMenu::ms_pInventoryMenu)
    {
        if (InventoryMenu::ms_pActionPointSource)
        {
            {
                TESBoundObject* p = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((InventoryMenu::ms_pActionPointSource))->GetName()));
                InventoryMenu::ms_pInventoryMenu->m_kHotkeyObjects.AddHead(p);
            }
        }
        InventoryMenu::UpdateItemList();
    }
}

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
// Calls FUN_0077fb80, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0077fb50
void* __thiscall FUN_0077fb50_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_0077fb80_cls *>(this)->FUN_0077fb80_cls::~FUN_0077fb80_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Clears the global DAT_011d9ea4 to zero when the object is destroyed.
// @fnv 0x0077fb80
FUN_0077fb80_cls::~FUN_0077fb80_cls()
{
    (*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)) = 0;
}

extern int DAT_011d9eb8;

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

// @fnv 0x0077ffd0
void __cdecl UpdateCurrentValue()
{
    int tab;
    int idx;
    int res5;
    if (reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<FUN_0077ffd0_obj*>(
            ((::Tile *)(reinterpret_cast<::Callees *>((reinterpret_cast<FUN_0077ffd0_menu*>(InventoryMenu::ms_pInventoryMenu)))->FUN_00726070())))))->IsTraitNonZero({}))
    {
        tab = 5;
    }
    else
    {
        tab = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab;
    }
    idx = tab;
    if (InventoryMenu::ms_pInventoryMenu->m_kItemList.vfn_04() != 0)
    {
        reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<FUN_0077ffd0_obj*>(
            reinterpret_cast<FUN_0077ffd0_lbx*>(&InventoryMenu::ms_pInventoryMenu->m_kItemList)->vfn_04(0xfac))))->GetFloat({});
        res5 = FUN_00ec62c0();
    }
    else
    {
        res5 = -1;
    }
    InventoryMenu::ms_pInventoryMenu->m_kPageStates[idx].m_iSelectedItemIndex = res5;
    reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<FUN_0077ffd0_obj*>(
        ((void *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<FUN_0077ffd0_list*>(&InventoryMenu::ms_pInventoryMenu->m_kItemList)))->FUN_00825c00(::FUN_00a01860("_current_value")))))))->GetFloat({});
    InventoryMenu::ms_pInventoryMenu->m_kPageStates[idx].m_iScrollOffset = FUN_00ec62c0();
}

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
// Checks indices 25 through 30 of the input interface and returns true if any first value is less than its second value.
// @fnv 0x00780f70
bool __cdecl FUN_00780f70()
{
    for (int index = 25; index < 31; ++index)
    {
        if (((InputInterface*)((*reinterpret_cast<char * *>(&::_g_thePlayer)) + 0xa4))->GetFirstValue(index) <
            ((InputInterface*)((*reinterpret_cast<char * *>(&::_g_thePlayer)) + 0xa4))->GetSecondValue(index))
        {
            return true;
        }
    }
    return false;
}

namespace InventorySelection {
struct Item;
struct Form;
struct Tile
{
};
struct TileRef
{
    Tile** FUN_0073ac90();
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
// On action 29 refreshes the selected item's label, stats, description, ammo and icon; on action 30 resets the description and button text.
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
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*icon->tile.FUN_0073ac90())))->FUN_00a01350(0xfcc, (char *)(path), 1);
                reinterpret_cast<::Tile *>(((*icon->tile.FUN_0073ac90())))->Set(0xfa3, 1);
            }
            else
                reinterpret_cast<::Tile *>(((*icon->tile.FUN_0073ac90())))->Set(0xfa3, 0);
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
    int FUN_00401170();
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
// @fnv 0x00781680
void FUN_00781680_shell::FUN_00781680()
{
    int icurrTabIndex;

    if (InventoryMenu::ms_pActionPointSource)
    {
        if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((InventoryMenu::ms_pActionPointSource))->GetName()))->GetFormType() == 0x19)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[6]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((DAT_011d5178))->GetMenuTitle()))), true);
        }
        else if (reinterpret_cast<::FUN_004bddd0_shell *>((((FUN_004bddd0_t*)InventoryMenu::ms_pActionPointSource)))->FUN_004bddd0(false))
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[6]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(::g_011d460c))->GetMenuTitle()))), true);
        }

        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[6]))->FUN_00a012d0(
            0xfaf,
            reinterpret_cast<::TileListBoxCalls *>((void *)(((TGF*)((::Tile *)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)this)))->FUN_00726070())))))->GetFloat(::InventorySelection::DAT_011d9ebc),
            true);
        m_pTiles[7]->Set(0xfaf, 1);

        m_pTiles[9]->Set(0xfaf,
                         (unsigned char)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((InventoryMenu::ms_pActionPointSource))->GetName()))->GetFormType() != 0x29));
        m_pTiles[19]->Set(0xfaf, 1);

        m_pTiles[8]->Set(0xfaf, reinterpret_cast<::InventoryCheck *>((((FUN_00781860_shell*)this)))->FUN_00781860((::Entry *)(InventoryMenu::ms_pActionPointSource)));
    }
    else
    {
        icurrTabIndex = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab + 0x18;

        if (icurrTabIndex == 0x1a)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[6]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(::g_011d478c))->GetMenuTitle()))), true);
        }
        else
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[6]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(::g_011d3cdc))->GetMenuTitle()))), true);
        }

        m_pTiles[6]->Set(0xfaf, 0);
        m_pTiles[7]->Set(0xfaf, 0);
        m_pTiles[9]->Set(0xfaf, 0);
        m_pTiles[19]->Set(0xfaf, 0);
        m_pTiles[8]->Set(0xfaf, 0);
    }
}
// @fnv 0x00781860
bool InventoryCheck::FUN_00781860(Entry* entry)
{
    bool result5 = false;
    Form* form4 = entry ? ((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) : 0;
    if (entry && ::InventoryStackRecord::GetConditionPercent(reinterpret_cast<::FUN_004bcdb0_shell *>((entry))->FUN_004bcdb0(true)) == 100.0)
        return result5;
    if (entry && form4 && (form4->FUN_00401170() == 40 || form4->FUN_00401170() == 24) &&
        reinterpret_cast<::FUN_004bcdb0_shell *>((entry))->FUN_004bcdb0(true) < 100.0)
    {
        if (((int)(reinterpret_cast<::Callees *>((entry))->FUN_00726070())) > 1)
            result5 = true;
        else
        {
            EntryListNode list6;
            Changes* changes = ((::Changes *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<void * *>(&::_g_thePlayer))))));
            Extra* originalExtra = ((::ExtraNode *)(::FUN_00559450((int *)(entry)))) ? *((::Extra **)(new ((void *)(((::ExtraNode *)(::FUN_00559450((int *)(entry)))))) ::Vec3())) : 0;
            EntryListNode* cleanup = &list6;
            reinterpret_cast<::fnv_004d4bd0::InventoryChangeFilterHost *>((changes))->FilterInventoryChanges(form4, (::fnv_004d4bd0::MatchedChanges *)(::EntryListNode *)(&list6));
            for (EntryListNode* node9 = &list6; node9 && *((::Entry **)(new ((void *)(node9)) ::Vec3())); node9 = ((::EntryListNode *)(reinterpret_cast<::Callees *>((node9))->FUN_00726070())))
            {
                Form* otherForm2 = ((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>(((*((::Entry **)(new ((void *)(node9)) ::Vec3())))))->GetName()));
                Extra* otherExtra8 = ((::ExtraNode *)(::FUN_00559450((int *)((*((::Entry **)(new ((void *)(node9)) ::Vec3())))))))
                                         ? *((::Extra **)(new ((void *)(((::ExtraNode *)(::FUN_00559450((int *)((*((::Entry **)(new ((void *)(node9)) ::Vec3()))))))))) ::Vec3()))
                                         : 0;
                if (!reinterpret_cast<::FUN_004bddd0_shell *>(((*((::Entry **)(new ((void *)(node9)) ::Vec3())))))->FUN_004bddd0(false))
                {
                    if (otherForm2 != form4 ||
                        (::InventoryStackRecord::GetConditionPercent(reinterpret_cast<::FUN_004bcdb0_shell *>(((*((::Entry **)(new ((void *)(node9)) ::Vec3())))))->FUN_004bcdb0(true)) < 100.0 &&
                         otherExtra8 != originalExtra && otherExtra8 && !reinterpret_cast<::FUN_00418ba0_shell *>((otherExtra8))->FUN_00418ba0()))
                        result5 = true;
                }
            }
            while (cleanup && *((::Entry **)(new ((void *)(cleanup)) ::Vec3())))
            {
                delete *((::Entry **)(new ((void *)(cleanup)) ::Vec3()));
                cleanup->FUN_0063f7b0();
            }
        }
    }
    return result5;
}

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

// @fnv 0x00782850
void __cdecl UpdateItemLabel(ItemLabelTile* tile, ItemLabelSource* item)
{
    char label[128];
    if (item)
    {
        if (((int)(reinterpret_cast<::Callees *>((item))->FUN_00726070())) > 1)
        {
            if (reinterpret_cast<::FUN_004bd820_stand *>((item))->FUN_004bd820())
                ::FUN_00406d00(label, 128, "%s+ (%d)", reinterpret_cast<::FUN_004be2d0_shell *>((item))->GetTargetFullName(), ((int)(reinterpret_cast<::Callees *>((item))->FUN_00726070())));
            else
                ::FUN_00406d00(label, 128, "%s (%d)", reinterpret_cast<::FUN_004be2d0_shell *>((item))->GetTargetFullName(), ((int)(reinterpret_cast<::Callees *>((item))->FUN_00726070())));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(label), true);
        }
        tile->Set(0xfaa, 29);
        if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->GetFormType() == 41 || ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->GetFormType() == 24 ||
            ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->GetFormType() == 40)
        {
            if (!reinterpret_cast<::fnv_00967b70::Cls *>((reinterpret_cast<ItemLabelPlayer*>(::_g_thePlayer)))->FUN_00967b70((::fnv_00967b70::ArgObj *)(item)))
                (*((::Tile **)(reinterpret_cast<::InventoryStackRecord *>(&(tile->children))->GetPayloadAddress())))->Set(0xfa9, 127);
            else
                (*((::Tile **)(reinterpret_cast<::InventoryStackRecord *>(&(tile->children))->GetPayloadAddress())))->Set(0xfa9, 255);
        }
        if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))->GetFormType() == 41 &&
            reinterpret_cast<::FUN_008a1710_shell *>((reinterpret_cast<ItemLabelPlayer*>(::_g_thePlayer)))->FUN_008a1710())
        {
            (*((::Tile **)(reinterpret_cast<::FUN_006317a0_struct *>(&(tile->children))->AddEight((int)(((void *)(::FUN_00559450((int *)&(tile->children)))))))))
                ->Set(0xfa3,
                      static_cast<bool>(item && ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName())) ==
                                                    reinterpret_cast<TESBoundObject*>(
                                                        ((::TESAmmo *)(reinterpret_cast<::AmmoOwner *>((reinterpret_cast<::FUN_008a1710_shell *>((reinterpret_cast<ItemLabelPlayer*>(::_g_thePlayer)))->FUN_008a1710()))->FUN_00525980((::AmmoActor *)(::Actor *)(reinterpret_cast<Actor*>(::_g_thePlayer))))))));
        }
        else
        {
            (*((::Tile **)(reinterpret_cast<::FUN_006317a0_struct *>(&(tile->children))->AddEight((int)(((void *)(::FUN_00559450((int *)&(tile->children)))))))))
                ->Set(0xfa3, item && reinterpret_cast<::FUN_004bddd0_shell *>((item))->FUN_004bddd0(false) ? 1 : 0);
        }
    }
}

// 0x00780d60  unit_65921382d98c.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, no stack args (ret): menu refresh/close path.

void __cdecl FUN_00782a90();
void __cdecl FUN_007832a0(void* tile, int index);

struct Sh006815c0
{
};
struct Sh00726070
{
};
struct Sh00a01230
{
};
struct Sh007314c0
{
    char pad[0x64];
};
struct Sh005ae3d0
{
    void FUN_005ae3d0(void** pp);
};
struct Sh004bddd0
{
};
struct Sh0088c650
{
};
struct Sh0088c790
{
};


class SettingString
{
  public:
};

struct GpEmb75
{
    virtual int v0();
    virtual int v1();
    virtual int v2(int arg);
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7(int arg);
};
struct Gp75
{
    char pad00[0xa4];
    GpEmb75 emb;
};

struct Menu75b
{
    char pad00[0xb8];
    Sh007314c0 lb;
    Sh005ae3d0 list;

    void FUN_00780d60();
};

// @fnv 0x00780d60
void Menu75b::FUN_00780d60()
{
    void* a = (void*)((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()));
    void* b = ((void *)(::FUN_00559450((int *)((*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource)))))) ? (void*)*((void **)(new ((void *)(((Sh006815c0*)((void *)(::FUN_00559450((int *)((*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource))))))))) ::Vec3())) : 0;

    if (reinterpret_cast<::FUN_00a01230_shell *>((((Sh00a01230*)reinterpret_cast<::Callees *>((((Sh00726070*)this)))->FUN_00726070())))->IsTraitNonZero(::InventorySelection::DAT_011d9ebc))
    {
        reinterpret_cast<::LBList_7314c0 *>(&(lb))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(FUN_007832a0), 0, 0x7fffffff);
    }

    void* c = (void*)((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()));
    list.FUN_005ae3d0(&c);

    if ((((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName())) == ((unsigned int)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0)))) || ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName())) == ((unsigned int)(::FUN_004839c0(0xccef2)))) &&
        ((Gp75*)::_g_thePlayer)->emb.v2(0x10) == ((Gp75*)::_g_thePlayer)->emb.v7(0x10))
    {
        ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::SettingString *>(&::g_011d2af0))))->IsDLCAvailable()))), 0, (int)(0), (int)(0), 2.0f, false);
    }
    else if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName())) == ((unsigned int)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x15)))) && !FUN_00780f70())
    {
        ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::SettingString *>(&::g_011d2af0))))->IsDLCAvailable()))), 0, (int)(0), (int)(0), 2.0f, false);
    }
    else if (!reinterpret_cast<::FUN_004bddd0_shell *>((((Sh004bddd0*)(*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource)))))->FUN_004bddd0(false))
    {
        reinterpret_cast<::FUN_0088c650_shell *>((((Sh0088c650*)::_g_thePlayer)))->FUN_0088c650((::TESBoundObject *)(a), (int)reinterpret_cast<::Callees *>((((Sh00726070*)(*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource)))))->FUN_00726070(), (::ExtraDataList *)(b), false, false, true);
    }
    else
    {
        reinterpret_cast<::s88c790::Actor *>((((Sh0088c790*)::_g_thePlayer)))->FUN_0088c790((int)(a), (int)reinterpret_cast<::Callees *>((((Sh00726070*)(*reinterpret_cast<void * *>(&::InventoryMenu::ms_pActionPointSource)))))->FUN_00726070(), (int)(b), false, false, true);
    }

done:
    FUN_00782a90();
}

namespace fnv_00780140 {
class VTTile
{
  public:
};

class VTForm
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
    virtual bool IsDeleted();  // +0x94
    int FUN_00401170();
};

struct VTPoint3
{
    float x, y, z;
};

struct VTItemData
{
};
struct VTItemNode
{
};

class VTTarget
{
  public:
};

class VTAction
{
  public:
    VTAction(VTForm* pkTargetNum, VTTile* pkTile);
    int unk00;
    int unk04;
    int unk08;
};

struct VTActionList
{
};
struct VTWeaponInfo
{
};

class VTProcess
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
    virtual VTWeaponInfo* GetWeaponInfo(int iHand);  // +0x148
    virtual VTActionList* GetActionList(int iFlag);  // +0x14c
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void PerformAction(VTAction* pkAction);  // +0x168
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
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void SetQueued(int iA, int iB, int iC);  // +0x580
};

struct VTWeapon
{
};
struct VTAnim;

class VTPlayer
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
    virtual void ResetIdle();  // +0x3c4
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void PlayAttack(VTAnim* pkAnimOut, int iType, bool bLeft, int iFlag);  // +0x3ec
};

struct VTCombat
{
};

struct VTCallbackList
{
};
struct VTSelection
{
};
struct VTTargetList
{
    void FUN_005ae3d0(VTForm* const& pkTargetNum);
};

struct VTCamera
{
};
struct VTSubMenu
{
};
class VTInterface
{
  public:
    int unk000[309];
    VTSubMenu m_kSubMenu;  // +0x4d4
};

struct VTSetting
{
};
struct VTCounter
{
};

struct VTSoundHandle
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~VTSoundHandle();
};
class VTAudio
{
  public:
    VTSoundHandle FUN_00ad7550(const char* pcName, int iFlags);
};

class VTMenu
{
  public:
    int unk00[10];
    VTTile* m_apTiles[23];  // +0x28
    int m_iMode;            // +0x84
    int unk88[12];
    VTCallbackList m_kCallbackList;  // +0xb8
    int unkbc[11];
    VTSelection m_kSelection;  // +0xe8
    int unkec[12];
    VTTargetList m_kTargets;  // +0x11c

    void FUN_00780140(int m_uiSoundID, VTTile* pkTile);
};


void FUN_00782470(int iFlag);
void FUN_00782a90();
void FUN_00782620();
void UpdateItemLabel(Tile* pkTile);
void IsNotFormType2E();

// Dispatches by the integer argument, handling mode changes and menu actions including item, drop, and attack paths with state checks.
// @fnv 0x00780140
void VTMenu::FUN_00780140(int m_uiSoundID, VTTile* pkTile)
{
    if (!pkTile && m_uiSoundID >= 0 && m_uiSoundID < 0x17)
        pkTile = m_apTiles[m_uiSoundID];
    switch (m_uiSoundID)
    {
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
        if (m_iMode != m_uiSoundID - 0x18)
        {
            int iOldMode = m_iMode;
            if (reinterpret_cast<::FUN_00a01230_shell *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero(::InventoryMenu::ms_iKeyringOpenTileID))
                reinterpret_cast<::Tile *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(::InventoryMenu::ms_iKeyringOpenTileID, 0);
            reinterpret_cast<::FUN_00781b10_shell *>(this)->ClearActionPointSource();
            UpdateCurrentValue();
            m_iMode = m_uiSoundID - 0x18;
            reinterpret_cast<::Tile *>((m_apTiles[13]))->Set(::InventoryMenu::ms_iCurrentTabTileID, m_iMode);
            reinterpret_cast<::FORenderedMenu *>((((::fnv_00780140::VTCamera *)(reinterpret_cast<::Interface *>((((VTInterface*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->GetPipboyManager()))))->StartBurst(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00780140::VTSetting *>(&::g_011db458)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00780140::VTSetting *>(&::g_011db37c)))))), 0.5f);
            reinterpret_cast<::FUN_00780be0_shell *>((((VTInterface*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->SetByte13(m_uiSoundID);
            reinterpret_cast<::ListBoxImpl *>(&(m_kCallbackList))->ApplyFilter((bool (*)(void *))(FUN_00782620));
            reinterpret_cast<::LBList_7314c0 *>(&(m_kCallbackList))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(FUN_00780c00), -1, 0x7fffffff);
            ::FUN_007800c0();
            FUN_00782470(1);
        }
        if (m_uiSoundID == 0x18)
            reinterpret_cast<::Tile *>((m_apTiles[19]))->Set(0xfa3, 1);
        else if (m_uiSoundID == 0x1c)
        {
            reinterpret_cast<::TutorialMessageGate718 *>(&(((VTInterface*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->m_kSubMenu))->FUN_00718630(0x24, ::InventoryMenu::FUN_0077ff80(), 0x1f4);
            reinterpret_cast<::LBList_7314c0 *>(&(((VTMenu*)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->m_kCallbackList))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(UpdateItemLabel), 0, 0x7fffffff);
        }
        else
        {
            if (m_uiSoundID == 0x19)
                reinterpret_cast<::TutorialMessageGate718 *>(&(((VTInterface*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->m_kSubMenu))->FUN_00718630(0x23, ::InventoryMenu::FUN_0077ff80(), 0x200);
            reinterpret_cast<::Tile *>((m_apTiles[19]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((m_apTiles[20]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((m_apTiles[22]))->Set(0xfa3, 0);
        }
        break;
    case 8:
        if ((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)))
        {
            ::s717280::FUN_00717280(0x24);
            UpdateCurrentValue();
            ::fnv_007b7020::FUN_007b7020((int)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))));
        }
        break;
    case 19:
        if ((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)) && ((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))->FUN_00401170() == 0x28)
        {
            ::s717280::FUN_00717280(0x24);
            UpdateCurrentValue();
            if (((::fnv_00780140::VTItemNode *)(::FUN_00559450((int *)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)))))) && !*((::fnv_00780140::VTItemData **)(new ((void *)(((::fnv_00780140::VTItemNode *)(::FUN_00559450((int *)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)))))))) ::Vec3())))
            {
                VTCombat* pkCombat = ((::fnv_00780140::VTCombat *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(::fnv_00780140::VTPlayer *)((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer))))));
                reinterpret_cast<::ChangesShell *>((pkCombat))->AddItemExtraData((::BoundShell *)(::fnv_00780140::VTForm *)(((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))), (int)(((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->FUN_00726070()))),
                                           (int)((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer))), (::ExtraShell *)(0), (::ExtraNodeShell **)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))));
            }
            ::FUN_00784710((::Entry78 *)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))), 1);
        }
        break;
    case 29:
        if ((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)) && !reinterpret_cast<::FUN_00a01230_shell *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero(::InventoryMenu::ms_iKeyringOpenTileID) &&
            ((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))->FUN_00401170() != 0x29)
        {
            bool bResume = false;
            if (reinterpret_cast<::HotkeyWheelDisplay *>(&(m_kSelection))->GetVisible())
            {
                if (!::FUN_004b71d0())
                {
                    if ((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)) && reinterpret_cast<::FUN_004bcdb0_shell *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->FUN_004bcdb0(1) == 0.0)
                        ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>((((VTSetting*)&(*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d3810)))))->GetMenuTitle()))), 2, (int)(0), (int)("UIVATSInsufficientAP"),
                                              2.0f, 0);
                    else if (!reinterpret_cast<::FUN_00a01230_shell *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero(::InventorySelection::DAT_011d9ebc) ||
                             ((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))->FUN_00401170() == 0x19)
                        ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>((((VTSetting*)&(*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d1e18)))))->GetMenuTitle()))), 2, (int)(0), (int)("UIVATSInsufficientAP"),
                                              2.0f, 0);
                    else
                    {
                        reinterpret_cast<::ThiS *>(&(m_kSelection))->FUN_007019e0((::ObjRef *)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))));
                        m_kTargets.FUN_005ae3d0(((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName())));
                        FUN_00782a90();
                    }
                }
            }
            else
            {
                reinterpret_cast<::Menu75b *>(this)->FUN_00780d60();
                bResume = true;
            }
            if (bResume)
            {
                reinterpret_cast<::FUN_00950030_shell *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_00950030();
                ((::fnv_00780140::VTProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->GetBaseTexture()))->SetQueued(1, 0, 0);
                ((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))->ResetIdle();
            }
        }
        else if (((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))->FUN_00401170() == 0x29)
        {
            VTForm* pkTargetNum = ((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()));
            if (!pkTargetNum || !reinterpret_cast<::FUN_00a01230_shell *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero(::InventorySelection::DAT_011d9ebc))
                break;
            VTAction* pkAction = new VTAction(((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName())), ((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->FUN_00726070())));
            VTProcess* pkProcess = ((::fnv_00780140::VTProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->GetBaseTexture()));
            VTWeapon* pkWeaponOut = ((::fnv_00780140::VTWeapon *)(reinterpret_cast<::FUN_006044c0_shell *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_006044c0()));
            VTAnim* pkAnimOut = ((::fnv_00780140::VTAnim *)(reinterpret_cast<::FUN_008a1710_shell *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_008a1710()));
            pkProcess->PerformAction(pkAction);
            reinterpret_cast<::CombatProcedure *>((pkProcess->GetActionList(0)))->Initialize({});
            reinterpret_cast<::ActorSoundStub *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->PlayActorSound((int)(((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()))), 1, 0);
            int iType = (pkWeaponOut && !((bool)(reinterpret_cast<::FUN_004938c0_class *>((pkWeaponOut))->GetByteAt384()))) ? 0 : 2;
            bool bLeft = reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((pkProcess->GetWeaponInfo(2)))->HasEffect({});
            ((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))->PlayAttack(pkAnimOut, iType, bLeft, 0);
            m_kTargets.FUN_005ae3d0(((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName())));
            FUN_00782a90();
        }
        break;
    case 30:
        if (!reinterpret_cast<::HotkeyWheelDisplay *>(&(m_kSelection))->GetVisible())
        {
            UpdateCurrentValue();
            reinterpret_cast<::Tile *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(::InventoryMenu::ms_iKeyringOpenTileID, 1);
            reinterpret_cast<::ListBoxImpl *>(&(m_kCallbackList))->ApplyFilter((bool (*)(void *))(IsNotFormType2E));
            reinterpret_cast<::LBList_7314c0 *>(&(m_kCallbackList))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(FUN_00780c00), -1, 0x7fffffff);
            reinterpret_cast<::FUN_00781b10_shell *>(this)->ClearActionPointSource();
            ::FUN_007800c0();
        }
        else
            ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>((((VTSetting*)&(*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d1e18)))))->GetMenuTitle()))), 0,
                                  (int)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"),
                                  (int)("UIVATSInsufficientAP"), 2.0f, 0);
        break;
    case 10:
        UpdateCurrentValue();
        reinterpret_cast<::Tile *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(::InventoryMenu::ms_iKeyringOpenTileID, 0);
        reinterpret_cast<::ListBoxImpl *>(&(m_kCallbackList))->ApplyFilter((bool (*)(void *))(FUN_00782620));
        reinterpret_cast<::LBList_7314c0 *>(&(m_kCallbackList))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(FUN_00780c00), -1, 0x7fffffff);
        ::FUN_007800c0();
        break;
    case 7:
        if ((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)))
        {
            VTPoint3 kPos = (*reinterpret_cast<::fnv_00780140::VTPoint3 *>((void *)&::NiPoint3::ZERO));
            VTForm* pkRefOut = ((::fnv_00780140::VTForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->GetName()));
            VTItemData* pkItem = ((::fnv_00780140::VTItemNode *)(::FUN_00559450((int *)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)))))) ? *((::fnv_00780140::VTItemData **)(new ((void *)(((::fnv_00780140::VTItemNode *)(::FUN_00559450((int *)((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource)))))))) ::Vec3())) : 0;
            if (reinterpret_cast<::FUN_00a01230_shell *>((((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero(::InventoryMenu::ms_iKeyringOpenTileID))
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_00780140::VTSoundHandle &)(((::fnv_00780140::VTAudio *)(::FUN_00453a70()))->FUN_00ad7550("UIVATSInsufficientAP", 0x121)))->FUN_00ad8830(false);
            else if (pkRefOut->IsDeleted())
                ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00780140::VTSetting *>(&::g_011d47a4))))->GetMenuTitle()))), 2, (int)(0), (int)(0), 2.0f, 0);
            else if (reinterpret_cast<::FUN_008a7570_shell *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_008a7570() != -1 && reinterpret_cast<::FUN_004bddd0_shell *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->FUN_004bddd0(0))
                ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00780140::VTSetting *>(&::g_011d22c8))))->GetMenuTitle()))), 2, (int)(0), (int)(0), 2.0f, 0);
            else if (reinterpret_cast<::OwnerObject *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_009337b0())
                ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00780140::VTSetting *>(&::g_011d43e4))))->GetMenuTitle()))), 2, (int)(0), (int)(0), 2.0f, 0);
            else if (pkItem && reinterpret_cast<::FUN_00418b10_shell *>((pkItem))->FUN_00418b10() && reinterpret_cast<::FUN_00418ab0_shell *>((pkItem))->FUN_00418ab0(0))
                ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00780140::VTSetting *>(&::g_011d31f8))))->GetMenuTitle()))), 2, (int)(0), (int)(0), 2.0f, 0);
            else if (!reinterpret_cast<::fnv_009614b0::Player *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_009614b0((::fnv_009614b0::Bound *)(pkRefOut), (::fnv_009614b0::V3 *)(::fnv_00780140::VTPoint3 *)(&kPos), 1, 1))
                ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00780140::VTSetting *>(&::g_011d3d30))))->GetMenuTitle()))), 2, (int)(0), (int)(0), 2.0f, 0);
            else
            {
                if ((int)((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->FUN_00726070())) > *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00780140::VTCounter *>(&::g_011d2418)))))))
                    ::CreateQuantityMenu((int)(((::fnv_00780140::VTTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::fnv_00780140::VTTarget * *>(&::InventoryMenu::ms_pActionPointSource))))->FUN_00726070()))), DropInventoryItem, 0x7fffffff);
                else
                    DropInventoryItem(1);
                reinterpret_cast<::FUN_00950030_shell *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->FUN_00950030();
                ((::fnv_00780140::VTProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->GetBaseTexture()))->SetQueued(1, 0, 0);
                ((VTPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))->ResetIdle();
            }
        }
    }
}
}  // namespace fnv_00780140

struct FilterForm
{
    int FUN_00401170();
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual bool IsQuestItem();
};
class TESForm;
class TESBipedModelForm
{
  public:
public:
    static ::TESBipedModelForm *GetFormAsBipedModel(const ::TESForm *);
};
struct FilterPlayer
{
};
struct FilterList
{
};

// Returns whether a form fails the current tab's checks, including type, item, and condition-index checks.
// @fnv 0x00782620
bool __cdecl FUN_00782620(Entry* entry)
{
    if ((*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))
    {
        FilterForm* form4 = entry ? (FilterForm*)((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) : 0;
        int tab3 = ((InventoryMenu*)(*reinterpret_cast<int *>(&::InventoryMenu::ms_pInventoryMenu)))->m_iCurrentTab + 24;
        if (!form4)
            return tab3 != 27;
        int type = form4->FUN_00401170();
        TESBipedModelForm* biped3 = ::TESBipedModelForm::GetFormAsBipedModel((TESForm*)form4);
        if ((biped3 && !reinterpret_cast<::FUN_00480d90_shell *>((biped3))->FUN_00480d90()) || ::FUN_00481f10((::TESObject *)(form4)) ||
            (form4->IsQuestItem() && !reinterpret_cast<::FUN_004be580_class *>((((FilterPlayer*)(*reinterpret_cast<char * *>(&::_g_thePlayer)))))->GetByteAt240()) || type == 46)
            return true;
        switch (tab3)
        {
        case 24:
            return type != 40;
        case 25:
            return type != 24 && type != 26;
        case 26:
            return type != 29 && type != 47 && type != 25;
        case 27:
            return type == 40 || type == 24 || type == 26 || type == 29 || type == 47 || type == 41 || type == 25;
        case 28:
            if (type != 41)
                return true;
            else
            {
                FilterList* list = ((::FilterList *)(::TESForm::LookupFormByEditorID((const char *)(int *)(&(*reinterpret_cast<int *>(&::DAT_010722f4))))));
                FilterForm* item = form4;
                if (list && reinterpret_cast<::FUN_0058ff60_shell *>((list))->GetConditionIndex((::TESForm *)(item)) >= 0)
                    return true;
                return false;
            }
        }
    }
    return true;
}

struct FUN_0073ac90_shell
{
    Tile** __thiscall FUN_0073ac90();
};

// Clears the static action point source and resets several inventory menu tiles and a related tile to 0.
// @fnv 0x00781b10
void FUN_00781b10_shell::ClearActionPointSource()
{
    InventoryMenu::ms_pActionPointSource = 0;

    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[12]->Set(0xFA3, 0);
    reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<InventoryMenu*>(this)->m_pTiles[11]))->FUN_00a012d0(0xFA3, 0.0f, false);
    reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<InventoryMenu*>(this)->m_pTiles[20]))->FUN_00a012d0(0xFA3, 0.0f, false);
    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[22]->Set(0xFA3, 0);

    (*reinterpret_cast<FUN_0073ac90_shell*>(
          reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x3C)) + 4)
          ->FUN_0073ac90())
        ->Set(0xFA3, 0);

    reinterpret_cast<FUN_00781680_shell*>(this)->FUN_00781680();
}
