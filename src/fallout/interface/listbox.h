// fallout/interface/listbox.h: declares StartMenu, TileListBoxCalls
#ifndef FNV_LISTBOX_MATCH_UNIT_H
#define FNV_LISTBOX_MATCH_UNIT_H


#include "fnv/decl/Cls_764e40.h"
#include "fnv/decl/Cls_764ef0.h"
#include "fnv/decl/FUN_00730e20_cls.h"
#include "fnv/decl/FUN_007a6bd0_shell.h"
#include "fnv/decl/FUN_007a6c80_shell.h"
#include "fnv/decl/FUN_007a79b0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/LBList.h"
#include "fnv/decl/ListBoxZ.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/SelectionList.h"
#include "fnv/decl/fnv_007d9660__SelectionList.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a08000.h"
#include "listbox_decls.h"
#include "layout_support.h"
#include "ListBoxBase.h"
#include "listbox_types_Tile.h"
#include "listbox_types_BGSSaveLoadFileEntry.h"

class BGSNote;
class InventoryStackRecord;
class StartMenu
{
  public:
    class Option;
};
template <class T> class ListBoxItem;

template <class T> class ListBox : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem<T>*> items;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    unsigned char padding1E[2];
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;
    unsigned char padding2E[2];

    unsigned int AddItem(unsigned int mask);
    bool Highlight(Tile* tile);
    void ResetItems();
    bool IsEnabled();
    unsigned int GetVisibleEntryCount();
    void Initialize(Tile* container, const char* templateName);
    bool SetSelection(Tile* tile);
    bool SetSelection(Tile* tile, int mode);
    T GetSelectedData();
    T GetSelectedData(Tile* tile);
};

class TileListBoxCalls : public Tile
{
  public:
    float GetFloat(int trait);
};


extern "C" const char kListBoxEnabled[] = "_enabled";
extern "C" const char kListBoxNumFiltered[] = "_number_of_visible_items";
extern "C" const char kListBoxScrollbar[] = "child(lb_scrollbar)";

template <>
// @fnv 0x007d87b0
unsigned int ListBox<BGSSaveLoadFileEntry*>::GetVisibleEntryCount()
{
    return m_pListTile != 0
               ? (unsigned int)((TileListBoxCalls*)m_pListTile)->GetFloat(::FUN_00a00940(kListBoxNumFiltered, -1))
               : 0;
}

template <>
// @fnv 0x007d8d60
bool ListBox<BGSSaveLoadFileEntry*>::SetSelection(Tile* tile)
{
    return reinterpret_cast<::fnv_007d9660::SelectionList *>(this)->FUN_007d9660((::fnv_007d9660::SelectionTile *)(tile), 0);
}

template <>
// @fnv 0x007a1910
PerkForm* ListBox<PerkForm*>::GetSelectedData()
{
    return ((::PerkForm *)(reinterpret_cast<::LBList *>(this)->FindItemData(m_pSelectedTile)));
}

template <>
// @fnv 0x0075a0d0
void ListBox<unsigned int>::Initialize(Tile* container, const char* templateName)
{
    m_pListTile = container;
    pTemplateName = templateName;
    m_pHighlightedTile = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(m_pListTile), kListBoxScrollbar)));
}

template <>
// @fnv 0x007cc5d0
unsigned int ListBox<StartMenu::Option*>::AddItem(unsigned int mask)
{
    return ((unsigned int)m_pListTile & mask) != 0;
}

// @fnv 0x00418900
SoundPlaybackHandle& SoundPlaybackHandle::operator=(const SoundPlaybackHandle& other)
{
    soundID = other.soundID;
    success = other.success;
    state = other.state;
    return *this;
}

template <>
// @fnv 0x007d7630
bool ListBox<BGSSaveLoadFileEntry*>::IsEnabled()
{
    return m_pListTile && reinterpret_cast<::sa040a0::Owner *>((m_pListTile))->IsAllChildrenFlag0();
}

template <>
// @fnv 0x00730ed0
bool ListBox<InventoryStackRecord*>::Highlight(Tile* tile)
{
    if (reinterpret_cast<::FUN_00730e20_cls *>(this)->FUN_00730e20() && (!tile || (reinterpret_cast<::ListOwner *>((((ListBox_int_*)this)))->ContainsKey((int)(tile)) &&
                                  reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        reinterpret_cast<::ListBoxZ *>(this)->FUN_0071a740();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x00764a00
bool ListBox<int>::Highlight(Tile* tile)
{
    if (reinterpret_cast<::Cls_764e40 *>(this)->FUN_00764e40() && (!tile || (reinterpret_cast<::ListOwner *>((((ListBox_int_*)this)))->ContainsKey((int)(tile)) &&
                                  reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        reinterpret_cast<::Cls_764ef0 *>(this)->UpdateHighlightTile();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x007a3170
bool ListBox<BGSNote*>::Highlight(Tile* tile)
{
    if (reinterpret_cast<::FUN_007a6bd0_shell *>(this)->FUN_007a6bd0() && (!tile || (reinterpret_cast<::ListOwner *>((((ListBox_int_*)this)))->ContainsKey((int)(tile)) &&
                                  reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        reinterpret_cast<::FUN_007a6c80_shell *>(this)->UpdateHighlightBox();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x007a4ce0
bool ListBox<BGSQuestObjective*>::Highlight(Tile* tile)
{
    if (reinterpret_cast<::FUN_007a79b0_shell *>(this)->FUN_007a79b0() && (!tile || (reinterpret_cast<::ListOwner *>((((ListBox_int_*)this)))->ContainsKey((int)(tile)) &&
                                  reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        reinterpret_cast<::SelectionList *>(this)->UpdateSelectionState();
        return true;
    }
    else
    {
        return false;
    }
}

#endif
