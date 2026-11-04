#pragma once

struct DF7230Collidable;

struct DF7230CastCollector {
public:
    // 0x00df7230
    float CastAgainstCollidable(const ::DF7230Collidable *);
};
