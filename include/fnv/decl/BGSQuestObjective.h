#pragma once

class TESQuest;

class BGSQuestObjective {
public:
    // 0x00437730
    void SetOwner(::TESQuest *);
    // 0x005a5dc0
    bool GetCompleted() const;
    // 0x005a5e70
    bool GetDisplayed() const;
    // 0x005ec1b0
    void Initialize();
};
