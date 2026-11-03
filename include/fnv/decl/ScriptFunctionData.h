#pragma once

class TESForm;
struct FunctionData;

class ScriptFunctionData {
public:
    // 0x00681fb0
    static void InitItem(::TESForm *, ::FunctionData *);
    // 0x00682270
    static unsigned int GetParamCount(const ::FunctionData *);
    // 0x006822a0
    static bool IsParamTESForm(const ::FunctionData *, unsigned int);
};
