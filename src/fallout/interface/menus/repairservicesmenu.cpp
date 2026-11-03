
// src/fallout/interface/menus/repairservicesmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/repairservicesmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/ActorGoldQuery.h"
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00419ad0_shell.h"
#include "fnv/decl/FUN_00419f80_shell.h"
#include "fnv/decl/FUN_00480d90_shell.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004bcf00_stand.h"
#include "fnv/decl/FUN_004bddd0_shell.h"
#include "fnv/decl/FUN_004bde40_shell.h"
#include "fnv/decl/FUN_004bfba0_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_008924e0.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/InventoryListBox.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ItemChange_004be200.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESBipedModelForm.h"
#include "fnv/decl/TESHealthForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00412380__FUN_00412380_shell.h"
#include "fnv/decl/fnv_004126c0__FUN_004126c0_shell.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00764000.h"
#include "fnv/symbols_007b7000.h"
#include "fnv/symbols_007b8000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
struct RepairServicesMenu
{
    int FUN_007b74c0();
};

// @fnv 0x007b74c0
int RepairServicesMenu::FUN_007b74c0()
{
    return 0x422;
}

// @fnv 0x007b7890
int __cdecl FUN_007b7890()
{
    return 0x422;
}

struct FUN_007b78a0_shell
{
    int m[10];
    bool FUN_007b78a0();
};

// Returns true only if all 16 entries following the first 10 ints in the object are non-zero; otherwise returns false.
// @fnv 0x007b78a0
bool FUN_007b78a0_shell::FUN_007b78a0()
{
    for (int i = 0; i < 16; ++i)
    {
        if (m[10 + i] == 0)
            return false;
    }
    return true;
}

namespace fnv_007b8ae0 {
struct Tile
{
    void Set(int, int);
};

struct RepairServicesMenu
{
    void UpdateRepairServiceTiles(int aiID, Tile* apTarget);
};

// @fnv 0x007b8ae0
void RepairServicesMenu::UpdateRepairServiceTiles(int aiID, Tile* apTarget)
{
    if (aiID == 0x11)
    {
        reinterpret_cast<Tile*>(*(int*)((int)this + 0x5C))->Set(0xFAF, 1);
        reinterpret_cast<Tile*>(*(int*)((int)this + 0x34))->Set(0xFA3, 0);
        reinterpret_cast<Tile*>(*(int*)((int)this + 0x38))->Set(0xFA3, 0);
    }
}
}  // namespace fnv_007b8ae0

struct FUN_007b74d0_shell
{
    void FUN_007b7500();
    void* DestroyIfFlagged(unsigned int);
};
struct Tile
{
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
struct Menu
{
public:
    void SetMenuVisibility(bool);
};
struct TESTopic
{
};
struct DAT_holder
{
    int field0;
    Tile* tile;
};
// @fnv 0x007b78e0
void __cdecl FUN_007b78e0()
{
    ::StartDialogueForTopic(((::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName(5, 5))));
    (*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0))->tile->Set(0x1772, 1);
    reinterpret_cast<::FUN_00a1d910_shell *>((((Menu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))))->FUN_00a1d910();
}

namespace fnv_007b82c0 {
struct Tile
{
};
struct RepairBatch
{
    void RepairAll(RepairBatch*);
};

// @fnv 0x007b82c0
void __cdecl FUN_007b82c0(Tile* pTile, RepairBatch* pItem)
{
    if (reinterpret_cast<::FUN_00a01230_shell *>((pTile))->IsTraitNonZero(::DAT_011da7dc))
        ((RepairBatch*)DAT_011da7f0)->RepairAll(pItem);
}
}  // namespace fnv_007b82c0

struct FUN_007308e0
{
    virtual ~FUN_007308e0();
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    int m[25];
};
struct FUN_007b7500 : Menu_007a8b10
{
    virtual ~FUN_007b7500();
    FUN_007308e0 t;
};
// Calls FUN_007b7500, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x007b74d0
void* FUN_007b74d0_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_007b7500 *>(this)->FUN_007b7500::~FUN_007b7500();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that clears the global DAT_011da7f0 pointer to null.
// @fnv 0x007b7500
FUN_007b7500::~FUN_007b7500()
{
    (*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)) = 0;
}

struct FUN_004bddd0_t
{
};

struct IC : FUN_004bddd0_t
{
};

struct InventoryStackRecord : IC
{
public:
    static float RoundToNearestStep(float, float);
};

struct ListBoxItem
{
    Tile* m_pTile;
    InventoryStackRecord* m_pInventoryEntryData;
};

struct Tile_IsTrue_standin
{
    bool ContainsTrait(int);
};

bool Tile_IsTrue_standin::ContainsTrait(int)
{
    return false;
}


// @fnv 0x007b7c40
int __cdecl FUN_007b7c40(ListBoxItem* apItem1, ListBoxItem* apItem2)
{
    bool bisGreyedOut1;
    bool bisGreyedOut2;
    int iresult = 0;

    bisGreyedOut1 = !reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<Tile_IsTrue_standin*>(apItem1->m_pTile)))->IsTraitNonZero(DAT_011da7dc);
    bisGreyedOut2 = !reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<Tile_IsTrue_standin*>(apItem2->m_pTile)))->IsTraitNonZero(DAT_011da7dc);

    if (bisGreyedOut1 && !bisGreyedOut2)
    {
        iresult = 1;
    }
    else if (!bisGreyedOut1 && bisGreyedOut2)
    {
        iresult = -1;
    }
    else
    {
        if (reinterpret_cast<::FUN_004bcdb0_shell *>((apItem1->m_pInventoryEntryData))->FUN_004bcdb0(false) <
            reinterpret_cast<::FUN_004bcdb0_shell *>((apItem2->m_pInventoryEntryData))->FUN_004bcdb0(false))
        {
            iresult = 1;
        }
        else if (reinterpret_cast<::FUN_004bcdb0_shell *>((apItem1->m_pInventoryEntryData))->FUN_004bcdb0(false) >
                 reinterpret_cast<::FUN_004bcdb0_shell *>((apItem2->m_pInventoryEntryData))->FUN_004bcdb0(false))
        {
            iresult = -1;
        }
        else
        {
            if (reinterpret_cast<::FUN_004bddd0_shell *>((apItem1->m_pInventoryEntryData))->FUN_004bddd0(false))
            {
                iresult = -1;
            }
            else if (reinterpret_cast<::FUN_004bddd0_shell *>((apItem2->m_pInventoryEntryData))->FUN_004bddd0(false))
            {
                iresult = 1;
            }
        }
    }

    if (bisGreyedOut1 && bisGreyedOut2)
        iresult = -iresult;

    return iresult;
}

struct FUN_00a1c4a0 : Menu_007a8b10
{
    FUN_00a1c4a0();
};
struct FUN_00730810
{
    FUN_00730810();
    ~FUN_00730810();
};
extern char DAT_01075da0;
extern char DAT_01075d94;
extern int DAT_011da7e4;
struct FUN_007b7400 : FUN_00a1c4a0
{
    FUN_00730810 inner;
    FUN_007b7400();
    virtual ~FUN_007b7400();
};
// Initializes four global values via FUN_00a01860 and sets the field at offset 0x98 of this object to zero.
// @fnv 0x007b7400
FUN_007b7400::FUN_007b7400()
{
    DAT_011da7e0 = FUN_00a01860(&(*reinterpret_cast<char *>(&::DAT_0106ed20)));
    DAT_011da7e8 = FUN_00a01860(&(*reinterpret_cast<char *>(&::DAT_0106ed18)));
    DAT_011da7e4 = FUN_00a01860(&DAT_01075da0);
    DAT_011da7dc = FUN_00a01860(&DAT_01075d94);
    *((int*)((char*)this + 0x98)) = 0;
}

struct Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual bool v94();
    int FUN_00401170();
};

struct Holder
{
};

struct Cfg
{
};



// Checks the holder's object and its state, comparing a value against config thresholds and returning whether the condition holds.
// @fnv 0x007b7b40
bool __cdecl FUN_007b7b40(Holder* pHolder)
{
    bool result2 = true;
    Obj* a7 = ((::Obj *)(reinterpret_cast<::Twin_0044ddc0 *>((pHolder))->GetName()));
    Obj* b = ((::Obj *)(::TESBipedModelForm::GetFormAsBipedModel((const ::TESForm *)(a7))));
    if (a7 == 0 || (b != 0 && !reinterpret_cast<::FUN_00480d90_shell *>((b))->FUN_00480d90()) || ::FUN_00481f10((::TESObject *)(a7)) || a7->v94())
    {
        result2 = true;
    }
    else
    {
        result2 =
            ((int)(::GetHealthForm((::TESForm *)(a7)))) == 0 || ((double)(reinterpret_cast<::FUN_004bcdb0_shell *>((pHolder))->FUN_004bcdb0(1))) >= (double)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Cfg *>(&::originalRuntimeFloatSetting944)))))) * ::DAT_01020758 ||
            (a7->FUN_00401170() == 0x18 && ((double)(::FUN_004be060((void *)(a7)))) <= ::_DAT_01012060 && ((double)(::FUN_004be180((char *)(a7)))) <= ::_DAT_01012060);
    }
    return result2;
}

class BSSoundHandleEx
{
  public:
    unsigned int id, state, flags;
    ~BSSoundHandleEx();
};
class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
struct RepairTile
{
};
struct RepairList
{
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
    void* FUN_007a1910();
};
struct RepairPlayer
{
};
extern int DAT_011da7e4;
extern char DAT_01075d38, DAT_01073a94;
struct RepairMenu
{
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
    RepairTile* tiles[16];
    RepairList items;
    int totalCost;
    void RefreshRepairMenu();
    void HandleRepairAction(int id, RepairTile* tile);
};
void __cdecl FUN_00763ff0();

struct RSMTile
{
};

struct RSMInterfaceManager
{
};

struct RSMSetting
{
};

struct RSMListBox
{
    void Initialize(RSMTile* apTemplate, const char* apName);
};

struct RSMExtraList
{
};

struct RSMActor
{
    int unk00[0x29];
    RSMExtraList kExtraList;
};

struct RSMMenu
{
    virtual ~RSMMenu();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual int GetID();

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
    RSMTile* pTile30;
    int unk34;
    int unk38;
    RSMTile* pTile3C;
    RSMTile* pTile40;
    int unk44;
    int unk48;
    int unk4C;
    RSMTile* pTile50;
    RSMTile* pTile54;
    int unk58;
    RSMTile* pTile5C;
    int unk60;
    RSMTile* pTile64;
    RSMListBox kRepairList;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int iUnk9C;

};

int __cdecl FUN_007b7890();


// Loads the repair services menu XML, validates its ID, binds the vendor and repair list, and applies localized strings when the language is English.
// @fnv 0x007b7570
RSMTile* __cdecl CreateRepairServicesMenu(RSMActor* apVendor)
{
    RSMMenu* pOldMenu5;
    RSMTile* pTile;
    RSMInterfaceManager* pInterfaceMgr2;

    if (!apVendor)
    {
        ::FUN_0040fbe0(
            );
        return 0;
    }

    pInterfaceMgr2 = ((::RSMInterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    pOldMenu5 = ((::RSMMenu *)(::FUN_00a09030(FUN_007b7890())));
    if (pOldMenu5)
        delete pOldMenu5;

    pTile = ((::RSMTile *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::RSMTile *)(reinterpret_cast<::InterfaceManager *>((pInterfaceMgr2))->FUN_00586150()))))->FUN_00a01b00((void *)("Data\\Menus\\repair_services_menu.xml"))));
    (*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0)) = ((::RSMMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((pTile))->FUN_00a03c90()));
    if ((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0)) && (*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->GetID() == FUN_007b7890())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))))->FUN_00a1dc70((::TileMenu *)(pTile), false);
        if (!reinterpret_cast<::FUN_007b78a0_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))))->FUN_007b78a0())
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), true);
        reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->pTile40))->SetTraitAndReset(::DAT_011da7e8, 1.0f);
        reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->pTile54))->SetTraitAndReset(::DAT_011da7e8, 1.0f);
        g_pRepairServicesVendor = apVendor;
        (*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->iUnk9C = reinterpret_cast<::ActorValueOwner *>(&(apVendor->kExtraList))->GetActorValueAsInteger((::ActorValue::Index)(0x27));
        (*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->kRepairList.Initialize((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->pTile30, "RSM_RepairListTemplate");
        reinterpret_cast<::RepairMenu *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))))->RefreshRepairMenu();
        FUN_00763ff0();
        if (FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RSMSetting *>(&::g_011c3cb4))))->GetMenuTitle())), "ENGLISH"))
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::RSMTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pTile))->FUN_00a03da0((char *)("RSM_Headline_Title"))))))->FUN_00a01350(::DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RSMSetting *>(&::g_011d32b8))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::RSMTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pTile))->FUN_00a03da0((char *)("RSM_EmptyRepairListText"))))))->FUN_00a01350(::DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RSMSetting *>(&::g_011d37d4))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->pTile3C))->FUN_00a01350(::DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RSMSetting *>(&::g_011d4da4))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->pTile50))->FUN_00a01350(::DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RSMSetting *>(&::g_011d4da4))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->pTile5C))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RSMSetting *>(&::g_011d1f2c))))->GetMenuTitle()))), true);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->pTile64))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RSMSetting *>(&::g_011d35c4))))->GetMenuTitle()))), true);
        }
        reinterpret_cast<::Menu *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))))->SetMenuVisibility(0);
        return pTile;
    }
    else if ((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0)) && ((int)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0))))->FUN_00726070())))
    {
        delete (*reinterpret_cast<::RSMMenu * *>(&::fnv_007b82c0::DAT_011da7f0));
    }
    return 0;
}

struct RSItemForm;

struct RSItem
{
};

struct RSTile;

struct RSTileList
{
};

struct RSTile
{
    int unk00;
    RSTileList kChildren;

};

struct RSRepairMenu
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int iTotalCost;
    int iSkill;
};

struct RSPlayer
{
};

int __cdecl GetLevelAdjustedMult(int aiSkill, float afHealth, float afValue);

// @fnv 0x007b7920
void __cdecl UpdateRepairMenuTile(RSTile* apTile, RSItem* apItem)
{
    if (!apTile || !apItem)
        return;

    int iCost = GetLevelAdjustedMult((*reinterpret_cast<::RSRepairMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->iSkill, reinterpret_cast<::FUN_004bcdb0_shell *>((apItem))->FUN_004bcdb0(true),
                                     ::FUN_0048e8a0((::TESForm *)(::RSItemForm *)(((::RSItemForm *)(reinterpret_cast<::Twin_0044ddc0 *>((apItem))->GetName())))));
    float fAlpha4 = (iCost > 0 && iCost <= reinterpret_cast<::ActorGoldQuery *>(((*reinterpret_cast<::RSPlayer * *>(&::_g_thePlayer))))->FUN_00891d70()) ? 255.0f : 128.0f;
    reinterpret_cast<::Tile *>((apTile))->Set(0xfaa, 0x11);
    reinterpret_cast<::Tile *>((apTile))->Set(DAT_011da7e4, iCost);
    (*reinterpret_cast<::RSRepairMenu * *>(&::fnv_007b82c0::DAT_011da7f0))->iTotalCost += iCost;
    reinterpret_cast<::FUN_00a012d0_t *>((((::RSTile *)(reinterpret_cast<::FUN_006317a0_struct *>(&(apTile->kChildren))->AddEight((int)(reinterpret_cast<::Callees *>(&(apTile->kChildren))->FUN_00726070()))))))->FUN_00a012d0(0xfa9, fAlpha4, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((::RSTile *)(reinterpret_cast<::TileFloatList *>((apTile))->FUN_00a03eb0(0x12)))))->FUN_00a012d0(0xfa9, fAlpha4, true);
    reinterpret_cast<::FUN_00a012d0_t *>((((::RSTile *)(reinterpret_cast<::FUN_006317a0_struct *>(&(apTile->kChildren))->AddEight((int)(((void *)(::FUN_00559450((int *)&(apTile->kChildren))))))))))->FUN_00a012d0(0xfa9, fAlpha4, true);
    reinterpret_cast<::Tile *>((apTile))->Set(0xfa3, reinterpret_cast<::TileListBoxCalls *>((apTile))->GetFloat(0xfac) >= 0.0);
    reinterpret_cast<::FUN_00a012d0_t *>((((::RSTile *)(reinterpret_cast<::TileFloatList *>((apTile))->FUN_00a03eb0(0x12)))))->FUN_00a012d0(0xfb1, reinterpret_cast<::FUN_004bcdb0_shell *>((apItem))->FUN_004bcdb0(true) * (double)0.6f, true);
    reinterpret_cast<::Tile *>((apTile))->Set(DAT_011da7dc, fAlpha4 == 255.0);
    if (reinterpret_cast<::FUN_004bddd0_shell *>((apItem))->FUN_004bddd0(false))
        reinterpret_cast<::Tile *>((((::RSTile *)(reinterpret_cast<::FUN_006317a0_struct *>(&(apTile->kChildren))->AddEight((int)(((void *)(::FUN_00559450((int *)&(apTile->kChildren))))))))))->Set(0xfa3, 1);
}

struct RepairMenuView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void Reset(int, int);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    RepairTile* tiles[16];
    RepairList items;
    int totalCost;
    int displayedCost;
};
struct RepairListView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Sort(int(__cdecl*)(ListBoxItem*, ListBoxItem*));
};
struct RepairPlayerView
{
};
struct RepairSetting
{
};
struct RepairStringTile
{
};
extern char DAT_01075f34, DAT_01070854;

// @fnv 0x007b8b30
void RepairMenu::RefreshRepairMenu()
{
    char szText[64];
    if ((*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))
    {
        ((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->totalCost = 0;
        ((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->Reset(17, 0);
        reinterpret_cast<::InventoryListBox *>((((RepairListView*)&((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->items)))->PopulateInventoryList((::InventoryOwner *)((*reinterpret_cast<::RepairPlayer * *>(&::_g_thePlayer))), (bool (*)(InventoryEntry *))(FUN_007b7b40), 0, (void (*)(Tile *, InventoryEntry *))(0), 1, 0);
        reinterpret_cast<::LBList_7314c0 *>((((RepairListView*)&((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->items)))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(Tile *, void *))::UpdateRepairMenuTile)), -1, 0x7fffffff);
        ((RepairListView*)&((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->items)->Sort(FUN_007b7c40);
        if (reinterpret_cast<::ActorGoldQuery *>((((RepairPlayerView*)(*reinterpret_cast<::RepairPlayer * *>(&::_g_thePlayer)))))->FUN_00891d70() > *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::RepairSetting *>(&::g_011d3a08)))))))
            FUN_00406d00(szText, 64, &DAT_01075f34, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RepairSetting *>(&::g_011d25b0))))->GetMenuTitle())), *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::RepairSetting *>(&::g_011d3a08)))))));
        else
            FUN_00406d00(szText, 64, &DAT_01070854, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RepairSetting *>(&::g_011d25b0))))->GetMenuTitle())),
                         reinterpret_cast<::ActorGoldQuery *>((((RepairPlayerView*)(*reinterpret_cast<::RepairPlayer * *>(&::_g_thePlayer)))))->FUN_00891d70());
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RepairStringTile*)tiles[1])))->FUN_00a01350(0xfc4, (char *)(szText), true);
        FUN_00406d00(szText, 64, &DAT_01070854, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RepairSetting *>(&::g_011d4030))))->GetMenuTitle())), ((RepairMenuView*)this)->displayedCost);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RepairStringTile*)tiles[0])))->FUN_00a01350(0xfc4, (char *)(szText), true);
        FUN_00406d00(szText, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RepairSetting *>(&::g_011d4780))))->GetMenuTitle())), ((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->totalCost);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((RepairStringTile*)((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->tiles[14])))->FUN_00a01350(0xfc4, (char *)(szText), true);
        ((Tile*)((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->tiles[14])
            ->Set(0xfaf,
                  ((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->totalCost > 0 &&
                      ((RepairMenuView*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->totalCost <= reinterpret_cast<::ActorGoldQuery *>((((RepairPlayerView*)(*reinterpret_cast<::RepairPlayer * *>(&::_g_thePlayer)))))->FUN_00891d70());
    }
}

struct StatTile
{
};
struct StatForm
{
    int FUN_00401170();
};
struct StatItem
{
};
struct StatItemProvider
{
    StatItem* FUN_007a1910();
};
struct StatValue
{
    float value;
};
struct StatSetting
{
};
int __cdecl strcat_s(char*, unsigned int, const char*);
struct StatMenu
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    StatTile* field34;
    StatTile* field38;
    StatTile* field3c;
    StatTile* field40;
    StatTile* field44;
    StatTile* field48;
    StatTile* field4c;
    StatTile* field50;
    StatTile* field54;
    StatTile* field58;
    StatTile* field5c;
    int field60;
    int field64;
    StatItemProvider field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    void UpdateItemComparison(int, StatTile*);
};
// @fnv 0x007b82f0
void StatMenu::UpdateItemComparison(int event, StatTile* tile)
{
    if (event == 17)
    {
        char text[64];
        StatItem* selectedItemTmp = field68.FUN_007a1910();
        float health2 = 0.0f;
        float projected6 = 0.0f;
        reinterpret_cast<::Tile *>((field5c))->Set(0xfaf, (int)reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(DAT_011da7dc));
        reinterpret_cast<::Tile *>((field38))->Set(0xfa3, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((field34))->FUN_00a01350(0xfcc, (char *)(reinterpret_cast<::ItemChange_004be200 *>((selectedItemTmp))->GetIconFilename((::TESObjectREFR *)(0))), true);
        reinterpret_cast<::Tile *>((field34))->Set(0xfa3, 1);
        health2 = ((double)(reinterpret_cast<::FUN_004bcdb0_shell *>((selectedItemTmp))->FUN_004bcdb0(1))) / 100.0;
        reinterpret_cast<::FUN_00a012d0_t *>((field3c))->FUN_00a012d0(0x1004, health2, true);
        if (((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName()))->FUN_00401170() == 40)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((field40))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d2c7c))))->GetMenuTitle()))), true);
            reinterpret_cast<::Tile *>((field40))->Set(
                DAT_011da7e8,
                (int)((double)(::InventoryStackRecord::RoundToNearestStep(::GetWeaponDamage((::TESObjectWEAP *)(::StatForm *)(((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName()))), health2, (::DamageExtra *)(selectedItemTmp), (::TESAmmo *)(0)), 1.0f))));
        }
        else if (((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName()))->FUN_00401170() == 24)
        {
            float armor3 = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((double)(::FUN_004be060((void *)(((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName())))))), health2)));
            float threshold0 = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((double)(::FUN_004be180((char *)(((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName())))))), health2)));
            if (threshold0 > 0.0)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field40))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d396c))))->GetMenuTitle()))), true);
                reinterpret_cast<::Tile *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field40))->Set(DAT_011da7e8, (int)threshold0);
            }
            else if (armor3 > 0.0)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field40))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                reinterpret_cast<::Tile *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field40))->Set(DAT_011da7e8, (int)armor3);
            }
            else
            {
                char empty0[128];
                ::TaskQueueInterface::CopyStringToBuffer(empty0, 128, "--");
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field40))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field40))->FUN_00a01350(DAT_011da7e8, (char *)(empty0), true);
            }
        }
        projected6 = ((::StatValue *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::StatSetting *>(&::originalRuntimeFloatSetting943))))))->value +
                     (((::StatValue *)&(::FUN_00403e20((float *)&(((StatSetting&)(*reinterpret_cast<::Cfg *>(&::originalRuntimeFloatSetting944)))))))->value - ((::StatValue *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::StatSetting *>(&::originalRuntimeFloatSetting943))))))->value) *
                         (field9c / 100.0f);
        projected6 = FUN_0040ebd0(projected6 / 10.0, 1.0f);
        if (((double)(::InventoryStackRecord::RoundToNearestStep(projected6, 0.001f))) <= ((double)(::InventoryStackRecord::RoundToNearestStep(health2, 0.001f))))
        {
            ::FUN_00406d00(text, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d4ee8))))->GetMenuTitle())), projected6 * 100.0, "%");
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((field4c))->FUN_00a01350(0xfc4, (char *)(text), true);
            reinterpret_cast<::Tile *>((field50))->Set(0xfa3, 0);
        }
        else
        {
            reinterpret_cast<::FUN_00a012d0_t *>((field50))->FUN_00a012d0(0x1004, projected6, true);
            reinterpret_cast<::Tile *>((field50))->Set(0xfa3, 1);
            if (((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName()))->FUN_00401170() == 40)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((field54))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d2c7c))))->GetMenuTitle()))), true);
                reinterpret_cast<::Tile *>((field54))->Set(DAT_011da7e8, (int)((double)(::InventoryStackRecord::RoundToNearestStep(::GetWeaponDamage((::TESObjectWEAP *)(::StatForm *)(((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName()))),
                                                                             projected6, (::DamageExtra *)(selectedItemTmp), (::TESAmmo *)(0)),
                                                             1.0f))));
            }
            else if (((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName()))->FUN_00401170() == 24)
            {
                float aThreshold1 = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((double)(::FUN_004be060((void *)(((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName())))))), projected6)));
                float armor6 = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((double)(::FUN_004be180((char *)(((::StatForm *)(reinterpret_cast<::Twin_0044ddc0 *>((selectedItemTmp))->GetName())))))), projected6)));
                if (armor6 > 0.0)
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field54))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d396c))))->GetMenuTitle()))), true);
                    reinterpret_cast<::Tile *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field54))->Set(DAT_011da7e8, (int)armor6);
                }
                else if (aThreshold1 > 0.0)
                {
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field54))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                    reinterpret_cast<::Tile *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field54))->Set(DAT_011da7e8, (int)aThreshold1);
                }
                else
                {
                    char emptyTmp[128];
                    ::TaskQueueInterface::CopyStringToBuffer(emptyTmp, 128, "--");
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field54))->FUN_00a01350(DAT_011da7e0, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((StatMenu*)(*reinterpret_cast<::DAT_holder * *>(&::fnv_007b82c0::DAT_011da7f0)))->field54))->FUN_00a01350(DAT_011da7e8, (char *)(emptyTmp), true);
                }
            }
            float healthDelta_2 = (reinterpret_cast<::TileListBoxCalls *>((field50))->GetFloat(0x1004) - reinterpret_cast<::TileListBoxCalls *>((field3c))->GetFloat(0x1004)) * 100.0;
            float statDelta2 = reinterpret_cast<::TileListBoxCalls *>((field54))->GetFloat(DAT_011da7e8) - reinterpret_cast<::TileListBoxCalls *>((field40))->GetFloat(DAT_011da7e8);
            healthDelta_2 = FUN_00404010(0.0f, healthDelta_2);
            statDelta2 = FUN_00404010(0.0f, statDelta2);
            ::FUN_00406d00(text, 64, "+%i", (int)(healthDelta_2 + 0.5));
            strcat_s(text, 64, "%");
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((field44))->FUN_00a01350(0xfc4, (char *)(text), true);
            ::FUN_00406d00(text, 64, "+%i", (int)(statDelta2 + 0.5));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((field48))->FUN_00a01350(0xfc4, (char *)(text), true);
            ::FUN_00406d00(text, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StatSetting *>(&::g_011d3cf4))))->GetMenuTitle())), (int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(DAT_011da7e4));
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((field58))->FUN_00a01350(0xfc4, (char *)(text), true);
            reinterpret_cast<::FUN_00a012d0_t *>((field58))->FUN_00a012d0(0xfa9, reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(DAT_011da7dc) ? 255.0f : 128.0f, true);
        }
    }
}


class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
    int FNV_FUN_0044ddc0Type();
};

class TESObjectWEAP : public TESBoundObject
{
  public:
};

class ExtraDataList
{
  public:
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;

    ExtraDataList();
    virtual ~ExtraDataList();
    void SetExtraHealth(float afHealth);
};

struct ExtraListNode
{
    void AddHead(ExtraDataList* const& apItem);
};

struct RepairEntry
{
};

struct RepairInventory
{
};

class RepairMenuData
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98;
    int iRepairSkill;

    void ApplyRepair(RepairEntry* apEntry);
};
// @fnv 0x007b7d80
void RepairMenu::HandleRepairAction(int iActionId, RepairTile* tile)
{
    if (!tile && iActionId >= 0 && iActionId < 16)
        tile = tiles[iActionId];
    switch (iActionId)
    {
    case 17:
        if (reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(DAT_011da7dc))
        {
            reinterpret_cast<::RepairMenuData *>(this)->ApplyRepair((::RepairEntry *)(void *)(items.FUN_007a1910()));
            reinterpret_cast<::FUN_008924e0 *>(((*reinterpret_cast<::RepairPlayer * *>(&::_g_thePlayer))))->SetRelationshipRank((::Actor *)((*reinterpret_cast<void * *>(&::g_pRepairServicesVendor))), (int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(DAT_011da7e4));
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID(&DAT_01075d38, 0x121)))->FUN_00ad8830(false);
            RefreshRepairMenu();
        }
        else
        {
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID(&DAT_01073a94, 0x121)))->FUN_00ad8830(false);
        }
        break;
    case 14:
        reinterpret_cast<::LBList_7314c0 *>(&(items))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((bool (&)(void *, void *))::fnv_007b82c0::FUN_007b82c0)), (int)(0), 0x7fffffff);
        reinterpret_cast<::FUN_008924e0 *>(((*reinterpret_cast<::RepairPlayer * *>(&::_g_thePlayer))))->SetRelationshipRank((::Actor *)((*reinterpret_cast<void * *>(&::g_pRepairServicesVendor))), totalCost);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID(&DAT_01075d38, 0x121)))->FUN_00ad8830(false);
        RefreshRepairMenu();
        break;
    case 15:
        FUN_007b78e0();
        break;
    }
}

// Computes a repair value from iRepairSkill and the entry's form, then merges or replaces the extra health extra data in the player's inventory changes.
// @fnv 0x007b7f70
void RepairMenuData::ApplyRepair(RepairEntry* apEntry)
{
    TESObjectWEAP* pWeapon;
    RepairEntry* pPlayerEntry;
    ExtraDataList* pNewList4;
    bool bMergedTmp;
    ExtraDataList* pOldListOut;
    ExtraListNode* pNodeOut;
    int iCount8;

    float fHealthPercent = 0.0f;
    fHealthPercent = ((::StatValue *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::StatSetting *>(&::originalRuntimeFloatSetting943))))))->value +
              (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Cfg *>(&::originalRuntimeFloatSetting944)))))) - ((::StatValue *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::StatSetting *>(&::originalRuntimeFloatSetting943))))))->value) * (iRepairSkill / 100.0f);
    fHealthPercent = FUN_0040ebd0(fHealthPercent / 10.0, 1.0f);
    pWeapon = dynamic_cast<TESObjectWEAP*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((apEntry))->GetName())));
    if (pWeapon)
        fHealthPercent *= reinterpret_cast<::FUN_004bcf00_stand *>((pWeapon))->GetModdedValue(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((apEntry))->HasEffect(10));
    else
        fHealthPercent *= ::TESHealthForm::GetBaseHealth((::TESForm *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((apEntry))->GetName()))));
    pPlayerEntry = ((::RepairEntry *)(reinterpret_cast<::FUN_004bfba0_shell *>((((::RepairInventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::RepairPlayer * *>(&::_g_thePlayer))))))))->FUN_004bfba0(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((apEntry))->GetName())), 1, 0)));
    pOldListOut = ((::ExtraListNode *)(::FUN_00559450((int *)(apEntry)))) ? *((::ExtraDataList **)(new ((void *)(((::ExtraListNode *)(::FUN_00559450((int *)(apEntry)))))) ::Vec3())) : 0;
    pNewList4 = new ExtraDataList;
    iCount8 = -1;
    bMergedTmp = false;
    iCount8 = reinterpret_cast<::FUN_00418770_shell *>((pOldListOut))->FUN_00418770();
    reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((pNewList4))->FUN_00412380(pOldListOut);
    reinterpret_cast<::FUN_00419ad0_shell *>((pNewList4))->FUN_00419ad0(1);
    pNewList4->SetExtraHealth(fHealthPercent);
    if (iCount8 > 1)
        reinterpret_cast<::FUN_00419ad0_shell *>((pOldListOut))->FUN_00419ad0(iCount8 - 1);
    for (pNodeOut = ((::ExtraListNode *)(::FUN_00559450((int *)(pPlayerEntry)))); pNodeOut && *((::ExtraDataList **)(new ((void *)(pNodeOut)) ::Vec3())); pNodeOut = ((::ExtraListNode *)(reinterpret_cast<::Callees *>((pNodeOut))->FUN_00726070())))
    {
        if (((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((apEntry))->GetName()))->FNV_FUN_0044ddc0Type() == 0x18 && ((void *)(reinterpret_cast<::FUN_004bde40_shell *>((apEntry))->FUN_004bde40())))
            break;
        if (!reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>(((*((::ExtraDataList **)(new ((void *)(pNodeOut)) ::Vec3())))))->FUN_004126c0(pNewList4, 1, 0) &&
            !reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((pNewList4))->FUN_004126c0(*((::ExtraDataList **)(new ((void *)(pNodeOut)) ::Vec3())), 1, 0))
        {
            reinterpret_cast<::FUN_00419ad0_shell *>(((*((::ExtraDataList **)(new ((void *)(pNodeOut)) ::Vec3())))))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>(((*((::ExtraDataList **)(new ((void *)(pNodeOut)) ::Vec3())))))->FUN_00418770() + 1);
            bMergedTmp = true;
        }
    }
    if (!bMergedTmp)
    {
        if (iCount8 > 1)
            ((::ExtraListNode *)(::FUN_00559450((int *)(pPlayerEntry))))->AddHead(pNewList4);
        else
            pOldListOut->SetExtraHealth(fHealthPercent);
    }
    else if (iCount8 == 1)
        reinterpret_cast<::ItemChangeListNode *>((((::ExtraListNode *)(::FUN_00559450((int *)(pPlayerEntry))))))->FUN_00905330((::InventoryStackRecord *const &)(pOldListOut));
    if (bMergedTmp || iCount8 == 1)
    {
        reinterpret_cast<::FUN_00419f80_shell *>((pNewList4))->FUN_00419f80((::ScriptLocals *)(0));
        delete pNewList4;
    }
}

#include "generated/data/fallout/interface/menus/repairservicesmenu.inc"
