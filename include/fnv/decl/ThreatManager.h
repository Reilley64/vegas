#pragma once

struct ThreatActor;
struct ThreatPosition;

struct ThreatManager {
public:
    // 0x00992720
    bool IsThreatWithinLimits(::ThreatActor *, ::ThreatActor *, const ::ThreatPosition &, float);
};
