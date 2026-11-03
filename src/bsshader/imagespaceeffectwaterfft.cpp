
// src/bsshader/imagespaceeffectwaterfft.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectwaterfft.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/BBA3C00Shader.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/H_00ba39a0.h"
#include "fnv/decl/ImageSpaceEffect.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/fnv_00ba3ba0__Holder.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01202000.h"
struct ImageSpaceTexture
{
};

struct ImageSpaceTextureSet
{
    char _0[0x58];
    ImageSpaceTexture m_kTextureSlot0;
    char _1[0x0f];
    ImageSpaceTexture m_kTextureSlot1;
    char _2[0x0f];
    ImageSpaceTexture m_kTextureSlot2;
    char _3[0x0f];
    ImageSpaceTexture m_kTextureSlot3;
    char _4[0x0f];
    ImageSpaceTexture m_kTextureSlot4;
    char _5[0x1f];
    bool m_bHeaderParsed;
    void FUN_00ba1250();
};

// @fnv 0x00ba1250
void ImageSpaceTextureSet::FUN_00ba1250()
{
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(m_kTextureSlot2))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(m_kTextureSlot2))->FUN_00ba39a0();
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(m_kTextureSlot3))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(m_kTextureSlot3))->FUN_00ba39a0();
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(m_kTextureSlot0))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(m_kTextureSlot0))->FUN_00ba39a0();
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(m_kTextureSlot1))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(m_kTextureSlot1))->FUN_00ba39a0();
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(m_kTextureSlot4))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(m_kTextureSlot4))->FUN_00ba39a0();
    m_bHeaderParsed = false;
}

struct MemoryManager
{
};

struct ImageSpaceEffectParam
{
    int unk00;
};

struct ImageSpaceShaderParam : ImageSpaceEffectParam
{
    ImageSpaceShaderParam();


    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    char unk54;
    bool bFlag55;
    bool bFlag56;
    char unk57;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
public:
    void SetShaderConstantVector4(int, float, float, float, float);
public:
    void CopyParamData(int, const float *, unsigned int);
public:
    void AllocateShaderConstants(int, int);
};

struct ShaderParamArray
{
};

struct RenderTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual unsigned int GetWidth(int i);
    virtual unsigned int GetHeight(int i);
};

class NiRenderer
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual RenderTarget* GetDefaultRenderTarget();
};

extern const float DAT_011add48[16];

struct TextureArray
{
    virtual ~TextureArray();
    void** m_pBase;
    void* GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
};

struct EffectSource
{
    int unk00;
    TextureArray textures;
};

struct ImageSpaceEffectX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ShaderParamArray params;

    void SetupShaderPasses(EffectSource* src, int unused);
};

// Configures four shader passes with textures and parameters from src, using the default render target dimensions for inverse scale factors.
// @fnv 0x00bd6bb0
void ImageSpaceEffectX::SetupShaderPasses(EffectSource* apSource, int unused)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(4);
    float width = DAT_011f9508->GetDefaultRenderTarget()->GetWidth(0);
    float height = DAT_011f9508->GetDefaultRenderTarget()->GetHeight(0);
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->AllocateShaderConstants(0, 0x18);
        param->CopyParamData(3, DAT_011add48, 0x40);
        param->SetShaderConstantVector4(2, 1.0f / width, 1.0f / height, 0.0f, 0.0f);
        param->bFlag55 = false;
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, (::ImageSpaceEffect *)(void *)(apSource->textures.GetAt(65)), param, 2);
        reinterpret_cast<::FUN_00a41520_cls *>(&(params))->FUN_00ba3aa0(0, (::KeyPair **)&(param));
    }
    ::SetEffectParamAt((char *)this, 0, 1, 1, {});
    reinterpret_cast<::FUN_00a41520_cls *>(&(params))->FUN_00ba3aa0(1, (::KeyPair **)&(const ::ImageSpaceEffectParam *const &)(0));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(1, 2, 3, 0, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(1, (::ImageSpaceEffect *)(void *)(apSource->textures.GetAt(18)), 0, 2);
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->AllocateShaderConstants(0, 3);
        param->SetShaderConstantVector4(0, 1.0f, DAT_01013974, DAT_01013d84, DAT_012023e0);
        param->bFlag56 = false;
        reinterpret_cast<::FUN_00a41520_cls *>(&(params))->FUN_00ba3aa0(2, (::KeyPair **)&(param));
        reinterpret_cast<::fnv_00ba3ba0::Holder *>(this)->FUN_00ba3ba0(2, 1, 2, 4, 0, 1, 0);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(2, (::ImageSpaceEffect *)(void *)(apSource->textures.GetAt(51)), param, 0);
    }
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->AllocateShaderConstants(0, 4);
        param->SetShaderConstantVector4(0, 1.0f, DAT_01013974, DAT_01013d84, DAT_012023e0);
        param->bFlag56 = false;
        reinterpret_cast<::FUN_00a41520_cls *>(&(params))->FUN_00ba3aa0(3, (::KeyPair **)&(param));
        reinterpret_cast<::BBA3C00Shader *>(this)->SetEntryRanges(3, 1, 2, 4, 5, 0, 1, 0, 0);
        reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(3, (::ImageSpaceEffect *)(void *)(apSource->textures.GetAt(52)), param, 0);
    }
}
