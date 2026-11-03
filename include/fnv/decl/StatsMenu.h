#pragma once

class Tile;
enum MiscStatManager__MiscStatID;

struct StatsMenu {
public:
    // 0x0070b7f0
    void SetCurrentPageFromChar(char);
    // 0x007af6b0
    void UpdateMinusPlusTiles();
    // 0x007dc040
    static bool SetTileFlashing(::Tile *, unsigned int);
    // 0x007dcfc0
    void UpdateActorValueTiles();
    // 0x007dda60
    static void ClearPerks();
    // 0x007ddad0
    void RefreshMiscStat(::MiscStatManager__MiscStatID);
    // 0x007df5d0
    static void UpdateStatusEffects();
    // 0x007dfd00
    static void SetStatsPage(unsigned char);
    // 0x011dace0
    static ::StatsMenu *ms_pInventoryMenu;
};
