
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_011f6000.h"
extern int DAT_010a48e8;
struct MMgr
{
};
struct BSTaskletGroupData
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Sets the object's vtable pointer to DAT_010a48e8 and, if flags has bit 1 set, deallocates the object via g_memoryManager, returning this.
// @fnv 0x00b029c0
void* BSTaskletGroupData::DestroyIfFlagged(unsigned int flags)
{
    *(void**)this = (void*)&DAT_010a48e8;
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MMgr *>(&::g_memoryManager))))->FUN_00aa4060((void*)this);
    return (void*)this;
}
