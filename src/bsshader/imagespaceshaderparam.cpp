// bsshader/imagespaceshaderparam.cpp: ImageSpaceShaderParam (9 functions)

#include <cstring>
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "imagespaceshaderparam_decls.h"
#include "imagespaceshaderparam_types_NiD3DShaderConstantMap.h"
#include "imagespaceshaderparam_types_ImageSpaceShaderParam.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_01200000.h"

// Releases and reallocates the vertex and pixel constant arrays, then registers them with two new NiD3DShaderConstantMap objects.
// @fnv 0x00b8ab10
void ImageSpaceShaderParam::AllocateShaderConstants(int vertexCount, int pixelCount)
{
    FUN_00b8a7e0();
    m_pVertexShaderConstantMap = new NiD3DShaderConstantMap((*reinterpret_cast<::GraphicsRenderer * *>(&::DAT_011f9508)), 0);
    m_pPixelShaderConstantMap = new NiD3DShaderConstantMap((*reinterpret_cast<::GraphicsRenderer * *>(&::DAT_011f9508)), 2);
    m_iVertexShaderConstantCount = vertexCount + 3;
    if (m_iVertexShaderConstantCount > 0)
    {
        if (m_pfVertexShaderConstants)
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pfVertexShaderConstants);
        m_pfVertexShaderConstants =
            reinterpret_cast<float*>(new ImageSpaceShaderParamFloat[m_iVertexShaderConstantCount * 4]);
        m_pVertexShaderConstantMap.m_pObject->AddConstant(
            "Constant Group", 0x10000000, 0, 0, m_iVertexShaderConstantCount, "", m_iVertexShaderConstantCount * 16, 4,
            m_pfVertexShaderConstants, false);
    }
    m_iPixelShaderConstantCount = pixelCount;
    if (m_iPixelShaderConstantCount > 0)
    {
        if (m_pfPixelShaderConstants)
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pfPixelShaderConstants);
        m_pfPixelShaderConstants =
            reinterpret_cast<float*>(new ImageSpaceShaderParamFloat[m_iPixelShaderConstantCount * 4]);
        m_pPixelShaderConstantMap.m_pObject->AddConstant(
            "Constant Group", 0x10000000, 0, 0, m_iPixelShaderConstantCount, "", m_iPixelShaderConstantCount * 16, 4,
            m_pfPixelShaderConstants, false);
    }
}

// Writes the four floats x, y, z and w into the float array at the given index times four.
// @fnv 0x00b8a790
void ImageSpaceShaderParam::SetShaderConstantVector4(int index, float x, float y, float z, float w)
{
    index *= 4;
    m_pfPixelShaderConstants[index] = x;
    m_pfPixelShaderConstants[index + 1] = y;
    m_pfPixelShaderConstants[index + 2] = z;
    m_pfPixelShaderConstants[index + 3] = w;
}

// @fnv 0x00b8a8d0
void ImageSpaceShaderParam::SetRenderState(unsigned int state, unsigned int value)
{
    reinterpret_cast<::FUN_00844700_Class *>(&(m_kRenderStateMap))->FUN_00844700(state, value);
}

// Releases the object references and deallocates the two buffers, clearing each pointer to null.
// @fnv 0x00b8a7e0
void ImageSpaceShaderParam::FUN_00b8a7e0()
{
    if (m_pVertexShaderConstantMap.m_pObject)
    {
        reinterpret_cast<NiRefObject*>(m_pVertexShaderConstantMap.m_pObject)->DecRefCount();
        m_pVertexShaderConstantMap.m_pObject = 0;
    }
    if (m_pPixelShaderConstantMap.m_pObject)
    {
        reinterpret_cast<NiRefObject*>(m_pPixelShaderConstantMap.m_pObject)->DecRefCount();
        m_pPixelShaderConstantMap.m_pObject = 0;
    }
    if (m_pfVertexShaderConstants)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pfVertexShaderConstants);
        m_pfVertexShaderConstants = 0;
    }
    if (m_pfPixelShaderConstants)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pfPixelShaderConstants);
        m_pfPixelShaderConstants = 0;
    }
}

// Copies size bytes from data into the parameter buffer at offset index*4.
// @fnv 0x00b8a8b0
void ImageSpaceShaderParam::CopyParamData(int index, const float* data, unsigned int size)
{
    std::memmove(m_pfPixelShaderConstants + index * 4, data, size);
}

// @fnv 0x00b8a7c0
void ImageSpaceShaderParam::FUN_00b8a7c0()
{
    m_eClearFlags = DAT_011f9440 ? NiRenderer__ClearFlags_CLEAR_ALL : NiRenderer__ClearFlags_CLEAR_NONE;
}

struct H
{
    char _0[0x3C];
    float* _pf;
    void SetFloat4At(int aiIndex, float f0, float f1, float f2, float f3);
};
// Writes four floats f0..f3 into the float array at offset aiIndex*4+12.
// @fnv 0x00b8a760
void H::SetFloat4At(int aiIndex, float f0, float f1, float f2, float f3)
{
    int idx = aiIndex * 4 + 12;
    _pf[idx] = f0;
    _pf[idx + 1] = f1;
    _pf[idx + 2] = f2;
    _pf[idx + 3] = f3;
}

struct FUN_00b8a860_shell
{
    char _pad[0x44];
    float* m_44;
    void SetEntry(int idx, float* src);
};
// Copies the four floats from src into the float array at m_44 at the slot given by idx.
// @fnv 0x00b8a860
void FUN_00b8a860_shell::SetEntry(int aiIndex, float* apSource)
{
    float fSrc1 = apSource[1];
    float fSrc2 = apSource[2];
    float fSrc3 = apSource[3];
    int iOffset = aiIndex * 4;
    float* pDest = m_44;
    pDest[iOffset] = apSource[0];
    pDest[iOffset + 1] = fSrc1;
    pDest[iOffset + 2] = fSrc2;
    pDest[iOffset + 3] = fSrc3;
}

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

// Sets a shader reference vector and three parameter vectors, using pPoint coordinates for the first when bUsePoint is set.
// @fnv 0x00c04e30
bool ShaderPass_4e30::FUN_00c04e30(int arg)
{
    ShaderConstants_4e30* pShader = pOwner->pShader;
    float fRadius;
    ParamColor_4e30 kParam1;
    ParamColor_4e30 kParam3 = kColor;
    ParamColor_4e30 kParam2;
    if (bUsePoint)
    {
        fRadius = MaxF_4e30(pPoint->radius, apTargetLight->radius);
        kParam1.r = pPoint->x;
        kParam1.g = pPoint->y;
        kParam1.b = pPoint->z;
        kParam1.a = 1.0f;
        kParam3.b = 1.0f;
        kParam3.a = 1.0f;
    }
    else
    {
        fRadius = apTargetLight->radius;
        kParam1.r = apTargetLight->r;
        kParam1.g = apTargetLight->g;
        kParam1.b = apTargetLight->b;
        kParam1.a = apTargetLight->a;
    }
    kParam2.r = apTargetLight->p20;
    kParam2.g = apTargetLight->p24;
    kParam2.b = apTargetLight->p28;
    kParam2.a = apTargetLight->p2C;
    reinterpret_cast<::ImageSpaceShaderParam *>((pShader))->SetShaderConstantVector4(0, apTargetLight->x, apTargetLight->y, apTargetLight->z, fRadius);
    reinterpret_cast<::FUN_00b8a860_shell *>((pShader))->SetEntry(1, &kParam1.r);
    reinterpret_cast<::FUN_00b8a860_shell *>((pShader))->SetEntry(2, &kParam2.r);
    reinterpret_cast<::FUN_00b8a860_shell *>((pShader))->SetEntry(3, &kParam3.r);
    return false;
}

// Native NiObject/NiTexture contracts: JIP-LN-NVSE internal/netimmerse.h.
struct NiRTTI;

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

struct NiStream;

struct NiBound;

struct NiControllerManager;

class NiTimeController;

class NiExtraData;

struct NiObject : public NiRefObject
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

#include "fnv/native_fixed_string.h"

struct NiObjectNET : public NiObject
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

#include "generated/data/bsshader/imagespaceshaderparam.inc"
#include "generated/data/bsshader/imagespaceshaderparam_rtm_variant.inc"
