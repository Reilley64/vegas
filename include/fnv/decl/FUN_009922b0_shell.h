#pragma once

class Actor;
class ActorCombatGroup;
class CombatController;

struct FUN_009922b0_shell {
public:
    // 0x009922b0
    ::CombatController *GetOrCreateCombatController(::Actor *, ::ActorCombatGroup *);
};
