#pragma once

class InventoryStackRecord;

struct ItemChangeList {
public:
    // 0x004d4480
    int GetExtraValueAtPosition(int, int);
    // 0x0083fd60
    void SortItems(int (*)(InventoryStackRecord *, InventoryStackRecord *));
};
