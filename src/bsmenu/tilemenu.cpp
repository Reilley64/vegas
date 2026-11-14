// bsmenu/tilemenu.cpp: TileMenu, TileRect, TileMenuStub (6 functions)

#include "fnv/decl/A0B020Tile.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_009ff600_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a074d0_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/TileX.h"
#include "fnv/decl/fnv_009ff690__ReleaseTile.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00a1d000.h"
#include "fnv/symbols_011f3000.h"
#include "tilemenu_decls.h"
#include "tilemenu_private.h"

// @fnv 0x00709a40
int TileMenu::GetType()
{
    return 0x389;
}

// @fnv 0x00a1ef30
void TileMenu::Init(Tile* parent, const char* name, Tile* replacedChild)
{
    reinterpret_cast<::FUN_009ff600_shell *>(this)->InitTile(parent, (char *)(name), replacedChild);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xFA1, 0.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xFA2, 0.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xFA8, 1.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xFC1, 0.25f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xFF4, 1.0f, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xFA3, 0.0f, true);
    reinterpret_cast<::FUN_00a074d0_shell *>(this)->FUN_00a074d0(3);
    pMenu = 0;
}

// @fnv 0x00a1f140
NiNode* TileMenu::CalculateNode()
{
    NiNode* node = reinterpret_cast<::TileX *>(this)->FUN_00a1f3b0();
    return node;
}

__forceinline TileRect::~TileRect()
{
    if (!IsSpecial())
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>(this)->FUN_009ff690();
}
// @fnv 0x00a1eff0
TileMenu::~TileMenu()
{
    if (pMenu)
    {
        Menu::SetVisible(pMenu->GetID(), false);
        Menu::SetMenuRootTile(pMenu->GetID(), 0);
        reinterpret_cast<::FUN_00a1dc70_shell *>((pMenu))->FUN_00a1dc70(0, false);
        delete pMenu;
    }
    if (!IsSpecial())
        reinterpret_cast<::fnv_009ff690::ReleaseTile *>(this)->FUN_009ff690();
}

// @fnv 0x00a1f160
Tile* TileMenu::SetTraitValue(int valueID, float floatValue, const char* strValue)
{
    if (valueID == 0xFA4)
    {
        if (!pMenu)
        {
            Menu* menu = Interface::GetMenuById((int)floatValue);
            pMenu = menu;
        }
        if (!pMenu)
        {
            ::FUN_00703c00("ERROR: Cant find menu class!", {});
        }
        else
        {
            reinterpret_cast<::FUN_00a1dc70_shell *>((pMenu))->FUN_00a1dc70(this, false);
            pMenu->m_iMenuId = pMenu->GetID();
            if (GetTraitFloat(0xFA7) == 102.0 || GetTraitFloat(0xFA7) == 103.0)
            {
                pMenu->SetModal(pMenu->GetID());
                reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xFAD, ::FUN_00a1dfb0(), true);
            }
            Menu::SetMenuRootTile((int)floatValue, this);
            return this;
        }
    }
    else if (pMenu && valueID >= 10000)
    {
        pMenu->OnUpdateUserTrait(valueID);
    }
    if (pMenu && valueID == 0xFA3)
    {
        Menu::SetVisible(pMenu->GetID(), floatValue != 0.0);
    }
    return 0;
}

class TileMenuStub : public TileMenu
{
  public:
    void FUN_00a1f310();
};

// Returns early if pMenu's ID is 0x3ec or 0x3ef, otherwise calls FUN_00a0b020.
// @fnv 0x00a1f310
void TileMenuStub::FUN_00a1f310()
{
    if (pMenu && (pMenu->GetID() == 0x3ec || pMenu->GetID() == 0x3ef))
        return;
    else
        reinterpret_cast<::A0B020Tile *>(this)->FUN_00a0b020();
}

#include "generated/data/bsmenu/tilemenu.inc"
