#pragma once

struct AE8470Item;

struct AE8470List {
public:
    // 0x00ae8470
    void SortList(int (*)(AE8470Item *, AE8470Item *));
};
