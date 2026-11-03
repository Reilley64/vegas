#pragma once

struct FleePath;
struct FleeRequest;
struct FleeStartNode;

struct FleeSearch {
public:
    // 0x006a92e0
    bool StartFleeSearch(::FleeRequest *, const ::FleeStartNode *, ::FleePath *, unsigned int);
};
