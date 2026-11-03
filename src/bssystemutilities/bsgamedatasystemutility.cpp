// bssystemutilities/bsgamedatasystemutility.cpp: BSGameDataSystemUtility (3 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00af39c0_Class.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "BSGameDataSystemUtility.h"

// @fnv 0x00af3a00
void BSGameDataSystemUtility::Destroy()
{}

struct FUN_00af39e0_shell : public BSGameDataSystemUtility
{
    void CallVirtualMethod2();
};

namespace {
struct VTable
{
    void* f0;
    void* f1;
    void(__thiscall* f2)(void*);
};
struct Obj
{
    VTable* vt;
};
}

// @fnv 0x00af39e0
void FUN_00af39e0_shell::CallVirtualMethod2()
{
    reinterpret_cast<Obj*>(this)->vt->f2(this);
}

struct MemoryManager
{
};
struct FUN_00af3a10_Class
{
    void* FUN_00af3a10(unsigned int);
};
// @fnv 0x00af3a10
void* FUN_00af3a10_Class::FUN_00af3a10(unsigned int flags)
{
    reinterpret_cast<::FUN_00af39c0_Class *>(this)->FUN_00af39c0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
