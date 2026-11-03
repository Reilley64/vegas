// bsshader/imagespaceeffectrefraction.cpp: free functions (4 functions)

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00ba3770_struct.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/FUN_00bd9160.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/OwnerStandIn.h"
#include "fnv/decl/Pool.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "imagespaceeffectrefraction_decls.h"

// @fnv 0x00bd9420
void RefractionImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam*)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(3);
    ImageSpaceShaderParam* shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 1);
    WaterTintRecord waterTint = (*reinterpret_cast<WaterTintRecord (*)[]>((void *)&::DAT_011FA0C0))[0];
    shaderParam->SetShaderConstantVector4(0, waterTint.r, waterTint.g, waterTint.b, waterTint.a);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(0, (::KeyPair **)&(shaderParam));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(0, 1, 2, 0, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, manager->pEffectList.m_pBase[41], shaderParam, 0);
}

// @fnv 0x00bd9380
BSRenderedTexture* RefractionImageSpaceEffect::GetRefractionTexture(bool create)
{
    if (!((::NiTexture *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(m_kRefractionTexture))->FUN_00ba3780())) && create)
    {
        DAT_011bf400 = 0;
        reinterpret_cast<::OwnerStandIn *>(&(m_kRefractionTexture))->FUN_00ba37a0(
            (::RefBase *)(::BSRenderedTexture *)(((::BSRenderedTexture *)(reinterpret_cast<::Pool *>((DAT_011f91a8))->FUN_00b6e110((unsigned int)(NiRenderer::ms_pRenderer), 31, 0, (unsigned int)(0), 0)))));
        DAT_011bf400 = 1;
    }
    return ((::BSRenderedTexture *)(reinterpret_cast<::FUN_00ba3770_struct *>(&(m_kRefractionTexture))->FUN_00ba3770()));
}

// @fnv 0x00bd93d0
RefractionImageSpaceEffect::RefractionImageSpaceEffect()
{
    volatile ImageSpaceTexture& texture = m_kRefractionTexture;
    *(void** volatile*)&m_ppVirtualMethodTable = DAT_010bc560;
    texture.m_bTextureFlag1 = false;
    texture.m_bTextureFlag2 = false;
    texture.m_bTextureFlag3 = false;
    texture.pTexture = 0;
    texture.m_eTextureFilterMode = 0;
    texture.m_eClampMode = 0;
}

struct X
{
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00bd9160, then deallocates this via g_memoryManager if flag has bit 1 set, and returns this.
// @fnv 0x00bd9400
void* X::ReleaseIfFlagged(unsigned int flag)
{
    reinterpret_cast<::FUN_00bd9160 *>(this)->FUN_00bd9160::~FUN_00bd9160();
    if (flag & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

#include "generated/data/bsshader/imagespaceeffectrefraction.inc"
