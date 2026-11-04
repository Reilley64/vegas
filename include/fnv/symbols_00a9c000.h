#pragma once

struct ShaderLight;
struct ShaderLights;

// 0x00a9c0e0
bool LookupShaderConstantMapping(const char *, unsigned int *);
// 0x00a9c130
::ShaderLight *GetLightByType(::ShaderLights *, unsigned int, unsigned int);
