#pragma once

struct hkFreeListNode;

struct hkFreeListStandin {
public:
    // 0x00dd71c0
    int FreeBlocks(::hkFreeListNode *);
};
