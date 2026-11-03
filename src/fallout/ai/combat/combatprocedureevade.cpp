
// src/fallout/ai/combat/combatprocedureevade.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureevade.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/AA10Menu.h"
#include "fnv/decl/AvoidWork.h"
#include "fnv/decl/AvoidanceMap.h"
#include "fnv/decl/CPStandIn009caae0.h"
#include "fnv/decl/CombatDialogueHandler.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_006e2b50_shell.h"
#include "fnv/decl/FUN_006e2bb0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008ad8f0Class.h"
#include "fnv/decl/FUN_008b3960_Class.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008df000_shell.h"
#include "fnv/decl/FUN_009892a0_shell.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_009a0680_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_006e29f0__FUN_006e29f0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00996e20__FUN_00996e20_shell.h"
#include "fnv/decl/fnv_00996e40__FUN_00996e40_shell.h"
#include "fnv/decl/fnv_009a1280__CombatLogic.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01050000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011f1000.h"
struct BGSLoadFormBuffer
{
};

struct CombatProcedure
{
    virtual void LoadGame(BGSLoadFormBuffer*);
};

struct CombatProcedureEvade : CombatProcedure
{
    void LoadGame(BGSLoadFormBuffer*);
};

struct FUN_009d5ff0_shell : CombatProcedureEvade
{
    void FUN_009d5ff0(BGSLoadFormBuffer*);
};

// @fnv 0x009d5ff0
void FUN_009d5ff0_shell::FUN_009d5ff0(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>(this)->FUN_00996ef0(buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x10)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x14)), 4);
}

struct FUN_009ca6c0_shell
{
};
struct FUN_009d5b40_shell
{
    void FUN_009d5b40(void);
};
extern int DAT_01091984;

// @fnv 0x009d5b40
void FUN_009d5b40_shell::FUN_009d5b40(void)
{
    *reinterpret_cast<int**>(this) = &DAT_01091984;
    reinterpret_cast<::FUN_009ca6c0_class *>((reinterpret_cast<FUN_009ca6c0_shell*>(this)))->FUN_009ca6c0();
}

struct FUN_009ca680
{
    virtual void Unk();
    int _pad1;
    int _pad2;
    int _pad3;
    FUN_009ca680();
};
struct FUN_009d5ad0 : FUN_009ca680
{
    int eState;
    int iLocation;
    FUN_009d5ad0(int aiLocation);
};
// Initializes the object's state to 0 and stores the given location value.
// @fnv 0x009d5ad0
FUN_009d5ad0::FUN_009d5ad0(int aiLocation)
{
    eState = 0;
    iLocation = aiLocation;
}

struct FUN_009d5b10_shell : FUN_009d5b40_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x009d5b10
void* FUN_009d5b10_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_009d5b40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

class TESActorBase;
struct Actor
{
public:
    ::TESActorBase *GetActorBase();
};
struct FUN_009cc4d0_shell
{
};
struct CombatProcedureEngageTarget
{
};
struct FUN_009d5b60_shell : CombatProcedureEvade
{
    void StopAndEngageTarget();
};
// Stops the actor's movement and then runs the engage-target combat procedure on this object.
// @fnv 0x009d5b60
void FUN_009d5b60_shell::StopAndEngageTarget()
{
    reinterpret_cast<::FUN_008b3ab0_shell *>((((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>((reinterpret_cast<FUN_009cc4d0_shell*>(this)))->FUN_00996de0()))))->FUN_008b3ab0();
    reinterpret_cast<::fnv_00996e40::FUN_00996e40_shell *>((reinterpret_cast<CombatProcedureEngageTarget*>(this)))->FUN_00996e40();
}

struct BGSSaveFormBuffer
{
};
struct CombatProcedure_SaveHelper
{
};
struct FUN_009d5fb0_shell : CombatProcedureEvade
{
    void SaveEvadeProcedure(BGSSaveFormBuffer*);
};
// Saves the base combat procedure, then writes the 4-byte values at offsets 0x10 and 0x14 into the save buffer.
// @fnv 0x009d5fb0
void FUN_009d5fb0_shell::SaveEvadeProcedure(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00996ed0_shell *>((((CombatProcedure_SaveHelper*)this)))->SaveToBuffer(apSaveGameBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x10), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0x14), 4, 0);
}

struct TESObjectREFR;
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
};
class PathingLocation
{
  public:
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

    PathingLocation(const NiPoint3&, TESObjectREFR*);
    ~PathingLocation();
};
struct EvadeActor;
template <class, unsigned int> class BSSimpleArray;
class PathingRequest
{
  public:
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

    ~PathingRequest();
    void SetDestination(PathingLocation*);
public:
    void SetAvoidNodeArray(::BSSimpleArray<void *, 1024> *);
};
class PathingRequestFlee : public PathingRequest
{
  public:
    PathingRequestFlee();
};
struct EvadeActorBaseData
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual bool CanSwim();
};
struct EvadeActorBase
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

    EvadeActorBaseData data;
};
struct EvadeWorldLocation
{
    int unk00, unk04, unk08, unk0c;
};
struct EvadeActor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const NiPoint3* GetPosition();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual bool IsCreature();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual float GetRadius(int);
    bool FUN_008b3840(NiPoint3*);
    bool FUN_008bb630(PathingRequest*);
};
struct EvadeController
{
};
struct EvadeMovement
{
};
struct EvadeContext
{
};
struct EvadeProcedure
{
    int unk00;
    EvadeContext* context;
    int unk08, unk0c, state, location;
    void UpdateFleeState();
};
struct EvadeManager
{
};
struct EvadeSearchResult
{
};
struct EvadeSearch
{
};
struct EvadeSetting
{
};
extern const char DAT_01091a08[], DAT_010919e8[], DAT_010919c8[];

// @fnv 0x009d5b90
void EvadeProcedure::UpdateFleeState()
{
    EvadeActor* actor = ((::EvadeActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    EvadeController* pController = ((::EvadeController *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()));
    switch (state)
    {
    case 0: {
        NiPoint3 actorPosition = *actor->GetPosition();
        PathingRequestFlee fleeRequest;
        reinterpret_cast<::fnv_006e29f0::FUN_006e29f0_shell *>(&(fleeRequest))->InitFromActor((::Actor *)(actor));
        reinterpret_cast<::FUN_006e2bb0_shell *>(&(fleeRequest))->SetInitialPathHeading(actor->GetRadius(0));
        if (actor->IsCreature())
            reinterpret_cast<::FUN_006e2b50_shell *>(&(fleeRequest))->SetCantOpenDoors(((::EvadeActorBase *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()))->data.CanSwim());
        int destination = 0;
        switch (location)
        {
        case 14: {
            reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::EvadeManager * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(context), 2, 5, 1);
            reinterpret_cast<::FUN_00507610_Class *>(&(fleeRequest))->FUN_00507610(DAT_0101e704);
            NiPoint3 targetPosition;
            if (!actor->FUN_008b3840(&targetPosition))
                reinterpret_cast<::FUN_008df000_shell *>(&(fleeRequest))->FUN_008df000();
            else
                fleeRequest.SetDestination(&PathingLocation(targetPosition, (TESObjectREFR*)actor));
            destination = ((int)(reinterpret_cast<::AvoidanceMap *>((((::EvadeSearchResult *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::EvadeSearch * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))))->BuildAvoidanceNodes({}, {}, {})));
            destination = ((int)(reinterpret_cast<::FUN_009892a0_shell *>((((::EvadeMovement *)(reinterpret_cast<::EffectSetting *>((context))->GetCastSound()))))->FUN_009892a0((::AvoidMember9892 *)(actor), (const ::Pos9892 *)(::NiPoint3 *)(&actorPosition), DAT_01050b98, (::PathingAvoidNodeArray *)(destination), (::AvoidMember9892 *)(0))));
            break;
        }
        case 10:
        case 12:
            reinterpret_cast<::FUN_00507610_Class *>(&(fleeRequest))->FUN_00507610(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::EvadeSetting *>(&::originalRuntimeFloatSetting438)))))));
            reinterpret_cast<::FUN_008df000_shell *>(&(fleeRequest))->FUN_008df000();
            destination = ((int)(reinterpret_cast<::AvoidWork *>((((::EvadeMovement *)(reinterpret_cast<::EffectSetting *>((context))->GetCastSound()))))->BuildAvoidNodes((::AvoidActor *)(actor), (::PathingAvoidNodeArray *)(0))));
            break;
        }
        reinterpret_cast<::PathingRequest *>(&(fleeRequest))->SetAvoidNodeArray((::BSSimpleArray<void *, 1024> *)(destination));
        reinterpret_cast<::FUN_008ad8f0Class *>(&(fleeRequest))->SetByteAtOffset9B(true);
        if (!actor->FUN_008bb630(&fleeRequest))
        {
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(DAT_01091a08));
            break;
        }
        state = 1;
        reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(3);
        break;
    }
    case 1:
        if (reinterpret_cast<::FUN_008b3b90_shell *>((actor))->FUN_008b3b90())
        {
            if (!reinterpret_cast<::FUN_008b3960_Class *>((actor))->FUN_008b3960())
            {
                switch (location)
                {
                case 12:
                    reinterpret_cast<::fnv_009a1280::CombatLogic *>((pController))->FUN_009a1280(0);
                    break;
                }
            }
            reinterpret_cast<::FUN_009a0680_shell *>((pController))->ClearAndDeletePointer();
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actor))->FUN_008b3960() ? DAT_010919e8 : DAT_010919c8));
        }
        else if (((bool)(reinterpret_cast<::TeleportableReference *>((actor))->GetTeleportDestinationForm())))
        {
            reinterpret_cast<::AA10Menu *>((pController))->HandleMenuEvent((int)(&(*(::EvadeWorldLocation *)(reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650({})))), location);
            reinterpret_cast<::CPStandIn009caae0 *>(this)->SetState();
        }
        break;
    }
}

#include "generated/data/fallout/ai/combat/combatprocedureevade.inc"
