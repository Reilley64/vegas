// src/havok/common/serialize/util/hkserializeutil_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/util/hkserializeutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/common/serialize/util/hkserializeutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkserializeutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/Cls.h"
#include "fnv/decl/DBA7F0Ref.h"
#include "fnv/decl/DbbOwner.h"
#include "fnv/decl/FUN_00dba680_cls.h"
#include "fnv/decl/FUN_00dba780_cls.h"
#include "fnv/decl/FUN_00dba810_cls.h"
#include "fnv/decl/FUN_00dba980_cls.h"
#include "fnv/decl/FUN_00dbc670.h"
#include "fnv/decl/FUN_00dbc6e0_s.h"
#include "fnv/decl/FUN_00dc5d30.h"
#include "fnv/decl/FUN_00dc72a0_class.h"
#include "fnv/decl/FUN_00dcc670_Class.h"
#include "fnv/decl/PatchManager.h"
#include "fnv/decl/ProviderWrapper.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/fnv_00dbd620__S_00dbd620_Owner.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d48000.h"
#include "fnv/symbols_00dc0000.h"
#include "fnv/symbols_00dc3000.h"
#include "fnv/symbols_00dc5000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010d7000.h"
#include "fnv/symbols_011b7000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
void __cdecl FUN_00d48640(int a, int b);
void __cdecl FUN_00d48660(int a, int b, int c);
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
int __cdecl FUN_00d484a0(int a1, int a2, int a3, int a4, int useLocal, int a6);
struct CtorBox
{

    void* f0;
    int f4;
    void* b;
};
void* __cdecl FUN_00d48ec0(void* a1, int a2, int a3);
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
S_00d49310_Result FUN_00d49310(void* stream);
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
struct FUN_00d493a0_cls
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    bool* MatchesTag(bool* out, const char* tag);
};
struct D493E0Object;
struct D493E0Ref
{
    D493E0Ref(D493E0Object* p);

    D493E0Object* m_pRetainedObject;
};
struct D493E0Registry
{
};
struct D493E0Loader
{
    int unk00;
    int unk04;
    int unk08;
    D493E0Registry* m_registry;

    D493E0Ref FindObject(const void* key, int flags) const;
};
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
    void FUN_00dba660();
};
struct Obj2
{
    void FUN_00dba660();
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
static int FUN_00d48a90(int a1, int esi_in, int edi_in, int ebx_in);
int __cdecl S00d48a90_Entry(int a1);
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
static void FUN_00d48680(S00d48680_Obj* obj, S00d48680_Arr* arr);
void __cdecl S00d48680_Entry(S00d48680_Obj* obj, S00d48680_Arr* arr);


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
struct VersionString
{
    unsigned word;
};
struct LoadFormat
{
    int kind;
    VersionString version;
    unsigned char pointerSize;
    unsigned char littleEndian;
    unsigned char paddingReuse;
    unsigned char emptyBase;
};
struct LoadError
{
    int code;
    hkStringPtr message;
    void set(int c, const char* text)
    {
        code = c;
        reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(message))->FUN_00cb0c10(text);
    }
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

static __declspec(noinline) void FUN_00d48680(S00d48680_Obj* obj, S00d48680_Arr* arr)
{
    VersionedDataBlock& input = *(VersionedDataBlock*)obj;
    Buffer& bytes = *(Buffer*)arr;
    if (input.canSeek())
    {
        input.seek(0, 2);
        bytes.resize(input.tell());
        input.seek(0, 0);
        input.read(bytes.begin(), bytes.size());
    }
    else
    {
        int readCount;
        do
        {
            const int chunk = 0x20000;
            bytes.reserve(bytes.size() + chunk);
            readCount = input.read(bytes.begin() + bytes.size(), chunk);
            bytes.expand(readCount);
        } while (readCount > 0);
    }
}

void __cdecl S00d48680_Entry(S00d48680_Obj* obj, S00d48680_Arr* arr)
{
    FUN_00d48680(obj, arr);
}

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

void* FiveIntegerLoadRecord(VersionedDataBlock& input, const LoadFormat& format, LoadError* error, const void* registry)
{
    return FUN_00d48760(input, format, error, registry);
}
