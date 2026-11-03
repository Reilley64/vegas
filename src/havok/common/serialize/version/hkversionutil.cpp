
// src/havok/common/serialize/version/hkversionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <new>
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cc0630.h"
struct hkStructureLayoutDC10;
#include "fnv/decl/FUN_00dc1680.h"
#include "fnv/decl/FUN_00e028e0.h"
#include "fnv/decl/FUN_00e04920_cls.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/symbols_00dc0000.h"
#include "fnv/symbols_011b7000.h"
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/ClassMember_d869.h"
#include "fnv/decl/D87370Obj.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00d46f00_s.h"
#include "fnv/decl/FUN_00d46fe0_Class.h"
#include "fnv/decl/FUN_00d47130_class.h"
#include "fnv/decl/FUN_00dc1670_cls.h"
#include "fnv/decl/FUN_00dc1bb0_Class.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/FnvCpu_FUN_00d470d0_CpuObject.h"
#include "fnv/decl/FnvCpu_FUN_00d871f0_CpuObject.h"
#include "fnv/decl/HkClassNode.h"
#include "fnv/decl/Struct_d86920.h"
#include "fnv/decl/TargetClass.h"
#include "fnv/decl/TestClass.h"
#include "fnv/decl/hkBufferedStreamD273.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00e03000.h"
#include "fnv/symbols_00e04000.h"
#include "fnv/symbols_010cf000.h"
#include "fnv/symbols_01268000.h"
extern "C" void __cdecl VisitObjectList(intptr_t, int);

struct FUN_00db7a80_Class
{
    int __pad0;
    int __pad1;
    int __pad2;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void EnsureInitialized();
};

// @fnv 0x00db7a80
void FUN_00db7a80_Class::EnsureInitialized()
{
    if (!m_iFourthElementInteger)
    {
        VisitObjectList(m_kPointB, m_iThirdValue);
        m_iFourthElementInteger = 1;
    }
}

struct MemoryManager
{
    virtual void FUN_00e00000() = 0;
    virtual void FUN_00e00004() = 0;
    virtual void FUN_00e00008(void*, unsigned short) = 0;
};

struct MemoryRouter
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    MemoryManager* m_pMemoryManager;
};

MemoryRouter* _D1A0E0GetMemoryRouter();

struct Object
{
    void FUN_00e03160();
};

struct FUN_00e049d0_Class : Object
{
    unsigned int m_auiShapeKeys;
    unsigned short m_type;

    FUN_00e049d0_Class* FUN_00e049d0(int flags);
};

// @fnv 0x00e049d0
FUN_00e049d0_Class* FUN_00e049d0_Class::FUN_00e049d0(int flags)
{
    Object::FUN_00e03160();

    if (flags & 1)
    {
        MemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short type = m_type;
        router->m_pMemoryManager->FUN_00e00008(this, type);
    }

    return this;
}


// @fnv 0x00dc0fb0
void* __cdecl FUN_00dc0fb0()
{
    return &::str_010cf830;
}

struct FUN_00d86980_Class
{
};

struct FUN_00d871a0
{
    int m_00;
    int m_04;

    FUN_00d871a0(void*, int);
};


// @fnv 0x00dc0fc0
void __cdecl FUN_00dc0fc0(void* a1, int a2, void* a3, int a4)
{
    FUN_00d871a0 obj1(a1, a2);
    FUN_00d871a0 obj2(a3, a4);
    bool b;
    if (((bool)(reinterpret_cast<::TargetClass *>(&(obj1))->FUN_00d871e0((bool *)&(b)))) && ((bool)(reinterpret_cast<::TargetClass *>(&(obj2))->FUN_00d871e0((bool *)&(b)))))
    {
        ::FUN_00cb1260(((void *)(reinterpret_cast<::FnvCpu_FUN_00d871f0_CpuObject *>(&(obj2))->FUN_00d871f0())), ((void *)(reinterpret_cast<::FnvCpu_FUN_00d871f0_CpuObject *>(&(obj1))->FUN_00d871f0())), reinterpret_cast<::ClassMember_d869 *>((((::FUN_00d86980_Class *)(reinterpret_cast<::D87370Obj *>(&(obj2))->FUN_00d87370()))))->FUN_00d86980());
    }
}

struct FUN_00d46d40_s
{
};

class GlobalObjectO2_00d472a0 : public FUN_00d46d40_s
{
  public:
    int m_00;
};


class hkClassMemberDC11
{
  public:
    enum Type
    {
        TYPE_POINTER = 0x14,
        TYPE_ARRAY = 0x16,
        TYPE_STRUCT = 0x19,
        TYPE_SIMPLEARRAY = 0x1a,
        TYPE_VARIANT = 0x1c,
        TYPE_CSTRING = 0x1d,
        TYPE_STRINGPTR = 0x21
    };

    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;

};

class hkVersionCheckDC11
{
  public:
    int IsMemberCompatible(const hkClassMemberDC11* pkOld, const hkClassMemberDC11* pkNew) throw();
};

// Returns 1 if the old class member is compatible with the new one by type/subtype, cstring-to-stringptr, or variant-to-pointer conversion; otherwise 0.
// @fnv 0x00dc1100
int hkVersionCheckDC11::IsMemberCompatible(const hkClassMemberDC11* pkOld, const hkClassMemberDC11* pkNew) throw()
{
    bool bTypeCompatible = (pkOld->m_type == pkNew->m_type) || (pkOld->m_type == hkClassMemberDC11::TYPE_SIMPLEARRAY &&
                                                                pkNew->m_type == hkClassMemberDC11::TYPE_ARRAY);
    bool bCStringToStringPtr =
        (pkOld->m_type == hkClassMemberDC11::TYPE_CSTRING && pkNew->m_type == hkClassMemberDC11::TYPE_STRINGPTR);
    bool bVariantToPtr =
        (pkOld->m_type == hkClassMemberDC11::TYPE_VARIANT && pkNew->m_type == hkClassMemberDC11::TYPE_POINTER &&
         pkNew->m_eSubtype == hkClassMemberDC11::TYPE_STRUCT && reinterpret_cast<::Struct_d86920 *>((void *)(pkNew))->FUN_00d86920() &&
         ::fnv_00cb0fa0::FUN_00cb0fa0(reinterpret_cast<::FnvClassNameNode *>((void *)&(g_01268748))->FUN_00d46d40(), reinterpret_cast<::FnvClassNameNode *>((void *)&((*(const ::FUN_00d46d40_s *)(reinterpret_cast<::TestClass *>((void *)(pkNew))->FUN_00d86910()))))->FUN_00d46d40()) == 0);
    bool bSubTypeCompatible =
        (pkOld->m_eSubtype == pkNew->m_eSubtype) || (pkOld->m_eSubtype == hkClassMemberDC11::TYPE_CSTRING &&
                                                     pkNew->m_eSubtype == hkClassMemberDC11::TYPE_STRINGPTR);
    bool bSubVariantToPtr =
        (pkOld->m_eSubtype == hkClassMemberDC11::TYPE_VARIANT && pkNew->m_eSubtype == hkClassMemberDC11::TYPE_POINTER &&
         reinterpret_cast<::Struct_d86920 *>((void *)(pkNew))->FUN_00d86920() && ::fnv_00cb0fa0::FUN_00cb0fa0(reinterpret_cast<::FnvClassNameNode *>((void *)&(g_01268748))->FUN_00d46d40(), reinterpret_cast<::FnvClassNameNode *>((void *)&((*(const ::FUN_00d46d40_s *)(reinterpret_cast<::TestClass *>((void *)(pkNew))->FUN_00d86910()))))->FUN_00d46d40()) == 0);

    if (::FUN_00e032d0((const void *)this, pkOld) || bCStringToStringPtr || bVariantToPtr ||
        (bTypeCompatible && (bSubTypeCompatible || bSubVariantToPtr)))
        return 1;
    return 0;
}

class hkMemoryAllocatorDC12;

struct hkMemoryRouterDC12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC12* m_pStreamAllocator;
    hkMemoryAllocatorDC12& heap()
    {
        return *m_pStreamAllocator;
    }
};


class hkPointerMapDC12
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkPointerMapDC12() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~hkPointerMapDC12() throw()
    {
        ::FUN_00a29680();
    }

};

class hkVisitorDC12
{
  public:
    int unk00;

    hkVisitorDC12() throw()
    {
        reinterpret_cast<::FUN_00dc1670_cls *>(this)->FUN_00dc1670();
    }
};

// @fnv 0x00dc1230
extern "C" void __cdecl VisitObjectList(intptr_t apvList, int iFlags)
{
    void* const* ppvList = reinterpret_cast<void* const*>(apvList);
    ::ProcessObjectArray((::BE04D90Object **)(ppvList), iFlags);
    hkVisitorDC12 kVisitor;
    hkPointerMapDC12 kDone;
    reinterpret_cast<::FUN_00cb1fe0_t *>(&(kDone))->EnsureCapacity((intptr_t)&((*static_cast<hkMemoryRouterDC12*>(::FUN_00c85750())).heap()), 0);
    for (int i = 0; ppvList[i]; i++)
        reinterpret_cast<::FUN_00dc1bb0_Class *>(&(kVisitor))->FUN_00dc1bb0((uintptr_t)(ppvList[i]), (uintptr_t)&(kDone), 1);
    reinterpret_cast<::CB1A90Owner *>(&(kDone))->ProcessArgument((::CB1A90Argument *)&((*static_cast<hkMemoryRouterDC12*>(::FUN_00c85750())).heap()));
}

class hkBoolDC10
{
  public:
    hkBoolDC10(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};

class FUN_00d27520
{
  public:
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_offset;
    char* m_buf;
    int m_curSize;
    int m_iCapacity;
    char m_overflowed;
public:
    ~FUN_00d27520();
};

class FUN_00d274c0 : public FUN_00d27520
{
  public:
    FUN_00d274c0(void* pvMem, int m_uiSizeAndFlags, hkBoolDC10 bMemoryIsString) throw();
};

struct EntryDC10
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short m_offset;
};

class SetDC10
{
  public:
};

class SectionsDC10
{
  public:
};

// Writes entries from pkSections whose key is not in pkSet to pvBuf via a FUN_00d274c0 writer.
// @fnv 0x00dc1070
void __cdecl FUN_00dc1070(void* apvBuffer, SetDC10* pkSet, SectionsDC10* pkSections)
{
    FUN_00d274c0 kWriter(apvBuffer, reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((pkSections))->FUN_00d470d0(), false);
    for (intptr_t i = 0; i < ((int)(reinterpret_cast<::FUN_00d46f00_s *>((pkSections))->FUN_00d46f00())); i++)
    {
        EntryDC10* pkEntry = ((::EntryDC10 *)(reinterpret_cast<::HkClassNode *>((pkSections))->FUN_00d46f20(i)));
        intptr_t key = pkEntry->m_key;
        if (!((intptr_t)(reinterpret_cast<::FUN_00d46fe0_Class *>((pkSet))->FUN_00d46fe0((const int *)(key)))))
        {
            int iOffset = pkEntry->m_offset;
            reinterpret_cast<::hkBufferedStreamD273 *>(&(kWriter))->FUN_00d27380(iOffset, 0);
            reinterpret_cast<::FUN_00d47130_class *>((pkSections))->InvokeTarget((const char *)(i), (::FUN_00d471c0_target *)(::FUN_00d27520 *)(&kWriter));
        }
    }
    reinterpret_cast<::FUN_00d27520 *>(&(kWriter))->FUN_00d27520::~FUN_00d27520();
}

struct S00dc15a0_Buffer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int* indices, unsigned int size);
};

struct S00dc15a0_AudioSystem
{
    int unk00;
    int unk04;
    int unk08;
    S00dc15a0_Buffer* unk0C;
};

struct S00dc15a0_Params
{
    void* unk00;
    int unk04;
};

struct S00dc15a0_Array
{
    int* m_data;
    intptr_t m_iElementCount;
    int m_capFlags;
};

namespace fnvc_adapt {
}

static __declspec(noinline) int FUN_00dc12c0(S00dc15a0_Params* params, int value, int flags, S00dc15a0_Array* arr)
{
    arr->m_iElementCount = (intptr_t)&params + (intptr_t)&value + (intptr_t)&flags;
    return arr->m_capFlags;
}

// Builds an array containing 0..count-1, passes it to FUN_00dc12c0, and returns that call's result.
// @fnv 0x00dc15a0
int __cdecl FUN_00dc15a0(S00dc15a0_Params* params, int value, int flags)
{
    S00dc15a0_Array arr;
    int count = params->unk04;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000000;

    S00dc15a0_AudioSystem* pAudioSystem = static_cast<S00dc15a0_AudioSystem*>(::FUN_00c85750());
    S00dc15a0_Buffer* heap = pAudioSystem->unk0C;
    int iCurrentCap = arr.m_capFlags & 0x3fffffff;
    if (iCurrentCap < count)
    {
        int newCap = iCurrentCap + iCurrentCap;
        if (count >= newCap)
            newCap = count;
        ::FUN_00c908c0((::SpawnedObject *)(heap), (::SpawnedArray *)(int **)(&arr.m_data), newCap, 4);
    }

    int index = 0;
    arr.m_iElementCount = count;
    if (params->unk04 > 0)
    {
        do
        {
            arr.m_data[index] = index;
            ++index;
        } while (index < params->unk04);
    }

    int result = FUN_00dc12c0(params, value, flags, &arr);

    pAudioSystem = static_cast<S00dc15a0_AudioSystem*>(::FUN_00c85750());
    S00dc15a0_Buffer* heap2 = pAudioSystem->unk0C;
    arr.m_iElementCount = 0;
    if ((arr.m_capFlags & 0x80000000) == 0)
    {
        heap2->vf10(arr.m_data, (arr.m_capFlags & 0x3fffffff) * 4);
    }

    return result;
}

struct hkStructureLayoutDC10
{
    char m_ucBytesInPointer;
    char m_bLittleEndian;
    char m_bReusePaddingOptimization;
    char m_bEmptyBaseClassOptimization;
};

struct hkFlagsDC10
{
    int m_kStorage;
    hkFlagsDC10(int i) : m_kStorage(i)
    {}
};

namespace FUN_00e03120 {
class hkObjectCopier
{
  public:
    hkObjectCopier(const hkStructureLayoutDC10& kSrc, const hkStructureLayoutDC10& kDst, hkFlagsDC10 kFlags);
    virtual void CopyContents();
    int unk04, unk08, unk0C;
};
}

namespace FUN_00dc1040 {
class PackfileObjectCopier : public FUN_00e03120::hkObjectCopier
{
  public:
    PackfileObjectCopier(const hkStructureLayoutDC10& kSrc, const hkStructureLayoutDC10& kDst);
    virtual void CopyContents();
};

// @fnv 0x00dc1040
PackfileObjectCopier::PackfileObjectCopier(const hkStructureLayoutDC10& kSrc, const hkStructureLayoutDC10& kDst)
    : FUN_00e03120::hkObjectCopier(kSrc, kDst, 0)
{}
}


extern "C" void _ReadWriteBarrier();
struct ByteBuffer
{
    ~ByteBuffer();
    char* data;
    int size;
    int capacity;
};
struct IndexArray
{
    int* data;
    int size;
    int capacity;
};
struct ObjectEntry
{
    void* object;
    int type;
};
struct ObjectArray
{
    ObjectEntry* data;
    int size;
    int capacity;
};
struct OffsetEntry
{
    intptr_t offset;
    int type;
};
struct OffsetArray
{
    OffsetEntry* data;
    int size;
    int capacity;
};
struct CopyAllocator
{
    virtual void slot0() = 0;
    virtual char* allocate(int size) = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void release(void* data, int size) = 0;
};
struct CopyRouter
{
    void* field00;
    void* field04;
    void* field08;
    void* field0c;
    CopyAllocator* allocator;
};
struct OffsetMap
{
    void* entries;
    int size;
    int capacity;
    ~OffsetMap()
    {
        reinterpret_cast<::CB1A90Owner *>(this)->ProcessArgument((::CB1A90Argument *)(((CopyRouter*)&(*static_cast<hkMemoryRouterDC12*>(::FUN_00c85750())))->allocator));
        ::FUN_00a29680();
    }
};
struct ByteBufferWriter
{
    void* vtable;
    unsigned short flags;
    unsigned short references;
    void* writer;
    ~ByteBufferWriter()
    {
        reinterpret_cast<struct ::FUN_00cc00e0 *>(this)->FUN_00cc00e0::~FUN_00cc00e0();
    }
};
struct CopyOption
{
    int value;
};
struct Relocation
{
    int offset;
    int target;
};
struct Import
{
    int offset;
    void* name;
    int field08;
    int field0c;
};
struct Relocations
{
    Relocation* local;
    int localCount;
    int localCapacity;
    Import* imports;
    int importCount;
    int importCapacity;
    void* exports;
    int exportCount;
    int exportCapacity;
    void* global;
    int globalCount;
    int globalCapacity;
    void* extra;
    ~Relocations()
    {
        reinterpret_cast<::FUN_00e028e0 *>(this)->FUN_00e028e0::~FUN_00e028e0();
    }
};
struct CopyWriter : Object
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int position;
    int options;
    ~CopyWriter()
    {
        FUN_00e03160();
    }
};
struct CopyListener
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void AddMemoryChunk(char*, int, int) = 0;
    virtual void addImport(void*, char*) = 0;
};

struct ObjectInput
{
    ObjectArray* p;
    ObjectInput(ObjectArray* q) : p(q)
    {}
};
struct OffsetInput
{
    OffsetArray* p;
    OffsetInput(OffsetArray* q) : p(q)
    {}
};
// @fnv 0x00dc12c0
static __declspec(noinline) char* FUN_00dc12c0(IndexArray* indices, ObjectInput objectInput, OffsetInput offsetInput,
                                               CopyListener* listener)
{
    ByteBuffer buffer;
    buffer.data = 0;
    buffer.size = 0;
    buffer.capacity = (int)0x80000000u;
    ByteBufferWriter stream;
    new ((void *)&(stream)) ::FUN_00cc0630(&buffer);
    Relocations fixups;
    fixups.local = 0;
    fixups.localCount = 0;
    fixups.localCapacity = (int)0x80000000u;
    fixups.imports = 0;
    fixups.importCount = 0;
    fixups.importCapacity = (int)0x80000000u;
    fixups.exports = 0;
    fixups.exportCount = 0;
    fixups.exportCapacity = (int)0x80000000u;
    fixups.global = 0;
    fixups.globalCount = 0;
    fixups.globalCapacity = (int)0x80000000u;
    fixups.extra = 0;
    OffsetMap map;
    map.entries = 0;
    map.size = 0;
    map.capacity = -1;
    CopyRouter* mapRouter = (CopyRouter*)&(*static_cast<hkMemoryRouterDC12*>(::FUN_00c85750()));
    _ReadWriteBarrier();
    reinterpret_cast<::FUN_00cb1fe0_t *>(&(map))->EnsureCapacity((intptr_t)(mapRouter->allocator), 0);
    int i;
    for (i = 0; i < indices->size; ++i)
    {
        int index = indices->data[i];
        ObjectEntry* object = &objectInput.p->data[index];
        CopyOption first;
        new ((void *)&(first)) ::FUN_00dc1680((*(const ::FUN_00dc1680 *)(&DAT_011b7b88)));
        CopyOption second;
        new ((void *)&(second)) ::FUN_00dc1680((*(const ::FUN_00dc1680 *)(&DAT_011b7b88)));
        CopyWriter writer;
        new ((void *)&(writer)) ::FUN_00dc1040::PackfileObjectCopier((*(const ::hkStructureLayoutDC10 *)(&second)), (*(const ::hkStructureLayoutDC10 *)(&first)));
        int type = offsetInput.p->data[index].type;
        offsetInput.p->data[index].offset = buffer.size;
        int entryOffset = buffer.size;
        void* entryObject = object->object;
        CopyRouter* entryRouter = (CopyRouter*)&(*static_cast<hkMemoryRouterDC12*>(::FUN_00c85750()));
        _ReadWriteBarrier();
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(&(map))->FUN_00cb1870((*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(entryRouter->allocator)), (uintptr_t)(entryObject), entryOffset);
        reinterpret_cast<::FUN_00e04920_cls *>(&(writer))->FUN_00e04920((uintptr_t)(object->object), object->type, (intptr_t)stream.writer, type, (uintptr_t)(&fixups));
    }
    int size = buffer.size;
    if (size)
    {
        CopyRouter* allocationRouter = (CopyRouter*)&(*static_cast<hkMemoryRouterDC12*>(::FUN_00c85750()));
        _ReadWriteBarrier();
        char* result = allocationRouter->allocator->allocate(size);
        listener->AddMemoryChunk(result, buffer.size, 5);
        ::FUN_00cb1260(result, buffer.data, buffer.size);
        for (i = 0; i < indices->size; ++i)
        {
            offsetInput.p->data[indices->data[i]].offset += (intptr_t)result;
        }
        for (i = 0; i < fixups.localCount; ++i)
        {
            Relocation* relocation = &fixups.local[i];
            *reinterpret_cast<char**>(result + relocation->offset) = result + relocation->target;
        }
        for (i = 0; i < fixups.importCount; ++i)
        {
            listener->addImport(fixups.imports[i].name, result + fixups.imports[i].offset);
        }
        return result;
    }
    return 0;
}

inline ByteBuffer::~ByteBuffer()
{
    CopyAllocator* allocator = ((CopyRouter*)&(*static_cast<hkMemoryRouterDC12*>(::FUN_00c85750())))->allocator;
    size = 0;
    if ((capacity & (int)0x80000000u) == 0)
        allocator->release(data, capacity & 0x3fffffff);
}
