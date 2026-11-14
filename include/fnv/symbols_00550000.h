#pragma once

class TESFile;
struct FormS;

// 0x005504e0
int GetSourceFileCount(::FormS *);
// 0x00550e10
bool HasFormInGroup(::TESFile *, unsigned int);
// 0x00550f60
bool FUN_00550f60(::TESFile *);
