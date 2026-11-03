// fallout/interface/fovatseffectmanager.cpp: ShadowLightData, EffectSetting (4 functions)


#include "fnv/result_slot.h"
#include "fnv/simple_list_node_view.h"
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
#include <cstdint>
#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSRenderedTexture.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/CameraState4E9.h"
#include "fnv/decl/EquipVisibility.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00422820_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004a1040_Helper.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_004ebbc0_shell.h"
#include "fnv/decl/FUN_005e50f0_Obj.h"
#include "fnv/decl/FUN_00800740_Class.h"
#include "fnv/decl/FUN_008007b0_Class.h"
#include "fnv/decl/FUN_00800820_Class.h"
#include "fnv/decl/FUN_00800870_Class.h"
#include "fnv/decl/FUN_00800900_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00c4edb0_Class.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/PropertyOwner.h"
#include "fnv/decl/S694a0.h"
#include "fnv/decl/S_00c4ed70_Class.h"
#include "fnv/decl/S_00c4edf0_cls.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/SystemColorManager.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/This8022.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_00457620__FUN_00457620_cls.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_008006b0__FUN_008006b0_Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004e9000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00ba9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01201000.h"

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
    if (pList && ((::BGSPerkEntry *)(reinterpret_cast<::SimpleListNodeView*>(pList)->m_item)))
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
                BGSPerkEntry* pPerkEntry = ((::BGSPerkEntry *)(reinterpret_cast<::SimpleListNodeView*>(pList)->m_item));
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


struct Struct801420
{
    int f0;
    void FUN_00801420(unsigned char a, int b);
    void FUN_00801450(unsigned char a, int b);
};
extern "C" unsigned char __cdecl FUN_00709d00();

struct FOVATSEffectManager_00801a60
{
    void FUN_00801ad0(int, int, int, unsigned char);
    void FUN_00801a60(int, int, int, unsigned char);
};

struct SoundPlaybackHandle
{
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    virtual void FUN_00000008();
    virtual void FUN_0000000C();
    virtual void FUN_00000010();
    virtual void Play();
};

struct S5 : SoundPlaybackHandle
{
};

struct S4
{
};

struct ImageSpaceManager : S4
{
public:
    static ::ImageSpaceManager *FUN_004e3270();
};

struct FOVATSEffectManager_008019d0
{
    void FUN_008019d0();
};

extern int DAT_012007fc;

// @fnv 0x008019d0
void FOVATSEffectManager_008019d0::FUN_008019d0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((::S5 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((::ImageSpaceManager::FUN_004e3270()))->FUN_004ebbc0(0x0A)))))->FUN_004f15a0(0);
    reinterpret_cast<::FUN_004f15a0_shell *>((((::S5 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((::ImageSpaceManager::FUN_004e3270()))->FUN_004ebbc0(0x0B)))))->FUN_004f15a0(0);
    ((::S5 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((::ImageSpaceManager::FUN_004e3270()))->FUN_004ebbc0(0x0A)))->Play();
    ((::S5 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((::ImageSpaceManager::FUN_004e3270()))->FUN_004ebbc0(0x0B)))->Play();
    DAT_012007fc = 0;
}

struct NiAVObject;

struct RefLike
{
};

struct FormLike
{
};

struct NodeLike
{
    int FUN_004b4ec0();
};

struct FilterLike
{
    int FUN_004a3a20();
};

struct FilterHolder
{
    int val;
    FilterHolder(int a);
    int FUN_004a3a20();
};

struct Vec3Like
{
    float x;
    float y;
    float z;
    Vec3Like();
};

struct CellLike
{
};

struct TESLike
{
};

struct ExtraLike
{
};


void* FUN_004b5ad0(NiAVObject* p);

// @fnv 0x004b5820
uintptr_t FUN_004b5820(FormLike* form)
{
    unsigned int result5 = 0;
    if (form)
    {
        void* node_ = FUN_004b59f0(form);
        void* objTmp = !node_ ? FUN_004b5950(form) : 0;
        if (node_)
        {
            RefLike* ref = ((::RefLike *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(node_))));
            if (ref)
            {
                result5 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((ref))->GetName()));
            }
            else if (((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::FilterHolder &)(FilterHolder(::FUN_0043b540((char *)(form)))))->FUN_004a3a20())) == 1)
            {
                Vec3Like pos4;
                ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&pos4)), (*(const ::hkVector4 *)(((NodeLike*)node_)->FUN_004b4ec0())));
                CellLike* cellA = ((::CellLike *)(reinterpret_cast<::fnv_00457620::FUN_00457620_cls *>(((*reinterpret_cast<::TESLike * *>(&::g_TES))))->FUN_00457620((const float *)(::Vec3Like *)(&pos4))));
                if (cellA && ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((cellA))->FUN_009611e0())))
                {
                    result5 = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((cellA))->FUN_009611e0()));
                }
            }
        }
        else
        {
            RefLike* ref2 = (RefLike*)FUN_004b5ad0((NiAVObject*)objTmp);
            if (ref2)
            {
                result5 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((ref2))->GetName()));
            }
            if (!result5)
            {
                ExtraLike* extra5 = (ExtraLike*)FUN_004b5a80(objTmp);
                if (extra5)
                {
                    result5 = ((unsigned int)(reinterpret_cast<::PropertyOwner *>((extra5))->FUN_00c85c80((void *)(0))));
                }
            }
        }
    }
    return result5;
}

struct VQueryObj
{
    ~VQueryObj();
};

struct VRenderer
{
};

struct VTimeGlobal
{
};

struct VTarget
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int a);
};

struct VNodePtr
{
    void* ptr;
    operator void*() const;
};


struct VATSEffectStub
{
    int state;
    VTarget* target;
    VNodePtr node;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    unsigned char unk118;
    unsigned char pending[16];
    unsigned char unk129;
    unsigned char unk12a;
    unsigned char unk12b;
    VQueryObj* queriesB[16];
    VQueryObj* queriesA[16];
    unsigned char done[16];
    unsigned int resultA[16];
    unsigned int resultB[16];
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    unsigned char unk284;
    unsigned char unk285;
    unsigned char unk286;
    unsigned char unk287;
    int unk288;
    int unk28c;
    int unk290;
    float unk294;
    unsigned char unk298;
    unsigned char unk299;
    unsigned char unk29a;
    unsigned char unk29b;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    unsigned char unk2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    unsigned int unk2c8;

    void FUN_00800370();
};

// @fnv 0x00800370
void VATSEffectStub::FUN_00800370()
{
    if (!node)
    {
        unk2b4 = 0;
        unk2b5 = 0;
        return;
    }
    float time = (float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::VTimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    if (unk2b4)
    {
        reinterpret_cast<::FUN_00800900_cls *>(this)->FUN_00800900(time);
    }
    else
    {
        if (unk284)
        {
            reinterpret_cast<::FUN_00800870_Class *>(this)->UpdateProgress(time);
        }
        else if (time > unk294)
        {
            reinterpret_cast<::fnv_008006b0::FUN_008006b0_Class *>(this)->FUN_008006b0();
        }
        reinterpret_cast<::FUN_008007b0_Class *>(this)->SetScaledValues(time);
        if (state == 1 && unk10 != -1)
        {
            reinterpret_cast<::FUN_00800820_Class *>(this)->FUN_00800820(time);
        }
    }
    if (unk298)
    {
        reinterpret_cast<::FUN_00800740_Class *>(this)->FUN_00800740(time);
    }
    if (target && target->v22c(0))
    {
        reinterpret_cast<::Target *>(this)->FUN_00800ac0((::TargetActor *)(0), -1, 0);
    }
    ::FUN_0040fbe0();
    for (unsigned int i = 0; i < 16; i++)
    {
        if (node && queriesA[i] && queriesB[i])
        {
            ::FUN_004a0370((char *)(((::VRenderer *)(::FUN_0043c4b0()))));
            unsigned int a;
            unsigned int b;
            if (((unsigned char)(reinterpret_cast<::S_00c4edf0_cls *>((queriesA[i]))->FUN_00c4edf0((std::intptr_t)(&a), 1))) && ((unsigned char)(reinterpret_cast<::S_00c4edf0_cls *>((queriesB[i]))->FUN_00c4edf0((std::intptr_t)(&b), 1))) && !done[i])
            {
                delete queriesA[i];
                queriesA[i] = 0;
                delete queriesB[i];
                queriesB[i] = 0;
                done[i] = 1;
                pending[i] = 0;
                resultA[i] = a;
                resultB[i] = b * unk2c8;
            }
            reinterpret_cast<::fnv_004a03c0::DD *>((((::VRenderer *)(::FUN_0043c4b0()))))->FUN_004a03c0();
        }
    }
}

struct Str8
{
    int p;
    int len;
    operator const char*() const;
};
struct Renderer
{
};
struct AnimData
{
};
struct Obj
{
};
struct FaceNode
{
};
struct S801880
{
    int unk00;
    int unk04;
    int unk08;
    int count;
    int selected;
    int unk14;
    Str8 names[80];
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    Str8 name;
    void FUN_00801880();
};
// @fnv 0x00801420
void Struct801420::FUN_00801420(unsigned char a, int b)
{
    if (f0 == 0)
        FUN_00801450(a, b);
    else
        reinterpret_cast<::S801880 *>(this)->FUN_00801880();
}

// @fnv 0x00801880
void S801880::FUN_00801880()
{
    if (this->count > 0)
    {
        Renderer* renderer = ((::Renderer *)(::FUN_0043c4b0()));
        FaceNode* node5 = ((::FaceNode *)(::FUN_0045c670()));
        int unk5 = this->unk04;
        Obj* objTmp = ((::Obj *)(reinterpret_cast<::MiddleLowProcess *>((node5))->GetProcessInteger()));
        reinterpret_cast<::FUN_004a0fd0_shell *>((objTmp))->FUN_004a0fd0((::NiNode *)(const char *)(this->name));
        AnimData* anim = ((::AnimData *)(reinterpret_cast<::BSFaceGenNiNode *>((node5))->GetAnimationData()));
        reinterpret_cast<::CameraState4E9 *>((((::Renderer *)(::FUN_0043c4b0()))))->SetFromCamera((*(const ::Camera4E9 *)(anim)));
        reinterpret_cast<::FUN_0041fd00_shell *>((objTmp))->FUN_0041fd00((int)(anim));
        reinterpret_cast<::S694a0 *>((objTmp))->FUN_00a694a0(((void *)&(reinterpret_cast<::NiCamera *>((anim))->GetViewFrustum())));
        bool found6 = false;
        const char* sel3 = 0;
        for (int i4 = 0; i4 < this->count; i4++)
        {
            const char* s4 = this->names[i4];
            if (i4 == this->selected)
            {
                ::fnv_00ba91a0::FUN_00ba91a0((::fnv_00ba91a0::Obj *)(s4), 0x31, 1);
                sel3 = s4;
                found6 = true;
            }
            ::FUN_00b6bee0(anim, (void *)(s4), (::BSShaderAccumulator *)(objTmp));
        }
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(anim), (::BSShaderAccumulator *)(const char *)(this->name), 0);
        reinterpret_cast<::FUN_004a0fd0_shell *>((objTmp))->FUN_004a0fd0((::NiNode *)(0));
        if (found6)
            ::fnv_00ba91a0::FUN_00ba91a0((::fnv_00ba91a0::Obj *)(sel3), 0x31, 0);
    }
}

struct Vec4Tmp_00801ad0
{
    unsigned int d0;
    unsigned int d1;
    unsigned int d2;
    unsigned int d3;
    void FUN_00414430(float a, float b, float c, float d);
};

struct Holder_00801ad0
{
};

struct Obj719_00801ad0
{
};

struct Obj6e5_00801ad0
{
    void FUN_006e5cc0(void* p);
};

struct Obj0664_00801ad0
{
    void FUN_0066b0d0(void* p);
};

struct Actor_00801ad0
{
};

struct S5_00801ad0
{
};

struct Mgr_00801ad0
{
};

extern float DAT_01201f2c;
extern float DAT_011ae614;
extern float DAT_011ae618;


// @fnv 0x00801ad0
void FOVATSEffectManager_00801a60::FUN_00801ad0(int a0, int a1, int a2, unsigned char a3)
{
    Vec4Tmp_00801ad0 tmp;
    new ((void *)&(tmp)) ::ImageSpaceEffectParam(0.0f, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::SystemColorManager *>((((::Obj719_00801ad0 *)(::FUN_00718b60()))))->GetColor({}, *(::NiColor *)nullptr);
    DAT_01201f2c = *(float*)((char*)this + 0x2bc);
    DAT_011ae614 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Holder_00801ad0 *>(&::g_011db7b4))))));
    DAT_011ae618 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Holder_00801ad0 *>(&::g_011db694))))));
    (*reinterpret_cast<unsigned int *>(&::DAT_01201f30)) = tmp.d0;
    (*reinterpret_cast<unsigned int *>(&::DAT_01201f34)) = tmp.d1;
    (*reinterpret_cast<unsigned int *>(&::DAT_01201f38)) = tmp.d2;
    (*reinterpret_cast<unsigned int *>(&::DAT_01201f3c)) = tmp.d3;
    ((Obj6e5_00801ad0*)&(*reinterpret_cast<int *>(&::DAT_01201f40)))->FUN_006e5cc0((char*)this + 0x2c4);
    ((Obj0664_00801ad0*)&(*reinterpret_cast<int *>(&::g_spBC0500Shared)))->FUN_0066b0d0(((void *)(reinterpret_cast<::FUN_004bc320_shell *>((((Actor_00801ad0*)a1)))->FUN_004bc320(0))));
    reinterpret_cast<::FUN_004f15a0_shell *>((((::S5_00801ad0 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((((::Mgr_00801ad0 *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_004ebbc0({})))))->FUN_004f15a0({});
}

struct FUN_00414430
{
    float r, g, b, a;
    FUN_00414430(float, float, float, float);
};
struct ExtraRefraction
{
    int unk00, unk04, unk08;
    float amount;
};
struct ExtraListRender
{
};
struct RenderActor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool IsHidden(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void AssignActorValue(int, float);
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual float GetRefraction();
};
struct RenderDevice
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void SetColor(FUN_00414430*);
    virtual void v0b0();
    virtual void GetColor(FUN_00414430*);
};
struct FUN_004a4410
{
    int handle;
    ~FUN_004a4410();
};
struct FUN_00c4ecf0
{
    int handle;
    FUN_00c4ecf0();
};
struct RenderAccumulator
{
};
struct AccumulatorPtr
{
    RenderAccumulator* value;
};
struct RenderTexture
{
};
extern unsigned char DAT_01200bf6, DAT_011fd86c;
struct VATSRender : VATSEffectStub
{
    AccumulatorPtr accumulator;
    void FUN_00800f30(RenderTexture*, int, unsigned char, int, int, unsigned char);
};
// @fnv 0x00800f30
void VATSRender::FUN_00800f30(RenderTexture* texture, int mode, unsigned char draw, int flags, int view,
                              unsigned char finish)
{
    if (((RenderActor*)target)->IsHidden(0))
        return;
    RenderDevice* restore = (RenderDevice*)((::VRenderer *)(::FUN_0043c4b0()));
    FUN_00414430 enabled(0.0f, 0.0f, 0.0f, 0.0f);
    restore->GetColor(&enabled);
    restore->SetColor(&ResultSlot(FUN_00414430(0.0f, 0.0f, 0.0f, 0.0f)));
    if (FUN_004e9510())
        ::FUN_00b6b8d0(view, (::NiRenderTargetGroup *)(void *)(((void *)(reinterpret_cast<::BSRenderedTexture *>((texture))->GetGroup()))));
    DAT_01200bf6 = 1;
    DAT_011fd86c = 1;
    unsigned char refraction;
    unsigned char extra = unk118;
    refraction = 0;
    RenderActor* saved = ((RenderActor*)target)->IsActor() ? (RenderActor*)target : 0;
    float perk = saved ? saved->GetRefraction() : 1.0f;
    unsigned char actor;
    ExtraRefraction* amount = 0;
    float renderer = 0.0f;
    ApplyPerkModifiers(0x45, (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)), &renderer);
    if (saved && ((::ExtraListRender *)(reinterpret_cast<::FUN_005d43c0_ *>((saved))->FUN_005d43c0())) && renderer > 0.0)
        amount = ((::ExtraRefraction *)(reinterpret_cast<::FUN_00422820_shell *>((((::ExtraListRender *)(reinterpret_cast<::FUN_005d43c0_ *>((saved))->FUN_005d43c0()))))->GetRefractionProperty()));
    actor = 0;
    float issued = 0.0f;
    if (amount && saved)
    {
        issued = amount->amount;
        actor = 1;
        saved->AssignActorValue(0, 0.0f);
    }
    if (extra)
    {
        if (mode == 2)
        {
            if (queriesB[unk23c])
                delete (FUN_004a4410*)queriesB[unk23c];
            queriesB[unk23c] = (VQueryObj*)new FUN_00c4ecf0;
            refraction = 1;
            reinterpret_cast<::S_00c4ed70_Class *>((((FUN_004a4410*)queriesB[unk23c])))->FUN_00c4ed70();
        }
        else if (mode == 1)
        {
            if (queriesA[unk23c])
                delete (FUN_004a4410*)queriesA[unk23c];
            queriesA[unk23c] = (VQueryObj*)new FUN_00c4ecf0;
            refraction = 1;
            reinterpret_cast<::S_00c4ed70_Class *>((((FUN_004a4410*)queriesA[unk23c])))->FUN_00c4ed70();
        }
    }
    reinterpret_cast<::FUN_004a1040_Helper *>((((::RenderAccumulator *)(::FUN_00559450((int *)&(accumulator))))))->Set(8);
    ::BSShaderManager::SetRenderMode(8);
    reinterpret_cast<::Struct801420 *>(this)->FUN_00801420(draw, flags);
    ::BSShaderManager::SetRenderMode(0);
    reinterpret_cast<::FUN_004a1040_Helper *>((((::RenderAccumulator *)(::FUN_00559450((int *)&(accumulator))))))->Set(0);
    if (refraction)
    {
        if (mode == 2)
        {
            if (queriesB[unk23c])
            {
                reinterpret_cast<::FUN_00c4edb0_Class *>((((FUN_004a4410*)queriesB[unk23c])))->FUN_00c4edb0();
                pending[unk23c] = 1;
            }
            else
                ::FUN_005b5e40();
        }
        else if (mode == 1)
        {
            if (queriesA[unk23c])
                reinterpret_cast<::FUN_00c4edb0_Class *>((((FUN_004a4410*)queriesA[unk23c])))->FUN_00c4edb0();
            else
                ::FUN_005b5e40();
        }
    }
    if (finish)
        ::BSRenderedTexture::EndAllAndResetRendererState();
    if (actor && saved)
        saved->AssignActorValue(1, issued);
    DAT_01200bf6 = 0;
    DAT_011fd86c = 0;
    restore->SetColor(&enabled);
}

extern float DAT_011ae5fc;
struct EffectModeSetup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    bool enabled;
    unsigned char unk285;
    unsigned char unk286;
    unsigned char unk287;
    int unk288;
    float value28c;
    int unk290;
    int unk294;
    bool scaled;
    unsigned char unk299;
    unsigned char unk29a;
    unsigned char unk29b;
    int unk29c;
    int unk2a0;
    int unk2a4;
    float value2a8;
    float value2ac;
    float value2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    float value2c0;
    int unk2c4;
    void FUN_00801bb0(int, Actor_00801ad0*, int, unsigned char);
};
// @fnv 0x00801a60
void FOVATSEffectManager_00801a60::FUN_00801a60(int a, int b, int c, unsigned char d)
{
    if (FUN_00709d00())
        return;
    if (reinterpret_cast<unsigned char*>(this)[0x129])
    {
        if (reinterpret_cast<unsigned char*>(this)[0x2b4])
        {
            FUN_00801ad0(a, b, c, d);
        }
        else
        {
            reinterpret_cast<::EffectModeSetup *>(this)->FUN_00801bb0(a, (::Actor_00801ad0 *)(b), c, d);
        }
    }
}
// @fnv 0x00801bb0
void EffectModeSetup::FUN_00801bb0(int unused, Actor_00801ad0* actor, int unused2, unsigned char flag)
{
    Vec4Tmp_00801ad0 vector;
    new ((void *)&(vector)) ::ImageSpaceEffectParam(0.0f, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::SystemColorManager *>((((::Obj719_00801ad0 *)(::FUN_00718b60()))))->GetColor({}, *(::NiColor *)nullptr);
    DAT_012007fc = 1;
    reinterpret_cast<::FUN_004f15a0_shell *>((((::S5_00801ad0 *)(reinterpret_cast<::FUN_004ebbc0_shell *>((((::Mgr_00801ad0 *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_004ebbc0({})))))->FUN_004f15a0({});
    (*reinterpret_cast<::Obj0664_00801ad0 *>(&::recon7fbee0::DAT_01200818)).FUN_0066b0d0(((void *)(reinterpret_cast<::FUN_004bc320_shell *>((actor))->FUN_004bc320(0))));
    if (enabled)
    {
        DAT_012007f0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Holder_00801ad0 *>(&::g_011db6e4))))));
        DAT_011ae5f8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Holder_00801ad0 *>(&::g_011db79c))))));
        DAT_012007f4 = value28c;
        (*reinterpret_cast<unsigned char *>(&::recon7fbee0::DAT_012007f8)) = 0;
    }
    else
    {
        DAT_012007f0 = 0.0f;
        DAT_011ae5f8 = 0.0f;
        DAT_012007f4 = DAT_01012054;
    }
    DAT_012007e8 = 0.0f;
    (*reinterpret_cast<::Obj6e5_00801ad0 *>(&::recon7fbee0::DAT_01200810)).FUN_006e5cc0(&unk2c4);
    (*reinterpret_cast<::Vec4Tmp_00801ad0 *>(&::recon7fbee0::DAT_01200800)) = vector;
    DAT_011ae5ec = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Holder_00801ad0 *>(&::g_011db714))))));
    DAT_011ae5e8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Holder_00801ad0 *>(&::g_011db720))))));
    DAT_011ae5ec += value2ac;
    DAT_011ae5e8 += value2b0;
    if (scaled)
    {
        DAT_011ae5ec *= 1.0f + value2a8 * 0.5;
        DAT_011ae5e8 *= 1.0f + value2a8;
    }
    DAT_011ae5fc = value2c0;
    DAT_011ae5f0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Holder_00801ad0 *>(&::g_011db778))))));
    DAT_011ae5f4 = 1.0f;
    DAT_012007ec = flag ? 1 : 0;
}

struct Obj9
{
};
struct Mid9
{
};
struct PtrObj9
{
    PtrObj9(int);
    ~PtrObj9();
    int v;
};
struct Wrap9
{
    PtrObj9* p;
    Wrap9(PtrObj9* q) : p(q)
    {}
};
struct Inner9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void* vt9c(PtrObj9*);
};
struct Node9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual Mid9* vt180();
};
struct Mgr9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual Obj9* vt190(int);
};
struct Actor9
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual bool vt100();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vtbl115();
    virtual Inner9* vt1d0();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual int vt1e8();
};

struct Svc9
{
};
struct X10
{
};
struct Sub9
{
    int v;
};
struct P2Obj
{
};
struct This9
{
    int state;
    Actor9* actor;
    Sub9 sub08;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    unsigned char unk128;
    unsigned char b129;
    unsigned char unk12a;
    unsigned char unk12b;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int f23c;
    int f240;
    int arr244[8];
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    unsigned char b2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    Sub9 sub2cc;
};

// @fnv 0x00801450
void Struct801420::FUN_00801450(unsigned char a, int b)
{
    if (((This9*)this)->actor)
    {
        if ((((This9*)this)->b129 && !(((This9*)this)->b2b4) || a) && b != 1)
            reinterpret_cast<::EquipVisibility *>((((This9*)this)))->UpdateEquipmentVisibility();
        VRenderer* ptr12 = ((::VRenderer *)(::FUN_0043c4b0()));
        P2Obj* q23 = ((::P2Obj *)(::FUN_0045c670()));
        Actor9* actor_ = ((This9*)this)->actor;
        X10* x102 = ((::X10 *)(reinterpret_cast<::MiddleLowProcess *>((q23))->GetProcessInteger()));
        reinterpret_cast<::FUN_004a0fd0_shell *>((x102))->FUN_004a0fd0((::NiNode *)(::FUN_00559450((int *)&(((This9*)this)->sub2cc))));
        reinterpret_cast<::BGSExplosion *>((x102))->FUN_004fb0b0((::BGSImpactDataSet *)(1));
        Svc9* svcX = ((::Svc9 *)(reinterpret_cast<::BSFaceGenNiNode *>((q23))->GetAnimationData()));
        Mgr9* mgr2X = 0;
        Obj9* o1z = 0;
        if (((This9*)this)->actor->vt100())
            mgr2X = ((::Mgr9 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor_))->GetBaseTexture()));
        if (mgr2X)
            o1z = mgr2X->vt190(actor_->vt1e8());
        if (((This9*)this)->f23c == 0xe || b == 1)
        {
            if (((This9*)this)->actor->vt100())
            {
                if (!(((This9*)this)->b2b4) || a)
                {
                    if (o1z && mgr2X)
                        ::FUN_00b6bee0(svcX, o1z, (::BSShaderAccumulator *)(x102));
                }
            }
        }
        if (((This9*)this)->f23c != 0xe || b == 1)
        {
            bool flag_ = 0;
            if (o1z)
            {
                flag_ = !reinterpret_cast<::FUN_00456630_helper *>((o1z))->FUN_00456610();
                reinterpret_cast<::TaskQueueInterface *>((o1z))->QueueActorDisarm(1);
            }
            ::FUN_00b6bee0(svcX, (void*)::FUN_00559450((int *)&(((This9*)this)->sub08)), (::BSShaderAccumulator *)(x102));
            if (((This9*)this)->actor->vt100())
            {
                Actor9* formA = ((This9*)this)->actor;
                Mid9* xmidX = ((::Node9 *)(reinterpret_cast<::Actor *>((formA))->GetActorBase()))->vt180();
                Obj9* rAX = ((::Obj9 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((xmidX))->GetValueByIndex(((This9*)this)->f23c)));
                void* res3cA;
                if (rAX)
                {
                    res3cA = formA->vt1d0()->vt9c(&ResultSlot(PtrObj9(((int)(reinterpret_cast<::StrOwner *>((rAX))->FUN_007fa950())))));
                    if (res3cA)
                        ::FUN_00b6bee0(svcX, res3cA, (::BSShaderAccumulator *)(x102));
                }
                if (((This9*)this)->f240 > 0)
                {
                    for (int i = 0; i < ((This9*)this)->f240; i++)
                    {
                        Mid9* m3A = ((::Node9 *)(reinterpret_cast<::Actor *>((formA))->GetActorBase()))->vt180();
                        Obj9* ares44C = ((::Obj9 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((m3A))->GetValueByIndex(((This9*)this)->arr244[i])));
                        void* res4c_;
                        if (ares44C)
                        {
                            res4c_ = formA->vt1d0()->vt9c(&ResultSlot(PtrObj9(((int)(reinterpret_cast<::StrOwner *>((ares44C))->FUN_007fa950())))));
                            if (res4c_)
                                ::FUN_00b6bee0(svcX, res4c_, (::BSShaderAccumulator *)(x102));
                        }
                    }
                }
            }
            if (o1z && flag_)
                reinterpret_cast<::TaskQueueInterface *>((o1z))->QueueActorDisarm(0);
        }
        ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(svcX), (::BSShaderAccumulator *)(::FUN_00559450((int *)&(((This9*)this)->sub2cc))), 0);
        reinterpret_cast<::FUN_004a0fd0_shell *>((x102))->FUN_004a0fd0((::NiNode *)(0));
        reinterpret_cast<::BGSExplosion *>((x102))->FUN_004fb0b0((::BGSImpactDataSet *)(0));
        if ((((This9*)this)->b129 && !(((This9*)this)->b2b4) || a) && b != 1)
            reinterpret_cast<::This8022 *>((((This9*)this)))->FUN_008022c0();
        (void)ptr12;
    }
}
#include "generated/data/fallout/interface/fovatseffectmanager.inc"
#include "generated/data/fallout/interface/fovatseffectmanager_od_variant.inc"
