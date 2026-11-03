#pragma once

class NiDynamicEffect;
class NiFixedString;

// 0x00a69030
void DestroyDynamicEffect(::NiDynamicEffect *);
// 0x00a69690
void FUN_00a69690(float *);
// 0x00a69c50
char *BuildFilterModeString(const char *, unsigned int);
// 0x00a69d80
bool FindTextureMapIndexByName(::NiFixedString *, unsigned int *);
