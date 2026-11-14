// Keeps the NiPointer of layout_support.h, which gives every member a body: on
// fnv/ni_pointer.h this unit does not compile. It uses the constructor from T*,
// the destructor, the conversion to T*, operator->, the copy assignment and
// operator=(T*).
#define FNV_KEEPS_OWN_NIPOINTER
// gamebryo2.2/corelibs/nianimation/nicolorinterpolator.cpp: NiColorInterpolator (17 functions)

#include <cstdint>
#include "fnv/symbols_00aa1000.h"
#include <windows.h>
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a4cc0_shell.h"
#include "fnv/decl/FUN_00a3ca10.h"
#include "fnv/decl/FUN_00a3d270_cls.h"
#include "fnv/decl/FUN_00a698a0_class.h"
#include "fnv/decl/FUN_00a95ca0_shell.h"
#include "fnv/decl/NiColorDataHack.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_004a4c90__FUN_004a4c90_shell.h"
#include "fnv/decl/fnv_00a3cbf0__NiKeyBasedInterpolator.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a57000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f3000.h"
#include "NiObject.h"

struct NiObjectNET;
struct NiStream;
struct RgbaColor
{
  public:
    RgbaColor()
    {}
    float r, g, b, a;
public:
    char *ToString(const char *);
public:
    void LoadBinary(::NiStream &);
};

class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY,
        NUMKEYTYPES
    };
    float m_fTime;
};
class ColorAnimationKey : public AnimationKey
{
  public:
    RgbaColor m_kRgbaColor;
};
class NiColorData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    ColorAnimationKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
};
class NiInterpolator : public NiObject
{
  public:
    float m_fLastTime;
};
class NiKeyBasedInterpolator : public NiInterpolator
{
  public:
    NiKeyBasedInterpolator();
};
class NiColorInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiColorInterpolator(NiColorData*);
    virtual ~NiColorInterpolator();
    virtual bool Update(float, NiObjectNET*, RgbaColor&);
    RgbaColor m_kColorValue;
    NiPointer<NiColorData> m_spColorData;
    unsigned int m_uiLastKeyIndex;
};

// @fnv 0x00a3bfb0
bool NiColorInterpolator::Update(float fTime, NiObjectNET*, RgbaColor& kValue)
{
    if (m_fLastTime == fTime)
    {
        kValue = m_kColorValue;
        if (reinterpret_cast<::FUN_004a4cc0_shell *>((void *)&(m_kColorValue))->FUN_004a4cc0((void *)&(DAT_011a9430)))
            return false;
        return true;
    }

    if (m_spColorData.m_pObject)
    {
        unsigned int uiNumKeys = m_spColorData.m_pObject->m_uiNumKeys;
        AnimationKey::KeyType eType = m_spColorData.m_pObject->m_eRequestType;
        unsigned char ucKeySize = m_spColorData.m_pObject->m_ucKeyDataSize;
        ColorAnimationKey* pkKeys = m_spColorData.m_pObject->m_pKeyArray;
        if (uiNumKeys > 0)
            m_kColorValue =
                ::InterpolateColor(fTime, (const char *)(pkKeys), (*(unsigned int *)&(eType)), uiNumKeys, (unsigned int *)&(m_uiLastKeyIndex), ucKeySize);
    }

    if (reinterpret_cast<::FUN_004a4cc0_shell *>((void *)&(m_kColorValue))->FUN_004a4cc0((void *)&(DAT_011a9430)))
        return false;
    kValue = m_kColorValue;
    m_fLastTime = fTime;
    return true;
}

namespace fnv_00a3bd10 {
class NiKeyBasedInterpolator
{
  public:
    NiKeyBasedInterpolator();
};

struct RgbaColor
{
    float r, g, b, a;
};

extern int DAT_011a9434;
extern int DAT_011a9438;
extern int DAT_011a943c;


// @fnv 0x00a3bd10
NiColorInterpolator* NiColorInterpolatorConstructor(NiColorInterpolator* pThis, int, void* pkColorData)
{
    new ((void *)(reinterpret_cast<NiKeyBasedInterpolator*>(pThis))) ::FUN_00a3ca10();
    *reinterpret_cast<int**>(pThis) = &::DAT_01096e14;
    *reinterpret_cast<RgbaColor*>(reinterpret_cast<char*>(pThis) + 0x0c) = (*reinterpret_cast<const ::fnv_00a3bd10::RgbaColor *>((void *)&::DAT_011a9430));
    *reinterpret_cast<void**>(&pThis->m_spColorData.m_pObject) = pkColorData;
    if (pkColorData)
    {
        InterlockedIncrement(reinterpret_cast<long*>(reinterpret_cast<char*>(pkColorData) + 4));
    }
    pThis->m_uiLastKeyIndex = 0;
    return pThis;
}
}  // namespace fnv_00a3bd10

struct FUN_00a3bd70_shell : public NiColorInterpolator
{
    void* FUN_00a3bd70();
};


// @fnv 0x00a3bd70
void* FUN_00a3bd70_shell::FUN_00a3bd70()
{
    return &(*reinterpret_cast<void * *>(&::g_011f3730));
}

struct FUN_00a487f0_shell
{
    void* GetNestedPointer(void* arg);
};

// @fnv 0x00a487f0
void* FUN_00a487f0_shell::GetNestedPointer(void* apUnused)
{
    void* ptr = *(void**)((char*)this + 0x1c);
    if (!ptr)
        return 0;
    return *(void**)((char*)ptr + 0xc);
}

struct FUN_00a3bc60_shell : public NiKeyBasedInterpolator
{
    RgbaColor m_kColorValue;
    NiPointer<NiColorData> m_spColorData;
    void SetColorValue(RgbaColor);
};
// Clears m_spColorData and stores the given color value in m_kColorValue.
// @fnv 0x00a3bc60
void FUN_00a3bc60_shell::SetColorValue(RgbaColor akColorValue)
{
    m_spColorData = 0;
    m_kColorValue = akColorValue;
}

struct DummyA3D0E0
{
};
struct HostA3BCB0 : NiColorInterpolator
{
    void FUN_00a3bcb0(float, float);
};
// If m_spColorData is set, forwards the two float arguments to its FUN_00a3d0e0 method.
// @fnv 0x00a3bcb0
void HostA3BCB0::FUN_00a3bcb0(float afArg1, float afArg2)
{
    if ((NiColorData*)m_spColorData)
        reinterpret_cast<::NiColorDataHack *>((((DummyA3D0E0*)(NiColorData*)m_spColorData)))->FUN_00a3d0e0(afArg1, afArg2);
}

struct NiObject;
struct NiStream
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void Func12(NiColorData*);
public:
    ::NiObject *DeserializeObject();
};
struct FUN_00a95ca0_helper
{
};
struct NiColorA_SaveHelper
{
};
struct FUN_00a3bce0_shell : NiColorInterpolator
{
    void FUN_00a3bce0(NiStream&);
};
// @fnv 0x00a3bce0
void FUN_00a3bce0_shell::FUN_00a3bce0(NiStream& kStream)
{
    reinterpret_cast<::FUN_00a95ca0_shell *>((((FUN_00a95ca0_helper*)this)))->FUN_00a95ca0((*(::S_00a58160_Stream *)(&kStream)));
    reinterpret_cast<::FUN_00a698a0_class *>((((NiColorA_SaveHelper*)&m_kColorValue)))->FUN_00a698a0(&kStream);
    kStream.Func12(m_spColorData.m_pObject);
}

struct NiKeyBasedInterpolatorHelper : public NiKeyBasedInterpolator
{
    NiKeyBasedInterpolatorHelper();
};
struct BSFadeNode : public NiKeyBasedInterpolatorHelper
{
    const void* m_ppVirtualMethodTable;
    RgbaColor m_kColorValue;
    NiPointer<NiColorData> m_spColorData;
    unsigned int m_uiLastKeyIndex;
};
extern int DAT_011a9434;
extern int DAT_011a9438;
extern int DAT_011a943c;
// @fnv 0x00a3c130
BSFadeNode* FUN_00a3c130()
{
    BSFadeNode* p = (BSFadeNode*)::operator new(0x24);
    if (p)
    {
        new ((void *)(p)) ::FUN_00a3ca10();
        *(uintptr_t*)p = (uintptr_t)&DAT_01096e14;
        *(unsigned int*)((char*)p + 0xc) = *(unsigned int*)&DAT_011a9430;
        *(unsigned int*)&p->m_kColorValue.r = DAT_011a9434;
        *(unsigned int*)&p->m_kColorValue.g = DAT_011a9438;
        *(unsigned int*)&p->m_kColorValue.b = DAT_011a943c;
        *(unsigned int*)&p->m_kColorValue.a = 0;
        *(unsigned int*)((char*)p + 0x20) = 0;
    }
    else
    {
        p = 0;
    }
    return p;
}

namespace fnv_00a48990 {
struct NiStream
{
};
struct NiColorA_Helper
{
};
struct NiKeyBasedInterpolator_LoadBinary_Helper
{
    virtual void LoadBinary(NiStream&);
};
struct FUN_00a48990_StandIn : NiKeyBasedInterpolator
{
    RgbaColor m_kColorValue;
    NiPointer<NiColorData> m_spColorData;
    void FUN_00a48990(NiStream&);
};
// Loads the base interpolator and color value from the stream, then stores the stream's next object as the color data pointer.
// @fnv 0x00a48990
void FUN_00a48990_StandIn::FUN_00a48990(NiStream& kStream)
{
    ::FUN_00aa0ac0();
    reinterpret_cast<::RgbaColor *>((((NiColorA_Helper*)&m_kColorValue)))->LoadBinary((::NiStream &)(kStream));
    m_spColorData = (NiColorData*)reinterpret_cast<::NiStream *>(&(kStream))->DeserializeObject();
}
}  // namespace fnv_00a48990

struct NiStream;
struct HC1Base
{
    bool FUN_00aa0ad0(NiStream*);
};
struct RegStreamable
{
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual bool RegisterStreamables(NiStream*) = 0;
};
struct FUN_00a489f0_StandIn : NiColorInterpolator
{
    bool FUN_00a489f0(NiStream*);
};
// @fnv 0x00a489f0
bool FUN_00a489f0_StandIn::FUN_00a489f0(NiStream* pkStream)
{
    if (!((HC1Base*)this)->FUN_00aa0ad0(pkStream))
        return false;
    NiColorData* pkColorData = m_spColorData.m_pObject;
    if (pkColorData)
        ((RegStreamable*)pkColorData)->RegisterStreamables(pkStream);
    return true;
}

struct NiObjectNET;
class NiColorData;

struct ColorValueWords
{
    unsigned int m_uiColorR;
    unsigned int m_uiColorG;
    unsigned int m_uiColorB;
    unsigned int m_uiColorA;

    ColorValueWords(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
    {
        *(volatile unsigned int*)&m_uiColorR = r;
        *(volatile unsigned int*)&m_uiColorG = g;
        *(volatile unsigned int*)&m_uiColorB = b;
        *(volatile unsigned int*)&m_uiColorA = a;
    }
};

struct FUN_00a3bd80 : public NiKeyBasedInterpolator, public ColorValueWords
{
    NiPointer<NiColorData> m_spColorData;
    unsigned int m_uiLastKeyIndex;

    FUN_00a3bd80(unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    virtual ~FUN_00a3bd80();
    virtual bool Update(float, NiObjectNET*, float*);
};

// Constructs a color interpolator, initializing the base interpolator, the RGBA color words, an empty color data pointer and a zeroed field.
// @fnv 0x00a3bd80
FUN_00a3bd80::FUN_00a3bd80(unsigned int auiColorR, unsigned int auiColorG, unsigned int auiColorB,
                           unsigned int auiColorA)
    : NiKeyBasedInterpolator(), ColorValueWords(auiColorR, auiColorG, auiColorB, auiColorA), m_spColorData(),
      m_uiLastKeyIndex(0)
{}

struct ColorCmp
{
    float r, g, b, a;
};

inline ColorAnimationKey* ComputePositionAtTime(NiColorData* d, unsigned int& n, AnimationKey::KeyType& t,
                                                unsigned char& s)
{
    n = d->m_uiNumKeys;
    t = d->m_eRequestType;
    s = d->m_ucKeyDataSize;
    return d->m_pKeyArray;
}

struct HostA3BDC0 : NiColorInterpolator
{
    void CollapseConstantColorKeys();
};

// If the color data has zero or one key, or all keys are equal for linear/step interpolation, clears m_spColorData and stores the single color value.
// @fnv 0x00a3bdc0
void HostA3BDC0::CollapseConstantColorKeys()
{
    if (m_spColorData)
    {
        unsigned int uiNumKeys;
        AnimationKey::KeyType eType;
        unsigned char ucKeySize;
        ColorAnimationKey* pkKeys = ComputePositionAtTime(m_spColorData, uiNumKeys, eType, ucKeySize);
        if (uiNumKeys == 0)
        {
            m_spColorData = 0;
            m_kColorValue = DAT_011a9430;
        }
        else
        {
            RgbaColor kValue = pkKeys->m_kRgbaColor;
            if (uiNumKeys != 1)
            {
                bool bAllEqual = false;
                if (eType == AnimationKey::LINKEY || eType == AnimationKey::STEPKEY)
                {
                    bAllEqual = true;
                    for (unsigned int uiIndex = 1; bAllEqual && uiIndex < uiNumKeys; uiIndex++)
                    {
                        ColorAnimationKey* pkKey = (ColorAnimationKey*)((char*)pkKeys + uiIndex * ucKeySize);
                        if (reinterpret_cast<::fnv_004a4c90::FUN_004a4c90_shell *>((void *)(((ColorCmp*)&pkKey->m_kRgbaColor)))->FUN_004a4c90((void *)&(kValue)))
                            bAllEqual = false;
                    }
                }
                if (!bAllEqual)
                    return;
            }
            m_spColorData = 0;
            m_kColorValue = kValue;
        }
    }
}

struct FUN_00a57050_helper
{
};
struct FUN_00a3d270_helper : NiColorData
{
};
struct FUN_00a3bef0_shell : NiColorInterpolator
{
    NiColorInterpolator* CreateClippedInterpolator(float startTime, float endTime);
};
// Creates a color interpolator for the given time range and, if color data exists, clips it and assigns the clipped data to the new interpolator.
// @fnv 0x00a3bef0
NiColorInterpolator* FUN_00a3bef0_shell::CreateClippedInterpolator(float startTime, float endTime)
{
    NiColorInterpolator* interpolator = ((::NiColorInterpolator *)(::FUN_00a57050((intptr_t)(reinterpret_cast<FUN_00a57050_helper*>(this)), startTime)));
    if (m_spColorData.m_pObject)
    {
        NiColorData* clippedData = 0;
        reinterpret_cast<::FUN_00a3d270_cls *>((reinterpret_cast<FUN_00a3d270_helper*>(m_spColorData.m_pObject)))->BuildAndSetData(startTime, endTime, (*(::NiPointerD27< ::NiDataD27> *)(&clippedData)));
        interpolator->m_spColorData = clippedData;
        interpolator->m_uiLastKeyIndex = 0;
        if (clippedData)
            clippedData->DecRefCount();
    }
    return interpolator;
}

struct FUN_00a3c0a0_shell : NiColorInterpolator
{
    void FUN_00a3c0a0(FUN_00a3c0a0_shell* dst, void* proc);
};
// @fnv 0x00a3c0a0
void FUN_00a3c0a0_shell::FUN_00a3c0a0(FUN_00a3c0a0_shell* apDest, void* proc)
{
    ::FUN_00aa0ab0();
    unsigned int* d4 = (unsigned int*)&apDest->m_kColorValue;
    unsigned int* s4 = (unsigned int*)&m_kColorValue;
    d4[0] = s4[0];
    d4[1] = s4[1];
    d4[2] = s4[2];
    d4[3] = s4[3];
    apDest->m_spColorData = m_spColorData;
    apDest->m_uiLastKeyIndex = m_uiLastKeyIndex;
}

struct ViewerArray
{
    void* m_pBase;
    unsigned int m_unk04;
    unsigned short m_usMax;
    unsigned short m_usNext;
    unsigned short m_unk0c;
    unsigned short m_usGrow;
};

struct ViewerNameHolder
{
    unsigned int m_unk00;
};


struct FUN_00a3c270_cls
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    ViewerNameHolder m_nameA;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_uiFilterValue;
    void AppendColorProperties(ViewerArray* out);
};

// @fnv 0x00a3c270
void FUN_00a3c270_cls::AppendColorProperties(ViewerArray* out)
{
    reinterpret_cast<::fnv_00a3cbf0::NiKeyBasedInterpolator *>((this))->FUN_00a3cbf0((::fnv_00a3cbf0::StrArr *)(out));
    void* pValue = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_011f3730))))));
    unsigned int uiIndex = out->m_usNext;
    if (uiIndex >= out->m_usMax)
    {
        reinterpret_cast<::ViewerStrings *>((out))->SetSize(uiIndex + out->m_usGrow);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((out))->SetAt(uiIndex, (*(char * *)(&pValue)));

    void* r = ((void *)(reinterpret_cast<::RgbaColor *>(&(m_nameA))->ToString("m_kColorValue")));
    uiIndex = out->m_usNext;
    unsigned int uiMax = out->m_usMax;
    pValue = r;
    if (uiIndex >= uiMax)
    {
        reinterpret_cast<::ViewerStrings *>((out))->SetSize(uiIndex + out->m_usGrow);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((out))->SetAt(uiIndex, (*(char * *)(&pValue)));

    uintptr_t v = m_uiFilterValue;
    void* s = ((void *)(::FUN_00a7d5a0("m_spColorData", (void *)(v))));
    uiIndex = out->m_usNext;
    uiMax = out->m_usMax;
    pValue = s;
    if (uiIndex >= uiMax)
    {
        reinterpret_cast<::ViewerStrings *>((out))->SetSize(uiIndex + out->m_usGrow);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((out))->SetAt(uiIndex, (*(char * *)(&pValue)));
}

inline NiColorInterpolator::NiColorInterpolator(NiColorData* data)
    : m_kColorValue(DAT_011a9430), m_spColorData(data), m_uiLastKeyIndex(0)
{}
struct Owner488
{
    NiColorInterpolator* CreateColorInterpolator(intptr_t);
};
// Allocates a NiColorInterpolator with null color data, initializes it via FUN_00a3c0a0 with arg, and returns it.
// @fnv 0x00a3c1f0
NiColorInterpolator* Owner488::CreateColorInterpolator(intptr_t arg)
{
    void* memory = FUN_00aa13e0(sizeof(NiColorInterpolator));
    NiColorInterpolator* interpolator = memory ? new (memory) NiColorInterpolator(0) : 0;
    reinterpret_cast<::FUN_00a3c0a0_shell *>(this)->FUN_00a3c0a0((::FUN_00a3c0a0_shell *)(interpolator), (void *)(arg));
    return interpolator;
}

class NiColorA3C;

class NiObjA3C
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
    virtual bool IsEqual(NiObjA3C* pkObject);
    unsigned int m_uiRefCount;

    bool FUN_00c85800(NiObjA3C* pkObject);
};

class NiColorA3C
{
  public:
    float r, g, b, a;
};

class FUN_00a3c190_C : public NiObjA3C
{
  public:
    float m_fLastTime;
    NiColorA3C m_kColorValue;
    NiPointer<NiObjA3C> m_spColorData;

    bool FUN_00a3c190(NiObjA3C* pkObject);
};

// Returns false when the base check, color check, or color-data check fails; otherwise returns true.
// @fnv 0x00a3c190
bool FUN_00a3c190_C::FUN_00a3c190(NiObjA3C* pkObject)
{
    if (!FUN_00c85800(pkObject))
        return false;

    FUN_00a3c190_C* pkDest = (FUN_00a3c190_C*)pkObject;
    if (reinterpret_cast<::fnv_004a4c90::FUN_004a4c90_shell *>((void *)&(m_kColorValue))->FUN_004a4c90((void *)&(pkDest->m_kColorValue)))
        return false;

    if ((m_spColorData && !pkDest->m_spColorData) || (!m_spColorData && pkDest->m_spColorData) ||
        (m_spColorData && !m_spColorData->IsEqual(pkDest->m_spColorData)))
        return false;

    return true;
}
