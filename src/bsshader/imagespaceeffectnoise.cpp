// bsshader/imagespaceeffectnoise.cpp: free functions (2 functions)

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_011f6000.h"
#include "imagespaceeffectnoise_decls.h"

// @fnv 0x00c05180
void NoiseImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam*)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(textures))->FUN_00a90180(2);
    ImageSpaceShaderParam* shader = new ImageSpaceShaderParam;
    shader->AllocateShaderConstants(0, 4);
    reinterpret_cast<::FUN_00a41520_cls *>(&(params))->FUN_00ba3aa0(0, (::KeyPair **)&(shader));
    ::SetEffectParamAt((char *)this, 0, 1, 0, {});
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, manager->effects->noise, shader, 0);
}

class ImageSpaceEffectParam;
class NiTPrimitiveArray_ImageSpaceEffectParam___
{
  public:
};

// Allocates an 8-byte parameter from two ints and stores it at uiIndex in the array at pThis+0x38.
// @fnv 0x00ba3b10
void SetEffectParamAt(char* pThis, int, unsigned int uiIndex, int a2, int a3)
{
    int* p = (int*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(8);
    p[0] = a2;
    ImageSpaceEffectParam* param = (ImageSpaceEffectParam*)p;
    p[1] = a3;
    reinterpret_cast<::FUN_00a41520_cls *>((((NiTPrimitiveArray_ImageSpaceEffectParam___*)(pThis + 0x38))))->FUN_00ba3aa0(uiIndex, (::KeyPair **)&(param));
}
