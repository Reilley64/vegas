// bsshader/imagespaceeffectblur_decls.h: declares MemoryManager, ImageSpaceManager, NiTexturingProperty, ImageSpaceShaderParam
#ifndef IMAGESPACEEFFECTBLUR_DECLS_H
#define IMAGESPACEEFFECTBLUR_DECLS_H
#include <cstddef>

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00ba3b50_t.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_011f6000.h"
class MemoryManager
{
  public:
};
extern float DAT_011ae6c8, DAT_011ae6cc;
class ImageSpaceEffectParam
{
};
class ImageSpaceEffect;
class ImageSpaceManager
{
  public:
    char pad[8];
    ImageSpaceEffect** effects;
    __forceinline ImageSpaceEffect* GetEffect(unsigned int index)
    {
        return effects[index];
    }
};
class ImageSpaceTexture;
class NiTexturingProperty
{
  public:
    enum FilterMode
    {
        FILTER_NEAREST,
        FILTER_BILERP
    };
};
template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTArray
{
  public:
    void* vtable;
    T* data;
    unsigned short capacity, size, effective, grow;
    void SetSize(unsigned int);
    // SetAt changes the array storage without retaining the argument reference.
    __declspec(noalias) void SetAt(unsigned int, T const&);
};
class ImageSpaceEffect
{
  public:
    char prefix[24];
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > pEffectParamList;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > pTextures;
public:
    void SetTextureArraySize(int);
};
class ImageSpaceEffectFourTexturePass : public ImageSpaceEffect
{
  public:
    void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
};
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    char data[0x56];
    unsigned char unk56;
    char pad57[0x31];
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int, int);
    void SetShaderConstantVector4(int, float, float, float, float);
};
#endif
