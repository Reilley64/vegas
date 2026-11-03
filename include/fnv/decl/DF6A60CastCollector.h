#pragma once

struct DF6A60Collidable;

struct DF6A60CastCollector {
public:
    // 0x00df6a60
    float LinearCastAgainst(const ::DF6A60Collidable *);
};
