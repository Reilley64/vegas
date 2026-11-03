
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "imagespaceeffecthdr_decls.h"

// @fnv 0x00BAD580
void HDRImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(13);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pTextures))->FUN_00a90180(3);
    m_bUseLowResolutionPath = DAT_011f941f && DAT_011f9420 && NiRenderer::ms_pRenderer->vfn_c8()->Unk_23(0) <= 1280;

    ImageSpaceShaderParam* shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 0);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->FUN_00b8a7c0();
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(7, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(7, manager->GetEffect(34), shaderParam, 0);

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->FUN_00b8a7c0();
    if (DAT_011f941f)
    {
        shaderParam->CopyParamData(3, DAT_011add48, 64);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(5, manager->GetEffect(65), shaderParam, 0);
    }
    else
    {
        shaderParam->CopyParamData(3, DAT_011add88, 256);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(5, manager->GetEffect(63), shaderParam, 0);
    }
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(5, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->FUN_00b8a7c0();
    if (DAT_011f941f)
    {
        shaderParam->CopyParamData(3, DAT_011add48, 64);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(12, manager->GetEffect(66), shaderParam, 0);
    }
    else
    {
        shaderParam->CopyParamData(3, DAT_011add88, 256);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(12, manager->GetEffect(68), shaderParam, 0);
    }
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(12, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[2] = false;
    shaderParam->FUN_00b8a7c0();
    if (DAT_011f941f)
    {
        shaderParam->CopyParamData(3, DAT_011add48, 64);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(11, manager->GetEffect(67), shaderParam, 0);
    }
    else
    {
        shaderParam->CopyParamData(3, DAT_011add88, 256);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(11, manager->GetEffect(69), shaderParam, 0);
    }
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(11, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->FUN_00b8a7c0();
    shaderParam->CopyParamData(3, DAT_011ade88, 144);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(6, manager->GetEffect(64), shaderParam, 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(6, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->FUN_00b8a7c0();
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(10, manager->GetEffect(71), shaderParam, 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(10, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->m_bTextureFlags[1] = false;
    shaderParam->m_bTextureFlags[2] = false;
    shaderParam->FUN_00b8a7c0();
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(9, manager->GetEffect(70), shaderParam, 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(9, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    shaderParam->FUN_00b8a7c0();
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(8, manager->GetEffect(62), shaderParam, 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(8, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(2, manager->GetEffect(58), shaderParam, 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(2, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(3, manager->GetEffect(59), shaderParam, 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(3, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));

    shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 24);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(4, manager->GetEffect(60), shaderParam, 0);
    reinterpret_cast<::FUN_00a41520_cls *>(&(pEffectParamList))->FUN_00ba3aa0(4, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)((ImageSpaceEffectParam*)shaderParam));
}
