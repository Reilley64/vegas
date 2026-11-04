#pragma once

struct Bounds;
struct IndexList;
struct PartitionBounds;
struct PartitionIndices;
struct PartitionQuantizedBounds;

// 0x00d9a520
extern "C" void FUN_00d9a520(const ::Bounds *, const ::Bounds *, ::IndexList *, int, int, ::Bounds *, ::Bounds *, int *, int *);
// 0x00d9a850
extern "C" void FUN_00d9a850(const ::PartitionBounds &, const ::PartitionQuantizedBounds *, ::PartitionIndices &, unsigned short, int, ::PartitionBounds &, ::PartitionBounds &, int &, int &);
