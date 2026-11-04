
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_011f6000.h"
extern int DAT_010a48ac;
struct MemoryManager
{
};
struct BSTaskletManager
{
    const void* pVtable;
    int _04;
    int _08;
    void* _0c;
    void* Destroy(unsigned int);
};
// @fnv 0x00b02780
void* BSTaskletManager::Destroy(unsigned int flags)
{
    pVtable = &DAT_010a48ac;
    CloseHandle(_0c);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
