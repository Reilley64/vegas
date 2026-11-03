// bssystemutilities/bssysinfosystemutility.cpp: BSSysInfoSystemUtility (3 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00af3b50_Class.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "BSSysInfoSystemUtility.h"

// @fnv 0x00af3b70
void BSSysInfoSystemUtility::Initialize()
{}

// @fnv 0x00af3b80
void BSSysInfoSystemUtility::Destroy()
{
    m_eLanguage = BSSysInfoSystemUtility__LANGUAGE_LANGUAGE_UNKNOWN;
}

struct MemoryManager
{
};
MemoryManager g_memoryManager;

struct FUN_00af3b50_holder
{
};

struct FUN_00af3ba0_shell
{
    void* FUN_00af3ba0(unsigned int flags);
};

// @fnv 0x00af3ba0
void* FUN_00af3ba0_shell::FUN_00af3ba0(unsigned int flags)
{
    reinterpret_cast<::FUN_00af3b50_Class *>((((FUN_00af3b50_holder*)this)))->SetVTable();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
