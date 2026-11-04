#pragma once

class TESFile;

class ScriptVariableInfo {
public:
    // 0x005e28b0
    ScriptVariableInfo();
    // 0x005e2a20
    void Load(::TESFile *);
};
