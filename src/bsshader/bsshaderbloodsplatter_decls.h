// bsshader/bsshaderbloodsplatter_decls.h: declares NiD3DVertexShader, NiD3DPixelShader, BeamStage, D3DRenderStateGroup, NiD3DPass
#ifndef BSSHADERBLOODSPLATTER_DECLS_H
#define BSSHADERBLOODSPLATTER_DECLS_H

#include "fnv/decl/E7DEF0TextureStage.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/StageSet.h"
#include "fnv/decl/StateGroup.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00e7e000.h"
#include "fnv/symbols_0126f000.h"
#include "bsshaderbloodsplatter_types_BSShaderBloodSplatter.h"

class NiD3DVertexShader : public NiRefObject
{
};
class NiD3DPixelShader : public NiRefObject
{
};

#define SPLATTER_ASSIGN(T)                                                                                             \
    inline NiPointer<T>& NiPointer<T>::operator=(T* object)                                                            \
    {                                                                                                                  \
        if (m_pObject != object)                                                                                       \
        {                                                                                                              \
            T* old = m_pObject;                                                                                        \
            if (old)                                                                                                   \
                old->DecRefCount();                                                                                    \
            m_pObject = object;                                                                                        \
            if (m_pObject)                                                                                             \
                m_pObject->IncRefCount();                                                                              \
        }                                                                                                              \
        return *this;                                                                                                  \
    }
SPLATTER_ASSIGN(NiD3DVertexShader)
SPLATTER_ASSIGN(NiD3DPixelShader)

class BeamStage
{
  public:
    unsigned char layoutPrefix[0x60];
    unsigned int m_uiRefCount;
    void DecRefCount()
    {
        --m_uiRefCount;
        if (m_uiRefCount == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>(this)->FUN_00e7ecd0();
    }
};
template <> class NiPointer<BeamStage>
{
  public:
    BeamStage* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    BeamStage* operator->() const
    {
        return m_pObject;
    }
    operator BeamStage*() const
    {
        return m_pObject;
    }
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};
class NiD3DPass
{
  public:
    unsigned char layoutPrefix[0x14];
    unsigned int m_uiStageMask;
    unsigned char layoutStages[0x18];
    D3DRenderStateGroup* m_pRenderStateGroup;
    unsigned char layoutPixel[0x10];
    NiPointer<NiD3DPixelShader> m_spPixelShaderObject;
    unsigned char layoutVertex[0x14];
    NiPointer<NiD3DVertexShader> m_spVertexShaderObject;
    static void CreateD3DPass(NiPointer<NiD3DPass>&);
    void SetRenderState(unsigned int state, unsigned int value, bool save)
    {
        if (!m_pRenderStateGroup)
            m_pRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        reinterpret_cast<::StateGroup *>((m_pRenderStateGroup))->SetNodeValue(state, value, save);
    }
    void SetVertexShader(NiD3DVertexShader* shader)
    {
        m_spVertexShaderObject = shader;
    }
    void SetPixelShader(NiD3DPixelShader* shader)
    {
        m_spPixelShaderObject = shader;
    }
public:
    void DestroyPass();
};
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
#undef SPLATTER_ASSIGN
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_uiStageMask) == 0x14);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pRenderStateGroup) == 0x30);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spPixelShaderObject) == 0x44);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spVertexShaderObject) == 0x5c);
FNV_STATIC_ASSERT(offsetof(BeamStage, m_uiRefCount) == 0x60);
#endif
