// bsshader/imagespaceeffectrefraction_decls.h: declares RgbaColor, WaterTintRecord, ImageSpaceShaderParam, ImageSpaceTexture, ImageSpaceManager and more
#ifndef IMAGESPACEEFFECTREFRACTION_DECLS_H
#define IMAGESPACEEFFECTREFRACTION_DECLS_H

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00ba3770_struct.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/OwnerStandIn.h"
#include "fnv/decl/Pool.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "layout_support.h"
#include "MemoryManager.h"

class ImageSpaceEffect;
class ImageSpaceEffectParam;
class ImageSpaceManager;
class ImageSpaceTexture;
class NiTexture;
class BSRenderedTexture;
class NiRenderer;

template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, const T& value);
};

class RgbaColor
{
  public:
    float r, g, b, a;
};
struct WaterTintRecord
{
    float r, g, b, a;
};

class ImageSpaceEffectParam
{
  public:
    void** m_ppVirtualMethodTable;
    NiTPrimitiveArray<int> m_kTextureTypes;
    NiTPrimitiveArray<int> m_kFilterModes;
};

class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    int m_eShaderFilterMode;
    unsigned int m_eClearFlags;
    RgbaColor m_eTextureClampMode;
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    void* m_pVertexShaderConstantMap;
    void* m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    NiTObjectArray<void*> m_kShaderTextures;
    NiTPrimitiveArray<int> m_kTextureFilterModes;
    void* m_kRenderStateMap[4];

    ImageSpaceShaderParam();
    void AllocateShaderConstants(int vertexCount, int pixelCount);
    void SetShaderConstantVector4(int index, float x, float y, float z, float w);
};

class ImageSpaceEffect
{
  public:
    void** m_ppVirtualMethodTable;
    bool bIsActive;
    bool bParamsChanged;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    NiTPrimitiveArray<ImageSpaceEffectParam*> pEffectParamList;
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;
    NiTPrimitiveArray<void*> pEffectInputs;
    NiTPrimitiveArray<int> pEffectOutput;

    ImageSpaceEffect();
public:
    void SetTextureArraySize(int);
};

class ImageSpaceTexture
{
  public:
    bool m_bTextureFlag1;
    bool m_bTextureFlag2;
    bool m_bTextureFlag3;
    void* pTexture;
    int m_eTextureFilterMode;
    int m_eClampMode;
};

class RefractionImageSpaceEffect : public ImageSpaceEffect
{
  public:
    RefractionImageSpaceEffect();
    ImageSpaceTexture m_kRefractionTexture;
    void Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param);
    BSRenderedTexture* GetRefractionTexture(bool create);
};

class ImageSpaceManager
{
  public:
    BSRenderedTexture* m_pCurrentRenderedTexture;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
};

class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};

class BSTextureManager
{
  public:
};
extern int DAT_011bf400;
extern void* DAT_010bc560[];

#endif
