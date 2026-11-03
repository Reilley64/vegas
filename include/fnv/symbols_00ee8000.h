#pragma once

class RendererEE8;
class ShaderLevelEE8;
struct ProgramCacheDirectoryState;
struct SourceObject;
struct SpawnedObject;

// 0x00ee81e0
long FUN_00ee81e0(const void *, void **, void *);
// 0x00ee81e6
int FUN_00ee81e6(void *);
// 0x00ee81ec
long long FUN_00ee81ec(void *, int);
// 0x00ee81f2
int FUN_00ee81f2(void *);
// 0x00ee81f8
void *FUN_00ee81f8(void *, int);
// 0x00ee81fe
void FUN_00ee81fe();
// 0x00ee8204
int FUN_00ee8204(void *, char *, int, int, int, int, int *);
// 0x00ee820a
void FUN_00ee820a();
// 0x00ee8710
::ShaderLevelEE8 *CreateShaderLevel(unsigned int, ::RendererEE8 *);
// 0x00ee8760
::SpawnedObject *FUN_00ee8760(void *, ::SourceObject *, void *);
// 0x00ee8990
bool FUN_00ee8990();
// 0x00ee8d20
extern "C" bool FUN_00ee8d20(::ProgramCacheDirectoryState *, int);
