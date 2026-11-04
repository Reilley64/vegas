#pragma once

class ScrapHeapBuffer;

struct MemoryManager {
public:
    // 0x00866770
    void FUN_00866770();
    // 0x00866e00
    void InitializeHeaps();
    // 0x00aa4030
    void *Allocate(unsigned int, const char *, const int, const char *);
    // 0x00aa4150
    void *Reallocate(void *, unsigned int);
    // 0x00aa42e0
    ::ScrapHeapBuffer *GetGeneralAllocator();
    unsigned int Size(const void *);
};
