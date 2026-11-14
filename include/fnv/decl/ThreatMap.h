#pragma once

struct Pt3;
struct Stamp;

struct ThreatMap {
public:
    // 0x009a5670
    float EvaluateThreats(::Pt3, int, float, float, struct ::Stamp, float);
};
