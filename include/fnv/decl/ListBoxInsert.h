#pragma once

struct ListItemData;
struct ListItemTile;

struct ListBoxInsert {
public:
    // 0x007f6fe0
    ::ListItemTile *AddItemTile(void *, const char *, int (*)(ListItemData *, ListItemData *), const char *);
};
