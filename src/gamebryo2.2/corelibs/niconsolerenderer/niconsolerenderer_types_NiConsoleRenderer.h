// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TASK_TYPES_NICONSOLERENDERER_H
#define FNV_TASK_TYPES_NICONSOLERENDERER_H

#include <cstdint>
#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "_RTL_CRITICAL_SECTION.h"
#include "layout_support.h"
class Direct3DDeviceInterface;
class GeometryRelatedType;
class Direct3DRenderState;
class COMUnknownInterface;
class RenderableGeometry;
class D3DXMATRIX;
class NiAccumulator;
class NiBound;
class RgbaColor;
class NiCriticalSection;
class NiD3DGeometryGroupManager;
class NiD3DShaderInterface;
class ShaderConstantLayout;
class NiDynamicEffectState;
class NiDynamicGeometryGroup;
class GeometryObject;
class NiMaterial;
class NiPixelData;
class NiPixelFormat;
class NiPoint2;
class NiPropertyState;
class NiRenderTargetGroup;
class NiRenderedCubeMap;
class NiRenderedTexture;
class NiRenderer;
class NiShader;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface_____AntiBloatAllocator;
class NiTListItem_NiD3DShaderInterface___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_NiD3DShaderInterface___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface___;
class NiUnsharedGeometryGroup;
class NiVBBlock;
class VertexBufferRelatedType;
class GeometryBufferRelatedType;
class VertexBufferManager;
class IndexBufferManager;
class ShaderPassRenderer;
class RendererCubeMapData;
class RendererBackendInterface;
class GraphicsRenderer;
class NiConsoleRenderer__BatchedObject;
class NiConsoleRenderer__PrePackObject;
class Direct3DRendererState;
class VertexDeclarationLayout;
class _D3DCAPS9;
class _D3DMATRIX;
class _D3DPSHADERCAPS2_0;
class Direct3DResourceRecord;
class _D3DVIEWPORT9;
class _D3DVSHADERCAPS2_0;
enum NiRenderer__EFrameState
{
    NiRenderer__EFrameState_FRAMESTATE_OUTSIDE_FRAME = 0,
    NiRenderer__EFrameState_FRAMESTATE_INSIDE_FRAME = 1,
    NiRenderer__EFrameState_FRAMESTATE_INSIDE_OFFSCREEN_FRAME = 2,
    NiRenderer__EFrameState_FRAMESTATE_WAITING_FOR_DISPLAY = 3
};
enum _D3DDEVTYPE
{
    _D3DDEVTYPE_D3DDEVTYPE_HAL = 1,
    _D3DDEVTYPE_D3DDEVTYPE_COMMAND_BUFFER = 2,
    _D3DDEVTYPE_D3DDEVTYPE_FORCE_DWORD = 2147483647
};
enum NiConsoleRenderer__TexFormat
{
    NiConsoleRenderer__TexFormat_TEX_RGB565 = 0,
    NiConsoleRenderer__TexFormat_TEX_RGB888 = 1,
    NiConsoleRenderer__TexFormat_TEX_RGBA5551 = 2,
    NiConsoleRenderer__TexFormat_TEX_RGBA4444 = 3,
    NiConsoleRenderer__TexFormat_TEX_RGBA8888 = 4,
    NiConsoleRenderer__TexFormat_TEX_PAL8 = 5,
    NiConsoleRenderer__TexFormat_TEX_PALA8 = 6,
    NiConsoleRenderer__TexFormat_TEX_COMPRESS1 = 7,
    NiConsoleRenderer__TexFormat_TEX_COMPRESS3 = 8,
    NiConsoleRenderer__TexFormat_TEX_COMPRESS5 = 9,
    NiConsoleRenderer__TexFormat_TEX_BUMP88 = 10,
    NiConsoleRenderer__TexFormat_TEX_BUMPLUMA556 = 11,
    NiConsoleRenderer__TexFormat_TEX_BUMPLUMA888 = 12,
    NiConsoleRenderer__TexFormat_TEX_L8 = 13,
    NiConsoleRenderer__TexFormat_TEX_A8 = 14,
    NiConsoleRenderer__TexFormat_TEX_RGBA1010102F = 15,
    NiConsoleRenderer__TexFormat_TEX_R16F = 16,
    NiConsoleRenderer__TexFormat_TEX_RG32F = 17,
    NiConsoleRenderer__TexFormat_TEX_RGBA64F = 18,
    NiConsoleRenderer__TexFormat_TEX_R32F = 19,
    NiConsoleRenderer__TexFormat_TEX_RG64F = 20,
    NiConsoleRenderer__TexFormat_TEX_RGBA128F = 21,
    NiConsoleRenderer__TexFormat_TEX_DEFAULT = 22,
    NiConsoleRenderer__TexFormat_TEX_NUM = 22
};
class NiCriticalSection
{
  public:
    _RTL_CRITICAL_SECTION m_kCriticalSection;  // +0x0, 28 bytes
    unsigned long m_ulThreadOwner;             // +0x1C, 4 bytes
    unsigned int m_uiLockCount;                // +0x20, 4 bytes
    unsigned char layoutPadding24[92];
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // void* __cdecl NiCriticalSection::*(unsigned int)
};
class NiRenderer : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    NiPointer<NiAccumulator> m_acRendererDataA;        // +0x8, 4 bytes
    NiPropertyState* m_pCamera;                        // +0xC, 4 bytes
    NiDynamicEffectState* m_pActiveRenderTargetGroup;  // +0x10, 4 bytes
    NiPointer<NiShader> m_acRendererDataB;             // +0x14, 4 bytes
    unsigned char layoutPadding18[104];
    NiCriticalSection m_acRendererDataC;       // +0x80, 128 bytes
    NiCriticalSection m_acRendererDataD;       // +0x100, 128 bytes
    NiCriticalSection m_acRendererDataE;       // +0x180, 128 bytes
    NiRenderer__EFrameState m_iRendererState;  // +0x200, 4 bytes
    unsigned int m_uiRendererFlags;            // +0x204, 4 bytes
    bool m_bRendererFlagA;                     // +0x208, 1 bytes
    bool m_bRendererFlagB;                     // +0x209, 1 bytes
    unsigned char layoutPadding20A[118];
    // const NiRTTI* __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(NiTPrimitiveArray<char *>*)
    // NiPoint3& __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(const NiPoint3&)
    // bool __cdecl NiRenderer::*(unsigned int)
    // NiRenderer
    // void __cdecl NiRenderer::*()
    // unsigned int __cdecl NiRenderer::*()
    // unsigned int __cdecl NiRenderer::*()
    // NiRenderer::EFrameState __cdecl NiRenderer::*()
    // bool __cdecl NiRenderer::*()
    // bool __cdecl NiRenderer::*()
    // bool __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(NiAccumulator*)
    // NiAccumulator* __cdecl NiRenderer::*()
    // bool __cdecl NiRenderer::*()
    // bool __cdecl NiRenderer::*(NiGeometry*, unsigned int, unsigned int, NiD3DShaderDeclaration*)
    // NiShader* __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(NiShader*)
    // const char* __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*()
    // NiPropertyState* __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(NiPropertyState*)
    // NiDynamicEffectState* __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(NiDynamicEffectState*)
    // void __cdecl NiRenderer::*(const char*)
    // void __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(const char*, ...)
    // void __cdecl NiRenderer::*(const char*, ...)
    // void __cdecl NiRenderer::*(const char*, ...)
    // void __cdecl NiRenderer::*()
    // NiRenderer* __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(NiPropertyState*, NiDynamicEffectState*)
    // void __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*(NiTriShape*)
    // void __cdecl NiRenderer::*(NiTriStrips*)
    // void __cdecl NiRenderer::*()
    // void __cdecl NiRenderer::*()
    // bool __cdecl NiRenderer::*(const char*, NiRenderer::EFrameState)
    // bool __cdecl NiRenderer::*(const char*, bool)
    // bool __cdecl NiRenderer::*(const char*, bool)
    // NiRenderer& __cdecl NiRenderer::*(const NiRenderer&)
    // void __cdecl NiRenderer::*()
};
class _D3DVSHADERCAPS2_0
{
  public:
    unsigned long Caps;           // +0x0, 4 bytes
    int DynamicFlowControlDepth;  // +0x4, 4 bytes
    int NumTemps;                 // +0x8, 4 bytes
    int StaticFlowControlDepth;   // +0xC, 4 bytes
};
class _D3DPSHADERCAPS2_0
{
  public:
    unsigned long Caps;           // +0x0, 4 bytes
    int DynamicFlowControlDepth;  // +0x4, 4 bytes
    int NumTemps;                 // +0x8, 4 bytes
    int StaticFlowControlDepth;   // +0xC, 4 bytes
    int NumInstructionSlots;      // +0x10, 4 bytes
};
class _D3DCAPS9
{
  public:
    _D3DDEVTYPE DeviceType;                           // +0x0, 4 bytes
    unsigned int AdapterOrdinal;                      // +0x4, 4 bytes
    unsigned long Caps;                               // +0x8, 4 bytes
    unsigned long Caps2;                              // +0xC, 4 bytes
    unsigned long Caps3;                              // +0x10, 4 bytes
    unsigned long PresentationIntervals;              // +0x14, 4 bytes
    unsigned long CursorCaps;                         // +0x18, 4 bytes
    unsigned long DevCaps;                            // +0x1C, 4 bytes
    unsigned long PrimitiveMiscCaps;                  // +0x20, 4 bytes
    unsigned long RasterCaps;                         // +0x24, 4 bytes
    unsigned long ZCmpCaps;                           // +0x28, 4 bytes
    unsigned long SrcBlendCaps;                       // +0x2C, 4 bytes
    unsigned long DestBlendCaps;                      // +0x30, 4 bytes
    unsigned long AlphaCmpCaps;                       // +0x34, 4 bytes
    unsigned long ShadeCaps;                          // +0x38, 4 bytes
    unsigned long TextureCaps;                        // +0x3C, 4 bytes
    unsigned long TextureFilterCaps;                  // +0x40, 4 bytes
    unsigned long CubeTextureFilterCaps;              // +0x44, 4 bytes
    unsigned long VolumeTextureFilterCaps;            // +0x48, 4 bytes
    unsigned long TextureAddressCaps;                 // +0x4C, 4 bytes
    unsigned long VolumeTextureAddressCaps;           // +0x50, 4 bytes
    unsigned long LineCaps;                           // +0x54, 4 bytes
    unsigned long MaxTextureWidth;                    // +0x58, 4 bytes
    unsigned long MaxTextureHeight;                   // +0x5C, 4 bytes
    unsigned long MaxVolumeExtent;                    // +0x60, 4 bytes
    unsigned long MaxTextureRepeat;                   // +0x64, 4 bytes
    unsigned long MaxTextureAspectRatio;              // +0x68, 4 bytes
    unsigned long MaxAnisotropy;                      // +0x6C, 4 bytes
    float MaxVertexW;                                 // +0x70, 4 bytes
    float GuardBandLeft;                              // +0x74, 4 bytes
    float GuardBandTop;                               // +0x78, 4 bytes
    float GuardBandRight;                             // +0x7C, 4 bytes
    float GuardBandBottom;                            // +0x80, 4 bytes
    float ExtentsAdjust;                              // +0x84, 4 bytes
    unsigned long StencilCaps;                        // +0x88, 4 bytes
    unsigned long FVFCaps;                            // +0x8C, 4 bytes
    unsigned long TextureOpCaps;                      // +0x90, 4 bytes
    unsigned long MaxTextureBlendStages;              // +0x94, 4 bytes
    unsigned long MaxSimultaneousTextures;            // +0x98, 4 bytes
    unsigned long VertexProcessingCaps;               // +0x9C, 4 bytes
    unsigned long MaxActiveLights;                    // +0xA0, 4 bytes
    unsigned long MaxUserClipPlanes;                  // +0xA4, 4 bytes
    unsigned long MaxVertexBlendMatrices;             // +0xA8, 4 bytes
    unsigned long MaxVertexBlendMatrixIndex;          // +0xAC, 4 bytes
    float MaxPointSize;                               // +0xB0, 4 bytes
    unsigned long MaxPrimitiveCount;                  // +0xB4, 4 bytes
    unsigned long MaxVertexIndex;                     // +0xB8, 4 bytes
    unsigned long MaxStreams;                         // +0xBC, 4 bytes
    unsigned long MaxStreamStride;                    // +0xC0, 4 bytes
    unsigned long VertexShaderVersion;                // +0xC4, 4 bytes
    unsigned long MaxVertexShaderConst;               // +0xC8, 4 bytes
    unsigned long PixelShaderVersion;                 // +0xCC, 4 bytes
    float PixelShader1xMaxValue;                      // +0xD0, 4 bytes
    unsigned long DevCaps2;                           // +0xD4, 4 bytes
    float MaxNpatchTessellationLevel;                 // +0xD8, 4 bytes
    unsigned long Reserved5;                          // +0xDC, 4 bytes
    unsigned int MasterAdapterOrdinal;                // +0xE0, 4 bytes
    unsigned int AdapterOrdinalInGroup;               // +0xE4, 4 bytes
    unsigned int NumberOfAdaptersInGroup;             // +0xE8, 4 bytes
    unsigned long DeclTypes;                          // +0xEC, 4 bytes
    unsigned long NumSimultaneousRTs;                 // +0xF0, 4 bytes
    unsigned long StretchRectFilterCaps;              // +0xF4, 4 bytes
    _D3DVSHADERCAPS2_0 VS20Caps;                      // +0xF8, 16 bytes
    _D3DPSHADERCAPS2_0 PS20Caps;                      // +0x108, 20 bytes
    unsigned long VertexTextureFilterCaps;            // +0x11C, 4 bytes
    unsigned long MaxVShaderInstructionsExecuted;     // +0x120, 4 bytes
    unsigned long MaxPShaderInstructionsExecuted;     // +0x124, 4 bytes
    unsigned long MaxVertexShader30InstructionSlots;  // +0x128, 4 bytes
    unsigned long MaxPixelShader30InstructionSlots;   // +0x12C, 4 bytes
};
class Direct3DResourceRecord
{
  public:
    unsigned long Flags;                // +0x0, 4 bytes
    unsigned long m_uiResourceId;       // +0x4, 4 bytes
    void* ResourceEntry;                // +0x8, 4 bytes
    unsigned long m_uiFieldAtOffset0C;  // +0xC, 4 bytes
    void* m_pPointerAtOffset10;         // +0x10, 4 bytes
    unsigned long m_uiFieldAtOffset14;  // +0x14, 4 bytes
};
class NiBound
{
  public:
    NiPoint3 m_kCenter;  // +0x0, 12 bytes
    union
    {                          // overlapping CodeView storage
        float m_fBoundRadius;  // +0xC, 4 bytes
        int m_iRadius;         // +0xC, 4 bytes
    };
    // void __cdecl NiBound::*()
    // const NiPoint3& __cdecl NiBound::*()
    // void __cdecl NiBound::*(float)
    // float __cdecl NiBound::*()
    // void __cdecl NiBound::*(const NiPoint3&, float)
    // bool __cdecl NiBound::*(const NiBound&)
    // bool __cdecl NiBound::*(const NiBound&)
    // void __cdecl NiBound::*(int, const NiPoint3*)
    // Update
    // void __cdecl NiBound::*(NiTPrimitiveArray<NiBound const *>&)
    // void __cdecl NiBound::*(const NiBound*)
    // int __cdecl NiBound::*(const NiPlane&)
    // bool __cdecl NiBound::*(float, const NiBound&, const NiPoint3&, const NiBound&, const NiPoint3&)
    // bool __cdecl NiBound::*(float, const NiBound&, const NiPoint3&, const NiBound&, const NiPoint3&, float&, NiPoint3&, bool, NiPoint3&, NiPoint3&)
    // void __cdecl NiBound::*(NiStream&)
    // void __cdecl NiBound::*(NiStream&)
    // char* __cdecl NiBound::*(const char*)
    // const NiBound& __cdecl NiBound::*(const NiBound&)
};
class _D3DMATRIX
{
  public:
    union
    {  // overlapping CodeView storage
        struct
        {
            float _11;  // +0x0, 4 bytes
            float _12;  // +0x4, 4 bytes
            float _13;  // +0x8, 4 bytes
            float _14;  // +0xC, 4 bytes
            float _21;  // +0x10, 4 bytes
            float _22;  // +0x14, 4 bytes
            float _23;  // +0x18, 4 bytes
            float _24;  // +0x1C, 4 bytes
            float _31;  // +0x20, 4 bytes
            float _32;  // +0x24, 4 bytes
            float _33;  // +0x28, 4 bytes
            float _34;  // +0x2C, 4 bytes
            float _41;  // +0x30, 4 bytes
            float _42;  // +0x34, 4 bytes
            float _43;  // +0x38, 4 bytes
            float _44;  // +0x3C, 4 bytes
        };
        float m[4][4];  // +0x0, 64 bytes
    };
};
class _D3DVIEWPORT9
{
  public:
    unsigned long X;       // +0x0, 4 bytes
    unsigned long Y;       // +0x4, 4 bytes
    unsigned long Width;   // +0x8, 4 bytes
    unsigned long Height;  // +0xC, 4 bytes
    float MinZ;            // +0x10, 4 bytes
    float MaxZ;            // +0x14, 4 bytes
};
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
class NiTListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface___
{
  public:
    NiTListItem_NiD3DShaderInterface___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiD3DShaderInterface___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(NiTListItem<NiD3DShaderInterface *>*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(NiTListItem<NiD3DShaderInterface *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*, NiTListItem<NiD3DShaderInterface *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*, NiTListItem<NiD3DShaderInterface *>*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(unsigned int)
};
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *> at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(NiD3DShaderInterface*&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(NiD3DShaderInterface*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*, NiD3DShaderInterface*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*, NiD3DShaderInterface*&)
    // NiD3DShaderInterface*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // NiD3DShaderInterface*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // NiD3DShaderInterface*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*)
    // NiD3DShaderInterface*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*&)
    // NiD3DShaderInterface*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*&)
    // NiD3DShaderInterface* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // NiD3DShaderInterface* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // NiD3DShaderInterface* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(NiD3DShaderInterface*&)
    // NiD3DShaderInterface* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(NiD3DShaderInterface*&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiD3DShaderInterface *>* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(NiTListItem<NiD3DShaderInterface *>*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *>::*(unsigned int)
};
class NiTPointerList_NiD3DShaderInterface___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiD3DShaderInterface___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiD3DShaderInterface *> at +0x0, size 12
    // NiTPointerList<NiD3DShaderInterface *>
    // void __cdecl NiTPointerList<NiD3DShaderInterface *>::*()
    // NiTPointerList<NiD3DShaderInterface *>& __cdecl NiTPointerList<NiD3DShaderInterface *>::*(const NiTPointerList<NiD3DShaderInterface *>&)
    // void* __cdecl NiTPointerList<NiD3DShaderInterface *>::*(unsigned int)
};
class ShaderConstantLayout
{
  public:
    unsigned int m_uiFirstInteger;            // +0x0, 4 bytes
    unsigned int SecondUnsignedIntegerField;  // +0x4, 4 bytes
    unsigned int SixUnsignedIntegerRecord;    // +0x8, 4 bytes
    unsigned int m_uiFourthDataValue;         // +0xC, 4 bytes
    unsigned int FifthUnsignedIntegerField;   // +0x10, 4 bytes
    unsigned int SevenUnsignedIntegerRecord;  // +0x14, 4 bytes
    unsigned int m_uiFourthInteger;           // +0x18, 4 bytes
    unsigned int FourthUnsignedIntegerField;  // +0x1C, 4 bytes
    unsigned int FiveUnsignedIntegerRecord;   // +0x20, 4 bytes
    unsigned int m_uiBufferSize;              // +0x24, 4 bytes
    // void __cdecl ShaderConstantLayout::*()
    // SetSystemPixelShaderVersion
    // SetMinPixelShaderVersion
    // SetPixelShaderVersionRequest
    // SetSystemVertexShaderVersion
    // SetMinVertexShaderVersion
    // SetVertexShaderVersionRequest
    // SetSystemUserVersion
    // SetMinUserVersion
    // SetUserVersionRequest
    // void __cdecl ShaderConstantLayout::*(unsigned int)
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
    // unsigned int __cdecl ShaderConstantLayout::*()
};
class D3DXMATRIX : public _D3DMATRIX
{
  public:
    // base _D3DMATRIX at +0x0, size 64
    // D3DXMATRIX
    // operator()
    // float* __cdecl D3DXMATRIX::*()
    // const float* __cdecl D3DXMATRIX::*()
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // operator*=
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(float)
    // operator+
    // operator-
    // operator*
    // D3DXMATRIX __cdecl D3DXMATRIX::*(float)
    // int __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // int __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
};
class GraphicsRenderer : public NiRenderer
{
  public:
    // base NiRenderer at +0x0, size 640
    volatile unsigned long RendererStateRecord;  // +0x280, 4 bytes
    unsigned int m_uiSecondUnsignedValue;        // +0x284, 4 bytes
    bool m_bDeviceFlag;                          // +0x288, 1 bytes
    unsigned char layoutPadding289[3];
    Direct3DDeviceInterface* m_pDirect3DDevice;        // +0x28C, 4 bytes
    _D3DCAPS9 m_kDeviceCapabilities;                   // +0x290, 304 bytes
    Direct3DResourceRecord m_kDirect3DResourceRecord;  // +0x3C0, 24 bytes
    unsigned int m_uiDeviceResourceCount;              // +0x3D8, 4 bytes
    bool m_bDeviceCapabilityFlag;                      // +0x3DC, 1 bytes
    unsigned char layoutPadding3DD[3];
    unsigned int m_uiDeviceState;            // +0x3E0, 4 bytes
    float m_fDeviceValue;                    // +0x3E4, 4 bytes
    unsigned int m_uiSecondInteger;          // +0x3E8, 4 bytes
    bool m_bAdditionalDeviceCapabilityFlag;  // +0x3EC, 1 bytes
    bool m_bSecondDeviceCapabilityFlag;      // +0x3ED, 1 bytes
    unsigned char layoutPadding3EE[2];
    unsigned int TwoBooleanThreeIntegerFloatRecord;                                    // +0x3F0, 4 bytes
    unsigned int BooleanFourIntegerFloatRecord;                                        // +0x3F4, 4 bytes
    unsigned int m_uiThirdInteger;                                                     // +0x3F8, 4 bytes
    float m_fPrePackValue;                                                             // +0x3FC, 4 bytes
    unsigned int m_uiIntegerAfterPrePackValue;                                         // +0x400, 4 bytes
    char m_acPrePackObjectName[32];                                                    // +0x404, 32 bytes
    NiTPointerMap<NiVBBlock*, NiConsoleRenderer__PrePackObject*> m_kPrePackObjectMap;  // +0x424, 16 bytes
    NiConsoleRenderer__BatchedObject* BatchedObjectRenderState;                        // +0x434, 4 bytes
    NiConsoleRenderer__BatchedObject* BatchedShaderRenderState;                        // +0x438, 4 bytes
    NiPropertyState* BatchedPropertyRenderState;                                       // +0x43C, 4 bytes
    NiDynamicEffectState* BatchedGeometryRenderState;                                  // +0x440, 4 bytes
    NiPointer<NiD3DShaderInterface> m_spShaderInterface;                               // +0x444, 4 bytes
    NiPoint3 m_kCameraPosition;                                                        // +0x448, 12 bytes
    NiPoint3 m_kCameraDirection;                                                       // +0x454, 12 bytes
    NiPoint3 m_kCameraUp;                                                              // +0x460, 12 bytes
    NiPoint3 m_kCameraRight;                                                           // +0x46C, 12 bytes
    NiBound m_kWorldBound;                                                             // +0x478, 16 bytes
    const NiBound m_kModelBound;                                                       // +0x488, 16 bytes
    float m_fNearPlaneDistance;                                                        // +0x498, 4 bytes
    float m_fFarPlaneDistance;                                                         // +0x49C, 4 bytes
    _D3DMATRIX m_kViewMatrix;                                                          // +0x4A0, 64 bytes
    _D3DVIEWPORT9 m_kViewport;                                                         // +0x4E0, 24 bytes
    unsigned int m_uiViewportState;                                                    // +0x4F8, 4 bytes
    unsigned int m_uiFirstRendererStateValue;                                          // +0x4FC, 4 bytes
    unsigned int m_uiSecondRendererStateValue;                                         // +0x500, 4 bytes
    unsigned int m_uiThirdRendererStateValue;                                          // +0x504, 4 bytes
    bool m_bFlagAt6F4;                                                                 // +0x508, 1 bytes
    bool m_bFlagAt6F5;                                                                 // +0x509, 1 bytes
    unsigned char layoutPadding50A[2];
    unsigned int TexturePixelFormatCache;                        // +0x50C, 4 bytes
    NiPixelFormat* m_ppkPixelFormatTable[5][22];                 // +0x510, 440 bytes
    NiPixelFormat* m_apRenderTargetPixelFormats[5];              // +0x6C8, 20 bytes
    NiPointer<NiPixelData> m_aspRenderTargetPixelData[5];        // +0x6DC, 20 bytes
    NiConsoleRenderer__TexFormat m_eTextureFormat;               // +0x6F0, 4 bytes
    NiPointer<NiRenderTargetGroup> m_pDefaultRenderTargetGroup;  // +0x6F4, 4 bytes
    NiRenderTargetGroup* m_pCurrentRenderTargetGroup;            // +0x6F8, 4 bytes
    unsigned int RenderTargetState;                              // +0x6FC, 4 bytes
    bool m_bFlagAt8A4;                                           // +0x700, 1 bytes
    bool m_bFlagAt8A5;                                           // +0x701, 1 bytes
    unsigned char layoutPadding702[2];
    float m_fGeometryParameter;                                                          // +0x704, 4 bytes
    NiPropertyState* m_pPropertyState;                                                   // +0x708, 4 bytes
    NiD3DGeometryGroupManager* m_pGeometryGroupManager;                                  // +0x70C, 4 bytes
    NiUnsharedGeometryGroup* m_pUnsharedGeometryGroup;                                   // +0x710, 4 bytes
    NiDynamicGeometryGroup* m_pDynamicGeometryGroup;                                     // +0x714, 4 bytes
    ShaderPassRenderer* m_pCurrentRenderState;                                           // +0x718, 4 bytes
    VertexDeclarationLayout* m_pShaderStreamInfo;                                        // +0x71C, 4 bytes
    IndexBufferManager* m_pRenderTargetGroup;                                            // +0x720, 4 bytes
    Direct3DRendererState* m_pFourthRendererObject;                                      // +0x724, 4 bytes
    NiTPointerMap<NiRenderedTexture*, RendererBackendInterface*> m_kRenderedTextureMap;  // +0x728, 16 bytes
    NiTPointerMap<NiRenderedCubeMap*, RendererCubeMapData*> m_kRenderedCubeMapMap;       // +0x738, 16 bytes
    NiTPointerMap<GeometryObject*, VertexBufferManager*> m_kGeometryObjectMap;           // +0x748, 16 bytes
    NiTPointerList_NiD3DShaderInterface___ m_kShaderList;                                // +0x758, 12 bytes
    ShaderConstantLayout m_kShaderData;                                                  // +0x764, 40 bytes
    NiPointer<GeometryBufferRelatedType> m_spGeometryBuffer;                             // +0x78C, 4 bytes
    D3DXMATRIX m_kFirstShadowMatrix;                                                     // +0x790, 64 bytes
    D3DXMATRIX m_kSecondShadowMatrix;                                                    // +0x7D0, 64 bytes
    D3DXMATRIX m_kThirdShadowMatrix;                                                     // +0x810, 64 bytes
    D3DXMATRIX m_kShadowMatrixAfterThird;                                                // +0x850, 64 bytes
    D3DXMATRIX ShadowGeometryData;                                                       // +0x890, 64 bytes
    NiPoint2* m_pSourcePoint2Array;                                                      // +0x8D0, 4 bytes
    RgbaColor* m_pIntermediateGeometryObject;                                            // +0x8D4, 4 bytes
    NiPoint2* m_pSecondPoint2Array;                                                      // +0x8D8, 4 bytes
    unsigned short* m_pIndexArray;                                                       // +0x8DC, 4 bytes
    unsigned short m_usIndexCount;                                                       // +0x8E0, 2 bytes
    unsigned char layoutPadding8E2[2];
    unsigned int MaterialVertexBufferRecord;                     // +0x8E4, 4 bytes
    NiPointer<NiMaterial> m_spRenderMaterial;                    // +0x8E8, 4 bytes
    VertexBufferRelatedType* m_pVertexBufferData;                // +0x8EC, 4 bytes
    Direct3DRenderState* MaterialVertexBufferData;               // +0x8F0, 4 bytes
    COMUnknownInterface* m_pFirstCOMInterface;                   // +0x8F4, 4 bytes
    COMUnknownInterface* VertexBufferAndInterfacePointerBundle;  // +0x8F8, 4 bytes
    COMUnknownInterface* MixedInterfacePointerBundleA;           // +0x8FC, 4 bytes
    COMUnknownInterface* SevenUnknownInterfacePointerGroupC;     // +0x900, 4 bytes
    COMUnknownInterface* SevenUnknownInterfacePointerGroupA;     // +0x904, 4 bytes
    COMUnknownInterface* SevenUnknownInterfacePointerGroupE;     // +0x908, 4 bytes
    COMUnknownInterface* SevenUnknownInterfacePointerGroupB;     // +0x90C, 4 bytes
    COMUnknownInterface* SevenUnknownInterfacePointerGroupD;     // +0x910, 4 bytes
    COMUnknownInterface* MixedInterfacePointerBundleB;           // +0x914, 4 bytes
    COMUnknownInterface* m_pCOMUnknownInterface;                 // +0x918, 4 bytes
    COMUnknownInterface* m_pAdditionalCOMInterface;              // +0x91C, 4 bytes
    RenderableGeometry* m_pFourthRendererInterface;              // +0x920, 4 bytes
    GeometryRelatedType* GeometryRendererInterface;              // +0x924, 4 bytes
    unsigned char layoutPadding928[88];
    // const NiRTTI* __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(const NiRect<float>*, unsigned int)
    // void __cdecl GraphicsRenderer::*(const NiRect<float>*)
    // bool __cdecl GraphicsRenderer::*(NiRenderTargetGroup*, unsigned int)
    // bool __cdecl GraphicsRenderer::*(unsigned int)
    // bool __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(NiTriShape*)
    // void __cdecl GraphicsRenderer::*(NiTriStrips*)
    // void __cdecl GraphicsRenderer::*(NiTriShape*)
    // void __cdecl GraphicsRenderer::*(NiTriStrips*)
    // void __cdecl GraphicsRenderer::*(NiParticles*)
    // void __cdecl GraphicsRenderer::*(NiParticles*)
    // void __cdecl GraphicsRenderer::*(NiLines*)
    // void __cdecl GraphicsRenderer::*(NiScreenTexture*)
    // SetDefaultProgramCache
    // void __cdecl GraphicsRenderer::*(NiDynamicEffect*)
    // void __cdecl GraphicsRenderer::*(NiGeometryData*)
    // void __cdecl GraphicsRenderer::*(NiMaterialProperty*)
    // void __cdecl GraphicsRenderer::*(NiScreenTexture*)
    // void __cdecl GraphicsRenderer::*(NiSkinPartition*)
    // void __cdecl GraphicsRenderer::*(NiSkinInstance*)
    // void __cdecl GraphicsRenderer::*(NiAVObject*)
    // bool __cdecl GraphicsRenderer::*(unsigned int, unsigned int, float&, float&, const NiRenderTargetGroup*)
    // FindClosestDepthStencilFormat
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(int, int, float*)
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(unsigned int)
    // void __cdecl GraphicsRenderer::*(unsigned long)
    // void __cdecl GraphicsRenderer::*()
    // GraphicsRenderer* __cdecl GraphicsRenderer::*(unsigned int, unsigned int, unsigned int, _D3DFORMAT, _D3DFORMAT, _D3DFORMAT, GraphicsRenderer::PresentationInterval, unsigned int)
    // Recreate
    // unsigned int __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(bool)
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(_D3DFORMAT)
    // void __cdecl GraphicsRenderer::*(_D3DFORMAT)
    // void __cdecl GraphicsRenderer::*(NiD3DVertexShader*)
    // void __cdecl GraphicsRenderer::*(NiD3DPixelShader*)
    // void __cdecl GraphicsRenderer::*(NiD3DShaderInterface*)
    // void __cdecl GraphicsRenderer::*(NiD3DShaderInterface*)
    // void __cdecl GraphicsRenderer::*(NiD3DShaderInterface*)
    // void __cdecl GraphicsRenderer::*()
    // Direct3DDeviceInterface* __cdecl GraphicsRenderer::*()
    // _D3DPRESENT_PARAMETERS_* __cdecl GraphicsRenderer::*()
    // const _D3DCAPS9* __cdecl GraphicsRenderer::*()
    // Direct3D* __cdecl GraphicsRenderer::*()
    // const Direct3DResourceRecord& __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(Direct3DResourceRecord&)
    // ShaderPassRenderer* __cdecl GraphicsRenderer::*()
    // VertexDeclarationLayout* __cdecl GraphicsRenderer::*()
    // Direct3DRendererState* __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(_D3DFORMAT)
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(NiObjectNET*)
    // void __cdecl GraphicsRenderer::*()
    // const char* __cdecl GraphicsRenderer::*(_D3DFORMAT)
    // _D3DMULTISAMPLE_TYPE __cdecl GraphicsRenderer::*(unsigned int)
    // unsigned int __cdecl GraphicsRenderer::*(GraphicsRenderer::PresentationInterval)
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(const char*)
    // void __cdecl GraphicsRenderer::*(const char*)
    // SetBackgroundColor
    // void __cdecl GraphicsRenderer::*(Ni2DBuffer*)
    // bool __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(float)
    // float __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // GraphicsRenderer* __cdecl GraphicsRenderer::*()
    // float __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(const NiTransform&, bool)
    // void __cdecl GraphicsRenderer::*(const NiSkinInstance*, const NiSkinPartition::Partition*, const NiTransform&)
    // void __cdecl GraphicsRenderer::*(const NiSkinInstance*, const NiTransform&, bool, unsigned int, bool)
    // void __cdecl GraphicsRenderer::*(NiGeometry*, NiGeometryData*, NiSkinInstance*, const NiTransform&, const NiBound&, NiGeometryBufferData*)
    // void __cdecl GraphicsRenderer::*(NiGeometry*, NiGeometryData*, const NiSkinInstance*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl GraphicsRenderer::*(bool, bool, bool, unsigned int)
    // bool __cdecl GraphicsRenderer::*(unsigned int)
    // bool __cdecl GraphicsRenderer::*(unsigned int)
    // bool __cdecl GraphicsRenderer::*(unsigned int)
    // unsigned int __cdecl GraphicsRenderer::*(unsigned int)
    // void __cdecl GraphicsRenderer::*(NiGeometryData*, NiSkinInstance*, NiSkinPartition::Partition*)
    // void __cdecl GraphicsRenderer::*(NiRenderedCubeMap*)
    // void __cdecl GraphicsRenderer::*(NiRenderedCubeMap*)
    // void __cdecl GraphicsRenderer::*(NiRenderedTexture*)
    // void __cdecl GraphicsRenderer::*(NiRenderedTexture*)
    // NiPixelFormat** __cdecl GraphicsRenderer::*(GraphicsRenderer::TexUsage)
    // const NiPixelFormat* __cdecl GraphicsRenderer::*(GraphicsRenderer::TexUsage)
    // const NiPixelData* __cdecl GraphicsRenderer::*(GraphicsRenderer::TexUsage)
    // GraphicsRenderer::TexFormat __cdecl GraphicsRenderer::*()
    // NiTexture* __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(Direct3DDeviceInterface*)
    // void __cdecl GraphicsRenderer::*(COMUnknownInterface*)
    // void __cdecl GraphicsRenderer::*(NiTexture*)
    // const _D3DMATRIX& __cdecl GraphicsRenderer::*()
    // const _D3DMATRIX& __cdecl GraphicsRenderer::*()
    // const _D3DMATRIX& __cdecl GraphicsRenderer::*()
    // const _D3DMATRIX& __cdecl GraphicsRenderer::*()
    // const D3DXMATRIX* __cdecl GraphicsRenderer::*()
    // const D3DXMATRIX* __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(unsigned int, unsigned int)
    // void __cdecl GraphicsRenderer::*(unsigned int, unsigned int)
    // void __cdecl GraphicsRenderer::*(unsigned int, unsigned int)
    // void __cdecl GraphicsRenderer::*(unsigned int, unsigned int)
    // void __cdecl GraphicsRenderer::*(unsigned int, unsigned int)
    // void __cdecl GraphicsRenderer::*(unsigned int, unsigned int)
    // void __cdecl GraphicsRenderer::*(unsigned int, unsigned int)
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // unsigned int __cdecl GraphicsRenderer::*()
    // const ShaderConstantLayout* __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(NiGeometryBufferData*, NiGeometryData*, NiSkinInstance*, NiD3DShaderDeclaration*, bool)
    // bool __cdecl GraphicsRenderer::*(NiGeometryBufferData*, NiGeometryData*, const NiSkinInstance*, NiSkinPartition::Partition*, NiD3DShaderDeclaration*, bool)
    // COMUnknownInterface* __cdecl GraphicsRenderer::*(_D3DVERTEXELEMENT9*)
    // unsigned int __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(Ni2DBuffer*)
    // NiVBChip* __cdecl GraphicsRenderer::*(BSPackedAdditionalGeometryData*, const NiSkinInstance*, NiSkinPartition::Partition*)
    // COMUnknownInterface* __cdecl GraphicsRenderer::*(unsigned int)
    // NiD3DShaderDeclaration* __cdecl GraphicsRenderer::*(unsigned int)
    // PackStripParticleVertex
    // GraphicsRenderer
    // void __cdecl GraphicsRenderer::*()
    // int __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(unsigned int, unsigned int, unsigned int, unsigned int, _D3DFORMAT, _D3DFORMAT, _D3DFORMAT, GraphicsRenderer::PresentationInterval, _D3DPRESENT_PARAMETERS_&)
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(const _D3DPRESENT_PARAMETERS_&)
    // void __cdecl GraphicsRenderer::*(unsigned short*, unsigned int, unsigned short*)
    // void __cdecl GraphicsRenderer::*(NiScreenTexture*)
    // void __cdecl GraphicsRenderer::*(NiScreenTexture*, unsigned short)
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(NiGeometry*, NiGeometryData*, unsigned short, unsigned short, const unsigned short*, const unsigned short*, unsigned short, NiD3DShaderDeclaration*)
    // bool __cdecl GraphicsRenderer::*(NiGeometry*, NiGeometryData*, NiSkinInstance*, NiD3DShaderDeclaration*, unsigned int, unsigned int)
    // bool __cdecl GraphicsRenderer::*(NiGeometryBufferData*, NiGeometryData*, NiSkinPartition::Partition*, NiD3DShaderDeclaration*)
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*()
    // void __cdecl GraphicsRenderer::*(NiGeometry*)
    // bool __cdecl GraphicsRenderer::*()
    // bool __cdecl GraphicsRenderer::*(NiGeometry*, const NiD3DShaderInterface*)
    // void __cdecl GraphicsRenderer::*(NiPixelFormat**, unsigned int, _D3DRESOURCETYPE)
    // void __cdecl GraphicsRenderer::*()
    // RenderableGeometry* __cdecl GraphicsRenderer::*()
    // GeometryRelatedType* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // COMUnknownInterface* __cdecl GraphicsRenderer::*(unsigned int)
    // COMUnknownInterface* __cdecl GraphicsRenderer::*()
    // GraphicsRenderer& __cdecl GraphicsRenderer::*(const GraphicsRenderer&)
    // void __cdecl GraphicsRenderer::*()
    bool BeginUsingRenderTargetGroup(NiRenderTargetGroup*, unsigned int);
    bool MapScreenCoordinates(unsigned int, unsigned int, float&, float&, NiRenderTargetGroup*);
    uintptr_t GetRenderTargetWidth();
    uintptr_t GetRenderTargetHeight();
};
#endif
