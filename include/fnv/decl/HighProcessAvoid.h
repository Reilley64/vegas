#pragma once

class NiPoint3;
struct AvoidActorStub;
struct AvoidRefStub;

struct HighProcessAvoid {
public:
    // 0x009042a0
    void AddAvoidArea(::AvoidActorStub *, ::NiPoint3, float, float, float, ::AvoidRefStub *, int);
};
