#include <cstddef>
// bsshader/imagespaceeffectnoise_decls.h: declares MemoryManager, ImageSpaceShaderParam, ImageSpaceManager, Effects

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_011f6000.h"
class MemoryManager
{
  public:
};
class ImageSpaceEffectParam
{
    char storage[36];
};
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
    char storage[100];

  public:
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int, int);
};
template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTArray
{
    char storage[16];

  public:
    void SetSize(unsigned int);
    void SetAt(unsigned int, const T&);
};
class ImageSpaceTexture;
class ImageSpaceEffect
{
  public:
    char prefix[24];
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > params;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > textures;
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > inputs;
public:
    void SetTextureArraySize(int);
};
class ImageSpaceManager
{
  public:
    char prefix[8];
    struct Effects
    {
        char prefix[200];
        ImageSpaceEffect* noise;
    }* effects;
};
class NoiseImageSpaceEffect : public ImageSpaceEffect
{
  public:
    void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
};
