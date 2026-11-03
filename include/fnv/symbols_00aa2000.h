#pragma once

namespace fnv_00aa2e60 { struct NiMemStream; }
struct NiMemStream;
struct S_00aa2dd0;

// 0x00aa2020
namespace fnv_00aa2020 { extern "C" void InitHolder(); }
// 0x00aa2060
extern "C" void FUN_00aa2060(int, int);
// 0x00aa2080
void FUN_00aa2080(void (*)(), int);
// 0x00aa20b0
void FUN_00aa20b0(void *);
// 0x00aa2170
namespace fnv_00aa2170 { void FUN_00aa2170(); }
// 0x00aa2740
void SetDebuggerThreadName(unsigned long, const char *);
// 0x00aa29d0
void FUN_00aa29d0();
// 0x00aa2a00
bool FUN_00aa2a00(char *);
// 0x00aa2a70
void RemoveDotSlash(char *);
// 0x00aa2ac0
namespace fnv_00aa2ac0 { void RemoveParentDirSegments(char *); }
// 0x00aa2ba0
unsigned int BuildAbsolutePath(char *, unsigned int, const char *, const char *);
// 0x00aa2c50
char *SkipPathPrefix(char *);
// 0x00aa2cc0
bool FUN_00aa2cc0(const char *);
// 0x00aa2d10
int FUN_00aa2d10(int, int);
// 0x00aa2dd0
unsigned int FUN_00aa2dd0(::NiMemStream *, void *, const void *, unsigned int);
// 0x00aa2e60
namespace fnv_00aa2e60 { unsigned int FUN_00aa2e60(::fnv_00aa2e60::NiMemStream *, void *, unsigned int); }
// 0x00aa2ea0
void FUN_00aa2ea0(::S_00aa2dd0 *, const void *, unsigned int);
// 0x00aa2ec0
unsigned int FUN_00aa2ec0(::NiMemStream *, void *, unsigned int, void *, void *);
// 0x00aa2f20
unsigned int FUN_00aa2f20(::NiMemStream *, const void *, unsigned int, void *, void *);
