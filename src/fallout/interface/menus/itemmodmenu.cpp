// fallout/interface/menus/itemmodmenu.cpp: ItemModMenu, RepairMenu, ModMenuStub, ItemModMenuHack and more (19 functions)

#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/ActiveEffectCollection.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004186f0_shell.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00419ad0_shell.h"
#include "fnv/decl/FUN_00419f80_shell.h"
#include "fnv/decl/FUN_0042e560_shell.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/FUN_004bd570_this.h"
#include "fnv/decl/FUN_004bd820_stand.h"
#include "fnv/decl/FUN_004bd880_stand.h"
#include "fnv/decl/FUN_004bddd0_shell.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_004bfba0_shell.h"
#include "fnv/decl/FUN_004d4ca0_shell.h"
#include "fnv/decl/FUN_0071ae60_shell.h"
#include "fnv/decl/FUN_0073ac90_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0088c650_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/Holder_70.h"
#include "fnv/decl/InvEntry_bdb40.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ItemChange_004be200.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/RList71a5.h"
#include "fnv/decl/S007b39b0.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00412380__FUN_00412380_shell.h"
#include "fnv/decl/fnv_004126c0__FUN_004126c0_shell.h"
#include "fnv/decl/fnv_0042e380__FUN_0042e380_Class.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/list71a__L71Menu.h"
#include "fnv/decl/s88c790__Actor.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00782000.h"
#include "fnv/symbols_00783000.h"
#include "fnv/symbols_00784000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "itemmodmenu_unit_decls.h"

static const int kGetClassValue = 1061;

// @fnv 0x00783310
ItemModMenu::ItemModMenu()
{
    DAT_011d9f3c = ::FUN_00a01860(::DAT_0106ed20);
    DAT_011d9f44 = ::FUN_00a01860(::DAT_0106ed18);
    DAT_011d9f48 = ::FUN_00a01860((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxEnabled)));
    DAT_011d9f4c = ::FUN_00a01860(DAT_01073b64);
    DAT_011d9f40 = 0;
}

// @fnv 0x007b5400
RepairMenu::RepairMenu()
{
    DAT_011da74c = ::FUN_00a01860(::DAT_0106ed20);
    DAT_011da754 = ::FUN_00a01860(::DAT_0106ed18);
    DAT_011da750 = ::FUN_00a01860((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxEnabled)));
    DAT_011da748 = ::FUN_00a01860(DAT_01075c44);
}

// @fnv 0x007833d0
int ItemModMenu::GetClass()
{
    return kGetClassValue;
}

struct FUN_007273f0_shell : public ItemModMenu
{
    bool FUN_007273f0();
};
// Loads the item mod menu tile from file, validates its menu ID, initializes the list box and child tiles, and returns the tile or 0 on failure.
// @fnv 0x00783440
Tile* __cdecl ItemModMenu::Create()
{
    struct CreateLocals
    {
        Menu* destroyedMenu;
        Tile* destroyedTile;
        Menu* oldMenu;
        Menu* oldMenuCopy;
        Tile* firstCopy;
        Tile* secondCopy;
        void* resourceProvider;
        Tile* fileTile;
        Tile* menuTile;
    } state;

    state.resourceProvider = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    state.menuTile = ((::Tile *)(::FUN_00a09030(FUN_00783640())));
    if (state.menuTile != 0)
    {
        state.firstCopy = state.menuTile;
        state.secondCopy = state.firstCopy;
        if (state.secondCopy != 0)
        {
            state.destroyedTile = state.secondCopy->Destroy(true);
        }
        else
        {
            state.destroyedTile = 0;
        }
    }

    state.fileTile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((((InterfaceManager*)state.resourceProvider)->FUN_00586150()))->FUN_00a01b00((void *)(DAT_01073c34));
    DAT_011d9f54 = reinterpret_cast<::FUN_00a03c90_shell *>((state.fileTile))->FUN_00a03c90();
    if (DAT_011d9f54 != 0 && DAT_011d9f54->GetID() == FUN_00783640())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((DAT_011d9f54))->FUN_00a1dc70((TileMenu*)state.fileTile, false);
        ::FUN_00867a20((void *)(((InventoryMenu*)DAT_011d9f54)));
        if (!reinterpret_cast<::FUN_007273f0_shell *>((DAT_011d9f54))->FUN_007273f0())
        {
            ::FUN_005b5e40();
            return 0;
        }

        if (((TileListBoxCalls*)state.fileTile)->GetFloat(0xfa7) == ::DAT_010704f0 ||
            ((TileListBoxCalls*)state.fileTile)->GetFloat(0xfa7) == ::DAT_010704e8)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((state.fileTile))->FUN_00a012d0(0xfad, Tile::GetInterfaceScale(), true);
        }

        ((ListBox_ItemChange___*)((char*)DAT_011d9f54 + 0x60))
            ->Initialize(((ItemModMenu*)DAT_011d9f54)->m_pTiles[1], DAT_01073bc4);
        ((ListBox_ItemChange___*)((char*)DAT_011d9f54 + 0x60))->FUN_007a1930(false);
        reinterpret_cast<::FUN_00a01290_shell *>((((ItemModMenu*)DAT_011d9f54)->m_pTiles[5]))->SetTraitAndReset(DAT_011d9f44, 1.0f);
        reinterpret_cast<::FUN_00a01290_shell *>((((ItemModMenu*)DAT_011d9f54)->m_pTiles[10]))->SetTraitAndReset(DAT_011d9f44, 1.0f);
        DAT_011d9f54->SetMenuVisibility(true);
        return state.fileTile;
    }

    else
    {
        if (DAT_011d9f54 != 0 && ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)DAT_011d9f54)))->FUN_00726070())) != 0)
        {
            state.oldMenu = DAT_011d9f54;
            state.oldMenuCopy = state.oldMenu;
            if (state.oldMenuCopy != 0)
            {
                state.destroyedMenu = state.oldMenuCopy->Destructor(true);
            }
            else
            {
                state.destroyedMenu = 0;
            }
        }
    }
    return 0;
}

// Checks the 14 int entries at offset 0x28 and returns false if any is zero, otherwise true.
// @fnv 0x007273f0
bool FUN_007273f0_shell::FUN_007273f0()
{
    for (int i = 0; i < 14; ++i)
    {
        if (((int*)((char*)this + 0x28))[i] == 0)
            return false;
    }
    return true;
}

// @fnv 0x00783640
int __cdecl FUN_00783640()
{
    return 0x425;
}

struct ModMenuStub
{
    void FUN_00783650();
    void* DestroyIfFlagged(unsigned int);
};
struct Tile_Set_Helper
{
};
struct ListBoxStandIn
{
};
struct ItemModMenuHack
{
    char _00[0x48];
    Tile_Set_Helper* _48;
    Tile_Set_Helper* _4C;
    char _50[0x10];
    ListBoxStandIn _60;
    void UpdateItemModTile(int aiID, Tile* apTarget);
};
// For ID 15, sets tile 0xFA3 to 0 on _4C and, when the list box count exceeds 1, also on _48.
// @fnv 0x00784050
void ItemModMenuHack::UpdateItemModTile(int aiID, Tile* apTarget)
{
    if (aiID == 15)
    {
        reinterpret_cast<::Tile *>((_4C))->Set(0xFA3, 0);
        if (reinterpret_cast<::FUN_0071ae60_shell *>(&(_60))->FUN_0071ae60() > 1)
        {
            reinterpret_cast<::Tile *>((_48))->Set(0xFA3, 0);
        }
    }
}

class FOPipboyManager;
struct Interface
{
public:
    ::FOPipboyManager *GetPipboyManager();
};
struct MyMenu
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
    bool HandleButtonPress(int aiButton, float afValue);
};
// @fnv 0x007840a0
bool MyMenu::HandleButtonPress(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 6:
    case 10:
        ::FUN_00706f30(3);
        this->f3(12, 0);
        bhandled = true;
    }
    return bhandled;
}

struct TileRemoveFade
{
};

struct FUN_007308e0
{
    virtual ~FUN_007308e0();
};

struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};

struct FUN_00783650 : Menu_007a8b10
{
    unsigned char opaque_00[0x44];
    TileRemoveFade* fadeControl;
    unsigned char opaque_4c[0x14];
    FUN_007308e0 member_60;

    ~FUN_00783650();
};
// Calls FUN_00783650, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00783410
void* ModMenuStub::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00783650 *>(this)->FUN_00783650::~FUN_00783650();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


// @fnv 0x00783650
FUN_00783650::~FUN_00783650()
{
    reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((fadeControl))->RemoveFadeItemsForTile(0xfa9);
    (*reinterpret_cast<int *>(&::DAT_011d9f54)) = 0;
}

struct GO
{
    operator unsigned int() const;
};

struct TV
{
};

struct FUN_006317a0_struct : public GO
{
    TV** AddEight(int);
};

struct ExtraDataList;

struct InventoryStackRecord
{
    BSSimpleList<ExtraDataList*>* m_pExtraDataLists;
    FUN_006317a0_struct object;
public:
    static float GetConditionPercent(float);
public:
    static float RoundToNearestStep(float, float);
public:
    void *GetPayloadAddress();
};

template <class T> struct ListBoxItem
{
    T m_item;
};

// Compares the visibility of the objects referenced by two list box items, returning -1, 1, or 0.
// @fnv 0x00783810
int CompareItemVisibility(ListBoxItem<InventoryStackRecord*>* apItem1, ListBoxItem<InventoryStackRecord*>* apItem2)
{
    bool bVisibleA;
    int iresult = 0;
    bool bVisibleB;

    bVisibleA = reinterpret_cast<::sa040a0::Owner *>(((*apItem1->m_item->object.AddEight(apItem1->m_item->object.operator unsigned int()))))->IsAllChildrenFlag0();
    bVisibleB = reinterpret_cast<::sa040a0::Owner *>(((*apItem2->m_item->object.AddEight(apItem2->m_item->object.operator unsigned int()))))->IsAllChildrenFlag0();

    if (bVisibleA && !bVisibleB)
        iresult = -1;
    else if (!bVisibleA && bVisibleB)
        iresult = 1;

    return iresult;
}

struct ModEntry;
struct ModObject
{
};
struct ModEntry
{
};
struct ModTile;
struct ModTileList
{
};
struct ModTile
{
    unsigned int field_00;
    ModTileList field_04;
};
extern float DAT_01073c54;
// @fnv 0x007836d0
void __cdecl UpdateTileFromObject(ModTile* tile, ModObject* object)
{
    if (!tile || !object)
        return;
    float value = reinterpret_cast<::FUN_004bcdb0_shell *>((object))->FUN_004bcdb0(1);
    reinterpret_cast<::Tile *>((tile))->Set(0xfaa, 15);
    reinterpret_cast<::Tile *>((tile))->Set(0xfa3, reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfac) >= ::_DAT_01012060 ? 1 : 0);
    reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfa3, 1.0f, true);
    ModEntry* entry = ((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()));
    if (reinterpret_cast<::FUN_004bd820_stand *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bd820())
    {
        ModEntry* other = ((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((object))->GetName()));
        if (((reinterpret_cast<::FUN_004bd820_stand *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bd820() & 1) && other == ((::ModEntry *)(reinterpret_cast<::FUN_004bd570_this *>((entry))->FUN_004bd570(1)))) ||
            ((reinterpret_cast<::FUN_004bd820_stand *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bd820() & 2) && other == ((::ModEntry *)(reinterpret_cast<::FUN_004bd570_this *>((entry))->FUN_004bd570(2)))) ||
            ((reinterpret_cast<::FUN_004bd820_stand *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bd820() & 4) && other == ((::ModEntry *)(reinterpret_cast<::FUN_004bd570_this *>((entry))->FUN_004bd570(4)))))
        {
            reinterpret_cast<::FUN_00a012d0_t *>(((*((::ModTile **)(reinterpret_cast<::InventoryStackRecord *>(&(tile->field_04))->GetPayloadAddress())))))->FUN_00a012d0(0xfa9, DAT_01073c54, true);
        }
    }
}

namespace fnv_007846a0 {
struct ItemListBoxCalls
{
    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
    virtual void Method3();
    virtual void Method4();
    virtual void Method5();
    virtual void Method6();
    virtual void Method7();
};
struct TileActionCalls
{
};

// @fnv 0x007846a0
void __cdecl ResetItemModMenu()
{
    reinterpret_cast<ItemListBoxCalls*>(&static_cast<ItemModMenu*>(DAT_011d9f54)->m_kItemList)->Method7();
    DAT_011d9f58 = 0;
    DAT_011d9f54->HandleMouseoverTileAlt(0x0f, 0);
    reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((reinterpret_cast<TileActionCalls*>(static_cast<ItemModMenu*>(DAT_011d9f54)->m_pTiles[8])))->RemoveFadeItemsForTile(0xfa9);
    reinterpret_cast<::Tile *>((reinterpret_cast<TileActionCalls*>(static_cast<ItemModMenu*>(DAT_011d9f54)->m_pTiles[8])))->Set(0xfa3, 0);
}
}  // namespace fnv_007846a0

struct EqForm;
struct EqScriptLocals;

struct EqExtraList
{
    virtual ~EqExtraList();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    EqExtraList();
};

struct EqExtraListNode
{
    EqExtraList* pItem;
    EqExtraListNode* pNext;

    void AddHead(EqExtraList*& arItem);
    void RemoveAll();
};

struct EqForm
{
};

struct EqEntry
{
};

struct EqInventoryChanges
{
};



struct EqMenu
{
    bool FUN_00783af0(EqEntry* apTarget);
};

// Merges the current entry's extra data into the player's inventory, equips it to a free hand slot, and returns whether it was equipped.
// @fnv 0x00783af0
bool EqMenu::FUN_00783af0(EqEntry* apTarget)
{
    EqEntry* pPlayerEntry =
        ((::EqEntry *)(reinterpret_cast<::FUN_004bfba0_shell *>((((::EqInventoryChanges *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<void * *>(&::_g_thePlayer))))))))->FUN_004bfba0((::TESBoundObject *)(::EqForm *)(((::EqForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()))), 1, 0)));
    EqExtraList* pExtra = (((::EqExtraListNode *)(::FUN_00559450((int *)((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58))))))) ? *((::EqExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(((::EqExtraListNode *)(::FUN_00559450((int *)((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58)))))))->m_item)) : 0;
    EqExtraList* pNewExtra2 = new EqExtraList;
    int _iCount = -1;
    bool bMerged4 = false;
    bool bEquipped = false;
    EqForm* pType3 = ((::EqForm *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()));
    bool bUnused3 = true;
    EqForm* pTargetType = ((::EqForm *)(reinterpret_cast<::Twin_0044ddc0 *>((apTarget))->GetName()));
    int iUnused2 = (*reinterpret_cast<int *>(&::InventoryMenu::ms_pActionPointSource));

    _iCount = reinterpret_cast<::FUN_00418770_shell *>((pExtra))->FUN_00418770();
    reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((pNewExtra2))->FUN_00412380((::ExtraDataList *)(pExtra));
    reinterpret_cast<::FUN_00419ad0_shell *>((pNewExtra2))->FUN_00419ad0(1);
    ((::EqExtraListNode *)(::FUN_00559450((int *)((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58))))))->RemoveAll();
    if (_iCount > 1)
        reinterpret_cast<::FUN_00419ad0_shell *>((pExtra))->FUN_00419ad0(_iCount - 1);

    unsigned char ucHand7 = 0;
    if (!(reinterpret_cast<::FUN_0042e560_shell *>((pNewExtra2))->FUN_0042e560() & 1) && ((::EqForm *)(reinterpret_cast<::FUN_004bd570_this *>((pType3))->FUN_004bd570(1))) == pTargetType)
    {
        reinterpret_cast<::fnv_0042e380::FUN_0042e380_Class *>((pNewExtra2))->FUN_0042e380(1);
        ucHand7 = 1;
        bEquipped = true;
    }
    else if (!(reinterpret_cast<::FUN_0042e560_shell *>((pNewExtra2))->FUN_0042e560() & 2) && ((::EqForm *)(reinterpret_cast<::FUN_004bd570_this *>((pType3))->FUN_004bd570(2))) == pTargetType)
    {
        reinterpret_cast<::fnv_0042e380::FUN_0042e380_Class *>((pNewExtra2))->FUN_0042e380(2);
        ucHand7 = 2;
        bEquipped = true;
    }
    else if (!(reinterpret_cast<::FUN_0042e560_shell *>((pNewExtra2))->FUN_0042e560() & 4) && ((::EqForm *)(reinterpret_cast<::FUN_004bd570_this *>((pType3))->FUN_004bd570(4))) == pTargetType)
    {
        reinterpret_cast<::fnv_0042e380::FUN_0042e380_Class *>((pNewExtra2))->FUN_0042e380(4);
        ucHand7 = 4;
        bEquipped = true;
    }

    for (EqExtraListNode* pNode4 = ((::EqExtraListNode *)(::FUN_00559450((int *)(pPlayerEntry)))); pNode4 && *((::EqExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pNode4)->m_item));
         pNode4 = ((::EqExtraListNode *)(reinterpret_cast<::Callees *>((pNode4))->FUN_00726070())))
    {
        if (!reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>(((*((::EqExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pNode4)->m_item)))))->FUN_004126c0((::ExtraDataList *)(pNewExtra2), 1, 0) && !reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((pNewExtra2))->FUN_004126c0((::ExtraDataList *)(*((::EqExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pNode4)->m_item))), 1, 0))
        {
            reinterpret_cast<::FUN_00419ad0_shell *>(((*((::EqExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pNode4)->m_item)))))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>(((*((::EqExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pNode4)->m_item)))))->FUN_00418770() + 1);
            ((::EqExtraListNode *)(::FUN_00559450((int *)((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58))))))->AddHead(*((::EqExtraList **)(&reinterpret_cast<::SimpleListNodeView*>(pNode4)->m_item)));
            bMerged4 = true;
        }
    }

    EqExtraList* pResult4 = 0;
    if (!bMerged4)
    {
        if (_iCount > 1)
        {
            ((::EqExtraListNode *)(::FUN_00559450((int *)(pPlayerEntry))))->AddHead(pNewExtra2);
            ((::EqExtraListNode *)(::FUN_00559450((int *)((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58))))))->AddHead(pNewExtra2);
            pResult4 = pNewExtra2;
        }
        else
        {
            reinterpret_cast<::fnv_0042e380::FUN_0042e380_Class *>((pExtra))->FUN_0042e380(ucHand7);
            ((::EqExtraListNode *)(::FUN_00559450((int *)((*reinterpret_cast<::EqEntry * *>(&::fnv_007846a0::DAT_011d9f58))))))->AddHead(pExtra);
            pResult4 = pExtra;
        }
    }
    else if (_iCount == 1)
    {
        reinterpret_cast<::ItemChangeListNode *>((((::EqExtraListNode *)(::FUN_00559450((int *)(pPlayerEntry))))))->FUN_00905330((::InventoryStackRecord *const &)(pExtra));
    }

    if (bMerged4 || _iCount == 1)
    {
        reinterpret_cast<::FUN_00419f80_shell *>((pNewExtra2))->FUN_00419f80((::ScriptLocals *)(::EqScriptLocals *)(0));
        delete pNewExtra2;
        if (pResult4 == pNewExtra2)
            pResult4 = 0;
    }

    if (((int)(reinterpret_cast<::FUN_004bd880_stand *>((pType3))->GetSlotPointer(ucHand7))) == 10 && pResult4)
        reinterpret_cast<::ExtraDataList *>((pResult4))->SetExtraHealth(reinterpret_cast<::FUN_004186f0_shell *>((pResult4))->FUN_004186f0() + reinterpret_cast<::FUN_004bcf60_shell *>((pType3))->GetEffectValue(10, 0));

    if (bEquipped)
        ::TopicMenuController::IncrementMiscStat(0x21);
    return bEquipped;
}


struct ModStr
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    ModStr(const char* src);
    ~ModStr();
    operator const char*() const;
};

struct ModListTile
{
};

struct ModListEntry
{
    ModListTile* pTile;
};

struct ModListOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ModListEntry* pEntry;

    void FUN_007b4410();
};

// @fnv 0x007b4410
void ModListOwner::FUN_007b4410()
{
    if (FUN_004b71d0())
    {
        if (!pEntry && !reinterpret_cast<::FUN_0076b610_Class *>((void *)this)->FUN_0076b610())
            pEntry = *((::ModListEntry **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90()));
        if (pEntry)
        {
            ModStr savedTraitString(reinterpret_cast<::FUN_00a011f0_shell *>((pEntry->pTile))->FUN_00a011f0(0xfe8));
            reinterpret_cast<::Tile *>((pEntry->pTile))->Set(0xfe8, -1);
            FUN_00706ff0((int)pEntry->pTile);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pEntry->pTile))->FUN_00a01350(0xfe8, (char *)(const char *)(savedTraitString), true);
            while (true)
            {
                int count = reinterpret_cast<::S007b39b0 *>((pEntry))->GetPosition();
                if (count)
                {
                    reinterpret_cast<::ActiveEffectCollection *>(this)->FUN_007b4530(-count);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

namespace fnv_007838a0 {
class TESForm;
template <class T> class BSStringT
{
  public:
    operator const T*() const;
};
class B006815c0
{
  public:
    B006815c0();
};
struct ContNode;
class TESObjectREFR_GetFlags_Helper
{
  public:
};
class ItemEntry : public BSStringT<char>
{
  public:
};
class TileValueW
{
  public:
};
class TileValueList
{
  public:
};
class BSSoundHandleEx
{
  public:
    unsigned int uiSoundID;
    unsigned char m_bLooping;
    unsigned int uiState;
    ~BSSoundHandleEx();
};
class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
struct FUN_004f2770_Class
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void SendItemModEvent(unsigned int ItemUpdateArray, TESForm* pForm, bool b1, bool b2, bool b3, bool b4, bool b5,
                                  bool b6, bool b7, bool b8);
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void UpdateRepairMenu();
};
class ItemModListW
{
  public:
    virtual void v0();
    virtual int v1();
    ItemEntry* FUN_007a1910();
};

class ItemModMenuW : public ItemModMenu
{
  public:
    void HandleItemModMenuClick(int tileID, Tile* clickedTile);
};

// @fnv 0x007838a0
void ItemModMenuW::HandleItemModMenuClick(int tileID, Tile* clickedTile)
{
    bool bHandled = false;
    if (!clickedTile && tileID >= 0 && tileID < 14)
        clickedTile = m_pTiles[tileID];
    switch (tileID)
    {
    case 15:
        if (reinterpret_cast<::TileListBoxCalls *>(((*((::fnv_007838a0::TileValueW **)(reinterpret_cast<::InventoryStackRecord *>((((TileValueList*)((char*)clickedTile + 4))))->GetPayloadAddress())))))->GetFloat({}) < 255.0)
        {
        }
        else
        {
            if (((ItemModListW*)&m_kItemList)->FUN_007a1910() != (*reinterpret_cast<::fnv_007838a0::ItemEntry * *>(&::fnv_007846a0::DAT_011d9f58)))
            {
                ItemEntry* pEntry = ((ItemModListW*)&m_kItemList)->FUN_007a1910();
                TESForm* pForm =
                    (const char*)*pEntry ? *(TESForm**)&reinterpret_cast<::SimpleListNodeView*>(((B006815c0*)(const char*)*pEntry))->m_item : 0;
                if (reinterpret_cast<::EqMenu *>(this)->FUN_00783af0((::EqEntry *)(pEntry)))
                {
                    (*reinterpret_cast<::fnv_007838a0::FUN_004f2770_Class * *>(&::_g_thePlayer))->SendItemModEvent(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_Helper*)pEntry)))->GetName())), pForm,
                                                   true, false, false, false, false, false, true, false);
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007838a0::BSSoundHandleEx &)(((::fnv_007838a0::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIItemGunsSmallUp ", 0x121)))->FUN_00ad8830(false);
                    reinterpret_cast<::RList71a5 *>((((ItemModListW*)&m_kItemList)))->RemoveTile((::LBTileObj *)(((ItemModListW*)&m_kItemList)->v1()));
                    ::FUN_00784710((::Entry78 *)((*reinterpret_cast<::fnv_007838a0::ItemEntry * *>(&::fnv_007846a0::DAT_011d9f58))), 0);
                    if (reinterpret_cast<::FUN_004bddd0_shell *>((pEntry))->FUN_004bddd0(false))
                    {
                        (*reinterpret_cast<::fnv_007838a0::FUN_004f2770_Class * *>(&::_g_thePlayer))->UpdateRepairMenu();
                        ::FUN_00782a90();
                    }
                }
            }
        }
        break;
    case 12:
        ::s717280::FUN_00717280(0x24);
        if (DAT_011d9f40 == 1)
        {
            reinterpret_cast<::FUN_0088c650_shell *>(((*reinterpret_cast<::fnv_007838a0::FUN_004f2770_Class * *>(&::_g_thePlayer))))->FUN_0088c650(
                (::TESBoundObject *)(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_Helper*)(*reinterpret_cast<::fnv_007838a0::ItemEntry * *>(&::fnv_007846a0::DAT_011d9f58)))))->GetName()))), (int)(((::fnv_007838a0::ContNode *)(reinterpret_cast<::Callees *>(((ContNode*)(*reinterpret_cast<::fnv_007838a0::ItemEntry * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_00726070()))),
                (::ExtraDataList *)(*(TESForm**)&reinterpret_cast<::SimpleListNodeView*>(((B006815c0*)(const char*)*(*reinterpret_cast<::fnv_007838a0::ItemEntry * *>(&::fnv_007846a0::DAT_011d9f58))))->m_item), true, false, true);
            reinterpret_cast<::Holder_70 *>(((*reinterpret_cast<::fnv_007838a0::ItemEntry * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bdc70();
            DAT_011d9f40 = 0;
        }
        ::sleep704::FUN_007048f0(1, 0, 0);
        break;
    }
}
}  // namespace fnv_007838a0

struct Form78;
struct Data78
{
};
struct Entry78
{
};
struct Form78
{
    int FUN_00401170();
};
struct Name78
{
};
struct Player78
{
};
struct Tile78
{
};
struct Box78
{
    virtual void v0();
    virtual int count();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile78* selected(int, int, int, int);
    virtual void v6();
    virtual void clear();
    virtual void sort(void (*)(void*, void*));
};
struct Menu78
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void notify(int, int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Tile78* unk28;
    int unk2c;
    int unk30;
    Tile78* unk34;
    Tile78* unk38;
    Tile78* unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    Box78 unk60;
};
struct Setting78
{
};
void PopulateModListScreen();
struct Input78
{
};
struct Manager78
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    Input78 unk4d4;
};
// @fnv 0x00784710
void FUN_00784710(Entry78* pEntry, bool b)
{
    if (b)
        DAT_011d9f40 = 0;
    if (DAT_011d9f54)
    {
        if (pEntry)
            (*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58)) = pEntry;
        if ((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58)) && b && reinterpret_cast<::FUN_004bddd0_shell *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bddd0(false))
        {
            reinterpret_cast<::InvEntry_bdb40 *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bdb40();
            reinterpret_cast<::s88c790::Actor *>(((*reinterpret_cast<::Player78 * *>(&::_g_thePlayer))))->FUN_0088c790((int)(((::Form78 *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()))), ((int)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_00726070())),
                                       (int)(*((void **)(&reinterpret_cast<::SimpleListNodeView*>(((::Data78 *)(::FUN_00559450((int *)((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58)))))))->m_item))), 0, 0, 1);
            DAT_011d9f40 = 1;
        }
        float condition = reinterpret_cast<::FUN_004bcdb0_shell *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bcdb0(1) / 100.0;
        reinterpret_cast<::FUN_00a012d0_t *>((((Menu78*)DAT_011d9f54)->unk38))->FUN_00a012d0(0x1004, condition, true);
        reinterpret_cast<::Tile *>((((Menu78*)DAT_011d9f54)->unk38))->Set(0xfa3, 1);
        if (((::Form78 *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()))->FUN_00401170() == 40)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Menu78*)DAT_011d9f54)->unk3c))->FUN_00a01350(DAT_011d9f3c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting78 *>(&::g_011d2c7c))))->GetMenuTitle()))), true);
            reinterpret_cast<::Tile *>((((Menu78*)DAT_011d9f54)
                ->unk3c))->Set(
                    DAT_011d9f44,
                    (int)::InventoryStackRecord::RoundToNearestStep(::GetWeaponDamage((::TESObjectWEAP *)(::Form78 *)(((::Form78 *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()))), condition, (::DamageExtra *)(pEntry), (::TESAmmo *)(0)), 1.0f));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Menu78*)DAT_011d9f54)
                ->unk28))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((Name78*)((char*)((::Form78 *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName())) + 0x30))))->FUN_00408da0()))), true);
        }
        else
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Menu78*)DAT_011d9f54)->unk3c))->FUN_00a01350(DAT_011d9f3c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting78 *>(&::g_011d20c4))))->GetMenuTitle()))), true);
            reinterpret_cast<::Tile *>((((Menu78*)DAT_011d9f54)
                ->unk3c))->Set(DAT_011d9f44, (int)::InventoryStackRecord::GetConditionPercent(::CombatDamageCalculator::CalculateArmorDamageThreshold(
                                               (int)((float)(::FUN_004be060((void *)(((::Form78 *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName())))))), condition)));
        }
        if (pEntry)
        {
            ((Menu78*)DAT_011d9f54)->unk60.clear();
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Menu78*)DAT_011d9f54)->unk34))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::ItemChange_004be200 *>(((*reinterpret_cast<::Entry78 * *>(&::fnv_007846a0::DAT_011d9f58))))->GetIconFilename((::TESObjectREFR *)(0))), true);
            PopulateModListScreen();
        }
        reinterpret_cast<::LBList_7314c0 *>(&(((Menu78*)DAT_011d9f54)->unk60))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(void *, void *))::UpdateTileFromObject)), 0, 0x7fffffff);
        ((Menu78*)DAT_011d9f54)->unk60.sort(((void (&)(void *, void *))::CompareItemVisibility));
        if (pEntry && FUN_004b71d0())
            reinterpret_cast<::FocusManager *>((((Manager78*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860((::FocusTile *)(::Tile78 *)(((Menu78*)DAT_011d9f54)->unk60.selected(1, 0, 0xfc3, 1)), {}, {});
        ((Menu78*)DAT_011d9f54)->notify(15, ((Menu78*)DAT_011d9f54)->unk60.count());
        if (pEntry)
        {
            ::fnv_007046f0::FUN_007046f0(1, 0, 0);
            reinterpret_cast<::TutorialMessageGate718 *>(&(((Manager78*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->unk4d4))->FUN_00718630(6, FUN_00783640(), 500);
        }
    }
}

struct xValT
{
};
class xListT
{
  public:
    virtual void v0();
    virtual xValT* GetValue(int iKey);
    int m_ai[3];
    struct xEntryT* GetSelected();
};
class xDescT
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* GetText(int a, unsigned int uiType);
};
struct xFormT
{
    int m_aiPad[0x1d];
    xDescT m_kDesc;
};
struct xEntryT
{
};
struct xTileT
{
};
struct xPipT
{
    void Shake(int i, float a, float b, bool c);
};
struct xProxyT
{
};
struct xHolderT
{
    int m_aiPad[0xd];
    xTileT* m_pTile;
};
struct xSetting
{
};
extern int xLastValue;

class xInvMenu
{
  public:
    int m_aiPad[0x15];
    xTileT* m_pTile54;
    int m_i58;
    xTileT* m_pTile5c;
    xListT m_kList;
    void FUN_00783ed0(int m_uiSoundID, int iUnused);
};

// Updates the selected entry's display, shakes the pip manager when the queried value changes, and sets description and icon tiles when available.
// @fnv 0x00783ed0
void xInvMenu::FUN_00783ed0(int m_uiSoundID, int iUnused)
{
    switch (m_uiSoundID)
    {
    case 15: {
        float qfTOqo[18];
        xEntryT* qsSDDgz = m_kList.GetSelected();
        int qrEZrs = qsSDDgz ? (int)reinterpret_cast<::TileListBoxCalls *>((m_kList.GetValue(0xfac)))->GetFloat({}) : 0;
        if (xLastValue != qrEZrs)
        {
            ((::xPipT *)(reinterpret_cast<::Interface *>((((::xProxyT *)(::fnv_004b7210::FUN_004b7210()))))->GetPipboyManager()))->Shake(
                0, xLastValue < qrEZrs ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::g_011db2f0)))))) : -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::g_011db2f0)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::g_011db358)))))), true);
            xLastValue = qrEZrs;
        }
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTile5c))->FUN_00a01350(0xfc4, (char *)(""), true);
        if (qsSDDgz && (*reinterpret_cast<void * *>(&::fnv_007846a0::DAT_011d9f58)))
        {
            xFormT* qxQHW = ((::xFormT *)(reinterpret_cast<::Twin_0044ddc0 *>((qsSDDgz))->GetName()));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTile5c))->FUN_00a01350(0xfc4, (char *)(qxQHW->m_kDesc.GetText(0, 0x43534544)), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::xHolderT * *>(&::DAT_011d9f54))->m_pTile))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::ItemChange_004be200 *>((qsSDDgz))->GetIconFilename((::TESObjectREFR *)(0))), true);
            reinterpret_cast<::FUN_00a012d0_t *>((m_pTile54))->FUN_00a012d0(::FUN_00a01860("_line_alpha"), 255.0f, true);
        }
    }
    break;
    }
}

struct Entry;
struct Extras;
struct ExtraNode
{
};
struct Extras
{
    void Add(Extras* const&);
};
struct Entry
{
    Entry(ModEntry*, int);
    int unk00;
    int unk04;
    int unk08;
};
struct EntryNode
{
    EntryNode();
    ~EntryNode();
    Entry* data;
    EntryNode* next;
};
struct Inventory
{
};
struct TileWorkList
{
    Tile_Set_Helper*& At(void*);
};
struct Row
{
    int unk00;
    TileWorkList children;
};
struct Rows
{
};
struct Root
{
    Root* GetRoot();
};
struct Text
{
};
struct Screen
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    Text* label38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    Text* label4c;
    int unk50;
    Text* label54;
    Text* label58;
    int unk5c;
    Rows rows;
    Root* GetRoot();
};
struct Setting
{
};

// Adds rows for flagged entries and collected inventory items, then updates several labels when the locale comparison is nonzero.
// @fnv 0x007840f0
void __cdecl PopulateModListScreen()
{
    if (!(*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58)))
        return;
    ModEntry* base3 = ((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()));
    ModEntry* mod4 = 0;
    ModEntry* kMod2_2 = 0;
    ModEntry* mod5 = 0;
    char aFlags = reinterpret_cast<::FUN_004bd820_stand *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->FUN_004bd820();
    if (aFlags)
    {
        Row* row = 0;
        Entry* entry = 0;
        if (aFlags & 1)
        {
            mod4 = ((::ModEntry *)(reinterpret_cast<::FUN_004bd570_this *>((base3))->FUN_004bd570(1)));
            entry = new Entry(mod4, 1);
            row = ((::Row *)(reinterpret_cast<::list71a::L71Menu *>(&(((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->rows))->FUN_0071a320((int)(entry), reinterpret_cast<::FUN_004be2d0_shell *>((entry))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
            reinterpret_cast<::Tile *>((row))->Set(DAT_011d9f4c, 1);
            reinterpret_cast<::Tile *>((row->children.At(((void *)(::FUN_00559450((int *)&(row->children)))))))->Set(4003, 1);
        }
        if (aFlags & 2)
        {
            kMod2_2 = ((::ModEntry *)(reinterpret_cast<::FUN_004bd570_this *>((base3))->FUN_004bd570(2)));
            entry = new Entry(kMod2_2, 1);
            row = ((::Row *)(reinterpret_cast<::list71a::L71Menu *>(&(((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->rows))->FUN_0071a320((int)(entry), reinterpret_cast<::FUN_004be2d0_shell *>((entry))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
            reinterpret_cast<::Tile *>((row))->Set(DAT_011d9f4c, 1);
            reinterpret_cast<::Tile *>((row->children.At(((void *)(::FUN_00559450((int *)&(row->children)))))))->Set(4003, 1);
        }
        if (aFlags & 4)
        {
            mod5 = ((::ModEntry *)(reinterpret_cast<::FUN_004bd570_this *>((base3))->FUN_004bd570(4)));
            entry = new Entry(mod5, 1);
            row = ((::Row *)(reinterpret_cast<::list71a::L71Menu *>(&(((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->rows))->FUN_0071a320((int)(entry), reinterpret_cast<::FUN_004be2d0_shell *>((entry))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
            reinterpret_cast<::Tile *>((row))->Set(DAT_011d9f4c, 1);
            reinterpret_cast<::Tile *>((row->children.At(((void *)(::FUN_00559450((int *)&(row->children)))))))->Set(4003, 1);
        }
    }
    EntryNode listVal;
    Inventory* inv3 = ((::Inventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::ModObject * *>(&::_g_thePlayer))))));
    reinterpret_cast<::FUN_004d4ca0_shell *>((inv3))->CollectTopicEntries((::TESForm *)(::ModEntry *)(((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::ModObject * *>(&::fnv_007846a0::DAT_011d9f58))))->GetName()))), (::TopicList4d4 *)(::EntryNode *)(&listVal));
    for (EntryNode* node6 = &listVal; node6 && ((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(node6)->m_item)); node6 = ((::EntryNode *)(reinterpret_cast<::Callees *>((node6))->FUN_00726070())))
    {
        Row* row = 0;
        Entry* entry = 0;
        for (int index7 = 0; index7 < ((int)(reinterpret_cast<::Callees *>((((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(node6)->m_item))))->FUN_00726070())); ++index7)
        {
            entry = ((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(node6)->m_item));
            if (index7 == 0)
            {
                if (((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) != mod4 && ((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) != kMod2_2 && ((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) != mod5)
                {
                    row = ((::Row *)(reinterpret_cast<::list71a::L71Menu *>(&(((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->rows))->FUN_0071a320((int)(entry), reinterpret_cast<::FUN_004be2d0_shell *>((entry))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
                    reinterpret_cast<::Tile *>((row))->Set(DAT_011d9f4c, 1);
                }
            }
            else if (((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) != mod4 && ((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) != kMod2_2 && ((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) != mod5)
            {
                entry = new Entry(((::ModEntry *)(reinterpret_cast<::Twin_0044ddc0 *>((((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(node6)->m_item))))->GetName())), 1);
                for (ExtraNode* extra6 = (ExtraNode*)((::Extras *)(::FUN_00559450((int *)(((::Entry *)(reinterpret_cast<::SimpleListNodeView*>(node6)->m_item)))))); extra6 && ((::Extras *)(reinterpret_cast<::SimpleListNodeView*>(extra6)->m_item));
                     extra6 = ((::ExtraNode *)(reinterpret_cast<::Callees *>((extra6))->FUN_00726070())))
                {
                    ((::Extras *)(::FUN_00559450((int *)(entry))))->Add(((::Extras *)(reinterpret_cast<::SimpleListNodeView*>(extra6)->m_item)));
                }
                row = ((::Row *)(reinterpret_cast<::list71a::L71Menu *>(&(((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->rows))->FUN_0071a320((int)(entry), reinterpret_cast<::FUN_004be2d0_shell *>((entry))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
                reinterpret_cast<::Tile *>((row))->Set(DAT_011d9f4c, 1);
            }
        }
    }
    if (::FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011c3cb4))))->GetMenuTitle())), "ENGLISH"))
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::Text *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::Root *)(reinterpret_cast<::Callees *>((((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))))->FUN_00726070()))))->FUN_00a03da0((char *)("IMM_Headline_Title"))))))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d4378))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->label38))->FUN_00a01350(DAT_011d9f3c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d4da4))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->label4c))->FUN_00a01350(DAT_011d9f3c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d4da4))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->label54))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d1f2c))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((Screen*)(*reinterpret_cast<int *>(&::DAT_011d9f54)))->label58))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d29f4))))->GetMenuTitle()))), true);
    }
}

#include "generated/data/fallout/interface/menus/itemmodmenu.inc"
