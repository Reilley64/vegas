#pragma once

struct Vec;

// 0x00eb7440
int IntersectPlane(float, const ::Vec &, float, const ::Vec &, const ::Vec &, const ::Vec &, float &, ::Vec &, float &, ::Vec &);
