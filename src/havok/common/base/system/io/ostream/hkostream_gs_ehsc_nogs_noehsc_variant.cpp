
// src/havok/common/base/system/io/ostream/hkostream_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/system/io/ostream/hkostream.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/system/io/ostream/hkostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/ostream/hkostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00c903b0_class.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/fnv_00cbf2f0__FUN_00cbf2f0_class.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010c9000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkOstream.h"
extern "C" __declspec(dllimport) void __stdcall free(void*);
void __cdecl FUN_00c85750();
struct Old
{
};
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    ~FUN_00cc00e0();
};
struct hkReferencedObjectStandIn
{
};
struct DDCC60WorldStandIn
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    hkReferencedObjectStandIn* m_ref;
    void FUN_00cc0480(hkReferencedObjectStandIn* pNew);
};
struct FUN_00cc0680
{
    int tell();
};
struct FUN_00cc07f0_Router
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Free(void*, unsigned short);
};
struct FUN_00cc07f0_MemoryRouter
{
    unsigned char padding[0x10];
    FUN_00cc07f0_Router* pRouter;
};
struct FUN_00cc07f0_StandIn
{
// @fnv 0x00cc07f0
    virtual ~FUN_00cc07f0_StandIn()
    {}
    void FUN_00cc0780();
    unsigned short m_nSize;

    FUN_00cc07f0_StandIn* FUN_00cc07f0(unsigned int deletingFlag);
};
struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    CpuInterface* target;
    void FUN_00cc0460();
};
// FUN_00cc0470 : the stub family - load a sub-object out of `this` and tail-jump to
// one of its virtuals (vtable offset 0x10).
struct Sub_00cc0470
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(void* a);
};
struct Own_00cc0470
{
    int u00;
    int u04;
    Sub_00cc0470* m_sub;
    void __thiscall FUN_00cc0470(void* a);
};
int* __cdecl FUN_00cc04c0();
int __cdecl FUN_00cc0770();
void __stdcall FUN_00e3b490(bool* p);
struct FUN_00cc04a0_Slots
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C(const char* name, void* value, int flags);
};
struct FUN_00cc04a0_Cls
{
    int unk00;
    int unk04;
    void* unk08;
    void RegisterWriter(FUN_00cc04a0_Slots* target, int unused);
};
class hkMemoryAllocatorCC06
{
  public:
    virtual ~hkMemoryAllocatorCC06() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterCC06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorCC06* m_pStreamAllocator;

    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750() throw();
}

class hkRefObjCC06
{
  public:
    virtual ~hkRefObjCC06() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCC06()
    {
        m_sReferenceCount = 1;
    }
    static void* operator new(unsigned int nbytes) throw()
    {
        hkRefObjCC06* b = static_cast<hkRefObjCC06*>(hkRouterCC06::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class FUN_00cc06f0 : public hkRefObjCC06
{
  public:
    int unk08;
    int unk0C;
    int unk10;

    FUN_00cc06f0(void* owner, int flag) throw();
};
class FUN_00cc0630 : public hkRefObjCC06
{
  public:
    FUN_00cc06f0* m_pChildAtom;

    FUN_00cc0630(void* owner);
    virtual ~FUN_00cc0630();
};
class hkMemoryAllocatorCC07
{
  public:
    virtual ~hkMemoryAllocatorCC07() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterCC07
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCC07* m_pStreamAllocator;
    hkMemoryAllocatorCC07& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC07 {
extern "C" hkMemoryRouterCC07& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayCC07
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterCC07::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
    ~hkArrayCC07() throw()
    {
        hkMemoryAllocatorCC07& kAlloc = hkRouterCC07::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class hkBaseObjectCC07
{
  public:
    virtual ~hkBaseObjectCC07() throw()
    {}
};
class FUN_00cc0780 : public hkBaseObjectCC07
{
  public:
    int unk04;
    hkArrayCC07<unsigned char>* m_buffer;
    int unk0C;
    int m_external;

    virtual ~FUN_00cc0780() throw();
};
struct GlobalObject_0045cfe0
{
    ~GlobalObject_0045cfe0();
    int unk00;
};
class FUN_00cbf430 : public GlobalObject_0045cfe0
{
  public:
    ~FUN_00cbf430();
};
class hkMemoryAllocatorD60B
{
  public:
    virtual ~hkMemoryAllocatorD60B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD60B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD60B* m_pStreamAllocator;

    hkMemoryAllocatorD60B& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD60B {
extern "C" hkMemoryRouterD60B& __cdecl FUN_00c85750() throw();
}

class hkRefObjD60B
{
  public:
    virtual ~hkRefObjD60B() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjD60B()
    {
        m_sReferenceCount = 1;
    }
    static void* operator new(unsigned int nbytes)
    {
        hkRefObjD60B* b = static_cast<hkRefObjD60B*>(hkRouterD60B::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class FUN_00d60b40 : public hkRefObjD60B
{
  public:
    FUN_00cc06f0* m_pChildAtom;
    char m_flag;

    FUN_00d60b40(void* owner, char flag) throw();
    virtual ~FUN_00d60b40();
};

#include <stdarg.h>
extern "C" const char str_010c9308[];

class hkWriter0080
{
  public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void write(const char* data, int len);
};

static __declspec(noinline) void FUN_00cc0080(hkWriter0080* out, const char* str)
{
    if (str)
    {
        out->write(str, ::fnv_00cb10d0::FUN_00cb10d0((const char *)((int)str)));
    }
    else
    {
        out->write(str_010c9308, 6);
    }
}

// @fnv 0x00cc0410
void __cdecl FUN_00cc0410(hkOstream* self, const char* fmt, ...)
{
    char buf[0x2728];
    va_list ap;
    va_start(ap, fmt);
    ::FUN_00cb0f50((int)(buf), 0x2728, (int)(fmt), (int)(ap));
    va_end(ap);
    FUN_00cc0080((hkWriter0080*)self->m_pStreamWriter, buf);
}
