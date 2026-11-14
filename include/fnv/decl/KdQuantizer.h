#pragma once

struct KdRegion;
struct QuantNode;

struct KdQuantizer {
public:
    // 0x00e07880
    void FUN_00e07880(const ::QuantNode *, const ::KdRegion *, int *, int *);
};
