#pragma once

class Script;
struct ScriptLocals;
namespace fnv_005e1160 { class TESObjectREFR; }

namespace fnv_005e1160 {
class ScriptRunner {
public:
    // 0x005e1160
    bool RunScript(::Script *, ::fnv_005e1160::TESObjectREFR *, ::ScriptLocals *);
};
}
