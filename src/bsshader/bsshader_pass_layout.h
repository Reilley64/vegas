// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PRIVATE_BSSHADER_PASS_H
#define FNV_PRIVATE_BSSHADER_PASS_H

#include "layout_support.h"
#include "layout_support.h"
class NiD3DPass;
class NiD3DPixelShader;
class D3DRenderStateGroup;
class NiD3DShaderConstantMap;
class BeamStage;
class NiD3DVertexShader;
class NiD3DPass
{
  public:
    void DestroyPass();
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            DestroyPass();
    }
    void** m_ppVirtualMethodTable;                                                // +0x0, 4 bytes
    char m_szName[16];                                              // +0x4, 16 bytes
    unsigned int m_uiStageMask;                                     // +0x14, 4 bytes
    unsigned int m_uiNumberOfStages;                                // +0x18, 4 bytes
    unsigned int m_uiStageOffset;                                   // +0x1C, 4 bytes
    NiTObjectArray<NiPointer<BeamStage> > m_kStageArray;            // +0x20, 16 bytes
    D3DRenderStateGroup* m_pRenderStateGroup;                       // +0x30, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;   // +0x34, 4 bytes
    char* m_pcPixelShaderFile;                                      // +0x38, 4 bytes
    char* m_pcPixelShaderFunction;                                  // +0x3C, 4 bytes
    char* m_pcPixelShaderProfile;                                   // +0x40, 4 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderObject;              // +0x44, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;  // +0x48, 4 bytes
    char m_bUsesSecondShaderConstantMap;                            // +0x4C, 1 bytes
    unsigned char layoutPadding4D[3];
    char* m_pcVertexShaderFile;                           // +0x50, 4 bytes
    char* m_pcVertexShaderFunction;                       // +0x54, 4 bytes
    char* m_pcVertexShaderProfile;                        // +0x58, 4 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShaderObject;  // +0x5C, 4 bytes
    bool m_bIsInitialized;                                // +0x60, 1 bytes
    bool m_bHasBeenApplied;                               // +0x61, 1 bytes
    unsigned char layoutPadding62[2];
    unsigned int m_uiRefCount;  // +0x64, 4 bytes
    // NiD3DPass
    // void __cdecl NiD3DPass::*(NiPointer<NiD3DPass>&)
    // const char* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(char*)
    // D3DRenderStateGroup* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(D3DRenderStateGroup*)
    // void __cdecl NiD3DPass::*(unsigned int, unsigned int, bool)
    // void __cdecl NiD3DPass::*(unsigned int, unsigned int, bool)
    // void __cdecl NiD3DPass::*(float)
    // bool __cdecl NiD3DPass::*(unsigned int)
    // bool __cdecl NiD3DPass::*(unsigned int, unsigned int&, bool&)
    // unsigned int __cdecl NiD3DPass::*()
    // unsigned int __cdecl NiD3DPass::*(unsigned int)
    // unsigned int __cdecl NiD3DPass::*(unsigned int)
    // NiD3DShaderConstantMap* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(NiD3DShaderConstantMap*)
    // const char* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(const char*)
    // const char* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(const char*)
    // const char* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(const char*)
    // NiD3DPixelShader* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(NiD3DPixelShader*)
    // NiD3DShaderConstantMap* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(NiD3DShaderConstantMap*)
    // const char* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(const char*)
    // const char* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(const char*)
    // const char* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(const char*)
    // NiD3DVertexShader* __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(NiD3DVertexShader*)
    // bool __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(bool)
    // unsigned int __cdecl NiD3DPass::*()
    // unsigned int __cdecl NiD3DPass::*()
    // unsigned int __cdecl NiD3DPass::*()
    // BeamStage* __cdecl NiD3DPass::*(unsigned int)
    // unsigned int __cdecl NiD3DPass::*(unsigned int, BeamStage*)
    // unsigned int __cdecl NiD3DPass::*(BeamStage*)
    // bool __cdecl NiD3DPass::*()
    // unsigned int __cdecl NiD3DPass::*()
    // bool __cdecl NiD3DPass::*(unsigned int, unsigned int)
    // unsigned int __cdecl NiD3DPass::*()
    // unsigned int __cdecl NiD3DPass::*()
    // unsigned int __cdecl NiD3DPass::*()
    // bool __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*()
    // bool __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*(unsigned int)
    // void __cdecl NiD3DPass::*(unsigned int)
    // void __cdecl NiD3DPass::*(unsigned int)
    // void __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*()
    // void __cdecl NiD3DPass::*()
    // NiD3DPass& __cdecl NiD3DPass::*(const NiD3DPass&)
    // void __cdecl NiD3DPass::*()
public:
    bool ApplyRenderStateChanges(bool);
};
#endif
