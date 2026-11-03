#pragma once

class NiPoint3;
class TESObjectCELL;
class bhkCharacterController;

// 0x00553300
void FUN_00553300(unsigned int);
// 0x00553320
char *FUN_00553320(unsigned char, unsigned int);
// 0x00553380
void FUN_00553380(void *);
// 0x00553520
void FUN_00553520(void *);
// 0x00553820
namespace fnv_00553820 { void FUN_00553820(::TESObjectCELL *); }
// 0x00553b60
char FUN_00553b60(char *);
// 0x00553fc0
::bhkCharacterController *CopyCharacterControllerVector(::bhkCharacterController *, const ::NiPoint3 &);
