#pragma once

class QuestDialogueInfo;
class TESQuest;

struct FUN_006195d0_shell {
public:
    // 0x006195d0
    ::QuestDialogueInfo *GetOrCreateQuestInfo(::TESQuest *, bool);
};
