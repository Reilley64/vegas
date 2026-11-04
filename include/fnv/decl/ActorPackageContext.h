#pragma once

class BGSLoadFormBuffer;
class TESObjectREFR;
class TESPackage;

class ActorPackageContext {
public:
    // 0x008c5ef0
    void Clear();
    // 0x008c6080
    void SetPackageAndTarget(::TESPackage *, ::TESObjectREFR *);
    // 0x008c6730
    void LoadGame(::BGSLoadFormBuffer *);
    // 0x008c6b20
    void ApplyLoadBuffer(::BGSLoadFormBuffer *);
};
