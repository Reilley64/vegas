// fallout/interface/menus/repairmenu.cpp: RepairMenu, RepairAction, PreviewMenu (18 functions)

#include <cstdint>
#include "fnv/simple_list_node_view.h"
#include "fnv/inventory_entry_fields.h"
#include <new>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00418ba0_shell.h"
#include "fnv/decl/FUN_00419ad0_shell.h"
#include "fnv/decl/FUN_00419f80_shell.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004bcf00_stand.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_004bfba0_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_0071ae60_shell.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07ed0_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ItemChange_004be200.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/RList71a5.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESHealthForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00412380__FUN_00412380_shell.h"
#include "fnv/decl/fnv_004126c0__FUN_004126c0_shell.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_004d4bd0__InventoryChangeFilterHost.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a07c60__FUN_00a07c60_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/list71a__L71Menu.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00782000.h"
#include "fnv/symbols_007b5000.h"
#include "fnv/symbols_007b6000.h"
#include "fnv/symbols_007b7000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01047000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "repairmenu_packet.h"
static const int kGetClassValue = 1035;
// @fnv 0x007b54b0
int RepairMenu::GetClass()
{
    return kGetClassValue;
}
// Applies the accumulated movement offset to the menu's X/Y tile values and resets movement to zero.
// @fnv 0x0077f700
void RepairMenu::UpdateRepairList()
{
    static float baseX = ((TileListBoxCalls*)pMenu)->GetFloat(4001);
    static float baseY = ((TileListBoxCalls*)pMenu)->GetFloat(4002);
    float x = 0.0f;
    float y = 0.0f;
    if (movement > 0.0)
    {
        DAT_011d9e91 = true;
        FUN_004169a0(((float)(::FUN_004a4240())), x, y);
        x *= movement;
        y *= movement;
    }
    if (DAT_011d9e91)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((pMenu))->FUN_00a012d0(4001, baseX + x, true);
        reinterpret_cast<::FUN_00a012d0_t *>((pMenu))->FUN_00a012d0(4002, baseY + y, true);
    }
    if (movement == 0.0)
        DAT_011d9e91 = false;
    movement = 0.0f;
}
struct FUN_007b5730_shell : public RepairMenu
{
    bool FUN_007b5730();
};
// Loads repair_menu.xml, stores the resulting RepairMenu, initializes its list and tiles, and returns the tile or null on failure.
// @fnv 0x007b5520
Tile* RepairMenu::Create()
{
    Menu* pExistingMenu;
    Tile* pTile;
    InterfaceManager* pInterface;
    pInterface = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    pExistingMenu = ((::Menu *)(::FUN_00a09030(FUN_007b5720())));
    if (pExistingMenu)
        delete pExistingMenu;
    pTile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((pInterface->FUN_00586150()))->FUN_00a01b00((void *)("Data\\Menus\\repair_menu.xml"));
    DAT_011da75c = (RepairMenu*)reinterpret_cast<::FUN_00a03c90_shell *>((pTile))->FUN_00a03c90();
    if (DAT_011da75c && DAT_011da75c->GetID() == FUN_007b5720())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((DAT_011da75c))->FUN_00a1dc70((TileMenu*)pTile, false);
        ::FUN_00867a20((void *)(((InventoryMenu*)DAT_011da75c)));
        if (!reinterpret_cast<::FUN_007b5730_shell *>((DAT_011da75c))->FUN_007b5730())
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (((TileListBoxCalls*)pTile)->GetFloat(4007) == 6006.0 || ((TileListBoxCalls*)pTile)->GetFloat(4007) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(4013, Tile::GetInterfaceScale(), true);
        DAT_011da75c->m_kRepairList.Initialize(DAT_011da75c->m_pTiles[1], "RM_RepairListTemplate");
        DAT_011da75c->m_kRepairList.FUN_007a1930(false);
        reinterpret_cast<::FUN_00a01290_shell *>((DAT_011da75c->m_pTiles[5]))->SetTraitAndReset(::DAT_011da754, 1.0f);
        reinterpret_cast<::FUN_00a01290_shell *>((DAT_011da75c->m_pTiles[10]))->SetTraitAndReset(::DAT_011da754, 1.0f);
        DAT_011da75c->SetMenuVisibility(true);
        return pTile;
    }
    else
    {
        if (DAT_011da75c && ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)DAT_011da75c)))->FUN_00726070())))
            delete DAT_011da75c;
    }
    return 0;
}

// Checks the 13 entries at offset 0x28 and returns true only if none of them is zero.
// @fnv 0x007b5730
bool FUN_007b5730_shell::FUN_007b5730()
{
    for (int iIndex = 0; iIndex < 13; ++iIndex)
    {
        if (((int*)((char*)this + 0x28))[iIndex] == 0)
            return false;
    }
    return true;
}

// @fnv 0x007b5720
int FUN_007b5720()
{
    return 0x40b;
}

struct Host007b54f0
{
    void FUN_007b5770();
    void* DestroyIfFlagged(unsigned int);
};
struct Tile_Set_Helper
{
};
struct Box071ae60
{
};
struct Standin007b6a00
{
    char _00[0x48];
    Tile_Set_Helper* _48;
    Tile_Set_Helper* _4c;
    char _50[0x0C];
    Box071ae60 _5c;
    void FUN_007b6a00(int aiID, Tile* apTarget);
};
// For ID 14, clears tile 0xFA3 on _4c and, when _5c.FUN_0071ae60() returns more than 1, also clears it on _48.
// @fnv 0x007b6a00
void Standin007b6a00::FUN_007b6a00(int aiID, Tile* apTarget)
{
    if (aiID == 14)
    {
        reinterpret_cast<::Tile *>((_4c))->Set(0xFA3, 0);
        if (reinterpret_cast<::FUN_0071ae60_shell *>(&(_5c))->FUN_0071ae60() > 1)
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
struct FUN_007b6a50_Host
{
    virtual void Vf0() = 0;
    virtual void Vf1() = 0;
    virtual void Vf2() = 0;
    virtual void Vf3(int, int) = 0;
    bool HandleButton(int aiButton, float afValue);
};
// @fnv 0x007b6a50
bool FUN_007b6a50_Host::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 6:
    case 10:
        ::FUN_00706f30(3);
        this->Vf3(12, 0);
        break;
    }
    return bhandled;
}

struct FUN_007308e0
{
    virtual ~FUN_007308e0();
};
struct TileRemoveFade
{
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct FUN_007b5770 : public Menu_007a8b10
{
    char pad2[0x44];
    Tile* tile;
    char pad3[0x10];
    FUN_007308e0 helper;
    virtual ~FUN_007b5770();
};
// Calls FUN_007b5770, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x007b54f0
void* Host007b54f0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_007b5770 *>(this)->FUN_007b5770::~FUN_007b5770();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Removes the tile via TileRemoveFade with id 0xfa9 and clears DAT_011da75c.
// @fnv 0x007b5770
FUN_007b5770::~FUN_007b5770()
{
    reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((((TileRemoveFade*)tile)))->RemoveFadeItemsForTile(0xfa9);
    DAT_011da75c = 0;
}

struct HealthOwner
{
    bool IsEquipped(bool abCheck);
};

struct ChildTile;
struct ChildTileList
{
};

struct ChildTile
{
};

struct RepairTile
{
    int unk00;
    ChildTileList children;
};

struct SkillOwner
{
};

struct PlayerStub
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    SkillOwner skills;
};



// @fnv 0x007b57f0
void UpdateRepairTile(RepairTile* apTile, HealthOwner* apItem)
{
    if (!apTile || !apItem)
        return;

    float fHealthPercent = reinterpret_cast<::FUN_004bcdb0_shell *>((apItem))->FUN_004bcdb0(true);
    reinterpret_cast<::Tile *>((apTile))->Set(0xfaa, 0xe);
    reinterpret_cast<::Tile *>((apTile))->Set(0xfa3, reinterpret_cast<::TileListBoxCalls *>((apTile))->GetFloat(0xfac) >= 0.0);
    reinterpret_cast<::FUN_00a012d0_t *>((((::RepairTile *)(reinterpret_cast<::TileFloatList *>((apTile))->FUN_00a03eb0(0xf)))))->FUN_00a012d0(0xfb1, fHealthPercent * 0.6f, true);
    if (apItem->IsEquipped(false))
        reinterpret_cast<::Tile *>((((::ChildTile *)(reinterpret_cast<::FUN_006317a0_struct *>((void *)&(apTile->children))->AddEight((intptr_t)(((void *)(::FUN_00559450((int *)&(apTile->children))))))))))->Set(0xfa3, 1);

    float fRepairHealth = reinterpret_cast<::FUN_004bcdb0_shell *>(((*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760))))->FUN_004bcdb0(true);
    float fResult = 0.0f;
    int iOut = -1;
    fResult = ::fnv_00648090::ComputeSkillValue((int)(((reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))->skills))->GetActorValueAsInteger((::ActorValue::Index)(0x27))))), fRepairHealth, fHealthPercent, &iOut) / 100.0;
    fResult = FUN_0040ebd0(fResult, 1.0f);
    reinterpret_cast<::FUN_00a012d0_t *>((apTile))->FUN_00a012d0(0x1004, fResult, true);
}

struct FUN_007b6970_tile
{
};
struct FUN_007b6970_shell : public RepairMenu
{
    void SetRepairMenuText(const char* apText);
};

// @fnv 0x007b6970
void FUN_007b6970_shell::SetRepairMenuText(const char* apText)
{
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((FUN_007b6970_tile*)m_pTiles[8])))->FUN_00a01350(4036, (char *)(apText), true);
    reinterpret_cast<::Tile *>((((FUN_007b6970_tile*)m_pTiles[9])))->Set(4003, 0);
    reinterpret_cast<::Tile *>((((FUN_007b6970_tile*)m_pTiles[8])))->Set(4003, 1);
    if (!reinterpret_cast<::FUN_00a07ed0_shell *>((((FUN_007b6970_tile*)m_pTiles[8])))->FUN_00a07ed0(4009))
    {
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((FUN_007b6970_tile*)m_pTiles[8])))->StartFade(4009, 255.0f, 64.0f, 2.0f, true);
    }
}

namespace fnv_007b6fb0 {
class RepairMenu;


class RmMenu
{
  public:
    virtual ~RmMenu();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14(int, int);
};

class RmSub
{
  public:
    virtual ~RmSub();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
};

class RmTile
{
  public:
};

struct RmView
{
    RmMenu m_fMinimumV;
    char m_gap04[0x48 - 0x04];
    RmTile* m_p48;
    char m_gap4c[0x5c - 0x4c];
    RmSub m_sub;
};

// @fnv 0x007b6fb0
void ResetRepairMenu()
{
    ((RmView*)(*reinterpret_cast<::fnv_007b6fb0::RepairMenu * *>(&::DAT_011da75c)))->m_sub.vf1c();
    DAT_011da760 = 0;
    ((RmView*)(*reinterpret_cast<::fnv_007b6fb0::RepairMenu * *>(&::DAT_011da75c)))->m_fMinimumV.vf14(0xe, 0);
    reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((((RmView*)(*reinterpret_cast<::fnv_007b6fb0::RepairMenu * *>(&::DAT_011da75c)))->m_p48))->RemoveFadeItemsForTile(0xfa9);
    reinterpret_cast<::Tile *>((((RmView*)(*reinterpret_cast<::fnv_007b6fb0::RepairMenu * *>(&::DAT_011da75c)))->m_p48))->Set(0xfa3, 0);
}
}  // namespace fnv_007b6fb0

namespace fnv_007b7020 {
struct RepairInventory
{
};
struct RepairForm
{
    int FUN_00401170();
};
struct RepairTile
{
};
struct RepairString
{
};
struct RepairList
{
    virtual void vf00();
    virtual int vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual int vf14(int, int, int, int);
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20(void(__cdecl*)());
};
struct RepairMenuVirtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10(int, int);
};
struct RepairHud
{
};
struct RepairManager
{
};

// @fnv 0x007b7020
void __cdecl FUN_007b7020(intptr_t target)
{
    if (DAT_011da75c != 0)
    {
        if (target != 0)
        {
            (*reinterpret_cast<::fnv_007b7020::RepairInventory * *>(&::fnv_007b6fb0::DAT_011da760)) = reinterpret_cast<RepairInventory*>(target);
        }
        float percent = reinterpret_cast<::FUN_004bcdb0_shell *>(((*reinterpret_cast<::fnv_007b7020::RepairInventory * *>(&::fnv_007b6fb0::DAT_011da760))))->FUN_004bcdb0(1) / ::g_d100;
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[4])))->FUN_00a012d0(0x1004, percent, 1);
        reinterpret_cast<::Tile *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[4])))->Set(0xfa3, 1);
        RepairForm* form = ((::fnv_007b7020::RepairForm *)(reinterpret_cast<::InventoryEntryFields *>(((*reinterpret_cast<::fnv_007b7020::RepairInventory * *>(&::fnv_007b6fb0::DAT_011da760))))->pObject));
        int type = form->FUN_00401170();
        if (type == 0x28)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b7020::RepairString *>(&::g_011d2c7c))))->GetMenuTitle()))), {});
            reinterpret_cast<::Tile *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->Set(::DAT_011da754, (int)::InventoryStackRecord::RoundToNearestStep(::GetWeaponDamage((::TESObjectWEAP *)(form), percent, (::DamageExtra *)(target), (::TESAmmo *)(0)), 1.0f));
        }
        else if (type == 0x18)
        {
            RepairForm* branchForm = form;
            float low = ::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((float)(::FUN_004be060((void *)(branchForm)))), percent);
            float maximum = ::CombatDamageCalculator::CalculateArmorDamageThreshold((int)::FUN_004be180((char *)(branchForm)), percent);
            if (maximum > ::_DAT_01012060)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b7020::RepairString *>(&::g_011d396c))))->GetMenuTitle()))), {});
                reinterpret_cast<::Tile *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->Set(::DAT_011da754, (int)maximum);
            }
            else if (low > ::_DAT_01012060)
            {
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b7020::RepairString *>(&::g_011d20c4))))->GetMenuTitle()))), {});
                reinterpret_cast<::Tile *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->Set(::DAT_011da754, (int)low);
            }
            else
            {
                char unavailableText[128];
                ::TaskQueueInterface::CopyStringToBuffer(unavailableText, 128, ::DAT_01047008);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b7020::RepairString *>(&::g_011d20c4))))->GetMenuTitle()))), {});
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->FUN_00a01350(::DAT_011da754, (char *)(unavailableText), 1);
            }
        }
        else
        {
            char unavailableText[128];
            ::TaskQueueInterface::CopyStringToBuffer(unavailableText, 128, ::DAT_01047008);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b7020::RepairString *>(&::g_011d20c4))))->GetMenuTitle()))), {});
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])))->FUN_00a01350(::DAT_011da754, (char *)(unavailableText), 1);
        }

        if (target != 0)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[3])))->FUN_00a01350(0xfcc, (char *)(((std::intptr_t)(reinterpret_cast<::ItemChange_004be200 *>(((*reinterpret_cast<::fnv_007b7020::RepairInventory * *>(&::fnv_007b6fb0::DAT_011da760))))->GetIconFilename((::TESObjectREFR *)(0))))), {});
            ::fnv_007b6aa0::PopulateRepairMenu();
        }
        reinterpret_cast<::LBList_7314c0 *>((reinterpret_cast<RepairList*>(&DAT_011da75c->m_kRepairList)))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void (*)())(&((void (&)())::UpdateRepairTile)), 0, 0x7fffffff);
        reinterpret_cast<RepairList*>(&DAT_011da75c->m_kRepairList)->vf20(&((void (&)())::CompareSortEntries));
        reinterpret_cast<::Tile *>((reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[0])))->Set(
                ::DAT_011da754,
                reinterpret_cast<::ActorValueOwner *>((reinterpret_cast<RepairHud*>(reinterpret_cast<char*>((*reinterpret_cast<::fnv_007b7020::RepairHud * *>(&::_g_thePlayer))) + 0xa4)))->GetActorValueAsInteger((::ActorValue::Index)(0x27)));
        if (target && ::FUN_004b71d0())
        {
            reinterpret_cast<::FocusManager *>((reinterpret_cast<RepairManager*>(
                ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860({}, {}, {});
        }
        reinterpret_cast<RepairMenuVirtual*>(DAT_011da75c)
            ->vf10(0xe, reinterpret_cast<RepairList*>(&DAT_011da75c->m_kRepairList)->vf04());
        if (target != 0)
        {
            ::FUN_007044c0(1, 0, 0);
            reinterpret_cast<::TutorialMessageGate718 *>((reinterpret_cast<RepairManager*>(reinterpret_cast<char*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))) + 0x4d4)))->FUN_00718630({}, {}, {});
        }
    }
}
}  // namespace fnv_007b7020

struct ValueObj_7b
{
};
struct ValueList_7b
{
};
struct FUN_00a01230_shell
{
    int unk00;
    ValueList_7b list;
    bool IsTraitNonZero(int aiFlag);
};
struct FUN_004bddd0_shell
{
    bool FUN_004bddd0(bool abFlag);
};
struct SortEntry_7b
{
    FUN_00a01230_shell* pItem;
    FUN_004bddd0_shell* pData;
};


// Compares two sort entries by a flag, a list value against 255, health, and a secondary predicate, returning -1, 0 or 1.
// @fnv 0x007b5950
int CompareSortEntries(SortEntry_7b* apA, SortEntry_7b* apB)
{
    int iResult = 0;
    bool bHasA6 = apA->pItem->IsTraitNonZero(::DAT_011da748);
    bool bHasB = apB->pItem->IsTraitNonZero(::DAT_011da748);
    bool bLowA = reinterpret_cast<::TileListBoxCalls *>(((*((::ValueObj_7b **)(reinterpret_cast<::InventoryStackRecord *>(&(apA->pItem->list))->GetPayloadAddress())))))->GetFloat({}) < 255.0;
    bool bLowB4 = reinterpret_cast<::TileListBoxCalls *>(((*((::ValueObj_7b **)(reinterpret_cast<::InventoryStackRecord *>(&(apB->pItem->list))->GetPayloadAddress())))))->GetFloat({}) < 255.0;
    if (bHasA6 && !bHasB)
    {
        iResult = -1;
    }
    else if (!bHasA6 && bHasB)
    {
        iResult = 1;
    }
    else if (bLowA && !bLowB4)
    {
        iResult = 1;
    }
    else if (!bLowA && bLowB4)
    {
        iResult = -1;
    }
    else
    {
        iResult = (reinterpret_cast<::FUN_004bcdb0_shell *>((apA->pData))->FUN_004bcdb0(true) < reinterpret_cast<::FUN_004bcdb0_shell *>((apB->pData))->FUN_004bcdb0(true))
                      ? 1
                      : ((reinterpret_cast<::FUN_004bcdb0_shell *>((apA->pData))->FUN_004bcdb0(true) > reinterpret_cast<::FUN_004bcdb0_shell *>((apB->pData))->FUN_004bcdb0(true)) ? -1 : 0);
        if (bLowA && bLowB4)
        {
            iResult = -iResult;
        }
        if (iResult == 0)
        {
            if (apA->pData->FUN_004bddd0(false))
            {
                iResult = -1;
            }
            else if (apB->pData->FUN_004bddd0(false))
            {
                iResult = 1;
            }
        }
    }
    return iResult;
}

struct FloatValue
{
};
struct Values
{
};
struct ClickTile
{
    int unk00;
    Values values;
};
struct FormStub
{
};
struct ItemStub
{
};
struct RepairList
{
    virtual void vf0();
    virtual intptr_t SelectedIndex();
    ItemStub* Selected();
};
struct AudioPlaybackHandle
{
    int unk00, unk04, unk08;
    ~AudioPlaybackHandle();
};
struct AudioMgr
{
    AudioPlaybackHandle GetSoundByEditorID(const char*, int, int);
};
struct InterfaceStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void Repair(intptr_t, intptr_t, int, int, int, int, int, int, int, int);
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void Refresh();
};
struct FUN_007b5b40_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Click(int, ClickTile*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    ClickTile* tiles[13];
    RepairList list;
    void HandleRepairMenuAction(int id, ClickTile* target);
};
class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
class TESObjectWEAP : public TESBoundObject
{
  public:
};
struct ExtraDataList
{
    virtual ~ExtraDataList();
    int flags04;
    int flags08;
    int flags0c;
    int flags10;
    int flags14;
    int flags18;
    int flags1c;
    ExtraDataList();
    void SetExtraHealth(float);
};
struct RepairExtraNode
{
    void FUN_0063f7b0();
    void FUN_005ae3d0(ExtraDataList*&);
};
struct RepairInventoryItem : HealthOwner
{
};
struct RepairInventoryChanges
{
};
struct RepairAction : RepairMenu
{
    void ApplyRepair(HealthOwner* source);
};
// @fnv 0x007b5b40
void FUN_007b5b40_cls::HandleRepairMenuAction(int aiActionId, ClickTile* apTargetTile)
{
    bool unused4 = false;
    if (!apTargetTile && aiActionId >= 0 && aiActionId < 13)
        apTargetTile = tiles[aiActionId];
    switch (aiActionId)
    {
    case 14:
        if (reinterpret_cast<::TileListBoxCalls *>(((*((::FloatValue **)(reinterpret_cast<::InventoryStackRecord *>(&(apTargetTile->values))->GetPayloadAddress())))))->GetFloat({}) < 255.0)
        {
        }
        else
        {
            if (list.Selected() != (ItemStub*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)) && reinterpret_cast<::FUN_00a01230_shell *>((tiles[9]))->IsTraitNonZero(0xfa3))
            {
                ItemStub* item5 = list.Selected();
                intptr_t base = ((::FormStub *)(::FUN_00559450((int *)(item5)))) ? *((intptr_t *)(&reinterpret_cast<::SimpleListNodeView*>(((::FormStub *)(::FUN_00559450((int *)(item5)))))->m_item)) : 0;
                reinterpret_cast<::RepairAction *>(this)->ApplyRepair((::HealthOwner *)(item5));
                (*reinterpret_cast<::InterfaceStub * *>(&::_g_thePlayer))->Repair(((intptr_t)(reinterpret_cast<::InventoryEntryFields *>((item5))->pObject)), base, 1, 0, 0, 0, 0, 0, 1, 0);
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::AudioPlaybackHandle &)(((::AudioMgr *)(::FUN_00453a70()))->GetSoundByEditorID("UIRepairWeapon", 0x121, 0)))->FUN_00ad8830({});
                reinterpret_cast<::RList71a5 *>(&(list))->RemoveTile((::LBTileObj *)(list.SelectedIndex()));
                if (reinterpret_cast<::FUN_0071ae60_shell *>(&(list))->FUN_0071ae60() == 1 || reinterpret_cast<::FUN_004bcdb0_shell *>(((*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760))))->FUN_004bcdb0(true) >= 99.0)
                    Click(12, 0);
                else
                    ::fnv_007b7020::FUN_007b7020(0);
                if (reinterpret_cast<::FUN_004bddd0_shell *>((item5))->FUN_004bddd0(false))
                {
                    (*reinterpret_cast<::InterfaceStub * *>(&::_g_thePlayer))->Refresh();
                    ::FUN_00782a90();
                }
            }
        }
        break;
    case 12:
        ::s717280::FUN_00717280(0x24);
        ::sleep704::FUN_007048f0(1, 0, 0);
        break;
    }
}
// Computes a repair amount from skill and health, applies it to the item's extra data, and merges the repaired entry into the inventory changes list.
// @fnv 0x007b5d80
void RepairAction::ApplyRepair(HealthOwner* source)
{
    float repairVal = 0.0f;
    repairVal = ::fnv_00648090::ComputeSkillValue((int)(((reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))->skills))->GetActorValueAsInteger((::ActorValue::Index)(39))))), reinterpret_cast<::FUN_004bcdb0_shell *>(((*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760))))->FUN_004bcdb0(true),
                                    reinterpret_cast<::FUN_004bcdb0_shell *>((source))->FUN_004bcdb0(true), 0) /
                100.0;
    repairVal = FUN_0040ebd0(repairVal, 1.0f);
    TESObjectWEAP* bound = dynamic_cast<TESObjectWEAP*>(((::TESBoundObject *)(reinterpret_cast<::InventoryEntryFields *>((((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->pObject)));
    if (bound)
        repairVal *= reinterpret_cast<::FUN_004bcf00_stand *>((bound))->GetModdedValue(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->HasEffect(10));
    else
        repairVal *= ::TESHealthForm::GetBaseHealth((::TESForm *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::InventoryEntryFields *>((((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->pObject))));
    RepairInventoryItem* entryTmp =
        ((::RepairInventoryItem *)(reinterpret_cast<::FUN_004bfba0_shell *>((((::RepairInventoryChanges *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))))))))->FUN_004bfba0(((::TESBoundObject *)(reinterpret_cast<::InventoryEntryFields *>((((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->pObject)), true, false)));
    ExtraDataList* extra7 = ((::RepairExtraNode *)(::FUN_00559450((int *)(((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))))
                                ? ((::ExtraDataList *)(reinterpret_cast<::SimpleListNodeView*>(((::RepairExtraNode *)(::FUN_00559450((int *)(((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760))))))))->m_item))
                                : 0;
    ExtraDataList* repairA = new ExtraDataList;
    int count = -1;
    bool found9 = false;
    count = reinterpret_cast<::FUN_00418770_shell *>((extra7))->FUN_00418770();
    reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((repairA))->FUN_00412380(extra7);
    reinterpret_cast<::FUN_00419ad0_shell *>((repairA))->FUN_00419ad0(1);
    repairA->SetExtraHealth(repairVal);
    ::TopicMenuController::IncrementMiscStat(34);
    ((::RepairExtraNode *)(::FUN_00559450((int *)(((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))))->FUN_0063f7b0();
    if (count > 1)
        reinterpret_cast<::FUN_00419ad0_shell *>((extra7))->FUN_00419ad0(count - 1);
    for (RepairExtraNode* node = ((::RepairExtraNode *)(::FUN_00559450((int *)(entryTmp)))); node && ((::ExtraDataList *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)); node = ((::RepairExtraNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        if (!reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((((::ExtraDataList *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))))->FUN_004126c0(repairA, true, false) &&
            !reinterpret_cast<::fnv_004126c0::FUN_004126c0_shell *>((repairA))->FUN_004126c0(((::ExtraDataList *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)), true, false))
        {
            reinterpret_cast<::FUN_00419ad0_shell *>((((::ExtraDataList *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))))->FUN_00419ad0(reinterpret_cast<::FUN_00418770_shell *>((((::ExtraDataList *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))))->FUN_00418770() + 1);
            ((::RepairExtraNode *)(::FUN_00559450((int *)(((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))))->FUN_005ae3d0(*((::ExtraDataList **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)));
            found9 = true;
        }
    }
    if (!found9)
    {
        if (count > 1)
        {
            ((::RepairExtraNode *)(::FUN_00559450((int *)(entryTmp))))->FUN_005ae3d0(repairA);
            ((::RepairExtraNode *)(::FUN_00559450((int *)(((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))))->FUN_005ae3d0(repairA);
        }
        else
        {
            extra7->SetExtraHealth(repairVal);
            ((::RepairExtraNode *)(::FUN_00559450((int *)(((RepairInventoryItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))))->FUN_005ae3d0(extra7);
        }
    }
    else if (count == 1)
    {
        reinterpret_cast<::ItemChangeListNode *>((((::RepairExtraNode *)(::FUN_00559450((int *)(entryTmp))))))->FUN_00905330((::InventoryStackRecord *const &)(extra7));
    }
    if (found9 || count == 1)
    {
        reinterpret_cast<::FUN_00419f80_shell *>((repairA))->FUN_00419f80((::ScriptLocals *)(void *)(0));
        delete repairA;
    }
}

struct PreviewForm
{
    int Type();
};
struct PreviewItem
{
};
struct PreviewTile
{
    float Value(int);
};
struct PreviewList
{
    virtual void v0();
    virtual PreviewTile* GetTile();
    PreviewItem* Selected();
};
struct PreviewSetting
{
};
struct PreviewPipboy
{
    void Rotate(int, float, float, bool);
};
struct PreviewInterface
{
};
extern int DAT_011da7d8;
int AppendPreview(char*, unsigned int, const char*);
struct PreviewMenu
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
    PreviewTile* tile38;
    PreviewTile* tile3c;
    PreviewTile* tile40;
    PreviewTile* tile44;
    PreviewTile* tile48;
    PreviewTile* tile4c;
    PreviewTile* tile50;
    PreviewTile* tile54;
    int unk58;
    PreviewList list;
    void UpdatePreviewComparison(int, PreviewTile*);
};

// @fnv 0x007b6120
void PreviewMenu::UpdatePreviewComparison(int event, PreviewTile* target)
{
    char text[64];
    switch (event)
    {
    case 14: {
        PreviewItem* item7 = list.Selected();
        int selection7 = item7 ? (int)reinterpret_cast<::TileListBoxCalls *>((list.GetTile()))->GetFloat(0xfac) : 0;
        if (DAT_011da7d8 != selection7)
        {
            ((::PreviewPipboy *)(reinterpret_cast<::Interface *>((((::PreviewInterface *)(::fnv_004b7210::FUN_004b7210()))))->GetPipboyManager()))->Rotate(
                0, DAT_011da7d8 < selection7 ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PreviewSetting *>(&::g_011db2f0)))))) : -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PreviewSetting *>(&::g_011db2f0)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PreviewSetting *>(&::g_011db358)))))), true);
            DAT_011da7d8 = selection7;
        }
        if (item7 && (*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))
        {
            float limitX = 75.0f;
            if (((::PreviewForm *)(reinterpret_cast<::InventoryEntryFields *>((item7))->pObject))->Type() == 24)
                limitX = 50.0f;
            if (limitX <= reinterpret_cast<::FUN_004bcdb0_shell *>((item7))->FUN_004bcdb0(true))
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)->tile54))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d3dcc))))->GetMenuTitle()))), true);
            else
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)->tile54))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d1f2c))))->GetMenuTitle()))), true);
            if (item7 == (PreviewItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))
            {
                if (reinterpret_cast<::FUN_0071ae60_shell *>(&(list))->FUN_0071ae60() > 1)
                    reinterpret_cast<::FUN_007b6970_shell *>(this)->SetRepairMenuText(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d270c))))->GetMenuTitle())));
                reinterpret_cast<::FUN_00a012d0_t *>((tile54))->FUN_00a012d0(::FUN_00a01860("_line_alpha"), 128.0f, true);
            }
            else
            {
                float health4 = reinterpret_cast<::TileListBoxCalls *>((target))->GetFloat(0x1004);
                int cost4 = (int)reinterpret_cast<::TileListBoxCalls *>((target))->GetFloat(0x1005);
                if (cost4 > 100)
                {
                    ::FUN_00406d00(text, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d4ee8))))->GetMenuTitle())), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PreviewSetting *>(&::originalRuntimeFloatSetting944)))))) * 10.0, "%");
                    reinterpret_cast<::FUN_007b6970_shell *>(this)->SetRepairMenuText(text);
                    reinterpret_cast<::FUN_00a012d0_t *>((tile54))->FUN_00a012d0(::FUN_00a01860("_line_alpha"), 128.0f, true);
                }
                else if (cost4 > 0)
                {
                    ::FUN_00406d00(text, 64, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d2b20))))->GetMenuTitle())), cost4, "%");
                    reinterpret_cast<::FUN_007b6970_shell *>(this)->SetRepairMenuText(text);
                    reinterpret_cast<::FUN_00a012d0_t *>((tile54))->FUN_00a012d0(::FUN_00a01860("_line_alpha"), 128.0f, true);
                }
                else
                {
                    reinterpret_cast<::FUN_00a012d0_t *>((tile54))->FUN_00a012d0(::FUN_00a01860("_line_alpha"), 255.0f, true);
                    reinterpret_cast<::FUN_00a012d0_t *>((tile4c))->FUN_00a012d0(0x1004, health4, true);
                    reinterpret_cast<::Tile *>((tile4c))->Set(0xfa3, 1);
                    reinterpret_cast<::Tile *>((tile48))->Set(0xfa3, 0);
                    if (((::PreviewForm *)(reinterpret_cast<::InventoryEntryFields *>((((PreviewItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->pObject))->Type() == 40)
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile50))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d2c7c))))->GetMenuTitle()))), true);
                        reinterpret_cast<::Tile *>((tile50))->Set(::DAT_011da754,
                                       (int)::InventoryStackRecord::RoundToNearestStep(::GetWeaponDamage((::TESObjectWEAP *)(::PreviewForm *)(((::PreviewForm *)(reinterpret_cast<::InventoryEntryFields *>((((PreviewItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->pObject))), health4,
                                                                     (::DamageExtra *)(::PreviewItem *)((PreviewItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760))), (::TESAmmo *)(0)),
                                                         1.0f));
                    }
                    else if (((::PreviewForm *)(reinterpret_cast<::InventoryEntryFields *>((item7))->pObject))->Type() == 24)
                    {
                        char empty[128];
                        {
                            PreviewForm* armor = ((::PreviewForm *)(reinterpret_cast<::InventoryEntryFields *>((((PreviewItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->pObject));
                            float oldhealth5 = reinterpret_cast<::FUN_004bcdb0_shell *>((((PreviewItem*)(*reinterpret_cast<::HealthOwner * *>(&::fnv_007b6fb0::DAT_011da760)))))->FUN_004bcdb0(true) / 100.0;
                            float oldarmor = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((float)(::FUN_004be060((void *)(armor)))), oldhealth5)));
                            float oldthreshold3 = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)::FUN_004be180((char *)(armor)), oldhealth5)));
                            float newarmor3 = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)((float)(::FUN_004be060((void *)(armor)))), health4)));
                            float newthreshold2 = ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold((int)::FUN_004be180((char *)(armor)), health4)));
                            ::TaskQueueInterface::CopyStringToBuffer(empty, 128, "--");
                            if (newthreshold2 > 0.0)
                            {
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)
                                    ->tile3c))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d396c))))->GetMenuTitle()))), true);
                                if (oldthreshold3 > 0.0)
                                    reinterpret_cast<::Tile *>((((PreviewMenu*)DAT_011da75c)->tile3c))->Set(::DAT_011da754, (int)oldthreshold3);
                                else
                                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)->tile3c))->FUN_00a01350(::DAT_011da754, (char *)(empty), true);
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)
                                    ->tile50))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d396c))))->GetMenuTitle()))), true);
                                reinterpret_cast<::Tile *>((((PreviewMenu*)DAT_011da75c)->tile50))->Set(::DAT_011da754, (int)newthreshold2);
                            }
                            else if (newarmor3 > 0.0)
                            {
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)
                                    ->tile3c))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                                if (oldarmor > 0.0)
                                    reinterpret_cast<::Tile *>((((PreviewMenu*)DAT_011da75c)->tile3c))->Set(::DAT_011da754, (int)oldarmor);
                                else
                                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)->tile3c))->FUN_00a01350(::DAT_011da754, (char *)(empty), true);
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)
                                    ->tile50))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                                reinterpret_cast<::Tile *>((((PreviewMenu*)DAT_011da75c)->tile50))->Set(::DAT_011da754, (int)newarmor3);
                            }
                            else
                            {
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)
                                    ->tile3c))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)->tile3c))->FUN_00a01350(::DAT_011da754, (char *)(empty), true);
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)
                                    ->tile50))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::PreviewSetting *>(&::g_011d20c4))))->GetMenuTitle()))), true);
                                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PreviewMenu*)DAT_011da75c)->tile50))->FUN_00a01350(::DAT_011da754, (char *)(empty), true);
                            }
                        }
                    }
                    float healthdiff8 = (reinterpret_cast<::TileListBoxCalls *>((tile4c))->GetFloat(0x1004) - reinterpret_cast<::TileListBoxCalls *>((tile38))->GetFloat(0x1004)) * 100.0;
                    float statdiff9 = reinterpret_cast<::TileListBoxCalls *>((tile50))->GetFloat(::DAT_011da754) - reinterpret_cast<::TileListBoxCalls *>((tile3c))->GetFloat(::DAT_011da754);
                    healthdiff8 = ::FUN_00404010(0.0f, healthdiff8);
                    statdiff9 = ::FUN_00404010(0.0f, statdiff9);
                    ::FUN_00406d00(text, 64, "+%i", (int)(healthdiff8 + 0.5));
                    AppendPreview(text, 64, "%");
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile40))->FUN_00a01350(0xfc4, (char *)(text), true);
                    ::FUN_00406d00(text, 64, "+%i", (int)(statdiff9 + 0.5));
                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile44))->FUN_00a01350(0xfc4, (char *)(text), true);
                }
            }
        }
        break;
    }
    }
}

namespace fnv_007b6aa0 {
struct Extra
{
};
struct Item;
struct ExtraNode
{
};
struct Item
{
    int unk00;
    int unk04;
    void* unk08;
    Item(void*, int);
};
struct ItemNode
{
    Item* data;
    ItemNode* next;
    ItemNode();
    ~ItemNode();
};
struct Changes
{
};
struct Value
{
};
struct UITile
{
};
struct Box
{
};
struct RepairView
{
    int unk00;
    void* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    UITile* tile28;
    int unk2c;
    UITile* tile30;
    int unk34;
    UITile* tile38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    UITile* tile4c;
    int unk50;
    UITile* tile54;
    UITile* tile58;
    Box box;
};
struct Setting
{
};
struct ExtraList
{
    void AddHead(Extra*&);
};
// @fnv 0x007b6aa0
void __cdecl PopulateRepairMenu()
{
    if (!(*reinterpret_cast<::fnv_007b6aa0::Item * *>(&::fnv_007b6fb0::DAT_011da760)))
        return;
    ItemNode selectedExtra;
    {
        Changes* c;
        c = ((::fnv_007b6aa0::Changes *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<void * *>(&::_g_thePlayer))))));
        reinterpret_cast<::fnv_004d4bd0::InventoryChangeFilterHost *>((c))->FilterInventoryChanges(((void *)((*reinterpret_cast<::fnv_007b6aa0::Item * *>(&::fnv_007b6fb0::DAT_011da760))->unk08)), (::fnv_004d4bd0::MatchedChanges *)(::fnv_007b6aa0::ItemNode *)(&selectedExtra));
    }
    for (ItemNode* node = &selectedExtra; node && ((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)); node = ((::fnv_007b6aa0::ItemNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        UITile* n;
        n = 0;
        Item* item;
        item = 0;
        for (int index = 0; index < ((std::intptr_t)(((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->unk04)); ++index)
        {
            float rawHealth;
            float extra;
            rawHealth = reinterpret_cast<::FUN_004bcdb0_shell *>((((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))))->FUN_004bcdb0(true);
            extra = ::InventoryStackRecord::GetConditionPercent(rawHealth);
            bool tmp;
            tmp = false;
            Extra* special;
            special = ((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)(((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))) ? ((::fnv_007b6aa0::Extra *)(reinterpret_cast<::SimpleListNodeView*>(((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)(((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))))->m_item)) : 0;
            if (special && reinterpret_cast<::FUN_00418ba0_shell *>((special))->FUN_00418ba0())
                tmp = true;
            if (extra < 100.0 || ((void *)(((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->unk08)) != ((void *)((*reinterpret_cast<::fnv_007b6aa0::Item * *>(&::fnv_007b6fb0::DAT_011da760))->unk08)))
            {
                if (!index)
                {
                    item = ((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
                    n = ((::fnv_007b6aa0::UITile *)(reinterpret_cast<::list71a::L71Menu *>(&((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->box))->FUN_0071a320((intptr_t)(item), reinterpret_cast<::FUN_004be2d0_shell *>((item))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
                    if (n && ((void *)(item->unk08)) == ((void *)((*reinterpret_cast<::fnv_007b6aa0::Item * *>(&::fnv_007b6fb0::DAT_011da760))->unk08)))
                    {
                        Extra* x;
                        x = ((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)(item)))) ? ((::fnv_007b6aa0::Extra *)(reinterpret_cast<::SimpleListNodeView*>(((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)(item)))))->m_item)) : 0;
                        Extra* list;
                        list = ((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)((*reinterpret_cast<::fnv_007b6aa0::Item * *>(&::fnv_007b6fb0::DAT_011da760)))))) ? ((::fnv_007b6aa0::Extra *)(reinterpret_cast<::SimpleListNodeView*>(((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)((*reinterpret_cast<::fnv_007b6aa0::Item * *>(&::fnv_007b6fb0::DAT_011da760)))))))->m_item)) : 0;
                        if (x == list)
                        {
                            (*reinterpret_cast<::fnv_007b6aa0::Item * *>(&::fnv_007b6fb0::DAT_011da760)) = item;
                            reinterpret_cast<::Tile *>((n))->Set(::DAT_011da748, 1);
                            Value* healthValue;
                            healthValue = ((::fnv_007b6aa0::Value *)(reinterpret_cast<::FUN_00a00e90_shell *>(((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->tile30))->FindTraitValue(0xfb0)));
                            Value* p;
                            p = ((::fnv_007b6aa0::Value *)(reinterpret_cast<::FUN_00a00e90_shell *>(((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->tile30))->FindTraitValue(0xfa2)));
                            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((healthValue))->RemoveFromReactions();
                            reinterpret_cast<::AGOwner *>((healthValue))->FUN_00a09130(0x7d0, (::Tile *)(n), 0xfb0);
                            reinterpret_cast<::P03Value *>((healthValue))->AppendFloatAction(0x7d2, 1.0f);
                            reinterpret_cast<::fnv_00a09410::EvalValue *>((healthValue))->FUN_00a09410(0);
                            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((p))->RemoveFromReactions();
                            reinterpret_cast<::AGOwner *>((p))->FUN_00a09130(0x7d0, (::Tile *)(n), 0xfa2);
                            reinterpret_cast<::fnv_00a09410::EvalValue *>((p))->FUN_00a09410(0);
                        }
                        else if (tmp || reinterpret_cast<::FUN_004bddd0_shell *>((item))->FUN_004bddd0(false))
                            reinterpret_cast<::RList71a5 *>(&((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->box))->RemoveTile((::LBTileObj *)(n));
                    }
                }
                else
                {
                    item = new Item(((void *)(((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item))->unk08)), 1);
                    for (ExtraNode* extraNode = ((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)(((::fnv_007b6aa0::Item *)(reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))); extraNode && ((::fnv_007b6aa0::Extra *)(reinterpret_cast<::SimpleListNodeView*>(extraNode)->m_item));
                         extraNode = ((::fnv_007b6aa0::ExtraNode *)(reinterpret_cast<::Callees *>((extraNode))->FUN_00726070())))
                        ((ExtraList*)((::fnv_007b6aa0::ExtraNode *)(::FUN_00559450((int *)(item)))))->AddHead(*((::fnv_007b6aa0::Extra **)(&reinterpret_cast<::SimpleListNodeView*>(extraNode)->m_item)));
                    n = ((::fnv_007b6aa0::UITile *)(reinterpret_cast<::list71a::L71Menu *>(&((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->box))->FUN_0071a320((intptr_t)(item), reinterpret_cast<::FUN_004be2d0_shell *>((item))->GetTargetFullName(), (int (*)(list71a::L71Item *, list71a::L71Item *))(0), (::list71a::L71Tile *)(0))));
                }
            }
        }
    }
    if (::FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b6aa0::Setting *>(&::g_011c3cb4))))->GetMenuTitle())), "ENGLISH"))
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::fnv_007b6aa0::UITile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::fnv_007b6aa0::UITile *)((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->unk04))))->FUN_00a03da0((char *)("RM_Headline_Title"))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b6aa0::Setting *>(&::g_011d4378))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->tile28))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b6aa0::Setting *>(&::g_011d4030))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->tile38))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b6aa0::Setting *>(&::g_011d4da4))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->tile4c))->FUN_00a01350(::DAT_011da74c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b6aa0::Setting *>(&::g_011d4da4))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->tile54))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b6aa0::Setting *>(&::g_011d1f2c))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007b6aa0::RepairView * *>(&::DAT_011da75c))->tile58))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b6aa0::Setting *>(&::g_011d29f4))))->GetMenuTitle()))), true);
    }
}
}  // namespace fnv_007b6aa0

#include "generated/data/fallout/interface/menus/repairmenu.inc"
