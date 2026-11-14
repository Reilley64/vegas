#pragma once

struct Body;
struct CollisionInput;
struct CollisionOutput;
struct Pair;

struct SimulationContext {
public:
    // 0x00cf9480
    void FUN_00cf9480(::Body **, int, ::CollisionInput *, void (*)(void *, Pair *, CollisionInput *, CollisionOutput *), int);
};
