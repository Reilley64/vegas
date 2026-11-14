#pragma once
#include <cstdint>

struct L08;
class NiTexture;
struct Source374;

// 0x00c03010
void AccumulateLightColor(::L08 *);
// 0x00c03180
void ApplySourceColor(::Source374 *);
// 0x00c03230
::NiTexture *GetTextureByIndex(char *, intptr_t);
