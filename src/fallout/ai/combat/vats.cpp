// fallout/ai/combat/vats.cpp: VATS, PlayerCharacter, SoundListView, ListHolder and more (26 functions)

#include <new>
#include "fnv/decl/AnimSwap.h"
#include "fnv/decl/B8C4890Actor.h"
#include "fnv/decl/BSAnimGroupSequence.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CameraState.h"
#include "fnv/decl/CheckerL8.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f00e0_shell.h"
#include "fnv/decl/FUN_005081b0_shell.h"
#include "fnv/decl/FUN_0058d630_shell.h"
#include "fnv/decl/FUN_005ff160_shell.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0070f490_Class.h"
#include "fnv/decl/FUN_0088b030_shell.h"
#include "fnv/decl/FUN_008b70d0_shell.h"
#include "fnv/decl/FUN_0093e840_shell.h"
#include "fnv/decl/FUN_0095f530_shell.h"
#include "fnv/decl/FUN_009c8600_Class.h"
#include "fnv/decl/FUN_009c8870_Class.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/IdleAnimationManager.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/Outer.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/SightActor.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004937c0__TESAnimGroup.h"
#include "fnv/decl/fnv_004937e0__TESAnimGroup.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00950110__FUN_00950110_pc.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004e6000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_006d3000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00771000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_009b5000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "vats_decls.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S819.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005db000.h"
#include <xmmintrin.h>

// @fnv 0x0093e770
void VATS::Update(int mode, bool force)
{
    reinterpret_cast<::FUN_0093e840_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->ApplyGlobalTimeMultiplier();
    if (reinterpret_cast<PlayerCharacter*>(this)->GetAnimation(
            !reinterpret_cast<::FUN_004eaf60_shell *>((reinterpret_cast<PlayerCharacter*>(this)))->FUN_004eaf60()))
    {
        reinterpret_cast<::FUN_0088b030_shell *>((reinterpret_cast<PlayerCharacter*>(this)->GetAnimation(!reinterpret_cast<::FUN_004eaf60_shell *>((reinterpret_cast<PlayerCharacter*>(this)))->FUN_004eaf60())))->FUN_0088b030(1.0f);
    }
    if (mode == 2 && (force || !((bool)(::IsStartMenuFlag1Set()))))
    {
        reinterpret_cast<::FUN_0095f530_shell *>((reinterpret_cast<CameraPathManager*>(::_g_thePlayer)))->FUN_0095f530((::TESObjectREFR *)(false), (::TESObjectREFR *)(3));
        reinterpret_cast<::VATS *>((reinterpret_cast<InventoryStackRecord*>(&(*reinterpret_cast<::VATS *>(&::g_011f2250)))))->FUN_009c8950(false, true);
        reinterpret_cast<BGSCameraShot*>(&(*reinterpret_cast<::VATS *>(&::g_011f2250)))->ResetCameraShot();
        reinterpret_cast<NiPoint3Interpolator*>(&(*reinterpret_cast<::VATS *>(&::g_011f2250)))->CreateObject(0, true);
        DAT_011f21d0 = true;
    }
    reinterpret_cast<PlayerCharacter*>(this)->fVATSTimer = 0.0f;
}

// @fnv 0x009c8cc0
float VATS::GetModeTimeMultiplier()
{
    float multiplier = 1.0f;
    if (eMode == 4)
    {
        if (pCamera && !reinterpret_cast<::FUN_0058d630_shell *>((pCamera))->FUN_0058d630())
            multiplier = 1.0f;
        else if (pCamera && reinterpret_cast<::FUN_00639aa0_shell *>((pCamera))->FUN_00639aa0() > 0.0)
            multiplier = reinterpret_cast<::FUN_00639aa0_shell *>((pCamera))->FUN_00639aa0();
        else
            multiplier = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting537))))))->f;
    }
    multiplier *= FUN_009443f0() / ::FUN_00716440();
    return multiplier;
}

struct BooleanFloatQuery;
struct TESObjectREFR;
struct VATSCommand
{
    void Initialize();
    void* __vecDelDtor(unsigned int);
    int eAction;
    bool bSuccess;
    bool m_kFieldAfterWeaponFlags;
    bool m_bFirstActionFlag;
    bool m_bSecondActionFlag;
    unsigned char m_ucFirstActionCode;
    unsigned char m_ucSecondActionCode;
    char _pad_a[2];
    TESObjectREFR* pTarget;
    int m_iActionValue;
    BooleanFloatQuery* m_pActionObject;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fOverrideActionPoints;
    bool m_bFinalActionFlag;
    char _pad_25[3];
};
struct FUN_009ca410_shell : public VATS
{
    void ProcessVATSCommands();
};

struct PlayerCharacter;

struct Animation;

struct Actor
{
public:
    void UpdateActorPresentation();
};

struct FUN_00498910_shell
{
};

struct Node
{
    VATSCommand* item;
    Node* next;
};

struct FUN_009ca410_shell_base : public VATS
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};

struct StandIn
{
};

// @fnv 0x009ca410
void FUN_009ca410_shell::ProcessVATSCommands()
{
    if (*(void**)&this->m_pIdleForm)
    {
        reinterpret_cast<::Animation *>((((FUN_00498910_shell*)reinterpret_cast<::FUN_008b70d0_shell *>((void *)(((Actor*)DAT_011f21f0)))->FUN_008b70d0())))->SpecialIdleFree(true, false);
        *(void**)&this->m_pIdleForm = 0;
    }

    while (!((FUN_009ca410_shell_base*)this)->FUN_008256d0())
    {
        VATSCommand* pcommand = ((::Node *)(((::Vec3 *)(void *)(((FUN_009ca410_shell_base*)this)))))->item;
        VATSCommand* pItem = pcommand;
        VATSCommand* pItemCopy = pItem;
        pItemCopy ? reinterpret_cast<::FUN_009c8870_Class *>((((StandIn*)pItemCopy)))->FUN_009c8870(1) : 0;
        ((FUN_009ca410_shell_base*)this)->FUN_0063f7b0();
    }
}

extern float DAT_011afe74;
extern float DAT_011afe78;
extern unsigned char DAT_012677cc;

// Returns DAT_011afe78 when DAT_012677cc is set, otherwise DAT_011afe74.
// @fnv 0x009c8ef0
float __cdecl FUN_009c8ef0()
{
    float fResult;
    if (DAT_012677cc)
        fResult = DAT_011afe78;
    else
        fResult = DAT_011afe74;
    return fResult;
}

struct SoundListEntry;

struct SoundListView
{
    void AddTail(SoundListEntry* const&);
    void AddCommand(SoundListEntry* apCommand);
};

// @fnv 0x009c71a0
void SoundListView::AddCommand(SoundListEntry* apCommand)
{
    reinterpret_cast<::Callees *>(this)->FUN_00905820((void *)&(apCommand));
}

struct ListHolder
{
    bool _ref_008256d0();
    void* FUN_009c71c0();
};

// @fnv 0x009c71c0
void* ListHolder::FUN_009c71c0()
{
    if (!_ref_008256d0())
        return *(void**)((void *)(((::Vec3 *)(void *)this)));
    return 0;
}

struct MyList
{
    bool _ref_008256d0();
    VATSCommand* FUN_009c71f0();
};
// @fnv 0x009c71f0
VATSCommand* MyList::FUN_009c71f0()
{
    MyList* iter;
    iter = this;
    while (iter && !iter->_ref_008256d0())
    {
        if (!((::MyList *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070())))
            return *((::VATSCommand **)(((::Vec3 *)(void *)(iter))));
        iter = ((::MyList *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
    }
    return 0;
}

struct bhkWorld
{
    static bool __cdecl QPickCountOverride();
};
float __cdecl FUN_009c8ef0();
extern float DAT_012677c4;
// Returns true when the pick count override is not active and FUN_009c8ef0() is less than DAT_012677c4; otherwise false.
// @fnv 0x009c8ea0
bool __cdecl FUN_009c8ea0()
{
    return !bhkWorld::QPickCountOverride() ? FUN_009c8ef0() < DAT_012677c4 : false;
}

struct FUN_009c9900_shell
{
    void SetByteAt76(unsigned char param_2);
};

// @fnv 0x009c9900
void FUN_009c9900_shell::SetByteAt76(unsigned char param_2)
{
    *reinterpret_cast<unsigned char*>(this + 0x76) = param_2;
}

struct FUN_009ca4a0
{
    FUN_009ca4a0();
};

struct Helper62d0
{
    Helper62d0& operator=(void const*);
};

struct FUN_009d9ec0_shell
{
    void AssignAtOffsetB0(void* p);
};

// @fnv 0x009d9ec0
void FUN_009d9ec0_shell::AssignAtOffsetB0(void* apValue)
{
    ((Helper62d0*)((char*)this + 0xb0))->operator=(apValue);
}

struct FUN_0063cfe0_Inner
{
    virtual ~FUN_0063cfe0_Inner();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct FUN_0063cfe0_shell
{
    char _pad_00[0x18];
    FUN_0063cfe0_Inner m_inner;
    void FUN_0063cfe0();
};

// @fnv 0x0063cfe0
void FUN_0063cfe0_shell::FUN_0063cfe0()
{
    m_inner.v5();
}

struct HUDMainMenu
{
};
struct VATS_COMMAND_LIST
{
    VATS_COMMAND_LIST();
    int iType;
    bool bFlag;
    char _pad_6[2];
    char _pad_8[4];
    PlayerCharacter* pOwner;
    char _pad_10[24];
    void CreateCommandAndUpdateHUD();
};
// @fnv 0x009ca1f0
void VATS_COMMAND_LIST::CreateCommandAndUpdateHUD()
{
    reinterpret_cast<::VATS *>((((InventoryStackRecord*)this)))->FUN_009c8950(false, false);
    VATS_COMMAND_LIST* pCommand = new VATS_COMMAND_LIST;
    pCommand->iType = 15;
    pCommand->bFlag = true;
    pCommand->pOwner = ::_g_thePlayer;
    ((SoundListView*)this)->AddCommand((SoundListEntry*)pCommand);
    ((NiPoint3Interpolator*)this)->CreateObject(4, false);
    ::fnv_00771700::FUN_00771700(4);
}


struct ActorX_S
{
};

struct BooleanFloatQuery
{
    void FUN_009b4dc0();
};


struct FUN_009c8e00_shell
{
    void FUN_009c8e00(VATSCommand* apCommand);
};

// @fnv 0x009c8e00
void FUN_009c8e00_shell::FUN_009c8e00(VATSCommand* apCommand)
{
    if (apCommand && FUN_0066dde0(apCommand->eAction))
    {
        if (apCommand->bSuccess && apCommand->pTarget && !FUN_009c8ea0())
        {
            if (!reinterpret_cast<::SightActor *>((((ActorX_S*)DAT_011f21f0)))->FUN_0088b880(1, (::SightActor *)(apCommand->pTarget), 1, (int *)(0), 0))
            {
                apCommand->bSuccess = false;
            }
        }

        if (apCommand->m_pActionObject)
        {
            apCommand->m_pActionObject->FUN_009b4dc0();
        }

        ::SetContextInfo((::n9b::Ctx *)(apCommand->m_pActionObject), (::n9b::Info *)(apCommand));
    }
}

struct NiLight;
struct ShadowSceneLight;

struct _FUN_0052aa80_shell
{
    bool operator!=(int) const;
};

struct GO : _FUN_0052aa80_shell
{
    void operator=(void*);
};

struct ShadowSceneNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void vfn_dc(NiLight*, bool);

};

struct NiAdditionalGeometryData
{
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};

struct FUN_009c9a50_shell
{
    char pad_00[0x34];
    GO m_34;

    void SetLight(NiLight* apLight, bool abClear);
};

// @fnv 0x009c9a50
void FUN_009c9a50_shell::SetLight(NiLight* apLight, bool abClear)
{
    if (abClear && m_34 != 0)
    {
        m_34 = 0;
    }

    if (apLight)
    {
        m_34 = ((::ShadowSceneLight *)(reinterpret_cast<::fnv_00b5c940::SSNode *>((NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(apLight), true)));
        NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)->vfn_dc(apLight, true);
    }
}


struct FUN_009b4d90
{
    char pad[0x64];
    FUN_009b4d90();
};

struct FUN_009ca500_shell : public VATSCommand
{
    void FUN_009ca500();
};
// @fnv 0x009ca4a0
FUN_009ca4a0::FUN_009ca4a0()
{
    reinterpret_cast<::FUN_009ca500_shell *>(this)->FUN_009ca500();
}

// @fnv 0x009ca500
void FUN_009ca500_shell::FUN_009ca500()
{
    eAction = 0x16;
    bSuccess = false;
    m_kFieldAfterWeaponFlags = false;
    m_bFirstActionFlag = false;
    m_bSecondActionFlag = false;
    m_ucFirstActionCode = 0;
    m_ucSecondActionCode = 0;
    pTarget = 0;
    m_iActionValue = 0x4d;
    m_pActionObject = (BooleanFloatQuery*)new FUN_009b4d90();
    m_fArmorDamage = 0.0f;
    m_fOverrideActionPoints = 0.0f;
    m_fHealthDamage = 0.0f;
    m_bFinalActionFlag = false;
}

struct S_009c8c40_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

struct S_009c8c40
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_009c8c40_Item* unk10;
    int unk14;
    float unk18;
    int unk1C;
    int unk20;
    void SetValue(int a);
};



struct FUN_009c9e90_shell : public VATS
{
    void RemoveCommandsForTarget(TESObjectREFR* target);
};

// Clears DAT_011f21cc if it equals target, then walks the command list removing every command whose pTarget is target.
// @fnv 0x009c9e90
void FUN_009c9e90_shell::RemoveCommandsForTarget(TESObjectREFR* target)
{
    if (target == (*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011f21cc)))
        (*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011f21cc)) = 0;

    BSSimpleList<VATSCommand*>* current = &m_kCommandList;
    BSSimpleList<VATSCommand*>* previous = 0;
    while (current != 0 && !current->IsEmpty())
    {
        VATSCommand* command = current->GetItem();
        if (command->pTarget == target)
        {
            VATSCommand* temporary = command;
            VATSCommand* deleting = temporary;
            deleting ? reinterpret_cast<::FUN_009c8870_Class *>((reinterpret_cast<StandIn*>(deleting)))->FUN_009c8870(1) : 0;

            if (previous)
            {
                previous->Remove(command);
                current = previous->GetNext();
            }
            else
            {
                current->RemoveHead();
            }
        }
        else
        {
            previous = current;
            current = current->GetNext();
        }
    }
}

struct VatsCmd9c9
{
    int m_eRequestType;
};
struct VatsList9c9
{
    bool IsValidCommand(VatsCmd9c9* pkCmd);
};

// @fnv 0x009c9f60
bool VatsList9c9::IsValidCommand(VatsCmd9c9* pkCmd)
{
    VatsCmd9c9* pkCommand = pkCmd;
    if (!pkCommand)
        pkCommand = *((::VatsCmd9c9 **)(((::Vec3 *)(void *)this)));
    if (pkCommand)
    {
        switch (pkCommand->m_eRequestType)
        {
        case 0:
        case 1:
        case 2:
        case 16:
        case 17:
        case 20:
        case 21:
            return true;
        }
    }
    return false;
}

class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3();
public:
    float GetLengthSquared();
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

struct ThisStub
{
};

class TESObjectREFR
{
  public:
    virtual void _v0();
    virtual void _v1();
    virtual void _v2();
    virtual void _v3();
    virtual void _v4();
    virtual void _v5();
    virtual void _v6();
    virtual void _v7();
    virtual void _v8();
    virtual void _v9();
    virtual void _v10();
    virtual void _v11();
    virtual void _v12();
    virtual void _v13();
    virtual void _v14();
    virtual void _v15();
    virtual void _v16();
    virtual void _v17();
    virtual void _v18();
    virtual void _v19();
    virtual void _v20();
    virtual void _v21();
    virtual void _v22();
    virtual void _v23();
    virtual void _v24();
    virtual void _v25();
    virtual void _v26();
    virtual void _v27();
    virtual void _v28();
    virtual void _v29();
    virtual void _v30();
    virtual void _v31();
    virtual void _v32();
    virtual void _v33();
    virtual void _v34();
    virtual void _v35();
    virtual void _v36();
    virtual void _v37();
    virtual void _v38();
    virtual void _v39();
    virtual void _v40();
    virtual void _v41();
    virtual void _v42();
    virtual void _v43();
    virtual void _v44();
    virtual void _v45();
    virtual void _v46();
    virtual void _v47();
    virtual void _v48();
    virtual void _v49();
    virtual void _v50();
    virtual void _v51();
    virtual void _v52();
    virtual void _v53();
    virtual void _v54();
    virtual void _v55();
    virtual void _v56();
    virtual void _v57();
    virtual void _v58();
    virtual void _v59();
    virtual void _v60();
    virtual void _v61();
    virtual void _v62();
    virtual void _v63();
    virtual void _v64();
    virtual void _v65();
    virtual void _v66();
    virtual void _v67();
    virtual void _v68();
    virtual void _v69();
    virtual void _v70();
    virtual void _v71();
    virtual void _v72();
    virtual void _v73();
    virtual void _v74();
    virtual void _v75();
    virtual void _v76();
    virtual void _v77();
    virtual void _v78();
    virtual void _v79();
    virtual void _v80();
    virtual void _v81();
    virtual void _v82();
    virtual void _v83();
    virtual void _v84();
    virtual void _v85();
    virtual void _v86();
    virtual void _v87();
    virtual void _v88();
    virtual void _v89();
    virtual void _v90();
    virtual void _v91();
    virtual void _v92();
    virtual void _v93();
    virtual void _v94();
    virtual void _v95();
    virtual void _v96();
    virtual void _v97();
    virtual void _v98();
    virtual void _v99();
    virtual void _v100();
    virtual void _v101();
    virtual void _v102();
    virtual void _v103();
    virtual void _v104();
    virtual void _v105();
    virtual void _v106();
    virtual void _v107();
    virtual void _v108();
    virtual void _v109();
    virtual void _v110();
    virtual void _v111();
    virtual void _v112();
    virtual void _v113();
    virtual void _v114();
    virtual void _v115();
    virtual void _v116();
    virtual void _v117();
    virtual void _v118();
    virtual void _v119();
    virtual void _v120();
    virtual ThisStub* vfn_1e4();
    virtual void _v122();
    virtual void _v123();
    virtual void _v124();
    virtual NiPoint3* vfn_1f4();
    virtual void _v126();
    virtual void _v127();
    virtual void _v128();
    virtual void _v129();
    virtual void _v130();
    virtual void _v131();
    virtual void _v132();
    virtual void _v133();
    virtual void _v134();
    virtual void _v135();
    virtual void _v136();
    virtual void _v137();
    virtual void _v138();
    virtual void _v139();
    virtual void _v140();
    virtual void _v141();
    virtual void _v142();
    virtual void _v143();
    virtual void _v144();
    virtual void _v145();
    virtual void _v146();
    virtual void _v147();
    virtual void _v148();
    virtual void _v149();
    virtual void _v150();
    virtual void _v151();
    virtual void _v152();
    virtual void _v153();
    virtual void _v154();
    virtual void _v155();
    virtual void _v156();
    virtual void _v157();
    virtual void _v158();
    virtual void _v159();
    virtual void _v160();
    virtual void _v161();
    virtual void _v162();
    virtual void _v163();
    virtual void _v164();
    virtual void _v165();
    virtual void _v166();
    virtual void _v167();
    virtual void _v168();
    virtual void _v169();
    virtual void vfn_2a8(NiPoint3*);
    virtual void _v171();
    virtual void _v172();
    virtual void _v173();
    virtual void _v174();
    virtual void _v175();
    virtual void vfn_2c0(TESObjectREFR*);
};

class TESIdleForm
{
  public:
    virtual void _v0();
    virtual void _v1();
    virtual void _v2();
    virtual void _v3();
    virtual void _v4();
    virtual void _v5();
    virtual void _v6();
    virtual void _v7();
    virtual void _v8();
    virtual void _v9();
    virtual void _v10();
    virtual void _v11();
    virtual void _v12();
    virtual void _v13();
    virtual void _v14();
    virtual void _v15();
    virtual void _v16();
    virtual void _v17();
    virtual void _v18();
    virtual void _v19();
    virtual void _v20();
    virtual void _v21();
    virtual void _v22();
    virtual void _v23();
    virtual void _v24();
    virtual void _v25();
    virtual void _v26();
    virtual void _v27();
    virtual void _v28();
    virtual void _v29();
    virtual void _v30();
    virtual void _v31();
    virtual void _v32();
    virtual void _v33();
    virtual void _v34();
    virtual void _v35();
    virtual void _v36();
    virtual void _v37();
    virtual void _v38();
    virtual void _v39();
    virtual void _v40();
    virtual void _v41();
    virtual void _v42();
    virtual void _v43();
    virtual void _v44();
    virtual void _v45();
    virtual void _v46();
    virtual void _v47();
    virtual void _v48();
    virtual void _v49();
    virtual void _v50();
    virtual void _v51();
    virtual void _v52();
    virtual void _v53();
    virtual void _v54();
    virtual void _v55();
    virtual void _v56();
    virtual void _v57();
    virtual void _v58();
    virtual void _v59();
    virtual void _v60();
    virtual void _v61();
    virtual void _v62();
    virtual void _v63();
    virtual void _v64();
    virtual void _v65();
    virtual void _v66();
    virtual void _v67();
    virtual void _v68();
    virtual void _v69();
    virtual void _v70();
    virtual void _v71();
    virtual void _v72();
    virtual void _v73();
    virtual void _v74();
    virtual void _v75();
    virtual const char* GetEditorID();
};

class TemporaryEffect
{
  public:
};

struct TIM_008b2010
{
};

template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting548;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting554;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting555;

struct TESObjectWEAP;
struct FUN_008a1710_shell
{
    TESObjectWEAP* FUN_008a1710();
};

void PlayMysteriousStrangerMusic();

struct FUN_009c9280_shell : public VATS
{
    void ExecuteVATSMeleeAttack(VATSCommand* pCmd);
};

// @fnv 0x009c9280
void FUN_009c9280_shell::ExecuteVATSMeleeAttack(VATSCommand* pAttackCmd)
{
    if (pAttackCmd->m_ucFirstActionCode)
    {
        if ((TemporaryEffect*)DAT_011f21f0 == DAT_011f21e8 || (TemporaryEffect*)DAT_011f21f0 == DAT_011f21ec ||
            reinterpret_cast<::VatsList9c9 *>((this))->IsValidCommand((::VatsCmd9c9 *)(pAttackCmd)))
        {
            if (pAttackCmd->pTarget)
            {
                float fDistance = 0.0f;
                if (pAttackCmd->m_bFirstActionFlag)
                {
                    fDistance = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting548))))->f;
                    if (reinterpret_cast<::Outer *>((DAT_011f21e8))->FUN_008c4850() != 1.0)
                    {
                        reinterpret_cast<::B8C4890Actor *>((DAT_011f21e8))->SetProcessValue(1.0f);
                        reinterpret_cast<::Actor *>((DAT_011f21e8))->UpdateActorPresentation();
                        PlayMysteriousStrangerMusic();
                    }
                }
                else if (pAttackCmd->m_bFinalActionFlag)
                {
                    fDistance = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting548))))->f;
                    if (reinterpret_cast<::Outer *>((DAT_011f21ec))->FUN_008c4850() != 1.0)
                    {
                        reinterpret_cast<::B8C4890Actor *>((DAT_011f21ec))->SetProcessValue(1.0f);
                        reinterpret_cast<::Actor *>((DAT_011f21ec))->UpdateActorPresentation();
                        PlayMysteriousStrangerMusic();
                    }
                }
                else
                {
                    fDistance =
                        ::GetActorReach((::A69C0Actor *)(::Actor *)((Actor*)DAT_011f21f0), (::A69C0Weapon *)((int)((FUN_008a1710_shell*)DAT_011f21f0)->FUN_008a1710()));
                    if (!((FUN_008a1710_shell*)DAT_011f21f0)->FUN_008a1710())
                    {
                        fDistance *= ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting554))))->f;
                    }
                    else if (::FUN_006450c0(((FUN_008a1710_shell*)DAT_011f21f0)->FUN_008a1710()))
                    {
                        fDistance *= ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting555))))->f;
                    }
                }

                NiPoint3 targetPos;
                if ((TemporaryEffect*)DAT_011f21f0 == DAT_011f21e8 || (TemporaryEffect*)DAT_011f21f0 == DAT_011f21ec)
                {
                    reinterpret_cast<::Reference *>((((TESObjectREFR*)DAT_011f21f0)))->FUN_00575830((::Position *)&(*((TESObjectREFR*)::_g_thePlayer)->vfn_1f4()));
                }

                if (::BuildPathingRequest((::TESObjectREFR *)(DAT_011f21f0), pAttackCmd->pTarget, fDistance, &targetPos))
                {
                    ((TESObjectREFR*)DAT_011f21f0)->vfn_2a8(&targetPos);
                    ((TESObjectREFR*)DAT_011f21f0)->vfn_2c0(pAttackCmd->pTarget);
                    if (::_g_thePlayer == DAT_011f21f0 && !reinterpret_cast<::CheckerL8 *>((this))->FUN_009c8f20((::PackageL8 *)(pAttackCmd)))
                    {
                        ((TESObjectREFR*)DAT_011f21f0)->vfn_2a8(pAttackCmd->pTarget->vfn_1f4());
                        ((TESObjectREFR*)DAT_011f21f0)->vfn_2c0(pAttackCmd->pTarget);
                    }
                }
                else
                {
                    ((TESObjectREFR*)DAT_011f21f0)->vfn_2a8(pAttackCmd->pTarget->vfn_1f4());
                    ((TESObjectREFR*)DAT_011f21f0)->vfn_2c0(pAttackCmd->pTarget);
                }

                reinterpret_cast<::AnimSwap *>((((TESObjectREFR*)DAT_011f21f0)->vfn_1e4()))->FUN_00493bd0();
            }
        }

        this->m_pIdleForm = reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::TIM_008b2010 * *>(&::DAT_011cb6a0))))->FindIdleFormForObject((::TESObjectREFR *)(DAT_011f21f0), pAttackCmd->pTarget);
        if (this->m_pIdleForm)
        {
            if (reinterpret_cast<::FUN_005ff160_shell *>((this->m_pIdleForm))->GetFlagsMasked() != 4)
            {
                ::FUN_005b5e40(
                    );
                this->m_pIdleForm = 0;
            }
        }
    }
}

namespace fnv_009c9ae0 {
// 0x009c9ae0  unit_21e1906d19b4.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, 1 stack arg (ret 4) - VATS point-light update.

struct NiPoint3;
struct BaseProcess;
struct NiAVObject;
struct ActorObj9c9;

struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3(float ax, float ay, float az);
    NiPoint3* Set(float ax, float ay, float az);
    NiPoint3 operator+(NiPoint3 const& rhs) const;
    NiPoint3 operator-(NiPoint3 const& rhs) const;
    NiPoint3& operator*=(float afScale);
};

struct NiBound9c9
{
};

struct NiMatrix3_9c9
{
    float m_afEntries[9];
    NiMatrix3_9c9();
};

struct ActorObj9c9
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual unsigned char v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual ActorObj9c9* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* v125();

    NiBound9c9 const& FUN_0043d450() const;
};

struct LightTarget9c9
{
};
struct LightPtr9c9
{
};
struct FloatGlobal9c9
{
};
struct SettingS9c9
{
    float fValue;
};
struct SettingT9c9
{
};
struct ShadowSceneNode9c9
{
    float FUN_00b5b610(NiPoint3 kPos, int* piOut, float* pfA, float* pfB, NiPoint3 kPos2, NiAVObject* pkLight);
};

struct NiAVObject
{
    NiBound9c9 const& FUN_0043d450() const;
    void FUN_0050dd50(NiPoint3 const& krValue);
};

ShadowSceneNode9c9* FUN_00450b80(unsigned int auiArg);


struct VATS9c9
{
    char _pad00[0x34];
    LightPtr9c9 m_spVATSLight;

    void FUN_009c9ae0(ActorObj9c9* apActor);
};

// @fnv 0x009c9ae0
void VATS9c9::FUN_009c9ae0(ActorObj9c9* apActor)
{
    if (apActor->v064())
    {
        if (apActor->v116())
        {
            if (((::fnv_009c9ae0::LightTarget9c9 *)(::FUN_00559450((int *)&(m_spVATSLight)))))
            {
                ActorObj9c9* pOwner = apActor;
                if (((::fnv_009c9ae0::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pOwner))->GetBaseTexture())))
                {
                    NiPoint3 kCenter5 = (*(::fnv_009c9ae0::NiPoint3 *)(((::Vec3 *)(void *)&((*(const ::fnv_009c9ae0::NiBound9c9 *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(apActor->v116()))->FUN_0043d450()))))));
                    NiPoint3 aKDir = *(*reinterpret_cast<::fnv_009c9ae0::ActorObj9c9 * *>(&::DAT_011f21f0))->v125() - *apActor->v125();

                    NiMatrix3_9c9 kRotX;
                    reinterpret_cast<::FUN_004a0c90_shell *>(&(kRotX))->FUN_004a0c90(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_009c9ae0::FloatGlobal9c9 *>(&::g_011f2304))))->FUN_00450410());

                    reinterpret_cast<::FUN_004a0c10_s *>(&(aKDir))->FUN_004a0c10();
                    aKDir = (*(::fnv_009c9ae0::NiPoint3 *)(::FUN_004b3ae0((::NiPoint3 *)&(aKDir), (*(const ::NiPoint3 *)((float const*)&kRotX)), {})));
                    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::fnv_009c9ae0::NiPoint3 &)(aKDir))->FUN_00439180(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_009c9ae0::FloatGlobal9c9 *>(&::g_011f222c))))->FUN_00450410());

                    kCenter5 = kCenter5 + aKDir;
                    kCenter5.z += reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_009c9ae0::FloatGlobal9c9 *>(&::g_011f220c))))->FUN_00450410();

                    NiPoint3 kOffset5(((::fnv_009c9ae0::SettingS9c9 *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009c9ae0::SettingT9c9 *>(&::g_011f21f4))))))->fValue, ((::fnv_009c9ae0::SettingS9c9 *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009c9ae0::SettingT9c9 *>(&::g_011f22a8))))))->fValue,
                                      ((::fnv_009c9ae0::SettingS9c9 *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009c9ae0::SettingT9c9 *>(&::g_011f22cc))))))->fValue);

                    int iOutVal = 0;
                    float fA9 = 0.0f;
                    float fB_ = 0.0f;

                    NiPoint3 _kSpawn = *pOwner->v125() + NiPoint3(0.0f, 0.0f, reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(pOwner))->GetActorHeight());

                    float fScaleTmp =
                        FUN_00450b80(0)->FUN_00b5b610(_kSpawn, &iOutVal, &fA9, &fB_, *(*reinterpret_cast<::fnv_009c9ae0::ActorObj9c9 * *>(&::DAT_011f21f0))->v125(),
                                                      ((::fnv_009c9ae0::NiAVObject *)(::fnv_004e6540::FUN_004e6540((char *)(((::fnv_009c9ae0::LightTarget9c9 *)(::FUN_00559450((int *)&(m_spVATSLight))))))))) *
                        100.0;

                    float fRadiusTmp;
                    float _fRange = ::FUN_0040ebd0(
                        1.0f, ::FUN_00404010(0.0f, ::LinearInterpolate(1.0f, 0.0f, reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_009c9ae0::FloatGlobal9c9 *>(&::g_011f2298))))->FUN_00450410(),
                                                                   reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_009c9ae0::FloatGlobal9c9 *>(&::g_011f2200))))->FUN_00450410(), fScaleTmp)));

                    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::fnv_009c9ae0::NiPoint3 &)(kOffset5))->FUN_00439180(_fRange);

                    fRadiusTmp = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_009c9ae0::NiPoint3 &)((kCenter5 - (*(::fnv_009c9ae0::NiPoint3 *)(((::Vec3 *)(void *)&((*(const ::fnv_009c9ae0::NiBound9c9 *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(apActor->v116()))->FUN_0043d450())))))))))->ComputeMagnitude() * 2.0f;

                    reinterpret_cast<::FUN_004f00e0_shell *>((((::fnv_009c9ae0::NiAVObject *)(::fnv_004e6540::FUN_004e6540((char *)(((::fnv_009c9ae0::LightTarget9c9 *)(::FUN_00559450((int *)&(m_spVATSLight))))))))))->FUN_004f00e0(&kCenter5);
                    ((::fnv_009c9ae0::NiAVObject *)(::fnv_004e6540::FUN_004e6540((char *)(((::fnv_009c9ae0::LightTarget9c9 *)(::FUN_00559450((int *)&(m_spVATSLight))))))))->FUN_0050dd50(NiPoint3(fRadiusTmp, 0.0f, 0.0f));
                    reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((::fnv_009c9ae0::NiAVObject *)(::fnv_004e6540::FUN_004e6540((char *)(((::fnv_009c9ae0::LightTarget9c9 *)(::FUN_00559450((int *)&(m_spVATSLight))))))))))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(kOffset5));
                    reinterpret_cast<::TaskQueueInterface *>((((::fnv_009c9ae0::NiAVObject *)(::fnv_004e6540::FUN_004e6540((char *)(((::fnv_009c9ae0::LightTarget9c9 *)(::FUN_00559450((int *)&(m_spVATSLight))))))))))->QueueActorDisarm(false);
                }
            }
        }
    }
}
}  // namespace fnv_009c9ae0

namespace fnv_009c9fe0 {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 ApplyScaled(float fScale) const;
    NiPoint3 FUN_0053d280(float fScale) const;
};

struct Bound9c9
{
};

class NiAVObject
{
  public:
    const Bound9c9& FUN_0043d450() const;
};

struct Ref9c9
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual NiAVObject* GetNode();
    virtual void W117();
    virtual void W118();
    virtual void W119();
    virtual void W120();
    virtual void W121();
    virtual void W122();
    virtual void W123();
    virtual void W124();
    virtual NiPoint3* GetPos();
};

struct Cmd9c9
{
    int m_kNextStreamField[3];
    Ref9c9* m_pkTarget;
};

struct CmdList9c9
{
    NiPoint3 FUN_009c9fe0(float fDistance);
};

// @fnv 0x009c9fe0
NiPoint3 CmdList9c9::FUN_009c9fe0(float afScale)
{
    NiPoint3 kPlayerPos = *((::fnv_009c9fe0::NiPoint3 *)(((::Vec3 *)(void *)&((*(const ::fnv_009c9fe0::Bound9c9 *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(((::fnv_009c9fe0::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((Ref9c9*)DAT_011f21f0)))->FUN_0043fcd0()))))->FUN_0043d450()))))));
    Cmd9c9* pkCmd = *((::fnv_009c9fe0::Cmd9c9 **)(((::Vec3 *)(void *)this)));
    if ((pkCmd && pkCmd->m_pkTarget) || (*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011f21cc)))
    {
        NiPoint3 kTarget = (*reinterpret_cast<const ::fnv_009c9fe0::NiPoint3 *>((void *)&::NiPoint3::ZERO));
        if (pkCmd && pkCmd->m_pkTarget)
        {
            if (pkCmd->m_pkTarget->GetNode())
                kTarget = *((::fnv_009c9fe0::NiPoint3 *)(((::Vec3 *)(void *)&((*(const ::fnv_009c9fe0::Bound9c9 *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(pkCmd->m_pkTarget->GetNode()))->FUN_0043d450()))))));
            else
                kTarget = *pkCmd->m_pkTarget->GetPos();
        }
        else if ((*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011f21cc)))
        {
            if (((Ref9c9*)(*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011f21cc)))->GetNode())
                kTarget = *((::fnv_009c9fe0::NiPoint3 *)(((::Vec3 *)(void *)&((*(const ::fnv_009c9fe0::Bound9c9 *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(((Ref9c9*)(*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011f21cc)))->GetNode()))->FUN_0043d450()))))));
            else
                kTarget = *((Ref9c9*)(*reinterpret_cast<::TESObjectREFR * *>(&::DAT_011f21cc)))->GetPos();
        }
        NiPoint3 kDirection = (*(::fnv_009c9fe0::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kTarget))->FUN_00439ef0((::NiPoint3 *)&(kPlayerPos), *(const ::NiPoint3 *)nullptr)));
        float fScaleMultiplier = reinterpret_cast<::NiPoint3 *>(&(kDirection))->GetLengthSquared();
        reinterpret_cast<::FUN_0063c8a0_shell *>(&(kPlayerPos))->FUN_0063c8a0((void *)&(const ::fnv_009c9fe0::NiPoint3 &)(kDirection.ApplyScaled(fScaleMultiplier).ApplyScaled(afScale).FUN_0053d280(100.0f)));
    }
    return kPlayerPos;
}
}  // namespace fnv_009c9fe0

struct FUN_009c95e0_Pt3
{
    float x;
    float y;
    float z;
    FUN_009c95e0_Pt3 operator-(const FUN_009c95e0_Pt3& o) const;
};
struct FUN_009c95e0_Ref
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual FUN_009c95e0_Pt3 Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual FUN_009c95e0_Pt3* GetPos();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual bool Unk_8B(bool a);
};
struct FUN_009c95e0_AnimGroup
{
};
struct FUN_009c95e0_Seq
{
};
struct FUN_009c95e0_Anim
{
};
struct FUN_009c95e0_Player
{
};
struct FUN_009c95e0_Camera
{
};
struct FUN_009c95e0_Command
{
    int eAction;
    int unk04;
    unsigned char m_ucFirstActionCode;
    FUN_009c95e0_Ref* pTarget;
};
struct FUN_009c95e0_Dist
{
};

struct FUN_009c95e0_VATS
{
    int unk00;
    int unk04;
    int eMode;
    int m_pCameraShotList;
    FUN_009c95e0_Camera* pCamera;
    float m_fCameraTime;
    float m_fCameraDuration;
    FUN_009c95e0_Ref* m_pSource;
    FUN_009c95e0_Ref* m_pTargetProjectile;
    void HandleCommand(FUN_009c95e0_Command* command);
};

struct Ref_ca2c0 : public TESObjectREFR
{
};

struct HitData_ca2c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    void SetFlag(int flag, bool val);
};

struct BaseProcess_ca2c0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual Ref_ca2c0* GetTarget();
};

struct Player_ca2c0 : public PlayerCharacter
{
};

struct VatsCmd_ca2c0 : public VATSCommand
{
    VatsCmd_ca2c0();
};

struct VATS_ca2c0 : public VATS
{
    void FUN_009ca2c0(TESObjectREFR* a1, int a2);
};

// Creates a VATS command targeting a1, sets its action, success, and hit data, then queues it and updates the VATS state.
// @fnv 0x009ca2c0
void VATS_ca2c0::FUN_009ca2c0(TESObjectREFR* apTarget, int a2)
{
    reinterpret_cast<::VATS *>(this)->FUN_009c8950(false, false);
    VATSCommand* cmd = new VatsCmd_ca2c0();
    cmd->eAction = 0x12;
    cmd->bSuccess = true;
    cmd->pTarget = apTarget;
    if (a2 == -1)
    {
        a2 = 0;
    }
    ((HitData_ca2c0*)cmd->m_pActionObject)->unk10 = a2;
    if (((::BaseProcess_ca2c0 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Player_ca2c0*)::_g_thePlayer)))->GetBaseTexture())) &&
        ((::BaseProcess_ca2c0 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Player_ca2c0*)::_g_thePlayer)))->GetBaseTexture()))->GetTarget())
    {
        unsigned int flags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((::BaseProcess_ca2c0 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Player_ca2c0*)::_g_thePlayer)))->GetBaseTexture()))->GetTarget()))->GetName()));
        ((HitData_ca2c0*)cmd->m_pActionObject)->unk30 = flags;
    }
    ((HitData_ca2c0*)cmd->m_pActionObject)->SetFlag(0x10, true);
    DAT_011f21f0 = ::_g_thePlayer;
    reinterpret_cast<::SoundListView *>(this)->AddCommand((::SoundListEntry *)(cmd));
    reinterpret_cast<::NiPoint3Interpolator *>(this)->CreateObject(4, false);
}

class GlobalObject2_0040c150
{
  public:
};
extern GlobalObject2_0040c150 g_011ce7e4;

class TemporaryEffect;

struct TESObjectREFRV7
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
    virtual bool GetDead(bool);
};

struct VATS_COMMAND_Del : public VATSCommand
{
    ~VATS_COMMAND_Del();
};

struct FUN_009c86b0_shell : public FUN_009ca410_shell_base
{
    void FUN_009c86b0();
};

// Deletes the current command, removes commands meeting the target checks, then sets player state and triggers action callbacks.
// @fnv 0x009c86b0
void FUN_009c86b0_shell::FUN_009c86b0()
{
    if (FUN_008256d0())
    {
        return;
    }
    VATSCommand* pCmd = ((::Node *)(((::Vec3 *)(void *)this)))->item;
    if (pCmd)
    {
        delete (VATS_COMMAND_Del*)pCmd;
        pCmd = 0;
        FUN_0063f7b0();
        if (m_pIdleForm)
        {
            reinterpret_cast<::Animation *>((((FUN_00498910_shell*)reinterpret_cast<::FUN_008b70d0_shell *>((void *)(((Actor*)DAT_011f21f0)))->FUN_008b70d0())))->SpecialIdleFree(true, false);
            m_pIdleForm = 0;
        }
        while (!FUN_008256d0())
        {
            pCmd = ((::Node *)(((::Vec3 *)(void *)this)))->item;
            bool bRemove = false;
            if (pCmd && pCmd->pTarget)
            {
                if (((TESObjectREFRV7*)pCmd->pTarget)->GetDead(false))
                {
                    bRemove = true;
                }
                else if (pCmd->m_bFirstActionFlag)
                {
                    if (reinterpret_cast<::HealthReferenceEntry *>((((TESObjectREFRV7*)pCmd->pTarget)))->FUN_00568ad0() > *((int *)&(::FUN_0043d4d0((int *)&(g_011ce7e4)))))
                    {
                        bRemove = true;
                    }
                }
            }
            if (bRemove)
            {
                delete (VATS_COMMAND_Del*)pCmd;
                pCmd = 0;
                FUN_0063f7b0();
            }
            else
            {
                break;
            }
        }
        if (pCmd && pCmd->m_bFirstActionFlag)
        {
            DAT_011f21f0 = (PlayerCharacter*)DAT_011f21e8;
            ::TopicMenuController::IncrementMiscStat(25);
        }
        if (pCmd && pCmd->m_bFinalActionFlag)
        {
            DAT_011f21f0 = (PlayerCharacter*)DAT_011f21ec;
            ::TopicMenuController::IncrementMiscStat(28);
        }
    }
}

struct CameraShotExtra : ::BGSCameraShot
{
};
struct CameraDisplayManager
{
};

struct FUN_009c9920_shell : ::VATS
{
    bool FUN_009c9920();
};
// @fnv 0x009c8c40
void S_009c8c40::SetValue(int a)
{
    unk20 = a;
    if (unk10 != 0)
    {
        reinterpret_cast<::FUN_009c95e0_VATS *>(this)->HandleCommand((::FUN_009c95e0_Command *)(void *)(reinterpret_cast<::ListHolder *>(this)->FUN_009c71c0()));
        if (unk18 == 0.0)
        {
            bool ok = true;
            while (unk10 != 0 && ok && DAT_011f21b8 > ::GetField38((char *)(unk10)))
                ok = reinterpret_cast<::FUN_009c9920_shell *>(this)->FUN_009c9920();
        }
    }
}
// Processes a VATS command, updating the camera state flag DAT_011f21b8 based on validity, animation, and target distance checks.
// @fnv 0x009c95e0
void FUN_009c95e0_VATS::HandleCommand(FUN_009c95e0_Command* command)
{
    if (reinterpret_cast<::VatsList9c9 *>(this)->IsValidCommand((::VatsCmd9c9 *)(command)))
    {
        FUN_009c95e0_Anim* animation = ((::FUN_009c95e0_Anim *)(reinterpret_cast<::FUN_008b70d0_shell *>((((FUN_009c95e0_Player*)DAT_011f21f0)))->FUN_008b70d0()));
        if (DAT_011f21b8 == 0)
        {
            FUN_009c95e0_Seq* sequence = ((::FUN_009c95e0_Seq *)(reinterpret_cast<::FUN_00491040_shell *>((animation))->FUN_00491040(4)));
            if (!sequence || (reinterpret_cast<::fnv_004937c0::TESAnimGroup *>((((::FUN_009c95e0_AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((sequence))->GetAnimGroup()))))->FUN_004937c0() && command->m_ucFirstActionCode == 0) ||
                (reinterpret_cast<::fnv_004937e0::TESAnimGroup *>((((::FUN_009c95e0_AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((sequence))->GetAnimGroup()))))->FUN_004937e0() && reinterpret_cast<::FUN_0070f490_Class *>((animation))->GetSlotValue(4) >= 1))
            {
                DAT_011f21b8 = 2;
            }
            else if (command->pTarget)
            {
                if (command->pTarget->Unk_8B(false))
                    DAT_011f21b8 = 2;
            }
            if (DAT_011f21b8 == 2)
            {
                if (m_fCameraDuration == 0.0)
                {
                    bool flag = true;
                    while (flag && DAT_011f21b8 > ::GetField38((char *)(pCamera)))
                        flag = reinterpret_cast<::FUN_009c9920_shell *>(this)->FUN_009c9920();
                }
            }
        }
        return;
    }
    if (command && command->eAction == 0x12)
    {
        DAT_011f21b8 = 2;
        reinterpret_cast<::FUN_009c9900_shell *>((pCamera))->SetByteAt76(1);
        return;
    }
    if (m_pSource && DAT_011f21b8 == 0)
        DAT_011f21b8 = 1;
    if (m_pSource || m_pTargetProjectile)
    {
        if (!m_pSource)
            DAT_011f21b8 = 2;
        else if (m_pSource && m_pTargetProjectile && (!pCamera || ::GetField38((char *)(pCamera)) == 2))
            DAT_011f21b8 = 2;
        else
        {
            FUN_009c95e0_Pt3 ptOffset = *command->pTarget->GetPos() - *m_pSource->GetPos();
            if (reinterpret_cast<::NiPoint3 *>((void *)&(ptOffset))->ComputeMagnitude() < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_009c95e0_Dist *>(&::g_011cf81c)))))) + command->pTarget->Unk_77().y)
                DAT_011f21b8 = 2;
            else if (m_pTargetProjectile)
            {
                ptOffset = *command->pTarget->GetPos() - *m_pTargetProjectile->GetPos();
                if (reinterpret_cast<::NiPoint3 *>((void *)&(ptOffset))->ComputeMagnitude() < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::FUN_009c95e0_Dist *>(&::g_011cf81c)))))) + command->pTarget->Unk_77().y)
                    DAT_011f21b8 = 2;
            }
        }
    }
    else if (DAT_011f21b8 == 1)
        DAT_011f21b8 = 2;
}
// Advances the camera shot list past the current shot, updates m_fCameraDuration, and notifies the display manager or sets DAT_011f21d3.
// @fnv 0x009c9920
bool FUN_009c9920_shell::FUN_009c9920()
{
    ::BSSimpleList< ::BGSCameraShot*>* nextCamera = m_pCameraShotList;
    bool found = false;
    while (nextCamera && (((nextCamera))->m_item) != pCamera)
    {
        nextCamera = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((nextCamera))->FUN_00726070()));
    }
    if (nextCamera)
    {
        nextCamera = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((nextCamera))->FUN_00726070()));
    }
    if (nextCamera)
    {
        if (pCamera)
        {
            reinterpret_cast<::CameraState *>((static_cast<CameraShotExtra*>(pCamera)))->ResetCameraState();
            pCamera = 0;
        }
        pCamera = (((nextCamera))->m_item);
        if (pCamera && m_fCameraDuration < reinterpret_cast<::FUN_005081b0_shell *>((static_cast<CameraShotExtra*>(pCamera)))->GetFloatAtOffset58())
        {
            m_fCameraDuration = reinterpret_cast<::FUN_005081b0_shell *>((static_cast<CameraShotExtra*>(pCamera)))->GetFloatAtOffset58();
        }
        if (pCamera && reinterpret_cast<::FUN_009c8600_Class *>((static_cast<CameraShotExtra*>(pCamera)))->FUN_009c8600())
        {
            reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>(((*reinterpret_cast<::CameraDisplayManager * *>(&::_g_thePlayer))))->FUN_00950110(true);
        }
        else
        {
            (*reinterpret_cast<unsigned char *>(&::DAT_011f21d3)) = 1;
        }
        found = true;
    }
    else if (!nextCamera && pCamera && !reinterpret_cast<::FUN_0058d630_shell *>((pCamera))->FUN_0058d630())
    {
        reinterpret_cast<::CameraState *>((static_cast<CameraShotExtra*>(pCamera)))->ResetCameraState();
        pCamera = 0;
    }
    return found;
}

bool __cdecl FUN_009c8ea0();
class NiPoint3L8
{
  public:
    float x;
    float y;
    float z;
};

class HitResultsL8
{
  public:
    HitResultsL8();
    ~HitResultsL8();
    __m128 m_akData[50];
};

class HitL8
{
  public:
    HitL8(void* pvHit);
    __m128 m_akPad[5];
    void* m_pvCollidable;
    int m_aiPad[3];
};

class HitListL8
{
  public:
    void* GetAt(int iIndex);
};

class HitArrayL8
{
  public:
};

class PickFlagsL8
{
  public:
    PickFlagsL8(int iValue);
    int m_iValue;
};

class PickQueryL8
{
  public:
    PickQueryL8();
    void SetFlags(PickFlagsL8 kFlags);
    __m128 m_akData[11];
};

class WorldL8
{
  public:
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w00a();
    virtual void w00b();
    virtual void w00c();
    virtual void w00d();
    virtual void w00e();
    virtual void w00f();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w01a();
    virtual void w01b();
    virtual void w01c();
    virtual void w01d();
    virtual void w01e();
    virtual void w01f();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w02a();
    virtual void w02b();
    virtual void w02c();
    virtual void w02d();
    virtual void w02e();
    virtual void w02f();
    virtual void w030();
    virtual void w031();
    virtual bool Pick(PickQueryL8& kQuery);
};

class CellL8
{
  public:
};

class ProjL8
{
  public:
};

class RefL8
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual const NiPoint3L8* GetPos();
};

class PackageL8
{
  public:
    char m_acPad[0xc];
    RefL8* m_pkTarget;
};



// @fnv 0x009c8f20
bool CheckerL8::FUN_009c8f20(PackageL8* pkPackage)
{
    RefL8* pkTarget = 0;
    if (pkPackage->m_pkTarget->IsActor())
        pkTarget = pkPackage->m_pkTarget;
    if (!pkTarget)
        return false;
    WorldL8* pkWorld = ((::CellL8 *)(reinterpret_cast<::LowProcess *>((pkTarget))->GetTarget())) ? ((::WorldL8 *)(reinterpret_cast<::FUN_004543c0_cls *>((((::CellL8 *)(reinterpret_cast<::LowProcess *>((pkTarget))->GetTarget()))))->FUN_004543c0())) : 0;
    if (!pkWorld)
        return false;
    unsigned int uiMask = 0x26206;
    ::ShadowLightData::SetTargetMaskForSelection(0x27, uiMask);
    NiPoint3L8 kFrom = *(*reinterpret_cast<::RefL8 * *>(&::DAT_011f21f0))->GetPos();
    NiPoint3L8 kTo = *pkTarget->GetPos();
    kFrom.z += 60.0;
    kTo.z += 60.0;
    PickQueryL8 kQuery;
    PickFlagsL8 kFlags(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(kFlags))->FUN_004a39f0(0x27);
    RefL8* pkActor = pkTarget->IsActor() ? pkTarget : 0;
    if (pkActor && ((::ProjL8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pkActor))->FUN_009306d0())))
        reinterpret_cast<::FUN_0059ce80_shell *>(&(kFlags))->FUN_0059ce80((unsigned int)(((void *)(reinterpret_cast<::S819 *>((((::ProjL8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pkActor))->FUN_009306d0()))))->FUN_00819250()))));
    else
        reinterpret_cast<::FUN_0059ce80_shell *>(&(kFlags))->FUN_0059ce80((unsigned int)(((void *)(::FUN_005dbe10()))));
    kQuery.SetFlags(kFlags);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(kQuery))->FUN_004a3da0((void *)&(kFrom));
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(kQuery))->FUN_004a3eb0((void *)&(kTo));
    HitResultsL8 kResults;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(kQuery))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::HitResultsL8 *)(&kResults));
    bool bPickResultFound = false;
    pkWorld->Pick(kQuery);
    for (int i = 0; !bPickResultFound && i < ((int)(reinterpret_cast<::Callees *>((((::HitListL8 *)(::FUN_00460140((int)(((::HitArrayL8 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(kQuery))->FUN_008cdd90()))))))))->FUN_00726070())); i++)
    {
        HitL8 kHit(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitListL8 *)(::FUN_00460140((int)(((::HitArrayL8 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(kQuery))->FUN_008cdd90()))))))))->GetEntryAt(i))));
        void* pvCollidable = ((void *)(::FUN_004b5820((::FormLike *)(kHit.m_pvCollidable))));
        RefL8* pkRef = ((::RefL8 *)(::FUN_0056f930((::NiAVObject *)(pvCollidable))));
        if (pvCollidable)
        {
            if (pkRef == pkTarget || pkRef == (*reinterpret_cast<::RefL8 * *>(&::DAT_011f21f0)))
                continue;
            else
                return false;
        }
    }
    return true;
}
#include "generated/data/fallout/ai/combat/vats.inc"
