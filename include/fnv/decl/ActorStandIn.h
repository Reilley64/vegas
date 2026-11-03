#pragma once

class NiPoint3;
class TESObjectREFR;
struct PathingAvoidNodeArray;
struct PathingRequest;

struct ActorStandIn {
public:
    // 0x008b38d0
    void BuildPathingRequest(::PathingRequest *, const ::NiPoint3 &, ::TESObjectREFR *, float, ::PathingAvoidNodeArray *);
};
