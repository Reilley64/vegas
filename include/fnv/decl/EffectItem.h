#pragma once

class TESFile;
template <class> class BSStringT;

class EffectItem {
public:
    // 0x00403ea0
    int GetAffectedActorValue();
    // 0x00404120
    bool Load(::TESFile *, const char *);
    // 0x00404670
    ::BSStringT<char> GetEffectName();
    // 0x00404710
    bool IsHostile();
    // 0x00404730
    bool IsScriptBasedEffect();
    // 0x00405e40
    bool IsDetrimental();
};
