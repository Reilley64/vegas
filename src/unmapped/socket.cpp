
// src/unmapped/socket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/remotelog/socket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_0044a000.h"
struct MorphName
{
    char const* GetMorphName();
};
// @fnv 0x0044a380
char const* MorphName::GetMorphName()
{
    return ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)(reinterpret_cast<MorphName*>(reinterpret_cast<char*>(this) + 0xc)));
}

// The std::string layout of the original runtime: the text sits in the 16-byte buffer until the capacity reaches 16, then in a heap block the buffer's first word points to.
struct StringStorageAca1e0
{
    int m_alloc;
    union
    {
        char* m_pHeap;
        char m_acBuffer[16];
    };
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
};

struct FUN_00aca1e0
{
    char pad00[0xc];
    StringStorageAca1e0 m_kName;
    void* GetPointer();
};
// @fnv 0x00aca1e0
void* FUN_00aca1e0::GetPointer()
{
    StringStorageAca1e0* p = &m_kName;
    return p->m_uiCapacity >= 16 ? (void*)p->m_pHeap : (void*)p->m_acBuffer;
}
