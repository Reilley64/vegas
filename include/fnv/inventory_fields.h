#pragma once

class TESBoundObject;

// The fields of an inventory change entry (InventoryStackRecord in include/InventoryStackRecord.h),
// for interface code that reaches entries through stand-in types.
struct InventoryEntryFields
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
};

// The data handler's list of inventory entries that UpdateInventoryForReference fills.
struct DataHandlerInventoryFields
{
    char pad[0x628];
    void* pInventoryList;
};
