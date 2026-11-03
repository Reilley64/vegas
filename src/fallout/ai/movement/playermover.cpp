
// Fallout: New Vegas - original source reconstruction.
// Source unit: fallout/ai/movement/playermover.cpp
//
// PlayerMover extends the ActorMover base with player-specific movement
// state: a side-step vector, the current move mode, the pending turn
// direction bits and the minimum turn timer.
//
// Notes on declarations:
// - NiPoint3 carries its static ZERO (bsaudio/bsaudiodefines.h precedent);
//   the canonical task NiPoint3.h omits it, so the identical-layout local
//   declaration below stands in and the canonical header is blocked by its
//   own include guard (FNV_NIPOINT3_H).
//   minimal base below is sized to the PC subobject (0x88 bytes, pActor at
//   +0x28) as observed in the PC disassembly.
//   fallout/misc/saveload/bgsloadformbuffer.cpp declaration.

#include "fnv/decl/BSAnimGroupSequence.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_004301b0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047d3b0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0050d4a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_008bbc10_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00494390__MovementAnimation.h"
#include "fnv/decl/fnv_004994f0__FUN_004994f0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00886b30__A_00886b30.h"
#include "fnv/decl/fnv_00897910__AnimOwner.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009df8c0__FUN_009df8c0_shell.h"
#include "fnv/decl/fnv_009dfb80__FUN_009dfb80_t.h"
#include "fnv/decl/loadpath__Mover.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_008b7000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
#include "playermover_layout.h"

#define FNV_NIPOINT3_H
class NiPoint3
{
  public:
    static const NiPoint3 ZERO;
    NiPoint3 operator+(const NiPoint3&) const;
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
public:
    float ComputeMagnitude() const;
};

#include "playermover_actor.h"
#include "playermover_decls.h"

class BGSLoadGameBuffer
{
  public:
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
};

class ActorMover
{
  public:

    unsigned char layoutPadding00[0x28];
    Actor* pActor;  // +0x28
    unsigned char layoutPadding2C[0x5C];
};

class PlayerMover : public ActorMover
{
  public:
    void Revert(BGSLoadFormBuffer* apBuffer);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    void SetMovementValue(float fTimeSinceScaleStart);
    void Update(float fTimeSinceScaleStart);
    void SetMoverMode(unsigned int auMode);
    void UpdatePlayerStatus(unsigned int auMode, bool abSet);
    void SetSideVec(const NiPoint3& arSideVec);
    void ClearMode(unsigned int auMode);

    NiPoint3 m_kSideVec;    // +0x88
    unsigned int ByteAndFlagState;  // +0x94
    unsigned int m_uiMode;  // +0x98
    float m_fValue;         // +0x9C
};

// @fnv 0x009ea6a0
void PlayerMover::Revert(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::fnv_009dfb80::FUN_009dfb80_t *>(this)->ResetPathingState(apBuffer);
    m_kSideVec = NiPoint3::ZERO;
    ByteAndFlagState = 0;
    m_fValue = -1.0f;
    m_uiMode = 0;
}

// @fnv 0x009ea610
void PlayerMover::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::loadpath::Mover *>(this)->FUN_009df3d0((::loadpath::Buffer *)(apBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_kSideVec), sizeof(m_kSideVec));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ByteAndFlagState), sizeof(ByteAndFlagState));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_uiMode), sizeof(m_uiMode));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fValue), sizeof(m_fValue));
}

// @fnv 0x009ea680
void PlayerMover::InitLoadGame(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::fnv_009df8c0::FUN_009df8c0_shell *>(this)->FUN_009df8c0((::fnv_009df8c0::BGSLoadFormBuffer *)(apBuffer));
}

// @fnv 0x009ea2f0
void PlayerMover::SetMovementValue(float afDelta)
{
    if (m_fValue > 0.0)
    {
        m_fValue -= afDelta;
        if (!pActor->Unk_85())
            ByteAndFlagState |= m_uiMode;
    }
}

// @fnv 0x009e9e50
void PlayerMover::Update(float fTimeSinceScaleStart)
{
    NiPoint3 delta = NiPoint3::ZERO;
    Animation* animation = ::_g_thePlayer->GetAnimation(false);
    if (!reinterpret_cast<::FUN_004eaf60_shell *>((::_g_thePlayer))->FUN_004eaf60())
    {
        Animation* firstPerson = ::_g_thePlayer->GetAnimation(true);
        if (!animation || reinterpret_cast<::FUN_004301b0_shell *>((firstPerson))->FUN_004301b0(1) == reinterpret_cast<::FUN_004301b0_shell *>((animation))->FUN_004301b0(1))
            animation = firstPerson;
    }
    if (!reinterpret_cast<::fnv_00886b30::A_00886b30 *>((::_g_thePlayer))->PlaceAtPosition((::fnv_00886b30::Pt3_00886b30 *)&(delta)))
    {
        if (animation)
        {
            if (reinterpret_cast<::FUN_0050d4a0_shell *>((::_g_thePlayer))->FUN_0050d4a0())
                reinterpret_cast<::fnv_00494390::MovementAnimation *>((animation))->GetMovement((::fnv_00494390::MotionPoint *)(::NiPoint3 *)(&delta), (::fnv_00494390::MotionActor *)(::_g_thePlayer), true, false);
            else
                reinterpret_cast<::fnv_00494390::MovementAnimation *>((animation))->GetMovement((::fnv_00494390::MotionPoint *)(::NiPoint3 *)(&delta), (::fnv_00494390::MotionActor *)(::_g_thePlayer), false, true);
        }
        struct ControllerState
        {
            bhkCharacterController* controller;
            PlayerMoverControllerState* state;
        } character;
        character.controller = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((::_g_thePlayer))->FUN_009306d0()));
        character.state = character.controller ? &character.controller->state : 0;
        if (character.state && ::FUN_008b7320((char *)(character.state)))
            delta = NiPoint3::ZERO;
        if ((ByteAndFlagState & 0xF) && !::_g_thePlayer->GetIsDying() && !reinterpret_cast<::FUN_0050d4a0_shell *>((::_g_thePlayer))->FUN_0050d4a0())
        {
            switch (::_g_thePlayer->GetAnimAction())
            {
            default:
                break;
            }
            struct MovementLengths
            {
                float sideLength;
                float deltaLength;
            } lengths;
            lengths.sideLength = reinterpret_cast<::NiPoint3 *>((void *)&(m_kSideVec))->ComputeMagnitude();
            lengths.deltaLength = reinterpret_cast<::NiPoint3 *>((void *)&(delta))->ComputeMagnitude();
            if (lengths.sideLength > 0.0 && lengths.deltaLength > 0.0 && !(ByteAndFlagState & 0x40))
            {
                float sideX = m_kSideVec.x / lengths.sideLength;
                float sideY = m_kSideVec.y / lengths.sideLength;
                delta.x = sideX * lengths.deltaLength;
                delta.y = sideY * lengths.deltaLength;
            }
        }
        if ((ByteAndFlagState & 3) && (ByteAndFlagState & 0xC) && !::_g_thePlayer->GetIsDying())
        {
            switch (reinterpret_cast<PlayerMoverProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(::_g_thePlayer)))->GetBaseTexture())))
                        ->GetKnockedState())
            {
            default:
                if (delta.y != 0.0)
                {
                    float displacement = m_kSideVec.x * fTimeSinceScaleStart * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((::_g_thePlayer))->FUN_00567400();
                    float angle = displacement / delta.y * 0.7853981852531433;
                    if (ByteAndFlagState & 4)
                        delta.x += -std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    else if (ByteAndFlagState & 8)
                        delta.x += std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    delta.y = cos(angle) * delta.y;
                }
            case 13:
            case 14:
                break;
            }
        }
    }
    if (reinterpret_cast<::FUN_0050d4a0_shell *>((::_g_thePlayer))->FUN_0050d4a0())
    {
        NiPoint3 position =
            *reinterpret_cast<NiPoint3*>(reinterpret_cast<TESTopicInfo*>(::_g_thePlayer)->GetAddTopicList()) + delta;
        ::_g_thePlayer->SetPos(&position);
    }
    else
    {
        ::_g_thePlayer->Move(fTimeSinceScaleStart, &delta, reinterpret_cast<::FUN_008846e0_shell *>((::_g_thePlayer))->GetVtbl20Result());
        struct GroundHeight
        {
            float height;
            TESObjectCELL* cell;
        } ground;
        ground.cell = reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(::_g_thePlayer)->GetTarget());
        if (ground.cell && !ground.cell->IsCellInterior())
        {
            ground.height = 0.0f;
            NiPoint3 position = *::_g_thePlayer->GetPos();
            if (reinterpret_cast<::S00546fb0_Cell *>((ground.cell))->FUN_00546fb0()->FUN_0053f180((const ::LandscapeColorData &)(position), ground.height))
            {
                if (ground.height - position.z > 32.0)
                {
                    position.z = ground.height + 32.0;
                    ::_g_thePlayer->SetPos(&position);
                }
            }
        }
    }
}

// @fnv 0x009ea3e0
void PlayerMover::SetMoverMode(unsigned int auMode)
{
    bool changed = (ByteAndFlagState & 0x400) != (auMode & 0x400);
    if (auMode & 0x30)
    {
        m_fValue = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting219))))))->f;
        m_uiMode = auMode & 0x30;
    }
    ByteAndFlagState = auMode;
    if (changed && TESAnimGroup::IsAimAnimation(reinterpret_cast<::FUN_004301b0_shell *>((::_g_thePlayer->GetAnimation(false)))->FUN_004301b0(4)))
    {
        struct AimAnimationState
        {
            ANIM_GROUP_ENUM group;
            unsigned short groupID;
            Animation* animation;
            NiControllerSequence* sequence;
        } aimState;
        aimState.group = reinterpret_cast<::FUN_008bbc10_shell *>((::_g_thePlayer))->FUN_008bbc10() ? (ANIM_GROUP_ENUM)20 : (ANIM_GROUP_ENUM)17;
        aimState.animation = ::_g_thePlayer->GetAnimation(false);
        aimState.sequence = ((::NiControllerSequence *)(reinterpret_cast<::FUN_00491040_shell *>((aimState.animation))->FUN_00491040(4)));
        aimState.groupID = reinterpret_cast<::fnv_00897910::AnimOwner *>((::_g_thePlayer))->FUN_00897910((*(int *)&(aimState.group)), (::fnv_00897910::Equipped *)(::InventoryStackRecord *)(0), false, (::fnv_00897910::AnimData *)(aimState.animation));
        if (!aimState.sequence ||
            aimState.groupID != reinterpret_cast<::FUN_0047d3b0_shell *>((reinterpret_cast<TESActorBaseData*>(reinterpret_cast<::BSAnimGroupSequence *>((aimState.sequence))->GetAnimGroup())))->FUN_0047d3b0())
            reinterpret_cast<::fnv_004994f0::FUN_004994f0_shell *>((aimState.animation))->FUN_004994f0(4, false);
        aimState.animation = ::_g_thePlayer->GetAnimation(true);
        aimState.sequence = ((::NiControllerSequence *)(reinterpret_cast<::FUN_00491040_shell *>((aimState.animation))->FUN_00491040(4)));
        aimState.groupID = reinterpret_cast<::fnv_00897910::AnimOwner *>((::_g_thePlayer))->FUN_00897910((*(int *)&(aimState.group)), (::fnv_00897910::Equipped *)(::InventoryStackRecord *)(0), false, (::fnv_00897910::AnimData *)(aimState.animation));
        if (!aimState.sequence ||
            aimState.groupID != reinterpret_cast<::FUN_0047d3b0_shell *>((reinterpret_cast<TESActorBaseData*>(reinterpret_cast<::BSAnimGroupSequence *>((aimState.sequence))->GetAnimGroup())))->FUN_0047d3b0())
            reinterpret_cast<::fnv_004994f0::FUN_004994f0_shell *>((aimState.animation))->FUN_004994f0(4, false);
    }
}

// @fnv 0x009ea360
void PlayerMover::UpdatePlayerStatus(unsigned int auMode, bool abSet)
{
    if (abSet)
        ByteAndFlagState |= auMode;
    else
        ByteAndFlagState &= ~auMode;
}

// Stores the given side vector into the player mover's side vector member.
// @fnv 0x009ea570
void PlayerMover::SetSideVec(const NiPoint3& arSideVec)
{
    m_kSideVec = arSideVec;
}

// @fnv 0x009ea3b0
void PlayerMover::ClearMode(unsigned int auMode)
{
    ByteAndFlagState &= ~auMode;
}

struct FUN_009e9de0_shell : PlayerMover
{
    void FUN_009e9de0(unsigned int auMode);
};

// @fnv 0x009e9de0
void FUN_009e9de0_shell::FUN_009e9de0(unsigned int auMode)
{
    ClearMode(auMode);
}

struct FUN_009e9dc0_shell : PlayerMover
{
    void FUN_009e9dc0(unsigned int auMode);
};

// @fnv 0x009e9dc0
void FUN_009e9dc0_shell::FUN_009e9dc0(unsigned int auMode)
{
    UpdatePlayerStatus(auMode, true);
}

struct FUN_009daef0
{
    virtual ~FUN_009daef0();
};

struct FUN_009e9e30_shell : FUN_009daef0
{
    void FUN_009e9e30();
};

// @fnv 0x009e9e30
void FUN_009e9e30_shell::FUN_009e9e30()
{
    *reinterpret_cast<int*>(this) = 0x0109297c;
    FUN_009daef0::~FUN_009daef0();
}

struct FUN_009e9e00_shell : FUN_009e9e30_shell
{
    void* FUN_009e9e00(unsigned int);
};
// Calls FUN_009e9e30, then deallocates this object if auFlags has bit 0 set, and returns this.
// @fnv 0x009e9e00
void* FUN_009e9e00_shell::FUN_009e9e00(unsigned int auFlags)
{
    FUN_009e9e30();
    if (auFlags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BGSSaveFormBuffer
{
};
struct FUN_009df100_shell : PlayerMover
{
    void FUN_009df100(BGSSaveFormBuffer* apBuffer);
};
struct FUN_009ea5a0_shell : PlayerMover
{
    void FUN_009ea5a0(BGSSaveFormBuffer* apBuffer);
};
// @fnv 0x009ea5a0
void FUN_009ea5a0_shell::FUN_009ea5a0(BGSSaveFormBuffer* apBuffer)
{
    ((FUN_009df100_shell*)this)->FUN_009df100(apBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_kSideVec, 0xC, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&ByteAndFlagState, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_uiMode, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_fValue, 4, 0);
}
