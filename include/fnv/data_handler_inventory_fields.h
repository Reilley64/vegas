#pragma once

// The data handler's list of inventory entries that UpdateInventoryForReference fills.
struct DataHandlerInventoryFields
{
    char pad[0x628];
    void* pInventoryList;
};
