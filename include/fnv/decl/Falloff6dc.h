#pragma once

struct Pt6dc;

struct Falloff6dc {
public:
    // 0x006dc780
    float EvaluateFalloff(const ::Pt6dc &);
};
