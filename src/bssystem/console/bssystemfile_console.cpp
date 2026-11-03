
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include <cstdint>
#include "fnv/decl/FUN_00aff000_tbl.h"
#include "fnv/decl/O.h"
#include "fnv/decl/SystemFileWriter.h"
#include "fnv/decl/Win32ReadFile.h"
struct FUN_008526d0_shell
{
    int m_iWordAt00;
    int SetFromCall(std::intptr_t a, int b, int c, std::intptr_t d);
};

// @fnv 0x008526d0
int FUN_008526d0_shell::SetFromCall(std::intptr_t a, int b, int c, std::intptr_t d)
{
    m_iWordAt00 = (int)((void *)(reinterpret_cast<::Win32ReadFile *>(this)->Read((void *)(a), b, c, (unsigned long long *)(d))));
    return m_iWordAt00;
}

struct FUN_00856350_shell
{
    void* m_p;
    void* SetAndReturnPointer(void* a, void* b, void* c, void* d);
};

// Stores the result of FUN_00afede0(a, b, c, d) in m_p and returns it.
// @fnv 0x00856350
void* FUN_00856350_shell::SetAndReturnPointer(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    m_p = ((void *)(reinterpret_cast<::SystemFileWriter *>(this)->FUN_00afede0(apArg1, (unsigned long)(apArg2), (int)(apArg3), (unsigned long long *)(apArg4))));
    return m_p;
}

struct S_008785e0
{
    int field0;
    int SetAndGetField0(int a, int b, int c, int d);
};
// Stores the result of FUN_00afeef0(a, b, c, d) into field0 and returns it.
// @fnv 0x008785e0
int S_008785e0::SetAndGetField0(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    field0 = reinterpret_cast<::O *>(this)->FUN_00afeef0(aiArg1, aiArg2, (::_LARGE_INTEGER *)(aiArg3));
    return field0;
}

struct FileSizeInfo
{
    unsigned int m_eErrorCode;
    unsigned int FUN_0065c290(LARGE_INTEGER& auiSize);
};

// Stores the result of GetValue into m_eErrorCode and returns it.
// @fnv 0x0065c290
unsigned int FileSizeInfo::FUN_0065c290(LARGE_INTEGER& auiSize)
{
    m_eErrorCode = reinterpret_cast<::FUN_00aff000_tbl *>(this)->GetValue((unsigned int *)(::_LARGE_INTEGER *)(&auiSize));
    return m_eErrorCode;
}

// @fnv 0x00aff0b0
int FUN_00aff0b0(const char* apcPath)
{
    return DeleteFileA(apcPath) ? 0 : 4;
}
