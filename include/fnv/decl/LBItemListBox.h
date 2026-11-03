#pragma once

struct LBItem;
struct LBTile;

struct LBItemListBox {
public:
    // 0x00786cf0
    ::LBTile *AddItemTile(int, const char *, int (*)(LBItem *, LBItem *), const char *);
};
