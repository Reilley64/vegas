#pragma once

class Script;
class TESObjectREFR;
enum SCRIPT_OUTPUT;

class ScriptRunner {
public:
    // 0x005e13a0
    bool ParseOutput(::Script *, ::SCRIPT_OUTPUT &, unsigned int &, int &, ::TESObjectREFR **, bool);
    // 0x005e1550
    bool ParseBlock(::Script *, const ::SCRIPT_OUTPUT, ::TESObjectREFR *, int &, const unsigned int, unsigned int &, const unsigned int, bool, bool);
};
