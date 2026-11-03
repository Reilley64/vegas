
// src/bsshader/bsshaderdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bsshaderdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include <cstring>
#include "fnv/decl/FUN_00baff20_Class.h"
#include "fnv/decl/FUN_00be1750_shell.h"
#include "fnv/decl/WorkerSource.h"
#include "fnv/decl/fnv_00bafe10__Src.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_01200000.h"
struct BSMaterialEmittanceMultController;
struct BSRefractionFirePeriodController;
struct BSRefractionStrengthController;
struct BSShaderNoLightingProperty;
struct BSShaderPPLightingProperty;
struct BSShaderProperty;
struct BSShaderTextureSet;
struct NiAVObject;
struct NiAlphaController;
struct NiMaterialColorController;
struct SkyShaderProperty;
struct TallGrassShaderProperty;
struct TileShaderProperty;
struct VolumetricFogShaderProperty;
struct ShaderPropertyConversionData
{
    void Convert(NiAVObject*, unsigned int);
    void CheckTextureAlphas();
    BSShaderProperty* GetShaderProperty();
    void SetupShaderFlags(BSShaderProperty*, NiAVObject*);
    void SetupTexturesPPLightingShader(BSShaderPPLightingProperty*);
    void SetupDataPPLightingShader(BSShaderPPLightingProperty*);
    void SetupTexturesNoLightingShader(BSShaderNoLightingProperty*);
    void SetupDataVolumetricFogShader(VolumetricFogShaderProperty*);
    void SetupTexturesTallGrassShader(TallGrassShaderProperty*);
    void SetupTexturesSkyShader(SkyShaderProperty*);
    void SetupDataSkyShader(SkyShaderProperty*);
    void SetupTexturesTileShader(TileShaderProperty*);
    bool IsValidProperty(NiAVObject*, BSShaderProperty*);
    int m_iShaderType;
    char m_kAmbientColor[12];
    char m_kDiffuseColor[12];
    float m_fShininess;
    float fAlpha;
    float m_fEmittanceMultiplier;
    NiMaterialColorController* m_pAmbientColorController;
    NiMaterialColorController* m_pDiffuseColorController;
    NiAlphaController* m_pAlphaController;
    BSMaterialEmittanceMultController* m_pEmittanceMultiplierController;
    bool m_bHasMaterialProperty;
    char _pad_39[3];
    int m_iShaderFlags1;
    int m_iShaderFlags2;
    bool m_bHasAlphaProperty;
    char _pad_45[3];
    int m_iShaderOption;
    unsigned char m_uiShaderOptionByte;
    bool m_bShaderFeature1;
    bool m_bShaderFeature2;
    bool m_bShaderFeature3;
    bool m_bShaderFeature4;
    bool m_bShaderFeature5;
    bool m_bShaderFeature6;
    bool m_bShaderFeatureActive;
    bool m_bShaderFeature8;
    bool m_bShaderFeature9;
    bool m_bShaderFeature10;
    bool m_bShaderFeature11;
    float m_fValueBeforeTextureCount;
    bool m_bShaderFeature12;
    char _pad_5d[3];
    int m_iTextureCount;
    BSRefractionStrengthController* m_pRefractionStrengthController;
    BSRefractionFirePeriodController* m_pRefractionFirePeriodController;
    bool m_bShaderFeature13;
    bool m_bShaderFeature14;
    char _pad_6e[2];
    float m_fRefractionStrength;
    float m_fRefractionFirePeriod;
    char m_kSpecularColor[12];
    float m_fShaderParameter1;
    bool m_bShaderFeature15;
    bool m_bShaderFeature16;
    bool m_bShaderFeature17;
    char _pad_8b[1];
    float m_fShaderParameter2;
    int m_iShaderOptionIndex;
    bool m_bShaderFeature18;
    char _pad_95[3];
    char m_kEmissiveColor[16];
    BSShaderTextureSet* m_pTextureSet;
    char m_cTrailingBytes[7];
    char _pad_b3[1];
    int m_iShaderDataFlags;
};
struct NiMemObject
{
    char _pad_0[1];
};
struct FUN_00bb0180_shell : public ShaderPropertyConversionData
{
    void AddProperties(NiAVObject*, unsigned int);
};

// Adds an alpha, material and/or shader property to apTarget according to the bits set in auiProperties.
// @fnv 0x00bb0180
void FUN_00bb0180_shell::AddProperties(NiAVObject* apTarget, unsigned int auiProperties)
{
    if (auiProperties & 1)
        reinterpret_cast<::WorkerSource *>(this)->UpdateWorkerObject((::WorkerTarget *)(apTarget));
    if (auiProperties & 2)
        reinterpret_cast<::fnv_00bafe10::Src *>(this)->CreateAndAttachMaterialProperty((::fnv_00bafe10::NiAVObject_Attach *)(apTarget));
    if (auiProperties & 4)
        reinterpret_cast<::FUN_00baff20_Class *>(this)->AttachAlphaProperty(apTarget);
}

extern int DAT_012005e0;

struct FUN_00bb0490_shell
{
    void CallVirtualMethod74();
};

// @fnv 0x00bb0490
void FUN_00bb0490_shell::CallVirtualMethod74()
{
    ((void(*)(void*, int))(*reinterpret_cast<void***>(this))[0x4a])(this, DAT_012005e0);
}

struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
struct NiD3DPixelShader
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct ShaderPtr
{
    T* m_pObject;
    ShaderPtr& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct NiD3DGPUProgramCache
{
    static const char* __cdecl GetPixelShaderProfile(bool);
public:
    static const char *GetVertexShaderProfile();
};
struct BSShader
{
};
struct PrecipShaderDef
{
    const char* pFile;
    _D3DXMACRO Macros[9];
};
struct FUN_00bb0360_t : BSShader
{
    void CreatePrecipitationPixelShaders();
};

// @fnv 0x00bb0360
void FUN_00bb0360_t::CreatePrecipitationPixelShaders()
{
    PrecipShaderDef ShaderDefs[2];
    ShaderDefs[0].pFile = "precipitation\\precipitation.p.hlsl";
    ShaderDefs[0].Macros[0].Name = 0;
    std::memset(&ShaderDefs[0].Macros[0].Definition, 0, 0x44);
    ShaderDefs[1].pFile = "precipitation\\precipitation.p.hlsl";
    ShaderDefs[1].Macros[0].Name = "SNOW";
    ShaderDefs[1].Macros[0].Definition = 0;
    ShaderDefs[1].Macros[1].Name = 0;
    std::memset(&ShaderDefs[1].Macros[1].Definition, 0, 0x3c);
    char acName[260];
    char acPath[260];
    for (int i = 0; i < 2; i++)
    {
        ::FUN_00be0c00(ShaderDefs[i].pFile, acPath);
        ::FUN_00406d00(acName, 260, "PRECIP%03i.pso", i);
        (*reinterpret_cast<ShaderPtr<NiD3DPixelShader> (*)[2]>(&::g_aspSmall))[i] = reinterpret_cast<::FUN_00be1750_shell *>(this)->FUN_00be1750((char *)(acPath), (void *)(ShaderDefs[i].Macros),
                                             (char *)(NiD3DGPUProgramCache::GetPixelShaderProfile(false)), (char *)(acName));
    }
}

struct NiD3DVertexShader
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct VSProfileCache
{
};
struct BSShaderVS
{
};
struct FUN_00bb01c0_t : BSShaderVS
{
    void CreatePrecipitationVertexShaders();
};

// @fnv 0x00bb01c0
void FUN_00bb01c0_t::CreatePrecipitationVertexShaders()
{
    PrecipShaderDef shaderDefs[4];
    shaderDefs[0].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[0].Macros[0].Name = "BILLBOARD_UP";
    shaderDefs[0].Macros[0].Definition = 0;
    shaderDefs[0].Macros[1].Name = 0;
    std::memset(&shaderDefs[0].Macros[1].Definition, 0, 0x3c);
    shaderDefs[1].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[1].Macros[0].Name = "BILLBOARD_FACE";
    shaderDefs[1].Macros[0].Definition = 0;
    shaderDefs[1].Macros[1].Name = 0;
    std::memset(&shaderDefs[1].Macros[1].Definition, 0, 0x3c);
    shaderDefs[2].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[2].Macros[0].Name = "BILLBOARD_UP";
    shaderDefs[2].Macros[0].Definition = 0;
    shaderDefs[2].Macros[1].Name = "SNOW";
    shaderDefs[2].Macros[1].Definition = 0;
    shaderDefs[2].Macros[2].Name = 0;
    std::memset(&shaderDefs[2].Macros[2].Definition, 0, 0x34);
    shaderDefs[3].pFile = "precipitation\\precipitation.v.hlsl";
    shaderDefs[3].Macros[0].Name = "BILLBOARD_FACE";
    shaderDefs[3].Macros[0].Definition = 0;
    shaderDefs[3].Macros[1].Name = "SNOW";
    shaderDefs[3].Macros[1].Definition = 0;
    shaderDefs[3].Macros[2].Name = 0;
    std::memset(&shaderDefs[3].Macros[2].Definition, 0, 0x34);
    for (int i = 0; i < 4; i++)
    {
        char shaderName[260];
        char shaderPath[260];
        ::FUN_00be0c00(shaderDefs[i].pFile, shaderPath);
        ::FUN_00406d00(shaderName, 260, "PRECIP%03i.vso", i);
        (*reinterpret_cast<ShaderPtr<NiD3DVertexShader> (*)[4]>(&::g_aspLarge))[i] =
            ((::NiD3DVertexShader *)(::fnv_00be0fe0::FUN_00be0fe0((const char *)this, (::_D3DXMACRO *)(shaderPath), (const char *)(shaderDefs[i].Macros), ::NiD3DGPUProgramCache::GetVertexShaderProfile())));
    }
}
