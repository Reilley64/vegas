
// src/havok/common/base/monitor/hkmonitorstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/monitor/hkmonitorstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_01268000.h"
struct S_00cb0da0
{
    int m_00;
    int m_04;
};

// @fnv 0x00cb0da0
void FUN_00cb0da0(S_00cb0da0* p)
{
    p->m_04 = p->m_00;
}

// ResizeBuffer - grow/shrink a spawned byte buffer through the audio allocator.
//
// The buffer keeps four pointers and a flag:
//   +0x00  m_00  start of the allocation
//   +0x04  m_04  current write position
//   +0x08  m_08  end of the allocation
//   +0x0c  m_0c  end - 0x20 (the reserved tail)
//   +0x10  m_10  "the allocation is live" flag
//
// FUN_00c85750 hands back the thread's audio system; its +0x14 member is the
// byte allocator whose virtual 4 allocates (through an in/out size) and whose
// virtual 5 releases a block.

struct ByteAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* Alloc(unsigned int* count);
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    ByteAllocator* m_14;
};

struct SpawnedBuffer
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    unsigned char m_10;
};


// @fnv 0x00cb0e50
void ResizeBuffer(SpawnedBuffer* pBuffer, int iSize)
{
    char* begin = pBuffer->m_00;
    char* end = pBuffer->m_08;
    if (iSize == (int)(pBuffer->m_08 - pBuffer->m_00))
    {
        return;
    }
    if (iSize > 0)
    {
        if (begin != 0 && pBuffer->m_10 != 0)
        {
            AllocHolder* h = (AllocHolder*)static_cast<char*>(::FUN_00c85750());
            h->m_14->Free(begin, end - begin);
        }
        pBuffer->m_10 = 1;
        AllocHolder* h2 = (AllocHolder*)static_cast<char*>(::FUN_00c85750());
        ByteAllocator* pAllocator = h2->m_14;
        {
            unsigned int count = iSize;
            char* p = (char*)pAllocator->Alloc(&count);
            pBuffer->m_00 = p;
            pBuffer->m_04 = p;
            pBuffer->m_08 = p + count;
            pBuffer->m_0c = p + count - 0x20;
        }
    }
    else
    {
        ::fnv_00cb0df0::FUN_00cb0df0((::fnv_00cb0df0::GrowBuffer *)(pBuffer));
    }
}

#include <windows.h>
namespace fnv_00cb0db0 {

class SpawnedAllocator
{
  public:
    virtual void vSlot0();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    SpawnedAllocator* m_14;
};


struct SpawnedObject
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char m_10;
};

// Allocates a SpawnedObject via the AllocHolder's SpawnedAllocator, stores it in TLS, and zeroes its fields.
// @fnv 0x00cb0db0
void __cdecl FUN_00cb0db0()
{
    AllocHolder* holder = static_cast<AllocHolder*>(::FUN_00c85750());
    SpawnedAllocator* alloc = holder->m_14;
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x14);
    TlsSetValue(::DAT_0126835c, obj);
    obj->m_10 = 0;
    obj->m_00 = 0;
    obj->m_08 = 0;
    obj->m_04 = 0;
    obj->m_0c = 0;
}
}  // namespace fnv_00cb0db0

namespace fnv_00cb0df0 {

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize);
};

struct AudioHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    AudioAllocator* m_pAllocator;
};


struct GrowBuffer
{
    char* m_pBegin;
    char* m_pCurrent;
    char* m_pRecordEnd;
    char* m_pReadData;
    char m_bOwned;
};

// Frees the owned record buffer and the TLS audio holder block, then clears the TLS slot.
// @fnv 0x00cb0df0
void __cdecl FUN_00cb0df0(GrowBuffer* apBuffer)
{
    void* pThreadData = TlsGetValue(::DAT_0126835c);

    char* pBegin = apBuffer->m_pBegin;
    if (pBegin != 0 && apBuffer->m_bOwned != 0)
    {
        char* pEnd = apBuffer->m_pRecordEnd;
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->FreeArray(pBegin, (int)(pEnd - pBegin));
    }

    AudioHolder* pHolder2 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    pAllocator2->Free(pThreadData, 0x14);

    TlsSetValue(::DAT_0126835c, 0);
}
}  // namespace fnv_00cb0df0
