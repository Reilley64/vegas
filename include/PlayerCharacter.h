// Source layout: PlayerCharacter. PC corrections are in generate_headers.py.
#ifndef FNV_PLAYERCHARACTER_H
#define FNV_PLAYERCHARACTER_H
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "layout_support.h"
#include "Character.h"
struct Animation;
class PlayerCharacter : public Character
{
  public:
    enum ModifierGroup
    {
        TEMPORARY = 0,
        SCRIPTS = 1,
        DAMAGE = 2
    };
    unsigned int layoutPadding1C8[31];
    float ActorValueModifierData[77];  // +0x244
    float m_afScriptModifiers[77];     // +0x378
    float ActorValueState;             // +0x4AC
    float ActorValueData[77];          // +0x4B0
    unsigned int layoutPadding5E4[26];
    bool bThirdPerson;  // +0x64C
    unsigned char layoutPadding64D;
    unsigned short layoutPadding64E;
    unsigned int layoutPadding650[12];
    unsigned char m_ucValueAt680;  // +0x680
    unsigned char layoutPadding681;
    unsigned short layoutPadding682;
    unsigned int layoutPadding684[13];
    TESQuest* m_pCurrentQuest;                          // +0x6B8
    BSSimpleList<BGSQuestObjective*> m_kObjectiveList;  // +0x6BC
    unsigned int layoutPadding6C4[61];
    unsigned char m_ucByteAtOffset7B8;  // +0x7B8
    unsigned char layoutPadding7B9;
    unsigned short layoutPadding7BA;
    bool m_bHasPerks;  // +0x7BC
    unsigned char layoutPadding7BD;
    unsigned short layoutPadding7BE;
    unsigned int layoutPadding7C0[47];
    BSSimpleList<PerkForm*> Perks;                             // +0x87C
    BSSimpleList<BGSEntryPointPerkEntry*> m_kEntryPointPerks[74];  // +0x884
    BSSimpleList<PerkForm*> m_kCompanionPerks;                 // +0xAD4
    unsigned int layoutPaddingADC[221];
    float GetActorValueModifierAmount(ModifierGroup modifier, ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index actorValue);
    virtual void Unk_139();
    virtual BSSimpleList<PerkForm*>* GetPerks(bool teammate);
    bool IsSleepingOrResting();
public:
    ::Animation *GetAnimation(bool) const;
};
#endif
