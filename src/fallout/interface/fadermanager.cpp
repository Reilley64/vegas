// fallout/interface/fadermanager.cpp: FaderManager, FM7 (10 functions)

#include <cstdint>
#include "fnv/decl/Bound88.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004bc280_S.h"
#include "fnv/decl/FUN_00821600_shell.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00aa4db0_shell.h"
#include "fnv/decl/FUN_00aa4ee0_t.h"
#include "fnv/decl/S457d70.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004de000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fadermanager_object_decls.h"

// Returns true if the fader's fade node exists, its flag is set, and its alpha equals 1.0.
// @fnv 0x00701450
bool FaderManager::HasFader(FADER_ENUM eFader)
{
    FaderEntry* pFader = &s_faders[eFader];
    if (pFader->pFadeNode != 0)
        if (pFader->bUnk08)
            if (pFader->fAlpha == 1.0)
                return true;
    return false;
}

// @fnv 0x007014e0
float FaderManager::GetFadeValue(FADER_ENUM eFader)
{
    return s_faders[eFader].fAlpha;
}

// @fnv 0x007010e0
void FaderManager::StopFader(FADER_ENUM eFader, bool bForce)
{
    if (s_faders[eFader].pFadeNode == 0)
        return;
    if (bForce || s_bAllowDetach)
    {
        ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((s_faders[eFader].pFadeNode))->FUN_009611e0()))->RemoveObject(s_faders[eFader].pFadeNode);
        s_faders[eFader].pFadeNode = 0;
        s_faders[eFader].fAlpha = 0.0f;
        s_faders[eFader].m_pParentNode = 0;
        reinterpret_cast<::S457d70 *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00457d70(0, (::Form457 *)(0), 0);
    }
    else
    {
        s_faders[eFader].bUnk08 = false;
        if (s_faders[eFader].fAlpha == 1.0)
            s_faders[eFader].fAlpha = ::DAT_0106ea1c;
    }
}

#include "fadermanager_update_decls.h"
static signed char s_iFadeDelay;

#include "fadermanager_create_decls.h"

// @fnv 0x00700960
void FaderManager::AddFader(FADER_ENUM eFader, float fDuration, bool bFadeOut)
{
    AutoMemContext kAllocationContext(MEM_CONTEXT_INTERFACE, true,
                                      "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\FaderManager.cpp",
                                      135);
    if (s_faders[eFader].pFadeNode)
    {
        if (!s_faders[eFader].bUnk08)
            StopFader(eFader, true);
        else
            return;
    }
    NiPoint3* pScreenVertices = new NiPoint3[4];
    FaderSurfaceParameters surface;
    surface.pTexCoords = new NiPoint2[4];
    unsigned short* pTriangles = (unsigned short*)::FUN_00aa1070(12);
    float fHalfScreenWidth = ((int)(::FUN_004dc1f0())) * 0.5;
    float fHalfHeight = FUN_004dc200() * 0.5;
    pScreenVertices[0] = NiPoint3(-fHalfScreenWidth, 0.0f, fHalfHeight);
    pScreenVertices[1] = NiPoint3(-fHalfScreenWidth, 0.0f, -fHalfHeight);
    pScreenVertices[2] = NiPoint3(fHalfScreenWidth, 0.0f, fHalfHeight);
    pScreenVertices[3] = NiPoint3(fHalfScreenWidth, 0.0f, -fHalfHeight);
    surface.pTexCoords[0] = NiPoint2(0.0f, 0.0f);
    surface.pTexCoords[1] = NiPoint2(0.0f, 1.0f);
    surface.pTexCoords[2] = NiPoint2(1.0f, 0.0f);
    surface.pTexCoords[3] = NiPoint2(1.0f, 1.0f);
    pTriangles[0] = 0;
    pTriangles[1] = 1;
    pTriangles[2] = 2;
    pTriangles[3] = 2;
    pTriangles[4] = 1;
    pTriangles[5] = 3;
    s_faders[eFader].pFadeNode = (BSFadeNode*)new NiSortAdjustNode(0);
    ::AssignFixedString((char *)(s_faders[eFader].pFadeNode), (int)&(const ::NiFixedString &)(NiFixedString(s_faders[eFader].pTextureName)), {});
    NiAlphaProperty* pBlendingProperty = new NiAlphaProperty;
    reinterpret_cast<::FUN_0049ed90_shell *>((pBlendingProperty))->FUN_0049ed90(true);
    reinterpret_cast<::FUN_00439410_cls *>((s_faders[eFader].pFadeNode))->FUN_00439410((::ArgObject *)(pBlendingProperty));
    NiTriShape* faderShape = new NiTriShape(4, pScreenVertices, 0, 0, surface.pTexCoords, 1, 0, 2, pTriangles);
    s_faders[eFader].pFadeNode->AddObject(faderShape, true);
    BSStringT<char> textureName;
    ::FUN_00406f60((::FUN_00406f90_this *)&(textureName), "Data\\Textures\\Interface\\Faders\\%s", s_faders[eFader].pTextureName);
    ::AssignFixedString((char *)(faderShape), (int)&(const ::NiFixedString &)(NiFixedString(((const char *)(::FUN_00559450((int *)&(textureName)))))), {});
    NiPointer<NiTexture> spTextureImage(
        ::NiSourceTexture::Create(NiFixedString(((const char *)(::FUN_00559450((int *)&(textureName))))), (::NiTexture__FormatPrefs &)((*reinterpret_cast<::NiTexture::TextureFormatPreferences *>(&::DAT_011a9598))), true, false));
    surface.fInitialAlpha = 0.0f;
    if (bFadeOut || fDuration == 0.0)
    {
        surface.fInitialAlpha = 1.0f;
        s_iFadeDelay = 3;
    }
    TileShaderProperty* pTileShader = new TileShaderProperty(false);
    pTileShader->FUN_00bb7a10(spTextureImage);
    reinterpret_cast<::FUN_008cc6d0_class *>((pTileShader))->FUN_008cc6d0(3);
    reinterpret_cast<::FUN_00821600_shell *>((pTileShader))->FUN_00821600(surface.fInitialAlpha);
    reinterpret_cast<::FUN_00439410_cls *>((faderShape))->FUN_00439410((::ArgObject *)(::NiObject *)((NiObject*)pTileShader));
    s_faders[eFader].m_pParentNode = (NiNode*)pTileShader;
    BSShaderManager::UpdateObjectTypeRecurse(faderShape, false, false);
    reinterpret_cast<::Bound88 *>((((::NiBound *)(::GetSourceFilesFromForm((char *)(faderShape))))))->ComputeBoundingSphere(4, (const ::Vec88 *)(pScreenVertices));
    NiNode* pRoot = m_pRootAboveMenus;
    if (s_faders[eFader].m_bUseAlternateRoot)
        pRoot = m_pRootBelowMenus;
    pRoot->AddObject(s_faders[eFader].pFadeNode, true);
    reinterpret_cast<::FUN_00a5a040_Class *>((pRoot))->FUN_00a5a040();
    NiUpdateData updateParams(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((pRoot))->FUN_00a59c60((std::intptr_t)&(updateParams));
    s_faders[eFader].fUnk0C = fDuration;
    s_faders[eFader].bUnk08 = !bFadeOut;
    s_faders[eFader].fAlpha = surface.fInitialAlpha;
}

// @fnv 0x007006c0
void FaderManager::AddRoot(NiNode* pParent, float m_fProjectionDepth, bool abBelowMenus)
{
    AutoMemContext kContext(MEM_CONTEXT_INTERFACE, true,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\FaderManager.cpp", 80);
    NiSortAdjustNode* pSortAdjustNode = new NiSortAdjustNode(0);
    if (abBelowMenus)
    {
        m_pRootBelowMenus = pSortAdjustNode;
        ::AssignFixedString((char *)(pSortAdjustNode), (int)&(const ::NiFixedString &)(NiFixedString("FaderNode Below Menus")), {});
    }
    else
    {
        m_pRootAboveMenus = pSortAdjustNode;
        ::AssignFixedString((char *)(pSortAdjustNode), (int)&(const ::NiFixedString &)(NiFixedString("FaderNode Above Menus")), {});
        m_fProjectionDepth -= 20.0;
    }
    NiDirectionalLight* apTargetLight = new NiDirectionalLight;
    ::AssignFixedString((char *)(apTargetLight), (int)&(const ::NiFixedString &)(NiFixedString("FaderNodeLight")), {});
    reinterpret_cast<::FUN_004bc280_S *>((apTargetLight))->FUN_004bc280((const ::C3 *)&(const ::NiPoint3 &)(NiPoint3(1.0f, 1.0f, 1.0f)));
    // This helper's canonical binding is a folded NiObject::LinkObject alias.
    ::FUN_00a89af0((std::intptr_t)(apTargetLight));
    pSortAdjustNode->AddObject(apTargetLight, true);
    float m_fGlyphWidthInPixels = (float)((int)(::FUN_004dc1f0()));
    float halfHeight = (float)FUN_004dc200();
    float fScale = 1.0f;
    if (halfHeight / m_fGlyphWidthInPixels != 0.75)
        fScale = 4.0f / 3.0f;
    if (m_fGlyphWidthInPixels != 1280.0)
        fScale *= 1280.0 / m_fGlyphWidthInPixels;
    if (FUN_004de070())
        fScale = 1.0f;
    reinterpret_cast<::FUN_00440490_shell *>((pSortAdjustNode))->FUN_00440490(fScale);
    reinterpret_cast<::FUN_00440460_S *>((pSortAdjustNode))->FUN_00440460((const ::V3 *)&(const ::NiPoint3 &)(NiPoint3(0.0f, m_fProjectionDepth, 0.0f)));
    pParent->AddObject(pSortAdjustNode, true);
}

struct GameTimerRecord
{
    void Update();
    float GetSeconds();
    float GetUnmodifiedSeconds();
    unsigned int GetTime();
    unsigned int GetStartTime();
    void ClampAt(unsigned int);
    bool QEnabled();
    bool GetSecondsIsZero();
    static void SetGlobalTimeMultiplierCache();
    void RestoreGlobalTimeMultiplierCache();
    static float QGlobalTimeMultiplier();
    static float QGlobalTimeMultiplierTarget();
    static void UpdateGlobalTimeMultiplier();
    void SetUseGlobalTimeMultiplierTarget(bool);
    bool QUseGlobalTimeMultiplierTarget();
    float GetRealTimeSeconds();
    void Enable();
    void Disable();
    void Init(unsigned int);
    unsigned char m_ucFirstTimerByte;
    char _pad_1[3];
    float m_fFirstTimerValue;
    float m_fSecondTimerValue;
    float fTimeSinceScaleStart;
    float m_fFourthTimerValue;
    unsigned int m_uiFirstTimerValue;
    unsigned int m_uiSecondTimerValue;
    bool m_bFirstTimerFlag;
    bool m_bSecondTimerFlag;
    char _pad_1e[2];
};
struct FUN_007013e0_shell : public GameTimerRecord
{
    float FUN_007013e0();
};
// Steps each fader's alpha toward 1 or 0 using elapsed time, removes faded-out nodes, and applies alpha to their shader properties.
// @fnv 0x007011d0
void FaderManager::AdvanceFaders(bool bUpdate)
{
    AutoMemContext context(MEM_CONTEXT_INTERFACE, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\FaderManager.cpp", 266);
    for (int i = 0; i < FADER_ENUM_FADER_COUNT; ++i)
    {
        FaderEntry* pFader = &s_faders[i];
        if (pFader->pFadeNode)
        {
            if (pFader->bUnk08)
            {
                if (pFader->fAlpha < 1.0)
                {
                    pFader->fAlpha += reinterpret_cast<::FUN_007013e0_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_007013e0() / pFader->fUnk0C;
                    if (pFader->fAlpha > 1.0)
                        pFader->fAlpha = 1.0f;
                    if (pFader->m_pParentNode)
                        reinterpret_cast<::FUN_00821600_shell *>((((TileShaderProperty*)(NiNode*)pFader->m_pParentNode)))->FUN_00821600(pFader->fAlpha);
                }
            }
            else
            {
                if (pFader->fAlpha <= 0.0)
                {
                    if (pFader->pFadeNode && ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((pFader->pFadeNode))->FUN_009611e0())))
                        ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((pFader->pFadeNode))->FUN_009611e0()))->RemoveObject(pFader->pFadeNode);
                    pFader->pFadeNode = 0;
                    pFader->fAlpha = 0.0f;
                }
                else
                {
                    if (s_iFadeDelay)
                        --s_iFadeDelay;
                    else
                        pFader->fAlpha -= reinterpret_cast<::FUN_007013e0_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_007013e0() / pFader->fUnk0C;
                    if (pFader->fAlpha < 0.0)
                        pFader->fAlpha = 0.0f;
                    if (pFader->m_pParentNode)
                        reinterpret_cast<::FUN_00821600_shell *>((((TileShaderProperty*)(NiNode*)pFader->m_pParentNode)))->FUN_00821600(pFader->fAlpha);
                }
            }
        }
    }
}


// @fnv 0x007013e0
float FUN_007013e0_shell::FUN_007013e0()
{
    return fTimeSinceScaleStart / DAT_011ac3a0;
}

struct FaderRec7
{
    char pad0[8];
    unsigned char f8;
    char pad1[7];
    int f10;
    float f14;
    char pad2[4];
};
struct FM7
{
    bool IsFaderActive(int);
};
// Returns true when the fader at idx has a nonzero f10 and f8 and its f14 is below 1.0.
// @fnv 0x00701400
bool FM7::IsFaderActive(int aiIndex)
{
    FaderRec7* f = (FaderRec7*)&s_faders[aiIndex];
    if (f->f10 && f->f8 && f->f14 < 1.0)
        return true;
    return false;
}

namespace fnv_007014a0 {
struct FaderRec7
{
    char pad0[8];
    unsigned char f8;
    char pad1[7];
    int f10;
    char pad2[8];
};
struct FM7
{
    bool FUN_007014a0(int);
};
// Returns true when the fader record at idx has a nonzero f10 and a nonzero f8.
// @fnv 0x007014a0
bool FM7::FUN_007014a0(int aiIndex)
{
    FaderRec7* f = (FaderRec7*)&s_faders[aiIndex];
    if (f->f10 && f->f8)
        return true;
    return false;
}
}  // namespace fnv_007014a0

struct FUN_006ffe80_shell
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24;
    unsigned char m_28, m_29;
    void FUN_006ffe80(int, int);
    void FUN_006ffe10();
};
// Calls FUN_006ffe80(0, 0), then initializes fields from DAT_0119f278/27c/280 and zeroes m_20, m_1c, m_24, m_29 while setting m_28 to 1.
// @fnv 0x006ffe10
void FUN_006ffe80_shell::FUN_006ffe10()
{
    FUN_006ffe80(0, 0);
    m_10 = DAT_0119f278;
    m_14 = DAT_0119f27c;
    m_18 = DAT_0119f280;
    m_20 = 0;
    m_1c = 0;
    m_24 = 0;
    m_28 = 1;
    m_29 = 0;
}

#include "generated/data/fallout/interface/fadermanager.inc"
