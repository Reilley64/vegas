#pragma once

struct BAA720_List;
struct BAA720_Matrix;

struct BAA720_Effect {
public:
    // 0x00baa720
    void ApplyLightToEffect(::BAA720_List *, const ::BAA720_Matrix *, float, unsigned int);
};
