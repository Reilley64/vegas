#pragma once

class ScriptCompiler;
class TESObjectREFR;
enum COMPILER_NAME;

struct ScriptCompileAndRun {
public:
    // 0x005ac400
    void FUN_005ac400(::ScriptCompiler *, ::COMPILER_NAME, ::TESObjectREFR *);
};
