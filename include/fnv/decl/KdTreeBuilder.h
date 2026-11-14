#pragma once

class KdVector4Comparison;
struct KdProjectedEntry;
struct KdSplitResults;
struct KdWorkingSet;

struct KdTreeBuilder {
public:
    // 0x00df4ec0
    static int FUN_00df4ec0(const ::KdWorkingSet &, int, int, ::KdSplitResults &, int &, ::KdWorkingSet &, const ::KdProjectedEntry &, const ::KdVector4Comparison &);
};
