#pragma once

class IMemoryManagerFile;

struct AbstractHeapBlockInfo {
public:
    // 0x00aaa430
    int WriteHeapBlockInfo(::IMemoryManagerFile *, bool);
};
