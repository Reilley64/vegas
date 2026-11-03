
// src/fallout/ai/combat/combatprocedureattacklow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureattacklow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/CombatWeapon.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_0097ac90_shell.h"
#include "fnv/decl/FUN_0097f450_shell.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996e00_shell.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_0099a2d0_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/fnv_00576260__FUN_00576260_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0089a760__HActor.h"
#include "fnv/decl/fnv_008a8dd0__This008a8dd0.h"
#include "fnv/decl/fnv_0097c150__CombatActionStandIn.h"
#include "fnv/decl/s575ca0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_009b5000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
struct BGSSaveGameBuffer
{
    virtual ~BGSSaveGameBuffer();
};
struct BGSSaveFormBuffer : BGSSaveGameBuffer
{
    virtual ~BGSSaveFormBuffer();
};
struct CombatProcedure
{
    virtual ~CombatProcedure();
};
struct TESObjectWEAP
{
    virtual ~TESObjectWEAP();
};
struct CombatProcedureAttackLow : CombatProcedure
{
    int m_10;
    int m_14;
    int m_18;
    TESObjectWEAP* pWeapon;
    void FUN_009cbfd0(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009cbfd0
void CombatProcedureAttackLow::FUN_009cbfd0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00996ed0_shell *>(this)->SaveToBuffer(apSaveGameBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(reinterpret_cast<char*>(&this->pWeapon), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(reinterpret_cast<char*>(this) + 0x14, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(reinterpret_cast<char*>(this) + 0x18, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*reinterpret_cast<TESObjectWEAP**>(reinterpret_cast<char*>(this) + 0x1c)), 0);
}

struct FUN_009ca6c0_shell
{
    void FUN_009ca6c0();
};

void FUN_009ca6c0_shell::FUN_009ca6c0()
{}

extern int DAT_01090aec;

struct FUN_009cbb50_shell
{
    void FUN_009cbb50();
};

// @fnv 0x009cbb50
void FUN_009cbb50_shell::FUN_009cbb50()
{
    *(int*)this = (int)&DAT_01090aec;
    reinterpret_cast<::FUN_009ca6c0_class *>((reinterpret_cast<FUN_009ca6c0_shell*>(this)))->FUN_009ca6c0();
}

struct FUN_009cbb20_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_009cbb50, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009cbb20
void* FUN_009cbb20_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_009cbb50_shell *>(this)->FUN_009cbb50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FNStub
{
};

typedef int DEBUGTEXT_LOCATION;
typedef int DEBUGTEXT_JUSTIFY;

struct IDebugText
{
    virtual void FUN_009cbf10_0();
    virtual void FUN_009cbf10_1();
    virtual void FUN_009cbf10_2();
    virtual void FUN_009cbf10_3();
    virtual void FUN_009cbf10_4();
    virtual void DisplayText(DEBUGTEXT_LOCATION location, DEBUGTEXT_JUSTIFY justify, const char* text, ...);
};

extern const char $SG2706[];
extern const char str_01090a98[];
extern const char str_010676a0[];
extern const char str_01090b50[];

struct FUN_009cbf10_shell : CombatProcedureAttackLow
{
    void DisplayAttackDebugText(IDebugText* apDebugText, DEBUGTEXT_LOCATION aeLocation, DEBUGTEXT_JUSTIFY aeJustify);
};

// Displays debug text for the combat procedure's state at offset 0x10, showing weapon full name and a float value when the state is 1.
// @fnv 0x009cbf10
void FUN_009cbf10_shell::DisplayAttackDebugText(IDebugText* apDebugText, DEBUGTEXT_LOCATION aeLocation,
                                                DEBUGTEXT_JUSTIFY aeJustify)
{
    switch (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10))
    {
    case 0:
        apDebugText->DisplayText(aeLocation, aeJustify, $SG2706);
        break;

    case 1:
        apDebugText->DisplayText(aeLocation, aeJustify, str_01090a98);

        apDebugText->DisplayText(
            aeLocation, aeJustify, str_01090b50,
            *reinterpret_cast<TESObjectWEAP**>(reinterpret_cast<char*>(this) + 0x1c)
                ? ((char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(reinterpret_cast<char*>(*reinterpret_cast<TESObjectWEAP**>(
                                                reinterpret_cast<char*>(this) + 0x1c)) +
                                            0x30)))->FUN_00408da0()))
                : str_010676a0,
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x14));
        break;
    }
}

struct BGSLoadFormBuffer
{
};

struct CombatProcedure_Helper
{
};

struct TESForm
{
    virtual ~TESForm();
};

extern void* _DAT_01183028;


struct FUN_009cc040_shell
{
    char padding[0x10];
    int m_10;
    int m_14;
    int m_18;
    TESObjectWEAP* pWeapon;

    void FUN_009cc040(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x009cc040
void FUN_009cc040_shell::FUN_009cc040(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>((reinterpret_cast<CombatProcedure_Helper*>(this)))->FUN_00996ef0(apLoadGameBuffer);

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_10), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_14), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_18), 4);

    pWeapon = dynamic_cast<TESObjectWEAP*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0()));
}

template <class T> class NiPointer
{
  public:
    operator T*() const;
    T* m_pObject;
};
class AnimIdle;

struct FUN_009b4d90
{
    FUN_009b4d90();
    char pad[0x64];
};

struct FUN_008c1c60 : NiPointer<AnimIdle>
{
    ~FUN_008c1c60();
};

struct FUN_008c1c30 : FUN_008c1c60
{
    FUN_008c1c30(FUN_009b4d90* apPackage);
};

struct FUN_004459e0
{
    ~FUN_004459e0();
};

struct FUN_00525980_weap
{
};

struct FUN_00645d00_base
{
    int iDummy;
};

struct FUN_009cbb70_actorbase
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
    virtual void v064();
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
    virtual void v095(void* apAmmo, int a2, int aiCount, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
    char pad[0xa4 - 4];
};

struct FUN_009cbb70_actor : FUN_009cbb70_actorbase, FUN_00645d00_base
{
};

struct FUN_0099a2d0_state
{
};

struct FUN_00586150_ctrl
{
};

extern const char DAT_01090b30[];

struct FUN_009cbb70_shell
{
    virtual ~FUN_009cbb70_shell();
    FUN_00586150_ctrl* pController;
    char padCur[8];
    int iState;
    float fTime;
    float fTimeCur;
    FUN_00525980_weap* pWeapon;
    void FUN_009cbb70();
};

// @fnv 0x009cbb70
void FUN_009cbb70_shell::FUN_009cbb70()
{
    FUN_009cbb70_actor* kActor = ((::FUN_009cbb70_actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    FUN_009cbb70_actor* pTarget = ((::FUN_009cbb70_actor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    FUN_0099a2d0_state* pState2 = ((::FUN_0099a2d0_state *)(reinterpret_cast<::InterfaceManager *>((pController))->FUN_00586150()));
    if (!pTarget || ((int)(reinterpret_cast<::s575ca0::Owner *>((pTarget))->FUN_00575ca0())) != ((int)(reinterpret_cast<::s575ca0::Owner *>((kActor))->FUN_00575ca0())))
    {
        reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(DAT_01090b30));
        return;
    }

    if (iState == 0)
    {
        pWeapon = ((::FUN_00525980_weap *)(reinterpret_cast<::FUN_0099a2d0_shell *>((pState2))->GetBestWeapon()));
        int aIType = pWeapon ? reinterpret_cast<::CombatWeapon *>((pWeapon))->FUN_00522c80() : 6;
        fTime = reinterpret_cast<::FUN_0097ac90_shell *>((pState2))->FUN_0097ac90(aIType);
        if (pWeapon)
        {
            FUN_004459e0* pItem = ((::FUN_004459e0 *)(reinterpret_cast<::fnv_00576260::FUN_00576260_shell *>((kActor))->FUN_00576260((::fnv_00576260::TESBoundObject *)(pWeapon), 0)));
            if (!pItem)
            {
                reinterpret_cast<::FUN_0097f450_shell *>((pState2))->SetAttacker(true);
                return;
            }
            fTimeCur = reinterpret_cast<::FUN_004bcdb0_shell *>((pItem))->FUN_004bcdb0(1);
            delete pItem;
        }
        iState = 1;
    }

    int iType = pWeapon ? reinterpret_cast<::CombatWeapon *>((pWeapon))->FUN_00522c80() : 6;
    if (pWeapon && pWeapon != ((::FUN_00525980_weap *)(reinterpret_cast<::fnv_0097c150::CombatActionStandIn *>((pState2))->FUN_0097c150(iType))))
    {
        reinterpret_cast<::FUN_0097f450_shell *>((pState2))->SetAttacker(true);
        iState = 0;
        return;
    }

    float fChance3 = reinterpret_cast<::FleeActorEntry *>((pTarget))->FUN_008a6650(0) ? FUN_00403e20(&(*reinterpret_cast<float *>(&::originalRuntimeFloatSetting497))) : FUN_00403e20(&(*reinterpret_cast<float *>(&::originalRuntimeFloatSetting496)));
    if (RandomFloat(0.0f, 1.0f) < fChance3)
    {
        FUN_008c1c30 spPackage(new FUN_009b4d90);
        ::FUN_009b5720((::FUN_009b5a30_Class *)(::AnimIdle *)(spPackage), (int)(kActor), (int)(pTarget), fTime);
        reinterpret_cast<::fnv_0089a760::HActor *>((pTarget))->FUN_0089a760((::fnv_0089a760::HHit *)(::AnimIdle *)(spPackage), 0);
    }

    if (pWeapon && ((void *)(reinterpret_cast<::AmmoOwner *>((pWeapon))->FUN_00525980((::AmmoActor *)(kActor)))) && reinterpret_cast<::fnv_008a8dd0::This008a8dd0 *>((kActor))->FUN_008a8dd0((::fnv_008a8dd0::Arg008a8dd0 *)(pWeapon)))
    {
        void* pAmmoA = ((void *)(reinterpret_cast<::AmmoOwner *>((pWeapon))->FUN_00525980((::AmmoActor *)(kActor))));
        int iCountCur = reinterpret_cast<::CombatState *>((kActor))->GetInventoryItemCount((::TESForm *)(pAmmoA));
        int iClip = ::FUN_00645d00((::ActorValueOwner *)(kActor), (::TESObjectWEAP *)(pWeapon), (::InventoryStackRecord *)(0));
        iClip = FUN_00647b70(iClip, 1);
        iClip = MinInt(iClip, iCountCur);
        kActor->v095(pAmmoA, 0, iClip, 0, 0, 0, 0, 0, 1, 0);
        if (iClip == iCountCur)
        {
            reinterpret_cast<::FUN_0097f450_shell *>((pState2))->SetAttacker(true);
            iState = 0;
        }
    }
}

#include "generated/data/fallout/ai/combat/combatprocedureattacklow.inc"
