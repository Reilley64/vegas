#pragma once

struct AvoidActor;
class PathingAvoidNodeArray;

struct AvoidWork {
public:
    // 0x009895a0
    ::PathingAvoidNodeArray *BuildAvoidNodes(::AvoidActor *, ::PathingAvoidNodeArray *);
};
