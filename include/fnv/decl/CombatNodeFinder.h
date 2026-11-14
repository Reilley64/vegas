#pragma once

struct ActorS;
struct RefS;

struct CombatNodeFinder {
public:
    // 0x0098c3d0
    ::RefS *FindNearestCombatNode(::ActorS *, float, bool);
};
