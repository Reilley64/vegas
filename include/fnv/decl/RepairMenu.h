#pragma once

class Tile;

class RepairMenu {
public:
    // 0x0077f700
    void UpdateRepairList();
    // 0x007b5520
    static ::Tile *Create();
    // 0x007b8b30
    void RefreshRepairMenu();
};
