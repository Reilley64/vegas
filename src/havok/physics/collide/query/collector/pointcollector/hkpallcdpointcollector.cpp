
// src/havok/physics/collide/query/collector/pointcollector/hkpallcdpointcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/pointcollector/hkpallcdpointcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c90000.h"
struct FUN_00caba90_array
{
    void* data;
    unsigned int count;
    unsigned int capacity;
};
struct FUN_006212c0_shell
{
    void* FUN_006212c0(void* source);
};
struct FUN_00caba90_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00caba90_array array;
    void* AppendItem(void* source);
};
// @fnv 0x00caba90
void* FUN_00caba90_Class::AppendItem(void* source)
{
    FUN_00caba90_array* items = &array;
    hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
    if (items->count == (items->capacity & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(&heap), (::AudioStream *)(items), 0x70);
    }
    unsigned int index = items->count;
    char* item = (char*)items->data + index * 0x70;
    items->count = index + 1;
    return ((FUN_006212c0_shell*)item)->FUN_006212c0(source);
}

struct ByteTag
{
    char m_cValue;

    ByteTag() : m_cValue(0)
    {}

    ~ByteTag()
    {}
};

void __cdecl FUN_009b2ed0(void* apData, int aiFirst, int aiLast, ByteTag akTag);

struct SortableArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pData;
    int m_iArrayLength;

    void FUN_00cabad0();
};

// @fnv 0x00cabad0
void SortableArray::FUN_00cabad0()
{
    ByteTag kTag;
    if (m_iArrayLength > 1)
        FUN_009b2ed0(m_pData, 0, m_iArrayLength - 1, kTag);
}

#include <xmmintrin.h>
struct S_00cab970_Vec
{
    __m128 q;
};
struct S_00cab970_Cd
{
    int unk00;
    unsigned int key;
    int unk08;
    S_00cab970_Cd* parent;
};
struct S_00cab970_Src
{
    S_00cab970_Vec a;
    S_00cab970_Vec b;
    S_00cab970_Cd* bodyA;
    S_00cab970_Cd* bodyB;
};
struct S_00cab970_Entry
{
    S_00cab970_Vec a;
    S_00cab970_Vec b;
    S_00cab970_Cd* rootA;
    unsigned int keyA;
    unsigned int keysA[8];
    S_00cab970_Cd* rootB;
    unsigned int keyB;
    unsigned int keysB[8];
};
struct S_00cab970_Arr;
struct S_00cab970_Arr
{
    S_00cab970_Entry* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline S_00cab970_Entry& AllocatePair()
    {
        hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(&heap), (::AudioStream *)(::S_00cab970_Arr *)(this), sizeof(S_00cab970_Entry));
        return m_data[m_iElementCount++];
    }
};
__forceinline void S_00cab970_Path(S_00cab970_Cd* const volatile& body, S_00cab970_Cd*& rootOut, unsigned int& keyOut,
                                   unsigned int* keys)
{
    S_00cab970_Cd* root = body;
    while (root->parent)
        root = root->parent;
    rootOut = root;
    keyOut = body->key;
    int depth = 0;
    S_00cab970_Cd* p = body->parent;
    while (p)
    {
        depth++;
        p = p->parent;
    }
    int n = depth;
    S_00cab970_Cd* c = body;
    keys[n--] = 0xffffffff;
    if (n >= 0)
    {
        unsigned int* k = keys + n;
        do
        {
            *k = c->key;
            c = c->parent;
            --n;
            --k;
        } while (n >= 0);
    }
}
struct S_00cab970_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cab970_Arr arr;
    void FUN_00cab970(const S_00cab970_Src* src);
};
// Allocates an entry in arr, copies the two vectors from src, and records the root, key, and key path for each body via S_00cab970_Path.
// @fnv 0x00cab970
void S_00cab970_Cls::FUN_00cab970(const S_00cab970_Src* src)
{
    S_00cab970_Entry& entry = arr.AllocatePair();
    entry.a.q = src->a.q;
    entry.b.q = src->b.q;
    S_00cab970_Path(src->bodyA, entry.rootA, entry.keyA, entry.keysA);
    S_00cab970_Path(src->bodyB, entry.rootB, entry.keyB, entry.keysB);
}
