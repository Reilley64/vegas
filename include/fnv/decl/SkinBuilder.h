#pragma once

struct SkinGeom;
struct SkinItems;

struct SkinBuilder {
public:
    // 0x00a84310
    bool BuildTriangleSetMapping(::SkinGeom *, void *, unsigned int, void *, ::SkinItems *, int **, int *);
};
