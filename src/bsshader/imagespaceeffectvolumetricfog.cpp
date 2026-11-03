
// src/bsshader/imagespaceeffectvolumetricfog.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectvolumetricfog.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/ImageSpaceEffect.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_011f6000.h"
typedef unsigned int size_t;

struct ImageSpaceTexture;
struct ImageSpaceEffectParam
{
};

template <typename T> struct NiTPrimitiveArray
{
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usGrowBy;
    unsigned short m_usQuantity;
    char pad[6];
    void SetSize(unsigned int size);
    void SetAt(unsigned int i, const T& element);
};

struct MemoryManager
{
};


struct ImageSpaceShaderParam : public ImageSpaceEffectParam
{
    char pad[0x88];


    ImageSpaceShaderParam();
public:
    void SetShaderConstantVector4(int, float, float, float, float);
public:
    void AllocateShaderConstants(int, int);
};

struct Arg2Inner
{
    char pad[0xa8];
    int field_a8;
};

struct Arg2
{
    char pad[8];
    Arg2Inner* field_8;
};

struct FUN_00c05780_class
{
    char pad_00[0x18];
    NiTPrimitiveArray<ImageSpaceEffectParam*> m_shaderParams;
    NiTPrimitiveArray<ImageSpaceTexture*> m_textures;


    void InitShaderEffect(Arg2* a2, void* a3);
};

// @fnv 0x00c05780
void FUN_00c05780_class::InitShaderEffect(Arg2* a2, void* pUnused)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_textures))->FUN_00a90180(2);
    ImageSpaceShaderParam* param = new ImageSpaceShaderParam();
    param->AllocateShaderConstants(0, 1);
    param->SetShaderConstantVector4(0, 1.0f, 1.0f, 1.0f, 1.0f);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_shaderParams))->FUN_00ba3aa0(0, (::KeyPair **)&(param));
    reinterpret_cast<::FUN_00ba3b50_t *>(this)->SetArrayEntry(0, 1, -1, 1, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, (::ImageSpaceEffect *)(a2->field_8->field_a8), (::ImageSpaceEffectParam *)(param), 0);
}
