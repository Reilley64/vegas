#pragma once

struct CollisionInput;
struct VirtObj;
class hkpCdBody;

struct CapsuleTriangleAgent {
public:
    // 0x00d3a620
    void FUN_00d3a620(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionInput *, ::VirtObj *);
};
