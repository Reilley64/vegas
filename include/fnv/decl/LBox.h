#pragma once

class Tile;
struct LBItem;

struct LBox {
public:
    // 0x007a5230
    ::Tile *AddItem(int, const char *, int (*)(LBItem *, LBItem *), const char *);
};
