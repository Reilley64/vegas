#pragma once

class FORenderedMenu;
class Tile;

class InterfaceManager {
public:
    // 0x00500a20
    void FUN_00500a20(::Tile *);
    // 0x00586150
    ::Tile *FUN_00586150();
    // 0x00707af0
    ::FORenderedMenu *GetActiveRenderedMenu();
    // 0x00713da0
    void AddTileIfAbsent(::Tile *);
    // 0x00714f00
    int GetTopEnterStackEntry();
    // 0x00714f70
    int GetMenuStackEntry(int);
    // 0x00715d40
    static float UpdateInterfaceState();
    // 0x00717920
    static bool IsInterfaceMenuActive();
    // 0x00747d00
    int FUN_00747d00();
};
