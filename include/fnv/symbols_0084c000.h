#pragma once

class B84C490SaveBuffer;
struct BGSLoadGameBuffer;

// 0x0084c030
bool FUN_0084c030(unsigned int, ::BGSLoadGameBuffer *);
// 0x0084c110
namespace fnv_0084c110 { void FUN_0084c110(unsigned int, unsigned int); }
// 0x0084c270
void BGSSaveLoadHistory_Destroy(unsigned char);
// 0x0084c490
void SavePlayerLocation(::B84C490SaveBuffer *);
// 0x0084c5a0
void LoadPlayerLocation(::BGSLoadGameBuffer *);
// 0x0084cbd0
void FUN_0084cbd0(const char *, ...);
// 0x0084ced0
namespace fnv_0084ced0 { void ReconstructAllGlobals(); }
// 0x0084cf30
void SaveImageSpaceModifierInstances(void *);
