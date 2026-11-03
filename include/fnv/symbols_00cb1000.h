#pragma once

struct DepthLimit;

// 0x00cb1090
void FUN_00cb1090(char *, const char *);
// 0x00cb10b0
void CopyIfNonEmpty(char *, const char *, int);
// 0x00cb10d0
namespace fnv_00cb10d0 { int FUN_00cb10d0(const char *); }
// 0x00cb10f0
void CallWithZeroMiddleArg(int, int);
// 0x00cb1130
namespace fnv_00cb1130 { const char *FUN_00cb1130(const char *, const char *); }
// 0x00cb1140
namespace fnv_00cb1140 { char *FUN_00cb1140(const char *, int); }
// 0x00cb1150
namespace fnv_00cb1150 { const char *FUN_00cb1150(const char *, int); }
// 0x00cb1160
char *FUN_00cb1160(const char *, void *);
// 0x00cb1190
int CallSwappedArgs(unsigned int, unsigned int);
// 0x00cb11b0
namespace fnv_00cb11b0 { void *FUN_00cb11b0(void *, int, void *); }
// 0x00cb1260
void *FUN_00cb1260(void *, const void *, unsigned int);
// 0x00cb1270
void *FUN_00cb1270(char *, const char *, int);
// 0x00cb1280
void FUN_00cb1280(void *, int, unsigned int);
// 0x00cb1290
int FUN_00cb1290(const unsigned char *, const unsigned char *, unsigned int);
// 0x00cb13c0
void FUN_00cb13c0(int);
// 0x00cb1410
void FUN_00cb1410(int);
// 0x00cb17f0
int FUN_00cb17f0(int);
// 0x00cb1810
int FUN_00cb1810(int);
// 0x00cb1980
int LookupBucketValue(::DepthLimit *, int, int, int *);
