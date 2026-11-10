// fallout_shared/sky/moon.cpp: Moon, TaskQueueInterface (11 functions)

#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00456630_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_00633ba0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/SkyShaderProperty.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00966000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_011de000.h"
#include "moon_types.h"
#include "fnv/decl/F940Owner.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_00bb0180_shell.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/fnv_00439390__NiObjectNET.h"
#include "fnv/symbols_00aa1000.h"

// @fnv 0x006366d0
float Moon::GetMoonVisibility()
{
    float fadeStart = 180.0 - m_fFadeStartAngle;
    float fadeEnd = 180.0 - m_fFadeEndAngle;
    if (fPos > 180.0)
        return 0.0f;
    else if (fPos <= m_fFadeStartAngle && fPos >= m_fFadeEndAngle)
        return (fPos - m_fFadeEndAngle) / (m_fFadeStartAngle - m_fFadeEndAngle);
    else if (fPos >= fadeStart && fPos <= fadeEnd)
        return (fadeEnd - fPos) / (fadeEnd - fadeStart);
    else if (fPos > m_fFadeStartAngle && fPos < fadeStart)
        return 1.0f;
    else
        return 0.0f;
}

// Returns a 0..1 visibility factor from fPos using start/end fade angles and their 180-degree mirrored late angles.
// @fnv 0x006367e0
float Moon::GetMoonShadowVisibility()
{
    struct FadeAngles
    {
        float start;
        float lateStart;
        float end;
        float lateEnd;
    } fadeAngles;
    fadeAngles.start = m_fFadeEndAngle;
    fadeAngles.end = m_fFadeEndAngle - m_fFadeAngleRange;
    fadeAngles.lateStart = 180.0 - fadeAngles.start;
    fadeAngles.lateEnd = 180.0 - fadeAngles.end;
    if (fPos > 180.0)
        return 0.0f;
    else if (fPos <= fadeAngles.start && fPos >= fadeAngles.end)
        return (fPos - fadeAngles.end) / (fadeAngles.start - fadeAngles.end);
    else if (fPos >= fadeAngles.lateStart && fPos <= fadeAngles.lateEnd)
        return (fadeAngles.lateEnd - fPos) / (fadeAngles.lateEnd - fadeAngles.lateStart);
    else if (fPos > fadeAngles.start && fPos < fadeAngles.lateStart)
        return 1.0f;
    else
        return 0.0f;
}

struct TaskQueueInterface
{
  public:
    void FUN_004902f0(bool);
    void FUN_00635fe0(bool bDisplay);
public:
    void QueueActorDisarm(bool);
};

// @fnv 0x00635fe0
void TaskQueueInterface::FUN_00635fe0(bool bDisplay)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(bDisplay, 0x20);
}

class Flag512Receiver
{
  public:
    void FUN_00636000(bool enabled);
};

// @fnv 0x00636000
void Flag512Receiver::FUN_00636000(bool enabled)
{
    reinterpret_cast<::FUN_00633ba0_Class *>(this)->FUN_00633ba0(enabled, 0x2000);
}

struct Calendar
{
    unsigned int GetGameDaysPassed(void);
};
extern unsigned int DAT_011cca80;
unsigned int FUN_00636980(void*);

// @fnv 0x006368f0
bool __cdecl FUN_006368f0(const Sky* apSky)
{
    if (((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(apSky))->FUN_0084e3a0())) && FUN_00636980(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(apSky))->FUN_0084e3a0()))))
    {
        unsigned int eNewPhase = ((*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameDaysPassed() % (FUN_00636980(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(apSky))->FUN_0084e3a0()))) * 8)) /
                                 FUN_00636980(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(apSky))->FUN_0084e3a0())));
        if (eNewPhase != DAT_011cca80)
        {
            DAT_011cca80 = eNewPhase;
            return true;
        }
    }
    return false;
}

struct FUN_00636980_Helper
{
    char pad[0x55];
    unsigned char f55;
    unsigned char FUN_00636980();
};

// @fnv 0x00636980
unsigned char FUN_00636980_Helper::FUN_00636980()
{
    return f55 & ~0xc0;
}

struct FUN_00456630_helper
{
};

struct FUN_006366b0_shell
{
    bool FUN_006366b0();
};

// @fnv 0x006366b0
bool FUN_006366b0_shell::FUN_006366b0()
{
    return ((bool)(reinterpret_cast<::FUN_00456630_Class *>((((FUN_00456630_helper*)this)))->FUN_00456630(0x20)));
}

struct S00634cb0
{
    void FUN_00634ce0();
    void* DestroyIfFlagged(unsigned int);
};
class NiNode
{
  public:
    virtual void Vfn00();
    virtual void Vfn04();
    virtual void Vfn08();
    virtual void Vfn0C();
    virtual void Vfn10();
    virtual void Vfn14();
    virtual void Vfn18();
    virtual void Vfn1C();
    virtual void Vfn20();
    virtual void Vfn24();
    virtual void Vfn28();
    virtual void Vfn2C();
    virtual void Vfn30();
    virtual void Vfn34();
    virtual void Vfn38();
    virtual void Vfn3C();
    virtual void Vfn40();
    virtual void Vfn44();
    virtual void Vfn48();
    virtual void Vfn4C();
    virtual void Vfn50();
    virtual void Vfn54();
    virtual void Vfn58();
    virtual void Vfn5C();
    virtual void Vfn60();
    virtual void Vfn64();
    virtual void Vfn68();
    virtual void Vfn6C();
    virtual void Vfn70();
    virtual void Vfn74();
    virtual void Vfn78();
    virtual void Vfn7C();
    virtual void Vfn80();
    virtual void Vfn84();
    virtual void Vfn88();
    virtual void Vfn8C();
    virtual void Vfn90();
    virtual void Vfn94();
    virtual void Vfn98();
    virtual void Vfn9C();
    virtual void VfnA0();
    virtual void VfnA4();
    virtual void VfnA8();
    virtual void VfnAC();
    virtual void VfnB0();
    virtual void VfnB4();
    virtual void VfnB8();
    virtual void VfnBC();
    virtual void VfnC0();
    virtual void VfnC4();
    virtual void VfnC8();
    virtual void VfnCC();
    virtual void VfnD0();
    virtual void VfnD4();
    virtual void VfnD8();
    virtual void VfnDC();
    virtual void VfnE0();
    virtual void VfnE4();
    virtual void DetachChildAlt(NiNode* child);
};

class FUN_00634ce0 : public SkyObject
{
  public:
    virtual ~FUN_00634ce0();
    NiPointer<NiNode> m_pMoonNode;
    NiPointer<NiNode> m_pMoonShadowNode;
    NiPointer<NiTriShape> m_pMoonShape;
    NiPointer<NiTriShape> m_pMoonShadowShape;
    BSStringT<char> m_kMoonTexturePaths[8];
    float m_fFadeStartAngle;
    float m_fFadeEndAngle;
    float m_fFadeAngleRange;
    float fSpeed;
    float m_fGlyphVerticalOffset;
    unsigned int iSize;
    int m_eUpdateStatus;
    float fPos;
    float m_fValue;
};
// Calls FUN_00634ce0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00634cb0
void* S00634cb0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00634ce0 *>(this)->FUN_00634ce0::~FUN_00634ce0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Clears the four NiPointer members, detaches the node from its parent if it has one, then clears the node pointer.
// @fnv 0x00634ce0
FUN_00634ce0::~FUN_00634ce0()
{
    m_pMoonShadowShape = 0;
    m_pMoonShape = 0;
    m_pMoonShadowNode = 0;
    m_pMoonNode = 0;
    if (((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((m_pRootNode).operator->()))->FUN_009611e0())))
    {
        ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((m_pRootNode).operator->()))->FUN_009611e0()))->DetachChildAlt(m_pRootNode);
    }
    m_pRootNode = 0;
}

// 0x00634a70  /MT /Od /Oy- /GS /EHsc /Gy /GF  thiscall ctor, 7 args (ret 0x1c)
// Moon::Moon(name, fadeStart, fadeEnd, shadowEarlyFade, speed, zOffset, size)

struct FUN_00406f90_this;

class FUN_00634a70 : public SkyObject
{
  public:
    FUN_00634a70(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade, float speed, float zOffset,
                 unsigned int size);
    virtual ~FUN_00634a70();
    NiPointer<NiNode> m_pMoonNode;
    NiPointer<NiNode> m_pMoonShadowNode;
    NiPointer<NiTriShape> m_pMoonShape;
    NiPointer<NiTriShape> m_pMoonShadowShape;
    BSStringT<char> m_kMoonTexturePaths[8];
    float m_fFadeStartAngle;
    float m_fFadeEndAngle;
    float m_fFadeAngleRange;
    float fSpeed;
    float m_fGlyphVerticalOffset;
    unsigned int iSize;
    int m_eUpdateStatus;
    float fPos;
    float m_fValue;
};

// Builds the moon texture paths from name and phase suffixes, stores fade/speed/z-offset/size parameters, and initialises position and node pointers.
// @fnv 0x00634a70
FUN_00634a70::FUN_00634a70(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade, float speed,
                           float zOffset, unsigned int size)
    : m_pMoonNode(0), m_pMoonShadowNode(0), m_pMoonShape(0), m_pMoonShadowShape(0)
{
    AutoMemContext memContext(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 50);
    const char* fmt = "\\Textures\\Sky\\%s_%s.dds";
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[3], fmt, name, "one_wan");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[5], fmt, name, "one_wax");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[2], fmt, name, "half_wan");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[6], fmt, name, "half_wax");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[1], fmt, name, "three_wan");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[7], fmt, name, "three_wax");
    FUN_00406f60((FUN_00406f90_this*)&m_kMoonTexturePaths[0], fmt, name, "full");

    m_fFadeStartAngle = fadeStart;
    m_fFadeEndAngle = fadeEnd;
    m_fFadeAngleRange = shadowEarlyFade;
    fSpeed = speed;
    m_fGlyphVerticalOffset = zOffset;
    iSize = size;
    fPos = 0.0f;
    m_fValue = 3.402823466e+38F;
    m_pMoonNode = 0;
    m_pMoonShadowNode = 0;
    m_pMoonShape = 0;
    m_pMoonShadowShape = 0;
    m_eUpdateStatus = 0;
}

class NiTexture;
struct TESSaveLoadGame;



namespace MoonUpdateDetail {

struct Flt
{
    operator std::uintptr_t() const;
};

struct Mtx
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
    Mtx operator*(const Mtx&) const;
};

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};

class NiAVObject
{
};

struct PropHelper
{
};

struct BGSTerrainManager
{
};

struct SkyShaderProperty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    RgbaColor kColor;

};

struct BSShaderManager
{
};

struct SkyView
{
};

struct BSThread
{
};

struct Twin_0084d030
{
};

struct TESSaveLoadGame
{
};

struct TESFaction_RankDataView
{
};

struct FUN_00524ac0_shell
{
};

struct FUN_004a0c90_shell
{
};

struct FUN_00636020_shell : public ::Moon
{
    void FUN_00636020(::Sky*, float);
};

// Updates moon position and visibility, sets texture and culling state on moon nodes, and applies rotation matrices when the sky view is active.
// @fnv 0x00636020
void FUN_00636020_shell::FUN_00636020(::Sky* apSky, float afSecondsPassed)
{
    float fTimePassed;
    float fvisShadow;
    float fvisMoon;
    float fvisStars;
    ::AutoMemContext tempMemContext(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 0x124);

    reinterpret_cast<::FUN_008d0600_s *>(this)->FUN_008d0600((std::intptr_t)(apSky), afSecondsPassed);

    if (m_fValue == _DAT_010231b0)
    {
        m_fValue = 0;
        fPos = DAT_010249d8;
    }
    if (reinterpret_cast<::FUN_0047c850 *>((((TESSaveLoadGame*)::g_TESSaveLoadGame)))->EvaluateCondition())
    {
        m_fValue = -((double)((*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameDaysPassed() - 1) * 24.0);
        fPos = DAT_010249d8;
    }
    fTimePassed = GetFieldEC((const char*)apSky) - m_fValue;
    if (fTimePassed < ::_DAT_01012060)
        fTimePassed = fTimePassed + 24.0;
    fPos = fSpeed * DAT_01012638 * fTimePassed + fPos;
    while (fPos < ::_DAT_01012060)
        fPos = fPos + ::DAT_0103c348;
    while (fPos >= ::DAT_0103c348)
        fPos = fPos - ::DAT_0103c348;
    m_fValue = GetFieldEC((const char*)apSky);

    fvisMoon = GetMoonVisibility();
    fvisShadow = GetMoonShadowVisibility();
    fvisStars = reinterpret_cast<::Twin_0084d030 *>((((Twin_0084d030*)(std::uintptr_t)reinterpret_cast<::ActorMover *>((((BSThread*)apSky)))->GetCurrentMoveModeType())))->GetStoredFloatValue();
    fvisShadow = FUN_0040ebd0(fvisShadow, fvisStars);

    if (m_eUpdateStatus == US_INITIALIZE ||
        (m_eUpdateStatus == US_WHEN_CULLED && fvisMoon <= ::_DAT_01012060 && fvisShadow <= ::_DAT_01012060))
    {
        SkyShaderProperty* pprop =
            (SkyShaderProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator std::uintptr_t())))->FUN_00a59d30(3)));
        ::NiPointer< ::NiTexture> spTex(0);
        ::BSShaderManager::GetTexture(
            (const char*)((const Flt*)&m_kMoonTexturePaths[DAT_011cca80])->operator std::uintptr_t(), true, spTex, true,
            false);
        ::NiTexture* ptex = (::NiTexture*)((const Flt*)&spTex)->operator std::uintptr_t();
        if (ptex)
            reinterpret_cast<::SkyShaderProperty *>((pprop))->SetTexture(ptex);
        ((::TaskQueueInterface*)((const Flt*)&m_pMoonShape)->operator std::uintptr_t())->FUN_00635fe0(ptex != 0);
        m_eUpdateStatus = US_NOT_REQUIRED;
    }

    if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((((SkyView*)apSky)))->FUN_00476c90())) == 3 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((((SkyView*)apSky)))->FUN_00476c90())) == 2)
    {
        if (!((::FUN_006366b0_shell*)((const Flt*)&m_pRootNode)->operator std::uintptr_t())->FUN_006366b0())
        {
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator std::uintptr_t())))->QueueActorDisarm(true);
            return;
        }
        Mtx matrixMoonZ;
        Mtx matrixMoonX;
        reinterpret_cast<::FUN_00524ac0_shell *>((((FUN_00524ac0_shell*)&matrixMoonX)))->FUN_00524ac0(-fPos * DAT_01023128);
        reinterpret_cast<::FUN_004a0c90_shell *>((((FUN_004a0c90_shell*)&matrixMoonZ)))->FUN_004a0c90(m_fGlyphVerticalOffset * DAT_01023128);
        reinterpret_cast<::FUN_0043fa80_s *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator std::uintptr_t())))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((const ::MoonUpdateDetail::Mtx &)(matrixMoonX * matrixMoonZ)));
        if (fvisMoon <= ::_DAT_01012060 && fvisShadow <= ::_DAT_01012060)
        {
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator std::uintptr_t())))->QueueActorDisarm(true);
        }
        else
        {
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator std::uintptr_t())))->QueueActorDisarm(false);
            if (fvisMoon <= ::_DAT_01012060 ||
                !((::FUN_006366b0_shell*)((const Flt*)&m_pMoonShape)->operator std::uintptr_t())->FUN_006366b0())
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonNode)->operator std::uintptr_t())))->QueueActorDisarm(true);
            }
            else
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonNode)->operator std::uintptr_t())))->QueueActorDisarm(false);
                SkyShaderProperty* pshadeProperty =
                    (((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator std::uintptr_t())))->FUN_00a59d30(3))) == 0
                         ? 0
                         : reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator std::uintptr_t())))->FUN_00a59d30(3))))))->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator std::uintptr_t())))->FUN_00a59d30(3)))
                        : 0;
                if (pshadeProperty)
                    pshadeProperty->kColor.a = fvisMoon;
            }
            if (fvisShadow <= ::_DAT_01012060 ||
                !((::FUN_006366b0_shell*)((const Flt*)&m_pMoonShadowShape)->operator std::uintptr_t())->FUN_006366b0())
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator std::uintptr_t())))->QueueActorDisarm(true);
            }
            else
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator std::uintptr_t())))->QueueActorDisarm(false);
                SkyShaderProperty* pshadeProperty =
                    (((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator std::uintptr_t())))->FUN_00a59d30(3))) == 0
                         ? 0
                         : reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShadowShape)
                                                     ->
                                                     operator std::uintptr_t())))->FUN_00a59d30(3))))))->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator std::uintptr_t())))->FUN_00a59d30(3)))
                        : 0;
                if (pshadeProperty)
                    pshadeProperty->kColor =
                        RgbaColor(((float*)((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>((((TESFaction_RankDataView*)apSky)))->GetField())))[0],
                                  ((float*)((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>((((TESFaction_RankDataView*)apSky)))->GetField())))[1],
                                  ((float*)((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>((((TESFaction_RankDataView*)apSky)))->GetField())))[2], fvisShadow);
            }
        }
    }
}

}

class NiMemObject
{
  public:
};

struct NiObject : public NiMemObject
{
  public:
    virtual ~NiObject();
    void IncRefCount();
    void DecRefCount();
    unsigned int refCount;
};

namespace stand {
struct NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
}

struct NiPoint2
{
  public:
    float x, y;
    NiPoint2();
    NiPoint2(float, float);
};

struct ImageSpaceEffectParam
{
  public:
    float r, g, b, a;
    ImageSpaceEffectParam();
    ImageSpaceEffectParam(float, float, float, float);
};

class NiTexture : public NiObject
{
};

class SkyShaderProperty_ctx
{
  public:
    void SetTexture(NiTexture*);
};

class NiTriShape : public NiObject
{
  public:
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, void*, NiPoint2*, unsigned short, unsigned int, unsigned short,
               unsigned short*);
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned char unk38, unk39, unk3a, unk3b;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned char unk44, unk45, unk46, unk47;
    unsigned int unk48;
    unsigned char unk4c, unk4d, unk4e, unk4f;
    unsigned char unk50, unk51, unk52, unk53;
    unsigned char unk54, unk55, unk56, unk57;
    unsigned int unk58;
    unsigned char unk5c, unk5d, unk5e, unk5f;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char unk6c, unk6d, unk6e, unk6f;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned char unk88, unk89, unk8a, unk8b;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned char unkb0, unkb1, unkb2, unkb3;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
};

class NiNode_ctx : public NiMemObject
{
  public:
    virtual void Vfn00();
    virtual void Vfn04();
    virtual void Vfn08();
    virtual void Vfn0C();
    virtual void Vfn10();
    virtual void Vfn14();
    virtual void Vfn18();
    virtual void Vfn1C();
    virtual void Vfn20();
    virtual void Vfn24();
    virtual void Vfn28();
    virtual void Vfn2C();
    virtual void Vfn30();
    virtual void Vfn34();
    virtual void Vfn38();
    virtual void Vfn3C();
    virtual void Vfn40();
    virtual void Vfn44();
    virtual void Vfn48();
    virtual void Vfn4C();
    virtual void Vfn50();
    virtual void Vfn54();
    virtual void Vfn58();
    virtual void Vfn5C();
    virtual void Vfn60();
    virtual void Vfn64();
    virtual void Vfn68();
    virtual void Vfn6C();
    virtual void Vfn70();
    virtual void Vfn74();
    virtual void Vfn78();
    virtual void Vfn7C();
    virtual void Vfn80();
    virtual void Vfn84();
    virtual void Vfn88();
    virtual void Vfn8C();
    virtual void Vfn90();
    virtual void Vfn94();
    virtual void Vfn98();
    virtual void Vfn9C();
    virtual void VfnA0();
    virtual void VfnA4();
    virtual void VfnA8();
    virtual void VfnAC();
    virtual void VfnB0();
    virtual void VfnB4();
    virtual void VfnB8();
    virtual void VfnBC();
    virtual void VfnC0();
    virtual void VfnC4();
    virtual void VfnC8();
    virtual void VfnCC();
    virtual void VfnD0();
    virtual void VfnD4();
    virtual void VfnD8();
    virtual void AttachChildInAvailableSlot(NiObject*, bool);
    NiNode_ctx(unsigned short);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned char unk38, unk39, unk3a, unk3b;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned char unk44, unk45, unk46, unk47;
    unsigned int unk48;
    unsigned char unk4c, unk4d, unk4e, unk4f;
    unsigned char unk50, unk51, unk52, unk53;
    unsigned char unk54, unk55, unk56, unk57;
    unsigned int unk58;
    unsigned char unk5c, unk5d, unk5e, unk5f;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char unk6c, unk6d, unk6e, unk6f;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned char unk88, unk89, unk8a, unk8b;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
};

class NiAlphaProperty : public NiObject
{
  public:
    NiAlphaProperty();
    unsigned int unk08, unk0c, unk10, unk14, unk18;
};

class FUN_00baf3c0
{
  public:
    FUN_00baf3c0();
    unsigned int shaderType;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned char unk38, unk39, unk3a, unk3b;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned char unk44, unk45, unk46, unk47;
    unsigned int unk48;
    unsigned char flags[12];
    unsigned int unk58;
    unsigned char unk5c, unk5d, unk5e, unk5f;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char unk6c, unk6d, unk6e, unk6f;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned char unk88, unk89, unk8a, unk8b;
    unsigned int unk8c;
    unsigned int shadowType;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned char unkb0, unkb1, unkb2, unkb3;
    unsigned int unkb4;
};

class B006815c0
{
  public:
    float m[3][3];
    B006815c0();
};

struct Sky
{
  public:
    static Sky* GetInstance();
};

class NiAVObject;

class BSShaderManager_ctx
{
  public:
    static void GetTexture(const char*, bool, NiPointer<NiTexture>&, bool, bool);
public:
    static void UpdateObjectTypeRecurse(::NiAVObject *, bool, bool);
};

class MoonInit : public Moon
{
  public:
    void FUN_00634e20(NiNode_ctx*, const char*);
};

// @fnv 0x00634e20
void MoonInit::FUN_00634e20(NiNode_ctx* root, const char* name)
{
    AutoMemContext kContext((MEM_CONTEXT)33, true,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 102);
    stand::NiPoint3* aMoonNormals = 0;
    stand::NiPoint3* moonVertices4 = 0;
    stand::NiPoint3* shadowNormals9 = 0;
    stand::NiPoint3* k = 0;
    NiPoint2* moonUVX = 0;
    NiPoint2* kc = 0;
    ImageSpaceEffectParam* moonColors4 = 0;
    ImageSpaceEffectParam* shadowColors_ = 0;
    unsigned short* moonIndices4 = 0;
    unsigned short* shadowIndicesA = 0;
    reinterpret_cast<::F940Owner *>(this)->CreateSortAdjustNode((::F940Parent *)(root));
    aMoonNormals = new stand::NiPoint3[4];
    moonVertices4 = new stand::NiPoint3[4];
    shadowNormals9 = new stand::NiPoint3[4];
    k = new stand::NiPoint3[4];
    moonVertices4[0] = stand::NiPoint3(-1.0 * iSize, (float)iSize, 0.0f);
    moonVertices4[1] = stand::NiPoint3(-1.0 * iSize, -1.0 * iSize, 0.0f);
    moonVertices4[2] = stand::NiPoint3((float)iSize, (float)iSize, 0.0f);
    moonVertices4[3] = stand::NiPoint3((float)iSize, -1.0 * iSize, 0.0f);
    k[0] = stand::NiPoint3(-1.0 * iSize, (float)iSize, 0.0f);
    k[1] = stand::NiPoint3(-1.0 * iSize, -1.0 * iSize, 0.0f);
    k[2] = stand::NiPoint3((float)iSize, (float)iSize, 0.0f);
    k[3] = stand::NiPoint3((float)iSize, -1.0 * iSize, 0.0f);
    moonUVX = new NiPoint2[4];
    kc = new NiPoint2[4];
    moonUVX[0] = NiPoint2(0, 0);
    moonUVX[1] = NiPoint2(0, 1);
    moonUVX[2] = NiPoint2(1, 0);
    moonUVX[3] = NiPoint2(1, 1);
    kc[0] = NiPoint2(0, 0);
    kc[1] = NiPoint2(0, 1);
    kc[2] = NiPoint2(1, 0);
    kc[3] = NiPoint2(1, 1);
    moonColors4 = new ImageSpaceEffectParam[4];
    shadowColors_ = new ImageSpaceEffectParam[4];
    ImageSpaceEffectParam iRed(1, 0, 0, 1);
    moonColors4[0] = iRed;
    moonColors4[1] = iRed;
    moonColors4[2] = iRed;
    moonColors4[3] = iRed;
    shadowColors_[0] = iRed;
    shadowColors_[1] = iRed;
    shadowColors_[2] = iRed;
    shadowColors_[3] = iRed;
    moonIndices4 = (unsigned short*)::FUN_00aa1070(12);
    shadowIndicesA = (unsigned short*)::FUN_00aa1070(12);
    moonIndices4[0] = 0;
    moonIndices4[1] = 1;
    moonIndices4[2] = 2;
    moonIndices4[3] = 2;
    moonIndices4[4] = 1;
    moonIndices4[5] = 3;
    shadowIndicesA[0] = 0;
    shadowIndicesA[1] = 1;
    shadowIndicesA[2] = 2;
    shadowIndicesA[3] = 2;
    shadowIndicesA[4] = 1;
    shadowIndicesA[5] = 3;
    m_pMoonShape = new NiTriShape(4, (NiPoint3*)moonVertices4, (NiPoint3*)aMoonNormals, moonColors4, moonUVX, 1, 0, 2,
                                  moonIndices4);
    reinterpret_cast<::TaskQueueInterface *>((((NiTriShape*)m_pMoonShape)))->FUN_004902f0(true);
    m_pMoonShadowShape =
        new NiTriShape(4, (NiPoint3*)k, (NiPoint3*)shadowNormals9, shadowColors_, kc, 1, 0, 2, shadowIndicesA);
    reinterpret_cast<::TaskQueueInterface *>((((NiTriShape*)m_pMoonShadowShape)))->FUN_004902f0(true);
    {
        NiPointer<NiAlphaProperty> alpha(new NiAlphaProperty);
        reinterpret_cast<::FUN_0049ed90_shell *>((((NiAlphaProperty*)alpha)))->FUN_0049ed90(true);
        reinterpret_cast<::NiObjectNET *>((((NiAlphaProperty*)alpha)))->FUN_00439340(6);
        reinterpret_cast<::fnv_00439390::NiObjectNET *>((((NiAlphaProperty*)alpha)))->FUN_00439390(0);
        reinterpret_cast<::Flag512Receiver *>((((NiAlphaProperty*)alpha)))->FUN_00636000(true);
        reinterpret_cast<::FUN_00439410_cls *>((((NiTriShape*)m_pMoonShape)))->FUN_00439410((::ArgObject *)(::NiObject *)(alpha));
        alpha = 0;
    }
    FUN_00baf3c0 kB;
    kB.shaderType = 6;
    kB.shadowType = 6;
    reinterpret_cast<::FUN_00bb0180_shell *>(&(kB))->AddProperties((::NiAVObject *)(::NiTriShape *)(m_pMoonShape), 1);
    kB.shadowType = 7;
    reinterpret_cast<::FUN_00bb0180_shell *>(&(kB))->AddProperties((::NiAVObject *)(::NiTriShape *)(m_pMoonShadowShape), 1);
    if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((Sky::GetInstance()))->FUN_00476c90())) == 3 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((Sky::GetInstance()))->FUN_00476c90())) == 2)
    {
        SkyShaderProperty_ctx* texture = ((::SkyShaderProperty_ctx *)(reinterpret_cast<::FUN_00a59d30_C *>((((NiTriShape*)m_pMoonShadowShape)))->FUN_00a59d30(3)));
        NiPointer<NiTexture> loaded(0);
        BSShaderManager_ctx::GetTexture("Textures\\Sky\\MoonShadow.dds", true, loaded, true, false);
        NiTexture* shader = loaded;
        if (shader)
            texture->SetTexture(shader);
        reinterpret_cast<::TaskQueueInterface *>((((NiTriShape*)m_pMoonShadowShape)))->FUN_00635fe0(shader != 0);
        m_eUpdateStatus = US_INITIALIZE;
    }
    m_pMoonNode = (NiNode*)new NiNode_ctx(0);
    m_pMoonShadowNode = (NiNode*)new NiNode_ctx(0);
    reinterpret_cast<::TaskQueueInterface *>((((NiNode_ctx*)(NiNode*)m_pMoonNode)))->FUN_004902f0(true);
    reinterpret_cast<::TaskQueueInterface *>((((NiNode_ctx*)(NiNode*)m_pMoonShadowNode)))->FUN_004902f0(true);
    ((NiNode_ctx*)(NiNode*)m_pMoonNode)->AttachChildInAvailableSlot(m_pMoonShape, true);
    ((NiNode_ctx*)(NiNode*)m_pMoonShadowNode)->AttachChildInAvailableSlot(m_pMoonShadowShape, true);
    ((NiNode_ctx*)(NiNode*)m_pRootNode)->AttachChildInAvailableSlot((NiObject*)(NiNode_ctx*)(NiNode*)m_pMoonShadowNode, true);
    ((NiNode_ctx*)(NiNode*)m_pRootNode)->AttachChildInAvailableSlot((NiObject*)(NiNode_ctx*)(NiNode*)m_pMoonNode, true);
    {
        B006815c0 rotation;
        reinterpret_cast<::FUN_00524ac0_shell *>(&(rotation))->FUN_00524ac0(-1.5707963705062866f);
        reinterpret_cast<::FUN_004bc1f0_S *>((((NiTriShape*)m_pMoonShape)))->FUN_004bc1f0(0, 512, 0);
        reinterpret_cast<::FUN_0043fa80_s *>((((NiTriShape*)m_pMoonShape)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
        reinterpret_cast<::FUN_004bc1f0_S *>((((NiTriShape*)m_pMoonShadowShape)))->FUN_004bc1f0(0, 512, 0);
        reinterpret_cast<::FUN_0043fa80_s *>((((NiTriShape*)m_pMoonShadowShape)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
        ::BSShaderManager_ctx::UpdateObjectTypeRecurse((::NiAVObject *)(::NiNode_ctx *)(NiNode*)(m_pRootNode), 0, 0);
    }
}

#include "generated/data/fallout_shared/sky/moon.inc"
