
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/decl/FUN_00e69970_shell.h"
#include "fnv/decl/FUN_00e89840_Class.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0126f000.h"
struct NiD3DShaderProgram
{
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_00e89840, then deletes this with size 0x2c when flags has bit 1 set, and returns this.
// @fnv 0x00e898a0
void* NiD3DShaderProgram::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00e89840_Class *>(this)->FUN_00e89840();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x2c);
    return this;
}

struct NiTMapBase
{
    bool RemoveAt(char const*);
};
struct Direct3DDeviceInterface
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
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
    virtual char const* GetName();
};
struct Program
{
    char _pad[0x14];
    NiTMapBase* pkMap;
};
// If the global Program and its map exist, gets the device's name and removes that entry from the map.
// @fnv 0x00e93790
void RemoveDeviceFromMap(Direct3DDeviceInterface* pkD3DDevice)
{
    if (!DAT_0126fa10)
        return;
    if (!pkD3DDevice)
        return;
    char const* psz = pkD3DDevice->GetName();
    if (!psz)
        return;
    NiTMapBase* pkM = DAT_0126fa10->pkMap;
    if (!pkM)
        return;
    pkM->RemoveAt(psz);
}

extern int DAT_010f119c;
struct S
{
    void FUN_00e971d0();
    void FUN_00e89b70();
};
struct ComObj
{
    virtual void F0();
    virtual void F1();
    virtual void __stdcall Release();
};
// Sets the vtable, frees the two pointers at offsets 0x3C and 0x40, releases and clears the ComObj at 0x44, then calls FUN_00e89b70.
// @fnv 0x00e971d0
void S::FUN_00e971d0()
{
    void* v1 = *(void**)((char*)this + 0x3C);
    *(void**)this = (void*)&DAT_010f119c;
    ::FUN_00aa10f0(v1);
    ::FUN_00aa10f0(*(void**)((char*)this + 0x40));
    ComObj* p = *(ComObj**)((char*)this + 0x44);
    if (p)
    {
        p->Release();
        *(ComObj**)((char*)this + 0x44) = 0;
    }
    FUN_00e89b70();
}

__declspec(noinline) void RemoveDeviceFromMap(Direct3DDeviceInterface*);
extern int DAT_010ef87c;

struct FUN_00e69970_class
{
};

// Sets the vtable, removes this device from the map, calls FUN_00e69970 when offset 0x34 is nonzero using the pointer at 0x24, then calls FUN_00e89840.
// @fnv 0x00e89b70
__declspec(noinline) void S::FUN_00e89b70()
{
    char* self = (char*)this;
    *(void**)self = (void*)&DAT_010ef87c;
    RemoveDeviceFromMap((Direct3DDeviceInterface*)this);
    if (*(void**)(self + 0x34) != 0)
    {
        reinterpret_cast<::FUN_00e69970_shell *>((((FUN_00e69970_class*)*(void**)(self + 0x24))))->ClearShader(this);
    }
    reinterpret_cast<::FUN_00e89840_Class *>((((NiD3DShaderProgram*)this)))->FUN_00e89840();
}
