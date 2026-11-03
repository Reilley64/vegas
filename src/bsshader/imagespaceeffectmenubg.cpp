// bsshader/imagespaceeffectmenubg.cpp: free functions (1 function)

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/Holder00ba37f0.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "imagespaceeffectmenubg_decls.h"

// @fnv 0x00c04730
void ImageSpaceEffectMenuBackground::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* parameters)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(3);
    m_pBackgroundTexture = new ImageSpaceTexture;
    if (!DAT_011f941e)
    {
        NiPointer<NiTexture> texture;
        BSShaderManager::GetTexture("Data\\Textures\\Interface\\Misc\\sepia.dds", true, texture, false, false);
        reinterpret_cast<::Holder00ba37f0 *>((m_pBackgroundTexture))->FUN_00ba37f0((::Tex00ba37f0 *)(texture.m_pObject));
    }
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00ba3aa0(2, (::KeyPair **)&(m_pBackgroundTexture));
    ImageSpaceShaderParam* shaderParameters = new ImageSpaceShaderParam;
    shaderParameters->AllocateShaderConstants(0, 1);
    shaderParameters->SetShaderConstantVector4(0, 0.0f, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(0, (::KeyPair **)&(shaderParameters));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(0, 1, 2, (*(int *)&(const ::NiTexturingProperty::FilterMode &)(NiTexturingProperty::FILTER_BILERP)), (*(int *)&(const ::NiTexturingProperty::FilterMode &)(NiTexturingProperty::FILTER_NEAREST)));
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, manager->pEffectList.m_pBase[ImageSpaceManager::EFFECT_SHADER_MENUBG], shaderParameters, 0);
}

#include "generated/data/bsshader/imagespaceeffectmenubg.inc"
