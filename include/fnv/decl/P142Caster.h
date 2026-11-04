#pragma once
#include <cstdint>

class NiPoint3;
struct P142Ref;
struct P142Spell;

struct P142Caster {
public:
    // 0x00817160
    void ApplySpellEffects(::P142Spell *, intptr_t, ::NiPoint3, ::P142Ref *, ::P142Ref *, int, float, float);
};
