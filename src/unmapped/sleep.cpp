
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "fnv/decl/FUN_0078d200_cls.h"
class RecursiveSpinLock
{
};

struct FUN_008691b0
{
    char pad00[0x20];
    RecursiveSpinLock m_kLock;
    void Lock();
};

// @fnv 0x008691b0
void FUN_008691b0::Lock()
{
    reinterpret_cast<::FUN_0078d200_cls *>(&m_kLock)->FUN_0078d200();
}

// @fnv 0x0040fca0
void FUN_0040fca0(unsigned long ms)
{
    Sleep(ms);
}
