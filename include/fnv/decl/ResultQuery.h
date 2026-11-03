#pragma once

struct ResultQuad;

struct ResultQuery {
public:
    // 0x00989140
    bool TryGetQuadForState(int, ::ResultQuad *, float);
};
