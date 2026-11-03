#pragma once

namespace fnv_00cb0df0 { struct GrowBuffer; }
struct S_00cb0da0;
struct SpawnedBuffer;

// 0x00cb0c00
void FUN_00cb0c00(int);
// 0x00cb0da0
void FUN_00cb0da0(::S_00cb0da0 *);
// 0x00cb0db0
namespace fnv_00cb0db0 { void FUN_00cb0db0(); }
// 0x00cb0df0
namespace fnv_00cb0df0 { void FUN_00cb0df0(::fnv_00cb0df0::GrowBuffer *); }
// 0x00cb0e50
void ResizeBuffer(::SpawnedBuffer *, int);
// 0x00cb0f10
char ToUpperAscii(char);
// 0x00cb0f30
char ToLowerAscii(char);
// 0x00cb0f50
void FUN_00cb0f50(int, int, int, int);
// 0x00cb0f60
int Vsnprintf(char *, int, const char *, ...);
// 0x00cb0f80
void FUN_00cb0f80(char *, const char *, char *);
// 0x00cb0fa0
namespace fnv_00cb0fa0 { int FUN_00cb0fa0(const char *, const char *); }
// 0x00cb0fd0
int FUN_00cb0fd0(const char *, const char *, unsigned int);
// 0x00cb0fe0
namespace fnv_00cb0fe0 { int CompareStringsCaseInsensitive(const char *, const char *); }
