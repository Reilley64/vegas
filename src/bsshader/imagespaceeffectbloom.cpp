// bsshader/imagespaceeffectbloom.cpp: free functions (1 function)

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_011f6000.h"
#include "imagespaceeffectbloom_decls.h"

// @fnv 0x00c03410
void BloomImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(2);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(3);

    ImageSpaceShaderParam* firstParam = new ImageSpaceShaderParam;
    firstParam->AllocateShaderConstants(0, 1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(0, (::KeyPair **)&(firstParam));
    ::SetEffectParamAt((char *)this, 0, 0, 1, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, manager->GetEffect(39), firstParam, 2);

    ImageSpaceShaderParam* secondParam = new ImageSpaceShaderParam;
    secondParam->AllocateShaderConstants(0, 1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(1, (::KeyPair **)&(secondParam));
    ::SetEffectParamAt((char *)this, 0, 1, 2, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(1, manager->GetEffect(57), secondParam, 0);
    secondParam->SetShaderConstantVector4(0, DAT_012023f4, DAT_012023f8, 0.0f, 0.0f);
}

#include "generated/data/bsshader/imagespaceeffectbloom.inc"
