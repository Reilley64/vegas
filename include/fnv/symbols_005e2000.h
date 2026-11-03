#pragma once
#include <cstdint>

class Script;
class ScriptLocalVariable;
class ScriptRunner;
class TESSound;

// 0x005e23f0
bool GetThreadLocalValue();
// 0x005e2410
void LogScriptCompileError(::ScriptRunner *, ::Script *, char *, ...);
// 0x005e28e0
::ScriptLocalVariable *FUN_005e28e0(::ScriptLocalVariable *);
// 0x005e2a70
::TESSound *GetBrushSound(const char *);
// 0x005e2b50
const char *GetStringByIndex(intptr_t);
