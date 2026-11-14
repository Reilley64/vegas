#pragma once
#include <cstdint>

struct NiCameraStandIn;
struct NiPoint3;

// 0x00a7d330
char *FUN_00a7d330(const char *);
// 0x00a7d370
char *FUN_00a7d370(const char *, bool);
// 0x00a7d3d0
void *FormatStringAssignment(const char *, char);
// 0x00a7d410
char *FUN_00a7d410(const char *, unsigned char);
// 0x00a7d450
char *FUN_00a7d450(const char *, short);
// 0x00a7d490
char *FUN_00a7d490(const char *, unsigned short);
// 0x00a7d4d0
char *FUN_00a7d4d0(const char *, intptr_t);
// 0x00a7d510
char *FUN_00a7d510(const char *, uintptr_t);
// 0x00a7d550
char *FUN_00a7d550(const char *, float);
// 0x00a7d5a0
char *FUN_00a7d5a0(const char *, void *);
// 0x00a7d5e0
namespace fnv_00a7d5e0 { char *FUN_00a7d5e0(const char *, const char *); }
// 0x00a7d6e0
void *FUN_00a7d6e0();
// 0x00a7db60
char *FUN_00a7db60(const char *, int);
// 0x00a7dc40
bool FUN_00a7dc40(::NiCameraStandIn *, const ::NiPoint3 &, ::NiPoint3 &, ::NiPoint3 &, ::NiPoint3 &);
