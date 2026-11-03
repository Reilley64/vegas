#pragma once

struct Options;

struct MenuWork {
public:
    // 0x0078bf80
    void UpdateMenuTiles(::Options *);
    // 0x007d01b0
    void BuildMenuList();
};
