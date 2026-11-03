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

class TaskQueueInterface
{
  public:
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

struct NiTexture;
struct TESSaveLoadGame;



namespace MoonUpdateDetail {

struct Flt
{
    operator unsigned int() const;
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

struct NiAVObject
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

    reinterpret_cast<::FUN_008d0600_s *>(this)->FUN_008d0600((int)(apSky), afSecondsPassed);

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
    fvisStars = reinterpret_cast<::Twin_0084d030 *>((((Twin_0084d030*)reinterpret_cast<::ActorMover *>((((BSThread*)apSky)))->GetCurrentMoveModeType())))->GetStoredFloatValue();
    fvisShadow = FUN_0040ebd0(fvisShadow, fvisStars);

    if (m_eUpdateStatus == US_INITIALIZE ||
        (m_eUpdateStatus == US_WHEN_CULLED && fvisMoon <= ::_DAT_01012060 && fvisShadow <= ::_DAT_01012060))
    {
        SkyShaderProperty* pprop =
            (SkyShaderProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())))->FUN_00a59d30(3)));
        ::NiPointer< ::NiTexture> spTex(0);
        ::BSShaderManager::GetTexture(
            (const char*)((const Flt*)&m_kMoonTexturePaths[DAT_011cca80])->operator unsigned int(), true, spTex, true,
            false);
        ::NiTexture* ptex = (::NiTexture*)((const Flt*)&spTex)->operator unsigned int();
        if (ptex)
            reinterpret_cast<::SkyShaderProperty *>((pprop))->SetTexture(ptex);
        ((::TaskQueueInterface*)((const Flt*)&m_pMoonShape)->operator unsigned int())->FUN_00635fe0(ptex != 0);
        m_eUpdateStatus = US_NOT_REQUIRED;
    }

    if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((((SkyView*)apSky)))->FUN_00476c90())) == 3 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((((SkyView*)apSky)))->FUN_00476c90())) == 2)
    {
        if (!((::FUN_006366b0_shell*)((const Flt*)&m_pRootNode)->operator unsigned int())->FUN_006366b0())
        {
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())))->QueueActorDisarm(true);
            return;
        }
        Mtx matrixMoonZ;
        Mtx matrixMoonX;
        new ((void *)&(matrixMoonX)) ::Vec3();
        new ((void *)&(matrixMoonZ)) ::Vec3();
        reinterpret_cast<::FUN_00524ac0_shell *>((((FUN_00524ac0_shell*)&matrixMoonX)))->FUN_00524ac0(-fPos * DAT_01023128);
        reinterpret_cast<::FUN_004a0c90_shell *>((((FUN_004a0c90_shell*)&matrixMoonZ)))->FUN_004a0c90(m_fGlyphVerticalOffset * DAT_01023128);
        reinterpret_cast<::FUN_0043fa80_s *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((const ::MoonUpdateDetail::Mtx &)(matrixMoonX * matrixMoonZ)));
        if (fvisMoon <= ::_DAT_01012060 && fvisShadow <= ::_DAT_01012060)
        {
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())))->QueueActorDisarm(true);
        }
        else
        {
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pRootNode)->operator unsigned int())))->QueueActorDisarm(false);
            if (fvisMoon <= ::_DAT_01012060 ||
                !((::FUN_006366b0_shell*)((const Flt*)&m_pMoonShape)->operator unsigned int())->FUN_006366b0())
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonNode)->operator unsigned int())))->QueueActorDisarm(true);
            }
            else
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonNode)->operator unsigned int())))->QueueActorDisarm(false);
                SkyShaderProperty* pshadeProperty =
                    (((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())))->FUN_00a59d30(3))) == 0
                         ? 0
                         : reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())))->FUN_00a59d30(3))))))->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShape)->operator unsigned int())))->FUN_00a59d30(3)))
                        : 0;
                if (pshadeProperty)
                    pshadeProperty->kColor.a = fvisMoon;
            }
            if (fvisShadow <= ::_DAT_01012060 ||
                !((::FUN_006366b0_shell*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())->FUN_006366b0())
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator unsigned int())))->QueueActorDisarm(true);
            }
            else
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)((const Flt*)&m_pMoonShadowNode)->operator unsigned int())))->QueueActorDisarm(false);
                SkyShaderProperty* pshadeProperty =
                    (((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())))->FUN_00a59d30(3))) == 0
                         ? 0
                         : reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShadowShape)
                                                     ->
                                                     operator unsigned int())))->FUN_00a59d30(3))))))->GetMinLevel() == 0xd)
                        ? (SkyShaderProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)((const Flt*)&m_pMoonShadowShape)->operator unsigned int())))->FUN_00a59d30(3)))
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
