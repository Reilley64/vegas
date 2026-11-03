// bsshader/imagespaceeffectblur.cpp: free functions (1 function)

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_011f6000.h"
#include "imagespaceeffectblur_decls.h"

// Initializes the blur effect's shader params, texture slots and effect param list entries from the manager's effects 45, 19 and 46.
// @fnv 0x00c054c0
void ImageSpaceEffectFourTexturePass::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(3);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(4);

    {
        ImageSpaceShaderParam* first = new ImageSpaceShaderParam;
        first->AllocateShaderConstants(0, 1);
        first->SetShaderConstantVector4(0, 0.0f, DAT_011ae6c8, DAT_011ae6cc, 0.0f);
        reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(0, (::KeyPair **)&(first));
        ::SetEffectParamAt((char *)this, 0, 1, 1, {});

        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, manager->GetEffect(45), first, 2);
        first = 0;
        reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(1, (::KeyPair **)&(first));
        reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(1, 2, 3, (*(int *)&(const ::NiTexturingProperty::FilterMode &)(NiTexturingProperty::FILTER_NEAREST)), (*(int *)&(const ::NiTexturingProperty::FilterMode &)(NiTexturingProperty::FILTER_NEAREST)));

        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(1, manager->GetEffect(19), first, 2);
    }
    ImageSpaceShaderParam* second = new ImageSpaceShaderParam;
    second->AllocateShaderConstants(0, 1);
    second->unk56 = 0;
    second->SetShaderConstantVector4(0, 1.0f, 1.0f, 1.0f, 1.0f);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(2, (::KeyPair **)&(second));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(2, 2, 1, (*(int *)&(const ::NiTexturingProperty::FilterMode &)(NiTexturingProperty::FILTER_BILERP)), (*(int *)&(const ::NiTexturingProperty::FilterMode &)(NiTexturingProperty::FILTER_NEAREST)));

    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(2, manager->GetEffect(46), second, 0);
}
