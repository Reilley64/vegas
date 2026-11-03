#pragma once

class TESCreature;
class TESFile;
enum CREATURE_SOUND_TYPE;

class CreatureSoundCollection {
public:
    // 0x005f0480
    bool LoadSoundsFromFile(::TESFile *, ::CREATURE_SOUND_TYPE, ::TESCreature *);
    // 0x005f7bf0
    void *DeleteThis(unsigned int);
};
