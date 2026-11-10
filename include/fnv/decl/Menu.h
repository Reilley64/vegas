#pragma once

class Tile;

class Menu {
public:
    // 0x007c0000
    void UpdateClockText();
    // 0x00a1c4a0
    Menu();
    // 0x00a1dc20
    void SetMenuVisibility(bool);
    // 0x00a1e130
    static void SetMenuRootTile(int, ::Tile *);
};
