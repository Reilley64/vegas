
// to their real unit once identified.

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00e937f0_shell.h"
#include "fnv/decl/FUN_00e93820_shell.h"
#include "fnv/decl/FUN_00ee9a60_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiGPUProgramCacheE93.h"
#include "fnv/decl/NiRefObject.h"
#include "fnv/decl/S_00ee8af0.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a47000.h"
#include "fnv/symbols_00a64000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e8d000.h"
#include "fnv/symbols_00e92000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_00ee9000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01270000.h"
#include "nid3dgpuprogramcache_decls.h"
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct MemoryManager
{
};
const char* __cdecl FUN_00e8dd60();
void* __cdecl FUN_00e8ea10();
struct RefCounted
{
    virtual void f0();
    virtual void f1();
    volatile long m_ref;
};
struct Holder
{
    RefCounted** m_base;
    unsigned int m_uiItemCount;
    unsigned int m_extra;
    void ReleaseAll();
};
struct S00e8ea20
{
    char _pad[0x44];
    char* _s;
    void* ReleaseAndDestroy(unsigned int);
};
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ValueHolder
{
    void* m_pOwnerObject;
    char* m_pText;
    RefCounted* m_object;
};
struct ObjectReference
{
    RefCounted* m_object;
};
class E8DF70BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(E8DF70BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(E8DF70BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};
template <class T>
inline void E8DF70BinaryStreamSave(E8DF70BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
class E8DF70Shader
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual const char** GetName();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual unsigned int GetCodeSize();
    virtual const char* GetCode();
};
class E8DF70Writer
{
  public:
    bool WriteShader(E8DF70BinaryStream& kStream, E8DF70Shader* pkShader);
};
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct S_00e8e1d0_Ptr
{
    RefCounted* p;
    S_00e8e1d0_Ptr(const S_00e8e1d0_Ptr& o) throw() : p(o.p)
    {
        if (p)
            InterlockedIncrement(&p->m_ref);
    }
    void Release() throw()
    {
        if (p)
        {
            RefCounted* q = p;
            if (!InterlockedDecrement(&q->m_ref))
                q->f1();
        }
    }
};
struct S_00e8e1d0_Node
{
    S_00e8e1d0_Node* next;
    unsigned key;
    S_00e8e1d0_Ptr val;
};
struct S_00e8e1d0_Map
{
    virtual void vf0();
    virtual S_00e8e1d0_Node* Alloc() throw();
    unsigned nBuckets;
    S_00e8e1d0_Node** buckets;
    unsigned count;
    void InsertOrAssign(const unsigned* k, S_00e8e1d0_Ptr v) throw();
};
struct FUN_00e8eb10_cls
{
    int m_vptr;
    int unk04;
    RefCounted* m_08;
    Holder m_0c;

    FUN_00e8eb10_cls* Destroy(unsigned char acFlags);
};
__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedIncrement(volatile long*);
__declspec(nothrow) inline long NiAtomicSubtract(volatile long* value)
{
    return InterlockedDecrement(value);
}
struct StringHeader
{
    volatile long refs;
    unsigned int length;
};
struct NiGlobalStringTable
{
    __declspec(nothrow) static char* AddString(const char*);
    __declspec(nothrow) static volatile long* GetRefCount(char*& h)
    {
        return &((StringHeader*)h - 1)->refs;
    }
    __declspec(nothrow) static void IncRefCount(char*& h)
    {
        if (h == ::DAT_0109b220)
            return;
        InterlockedIncrement(GetRefCount(h));
    }
    __declspec(nothrow) static void DecRefCount(char*& h)
    {
        if (h == ::DAT_0109b220)
            return;
        volatile long* count = GetRefCount(h);
        NiAtomicSubtract(count);
    }
};
class NiFixedString
{
  public:
    char* data;
    __declspec(nothrow) NiFixedString() : data(::DAT_0109b220)
    {}
    __declspec(nothrow) NiFixedString(const char* text);
    __declspec(nothrow) ~NiFixedString();
    NiFixedString& operator=(const char* text)
    {
        if (data != text)
        {
            char* old = data;
            data = NiGlobalStringTable::AddString(text);
            if (old != ::DAT_0109b220)
                InterlockedDecrement(&((StringHeader*)old - 1)->refs);
        }
        return *this;
    }
    NiFixedString& operator=(const NiFixedString& other)
    {
        char* incoming = other.data;
        if (data != incoming)
        {
            NiGlobalStringTable::IncRefCount(incoming);
            char* outgoing = data;
            NiGlobalStringTable::DecRefCount(outgoing);
            data = incoming;
        }
        return *this;
    }
    bool operator==(const char* text) const
    {
        if (data == text)
            return true;
        if (!text || !data)
            return false;
        return ::NiStricmp(data, text) == 0;
    }
};
__declspec(nothrow) NiFixedString::NiFixedString(const char* text)
{
    if (!text)
        data = ::DAT_0109b220;
    else
        data = NiGlobalStringTable::AddString(text);
}
__declspec(nothrow) NiFixedString::~NiFixedString()
{
    NiGlobalStringTable::DecRefCount(data);
}
struct W20Profiles
{
    NiFixedString* data;
    unsigned int capacity, count, unk0c, unk10;
    __declspec(nothrow) void FUN_00e8e290(unsigned int);
    __declspec(nothrow) void PushBack(const NiFixedString& value)
    {
        if (count == capacity)
            FUN_00e8e290(capacity > 0 ? capacity * 2 : 1);
        data[count++] = value;
    }
};
struct W20Base
{
    virtual void foo();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    NiFixedString name;
    unsigned int unk1c, unk20;
    NiFixedString profile;
    W20Profiles profiles;
    __declspec(nothrow) W20Base(int, int, int);
};
struct FUN_00e8e450 : W20Base
{
    int type;
    bool flag;
    NiFixedString suffix;
    virtual void foo();
    __declspec(nothrow) FUN_00e8e450(int, const char*, int, const NiFixedString&, const char*, int, bool, int, bool);
};
struct ShaderStream8e
{
    virtual void v00();
    virtual void v01();
    virtual void Seek(int iNumBytes);
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(ShaderStream8e* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void LoadBinary8e(ShaderStream8e* pkStream, T* pkValue, unsigned int ItemUpdateArray)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pkValue, ItemUpdateArray * sizeof(T), &uiSize, 1);
}
struct ShaderBuffer8e
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void* __stdcall GetBufferPointer();
    virtual unsigned long __stdcall GetBufferSize();
};
struct FixedString8e
{
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};
struct ShaderProgram8e;
struct ShaderFactory8e
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
    virtual ShaderProgram8e* CreateVertexShaderProgram(ShaderBuffer8e* pkCode, unsigned int uiCodeSize,
                                                       const char* pcName, const char* pcEntryPoint,
                                                       const char* pcShaderTarget, void* pvDecl, unsigned int uiUsage,
                                                       bool bSoftwareVP, bool bRecoverable);
    virtual ShaderProgram8e* CreatePixelShaderProgram(ShaderBuffer8e* pkCode, unsigned int uiCodeSize,
                                                      const char* pcName, const char* pcEntryPoint,
                                                      const char* pcShaderTarget, bool bRecoverable);
};
struct ShaderLibrary8e
{
};
struct ShaderLoader8e
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
    virtual const FixedString8e& GetLoaderName();

    bool LoadShaderProgram(ShaderStream8e* pkStream, const FixedString8e& kName, ShaderProgram8e** ppkProgram,
                           bool bSkip);
};

class NiD3DPass;

namespace sc1d790 {

struct MemoryHeap
{
    void FUN_00aa4060(void* pvMem);
};


}

template <class T> class NiPointer
{
  public:
    NiPointer() throw();
    ~NiPointer()
    {}

    static void* operator new[](unsigned int uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::sc1d790::MemoryHeap *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    }
    static void operator delete[](void* pvMem, unsigned int uiSize)
    {
        (*reinterpret_cast<::sc1d790::MemoryHeap *>(&::g_memoryManager)).FUN_00aa4060(pvMem);
    }

    T* m_pObject;
};

namespace sc1d790 {

// @fnv 0x00c1d790
NiPointer<NiD3DPass>* FUN_00c1d790(unsigned int ItemUpdateArray)
{
    return new NiPointer<NiD3DPass>[ItemUpdateArray];
}

}
