#pragma once
#include <cstdint>

class InventoryStackRecord;

struct ItemChangeList {
public:
    // 0x004d4480
    intptr_t GetExtraValueAtPosition(intptr_t, int);
    // 0x0083fd60
    void SortItems(int (*)(InventoryStackRecord *, InventoryStackRecord *));
};
