#pragma once

class PathingAvoidNodeArray;
struct AvoidanceContext;

struct AvoidanceMap {
public:
    // 0x009a57a0
    ::PathingAvoidNodeArray *BuildAvoidanceNodes(void *, ::AvoidanceContext *, float);
};
