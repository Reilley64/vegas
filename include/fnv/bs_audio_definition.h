#ifndef FNV_BS_AUDIO_DEFINITION_H
#define FNV_BS_AUDIO_DEFINITION_H

// BSAudioDefinition and BSSoundInfo: the description of one sound, and the
// record the audio manager keeps per sound, which holds one.
//
// This is the one shared declaration of the two classes. It declares the
// fields, and the members that build/units.json gives an address under the
// class's name. The header has no body: src/bsaudio/bsaudiodefines_h_unit.cpp
// owns the five addresses and defines the members.
//
// The fields are the owning unit's. Each class holds its own two pointers, so
// the offsets follow the pointer size: the classes are 572 and 596 bytes in
// the 32-bit original and 584 and 608 bytes where a pointer is eight bytes.
// Code that constructs one in place must provide that storage.
// docs/shared-audio-definition.md has the measurements.

#include <cstddef>

// The position type as the two audio units declare it. NiPoint3 has no shared
// declaration yet; a unit that declares another NiPoint3 at global scope
// cannot include this header.
struct NiPoint3
{
    float x;
    float y;
    float z;
    static const NiPoint3 ZERO;
};

class BSAudioDefinition
{
  public:
    char* pName;
    char Name[260];
    char* pFileName;
    char FileName[260];
    float fFirstValue;
    float fSecondValue;
    NiPoint3 Location;
    unsigned int uiSoundFlags;
    float m_fMinimumDistance;
    float m_fMaximumDistance;
    unsigned int m_uiSoundParameterA;
    unsigned int m_uiSoundParameterB;
    unsigned int m_uiSoundParameter6;

    BSAudioDefinition();                                          // 0x00ae8770
    ~BSAudioDefinition();                                         // 0x00ae8830
    BSAudioDefinition& operator=(const BSAudioDefinition& aCopy); // 0x00ae88c0
};

class BSSoundInfo
{
  public:
    unsigned int m_uiSoundID;
    float m_fSoundVolume;
    float m_fFadeDuration;
    unsigned int m_uiValueAt0C;
    unsigned int m_uiPlaybackFlags;
    bool m_bValueAt14;
    unsigned char layoutPadding15[3];
    BSAudioDefinition m_kAudioDefinition;

    BSSoundInfo(BSSoundInfo* aCopy); // 0x00ae8a40
    ~BSSoundInfo();                  // 0x00ae8af0
};

// The storage the owning unit's bodies write. The constructor of
// BSAudioDefinition stores into every byte range checked here.
static_assert(sizeof(void*) == 8);
static_assert(offsetof(BSAudioDefinition, Name) == 0x8);
static_assert(offsetof(BSAudioDefinition, pFileName) == 0x110);
static_assert(offsetof(BSAudioDefinition, FileName) == 0x118);
static_assert(offsetof(BSAudioDefinition, fFirstValue) == 0x21c);
static_assert(offsetof(BSAudioDefinition, Location) == 0x224);
static_assert(offsetof(BSAudioDefinition, uiSoundFlags) == 0x230);
static_assert(offsetof(BSAudioDefinition, m_uiSoundParameter6) == 0x244);
static_assert(sizeof(BSAudioDefinition) == 0x248);
static_assert(offsetof(BSSoundInfo, m_kAudioDefinition) == 0x18);
static_assert(sizeof(BSSoundInfo) == 0x260);

#endif
