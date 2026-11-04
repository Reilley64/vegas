#pragma once

struct MoveFilter;
struct MoveOwner;

struct InventoryMove {
public:
    // 0x004ce380
    float FUN_004ce380(::MoveOwner *, ::MoveOwner *, bool, bool, bool, bool, int, ::MoveFilter *);
};
