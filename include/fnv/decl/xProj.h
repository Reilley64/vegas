#pragma once

struct xActorV;
struct xOwner;
struct xP3;

struct xProj {
public:
    // 0x00811980
    xProj(::xActorV *, int, int, int, ::xP3, ::xP3);
    // 0x00819360
    xProj(int, int, int, int, ::xP3, ::xP3, void *, ::xOwner *);
};
