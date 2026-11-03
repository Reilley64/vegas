#pragma once

class TESFile;

// 0x004856d0
void FUN_004856d0(int);
// 0x004856f0
void FUN_004856f0(void *, void *, void *);
// 0x00485710
void FUN_00485710(void *, void *, void *);
// 0x00485730
void FUN_00485730(void *, void *, void *);
// 0x00485820
void FUN_00485820(void *, void *, unsigned int);
// 0x004858f0
void FUN_004858f0(unsigned int, unsigned char);
// 0x00485910
void FUN_00485910(unsigned int, int);
// 0x00485950
void FUN_00485950(void *, unsigned short);
// 0x00485990
void AppendChunk(unsigned int, const void *, unsigned int);
// 0x00485d50
void ResolveFormID(unsigned int *, ::TESFile *);
