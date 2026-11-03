
// src/fallout_shared/testopic_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0061af30: the skeleton of src/fallout_shared/testopic.cpp
// with declarations corrected to what the original code does (TESTopicInfo.h: TESTopicInfo += TESQuest* FUN_006733e0();). Move the function to its real unit once
// that unit declares it this way.

#include <new>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061af10_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiFormArray.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFaction_RankDataView.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/TopicLinkLists.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_011de000.h"
#include "TESTopic.h"
#include "TESTopicInfo_decl_testopic.h"
#include "TESQuest.h"
#include "QuestDialogueInfo.h"
#include "INFO_LINK_ELEMENT.h"
#include "TESTopicInfoData.h"
#include "DialogueItem.h"
#include "MobileObject.h"
#include "PlayerCharacter.h"
#include "game_constants.h"

// @fnv 0x0061af30
TESTopicInfo* FUN_0061af30(TESTopicInfo* input, bool& deferredResult, TESObjectREFR* speaker, TESObjectREFR* listener,
                           bool filter, BSSimpleList<DialogueItem*>* history)
{
    TESTopicInfo* b = input;
    deferredResult = false;
    if (!b || reinterpret_cast<::FUN_00440d80_shell *>((void *)(b))->FUN_00440d80())
        return 0;
    TESTopicInfo* excluded = 0;
    BSSimpleList<TESTopicInfo*> choices;
    unsigned int f = 0;
    bool h = false;
    BSSimpleList<TESTopicInfo*>* a = 0;
    if (((::TESTopicInfoData *)(::GetField38((char *)(b)))))
        a = ((::BSSimpleList< ::TESTopicInfo *> *)(::FUN_00460140((int)(((::TESTopicInfoData *)(::GetField38((char *)(b))))))));
    TESTopicInfo* fallback = 0;
    while (a && ((::TESTopicInfo *)(new ((void *)(a)) ::Vec3())) && !h)
    {
        TESTopicInfo* info = ((::TESTopicInfo *)(new ((void *)(a)) ::Vec3()));
        TESQuest* quest = info->FUN_006733e0();
        a = ((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
        if (quest && reinterpret_cast<::TESFaction_RankDataView *>((quest))->FUN_00455620() && quest->GetConditions()->ContainsTrait(speaker, listener))
        {
            bool deferred = false;
            bool allowed = true;
            if (info && reinterpret_cast<::TopicFlagStandIn *>((info))->FUN_0061aef0() && speaker->IsMobileObject())
            {
                MobileObject* mobile = (MobileObject*)speaker;
                if (reinterpret_cast<::FUN_00935a40_cls *>((mobile))->HasEntryWithKey((int)(info)))
                    allowed = false;
            }
            if (info && allowed && reinterpret_cast<::FUN_0061e600_t *>((info))->FUN_0061e600(deferred, 0, speaker, listener))
            {
                deferredResult = false;
                bool keep = true;
                if (keep)
                {
                    if (::IsFlag20Set((char *)(info)))
                        h = true;
                    BSSimpleList<DialogueItem*>* seen = history;
                    while (seen && !seen->IsEmpty())
                    {
                        DialogueItem* dialogue = ((::DialogueItem *)(new ((void *)(seen)) ::Vec3()));
                        if (((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((dialogue))->FUN_0084e3a0())) == info)
                        {
                            excluded = info;
                            keep = false;
                            break;
                        }
                        seen = ((::BSSimpleList< ::DialogueItem *> *)(reinterpret_cast<::Callees *>((seen))->FUN_00726070()));
                    }
                }
                if (keep)
                {
                    if (::IsFlag20Set((char *)(info)))
                        h = true;
                    if (choices.IsEmpty() && !::FUN_00619410((const char *)(info)))
                    {
                        return info;
                    }
                    else if (!::FUN_00619410((const char *)(info)))
                    {
                        h = true;
                        break;
                    }
                    else
                    {
                        choices.AddHead(info);
                        f++;
                    }
                }
                if (!filter && deferred)
                {
                    fallback = info;
                    deferredResult = true;
                }
                if (h)
                    break;
            }
        }
    }
    if (choices.IsEmpty())
    {
        if (filter)
            return 0;
        else
            return fallback;
    }
    else
    {
        int pick = f ? DialogueRandom() % f + 1 : 0;
        int a = 0;
        BSSimpleList<TESTopicInfo*>* c = &choices;
        TESTopicInfo* selected = 0;
        TESTopicInfo* b = 0;
        while (a < pick && c)
        {
            b = ((::TESTopicInfo *)(new ((void *)(c)) ::Vec3()));
            if (b)
            {
                selected = b;
                a++;
            }
            c = ((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((c))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>(&(choices))->RemoveAll();
        return selected;
    }
}
