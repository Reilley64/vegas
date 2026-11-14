#ifndef SPEEDTREELEAFSHADER_DECLS_H
#define SPEEDTREELEAFSHADER_DECLS_H

#include "fnv/symbols_01011000.h"
#include "fnv/symbols_010a1000.h"
#include "fnv/symbols_010af000.h"
#include "fnv/symbols_010b8000.h"
#include "fnv/symbols_010b9000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_01200000.h"
#include "layout_support.h"
#include "NiRefObject.h"

class NiD3DVertexShader;
class NiD3DPixelShader;
class NiD3DPass;
class NiD3DShaderDeclaration;
class NiD3DShaderConstantMap;

template <> class NiPointer<NiD3DShaderDeclaration>
{
  public:
    NiD3DShaderDeclaration* m_pObject;
    ~NiPointer();
};

template <> class NiPointer<NiD3DShaderConstantMap>
{
  public:
    NiD3DShaderConstantMap* m_pObject;
    ~NiPointer();
    NiPointer& operator=(NiD3DShaderConstantMap* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
        }
        return *this;
    }
};

template <> class NiPointer<NiD3DVertexShader>
{
  public:
    NiD3DVertexShader* m_pObject;
    NiPointer();
    ~NiPointer();
};

template <> class NiPointer<NiD3DPixelShader>
{
  public:
    NiD3DPixelShader* m_pObject;
    NiPointer();
    ~NiPointer();
};

template <> class NiPointer<NiD3DPass>
{
  public:
    NiD3DPass* m_pObject;
    NiPointer();
    ~NiPointer();
};

extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned int size);

extern "C"
{
    extern float DAT_01200664;
    extern float DAT_01200674;

    extern const char DAT_010B92D0[];

    void FUN_00b79930();
}

#endif
