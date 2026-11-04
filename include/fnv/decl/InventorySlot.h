#pragma once

class ExtraDataList;
struct RefSlot;

struct InventorySlot {
public:
    // 0x004bf800
    void SetInventorySlotExtraData(::RefSlot *, ::ExtraDataList *, int);
};
