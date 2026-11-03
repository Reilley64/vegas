#pragma once

struct ItemListEntry;

class ItemListOwner {
public:
    // 0x007e0ce0
    ::ItemListEntry *FindEntryByFormID(int);
};
