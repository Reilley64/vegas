#pragma once
#include <cstdint>

#include <cstdint>

struct SearchDestination;
struct SearchPath;

struct SearchOwner {
public:
    // 0x00995dd0
    void FindAndDispatchById(std::intptr_t, ::SearchDestination *);
    // 0x009b1720
    int *FindEntryResultByCategory(intptr_t);
    // 0x00e23900
    int LookupPairResult(::SearchPath *);
};
