// fallout/ai/combat/combatprocedureattackmelee.cpp: CombatProcedureAttackMelee, This, MeleeProc, CombatAttackHelper and more (57 functions)

#include <cmath>
#include <cstring>
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/AnimSequenceStub.h"
#include "fnv/decl/AnimationInterface.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/B_008b3630.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/CombatDialogueHandler.h"
#include "fnv/decl/CombatProcedureEx.h"
#include "fnv/decl/CombatProcedure_008b3a50.h"
#include "fnv/decl/DoorAccessData.h"
#include "fnv/decl/DummyOuter.h"
#include "fnv/decl/FUN_004301b0_shell.h"
#include "fnv/decl/FUN_00435de0_ctor.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004565f0_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_004938e0_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004e45e0_shell.h"
#include "fnv/decl/FUN_004e4600_shell.h"
#include "fnv/decl/FUN_004e4620_shell.h"
#include "fnv/decl/FUN_00505b80_cls.h"
#include "fnv/decl/FUN_00505c00_shell.h"
#include "fnv/decl/FUN_00505c20_class.h"
#include "fnv/decl/FUN_00508070_class.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_00644640_shell.h"
#include "fnv/decl/FUN_00644660_holder.h"
#include "fnv/decl/FUN_00644790_class.h"
#include "fnv/decl/FUN_006447b0_shell.h"
#include "fnv/decl/FUN_006a9560_Class.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/decl/FUN_0070f490_Class.h"
#include "fnv/decl/FUN_00798420_shell.h"
#include "fnv/decl/FUN_00812870_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00885d70_Class.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_00894d60_shell.h"
#include "fnv/decl/FUN_00897b50_shell.h"
#include "fnv/decl/FUN_008a16d0_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_008b3960_Class.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b3bf0_shell.h"
#include "fnv/decl/FUN_008b3c70Class.h"
#include "fnv/decl/FUN_00905450_StandIn.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_0097fa50_Class.h"
#include "fnv/decl/FUN_0097fc70_shell.h"
#include "fnv/decl/FUN_009818e0_shell.h"
#include "fnv/decl/FUN_00981970_shell.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_009a5480_class.h"
#include "fnv/decl/FUN_009a5eb0_shell.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/FUN_009cc490_shell.h"
#include "fnv/decl/FUN_009cdac0_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_009e8670.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/PathingLocation.h"
#include "fnv/decl/PathingLocationCheck.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/Pawn.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESAnimGroup.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/Target97ff.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00884dc0__FUN_00884dc0_shell.h"
#include "fnv/decl/fnv_00897910__AnimOwner.h"
#include "fnv/decl/fnv_008b3880__FUN_008b3880_target.h"
#include "fnv/decl/fnv_008b3bd0__FUN_008b3bd0_shell.h"
#include "fnv/decl/fnv_008be280__FloatValueProvider.h"
#include "fnv/decl/fnv_00981900__CombatController.h"
#include "fnv/decl/fnv_009928c0__CombatFlagHolder.h"
#include "fnv/decl/fnv_00996e20__FUN_00996e20_shell.h"
#include "fnv/decl/fnv_00996ea0__MyProc.h"
#include "fnv/decl/fnv_009a0ec0__FUN_009a0ec0_shell.h"
#include "fnv/decl/fnv_009a5f90__FUN_009a5f90_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005b6000.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00906000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00966000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_0097f000.h"
#include "fnv/symbols_009a7000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_0104f000.h"
#include "fnv/symbols_01090000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f4000.h"
#include "combatprocedureattackmelee_timer.h"

// @fnv 0x008d7f80
bool TimeoutTimer::CheckTimer()
{
    return ::FUN_00435dd0() - m_fStartTime > m_fTimeout;
}


// @fnv 0x0097f2d0
char FUN_0097f2d0(char* this_)
{
    return GetByteAtOffset70(*(char**)(this_ + 0x9c));
}

struct FUN_009cef70_shell
{
    float FUN_009cef70(int index);
};

// @fnv 0x009cef70
float FUN_009cef70_shell::FUN_009cef70(int index)
{
    return ((float*)this)[index + 0x3f];
}

struct FUN_009cef90_shell
{
    float FUN_009cef90(int index);
};

// @fnv 0x009cef90
float FUN_009cef90_shell::FUN_009cef90(int index)
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x110 + index * 4);
}

struct FUN_009cf400_shell
{
    unsigned char GetByteAtOffsetAD();
};

// @fnv 0x009cf400
unsigned char FUN_009cf400_shell::GetByteAtOffsetAD()
{
    return ((unsigned char*)this)[0xad];
}

struct FUN_009cf6d0_shell
{
    void FUN_009cf6d0(int arg);
};

// Stores the previous value at offset 0x14 into offset 0x18, then writes arg into offset 0x14.
// @fnv 0x009cf6d0
void FUN_009cf6d0_shell::FUN_009cf6d0(int arg)
{
    *(int*)((char*)this + 0x18) = *(int*)((char*)this + 0x14);
    *(int*)((char*)this + 0x14) = arg;
}

struct FUN_009cfc40_shell
{
    void FUN_009cfc40(int);
};

// @fnv 0x009cfc40
void FUN_009cfc40_shell::FUN_009cfc40(int)
{
    ((unsigned char*)this)[0] = 1;
}

struct Setting_S
{
};
struct Obj
{
};
// @fnv 0x00644580
float FUN_00644580(Obj* p, int percent, int unused, bool abApplySetting, bool abUseAltValue)
{
    float fPercentScale;
    float fResult;
    fPercentScale = percent / g_d100;
    fResult = ((char)(reinterpret_cast<::FUN_00644640_shell *>((p))->FUN_00644640())) + ((double)(reinterpret_cast<::FUN_00644660_holder *>((p))->GetE0())) + reinterpret_cast<::FUN_00885d70_Class *>((p))->GetFieldDC() * fPercentScale;
    fResult = fResult * (abUseAltValue ? reinterpret_cast<::FUN_009a5480_class *>((p))->GetFieldE4Float() : reinterpret_cast<::FUN_004e45e0_shell *>((p))->GetFieldE8Float());
    return abApplySetting ? fResult
                          : fResult * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting592)))))) * (abUseAltValue ? 1.0f : 0.25f);
}

struct FUN_009cc220
{
    virtual ~FUN_009cc220();
};
struct FUN_009cc1f0_shell
{
    void* DestroySelf(unsigned int flags);
};
// @fnv 0x009cc1f0
void* FUN_009cc1f0_shell::DestroySelf(unsigned int flags)
{
    ((FUN_009cc220*)this)->FUN_009cc220::~FUN_009cc220();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_009cc220 {
struct FUN_009ca6c0_shell
{
    virtual ~FUN_009ca6c0_shell();
};
struct FUN_009cc220 : FUN_009ca6c0_shell
{
    virtual ~FUN_009cc220();
};
// @fnv 0x009cc220
FUN_009cc220::~FUN_009cc220()
{}
}  // namespace fnv_009cc220

struct FUN_008b3ab0_shell
{
    void FUN_008b3ab0();
};
struct FUN_00894cc0_shell
{
    bool FUN_00894cc0(bool);
};
struct CombatProcedure
{
};
struct FUN_009cc4d0_shell : CombatProcedure
{
    void RunCombatProcedure();
};
struct AnimIdle
{
};
struct FUN_008935f0_shell
{
};
struct FUN_009cce70_shell : AnimIdle
{
    void FUN_009cce70(int attack, int arg2);
};
namespace fnv_009cd3d0 {
struct AnimIdle
{
};
struct FUN_009cd3d0_shell : AnimIdle
{
    void FUN_009cd3d0();
};
// If GetSection() returns 2 and the timer at offset 0x20 has elapsed, calls FUN_009cf6d0 with 3.
// @fnv 0x009cd3d0
void FUN_009cd3d0_shell::FUN_009cd3d0()
{
    if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) != 2)
        return;
    if (((TimeoutTimer*)((char*)this + 0x20))->CheckTimer())
        ((FUN_009cf6d0_shell*)this)->FUN_009cf6d0(3);
}
}  // namespace fnv_009cd3d0

struct FUN_009cd410_shell
{
    void FUN_009cd410();
};
struct FUN_009cdde0_shell
{
    bool HasNoFlag(unsigned short mask);
};
// Returns true when the 16-bit flags at offset 8 do not contain any bit of mask.
// @fnv 0x009cdde0
bool FUN_009cdde0_shell::HasNoFlag(unsigned short mask)
{
    return !(*(unsigned short*)((char*)this + 8) & mask) != 0;
}

struct FUN_00894900_shell
{
    bool FUN_00894900();
};
class BGSLoadGameBuffer;
struct CombatTargetTimestamp
{
public:
    void LoadGame(::BGSLoadGameBuffer *);
};
struct FUN_009cde10_shell
{
    void EvaluateReaction();
    unsigned char FUN_009cf030(float, float, int);
    void FUN_009cde10();
};
struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float);
};
struct FUN_009ce190_shell
{
    void FUN_009ce190();
};
float __cdecl GetActorReach(Actor*, int);
struct FUN_009ce560_shell
{
    float FUN_009ce560();
};
struct FUN_009cefb0_shell
{
    char FUN_009cefb0();
};
// @fnv 0x009cefb0
char FUN_009cefb0_shell::FUN_009cefb0()
{
    return *((char*)this + 0xf9);
}

struct Date
{
    ~Date();
};
struct FUN_009cf660_shell
{
    void SetMode(int mode);
};
namespace fnv_009cfbd0 {
struct FUN_009cdde0_shell
{
};
struct FUN_009cfbd0_shell
{
    char FUN_009cfbd0(unsigned short mask);
};
// Forwards the mask to the HasNoFlag method of the object at offset 0x64 and returns its result.
// @fnv 0x009cfbd0
char FUN_009cfbd0_shell::FUN_009cfbd0(unsigned short mask)
{
    char result = 1;
    result = ((char)(reinterpret_cast<::FUN_009cdde0_shell *>((((FUN_009cdde0_shell*)((char*)this + 0x64))))->HasNoFlag(mask)));
    return result;
}
}  // namespace fnv_009cfbd0

struct FUN_008b3bd0_shell
{
};
struct FUN_009cfc00_shell
{
    void FUN_009cfc00();
};
namespace fnv_009cfc60 {
struct FUN_008b3a50_shell
{
};
struct FUN_008b3ab0_shell
{
};
struct FUN_009cfc60_shell
{
    Actor* FUN_00996de0();
    void StopIfSpeakerOutOfRange();
    void FUN_009cfc60();
};
// Gets an Actor via FUN_00996de0, calls FUN_008b3a50 and FUN_008b3ab0 on it, then calls StopIfSpeakerOutOfRange.
// @fnv 0x009cfc60
void FUN_009cfc60_shell::FUN_009cfc60()
{
    Actor* pattacker = FUN_00996de0();
    reinterpret_cast<::CombatProcedure_008b3a50 *>((((FUN_008b3a50_shell*)pattacker)))->FUN_008b3a50();
    reinterpret_cast<::FUN_008b3ab0_shell *>((((FUN_008b3ab0_shell*)pattacker)))->FUN_008b3ab0();
    StopIfSpeakerOutOfRange();
}
}  // namespace fnv_009cfc60

float __cdecl FUN_009a64d0(Actor*, Actor*, int);
struct FUN_009cfd20_shell
{
    float GetModifierValue();
};
struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
struct FUN_00906f60
{
    FUN_00906f60();
    char d[16];
};
struct FUN_009cff10_shell
{
    bool a;
    bool b;
    int c;
    short d;
    bool e;
    bool f;
    bool g;
    bool h;
    NiPoint3 v;
    FUN_00906f60 m;
    FUN_009cff10_shell* Reset();
};
// Resets all flags, clears c and d, sets v to _NiPoint3_ZERO, constructs m, and returns this.
// @fnv 0x009cff10
FUN_009cff10_shell* FUN_009cff10_shell::Reset()
{
    a = false;
    b = false;
    c = 0;
    d = 0;
    e = false;
    f = false;
    g = false;
    h = false;
    v = ::NiPoint3::ZERO;
    ::FUN_00906f60((float *)&(m));
    return this;
}

struct FUN_009d0530_shell
{
    void UpdateFlags(unsigned short mask, bool clear);
};
// Sets or clears the bits of mask in the 16-bit flags word at offset 8 of this object, depending on clear.
// @fnv 0x009d0530
void FUN_009d0530_shell::UpdateFlags(unsigned short mask, bool clear)
{
    clear ? ((unsigned short*)this)[4] &= ~mask : ((unsigned short*)this)[4] |= mask;
}

namespace fnv_009d0590 {
struct TESObjectREFR;
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct PathingLocation
{
    int a, b, c, d, e, f, g, h, i, j;
    PathingLocation(TESObjectREFR*);
    ~PathingLocation();
};
struct Pathing
{
    static bool __cdecl FindPathingLocation(PathingLocation&, const NiPoint3&, PathingLocation*, void*);
};
struct FUN_009d0590_shell
{
    bool FUN_009d0590(TESObjectREFR* ref, const NiPoint3* pt);
};
// @fnv 0x009d0590
bool FUN_009d0590_shell::FUN_009d0590(TESObjectREFR* ref, const NiPoint3* pt)
{
    PathingLocation loc(ref);
    return Pathing::FindPathingLocation(loc, *pt, 0, 0);
}
}  // namespace fnv_009d0590

namespace fnv_009d0610 {
struct TESAmmoInitCalls
{
};
struct Setting_S
{
};
struct FUN_008d7f40_shell
{
};
struct FUN_009d0610_shell
{
    bool active;
    unsigned int elapsed;
    unsigned int UpdateDirection(unsigned int, unsigned int);
    void FUN_009d0610(TESAmmoInitCalls* src);
};
// @fnv 0x009d0610
void FUN_009d0610_shell::FUN_009d0610(TESAmmoInitCalls* pAmmoInitCalls)
{
    if (((TimeoutTimer*)((char*)this + 0x1c))->CheckTimer() || elapsed > 0)
        elapsed = UpdateDirection(((unsigned int)(::GetFieldBC((::FUN_0097ae90_Class *)(pAmmoInitCalls)))), elapsed) + elapsed;
    if (elapsed >= 4)
    {
        active = false;
        elapsed = 0;
        reinterpret_cast<::FUN_008d7f40_shell *>((((FUN_008d7f40_shell*)((char*)this + 0x1c))))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009d0610::Setting_S *>(&::g_011cee60)))))));
    }
}
}  // namespace fnv_009d0610

namespace fnv_009d0690 {
struct BGSSaveFormBuffer
{
};
struct FUN_009a5eb0_shell
{
};
struct CombatTargetTimestamp
{
};
struct FUN_009d0690_shell
{
    void FUN_009d0690(BGSSaveFormBuffer* buf);
};
// @fnv 0x009d0690
void FUN_009d0690_shell::FUN_009d0690(BGSSaveFormBuffer* buf)
{
    reinterpret_cast<::FUN_00996ed0_shell *>(this)->SaveToBuffer((::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50((char*)this + 0x10, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50((char*)this + 0x14, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50((char*)this + 0x18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50((char*)this + 0x1c, 4, 0);
    reinterpret_cast<::FUN_009a5eb0_shell *>((((FUN_009a5eb0_shell*)((char*)this + 0x20))))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::FUN_009a5eb0_shell *>((((FUN_009a5eb0_shell*)((char*)this + 0x28))))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::FUN_009a5eb0_shell *>((((FUN_009a5eb0_shell*)((char*)this + 0x30))))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::FUN_009a5eb0_shell *>((((FUN_009a5eb0_shell*)((char*)this + 0x38))))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::FUN_009a5eb0_shell *>((((FUN_009a5eb0_shell*)((char*)this + 0x40))))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::FUN_009a5eb0_shell *>((((FUN_009a5eb0_shell*)((char*)this + 0x48))))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((CombatTargetTimestamp*)((char*)this + 0x60))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(buf));
    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50((char*)this + 0x50, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50((char*)this + 0x54, 4, 0);
}
}  // namespace fnv_009d0690

namespace fnv_009d0790 {
struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
};
struct FUN_009a5e_timer
{
};
struct CombatTargetTimestamp
{
};
struct FUN_009d0790_shell
{
    void FUN_009d0790(BGSLoadFormBuffer* buf);
};
// Loads the base form data, four 4-byte fields, six timers, a version-gated object, then a 1-byte and a 4-byte field from the buffer.
// @fnv 0x009d0790
void FUN_009d0790_shell::FUN_009d0790(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>(this)->FUN_00996ef0((::BGSLoadFormBuffer *)(apBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x10), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x14), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x18), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x1c), 4);
    reinterpret_cast<::TimeoutTimer *>((((FUN_009a5e_timer*)((char*)this + 0x20))))->LoadGame((::BGSLoadFormBuffer *)(apBuffer));
    reinterpret_cast<::TimeoutTimer *>((((FUN_009a5e_timer*)((char*)this + 0x28))))->LoadGame((::BGSLoadFormBuffer *)(apBuffer));
    reinterpret_cast<::TimeoutTimer *>((((FUN_009a5e_timer*)((char*)this + 0x30))))->LoadGame((::BGSLoadFormBuffer *)(apBuffer));
    reinterpret_cast<::TimeoutTimer *>((((FUN_009a5e_timer*)((char*)this + 0x38))))->LoadGame((::BGSLoadFormBuffer *)(apBuffer));
    reinterpret_cast<::TimeoutTimer *>((((FUN_009a5e_timer*)((char*)this + 0x40))))->LoadGame((::BGSLoadFormBuffer *)(apBuffer));
    reinterpret_cast<::TimeoutTimer *>((((FUN_009a5e_timer*)((char*)this + 0x48))))->LoadGame((::BGSLoadFormBuffer *)(apBuffer));
    if (apBuffer->GetVersion() >= 0x12)
        reinterpret_cast<::CombatTargetTimestamp *>((((CombatTargetTimestamp*)((char*)this + 0x60))))->LoadGame((::BGSLoadGameBuffer *)(apBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x50), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x54), 4);
}
}  // namespace fnv_009d0790

struct FUN_00996de0_Class
{
    unsigned int FUN_00996de0();
};
// Gets the attacker Actor, runs the base procedure, then calls two functions on the attacker with false.
// @fnv 0x009cc4d0
void FUN_009cc4d0_shell::RunCombatProcedure()
{
    Actor* pattacker = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
    ((FUN_008b3ab0_shell*)pattacker)->FUN_008b3ab0();
    ((FUN_00894cc0_shell*)pattacker)->FUN_00894cc0(false);
}
// @fnv 0x009cce70
void FUN_009cce70_shell::FUN_009cce70(int attack, int arg2)
{
    if (attack == 0xff || !((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())))
        return;
    Actor* pattacker = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    bool queued = reinterpret_cast<::Pawn *>((((FUN_008935f0_shell*)pattacker)))->TryAttack(attack);
    if (queued)
    {
        ((FUN_009cf6d0_shell*)this)->FUN_009cf6d0(0);
        ((int*)this)[7] = attack;
    }
}
// Returns the cached modifier value, recomputing it from the attacker and the value at offset 4 when it is below _gModifierZero.
// @fnv 0x009ce560
float FUN_009ce560_shell::FUN_009ce560()
{
    Actor* pattacker = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    if (((float*)this)[0x16] < ::_DAT_01012060)
        ((float*)this)[0x16] = GetActorReach(pattacker, FUN_007031c0(((int*)this)[1]));
    return ((float*)this)[0x16];
}
// Gets the attacker via FUN_00996de0 and, if FUN_008b3bd0 returns false, calls FUN_009cfc40(1) on the object at this+0x64.
// @fnv 0x009cfc00
void FUN_009cfc00_shell::FUN_009cfc00()
{
    Actor* pattacker = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    if (!((unsigned char)(reinterpret_cast<::fnv_008b3bd0::FUN_008b3bd0_shell *>((((FUN_008b3bd0_shell*)pattacker)))->FUN_008b3bd0())))
        ((FUN_009cfc40_shell*)((char*)this + 0x64))->FUN_009cfc40(1);
}
struct FUN_00980070_shell
{
    unsigned int FUN_00980070();
};
struct FUN_005524b0_class
{
    char GetByteAtOffset8C();
};

struct FUN_009cefd0_shell
{
    int m_00;
    FUN_00980070_shell* m_04;
    char IsWithinThreshold(float a, float b, float c);
};

// Calls FUN_00996de0 and FUN_00980070, checks whether GetByteAtOffset8C returns at least 100, and returns 1 when a is not greater than b.
// @fnv 0x009cefd0
char FUN_009cefd0_shell::IsWithinThreshold(float afValue, float afLimit, float afUnused)
{
    char bResult = 0;
    unsigned int pTarget3 = ((FUN_00996de0_Class*)this)->FUN_00996de0();
    bool bFlag = ((FUN_005524b0_class*)this->m_04->FUN_00980070())->GetByteAtOffset8C() >= 100;
    float fElapsed3 = 0.0f;
    if (afValue <= afLimit + fElapsed3)
    {
        bResult = 1;
    }
    return bResult;
}

struct AnimDataV
{
};
struct ActorV
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual AnimDataV* GetAnimData(int);
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual bool V218();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual bool V230();
};
struct TESObjectWEAP;
struct FUN_0051f5f0_shell
{
    unsigned int GetByteAt11D();
};
struct MobileObject
{
};
struct FatigueProxy
{
};
struct FUN_00996e00_shell
{
    void* FUN_00996e00();
};
// @fnv 0x009cfd20
float FUN_009cfd20_shell::GetModifierValue()
{
    if (((float*)this)[0x17] < ::_DAT_01012060)
        ((float*)this)[0x17] = FUN_009a64d0(((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0())), ((::Actor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00())), 0);
    return ((float*)this)[0x17];
}
struct S009cefd0
{
};
struct S009ce870
{
    int FUN_009ce870(float, float, bool, bool, int);
};
struct BSAudio
{
};
struct CombatProcedureAttackMelee
{
    int m_00;
    FUN_00980070_shell* m_04;
    int FUN_009ccb20(bool abMidAttack, float afDistance, float afReach, bool abTargetAttacking, bool abTargetPostAttack,
                     bool abTargetRecoiling, bool* abDoPowerAttack, bool* abSwitchAttack);
};

// Chooses a melee attack id from distance, reach, power-attack and animation state, setting the power-attack and switch-attack flags.
// @fnv 0x009ccb20
int CombatProcedureAttackMelee::FUN_009ccb20(bool abMidAttack, float afDistance, float afReach, bool abTargetAttacking,
                                             bool abTargetPostAttack, bool abTargetRecoiling, bool* abDoPowerAttack,
                                             bool* abSwitchAttack)
{
    TESObjectWEAP* pweapon;
    bool bwithinNormalReach;
    ActorV* ptarget;
    int iAttack;
    ActorV* pattacker;

    pattacker = (ActorV*)((FUN_00996de0_Class*)this)->FUN_00996de0();
    ptarget = (ActorV*)((FUN_00996e00_shell*)this)->FUN_00996e00();
    *abSwitchAttack = false;
    iAttack = 0xff;
    pweapon = (TESObjectWEAP*)FUN_007031c0((int)m_04);
    if (!ptarget)
        return iAttack;
    if (pattacker->V218() && reinterpret_cast<::FUN_005a2030_shell *>((void *)(((MobileObject*)pattacker)))->FUN_005a2030())
        *abDoPowerAttack = false;
    else
        *abDoPowerAttack = ::CheckChanceSuccess((::C644810Actor *)(m_04->FUN_00980070()), reinterpret_cast<::FUN_00893530_shell *>((((FatigueProxy*)pattacker)))->GetFatigueRatio(),
                                              abTargetRecoiling, ptarget->V230(), 0);
    if ((int)((void *)(reinterpret_cast<::MagicCaster_shell *>((((BSAudio*)this)))->FUN_0044edb0())) == 4)
    {
        afReach += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting597))))));
        if (DialogueRandom() % 100 < 2)
            afReach += g_d100;
    }
    bwithinNormalReach = ((bool)(reinterpret_cast<::FUN_009cefd0_shell *>((((S009cefd0*)this)))->IsWithinThreshold(afDistance, afReach, 0)));
    if (!abMidAttack)
    {
        if (*abDoPowerAttack)
            iAttack = ((S009ce870*)this)->FUN_009ce870(afDistance, afReach, abTargetAttacking, abTargetPostAttack, 0);
        if (iAttack == 0xff && bwithinNormalReach)
        {
            iAttack = pweapon ? ((FUN_0051f5f0_shell*)pweapon)->GetByteAt11D() : 0xff;
            if (iAttack == 0xff)
            {
                if (reinterpret_cast<::AnimationInterface *>((pattacker->GetAnimData(1)))->FUN_00495f50((*reinterpret_cast<int *>((void *)&::g_kTextKeyA)), 0, {}) == 'l')
                    iAttack = 0x1a;
                else
                    iAttack = 0x20;
            }
        }
    }
    else if (reinterpret_cast<::FUN_0070f490_Class *>((pattacker->GetAnimData(4)))->GetSlotValue({}) == 3)
    {
        if (*abDoPowerAttack)
            iAttack = ((S009ce870*)this)->FUN_009ce870(afDistance, afReach, abTargetAttacking, abTargetPostAttack, 0);
        if (iAttack == 0xff && bwithinNormalReach)
        {
            switch (reinterpret_cast<::AnimSequenceStub *>((((ActorV*)((FUN_00996de0_Class*)this)->FUN_00996de0())->GetAnimData(0)))->FUN_00495e40({}))
            {
            case 0x33:
                iAttack = 0x26;
                break;
            case 0x34:
                iAttack = 0x2c;
                break;
            case 0x35:
                iAttack = 0x32;
                break;
            case 0x36:
                iAttack = 0x38;
                break;
            case 0x37:
                iAttack = 0x3e;
                break;
            case 0x38:
                iAttack = 0x44;
                break;
            case 0x6c:
                iAttack = 0x1a;
                break;
            default:
                if (pweapon && ((FUN_0051f5f0_shell*)pweapon)->GetByteAt11D() != 0xff)
                    iAttack = ((FUN_0051f5f0_shell*)pweapon)->GetByteAt11D();
                else
                    iAttack = 0x20;
                break;
            }
            *abSwitchAttack = true;
        }
    }
    return iAttack;
}

struct TargetInterface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(int arg);
};

struct FUN_008b3a20_shell
{
    int unk000, unk004, unk008, unk00C;
    int unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C;
    int unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C;
    int unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC;
    int unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC;
    int unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C;
    int unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C;
    int unk130, unk134, unk138, unk13C;
    int unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C;
    int unk160, unk164, unk168, unk16C;
    int unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C;
    TargetInterface* unk190;

    void DispatchToTarget(int arg);
};

// Forwards the argument to the virtual v0c method of the object stored at unk190.
// @fnv 0x008b3a20
void FUN_008b3a20_shell::DispatchToTarget(int aiValue)
{
    unk190->v0c(aiValue);
}

struct CombatProcBase
{
    CombatProcBase();
    virtual ~CombatProcBase();
    int unk04;
    int unk08;
    int unk0C;
};

struct CombatPoint2
{
    CombatPoint2();
    float x;
    float y;
};

struct CombatValue
{
    CombatValue();
    CombatValue(float f);
    int value;
};

struct CombatMeleeData
{
    CombatMeleeData();
    int unk00;
};

extern const float fCombatMaxValue;

struct FUN_009cc0c0 : CombatProcBase
{
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CombatPoint2 pt20;
    CombatPoint2 pt28;
    CombatPoint2 pt30;
    CombatPoint2 pt38;
    CombatPoint2 pt40;
    CombatPoint2 pt48;
    bool unk50;
    int unk54;
    float unk58;
    float unk5C;
    CombatValue val60;
    CombatMeleeData data64;
    FUN_009cc0c0();
    virtual ~FUN_009cc0c0();
};

// Initializes the combat procedure object's fields to defaults, sets the value to negative fCombatMaxValue, and stores it in val60.
// @fnv 0x009cc0c0
FUN_009cc0c0::FUN_009cc0c0()
{
    unk04 = 0;
    unk1C = 0xff;
    unk10 = 0;
    unk14 = 3;
    unk18 = 3;
    unk54 = 0x100;
    unk50 = false;
    unk58 = -1.0f;
    unk5C = -1.0f;
    CombatValue initial(-fCombatMaxValue);
    val60 = initial;
}

struct AnimData;
struct SubA4
{
};
struct ActorA
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual AnimData* GetAnimData121();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    SubA4 m_a4;
};
struct ActorB
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
    virtual int V116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual bool V140();
    virtual bool V141();
};
struct Proc
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual bool V254();
};

struct AnimData
{
};
struct Mid2
{
};
struct Mid1
{
    virtual void vdummy();
    Mid2* GetHandle();
};
struct Mid3
{
};
struct Obj04
{
};
struct SettingObj
{
};
struct GlobalObj
{
};
struct Sub20
{
};
struct This
{
    int m_00;
    Obj04* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    Sub20 m_20;
    void FUN_009cc510();
};
// @fnv 0x009cc510
void This::FUN_009cc510()
{
    float n44;
    float n45;
    float m2;
    void* m33;
    int m36;
    float m48;
    bool v29;
    bool v30;
    float v51;
    bool t5;
    bool t19;
    int t43;
    ActorB* t45;
    bool t57;
    bool s5;
    float s12;
    bool s20;
    int s23;
    bool s33;
    bool s44;
    AnimData* s56;
    bool r14;
    ActorA* r23;
    bool r39;
    r23 = ((::ActorA *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    t45 = ((::ActorB *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) != 3 || t45 == 0)
        return;
    if (((bool)(reinterpret_cast<::FUN_00981970_shell *>((m_04))->FUN_00981970())))
        return;
    m_1c = 0xff;
    s12 = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
    v51 = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
    s56 = r23->GetAnimData121();
    t43 = reinterpret_cast<::FUN_008a7570_shell *>((r23))->FUN_008a7570();
    s23 = reinterpret_cast<::FUN_008a7570_shell *>((t45))->FUN_008a7570();
    t57 = ::TESAnimGroup::IsActionTypeValid(reinterpret_cast<::FUN_004301b0_shell *>((s56))->FUN_004301b0(4));
    t5 = reinterpret_cast<::FUN_0070f490_Class *>((s56))->GetSlotValue(4) == 3;
    r39 = t43 == 4;
    t19 = t43 == 8 || t43 == 10;
    s33 = reinterpret_cast<::FUN_00894900_shell *>((t45))->FUN_00894900();
    s20 = s23 == 4;
    s5 = s23 == 8 || s23 == 10;
    s44 = ((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((t45))->FUN_00493bb0()));
    r14 = reinterpret_cast<::FUN_00894d60_shell *>((t45))->FUN_00894d60();
    if (((bool)(reinterpret_cast<::FUN_009cefd0_shell *>(this)->IsWithinThreshold(s12, v51, 0))))
    {
        n44 = 0.0f;
        n44 = ::CalculateWeightedValue((::Obj641 *)((int)((void *)(reinterpret_cast<::FUN_00980070_shell *>((m_04))->FUN_00980070()))), reinterpret_cast<::FUN_0097fc70_shell *>((m_04))->FUN_0097fc70(), reinterpret_cast<::ActorValueOwner *>(&(r23->m_a4))->GetActorValueAsInteger((::ActorValue::Index)(11)), s33,
                                     FUN_007031c0((int)m_04) == 0, s5, t45->V140(), r14);
        if (reinterpret_cast<::FUN_00435e00_t *>(((*(::Mid1 *)(reinterpret_cast<::InterfaceManager *>((m_04))->FUN_00586150())).GetHandle()))->FUN_00435e00() > 5.0 && n44 != 0.0)
            n44 += 100.0;
        if (!s44 && t45 != (*reinterpret_cast<::ActorB * *>(&::_g_thePlayer)))
            n44 += 100.0;
        m2 = ::FUN_00644580((::Obj *)(void *)(((void *)(reinterpret_cast<::FUN_00980070_shell *>((m_04))->FUN_00980070()))), 50, 50, false, s33);
        v29 = t45->V141() || t45->V140() || ((bool)(reinterpret_cast<::FUN_00437bd0_stub *>((t45))->FUN_00437bd0())) || ::FUN_00579670((char *)(t45)) || reinterpret_cast<::FUN_00437bf0_shell *>((t45))->FUN_00437bf0();
        m33 = ((void *)(reinterpret_cast<::FUN_008a1710_shell *>((t45))->FUN_008a1710()));
        if (v29 || !reinterpret_cast<::FUN_008a16d0_shell *>((t45))->FUN_008a16d0() || (m33 != 0 && ::FUN_004c0c30((char *)(m33))))
            m2 = 0.0f;
        v30 = (t57 && n44 > 0.0f) ? true : ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((::ActorA *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))))->GetBaseTexture()))->V254();
        if (!v30 || !((bool)(::FUN_0097f2d0((char *)(m_04)))))
        {
            n44 = 0.0f;
            if (!((bool)(::FUN_0097f2d0((char *)(m_04)))))
                m2 = 0.0f;
        }
        if ((t57 && !t5) || ((int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) == 4 || t19)
            m2 = 0.0f;
        if (!reinterpret_cast<::FUN_00494710_shell *>((s56))->FUN_00494710(0xaa))
            m2 = 0.0f;
        n45 = FUN_00404010((float)(100.0 - (n44 + m2)), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingObj *>(&::originalRuntimeFloatSetting690)))))));
        if (t57 && !t5)
            n45 = 0.0f;
        if (m_18 == 2)
            n45 = 0.0f;
        m36 = (int)(n44 + m2 + n45);
        m48 = (float)(::DialogueRandom() % (unsigned int)(m36 > 0 ? m36 : 100));
        if (m48 < n44)
        {
            if (((bool)(reinterpret_cast<::fnv_00981900::CombatController *>((m_04))->GetModifierKey())))
            {
                reinterpret_cast<::FUN_00894cc0_shell *>((r23))->FUN_00894cc0(false);
                if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 1)
                    reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
            }
            bool found = false;
            bool bp2 = false;
            int res = reinterpret_cast<::CombatProcedureAttackMelee *>(this)->FUN_009ccb20(t57, s12, v51, s33, s20, s5, &found, &bp2);
            if (res != 0xff)
            {
                if (((::ActorB *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()))->V116() != 0)
                {
                    if (found)
                    {
                        reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::GlobalObj * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(m_04), 2, 1, 0);
                    }
                    else
                    {
                        reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::GlobalObj * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(m_04), 2, 0, 0);
                    }
                    reinterpret_cast<::FUN_009cce70_shell *>(this)->FUN_009cce70(res, bp2);
                }
            }
        }
        else if (m2 > 0.0f && (n44 + m2) > m48)
        {
            reinterpret_cast<::FUN_00894cc0_shell *>((r23))->FUN_00894cc0(true);
            reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(1);
        }
        else
        {
            if (m_18 != 2)
            {
                reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(2);
                float f60 = ::CombatDamageCalculator::GetDamageMultiplier(reinterpret_cast<::FUN_004565f0_shell *>((((Mid3*)((void *)(reinterpret_cast<::FUN_00980070_shell *>((m_04))->FUN_00980070())))))->GetFloat(),
                                         reinterpret_cast<::FUN_00812870_t *>((((Mid3*)((void *)(reinterpret_cast<::FUN_00980070_shell *>((m_04))->FUN_00980070())))))->GetUnka4());
                reinterpret_cast<::FUN_008d7f40_shell *>(&(m_20))->FUN_008d7f40(f60);
            }
        }
    }
}

namespace fnv_009cced0 {
struct FUN_009cced0_cls
{
    int m_00;
    int m_04;
    void FUN_009cced0();
};


// @fnv 0x009cced0
void FUN_009cced0_cls::FUN_009cced0()
{
    if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())))
    {
        return;
    }
    Actor* a = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    void* b = reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00();
    unsigned char r_2 = ((unsigned char)(::TESAnimGroup::IsActionTypeValid(reinterpret_cast<::FUN_004301b0_shell *>((((ActorV*)a)->GetAnimData(4)))->FUN_004301b0({}))));
    if (r_2)
    {
        if (reinterpret_cast<::FUN_0070f490_Class *>((((ActorV*)a)->GetAnimData(4)))->GetSlotValue({}) == 3)
        {
            reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
            reinterpret_cast<::This *>(this)->FUN_009cc510();
        }
        int pResult = FUN_007031c0(m_04);
        if (pResult != 0)
        {
            if (((unsigned char)(::FUN_005f25d0(reinterpret_cast<FUN_0051f5f0_shell*>(pResult)->GetByteAt11D()))))
            {
                reinterpret_cast<::Pawn *>((reinterpret_cast<FUN_008935f0_shell*>(a)))->TryAttack(
                    reinterpret_cast<FUN_0051f5f0_shell*>(pResult)->GetByteAt11D());
            }
        }
    }
    else
    {
        reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
    }
}
}  // namespace fnv_009cced0

struct AnimSequence
{
};
struct AnimDataM
{
};
struct TimerObj
{
};
struct ProcessM
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual TimerObj* GetTimer();
};
struct MeleeActor
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual AnimDataM* GetAnimDataM();
};
struct MeleeTarget
{
};
struct MeleeProc
{
    void FUN_009ccfb0();
};

struct AnimData9cd430
{
};

struct Actor9cd430
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual AnimData9cd430* GetAnimData(int);
};

struct Controller9cd430
{
};

struct FloatSetting9cd430
{
};

bool __cdecl IsTargetInCone(Actor9cd430*, void*, int);

struct CombatProc9cd430
{
    int m_00;
    Controller9cd430* m_04;

    void Do9cd5e0();
    void FUN_009cd430();
};

struct CombatAttackVT
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual int v07d();
};

struct CombatVec3
{
    float x;
    float y;
    float z;
};
void __cdecl FUN_009a68b0(CombatVec3* out, void* a, CombatAttackVT* b, int c, float f);

class CombatAttackHelper
{
  public:
    void FUN_009ce5b0(CombatVec3* out);
    void FUN_009cdf00();
};

struct AttackDirection
{
    int iDirection;
};
struct PowerAttackEntry
{
    int iAttackId;
};

extern double DAT_01090d68;
extern int DAT_011a5ac8[];

struct SettingX
{
};

struct WeapObj
{
};

struct AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int);
};

struct ActorX
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual WeapObj* GetLoadedForm();
    char pad04[0xa0];
    AVOwner avOwner;
};

struct AttackData
{
};

struct AttackInfo
{
    AttackInfo();
    char unk00[12];
};

struct CombatCtrl
{
    bool FUN_009800e0(int, AttackInfo*);
};

struct ProcX
{
    int m_00;
    CombatCtrl* m_04;
    float FUN_009cfe90();
};

// Chooses a melee attack id from five candidates based on distance, reach, weapon speed and actor state, then logs the selection.
// @fnv 0x009ce870
int S009ce870::FUN_009ce870(float afDistance, float afReach, bool, bool, int)
{
    bool bSelected9 = false;
    bool unk3a5 = false;
    int iResult = 0xff;
    int iAttack5 = 0xff;
    int count = 0;
    bool abAllowedA[5];
    ::FUN_00403d30(abAllowedA, 0, 5);
    ActorX* pActorF = ((::ActorX *)(reinterpret_cast<::FUN_00996de0_Class *>((((ProcX*)this)))->FUN_00996de0()));
    AttackData* pDataVal = ((::AttackData *)(reinterpret_cast<::FUN_00980070_shell *>((((ProcX*)this)->m_04))->FUN_00980070()));
    if (((bool)(reinterpret_cast<::FUN_00981970_shell *>((((ProcX*)this)->m_04))->FUN_00981970())))
        return 0xff;
    if (!((bool)(reinterpret_cast<::FUN_009cefb0_shell *>((((ProcX*)this)->m_04))->FUN_009cefb0())))
        reinterpret_cast<::Target97ff *>((((ProcX*)this)->m_04))->UpdateActorValues();
    bool bPower7 = reinterpret_cast<::MiddleHighProcess *>((((ProcX*)this)->m_04))->ResetAlertState() && !((bool)(reinterpret_cast<::FUN_009cefd0_shell *>((((ProcX*)this)))->IsWithinThreshold(afDistance, afReach, 0)));
    float fMultX = bPower7 ? reinterpret_cast<::FUN_006d2c20_Class *>((pDataVal))->GetFloatAtOffsetB0() : 1.0f;
    WeapObj* pWeap4 = pActorF->GetLoadedForm();
    float fSpeed7 = reinterpret_cast<::FUN_00508070_class *>((pWeap4))->FUN_00508070();
    if (fSpeed7 <= ::_DAT_01012060)
        fSpeed7 = 1.0f;
    float fRateB = ((ProcX*)this)->FUN_009cfe90();
    float fReach5 = afReach * fMultX;
    bool bAny6 =
        pActorF->avOwner.GetActorValue(0x1d) > ::_DAT_01012060 && pActorF->avOwner.GetActorValue(0x1e) > ::_DAT_01012060;
    int aiAttacks[5];
    for (int i = 0; i < 5; i++)
    {
        float fMin = reinterpret_cast<::FUN_009cef70_shell *>((((ProcX*)this)->m_04))->FUN_009cef70(i);
        if (fMin > ::g_01012070 && !bAny6)
            continue;
        float fScaledValue = FUN_00404010((float)(fMin * fMultX), fReach5);
        float fTime = reinterpret_cast<::FUN_009cef90_shell *>((((ProcX*)this)->m_04))->FUN_009cef90(i);
        if (fTime < ::_DAT_01012060)
            continue;
        int aiSoundId = i + 0x5c;
        if (reinterpret_cast<::fnv_009928c0::CombatFlagHolder *>((pDataVal))->HasCombatFlag(1) && !((bool)(reinterpret_cast<::FUN_00505b80_cls *>((pDataVal))->DispatchByType(aiSoundId))))
            continue;
        float fDistB = fTime * fRateB / fSpeed7 + afDistance;
        if (fDistB <= fScaledValue && (fMin <= fReach5 || fScaledValue * DAT_01090d68 < fDistB))
        {
            aiAttacks[count] = aiSoundId;
            count++;
            abAllowedA[i] = true;
        }
    }
    if (count == 0)
        return 0xff;
    for (int j = count; j < 5; j++)
        aiAttacks[j] = 0xff;
    if (count == 1)
    {
        iAttack5 = aiAttacks[0];
    }
    else if (count > 1 && bPower7 && !reinterpret_cast<::fnv_009928c0::CombatFlagHolder *>((pDataVal))->HasCombatFlag(1))
    {
        int r = ::GetRandomNumberInRange(0, count);
        iAttack5 = aiAttacks[r];
    }
    if (iAttack5 == 0xff)
    {
        if (!reinterpret_cast<::fnv_009928c0::CombatFlagHolder *>((pDataVal))->HasCombatFlag(1))
        {
            int k = 5;
            if (abAllowedA[2] && afDistance < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting593)))))))
            {
                k = 2;
            }
            else if (abAllowedA[1] && afDistance > afReach * DAT_01021798)
            {
                k = 1;
            }
            else
            {
                unsigned short usMove = ((unsigned short)(reinterpret_cast<::FUN_008846e0_shell *>((pActorF))->GetVtbl20Result()));
                if (abAllowedA[3] && (usMove & 4))
                {
                    k = 3;
                }
                else if (abAllowedA[4] && (usMove & 8))
                {
                    k = 4;
                }
                else if (abAllowedA[0])
                {
                    k = 0;
                }
            }
            if (k != 5)
                iAttack5 = DAT_011a5ac8[k];
        }
        if (iAttack5 == 0xff)
        {
            unsigned char aucWeightsA[5];
            for (unsigned int u = 0; u < 5; u++)
            {
                int aiSoundId = u + 0x5c;
                aucWeightsA[u] = ((bool)(reinterpret_cast<::FUN_00505b80_cls *>((pDataVal))->DispatchByType(aiSoundId)));
            }
            unsigned int uiTotal = 0;
            for (unsigned int u = 0; u < (unsigned int)count; u++)
                uiTotal += aucWeightsA[aiAttacks[u] - 0x5c];
            if (uiTotal > 0)
            {
                unsigned int uiAttackSelectionRoll = ::GetRandomNumberInRange(0, uiTotal);
                unsigned int uiAcc = 0;
                for (unsigned int u = 0; u < (unsigned int)count; u++)
                {
                    uiAcc += aucWeightsA[aiAttacks[u] - 0x5c];
                    if (uiAttackSelectionRoll <= uiAcc)
                    {
                        iAttack5 = aiAttacks[u];
                        break;
                    }
                }
            }
        }
    }
    AttackInfo info7;
    if (!((ProcX*)this)->m_04->FUN_009800e0(iAttack5, &info7))
        ::FUN_005b5e40();
    iResult = iAttack5;
    bSelected9 = true;
    if (((bool)(::FUN_005b6f70())) && bSelected9)
    {
        ::FUN_00703c00("%.20s selects %s power attack!", reinterpret_cast<::FUN_0055d520_shell *>((pActorF))->FUN_0055d520());
    }
    return iResult;
}

struct CombatNode
{
    signed char GetByteAtOffset8C();
};
struct CombatContext
{
};
struct MeleeProcedure
{
    int unk00;
    CombatContext* context;
    bool IsActionAvailable(unsigned);
};
// Returns true if the combat node's value exceeds DAT_01012060 and, when flag 1 is set, the per-action check for action 92-96 is positive.
// @fnv 0x009cf420
bool MeleeProcedure::IsActionAvailable(unsigned action)
{
    Actor* actor = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    bool result = false;
    if (((::CombatNode *)(reinterpret_cast<::FUN_00980070_shell *>((context))->FUN_00980070()))->GetByteAtOffset8C() > ::_DAT_01012060)
    {
        result = true;
        if (reinterpret_cast<::fnv_009928c0::CombatFlagHolder *>((((::CombatNode *)(reinterpret_cast<::FUN_00980070_shell *>((context))->FUN_00980070()))))->HasCombatFlag(1))
        {
            switch (action)
            {
            case 92:
                result = ((signed char)(reinterpret_cast<::DoorAccessData *>((((::CombatNode *)(reinterpret_cast<::FUN_00980070_shell *>((context))->FUN_00980070()))))->ReadState98())) > 0;
                break;
            case 93:
                result = ((signed char)(reinterpret_cast<::FUN_00505c00_shell *>((((::CombatNode *)(reinterpret_cast<::FUN_00980070_shell *>((context))->FUN_00980070()))))->FUN_00505c00())) > 0;
                break;
            case 94:
                result = ((signed char)(reinterpret_cast<::FUN_00505c20_class *>((((::CombatNode *)(reinterpret_cast<::FUN_00980070_shell *>((context))->FUN_00980070()))))->GetByteAtOffset9A())) > 0;
                break;
            case 95:
                result = ((signed char)(reinterpret_cast<::FUN_006a9560_Class *>((((::CombatNode *)(reinterpret_cast<::FUN_00980070_shell *>((context))->FUN_00980070()))))->GetByteAtOffset9B())) > 0;
                break;
            case 96:
                result = ((signed char)(reinterpret_cast<::FUN_009e8670 *>((((::CombatNode *)(reinterpret_cast<::FUN_00980070_shell *>((context))->FUN_00980070()))))->GetMethod())) > 0;
                break;
            }
        }
    }
    return result;
}

namespace CombatReaction {
struct Animation
{
};
struct Actor
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
    virtual Animation* GetAnimation();
};
struct Config
{
};
struct Owner
{
};
struct Timer
{
    int a, b;
};
struct Options
{
};
struct Setting
{
};
extern const char DAT_01090ca4[], DAT_01090c9c[], DAT_01090c60[];
int FUN_005f2440(unsigned short);
struct Procedure
{
    int unk00;
    Owner* owner;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Timer reactionTimer, durationTimer;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    bool special;
    char unk51, unk52, unk53;
    int unk54, unk58, unk5c, unk60;
    Options options;
    void EvaluateReaction();
};
// @fnv 0x009cd5e0
void Procedure::EvaluateReaction()
{
    Actor* actor2 = ((::CombatReaction::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Actor* target = ((::CombatReaction::Actor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    if (!target)
        return;
    bool targetState3 = reinterpret_cast<::FUN_008a7570_shell *>((target))->FUN_008a7570() == 2;
    bool targetCondition3 = ::FUN_009a96c0((::ActH2 *)(target));
    float chance =
        ::fnv_00644990::FUN_00644990(((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070())), (int)reinterpret_cast<::fnv_00884dc0::FUN_00884dc0_shell *>((actor2))->FUN_00884dc0(), reinterpret_cast<::FUN_00893530_shell *>((actor2))->GetFatigueRatio(), targetState3);
    if (chance < ::_DAT_01012060)
        chance = 0.0f;
    if (special)
        chance += ::DAT_0104f2f0;
    if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 2)
        chance += ::DAT_01020758;
    if (target != (*reinterpret_cast<::CombatReaction::Actor * *>(&::_g_thePlayer)) && !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((target))->FUN_00493bb0())))
        chance -= ::g_d100;
    if (reinterpret_cast<::FUN_005a2030_shell *>((actor2))->FUN_005a2030())
        chance = 0.0f;
    float roll = (float)(::DialogueRandom() % 100);
    if (roll <= chance)
    {
        bool actorState = reinterpret_cast<::FUN_008a7570_shell *>((actor2))->FUN_008a7570() == 2;
        float first2 = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
        float second7 = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
        unsigned short action = ::FUN_00644a70((::OCActor *)(::CombatReaction::Config *)(((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))), actorState, targetState3, first2, second7, special,
                                             targetCondition3, reinterpret_cast<::TESActorBaseData *>(&(options))->GetFatigue());
        if (action)
        {
            Animation* animation = ((::CombatReaction::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->GetAnimation();
            if (animation)
            {
                int state = 3;
                bool allowed = true;
                float duration3 = 0.0f;
                switch (action & 15)
                {
                case 4:
                    state = 5;
                    allowed = ((bool)(reinterpret_cast<::fnv_009cfbd0::FUN_009cfbd0_shell *>(this)->FUN_009cfbd0(4)));
                    duration3 =
                        ::CombatDamageCalculator::GetDamageMultiplier(reinterpret_cast<::TESGrass *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetLowestAllowedSlope(), reinterpret_cast<::FUN_009cdac0_shell *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetField60Float());
                    break;
                case 8:
                    state = 6;
                    allowed = ((bool)(reinterpret_cast<::fnv_009cfbd0::FUN_009cfbd0_shell *>(this)->FUN_009cfbd0(8)));
                    duration3 =
                        ::CombatDamageCalculator::GetDamageMultiplier(reinterpret_cast<::TESGrass *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetLowestAllowedSlope(), reinterpret_cast<::FUN_009cdac0_shell *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetField60Float());
                    break;
                case 2:
                    state = 4;
                    duration3 =
                        ::CombatDamageCalculator::GetDamageMultiplier(reinterpret_cast<::PathingRequest *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetActorRadius(), reinterpret_cast<::PathingRequest *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetSmoothingRandomness());
                    break;
                default:
                    duration3 = ::CombatDamageCalculator::GetDamageMultiplier(reinterpret_cast<::FUN_009cdae0_shell *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetFloatAt64(),
                                             ::GetFloatAtOffset68((const char *)(((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070())))));
                    break;
                }
                if (FUN_005f2440(reinterpret_cast<::fnv_00897910::AnimOwner *>((((::CombatReaction::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))))->FUN_00897910(state, (::fnv_00897910::Equipped *)(0), 0, (::fnv_00897910::AnimData *)(0))) == state)
                {
                    float current = reinterpret_cast<::FUN_00897b50_shell *>((actor2))->FUN_00897b50((::ANIM_GROUP_ENUM)(state));
                    duration3 = ((double)(::FUN_00404010(current, duration3)));
                    float amount_2 = 0.0f;
                    reinterpret_cast<::FUN_008b3a20_shell *>((actor2))->DispatchToTarget(targetState3 && amount_2 > *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatReaction::Setting *>(&::originalRuntimeFloatSetting345)))))) ? action | 512
                                                                                                     : action | 256);
                    reinterpret_cast<::FUN_008d7f40_shell *>(&(reactionTimer))->FUN_008d7f40(duration3);
                    reinterpret_cast<::FUN_008d7f40_shell *>(&(durationTimer))->FUN_008d7f40(current);
                    reinterpret_cast<::FUN_009cf660_shell *>(this)->SetMode(2);
                }
                else if (((bool)(::FUN_005b6f70())))
                    ::FUN_00703c00(DAT_01090c60, reinterpret_cast<::FUN_0055d520_shell *>((actor2))->FUN_0055d520());
            }
        }
    }
    else if (((int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) != 1)
    {
        float delay = ::CombatDamageCalculator::GetDamageMultiplier(reinterpret_cast<::PathingRequest *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetCenterRadius(), reinterpret_cast<::PathingRequest *>((((::CombatReaction::Config *)(reinterpret_cast<::FUN_00980070_shell *>((owner))->FUN_00980070()))))->GetTargetRadius());
        reinterpret_cast<::FUN_008d7f40_shell *>(&(reactionTimer))->FUN_008d7f40(delay);
        reinterpret_cast<::fnv_009cfc60::FUN_009cfc60_shell *>(this)->FUN_009cfc60();
        reinterpret_cast<::FUN_009cf660_shell *>(this)->SetMode(1);
    }
}
}

struct Process98
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v12a();
    virtual void v12b();
    virtual void v12c();
    virtual void v12d();
    virtual void v12e();
    virtual void v12f();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v13a();
    virtual void v13b();
    virtual void v13c();
    virtual void v13d();
    virtual void v13e();
    virtual void v13f();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v14a();
    virtual void v14b();
    virtual void v14c();
    virtual void v14d();
    virtual void v14e();
    virtual void v14f();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v15a();
    virtual void v15b();
    virtual void v15c();
    virtual void v15d();
    virtual void v15e();
    virtual void v15f();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v16a();
    virtual void v16b();
    virtual void v16c();
    virtual void v16d();
    virtual void v16e();
    virtual void v16f();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v17a();
    virtual void v17b();
    virtual void v17c();
    virtual void v17d();
    virtual void v17e();
    virtual void v17f();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual int State();
};
struct Actor98
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual bool Test(bool);
};
struct Context98
{
};
struct Procedure98
{
    int unk00;
    Context98* context;
    void UpdateState();
};
// @fnv 0x009cde10
void FUN_009cde10_shell::FUN_009cde10()
{
    FUN_00894900_shell* ptarget;
    if (((int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) != 1)
        return;
    ptarget = ((::FUN_00894900_shell *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    if (((TimeoutTimer*)((char*)this + 0x28))->CheckTimer())
    {
        reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
        return;
    }
    if (reinterpret_cast<::FUN_00435e00_t *>((((CombatTargetTimestamp*)((char*)this + 0x28))))->FUN_00435e00() > DAT_01011588)
    {
        float freach;
        float fdistance;
        fdistance = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
        freach = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
        if (FUN_009cf030(fdistance, freach, 0))
        {
            reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
            return;
        }
    }
    if ((ptarget && ptarget->FUN_00894900()) || *((unsigned char*)this + 0x50))
    {
        if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 2)
        {
            ((FUN_009cf6d0_shell*)this)->FUN_009cf6d0(3);
            reinterpret_cast<::Procedure98 *>(this)->UpdateState();
        }
        EvaluateReaction();
    }
}
// Gets the actor and dispatches on FUN_00825c00(); in case 3 it checks the process state, context and actor test before calling FUN_009cc510().
// @fnv 0x009cf570
void Procedure98::UpdateState()
{
    Actor98* actor = ((::Actor98 *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    switch (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())
    {
    case 0:
        reinterpret_cast<::fnv_009cced0::FUN_009cced0_cls *>(this)->FUN_009cced0();
        break;
    case 1:
        reinterpret_cast<::MeleeProc *>(this)->FUN_009ccfb0();
        break;
    case 2:
        reinterpret_cast<::fnv_009cd3d0::FUN_009cd3d0_shell *>(this)->FUN_009cd3d0();
        break;
    case 3: {
        int result = actor && ((::Process98 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) ? ((::Process98 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->State() : 0;
        if (!reinterpret_cast<::DummyOuter *>((context))->FUN_009818b0() && !result && (!actor || !actor->Test(false)))
            reinterpret_cast<::This *>(this)->FUN_009cc510();
        break;
    }
    }
}

struct MeleeDebugActor
{
};
struct MeleeDebugTimer
{
    float started;
    float target;
};
struct MeleeDebugFlags
{
    unsigned short flags;
    unsigned short unknown;
};
struct MeleeDebugOutput
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void SlotC();
    virtual void Slot10();
    virtual void Print(int, int, const char*, ...);
};
extern const char DAT_01090e78[], DAT_01090e6c[], DAT_01090e64[], DAT_01090e5c[], DAT_01090e4c[],
    DAT_01090e40[], DAT_01090e30[];
extern const char DAT_01090e20[], DAT_01090e10[], DAT_01090e04[], DAT_01090df8[],
    DAT_01090dec[], DAT_01090dc8[], DAT_01090db8[], DAT_01090d8c[], DAT_01090d70[], DAT_01017b68[], DAT_01017b64[];
extern const char* DAT_011a5aa4[];
extern const char* DAT_011a5ab8[];
struct MeleeDebugProcedure
{
    int unk00, unk04, unk08, unk0C;
    int moveState;
    int attackState;
    int unk18;
    int action;
    MeleeDebugTimer attackTimer;
    MeleeDebugTimer moveTimer;
    int unk30, unk34, unk38, unk3C, unk40, unk44;
    MeleeDebugTimer delayTimer;
    int unk50, unk54, unk58, unk5C, unk60;
    MeleeDebugFlags stateFlags;
    void PrintDebugInfo(MeleeDebugOutput*, int, int);
};
// Builds description strings from move, attack and delay timers and prints the procedure's move/attack state and flags via output->Print.
// @fnv 0x009cf700
void MeleeDebugProcedure::PrintDebugInfo(MeleeDebugOutput* output, int x, int y)
{
    MeleeDebugActor* actor = ((::MeleeDebugActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    short sMovementFlags = ((short)(reinterpret_cast<::FUN_008846e0_shell *>((actor))->GetVtbl20Result()));
    char description[100];
    description[0] = DAT_01011584[0];
    std::memset(description + 1, 0, 99);
    switch (moveState)
    {
    case 2:
        ::FUN_00406d00(description, 100, DAT_01090e4c,
                     sMovementFlags & 1   ? DAT_01090e78
                     : sMovementFlags & 2 ? DAT_01090e6c
                     : sMovementFlags & 4 ? DAT_01090e64
                     : sMovementFlags & 8 ? DAT_01090e5c
                                          : DAT_01011584,
                     reinterpret_cast<::FUN_00435e00_t *>(&(moveTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(moveTimer))->FUN_006b9130());
        break;
    case 1:
        ::FUN_00406d00(description, 100, DAT_01090e40, reinterpret_cast<::FUN_00435e00_t *>(&(moveTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(moveTimer))->FUN_006b9130());
        break;
    default:
        description[0] = 0;
        break;
    }
    output->Print(x, y, DAT_01090e30, DAT_011a5aa4[moveState], description);
    switch (attackState)
    {
    case 0:
        ::TaskQueueInterface::CopyStringToBuffer(description, 100,
                     action == 26   ? ::CombatReaction::DAT_01090cb8
                     : action == 32 ? ::CombatReaction::DAT_01090cb0
                     : action == 92 ? DAT_01090e20
                     : action == 93 ? DAT_01090e10
                     : action == 94 ? DAT_01090e04
                     : action == 95 ? DAT_01090df8
                     : action == 96 ? DAT_01090dec
                                    : DAT_01011584);
        break;
    case 2:
        ::FUN_00406d00(description, 100, DAT_01090e40, reinterpret_cast<::FUN_00435e00_t *>(&(attackTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(attackTimer))->FUN_006b9130());
        break;
    default:
        description[0] = 0;
        break;
    }
    if (reinterpret_cast<::FUN_0097fa50_Class *>(&(delayTimer))->FUN_0097fa50())
        output->Print(x, y, DAT_01090dc8, reinterpret_cast<::FUN_00435e00_t *>(&(delayTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(delayTimer))->FUN_006b9130());
    output->Print(x, y, DAT_01090db8, DAT_011a5ab8[attackState], description);
    if (reinterpret_cast<::TESActorBaseData *>(&(stateFlags))->GetFatigue() && !reinterpret_cast<::fnv_008b3bd0::FUN_008b3bd0_shell *>((actor))->FUN_008b3bd0())
        output->Print(x, y, DAT_01090d8c, reinterpret_cast<::FUN_009cdde0_shell *>(&(stateFlags))->HasNoFlag(4) ? DAT_01017b68 : DAT_01017b64,
                      reinterpret_cast<::FUN_009cdde0_shell *>(&(stateFlags))->HasNoFlag(8) ? DAT_01017b68 : DAT_01017b64,
                      reinterpret_cast<::FUN_009cdde0_shell *>(&(stateFlags))->HasNoFlag(1) ? DAT_01017b68 : DAT_01017b64,
                      reinterpret_cast<::FUN_009cdde0_shell *>(&(stateFlags))->HasNoFlag(2) ? DAT_01017b68 : DAT_01017b64);
    if (reinterpret_cast<::FUN_009373f0_shell *>(&(stateFlags))->FUN_009373f0())
        output->Print(x, y, DAT_01090d70);
}

class Point9CF
{
  public:
    float x, y, z;

    Point9CF operator-(const Point9CF& pt) const;
    float Length() const;
};

class Actor9CF
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual const Point9CF& GetPos();
};

class Position9CF
{
  public:
    const Point9CF& GetPos();
};

class Setting9CF
{
  public:
};



class Dialogue9CF
{
  public:
    void StopIfSpeakerOutOfRange();

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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    Position9CF m_kListener;
};

// @fnv 0x009cfc90
void Dialogue9CF::StopIfSpeakerOutOfRange()
{
    if (!((bool)(::FUN_00525420())))
    {
        Actor9CF* pkSpeaker = ((::Actor9CF *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
        Point9CF kDelta = m_kListener.GetPos() - pkSpeaker->GetPos();
        if (reinterpret_cast<::TESCombatStyle *>((void *)&(kDelta))->UpdateCombatStyle() >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9CF *>(&::originalRuntimeFloatSetting713)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting9CF *>(&::originalRuntimeFloatSetting713)))))))
            reinterpret_cast<::FUN_009cfc00_shell *>(this)->FUN_009cfc00();
    }
}

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3 operator+(const Pt3& o) const;
    Pt3 operator-(const Pt3& o) const;
    float Length() const;
};
struct CombatActor
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual Pt3* GetPos();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void GetCurrentTargetDistance(Pt3* out);
};
struct CombatProcStub
{
    bool IsTargetOutOfRange();
};
// @fnv 0x009cd410
void FUN_009cd410_shell::FUN_009cd410()
{
    reinterpret_cast<::FUN_009cf660_shell *>(this)->SetMode(0);
}
// @fnv 0x009cf660
void FUN_009cf660_shell::SetMode(int mode)
{
    if (((int*)this)[4] != mode)
    {
        if (mode == 0 && ((int*)this)[4] == 4 && ((unsigned char)(reinterpret_cast<::CombatProcStub *>(this)->IsTargetOutOfRange())))
            return;
        if (mode == 4 || ((int*)this)[4] == 4)
            reinterpret_cast<::TESForm *>((((Date*)((int*)this)[1])))->ClearData();
        reinterpret_cast<::FUN_009cfc00_shell *>(this)->FUN_009cfc00();
    }
    ((int*)this)[4] = mode;
}
// Checks the actor is alive, projects a point ahead of it along its heading, and returns whether the target is at least range*range away from that point.
// @fnv 0x009cfd70
bool CombatProcStub::IsTargetOutOfRange()
{
    Pt3 unusedPos8 = (*reinterpret_cast<::Pt3 *>((void *)&::NiPoint3::ZERO));
    Pt3 heading = (*reinterpret_cast<::Pt3 *>((void *)&::NiPoint3::ZERO));
    if (!((::CombatActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00())) || !reinterpret_cast<::FUN_004938e0_shell *>((((::CombatActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()))))->FUN_004938e0())
        return false;
    ((::CombatActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()))->GetCurrentTargetDistance(&heading);
    heading.z = 0.0f;
    Pt3 aheadX = *((::CombatActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()))->GetPos() + heading;
    float aRange = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
    Pt3 diff4 = *((::CombatActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->GetPos() - aheadX;
    float dist = reinterpret_cast<::TESCombatStyle *>((void *)&(diff4))->UpdateCombatStyle();
    return dist >= aRange * aRange;
}

struct FUN_00416870
{
    float x, y, z;
    FUN_00416870(float, float, float);
};
struct FUN_006815c0
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    FUN_006815c0();
    FUN_00416870 FUN_004b4500(const FUN_00416870&) const;
};
struct Control057
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual bool Check(int);
};
struct Actor057
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
    virtual FUN_00416870& Position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float Heading();
    float FUN_008be350();
};
struct State057
{
    bool active, initialized;
    int mode;
    short mask;
    bool left, right, forward, back;
    FUN_00416870 position;
    int UpdateDirection(Actor057* actor, unsigned direction);
};
// Initializes direction flags from controls, updates position, and for the given direction tests a rotated offset point, storing the result via UpdateFlags.
// @fnv 0x009cff90
int State057::UpdateDirection(Actor057* actor, unsigned direction)
{
    if (!initialized)
    {
        left = ((::Control057 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Check(5);
        right = ((::Control057 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Check(6);
        forward = ((::Control057 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Check(3);
        back = ((::Control057 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Check(4);
        initialized = true;
    }
    if (!active && reinterpret_cast<::fnv_008b3bd0::FUN_008b3bd0_shell *>((actor))->FUN_008b3bd0())
        return 4;
    else if (!active && direction == 0)
    {
        FUN_00416870 f = (*(struct struct ::FUN_00416870 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(position))->FUN_00439ef0((::NiPoint3 *)&(actor->Position()), *(const ::NiPoint3 *)nullptr)));
        if (reinterpret_cast<::NiPoint3 *>((void *)&(f))->ComputeMagnitude() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting713)))))))
            return 4;
    }
    position = actor->Position();
    FUN_006815c0 a;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(a))->FUN_004a0c90(actor->Heading());
    float b = reinterpret_cast<::fnv_008be280::FloatValueProvider *>((actor))->FUN_008be280();
    if (b == 0.0)
        b = 32.0f;
    float e = actor->FUN_008be350();
    if (e == 0.0)
        e = b;
    unsigned c;
    float d = b / e;
    if (d > 0.5 && d < 2.0)
    {
        b = FUN_00404010(b, e);
        e = b;
    }
    b = FUN_0040ebd0(b, 64.0f);
    e = FUN_0040ebd0(e, 64.0f);
    c = reinterpret_cast<::FUN_008846e0_shell *>((actor))->GetVtbl20Result();
    switch (direction)
    {
    case 0: {
        FUN_00416870 g(0.0f, -e, 0.0f);
        if (c & 2)
            g.y -= e;
        g = (*(struct struct ::FUN_00416870 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const struct ::FUN_00416870 &)(a.FUN_004b4500(g)))->ProjectileLaunched((::NiPoint3 *)&(position), {})));
        reinterpret_cast<::FUN_009d0530_shell *>(this)->UpdateFlags(2, back ? reinterpret_cast<::fnv_009d0590::FUN_009d0590_shell *>(this)->FUN_009d0590((::fnv_009d0590::TESObjectREFR *)(actor), (const ::fnv_009d0590::NiPoint3 *)&(g)) : false);
        break;
    }
    case 1: {
        FUN_00416870 h(0.0f, e, 0.0f);
        if (c & 1)
            h.y += e;
        h = (*(struct struct ::FUN_00416870 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const struct ::FUN_00416870 &)(a.FUN_004b4500(h)))->ProjectileLaunched((::NiPoint3 *)&(position), {})));
        reinterpret_cast<::FUN_009d0530_shell *>(this)->UpdateFlags(1, forward ? reinterpret_cast<::fnv_009d0590::FUN_009d0590_shell *>(this)->FUN_009d0590((::fnv_009d0590::TESObjectREFR *)(actor), (const ::fnv_009d0590::NiPoint3 *)&(h)) : false);
        break;
    }
    case 2: {
        FUN_00416870 i(-b, 0.0f, 0.0f);
        if (c & 4)
            i.x -= b;
        i = (*(struct struct ::FUN_00416870 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const struct ::FUN_00416870 &)(a.FUN_004b4500(i)))->ProjectileLaunched((::NiPoint3 *)&(position), {})));
        reinterpret_cast<::FUN_009d0530_shell *>(this)->UpdateFlags(4, left ? reinterpret_cast<::fnv_009d0590::FUN_009d0590_shell *>(this)->FUN_009d0590((::fnv_009d0590::TESObjectREFR *)(actor), (const ::fnv_009d0590::NiPoint3 *)&(i)) : false);
        break;
    }
    case 3: {
        FUN_00416870 j(b, 0.0f, 0.0f);
        if (c & 8)
            j.x += b;
        j = (*(struct struct ::FUN_00416870 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const struct ::FUN_00416870 &)(a.FUN_004b4500(j)))->ProjectileLaunched((::NiPoint3 *)&(position), {})));
        reinterpret_cast<::FUN_009d0530_shell *>(this)->UpdateFlags(8, right ? reinterpret_cast<::fnv_009d0590::FUN_009d0590_shell *>(this)->FUN_009d0590((::fnv_009d0590::TESObjectREFR *)(actor), (const ::fnv_009d0590::NiPoint3 *)&(j)) : false);
        break;
    }
    }
    return 1;
}

class GlobalObject_0045d260
{
  public:
};
extern GlobalObject_0045d260 g_011f24e4;
struct P12_9cc240
{
    float dst0, y, z;
};
struct Act9cc240
{
};
struct Tgt9cc240
{
};
struct Proc9cc240
{
};
struct Own9cc240
{
};
struct Sub64_9cc240
{
};
struct Sub48_9cc240
{
};
P12_9cc240* GetTargetLocationWithOffset(P12_9cc240* r, Tgt9cc240* t, int n);
struct CPAM9cc240
{
    int m0;
    Own9cc240* m4;
    int m8, mc;
    int m10;
    int m14;
    char pad18[0x30];
    Sub48_9cc240 m48;
    char pad49[0x13];
    float m5c;
    int m60;
    Sub64_9cc240 m64;
    void UpdateCombatState();
};
struct Seq150
{
};
struct Anim150
{
};
struct State150
{
};
struct Actor150
{
    virtual void p00();
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual Anim150* anim();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual bool V230();
    virtual bool check234();
    virtual void x00();
    virtual void x01();
    virtual void x02();
    virtual void x03();
    virtual void x04();
    virtual void x05();
    virtual void x06();
    virtual void x07();
    virtual void x08();
    virtual void x09();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void x20();
    virtual void x21();
    virtual void x22();
    virtual void x23();
    virtual void x24();
    virtual void x25();
    virtual void x26();
    virtual void x27();
    virtual void x28();
    virtual void x29();
    virtual void x30();
    virtual void x31();
    virtual void x32();
    virtual void x33();
    virtual void x34();
    virtual void x35();
    virtual void x36();
    virtual void x37();
    virtual void x38();
    virtual void x39();
    virtual void x40();
    virtual void x41();
    virtual void x42();
    virtual void x43();
    virtual void x44();
    virtual void x45();
    virtual void x46();
    virtual void x47();
    virtual void x48();
    virtual void x49();
    virtual void x50();
    virtual void x51();
    virtual void x52();
    virtual void x53();
    virtual void x54();
    virtual void x55();
    virtual void x56();
    virtual void x57();
    virtual void x58();
    virtual void x59();
    virtual void x60();
    virtual void x61();
    virtual void x62();
    virtual void x63();
    virtual void x64();
    virtual void x65();
    virtual void x66();
    virtual void x67();
    virtual void x68();
    virtual void x69();
    virtual void x70();
    virtual void x71();
    virtual void x72();
    virtual void x73();
    virtual void x74();
    virtual void x75();
    virtual void x76();
    virtual void x77();
    virtual void x78();
    virtual void x79();
    virtual void x80();
    virtual void x81();
    virtual void x82();
    virtual void x83();
    virtual void x84();
    virtual void x85();
    virtual void x86();
    virtual void x87();
    virtual void x88();
    virtual void x89();
    virtual void x90();
    virtual void x91();
    virtual void x92();
    virtual void x93();
    virtual void x94();
    virtual void x95();
    virtual void x96();
    virtual void x97();
    virtual void x98();
    virtual void x99();
    virtual void x100();
    virtual void x101();
    virtual void x102();
    virtual void x103();
    virtual void x104();
    virtual void x105();
    virtual void x106();
    virtual void x107();
    virtual void x108();
    virtual void x109();
    virtual void x110();
    virtual void x111();
    virtual void x112();
    virtual void x113();
    virtual void x114();
    virtual void x115();
    virtual void x116();
    virtual void x117();
    virtual void x118();
    virtual void x119();
    virtual void x120();
    virtual void x121();
    virtual void x122();
    virtual void x123();
    virtual State150* state();
};
struct C150
{
    int pad;
    State150* m04;
    void FUN_009cd150();
};
// In mode 1, checks the actor's readiness, timer value and attack state, and either sets state 3, finishes, or continues the melee procedure.
// @fnv 0x009ccfb0
void MeleeProc::FUN_009ccfb0()
{
    if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) != 1)
        return;
    MeleeActor* actor = ((::MeleeActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    MeleeTarget* target8 = ((::MeleeTarget *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    if (!reinterpret_cast<::FUN_00894d60_shell *>((actor))->FUN_00894d60())
        reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
    TimerObj* timer5 = ((::ProcessM *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetTimer();
    if (timer5)
    {
        bool bAttacking4 = false;
        if (((::MeleeActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->GetAnimDataM() && ((::AnimSequence *)(reinterpret_cast<::FUN_00491040_shell *>((((::MeleeActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->GetAnimDataM()))->FUN_00491040(2))) &&
            ((int)(reinterpret_cast<::LowProcess *>((((::AnimSequence *)(reinterpret_cast<::FUN_00491040_shell *>((((::MeleeActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->GetAnimDataM()))->FUN_00491040(2)))))->GetActiveCombatTarget())) != 1)
            bAttacking4 = true;
        float fTime = reinterpret_cast<::FUN_004bcdb0_shell *>((timer5))->FUN_004bcdb0(0);
        if (fTime <= ::_DAT_01012060 && !bAttacking4)
        {
            reinterpret_cast<::FUN_00894cc0_shell *>((actor))->FUN_00894cc0(false);
            reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
        }
        else
        {
            bool bTargetAttack2 = target8 ? reinterpret_cast<::FUN_008a7570_shell *>((target8))->FUN_008a7570() == 8 : 0;
            if (bTargetAttack2 && !bAttacking4)
            {
                reinterpret_cast<::FUN_00894cc0_shell *>((actor))->FUN_00894cc0(false);
                reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
                reinterpret_cast<::Procedure98 *>(this)->UpdateState();
            }
            else if (!bAttacking4)
            {
                reinterpret_cast<::C150 *>(this)->FUN_009cd150();
            }
        }
    }
}
// Chooses a combat action from range, controller state and target checks, calling Do9ce190, Do9cd150, Do9cdf00 or Do9cd5e0.
// @fnv 0x009cd430
void CombatProc9cd430::FUN_009cd430()
{
    if (((int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())))
        return;
    Actor9cd430* actor = ((::Actor9cd430 *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    void* target = reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00();
    float distance = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
    float reachDist = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
    float m_fGlyphExtent = 0.0f;
    float fImpulseRadiusSquared = 0.0f;
    bool inRange = ((bool)(reinterpret_cast<::FUN_009cefd0_shell *>(this)->IsWithinThreshold(distance, reachDist, 0)));
    if (inRange && !((bool)(::FUN_0097f2d0((char *)(m_04)))) && IsTargetInCone(actor, target, 0))
    {
        reinterpret_cast<::FUN_009ce190_shell *>(this)->FUN_009ce190();
        return;
    }
    if (((bool)(reinterpret_cast<::fnv_00981900::CombatController *>((m_04))->GetModifierKey())) || ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 1)
    {
        reinterpret_cast<::C150 *>(this)->FUN_009cd150();
        return;
    }
    bool bInReach = false;
    if (((bool)(reinterpret_cast<::FUN_009cde10_shell *>(this)->FUN_009cf030(distance, reachDist, 0))))
    {
        if (distance - reachDist > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting9cd430 *>(&::originalRuntimeFloatSetting593)))))) || reinterpret_cast<::CombatProcStub *>(this)->IsTargetOutOfRange())
        {
            reinterpret_cast<::FUN_009ce190_shell *>(this)->FUN_009ce190();
        }
        else
        {
            reinterpret_cast<::CombatAttackHelper *>(this)->FUN_009cdf00();
            return;
        }
    }
    else if (bInReach && distance < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting9cd430 *>(&::originalRuntimeFloatSetting593)))))))
    {
        bool ok = ::TESAnimGroup::IsValidAnimationGroup(reinterpret_cast<::FUN_004301b0_shell *>((actor->GetAnimData(4)))->FUN_004301b0({}));
        if (!ok)
            reinterpret_cast<::CombatAttackHelper *>(this)->FUN_009cdf00();
    }
    else
    {
        Do9cd5e0();
    }
}
// @fnv 0x009cd150
void C150::FUN_009cd150()
{
    if (((::Actor150 *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->anim() && ((::Seq150 *)(reinterpret_cast<::FUN_00491040_shell *>((((::Actor150 *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->anim()))->FUN_00491040(2))) &&
        ((int)(reinterpret_cast<::LowProcess *>((((::Seq150 *)(reinterpret_cast<::FUN_00491040_shell *>((((::Actor150 *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))->anim()))->FUN_00491040(2)))))->GetActiveCombatTarget())) != 1)
        return;
    Actor150* actor2 = ((::Actor150 *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Actor150* target7 = ((::Actor150 *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    if (((bool)(reinterpret_cast<::fnv_00981900::CombatController *>((m04))->GetModifierKey())) || ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 1)
    {
        if (!target7)
        {
            if (reinterpret_cast<::FUN_00894d60_shell *>((actor2))->FUN_00894d60())
                reinterpret_cast<::FUN_00894cc0_shell *>((actor2))->FUN_00894cc0(false);
            reinterpret_cast<::FUN_009818e0_shell *>((m04))->FUN_009818e0(0);
            if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 1)
                reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
            return;
        }
        bool active = reinterpret_cast<::FUN_00894900_shell *>((target7))->FUN_00894900();
        bool action = reinterpret_cast<::FUN_008a7570_shell *>((target7))->FUN_008a7570() == 4;
        bool state2 = false;
        if (target7->state())
            state2 = ((bool)(reinterpret_cast<::fnv_00981900::CombatController *>((target7->state()))->GetModifierKey()));
        float elapsedTmp = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
        float limit = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
        bool flag_ = false;
        bool blocked = target7->check234() || target7->V230() || ((unsigned char)(reinterpret_cast<::FUN_00437bd0_stub *>((target7))->FUN_00437bd0())) || ::FUN_00579670((char *)(target7)) ||
                       reinterpret_cast<::FUN_00437bf0_shell *>((target7))->FUN_00437bf0();
        if (!(!(elapsedTmp > limit) && !blocked && !action && !state2 &&
              (::DialogueRandom() % 100 >= 5 || (active && !flag_)) && reinterpret_cast<::FUN_00894d60_shell *>((actor2))->FUN_00894d60()))
        {
            if (reinterpret_cast<::FUN_00894d60_shell *>((actor2))->FUN_00894d60())
                reinterpret_cast<::FUN_00894cc0_shell *>((actor2))->FUN_00894cc0(false);
            reinterpret_cast<::FUN_009818e0_shell *>((m04))->FUN_009818e0(0);
            if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 1)
                reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
        }
    }
}

struct ActorHelper
{
    bool FUN_008b3840(void*);
};

struct NiPoint3_ext : public NiPoint3
{
    NiPoint3_ext();
    NiPoint3 operator-(const NiPoint3&) const;
    float Length() const;
};

struct CombatProcedure_shell : public FUN_009cde10_shell
{
    int unk00;
    void* m_04;

    void FUN_009ce5b0(CombatVec3*);
    void UpdateCombatMovement();
};
// @fnv 0x009cdf00
void CombatAttackHelper::FUN_009cdf00()
{
    void* a;
    CombatAttackVT* b;
    CombatVec3 out4;
    reinterpret_cast<::FUN_009cf660_shell *>(this)->SetMode(3);
    a = ((void *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    b = ((::CombatAttackVT *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(1);
    FUN_009a68b0(&out4, a, b, b->v07d(), reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560());
    FUN_009ce5b0(&out4);
    reinterpret_cast<::CombatProcedure_shell *>(this)->UpdateCombatMovement();
}

float __cdecl FUN_009a6770(ActorHelper*, Actor057*);

// @fnv 0x009cdf80
void CombatProcedure_shell::UpdateCombatMovement()
{
    ActorHelper* actor;
    unsigned short wVal;
    float f0c;
    Actor057* target8;
    CombatVec3 vec1c3;
    float fX;

    if (((int)(reinterpret_cast<::MagicCaster_shell *>((this))->FUN_0044edb0())) != 3)
    {
        return;
    }

    actor = ((::ActorHelper *)(reinterpret_cast<::FUN_00996de0_Class *>((this))->FUN_00996de0()));
    target8 = ((::Actor057 *)(reinterpret_cast<::FUN_00996e00_shell *>((this))->FUN_00996e00()));
    f0c = reinterpret_cast<::FUN_009cfd20_shell *>((this))->GetModifierValue();
    fX = reinterpret_cast<::FUN_009ce560_shell *>((this))->FUN_009ce560();
    wVal = ((unsigned short)(reinterpret_cast<::FUN_008846e0_shell *>((actor))->GetVtbl20Result()));

    if (!reinterpret_cast<::fnv_008b3bd0::FUN_008b3bd0_shell *>((actor))->FUN_008b3bd0())
    {
        reinterpret_cast<::FUN_009cd410_shell *>((this))->FUN_009cd410();
        return;
    }

    FUN_009a68b0(&vec1c3, actor, (CombatAttackVT*)target8, (int)&target8->Position(), reinterpret_cast<::FUN_009ce560_shell *>((this))->FUN_009ce560());

    if (f0c > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting9cd430 *>(&::originalRuntimeFloatSetting593)))))) * 2)
    {
        if (!((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((this))->FUN_00825c00())))
        {
            reinterpret_cast<::FUN_009ce190_shell *>((this))->FUN_009ce190();
        }
        return;
    }

    if (this->FUN_009cf030(f0c, fX, 0) && ((bool)(::FUN_0097f2d0((char *)(this->m_04)))))
    {
        unsigned char b_ = 0;
        NiPoint3_ext pt9;
        if (reinterpret_cast<::FUN_008b3bf0_shell *>((actor))->FUN_008b3bf0())
        {
            b_ = 1;
        }
        else if (actor->FUN_008b3840(&pt9))
        {
            float f38 = FUN_009a6770(actor, target8);
            float f5 = ((NiPoint3_ext&)(pt9 - (const NiPoint3&)target8->Position())).Length() - f38;
            b_ = ((unsigned char)(reinterpret_cast<::FUN_009cefd0_shell *>((this))->IsWithinThreshold(f5, fX, 0)));
        }
        if (!b_)
        {
            this->FUN_009ce5b0(&vec1c3);
        }
        return;
    }

    if (((unsigned char)(reinterpret_cast<::FUN_009cefd0_shell *>((this))->IsWithinThreshold(f0c, fX, 0))))
    {
        if ((wVal & 2) && f0c < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting9cd430 *>(&::originalRuntimeFloatSetting593)))))))
        {
            reinterpret_cast<::Procedure98 *>((this))->UpdateState();
        }
        else
        {
            reinterpret_cast<::FUN_009cd410_shell *>((this))->FUN_009cd410();
        }
    }
}

struct ZPoint
{
    float unk00, unk04, unk08;
};
struct B006815c0
{
    float unk00, unk04, unk08;
    B006815c0();
};
struct ZAnim
{
};
struct ZProcess
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual bool Check();
};
struct ZActor
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
    virtual ZAnim* Anim(int, int, int);
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const ZPoint& Pos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual bool Check();
    bool FUN_008b3840(B006815c0*);
};
void __cdecl FUN_009a68b0(ZPoint*, ZActor*, ZActor*, const ZPoint&, float);
float __cdecl FUN_009a6770(ZActor*, ZActor*);
bool __cdecl IsTargetInCone(ZActor*, ZActor*, int);
struct ZSetting
{
};
struct ZMelee
{
    int unk00;
    char* unk04;
    int unk08, unk0C, unk10, unk14;
    void FUN_009ce5b0(ZPoint*);
    void UpdateMeleeCombat();
};
struct AnimData_9cf
{
};

struct ActorProcess_9cf
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual void va5();
    virtual void va6();
    virtual void va7();
    virtual void va8();
    virtual void va9();
    virtual void vaa();
    virtual void vab();
    virtual void vac();
    virtual void vad();
    virtual void vae();
    virtual void vaf();
    virtual void vb0();
    virtual void vb1();
    virtual void vb2();
    virtual void vb3();
    virtual void vb4();
    virtual void vb5();
    virtual void vb6();
    virtual void vb7();
    virtual void vb8();
    virtual void vb9();
    virtual void vba();
    virtual void vbb();
    virtual void vbc();
    virtual void vbd();
    virtual void vbe();
    virtual void vbf();
    virtual void vc0();
    virtual void vc1();
    virtual void vc2();
    virtual void vc3();
    virtual void vc4();
    virtual void vc5();
    virtual void vc6();
    virtual void vc7();
    virtual void vc8();
    virtual void vc9();
    virtual void vca();
    virtual void vcb();
    virtual void vcc();
    virtual void vcd();
    virtual void vce();
    virtual void vcf();
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vda();
    virtual void vdb();
    virtual void vdc();
    virtual void vdd();
    virtual void vde();
    virtual void vdf();
    virtual void ve0();
    virtual void ve1();
    virtual void ve2();
    virtual void ve3();
    virtual void ve4();
    virtual void ve5();
    virtual void ve6();
    virtual void ve7();
    virtual void ve8();
    virtual void ve9();
    virtual void vea();
    virtual void veb();
    virtual void vec();
    virtual void ved();
    virtual void vee();
    virtual void vef();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vfa();
    virtual void vfb();
    virtual void vfc();
    virtual void vfd();
    virtual bool V254();
};

struct Obj_9cf
{
};

struct Context_9cf
{
};

struct Actor_9cf
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual AnimData_9cf* v1e4();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void* v1f4();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual bool v218();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual void v8b();
    virtual bool v230();

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
    SubA4 m_a4;

};

struct CTSHelper
{
    int m_val;
};

bool __cdecl IsTargetInCone(Actor_9cf*, Actor_9cf*, int);

struct FUN_009cf090_Class
{
    int unk00;
    Context_9cf* m_04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c;
    CTSHelper m_timer60;


    void TryAttackTarget(float a1, float a2);
};
// Calls SetMode(4), FUN_00996e20(3), FUN_008d7f40(3.0f) on the object at offset 0x28, then UpdateMeleeCombat.
// @fnv 0x009ce190
void FUN_009ce190_shell::FUN_009ce190()
{
    reinterpret_cast<::FUN_009cf660_shell *>(this)->SetMode(4);
    reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(3);
    ((FUN_008d7f40_shell*)((char*)this + 0x28))->FUN_008d7f40(3.0f);
    reinterpret_cast<::ZMelee *>(this)->UpdateMeleeCombat();
}
// @fnv 0x009ce1d0
void ZMelee::UpdateMeleeCombat()
{
    if (((int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) != 4)
        return;
    ZActor* actor2 = ((::ZActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    ZActor* target2 = ((::ZActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    float distance3 = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
    float kReach = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
    bool mid4 = reinterpret_cast<::CombatProcStub *>(this)->IsTargetOutOfRange();
    ZProcess* process2 = ((::ZProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor2))->GetBaseTexture()));
    if ((((bool)(reinterpret_cast<::FUN_009cde10_shell *>(this)->FUN_009cf030(distance3, kReach, 0))) && ((bool)(::FUN_0097f2d0((char *)(void *)((void*)unk04))))) || !((bool)(::FUN_0097f2d0((char *)(void *)((void*)unk04)))))
    {
        ZPoint point2;
        FUN_009a68b0(&point2, actor2, target2, target2->Pos(), reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560());
        bool ready3 = false;
        B006815c0 kPos;
        if (reinterpret_cast<::FUN_008b3bf0_shell *>((actor2))->FUN_008b3bf0())
            ready3 = true;
        else if (!((bool)(reinterpret_cast<::FUN_008b3c70Class *>((actor2))->FUN_008b3c70())) && actor2->FUN_008b3840(&kPos))
        {
            float _radius = FUN_009a6770(actor2, target2);
            float delta = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::ZPoint &)((*(::ZPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kPos))->FUN_00439ef0((::NiPoint3 *)&(target2->Pos()), *(const ::NiPoint3 *)nullptr)))))->FUN_00589850() - _radius;
            ready3 = ((bool)(reinterpret_cast<::FUN_009cefd0_shell *>(this)->IsWithinThreshold(delta, kReach, 0)));
        }
        if (!ready3)
            FUN_009ce5b0(&point2);
    }
    if (((bool)(reinterpret_cast<::TeleportableReference *>((actor2))->GetTeleportDestinationForm())))
    {
        if (!mid4)
            reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
    }
    else if (reinterpret_cast<::FUN_00894d60_shell *>((actor2))->FUN_00894d60())
        reinterpret_cast<::FUN_00894cc0_shell *>((actor2))->FUN_00894cc0(false);
    else if (((bool)(reinterpret_cast<::FUN_009cefd0_shell *>(this)->IsWithinThreshold(distance3, kReach, 0))) && ((bool)(::FUN_0097f2d0((char *)(void *)((void*)unk04)))))
    {
        if (mid4 && distance3 < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting9cd430 *>(&::originalRuntimeFloatSetting593)))))) * 2.0f)
            reinterpret_cast<::CombatAttackHelper *>(this)->FUN_009cdf00();
        else
            reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
    }
    else if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) && ((bool)(reinterpret_cast<::FUN_009cefd0_shell *>(this)->IsWithinThreshold(distance3, kReach * 2.0f, 0))) && ((bool)(::FUN_0097f2d0((char *)(void *)((void*)unk04)))) &&
             actor2->Check() && process2 && process2->Check())
    {
        if (IsTargetInCone(actor2, target2, 0))
        {
            int topicB = FUN_007031c0((int)unk04);
            if (DialogueRandom() % 100 < (int)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ZSetting *>(&::g_011cf27c)))))) * ::g_d100))
            {
                int attackVal = 255;
                if (reinterpret_cast<::AnimationInterface *>((actor2->Anim(1, (*reinterpret_cast<int *>((void *)&::g_kTextKeyA)), 0)))->FUN_00495f50({}, {}, {}) == 108)
                    attackVal = 26;
                else
                    attackVal = 32;
                reinterpret_cast<::FUN_009cce70_shell *>(this)->FUN_009cce70(attackVal, 0);
            }
        }
    }
    else if (unk14)
        reinterpret_cast<::FUN_009cf090_Class *>(this)->TryAttackTarget(distance3, kReach);
}

// @fnv 0x009cf090
void FUN_009cf090_Class::TryAttackTarget(float afArg1, float afArg2)
{
    Actor_9cf* pkActorVal;
    bool bTargetRecoiling;
    {
        int iAttack4;
        bool bTargetAttacking4;
        int iAnimAction4;
        bool bTargetMidAttack3;
        bool bTargetPostAttack_2;
        bool bInAttackAnim5;
        Actor_9cf* pkTarget5;
        int iRandA;
        float fPercent4;
        float aFMax;
        float fChanceTmp;
        CTSHelper helper_;

        if (((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((this))->FUN_00825c00())) != 3)
        {
            return;
        }

        pkActorVal = ((::Actor_9cf *)(reinterpret_cast<::FUN_00996de0_Class *>((this))->FUN_00996de0()));
        pkTarget5 = ((::Actor_9cf *)(reinterpret_cast<::FUN_00996e00_shell *>((this))->FUN_00996e00()));
        if (!pkTarget5)
        {
            return;
        }

        if (reinterpret_cast<::FUN_00435e00_t *>(&(this->m_timer60))->FUN_00435e00() < 1.0)
        {
            return;
        }

        if (!reinterpret_cast<::MiddleHighProcess *>((this->m_04))->ResetAlertState())
        {
            return;
        }

        if (!((::ActorProcess_9cf *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActorVal))->GetBaseTexture()))->V254())
        {
            return;
        }

        bInAttackAnim5 = (pkActorVal->v1e4() != 0) ? ::TESAnimGroup::IsValidAnimationGroup(reinterpret_cast<::FUN_004301b0_shell *>((pkActorVal->v1e4()))->FUN_004301b0(4)) : false;
        if (bInAttackAnim5)
        {
            return;
        }

        if (pkActorVal->v218() && reinterpret_cast<::FUN_005a2030_shell *>((pkActorVal))->FUN_005a2030())
        {
            return;
        }

        if (!((bool)(::FUN_0097f2d0((char *)(this->m_04)))))
        {
            return;
        }

        if (!IsTargetInCone(pkActorVal, pkTarget5, 0))
        {
            return;
        }

        iAnimAction4 = reinterpret_cast<::FUN_008a7570_shell *>((pkTarget5))->FUN_008a7570();
        bTargetAttacking4 = reinterpret_cast<::FUN_00894900_shell *>((pkTarget5))->FUN_00894900();
        bTargetMidAttack3 = (iAnimAction4 == 4);
        bTargetPostAttack_2 = (iAnimAction4 == 8 || iAnimAction4 == 10);
        bTargetRecoiling = reinterpret_cast<::FUN_00894d60_shell *>((pkTarget5))->FUN_00894d60();

        iAttack4 = reinterpret_cast<::S009ce870 *>((this))->FUN_009ce870(afArg1, afArg2, bTargetAttacking4, bTargetMidAttack3, 1);
        if (iAttack4 != 0xff)
        {
            if (reinterpret_cast<::MeleeProcedure *>((this))->IsActionAvailable(iAttack4))
            {
                iRandA = DialogueRandom() % 100;
                if (iRandA < ((char)(reinterpret_cast<::FUN_009cf400_shell *>((((::Obj_9cf *)(reinterpret_cast<::FUN_00980070_shell *>((this->m_04))->FUN_00980070()))))->GetByteAtOffsetAD())))
                {
                    fChanceTmp = ::CalculateWeightedValue((::Obj641 *)((int)((::Obj_9cf *)(reinterpret_cast<::FUN_00980070_shell *>((this->m_04))->FUN_00980070()))), reinterpret_cast<::FUN_0097fc70_shell *>((this->m_04))->FUN_0097fc70(),
                                                        reinterpret_cast<::ActorValueOwner *>(&(pkActorVal->m_a4))->GetActorValueAsInteger((::ActorValue::Index)(11)), bTargetAttacking4,
                                                        !::FUN_007031c0((int)(this->m_04)), bTargetPostAttack_2,
                                                        pkTarget5->v230(), bTargetRecoiling);

                    fPercent4 = FUN_00644580((Obj*)((::Obj_9cf *)(reinterpret_cast<::FUN_00980070_shell *>((this->m_04))->FUN_00980070())), 50, 50, false, bTargetAttacking4);

                    aFMax = FUN_00404010(100.0 - (fChanceTmp + fPercent4), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingObj *>(&::originalRuntimeFloatSetting690)))))));

                    if (fChanceTmp > fPercent4 && fChanceTmp > aFMax)
                    {
                        if (::FUN_009a7940((::SightReference *)(pkActorVal), (::SightReference *)(pkTarget5), (*(const ::NiPoint3 *)(pkActorVal->v1f4())), (*(const ::NiPoint3 *)(pkTarget5->v1f4())), 0, 30))
                        {
                            reinterpret_cast<::FUN_009cce70_shell *>((this))->FUN_009cce70(iAttack4, 0);
                            reinterpret_cast<::FUN_009cf660_shell *>((this))->SetMode(0);
                        }
                        else
                        {
                            reinterpret_cast<::FUN_00435de0_ctor *>(&(helper_))->FUN_00435de0(FUN_00435dd0());
                            this->m_timer60 = helper_;
                        }
                    }
                }
            }
        }
    }
}

struct Obj641
{
};
// Computes a weighted value from object fields scaled by a percent ratio, applying optional additive and multiplicative modifiers.
// @fnv 0x00644680
float __cdecl CalculateWeightedValue(Obj641* object, int percent, int unused, bool useMult, bool useThird,
                                     bool useFirst, bool useSecond, bool useLast)
{
    float value;
    float ratio = (float)(percent / g_d100);
    float modifier1 = useFirst ? reinterpret_cast<::FUN_00644790_class *>((object))->FUN_00644790() : 0.0f;
    float second = useSecond ? reinterpret_cast<::FUN_006447b0_shell *>((object))->GetField84Float() : 0.0f;
    float third = useThird ? reinterpret_cast<::PathingRequest *>((object))->GetGoalZDelta() : 0.0f;
    float weighted = reinterpret_cast<::FUN_004e4600_shell *>((object))->FUN_004e4600() + ::GetFieldEC((const char *)(object)) * ratio;
    value = ((signed char)(reinterpret_cast<::FUN_00798420_shell *>((object))->GetUnk7d())) + modifier1 + second + third + weighted;
    value *= useMult ? ::FUN_006447d0((const char *)(object)) : reinterpret_cast<::FUN_004e4620_shell *>((object))->FUN_004e4620();
    value *= useLast ? reinterpret_cast<::NiCamera *>((object))->GetMaxFarNearRatio() : 1.0f;
    return value;
}

struct xActorM
{
};
struct xCtx
{
};
struct xTimerC
{
    int m_ai[2];
};
struct xOpts
{
};
struct xMgr
{
};
struct xSetting
{
};

class xMelee
{
  public:
    int m_i0;
    xCtx* m_pCtx;
    int m_aiPad[8];
    xTimerC m_kReaction;
    xTimerC m_kDuration;
    int m_aiPad2[11];
    xOpts m_kOpts;
    void UpdateDodge();
};
// @fnv 0x009cc240
void CPAM9cc240::UpdateCombatState()
{
    float _v;
    float a7;
    int h3;
    Act9cc240* dst0;
    P12_9cc240 j;
    P12_9cc240 dst2;
    dst0 = ((::Act9cc240 *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Tgt9cc240* idxTmp;
    idxTmp = ((::Tgt9cc240 *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    m5c = -1.0f;
    reinterpret_cast<::TESForm *>(&(g_011f24e4))->ClearData();
    reinterpret_cast<::fnv_009d0610::FUN_009d0610_shell *>(&(m64))->FUN_009d0610((::fnv_009d0610::TESAmmoInitCalls *)(m4));
    reinterpret_cast<::Procedure98 *>(this)->UpdateState();
    reinterpret_cast<::TESForm *>(this)->ClearData();
    if (((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) == 3 || ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) == 4)
    {
        if (reinterpret_cast<::FUN_008b3b90_shell *>((dst0))->FUN_008b3b90() && !reinterpret_cast<::FUN_008b3960_Class *>((dst0))->FUN_008b3960())
        {
            if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(m48))->FUN_0097fa50())
            {
                reinterpret_cast<::FUN_008d7f40_shell *>(&(m48))->FUN_008d7f40(2.0f);
            }
            else if (reinterpret_cast<::TimeoutTimer *>(&(m48))->CheckTimer())
            {
                reinterpret_cast<::FUN_009cc490_shell *>((((::Proc9cc240 *)(reinterpret_cast<::InterfaceManager *>((m4))->FUN_00586150()))))->FUN_009cc490(2);
                reinterpret_cast<::fnv_009a0ec0::FUN_009a0ec0_shell *>((((::Proc9cc240 *)(reinterpret_cast<::InterfaceManager *>((m4))->FUN_00586150()))))->SetNodeBlockAndTimestamp((const ::fnv_009a0ec0::FUN_009a0ec0_Block *)(::P12_9cc240 *)(((::P12_9cc240 *)(reinterpret_cast<::FUN_00575650_Class *>((idxTmp))->FUN_00575650((::FUN_00575650_Result *)(::P12_9cc240 *)(&j))))));
                reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Could not reach target"));
            }
        }
        else if (reinterpret_cast<::FUN_008b3960_Class *>((dst0))->FUN_008b3960())
        {
            reinterpret_cast<::TimeoutTimer *>(&(m48))->FUN_00910b10();
        }
    }
    else
    {
        reinterpret_cast<::TimeoutTimer *>(&(m48))->FUN_00910b10();
    }
    switch (((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())))
    {
    case 0:
        reinterpret_cast<::CombatProc9cd430 *>(this)->FUN_009cd430();
        break;
    case 2:
        reinterpret_cast<::xMelee *>(this)->UpdateDodge();
        break;
    case 1:
        reinterpret_cast<::FUN_009cde10_shell *>(this)->FUN_009cde10();
        break;
    case 3:
        reinterpret_cast<::CombatProcedure_shell *>(this)->UpdateCombatMovement();
        break;
    case 4:
        reinterpret_cast<::ZMelee *>(this)->UpdateMeleeCombat();
        break;
    }
    bool bDone6;
    bDone6 = false;
    if (3 != m14)
    {
        bDone6 = true;
    }
    else if (m10 == 3)
    {
        bDone6 = true;
    }
    else
    {
        _v = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
        a7 = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
        if (_v - a7 < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting594)))))) * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((dst0))->FUN_00567400() * 2.25)
            bDone6 = true;
    }
    if (bDone6)
    {
        GetTargetLocationWithOffset(&dst2, idxTmp, 2);
        reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((*(const ::NiPoint3 *)(&dst2)), 4);
    }
    else
    {
        reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
    }
    reinterpret_cast<::TESForm *>(&(g_011f24e4))->ClearData();
}

// Advances the dodge reaction timer, checks actor readiness and distance, and triggers a block, strike, or combat notification.
// @fnv 0x009cdb00
void xMelee::UpdateDodge()
{
    if (((int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) != 2)
        return;
    if (reinterpret_cast<::TimeoutTimer *>(&(m_kReaction))->CheckTimer())
    {
        reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
        reinterpret_cast<::FUN_009cfc00_shell *>(this)->FUN_009cfc00();
        return;
    }
    xActorM* qfTOqo = ((::xActorM *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    xActorM* qpqRa = ((::xActorM *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    int qSVM = ((int)(reinterpret_cast<::FUN_008846e0_shell *>((qfTOqo))->GetVtbl20Result()));
    if (!reinterpret_cast<::FUN_004938e0_shell *>((qfTOqo))->FUN_004938e0())
    {
        reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
        return;
    }
    reinterpret_cast<::TESForm *>(this)->ClearData();
    reinterpret_cast<::Dialogue9CF *>(this)->StopIfSpeakerOutOfRange();
    int qsSDDgz = qpqRa ? reinterpret_cast<::FUN_008a7570_shell *>((qpqRa))->FUN_008a7570() : -1;
    if (qsSDDgz == 2 && ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == 2)
    {
        reinterpret_cast<::FUN_009cf6d0_shell *>(this)->FUN_009cf6d0(3);
        reinterpret_cast<::Procedure98 *>(this)->UpdateState();
    }
    if (!reinterpret_cast<::FUN_009cdde0_shell *>(&(m_kOpts))->HasNoFlag((unsigned short)qSVM))
    {
        reinterpret_cast<::fnv_009cfc60::FUN_009cfc60_shell *>(this)->FUN_009cfc60();
        if (::FUN_005b6f70())
            ::FUN_00703c00("%.20s has run out of room to dodge.", reinterpret_cast<::FUN_0055d520_shell *>((qfTOqo))->FUN_0055d520());
        reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
        return;
    }
    float qrEZrs = reinterpret_cast<::FUN_009cfd20_shell *>(this)->GetModifierValue();
    float qdqWL = reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560();
    if ((qSVM & 4) || (qSVM & 8))
    {
        if (qrEZrs > qdqWL)
        {
            if (((bool)(reinterpret_cast<::FUN_009cde10_shell *>(this)->FUN_009cf030(qrEZrs, qdqWL, 0))))
            {
                if (reinterpret_cast<::TimeoutTimer *>(&(m_kDuration))->CheckTimer())
                {
                    reinterpret_cast<::fnv_009cfc60::FUN_009cfc60_shell *>(this)->FUN_009cfc60();
                    reinterpret_cast<::FUN_009ce190_shell *>(this)->FUN_009ce190();
                    return;
                }
            }
            else
                reinterpret_cast<::FUN_008b3a20_shell *>((qfTOqo))->DispatchToTarget(qSVM | 1);
        }
        else if (qrEZrs < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting593)))))) && (qSVM & 1))
            reinterpret_cast<::FUN_008b3a20_shell *>((qfTOqo))->DispatchToTarget(qSVM & ~1);
    }
    else if (qSVM & 1)
    {
        if (qrEZrs <= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting593)))))) && reinterpret_cast<::TimeoutTimer *>(&(m_kDuration))->CheckTimer())
        {
            reinterpret_cast<::fnv_009cfc60::FUN_009cfc60_shell *>(this)->FUN_009cfc60();
            reinterpret_cast<::FUN_009cd410_shell *>(this)->FUN_009cd410();
            return;
        }
    }
    if (qsSDDgz == 2)
    {
        float qxQHW = (float)(::DialogueRandom() % 100);
        if ((qSVM & 0x100) && !((bool)(reinterpret_cast<::fnv_00981900::CombatController *>((m_pCtx))->GetModifierKey())) && qxQHW > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting345)))))))
            reinterpret_cast<::FUN_008b3a20_shell *>((qfTOqo))->DispatchToTarget((qSVM | 0x200) & ~0x100);
    }
    else if (qSVM & 0x200)
        reinterpret_cast<::FUN_008b3a20_shell *>((qfTOqo))->DispatchToTarget((qSVM | 0x100) & ~0x200);
    reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::xMgr * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(m_pCtx), 2, 0, 0);
}


struct FUN_009cfe90_Vector
{
    int x;
    int y;
    int z;
};

struct FUN_009cfe90_TargetBase
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
};

struct FUN_009cfe90_Target : FUN_009cfe90_TargetBase
{
    virtual void vf2ac(int* value);
};

// @fnv 0x009cfe90
float ProcX::FUN_009cfe90()
{
    FUN_009cfe90_Vector value;

    if (((::CombatAttackVT *)(reinterpret_cast<::FUN_00996e00_shell *>((reinterpret_cast<CombatAttackHelper*>(this)))->FUN_00996e00())) == 0 ||
        !reinterpret_cast<::FUN_004938e0_shell *>((reinterpret_cast<FUN_009cfe90_Target*>(((::CombatAttackVT *)(reinterpret_cast<::FUN_00996e00_shell *>((reinterpret_cast<CombatAttackHelper*>(this)))->FUN_00996e00())))))->FUN_004938e0())
        return 0.0f;

    value.x = (*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
    value.y = ::_DAT_011f4270;
    value.z = ::_DAT_011f4274;

    reinterpret_cast<FUN_009cfe90_Target*>(((::CombatAttackVT *)(reinterpret_cast<::FUN_00996e00_shell *>((reinterpret_cast<CombatAttackHelper*>(this)))->FUN_00996e00())))
        ->vf2ac(&value.x);

    return reinterpret_cast<::FUN_00589850_Class *>(&(value))->FUN_00589850();
}

namespace fnv_009ce5b0 {
struct Req
{
    int data[43];
    Req();
    ~Req();
};
struct Vec
{
    float x, y, z;
};
struct Loc
{
    int data[10];
    Loc(Vec const&, void*);
    ~Loc();
};
struct Shape;
struct Avoid
{
    int data[6];
    Avoid();
};
struct Ptr
{
    Avoid* p;
    Ptr(Avoid*);
    ~Ptr();
};
struct Shape
{
    int data[9];
    Shape(int, float, float);
};
struct Settings
{
};
struct Act
{
    float FUN_008be1b0();
};
struct Targ : CombatAttackVT
{
};
struct Holder
{
};
float __cdecl FUN_009a6830(Act*, Targ*, float);
struct C009ce5b0
{
    int pad;
    Holder* holder;
    void FUN_009ce5b0(Vec* pos);
};
// Builds a request using an avoidance shape when both checks pass, otherwise builds one from target data.
// @fnv 0x009ce5b0
void C009ce5b0::FUN_009ce5b0(Vec* apPosition)
{
    Act* actor2 = ((::fnv_009ce5b0::Act *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Targ* target = ((::fnv_009ce5b0::Targ *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    Req request;
    Loc location(*apPosition, actor2);
    if (((unsigned char)(reinterpret_cast<::PathingLocationCheck *>(&(location))->FUN_006ded70(actor2->FUN_008be1b0()))) &&
        ((unsigned char)(::FUN_009a7940((::SightReference *)(actor2), (::SightReference *)(target), (*(const ::NiPoint3 *)(apPosition)), (*(const ::NiPoint3 *)(target->v07d())), 0, 30))))
    {
        Ptr avoidX(new Avoid);
        reinterpret_cast<::FUN_00905450_StandIn *>((((::fnv_009ce5b0::Avoid *)(::FUN_00559450((int *)&(avoidX))))))->AppendNode((::PathingAvoidanceNode *)&(const ::fnv_009ce5b0::Shape &)(Shape(target->v07d(), *((float *)&(::FUN_00403e20((float *)(((Settings*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting385))))))),
                                                  *((float *)&(::FUN_00403e20((float *)(((Settings*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting386))))))))));
        reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor2))->PathToLocation((::fnv_008b3880::PathingRequest *)(::fnv_009ce5b0::Req *)(&request), (void *)(&(*(::fnv_009ce5b0::Vec *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(location))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), (void *)(((unsigned int)(reinterpret_cast<::PathingLocation *>((void *)&(location))->GetContainingCell()))), (void *)(reinterpret_cast<::BGSTerrainManager *>(&(location))->GetMinLevel()), 5.0f,
                             (::fnv_008b3880::PathingAvoidNodeArray *)(::fnv_009ce5b0::Avoid *)(((::fnv_009ce5b0::Avoid *)(::FUN_00559450((int *)&(avoidX))))));
    }
    else
    {
        float distance = 10.0f;
        if ((unsigned char)GetByteAtOffset70(((char *)(reinterpret_cast<::InterfaceManager *>((holder))->FUN_00586150()))))
            distance = FUN_009a6830(actor2, target, reinterpret_cast<::FUN_009ce560_shell *>(this)->FUN_009ce560());
        reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor2))->PathToLocation((::fnv_008b3880::PathingRequest *)(::fnv_009ce5b0::Req *)(&request), (void *)((void*)target->v07d()), (void *)(((unsigned int)(reinterpret_cast<::LowProcess *>((target))->GetTarget()))), (void *)((unsigned)((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((target))->FUN_00575d70()))),
                             distance, (::fnv_008b3880::PathingAvoidNodeArray *)(::fnv_009ce5b0::Avoid *)(0));
    }
    reinterpret_cast<::B_008b3630 *>((actor2))->SetPathingRequestAvoidNodes((::PathingRequest_b *)(::fnv_009ce5b0::Req *)(&request));
}
}  // namespace fnv_009ce5b0

struct FUN_00996de0_ClassQ
{
};
struct FUN_00980070_shellQ
{
};
struct FUN_005524b0_classQ
{
    char GetByteAtOffset8C();
};

// Returns 1 if a is at least b, otherwise 0, ignoring the c parameter.
// @fnv 0x009cf030
unsigned char FUN_009cde10_shell::FUN_009cf030(float a, float b, int aiUnused)
{
    Actor* pTarget3;
    bool bFlag;
    float m_fPackageValue;
    unsigned char bResult = 0;

    pTarget3 = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>((((FUN_00996de0_ClassQ*)this)))->FUN_00996de0()));
    bFlag = ((FUN_005524b0_classQ*)reinterpret_cast<::FUN_00980070_shell *>(((*(FUN_00980070_shellQ**)((char*)this + 4))))->FUN_00980070())->GetByteAtOffset8C() >= 100;
    m_fPackageValue = 0.0f;
    if (a >= b + m_fPackageValue)
    {
        bResult = 1;
    }
    return bResult;
}

#include "generated/data/fallout/ai/combat/combatprocedureattackmelee.inc"
