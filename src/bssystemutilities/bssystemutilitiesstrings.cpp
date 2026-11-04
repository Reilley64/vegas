// bssystemutilities/bssystemutilitiesstrings.cpp: BSSystemUtilitiesStrings (4 functions)

#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00af35c0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "bssystemutilitiesstrings.h"

// Frees each of the 8 stored string pointers via g_memoryManager.Deallocate and clears the slots.
// @fnv 0x00af3680
void BSSystemUtilitiesStrings::Destroy()
{
    for (unsigned int i = 0; i < 8; ++i)
    {
        if (m_pStringFunctions[i])
        {
            void* ptr = m_pStringFunctions[i];
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(ptr);
            m_pStringFunctions[i] = 0;
        }
    }
}

struct FUN_00af3660_shell : public BSSystemUtilitiesStrings
{
    void CallVTableMethod();
};

struct VTableHelper_00af3660
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

// @fnv 0x00af3660
void FUN_00af3660_shell::CallVTableMethod()
{
    reinterpret_cast<VTableHelper_00af3660*>(this)->v2();
}

struct FUN_00af37a0_Owner
{
    void* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x00af37a0
void* FUN_00af37a0_Owner::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00af35c0_Class *>(this)->FUN_00af35c0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct P03MM : public MemoryManager
{
};


struct FUN_00af36e0_shell
{
    char pad[4];
    char* m_pStringFunctions[1];

    void SetStringAt(unsigned int index, const char* str);
};

// Frees the string stored at the given index, then allocates and copies a new copy of str into that slot if str is non-null.
// @fnv 0x00af36e0
void FUN_00af36e0_shell::SetStringAt(unsigned int index, const char* pcStr)
{
    unsigned int len;
    if (m_pStringFunctions[index])
    {
        void* pOldString = m_pStringFunctions[index];
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa4060(pOldString);
        m_pStringFunctions[index] = 0;
    }
    if (pcStr)
    {
        len = std::strlen(pcStr) + 1;
        void* pAllocated = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(len);
        m_pStringFunctions[index] = (char*)pAllocated;
        void* pZeroed = m_pStringFunctions[index];
        std::memset(pZeroed, 0, len);
        void* pNewString = m_pStringFunctions[index];
        fnv::crt::strcpy_s((char*)pNewString, len, pcStr);
    }
}

#include "generated/data/bssystemutilities/bssystemutilitiesstrings.inc"
