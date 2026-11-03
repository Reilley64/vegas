// Recovered unit header: fallout/interface/menus/inventorymenu.h
#ifndef FNV_INVENTORYMENU_UNIT_H
#define FNV_INVENTORYMENU_UNIT_H

#include "layout_support.h"
#include "InventoryMenu__sPageState.h"
#include "ListBox_ItemChange___.h"
#include "HotkeyWheelDisplay.h"
#include "Menu.h"

class InventoryMenu : public Menu
{
  public:
    Tile* m_pTiles[23];                              // +0x28
    int m_iCurrentTab;                               // +0x84
    InventoryMenu__sPageState m_kPageStates[6];      // +0x88
    ListBox_ItemChange___ m_kItemList;               // +0xB8
    HotkeyWheelDisplay m_kMenuData;                        // +0xE8
    BSSimpleList<TESBoundObject*> m_kHotkeyObjects;  // +0x11C
    int GetClass();
    void AssignTileByID(int id, Tile* tile);
};

#endif
