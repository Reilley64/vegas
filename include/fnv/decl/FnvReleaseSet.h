#pragma once

struct FnvReleaseCounts;

struct FnvReleaseSet {
public:
    // 0x00d044f0
    void ReleasePendingCounts(::FnvReleaseCounts *);
};
