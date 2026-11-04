// Source layout: ItemModMenu. PC corrections are in generate_headers.py.
#ifndef FNV_ITEMMODMENU_H
#define FNV_ITEMMODMENU_H

#include "layout_support.h"
#include "ListBox_ItemChange___.h"
#include "Menu.h"
class ItemModMenu : public Menu
{
  public:
    Tile* m_pTiles[14];                 // +0x28
    ListBox_ItemChange___ m_kItemList;  // +0x60
    int GetClass();
};
#endif
