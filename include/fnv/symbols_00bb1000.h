#pragma once

struct LightOwner;
struct D3DXMATRIXBB2;

// 0x00bb1960
void UpdateLightDirection(::LightOwner *, const ::D3DXMATRIXBB2 *, float);
