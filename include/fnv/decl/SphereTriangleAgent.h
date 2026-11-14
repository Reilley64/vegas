#pragma once

struct CollisionBody;
struct CollisionInput;
struct ContactCollector;

struct SphereTriangleAgent {
public:
    // 0x00d38390
    void FUN_00d38390(const ::CollisionBody *, const ::CollisionBody *, const ::CollisionInput *, ::ContactCollector *);
};
