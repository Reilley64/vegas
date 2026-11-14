#pragma once
#include <cstdint>

struct FleePath;
struct FleeRequest;
struct FleeStartNode;

struct FleeSearch {
public:
    // 0x006a92e0
    bool StartFleeSearch(::FleeRequest *, const ::FleeStartNode *, ::FleePath *, std::uintptr_t);
};
