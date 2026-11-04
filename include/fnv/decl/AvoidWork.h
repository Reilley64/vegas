#pragma once

struct AvoidActor;
struct PathingAvoidNodeArray;

struct AvoidWork {
public:
    // 0x009895a0
    ::PathingAvoidNodeArray *BuildAvoidNodes(::AvoidActor *, ::PathingAvoidNodeArray *);
};
