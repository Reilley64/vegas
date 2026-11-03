#include <cstddef>
// bsshader/imagespaceeffectgethit.cpp: Standin (4 functions)

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00b8a9e0.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/FUN_00c03580.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01202000.h"
#include "imagespaceeffectgethit_types_ImageSpaceEffectGetHit.h"
#include "imagespaceeffectgethit_types_ImageSpaceShaderParam.h"
#include "MemoryManager.h"
#include "imagespaceeffectgethit_decls.h"

// Updates two shader parameters from global constants using a computed angle, sets DAT_012003c4, and returns true.
// @fnv 0x00c03740
bool ImageSpaceEffectWithTwoTextures::UpdateParams(ImageSpaceEffectParam* param)
{
    ImageSpaceShaderParam* shader = reinterpret_cast<ImageSpaceShaderParam*>(pEffectParamList.m_pBase[3]);
    float angle = static_cast<float>(::DAT_011f940c / ::DAT_01012640 * ::_DAT_0104eea0);
    shader->SetShaderConstantVector4(0, 0.0f, 0.0f, ::DAT_0120240c * DAT_012023fc, ::DAT_0120240c);
    float cosine = static_cast<float>(cos(angle));
    float sine = static_cast<float>(sin(angle));
    shader->SetShaderConstantVector4(1, sine * ::DAT_01202400, cosine * ::DAT_01202400, 1.0f, 1.0f);
    DAT_012003c4 = ::DAT_010162c0;
    return true;
}

// @fnv 0x00c03810
ImageSpaceEffectWithTwoTextures::ImageSpaceEffectWithTwoTextures()
{
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(4);
}

struct Standin
{
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00c03580, then if bit 0 of flags is set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00c03890
void* Standin::ReleaseIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00c03580 *>(this)->FUN_00c03580::~FUN_00c03580();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct ImageSpaceManagerX
{
    int unk00;
    NiTPrimitiveArray_ImageSpaceEffect___ kEffects;
    ImageSpaceEffect* GetEffect(unsigned int index)
    {
        return kEffects.m_pBase[index];
    }
};
struct ImageSpaceTextureArrayX
{
};
struct ImageSpaceParamArrayX
{
};
struct ImageSpaceShaderParamX : ImageSpaceShaderParam
{
    ImageSpaceShaderParamX();
};
struct ImageSpaceEffectX : ImageSpaceEffect
{
    void SetupEffect(ImageSpaceManagerX* manager, ImageSpaceEffectParam* param);
    ImageSpaceParamArrayX& Params()
    {
        return *(ImageSpaceParamArrayX*)&pEffectParamList;
    }
};
// Sets texture and parameter arrays, configures four effect slots, and creates shader constants for the fourth slot.
// @fnv 0x00c038b0
void ImageSpaceEffectX::SetupEffect(ImageSpaceManagerX* manager, ImageSpaceEffectParam* param)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(4);
    reinterpret_cast<::FUN_00a41520_cls *>((((ImageSpaceTextureArrayX*)&pTextures)))->FUN_00a90180(4);
    reinterpret_cast<::FUN_00a41520_cls *>(&(Params()))->FUN_00ba3aa0(0, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)(0));
    ::SetEffectParamAt((char *)this, 0, 0, 1, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, manager->GetEffect(34), 0, 2);
    reinterpret_cast<::FUN_00a41520_cls *>(&(Params()))->FUN_00ba3aa0(1, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(1, 2, 3, 0, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(1, manager->GetEffect(17), 0, 2);
    reinterpret_cast<::FUN_00a41520_cls *>(&(Params()))->FUN_00ba3aa0(2, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(2, 2, 3, 0, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(2, manager->GetEffect(17), 0, 2);
    ImageSpaceShaderParamX* shaderParam = new ImageSpaceShaderParamX;
    shaderParam->AllocateShaderConstants(0, 2);
    shaderParam->m_bTextureFlags[2] = false;
    reinterpret_cast<::FUN_00a41520_cls *>(&(Params()))->FUN_00ba3aa0(3, (::KeyPair **)&(shaderParam));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(3, 1, 2, 0, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(3, manager->GetEffect(44), shaderParam, 0);
}

#include "generated/data/bsshader/imagespaceeffectgethit.inc"
