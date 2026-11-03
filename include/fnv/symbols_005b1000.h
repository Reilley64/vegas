#pragma once

class ScriptFunctionInfo;
enum SCRIPT_OUTPUT;
struct ScriptWordView;

// 0x005b1120
::ScriptFunctionInfo *GetFunctionByOpcode(::SCRIPT_OUTPUT);
// 0x005b1910
bool ResolveScriptCommand(::ScriptWordView *);
// 0x005b1b60
void FUN_005b1b60(const char *, int *);
