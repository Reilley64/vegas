
// src/gamebryo2.2/corelibs/nimain/nipalette_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nipalette.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/nipalette.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nipalette.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstdint>
#include "fnv/decl/FUN_00aa42c0_class.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00aa6c70_shell.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_011f6000.h"
void* __cdecl FUN_00a8b070();

// MemoryManager::FUN_00aa4060 - release a block that was handed out by one
// of the manager's heaps.
//
// The pointer is looked up in a 256 entry page table (one entry per 16 MB of
// the address space).  When the entry belongs to a pool that really owns the
// block the pool frees it, otherwise the owning heap is asked first and the
// plain free() is the last resort.

// One entry of the page table: the base of the pool and its size.
struct FNV_Pool
{
    int unk00;
    unsigned int m_base;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    unsigned int m_iElementCount;
};

// The page table: 256 entries, one per 16 MB page of the address space.

// The heap that owns a block.  The block is handed to the fourth slot.
struct FNV_Heap
{
    virtual void FNV_heapUnknown0();
    virtual void FNV_heapUnknown1();
    virtual void FNV_heapUnknown2();
    virtual void FNV_heapRelease(void* block, int flag);
};

// The memory manager itself.
struct FNV_MemoryManager
{
    unsigned char m_bEnableState;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    void* m_pHeap;


    void FUN_00aa4060(void* block);
};

// @fnv 0x00aa4060
void FNV_MemoryManager::FUN_00aa4060(void* block)
{
    if (!block)
        return;

    if (!this->m_bEnableState)
    {
        reinterpret_cast<::FUN_00aa42c0_class *>((this))->FreePointer(block, 0);
        return;
    }

    void* pHeapMgr = this->m_pHeap;
    if (!pHeapMgr)
    {
        reinterpret_cast<::FUN_00aa42c0_class *>((this))->FreePointer(block, 0);
        return;
    }

    FNV_Pool* poolObj = (*reinterpret_cast<FNV_Pool * (*)[256]>(&::ms_pPoolAddressMap))[((uintptr_t)block) >> 24];
    if (poolObj)
    {
        if ((unsigned char)(((uintptr_t)block >= poolObj->m_base) &&
                                    ((uintptr_t)block < (unsigned int)(poolObj->m_base + poolObj->m_iElementCount))
                                ? 1
                                : 0))
        {
            reinterpret_cast<::FUN_00aa6c70_shell *>((poolObj))->FUN_00aa6c70(block);
            return;
        }
    }

    FNV_Heap* owner = ((::FNV_Heap *)(reinterpret_cast<::FUN_00aa45a0_Class *>((this))->FindItemByArg((intptr_t)(block))));
    if (owner)
    {
        owner->FNV_heapRelease(block, 0);
        return;
    }

    reinterpret_cast<::FUN_00aa42c0_class *>((this))->FreePointer(block, 0);
}
