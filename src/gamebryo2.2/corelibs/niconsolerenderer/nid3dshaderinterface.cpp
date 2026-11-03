// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderinterface.cpp: NiD3DShaderInterface (11 functions)

#include <new>
#include "fnv/decl/FUN_00a5d3a0.h"
#include "fnv/decl/FUN_00a8f490.h"
#include "fnv/decl/FUN_00e93ad0.h"
#include "fnv/decl/NiRefObject.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e7e000.h"
#include "fnv/symbols_00e7f000.h"
#include "fnv/symbols_00e91000.h"
#include "fnv/symbols_00e92000.h"
#include "fnv/symbols_00e93000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_0109f000.h"
#include "fnv/symbols_010ef000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_0126f000.h"
#include "nid3dshaderinterface_decls.h"

// @fnv 0x00e81a90
bool NiD3DShaderInterface::Initialize()
{
    if (!NiRenderer::ms_pRenderer)
        return false;
    SetShaderObject((GraphicsRenderer*)NiRenderer::ms_pRenderer);
    return NiShader::Initialize();
}

// @fnv 0x00e818d0
void NiD3DShaderInterface::SetShaderObject(GraphicsRenderer* renderer)
{
    m_pShaderObject = renderer;
    if (renderer)
    {
        ShaderPassRenderer* state = renderer->m_pCurrentRenderState;
        if (m_pRenderState)
        {
            typedef void(__stdcall * ReleaseFunction)(ShaderPassRenderer*);
            ReleaseFunction release = (ReleaseFunction)m_pRenderState->m_ppVirtualMethodTable[2];
            release(m_pRenderState);
        }
        m_pRenderState = state;
        if (state)
        {
            typedef void(__stdcall * AddRefFunction)(ShaderPassRenderer*);
            AddRefFunction addRef = (AddRefFunction)state->m_ppVirtualMethodTable[1];
            addRef(state);
        }
        m_pD3DDevice = m_pShaderObject->m_pD3DDevice;
    }
    else
    {
        m_pD3DDevice = 0;
        if (m_pRenderState)
        {
            typedef void(__stdcall * ReleaseFunction)(ShaderPassRenderer*);
            ReleaseFunction release = (ReleaseFunction)m_pRenderState->m_ppVirtualMethodTable[2];
            release(m_pRenderState);
        }
        m_pRenderState = 0;
    }
}

// @fnv 0x00e81940
unsigned int NiD3DShaderInterface::InitializeShaderRenderer(GraphicsRenderer* renderer)
{
    Direct3DDeviceInterface* device = renderer->m_pD3DDevice;
    ::FUN_00e7f920((int)(renderer));
    ::FUN_00e7e8d0((int)(renderer));
    (*reinterpret_cast<::Direct3DDeviceInterface * *>(&::DAT_0126f99c)) = device;
    ::FUN_00e92f70((int)(renderer));
    ::FUN_00e93f50(renderer);
    NiD3DPass::SetActiveRenderer(renderer);
    device->vfn_100();
    NiD3DShaderFactory* factory = ((::NiD3DShaderFactory *)(::FUN_00e91f10()));
    if (factory)
        factory->vfn_70(renderer);
    if (!::DAT_0126fa10)
    {
        Program* p = (Program*)NiMemObject::operator new(28);
        ::DAT_0126fa10 = p ? ((::Program *)(new ((void *)(p)) ::FUN_00e93ad0())) : 0;
        if (!::DAT_0126fa10)
            ::FUN_00a29680();
    }
    return 0;
}

extern int DAT_0109f584;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// Sets the vtable and clears fields of the object, increments the global counter, then assigns the second vtable and initializes the remaining fields.
// @fnv 0x00a8f440
void* __fastcall FUN_00a8f440(void* apObject)
{
    *(int**)apObject = &::DAT_0101dce4;
    *((int*)apObject + 1) = 0;
    InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    *(int**)apObject = &DAT_0109f584;
    *((int*)apObject + 2) = (*reinterpret_cast<int *>(&::DAT_0109b220));
    *((int*)apObject + 3) = 0;
    *((char*)apObject + 16) = 0;
    return apObject;
}

// @fnv 0x00a8f1b0
const char* const* __fastcall FUN_00a8f1b0(void* p, int)
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f5d00));
}

// @fnv 0x00a8f480
const char* const* __fastcall FUN_00a8f480(void* p, int)
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f5d08));
}

struct VF
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void Op(int);
};
void FUN_00aa0000();
void DestroyProgram();
// @fnv 0x00e819f0
int FUN_00e819f0()
{
    VF* pShaderFactory = (VF*)((::NiD3DShaderFactory *)(::FUN_00e91f10()));
    if (pShaderFactory)
    {
        FUN_00aa0000();
        pShaderFactory->Op(0);
    }
    ::FUN_00e7f920((int)(0));
    ::FUN_00e7e8d0((int)(0));
    (*reinterpret_cast<::Direct3DDeviceInterface * *>(&::DAT_0126f99c)) = 0;
    DestroyProgram();
    ::FUN_00e92f70((int)(0));
    ::FUN_00e93f50(0);
    NiD3DPass::SetActiveRenderer(0);
    return 0;
}

struct Rel
{
    virtual void a();
    virtual void b();
    virtual unsigned long __stdcall Release();
};
struct Obj
{
    void* vt;
    int p[4];
    Rel* dev;
    int r;
    int s;
};
// Sets the object's vtable, clears r and s, releases dev if set, nulls dev, then calls FUN_00a8f490.
// @fnv 0x00e81a50
void __fastcall FUN_00e81a50(Obj* pObj, int)
{
    *(int**)pObj = &DAT_010ef39c;
    Rel* d = pObj->dev;
    pObj->r = 0;
    pObj->s = 0;
    if (d)
        d->Release();
    pObj->dev = 0;
    reinterpret_cast<class ::FUN_00a8f490 *>((pObj))->FUN_00a8f490::~FUN_00a8f490();
}

namespace fnv_00e81ab0 {
struct Rel
{
    virtual void a();
    virtual void b();
    virtual unsigned long __stdcall Release();
};
struct Obj
{
    void* vt;
    int p[4];
    Rel* dev;
    int r;
    int s;
};
// @fnv 0x00e81ab0
Obj* __fastcall FUN_00e81ab0(Obj* o, int, unsigned int flags)
{
    *(int**)o = &::DAT_010ef39c;
    Rel* d = o->dev;
    o->r = 0;
    o->s = 0;
    if (d)
        d->Release();
    o->dev = 0;
    reinterpret_cast<class ::FUN_00a8f490 *>((o))->FUN_00a8f490::~FUN_00a8f490();
    if (flags & 1)
        ::FUN_00aa1460(o, 0x24);
    return o;
}
}  // namespace fnv_00e81ab0

struct Rf
{
    virtual void a();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
// Stores r in DAT_0126fa2c and, if r is non-null, releases the old DAT_0126fa28 and AddRefs the object at r+0x288; otherwise releases and clears DAT_0126fa28.
// @fnv 0x00e93f50
void FUN_00e93f50(void* apObject)
{
    DAT_0126fa2c = apObject;
    if (apObject)
    {
        Rf* pRef = *(Rf**)((char*)apObject + 0x288);
        if ((*reinterpret_cast<::Rf * *>(&::g_0126fa28)))
            (*reinterpret_cast<::Rf * *>(&::g_0126fa28))->Release();
        (*reinterpret_cast<::Rf * *>(&::g_0126fa28)) = pRef;
        if (pRef)
            pRef->AddRef();
    }
    else
    {
        if ((*reinterpret_cast<::Rf * *>(&::g_0126fa28)))
            (*reinterpret_cast<::Rf * *>(&::g_0126fa28))->Release();
        (*reinterpret_cast<::Rf * *>(&::g_0126fa28)) = 0;
    }
}

// Constructor of a derived object: base ctor call, two zeroed fields, vtable pointer, one more zeroed field.

struct FUN_00a8f190_cls
{
    void* m_pVTable;  // +0x00
    int m_i04;        // +0x04
    int m_i08;        // +0x08
    int m_i0C;        // +0x0C
    int m_i10;        // +0x10

      // base constructor (external)

    FUN_00a8f190_cls();
};

// @fnv 0x00a8f190
FUN_00a8f190_cls::FUN_00a8f190_cls()
{
    new ((void *)this) struct ::FUN_00a5d3a0();
    m_i08 = 0;
    m_i0C = 0;
    *(void* volatile*)&m_pVTable = &(*reinterpret_cast<int *>((void *)&::DAT_0109f4dc));
    *(int volatile*)&m_i10 = 0;
}
