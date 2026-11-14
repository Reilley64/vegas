#pragma once

struct AnimationOutput;

struct MovementController {
public:
    // 0x008cd780
    bool UpdateAnimation(::AnimationOutput *);
};
