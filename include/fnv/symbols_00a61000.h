#pragma once

class A61750Texture;
class A61E60Obj;
class NiTexture;
namespace fnv_00a61040 { struct SpawnedObject; }
struct A616E0Iter;
struct CubeRenderer;
struct NiCubeMap;
struct NiRenderer;
struct TextureFormatPreferences;

// 0x00a61040
namespace fnv_00a61040 { ::fnv_00a61040::SpawnedObject *FUN_00a61040(char **, int, ::NiRenderer *, int *); }
// 0x00a61120
::NiCubeMap *CreateCubeMap(void *, void *, void *, void *, void *, void *, ::CubeRenderer *, int, const ::TextureFormatPreferences *);
// 0x00a614d0
bool FUN_00a614d0(const char *, const char *);
// 0x00a61530
unsigned int FUN_00a61530(const char *);
// 0x00a616e0
bool FUN_00a616e0(::A616E0Iter *);
// 0x00a61750
unsigned int GetTextureSizeLevel(::A61750Texture *);
// 0x00a61ad0
namespace fnv_00a61ad0 { void FUN_00a61ad0(); }
// 0x00a61b90
bool FindTextureByPath(const char *, ::NiTexture **);
// 0x00a61cd0
void FUN_00a61cd0();
// 0x00a61e60
void *FindNodeByObject(::A61E60Obj *);
// 0x00a61f30
bool FUN_00a61f30(const void *);
// 0x00a61fb0
bool FUN_00a61fb0(const char *);
