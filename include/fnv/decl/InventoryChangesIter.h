#pragma once

class InventoryStackRecord;

struct InventoryChangesIter {
public:
    // 0x004bf4b0
    ::InventoryStackRecord *FindEntryWithExtraListType(int);
};
