// include/ListBox_PerkRankData___.h: declares ListBox_PerkRankData___
#ifndef FNV_LISTBOX_PERKRANKDATA____H
#define FNV_LISTBOX_PERKRANKDATA____H

#include "layout_support.h"
#include "ListBoxBase.h"
class ListBox_PerkRankData___ : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem_PerkRankData___*> bSSimpleList_ListBoxItem_PerkRankData______Component;  // +0x4
    Tile* m_pListTile;                                                                                // +0xC
    Tile* m_pSelectedTile;                                                                            // +0x10
    Tile* m_pHighlightedTile;                                                                         // +0x14
    const char* pTemplateName;                                                                        // +0x18
    unsigned short m_usSelectedIndex;                                                                 // +0x1C
    unsigned short layoutPadding1E;
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned short layoutPadding2E;
};
#endif
