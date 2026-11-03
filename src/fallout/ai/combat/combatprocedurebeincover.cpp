
// src/fallout/ai/combat/combatprocedurebeincover.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedurebeincover.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/ActorCombatGroup.h"
#include "fnv/decl/CombatProcedureEx.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00480100_shell.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_005407b0_Class.h"
#include "fnv/decl/FUN_008854d0_.h"
#include "fnv/decl/FUN_008a88f0_cls.h"
#include "fnv/decl/FUN_008b3960_Class.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b3c90_class.h"
#include "fnv/decl/FUN_0097fa50_Class.h"
#include "fnv/decl/FUN_00996e00_shell.h"
#include "fnv/decl/FUN_00998a30_shell.h"
#include "fnv/decl/FUN_0099ccd0_shell.h"
#include "fnv/decl/FUN_009a03d0_cls.h"
#include "fnv/decl/FUN_009a0600_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/FUN_009d3390_cls.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S_008a8840.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008a8870__HA.h"
#include "fnv/decl/fnv_008b3880__FUN_008b3880_target.h"
#include "fnv/decl/fnv_00996e20__FUN_00996e20_shell.h"
#include "fnv/decl/fnv_00996e40__FUN_00996e40_shell.h"
#include "fnv/decl/fnv_00996ea0__MyProc.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_0097b000.h"
#include "fnv/symbols_0097f000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];
struct FUN_009d2510_shell : public TESAttributes
{
    unsigned int FUN_009d2510();
};

// @fnv 0x009d2510
unsigned int FUN_009d2510_shell::FUN_009d2510()
{
    return 7;
}

void __cdecl operator delete(void*);

struct FUN_009d2520_shell
{
    void __thiscall FUN_009d2550();
    void* __thiscall FUN_009d2520(unsigned int flags);
};

// Calls FUN_009d2550, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x009d2520
void* FUN_009d2520_shell::FUN_009d2520(unsigned int flags)
{
    FUN_009d2550();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_009d32e0_shell
{
    float __thiscall GetRandomFloatInRange();
};

// Returns a random float between the two floats stored at offsets 0x20 and 0x24 of this object.
// @fnv 0x009d32e0
float __thiscall FUN_009d32e0_shell::GetRandomFloatInRange()
{
    return ::RandomFloat(*(float*)(this + 0x20), *(float*)(this + 0x24));
}


struct FUN_009d3310_shell
{
    float __thiscall GetRandomFloat();
};

// Returns a random float between the two float values stored at offsets 0x28 and 0x2c of this object.
// @fnv 0x009d3310
float __thiscall FUN_009d3310_shell::GetRandomFloat()
{
    return ::RandomFloat(*(float*)((char*)this + 0x28), *(float*)((char*)this + 0x2c));
}


struct TESCombatStyle
{
    char pad[0x30];
    float m_fMinimum;
    float m_fMaximum;
    float __thiscall GetRandomValue();
public:
    float UpdateCombatStyle();
};

// Returns a random float between the combat style's two stored float fields.
// @fnv 0x009d3340
float __thiscall TESCombatStyle::GetRandomValue()
{
    return ::RandomFloat(m_fMinimum, m_fMaximum);
}

struct FUN_009ca6c0_shell
{
};
extern "C" int DAT_010910f4;

// @fnv 0x009d2550
void __thiscall FUN_009d2520_shell::FUN_009d2550()
{
    *reinterpret_cast<void**>(this) = &DAT_010910f4;
    reinterpret_cast<::FUN_009ca6c0_class *>((reinterpret_cast<FUN_009ca6c0_shell*>(this)))->FUN_009ca6c0();
}

struct Actor
{
};
struct TESAmmoInitCalls
{
};
struct CombatProcedure
{
};
struct CombatProcedureEngageTarget
{
};
struct FUN_009d2570_shell : public CombatProcedure
{
    char pad[4];
    TESAmmoInitCalls* m_pattacker;
    void StopAttackerAndEngageTarget();
};
// @fnv 0x009d2570
void FUN_009d2570_shell::StopAttackerAndEngageTarget()
{
    Actor* actor = ((::Actor *)(::GetFieldBC((::FUN_0097ae90_Class *)(m_pattacker))));
    reinterpret_cast<::FUN_008b3ab0_shell *>((actor))->FUN_008b3ab0();
    reinterpret_cast<::fnv_00996e40::FUN_00996e40_shell *>((((CombatProcedureEngageTarget*)this)))->FUN_00996e40();
    reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
}

struct FUN_00980070_shell
{
    unsigned int FUN_00980070();
};
struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float);
};
struct FUN_00996de0_Class
{
    Actor* FUN_00996de0();
};
struct Projectile;
struct FUN_009d33e0_shell : CombatProcedure
{
    void UpdateCombatProcedure(Projectile* apProjectile);
};
// @fnv 0x009d33e0
void FUN_009d33e0_shell::UpdateCombatProcedure(Projectile* apProjectile)
{
    switch (*(int*)((char*)this + 0x10))
    {
    case 1:
        ((FUN_008d7f40_shell*)((char*)this + 0x3c))
            ->FUN_008d7f40(((FUN_009d32e0_shell*)((FUN_00980070_shell*)*(int*)((char*)this + 4))->FUN_00980070())
                               ->GetRandomFloatInRange());
        break;
    case 2:
        reinterpret_cast<::FUN_008b3ab0_shell *>((((FUN_00996de0_Class*)this)->FUN_00996de0()))->FUN_008b3ab0();
        reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
        *(int*)((char*)this + 0x10) = 4;
        ((FUN_008d7f40_shell*)((char*)this + 0x4c))
            ->FUN_008d7f40(
                ((TESCombatStyle*)((FUN_00980070_shell*)*(int*)((char*)this + 4))->FUN_00980070())->GetRandomValue());
        break;
    }
}

struct Modifier
{
};

struct CTSHelper : public Modifier
{
};

struct FUN_0097fa50_shell : public CTSHelper
{
};

enum DEBUGTEXT_LOCATION
{
    DEBUGTEXT_LOCATION_0
};

enum DEBUGTEXT_JUSTIFY
{
    DEBUGTEXT_JUSTIFY_0
};

struct IDebugText
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void __cdecl Print(DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY, const char*, ...) = 0;
};

extern const char $SG2706[];
extern const char str_01091084[];
extern const char str_0109135c[];
extern const char str_01091380[];
extern const char str_010913a4[];
extern const char str_010913c8[];
extern const char str_010913ec[];
extern const char str_010913fc[];
extern const char str_01091414[];
extern const char str_01091420[];
extern const char str_01091434[];
extern const char str_01091458[];
extern const char str_01091474[];
extern const char str_0109148c[];
extern const char str_01091498[];
extern const char str_010914b0[];

struct CombatProcedureBeInCover
{
    enum COVER_STATE
    {
        INITIALIZING = 0,
        WAITING_BEHIND_COVER,
        MOVING_OUT,
        WAITING_OUT_OF_COVER,
        FIRING_OUT_OF_COVER,
        MOVING_IN,
        MOVING_IN_AND_ROTATE,
        HOLDING_GROUND
    };

    unsigned char _pad0[0x10];
    COVER_STATE eState;
    void* m_pCurrentCoverPoint;
    float m_afFirstVector[3];
    float m_afSecondVector[3];
    unsigned char _pad1[0x0C];

    FUN_0097fa50_shell m_waitTimer;
    unsigned char _pad2[7];
    FUN_0097fa50_shell m_waitingOutTimer;
    unsigned char _pad3[7];
    FUN_0097fa50_shell m_firingTimer;
    unsigned char _pad4[7];
    FUN_0097fa50_shell m_reevaluateTimer;
    unsigned char _pad5[7];
    FUN_0097fa50_shell m_holdingGroundTimer;
    unsigned char _pad6[7];
    FUN_0097fa50_shell m_targetBlockedTimer;

    void DebugText(IDebugText*, DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY);
};

// Prints debug text describing the current cover state and its timers, positions and target-blocked status via pDebugText.
// @fnv 0x009d3470
void CombatProcedureBeInCover::DebugText(IDebugText* pDebugText, DEBUGTEXT_LOCATION aeLocation,
                                         DEBUGTEXT_JUSTIFY aeJustify)
{
    switch (eState)
    {
    case INITIALIZING:
        pDebugText->Print(aeLocation, aeJustify, $SG2706);
        break;

    case WAITING_BEHIND_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_010914b0);
        pDebugText->Print(aeLocation, aeJustify, str_01091498, reinterpret_cast<::FUN_00435e00_t *>(&(m_waitTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(m_waitTimer))->FUN_006b9130());
        break;

    case MOVING_OUT:
        pDebugText->Print(aeLocation, aeJustify, str_0109148c);
        break;

    case WAITING_OUT_OF_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_01091474);
        pDebugText->Print(aeLocation, aeJustify, str_01091458, reinterpret_cast<::FUN_00435e00_t *>(&(m_waitingOutTimer))->FUN_00435e00(),
                          reinterpret_cast<::TimeoutTimer *>(&(m_waitingOutTimer))->FUN_006b9130());
        if (reinterpret_cast<::FUN_0097fa50_Class *>(&(m_targetBlockedTimer))->FUN_0097fa50())
        {
            pDebugText->Print(aeLocation, aeJustify, str_01091434, reinterpret_cast<::FUN_00435e00_t *>(&(m_targetBlockedTimer))->FUN_00435e00(),
                              reinterpret_cast<::TimeoutTimer *>(&(m_targetBlockedTimer))->FUN_006b9130());
        }
        break;

    case FIRING_OUT_OF_COVER:
        pDebugText->Print(aeLocation, aeJustify, str_01091420);
        pDebugText->Print(aeLocation, aeJustify, str_01091084, reinterpret_cast<::FUN_00435e00_t *>(&(m_firingTimer))->FUN_00435e00(),
                          reinterpret_cast<::TimeoutTimer *>(&(m_firingTimer))->FUN_006b9130());
        break;

    case MOVING_IN:
        pDebugText->Print(aeLocation, aeJustify, str_01091414);
        break;

    case MOVING_IN_AND_ROTATE:
        pDebugText->Print(aeLocation, aeJustify, str_010913fc);
        break;

    case HOLDING_GROUND:
        pDebugText->Print(aeLocation, aeJustify, str_010913ec);
        pDebugText->Print(aeLocation, aeJustify, str_010913c8, reinterpret_cast<::FUN_00435e00_t *>(&(m_holdingGroundTimer))->FUN_00435e00(),
                          reinterpret_cast<::TimeoutTimer *>(&(m_holdingGroundTimer))->FUN_006b9130());
        break;
    }

    if (reinterpret_cast<::FUN_0097fa50_Class *>(&(m_reevaluateTimer))->FUN_0097fa50())
    {
        pDebugText->Print(aeLocation, aeJustify, str_010913a4, reinterpret_cast<::FUN_00435e00_t *>(&(m_reevaluateTimer))->FUN_00435e00(),
                          reinterpret_cast<::TimeoutTimer *>(&(m_reevaluateTimer))->FUN_006b9130());
    }

    pDebugText->Print(aeLocation, aeJustify, str_01091380, m_afFirstVector[0], m_afFirstVector[1], m_afFirstVector[2]);

    pDebugText->Print(aeLocation, aeJustify, str_0109135c, m_afSecondVector[0], m_afSecondVector[1],
                      m_afSecondVector[2]);
}

struct CoverBaseCls
{
    virtual ~CoverBaseCls();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    CoverBaseCls();
};

struct CoverVec3
{
    float x;
    float y;
    float z;
    CoverVec3();
};

struct CoverTimer
{
    unsigned int unk00;
    unsigned int unk04;
    CoverTimer();
};

struct FUN_009d2440_cls : CoverBaseCls
{
    virtual void v0();
    int m_eAnimationState;
    void* m_pLocation;
    CoverVec3 m_curCover;
    CoverVec3 m_curFire;
    CoverVec3 m_thirdVec;
    CoverTimer m_t0;
    CoverTimer m_t1;
    CoverTimer m_t2;
    CoverTimer m_t3;
    CoverTimer m_t4;
    CoverTimer m_t5;
    FUN_009d2440_cls(void* pLoc);
    virtual ~FUN_009d2440_cls();
};

// @fnv 0x009d2440
FUN_009d2440_cls::FUN_009d2440_cls(void* pLoc) : m_eAnimationState(0), m_pLocation(pLoc)
{}

struct BGSSaveFormBuffer;
struct FUN_00996ed0_shell
{
public:
    void SaveToBuffer(::BGSSaveFormBuffer *);
};

struct FUN_00586150_shell
{
};

struct FUN_0097fb60_shell
{
    int GetFieldAtE8();
};

struct FUN_00865e50_shell
{
public:
    void FUN_00865e50(void *, unsigned int, unsigned int);
};

struct BGSSaveFormBuffer;
struct FUN_009a5eb0_shell
{
public:
    void FUN_009a5eb0(::BGSSaveFormBuffer *);
};

struct FUN_009d3800_cls
{
    void FUN_009d3800(void* a1);
};

class Tile;
struct BGSLoadFormBuffer
{
};
struct InterfaceManager
{
    Tile* FUN_00586150();
};
// @fnv 0x009d3800
void FUN_009d3800_cls::FUN_009d3800(void* a1)
{
    unsigned char flag;

    ((FUN_00996ed0_shell*)this)->SaveToBuffer((::BGSSaveFormBuffer *)(a1));
    flag = ((FUN_0097fb60_shell*)((void *)(reinterpret_cast<::InterfaceManager *>((((FUN_00586150_shell*)*(void**)((char*)this + 4))))->FUN_00586150())))->GetFieldAtE8() ==
           *(int*)((char*)this + 0x14);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x10, 4, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50(&flag, 1, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x18, 0xc, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x24, 0xc, 0);
    ((FUN_00865e50_shell*)a1)->FUN_00865e50((char*)this + 0x30, 0xc, 0);
    ((FUN_009a5eb0_shell*)((char*)this + 0x3c))->FUN_009a5eb0((::BGSSaveFormBuffer *)(a1));
    ((FUN_009a5eb0_shell*)((char*)this + 0x44))->FUN_009a5eb0((::BGSSaveFormBuffer *)(a1));
    ((FUN_009a5eb0_shell*)((char*)this + 0x4c))->FUN_009a5eb0((::BGSSaveFormBuffer *)(a1));
    ((FUN_009a5eb0_shell*)((char*)this + 0x54))->FUN_009a5eb0((::BGSSaveFormBuffer *)(a1));
    ((FUN_009a5eb0_shell*)((char*)this + 0x5c))->FUN_009a5eb0((::BGSSaveFormBuffer *)(a1));
    ((FUN_009a5eb0_shell*)((char*)this + 0x64))->FUN_009a5eb0((::BGSSaveFormBuffer *)(a1));
}

struct FUN_00996ef0_shell
{
    void FUN_00996ef0(BGSLoadFormBuffer* apBuffer);
};
struct FUN_009a5f20_Timer
{
    char data[8];
};
struct FUN_009d38f0_shell : FUN_00996ef0_shell
{
    void* vtbl;
    InterfaceManager* pManager;
    char pad08[8];
    int eState;
    unsigned int uiCoverLocation;
    float m_afFirstVector[3];
    float m_afSecondVector[3];
    float LastPosition[3];
    FUN_009a5f20_Timer kWaitTimer;
    FUN_009a5f20_Timer kWaitingOutTimer;
    FUN_009a5f20_Timer kTimer4c;
    FUN_009a5f20_Timer kTimer54;
    FUN_009a5f20_Timer kTimer5c;
    FUN_009a5f20_Timer kTimer64;
    void FUN_009d38f0(BGSLoadFormBuffer* apBuffer);
};
// Loads state, cover location, three 3-float vectors and six timers from the form buffer, resolving the cover location via the interface manager.
// @fnv 0x009d38f0
void FUN_009d38f0_shell::FUN_009d38f0(BGSLoadFormBuffer* apBuffer)
{
    FUN_00996ef0(apBuffer);
    bool bHasCover = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&eState), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bHasCover), 1);
    if (bHasCover)
        uiCoverLocation = ((FUN_0097fb60_shell*)pManager->FUN_00586150())->GetFieldAtE8();
    else
        uiCoverLocation = GetFieldValue((unsigned int*)pManager->FUN_00586150());
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(m_afFirstVector), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(m_afSecondVector), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(LastPosition), 0xc);
    reinterpret_cast<::TimeoutTimer *>(&(kWaitTimer))->LoadGame(apBuffer);
    reinterpret_cast<::TimeoutTimer *>(&(kWaitingOutTimer))->LoadGame(apBuffer);
    reinterpret_cast<::TimeoutTimer *>(&(kTimer4c))->LoadGame(apBuffer);
    reinterpret_cast<::TimeoutTimer *>(&(kTimer54))->LoadGame(apBuffer);
    reinterpret_cast<::TimeoutTimer *>(&(kTimer5c))->LoadGame(apBuffer);
    reinterpret_cast<::TimeoutTimer *>(&(kTimer64))->LoadGame(apBuffer);
}

struct CoverPoint
{
    float x, y, z;
    CoverPoint operator-(const CoverPoint&) const;
};
struct CoverClock
{
    int started;
    float duration;
};
struct CoverRequest
{
    virtual ~CoverRequest();
    CoverRequest();
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
};
struct CoverActor
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
    virtual CoverPoint GetAim();
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
    virtual const CoverPoint& GetPosition();

    bool RequestPath(CoverRequest*);
};
struct CombatCoverPoint
{
    int unk00, unk04;
    CoverPoint position;
    CoverPoint direction;
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
    bool occupied;
    bool CanFire();
};
struct CoverStamp
{
    int value;
};
struct CoverState
{
    CoverStamp GetStamp();
};
struct CoverGroup
{
};
struct CoverStyle
{
};
struct CoverManager
{
};
struct CoverSetting
{
};
struct CoverProcedure
{
    int unk00;
    CoverManager* manager;
    int unk08, unk0c;
    unsigned state;
    CombatCoverPoint* location;
    CoverPoint coverPosition, firePosition, lookPosition;
    CoverClock wait, outWait, firing, reevaluate, holding, blocked;
    CoverActor* FUN_00996de0();
    void UpdateCoverState();
};
static const char kCoverLOS[] = "Target has LOS on Cover position";
// Validates the cover location, reevaluates paths/LOS, and advances the cover procedure state machine through movement, firing and holding phases.
// @fnv 0x009d25b0
void CoverProcedure::UpdateCoverState()
{
    if (!reinterpret_cast<::FUN_009a0600_shell *>((((::CoverState *)(reinterpret_cast<::InterfaceManager *>((manager))->FUN_00586150()))))->FUN_009a0600((::CombatCoverPointData *)(location)))
    {
        reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cover Location no longer exists"));
        return;
    }
    CoverActor* actor_ = FUN_00996de0();
    CoverActor* targetTmp = ((::CoverActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    CoverState* combat7 = ((::CoverState *)(reinterpret_cast<::InterfaceManager *>((manager))->FUN_00586150()));
    CoverGroup* group7 = ((::CoverGroup *)(reinterpret_cast<::EffectSetting *>((manager))->GetCastSound()));
    bool evaluatedA = false;
    bool changedVal = false;
    bool canFire4 = location->CanFire();
    bool active8 = reinterpret_cast<::FUN_00998a30_shell *>((manager))->FUN_00998a30();
    if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(reevaluate))->FUN_0097fa50())
        reinterpret_cast<::FUN_008d7f40_shell *>(&(reevaluate))->FUN_008d7f40(1.0f);
    else if (reinterpret_cast<::TimeoutTimer *>(&(reevaluate))->CheckTimer())
    {
        reinterpret_cast<::FUN_008d7f40_shell *>(&(reevaluate))->FUN_008d7f40(1.0f);
        evaluatedA = true;
        if (state != 0)
        {
            if (::FUN_0097fb20((::CombatState *)(combat7)))
            {
                bool reachable4 = reinterpret_cast<::FUN_0099ccd0_shell *>((combat7))->FUN_0099ccd0((::Seg99 *)&(location->direction), (::NiPoint3Ex *)&(coverPosition), (::FUN_0099ccd0_Actor *)(targetTmp), 1);
                if (!reachable4 && state != 7)
                {
                    reinterpret_cast<::FUN_008b3ab0_shell *>((actor_))->FUN_008b3ab0();
                    reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
                    state = 7;
                    reinterpret_cast<::FUN_008d7f40_shell *>(&(holding))->FUN_008d7f40(2.0f);
                    changedVal = true;
                }
            }
            else
            {
                CoverPoint coverPos9 = targetTmp->GetPosition();
                CoverPoint targetPos = location->position;
                CoverPoint delta = coverPos9 - targetPos;
                if (reinterpret_cast<::TESCombatStyle *>((void *)&(delta))->UpdateCombatStyle() > 589824.0 && ((bool)(reinterpret_cast<::ActorCombatGroup *>((group7))->GetByteAtOffset100((int)(targetTmp)))))
                    reinterpret_cast<::FUN_005407b0_Class *>((location))->FUN_005407b0(1);
            }
        }
    }
    switch (state)
    {
    case 0: {
        location->occupied = false;
        ::fnv_009a9370::FUN_009a9370((::fnv_009a9370::CombatController *)(manager), (::fnv_009a9370::CombatCoverPointData *)(location), (::fnv_009a9370::NiPoint3 *)&(coverPosition), (::fnv_009a9370::NiPoint3 *)&(firePosition));
        lookPosition = firePosition;
        float height = reinterpret_cast<::FUN_00998a30_shell *>((manager))->FUN_00998a30() ? reinterpret_cast<::FUN_008854d0_ *>((actor_))->FUN_008854d0(false) : reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(actor_))->GetActorHeight();
        lookPosition.z = height * 0.75 + lookPosition.z;
        CoverRequest request;
        reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor_))->PathToLocation((::fnv_008b3880::PathingRequest *)&(request), (void *)&(coverPosition), ((void *)(reinterpret_cast<::LowProcess *>((actor_))->GetTarget())), ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor_))->FUN_00575d70())), 0.0f, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
        if (!actor_->RequestPath(&request))
        {
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to Cover position"));
            return;
        }
        state = 6;
        if (((bool)(reinterpret_cast<::FUN_009d3390_cls *>((location))->FUN_009d3390())))
            reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((const ::NiPoint3 &)(lookPosition), 3);
        reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(3);
        break;
    }
    case 1: {
        if (!reinterpret_cast<::fnv_008a8870::HA *>((actor_))->FUN_008a8870())
        {
            if (reinterpret_cast<::FUN_00435e00_t *>((void *)&(const ::CoverStamp &)(combat7->GetStamp()))->FUN_00435e00() > 0.5 &&
                reinterpret_cast<::FUN_008a88f0_cls *>((actor_))->FUN_008a88f0() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CoverSetting *>(&::originalRuntimeFloatSetting378)))))))
            {
                reinterpret_cast<::S_008a8840 *>((actor_))->FUN_008a8840();
            }
            else if (reinterpret_cast<::TimeoutTimer *>(&(wait))->CheckTimer())
            {
                CoverRequest request;
                reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor_))->PathToLocation((::fnv_008b3880::PathingRequest *)&(request), (void *)&(firePosition), ((void *)(reinterpret_cast<::LowProcess *>((actor_))->GetTarget())), ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor_))->FUN_00575d70())), 0.0f, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
                if (!actor_->RequestPath(&request))
                {
                    reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to Fire position"));
                    return;
                }
                if (((bool)(reinterpret_cast<::FUN_009d3390_cls *>((location))->FUN_009d3390())))
                    reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
                reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((const ::NiPoint3 &)((const ::CoverPoint &)(targetTmp->GetAim())), 1);
                state = 2;
                reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(canFire4 && active8 ? 2 : 1);
            }
        }
        break;
    }
    case 2: {
        if (reinterpret_cast<::FUN_008b3b90_shell *>((actor_))->FUN_008b3b90())
        {
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actor_))->FUN_008b3960() ? "Pathing failed while moving out" : "Path Building failed to move out"));
            return;
        }
        if (((bool)(reinterpret_cast<::TeleportableReference *>((actor_))->GetTeleportDestinationForm())))
        {
            state = 3;
            reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
            reinterpret_cast<::FUN_008d7f40_shell *>(&(outWait))->FUN_008d7f40(reinterpret_cast<::FUN_009d3310_shell *>((((::CoverStyle *)(reinterpret_cast<::FUN_00980070_shell *>((manager))->FUN_00980070()))))->GetRandomFloat());
        }
        break;
    }
    case 3: {
        CoverStamp stamp = combat7->GetStamp();
        if (reinterpret_cast<::CombatTargetTimestamp *>(&(stamp))->FUN_006a7f50() > reinterpret_cast<::CombatTargetTimestamp *>(&(wait))->FUN_006a7f50())
        {
            state = 4;
            reinterpret_cast<::FUN_008d7f40_shell *>(&(firing))->FUN_008d7f40(reinterpret_cast<::TESCombatStyle *>((((::CoverStyle *)(reinterpret_cast<::FUN_00980070_shell *>((manager))->FUN_00980070()))))->GetRandomValue());
            reinterpret_cast<::TimeoutTimer *>(&(blocked))->FUN_00910b10();
        }
        else if (reinterpret_cast<::TimeoutTimer *>(&(outWait))->CheckTimer())
        {
            reinterpret_cast<::FUN_009a03d0_cls *>((combat7))->FUN_009a03d0(0);
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Waited out of cover without firing"));
            return;
        }
        else if (reinterpret_cast<::FUN_00435e00_t *>(&(outWait))->FUN_00435e00() > 2.0 && !::FUN_0097fb20((::CombatState *)(combat7)) && ((bool)(reinterpret_cast<::ActorCombatGroup *>((group7))->GetByteAtOffset100((int)(targetTmp)))))
        {
            reinterpret_cast<::FUN_009a03d0_cls *>((combat7))->FUN_009a03d0(0);
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Waited out of cover and group member has LOS on target"));
            return;
        }
        if (((bool)(reinterpret_cast<::FUN_008b3c90_class *>((combat7))->GetByteAtOffset114())))
        {
            if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(blocked))->FUN_0097fa50())
                reinterpret_cast<::FUN_008d7f40_shell *>(&(blocked))->FUN_008d7f40(2.0f);
            else if (reinterpret_cast<::TimeoutTimer *>(&(blocked))->CheckTimer())
            {
                reinterpret_cast<::FUN_009a03d0_cls *>((combat7))->FUN_009a03d0(1);
                reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Waited out of cover but was blocked"));
                return;
            }
        }
        break;
    }
    case 4: {
        float attackTime_ = reinterpret_cast<::FUN_008a88f0_cls *>((actor_))->FUN_008a88f0();
        if (attackTime_ < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CoverSetting *>(&::originalRuntimeFloatSetting379)))))) || reinterpret_cast<::fnv_008a8870::HA *>((actor_))->FUN_008a8870() || reinterpret_cast<::TimeoutTimer *>(&(firing))->CheckTimer())
        {
            CoverRequest request;
            reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor_))->PathToLocation((::fnv_008b3880::PathingRequest *)&(request), (void *)&(coverPosition), ((void *)(reinterpret_cast<::LowProcess *>((actor_))->GetTarget())), ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor_))->FUN_00575d70())), 0.0f, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
            if (!actor_->RequestPath(&request))
            {
                reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to move back to Cover position"));
                return;
            }
            reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(canFire4 && active8 ? 2 : 1);
            state = 5;
        }
        break;
    }
    case 5: {
        if (reinterpret_cast<::FUN_008b3b90_shell *>((actor_))->FUN_008b3b90())
        {
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actor_))->FUN_008b3960() ? "Pathing failed while moving in" : "Path Building failed to move in"));
            return;
        }
        if (((bool)(reinterpret_cast<::TeleportableReference *>((actor_))->GetTeleportDestinationForm())))
        {
            state = 1;
            reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
            reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(2);
            reinterpret_cast<::FUN_008d7f40_shell *>(&(wait))->FUN_008d7f40(reinterpret_cast<::FUN_009d32e0_shell *>((((::CoverStyle *)(reinterpret_cast<::FUN_00980070_shell *>((manager))->FUN_00980070()))))->GetRandomFloatInRange());
        }
        else
        {
            float dist9 = reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::CoverPoint &)((actor_->GetPosition() - coverPosition)))->UpdateCombatStyle();
            if (dist9 < 1024.0)
            {
                state = 6;
                if (((bool)(reinterpret_cast<::FUN_009d3390_cls *>((location))->FUN_009d3390())))
                    reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((const ::NiPoint3 &)(lookPosition), 3);
                reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(1);
            }
        }
        break;
    }
    case 6: {
        if (reinterpret_cast<::FUN_008b3b90_shell *>((actor_))->FUN_008b3b90())
        {
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actor_))->FUN_008b3960() ? "Pathing failed while moving in and rotating"
                                           : "Path Building failed to move in and rotate"));
            return;
        }
        if (((bool)(reinterpret_cast<::TeleportableReference *>((actor_))->GetTeleportDestinationForm())))
        {
            state = 1;
            reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(2);
            reinterpret_cast<::FUN_008d7f40_shell *>(&(wait))->FUN_008d7f40(reinterpret_cast<::FUN_009d32e0_shell *>((((::CoverStyle *)(reinterpret_cast<::FUN_00980070_shell *>((manager))->FUN_00980070()))))->GetRandomFloatInRange());
        }
        break;
    }
    case 7: {
        if (evaluatedA && !changedVal)
        {
            CoverRequest request;
            reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor_))->PathToLocation((::fnv_008b3880::PathingRequest *)&(request), (void *)&(coverPosition), ((void *)(reinterpret_cast<::LowProcess *>((actor_))->GetTarget())), ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor_))->FUN_00575d70())), 0.0f, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
            if (!actor_->RequestPath(&request))
            {
                reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to move back to Cover position"));
                return;
            }
            reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(canFire4 && active8 ? 2 : 1);
            state = 5;
        }
        else if (reinterpret_cast<::TimeoutTimer *>(&(holding))->CheckTimer())
        {
            reinterpret_cast<::FUN_009a03d0_cls *>((combat7))->FUN_009a03d0(0);
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(kCoverLOS));
            return;
        }
        else if (reinterpret_cast<::FUN_00435e00_t *>(&(holding))->FUN_00435e00() > reinterpret_cast<::TimeoutTimer *>(&(holding))->FUN_006b9130() / 4.0)
        {
            CoverPoint delta = targetTmp->GetPosition();
            CoverPoint targetPos = actor_->GetPosition();
            CoverPoint actorPos6 = targetPos - delta;
            if (reinterpret_cast<::TESCombatStyle *>((void *)&(actorPos6))->UpdateCombatStyle() < 262144.0)
            {
                reinterpret_cast<::FUN_009a03d0_cls *>((combat7))->FUN_009a03d0(0);
                reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(kCoverLOS));
            }
        }
        break;
    }
    }
}
