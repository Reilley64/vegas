#pragma once

struct xOutHit;
struct xP3;
struct xRef;

struct xCaster {
public:
    // 0x00620bc0
    bool FUN_00620bc0(const ::xP3 &, ::xP3 &, ::xOutHit *);
    // 0x006214d0
    bool FUN_006214d0(::xRef *, const ::xP3 &, float, float);
};
