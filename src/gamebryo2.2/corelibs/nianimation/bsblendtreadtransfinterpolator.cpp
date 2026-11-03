
#include <new>
#include "fnv/decl/BlendCopy.h"
#include "fnv/decl/FUN_00a37260_shell.h"
#include "fnv/decl/NiQuaternion.h"
#include "fnv/decl/SBObject.h"
#include "fnv/decl/fnv_00a37980__Blend100.h"
#include "fnv/symbols_00a36000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011f3000.h"
#include "bsblendtreadtransfinterpolator_decls.h"
struct GlobalObjectO2_00a7b610;

// @fnv 0x00a42fe0
GlobalObjectO2_00a7b610* __cdecl FUN_00a42fe0()
{
    return &::g_011f3ed0;
}

struct BSFadeNode
{
    void* operator new(unsigned int);
};
extern int DAT_01097904;
void __fastcall FUN_00a36890(void*);
struct CloneOwner
{
    char _pad0[0x30];
    float m_fValueAtOffset30;
    void* __thiscall Clone(void* kCloning);
};
// ---- stand-in for the undeclared NiInterpolator (vtable slot 46 = +0xb8) ----
class NiInterpolator
{
  public:
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
    virtual bool IsCorrectType();
public:
    NiInterpolator();
};

// @fnv 0x00a39100
bool __stdcall FUN_00a39100(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->IsCorrectType();
}

namespace fnv_00a43160 {
struct NiPoint3
{
    float x, y, z;
};
struct NiQuaternion
{
    float w, x, y, z;
};
struct NiQuatTransform
{
    NiPoint3 translate;
    NiQuaternion rotate;
    float scale;
};
struct NiObjectNET;
struct NiInterpolatorUpdate
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual bool Update(float, NiObjectNET*, NiQuatTransform&);
    int unk04, unk08, unk0c, unk10, unk14;
    float m_fScale;
};
struct BlendItem
{
    NiInterpolatorUpdate* interpolator;
    int unk04;
    float weight;
    int unk0c, unk10;
    float time;
};
struct BSBlendInterpClass
{
    void* vtbl;
    unsigned int refCount;
    float lastTime;
    unsigned char flags, count, active, single;
    int unk10;
    BlendItem* items;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    float phase;
    bool BlendInterpolators(float time, NiObjectNET* object, NiQuatTransform& result);
};
// @fnv 0x00a43160
bool BSBlendInterpClass::BlendInterpolators(float time, NiObjectNET* object, NiQuatTransform& arResult)
{
    float total = 0.0f;
    for (unsigned char i = 0; i < count; ++i)
    {
        BlendItem& item = items[i];
        if (item.interpolator && item.weight > 0.0f)
        {
            float sampleTime = time;
            if (item.weight != 0.0f)
            {
                if (flags & 1)
                    sampleTime = item.time;
                if (sampleTime != ::DAT_0109696c)
                {
                    NiQuatTransform transform = {(*reinterpret_cast<const ::fnv_00a43160::NiPoint3 *>(&::DAT_011a8400)), (*reinterpret_cast<const ::fnv_00a43160::NiQuaternion *>(&::DAT_011f3704)), ::DAT_01096b8c};
                    if (item.interpolator->Update(sampleTime, object, transform))
                    {
                        total += item.interpolator->m_fScale * item.weight;
                    }
                }
            }
        }
    }
    float& combined = phase;
    combined += total;
    if (combined > 1.0f)
        phase = combined - ::g_01012070;
    else if (combined < 0.0f)
        phase = combined + ::g_01012070;
    float* __restrict pfOut = (float*)&arResult;
    pfOut[7] = pfOut[4] = pfOut[0] = ::DAT_01015f5c;
    return true;
}
}  // namespace fnv_00a43160

// @fnv 0x00a40a00
void __cdecl FUN_00a40a00()
{
    ::fnv_00a36f80::FUN_00a36f80({}, {}, *(::fnv_00a36f80::StreamS *)nullptr);
}

// @fnv 0x00a40a10
void __cdecl FUN_00a40a10()
{
    static_cast<::SBObject *>(nullptr)->FUN_00a37ec0(*(::SBStream *)nullptr);
}


// @fnv 0x00a42fc0
void __cdecl FUN_00a42fc0()
{
    static_cast<::fnv_00a37980::Blend100 *>(nullptr)->FUN_00a37980(*(::fnv_00a37980::Stream100 *)nullptr);
}


// @fnv 0x00a42fd0
void __cdecl FUN_00a42fd0()
{
    ::fnv_00a36fd0::FUN_00a36fd0({}, {}, {});
}

struct QQuatOps
{
    float x, y, z, w;
};
class NiQuatTransform
{
  public:
    float px, py, pz;
    QQuatOps rotation;
    float scale;
};
class TreadInterp
{
  public:
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
    virtual bool Update(float, NiObjectNET*, NiQuatTransform&);
    float unk04, unk08, unk0c, unk10, unk14, delta;
};
class TreadOwner
{
  public:
    int unk00, unk04, unk08;
    unsigned char flags, unk0d, unk0e, unk0f;
    int unk10, unk14;
    TreadInterp* single;
    int unk1c;
    float time;
    int unk24, unk28, unk2c;
    float lerp;
    bool UpdateTreadTransform(float, NiObjectNET*, NiQuatTransform&);
};
// @fnv 0x00a432d0
bool BSBlendTreadTransfInterpolator::Update(float time, NiObjectNET* target, NiQuatTransform& arValue)
{
    bool result = false;
    if (m_ucInterpCount == 1)
        result = reinterpret_cast<::TreadOwner *>(this)->UpdateTreadTransform(time, target, arValue);
    else if (m_ucInterpCount > 0)
    {
        reinterpret_cast<::FUN_00a37260_shell *>(this)->UpdateNormalizedWeights();
        result = UpdateAccumulatedTransform(time, target, arValue);
    }
    m_fLastTime = time;
    return result;
}
// @fnv 0x00a43040
bool TreadOwner::UpdateTreadTransform(float afTime, NiObjectNET* target, NiQuatTransform& arTransform)
{
    if (flags & 1)
        afTime = time;
    if (afTime == DAT_0109696c)
    {
        arTransform.px = -3.4028234663852886e38f;
        arTransform.rotation.y = -3.4028234663852886e38f;
        arTransform.scale = -3.4028234663852886e38f;
        return false;
    }
    if (single->Update(afTime, target, arTransform))
    {
        lerp += single->delta;
        if (lerp > 1.0f)
            lerp = lerp - 1.0;
        else if (lerp < 0.0f)
            lerp = lerp + 1.0;
        if (arTransform.rotation.y != -3.4028234663852886e38)
        {
            QQuatOps qRotation = arTransform.rotation;
            reinterpret_cast<::NiQuaternion *>(&(qRotation))->MakeUnitLength();
            arTransform.rotation = qRotation;
        }
        return true;
    }
    arTransform.px = -3.4028234663852886e38f;
    arTransform.rotation.y = -3.4028234663852886e38f;
    arTransform.scale = -3.4028234663852886e38f;
    return false;
}

static volatile float BlendTimeValue = -3.402823466e+38f;
extern int DAT_0109697c;

class InterpolatorStorage
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    float m_fLastTime;
    InterpolatorStorage()
    {
        new ((void *)this) ::NiInterpolator();
    }
};

class FUN_00a36890 : public InterpolatorStorage
{
  public:
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    void* m_pInterpArray;
    void* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;
    FUN_00a36890();
};
// @fnv 0x00a42ff0
void* __thiscall CloneOwner::Clone(void* kCloning)
{
    CloneOwner* pkObject;
    pkObject = (CloneOwner*)BSFadeNode::operator new(0x34);
    if (pkObject)
    {
        new ((void *)(pkObject)) class ::FUN_00a36890();
        pkObject->m_fValueAtOffset30 = 0.0f;
        *(void**)pkObject = (void*)&DAT_01097904;
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<::BlendCopy *>(this)->FUN_00a37510((::NiBlendInterpolator *)(pkObject), (::CloningProcess *)(kCloning));
    pkObject->m_fValueAtOffset30 = m_fValueAtOffset30;
    return pkObject;
}

typedef class FUN_00a36890 BlendConstructor;

// Initializes BlendConstructor members, setting array and single interpolator pointers to null and weight fields to BlendTimeValue.
// @fnv 0x00a36890
BlendConstructor::FUN_00a36890()
    : m_uiObjectFlags((m_ppVirtualMethodTable = &DAT_0109697c, 0)), m_ucArraySize(0), m_ucInterpCount(0), m_ucSingleIdx(0xff),
      m_cHighPriority(-128), m_cNextHighPriority(-128), m_pInterpArray(0), m_pSingleInterpolator(0),
      m_fWeightThreshold(0.0f), m_fSingleInterpolatorTime(BlendTimeValue), m_fHighSumOfWeights(BlendTimeValue),
      m_fNextHighSumOfWeights(BlendTimeValue), m_fTrailingValue(BlendTimeValue)
{}
