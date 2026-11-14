#pragma once

class InventoryStackRecord;
class Tile;

class InventoryMenu {
public:
    // 0x0077fc10
    static ::Tile *Create();
    // 0x0077ff80
    static int FUN_0077ff80();
    // 0x011d9ea4
    static ::InventoryMenu *ms_pInventoryMenu;
    // 0x011d9ea8
    static ::InventoryStackRecord *ms_pActionPointSource;
    // 0x011d9eac
    static int ms_iCurrentTabTileID;
    // 0x011d9eb4
    static int ms_iValueTileID;
    // 0x011d9eb8
    static int ms_iKeyringOpenTileID;
};
