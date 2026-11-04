#pragma once

class SaveLoadFile;
class TESForm;
class TESObjectCELL;
class TESWorldSpace;
struct FUN_008464f0_arg;
struct UnknownOwner008463c0;

// 0x00846080
unsigned int ReadEncodedInteger(char *, unsigned int &);
// 0x00846190
bool GetCellAndWorldspaceForForm(::TESForm *, ::TESObjectCELL *&, ::TESWorldSpace *&);
// 0x008463c0
bool FUN_008463c0(::UnknownOwner008463c0 *);
// 0x008464f0
void FUN_008464f0(char *, ::FUN_008464f0_arg);
// 0x00846520
::SaveLoadFile *FUN_00846520(const char *, bool, unsigned int);
// 0x00846a20
namespace fnv_00846a20 { void UpdateFileWriteTime(char *); }
// 0x00846ad0
namespace fnv_00846ad0 { bool FUN_00846ad0(const char **); }
// 0x00846af0
namespace fnv_00846af0 { bool IsLegacyAutosaveFileName(const char **); }
