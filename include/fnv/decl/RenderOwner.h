#pragma once

struct BoundOut;

struct RenderOwner {
public:
    // 0x00a675b0
    void GetBounds(::BoundOut *);
    // 0x00bd1cf0
    void DrawSlots(void *);
};
