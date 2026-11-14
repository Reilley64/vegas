// Source layout: RepairMenu. PC corrections are in generate_headers.py.
#ifndef FNV_REPAIRMENU_DECLS_H
#define FNV_REPAIRMENU_DECLS_H

#include "layout_support.h"
#include "ListBox_ItemChange___.h"
#include "Menu.h"
class RepairMenu : public Menu
{
  public:
    Tile* m_pTiles[13];                   // +0x28
    ListBox_ItemChange___ m_kRepairList;  // +0x5C
    int GetClass();
    void AssignTileByID(int tileID, Tile* tile);
};
#endif
