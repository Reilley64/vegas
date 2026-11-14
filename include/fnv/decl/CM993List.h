#pragma once

struct CM993DstArray;
struct CM993SrcArray;

struct CM993List {
public:
    // 0x00993db0
    ::CM993List *InitFromSources(int, int, ::CM993DstArray *, ::CM993SrcArray *, int);
};
