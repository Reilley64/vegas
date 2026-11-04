#pragma once

struct MyItem;
struct MyTile;

struct MyBox {
public:
    // 0x007a2930
    ::MyTile *CreateListItem(int, const char *, int (*)(MyItem *, MyItem *), const char *);
};
