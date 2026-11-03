#pragma once

namespace ActorValue { enum Index; }

class TESClass {
public:
    // 0x005a5f40
    bool IsTagSkill(::ActorValue::Index) const;
    // 0x005f67c0
    void ResetFormData();
    // 0x005f6e60
    bool IsGuard();
    // 0x005f6e80
    void SetClassSkillAtIndex(int, ::ActorValue::Index);
};
