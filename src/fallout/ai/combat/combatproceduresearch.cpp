
// src/fallout/ai/combat/combatproceduresearch.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatproceduresearch.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/result_slot.h"
#include <new>
#include "fnv/decl/ActorMagicQuery.h"
#include "fnv/decl/ActorStandIn.h"
#include "fnv/decl/Animation.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/C8B39D0Actor.h"
#include "fnv/decl/Caller_43a3f0.h"
#include "fnv/decl/CombatNodeFinder.h"
#include "fnv/decl/CombatSearchCls.h"
#include "fnv/decl/CombatSearchMgr.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_00527b70_shell.h"
#include "fnv/decl/FUN_00527ba0_This.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_005757d0_shell.h"
#include "fnv/decl/FUN_006df760_shell.h"
#include "fnv/decl/FUN_006e0b50_cls.h"
#include "fnv/decl/FUN_006e0bc0_shell.h"
#include "fnv/decl/FUN_006e2b50_shell.h"
#include "fnv/decl/FUN_006e4340_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008ad8f0Class.h"
#include "fnv/decl/FUN_008b3960_Class.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008df000_shell.h"
#include "fnv/decl/FUN_008e7c50_cls.h"
#include "fnv/decl/FUN_00915d20_shell.h"
#include "fnv/decl/FUN_0097ede0_cls.h"
#include "fnv/decl/FUN_0097ef30_shell.h"
#include "fnv/decl/FUN_00985bb0_Class.h"
#include "fnv/decl/FUN_0098c6e0_class.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996e00_shell.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_009a0b00_s.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/FUN_009d9ec0_shell.h"
#include "fnv/decl/FUN_009d9ee0_Class.h"
#include "fnv/decl/FUN_009d9f00_Class.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FUN_009d9f60_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/ItemList.h"
#include "fnv/decl/PathingLocationProxy.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/ProximityGroup.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00568fa0__Fn568fa0.h"
#include "fnv/decl/fnv_00569000__TESObjectREFR_ext.h"
#include "fnv/decl/fnv_006e29f0__FUN_006e29f0_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_008bcd20__FUN_008bcd20_shell.h"
#include "fnv/decl/fnv_008bcd60__FUN_008bcd60_Class.h"
#include "fnv/decl/fnv_0097fa90__FUN_0097fa90_Class.h"
#include "fnv/decl/fnv_0098c750__FUN_0098c750_class.h"
#include "fnv/decl/fnv_00996e20__FUN_00996e20_shell.h"
#include "fnv/decl/fnv_00996e40__FUN_00996e40_shell.h"
#include "fnv/decl/fnv_009a02a0__FUN_009a02a0_struct.h"
#include "fnv/decl/fnv_009a0ec0__FUN_009a0ec0_shell.h"
#include "fnv/decl/fnv_009d9f20__FUN_009d9f20_shell.h"
#include "fnv/decl/s575ca0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_008e7000.h"
#include "fnv/symbols_00906000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
enum COMBAT_PROCEDURES
{
    eCombatProcedure = 10
};

struct CombatProcedure
{
    virtual int GetType() = 0;
};

struct CombatProcedureSearch : CombatProcedure
{
    virtual int FUN_009d8c00();
};

// @fnv 0x009d8c00
int CombatProcedureSearch::FUN_009d8c00()
{
    return eCombatProcedure;
}


struct FUN_009d8c10_shell
{
    void FUN_009d8c40();
    void* Destroy(unsigned int flags);
};

// Calls FUN_009d8c40, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x009d8c10
void* FUN_009d8c10_shell::Destroy(unsigned int flags)
{
    FUN_009d8c40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_009d8d00_shell
{
    void SetFieldEC(intptr_t param);
};

// @fnv 0x009d8d00
void FUN_009d8d00_shell::SetFieldEC(intptr_t aiValue)
{
    *(int*)((char*)this + 0xec) = aiValue;
}

struct TESObjectREFR;
struct TESBoundObject;
struct FUN_009d9fa0_shell
{
    void* m_packed[0x3c / 4];
    TESObjectREFR* m_pReference;
    void ClearRefIfMatches(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount, bool abActivatedScriptOnly);
};

// Clears the stored reference when it equals apRef.
// @fnv 0x009d9fa0
void FUN_009d9fa0_shell::ClearRefIfMatches(TESObjectREFR* apRef, TESBoundObject* apObject, int aiCount,
                                           bool abActivatedScriptOnly)
{
    if (m_pReference == apRef)
        m_pReference = 0;
}

struct FUN_009ca6c0_shell
{
};

extern int DAT_01091db4;

// @fnv 0x009d8c40
void FUN_009d8c10_shell::FUN_009d8c40()
{
    *reinterpret_cast<void**>(this) = (void*)&DAT_01091db4;
    reinterpret_cast<::FUN_009ca6c0_class *>((((FUN_009ca6c0_shell*)this)))->FUN_009ca6c0();
}

struct AvoidSphere
{
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_009da570_shell
{
    float GetAvoidRadius() const;
};
// Returns the radius of the AvoidSphere referenced at offset 0xd4, or -1.0f when that pointer is null.
// @fnv 0x009da570
float FUN_009da570_shell::GetAvoidRadius() const
{
    return reinterpret_cast<Flt*>(reinterpret_cast<char*>(const_cast<FUN_009da570_shell*>(this)) + 0xd4)
                   ->
                   operator unsigned int()
               ? reinterpret_cast<::BSMultiBoundSphere *>((void *)(reinterpret_cast<AvoidSphere*>(
                     reinterpret_cast<Flt*>(reinterpret_cast<char*>(const_cast<FUN_009da570_shell*>(this)) + 0xd4)
                         ->
                         operator unsigned int())))->GetRadius()
               : -1.0f;
}

struct CoordinateTriple
{
};
struct BGSSaveFormBuffer
{
};
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer*);
};
struct CombatProcedureSaveGameShell
{
};
struct CombatProcedureSearchSaveShell : CombatProcedureSearch
{
    void FUN_009da5c0(BGSSaveFormBuffer*);
};
// Saves the combat procedure search state to the buffer: base data, a 4-byte field at 0x10, sub-objects at 0x2c/0x1c/0x14/0x24, and a pointer at 0x3c.
// @fnv 0x009da5c0
void CombatProcedureSearchSaveShell::FUN_009da5c0(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ed0_shell *>((((CombatProcedureSaveGameShell*)this)))->SaveToBuffer(buffer);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x10, 4, 0);
    reinterpret_cast<::FUN_00527b70_shell *>((((CoordinateTriple*)((char*)this + 0x2c))))->FUN_00527b70((::BGSSaveGameBuffer *)(buffer));
    ((FUN_009a5eb0_shell*)((char*)this + 0x1c))->FUN_009a5eb0(buffer);
    ((FUN_009a5eb0_shell*)((char*)this + 0x14))->FUN_009a5eb0(buffer);
    ((FUN_009a5eb0_shell*)((char*)this + 0x24))->FUN_009a5eb0(buffer);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0x3c)), 0);
}

struct BGSLoadFormBuffer
{
};
struct FUN_00527ba0_Class
{
};
struct TimeoutTimer
{
    void LoadGame(BGSLoadFormBuffer*);
public:
    float FUN_006b9130();
public:
    bool CheckTimer();
};
struct CombatProcedure_LoadGame : CombatProcedure
{
};
struct CombatProcedureSearch_LoadGame : CombatProcedureSearch
{
    void FUN_009da640(BGSLoadFormBuffer*);
};
// Loads the base CombatProcedure state, then reads a 4-byte field and loads four sub-objects and a bool from the buffer.
// @fnv 0x009da640
void CombatProcedureSearch_LoadGame::FUN_009da640(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>((reinterpret_cast<CombatProcedure_LoadGame*>(this)))->FUN_00996ef0(buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10)), 4);
    reinterpret_cast<::FUN_00527ba0_This *>((reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x2c)))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x1c)->LoadGame(buffer);
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x14)->LoadGame(buffer);
    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x24)->LoadGame(buffer);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x3c)));
}

struct BGSLoadFormBuffer;
struct TESForm
{
    virtual void Revert(unsigned int);
};
class ExtraRadioData;
struct TESObjectREFR : TESForm
{
    virtual ~TESObjectREFR();
public:
    ::ExtraRadioData *GetExtraRadioData();
};
struct FUN_009da6c0_holder
{
    unsigned char _pad[0x3c];
    TESObjectREFR* m_pReference;
    void RevertAndResolveRef(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009da6c0
void FUN_009da6c0_holder::RevertAndResolveRef(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>((((TESForm*)this)))->FUN_004534f0((uintptr_t)apLoadGameBuffer);
    m_pReference =
        m_pReference ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(uintptr_t)m_pReference)) : 0;
}

class TESActorBase;
struct Actor
{
public:
    ::TESActorBase *GetActorBase();
};
class TESSound;
struct EffectSetting
{
public:
    ::TESSound *GetCastSound();
};
struct CombatProcedureEngageTarget
{
};
struct FUN_009d8c60_shell : CombatProcedureEngageTarget
{
    void UpdateEngageTarget();
};
struct FUN_0098c780_shell
{
    void ClearReservedFlag(intptr_t);
};
struct FUN_009d8d20_Class
{
    int GetFieldEC();
};
// @fnv 0x009d8c60
void FUN_009d8c60_shell::UpdateEngageTarget()
{
    Actor* pattacker = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    EffectSetting* pcombatGroup = ((::EffectSetting *)(reinterpret_cast<::EffectSetting *>((void *)(((EffectSetting**)((char*)this + 4))[0]))->GetCastSound()));
    if (pcombatGroup && ((FUN_009d8d20_Class*)pcombatGroup)->GetFieldEC() == (intptr_t)pattacker)
        ((FUN_009d8d00_shell*)pcombatGroup)->SetFieldEC(0);
    reinterpret_cast<::FUN_008b3ab0_shell *>((pattacker))->FUN_008b3ab0();
    reinterpret_cast<::fnv_00996e40::FUN_00996e40_shell *>(this)->FUN_00996e40();
    if (*(int*)((char*)this + 0x10) == 5 || *(int*)((char*)this + 0x10) == 4)
        reinterpret_cast<::fnv_008bcd20::FUN_008bcd20_shell *>((pattacker))->FUN_008bcd20();
    if (*(int*)((char*)this + 0x10) == 2 && pcombatGroup && *(void**)((char*)this + 0x3c))
        ((FUN_0098c780_shell*)pcombatGroup)->ClearReservedFlag((intptr_t)*(void**)((char*)this + 0x3c));
}

extern int DAT_01091db4;

struct FUN_009d8b60_base
{
    FUN_009d8b60_base();
    ~FUN_009d8b60_base();
};

struct FUN_009d8b60_member8
{
    int m_00;
    int m_04;
};

struct FUN_009d8b60_member16
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_009d8b60_cls : FUN_009d8b60_base
{
    void* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    FUN_009d8b60_member8 m_14;
    FUN_009d8b60_member8 m_1c;
    FUN_009d8b60_member8 m_24;
    FUN_009d8b60_member16 m_2c;
    int m_3c;

    FUN_009d8b60_cls();
};

// Initializes the object: sets the vtable pointer, zeroes m_10 and m_3c, and calls Init on the four member sub-objects.
// @fnv 0x009d8b60
FUN_009d8b60_cls::FUN_009d8b60_cls()
{
    m_vptr = (void*)&DAT_01091db4;
    m_10 = 0;
    ::FUN_00906f60((float *)&(m_14));
    ::FUN_00906f60((float *)&(m_1c));
    ::FUN_00906f60((float *)&(m_24));
    reinterpret_cast<::FUN_0097ede0_cls *>(&(m_2c))->FUN_0097ede0();
    m_3c = 0;
}

struct FUN_009da550_val
{
    int v;
};

struct FUN_009da550_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;
    int unk53;
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    FUN_009da550_val m_iE8;
    FUN_009da550_val* GetValue(FUN_009da550_val* apOut);
};

// @fnv 0x009da550
FUN_009da550_val* FUN_009da550_cls::GetValue(FUN_009da550_val* apOut)
{
    *apOut = m_iE8;
    return apOut;
}

namespace SearchDiagnostics {
struct Vector
{
    float x, y, z;
};
struct Reference
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
    virtual const char* Name();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const Vector& Position();
};
struct Location
{
    int unk00, unk04, unk08, unk0c;
};
struct Radius
{
    int value;
};
struct Range
{
    int unk00, unk04, unk08, unk0c;
};
struct Context
{
};
struct Owner
{
};
struct Output
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Print(int, int, const char*, ...);
};
extern const char DAT_01090b68[], DAT_01092078[], DAT_0109205c[], DAT_0108cfe4[], DAT_0109204c[], DAT_0109202c[],
    DAT_01092020[], DAT_0109200c[], DAT_01091ff0[], DAT_01091fe0[], DAT_01091fd8[], DAT_01091fb0[], DAT_01091f88[],
    DAT_01091f60[], DAT_01091f40[];
struct Search
{
    int unk00;
    Owner* owner;
    int unk08, unk0c;
    unsigned int state;
    int unk14, unk18;
    Range range;
    Location location;
    Reference* door;
    void PrintDebugInfo(Output*, int, int);
};
// @fnv 0x009d9fd0
void Search::PrintDebugInfo(Output* output, int x, int y)
{
    Reference* actor = ((::SearchDiagnostics::Reference *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Context* context = ((::SearchDiagnostics::Context *)(reinterpret_cast<::EffectSetting *>((owner))->GetCastSound()));
    switch (state)
    {
    case 0:
        output->Print(x, y, DAT_01090b68);
        break;
    case 1:
        output->Print(x, y, DAT_01092078);
        output->Print(x, y, DAT_0109205c, (*(const ::SearchDiagnostics::Vector *)(((::Vec3 *)(void *)&(location)))).x, (*(const ::SearchDiagnostics::Vector *)(((::Vec3 *)(void *)&(location)))).y,
                      (*(const ::SearchDiagnostics::Vector *)(((::Vec3 *)(void *)&(location)))).z);
        output->Print(x, y, DAT_0108cfe4, ((::SearchDiagnostics::Reference *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(location))->FUN_0084e3a0()))->Name());
        break;
    case 2:
        output->Print(x, y, DAT_0109204c);
        if (door)
            output->Print(x, y, DAT_0109202c, door->Name(), door->Position().x, door->Position().y, door->Position().z);
        break;
    case 3:
        output->Print(x, y, DAT_01092020);
        break;
    case 4:
        output->Print(x, y, DAT_0109200c);
        output->Print(x, y, DAT_01091ff0, ((double)(reinterpret_cast<::FUN_00435e00_t *>(&(range))->FUN_00435e00())), ((double)(reinterpret_cast<::TimeoutTimer *>(&(range))->FUN_006b9130())));
        break;
    case 5:
        output->Print(x, y, DAT_01091fe0);
        output->Print(x, y, DAT_01091ff0, ((double)(reinterpret_cast<::FUN_00435e00_t *>(&(range))->FUN_00435e00())), ((double)(reinterpret_cast<::TimeoutTimer *>(&(range))->FUN_006b9130())));
        break;
    case 6:
        output->Print(x, y, DAT_01091fd8);
        output->Print(x, y, DAT_01091ff0, ((double)(reinterpret_cast<::FUN_00435e00_t *>(&(range))->FUN_00435e00())), ((double)(reinterpret_cast<::TimeoutTimer *>(&(range))->FUN_006b9130())));
        break;
    case 7:
        output->Print(x, y, DAT_01091fb0);
        output->Print(x, y, DAT_01091ff0, ((double)(reinterpret_cast<::FUN_00435e00_t *>(&(range))->FUN_00435e00())), ((double)(reinterpret_cast<::TimeoutTimer *>(&(range))->FUN_006b9130())));
        if (((double)(reinterpret_cast<::CombatTargetTimestamp *>((((::SearchDiagnostics::Range *)(reinterpret_cast<::FUN_009d9f40_Class *>((context))->FUN_009d9f40()))))->FUN_006a7f50())) < ((double)(reinterpret_cast<::CombatTargetTimestamp *>(&(range))->FUN_006a7f50())) &&
            ((::SearchDiagnostics::Reference *)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)&(const ::SearchDiagnostics::Location &)((*(::SearchDiagnostics::Location *)(reinterpret_cast<::FUN_009d9f60_shell *>((context))->FUN_009d9f60({})))))->FUN_0084e3a0())) != ((void *)(reinterpret_cast<::s575ca0::Owner *>((actor))->FUN_00575ca0())))
            output->Print(x, y, DAT_01091f88, ((double)(reinterpret_cast<::FUN_00435e00_t *>((((::SearchDiagnostics::Range *)(reinterpret_cast<::FUN_009d9f40_Class *>((context))->FUN_009d9f40()))))->FUN_00435e00())),
                          ((double)(reinterpret_cast<::TimeoutTimer *>((((::SearchDiagnostics::Range *)(reinterpret_cast<::FUN_009d9f40_Class *>((context))->FUN_009d9f40()))))->FUN_006b9130())));
        break;
    case 8:
        output->Print(x, y, DAT_01091f60);
        output->Print(x, y, DAT_0109205c, (*(const ::SearchDiagnostics::Vector *)(((::Vec3 *)(void *)&(location)))).x, (*(const ::SearchDiagnostics::Vector *)(((::Vec3 *)(void *)&(location)))).y,
                      (*(const ::SearchDiagnostics::Vector *)(((::Vec3 *)(void *)&(location)))).z);
        output->Print(x, y, DAT_0108cfe4, ((::SearchDiagnostics::Reference *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(location))->FUN_0084e3a0()))->Name());
        break;
    }
    float confidence = reinterpret_cast<::FUN_009da570_shell *>((context))->GetAvoidRadius();
    if (confidence >= ::_DAT_01012060)
        output->Print(x, y, DAT_01091f40, ((int)(reinterpret_cast<::FUN_00458400_cls *>((context))->GetFieldD0())), ((double)(reinterpret_cast<::Animation *>((context))->FUN_009442a0())), confidence * ::g_d100,
                      ((double)(reinterpret_cast<::fnv_0097fa90::FUN_0097fa90_Class *>((void *)&(const ::SearchDiagnostics::Radius &)((*(::SearchDiagnostics::Radius *)(reinterpret_cast<::FUN_009da550_cls *>((context))->GetValue({})))))->GetClampedDifference())));
}
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3&) const;
};


struct GameSettingCollection;
struct SETTING_VALUE
{
    float f;
};

template <typename T> struct SettingT
{
    SETTING_VALUE* Float();
};



struct FUN_008d7f40_shell
{
    int m_00;
    int m_04;
    void FUN_008d7f40(float);
};

struct Location16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    double FUN_00527a40(const Location16*);
};

struct Obj0049f1c0;

struct BSPortalGraphSub
{
};

struct TileSub
{
    void* GetLODMultType();
};

struct S00568fa0
{
};

struct SearchRef : S00568fa0
{
};

struct RangeSub
{
};

struct ContextSub
{
};

struct OwnerSub
{
};

class NavMeshPtr;
struct PathingLocation
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

    PathingLocation();
    PathingLocation(const NiPoint3&, void*);
    PathingLocation(Location16*);
    ~PathingLocation();

public:
    bool ResolveNavMesh(::NavMeshPtr &);
public:
    bool HasValidTriangle_006dd6a0();
};

bool FUN_006d7490(PathingLocation*, void*, int, int);

template <typename T> struct NiPointer
{
    int unk00;
    NiPointer(void*);
    ~NiPointer();
};

struct PathingRequestHelper
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

    PathingRequestHelper();
    virtual ~PathingRequestHelper();

};

struct PathingRequestLOS : PathingRequestHelper
{
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

    PathingRequestLOS();
    virtual ~PathingRequestLOS();

    void FUN_006e5a40(NiPoint3, float);
};

struct Outer006d8910
{
    unsigned char FUN_006d8910(unsigned short);
};

struct NavMeshPtr
{
    int unk00;
    NavMeshPtr();
    ~NavMeshPtr();

    Outer006d8910* operator->();
};

struct Obj0049f1c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Obj0049f1c0();
    ~Obj0049f1c0();
};

struct ActorBaseSub
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
    virtual bool v10();
};

struct ActorBaseImpl
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
    ActorBaseSub sub;
};

struct ActorSub : Actor
{
    int FUN_00931850();
    bool SetPathingRequestAvoidNodes(void*);
    bool FUN_008b3860(void*);
    bool FUN_008bb630(void*);

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
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& Position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool v135();
};

struct SearchProcedure : CombatProcedureSearch
{
    OwnerSub* owner;
    int unk08;
    int unk0c;
    unsigned int state;
    FUN_008d7f40_shell timer14;
    FUN_008d7f40_shell timer1c;
    FUN_008d7f40_shell timer24;
    Location16 location;
    SearchRef* m_pReference;


    void UpdateSearchState();
};

static const char* g_dummy_sg = "dummy";

// @fnv 0x009d8d40
void SearchProcedure::UpdateSearchState()
{
    ActorSub* pActor2;
    BSPortalGraphSub* m_pPortalConnectivityGraphInfo;
    int hasTarget_2;
    TileSub* pTile2;
    void* pUnk7;
    ContextSub* pContext;

    pActor2 = ((::ActorSub *)(reinterpret_cast<::FUN_00996de0_Class *>((this))->FUN_00996de0()));
    pUnk7 = reinterpret_cast<::FUN_00996e00_shell *>((this))->FUN_00996e00();
    hasTarget_2 = pActor2->FUN_00931850();
    pContext = ((::ContextSub *)(reinterpret_cast<::EffectSetting *>((this->owner))->GetCastSound()));
    m_pPortalConnectivityGraphInfo = ((::BSPortalGraphSub *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((pContext))->FUN_009d9f20()));
    pTile2 = ((::TileSub *)(reinterpret_cast<::InterfaceManager *>((this->owner))->FUN_00586150()));

    switch (this->state)
    {
    case 0:
        if (!hasTarget_2 && ((int)(reinterpret_cast<::FUN_009d9f00_Class *>((this->owner))->FUN_009d9f00())) == 4)
        {
            this->state = 7;
            this->timer1c.FUN_008d7f40(::DAT_010162c0);
            break;
        }
        this->m_pReference = 0;
        if (reinterpret_cast<::FUN_0097ef30_shell *>((pContext))->FUN_0097ef30())
        {
            SearchRef* pObj28 = ((::SearchRef *)(reinterpret_cast<::ItemList *>((pContext))->FindBestItem((::ActorObj *)(pActor2), 0, (::ItemObj *)(0))));
            if (pObj28 && reinterpret_cast<::FUN_00985bb0_Class *>((pObj28))->FUN_00985bb0() > ::DAT_0101db88)
            {
                PathingRequestHelper req;
                reinterpret_cast<::ActorStandIn *>((pActor2))->BuildPathingRequest((::PathingRequest *)(void *)(&req), (*(const ::NiPoint3 *)(&(*(const ::NiPoint3 *)(((::Vec3 *)(void *)(pObj28)))))), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pObj28))->FUN_0084e3a0()))), ::DAT_0101e704, (::PathingAvoidNodeArray *)(0));
                reinterpret_cast<::FUN_008e7c50_cls *>(&(req))->SetUseSoft(false);
                if (!pActor2->SetPathingRequestAvoidNodes(&req))
                {
                    reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)("Cannot setup path to investigate point"));
                    break;
                }
                this->state = 1;
                this->timer14.FUN_008d7f40(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting461))))->f);
                this->location = *(Location16*)pObj28;
            }
            else
            {
                SearchRef* pObjE0 =
                    ((::SearchRef *)(reinterpret_cast<::CombatNodeFinder *>((pContext))->FindNearestCombatNode((::ActorS *)(pActor2),
                                                    (hasTarget_2 == 0) ? ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting462))))->f
                                                                       : ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting464))))->f,
                                                    1)));
                if (pObjE0)
                {
                    PathingRequestHelper req;
                    reinterpret_cast<::ActorStandIn *>((pActor2))->BuildPathingRequest((::PathingRequest *)(void *)(&req), (*(const ::NiPoint3 *)(const void *)&(reinterpret_cast<::fnv_00568fa0::Fn568fa0 *>((pObjE0))->FUN_00568fa0())), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::s575ca0::Owner *>((pObjE0))->FUN_00575ca0()))), 0.0f, (::PathingAvoidNodeArray *)(0));
                    NiPoint3 rot = *((::NiPoint3 *)(reinterpret_cast<::fnv_00569000::TESObjectREFR_ext *>((pObjE0))->FUN_00569000()));
                    ::SetTargetAngle((char *)&(req), WrapAngle(rot.z - 3.1415927410125732));
                    if (!pActor2->SetPathingRequestAvoidNodes(&req))
                    {
                        reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)("Cannot setup path to search door"));
                        break;
                    }
                    this->state = 2;
                    this->m_pReference = pObjE0;
                    reinterpret_cast<::fnv_0098c750::FUN_0098c750_class *>((pContext))->FUN_0098c750((intptr_t)(pObjE0));
                }
                else
                {
                    Location16 loc1ac = (*(::Location16 *)(reinterpret_cast<::FUN_009d9f60_shell *>((pContext))->FUN_009d9f60({})));
                    if (m_pPortalConnectivityGraphInfo == 0 || ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(loc1ac))->FUN_0084e3a0())) != ((void *)(reinterpret_cast<::s575ca0::Owner *>((pActor2))->FUN_00575ca0())))
                    {
                        Location16 loc1bc = (*(::Location16 *)(reinterpret_cast<::FUN_00575650_Class *>((pActor2))->FUN_00575650({})));
                        if (loc1bc.FUN_00527a40(&loc1ac) > DAT_0106cd60)
                        {
                            PathingRequestHelper req;
                            if (reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>((pTile2))->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&loc1ac)), 1, 0))
                            {
                                reinterpret_cast<::ActorStandIn *>((pActor2))->BuildPathingRequest((::PathingRequest *)(void *)(&req), (*(const ::NiPoint3 *)(((void *)(((::Vec3 *)(void *)&(loc1ac)))))), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(loc1ac))->FUN_0084e3a0()))),
                                                             ::DAT_0101e704, (::PathingAvoidNodeArray *)(0));
                                if (!pActor2->SetPathingRequestAvoidNodes(&req))
                                {
                                    reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)("Cannot setup path to search center"));
                                    break;
                                }
                                this->location = loc1ac;
                                this->state = 8;
                            }
                        }
                        else
                        {
                            this->state = 6;
                            this->timer1c.FUN_008d7f40(1.0f);
                        }
                    }
                    else
                    {
                        void* p360 = ((void *)(reinterpret_cast<::FUN_009d8d20_Class *>((pContext))->GetFieldEC()));
                        if (p360 && p360 != pActor2)
                        {
                            break;
                        }
                        PathingRequestLOS losReq;
                        reinterpret_cast<::fnv_006e29f0::FUN_006e29f0_shell *>(&(losReq))->InitFromActor((::Actor *)(pActor2));
                        if (pActor2->v135())
                        {
                            reinterpret_cast<::FUN_006e2b50_shell *>(&(losReq))->SetCantOpenDoors(((::ActorBaseImpl *)(reinterpret_cast<::Actor *>((pActor2))->GetActorBase()))->sub.v10());
                        }
                        reinterpret_cast<::FUN_008df000_shell *>(&(losReq))->FUN_008df000();
                        reinterpret_cast<::FUN_009d9ec0_shell *>(&(losReq))->AssignAtOffsetB0((void *)&(const ::NiPointer<void> &)(m_pPortalConnectivityGraphInfo));
                        SearchRef* pSearch = (SearchRef*)pTile2->GetLODMultType();
                        if (pSearch && (*(unsigned char*)pSearch == 1 || *(unsigned char*)pSearch == 2 ||
                                        *(unsigned char*)pSearch == 3))
                        {
                            losReq.FUN_006e5a40(*(NiPoint3*)&(*(const ::NiPoint3 *)(((::Vec3 *)(void *)(((SearchRef*)((char*)pSearch + 8)))))),
                                                reinterpret_cast<::FUN_009a0b00_s *>((pTile2))->FUN_009a0b00());
                        }
                        if (pObj28 && ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pObj28))->FUN_0084e3a0())) == ((void *)(reinterpret_cast<::s575ca0::Owner *>((pActor2))->FUN_00575ca0())))
                        {
                            reinterpret_cast<::PathingRequest *>(&(losReq))->SetDestination(&ResultSlot(PathingLocation((*(const ::NiPoint3 *)(((::Vec3 *)(void *)(pObj28)))), pActor2)));
                        }
                        reinterpret_cast<::FUN_006e4340_Class *>(&(losReq))->FUN_006e4340(::DAT_010231a0);
                        reinterpret_cast<::FUN_008ad8f0Class *>(&(losReq))->SetByteAtOffset9B(0);
                        Obj0049f1c0 objLoc;
                        if (reinterpret_cast<::CombatSearchCls *>((pContext))->CheckOtherEntriesForTarget((::CombatEntryObj *)(pActor2), (::CombatGroupTarget *)(::Obj0049f1c0 *)(&objLoc)))
                        {
                            reinterpret_cast<::FUN_009d9ee0_Class *>(&(losReq))->FUN_009d9ee0((::LinkedObject *)(::Obj0049f1c0 *)(&objLoc));
                        }
                        if (!pActor2->FUN_008bb630(&losReq))
                        {
                            reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)("Cannot setup LOS search path"));
                            break;
                        }
                        reinterpret_cast<::FUN_009d8d00_shell *>((pContext))->SetFieldEC((intptr_t)(pActor2));
                        this->timer14.FUN_008d7f40(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT< ::GameSettingCollection> *>(&::g_011cecc4))))))->f);
                        this->state = 3;
                        this->timer24.FUN_008d7f40(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting465))))->f);
                    }
                }
            }
            reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>((this))->FUN_00996e20(1);
        }
        break;

    case 1:
    case 8:
        if (reinterpret_cast<::FUN_008b3b90_shell *>((pActor2))->FUN_008b3b90())
        {
            if (!reinterpret_cast<::FUN_008b3960_Class *>((pActor2))->FUN_008b3960())
            {
                reinterpret_cast<::fnv_009a0ec0::FUN_009a0ec0_shell *>((pTile2))->SetNodeBlockAndTimestamp((const ::fnv_009a0ec0::FUN_009a0ec0_Block *)&(this->location));
            }
            reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)(reinterpret_cast<::FUN_008b3960_Class *>((pActor2))->FUN_008b3960() ? "Pathing failed while moving to destination"
                                                       : "Path Building failed to destination"));
            break;
        }
        {
            bool bFlag361 = false;
            if (this->state == 1 && reinterpret_cast<::TimeoutTimer *>(&(this->timer14))->CheckTimer())
            {
                Location16 loc374 = (*(::Location16 *)(reinterpret_cast<::FUN_00575650_Class *>((pActor2))->FUN_00575650({})));
                if (loc374.FUN_00527a40(&this->location) <
                    ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting460))))->f * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting460))))->f)
                {
                    PathingLocation loc39c(&this->location);
                    if (FUN_006d7490(&loc39c, ((void *)(((::Vec3 *)(void *)&(loc374)))), 0, 0))
                    {
                        bFlag361 = true;
                    }
                }
                this->timer14.FUN_008d7f40(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT< ::GameSettingCollection> *>(&::g_011cfad4))))))->f);
            }
            if (bFlag361 || ((bool)(reinterpret_cast<::TeleportableReference *>((pActor2))->GetTeleportDestinationForm())))
            {
                if (bFlag361)
                {
                    reinterpret_cast<::FUN_008b3ab0_shell *>((pActor2))->FUN_008b3ab0();
                }
                reinterpret_cast<::ProximityGroup *>((pContext))->UpdateProximityTimers(&this->location);
                this->state = 6;
                this->timer1c.FUN_008d7f40(1.0f);
            }
        }
        break;

    case 2:
        if (reinterpret_cast<::FUN_008b3b90_shell *>((pActor2))->FUN_008b3b90())
        {
            if (!reinterpret_cast<::FUN_008b3960_Class *>((pActor2))->FUN_008b3960() && this->m_pReference)
            {
                reinterpret_cast<::fnv_009a0ec0::FUN_009a0ec0_shell *>((pTile2))->SetNodeBlockAndTimestamp((const ::fnv_009a0ec0::FUN_009a0ec0_Block *)&(const ::Location16 &)((*(::Location16 *)(reinterpret_cast<::FUN_00575650_Class *>((this->m_pReference))->FUN_00575650({})))));
                reinterpret_cast<::CombatSearchMgr *>((pContext))->FUN_0098c710((intptr_t)(this->m_pReference));
            }
            reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)(reinterpret_cast<::FUN_008b3960_Class *>((pActor2))->FUN_008b3960() ? "Pathing failed while moving to search door"
                                                       : "Path Building failed to search door"));
            break;
        }
        if (((bool)(reinterpret_cast<::TeleportableReference *>((pActor2))->GetTeleportDestinationForm())))
        {
            if (this->m_pReference)
            {
                reinterpret_cast<::FUN_0098c6e0_class *>((pContext))->FUN_0098c6e0((intptr_t)(this->m_pReference));
                if (!hasTarget_2)
                {
                    reinterpret_cast<::fnv_008bcd60::FUN_008bcd60_Class *>((pActor2))->FUN_008bcd60();
                    this->state = 4;
                    this->timer1c.FUN_008d7f40(DAT_01017718);
                }
                else
                {
                    PathingRequestHelper req;
                    SearchRef* p3a0 = (SearchRef*)((void *)(reinterpret_cast<::TESObjectREFR *>((this->m_pReference))->GetExtraRadioData()));
                    if (!p3a0)
                    {
                        break;
                    }
                    reinterpret_cast<::ActorStandIn *>((pActor2))->BuildPathingRequest((::PathingRequest *)(void *)(&req), (*(const ::NiPoint3 *)(((void *)(reinterpret_cast<::BaseProcess *>((p3a0))->GetCurrentProcessData())))), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::Caller_43a3f0 *>((p3a0))->FUN_0043a3f0()))), 0.0f, (::PathingAvoidNodeArray *)(0));
                    if (!pActor2->SetPathingRequestAvoidNodes(&req))
                    {
                        reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)("Cannot setup path through search door"));
                        break;
                    }
                    this->state = 2;
                }
                this->m_pReference = 0;
            }
            else
            {
                this->state = 6;
                this->timer1c.FUN_008d7f40(1.0f);
            }
        }
        break;

    case 3: {
        bool bFlag455;
        if (reinterpret_cast<::FUN_008b3b90_shell *>((pActor2))->FUN_008b3b90())
        {
            if (!reinterpret_cast<::FUN_008b3960_Class *>((pActor2))->FUN_008b3960())
            {
                SearchRef* p45c = ((::SearchRef *)(reinterpret_cast<::C8B39D0Actor *>((pActor2))->FUN_008b39d0()));
                if (p45c && m_pPortalConnectivityGraphInfo)
                {
                    reinterpret_cast<::PathingLocationProxy *>((p45c))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
                    reinterpret_cast<::FUN_006e0bc0_shell *>((m_pPortalConnectivityGraphInfo))->FUN_006e0bc0((::BSAudio *)(p45c), 1);
                    reinterpret_cast<::FUN_00915d20_shell *>((pContext))->FUN_00915d20(1);
                }
            }
            reinterpret_cast<::FUN_009caac0_shell *>((this))->FUN_009caac0((intptr_t)(reinterpret_cast<::FUN_008b3960_Class *>((pActor2))->FUN_008b3960() ? "Pathing failed while searching"
                                                       : "Path Building failed to search"));
            break;
        }
        if (reinterpret_cast<::TimeoutTimer *>(&(this->timer24))->CheckTimer() && !hasTarget_2)
        {
            this->timer24.FUN_008d7f40(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting465))))->f);
            SearchRef* pObj460 = ((::SearchRef *)(reinterpret_cast<::CombatNodeFinder *>((pContext))->FindNearestCombatNode((::ActorS *)(pActor2), ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting463))))->f, 1)));
            if (pObj460)
            {
                PathingRequestHelper req;
                reinterpret_cast<::ActorStandIn *>((pActor2))->BuildPathingRequest((::PathingRequest *)(void *)(&req), (*(const ::NiPoint3 *)(const void *)&(reinterpret_cast<::fnv_00568fa0::Fn568fa0 *>((pObj460))->FUN_00568fa0())), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::s575ca0::Owner *>((pObj460))->FUN_00575ca0()))), 0.0f, (::PathingAvoidNodeArray *)(0));
                if (pActor2->SetPathingRequestAvoidNodes(&req))
                {
                    this->state = 2;
                    this->m_pReference = pObj460;
                    reinterpret_cast<::fnv_0098c750::FUN_0098c750_class *>((pContext))->FUN_0098c750((intptr_t)(pObj460));
                    break;
                }
            }
        }
        {
            bFlag455 = false;
            if (m_pPortalConnectivityGraphInfo && reinterpret_cast<::TimeoutTimer *>(&(this->timer14))->CheckTimer())
            {
                PathingLocation loc53c;
                if (pActor2->FUN_008b3860(&loc53c))
                {
                    NiPoint3 vDiff = pActor2->Position() - reinterpret_cast<::TaskQueueInterface *>((void *)&(loc53c))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
                    float dist = reinterpret_cast<::TESCombatStyle *>((void *)&(vDiff))->UpdateCombatStyle();
                    if (dist < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting457))))->f * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting457))))->f)
                    {
                        reinterpret_cast<::PathingLocationProxy *>(&(loc53c))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
                        if (reinterpret_cast<::PathingLocation *>(&(loc53c))->HasValidTriangle_006dd6a0() && reinterpret_cast<::FUN_006e0b50_cls *>((m_pPortalConnectivityGraphInfo))->FUN_006e0b50(&loc53c))
                        {
                            bFlag455 = true;
                            NavMeshPtr navMesh;
                            if (reinterpret_cast<::PathingLocation *>(&(loc53c))->ResolveNavMesh((*(::NavMeshPtr *)(&navMesh))))
                            {
                                char cRes = navMesh->FUN_006d8910(reinterpret_cast<::FUN_006df760_shell *>(&(loc53c))->GetShortValueAtOffset24());
                                if ((cRes == 1 && dist > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting459))))->f *
                                                             ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting459))))->f) ||
                                    (cRes == 2 && dist > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting458))))->f *
                                                             ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting458))))->f))
                                {
                                    bFlag455 = false;
                                }
                            }
                            if (bFlag455)
                            {
                                reinterpret_cast<::FUN_008b3ab0_shell *>((pActor2))->FUN_008b3ab0();
                            }
                        }
                    }
                }
                this->timer14.FUN_008d7f40(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT< ::GameSettingCollection> *>(&::g_011cecc4))))))->f);
            }
            if (bFlag455 || ((bool)(reinterpret_cast<::TeleportableReference *>((pActor2))->GetTeleportDestinationForm())))
            {
                this->state = 6;
                this->timer1c.FUN_008d7f40(1.0f);
            }
        }
        break;
    }

    case 4:
        if (((double)(reinterpret_cast<::ActorMagicQuery *>((pActor2))->GetMagicProcessValue())) <= ::_DAT_01012060)
        {
            if (this->m_pReference)
            {
                NiPoint3 rot = *((::NiPoint3 *)(reinterpret_cast<::fnv_00569000::TESObjectREFR_ext *>((this->m_pReference))->FUN_00569000()));
                reinterpret_cast<::FUN_005757d0_shell *>((pActor2))->FUN_005757d0(WrapAngle(rot.z));
            }
            this->state = 5;
        }
        break;

    case 5:
        if (reinterpret_cast<::TimeoutTimer *>(&(this->timer1c))->CheckTimer())
        {
            if (((double)(reinterpret_cast<::ActorMagicQuery *>((pActor2))->GetMagicProcessValue())) < ::g_01012070)
            {
                reinterpret_cast<::fnv_008bcd20::FUN_008bcd20_shell *>((pActor2))->FUN_008bcd20();
            }
            this->state = 0;
        }
        break;

    case 6:
        if (reinterpret_cast<::TimeoutTimer *>(&(this->timer1c))->CheckTimer())
        {
            this->state = 0;
        }
        break;

    case 7:
        if (((double)(reinterpret_cast<::CombatTargetTimestamp *>((((::RangeSub *)(reinterpret_cast<::FUN_009d9f40_Class *>((pContext))->FUN_009d9f40()))))->FUN_006a7f50())) < ((double)(reinterpret_cast<::CombatTargetTimestamp *>(&(this->timer1c))->FUN_006a7f50())))
        {
            if (((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)&(const ::Location16 &)((*(::Location16 *)(reinterpret_cast<::FUN_009d9f60_shell *>((pContext))->FUN_009d9f60({})))))->FUN_0084e3a0())) != ((void *)(reinterpret_cast<::s575ca0::Owner *>((pActor2))->FUN_00575ca0())))
            {
                break;
            }
        }
        if (reinterpret_cast<::TimeoutTimer *>(&(this->timer1c))->CheckTimer())
        {
            this->state = 0;
        }
        break;
    }
}

#include "generated/data/fallout/ai/combat/combatproceduresearch.inc"
