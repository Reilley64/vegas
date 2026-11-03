// src/bsshader/imagespaceshaderparam_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/bsshader/imagespaceshaderparam.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01200000.h"
#include "imagespaceshaderparam_decls.h"
#include "imagespaceshaderparam_types_NiD3DShaderConstantMap.h"
#include "imagespaceshaderparam_types_ImageSpaceShaderParam.h"
struct H
{
    char _0[0x3C];
    float* _pf;
    void SetFloat4At(int aiIndex, float f0, float f1, float f2, float f3);
};
struct FUN_00b8a860_shell
{
    char _pad[0x44];
    float* m_44;
    void SetEntry(int idx, float* src);
};
struct ShaderConstants_4e30
{
};
struct ShaderParamOwner_4e30
{
    ShaderConstants_4e30* pShader;
};
struct PointData_4e30
{
    float x;
    float y;
    float z;
    float radius;
};
struct LightData_4e30
{
    float x;
    float y;
    float z;
    float radius;
    float r;
    float g;
    float b;
    float a;
    float p20;
    float p24;
    float p28;
    float p2C;
};
struct ParamColor_4e30
{
    float r;
    float g;
    float b;
    float a;
};
inline float MaxF_4e30(float a, float b)
{
    return a > b ? a : b;
}
struct ShaderPass_4e30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ShaderParamOwner_4e30* pOwner;
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
    bool bUsePoint;
    char unk59;
    char unk5A;
    char unk5B;
    PointData_4e30* pPoint;
    LightData_4e30* apTargetLight;
    int unk64;
    ParamColor_4e30 kColor;

    bool FUN_00c04e30(int arg);
};

// Native NiObject/NiTexture contracts: JIP-LN-NVSE internal/netimmerse.h.
class NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiObjectCopyInfo;
class NiStream;
class NiBound;
class NiControllerManager;
class NiTimeController;
class NiExtraData;
class NiObject : public NiRefObject
{
  public:
    virtual NiRTTI* GetType();
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
    virtual BSMultiBoundNode* GetMultiBoundNode();
    virtual NiGeometry* GetNiGeometry();
    virtual NiTriBasedGeom* GetTriBasedGeom();
    virtual NiTriStrips* GetTriStrips();
    virtual NiTriShape* GetTriShape();
    virtual BSSegmentedTriShape* GetSegmentedTriShape();
    virtual BSResizableTriShape* GetResizableTriShape();
    virtual NiParticles* GetNiParticles();
    virtual NiLines* GetNiLines();
    virtual bhkNiCollisionObject* GetCollisionObject();
    virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    virtual bhkRigidBody* GetRigidBody();
    virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    virtual NiObject* Clone(NiObjectCopyInfo*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual void RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool Compare(NiObject*);
    virtual void GetViewerStrings(NiTArray<char*, NiTNewInterface<char*> >*);
    virtual void AddViewerStrings(NiTArray<char*, NiTNewInterface<char*> >*);
    virtual void ProcessClone(NiObjectCopyInfo*);
    virtual void PostLinkObject(NiStream*);
    virtual bool StreamCanSkip();
    virtual NiRTTI* GetStreamableRTTI();
    virtual void SetWorldBound(NiBound*);
    virtual unsigned int GetBlockAllocationSize();
    virtual void Unk_20();
    virtual void Unk_21(unsigned int);
    virtual NiControllerManager* GetControllerManager();
};
class NiFixedString
{
  public:
    const char* str;
};
class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_blockName;
    NiTimeController* m_controller;
    NiExtraData** m_extraDataList;
    unsigned short m_extraDataListLen, m_extraDataListCapacity;
};
class NiTexture : public NiObjectNET
{
  public:
    virtual void Unk_23();
    virtual void Unk_24();
    virtual unsigned int GetRenderedWidth();
    virtual unsigned int GetRenderedHeight();
};
struct ImageSpaceTexture
{
};
extern float g_afBlurKernel[15][4];
extern float g_afBlurWeights[8][15][4];

struct BlurParamArray
{
    void* m_ppVirtualMethodTable;
    ImageSpaceShaderParam** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    ImageSpaceShaderParam*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct BlurTexArray
{
    void* m_ppVirtualMethodTable;
    const ImageSpaceTexture** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    const ImageSpaceTexture*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct ImageSpaceEffectFourTexturePass
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    BlurParamArray unk18;
    BlurTexArray unk28;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    bool unk5C;
    bool FUN_00ba4270(int a1);
};

// @fnv 0x00ba4270
bool ImageSpaceEffectFourTexturePass::FUN_00ba4270(int a1)
{
    float m_fGlyphWidthInPixels = (float)((::NiTexture *)(reinterpret_cast<::FUN_00ba3780_struct *>((void *)(unk28.GetAt(2)))->FUN_00ba3780()))->GetRenderedWidth();
    float m_fGlyphExtent = (float)((::NiTexture *)(reinterpret_cast<::FUN_00ba3780_struct *>((void *)(unk28.GetAt(1)))->FUN_00ba3780()))->GetRenderedHeight();
    int iLevel = unk58;
    int iLo = iLevel - 1;
    int iHi = iLo + 1;
    if (iHi > 7)
        iHi = 7;
    if (iLo < 1)
        iLo = 1;
    int iStart = (7 - iHi) * 4;
    float fT = 1.0f - ((float)iLevel - ::DAT_012003c4);
    if (fT == 0.0f)
        fT = 1.0f;
    for (int i = 0; i < 15; i++)
        g_afBlurKernel[i][2] =
            (g_afBlurWeights[iHi - 1][i][2] - g_afBlurWeights[iLo - 1][i][2]) * fT + g_afBlurWeights[iLo - 1][i][2];
    ImageSpaceShaderParam* pParam = unk18.GetAt(0);
    m_fGlyphExtent = 1.0f / m_fGlyphExtent;
    pParam->SetShaderConstantVector4(0, 0.0f, m_fGlyphExtent, 0.0f, 0.0f);
    if (unk5C)
        pParam->SetShaderConstantVector4(17, ::DAT_012003c8, ::DAT_011adbd4, 0.0f, 0.0f);
    pParam->CopyParamData(1, &g_afBlurKernel[0][iStart], (iHi * 2 + 1) * 16);
    pParam = unk18.GetAt(1);
    m_fGlyphWidthInPixels = 1.0f / m_fGlyphWidthInPixels;
    pParam->SetShaderConstantVector4(0, m_fGlyphWidthInPixels, 0.0f, 0.0f, 0.0f);
    pParam->CopyParamData(1, &g_afBlurKernel[0][iStart], (iHi * 2 + 1) * 16);
    return false;
}

#include "generated/data/bsshader/imagespaceshaderparam_rtm_variant.inc"
