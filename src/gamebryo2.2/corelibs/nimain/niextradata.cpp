// gamebryo2.2/corelibs/nimain/niextradata.cpp: NiExtraData, NiAccumulator, MyOwner, ExtraDataObject and more (13 functions)

#include <new>
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FUN_00a5d3a0.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a47000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_0109d000.h"
#include "fnv/symbols_011f4000.h"
#include "niextradata_packet.h"
// @fnv 0x00aa0fe0
void NiAccumulator::ClearCamera()
{
    camera = 0;
}
// @fnv 0x00a7b3b0
void NiExtraData::LinkObject(NiStream& stream)
{
    if (stream.version < 0x0500000b)
        name.handle = stream.GetLoadedObject();
}
// Constructs a NiExtraData: sets the vtable, then assigns name from src with interlocked refcount updates on the string handle.
// @fnv 0x00a7b440
NiExtraData::NiExtraData(const NiFixedString& aName)
{
    const NiFixedString& src = aName;
    *(void**)this = kVtbl_NiExtraData;
    void* empty = (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).handle;
    name.handle = empty;
    void* srcHandle = src.handle;
    if (empty != srcHandle)
    {
        if (srcHandle != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).handle)
            InterlockedIncrement((long*)((char*)srcHandle - 8));
        if (name.handle != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).handle)
            InterlockedDecrement((long*)((char*)name.handle - 8));
        name.handle = srcHandle;
    }
}
// Loads NiExtraData from a stream: reads a count and byte buffer for old versions, otherwise reads the name, registering a NiBinaryExtraData object.
// @fnv 0x00a7b4a0
void NiExtraData::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream));
    if (stream.version < 0x0500000b)
    {
        reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
        unsigned int count;
        ReadCount(stream, count);
        if (count > 0 && IsExactKindOf((*reinterpret_cast<const char (*)[]>(&::g_011f4a80)), this))
        {
            unsigned char* buffer = (unsigned char*)::FUN_00aa1070(count);
            ::FUN_00a471d0((::FUN_00a471d0_Stream *)&(stream), buffer, count);
            NiBinaryExtraData* extra = new NiBinaryExtraData(count, buffer);
            if (extra)
                stream.RegisterObject(extra);
        }
    }
    else if (stream.version < 0x14010001)
        reinterpret_cast<::Cls_a64ea0 *>(&(stream))->FUN_00a64ea0((char **)&(name));
    else
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(stream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(name));
}

struct NiObjectBase
{
    bool RegisterStreamables(NiStream*);
};
struct FakeStream
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual unsigned char f8(int*);
};
struct MyOwner : public NiObject
{
    int _08;
    bool FUN_00a7b290(NiStream&);
};
// @fnv 0x00a7b290
bool MyOwner::FUN_00a7b290(NiStream& kStream)
{
    if (!((NiObjectBase*)this)->NiObjectBase::RegisterStreamables(&kStream))
        return false;
    return ((FakeStream&)kStream).f8(&_08);
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
struct FUN_00a7b330_shell : public NiBinaryExtraData
{
    void FUN_00a7b330(NiBinaryExtraData*, CloningProcess*);
};

struct FUN_00a5d450_holder
{
};
// @fnv 0x00a7b330
void FUN_00a7b330_shell::FUN_00a7b330(NiBinaryExtraData* pkDest, CloningProcess* kCloning)
{
    reinterpret_cast<::FUN_00a5d450_class *>((((FUN_00a5d450_holder*)this)))->CreateVertexBufferSet((unsigned int)(pkDest), kCloning);
    char* src = *(char**)((char*)this + 8);
    if (*(char**)((char*)pkDest + 8) != src)
    {
        if (src != *(char**)&(*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)))
            InterlockedIncrement((long*)(src - 8));
        char* dst = *(char**)((char*)pkDest + 8);
        if (dst != *(char**)&(*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)))
            InterlockedDecrement((long*)(dst - 8));
        *(char**)((char*)pkDest + 8) = src;
    }
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct _Call_a5d3a0
{
    _Call_a5d3a0();
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// Allocates a 12-byte NiExtraData, constructs it, sets its vtable and copies a stored int into offset 8, returning the object or null.
// @fnv 0x00a7b380
NiExtraData* FUN_00a7b380()
{
    NiExtraData* p = (NiExtraData*)BSFadeNode::operator new(12);
    if (p)
    {
        new (p) _Call_a5d3a0;
        *(void**)p = (void*)kVtbl_NiExtraData;
        *(int*)((char*)p + 8) = *(int*)&(*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220));
        return p;
    }
    return 0;
}

struct FUN_00a7b2c0_NiObject
{
};

struct FUN_00a7b2c0_NiStream
{
};

struct FUN_00a7b2c0_shell
{
    void* vtable;
    unsigned int pad;
    char m_kName[1];
    void FUN_00a7b2c0(NiStream& kStream);
};

// @fnv 0x00a7b2c0
void FUN_00a7b2c0_shell::FUN_00a7b2c0(NiStream& kStream)
{
    ::FUN_00a89af0((int)(reinterpret_cast<FUN_00a7b2c0_NiObject*>(this)));
    reinterpret_cast<::FUN_00a641f0_cls *>((reinterpret_cast<FUN_00a7b2c0_NiStream*>(&kStream)))->WriteObjectLink((void *)(m_kName));
}


struct NiRefObject
{
    virtual ~NiRefObject();
};

struct FUN_00a7b300_shell : public NiRefObject
{
    void FUN_00a7b300();
};

// Restores the NiExtraData vtable, releases the reference-counted object at offset 8 if not the empty sentinel, then calls the NiRefObject destructor.
// @fnv 0x00a7b300
void FUN_00a7b300_shell::FUN_00a7b300()
{
    *reinterpret_cast<void* volatile*>(this) = kVtbl_NiExtraData;

    void* pRef = *reinterpret_cast<void* const volatile*>(reinterpret_cast<unsigned char*>(this) + 8);

    if (pRef != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
        InterlockedDecrement(reinterpret_cast<long*>(reinterpret_cast<unsigned char*>(pRef) - 8));

    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
}


struct ExtraDataObject
{
    void* m_vtbl;
    unsigned int refs;
    void* name;

    ExtraDataObject* FUN_00a7b2e0();
};

// @fnv 0x00a7b2e0
ExtraDataObject* ExtraDataObject::FUN_00a7b2e0()
{
    new ((void *)this) struct ::FUN_00a5d3a0();
    m_vtbl = &(*reinterpret_cast<int *>(&::kVtbl_NiExtraData));
    name = (*reinterpret_cast<void * *>(&::DAT_0109b220));
    return this;
}

class NiObject_00a7b3d0
{
  public:
    void* vtable;
    unsigned int _04;
    unsigned int _08;

    unsigned char FUN_00a7b3d0(NiObject_00a7b3d0* object);
};

// Returns 0 if IsSameAs fails; otherwise returns whether _08 equals object->_08.
// @fnv 0x00a7b3d0
unsigned char NiObject_00a7b3d0::FUN_00a7b3d0(NiObject_00a7b3d0* object)
{
    if (!((unsigned char)(reinterpret_cast<::A5d470Class *>(this)->IsSameAs((::A5d470Object *)(object)))))
        return 0;

    return _08 == object->_08;
}

extern "C" void _ReadWriteBarrier(void);

struct Cls
{
    void* m_vptr;
    unsigned int m_refs;
    void* m_nameHandle;


    Cls* DestroyExtraData(unsigned char acFlags);
};

// @fnv 0x00a7b400
Cls* Cls::DestroyExtraData(unsigned char acFlags)
{
    *(volatile void**)&m_vptr = kVtbl_NiExtraData;
    _ReadWriteBarrier();
    if (m_nameHandle != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
    {
        InterlockedDecrement((long*)((char*)m_nameHandle - 8));
    }
    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0xc);
    }
    return this;
}

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity, count, used, grow;
    void Add(char* value)
    {
        unsigned int index = count;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + grow);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
};
extern const char DAT_01097790[];
struct ExtraDataStrings
{
    void* vtable;
    unsigned int refs;
    const char* name;
    const char* GetName() const
    {
        return name;
    }
    void FUN_00a7b580(StrArr* strings);
};
// @fnv 0x00a7b580
void ExtraDataStrings::FUN_00a7b580(StrArr* strings)
{
    strings->Add(::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f4a80))));
    strings->Add(::fnv_00a7d5e0::FUN_00a7d5e0(DAT_01097790, GetName()));
}
