#pragma once

class TESBoundObject;

struct ScriptLocals {
public:
    // 0x00541c80
    ::TESBoundObject *GetLocalData();
    // 0x00541cb0
    ::TESBoundObject *GetActionEntry();
    // 0x006ebc50
    void ProcessPendingTasks();
};
