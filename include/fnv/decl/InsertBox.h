#pragma once
#include <cstdint>

class Tile;
struct LBItem;

struct InsertBox {
public:
    // 0x007a3820
    ::Tile *FUN_007a3820(intptr_t, const char *, int (*)(LBItem *, LBItem *), const char *);
};
