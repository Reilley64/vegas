// bsshader/imagespaceeffectvatsscan.cpp: free functions (3 functions)

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BA3760Object.h"
#include "fnv/decl/BBA3C00Shader.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/FUN_00bc0360.h"
#include "fnv/decl/Holder00ba37f0.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01201000.h"
#include "imagespaceeffectvatsscan_decls.h"
#include <new>

// @fnv 0x00bc06c0
void ImageSpaceEffectMultiTexture::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* params)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(5);
    BSShaderManager::GetTexture("Data\\Textures\\Pipboy3000\\PipboyScanlines.dds", true, DAT_01201f40, false, false);
    NiTexture* pScanTexture = DAT_01201f40.m_pObject;
    BSShaderManager::GetTexture("Data\\Textures\\Pipboy3000\\PipboyDistortEffectMap.dds", true, DAT_01201f48, false,
                                false);
    NiTexture* pDistortTexture = DAT_01201f48.m_pObject;
    ImageSpaceTexture* pTexture = new ImageSpaceTexture;
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00ba3aa0(3, (::KeyPair **)&(pTexture));
    reinterpret_cast<::Holder00ba37f0 *>((pTextures.m_pBase[3]))->FUN_00ba37f0((::Tex00ba37f0 *)(pScanTexture));
    reinterpret_cast<::BA3760Object *>((((NonActorMagicCaster*)pTextures.m_pBase[3])))->FUN_00ba3760((int)((MagicItem*)3));
    pTexture = new ImageSpaceTexture;
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00ba3aa0(4, (::KeyPair **)&(pTexture));
    reinterpret_cast<::Holder00ba37f0 *>((pTextures.m_pBase[4]))->FUN_00ba37f0((::Tex00ba37f0 *)(pDistortTexture));
    pDistortTexture = (NiTexture*)new ImageSpaceTexture;
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00ba3aa0(2, (::KeyPair **)&((ImageSpaceTexture*&)pDistortTexture));
    reinterpret_cast<::Holder00ba37f0 *>((pTextures.m_pBase[2]))->FUN_00ba37f0((::Tex00ba37f0 *)(::NiTexture *)(0));
    char* effect = *(char**)(*(char**)((char*)manager + 8) + 0x12c);
    char* pAdjustedEffect = effect ? effect - 0x6c : 0;
    ImageSpaceShaderParam* pShaderParam = new ImageSpaceShaderParam;
    pShaderParam->AllocateShaderConstants(0, 3);
    pShaderParam->m_eClearFlags = (NiRenderer__ClearFlags)1;
    pShaderParam->SetShaderConstantVector4(1, DAT_011ae614, DAT_01201f2c, DAT_011ae618, 0.0f);
    pShaderParam->SetShaderConstantVector4(2, DAT_01201f30, DAT_01201f34, DAT_01201f38, DAT_01201f3c);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(0, (::KeyPair **)&(pShaderParam));
    reinterpret_cast<::BBA3C00Shader *>(this)->SetEntryRanges(0, 1, 2, 3, 4, 0, 0, 0, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, (ImageSpaceEffect*)(pAdjustedEffect ? pAdjustedEffect + 0x6c : 0), pShaderParam, 0);
}

struct Unknown
{
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00bc06a0
void* Unknown::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00bc0360 *>(this)->FUN_00bc0360::~FUN_00bc0360();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

class FUN_00bc0600 : public ImageSpaceEffect
{
  public:
    FUN_00bc0600();
};

// @fnv 0x00bc0600
FUN_00bc0600::FUN_00bc0600()
{
    RgbaColor kWhiteColor;
    m_ppVirtualMethodTable = (void**)&DAT_010ba350;
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(5);
    kWhiteColor.r = 1.0f;
    bIsActive = false;
    kWhiteColor.g = kWhiteColor.r;
    kWhiteColor.b = kWhiteColor.g;
    kWhiteColor.a = kWhiteColor.b;
    *(RgbaColor*)&DAT_01201f30 = kWhiteColor;
}
