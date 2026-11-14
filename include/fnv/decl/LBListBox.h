#pragma once

struct LBItem;
struct LBTile;

struct LBListBox {
public:
    // 0x00722140
    void FUN_00722140();
    // 0x00729fe0
    void ApplyFilter(bool (*)(void *));
    // 0x0075a110
    ::LBTile *AddItem(int, const char *, int (*)(LBItem *, LBItem *), const char *);
};
