// fallout_shared/facegen/bsfacegenkeyframe.cpp: BSFaceGenKeyframeMultiple, BSFaceGenKeyframe, DelStandIn, KFThis and more (26 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Sd4e0.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0064f000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d5000.h"
#include "bsfacegenkeyframe_decls.h"

// @fnv 0x00488d50
float BSFaceGenKeyframe::GetTime()
{
    return fTime;
}

// @fnv 0x0064f850
void BSFaceGenKeyframeMultiple::NormalizeFaceGenValues()
{
    BSFaceGenManager::NormalizeFaceGenValues(m_pfFaceGenValues, m_uiFaceGenValueCount);
}

// Sets eType to the given morph type and returns true if it changed, otherwise returns false.
// @fnv 0x0064eb00
bool BSFaceGenKeyframe::SetType(BS_FACEGEN_MORPH_TYPE type)
{
    if (type != eType)
    {
        eType = type;
        return true;
    }
    return false;
}

// Sets fTime to the given time and returns true if it changed, otherwise returns false.
// @fnv 0x0064eb30
bool BSFaceGenKeyframe::SetTime(float time)
{
    if (time != fTime)
    {
        fTime = time;
        return true;
    }
    return false;
}

// @fnv 0x0064ed00
BSFaceGenKeyframeMultiple::~BSFaceGenKeyframeMultiple()
{
    BSFaceGenKeyframeMultiple::ApplyFaceGenValues(0, true);
}

// Returns true if quantity is in range and the keyframe value at that index lies between 0.0 and 1.0.
// @fnv 0x0064fb90
bool BSFaceGenKeyframeMultiple::IsQuantityInRange(unsigned int uiIndex)
{
    return uiIndex < m_uiFaceGenValueCount ? (m_pfFaceGenValues[uiIndex] >= 0.0 && m_pfFaceGenValues[uiIndex] <= 1.0)
                                           : false;
}

// Returns the largest value among the keyframes whose validity check passes, or 0.0f if none do.
// @fnv 0x0064f760
float BSFaceGenKeyframeMultiple::GetAttributeStrength()
{
    float fMaxValue = 0.0f;
    for (unsigned int quantity = 0; quantity < m_uiFaceGenValueCount; ++quantity)
    {
        if (IsQuantityInRange(quantity))
        {
            if (m_pfFaceGenValues[quantity] > fMaxValue)
                fMaxValue = m_pfFaceGenValues[quantity];
        }
    }
    return fMaxValue;
}

// @fnv 0x0064f880
bool BSFaceGenKeyframeMultiple::HasNonzeroQuantity()
{
    for (unsigned int i = 0; i < m_uiFaceGenValueCount; ++i)
    {
        float quantity = m_pfFaceGenValues[i];
        if (quantity < 0.0 || quantity > 1.0)
            continue;
        if (quantity > 0.0)
            return true;
    }
    return false;
}

// @fnv 0x0064eb60
BSFaceGenKeyframeMultiple::BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE aeMorphType, unsigned int count)
    : BSFaceGenKeyframe(aeMorphType)
{
    m_pfFaceGenValues = 0;
    m_uiFaceGenValueCount = 0;
    BSFaceGenKeyframeMultiple::ApplyFaceGenValues(count, true);
}

// @fnv 0x0064f480
bool BSFaceGenKeyframeMultiple::ClearData(bool initialize)
{
    bool changed = false;
    if (vfn_0c() != 0.0)
        changed = true;
    vfn_10(0.0f);
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((reinterpret_cast<OSGlobals*>(this)))->FUN_0044edb0())); ++i)
    {
        if (IsQuantityInRange(i))
        {
            changed = true;
            break;
        }
    }
    ApplyFaceGenValues(((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((reinterpret_cast<OSGlobals*>(this)))->FUN_0044edb0())), initialize);
    return changed;
}

// @fnv 0x0064fc00
void BSFaceGenKeyframeMultiple::ApplyFaceGenValues(unsigned int count, bool initialize)
{
    if (count != m_uiFaceGenValueCount)
    {
        if (m_pfFaceGenValues)
        {
            delete[] m_pfFaceGenValues;
            m_pfFaceGenValues = 0;
        }
        m_uiFaceGenValueCount = count;
        if (m_uiFaceGenValueCount > 0)
        {
            m_pfFaceGenValues = new float[m_uiFaceGenValueCount];
            BSFaceGenManager::ApplyFaceGenValues(m_pfFaceGenValues, m_uiFaceGenValueCount, initialize);
        }
    }
    if (m_uiFaceGenValueCount > 0)
        BSFaceGenManager::ApplyFaceGenValues(m_pfFaceGenValues, m_uiFaceGenValueCount, initialize);
}

extern int DAT_010653fc;

struct FUN_0064ea80_helper
{
    int vtable;
    int iType;
    float fTime;
    void* Init(int aeType);
};

// Sets the vtable, stores aeType in iType, resets fTime to 0.0f and returns this.
// @fnv 0x0064ea80
void* FUN_0064ea80_helper::Init(int aeType)
{
    vtable = (int)&DAT_010653fc;
    iType = aeType;
    fTime = 0.0f;
    return this;
}

struct FUN_0064eae0_shell : public BSFaceGenKeyframe
{
    void SetVTable();
};

extern int DAT_010653fc;

// @fnv 0x0064eae0
void FUN_0064eae0_shell::SetVTable()
{
    *(int**)this = &DAT_010653fc;
}

struct FUN_0064f690_shell : public BSFaceGenKeyframeMultiple
{
    bool DiffersFrom(BSFaceGenKeyframe*);
};

struct RotationValues
{
};

struct VTableHelper
{
    virtual void v0();
    virtual unsigned int v1();
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
    virtual bool v17();
};

// Returns true if apOther is not a matching BSFaceGenKeyframeMultiple or any of its per-index values differ from this keyframe's.
// @fnv 0x0064f690
bool FUN_0064f690_shell::DiffersFrom(BSFaceGenKeyframe* apOther)
{
    BSFaceGenKeyframeMultiple* pkeyframe = (apOther && reinterpret_cast<VTableHelper*>(apOther)->v17())
                                               ? reinterpret_cast<BSFaceGenKeyframeMultiple*>(apOther)
                                               : 0;
    if (!pkeyframe || reinterpret_cast<VTableHelper*>(pkeyframe)->v1() != reinterpret_cast<VTableHelper*>(this)->v1() ||
        ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((reinterpret_cast<OSGlobals*>(pkeyframe)))->FUN_0044edb0())) !=
            ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((reinterpret_cast<OSGlobals*>(this)))->FUN_0044edb0())))
    {
        return true;
    }
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((reinterpret_cast<OSGlobals*>(this)))->FUN_0044edb0())); ++i)
    {
        if (reinterpret_cast<::Sd4e0 *>((reinterpret_cast<RotationValues*>(pkeyframe)))->FUN_005dd4e0(i) !=
            reinterpret_cast<::Sd4e0 *>((reinterpret_cast<RotationValues*>(this)))->FUN_005dd4e0(i))
        {
            return true;
        }
    }
    return false;
}

union SETTING_VALUE
{
    float f;
};

struct SettingT_GameSettingCollection_
{
};


// Returns the float value of originalRuntimeFloatSetting1262 if it is greater than 0.0, otherwise returns 0.0f.
// @fnv 0x0064fb10
float __cdecl FUN_0064fb10()
{
    return ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1262))))))->f > 0.0 ? ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1262))))))->f : 0.0f;
}

namespace fnv_0064fb50 {
struct SettingT_GameSettingCollection_
{
};

// Returns the float value from g_011d577c if it is greater than zero, otherwise returns 0.0f.
// @fnv 0x0064fb50
float __cdecl FUN_0064fb50()
{
    return *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0064fb50::SettingT_GameSettingCollection_ *>(&::g_011d577c)))))) > 0.0 ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0064fb50::SettingT_GameSettingCollection_ *>(&::g_011d577c)))))) : 0.0f;
}
}  // namespace fnv_0064fb50

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_0064ebe0(unsigned int flags);
};
// Runs the destructor on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0064ebe0
void* DelStandIn::FUN_0064ebe0(unsigned int flags)
{
    reinterpret_cast<::BSFaceGenKeyframeMultiple *>((((DtorStandIn*)this)))->BSFaceGenKeyframeMultiple::~BSFaceGenKeyframeMultiple();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct KFX2
{
    virtual ~KFX2();
    virtual BS_FACEGEN_MORPH_TYPE GetType();
    virtual void s2();
    virtual float vfn_0c();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
};
struct KFXLoop
{
};

struct FUN_0064ec10_obj : public BSFaceGenKeyframe
{
    float* m_pfFaceGenValues;
    unsigned int m_uiFaceGenValueCount;
    FUN_0064ec10_obj(const FUN_0064ec10_obj& aOther);
    virtual ~FUN_0064ec10_obj();
};

// @fnv 0x0064ec10
FUN_0064ec10_obj::FUN_0064ec10_obj(const FUN_0064ec10_obj& aOther) : BSFaceGenKeyframe((BS_FACEGEN_MORPH_TYPE)-1)
{
    SetType(((KFX2*)&aOther)->GetType());
    SetTime(((KFX2*)&aOther)->vfn_0c());
    m_pfFaceGenValues = 0;
    m_uiFaceGenValueCount = 0;
    ((BSFaceGenKeyframeMultiple*)this)
        ->BSFaceGenKeyframeMultiple::ApplyFaceGenValues(((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((((OSGlobals*)&aOther)))->FUN_0044edb0())), true);
    for (unsigned int i = 0; i < m_uiFaceGenValueCount; i++)
        reinterpret_cast<::BSFaceGenKeyframeMultiple *>((((KFXLoop*)this)))->FUN_0064a4d0(i, reinterpret_cast<::Sd4e0 *>((((KFX2*)&aOther)))->FUN_005dd4e0(i));
}

namespace fnv_0064f5b0 {
struct KFThis
{
    virtual ~KFThis();
    virtual void s1();
    virtual bool SetType(BS_FACEGEN_MORPH_TYPE);
    virtual float vfn_0c();
    virtual bool vfn_10(float);
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void ApplyFaceGenValues(unsigned int, bool);
    char pad[0xc];
    unsigned int m_uiFaceGenValueCount;
    void CopyFromKeyframe(BSFaceGenKeyframe*);
};
struct KFX
{
    virtual ~KFX();
    virtual BS_FACEGEN_MORPH_TYPE GetType();
    virtual void s2();
    virtual float vfn_0c();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual bool IsMultiple();
};
struct KFXLoop
{
};

// @fnv 0x0064f5b0
void KFThis::CopyFromKeyframe(BSFaceGenKeyframe* apFrom)
{
    KFX* pSourceMultiple = apFrom && ((KFX*)apFrom)->IsMultiple() ? (KFX*)apFrom : 0;
    if (!pSourceMultiple)
        return;
    SetType(pSourceMultiple->GetType());
    vfn_10(pSourceMultiple->vfn_0c());
    ApplyFaceGenValues(((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((((OSGlobals*)pSourceMultiple)))->FUN_0044edb0())), true);
    for (unsigned int i = 0; i < m_uiFaceGenValueCount; i++)
        reinterpret_cast<::BSFaceGenKeyframeMultiple *>((((KFXLoop*)this)))->FUN_0064a4d0(i, reinterpret_cast<::Sd4e0 *>((pSourceMultiple))->FUN_005dd4e0(i));
}
}  // namespace fnv_0064f5b0

struct FUN_0064eab0_shell : BSFaceGenKeyframe
{
    void* DestroyKeyframe(unsigned int);
};
// Runs the BSFaceGenKeyframe destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x0064eab0
void* FUN_0064eab0_shell::DestroyKeyframe(unsigned int flags)
{
    reinterpret_cast<::FUN_0064eae0_shell *>((this))->SetVTable();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0064f530 {
struct FUN_0064ec10_obj
{
    char _vtable[4];
    char _m0[16];
    FUN_0064ec10_obj(const FUN_0064ec10_obj&);
};
struct FUN_0064f530_shell : FUN_0064ec10_obj
{
    FUN_0064ec10_obj* FUN_0064f530();
};
// Allocates a new FUN_0064ec10_obj by copying *this and returns the pointer.
// @fnv 0x0064f530
FUN_0064ec10_obj* FUN_0064f530_shell::FUN_0064f530()
{
    FUN_0064ec10_obj* preturn;
    preturn = new FUN_0064ec10_obj(*this);
    return preturn;
}
}  // namespace fnv_0064f530


struct FUN_0064f7e0_shell : public BSFaceGenKeyframeMultiple
{
    bool FUN_0064f7e0();
};

// Loops over the keyframes, calling the virtual at vtable slot 19; returns false if any keyframe is active and its value exceeds _gModifierZero, otherwise true.
// @fnv 0x0064f7e0
bool FUN_0064f7e0_shell::FUN_0064f7e0()
{
    unsigned int i;
    for (i = 0; i < m_uiFaceGenValueCount; ++i)
    {
        if (((bool(*)(void*, unsigned int))(*(void***)this)[19])(this, i) &&
            m_pfFaceGenValues[i] > ::_DAT_01012060)
            return false;
    }
    return true;
}

struct KFShell
{
    virtual ~KFShell();
    virtual unsigned int GetType();
    virtual void s2();
    virtual float GetAttributeStrength();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual bool IsValid();
    int eType;
    float fTime;
    float* m_pfFaceGenValues;
    unsigned int m_uiFaceGenValueCount;
    KFShell(const KFShell& aOther);
    bool AddToCompatibleList(struct KFList* apList);
};

struct KFList
{
    void AddTail(void* const& apItem);
};

// @fnv 0x0064ed60
bool KFShell::AddToCompatibleList(KFList* apList)
{
    if (!apList)
        return false;
    if (GetAttributeStrength() < 0.0)
        return false;
    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apList))->GetName())))
    {
        KFShell* pFirst = *((::KFShell **)(reinterpret_cast<::InventoryStackRecord *>((apList))->GetPayloadAddress()));
        KFShell* pValid = (pFirst && pFirst->IsValid()) ? pFirst : 0;
        if (!pValid || pValid->GetType() != GetType())
            return false;
    }
    KFShell* pCopy = new KFShell(*this);
    reinterpret_cast<::FUN_004ed8c0_shell *>((apList))->FUN_004ed8c0((int *)&(pCopy));
    return true;
}

struct BlendFrame
{
    virtual ~BlendFrame();
    virtual unsigned GetType();
    virtual bool SetType(unsigned);
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
    virtual bool IsValid();
    virtual void slot18();
    virtual bool IsQuantityInRange(unsigned);
    int type;
    float time;
    float* quantities;
    unsigned count;
    BlendFrame(const BlendFrame&);
    bool BlendWith(BlendFrame*, BlendFrame*, float);
};
// Blends this frame's quantities with frames a and b using weight clamped to [0,1], copying or interpolating per index, and returns the last SetQuantity result.
// @fnv 0x0064f0b0
bool BlendFrame::BlendWith(BlendFrame* apLeft, BlendFrame* apRight, float weight)
{
    BlendFrame* leftX = apLeft && apLeft->IsValid() ? apLeft : 0;
    BlendFrame* right3 = apRight && apRight->IsValid() ? apRight : 0;
    bool _deleteLeft = false;
    bool deleteRight = false;
    bool resultB = false;
    if (!leftX || !right3 || leftX == right3 || leftX->GetType() != right3->GetType())
        return false;
    if (leftX == this)
    {
        leftX = new BlendFrame(*this);
        _deleteLeft = true;
    }
    else if (right3 == this)
    {
        right3 = new BlendFrame(*this);
        deleteRight = true;
    }
    float blendA;
    if (weight < 0.0)
        blendA = 0.0f;
    else if (weight > 1.0)
        blendA = 1.0f;
    else
        blendA = weight;
    unsigned _maximum;
    if (((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((leftX))->FUN_0044edb0())) >= ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((right3))->FUN_0044edb0())))
        _maximum = ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((leftX))->FUN_0044edb0()));
    else
        _maximum = ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((right3))->FUN_0044edb0()));
    SetType(leftX->GetType());
    for (unsigned index = 0; index < count; ++index)
    {
        if (blendA == 0.0 || !right3->IsQuantityInRange(index))
        {
            if (leftX->IsQuantityInRange(index))
                resultB = reinterpret_cast<::BSFaceGenKeyframeMultiple *>(this)->FUN_0064a4d0(index, reinterpret_cast<::Sd4e0 *>((leftX))->FUN_005dd4e0(index));
        }
        else if (blendA == 1.0 || !leftX->IsQuantityInRange(index))
        {
            if (right3->IsQuantityInRange(index))
                resultB = reinterpret_cast<::BSFaceGenKeyframeMultiple *>(this)->FUN_0064a4d0(index, reinterpret_cast<::Sd4e0 *>((right3))->FUN_005dd4e0(index));
        }
        else if (leftX->IsQuantityInRange(index) && right3->IsQuantityInRange(index))
        {
            resultB =
                reinterpret_cast<::BSFaceGenKeyframeMultiple *>(this)->FUN_0064a4d0(index, reinterpret_cast<::Sd4e0 *>((leftX))->FUN_005dd4e0(index) * (1.0 - blendA) + blendA * reinterpret_cast<::Sd4e0 *>((right3))->FUN_005dd4e0(index));
        }
    }
    if (_deleteLeft)
    {
        delete leftX;
    }
    if (deleteRight)
    {
        delete right3;
    }
    return resultB;
}

namespace fnv_0064eea0 {
// 0x0064eea0  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, 4 stack args (ret 0x10): blends this keyframe loop toward another one
struct Vt0064eea0
{
    virtual void d0();
    virtual void* v04();
    virtual void d8();
    virtual void dc();
    virtual void d10();
    virtual void d14();
    virtual void d18();
    virtual void d1c();
    virtual void d20();
    virtual void d24();
    virtual void d28();
    virtual void d2c();
    virtual void d30();
    virtual void d34();
    virtual void d38();
    virtual void d3c();
    virtual void d40();
    virtual bool v44();
};

class MagicTarget;
struct Sh0044edb0
{
};
struct Sd4e0
{
};


struct KFXLoop
{
    virtual void d0();
    virtual void* v04();
    virtual void d8();
    virtual void dc();
    virtual void d10();
    virtual void d14();
    virtual void d18();
    virtual void d1c();
    virtual void d20();
    virtual void d24();
    virtual void d28();
    virtual void d2c();
    virtual void d30();
    virtual void d34();
    virtual void d38();
    virtual void d3c();
    virtual void d40();
    virtual bool v44();
    bool BlendFrom(Vt0064eea0* o, float f, bool b1, bool b2);
};

// @fnv 0x0064eea0
bool KFXLoop::BlendFrom(Vt0064eea0* pOther, float f, bool b1, bool b2)
{
    Vt0064eea0* pfOther = (pOther != 0 && pOther->v44()) ? pOther : 0;
    float fClamped;
    bool bChanged = false;

    if (pfOther == 0 || pfOther == (Vt0064eea0*)this || ((Vt0064eea0*)this)->v04() != pfOther->v04() ||
        ((::fnv_0064eea0::MagicTarget *)(reinterpret_cast<::MagicCaster_shell *>((((Sh0044edb0*)this)))->FUN_0044edb0())) != ((::fnv_0064eea0::MagicTarget *)(reinterpret_cast<::MagicCaster_shell *>((((Sh0044edb0*)pfOther)))->FUN_0044edb0())))
    {
        return false;
    }

    if (f < 0.0f)
    {
        fClamped = 0.0f;
    }
    else if (f > 1.0f)
    {
        fClamped = 1.0f;
    }
    else
    {
        fClamped = f;
    }

    for (unsigned int i = 0; i < *(unsigned int*)((char*)this + 0x10); ++i)
    {
        if (!b1 && ::FUN_0040eb10(reinterpret_cast<::Sd4e0 *>((((Sd4e0*)pfOther)))->FUN_005dd4e0(i), 0.0f, 0.001f))
        {
            continue;
        }
        if (reinterpret_cast<::Sd4e0 *>((((Sd4e0*)pfOther)))->FUN_005dd4e0(i) < 3.4028234663852886e38)
        {
            if (f < 1.0f && reinterpret_cast<::Sd4e0 *>((((Sd4e0*)this)))->FUN_005dd4e0(i) < 3.4028234663852886e38)
            {
                bChanged = bChanged | reinterpret_cast<::BSFaceGenKeyframeMultiple *>((this))->FUN_0064a4d0(i, reinterpret_cast<::Sd4e0 *>((((Sd4e0*)this)))->FUN_005dd4e0(i) * (1.0 - fClamped) +
                                                                reinterpret_cast<::Sd4e0 *>((((Sd4e0*)pfOther)))->FUN_005dd4e0(i) * fClamped);
            }
            else
            {
                bChanged = bChanged | reinterpret_cast<::BSFaceGenKeyframeMultiple *>((this))->FUN_0064a4d0(i, reinterpret_cast<::Sd4e0 *>((((Sd4e0*)pfOther)))->FUN_005dd4e0(i));
            }
        }
        else if (b2)
        {
            bChanged = bChanged | reinterpret_cast<::BSFaceGenKeyframeMultiple *>((this))->FUN_0064a4d0(i, 3.402823466e38f);
        }
    }
    return bChanged;
}
}  // namespace fnv_0064eea0

class xKF
{
  public:
    virtual void v0();
    virtual int GetType();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual bool IsCompatible(class xKF* p);
    virtual float GetScale();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool IsValidX();
    virtual void v18();
    virtual bool IsActive(unsigned int i);
    bool Interpolate(float fTime, xKF* pOther);
};

// For compatible inputs, moves active values toward pOther by a time-scaled step and returns true.
// @fnv 0x0064f900
bool xKF::Interpolate(float fTime, xKF* pOther)
{
    float qfTOqo;
    xKF* qsSDDgz = (pOther && pOther->IsValidX()) ? pOther : 0;
    float qrEZrs;
    bool qpqRa = false;
    unsigned int qSVM;
    if (fTime <= 0.0 || !qsSDDgz || qsSDDgz->GetType() != GetType() || ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((qsSDDgz))->FUN_0044edb0())) != ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())) ||
        !IsCompatible(qsSDDgz))
        return false;
    qfTOqo = (::FUN_0064fb10() + ::fnv_0064fb50::FUN_0064fb50() * pOther->GetScale()) * fTime;
    for (qSVM = 0; qSVM < ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>(this)->FUN_0044edb0())); qSVM++)
    {
        if (!IsActive(qSVM))
            continue;
        qrEZrs = reinterpret_cast<::Sd4e0 *>((qsSDDgz))->FUN_005dd4e0(qSVM) - reinterpret_cast<::Sd4e0 *>(this)->FUN_005dd4e0(qSVM);
        if (::FUN_00408860(qrEZrs) < qfTOqo)
            qpqRa |= reinterpret_cast<::BSFaceGenKeyframeMultiple *>(this)->FUN_0064a4d0(qSVM, reinterpret_cast<::Sd4e0 *>((qsSDDgz))->FUN_005dd4e0(qSVM));
        else if (qrEZrs < 0.0)
            qpqRa |= reinterpret_cast<::BSFaceGenKeyframeMultiple *>(this)->FUN_0064a4d0(qSVM, reinterpret_cast<::Sd4e0 *>(this)->FUN_005dd4e0(qSVM) - qfTOqo);
        else if (qrEZrs > 0.0)
            qpqRa |= reinterpret_cast<::BSFaceGenKeyframeMultiple *>(this)->FUN_0064a4d0(qSVM, reinterpret_cast<::Sd4e0 *>(this)->FUN_005dd4e0(qSVM) + qfTOqo);
    }
    return true;
}
