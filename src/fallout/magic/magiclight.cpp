
// src/fallout/magic/magiclight.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magiclight.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/B5Owner.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0080ed20_shell.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/S_0050de20_Class.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
struct FUN_0081c470_shell
{
    char pad0[0x10];
    float m_fFadeInTime;
    float m_fFadeOutTime;
    bool bFadeInActive;
    void FUN_0081c470(bool abIn, float afTime);
};

// @fnv 0x0081c470
void FUN_0081c470_shell::FUN_0081c470(bool abIn, float afTime)
{
    bFadeInActive = abIn;
    m_fFadeOutTime = afTime;
    m_fFadeInTime = 0.0f;
}

struct P3
{
    float x;
    float y;
    float z;

};

struct NiColor : public P3
{
    NiColor& operator*=(float fScale);
};

struct NiPointLight
{
public:
    void FUN_0050dd20(float);
};

struct GO
{
    NiPointLight* apTargetLight;
    unsigned int m_uiRefCount;

    operator unsigned int();
};

struct FUN_005e3fc0_shell
{
    unsigned int Get();
};


struct MagicEffectCollection
{
    void* pVTable;
    FUN_005e3fc0_shell* m_pFadeTarget;
    GO m_go;
    float m_fFadeInTime;
    float m_fFadeOutTime;
    bool bFadeInActive;

    void UpdateLightFade(float fTimeSinceScaleStart);
};

// @fnv 0x0081c320
void MagicEffectCollection::UpdateLightFade(float fTimeSinceScaleStart)
{
    float flightScale;
    unsigned int ucolor;
    NiColor color;

    if (m_pFadeTarget)
    {
        if (m_fFadeOutTime > _DAT_01012060)
        {
            m_fFadeInTime += fTimeSinceScaleStart;

            ucolor = m_pFadeTarget->Get();

            reinterpret_cast<::FUN_00416870_t *>(&(color))->FUN_00416870(static_cast<float>(static_cast<unsigned char>(ucolor & 0xff)),
                      static_cast<float>(static_cast<unsigned char>((static_cast<unsigned short>(ucolor) >> 8) & 0xff)),
                      static_cast<float>(static_cast<unsigned char>((ucolor >> 16) & 0xff)));

            if (bFadeInActive)
                flightScale = m_fFadeInTime / m_fFadeOutTime;
            else
                flightScale = 1.0f - m_fFadeInTime / m_fFadeOutTime;

            if (flightScale > 1.0)
            {
                m_fFadeOutTime = 0.0f;
                flightScale = 1.0f;
            }
            else if (flightScale < _DAT_01012060)
            {
                m_fFadeOutTime = 0.0f;
                flightScale = 0.0f;
            }

            reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiColor &)(color))->FUN_00439180(flightScale / 255.0);

            reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((reinterpret_cast<NiPointLight*>(m_go.operator unsigned int())))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(color));
        }

        reinterpret_cast<::S_0050de20_Class *>((m_pFadeTarget))->FUN_0050de20((::S_0050de20_A *)(::GO *)(&m_go), 0);
    }
}

class S4ee810
{
  public:
    S4ee810(int iValue);
    ~S4ee810();
    int unk00;
};

class PathingSolution;

template <class T> class PathingRef
{
  public:
    PathingRef();
    ~PathingRef();
    void Reset(void* p);
    T* m_pObject;
};

class FUN_0081bf80 : public S4ee810
{
  public:
    FUN_0081bf80(int a, intptr_t b);

    int m_iFadeIndex;
    PathingRef<PathingSolution> m_kSolution;
    float m_fScale;
    float m_fValue0;
    float m_fValue1;
    bool m_bDone;
};

class TESForm
{
  public:
    virtual ~TESForm();
};

class TESObjectLIGH : public TESForm
{
  public:
};


struct MLPoint3
{
    float x;
    float y;
    float z;

    MLPoint3(float afX, float afY, float afZ);
    MLPoint3& operator/=(float afScale);
};

struct MLPointLight
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;

    MLPointLight();
    void SetAttenuation(const MLPoint3& arAttenuation);
};

struct MLNode
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void AttachChildInAvailableSlot(MLPointLight* apChild, bool abFirstAvailable);
};

template <class T> struct MLPointer
{
    T* m_pObject;

    MLPointer& operator=(T* apObject);
    operator T*() const;
};

struct MLShadowSceneNode
{
};



struct MagicLightObject
{
    MLPointer<MLNode> m_pController;
    TESObjectLIGH* pLightForm;
    MLPointer<MLPointLight> m_pMenuLight;
    float fFadeAmount;

    void CreatePointLight(unsigned int auiFormID, MLNode* apNode);
};
// Initialises the base with 0, clears the solution reference, sets scale to 1.0, clears the done flag and values, then calls Init(a, b).
// @fnv 0x0081bf80
FUN_0081bf80::FUN_0081bf80(int a, intptr_t b) : S4ee810(0)
{
    m_iFadeIndex = 0;
    m_kSolution.Reset(0);
    m_fScale = 1.0f;
    m_bDone = false;
    m_fValue0 = 0.0f;
    m_fValue1 = 0.0f;
    reinterpret_cast<::MagicLightObject *>(this)->CreatePointLight(a, (::MLNode *)(b));
}

// @fnv 0x0081c030
void MagicLightObject::CreatePointLight(unsigned int auiFormID, MLNode* apNode)
{
    TESForm* pForm2 = ::FUN_004839c0(auiFormID);
    pLightForm = dynamic_cast<TESObjectLIGH*>(pForm2);
    if (pLightForm)
    {
        m_pMenuLight = new MLPointLight;
        fFadeAmount = 1.0f;
        unsigned int uiColor = reinterpret_cast<::FUN_005e3fc0_shell *>((pLightForm))->Get();
        MLPoint3 kDiffuseColor((unsigned char)(uiColor & 0xff), (unsigned char)(((unsigned short)uiColor >> 8) & 0xff),
                               (unsigned char)((uiColor >> 16) & 0xff));
        reinterpret_cast<::FUN_0080ed20_shell *>((void *)&(const ::MLPoint3 &)(kDiffuseColor))->DivideByScalar(255.0f);
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((MLPointLight*)m_pMenuLight)))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(kDiffuseColor));
        MLPoint3 kAttenuation(::DAT_01013d84, 0.0f, 0.0f);
        ((MLPointLight*)m_pMenuLight)->SetAttenuation(kAttenuation);
        reinterpret_cast<::NiPointLight *>((((MLPointLight*)m_pMenuLight)))->FUN_0050dd20(::GetFieldB4Float((char *)(pLightForm)));
        MLShadowSceneNode* pShadowNode5 = ((::MLShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
        if (pShadowNode5)
            reinterpret_cast<::fnv_00b5c940::SSNode *>((pShadowNode5))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(::MLPointLight *)(m_pMenuLight), true);
        m_pController = apNode;
        ((MLNode*)m_pController)->AttachChildInAvailableSlot(m_pMenuLight, true);
    }
}

template <class T> class NiPointer
{
  public:
    NiPointer(T* p);
    ~NiPointer();
    NiPointer& operator=(T* p);
    operator T*() const;
    T* operator->() const;
    T* m_pObject;
};
class NiNode;
class NiAVObject
{
  public:
    virtual void v000(), v004(), v008(), v00C(), v010(), v014(), v018(), v01C(), v020(), v024(), v028(), v02C(), v030(),
        v034(), v038(), v03C(), v040(), v044(), v048(), v04C(), v050(), v054(), v058(), v05C(), v060(), v064(), v068(),
        v06C(), v070(), v074(), v078(), v07C(), v080(), v084(), v088(), v08C(), v090(), v094(), v098(), v09C(), v0A0(),
        v0A4(), v0A8(), v0AC(), v0B0(), v0B4(), v0B8(), v0BC(), v0C0(), v0C4(), v0C8(), v0CC(), v0D0(), v0D4(), v0D8(),
        v0DC(), v0E0(), v0E4();
    virtual void VE8(NiNode* pNode);
};
class ShadowSceneNode
{
  public:
};
class FUN_00418f40 : public NiPointer<NiNode>
{
  public:
    ~FUN_00418f40();
    using NiPointer<NiNode>::operator=;
};
class FUN_0081c240
{
  public:
    NiPointer<NiAVObject> m_pReferencedObject;
    unsigned int m_uiValue1;
    FUN_00418f40 m_spNode;
    ~FUN_0081c240();
};
// Calls the referenced object's virtual method and the shadow scene node with m_spNode, then clears the members.
// @fnv 0x0081c240
FUN_0081c240::~FUN_0081c240()
{
    if (m_pReferencedObject)
        m_pReferencedObject->VE8(m_spNode);
    m_pReferencedObject = 0;
    ShadowSceneNode* pShadow = ::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
    if (pShadow)
        reinterpret_cast<::B5Owner *>((pShadow))->FUN_00b5eed0((std::uintptr_t)(m_spNode.m_pObject));
    m_spNode = 0;
    m_uiValue1 = 0;
}
