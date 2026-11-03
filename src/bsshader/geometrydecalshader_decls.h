// bsshader/geometrydecalshader_decls.h: declares NiMemObject, NiRefObject, NiD3DPixelShader, NiD3DVertexShader, NiD3DPass and more

#include <windows.h>
#include "fnv/decl/FUN_00be1750_shell.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_010a1000.h"

class NiMemObject
{
  public:
};

class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject()
    {}
    virtual void DeleteThis()
    {}
    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

class NiD3DPixelShader : public NiRefObject
{
};
class NiD3DVertexShader : public NiRefObject
{
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer();
    ~NiPointer();
    NiPointer<T>& operator=(const NiPointer<T>& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (object)
                object->IncRefCount();
        }
        return *this;
    }
};

template <class> class NiPointer;
class NiD3DPass
{
  public:
    virtual void Placeholder()
    {}
    unsigned char unk04[0x60];
    unsigned int m_uiRefCount;
    void DestroyPass();
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        --m_uiRefCount;
        if (!m_uiRefCount)
            DestroyPass();
    }
public:
    bool ApplyRenderStateChanges(bool);
public:
    static void CreateD3DPass(::NiPointer< ::NiD3DPass> &);
};

class GraphicsRenderer;

struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};

class NiGPUProgram : public NiRefObject
{
  public:
    enum ProgramType
    {
        PROGRAM_VERTEX = 0,
        PROGRAM_PIXEL = 2
    };
};

template <> NiPointer<NiD3DPass>::NiPointer();
template <> NiPointer<NiD3DPass>::~NiPointer();
template <> NiPointer<NiD3DPixelShader>::NiPointer();
template <> NiPointer<NiD3DPixelShader>::~NiPointer();

class PassReference
{
  public:
    NiRefObject* m_pObject;
    PassReference() : m_pObject(0)
    {}
    ~PassReference()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    PassReference& operator=(NiRefObject* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

class NiD3DShaderConstantMap : public NiRefObject
{
  public:
    NiGPUProgram::ProgramType m_iProgramType;
    unsigned char unk0c[0x38];

    NiD3DShaderConstantMap(GraphicsRenderer* renderer, unsigned int type);

    virtual unsigned int AddConstant10(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*,
                                       unsigned int, unsigned int, const void*, bool)
    {
        return 0;
    }
    virtual void Slot03()
    {}
    virtual void Slot04()
    {}
    virtual void Slot05()
    {}
    virtual void Slot06()
    {}
    virtual void Slot07()
    {}
    virtual void Slot08()
    {}
    virtual void Slot09()
    {}
    virtual void Slot10()
    {}
    virtual void Slot11()
    {}
    virtual void Slot12()
    {}
    virtual void Slot13()
    {}
    virtual void Slot14()
    {}
    virtual void Slot15()
    {}
    virtual void Slot16()
    {}
    virtual void Slot17()
    {}
    virtual void Slot18()
    {}
    virtual void Slot19()
    {}
    virtual void Slot20()
    {}
    virtual void Slot21()
    {}
    virtual void Slot22()
    {}
    virtual void Slot23()
    {}
    virtual void Slot24()
    {}
    virtual void Slot25()
    {}
    virtual unsigned int AddConstant8(const char*, unsigned int, unsigned int, const char*, unsigned int, unsigned int,
                                      const void*, bool)
    {
        return 0;
    }
    virtual void Slot27()
    {}
    virtual NiRefObject* GetEntry(const char*)
    {
        return 0;
    }
};

extern const char DAT_010bb750[];
extern const char DAT_010bb744[];
extern const float DAT_012021d0[];
extern const float DAT_012021c0[];

class BSShader : public NiRefObject
{
  public:
    unsigned char unk08[0x10];
    GraphicsRenderer* m_pShaderObject;
    unsigned char unk1c[8];
    bool m_bIsInitialized;
    bool m_bSoftwareVertexProcessing;
    unsigned char unk26[2];
    NiRefObject* m_spShaderDeclaration;
    void* m_pRenderStateGroup;
    PassReference m_spFirstShaderConstantMap;
    PassReference m_spSecondShaderConstantMap;
    unsigned int m_uiShaderType;
    unsigned char unk3c[0x2c];
    int m_iPassId;

    BSShader();
};

class GeometryDecalShader : public BSShader
{
  public:
    NiPointer<NiD3DPass> m_spPasses[2];
    NiPointer<NiD3DPixelShader> m_spVertexShaders[2];
    NiPointer<NiD3DPixelShader> m_spPixelShaders[2];
    PassReference m_pkPass0;
    PassReference m_pkPass1;
    PassReference m_pkPass2;

    GeometryDecalShader();
    void UpdateShaderConstants();
};
