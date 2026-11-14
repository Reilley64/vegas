#pragma once

struct CombatEntryObj;
struct CombatGroupTarget;

struct CombatSearchCls {
public:
    // 0x0098c7b0
    bool CheckOtherEntriesForTarget(::CombatEntryObj *, ::CombatGroupTarget *);
};
