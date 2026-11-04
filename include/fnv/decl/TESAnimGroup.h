#pragma once

enum ANIM_GROUP_ENUM;
enum ANIM_GROUP_MOVE_ENUM;
enum ANIM_GROUP_WEAPON_ENUM;

class TESAnimGroup {
public:
    // 0x005f2370
    static unsigned short AnimGroup(::ANIM_GROUP_MOVE_ENUM, ::ANIM_GROUP_WEAPON_ENUM, ::ANIM_GROUP_ENUM, bool);
    // 0x005f23c0
    static ::ANIM_GROUP_MOVE_ENUM GetMoveType(unsigned short);
    // 0x005f2420
    ::ANIM_GROUP_ENUM GetType() const;
    // 0x005f2440
    static ::ANIM_GROUP_ENUM GetType(unsigned short);
    // 0x005f2540
    static bool IsActionTypeValid(unsigned short);
    // 0x005f2630
    static bool IsAimAnimation(unsigned short);
    // 0x005f2670
    static bool IsValidAnimationGroup(unsigned short);
    // 0x005f4c70
    float GetAnimationSpeed() const;
    // 0x005f4d60
    bool IsJumpAnimation() const;
};
