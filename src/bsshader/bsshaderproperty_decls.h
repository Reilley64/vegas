// bsshader/bsshaderproperty_decls.h: declares BSShaderPropertyLightSlot, BSShaderProperty
#ifndef FNV_BSSHADERPROPERTY_DECLS_H
#define FNV_BSSHADERPROPERTY_DECLS_H

#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include "MemoryManager.h"

void __cdecl operator delete(void*);
class NiGeometry;
class ShadowSceneLight;

// Trivial pointer slots let the shader's private allocator own the light array.
// The storage contains only the light pointer, with no per-array lifetime cookie.
struct BSShaderPropertyLightSlot
{
    ShadowSceneLight* light;
    static void* operator new[](unsigned int size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
};
FNV_STATIC_ASSERT(sizeof(BSShaderPropertyLightSlot) == sizeof(ShadowSceneLight*));

class BSShaderProperty
{
  public:
    class ShaderPassEntry;
    class ShaderPassList;
};

class BSShaderProperty::ShaderPassEntry
{
  public:
    NiGeometry* m_pShaderGeometry;
    unsigned short m_usShaderPassType;
    unsigned char m_ucLightIndex;
    bool m_bIsBest;
    bool m_bRendered;
    unsigned char m_ucLightCount;
    unsigned char m_ucLightCapacity;
    unsigned char m_ucPassIndex;
    ShadowSceneLight** m_ppShadowSceneLights;

    ShaderPassEntry(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ...);
    void __cdecl FUN_00ba8c50(unsigned char, ShadowSceneLight*, ...);
    void SetPassEnum(unsigned short value)
    {
        m_usShaderPassType = value;
    }
    void SetFirstPass(bool value)
    {
        m_bIsBest = value;
    }
    void SetGeometry(NiGeometry* value)
    {
        m_pShaderGeometry = value;
    }
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
};

template <> class NiTArray<BSShaderProperty::ShaderPassEntry*, NiTNewInterface<BSShaderProperty::ShaderPassEntry*> >
{
  public:
    virtual ~NiTArray();
    BSShaderProperty::ShaderPassEntry** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00ba8d30(unsigned int);
    unsigned int Add(BSShaderProperty::ShaderPassEntry* item)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_00ba8d30(index + m_usGrowBy);
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(index, (::KeyPair **)&(item));
        return index;
    }
};

class BSShaderProperty::ShaderPassList
{
  public:
    NiTObjectArray<ShaderPassEntry*> m_kRenderPasses;
    unsigned int iSize;
    void Add(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*,
             ShadowSceneLight*);
};
FNV_STATIC_ASSERT(sizeof(BSShaderProperty::ShaderPassEntry) == 16);
FNV_STATIC_ASSERT(sizeof(BSShaderProperty::ShaderPassList) == 20);
#endif
