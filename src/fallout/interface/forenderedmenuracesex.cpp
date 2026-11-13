
// src/fallout/interface/forenderedmenuracesex.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/forenderedmenuracesex.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/native_fixed_string.h"
#include "fallout/interface/rendered_menu_fields.h"
#include "fnv/game_timer.h"
#include <cstdint>
#include <new>
#include <cstdlib>
#include "fnv/decl/BB97550Shader.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BSRenderedTexture.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FOPipboyManager.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004bc280_S.h"
#include "fnv/decl/FUN_004dc540_shell.h"
#include "fnv/decl/FUN_00503650_shell.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_0050c630_helper.h"
#include "fnv/decl/FUN_006b0570_shell.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_00792780_Class.h"
#include "fnv/decl/FUN_007f7fb0_Class.h"
#include "fnv/decl/FUN_007faf10_shell.h"
#include "fnv/decl/FUN_007fd620_Class.h"
#include "fnv/decl/FUN_007fecc0_Class.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_008d7f00_class.h"
#include "fnv/decl/FUN_008eeaa0Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00965580_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/M3_.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/MenuStub.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/NiPointLight.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/Rendered82.h"
#include "fnv/decl/RenderedMenu7fb7.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/SystemColorManager.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/UAMActor.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_0050c660__FUN_0050c660_shell.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_007fd640__FUN_007fd640Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008b6200__FUN_008b6200.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040d000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_0050c000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01203000.h"
struct S16
{
    int a, b, c, d;
};
struct FUN_007feb40_This
{
    char _pad[0xC0];
    S16* GetValueAtC0(S16* p);
};
// Copies the 16-byte value at offset 0xC0 of this object into the caller-supplied struct and returns that pointer.
// @fnv 0x007feb40
S16* FUN_007feb40_This::GetValueAtC0(S16* pValue)
{
    *pValue = *(S16*)((char*)this + 0xC0);
    return pValue;
}

struct Animation
{
};
struct Animation;
class PlayerCharacter
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void Refresh();
public:
    ::Animation *GetAnimation(bool) const;
};
class Menu
{
  public:
    bool FUN_007fe4e0();
};
// @fnv 0x007fe4e0
bool Menu::FUN_007fe4e0()
{
    if (!reinterpret_cast<::FOPipboyManager *>(this)->IsUnk28Set())
    {
        ::fnv_007037e0::FUN_007037e0();
        return false;
    }
    reinterpret_cast<::FUN_008eeaa0Class *>((::_g_thePlayer->GetAnimation(false)))->FUN_008eeaa0(23);
    ::_g_thePlayer->Refresh();
    reinterpret_cast<::UAMActor *>((::_g_thePlayer))->FUN_008885e0((::UAMAnim *)(::Animation *)(::_g_thePlayer->GetAnimation(false)), 0.0f);
    return reinterpret_cast<::FUN_007faf10_shell *>(this)->UpdateScreenEffect();
}

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};
struct SettingFloat
{
};
struct NiRenderer;
struct ImageSpaceManager
{
public:
    static ::ImageSpaceManager *FUN_004e3270();
};
struct Effect
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    float primary;
    bool enabled;
    unsigned char state159, state15a, state15b;
    unsigned int unk15c;
    float secondary;
    void FUN_007fe9c0(void*, void*, void*);
};
// @fnv 0x007fe9c0
void Effect::FUN_007fe9c0(void* apArg1, void* apArg2, void* unused)
{
    bool active = true;
    active = false;
    if (active)
    {
        ::DAT_011ae600 = reinterpret_cast<::FUN_00507e10_shell *>(this)->FUN_00507e10();
        ::DAT_0120081c = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011db520))))));
        ::DAT_011ae604 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011db464))))));
        ::DAT_01200820 = primary;
        (*reinterpret_cast<::RgbaColor *>(&::DAT_0120082c)) = (*(::RgbaColor *)(reinterpret_cast<::FUN_007feb40_This *>(this)->GetValueAtC0({})));
    }
    else
    {
        ::DAT_0120081c = 0.0f;
        ::DAT_011ae604 = 0.0f;
        ::DAT_01200820 = -1.0f;
        ::DAT_011ae600 = 1.0f;
        (*reinterpret_cast<::RgbaColor *>(&::DAT_0120082c)) = RgbaColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
    if (enabled && active)
    {
        ::DAT_01200824 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011db520))))));
        ::DAT_011ae608 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011db464))))));
        ::DAT_01200828 = secondary;
    }
    else
    {
        ::DAT_01200824 = 0.0f;
        ::DAT_011ae608 = 0.0f;
        ::DAT_01200828 = -1.0f;
    }
    reinterpret_cast<::BB97550Shader *>((::ImageSpaceManager::FUN_004e3270()))->FUN_00b97550(30, (std::intptr_t)(::FUN_0043c4b0()), (std::intptr_t)(apArg1), (std::intptr_t)(apArg2), 0, 1);
}

struct S_007fb5a0_Point3
{
    float x, y, z;
    S_007fb5a0_Point3 operator*(float s) const;
    S_007fb5a0_Point3 operator+(const S_007fb5a0_Point3& o) const;
};

struct S_007fb5a0_UpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bUpdateFlags;
    int unk8;
    S_007fb5a0_UpdateData(float t, bool c, bool f);
};

struct S_007fb5a0_Node
{
};

struct S_007fb5a0_NodePtr
{
    S_007fb5a0_Node* m_p;
    operator S_007fb5a0_Node*() const;
    S_007fb5a0_Node* operator->() const;
};

struct S_007fb5a0_Setting
{
};


float FUN_004e44d0(float f);

struct S_007fb5a0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    S_007fb5a0_NodePtr m_pController;  // 1c
    int unk20, unk24, unk28;
    S_007fb5a0_Point3 kBase;        // 2c
    float m_fThirdCreatureStatCur;  // 38
    float fOffsetScale;             // 3c
    int unk40, unk44, unk48;
    char unk4c;
    bool bUseFirst;  // 4d
    char unk4e, unk4f;
    int unk50, unk54, unk58;
    float fFirst;  // 5c
    bool bUseSin;  // 60
    char unk61, unk62, unk63;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    float fSecond;  // 8c
    int unk90;
    bool bApplyOffset;  // 94

    void UpdateNodePosition(float fTime);
};

// @fnv 0x007fb5a0
void S_007fb5a0::UpdateNodePosition(float fTime)
{
    if (m_pController)
    {
        S_007fb5a0_Point3 kIntersectionOffset = (*reinterpret_cast<::S_007fb5a0_Point3 *>(&::DAT_011f4998));
        if (bApplyOffset)
        {
            float fA = bUseFirst ? fFirst * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_007fb5a0_Setting *>(&::g_011db430)))))) : 0.0;
            float fB = fSecond * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_007fb5a0_Setting *>(&::g_011db4a4))))));
            float fScaleA = bUseSin ? FUN_004e44d0(fTime * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_007fb5a0_Setting *>(&::g_011db3e8))))))) + 0.5 : 1.0;
            float fD = (fA + fB) * fScaleA;
            kIntersectionOffset = kBase * fD * fOffsetScale;
        }
        S_007fb5a0_Point3 kPos = kBase * m_fThirdCreatureStatCur + kIntersectionOffset;
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>(((m_pController).operator->()))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(kPos));
        S_007fb5a0_UpdateData kData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>(((m_pController).operator->()))->FUN_00a59c60((std::intptr_t)&(kData));
    }
}

struct S_007fe560_Shadow;
struct S_007fe560_Pt3
{
    float x, y, z;
};
struct S_007fe560_Upd
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_007fe560_Light
{
    void FUN_0050dd50(const S_007fe560_Pt3& p);
};
struct S_007fe560_Base
{
};

struct FUN_007fe560_cls : S_007fe560_Base
{
    void InitTerminalLight();
};

class NiNode;
class Menu;

struct NodePtr
{
    NiNode* m_pObject;
    operator NiNode*() const;
};

struct PickVec
{
    float x;
    float y;
    float z;
    PickVec();
};

struct PickRecord
{
};

struct GlobalObject_00e98f20
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
    GlobalObject_00e98f20(int a1, int a2);
    ~GlobalObject_00e98f20();
};

struct InterfaceManager
{
};


struct PickCamera
{
};

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    ~BSSoundHandleEx();
};

struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};

struct RaceSexMenu
{
public:
    void FUN_007fe910(void *);
};

struct MenuTile
{
};

struct ShadowSceneNode;
class FORenderedMenu
{
public:
    void OnMenuOpen();
public:
    bool CreateMenuLight(const char *, ::ShadowSceneNode *);
};
// @fnv 0x007fe560
void FUN_007fe560_cls::InitTerminalLight()
{
    if (!reinterpret_cast<::FORenderedMenu *>(this)->CreateMenuLight("Omni01", (::ShadowSceneNode *)(::S_007fe560_Shadow *)(((::S_007fe560_Shadow *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))))
    {
        ::FUN_005b5e40();
        return;
    }
    S_007fe560_Light* light = ((::S_007fe560_Light *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>(this)->FUN_006838b0()));
    if (light)
    {
        S_007fe560_Pt3 kPos;
        S_007fe560_Pt3 kDiffuseColor;
        S_007fe560_Pt3 kAmbient;
        S_007fe560_Pt3 kFullColor;
        S_007fe560_Upd kNewData;
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((light))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(*((::S_007fe560_Pt3 *)(reinterpret_cast<::FUN_00416870_t *>(&(kAmbient))->FUN_00416870(0.0f, 0.0f, 0.0f)))));
        reinterpret_cast<::FUN_004bc280_S *>((light))->FUN_004bc280((const ::C3 *)&(*((::S_007fe560_Pt3 *)(reinterpret_cast<::FUN_00416870_t *>(&(kDiffuseColor))->FUN_00416870(0.0f, 0.0f, 0.0f)))));
        reinterpret_cast<::FUN_0050c630_helper *>((light))->FUN_0050c630(0.0f);
        reinterpret_cast<::fnv_0050c660::FUN_0050c660_shell *>((light))->FUN_0050c660(0.0f);
        ::FUN_0050c690((::NiDynamicEffect *)(light), 0.0f);
        reinterpret_cast<::NiPointLight *>((light))->FUN_0050dd20(1.0f);
        light->FUN_0050dd50(*((::S_007fe560_Pt3 *)(reinterpret_cast<::FUN_00416870_t *>(&(kPos))->FUN_00416870(DAT_01017b78, 0.0f, 0.0f))));
        reinterpret_cast<::FUN_00416870_t *>(&(kFullColor))->FUN_00416870(1.0f, 1.0f, 1.0f);
        reinterpret_cast<::FUN_006b0570_shell *>(this)->FUN_006b0570((::NiColor *)(::S_007fe560_Pt3 *)(&kFullColor));
        reinterpret_cast<::FUN_00965580_shell *>(this)->SetIntensity(1.0f);
        reinterpret_cast<::FOPipboyManager *>(this)->SetScreenLightFlickerIntensity(1.0f);
        new ((void *)&(kNewData)) ::NiUpdateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((light))->FUN_00a59c60((std::intptr_t)&(kNewData));
    }
}

struct FORenderedMenuRaceSex : FORenderedMenu
{
    int unk00[0x36];
    NodePtr unkD8[4];
    NodePtr unkE8[4];

    bool HandleRaceSexMenuInput(bool abDown, intptr_t a2, intptr_t a3);
};

// @fnv 0x007fe6c0
bool FORenderedMenuRaceSex::HandleRaceSexMenuInput(bool abDown, intptr_t a2, intptr_t a3)
{
    InterfaceManager* pInterface = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    if (abDown)
    {
        bool bReady = true;
        for (int i = 0; bReady && i < 4; i++)
        {
            if (!(NiNode*)unkD8[i] || !(NiNode*)unkE8[i])
                bReady = false;
        }
        if (bReady)
        {
            PickVec origin;
            PickVec dir;
            GlobalObject_00e98f20 pick(0, 8);
            reinterpret_cast<::FUN_00458b30_class *>(&(pick))->SetByteAtOffset17(1);
            reinterpret_cast<::CombatProcedure *>(&(pick))->Initialize((::CombatController *)(0));
            reinterpret_cast<::FUN_00792780_Class *>(&(pick))->SetByteAtOffset30(0);
            intptr_t iFound = -1;
            for (int j = 0; iFound < 0 && j < 4; j++)
            {
                reinterpret_cast<::NiPick *>(&(pick))->FUN_00705fc0(unkD8[j]);
                reinterpret_cast<::CameraWindowRay *>((((::PickCamera *)(reinterpret_cast<::RenderedMenuFields *>(this)->m_pMenuLightParameters))))->MapScreenToRay((int)reinterpret_cast<::BGSImpactData *>((pInterface))->FUN_009a9350(), (int)reinterpret_cast<::FUN_00792760_shell *>((pInterface))->FUN_00792760(),
                                               (*(::NiPoint3 *)(&origin)), (*(::NiPoint3 *)(&dir)), (const ::NiRenderTargetGroup *)(0));
                if (reinterpret_cast<::NiPick *>(&(pick))->PerformPick((*(const ::NiPoint3 *)(&origin)), (*(const ::NiPoint3 *)(&dir)), 0))
                {
                    if (((void *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::PickRecord *)(reinterpret_cast<::BGSCameraPath *>(&(pick))->GetConditions()))))->FUN_00968670(0))))
                        iFound = j;
                }
            }
            if (iFound >= 0)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIMenuMode", 0x121)))->FUN_00ad8830(false);
                ((::RaceSexMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((((::MenuTile *)(reinterpret_cast<::RenderedMenuFields *>(this)->m_pFourthMenuObject))))->FUN_00a03c90()))->FUN_007fe910((void *)(iFound));
                return true;
            }
        }
    }
    return reinterpret_cast<::RenderedMenu7fb7 *>(this)->FUN_007fb790((void *)(abDown), (float *)(a2), (float *)(a3));
}



struct TimerSource
{
};


struct FUN_007feb80_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54(float afValue);

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
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    float m_f150;
    float m_f154;
    unsigned char m_b158;
    unsigned char unk159;
    unsigned char unk15A;
    unsigned char unk15B;
    unsigned char unk15C;
    unsigned char unk15D;
    unsigned char unk15E;
    unsigned char unk15F;
    unsigned char unk160;
    unsigned char unk161;
    unsigned char unk162;
    unsigned char unk163;
    unsigned char unk164;
    unsigned char unk165;
    unsigned char unk166;
    unsigned char unk167;
    float m_f168;

    void Update(float afValue);
};

// Updates m_f150/m_f154 when afValue exceeds the timer threshold, then calls v54 if m_b158 is set, otherwise calls FUN_007fecc0 when afValue exceeds m_f168.
// @fnv 0x007feb80
void FUN_007feb80_cls::Update(float afValue)
{
    if ((double)(afValue - m_f150) > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TimerSource *>(&::g_011db5b4)))))))
    {
        m_f150 = afValue;
        m_f154 = (float)((std::rand() % 1000) * ::DAT_01016978);
    }
    if (m_b158 != 0)
    {
        v54(afValue);
    }
    else if (afValue > m_f168)
    {
        reinterpret_cast<::FUN_007fecc0_Class *>(this)->FUN_007fecc0();
    }
}

struct FloatSource
{
};

struct IntSource
{
};


struct Timer
{
    char pad[0x158];
    bool unk158;
    float unk15c;
    float unk160;
    float unk164;
    float unk168;
    void FUN_007fec30(float now);
};

// @fnv 0x007fec30
void Timer::FUN_007fec30(float now)
{
    float delta = now - unk15c;
    unk160 = delta / unk164;
    if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSource *>(&::g_011db520)))))) + ::g_01012070 < unk160)
    {
        unk158 = false;
        unk168 = (float)(std::rand() % *((int *)&(::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::IntSource *>(&::g_011db4f8))))))) + now;
    }
}

struct xColorA
{
    xColorA(float, float, float, float);
    float r, g, b, a;
};
struct xPoint3
{
    xPoint3(float, float, float);
    float x, y, z;
};
struct xMat3
{
    xMat3();
    xMat3 FUN_0043f8d0(const xMat3&) const;
    float m[9];
};
struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger, m_usTrailingValue;
};
struct xFrustum
{
    xFrustum(bool);
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
};
struct xBound
{
};
struct xNiMem
{
};

struct xAV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual struct xAV* GetNode();
    virtual void v4();
    virtual void v5();
    virtual struct xAV* GetGeom();
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual struct xAV* GetObjectByName(const ::NiFixedString&);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(struct xAV*, bool);
};

struct xCam : xAV
{
    xCam();
    int m_auiShapeKeys[(0x114 - 4) / 4];
};
struct xLight : xAV
{
    xLight();
    void FUN_0050dd50(const xPoint3&);
    int m_auiShapeKeys[(0xfc - 4) / 4];
};
struct xAlpha : xNiMem
{
    xAlpha();
    int m_auiShapeKeys[7];
};
struct xGO
{
    void FUN_0066b0d0(void*);
    xAV* m_p;
};
struct xColorMgr
{
};
struct ClockSource
{
};
struct xIntSetting
{
};
struct xFltSetting
{
};
struct xLoader
{
};
struct xT2
{
};
struct xT1
{
};

struct xFarObj
{
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
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual float GetFar();
};

struct xShadow
{
};

static const char s_szScreen[] = "Screen";
static const char s_szSexBtn[] = "SexBtn:0";
static const char s_szRaceBtn[] = "RaceBtn:0";
static const char s_szFaceBtn[] = "FaceBtn:0";
static const char s_szBodyBtn[] = "BodyBtn:0";
static const char s_szSexGlow[] = "SexGlow:0";
static const char s_szRaceGlow[] = "RaceGlow:0";
static const char s_szFaceGlow[] = "FaceGlow:0";
static const char s_szBodyGlow[] = "BodyGlow:0";
extern const char s_litEnd7fc970[] = "";

struct xRenderedMenu
{
    int m_pad00[0xd8 / 4];
    xGO m_d8, m_dc, m_e0, m_e4, m_e8, m_ec, m_f0, m_f4, m_f8, m_fc;
    int m_100;
    xGO m_104;
    int m_pad108[(0x150 - 0x108) / 4];
    float m_150, m_154;
    bool m_158;
    int m_15c, m_160;
    float m_164, m_168;
    int FUN_009b6600();
    void Init();
};

// Initializes the rendered menu by loading the screen model, configuring its transform and camera, and setting up the terminal light.
// @fnv 0x007fc970
void xRenderedMenu::Init()
{
    float qahtre;
    m_158 = false;
    m_168 = (double)::fnv::timer::Time() + std::rand() % *((int *)&(::FUN_0043d4d0((::Setting *)&((*reinterpret_cast<::xIntSetting *>(&::g_011db4f8))))));
    m_164 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db4d0))))));
    xColorA qHXYKT(0.0f, 0.0f, 0.0f, 0.0f);
    if (reinterpret_cast<::SystemColorManager *>((((::xColorMgr *)(::FUN_00718b60()))))->GetColor(3, (::NiColor &)(qHXYKT)))
        reinterpret_cast<::FUN_007f7fb0_Class *>(this)->FUN_007f7fb0((const ::FUN_007f7fb0_Value *)&(qHXYKT));
    xAV* qdqWL = 0;
    if (!((::xAV *)(::FUN_00559450((int *)&(m_f8)))))
    {
        qdqWL = ((::xAV *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::xLoader * *>(&::g_modelLoader))))->FUN_00447080((char *)(((const char *)(reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((((::xT2 *)(reinterpret_cast<::FUN_00a03c90_shell *>((((::xT1 *)(reinterpret_cast<::RenderedMenuFields *>(this)->m_pFourthMenuObject))))->FUN_00a03c90()))))->FUN_007fd640()))), 0, true, false, false,
                                                false)));
        m_f8.FUN_0066b0d0(qdqWL);
        ::UpdateObjectVisibility((::NiAVObject *)(qdqWL));
    }
    else
    {
        qdqWL = ((::xAV *)(::FUN_00559450((int *)&(m_f8))));
    }
    reinterpret_cast<::FUN_00440490_shell *>((qdqWL))->FUN_00440490(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db544)))))));
    reinterpret_cast<::FUN_004dc540_shell *>(this)->FUN_004dc540((::NiAVObject *)(qdqWL));
    xAV* qSuoDt = qdqWL->GetObjectByName(::NiFixedString(s_szScreen));
    reinterpret_cast<::MenuStub *>(this)->FUN_007fae70(0);
    reinterpret_cast<::FUN_00810530_c *>(this)->FUN_00810530(false);
    m_fc.FUN_0066b0d0(0);
    m_104.FUN_0066b0d0(0);
    m_d8.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szSexBtn)));
    m_dc.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szRaceBtn)));
    m_e0.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szFaceBtn)));
    m_e4.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szBodyBtn)));
    m_e8.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szSexGlow)));
    m_ec.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szRaceGlow)));
    m_f0.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szFaceGlow)));
    m_f4.FUN_0066b0d0(qdqWL->GetObjectByName(::NiFixedString(s_szBodyGlow)));
    m_150 = 0.0f;
    m_154 = 0.0f;
    reinterpret_cast<::FUN_008d7f00_class *>(this)->FUN_008d7f00(0.0f);
    xMat3 qpqRa;
    xMat3 qjXCGmG;
    reinterpret_cast<::ThreeByThreeMatrix *>(&(qpqRa))->SetYRotation(1.57f);
    reinterpret_cast<::FUN_004a0c90_shell *>(&(qjXCGmG))->FUN_004a0c90(1.57f);
    reinterpret_cast<::FUN_0043fa80_s *>((qdqWL))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((const ::xMat3 &)(qjXCGmG.FUN_0043f8d0(qpqRa))));
    float qhxpxJd = 0.0f;
    if (FUN_009b6600() == 1 || FUN_009b6600() == 0)
        qhxpxJd = 80.0f;
    else
        qhxpxJd = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db570))))));
    if (!::FUN_00707b50() && !::DAT_011f9426)
        qhxpxJd *= 0.75;
    if (FUN_009b6600() == 1 || FUN_009b6600() == 0)
        reinterpret_cast<::FUN_004bc1f0_S *>((qdqWL))->FUN_004bc1f0(qhxpxJd, 0.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db5cc)))))));
    else
        reinterpret_cast<::FUN_004bc1f0_S *>((qdqWL))->FUN_004bc1f0(qhxpxJd, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db594)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db5cc)))))));
    xUpdateData qsSDDgz(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((qdqWL))->FUN_00a59c60((std::intptr_t)&(qsSDDgz));
    xCam* qSVM = new xCam();
    xColorA qrEZrs(0.0f, 1.0f, 1.0f, 0.0f);
    reinterpret_cast<::_Cam_00712e60 *>((qSVM))->FUN_00712e60((const ::_Rect16_00712e60 &)(qrEZrs));
    xMat3 qbGYp;
    reinterpret_cast<::M3_ *>(&(qbGYp))->SetElement(0, 0.0f, 0.0f, 1.0f);
    reinterpret_cast<::M3_ *>(&(qbGYp))->SetElement(1, 1.0f, 0.0f, 0.0f);
    reinterpret_cast<::M3_ *>(&(qbGYp))->SetElement(2, 0.0f, 1.0f, 0.0f);
    reinterpret_cast<::FUN_0043fa80_s *>((qSVM))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((*reinterpret_cast<::xMat3 *>(&::DAT_011a9448))));
    reinterpret_cast<::FUN_00733fd0_shell *>((qSVM))->FUN_00733fd0(1.0f);
    xFrustum qnuVZg(false);
    qnuVZg.m_fFarPlane = ((::xFarObj *)(::FUN_0045c670()))->GetFar();
    qnuVZg.m_fNearPlane = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_01203144))))));
    reinterpret_cast<::FUN_00507700_cls *>((qSVM))->FUN_00507700(qnuVZg.m_fFarPlane / qnuVZg.m_fNearPlane);
    float qvyWyw = (float)(::DAT_011f9426 ? ::DAT_011f9434 : ::FUN_004dc200()) / ((int)(::FUN_004dc1f0()));
    float qkbsJ = 0.75f;
    qahtre = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_01203150)))))) * 0.01745329238474369 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db5ec))))));
    qnuVZg.m_fLeftBound = -::FUN_0057dd70(qahtre) * qkbsJ;
    qnuVZg.m_fRightBound = ::FUN_0057dd70(qahtre) * qkbsJ;
    qnuVZg.m_fBottomBound = -::FUN_0057dd70(qahtre) * qvyWyw * qkbsJ;
    qnuVZg.m_fTopBound = ::FUN_0057dd70(qahtre) * qvyWyw * qkbsJ;
    qnuVZg.m_bOrthographic = false;
    reinterpret_cast<::NiCamera *>((qSVM))->UpdateViewFrustum((const ::NiFrustum &)(qnuVZg));
    ::UpdateCameraFrustum((::NiCamera *)(qSVM), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011db5ec)))))));
    xUpdateData qfTOqo(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((qSVM))->FUN_00a59c60((std::intptr_t)&(qfTOqo));
    reinterpret_cast<::FUN_007fd620_Class *>(this)->SetGo(qSVM);
    if (qSuoDt->GetGeom())
        reinterpret_cast<::FOPipboyManager *>(this)->SetScreen((::NiAVObject *)(::xAV *)(qSuoDt->GetGeom()));
    else if (qSuoDt->GetNode())
        reinterpret_cast<::FOPipboyManager *>(this)->SetScreen((::NiAVObject *)(::xAV *)(((::xAV *)(reinterpret_cast<::NiNode *>((qSuoDt->GetNode()))->GetAt(0)))->GetGeom()));
    reinterpret_cast<::FUN_004dc540_shell *>(this)->FUN_004dc540((::NiAVObject *)(qdqWL));
    reinterpret_cast<::ExtraOwnerB *>((((::xAV *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950()))))->FUN_00a5b230(::FUN_0040df90());
    reinterpret_cast<::FUN_00439410_cls *>((((::xAV *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950()))))->FUN_00439410((::ArgObject *)(void *)(new xAlpha()));
    float qzzQr = reinterpret_cast<::Twin_0084d030 *>((((::xBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((qdqWL))->FUN_0043d450()))))->GetStoredFloatValue() * 3.0;
    void* qpTd = ((void *)(reinterpret_cast<::SSN_b5 *>((((::xShadow *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)))))->FUN_00b5ca70((::Node_b5 *)(qdqWL), qzzQr)));
    if (!qpTd)
    {
        xLight* PLIGHT = new xLight();
        qdqWL->AttachChildInAvailableSlot(PLIGHT, true);
        reinterpret_cast<::FUN_00440460_S *>((PLIGHT))->FUN_00440460((const ::V3 *)&(const ::xPoint3 &)(xPoint3(0.0f, -50.0f, 0.0f)));
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((PLIGHT))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)((const ::xPoint3 &)(xPoint3(0.75f, 0.75f, 0.75f))));
        PLIGHT->FUN_0050dd50(xPoint3(1000.0f, 0.0f, 0.0f));
        reinterpret_cast<::NiPointLight *>((PLIGHT))->FUN_0050dd20(1.0f);
        xUpdateData UPD3(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((PLIGHT))->FUN_00a59c60((std::intptr_t)&(UPD3));
        reinterpret_cast<::fnv_00b5c940::SSNode *>((((::xShadow *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)))))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(PLIGHT), 0);
        reinterpret_cast<::FUN_007fe560_cls *>(this)->InitTerminalLight();
    }
    reinterpret_cast<::FORenderedMenu *>(this)->OnMenuOpen();
}

namespace fnv_007fe1f0 {
struct RtColor
{
    float r, g, b, a;
    RtColor(float fR, float fG, float fB, float fA);
};

struct RtTexture;
struct RtTarget
{
};
struct RtRenderer
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void SetBackgroundColor(const RtColor& kColor);
    virtual void v044();
    virtual void SetBorderColor(const RtColor& kColor);
};

template <class T> struct RtPtr
{
    T* m_pObject;
    RtPtr(T* pObject);
    ~RtPtr();
    T* FUN_00559450() const;
    RtPtr& FUN_0066b0d0(T* pObject);
};

struct RtTextureData
{
};
struct RtTexture : RtTextureData
{
};

struct RtAccum
{
    int unk00[0xc4 / 4];
    RtAccum(int iUnk);
    ~RtAccum();
};

struct RtSource
{
};

struct RtNode;
struct RenderToTextureImpl
{
    char pad000[0x104];
    RtPtr<RtNode> m_spScene;

    void FUN_007fe1f0(intptr_t a1, int a2, int a3);
};

// Sets a render target and background color, processes m_spScene through render calls, then passes the target to FUN_007fba00.
// @fnv 0x007fe1f0
void RenderToTextureImpl::FUN_007fe1f0(intptr_t aiUnk, int aiUnk2, int aiUnk3)
{
    bool bOverrideTmp = false;
    bOverrideTmp = true;
    RtRenderer* pkRendererY = ((::fnv_007fe1f0::RtRenderer *)(::FUN_0043c4b0()));
    RtPtr<RtTexture> spTarget5(((::fnv_007fe1f0::RtTexture *)(reinterpret_cast<::Pool *>(::FUN_004a0ea0())->FUN_00b6e110(reinterpret_cast<std::uintptr_t>(::FUN_0043c4b0()), 0x30, 0, 0, 0))));
    RtColor kKBorder(0.0f, 0.0f, 0.0f, 0.0f);
    RtColor kBackgroundVal2(0.0f, 0.0f, 0.0f, 0.0f);
    kBackgroundVal2 = (*(const ::fnv_007fe1f0::RtColor *)(reinterpret_cast<::FUN_00503650_shell *>(this)->FUN_00503650()));
    kBackgroundVal2.a = 1.0f;
    if (bOverrideTmp)
        kBackgroundVal2 = RtColor(0.125f, 0.161f, 0.141f, 1.0f);
    pkRendererY->SetBorderColor(kKBorder);
    pkRendererY->SetBackgroundColor(kBackgroundVal2);
    ::FUN_00b6b8d0(7, (::NiRenderTargetGroup *)(void *)(((void *)(reinterpret_cast<::BSRenderedTexture *>((((::fnv_007fe1f0::RtTexture *)(::FUN_00559450((int *)&(spTarget5))))))->GetGroup()))));
    RtAccum kAccumRes(0);
    RtPtr<RtTexture> spSource9(((::fnv_007fe1f0::RtTexture *)(reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((((::fnv_007fe1f0::RtSource *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007fd640())));
    reinterpret_cast<::FUN_004a0fd0_shell *>(&(kAccumRes))->FUN_004a0fd0((::NiNode *)(::fnv_007fe1f0::RtTexture *)(((::fnv_007fe1f0::RtTexture *)(::FUN_00559450((int *)&(spSource9))))));
    reinterpret_cast<::FUN_00c4f270_Class *>(&(kAccumRes))->FUN_00c4f270(1);
    ::FUN_00b6bee0(((::fnv_007fe1f0::RtNode *)(::FUN_00559450((int *)&(m_spScene)))), ((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))), (::BSShaderAccumulator *)(::fnv_007fe1f0::RtAccum *)(&kAccumRes));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(void *)(((::fnv_007fe1f0::RtNode *)(::FUN_00559450((int *)&(m_spScene))))), (::BSShaderAccumulator *)(::fnv_007fe1f0::RtTexture *)(((::fnv_007fe1f0::RtTexture *)(::FUN_00559450((int *)&(spSource9))))), 0);
    reinterpret_cast<::FUN_00c4f2d0_class *>(&(kAccumRes))->FUN_00c4f2d0();
    reinterpret_cast<::FUN_004a0fd0_shell *>(&(kAccumRes))->FUN_004a0fd0((::NiNode *)(::fnv_007fe1f0::RtTexture *)(0));
    spSource9.FUN_0066b0d0(0);
    ::BSRenderedTexture::EndAllAndResetRendererState();
    reinterpret_cast<::Rendered82 *>(this)->FUN_007fba00((void *)(aiUnk), (void *)(0), (::Target82 *)(::fnv_007fe1f0::RtTexture *)(((::fnv_007fe1f0::RtTexture *)(::FUN_00559450((int *)&(spTarget5))))));
    reinterpret_cast<::Manager *>((((::fnv_007fe1f0::RtTarget *)(::FUN_004a0ea0()))))->FUN_00b6da10({});
    spTarget5.FUN_0066b0d0(0);
}
}  // namespace fnv_007fe1f0

#include "generated/data/fallout/interface/forenderedmenuracesex.inc"
