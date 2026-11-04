#pragma once

struct WalkTemp;

struct WalkInventory {
public:
    // 0x004d4530
    int ForEachInventoryItem(bool (*)(WalkTemp *, void *), void *, int);
};
