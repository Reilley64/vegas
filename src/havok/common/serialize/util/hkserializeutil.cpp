
// src/havok/common/serialize/util/hkserializeutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkserializeutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00d48640
#include "fnv/decl/DbbOwner.h"
#include "fnv/decl/FUN_00dba680_cls.h"
#include "fnv/decl/FUN_00dba810_cls.h"
#include "fnv/decl/ProviderWrapper.h"
#include "fnv/decl/hkDataObjectNativeDBB7.h"
#include "fnv/symbols_011b7000.h"
#include <cstring>
#include "fnv/decl/FUN_00cb0a60.h"
#include "fnv/decl/FUN_00d61a50_cls.h"
#include "fnv/symbols_00d2c000.h"
#include <new>
#include "fnv/decl/Cls.h"
#include "fnv/decl/DBA7F0Ref.h"
#include "fnv/decl/DataObjectHandle.h"
#include "fnv/decl/FUN_00d47970_Class.h"
#include "fnv/decl/FUN_00d87790.h"
#include "fnv/decl/FUN_00d877d0_class.h"
#include "fnv/decl/FUN_00dba780_cls.h"
#include "fnv/decl/FUN_00dba980_cls.h"
#include "fnv/decl/FUN_00dbb360_Class.h"
#include "fnv/decl/FUN_00dbb3f0__hkDataWorldNative.h"
#include "fnv/decl/FUN_00dbb490_class.h"
#include "fnv/decl/FUN_00dbc670.h"
#include "fnv/decl/FUN_00dbc6e0_s.h"
#include "fnv/decl/FUN_00dc5d30.h"
#include "fnv/decl/FUN_00dc72a0_class.h"
#include "fnv/decl/FUN_00dcc670_Class.h"
#include "fnv/decl/MapCB1C.h"
#include "fnv/decl/PatchManager.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/S_00db8670_PatchManager.h"
#include "fnv/decl/fnv_00dbd620__S_00dbd620_Owner.h"
#include "fnv/decl/hkClassD47120.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d48000.h"
#include "fnv/symbols_00dba000.h"
#include "fnv/symbols_00dc0000.h"
#include "fnv/symbols_00dc3000.h"
#include "fnv/symbols_00dc5000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010cf000.h"
#include "fnv/symbols_010d7000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
void __cdecl FUN_00d48640(int a, int b)
{
    ::FUN_00d48620(a, b, 1);
}


// @fnv 0x00d48660
void __cdecl FUN_00d48660(int a, int b, int c)
{
    FUN_00d485a0(a, b, c, 1, 0);
}


struct hkReferencedObject
{
};

struct FUN_00dcc160_cls
{
    void* vtbl;
    int a;
    hkReferencedObject* b;
    void FUN_00dcc160();
};

// @fnv 0x00dcc160
void FUN_00dcc160_cls::FUN_00dcc160()
{
    hkReferencedObject* old = b;
    vtbl = &DAT_010d7540;
    if (old)
        reinterpret_cast<::hkReferencedObjectC905 *>((old))->FUN_00c905b0();
    vtbl = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct FUN_00dbc670_storage
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
};
struct FUN_00dbc670_shell
{
};
struct GlobalDispatch
{
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int Dispatch(int, int, int, int, int);
};
// @fnv 0x00d484a0
int __cdecl FUN_00d484a0(int a1, int a2, int a3, int a4, int useLocal, int a6)
{
    if (a3)
    {
        if (useLocal)
        {
            FUN_00dbc670_storage msgStorage;
            FUN_00dbc670_shell* shell = (FUN_00dbc670_shell*)&msgStorage;
            new ((void *)(shell)) ::FUN_00dbc670();
            reinterpret_cast<::Cls *>((shell))->FUN_00dbda50((void *)(a1), (void *)(a2), (void *)(a6));
            int result = ((int)(reinterpret_cast<::fnv_00dbd620::S_00dbd620_Owner *>((shell))->ProcessPoly((::fnv_00dbd620::S_00dbd620_Poly *)(a3), (::fnv_00dbd620::S_00dbd620_Arg *)(a4))));
            reinterpret_cast<::FUN_00dbc6e0_s *>((shell))->FUN_00dbc6e0();
            return result;
        }
        return DAT_01269b74->Dispatch(a1, a2, a3, a4, a6);
    }
    return 1;
}


struct CtorBox
{

    void* f0;
    int f4;
    void* b;
};

// Constructs a CtorBox from a1, calls FUN_00d48d30 on its b field with a2 and a3, destroys the box, and returns the result.
// @fnv 0x00d48ec0
void* __cdecl FUN_00d48ec0(void* a1, int a2, int a3)
{
    CtorBox obj;
    CtorBox* p = ((::CtorBox *)(reinterpret_cast<::FUN_00dcc670_Class *>(&(obj))->InitFromValue((int *)(a1))));
    void* res = ((void *)(::FUN_00d48d30((::S00d48d30_Stream *)(p->b), (::S00d48d30_Result *)(a2), a3)));
    reinterpret_cast<::FUN_00dcc160_cls *>(&(obj))->FUN_00dcc160();
    return res;
}

namespace fnv_00d48f00 {
extern int DAT_011b7b88;
struct Header180
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    char unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Header180()
    {
        ::FUN_00cb1280(this, -1, 64);
        unk00 = 0x57e0e057;
        unk04 = 0x10c0c010;
        unk28 = 0;
    }
};
struct Object180
{
    void* unk00;
    int unk04;
    void* unk08;
    Object180* FUN_00dcc6a0(void* input, int arg2);
};
// @fnv 0x00d48f00
int __cdecl FUN_00d48f00(Header180* pHeader, int arg2, int arg3, int arg4)
{
    Header180 defaultHeader;
    if (pHeader->unk00 == defaultHeader.unk00 && pHeader->unk04 == defaultHeader.unk04 &&
        ::FUN_00cb1290((const unsigned char *)(const void *)(&pHeader->unk10), (const unsigned char *)(const void *)(&DAT_011b7b88), 4) == 0 && ::fnv_00cb0fa0::FUN_00cb0fa0(&pHeader->unk28, ((const char *)(::FUN_00dc0fb0()))) == 0)
        return ((int)(::CreateResourceFromArray(pHeader, (void *)(arg2), (void *)(0))));
    Object180 wrapper;
    Object180* result = wrapper.FUN_00dcc6a0(pHeader, arg2);
    void* payload = result->unk08;
    int value = ::FUN_00d48d30((::S00d48d30_Stream *)(payload), (::S00d48d30_Result *)(arg3), arg4);
    reinterpret_cast<::FUN_00dcc160_cls *>(&(wrapper))->FUN_00dcc160();
    return value;
}
}  // namespace fnv_00d48f00

struct S_00d49310_Lock
{
    int unk0;
    int unk4;
    S_00d49310_Lock() throw();
    ~S_00d49310_Lock() throw();
};
struct S_00d49310_Result
{
    int m_uiFilterValue;
    S_00d49310_Result(int v) : m_uiFilterValue(v)
    {}
};
// @fnv 0x00d49310
S_00d49310_Result FUN_00d49310(void* stream)
{
    S_00d49310_Lock lock;
    int res;
    FUN_00d48af0(stream, &res);
    return S_00d49310_Result(res);
}


static inline int S_00d49350_Compare(const char* a, const char* b)
{
    if (a)
    {
        if (b)
            return ::fnv_00cb0fa0::FUN_00cb0fa0(a, b);
        return 1;
    }
    return b ? -1 : 0;
}

struct S_00d49350
{
    unsigned int m_pcText;

    const char* cString() const
    {
        return (const char*)(m_pcText & ~1u);
    }
    int Equals(const char* s) const;
};

// Compares the stored string with s using S_00d49350_Compare and returns whether they are equal.
// @fnv 0x00d49350
int S_00d49350::Equals(const char* aString) const
{
    return S_00d49350_Compare(cString(), aString) == 0;
}

struct FUN_00d493a0_cls
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    bool* MatchesTag(bool* out, const char* tag);
};

// Compares the four bytes m_00..m_03 against the first four bytes of tag, stores the result in out and returns out.
// @fnv 0x00d493a0
bool* FUN_00d493a0_cls::MatchesTag(bool* pbResult, const char* tag)
{
    bool r;
    if (m_00 == tag[0] && m_01 == tag[1] && m_02 == tag[2] && m_03 == tag[3])
    {
        r = true;
    }
    else
    {
        r = false;
    }
    *pbResult = r;
    return pbResult;
}

struct D493E0Object;

struct D493E0Ref
{
    D493E0Ref(D493E0Object* p);

    D493E0Object* m_pRetainedObject;
};

struct D493E0Registry
{
    D493E0Object* find(const void* key, int flags) const;
};

struct D493E0Loader
{
    int unk00;
    int unk04;
    int unk08;
    D493E0Registry* m_registry;

    D493E0Ref FindObject(const void* key, int flags) const;
};

// Looks up key in m_registry when key is non-null and returns a D493E0Ref wrapping the found object, otherwise a null D493E0Ref.
// @fnv 0x00d493e0
D493E0Ref D493E0Loader::FindObject(const void* key, int flags) const
{
    if (key)
        return D493E0Ref(m_registry->find(key, flags));
    return D493E0Ref(0);
}

struct Pair
{
    void* first;
    void* second;
};

struct Vt4Obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void* unk10(void* apArg);
};

struct GlobalObj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual Vt4Obj* unk10();
};

struct Obj5
{
    void* FUN_00dba680();
    void FUN_00dba660();
};

struct Obj2
{
    void GetObjectValue(Obj5* apOut);
    void FUN_00dba660();
    void GetSourcePair(Pair* apOut);
};

struct Obj1
{
};

struct PairVt
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c(void** apFirst, void** apSecond);
};


struct FUN_00d49420_cls
{
    int unk00;
    int unk04;
    PairVt* m_08;

    Obj1* ProcessPair(Obj1* apArg1, Obj2* apArg2);
    void unk20(Obj1* apA, void* apB, void* apC);
};

// @fnv 0x00d49420
Obj1* FUN_00d49420_cls::ProcessPair(Obj1* apArg1, Obj2* apArg2)
{
    if (m_08 != 0)
    {
        if (((int)(reinterpret_cast<::FUN_00dba980_cls *>((apArg2))->FUN_00dba980())) == 0)
        {
            Obj5 local28;
            Pair pair;
            apArg2->GetObjectValue(&local28);
            Vt4Obj* v = reinterpret_cast<GlobalObj*>(DAT_01268b08)->unk10();
            void** pVtableSlot = *(void***)v + 4;
            void* arg = local28.FUN_00dba680();
            void* pSecond = reinterpret_cast<void*(*)(void*, void*)>(*pVtableSlot)(v, arg);
            apArg2->GetSourcePair(&pair);
            void* first = pair.first;
            if (pair.second != 0)
            {
                pSecond = pair.second;
            }
            void* second = pSecond;
            m_08->unk0c(&first, &second);
            if (first == pair.first && second == pSecond)
            {
                ::FUN_00dba660();
            }
            else
            {
                reinterpret_cast<::D493E0Loader *>(this)->FindObject(apArg1, (int)(first));
                ::FUN_00dba660();
                return apArg1;
            }
        }
    }
    reinterpret_cast<::FUN_00dba780_cls *>((apArg1))->AssignRef((::FUN_00dba780_cls *)(apArg2));
    return apArg1;
}

extern volatile int DAT_01269b70;

static __declspec(noinline) int FUN_00d48950(int d, int a, int b, int c)
{
    int* pb = &b;
    if (d)
    {
        return a;
    }
    return *pb + c;
}

struct Holder_cls
{
    int unk00;
};

struct Pending_cls
{
    int unk00;
    int unk04;
};

struct Owner_cls
{
};

// Initialises a Pending_cls and Holder_cls, then returns 1 if a condition on edi_in fails, otherwise calls Owner_cls::FUN_00dba0d0.
// @fnv 0x00d48a90
static __declspec(noinline) int FUN_00d48a90(int a1, int esi_in, int edi_in, int ebx_in)
{
    Pending_cls p;
    Holder_cls h;

    new ((void *)&(p)) ::FUN_00dc5d30();
    ::FUN_00dc5d50((unsigned int)&(p), (unsigned int)(&h), a1);
    reinterpret_cast<::DBA7F0Ref *>(&(h))->FUN_00dba7f0();

    if (edi_in != 0)
    {
        if (FUN_00d48950(edi_in, esi_in, DAT_01269b70, ebx_in) == 0)
        {
            return 1;
        }
    }
    return reinterpret_cast<::PatchManager *>((((Owner_cls*)DAT_01269b70)))->FUN_00dba0d0(esi_in, ebx_in);
}

int __cdecl S00d48a90_Entry(int a1)
{
    return FUN_00d48a90(a1, 0, 0, 0);
}

struct S00d48d30_Bool
{
    char m_cBooleanValue;
    S00d48d30_Bool()
    {}
};

struct S00d48d30_Stream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S00d48d30_Bool IsStreamValid() const;
};

struct hkStringPtr
{
    void* m_pcText;
    void operator=(const char* s);
public:
    void FUN_00cb0c70(const char *, ...);
};

struct S00d48d30_Result
{
    int m_iResultCode;
    hkStringPtr m_message;
};

struct S00d48d30_Lock
{
    int unk00;
    int unk04;
    S00d48d30_Lock() throw();
    ~S00d48d30_Lock() throw();
};

struct S00d48d30_Ref
{
    int unk00;
    S00d48d30_Ref(const S00d48d30_Ref&) throw();
    ~S00d48d30_Ref() throw();
};

struct S00d48d30_Format
{
    int m_type;
    int attach(struct S00d48d30_Stream* s, struct S00d48d30_Result* out);
};

struct S00d48d30_Reader
{
    int unk00;
    int unk04;
    int unk08;
    S00d48d30_Reader() throw();
    ~S00d48d30_Reader() throw();
    void prepare();
    int open(S00d48d30_Stream* s);
    void close();
};

struct S00d48d30_Service
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int getLoadOptions();
    virtual int getDefaultOptions();
};

extern const char str_010cfacc[];
extern const char str_010cfab8[];
extern const char str_010cfa94[];

int S00d48d30_Finish(int opts);

static __declspec(noinline) int FUN_00d48a90(S00d48d30_Stream* s, S00d48d30_Reader* reader, S00d48d30_Result* out)
{
    reader->prepare();
    if (reader->open(s) == 0)
    {
        if (out != 0)
        {
            out->m_iResultCode = 3;
            reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(out->m_message))->FUN_00cb0c10(str_010cfa94);
        }
        reader->close();
        return 1;
    }
    return 0;
}

static __declspec(noinline) int FUN_00d48760(S00d48d30_Stream* s, S00d48d30_Format* format, S00d48d30_Result* out,
                                             int opts)
{
    if (format->m_type < 2)
    {
        return 0;
    }
    if (out != 0)
    {
        out->m_iResultCode = 0;
    }
    if (s == 0)
    {
        return 0;
    }
    if (format->attach(s, out) == 0)
    {
        return 0;
    }
    return S00d48d30_Finish(opts);
}

// Validates the stream, resolves load options, and dispatches to a format-specific loader based on the detected stream type.
// @fnv 0x00d48d30
int __cdecl FUN_00d48d30(S00d48d30_Stream* apStream, S00d48d30_Result* apResult, int aiOptions) throw()
{
    if (apStream == 0)
    {
        if (apResult != 0)
        {
            apResult->m_iResultCode = 1;
            reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(apResult->m_message))->FUN_00cb0c10(str_010cfacc);
        }
        return 0;
    }
    if (!apStream->IsStreamValid().m_cBooleanValue)
    {
        if (apResult != 0)
        {
            apResult->m_iResultCode = 1;
            reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(apResult->m_message))->FUN_00cb0c10(str_010cfab8);
        }
        return 0;
    }
    if (aiOptions == 0)
    {
        aiOptions = reinterpret_cast<S00d48d30_Service*>(DAT_01268b08)->getDefaultOptions();
    }
    S00d48d30_Lock lock;
    S00d48d30_Format format;
    FUN_00d48af0(apStream, &format.m_type);
    switch (format.m_type)
    {
    case 2:
    case 3:
        return FUN_00d48760(apStream, &format, apResult,
                            reinterpret_cast<S00d48d30_Service*>(DAT_01268b08)->getLoadOptions());
    case 4: {
        S00d48d30_Reader reader;
        if (FUN_00d48a90(apStream, &reader, apResult) == 0)
        {
            return ((int)(::FUN_00dc3300((::S_PH *)&(const ::S00d48d30_Ref &)((*(::S00d48d30_Ref *)(reinterpret_cast<::FUN_00dc72a0_class *>(&(reader))->ForwardToReceiver({})))), (::S_Dom *)(aiOptions))));
        }
        return 0;
    }
    }
    if (apResult != 0)
    {
        apResult->m_iResultCode = 2;
        reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(apResult->m_message))->FUN_00cb0c10(str_010cfa94);
    }
    return 0;
}

struct S00d48680_Arr
{
    char* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};

struct S00d48680_Alloc
{
    int unk00;
};

struct S00d48680_Sys
{
    int unk00;
    int unk04;
    int unk08;
    S00d48680_Alloc* heap;
    S00d48680_Alloc& getHeap()
    {
        return *heap;
    }
};

extern "C" S00d48680_Sys* __cdecl FUN_00c85750();

struct S00d48680_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int a, int b);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned char& v9(unsigned char& f);
    virtual void v10(int a, int b);
    virtual int v11();
};

// Reads data into arr from obj, growing the buffer via FUN_00c908c0 when the requested size exceeds the current capacity.
// @fnv 0x00d48680
static __declspec(noinline) void FUN_00d48680(S00d48680_Obj* apReader, S00d48680_Arr* apBuffer)
{
    unsigned char flag;
    if (apReader->v9(flag))
    {
        apReader->v10(0, 2);
        int iNeeded = apReader->v11();
        S00d48680_Alloc& heap = FUN_00c85750()->getHeap();
        unsigned int cap = apBuffer->m_capFlags & 0x3fffffff;
        if ((int)cap < iNeeded)
        {
            int grow = (int)(cap * 2);
            if (iNeeded >= grow)
            {
                grow = iNeeded;
            }
            ::FUN_00c908c0((::SpawnedObject *)(::S00d48680_Alloc *)(&heap), (::SpawnedArray *)(apBuffer), grow, 1);
        }
        apBuffer->m_iElementCount = iNeeded;
        apReader->v10(0, 0);
        apReader->v4((int)apBuffer->m_data, apBuffer->m_iElementCount);
        return;
    }

    int r;
    do
    {
        int iNeeded = apBuffer->m_iElementCount + 0x20000;
        S00d48680_Alloc& heap = FUN_00c85750()->getHeap();
        unsigned int cap = apBuffer->m_capFlags & 0x3fffffff;
        if ((int)cap < iNeeded)
        {
            int grow = (int)(cap * 2);
            if (iNeeded < grow)
            {
                iNeeded = grow;
            }
            ::FUN_00c908c0((::SpawnedObject *)(::S00d48680_Alloc *)(&heap), (::SpawnedArray *)(apBuffer), iNeeded, 1);
        }
        char* d = apBuffer->m_data;
        int iSize = apBuffer->m_iElementCount;
        r = apReader->v4((int)(d + iSize), 0x20000);
        apBuffer->m_iElementCount += r;
    } while (r > 0);
}

void __cdecl S00d48680_Entry(S00d48680_Obj* obj, S00d48680_Arr* arr)
{
    FUN_00d48680(obj, arr);
}

struct HashPolicy
{
};
struct StringMapState
{
    void* entries;
    int count;
    int mask;
    HashPolicy policy;
    StringMapState() throw()
    {
        new ((void *)this) ::FUN_00d87790((*(int *)&(const ::HashPolicy &)(HashPolicy())));
    }
    void clear() throw()
    {
        reinterpret_cast<::FUN_00d877d0_class *>(this)->FreeBuffer();
    }
};
struct RegistryBase
{
    void** dispatch;
    unsigned short allocationSize;
    unsigned short references;
    RegistryBase() throw() : references(1)
    {
        dispatch = (*reinterpret_cast<void * (*)[]>(&::fnv_00d47d70::DAT_010cf7b0));
    }
};
struct TypeRegistry : RegistryBase
{
    StringMapState types;
    int finish;
    TypeRegistry(int flag) throw() : finish(flag)
    {}
    void clear() throw()
    {
        types.clear();
    }
};
struct RuntimeClass;
struct ClassRegistry
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual const RuntimeClass* find(const char*) const throw();
};
struct Resource : hkReferencedObject
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void* contents(const char*, const TypeRegistry*) const throw();
    virtual const char* name() const throw();
};
struct ResourceRef
{
    Resource* ptr;
    ResourceRef() throw() : ptr(0)
    {}
    void clear() throw()
    {
        if (ptr)
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(ptr))->FUN_00c905b0();
        ptr = 0;
    }
    Resource* operator->() const
    {
        return ptr;
    }
    void take(Resource* p) throw()
    {
        if (ptr && ptr != p)
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(ptr))->FUN_00c905b0();
        ptr = p;
    }
};
struct ObjectImpl
{
    virtual ~ObjectImpl() throw();
    unsigned short allocationSize;
    unsigned short references;
    int externalRefs;
};
struct RootObject
{
    ObjectImpl* impl;
    __declspec(noinline) void FUN_00dba7f0() throw();
    RootObject(ObjectImpl* p) throw()
    {
        reinterpret_cast<::DataObjectHandle *>(this)->FUN_00dba760((::RefObj *)(p));
    }
    void clear() throw()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
};
__declspec(noinline) void RootObject::FUN_00dba7f0() throw()
{
    if (impl)
    {
        --impl->references;
        if (--impl->externalRefs == 0)
            delete impl;
    }
}
struct NativeWorld
{
    void* dispatch;
    unsigned short allocationSize;
    unsigned short references;
    const ClassRegistry* classes;
    void* vtableRegistry;
    void* mapEntries;
    int mapCount;
    int mapMask;
    HashPolicy mapPolicy;
    void* rootPointer;
    const RuntimeClass* rootClass;
    ObjectImpl* FUN_00dbb4f0(void*, const RuntimeClass&) const throw();
    NativeWorld() throw()
    {
        reinterpret_cast<::FUN_00dbb360_Class *>(this)->Initialize();
    }
    void clear() throw()
    {
        reinterpret_cast<::FUN_00dbb3f0::hkDataWorldNative *>(this)->FUN_00dbb3f0::hkDataWorldNative::~hkDataWorldNative();
    }
};
struct ObjectResource;
struct LoadFormat
{
    int type;
    S_00d49350 version;
    unsigned int layout;
};
struct LoadError
{
    int status;
    hkStringPtr message;
};
struct LoadStream;
struct LoadBuffer
{
    char* data;
    int size;
    unsigned int capacity;
};
struct LoadAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void freeBlock(void*, int) throw();
};
struct LoadMemory
{
    int unk00;
    int unk04;
    int unk08;
    LoadAllocator* heap;
};
extern unsigned int DAT_011b7b88;
extern const char str_010cf9d8[];
void __cdecl FUN_00d48680(LoadStream&, LoadBuffer&) throw();
struct DeprecatedLoader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Resource* load(LoadStream&, const LoadFormat&, LoadError*) throw();
};
static __declspec(noinline) __declspec(nothrow) Resource* FUN_00d48760(LoadStream& input, const LoadFormat& format,
                                                                       LoadError* error,
                                                                       const TypeRegistry& types) throw()
{
    if (format.type == 2)
    {
        if (::FUN_00cb1290((const unsigned char *)(const void *)(&format.layout), (const unsigned char *)(const void *)(&DAT_011b7b88), 4) == 0)
        {
            if (format.version.Equals(((const char *)(::FUN_00dc0fb0()))))
            {
                LoadBuffer buffer;
                buffer.data = 0;
                buffer.size = 0;
                buffer.capacity = 0x80000000;
                FUN_00d48680(input, buffer);
                Resource* result = ((::Resource *)(::CreateResourceFromArray((void *)(buffer.data), (void *)(buffer.size), (void *)(&types))));
                LoadMemory* memory = (LoadMemory*)FUN_00c85750();
                buffer.size = 0;
                if ((int)buffer.capacity >= 0)
                    memory->heap->freeBlock(buffer.data, buffer.capacity & 0x3fffffff);
                return result;
            }
        }
        else
        {
            if (error)
            {
                error->status = 3;
                reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(error->message))->FUN_00cb0c10(str_010cf9d8);
            }
            return 0;
        }
    }
    return ((DeprecatedLoader*)DAT_01269b74)->load(input, format, error);
}

// Loads a resource via FUN_00d48760, resolves its class in classes, and constructs an ObjectResource from the parsed data.
// @fnv 0x00d48840
static __declspec(noinline) ObjectResource* FUN_00d48840(LoadStream* input, LoadFormat& format, LoadError* error,
                                                         const ClassRegistry* classes, const TypeRegistry* types)
{
    TypeRegistry unfinished(0);
    reinterpret_cast<::FUN_00d47970_Class *>(&(unfinished))->FUN_00d47970((void *)&(*types));
    ResourceRef resource;
    resource.take((Resource*)FUN_00d48760((S00d48d30_Stream*)input, (S00d48d30_Format*)&format,
                                          (S00d48d30_Result*)error, (int)&unfinished));
    NativeWorld data;
    reinterpret_cast<::FUN_00dbb490_class *>(&(data))->SetReferencedObject((::hkReferencedObject *)(classes));
    const RuntimeClass* rootClass = classes->find(resource->name());
    if (rootClass)
    {
        RootObject root(data.FUN_00dbb4f0(resource->contents(0, types), *rootClass));
        ObjectResource* result = ((::ObjectResource *)(::FUN_00dc32c0((void *)&(root), (void *)(classes), (void *)(types))));
        root.clear();
        data.clear();
        resource.clear();
        unfinished.clear();
        return result;
    }
    data.clear();
    resource.clear();
    unfinished.clear();
    return 0;
}
LoadStream* volatile inputSource;
LoadFormat* volatile formatSource;
LoadError* volatile errorSource;
const ClassRegistry* volatile classSource;
const TypeRegistry* volatile typeSource;
ObjectResource* volatile outputSink;
void CallHeapLoader()
{
    outputSink = FUN_00d48840(inputSource, *formatSource, errorSource, classSource, typeSource);
}

extern const char str_010cf9f4[];

struct S00d48950_Item
{
    virtual void v00();
    virtual void v04();
    virtual void* GetIteratorKey();
    virtual int GetNumOwnMembers();
};
struct S00d48950_ItemArray
{
    S00d48950_Item** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d48950_Root
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void getItems(S00d48950_ItemArray& items);
};
struct S00d48950_Entry
{
};
struct S00d48950_Lookup
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual S00d48950_Entry* find(void* key);
};
struct S00d48950_Set
{
};
struct S00d48950_Target
{
    char pad00[0x18];
    S00d48950_Set m_set;
    __int64 FUN_00db7dd0(void* key, int version);
};
struct S00d48950_Result
{
    int m_pMoppCode;
    char m_message[1];
};
struct S00d48950_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S00d48950_Sys
{
    int unk00, unk04, unk08, unk0c;
    S00d48950_Heap* m_pStreamAllocator;
    S00d48950_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

// For each root item, checks lookup and adds it to target's set when versions differ; returns 0 with result code 4 on failure, otherwise 1.
// @fnv 0x00d48950
static __declspec(noinline) int FUN_00d48950(S00d48950_Result* result, S00d48950_Target* target,
                                             S00d48950_Lookup* lookup, S00d48950_Root* root)
{
    reinterpret_cast<::S_00db8670_PatchManager *>((target))->FUN_00db8670();
    S00d48950_ItemArray items;
    items.m_data = 0;
    items.m_iElementCount = 0;
    items.m_iCapacityState = 0x80000000;
    root->getItems(items);
    for (int iIndex = 0; iIndex < items.m_iElementCount; iIndex++)
    {
        void* key = items.m_data[iIndex]->GetIteratorKey();
        int version = items.m_data[iIndex]->GetNumOwnMembers();
        S00d48950_Entry* entry = lookup->find(key);
        int iCurrentVersion = entry ? reinterpret_cast<::hkClassD47120 *>((entry))->FUN_00d47120() : -1;
        if (entry && iCurrentVersion == version)
            continue;
        __int64 id = target->FUN_00db7dd0(key, version);
        if (((int)(reinterpret_cast<::MapCB1C *>(&(target->m_set))->FUN_00cb1cb0(id, -1))) == -1)
        {
            result->m_pMoppCode = 4;
            reinterpret_cast<::hkStringPtr *>((result->m_message))->FUN_00cb0c70(str_010cf9f4, key, version);
            S00d48950_Heap& heap = *((S00d48950_Sys*)FUN_00c85750())->m_pStreamAllocator;
            items.m_iElementCount = 0;
            if ((items.m_iCapacityState & 0x80000000) == 0)
                heap.ReturnMemory(items.m_data, (items.m_iCapacityState & 0x3fffffff) * 4);
            return 0;
        }
    }
    S00d48950_Heap& heap = ((S00d48950_Sys*)FUN_00c85750())->heap();
    items.m_iElementCount = 0;
    if ((items.m_iCapacityState & 0x80000000) == 0)
        heap.ReturnMemory(items.m_data, (items.m_iCapacityState & 0x3fffffff) * 4);
    return 1;
}

S00d48950_Result* volatile g00d48950_result;
S00d48950_Target* volatile g00d48950_target;
S00d48950_Lookup* volatile g00d48950_lookup;
S00d48950_Root* volatile g00d48950_root;
volatile int g00d48950_out;
void S00d48950_Caller()
{
    g00d48950_out = FUN_00d48950(g00d48950_result, g00d48950_target, g00d48950_lookup, g00d48950_root);
}

extern "C" int __cdecl FUN_00d485a0(int, int, int, int, int);

extern int DAT_010cf9b4;
struct Lister
{
    const int* vtbl;
    unsigned char f04;
    short f06;
    int f08;
    void* f0c;
};
struct World
{
    void* vtbl;
    unsigned char f04;
    short f06;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int* method2(int*);
};
struct RefHolder
{
};
struct Proxy
{
    void* vtbl;
    short refs;
};
extern int DAT_010cf9c8;
int __cdecl dispatch(Proxy*, int*, int, void*);
static __declspec(noinline) int helper(int a, void* b, int* c)
{
    if (!a)
        return 1;
    Proxy p;
    p.vtbl = &DAT_010cf9c8;
    p.refs = 1;
    return dispatch(&p, c, a, b);
}
// @fnv 0x00d485a0
extern "C" int __cdecl FUN_00d485a0(int a1, int a2, int a3, int a4, int a5)
{
    Lister lister;
    World world;
    reinterpret_cast<::FUN_00dbb360_Class *>(&(world))->Initialize();
    reinterpret_cast<::hkDataObjectNativeDBB7 *>(&(world))->SetContents((void *)(a1), (*(::hkClassDBB7 *)(a2)));
    lister.f06 = 1;
    lister.vtbl = &DAT_010cf9b4;
    lister.f08 = a5;
    lister.f0c = &world;
    int* obj = world.method2(&a5);
    int r = helper(a3, &lister, obj);
    reinterpret_cast<::DBA7F0Ref *>((((RefHolder*)&a5)))->FUN_00dba7f0();
    lister.vtbl = &(*reinterpret_cast<int *>(&::DAT_0102e388));
    reinterpret_cast<::FUN_00dbb3f0::hkDataWorldNative *>(&(world))->FUN_00dbb3f0::hkDataWorldNative::~hkDataWorldNative();
    return r;
}
static void FUN_00d48680(S00d48680_Obj* obj, S00d48680_Arr* arr);


struct ByteBool
{
    char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct VersionedDataBlock
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ByteBool IsStreamValid() const;
    virtual int read(void*, int);
    virtual int skip(int);
    virtual ByteBool marks() const;
    virtual int mark(int);
    virtual int rewind();
    virtual ByteBool canSeek() const;
    virtual int seek(int, int);
    virtual int tell() const;
};
struct BufferAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void freeBuffer(void*, int);
};
struct TemporaryAllocator
{
    __forceinline BufferAllocator& get(void*)
    {
        return *(BufferAllocator*)FUN_00c85750()->heap;
    }
};
struct BufferBase : S00d48680_Arr
{
    __forceinline BufferBase()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_capFlags = 0x80000000;
    }
    __forceinline ~BufferBase()
    {}
    __forceinline int size() const
    {
        return m_iElementCount;
    }
    __forceinline char* begin()
    {
        return m_data;
    }
    __forceinline int capacity() const
    {
        return m_capFlags & 0x3fffffff;
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void release(BufferAllocator& allocator)
    {
        clear();
        if ((m_capFlags & 0x80000000u) == 0)
            allocator.freeBuffer(m_data, capacity());
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    __forceinline void reserve(BufferAllocator& allocator, int required)
    {
        if (required > capacity())
        {
            int grown = 2 * capacity();
            ::FUN_00c908c0((::SpawnedObject *)(::S00d48680_Alloc *)((S00d48680_Alloc*)&allocator), (::SpawnedArray *)(::S00d48680_Arr *)(this), required > grown ? required : grown, 1);
        }
    }
    __forceinline void resize(BufferAllocator& allocator, int count)
    {
        reserve(allocator, count);
        m_iElementCount = count;
    }
    __forceinline char* expand(int count)
    {
        int old = m_iElementCount;
        m_iElementCount = old + count;
        return m_data + old;
    }
};
struct Buffer : BufferBase
{
    __forceinline Buffer()
    {}
    __forceinline ~Buffer()
    {
        release(TemporaryAllocator().get(this));
    }
    __forceinline void reserve(int count)
    {
        BufferBase::reserve(TemporaryAllocator().get(this), count);
    }
    __forceinline void resize(int count)
    {
        BufferBase::resize(TemporaryAllocator().get(this), count);
    }
};
struct OldLoader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* load(VersionedDataBlock&, const LoadFormat&, LoadError*);
    static OldLoader& instance()
    {
        return *(OldLoader*)DAT_01269b74;
    }
};

// @fnv 0x00d48760
static __declspec(noinline) void* FUN_00d48760(VersionedDataBlock& input, const LoadFormat& format, LoadError* error,
                                               const void* registry)
{
    if (format.kind == 2)
    {
        if (::FUN_00cb1290((const unsigned char *)(const void *)(&format.pointerSize), (const unsigned char *)(const void *)(&DAT_011b7b88), 4) == 0)
        {
            if (reinterpret_cast<::S_00d49350 *>((void *)&(format.version))->Equals(((const char *)(::FUN_00dc0fb0()))))
            {
                Buffer bytes;
                FUN_00d48680((S00d48680_Obj*)&input, &bytes);
                return ::CreateResourceFromArray((void *)(bytes.begin()), (void *)(bytes.size()), (void *)(registry));
            }
        }
        else
        {
            if (error)
                error->set(3, "Wrong platform for packfile");
            return 0;
        }
    }
    return OldLoader::instance().load(input, format, error);
}
void FUN_00d48af0(void* stream, int* out) throw();
void FUN_00d48af0(void* stream, int* out) throw();
struct FormatInfo
{
    int type;
    hkStringPtr version;
    unsigned char layout[4];
};
struct StringOps
{
    unsigned int bits;
    void FUN_00cb0c50(const char*, int);
};
struct HeapApi
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void freeBlock(void*, int);
    template <class T> void freeBuffer(void* p, int count)
    {
        const int width = sizeof(T);
        freeBlock(p, count * width);
    }
};
struct HeapView
{
    int a;
    int b;
    int c;
    HeapApi* heap;
    HeapApi& temp()
    {
        return *heap;
    }
};
struct TempAllocator
{
    HeapApi& get(void*)
    {
        return reinterpret_cast<HeapView*>(FUN_00c85750())->temp();
    }
};
struct CharArrayBase
{
    char* data;
    int size;
    int flags;
    const char* begin() const
    {
        return data;
    }
    int capacity() const
    {
        return flags & 0x3fffffff;
    }
    void clear()
    {
        size = 0;
    }
    void release(HeapApi& heap)
    {
        clear();
        if ((flags & 0x80000000u) == 0)
            heap.freeBuffer<char>(data, capacity());
        data = 0;
        flags = 0x80000000u;
    }
};
struct CharArray : CharArrayBase
{
    void release()
    {
        CharArrayBase::release(TempAllocator().get(this));
    }
    ~CharArray()
    {
        release();
    }
};
struct CharStorage : CharArray
{
    char storage[128];
    ~CharStorage()
    {}
};
struct BufferedText
{
    CharStorage array;
    const char* cString() const
    {
        return array.begin();
    }
};
inline const char* stringText(const hkStringPtr& s)
{
    return reinterpret_cast<const char*>(reinterpret_cast<unsigned int>(s.m_pcText) & ~1u);
}
void __cdecl FUN_00cb1280(void*, int, int);
struct PackHeader
{
    PackHeader()
    {
        FUN_00cb1280(this, -1, sizeof(*this));
        magic[0] = 0x57e0e057;
        magic[1] = 0x10c0c010;
        version[0] = 0;
    }
    int magic[2];
    int userTag;
    int fileVersion;
    unsigned char layout[4];
    int sections;
    int contentSection;
    int contentOffset;
    int classSection;
    int classOffset;
    char version[16];
    int reserved0;
    int reserved1;
};
struct SmallBool
{
    char value;
    SmallBool()
    {}
    SmallBool(bool b) : value((char)b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
void __cdecl FUN_00cb1280(void*, int, int);
inline unsigned int reverseWord(unsigned int word)
{
    union WordBytes
    {
        unsigned int word;
        unsigned char byte[4];
    } src, dst;
    src.word = word;
    dst.byte[0] = src.byte[3];
    dst.byte[1] = src.byte[2];
    dst.byte[2] = src.byte[1];
    dst.byte[3] = src.byte[0];
    return dst.word;
}
inline SmallBool __cdecl CheckMagicPair(unsigned int a, unsigned int b)
{
    return ((a == 0xcab00d1e && b == 0xd011face) || (reverseWord(a) == 0xcab00d1e && reverseWord(b) == 0xd011face));
}
const char* __cdecl FUN_00cb1130(const char*, const char*);
int __cdecl FUN_00cb10d0(const char*);
const char* __cdecl FUN_00cb1140(const char*, int);
int __cdecl CallWithZeroMiddleArg(const char*, int);

static __declspec(noinline) const char* FUN_00d48420(const char* p)
{
    while (*p && *p == ' ')
        ++p;
    return p;
}
static __declspec(noinline) int ParseQuotedValue(const char* text, const char* key, hkStringPtr& out)
{
    const char* first = FUN_00cb1130(text, key);
    if (!first)
        return 0;
    first += FUN_00cb10d0(key);
    first = FUN_00d48420(first);
    if (*first != '=')
        return 0;
    ++first;
    first = FUN_00d48420(first);
    if (*first != '"')
        return 0;
    ++first;
    const char* last = FUN_00cb1140(first, '"');
    if (!last)
        return 0;
    reinterpret_cast<StringOps*>(&out)->FUN_00cb0c50(first, int(last - first));
    return 1;
}

static __forceinline void detect(VersionedDataBlock* reader, FormatInfo& out)
{
    out.type = 0;
    reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(out.version))->FUN_00cb0c10(0);
    ::FUN_00d2cab0();
    char bytes[128];
    std::memset(bytes, 0, 128);
    reader->mark(128);
    int count = reader->read(bytes, 128);
    reader->rewind();
    PackHeader baseline;
    const PackHeader* binary = reinterpret_cast<const PackHeader*>(bytes);
    const unsigned int* tag = reinterpret_cast<const unsigned int*>(bytes);
    if (count >= 8 && CheckMagicPair(tag[0], tag[1]))
    {
        out.type = 4;
    }
    else if (count >= int(sizeof(PackHeader)) && binary->magic[0] == baseline.magic[0] &&
             binary->magic[1] == baseline.magic[1])
    {
        out.type = 2;
        reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(out.version))->FUN_00cb0c10(binary->version);
        ::fnv_00d2caa0::FUN_00d2caa0(&out.layout, (void *)(binary->layout), 4);
    }
    else if (FUN_00cb1130(bytes, "<hkpackfile ") || FUN_00cb1130(bytes, "<hkpackfile>"))
    {
        out.type = 3;
        BufferedText header;
        reinterpret_cast<::FUN_00d61a50_cls *>(&(header))->FUN_00d61a50((int)(FUN_00cb1130(bytes, "<hkpackfile")));
        hkStringPtr version;
        new ((void *)(reinterpret_cast<StringOps*>(&version))) struct ::FUN_00cb0a60();
        if (ParseQuotedValue(header.cString(), "classversion", version))
        {
            int v = CallWithZeroMiddleArg(stringText(version), 0);
            switch (v)
            {
            case 1:
                reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(out.version))->FUN_00cb0c10("Havok-3.0.0");
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                if (!ParseQuotedValue(header.cString(), "contentsversion", out.version))
                    reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(out.version))->FUN_00cb0c10("Havok-3.1.0");
                break;
            default:
                reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(out.version))->FUN_00cb0c10("error");
                break;
            }
        }
        else
            reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(out.version))->FUN_00cb0c10("Havok-3.0.0");
        ::FUN_00cb0c00((int)(reinterpret_cast<StringOps*>(&version)));
    }
}
// @fnv 0x00d48af0
void FUN_00d48af0(void* stream, int* out) throw()
{
    detect(static_cast<VersionedDataBlock*>(stream), *reinterpret_cast<FormatInfo*>(out));
}

#include "generated/data/havok/common/serialize/util/hkserializeutil.inc"
