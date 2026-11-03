// fallout/magic/scripteffect.cpp: ScriptEffect, ScriptEffectShell (14 functions)

#include <new>
#include "fnv/decl/ActiveEffectLoader.h"
#include "fnv/decl/ActiveEffectSaveShell.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CopyOwner.h"
#include "fnv/decl/EffectSaveShell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_005a9290_shell.h"
#include "fnv/decl/FUN_005a9d00_shell.h"
#include "fnv/decl/FUN_005ac340_t.h"
#include "fnv/decl/FUN_005ac380.h"
#include "fnv/decl/FUN_00804f80_shell.h"
#include "fnv/decl/FUN_00806420_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/LoadScriptLocals.h"
#include "fnv/decl/SaveLocals9db0.h"
#include "fnv/decl/ThisX.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_005a9f20__FUN_005a9f20_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_005a9000.h"
#include "fnv/symbols_011de000.h"
#include "scripteffect_decls.h"
// @fnv 0x00827bd0
void ScriptEffect::Update(float elapsed)
{
    if (pScript)
    {
        pScript->AdvanceScript(((MagicTarget*)((ActorMover*)this)->GetCurrentMoveModeType())->GetActor(),
                               m_pScriptLocals, elapsed);
    }
}
struct T8277c0
{
    void FUN_008277f0();
    void* DestroyIfFlagged(unsigned int);
};
struct Actor;
struct TESForm
{
    virtual void Revert(unsigned int);
};
struct ScriptLocalsCall
{
};
struct FUN_00827de0_shell : TESForm
{
    char _pad[0x48];
    ScriptLocalsCall* m_pScriptLocals;
    void FUN_00827de0(Actor* apActor);
};
// Reverts the form, then if a script-locals call object is set, invokes its FUN_005a9d00 method.
// @fnv 0x00827de0
void FUN_00827de0_shell::FUN_00827de0(Actor* apActor)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((unsigned int)apActor);
    if (m_pScriptLocals)
        reinterpret_cast<::FUN_005a9d00_shell *>((m_pScriptLocals))->FUN_005a9d00();
}


struct ScriptLocalVariable
{
    unsigned int uiID;
    double fValue;
    bool m_bIsString;
};

struct SCRIPT_LOCAL_LIST
{
    ScriptLocalVariable* item;
    SCRIPT_LOCAL_LIST* next;
    bool FUN_008256d0();
};

struct ScriptLocals_0084e3a0
{
};

struct ScriptLocals_005a8f40
{
};

struct ScriptLocals_SetVariable
{
};

struct ActiveEffect_CopyData
{
};

struct FUN_00827930_shell : ScriptEffect
{
    void CopyScriptEffectData(ActiveEffect* apDestination);
};

struct ScriptEventListStub
{
    int a;
    int b;
};

struct FUN_00803ed0
{
    virtual ~FUN_00803ed0();
};
struct FUN_008277f0 : FUN_00803ed0
{
    ~FUN_008277f0();
};
// Calls FUN_008277f0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x008277c0
void* T8277c0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_008277f0 *>(this)->FUN_008277f0::~FUN_008277f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that deletes the ScriptLocals object stored at offset 0x4c if it is non-null.
// @fnv 0x008277f0
FUN_008277f0::~FUN_008277f0()
{
    if (reinterpret_cast<ScriptLocals*>(
            *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x4c)))
        delete reinterpret_cast<ScriptLocals*>(
            *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x4c));
}

struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct FUN_00827a40_shell : ScriptEffect
{
    FUN_00827a40_shell(MagicCaster*, MagicItem*, EffectItem*);
};
// Allocates and constructs a ScriptEffect shell from the caster, magic item and effect item.
// @fnv 0x00827a40
FUN_00827a40_shell* CreateScriptEffect(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect)
{
    return new FUN_00827a40_shell(apCaster, apItem, apEffect);
}

struct TESSaveLoadGame
{
};
struct ScriptEffect_GetSaveSize_Helper
{
};
struct FUN_005a94f0_shell
{
};
struct FUN_00827c20_shell : ActiveEffect
{
    unsigned short FUN_00827c20(Actor* apActor);
};
// @fnv 0x00827c20
unsigned short FUN_00827c20_shell::FUN_00827c20(Actor* apActor)
{
    unsigned short usSaveSize = 0;
    usSaveSize += reinterpret_cast<::FUN_00804f80_shell *>((((ScriptEffect_GetSaveSize_Helper*)this)))->FUN_00804f80(apActor);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x2a)
        usSaveSize += 2;
    if (*(void**)((char*)this + 0x4c))
        usSaveSize += ::GetScriptLocalsSerializedSize((::ScriptLocals *)(((FUN_005a94f0_shell*)*(void**)((char*)this + 0x4c))));
    return usSaveSize;
}

extern unsigned int _data_011c16bc;

struct FUN_00827880_CopyFrom
{
    virtual void FUN_0000();
    virtual void FUN_0001();
    virtual void FUN_0002();
    virtual void FUN_0003();
    virtual void FUN_0004();
    virtual void FUN_0005();
    virtual void FUN_0006();
    virtual void FUN_0007();
    virtual void FUN_0008();
    virtual void FUN_0009();
    virtual void FUN_000A();
    virtual void FUN_000B();
    virtual void FUN_000C();
    virtual void FUN_000D();
    virtual void FUN_000E();
    virtual void FUN_000F();
    virtual void FUN_0010();
    virtual void CopyFrom(ActiveEffect*);
};

struct FUN_00827880_shell : ScriptEffect
{
    ActiveEffect* FUN_00827880();
};

// @fnv 0x00827880
ActiveEffect* FUN_00827880_shell::FUN_00827880()
{
    ScriptEffect* pEffect =
        new FUN_00827a40_shell(*reinterpret_cast<MagicCaster**>(&this->unk28),
                               *reinterpret_cast<MagicItem**>(&this->unk08),
                               *reinterpret_cast<EffectItem**>(&this->unk0c));

    reinterpret_cast<FUN_00827880_CopyFrom*>(this)->CopyFrom(pEffect);

    return pEffect;
}

struct ScriptExtended
{
};
struct TargetContext
{
    virtual void unused();
    virtual TESObjectREFR* GetActor(ScriptLocals*);
};
struct ScriptEffectShell : ScriptEffect
{
    void FUN_00827ac0();
};
struct FUN_008050d0_shell
{
};

struct FUN_008579b0_shell
{
    void FUN_008579b0(void*, unsigned int);
};

struct FUN_005a9670_shell
{
};

struct FUN_00827ca0_shell : ScriptEffect
{
    void LoadScriptEffect(BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x00827ca0
void FUN_00827ca0_shell::LoadScriptEffect(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::EffectSaveShell *>((((FUN_008050d0_shell*)this)))->FUN_008050d0((::Actor *)(apBuffer));
    unsigned short count = 0;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x2a)
    {
        if (m_pScriptLocals)
        {
            count = ::GetScriptLocalsSerializedSize((::ScriptLocals *)(((FUN_005a94f0_shell*)m_pScriptLocals)));
        }
        ((FUN_008579b0_shell*)g_TESSaveLoadGame)->FUN_008579b0(&count, 2);
    }
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() < 0x2a)
    {
        count = 1;
    }
    if (count)
    {
        reinterpret_cast<::ThisX *>((((FUN_005a9670_shell*)m_pScriptLocals)))->WriteScriptLocals();
    }
}

struct ActiveEffect_LoadGame_Helper
{
};

struct FUN_005abf60_shell
{
    ScriptLocals* FUN_005abf60();
};
// Loads the script effect's saved state: reads a has-locals flag, then loads script locals into the cached ScriptLocals or a temporary one.
// @fnv 0x00827e60
void ScriptEffect::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00806420_shell *>(this)->FUN_00806420(buffer);
    unsigned char hasLocals = 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hasLocals), 1);
    if (hasLocals)
    {
        if (!m_pScriptLocals)
            m_pScriptLocals = reinterpret_cast<::FUN_005abf60_shell *>((pScript))->FUN_005abf60();
        if (m_pScriptLocals)
            reinterpret_cast<::fnv_005a9f20::FUN_005a9f20_shell *>((m_pScriptLocals))->FUN_005a9f20((::fnv_005a9f20::BGSLoadFormBuffer *)(buffer));
        else
        {
            ScriptLocals locals;
            reinterpret_cast<::fnv_005a9f20::FUN_005a9f20_shell *>(&(locals))->FUN_005a9f20((::fnv_005a9f20::BGSLoadFormBuffer *)(buffer));
        }
    }
}
// @fnv 0x00827930
void FUN_00827930_shell::CopyScriptEffectData(ActiveEffect* apDestination)
{
    reinterpret_cast<::ActiveEffect *>((((ActiveEffect_CopyData*)this)))->CopyData(apDestination);
    ScriptEffect* pse = dynamic_cast<ScriptEffect*>(apDestination);
    if (pse)
    {
        pse->pScript = pScript;
        if (pScript && m_pScriptLocals)
        {
            pse->m_pScriptLocals = reinterpret_cast<::FUN_005abf60_shell *>((pScript))->FUN_005abf60();
            reinterpret_cast<::CopyOwner *>((((ScriptLocals_005a8f40*)pse->m_pScriptLocals)))->CopyFromSource((::CopySource *)(m_pScriptLocals));
            SCRIPT_LOCAL_LIST* pLocalEntry = ((::SCRIPT_LOCAL_LIST *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ScriptLocals_0084e3a0*)m_pScriptLocals)))->FUN_0084e3a0()));
            while (pLocalEntry && !pLocalEntry->FUN_008256d0())
            {
                reinterpret_cast<::FUN_005a9290_shell *>((((ScriptLocals_SetVariable*)pse->m_pScriptLocals)))->SetScriptVariable(((::ScriptLocalVariable *)(new ((void *)(pLocalEntry)) ::Vec3()))->uiID, ((::ScriptLocalVariable *)(new ((void *)(pLocalEntry)) ::Vec3()))->fValue);
                pLocalEntry = ((::SCRIPT_LOCAL_LIST *)(reinterpret_cast<::Callees *>((pLocalEntry))->FUN_00726070()));
            }
            if (m_pScriptLocals->effect)
                pse->m_pScriptLocals->effect = new ScriptEventListStub;
        }
    }
}
// If pScript is set, gets its ScriptLocals and passes the actor from the target context to ScriptExtended::RunScriptOnTarget.
// @fnv 0x00827ac0
void ScriptEffectShell::FUN_00827ac0()
{
    if (pScript != 0)
    {
        m_pScriptLocals = reinterpret_cast<::FUN_005abf60_shell *>((pScript))->FUN_005abf60();
        reinterpret_cast<::FUN_005ac340_t *>((((ScriptExtended*)pScript)))->RunScriptOnTarget(((::TargetContext *)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))->GetActor(m_pScriptLocals), {});
    }
}

struct FUN_008579e0_shell
{
    void FUN_008579e0(void* pFlag, unsigned int value);
};

struct FUN_00857bd0
{
    void Init(unsigned int value);
};

struct FUN_005a9950_stub
{
};

struct FUN_00827d30_class : ScriptEffect
{
    void FUN_00827d30(Actor* apActor);
};

// @fnv 0x00827d30
void FUN_00827d30_class::FUN_00827d30(Actor* apActor)
{
    reinterpret_cast<::ActiveEffectLoader *>((((ActiveEffect_LoadGame_Helper*)this)))->FUN_00805330(apActor);
    unsigned short flag = 0;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 42)
    {
        ((FUN_008579e0_shell*)g_TESSaveLoadGame)->FUN_008579e0(&flag, 2);
    }
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() < 42)
    {
        flag = 1;
    }
    if (flag)
    {
        if (m_pScriptLocals == 0)
        {
            m_pScriptLocals = ((FUN_005abf60_shell*)pScript)->FUN_005abf60();
        }
        if (m_pScriptLocals != 0)
        {
            reinterpret_cast<::LoadScriptLocals *>((((FUN_005a9950_stub*)m_pScriptLocals)))->FUN_005a9950();
        }
        else
        {
            ((FUN_00857bd0*)g_TESSaveLoadGame)->Init(flag);
        }
    }
}

struct Actor
{
};

struct S_00827e10_Foo : TESForm
{
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
    Actor* unk4c;

    void FUN_00827e10(Actor* apActor);
};

// Calls FUN_00806230, passes a bool derived from unk4c to the actor, and if it stays true calls FUN_005a9db0 on unk4c.
// @fnv 0x00827e10
void S_00827e10_Foo::FUN_00827e10(Actor* apActor)
{
    reinterpret_cast<::ActiveEffectSaveShell *>((this))->FUN_00806230((::SaveFormBuf *)(apActor));

    bool bValue = this->unk4c;
    reinterpret_cast<::FUN_00865e50_shell *>((apActor))->FUN_00865e50(&bValue, 1, 0);

    if (bValue)
        reinterpret_cast<::SaveLocals9db0 *>((this->unk4c))->FUN_005a9db0((::BGSSaveFormBuffer *)(apActor));
}

class TESObjectCELL;
struct TESBipedModelForm
{
};
class NavMesh
{
  public:
};
struct Cell827b
{
    virtual void v00();
    virtual void* v01(ScriptLocals* apLocals);
};
struct FUN_005ac380_t
{
};
struct FUN_00827b20_t
{
    char _pad[0x48];
    FUN_005ac380_t* m_48;
    ScriptLocals* m_pLocals;
    void ReleaseLocals();
};
// @fnv 0x00827b20
void FUN_00827b20_t::ReleaseLocals()
{
    if (m_48 && (!reinterpret_cast<::FUN_0047c850 *>((((TESBipedModelForm*)g_TESSaveLoadGame)))->EvaluateCondition() ||
                 reinterpret_cast<::FUN_0047c850 *>((((TESBipedModelForm*)g_TESSaveLoadGame)))->EvaluateCondition()))
    {
        reinterpret_cast<::FUN_005ac380 *>((m_48))->ExecuteEffectOnTarget((::TESObjectREFR *)(void *)(((Cell827b*)((::TESObjectCELL *)(reinterpret_cast<::ActorMover *>((((NavMesh*)this)))->GetCurrentMoveModeType())))->v01(m_pLocals)), {});
    }
    if (m_pLocals)
    {
        delete m_pLocals;
        m_pLocals = 0;
    }
}
