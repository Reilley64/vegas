#pragma once

struct BoxItem;
struct ItemTile;

struct IntListBox {
public:
    // 0x00764430
    ::ItemTile *FUN_00764430(int, const char *, int (*)(BoxItem *, BoxItem *), const char *);
};
