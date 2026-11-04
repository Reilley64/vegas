#pragma once
#include <cstdint>

struct LBItem;
struct LBTile;

struct LBItemListBox {
public:
    // 0x00786cf0
    ::LBTile *AddItemTile(intptr_t, const char *, int (*)(LBItem *, LBItem *), const char *);
};
