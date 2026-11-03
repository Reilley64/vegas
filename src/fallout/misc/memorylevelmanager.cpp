// fallout/misc/memorylevelmanager.cpp: ActorReferenceArray (5 functions)

#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/FUN_00422320_shell.h"
#include "fnv/decl/FUN_00422450.h"
#include "fnv/decl/FUN_00529ea0_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_008b39f0_shell.h"
#include "fnv/decl/FUN_00904430_Class.h"
#include "fnv/decl/FUN_00977c70_class.h"
#include "fnv/decl/FUN_00977c90_class.h"
#include "fnv/decl/FUN_009c1a50_shell.h"
#include "fnv/decl/FUN_00c3e340_cls.h"
#include "fnv/decl/FaceGenModelCache650.h"
#include "fnv/decl/HighProcessAvoid.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_00448620__FUN_00448620_cls.h"
#include "fnv/decl/fnv_00452490__FUN_00452490_shell.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_008982c0__FUN_008982c0_shell.h"
#include "fnv/decl/fnv_008bcc80__FUN_008bcc80_shell.h"
#include "fnv/decl/fnv_008c4330__FUN_008c4330_cls.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00868000.h"
#include "fnv/symbols_00878000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00aa7000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01202000.h"
#include "memorylevelmanager_decls.h"
// @fnv 0x009777a0
void ActorReferenceArray::ResetActorReferences()
{
    struct Locals
    {
        Actor* resetRef;
        Actor* resetActor;
        unsigned int resetIndex;
        BaseProcess* playerProcess;
        float playerScale;
        float distance;
        float value;
        float scale;
        unsigned int i;
        Actor* ref;
        float radius;
        BaseProcess* process;
        float playerDistance;
        float playerValue;
        Actor* actor;
        float amount;
        TESFile* key;
        ExtraDataList* extra;
        TESObjectREFR* source;
        void* pos;
        unsigned char padding0;
        unsigned char padding1;
        unsigned char padding2;
        bool reset;
        unsigned int unused;
        BGSReconstructFormsInAllFilesMap* map;
        float maximum;
    } local;
    // This local name preserves MSVC 2008 stack allocation order.
    BaseProcess* maximum;
    local.reset = false;
    local.maximum = 0.0f;
    local.unused = 0;
    local.map = reinterpret_cast<BGSReconstructFormsInAllFilesMap*>(
        ((::BSSimpleList< ::TESReputation *> *)(reinterpret_cast<::FUN_009c1a50_shell *>((reinterpret_cast<TESDataHandler*>(DAT_011c95c8)))->FUN_009c1a50())));
    if (local.map)
    {
        local.pos = local.map->GetFirstPos();
        if (local.pos)
            DAT_011f12d8 = true;
        else if (!local.pos && DAT_011f12d8)
        {
            DAT_011f12d8 = false;
            local.reset = true;
        }
        while (local.pos)
        {
            local.key = 0;
            local.source = 0;
            reinterpret_cast<::C6b7f20_Map *>((local.map))->FUN_006b7f20((::C6b7f20_Node **)&(local.pos), (unsigned int *)&(local.key), (void **)&(reinterpret_cast<BGSReconstructFormsInFileMap*&>(local.source)));
            local.extra = local.source ? ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((local.source))->FUN_005d43c0())) : 0;
            if (local.extra)
            {
                local.radius = reinterpret_cast<::FUN_00422320_shell *>((local.extra))->FUN_00422320();
                local.amount = reinterpret_cast<::FUN_00422450 *>((local.extra))->GetExtraDataFloat();
                local.ref = 0;
                local.actor = 0;
                local.process = 0;
                for (local.i = 0; local.i < reinterpret_cast<::FUN_005be5c0_shell *>((reinterpret_cast<TopicInfoArray*>(actorArray)))->FUN_005be5c0(0); local.i++)
                {
                    local.ref = ((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((reinterpret_cast<TopicInfoArray*>(actorArray)))->FUN_00968670(local.i)));
                    local.actor = 0;
                    if (local.ref && local.ref->vfn_100())
                        local.actor = local.ref;
                    if (local.actor)
                    {
                        local.process = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((local.actor))->GetBaseTexture()));
                        if (((double)(reinterpret_cast<::FUN_00977c70_class *>((local.process))->GetField43C())) >
                            ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting1045)))))
                                ->f)
                        {
                            local.distance = reinterpret_cast<::RefS *>((local.actor))->FUN_005723b0((::RefS *)(local.source), false, true);
                            local.value = ScaleByInverseRatio(local.amount, local.radius, local.distance);
                            local.scale = reinterpret_cast<::fnv_008c4330::FUN_008c4330_cls *>((local.actor))->FUN_008c4330();
                            local.value *= local.scale;
                            if (local.actor &&
                                local.value >
                                    ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting292)))))
                                        ->f &&
                                local.value > reinterpret_cast<::FUN_00904430_Class *>((local.process))->GetField440())
                            {
                                if (reinterpret_cast<::fnv_008bcc80::FUN_008bcc80_shell *>((local.actor))->FUN_008bcc80())
                                {
                                    if (!local.process->vfn_258(local.source))
                                        reinterpret_cast<::HighProcessAvoid *>((local.process))->AddAvoidArea((::AvoidActorStub *)(local.actor), local.source->GetPos(), local.radius,
                                                                    3.402823466e+38f, local.value, (::AvoidRefStub *)(local.source), false);
                                    else if (!((bool)(reinterpret_cast<::TeleportableReference *>((local.actor))->GetTeleportDestinationForm())))
                                        reinterpret_cast<::FUN_008b39f0_shell *>((local.actor))->FUN_008b39f0(0x200);
                                    else
                                        reinterpret_cast<::fnv_008982c0::FUN_008982c0_shell *>((local.actor))->SetRadiationAvoidPackage(local.source, 0.0f);
                                }
                                reinterpret_cast<::FUN_00977c90_class *>((local.process))->FUN_00977c90(local.value);
                            }
                            local.process->vfn_768(reinterpret_cast<::FUN_00904430_Class *>((local.process))->GetField440());
                        }
                    }
                }
                local.process = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((::_g_thePlayer))->GetBaseTexture()));
                local.playerDistance = reinterpret_cast<::RefS *>((::_g_thePlayer))->FUN_005723b0((::RefS *)(local.source), false, true);
                local.playerValue = ScaleByInverseRatio(local.amount, local.radius, local.playerDistance);
                if (local.playerValue > 0.0)
                {
                    local.playerScale = reinterpret_cast<::fnv_008c4330::FUN_008c4330_cls *>((::_g_thePlayer))->FUN_008c4330();
                    local.playerValue *= local.playerScale;
                }
                if (::_g_thePlayer && local.playerValue > 0.0 && local.playerValue > reinterpret_cast<::FUN_00904430_Class *>((local.process))->GetField440())
                    reinterpret_cast<::FUN_00977c90_class *>((local.process))->FUN_00977c90(local.playerValue);
                if (local.maximum < local.playerValue)
                    local.maximum = local.playerValue;
                local.process->vfn_768(reinterpret_cast<::FUN_00904430_Class *>((local.process))->GetField440());
            }
        }
    }
    active = local.maximum > 0.0 ? 1 : 0;
    if (local.reset)
    {
        for (local.resetIndex = 0; local.resetIndex < reinterpret_cast<::FUN_005be5c0_shell *>((reinterpret_cast<TopicInfoArray*>(actorArray)))->FUN_005be5c0(0);
             local.resetIndex++)
        {
            local.resetRef = ((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((reinterpret_cast<TopicInfoArray*>(actorArray)))->FUN_00968670(local.resetIndex)));
            local.resetActor = local.resetRef && local.resetRef->vfn_100() ? local.resetRef : 0;
            if (local.resetActor)
            {
                maximum = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((local.resetActor))->GetBaseTexture()));
                if (maximum)
                    maximum->vfn_768(0.0f);
            }
        }
        local.playerProcess = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((::_g_thePlayer))->GetBaseTexture()));
        if (local.playerProcess)
            local.playerProcess->vfn_768(0.0f);
    }
}

class NiRenderer
{
  public:
};
class IOManager;

void __cdecl FUN_008781e0(int);
void __cdecl FUN_00a5b460(void);

// @fnv 0x00878200
void __cdecl FUN_00878200(unsigned char* aFreeData)
{
    FUN_00a5b460();
    FUN_00aa7030();
    if (aFreeData[5])
    {
        ::fnv_00652190::FUN_00652190();
    }
    FUN_008781e0(*(int*)(aFreeData + 8));
    if (aFreeData[3])
    {
        reinterpret_cast<::fnv_004a03c0::DD *>((FUN_0043c4b0()))->FUN_004a03c0();
    }
    reinterpret_cast<::FUN_00c3e340_cls *>((::DAT_01202d98))->FUN_00c3e340();
}

class ShadowSceneNode;

class ModelLoader
{
  public:
};

class NiAdditionalGeometryData
{
  public:
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};

class TES
{
  public:
};


void __cdecl FUN_00651f40();

// @fnv 0x00878250
void __cdecl FUN_00878250(bool abRunExtraSteps)
{
    ::FUN_00868d70(1);
    reinterpret_cast<::Owner *>((NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->FUN_00b5fd60();
    ::FUN_00c459d0(0);
    if (abRunExtraSteps)
    {
        FUN_00651e30();
        FUN_00651f40();
    }
    reinterpret_cast<::fnv_00448620::FUN_00448620_cls *>((g_modelLoader))->FUN_00448620(true);
    reinterpret_cast<::fnv_00452490::FUN_00452490_shell *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00452490(false);
}

struct FUN_00878340_shell : public PlayerCharacter
{
    bool FUN_00878340();
};
// @fnv 0x008782b0
void ActorReferenceArray::SetupActorReferences()
{
    ActorReferenceSetupData data;
    ::FUN_00878160((char *)&(data), true, true, true);
    FUN_00878250(data.c);
    if (reinterpret_cast<::FUN_00878340_shell *>((::_g_thePlayer))->FUN_00878340() && BSFaceGenManager::GetModelMap() &&
        ((bool)(reinterpret_cast<::FUN_00529ea0_shell *>((BSFaceGenManager::GetModelMap()))->FUN_00529ea0())) && !((::Tile *)(::FUN_00a09030(0x40c))))
        reinterpret_cast<::FaceGenModelCache650 *>((BSFaceGenManager::GetModelMap()))->PurgeUnusedModels(false);
    ::FUN_00878200((unsigned char *)&(data));
}

// @fnv 0x00878340
bool FUN_00878340_shell::FUN_00878340()
{
    return *((bool*)((char*)this + 0x75d));
}

#include "generated/data/fallout/misc/memorylevelmanager.inc"
