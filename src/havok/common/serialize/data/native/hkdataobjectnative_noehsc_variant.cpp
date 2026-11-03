
// src/havok/common/serialize/data/native/hkdataobjectnative_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/havok/common/serialize/data/native/hkdataobjectnative.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/D871A0Buffer.h"
#include "fnv/decl/D87250Array.h"
#include "fnv/decl/D87370Obj.h"
#include "fnv/decl/DataObjectHandle.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00d46f00_s.h"
#include "fnv/decl/FUN_00d46f70_cls.h"
#include "fnv/decl/FUN_00d46f80_class.h"
#include "fnv/decl/FUN_00d87200_cls.h"
#include "fnv/decl/FUN_00d87260_cls.h"
#include "fnv/decl/FUN_00d87440_Class.h"
#include "fnv/decl/FUN_00d874b0_class.h"
#include "fnv/decl/FUN_00d87790.h"
#include "fnv/decl/FUN_00d877d0_class.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/HkClassNode.h"
#include "fnv/decl/Pair.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/SlotBitmap.h"
#include "fnv/decl/StringMemberAccessor.h"
#include "fnv/decl/TargetClass.h"
#include "fnv/decl/fnv_00d47080__Container.h"
#include "fnv/decl/fnv_00dbbe80__hkDataClassNativeDBBE.h"
#include "fnv/decl/hkClassEnumD470.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkSetD874.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00d86000.h"
#include "fnv/symbols_00d87000.h"
#include "fnv/symbols_01268000.h"
void FUN_00dbb610(int* p);
struct hkReferencedObject
{
};
struct FUN_00dbb490_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    hkReferencedObject* m_8;
    void SetReferencedObject(hkReferencedObject* p);
};
struct FUN_00dbbb20_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    void* m_10;
    int FUN_00dbbb20(int a);
};
struct FUN_00d46f00_Class
{
};
struct FUN_00dbbc50_Class
{
    int FUN_00dbbc50(int a);
};
struct FUN_00dbbc60_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int FUN_00dbbc60(int a);
};
struct FUN_00d873b0_t
{
    int a;
    int b;
    FUN_00d873b0_t(int x, int y);
};
struct D481D0Class
{
    const char* getName();
};
struct FUN_00dbb920_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    const char* FUN_00dbb920();
};
struct TypeNode
{
};
struct FUN_00dbb9d0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int FUN_00dbb9d0();
};
struct hkDataArrayNative
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int GetElementAsInt(int index);
};
struct FUN_00dbbd70_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    char* m_10;
    int m_14;
    int m_18;
    __int64 GetEntry64(int a);
};
struct Shape
{
};
struct Container
{
};
struct FUN_00dbbfa0_Class
{
    int m_00;
    int m_04;
    int m_08;
    Container* m_0c;

    void FUN_00dbbfa0(int, int);
};
struct FUN_00d46f20_Class
{
};
struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46f20_Class* m_0c;

    void InvokeMemberFunction(int a, int b);
};
struct FUN_00dbc640_class;
struct FUN_00dbc640_allocator
{
// @fnv 0x00dbc640
    virtual void FUN_00dbc640_0()
    {}
    virtual void FUN_00dbc640_1()
    {}
    virtual void FUN_00dbc640_2(FUN_00dbc640_class* p, unsigned short size);
};
struct FUN_00dbc640_router
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0C;
    FUN_00dbc640_allocator* m_10;
};
FUN_00dbc640_router* _D1A0E0GetMemoryRouter();
struct FUN_00dbc640_class
{
    int m_00;
    unsigned short m_04;

    void FUN_00dbb3f0();

    FUN_00dbc640_class* FUN_00dbc640(int flags);
};
FUN_00dbc640_class* FUN_00dbc640_class::FUN_00dbc640(int flags)
{
    this->FUN_00dbb3f0();

    if (flags & 1)
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        router->m_10->FUN_00dbc640_2(this, this->m_04);
    }

    return this;
}
struct Inner
{
    void Run();
};
struct FUN_00dbb930_cls
{
    int unk00;
    int unk04;
    int unk08;
    Inner* m_pInner;
    void FUN_00dbb930();
};
struct FUN_00d47080_Class
{
};
struct FUN_00dbb9e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d47080_Class* unk0c;

    void FUN_00dbb9e0();
};
struct FUN_00dbb9f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d46f00_Class* m_0C;
    void FUN_00dbb9f0();
};
struct FUN_00dbba00_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int FUN_00dbba00(int param_1);
};
__int64 FUN_00dbba40(int);
int FUN_00dc9520(unsigned int arg0);
int FUN_00dbb120(int arg0);
int FUN_00dbb130(int a, int b);
struct FUN_00c90510_Obj : hkReferencedObject
{
};
struct FUN_00d87790_Result
{
    unsigned char value;
};
struct FUN_00d87790_Obj
{
};
struct FUN_00dbb360_Global
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual FUN_00c90510_Obj* vf10();
    virtual FUN_00c90510_Obj* vf14();
};
extern int DAT_010d6518[];
struct FUN_00dbb360_Class
{
    int m_00;
    unsigned short m_04, m_06;
    hkReferencedObject* m_08;
    hkReferencedObject* m_0C;
    FUN_00d87790_Obj m_10;
    int m_14, m_18, m_1C, m_20, m_24;
    FUN_00dbb360_Class* Initialize();
};
class hkMemoryAllocatorDBB5
{
  public:
    virtual ~hkMemoryAllocatorDBB5() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterDBB5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB5* m_pStreamAllocator;

    hkMemoryAllocatorDBB5& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDBB5 {
extern "C" hkMemoryRouterDBB5& __cdecl FUN_00c85750() throw();
}
class hkRefObjDBB5
{
  public:
    virtual ~hkRefObjDBB5() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjDBB5() throw()
    {
        m_sReferenceCount = 0;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB5* b = static_cast<hkRefObjDBB5*>(hkRouterDBB5::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class hkStringDBB5
{
  public:
    int unk00;
    int unk04;
};
class hkStringFnDBB5
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};
struct hkNameDescDBB5
{
    const char* m_name;
    int m_len;
};
class hkLibDBB5;
class hkResourceDBB5 : public hkRefObjDBB5
{
  public:
    int m_08;

    hkResourceDBB5() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB5() throw();
};
class hkNodeDBB5 : public hkResourceDBB5
{
  public:
    hkStringDBB5 m_name;
    hkLibDBB5* m_pOwnerObject;

    hkNodeDBB5() throw()
    {}
    virtual ~hkNodeDBB5() throw();
};
class hkNodeRefDBB5
{
  public:
    hkNodeDBB5* m_node;
};
class hkLibDBB5
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB5* m_pStringFunctions;

    hkNodeRefDBB5 CreateNode(const hkNameDescDBB5& desc);
};
struct hkErrorDBB7
{
    virtual ~hkErrorDBB7();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
struct hkOstreamDBB7
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    hkOstreamDBB7& FUN_00cc0120(const void* pvPointer) throw();
};
struct FUN_00cb1600 : hkOstreamDBB7
{
    FUN_00cb1600(char* pcBuffer, int iSize) throw();
};
struct hkBoolDBB7
{
    char m_bValue;
    hkBoolDBB7() throw()
    {}
};
struct FUN_00d46d40_s
{
};
struct hkClassDBB7 : FUN_00d46d40_s
{
    hkBoolDBB7 GetLastNodeFlag() const throw();
};
class hkVtableClassRegistryDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual hkClassDBB7* GetClassFromVirtualInstance(void* pvObject) throw();
};
class hkDataWorldNativeDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};
class hkDataObjectNativeDBB7
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    hkDataWorldNativeDBB7* m_pkWorld;
    hkVtableClassRegistryDBB7* m_pkVtableRegistry;
    int m_aiUnk10[4];
    void* m_pvObject;
    void* m_pkClass;

    hkDataWorldNativeDBB7* getWorld() const
    {
        return m_pkWorld;
    }
    void SetContents(void* pvObject, hkClassDBB7& kClass);
};
struct hkBoolDBB9
{
    char m_cBooleanValue;
    hkBoolDBB9(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
class hkNamedNodeDBB9
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual const char* getName() const throw();
    virtual void V3() throw();
    virtual hkNamedNodeDBB9* getNext() const throw();

    hkBoolDBB9 FUN_00dbb970(const hkNamedNodeDBB9* pkNode) const;
};
class hkHalf
{
  public:
    short m_uiFilterValue;
    hkHalf()
    {}
    hkHalf(float f)
    {
        int t = *(int*)&f;
        m_uiFilterValue = (short)(t >> 16);
    }
};
hkHalf MakeZeroHalf(int a);
struct FUN_00d871a0_Data
{
    int memberData;
    int key;
    void FUN_00d871a0(void* value, int argument);
};
struct FUN_00dbbae0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int FUN_00dbbae0(int argument);
};
class hkOwnerDBBB;
struct hkRefDBBB
{
    hkOwnerDBBB* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDBBB(hkOwnerDBBB* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};
class hkOwnerDBBB
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8(int iKey);

    hkRefDBBB MakeRef(int iKey);
};
struct FUN_00dbbca0_class
{
    int m_00, m_04, m_08, m_0c;
    char* m_10;
    int m_14, m_18, m_1c;
    float FUN_00dbbca0(int index);
};
class hkMemoryAllocatorDBBD
{
  public:
    virtual ~hkMemoryAllocatorDBBD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterDBBD
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDBBD* m_pStreamAllocator;
    hkMemoryAllocatorDBBD& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDBBD& __cdecl FUN_00c85750();
struct hkClassMemberTypeDBBD
{
    int unk00;
    int unk04;
    short m_iElementCount;
};
struct hkArrayBaseDBBD
{
    void* m_data;
    int m_iElementCount;
};
class FUN_00dbbb90
{
  public:
    virtual ~FUN_00dbbb90() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void* operator new(unsigned int nbytes)
    {
        FUN_00dbbb90* b = static_cast<FUN_00dbbb90*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    FUN_00dbbb90(int iWorld, void* pvData, int iSize, int iStride, int iType, int m_iMenuId, int iTupleCount) throw();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
class hkDataObjectNativeDBBD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_pOwningWorld;
    char* m_data;
    int unk14;
    int m_iElementIndex;
    int m_type;
    int m_class;
    int unk24;
    int m_iFlags;

    FUN_00dbbb90* GetElement(int iIndex);
};
struct FUN_00d46f20_Map
{
};
struct FUN_00dbbe30_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00d46f20_Map* m_map;

    int GetValueForKey(int iKey);
};
enum hkTypeDBC3
{
    TYPE_POINTER = 0x1d,
    TYPE_FLAGS = 0x21
};
struct hkClassMemberDBC3
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    hkTypeDBC3 getType() const
    {
        return (hkTypeDBC3)m_type;
    }
};
class hkVariantDBC3
{
  public:
    int unk00;
    int unk04;

    hkVariantDBC3(void* obj, void* name) throw()
    {
        reinterpret_cast<::D871A0Buffer *>(this)->FUN_00d871a0((*(const ::D871A0Array *)(obj)), (int)(name));
    }
    void FUN_00d871a0(void* obj, void* name) throw();
};
class hkObjDBC3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    char m_data[4];

    unsigned int GetMemberValue(void* name);
};
struct FUN_00c85750_Result
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    class FUN_00dba490_heap* m_10;
};
struct FUN_00c85750_Class
{
    int FUN_00c85750();
};
class FUN_00dba490_heap
{
  public:
    virtual void h_slot0();
    virtual void h_slot1();
    virtual void h_slot2();
    virtual void h_slot3();
    virtual void h_freeBlock(int param, int size);
};
struct FUN_00dba490_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;

    void FUN_00dba490();
};
class hkMemoryAllocatorDBB6
{
  public:
    virtual ~hkMemoryAllocatorDBB6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};
struct hkMemoryRouterDBB6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB6* m_pStreamAllocator;

    hkMemoryAllocatorDBB6& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDBB6 {
extern "C" hkMemoryRouterDBB6& __cdecl FUN_00c85750() throw();
}
class hkRefObjDBB6
{
  public:
    virtual ~hkRefObjDBB6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjDBB6() throw()
    {
        m_sReferenceCount = 0;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB6* b = static_cast<hkRefObjDBB6*>(hkRouterDBB6::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class hkStringDBB6
{
  public:
    int unk00;
    int unk04;
};
class hkStringFnDBB6
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};
struct hkNameDescDBB6
{
    const char* m_name;
    int m_len;
};
class hkLibDBB6;
class hkResourceDBB6 : public hkRefObjDBB6
{
  public:
    int m_08;

    hkResourceDBB6() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB6() throw();
};
class hkNodeDBB6 : public hkResourceDBB6
{
  public:
    hkStringDBB6 m_name;
    hkLibDBB6* m_pOwnerObject;

    hkNodeDBB6() throw()
    {}
    virtual ~hkNodeDBB6() throw();
};
class hkNodeRefDBB6
{
  public:
    hkNodeDBB6* m_node;
};
class hkLibDBB6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB6* m_pStringFunctions;

    int unk10[4];
    hkStringDBB6 m_name;

    hkNodeRefDBB6 FUN_00dbb620();
};
float FUN_00dbba10(void* pArg);
struct FUN_00d470f0_Obj
{
    unsigned char* GetLastNodeFlag(unsigned char* flag);
};
struct HKDBB50Handle
{
    void* m_pObject;
    int m_iClass;
};
struct FUN_00dbba50_Obj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    FUN_00d470f0_Obj* m_10;

    HKDBB50Handle* GetHandle(HKDBB50Handle* __restrict handle);
};
struct FUN_00d871a0
{
    int m_00;
    int m_04;
    FUN_00d871a0(void* pair, int x);
};
struct FUN_00dbbb60_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void* FUN_00dbbb60(int a, int b);
};
struct ComponentDescDBC5C0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
};
struct StreamDBC5C0;
struct AccessorDBC5C0
{
    AccessorDBC5C0(StreamDBC5C0* pkStream, int iIndex);
    int m_iA;
    int m_iB;
};
struct StreamDBC5C0
{
    int unk00;
};
struct VertexDataDBC5C0
{
    int unk00;
    int unk04;
    int unk08;
    StreamDBC5C0 m_kVertexStream;
    float GetFloat(int iIndex);
};

struct hkBoolDBB3
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

namespace hkDBB3 {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <class T> class ReferenceCountedPointer
{
  public:
    ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};

class hkDataClassNative
{
  public:
    virtual ~hkDataClassNative() throw();
};

class hkPointerMapDBB3
{
  public:
    ~hkPointerMapDBB3() throw()
    {
        reinterpret_cast<::FUN_00d877d0_class *>(this)->FreeBuffer();
    }

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
}

namespace FUN_00dbb3f0 {
class hkDataWorldNative : public hkDBB3::hkReferencedObject
{
  public:
    virtual ~hkDataWorldNative();

    hkDBB3::ReferenceCountedPointer<hkDBB3::hkReferencedObject> m_ppVirtualMethodTable;
    hkDBB3::ReferenceCountedPointer<hkDBB3::hkReferencedObject> m_infoReg;
    hkDBB3::hkPointerMapDBB3 m_kLookupMap;
};

// @fnv 0x00dbb3f0
hkDataWorldNative::~hkDataWorldNative()
{
    char valid;
    int it = reinterpret_cast<::hkSetD874 *>(&(m_kLookupMap))->FUN_00d87410();
    reinterpret_cast<::FUN_00d874b0_class *>(&(m_kLookupMap))->SetBoolFromThreshold(&valid, it);
    while (valid)
    {
        delete ((::hkDBB3::hkDataClassNative *)(reinterpret_cast<::FUN_00d87440_Class *>(&(m_kLookupMap))->FUN_00d87440(it)));
        it = reinterpret_cast<::SlotBitmap *>(&(m_kLookupMap))->FindNextUsedSlot(it);
        reinterpret_cast<::FUN_00d874b0_class *>(&(m_kLookupMap))->SetBoolFromThreshold(&valid, it);
    }
}
}
