#pragma once

class NiFile;
class NiFileHack;
struct ProcessingState;

// 0x00aa1000
void FUN_00aa1000();
// 0x00aa1070
void *FUN_00aa1070(unsigned int);
// 0x00aa10b0
void *FUN_00aa10b0(unsigned int, unsigned int);
// 0x00aa10f0
void FUN_00aa10f0(void *);
// 0x00aa1110
namespace fnv_00aa1110 { void FUN_00aa1110(void *); }
// 0x00aa1130
void *FUN_00aa1130(unsigned int, unsigned int);
// 0x00aa1190
namespace fnv_00aa1190 { void FreeAllocatorBlock(void *); }
// 0x00aa11b0
void *InlRealloc(void *, unsigned int);
// 0x00aa12f0
float GetElapsedSeconds();
// 0x00aa1360
int NiStricmp(const char *, const char *);
// 0x00aa1370
int FUN_00aa1370(const char *, const char *, unsigned int);
// 0x00aa1380
void NormalizePathSeparators(char *);
// 0x00aa13e0
void FUN_00aa13e0(int);
// 0x00aa1420
void FUN_00aa1420(int);
// 0x00aa1460
void FUN_00aa1460(void *, unsigned int);
// 0x00aa1490
void FUN_00aa1490(void *, unsigned int);
// 0x00aa1980
void FUN_00aa1980();
// 0x00aa19a0
unsigned int ReadFileData(::NiFileHack *, void *, unsigned int);
// 0x00aa19c0
void FUN_00aa19c0(void *, void *, unsigned int);
// 0x00aa19e0
unsigned int FUN_00aa19e0(::NiFile *, void *, unsigned int, void *, void *);
// 0x00aa1ab0
void FUN_00aa1ab0();
// 0x00aa1ad0
unsigned int FUN_00aa1ad0(::ProcessingState *, const void *, unsigned int, void *, void *);
// 0x00aa1d40
unsigned char FUN_00aa1d40();
// 0x00aa1de0
void SwapBufferBySizes(char *, unsigned int, const unsigned int *, unsigned int);
