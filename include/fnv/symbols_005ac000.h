#pragma once

class ExtraDataList;
class Script;
struct ScriptLocals;
class TESForm;
class TESObjectREFR;
struct ExtractParameter;
struct ExtractScript;

// 0x005ac190
void FUN_005ac190(::TESObjectREFR *, ::ExtraDataList *);
// 0x005ac750
bool FUN_005ac750(::TESForm *, ::ExtraDataList *, unsigned int);
// 0x005ac7a0
bool ReadScriptValue(double *, const char *, unsigned int *, ::TESObjectREFR *, ::TESObjectREFR *, ::Script *, ::ScriptLocals *, bool);
// 0x005acc90
void FUN_005acc90(unsigned int *, const double *);
// 0x005accb0
bool FUN_005accb0(const ::ExtractParameter *, const char *, unsigned int *, ::TESObjectREFR *, ::TESObjectREFR *, ::ExtractScript *, ::ScriptLocals *, ...);
