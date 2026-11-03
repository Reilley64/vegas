#pragma once

struct Color;
struct Flags;
struct Geometry;
struct Shape;

struct StripTarget {
public:
    // 0x00e718a0
    void DrawStrip(::Geometry *, ::Flags *, ::Shape *, void *, ::Color *);
};
