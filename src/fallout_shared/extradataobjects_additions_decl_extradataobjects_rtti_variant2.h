// Unit-private additions. No supplied header or accepted definition is changed.
#ifndef FNV_EXTRADATAOBJECTS_ADDITIONS_H
#define FNV_EXTRADATAOBJECTS_ADDITIONS_H

// Canonical callable identities from IDENTITIES.md. Settings named by
// JohnnyGuitarNVSE GameSettingCollection.hpp and JIP settings_enum.h.
#include <cstring>
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_011c3000.h"
union SETTING_VALUE
{
    int i;
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
};
class GameSettingCollection
{
  public:
};

// Declaration source: include/NiPoint3.h; natural PC alignment.
// Source layout: NiPoint3. PC corrections are in generate_headers.py.
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
};

// Names of nested/template specializations use the canonical generator identifier mapping.
class ReferenceIntersectionData;
class ReferenceIntersectionData
{
  public:
    TESObjectREFR* m_pHitReference;  // +0x0, 4 bytes
    NiPoint3 Intersect;              // +0x4, 12 bytes
    NiPoint3 Normal;                 // +0x10, 12 bytes
};

// Names of nested/template specializations use the canonical generator identifier mapping.
class ExtraHealth;
class ExtraHealth : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    float fHealthPercent;  // +0xC, 4 bytes
    bool Compare(BSExtraData* extra);
    // ExtraHealth
    // bool __cdecl ExtraHealth::*(BSExtraData*)
    // void __cdecl ExtraHealth::*()
    // ExtraHealth& __cdecl ExtraHealth::*(const ExtraHealth&)
    // void __cdecl ExtraHealth::*()
};

// Names of nested/template specializations use the canonical generator identifier mapping.
class ExtraDecalRefs;
class ReferenceIntersectionData;
class ExtraDecalRefs : public BSExtraData
{
  public:
    void FUN_00433db0(TESForm* form);  // declared for the original code (decl_variants.py)

  public:
    // base BSExtraData at +0x0, size 12
    BSSimpleList<ReferenceIntersectionData*> m_kDecalReferences;  // +0xC, 8 bytes
    ReferenceIntersectionData* FindDecalReference(TESObjectREFR*);
    // ExtraDecalRefs
    // void __cdecl ExtraDecalRefs::*()
    // void __cdecl ExtraDecalRefs::*(TESForm*)
    // bool __cdecl ExtraDecalRefs::*(BSExtraData*)
    // void __cdecl ExtraDecalRefs::*(BSExtraData*)
    // void __cdecl ExtraDecalRefs::*()
    // void __cdecl ExtraDecalRefs::*(TESObjectREFR*)
    // void __cdecl ExtraDecalRefs::*(TESObjectREFR*, const NiPoint3&, const NiPoint3&)
    // ExtraDecalRefs& __cdecl ExtraDecalRefs::*(const ExtraDecalRefs&)
    // void __cdecl ExtraDecalRefs::*()
};

// independently declares these names/types and the PC8-byte record layout.
class FactionReaction
{
  public:
    TESFaction* pFaction;
    char m_ucRank;
};

// Public names/layout: JohnnyGuitarNVSE BGSQuestObjective.hpp; its cpp
// explicitly annotates SetOwner as GAME00437730. No implementation copied.
class TESQuest;
class RegionObjectEntry;
class BGSQuestObjective
{
  public:
    BGSQuestObjective();
    virtual ~BGSQuestObjective();
    struct _State
    {
        enum State
        {
            DORMANT = 0,
            DISPLAYED = 1,
            COMPLETED = 2,
            COMPLETED_DISPLAYED = 3
        };
    };
    typedef _State::State State;
    unsigned int uiIndex;
    BSStringT<char> QuestObjectiveEntry;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<RegionObjectEntry*> kTargets;
    bool bInitialized;
    State eState;
    void SetOwner(TESQuest*);
};
#endif
