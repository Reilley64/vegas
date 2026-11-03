
// src/fallout/interface/forenderedterminal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/forenderedterminal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/AudioClass_ae5680.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FOPipboyManager.h"
#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00456630_Class.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004dc540_shell.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_007f7fb0_Class.h"
#include "fnv/decl/FUN_007faf10_shell.h"
#include "fnv/decl/FUN_007fd620_Class.h"
#include "fnv/decl/FUN_007ffd50_shell.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00b4dec0_shell.h"
#include "fnv/decl/M3_.h"
#include "fnv/decl/MenuStub.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/Rendered82.h"
#include "fnv/decl/RenderedMenu7fb7.h"
#include "fnv/decl/S0042fa20.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/SystemColorManager.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_007181d0__FUN_007181d0_shell.h"
#include "fnv/decl/fnv_007ff960__FOPipboyManagerPC.h"
#include "fnv/decl/fnv_008b6200__FUN_008b6200.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040d000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_007ff000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01055000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01203000.h"
struct ShadowSceneNode;
struct NiPoint3;
struct NiAVObject
{
    virtual ~NiAVObject();
public:
    ::NiPoint3 &FUN_0043c490();
};
struct FORenderedTerminal
{
    NiAVObject* GetTerminalScreenObject();
    NiAVObject* FUN_007ffad0();
};

struct NiAdditionalGeometryData
{
    static NiAVObject* __cdecl GetShadowSceneNodeForIndex(int);
};

// @fnv 0x007ffad0
NiAVObject* FORenderedTerminal::FUN_007ffad0()
{
    return NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1);
}

struct GlobalObjectO2_0045cfe0
{
};

GlobalObjectO2_0045cfe0 g_011f9148;

// @fnv 0x007ffb60
void ForwardToGlobalObject(int aiValue)
{
    reinterpret_cast<::S0042fa20 *>(&(g_011f9148))->FUN_0045ce80(aiValue);
}

namespace fnv_007ffb80 {
struct GlobalObject2_0040c150
{
    int* Int(void);
};
struct GlobalObjectO2_0045cfe0
{
    int* Int(void);
};
extern GlobalObjectO2_0045cfe0 g_011f9148;

// @fnv 0x007ffb80
int FUN_007ffb80()
{
    return *((int *)&(::FUN_0043d4d0((int *)&(g_011f9148))));
}
}  // namespace fnv_007ffb80

struct FUN_00456630_helper
{
};

struct FUN_007ff8e0_shell
{
    bool FUN_007ff8e0();
};

// @fnv 0x007ff8e0
bool FUN_007ff8e0_shell::FUN_007ff8e0()
{
    return ((bool)(reinterpret_cast<::FUN_00456630_Class *>((reinterpret_cast<FUN_00456630_helper*>(this)))->FUN_00456630(0x4000)));
}

struct FUN_007ff8c0_shell : public FUN_007ff8e0_shell
{
    bool FUN_007ff8c0();
};
// @fnv 0x007ff8c0
bool FUN_007ff8c0_shell::FUN_007ff8c0()
{
    return FUN_007ff8e0();
}

struct NiUpdateData
{
    int _00;
    int _04;
    int _08;
    NiUpdateData(float, bool, bool);
};
struct BSAudio
{
    unsigned int GetSynchTime();
};
struct FUN_004bc1f0_S
{
    void FUN_004bc1f0(float, float, float);
};
class NiAVObject;
struct NiNode
{
public:
    ::NiAVObject *GetAt(unsigned int);
};
extern float DAT_01078bb0;
struct FUN_007ff900_This
{
    void UpdateSynchTimeNode();
};
// @fnv 0x007ff900
void FUN_007ff900_This::UpdateSynchTimeNode()
{
    NiAVObject* proot;
    proot = (NiAVObject*)((BSAudio*)this)->GetSynchTime();
    if (proot)
    {
        ((FUN_004bc1f0_S*)proot)->FUN_004bc1f0(DAT_01078bb0, 0.0f, 0.0f);
        NiUpdateData UpdateData(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NiNode*)proot)))->FUN_00a59c60((std::intptr_t)&(UpdateData));
    }
}

struct V3;
struct FUN_00440460_S
{
    void FUN_00440460(V3 const*);
};
struct BSRenderedTexture;
struct NiRenderer
{
    enum ClearFlags
    {
        kClearNone,
        kClearZ,
        kClearColor,
        kClearStencil,
        kClearAll
    };
};
struct FUN_007ff7c0_shell : public BSAudio, public FUN_00440460_S
{
    void FUN_007ff7c0(BSRenderedTexture* apTarget, NiRenderer::ClearFlags aeClearMode, BSRenderedTexture* apSwapTarget);
};
// @fnv 0x007ff7c0
void FUN_007ff7c0_shell::FUN_007ff7c0(BSRenderedTexture* apTarget, NiRenderer::ClearFlags aeClearMode,
                                      BSRenderedTexture* apSwapTarget)
{
    NiAVObject* proot = (NiAVObject*)GetSynchTime();
    if (proot)
    {
        ((FUN_00440460_S*)proot)->FUN_00440460((V3 const*)((char*)this + 0xd8));
        NiUpdateData UpdateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NiNode*)proot)))->FUN_00a59c60((std::intptr_t)&(UpdateData));
    }
    reinterpret_cast<::Rendered82 *>(this)->FUN_007fba00(apTarget, (void *)(1), (::Target82 *)(0));
}

struct Flt
{
    operator unsigned int();
};
void ForwardToGlobalObject(int param);
struct BSFadeNode
{
    void SetRange(float, float);
};
struct FUN_007ffaf0_shell
{
    void FUN_007ffaf0();
};

// If g_011db63c is set, saves and restores the value from FUN_007ffb80 around ForwardToGlobalObject(0) and SetRange(0,0); then sets byte 0xec to 1 and float 0xe8 to 1.0.
// @fnv 0x007ffaf0
void FUN_007ffaf0_shell::FUN_007ffaf0()
{
    if ((unsigned int)(*reinterpret_cast<::Flt *>(&::g_011db63c)))
    {
        int iSavedValue = ::fnv_007ffb80::FUN_007ffb80();
        ForwardToGlobalObject(0);
        ((BSFadeNode*)(unsigned int)(*reinterpret_cast<::Flt *>(&::g_011db63c)))->SetRange(0.0f, 0.0f);
        ForwardToGlobalObject(iSavedValue);
    }
    ((char*)this)[0xec] = 1;
    *(float*)((char*)this + 0xe8) = 1.0f;
}

struct FUN_007ff820_shell : public FUN_007ff7c0_shell
{
    bool UpdateAudioFallback();
};

struct AudioClock : public FUN_007ff8c0_shell
{
};
struct AudioFallback
{
};


// @fnv 0x007ff820
bool FUN_007ff820_shell::UpdateAudioFallback()
{
    if (*((unsigned char*)this + 0xec))
    {
        if (!(*reinterpret_cast<::Flt *>(&::g_011db63c)) || !((AudioClock*)(unsigned int)(*reinterpret_cast<::Flt *>(&::g_011db63c)))->FUN_007ff8c0() ||
            *((float*)((char*)this + 0xe8)) == ::GetFieldB4Float((char *)(::AudioClock *)((AudioClock*)(unsigned int)(*reinterpret_cast<::Flt *>(&::g_011db63c)))))
        {
            reinterpret_cast<::fnv_007181d0::FUN_007181d0_shell *>((((::AudioFallback *)(::fnv_004b7210::FUN_004b7210()))))->SetRenderedMenu({});
            return true;
        }
        else
        {
            *((float*)((char*)this + 0xe8)) = ::GetFieldB4Float((char *)(::AudioClock *)((AudioClock*)(unsigned int)(*reinterpret_cast<::Flt *>(&::g_011db63c))));
        }
    }
    return reinterpret_cast<::FUN_007faf10_shell *>((this))->UpdateScreenEffect();
}

struct PickTargetNode;

struct PickNodePtr
{
    operator PickTargetNode*() const;
};

struct PickPoint3
{
    float x;
    float y;
    float z;
    PickPoint3();
};

struct PickCamera
{
};

struct PickFaceGenNode
{
};

struct PickInterfaceMgr
{
};

struct PickRecord
{
    PickTargetNode* GetObject();
};

struct PickResultArray
{
};

struct PickQuery
{
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
    PickQuery(int aeSortType, int aeIntersectType);
    ~PickQuery();
};

struct RenderedTerminalStandIn
{
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
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    PickNodePtr spScreenNode;

    bool HandleClick(bool abDown, int aiX, int aiY);
};

// If the screen node is set and the button is down, ray-picks it from the cursor and calls OnScreenClicked on a hit; otherwise falls through to HandleClickBase.
// @fnv 0x007ffba0
bool RenderedTerminalStandIn::HandleClick(bool abDown, int aiX, int aiY)
{
    bool bHandledX = false;
    PickInterfaceMgr* pInterfaceMgr = ((::PickInterfaceMgr *)(::fnv_004b7210::FUN_004b7210()));
    if (spScreenNode && abDown)
    {
        PickPoint3 kOriginTmp;
        PickPoint3 kDir3;
        PickCamera* pCamera = ((::PickCamera *)(reinterpret_cast<::fnv_008b6200::FUN_008b6200 *>(this)->GetFlt()));
        if (!pCamera)
        {
            pCamera = ((::PickCamera *)(reinterpret_cast<::BSFaceGenNiNode *>((((::PickFaceGenNode *)(::FUN_0045c670()))))->GetAnimationData()));
        }
        PickQuery kPick(0, 8);
        reinterpret_cast<::FUN_00458b30_class *>(&(kPick))->SetByteAtOffset17(0);
        reinterpret_cast<::NiPick *>(&(kPick))->FUN_00705fc0(spScreenNode);
        reinterpret_cast<::CombatProcedure *>(&(kPick))->Initialize((::CombatController *)(true));
        reinterpret_cast<::CameraWindowRay *>((pCamera))->MapScreenToRay((int)reinterpret_cast<::BGSImpactData *>((pInterfaceMgr))->FUN_009a9350(), (int)reinterpret_cast<::FUN_00792760_shell *>((pInterfaceMgr))->FUN_00792760(), (::NiPoint3 &)(kOriginTmp),
                                  (::NiPoint3 &)(kDir3), (const ::NiRenderTargetGroup *)(0));
        if (reinterpret_cast<::NiPick *>(&(kPick))->PerformPick((const ::NiPoint3 &)(kOriginTmp), (const ::NiPoint3 &)(kDir3), false))
        {
            unsigned int uiIndex3 = 0;
            PickRecord* pRecord5 = ((::PickRecord *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>(&((*(::PickResultArray *)(reinterpret_cast<::BGSCameraPath *>(&(kPick))->GetConditions()))))->FUN_00968670(uiIndex3)));
            if (pRecord5 && pRecord5->GetObject() == spScreenNode)
            {
                reinterpret_cast<::FUN_007ffd50_shell *>(this)->FUN_007ffd50();
                return false;
            }
        }
    }
    bool bResult = reinterpret_cast<::RenderedMenu7fb7 *>(this)->FUN_007fb790((void *)(abDown), (float *)(aiX), (float *)(aiY));
    return bResult;
}

struct FloatSetting
{
};
extern int DAT_011f9434;
struct Name
{
    unsigned interned;
    Name(const char*);
    ~Name();
};
struct Vector3
{
    float x, y, z;
    Vector3(float, int, int);
};
struct FourFloatVector
{
    float x, y, z, w;
    FourFloatVector(float, float, float, float);
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix();
    Matrix operator*(const Matrix&) const;
};
struct Frustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    Frustum(int);
};
struct Resource
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Resource* Child(int);
    virtual void v10();
    virtual void v14();
    virtual Resource* GetNode();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual Resource* Find(const Name&);
};
struct NodeHolder
{
    void Assign(Resource*);
};
struct Manager
{
};
struct Camera : Resource
{
    int f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    int f80, f84, f88, f8c, f90, f94, f98, f9c, fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc;
    int fc0, fc4, fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0, ff4, ff8, ffc;
    int f100, f104, f108, f10c, f110;
    Camera();
};
struct Controller
{
    int f00, f04, f08, f0c, f10, f14, f18;
    Controller();
};
struct Interface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual float GetFar();
};
struct Backend
{
};
Backend* __cdecl GetBackend(int);
struct Colors
{
};
struct RenderNode
{
    Resource* GetRenderObject();
    void SetupPowerButtonScreen();
};
// Loads the screen and PowerButton nodes, builds a camera with frustum, sets screen/root/camera, updates, and creates the backend render object.
// @fnv 0x007feeb0
void RenderNode::SetupPowerButtonScreen()
{
    reinterpret_cast<::FOPipboyManager *>(this)->SetScanlines(1, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011db674)))))));
    bool createdCur = false;
    Resource* rootP = 0;
    if (!(unsigned)(*reinterpret_cast<::Flt *>(&::g_011db63c)))
    {
        rootP = ((::Resource *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::Manager * *>(&::g_modelLoader))))->FUN_00447080((char *)((*reinterpret_cast<unsigned int *>(&::DAT_011a0bb0))), 0, 1, 0, 0, 0)));
        ((NodeHolder*)&(*reinterpret_cast<::Flt *>(&::g_011db63c)))->Assign(rootP);
        ::UpdateObjectVisibility((::NiAVObject *)(rootP));
        createdCur = true;
    }
    else
        rootP = (Resource*)(unsigned)(*reinterpret_cast<::Flt *>(&::g_011db63c));
    Resource* screenX = rootP->Find(Name("screen"));
    Resource* screenNode = screenX->GetNode();
    if (!screenNode)
        screenNode = ((::Resource *)(reinterpret_cast<::NiNode *>((screenX->Child(0)))->GetAt({})))->GetNode();
    Resource* kPower = rootP->Find(Name("PowerButton"));
    if (kPower->GetNode())
        ((NodeHolder*)((char*)this + 0xe4))->Assign(kPower);
    else
        ((NodeHolder*)((char*)this + 0xe4))->Assign(((::Resource *)(reinterpret_cast<::NiNode *>((kPower->Child(0)))->GetAt({}))));
    Matrix rotAM, rotB;
    reinterpret_cast<::ThreeByThreeMatrix *>(&(rotAM))->SetYRotation(DAT_010559cc);
    reinterpret_cast<::FUN_004a0c90_shell *>(&(rotB))->FUN_004a0c90(DAT_010559cc);
    reinterpret_cast<::FUN_0043fa80_s *>((rootP))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((const ::Matrix &)(rotB * rotAM)));
    float rate9 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011db65c))))));
    if (!FUN_00707b50() && !DAT_011f9426)
        rate9 = (float)(rate9 * ::DAT_0101de30);
    reinterpret_cast<::FUN_004bc1f0_S *>((rootP))->FUN_004bc1f0(rate9, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011db614)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011db62c)))))));
    Vector3 akStart(0.f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((rootP))->FUN_00a59c60((std::intptr_t)&(akStart));
    Camera* cameraK = new Camera;
    FourFloatVector viewport(0.f, 1.f, 1.f, 0.f);
    reinterpret_cast<::_Cam_00712e60 *>((cameraK))->FUN_00712e60((const ::_Rect16_00712e60 &)(viewport));
    Matrix frame5;
    reinterpret_cast<::M3_ *>(&(frame5))->SetElement(0, 0.f, 0.f, 1.f);
    reinterpret_cast<::M3_ *>(&(frame5))->SetElement(1, 1.f, 0.f, 0.f);
    reinterpret_cast<::M3_ *>(&(frame5))->SetElement(2, 0.f, 1.f, 0.f);
    reinterpret_cast<::FUN_0043fa80_s *>((cameraK))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((*reinterpret_cast<::Matrix *>(&::DAT_011a9448))));
    reinterpret_cast<::FUN_00733fd0_shell *>((cameraK))->FUN_00733fd0(1.f);
    Frustum frustum(0);
    frustum.farPlane = ((::Interface *)(::FUN_0045c670()))->GetFar();
    frustum.nearPlane = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_01203144))))));
    reinterpret_cast<::FUN_00507700_cls *>((cameraK))->FUN_00507700(frustum.farPlane / frustum.nearPlane);
    float aspect6 = (double)(DAT_011f9426 ? DAT_011f9434 : FUN_004dc200()) / ((int)(::FUN_004dc1f0()));
    float scale4 = DAT_01016264;
    float angle7 = (float)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_01203150)))))) * ::DAT_01023128 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011db5ec)))))));
    frustum.left = -FUN_0057dd70(angle7) * scale4;
    frustum.right = FUN_0057dd70(angle7) * scale4;
    frustum.bottom = -FUN_0057dd70(angle7) * aspect6 * scale4;
    frustum.top = FUN_0057dd70(angle7) * aspect6 * scale4;
    frustum.ortho = false;
    reinterpret_cast<::NiCamera *>((cameraK))->UpdateViewFrustum((const ::NiFrustum &)(frustum));
    Vector3 pos2(0.f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((cameraK))->FUN_00a59c60((std::intptr_t)&(pos2));
    reinterpret_cast<::FOPipboyManager *>(this)->FUN_007fc2d0((::NiAVObject *)(screenNode));
    reinterpret_cast<::FOPipboyManager *>(this)->SetScreen((::NiAVObject *)(screenNode));
    reinterpret_cast<::FUN_004dc540_shell *>(this)->FUN_004dc540((::NiAVObject *)(rootP));
    reinterpret_cast<::ExtraOwnerB *>((screenNode))->FUN_00a5b230((int)(((::FUN_0040df90()))));
    reinterpret_cast<::FUN_00439410_cls *>((screenNode))->FUN_00439410((::ArgObject *)(void *)(new Controller));
    reinterpret_cast<::FUN_007fd620_Class *>(this)->SetGo(cameraK);
    reinterpret_cast<::FORenderedMenu *>(this)->OnMenuOpen();
    *(Vector3*)((char*)this + 0xd8) = (*(const ::Vector3 *)&(reinterpret_cast<::NiAVObject *>((GetRenderObject()))->FUN_0043c490()));
    reinterpret_cast<::FUN_004bc1f0_S *>((GetRenderObject()))->FUN_004bc1f0(DAT_01078bb0, 0.f, 0.f);
    float radius = (float)(reinterpret_cast<::Twin_0084d030 *>((((::Resource *)(reinterpret_cast<::FUN_0043d450_Owner *>((rootP))->FUN_0043d450()))))->GetStoredFloatValue() * DAT_01021928);
    void* aBackend = ((void *)(reinterpret_cast<::SSN_b5 *>((GetBackend(1)))->FUN_00b5ca70((::Node_b5 *)(rootP), radius)));
    if (!aBackend)
        reinterpret_cast<::fnv_007ff960::FOPipboyManagerPC *>(this)->CreateTerminalLight();
    reinterpret_cast<::MenuStub *>(this)->FUN_007fae70(0);
    reinterpret_cast<::FUN_00810530_c *>(this)->FUN_00810530(0);
    reinterpret_cast<::FUN_00b4dec0_shell *>((((Resource*)(unsigned)(*reinterpret_cast<::Flt *>(&::g_011db63c)))))->FUN_00b4dec0(8);
    FourFloatVector colorF(0.f, 0.f, 0.f, 0.f);
    if (reinterpret_cast<::SystemColorManager *>((((::Colors *)(::FUN_00718b60()))))->GetColor((int)&(colorF), *(::NiColor *)nullptr))
        reinterpret_cast<::FUN_007f7fb0_Class *>(this)->FUN_007f7fb0((const ::FUN_007f7fb0_Value *)&(colorF));
    *(float*)((char*)this + 0xe8) = 1.f;
}

struct Sound376
{
    unsigned int id;
    unsigned int flags;
    unsigned int state;
    ~Sound376()
    {}
};
struct Audio376
{
};
// @fnv 0x007ffe40
void FUN_007ffe40()
{
    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::Sound376 &)((*(::Sound376 *)(reinterpret_cast<::AudioClass_ae5680 *>((((::Audio376 *)(::FUN_00ad9060()))))->ResolveAudioHandle((::Handle_ae5680 *)("OBJComputerTerminalPowerDown"), 0x121, {})))))->FUN_00ad8830(false);
}

#include "generated/data/fallout/interface/forenderedterminal.inc"
