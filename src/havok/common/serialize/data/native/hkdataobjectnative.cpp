
// src/havok/common/serialize/data/native/hkdataobjectnative.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/native/hkdataobjectnative.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dbb610
#include <new>
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/D871A0Buffer.h"
#include "fnv/decl/D87250Array.h"
#include "fnv/decl/D87370Obj.h"
#include "fnv/decl/DataObjectHandle.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00d46f00_s.h"
#include "fnv/decl/FUN_00d46f70_cls.h"
#include "fnv/decl/FUN_00d46f80_class.h"
#include "fnv/decl/FUN_00d46fe0_Class.h"
#include "fnv/decl/FUN_00d87200_cls.h"
#include "fnv/decl/FUN_00d87210_class.h"
#include "fnv/decl/FUN_00d87260_cls.h"
#include "fnv/decl/FUN_00d87280_class.h"
#include "fnv/decl/FUN_00d872a0_t.h"
#include "fnv/decl/FUN_00d872b0_class.h"
#include "fnv/decl/FUN_00d872d0_class.h"
#include "fnv/decl/FUN_00d872f0_class.h"
#include "fnv/decl/FUN_00d87360_class.h"
#include "fnv/decl/FUN_00d87790.h"
#include "fnv/decl/FUN_00dbb3f0__hkDataWorldNative.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/FnvCpu_FUN_00d470d0_CpuObject.h"
#include "fnv/decl/HkClassNode.h"
#include "fnv/decl/IntArrayView.h"
#include "fnv/decl/OwnerD4728.h"
#include "fnv/decl/OwnerD869.h"
#include "fnv/decl/Pair.h"
#include "fnv/decl/ReflectObj.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/StringMemberAccessor.h"
#include "fnv/decl/Struct_d86920.h"
#include "fnv/decl/fnv_00d47080__Container.h"
#include "fnv/decl/hkClassD47120.h"
#include "fnv/decl/hkClassEnumD470.h"
#include "fnv/decl/hkClassMember_FUN_00d86960.h"
#include "fnv/decl/hkObjectD878.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkStringMapD874.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d86000.h"
#include "fnv/symbols_00d87000.h"
#include "fnv/symbols_00dc1000.h"
#include "fnv/symbols_01268000.h"
void FUN_00dbb610(int* p)
{
    *p = 0;
}

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

// @fnv 0x00dbb490
void FUN_00dbb490_class::SetReferencedObject(hkReferencedObject* apObject)
{
    if (apObject)
        reinterpret_cast<::FUN_00c90510_class *>((apObject))->FUN_00c90510();
    if (m_8)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_8))->FUN_00c905b0();
    m_8 = apObject;
}

namespace fnv_00dbb4c0 {
struct hkReferencedObject
{
};
struct FUN_00dbb4c0_class
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    hkReferencedObject* m_pObject;
    void SetObject(hkReferencedObject* object);
};
// @fnv 0x00dbb4c0
void FUN_00dbb4c0_class::SetObject(hkReferencedObject* object)
{
    if (object)
        reinterpret_cast<::FUN_00c90510_class *>((object))->FUN_00c90510();
    if (m_pObject)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pObject))->FUN_00c905b0();
    m_pObject = object;
}
}  // namespace fnv_00dbb4c0

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

// @fnv 0x00dbbb20
int FUN_00dbbb20_Class::FUN_00dbbb20(int a)
{
    return (a < ((int)(reinterpret_cast<::FUN_00d46f00_s *>((((FUN_00d46f00_Class*)m_10)))->FUN_00d46f00()))) ? 1 : 0;
}

struct FUN_00dbbc50_Class
{
    int FUN_00dbbc50(int a);
};

// @fnv 0x00dbbc50
int FUN_00dbbc50_Class::FUN_00dbbc50(int a)
{
    return *(int*)(this + 0x10) + a * *(int*)(this + 0x18);
}

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
// @fnv 0x00dbbc60
int FUN_00dbbc60_Class::FUN_00dbbc60(int aiIndex)
{
    switch (m_1c)
    {
    case 0x1d:
        return *(int*)((char*)m_10 + m_18 * aiIndex);
    case 0x21:
        return (*(int*)((char*)m_10 + m_18 * aiIndex)) & 0xfffffffe;
    default:
        return 0;
    }
}

struct FUN_00d873b0_t
{
    int a;
    int b;
    FUN_00d873b0_t(int x, int y);
};
// @fnv 0x00d873b0
FUN_00d873b0_t::FUN_00d873b0_t(int aiFirst, int aiSecond)
{
    a = aiFirst;
    b = aiSecond;
}

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
// @fnv 0x00dbb920
const char* FUN_00dbb920_Class::FUN_00dbb920()
{
    return reinterpret_cast<::FnvClassNameNode *>((((D481D0Class*)*(int**)((int*)this + 3))))->FUN_00d46d40();
}

namespace fnv_00dbb940 {
struct D481D0Class
{
    char const* getName() const;
};

struct FUN_00d46d50_s
{
};

struct FUN_00dbb940_VirtualClass
{
    virtual void FUN_00dbb940_0() = 0;
    virtual void FUN_00dbb940_1() = 0;
    virtual void FUN_00dbb940_2() = 0;
    virtual void FUN_00dbb940_3() = 0;
    virtual void FUN_00dbb940_4() = 0;
    virtual void FUN_00dbb940_5() = 0;
    virtual void FUN_00dbb940_6() = 0;
    virtual void FUN_00dbb940_7() = 0;
    virtual void FUN_00dbb940_8() = 0;
    virtual int FUN_00dbb940_9(char const* name) = 0;
};

struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46d50_s* m_0C;
    FUN_00dbb940_VirtualClass* m_10;

    int FUN_00dbb940();
};

// @fnv 0x00dbb940
int hkDataClassNative::FUN_00dbb940()
{
    D481D0Class* parent = ((::fnv_00dbb940::D481D0Class *)(reinterpret_cast<::ReflectObj *>((m_0C))->FUN_00d46d50()));

    if (parent)
    {
        return m_10->FUN_00dbb940_9(reinterpret_cast<::FnvClassNameNode *>((void *)(parent))->FUN_00d46d40());
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00dbb940

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
// @fnv 0x00dbb9d0
int FUN_00dbb9d0_Class::FUN_00dbb9d0()
{
    return reinterpret_cast<::FUN_00d46f70_cls *>((((TypeNode*)this->m_0C)))->FUN_00d46f70();
}

namespace fnv_00dbba80 {
struct D481D0Class
{
    char const* getName() const;
};

struct FUN_00dbba80_Manager
{
    virtual void FUN_00dbba80_0() = 0;
    virtual void FUN_00dbba80_1() = 0;
    virtual void FUN_00dbba80_2() = 0;
    virtual void FUN_00dbba80_3() = 0;
    virtual void FUN_00dbba80_4() = 0;
    virtual void FUN_00dbba80_5() = 0;
    virtual void FUN_00dbba80_6() = 0;
    virtual void FUN_00dbba80_7() = 0;
    virtual void FUN_00dbba80_8() = 0;
    virtual D481D0Class* GetVariantValue(char const* name) = 0;
};

struct FUN_00dbba80_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    D481D0Class* m_10;
    FUN_00dbba80_Manager* m_14;

    D481D0Class* GetNamedClass();
};

// If m_10 is set, looks up its name through m_14 and returns the resulting D481D0Class; otherwise returns 0.
// @fnv 0x00dbba80
D481D0Class* FUN_00dbba80_Class::GetNamedClass()
{
    if (m_10)
        return m_14->GetVariantValue(reinterpret_cast<::FnvClassNameNode *>((void *)(m_10))->FUN_00d46d40());

    return 0;
}
}  // namespace fnv_00dbba80

namespace fnv_00dbbc20 {
struct D481D0Class
{
    virtual int FUN_00dbbc20_1();
    virtual int FUN_00dbbc20_2();
    virtual int FUN_00dbbc20_3();
    virtual int FUN_00dbbc20_4();
    virtual int FUN_00dbbc20_5();
    virtual int FUN_00dbbc20_6();
    virtual int FUN_00dbbc20_7();
    virtual int FUN_00dbbc20_8();
    virtual int FUN_00dbbc20_9();
    virtual int FUN_00dbbc20_10(char const* name);

    char const* getName() const;
};

struct FUN_00dbbc20_Class : D481D0Class
{
    int m_04;
    int m_08;
    D481D0Class* m_0C;
    void* m_10;
    int m_14;
    int m_18;
    int m_1C;
    D481D0Class* m_20;

    int FUN_00dbbc20();
};

// If m_20 is set, returns the result of calling FUN_00dbbc20_10 on m_0C with m_20's name; otherwise returns 0.
// @fnv 0x00dbbc20
int FUN_00dbbc20_Class::FUN_00dbbc20()
{
    if (m_20)
        return m_0C->FUN_00dbbc20_10(reinterpret_cast<::FnvClassNameNode *>((void *)(m_20))->FUN_00d46d40());

    return 0;
}
}  // namespace fnv_00dbbc20

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

// Reads the element at index from the array data pointer and returns it as an int, interpreting it according to the element type in m_1c.
// @fnv 0x00dbbcf0
int hkDataArrayNative::GetElementAsInt(int index)
{
    int* p = (int*)(m_10 + m_18 * index);
    switch (m_1c - 1)
    {
    case 0:
        return *(signed char*)p;
    case 1:
        return *(signed char*)p;
    case 2:
        return *(signed char*)p;
    case 3:
        return *(unsigned char*)p;
    case 4:
        return *(signed short*)p;
    case 5:
        return *(unsigned short*)p;
    case 6:
        return *(int*)p;
    case 7:
        return *(int*)p;
    case 8:
        return *(int*)p;
    case 9:
        return *(int*)p;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
        return 0;
    case 29:
        return *(int*)p;
    default:
        return 0;
    }
}

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

// @fnv 0x00dbbd70
__int64 FUN_00dbbd70_class::GetEntry64(int aiIndex)
{
    return *reinterpret_cast<__int64*>(m_10 + m_18 * aiIndex);
}

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

    void GetMemberInfo(Shape const*, int);
    void FUN_00dbbfa0(int, int);
};

// Retrieves the shape at index a from the container m_0c and passes it with b to GetMemberInfo.
// @fnv 0x00dbbfa0
void FUN_00dbbfa0_Class::FUN_00dbbfa0(int a, int b)
{
    GetMemberInfo(((const ::Shape *)(reinterpret_cast<::FUN_00d46f80_class *>((void *)(m_0c))->FUN_00d46f80(a))), b);
}

struct FUN_00d46f20_Class
{
};

struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46f20_Class* m_0c;

    void SetInvocationResult(int result);
    void InvokeMemberFunction(int a, int b);
};

// @fnv 0x00dbbfd0
void hkDataClassNative::InvokeMemberFunction(int aiArg1, int aiArg2)
{
    int result = ((int)(reinterpret_cast<::HkClassNode *>((m_0c))->FUN_00d46f20(aiArg1)));
    SetInvocationResult(result);
}

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


    FUN_00dbc640_class* FUN_00dbc640(int flags);
};

FUN_00dbc640_class* FUN_00dbc640_class::FUN_00dbc640(int flags)
{
    reinterpret_cast<::FUN_00dbb3f0::hkDataWorldNative *>((this))->FUN_00dbb3f0::hkDataWorldNative::~hkDataWorldNative();

    if (flags & 1)
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        router->m_10->FUN_00dbc640_2(this, this->m_04);
    }

    return this;
}

struct Inner
{
};

struct FUN_00dbb930_cls
{
    int unk00;
    int unk04;
    int unk08;
    Inner* m_pInner;
    void FUN_00dbb930();
};

// @fnv 0x00dbb930
void FUN_00dbb930_cls::FUN_00dbb930()
{
    reinterpret_cast<::hkClassD47120 *>((m_pInner))->FUN_00d47120();
}

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

// @fnv 0x00dbb9e0
void FUN_00dbb9e0_Class::FUN_00dbb9e0()
{
    reinterpret_cast<::fnv_00d47080::Container *>((unk0c))->FindIndexByName({});
}

struct FUN_00dbb9f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d46f00_Class* m_0C;
    void FUN_00dbb9f0();
};

// @fnv 0x00dbb9f0
void FUN_00dbb9f0_cls::FUN_00dbb9f0()
{
    reinterpret_cast<::FUN_00d46f00_s *>((m_0C))->FUN_00d46f00();
}

struct FUN_00dbba00_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int FUN_00dbba00(int param_1);
};

// @fnv 0x00dbba00
int FUN_00dbba00_Class::FUN_00dbba00(int param_1)
{

    FUN_00dbba00_Class* target = *reinterpret_cast<FUN_00dbba00_Class**>(reinterpret_cast<char*>(this) + 0xC);
    return reinterpret_cast<::hkClassEnumD470 *>((target))->FUN_00d47030((const char *)(param_1));
}

// @fnv 0x00dbba40
__int64 FUN_00dbba40(int)
{
    return 0;
}

// @fnv 0x00dc9520
int FUN_00dc9520(unsigned int arg0)
{
    return (int)(arg0 + 1u);
}

// @fnv 0x00dbb120
int FUN_00dbb120(int arg0)
{
    return 0;
}

// @fnv 0x00dbb130
int FUN_00dbb130(int a, int b)
{
    return 0;
}

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
// Initializes the object's fields, resets m_10, and stores referenced objects obtained from DAT_01268b08's vf14 and vf10.
// @fnv 0x00dbb360
FUN_00dbb360_Class* FUN_00dbb360_Class::Initialize()
{
    FUN_00d87790_Result result;
    m_06 = 1;
    result.value = 0;
    m_00 = (int)DAT_010d6518;
    *reinterpret_cast<hkReferencedObject* volatile*>(&m_08) = 0;
    *reinterpret_cast<hkReferencedObject* volatile*>(&m_0C) = 0;
    new ((void *)&(m_10)) ::FUN_00d87790((*(int *)&(const ::FUN_00d87790_Result &)(result)));
    m_24 = 0;
    m_20 = 0;
    FUN_00c90510_Obj* p = (*reinterpret_cast<::FUN_00dbb360_Global * *>(&::DAT_01268b08))->vf14();
    if (p)
        reinterpret_cast<::FUN_00c90510_class *>((p))->FUN_00c90510();
    if (m_0C)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_0C))->FUN_00c905b0();
    m_0C = p;
    p = (*reinterpret_cast<::FUN_00dbb360_Global * *>(&::DAT_01268b08))->vf10();
    if (p)
        reinterpret_cast<::FUN_00c90510_class *>((p))->FUN_00c90510();
    if (m_08)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_08))->FUN_00c905b0();
    m_08 = p;
    return this;
}

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

// @fnv 0x00dbb5a0
hkNodeRefDBB5 hkLibDBB5::CreateNode(const hkNameDescDBB5& aNameDesc)
{
    hkNodeDBB5* node = new hkNodeDBB5();
    int len = aNameDesc.m_len;
    if (!len)
        len = m_pStringFunctions->strLen(aNameDesc.m_name);
    new ((void *)&(node->m_name)) ::FUN_00d873b0_t((int)(aNameDesc.m_name), len);
    node->m_pOwnerObject = this;
    hkNodeRefDBB5 r;
    reinterpret_cast<::DataObjectHandle *>(&(r))->FUN_00dba760((::RefObj *)(node));
    return r;
}

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
    const char* FUN_00d46d40() throw();
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

// Stores pvObject and resolves its class through the world/vtable registry, reporting an error and clearing pvObject if the class is not registered.
// @fnv 0x00dbb730
void hkDataObjectNativeDBB7::SetContents(void* pvObject, hkClassDBB7& kClass)
{
    m_pvObject = pvObject;
    void* pvClass;
    if (kClass.GetLastNodeFlag().m_bValue)
    {
        hkDataWorldNativeDBB7* pkWorld = m_pkWorld;
        hkClassDBB7* pkClass = m_pkVtableRegistry->GetClassFromVirtualInstance(pvObject);
        pvClass = !pkClass ? 0 : pkWorld->GetClassFromName(reinterpret_cast<::FnvClassNameNode *>((pkClass))->FUN_00d46d40());
    }
    else
        pvClass = getWorld()->GetClassFromName(reinterpret_cast<::FnvClassNameNode *>(&(kClass))->FUN_00d46d40());
    m_pkClass = pvClass;
    if (!m_pkClass)
    {
        unsigned int auiReportBuf[0x80];
        FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
        reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&(kReportStream))->FUN_00cc01c0("Cannot set contents with object at 0x")))
            .FUN_00cc0120(pvObject)))->FUN_00cc01c0(". Class '")))))->FUN_00cc01c0(reinterpret_cast<::FnvClassNameNode *>(&(kClass))->FUN_00d46d40())))))->FUN_00cc01c0("' is not registered in the hkDataWorldNative. Ignore it.");
        (*reinterpret_cast<::hkErrorDBB7 * *>(&::DAT_01268360))->message(1, 0x1800473b, (char*)auiReportBuf, ".\\Data\\Native\\hkDataObjectNative.cpp", 0x2fc);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(kReportStream))->FUN_00cc00e0::~FUN_00cc00e0();
        m_pvObject = 0;
    }
}


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

// @fnv 0x00dbb970
hkBoolDBB9 hkNamedNodeDBB9::FUN_00dbb970(const hkNamedNodeDBB9* pkNode) const
{
    while (pkNode)
    {
        if (::fnv_00cb0fa0::FUN_00cb0fa0((const char *)((int)pkNode->getName()), (const char *)((int)getName())) == 0)
            return true;
        pkNode = pkNode->getNext();
    }
    return false;
}

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

// @fnv 0x00dbba20
hkHalf MakeZeroHalf(int a)
{
    return hkHalf(0.0f);
}

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

// Constructs and returns an hkRefDBBB holding this owner and the value from V8(iKey).
// @fnv 0x00dbbb40
hkRefDBBB hkOwnerDBBB::MakeRef(int iKey)
{
    return hkRefDBBB(this, V8(iKey));
}

struct FUN_00dbbca0_class
{
    int m_00, m_04, m_08, m_0c;
    char* m_10;
    int m_14, m_18, m_1c;
    float FUN_00dbbca0(int index);
};
// Reads a value at m_10 + m_18*index, as float when m_1c==11, as sign-extended short shifted left 16 when m_1c==32, else 0.0f.
// @fnv 0x00dbbca0
float FUN_00dbbca0_class::FUN_00dbbca0(int index)
{
    volatile float& fValue = *reinterpret_cast<volatile float*>(&index);
    if (m_1c != 11)
    {
        if (m_1c != 32)
        {
            fValue = 0.0f;
            return fValue;
        }
        index = int(*reinterpret_cast<short*>(m_10 + m_18 * index)) << 16;
        return fValue;
    }
    fValue = *reinterpret_cast<float*>(m_10 + m_18 * index);
    return fValue;
}

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

// @fnv 0x00dbbd90
FUN_00dbbb90* hkDataObjectNativeDBBD::GetElement(int iIndex)
{
    void* pvAddr = m_data + m_iElementIndex * iIndex;
    if (m_iFlags)
    {
        int iStride = ((::hkClassMemberTypeDBBD *)(::FUN_00d868a0(m_type)))->m_iElementCount;
        return new FUN_00dbbb90(m_pOwningWorld, pvAddr, m_iFlags, iStride, m_type, m_class, 0);
    }
    hkArrayBaseDBBD* pkArray = static_cast<hkArrayBaseDBBD*>(pvAddr);
    return new FUN_00dbbb90(m_pOwningWorld, pkArray->m_data, pkArray->m_iElementCount, 0, 0, 0, 0);
}

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

// @fnv 0x00dbbe30
int FUN_00dbbe30_cls::GetValueForKey(int iKey)
{
    return *((int *)(reinterpret_cast<::HkClassNode *>((m_map))->FUN_00d46f20(iKey)));
}

namespace fnv_00dbbe50 {
class hkBaseDBBE
{
  public:
    virtual ~hkBaseDBBE() throw()
    {}
};

class hkMemoryAllocatorXdbbe50
{
  public:
    virtual ~hkMemoryAllocatorXdbbe50() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXdbbe50
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXdbbe50* m_pStreamAllocator;

    hkMemoryAllocatorXdbbe50& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXdbbe50& __cdecl FUN_00c85750() throw();

class hkObjdbbe50 : public hkBaseDBBE
{
  public:
    hkObjdbbe50* FUN_00dbbe50(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObjdbbe50*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

// Destroys the base object and, when bit 0 of uiFlags is set, frees this object through the heap allocator.
// @fnv 0x00dbbe50
hkObjdbbe50* hkObjdbbe50::FUN_00dbbe50(unsigned int uiFlags) throw()
{
    this->hkBaseDBBE::~hkBaseDBBE();
    if (uiFlags & 1)
        hkObjdbbe50::operator delete(this);
    return this;
}
}  // namespace fnv_00dbbe50

namespace fnv_00dbbe80 {
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
};

struct hkClassMemberDBBE
{
    const char* m_name;
    int m_class;
    int m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;

    bool flagsAllAreSet(unsigned short usMask) const
    {
        return (m_flags & usMask) == usMask;
    }
};

struct hkDataWorldDBBE
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};

struct FUN_00d871a0
{
    void* m_object;
    const void* m_pObjectTypeInfo;
    FUN_00d871a0(void* pvObject, const char* pcMember) throw();
};

struct hkMemberInfoDBBE
{
    const char* m_name;
    const void* m_pOwnerObject;
    int m_type;
    void* m_valueClass;
    int m_arrayCount;
};

extern const char* DAT_011b7958;

struct hkDataClassNativeDBBE
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkDataWorldDBBE* m_pOwningWorld;

    void GetMemberInfo(const hkClassMemberDBBE& kMember, hkMemberInfoDBBE& kInfo) const throw();
};

// Fills kInfo from kMember: copies the name, sets the owner, and resolves type, value class and array count, using the world to look up the class name.
// @fnv 0x00dbbe80
void hkDataClassNativeDBBE::GetMemberInfo(const hkClassMemberDBBE& kMember, hkMemberInfoDBBE& kInfo) const throw()
{
    kInfo.m_name = kMember.m_name;
    kInfo.m_pOwnerObject = this;
    if (kMember.flagsAllAreSet(0x400))
    {
        kInfo.m_type = 0;
        kInfo.m_valueClass = 0;
        kInfo.m_arrayCount = 0;
        return;
    }
    int iSubType = kMember.m_eSubtype;
    int iType = kMember.m_type;
    kInfo.m_type = ::GetShapeTypeFlags(iType, iSubType, (::DC1C50Collection *)(::fnv_00dbbe80::FUN_00d46d40_s *)(((::fnv_00dbbe80::FUN_00d46d40_s *)(reinterpret_cast<::Struct_d86920 *>((void *)&(kMember))->FUN_00d86920()))), reinterpret_cast<::OwnerD869 *>((void *)&(kMember))->FUN_00d86940());
    if (((::fnv_00dbbe80::FUN_00d46d40_s *)(reinterpret_cast<::Struct_d86920 *>((void *)&(kMember))->FUN_00d86920())))
    {
        void* pvAttr = ((void *)(reinterpret_cast<::hkClassMember_FUN_00d86960 *>((void *)&(kMember))->FUN_00d86960(DAT_011b7958)));
        if (pvAttr)
        {
            FUN_00d871a0 kAccess(pvAttr, "typeName");
            kInfo.m_valueClass = m_pOwningWorld->GetClassFromName(*((const char **)(::FUN_00d87220((char *)&(kAccess), 0, {}))));
        }
        else
        {
            kInfo.m_valueClass = m_pOwningWorld->GetClassFromName(reinterpret_cast<::FnvClassNameNode *>((((::fnv_00dbbe80::FUN_00d46d40_s *)(reinterpret_cast<::Struct_d86920 *>((void *)&(kMember))->FUN_00d86920()))))->FUN_00d46d40());
        }
    }
    else
    {
        kInfo.m_valueClass = 0;
    }
    kInfo.m_arrayCount = reinterpret_cast<::OwnerD869 *>((void *)&(kMember))->FUN_00d86940();
}
}  // namespace fnv_00dbbe80

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

// Builds an hkVariantDBC3 from m_data and name, then returns the member's pointer value or its flags value with bit 0 cleared, or 0 for other types.
// @fnv 0x00dbc310
unsigned int hkObjDBC3::GetMemberValue(void* name)
{
    hkVariantDBC3 v(m_data, name);
    switch (((::hkClassMemberDBC3 *)(reinterpret_cast<::D87370Obj *>(&(v))->FUN_00d87370()))->getType())
    {
    case TYPE_POINTER:
        return *((unsigned int *)(::FUN_00d87220((char *)&(v), 0, {})));
    case TYPE_FLAGS:
        return *((unsigned int *)(reinterpret_cast<::StringMemberAccessor *>(&(v))->FUN_00d87230(0))) & ~1u;
    }
    return 0;
}

namespace fnv_00dbc370 {
class hkClassMemberDBC3
{
  public:
    enum Type
    {
        TYPE_VOID,
        TYPE_BOOL,
        TYPE_CHAR,
        TYPE_INT8,
        TYPE_UINT8,
        TYPE_INT16,
        TYPE_UINT16,
        TYPE_INT32,
        TYPE_UINT32,
        TYPE_INT64,
        TYPE_UINT64,
        TYPE_REAL,
        TYPE_VECTOR4,
        TYPE_QUATERNION,
        TYPE_MATRIX3,
        TYPE_ROTATION,
        TYPE_QSTRANSFORM,
        TYPE_MATRIX4,
        TYPE_TRANSFORM,
        TYPE_ZERO,
        TYPE_POINTER,
        TYPE_FUNCTIONPOINTER,
        TYPE_ARRAY,
        TYPE_INPLACEARRAY,
        TYPE_ENUM,
        TYPE_STRUCT,
        TYPE_SIMPLEARRAY,
        TYPE_HOMOGENEOUSARRAY,
        TYPE_VARIANT,
        TYPE_CSTRING,
        TYPE_ULONG,
        TYPE_FLAGS
    };
    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_pCustomAttributes;

    Type getType() const
    {
        return (Type)m_type;
    }
    Type getSubType() const
    {
        return (Type)m_eSubtype;
    }
};

struct hkVariantDBC3
{
    void* m_object;
    const void* m_class;
};

class hkClassMemberAccessorDBC3
{
  public:
    void* m_pTargetObject;
    const hkClassMemberDBC3* m_kMemberDescriptor;

    void FUN_00d871a0(hkVariantDBC3& kObject, const hkClassMemberDBC3* pkMember) throw();
    hkClassMemberAccessorDBC3(hkVariantDBC3& kObject, const hkClassMemberDBC3* pkMember)
    {
        reinterpret_cast<::D871A0Buffer *>(this)->FUN_00d871a0((const ::D871A0Array &)(kObject), (int)(pkMember));
    }

    const hkClassMemberDBC3& FUN_00d87370() const throw();
};

class hkDataObjectNativeDBC3
{
  public:
    void* m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    hkVariantDBC3 m_object;

    __int64 GetMemberValueAsInt64(const hkClassMemberDBC3* pkHandle) throw();
};

// @fnv 0x00dbc370
__int64 hkDataObjectNativeDBC3::GetMemberValueAsInt64(const hkClassMemberDBC3* pkHandle) throw()
{
    hkClassMemberAccessorDBC3 kAccessor(m_object, pkHandle);
    const hkClassMemberDBC3& kMember = kAccessor.FUN_00d87370();
    hkClassMemberDBC3::Type eType = kMember.getType();
    while (1)
    {
        switch (eType)
        {
        case hkClassMemberDBC3::TYPE_BOOL:
        case hkClassMemberDBC3::TYPE_CHAR:
        case hkClassMemberDBC3::TYPE_INT8:
            return ((signed char)(reinterpret_cast<::CpuObject *>(&(kAccessor))->FUN_00d872e0(0)));
        case hkClassMemberDBC3::TYPE_UINT8:
            return ((unsigned char)(reinterpret_cast<::FUN_00d872f0_class *>(&(kAccessor))->FUN_00d872f0(0)));
        case hkClassMemberDBC3::TYPE_INT16:
            return ((short)(::FUN_00d872c0((int *)&(kAccessor), 0, {})));
        case hkClassMemberDBC3::TYPE_UINT16:
            return ((unsigned short)(reinterpret_cast<::FUN_00d872d0_class *>(&(kAccessor))->FUN_00d872d0(0)));
        case hkClassMemberDBC3::TYPE_INT32:
            return ((int)(reinterpret_cast<::IntArrayView *>(&(kAccessor))->FUN_00d87270(0)));
        case hkClassMemberDBC3::TYPE_UINT32:
            return ((unsigned int)(reinterpret_cast<::FUN_00d87280_class *>(&(kAccessor))->FUN_00d87280(0)));
        case hkClassMemberDBC3::TYPE_INT64:
            return ((long long)(::FUN_00d87290((const void *)&(kAccessor), 0, {})));
        case hkClassMemberDBC3::TYPE_UINT64:
            return ((unsigned long long)(reinterpret_cast<::FUN_00d872a0_t *>(&(kAccessor))->FUN_00d872a0(0)));
        case hkClassMemberDBC3::TYPE_ULONG:
            return ((unsigned long)(reinterpret_cast<::FUN_00d872b0_class *>(&(kAccessor))->FUN_00d872b0(0)));
        case hkClassMemberDBC3::TYPE_ENUM:
        case hkClassMemberDBC3::TYPE_FLAGS:
            eType = kMember.getSubType();
            break;
        default:
            return 0;
        }
    }
}
}  // namespace fnv_00dbc370

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

// Gets a heap, conditionally frees m_0C using a size derived from m_14, then resets m_0C and m_14.
// @fnv 0x00dba490
void FUN_00dba490_class::FUN_00dba490()
{
    FUN_00c85750_Result* result = (FUN_00c85750_Result*)((FUN_00c85750_Class*)this)->FUN_00c85750();
    FUN_00dba490_heap* heap = result->m_10;
    int value = m_14;
    m_10 = 0;
    if ((value & 0x80000000) == 0)
    {
        heap->h_freeBlock(m_0C, (value & 0x3fffffff) * 16);
    }
    m_0C = 0;
    m_14 = (int)0x80000000;
}

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
    void FUN_00d873d0(const hkStringDBB6& other) throw();
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

// Allocates a new hkNodeDBB6, copies m_name into it, sets m_pOwnerObject to this, and returns it wrapped in an hkNodeRefDBB6.
// @fnv 0x00dbb620
hkNodeRefDBB6 hkLibDBB6::FUN_00dbb620()
{
    hkNodeDBB6* node = new hkNodeDBB6();
    reinterpret_cast<::Pair *>(&(node->m_name))->FUN_00d873d0((const ::Pair &)(m_name));
    node->m_pOwnerObject = this;
    hkNodeRefDBB6 r;
    reinterpret_cast<::DataObjectHandle *>(&(r))->FUN_00dba760((::RefObj *)(node));
    return r;
}

// Returns 0.0f.
// @fnv 0x00dbba10
float FUN_00dbba10(void* pArg)
{
    return 0.0f;
}

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

// @fnv 0x00dbba50
HKDBB50Handle* FUN_00dbba50_Obj::GetHandle(HKDBB50Handle* __restrict handle)
{
    int first = m_0C;
    unsigned char flag;
    handle->m_pObject = (void*)first;
    FUN_00d470f0_Obj* reg = m_10;
    unsigned char* text = reg->GetLastNodeFlag(&flag);
    handle->m_iClass = ((*text != 0) - 1) & (int)(unsigned int)reg;
    return handle;
}

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

// Constructs a FUN_00d871a0 with m_0c and a, then returns the result of FUN_00d87200.
// @fnv 0x00dbbb60
void* FUN_00dbbb60_cls::FUN_00dbbb60(int a, int aiUnused)
{
    FUN_00d871a0 t(&this->m_0c, a);
    return reinterpret_cast<::FUN_00d87200_cls *>(&(t))->FUN_00d87200();
}

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

// Reads component 0 at iIndex as float bits for types 0xb or 0x20; returns 0.0f otherwise.
// @fnv 0x00dbc5c0
float VertexDataDBC5C0::GetFloat(int iIndex)
{
    AccessorDBC5C0 kAccessor(&m_kVertexStream, iIndex);
    union
    {
        float f;
        int i;
    } uValue;
    int iType = ((const ::ComponentDescDBC5C0 *)(reinterpret_cast<::D87370Obj *>(&(kAccessor))->FUN_00d87370()))->m_type;
    switch (iType)
    {
    case 0xb:
        uValue.f = *((const float *)&(reinterpret_cast<::D87250Array *>(&(kAccessor))->FUN_00d87250(0)));
        break;
    case 0x20:
        uValue.i = *((const short *)(reinterpret_cast<::FUN_00d87260_cls *>(&(kAccessor))->FUN_00d87260(0))) << 16;
        break;
    default:
        uValue.f = 0.0f;
        break;
    }
    return uValue.f;
}

extern const char str_010a5824[];
struct WriterC12
{
    virtual void write(const char* s, int len) throw();
};
static __declspec(noinline) void FUN_00cc0080(WriterC12* pkWriter, const char* pcString)
{
    if (pcString == 0)
        pkWriter->write("(null)", 6);
    else
        pkWriter->write(pcString, ::fnv_00cb10d0::FUN_00cb10d0(pcString));
}
// @fnv 0x00cc0120
hkOstreamDBB7& hkOstreamDBB7::FUN_00cc0120(const void* pvPointer) throw()
{
    int buffer[2506];
    ::Vsnprintf((char*)buffer, 0x2728u, str_010a5824, pvPointer);
    FUN_00cc0080((WriterC12*)m_uiLogicalSize, (const char*)buffer);
    return *this;
}

namespace dbb {
struct Pair
{
    int a;
    int b;
};
}
void DbbExtern(void*);

struct DbbOwner
{
    int unk00;
    int unk04;
    void FUN_00dbb4f0(int a, int b);
};

static __declspec(noinline) void FUN_00dbb260(dbb::Pair* p, DbbOwner* self)
{
    for (int i = 0; i < self->unk00; i++)
    {
        DbbExtern(self);
        p->a += self->unk04 + i;
        p->b -= i;
    }
}

// Stores the two input integers into a dbb::Pair and passes it to FUN_00dbb260 for in-place modification.
// @fnv 0x00dbb4f0
void DbbOwner::FUN_00dbb4f0(int aiFirst, int aiSecond)
{
    dbb::Pair p;
    p.a = aiFirst;
    p.b = aiSecond;
    FUN_00dbb260(&p, this);
}

struct Input680
{
    void* FUN_00dba680();
};
struct Size680
{
};
struct Dispatch680
{
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void RunFourthVirtual();
    virtual void* v4(void* a);
    virtual void q5();
    virtual void RunSeventhVirtualOperation();
    virtual void* v7(void* a);
    virtual void q8();
    virtual void* q9(const char* s);
};
struct Manager680
{
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual Dispatch680* RunFourthVirtual();
};
typedef void(__cdecl* Callback680)(void*, int);
struct CallbackEntry680
{
    void* object;
    Callback680 callback;
};
struct Pair680
{
    void* a;
    FUN_00d46d40_s* b;
};
struct Resolved680
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d46d40_s* descriptor;
};
struct Node680
{
    void* vtable;
    unsigned short size;
    unsigned short refs;
    int unk08;
    hkStringDBB6 name;
    Dispatch680* owner;
};
extern const char DAT_010d64bc[], DAT_010d64d0[], DAT_010d64dc[], DAT_010d6394[];
extern int DAT_010d6334;

static __declspec(noinline) Node680* FUN_00dbb260(Pair680* p, Dispatch680* o)
{
    if (p->b)
    {
        Resolved680* r = (Resolved680*)o->q9(reinterpret_cast<::FnvClassNameNode *>((p->b))->FUN_00d46d40());
        if (r)
        {
            p->b = r->descriptor;
        }
        else
        {
            char buffer[512];
            FUN_00cb1600 stream(buffer, 512);
            reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&(stream))->FUN_00cc01c0(DAT_010d64bc)))
                .FUN_00cc0120(p->a)))->FUN_00cc01c0(DAT_010d64d0)))))->FUN_00cc01c0(reinterpret_cast<::FnvClassNameNode *>((p->b))->FUN_00d46d40())))))->FUN_00cc01c0(DAT_010d64dc);
            (*reinterpret_cast<::hkErrorDBB7 * *>(&::DAT_01268360))->message(1, 0x1800473a, buffer, DAT_010d6394, 0x2c7);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(stream))->FUN_00cc00e0::~FUN_00cc00e0();
            p->a = 0;
            p->b = 0;
        }
    }
    Node680* e = (Node680*)hkRouterDBB6::FUN_00c85750().heap().AllocateMemoryBlock(24);
    e->refs = 0;
    e->unk08 = 0;
    e->size = 24;
    e->vtable = &DAT_010d6334;
    reinterpret_cast<::Pair *>(&(e->name))->FUN_00d873d0((const ::Pair &)(*(hkStringDBB6*)p));
    e->owner = o;
    return e;
}
struct Owner680
{
    int unk00;
    int unk04;
    Dispatch680* dispatch;
    void FUN_00dbb680(Input680* input);
};
struct RawDispatch680;
typedef void*(* DispatchFn680)(RawDispatch680*, void*);
struct DispatchTable680
{
    DispatchFn680 q0, q1, q2, RunFourthVirtual, v4, q5, RunSeventhVirtualOperation, v7;
};
struct RawDispatch680
{
    DispatchTable680* table;
};
// Allocates a block using the first dispatch result's size, invokes an available callback, then passes the block and second result to FUN_00dbb260.
// @fnv 0x00dbb680
void Owner680::FUN_00dbb680(Input680* input)
{
    RawDispatch680* pRawDispatch = (RawDispatch680*)dispatch;
    Pair680 p;
    DispatchFn680* firstSlot = &pRawDispatch->table->v4;
    void* r2 = (*firstSlot)(pRawDispatch, input->FUN_00dba680());
    int size = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((((Size680*)r2)))->FUN_00d470d0();
    p.a = hkRouterDBB6::FUN_00c85750().heap().AllocateMemoryBlock(size);
    p.b = (FUN_00d46d40_s*)r2;
    if (p.a)
    {
        ::FUN_00cb1280(p.a, 0, reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((((Size680*)r2)))->FUN_00d470d0());
        RawDispatch680* d = (RawDispatch680*)((Manager680*)(*reinterpret_cast<::FUN_00dbb360_Global * *>(&::DAT_01268b08)))->RunFourthVirtual();
        DispatchFn680* secondSlot = &d->table->v7;
        CallbackEntry680* pCallbackEntry = (CallbackEntry680*)(*secondSlot)(d, input->FUN_00dba680());
        if (pCallbackEntry && pCallbackEntry->callback)
            pCallbackEntry->callback(p.a, 0);
    }
    FUN_00dbb260(&p, (Dispatch680*)this);
}


struct Allocator_s
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void free(void* p, int nbytes) throw();
};

template <typename T> __forceinline void constructWithCopyRange(T* p, int n, const T& t) throw()
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(int(0x80000000))
    {}

    ~hkArray() throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        void* alloc = router->m_10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & int(0x80000000)) == 0)
        {
            ((Allocator_s*)alloc)->free(m_data, (cap & 0x3FFFFFFF) * sizeof(T));
        }
    }

    T& operator[](int i) throw()
    {
        return m_data[i];
    }

    void AddBack(const T& item) throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        {
            ::ResizeAudioStream((::AudioAllocator *)(router->m_10), (::AudioStream *)(void *)(this), sizeof(T));
        }
        constructWithCopyRange(m_data + m_iElementCount, 1, item);
        m_iElementCount++;
    }
};

// local members list (same layout/semantics as hkArray, used for the loop scan)
template <typename T> struct MemberArrLcl
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    MemberArrLcl() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(int(0x80000000))
    {}

    ~MemberArrLcl() throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        void* alloc = router->m_10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & int(0x80000000)) == 0)
        {
            ((Allocator_s*)alloc)->free(m_data, (cap & 0x3FFFFFFF) * sizeof(T));
        }
    }

    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
};

struct TargetClass
{
    virtual void t0() throw();
    virtual void t1() throw();
    virtual void t2() throw();
    virtual void t3() throw();
    virtual void t4() throw();
    virtual void getDeclaredMembers(MemberArrLcl<FUN_00d46d40_s*>* out) throw();
public:
    bool *FUN_00d871e0(bool *);
};
// @fnv 0x00dbbae0
int FUN_00dbbae0_Class::FUN_00dbbae0(int iKey)
{
    FUN_00d871a0_Data lookup;
    reinterpret_cast<::D871A0Buffer *>(&(lookup))->FUN_00d871a0((*(const ::D871A0Array *)(&unk0C)), iKey);
    return *((const char *)(reinterpret_cast<::TargetClass *>(&(lookup))->FUN_00d871e0((bool *)(&iKey)))) != 0;
}

struct FUN_00dbb840_class
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void v8() throw();
    virtual FUN_00d46d40_s* getMemberHandle(const char* name) throw();

    int unk04;
    TargetClass* m_class;

    void FUN_00dbb840(hkArray<FUN_00d46d40_s*>& out) throw();
};

// @fnv 0x00dbb840
void FUN_00dbb840_class::FUN_00dbb840(hkArray<FUN_00d46d40_s*>& out) throw()
{
    int i = 0;
    TargetClass* cls = this->m_class;
    if (!cls)
        return;
    MemberArrLcl<FUN_00d46d40_s*> declaredMembers;
    cls->getDeclaredMembers(&declaredMembers);
    for (; i < declaredMembers.GetLogicalSize(); ++i)
    {
        if (*(char*)((void *)(reinterpret_cast<::OwnerD4728 *>((declaredMembers[i]))->FUN_00d47280())) & 1)
        {
            continue;
        }
        FUN_00d46d40_s* handle = this->getMemberHandle(reinterpret_cast<::FnvClassNameNode *>((declaredMembers[i]))->FUN_00d46d40());
        out.AddBack(handle);
    }
}

struct MemberDBC0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iFlags;
    unsigned short m_flags;
    unsigned short m_offset;
};
struct ClassDBC0
{
};
struct ObjectDBC0
{
    int unk00;
    int unk04;
    int unk08;
    int m_pOwningWorld;
    char* m_data;
    int m_iElementCount;
    int m_iElementIndex;
    int unk1c;
    ClassDBC0* m_class;
    FUN_00dbbb90* FUN_00dbc0c0(int index);
};
// Looks up a member by index, computes a type code, and constructs a new FUN_00dbbb90 from selected fields.
// @fnv 0x00dbc0c0
FUN_00dbbb90* ObjectDBC0::FUN_00dbc0c0(int index)
{
    MemberDBC0* member = ((::MemberDBC0 *)(reinterpret_cast<::FUN_00d46fe0_Class *>((m_class))->FUN_00d46fe0((const int *)(index))));
    char* data = m_data + member->m_offset;
    unsigned char type = member->m_type;
    index = type == 0x18 || type == 0x1f ? (int)member->m_eSubtype : (int)type;
    return new FUN_00dbbb90(m_pOwningWorld, data, m_iElementCount, m_iElementIndex, index, reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920(),
                            reinterpret_cast<::OwnerD869 *>((member))->FUN_00d86940());
}

struct S00dbc150_ClassDef
{
};

struct S00dbc150_Member
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_carraySize;

};

struct S00dbc150_Pair
{
    void* m_data;
    S00dbc150_Member* m_kMemberDescriptor;

    S00dbc150_Pair(void* obj, const char* name)
    {
        reinterpret_cast<::D871A0Buffer *>(this)->FUN_00d871a0((*(const ::D871A0Array *)(obj)), (int)(name));
    }
    void FUN_00d871a0(void* obj, const char* name);
};

struct S00dbc150_HomArray
{
    S00dbc150_ClassDef* m_pObjectTypeInfo;
    void* m_data;
    int m_iElementCount;
};

struct S00dbc150_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_14;

    FUN_00dbbb90* FUN_00dbc150(const char* name);
};

// Resolves a named member on this object, determines its type, tuple size, and class, and returns a new FUN_00dbbb90 descriptor.
// @fnv 0x00dbc150
FUN_00dbbb90* S00dbc150_Obj::FUN_00dbc150(const char* name)
{
    S00dbc150_Pair pair(&this->unk0c, name);
    S00dbc150_Member* member = ((::S00dbc150_Member *)(reinterpret_cast<::D87370Obj *>(&(pair))->FUN_00d87370()));
    hkArrayBaseDBBD out;
    int tupleSize;
    int subType;
    S00dbc150_ClassDef* classDef;

    switch (member->m_type)
    {
    case 27: {
        S00dbc150_HomArray* pArray = (S00dbc150_HomArray*)reinterpret_cast<::FUN_00d87200_cls *>(&(pair))->FUN_00d87200();
        out.m_data = pArray->m_data;
        out.m_iElementCount = pArray->m_iElementCount;
        S00dbc150_ClassDef* cls = ((S00dbc150_HomArray*)reinterpret_cast<::FUN_00d87200_cls *>(&(pair))->FUN_00d87200())->m_pObjectTypeInfo;
        classDef = cls;
        if (cls)
        {
            tupleSize = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((cls))->FUN_00d470d0();
            subType = 25;
        }
        else
        {
            tupleSize = 0;
            goto ZERO_SUBTYPE;
        }
        break;
    }
    case 22:
    case 26: {
        hkArrayBaseDBBD* pArray = (hkArrayBaseDBBD*)reinterpret_cast<::FUN_00d87200_cls *>(&(pair))->FUN_00d87200();
        out.m_data = pArray->m_data;
        out.m_iElementCount = pArray->m_iElementCount;
        S00dbc150_ClassDef* cls = ((::S00dbc150_ClassDef *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()));
        classDef = cls;
        subType = member->m_eSubtype;
        hkClassMemberTypeDBBD* pTypeInfo = ((::hkClassMemberTypeDBBD *)(::FUN_00d868a0(subType)));
        tupleSize = pTypeInfo->m_iElementCount;
        if (!subType)
        {
            return new FUN_00dbbb90(this->m_14, 0, 0, 0, 0, 0, 0);
        }
        if (tupleSize == -1)
        {
            tupleSize = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((cls))->FUN_00d470d0();
        }
        break;
    }
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 20:
    case 25:
    case 30:
    case 32: {
        out.m_data = reinterpret_cast<::FUN_00d87200_cls *>(&(pair))->FUN_00d87200();
        int c = reinterpret_cast<::OwnerD869 *>((((::S00dbc150_Member *)(reinterpret_cast<::D87370Obj *>(&(pair))->FUN_00d87370()))))->FUN_00d86940();
        subType = member->m_type;
        out.m_iElementCount = c;
        S00dbc150_ClassDef* cls = ((::S00dbc150_ClassDef *)(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920()));
        classDef = cls;
        if (subType == 25)
        {
            tupleSize = reinterpret_cast<::FnvCpu_FUN_00d470d0_CpuObject *>((cls))->FUN_00d470d0();
        }
        else
        {
            tupleSize = ((::hkClassMemberTypeDBBD *)(::FUN_00d868a0(subType)))->m_iElementCount;
        }
        break;
    }
    default:
        out.m_data = 0;
        out.m_iElementCount = 0;
        classDef = 0;
        tupleSize = 0;
    ZERO_SUBTYPE:
        subType = 0;
        break;
    }

    return new FUN_00dbbb90(this->m_14, out.m_data, out.m_iElementCount, tupleSize, subType, (int)classDef, 0);
}

extern int DAT_010d642c[];

struct S00dbbb90_Obj
{
    int* m_00;
    unsigned short unk04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    S00dbbb90_Obj* FUN_00dbbb90(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

// Initializes S00dbbb90_Obj fields from a1-a7, sets m_00 to DAT_010d642c, and computes m_24 from GetShapeTypeFlags.
// @fnv 0x00dbbb90
S00dbbb90_Obj* S00dbbb90_Obj::FUN_00dbbb90(int ai0c, int ai10, int ai14, int ai18, int ai1c, int ai20, int ai28)
{
    m_06 = 0;
    m_08 = 0;
    m_0c = ai0c;
    m_10 = ai10;
    m_14 = ai14;
    m_18 = ai18;
    m_00 = DAT_010d642c;
    m_1c = ai1c;
    m_20 = ai20;
    m_28 = ai28;
    int r = ::GetShapeTypeFlags(0x16, ai1c, (::DC1C50Collection *)(ai20), ai28);
    m_24 = (r > 0x10) ? (r - 0x10) : 0x10;
    return this;
}

extern "C" void _ReadWriteBarrier();
struct VariantC4D0
{
    int m_00;
    int m_04;
    void FUN_00d871a0(void* obj, int name);
};
struct MemberC4D0
{
    int m_00;
    int m_04;
    int m_08;
    unsigned char m_type;
};
extern "C" int dummy_call(int a);
static __declspec(noinline) __int64 FUN_00dbb140(int x, int* obj, int y, int z)
{
    int* a[3];
    a[0] = &x;
    a[1] = &y;
    a[2] = &z;
    int g1 = *a[1];
    int t1 = dummy_call(g1);
    g1 = g1 + t1;
    int g2 = *a[2];
    int t2 = dummy_call(g2);
    g2 = g2 + t2;
    if (!obj)
        return *a[0];
    return *a[0] + *obj + g1 + g2;
}
struct TailC4D0
{
    int FUN_00dbb260();
};
struct PairC4D0
{
    int lo;
    int hi;
    void FUN_00d873d0(const PairC4D0& other);
};
__declspec(noinline) void PairC4D0::FUN_00d873d0(const PairC4D0& other)
{
    lo = other.lo;
    hi = other.hi;
}
struct NativeC4D0
{
    int m_00, m_04, m_08;
    PairC4D0 value;
    int* world;
};
struct ClassC4D0
{
    const char* FUN_00d46d40();
};
struct FoundClassC4D0
{
    int m_00, m_04, m_08;
    int classValue;
};
struct WorldC4D0
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual FoundClassC4D0* GetClassFromName(const char* name);
};
extern NativeC4D0* allocateNativeC4D0();
extern void warnNativeC4D0(int, int);
static __declspec(noinline) int FUN_00dbb260(PairC4D0* r, int* blk)
{
    if (r->hi)
    {
        FoundClassC4D0* c = ((WorldC4D0*)blk)->GetClassFromName(((ClassC4D0*)r->hi)->FUN_00d46d40());
        if (c)
            r->hi = c->classValue;
        else
        {
            warnNativeC4D0(r->lo, r->hi);
            r->lo = 0;
            r->hi = 0;
        }
    }
    NativeC4D0* p = allocateNativeC4D0();
    p->m_00 = 0;
    p->m_04 = 0;
    p->m_08 = 0;
    p->value.FUN_00d873d0(*r);
    p->world = blk;
    return (int)p;
}
struct FUN_00dbc4d0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int* m_14;

    int FUN_00dbc4d0(int name);
};
// Looks up a member by name, extracts its value based on type, and returns a native object via FUN_00dbb260.
// @fnv 0x00dbc4d0
int FUN_00dbc4d0_Class::FUN_00dbc4d0(int name)
{
    MemberC4D0* member;
    VariantC4D0 v;
    reinterpret_cast<::D871A0Buffer *>(&(v))->FUN_00d871a0((*(const ::D871A0Array *)(&m_0C)), name);
    member = (MemberC4D0*)((int *)(reinterpret_cast<::D87370Obj *>(&(v))->FUN_00d87370()));
    PairC4D0 result;
    result.lo = 0;
    result.hi = 0;
    _ReadWriteBarrier();
    int type = member->m_type;
    switch (type)
    {
    case 0x14: {
        int b2 = m_14[2];
        int b3 = m_14[3];
        unsigned __int64 r = FUN_00dbb140(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920(), *(int**)reinterpret_cast<::FUN_00d87210_class *>(&(v))->FUN_00d87210(0), b3, b2);
        result.lo = (int)r;
        result.hi = (int)(r >> 32);
        break;
    }
    case 0x19: {
        int b2 = m_14[2];
        int b3 = m_14[3];
        unsigned __int64 r = FUN_00dbb140(reinterpret_cast<::Struct_d86920 *>((member))->FUN_00d86920(), (int*)reinterpret_cast<::FUN_00d87200_cls *>(&(v))->FUN_00d87200(), b3, b2);
        result.lo = (int)r;
        result.hi = (int)(r >> 32);
        break;
    }
    case 0x1c: {
        int* p = ((int *)(reinterpret_cast<::FUN_00d87360_class *>(&(v))->FUN_00d87360(0)));
        result.lo = p[0];
        _ReadWriteBarrier();
        result.hi = p[1];
        break;
    }
    default:
        return 0;
    }
    if (result.lo != 0 && result.hi != 0)
    {
        return FUN_00dbb260(&result, m_14);
    }
    return 0;
}

struct NativeVariant
{
    void* object;
    void* pClassInfo;
};
hkClassDBB7* volatile inputClass;
hkVtableClassRegistryDBB7* volatile inputRegistry;
hkDataWorldNativeDBB7* volatile inputWorld;
void* volatile inputObject;
void* volatile outputObject;
void* volatile outputClass;

static __forceinline void* CreateDataObjectFromNativeInstance(void* object, hkVtableClassRegistryDBB7* registry,
                                                              hkDataWorldNativeDBB7* world)
{
    void* pClassInfo = registry->GetClassFromVirtualInstance(object);
    if (pClassInfo)
    {
        pClassInfo = world->GetClassFromName(reinterpret_cast<::FnvClassNameNode *>((((hkClassDBB7*)pClassInfo)))->FUN_00d46d40());
    }
    return pClassInfo;
}

// Creates a NativeVariant, using the resolved class for virtual classes and the given class otherwise.
// @fnv 0x00dbb140
static __declspec(noinline) NativeVariant
    FUN_00dbb140(unsigned int akClass, void* object, hkVtableClassRegistryDBB7* registry, hkDataWorldNativeDBB7* world)
{
    hkClassDBB7* pClass = (hkClassDBB7*)akClass;
    NativeVariant result = {0, 0};
    if (pClass && object)
    {
        if (pClass->GetLastNodeFlag().m_bValue)
        {
            void* pMostDerivedClass = CreateDataObjectFromNativeInstance(object, registry, world);
            if (pMostDerivedClass)
            {
                result.pClassInfo = pMostDerivedClass;
                result.object = object;
            }
            else
            {
                unsigned int buffer[128];
                FUN_00cb1600 stream((char*)buffer, 512);
                reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDBB7 *)(reinterpret_cast<::SinkOwner *>(&(stream))->FUN_00cc01c0("Could not find the most derived class for virtual object ")))))->FUN_00cc01c0(reinterpret_cast<::FnvClassNameNode *>((pClass))->FUN_00d46d40())))))->FUN_00cc01c0(" at ")))
                    .FUN_00cc0120(object)))->FUN_00cc01c0(". The object is replaced with HK_NULL.");
                (*reinterpret_cast<::hkErrorDBB7 * *>(&::DAT_01268360))->message(1, 0x3476d70f, (char*)buffer, ".\\Data\\Native\\hkDataObjectNative.cpp", 55);
                reinterpret_cast<struct ::FUN_00cc00e0 *>(&(stream))->FUN_00cc00e0::~FUN_00cc00e0();
                return result;
            }
        }
        else
        {
            result.pClassInfo = pClass;
            result.object = object;
        }
    }
    return result;
}

void nativeCaller()
{
    NativeVariant result = FUN_00dbb140((unsigned int)inputClass, inputObject, inputRegistry, inputWorld);
    outputObject = result.object;
    outputClass = result.pClassInfo;
}

namespace fnv_00dbb520 {
extern int DAT_010d62fc;
struct Source
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void* vf10(void*);
};
struct Allocator
{
    virtual void a();
    virtual void* allocate(unsigned int);
};
struct Router
{
    int a, b, c, d;
    Allocator* allocator;
};
Router* __cdecl FUN_00c85750();
struct Index
{
};
struct Record
{
    void* type;
    unsigned short byteSize;
    unsigned short flags;
    unsigned int state;
    void* reference;
    void* owner;
};
struct Object
{
    int a, b;
    Source* source;
    int d;
    Index index;
    Record* FUN_00dbb520(void*);
};
// Looks up a record by key in the index, or allocates a new 20-byte record, stores the source reference, and inserts it into the index.
// @fnv 0x00dbb520
Record* Object::FUN_00dbb520(void* key)
{
    void* reference;
    if (key)
    {
        Record* existing = (Record*)((void *)(reinterpret_cast<::hkObjectD878 *>(&(index))->GetValue((int)(key), (int)(0))));
        if (existing)
            return existing;
        reference = source->vf10(key);
    }
    else
        reference = 0;
    Router* router = FUN_00c85750();
    Record* record = (Record*)router->allocator->allocate(20);
    record->byteSize = 20;
    record->flags = 0;
    record->state = 0;
    record->type = &DAT_010d62fc;
    record->reference = reference;
    record->owner = this;
    reinterpret_cast<::hkStringMapD874 *>(&(index))->FUN_00d874d0((const char *)(key), (int)(record));
    return record;
}
}  // namespace fnv_00dbb520

struct NativeMemberReferenceDBBA
{
    int object;
    int name;

    NativeMemberReferenceDBBA(int owner, int memberName) : object(owner), name(memberName)
    {}
};

struct C_dbbab0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;

    NativeMemberReferenceDBBA FUN_00dbbab0(int param_1);
};

// Calls FUN_00d871a0 on m_0C with param_1, then returns a NativeMemberReferenceDBBA pairing this object with param_1.
// @fnv 0x00dbbab0
NativeMemberReferenceDBBA C_dbbab0::FUN_00dbbab0(int aiMemberName)
{
    FUN_00d871a0 member(&m_0C, aiMemberName);
    return NativeMemberReferenceDBBA((int)this, aiMemberName);
}
