// BSAudioDefinition, as the owning unit of the game library defines it: this
// program compiles the same bodies, src/bsaudio/bsaudiodefinition.inl, against
// the shared declaration.
//
// It guards what the constructor and the assignment do, and the two string
// copies. Each definition lives in a heap block of exactly its size, so a
// sanitizer build reports one of these bodies writing past the declared size.
//
// It does not guard the callers. It cannot see a site in
// src/bsaudio/bsaudiomanager.cpp that provides too little storage, and it
// never executes BSSoundInfo::BSSoundInfo(BSSoundInfo*): that the body at
// 0x00ae8a40 writes 608 bytes rests on the disassembly of the owning unit's
// object. The layout guard is the static_asserts of the header.

#include "fnv/bs_audio_definition.h"

#include <cstdio>
#include <cstring>
#include <memory>
#include <new>

#include "bsaudio/bsaudiodefinition.inl"

// The game library defines this constant in its composed data, with this
// initializer. That object cannot be linked into a host program.
const NiPoint3 NiPoint3::ZERO{};

namespace
{
int failures;

void Check(bool condition, const char* name)
{
    if (!condition)
    {
        std::fprintf(stderr, "audio definition: %s\n", name);
        ++failures;
    }
}

struct Storage
{
    std::unique_ptr<unsigned char[]> bytes{new unsigned char[sizeof(BSAudioDefinition)]};

    Storage()
    {
        std::memset(bytes.get(), 0xcd, sizeof(BSAudioDefinition));
    }
    BSAudioDefinition* Construct()
    {
        return new (bytes.get()) BSAudioDefinition();
    }
};

void Construction()
{
    Storage storage;
    BSAudioDefinition* definition = storage.Construct();
    Check(definition->pName == definition->Name, "the name pointer is the object's own buffer");
    Check(definition->pFileName == definition->FileName, "the file name pointer is the object's own buffer");
    Check(definition->Name[0] == 0 && definition->FileName[0] == 0, "both strings start empty");
    Check(definition->fFirstValue == 0.0f && definition->fSecondValue == 0.0f, "the two values start at zero");
    Check(definition->Location.x == NiPoint3::ZERO.x && definition->Location.y == NiPoint3::ZERO.y &&
              definition->Location.z == NiPoint3::ZERO.z,
          "the location starts at the zero point");
    Check(definition->uiSoundFlags == 0 && definition->m_fMinimumDistance == 0.0f &&
              definition->m_fMaximumDistance == 0.0f,
          "flags and distances start at zero");
    Check(definition->m_uiSoundParameterA == 0 && definition->m_uiSoundParameterB == 0 &&
              definition->m_uiSoundParameter6 == 0,
          "the three parameters start at zero");
    definition->~BSAudioDefinition();
}

void Assignment()
{
    Storage sourceStorage;
    Storage targetStorage;
    BSAudioDefinition* source = sourceStorage.Construct();
    BSAudioDefinition* target = targetStorage.Construct();
    std::memcpy(source->Name, "name", 5);
    std::memcpy(source->FileName, "file", 5);
    source->fFirstValue = 1.0f;
    source->fSecondValue = 2.0f;
    source->Location.x = 3.0f;
    source->Location.y = 4.0f;
    source->Location.z = 5.0f;
    source->uiSoundFlags = 6;
    source->m_fMinimumDistance = 7.0f;
    source->m_fMaximumDistance = 8.0f;
    source->m_uiSoundParameterA = 9;
    source->m_uiSoundParameterB = 10;
    source->m_uiSoundParameter6 = 11;

    BSAudioDefinition& result = (*target = *source);
    Check(&result == target, "assignment returns the target");
    Check(target->pName == target->Name && target->pFileName == target->FileName,
          "the target keeps pointing at its own buffers");
    Check(std::strcmp(target->Name, "name") == 0 && std::strcmp(target->FileName, "file") == 0,
          "both strings are copied");
    Check(target->fFirstValue == 1.0f && target->fSecondValue == 2.0f, "the two values are copied");
    Check(target->Location.x == 3.0f && target->Location.y == 4.0f && target->Location.z == 5.0f,
          "the location is copied");
    Check(target->uiSoundFlags == 6 && target->m_fMinimumDistance == 7.0f && target->m_fMaximumDistance == 8.0f,
          "flags and distances are copied");
    Check(target->m_uiSoundParameterA == 9 && target->m_uiSoundParameterB == 10 &&
              target->m_uiSoundParameter6 == 11,
          "the three parameters are copied");

    // A source without strings empties the target's.
    source->pName = nullptr;
    source->pFileName = nullptr;
    *target = *source;
    Check(target->Name[0] == 0 && target->FileName[0] == 0, "a source without strings empties both");
    Check(target->pName == target->Name && target->pFileName == target->FileName,
          "the target's pointers survive a source without strings");

    target->~BSAudioDefinition();
    source->~BSAudioDefinition();
}
}

int main()
{
    Construction();
    Assignment();
    return failures == 0 ? 0 : 1;
}
