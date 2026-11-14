#pragma once

class TESFaction;

class ExtraFactionChanges {
public:
    // 0x00436e10
    void RemoveFaction(::TESFaction *);
    // 0x00436f80
    void SetFactionRank(::TESFaction *, int);
    // 0x0047ebf0
    bool HasFactionEntry(::TESFaction *);
};
