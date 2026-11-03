#pragma once

class SaveLoadFile;
enum SIZE_TYPE;
namespace fnv_00845d80 { struct FUN_00846330_shell; }
struct FUN_00845b30_arg;
struct FUN_00846330_shell;

// 0x008456c0
void FUN_008456c0(void *);
// 0x00845b30
int *FUN_00845b30(int *, ::FUN_00845b30_arg);
// 0x00845cc0
void FUN_00845cc0(const char *, ...);
// 0x00845d00
void ForwardToShell(::FUN_00846330_shell *, int, int);
// 0x00845d20
void ReadFileIntoBuffer(::SaveLoadFile *, unsigned int *, unsigned int);
// 0x00845d80
namespace fnv_00845d80 { void WriteValueByType(::fnv_00845d80::FUN_00846330_shell *, unsigned short, int); }
// 0x00845de0
void WriteTypedValue(void *, unsigned int, unsigned int);
// 0x00845e50
unsigned int ReadSizedUnsignedInt(::SaveLoadFile *, unsigned int &, ::SIZE_TYPE);
// 0x00845ee0
unsigned int ReadValueBySizeType(const void *, unsigned int *, unsigned int);
