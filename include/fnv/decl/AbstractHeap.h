#pragma once

class HeapFreeBlock;
class HeapFreeList;
struct MemoryBlockHeader;

struct AbstractHeap {
public:
    // 0x00683610
    void AppendBlock(::MemoryBlockHeader *);
    // 0x00aa9e50
    void FUN_00aa9e50(::HeapFreeList *, ::HeapFreeBlock *);
};
