// bssystemutilities/bssavedatasystemutility.cpp: BSSaveDataSystemUtility, TargetClass (4 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00af2f20_Class.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "BSSaveDataSystemUtility.h"

// @fnv 0x00af2f60
void BSSaveDataSystemUtility::Destroy()
{
    m_pOperationContext = 0;
}

struct FUN_00af2f40_shell : public BSSaveDataSystemUtility
{
    void CallVTableMethod();
};

struct VTableHelper
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

// @fnv 0x00af2f40
void FUN_00af2f40_shell::CallVTableMethod()
{
    reinterpret_cast<VTableHelper*>(this)->v2();
}

class MemoryManager
{
  public:
};
struct TargetClass
{
    void* FUN_00af2fc0(unsigned int flags);
};
// @fnv 0x00af2fc0
void* TargetClass::FUN_00af2fc0(unsigned int flags)
{
    reinterpret_cast<::FUN_00af2f20_Class *>(this)->FUN_00af2f20();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00af2ff0_Holder
{
    bool FUN_00af2ff0(const char* a, void* b);
};
// @fnv 0x00af2ff0
bool FUN_00af2ff0_Holder::FUN_00af2ff0(const char* a, void* b)
{
    return false;
}
