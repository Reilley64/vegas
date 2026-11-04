#pragma once

class BGSQuestObjective;

struct FilterHost {
public:
    // 0x007a49e0
    void ApplyObjectiveFilter(bool (*)(BGSQuestObjective *));
};
