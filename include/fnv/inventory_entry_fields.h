#pragma once

// The fields of an inventory entry (ExtraContainerChanges::EntryData: extra data lists, count change, object), for
// units whose entry stand-ins declare no fields. The 4-byte getters folded into 0x00726070 and 0x0044ddc0 read
// `iCountDelta` and `pObject` when called on an entry.
struct InventoryEntryFields
{
    void* pExtraLists;
    int iCountDelta;
    void* pObject;
};
