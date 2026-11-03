#pragma once

class BGSBodyPartData;
class CreatureSoundCollection;

class TESCreature {
public:
    // 0x0059f3a0
    signed char GetCreatureType() const;
    // 0x005f7230
    TESCreature();
    // 0x005f7900
    ~TESCreature();
    // 0x005f7b80
    void ClearData();
    // 0x005f9140
    void SetCreatureSoundsFrom(::TESCreature *);
    // 0x005f9210
    ::CreatureSoundCollection *GetMutableCreatureSounds();
    // 0x005f92d0
    intptr_t FUN_005f92d0(int);
    // 0x005fa310
    void SetBodyPartData(::BGSBodyPartData *);
    // 0x005fbf20
    char FUN_005fbf20() const;
};
