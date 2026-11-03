
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_011f6000.h"
extern int DAT_010a48ac;
struct MemoryManager
{
};
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct BSTaskletManager
{
    int _00;
    int _04;
    int _08;
    void* _0c;
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x00b02780
void* __thiscall BSTaskletManager::Destroy(unsigned int flags)
{
    *(int*)this = (int)&DAT_010a48ac;
    CloseHandle(_0c);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
