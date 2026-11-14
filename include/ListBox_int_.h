// Source layout: ListBox<int>. PC corrections are in generate_headers.py.
#ifndef FNV_LISTBOX_INT__H
#define FNV_LISTBOX_INT__H
#include "layout_support.h"
#include "ListBoxBase.h"
class ListBox_int_ : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem_int_*> bSSimpleList_ListBoxItem_int____Component;  // +0x4
    Tile* m_pListTile;                                                          // +0xC
    Tile* m_pSelectedTile;                                                      // +0x10
    Tile* m_pHighlightedTile;                                                   // +0x14
    const char* pTemplateName;                                                  // +0x18
    unsigned short m_usSelectedIndex;                                           // +0x1C
    unsigned short layoutPadding1E;
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned short layoutPadding2E;
};
#endif
