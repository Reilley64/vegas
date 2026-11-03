
// src/staging/blk_00540000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cstring>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_0046f070_shell.h"
#include "fnv/decl/FUN_00544440_Class.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00555bc0_shell.h"
#include "fnv/decl/FUN_00555be0_stub.h"
#include "fnv/decl/FUN_00557d50.h"
#include "fnv/decl/FUN_00559d90.h"
#include "fnv/decl/FUN_005651e0_shell.h"
#include "fnv/decl/FUN_00572230_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006208d0_cls.h"
#include "fnv/decl/FUN_006b8310_class.h"
#include "fnv/decl/FUN_008799c0_shell.h"
#include "fnv/decl/FUN_00c74760.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiTPointerListBase.h"
#include "fnv/decl/Range62A.h"
#include "fnv/decl/SeenData_S.h"
#include "fnv/decl/TESContainer.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/extra421__E4List.h"
#include "fnv/decl/fnv_0054acf0__FUN_0054acf0.h"
#include "fnv/decl/fnv_005596a0__FUN_005596a0.h"
#include "fnv/decl/fnv_0062a100__FUN_0062a100_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004ba000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_00879000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01272000.h"
#include "../../include/layout_support.h"

struct FUN_00540700_Class
{
    int FUN_00540780(int);
    int FUN_00540700();
};

// @fnv 0x00540700
int FUN_00540700_Class::FUN_00540700()
{
    return FUN_00540780(0x25);
}

struct FUN_005407b0_Class
{
    void FUN_005407b0(char a);
};

// @fnv 0x005407b0
void FUN_005407b0_Class::FUN_005407b0(char acValue)
{
    *reinterpret_cast<char*>(this) = acValue;
}

struct FUN_00540830_class
{
    const char* vtbl;
    FUN_00540830_class* FUN_00540830(int a, int b);
};

struct TaskQueueInterface
{
    void SetTaskFlag_005468b0(bool enabled);
};

// @fnv 0x005468b0
void TaskQueueInterface::SetTaskFlag_005468b0(bool enabled)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(enabled, 0x200000);
}

struct GO
{
    void* operator=(void*);
};

struct FUN_00549610_Class
{
    void FUN_00549610(void* arg);
};

// @fnv 0x00549610
void FUN_00549610_Class::FUN_00549610(void* arg)
{
    *(GO*)((char*)this + 0x104) = arg;
}


// @fnv 0x00553300
void __cdecl FUN_00553300(unsigned int blocksize)
{
    ::FUN_00553320(16, blocksize);
}

struct FUN_00554590_Class
{
    void* vtbl;
    void* FUN_00554590();
};

extern int DAT_0102f10c;

// @fnv 0x00554590
void* FUN_00554590_Class::FUN_00554590()
{
    new ((void *)this) ::FUN_00c74760();
    vtbl = &DAT_0102f10c;
    return this;
}

struct FUN_005545b0
{
    void Call();
};
struct FUN_005545d0_Class
{
    void FUN_005545f0();
    void FUN_005545d0();
};
// @fnv 0x005545b0
void FUN_005545b0::Call()
{
    reinterpret_cast<::FUN_005545d0_Class *>(this)->FUN_005545d0();
}

struct FUN_00554650_Class
{
    void FUN_00554650();
};

// @fnv 0x00554650
void FUN_00554650_Class::FUN_00554650()
{
    *(char**)((char*)this) = "pFU";
}


// @fnv 0x005586c0
void __cdecl FUN_005586c0(int a)
{
    ::WriteRenderStatsFile((::RenderStats *)(a));
}

extern int DAT_0102f448;
struct FUN_00559e50_Class
{
    int* p;
    void FUN_00559eb0(int arg);
    FUN_00559e50_Class* InitializeWithGlobal(int arg);
};
struct FUN_0055a020_Class
{
    void FUN_0055a020();
};

struct FUN_0055a220_class
{
};

struct FUN_0055a220 : FUN_0055a220_class
{
    FUN_0055a220();
};

struct FUN_0055a290_Class
{
    void FUN_0055a290();
};

struct FUN_0055a2b0_Class
{
    void* m0;
    void* m1;
    void FUN_0055a2b0();
};
// @fnv 0x0055a290
void FUN_0055a290_Class::FUN_0055a290()
{
    reinterpret_cast<::FUN_0055a2b0_Class *>(this)->FUN_0055a2b0();
}

// @fnv 0x0055a2b0
void FUN_0055a2b0_Class::FUN_0055a2b0()
{
    reinterpret_cast<::FUN_006208d0_cls *>((((FUN_0055a2b0_Class*)((char*)this + 8))))->FUN_006208d0_cls::~FUN_006208d0_cls();
}

struct FUN_0055b9a0_class
{
    char GetByteAtOffset42();
};

// @fnv 0x0055b9a0
char FUN_0055b9a0_class::GetByteAtOffset42()
{
    return ((char*)this)[0x2a];
}

extern void* DAT_0102e47c;

struct FUN_00540a10_cls : public NiTPointerMap<int, int>
{
    void* b;
    void FUN_00540a10();
};

// @fnv 0x00540a10
void FUN_00540a10_cls::FUN_00540a10()
{
    *(void**)this = &DAT_0102e47c;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

namespace fnv_00559230 {
struct FUN_00559230_class
{
    void* m_vft;
    void* m_auiShapeKeys;
    void* pAudioItems;
    void RemoveAll();
    void FUN_00559230();
};
// @fnv 0x00559230
void FUN_00559230_class::FUN_00559230()
{
    m_vft = &::DAT_0102f398;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(pAudioItems);
}
}  // namespace fnv_00559230

namespace fnv_00559df0 {
struct FUN_00559df0
{
    void* p;
    void* q;
    void* r;
    void Init();
};
// Sets p to DAT_0102f428, clears the pointer map, and frees r via _NiFreeAlias.
// @fnv 0x00559df0
void FUN_00559df0::Init()
{
    p = &(*reinterpret_cast<void * *>(&::fnv_00559d20::DAT_0102f428));
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(r);
}
}  // namespace fnv_00559df0

namespace fnv_00559ff0 {

struct FUN_00559ff0_class
{
    void* vtbl;
    int unused;
    void* data;
    void FUN_00559ff0();
};

// Resets the vtable pointer, clears the pointer map contents, and frees the data pointer.
// @fnv 0x00559ff0
void FUN_00559ff0_class::FUN_00559ff0()
{
    vtbl = &(*reinterpret_cast<void * *>(&::DAT_0102f468));
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(data);
}
}  // namespace fnv_00559ff0

void __cdecl operator delete(void*);
struct FUN_005407d0_Class
{
    void FUN_005409b0();
    void* FUN_005407d0(unsigned int flags);
};
struct FUN_00540800_Class
{
    void FUN_00540800();
public:
    void FUN_00537ce0();
};
struct FUN_00540a40_Class : public FUN_00540800_Class
{
    void* FUN_00540a40(unsigned int flags);
};
// Calls the base class destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00540a40
void* FUN_00540a40_Class::FUN_00540a40(unsigned int flags)
{
    FUN_00540800_Class::FUN_00540800();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00540a70 {
struct FUN_00540800_Class
{
};
struct FUN_00540a70_Class : public FUN_00540800_Class
{
    FUN_00540a70_Class* FUN_00540a70(unsigned int flags);
};
// Calls FUN_00537ce0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00540a70
FUN_00540a70_Class* FUN_00540a70_Class::FUN_00540a70(unsigned int flags)
{
    reinterpret_cast<::FUN_00540800_Class *>(this)->FUN_00537ce0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00540a70


struct FUN_00540aa0_Class : public FUN_00540a10_cls
{
    void* FUN_00540aa0(unsigned int flags);
};

// Calls FUN_00540a10, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00540aa0
void* FUN_00540aa0_Class::FUN_00540aa0(unsigned int flags)
{
    FUN_00540a10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_00554670_Class : public FUN_00554650_Class
{
    void* FUN_00554670(unsigned int flags);
};

// Calls the base cleanup, frees this object when flags has bit 0 set, and returns this.
// @fnv 0x00554670
void* FUN_00554670_Class::FUN_00554670(unsigned int flags)
{
    FUN_00554650();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00558f80
{
    void Init();
};
struct FUN_00559870_Class : public FUN_00558f80
{
    FUN_00559870_Class* InitAndMaybeFree(unsigned int flags);
};
// @fnv 0x00559870
FUN_00559870_Class* FUN_00559870_Class::InitAndMaybeFree(unsigned int flags)
{
    Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl FUN_00559080();
struct FUN_005598a0_Class
{
    void* FUN_005598a0(unsigned int flags);
};
// Calls FUN_00559080 on this, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x005598a0
void* FUN_005598a0_Class::FUN_005598a0(unsigned int flags)
{
    ((void(*)(void*))FUN_00559080)(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005598d0_Class
{
    void* FUN_005598d0(unsigned int flags);
};
// Calls FUN_00559230, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x005598d0
void* FUN_005598d0_Class::FUN_005598d0(unsigned int flags)
{
    reinterpret_cast<::fnv_00559230::FUN_00559230_class *>(this)->FUN_00559230();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005422b0Class
{
    void FUN_00559460();
    void* FUN_00559940(unsigned int flags);
public:
    void FUN_005422b0();
};
// @fnv 0x00559940
void* FUN_005422b0Class::FUN_00559940(unsigned int flags)
{
    FUN_00559460();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00559970 {
struct FUN_005422b0Class
{
    void* FUN_00559970(unsigned int flags);
};
void __cdecl operator delete(void*);
// @fnv 0x00559970
void* FUN_005422b0Class::FUN_00559970(unsigned int flags)
{
    reinterpret_cast<::FUN_005422b0Class *>(this)->FUN_005422b0();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_00559970

struct GlobalObject_00559cc0
{
    void* FUN_00559cf0(unsigned int flags);
};
// @fnv 0x00559cf0
void* GlobalObject_00559cc0::FUN_00559cf0(unsigned int flags)
{
    reinterpret_cast<::FUN_00559d90 *>((this))->FUN_00559d90::~FUN_00559d90();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_00559ff0();

struct FUN_0055a130_Class
{
    void FUN_00559ff0();
    void* FUN_0055a130(unsigned int flags);
};

// Calls FUN_00559ff0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0055a130
void* FUN_0055a130_Class::FUN_0055a130(unsigned int flags)
{
    reinterpret_cast<::fnv_00559ff0::FUN_00559ff0_class *>(this)->FUN_00559ff0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Flt
{
    int v;
    operator unsigned int();
};
struct S
{
    char _0[0xAC];
    Flt* p;
    unsigned int GetElement(int);
};
// Returns the unsigned int value stored at index a in the Flt array pointed to by p.
// @fnv 0x00540540
unsigned int S::GetElement(int aiIndex)
{
    return p[aiIndex];
}

namespace fnv_00540570 {
struct Flt
{
    int v;
    operator unsigned int();
};
struct FUN_00540570_Owner
{
    unsigned int GetFltValue(int);
};
// Returns the unsigned int value of the Flt element at index from the Flt array stored at offset 0xb0 of this object.
// @fnv 0x00540570
unsigned int FUN_00540570_Owner::GetFltValue(int index)
{
    return (*(Flt**)((char*)this + 0xb0))[index];
}
}  // namespace fnv_00540570

extern int DAT_0102e44c;
struct FUN_00540940_Standin
{
};
// Assigns the string literal "@\nT" to the object and deallocates the pointer stored at offset 4.
// @fnv 0x00540800
void FUN_00540800_Class::FUN_00540800()
{
    *(const char**)this = "@\nT";
    ::FUN_004ede70(*(void***)((char*)this + 4));
}

struct Date
{
    ~Date();
};
struct FUN_005408e0 : Date
{
    ~FUN_005408e0();
};
struct FUN_00540940_Class
{
    void* InitBuffer(unsigned int size);
};
// @fnv 0x00540780
int FUN_00540700_Class::FUN_00540780(int a)
{
    reinterpret_cast<::FUN_00540940_Class *>((((FUN_00540940_Standin*)this)))->InitBuffer(a);
    *(void**)this = (void*)&DAT_0102e44c;
    return (int)this;
}

// Sets the vtable and size, allocates size*4 bytes, zeroes them, and returns this.
// @fnv 0x00540940
void* FUN_00540940_Class::InitBuffer(unsigned int size)
{
    ((void**)this)[0] = &DAT_0102e47c;
    ((unsigned int*)this)[1] = size;
    ((unsigned int*)this)[3] = 0;
    unsigned int count = ((unsigned int*)this)[1] * 4;
    ((void**)this)[2] = ::FUN_00aa1070(count);
    ::FUN_00403d30(((void**)this)[2], 0, ((unsigned int*)this)[1] * 4);
    return this;
}

struct H_A100
{
};
struct FUN_00540c20_Class
{
};
struct FUN_00540b70_Class
{
    void* m0;
    unsigned int pad;
    unsigned int m1;
    void FUN_00540b70(void* a);
};
struct FUN_00540c20_Holder
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void vf(int, int)
    {}
    void CallVirtualWithArgs(int, int);
};
// @fnv 0x00540b70
void FUN_00540b70_Class::FUN_00540b70(void* a)
{
    reinterpret_cast<::Range62A *>(this)->DestroyRange();
    if (!(m1 & 0x80000000))
    {
        reinterpret_cast<::FUN_00540c20_Holder *>((((FUN_00540c20_Class*)a)))->CallVirtualWithArgs((int)(m0), (int)(((void *)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>((((H_A100*)this)))->GetSizeMasked()))));
    }
    m0 = 0;
    m1 = 0x80000000;
}
// Calls the virtual function vf with the two arguments and returns.
// @fnv 0x00540c20
void FUN_00540c20_Holder::CallVirtualWithArgs(int aiArg1, int aiArg2)
{
    int v = 1;
    vf(aiArg1, aiArg2);
}

// @fnv 0x00541cd0
void FUN_00541cd0()
{
    DAT_011cc54c = 0;
}

struct Sky
{
};
struct DoorH
{
};
struct FUN_00547440_Class
{
    void FUN_00547440(float f);
};
// @fnv 0x00547440
void FUN_00547440_Class::FUN_00547440(float afValue)
{
    Sky* p = ((::Sky *)(reinterpret_cast<::TESObjectCELL *>((((DoorH*)this)))->GetParentWorldSpace()));
    if (p && FUN_0040eb10(reinterpret_cast<::FUN_004536e0_Class *>((p))->GetFieldCC(), afValue, 0.001f))
        *(float*)((char*)this + 0x50) = 3.402823466e+38f;
    else
        *(float*)((char*)this + 0x50) = afValue;
}

extern int DAT_011ca080;
int __cdecl FUN_005510f0();
void __cdecl FUN_00551100(int a);
// If a is nonzero, clears DAT_011ca080 when it equals a, and calls FUN_00551100(0) when FUN_005510f0() returns a.
// @fnv 0x005510b0
void __cdecl ClearGlobalIfMatches(int aiValue)
{
    if (aiValue)
    {
        if (aiValue == DAT_011ca080)
            DAT_011ca080 = 0;
        if (FUN_005510f0() == aiValue)
            FUN_00551100(0);
    }
}

extern int DAT_011c7a60;
// @fnv 0x00551100
void FUN_00551100(int v)
{
    DAT_011c7a60 = v;
}

struct ArrSI
{
};
struct TESObjectREFR
{
};
struct FUN_005516f0_Class
{
    void SetFlag400(bool set);
};
// Reads the object's flags, sets or clears bit 0x400 based on set, and writes the flags back.
// @fnv 0x005516f0
void FUN_005516f0_Class::SetFlag400(bool set)
{
    unsigned int flags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName()));
    if (set)
        flags |= 0x400;
    else
        flags &= ~0x400;
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)this)))->AssignLandTexture((::TESLandTexture *)(flags));
}

struct MemoryManager
{
};
// If a is non-null, backs up by the size byte stored before it and deallocates the resulting block through the memory manager.
// @fnv 0x00553380
void __cdecl FUN_00553380(void* apBlock)
{
    unsigned char* p;
    if (apBlock != 0)
    {
        p = (unsigned char*)apBlock;
        p -= p[-1];
        reinterpret_cast<::FNV_MemoryManager *>((::FUN_00401020()))->FUN_00aa4060(p);
    }
}

namespace fnv_00554780 {
struct Tgt
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
};
struct Flt
{
    operator unsigned int();
};
// If g_011ca0d8 is non-null, casts it to a Tgt pointer and calls its virtual method f49.
// @fnv 0x00554780
void __cdecl CallIfPresent()
{
    if ((*reinterpret_cast<::fnv_00554780::Flt *>(&::g_011ca0d8)))
    {
        Tgt* t = (Tgt*)(unsigned int)(*reinterpret_cast<::fnv_00554780::Flt *>(&::g_011ca0d8));
        t->f49();
    }
}
}  // namespace fnv_00554780

struct ExtraDataList
{
    void FUN_00554960(bool);
    bool FUN_00554910();
};
// @fnv 0x00554910
bool ExtraDataList::FUN_00554910()
{
    bool result = false;
    {
        void* master = reinterpret_cast<::FUN_004543c0_cls *>(this)->FUN_004543c0();
        if (master)
        {
            result = !FUN_004bae00((char const*)master);
            FUN_00554960(result);
        }
    }
    return result;
}

struct FUN_00421a40_class
{
    float GetExtraFloatValue();
};
struct TESTopicInfo
{
};
class NiPoint3;
struct TESObjectCELL_Ext : public TESObjectCELL
{
    float FUN_00555ad0();
public:
    void FUN_00555b10(const ::NiPoint3 &, ::NiPoint3 &, bool);
};
// Returns 0.0f for exterior cells, otherwise the value from GetPrompt()->GetExtraFloatValue() when the cell is interior.
// @fnv 0x00555ad0
float TESObjectCELL_Ext::FUN_00555ad0()
{
    float result = 0.0f;
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
        result = ((FUN_00421a40_class*)((::FUN_00421a40_class *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESTopicInfo*)this)))->GetExtraDataList())))->GetExtraFloatValue();
    return result;
}

struct S_base_558690
{
    char p[0x1c];
};
struct S_ref_558690
{
    char x[0x0c];
};
struct FUN_00558690 : S_base_558690
{
    S_ref_558690 m1;
    S_ref_558690 m2;
    FUN_00558690();
};
// Initializes the base object and then constructs both member references m1 and m2.
// @fnv 0x00558690
FUN_00558690::FUN_00558690()
{
    new ((void *)this) ::FUN_00557d50();
    new ((void *)&(m1)) ::Vec3();
    new ((void *)&(m2)) ::Vec3();
}

struct Helper62d0
{
    int v;
    void* operator=(void const*);
};
struct FUN_00559900_Struct
{
    Helper62d0 m0;
    Helper62d0 m4;
    char m8;
    FUN_00559900_Struct& AssignFrom(FUN_00559900_Struct const&);
};
// @fnv 0x00559900
FUN_00559900_Struct& FUN_00559900_Struct::AssignFrom(FUN_00559900_Struct const& aOther)
{
    m0 = &aOther.m0;
    m4 = &aOther.m4;
    m8 = aOther.m8;
    return *this;
}

struct FUN_005596a0
{
    virtual ~FUN_005596a0();
    void* DestroyAndFreeIfFlagged(unsigned int);
};
// Runs the destructor, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x005599a0
void* FUN_005596a0::DestroyAndFreeIfFlagged(unsigned int flags)
{
    reinterpret_cast<::fnv_005596a0::FUN_005596a0 *>((this))->fnv_005596a0::FUN_005596a0::~FUN_005596a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005596e0
{
    virtual ~FUN_005596e0();
    void* FUN_005599d0(unsigned int);
};
// Runs the destructor, then frees this with _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x005599d0
void* FUN_005596e0::FUN_005599d0(unsigned int flags)
{
    this->FUN_005596e0::~FUN_005596e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Fills count elements of dest with the single value pointed to by src.
// @fnv 0x00559a00
void __cdecl CopyRepeatedValue(int* dest, int count, int* src)
{
    for (int i = 0; i < count; i++)
        dest[i] = *src;
}

struct FUN_00559a70_Class
{
    void* head;
    void* tail;
    int count;
    void FUN_00559a70(void* block);
};
// Links block into the list after tail, updating head when the list was empty, then increments count.
// @fnv 0x00559a70
void FUN_00559a70_Class::FUN_00559a70(void* block)
{
    ((void**)block)[0] = 0;
    ((void**)block)[1] = tail;
    if (tail)
        ((void**)tail)[0] = block;
    else
        head = block;
    tail = block;
    ++count;
}

struct Unk6b
{
};
struct FUN_00559c90_Class
{
    char _0[8];
    Unk6b unk8;
    void FUN_00559c90(void*);
};
// Sets the int at offset 8 of a1 to 0, then calls unk8.FreeMemory(a1).
// @fnv 0x00559c90
void FUN_00559c90_Class::FUN_00559c90(void* a1)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(a1) + 8) = 0;
    reinterpret_cast<::FUN_006b8310_class *>(&(unk8))->FreeMemory(a1);
}

namespace fnv_00559d20 {
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

struct FUN_00559d20_Class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00559d20_Class* InitArray(int n);
};

// Sets the vtable, stores the element count, allocates count*4 bytes for data and zeroes it.
// @fnv 0x00559d20
FUN_00559d20_Class* FUN_00559d20_Class::InitArray(int aiCount)
{
    *reinterpret_cast<void**>(this) = &DAT_0102f428;
    count = aiCount;
    pad = 0;
    unsigned int size = count * 4;
    data = ::FUN_00aa1070(size);
    memset(data, 0, count * 4);
    return this;
}
}  // namespace fnv_00559d20

struct FUN_00559df0
{
    virtual ~FUN_00559df0();
    void* FUN_00559e20(unsigned int flags);
};
// Calls the destructor and, when flags has bit 0 set, frees the object with operator delete; returns this.
// @fnv 0x00559e20
void* FUN_00559df0::FUN_00559e20(unsigned int flags)
{
    reinterpret_cast<::fnv_00559df0::FUN_00559df0 *>((this))->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct AnimIdle
{
    unsigned int m_uiRefCount;
    void* m_pObject;
    void IncRefCount();
    unsigned int DecRefCount();
};
struct BSFaceGenModelExtraData
{
    unsigned int m_uiRefCount;
    void* m_pObject;
    void IncRefCount();
    unsigned int DecRefCount();
};
struct FUN_0055a0c0
{
    NiPointer<AnimIdle> a;
    NiPointer<BSFaceGenModelExtraData> b;
    char c;
    FUN_0055a0c0(int);
};
// @fnv 0x0055a0c0
FUN_0055a0c0::FUN_0055a0c0(int)
{
    c = 0;
}

struct FUN_0055a240_Obj
{
};
struct FUN_0055a1e0_Class
{
    void FUN_0055a1e0(FUN_0055a240_Obj*);
};
// Returns true for the listed type codes (0x3a-0x40, 0x42, 0x43, 0x69) and false otherwise.
// @fnv 0x005548a0
bool __cdecl FUN_005548a0(unsigned char type)
{
    switch (type)
    {
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x69:
        return true;
    default:
        return false;
    }
}

extern int DAT_011f9fc8;
extern int DAT_011f9fcc;
extern int DAT_011f9fd0;
extern int DAT_011f9fd4;
extern int DAT_011f9fd8;
extern int DAT_011f9fdc;
extern int DAT_011f9fe0;
extern int DAT_011f9fe4;
extern int DAT_011f9fe8;
extern int DAT_011f9fec;
extern int DAT_011f9ff0;

struct FUN_00558600_Class
{
    void FUN_00558600(int* a, int* b, int* c, int* d, int* e, int* f, int* g, int* h, int* i, int* j,
                                 int* k);
};

// Writes eleven global values from DAT_011f9fc8 through DAT_011f9ff0 into the eleven output pointers.
// @fnv 0x00558600
void FUN_00558600_Class::FUN_00558600(int* a, int* b, int* c, int* d, int* e, int* f, int* g, int* h, int* i,
                                                 int* j, int* k)
{
    *a = DAT_011f9fc8;
    *b = DAT_011f9fcc;
    *c = DAT_011f9fd8;
    *d = DAT_011f9fdc;
    *e = DAT_011f9fe0;
    *f = DAT_011f9fe4;
    *g = DAT_011f9fd0;
    *h = DAT_011f9fd4;
    *i = DAT_011f9fe8;
    *j = DAT_011f9ff0;
    *k = DAT_011f9fec;
}

void* __cdecl operator new(unsigned int);
extern int DAT_0102f3e8;
struct FUN_00559b40
{
    int* vtbl;
    int count;
    int* data;
    int pad;
    FUN_00559b40* Init(int n);
};
// Sets the vtable, stores n in count, and if n is nonzero allocates count*4 bytes into data and zeroes them.
// @fnv 0x00559b40
FUN_00559b40* FUN_00559b40::Init(int aiCount)
{
    int* pAlloc;
    int size;
    vtbl = &DAT_0102f3e8;
    count = aiCount;
    pad = 0;
    if (aiCount)
    {
        size = count * 4;
        pAlloc = (int*)::FUN_00401000(size);
        data = pAlloc;
        std::memset(data, 0, count * 4);
    }
    return this;
}

struct FUN_0055a040_Class
{
    void* m0;
    void* m1;
    FUN_0055a2b0_Class m2;
    void FUN_0055a040(FUN_0055a240_Obj* a);
};
// Constructs a temporary FUN_0055a0c0 with 0, passes it to a's AssignFrom at offset 8, then calls FUN_0055a1e0 on this+12 with a.
// @fnv 0x0055a040
void FUN_0055a040_Class::FUN_0055a040(FUN_0055a240_Obj* a)
{
    {
        FUN_0055a0c0 t(0);
        ((FUN_00559900_Struct*)((char*)a + 8))->AssignFrom(*(FUN_00559900_Struct*)&t);
    }
    ((FUN_0055a1e0_Class*)((char*)this + 12))->FUN_0055a1e0(a);
}

struct ActorCombatGroup;
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short size);
};
extern int $SG6448;

struct FUN_00540b00_Class
{
    int* vtbl;
    ActorCombatGroup** p;
    unsigned short w8;
    unsigned short a;
    unsigned short c;
    unsigned short b;
    FUN_00540b00_Class(unsigned short x, unsigned short y);
};
// Calls FUN_00540b00 with the two arguments, sets vtbl to "p\nT", and returns this.
// @fnv 0x00540830
FUN_00540830_class* FUN_00540830_class::FUN_00540830(int aiArg1, int aiArg2)
{
    new ((void *)this) ::FUN_00540b00_Class(aiArg1, aiArg2);
    vtbl = "p\nT";
    return this;
}

// @fnv 0x00540b00
FUN_00540b00_Class::FUN_00540b00_Class(unsigned short ausSize, unsigned short y)
{
    vtbl = (int*)&$SG6448;
    w8 = ausSize;
    b = y;
    a = 0;
    c = 0;
    if (w8 > 0)
        p = NiTMallocInterface_0096afc0::Allocate(w8);
    else
        p = 0;
}

struct TESObjectCONT;
struct BGSPerkEntry;
struct BSSimpleList_551110
{
};
struct FUN_009604f0_shell
{
    BSSimpleList_551110* FUN_009604f0();
};
struct TESObject
{
};
struct FUN_00551110_Cell : public TESObjectCELL
{
    BSSimpleList_551110* FUN_009604f0();
    BGSPerkEntry* FUN_00551110();
};
// Locks cell refs, walks the list from FUN_009604f0 and returns the first entry whose GetNext equals DAT_011c3f40, then unlocks.
// @fnv 0x00551110
BGSPerkEntry* FUN_00551110_Cell::FUN_00551110()
{
    BGSPerkEntry* result2 = 0;
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    BSSimpleList_551110* list = FUN_009604f0();
    while (list)
    {
        BGSPerkEntry* entry = *((::BGSPerkEntry **)(new ((void *)(list)) ::Vec3()));
        if (entry && ((::TESObjectCONT *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<TESObject*>(entry)))->FUN_007af430())) == ::DAT_011c3f40)
        {
            result2 = entry;
            break;
        }
        list = ((::BSSimpleList_551110 *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
    return result2;
}

struct P03MM
{
};
// @fnv 0x00553320
char* __cdecl FUN_00553320(unsigned char count, unsigned int size)
{
    char* ptr = (char*)reinterpret_cast<::MemoryManagerStandIn *>((((P03MM*)::FUN_00401020())))->FUN_00aa3e40(count + size);
    unsigned char len = (unsigned char)((count - 1) & (unsigned int)ptr);
    len = count - len;
    ptr += len;
    ptr[-1] = len;
    return ptr;
}

namespace fnv_00559ad0 {
struct ActorCombatGroup;
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_00559ad0_Class
{
    void* vtbl;
    ActorCombatGroup** p;
    unsigned short count;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short m0e;
    FUN_00559ad0_Class(unsigned short a, unsigned short b);
};
// Sets the vtable, stores the two counts, zeroes the other fields, and allocates an array of count pointers or null when count is zero.
// @fnv 0x00559ad0
FUN_00559ad0_Class::FUN_00559ad0_Class(unsigned short ausCount, unsigned short b)
{
    vtbl = &::DAT_0102f3b8;
    count = ausCount;
    m0e = b;
    m0a = 0;
    m0c = 0;
    if (count > 0)
        p = NiTMallocInterface_0096afc0::Allocate(count);
    else
        p = 0;
}
}  // namespace fnv_00559ad0

__declspec(thread) char g_tls_00551680[0x25e];

// @fnv 0x00551680
char __cdecl FUN_00551680()
{
    return (*reinterpret_cast<char (*)[606]>(&::g_tlsBlock))[0x25d];
}

__declspec(thread) bool g_tlsValue;

// @fnv 0x005516a0
void __cdecl FUN_005516a0(bool value)
{
    g_tlsValue = value;
}

struct FUN_00556850_Class
{
    bool IsFlagSet();
};
// @fnv 0x00556850
bool FUN_00556850_Class::IsFlagSet()
{
    return (((unsigned char*)this)[0x25] & 1) ? true : false;
}

struct FUN_0054acf0_Class
{
};
struct FUN_0055a270_Class
{
    void* m0;
    void* m1;
    FUN_0054acf0_Class inner;
    void* FUN_0055a270();
};
// @fnv 0x0055a220
FUN_0055a220::FUN_0055a220()
{
    reinterpret_cast<::FUN_0055a270_Class *>(this)->FUN_0055a270();
}
// @fnv 0x0055a270
void* FUN_0055a270_Class::FUN_0055a270()
{
    new ((void *)&(inner)) ::fnv_0054acf0::FUN_0054acf0();
    return this;
}

struct RefObj_5405a0
{
    unsigned int m_uiRefCount;
    void IncRefCount();
    unsigned int DecRefCount();
};

struct NiPoint2
{
    float x;
    float y;
    NiPoint2();
    NiPoint2(float fx, float fy);
};

struct Entry_5405a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Entry_5405a0();
    ~Entry_5405a0();
};

struct Quad_5405a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};


struct FUN_005405a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    NiPointer<RefObj_5405a0> spObject14;
    NiPoint2 kBounds18;
    int values20[4];
    Quad_5405a0 unk30;
    Quad_5405a0 unk40;
    int unk50;
    Entry_5405a0 entries54[4];
    NiPointer<RefObj_5405a0> spObject94;
    int unk98;
    int unk9C;
    float unkA0;
    FUN_005405a0();
};

// @fnv 0x005405a0
FUN_005405a0::FUN_005405a0()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    unk0C = 0;
    unk10 = 0;
    spObject14 = 0;
    kBounds18 = NiPoint2(3.402823466e+38f, DAT_01015f5c);
    for (int i = 0; i < 4; i++)
        values20[i] = DAT_011c9f04;
    ::FUN_00403d30(&unk30, 0, sizeof(unk30));
    ::FUN_00403d30(&unk40, 0, sizeof(unk40));
    unk50 = 0;
    unkA0 = 0.0f;
}

struct __declspec(align(1)) FUN_004a4840_Class
{
    char value;
    int FUN_004a4840(int arg);
};

struct FUN_00540860_Class
{
};

struct FUN_00540750_Class : public FUN_00540860_Class
{
    void FUN_00540750(int arg);
};

struct B40AD0Helper
{
    void* Get(void* pvOwner);
};

class B40AD0Owner
{
  public:
    void FUN_00540ad0();
};
// @fnv 0x005408e0
FUN_005408e0::~FUN_005408e0()
{
    reinterpret_cast<::B40AD0Owner *>(this)->FUN_00540ad0();
}

// Calls Apply with the pointer returned by B40AD0Helper::Get for this object.
// @fnv 0x00540ad0
void B40AD0Owner::FUN_00540ad0()
{
    reinterpret_cast<::FUN_00540b70_Class *>(this)->FUN_00540b70(B40AD0Helper().Get(this));
}

struct C540BC0Allocator;


class C540BC0Array
{
  public:
    void ReserveCapacity(C540BC0Allocator& kAlloc, int n);

    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// reserve
// Grows the array to hold at least n elements, doubling the current capacity or using n if larger, via C540BC0Reserve.
// @fnv 0x00540bc0
void C540BC0Array::ReserveCapacity(C540BC0Allocator& kAlloc, int aiMinElements)
{
    int capacity = ((int)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>(this)->GetSizeMasked()));
    if (capacity < aiMinElements)
    {
        int iDoubledCapacity = 2 * capacity;
        int iNewCapacity = (aiMinElements < iDoubledCapacity) ? iDoubledCapacity : aiMinElements;
        ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewCapacity, sizeof(char));
    }
}


// @fnv 0x0054ee60
void __cdecl FUN_0054ee60(char value)
{
    ((unsigned char *)(::FUN_00664840(true)))[0x18] = value;
}

extern int DAT_011c7a60;

// @fnv 0x005510f0
int __cdecl FUN_005510f0()
{
    return DAT_011c7a60;
}

struct S_005545f0_Base
{
    int unk00;
    int unk04;
    int unk08;
    ~S_005545f0_Base();
};

struct S_005545f0_Member
{
    int unk00;
    ~S_005545f0_Member();
};

struct FUN_005545f0 : S_005545f0_Base
{
    S_005545f0_Member m_0c;
    ~FUN_005545f0();
};
// @fnv 0x005545d0
void FUN_005545d0_Class::FUN_005545d0()
{
    reinterpret_cast<::FUN_005545f0 *>(this)->FUN_005545f0::~FUN_005545f0();
}

// Destructor of the object; destroys its member and base subobjects and returns.
// @fnv 0x005545f0
FUN_005545f0::~FUN_005545f0()
{}

struct VObj
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void VCall(void* a, bool flag);
};

struct CellStandin
{
};
struct ExtraStandin
{
    void SetFlagOnChildren(bool flag);
};

// @fnv 0x00554960
void ExtraDataList::FUN_00554960(bool flag)
{
    void* world = reinterpret_cast<::FUN_004543c0_cls *>((this))->FUN_004543c0();
    void* a = ((void *)(reinterpret_cast<::FUN_00545cb0_shell *>((((CellStandin*)this)))->FUN_00545cb0()));
    if (world && a)
    {
        ((VObj*)world)->VCall(a, flag);
        ((ExtraStandin*)this)->SetFlagOnChildren(flag);
        ::EnsureLightingProperty((::AVObjectEx *)(a));
    }
}

struct ObjB68;
struct Cell68
{
    Cell68* FUN_00556ef0(int a, int b, int c);
};
struct ObjB68
{
};
struct Player68
{
};

// Counts how many of the four neighbouring cells around a position pass a cell check, using the player's current cell and grid offsets.
// @fnv 0x00556870
int __cdecl FUN_00556870(float* afPosition)
{
    unsigned int outX2;
    outX2 = 0;
    Cell68* n;
    n = ((::Cell68 *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::Player68 * *>(&::_g_thePlayer))))->GetTarget()));
    if (n)
    {
        if (reinterpret_cast<::TESObjectCELL *>((n))->IsCellInterior())
        {
            int s;
            s = (FUN_00406d90(afPosition[0]) - 0x800) >> 12;
            long cy;
            int flagX;
            cy = (FUN_00406d90(afPosition[1]) - 0x800) >> 12;
            flagX = 0;
            int cellF;
            cellF = 0;
            ::WorldToCellOffset((*(const ::NiPoint3 *)(afPosition)), 1, (*(int *)(&flagX)), (*(int *)(&cellF)));
            Cell68* a;
            a = n->FUN_00556ef0(s, cy, 0);
            if (a && reinterpret_cast<::FUN_008799c0_shell *>((a))->IsValueSeen((void *)(flagX), cellF))
                outX2++;
            Cell68* flagY;
            flagY = 0;
            bool res = false;
            if (cellF == 15)
            {
                res = true;
                flagY = n->FUN_00556ef0(s, cy + 1, 0);
                if (flagY && reinterpret_cast<::FUN_008799c0_shell *>((flagY))->IsValueSeen((void *)(flagX), 0))
                    outX2 += 1;
            }
            else if (a)
            {
                if (reinterpret_cast<::FUN_008799c0_shell *>((a))->IsValueSeen((void *)(flagX), cellF + 1))
                    outX2++;
            }
            bool cnt;
            Cell68* cellY = 0;
            cnt = false;
            if (flagX == 15)
            {
                cnt = true;
                cellY = n->FUN_00556ef0(s + 1, cy, 0);
                if (cellY && reinterpret_cast<::FUN_008799c0_shell *>((cellY))->IsValueSeen((void *)(0), cellF))
                    ++outX2;
            }
            else if (a)
            {
                if (reinterpret_cast<::FUN_008799c0_shell *>((a))->IsValueSeen((void *)(flagX + 1), cellF))
                    outX2 += 1;
            }
            if (res && cnt)
            {
                Cell68* outY;
                outY = n->FUN_00556ef0(1 + s, cy + 1, 0);
                if (outY && reinterpret_cast<::FUN_008799c0_shell *>((outY))->IsValueSeen((void *)(0), 0))
                    outX2 += 1;
            }
            else if (res)
            {
                if (flagY && reinterpret_cast<::FUN_008799c0_shell *>((flagY))->IsValueSeen((void *)(1 + flagX), 0))
                    outX2 += 1;
            }
            else if (cnt)
            {
                if (cellY && reinterpret_cast<::FUN_008799c0_shell *>((cellY))->IsValueSeen((void *)(0), cellF + 1))
                    ++outX2;
            }
            else
            {
                if (a && reinterpret_cast<::FUN_008799c0_shell *>((a))->IsValueSeen((void *)(1 + flagX), 1 + cellF))
                    outX2 += 1;
            }
        }
        else
        {
            ObjB68* cellC;
            cellC = ((::ObjB68 *)(reinterpret_cast<::TESObjectCELL *>((n))->GetParentWorldSpace()));
            if (cellC)
            {
                int cellD;
                cellD = FUN_00406d90(afPosition[0]) >> 12;
                long cy2;
                cy2 = FUN_00406d90(afPosition[1]) >> 12;
                int diag;
                diag = 0;
                int j;
                j = 0;
                ::WorldToCellOffset((*(const ::NiPoint3 *)(afPosition)), 0, (*(int *)(&diag)), (*(int *)(&j)));
                Cell68* objB;
                objB = ((::Cell68 *)(reinterpret_cast<::TESWorldSpace *>((cellC))->GetCellAtGridPosition(cellD, cy2)));
                Cell68* cx2;
                cx2 = objB ? ((::Cell68 *)(reinterpret_cast<::FUN_00555bc0_shell *>((objB))->FindSeenData())) : 0;
                if ((cx2 && reinterpret_cast<::FUN_008799c0_shell *>((cx2))->IsValueSeen((void *)(diag), j)) || (objB && reinterpret_cast<::FUN_00556850_Class *>((objB))->IsFlagSet()))
                    ++outX2;
                Cell68* cellX;
                cellX = 0;
                Cell68* cellE;
                cellE = 0;
                bool flagY2;
                flagY2 = false;
                if (j == 15)
                {
                    flagY2 = true;
                    cellE = ((::Cell68 *)(reinterpret_cast<::TESWorldSpace *>((cellC))->GetCellAtGridPosition(cellD, cy2 + 1)));
                    cellX = cellE ? ((::Cell68 *)(reinterpret_cast<::FUN_00555bc0_shell *>((cellE))->FindSeenData())) : 0;
                    if ((cellX && reinterpret_cast<::FUN_008799c0_shell *>((cellX))->IsValueSeen((void *)(diag), 0)) || (cellE && reinterpret_cast<::FUN_00556850_Class *>((cellE))->IsFlagSet()))
                        ++outX2;
                }
                else
                {
                    if ((cx2 && reinterpret_cast<::FUN_008799c0_shell *>((cx2))->IsValueSeen((void *)(diag), j + 1)) || (objB && reinterpret_cast<::FUN_00556850_Class *>((objB))->IsFlagSet()))
                        ++outX2;
                }
                Cell68* mid3 = 0;
                Cell68* outX;
                outX = 0;
                bool parent;
                parent = false;
                if (diag == 15)
                {
                    parent = true;
                    outX = ((::Cell68 *)(reinterpret_cast<::TESWorldSpace *>((cellC))->GetCellAtGridPosition(cellD + 1, cy2)));
                    mid3 = outX ? ((::Cell68 *)(reinterpret_cast<::FUN_00555bc0_shell *>((outX))->FindSeenData())) : 0;
                    if ((mid3 && reinterpret_cast<::FUN_008799c0_shell *>((mid3))->IsValueSeen((void *)(0), j)) || (outX && reinterpret_cast<::FUN_00556850_Class *>((outX))->IsFlagSet()))
                        outX2 += 1;
                }
                else
                {
                    if ((cx2 && reinterpret_cast<::FUN_008799c0_shell *>((cx2))->IsValueSeen((void *)(diag + 1), j)) || (objB && reinterpret_cast<::FUN_00556850_Class *>((objB))->IsFlagSet()))
                        ++outX2;
                }
                if (flagY2 && parent)
                {
                    n = ((::Cell68 *)(reinterpret_cast<::TESWorldSpace *>((cellC))->GetCellAtGridPosition(cellD + 1, 1 + cy2)));
                    Cell68* count;
                    count = n ? ((::Cell68 *)(reinterpret_cast<::FUN_00555bc0_shell *>((n))->FindSeenData())) : 0;
                    if ((count && reinterpret_cast<::FUN_008799c0_shell *>((count))->IsValueSeen((void *)(0), 0)) || (n && reinterpret_cast<::FUN_00556850_Class *>((n))->IsFlagSet()))
                        outX2 += 1;
                }
                else if (flagY2)
                {
                    if ((cellX && reinterpret_cast<::FUN_008799c0_shell *>((cellX))->IsValueSeen((void *)(diag + 1), 0)) || (cellE && reinterpret_cast<::FUN_00556850_Class *>((cellE))->IsFlagSet()))
                        ++outX2;
                }
                else if (parent)
                {
                    if ((mid3 && reinterpret_cast<::FUN_008799c0_shell *>((mid3))->IsValueSeen((void *)(0), j + 1)) || (outX && reinterpret_cast<::FUN_00556850_Class *>((outX))->IsFlagSet()))
                        outX2++;
                }
                else
                {
                    if ((cx2 && reinterpret_cast<::FUN_008799c0_shell *>((cx2))->IsValueSeen((void *)(1 + diag), 1 + j)) || (objB && reinterpret_cast<::FUN_00556850_Class *>((objB))->IsFlagSet()))
                        outX2 += 1;
                }
            }
        }
    }
    return outX2;
}

struct FUN_005570b0_shell
{
    bool IsSet();
};

// @fnv 0x005570b0
bool FUN_005570b0_shell::IsSet()
{
    return *reinterpret_cast<volatile int*>(this) != 0;
}

struct ItemNode
{
    ItemNode* m0;
    int m4;
    FUN_00559900_Struct m8;
};

class FUN_005593a0_cls
{
  public:
    virtual void unk0();
    virtual int unk1(int v);
    unsigned int m_uiItemCount;
    ItemNode** m_data;
    void FUN_005593a0(ItemNode** a1, int* a2, FUN_00559900_Struct* a3);
};

// @fnv 0x005593a0
void FUN_005593a0_cls::FUN_005593a0(ItemNode** apNode, int* piValue, FUN_00559900_Struct* apStruct)
{
    ItemNode* node = *apNode;
    *piValue = node->m4;
    apStruct->AssignFrom(node->m8);
    if (node->m0 != 0)
    {
        *apNode = node->m0;
        return;
    }
    unsigned int i = unk1(node->m4);
    for (i++; i < m_uiItemCount; i++)
    {
        node = m_data[i];
        if (node != 0)
        {
            *apNode = node;
            return;
        }
    }
    *apNode = 0;
}


// Sets the object's vtable pointer to DAT_0102f3b8 and calls FUN_004ede70 on the int at offset 4.
// @fnv 0x00559460
void FUN_005422b0Class::FUN_00559460()
{
    *(int*)this = (int)&DAT_0102f3b8;
    ::FUN_004ede70((void *)(*(int*)((char*)this + 4)));
}

struct FUN_00559bc0_node
{
    FUN_00559bc0_node* m_next;
};

class FUN_00559bc0_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(FUN_00559bc0_node* node);

    unsigned int m_04;
    FUN_00559bc0_node** m_08;
    unsigned int m_0c;

    void FUN_00559bc0();
};

// Calls v10 on every node in each of the m_04 buckets of m_08, then resets m_0c to 0.
// @fnv 0x00559bc0
void FUN_00559bc0_cls::FUN_00559bc0()
{
    for (unsigned int i = 0; i < m_04; i++)
    {
        FUN_00559bc0_node* node = m_08[i];
        while (node != 0)
        {
            v10(node);
            node = node->m_next;
        }
    }
    m_0c = 0;
}

struct Vec12
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    ~Vec12();
};

struct Sub
{
    unsigned int m_00;
};

struct Obj
{
    unsigned int m_00;
    unsigned int m_04;
    Sub m_08;
};

struct FUN_00559f20_cls
{
    void SetValueAndHelper(Obj* p, unsigned int v, Vec12 s);
};

// Stores v into p->m_04 and calls p->m_08.Helper with s.
// @fnv 0x00559f20
void FUN_00559f20_cls::SetValueAndHelper(Obj* pObj, unsigned int uiValue, Vec12 vecArg)
{
    pObj->m_04 = uiValue;
    reinterpret_cast<::FUN_00559900_Struct *>(&(pObj->m_08))->AssignFrom((const ::FUN_00559900_Struct &)(vecArg));
}

// The target allocates 0x14 bytes.  These five unknown fields
// preserve the object layout until the constructor's fields are identified.
struct RuntimeWorkItem : FUN_0055a220
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
};

struct RuntimeWorkItemFactory
{
    RuntimeWorkItem* CreateRuntimeWorkItem();
};
// @fnv 0x0055a020
void FUN_0055a020_Class::FUN_0055a020()
{
    reinterpret_cast<::RuntimeWorkItemFactory *>((((FUN_0055a020_Class*)((char*)this + 0xc))))->CreateRuntimeWorkItem();
}

// Allocates and returns a new RuntimeWorkItem instance.
// @fnv 0x0055a160
RuntimeWorkItem* RuntimeWorkItemFactory::CreateRuntimeWorkItem()
{
    return new RuntimeWorkItem;
}

extern void(* DAT_00fdf07c)(void*);

struct FUN_0055a2d0_Class
{
    void* unk00;
    void* m_pSecondPointer;

    void FUN_0055a2d0();
};

// @fnv 0x0055a2d0
void FUN_0055a2d0_Class::FUN_0055a2d0()
{
    DAT_00fdf07c(this->m_pSecondPointer);
}

struct ContainerType
{
    unsigned char FUN_00401170();
};
struct ExtraListType
{
};
struct ItemRef
{
    void FUN_00574b30(ItemRef*, int, int, int);
};
struct ItemList
{
};
struct FUN_005512f0_shell
{
    ItemList* FUN_009604f0();
    void FUN_005512f0(ItemRef*);
};
// @fnv 0x005512f0
void FUN_005512f0_shell::FUN_005512f0(ItemRef* dest)
{
    if (dest && ((::ContainerType *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((dest))->FUN_007af430())) == (ContainerType*)::DAT_011c3f40)
    {
        reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
        ItemList* list = FUN_009604f0();
        while (list)
        {
            ItemRef* item = *((::ItemRef **)(new ((void *)(list)) ::Vec3()));
            if (item && !reinterpret_cast<::FUN_00440d80_shell *>((item))->FUN_00440d80() && !reinterpret_cast<::TESForm *>((item))->GetDisabled())
            {
                bool allowed = false;
                unsigned char type = ((::ContainerType *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((item))->FUN_007af430()))->FUN_00401170();
                switch (type)
                {
                case 30: {
                    ContainerType* container = ((::ContainerType *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((item))->FUN_007af430()));
                    if (reinterpret_cast<::FUN_0046f070_shell *>((container))->FUN_0046f070())
                        allowed = true;
                    break;
                }
                default:
                    allowed = ::TESContainer::IsValidContainerType(type);
                    break;
                }
                if (allowed)
                {
                    dest->FUN_00574b30(item, reinterpret_cast<::FUN_00418770_shell *>((((::ExtraListType *)(reinterpret_cast<::FUN_005d43c0_ *>((item))->FUN_005d43c0()))))->FUN_00418770(), 0, 0);
                    reinterpret_cast<::FUN_00572230_shell *>((item))->FUN_00572230();
                }
            }
            list = ((::ItemList *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)this);
    }
}

namespace CellLighting {
struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3(float, float, float);
};
struct Vec2
{
    float x, y;
    Vec2(float, float);
};
struct Setting
{
};
struct LightData
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
    static void* operator new(unsigned int);
    LightData();
};
struct Extras
{
};
struct Cell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void MarkChanged(unsigned int);
    LightData* FUN_00556ef0(int, int, bool);
    void UpdateLightingAtPoint(const Vec3*);
};
// @fnv 0x00555f60
void Cell::UpdateLightingAtPoint(const Vec3* apPoint)
{
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        Vec3 point = *apPoint;
        if (reinterpret_cast<::TESObjectCELL_Ext *>(this)->FUN_00555ad0() != 0.0)
        {
            reinterpret_cast<::TESObjectCELL_Ext *>(this)->FUN_00555b10((*(const ::NiPoint3 *)(apPoint)), (*(::NiPoint3 *)(&point)), true);
            Vec3 centers3[9];
            LightData* lights[9];
            ::FUN_00403d30(lights, 0, 36);
            ::FUN_00403d30(centers3, 0, 108);
            int x = (::FUN_00406d90(point.x) - 2048) >> 12;
            int y = (::FUN_00406d90(point.y) - 2048) >> 12;
            int count3 = 0;
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    lights[count3] = FUN_00556ef0(x + dx, y + dy, true);
                    centers3[count3] = Vec3(((x + dx) << 12) + 2048, ((y + dy) << 12) + 2048, point.z);
                    count3++;
                }
            }
            for (int i = 0; i < 9; i++)
            {
                if (lights[i])
                    reinterpret_cast<::SeenData_S *>((lights[i]))->HasEnoughSeenPoints((*(const ::NiPoint3 *)(&point)), (*(const ::NiPoint3 *)(&centers3[i])));
                else
                    break;
            }
        }
        else
        {
            Vec3 centers2[4];
            LightData* lights2[4];
            ::FUN_00403d30(lights2, 0, 16);
            ::FUN_00403d30(centers2, 0, 48);
            int x2 = (::FUN_00406d90(point.x) - 2048) >> 12;
            int y2 = (::FUN_00406d90(point.y) - 2048) >> 12;
            lights2[0] = FUN_00556ef0(x2, y2, true);
            centers2[0] = Vec3((x2 << 12) + 2048, (y2 << 12) + 2048, point.z);
            Vec2 lowerA((x2 << 12) + 2048, (y2 << 12) + 2048);
            Vec2 upper2(((x2 + 4096) << 12) + 2048, ((y2 + 4096) << 12) + 2048);
            int dx2 = 0;
            int dy2 = 0;
            if (lowerA.x >= point.x - *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellLighting::Setting *>(&::originalRuntimeFloatSetting37)))))))
                dx2 = -1;
            else if (upper2.x <= point.x + *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellLighting::Setting *>(&::originalRuntimeFloatSetting37)))))))
                dx2 = 1;
            if (lowerA.y >= point.y - *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellLighting::Setting *>(&::originalRuntimeFloatSetting37)))))))
                dy2 = -1;
            else if (upper2.y <= point.y + *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CellLighting::Setting *>(&::originalRuntimeFloatSetting37)))))))
                dy2 = 1;
            int count9 = 1;
            if (dx2)
            {
                centers2[count9] = Vec3(((x2 + dx2) << 12) + 2048, (y2 << 12) + 2048, point.z);
                lights2[count9] = FUN_00556ef0(x2 + dx2, y2, true);
                count9++;
            }
            if (dy2)
            {
                centers2[count9] = Vec3((x2 << 12) + 2048, ((y2 + dy2) << 12) + 2048, point.z);
                lights2[count9] = FUN_00556ef0(x2, y2 + dy2, true);
                count9++;
            }
            if (dx2 && dy2)
            {
                centers2[count9] = Vec3(((x2 + dx2) << 12) + 2048, ((y2 + dy2) << 12) + 2048, point.z);
                lights2[count9] = FUN_00556ef0(x2 + dx2, y2 + dy2, true);
                count9++;
            }
            for (int j = 0; j < 4; j++)
            {
                if (lights2[j])
                    reinterpret_cast<::SeenData_S *>((lights2[j]))->HasEnoughSeenPoints((*(const ::NiPoint3 *)(&point)), (*(const ::NiPoint3 *)(&centers2[j])));
                else
                    break;
            }
        }
    }
    else
    {
        if (reinterpret_cast<::FUN_00556850_Class *>(this)->IsFlagSet())
            return;
        LightData* light = ((::CellLighting::LightData *)(reinterpret_cast<::FUN_00555bc0_shell *>(this)->FindSeenData()));
        if (!light)
        {
            light = new LightData();
            reinterpret_cast<::extra421::E4List *>((((::CellLighting::Extras *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00421940((::extra421::E4Object *)(light));
            MarkChanged(0x80000000);
        }
        Vec3 center2(reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridX() << 12, reinterpret_cast<::TESObjectCELL *>(this)->GetCellGridY() << 12, apPoint->z);
        bool changed = reinterpret_cast<::SeenData_S *>((light))->HasEnoughSeenPoints((*(const ::NiPoint3 *)(apPoint)), (*(const ::NiPoint3 *)(&center2)));
        if (changed)
        {
            reinterpret_cast<::FUN_00555be0_stub *>(this)->FUN_00555be0();
            reinterpret_cast<::FUN_00544440_Class *>(this)->FUN_00544440(true);
        }
    }
}
}

struct SeenData
{
    virtual void v00();
    unsigned int field_04, field_08, field_0c, field_10, field_14, field_18, field_1c, field_20;
};
struct IntSeenData : SeenData
{
    signed char field_24, field_25;
    unsigned short field_26;
    IntSeenData* field_28;
    IntSeenData(unsigned char, unsigned char);
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct Result556ef0
{
};
struct Target556ef0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(unsigned int);
    IntSeenData* FUN_00556ef0(int a, int b, bool create);
};
// Searches the linked list from FUN_00555bc0 for a node matching a and b, appending a new IntSeenData when create is set and none matches.
// @fnv 0x00556ef0
IntSeenData* Target556ef0::FUN_00556ef0(int a, int b, bool create)
{
    IntSeenData* node = 0;
    if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
    {
        node = dynamic_cast<IntSeenData*>(reinterpret_cast<::FUN_00555bc0_shell *>(this)->FindSeenData());
        IntSeenData* previous = 0;
        while (node)
        {
            if (node->field_24 == a && node->field_25 == b)
                break;
            previous = node;
            node = node->field_28;
        }
        if (!node && create)
        {
            if (previous)
            {
                previous->field_28 = new IntSeenData((unsigned char)a, (unsigned char)b);
                node = previous->field_28;
            }
            else
            {
                node = new IntSeenData((unsigned char)a, (unsigned char)b);
                reinterpret_cast<::extra421::E4List *>((((::Result556ef0 *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00421940((::extra421::E4Object *)(node));
                v48(0x80000000);
            }
        }
    }
    return node;
}

struct CleanupBase559810
{
    ~CleanupBase559810();
};
struct FUN_00559810 : CleanupBase559810
{
    ~FUN_00559810();
};
// @fnv 0x00559810
FUN_00559810::~FUN_00559810()
{
    reinterpret_cast<::NiTPointerListBase *>(this)->FUN_00559c30();
}

struct FUN_00559eb0
{
    int vtbl;
    int count;
    void* data;
    int flags;
    FUN_00559eb0(int arg);
};
// Calls FUN_00559eb0 with arg, sets p to point at DAT_0102f448, and returns this.
// @fnv 0x00559e50
FUN_00559e50_Class* FUN_00559e50_Class::InitializeWithGlobal(int arg)
{
    new ((void *)this) ::FUN_00559eb0(arg);
    p = &DAT_0102f448;
    return this;
}
// Sets the vtable, stores arg as count, zeroes flags, allocates count*4 bytes and clears them.
// @fnv 0x00559eb0
FUN_00559eb0::FUN_00559eb0(int aiCount)
{
    *(int*)this = (int)&DAT_0102f468;
    this->count = aiCount;
    this->flags = 0;
    unsigned int byteCount = (unsigned int)(this->count << 2);
    this->data = ::FUN_00aa1070(byteCount);
    ::FUN_00403d30(this->data, 0, (unsigned int)(this->count << 2));
}

class GlobalObject_00a7b610;

class NiAVObject
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual int v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188(bool flag);
};

class NiAVObject;
class NiNode : public NiAVObject
{
  public:
    unsigned int FUN_0043b480();
public:
    ::NiAVObject *GetAt(unsigned int);
};

struct FUN_0054a050_shell
{
    NiNode* FUN_0054a050();
};

struct FUN_00456fc0_cls
{
};


// @fnv 0x00554a20
void ExtraStandin::SetFlagOnChildren(bool flag)
{
    NiNode* node7 = reinterpret_cast<FUN_0054a050_shell*>(this)->FUN_0054a050();
    unsigned int count = node7->FUN_0043b480();
    while (count--)
    {
        NiAVObject* child = node7->GetAt(count);
        NiAVObject* obj2 = ((::NiAVObject *)(::FUN_0056f930(child)));
        if (obj2 != 0)
        {
            obj2->v188(flag);
        }
    }
    NiNode* list3 = ((::NiNode *)(reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<FUN_00456fc0_cls*>(this)))->GetCellChildAt(7)));
    for (unsigned int i3 = 0; i3 < list3->FUN_0043b480(); i3++)
    {
        NiAVObject* itemB = list3->GetAt(i3);
        if (itemB != 0)
        {
            if (!(itemB->v005() || ::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(::GlobalObject_00a7b610 *)(&g_01202828), (const ::fnv_0045bad0::NiObject *)(itemB))))
            {
                continue;
            }
            NiNode* _sub = static_cast<NiNode*>(itemB);
            for (unsigned int j6 = 0; j6 < _sub->FUN_0043b480(); j6++)
            {
                itemB = _sub->GetAt(j6);
                if (itemB != 0)
                {
                    NiAVObject* oX = ((::NiAVObject *)(::FUN_0056f930(itemB)));
                    if (oX->v064())
                    {
                        NiAVObject* o2 = oX;
                        o2->v188(flag);
                    }
                }
            }
        }
    }
}

class FUN_00540a10
{
  public:
    virtual ~FUN_00540a10();

};

class FUN_005409b0 : public FUN_00540a10
{
  public:
    virtual ~FUN_005409b0();
};
// Calls FUN_005409b0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x005407d0
void* FUN_005407d0_Class::FUN_005407d0(unsigned int flags)
{
    reinterpret_cast<::FUN_005409b0 *>(this)->FUN_005409b0::~FUN_005409b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for FUN_005409b0 that calls FUN_00438af0 before returning.
// @fnv 0x005409b0
FUN_005409b0::~FUN_005409b0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct BaseFQ
{
    int FUN_00401170();
};
struct HndQ
{
    virtual void v0(), v1();
    virtual void Handle(void* p);
};
struct ObjQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v0a(), v0b(), v0c(), v0d(),
        v0e(), v0f(), v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(), v18(), v19(), v1a(), v1b(), v1c(), v1d(),
        v1e(), v1f(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v2a(), v2b(), v2c(), v2d(),
        v2e(), v2f(), v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v3a(), v3b(), v3c(), v3d(),
        v3e(), v3f();
    virtual HndQ* GetHandlerQ();
};
struct RefQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v0a(), v0b(), v0c(), v0d(),
        v0e(), v0f(), v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(), v18(), v19(), v1a(), v1b(), v1c(), v1d(),
        v1e(), v1f(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v2a(), v2b(), v2c(), v2d(),
        v2e(), v2f(), v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v3a(), v3b(), v3c(), v3d(),
        v3e(), v3f(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v4a(), v4b(), v4c(), v4d(),
        v4e(), v4f(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v5a(), v5b(), v5c(), v5d(),
        v5e(), v5f(), v60(), v61(), v62(), v63(), v64(), v65(), v66(), v67(), v68(), v69(), v6a(), v6b(), v6c(), v6d(),
        v6e(), v6f(), v70(), v71(), v72(), v73();
    virtual ObjQ* Get3DQ();
};
struct LstQ
{
};
struct CellQ
{
    LstQ* FUN_009604f0();
    void FUN_005570d0();
};
// For each list entry with FUN_005651e0 false, FUN_00401170 equal to 0x25 and a Get3DQ() object, calls that object's GetHandlerQ()->Handle(obj).
// @fnv 0x005570d0
void CellQ::FUN_005570d0()
{
    reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
    LstQ* pIter = FUN_009604f0();
    while (pIter)
    {
        RefQ* pRef = *((::RefQ **)(new ((void *)(pIter)) ::Vec3()));
        if (pRef && !reinterpret_cast<::FUN_005651e0_shell *>((pRef))->FUN_005651e0() && ((::BaseFQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430()))->FUN_00401170() == 0x25 && pRef->Get3DQ())
        {
            ObjQ* pObj = pRef->Get3DQ();
            pObj->GetHandlerQ()->Handle(pObj);
        }
        pIter = ((::LstQ *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}

class MapBase559F90
{
  public:
    virtual ~MapBase559F90();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    void RemoveAll();
};
class FUN_00559f90 : public MapBase559F90
{
  public:
    virtual ~FUN_00559f90();
};

// Destructor that calls RemoveAll.
// @fnv 0x00559f90
FUN_00559f90::~FUN_00559f90()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct Sweep540
{
    int m0;
    int m4;
    void SetSize(int a, int b);
};
// @fnv 0x00540750
void FUN_00540750_Class::FUN_00540750(int aiValue)
{
    FUN_004a4840_Class local = {};
    reinterpret_cast<::Sweep540 *>((this))->SetSize(local.FUN_004a4840((int)this), aiValue);
}
struct Tag540
{
};

// Calls ReserveCapacity(a, b), runs FUN_0040fbe0 on the ranges between m4 and b, then sets m4 to b.
// @fnv 0x00540860
void Sweep540::SetSize(int a, int b)
{
    reinterpret_cast<::C540BC0Array *>(this)->ReserveCapacity((*(::C540BC0Allocator *)(a)), b);
    ::FUN_0040fbe0();
    ::FUN_0040fbe0();
    m4 = b;
}

struct GlobalObject_00559e50
{
    ~GlobalObject_00559e50();
};
struct FUN_00559e80 : GlobalObject_00559e50
{
    virtual ~FUN_00559e80();
};
// @fnv 0x00559e80
FUN_00559e80::~FUN_00559e80()
{}

struct FUN_0055a240_Class : public FUN_0055a290_Class
{
    void* FUN_0055a240(unsigned int flags);
};
// If the passed object pointer is non-null, calls its FUN_0055a240 method with 1.
// @fnv 0x0055a1e0
void FUN_0055a1e0_Class::FUN_0055a1e0(FUN_0055a240_Obj* pObj)
{
    FUN_0055a240_Obj* m = pObj;
    FUN_0055a240_Obj* n = m;
    n ? ((int)(reinterpret_cast<::FUN_0055a240_Class *>((n))->FUN_0055a240(1))) : 0;
}
// Calls FUN_0055a290, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0055a240
void* FUN_0055a240_Class::FUN_0055a240(unsigned int flags)
{
    FUN_0055a290();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
