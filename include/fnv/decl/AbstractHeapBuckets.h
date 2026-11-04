#pragma once

struct HeapDumpFile;

struct AbstractHeapBuckets {
public:
    // 0x00aaa310
    int WriteBucketInfo(::HeapDumpFile *);
};
