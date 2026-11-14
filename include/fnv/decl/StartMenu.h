#pragma once

class TileMenu;

class StartMenu {
public:
    // 0x00403df0
    ::TileMenu *GetMenuTitle();
    // 0x007ce8f0
    bool IsStartMenuActive();
};
