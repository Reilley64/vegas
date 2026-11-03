
// src/havok/common/serialize/util/hkserializeutil_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00d485a0: the skeleton of src/havok/common/serialize/util/hkserializeutil.cpp
// with declarations corrected to what the original code does (unit: extern "C" void __cdecl FUN_00d485a0(int, int, int, int, int -> extern "C" int __cdecl FUN_00d485a0(int, int, int, int, int)). Move the function to its real unit once
// that unit declares it this way.

// src/havok/common/serialize/util/hkserializeutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkserializeutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/Cls.h"
#include "fnv/decl/DBA7F0Ref.h"
#include "fnv/decl/DbbOwner.h"
#include "fnv/decl/FUN_00dba680_cls.h"
#include "fnv/decl/FUN_00dba780_cls.h"
#include "fnv/decl/FUN_00dba810_cls.h"
#include "fnv/decl/FUN_00dba980_cls.h"
#include "fnv/decl/FUN_00dbb360_Class.h"
#include "fnv/decl/FUN_00dbb3f0__hkDataWorldNative.h"
#include "fnv/decl/FUN_00dbc670.h"
#include "fnv/decl/FUN_00dbc6e0_s.h"
#include "fnv/decl/FUN_00dcc670_Class.h"
#include "fnv/decl/ProviderWrapper.h"
#include "fnv/decl/fnv_00dbd620__S_00dbd620_Owner.h"
#include "fnv/decl/hkDataObjectNativeDBB7.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00d48000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010d7000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
void __cdecl FUN_00d48640(int a, int b);
extern "C" int __cdecl FUN_00d485a0(int, int, int, int, int);
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
