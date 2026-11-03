#pragma once

class Tile;
struct LBItem;

struct InsertBox {
public:
    // 0x007a3820
    ::Tile *FUN_007a3820(int, const char *, int (*)(LBItem *, LBItem *), const char *);
};
