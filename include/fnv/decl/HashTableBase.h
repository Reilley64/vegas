#pragma once
#include <cstdint>

struct DataBufferInfo;
struct TableValue;

struct HashTableBase {
public:
    // 0x004b9bf0
    void GetNextEntry(::DataBufferInfo **, int *, ::TableValue *);
    // 0x00aa0250
    bool FUN_00aa0250(const unsigned int *);
    // 0x00b57ea0
    void InsertOrUpdate(uintptr_t, uintptr_t);
    // 0x00dbe920
    void ClearEntries();
};
