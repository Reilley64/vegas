#pragma once

class TESFile;
class TESForm;
class TESModel;

// 0x00489190
void FUN_00489190(char *, ::TESForm *);
// 0x00489280
bool FUN_00489280(int);
// 0x004893e0
void FUN_004893e0(::TESModel *, ::TESFile *);
// 0x00489540
unsigned int FUN_00489540(void *);
// 0x004895b0
const char *FUN_004895b0(::TESForm *);
// 0x004898f0
namespace fnv_004898f0 { unsigned int GetFltValue(int); }
