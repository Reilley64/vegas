#pragma once

struct GeomData;
struct TriIndexList;

struct PartitionEx {
public:
    // 0x00a822d0
    unsigned short *BuildVertexRemapTable(const ::TriIndexList &, const ::GeomData *);
};
