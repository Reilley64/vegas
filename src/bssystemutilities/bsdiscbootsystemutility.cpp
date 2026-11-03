// bssystemutilities/bsdiscbootsystemutility.cpp: BSDiscBootSystemUtility (3 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00af3a80_Class.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "bsdiscbootsystemutility_local.h"

typedef void(* DestroyFn)(BSDiscBootSystemUtility*);

extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

// @fnv 0x00af3ae0
void BSDiscBootSystemUtility::Destroy()
{}

// @fnv 0x00af3aa0
void BSDiscBootSystemUtility::Initialize(const char* titleID, unsigned int parentalLevel)
{
    ((DestroyFn)m_ppVirtualMethodTable[2])(this);
    if (titleID)
    {
        strcpy_s(m_acTitleID, 0x40, titleID);
    }
    m_uiParentalLevel = parentalLevel;
}

struct MemoryManager
{
};
struct FUN_00af3af0_Class
{
    void* FUN_00af3af0(unsigned int);
};
// @fnv 0x00af3af0
void* FUN_00af3af0_Class::FUN_00af3af0(unsigned int flags)
{
    reinterpret_cast<::FUN_00af3a80_Class *>(this)->InitPointer();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
