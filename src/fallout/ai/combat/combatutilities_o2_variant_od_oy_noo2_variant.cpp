
// src/fallout/ai/combat/combatutilities_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/combatutilities_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/combatutilities_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/combatutilities.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/combatutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004fd420_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_009c0000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f1000.h"
float __cdecl FUN_009a7dd0(float a, float b, float c);
extern int DAT_011a558c;
extern "C" int DAT_011a558c;
float ScaleCharToFloat(char arg);
struct FUN_009a9f00_shell
{
    void SetFieldE0(float value);
};
struct BGSProjectile
{
};
struct FUN_009a7f80_shell : BGSProjectile
{
    bool FUN_009a7f80() const;
};
long __cdecl ScaleByRatio(float a);

// FUN_009a6e90 - trajectory raycast stepper, worker5 v1 one-pass transcription
struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    float ComputeMagnitude() const;
};
struct PtOp
{
    NiPoint3 operator-(const NiPoint3& o) const;
};
struct Pt
{
};
struct NiPoint3Ex
{
    NiPoint3 operator+(const NiPoint3& o) const;
};
struct NiPoint3_helper
{
    NiPoint3 operator*(float f) const;
};

struct bhkFilter
{
};
struct FUN_00931ed0_shell
{
    bhkFilter* FUN_00931ed0(void* p);
};
struct TESObjectCELL;
struct TESObjectREFR
{
};
class TESObjectREFR;
struct FUN_00553ee0_shell
{
public:
    void *FUN_00553ee0(::TESObjectREFR *);
};
struct FUN_004a39f0_shell
{
    void FUN_004a39f0(int a);
};
struct FUN_0059ce80_shell
{
    void FUN_0059ce80(unsigned int a);
};
struct FUN_00966980_shell
{
    float FUN_00966980();
};
struct PathingRequest
{
};
struct GlobalObject_008c71b0
{
    int m_val;
    GlobalObject_008c71b0(int a);
};
struct LockObj
{
};
struct SETTING_VALUE
{
    int value;
};
struct GameSettingCollection
{
    SETTING_VALUE* Bool();
};
struct hkpAllRayHitCollector;
struct FUN_004a3f70_shell
{
    void FUN_004a3f70(int value);
};
struct FUN_004a3fb0_shell
{
    void FUN_004a3fb0(hkpAllRayHitCollector* p);
};
struct FUN_004a3da0_shell
{
};
struct FUN_004a3eb0_shell
{
    void FUN_004a3eb0(void* p);
};

class FUN_004a3a70
{
  public:
    FUN_004a3a70();
    virtual ~FUN_004a3a70();
    union HitVec
    {
        float components[4];
        char bytes[16];
    };
    HitVec m_kHits[50];
    int m_tail0;
};
struct __declspec(align(16)) FUN_004a3c20_shell
{
    FUN_004a3c20_shell();
    float m_v[44];
};


float cos(float a);


// @fnv 0x009a6e90
bool __cdecl FUN_009a6e90(void* a0, void* a1, float a2, float s0, float s1, float s2, float e0, float e1, float e2,
                          NiPoint3* outPt, int* outInt, float* outFrac)
{
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::LockObj *>(&::g_011f1c7c))))->ClearData();
    GlobalObject_008c71b0 obj18(0);
    ((FUN_004a39f0_shell*)&obj18)->FUN_004a39f0(6);
    int tmp1c;
    ((FUN_0059ce80_shell*)&obj18)
        ->FUN_0059ce80((unsigned int)((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((FUN_00931ed0_shell*)a0)->FUN_00931ed0(&tmp1c)))->FUN_004a3a20())));

    double d28;
    if (a1)
    {
        d28 = (double)(((FUN_00966980_shell*)a1)->FUN_00966980() * ::DAT_011f1c00);
    }
    else
    {
        d28 = 0.0;
    }
    float v2c = (float)d28;
    int v30 = 0;
    int v34 = 0;

    FUN_004a3a70 obj360;
    FUN_004a3c20_shell obj410;
    ((FUN_004a3f70_shell*)&obj410)->FUN_004a3f70(obj18.m_val);
    ((FUN_004a3fb0_shell*)&obj410)->FUN_004a3fb0((hkpAllRayHitCollector*)&obj360);

    NiPoint3 vecStart;
    vecStart = *(NiPoint3*)&s0;
    NiPoint3 pos;
    pos = *(NiPoint3*)&e0;
    float frac = 0.0f;
    unsigned int v430 = 1;
    unsigned int cnt = 1;

    if (v2c == ::_DAT_01012060)
    {
        reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>((((FUN_004a3da0_shell*)&obj410)))->FUN_004a3da0(&vecStart);
        ((FUN_004a3eb0_shell*)&obj410)->FUN_004a3eb0(&pos);
        v30 = ((int)(((FUN_00553ee0_shell*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((((TESObjectREFR*)a0)))->GetTarget())))->FUN_00553ee0({})));
        v34 = ::FUN_009c0d80((::Scene *)(void *)(&obj410), (::Controller *)(0), (int)(a1), &frac, 0, 3.4028234663852886e38f);
        if (*(unsigned char*)(*reinterpret_cast<::GameSettingCollection *>(&::g_011f1c4c)).Bool() &&
            (DAT_011dea24 == 0 || DAT_011dea24 == (*reinterpret_cast<int *>(&::_g_thePlayer)) || DAT_011dea24 == (int)a0))
        {
            ::DrawDebugLine((*(const ::DebugPoint *)(&vecStart)), (*(const ::DebugPoint *)(&pos)), v34, frac, (const ::RgbaColor *)(0), (const ::RgbaColor *)(0));
        }
    }
    else
    {
        NiPoint3 diff = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((PtOp*)&e0)))->FUN_00439ef0-((::NiPoint3 *)&(*(NiPoint3*)&s0), *(const ::NiPoint3 *)nullptr)));
        float v448 = FUN_004b54c0(diff.z / reinterpret_cast<::NiPoint3 *>((void *)(((Pt*)&diff)))->ComputeMagnitude());
        diff.z = 0.0f;
        float v44c = reinterpret_cast<::NiPoint3 *>((void *)(((Pt*)&diff)))->ComputeMagnitude();
        float v450 = ::GetAngleFromVector((*(const ::NiPoint3 *)(&diff)));
        float v454 = a2;
        if (v454 == ::_DAT_01012060)
        {
            v454 = ::GetFloatAtOffset68((const char *)(((PathingRequest*)a1)));
        }
        cnt = (unsigned int)((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GameSettingCollection *>(&::g_011cfd7c))))))->value;
        float v464 = v44c / cnt;
        float v468 = FUN_004e44b0(v450) * v464;
        float v46c = cos(v450) * v464;
        float v470 = FUN_0057dd70(v448);
        float v474 = cos(v448);
        unsigned int i;
        for (i = 0; i < cnt; i++)
        {
            v430 = i + 1;
            pos = *(NiPoint3*)&s0;
            float t = (float)(v430 * v464);
            float v488 = t * v470 - v2c * t * t / (v454 * v454 * v474 * v474 * ::DAT_01011590);
            pos.x += v430 * v468;
            pos.y += v430 * v46c;
            pos.z += v488;
            reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>((((FUN_004a3da0_shell*)&obj410)))->FUN_004a3da0(&vecStart);
            ((FUN_004a3eb0_shell*)&obj410)->FUN_004a3eb0(&pos);
            v30 = ((int)(((FUN_00553ee0_shell*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((((TESObjectREFR*)a0)))->GetTarget())))->FUN_00553ee0({})));
            v34 = ::FUN_009c0d80((::Scene *)(void *)(&obj410), (::Controller *)(0), (int)(a1), &frac, 0, 3.4028234663852886e38f);
            if (*(unsigned char*)(*reinterpret_cast<::GameSettingCollection *>(&::g_011f1c4c)).Bool() &&
                (DAT_011dea24 == 0 || DAT_011dea24 == (*reinterpret_cast<int *>(&::_g_thePlayer)) || DAT_011dea24 == (int)a0))
            {
                ::DrawDebugLine((*(const ::DebugPoint *)(&vecStart)), (*(const ::DebugPoint *)(&pos)), v34, frac, (const ::RgbaColor *)(0), (const ::RgbaColor *)(0));
            }
            if (v34)
                break;
            vecStart = pos;
        }
    }

    if (v34)
    {
        if (outInt)
        {
            *outInt = ((int)(::FUN_0056f930((::NiAVObject *)(v34))));
        }
        if (outPt)
        {
            *outPt = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(((NiPoint3Ex*)&((NiPoint3_helper*)&(*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((PtOp*)&pos)))->FUN_00439ef0-((::NiPoint3 *)&(vecStart), *(const ::NiPoint3 *)nullptr))))->operator*(frac))))->ProjectileLaunched+((::NiPoint3 *)&(vecStart), {})));
        }
        if (outFrac)
        {
            if (cnt == 1)
            {
                *outFrac = frac;
            }
            else
            {
                *outFrac = frac / cnt + (v430 - 1) / (float)cnt;
            }
        }
        reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::LockObj *>(&::g_011f1c7c))))->ClearData();
        return true;
    }
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::LockObj *>(&::g_011f1c7c))))->ClearData();
    return false;
}
