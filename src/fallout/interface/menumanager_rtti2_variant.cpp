// src/fallout/interface/menumanager_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BookMenu). The skeleton of src/fallout/interface/menumanager.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/FUN_004fd3a0_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_0073a000.h"
#include "fnv/symbols_0075b000.h"
#include "fnv/symbols_0076b000.h"
#include "fnv/symbols_00784000.h"
#include "fnv/symbols_00788000.h"
#include "fnv/symbols_007cb000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_011f3000.h"
#include "menumanager_decls_rtti2_menumanager.h"

// 0x00720aa0  838 bytes  /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), one int arg: fetch the cached menu for that class, delete
// it, then build the class's menu through an if/else-if chain over the ids.

class Tile
{
  public:
    virtual ~Tile();
};

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};

class TESObjectBOOK : public TESBoundObject
{
};

int FUN_00720df0();

struct Mgr20
{
    void* FUN_00720aa0(int menuClass);
};

// @fnv 0x00720aa0
void* Mgr20::FUN_00720aa0(int menuClass)
{
    Tile* pMenu = ((::Tile *)(::FUN_00a09030(menuClass)));
    bool bFlag = ((bool)(::IsStartMenuFlag1Set()));
    if (pMenu)
    {
        delete pMenu;
    }
    pMenu = 0;

    if (FUN_00720df0() == menuClass)
    {
        pMenu = ((::Tile *)(::fnv_00704140::FUN_00704140()));
        ::fnv_007164c0::FUN_007164c0((int)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x40b)
    {
        pMenu = ((::Tile *)(::fnv_00704490::FUN_00704490()));
        ::fnv_007164c0::FUN_007164c0((int)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x425)
    {
        pMenu = ((::Tile *)(::fnv_007046c0::FUN_007046c0()));
        ::fnv_007164c0::FUN_007164c0((int)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x3ea)
    {
        pMenu = ::fnv_007048c0::CreateInventoryMenuIfModifierKey();
        ::fnv_007164c0::FUN_007164c0((int)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x3eb)
    {
        pMenu = ((::Tile *)(::fnv_00704be0::FUN_00704be0()));
        ::fnv_007164c0::FUN_007164c0((int)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x3ec)
    {
        pMenu = FUN_0076bfe0();
    }
    else if (FUN_0070ede0() == menuClass && ::InitStartMenu(bFlag, false))
    {
        pMenu = ((::Tile *)(::FUN_00a09030(menuClass)));
    }
    else if (menuClass == 0x3ef)
    {
        pMenu = ::CreateLoadingMenuTile((::TESForm *)(void *)(0), true, false);
    }
    else if (menuClass == 0x403)
    {
        pMenu = ((::Tile *)(::fnv_00784c80::FUN_00784c80()));
    }
    else if (menuClass == 0x3f0)
    {
        ContainerMenu* pContainer = dynamic_cast<ContainerMenu*>(((::Tile *)(::FUN_00a09030(0x3f0))));
        if (pContainer)
        {
            pMenu = ((::Tile *)(::FUN_0075b310((::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_004fd3a0_shell *>((((Tile*)pContainer)))->FUN_004fd3a0()))), 1)));
        }
    }
    else if (menuClass == 0x402)
    {
        BookMenu* pBookMenu = dynamic_cast<BookMenu*>(((::Tile *)(::FUN_00a09030(0x3f0))));
        if (pBookMenu)
        {
            char* data = reinterpret_cast<::Script *>((((Tile*)pBookMenu)))->GetData();
            TESObjectBOOK* pBookForm = dynamic_cast<TESObjectBOOK*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESBoundObject*)data)))->FUN_007af430())));
            delete (Tile*)pBookMenu;
            pMenu = ::FUN_0073ad50((::TESObjectBOOK *)(pBookForm), (::TESObjectREFR *)(data));
        }
    }

    return pMenu;
}
