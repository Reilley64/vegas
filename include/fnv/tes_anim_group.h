#ifndef FNV_TES_ANIM_GROUP_H
#define FNV_TES_ANIM_GROUP_H

// TESAnimGroup: the animation group that a controller sequence carries, with
// its packed type word, its key times, its speed and its sound entries.
//
// This is the one shared declaration of the class. It declares the fields,
// the destructor and the members that build/units.json gives an address under
// the class's name. The header has no body: every member except the
// destructor is defined by src/fallout_shared/tesanimgroup.cpp, the unit that
// holds its function row.
// docs/shared-tesanimgroup.md has the evidence for each field and the rule
// for moving a unit onto this header.
//
// The including unit declares these first, because the tree still holds many
// private copies of each and this header cannot declare them again:
//   - NiPoint3, complete, 12 bytes with alignment 4;
//   - ANIM_GROUP_ENUM, ANIM_GROUP_MOVE_ENUM and ANIM_GROUP_WEAPON_ENUM,
//     complete, 4 bytes each.
// The assertions after the class fail the build of a unit whose NiPoint3 gives
// the class another layout, or whose enumeration has another size and so
// gives the members that take or return it another signature.
#include "fnv/ni_ref_object.h"

class NiControllerSequence;
class TESSound;

// Public JohnnyGuitar BSEnums.hpp declaration, adapted to C++03 enum syntax.
struct _AnimationGroupActionType
{
    enum Type
    {
        START_STOP,
        LOOP,
        SPECIAL_IDLE,
        EQUIP,
        UNEQUIP,
        ATTACK,
        ATTACK_POWER,
        ATTACK_THROW,
        ATTACK_THROW_ATTACH,
        ATTACK_SPIN,
        COUNT
    };
};
typedef _AnimationGroupActionType::Type ANIM_GROUP_ACTION_TYPE;
class TESAnimGroup : public NiRefObject
{
  public:
    // Declared and not bound: no function row carries this name. The recipe
    // has the body at 0x005f22d0 under a stand-in class.
    virtual ~TESAnimGroup();
    struct AnimGroupSound
    {
        float fTime;
        union
        {
            unsigned char ucVolume;
            unsigned char eType;
        };
        union
        {
            float fCurrentSpeed;
            unsigned int uiEnumData;
        };
        TESSound* SoundAssetTmp;
    };
    unsigned char m_ucSectionPriorities[8];
    unsigned short sType;
    unsigned int frameCount;
    float* times;
    NiPoint3 speed;
    char m_cByteAfterSpeed;
    unsigned char m_ucBlendCount, m_ucBlendInCount, m_ucBlendOutCount, m_ucDecal;
    const char* pParentName;
    unsigned int m_uiSoundEntryCount;
    AnimGroupSound* sounds;
    // Owned by src/fallout_shared/tesanimgroup.cpp.
    static unsigned short AnimGroup(ANIM_GROUP_MOVE_ENUM, ANIM_GROUP_WEAPON_ENUM, ANIM_GROUP_ENUM, bool); // 0x005f2370
    static ANIM_GROUP_MOVE_ENUM GetMoveType(unsigned short);       // 0x005f23c0
    static ANIM_GROUP_ENUM GetType(unsigned short);                // 0x005f2440
    ANIM_GROUP_ENUM GetType() const;                               // 0x005f2420
    static bool IsActionTypeValid(ANIM_GROUP_ACTION_TYPE);         // 0x005f25a0
    static bool IsActionTypeValid(unsigned short);                 // 0x005f2540
    static bool IsAimAnimation(unsigned short);                    // 0x005f2630
    static bool IsValidAnimationGroup(ANIM_GROUP_ACTION_TYPE);     // 0x005f26b0
    static bool IsValidAnimationGroup(unsigned short);             // 0x005f2670
    bool IsJumpAnimation() const;                                  // 0x005f4d60
    float GetAnimationSpeed() const;                               // 0x005f4c70
    static char* FindNextLine(char*);                              // 0x005f3870
    void SetSoundsFromSequence(NiControllerSequence*);             // 0x005f4d00
};

// The including unit supplies NiPoint3 and the three enumerations. With a
// NiPoint3 of 12 bytes and alignment 4 the class is 88 bytes on every build
// target, which is what the owning unit's compiler measures on windows-x64.
// The offsets of the first three fields differ between build targets, so no
// body may reach a field by a fixed offset.
static_assert(sizeof(NiPoint3) == 12 && alignof(NiPoint3) == 4);
static_assert(sizeof(ANIM_GROUP_ENUM) == 4);
static_assert(sizeof(ANIM_GROUP_MOVE_ENUM) == 4);
static_assert(sizeof(ANIM_GROUP_WEAPON_ENUM) == 4);
static_assert(sizeof(TESAnimGroup) == 88 && alignof(TESAnimGroup) == 8);
static_assert(sizeof(TESAnimGroup::AnimGroupSound) == 24);

#endif
