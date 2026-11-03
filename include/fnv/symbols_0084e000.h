#pragma once

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class FormChangeMask;
class GameFileBuf;
class TESForm;
enum INITIAL_DATA_TYPE;
namespace fnv_0084e730 { struct FormChangeMask; }
struct BGSNumericIDIndex3;

// 0x0084e730
namespace fnv_0084e730 { int FUN_0084e730(unsigned int, int, ::fnv_0084e730::FormChangeMask); }
// 0x0084e800
unsigned int FUN_0084e800(int);
// 0x0084e850
unsigned int FUN_0084e850(::GameFileBuf *, int, void *);
// 0x0084e8c0
int LoadFormData(::BGSLoadFormBuffer *, int, void *);
// 0x0084e930
void FUN_0084e930(::BGSLoadFormBuffer *, ::INITIAL_DATA_TYPE, void *);
// 0x0084eaf0
::BGSNumericIDIndex3 *ClearNumericIDIndex(::BGSNumericIDIndex3 *);
// 0x0084eb80
::INITIAL_DATA_TYPE FUN_0084eb80(::BGSSaveFormBuffer *, ::TESForm *, ::FormChangeMask);
