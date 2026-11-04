// fallout/interface/forenderedmenu.cpp: FORenderedMenu, MenuStub, FOPipboyManager, HOLDER and more (44 functions)

#include "fnv/av_object_fields.h"
#include "fallout/interface/tile_fields.h"
#include <cstdint>
#include <new>
#include <cstdlib>
#include "fnv/decl/B5Owner.h"
#include "fnv/decl/BB97550Shader.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/BSRenderedTexture.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CamLook.h"
#include "fnv/decl/CameraState4E9.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00438230_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00476ae0_class.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004a1040_Helper.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_0054b800_class.h"
#include "fnv/decl/FUN_005e3fc0_shell.h"
#include "fnv/decl/FUN_00644640_shell.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_00792780_Class.h"
#include "fnv/decl/FUN_007fa970_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00884f80_shell.h"
#include "fnv/decl/FUN_008b3a80_Class.h"
#include "fnv/decl/FUN_008c51c0_shell.h"
#include "fnv/decl/FUN_008eeaa0Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a03d40_shell.h"
#include "fnv/decl/FUN_00a079d0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/ImageSpaceManager.h"
#include "fnv/decl/InputManager.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/PartialScreenGeometryReceiver.h"
#include "fnv/decl/PipboyStub.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/RaceSexMenuCamera.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/decl/fnv_00439390__NiObjectNET.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00494740__FUN_00494740_t.h"
#include "fnv/decl/fnv_00496080__FUN_00496080_shell.h"
#include "fnv/decl/fnv_004985f0__FUN_004985f0_s.h"
#include "fnv/decl/fnv_004bc450__FUN_004bc450_S.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00871dc0__FUN_00871dc0_class.h"
#include "fnv/decl/fnv_00897910__AnimOwner.h"
#include "fnv/decl/fnv_008b6200__FUN_008b6200.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00a59e20__NiAVObject.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_004e9000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d2000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_007f8000.h"
#include "fnv/symbols_007fd000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01203000.h"
#include "forenderedmenu_decls.h"
#include <windows.h>
#include "fnv/symbols_007fa000.h"

const char kRenderedMenuBurstSound[] = "UIPipBoyStatic";

// @fnv 0x0063d040
void FORenderedMenu::GetCurrentTimeMilliseconds()
{
    m_pRenderedMenuObject.operator NiAVObject*();
}

// Enables the burst, stores duration and intensity, records the start timestamp, and optionally plays the burst sound.
// @fnv 0x007fb150
void FORenderedMenu::StartBurst(float duration, float intensity, float soundChance)
{
    m_bBurstActive = true;
    fBurstDuration = duration;
    m_fBurstSoundChance = intensity;
    m_fBurstIntensity = intensity;
    m_fBurstElapsedTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();

    if (g_burstSoundEnabled && RandomBoolean(soundChance))
    {
        SoundPlaybackHandle soundHandle;
        soundHandle = ::FUN_00453a70()->GetSoundHandleByEditorID(kRenderedMenuBurstSound, 0x121);
        reinterpret_cast<::FUN_00ad8830_shell *>(&(soundHandle))->FUN_00ad8830(false);
    }
}

// Creates a BSShaderAccumulator, loads the Pipboy screen texture as default, copies blur settings from globals and marks the menu initialized.
// @fnv 0x007fc150
void FORenderedMenu::OnMenuOpen()
{
    m_pMenuLightNode = new BSShaderAccumulator(BSShaderManager::Interface, 1, 0x2f7);
    reinterpret_cast<::FUN_004a1040_Helper *>(((m_pMenuLightNode).operator->()))->Set(10);
    NiTexture* pTexture = 0;
    NiPointer<NiTexture> kTexture(0);
    BSShaderManager::GetTexture("Data\\Textures\\Pipboy3000\\screen.dds", true, kTexture, true, false);
    pTexture = kTexture;
    if (!pTexture)
        ::FUN_005b5e40();
    SetDefaultTexture(pTexture);
    fBlurRadius = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db44c))))))->f;
    fBlurIntensity = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db470))))))->f;
    BSShaderManager::GetTexture(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db3d8))))->GetMenuTitle())), true, m_pMenuLightShadowNode, false, false);
    bInitialized = true;
}

// @fnv 0x007fc2d0
void FOPipboyManager::FUN_007fc2d0(NiAVObject* object)
{
    NiProperty* material;
    {
        NiProperty* textureProperty = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((NiGeometry*)object)))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));
        reinterpret_cast<::FUN_00438230_Class *>((textureProperty))->FUN_00438230((::NiNode *)(::NiTexture *)(m_pDefaultTexture));
        if (!((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((NiGeometry*)object)))->FUN_00a59d30(0))))
        {
            NiAlphaProperty* alpha = new NiAlphaProperty;
            reinterpret_cast<::FUN_0049ed90_shell *>((alpha))->FUN_0049ed90(false);
            reinterpret_cast<::NiObjectNET *>((alpha))->FUN_00439340(6);
            reinterpret_cast<::fnv_00439390::NiObjectNET *>((alpha))->FUN_00439390(0);
            reinterpret_cast<::FUN_00439410_cls *>((object))->FUN_00439410((::ArgObject *)(alpha));
        }
    }
    material = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((NiGeometry*)object)))->FUN_00a59d30(FUN_004af350())));
    if (material)
        reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>((material))->FUN_004bc450((const ::fnv_004bc450::C3 *)(const ::NiColor *)(&::DAT_011f4998));
    reinterpret_cast<::FUN_00a5a040_Class *>((object))->FUN_00a5a040();
    NiUpdateData data(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((object))->FUN_00a59c60((std::intptr_t)&(data));
}

// @fnv 0x007fc2b0
void FORenderedMenu::SetDefaultTexture(NiTexture* texture)
{
    m_pDefaultTexture = texture;
}

struct NP
{
    ~NP();
    void* p;
};
struct FUN_007fad10
{
    virtual ~FUN_007fad10();
    NP np04;
    NP np08;
    NP np0c;
    NP np10;
    NP np14;
    char pad18[4];
    NP np1c;
    char pad20[4];
    NP np24;
    char pad28[0x94];
    NP npbc;
    char pad_c0[0x14];
    NP npd4;
};
struct FUN_007fc6f0_shell : public FORenderedMenu
{
    void FUN_007fc6f0();
};
// @fnv 0x007fc400
bool FORenderedMenu::CreateMenuLight(const char* nodeName, ShadowSceneNode* shadowNode)
{
    ShadowSceneNode* pResolvedShadowNode;
    bool bSuccess = false;
    pResolvedShadowNode = shadowNode ? shadowNode : ::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
    if (((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>(this)->GetRegionMapName())))
    {
        reinterpret_cast<::FUN_007fc6f0_shell *>(this)->FUN_007fc6f0();
        NiNode* pNode;
        NiAVObject* pObject = ((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>(this)->GetRegionMapName()))->GetObjectByName(NiFixedString(nodeName));
        pNode = 0;
        if (pObject)
            pNode = pObject->GetAsNiNode();
        if (pNode)
        {
            m_pMenuLight = new NiPointLight;
            NiPoint3 kTranslate = pNode->FUN_0043c490();
            reinterpret_cast<::FUN_00440460_S *>(((m_pMenuLight).operator->()))->FUN_00440460((const ::V3 *)&(kTranslate));
            reinterpret_cast<::fnv_00b5c940::SSNode *>((pResolvedShadowNode))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(::NiLight *)((NiLight*)(NiPointLight*)m_pMenuLight), true);
            m_pSecondaryMenuObject = pResolvedShadowNode;
            ((::NiNode *)(reinterpret_cast<::NiAVObjectFields *>((pNode))->m_pkParent))->AddObject(m_pMenuLight, true);
            NiUpdateData kData(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>(((m_pMenuBackgroundScreenGeometry).operator->()))->FUN_00a59c60((std::intptr_t)&(kData));
            reinterpret_cast<::TaskQueueInterface *>(((m_pMenuLight).operator->()))->QueueActorDisarm(true);
            ::AssignFixedString((char *)((m_pMenuLight).operator->()), (std::intptr_t)&(const ::NiFixedString &)(NiFixedString("RenderedMenuLight")), {});
            bSuccess = true;
        }
        else
        {
            NiAVObject* light = ((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>(this)->GetRegionMapName()))->GetObjectByName(NiFixedString("RenderedMenuLight"));
            if (light)
            {
                m_pMenuLight = (NiPointLight*)((::NiAVObject *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4a98)), (::NiObject *)(light))));
                if (m_pMenuLight)
                    bSuccess = true;
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
    }
    return bSuccess;
}

struct Flt
{
    operator unsigned int() const;
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct ExtraDataList
{
};
struct LightNodeV
{
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
    virtual void AttachLight(unsigned int);
};
// @fnv 0x007fc6f0
void FUN_007fc6f0_shell::FUN_007fc6f0()
{
    if (*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x1c))
    {
        if (((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>((reinterpret_cast<FORenderedMenu*>(this)))->GetRegionMapName()))->GetAsNiNode())
        {
            reinterpret_cast<LightNodeV*>(((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>((reinterpret_cast<FORenderedMenu*>(this)))->GetRegionMapName()))->GetAsNiNode())
                ->AttachLight(*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x1c));
        }
        reinterpret_cast<::B5Owner *>(((*reinterpret_cast<ExtraDataList**>(&this->m_pSecondaryMenuObject))))->FUN_00b5eed0((std::uintptr_t)(reinterpret_cast<NiAVObject*>(
                (unsigned int)*reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x1c))));
        *reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x1c) = 0;
    }
}


// @fnv 0x007f8160
void FUN_007f8160(char value)
{
    DAT_0118abb1 = value;
}

struct FUN_007fadf0_shell : public FORenderedMenu
{
    void FUN_007fadf0();
};
// @fnv 0x007fad10
FUN_007fad10::~FUN_007fad10()
{
    reinterpret_cast<::FUN_007fadf0_shell *>(this)->FUN_007fadf0();
}

// Calls the base FORenderedMenu function, then zeroes several fields at offsets 4 through 0xd4 and a byte at 0x28.
// @fnv 0x007fadf0
void FUN_007fadf0_shell::FUN_007fadf0()
{
    reinterpret_cast<::FUN_007fc6f0_shell *>((reinterpret_cast<FORenderedMenu*>(this)))->FUN_007fc6f0();
    reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 4)->operator=(0);
    reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x14)->operator=(0);
    reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0xc)->operator=(0);
    reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x10)->operator=(0);
    reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x1c)->operator=(0);
    reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0x24)->operator=(0);
    reinterpret_cast<NP_0081c630*>(reinterpret_cast<char*>(this) + 0xd4)->operator=(0);
    *reinterpret_cast<char*>(&this->bInitialized) = 0;
}

// @fnv 0x007faef0
unsigned char GetByteAtOffsetB9(void* thisPtr)
{
    return ((unsigned char*)thisPtr)[0xb9];
}


// @fnv 0x007fdf30
char* FUN_007fdf30()
{
    return DAT_011f35cc;
}

struct FUN_0087d6c0_shell
{
    float FUN_0087d6c0();
};

// @fnv 0x0087d6c0
float FUN_0087d6c0_shell::FUN_0087d6c0()
{
    return 1.0f;
}

struct FUN_00706060_shell
{
    float FUN_00706060();
};
// Returns the float from GetFieldB4Float at g_011db63c if that pointer is non-null, otherwise returns 1.0f.
// @fnv 0x00706060
float FUN_00706060_shell::FUN_00706060()
{
    return (unsigned int)(*reinterpret_cast<::Flt *>(&::g_011db63c)) ? GetFieldB4Float((char*)(uintptr_t)(*reinterpret_cast<::Flt *>(&::g_011db63c))) : 1.0f;
}

struct HOLDER
{
    void* DestroyHolder(unsigned int);
};
// Runs the destructor on this object, frees it with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x007face0
void* HOLDER::DestroyHolder(unsigned int flags)
{
    ((FUN_007fad10*)this)->FUN_007fad10::~FUN_007fad10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct MenuStub
{
    char _p00[0x1c];
    Flt unk1c;
    char _p1d[0x30];
    bool b4d;
    char _p4e[0x12];
    bool b60;
    char _p61[0x58];
    bool bB9;
    void ResetMenuState();
    void FUN_007fae70(intptr_t);
};
// Clears the bB9, b4d and b60 flags, culls the object at unk1c if set, and calls FUN_007fae70(0).
// @fnv 0x007fb0b0
void MenuStub::ResetMenuState()
{
    bB9 = 0;
    b4d = 0;
    b60 = 0;
    if (unk1c)
        reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)(uintptr_t)unk1c)))->QueueActorDisarm(true);
    FUN_007fae70(0);
}

struct S007fb100
{
    char _0[0x95];
    unsigned char b95;
    char _96[2];
    float f98;
    float f9c;
    void FUN_007fb100();
};
// Sets b95 to 1, stores the current global timestamp in f98, and resets f9c to 0.0f.
// @fnv 0x007fb100
void S007fb100::FUN_007fb100()
{
    b95 = 1;
    f98 = (float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    f9c = 0.0f;
}

struct FUN_007fb250_owner
{
    char pad00[0x60];
    bool unk60;
    char pad61[0x3];
    float unk64;
    float unk68;
    float unk6c;
    float unk70;

    void FUN_007fb250(float afDuration, float afIntensity);
};
// @fnv 0x007fb250
void FUN_007fb250_owner::FUN_007fb250(float afDuration, float afIntensity)
{
    this->unk60 = true;
    this->unk68 = afDuration;
    this->unk6c = afIntensity * (double)0.0001f;
    this->unk64 = (float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    this->unk70 = 0.0f;
}

namespace fnv_007fb420 {
struct MenuStub
{
    char pad00[0x4d];
    bool unk4d;
    char pad4e[0x2];
    float unk50;
    float unk54;
    float unk58;
    float unk5c;

    void FUN_007fb420(float afTime);
};
// @fnv 0x007fb420
void MenuStub::FUN_007fb420(float afTime)
{
    float fintensityValue = afTime - this->unk50;
    if (fintensityValue > this->unk54)
        this->unk4d = 0;
    else
    {
        float fRemaining = 1.0F - fintensityValue / this->unk54;
        this->unk5c = this->unk58 * fRemaining;
    }
}
}  // namespace fnv_007fb420

struct HackLight
{
    NiAVObject* FUN_007fc6f0();
};
struct MyMenu : public FORenderedMenu
{
    void FUN_007ffdb0();
};
// @fnv 0x007ffdb0
void MyMenu::FUN_007ffdb0()
{
    NiAVObject* light = ((HackLight*)this)->FUN_007fc6f0();
    if (light)
    {
        reinterpret_cast<::FUN_00440460_S *>((light))->FUN_00440460((const ::V3 *)&(*(NiPoint3*)((char*)this + 0xD8)));
        NiUpdateData upd(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((light))->FUN_00a59c60((std::intptr_t)&(upd));
    }
}

class Tile;
struct Interface
{
    void FUN_007fa8d0(bool flag);
public:
    static ::Tile *GetPrimaryInterfaceTile();
};
// Sets the app-culled flag on both the root node and the node returned by FUN_007fa970, if both exist.
// @fnv 0x007fa8d0
void Interface::FUN_007fa8d0(bool abCulled)
{
    if (!((::NiNode *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950())) || !((::NiNode *)(reinterpret_cast<::FUN_007fa970_Class *>(this)->FUN_007fa970())))
        return;
    if (abCulled)
    {
        reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950()))))->QueueActorDisarm(true);
        reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::FUN_007fa970_Class *>(this)->FUN_007fa970()))))->QueueActorDisarm(true);
    }
    else
    {
        reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950()))))->QueueActorDisarm(false);
        reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::FUN_007fa970_Class *>(this)->FUN_007fa970()))))->QueueActorDisarm(false);
    }
}

namespace fnv_007fb040 {
struct Menu;
struct Tile
{
};
struct Menu
{
};
struct Interface
{
};
struct FUN_00a079d0_shell
{
};
struct FUN_007fb040_shell : public MenuStub
{
    void FUN_007fb040();
};
// @fnv 0x007fb040
void FUN_007fb040_shell::FUN_007fb040()
{
    if (((::NiNode *)(reinterpret_cast<::NiAVObjectFields *>((reinterpret_cast<NiAVObject*>(this)))->m_pkParent)))
        ::FUN_00867a20((void *)(reinterpret_cast<Menu*>(((::fnv_007fb040::Menu *)(reinterpret_cast<::FUN_00a03c90_shell *>((reinterpret_cast<Tile*>(((::NiNode *)(reinterpret_cast<::NiAVObjectFields *>((reinterpret_cast<NiAVObject*>(this)))->m_pkParent)))))->FUN_00a03c90())))));
    reinterpret_cast<::FUN_00a079d0_shell *>((((FUN_00a079d0_shell*)((::fnv_007fb040::Tile *)(::Interface::GetPrimaryInterfaceTile())))))->UpdateTileChildren();
    if (unk1c.operator unsigned int())
        reinterpret_cast<::TaskQueueInterface *>((reinterpret_cast<NiAVObject*>(unk1c.operator unsigned int())))->QueueActorDisarm(false);
    bB9 = true;
}
}  // namespace fnv_007fb040

struct Tile
{
};
struct Menu;
struct FUN_007fc8d0_shell : public FORenderedMenu
{
    void FUN_007fc8d0();
};
// Looks up three tiles by id and, for each enabled flag at offsets 0xd2/0xd0/0xd1, un-culls that tile's node.
// @fnv 0x007fc8d0
void FUN_007fc8d0_shell::FUN_007fc8d0()
{
    Tile* pquantity2 = (Tile*)((::Menu *)(::FUN_00a09030(0x3e9)));
    Tile* pmessage = (Tile*)((::Menu *)(::FUN_00a09030(0x3f8)));
    Tile* ptutorial = (Tile*)((::Menu *)(::FUN_00a09030(0x423)));
    if (*(unsigned char*)&this->m_bMenuLightAttached)
        reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::TileFields *>((pquantity2))->renderedNode))))->QueueActorDisarm(false);
    if (*(unsigned char*)&this->m_bMenuLightVisible)
        reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::TileFields *>((pmessage))->renderedNode))))->QueueActorDisarm(false);
    if (*(unsigned char*)&this->m_bMenuLightShadowed)
        reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::TileFields *>((ptutorial))->renderedNode))))->QueueActorDisarm(false);
}

struct S_007fb2b0
{
    char pad00[0x74];
    unsigned char b74;
    char pad75[3];
    float f78;
    float f7c;
    float f80;
    float f84;
    float f88;
    void FUN_007fb2b0(float, float, float);
};
// Sets b74 to 1, stores x, y, z into f7c, f80, f84, records the global timestamp in f78 and clears f88.
// @fnv 0x007fb2b0
void S_007fb2b0::FUN_007fb2b0(float x, float y, float z)
{
    b74 = 1;
    f7c = x;
    f80 = y;
    f84 = z;
    f78 = (float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    f88 = 0.0f;
}

struct GO
{
    void operator=(void*);
};

struct FUN_007fbeb0_shell
{
    char pad1fc[1];
    char pad1fd[1];
    char pad1fe[1];
    GO go1ff;
    void SetValueAndAssign(char, void*);
};

// @fnv 0x007fbeb0
void FUN_007fbeb0_shell::SetValueAndAssign(char value, void* ptr)
{
    ((char*)this + 0x1fc)[0] = value;
    ((GO*)this + 0x1f8)->operator=(ptr);
}

namespace fnv_007fdf10 {
struct GO
{
    GO& operator=(void*);
};

struct FUN_007fdf10_shell
{
    char pad_d4[0xd4];
    GO go_d4;
    void SetGo(void*);
};

// @fnv 0x007fdf10
void FUN_007fdf10_shell::SetGo(void* apValue)
{
    go_d4 = apValue;
}
}  // namespace fnv_007fdf10

float __cdecl FUN_004e44d0(float);
struct FUN_007fb3a0_shell
{
    char pad00[0x74];
    unsigned char unk74;
    char pad75[0x3];
    float unk78;
    float unk7c;
    float unk80;
    float unk84;
    float unk88;

    void FUN_007fb3a0(float afTime);
};
// @fnv 0x007fb3a0
void FUN_007fb3a0_shell::FUN_007fb3a0(float afTime)
{
    float fdelta = afTime - this->unk78;
    if (fdelta > this->unk7c)
    {
        this->unk74 = 0;
    }
    else
    {
        float fRemainder = 1.0f - (fdelta / this->unk7c);
        this->unk88 =
            FUN_004e44d0(fdelta * this->unk84) * this->unk80 * fRemainder;
    }
}

float __cdecl ApplyNoise(float);
struct GlobalObject_0044f440 : SettingT_GameSettingCollection_
{
};

struct FUN_007fb530_shell
{
    char pad00[0x8c];
    float unk8c;
    float unk90;

    void FUN_007fb530(float afDuration);
};

// @fnv 0x007fb530
void FUN_007fb530_shell::FUN_007fb530(float afDuration)
{
    float f04 = ApplyNoise(afDuration * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::g_011db408))))->f) * 2.0f;
    this->unk8c = f04 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::g_011db3a4))))->f;
    this->unk90 = f04 * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::g_011db424))))->f;
}

struct FUN_007f8010_shell : public FORenderedMenu
{
    void FUN_007f8010();
};

struct SndX
{
};

struct TESImageSpaceModifier
{
};

struct ImageSpaceModifierInstanceForm
{
    static void __cdecl Stop(TESImageSpaceModifier*);
};

void __cdecl FUN_004de8c0(float);


// @fnv 0x007f8010
void FUN_007f8010_shell::FUN_007f8010()
{
    if (!reinterpret_cast<::FOPipboyManager *>(this)->IsUnk28Set())
        return;

    reinterpret_cast<Interface*>(this)->FUN_007fa8d0(false);
    reinterpret_cast<::PipboyStub *>(this)->FUN_007f7f40();

    DAT_011d890a = 1;
    g_burstSoundEnabled = 1;

    ::fnv_00702c80::FUN_00702c80(true, true);

    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x154)))->FUN_00ad88f0();
    reinterpret_cast<::SoundPlaybackHandle *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x154)))->Release();

    reinterpret_cast<SoundPlaybackHandle*>(reinterpret_cast<char*>(this) + 0x154)
        ->
        operator=(::FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyHumLP", 0x31));

    reinterpret_cast<::FUN_00ad8830_shell *>((reinterpret_cast<SoundPlaybackHandle*>(reinterpret_cast<char*>(this) + 0x154)))->FUN_00ad8830(false);

    StartBurst(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::g_011db480))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(::g_011db43c))))->f, 0.5f);

    reinterpret_cast<::fnv_007fb040::FUN_007fb040_shell *>(this)->FUN_007fb040();

    ImageSpaceModifierInstanceForm::Stop(::FUN_005d2860());

    FUN_007f8160(0);
    FUN_004de8c0(0.0f);
}

// @fnv 0x007fae70
void MenuStub::FUN_007fae70(intptr_t apTexture)
{
    NiProperty* pnlp;

    if ((*reinterpret_cast<unsigned char*>(&this->_p1d[11])) == 0)
        return;

    if (reinterpret_cast<Flt*>(&this->_p00[4])->operator unsigned int() == 0)
    {
        ::FUN_005b5e40();
        return;
    }

    pnlp = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((reinterpret_cast<NiGeometry*>(
               reinterpret_cast<Flt*>(&this->_p00[4])->operator unsigned int())))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));

    if (apTexture != 0)
    {
        reinterpret_cast<::FUN_00438230_Class *>((pnlp))->FUN_00438230((::NiNode *)(::NiTexture *)(reinterpret_cast<NiTexture*>(apTexture)));
    }
    else
    {
        reinterpret_cast<::FUN_00438230_Class *>((pnlp))->FUN_00438230((::NiNode *)(::NiTexture *)(reinterpret_cast<NiTexture*>(
            reinterpret_cast<Flt*>(&this->_p00[16])->operator unsigned int())));
    }
}

struct FUN_007079f0_shell
{
    bool FUN_007079f0();
};


struct FUN_007faf10_shell
{
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
    virtual void v0e(float);
    virtual void v0f(float);
    virtual void v10(float);
    virtual void v11(float);
    virtual void v12(float);
    virtual void v13(float);

    char pad04[0x34];
    float fScreenLightBaseIntensity;
    float m_fFlicker;
    float fBlurRadius;
    float fBlurIntensity;
    float m_fScanlineScale;
    bool m_bDoScanlines;
    bool m_bBurstActive;
    char pad4e[0x12];
    bool m_bBurstSoundPlayed;
    char pad61[0x13];
    bool m_bVerticalHoldActive;
    char pad75[0x20];
    bool m_bShudderActive;
    char pad96[0x0e];
    float m_fDistortTimeRemaining;
    char pada8[0x10];
    bool m_bMenuLightEnabled;

    bool UpdateScreenEffect();
};

// Reads the global time stamp, updates the menu-open state, and drives the screen effect's virtual update methods when the menu is or was open.
// @fnv 0x007faf10
bool FUN_007faf10_shell::UpdateScreenEffect()
{
    bool bmenuOpenPreviousUpdate;
    float fappTime;

    fappTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    bmenuOpenPreviousUpdate = m_bMenuLightEnabled;

    m_bMenuLightEnabled = ((::FUN_007079f0_shell *)(::fnv_004b7210::FUN_004b7210()))->FUN_007079f0();

    if (!m_bMenuLightEnabled && !bmenuOpenPreviousUpdate)
        return false;

    v12(fappTime);

    if (m_bBurstActive)
        v0e(fappTime);

    if (m_bBurstSoundPlayed)
        v0f(fappTime);

    if (m_bVerticalHoldActive)
        v10(fappTime);

    v11(fappTime);

    if (m_bShudderActive)
    {
        v13(fappTime);
    }
    else
    {
        if (fappTime > m_fDistortTimeRemaining)
            reinterpret_cast<S007fb100*>(this)->FUN_007fb100();
    }

    return true;
}

struct FUN_00456630_helper : NiAVObject
{
    bool FUN_00456610();
};

struct FUN_007fc790_shell : public FORenderedMenu
{
    void UpdateMenuVisibility();
};

// @fnv 0x007fc790
void FUN_007fc790_shell::UpdateMenuVisibility()
{
    Tile* pMenu;

    {
        Tile* pOtherMenu = (Tile*)((::Menu *)(::FUN_00a09030(0x3e9)));
        Tile* m_pTerminal = (Tile*)((::Menu *)(::FUN_00a09030(0x3f8)));
        pMenu = (Tile*)((::Menu *)(::FUN_00a09030(0x423)));

        (*(unsigned char*)&this->m_bMenuLightAttached) =
            pOtherMenu ? !((FUN_00456630_helper*)((::NiNode *)(reinterpret_cast<::TileFields *>((pOtherMenu))->renderedNode)))->FUN_00456610() : 0;

        (*(unsigned char*)&this->m_bMenuLightVisible) =
            m_pTerminal ? !((FUN_00456630_helper*)((::NiNode *)(reinterpret_cast<::TileFields *>((m_pTerminal))->renderedNode)))->FUN_00456610() : 0;

        (*(unsigned char*)&this->m_bMenuLightShadowed) = pMenu ? !((FUN_00456630_helper*)((::NiNode *)(reinterpret_cast<::TileFields *>((pMenu))->renderedNode)))->FUN_00456610() : 0;

        if ((*(unsigned char*)&this->m_bMenuLightAttached))
            reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::TileFields *>((pOtherMenu))->renderedNode))))->QueueActorDisarm(true);

        if ((*(unsigned char*)&this->m_bMenuLightVisible))
            reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::TileFields *>((m_pTerminal))->renderedNode))))->QueueActorDisarm(true);

        if ((*(unsigned char*)&this->m_bMenuLightShadowed))
            reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(reinterpret_cast<::TileFields *>((pMenu))->renderedNode))))->QueueActorDisarm(true);
    }
}

struct SettingIntCollection_
{
};


struct DistortMenuView : public FORenderedMenu
{
    void UpdateDistortTimer(float dt);
};

// @fnv 0x007fb310
void DistortMenuView::UpdateDistortTimer(float dt)
{
    float t = dt - m_fDistortHorizontalScale;
    m_fDistortVerticalScale = t / fDistortDuration;
    if (((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db520))))))->f + ::g_01012070 < m_fDistortVerticalScale)
    {
        m_bShudderActive = 0;
        m_fDistortTimeRemaining = (float)(std::rand() % *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingIntCollection_ *>(&::g_011db4f8))))))) + dt;
    }
}

struct FUN_007fb480_Class
{
    unsigned int unk00;
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
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned char unk60;
    float f64;
    float f68;
    float f6c;
    float f70;
    void FUN_007fb480(float a);
};


// @fnv 0x007fb480
void FUN_007fb480_Class::FUN_007fb480(float a)
{
    float d = a - f64;
    if (d > f68)
    {
        unk60 = 0;
        reinterpret_cast<::S_007fb2b0 *>((this))->FUN_007fb2b0(DAT_0101b2d0, DAT_010181bc, DAT_010181bc);
    }
    else
    {
        f70 = d * f6c;
        if ((double)f70 >= 1.0 || (double)f70 < 0.0)
        {
            f70 = f70 - FUN_00404040(f70);
        }
    }
}

struct FloatMatrix3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct Point3
{
    float x, y, z;
    Point3(float, float, float);
};
struct Rect4
{
    float left, right, top, bottom;
    Rect4(float, float, float, float);
};
struct Frustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    Frustum(bool);
};
struct BoundView
{
};
struct NodeView : NiNode
{
};
struct CameraView : NiAVObject
{
};
struct MenuView
{
    int FUN_007dcc00();
};
struct TileView
{
};
struct AnimView
{
};
struct PlayerView;
struct ProcessView
{
    virtual void unkV000();
    virtual void unkV001();
    virtual void unkV002();
    virtual void unkV003();
    virtual void unkV004();
    virtual void unkV005();
    virtual void unkV006();
    virtual void unkV007();
    virtual void unkV008();
    virtual void unkV009();
    virtual void unkV00A();
    virtual void unkV00B();
    virtual void unkV00C();
    virtual void unkV00D();
    virtual void unkV00E();
    virtual void unkV00F();
    virtual void unkV010();
    virtual void unkV011();
    virtual void unkV012();
    virtual void unkV013();
    virtual void unkV014();
    virtual void unkV015();
    virtual void unkV016();
    virtual void unkV017();
    virtual void unkV018();
    virtual void unkV019();
    virtual void unkV01A();
    virtual void unkV01B();
    virtual void unkV01C();
    virtual void unkV01D();
    virtual void unkV01E();
    virtual void unkV01F();
    virtual void unkV020();
    virtual void unkV021();
    virtual void unkV022();
    virtual void unkV023();
    virtual void unkV024();
    virtual void unkV025();
    virtual void unkV026();
    virtual void unkV027();
    virtual void unkV028();
    virtual void unkV029();
    virtual void unkV02A();
    virtual void unkV02B();
    virtual void unkV02C();
    virtual void unkV02D();
    virtual void unkV02E();
    virtual void unkV02F();
    virtual void unkV030();
    virtual void unkV031();
    virtual void unkV032();
    virtual void unkV033();
    virtual void unkV034();
    virtual void unkV035();
    virtual void unkV036();
    virtual void unkV037();
    virtual void unkV038();
    virtual void unkV039();
    virtual void unkV03A();
    virtual void unkV03B();
    virtual void unkV03C();
    virtual void unkV03D();
    virtual void unkV03E();
    virtual void unkV03F();
    virtual void unkV040();
    virtual void unkV041();
    virtual void unkV042();
    virtual void unkV043();
    virtual void unkV044();
    virtual void unkV045();
    virtual void unkV046();
    virtual void unkV047();
    virtual void unkV048();
    virtual void unkV049();
    virtual void unkV04A();
    virtual void unkV04B();
    virtual void unkV04C();
    virtual void unkV04D();
    virtual void unkV04E();
    virtual void unkV04F();
    virtual void unkV050();
    virtual void unkV051();
    virtual void unkV052();
    virtual void unkV053();
    virtual void unkV054();
    virtual void unkV055();
    virtual void unkV056();
    virtual void unkV057();
    virtual void unkV058();
    virtual void unkV059();
    virtual void unkV05A();
    virtual void unkV05B();
    virtual void unkV05C();
    virtual void unkV05D();
    virtual void unkV05E();
    virtual void unkV05F();
    virtual void unkV060();
    virtual void unkV061();
    virtual void unkV062();
    virtual void unkV063();
    virtual void unkV064();
    virtual void unkV065();
    virtual void unkV066();
    virtual void unkV067();
    virtual void unkV068();
    virtual void unkV069();
    virtual void unkV06A();
    virtual void unkV06B();
    virtual void unkV06C();
    virtual void unkV06D();
    virtual void unkV06E();
    virtual void unkV06F();
    virtual void unkV070();
    virtual void unkV071();
    virtual void unkV072();
    virtual void unkV073();
    virtual void unkV074();
    virtual void unkV075();
    virtual void unkV076();
    virtual void unkV077();
    virtual void unkV078();
    virtual void unkV079();
    virtual void unkV07A();
    virtual void unkV07B();
    virtual void unkV07C();
    virtual void unkV07D();
    virtual void unkV07E();
    virtual void unkV07F();
    virtual void unkV080();
    virtual void unkV081();
    virtual void unkV082();
    virtual void unkV083();
    virtual void unkV084();
    virtual void unkV085();
    virtual void unkV086();
    virtual void unkV087();
    virtual void unkV088();
    virtual void unkV089();
    virtual void unkV08A();
    virtual void unkV08B();
    virtual void unkV08C();
    virtual void unkV08D();
    virtual void unkV08E();
    virtual void unkV08F();
    virtual void unkV090();
    virtual void unkV091();
    virtual void unkV092();
    virtual void unkV093();
    virtual void unkV094();
    virtual void unkV095();
    virtual void unkV096();
    virtual void unkV097();
    virtual void unkV098();
    virtual void unkV099();
    virtual void unkV09A();
    virtual void unkV09B();
    virtual void unkV09C();
    virtual void unkV09D();
    virtual void unkV09E();
    virtual void unkV09F();
    virtual void unkV0A0();
    virtual void unkV0A1();
    virtual void unkV0A2();
    virtual void unkV0A3();
    virtual void unkV0A4();
    virtual void unkV0A5();
    virtual void unkV0A6();
    virtual void unkV0A7();
    virtual void unkV0A8();
    virtual void unkV0A9();
    virtual void unkV0AA();
    virtual void unkV0AB();
    virtual void unkV0AC();
    virtual void unkV0AD();
    virtual void unkV0AE();
    virtual void unkV0AF();
    virtual void unkV0B0();
    virtual void unkV0B1();
    virtual void unkV0B2();
    virtual void unkV0B3();
    virtual void unkV0B4();
    virtual void unkV0B5();
    virtual void unkV0B6();
    virtual void unkV0B7();
    virtual void unkV0B8();
    virtual void unkV0B9();
    virtual void unkV0BA();
    virtual void unkV0BB();
    virtual void unkV0BC();
    virtual void unkV0BD();
    virtual void unkV0BE();
    virtual void unkV0BF();
    virtual void unkV0C0();
    virtual void unkV0C1();
    virtual void unkV0C2();
    virtual void unkV0C3();
    virtual void unkV0C4();
    virtual void unkV0C5();
    virtual void unkV0C6();
    virtual void unkV0C7();
    virtual void unkV0C8();
    virtual void unkV0C9();
    virtual void unkV0CA();
    virtual void unkV0CB();
    virtual void unkV0CC();
    virtual void unkV0CD();
    virtual void unkV0CE();
    virtual void unkV0CF();
    virtual void unkV0D0();
    virtual void unkV0D1();
    virtual void unkV0D2();
    virtual void unkV0D3();
    virtual void unkV0D4();
    virtual void unkV0D5();
    virtual void unkV0D6();
    virtual void unkV0D7();
    virtual void unkV0D8();
    virtual void unkV0D9();
    virtual void unkV0DA();
    virtual void unkV0DB();
    virtual void unkV0DC();
    virtual void unkV0DD();
    virtual void unkV0DE();
    virtual void unkV0DF();
    virtual void unkV0E0();
    virtual void unkV0E1();
    virtual void unkV0E2();
    virtual void unkV0E3();
    virtual void unkV0E4();
    virtual void unkV0E5();
    virtual void unkV0E6();
    virtual void unkV0E7();
    virtual void unkV0E8();
    virtual void unkV0E9();
    virtual void unkV0EA();
    virtual void unkV0EB();
    virtual void unkV0EC();
    virtual void unkV0ED();
    virtual void unkV0EE();
    virtual void unkV0EF();
    virtual void unkV0F0();
    virtual void unkV0F1();
    virtual void unkV0F2();
    virtual void unkV0F3();
    virtual void unkV0F4();
    virtual void unkV0F5();
    virtual void unkV0F6();
    virtual void unkV0F7();
    virtual void unkV0F8();
    virtual void unkV0F9();
    virtual void unkV0FA();
    virtual void unkV0FB();
    virtual void unkV0FC();
    virtual void unkV0FD();
    virtual void unkV0FE();
    virtual void unkV0FF();
    virtual void unkV100();
    virtual void unkV101();
    virtual void unkV102();
    virtual void unkV103();
    virtual void unkV104();
    virtual void unkV105();
    virtual void unkV106();
    virtual void unkV107();
    virtual void unkV108();
    virtual void unkV109();
    virtual void unkV10A();
    virtual void unkV10B();
    virtual void unkV10C();
    virtual void unkV10D();
    virtual void unkV10E();
    virtual void unkV10F();
    virtual void unkV110();
    virtual void unkV111();
    virtual void unkV112();
    virtual void unkV113();
    virtual void unkV114();
    virtual void unkV115();
    virtual void SetState(PlayerView*, int);
};
struct PlayerView
{
    virtual void unkV000();
    virtual void unkV001();
    virtual void unkV002();
    virtual void unkV003();
    virtual void unkV004();
    virtual void unkV005();
    virtual void unkV006();
    virtual void unkV007();
    virtual void unkV008();
    virtual void unkV009();
    virtual void unkV00A();
    virtual void unkV00B();
    virtual void unkV00C();
    virtual void unkV00D();
    virtual void unkV00E();
    virtual void unkV00F();
    virtual void unkV010();
    virtual void unkV011();
    virtual void unkV012();
    virtual void unkV013();
    virtual void unkV014();
    virtual void unkV015();
    virtual void unkV016();
    virtual void unkV017();
    virtual void unkV018();
    virtual void unkV019();
    virtual void unkV01A();
    virtual void unkV01B();
    virtual void unkV01C();
    virtual void unkV01D();
    virtual void unkV01E();
    virtual void unkV01F();
    virtual void unkV020();
    virtual void unkV021();
    virtual void unkV022();
    virtual void unkV023();
    virtual void unkV024();
    virtual void unkV025();
    virtual void unkV026();
    virtual void unkV027();
    virtual void unkV028();
    virtual void unkV029();
    virtual void unkV02A();
    virtual void unkV02B();
    virtual void unkV02C();
    virtual void unkV02D();
    virtual void unkV02E();
    virtual void unkV02F();
    virtual void unkV030();
    virtual void unkV031();
    virtual void unkV032();
    virtual void unkV033();
    virtual void unkV034();
    virtual void unkV035();
    virtual void unkV036();
    virtual void unkV037();
    virtual void unkV038();
    virtual void unkV039();
    virtual void unkV03A();
    virtual void unkV03B();
    virtual void unkV03C();
    virtual void unkV03D();
    virtual void unkV03E();
    virtual void unkV03F();
    virtual void unkV040();
    virtual void unkV041();
    virtual void unkV042();
    virtual void unkV043();
    virtual void unkV044();
    virtual void unkV045();
    virtual void unkV046();
    virtual void unkV047();
    virtual void unkV048();
    virtual void unkV049();
    virtual void unkV04A();
    virtual void unkV04B();
    virtual void unkV04C();
    virtual void unkV04D();
    virtual void unkV04E();
    virtual void unkV04F();
    virtual void unkV050();
    virtual void unkV051();
    virtual void unkV052();
    virtual void unkV053();
    virtual void unkV054();
    virtual void unkV055();
    virtual void unkV056();
    virtual void unkV057();
    virtual void unkV058();
    virtual void unkV059();
    virtual void unkV05A();
    virtual void unkV05B();
    virtual void unkV05C();
    virtual void unkV05D();
    virtual void unkV05E();
    virtual void unkV05F();
    virtual void unkV060();
    virtual void unkV061();
    virtual void unkV062();
    virtual void unkV063();
    virtual void unkV064();
    virtual void unkV065();
    virtual void unkV066();
    virtual void unkV067();
    virtual void unkV068();
    virtual void unkV069();
    virtual void unkV06A();
    virtual void unkV06B();
    virtual void unkV06C();
    virtual void unkV06D();
    virtual void unkV06E();
    virtual void unkV06F();
    virtual void unkV070();
    virtual void unkV071();
    virtual void unkV072();
    virtual void unkV073();
    virtual void unkV074();
    virtual void unkV075();
    virtual void unkV076();
    virtual void unkV077();
    virtual void unkV078();
    virtual void unkV079();
    virtual void unkV07A();
    virtual void unkV07B();
    virtual void unkV07C();
    virtual void unkV07D();
    virtual void unkV07E();
    virtual void unkV07F();
    virtual void unkV080();
    virtual void unkV081();
    virtual void unkV082();
    virtual void unkV083();
    virtual void unkV084();
    virtual void unkV085();
    virtual void unkV086();
    virtual void unkV087();
    virtual void unkV088();
    virtual void unkV089();
    virtual void unkV08A();
    virtual void unkV08B();
    virtual void unkV08C();
    virtual void unkV08D();
    virtual void unkV08E();
    virtual void unkV08F();
    virtual void unkV090();
    virtual void unkV091();
    virtual void unkV092();
    virtual void unkV093();
    virtual void unkV094();
    virtual void unkV095();
    virtual void unkV096();
    virtual void unkV097();
    virtual void unkV098();
    virtual void unkV099();
    virtual void unkV09A();
    virtual void unkV09B();
    virtual void unkV09C();
    virtual void unkV09D();
    virtual void unkV09E();
    virtual void unkV09F();
    virtual void unkV0A0();
    virtual void unkV0A1();
    virtual void unkV0A2();
    virtual void unkV0A3();
    virtual void unkV0A4();
    virtual void unkV0A5();
    virtual void unkV0A6();
    virtual void unkV0A7();
    virtual void unkV0A8();
    virtual void unkV0A9();
    virtual void unkV0AA();
    virtual void unkV0AB();
    virtual void unkV0AC();
    virtual void unkV0AD();
    virtual void unkV0AE();
    virtual void unkV0AF();
    virtual void unkV0B0();
    virtual void unkV0B1();
    virtual void unkV0B2();
    virtual void unkV0B3();
    virtual void unkV0B4();
    virtual void unkV0B5();
    virtual void unkV0B6();
    virtual void unkV0B7();
    virtual void unkV0B8();
    virtual void unkV0B9();
    virtual void unkV0BA();
    virtual void unkV0BB();
    virtual void unkV0BC();
    virtual void unkV0BD();
    virtual void SetAngle(float);
};
struct NewScene
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
    NewScene(unsigned);
};
struct NewCamera
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
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    NewCamera();
};
struct EngineView
{
};
struct ControlsView
{
};
struct LoaderView
{
};
struct SettingView
{
};
struct SceneView : NiNode
{
};
struct RendererView
{
    virtual void unkV00();
    virtual void unkV01();
    virtual void unkV02();
    virtual void unkV03();
    virtual void unkV04();
    virtual void unkV05();
    virtual void unkV06();
    virtual void unkV07();
    virtual void unkV08();
    virtual void unkV09();
    virtual void unkV0A();
    virtual void unkV0B();
    virtual void unkV0C();
    virtual void unkV0D();
    virtual void unkV0E();
    virtual void unkV0F();
    virtual void unkV10();
    virtual void unkV11();
    virtual void unkV12();
    virtual void unkV13();
    virtual void unkV14();
    virtual void unkV15();
    virtual void unkV16();
    virtual void unkV17();
    virtual void unkV18();
    virtual void unkV19();
    virtual void unkV1A();
    virtual void unkV1B();
    virtual void unkV1C();
    virtual void unkV1D();
    virtual void unkV1E();
    virtual void unkV1F();
    virtual void unkV20();
    virtual void unkV21();
    virtual void unkV22();
    virtual void unkV23();
    virtual void unkV24();
    virtual void unkV25();
    virtual void unkV26();
    virtual void unkV27();
    virtual void unkV28();
    virtual void unkV29();
    virtual void unkV2A();
    virtual void unkV2B();
    virtual void unkV2C();
    virtual void unkV2D();
    virtual void unkV2E();
    virtual void unkV2F();
    virtual void unkV30();
    virtual void unkV31();
    virtual void unkV32();
    virtual void unkV33();
    virtual void unkV34();
    virtual void unkV35();
    virtual void unkV36();
    virtual void unkV37();
    virtual void unkV38();
    virtual void unkV39();
    virtual void unkV3A();
    virtual void unkV3B();
    virtual void unkV3C();
    virtual void unkV3D();
    virtual void unkV3E();
    virtual void unkV3F();
    virtual float GetScalarValue();
};
struct FUN_007fd6c0_Class
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    void* unk018;
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
    NiPointer<NodeView> root;
    NiPointer<NiNode> scene;
    NiPointer<CameraView> camera;
    NiPointer<NodeView> light;
    NiPointer<Tile> savedTile;
    NiPoint3 savedPosition;
    FloatMatrix3 savedRotation;
    NiPoint3 savedHead;
    bool savedCull;
    void UpdatePlayerFaceScene();
};
struct FUN_007fe930_Class : HackLight
{
    void FUN_007fe930();
};
// @fnv 0x007fe930
void FUN_007fe930_Class::FUN_007fe930()
{
    NiAVObject* pObject = FUN_007fc6f0();
}

class MenuSlotTarget
{
  public:
};

class MenuSlot
{
  public:
    void* m_pFlagTarget;
};

class MenuDriver
{
  public:
    unsigned int unk00[0x3a];
    MenuSlot m_slots[4];
    void UpdateSlotSelection(int a1);
};
// @fnv 0x007fd6c0
void FUN_007fd6c0_Class::UpdatePlayerFaceScene()
{
    reinterpret_cast<::fnv_00871dc0::FUN_00871dc0_class *>(((*reinterpret_cast<::EngineView * *>(&::g_osGlobals))))->FUN_00871dc0();
    DAT_011ad884 = false;
    if (!reinterpret_cast<::FOPipboyManager *>(this)->IsUnk28Set())
        return;
    NiAVObject* frustum = ((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>(this)->GetRegionMapName()));
    NiUpdateData viewport(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((frustum))->FUN_00a59c60((std::intptr_t)&(viewport));
    MenuView* radius = ((::MenuView *)(reinterpret_cast<::FUN_00a03c90_shell *>((((::TileView *)(this->unk018))))->FUN_00a03c90()));
    if (((::NiAVObject *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>(this)->FUN_006838b0())))
        reinterpret_cast<::TaskQueueInterface *>((((::NiAVObject *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>(this)->FUN_006838b0()))))->QueueActorDisarm(false);
    reinterpret_cast<::fnv_007fb040::FUN_007fb040_shell *>(this)->FUN_007fb040();
    ((NiNode*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))->AddObject(((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>(this)->GetRegionMapName())), true);
    reinterpret_cast<::InputManager *>((((ControlsView*)FUN_007fdf30())))->FUN_00a253d0();
    ((::ProcessView *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))))->GetBaseTexture()))->SetState((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer)), 0);
    reinterpret_cast<::FUN_00884f80_shell *>(((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))))->FUN_00884f80();
    reinterpret_cast<::FUN_008b3a80_Class *>(((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))))->ForwardToVtSlot((void *)(0x400));
    reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>((((::AnimView *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))))->GetAnimation(false)))))->FUN_00496080(20, 0.0f);
    reinterpret_cast<::FUN_008eeaa0Class *>((((::AnimView *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))))->GetAnimation(false)))))->FUN_008eeaa0(23);
    reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((((::AnimView *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))))->GetAnimation(false)))))->FUN_00494740(0, 1, -1, -1);
    (*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))->SetAngle(0.0f);
    root = ((::NodeView *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer))))->FUN_00950bb0(false)));
    savedPosition = root->FUN_0043c490();
    savedRotation = (*(::FloatMatrix3 *)(::FUN_006a9540((char *)((root).operator->()))));
    savedHead = root->GetObjectByName(NiFixedString("Bip01"))->FUN_0043c490();
    savedTile = ((::Tile *)(reinterpret_cast<::FUN_009611e0_shell *>(((root).operator->()))->FUN_009611e0()));
    savedCull = reinterpret_cast<::FUN_00456630_helper *>(((root).operator->()))->FUN_00456610();
    scene = (NiNode*)new NewScene(0);
    ((NiNode*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))->AddObject(scene, true);
    light = (NodeView*)reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::LoaderView * *>(&::g_modelLoader))))->FUN_00447080((char *)("Meshes\\Terminals\\PlayerFaceLights01.NIF"), 0, true, false, false,
                                                  false);
    scene->AddObject(root, true);
    scene->AddObject(light, true);
    float menu = reinterpret_cast<::Twin_0084d030 *>((void *)&((*(::BoundView *)(reinterpret_cast<::FUN_0043d450_Owner *>(((root).operator->()))->FUN_0043d450()))))->GetStoredFloatValue() * 3.0;
    reinterpret_cast<::SSN_b5 *>((((SceneView*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))))->FUN_00b5ca70((::Node_b5 *)(::NiNode *)(light->GetAsNiNode()), menu);
    reinterpret_cast<::NiAVObject *>((((NodeView*)(NiNode*)scene)))->SetLocalRotation(3.1415927410125732f, 0.0f, 0.0f, 1.0f);
    reinterpret_cast<::FUN_004bc1f0_S *>(((root).operator->()))->FUN_004bc1f0(0.0f, -5.0f, 0.0f);
    reinterpret_cast<::FUN_0043fa80_s *>(((root).operator->()))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<int *>(&::DAT_011a9448)))));
    NiUpdateData cameraUpdate(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((scene).operator->()))->FUN_00a59c60((std::intptr_t)&(cameraUpdate));
    reinterpret_cast<::fnv_007fdf10::FUN_007fdf10_shell *>((radius))->SetGo(scene);
    camera = (CameraView*)new NewCamera;
    Rect4 up(0.0f, 1.0f, 1.0f, 0.0f);
    reinterpret_cast<::_Cam_00712e60 *>(((camera).operator->()))->FUN_00712e60((const ::_Rect16_00712e60 &)(up));
    reinterpret_cast<::FUN_00733fd0_shell *>(((camera).operator->()))->FUN_00733fd0(1.0f);
    Point3 rootUpdate(0.0f, 1.0f, 0.0f);
    reinterpret_cast<::CamLook *>(((camera).operator->()))->SetLookAt((const ::CamPoint &)(rootUpdate), (const ::CamPoint &)((const ::Point3 &)(Point3(0.0f, 0.0f, 1.0f))));
    Frustum RootUpdate(false);
    RootUpdate.farPlane = ((::RendererView *)(::FUN_0045c670()))->GetScalarValue();
    RootUpdate.nearPlane = ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingView *>(&::g_01203144))));
    reinterpret_cast<::FUN_00507700_cls *>(((camera).operator->()))->FUN_00507700(RootUpdate.farPlane / RootUpdate.nearPlane);
    float angle = (::FUN_00403e20((float *)&((*reinterpret_cast<::SettingView *>(&::g_01203150)))) * 0.01745329238474369) * ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingView *>(&::g_011db5ec))));
    RootUpdate.left = -FUN_0057dd70(angle);
    RootUpdate.right = FUN_0057dd70(angle);
    RootUpdate.bottom = -FUN_0057dd70(angle);
    RootUpdate.top = FUN_0057dd70(angle);
    RootUpdate.ortho = false;
    reinterpret_cast<::NiCamera *>(((camera).operator->()))->UpdateViewFrustum((const ::NiFrustum &)(RootUpdate));
    NiUpdateData menuRoot(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((camera).operator->()))->FUN_00a59c60((std::intptr_t)&(menuRoot));
    reinterpret_cast<::TaskQueueInterface *>(((root).operator->()))->QueueActorDisarm(false);
    reinterpret_cast<::Target *>((radius))->FUN_007b1970(0.5235987901687622f, true);
    reinterpret_cast<::RaceSexMenuCamera *>((radius))->UpdateProgress(0.0f, true);
    reinterpret_cast<::MenuDriver *>(this)->UpdateSlotSelection(radius->FUN_007dcc00());
}

// For each of the 4 slots with a non-null target, applies whether the slot index differs from a1.
// @fnv 0x007fe950
void MenuDriver::UpdateSlotSelection(int aiSelectedIndex)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        if (((::MenuSlotTarget *)(::FUN_00559450((int *)&(m_slots[i])))) != 0)
        {
            reinterpret_cast<::TaskQueueInterface *>((((::MenuSlotTarget *)(::FUN_00559450((int *)&(m_slots[i]))))))->QueueActorDisarm(i != aiSelectedIndex);
        }
    }
}

struct FUN_007ff650_h
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_007ff650_p
{
};

struct FUN_007ff650_q
{
};

struct FUN_007ff650_r
{
};

struct FUN_007ff650_g
{
};


struct FUN_007ff650_sn
{
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
    virtual void v37(FUN_007ff650_p*, unsigned int);
};

struct FUN_007ff650_cls : public FORenderedMenu
{
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    float unkE8;
    unsigned char unkEC;

    void FUN_007ff650();
};


// @fnv 0x007ff650
void FUN_007ff650_cls::FUN_007ff650()
{
    FUN_007ff650_h local2;
    FUN_007ff650_p* a = ((::FUN_007ff650_p *)(reinterpret_cast<::TESRegionDataMap *>((this))->GetRegionMapName()));
    ((FUN_007ff650_sn*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))->v37(((::FUN_007ff650_p *)(reinterpret_cast<::TESRegionDataMap *>((this))->GetRegionMapName())), 1);
    new ((void *)&(local2)) ::NiUpdateData(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((a))->FUN_00a59c60((std::intptr_t)(&local2));
    if (((::FUN_007ff650_q *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((this))->FUN_006838b0())) != 0)
    {
        reinterpret_cast<::TaskQueueInterface *>((((::FUN_007ff650_q *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((this))->FUN_006838b0()))))->QueueActorDisarm(0);
    }
    reinterpret_cast<::fnv_007fb040::FUN_007fb040_shell *>((this))->FUN_007fb040();
    this->unkEC = 0;
    this->unkE8 = 0.0f;
    if (((::FUN_007ff650_r *)(::FUN_00559450((int *)&((*reinterpret_cast<::FUN_007ff650_g *>(&::g_011db63c)))))) != 0)
    {
        reinterpret_cast<::BSFadeNode *>((((::FUN_007ff650_r *)(::FUN_00559450((int *)&((*reinterpret_cast<::FUN_007ff650_g *>(&::g_011db63c))))))))->SetRange(DAT_01017130, DAT_01017130);
        reinterpret_cast<::FUN_0054b800_class *>((((::FUN_007ff650_r *)(::FUN_00559450((int *)&((*reinterpret_cast<::FUN_007ff650_g *>(&::g_011db63c))))))))->FUN_0054b800();
        reinterpret_cast<::FUN_00476ae0_class *>((((::FUN_007ff650_r *)(::FUN_00559450((int *)&((*reinterpret_cast<::FUN_007ff650_g *>(&::g_011db63c))))))))->FUN_00476ae0(0);
    }
}

struct Obj82
{
};
struct Tile82
{
};
struct Menu82
{
};
struct Manager82
{
};
struct Rect82
{
    float left, right, top, bottom;
    Rect82(float, float, float, float);
};
struct Frustum82
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
};
struct Camera82
{
};
struct Accumulator82
{
};
struct Scene82
{
    char pad[0xb4];
    struct Accumulator82* unkB4;
};
struct Interface82
{
    char pad[0xa4];
    struct Obj82* unkA4;
};
struct Target82
{
};
struct TargetManager82
{
};
struct Pointer82
{
    void* value;
    Pointer82(int);
    ~Pointer82();
    void FUN_0066b0d0(Target82*);
};
struct ObjectPointer82
{
    void* value;
};
struct Renderer82
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
    virtual void SetRect(const Rect82&);
    virtual void v44();
    virtual void GetRect(Rect82&);
};
struct Rendered82
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Finish();
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
    virtual void Render(Target82*, void*, void*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ObjectPointer82 root;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    bool initialized, scaled, partial;
    unsigned char unk2b;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    Rect82 color;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    ObjectPointer82 accumulator;
    void FUN_007fba00(void*, void*, Target82*);
};
struct Partial82
{
};
// Renders the scene through the accumulator with a temporary orthographic frustum, restoring UI visibility, rect and camera state afterwards.
// @fnv 0x007fba00
void Rendered82::FUN_007fba00(void* pRenderArg1, void* pRenderArg2, Target82* pSuppliedTarget)
{
    if (!initialized)
        return;
    if (!((::Obj82 *)(::FUN_00559450((int *)&(root)))))
        return;
    Renderer82* renderer5 = ((::Renderer82 *)(::FUN_0043c4b0()));
    Interface82* interface23 = ((::Interface82 *)(::fnv_004b7210::FUN_004b7210()));
    if (reinterpret_cast<::FUN_00644640_shell *>((interface23))->FUN_00644640())
        reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(interface23->unkA4))))->QueueActorDisarm(true);
    Scene82* scene3 = ((::Scene82 *)(reinterpret_cast<::StrOwner *>((interface23))->FUN_007fa950()));
    Accumulator82* render4 = ((::Accumulator82 *)(scene3->unkB4));
    reinterpret_cast<::FUN_004a0fd0_shell *>((render4))->FUN_004a0fd0((::NiNode *)(void *)(((::Obj82 *)(::FUN_00559450((int *)&(accumulator))))));
    Rect82 rect2(0.0f, 0.0f, 0.0f, 0.0f);
    renderer5->GetRect(rect2);
    renderer5->SetRect(color);
    Camera82* camera23 = ((::Camera82 *)(reinterpret_cast<::BSFaceGenNiNode *>((scene3))->GetAnimationData()));
    Pointer82 target31(0);
    if (!pSuppliedTarget)
        target31.FUN_0066b0d0(((::Target82 *)(reinterpret_cast<::Pool *>(::FUN_004a0ea0())->FUN_00b6e110(reinterpret_cast<std::uintptr_t>(::FUN_0043c4b0()), 49, 0, 0, 0))));
    else
        target31.FUN_0066b0d0(pSuppliedTarget);
    if (FUN_004e9510())
    {
        ::FUN_00b6b8d0((intptr_t)(pRenderArg2), (::NiRenderTargetGroup *)(void *)(((void *)(reinterpret_cast<::BSRenderedTexture *>((((::Target82 *)(::FUN_00559450((int *)&(target31))))))->GetGroup()))));
        reinterpret_cast<::_Cam_00712e60 *>((camera23))->FUN_00712e60((const ::_Rect16_00712e60 &)((const ::Rect82 &)(Rect82(0.0f, 1.0f, 1.0f, 0.0f))));
    }
    Frustum82 frustum12 = (*(::Frustum82 *)&(reinterpret_cast<::NiCamera *>((camera23))->GetViewFrustum()));
    Frustum82 saved14 = frustum12;
    frustum12.ortho = true;
    frustum12.left = 0.0f;
    frustum12.right = 1280.0f;
    frustum12.top = 960.0f;
    frustum12.bottom = 0.0f;
    frustum12.nearPlane = 0.0f;
    frustum12.farPlane = 10000.0f;
    reinterpret_cast<::NiCamera *>((camera23))->UpdateViewFrustum((const ::NiFrustum &)(frustum12));
    reinterpret_cast<::CameraState4E9 *>((renderer5))->SetFromCamera((*(const ::Camera4E9 *)(camera23)));
    Tile82* tile16 = ((::Tile82 *)(reinterpret_cast<::FUN_0045cd60_shell *>((interface23))->FUN_0045cd60()));
    bool oldTile23 = false;
    if (tile16)
    {
        oldTile23 = reinterpret_cast<::FUN_00456630_helper *>((((::Obj82 *)(reinterpret_cast<::TileFields *>((tile16))->renderedNode))))->FUN_00456610();
        reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(reinterpret_cast<::TileFields *>((tile16))->renderedNode))))->QueueActorDisarm(true);
    }
    Obj82* object4 = ((::Obj82 *)(::FUN_00706d10()));
    bool oldObject25 = object4 ? reinterpret_cast<::FUN_00456630_helper *>((object4))->FUN_00456610() : false;
    if (object4)
        reinterpret_cast<::TaskQueueInterface *>((object4))->QueueActorDisarm(true);
    Menu82* menu1 = ((::Menu82 *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::Manager82 * *>(&::g_pHudMainMenuInstance))))->FUN_00726070()));
    bool oldMenu21 = reinterpret_cast<::FUN_00456630_helper *>((((::Obj82 *)(reinterpret_cast<::TileFields *>((((::Tile82 *)(reinterpret_cast<::FUN_00a03d40_shell *>((menu1))->FUN_00a03d40()))))->renderedNode))))->FUN_00456610();
    reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(reinterpret_cast<::TileFields *>((((::Tile82 *)(reinterpret_cast<::FUN_00a03d40_shell *>((menu1))->FUN_00a03d40()))))->renderedNode))))->QueueActorDisarm(true);
    if (this != ((::Rendered82 *)(::fnv_00705990::FUN_00705990())))
        reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(::FUN_00559450((int *)&(root))))))->QueueActorDisarm(false);
    reinterpret_cast<::FUN_007fc790_shell *>(this)->UpdateMenuVisibility();
    reinterpret_cast<::FUN_00c4f270_Class *>((render4))->FUN_00c4f270(1);
    ::FUN_00b6bee0(((::Camera82 *)(reinterpret_cast<::BSFaceGenNiNode *>((scene3))->GetAnimationData())), ((::Obj82 *)(::FUN_00559450((int *)&(root)))), (::BSShaderAccumulator *)(render4));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(::Camera82 *)(((::Camera82 *)(reinterpret_cast<::BSFaceGenNiNode *>((scene3))->GetAnimationData()))), (::BSShaderAccumulator *)(::Obj82 *)(((::Obj82 *)(::FUN_00559450((int *)&(accumulator))))), 0);
    reinterpret_cast<::FUN_00c4f2d0_class *>((render4))->FUN_00c4f2d0();
    reinterpret_cast<::FUN_007fc8d0_shell *>(this)->FUN_007fc8d0();
    reinterpret_cast<::FUN_004a0fd0_shell *>((render4))->FUN_004a0fd0((::NiNode *)(void *)(0));
    if (this != ((::Rendered82 *)(::fnv_00705990::FUN_00705990())))
        reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(::FUN_00559450((int *)&(root))))))->QueueActorDisarm(true);
    reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(reinterpret_cast<::TileFields *>((((::Tile82 *)(reinterpret_cast<::FUN_00a03d40_shell *>((menu1))->FUN_00a03d40()))))->renderedNode))))->QueueActorDisarm(oldMenu21);
    if (tile16)
        reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(reinterpret_cast<::TileFields *>((tile16))->renderedNode))))->QueueActorDisarm(oldTile23);
    if (object4)
        reinterpret_cast<::TaskQueueInterface *>((object4))->QueueActorDisarm(oldObject25);
    ::BSRenderedTexture::EndAllAndResetRendererState();
    Render(((::Target82 *)(::FUN_00559450((int *)&(target31)))), pRenderArg1, pRenderArg2);
    if (!pSuppliedTarget)
        reinterpret_cast<::Manager *>(::FUN_004a0ea0())->FUN_00b6da10((::Item *)(::FUN_00559450((int *)&(target31))));
    renderer5->SetRect(rect2);
    reinterpret_cast<::NiCamera *>((camera23))->UpdateViewFrustum((const ::NiFrustum &)(saved14));
    if (partial)
        reinterpret_cast<::FUN_007fbeb0_shell *>((((::Partial82 *)(::ImageSpaceManager::FUN_004e3270()))))->SetValueAndAssign(0, (void *)(0));
    Finish();
    if (reinterpret_cast<::FUN_00644640_shell *>((interface23))->FUN_00644640())
        reinterpret_cast<::TaskQueueInterface *>((((::Obj82 *)(interface23->unkA4))))->QueueActorDisarm(false);
}

struct FUN_00483710
{
    int a, b, c;
    ~FUN_00483710();
};
namespace n7f8 {
typedef ::FUN_00483710 Snd;
struct Audio
{
    Snd FUN_00ad7550(const char* name, unsigned int flags);
};
struct Anim
{
};
struct Player
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
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual int v133();
};
struct SndX
{
};
struct Mgr
{
    char pad[0x154];
    SndX m_154;
    void FUN_007f8170();
};
}
// @fnv 0x007f8170
void n7f8::Mgr::FUN_007f8170()
{
    reinterpret_cast<::Interface *>(this)->FUN_007fa8d0(reinterpret_cast<::FUN_008c51c0_shell *>((((Player*)(*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer)))))->FUN_008c51c0());
    Anim* anim = ((::n7f8::Anim *)(reinterpret_cast<::PlayerCharacter *>((((Player*)(*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer)))))->GetAnimation(true)));
    if (anim)
    {
        if (!reinterpret_cast<::fnv_004985f0::FUN_004985f0_s *>((anim))->FUN_004985f0())
            reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>((anim))->FUN_00496080(7, 0.0f);
        reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((anim))->FUN_00494740(reinterpret_cast<::fnv_00897910::AnimOwner *>((((Player*)(*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer)))))->FUN_00897910(0, (::fnv_00897910::Equipped *)(0), 0, (::fnv_00897910::AnimData *)(0)), 1, -1, -1);
        reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((((::n7f8::Anim *)(reinterpret_cast<::PlayerCharacter *>((((Player*)(*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer)))))->GetAnimation(false)))))->FUN_00494740(reinterpret_cast<::fnv_00897910::AnimOwner *>((((Player*)(*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer)))))->FUN_00897910(0, (::fnv_00897910::Equipped *)(0), 0, (::fnv_00897910::AnimData *)(0)), 1, -1, -1);
        if (((Player*)(*reinterpret_cast<::PlayerView * *>(&::_g_thePlayer)))->v133())
            reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((anim))->FUN_00494740(0, 1, -1, 0);
    }
    if (!reinterpret_cast<::FOPipboyManager *>(this)->IsUnk28Set())
        return;
    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const struct ::FUN_00483710 &)(((::n7f8::Audio *)(::FUN_00453a70()))->FUN_00ad7550("UIPipBoyAccessDown", 0x121)))->FUN_00ad8830(false);
    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(m_154))->FUN_00ad88f0();
    reinterpret_cast<::SoundPlaybackHandle *>(&(m_154))->Release();
    reinterpret_cast<::FOPipboyManager *>(this)->ActivateButton(0);
    ::UpdateMenuTileVisibility();
    reinterpret_cast<::MenuStub *>(this)->ResetMenuState();
    ::g_burstSoundEnabled = false;
    ::FUN_007f8160(1);
}

class FUN_006815c0
{
  public:
    FUN_006815c0();
    float x, y, z;
};

struct Input7fb7
{
};

struct Point2_7fb7
{
    float x, y;
};

struct Camera7fb7
{
};

struct View7fb7
{
};

struct Record7fb7
{
    NiGeometry* FUN_00458b50();
};

struct Results7fb7
{
};

class GlobalObject_00e98f20
{
  public:
    GlobalObject_00e98f20(int iSize, int iGrowBy);
    ~GlobalObject_00e98f20();
    int m_kNextStreamField[13];
};

struct Target7fb7
{
};

struct Renderer7fb7
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual Target7fb7* GetDefaultTarget();
};

struct Calls7fb7
{
    static bool __cdecl FUN_00702680(int iMenu, int iUnused);
};

struct RenderedMenu7fb7 : public FORenderedMenu
{
    bool FUN_007fb790(void* pkUnused, float* pfX, float* pfY);
};

// @fnv 0x007fb790
bool RenderedMenu7fb7::FUN_007fb790(void* pkUnused, float* pfX, float* pfY)
{
    bool bResult = false;
    reinterpret_cast<::TaskQueueInterface *>(((m_pRenderedMenuObject).operator->()))->QueueActorDisarm(false);
    Input7fb7* pkInput = ((::Input7fb7 *)(::fnv_004b7210::FUN_004b7210()));
    if (!m_pMenuBackgroundScreenGeometry)
        return false;
    FUN_006815c0 kSource;
    FUN_006815c0 kWorldPosition;
    GlobalObject_00e98f20 kPickObj(0, 8);
    Camera7fb7* pkCamera3D;
    if (((::Camera7fb7 *)(m_pMenuLightParameters.m_pObject)))
        pkCamera3D = ((::Camera7fb7 *)(m_pMenuLightParameters.m_pObject));
    else
        pkCamera3D = ((::Camera7fb7 *)(reinterpret_cast<::BSFaceGenNiNode *>((((::View7fb7 *)(::FUN_0045c670()))))->GetAnimationData()));
    reinterpret_cast<::FUN_00458b30_class *>(&(kPickObj))->SetByteAtOffset17(1);
    reinterpret_cast<::NiPick *>(&(kPickObj))->FUN_00705fc0(m_pMenuBackgroundScreenGeometry);
    reinterpret_cast<::CombatProcedure *>(&(kPickObj))->Initialize((::CombatController *)(0));
    reinterpret_cast<::FUN_00792780_Class *>(&(kPickObj))->SetByteAtOffset30(1);
    reinterpret_cast<::CameraWindowRay *>((pkCamera3D))->MapScreenToRay((int)reinterpret_cast<::BGSImpactData *>((pkInput))->FUN_009a9350(), (int)reinterpret_cast<::FUN_00792760_shell *>((pkInput))->FUN_00792760(), (::NiPoint3 &)(kSource), (::NiPoint3 &)(kWorldPosition), (const ::NiRenderTargetGroup *)(void *)(0));
    if (reinterpret_cast<::NiPick *>(&(kPickObj))->PerformPick((const ::NiPoint3 &)(kSource), (const ::NiPoint3 &)(kWorldPosition), false))
    {
        unsigned int uiResult = 0;
        Record7fb7* pkResult = ((::Record7fb7 *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::Results7fb7 *)(reinterpret_cast<::BGSCameraPath *>(&(kPickObj))->GetConditions()))))->FUN_00968670(uiResult)));
        if (pkResult && pkResult->FUN_00458b50() == m_pMenuBackgroundScreenGeometry)
        {
            Point2_7fb7 kUV = (*(const ::Point2_7fb7 *)(reinterpret_cast<::BGSCameraPath *>((pkResult))->GetShotList()));
            if (Calls7fb7::FUN_00702680(0x40c, 0))
            {
                kUV.x *= 0.62999999523162842;
                kUV.x += 0.37000000476837158;
                kUV.y *= 0.64999997615814209;
                kUV.y += 0.34000000357627869;
            }
            float m_fGlyphExtent = (float)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::Renderer7fb7 *)(::FUN_0043c4b0()))->GetDefaultTarget()))->FUN_0084e3a0()));
            float m_fGlyphWidthInPixels = m_fGlyphExtent * 1.3333330154418945;
            *pfX = kUV.x * m_fGlyphWidthInPixels;
            *pfY = kUV.y * m_fGlyphExtent;
            bResult = true;
        }
    }
    return bResult;
}

namespace recon7fbee0 {
struct Ptr
{
    Ptr& FUN_006e5cc0(const Ptr&);
    void FUN_0066b0d0(void*);
};
struct Arg
{
};
struct Obj
{
};
struct Setting
{
};
struct Node
{
};
struct Manager
{
};
struct Four
{
    int a, b, c, d;
};
struct Menu
{
    char p0[0xc];
    Node node;
    char p0d[0xb];
    Obj* obj;
    char p1c[0xe];
    bool active;
    char p2b[0x15];
    float f40, f44, f48;
    char p4c;
    bool b4d;
    char p4e[0xe];
    float f5c;
    bool b60;
    char p61[0xf];
    float f70;
    bool b74;
    char p75[0x13];
    float f88, f8c, f90;
    char p94;
    bool b95;
    char p96[6];
    float f9c;
    char pa0[0x1c];
    Ptr ptr;
    char pbd[3];
    Four four;
    void FUN_007fbee0(Arg*, void*, int);
};
// @fnv 0x007fbee0
void Menu::FUN_007fbee0(Arg* a, void* pData, int iValue)
{
    void* pUnused = ((void *)(::fnv_004b7210::FUN_004b7210()));
    *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5e8)) = f40;
    *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5ec)) = f44;
    *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5f0)) = f48;
    *(float*)&(*reinterpret_cast<char *>(&::DAT_012007e8)) = 0.0f;
    ((Ptr*)&DAT_01200810)->FUN_006e5cc0(ptr);
    ((Ptr*)&DAT_01200818)->FUN_0066b0d0(((void *)(reinterpret_cast<::FUN_004bc320_shell *>((a))->FUN_004bc320(0))));
    if (this == ((void *)(::fnv_00705990::FUN_00705990())))
        *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5f4)) = ::FUN_00717860();
    else
        *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5f4)) = reinterpret_cast<::TileListBoxCalls *>((obj))->GetFloat(0xfb0);
    if (b4d)
    {
        *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5ec)) *= 1.0f + f5c;
        *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5e8)) *= 1.0f + f5c;
    }
    if (b60)
        *(float*)&(*reinterpret_cast<char *>(&::DAT_012007e8)) = ::FUN_00717860() * f70;
    if (b74)
        *(float*)&(*reinterpret_cast<char *>(&::DAT_012007e8)) += ::FUN_00717860() * f88;
    *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5ec)) += f8c;
    *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5e8)) += f90;
    if (b95)
    {
        *(float*)&(*reinterpret_cast<char *>(&::DAT_012007f0)) = *((float *)&(::FUN_00403e20((float *)(((Setting*)&(*reinterpret_cast<char *>(&::g_011db520)))))));
        *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5f8)) = *((float *)&(::FUN_00403e20((float *)(((Setting*)&(*reinterpret_cast<char *>(&::g_011db464)))))));
        *(float*)&(*reinterpret_cast<char *>(&::DAT_012007f4)) = f9c;
        DAT_012007f8 = 1;
    }
    else
    {
        *(float*)&(*reinterpret_cast<char *>(&::DAT_012007f0)) = 0.0f;
        *(float*)&(*reinterpret_cast<char *>(&::DAT_011ae5f8)) = 0.0f;
        *(float*)&(*reinterpret_cast<char *>(&::DAT_012007f4)) = -1.0f;
    }
    *(Four*)&DAT_01200800 = four;
    if (active && !((void *)(::FUN_00559450((int *)&(node)))))
        reinterpret_cast<::PartialScreenGeometryReceiver *>((((::recon7fbee0::Manager *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_00b8c3b0(::FUN_00717860(), ::FUN_00717860(), (*(::NiPointer< ::NiScreenElements> *)(&node)));
    if (active)
        reinterpret_cast<::FUN_007fbeb0_shell *>((((::recon7fbee0::Manager *)(::ImageSpaceManager::FUN_004e3270()))))->SetValueAndAssign(1, ((void *)(::FUN_00559450((int *)&(node)))));
    *(int*)&(*reinterpret_cast<char *>(&::DAT_012007ec)) = iValue;
    reinterpret_cast<::BB97550Shader *>((((::recon7fbee0::Manager *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_00b97550(10, (std::intptr_t)(((void *)(::FUN_0043c4b0()))), (std::intptr_t)(a), (std::intptr_t)(pData), 0, 1);
    ((Ptr*)&DAT_01200818)->FUN_0066b0d0(0);
}
}

struct Node007f
{
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
    virtual Node007f* v27(const NiFixedString&);
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
    virtual void v37(Node007f*, bool);
    virtual void v38();
    virtual void v39();
    virtual void v3a(Node007f*);
};
struct Ref007f
{
    void FUN_0066b0d0(void*);
};
struct Owner007f
{
    char pad[0xf8];
    Ref007f rF8;
    char fillF9[3];
    Ref007f rFC;
    char fillFD[3];
    Ref007f r100;
    char fill101[3];
    Ref007f r104;
    char fill105[3];
    Ref007f r108;
    char fill109[3];
    Ref007f r10C;
    char fill10D[3];
    char p110[12];
    char p11C[36];
    char p140[12];
    bool b14C;
    void FUN_007fdf40();
};
// @fnv 0x007fdf40
void Owner007f::FUN_007fdf40()
{
    DAT_011ad884 = 1;
    if (!reinterpret_cast<::FOPipboyManager *>(this)->IsUnk28Set())
        return;
    if (((::Node007f *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>(this)->FUN_006838b0())))
    {
        reinterpret_cast<::TaskQueueInterface *>((((::Node007f *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>(this)->FUN_006838b0()))))->QueueActorDisarm(true);
        NiUpdateData ud(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::Node007f *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>(this)->FUN_006838b0()))))->FUN_00a59c60((std::intptr_t)&(ud));
    }
    ((::Node007f *)(::FUN_00559450((int *)&(r100))))->v3a(((::Node007f *)(::FUN_00559450((int *)&(r108)))));
    ((::Node007f *)(::FUN_00559450((int *)&(r100))))->v3a(((::Node007f *)(::FUN_00559450((int *)&(rFC)))));
    ((Node007f*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))->v3a(((::Node007f *)(::FUN_00559450((int *)&(r100)))));
    r100.FUN_0066b0d0(0);
    ((Node007f*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))->v3a(((::Node007f *)(reinterpret_cast<::TESRegionDataMap *>(this)->GetRegionMapName())));
    ((::Node007f *)(::FUN_00559450((int *)&(r10C))))->v37(((::Node007f *)(::FUN_00559450((int *)&(rFC)))), true);
    reinterpret_cast<::FUN_00440460_S *>((((::Node007f *)(::FUN_00559450((int *)&(rFC))))->v27(NiFixedString(&DAT_0101e460))))->FUN_00440460((const ::V3 *)(p140));
    reinterpret_cast<::FUN_0043fa80_s *>((((::Node007f *)(::FUN_00559450((int *)&(rFC))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(p11C)));
    reinterpret_cast<::FUN_00440460_S *>((((::Node007f *)(::FUN_00559450((int *)&(rFC))))))->FUN_00440460((const ::V3 *)(p110));
    reinterpret_cast<::TaskQueueInterface *>((((::Node007f *)(::FUN_00559450((int *)&(rFC))))))->QueueActorDisarm(b14C);
    rFC.FUN_0066b0d0(0);
    r104.FUN_0066b0d0(0);
    rF8.FUN_0066b0d0(0);
    reinterpret_cast<::MultiBoundManagerB5D *>((((Node007f*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->FUN_00b5d180();
    reinterpret_cast<::MenuStub *>(this)->ResetMenuState();
    reinterpret_cast<::MenuDriver *>(this)->UpdateSlotSelection(-1);
    r108.FUN_0066b0d0(0);
}

struct NiAVObjectS;
struct BGSBodyPart
{
};
struct NiAVObjectS : NiAVObject
{
};
struct SSNVt
{
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
    virtual void v3a(NiAVObject*);
};
struct FUN_007ff740_shell : public FORenderedMenu
{
    void UpdateBodyPart();
};
// If GetPartName returns an object, calls FUN_00450f90(true) and Update on it, then calls v3a with the menu root and resets menu state.
// @fnv 0x007ff740
void FUN_007ff740_shell::UpdateBodyPart()
{
    if (((::NiAVObjectS *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((((BGSBodyPart*)this)))->FUN_006838b0())))
    {
        reinterpret_cast<::TaskQueueInterface *>((((::NiAVObjectS *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((((BGSBodyPart*)this)))->FUN_006838b0()))))->QueueActorDisarm(true);
        NiUpdateData upd(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::NiAVObjectS *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((((BGSBodyPart*)this)))->FUN_006838b0()))))->FUN_00a59c60((std::intptr_t)&(upd));
    }
    ((SSNVt*)::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))->v3a(((::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>((this))->GetRegionMapName())));
    ((MenuStub*)this)->ResetMenuState();
}



struct SpawnedRef
{
    virtual void vfn00();
    virtual void Free();
    long m_iObjectReferenceCount;
};

struct SpawnedSubBase
{
    virtual void vfnBase();
    SpawnedSubBase(unsigned int a, unsigned int b);
};

struct SpawnedSub : SpawnedSubBase
{
    unsigned int unk04;
    unsigned int unk08;
    volatile unsigned int unk0c;
    unsigned int unk10;

    SpawnedSub(unsigned int a, unsigned int b) : SpawnedSubBase(a, b)
    {
        unk10 = 0;
    }
};

class FUN_00e98f20
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    volatile unsigned int unk0c;
    volatile unsigned char unk10;
    volatile unsigned char unk11;
    SpawnedRef* m_pReference;
    SpawnedSub m_sub;
    unsigned int unk2c;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;

    FUN_00e98f20(unsigned int a, unsigned int b);
};

// @fnv 0x00e98f20
FUN_00e98f20::FUN_00e98f20(unsigned int a, unsigned int b) : m_pReference(0), m_sub(a, b)
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 1;
    unk0c = 1;
    unk10 = 1;
    unk11 = 0;
    SpawnedRef* p = *(SpawnedRef* volatile*)&m_pReference;
    if (p != 0)
    {
        if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0)
        {
            p->Free();
        }
        m_pReference = 0;
    }
    unk30 = 0;
    unk31 = 0;
    unk32 = 0;
    unk33 = 0;
    unk2c = 0;
}
#include "generated/data/fallout/interface/forenderedmenu.inc"
