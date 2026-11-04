
#include "fnv/decl/fnv_00a07c60__FUN_00a07c60_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "statsmenu_decls.h"

// @fnv 0x0071f660
int StatsMenu::GetClass()
{
    return 1003;
}

// @fnv 0x0071fa50
void StatsMenu::AssignTileByID(int id, Tile* tile)
{
    if (id >= 0 && id < 60)
        m_pTiles[id] = tile;
}

// @fnv 0x007dc040
bool StatsMenu::SetTileFlashing(Tile* tile, unsigned int flashing)
{
    if (flashing)
        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((tile))->StartFade(4009, 255.0f, 0.0f, 1.0f, (*(int *)&(const ::Tile::TILE_FADE_CONTROL_TYPE &)(Tile::FADE)));
    else
    {
        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((tile))->RemoveFadeItemsForTile(4009);
        tile->Set(4009, 255);
    }
    return true;
}

// @fnv 0x007db2c0
StatsMenu::BodyPartDisplay::BodyPartDisplay()
{
    m_iBodyPartCount = 0;
    memset(m_auiBodyPartValues, -1, sizeof(m_auiBodyPartValues));
}
