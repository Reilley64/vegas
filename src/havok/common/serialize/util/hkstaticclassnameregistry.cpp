
// src/havok/common/serialize/util/hkstaticclassnameregistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkstaticclassnameregistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00db7a80_Class.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
struct SlotEntry
{
    int unk00;
};


struct FUN_00db7ae0_cls
{
    int unk00;
    int unk04;
    int unk08;
    SlotEntry** m_slots;

    SlotEntry* FindSlotByKey(void* p);
};

// Resets the slot table, then scans m_slots for the first entry whose Key matches p via MatchSlotKey and returns it, or 0 if none match.
// @fnv 0x00db7ae0
SlotEntry* FUN_00db7ae0_cls::FindSlotByKey(void* apKey)
{
    reinterpret_cast<::FUN_00db7a80_Class *>(this)->EnsureInitialized();
    int i = 0;
    if (m_slots[i] != 0)
    {
        do
        {
            SlotEntry* key = ((::SlotEntry *)(reinterpret_cast<::FnvClassNameNode *>((m_slots[i]))->FUN_00d46d40()));
            if (::fnv_00cb0fa0::FUN_00cb0fa0((const char *)(apKey), (const char *)(key)) == 0)
            {
                return m_slots[i];
            }
            i++;
        } while (m_slots[i] != 0);
    }
    return 0;
}

struct FUN_00db7b40
{
    virtual void v0();
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00db7b40(int a, int b, int c);
};
// Initializes the object: sets unk06 to 1, stores a, b and c into unk0c, unk10 and unk08, and clears unk14.
// @fnv 0x00db7b40
FUN_00db7b40::FUN_00db7b40(int aiValue1, int aiValue2, int aiValue3)
{
    unk06 = 1;
    unk0c = aiValue1;
    unk10 = aiValue2;
    unk14 = 0;
    unk08 = aiValue3;
}

struct FUN_00db7b70_Array
{
    void** data;
    int count;
    int capacity;
};

struct FUN_00c85750_Obj
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
};

struct FUN_00db7b70_Class
{
    int unk00;
    int unk04;
    int unk08;
    void** unk0c;
    int unk10;
    int unk14;
    void AppendToArray(FUN_00db7b70_Array* p);
};


// Appends the null-terminated pointer list in unk0c to the array p, growing its capacity via the memory manager when needed.
// @fnv 0x00db7b70
void FUN_00db7b70_Class::AppendToArray(FUN_00db7b70_Array* apArray)
{
    reinterpret_cast<::FUN_00db7a80_Class *>((this))->EnsureInitialized();

    int count = 0;
    while (this->unk0c[count] != 0)
        count++;

    FUN_00c85750_Obj* tls = (FUN_00c85750_Obj*)FUN_00c85750();
    void* memmgr = tls->unk10;
    int oldCount = apArray->count;
    int iCapacity = apArray->capacity;
    int iNeeded = count + oldCount;
    iCapacity &= 0x3fffffff;
    if (iCapacity < iNeeded)
    {
        int iNewCapacity = (iNeeded >= iCapacity * 2) ? iNeeded : iCapacity * 2;
        ::FUN_00c908c0((::SpawnedObject *)(memmgr), (::SpawnedArray *)(apArray), iNewCapacity, 4);
    }
    apArray->count += count;

    void** ppDest = apArray->data + oldCount;
    for (int i = 0; this->unk0c[i] != 0; i++)
        ppDest[i] = this->unk0c[i];
}

struct FnvCpu_FUN_00db7a70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int FUN_00db7a70();
};
// @fnv 0x00db7a70
int FnvCpu_FUN_00db7a70_CpuObject::FUN_00db7a70()
{
    return value;
}
