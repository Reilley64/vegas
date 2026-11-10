#pragma once

class ActiveEffect;
class Actor;
namespace ActorValue { enum Index; }
class Actor;

class ValueModifierEffect {
public:
    // 0x006733e0
    ::ActorValue::Index GetActorValue();
    // 0x00673400
    void SetActorValue(::ActorValue::Index);
    // 0x00802db0
    void FUN_00802db0(::Actor *);
    // 0x0082bbe0
    void CopyData(::ActiveEffect *);
    // 0x0082be10
    void RefreshPlayerActorValue();
    // 0x0082c660
    void Update(float);
    // 0x0082ca50
    void ApplyActorValueModifier(::Actor *, float, ::ActorValue::Index);
    // 0x0082ce70
    float GetModifiedMagnitude(float);
};
