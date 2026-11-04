
// src/fallout/ai/combat/combatprocedureattackgrenade.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureattackgrenade.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/S_009a7670_P3.h"
#include "fnv/symbols_009a7000.h"
#include "fnv/combat_controller_fields.h"
#include <cstdint>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/CPStandIn009caae0.h"
#include "fnv/decl/CombatDialogueHandler.h"
#include "fnv/decl/CombatProcedureEx.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0070f490_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00894900_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_008d7f40_shell.h"
#include "fnv/decl/FUN_00966a00_Class.h"
#include "fnv/decl/FUN_0097fa50_Class.h"
#include "fnv/decl/FUN_00981970_shell.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996e00_shell.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/Pawn.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/ThreatManager.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0097ee90__DummyInner.h"
#include "fnv/decl/fnv_00996ea0__MyProc.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_008b3000.h"
#include "fnv/symbols_00906000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_009a8000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011f1000.h"
struct CombatProcedure
{
};

struct CombatProcedureAttackGrenade : CombatProcedure
{
    void FUN_009cafc0();
};

// @fnv 0x009cafc0
void CombatProcedureAttackGrenade::FUN_009cafc0()
{
    reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
}

struct FUN_009cb440_shell
{
    void FUN_009cb440(unsigned char b);
};

// @fnv 0x009cb440
void FUN_009cb440_shell::FUN_009cb440(unsigned char b)
{
    *reinterpret_cast<unsigned char*>(this + 0x73) = b;
}


struct FUN_009caeb0_shell
{
    void* FUN_009caeb0(unsigned int flags);
};

extern int DAT_010909bc;
struct FUN_009ca6c0_shell
{
};
struct FUN_009cafa0_shell
{
    void FUN_009cafa0();
};
// Calls FUN_009cafa0, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009caeb0
void* FUN_009caeb0_shell::FUN_009caeb0(unsigned int flags)
{
    reinterpret_cast<::FUN_009cafa0_shell *>(this)->FUN_009cafa0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x009cafa0
void FUN_009cafa0_shell::FUN_009cafa0()
{
    *reinterpret_cast<int**>(this) = &DAT_010909bc;
    reinterpret_cast<::FUN_009ca6c0_class *>((reinterpret_cast<FUN_009ca6c0_shell*>(this)))->FUN_009ca6c0();
}

struct Setting_S
{
};
struct Projectile
{
};
struct IMH
{
};
struct Helper_caae0
{
};
struct FUN_009cb830_shell
{
    void FUN_009cb830(Projectile* apProjectile);
    char pad00[0x14];
    bool unk14;
    char pad15[0x1b];
    bool unk30;
};
// @fnv 0x009cb830
void FUN_009cb830_shell::FUN_009cb830(Projectile* apProjectile)
{
    if (this->unk30)
    {
        reinterpret_cast<::FUN_00966a00_Class *>((apProjectile))->FUN_00966a00(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting375)))))));
    }
    this->unk30 = 0;
    if (this->unk14)
    {
        ((::FUN_009cb440_shell *)(reinterpret_cast<::InterfaceManager *>(((*(IMH**)((char*)this + 4))))->FUN_00586150()))->FUN_009cb440(1);
        reinterpret_cast<::CPStandIn009caae0 *>((((Helper_caae0*)this)))->SetState();
    }
}

struct BGSSaveFormBuffer
{
};
struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer* p);
};
struct CombatProcedureSaveGameShell
{
};
struct FUN_009cb9c0_shell
{
    void FUN_009cb9c0(BGSSaveFormBuffer* p);
};
// @fnv 0x009cb9c0
void FUN_009cb9c0_shell::FUN_009cb9c0(BGSSaveFormBuffer* pBuffer)
{
    reinterpret_cast<::FUN_00996ed0_shell *>((((CombatProcedureSaveGameShell*)this)))->SaveToBuffer(pBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x10, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x14, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x18, 0xc, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x24, 0xc, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x30, 1, 0);
    ((FUN_009a5eb0_shell*)((char*)this + 0x34))->FUN_009a5eb0(pBuffer);
}

struct BGSLoadFormBuffer
{
};
struct CombatProcedure_LoadGame
{
};
struct TimeoutTimer
{
    void LoadGame(BGSLoadFormBuffer* p);
public:
    float FUN_006b9130();
public:
    bool CheckTimer();
public:
    void FUN_00910b10();
};
struct FUN_009cba50_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_aa;
    int m_ab;
    int m_ac;
    int m_ad;
    int m_ae;
    int m_af;
    int m_ag;
    int m_ah;
    int m_ai;
    int m_aj;
    int m_ak;
    int m_al;
    int m_am;
    int m_an;
    int m_ao;
    int m_ap;
    int m_aq;
    int m_ar;
    int m_as;
    int m_at;
    int m_au;
    int m_av;
    int m_aw;
    int m_ax;
    int m_ay;
    int m_az;
    void FUN_009cba50(BGSLoadFormBuffer* buffer);
};
// @fnv 0x009cba50
void FUN_009cba50_shell::FUN_009cba50(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>((((CombatProcedure_LoadGame*)this)))->FUN_00996ef0(buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_usTrailingValue), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_f), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_g), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iUnknownValue), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iUnknownValue2), 1);
    ((TimeoutTimer*)&this->m_uiValueCount)->LoadGame(buffer);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    void FUN_006815c0();
public:
    static const ::NiPoint3 ZERO;
};
struct NonPodPoint3
{
    float x;
    float y;
    float z;
    NonPodPoint3();
};
NiPoint3* __cdecl FUN_009a8050(NiPoint3* result, void* actor);
void __cdecl GetTargetLocationWithOffset(NiPoint3* result, void* target, int mode);
// @fnv 0x009a7580
unsigned char __cdecl FUN_009a7580(void* actor, void* target, FUN_009a7f00_obj* apObject, NiPoint3* optionalOrigin,
                                   unsigned char* apFlag, S_009a7670_P3* apResult, float scale)
{
    if (!actor || !target)
        return 0;
    NiPoint3 offset;
    offset.FUN_006815c0();
    if (optionalOrigin)
        offset = *optionalOrigin;
    else
    {
        NiPoint3 temp;
        offset = *FUN_009a8050(&temp, actor);
    }
    NiPoint3 origin;
    GetTargetLocationWithOffset(&origin, target, 2);
    NonPodPoint3 direction = (*(::NonPodPoint3 *)(::GetTriple12((::Triple12 *)(target), {})));
    return ::FUN_009a7670(actor, target, apObject, *reinterpret_cast<S_009a7670_P3*>(&offset),
                          *reinterpret_cast<S_009a7670_P3*>(&origin), *reinterpret_cast<S_009a7670_P3*>(&direction), apFlag,
                          apResult, scale);
}

struct Vec3
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};

extern int DAT_010909bc;

struct CombatBaseObj
{
    void* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    CombatBaseObj();
};

struct CombatMember34
{
    int m_00;
    ~CombatMember34();
};

struct FUN_009cadf0_cls : CombatBaseObj
{
    int m_10;
    unsigned char m_14;
    Vec3 m_18;
    Vec3 m_24;
    unsigned char m_30;
    CombatMember34 m_34;
    FUN_009cadf0_cls();
};

// Initialises the object: sets the vtable, zeroes m_10/m_14/m_30, copies DAT_011f426c into m_18 and m_24, and calls m_34.Init().
// @fnv 0x009cadf0
FUN_009cadf0_cls::FUN_009cadf0_cls()
{
    m_vptr = &DAT_010909bc;
    m_10 = 0;
    m_14 = 0;
    m_18 = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
    m_24 = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
    m_30 = 0;
    ::FUN_00906f60((float *)&(m_34));
}

namespace fnv_009caee0 {
struct Vec3_b6365
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};


class Base_b6365
{
  public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    Base_b6365();
    ~Base_b6365();
};

class Member_b6365
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
};

class FUN_009caee0 : public Base_b6365
{
  public:
    virtual ~FUN_009caee0();
    unsigned char m_14;
    Vec3_b6365 m_18;
    Vec3_b6365 m_24;
    unsigned char m_30;
    Member_b6365 m_34;

    FUN_009caee0(const Vec3_b6365* src, unsigned char flag);
};

// Initialises the object: stores a copy of src into m_18, sets m_24 from DAT_011f426c, m_14 to 1, m_30 to flag, and resets m_34.
// @fnv 0x009caee0
FUN_009caee0::FUN_009caee0(const Vec3_b6365* src, unsigned char flag) : Base_b6365()
{
    m_10 = 0;
    m_14 = 1;
    m_18 = *src;
    m_24 = (*reinterpret_cast<::fnv_009caee0::Vec3_b6365 *>((void *)&::NiPoint3::ZERO));
    m_30 = flag;
    ::FUN_00906f60((float *)&(m_34));
}
}  // namespace fnv_009caee0

class B9CB380Form;
class B9CB380Mobile;

class B9CB380Process
{
  public:
};

class B9CB380Actor
{
  public:
};

class B9CB380World
{
  public:
};

class B9CB380Setting
{
  public:
};

class B9CB380Timer
{
  public:

    int unk00;
};


class B9CB380Package
{
  public:
    int unk00;
    B9CB380Actor* m_pkActor;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bFlag14;
    char unk15;
    short unk16;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    B9CB380Timer m_kTimer;

    bool FUN_009cb380(B9CB380Form* pkForm, intptr_t iArg, float fArg);
};

// @fnv 0x009cb380
bool B9CB380Package::FUN_009cb380(B9CB380Form* pkForm, intptr_t iArg, float fArg)
{
    B9CB380Mobile* pkMobile2 = ((::B9CB380Mobile *)(reinterpret_cast<CombatControllerFields*>(m_pkActor)->pActor));
    B9CB380Process* pkProcess = ((::B9CB380Process *)(reinterpret_cast<::InterfaceManager *>((m_pkActor))->FUN_00586150()));
    if (!reinterpret_cast<::ThreatManager *>(((*reinterpret_cast<::B9CB380World * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->IsThreatWithinLimits((::ThreatActor *)(pkMobile2), (::ThreatActor *)(pkForm), (*(const ::ThreatPosition *)(iArg)), fArg))
    {
        if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(m_kTimer))->FUN_0097fa50())
            reinterpret_cast<::FUN_008d7f40_shell *>(&(m_kTimer))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::B9CB380Setting *>(&::originalRuntimeFloatSetting358)))))));
        else if (reinterpret_cast<::TimeoutTimer *>(&(m_kTimer))->CheckTimer())
            reinterpret_cast<::TESObjectACTI *>((pkProcess))->SetActivateSound((::TESSound *)(pkForm));
        if (m_bFlag14)
        {
            reinterpret_cast<::FUN_009cb440_shell *>((pkProcess))->FUN_009cb440(true);
            reinterpret_cast<::CPStandIn009caae0 *>(this)->SetState();
        }
        return false;
    }
    return true;
}

namespace fnv_009cb6e0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
};


struct Actor;
struct PathingRequest
{
};
struct TESObjectREFR
{
};
struct InterfaceManager
{
};

NiPoint3 __cdecl ComputeTrajectory(Actor* actor, void* target, int unused, PathingRequest* req, float dist, bool flag);
NiPoint3 __cdecl FUN_009a8d80(Actor* actor, NiPoint3* point, int unused, PathingRequest* req, float dist, bool flag);

struct CombatProcedureShell
{
    int unk00;
    InterfaceManager* unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool b14;
    NiPoint3 pt18;
    int unk24;
    int unk28;
    int unk2C;
    bool b30;

    NiPoint3 GetPathingPoint();
};

// @fnv 0x009cb6e0
NiPoint3 CombatProcedureShell::GetPathingPoint()
{
    if (!b14 && !reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00())
    {
        return (*reinterpret_cast<const ::fnv_009cb6e0::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    }
    TESObjectREFR* ref = ((::fnv_009cb6e0::TESObjectREFR *)(::FUN_007031c0((intptr_t)(unk04))));
    PathingRequest* req = ((::fnv_009cb6e0::PathingRequest *)(reinterpret_cast<::Thing *>((ref))->GetOrFallback((intptr_t)(((::fnv_009cb6e0::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))))));
    float dist = ::GetFloatAtOffset68((const char *)(req)) * (b30 ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting375)))))) : 1.0f);
    NiPoint3 point;
    if (!b14)
    {
        point = ComputeTrajectory(((::fnv_009cb6e0::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0())), reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00(), 0, req, dist, b30);
    }
    else
    {
        point = FUN_009a8d80(((::fnv_009cb6e0::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0())), &pt18, 0, req, dist, b30);
    }
    return point;
}
}  // namespace fnv_009cb6e0

struct Point
{
    float x, y, z;
    Point();
};
struct Target
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
    virtual Point* Position();
};
struct Item
{
};
struct Manager
{
};
struct Process
{
};
struct Owner
{
};
struct Procedure
{
    int unk00;
    Owner* owner;
    int unk08, unk0c, unk10;
    unsigned char active;
    Point origin;
    Point destination;
    unsigned char category;
    bool FUN_009cb460(Point* output, Point* input);
};
unsigned char Arc(void*, Target*, Item*, Point, Point, Point, unsigned char*, Point*, float);
unsigned char Direct(void*, Target*, Item*, Point*, unsigned char*, Point*, float);
float Distance(Item*, Point, Point, unsigned char, float);
// @fnv 0x009cb460
bool Procedure::FUN_009cb460(Point* output, Point* input)
{
    void* i;
    i = ((void *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Target* targetVal;
    targetVal = ((::Target *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    Manager* sound;
    sound = ((::Manager *)(::FUN_007031c0((intptr_t)(owner))));
    Item* z;
    z = ((::Item *)(reinterpret_cast<::Thing *>((sound))->GetOrFallback((intptr_t)(i))));
    void* pForm;
    pForm = ((void *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(z))));
    bool ptr;
    ptr = false;
    if (active)
    {
        if (Arc(i, targetVal, z, *input, origin, (*reinterpret_cast<::Point *>((void *)&::NiPoint3::ZERO)), &category, &destination, ::DAT_01012054))
        {
            *output = destination;
            ptr = true;
        }
    }
    else
    {
        if (Direct(((void *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0())), ((::Target *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00())), ((::Item *)(reinterpret_cast<::Thing *>((sound))->GetOrFallback((intptr_t)(i)))), input, &category, &destination, ::DAT_01012054))
        {
            *output = destination;
            ptr = true;
        }
    }
    if (ptr && pForm)
    {
        Point position7;
        if (active)
            position7 = origin;
        else
        {
            position7 = destination;
            position7.z = targetVal->Position()->z;
        }
        float distance7;
        distance7 = Distance(z, *input, position7, category, 0.0f);
        if (!reinterpret_cast<::B9CB380Package *>(this)->FUN_009cb380((::B9CB380Form *)(pForm), (intptr_t)(&position7), distance7))
            ptr = false;
    }
    if (!ptr && active)
    {
        reinterpret_cast<::FUN_009cb440_shell *>((((::Process *)(reinterpret_cast<::InterfaceManager *>((owner))->FUN_00586150()))))->FUN_009cb440(1);
        reinterpret_cast<::CPStandIn009caae0 *>(this)->SetState();
    }
    return ptr;
}

namespace fnv_009cafe0 {
struct Pt3
{
    float x;
    float y;
    float z;
};

struct Obj70
{
};
struct ProcessObj
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual bool vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c(int a);
};
struct ActorObj
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual Obj70* vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual Pt3* vfn_1f4();
};
struct SoundObj
{
    int s00;
};
struct MidObj
{
};
struct Obj703
{
};
struct Obj586
{
};
struct Sub04
{
};
struct GlobalObj
{
};
struct Member34
{
};

struct Package
{
    int unk00;
    Sub04* m_04;
    int unk08;
    int unk0c;
    int m_10;
    unsigned char m_14;
    unsigned char m_15;
    short m_16;
    Pt3 m_18;
    Pt3 m_24;
    unsigned char m_30;
    unsigned char m_31;
    unsigned char m_32;
    unsigned char m_33;
    Member34 m_34;
    Pt3* GetPathingPoint(Pt3* out);
    void UpdateWeaponFire();
};

// @fnv 0x009cafe0
void Package::UpdateWeaponFire()
{
    ActorObj* actor2;
    actor2 = ((::fnv_009cafe0::ActorObj *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    ActorObj* i;
    i = ((::fnv_009cafe0::ActorObj *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    Obj586* n;
    n = ((::fnv_009cafe0::Obj586 *)(reinterpret_cast<::InterfaceManager *>((m_04))->FUN_00586150()));
    Obj703* s;
    s = ((::fnv_009cafe0::Obj703 *)(::FUN_007031c0((intptr_t)(m_04))));
    Obj70* aPObj;
    aPObj = actor2->vfn_1e4();
    if (!s || !aPObj || !((::fnv_009cafe0::MidObj *)(reinterpret_cast<::Thing *>((s))->GetOrFallback((intptr_t)(actor2)))))
    {
        reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((intptr_t)("Missing either weapon, animation, or weapon projectile"));
        return;
    }
    if (reinterpret_cast<::FUN_00894900_shell *>((actor2))->FUN_00894900())
    {
        m_10 = 1;
    }
    else if (reinterpret_cast<::FUN_008a7570_shell *>((actor2))->FUN_008a7570() == -1)
    {
        m_10 = 0;
    }
    if (!m_14 && !m_10)
    {
        m_30 = 0;
    }
    if (!reinterpret_cast<::fnv_0097ee90::DummyInner *>((n))->FUN_0097ee90() || ::fnv_008b3c10::FUN_008b3c10((::fnv_008b3c10::CombatState *)(n)))
    {
        if (m_10)
        {
            reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
            m_10 = 0;
        }
        return;
    }
    reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::fnv_009cafe0::GlobalObj * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(m_04), 2, 0, 0);
    Pt3 AJ;
    m_24 = *GetPathingPoint(&AJ);
    Pt3 dir3;
    dir3.x = 0.0f;
    dir3.y = 0.0f;
    dir3.z = 0.0f;
    ::FUN_009a9180((::S_009a9180_Actor *)(m_04), (::S_009a9180_Data *)(s), &dir3.x, &dir3.y, &dir3.z);
    Pt3 kIter;
    reinterpret_cast<::FUN_00439ef0_class *>(&(m_24))->FUN_00439ef0((::NiPoint3 *)(::fnv_009cafe0::Pt3 *)(&kIter), (*(const ::NiPoint3 *)(actor2->vfn_1f4())));
    if (reinterpret_cast<::FUN_00595c80_shell *>(&(kIter))->GetSquaredXYLength() > dir3.z * dir3.z)
    {
        reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
        m_10 = 0;
        return;
    }
    if (reinterpret_cast<::NiPlane *>(&(m_24))->operator==((*(const ::NiPlane *)((Pt3*)&(*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO))))))
    {
        reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((*(const ::NiPoint3 *)(&m_24)), 4);
    }
    if (1 == m_10 && (reinterpret_cast<::FUN_008a7570_shell *>((actor2))->FUN_008a7570() != 4 || reinterpret_cast<::FUN_0070f490_Class *>((aPObj))->GetSlotValue(4) > 2))
    {
        return;
    }
    if (!((::fnv_009cafe0::ProcessObj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor2))->GetBaseTexture()))->vfn_3f8() || ((bool)(reinterpret_cast<::FUN_00981970_shell *>((m_04))->FUN_00981970())))
    {
        return;
    }
    SoundObj* idx;
    idx = ((::fnv_009cafe0::SoundObj *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::fnv_009cafe0::MidObj *)(reinterpret_cast<::Thing *>((s))->GetOrFallback((intptr_t)(actor2))))))));
    Pt3* AP;
    Pt3 CTmp;
    if (idx)
    {
        AP = m_14 ? &m_18 : i->vfn_1f4();
        CTmp = *AP;
        if (!reinterpret_cast<::B9CB380Package *>(this)->FUN_009cb380((::B9CB380Form *)(idx), (intptr_t)(&CTmp), 0.0f))
        {
            return;
        }
    }
    MidObj* pForm;
    pForm = ((::fnv_009cafe0::MidObj *)(reinterpret_cast<::Thing *>((s))->GetOrFallback((intptr_t)(actor2))));
    if (!m_14)
    {
        if (!::FUN_009a7580(actor2, i, (::FUN_009a7f00_obj *)(pForm), 0, &m_30, reinterpret_cast<::S_009a7670_P3 *>(&m_24), -1.0f))
        {
            return;
        }
    }
    if (idx)
    {
        reinterpret_cast<::TESObjectACTI *>((n))->SetActivateSound((::TESSound *)(0));
        reinterpret_cast<::TimeoutTimer *>(&(m_34))->FUN_00910b10();
    }
    ((::fnv_009cafe0::ProcessObj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor2))->GetBaseTexture()))->vfn_43c(1);
    reinterpret_cast<::Pawn *>((actor2))->TryAttack(0x72);
    m_10 = 1;
    if (idx && ::IsExplosionRadiusValid((::PathingRequest *)(idx)))
    {
        reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::fnv_009cafe0::GlobalObj * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(m_04), 2, 4, 1);
    }
}
}  // namespace fnv_009cafe0

struct IDebugText
{
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void __cdecl Write(int location, int justify, const char* format, ...);
};

struct CTSHelper
{
};

struct Modifier
{
};

struct FUN_009cb890_shell
{
    void WriteDebugText(IDebugText* debugText, int location, int justify);
    char pad00[0x30];
    unsigned char unk30;
    char pad31[0x4];
};

// Writes debug lines for the state, targeted point, high-arc flag and blocked-timer values via debugText->Write.
// @fnv 0x009cb890
void FUN_009cb890_shell::WriteDebugText(IDebugText* debugText, int location, int justify)
{
    switch (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x10))
    {
    case 0:
        debugText->Write(location, justify, "IDLE");
        break;
    case 1:
        debugText->Write(location, justify, "ATTACKING");
        break;
    }

    debugText->Write(location, justify, "Targeted Point: %.02f, %.02f, %.02f",
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x24),
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x28),
                     *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(this) + 0x2c));

    if (this->unk30)
    {
        debugText->Write(location, justify, "HIGH ARC");
    }

    if (reinterpret_cast<::FUN_0097fa50_Class *>((reinterpret_cast<Modifier*>(reinterpret_cast<unsigned char*>(this) + 0x34)))->FUN_0097fa50())
    {
        debugText->Write(location, justify, "Explosive Projectile Blocked Timer: %.02f/%.02f",
                         reinterpret_cast<::FUN_00435e00_t *>((reinterpret_cast<CTSHelper*>(reinterpret_cast<unsigned char*>(this) + 0x34)))->FUN_00435e00(),
                         reinterpret_cast<::TimeoutTimer *>((reinterpret_cast<Modifier*>(reinterpret_cast<unsigned char*>(this) + 0x34)))->FUN_006b9130());
    }
}
