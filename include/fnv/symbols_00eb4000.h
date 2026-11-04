#pragma once

struct BoxVec3;
struct OrientedBox;

// 0x00eb42e0
float GetSqrDistanceToOrientedBox(const ::BoxVec3 *, const ::OrientedBox *, float *, float *, float *);
