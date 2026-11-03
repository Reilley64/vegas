// Private declarations for the playercharacter.h unit.
#ifndef FNV_PLAYERCHARACTER_UNIT_DECLS_H
#define FNV_PLAYERCHARACTER_UNIT_DECLS_H

#include "fnv/decl/FNV_AnimationOwner.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/fnv_00494740__FUN_00494740_t.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_01197000.h"
#include "layout_support.h"
class TESObjectWEAP;
class ActorCombatGroup;
class Animation;
class BSAnimGroupSequence;
enum ACTION_FLAGS
{
    ACTION_FLAGS_NONE = 0
};
enum ANIM_GROUP_SECTION
{
    ANIM_GROUP_SECTION_NONE = -1
};
class NiNode;
class TESObjectREFR;
template <class> class BSSimpleList;
class Animation
{
  public:
public:
    bool Init(::BSSimpleList<const char *> *, ::NiNode *, ::TESObjectREFR *, bool);
public:
    float FUN_009442a0() const;
};
enum ANIM_GROUP_ENUM;
enum ANIM_GROUP_MOVE_ENUM;
enum ANIM_GROUP_WEAPON_ENUM;
class TESAnimGroup
{
  public:
    static ANIM_GROUP_ENUM GetType(unsigned short group);
public:
    static unsigned short AnimGroup(::ANIM_GROUP_MOVE_ENUM, ::ANIM_GROUP_WEAPON_ENUM, ::ANIM_GROUP_ENUM, bool);
public:
    ::ANIM_GROUP_ENUM GetType() const;
public:
    static bool IsActionTypeValid(unsigned short);
public:
    static bool IsValidAnimationGroup(unsigned short);
};
struct PlayerCharacterAnimGroupInfo
{
    bool availableInThirdPerson;
    unsigned char layoutPadding1[3];
    ANIM_GROUP_SECTION section;
    unsigned char layoutPadding8[28];
};
// Source layout: PlayerCharacter. PC corrections are in generate_headers.py.
#ifndef FNV_PLAYERCHARACTER_H
#define FNV_PLAYERCHARACTER_H
#include "layout_support.h"
#include "playercharacter_actor_decls.h"
#include "../../../include/Character.h"
class Animation;
class BGSNote;
struct Biped;
class PlayerCharacter : public Character
{
  public:
    enum ModifierGroup
    {
        TEMPORARY = 0,
        SCRIPTS = 1,
        DAMAGE = 2
    };
    unsigned char layoutPadding1C8[0x3e];
    bool unk206;
    unsigned char pad207[0x3d];
    float ActorValueModifierData[77];  // +0x244
    float m_afScriptModifiers[77];     // +0x378
    float ActorValueState;             // +0x4AC
    float ActorValueData[77];          // +0x4B0
    unsigned char layoutPadding5E4[104];
    bool bThirdPerson;  // +0x64C
    unsigned char layoutPadding64D[51];
    unsigned char m_ucValueAt680;  // +0x680
    unsigned char layoutPadding681[0xf];
    void* unk690;
    unsigned char pad694[0x24];
    TESQuest* m_pCurrentQuest;                          // +0x6B8
    BSSimpleList<BGSQuestObjective*> m_kObjectiveList;  // +0x6BC
    unsigned char layoutPadding6C4[0x30];
    void* unk6f4;
    unsigned char pad6f8[0xc0];
    unsigned char m_ucByteAtOffset7B8;  // +0x7B8
    unsigned char layoutPadding7B9[3];
    bool m_bHasPerks;  // +0x7BC
    unsigned char layoutPadding7BD[191];
    BSSimpleList<PerkForm*> Perks;                             // +0x87C
    BSSimpleList<BGSEntryPointPerkEntry*> m_kEntryPointPerks[74];  // +0x884
    BSSimpleList<PerkForm*> m_kCompanionPerks;                 // +0xAD4
    unsigned char layoutPaddingADC[648];
    ActorCombatGroup* m_pCombatData;  // +0xD64
    unsigned char layoutPaddingD68[232];
    void SetActionGroupFlags(unsigned short group, ACTION_FLAGS flags);
    void ResetActorValueModifiers();
    ActorCombatGroup* GetCombatGroup();
    Animation* GetAnimation(bool firstPerson);
    float GetActorValueModifierAmount(ModifierGroup modifier, ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index actorValue);
public:
    void SetUnderAIControl(bool);
public:
    void UpdateCameraMode();
public:
    ::Animation *GetAnimation(bool) const;
public:
    ::Biped *FUN_00950b00(bool);
public:
    bool HasNote(::BGSNote *);
};
#endif

#endif
