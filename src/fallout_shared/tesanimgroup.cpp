// fallout_shared/tesanimgroup.cpp: TESAnimGroup, BSAnimGroupSequence, TESAnimGroupDestructionView, Holder (35 functions)

#include <new>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FOPipboyManager.h"
#include "fnv/decl/FUN_00495f30_shell.h"
#include "fnv/decl/FUN_005f29f0_Class.h"
#include "fnv/decl/FUN_005f2a30_Class.h"
#include "fnv/decl/FUN_005f2a70_cls.h"
#include "fnv/decl/FUN_005f2ac0_cls.h"
#include "fnv/decl/FUN_005f2b20_Class.h"
#include "fnv/decl/FUN_005f4b70_Class.h"
#include "fnv/decl/FUN_005f4b90_Class.h"
#include "fnv/decl/FUN_005f4bd0_class.h"
#include "fnv/decl/FUN_005f4c00_cls.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008bf4e0_cls.h"
#include "fnv/decl/FUN_00a307c0_cls.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S7f.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/sad8050__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_005f3000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_01197000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011c3000.h"
#include "tesanimgroup_types.h"
#include "tesanimgroup_sequence_types.h"

// Combines powerArmor, move, weapon and group into a packed 16-bit animation group value via bit shifts.
// @fnv 0x005f2370
unsigned short TESAnimGroup::AnimGroup(ANIM_GROUP_MOVE_ENUM move, ANIM_GROUP_WEAPON_ENUM weapon, ANIM_GROUP_ENUM group,
                                       bool powerArmor)
{
    return (powerArmor << 15) + (move << 12) + (weapon << 8) + group;
}

// @fnv 0x005f23c0
ANIM_GROUP_MOVE_ENUM TESAnimGroup::GetMoveType(unsigned short group)
{
    return static_cast<ANIM_GROUP_MOVE_ENUM>((group & 0x7000) >> 12);
}

// @fnv 0x005f2440
ANIM_GROUP_ENUM TESAnimGroup::GetType(unsigned short group)
{
    return static_cast<ANIM_GROUP_ENUM>(group & 0xFF);
}

// @fnv 0x005f2420
ANIM_GROUP_ENUM TESAnimGroup::GetType() const
{
    return GetType(sType);
}

// Returns true when the animation group action type is one of the attack variants, false otherwise.
// @fnv 0x005f25a0
bool TESAnimGroup::IsActionTypeValid(ANIM_GROUP_ACTION_TYPE aeActionType)
{
    switch (aeActionType)
    {
    case _AnimationGroupActionType::ATTACK:
    case _AnimationGroupActionType::ATTACK_POWER:
    case _AnimationGroupActionType::ATTACK_THROW:
    case _AnimationGroupActionType::ATTACK_THROW_ATTACH:
    case _AnimationGroupActionType::ATTACK_SPIN:
        return true;
    default:
        return false;
    }
}

// Returns true if group is not ANIM_GROUP_NONE and its type falls between ANIM_GROUP_AIM and ANIM_GROUP_AIM_IS_DOWN.
// @fnv 0x005f2630
bool TESAnimGroup::IsAimAnimation(unsigned short group)
{
    if (group == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    ANIM_GROUP_ENUM type = GetType(group);
    if (type >= ANIM_GROUP_ENUM_ANIM_GROUP_AIM && type <= ANIM_GROUP_ENUM_ANIM_GROUP_AIM_IS_DOWN)
        return true;
    return false;
}

// @fnv 0x005f26b0
bool TESAnimGroup::IsValidAnimationGroup(ANIM_GROUP_ACTION_TYPE type)
{
    return type == _AnimationGroupActionType::ATTACK_POWER;
}

// Returns true if the animation group type is one of the jump-loop variants, false otherwise.
// @fnv 0x005f4d60
bool TESAnimGroup::IsJumpAnimation() const
{
    switch (GetType(sType))
    {
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_FORWARD:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_BACKWARD:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_LEFT:
    case ANIM_GROUP_ENUM_ANIM_GROUP_JUMP_LOOP_RIGHT:
        return true;
    default:
        return false;
    }
}

// @fnv 0x005f4c70
float TESAnimGroup::GetAnimationSpeed() const
{
    return reinterpret_cast<::NiPoint3 *>((void *)&(speed))->ComputeMagnitude();
}

// @fnv 0x005f3870
char* TESAnimGroup::FindNextLine(char* pcText)
{
    pcText = strchr(pcText, '\n');
    while (pcText && *pcText && (*pcText == '\r' || *pcText == '\n'))
        ++pcText;
    if (pcText && *pcText)
        return pcText;
    return 0;
}

// @fnv 0x0048f7f0
TESAnimGroup* BSAnimGroupSequence::GetAnimGroup() const
{
    return m_spAnimGroup;
}

// Returns false for ANIM_GROUP_ENUM_ANIM_GROUP_NONE, otherwise recurses on the action of the group's type entry in DAT_011977e4.
// @fnv 0x005f2670
bool TESAnimGroup::IsValidAnimationGroup(unsigned short group)
{
    if (group == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    return IsValidAnimationGroup(DAT_011977e4[GetType(group)].action);
}

// @fnv 0x005f2540
bool TESAnimGroup::IsActionTypeValid(unsigned short group)
{
    ANIM_GROUP_ENUM type = GetType(group);
    if (type == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return false;
    switch (type)
    {
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_UP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_DOWN:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS_UP:
    case ANIM_GROUP_ENUM_ANIM_GROUP_ATTACK_LOOP_IS_DOWN:
        return true;
    }
    return IsActionTypeValid(DAT_011977e4[type].action);
}

// @fnv 0x005f4d00
void TESAnimGroup::SetSoundsFromSequence(NiControllerSequence* sequence)
{
    BSAnimGroupSequence* animSequence = static_cast<BSAnimGroupSequence*>(sequence);
    for (int i = 0; i < 8; ++i)
    {
        if (DAT_01199bcc[i])
            m_ucSectionPriorities[i] = animSequence->GetPriority(DAT_01199bcc[i], 0);
    }
}

struct FUN_0047d3b0_shell : public TESAnimGroup
{
    unsigned short FUN_0047d3b0();
};

// @fnv 0x0047d3b0
unsigned short FUN_0047d3b0_shell::FUN_0047d3b0()
{
    return sType;
}

struct NiMemObjectAllocation
{
};

struct TESAnimGroupDestructionView : public TESAnimGroup
{
    void FUN_005f22d0();
    void* FUN_005f22a0(unsigned int flags);
};

struct FUN_005f3740_shell : public TESAnimGroup
{
    bool FUN_005f3740(unsigned int, float);
};

// Writes afValue into the times array at aiIndex, returning false if times is null or aiIndex is out of range.
// @fnv 0x005f3740
bool FUN_005f3740_shell::FUN_005f3740(unsigned int aiIndex, float afValue)
{
    if (!times)
        return false;
    if (aiIndex >= frameCount)
        return false;
    times[aiIndex] = afValue;
    return true;
}

struct FUN_005f3780_shell : public TESAnimGroup
{
    float FUN_005f3780(int);
};


struct AnimGroupInfo_011977d8
{
    const char* name;
    char pad[0x20];
};

// Validates groupAction against frameCount, warns on out-of-range or NaN times, and returns times[groupAction] or 0.0f.
// @fnv 0x005f3780
float FUN_005f3780_shell::FUN_005f3780(int groupAction)
{
    if (groupAction < 0)
    {
        ::FUN_005b5e40();
        return 0.0f;
    }
    if ((unsigned int)groupAction >= frameCount)
    {
        ::FUN_005b5e40();
        return 0.0f;
    }
    if (times)
    {
        if (std::isnan(times[groupAction]))
        {
            ::FUN_005b5e40();
            return 0.0f;
        }
        return times[groupAction];
    }
    return 0.0f;
}

template <typename T> unsigned int __cdecl BSStringLength(const T* str);



// @fnv 0x005f38d0
void __cdecl FUN_005f38d0(const char* apModelName, unsigned int* aeMove, unsigned int* aeWeapon, bool* abPowerArmor)
{
    unsigned int n;
    const char* plastSlash = ((const char *)(std::strrchr((char *)(apModelName), '\\')));
    *abPowerArmor = false;
    *aeMove = 0;
    *aeWeapon = 0;
    if (plastSlash)
    {
        plastSlash = plastSlash + 1;
        if (fnv::crt::strnicmp(plastSlash, "PA", ::FUN_0044a670("PA")) == 0)
        {
            *abPowerArmor = true;
            plastSlash += ::FUN_0044a670("PA");
        }
        for (n = 1; n < 4; ++n)
        {
            if (fnv::crt::strnicmp(plastSlash, DAT_01197794[n], ::FUN_0044a670(DAT_01197794[n])) == 0)
            {
                *aeMove = n;
                plastSlash += ::FUN_0044a670(DAT_01197794[n]);
                break;
            }
        }
        for (n = 1; n < 12; ++n)
        {
            if (fnv::crt::strnicmp(plastSlash, DAT_011977a4[n], ::FUN_0044a670(DAT_011977a4[n])) == 0)
            {
                *aeWeapon = n;
                break;
            }
        }
    }
}

struct FUN_005f4c40_shell : public TESAnimGroup
{
    void SetSpeed(NiPoint3*);
};

// Stores the NiPoint3 pointed to by apSpeed into the speed field.
// @fnv 0x005f4c40
void FUN_005f4c40_shell::SetSpeed(NiPoint3* apSpeed)
{
    speed = *apSpeed;
}

struct UShortArg
{
    unsigned short v;
};

// @fnv 0x005f2450
void SetAnimGroupType(TESAnimGroup* self, UShortArg type)
{
    self->sType = type.v;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (!*PTR_s_Start_01199a50[i][*(int*)&DAT_011977e4[TESAnimGroup::GetType(type.v)]])
            break;
    }
    self->frameCount = i;
    if (self->times)
        delete self->times;
    if (self->frameCount)
    {
        self->times = new float[self->frameCount];
        ::FUN_00403d30(self->times, 0, self->frameCount * sizeof(float));
    }
    else
    {
        self->times = 0;
    }
}

extern int DAT_010484e8;


struct EBase
{
    virtual ~EBase();
};

struct FUN_005f22d0 : EBase
{
    char pad18[0x18 - sizeof(EBase)];
    void* times;
    char pad34[0x34 - 0x18 - sizeof(void*)];
    int m_uiSoundEntryCount;
    void* sounds;

    virtual ~FUN_005f22d0();
};
// Calls FUN_005f22d0, frees this via NiMemObjectAllocation::operator delete when flags has bit 1 set, and returns this.
// @fnv 0x005f22a0
void* TESAnimGroupDestructionView::FUN_005f22a0(unsigned int flags)
{
    reinterpret_cast<::FUN_005f22d0 *>((this))->FUN_005f22d0::~FUN_005f22d0();
    if (flags & 1)
        ::FUN_00aa1460(this, sizeof(TESAnimGroup));
    return this;
}

// @fnv 0x005f22d0
FUN_005f22d0::~FUN_005f22d0()
{
    void* p = times;
    ::FUN_00401030(p);
    times = 0;
    ::FUN_00401030(sounds);
    sounds = 0;
    m_uiSoundEntryCount = 0;
}

struct FUN_005f23a0_shell : TESAnimGroup
{
    ANIM_GROUP_MOVE_ENUM GetMoveAnimGroup();
};

// @fnv 0x005f23a0
ANIM_GROUP_MOVE_ENUM FUN_005f23a0_shell::GetMoveAnimGroup()
{
    return TESAnimGroup::GetMoveType(this->sType);
}


struct FUN_005f23e0_shell
{
    unsigned short FUN_005f23e0();
};

// @fnv 0x005f23e0
unsigned short FUN_005f23e0_shell::FUN_005f23e0()
{
    return ((unsigned short)(::fnv_005f2400::FUN_005f2400(*((unsigned short*)((char*)this + 0x10)))));
}

namespace fnv_005f2400 {
// @fnv 0x005f2400
int FUN_005f2400(unsigned short ausValue)
{
    return (ausValue & 0xf00) >> 8;
}
}  // namespace fnv_005f2400

// @fnv 0x005f2610
bool __cdecl IsNine(int aiValue)
{
    if (aiValue == 9)
    {
        return true;
    }
    return false;
}

// @fnv 0x005f2700
bool IsValidCharCode(int aiCharCode)
{
    if (aiCharCode >= 0xb1 && aiCharCode <= 0xc7)
        return true;
    return false;
}


// Returns false for anim group 0xff, otherwise checks whether the group's type is an iron sights action.
// @fnv 0x005f2720
bool IsIronSightsAnimGroup(unsigned short usAnimGroup)
{
    if (usAnimGroup == 0xff)
        return false;
    return ::FUN_005f2750((*(int *)&(const ::ANIM_GROUP_ENUM &)(TESAnimGroup::GetType(usAnimGroup))));
}

int __cdecl GetType(unsigned short);
bool __cdecl IsNine(int);

// Returns false for type 0xff, otherwise looks up the type's entry and returns the result of IsNine on its stored value.
// @fnv 0x005f25d0
bool FUN_005f25d0(unsigned short ausType)
{
    if (ausType == 0xff)
        return false;
    return IsNine(*(int*)(GetType(ausType) * 0x24 + 0x11977e4));
}

struct TESSound;
struct SoundPlaybackEntry
{
    float fTime;
    unsigned char m_bFlag;
    char _pad_5[3];
    float fCurrentSpeed;
    TESSound* SoundAssetTmp;
};
struct FUN_005f2820_shell : public TESAnimGroup
{
    void FUN_005f2820(unsigned int);
};


// Resizes the sounds array to count entries, copying existing entries and initialising new ones with default time, type and volume values.
// @fnv 0x005f2820
void FUN_005f2820_shell::FUN_005f2820(unsigned int count)
{
    unsigned int oldSoundCount = m_uiSoundEntryCount;
    m_uiSoundEntryCount = count;
    if (!m_uiSoundEntryCount)
    {
        ::FUN_00401030(sounds);
        sounds = 0;
        return;
    }
    if (oldSoundCount)
    {
        SoundPlaybackEntry* sounds_old = (SoundPlaybackEntry*)::FUN_00401000(oldSoundCount * 16);
        __memcpy(sounds_old, sounds, oldSoundCount * 16);
        sounds = (AnimGroupSound*)::Reallocate(sounds, m_uiSoundEntryCount * 16);
        unsigned int n = oldSoundCount;
        if (oldSoundCount > m_uiSoundEntryCount)
            n = m_uiSoundEntryCount;
        __memcpy(sounds, sounds_old, n * 16);
        ::FUN_00401030(sounds_old);
        for (unsigned int i = oldSoundCount; i < m_uiSoundEntryCount; i++)
        {
            sounds[i].SoundAssetTmp = 0;
            sounds[i].fTime = 0.0f;
            sounds[i].eType = 0xfa;
            sounds[i].fCurrentSpeed = 1.0f;
        }
    }
    else
    {
        sounds = (AnimGroupSound*)::FUN_00401000(m_uiSoundEntryCount * 16);
        for (unsigned int i = 0; i < m_uiSoundEntryCount; i++)
        {
            sounds[i].SoundAssetTmp = 0;
            sounds[i].fTime = 0.0f;
            sounds[i].eType = 0xfa;
            sounds[i].fCurrentSpeed = 1.0f;
        }
    }
}

int __cdecl GetType(unsigned short);
// Returns true when GetType(a) is 0, 1 or 0xAA, otherwise false.
// @fnv 0x005f4cc0
bool __cdecl FUN_005f4cc0(unsigned short ausType)
{
    switch (GetType(ausType))
    {
    case 0:
    case 1:
    case 0xAA:
        return true;
    default:
        return false;
    }
}

namespace fnv_005f3a20 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiStream;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESSound;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob36
{
    char b[36];
};
struct TimedTextEntry
{
    void SetTime(float);
    void SetText(void*);
    TimedTextEntry* Copy();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void RegisterStreamables(NiStream*);
    void* __vecDelDtor(unsigned int);
    float m_fTime;
    NiFixedString m_kText;
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};

template <class T> unsigned int BSStringLength(const T* str);
char* strchr(char* str, int ch);

struct NiFixedStringEx : NiFixedString
{
    NiFixedStringEx(const NiFixedString& kString);
    ~NiFixedStringEx();
    operator const char*() const;
};

struct NiTextKeyExtraData
{
};

struct NiControllerSequenceEx : NiControllerSequence
{
    NiTextKeyExtraData* GetTextKeys() const;
};

enum ANIM_ENUM
{
};

struct TESSound
{
};

struct BSAudio
{
};

struct TESDataHandler
{
};

struct TESFile
{
};

struct TESAnimGroupEx : TESAnimGroup
{
    TESAnimGroupEx(unsigned short sGroup);
};


struct AnimGroupInfo
{
    const char* pName;
    int iUnk04;
    int iLoopType;
    int iSequenceType;
    int m_iPadding[5];
};

extern const char* DAT_01199b50[];

// Parses a controller sequence's text keys to build a TESAnimGroupEx, setting parent, morph, blend, decal and sound data and warning on bad notes.
// @fnv 0x005f3a20
TESAnimGroup* FUN_005f3a20(NiControllerSequenceEx* apSequence, const char* apModelName)
{
    ANIM_GROUP_ENUM m;
    char message[260];
    bool bshowWarning = false;
    TESAnimGroupEx* panimGroup = 0;
    ANIM_GROUP_ENUM lastGroup = (ANIM_GROUP_ENUM)0xff;
    unsigned int iactionIndex = 0;
    bool bpowerArmor = false;
    ANIM_GROUP_MOVE_ENUM eanimMove = ANIM_GROUP_MOVE_ENUM_AGM_NONE;
    ANIM_GROUP_WEAPON_ENUM eanimWeapon = ANIM_GROUP_WEAPON_ENUM_AGW_NONE;
    const char* plastSlash = ((const char *)(std::strrchr((char *)(apModelName), '\\')));
    ::FUN_0043b2b0(true);
    const char* paccumName = (*(const ::fnv_005f3a20::NiFixedStringEx *)(reinterpret_cast<::FUN_006c9900_shell *>((void *)(apSequence))->FUN_006c9900()));
    int iaccumIndex = -1;
    int inonAccumIndex = -1;
    char cnonAccumName[64];
    ::FUN_00406d00(cnonAccumName, 64, "%s NonAccum", paccumName);
    unsigned int n;
    for (n = 0; n < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(apSequence))->FUN_0084e3a0())); n++)
    {
        char ptestName[260];
        reinterpret_cast<::FUN_00a307c0_cls *>((apSequence))->GetEntryText(n, ptestName);
        if (ptestName[0])
        {
            if (!::FUN_00404dc0(paccumName, ptestName))
                iaccumIndex = n;
            else if (!::FUN_00404dc0(cnonAccumName, ptestName))
                inonAccumIndex = n;
        }
        else
        {
            ::FUN_005b5e40();
        }
        if (iaccumIndex != -1 && inonAccumIndex != -1)
        {
            reinterpret_cast<::FUN_005f4bd0_class *>((apSequence))->SetEntryByte(inonAccumIndex, ((bool)(reinterpret_cast<::FUN_005f4c00_cls *>((apSequence))->GetEntryByte0d(iaccumIndex))));
            break;
        }
    }

    ::FUN_005f38d0(apModelName, (unsigned int *)&(eanimMove), (unsigned int *)&(eanimWeapon), (bool *)&(bpowerArmor));

    if (apSequence && apSequence->GetTextKeys())
    {
        unsigned int numKeys;
        char plocalKeyText[260];
        TimedTextEntry* key = ((::fnv_005f3a20::TimedTextEntry *)(reinterpret_cast<::FUN_00495f30_shell *>((void *)(apSequence->GetTextKeys()))->FUN_00495f30((int *)&(numKeys))));
        for (n = 0; n < numKeys; n++)
        {
            NiFixedStringEx keyText(*(NiFixedString*)((void *)(reinterpret_cast<::BaseProcess *>(&(key[n]))->GetCurrentProcessData())));
            float time = reinterpret_cast<::CombatTargetTimestamp *>(&(key[n]))->FUN_006a7f50();
            if (!((bool)(reinterpret_cast<::NiFixedString *>((void *)&(keyText))->IsNotEmpty())))
            {
                ::FUN_005b5e40();
                bshowWarning = true;
            }
            else if (!fnv::crt::strnicmp(keyText, "prn:", 4))
            {
                if (((const char*)keyText)[4] != ' ')
                    reinterpret_cast<::BGSCameraPath *>((panimGroup))->AssignParentPath((::BGSCameraPath *)(keyText + 4));
                else
                    reinterpret_cast<::BGSCameraPath *>((panimGroup))->AssignParentPath((::BGSCameraPath *)(keyText + 5));
            }
            else
            {
                ::TaskQueueInterface::CopyStringToBuffer(plocalKeyText, 260, keyText);
                char* ptoken = plocalKeyText;
                char* pfirstLineOfKeyText = plocalKeyText;
                while (ptoken && ::FUN_0044a670(ptoken))
                {
                    if (*ptoken == '\r')
                        ptoken = TESAnimGroup::FindNextLine(ptoken);
                    if (!fnv::crt::strnicmp(ptoken, ::g_kTextKeyA, ::FUN_0044a670(::g_kTextKeyA)))
                    {
                        if (!((char)(reinterpret_cast<::FOPipboyManager *>((panimGroup))->IsUnk28Set())))
                            reinterpret_cast<::MiddleHighProcess *>((panimGroup))->FUN_00929260(ptoken[2]);
                    }
                    else if (!fnv::crt::strnicmp(ptoken, "BlendIn:", 8))
                    {
                        if (ptoken[8] != ' ')
                            reinterpret_cast<::S7f *>((panimGroup))->SetValue(std::atoi(ptoken + 8));
                        else
                            reinterpret_cast<::S7f *>((panimGroup))->SetValue(std::atoi(ptoken + 9));
                    }
                    else if (!fnv::crt::strnicmp(ptoken, "BlendOut:", 9))
                    {
                        if (ptoken[9] != ' ')
                            reinterpret_cast<::FUN_005f4b90_Class *>((panimGroup))->SetByteAtOffset2B(std::atoi(ptoken + 9));
                        else
                            reinterpret_cast<::FUN_005f4b90_Class *>((panimGroup))->SetByteAtOffset2B(std::atoi(ptoken + 10));
                    }
                    else if (!fnv::crt::strnicmp(ptoken, "Blend:", 6))
                    {
                        if (ptoken[6] != ' ')
                            reinterpret_cast<::FUN_005f4b70_Class *>((panimGroup))->FUN_005f4b70(std::atoi(ptoken + 6));
                        else
                            reinterpret_cast<::FUN_005f4b70_Class *>((panimGroup))->FUN_005f4b70(std::atoi(ptoken + 7));
                    }
                    else if (!fnv::crt::strnicmp(ptoken, "Decal:", 6))
                    {
                        if (ptoken[6] != ' ')
                            reinterpret_cast<::FUN_008bf4e0_cls *>((panimGroup))->set(std::atoi(ptoken + 6));
                        else
                            reinterpret_cast<::FUN_008bf4e0_cls *>((panimGroup))->set(std::atoi(ptoken + 7));
                    }
                    else if (!fnv::crt::strnicmp(ptoken, "Sound:", ::FUN_0044a670("Sound:")) ||
                             !fnv::crt::strnicmp(ptoken, "Enum:", ::FUN_0044a670("Enum:")))
                    {
                        bool benum = false;
                        if (!fnv::crt::strnicmp(ptoken, "Enum:", ::FUN_0044a670("Enum:")))
                            benum = true;
                        if (panimGroup)
                        {
                            char* cr2 = strchr(ptoken, '\r');
                            if (cr2)
                                *cr2 = 0;
                            const char* soundID = ptoken;
                            if (benum)
                                soundID += ::FUN_0044a670("Enum: ");
                            else
                                soundID += ::FUN_0044a670("Sound: ");
                            ::TaskQueueInterface::CopyStringToBuffer(message, 260, soundID);
                            char* vol = 0;
                            char* pitch = 0;
                            char* cr = strchr(message, ',');
                            if (cr)
                            {
                                vol = cr + 1;
                            }
                            else
                            {
                                cr = strchr(message, ' ');
                                if (cr)
                                    vol = cr + 1;
                            }
                            if (cr)
                                *cr = 0;
                            if (vol)
                            {
                                while (*vol == ' ' && *vol != '\r')
                                    vol++;
                                cr = strchr(vol, ',');
                                if (cr)
                                {
                                    pitch = cr + 1;
                                }
                                else
                                {
                                    cr = strchr(vol, ' ');
                                    if (cr)
                                        pitch = cr + 1;
                                }
                                if (cr)
                                    *cr = 0;
                            }
                            bool bbadNote = false;
                            if (benum)
                            {
                                ANIM_ENUM etype = (ANIM_ENUM)0;
                                while (etype < 31 && ::FUN_00404dc0(DAT_01199b50[etype], message))
                                    etype = (ANIM_ENUM)(etype + 1);
                                if (etype < 31)
                                {
                                    unsigned int iElementIndex = ((ptoken - pfirstLineOfKeyText) << 8) | n;
                                    unsigned int m_uiSoundEntryCount = ((unsigned int)(reinterpret_cast<::BGSCameraPath *>((panimGroup))->GetPrevPath()));
                                    reinterpret_cast<::FUN_005f2820_shell *>((panimGroup))->FUN_005f2820(m_uiSoundEntryCount + 1);
                                    reinterpret_cast<::FUN_005f29f0_Class *>((panimGroup))->SetValueAtIndex(m_uiSoundEntryCount, time);
                                    reinterpret_cast<::FUN_005f2a70_cls *>((panimGroup))->SetRecordFlagAndValue(m_uiSoundEntryCount, (*(unsigned char *)&(etype)), iElementIndex);
                                }
                                else
                                {
                                    bbadNote = true;
                                }
                            }
                            else
                            {
                                TESSound* openSound = ((::fnv_005f3a20::TESSound *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_005f3a20::TESDataHandler * *>(&::g_dataHandler))))->GetSoundByEditorID(message)));
                                if (openSound)
                                {
                                    reinterpret_cast<::sad8050::Owner *>((((::fnv_005f3a20::BSAudio *)(::FUN_00453a70()))))->ForwardToManager(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((openSound))->FUN_0084e3a0())), false);
                                    unsigned int m_uiSoundEntryCount = ((unsigned int)(reinterpret_cast<::BGSCameraPath *>((panimGroup))->GetPrevPath()));
                                    reinterpret_cast<::FUN_005f2820_shell *>((panimGroup))->FUN_005f2820(m_uiSoundEntryCount + 1);
                                    reinterpret_cast<::FUN_005f29f0_Class *>((panimGroup))->SetValueAtIndex(m_uiSoundEntryCount, time);
                                    reinterpret_cast<::FUN_005f2a30_Class *>((panimGroup))->SetEntryValue(m_uiSoundEntryCount, (std::uintptr_t)(openSound));
                                    if (vol && *vol)
                                        reinterpret_cast<::FUN_005f2ac0_cls *>((panimGroup))->SetRecordValue(m_uiSoundEntryCount, std::atof(vol));
                                    if (pitch)
                                        reinterpret_cast<::FUN_005f2b20_Class *>((panimGroup))->SetEntryFloat(m_uiSoundEntryCount, std::atof(pitch));
                                }
                                else
                                {
                                    bbadNote = true;
                                }
                            }
                            if (bbadNote)
                            {
                                ::FUN_005b5e40();
                                bshowWarning = true;
                            }
                            if (cr2)
                                *cr2 = '\r';
                        }
                    }
                    else
                    {
                        for (m = (ANIM_GROUP_ENUM)0; m < 245; m = (ANIM_GROUP_ENUM)(m + 1))
                        {
                            if (lastGroup != 0xff)
                                m = lastGroup;
                            if (!::FUN_00404dc0((*(const ::fnv_005f3a20::NiFixedStringEx *)(reinterpret_cast<::TESTopicInfoData *>((void *)(apSequence))->GetLinkToList())), (*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].pName))
                            {
                                lastGroup = m;
                                ANIM_GROUP_ACTION action = (ANIM_GROUP_ACTION)(*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].m_iPadding[iactionIndex];
                                if (action == -1)
                                    break;
                                if (m == 2 && iactionIndex == 1 &&
                                    !fnv::crt::strnicmp(ptoken, ::PTR_s_Start_01199a50[3][(*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType],
                                                ::FUN_0044a670(::PTR_s_Start_01199a50[3][(*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType])))
                                    iactionIndex = action = (ANIM_GROUP_ACTION)3;
                                if ((*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType == 5 && iactionIndex == 2 &&
                                    !fnv::crt::strnicmp(ptoken, ::PTR_s_Start_01199a50[3][(*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType],
                                                ::FUN_0044a670(::PTR_s_Start_01199a50[3][(*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType])))
                                    iactionIndex = action = (ANIM_GROUP_ACTION)3;
                                if (!fnv::crt::strnicmp(ptoken, ::PTR_s_Start_01199a50[action][(*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType],
                                                ::FUN_0044a670(::PTR_s_Start_01199a50[action][(*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType])))
                                {
                                    if (!panimGroup)
                                    {
                                        if (m == 2)
                                            panimGroup = new TESAnimGroupEx((unsigned short)m);
                                        else
                                            panimGroup = new TESAnimGroupEx(
                                                TESAnimGroup::AnimGroup(eanimMove, eanimWeapon, m, bpowerArmor));
                                    }
                                    if (time > -1.0)
                                        reinterpret_cast<::FUN_005f3740_shell *>((panimGroup))->FUN_005f3740(action, time);
                                    if ((*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType == 1 && reinterpret_cast<::ActorMover *>((void *)(apSequence))->GetCurrentMoveModeType())
                                    {
                                        if ((*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iLoopType != 1)
                                        {
                                            ::FUN_005b5e40();
                                            bshowWarning = true;
                                        }
                                    }
                                    else if ((*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].iSequenceType != 1 && !reinterpret_cast<::ActorMover *>((void *)(apSequence))->GetCurrentMoveModeType())
                                    {
                                        ::FUN_005b5e40();
                                        bshowWarning = true;
                                    }
                                    iactionIndex++;
                                    break;
                                }
                                if (iactionIndex == 5 || (*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[m].m_iPadding[iactionIndex] == -1)
                                {
                                    char* cr = strchr(ptoken, '\r');
                                    if (cr)
                                        *cr = 0;
                                    ::FUN_005b5e40();
                                    if (cr)
                                        *cr = '\r';
                                    bshowWarning = true;
                                }
                                break;
                            }
                            else if (m == lastGroup)
                            {
                                break;
                            }
                        }
                        if (m == 245)
                        {
                            ::FUN_005b5e40();
                            bshowWarning = true;
                            ptoken = 0;
                            n = numKeys;
                        }
                    }
                    if (ptoken)
                        ptoken = TESAnimGroup::FindNextLine(ptoken);
                }
            }
        }

        if (panimGroup)
        {
            panimGroup->SetSoundsFromSequence(apSequence);
            ANIM_GROUP_ACTION estartAction = (ANIM_GROUP_ACTION)0;
            ANIM_GROUP_ACTION eendAction = (ANIM_GROUP_ACTION)1;
            switch ((*reinterpret_cast<fnv_005f3a20::AnimGroupInfo (*)[]>(&::DAT_011977d8))[panimGroup->GetType()].iSequenceType)
            {
            case 7:
                eendAction = (ANIM_GROUP_ACTION)4;
                break;
            case 8:
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 9:
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 5:
                if (reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(2) < reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(1))
                    reinterpret_cast<::FUN_005f3740_shell *>((panimGroup))->FUN_005f3740(2, reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(1));
                eendAction = (ANIM_GROUP_ACTION)4;
                break;
            case 6:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            case 10:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            case 2:
                if (reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(1) < reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(0))
                    reinterpret_cast<::FUN_005f3740_shell *>((panimGroup))->FUN_005f3740(1, reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(0));
                if (reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(2) <= reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(1))
                    reinterpret_cast<::FUN_005f3740_shell *>((panimGroup))->FUN_005f3740(2, reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(3));
                eendAction = (ANIM_GROUP_ACTION)3;
                break;
            case 3:
            case 4:
                eendAction = (ANIM_GROUP_ACTION)2;
                break;
            }
            if (reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(eendAction) <= reinterpret_cast<::FUN_005f3780_shell *>((panimGroup))->FUN_005f3780(estartAction))
            {
                ::FUN_005b5e40();
                bshowWarning = true;
            }
            if (panimGroup->m_ucBlendCount && (panimGroup->m_ucBlendInCount || panimGroup->m_ucBlendOutCount))
            {
                ::FUN_005b5e40();
                bshowWarning = true;
            }
        }
    }

    ::FUN_0043b2b0(false);
    if (bshowWarning)
        ::FUN_005b5e40();
    return panimGroup;
}
}  // namespace fnv_005f3a20

struct FUN_005f26c0_cls : public TESAnimGroup
{
    bool FUN_005f26c0();
};

int __cdecl FUN_005f2440(unsigned short);

// Returns true when the animation group's sType maps to one of the codes 0x5c through 0x65, otherwise false.
// @fnv 0x005f26c0
bool FUN_005f26c0_cls::FUN_005f26c0()
{
    switch (FUN_005f2440(sType))
    {
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
        return true;
    default:
        return false;
    }
}

// FUN_005f2750: switch over a byte-coded action id; true for the listed action ids.
// @fnv 0x005f2750
bool __cdecl FUN_005f2750(int a)
{
    switch (a)
    {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x7b:
    case 0x7c:
    case 0x7d:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8d:
    case 0x8e:
    case 0x8f:
    case 0x93:
    case 0x94:
    case 0x95:
        return true;
    default:
        return false;
    }
}

struct Vec3
{
    int x;
    int y;
    int z;
};

struct Holder
{
    char pad[0x1c];
    Vec3 m_vec;
    Vec3* GetVec(Vec3* out);
};

// Copies m_vec into the out parameter and returns out.
// @fnv 0x005f4c90
Vec3* Holder::GetVec(Vec3* out)
{
    *out = m_vec;
    return out;
}

#include "generated/data/fallout_shared/tesanimgroup.inc"
