// gamebryo2.2/corelibs/nianimation/niblendpoint3interpolator.cpp: NiBlendPoint3Interpolator, BlendPointShell (13 functions)

#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BlendCopy.h"
#include "fnv/decl/BlendSerializer.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a36890.h"
#include "fnv/decl/FUN_00a37260_shell.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiColor.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/SBObject.h"
#include "fnv/decl/S_00a370b0_Class.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a37980__Blend100.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a36000.h"
#include "fnv/symbols_00a37000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f4000.h"
#include "niblendpoint3interpolator_decls.h"

// @fnv 0x00a55b90
bool NiBlendPoint3Interpolator::UpdateAccumulatedTransform(float fTime, NiObjectNET* pkTarget, NiPoint3& kValue)
{
    if (m_uiObjectFlags & 1)
        fTime = m_fSingleInterpolatorTime;

    if (fTime == ::DAT_0109696c)
        return false;

    if (m_pSingleInterpolator->Update(fTime, pkTarget, m_kPoint3Value))
    {
        kValue = m_kPoint3Value;
        return true;
    }

    m_kPoint3Value = DAT_011a9424;
    kValue = m_kPoint3Value;
    return false;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
// @fnv 0x00a55af0
GlobalObjectO2_00a7b610* __cdecl FUN_00a55af0()
{
    return &::g_011f406c;
}

struct FUN_00a55ec0_shell : public NiBlendPoint3Interpolator
{
    bool FUN_00a55ec0(NiObject*);
};

struct FUN_00a36fd0_tgt
{
};
struct Call_439090_tgt
{
};

// Calls FUN_00a36fd0 on pkObject; if that succeeds, calls _Call_439090 on pkObject+0x30 and returns its negation.
// @fnv 0x00a55ec0
bool FUN_00a55ec0_shell::FUN_00a55ec0(NiObject* pkObject)
{
    bool r = ::fnv_00a36fd0::FUN_00a36fd0((::fnv_00a36fd0::BlendS *)(((FUN_00a36fd0_tgt*)this)), (int)(pkObject), {});
    if (!r)
        return r;
    r = reinterpret_cast<::NiPlane *>((((Call_439090_tgt*)&this->m_kPoint3Value.x)))->operator==((*(const ::NiPlane *)((char*)pkObject + 0x30)));
    r = !r;
    return r;
}

namespace fnv_00a55ef0 {
struct FUN_00a55ef0_shell : public NiBlendPoint3Interpolator
{
    void AppendPoint3Value(void*);
};

struct ActorCombatGroup;
struct GlobalObjectO2_00a7b610
{
    void* p;
};
struct ViewerBase
{
};
struct ViewerPoint3
{
};
struct ArrSizeHelper
{
};
struct StrArrView
{
    char pad[8];
    unsigned short maxSize;
    unsigned short count;
    char pad2[2];
    unsigned short growBy;
};
typedef NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > StrArray;
// @fnv 0x00a55ef0
void FUN_00a55ef0_shell::AppendPoint3Value(void* pkStrings)
{
    reinterpret_cast<::BlendSerializer *>((((ViewerBase*)this)))->FUN_00a38080((::NiStream *)(pkStrings));
    StrArray* arr = (StrArray*)pkStrings;
    StrArrView* pArrayView = (StrArrView*)pkStrings;
    ActorCombatGroup* pElement = (ActorCombatGroup*)::FUN_00a7d330((*(const char * *)&(const ::fnv_00a55ef0::GlobalObjectO2_00a7b610 &)((*reinterpret_cast<::fnv_00a55ef0::GlobalObjectO2_00a7b610 *>(&::g_011f406c)))));
    unsigned int i = pArrayView->count;
    if (i >= pArrayView->maxSize)
        reinterpret_cast<::ViewerStrings *>((((ArrSizeHelper*)arr)))->SetSize(pArrayView->growBy + i);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((((ArrSizeHelper*)arr)))->SetAt(i, (char *&)(pElement));
    pElement = (ActorCombatGroup*)reinterpret_cast<::NiPoint3 *>((((ViewerPoint3*)&this->m_kPoint3Value.x)))->FUN_00a59af0("m_kPoint3Value");
    i = pArrayView->count;
    if (i >= pArrayView->maxSize)
        reinterpret_cast<::ViewerStrings *>((((ArrSizeHelper*)arr)))->SetSize(pArrayView->growBy + i);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((((ArrSizeHelper*)arr)))->SetAt(i, (char *&)(pElement));
}
}  // namespace fnv_00a55ef0

// Calls the virtual function at vtable offset 0xb0 on p and returns its bool result.
// @fnv 0x00a55a60
bool FUN_00a55a60(NiBlendPoint3Interpolator* p)
{
    return reinterpret_cast<bool(*)(NiObject*)>(*reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const unsigned char*>(*reinterpret_cast<const unsigned int*>(p)) + 0xb0))(p);
}

struct BSFadeNode
{
};
extern int DAT_0109a49c;
// @fnv 0x00a55a80
void* FUN_00a55a80()
{
    void* p = ::operator new(64);
    if (p)
    {
        new ((void *)(p)) class ::FUN_00a36890();
        *(void**)p = (void*)&DAT_0109a49c;
        *(int*)((char*)p + 0x30) = (*reinterpret_cast<int *>((void *)&::DAT_011a9424));
        *(int*)((char*)p + 0x34) = (*reinterpret_cast<int *>(&::DAT_011a9428));
        *(int*)((char*)p + 0x38) = (*reinterpret_cast<int *>(&::DAT_011a942c));
        *(unsigned char*)((char*)p + 0x3c) = 0;
        return p;
    }
    return 0;
}

struct FUN_00a37ec0_tgt
{
};
struct NiColorSaveHelper
{
    void SaveBinary(NiStream&);
};
struct FUN_00a37ec0_shell : public NiBlendPoint3Interpolator
{
    void FUN_00a55ad0(NiStream& stream);
};
// @fnv 0x00a55ad0
void FUN_00a37ec0_shell::FUN_00a55ad0(NiStream& stream)
{
    reinterpret_cast<::SBObject *>((((FUN_00a37ec0_tgt*)this)))->FUN_00a37ec0((::SBStream &)(stream));
    reinterpret_cast<::NiColor *>((((NiColorSaveHelper*)&this->m_kPoint3Value.x)))->SaveBinary(stream);
}

struct Cls_00a55b00
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls DestroyInterpolatorArray on this, frees this with _delete when bit 0 of f is set, and returns this.
// @fnv 0x00a55b00
void* Cls_00a55b00::DestroyIfFlagged(unsigned int auiFlags)
{
    ::DestroyInterpolatorArray((::NiBlendInterpolator *)(void *)(this), {});
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x40);
    return this;
}

struct CloningProcess;
struct CloneOwner
{
};
struct FUN_00a55b20_shell : public NiBlendPoint3Interpolator
{
    void* FUN_00a55b20(CloningProcess*);
};
// Allocates a NiBlendPoint3Interpolator, initialises it, copies the point3 fields and flag from this, and returns the clone.
// @fnv 0x00a55b20
void* FUN_00a55b20_shell::FUN_00a55b20(CloningProcess* kCloning)
{
    NiBlendPoint3Interpolator* pkObject = static_cast<NiBlendPoint3Interpolator*>(::operator new(0x40));
    if (pkObject)
    {
        new ((void *)(pkObject)) class ::FUN_00a36890();
        *reinterpret_cast<void**>(pkObject) = &DAT_0109a49c;
        *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.x) = (*reinterpret_cast<int *>((void *)&::DAT_011a9424));
        *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.y) = (*reinterpret_cast<int *>(&::DAT_011a9428));
        *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.z) = (*reinterpret_cast<int *>(&::DAT_011a942c));
        *reinterpret_cast<char*>(&pkObject->m_bValueValid) = 0;
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<::BlendCopy *>((reinterpret_cast<CloneOwner*>(this)))->FUN_00a37510((::NiBlendInterpolator *)(pkObject), (::CloningProcess *)(kCloning));
    *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.x) =
        *reinterpret_cast<int*>(&this->m_kPoint3Value.x);
    *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.y) =
        *reinterpret_cast<int*>(&this->m_kPoint3Value.y);
    *reinterpret_cast<int*>(&pkObject->m_kPoint3Value.z) =
        *reinterpret_cast<int*>(&this->m_kPoint3Value.z);
    *reinterpret_cast<char*>(&pkObject->m_bValueValid) =
        *reinterpret_cast<char*>(&this->m_bValueValid);
    return pkObject;
}

extern int DAT_0109a49c;

struct FUN_00a370b0_tgt
{
};

struct FUN_00a55a10
{
    int m_vptr;
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
    NiPoint3 m_kPoint3Value;
    bool m_bValueValid;

    FUN_00a55a10(void* a, float f, void* c);
};

// @fnv 0x00a55a10
FUN_00a55a10::FUN_00a55a10(void* apArg, float f, void* c)
{
    reinterpret_cast<::S_00a370b0_Class *>((((FUN_00a370b0_tgt*)this)))->FUN_00a370b0((bool)(apArg), f, (volatile unsigned char)(c));
    m_vptr = reinterpret_cast<int>(&DAT_0109a49c);
    m_kPoint3Value = DAT_011a9424;
    m_bValueValid = false;
}

struct FUN_00a37980_tgt
{
};
struct FUN_00a59be0_tgt
{
};
struct FUN_00a55e60_cls : public NiBlendPoint3Interpolator
{
    void FUN_00a55e60(NiObjectNET* p);
};
// @fnv 0x00a55e60
void FUN_00a55e60_cls::FUN_00a55e60(NiObjectNET* apObject)
{
    reinterpret_cast<::fnv_00a37980::Blend100 *>((((FUN_00a37980_tgt*)this)))->FUN_00a37980((*(::fnv_00a37980::Stream100 *)(apObject)));
    NiPoint3* pt = &m_kPoint3Value;
    reinterpret_cast<::NiColor *>((((FUN_00a59be0_tgt*)pt)))->LoadBinary((*(::NiStream *)(apObject)));
    if (pt->x != DAT_011a9424.x || pt->y != DAT_011a9424.y || pt->z != DAT_011a9424.z)
    {
        m_bValueValid = true;
    }
}

class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    int m_iValueAt14;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
struct BlendPointShell : NiBlendPoint3Interpolator
{
    static NiPoint3& Add(NiPoint3& a, const NiPoint3& b)
    {
        a.x = b.x + a.x;
        float* pa = &a.x;
        pa[1] += b.y;
        pa[2] += b.z;
        return a;
    }
    bool GetTime(unsigned char index, float& time)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[index];
        if (!item.m_spControllerInterpolator || item.m_fNormalizedWeight == 0.0f)
            return false;
        if (m_uiObjectFlags & 1)
            time = item.m_fLastEvaluationTime;
        return time != ::DAT_0109696c;
    }
    bool FUN_00a55c30(float time, NiObjectNET* target, NiPoint3& value);
};
// Updates the interpolator: delegates to single or multi-interpolation update based on m_ucInterpCount, stores fTime in m_fLastTime, and returns success.
// @fnv 0x00a55e00
bool NiBlendPoint3Interpolator::Update(float fTime, NiObjectNET* pkTarget, NiPoint3& kValue)
{
    bool bSuccess = false;
    if (m_ucInterpCount == 1)
        bSuccess = UpdateAccumulatedTransform(fTime, pkTarget, kValue);
    else if (m_ucInterpCount > 0)
    {
        reinterpret_cast<::FUN_00a37260_shell *>(this)->UpdateNormalizedWeights();
        bSuccess = reinterpret_cast<::BlendPointShell *>(this)->FUN_00a55c30(fTime, pkTarget, kValue);
    }
    m_fLastTime = fTime;
    return bSuccess;
}
// Blends successful controller values using normalized weights, adjusts for skipped weights, and writes the result to value.
// @fnv 0x00a55c30
bool BlendPointShell::FUN_00a55c30(float time, NiObjectNET* target, NiPoint3& value)
{
    float weight = 1.0f;
    m_bValueValid = false;
    m_kPoint3Value = ::NiPoint3::ZERO;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[i];
        if (item.m_spControllerInterpolator && item.m_fNormalizedWeight > 0.0f)
        {
            float updateTime = time;
            if (!GetTime(i, updateTime))
            {
                weight -= item.m_fNormalizedWeight;
                continue;
            }
            NiPoint3 tempPoint;
            if (item.m_spControllerInterpolator->Update(updateTime, target, tempPoint))
            {
                float w = m_pInterpArray[i].m_fNormalizedWeight;
                NiPoint3 scaledPoint;
                scaledPoint.x = tempPoint.x * w;
                scaledPoint.y = tempPoint.y * w;
                scaledPoint.z = tempPoint.z * w;
                Add(m_kPoint3Value, scaledPoint);
                m_bValueValid = true;
            }
            else
                weight -= m_pInterpArray[i].m_fNormalizedWeight;
        }
    }
    if (!m_bValueValid)
    {
        m_kPoint3Value = DAT_011a9424;
        value = m_kPoint3Value;
        return false;
    }
    float inverseWeight = 1.0f / weight;
    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(m_kPoint3Value))->FUN_00439180(inverseWeight);
    value = m_kPoint3Value;
    return true;
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/niblendpoint3interpolator.inc"
