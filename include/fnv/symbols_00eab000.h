#pragma once

struct Sphere0;
struct V3;

// 0x00eabb20
bool IntersectSpheres(float, const ::Sphere0 &, const ::V3 &, const ::Sphere0 &, const ::V3 &, float &, ::V3 &, bool, ::V3 &, ::V3 &);
