// fallout/interface/fopipboymanager.cpp: FOPipboyManager, FOPipboyManagerPC, SystemColorManager, Interface and more (29 functions)

#include "fnv/decl/BSAnimGroupSequence.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/DecalStub.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00424940_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00444020_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00491180_shell.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_004bc280_S.h"
#include "fnv/decl/FUN_0050c630_helper.h"
#include "fnv/decl/FUN_005db4c0_struct.h"
#include "fnv/decl/FUN_007f7fb0_Class.h"
#include "fnv/decl/FUN_007f7fe0_cls.h"
#include "fnv/decl/FUN_007fadf0_shell.h"
#include "fnv/decl/FUN_007faf10_shell.h"
#include "fnv/decl/FUN_007fb250_owner.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_008eeaa0Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ba8ab0_shell.h"
#include "fnv/decl/IOManager.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/S7f.h"
#include "fnv/decl/S_007fb2b0.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThisStub.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_00494740__FUN_00494740_t.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_0050c660__FUN_0050c660_shell.h"
#include "fnv/decl/fnv_00572750__XActor.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_007181d0__FUN_007181d0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00a59e20__NiAVObject.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_0050c000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_007ff000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "fopipboymanager_decls.h"

// @fnv 0x007f9070
void FOPipboyManager::UpdatePipBoyButton()
{
    NiAVObject* button = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton01"));
    if (!button)
        button = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton01:0"));
    if (button)
    {
        NiNode* node;
        node = (NiNode*)((::NiAVObject *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)),
                                      (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton01"))))));
        if (!node)
            node = (NiNode*)((::NiAVObject *)(::FUN_00653270(
                &(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)), (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton01:0"))))));
        m_cPipBoyButtonAvailability[0] = ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
        node = (NiNode*)((::NiAVObject *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)),
                                      (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton02"))))));
        if (!node)
            node = (NiNode*)((::NiAVObject *)(::FUN_00653270(
                &(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)), (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton02:0"))))));
        m_cPipBoyButtonAvailability[1] = ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
        node = (NiNode*)((::NiAVObject *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)),
                                      (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton03"))))));
        if (!node)
            node = (NiNode*)((::NiAVObject *)(::FUN_00653270(
                &(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)), (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("PipBoyButton03:0"))))));
        m_cPipBoyButtonAvailability[2] = ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
    }
    button = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("StatsGlow"));
    if (!button)
        button = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("StatsGlow:0"));
    if (button)
    {
        m_pButtonGlowObjects[0] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("StatsGlow"));
        if (!m_pButtonGlowObjects[0])
            m_pButtonGlowObjects[0] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("StatsGlow:0"));
        m_pButtonGlowObjects[1] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("ItemsGlow"));
        if (!m_pButtonGlowObjects[1])
            m_pButtonGlowObjects[1] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("ItemsGlow:0"));
        m_pButtonGlowObjects[2] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("DataGlow"));
        if (!m_pButtonGlowObjects[2])
            m_pButtonGlowObjects[2] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("DataGlow:0"));
        reinterpret_cast<::FOPipboyManager *>(this)->ActivateButton(false);
    }
}

// @fnv 0x007f99d0
void FOPipboyManager::UpdateScrollKnob()
{
    NiAVObject* pObject = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("ScrollKnob"));
    if (!pObject)
        pObject = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("ScrollKnob:0"));
    if (pObject && pObject->IsSceneNode())
        m_pGaugeObjects[0] = pObject->IsSceneNode()->GetAt(0);
    m_pGaugeObjects[1] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("RadNeedle"));
    if (!m_pGaugeObjects[1])
        m_pGaugeObjects[1] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("RadNeedle:0"));
    m_pGaugeObjects[2] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("TabKnob"));
    if (!m_pGaugeObjects[2])
        m_pGaugeObjects[2] = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("TabKnob:0"));
    m_fTabKnobPositions[0] = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db33c))))))->f;
    m_fTabKnobPositions[4] = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db34c))))))->f;
    float fStep = (m_fTabKnobPositions[4] - m_fTabKnobPositions[0]) / 4.0;
    for (unsigned int i = 1; i < 4; ++i)
        m_fTabKnobPositions[i] = m_fTabKnobPositions[i - 1] + fStep;
    m_fChartFirstPoint[2] = m_fTabKnobPositions[0];
    m_fChartSecondPoint[2] = m_fTabKnobPositions[0];
    m_fGaugeValues2[2] = 0.0f;
    m_fChartSecondPoint[1] = ::_g_thePlayer ? 1.5707963267948966 - ::_g_thePlayer->actorValues.GetCurrentActorValue(54) /
                                                                    StatsMenu::GetChartScale() * 3.1415927410125732
                                         : 0.0;
    m_fChartFirstPoint[1] = m_fChartSecondPoint[1];
    m_fGaugeValues2[1] = 0.0f;
    ThreeByThreeMatrix kLocalRotate;
    ThreeByThreeMatrix kParentRotate;
    if (m_pGaugeObjects[0])
    {
        kLocalRotate = (*(const ::ThreeByThreeMatrix *)(::FUN_006a9540((char *)((m_pGaugeObjects[0]).operator->()))));
        kParentRotate = (*(const ::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((m_pGaugeObjects[0]).operator->()))->FUN_009611e0()))))));
        reinterpret_cast<::FUN_0043fa80_s *>((((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((m_pGaugeObjects[0]).operator->()))->FUN_009611e0()))))->FUN_0043fa80(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(const ::ThreeByThreeMatrix &)(kParentRotate))->operator+(kLocalRotate));
        m_pGaugeObjects[0]->SetLocalRotation(m_fChartFirstPoint[0], 1.0f, 0.0f, 0.0f);
    }
    if (m_pGaugeObjects[1])
        m_pGaugeObjects[1]->SetLocalRotation(m_fChartFirstPoint[1], 0.0f, 0.0f, 1.0f);
    if (m_pGaugeObjects[2])
        m_pGaugeObjects[2]->SetLocalRotation(m_fChartFirstPoint[2], 0.0f, 0.0f, 1.0f);
}

// @fnv 0x007fa310
void FOPipboyManager::SetPipBoyObjectVisibility(bool thirdPerson, bool show, bool updateState)
{
    NiNode* pRoot = (thirdPerson ? m_pPipBoyObject1 : m_pPipBoyObject0);
    if (pRoot)
    {
        NiAVObject* pEffect = pRoot->GetObjectByName(NiFixedString("PipboyLightEffect"));
        if (!pEffect)
            pEffect = pRoot->GetObjectByName(NiFixedString("PipboyLightEffect:0"));
        if (pEffect)
        {
            reinterpret_cast<::TaskQueueInterface *>((pEffect))->QueueActorDisarm(!show);
            if (updateState)
            {
                if (thirdPerson)
                {
                    b1stPersonLightOn = show;
                }
                else
                {
                    b3rdPersonLightOn = show;
                    NiNode* pNode = pEffect->IsSceneNode();
                    if (pNode && ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pNode))->FUN_00453470())))
                    {
                        NiGeometry* m_pShaderGeometry = pNode->GetAt(0)->IsGeometry();
                        if (m_pShaderGeometry)
                        {
                            NiProperty* pProperty = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((m_pShaderGeometry))->FUN_00a59d30(FUN_004af350())));
                            if (pProperty)
                                reinterpret_cast<::DecalStub *>((pProperty))->FUN_0068c9f0((float)show);
                            else
                            {
                                BSShaderProperty* pShaderProperty =
                                    (BSShaderProperty*)((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((m_pShaderGeometry))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));
                                reinterpret_cast<::FUN_00ba8ab0_shell *>((pShaderProperty))->FUN_00ba8ab0((float)show);
                            }
                            reinterpret_cast<::FUN_00a5a040_Class *>((m_pShaderGeometry))->FUN_00a5a040();
                        }
                    }
                }
            }
        }
    }
    else if (updateState)
    {
        if (thirdPerson)
            b1stPersonLightOn = show;
        else
            b3rdPersonLightOn = show;
    }
}

// The callers receive Interface::FUN_004b7210() and then access the Pipboy manager.
// @fnv 0x00704370
FOPipboyManager* Interface::GetPipboyManager()
{
    return pPipboyManager;
}

// @fnv 0x007f9050
void FOPipboyManager::SetScanlines(bool enabled, float scale)
{
    doScanlines = enabled;
    scanlineScale = scale;
}
// @fnv 0x007f9010
void FOPipboyManager::SetScreen(NiAVObject* apScreen)
{
    screen = apScreen;
}
// @fnv 0x007f99b0
void FOPipboyManager::SetScreenLightFlickerIntensity(float value)
{
    flicker = value;
}
// @fnv 0x007f9030
void FOPipboyManager::SetBlurIntensity(float value)
{
    blurIntensity = value;
}

struct FUN_004dc540_shell : public FORenderedMenu
{
    void FUN_004dc540(NiAVObject*);
};
// @fnv 0x007f8ba0
void FOPipboyManager::OnMenuOpen()
{
    NiNode* screenNode;
    if ((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011db2cc)).Bool()->b && !IsUnk28Set() && ::_g_thePlayer && ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true))))
    {
        {
            struct Screens
            {
                NiAVObject* thirdPerson;
                NiAVObject* firstPerson;
            } screenObjects;
            screenObjects.thirdPerson = 0;
            screenObjects.firstPerson = 0;
            screenNode = 0;
            screenNode = (NiNode*)((::NiAVObject *)(::FUN_00653270(
                &(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)), (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("pipboyscreen"))))));
            if (!screenNode)
                screenNode = (NiNode*)((::NiAVObject *)(::FUN_00653270(
                    &(*reinterpret_cast<::NiRTTI *>(&::g_011f4428)), (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("pipboyscreen:0"))))));
            FORenderedMenu::OnMenuOpen();
            reinterpret_cast<::NiPick *>(this)->FUN_00705fc0(((::NiNode *)(reinterpret_cast<::StrOwner *>((((::Interface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007fa950())));
            if (screenNode)
            {
                screenObjects.firstPerson = ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((screenNode))->FUN_0045bc00(0)));
                m_pPipBoyObject0 = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((screenNode))->FUN_009611e0()));
            }
            else
            {
                screenObjects.firstPerson = ((::NiAVObject *)(::FUN_00653270(
                    &(*reinterpret_cast<::NiRTTI *>(&::g_011f4acc)), (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))->GetObjectByName(NiFixedString("pipboyscreen:0"))))));
                if (screenObjects.firstPerson)
                    m_pPipBoyObject0 = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((screenObjects.firstPerson))->FUN_009611e0()));
            }
            reinterpret_cast<::FUN_004dc540_shell *>(this)->FUN_004dc540((::NiAVObject *)(::NiNode *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))));
            if (screenNode)
            {
                screenObjects.thirdPerson = ((::NiAVObject *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4acc)), (::NiObject *)(::NiAVObject *)(((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((screenNode))->FUN_0045bc00(0)))))));
                m_pPipBoyObject1 = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((screenNode))->FUN_009611e0()));
                m_pPipBoyObject2 = screenObjects.thirdPerson;
            }
            else if (screenObjects.firstPerson)
            {
                screenObjects.thirdPerson = screenObjects.firstPerson;
                m_pPipBoyObject1 = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((screenObjects.firstPerson))->FUN_009611e0()));
                m_pPipBoyObject2 = screenObjects.thirdPerson;
            }
            if (screenObjects.firstPerson && screenObjects.thirdPerson)
            {
                FUN_007fc2d0(screenObjects.firstPerson);
                FUN_007fc2d0(screenObjects.thirdPerson);
                SetScreen(screenObjects.firstPerson);
            }
            UpdatePipBoyButton();
            UpdateScrollKnob();
            InitializeMenuLight();
            if (m_pPipBoyObject0)
            {
                NiUpdateData updateData(0.0f, false, false);
                reinterpret_cast<::FUN_00a59c60_cls *>(((m_pPipBoyObject0).operator->()))->FUN_00a59c60((int)&(updateData));
                reinterpret_cast<::FUN_00a5a040_Class *>(((m_pPipBoyObject0).operator->()))->FUN_00a5a040();
            }
            if (m_pPipBoyObject1)
            {
                NiUpdateData updateData(0.0f, false, false);
                reinterpret_cast<::FUN_00a59c60_cls *>(((m_pPipBoyObject1).operator->()))->FUN_00a59c60((int)&(updateData));
                reinterpret_cast<::FUN_00a5a040_Class *>(((m_pPipBoyObject1).operator->()))->FUN_00a5a040();
            }
        }
        RgbaColor kColor(0.0f, 0.0f, 0.0f, 0.0f);
        if (((::SystemColorManager *)(::FUN_00718b60()))->GetColor(4, (::NiColor &)(kColor)))
        {
            reinterpret_cast<::FUN_007f7fe0_cls *>(this)->SetQuad((const ::Quad4 *)&(kColor));
            reinterpret_cast<::FUN_007f7fb0_Class *>(this)->FUN_007f7fb0((const ::FUN_007f7fb0_Value *)&(kColor));
        }
        SetBlurIntensity(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db2dc))))))->f);
        reinterpret_cast<::FUN_00444020_Class *>(this)->FUN_00444020(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db328))))))->f);
        SetScanlines(true, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db274))))))->f);
        reinterpret_cast<::FUN_00810530_c *>(this)->FUN_00810530(true);
        SetPipBoyObjectVisibility(false, false, true);
        SetPipBoyObjectVisibility(true, false, true);
    }
}

// @fnv 0x004dc540
void FUN_004dc540_shell::FUN_004dc540(NiAVObject* apScreenParent)
{
    *(NiPointer<NiNode>*)((char*)this + 8) = (NiNode*)apScreenParent;
}

struct NiStream;
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};
struct FUN_006b0570_shell : public FORenderedMenu
{
    void FUN_006b0570(NiColor*);
};

// Copies the NiColor pointed to by the argument into the field at offset 0x2c of this object.
// @fnv 0x006b0570
void FUN_006b0570_shell::FUN_006b0570(NiColor* apColor)
{
    *(NiColor*)((char*)this + 0x2c) = *apColor;
}

struct FUN_007f86f0_shell : public FOPipboyManager
{
    void SetKnobTargetAndRate(int, float, float);
};

// Stores afTarget and afRate into the per-knob arrays at offsets 0x118 and 0x124 for index aiKnob.
// @fnv 0x007f86f0
void FUN_007f86f0_shell::SetKnobTargetAndRate(int aiKnob, float afTarget, float afRate)
{
    (&this->m_fChartSecondPoint[0])[aiKnob] = afTarget;
    (&this->m_fGaugeValues2[0])[aiKnob] = afRate;
}

struct FUN_00965580_shell : public FORenderedMenu
{
    void SetIntensity(float);
};
// @fnv 0x007f9840
void FOPipboyManager::InitializeMenuLight()
{
    if (!CreateMenuLight("Omni01", 0))
        CreateMenuLight("Omni01:0", 0);
    NiPointLight* light = (NiPointLight*)((const char *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((((BGSBodyPart*)this)))->FUN_006838b0()));
    struct PointStorage
    {
        float x, y, z;
    } rgb;
    if (light)
    {
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((light))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)((const ::NiPoint3 &)(NiPoint3(0.0f, 0.0f, 0.0f))));
        reinterpret_cast<::FUN_004bc280_S *>((light))->FUN_004bc280((const ::C3 *)&(const ::NiPoint3 &)(NiPoint3(0.0f, 0.0f, 0.0f)));
        reinterpret_cast<::FUN_0050c630_helper *>((light))->FUN_0050c630(0.0f);
        reinterpret_cast<::fnv_0050c660::FUN_0050c660_shell *>((light))->FUN_0050c660(0.0f);
        ::FUN_0050c690((::NiDynamicEffect *)(light), 0.0f);
        light->FUN_0050dd20(1.0f);
        light->FUN_0050dd50(NiPoint3(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db514))))))->f, 0.0f, 0.0f));
        RgbaColor color(0.0f, 0.0f, 0.0f, 0.0f);
        ((::SystemColorManager *)(::FUN_00718b60()))->GetColor(4, (::NiColor &)(color));
        reinterpret_cast<::FUN_00416870_t *>((((NiPoint3*)&rgb)))->FUN_00416870(color.r, color.g, color.b);
        reinterpret_cast<::FUN_006b0570_shell *>((((PathingGraphNode*)this)))->FUN_006b0570((::NiColor *)&((const NiPoint3&)rgb));
        reinterpret_cast<::FUN_00965580_shell *>(this)->SetIntensity(1.0f);
        SetScreenLightFlickerIntensity(1.0f);
    }
}

// @fnv 0x00965580
void FUN_00965580_shell::SetIntensity(float afIntensity)
{
    this->fScreenLightBaseIntensity = afIntensity;
}

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_007f7cb0(unsigned int flags);
};
// Calls the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007f7cb0
void* DelStandIn::FUN_007f7cb0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

class NiScreenElements : public NiGeometry
{
};

struct SoundPlaybackHandle
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
};

struct FUN_007fad10 : public FORenderedMenu
{
};

struct FOPipboyManagerPC : public FUN_007fad10
{
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    void FUN_007f7e00();
};

// Clears the pipboy node pointers, per-index arrays and screen elements, then calls FUN_007fadf0.
// @fnv 0x007f7e00
void FOPipboyManagerPC::FUN_007f7e00()
{
    m_pPipBoyObject0 = 0;
    m_pPipBoyObject1 = 0;
    m_pScreenGeometry = 0;
    for (int i = 0; i < 3; i++)
    {
        m_cPipBoyButtonAvailability[i] = 0;
        m_pButtonGlowObjects[i] = 0;
        m_pGaugeObjects[i] = 0;
        m_fChartFirstPoint[i] = 0;
        m_fChartSecondPoint[i] = 0;
        m_fGaugeValues2[i] = 0;
    }
    m_pPipBoyObject2 = 0;
    reinterpret_cast<::FUN_007fadf0_shell *>(this)->FUN_007fadf0();
}

namespace fnv_007f8610 {
class NiScreenElements : public NiGeometry
{
};

struct SoundPlaybackHandle
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& rhs);
};

struct BSAudio
{
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};

struct FOPipboyManagerPC : public FORenderedMenu
{
    enum Knobs
    {
    };
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    void FUN_007f8610(Knobs aiKnob, float afAmount, float afRate, bool abPlaySound);
};

// @fnv 0x007f8610
void FOPipboyManagerPC::FUN_007f8610(Knobs aiKnob, float afAmount, float afRate, bool abPlaySound)
{
    if (abPlaySound && aiKnob == 0)
    {
        SoundPlaybackHandle soundHandle;
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_007f8610::SoundPlaybackHandle &)(soundHandle))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_007f8610::SoundPlaybackHandle &)(((::fnv_007f8610::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIPipBoyScroll", 0x121))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(soundHandle))->FUN_00ad8830(false);
    }
    m_fChartSecondPoint[aiKnob] += afAmount;
    m_fGaugeValues2[aiKnob] = afRate;
}
}  // namespace fnv_007f8610

namespace fnv_007f8a80 {

class FORenderedMenuPC : public FORenderedMenu
{
  public:
};


struct FOPipboyManagerPC : public FOPipboyManager
{
    void FUN_007f8a80();
};

// @fnv 0x007f8a80
void FOPipboyManagerPC::FUN_007f8a80()
{
    float fchance;

    fchance = ::RandomFloat0To1();
    if (fchance < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db4b4))))))->f)
        reinterpret_cast<::FUN_007fb250_owner *>((((FORenderedMenuPC*)((::Interface *)(::fnv_004b7210::FUN_004b7210()))->GetPipboyManager())))->FUN_007fb250(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db4ec))))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db3fc))))))->f);
    if (fchance >= ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db4b4))))))->f && fchance < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db4b4))))))->f + ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db4e0))))))->f)
        reinterpret_cast<::S_007fb2b0 *>((((FORenderedMenuPC*)((::Interface *)(::fnv_004b7210::FUN_004b7210()))->GetPipboyManager())))->FUN_007fb2b0(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db414))))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db3bc))))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db3b0))))))->f);
    reinterpret_cast<::FORenderedMenu *>((((FORenderedMenuPC*)((::Interface *)(::fnv_004b7210::FUN_004b7210()))->GetPipboyManager())))->StartBurst(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db480))))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db43c))))))->f, 0.5f);
}
}  // namespace fnv_007f8a80

namespace fnv_007fa220 {
class Actor;
class TESAnimGroup
{
  public:
    unsigned int GetType();
};
class NiControllerSequence
{
};
class BSAnimGroupSequence : public NiControllerSequence
{
  public:
};
enum ACTION_FLAGS
{
};
enum ANIM_GROUP_SECTION
{
};
class Animation
{
  public:
};
class PlayerCharacterPC : public PlayerCharacter
{
  public:
};
struct FUN_00424940_shell
{
};
struct Twin_0084d030
{
};

struct FOPipboyManagerPC : public FOPipboyManager
{
    void FUN_007fa220();
};

// @fnv 0x007fa220
void FOPipboyManagerPC::FUN_007fa220()
{
    BSAnimGroupSequence* pIdleSequence;
    Animation* panim;

    if (::fnv_00703d50::FUN_00703d50())
        return;
    if (*(int*)((char*)((::Interface *)(::fnv_004b7210::FUN_004b7210())) + 0x4bc) != 3)
        return;
    if (reinterpret_cast<::FUN_00424940_shell *>((((FUN_00424940_shell*)((::Interface *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00424940() == 4)
        return;
    panim = ((::fnv_007fa220::Animation *)(reinterpret_cast<::PlayerCharacter *>((void *)(((PlayerCharacterPC*)::_g_thePlayer)))->GetAnimation(true)));
    pIdleSequence = (BSAnimGroupSequence*)((::fnv_007fa220::NiControllerSequence *)(reinterpret_cast<::FUN_00491040_shell *>((panim))->FUN_00491040(0)));
    if (pIdleSequence && ((::fnv_007fa220::TESAnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pIdleSequence))->GetAnimGroup()))->GetType() != 1 && reinterpret_cast<::FUN_00494710_shell *>((panim))->FUN_00494710(1))
        reinterpret_cast<::fnv_00494740::FUN_00494740_t *>((panim))->FUN_00494740(1, (*(int *)&(const ::fnv_007fa220::ACTION_FLAGS &)((ACTION_FLAGS)1)), -1, (*(int *)&(const ::fnv_007fa220::ANIM_GROUP_SECTION &)((ANIM_GROUP_SECTION)-1)));
    reinterpret_cast<::FUN_008eeaa0Class *>((panim))->FUN_008eeaa0(0x17);
    reinterpret_cast<::FUN_00491180_shell *>((panim))->FUN_00491180((::TESObjectREFR *)(::fnv_007fa220::Actor *)((Actor*)::_g_thePlayer), reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_007fa220::Twin_0084d030 *>(&::g_timeGlobal))))->GetStoredFloatValue(), -1.0f);
    reinterpret_cast<::ThisStub *>((panim))->FUN_00493900((Actor*)::_g_thePlayer);
}
}  // namespace fnv_007fa220

namespace fnv_007fa810 {
class NiScreenElements : public NiGeometry
{
};

struct SoundPlaybackHandle
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
};

struct ReferenceLightData
{
    NiPointer<NiPointLight> m_pMenuLight;
};

extern double _gModifierZero;

struct FOPipboyManagerPC : public FORenderedMenu
{
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    NiPointer<NiScreenElements> m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiGeometry> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    void UpdatePipboyLightFade(float afTime);
};

// @fnv 0x007fa810
void FOPipboyManagerPC::UpdatePipboyLightFade(float afTime)
{
    ReferenceLightData* plightref;
    float ffade;
    float fdelta;

    fdelta = afTime - m_fFirstPersonLightIntensity;
    ffade = ::FUN_0040ebd0(fdelta / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db308))))))->f, 1.0f);
    ffade = ::FUN_00404010(0.0f, ffade);
    if (m_fThirdPersonLightIntensity == 0.0)
        ffade = 1.0f - ffade;
    plightref = ((::fnv_007fa810::ReferenceLightData *)(reinterpret_cast<::fnv_00572750::XActor *>((::_g_thePlayer))->FUN_00572750()));
    if (plightref && plightref->m_pMenuLight)
        ((NiPointLight*)plightref->m_pMenuLight)->FUN_0050dd20(ffade);
}
}  // namespace fnv_007fa810

namespace fnv_007ff960 {
class NiColor
{
  public:
    float r, g, b;
    NiColor(float, float, float);
};



class NiAVObjectPC : public NiAVObject
{
  public:
};

struct FOPipboyManagerPC : public FOPipboyManager
{
    void CreateTerminalLight();
};

// @fnv 0x007ff960
void FOPipboyManagerPC::CreateTerminalLight()
{
    NiPointLight* plight;

    if (!CreateMenuLight("Omni01", ::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)))
    {
        ::FUN_005b5e40();
        return;
    }
    plight = ((::NiPointLight *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>(this)->FUN_006838b0()));
    if (plight)
    {
        reinterpret_cast<::FUN_004bc280_S *>((plight))->FUN_004bc280((const ::C3 *)&(const ::NiPoint3 &)(NiPoint3(0, 0, 0)));
        reinterpret_cast<::FUN_0050c630_helper *>((plight))->FUN_0050c630(0);
        reinterpret_cast<::fnv_0050c660::FUN_0050c660_shell *>((plight))->FUN_0050c660(0);
        ::FUN_0050c690((::NiDynamicEffect *)(plight), 0);
        plight->FUN_0050dd20(1.0f);
        plight->FUN_0050dd50(NiPoint3(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db644))))))->f, 0, 0));
        {
            NiColor screenLightColor(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db608))))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db668))))))->f, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db5f8))))))->f);
            reinterpret_cast<::FUN_006b0570_shell *>(this)->FUN_006b0570((::NiColor *)&(screenLightColor));
        }
        reinterpret_cast<::FUN_00965580_shell *>(this)->SetIntensity(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db650))))))->f);
        SetScreenLightFlickerIntensity(1.0f);
        NiUpdateData updateData(0, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NiAVObjectPC*)plight)))->FUN_00a59c60((int)&(updateData));
    }
}
}  // namespace fnv_007ff960

struct AnimIdle
{
};
struct GameTimerRecord
{
    int dummy;
};
struct S07f7ee0
{
    void FUN_007f8320(float);
    bool FUN_007f7ee0();
};
// @fnv 0x007f7ee0
bool S07f7ee0::FUN_007f7ee0()
{
    float fappTime;
    if (!reinterpret_cast<::FUN_007faf10_shell *>((this))->UpdateScreenEffect())
        return false;
    fappTime = (float)(unsigned int)((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)&g_timeGlobal)))->FUN_00825c00()));
    this->FUN_007f8320(fappTime);
    reinterpret_cast<::fnv_007fa220::FOPipboyManagerPC *>((this))->FUN_007fa220();
    return true;
}

struct Im7181
{
};
namespace ol4_00985000 {
struct CGBase
{
};
}
struct VTab
{
    virtual int VFn(int);
};
struct FUN_007ffd50_shell
{
    void FUN_007ffd50();
};
// Calls FUN_007ffe40, invokes VFn(1) on the parent if present, then sets procedure type 0 and calls SetRenderedMenu(0) on the FUN_004b7210 result.
// @fnv 0x007ffd50
void FUN_007ffd50_shell::FUN_007ffd50()
{
    VTab* parent;
    FUN_007ffe40();
    {
        NiNode* obj = ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((NiAVObject*)this)))->FUN_009611e0()));
        parent = (VTab*)obj;
    }
    parent ? parent->VFn(1) : 0;
    reinterpret_cast<::TESPackage *>((((ol4_00985000::CGBase*)this)))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(0));
    reinterpret_cast<::fnv_007181d0::FUN_007181d0_shell *>((((Im7181*)((void *)(::fnv_004b7210::FUN_004b7210())))))->SetRenderedMenu((::fnv_007181d0::FORenderedMenu *)(0));
}

// FUN_007fa990: thiscall; calls on two module globals, three far virtual calls
struct G02d98
{
};
class G11dea3c
{
  public:
};

struct Obj
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
    virtual void v064() = 0;
    virtual void v065() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092(G11dea3c* a) = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void v243() = 0;
    virtual void v244() = 0;
    virtual void v245() = 0;
    virtual void v246() = 0;
    virtual void v247() = 0;
    virtual void v248() = 0;
    virtual void v249() = 0;
    virtual void v250() = 0;
    virtual void v251() = 0;
    virtual void v252() = 0;
    virtual void v253() = 0;
    virtual void v254() = 0;
    virtual void v255() = 0;
    virtual void v256() = 0;
    virtual void v257() = 0;
    virtual void v258() = 0;
    virtual void v259() = 0;
    virtual void v260() = 0;
    virtual void v261() = 0;
    virtual void v262() = 0;
    virtual void v263() = 0;
    virtual void v264() = 0;
    virtual void v265() = 0;
    virtual void v266() = 0;
    virtual void v267() = 0;
    virtual void v268() = 0;
    virtual void v269() = 0;
    virtual void v270() = 0;
    virtual void v271() = 0;
    virtual void v272() = 0;
    virtual void v273() = 0;
    virtual void v274() = 0;
    virtual void v275() = 0;
    virtual void v276() = 0;
    virtual void v277() = 0;
    virtual void v278() = 0;
    virtual void v279() = 0;
    virtual void v280() = 0;
    virtual void v281(G11dea3c* a) = 0;
    virtual void v282(int a) = 0;
};


class FUN_007fa990_cls
{
  public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;   // +0x24
    virtual void v10() = 0;  // +0x28
    void FUN_007fa990();
};

// Calls FUN_00c3dfa0(5) on DAT_01202d98, obtains an object from DAT_011dea3c, invokes v092, v282(1) and v281 on it, then v10, v9 and FUN_005db4c0(0).
// @fnv 0x007fa990
void FUN_007fa990_cls::FUN_007fa990()
{
    reinterpret_cast<::IOManager *>((reinterpret_cast<G02d98*>((*reinterpret_cast<unsigned int *>(&::DAT_01202d98)))))->FUN_00c3dfa0(5);
    Obj* obj = ((::Obj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<G11dea3c*>((*reinterpret_cast<unsigned int *>(&::_g_thePlayer)))))->GetBaseTexture()));
    obj->v092(reinterpret_cast<G11dea3c*>((*reinterpret_cast<unsigned int *>(&::_g_thePlayer))));
    obj->v282(1);
    obj->v281(reinterpret_cast<G11dea3c*>((*reinterpret_cast<unsigned int *>(&::_g_thePlayer))));
    v10();
    v9();
    reinterpret_cast<::FUN_005db4c0_struct *>(this)->FUN_005db4c0(0);
}

struct PipBase
{
    PipBase();
    virtual ~PipBase();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
};
struct PipPointer
{
    void* object;
    PipPointer();
    PipPointer(void*);
    ~PipPointer();
    PipPointer& operator=(void*);
};
struct PipSound
{
    int id;
    int state;
    int flags;
    PipSound();
    ~PipSound();
};
struct FUN_007f7a70 : PipBase
{
    PipPointer root, thirdRoot, thirdScreen, partialGeometry;
    PipPointer buttons[3];
    PipPointer glow[3];
    PipPointer knobs[3];
    float positions[3];
    float targets[3];
    float rates[3];
    float tabPositions[5];
    bool scaled;
    float wheelRotation;
    float wheelTarget;
    bool up;
    PipSound sound;
    bool firstLight;
    bool thirdLight;
    bool fading;
    FUN_007f7a70();
    virtual ~FUN_007f7a70();
};
// @fnv 0x007f7a70
FUN_007f7a70::FUN_007f7a70() : root(0), thirdRoot(0), thirdScreen(0), partialGeometry(0)
{
    root = 0;
    thirdRoot = 0;
    partialGeometry = 0;
    for (int index = 0; index < 3; ++index)
    {
        buttons[index] = 0;
        glow[index] = 0;
        knobs[index] = 0;
        positions[index] = 0.0f;
        targets[index] = 0.0f;
        rates[index] = 0.0f;
    }
    scaled = false;
    up = false;
    firstLight = false;
    thirdLight = false;
    reinterpret_cast<::S7f *>(this)->SetValue(true);
    fading = false;
    thirdScreen = 0;
}

struct PipboyBase
{
    virtual ~PipboyBase();
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
};
struct PipboyPointer
{
    void* object;
    ~PipboyPointer();
};
struct FUN_007f7ce0 : PipboyBase
{
    PipboyPointer m_pPipBoyObject0;
    PipboyPointer m_pPipBoyObject1;
    PipboyPointer m_pPipBoyObject2;
    PipboyPointer m_pScreenGeometry;
    PipboyPointer m_cPipBoyButtonAvailability[3];
    PipboyPointer m_pButtonGlowObjects[3];
    PipboyPointer m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    SoundPlaybackHandle m_kPipBoyLightData;
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    virtual ~FUN_007f7ce0();
};
// Destructor that, if FUN_00705ea0() returns true, calls FUN_00703610().
// @fnv 0x007f7ce0
FUN_007f7ce0::~FUN_007f7ce0()
{
    if (::Interface::IsInterfaceActive())
        ::fnv_00703610::FUN_00703610();
}

namespace fnv_007f8320 {
extern float DAT_011db370;

class NiAVObjectHelper : public NiAVObject
{
  public:
};

class S07f7ee0 : public FOPipboyManager
{
  public:
    void FUN_007f8320(float fTime);
};

// @fnv 0x007f8320
void S07f7ee0::FUN_007f8320(float fTime)
{
    bool bUpdated[3];
    float fMoveElapsedTime = fTime - DAT_011db370;
    bUpdated[0] = false;
    bUpdated[1] = false;
    bUpdated[2] = false;

    for (int i = 0; i < 3; i++)
    {
        if (m_fChartSecondPoint[i] > m_fChartFirstPoint[i])
        {
            m_fChartFirstPoint[i] += m_fGaugeValues2[i] * fMoveElapsedTime;
            if (m_fChartFirstPoint[i] > m_fChartSecondPoint[i])
            {
                m_fChartFirstPoint[i] = m_fChartSecondPoint[i];
            }
            bUpdated[i] = true;
        }
        if (m_fChartSecondPoint[i] < m_fChartFirstPoint[i])
        {
            m_fChartFirstPoint[i] -= m_fGaugeValues2[i] * fMoveElapsedTime;
            if (m_fChartFirstPoint[i] < m_fChartSecondPoint[i])
            {
                m_fChartFirstPoint[i] = m_fChartSecondPoint[i];
            }
            bUpdated[i] = true;
        }
    }

    if (m_pGaugeObjects[0] && bUpdated[0])
    {
        reinterpret_cast<::NiAVObject *>((((NiAVObjectHelper*)(NiAVObject*)m_pGaugeObjects[0])))->SetLocalRotation(m_fChartFirstPoint[0], 1.0f, 0.0f, 0.0f);
        NiUpdateData updateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>(((m_pGaugeObjects[0]).operator->()))->FUN_00a59c60((int)&(updateData));
    }

    if (m_pGaugeObjects[1] && bUpdated[1])
    {
        reinterpret_cast<::NiAVObject *>((((NiAVObjectHelper*)(NiAVObject*)m_pGaugeObjects[1])))->SetLocalRotation(m_fChartFirstPoint[1], 0.0f, 0.0f, 1.0f);
        NiUpdateData updateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>(((m_pGaugeObjects[1]).operator->()))->FUN_00a59c60((int)&(updateData));
    }

    if (m_pGaugeObjects[2] && bUpdated[2])
    {
        reinterpret_cast<::NiAVObject *>((((NiAVObjectHelper*)(NiAVObject*)m_pGaugeObjects[2])))->SetLocalRotation(m_fChartFirstPoint[2], 0.0f, 0.0f, 1.0f);
        NiUpdateData updateData(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>(((m_pGaugeObjects[2]).operator->()))->FUN_00a59c60((int)&(updateData));
    }

    DAT_011db370 = fTime;
}
}  // namespace fnv_007f8320

class FadeGeometry : public NiGeometry
{
  public:
};
class PipboyFadeManager : public FORenderedMenu
{
  public:
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    void* m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiAVObject> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    unsigned int backgroundHum[3];
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    bool m_bPipBoyLightOn;
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    void UpdateFade(float);
};
// @fnv 0x007fa540
void PipboyFadeManager::UpdateFade(float now)
{
    if (m_bPipBoyLightOn)
    {
        reinterpret_cast<::fnv_007fa810::FOPipboyManagerPC *>(this)->UpdatePipboyLightFade(now);
        reinterpret_cast<::FOPipboyManager *>(this)->SetPipBoyObjectVisibility(false, true, false);
        NiNode* aTarget = m_pPipBoyObject0;  // Root containing the light effect.
        float time = now - m_fFirstPersonLightIntensity;
        float result = FUN_0040ebd0(time / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011db2bc))))))->f, 1.0f);
        result = FUN_00404010(0.0f, result);
        if (m_fThirdPersonLightIntensity == 0.0)
            result = 1.0f - result;
        NiAVObject* effect = aTarget->GetObjectByName(NiFixedString("PipboyLightEffect"));
        if (!effect)
            effect = aTarget->GetObjectByName(NiFixedString("PipboyLightEffect:0"));
        NiNode* current = 0;
        if (effect)
            current = effect->IsSceneNode();
        if (current && ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((current))->FUN_00453470())))
        {
            FadeGeometry* geometry = static_cast<FadeGeometry*>(current->GetAt(0)->IsGeometry());
            if (geometry)
            {
                NiProperty* property = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geometry))->FUN_00a59d30(FUN_004af350())));
                if (property)
                    reinterpret_cast<::DecalStub *>((property))->FUN_0068c9f0(result);
                else
                {
                    BSShaderProperty* shader = static_cast<BSShaderProperty*>(((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geometry))->FUN_00a59d30(((unsigned int)(::FUN_00438220()))))));
                    reinterpret_cast<::FUN_00ba8ab0_shell *>((shader))->FUN_00ba8ab0(result);
                }
                reinterpret_cast<::FUN_00a5a040_Class *>((geometry))->FUN_00a5a040();
            }
        }
        if (result == m_fThirdPersonLightIntensity)
        {
            m_bPipBoyLightOn = false;
            if (m_fThirdPersonLightIntensity == 0.0)
                reinterpret_cast<::FOPipboyManager *>(this)->SetPipBoyObjectVisibility(false, false, false);
        }
    }
}

namespace fnv_007fa7a0 {
class TimeGlobal
{
  public:
};


struct PipboyStub
{
    char m_auiShapeKeys[0x160];
    bool b1stPersonLightOn;  // 0x160
    char m_pad161;
    bool b3rdPersonLightOn;  // 0x162
    char m_pad163;
    float m_fFirstPersonLightIntensity;  // 0x164
    float m_fThirdPersonLightIntensity;  // 0x168
    void UpdatePipboyLight(bool b);
};

// @fnv 0x007fa7a0
void PipboyStub::UpdatePipboyLight(bool b)
{
    if (b1stPersonLightOn)
    {
        m_fFirstPersonLightIntensity = (float)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_007fa7a0::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
        b3rdPersonLightOn = true;
        if (b)
            m_fThirdPersonLightIntensity = 0.0f;
        else
            m_fThirdPersonLightIntensity = 1.0f;
    }
}
}  // namespace fnv_007fa7a0

#include "generated/data/fallout/interface/fopipboymanager.inc"
