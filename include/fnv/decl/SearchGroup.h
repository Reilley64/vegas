#pragma once

struct InputActor;
struct OutputActor;

struct SearchGroup {
public:
    // 0x0098cd50
    ::OutputActor *FindNearestActor(::InputActor *, ::OutputActor *, float);
};
