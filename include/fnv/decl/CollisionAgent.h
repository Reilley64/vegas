#pragma once

struct BodyRecord;
struct Collector;
struct CollisionInput;

struct CollisionAgent {
public:
    // 0x00d39ef0
    void FUN_00d39ef0(const ::BodyRecord &, const ::BodyRecord &, const ::CollisionInput &, ::Collector *);
};
