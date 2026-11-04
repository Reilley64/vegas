#pragma once

struct LightOwner;
struct Matrix44;

// 0x00bb1960
void UpdateLightDirection(::LightOwner *, const ::Matrix44 *, float);
