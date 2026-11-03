#pragma once

struct Geometry;
struct P3;
struct Pick;

// 0x00e9a280
bool RaycastGeometry(const ::P3 *, const ::P3 *, ::Pick *, ::Geometry *);
