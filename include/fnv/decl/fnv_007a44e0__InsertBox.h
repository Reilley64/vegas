#pragma once
#include <cstdint>

class Tile;
struct LBItem;

namespace fnv_007a44e0 {
struct InsertBox {
public:
    // 0x007a44e0
    ::Tile *FUN_007a44e0(intptr_t, const char *, int (*)(LBItem *, LBItem *), const char *);
};
}
