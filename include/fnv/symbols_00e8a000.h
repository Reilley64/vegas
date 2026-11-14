#pragma once

struct DeviceResource;
struct ResourceConfig;
struct ShaderChoices093;
struct ShaderRequest093;
struct ShaderTraits093;
struct TextureInput;

// 0x00e8a240
unsigned int FUN_00e8a240(char *, int);
// 0x00e8a300
void *FUN_00e8a300(::ShaderRequest093 *, ::ShaderTraits093 *, ::ShaderChoices093 *);
// 0x00e8a9b0
void ReleaseShaderNodes();
// 0x00e8abf0
::DeviceResource *FUN_00e8abf0(::TextureInput *, ::ResourceConfig *);
