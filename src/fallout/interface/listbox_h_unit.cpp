// fallout/interface/listbox_h_unit.cpp: Helper, xEntryMenu, SomeClass (11 functions)

#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cls_764e40.h"
#include "fnv/decl/Cls_764ef0.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_007242c0_shell.h"
#include "fnv/decl/FUN_00730e20_cls.h"
#include "fnv/decl/FUN_007a28c0.h"
#include "fnv/decl/FUN_007a4470_cls.h"
#include "fnv/decl/FUN_007a6b00_shell.h"
#include "fnv/decl/FUN_007a6bd0_shell.h"
#include "fnv/decl/FUN_007a6c80_shell.h"
#include "fnv/decl/FUN_007a78e0_cls.h"
#include "fnv/decl/FUN_007a79b0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/LBList.h"
#include "fnv/decl/ListBoxZ.h"
#include "fnv/decl/ListBox_71ad30.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/ScrollList.h"
#include "fnv/decl/ScrollListHost.h"
#include "fnv/decl/SelectionList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_007d9660__SelectionList.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011d8000.h"
#include "listbox.h"

struct Helper
{
    void FUN_007308e0();
    void* FUN_00731580(unsigned int flags);
};
struct WeatherEntry;
typedef int(__cdecl* CmpFunc)(WeatherEntry*, WeatherEntry*);
struct ShellTmp
{
    int _pad;
    BSSimpleList<WeatherEntry*> _list;
    void FUN_007a2e00(CmpFunc a1);
};
// @fnv 0x007a2e00
void ShellTmp::FUN_007a2e00(CmpFunc pCompare)
{
    reinterpret_cast<::ItemChangeList *>(&(_list))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(pCompare));
    reinterpret_cast<::FUN_007a6b00_shell *>(this)->AssignTileIndices();
}

struct WeatherEntry;
struct Unk007a78e0
{
};
struct Holder007a49b0
{
    int _pad;
    BSSimpleList<WeatherEntry*> _list;
    void SortWeatherList(int (*)(WeatherEntry*, WeatherEntry*));
};
// Sorts the weather entry list using the given comparison function, then calls ProcessEntries on this object.
// @fnv 0x007a49b0
void Holder007a49b0::SortWeatherList(int (*a1)(WeatherEntry*, WeatherEntry*))
{
    reinterpret_cast<::ItemChangeList *>(&(_list))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(a1));
    reinterpret_cast<::FUN_007a78e0_cls *>((((Unk007a78e0*)this)))->ProcessEntries();
}

struct DummyClass
{
    void* FUN_007a6160(unsigned int);
};
// Calls FUN_007a28c0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x007a6160
void* DummyClass::FUN_007a6160(unsigned int flags)
{
    reinterpret_cast<::FUN_007a28c0 *>(this)->FUN_007a28c0::~FUN_007a28c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_007a61c0
{
    void* FUN_007a61c0(unsigned int);
};
// Calls FUN_007a4470, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007a61c0
void* S_007a61c0::FUN_007a61c0(unsigned int flags)
{
    reinterpret_cast<::FUN_007a4470_cls *>(this)->FUN_007a4470_cls::~FUN_007a4470_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

class ListItemTile
{
  public:
    virtual ~ListItemTile();
};
class ListItemData
{
  public:
    ~ListItemData();
};
template <class T> class ListBoxItem
{
  public:
    ListItemTile* tile;
    T data;
};
struct ListNodeCalls
{
};
struct TileValueCalls
{
};
class FUN_007308e0 : public ListBox<ListItemData*>
{
  public:
    void FUN_00730950();
public:
    ~FUN_007308e0();
};
// @fnv 0x00731580
void* Helper::FUN_00731580(unsigned int flags)
{
    reinterpret_cast<::FUN_007308e0 *>(this)->FUN_007308e0::~FUN_007308e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00730950
void FUN_007308e0::FUN_00730950()
{
    while (items.m_pkNext && ((::ListBoxItem< ::ListItemData *> *)(new ((void *)(items.m_pkNext)) ::Vec3())))
    {
        BSSimpleList<ListBoxItem<ListItemData*>*>* next = ((::BSSimpleList< ::ListBoxItem< ::ListItemData *> *> *)(reinterpret_cast<::Callees *>((items.m_pkNext))->FUN_00726070()));
        if (!s_bAllowDetach)
            delete ((::ListBoxItem< ::ListItemData *> *)(new ((void *)(items.m_pkNext)) ::Vec3()))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete ((::ListBoxItem< ::ListItemData *> *)(new ((void *)(items.m_pkNext)) ::Vec3()))->data;
        delete ((::ListBoxItem< ::ListItemData *> *)(new ((void *)(items.m_pkNext)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((((ListNodeCalls*)items.m_pkNext)))->Initialize((::CombatController *)(0));
        delete items.m_pkNext;
        items.m_pkNext = next;
    }
    if (items.m_item)
    {
        if (!s_bAllowDetach)
            delete items.m_item->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete items.m_item->data;
        delete items.m_item;
    }
    items.m_item = 0;
    m_usSelectedIndex = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        reinterpret_cast<::FUN_00a012d0_t *>((((TileValueCalls*)m_pListTile)))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::ListBox_71ad30 *>(this)->UpdateScrollPages();
    m_pSelectedTile = 0;
    reinterpret_cast<::ListBoxZ *>(this)->FUN_0071a740();
}

template <> class ListBoxItem<unsigned int>
{
  public:
    Tile* pTile;
    unsigned int data;
    bool m_bFiltered;
};

struct LB_00730f40 : BSSimpleList<ListBoxItem<unsigned int>*>
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Tile* GetTileAt(unsigned int index, bool b);
    TileListBoxCalls* m_pListTile;
    TileListBoxCalls* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    Tile* FUN_00730f40(int event);
};

class xEntryObj
{
  public:
    virtual ~xEntryObj();
};

class InventoryStackRecord
{
  public:
    int m_i0;
    ~InventoryStackRecord();
public:
    static float RoundToNearestStep(float, float);
};
// Computes a candidate tile from the event and returns it when it differs from the selected tile.
// @fnv 0x00730f40
Tile* LB_00730f40::FUN_00730f40(int event)
{
    Tile* selected = 0;
    int delta = 0;
    switch (event)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = m_pListTile
                    ? (int)::InventoryStackRecord::RoundToNearestStep(
                          -m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                    : 0;
        break;
    case 16:
        delta = m_pListTile
                    ? (int)::InventoryStackRecord::RoundToNearestStep(
                          m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                    : 0;
        break;
    }
    if (reinterpret_cast<::FUN_00730e20_cls *>(this)->FUN_00730e20() && delta && m_usSelectedIndex)
    {
        int index = m_usSelectedIndex - 1;
        int last;
        if (m_pSelectedTile)
        {
            int current = (int)m_pSelectedTile->GetFloat(0xfac);
            last = current + delta;
            if (last < 0)
                last = 0;
            else if (last > index)
                last = index;
        }
        else
        {
            if (delta > 0)
                last = 0;
            else
                last = index;
        }
        while (true)
        {
            BSSimpleList<ListBoxItem<unsigned int>*>* entry = this;
            for (; !selected && entry && ((::ListBoxItem<unsigned int> *)(new ((void *)(entry)) ::Vec3())); entry = ((::BSSimpleList< ::ListBoxItem<unsigned int> *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070())))
            {
                if (((TileListBoxCalls*)((::ListBoxItem<unsigned int> *)(new ((void *)(entry)) ::Vec3()))->pTile)->GetFloat(0xfac) == last)
                    selected = ((::ListBoxItem<unsigned int> *)(new ((void *)(entry)) ::Vec3()))->pTile;
            }
            if (selected && !reinterpret_cast<::FUN_00a01230_shell *>((selected))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1)))
            {
                selected = 0;
                if (delta > 0 && ++last > index)
                {
                    last = index - 1;
                    while ((!selected || !reinterpret_cast<::FUN_00a01230_shell *>((selected))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1))) && last >= 0)
                    {
                        selected = GetTileAt(last--, false);
                    }
                    break;
                }
                else if (delta < 0 && --last < 0)
                {
                    last = 1;
                    while ((!selected || !reinterpret_cast<::FUN_00a01230_shell *>((selected))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1))) &&
                           last <= index)
                    {
                        selected = GetTileAt(last++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return selected != m_pSelectedTile ? selected : 0;
}

struct xEntryItem
{
    xEntryObj* m_pEntryObject;
    InventoryStackRecord* m_pChange;
};

class List_009e03e0
{
  public:
    xEntryItem* m_pInventoryEntryData;
    List_009e03e0* m_pNext;
    ~List_009e03e0();
};

class xTileT
{
  public:
};

class xEntryMenu
{
  public:
    int m_i0;
    xEntryItem* m_pSelected;
    List_009e03e0* m_pEntries;
    xTileT* m_pTile;
    int m_i10;
    int m_aiPad[2];
    unsigned short m_us1c;
    float m_f20;
    void ClearEntries();
};

// Frees all xEntryItem entries and the selected item, resets m_us1c, m_f20, m_i10, and refreshes the menu.
// @fnv 0x007a2bd0
void xEntryMenu::ClearEntries()
{
    while (m_pEntries && *((::xEntryItem **)(new ((void *)(m_pEntries)) ::Vec3())))
    {
        List_009e03e0* pNext = ((::List_009e03e0 *)(reinterpret_cast<::Callees *>((m_pEntries))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::xEntryItem **)(new ((void *)(m_pEntries)) ::Vec3())))->m_pEntryObject;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::xEntryItem **)(new ((void *)(m_pEntries)) ::Vec3())))->m_pChange;
        delete *((::xEntryItem **)(new ((void *)(m_pEntries)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((m_pEntries))->Initialize((::CombatController *)(0));
        delete m_pEntries;
        m_pEntries = pNext;
    }
    if (m_pSelected)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete m_pSelected->m_pEntryObject;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete m_pSelected->m_pChange;
        delete m_pSelected;
    }
    m_pSelected = 0;
    m_us1c = 0;
    m_f20 = 0.0f;
    if (m_pTile)
        reinterpret_cast<::FUN_00a012d0_t *>((m_pTile))->FUN_00a012d0(::FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::ScrollListHost *>(this)->FUN_007a7080();
    m_i10 = 0;
    reinterpret_cast<::FUN_007a6c80_shell *>(this)->UpdateHighlightBox();
}

struct ClearTile
{
    virtual ~ClearTile();
};
struct ClearData
{
    ~ClearData();
};
struct ClearTilePayloadPair
{
    ClearTile* unk00;
    ClearData* unk04;
};
struct ClearNode
{
    ClearTilePayloadPair* unk00;
    ClearNode* unk04;
    ~ClearNode();
};
struct Target007a4780
{
    void* unk00;
    ClearTilePayloadPair* unk04;
    ClearNode* unk08;
    ClearTile* unk0c;
    ClearTile* unk10;
    void* unk14;
    const char* unk18;
    unsigned short unk1c;
    float unk20;
    void FUN_007a4780();
};
// Clears the entries, resets fields, and calls FUN_00a012d0 on unk0c with a value from FUN_00a01860.
// @fnv 0x007a4780
void Target007a4780::FUN_007a4780()
{
    while (unk08 && ((::ClearTilePayloadPair *)(new ((void *)(unk08)) ::Vec3())))
    {
        ClearNode* next = ((::ClearNode *)(reinterpret_cast<::Callees *>((unk08))->FUN_00726070()));
        if (!(*reinterpret_cast<unsigned char *>(&::fnv_007a2070::s_bAllowDetach)))
            delete ((::ClearTilePayloadPair *)(new ((void *)(unk08)) ::Vec3()))->unk00;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete ((::ClearTilePayloadPair *)(new ((void *)(unk08)) ::Vec3()))->unk04;
        delete ((::ClearTilePayloadPair *)(new ((void *)(unk08)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((unk08))->Initialize((::CombatController *)(::ClearTilePayloadPair *)(0));
        delete unk08;
        unk08 = next;
    }
    if (unk04)
    {
        if (!(*reinterpret_cast<unsigned char *>(&::fnv_007a2070::s_bAllowDetach)))
            delete unk04->unk00;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete unk04->unk04;
        delete unk04;
    }
    unk04 = 0;
    unk1c = 0;
    unk20 = 0.0f;
    if (unk0c)
        reinterpret_cast<::FUN_00a012d0_t *>((unk0c))->FUN_00a012d0(FUN_00a01860(::str_0106f8d0), 0.0f, true);
    reinterpret_cast<::ScrollList *>(this)->FUN_007a7d80();
    unk10 = 0;
    reinterpret_cast<::SelectionList *>(this)->UpdateSelectionState();
}

struct LB_007a4d50 : BSSimpleList<ListBoxItem<unsigned int>*>
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Tile* GetTileAt(unsigned int index, bool b);
    TileListBoxCalls* m_pListTile;
    TileListBoxCalls* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    Tile* FUN_007a4d50(int event);
};

// Finds a candidate tile using the event-derived delta, skips disabled tiles, and returns it if it differs from m_pSelectedTile.
// @fnv 0x007a4d50
Tile* LB_007a4d50::FUN_007a4d50(int event)
{
    Tile* pNewTile = 0;
    int iDelta = 0;
    switch (event)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pListTile
                     ? (int)::InventoryStackRecord::RoundToNearestStep(
                           -m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                     : 0;
        break;
    case 16:
        iDelta = m_pListTile
                     ? (int)::InventoryStackRecord::RoundToNearestStep(
                           m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                     : 0;
        break;
    }
    if (reinterpret_cast<::FUN_007a79b0_shell *>(this)->FUN_007a79b0() && iDelta && m_usSelectedIndex)
    {
        int iTargetIndex;
        int iMaxIndex = m_usSelectedIndex - 1;
        if (m_pSelectedTile)
        {
            int hiIdx = (int)m_pSelectedTile->GetFloat(0xfac);
            iTargetIndex = hiIdx + iDelta;
            if (iTargetIndex < 0)
            {
                iTargetIndex = 0;
            }
            else if (iTargetIndex > iMaxIndex)
            {
                iTargetIndex = iMaxIndex;
            }
        }
        else if (iDelta > 0)
        {
            iTargetIndex = 0;
        }
        else
        {
            iTargetIndex = iMaxIndex;
        }
        while (true)
        {
            for (BSSimpleList<ListBoxItem<unsigned int>*>* node = this; !pNewTile && node && ((::ListBoxItem<unsigned int> *)(new ((void *)(node)) ::Vec3()));
                 node = ((::BSSimpleList< ::ListBoxItem<unsigned int> *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (((TileListBoxCalls*)((::ListBoxItem<unsigned int> *)(new ((void *)(node)) ::Vec3()))->pTile)->GetFloat(0xfac) == iTargetIndex)
                {
                    pNewTile = ((::ListBoxItem<unsigned int> *)(new ((void *)(node)) ::Vec3()))->pTile;
                }
            }
            if (pNewTile && !reinterpret_cast<::FUN_00a01230_shell *>((pNewTile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1)))
            {
                pNewTile = 0;
                if (iDelta > 0 && ++iTargetIndex > iMaxIndex)
                {
                    iTargetIndex = iMaxIndex - 1;
                    while ((!pNewTile || !reinterpret_cast<::FUN_00a01230_shell *>((pNewTile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1))) &&
                           iTargetIndex >= 0)
                    {
                        pNewTile = GetTileAt(iTargetIndex--, false);
                    }
                    break;
                }
                else if (iDelta < 0 && --iTargetIndex < 0)
                {
                    iTargetIndex = 1;
                    while ((!pNewTile || !reinterpret_cast<::FUN_00a01230_shell *>((pNewTile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1))) &&
                           iTargetIndex <= iMaxIndex)
                    {
                        pNewTile = GetTileAt(iTargetIndex++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return pNewTile != m_pSelectedTile ? pNewTile : 0;
}

class ListBoxBaseWithVTable
{
  public:
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3() = 0;
    virtual void func4() = 0;
    virtual Tile* GetTile(int index, int unk) = 0;
};

class SomeClass : public ListBox<BGSNote*>
{
  public:
    Tile* FUN_007a31e0(int param);
};

// Finds an enabled tile at the event-derived target index and returns it when it differs from the current selection.
// @fnv 0x007a31e0
Tile* SomeClass::FUN_007a31e0(int param)
{
    Tile* pResultTile = NULL;
    int delta = 0;

    switch (param)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = m_pListTile
                    ? (int)::InventoryStackRecord::RoundToNearestStep(-((TileListBoxCalls*)m_pListTile)->GetFloat(4016) /
                                            ((TileListBoxCalls*)m_pListTile)->GetFloat(FUN_00a01860("_scroll_delta")),
                                        1.0f)
                    : 0;
        break;
    case 16:
        delta = m_pListTile
                    ? (int)::InventoryStackRecord::RoundToNearestStep(((TileListBoxCalls*)m_pListTile)->GetFloat(4016) /
                                            ((TileListBoxCalls*)m_pListTile)->GetFloat(FUN_00a01860("_scroll_delta")),
                                        1.0f)
                    : 0;
        break;
    }

    if (reinterpret_cast<::FUN_007a6bd0_shell *>(this)->FUN_007a6bd0() && delta && m_usSelectedIndex)
    {
        int maxIndex = m_usSelectedIndex - 1;
        int targetIndex;

        if (m_pSelectedTile)
        {
            int curIndex = (int)((TileListBoxCalls*)m_pSelectedTile)->GetFloat(4012);
            targetIndex = curIndex + delta;
            if (targetIndex < 0)
                targetIndex = 0;
            else if (targetIndex > maxIndex)
                targetIndex = maxIndex;
        }
        else
        {
            if (delta > 0)
                targetIndex = 0;
            else
                targetIndex = maxIndex;
        }

        while (true)
        {
            for (BSSimpleList<ListBoxItem<BGSNote*>*>* iter = this ? &items : NULL;
                 !pResultTile && iter && ((::ListBoxItem< ::BGSNote *> *)(new ((void *)(iter)) ::Vec3())); iter = ((::BSSimpleList< ::ListBoxItem< ::BGSNote *> *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070())))
            {
                if (((TileListBoxCalls*)((::ListBoxItem< ::BGSNote *> *)(new ((void *)(iter)) ::Vec3()))->tile)->GetFloat(4012) == (float)targetIndex)
                {
                    pResultTile = (Tile*)((::ListBoxItem< ::BGSNote *> *)(new ((void *)(iter)) ::Vec3()))->tile;
                }
            }

            if (pResultTile && !reinterpret_cast<::FUN_00a01230_shell *>((pResultTile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1)))
            {
                pResultTile = NULL;
                if (delta > 0 && ++targetIndex > maxIndex)
                {
                    targetIndex = maxIndex - 1;
                    while ((!pResultTile || !reinterpret_cast<::FUN_00a01230_shell *>((pResultTile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1))) &&
                           targetIndex >= 0)
                    {
                        pResultTile = ((ListBoxBaseWithVTable*)this)->GetTile(targetIndex--, 0);
                    }
                    break;
                }
                else if (delta < 0 && --targetIndex < 0)
                {
                    targetIndex = 1;
                    while ((!pResultTile || !reinterpret_cast<::FUN_00a01230_shell *>((pResultTile))->IsTraitNonZero(::FUN_00a00940(kListBoxEnabled, -1))) &&
                           targetIndex <= maxIndex)
                    {
                        pResultTile = ((ListBoxBaseWithVTable*)this)->GetTile(targetIndex++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return (pResultTile != m_pSelectedTile) ? pResultTile : NULL;
}
