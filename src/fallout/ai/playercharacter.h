// fallout/ai/playercharacter.h: declares AnimSelection
#ifndef FNV_PLAYERCHARACTER_UNIT_H
#define FNV_PLAYERCHARACTER_UNIT_H

#include "fnv/decl/FNV_AnimationOwner.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/fnv_00494740__FUN_00494740_t.h"
#include "fnv/decl/fnv_00897910__AnimOwner.h"
#include "fnv/symbols_005f2000.h"
#include "playercharacter_decls.h"

// @fnv 0x009520f0
void PlayerCharacter::SetActionGroupFlags(unsigned short group, ACTION_FLAGS flags)
{
    if (group & 0x8000)
        group &= 0x7FFF;
    struct AnimSelection
    {
        ANIM_GROUP_ENUM type;
        Animation* animation;
    } selection;
    selection.type = TESAnimGroup::GetType(group);
    if (selection.type == ANIM_GROUP_ENUM_ANIM_GROUP_NONE)
        return;
    selection.animation = reinterpret_cast<::PlayerCharacter *>(this)->GetAnimation(true);
    bool copied = false;
    if (DAT_011977dc[selection.type].availableInThirdPerson)
    {
        Animation* thirdPerson = reinterpret_cast<::PlayerCharacter *>(this)->GetAnimation(false);
        BSAnimGroupSequence* sequence = reinterpret_cast<::FUN_00491040_shell *>((thirdPerson))->FUN_00491040((*(int *)&(DAT_011977dc[selection.type].section)));
        copied = static_cast<bool>(reinterpret_cast<::FNV_AnimationOwner *>((selection.animation))->GetSequenceForKey(sequence, group));
    }
    if (!copied)
    {
        if (reinterpret_cast<::FUN_00494710_shell *>((selection.animation))->FUN_00494710(group))
            reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((selection.animation))->FUN_00494740(group, (*(int *)&(flags)), -1, (*(int *)&(const ::ANIM_GROUP_SECTION &)(ANIM_GROUP_SECTION_NONE)));
        else if (::IsIronSightsAnimGroup(group) && reinterpret_cast<::FUN_00494710_shell *>((selection.animation))->FUN_00494710(group - 3))
            reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((selection.animation))->FUN_00494740(group - 3, (*(int *)&(flags)), -1, (*(int *)&(const ::ANIM_GROUP_SECTION &)(ANIM_GROUP_SECTION_NONE)));
        else
        {
            unsigned short fallback = reinterpret_cast<::fnv_00897910::AnimOwner *>(this)->FUN_00897910((*(int *)&(selection.type)), (::fnv_00897910::Equipped *)(::InventoryStackRecord *)(0), !reinterpret_cast<::FUN_008a1710_shell *>(this)->FUN_008a1710(), (::fnv_00897910::AnimData *)(selection.animation));
            if (TESAnimGroup::GetType(fallback) == selection.type ||
                (::FUN_005f2750((*(int *)&(selection.type))) &&
                 TESAnimGroup::GetType(fallback) == selection.type - 3))
                reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((selection.animation))->FUN_00494740(fallback, (*(int *)&(flags)), -1, (*(int *)&(const ::ANIM_GROUP_SECTION &)(ANIM_GROUP_SECTION_NONE)));
        }
    }
}

// @fnv 0x0095ed80
void PlayerCharacter::ResetActorValueModifiers()
{
    for (int i = 0; i < 77; ++i)
    {
        if (ActorValueModifierData[i] != 0.0 && !FUN_00822f70(static_cast<ActorValue::Index>(i)))
            ActorValueModifierData[i] = 0.0f;
    }
}

// @fnv 0x009396d0
ActorCombatGroup* PlayerCharacter::GetCombatGroup()
{
    return m_pCombatData;
}
#endif
