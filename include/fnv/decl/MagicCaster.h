#pragma once
#include <cstdint>

class ActiveEffect;
class Actor;
class MagicItem;
class MagicTarget;
struct NiPoint3;
enum MagicCaster__State;

class MagicCaster {
public:
    // 0x00815300
    MagicCaster();
    // 0x00815410
    ::Actor *GetCasterActor();
    // 0x00815b00
    void RemoveCastingArt();
    // 0x00817940
    bool AddEffectToTarget(::MagicTarget *, ::NiPoint3, ::MagicItem *, ::ActiveEffect *, bool);
    // 0x00818af0
    void SetState(::MagicCaster__State, char *);
    // 0x00818c60
    static ::MagicCaster *GetCasterByHandle(uintptr_t);
};
