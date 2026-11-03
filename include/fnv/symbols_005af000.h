#pragma once

struct CompilerShell;
struct ScriptLineBuffer;
struct ScriptSource;
struct ScriptVariableData;

// 0x005af3f0
int ReadScriptLine(::ScriptSource *, ::ScriptLineBuffer *);
// 0x005af5f0
int FUN_005af5f0(::CompilerShell *, ::ScriptVariableData *, char *, int *, bool, bool);
// 0x005afe10
void FUN_005afe10(int, int, int);
// 0x005afeb0
namespace fnv_005afeb0 { bool FUN_005afeb0(const char *); }
