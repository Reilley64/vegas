#include "havok/hkMemoryRouter.h"
#include <cstdint>
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include "fnv/symbols_011b3000.h"

// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include "fnv/decl/FUN_00d06fb0_cls.h"
// The 3-axis sweep as the axis0 candidate sweep (FUN_00d112c0) sees it; offsets are the 32-bit release's.
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
struct S_00d112c0_EndPoint {
    hkUint16 m_uiFilterValue;
    hkUint16 m_usIndex;
};
struct S_00d112c0_Node {
    hkUint16 m_min1, m_min2, m_max1, m_max2;
    hkUint16 m_min0;
    hkUint16 m_max0;
    unsigned int m_handle;
};
struct S_00d112c0_Marker {
    hkUint16 m_usIndex;
    hkUint16 unk2;
    const hkUint16* m_kNode;
    int m_uiItemCount;
    int m_iCapacityState;
};
struct S_00d112c0 {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    S_00d112c0_Node* m_kNodeCollection;
    int unka4;
    int unka8;
    S_00d112c0_EndPoint* m_ep;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int m_iMarkerCount;
    int m_markerShift;
    S_00d112c0_Marker* m_pOverlappingMarkerInfo;
    void FUN_00d112c0(int numNodes, int key, const S_00d112c0_Node* aabb, hkUint16 skip, hkUint32* bits);
};
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_00d10000.h"
#include "fnv/symbols_00d11000.h"
#include "fnv/symbols_00d13000.h"
#include "fnv/symbols_00d19000.h"
#include "fnv/symbols_00d1a000.h"
#include "fnv/symbols_00d9f000.h"
#include "fnv/symbols_010cd000.h"
#include "fnv/symbols_011b3000.h"

// @fnv 0x00d19d70
unsigned short MaxUnsignedShort(unsigned short ausLeft, unsigned short ausRight)
{
    return ausLeft > ausRight ? ausLeft : ausRight;
}

// hkp3AxisSweep::hkpBpNode: the endpoint indices, then the handle at 32-bit +0xc.
struct UnkRet { unsigned short m_endpoints[6]; void* m_handle; };
// hkpBroadPhaseHandlePair.
struct BroadPhaseHandlePairQ { void* m_a; void* m_b; };
struct BroadPhaseHandlePairArrayQ { BroadPhaseHandlePairQ* m_data; int m_size; int m_capacityAndFlags; };
// @fnv 0x00d11bc0
void AppendPairToBuffer(UnkRet* apFirst, UnkRet* apSecond, void* apBuffer)
{
    BroadPhaseHandlePairArrayQ* q = static_cast<BroadPhaseHandlePairArrayQ*>(apBuffer);
    if (q->m_size == (q->m_capacityAndFlags & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(apBuffer), sizeof(BroadPhaseHandlePairQ));
    BroadPhaseHandlePairQ* e = q->m_data + q->m_size;
    q->m_size = q->m_size + 1;
    e->m_a = apFirst->m_handle;
    e->m_b = apSecond->m_handle;
}

// @fnv 0x00d10ad0
void ToggleBit(int aiBitIndex, void* apBits)
{
    int* p = (int*)apBits;
    int idx = aiBitIndex >> 5;
    int mask = 1 << (aiBitIndex & 0x1F);
    p[idx] ^= mask;
}

struct Entry {
    unsigned short key;
    unsigned short value;
};
// Binary-searches a sorted Entry range for the first entry whose key is not less than key, returning that entry pointer.
// @fnv 0x00d10ea0
Entry* LowerBoundEntry(Entry* first, Entry* last, unsigned short key) {
    while ((((char*)last - (char*)first) & ~3) > 0x40) {
        Entry* middle = first + (((char*)last - (char*)first) >> 3);
        if (middle->key < key) first = middle;
        else last = middle;
    }
    while (first->key < key) ++first;
    return first;
}

struct FUN_00d11960_cls {
    int* m_pEntryData;
    int m_iArrayLength;
    void FUN_00d11960(int aiFirst, int aiSecond);
};

// @fnv 0x00d11960
void FUN_00d11960_cls::FUN_00d11960(int aiFirst, int aiSecond)
{
    int* p = m_pEntryData + aiFirst;
    int* pEnd = m_pEntryData + aiSecond - 1;
    while (p < pEnd) {
        p[0] = p[1];
        p++;
    }
    int iCount = m_iArrayLength;
    int* pLast = m_pEntryData + (iCount - 2);
    m_iArrayLength = iCount - 2;
    while (p < pLast) {
        p[0] = p[2];
        p++;
    }
}

namespace fnv_00d1a040 {
struct Entry { unsigned short type; unsigned short index; };
struct Container {
    Entry* entries;
    int count;
    int capacity;
    void FUN_00d1a040(char* nodes, int** remap);
};
// Remaps each entry's index through remap, drops entries with negative mapping, writes kept positions into DAT_011b37a4 tables, and grows capacity if needed.
// @fnv 0x00d1a040
void Container::FUN_00d1a040(char* nodes, int** remap) {
    Entry* src = entries;
    Entry* end = src + count;
    int kept = 0;
    Entry* dst = src;
    while (src < end) {
        int mapped = (*remap)[src->index];
        if (mapped >= 0) {
            *dst = *src;
            dst->index = (unsigned short)mapped;
            *(unsigned short*)(nodes + mapped * 16 + ::DAT_011b37a4[src->type & 1]) = (unsigned short)kept;
            ++dst;
            ++kept;
        }
        ++src;
    }
    hkMemoryAllocator* mgr = &hkMemoryRouter::getInstance().heap();
    int capacity = this->capacity & 0x3fffffff;
    if (capacity < kept) {
        int newCapacity = capacity * 2;
        if (kept >= newCapacity)
            newCapacity = kept;
        ::FUN_00c908c0((::SpawnedObject *)(mgr), (::SpawnedArray *)(void *)(this), newCapacity, 4);
    }
    count = kept;
}
}  // namespace fnv_00d1a040





struct D1A0E0Entry {
    unsigned short m_flags;
    unsigned short m_uiEdgeIndex;
};

struct D1A0E0IntArray {
    int* m_data;
    int m_iElementCount;
};

struct D1A0E0EntryArray {
    D1A0E0Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(hkMemoryAllocator *)(&alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(D1A0E0Entry));
        }
    }

    void SetSizeAndGrow(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }

    void FUN_00d1a0e0(char* nodes, const D1A0E0IntArray& remap);
};

// @fnv 0x00d1a0e0
void D1A0E0EntryArray::FUN_00d1a0e0(char* nodes, const D1A0E0IntArray& remap)
{
    D1A0E0Entry* end = m_data + m_iElementCount;
    int count = 0;
    D1A0E0Entry* dst = m_data;
    for (D1A0E0Entry* src = m_data; src < end; src++) {
        int newIndex = remap.m_data[src->m_uiEdgeIndex];
        if (newIndex >= 0) {
            *dst = *src;
            dst->m_uiEdgeIndex = (unsigned short)newIndex;
            *(unsigned short*)(nodes + newIndex * 16 + ::g_D1A0E0Tables[src->m_flags & 1]) = (unsigned short)count;
            dst++;
            count++;
        }
    }
    SetSizeAndGrow(hkMemoryRouter::getInstance().heap(), count);
}


struct S_00d1a180_ArrayUtil {
public:
    static int __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int elemSize);
};

extern int DAT_011b37b4[2];


struct S_00d1a180_HeapAllocator {
    static hkMemoryAllocator& get(const void*) { return hkMemoryRouter::getInstance().heap(); }
};

struct S_00d1a180_IntArray {
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct S_00d1a180_EndPoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
};

struct S_00d1a180_Axis {
    S_00d1a180_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void GrowArrayCapacity(hkMemoryAllocator& a, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(a), (::SpawnedArray *)(void *)(this), newSize, sizeof(S_00d1a180_EndPoint));
        }
    }

    void _setSize(hkMemoryAllocator& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }

    void SetSizeAndGrow(int n)
    {
        _setSize(S_00d1a180_HeapAllocator().get(this), n);
    }

    void RemapEndPoints(char* nodes, const S_00d1a180_IntArray& remap);
};

// @fnv 0x00d1a180
void S_00d1a180_Axis::RemapEndPoints(char* nodes, const S_00d1a180_IntArray& remap)
{
    S_00d1a180_EndPoint* end = m_data + m_iElementCount;
    int n = 0;
    S_00d1a180_EndPoint* dst = m_data;
    for (S_00d1a180_EndPoint* src = m_data; src < end; src++) {
        int newIndex = remap.m_data[src->m_usIndex];
        if (newIndex >= 0) {
            *dst = *src;
            dst->m_usIndex = (unsigned short)newIndex;
            *(unsigned short*)(nodes + (newIndex * 16 + DAT_011b37b4[src->m_uiFilterValue & 1])) = (unsigned short)n;
            dst++;
            n++;
        }
    }
    SetSizeAndGrow(n);
}

// @fnv 0x00d10af0
void FUN_00d10af0(int index, unsigned int* apuiBits)
{
    unsigned int mask = 1u << (index & 0x1f);
    unsigned int w = index >> 5;
    apuiBits[w] &= ~mask;
}

struct FUN_00d11620_cls {
    int unk00;
    int unk04;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int m_iA4;
    int FUN_00d11620();
};

// @fnv 0x00d11620
int FUN_00d11620_cls::FUN_00d11620()
{
    return m_iA4 - 1;
}

// Reconstructed source for FUN_00d119c0 (forwarding thunk, 24 bytes).
// Target shape:
//   mov edx, [esp+4]            ; handle (first stack arg)
//   mov eax, [edx]              ; handle->unk00 (entry index)
//   shl eax, 4                  ; * 16 (entry stride)
//   add eax, [ecx+0xA0]         ; + &this->entries
//   mov [esp+4], eax            ; forward as first stack arg
//   jmp FUN_00d11650            ; tail call, ecx = this preserved

struct UnkHandle {
    int unk00; // entry index read at [handle]
};

struct SweepEntry { // 16-byte entry, matches shl eax,4 stride
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

// Tail-call target observed forwarding (this, handle, entry) with edx = handle kept live:
// helper taking (self in ecx, handle in edx, entry on stack).
void FUN_00d11650(void* self, UnkHandle* handle, SweepEntry* entry);

// Stand-in owner class for the thunk; fnvcheck matches the name FUN_00d119c0.
struct FUN_00d119c0_owner {
    int unk00;
    int unk04;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    SweepEntry* unkA0; // entry array base pointer at this+0xA0

    void FUN_00d119c0(UnkHandle* handle);
};

// @fnv 0x00d119c0
void FUN_00d119c0_owner::FUN_00d119c0(UnkHandle* handle) {
    FUN_00d11650(this, handle, this->unkA0 + handle->unk00);
}


struct PairEntry {
    int m_pHeadNode;
    int m_iSecondInteger;
};

struct PairArray {
    PairEntry* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct FUN_00d11c10_cls {
    int unk00;
    int unk04;
    int unk08;
    int m_0C;
};

// Grows the pair array if full, then appends an entry holding self->m_0C and other->m_0C and increments the count.
// @fnv 0x00d11c10
void AppendPairEntry(FUN_00d11c10_cls* pFirst, FUN_00d11c10_cls* pSecond, PairArray* arr) {
    if (arr->m_iArrayLength == (int)(arr->m_uCapFlags & 0x3fffffffu)) {
        ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(arr), 8);
    }
    PairEntry* slot = arr->m_pData + arr->m_iArrayLength;
    arr->m_iArrayLength++;
    slot->m_pHeadNode = pFirst->m_0C;
    slot->m_iSecondInteger = pSecond->m_0C;
}

unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);


void AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);

struct FnvNode {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};

struct FnvArr {
    void* m_data;
    int m_uiItemCount;
    unsigned int m_cap;
};

struct FnvPair8 {
    unsigned int first;
    unsigned int second;
};


// @fnv 0x00d11c60
void FUN_00d11c60(void* base, FnvNode* pNode, unsigned short ausValue, FnvNode* pOther, FnvArr* pPairArr)
{
    if ((pOther->m_0c & 1) == 0) {
        FnvArr* arr = pPairArr;
        if ((int)arr->m_uiItemCount == (int)(arr->m_cap & 0x3fffffff)) {
            ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(arr), 8);
        }
        unsigned int idx = (unsigned int)arr->m_uiItemCount;
        FnvPair8* e = (FnvPair8*)arr->m_data + idx;
        arr->m_uiItemCount = (int)(idx + 1);
        e->first = pNode->m_0c;
        e->second = pOther->m_0c;
    } else {
        FnvArr* arr = (FnvArr*)((char*)base + (pOther->m_0c & 0xfffffffe) + 4);
        if ((int)arr->m_uiItemCount == (int)(arr->m_cap & 0x3fffffff)) {
            ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(arr), 2);
        }
        unsigned int idx = (unsigned int)arr->m_uiItemCount;
        unsigned short* e = (unsigned short*)arr->m_data + *(volatile int*)&arr->m_uiItemCount;
        *e = ausValue;
        arr->m_uiItemCount++;
    }
}

namespace fnv_00d11d00 {
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);


void AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);

struct PairEntry {
    int m_00;
    int m_04;
};

struct PairArray {
    PairEntry* m_00;
    int m_04;
    unsigned int m_08;
};


struct TagOwner {
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0c;
};

struct TagEntity {
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
};

struct TaggedList {
    int unk00;
    unsigned short* m_04;
    int m_08;
};

// @fnv 0x00d11d00
void RemoveOrAppendTagEntry(char* base, TagEntity* entity, unsigned int idx, TagOwner* owner, PairArray* arr)
{
    if ((owner->m_0c & 1) == 0) {
        if (arr->m_04 == (int)(arr->m_08 & 0x3fffffff)) {
            ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(arr), 8);
        }
        int n = arr->m_04;
        PairEntry* e = arr->m_00 + n;
        arr->m_04 = n + 1;
        e->m_00 = entity->m_0c;
        e->m_04 = owner->m_0c;
    } else {
        TaggedList* list = reinterpret_cast<TaggedList*>(base + (owner->m_0c & 0xfffffffe));
        int count = list->m_08;
        int index = 0;
        if (count > 0) {
            do {
                if (list->m_04[index] == (unsigned short)idx) {
                    goto found;
                }
                ++index;
            } while (index < count);
        }
        index = -1;
found:
        volatile int* cnt = &list->m_08;
        (*cnt)--;
        int last = list->m_08;
        if (last != index) {
            list->m_04[index] = list->m_04[last];
        }
    }
}
}  // namespace fnv_00d11d00

struct FUN_00d11da0_cls;


struct FUN_00d11da0_entry {
    unsigned short key;
    unsigned short value;
};


struct FUN_00d11da0_cls {
    FUN_00d11da0_entry* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;

    void InsertPair(const void* a1, unsigned int a2, unsigned short a3,
                      unsigned short a4, unsigned short* outIndex2, unsigned short* outIndex);
};

// @fnv 0x00d11da0
void FUN_00d11da0_cls::InsertPair(const void* auiUnused, unsigned int auiValue, unsigned short ausKey2,
                                    unsigned short ausKey1, unsigned short* pausIndex2, unsigned short* pausIndex1)
{
    int n = m_uiItemCount + 2;
    hkMemoryAllocator* allocator = &hkMemoryRouter::getInstance().heap();
    unsigned int cap = m_capFlags & 0x3fffffffu;

    if ((int)cap < n) {
        int newCap = (int)(cap + cap);
        if (n >= newCap) {
            newCap = n;
        }
        ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(::FUN_00d11da0_cls *)(this), (unsigned int)newCap, 4);
    }

    FUN_00d11da0_entry* p = m_data + (n - 3);
    m_uiItemCount = n;
    p[2] = p[0];
    p--;
    while (ausKey1 < p->key) {
        p[2] = p[0];
        p--;
    }
    while (ausKey1 == p->key && auiValue < p->value) {
        p[2] = p[0];
        p--;
    }
    p[2].key = ausKey1;
    p[2].value = (unsigned short)auiValue;
    *pausIndex1 = (unsigned short)((p - m_data) + 2);

    FUN_00d11da0_entry* q = p;
    while (ausKey2 < q->key) {
        q[1] = q[0];
        q--;
    }
    while (ausKey2 == q->key && auiValue < q->value) {
        q[1] = q[0];
        q--;
    }
    q[1].value = (unsigned short)auiValue;
    q[1].key = ausKey2;
    *pausIndex2 = (unsigned short)((q - m_data) + 1);
    (void)auiUnused;
}

struct S_00d138a0_Pair {
    uintptr_t unk00;  // handles, tagged with bit 0 for markers
    uintptr_t unk04;
};
struct S_00d138a0_Array {
    S_00d138a0_Pair* unk00;
    int unk04;
    unsigned int unk08;
};
struct S_00d138a0_Node {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    uintptr_t unk0c;  // the handle, or a marker offset with bit 0 set
};
// @fnv 0x00d138a0
void __cdecl CollectNodePairs(const void* unused, S_00d138a0_Node* node, int count, S_00d138a0_Array* out)
{
    for (--count; count > 0; --count) {
        unsigned int limit = node->unk0a;
        S_00d138a0_Node* cur = node + 1;
        for (; cur->unk08 < limit; cur++) {
            if (((cur->unk04 - node->unk00) | (node->unk04 - cur->unk00)) & 0x80008000) {
            } else if (!(cur->unk0c & 1)) {
                if (out->unk04 == (int)(out->unk08 & 0x3fffffff))
                    ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(out), 8);
                S_00d138a0_Pair* e = &out->unk00[out->unk04++];
                e->unk00 = node->unk0c;
                e->unk04 = cur->unk0c;
            }
        }
        node = node + 1;
    }
}





// Writes the smallest of v[0], v[1], v[2] to out and returns its index (0, 1 or 2).
// @fnv 0x00d19d10
int __cdecl FUN_00d19d10(const float* afValues, float* pfMin) {
    if (afValues[0] < afValues[1]) {
        if (afValues[0] < afValues[2]) {
            *pfMin = afValues[0];
            return 0;
        }
    } else if (afValues[1] < afValues[2]) {
        *pfMin = afValues[1];
        return 1;
    }
    *pfMin = afValues[2];
    return 2;
}


struct hkp3AxisSweep;

struct Endpoint {
    unsigned short value;
    unsigned short handle;
};

struct S_00d19d90_Class {
    Endpoint* m_endpoints;
    void MergeSortedEndpoints(void* pLookup, int totalCount, Endpoint* pSrc2, int count2);
};

// Merges two sorted Endpoint ranges into m_endpoints from the back, writing each endpoint's output index into pLookup at a handle-derived offset.
// @fnv 0x00d19d90
void S_00d19d90_Class::MergeSortedEndpoints(void* pLookupTable, int iDestCount, Endpoint* pSrcEndpoints, int iSrcCount)
{
    Endpoint* pSrcCursor = &pSrcEndpoints[iSrcCount - 1];
    Endpoint* pDestEndpoints = m_endpoints;
    int iOutIndex = iDestCount;
    int c = iOutIndex - iSrcCount;
    Endpoint* pDestCursor = &pDestEndpoints[c - 1];
    iSrcCount = pDestCursor->value;
    iOutIndex--;
    iDestCount = pSrcCursor->value;
    Endpoint* pOut = &pDestEndpoints[iOutIndex];
    while (true)
    {
        if (iSrcCount > iDestCount)
        {
            *pOut = *pDestCursor;
            unsigned int offset = (pDestCursor->handle << 4) + DAT_011b37a4[pDestCursor->value & 1];
            *(unsigned short*)((char*)pLookupTable + offset) = (unsigned short)iOutIndex;
            pDestCursor--;
            pOut--;
            iOutIndex--;
            iSrcCount = pDestCursor->value;
        }
        else
        {
            *pOut = *pSrcCursor;
            unsigned int offset = (pSrcCursor->handle << 4) + DAT_011b37a4[pSrcCursor->value & 1];
            *(unsigned short*)((char*)pLookupTable + offset) = (unsigned short)iOutIndex;
            pSrcCursor--;
            pOut--;
            iDestCount = pSrcCursor->value;
            iOutIndex--;
            if (pSrcCursor < pSrcEndpoints)
                break;
        }
    }
}

struct Pair {
    unsigned short key;
    unsigned short hi;
};


struct FUN_00d19ef0_cls {
    Pair* m_pItems;
    void FUN_00d19ef0(char* out, int n, Pair* src, int k);
};

// @fnv 0x00d19ef0
void FUN_00d19ef0_cls::FUN_00d19ef0(char* out, int iCount, Pair* src, int iSplit) {
    int cnt = iCount - iSplit;
    Pair* pRight = &src[iSplit - 1];
    Pair* base = m_pItems;
    Pair* pLeft = &base[cnt - 1];
    int iLeftKey = pLeft->key;
    int s2 = pRight->key;
    --iCount;
    int idx = iCount;
    Pair* pWrite = &base[idx];
    for (;;) {
        if (iLeftKey > s2) {
            *pWrite = *pLeft;
            unsigned int off = ((unsigned int)pLeft->hi << 4) + DAT_011b37b4[pLeft->key & 1];
            *(unsigned short*)(out + off) = (unsigned short)idx;
            --pLeft;
            --pWrite;
            --idx;
            iLeftKey = pLeft->key;
        } else {
            *pWrite = *pRight;
            unsigned int off = ((unsigned int)pRight->hi << 4) + DAT_011b37b4[pRight->key & 1];
            *(unsigned short*)(out + off) = (unsigned short)idx;
            --pRight;
            --pWrite;
            --idx;
            s2 = pRight->key;
            if (pRight < src) {
                break;
            }
        }
    }
}

// Recursive quicksort partition over 4-byte records keyed by (low16, high16) lexicographically.
// @fnv 0x00d19fa0
void __cdecl FUN_00d19fa0(unsigned int* auiValues, int lo, int hi, int auiUnused)
{
    for (;;) {
        int i = lo;
        int j = hi;
        __declspec(align(16)) union PivotSlot { unsigned int v; struct { unsigned short low, high; } halves; } pivot;
        pivot.v = auiValues[(i + j) >> 1];

        for (;;) {
            while ((unsigned short)auiValues[i] < (unsigned short)pivot.v
                || ((unsigned short)auiValues[i] == (unsigned short)pivot.v
                    && (unsigned short)(auiValues[i] >> 16) < (unsigned short)(pivot.v >> 16))) {
                ++i;
            }
            while ((unsigned short)pivot.v < (unsigned short)auiValues[j]
                || ((unsigned short)pivot.v == (unsigned short)auiValues[j]
                    && *(volatile unsigned short*)&pivot.halves.high < (unsigned short)(auiValues[j] >> 16))) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                unsigned int a = auiValues[i];
                unsigned int b = auiValues[j];
                auiValues[j] = a;
                auiValues[i] = b;
            }
            --j;
            ++i;
            if (i > j) {
                break;
            }
        }

        if (lo < j) {
            FUN_00d19fa0(auiValues, lo, j, auiUnused);
        }
        if (i >= hi) {
            return;
        }
        lo = i;
    }
}

// Recursive quicksort partition over 4-byte records keyed by their low 16 bits.
// @fnv 0x00d1a220
void __cdecl QuickSortByLowWord(unsigned int* auiArray, int lo, int hi, int auiUnused)
{
    for (;;) {
        int j = hi;
        int i = lo;
        unsigned int pivot = auiArray[(i + j) >> 1];

        for (;;) {
            while ((unsigned short)auiArray[i] < (unsigned short)pivot) {
                ++i;
            }
            while ((unsigned short)pivot < (unsigned short)auiArray[j]) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                __declspec(align(16)) unsigned int uiLeftValue = auiArray[i];
                unsigned int uiRightValue = auiArray[j];
                auiArray[j] = uiLeftValue;
                auiArray[i] = uiRightValue;
            }
            --j;
            ++i;
            if (i > j) {
                break;
            }
        }

        if (lo < j) {
            QuickSortByLowWord(auiArray, lo, j, auiUnused);
        }
        if (i >= hi) {
            return;
        }
        lo = i;
    }
}

// @fnv 0x00d10b10
static int __declspec(noinline) FUN_00d10b10(void* self, int index, unsigned int* apuiBits)
{
    unsigned int mask = 1u << (index & 31);
    return (int)(mask & apuiBits[index >> 5]);
}

int IsBitmapBitSet(void* table, int index, unsigned int* bits)
{
    return FUN_00d10b10(table, index, bits);
}


class FUN_00d11120_cls {
public:
    Endpoint* m_endpoints;
    void MergeEndpoints(char* cells, int n, int m,
                      unsigned int axis, Endpoint* scratch);
};

// @fnv 0x00d11120
void FUN_00d11120_cls::MergeEndpoints(char* cells, int aiCount, int aiExtraCount,
                                    unsigned int axis, Endpoint* scratch)
{
    for (int i = 0; i < aiCount; i++) {
        scratch[i] = m_endpoints[i];
    }

    Endpoint* last = scratch + 1;
    Endpoint* b = m_endpoints + aiCount;
    Endpoint* w = m_endpoints + 1;
    Endpoint* a = scratch + aiCount - 1;
    aiCount += aiExtraCount;
    Endpoint* pRightEnd = m_endpoints + aiCount;

    while (last->value < b->value) {
        last++;
        w++;
    }

    if (last < a && b < pRightEnd) {
        for (;;) {
            if (last->value < b->value || (last->value == b->value && last->handle < b->handle)) {
                *w = *last;
                unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
                *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
                last++;
                w++;
                if (last >= a) {
                    break;
                }
            } else {
                *w = *b;
                unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
                *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
                b++;
                w++;
                if (b >= pRightEnd) {
                    break;
                }
            }
        }
    }
    while (b < pRightEnd) {
        *w = *b;
        unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
        *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
        b++;
        w++;
    }
    while (last <= a) {
        *w = *last;
        unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
        *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
        last++;
        w++;
    }
}

// Adapted from an unverified prior attempt by another contributor; original author/model unknown.

struct S_d11790_Node { unsigned short m_usValue00, m_usValue02, m_usValue04, m_usValue06, m_usValue08, m_usValue0A; unsigned short unk0c, unk0e; };
struct S_d11790_Edge { unsigned short value; unsigned short handle; };

typedef unsigned short S_d11790_Node::* S_d11790_Field;

static __forceinline void S_d11790_Fix(S_d11790_Node* nodes, S_d11790_Edge* edges, S_d11790_Node* node, S_d11790_Field field, unsigned h)
{
    unsigned i = node->*field;
    S_d11790_Edge* e = edges + i;
    while (e[0].value == e[-1].value) {
        unsigned p = e[-1].handle;
        if (!(h < p)) break;
        e[0] = e[-1];
        --e;
        nodes[p].*field = i;
        --i;
    }
    e->handle = h;
    unsigned short* currentField = &(node->*field);

    *currentField = i;
}

struct S_d11790_Sweep {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    S_d11790_Node* nodes;
    int unka4;
    int unka8;
    S_d11790_Edge* axis0;
    int unkb0;
    int unkb4;
    S_d11790_Edge* axis1;
    int unkbc;
    int unkc0;
    S_d11790_Edge* axis2;
    void FixNodeEdges(unsigned h);
};

// Runs S_d11790_Fix on node h for six node fields across the three edge axes.
// @fnv 0x00d11790
void S_d11790_Sweep::FixNodeEdges(unsigned auiNodeIndex)
{
    S_d11790_Node* nd = nodes;
    S_d11790_Node* n = &nd[auiNodeIndex];
    S_d11790_Fix(nd, axis0, n, &S_d11790_Node::m_usValue08, auiNodeIndex);
    S_d11790_Fix(nd, axis0, n, &S_d11790_Node::m_usValue0A, auiNodeIndex);
    S_d11790_Fix(nd, axis1, n, &S_d11790_Node::m_usValue00, auiNodeIndex);
    S_d11790_Fix(nd, axis1, n, &S_d11790_Node::m_usValue04, auiNodeIndex);
    S_d11790_Fix(nd, axis2, n, &S_d11790_Node::m_usValue02, auiNodeIndex);
    S_d11790_Fix(nd, axis2, n, &S_d11790_Node::m_usValue06, auiNodeIndex);
}


struct hkStatisticsCollector {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void AddMemoryChunk(int type, const char* name, const void* ptr, int size, int allocatedSize);

    int pad04;
    int pad08;
    int pad0C;
    char m_reportInplaceAllocations;

};

template <typename T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct FourIntegerBlock {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct UnsignedShortPair {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
};

struct OverlappingMarkerInfo {
    int unk00;
    hkArray<unsigned short> m_overlappingMarkers;
};

template <typename T>
__forceinline void addArray(hkStatisticsCollector* collector, const char* name, const hkArray<T>& arr)
{
    if ((arr.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations) {
        void* data = arr.m_data;
        int capacity = arr.m_iCapacityState & 0x3fffffff;
        int allocated = ::fnv_00d06f80::FUN_00d06f80(static_cast<const char*>(data), capacity * sizeof(T));
        collector->AddMemoryChunk(3, name, arr.m_data, arr.m_iElementCount * sizeof(T), allocated);
    }
}

// 0xe0 bytes on 32-bit.
struct __declspec(align(16)) hkp3AxisSweep {
    const void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_threadCheck[2];  // +0x08, hkMultiThreadCheck
    void* m_criticalSection;        // +0x10
    int unk14; int unk18; int unk1C;
    __m128 m_quantization[8];       // +0x20, the world aabb and the quantization offsets and scales

    hkArray<FourIntegerBlock> m_kNodeCollection;
    hkArray<UnsignedShortPair> m_axis0;
    hkArray<UnsignedShortPair> m_axis1;
    hkArray<UnsignedShortPair> m_axis2;
    int m_iMarkerCount;
    int unkD4;
    OverlappingMarkerInfo* m_pOverlappingMarkerInfo;

    void ReportStatistics(hkStatisticsCollector* collector, const void* cls);
    int FUN_00d11630();
};

// @fnv 0x00d11630
int hkp3AxisSweep::FUN_00d11630()
{
    return 8 * (3 * (m_kNodeCollection.m_iElementCount - m_iMarkerCount)) + 0x24;
}

struct SpawnedObject {
    const void* m_vtable;
    unsigned short m_wSize;

    SpawnedObject* Init(const void* a, const void* b, int c);
};

// Allocates a 3-axis sweep broad phase from the heap, sets its size, and initializes it with the three arguments.
// @fnv 0x00d182a0
SpawnedObject* FUN_00d182a0(const void* a, const void* b, int c)
{
    SpawnedObject* obj = static_cast<SpawnedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(hkp3AxisSweep)));
    obj->m_wSize = sizeof(hkp3AxisSweep);
    return obj->Init(a, b, c);
}

// Reports the sizes of the node, axis and marker arrays to the statistics collector, including each marker's overlapping markers.
// @fnv 0x00d119e0
void hkp3AxisSweep::ReportStatistics(hkStatisticsCollector* collector, const void* cls)
{
    addArray(collector, "Nodes", m_kNodeCollection);
    addArray(collector, "Axis", m_axis0);
    addArray(collector, "Axis", m_axis1);
    addArray(collector, "Axis", m_axis2);

    if (m_iMarkerCount != 0) {
        reinterpret_cast<::FUN_00d06fb0_cls *>((collector))->DispatchWithMode((void *)("Markers"), (void *)(m_pOverlappingMarkerInfo), m_iMarkerCount * sizeof(OverlappingMarkerInfo), 0);
    }

    for (int i = 0; i < m_iMarkerCount; ++i) {
        addArray(collector, "Markers", m_pOverlappingMarkerInfo[i].m_overlappingMarkers);
    }
}

void __cdecl FUN_00c856c0(void*, void*) throw();



template <typename T>
struct hkArray_00d182e0 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease(hkMemoryAllocator* alloc) throw() {
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & 0x80000000)) {
            alloc->bufFree(m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct Node_00d182e0 {
    int unk00; int unk04; int unk08; int unk0c;
};

struct EndPoint_00d182e0 {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
};

struct SubNode_00d182e0 {
    int unk00;
    hkArray_00d182e0<unsigned short> m_ppData;
};

struct BroadPhaseBase {
    virtual ~BroadPhaseBase() throw();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00d182e0 : public BroadPhaseBase {
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    hkArray_00d182e0<Node_00d182e0> m_kNodeCollection;
    hkArray_00d182e0<EndPoint_00d182e0> m_kAxisEndPoints[3];
    int m_numSubNodes;
    int unkD4;
    SubNode_00d182e0* m_subNodes;

    virtual ~FUN_00d182e0() throw();
};

// Frees each sub-node's array, the sub-node block, the three endpoint arrays and the node array through the router's allocator.
// @fnv 0x00d182e0
FUN_00d182e0::~FUN_00d182e0() throw() {
    for (int i = 0; i < m_numSubNodes; ++i) {
        hkArray_00d182e0<unsigned short>* arr = &m_subNodes[i].m_ppData;
        arr->ClearAndRelease(&hkMemoryRouter::getInstance().heap());
    }
    SubNode_00d182e0* subNodes = m_subNodes;
    FUN_00c856c0(&hkMemoryRouter::getInstance().heap(), subNodes);

    hkArray_00d182e0<EndPoint_00d182e0>* axis = &m_kAxisEndPoints[3];
    for (int i = 2; i >= 0; --i) {
        --axis;
        axis->ClearAndRelease(&hkMemoryRouter::getInstance().heap());
    }
    m_kNodeCollection.ClearAndRelease(&hkMemoryRouter::getInstance().heap());
}

// Returns 0.
// @fnv 0x00d10ac0
int __cdecl FUN_00d10ac0() {
    return 0;
}

// Empty function that does nothing and returns immediately.
// @fnv 0x00d10ff0
void __cdecl FUN_00d10ff0() {
}



template <typename T>
static void constructWithCopy(T* p, int n, const T& t) {
    for (int i = 0; i < n; i++) {
        p[i] = t;
    }
}

template <typename T>
static void construct(T* p, int n) {
    for (int i = 0; i < n; i++) {
    }
}

struct SmallArray {
    unsigned short* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;

    void _pushBack(hkMemoryAllocator& alloc, const unsigned short& val) {
        if (m_iElementCount == (int)(m_iCapacityState & 0x3fffffff)) {
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(unsigned short));
        }
        constructWithCopy(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }

    void AddBack(const unsigned short& val) {
        _pushBack(hkMemoryRouter::getInstance().heap(), val);
    }

    int indexOf(const unsigned short& val) const {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == val)
                return i;
        }
        return -1;
    }

    void removeAt(int index) {
        m_iElementCount--;
        if (m_iElementCount != index) {
            m_data[index] = m_data[m_iElementCount];
        }
    }
};

struct TargetStruct {
    int unk00;
    SmallArray m_ppData;
};

struct BroadPhasePairArray : S_00d138a0_Array {
    S_00d138a0_Pair& _expandOne(hkMemoryAllocator& alloc) {
        if (unk04 == (int)(unk08 & 0x3fffffff)) {
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(S_00d138a0_Pair));
            construct(unk00 + unk04, 1);
        }
        return unk00[unk04++];
    }

    S_00d138a0_Pair& AllocatePair() {
        return _expandOne(hkMemoryRouter::getInstance().heap());
    }
};

struct C_00d13620 {
    int unk00;
    int unk04;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    void* m_unkD8;

    void BuildBroadPhasePairs(S_00d138a0_Node* nodesA, int numNodesA, S_00d138a0_Node* nodesB, int numNodesB, int mode, BroadPhasePairArray& pairs);
};

// Sweeps two sorted node arrays, emitting overlapping pairs into pairs or adding/removing ids in per-node SmallArrays depending on mode.
// @fnv 0x00d13620
void C_00d13620::BuildBroadPhasePairs(S_00d138a0_Node* nodesA, int numNodesA, S_00d138a0_Node* nodesB, int numNodesB, int mode, BroadPhasePairArray& pairs)
{
    char* idx = (char*)m_unkD8;
    while (true) {
        if (nodesA->unk08 > nodesB->unk08) {
            unsigned int target = nodesB->unk0a;
            S_00d138a0_Node* curB = nodesA;
            while (curB->unk08 < target) {
                if (!(((nodesB->unk04 - curB->unk00) | (curB->unk04 - nodesB->unk00)) & 0x80008000)) {
                    if (nodesB->unk0c & 1) {
                        if (mode != 1) {
                            unsigned int id = *(unsigned int*)curB->unk0c;
                            TargetStruct* m = (TargetStruct*)(idx + (nodesB->unk0c & ~1));
                            if (mode == 0) {
                                m->m_ppData.AddBack(id);
                            } else {
                                m->m_ppData.removeAt(m->m_ppData.indexOf(id));
                            }
                        }
                    } else {
                        S_00d138a0_Pair& pair = pairs.AllocatePair();
                        pair.unk00 = curB->unk0c;
                        pair.unk04 = nodesB->unk0c;
                    }
                }
                curB++;
            }
            nodesB++;
            if (--numNodesB <= 0) break;
        } else {
            unsigned int target = nodesA->unk0a;
            S_00d138a0_Node* curA = nodesB;
            while (curA->unk08 < target) {
                if (!(((nodesA->unk04 - curA->unk00) | (curA->unk04 - nodesA->unk00)) & 0x80008000)) {
                    if (curA->unk0c & 1) {
                        if (mode != 1) {
                            unsigned int id = *(unsigned int*)nodesA->unk0c;
                            TargetStruct* m = (TargetStruct*)(idx + (curA->unk0c & ~1));
                            if (mode == 0) {
                                m->m_ppData.AddBack(id);
                            } else {
                                m->m_ppData.removeAt(m->m_ppData.indexOf(id));
                            }
                        }
                    } else {
                        S_00d138a0_Pair& pair = pairs.AllocatePair();
                        pair.unk00 = nodesA->unk0c;
                        pair.unk04 = curA->unk0c;
                    }
                }
                curA++;
            }
            nodesA++;
            if (--numNodesA <= 0) break;
        }
    }
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

// Broad-phase endpoint sweep with two inline active-node sets.
struct BSAudioLocal { void* p; int a; int b; };


struct U16 { unsigned short v; };
struct ShortVec {
    U16* m_00; int m_04; int m_08;
};
struct LocalVec {
    U16* m_00; int m_04; int m_08;
    U16 m_0c[256];
};
struct EntryLocal {
    unsigned short m_00; unsigned short m_02;
};
struct Record {
    int m_00; int m_04; int m_08; uintptr_t m_0c;
};
struct ObjX {
    int m_00;
    ShortVec m_04v;
};
struct PairLocal {
    uintptr_t m_00; uintptr_t m_04;
};
struct PairVec {
    PairLocal* m_00; int m_04; int m_08;
};
struct ThisCls {
    int m_00; int m_04; int m_08; int m_0c; int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c; int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44; int m_48; int m_4c; int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c; int m_70; int m_74; int m_78; int m_7c;
    int m_80; int m_84; int m_88; int m_8c; int m_90; int m_94; int m_98; int m_9c;
    Record* m_a0; int m_a4; int m_a8;
    int* m_ac; int m_b0;
    int m_b4; int m_b8; int m_bc; int m_c0; int m_c4; int m_c8; int m_cc; int m_d0; int m_d4;
    char* m_d8;
    void FUN_00d14a60(unsigned int* bits, PairVec* out, char flag);
};

static int FindIdx(const U16* p, int n, unsigned short v)
{
    for (int i = 0; i < n; i++) {
        if (p[i].v == v) return i;
    }
    return -1;
}
static void PushShort(ShortVec* v, unsigned short val)
{
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(v), 2);
    v->m_00[v->m_04].v = val;
    v->m_04++;
}
static void PushDynamic(ShortVec* v, unsigned short val)
{
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(v), 2);
    U16* p = v->m_00 + *(volatile int*)&v->m_04;
    p->v = val;
    v->m_04++;
}
static void FreeLocalVec(LocalVec& v)
{
    hkMemoryAllocator& ao = hkMemoryRouter::getInstance().heap();
    int cap = v.m_08;
    v.m_04 = 0;
    if ((cap & (int)0x80000000) == 0) {
        ao.bufFree(v.m_00, (cap & 0x3fffffff) * 2);
    }
    v.m_00 = 0;
    v.m_08 = (int)0x80000000;
}

// The caller reserves space before appending overlap pairs.
static __forceinline void AppendN(PairVec* out, Record* other, Record* rec, int n)
{
    for (int k = 0; k < n; ++k) {
        PairLocal* p = &out->m_00[out->m_04];
        out->m_04++;
        p->m_00 = other->m_0c;
        p->m_04 = rec->m_0c;
    }
}
static __forceinline void HandlePair(ThisCls* idx, Record* rec, Record* other, PairVec* out, char flag)
{
    Record* second = rec;
    Record* first = other;
    if ((rec->m_0c & 1) == 0) {
        if ((other->m_0c & 1) == 0) {
            if (out->m_04 == (out->m_08 & 0x3fffffff))
                ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(out), sizeof(PairLocal));
            AppendN(out, other, rec, 1);
            return;
        }
        first = rec;
        second = other;
    }
    int fidx = (int)((char*)first - (char*)idx->m_a0) >> 4;
    ObjX* obj = (ObjX*)(idx->m_d8 + (second->m_0c & ~(uintptr_t)1));
    if (flag != 0) {
        PushDynamic(&obj->m_04v, (unsigned short)fidx);
    } else {
        ShortVec* lv = &obj->m_04v;
        int self = FindIdx(lv->m_00, lv->m_04, (unsigned short)fidx);
        int& cnt = lv->m_04;
        cnt--;
        int last = cnt;
        if (last != self)
            lv->m_00[self] = lv->m_00[last];
    }
}

// @fnv 0x00d14a60
void ThisCls::FUN_00d14a60(unsigned int* bits, PairVec* out, char flag)
{
    LocalVec sv1;
    LocalVec sv2;
    sv2.m_00 = sv2.m_0c;
    sv2.m_08 = (int)0x80000100;
    sv2.m_04 = 0;
    sv1.m_00 = sv1.m_0c;
    sv1.m_08 = (int)0x80000100;
    sv1.m_04 = 0;
    ThisCls* idx = this;
    EntryLocal* end = (EntryLocal*)idx->m_ac + idx->m_b0 - 1;
    EntryLocal* cur = (EntryLocal*)idx->m_ac + 1;
    if (cur < end) {
        do {
            int val = cur->m_02;
            int y = (1 << (val & 0x1f)) & (int)bits[val >> 5];
            if ((cur->m_00 & 1) != 0) {
                ShortVec* v = y != 0 ? (ShortVec*)&sv2 : (ShortVec*)&sv1;
                int n = v->m_04;
                int self = FindIdx(v->m_00, n, (unsigned short)val);
                int last = n - 1;
                v->m_04 = last;
                if (last != self)
                    v->m_00[self] = v->m_00[last];
            } else {
                Record* rec = &idx->m_a0[val];
                for (int i = 0; i < sv2.m_04; i++) {
                    Record* other = &idx->m_a0[sv2.m_00[i].v];
                    int d1 = rec->m_04 - other->m_00;
                    int d0 = other->m_04 - rec->m_00;
                    if (((d0 | d1) & (int)0x80008000) != 0) continue;
                    HandlePair(idx, rec, other, out, flag);
                }
                if (y != 0) {
                    for (int i = 0; i < sv1.m_04; i++) {
                        Record* other = &idx->m_a0[sv1.m_00[i].v];
                        int d0 = other->m_04 - rec->m_00;
                        int d1 = rec->m_04 - other->m_00;
                        if (((d0 | d1) & (int)0x80008000) != 0) continue;
                        HandlePair(idx, rec, other, out, flag);
                    }
                    PushShort((ShortVec*)&sv2, (unsigned short)val);
                } else {
                    PushShort((ShortVec*)&sv1, (unsigned short)val);
                }
            }
            cur++;
        } while (cur < end);
    }
    FreeLocalVec(sv1);
    FreeLocalVec(sv2);
}

#include <xmmintrin.h>

struct FUN_00d10e10_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    __m128 m_negSrc;   // +0x40
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    __m128 m_recipSrc; // +0x60

    void FUN_00d10e10(__m128* out0, __m128* out1);
};

// XORs m_negSrc with DAT_010c44d0 into out0, computes a Newton-refined reciprocal of m_recipSrc, scales it by DAT_010cd5b0, and adds out0 into out1.
// @fnv 0x00d10e10
void FUN_00d10e10_cls::FUN_00d10e10(__m128* out0, __m128* out1) {
    __m128 negated = _mm_xor_ps(m_negSrc, ::DAT_010c44d0);
    *out0 = negated;

    __m128 v = m_recipSrc;
    __m128 hi = _mm_unpackhi_ps(v, DAT_010c7170);
    __m128 x = _mm_shuffle_ps(v, hi, 0xc4);

    __m128 r = _mm_rcp_ps(x);
    __m128 rxr = _mm_mul_ps(_mm_mul_ps(r, x), r);
    __m128 refined = _mm_sub_ps(_mm_add_ps(r, r), rxr);
    *out1 = refined;

    __m128 scale = _mm_set1_ps(DAT_010cd5b0);
    __m128 scaled = _mm_mul_ps(scale, refined);
    *out1 = scaled;
    *out1 = _mm_add_ps(*out0, scaled);
}

// @fnv 0x00d10e80
void __cdecl FUN_00d10e80()
{
}

struct S00d11470_Entry {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
};

struct S00d11470_Object {
    int unk00;
    int unk04;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    char* unkA0;
};

struct S00d11470_Owner {
    bool FUN_00d11470(int* first, int* second);
};

// Takes the 16-byte records at unkA0 indexed by *first and *second and returns true if none of their field cross-differences has a sign bit set.
// @fnv 0x00d11470
bool S00d11470_Owner::FUN_00d11470(int* first, int* second)
{
    S00d11470_Object* object =
        reinterpret_cast<S00d11470_Object*>(this);

    S00d11470_Entry* entrySecond =
        reinterpret_cast<S00d11470_Entry*>(object->unkA0 + *first * 16);
    S00d11470_Entry* entryFirst =
        reinterpret_cast<S00d11470_Entry*>(object->unkA0 + *second * 16);

    unsigned short difference = static_cast<unsigned short>(
        entrySecond->unk0A - entryFirst->unk08);
    difference = static_cast<unsigned short>(
        difference | (entryFirst->unk0A - entrySecond->unk08));
    difference = static_cast<unsigned short>(
        difference | (entrySecond->unk04 - entryFirst->unk00));
    difference = static_cast<unsigned short>(
        difference | (entryFirst->unk04 - entrySecond->unk00));

    int differenceFirst = entrySecond->unk04 - entryFirst->unk00;
    int differenceSecond = entryFirst->unk04 - entrySecond->unk00;

    if (!(difference & 0x8000) && !((differenceFirst | differenceSecond) & 0x80008000))
        return true;
    return false;
}


struct FUN_00d11e80_cls {
    S_00d1a180_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int InsertEndpoints(char* nodes, int axis, S_00d1a180_EndPoint* newEndpoints, int numNew);
};

// Grows the endpoint array if needed, shifts existing endpoints to make room for numNew new entries, and returns the insertion index.
// @fnv 0x00d11e80
int FUN_00d11e80_cls::InsertEndpoints(char* nodes, int axis, S_00d1a180_EndPoint* newEndpoints, int numNew) {
    int oldCount = m_iElementCount;
    int newCount = oldCount + numNew;

    hkMemoryAllocator* alloc = &hkMemoryRouter::getInstance().heap();
    int cap = m_iCapacityState & 0x3fffffff;
    if (cap < newCount) {
        cap = (newCount < 2 * cap) ? 2 * cap : newCount;
        ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(void *)(this), cap, 4);
    }

    m_iElementCount = newCount;

    unsigned int ins = newEndpoints[numNew - 1].m_uiFilterValue;
    S_00d1a180_EndPoint* dst = m_data + newCount - 1;
    S_00d1a180_EndPoint* src = m_data + oldCount - 1;
    _mm_prefetch((const char*)dst, _MM_HINT_NTA);
    _mm_prefetch((const char*)(dst - 128), _MM_HINT_NTA);
    _mm_prefetch((const char*)src, _MM_HINT_NTA);
    _mm_prefetch((const char*)(dst - 128), _MM_HINT_NTA);

    *dst = *src;
    int axis2 = axis * 2;
    *(unsigned short*)(nodes + DAT_011b37a4[(src->m_uiFilterValue & 1) + axis2] + (src->m_usIndex << 4)) = (unsigned short)(dst - m_data);
    src--;
    dst--;

    while (src->m_uiFilterValue > (unsigned short)ins) {
        *dst = *src;
        _mm_prefetch((const char*)(src - 128), _MM_HINT_NTA);
        *(unsigned short*)(nodes + DAT_011b37a4[(src->m_uiFilterValue & 1) + axis2] + (src->m_usIndex << 4)) = (unsigned short)(dst - m_data);
        _mm_prefetch((const char*)(src - 128), _MM_HINT_NTA);
        src--;
        dst--;
    }

    return (dst - m_data) + 1;
}

extern "C" void _ReadWriteBarrier(void);
struct d11Out {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct d11Node {
    int unk00;
    int unk04;
    int unk08;
    int m_flags;
};
struct d11Pair {
    float minX, minY, minZ, minW;
    float maxX, maxY, maxZ, maxW;
};
struct d11Sweep {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    d11Node* m_pNodes;
    int m_iArrayLength;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int m_iBase;

    void FUN_00d11fa0(d11Out& __restrict out);
};

// @fnv 0x00d11fa0
void d11Sweep::FUN_00d11fa0(d11Out& __restrict out)
{
    d11Out* pOut = &out;
    int iCount = m_iArrayLength - m_iBase;
    if ((pOut->m_iCapacityState & 0x3fffffff) < iCount)
        ::FUN_00c908c0((::SpawnedObject *)(&hkMemoryRouter::getInstance().heap()), (::SpawnedArray *)(pOut), iCount, 0x20);
    int n = m_iArrayLength - m_iBase;
    _ReadWriteBarrier();
    pOut->m_iElementCount = n;
    int iPairIndex = 0;
    for (int i = 0; i < m_iArrayLength; i++) {
        d11Node* node = &m_pNodes[i];
        _ReadWriteBarrier();
        if (!(node->m_flags & 1))
            ((void (*)(d11Sweep*, d11Node*, d11Pair*))FUN_00d11650)(this, node, &((d11Pair*)pOut->m_data)[iPairIndex++]);
    }
}

struct SweepEndpoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
    SweepEndpoint() {}
    SweepEndpoint(unsigned short val, unsigned short idx) : m_uiFilterValue(val), m_usIndex(idx) {}
};


template <typename T>
inline void S00d13950_constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i) {
        new (p + i) T(t);
    }
}

template <typename T>
struct SweepArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    SweepArray(T* data, int size, int cap) {
        m_data = data;
        m_iElementCount = size;
        m_iCapacityState = cap | 0x80000000;
    }

    void pushBackUnchecked(const T& t) {
        S00d13950_constructWithCopy<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct SweepNode {
    unsigned short m_min1;
    unsigned short m_min2;
    unsigned short m_max1;
    unsigned short m_max2;
    unsigned short m_min0;
    unsigned short m_max0;
};



struct S00d13950_Less {};

template <typename T, typename L>
inline void S00d13950_quickSort(T* pArr, int iSize, L cmpLess)
{
    if (iSize > 1) {
        ::FUN_00d19fa0((unsigned int *)(pArr), 0, iSize - 1, (*(int *)&(const ::S00d13950_Less &)(cmpLess)));
    }
}

struct SweepClass {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    SweepArray<SweepEndpoint> m_kAxisEndPoints[3];

    void FUN_00d13950(const SweepArray<SweepNode*>& nodes, SweepArray<SweepEndpoint>* tempAxes);
};

// Fills three SweepArray<SweepEndpoint> buffers with min/max endpoints from each SweepNode, sorts each axis, and adds sentinel endpoints.
// @fnv 0x00d13950
void SweepClass::FUN_00d13950(const SweepArray<SweepNode*>& nodes, SweepArray<SweepEndpoint>* tempAxes)
{
    SweepEndpoint* buf = (SweepEndpoint*)(tempAxes + 3);
    int cap = 2 * nodes.m_iElementCount + 2;
    new (&tempAxes[0]) SweepArray<SweepEndpoint>(buf, 0, cap);
    new (&tempAxes[1]) SweepArray<SweepEndpoint>(buf + cap, 0, cap);
    new (&tempAxes[2]) SweepArray<SweepEndpoint>(buf + cap * 2, 0, cap);

    SweepEndpoint sentinel;
    sentinel.m_uiFilterValue = 0;
    sentinel.m_usIndex = 0;
    tempAxes[0].pushBackUnchecked(sentinel);
    tempAxes[1].pushBackUnchecked(sentinel);
    tempAxes[2].pushBackUnchecked(sentinel);

    SweepNode* const* nodeIt = nodes.m_data;
    for (int i = nodes.m_iElementCount - 1; i >= 0; --i) {
        tempAxes[0].pushBackUnchecked(m_kAxisEndPoints[0].m_data[(*nodeIt)->m_min0]);
        tempAxes[0].pushBackUnchecked(m_kAxisEndPoints[0].m_data[(*nodeIt)->m_max0]);
        tempAxes[1].pushBackUnchecked(m_kAxisEndPoints[1].m_data[(*nodeIt)->m_min1]);
        tempAxes[1].pushBackUnchecked(m_kAxisEndPoints[1].m_data[(*nodeIt)->m_max1]);
        tempAxes[2].pushBackUnchecked(m_kAxisEndPoints[2].m_data[(*nodeIt)->m_min2]);
        tempAxes[2].pushBackUnchecked(m_kAxisEndPoints[2].m_data[(*nodeIt)->m_max2]);
        nodeIt++;
    }

    for (int j = 0; j < 3; ++j) {
        S00d13950_quickSort(tempAxes[j].m_data + 1, tempAxes[j].m_iElementCount - 1, S00d13950_Less());
    }

    sentinel.m_uiFilterValue = 0xfffc;
    sentinel.m_usIndex = 0;
    tempAxes[0].pushBackUnchecked(sentinel);
    tempAxes[1].pushBackUnchecked(sentinel);
    tempAxes[2].pushBackUnchecked(sentinel);
}

namespace fnv_00d13bd0 {
struct SweepBase {
    const void** vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    SweepBase() throw();
};
void* AllocateWithHeader(hkMemoryAllocator*, int);

struct SweepNode {
    unsigned short min0, max0, min1, max1, min2, max2;
    int link;
};
struct SweepEnd {
    unsigned short value, node;
};
template<class T> struct SweepArray {
    T* data;
    int size, capacity;
    SweepArray():data(0),size(0),capacity(0x80000000) {}

    static void reserveHeap(hkMemoryAllocator& heap, SweepArray* array, int n) {
        int cap = array->capacity & 0x3fffffff;
        if (cap < n) {
            int grown = 2*cap;
            ::FUN_00c908c0((::SpawnedObject *)(hkMemoryAllocator *)(&heap), (::SpawnedArray *)(array), n < grown ? grown : n, sizeof(T));
        }
    }
    T& _expandOne(hkMemoryAllocator& heap) { if(size == (capacity & 0x3fffffff)) { ::ResizeAudioStream((::AudioAllocator *)(hkMemoryAllocator *)(&heap),(::AudioStream *)(void *)(this),sizeof(T)); construct(data+size,1); } return data[size++]; }
    T& expand() { return _expandOne(hkMemoryRouter::getInstance().heap()); }
    void append(const SweepEnd& value) {
        new (data+size) SweepEnd(value);
        ++size;
    }
};
struct SweepMarker { unsigned short node,value; SweepArray<unsigned short> overlaps; };
union SweepBits { __m128 vector; struct { unsigned int x,y,z,w; } bits; };
static const __m128 sweepBias={65536.0f,65536.0f,65536.0f,65536.0f};
extern const void* DAT_010cd5cc[];
extern "C" void _ReadWriteBarrier(void);
inline void findSweepShift(int value,int& result) { result=-1; if(value>0) { int current=*(volatile int*)&result; do {value>>=1;++current;}while(value>0);result=current;} }
struct SweepScratch { union {float upper;SweepEnd endpoint;}; union {int logarithm;int byteOffset;}; union {float lower;int power;int index;SweepEnd last;}; union {float middle;float value;int needed;int markerCount;}; SweepNode* root; };
struct SweepBound { int x,y,z,w; SweepBound(const int* p):x(p[0]),y(p[1]),z(p[2]),w(p[3]) {} };
struct FUN_00d13bd0 : SweepBase {
    SweepBound lowBound,highBound;
    __m128 offset,offset2,scale,unk70,unk80,unk90;
    SweepArray<SweepNode> nodes;
    SweepArray<SweepEnd> axes[3];
    int mask,shift;
    SweepMarker* markers;
    float correction;
    FUN_00d13bd0(const int* low,const int* high,int count);
};
// Initializes sweep bounds, allocates node and marker arrays, and builds the initial sweep tree structure for the given count.
// @fnv 0x00d13bd0
FUN_00d13bd0::FUN_00d13bd0(const int* low,const int* high,int count):lowBound((vtable=DAT_010cd5cc,low)),highBound(high) {
    SweepScratch scratch; findSweepShift(count ? count : 1,scratch.logarithm);
    nodes.reserveHeap(hkMemoryRouter::getInstance().heap(), &nodes, 255);
    __m128 scaleCopy,maximum,bias;
    scratch.lower=10.0f;scratch.upper=11.0f;
    bias=sweepBias;
    offset=_mm_setzero_ps(); offset2=_mm_setzero_ps(); scale=_mm_set1_ps(1.0f);
    const __m128& scaleRef=scale;
    scaleCopy=scaleRef;
    maximum=(*reinterpret_cast<__m128 *>(&::DAT_011b3790));
    for(int iteration=0;iteration<23;++iteration) {
        scratch.middle=(scratch.upper+scratch.lower)*0.5;
        double midpoint=scratch.middle; float& value=scratch.value;value=midpoint+1.0f;
        SweepBits result;
        result.vector=_mm_add_ps(_mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(_mm_set1_ps(value),offset),scaleCopy),maximum),_mm_setzero_ps()),bias);
        if((unsigned short)((result.bits.x>>7)|1)<12) scratch.lower=midpoint; else scratch.upper=midpoint;
    }
    scale=_mm_setzero_ps(); offset=_mm_setzero_ps(); offset2=_mm_setzero_ps();
    correction=(scratch.upper+scratch.lower)*0.5-11.0;
    scratch.root=&nodes.expand();
    SweepNode& root=*scratch.root;
    root.max0=0;root.min0=0;root.min2=0;root.link=0;
    scratch.power=1<<scratch.logarithm;
    scratch.needed = scratch.power + scratch.power + 510;
    axes[0].reserveHeap(hkMemoryRouter::getInstance().heap(), &axes[0], scratch.needed);
    axes[1].reserveHeap(hkMemoryRouter::getInstance().heap(), &axes[1], 512);
    axes[2].reserveHeap(hkMemoryRouter::getInstance().heap(), &axes[2], 512);
    scratch.endpoint.node=0;scratch.endpoint.value=0;
    axes[0].append(scratch.endpoint); axes[1].append(scratch.endpoint); axes[2].append(scratch.endpoint);
    shift=scratch.logarithm; scratch.markerCount=scratch.power-1; mask=scratch.markerCount; markers=0;
    if(scratch.markerCount) {
        hkMemoryAllocator* heap = &hkMemoryRouter::getInstance().heap();
        int iAllocationSize = scratch.markerCount * 16;
        markers = (SweepMarker*)AllocateWithHeader(heap, iAllocationSize);
    }
    scratch.index=0;
    if(scratch.index<mask) { scratch.byteOffset=0; for(;scratch.index<mask;++scratch.index,scratch.byteOffset+=16) {
        SweepMarker* marker=new((SweepMarker*)((char*)markers+scratch.byteOffset)) SweepMarker;
        scratch.endpoint.node=(unsigned short)nodes.size;scratch.endpoint.value=(unsigned short)((scratch.index+1)<<(16-shift));
        marker->node=scratch.endpoint.node; marker->value=scratch.endpoint.value;
        SweepNode& node=nodes.expand();
        node.min2=(unsigned short)axes[0].size;
        axes[0].append(scratch.endpoint);
        scratch.endpoint.value|=1;
        node.max2=(unsigned short)axes[0].size;
        axes[0].append(scratch.endpoint);
        node.link=scratch.byteOffset|1;
        node.max0=0;node.min0=0;node.max1=1;node.min1=1;
    }
    }
    *scratch.root=nodes.data[0];
    scratch.root->max2=(unsigned short)axes[0].size;
    scratch.root->min1=(unsigned short)axes[1].size;
    scratch.root->max1=(unsigned short)axes[2].size;
    scratch.last.node=0;scratch.last.value=0xfffd;
    axes[0].append(scratch.last);axes[1].append(scratch.last);axes[2].append(scratch.last);
}
}  // namespace fnv_00d13bd0




template <typename T>
struct HkDynamicArray {
    T* m_data;
    int m_iCapacityState;

    __forceinline HkDynamicArray(int n) throw() {
        allocate(hkMemoryRouter::getInstance().temp(), n);
    }
    __forceinline void allocate(hkMemoryAllocator& alloc, int n) throw() {
        int num = n;
        m_data = num ? alloc._bufAlloc<T>(num) : 0;
        m_iCapacityState = num ? num : (int)0x80000000;
    }

    __forceinline ~HkDynamicArray() throw() {
        release(hkMemoryRouter::getInstance().temp());
    }
    __forceinline void release(hkMemoryAllocator& alloc) throw() {
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * (int)sizeof(T));
        }
    }

    __forceinline T& operator[](int i) { return m_data[i]; }
};

template <typename T>
__forceinline T* hkTempAlloc(hkMemoryAllocator& alloc, int n, int& capOut) throw() {
    int num = n;
    T* p = num ? alloc._bufAlloc<T>(num) : 0;
    capOut = num ? num : (int)0x80000000;
    return p;
}

template <typename T>
__forceinline void hkTempFree(hkMemoryAllocator& alloc, T* p, int cap) throw() {
    if ((cap & 0x80000000) == 0) {
        alloc.bufFree(p, (cap & 0x3fffffff) * (int)sizeof(T));
    }
}

struct Elem {
    unsigned short m_usValue00;
    unsigned short m_usValue02;
    unsigned short m_usValue04;
    unsigned short m_usValue06;
    unsigned short m_usValue08;
    unsigned short m_usValue0A;
    int* h;
    __forceinline int isMarker() const throw() { return (uintptr_t)h & 1; }
    __forceinline struct Sub* getMarker(struct Sub* base) const throw() { return (struct Sub*)((char*)base + ((uintptr_t)h & ~1)); }
};

template <typename T>
struct S00d15fc0_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i) throw() { return m_data[i]; }
    __forceinline int GetLogicalSize() const throw() { return m_iElementCount; }
};

struct Sub {
    unsigned short x;
    unsigned short x2;
    unsigned short* idx;
    int n;
    int y;
};

struct AxisPair {
    unsigned short* p;
    int n;
    int cap;
};

struct KeyPair {
    unsigned short val;
    unsigned short idx;
};
struct KeyLess { bool operator()(const KeyPair& a, const KeyPair& b) const { return a.val < b.val; } };

template <typename L>
__forceinline void hkQuickSort(KeyPair* p, int size, L cmp) throw() {
    if (size > 1) {
        ::QuickSortByLowWord((unsigned int *)(p), 0, size - 1, (*(int *)&(const ::KeyLess &)(cmp)));
    }
}

struct Sweep {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    S00d15fc0_Array<Elem> m_kNodeCollection;
    AxisPair m_ac[3];
    int m_d0;
    int m_d4;
    Sub* m_d8;

    void FUN_00d15fc0();
    __forceinline void setNodeIndex(Elem& node, int i) throw() {
        int* const& h = node.h;
        if (((uintptr_t)h & 1) == 0) {
            *h = i;
        } else {
            *(unsigned short*)((char*)m_d8 + ((uintptr_t)h & ~1)) = (unsigned short)i;
        }
    }
};

// Sorts m_kNodeCollection by m_usValue08, remaps node indices in m_d8 and m_ac, updates node h pointers, and calls FixNodeEdges.
// @fnv 0x00d15fc0
void Sweep::FUN_00d15fc0() {
    int n = m_kNodeCollection.GetLogicalSize();
    int tmpCap;
    Elem* tmp = hkTempAlloc<Elem>(hkMemoryRouter::getInstance().temp(), n, tmpCap);
    int keysCap;
    KeyPair* keys = hkTempAlloc<KeyPair>(hkMemoryRouter::getInstance().temp(), n, keysCap);
    int remapCap;
    int* remap = hkTempAlloc<int>(hkMemoryRouter::getInstance().temp(), n, remapCap);

    {
    int i=0;
    if (i < m_kNodeCollection.GetLogicalSize()) {
        int offset=0;
        do {
        *(Elem*)((char*)tmp + offset) = *(Elem*)((char*)m_kNodeCollection.m_data + offset);
        keys[i].val = ((Elem*)((char*)m_kNodeCollection.m_data + offset))->m_usValue08;
        keys[i].idx = (unsigned short)i;
i++; offset += sizeof(Elem);
        } while (i < m_kNodeCollection.GetLogicalSize());
    }
    }

    hkQuickSort(&keys[1], n - 1, KeyLess());

    for (int i = 0; i < m_kNodeCollection.GetLogicalSize(); i++) {
        unsigned idx = keys[i].idx;
        remap[idx] = i;
        m_kNodeCollection[i] = tmp[idx];
    }

    for (int i=1; i<m_kNodeCollection.GetLogicalSize(); i++) {
int* h=m_kNodeCollection[i].h; Elem& node=m_kNodeCollection[i];
if (((uintptr_t)node.h & 1)==0) *h=i; else node.getMarker(m_d8)->x=(unsigned short)i;
    }

    for (int j = 0; j < m_d0; j++) {
        Sub* x = &m_d8[j];
        for (int idx = x->n - 1; idx >= 0; idx--) {
            x->idx[idx] = (unsigned short)remap[x->idx[idx]];
        }
    }

    for (int a = 0; a < 3; a++) {
        KeyPair* w = (KeyPair*)m_ac[a].p;
        for (int idx = 0; idx < m_ac[a].n; idx++) {
            w[idx].idx = (unsigned short)remap[w[idx].idx];
        }
    }

    for (int i = 1; i < m_kNodeCollection.GetLogicalSize(); i++) {
        reinterpret_cast<::S_d11790_Sweep *>(this)->FixNodeEdges(i);
    }

    hkTempFree(hkMemoryRouter::getInstance().temp(), remap, remapCap);
    hkTempFree(hkMemoryRouter::getInstance().temp(), keys, keysCap);
    hkTempFree(hkMemoryRouter::getInstance().temp(), tmp, tmpCap);
}


struct SweepMerge {
    Endpoint* m_endpoints;
    void FUN_00d19e40(char* cells, int n, Endpoint* source, int count);
};

// Merges m_endpoints[0..n-count) with source[0..count) from the back into m_endpoints, writing each moved endpoint's new index into cells.
// @fnv 0x00d19e40
void SweepMerge::FUN_00d19e40(char* cells, int aiTotalCount, Endpoint* apRightStart, int aiRightCount)
{
    Endpoint* base = m_endpoints;
    Endpoint* right = apRightStart;
    right += aiRightCount - 1;
    int oldCount = aiTotalCount - aiRightCount;
    Endpoint* left = base + oldCount - 1;
    int leftValue = base[oldCount - 1].value;
    int rightValue = right->value;
    int index = aiTotalCount - 1;
    Endpoint* out = base + index;
    for (;;) {
        if (leftValue > rightValue) {
            *out = *left;
            unsigned int slot = (left->handle << 4) + ::g_D1A0E0Tables[left->value & 1];
            *(unsigned short*)(cells + slot) = (unsigned short)index;
            --left;
            --out;
            --index;
            leftValue = left->value;
        } else {
            *out = *right;
            unsigned int slot = (right->handle << 4) + ::g_D1A0E0Tables[right->value & 1];
            *(unsigned short*)(cells + slot) = (unsigned short)index;
            --right;
            rightValue = right->value;
            --out;
            --index;
            if (right < apRightStart) break;
        }
    }
}

__declspec(align(16)) struct FUN_00d1a2a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    __m128 m_v70;
    __m128 m_v80;

    void GetValues(__m128* out0, __m128* out1);
};

// Copies the two __m128 members m_v70 and m_v80 into the caller-supplied output pointers out0 and out1.
// @fnv 0x00d1a2a0
void FUN_00d1a2a0_cls::GetValues(__m128* out0, __m128* out1)
{
    *out0 = m_v70;
    *out1 = m_v80;
}



struct S_00d1a2d0_Base {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual void v0();
    static void operator delete(void* p)
    {
        S_00d1a2d0_Base* b = static_cast<S_00d1a2d0_Base*>(p);
        hkMemoryRouter::getInstance().heap().blockFree(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00d1a2d0 : S_00d1a2d0_Base {
    FUN_00d1a2d0();
    virtual ~FUN_00d1a2d0();
};

// @fnv 0x00d1a2d0
FUN_00d1a2d0::FUN_00d1a2d0() {}

#include <xmmintrin.h>
namespace fnv_00d11650 {


typedef float hkReal;
typedef unsigned short hkUint16;

struct hkVector4q {
    __m128 m_vComponents;

    __forceinline hkReal operator()(int i) const { return m_vComponents[i]; }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& v) { m_vComponents = _mm_sub_ps(a.m_vComponents, v.m_vComponents); }
    __forceinline void operator=(const hkVector4q& v) { m_vComponents = v.m_vComponents; }
    __forceinline void sub4(const hkVector4q& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
};

struct hkAabbq {
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct BpNode {
    hkUint16 m_usValue00;
    hkUint16 m_usValue02;
    hkUint16 m_usValue04;
    hkUint16 m_usValue06;
    hkUint16 m_usValue08;
    hkUint16 m_usValue0A;
};

struct BpEndPoint {
    hkUint16 m_uiFilterValue;
    hkUint16 m_usIndex;
};

struct BpAxis {
    BpEndPoint* m_pEndPoints;
    int m_iElementCount;
    int m_iCapacityState;
};

struct AxisSweep3 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    hkVector4q m_kVectorAt40;
    hkVector4q m_kVectorAt50;
    hkVector4q m_vScale;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    BpAxis m_kNodeCollection;
    BpAxis m_kAxisEndPoints[3];

    void FUN_00d11650(const BpNode& node, hkAabbq& aabb) const;
};

// Computes the axis-aligned bounding box of a BpNode in local space by scaling its endpoint coordinates and storing the result in aabb.
// @fnv 0x00d11650
void AxisSweep3::FUN_00d11650(const BpNode& node, hkAabbq& aabb) const
{
    hkReal fInvScaleX = 1.0f / m_vScale(0);
    hkReal fInvScaleY = 1.0f / m_vScale(1);
    hkReal fInvScaleZ = 1.0f / m_vScale(2);


    hkVector4q mn; mn.set(fInvScaleX * m_kAxisEndPoints[0].m_pEndPoints[node.m_usValue08].m_uiFilterValue, fInvScaleY * m_kAxisEndPoints[1].m_pEndPoints[node.m_usValue00].m_uiFilterValue, fInvScaleZ * m_kAxisEndPoints[2].m_pEndPoints[node.m_usValue02].m_uiFilterValue, 0.0f);
    float hx = m_kAxisEndPoints[0].m_pEndPoints[node.m_usValue0A].m_uiFilterValue;
float hy = m_kAxisEndPoints[1].m_pEndPoints[node.m_usValue04].m_uiFilterValue;
float hz = m_kAxisEndPoints[2].m_pEndPoints[node.m_usValue06].m_uiFilterValue;
hkVector4q mx; mx.set(fInvScaleX*hx,fInvScaleY*hy,fInvScaleZ*hz,0.0f);
    mn.sub4(m_kVectorAt40);
    mx.sub4(m_kVectorAt40);
    aabb.m_kMinimumCorner = mn;
    aabb.m_kMaximumCorner = mx;
}
}  // namespace fnv_00d11650

extern "C" void _ReadWriteBarrier();
// Havok axis sweep. Based on community near miss nm_5cdcf740ad53441b93a7.
//
// The sweep shape keeps a block of 32 sixteen byte records; every block owns
// a bit mask that marks the records which still overlap the reference record
// of the current sweep.  The overlapping ones are appended to the event list
// of the caller.

static __forceinline void AllocateMaskBlocks(hkMemoryAllocator& sink, int blocks, void*& buffer, int& masks) {
    if (blocks) {
        int size = blocks * 4;
        void* result = sink.bufAlloc(size);
        int actualMasks = size / 4;
        buffer = result;
        // Preserve the buffer store before publishing its allocation flags.
        _ReadWriteBarrier();
        masks = actualMasks;
        return;
    }
    buffer = 0;
}


struct EventList {
    void* data;
    int count;
    int capacity;
};

struct SweepEvent {
    int* index;
    int value;
};

struct SweepRecord {
    int f00;
    int f04;
    unsigned short f08;
    unsigned short f0a;
    int f0c;
};

struct SweepType {
    unsigned short value;
    unsigned short unk02;
};

struct AxisSweep {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    SweepRecord* records;
    int numRecords;
    int unkA8;
    SweepType* types;
    void FUN_00d14100(int* index, EventList* events);
};

// Iterates sweep records matching a bitmask, appending those whose f0c value is even to the events list, growing it when full.
// @fnv 0x00d14100
void AxisSweep::FUN_00d14100(int* index, EventList* events)
{
    int count = numRecords;
    int blocks = (count >> 5) + 8;
    hkMemoryAllocator& sink = hkMemoryRouter::getInstance().temp();
    SweepRecord* block;
    unsigned* pMask;
    void* buffer;
    int masks = 0;
    unsigned* maskEnd;
    AllocateMaskBlocks(sink, blocks, buffer, masks);
    if (!masks)
        masks = 0x80000000;

    int idx = *index;
    SweepRecord* ref = records + idx;
    unsigned short code = types[ref->f08].value;
    pMask = (unsigned*)buffer;
    reinterpret_cast<::S_00d112c0 *>(this)->FUN_00d112c0(count, code, (const ::S_00d112c0_Node *)(ref), idx, (unsigned int *)(buffer));

    block = records;
    maskEnd = pMask + (numRecords >> 5) + 1;
    while (pMask < maskEnd) {
        unsigned mask = *pMask;
        SweepRecord* rec = block;
        while (mask) {
            if ((mask & 0xff) == 0) {
                rec += 8;
                mask >>= 8;
                continue;
            }
            if (mask & 1) {
                if (!(((rec->f04 - ref->f00) | (ref->f04 - rec->f00)) & 0x80008000)) {
                    int value = rec->f0c;
                    if (!(value & 1)) {
                        if (events->count == (events->capacity & 0x3fffffff))
                            ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(events), 8);
                        SweepEvent* slot = (SweepEvent*)((char*)events->data + events->count * 8);
                        if (slot) {
                            slot->index = index;
                            slot->value = value;
                        }
                        events->count++;
                    }
                }
            }
            rec += 1;
            mask >>= 1;
        }
        block += 32;
        pMask += 1;
    }

    hkMemoryAllocator& s2 = hkMemoryRouter::getInstance().temp();
    if (!(masks & 0x80000000u))
        s2.bufFree(buffer, (masks & 0x3fffffff) * 4);
}

extern "C" void _ReadWriteBarrier();
struct SweepNodeX {
 unsigned int minimum;
 unsigned int maximum;
 unsigned short lowZ, highZ;
 uintptr_t handle;
};
struct SweepGroupX {
 unsigned short node, flags;
 unsigned short* data;
 int size;
 int capacity;
 int find(const unsigned short& value,int start=0,int end=-1) const {
  if(end<0) end=size;
  for(int i=start;i<end;++i) if(data[i]==value) return i;
  return -1;
 }
 void remove(unsigned short value) {
  int i=find(value); removeAt(i);
 }
 void removeAt(int i) { --*(volatile int*)&size;
  if(size!=i) data[i]=data[size];
 }
};
struct SweepAllocatorX {
 virtual void f0(); virtual void f4(); virtual void f8();
 virtual void* allocate(int& bytes);
 virtual void release(void*, int bytes);
};
struct SweepRouterX {
 int u0,u4,u8;
 SweepAllocatorX* stack;
 hkMemoryAllocator* heap;
 static SweepRouterX* __cdecl router();
 hkMemoryAllocator& getHeap() { return *heap; }
 SweepAllocatorX& getStack() { return *stack; }
};
struct SweepPairX {
 unsigned int* first; unsigned int second;
 SweepPairX(unsigned int* a,unsigned int b) : first(a),second(b) {}
};
struct SweepPairsX {
 SweepPairX* data; int size; unsigned int capacity;
 void push(unsigned int* a,unsigned int b) {
  SweepRouterX* r=SweepRouterX::router();
  if(size==(capacity&0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(r->heap),(::AudioStream *)(void *)(this),8);
  new(data+size) SweepPairX(a,b);
  ++size;
 }
};
struct SweepNodesX {
 SweepNodeX* data; int size; int capacity;
 void SetSizeAndGrow(int n) {
  hkMemoryAllocator& a=SweepRouterX::router()->getHeap();
  int cap=capacity&0x3fffffff;
  if(cap<n) { int twice=cap*2; ::FUN_00c908c0((::SpawnedObject *)(hkMemoryAllocator *)(&a),(::SpawnedArray *)(void *)(this),n<twice?twice:n,16); }
  size=n;
 }
};
struct SweepAxisX {
 Endpoint* data; int size; int capacity;
};
struct SweepOwnerX {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 SweepNodesX nodes;
 SweepAxisX axes[3];
 int groupCount;
 unsigned short shiftBits, unusedD6;
 SweepGroupX* groups;
 void FUN_00d14600(unsigned int* handle,SweepPairsX* pairs);
};
// Removes the node at handle from the sweep structure, updating axes, groups, and node storage.
// @fnv 0x00d14600
void SweepOwnerX::FUN_00d14600(unsigned int* handle,SweepPairsX* pairs) {
 unsigned long base=*handle;
 unsigned long count;
 count = nodes.size;
 SweepNodeX* alloc=nodes.data+base;
 unsigned int* index;
 int c;
 int first=((unsigned int)count>>5)+8;
 SweepAllocatorX& other=SweepRouterX::router()->getStack();
 if(first) {
  int bytes=first*4;
  unsigned int* value=index=(unsigned int*)other.allocate(bytes);
  int converted=bytes/4;
_ReadWriteBarrier();
  index=value;
  c=converted;
 } else { index=0; c=0; }
 if(!c) c=0x80000000;
 reinterpret_cast<::S_00d112c0 *>(this)->FUN_00d112c0(count,axes[0].data[alloc->lowZ].value,(const ::S_00d112c0_Node *)(alloc),base,index);
 unsigned int* capacity=index;
 SweepNodeX* q;
 q = nodes.data;
 unsigned int* last;
 last = index+(nodes.size>>5)+1;
 for(;capacity<last;++capacity,q+=32) {
  SweepNodeX* wordCount=q;
  unsigned int mask=*capacity;
  while(mask) {
   if(!(mask&255)) { wordCount+=8; mask>>=8; }
   else {
    if(mask&1) {
     if(!(((wordCount->maximum-alloc->minimum)|(alloc->maximum-wordCount->minimum))&0x80008000)) {
      unsigned int result=wordCount->handle;
      if(!(result&1)) {
       pairs->push(handle,result);
      } else {
       SweepGroupX* group=(SweepGroupX*)((char*)groups+(result&~1));
       group->remove((unsigned short)base);
      }
     }
    }
    ++wordCount; mask>>=1;
   }
  }
 }
 SweepAllocatorX& releaseAlloc=SweepRouterX::router()->getStack();
 if(!(c&0x80000000)) releaseAlloc.release(index,(c&0x3fffffff)*4);
 q=nodes.data;
 reinterpret_cast<::FUN_00d11960_cls *>(&(axes[0]))->FUN_00d11960(alloc->lowZ,alloc->highZ);
 reinterpret_cast<::FUN_00d11960_cls *>(&(axes[1]))->FUN_00d11960((unsigned short)alloc->minimum,(unsigned short)alloc->maximum);
 reinterpret_cast<::FUN_00d11960_cls *>(&(axes[2]))->FUN_00d11960((unsigned short)(alloc->minimum>>16),(unsigned short)(alloc->maximum>>16));
 ::FUN_00d10d10((::BpBoundNode *)(q), count, (const ::BpBoundWords *)(alloc));
 if(base<(unsigned int)(count-1)) {
  *alloc=nodes.data[count-1];
  axes[0].data[alloc->lowZ].handle=(unsigned short)base;
  axes[0].data[alloc->highZ].handle=(unsigned short)base;
  if(!(1 & alloc->handle)) {
   axes[1].data[(unsigned short)alloc->minimum].handle=(unsigned short)base;
   axes[1].data[(unsigned short)alloc->maximum].handle=(unsigned short)base;
   axes[2].data[(unsigned short)(alloc->minimum>>16)].handle=(unsigned short)base;
   axes[2].data[(unsigned short)(alloc->maximum>>16)].handle=(unsigned short)base;
   *(unsigned int*)alloc->handle=base;
  } else {
   SweepGroupX* group=(SweepGroupX*)((char*)groups+(alloc->handle&~1));
   group->node=(unsigned short)base;
  }
  if(groupCount && !(alloc->handle&1)) {
   unsigned short low=alloc->lowZ;
   Endpoint* zPoints=axes[0].data;
   
   int cursor=zPoints[low].value>>(unsigned short)(16-shiftBits);
   if(cursor > 0 && nodes.data[groups[cursor-1].node].highZ>low) --cursor;
   int end=(zPoints[alloc->highZ].value>>(unsigned short)(16-shiftBits))-1;
   if(cursor<=end) {
   unsigned short oldIndex=(unsigned short)(count-1);
   for(int i=cursor;i<=end;++i) {
    SweepGroupX& group=groups[i];
    group.data[group.find(oldIndex)]=(unsigned short)base;
   }
   }
  }
  reinterpret_cast<::S_d11790_Sweep *>(this)->FixNodeEdges(base);
 }
 nodes.SetSizeAndGrow(count-1);
}

struct CacheNode { unsigned short minY,minZ,maxY,maxZ,minX,maxX; uintptr_t handle; };


struct Item {
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    volatile unsigned int m_14;
};

struct ItemList {
    Item** m_items;
    int m_uiItemCount;
};

struct Blk {
    CacheNode** a; // data pointer
    unsigned int b; // element count
    unsigned int c; // capacity and ownership flags
    char* d; // original local allocation
};

struct CacheOwner {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74;
    unsigned int unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    CacheNode* m_a0;

    int unkA4, unkA8;
    SweepArray<SweepEndpoint> axis[3];
    void FUN_00d15f10(ItemList* a1, void* a2);
};

// Fills a pool array with (item->m_14 << 4) + m_a0 per item, calls FUN_00d13950 with it and a2, then restores the pool pointer and frees the array.
// @fnv 0x00d15f10
void CacheOwner::FUN_00d15f10(ItemList* apItemList, void* a2)
{
    CacheOwner* volatile self = this;
    Blk blk;
    ItemList* list = apItemList;
    unsigned int n = (unsigned int)list->m_uiItemCount;
    int i = 0;
    blk.b = (unsigned int)i;
    char* base = static_cast<char*>(hkMemoryRouter::getInstance().allocateStack((n * sizeof(CacheNode*) + 0x7f) & ~size_t(0x7f)));
    unsigned int flags = n | 0x80000000u;
    CacheNode** arr = reinterpret_cast<CacheNode**>(base);
    blk.a = arr;
    blk.c = flags;
    blk.d = base;

    if (i < list->m_uiItemCount) {
      do {
        unsigned int index=list->m_items[i]->m_14; arr[i++] = self->m_a0 + index;
      } while(i < list->m_uiItemCount);
      blk.b = (unsigned int)i;
    }
    CacheOwner* callSelf=self; reinterpret_cast<::SweepClass *>((callSelf))->FUN_00d13950((*(const ::SweepArray< ::SweepNode *> *)(&blk)), static_cast<::SweepArray< ::SweepEndpoint> *>(a2));
    hkMemoryRouter::getInstance().deallocateStack(base);
    if ((flags & 0x80000000u) == 0) {
        hkMemoryRouter::getInstance().heap().bufFree(arr, (flags & 0x3fffffffu) * sizeof(CacheNode*));
    }
}

#include <xmmintrin.h>
namespace fnv_00d142b0 {
#include <xmmintrin.h>


struct Entry4 { unsigned short value; unsigned short handle; };
struct AxisArr {
    Entry4* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
    void InsertPair(const void* a1, unsigned int a2, unsigned short a3, unsigned short a4, unsigned short* out2, unsigned short* out1);
};
struct Node16 {
    union { unsigned int f0; struct { unsigned short minY, minZ; }; };
    union { unsigned int f4; struct { unsigned short maxY, maxZ; }; };
    union { unsigned int f8; struct { unsigned short minX, maxX; }; };
    int* fC;
};
struct NodesArr {
    Node16* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};
struct Pair8 { uintptr_t first; uintptr_t second; };
struct PairArr {
    Pair8* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};
struct Input {
    unsigned int v0; unsigned int v4; unsigned int v8; unsigned int vC;
    unsigned int v10; unsigned int v14; unsigned int v18; unsigned int v1C;
};
struct Sweep {
    int u00; int u04; int u08; int u0C; int u10; int u14; int u18; int u1C;
    int u20; int u24; int u28; int u2C; int u30; int u34; int u38; int u3C;
    int u40; int u44; int u48; int u4C; int u50; int u54; int u58; int u5C;
    int u60; int u64; int u68; int u6C; int u70; int u74; int u78; int u7C;
    int u80; int u84; int u88; int u8C; int u90; int u94; int u98; int u9C;
    NodesArr m_kNodeCollection;
    FUN_00d11da0_cls m_axis0;
    FUN_00d11da0_cls m_axis1;
    FUN_00d11da0_cls m_axis2;
    int uD0; int uD4;
    char* m_markerBase;
    __declspec(noinline) void FUN_00d10b30(Node16* buf, int index, Node16* node);
    void FUN_00d142b0(int* handle, Input* input, PairArr* outPairs);
};


union CheckedUnsignedShortVector {
    __m64 v;
    struct { short x,y,z,w; };
};
__declspec(noinline) void Sweep::FUN_00d10b30(Node16* buf, int index, Node16* node) {
    CheckedUnsignedShortVector lo,hi,loMax,hiMax;
    __m64 yz = *(__m64*)&node->f0;
    __m64 x = *(__m64*)&node->f8;
    __m64 all = _mm_cmpeq_pi16(_mm_setzero_si64(),_mm_setzero_si64());
    __m64 ones = _mm_srli_pi16(all,15);
    __m64 twos = _mm_slli_pi16(ones,1);
    lo.v = _mm_sub_pi16(_mm_unpacklo_pi32(yz,yz), ones);
    __m64 yzMax = _mm_srli_si64(yz,32);
    loMax.v = _mm_sub_pi16(_mm_unpacklo_pi32(yzMax,yzMax), twos);
    hi.v = _mm_sub_pi16(_mm_unpacklo_pi16(x,x), ones);
    __m64 xMax = _mm_srli_si64(x,16);
    hiMax.v = _mm_sub_pi16(_mm_unpacklo_pi16(xMax,xMax), twos);
    __m64 mask = _mm_srli_si64(all,32);
    Node16* end = buf + index;
    for (;buf < end; ++buf) {
        __m64 a = *(__m64*)&buf->f0;
        __m64 b = *(__m64*)&buf->f8;
        *(__m64*)&buf->f0 = _mm_sub_pi16(a,_mm_add_pi16(_mm_cmpgt_pi16(a,lo.v),_mm_cmpgt_pi16(a,loMax.v)));
        *(__m64*)&buf->f8 = _mm_sub_pi16(b,_mm_and_si64(mask,_mm_add_pi16(_mm_cmpgt_pi16(b,hi.v),_mm_cmpgt_pi16(b,hiMax.v))));
    }
    _mm_empty();
}

struct __declspec(align(16)) BoundVector {
    unsigned int x,y,z,w;
};
// Inserts a node into m_kNodeCollection, updates axis bounds, and collects overlapping node handles into outPairs.
// @fnv 0x00d142b0
void Sweep::FUN_00d142b0(int* handle, Input* input, PairArr* outPairs) {
    BoundVector mins, maxs;
    mins.x = input->v0 >> 15;
    mins.y = input->v4 >> 15;
    mins.z = input->v8 >> 15;
    unsigned int max0 = input->v10 >> 15;
    if (max0 != 0xffff) ++max0;
    maxs.x = max0 | 1;
    unsigned int max1 = input->v14 >> 15;
    if (max1 != 0xffff) ++max1;
    maxs.y = max1 | 1;
    unsigned int max2 = input->v18 >> 15;
    if (max2 != 0xffff) ++max2;
    maxs.z = max2 | 1;
    mins.x &= 0xfffe;
    mins.y &= 0xfffe;
    mins.z &= 0xfffe;
    int oldSize = m_kNodeCollection.m_iElementCount;
    NodesArr* nodes = &m_kNodeCollection;
    if (nodes->m_iElementCount == (int)(nodes->m_capFlags & 0x3fffffff)) {
        ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(nodes), sizeof(Node16));
    }
    Node16* node = nodes->m_data + nodes->m_iElementCount++;
    Node16* data = m_kNodeCollection.m_data;
    m_axis0.InsertPair(data, oldSize, (unsigned short)mins.x, (unsigned short)maxs.x, &node->minX, &node->maxX);
    m_axis1.InsertPair(data, oldSize, (unsigned short)mins.y, (unsigned short)maxs.y, &node->minY, &node->maxY);
    m_axis2.InsertPair(data, oldSize, (unsigned short)mins.z, (unsigned short)maxs.z, &node->minZ, &node->maxZ);
    ::FUN_00d10b30((::S00d10b30_Node *)(data), oldSize, (const ::S00d10b30_Bnd *)(node));
    node->fC = handle;
    *handle = oldSize;
    int nodeCount = m_kNodeCollection.m_iElementCount;
    int count = (nodeCount >> 5) + 8;
    hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().temp();
    int* bufData;
    unsigned int bufCap;
    if (count != 0) {
        int bytes = count * 4;
        int* result = static_cast<int*>(alloc.bufAlloc(bytes));
        int n = bytes / 4;
        bufData = result;
        bufCap = n;
    } else {
        bufData = 0;
        bufCap = 0;
    }
    if (bufCap == 0) bufCap = 0x80000000;
    reinterpret_cast<::S_00d112c0 *>(this)->FUN_00d112c0(nodeCount, mins.x, (const ::S_00d112c0_Node *)(node), oldSize, (unsigned int *)(bufData));
    int* cursor = bufData;
    Node16* chunk = m_kNodeCollection.m_data;
    int* end = bufData + ((m_kNodeCollection.m_iElementCount >> 5) + 1);
    while (cursor < end) {
        Node16* n = chunk;
        unsigned int bits = (unsigned int)*cursor;
        if (bits != 0) {
            for (;;) {
                if ((unsigned char)bits == 0) {
                    n += 8;
                    bits >>= 8;
                } else {
                    if (bits & 1) {
                        int diff1 = (int)n->f4 - (int)node->f0;
                        int diff2 = (int)node->f4 - (int)n->f0;
                        if (((diff1 | diff2) & 0x80008000) == 0) {
                            uintptr_t fc = (uintptr_t)n->fC;
                            if ((fc & 1) == 0) {
                                if (outPairs->m_iElementCount == (int)(outPairs->m_capFlags & 0x3fffffff)) {
                                    ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(outPairs), sizeof(Pair8));
                                }
                                Pair8* dst = outPairs->m_data + outPairs->m_iElementCount;
                                if (dst) {
                                    dst->first = (uintptr_t)handle;
                                    dst->second = fc;
                                }
                                outPairs->m_iElementCount++;
                            } else {
                                TargetStruct* marker = (TargetStruct*)(m_markerBase + (fc & ~1));
                                marker->m_ppData.AddBack((const unsigned short&)oldSize);
                            }
                        }
                    }
                    ++n;
                    bits >>= 1;
                }
                if (!bits) break;
            }
        }
        chunk += 32;
        ++cursor;
    }
    if (!(bufCap & 0x80000000)) {
        hkMemoryRouter::getInstance().temp().bufFree(bufData, (bufCap & 0x3fffffff) * 4);
    }
}
}  // namespace fnv_00d142b0

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
namespace fnv_00d175f0 {
#include <xmmintrin.h>

extern "C" void _ReadWriteBarrier(void);
struct SweepEnd { unsigned short value, handle; };
struct SweepNode {
    unsigned short minY, minZ, maxY, maxZ, minX, maxX;
    unsigned* handle;
};
struct SweepList { void* data; int size; int capacity;
    SweepList():data(0),size(0),capacity(0x80000000) {}
    void clear() throw() {
        hkMemoryAllocator* heap=&hkMemoryRouter::getInstance().heap();
        int cap=capacity;
        size=0;
        if (!(cap & 0x80000000)) heap->bufFree(data,(cap&0x3fffffff)*8);
        data=0;capacity=0x80000000;
    }

};
struct SweepAxis { SweepEnd* data; int size; int capacity; };
void AppendPairToBuffer(SweepNode*, SweepNode*, void*);
struct __declspec(align(16)) SweepVector { float x,y,z,w; };
struct __declspec(align(16)) SweepBounds { unsigned low[4], high[4]; };
struct SweepManager {
    unsigned field00;
    unsigned field04;
    unsigned field08;
    unsigned field0C;
    unsigned field10;
    unsigned field14;
    unsigned field18;
    unsigned field1C;
    unsigned field20;
    unsigned field24;
    unsigned field28;
    unsigned field2C;
    unsigned field30;
    unsigned field34;
    unsigned field38;
    unsigned field3C;
    unsigned field40;
    unsigned field44;
    unsigned field48;
    unsigned field4C;
    unsigned field50;
    unsigned field54;
    unsigned field58;
    unsigned field5C;
    float scale[4];
    unsigned field70;
    unsigned field74;
    unsigned field78;
    unsigned field7C;
    unsigned field80;
    unsigned field84;
    unsigned field88;
    unsigned field8C;
    unsigned field90;
    unsigned field94;
    unsigned field98;
    unsigned field9C;
    SweepNode* nodes;
    int nodeCount, nodeCapacity;
    SweepAxis axes[3];
    int markerCount, fieldD4;
    void* markers;
    __forceinline void update(unsigned id, const SweepBounds& bounds, void* added, SweepList& removed);
    void FUN_00d175f0(const SweepVector* shift, SweepVector* effective, void* added);
};
// Rounds a shift vector to integer scale, updates sweep axis values, and calls update for nodes crossing sweep boundaries.
// @fnv 0x00d175f0
void SweepManager::FUN_00d175f0(const SweepVector* shift, SweepVector* effective, void* added) {
    SweepVector rounded = *shift;
    __int64 delta[3];
    for (int a=0; a<3; ++a) {
        delta[a] = (__int64)(scale[a] * (&rounded.x)[a]) & ~(__int64)1;
        (&rounded.x)[a] = (float)delta[a] / scale[a];
    }
    *(__m128*)effective = *(__m128*)&rounded;
    SweepList removed;
    for (int axis=0; axis<3; ++axis) {
        SweepAxis* list = &axes[axis];
        int displacement = (int)delta[axis];
        int end, step, first;
        if (displacement < 0) { end=list->size-1; first=1; step=1; }
        else { first=list->size-2; _ReadWriteBarrier(); end=0; step=-1; }
        for (int position=first; position!=end; position+=step) {
            SweepEnd* ep = list->data+position;
            unsigned value=ep->value;
            if (value-2 > 0xfff9u) continue;
            int shifted=((displacement+value)&~1) | (value&1);
            SweepNode* original=nodes+ep->handle;
            if (shifted<0) shifted=value&1;
            else if (shifted>=0xfffc) shifted=(value&1)|0xfffc;
            ep->value=(unsigned short)shifted;
            if (shifted!=0 && shifted!=0xfffd) continue;
            SweepBounds bounds;
            SweepEnd* edgesX=axes[0].data;
            bounds.low[0]=edgesX[original->minX].value;
            SweepEnd* edgesY=axes[1].data;
            bounds.low[1]=edgesY[original->minY].value;
            SweepEnd* edgesZ=axes[2].data;
            bounds.low[2]=edgesZ[original->minZ].value;
            _ReadWriteBarrier();
            bounds.high[0]=edgesX[original->maxX].value;
            bounds.high[1]=edgesY[original->maxY].value;
            bounds.high[2]=edgesZ[original->maxZ].value;
            unsigned id=*original->handle;
            update(id,bounds,added,removed);
        }
    }
    removed.clear();
}

__forceinline void SweepManager::update(unsigned id, const SweepBounds& bounds, void* added, SweepList& removed) {
            SweepNode* crossing7; (void)crossing7;
            SweepNode* crossing6; (void)crossing6;
            SweepNode* crossing5; (void)crossing5;
            SweepNode* crossing4; (void)crossing4;
            SweepNode* node=nodes+id;
            unsigned xLeftOverlap; (void)xLeftOverlap;
            SweepNode* base=nodes;
            { // min_left, axis 0
                unsigned index=node->minX;
                SweepEnd* cursor=axes[0].data+index;
                unsigned adjacent=cursor[-1].value;
                while (bounds.low[0] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[-1];
                    cursor+=-1;
                    if ((adjacent&1)) {
                        unsigned overlaps = (( *(unsigned*)&node->maxY - *(unsigned*)&other->minY) | (*(unsigned*)&other->maxY - *(unsigned*)&node->minY));
                        other->maxX=(unsigned short)index;
                        if ((overlaps & 0x80008000u)==0) ::FUN_00d11c60(markers,(::FnvNode *)(node),id,(::FnvNode *)(other),(::FnvArr *)(added));
                    } else {
                        other->minX=(unsigned short)index;
                    }
                    --index;
                    adjacent=cursor[-1].value;
                }
                while (bounds.low[0] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    other->minX=(unsigned short)index;
                    --index;
                }
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[0];
                node->minX=(unsigned short)index;
                _ReadWriteBarrier();
            }
            { // max_right, axis 0
                unsigned index=node->maxX;
                SweepEnd* cursor=axes[0].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.high[0] > adjacent) {
                    *cursor=cursor[1];
                    ++index;
                    cursor+=1;
                    SweepNode* other=base+cursor->handle;
                    if (!(adjacent&1)) {
                        unsigned firstMax=*(unsigned*)&other->maxY;
                        unsigned secondMax=*(unsigned*)&node->maxY;
                        _ReadWriteBarrier();
                        unsigned secondGap=secondMax-*(unsigned*)&other->minY;
                        _ReadWriteBarrier();
                        unsigned firstGap=firstMax-*(unsigned*)&node->minY;
                        unsigned overlaps=firstGap|secondGap;
                        --other->minX;
                        if ((overlaps & 0x80008000u)==0) ::FUN_00d11c60(markers,(::FnvNode *)(node),id,(::FnvNode *)(other),(::FnvArr *)(added));
                    } else {
                        --other->maxX;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.high[0] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId || otherId==0) break;
                    ++index;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].maxX;
                    cursor+=1;
                    --*otherIndex;
                }
                adjacent=cursor[-1].value;
                while (bounds.high[0] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    --index;
                    if (!(adjacent&1)) {
                        unsigned short* mx=&other->minX;
                        xLeftOverlap = ((*(unsigned*)&node->maxY - *(unsigned*)&other->minY) | (*(unsigned*)&other->maxY - *(unsigned*)&node->minY));
                        ++*mx;
                        if ((xLeftOverlap & 0x80008000u)==0) ::fnv_00d11d00::RemoveOrAppendTagEntry((char *)(markers),(::fnv_00d11d00::TagEntity *)(node),id,(::fnv_00d11d00::TagOwner *)(other),(::fnv_00d11d00::PairArray *)(void *)(&removed));
                    } else {
                        ++other->maxX;
                    }
                    adjacent=cursor[-1].value;
                }
                while (bounds.high[0] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    --index;
                    *cursor=cursor[-1];
                    unsigned short* otherIndex=&base[otherId].maxX;
                    cursor+=-1;
                    ++*otherIndex;
                }
                node->maxX=(unsigned short)index;
                cursor->value=(unsigned short)bounds.high[0];
                cursor->handle=(unsigned short)id;
            }
            { // min_right, axis 0
                unsigned index=node->minX;
                SweepEnd* cursor=axes[0].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.low[0] > adjacent) {
                    unsigned otherId=cursor[1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[1];
                    cursor+=1;
                    ++index;
                    if ((adjacent&1)) {
                        unsigned overlaps = (( *(unsigned*)&node->maxY - *(unsigned*)&other->minY) | (*(unsigned*)&other->maxY - *(unsigned*)&node->minY));
                        --other->maxX;
                        if ((overlaps & 0x80008000u)==0) ::fnv_00d11d00::RemoveOrAppendTagEntry((char *)(markers),(::fnv_00d11d00::TagEntity *)(node),id,(::fnv_00d11d00::TagOwner *)(other),(::fnv_00d11d00::PairArray *)(void *)(&removed));
                    } else {
                        --other->minX;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.low[0] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId) break;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].minX;
                    cursor+=1;
                    --*otherIndex;
                    ++index;
                }
                node->minX=(unsigned short)index;
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[0];
            }
            { // min_left, axis 1
                unsigned index=node->minY;
                SweepEnd* cursor=axes[1].data+index;
                unsigned adjacent=cursor[-1].value;
                while (bounds.low[1] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    crossing4=base+otherId;
                    *cursor=cursor[-1];
                    cursor+=-1;
                    if ((adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing4->minZ;
                        overlaps |= crossing4->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing4->minX;
                        overlaps |= crossing4->maxX-node->minX;

                        crossing4->maxY=(unsigned short)index;
                        if ((overlaps & 0x8000u)==0) ::AppendPairToBuffer((::UnkRet *)(node),(::UnkRet *)(crossing4),added);
                    } else {
                        crossing4->minY=(unsigned short)index;
                    }
                    --index;
                    adjacent=cursor[-1].value;
                }
                while (bounds.low[1] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    other->minY=(unsigned short)index;
                    --index;
                }
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[1];
                node->minY=(unsigned short)index;
            }
            { // max_right, axis 1
                unsigned index=node->maxY;
                SweepEnd* cursor=axes[1].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.high[1] > adjacent) {
                    *cursor=cursor[1];
                    ++index;
                    cursor+=1;
                    crossing5=base+cursor->handle;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing5->minZ;
                        overlaps |= crossing5->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing5->minX;
                        overlaps |= crossing5->maxX-node->minX;

                        --crossing5->minY;
                        if ((overlaps & 0x8000u)==0) ::AppendPairToBuffer((::UnkRet *)(node),(::UnkRet *)(crossing5),added);
                    } else {
                        --crossing5->maxY;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.high[1] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId || otherId==0) break;
                    ++index;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].maxY;
                    cursor+=1;
                    --*otherIndex;
                }
                adjacent=cursor[-1].value;
                while (bounds.high[1] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    *cursor=cursor[-1];
                    crossing6=base+otherId;
                    cursor+=-1;
                    --index;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing6->minZ;
                        overlaps |= crossing6->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing6->minX;
                        overlaps |= crossing6->maxX-node->minX;

                        ++crossing6->minY;
                        if ((overlaps & 0x8000u)==0) ::AppendPairEntry((::FUN_00d11c10_cls *)(node),(::FUN_00d11c10_cls *)(crossing6),(::PairArray *)(void *)(&removed));
                    } else {
                        ++crossing6->maxY;
                    }
                    adjacent=cursor[-1].value;
                }
                while (bounds.high[1] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    --index;
                    *cursor=cursor[-1];
                    unsigned short* otherIndex=&base[otherId].maxY;
                    cursor+=-1;
                    ++*otherIndex;
                }
                node->maxY=(unsigned short)index;
                cursor->value=(unsigned short)bounds.high[1];
                cursor->handle=(unsigned short)id;
            }
            { // min_right, axis 1
                unsigned index=node->minY;
                SweepEnd* cursor=axes[1].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.low[1] > adjacent) {
                    unsigned otherId=cursor[1].handle;
                    crossing7=base+otherId;
                    *cursor=cursor[1];
                    cursor+=1;
                    ++index;
                    if ((adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing7->minZ;
                        overlaps |= crossing7->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing7->minX;
                        overlaps |= crossing7->maxX-node->minX;

                        --crossing7->maxY;
                        if ((overlaps & 0x8000u)==0) ::AppendPairEntry((::FUN_00d11c10_cls *)(node),(::FUN_00d11c10_cls *)(crossing7),(::PairArray *)(void *)(&removed));
                    } else {
                        --crossing7->minY;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.low[1] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId) break;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].minY;
                    cursor+=1;
                    --*otherIndex;
                    ++index;
                }
                node->minY=(unsigned short)index;
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[1];
            }
            { // min_left, axis 2
                unsigned index=node->minZ;
                SweepEnd* cursor=axes[2].data+index;
                unsigned adjacent=cursor[-1].value;
                while (bounds.low[2] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[-1];
                    cursor+=-1;
                    if ((adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        other->maxZ=(unsigned short)index;
                        if ((overlaps & 0x8000u)==0) ::AppendPairToBuffer((::UnkRet *)(node),(::UnkRet *)(other),added);
                    } else {
                        other->minZ=(unsigned short)index;
                    }
                    --index;
                    adjacent=cursor[-1].value;
                }
                while (bounds.low[2] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    other->minZ=(unsigned short)index;
                    --index;
                }
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[2];
                node->minZ=(unsigned short)index;
            }
            { // max_right, axis 2
                unsigned index=node->maxZ;
                SweepEnd* cursor=axes[2].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.high[2] > adjacent) {
                    *cursor=cursor[1];
                    ++index;
                    cursor+=1;
                    SweepNode* other=base+cursor->handle;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        --other->minZ;
                        if ((overlaps & 0x8000u)==0) ::AppendPairToBuffer((::UnkRet *)(node),(::UnkRet *)(other),added);
                    } else {
                        --other->maxZ;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.high[2] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId || otherId==0) break;
                    ++index;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].maxZ;
                    cursor+=1;
                    --*otherIndex;
                }
                adjacent=cursor[-1].value;
                while (bounds.high[2] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    --index;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        ++other->minZ;
                        if ((overlaps & 0x8000u)==0) ::AppendPairEntry((::FUN_00d11c10_cls *)(node),(::FUN_00d11c10_cls *)(other),(::PairArray *)(void *)(&removed));
                    } else {
                        ++other->maxZ;
                    }
                    adjacent=cursor[-1].value;
                }
                while (bounds.high[2] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    --index;
                    *cursor=cursor[-1];
                    unsigned short* otherIndex=&base[otherId].maxZ;
                    cursor+=-1;
                    ++*otherIndex;
                }
                node->maxZ=(unsigned short)index;
                cursor->value=(unsigned short)bounds.high[2];
                cursor->handle=(unsigned short)id;
            }
            { // min_right, axis 2
                unsigned index=node->minZ;
                SweepEnd* cursor=axes[2].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.low[2] > adjacent) {
                    unsigned otherId=cursor[1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[1];
                    cursor+=1;
                    ++index;
                    if ((adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        --other->maxZ;
                        if ((overlaps & 0x8000u)==0) ::AppendPairEntry((::FUN_00d11c10_cls *)(node),(::FUN_00d11c10_cls *)(other),(::PairArray *)(void *)(&removed));
                    } else {
                        --other->minZ;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.low[2] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId) break;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].minZ;
                    cursor+=1;
                    --*otherIndex;
                    ++index;
                }
                node->minZ=(unsigned short)index;
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[2];
            }
}
}  // namespace fnv_00d175f0

extern "C" void _ReadBarrier();
template<class T> struct Arr;
template<class T> struct Arr {
    T* data;
    int size;
    unsigned cap;
    __forceinline void SetSize(int n) {
        SetSize(hkMemoryRouter::getInstance().heap(), n);
    }
    __forceinline void SetSize(hkMemoryAllocator& a, int n) {
        int c = cap & 0x3fffffff;
        if (c < n) {
            int nc = c * 2;
            if (n >= nc) nc = n;
            ::FUN_00c908c0((::SpawnedObject *)(&a), (::SpawnedArray *)(void *)(this), nc, sizeof(T));
        }
        size = n;
    }
};
template<class T> static __forceinline void ReleaseTemp(Arr<T>& arr) {
    hkMemoryAllocator* a=&hkMemoryRouter::getInstance().temp();
    arr.size=0;
    if ((arr.cap & 0x80000000) == 0) a->bufFree(arr.data,(arr.cap & 0x3fffffff)*sizeof(T));
    arr.data=0;arr.cap=0x80000000;
}
template<class T> static __forceinline T* AllocateBuffer(int& n, unsigned& capacity) {
    T* p = n ? hkMemoryRouter::getInstance().temp()._bufAlloc<T>(n) : 0;
    capacity = n ? n : 0x80000000;
    return p;
}
template<class T> static __forceinline void FreeBuffer(T* data, unsigned capacity) {
    if ((capacity & 0x80000000) == 0) hkMemoryRouter::getInstance().temp().bufFree(data, (capacity & 0x3fffffff) * sizeof(T));
}
struct RawBox { unsigned lower, upper, axis; int* handle; };
struct Bounds {
    union { struct { unsigned short lo0, lo1; }; unsigned lo01; };
    union { struct { unsigned short hi0, hi1; }; unsigned hi01; };
};
struct Box {
    union { struct { unsigned short lo0, lo1; }; unsigned lo01; };
    union { struct { unsigned short hi0, hi1; }; unsigned hi01; };
    union { struct { unsigned short loZ, hiZ; }; unsigned zPair; };
    int* ref;
    void CopyPacked(const Box& b) { *(RawBox*)this = *(const RawBox*)&b; }
    Box& operator=(const Box& b) { CopyPacked(b); return *this; }
};
struct Key { unsigned short key, idx; };
struct RemovedHandle { int idx; };
struct RemovedHandleList { RemovedHandle** items; int count; };
struct Node { unsigned short idx, pad; Arr<unsigned short> arr; };
struct Stub_00d1a040 { int a, b, c;  };
struct Stub_00d1a0e0 { int a, b, c;  };
struct Stub_00d1a180 { int a, b, c;  };
struct AssignedSweep {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    Arr<Box> boxes;
    Stub_00d1a040 s_ac;
    Stub_00d1a0e0 s_b8;
    Stub_00d1a180 s_c4;
    int nodeCount;
    int unkD4;
    Node* nodes;
    void FUN_00d193e0(RemovedHandleList*, void*);
};
// Removes the listed boxes by moving the last boxes into their slots, calls FUN_00d138a0 and FUN_00d13620, and remaps node index arrays.
// @fnv 0x00d193e0
void AssignedSweep::FUN_00d193e0(RemovedHandleList* apRemoved, void* arg2)
{
    int count = apRemoved->count;
    int total = boxes.size;
    Box* current=0;
    Box* data=0;
    int marker = 0;
    unsigned capA; int sizeA = count + 1;
    Box* pSortedBoxes = AllocateBuffer<Box>(sizeA, capA);
    __declspec(align(16)) Box L = boxes.data[apRemoved->items[0]->idx];
    {
        unsigned capB; int sizeB = count + 4;
    Key* pSortKeys; hkMemoryAllocator* allocatorB=&hkMemoryRouter::getInstance().temp();
        if (sizeB) { int request=sizeB*4;
            pSortKeys=static_cast<Key*>(allocatorB->bufAlloc(request));
            sizeB=request/4;
        } else { pSortKeys=0; }
        capB=sizeB?sizeB:0x80000000;
        
        for (int i = 0; i < count; ++i) {
            int idx = apRemoved->items[i]->idx;
            Box& b = boxes.data[idx];
            pSortKeys[i].idx = idx;
            pSortKeys[i].key = b.loZ;
            unsigned short loZ = b.loZ; if (L.loZ >= loZ) L.loZ = loZ;
            if (L.lo0 >= b.lo0) L.lo0 = b.lo0;
            if (L.lo1 >= b.lo1) L.lo1 = b.lo1;
            if (L.hiZ <= b.hiZ) L.hiZ = b.hiZ;
            if (L.hi0 <= b.hi0) L.hi0 = b.hi0;
            if (L.hi1 <= b.hi1) L.hi1 = b.hi1;
        }
        unsigned capC; int sizeC = count + 4;
    Key* pScratch = AllocateBuffer<Key>(sizeC, capC);
        pSortKeys[count].key = 0xffff;
        pSortKeys[count + 1].key = 0xffff;
        pSortKeys[count + 2].key = 0xffff;
        ::FUN_00d9fcf0((unsigned int *)(pSortKeys), (count + 3) & ~3, (unsigned int *)(pScratch));
        for (int i = 0; i < count; ++i) {
            Box& b = boxes.data[pSortKeys[i].idx];
            pSortedBoxes[i].CopyPacked(b);
            *b.ref = 0;
            b.ref = &marker;
        }
        pSortedBoxes[count].loZ = 0xffff;
        FreeBuffer(pScratch, capC);
        FreeBuffer(pSortKeys, capB);
    }
    Arr<int> D;
    D.data = 0; D.size = 0; D.cap = 0x80000000;
    int reserve = nodeCount + count;
    if ((int)(D.cap & 0x3fffffff) < reserve)
        ::FUN_00c908c0((::SpawnedObject *)(&hkMemoryRouter::getInstance().temp()), (::SpawnedArray *)(void *)(&D), reserve, 4);
    unsigned capE; int sizeE = total;
    Arr<int> view;
    view.data = AllocateBuffer<int>(sizeE, capE);
    int* E = view.data;
    view.size = sizeE; view.cap = capE;
    int iOverlapCount = 0;
    unsigned capG; int sizeG = total - count + 4;
    Key* pOverlapKeys = AllocateBuffer<Key>(sizeG, capG);
    int last = total - 1;
    E[0] = 0;
    for (int i = 1; i <= last; ++i) {
        data = &boxes.data[0];
        current=data+i;
        if (data[last].ref == &marker) {
            E[last] = -1;
            --last;
            --i;
            continue;
        }
        if (current->ref == &marker) {
            current->CopyPacked(data[last]);
            E[last]=i; E[i]=-1; --last; constructWithCopy(D.data + D.size, 1, i);
            ++D.size;
            int* r = current->ref;
            if (!((uintptr_t)r & 1)) {
                *r = i;
            } else {
                *(unsigned short*)((char*)nodes + ((uintptr_t)r & ~(uintptr_t)1)) = (unsigned short)i;
                continue;
            }
        } else {
            E[i] = i;
        }
        Box& b=*current;
        if (0 == (((b.hi01 - L.lo01) | (L.hi01 - b.lo01)) & 0x80008000)) {
            unsigned short lo = b.loZ;
            unsigned short t = b.hi0 - L.lo0;
            t |= b.hiZ - L.loZ;
            t |= L.hi0 - b.lo0;
            t |= L.hiZ - lo;
            if ((t & 0x8000) == 0) {
                pOverlapKeys[iOverlapCount].key = lo;
                pOverlapKeys[iOverlapCount].idx = i;
                ++iOverlapCount;
            }
        }
    }
    boxes.SetSize(last + 1);
    unsigned capret; int sizeret = iOverlapCount + 1;
    Box* pOverlapBoxes = AllocateBuffer<Box>(sizeret, capret);
    {
        unsigned capI; int sizeI = iOverlapCount + 4;
    Key* pOverlapScratch = AllocateBuffer<Key>(sizeI, capI);
        pOverlapKeys[iOverlapCount].key = 0xffff;
        pOverlapKeys[iOverlapCount + 1].key = 0xffff;
        pOverlapKeys[iOverlapCount + 2].key = 0xffff;
        ::FUN_00d9fcf0((unsigned int *)(pOverlapKeys), (iOverlapCount + 3) & ~3, (unsigned int *)(pOverlapScratch));
        for (int j = 0; j < iOverlapCount; ++j)
            { Box& b=boxes.data[pOverlapKeys[j].idx];
            pOverlapBoxes[j].CopyPacked(b); }
        pOverlapBoxes[iOverlapCount].loZ = 0xffff;
        FreeBuffer(pOverlapScratch, capI);
    }
    ::CollectNodePairs(this, (::S_00d138a0_Node *)(pSortedBoxes), count, static_cast<::S_00d138a0_Array *>(arg2));
    reinterpret_cast<::C_00d13620 *>(this)->BuildBroadPhasePairs((::S_00d138a0_Node *)(pSortedBoxes), count, (::S_00d138a0_Node *)(pOverlapBoxes), iOverlapCount, 1, *static_cast<::BroadPhasePairArray *>(arg2));
    reinterpret_cast<::fnv_00d1a040::Container *>(&(s_ac))->FUN_00d1a040((char *)(boxes.data), (int **)(::Arr<int> *)(&view));
    reinterpret_cast<::D1A0E0EntryArray *>(&(s_b8))->FUN_00d1a0e0((char *)(boxes.data), (*(const ::D1A0E0IntArray *)(&view)));
    reinterpret_cast<::S_00d1a180_Axis *>(&(s_c4))->RemapEndPoints((char *)(boxes.data), (*(const ::S_00d1a180_IntArray *)(&view)));
    if (nodeCount) {
        int twoN = count + count;
        for (int k = 0; k < nodeCount; ++k) {
            Node* nd = &nodes[k];
            Box& b = boxes.data[nd->idx];
            b.hi0 -= twoN;
            b.hi1 -= twoN;
            int cnt = 0;
            for (int j = 0; j < nd->arr.size; ++j) {
                int v = E[nd->arr.data[j]];
                if (v >= 0) nd->arr.data[cnt++] = v;
            }
            nd->arr.SetSize(cnt);
        }
    }
    for (int i = 0; i < D.size; ++i) reinterpret_cast<::S_d11790_Sweep *>(this)->FixNodeEdges(D.data[i]);
    FreeBuffer(pOverlapBoxes, capret);
    FreeBuffer(pOverlapKeys, capG);
    FreeBuffer(E, capE);
    ReleaseTemp(D);
    FreeBuffer(pSortedBoxes, capA);
}

// Moved from hkp3axissweep_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_01267000.h"
void ToggleBit(int a, void* b);
void FUN_00d10af0(int index, unsigned int* bits);
SpawnedObject* FUN_00d182a0(const void* a, const void* b, int c);
static int FUN_00d10b10(void* self, int index, unsigned int* bits);
int IsBitmapBitSet(void* table, int index, unsigned int* bits);
int __cdecl FUN_00d10ac0();
void __cdecl FUN_00d10ff0();
__declspec(align(16)) struct S00d10b30_Node {
    __m64 lo;
    __m64 hi;
};

struct S00d10b30_Bnd {
    short lo0;
    short lo1;
    short lo2;
    short lo3;
    short hi0;
    short hi1;
};

// @fnv 0x00d10b30
void FUN_00d10b30(S00d10b30_Node* nodes, int n, const S00d10b30_Bnd* bnd)
{
    S00d10b30_Node r1, r2;
    reinterpret_cast<short*>(&r1.hi)[1] = reinterpret_cast<short*>(&r1.hi)[0] = bnd->hi0 - 1;
    reinterpret_cast<short*>(&r1.lo)[2] = reinterpret_cast<short*>(&r1.lo)[0] = bnd->lo0 - 1;
    reinterpret_cast<short*>(&r1.lo)[3] = reinterpret_cast<short*>(&r1.lo)[1] = bnd->lo1 - 1;
    reinterpret_cast<short*>(&r2.hi)[1] = reinterpret_cast<short*>(&r2.hi)[0] = bnd->hi1 - 2;
    reinterpret_cast<short*>(&r2.lo)[2] = reinterpret_cast<short*>(&r2.lo)[0] = bnd->lo2 - 2;
    reinterpret_cast<short*>(&r2.lo)[3] = reinterpret_cast<short*>(&r2.lo)[1] = bnd->lo3 - 2;
    __m64 mask = _mm_set_pi32(0, -1);

    S00d10b30_Node* end = nodes + n;
    for (S00d10b30_Node* p = nodes; p < end; ++p) {
        __m64 lo = p->lo;
        __m64 hi = p->hi;
        p->lo = _mm_sub_pi16(lo, _mm_add_pi16(_mm_cmpgt_pi16(lo, r1.lo), _mm_cmpgt_pi16(lo, r2.lo)));
        p->hi = _mm_sub_pi16(hi, _mm_and_si64(mask, _mm_add_pi16(_mm_cmpgt_pi16(hi, r1.hi), _mm_cmpgt_pi16(hi, r2.hi))));
    }
    _mm_empty();
}

__declspec(align(16)) struct BpRefBounds {
    unsigned short lo0;
    unsigned short lo1;
    unsigned short lo2;
    unsigned short lo3;
    unsigned short hi0;
    unsigned short hi1;
    unsigned short hi2;
    unsigned short hi3;
};

struct BpDeltaPair {
    unsigned int lo;
    unsigned int hi;
};

// @fnv 0x00d10c40
void FUN_00d10c40(FourIntegerBlock* nodes, int n, int delta, const int* bound)
{
    BpRefBounds ref;
    ref.hi0 = (unsigned short)(bound[0] - 1);
    ref.hi1 = ref.hi0;
    ref.lo0 = (unsigned short)(bound[1] - 1);
    ref.lo2 = ref.lo0;
    ref.lo1 = (unsigned short)(bound[2] - 1);
    ref.lo3 = ref.lo1;

    unsigned int d = (unsigned int)delta * 0x10001u;
    __m64 dAll = _mm_set_pi32(d, d);
    __m64 dHi = _mm_set_pi32(0, d);
    __m64 refLo = *(__m64*)&ref.lo0;
    __m64 refHi = *(__m64*)&ref.hi0;

    FourIntegerBlock* end = nodes + n;
    for (FourIntegerBlock* p = nodes; p < end; ++p) {
        __m64 lo = *(__m64*)&p->unk00;
        __m64 hi = *(__m64*)&p->unk08;
        *(__m64*)&p->unk00 = _mm_add_pi16(lo, _mm_and_si64(_mm_cmpgt_pi16(lo, refLo), dAll));
        *(__m64*)&p->unk08 = _mm_add_pi16(hi, _mm_and_si64(_mm_cmpgt_pi16(hi, refHi), dHi));
    }
    _mm_empty();
}

struct BpBoundNode { __m64 lo; __m64 hi; };
struct BpBoundWords { unsigned short lo0, lo1, lo2, lo3, hi0, hi1; };
struct __declspec(align(16)) ReferenceBounds {
    unsigned short min0, min1, min2, min3;
    unsigned short max0, max1;
    unsigned int maxSentinels;
};
// @fnv 0x00d10d10
void FUN_00d10d10(BpBoundNode* nodes, int n, const BpBoundWords* bnd)
{
    ReferenceBounds first, second;
    __m64 mask;
    unsigned int hi0 = bnd->hi0;
    first.max0 = hi0; first.max1 = hi0;
    unsigned int lo0 = bnd->lo0;
    first.min0 = lo0; first.min2 = lo0;
    unsigned int lo1 = bnd->lo1;
    first.min1 = lo1; first.min3 = lo1;
    unsigned int hi1 = bnd->hi1;
    second.max0 = hi1; second.max1 = hi1;
    unsigned int lo2 = bnd->lo2;
    second.min0 = lo2; second.min2 = lo2;
    unsigned int lo3 = bnd->lo3;
    second.min1 = lo3; second.min3 = lo3;
    BpBoundNode* end = nodes + n;
    first.maxSentinels = 0xffffffff;
    second.maxSentinels = 0xffffffff;
    mask = _mm_set_pi32(0, -1);
    __m64 a = *(__m64*)&first.min0;
    __m64 b = *(__m64*)&first.max0;
    __m64 d = *(__m64*)&second.max0;
    for (BpBoundNode* p = nodes; p != end; ++p) {
        __m64 lo = p->lo;
        __m64 hi = p->hi;
        __m64 t0 = _mm_cmpgt_pi16(lo, a);
        __m64 t1 = _mm_cmpgt_pi16(lo, *(__m64*)&second.min0);
        t0 = _mm_add_pi16(t0, t1);
        p->lo = _mm_add_pi16(lo, t0);
        __m64 u0 = _mm_cmpgt_pi16(hi, b);
        __m64 u1 = _mm_cmpgt_pi16(hi, d);
        u0 = _mm_and_si64(_mm_add_pi16(u0, u1), mask);
        p->hi = _mm_add_pi16(hi, u0);
    }
    _mm_empty();
}

int fnv_FloatToInt(float fValue);


struct SweepVec4 { __m128 m_vComponents; };
struct SweepAabb { SweepVec4 m_kMinimumCorner; SweepVec4 m_kMaximumCorner; };
struct SweepAabbInt { int m_min0; int m_min1; int m_min2; int m_min3; int m_max0; int m_max1; int m_max2; int m_max3; };

struct SweepCls {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int v14(void* a, SweepAabbInt* b, int c);
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    SweepVec4 m_kVectorAt40;
    SweepVec4 m_kVectorAt50;
    SweepVec4 m_vScale;
    int FUN_00d114e0(void* a1, const SweepAabb& aabb, int a3);
};

// @fnv 0x00d114e0
int SweepCls::FUN_00d114e0(void* a1, const SweepAabb& aabb, int a3)
{
    SweepAabbInt out;
    const __m128 maxVal = ::DAT_011b6d70;
    {
        __m128 v = _mm_add_ps(m_kVectorAt40.m_vComponents, aabb.m_kMinimumCorner.m_vComponents);
        v = _mm_mul_ps(v, m_vScale.m_vComponents);
        v = _mm_min_ps(v, maxVal);
        v = _mm_max_ps(v, (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
        SweepVec4 t; t.m_vComponents = v;
        const float* f = (const float*)&t;
        out.m_min0 = fnv_FloatToInt(f[0]);
        out.m_min1 = fnv_FloatToInt(f[1]);
        out.m_min2 = fnv_FloatToInt(f[2]);
        out.m_min3 = fnv_FloatToInt(f[3]);
    }
    {
        __m128 v = _mm_add_ps(m_kVectorAt50.m_vComponents, aabb.m_kMaximumCorner.m_vComponents);
        v = _mm_mul_ps(v, m_vScale.m_vComponents);
        v = _mm_min_ps(v, maxVal);
        v = _mm_max_ps(v, (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
        SweepVec4 t; t.m_vComponents = v;
        const float* f = (const float*)&t;
        out.m_max0 = fnv_FloatToInt(f[0]);
        out.m_max1 = fnv_FloatToInt(f[1]);
        out.m_max2 = fnv_FloatToInt(f[2]);
        out.m_max3 = fnv_FloatToInt(f[3]);
    }
    return v14(a1, &out, a3);
}

// Axis0 candidate-bitset sweep. First argument is updated node count,
// independently confirmed at the real caller; it is not allocation words.
// Destination is16-byte aligned raw bit storage with caller padding.

inline void flip(hkUint32* bits, int i) {
    int idx = i >> 5;
    bits[idx] ^= 1u << (i & 31);
}
inline void clear(hkUint32* bits, int i) {
    int idx = i >> 5;
    bits[idx] &= ~(1u << (i & 31));
}
// @fnv 0x00d112c0
void S_00d112c0::FUN_00d112c0(int numNodes, int key, const S_00d112c0_Node* aabb, hkUint16 skip, hkUint32* bits)
{
    unsigned minX = aabb->m_min0;
    unsigned maxX = aabb->m_max0;
    int n = numNodes >> 7;
    __m128 zero = _mm_setzero_ps();
    hkUint32* const b0 = bits;
    __m128* d = (__m128*)b0;
    for (; n >= 0; n--) {
        __m128* t = d;
        d++;
        _mm_store_ps((float*)t, zero);
    }
    S_00d112c0_EndPoint* ep = m_ep + 1;
    if (m_iMarkerCount) {
        key >>= (16 - m_markerShift);
        if (key > 0) {
            const S_00d112c0_Marker* m = &m_pOverlappingMarkerInfo[key - 1];
            flip(bits, m->m_usIndex);
            const hkUint16* l = m->m_kNode;
            int c = m->m_uiItemCount - 1;
            while (c >= 0) {
                if (*l != skip)
                    flip(bits, *l);
                l++;
                c--;
            }
            const S_00d112c0_Node* n = &m_kNodeCollection[m->m_usIndex];
            S_00d112c0_EndPoint* p = m_ep + n->m_min0 + 1;
            S_00d112c0_EndPoint* e = m_ep + n->m_max0;
            for (; p < e; p++)
                if (!(p->m_uiFilterValue & 1))
                    clear(bits, p->m_usIndex);
            ep = m_ep + n->m_min0 + 1;
        }
    }
    S_00d112c0_EndPoint* e1 = m_ep + minX;
    for (; ep < e1; ep++)
        flip(bits, ep->m_usIndex);
    ep++;
    S_00d112c0_EndPoint* e2 = m_ep + maxX;
    for (; ep < e2; ep++)
        if (!(ep->m_uiFilterValue & 1))
            flip(bits, ep->m_usIndex);
}

struct ObjPrefix { unsigned short f0; unsigned short f1; };
struct Obj8 : ObjPrefix { unsigned short f2; unsigned short f3; unsigned short f4; unsigned short f5; int tail; __forceinline unsigned short& slot0(){return f0;} __forceinline unsigned short& slot1(){return f1;} __forceinline unsigned short& slot2(){return f2;} __forceinline unsigned short& slot3(){return f3;} __forceinline unsigned short& slot4(){return f4;} __forceinline unsigned short& slot5(){return f5;} };
union End8 { struct { unsigned short key; unsigned short id; }; unsigned int packed; };
struct Mgr8;
struct __declspec(align(16)) QuantMin40 { unsigned short x,y,z,w; };
struct Vec33 {
    __m128 data;
    __forceinline void setZero() { data=_mm_setzero_ps(); }
    __forceinline void setAdd4(const Vec33& a,const Vec33& b) { data=_mm_add_ps(a.data,b.data); }
    __forceinline void mul4(const Vec33& b) { data=_mm_mul_ps(data,b.data); }
    __forceinline void min4(const Vec33& b) { data=_mm_min_ps(data,b.data); }
    __forceinline void max4(const Vec33& b) { data=_mm_max_ps(data,b.data); }
    __forceinline void add4(const Vec33& b) { data=_mm_add_ps(data,b.data); }
};
struct Bounds33 { unsigned int min[4]; unsigned int max[4]; };
struct VPair8 { Vec33 v0; Vec33 v1; };
struct Sweep8 {
    int m00; int m04; int m08; int m0c; int m10; int m14; int m18; int m1c;
    int m20; int m24; int m28; int m2c; int m30; int m34; int m38; int m3c;
    Vec33 row40; Vec33 row50; Vec33 row60;
    int m70; int m74; int m78; int m7c; int m80; int m84; int m88; int m8c;
    int m90; int m94; int m98; int m9c;
    Obj8* objs; int mA4; int mA8; End8* listA; int mB0; int mB4; End8* listB; int mB8dummy;
    int mC0; End8* listC; int mC8; int mCC; int mD0; int mD4; Mgr8* mgr; int mDC;
    __forceinline void convert33(const char* addr, Bounds33& out) {
const VPair8* a1=(const VPair8*)addr; Vec33 zero; zero.setZero();
            Vec33 clamp; clamp.data=_mm_load_ps(DAT_011b3790);
            const Vec33& bias=*(const Vec33*)DAT_011b3770;
            Vec33 pw, qw;
            pw.setAdd4(a1->v0,row40); pw.mul4(row60); pw.min4(clamp); pw.max4(zero); pw.add4(bias);
                        QuantMin40 qa;
            qa.x = (unsigned short)(reinterpret_cast<unsigned int*>(&pw.data)[0] >> 7);
            qa.y = (unsigned short)(reinterpret_cast<unsigned int*>(&pw.data)[1] >> 7);
            qa.z = (unsigned short)(reinterpret_cast<unsigned int*>(&pw.data)[2] >> 7);
            qw.setAdd4(a1->v1,row50); qw.mul4(row60); qw.min4(clamp); qw.max4(zero); qw.add4(bias);
            unsigned short u[4];
            u[0] = (unsigned short)(reinterpret_cast<unsigned int*>(&qw.data)[0] >> 7);
            u[1] = (unsigned short)(reinterpret_cast<unsigned int*>(&qw.data)[1] >> 7);
            u[2] = (unsigned short)(reinterpret_cast<unsigned int*>(&qw.data)[2] >> 7);

            out.min[0] = (*(unsigned int*)&qa.x) & 0xfffe; out.min[1] = (*(unsigned int*)&qa.y) & 0xfffe; out.min[2] = (*(unsigned int*)&qa.z) & 0xfffe;
            out.max[0] = u[0] | 1;
            out.max[1] = u[1] | 1;
            out.max[2] = u[2] | 1;

    }
    __forceinline void axis34_0(Obj8* key, unsigned int r, Obj8& current, unsigned int lower, unsigned int upper, void* a3, void* a4) {
Obj8* ep=&current;
            // P1: listA, pos field f4 (offset 8), p lower, backward + equal tail
            {
                End8* list = listA;
                int obj = ep->f4;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot5() = (unsigned short)obj;
                            if ((overlaps & 0x80008000) == 0)
                                ::FUN_00d11c60(mgr, (::FnvNode *)(ep), r, (::FnvNode *)(other), (::FnvArr *)(a3));
                        } else {
                            other->slot4() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot4() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
                ep->f4 = (unsigned short)obj;
            }
            // P2: listA, pos field f5, p upper, forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listA;
                int obj = ep->f5;
                End8* i = list + obj;
                unsigned int p;
                p = upper;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
 Obj8* other; (void)other;
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot4()--;
                            if ((overlaps & 0x80008000) == 0)
                                ::FUN_00d11c60(mgr, (::FnvNode *)(ep), r, (::FnvNode *)(other), (::FnvArr *)(a3));
                        } else {
                            other->slot5()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        if (!nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot5()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        i[0].packed = i[-1].packed;
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i--;
                        obj--;
                        if ((n & 1) == 0) {
                            int a; unsigned int end; (void)a; end = (*(int*)&ep->f2) - (*(int*)&other->f0); a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            other->slot4()++;
                            if (((a | end) & 0x80008000) == 0)
                                ::fnv_00d11d00::RemoveOrAppendTagEntry((char *)(mgr), (::fnv_00d11d00::TagEntity *)(ep), r, (::fnv_00d11d00::TagOwner *)(other), (::fnv_00d11d00::PairArray *)(a4));
                        } else {
                            other->slot5()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot5()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f5 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
            }
            // P1 forward: listA, pos field f4, p lower, forward + fwd-equal
            {
                End8* list = listA;
                int obj = ep->f4;
                End8* i = list + obj;
                unsigned int otherIdx = i[1].key;
                unsigned int p = lower;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        obj++;
                        if (otherIdx & 1) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot5()--;
                            if ((overlaps & 0x80008000) == 0)
                                ::fnv_00d11d00::RemoveOrAppendTagEntry((char *)(mgr), (::fnv_00d11d00::TagEntity *)(ep), r, (::fnv_00d11d00::TagOwner *)(other), (::fnv_00d11d00::PairArray *)(a4));
                        } else {
                            other->slot4()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot4()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f4 = (unsigned short)obj;
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
            }

    }
    __forceinline void axis34_1(Obj8* key, unsigned int r, Obj8& current, unsigned int lower, unsigned int upper, void* a3, void* a4) {
Obj8* ep=&current;
            // P4 backward: listB, pos field f0, p lower, backward + bwd-equal (4x u16 overlap test)
            {
                End8* list = listB;
                int obj = ep->f0;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            unsigned short a = (unsigned short)((unsigned short)((*(int*)&ep->f2) >> 16) - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot2() = (unsigned short)obj;
                            if ((a & 0x8000) == 0)
                                ::AppendPairToBuffer((::UnkRet *)(ep), (::UnkRet *)(other), (void *)(a3));
                        } else {
                            other->slot0() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot0() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
                ep->f0 = (unsigned short)obj;
            }
            // P5: listB, pos field f2, p upper, forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listB;
                int obj = ep->f2;
                End8* i = list + obj;
                unsigned int p = upper;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        Obj8* other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            unsigned short a = (unsigned short)((unsigned short)((*(int*)&ep->f2) >> 16) - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot0()--;
                            if ((a & 0x8000) == 0)
                                ::AppendPairToBuffer((::UnkRet *)(ep), (::UnkRet *)(other), (void *)(a3));
                        } else {
                            other->slot2()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        if (nextKey == 0) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot2()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        i[0].packed = i[-1].packed;
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i--;
                        obj--;
                        if ((n & 1) == 0) {
                            unsigned short a = (unsigned short)(ep->f3 - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot0()++;
                            if ((a & 0x8000) == 0)
                                ::AppendPairEntry((::FUN_00d11c10_cls *)(ep), (::FUN_00d11c10_cls *)(other), (::PairArray *)(a4));
                        } else {
                            other->slot2()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot2()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f2 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
            }
            // P4 forward: listB, pos field f0, p lower, forward + fwd-equal
            {
                End8* list = listB;
                int obj = ep->f0;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i += 1;
                        obj++;
                        if (otherIdx & 1) {
                            unsigned short a = (unsigned short)(ep->f3 - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot2()--;
                            if ((a & 0x8000) == 0)
                                ::AppendPairEntry((::FUN_00d11c10_cls *)(ep), (::FUN_00d11c10_cls *)(other), (::PairArray *)(a4));
                        } else {
                            other->slot0()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot0()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f0 = (unsigned short)obj;
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
            }

    }

    void FUN_00d12040(int** a0, const char* a1, int a2, void* volatile a3, void* volatile a4);
};
// @fnv 0x00d12040
void Sweep8::FUN_00d12040(int** a0, const char* a1, int a2, void* volatile a3, void* volatile a4)
{
    
    int** r;
    int** res = a0 + a2;
    r = a0;

    if (r < res) {
        do {
            Bounds33 bounds; convert33(a1, bounds);
            unsigned int pObj;
            Obj8* key;
            key = objs;
            pObj = **r;
            Obj8* ep;
            ep = key + pObj;
            axis34_0(key,pObj,*ep,bounds.min[0],bounds.max[0],a3,a4);
            axis34_1(key,pObj,*ep,bounds.min[1],bounds.max[1],a3,a4);
            {
 void* added=a3; void* removed=a4;

            // P7 backward: listC, pos field f1, p bounds.min[2], backward + bwd-equal (4x u16 overlap test, pairs f5/f4 + f2/f0)
            {
                End8* list = listC;
                int obj = ep->f1;
                End8* i = list + obj;
                unsigned int p = bounds.min[2];
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            unsigned short a;
                            a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot3() = (unsigned short)obj;
                            if ((a & 0x8000) == 0)
                                ::AppendPairToBuffer((::UnkRet *)(ep), (::UnkRet *)(other), (void *)(added));
                        } else {
                            other->slot1() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (pObj >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot1() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->id = (unsigned short)pObj;
                ((End8*)i)->key = (unsigned short)p;
                ep->f1 = (unsigned short)obj;
            }
            // P8: listC, pos field f3, p bounds.max[2], forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listC;
                int obj = ep->f3;
                End8* i = list + obj;
                unsigned int p = bounds.max[2];
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        Obj8* other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            unsigned short a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot1()--;
                            if ((a & 0x8000) == 0)
                                ::AppendPairToBuffer((::UnkRet *)(ep), (::UnkRet *)(other), (void *)(added));
                        } else {
                            other->slot3()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (pObj <= nextKey) break;
                        if (nextKey == 0) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot3()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        i[0].packed = i[-1].packed;
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i--;
                        obj--;
                        if ((n & 1) == 0) {
                            unsigned short a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot1()++;
                            if ((a & 0x8000) == 0)
                                ::AppendPairEntry((::FUN_00d11c10_cls *)(ep), (::FUN_00d11c10_cls *)(other), (::PairArray *)(removed));
                        } else {
                            other->slot3()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (pObj >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot3()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f3 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)pObj;
            }
            // P7 forward: listC, pos field f1, p bounds.min[2], forward + fwd-equal
            {
                End8* list = listC;
                int obj = ep->f1;
                End8* i = list + obj;
                unsigned int p = bounds.min[2];
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        obj++;
                        if (otherIdx & 1) {
                            unsigned short a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot3()--;
                            if ((a & 0x8000) == 0)
                                ::AppendPairEntry((::FUN_00d11c10_cls *)(ep), (::FUN_00d11c10_cls *)(other), (::PairArray *)(removed));
                        } else {
                            other->slot1()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (pObj <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot1()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f1=(unsigned short)obj;
i->id=(unsigned short)pObj;
i->key=(unsigned short)p;
a1+=sizeof(Vec33);
a1+=sizeof(Vec33);
            }

    }

r += 1;
        } while (r < res);
    }
}
namespace fnv_00d154a0 {
extern "C" void _ReadWriteBarrier(void);

struct Obj154 {
    virtual float unk00(int a, int b);
    virtual float call4(int a, int b);
};

struct Entry16 {
    unsigned short key;
    unsigned short pad;
    unsigned short* list;
    int count;
    int capacity;
};
struct Node16 {
    int f0; int f4;
    unsigned short f8;
    unsigned short f10;
    int f12;
};
struct Elem64 {
    int minPair;
    int maxPair;
    int unk8;
    int handle;
};

// A view beginning at one node's packed maximum and ending at the next node's minimum.
struct NodeTail154 { int maxPair,unk8,handle,nextMinPair; };

struct Axis154 {
    Entry* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    __forceinline void search(int low,int high,unsigned short& lower,unsigned short& upper) {
        Entry* base=m_data;
        Entry* last=base+m_iElementCount-2;
        Entry* res=::LowerBoundEntry(base+1, last, (unsigned short)low);
        lower=(unsigned short)(res-base);
        res=::LowerBoundEntry(base+1, last, (unsigned short)high);
        upper=(unsigned short)(res-(base+1));
    }

};

struct Aabb154 {__m128 min,max;};
struct Input154 { const Aabb154* p; Input154(const Aabb154* q):p(q) {} };
struct Callback154 { Obj154* p; Callback154(Obj154* q):p(q) {} };
struct Sweep154 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    __m128 unk40;
    __m128 unk50;
    __m128 unk60;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    Node16* unkA0;
    int unkA4;
    int unkA8;
    int* unkAC;
    int unkB0, unkB4;
    Axis154 axisB8;
    Axis154 axisC4;
    int unkD0;
    int unkD4;
    Entry16* unkD8;

    void FUN_00d154a0(Input154 input, Callback154 callback);
};

static void toggleBit(int* buf,int v){int idx=v>>5;int mask=1<<(v&31);buf[idx]^=mask;}
static void clearBit(int* buf,int v){int idx=v>>5;int mask=1<<(v&31);buf[idx]&=~mask;}
// @fnv 0x00d154a0
void Sweep154::FUN_00d154a0(Input154 input, Callback154 callback) {
    int* wordEnd;
    (void)&wordEnd; // Keep the end pointer first in the compiler's local-symbol ordering.
    int count = unkA4;
    int nInts = (count >> 5) + 8;
    hkMemoryAllocator* alloc = &hkMemoryRouter::getInstance().temp();
    int* buf;
    int cap;
    if (nInts != 0) {
        int reqSize=nInts*4;
        int* data=static_cast<int*>(alloc->bufAlloc(reqSize));
        int capacity=reqSize/4;
        buf=data;
        _ReadWriteBarrier();
        cap=capacity;
    } else {buf=0;cap=0;}
    if(!cap) cap=0x80000000;
    int nWords = count >> 7;
    __m128 zero = _mm_setzero_ps();
    __m128* zp = (__m128*)buf;
    for (int i = nWords; i >= 0; i--) { _mm_store_ps((float*)zp++, zero); }
    __m128 in0 = input.p->min;
    __m128 in1 = input.p->max;
    const __m128& scale = unk60;
    __m128 cmax = (*reinterpret_cast<__m128 *>(&::DAT_011b3790));
    const __m128& coff = (*reinterpret_cast<__m128 *>(&::DAT_011b3770));
    __m128 r = _mm_add_ps(_mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(unk40, in0), scale), cmax), zero), coff);
    struct Scratch154 { unsigned short ep[4]; union { __m128 vector; unsigned int u[4]; struct {int low[4],high[4];} bounds; } tmp; } scratch;
    scratch.tmp.vector = r;

    scratch.ep[0] = (unsigned short)(scratch.tmp.u[0] >> 7);
    scratch.ep[1] = (unsigned short)(scratch.tmp.u[1] >> 7);
    scratch.ep[2] = (unsigned short)(scratch.tmp.u[2] >> 7);
    __m128 r2 = _mm_add_ps(_mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(unk50, in1), scale), cmax), zero), coff);
    scratch.tmp.vector = r2;
    unsigned int hx=scratch.tmp.u[0]>>7,hy=scratch.tmp.u[1]>>7,hz=scratch.tmp.u[2]>>7;

    scratch.tmp.bounds.low[0] = *(int*)&scratch.ep[0] & 0xfffe;
    scratch.tmp.bounds.low[1] = *(int*)&scratch.ep[1] & 0xfffe;
    scratch.tmp.bounds.low[2] = *(int*)&scratch.ep[2] & 0xfffe;
    scratch.tmp.bounds.high[0] = (unsigned short)hx | 1;
    scratch.tmp.bounds.high[1] = (unsigned short)hy | 1;
    scratch.tmp.bounds.high[2] = (unsigned short)hz | 1;

    Endpoint* scan = (Endpoint*)unkAC + 1;
    if (unkD0 != 0) {
        int idx = scratch.tmp.bounds.low[0] >> (16 - unkD4);
        if (idx > 0) {
            Entry16* e = &unkD8[idx - 1];
            toggleBit(buf, e->key);
            unsigned short* cur = e->list;
            int rem = e->count - 1;
            while (rem >= 0) {
                toggleBit(buf, *cur);
                cur++;
                rem--;
            }
            Node16* node = &unkA0[e->key];
            Endpoint* axis=(Endpoint*)unkAC;
            int lower=node->f8,upper=node->f10;
            Endpoint* q=axis+lower+1;Endpoint* end=axis+upper;
            for (;q<end;q++) {
                if (!(q->value & 1))
                    clearBit(buf, q->handle);
            }
            scan = (Endpoint*)unkAC + node->f8 + 1;
        }
    }
    while (scan->value < (unsigned int)scratch.tmp.bounds.low[0]) {
        toggleBit(buf, scan->handle);
        scan++;
    }
    while (scan->value < (unsigned int)scratch.tmp.bounds.high[0]) {
        if (!(scan->value & 1))
            toggleBit(buf, scan->handle);
        scan++;
    }

    axisB8.search(scratch.tmp.bounds.low[1],scratch.tmp.bounds.high[1],scratch.ep[0],scratch.ep[2]);
    axisC4.search(scratch.tmp.bounds.low[2],scratch.tmp.bounds.high[2],scratch.ep[1],scratch.ep[3]);
    int* wp=buf;
    Elem64* ausAnimationGroup = (Elem64*)unkA0;
    wordEnd = buf + (unkA4 >> 5) + 1;
    if(wp < wordEnd) {
    Obj154* obj = callback.p;
    do {
        int word = *wp;
        NodeTail154* g = (NodeTail154*)&ausAnimationGroup[2].maxPair;
        while (word != 0) {
            if (word & 0xf) {
                if (word & 1) {
                    if ((((*(int*)&scratch.ep[2] - g[-3].nextMinPair) | (g[-2].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[-2].handle & 1))
                        obj->call4(g[-2].handle, 0);
                }
                if (word & 2) {
                    if ((((*(int*)&scratch.ep[2] - g[-2].nextMinPair) | (g[-1].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[-1].handle & 1))
                        obj->call4(g[-1].handle, 0);
                }
                if (word & 4) {
                    if ((((*(int*)&scratch.ep[2] - g[-1].nextMinPair) | (g[0].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[0].handle & 1))
                        obj->call4(g[0].handle, 0);
                }
                if (word & 8) {
                    if ((((*(int*)&scratch.ep[2] - g[0].nextMinPair) | (g[1].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[1].handle & 1))
                        obj->call4(g[1].handle, 0);
                }
            }
            word = (int)((unsigned int)word >> 4);
            g += 4;
        }
        ausAnimationGroup += 32;
        ++wp;
    }while(wp < wordEnd);

    }
    if (!(cap & 0x80000000))
        hkMemoryRouter::getInstance().temp().bufFree(buf, (cap & 0x3fffffff) * 4);
}

}  // namespace fnv_00d154a0

// @fnv 0x00d11000
static __declspec(noinline) unsigned int* FUN_00d11000(unsigned int* dst, int n)
{
    int i = n >> 4;
    __m128 zero = _mm_setzero_ps();
    if (i >= 0) {
        unsigned int* p = dst;
        do {
            unsigned int* cur = p;
            p = cur + 4;
            _mm_store_ps((float*)cur, zero);
            i--;
        } while (i >= 0);
        return p;
    }
    return dst;
}

unsigned int* volatile g_zeroDestination;
volatile int g_zeroLength;
unsigned int* CallZeroBlocks() { return FUN_00d11000(g_zeroDestination, g_zeroLength); }
namespace fnv_00d159a0 {
#include <xmmintrin.h>


inline hkMemoryAllocator& S159a0_stack() { return hkMemoryRouter::getInstance().temp(); }

struct S159a0_Node {
    unsigned short m_usValue00;
    unsigned short m_usValue02;
    unsigned short m_usValue04;
    unsigned short m_usValue06;
    unsigned short minX;
    unsigned short maxX;
    unsigned int handle;
    unsigned int yzDisjoint(const S159a0_Node& o) const
    {
        unsigned int maxA = *(const unsigned int*)&m_usValue04;
        unsigned int minB = *(const unsigned int*)&o.m_usValue00;
        unsigned int maxB = *(const unsigned int*)&o.m_usValue04;
        unsigned int minA = *(const unsigned int*)&m_usValue00;
        maxB -= minA;
        maxA -= minB;
        return (maxA | maxB) & 0x80008000;
    }
};
struct S159a0_NodeArray {
    S159a0_Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void destroy()
    {
        hkMemoryAllocator& a = S159a0_stack();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(S159a0_Node*));
    }
};

struct S159a0_U16Array {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S159a0_Marker {
    unsigned short m_usIndex;
    unsigned short m_uiFilterValue;
    S159a0_U16Array m_kMarkerIndices;
};
struct S159a0_Axis {
    Endpoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
union __declspec(align(16)) S159a0_IntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
union S159a0_QuadInt {
    __m128 q;
    unsigned int u[4];
};
struct __declspec(align(16)) S159a0_AabbInt {
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};
struct S159a0_Aabb {
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

struct S159a0_Vec { __m128 m_vComponents; };

inline void S159a0_convert(const __m128& in, const __m128& offset, const __m128& scale, const S159a0_Vec& minV, const S159a0_Vec& maxV, S159a0_IntUnion64& out)
{
    __m128 x = _mm_add_ps(offset, in);
    x = _mm_mul_ps(x, scale);
    x = _mm_min_ps(x, maxV.m_vComponents);
    x = _mm_max_ps(x, minV.m_vComponents);
    x = _mm_add_ps(x, (*reinterpret_cast<__m128 *>(&::DAT_011b3770)));
    S159a0_QuadInt u;
    u.q = x;
    out.u16[0] = (unsigned short)(u.u[0] >> 7);
    out.u16[1] = (unsigned short)(u.u[1] >> 7);
    out.u16[2] = (unsigned short)(u.u[2] >> 7);
}

inline void S159a0_flip(unsigned int* bits, int i) { int mask = 1 << (i & 31); int w = i >> 5; bits[w] ^= mask; }
inline void S159a0_clear(unsigned int* bits, int i) { int mask = 1 << (i & 31); int w = i >> 5; bits[w] &= ~mask; }

inline void S159a0_memClear16(void* dst, int numQuads)
{
    __m128 zero = _mm_setzero_ps();
    __m128* d = (__m128*)dst;
    for (int i = numQuads - 1; i >= 0; i--)
        _mm_store_ps((float*)d++, zero);
}

struct S159a0_Sweep {
    int unk00; int unk04; int unk08; int unk0c;
    __m128 unk10; __m128 unk20; __m128 unk30;
    __m128 m_kVectorAt40; __m128 m_kVectorAt50; __m128 m_vScale;
    __m128 unk70; __m128 unk80; __m128 unk90;
    S159a0_Node* m_kNodeCollection; int m_iNodeCount; int m_nodesCap;
    S159a0_Axis m_kAxisEndPoints[3];
    int m_iMarkerCount; int m_iMarkerCapacity; S159a0_Marker* m_pOverlappingMarkerInfo;
    __forceinline void querySingleAabbSub(unsigned int* handle, const unsigned int* bitField, const unsigned int* bitFieldEnd, const S159a0_Node& queryNode, S159a0_NodeArray& out);
    void FUN_00d159a0(const S159a0_Aabb& aabb, PairArray& out);
};

inline void S159a0_test(S159a0_Node* n, int k, const S159a0_Node& q, S159a0_NodeArray& arr)
{
    if (!q.yzDisjoint(n[k]) && !(n[k].handle & 1))
        arr.m_data[arr.m_iElementCount++] = &n[k];
}

__forceinline void S159a0_Sweep::querySingleAabbSub(unsigned int* handle, const unsigned int* bitField, const unsigned int* bitFieldEnd, const S159a0_Node& queryNode, S159a0_NodeArray& out)
{
    const unsigned int* b = bitField;
    S159a0_Node* nodes = &m_kNodeCollection[0];
    bitFieldEnd += (m_iNodeCount >> 5) + 1;
    for (; b < bitFieldEnd; nodes += 32, b++) {
        unsigned int bits = *b;
        if (!bits) continue;
        S159a0_Node* n = nodes;
        do {
            if (bits & 15) {
                if (bits & 1) S159a0_test(n, 0, queryNode, out);
                if (bits & 2) S159a0_test(n, 1, queryNode, out);
                if (bits & 4) S159a0_test(n, 2, queryNode, out);
                if (bits & 8) S159a0_test(n, 3, queryNode, out);
            }
            bits >>= 4;
            n += 4;
        } while (bits);
    }
}

// @fnv 0x00d159a0
void S159a0_Sweep::FUN_00d159a0(const S159a0_Aabb& aabb, PairArray& out)
{
    S159a0_NodeArray overlapping;
    overlapping.m_data = 0;
    overlapping.m_iElementCount = 0;
    overlapping.m_iCapacityState = 0x80000000;
    {
        int n = m_iNodeCount;
        if ((overlapping.m_iCapacityState & 0x3fffffff) < n)
            ::FUN_00c908c0((::SpawnedObject *)(&hkMemoryRouter::getInstance().temp()), (::SpawnedArray *)(::fnv_00d159a0::S159a0_NodeArray *)(&overlapping), n, 4);
    }

    int numNodes = m_iNodeCount;
    int bitFieldSize = (numNodes >> 5) + 8;
    unsigned int* b = 0;
    unsigned int* bitField;
    int bitFieldCap;
    {
        hkMemoryAllocator& a = S159a0_stack();
        if (bitFieldSize) {
            int bytes = bitFieldSize * 4;
            bitField = (unsigned int*)a.bufAlloc(bytes);
            bitFieldCap = bytes / 4;
        } else {
            bitField = 0;
            bitFieldCap = 0;
        }
        if (!bitFieldCap) bitFieldCap = 0x80000000;
    }
    S159a0_memClear16(bitField, (numNodes >> 7) + 1);
    S159a0_Vec clipMin;
    clipMin.m_vComponents = _mm_setzero_ps();
    S159a0_Vec clipMax;
    clipMax.m_vComponents = (*reinterpret_cast<__m128 *>(&::DAT_011b3790));

    S159a0_AabbInt aabbInt;
    S159a0_IntUnion64 mi;
    {
        S159a0_IntUnion64 ma;
        S159a0_convert(aabb.m_kMinimumCorner, m_kVectorAt40, m_vScale, clipMin, clipMax, mi);
        S159a0_convert(aabb.m_kMaximumCorner, m_kVectorAt50, m_vScale, clipMin, clipMax, ma);
        aabbInt.m_kMinimumCorner[0] = mi.u16[0] & 0xfffe;
        aabbInt.m_kMinimumCorner[1] = mi.u16[1] & 0xfffe;
        aabbInt.m_kMinimumCorner[2] = mi.u16[2] & 0xfffe;
        aabbInt.m_kMaximumCorner[0] = ma.u16[0] | 1;
        aabbInt.m_kMaximumCorner[1] = ma.u16[1] | 1;
        aabbInt.m_kMaximumCorner[2] = ma.u16[2] | 1;
    }

    Endpoint* ep = m_kAxisEndPoints[0].m_data + 1;
    if (m_iMarkerCount) {
        int mk = (int)aabbInt.m_kMinimumCorner[0] >> (16 - m_iMarkerCapacity);
        if (mk > 0) {
            S159a0_Marker* m = &m_pOverlappingMarkerInfo[mk - 1];
            S159a0_flip(bitField, m->m_usIndex);
            unsigned short* o = m->m_kMarkerIndices.m_data;
            for (int i = m->m_kMarkerIndices.m_iElementCount - 1; i >= 0; i--)
                S159a0_flip(bitField, *o++);
            S159a0_Node* node = &m_kNodeCollection[m->m_usIndex];
            Endpoint* e = m_kAxisEndPoints[0].m_data + node->minX + 1;
            Endpoint* end = m_kAxisEndPoints[0].m_data + node->maxX;
            for (; e < end; e++)
                if (!(e->value & 1)) S159a0_clear(bitField, e->handle);
            ep = m_kAxisEndPoints[0].m_data + node->minX + 1;
        }
    }
    while (ep->value < aabbInt.m_kMinimumCorner[0]) {
        S159a0_flip(bitField, ep->handle);
        ep++;
    }
    while (ep->value < aabbInt.m_kMaximumCorner[0]) {
        if (!(ep->value & 1)) S159a0_flip(bitField, ep->handle);
        ep++;
    }

    S159a0_Node qn;
    {
        S159a0_Axis& ax = m_kAxisEndPoints[1];
        Endpoint* data = ax.m_data;
        Endpoint* last = data + ax.m_iElementCount - 2;
        qn.m_usValue00 = (unsigned short)(((::Endpoint *)(::LowerBoundEntry((::Entry *)(data + 1), (::Entry *)(last), (unsigned short)aabbInt.m_kMinimumCorner[1]))) - data);
        qn.m_usValue04 = (unsigned short)(((::Endpoint *)(::LowerBoundEntry((::Entry *)(data + 1), (::Entry *)(last), (unsigned short)aabbInt.m_kMaximumCorner[1]))) - 1 - data);
    }
    {
        S159a0_Axis& ax = m_kAxisEndPoints[2];
        Endpoint* data = ax.m_data;
        Endpoint* last = data + ax.m_iElementCount - 2;
        qn.m_usValue02 = (unsigned short)(((::Endpoint *)(::LowerBoundEntry((::Entry *)(data + 1), (::Entry *)(last), (unsigned short)aabbInt.m_kMinimumCorner[2]))) - data);
        qn.m_usValue06 = (unsigned short)(((::Endpoint *)(::LowerBoundEntry((::Entry *)(data + 1), (::Entry *)(last), (unsigned short)aabbInt.m_kMaximumCorner[2]))) - 1 - data);
    }

    querySingleAabbSub(b, bitField, bitField, qn, overlapping);

    {
        hkMemoryAllocator& a = S159a0_stack();
        if ((bitFieldCap & 0x80000000) == 0) a.bufFree(bitField, (bitFieldCap & 0x3fffffff) * 4);
    }
    reinterpret_cast<::SweepClass *>(this)->FUN_00d13950((*(const ::SweepArray< ::SweepNode *> *)(&overlapping)), (::SweepArray< ::SweepEndpoint> *)(::PairArray *)(&out));
    overlapping.destroy();
}
}  // namespace fnv_00d159a0
#include <math.h>
namespace fnv_00d16c50 {
#include <math.h>


struct S16c50_TempAllocator {
    hkMemoryAllocator& get(void*) { return hkMemoryRouter::getInstance().temp(); }
};

struct S16c50_Vec4 {
    __m128 m_vComponents;
    float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    void setAdd4(const S16c50_Vec4& a, const S16c50_Vec4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void setSub4(const S16c50_Vec4& a, const S16c50_Vec4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void operator=(const S16c50_Vec4& v) { m_vComponents = v.m_vComponents; }
};

union S16c50_IntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
union S16c50_QuadInt {
    __m128 q;
    unsigned int i[4];
};

__forceinline void S16c50_convertToUint16WithClip(const S16c50_Vec4& in, const S16c50_Vec4& offset, const S16c50_Vec4& scale, const S16c50_Vec4& minV, const S16c50_Vec4& maxV, S16c50_IntUnion64& out)
{
    __m128 x = _mm_add_ps(offset.m_vComponents, in.m_vComponents);
    x = _mm_mul_ps(x, scale.m_vComponents);
    x = _mm_min_ps(x, maxV.m_vComponents);
    x = _mm_max_ps(x, minV.m_vComponents);
    x = _mm_add_ps(x, (*reinterpret_cast<__m128 *>(&::DAT_011b3770)));
    S16c50_QuadInt u;
    u.q = x;
    out.u16[0] = (unsigned short)(u.i[0] >> 7);
    out.u16[1] = (unsigned short)(u.i[1] >> 7);
    out.u16[2] = (unsigned short)(u.i[2] >> 7);
    out.u16[3] = (unsigned short)(u.i[3] >> 7);
}

struct S16c50_EndPoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
    int isMaxPoint() const { return m_uiFilterValue & 1; }
};
struct S16c50_Node {
    unsigned short m_min_y;
    unsigned short m_min_z;
    unsigned short m_max_y;
    unsigned short m_max_z;
    unsigned short m_min_x;
    unsigned short m_max_x;
    unsigned int m_handle;
    int isMarker() const { return m_handle & 1; }
};
struct S16c50_Axis {
    S16c50_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    const S16c50_EndPoint* begin() const { return m_data; }
    const S16c50_EndPoint& operator[](int i) const { return m_data[i]; }
};
struct S16c50_NodeArray {
    S16c50_Node* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    const S16c50_Node& operator[](int i) const { return m_data[i]; }
};

struct S16c50_ByteArray {
    unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S16c50_ByteArray(int n)
    {
        hkMemoryAllocator& a = S16c50_TempAllocator().get(this);
        unsigned char* p = n ? a._bufAlloc<unsigned char>(n) : 0;
        int cap = n ? n : (int)0x80000000;
        m_data = p;
        m_iElementCount = n;
        m_iCapacityState = cap;
    }
    __forceinline ~S16c50_ByteArray()
    {
        hkMemoryAllocator& a = S16c50_TempAllocator().get(this);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0) {
            a._bufFree<unsigned char>(m_data, m_iCapacityState & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = (int)0x80000000;
    }
    unsigned char* begin() { return m_data; }
};

struct S16c50_Collector {
    virtual void v0();
    virtual float ReleaseCollector(unsigned int handle, int castIndex);
};
struct S16c50_CastAabbInput {
    S16c50_Vec4 m_vFrom;
    S16c50_Vec4 m_vTo;
    S16c50_Vec4 m_vHalfExtents;
    const char* m_pBroadPhaseAabbCache;
};

extern const double DAT_010c9300;
extern const float DAT_0104a494;

static __forceinline void S16c50_memclear16(void* dest, int numBytes)
{
    S16c50_Vec4 zero; zero.setZero4();
    S16c50_Vec4* d = (S16c50_Vec4*)dest;
    for (numBytes = numBytes >> 4; numBytes >= 0; numBytes--) {
        *(d++) = zero;
    }
}

static __forceinline float S16c50_min2(float a, float b) { return a < b ? a : b; }

template <class T> static inline void S16c50_swap(T& a, T& b) { T t = a; a = b; b = t; }

static __forceinline int S16c50_getMinComponent(const S16c50_Vec4& v, float& m)
{
    if (v(0) < v(1)) {
        if (v(0) < v(2)) { m = v(0); return 0; }
    } else if (v(1) < v(2)) {
        m = v(1); return 1;
    }
    m = v(2); return 2;
}

__declspec(noinline) int __cdecl FUN_00d19d10(const float* v, float* m)
{
    if (v[0] < v[1]) {
        if (v[0] < v[2]) { *m = v[0]; return 0; }
    } else if (v[1] < v[2]) {
        *m = v[1]; return 1;
    }
    *m = v[2]; return 2;
}

static __forceinline void S16c50_calcCurDist(int axis, S16c50_Vec4& curDist, const S16c50_EndPoint* ep, const S16c50_Vec4& invDir, const S16c50_Vec4& start)
{
    curDist(axis) = ep->m_uiFilterValue * invDir(axis) - start(axis);
}

struct S16c50_Sweep {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    S16c50_Vec4 m_kVectorAt40;
    S16c50_Vec4 m_kVectorAt50;
    S16c50_Vec4 m_vScale;
    S16c50_Vec4 unk70;
    S16c50_Vec4 unk80;
    S16c50_Vec4 unk90;
    S16c50_NodeArray m_kNodeCollection;
    S16c50_Axis m_kAxisEndPoints[3];
    int m_iMarkerCount;
    int m_iMarkerCapacity;
    void* m_pOverlappingMarkerInfo;
    float m_fValueAfterOverlappingMarkerInfo;

    __forceinline void convertVectorToInt(const S16c50_Vec4& vec, unsigned int* intsOut) const
    {
        S16c50_Vec4 minVal; minVal.setZero4();
        S16c50_Vec4 maxVal; maxVal.m_vComponents = (*reinterpret_cast<__m128 *>(&::DAT_011b3790));
        S16c50_IntUnion64 out;
        S16c50_convertToUint16WithClip(vec, m_kVectorAt40, m_vScale, minVal, maxVal, out);
        intsOut[0] = out.u16[0];
        intsOut[1] = out.u16[1];
        intsOut[2] = out.u16[2];
        intsOut[3] = out.u16[3];
    }
    void FUN_00d16c50(const S16c50_CastAabbInput& input, S16c50_Collector& collector) const;
};

// @fnv 0x00d16c50
void S16c50_Sweep::FUN_00d16c50(const S16c50_CastAabbInput& input, S16c50_Collector& collector) const
{
    S16c50_Vec4 fromMin; fromMin.setSub4(input.m_vFrom, input.m_vHalfExtents);
    S16c50_Vec4 fromMax; fromMax.setAdd4(input.m_vFrom, input.m_vHalfExtents);
    __declspec(align(16)) unsigned int auiLowerBounds[4];
    __declspec(align(16)) unsigned int auiUpperBounds[4];
    convertVectorToInt(fromMin, auiLowerBounds);
    convertVectorToInt(fromMax, auiUpperBounds);

    S16c50_ByteArray bitFieldArray(m_kNodeCollection.GetLogicalSize() + 16);
    S16c50_memclear16(bitFieldArray.begin(), m_kNodeCollection.GetLogicalSize());

    const S16c50_Axis* axisArray = input.m_pBroadPhaseAabbCache ? (const S16c50_Axis*)input.m_pBroadPhaseAabbCache : &m_kAxisEndPoints[0];

    const S16c50_EndPoint* enterCur[3];
    const S16c50_EndPoint* exitCur[3];
    {
        unsigned char* bitField;
        bitField = bitFieldArray.begin();
        int mask = 1;
        for (int i = 0; 3 > i; i++) {
            const S16c50_Axis& axis = axisArray[i];
            if (auiLowerBounds[i] < axis[axis.GetLogicalSize() >> 1].m_uiFilterValue) {
                const S16c50_EndPoint* end = axis.begin() + axis.GetLogicalSize() - 4;
                const S16c50_EndPoint* ep = &axis[1];
                for (; ep < end; ep += 4) {
                    if (ep[3].m_uiFilterValue > auiLowerBounds[i]) break;
                    bitField[ep[0].m_usIndex] ^= mask;
                    bitField[ep[1].m_usIndex] ^= mask;
                    bitField[ep[2].m_usIndex] ^= mask;
                    bitField[ep[3].m_usIndex] ^= mask;
                }
                for (; ep->m_uiFilterValue <= auiLowerBounds[i]; ep++) {
                    bitField[ep->m_usIndex] ^= mask;
                }
                enterCur[i] = ep;
                for (; ep->m_uiFilterValue <= auiUpperBounds[i]; ep++) {
                    bitField[ep->m_usIndex] ^= mask & (ep->isMaxPoint() - 1);
                }
                exitCur[i] = ep;
            } else {
                const S16c50_EndPoint* start = axis.begin() + 4;
                const S16c50_EndPoint* ep;
                ep = &axis[axis.GetLogicalSize() - 2];
                for (; ep >= start; ep -= 4) {
                    if (ep[-3].m_uiFilterValue <= auiUpperBounds[i]) break;
                    bitField[ep[0].m_usIndex] ^= mask;
                    bitField[ep[-1].m_usIndex] ^= mask;
                    bitField[ep[-2].m_usIndex] ^= mask;
                    bitField[ep[-3].m_usIndex] ^= mask;
                }
                for (; ep->m_uiFilterValue > auiUpperBounds[i]; ep--) {
                    bitField[ep->m_usIndex] ^= mask;
                }
                exitCur[i] = 1 + ep;
                for (; ep->m_uiFilterValue > auiLowerBounds[i]; ep--) {
                    bitField[ep->m_usIndex] ^= mask & (-ep->isMaxPoint());
                }
                enterCur[i] = ep + 1;
            }
            mask <<= 1;
        }
    }

    float earliestHit = 1.0f;
    {
        const S16c50_Node* node = &m_kNodeCollection[0];
        int numNodes = m_kNodeCollection.GetLogicalSize();
        unsigned char* bf = bitFieldArray.begin();
        const unsigned int* p = (const unsigned int*)bf;
        const unsigned int* pEnd = p + (numNodes >> 2) + 1;
        for (; p < pEnd; node += 4, p++) {
            if (((*p + 0x01010101) & 0x08080808) == 0) continue;
            const unsigned char* b = (const unsigned char*)p;
            if (b[0] == 7 && !node[0].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[0].m_handle, 0));
            if (b[1] == 7 && !node[1].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[1].m_handle, 0));
            if (b[2] == 7 && !node[2].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[2].m_handle, 0));
            if (b[3] == 7 && !node[3].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[3].m_handle, 0));
        }
    }

    S16c50_Vec4 dir; dir.setSub4(input.m_vTo, input.m_vFrom);
    S16c50_Vec4 invDir;
    S16c50_Vec4 startDist;
    S16c50_Vec4 endDist;
    int step[3];
    int flipEnter[3];
    int flipExit[3];
    for (int i = 0; i < 3; i++) {
        float d = m_vScale(i) * dir(i);
        float absD = fabsf(d);
        if (d > 0.0) {
            step[i] = 4;
            flipEnter[i] = 0;
            flipExit[i] = 1;
        } else {
            step[i] = -4;
            S16c50_swap(enterCur[i], exitCur[i]);
            S16c50_swap(fromMin(i), fromMax(i));
            S16c50_swap(auiLowerBounds[i], auiUpperBounds[i]);
            enterCur[i]--;
            exitCur[i]--;
            flipEnter[i] = 1;
            flipExit[i] = 0;
        }
        float a = (fromMin(i) + m_kVectorAt40(i)) * m_vScale(i);
        float lo = m_kVectorAt40(i);
        float b = (input.m_vTo(i) + lo) * m_vScale(i);
        if (absD < a * 1.1920928955078125e-07 || absD < b * 1.1920928955078125e-07) {
            invDir(i) = 0.0f;
            startDist(i) = -2.0f;
            endDist(i) = -2.0f;
        } else {
            float inv = 1.0f / d;
            invDir(i) = inv;
            float s0 = (fromMin(i) + m_kVectorAt40(i)) * m_vScale(i);
            float s1 = s0 - m_fValueAfterOverlappingMarkerInfo;
            startDist(i) = inv * s1;
            float e0 = (fromMax(i) + m_kVectorAt40(i)) * m_vScale(i);
            float e1 = e0 - m_fValueAfterOverlappingMarkerInfo;
            endDist(i) = inv * e1;
        }
    }

    S16c50_Vec4 enterDist;
    S16c50_Vec4 exitDist;
    const S16c50_EndPoint* curEnter[3] = { enterCur[0], enterCur[1], enterCur[2] };
    const S16c50_EndPoint* curExit[3] = { exitCur[0], exitCur[1], exitCur[2] };
    enterDist(0) = curEnter[0]->m_uiFilterValue * invDir(0) - startDist(0);
    enterDist(1) = curEnter[1]->m_uiFilterValue * invDir(1) - startDist(1);
    enterDist(2) = curEnter[2]->m_uiFilterValue * invDir(2) - startDist(2);
    exitDist(0) = curExit[0]->m_uiFilterValue * invDir(0) - endDist(0);
    exitDist(1) = curExit[1]->m_uiFilterValue * invDir(1) - endDist(1);
    exitDist(2) = curExit[2]->m_uiFilterValue * invDir(2) - endDist(2);

    unsigned char* bitField = bitFieldArray.begin();
    bitField[0] = 8;
    float dummy;
    float d2;
    float d3;
    float d4;
    float d5;
    int enterAxis = S16c50_getMinComponent(enterDist, dummy);
    int exitAxis = S16c50_getMinComponent(exitDist, dummy);

    while (1) {
        if (exitDist(exitAxis) < enterDist(enterAxis)) {
            if (exitDist(exitAxis) > earliestHit) break;
            while (1) {
                unsigned int nodeIndex = curExit[exitAxis]->m_usIndex;
                int m = (curExit[exitAxis]->isMaxPoint() ^ flipExit[exitAxis]) << exitAxis;
                bitField[nodeIndex] ^= m;
                if (bitField[nodeIndex] >= 7) {
                    if (!nodeIndex) {
                        exitDist(exitAxis) = ::DAT_010162c0;
                        exitAxis = ::FUN_00d19d10(&exitDist(0), &d2);
                        break;
                    }
                    const S16c50_Node& node = m_kNodeCollection[nodeIndex];
                    if (m && !node.isMarker()) {
                        earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node.m_handle, 0));
                    }
                }
                unsigned short value = curExit[exitAxis]->m_uiFilterValue;
                curExit[exitAxis] = (const S16c50_EndPoint*)((const char*)curExit[exitAxis] + step[exitAxis]);
                if (value == curExit[exitAxis]->m_uiFilterValue) continue;
                S16c50_EndPoint ep = *curExit[exitAxis];
                S16c50_calcCurDist(exitAxis, exitDist, &ep, invDir, endDist);
                exitAxis = ::FUN_00d19d10(&exitDist(0), &d3);
                break;
            }
        } else {
            if (enterDist(enterAxis) > earliestHit) break;
            while (1) {
                unsigned int nodeIndex = curEnter[enterAxis]->m_usIndex;
                bitField[nodeIndex] ^= (curEnter[enterAxis]->isMaxPoint() ^ flipEnter[enterAxis]) << enterAxis;
                if (bitField[nodeIndex] > 8) {
                    enterDist(enterAxis) = ::DAT_010162c0;
                    enterAxis = ::FUN_00d19d10(&enterDist(0), &d4);
                    break;
                }
                unsigned short value = curEnter[enterAxis]->m_uiFilterValue;
                curEnter[enterAxis] = (const S16c50_EndPoint*)((const char*)curEnter[enterAxis] + step[enterAxis]);
                if (value == curEnter[enterAxis]->m_uiFilterValue) continue;
                S16c50_EndPoint ep = *curEnter[enterAxis];
                S16c50_calcCurDist(enterAxis, enterDist, &ep, invDir, startDist);
                enterAxis = ::FUN_00d19d10(&enterDist(0), &d5);
                break;
            }
        }
    }
}
}  // namespace fnv_00d16c50


struct Vec4
{
    __m128 m_vComponents;

    void setNeg4(const Vec4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, ::DAT_010c44d0); }
    void add4(const Vec4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    void setAdd4(const Vec4& a, const Vec4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void setXYZW(const Vec4& xyz, const Vec4& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), _MM_SHUFFLE(3, 0, 1, 0));
    }
    void setReciprocal4(const Vec4& v)
    {
        __m128 e = _mm_rcp_ps(v.m_vComponents);
        m_vComponents = _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, v.m_vComponents), e));
    }
};

struct SweepShiftPairs;

struct SweepShift
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void shiftObjects(const Vec4& distance, Vec4& applied, SweepShiftPairs& pairs);

    Vec4 m_10;
    Vec4 m_20;
    Vec4 m_30;
    Vec4 m_lowOffset;
    Vec4 m_lowRounded;
    Vec4 m_lowScale;
    Vec4 m_highOffset;
    Vec4 m_highRounded;
    Vec4 m_highScale;

    void FUN_00d10f00(const Vec4& distance, Vec4& appliedOut, SweepShiftPairs& pairs);
};

// @fnv 0x00d10f00
void SweepShift::FUN_00d10f00(const Vec4& distance, Vec4& appliedOut, SweepShiftPairs& pairs)
{
    Vec4 negated;
    negated.setNeg4(distance);
    Vec4 applied;
    shiftObjects(negated, applied, pairs);

    m_lowOffset.add4(applied);
    {
        const Vec4& one = (const Vec4&)DAT_010c7170;
        Vec4 scale;
        scale.setXYZW(m_lowScale, one);
        Vec4 step;
        step.setReciprocal4(scale);
        m_lowRounded.setAdd4(step, m_lowOffset);
    }
    m_highOffset.add4(applied);
    {
        const Vec4& one = (const Vec4&)DAT_010c7170;
        Vec4 scale;
        scale.setXYZW(m_highScale, one);
        Vec4 step;
        step.setReciprocal4(scale);
        m_highRounded.setAdd4(step, m_highOffset);
    }
    appliedOut.setNeg4(applied);
}

struct S4ef0TempAlloc { __forceinline hkMemoryAllocator& get(void*) { return hkMemoryRouter::getInstance().temp(); } };
struct S4ef0HeapAlloc { __forceinline hkMemoryAllocator& get(const void*) { return hkMemoryRouter::getInstance().heap(); } };
struct S4ef0TypeIsPod {};
 struct S4ef0TypeIsClass {};
template<class T> __forceinline void S4ef0_construct(T* t,int n,S4ef0TypeIsPod) {}
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsClass) { for(int i=0;i<n;++i) { if(t+i) t[i]=tcopy; } }
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsPod) { for(int i=0;i<n;++i) { t[i]=tcopy; } }
template<class T> struct S4ef0ArrayBase {
 enum { CAPACITY_MASK=0x3fffffff, DONT_DEALLOCATE_FLAG=0x80000000 };
 T* m_data; int m_iElementCount; int m_iCapacityState;
 __forceinline S4ef0ArrayBase():m_data(0),m_iElementCount(0),m_iCapacityState(DONT_DEALLOCATE_FLAG) {}
 __forceinline int GetLogicalSize() const { return m_iElementCount; }
 __forceinline int getCapacity() const { return m_iCapacityState&static_cast<int>(CAPACITY_MASK); }
 __forceinline T* begin() { return m_data; }
 __forceinline T* end() { return m_data+m_iElementCount; }
 __forceinline const T* begin() const { return m_data; }
 __forceinline const T* end() const { return m_data+m_iElementCount; }
 __forceinline T& operator[](int i) { return m_data[i]; }
 __forceinline const T& operator[](int i) const { return m_data[i]; }
 __forceinline void setOwnedData(T* ptr,int size,int capacity) { m_data=ptr; m_iElementCount=size; m_iCapacityState=capacity; }
 __forceinline void clear() { m_iElementCount=0; }
 __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc) {
  clear();
  if((m_iCapacityState&DONT_DEALLOCATE_FLAG)==0) alloc._bufFree<T>(m_data,getCapacity());
  m_data=0; m_iCapacityState=DONT_DEALLOCATE_FLAG;
 }
 __forceinline void pushBackUnchecked(const T& t) { S4ef0_constructWithCopy(m_data+m_iElementCount,1,t,S4ef0TypeIsPod()); m_iElementCount++; }
 __forceinline void _pushBack(hkMemoryAllocator& alloc,const T& t) {
  if(m_iElementCount==getCapacity()) ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc),(::AudioStream *)(void *)(this),sizeof(T));
  S4ef0_constructWithCopy(m_data+m_iElementCount,1,t,S4ef0TypeIsClass());
  m_iElementCount++;
 }
};
template<class T,class A> struct S4ef0Array : S4ef0ArrayBase<T> {
 __forceinline S4ef0Array(int n) : S4ef0ArrayBase<T>() {
  hkMemoryAllocator& a=A().get(this);
  T* p=n ? a._bufAlloc<T>(n) : 0;
  int cap=n ? n : S4ef0ArrayBase<T>::DONT_DEALLOCATE_FLAG;
  this->setOwnedData(p,n,cap);
  S4ef0_construct(this->m_data,n,S4ef0TypeIsPod());
 }
 __forceinline ~S4ef0Array() { this->_clearAndDeallocate(A().get(this)); }
 __forceinline void AddBack(const T& t) { this->_pushBack(A().get(this),t); }
};
struct S4ef0Vector {
 __m128 m_vComponents;
 __forceinline S4ef0Vector() {}
 __forceinline __m128& getQuad() { return m_vComponents; }
 __forceinline const __m128& getQuad() const { return m_vComponents; }
 __forceinline void setZero4() { m_vComponents=_mm_setzero_ps(); }
 __forceinline void operator=(const S4ef0Vector& v) { m_vComponents=v.m_vComponents; }
 __forceinline void setAdd4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_add_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void add4(const S4ef0Vector& v) { m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents); }
 __forceinline void mul4(const S4ef0Vector& v) { m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents); }
 __forceinline void setMin4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_min_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void setMax4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_max_ps(a.m_vComponents,b.m_vComponents); }
};
struct S4ef0Aabb { S4ef0Vector m_kMinimumCorner,m_kMaximumCorner; };
__declspec(align(16)) struct S4ef0AabbInt { unsigned int m_kMinimumCorner[3]; unsigned char m_ucExpansionMin[3]; unsigned char m_ucExpansionShift; unsigned int m_kMaximumCorner[3]; unsigned char m_ucExpansionMax[3]; unsigned char m_expansionMaxXYZ; };
union S4ef0Union64 { __m128 quad; __int64 i64; unsigned __int64 u64; int i32[2]; unsigned int u32[2]; short i16[4]; unsigned short u16[4]; };
__forceinline void S4ef0_convertToUint16WithClip(const S4ef0Vector& in,const S4ef0Vector& offset,const S4ef0Vector& scale,const S4ef0Vector& min,const S4ef0Vector& max,S4ef0Union64& out) {
 S4ef0Vector x;
 x.setAdd4(in,offset);
 x.mul4(scale);
 x.setMin4(x,max);
 x.setMax4(x,min);
 S4ef0Vector magic;
 magic.getQuad()=*(const __m128*)DAT_011b3770;
 x.add4(magic);
 union { __m128 q; unsigned int i[4]; } u;
 u.q=x.getQuad();
 out.i16[0]=(short)(u.i[0]>>7);
 out.i16[1]=(short)(u.i[1]>>7);
 out.i16[2]=(short)(u.i[2]>>7);
 out.i16[3]=(short)(u.i[3]>>7);
}
__forceinline void S4ef0_memclear16(void* dest,int numBytes) {
 S4ef0Vector zero; zero.setZero4();
 S4ef0Vector* d=(S4ef0Vector*)dest;
 for(numBytes>>=4;numBytes>=0;numBytes--) { *(d++)=zero; }
}
__forceinline void S4ef0_staticFlipBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]^=mask; }
__forceinline void S4ef0_staticClearBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]&=~mask; }
struct S4ef0Pair { uintptr_t m_kPointA,m_kPointB; };
struct S4ef0Node {
 unsigned short m_usValue00,m_usValue02,m_usValue04,m_usValue06,m_usValue08,m_usValue0A; uintptr_t m_handle;
 __forceinline unsigned int yzDisjoint(const S4ef0Node& other) const {
  unsigned int minA=*(const unsigned int*)&m_usValue00; unsigned int minB=*(const unsigned int*)&other.m_usValue00;
  unsigned int maxA=*(const unsigned int*)&m_usValue04; unsigned int maxB=*(const unsigned int*)&other.m_usValue04;
  maxA-=minB; maxB-=minA; maxA|=maxB; maxA&=0x80008000; return maxA;
 }
 __forceinline int isMarker() const { return m_handle&1; }
};
struct S4ef0Marker { unsigned short m_usIndex,m_uiFilterValue; S4ef0ArrayBase<unsigned short> m_kMarkerIndices; };
struct S4ef0Axis : S4ef0ArrayBase<Entry> { };
struct S4ef0Handle;
struct S4ef0Collector { virtual void v0(); virtual float ReleaseCollector(unsigned int h,int i); };
typedef S4ef0Array<S4ef0Pair,S4ef0HeapAlloc> S4ef0Results;
typedef S4ef0ArrayBase<const S4ef0Node*> S4ef0NodeArr;
struct S4ef0Owner {
 __m128 unk00,unk10,unk20,unk30;
 S4ef0Vector m_kVectorAt40,m_kVectorAt50,m_vScale;
 __m128 unk70,unk80,unk90;
 S4ef0ArrayBase<S4ef0Node> m_kNodeCollection;
 S4ef0Axis m_kAxisEndPoints[3];
 int m_iMarkerCount,m_iMarkerCapacity; S4ef0Marker* m_pOverlappingMarkerInfo;
 __forceinline int getNumMarkers() const { return m_iMarkerCount; }
 __forceinline void _convertAabbToInt(const S4ef0Aabb& aabb,S4ef0AabbInt& aabbOut) const { _convertAabbToIntS(aabb,m_kVectorAt40,m_kVectorAt50,m_vScale,aabbOut); }
 static __forceinline void _convertAabbToIntS(const S4ef0Aabb& aabb,const S4ef0Vector& offsetLow,const S4ef0Vector& offsetHigh,const S4ef0Vector& scale,S4ef0AabbInt& aabbOut);
 __forceinline void querySingleAabbSub(S4ef0Handle* object,const unsigned int* bitField,S4ef0Node& refNode,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 __forceinline void _querySingleAabb(const S4ef0Aabb& aabb,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 void FUN_00d14ef0(const S4ef0Aabb& aabb,S4ef0Results& pairsOut) const;
};
__forceinline void S4ef0Owner::_convertAabbToIntS(const S4ef0Aabb& aabb,const S4ef0Vector& offsetLow,const S4ef0Vector& offsetHigh,const S4ef0Vector& scale,S4ef0AabbInt& aabbOut) {
 S4ef0Vector zero; zero.setZero4();
 S4ef0Vector maxVal; maxVal.getQuad()=*(const __m128*)DAT_011b3790;
 S4ef0Union64 mi;
 S4ef0Union64 ma;
 S4ef0_convertToUint16WithClip(aabb.m_kMinimumCorner,offsetLow,scale,zero,maxVal,mi);
 S4ef0_convertToUint16WithClip(aabb.m_kMaximumCorner,offsetHigh,scale,zero,maxVal,ma);
 aabbOut.m_kMinimumCorner[0]=mi.u16[0]&0xfffe;
 aabbOut.m_kMinimumCorner[1]=mi.u16[1]&0xfffe;
 aabbOut.m_kMinimumCorner[2]=mi.u16[2]&0xfffe;
 aabbOut.m_kMaximumCorner[0]=ma.u16[0]|1;
 aabbOut.m_kMaximumCorner[1]=ma.u16[1]|1;
 aabbOut.m_kMaximumCorner[2]=ma.u16[2]|1;
}
__forceinline void S4ef0Owner::querySingleAabbSub(S4ef0Handle* object,const unsigned int* bitField,S4ef0Node& refNode,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const {
 S4ef0Pair pair; pair.m_kPointA=(uintptr_t)object;
 const S4ef0Node* nodes=&m_kNodeCollection[0];
 const unsigned int* bitFieldEnd=bitField+(m_kNodeCollection.GetLogicalSize()>>5)+1;
 for(;bitField<bitFieldEnd;nodes+=32,bitField++) {
  unsigned int bits=*bitField;
  if(!bits) continue;
  const S4ef0Node* n=nodes;
  do {
   if(bits&0xf) {
    if(bits&1) {
     if(!n[0].yzDisjoint(refNode) && !n[0].isMarker()) {
      if(type==0) { pair.m_kPointB=n[0].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[0]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[0].m_handle,0); }
     }
    }
    if(bits&2) {
     if(!n[1].yzDisjoint(refNode) && !n[1].isMarker()) {
      if(type==0) { pair.m_kPointB=n[1].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[1]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[1].m_handle,0); }
     }
    }
    if(bits&4) {
     if(!n[2].yzDisjoint(refNode) && !n[2].isMarker()) {
      if(type==0) { pair.m_kPointB=n[2].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[2]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[2].m_handle,0); }
     }
    }
    if(bits&8) {
     if(!n[3].yzDisjoint(refNode) && !n[3].isMarker()) {
      if(type==0) { pair.m_kPointB=n[3].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[3]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[3].m_handle,0); }
     }
    }
   }
   n+=4; bits>>=4;
  } while(bits);
 }
}
__forceinline void S4ef0Owner::_querySingleAabb(const S4ef0Aabb& aabb,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const {
 S4ef0Handle* object=0;
 int size=m_kNodeCollection.GetLogicalSize();
 S4ef0Array<unsigned int,S4ef0TempAlloc> bitFieldArr((size>>5)+8);
 unsigned int* bitField=bitFieldArr.begin();
 S4ef0_memclear16(bitField,size>>3);
 S4ef0AabbInt aabbInt;
 _convertAabbToInt(aabb,aabbInt);
 const Entry* ep=&m_kAxisEndPoints[0][1];
 if(getNumMarkers()) {
  int value=aabbInt.m_kMinimumCorner[0];
  int pos=value>>(16-m_iMarkerCapacity);
  if(pos>0) {
   S4ef0Marker* marker=&m_pOverlappingMarkerInfo[pos-1];
   S4ef0_staticFlipBit(bitField,marker->m_usIndex);
   const unsigned short* objects=marker->m_kMarkerIndices.begin();
   for(int i=marker->m_kMarkerIndices.GetLogicalSize()-1;i>=0;i--) { S4ef0_staticFlipBit(bitField,*objects); objects++; }
   const S4ef0Node& node=m_kNodeCollection[marker->m_usIndex];
   ep=&m_kAxisEndPoints[0][node.m_usValue08+1];
   const Entry* end=&m_kAxisEndPoints[0][node.m_usValue0A];
   for(;ep<end;ep++) { if(!(ep->key&1)) S4ef0_staticClearBit(bitField,ep->value); }
   ep=&m_kAxisEndPoints[0][node.m_usValue08+1];
  }
 }
 for(;ep->key<aabbInt.m_kMinimumCorner[0];ep++) { S4ef0_staticFlipBit(bitField,ep->value); }
 for(;ep->key<aabbInt.m_kMaximumCorner[0];ep++) { if(!(ep->key&1)) S4ef0_staticFlipBit(bitField,ep->value); }
 S4ef0Node refNode;
 {
  const S4ef0Axis& axis=m_kAxisEndPoints[1];
  const Entry* start=&axis[0];
  refNode.m_usValue00=(unsigned short)(::LowerBoundEntry(const_cast<::Entry *>(start+1), const_cast<::Entry *>(axis.end()-2), (unsigned short)aabbInt.m_kMinimumCorner[1])-start);
  refNode.m_usValue04=(unsigned short)(::LowerBoundEntry(const_cast<::Entry *>(start+1), const_cast<::Entry *>(axis.end()-2), (unsigned short)aabbInt.m_kMaximumCorner[1])-(start+1));
 }
 {
  const S4ef0Axis& axis=m_kAxisEndPoints[2];
  const Entry* start=&axis[0];
  refNode.m_usValue02=(unsigned short)(::LowerBoundEntry(const_cast<::Entry *>(start+1), const_cast<::Entry *>(axis.end()-2), (unsigned short)aabbInt.m_kMinimumCorner[2])-start);
  refNode.m_usValue06=(unsigned short)(::LowerBoundEntry(const_cast<::Entry *>(start+1), const_cast<::Entry *>(axis.end()-2), (unsigned short)aabbInt.m_kMaximumCorner[2])-(start+1));
 }
 querySingleAabbSub(object,bitField,refNode,type,pairsOut,nodesOut,collector);
}
// @fnv 0x00d14ef0
void S4ef0Owner::FUN_00d14ef0(const S4ef0Aabb& aabb,S4ef0Results& pairsOut) const {
 _querySingleAabb(aabb,0,&pairsOut,0,0);
}


static const __m128 batchSweepBias={65536.0f,65536.0f,65536.0f,65536.0f};


template<class T> __forceinline T* allocateSweep(hkMemoryAllocator& allocator, int count, int& capacity) {
    T* result = count ? allocator._bufAlloc<T>(count) : 0;
    capacity = count ? count : (int)0x80000000;
    return result;
}
struct SweepVector {
    __m128 v;
    __forceinline void operator=(const SweepVector& value){v=value.v;}
    __forceinline void setMin(const SweepVector& a,const SweepVector& b) {v=_mm_min_ps(a.v,b.v);}
    __forceinline void setMax(const SweepVector& a,const SweepVector& b) {v=_mm_max_ps(a.v,b.v);}
    __forceinline void setAdd(const SweepVector& a,const SweepVector& b) {v=_mm_add_ps(a.v,b.v);}
    __forceinline void mul(const SweepVector& a) {v=_mm_mul_ps(v,a.v);}
    __forceinline void add(const SweepVector& a) {v=_mm_add_ps(v,a.v);}
};
__forceinline void clearSweepQuads(void* storage,int chunks) {
 SweepVector zero;zero.v=_mm_setzero_ps();
 SweepVector* cursor=(SweepVector*)storage;
 while(--chunks>=0) *cursor++=zero;
}
union ShortResult {__m128 vector;unsigned short values[4];short signedValues[4];unsigned int pairs[2];__int64 wide;};
__forceinline void convertSweepBound(const SweepVector& input,const SweepVector& offset,const SweepVector& scale,const SweepVector& min,const SweepVector& max,ShortResult& out) {
    SweepVector value;
    value.setAdd(input,offset);value.mul(scale);value.setMin(value,max);value.setMax(value,min);
    SweepVector bias;bias.v=batchSweepBias;value.add(bias);
    union {__m128 v;unsigned int words[4];} bits;
    bits.v=value.v;
    out.values[0]=(unsigned short)(bits.words[0]>>7);
    out.values[1]=(unsigned short)(bits.words[1]>>7);
    out.values[2]=(unsigned short)(bits.words[2]>>7);
}
struct BatchAabb { SweepVector low,high;
 __forceinline void include(const BatchAabb& other) {low.setMin(low,other.low);high.setMax(high,other.high);}
};
struct __declspec(align(16)) QuantBatchAabb {
    unsigned int low[3];
    unsigned char expandLowX,expandLowY,expandLowZ,expandShift;
    unsigned int high[3];
    unsigned char expandHighX,expandHighY,expandHighZ,shapeByte;
};
struct __declspec(align(16)) SweepLowShorts { unsigned short x,y,z,w; };
__forceinline void quantizeSweepAabb(const SweepVector& offsetLow,const BatchAabb& box,const SweepVector& offsetHigh,const SweepVector& scale,QuantBatchAabb& out) {
    SweepVector zero,upper;zero.v=_mm_setzero_ps();upper.v=_mm_load_ps(DAT_011b3790);
    SweepVector magic;magic.v=batchSweepBias;
    SweepVector lowValue,highValue;
    lowValue.setAdd(box.low,offsetLow);lowValue.mul(scale);lowValue.setMin(lowValue,upper);lowValue.setMax(lowValue,zero);lowValue.add(magic);
    ShortResult lower;
    lower.values[0]=(unsigned short)(reinterpret_cast<unsigned int*>(&lowValue.v)[0]>>7);
    lower.values[1]=(unsigned short)(reinterpret_cast<unsigned int*>(&lowValue.v)[1]>>7);
    lower.values[2]=(unsigned short)(reinterpret_cast<unsigned int*>(&lowValue.v)[2]>>7);
    highValue.setAdd(box.high,offsetHigh);highValue.mul(scale);highValue.setMin(highValue,upper);highValue.setMax(highValue,zero);highValue.add(magic);
    ShortResult upperResult;
    upperResult.values[0]=(unsigned short)(reinterpret_cast<unsigned int*>(&highValue.v)[0]>>7);
    upperResult.values[1]=(unsigned short)(reinterpret_cast<unsigned int*>(&highValue.v)[1]>>7);
    upperResult.values[2]=(unsigned short)(reinterpret_cast<unsigned int*>(&highValue.v)[2]>>7);
    out.low[0]=lower.values[0]&0xfffe;
    out.low[1]=lower.values[1]&0xfffe;
    out.low[2]=lower.values[2]&0xfffe;
    out.high[0]=upperResult.values[0]|1;
    out.high[1]=upperResult.values[1]|1;
    out.high[2]=upperResult.values[2]|1;
}

__forceinline void quantizeCombinedSweepAabb(const BatchAabb& box,const SweepVector& offsetLow,const SweepVector& offsetHigh,const SweepVector& scale,QuantBatchAabb& out) {
    SweepVector zero,upper;zero.v=_mm_setzero_ps();upper.v=_mm_load_ps(DAT_011b3790);
    SweepVector magic;magic.v=batchSweepBias;
    SweepVector lowValue,highValue;
    lowValue.setAdd(box.low,offsetLow);lowValue.mul(scale);lowValue.setMin(lowValue,upper);lowValue.setMax(lowValue,zero);lowValue.add(magic);
    ShortResult lower;
    lower.values[0]=(unsigned short)(reinterpret_cast<unsigned int*>(&lowValue.v)[0]>>7);
    lower.values[1]=(unsigned short)(reinterpret_cast<unsigned int*>(&lowValue.v)[1]>>7);
    lower.values[2]=(unsigned short)(reinterpret_cast<unsigned int*>(&lowValue.v)[2]>>7);
    highValue.setAdd(box.high,offsetHigh);highValue.mul(scale);highValue.setMin(highValue,upper);highValue.setMax(highValue,zero);highValue.add(magic);
    ShortResult upperResult;
    upperResult.values[0]=(unsigned short)(reinterpret_cast<unsigned int*>(&highValue.v)[0]>>7);
    upperResult.values[1]=(unsigned short)(reinterpret_cast<unsigned int*>(&highValue.v)[1]>>7);
    upperResult.values[2]=(unsigned short)(reinterpret_cast<unsigned int*>(&highValue.v)[2]>>7);
    out.low[0]=lower.values[0]&0xfffe;
    out.low[1]=lower.values[1]&0xfffe;
    out.low[2]=lower.values[2]&0xfffe;
    out.high[0]=upperResult.values[0]|1;
    out.high[1]=upperResult.values[1]|1;
    out.high[2]=upperResult.values[2]|1;
}


struct BatchSweepKey { unsigned short val,idx; };
struct SweepBatchNode;
template<class T> __forceinline void destroySweepRange(T* p,int n) {for(int k=0;k<n;++k)p[k].~T();}
template<class T> __forceinline void initializeSweepRange(T* p,int n) {for(int k=0;k<n;++k)::new(p+k) T;}

template<class T> struct SweepStorageBase {
 T* data;int size;int capacity;
 __forceinline SweepStorageBase():data(0),size(0),capacity(0x80000000){}
 __forceinline void own(T* pointer,int count,int flags){this->data=pointer;this->size=count;this->capacity=flags;}
 __forceinline T& operator[](int i){return data[i];}
 __forceinline void setSizeUnchecked(int n){destroySweepRange(data+n,size-n);initializeSweepRange(data+size,n-size);size=n;}
 __forceinline T* begin(){return data;}
};
struct SweepStackPolicy {__forceinline hkMemoryAllocator& get(const void*){return hkMemoryRouter::getInstance().temp();}};
template<class T> struct SweepBuffer:SweepStorageBase<T> {
    __forceinline T& operator[](int i){return data[i];}
    __forceinline SweepBuffer(int count) :SweepStorageBase<T>() {
        hkMemoryAllocator& allocator=SweepStackPolicy().get(this);
        T* pointer=count ? allocator._bufAlloc<T>(count) : 0;
        int flags=count ? count : (int)0x80000000;
        own(pointer,count,flags);initializeSweepRange(data,count);
    }
    __forceinline SweepBuffer(int count,SweepBatchNode** nodes,void*& baseOut) :SweepStorageBase<T>() {
        hkMemoryAllocator& allocator=SweepStackPolicy().get(this);
        T* pointer;
        if(count){int bytes=count*(int)sizeof(T);pointer=(T*)allocator.bufAlloc(bytes);count=bytes/(int)sizeof(T);}else {pointer=0;}
        int flags;if(count){flags=count;baseOut=*nodes;}else{flags=0x80000000;baseOut=*nodes;}
        own(pointer,count,flags);initializeSweepRange(data,count);
    }
};

struct SweepObjectHandle {unsigned int id;};
struct SweepBatchNode {
 unsigned short minY,minZ,maxY,maxZ,minX,maxX;
 SweepObjectHandle* handle;
 __forceinline unsigned int disjointYZ(const SweepBatchNode& other) const {
  unsigned int first=(*(const unsigned int*)&maxY)-(*(const unsigned int*)&other.minY);
  unsigned int second=(*(const unsigned int*)&other.maxY)-(*(const unsigned int*)&minY);
  return (first|second)&0x80008000;
 }
 __forceinline int isMarker() const {return (uintptr_t)handle&1;}
};

struct BatchNodeArr:SweepStorageBase<SweepBatchNode*> {
 __forceinline void clear(hkMemoryAllocator& alloc) {
   size=0;if(!(capacity&0x80000000))alloc.bufFree(data,(capacity&0x3fffffff)*4);
   data=0;capacity=0x80000000;
 }
 __forceinline void clearAndFree() {clear(hkMemoryRouter::getInstance().temp());}
};
struct BatchNodeArray:SweepStorageBase<SweepBatchNode> {};
struct BatchMarker { unsigned short node,value; unsigned short* data; int size,capacity; };
struct SortArr15 {
    Endpoint* data; int size; int cap;
    __declspec(noinline) void* LowerBoundEntry(void* begin, void* end, int thresh);
};
__declspec(noinline) void* SortArr15::LowerBoundEntry(void* begin,void* end,int thresh) {
 Endpoint* first=(Endpoint*)begin;Endpoint* last=(Endpoint*)end;
 unsigned short key=(unsigned short)thresh;
 while(last-first>16){Endpoint* middle=first+((last-first)>>1);if(middle->value<key)first=middle;else last=middle;}
 while(first->value<key)++first;
 return first;
}

union PackedBatchBounds {
    unsigned short values[4];
    struct { unsigned int low,high; } packed;
};
struct In1 { SweepObjectHandle** f0; int count; };

struct In2 { BatchAabb* base; int gate; };

struct Sweep15 : public BroadPhaseBase {
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    SweepVector m_kVectorAt40;
    SweepVector m_kVectorAt50;
    SweepVector m_vScale;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    BatchNodeArray arrA0;
    SortArr15 axes[3];
    int m_iMarkerCount;
    int m_markerShift;
    BatchMarker* m_pOverlappingMarkerInfo;

    __forceinline void collectSweepCandidates(const BatchAabb& spl,BatchNodeArr& local);
    void FUN_00d18400(In1* p1, In2* p2, void* p3);
};

struct EndpointOrder { };
__forceinline void sortSweepEndpoints(void* p,int count,EndpointOrder order) {
 if(count>1) ::FUN_00d19fa0((unsigned int *)(p),0,count-1,(*(int *)&(const ::EndpointOrder &)(order)));
}

__forceinline void Sweep15::collectSweepCandidates(const BatchAabb& spl,BatchNodeArr& local)
{
        int capA4=arrA0.size;
        int sz = (capA4 >> 5) + 8;
        SweepBuffer<int> bitmap(sz);
        
        clearSweepQuads(bitmap.data,(capA4>>7)+1);
        QuantBatchAabb quantized;
        quantizeCombinedSweepAabb(spl,m_kVectorAt40,m_kVectorAt50,m_vScale,quantized);

        Endpoint* cntBase = axes[0].data;
        int listCount = m_iMarkerCount;
        int listShift = m_markerShift;
        BatchMarker* listData = m_pOverlappingMarkerInfo;
        int* bits = (int*)bitmap.data;
        unsigned short* scan = (unsigned short*)(cntBase + 1);
        if (listCount != 0) {
            int cnt = (int)quantized.low[0] >> (16 - listShift);
            if (cnt > 0) {
                BatchMarker* entry = listData + cnt - 1;
                int w0 = entry->node;
                ToggleBit(w0,bits);
                int rem = entry->size - 1;
                unsigned short* wp = entry->data;
                while (rem >= 0) {
                    ToggleBit(*wp++,bits);
                    rem--;
                }
                SweepBatchNode* rec = arrA0.data + entry->node;
                Endpoint* rangeBase=axes[0].data;Endpoint* s=rangeBase+rec->minX+1;Endpoint* end=rangeBase+rec->maxX;
                while(s<end){
                    if((s->value&1)==0){int w=s->handle;FUN_00d10af0(w,(unsigned int*)bits);}
                    ++s;
                }
                scan=(unsigned short*)(axes[0].data+rec->minX+1);
            }
        }
        while (*scan < (unsigned int)quantized.low[0]) {
            int w = scan[1];
            ToggleBit(w,bits);
            scan += 2;
        }
        unsigned short scanValue=*scan;
        while(scanValue < (unsigned int)quantized.high[0]) {
            if(!(scanValue&1)) {
                int w=scan[1];
                ToggleBit(w,bits);
            }
            scan+=2;
            scanValue=*scan;
        }
        SweepBatchNode sortBounds;
        {
            SortArr15* sa = &axes[1];
            char* d = (char*)sa->data;
            char* end = d + sa->size * 4 - 8;
            char* r = (char*)((void *)(::LowerBoundEntry((::Entry *)(void *)(d + 4), (::Entry *)(void *)(end), (unsigned short)quantized.low[1])));
            sortBounds.minY = (unsigned short)((r - d) >> 2);
            r = (char*)((void *)(::LowerBoundEntry((::Entry *)(void *)(d + 4), (::Entry *)(void *)(end), (unsigned short)quantized.high[1])));
            sortBounds.maxY = (unsigned short)(((r - d) - 4) >> 2);
        }
        {
            SortArr15* sa = &axes[2];
            char* d = (char*)sa->data;
            char* end = d + sa->size * 4 - 8;
            char* r = (char*)((void *)(::LowerBoundEntry((::Entry *)(void *)(d + 4), (::Entry *)(void *)(end), (unsigned short)quantized.low[2])));
            sortBounds.minZ = (unsigned short)((r - d) >> 2);
            r = (char*)((void *)(::LowerBoundEntry((::Entry *)(void *)(d + 4), (::Entry *)(void *)(end), (unsigned short)quantized.high[2])));
            sortBounds.maxZ = (unsigned short)(((r - d) - 4) >> 2);
        }
        {
            SweepBatchNode* group = arrA0.data;
            int* bp=bits;
            int* bitsEnd = bits + (arrA0.size >> 5) + 1;
            for (; bp < bitsEnd; bp++) {
                unsigned int word = *bp;
                SweepBatchNode* rec = group;
                while (word) {
                    if(word & 15) {
                        if(word & 1) {
                            if(!rec[0].disjointYZ(sortBounds) && !rec[0].isMarker())
                                ((SweepBatchNode**)local.data)[local.size++]=rec+0;
                        }
                        if(word & 2) {
                            if(!rec[1].disjointYZ(sortBounds) && !rec[1].isMarker())
                                ((SweepBatchNode**)local.data)[local.size++]=rec+1;
                        }
                        if(word & 4) {
                            if(!rec[2].disjointYZ(sortBounds) && !rec[2].isMarker())
                                ((SweepBatchNode**)local.data)[local.size++]=rec+2;
                        }
                        if(word & 8) {
                            if(!rec[3].disjointYZ(sortBounds) && !rec[3].isMarker())
                                ((SweepBatchNode**)local.data)[local.size++]=rec+3;
                        }
                    }
                    word >>= 4;
                    rec += 4;
                }
                group += 32;
            }
        }
        {
            hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
            if ((bitmap.capacity & 0x80000000) == 0) al->bufFree( bitmap.data, (bitmap.capacity & 0x3fffffff) * 4);
        }
    
}

// @fnv 0x00d18400
void Sweep15::FUN_00d18400(In1* p1, In2* p2, void* p3)
{
    Endpoint* ptrs[3];
    BatchAabb spl;
    In2* g = p2;
    if (g->gate < 1) return;
    In1* input = p1;
    int capA4 = arrA0.size;
    int savedN = input->count;
    int two = savedN + savedN;
    SweepBuffer<Endpoint> b1(two);
    SweepBuffer<Endpoint> b2(two);
    SweepBuffer<Endpoint> b3(two);
    BatchNodeArr local; local.data = 0; local.size = 0; local.capacity = (int)0x80000000;
    {
        if ((local.capacity & 0x3fffffff) < capA4)
            ::FUN_00c908c0((::SpawnedObject *)(&hkMemoryRouter::getInstance().temp()), (::SpawnedArray *)(void *)(&local), capA4, 4);
    }
    {
        BatchNodeArray& nodes=arrA0;
        hkMemoryAllocator* growArg = &hkMemoryRouter::getInstance().heap();
        int need = nodes.size + savedN;
        if ((nodes.capacity & 0x3fffffff) < need) {
            int want = nodes.capacity & 0x3fffffff;
            want += want;
            if (need < want) need = want;
            ::FUN_00c908c0((::SpawnedObject *)(growArg), (::SpawnedArray *)(void *)(&nodes), need, 0x10);
        }
        nodes.size += savedN;
    }
    spl.low.v=_mm_set1_ps(::DAT_0104da48);
    spl.high.v=_mm_set1_ps(::DAT_0104e148);
    ptrs[0] = b1.data; ptrs[1] = b2.data; ptrs[2] = b3.data;
    int i=0;
    if(i<savedN) {

        do {

            spl.include(p2->base[i]);
            QuantBatchAabb quantized;
            quantizeSweepAabb(m_kVectorAt40,p2->base[i],m_kVectorAt50,m_vScale,quantized);
            unsigned int* ca=quantized.low;unsigned int* db=quantized.high;
            int destIdx=capA4+i;
            SweepObjectHandle* val = p1->f0[i];
            SweepBatchNode* rec = arrA0.data + destIdx;
            rec->handle = val;
            val->id = destIdx;
            Endpoint* o1=ptrs[0]+i*2;
            o1[0].value=(unsigned short)ca[0];o1[0].handle=(unsigned short)destIdx;
            o1[1].value=(unsigned short)db[0];o1[1].handle=(unsigned short)destIdx;
            Endpoint* o2=ptrs[1]+i*2;
            o2[0].value=(unsigned short)ca[1];o2[0].handle=(unsigned short)destIdx;
            o2[1].value=(unsigned short)db[1];o2[1].handle=(unsigned short)destIdx;
            Endpoint* o3=ptrs[2]+i*2;
            o3[0].value=(unsigned short)ca[2];o3[0].handle=(unsigned short)destIdx;
            o3[1].value=(unsigned short)db[2];o3[1].handle=(unsigned short)destIdx;
            (void)ptrs;


            ++i;
        } while(i<savedN);
    }
    arrA0.setSizeUnchecked(capA4);
    collectSweepCandidates(spl,local);

    {
        BatchNodeArray& nodes=arrA0;
        hkMemoryAllocator* growArg = &hkMemoryRouter::getInstance().heap();
        int need = nodes.size + savedN;
        if ((nodes.capacity & 0x3fffffff) < need) {
            int want = nodes.capacity & 0x3fffffff;
            want += want;
            if (need < want) need = want;
            ::FUN_00c908c0((::SpawnedObject *)(growArg), (::SpawnedArray *)(void *)(&nodes), need, 0x10);
        }
        nodes.size += savedN;
    }
    void* baseA0 = arrA0.data;
    int outArr[3];
    int endPointCount;
    for (int i = 0; i < 3; i++) {
        endPointCount=savedN+savedN;
        int twoN=endPointCount;
        sortSweepEndpoints(ptrs[i],twoN,EndpointOrder());
    }
    for (int i = 0; i < 3; i++) {
        SortArr15* sa = axes + i;
        outArr[i] = reinterpret_cast<::FUN_00d11e80_cls *>((sa))->InsertEndpoints((char *)(baseA0), i, (::S_00d1a180_EndPoint *)(ptrs[i]), endPointCount);
    }
    reinterpret_cast<::S_00d19d90_Class *>(&(axes[0]))->MergeSortedEndpoints(baseA0, outArr[0], (::Endpoint *)(b1.data), endPointCount);
    reinterpret_cast<::SweepMerge *>(&(axes[1]))->FUN_00d19e40((char *)(baseA0), outArr[1], (::Endpoint *)(b2.data), endPointCount);
    reinterpret_cast<::FUN_00d19ef0_cls *>(&(axes[2]))->FUN_00d19ef0((char *)(baseA0), outArr[2], (::Pair *)(b3.data), endPointCount);
    if(m_iMarkerCount) {
        for(int i=0;i<m_iMarkerCount;++i) {
            SweepBatchNode& node=arrA0.data[m_pOverlappingMarkerInfo[i].node];
            node.maxY+=(unsigned short)(endPointCount);
            node.maxZ+=(unsigned short)(endPointCount);
        }
    }
    SweepBuffer<SweepBatchNode> sortedNew(savedN + 1);
     
    SweepBuffer<BatchSweepKey> newKeys(savedN + 4);
     
    SweepBuffer<BatchSweepKey> newScratch(savedN + 4);
     
    {
        unsigned short* b = (unsigned short*)newKeys.data;
        for (int i = 0; i < savedN; i++) {
            b[i * 2 + 1] = (unsigned short)(capA4 + i);
            b[i * 2] = arrA0.data[capA4+i].minX;
        }
        b[savedN * 2] = (unsigned short)0xffff;
        b[savedN * 2 + 2] = (unsigned short)0xffff;
        b[savedN * 2 + 4] = (unsigned short)0xffff;
    }
    ::FUN_00d9fcf0((unsigned int *)(newKeys.data), (savedN + 3) & 0xfffffffc, (unsigned int *)(newScratch.data));
    for(int i=0;i<savedN;++i) sortedNew[i]=arrA0.data[newKeys[i].idx];
    ((SweepBatchNode*)sortedNew.data)[savedN].minX = (unsigned short)0xffff;
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((newScratch.capacity & (int)0x80000000) == 0) al->bufFree( newScratch.data, (newScratch.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((newKeys.capacity & 0x80000000) == 0) al->bufFree( newKeys.data, (newKeys.capacity & 0x3fffffff) * 4);
    }
    int cntC = local.size;
    SweepBuffer<SweepBatchNode> sortedOld(cntC + 1);
     
    SweepBuffer<BatchSweepKey> oldKeys(cntC + 4);
     
    SweepBuffer<BatchSweepKey> oldScratch(cntC + 4);
    SweepBatchNode* oldBase=arrA0.data;
     
    {
        unsigned short* b = (unsigned short*)oldKeys.data;
        for (int i = 0; i < cntC; i++) {
            SweepBatchNode* rec = ((SweepBatchNode**)local.data)[i];
            b[i * 2 + 1] = (unsigned short)(rec-oldBase);
            b[i * 2] = rec->minX;
        }
        b[cntC * 2] = (unsigned short)0xffff;
        b[cntC * 2 + 2] = (unsigned short)0xffff;
        b[cntC * 2 + 4] = (unsigned short)0xffff;
    }
    ::FUN_00d9fcf0((unsigned int *)(oldKeys.data), (cntC + 3) & 0xfffffffc, (unsigned int *)(oldScratch.data));
    for(int i=0;i<cntC;++i) sortedOld[i]=arrA0.data[oldKeys[i].idx];
    ((SweepBatchNode*)sortedOld.data)[cntC].minX = (unsigned short)0xffff;
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((oldScratch.capacity & (int)0x80000000) == 0) al->bufFree( oldScratch.data, (oldScratch.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((oldKeys.capacity & (int)0x80000000) == 0) al->bufFree( oldKeys.data, (oldKeys.capacity & 0x3fffffff) * 4);
    }
    ::CollectNodePairs(this, (::S_00d138a0_Node *)(sortedNew.data), savedN, static_cast<::S_00d138a0_Array *>(p3));
    reinterpret_cast<::C_00d13620 *>(this)->BuildBroadPhasePairs((::S_00d138a0_Node *)(sortedNew.data), savedN, (::S_00d138a0_Node *)(sortedOld.data), cntC, 0, *static_cast<::BroadPhasePairArray *>(p3));
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((sortedOld.capacity & 0x80000000) == 0) al->bufFree( sortedOld.data, (sortedOld.capacity & 0x3fffffff) * 16);
    }
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((sortedNew.capacity & 0x80000000) == 0) al->bufFree( sortedNew.data, (sortedNew.capacity & 0x3fffffff) * 16);
    }
    local.clearAndFree();
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((b3.capacity & 0x80000000) == 0) al->bufFree( b3.data, (b3.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((b2.capacity & 0x80000000) == 0) al->bufFree( b2.data, (b2.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryAllocator* al = &hkMemoryRouter::getInstance().temp();
        if ((b1.capacity & 0x80000000) == 0) al->bufFree( b1.data, (b1.capacity & 0x3fffffff) * 4);
    }
    return;
}

// Moved from hkp3axissweep_gs_nogs_variant.cpp (VEGAS-15).
int __cdecl FUN_00d19d10(const float* v, float* out);
void __cdecl FUN_00d19fa0(unsigned int* base, int lo, int hi, int unkArg);
void __cdecl QuickSortByLowWord(unsigned int* base, int lo, int hi, int unkArg);
void __cdecl FUN_00d10e80();
void __cdecl FUN_00d19fa0(SweepEndpoint* base, int lo, int hi, S00d13950_Less cmp);
void __cdecl QuickSortByLowWord(void*, int, int, KeyLess) throw();



struct __declspec(align(16)) RayDirection {
    union { __m128 value; float components[4]; };
    __forceinline float& component(int axis) { return components[axis]; }
    __forceinline void subtract(const RayDirection& origin) {
        value = _mm_sub_ps(value, origin.value);
    }
};

struct SweepEndpointD16300 {
    unsigned short position;
    unsigned short handle;
};



struct SweepAxis {
    SweepEndpointD16300* entries;
    int count;
    int capacity;

    __forceinline int GetLogicalSize() const { return count; }
    __forceinline const SweepEndpointD16300* begin() const { return entries; }
    __forceinline const SweepEndpointD16300& operator[](int i) const { return entries[i]; }
};



struct SweepScan {
    float origin[4];
    int rayCount;
    float* positions;
    int positionStride;
    SweepAxis* axes;
};

struct SweepHandle;

struct SweepRayCast {
    virtual void reserved0();
    virtual float intersect(const SweepHandle* handle, int rayIndex);
};


inline float sweepBound(float x,float offset,float scale) { return (x+offset)*scale; }
inline float sweepSub(float x,float y) { return x-y; }

inline float sweepMin(float a, float b) { return a < b ? a : b; }

struct SweepKeyValues { unsigned int x,y,z,w; };

union SweepScratch { SweepRayCast* collector; float cursorSteps; float curMask; };

struct SweepAllocation { int size; int capacity; };

struct SweepFlag {
    unsigned char value;
    SweepFlag& operator^=(unsigned char mask) { value ^= mask; return *this; }
};


__forceinline SweepEndpointD16300* searchEndpoints(const SweepAxis& axis,const unsigned int* low,int ordinal,unsigned char* a,int idx) {


    const SweepEndpointD16300* midP=&axis[axis.GetLogicalSize()>>1];
    const SweepEndpointD16300* p;
    
    if (low[ordinal] < midP->position) {
        const SweepEndpointD16300* endP = axis.begin()+axis.GetLogicalSize()-4;
        for(p = &axis[1]; p < endP && p[3].position <= low[ordinal]; p += 4) {
            ((SweepFlag*)a)[p[0].handle] ^= idx;
            ((SweepFlag*)a)[p[1].handle] ^= idx;
            ((SweepFlag*)a)[p[2].handle] ^= idx;
            ((SweepFlag*)a)[p[3].handle] ^= idx;
        }
        for(;p->position <= low[ordinal];++p) ((SweepFlag*)a)[p->handle] ^= idx;
    } else {
        const SweepEndpointD16300* endP = axis.begin()+4;
        for(p = &axis[axis.GetLogicalSize()-2];p >= endP && p[-3].position > low[ordinal];p -= 4) {
            ((SweepFlag*)a)[p[0].handle] ^= idx;
            ((SweepFlag*)a)[p[-1].handle] ^= idx;
            ((SweepFlag*)a)[p[-2].handle] ^= idx;
            ((SweepFlag*)a)[p[-3].handle] ^= idx;
        }
        for(;p->position > low[ordinal];--p) ((SweepFlag*)a)[p->handle] ^= idx;
        ++p;
    }
    return (SweepEndpointD16300*)p;
}

struct SweepNodeD16300 {
    unsigned short minY, minZ, maxY, maxZ, minX, maxX;
    SweepHandle* handle;
    int isMarker() const { return (uintptr_t)handle & 1; }
};

struct SweepSpace {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    float centerOffset[4];
    unsigned int unk50, unk54, unk58, unk5c;
    float reciprocalExtent[4];
    unsigned int unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c;
    SweepNodeD16300* nodes;
    int numNodes;
    unsigned int unkA8;
    SweepAxis axes[3];
    unsigned int unkD0, unkD4, unkD8;
    float tolerance;
    void FUN_00d16300(const SweepScan& scan, SweepRayCast* rays, int rayStride) const;
};

// @fnv 0x00d16300
void SweepSpace::FUN_00d16300(const SweepScan& scan, SweepRayCast* rays, int rayStride) const
{
    __declspec(align(16)) unsigned int sweepKeys[4];
    SweepEndpointD16300* c[3];
    int capacity;
    __declspec(align(16)) float distances[4];
    __declspec(align(16)) float bias[4];
    SweepEndpointD16300* nextEndpoint[3];
    __declspec(align(16)) float inverse[4];
    int inv[3];
    RayDirection direction;

    unsigned int handle;
    (void)handle;
    __m128 node3;
    node3 = _mm_mul_ps(_mm_add_ps(_mm_load_ps(centerOffset), _mm_load_ps(scan.origin)), _mm_load_ps(reciprocalExtent));
    __m128 dist = _mm_setzero_ps();
    node3 = _mm_min_ps(node3, (*reinterpret_cast<__m128 *>(&::DAT_011b3790)));
    node3 = _mm_max_ps(node3, dist);
    node3 = _mm_add_ps(node3, (*reinterpret_cast<__m128 *>(&::DAT_011b3770)));
    _mm_store_ps((float*)sweepKeys, node3);
    SweepKeyValues x = { sweepKeys[0] >> 7, sweepKeys[1] >> 7, sweepKeys[2] >> 7, sweepKeys[3] >> 7 };
    sweepKeys[0] = (unsigned short)x.x;
    sweepKeys[1] = (unsigned short)x.y;
    sweepKeys[2] = (unsigned short)x.z;
    sweepKeys[3] = (unsigned short)x.w;

    unsigned long bytesNeeded = numNodes + 16;
    unsigned char* a;
    SweepScratch scratch;
    hkMemoryAllocator* z = &hkMemoryRouter::getInstance().temp();
    int req = bytesNeeded;
    if (req) {
        int n = req;
        a = static_cast<unsigned char*>(z->bufAlloc(n));
        req = n;
    } else {
        a = 0;
    }
    capacity = req ? req : 0x80000000;

    float* nearest = (float*)a;
    for (int n = numNodes >> 4; n >= 0; --n) {
        float* scaled;
        scaled = nearest;
        nearest += 4;
        _mm_store_ps(scaled, dist);
    }

    const SweepAxis* axesToScan = scan.axes ? scan.axes : axes;
    int idx = 0x11;
    for (int axisIndex = 0; axisIndex < 3; ++axisIndex, idx += idx) {
        nextEndpoint[axisIndex] = searchEndpoints(axesToScan[axisIndex],sweepKeys,axisIndex,a,idx);
    }

    unsigned int n = scan.rayCount;
    float* cnt = static_cast<float*>(hkMemoryRouter::getInstance().allocateStack((sizeof(float) * n + 0x7f) & ~size_t(0x7f)));
    for (int q = 0; q < scan.rayCount; ++q) {
        cnt[q] = 1.0f;
    }

    const unsigned int* p = (const unsigned int*)a;
    const unsigned int* pEnd = p + (numNodes >> 2) + 1;
    const SweepNodeD16300* node = nodes;
    while (p < pEnd) {
        if (!((p[0] + 0x01010101) & 0x08080808)) {
            if (!((p[1] + 0x01010101) & 0x08080808)) {
                if (!((p[2] + 0x01010101) & 0x08080808)) {
                    node += 12;
                    p += 3;
                    continue;
                }
                node += 8;
                p += 2;
                continue;
            }
            node += 4;
            p++;
            continue;
        }

        const unsigned char* f = (const unsigned char*)p;
        if (f[0] == 0x77 && !node[0].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[0].handle, r);
                float selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }
        if (f[1] == 0x77 && !node[1].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[1].handle, r);
                float selectedDistance;
                selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }
        if (f[2] == 0x77 && !node[2].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[2].handle, r);
                float selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }
        if (f[3] == 0x77 && !node[3].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[3].handle, r);
                float selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }

        node += 4;
        p++;
    }

    a[0] = 0x88;
    SweepRayCast* in = rays;
    int nodeCount = numNodes;
    {
        for (int ray = 0; ray < scan.rayCount; ++ray) {
            float scaledDiff = cnt[ray];
            c[0] = nextEndpoint[0];
            c[1] = nextEndpoint[1];
            c[2] = nextEndpoint[2];
            unsigned int* res = (unsigned int*)((char*)scan.positions + ray * scan.positionStride);
            sweepKeys[0] = res[0];
            sweepKeys[1] = res[1];
            sweepKeys[2] = res[2];
            sweepKeys[3] = res[3];
            direction.value = _mm_load_ps((float*)sweepKeys);
            direction.subtract(*(const RayDirection*)scan.origin);


            for (int k = 0; 3 > k; ++k) {
                float zeroOut = direction.component(k) * reciprocalExtent[k];
                float s = fabsf(zeroOut);
                scratch.cursorSteps = (scan.origin[k] + centerOffset[k]) * reciprocalExtent[k];
                if (s < scratch.cursorSteps * 1.1920928955078125e-07 ||
                    s < sweepBound(((float*)sweepKeys)[k], centerOffset[k], reciprocalExtent[k]) * 1.1920928955078125e-07) {
                    inverse[k] = 0.0f;
                    bias[k] = -2.0f;
                } else {
                    inv[k] = 1;
                    float allocator;
                    allocator = 1.0f / zeroOut;
                    if (zeroOut < 0.0f) {
                        inv[k] = -1;
                        c[k] = c[k] - 1;
                    }
                    inverse[k] = allocator;
                    bias[k] = allocator * sweepSub(scratch.cursorSteps, tolerance);
                }
            }

            distances[0] = (float)(int)(c[0]->position) * inverse[0] - bias[0];
            distances[1] = (float)(int)(c[1]->position) * inverse[1] - bias[1];
            distances[2] = (float)(int)(c[2]->position) * inverse[2] - bias[2];

            while (true) {
                long node2;
                if (distances[0] < distances[1]) {
                    if (!(distances[0] < distances[2])) {
                        node2 = 2;
                        scratch.curMask = distances[2];
                    } else {
                        node2 = 0;
                        scratch.curMask = distances[0];
                    }
                } else {
                    if (distances[1] < distances[2]) {
                        node2 = 1;
                        scratch.curMask = distances[1];
                    } else {
                        node2 = 2;
                        scratch.curMask = distances[2];
                    }
                }

                if (scratch.curMask > scaledDiff) break;

                unsigned char sweepCursor = (unsigned char)(1 << (node2 + 4));
                do {
                    SweepEndpointD16300* current;
                    current = c[node2];
                    handle = current->handle;
                    unsigned char& fl = a[handle];
                    fl ^= sweepCursor;
                    if (fl >= 0x70) {
                        if (handle == 0) {
                            distances[node2] = 2.0f;
                            break;
                        }
                        const SweepNodeD16300& y = nodes[handle];
                        if (!((uintptr_t)y.handle & 1)) {
                            float dimensions = in->intersect(y.handle, ray);
                            if (!(scaledDiff < dimensions)) {
                                scaledDiff = dimensions;
                            }
                        }
                    }
                    unsigned int pos = current->position;
                    _ReadWriteBarrier();
                    SweepEndpointD16300* p;
                    p = c[node2] = current + inv[node2];
                    if ((unsigned short)pos != p->position) {
                        distances[node2] = (float)(int)(p->position) * inverse[node2] - bias[node2];
                        break;
                    }
                } while (true);
            }

            if (ray < scan.rayCount - 1) {
                unsigned int* flagEnd;
                flagEnd = (unsigned int*)a;
                unsigned int* end = (unsigned int*)(a + ((nodeCount >> 2) * 4) + 4);
                for (; flagEnd < end; flagEnd += 2) {
                    unsigned long rayBest;
                    rayBest = flagEnd[0] & 0x0f0f0f0f;
                    unsigned int val = flagEnd[1] & 0x0f0f0f0f;
                    flagEnd[0] = (rayBest << 4) | rayBest;
                    flagEnd[1] = (val << 4) | val;
                }
            }
            in = (SweepRayCast*)((char*)in + rayStride);
        }
    }

    hkMemoryRouter::getInstance().deallocateStack(cnt);
    hkMemoryAllocator& endpoint = hkMemoryRouter::getInstance().temp();
    if ((capacity & 0x80000000) == 0) {
        endpoint.bufFree(a, capacity & 0x3fffffff);
    }
}

// Moved from hkp3axissweep_rtm_variant.cpp (VEGAS-15).
unsigned short MaxUnsignedShort(unsigned short ausLeft, unsigned short ausRight);
void __cdecl ResizeAudioStream(void*, void*, int);
void ToggleBit(int aiBitIndex, void* apBits);
void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);
void FUN_00d10af0(int index, unsigned int* apuiBits);
void __cdecl FUN_00c908c0(void* allocator, FUN_00d11da0_cls* self, unsigned int newCap, int elemSize);
int __cdecl FUN_00d19d10(const float* afValues, float* pfMin);
void __cdecl FUN_00d19fa0(unsigned int* auiValues, int lo, int hi, int auiUnused);
void __cdecl QuickSortByLowWord(unsigned int* auiArray, int lo, int hi, int auiUnused);
static int FUN_00d10b10(void* self, int index, unsigned int* apuiBits);
void __cdecl FUN_00c908c0(void* alloc, void* self, int newCap, int elemSize);
void __cdecl FUN_00c908c0(hkMemoryAllocator* a, void* arr, int cap, int esz);
template<class T> struct RtmArr {
    T* data;
    int size;
    unsigned cap;
    __forceinline void SetSize(int n) {
        SetSize(hkMemoryRouter::getInstance().heap(), n);
    }
    __forceinline void SetSize(hkMemoryAllocator& a, int n) {
        int c = cap & 0x3fffffff;
        if (c < n) {
            int nc = c * 2;
            if (n >= nc) nc = n;
            FUN_00c908c0(&a, this, nc, sizeof(T));
        }
        size = n;
    }
};

struct SweepDeltaPair { const unsigned short* x; const unsigned short* y; };
struct SweepEdge { unsigned short value,index; };
struct RtmSweepAxis { SweepEdge* data; int size,capacity; };
struct SweepHandle { unsigned index; };
struct __declspec(align(16)) SweepBounds { unsigned v[4]; };
struct SweepBoundsPair { SweepBounds low,high; };
struct SweepBox { unsigned lo[4],hi[4]; };
struct SweepTarget {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 CacheNode* nodes;
 unsigned unkA4,unkA8;
 RtmSweepAxis xAxis,yAxis,zAxis;
 unsigned unkD0,unkD4;
 void* pairs;
 template<int Axis> __forceinline unsigned short& minimum(CacheNode& n) { return Axis==0?n.minX:Axis==1?n.minY:n.minZ; }
 template<int Axis> __forceinline unsigned short& maximum(CacheNode& n) { return Axis==0?n.maxX:Axis==1?n.maxY:n.maxZ; }
 __forceinline unsigned yRightFlags(CacheNode* a,CacheNode* b) {SweepDeltaPair p;p.y=&b->maxZ;p.x=&a->maxZ;unsigned short f=(unsigned short)(*p.x-b->minZ)|(unsigned short)(*p.y-a->minZ)|(unsigned short)(a->maxX-b->minX)|(unsigned short)(b->maxX-a->minX);return f;}
 template<int Axis> __forceinline unsigned overlaps(CacheNode* a,CacheNode* b) {
  if(Axis==0) { const unsigned& x=*(const unsigned*)&a->maxY; const unsigned& y=*(const unsigned*)&b->maxY; const unsigned& u=*(const unsigned*)&a->minY; const unsigned& v=*(const unsigned*)&b->minY; return (x-v)|(y-u); }
  unsigned short flags;
  if (Axis==1) flags=(unsigned short)(b->maxZ-a->minZ)|(unsigned short)(a->maxZ-b->minZ)|(unsigned short)(a->maxX-b->minX)|(unsigned short)(b->maxX-a->minX);
  else flags=(unsigned short)(b->maxX-a->minX)|(unsigned short)(a->maxX-b->minX)|(unsigned short)(b->maxY-a->minY)|(unsigned short)(a->maxY-b->minY);
  return flags;
 }
 template<int Axis> __forceinline void added(CacheNode* a,CacheNode* b,unsigned index,void* out) {
  if(Axis==0) ::FUN_00d11c60(pairs,(::FnvNode *)(a),index,(::FnvNode *)(b),(::FnvArr *)(out));
  else AppendPairToBuffer((UnkRet*)a,(UnkRet*)b,out);
 }
 template<int Axis> __forceinline void removed(CacheNode* a,CacheNode* b,unsigned index,void* out) {
  if(Axis==0) ::fnv_00d11d00::RemoveOrAppendTagEntry((char *)(pairs),(::fnv_00d11d00::TagEntity *)(a),index,(::fnv_00d11d00::TagOwner *)(b),(::fnv_00d11d00::PairArray *)(out));
  else ::AppendPairEntry((::FUN_00d11c10_cls *)(a),(::FUN_00d11c10_cls *)(b),(::PairArray *)(out));
 }
 template<int Axis> __forceinline void updateAxis(CacheNode* allNodes,RtmSweepAxis& axis,CacheNode* node,unsigned index,unsigned low,unsigned high,void* add,void* remove) {
  CacheNode* leftNeighbor; (void)leftNeighbor;
  CacheNode* backNeighbor; (void)backNeighbor;
  CacheNode* rightNeighbor; (void)rightNeighbor;
  CacheNode* outNeighbor; (void)outNeighbor;
  unsigned position=minimum<Axis>(*node);
  SweepEdge* edge=axis.data+position;
  unsigned value=edge[-1].value;
  while(low<value) {
   leftNeighbor=allNodes+edge[-1].index;
   *edge=edge[-1]; --edge;
   if(value&1) {
    unsigned separated=overlaps<Axis>(node,leftNeighbor);
    maximum<Axis>(*leftNeighbor)=(unsigned short)position;
    if(!(separated & (Axis==0?0x80008000:0x8000))) added<Axis>(node,leftNeighbor,index,add);
   } else minimum<Axis>(*leftNeighbor)=(unsigned short)position;
   value=edge[-1].value; --position;
  }
  while(low==edge[-1].value && index<edge[-1].index) {
   unsigned otherIndex=edge[-1].index;
   *edge=edge[-1]; --edge;
   minimum<Axis>(allNodes[otherIndex])=(unsigned short)position; --position;
  }
  edge->index=(unsigned short)index; edge->value=(unsigned short)low; minimum<Axis>(*node)=(unsigned short)position;
  position=maximum<Axis>(*node);edge=axis.data+position;
  value=edge[1].value;
  while(high>value) {
   *edge=edge[1]; ++edge; outNeighbor=allNodes+edge->index; ++position;
   if(!(value&1)) {
    unsigned separated=overlaps<Axis>(node,outNeighbor);
    --minimum<Axis>(*outNeighbor);
    if(!(separated & (Axis==0?0x80008000:0x8000))) added<Axis>(node,outNeighbor,index,add);
   } else --maximum<Axis>(*outNeighbor);
   value=edge[1].value;
  }
  while(high==edge[1].value) {
   unsigned otherIndex=edge[1].index;
   if(index<=otherIndex || otherIndex==0) break; *edge=edge[1]; ++edge;
   --maximum<Axis>(allNodes[otherIndex]); ++position;
  }
  value=edge[-1].value;
  while(high<value) {
   *edge=edge[-1]; backNeighbor=allNodes+edge[-1].index; --edge; --position;
   if(!(value&1)) {
    unsigned separated=overlaps<Axis>(node,backNeighbor);
    ++minimum<Axis>(*backNeighbor);
    if(!(separated & (Axis==0?0x80008000:0x8000))) removed<Axis>(node,backNeighbor,index,remove);
   } else ++maximum<Axis>(*backNeighbor);
   value=edge[-1].value;
  }
  while(high==edge[-1].value && index<edge[-1].index) {
   unsigned otherIndex=edge[-1].index; *edge=edge[-1]; --edge;
   ++maximum<Axis>(allNodes[otherIndex]); --position;
  }
  maximum<Axis>(*node)=(unsigned short)position; edge->value=(unsigned short)high; edge->index=(unsigned short)index;
  position=minimum<Axis>(*node);edge=axis.data+position;value=edge[1].value;
  while(low>value) {
   rightNeighbor=allNodes+edge[1].index; *edge=edge[1]; ++edge; ++position;
   if(value&1) {
    unsigned separated=Axis==1?yRightFlags(node,rightNeighbor):overlaps<Axis>(node,rightNeighbor);
    --maximum<Axis>(*rightNeighbor);
    if(!(separated & (Axis==0?0x80008000:0x8000))) removed<Axis>(node,rightNeighbor,index,remove);
   } else --minimum<Axis>(*rightNeighbor);
   value=edge[1].value;
  }
  while(low==edge[1].value && index>edge[1].index) {
   unsigned otherIndex=edge[1].index;*edge=edge[1];++edge;
   --minimum<Axis>(allNodes[otherIndex]);++position;
  }
  minimum<Axis>(*node)=(unsigned short)position;edge->index=(unsigned short)index;edge->value=(unsigned short)low;
 }
 void FUN_00d12b80(SweepHandle**,const SweepBox*,int,void*,void*);
};
// @fnv 0x00d12b80
void SweepTarget::FUN_00d12b80(SweepHandle** handles,const SweepBox* boxes,int count,void* add,void* remove) {
 SweepHandle** end; (void)end;
 CacheNode* node; (void)node;
 SweepHandle** current; (void)current;
 CacheNode* base; (void)base;
 unsigned index; (void)index;

 end=handles+count;
 for(current=handles;current<end;++current,++boxes) {
  SweepBoundsPair bounds;
  for(int k=0;k<3;++k) bounds.low.v[k]=boxes->lo[k]>>15;
  for(int k=0;k<3;++k) {
   unsigned v=boxes->hi[k]>>15;
   if(v!=0xffff) ++v;
   bounds.high.v[k]=v|1;
  }

  for(int k=0;k<3;++k) bounds.low.v[k]&=0xfffe;
  base=nodes;
  index=(*current)->index;
  node=base+index;
  updateAxis<0>(base,xAxis,node,index,bounds.low.v[0],bounds.high.v[0],add,remove);
  updateAxis<1>(base,yAxis,node,index,bounds.low.v[1],bounds.high.v[1],add,remove);
  updateAxis<2>(base,zAxis,node,index,bounds.low.v[2],bounds.high.v[2],add,remove);
 }
}

// Moved from hkp3axissweep_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
void FUN_00d10c40(FourIntegerBlock* nodes, int n, int delta, const int* bound);
static unsigned int* FUN_00d11000(unsigned int* dst, int n);
unsigned int* CallZeroBlocks();

extern "C" const float DAT_010cd5b4;

struct OffsetScaleVector : SweepVec4 {
    void operator=(const OffsetScaleVector& v) { m_vComponents = v.m_vComponents; }
    float& operator()(int i) { return ((float*)&m_vComponents)[i]; }
    void setSub4(const OffsetScaleVector& a, const OffsetScaleVector& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    void setMul4(float r, const OffsetScaleVector& a) { __m128 t = _mm_load_ss(&r); m_vComponents = _mm_mul_ps(a.m_vComponents, _mm_shuffle_ps(t, t, 0)); }
    void setAddMul4(const OffsetScaleVector& a, const OffsetScaleVector& b, float r) { __m128 t = _mm_load_ss(&r); m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), b.m_vComponents), a.m_vComponents); }
    void zeroElement3() { __m128 z = _mm_setzero_ps(); m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, z), 0xc4); }
};

struct Sweep3Axis {
    OffsetScaleVector unk00;
    OffsetScaleVector unk10;
    OffsetScaleVector m_aabbMin;
    OffsetScaleVector m_aabbMax;
    OffsetScaleVector m_kVectorAt40;
    OffsetScaleVector m_kVectorAt50;
    OffsetScaleVector m_vScale;
    OffsetScaleVector m_kVectorAt70;
    OffsetScaleVector m_kVectorAt80;
    OffsetScaleVector m_kVectorAt90;

    void FUN_00d11020(const OffsetScaleVector& offsetLow, const OffsetScaleVector& offsetHigh, const OffsetScaleVector& scale);
};

// @fnv 0x00d11020
void Sweep3Axis::FUN_00d11020(const OffsetScaleVector& offsetLow, const OffsetScaleVector& offsetHigh, const OffsetScaleVector& scale)
{
    m_kVectorAt70 = offsetLow;
    m_kVectorAt80 = offsetHigh;
    m_kVectorAt90 = scale;
    m_kVectorAt40 = offsetLow;

    OffsetScaleVector span;
    span.setSub4(m_aabbMax, m_aabbMin);
    OffsetScaleVector spanInv;
    spanInv.set(1.0f / span(0), 1.0f / span(1), 1.0f / span(2), 0.0f);

    m_kVectorAt50.setAddMul4(m_kVectorAt40, span, DAT_010cd5b4);
    m_vScale.setMul4(::DAT_010cd5b0, spanInv);

    m_vScale.zeroElement3();
    m_kVectorAt40.zeroElement3();
    m_kVectorAt50.zeroElement3();
}
#include "generated/data/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.inc"
