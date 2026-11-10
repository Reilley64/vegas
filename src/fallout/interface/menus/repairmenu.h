
#include "repairmenu_decls.h"

// @fnv 0x007b54c0
void RepairMenu::AssignTileByID(int tileID, Tile* tile)
{
    if (tileID >= 0 && tileID < 13)
        m_pTiles[tileID] = tile;
}
