#pragma once

struct ActorC;
struct DestinationC;
struct OptionsC;
struct PointC;
struct SegmentC;

struct SearchC {
public:
    // 0x0099c230
    bool FindPathCandidate(::SegmentC *, ::DestinationC *, ::OptionsC *, ::PointC *, void *, void *, int, ::ActorC *, ::ActorC *, float, float, int *, float *, bool);
};
