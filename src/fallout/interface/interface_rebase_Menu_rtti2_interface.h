// Source layout: Menu. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_TABLINE_MENU_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_TABLINE_MENU_H
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "interface_rebase_layout_support.h"
class Menu
{
  public:
    virtual ~Menu();  // the original class is polymorphic (rtti_variants.py)
  public:
    static bool IsMenuVisible(Interface::enumMenus);
    TileMenu* pMenu;                                        // +0x4
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;  // +0x8
    Tile* m_pMenuTile;                                        // +0x10
    int m_iModalMenuId;                                     // +0x14
    int m_iSecondaryValue;                                  // +0x18
    bool m_bIsSpecial;                                      // +0x1C
    bool m_bVisible;                                        // +0x1D
    unsigned char layoutPadding1E[2];
    int m_iMenuId;                       // +0x20
    Interface__FADE_STATE m_eFadeState;  // +0x24
};
#endif
