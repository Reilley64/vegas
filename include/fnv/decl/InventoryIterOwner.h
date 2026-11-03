#pragma once

struct IterState;

struct InventoryIterOwner {
public:
    // 0x004d4830
    bool AdvanceInventoryIterator(::IterState *, void **, int);
};
