#pragma once

class hkMemoryAllocatorDBE8;
struct hkPairKeyDBE8;

class hkPairMapDBE8 {
public:
    // 0x00dbe810
    int InsertOrUpdate(::hkMemoryAllocatorDBE8 &, ::hkPairKeyDBE8, unsigned int);
};
