#pragma once

class Actor;
class MobileObject;

class SandBoxActorPackageData {
public:
    // 0x009f3c10
    bool IsLocationCheckDue();
    // 0x009f4300
    bool IsActorWithinLocationRadius(::Actor *, bool);
    // 0x009f43c0
    bool HasProcessTarget(::Actor *);
    // 0x009f56b0
    bool IsObjectWithinLocationRadius(::MobileObject *, float);
};
