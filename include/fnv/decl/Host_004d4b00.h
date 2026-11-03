#pragma once
#include <cstdint>

struct Entry_004d4b00;
struct Iterator_004d4b00;
struct Output_004d4b00;

struct Host_004d4b00 {
public:
    // 0x004ca330
    ::Entry_004d4b00 *GetNextInventoryEntry(::Iterator_004d4b00 *);
    // 0x004d4b00
    void FindEntriesByType(intptr_t, ::Output_004d4b00 *);
};
