
// src/fallout/audio/falloutradio_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00835be0: the skeleton of src/fallout/audio/falloutradio.cpp
// that unit declares it this way.

#include <new>
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00832190_shell.h"
#include "fnv/decl/FUN_00833040_shell.h"
#include "fnv/decl/FUN_00833100_shell.h"
#include "fnv/decl/FUN_00833be0_shell.h"
#include "fnv/decl/FUN_00835690_shell.h"
#include "fnv/decl/FUN_00835f10_shell.h"
#include "fnv/decl/FUN_0083b9f0_shell.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/Holder00832160.h"
#include "fnv/decl/Mid83b9a0.h"
#include "fnv/decl/StateStandIn.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0083c470__FUN_0083c470_holder.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/s835fe0__RefHandle.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00832000.h"
#include "fnv/symbols_00833000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "falloutradio_private_decls_decl_falloutradio.h"

class BGSTalkingActivator : public TESForm
{
};
class DialogueResponse;
class TESTopicInfo;
class TESQuest;
class DialogueResponse;
class DialogueItem
{
  public:
    BSSimpleList<DialogueResponse*> responses;
    BSSimpleList<DialogueResponse*>* current;
    TESTopicInfo* info;
    TESTopic* topic;
    TESQuest* quest;
    TESObjectREFR* speaker;
public:
    bool SelectDefaultResponseList();
public:
    ::DialogueResponse *GetActiveResponse();
};
class Conversation
{
  public:
    BSSimpleList<DialogueItem*> items;
    BSSimpleList<DialogueItem*>* current;
    ~Conversation();
};
class TESTopic;
FalloutRadio::RadioStationState* CreateRadioStationState(BGSTalkingActivator*, bool);
void FUN_00834260(FalloutRadio::RadioStationState*);
class ATM
{
  public:
};
class BSAudio
{
  public:
    unsigned int GetSynchTime();
};
// @fnv 0x00835be0
void FUN_00835be0(BGSTalkingActivator* form, TESTopic* topic)
{
    TESTopic* a = 0;
    FalloutRadio::RadioStationState* station = 0;
    if (DAT_011dd436)
        return;
    BSSimpleList<FalloutRadio::RadioStationState*>* entries = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554));
    while (entries && ((::FalloutRadio::RadioStationState *)(new ((void *)(entries)) ::Vec3())))
    {
        if (((::FalloutRadio::RadioStationState *)(new ((void *)(entries)) ::Vec3()))->form == form)
        {
            station = ((::FalloutRadio::RadioStationState *)(new ((void *)(entries)) ::Vec3()));
            break;
        }
        entries = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((entries))->FUN_00726070()));
    }
    if (!station)
        station = CreateRadioStationState(form, false);
    a = topic ? topic : ((::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName(7, 0)));
    if (!station || station->form->GetDisabled())
        return;
    bool f = reinterpret_cast<::FUN_00833040_shell *>(&(station->station))->IsFlag20Set();
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::ATM *>(&::g_011dd5e8))))->FUN_004538a0((int)("FalloutRadio::StartRadioConversation"));
    if (station->station.conversation)
        while (reinterpret_cast<::FUN_0083b9f0_shell *>((station->station.conversation))->FUN_0083b9f0())
        {
        }
    if (((bool)(reinterpret_cast<::FUN_00833be0_shell *>(&(station->station))->FUN_00833be0())))
    {
        reinterpret_cast<::FUN_00833100_shell *>(&(station->station))->FUN_00833100(false);
        station->station.state = 1;
        FUN_00834260(station);
    }
    if ((*reinterpret_cast<::FalloutRadio::RadioStationState * *>(&::DAT_011dd42c)) == station && DAT_011dd434)
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc))))->FUN_00ad88f0();
        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)).Release();
        if (((bool)(::FUN_00833ce0())))
        {
            ::FalloutAudioMedia::BeginMediaUpdate();
            ::FUN_008325a0(true);
            ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)(MEDIATYPE_RADIO)), 0, 1000, false, false, 0.0f, 0);
            ::FalloutAudioMedia::EndMediaUpdate();
        }
    }
    BSSimpleList<FalloutRadio::RadioReceiver*>* b = &station->receivers;
    while (b && ((::FalloutRadio::RadioReceiver *)(new ((void *)(b)) ::Vec3())))
    {
        FalloutRadio::RadioReceiver* receiver = ((::FalloutRadio::RadioReceiver *)(new ((void *)(b)) ::Vec3()));
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(receiver->sound))->FUN_00ad88f0();
        receiver->sound.Release();
        b = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((b))->FUN_00726070()));
    }
    ::AdvanceConversation((::RadioState *)(station), a);
    station->station.state = 0;
    reinterpret_cast<::fnv_0083c470::FUN_0083c470_holder *>((station->station.conversation))->FUN_0083c470();
    reinterpret_cast<::Mid83b9a0 *>((station->station.conversation))->FUN_0083b9a0();
    if (!((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((station->station.conversation))->GetActiveResponse())))
    {
        delete station->station.conversation;
        station->station.conversation = 0;
        station->station.state = 1;
    }
    else
    {
        if ((*reinterpret_cast<::FalloutRadio::RadioStationState * *>(&::DAT_011dd42c)) == station && DAT_011dd434)
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc))))->FUN_00ad88f0();
            (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)).Release();
            if (((bool)(::FUN_00833ce0())))
            {
                ::FalloutAudioMedia::BeginMediaUpdate();
                ::FUN_008325a0(true);
                ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)(MEDIATYPE_RADIO)), 0, 1000, false, false, 0.0f, 0);
                ::FalloutAudioMedia::EndMediaUpdate();
            }
        }
        ((::DialogueItem *)(reinterpret_cast<::DialogueItem *>((station->station.conversation))->GetActiveResponse()))->SelectDefaultResponseList();
    }
    if (station->station.state > 1)
        station->station.state = 0;
    station->station.nextUpdate = ::FUN_00453a70()->GetSynchTime() + 50;
    reinterpret_cast<::FUN_00835690_shell *>(&(station->station))->SetFlag80(true);
    reinterpret_cast<::FUN_00833100_shell *>(&(station->station))->FUN_00833100(f);
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::ATM *>(&::g_011dd5e8))))->WaitForTasksDuringRendering();
}
