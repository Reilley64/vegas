#pragma once
#include <cstdint>

class NiD3DShaderProgramCreator;
struct Program;
struct ShaderArg;

// 0x00e930a0
bool FindShaderProgramFile(const char *, char *, unsigned int);
// 0x00e93260
void FUN_00e93260(::NiD3DShaderProgramCreator *);
// 0x00e932f0
namespace fnv_00e932f0 { void *FUN_00e932f0(const char *); }
// 0x00e937c0
void RemoveProgramFromMap(::Program *);
// 0x00e93850
namespace fnv_00e93850 { ::ShaderArg *FUN_00e93850(const char *, const char *, const char *, const char *, uintptr_t, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); }
// 0x00e938e0
void *FUN_00e938e0(void *, void *, const char *, const char *, void *, void *, void *);
// 0x00e93d80
void CreateCreatorMap();
// 0x00e93df0
void FUN_00e93df0();
// 0x00e93f50
void FUN_00e93f50(void *);
