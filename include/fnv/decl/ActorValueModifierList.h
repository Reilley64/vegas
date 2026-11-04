#pragma once
#include <cstdint>

class Modifier;

class ActorValueModifierList {
public:
    // 0x009370b0
    void RemoveAllModifiers();
    // 0x00937160
    void CopyModifierListFrom(::ActorValueModifierList *);
    // 0x00937280
    void AddFastModifier(char, ::Modifier *);
    // 0x009376e0
    float GetActorValueModifierAmount(char, bool &);
    // 0x00937730
    float GetActorValueModifierAmount(char);
    // 0x00937d50
    void FUN_00937d50(intptr_t);
};
