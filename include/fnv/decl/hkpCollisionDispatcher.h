#pragma once

struct CollisionAgentEntry;

struct hkpCollisionDispatcher {
public:
    // 0x00cfb2a0
    void RegisterAgentType(signed char (*)[32], signed char, int, int, signed char, signed char, CollisionAgentEntry (*)[32], int);
};
