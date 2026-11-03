// fallout_shared/tesimagespacemodifier_decls.h: declares TimedAnimationKey, TimedFloatKey, RgbaColor, ColorAnimationKey, AlphaColor and more
#ifndef TESIMAGESPACEMODIFIER_DECLS_H
#define TESIMAGESPACEMODIFIER_DECLS_H

#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_0052ce20_shell.h"
#include "fnv/decl/FUN_0052cfc0_Class.h"
#include "fnv/decl/FUN_00b8af10_shell.h"
#include "fnv/decl/FUN_00b8af40_shell.h"
#include "fnv/decl/FUN_00b8af60_shell.h"
#include "fnv/decl/FUN_00b8af90_shell.h"
#include "fnv/decl/FUN_00b8afb0_shell.h"
#include "fnv/decl/FUN_00b8afe0_shell.h"
#include "fnv/decl/FUN_00b8b760_cls.h"
#include "fnv/decl/FUN_00b8cb30_cls.h"
#include "fnv/decl/FUN_00b8cc20_class.h"
#include "fnv/decl/fnv_00b8b8d0__ImageSpaceDistanceEffect.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_011c9000.h"
#include "TESForm.h"
#include "layout_support.h"
class NiAVObject;
class NiObjectNET;
class NiBound;
class ImageSpaceManager;
#include <malloc.h>
enum TESImageModifierChunks
{
    CHUNK_ID_SNAM_LOCAL_ID = 0x4d414e53,
    CHUNK_ID_BNAM_ID = 0x4d414e42,
    CHUNK_ID_DNAM_ID = 0x4d414e44,
    CHUNK_ID_RDSI_ID = 0x49534452,
    CHUNK_ID_RDSD_ID = 0x44534452,
    CHUNK_ID_RNAM_ID = 0x4d414e52,
    CHUNK_ID_TNAM_ID = 0x4d414e54,
    CHUNK_ID_UNAM_ID = 0x4d414e55,
    CHUNK_ID_VNAM_ID = 0x4d414e56,
    CHUNK_ID_WNAM_ID = 0x4d414e57
};
void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
template <int N> struct EndianSizeTag
{
};
class TimedAnimationKey
{
  public:
    float m_fTime;
};
class TimedFloatKey : public TimedAnimationKey
{
  public:
    float m_fValue;
    TimedFloatKey();
    ~TimedFloatKey();
};
class RgbaColor
{
  public:
    float r, g, b, a;
    RgbaColor(float, float, float, float);
    RgbaColor& FUN_005321d0(float);
};
class ColorAnimationKey
{
  public:
    float m_fTime;
    RgbaColor m_kRgbaColor;
};
class AlphaColor : public ColorAnimationKey
{
  public:
    AlphaColor();
    ~AlphaColor();
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2();
    NiPoint2(float, float);
    NiPoint2 operator*(float) const;
};
class NiFloatData;
class NiColorData;
class TESImageSpaceColorDataPointer
{
  public:
    NiColorData*& operator=(NiColorData*);
};
class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP = 0,
        LINKEY = 1
    };
};
class NiFloatInterpolator
{
  public:
    virtual ~NiFloatInterpolator();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual bool Update(float, NiObjectNET*, float&);
    unsigned int m_uiRefCount;
    float m_fLastTime, m_fFloatValue;
    NiFloatData* m_spFloatData;
    unsigned int m_uiLastKeyIndex;
    NiFloatInterpolator(NiFloatData* = 0);
    void SetAnimationKeys(TimedAnimationKey*, unsigned int, AnimationKey::KeyType);
};
class NiColorInterpolator
{
  public:
    virtual ~NiColorInterpolator();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual bool Update(float, NiObjectNET*, RgbaColor&);
    unsigned int m_uiRefCount;
    float m_fLastTime;
    RgbaColor m_kColorValue;
    NiColorData* m_spColorData;
    unsigned int m_uiLastKeyIndex;
    NiColorInterpolator(NiColorData* = 0);
    void SetColorData(NiColorData*);
    void SetAnimationKeys(ColorAnimationKey*, unsigned int, AnimationKey::KeyType);
};
class TESImageSpaceModifier : public TESForm
{
  public:
    class ImageSpaceModifierEffectData
    {
      public:
        bool m_bOverride;
        float fDuration;
        unsigned int m_auiKeyframeCountsByTypeAndChannel[21][2];
        unsigned int m_uiEffectEntryCountFirst, m_uiEffectEntryCountSecond, m_uiEffectEntryCountThird,
            m_uiEffectEntryCountFourth, m_uiEffectEntryCountFifth, m_uiEffectEntryCountSixth;
        bool m_bUseRadialBlur;
        NiPoint2 m_kRadialBlurCenter;
        unsigned int m_uiEffectEntryCountSeventh, m_uiEffectEntryCountEighth, m_uiEffectEntryCountNinth;
        bool m_bUseEffectEntries;
        unsigned char m_ucEffectMode;
        unsigned int m_uiEffectEntryCountTenth, m_uiEffectEntryCountEleventh, m_uiEffectEntryCountTwelfth,
            m_uiEffectEntryCountThirteenth;
        ImageSpaceModifierEffectData();
    };
    TESSound* pOutroSound;
    TESSound* pIntroSound;
    ImageSpaceModifierEffectData Data;
    NiFloatInterpolator m_akFloatInterpolators[21][2];
    NiFloatInterpolator m_kFloatInterpolatorOne, m_kFloatInterpolatorTwo;
    NiColorInterpolator m_kColorInterpolatorOne, m_kColorInterpolatorTwo;
    NiFloatInterpolator m_kFloatInterpolatorNine, m_kFloatInterpolatorTen, m_kFloatInterpolatorEleven,
        m_kFloatInterpolatorThree, m_kFloatInterpolatorFour;
    NiFloatInterpolator m_kFloatInterpolatorFive, m_kFloatInterpolatorSix, m_kFloatInterpolatorSeven,
        m_kFloatInterpolatorEight;
    TimedFloatKey* pEffectEntryTable[21][2];
    TimedFloatKey *pSecondEffectEntries, *pThirdEffectEntries;
    AlphaColor *pFirstEffectRecordArray, *pSecondEffectRecordArray;
    TimedFloatKey *pTenthEffectEntries, *pEleventhEffectEntries, *pTwelfthEffectEntries, *pFourthEffectEntries,
        *pFifthEffectEntries;
    TimedFloatKey *pSeventhEffectEntries, *pEighthEffectEntries, *pNinthEffectEntries, *pSixthEffectEntries;
    TESImageSpaceModifier();
    void ResetFormData();
    virtual bool Load(TESFile*);
    virtual void ClearData();
    virtual void InitItem();
    void Apply(float, float, NiAVObject*);
    void EvaluateInterpolators(float, float);
    bool IsExpired(float);
    void InitializeModifierData();
};
FNV_STATIC_ASSERT(sizeof(TESImageSpaceModifier::ImageSpaceModifierEffectData) == 0xf4);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, m_akFloatInterpolators) == 0x114);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifier, pEffectEntryTable) == 0x654);
extern float DAT_0118aba0[2];
extern float DAT_0118aba8[2];

extern float DAT_011c96fc;
void FUN_005330e0(float&, float, float);
class NiPoint2;
class RgbaColor;
class ImageSpaceManager
{
  public:
    static ImageSpaceManager* FUN_004e3270();
    void SetRadialBlurParameters(float, float, float, float, float, const NiPoint2&);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
public:
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
public:
    void ApplyTintColorParamModifier(::RgbaColor &);
public:
    void ApplyTintColorParamModifierWeather(::RgbaColor &);
public:
    void SetFadeColorParamModifier(::RgbaColor &);
public:
    void ApplyFadeColorParamModifierWeather(::RgbaColor &);
public:
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, const ::NiPoint2 &);
};
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void UpdateWorldBound();
};

class TESSound : public TESForm
{
};
#endif
