#pragma once

namespace fnv_00af4be0 { struct PluginFile; }

// 0x00af4070
void FUN_00af4070(char *, const char *);
// 0x00af4170
unsigned int GetPathHash(const char *, bool);
// 0x00af4200
bool CleanPath(const char *, char *, unsigned int);
// 0x00af4250
void BuildAssetPath(const char *, char *, unsigned int);
// 0x00af4310
void CopyRelativeDataPath(const char *, char *, unsigned int);
// 0x00af43a0
void FUN_00af43a0(bool, char *, char *, unsigned int);
// 0x00af4460
void FUN_00af4460(bool);
// 0x00af4470
void FUN_00af4470(int, int, int);
// 0x00af4490
void FUN_00af4490(bool, const char *);
// 0x00af4540
void FUN_00af4540();
// 0x00af4550
namespace fnv_00af4550 { bool FUN_00af4550(); }
// 0x00af4be0
namespace fnv_00af4be0 { ::fnv_00af4be0::PluginFile *FUN_00af4be0(const char *, unsigned short, bool); }
