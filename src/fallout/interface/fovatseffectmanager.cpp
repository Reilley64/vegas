// fallout/interface/fovatseffectmanager.cpp: ShadowLightData, EffectSetting (4 functions)


#include <new>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
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
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01267000.h"
#include "fovatseffectmanager_targets.h"

// Stores targetMask at selected_target_masks[selectedIndex] and sets or clears the selectedIndex bit in each of the 43 mask words according to targetMask.
// @fnv 0x00c82870
void ShadowLightData::SetTargetMaskForSelection(unsigned int selectedIndex, unsigned __int64 ullTargetMask)
{
    unsigned __int64 ullSelectedBit = ((unsigned __int64)1) << selectedIndex;
    selected_target_masks[selectedIndex] = ullTargetMask;

    unsigned __int64 ullTestBit = 1;
    unsigned int byteOffset = 0;
    do
    {
        unsigned __int64* pullMaskWord = (unsigned __int64*)((unsigned char*)selected_target_masks + byteOffset);
        if (ullTargetMask & ullTestBit)
            *pullMaskWord |= ullSelectedBit;
        else
            *pullMaskWord &= ~ullSelectedBit;
        ullTestBit <<= 1;
        byteOffset += 8;
    } while (byteOffset < 0x158);
}

#pragma optimize("", off)
#include "fovatseffectmanager_perks.h"

// Applies the perk entry-point functions for an actor's entry point, validating filter parameters and function arguments first.
// @fnv 0x005e58f0
void ApplyPerkModifiers(int entryPoint, Actor* actor, ...)
{
    if (!actor || entryPoint >= 74)
        return;
    bool bUsePlayer = false;
    Actor* pOriginalActor = actor;
    if (actor != (Actor*)::_g_thePlayer && reinterpret_cast<::MiddleHighProcess *>((actor))->IsActorInCombat())
    {
        bUsePlayer = true;
        actor = (Actor*)::_g_thePlayer;
    }
    BSSimpleList<BGSPerkEntry*>* pList = actor->GetPerkEntriesForEntryPoint((unsigned char)entryPoint, bUsePlayer);
    if (pList && ((::BGSPerkEntry *)(new ((void *)(pList)) ::Vec3())))
    {
        actor = pOriginalActor;
        void* pEntryPointArguments[10];
        void* pParameters[10];
        struct PerkArgumentValidation
        {
            bool validArguments;
            unsigned char argumentCount;
            unsigned char parameterCount;
            bool validParameters;
        } argumentValidation;
        struct PerkArgumentCursor
        {
            BGSEntryPointFunction::ENTRY_POINT_FUNCTION_TYPE type;
            char* current;
        } kArgumentPosition;
        argumentValidation.parameterCount = EntryPointFunctionDispatcher::ms_kEntryPointTable[entryPoint].filterCount;
        kArgumentPosition.type = (BGSEntryPointFunction::ENTRY_POINT_FUNCTION_TYPE)
                                     EntryPointFunctionDispatcher::ms_kEntryPointTable[entryPoint]
                                         .functionType;
        argumentValidation.argumentCount = BGSEntryPointFunction::GetArgumentCount(kArgumentPosition.type);
        pParameters[0] = actor;
        kArgumentPosition.current = (char*)(&actor + 1);
        argumentValidation.validParameters = true;
        for (unsigned int i = 1; i < argumentValidation.parameterCount; ++i)
        {
            pParameters[i] = *(void**)((kArgumentPosition.current += 4) - 4);
            if (!pParameters[i])
                argumentValidation.validParameters = false;
        }
        argumentValidation.validArguments = true;
        for (unsigned int i = 0; i < argumentValidation.argumentCount; ++i)
        {
            pEntryPointArguments[i] = *(void**)((kArgumentPosition.current += 4) - 4);
            if (!pEntryPointArguments[i])
                argumentValidation.validArguments = false;
        }
        kArgumentPosition.current = 0;
        if (argumentValidation.validParameters && argumentValidation.validArguments)
        {
            while (pList)
            {
                BGSPerkEntry* pPerkEntry = ((::BGSPerkEntry *)(new ((void *)(pList)) ::Vec3()));
                if (pPerkEntry && pPerkEntry->IsInfoValidForDialogue(argumentValidation.parameterCount, pParameters))
                    BGSEntryPointFunction::ApplyFunction(
                        (BGSEntryPointFunction::ENTRY_POINT_FUNCTION)pPerkEntry->GetFunction(), actor,
                        kArgumentPosition.type, argumentValidation.argumentCount, pEntryPointArguments,
                        pPerkEntry->GetFunctionData());
                pList = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
            }
        }
        else
        {
            ::FUN_005b5e40();
        }
    }
}

#include "fovatseffectmanager_effects.h"

// Initializes the EffectSetting data fields to defaults, reads two game-setting floats, and sets the form type to 0x10.
// @fnv 0x00407020
EffectSetting::EffectSetting()
{
    data.iFlags = 0;
    data.m_fBaseCost = 0.0f;
    data.m_pAssociatedForm = 0;
    data.m_iAssociatedActorValue = -1;
    data.m_iAssociatedSkill = -1;
    data.m_iResistanceActorValue = -1;
    data.m_sCounterEffectCount = 0;
    data.apTargetLight = 0;
    data.m_pEffectShader = 0;
    data.m_pEnchantEffectShader = 0;
    data.fSpeed = 1.0f;
    data.m_pCastSound = 0;
    data.m_pBoltSound = 0;
    data.m_pContactSound = 0;
    data.m_pAreaEffectSound = 0;
    data.m_fEnchantmentFactor = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(((SettingT_GameSettingCollection_&)g_011c36c0)))))->f;
    data.m_fBarterFactor = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(((SettingT_GameSettingCollection_&)g_011c37e8)))))->f;
    data.m_eEffectTypeItem = 0;
    m_iActorValue = 0;
    m_iEffectID = 0;
    m_pEffectSettingCallback = 0;
    m_pPredicateData = 0;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x10)));
}

// @fnv 0x007f7610
ShadowLightData::ShadowLightData() : m_spTargetObject(0)
{
    pShaderParams = new ImageSpaceShaderParam;
    pShaderParams->AllocateShaderConstants(0, 0);
    pShaderParams->m_bTextureFlags[1] = false;
    pShaderParams->m_bTextureFlags[2] = false;
    pShaderParams->m_eShaderFilterMode = (NiTexturingProperty__FilterMode)1;
    m_spTargetObject = 0;
    state.enabled = false;
    point3 = DAT_011f4980;
    effectEnabled = false;
    intensity = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(((SettingT_GameSettingCollection_&)g_011db25c)))))->f;
    radius = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(((SettingT_GameSettingCollection_&)g_011db238)))))->f;
    duration = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(((SettingT_GameSettingCollection_&)g_011db200)))))->f;
}

#include "generated/data/fallout/interface/fovatseffectmanager.inc"
