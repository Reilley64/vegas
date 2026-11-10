// fallout/ai/character_decls.h: declares BGSLoadFormBuffer, Character, PlayerCharacter, AudioMarkerDataCalls, CharacterActorCalls
#ifndef FNV_CHARACTER_DECLS_H
#define FNV_CHARACTER_DECLS_H

#include "fnv/decl/P164Actor.h"
#include "fnv/decl/PlayerNearbyRefs.h"
#include "fnv/decl/TESRace.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#define PlayerCharacter PlayerCharacter_ActorHeader
#include "Actor.h"
#undef PlayerCharacter

struct BGSLoadFormBuffer
{
  public:
    virtual unsigned char GetVersion();
};

class Character : public Actor
{
  public:
    BipedAnim* pBiped;
    float m_fFirstResetValue;
    float m_fSecondValue;
    bool m_bTrespassing;
    bool m_bActorGuard;
    unsigned char layoutPadding1C2[2];
    float m_fThirdValue;
    virtual void Unk_137(void);
    virtual void Unk_138(void);

    MagicTarget* GetMagicTarget();
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void* GetCurrentMusicMarker();
public:
    void FUN_008d4e80();
};

class MusicMarkerReference;
struct Biped;
class PlayerCharacter
{
  public:
public:
    ::Biped *FUN_00950b00(bool);
};

class AudioMarkerDataCalls
{
  public:
};

class CharacterActorCalls
{
  public:
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
};
#endif
