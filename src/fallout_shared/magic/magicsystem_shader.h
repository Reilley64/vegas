// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MAGICSYSTEM_SHADER_H
#define FNV_MAGICSYSTEM_SHADER_H

#include "layout_support.h"
#include "NiPoint3.h"
#include "TESForm.h"
#include "TESTexture.h"
class BGSDebris;
class EffectShaderData;
class TESEffectShader;
enum _D3DBLEND
{
    _D3DBLEND_D3DBLEND_ZERO = 0,
    _D3DBLEND_D3DBLEND_ONE = 1,
    _D3DBLEND_D3DBLEND_SRCCOLOR = 4,
    _D3DBLEND_D3DBLEND_INVSRCCOLOR = 5,
    _D3DBLEND_D3DBLEND_SRCALPHA = 6,
    _D3DBLEND_D3DBLEND_INVSRCALPHA = 7,
    _D3DBLEND_D3DBLEND_DESTCOLOR = 8,
    _D3DBLEND_D3DBLEND_INVDESTCOLOR = 9,
    _D3DBLEND_D3DBLEND_DESTALPHA = 10,
    _D3DBLEND_D3DBLEND_INVDESTALPHA = 11,
    _D3DBLEND_D3DBLEND_BLENDFACTOR = 12,
    _D3DBLEND_D3DBLEND_INVBLENDFACTOR = 13,
    _D3DBLEND_D3DBLEND_CONSTANTALPHA = 14,
    _D3DBLEND_D3DBLEND_INVCONSTANTALPHA = 15,
    _D3DBLEND_D3DBLEND_SRCALPHASAT = 16,
    _D3DBLEND_D3DBLEND_FORCE_DWORD = 2147483647
};
enum _D3DBLENDOP
{
    _D3DBLENDOP_D3DBLENDOP_ADD = 0,
    _D3DBLENDOP_D3DBLENDOP_SUBTRACT = 1,
    _D3DBLENDOP_D3DBLENDOP_MIN = 2,
    _D3DBLENDOP_D3DBLENDOP_MAX = 3,
    _D3DBLENDOP_D3DBLENDOP_REVSUBTRACT = 4,
    _D3DBLENDOP_D3DBLENDOP_FORCE_DWORD = 2147483647
};
enum _NDLZCMPFUNC
{
    _NDLZCMPFUNC_NDLZCMP_NEVER = 0,
    _NDLZCMPFUNC_NDLZCMP_LESS = 4,
    _NDLZCMPFUNC_NDLZCMP_EQUAL = 2,
    _NDLZCMPFUNC_NDLZCMP_LESSEQUAL = 6,
    _NDLZCMPFUNC_NDLZCMP_GREATER = 1,
    _NDLZCMPFUNC_NDLZCMP_NOTEQUAL = 5,
    _NDLZCMPFUNC_NDLZCMP_GREATEREQUAL = 3,
    _NDLZCMPFUNC_NDLZCMP_ALWAYS = 7,
    _NDLZCMPFUNC_NDLZCMP_FORCE_DWORD = 2147483647
};
class EffectShaderData
{
  public:
    unsigned char cFlags;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    _D3DBLEND m_eDestinationBlend;                // +0x4, 4 bytes
    _D3DBLENDOP m_eBlendOperation;                // +0x8, 4 bytes
    _NDLZCMPFUNC m_eDepthCompareFunction;         // +0xC, 4 bytes
    unsigned int BlendDepthState;                 // +0x10, 4 bytes
    float BlendDepthParameters;                   // +0x14, 4 bytes
    float DepthCompareParameters;                 // +0x18, 4 bytes
    float IndexedFloatParameters;                 // +0x1C, 4 bytes
    float ShaderFloatParameterSet;                // +0x20, 4 bytes
    float ShaderParameterFormatSet;               // +0x24, 4 bytes
    float SevenFloatParameterRecord;              // +0x28, 4 bytes
    float SixFloatAndUnsignedIntegerRecord;       // +0x2C, 4 bytes
    float SixFloatUnsignedIntegerAndFloatRecord;  // +0x30, 4 bytes
    float ExtendedFloatFlagParameters;            // +0x34, 4 bytes
    unsigned int ShaderFloatParameterBlock;       // +0x38, 4 bytes
    float SixFloatRecordWithMiddleFlag;           // +0x3C, 4 bytes
    float FloatFlagParameters;                    // +0x40, 4 bytes
    float SixFloatRecordWithLeadingFlag;          // +0x44, 4 bytes
    float BlendFloatParameters;                   // +0x48, 4 bytes
    float AlphaBlendParameters;                   // +0x4C, 4 bytes
    float BlendStateParameters;                   // +0x50, 4 bytes
    float BlendFactorState;                       // +0x54, 4 bytes
    float BlendModeConfiguration;                 // +0x58, 4 bytes
    _D3DBLEND m_eSourceBlend;                     // +0x5C, 4 bytes
    _D3DBLEND m_eAlphaSourceBlend;                // +0x60, 4 bytes
    _D3DBLENDOP m_eAlphaBlendOperation;           // +0x64, 4 bytes
    _NDLZCMPFUNC m_eAlphaDepthCompareFunction;    // +0x68, 4 bytes
    _D3DBLEND m_eAlphaDestinationBlend;           // +0x6C, 4 bytes
    float AlphaBlendSettings;                     // +0x70, 4 bytes
    float m_fAlphaBlendParameter;                 // +0x74, 4 bytes
    float BlendFactorParameters;                  // +0x78, 4 bytes
    float m_fShaderFloatParameter1;               // +0x7C, 4 bytes
    float m_fShaderFloatParameter2;               // +0x80, 4 bytes
    float m_fShaderFloatParameter3;               // +0x84, 4 bytes
    float m_fShaderFloatParameter4;               // +0x88, 4 bytes
    float m_fShaderFloatParameter5;               // +0x8C, 4 bytes
    float m_fShaderFloatParameter6;               // +0x90, 4 bytes
    NiPoint3 VelocityState;                       // +0x94, 12 bytes
    NiPoint3 m_kVectorState2;                     // +0xA0, 12 bytes
    float m_fShaderFloatParameter7;               // +0xAC, 4 bytes
    float m_fShaderFloatParameter8;               // +0xB0, 4 bytes
    float m_fShaderFloatParameter9;               // +0xB4, 4 bytes
    float m_fShaderFloatParameter10;              // +0xB8, 4 bytes
    unsigned int m_uiColorParameter1;             // +0xBC, 4 bytes
    unsigned int m_uiColorParameter2;             // +0xC0, 4 bytes
    unsigned int m_uiColorParameter3;             // +0xC4, 4 bytes
    float m_fShaderFloatParameter11;              // +0xC8, 4 bytes
    float m_fShaderFloatParameter12;              // +0xCC, 4 bytes
    float m_fShaderFloatParameter13;              // +0xD0, 4 bytes
    float m_fShaderFloatParameter14;              // +0xD4, 4 bytes
    float m_fShaderFloatParameter15;              // +0xD8, 4 bytes
    float m_fShaderFloatParameter16;              // +0xDC, 4 bytes
    float m_fShaderFloatParameter17;              // +0xE0, 4 bytes
    float m_fShaderFloatParameter18;              // +0xE4, 4 bytes
    float m_fShaderFloatParameter19;              // +0xE8, 4 bytes
    float m_fShaderFloatParameter20;              // +0xEC, 4 bytes
    float m_fShaderFloatParameter21;              // +0xF0, 4 bytes
    BGSDebris* pAddonModels;                      // +0xF4, 4 bytes
    float DebrisModelSettings;                    // +0xF8, 4 bytes
    float EffectShaderAddonData;                  // +0xFC, 4 bytes
    float DebrisColorSettings;                    // +0x100, 4 bytes
    float EffectShaderColorData;                  // +0x104, 4 bytes
    float EffectShaderParameters;                 // +0x108, 4 bytes
    unsigned int m_uiBaseColor;                   // +0x10C, 4 bytes
    float m_fFloatAfterDefaultColor;              // +0x110, 4 bytes
    unsigned int m_uiIntegerParameter1;           // +0x114, 4 bytes
    unsigned int m_uiIntegerParameter2;           // +0x118, 4 bytes
    float m_fFirstValueAfterIntegerFields;        // +0x11C, 4 bytes
    float m_fSecondValueAfterIntegerFields;       // +0x120, 4 bytes
    float UnsignedIntAndSixFloatData;             // +0x124, 4 bytes
    float SixFloatValueSet;                       // +0x128, 4 bytes
    float FiveFloatData;                          // +0x12C, 4 bytes
    float FourFloatValueSet;                      // +0x130, 4 bytes
    // void __cdecl EffectShaderData::*()
    // void __cdecl EffectShaderData::*()
    // void __cdecl EffectShaderData::*()
};
class TESEffectShader : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    EffectShaderData Data;                // +0x18, 308 bytes
    TESTexture m_kFillTexture;            // +0x14C, 12 bytes
    TESTexture m_kParticleShaderTexture;  // +0x158, 12 bytes
    TESTexture m_kHolesTexture;           // +0x164, 12 bytes
    TESEffectShader();
    // void __cdecl TESEffectShader::*()
    // EffectShaderData* __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*()
    // bool __cdecl TESEffectShader::*(TESFile*)
    // void __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(TESForm*)
    // bool __cdecl TESEffectShader::*(TESForm*)
    // void __cdecl TESEffectShader::*()
    // _D3DBLEND __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_D3DBLEND)
    // _D3DBLEND __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_D3DBLEND)
    // _D3DBLENDOP __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_D3DBLENDOP)
    // _NDLZCMPFUNC __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_NDLZCMPFUNC)
    // TESTexture* __cdecl TESEffectShader::*()
    // unsigned int __cdecl TESEffectShader::*()
    // SetFillColor
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // unsigned int __cdecl TESEffectShader::*()
    // SetEdgeColor
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // _D3DBLEND __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_D3DBLEND)
    // _D3DBLEND __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_D3DBLEND)
    // _D3DBLENDOP __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_D3DBLENDOP)
    // _NDLZCMPFUNC __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(_NDLZCMPFUNC)
    // TESTexture* __cdecl TESEffectShader::*()
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // NiPoint3 __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(NiPoint3)
    // void __cdecl TESEffectShader::*(float)
    // void __cdecl TESEffectShader::*(float)
    // void __cdecl TESEffectShader::*(float)
    // NiPoint3 __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(NiPoint3)
    // void __cdecl TESEffectShader::*(float)
    // void __cdecl TESEffectShader::*(float)
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // unsigned int __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(unsigned int)
    // unsigned int __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(unsigned int)
    // unsigned int __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(unsigned int)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // BGSDebris* __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(BGSDebris*)
    // TESTexture* __cdecl TESEffectShader::*()
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // unsigned int __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(unsigned int)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // unsigned int __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(unsigned int)
    // unsigned int __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(unsigned int)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*()
    // void __cdecl TESEffectShader::*(float)
    // ParticleShaderProperty* __cdecl TESEffectShader::*(NiAVObject*, NiAVObject*, NiSourceTexture*, float)
    // void __cdecl TESEffectShader::*(ParticleShaderProperty*, NiSourceTexture*)
    // void __cdecl TESEffectShader::*(NiAVObject*, ParticleShaderProperty*)
    // BSShaderPPLightingProperty::TextureEffectData* __cdecl TESEffectShader::*(NiAVObject*, NiSourceTexture*, NiSourceTexture*)
    // void __cdecl TESEffectShader::*(NiAVObject*, BSShaderPPLightingProperty::TextureEffectData*)
    // void __cdecl TESEffectShader::*(NiAVObject*, BSShaderPPLightingProperty::TextureEffectData*)
    // void __cdecl TESEffectShader::*(BSShaderPPLightingProperty::TextureEffectData*, float, float, float, bool)
    // float __cdecl TESEffectShader::*(float, float, float, bool)
    // float __cdecl TESEffectShader::*(float, float, float, bool)
    // float __cdecl TESEffectShader::*(float, float, float, bool, float, float, float, float, float)
    // float __cdecl TESEffectShader::*(float, float, float, bool)
    // float __cdecl TESEffectShader::*(float)
    // float __cdecl TESEffectShader::*(float)
    // bool __cdecl TESEffectShader::*(TESEffectShader::EffectShaderFlags)
    // void __cdecl TESEffectShader::*(TESEffectShader::EffectShaderFlags, bool)
    // TESEffectShader& __cdecl TESEffectShader::*(const TESEffectShader&)
    // void __cdecl TESEffectShader::*()
};
#endif
