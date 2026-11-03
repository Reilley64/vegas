#pragma once

class NiFixedString;
class NiObject;
class ShaderEntry;

// 0x00aa0020
int FUN_00aa0020(int, int, const char *, ...);
// 0x00aa0400
bool AcquireGlobalConstantEntry(const ::NiFixedString *, unsigned int, unsigned int, unsigned int);
// 0x00aa04e0
bool RemoveGlobalConstant(const ::NiFixedString *);
// 0x00aa08d0
::ShaderEntry *FindOrCreateShaderEntry(const char *, bool);
// 0x00aa0ab0
void FUN_00aa0ab0();
// 0x00aa0ac0
void FUN_00aa0ac0();
// 0x00aa0ad0
void FUN_00aa0ad0();
// 0x00aa0ae0
unsigned char FUN_00aa0ae0(::NiObject *);
