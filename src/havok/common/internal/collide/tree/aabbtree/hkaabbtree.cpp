// havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp: ElemPool, Owner, RecordPool, MapD9 and more (24 functions)

#include "fnv_simd.h"
#include <cstddef>
#include <new>
#include "fnv/decl/HandlePool_d9c4.h"
#include "fnv/decl/S_00d9af30.h"
#include "fnv/decl/fnv_00d9c280__FUN_00d9c280_cls.h"
#include "fnv/decl/fnv_00d9c360__D9C360Tree.h"
#include "fnv/symbols_00d9a000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/decl/Sd9_Tree.h"
#include <xmmintrin.h>
// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/hkaabbtree.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00d9a4d0_Class.h"
#include "fnv/decl/IdxStand_.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d9c000.h"
#include "fnv/symbols_010d4000.h"
#include "fnv/symbols_01267000.h"
struct FUN_00d9be20_class {
};

struct FUN_00d9be30_class {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    void FUN_00d9be30();
};

struct FUN_00d9be20_cls {
};
struct FUN_00d9bed0_cls {
    void FUN_00d9bed0();
};
struct Obj_d9be20 {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    void FUN_00d9be20();
};
// @fnv 0x00d9be30
void FUN_00d9be30_class::FUN_00d9be30()
{
    reinterpret_cast<::Obj_d9be20 *>((reinterpret_cast<FUN_00d9be20_class*>(&this->m1c)))->FUN_00d9be20();
    m10 = 0;
    m14 = 0x7fffffff;
    m18 = 0;
}
// @fnv 0x00d9bed0
void FUN_00d9bed0_cls::FUN_00d9bed0()
{
    reinterpret_cast<::Obj_d9be20 *>((((FUN_00d9be20_cls*)((char*)this + 0x1c))))->FUN_00d9be20();
    *(int*)((char*)this + 0x10) = 0;
    *(unsigned short*)((char*)this + 0x14) = 0x7fff;
    *(int*)((char*)this + 0x18) = 0;
}
// @fnv 0x00d9be20
void Obj_d9be20::FUN_00d9be20() { m4 = 0; m10 = 0; }

#ifndef _INCLUDED_MM2

#endif

struct Vec4 {
    __m128 m_vComponents;
    Vec4& operator=(const Vec4& o) { m_vComponents = o.m_vComponents; return *this; }
};

struct Key {
    int a;
    int b;
    Key& operator=(const Key& o) { a = o.a; b = o.b; a = o.a; return *this; }
};

struct Elem {
    Vec4 v0;
    Vec4 v1;
    Key k;
    int c;
    int d;
};

struct IntArray {
    int* m_data;
    int m_iElementCount;
    int& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }
    int GetLogicalSize() const { return m_iElementCount; }
};

struct ElemPool {
    Elem* m_pElements;
    int m_pRayCursor;
    int m_unk08;
    IntArray m_freeArr;

    void Grow(int newCapacity, int a, int b);
    int AllocElem(int a, int b, const Elem& e);
};

// @fnv 0x00d9cd80
int ElemPool::AllocElem(int aiArg1, int aiArg2, const Elem& arElem)
{
    if (m_freeArr.GetLogicalSize() == 0)
        Grow(m_pRayCursor + 128, aiArg1, aiArg2);
    int idx = m_freeArr.back();
    m_freeArr.popBack();
    m_pElements[idx] = arElem;
    return idx;
}

struct FUN_00d9ce00_Class
{
    int base;
    int value;
    int unk08;
    int* items;
    int count;
    int FUN_00d9c450(int start, int first, int second);
    int* PopItem(int first, int second, int* output);
};

// @fnv 0x00d9ce00
int* FUN_00d9ce00_Class::PopItem(int first, int second, int* output)
{
    if (count == 0)
        FUN_00d9c450(value + 0x80, first, second);
    *output = items[count - 1];
    --count;
    return (int*)(((*output * 3) << 4) + base);
}

struct UnsignedShortArray { unsigned short* elements; unsigned int count; unsigned int capacity; };
struct AllocationContext { int unknown00, unknown04, unknown08, unknown0c; void* memory; };
struct Owner { int unknown00, unknown04, unknown08; UnsignedShortArray buffer; AllocationContext* FUN_00c85750(); unsigned short* AppendElement(unsigned short value); };
// Grows the buffer if it is full, appends value at the end, increments the count and returns a pointer to the stored element.
// @fnv 0x00d9bef0
unsigned short* Owner::AppendElement(unsigned short value) {
    UnsignedShortArray* pBuffer = &buffer;
    AllocationContext* context = FUN_00c85750();
    if (pBuffer->count == (pBuffer->capacity & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(context->memory), (::AudioStream *)(pBuffer), 2);
    unsigned short* pElement = pBuffer->elements + pBuffer->count;
    *pElement = value;
    ++pBuffer->count;
    return pElement;
}

struct Allocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void* p, unsigned int bytes);
};

struct AllocHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* m_pThreadAllocator;
};

AllocHolder* __cdecl FUN_00c85750();

struct S_d9bf30_Rec {
    int unk0; int unk4; int unk8; int unkc;
    unsigned short unk10; unsigned short unk12;
};

struct S_d9bf30_Words {
    unsigned short* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    void push(unsigned short v) {
        unsigned short* p = m_data + m_uiItemCount;
        for (int k = 0; k < 1; k++) p[k] = v;
        m_uiItemCount++;
    }
    __forceinline void refill(unsigned short newSize, int oldCount) {
        AllocHolder* holder = FUN_00c85750();
        Allocator* alloc = holder->m_pThreadAllocator;

        unsigned int cap = m_capFlags & 0x3fffffffu;
        if ((int)cap < (int)newSize) {
            unsigned int nc = cap + cap;
            if ((int)newSize >= (int)nc) {
                nc = newSize;
            }
            ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(void **)((void**)&m_data), nc, 2);
        }

        for (int i = (int)newSize - 1; i >= oldCount; --i) {
            push((unsigned short)i);
        }
    }
};

struct FUN_00d9bf30_cls {
    S_d9bf30_Rec* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    S_d9bf30_Words m_free;

    void AllocateRecords(unsigned short newSize, S_d9bf30_Rec** out, unsigned short* idx);
};

// @fnv 0x00d9bf30
void FUN_00d9bf30_cls::AllocateRecords(unsigned short newSize, S_d9bf30_Rec** apOutRec, unsigned short* apIndex)
{
    int oldCount = m_uiItemCount;
    int n = newSize;

    AllocHolder* holder = FUN_00c85750();
    Allocator* alloc;
    alloc = holder->m_pThreadAllocator;

    unsigned int cap = m_capFlags & 0x3fffffffu;
    if ((int)cap < n) {
        unsigned long nc = cap + cap;
        if (n >= (int)nc) {
            nc = newSize;
        }
        ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(void **)((void**)&m_data), nc, 0x14);
    }

    int k = n - m_uiItemCount;
    S_d9bf30_Rec* rec = m_data + m_uiItemCount;
    if (k > 0) {
        do {
            if (0 != rec) {
                rec->unk10 = 0;
            }
            ++rec;
        } while (--k != 0);
    }

    m_uiItemCount = newSize;

    m_free.refill(newSize, oldCount);

    int id = *apIndex;
    if ((unsigned short)id != 0x7fff) {
        *apOutRec = m_data + (unsigned short)id;
    }
}

namespace fnv_00d9c010 {
// ---------------------------------------------------------------------------
// ClearBuffers
//
// Releases the two growable buffers that the object owns and marks both of
// them empty again.
//
// Every buffer is described by a data pointer, the number of live items and
// the capacity that was reserved for it.  A capacity of 0x80000000 is the
// "empty" marker, a capacity with the sign bit set therefore means that
// nothing was reserved and nothing has to be released.
//
// The memory itself belongs to the audio sink that is reached through the
// thread local BSAudio instance; the number of bytes that is reported back
// to the sink is the masked capacity multiplied by the size of one item,
// because that is the number of bytes the sink handed out in the first
// place.  The release goes through the fifth entry of the sink's vtable.
// ---------------------------------------------------------------------------

// The sink that owns the memory of the streamed buffers.
struct AudioSink {
    virtual void* unk00();
    virtual void* unk04();
    virtual void* unk08();
    virtual void* unk0c();
    virtual void release(void* data, int size);
};

// The thread local audio system, the sink is its fifth member.
struct BSAudio {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioSink* m_sink;
};

// The thread local getter of the audio system (it is declared, not defined,
// because it lives in another translation unit).
BSAudio* __cdecl FUN_00c85750();

// The object that owns the two buffers: items of 48 bytes and items of 4
// bytes, each with its own data pointer, item count and capacity.
struct FUN_00d9c010_cls {
    void* m_data0;   // 0x00
    int m_count0;    // 0x04
    int m_capacity0; // 0x08
    void* m_data1;   // 0x0c
    int m_count1;    // 0x10
    int m_capacity1; // 0x14
    void ClearBuffers();
};

// @fnv 0x00d9c010
void FUN_00d9c010_cls::ClearBuffers()
{
    {
        BSAudio* audio = FUN_00c85750();
        AudioSink* sink = audio->m_sink;
        int capacity = m_capacity1;
        m_count1 = 0;
        if (!(capacity & 0x80000000))
            sink->release(m_data1, (capacity & 0x3fffffff) * 4);
        m_data1 = 0;
        m_capacity1 = 0x80000000;
    }
    {
        BSAudio* audio = FUN_00c85750();
        AudioSink* sink = audio->m_sink;
        int capacity = m_capacity0;
        m_count0 = 0;
        if (!(capacity & 0x80000000))
            sink->release(m_data0, (capacity & 0x3fffffff) * 48);
        m_data0 = 0;
        m_capacity0 = 0x80000000;
    }
}
}  // namespace fnv_00d9c010

namespace fnv_00d9c090 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d9c090_cls {
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void ClearArrays();
};

// @fnv 0x00d9c090
void FUN_00d9c090_cls::ClearArrays()
{
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapBits1 = m_uCapBits1;
    m_iCount1 = 0;
    if ((uCapBits1 & 0x80000000u) == 0) {
        pAllocator->FreeArray(m_pData1, (uCapBits1 & 0x3fffffffu) * 2);
    }
    m_pData1 = 0;
    m_uCapBits1 = 0x80000000u;

    AudioHolder* pHolder2 = FUN_00c85750();
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((uCapBits2 & 0x80000000u) == 0) {
        pAllocator2->FreeArray(m_pData2, (uCapBits2 & 0x3fffffffu) * 20);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
}
}  // namespace fnv_00d9c090

struct Record20 { int field0,field4,field8,fieldC,field10; };
struct RecordPool {
    Record20* records;
    unsigned short type;
    unsigned short unk06;
    int unk08;
    unsigned short* available;
    int count;
    unsigned short AddRecord(int first,int second,const Record20* item);
};
// @fnv 0x00d9c210
unsigned short RecordPool::AddRecord(int first,int second,const Record20* item) {
    if (!count) reinterpret_cast<::FUN_00d9bf30_cls *>(this)->AllocateRecords((unsigned short)(type + 0x80),(::S_d9bf30_Rec **)(first),(unsigned short *)(second));
    unsigned short slot=available[count - 1];
    volatile int& remaining = count;
    --remaining;
    records[slot] = *item;
    return slot;
}

namespace fnv_00d9c280 {
// PopGlyphRecord - pops one 16-bit entry off the object's stack and returns the
// record it names.  The stack is refilled (in blocks of 0x80 records) by
// AllocateRecords when it runs empty.
//
// Object layout (from the disassembly):
//   +0x00  Glyph20* m_pRecords   array of 0x14-byte records
//   +0x04  int      m_nRecords   number of records
//   +0x08  int      m_capRecords record capacity
//   +0x0c  ushort*  m_pStackBuffer     array of 16-bit stack entries
//   +0x10  int      m_nStack     number of stack entries
//   +0x14  int      m_capStack   stack capacity

struct Glyph20 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00d9bf30_cls {
};

struct FUN_00d9c280_cls {
    Glyph20* m_pRecords;      // +0x00
    int m_nRecords;           // +0x04
    int m_capRecords;         // +0x08
    unsigned short* m_pStackBuffer; // +0x0c
    int m_nStack;             // +0x10
    int m_capStack;           // +0x14

    Glyph20* PopGlyphRecord(int* outRecord, unsigned short* inChar, unsigned short* outChar);
};

// @fnv 0x00d9c280
Glyph20* FUN_00d9c280_cls::PopGlyphRecord(int* outRecord, unsigned short* inChar, unsigned short* outChar) {
    if (m_nStack == 0) {
        unsigned short index = (unsigned short)(0x80 + m_nRecords);
        reinterpret_cast<::FUN_00d9bf30_cls *>((((FUN_00d9bf30_cls*)this)))->AllocateRecords(index, (::S_d9bf30_Rec **)(outRecord), inChar);
    }
    unsigned short*& stack = m_pStackBuffer;
    *outChar = stack[m_nStack - 1];
    m_nStack--;
    return &m_pRecords[*outChar];
}
}  // namespace fnv_00d9c280

namespace fnv_00d9c320 {
extern int DAT_010d40ac;

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct SubObject_b3483 {
    int unk00;
};

struct FUN_00d9c320_cls {
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    SubObject_b3483 m_sub;

    FUN_00d9c320_cls* Destroy(unsigned char acFlags);
};

// Sets the vtable, calls BaseRelease and the sub-object's Release, and if bit 0 of acFlags is set frees this object through the audio allocator.
// @fnv 0x00d9c320
FUN_00d9c320_cls* FUN_00d9c320_cls::Destroy(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010d40ac;
    reinterpret_cast<::FUN_00d9bed0_cls *>(this)->FUN_00d9bed0();
    reinterpret_cast<::fnv_00d9c090::FUN_00d9c090_cls *>(&(m_sub))->ClearArrays();
    if (acFlags & 1) {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, 0x80);
    }
    return this;
}
}  // namespace fnv_00d9c320

namespace fnv_00d9c360 {
struct D9C360Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct D9C360MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D9C360Allocator* m_pStreamAllocator;

    D9C360Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D9C360MemoryRouter& __cdecl FUN_00c85750();

struct D9C360Node {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_pChildAtom;
    int unk24;
    unsigned int m_flags;
    int m_sibling;
};

struct D9C360NodeArray {
};

// hkInplaceArray<D9C360Node*, 128> without a destructor (Havok was built without EH).
struct D9C360NodeStack {
    D9C360Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    D9C360Node* m_kStorage[128];

    D9C360NodeStack() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000080) {}

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void AddBack(D9C360Node* n)
    {
        D9C360Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(D9C360Node*));
        m_data[m_iElementCount++] = n;
    }

    void release()
    {
        D9C360Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(D9C360Node*));
    }
};

struct D9C360Tree {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    D9C360NodeArray m_kNodeCollection;

    void TraverseTree(D9C360Node* root, void* context);
};

// @fnv 0x00d9c360
void D9C360Tree::TraverseTree(D9C360Node* node, void* context)
{
    if (!node)
        return;
    D9C360NodeStack stack;
    for (;;) {
        if (node->m_flags & 0x80000000) {
            if (stack.m_iElementCount == 0)
                break;
            node = stack.m_data[stack.m_iElementCount - 1];
            stack.m_iElementCount--;
            continue;
        }
        node = ((::fnv_00d9c360::D9C360Node *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(node->m_pChildAtom)));
        D9C360Node* sibling = (node->m_sibling != 0x7fffffff) ? ((::fnv_00d9c360::D9C360Node *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(node->m_sibling))) : 0;
        stack.AddBack(sibling);
    }
    stack.release();
}
}  // namespace fnv_00d9c360

struct BoundsNode { unsigned short m00,m02,m04,m06,m08,m0A,m0C,m0E,m10,m12; };
struct FUN_00d9a4d0_cls {  };
struct FUN_00d9b450_cls { int m00,m04,m08,m0C,m10,m14,m18; FUN_00d9a4d0_cls m1c; void UpdateBoundsNode(BoundsNode* a1,unsigned short a2,unsigned short a3); };
// Sets a node's m12 to a3, then unless m10 has bit 0x8000 set, updates its two child nodes and recomputes the node's bounds from them.
// @fnv 0x00d9b450
void FUN_00d9b450_cls::UpdateBoundsNode(BoundsNode* pNode,unsigned short usValue,unsigned short usValue2) {
 pNode->m12=usValue2;
 if(pNode->m10&0x8000) return;
 BoundsNode* pChild1=((::BoundsNode *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(m1c))->GetEntryOffset(pNode->m0C)));
 BoundsNode* pChild2=((::BoundsNode *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(m1c))->GetEntryOffset(pNode->m0E)));
 pChild1->m10=(pChild1->m10&0x8000)|usValue;
 pChild2->m10=(pChild2->m10&0x8000)|usValue;
 UpdateBoundsNode(pChild1,pNode->m0C,pNode->m0E);
 UpdateBoundsNode(pChild2,pNode->m0E,usValue2);
 unsigned short b=pChild2->m06, c=pChild1->m06; pNode->m06=c<b?c:b;
 b=pChild2->m00; c=pChild1->m00; pNode->m00=c>b?c:b;
 b=pChild2->m08; c=pChild1->m08; pNode->m08=c<b?c:b;
 b=pChild2->m02; c=pChild1->m02; pNode->m02=c>b?c:b;
 b=pChild2->m0A; c=pChild1->m0A; pNode->m0A=c<b?c:b;
 b=pChild2->m04; c=pChild1->m04; pNode->m04=c>b?c:b;
}

struct S_00d9d650_Heap
{
    virtual void unkVfn0();
    virtual void unkVfn1();
    virtual void unkVfn2();
    virtual void unkVfn3();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00d9d650_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d9d650_Heap* m_pStreamAllocator;
    S_00d9d650_Heap& heap() { return *m_pStreamAllocator; }
};

namespace fnvc_adapt { S_00d9d650_Router& __cdecl FUN_00c85750(); }

template <typename T>
struct S_00d9d650_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d9d650_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d9d650_Array() throw() { _clearAndDeallocate(fnvc_adapt::FUN_00c85750().heap()); }

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }

    void _clearAndDeallocate(S_00d9d650_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00d9d650_Heap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00d9d650_Heap& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n) { _setSize(fnvc_adapt::FUN_00c85750().heap(), n); }
};

struct S_00d9d650_Vector4
{
    __m128 m_vComponents;
    void operator=(const S_00d9d650_Vector4& v) { m_vComponents = v.m_vComponents; }
};

struct S_00d9d650_Aabb
{
    S_00d9d650_Vector4 m_kMinimumCorner;
    S_00d9d650_Vector4 m_kMaximumCorner;
};

struct S_00d9d650_Node
{
    S_00d9d650_Aabb m_kBounds;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void setLeaf(int key)
    {
        m_20 = key;
        m_28 |= 0x80000000;
    }
};

struct S_00d9d650_Pool
{
    void FUN_00d9c450(int numNodes, S_00d9d650_Node** root, int* a);
};

struct S_00d9d650_Tree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d9d650_Node* m_pTreeNode;
    int m_14;
    int m_iNodeCount;
    S_00d9d650_Pool m_kNodePool;

    void MergeNode(S_00d9d650_Node* root, int a, int b);
    void BuildTree(const S_00d9d650_Aabb* aabbs, const int* keys, int n, S_00d9d650_Array<int>& out) throw();
};

// @fnv 0x00d9d650
void S_00d9d650_Tree::BuildTree(const S_00d9d650_Aabb* aabbs, const int* keys, int n, S_00d9d650_Array<int>& out) throw()
{
    m_iNodeCount = n;
    if (n)
    {
        out.SetSizeAndGrow(n);
        m_kNodePool.FUN_00d9c450(2 * n - 1, &m_pTreeNode, &m_14);
        m_pTreeNode = ((::S_00d9d650_Node *)(reinterpret_cast<::FUN_00d9ce00_Class *>(&(m_kNodePool))->PopItem((int)(&m_pTreeNode), (int)(&m_14), &m_14)));
        m_pTreeNode->m_28 |= 0x7fffffff;

        S_00d9d650_Array<S_00d9d650_Aabb> tmp;
        tmp.SetSizeAndGrow(n);
        for (int i = 0; i < n; i++)
        {
            S_00d9d650_Aabb& d = tmp[i];
            d.m_kMaximumCorner = aabbs[i].m_kMaximumCorner;
            d.m_kMinimumCorner = aabbs[i].m_kMinimumCorner;
        }

        if (n == 1)
        {
            m_pTreeNode->setLeaf(keys[0]);
            m_pTreeNode->m_2c = 0x7fffffff;
            m_pTreeNode->m_kBounds = tmp[0];
            out[0] = m_14;
        }
        else
        {
            reinterpret_cast<::BuildTree *>(this)->FUN_00d9d1c0((const ::BuildAabb *)(tmp.m_data), keys, n, (::BuildTreeNode *)(m_pTreeNode), (::BuildArray<int> &)(out), 0);
        }
        MergeNode(m_pTreeNode, m_14, 0x7fffffff);
        reinterpret_cast<::fnv_00d9c360::D9C360Tree *>(this)->TraverseTree((::fnv_00d9c360::D9C360Node *)(m_pTreeNode), (void *)(0));
    }
}

struct Node_d9c520
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
};

struct Resolver_d9c520
{
};

struct TrackedArray_d9c520
{
    Node_d9c520** elements;
    unsigned int count;
    int capacity;
};

struct Pool_d9c520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Resolver_d9c520 resolver;

    void TraverseNodeTree(Node_d9c520* node, int second);
};

// Walks the node tree using a stack array, resolving children and pushing/popping nodes, then frees the tracked array if it was heap-allocated.
// @fnv 0x00d9c520
void Pool_d9c520::TraverseNodeTree(Node_d9c520* node, int second)
{
    if (node != 0)
    {
        TrackedArray_d9c520 nodeStack;
        Node_d9c520* stack[128];
        nodeStack.elements = stack;
        nodeStack.count = 0;
        nodeStack.capacity = 0x80000080;
        while (true)
        {
            if ((node->unk10 & 0x8000) != 0)
            {
                if (nodeStack.count == 0)
                    break;
                node = nodeStack.elements[nodeStack.count - 1];
                nodeStack.count = nodeStack.count - 1;
            }
            else
            {
                node = ((::Node_d9c520 *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(resolver))->GetEntryOffset(node->unk0C)));
                Node_d9c520* child = node->unk12 != 0x7fff ? ((::Node_d9c520 *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(resolver))->GetEntryOffset(node->unk12))) : 0;
                AllocHolder* holder = FUN_00c85750();
                if (nodeStack.count == (nodeStack.capacity & 0x3fffffff))
                    ::ResizeAudioStream((::AudioAllocator *)(holder->m_pThreadAllocator), (::AudioStream *)(::UnsignedShortArray *)((UnsignedShortArray*)&nodeStack), 4);
                nodeStack.elements[nodeStack.count] = child;
                nodeStack.count = nodeStack.count + 1;
            }
        }
        AllocHolder* holder = FUN_00c85750();
        Allocator* allocator = holder->m_pThreadAllocator;
        int capacity = nodeStack.capacity;
        nodeStack.count = 0;
        if (capacity & 0x80000000)
            return;
        allocator->Free(nodeStack.elements, (capacity & 0x3fffffff) * 4);
    }
}


// @fnv 0x00d9c2d0
void __cdecl FUN_00d9c2d0(int param_1, unsigned short param_2) {
    static_cast<::Owner *>(nullptr)->AppendElement({});
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
#include "fnv/symbols_simd.h"

struct NodeD9C7 {
    char unk00[0x10];
    unsigned short m_usFlags;
};

class FreeListD9C7 {
public:
};

class FUN_00d9c7d0_C {
public:
    char unk00[0x10];
    NodeD9C7* m_pkTreeNode;
    short m_sValue;
    short unk16;
    int m_iArrayLength;
    FreeListD9C7 m_kFreeList;

    void FUN_00d9bb50(NodeD9C7* pkNode, NodeD9C7** ppkOut);
    void FUN_00d9c7d0(NodeD9C7* pkNode);
};

// @fnv 0x00d9c7d0
void FUN_00d9c7d0_C::FUN_00d9c7d0(NodeD9C7* pkNode)
{
    if (!(m_pkTreeNode->m_usFlags & 0x8000)) {
        NodeD9C7* pkOther;
        FUN_00d9bb50(pkNode, &pkOther);
        ::FUN_00d9c2d0((int)&(m_kFreeList), (unsigned short)(pkOther));
    } else {
        m_sValue = 0x7fff;
        m_pkTreeNode = 0;
    }
    ::FUN_00d9c2d0((int)&(m_kFreeList), (unsigned short)(pkNode));
    m_iArrayLength--;
}

#ifndef _INCLUDED_MM2

#endif

struct hkVector4 {
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& o) { m_vComponents = o.m_vComponents; return *this; }
    void set(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
};


struct Range {
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    Range() : m_kPointA(0), m_kPointB(0), m_iThirdValue(0x80000000u) {}
};

struct FUN_00d9c110_cls {
    virtual ~FUN_00d9c110_cls();
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    Range m1c;
    Range m28;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    hkVector4 m40;
    hkVector4 m50;
    hkVector4 m60;
    hkVector4 m70;
    FUN_00d9c110_cls();
};

// @fnv 0x00d9c110
FUN_00d9c110_cls::FUN_00d9c110_cls() {
    m40 = (*reinterpret_cast<::hkVector4 *>(&::DAT_01267e30));
    m50 = (*reinterpret_cast<::hkVector4 *>(&::DAT_01267e30));
    hkVector4 v;
    v.set(1.0f, 1.0f, 1.0f, 0.0f);
    m10 = 0;
    m18 = 0;
    m14 = 0x7fffffffu;
    m60 = v;
    m70 = v;
}


template <class T> struct hkArray_d9c4 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void reserve(int n)
    {
        S_00d9d650_Heap& heap = fnvc_adapt::FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            ::FUN_00c908c0((::SpawnedObject *)&(heap), (::SpawnedArray *)(void *)(this), n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    static void construct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
            new (p + i) T();
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline void pushBackUnchecked(const T& t)
    {
        T* p = &m_data[m_iElementCount];
        __assume(p != 0);
        new (p) T(t);
        m_iElementCount++;
    }
};

struct Handle_d9c4 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int m_pOwnerObject;
    int unk2C;
    Handle_d9c4() { m_pOwnerObject = 0; }
};

struct HandlePool_d9c4 {
    hkArray_d9c4<Handle_d9c4> m_handles;
    hkArray_d9c4<int> m_kFreeListEntries;
    void FUN_00d9c450(int newSize, Handle_d9c4** ppHandle, const int* pIndex);
};

// @fnv 0x00d9c450
void HandlePool_d9c4::FUN_00d9c450(int newSize, Handle_d9c4** ppHandle, const int* pIndex)
{
    int oldSize = m_handles.m_iElementCount;
    m_handles.SetSizeAndGrow(newSize);
    m_kFreeListEntries.reserve(newSize);
    for (int i = newSize - 1; i >= oldSize; i--)
        m_kFreeListEntries.pushBackUnchecked(i);
    if (*pIndex != 0x7fffffff)
        *ppHandle = &m_handles.m_data[*pIndex];
}

struct S_00d9af30_Node {
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
    int unk20;
    int unk24;
    unsigned int m_flags;
    int unk2c;
};
struct S_00d9af30_Pool {
    S_00d9af30_Node* m_pData;
};
struct S_00d9af30 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00d9af30_Pool m_kNodePool;
    void MergeNode(S_00d9af30_Node* n, int a, int b);
};
// Stores b in n->unk2c; for nonleaf nodes, updates child flags, recurses, and combines their bounds into n.
// @fnv 0x00d9af30
void S_00d9af30::MergeNode(S_00d9af30_Node* apNode, int a, int b)
{
    apNode->unk2c = b;
    if ((apNode->m_flags & 0x80000000) == 0) {
        S_00d9af30_Node* pLeft = ((::S_00d9af30_Node *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodePool))->FUN_00d9a4c0(apNode->unk20)));
        S_00d9af30_Node* r = ((::S_00d9af30_Node *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodePool))->FUN_00d9a4c0(apNode->unk24)));
        pLeft->m_flags = (pLeft->m_flags & 0x80000000) | a;
        r->m_flags = (r->m_flags & 0x80000000) | a;
        MergeNode(pLeft, apNode->unk20, apNode->unk24);
        MergeNode(r, apNode->unk24, b);
        apNode->m_kMinimumCorner = _mm_min_ps(pLeft->m_kMinimumCorner, r->m_kMinimumCorner);
        apNode->m_kMaximumCorner = _mm_max_ps(pLeft->m_kMaximumCorner, r->m_kMaximumCorner);
    }
}

struct __declspec(align(16)) Block32 {
    __m128 m00;
    __m128 m10;
};

struct S00d9a4c0_Cls {
};


struct MapD9 {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    S00d9a4c0_Cls m1c;
    void FUN_00d9be50(int key, const Block32* src);
};

// Stores a Block32 value for key, replacing an existing entry or inserting a new one via FUN_00d9afe0.
// @fnv 0x00d9be50
void MapD9::FUN_00d9be50(int key, const Block32* src) {
    if (m14 == key) {
        Block32* out = ((::Block32 *)(reinterpret_cast<::IdxStand_ *>(&(m1c))->FUN_00d9a4c0(key)));
        out->m10 = src->m10;
        out->m00 = src->m00;
        return;
    }
    unsigned int tmp;
    reinterpret_cast<::S00d9b240_Tree *>((key))->FUN_00d9b240((int)(&tmp), {});
    Block32* out = ((::Block32 *)(reinterpret_cast<::IdxStand_ *>(&(m1c))->FUN_00d9a4c0(key)));
    __m128 hi = src->m10;
    __m128 lo = src->m00;
    out->m00 = lo;
    out->m10 = hi;
    reinterpret_cast<::AabbTree *>(this)->FUN_00d9afe0(m14, key, tmp);
}


struct __declspec(align(16)) S_00d9c180_Vec { float x, y, z, w; };

struct S_00d9c180_Arr { int m_data; int m_iElementCount; int m_cap; S_00d9c180_Arr() { m_data = 0; m_iElementCount = 0; m_cap = 0x80000000; } };

struct S_00d9c180_Base
{
    virtual void Reserved0();
};

struct __declspec(align(16)) FUN_00d9c180 : S_00d9c180_Base
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned short unk16;
    int unk18;
    S_00d9c180_Arr unk1C;
    S_00d9c180_Arr unk28;
    int unk34;
    int unk38;
    int unk3C;
    S_00d9c180_Vec unk40;
    S_00d9c180_Vec unk50;
    S_00d9c180_Vec unk60;
    S_00d9c180_Vec unk70;
    FUN_00d9c180(const S_00d9c180_Vec* a, const S_00d9c180_Vec* b, const S_00d9c180_Vec* c);
};

// Copies three input vectors into fields, computes a reciprocal approximation into unk70, and sets unk10 and unk18 to zero and unk14 to 0x7fff.
// @fnv 0x00d9c180
FUN_00d9c180::FUN_00d9c180(const S_00d9c180_Vec* apVecA, const S_00d9c180_Vec* apVecB, const S_00d9c180_Vec* apVecC)
{
    *(__m128*)&unk40 = *(const __m128*)apVecA;
    *(__m128*)&unk50 = *(const __m128*)apVecB;
    *(__m128*)&unk60 = *(const __m128*)apVecC;
    __m128 v = *(const __m128*)apVecC;
    __m128 t = _mm_unpackhi_ps(v, DAT_010c7170);
    __m128 vShuffled = _mm_shuffle_ps(v, t, 0xc4);
    __m128 r = _mm_rcp_ps(vShuffled);
    __m128 r2 = _mm_mul_ps(_mm_mul_ps(r, vShuffled), r);
    *(__m128*)&unk70 = _mm_sub_ps(_mm_add_ps(r, r), r2);
    unk10 = 0;
    unk18 = 0;
    unk14 = 0x7fff;
}


struct TreeDeleteAllocatorD9C2 {
    virtual void First();
    virtual void Second();
    virtual void Deallocate(void* address, unsigned int size);
};

struct TreeDeleteNodeManagerD9C2 {
};

struct TreeDeleteD9C2 {
    const void** m_ppVirtualMethodTable;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    TreeDeleteNodeManagerD9C2 m_kNodeCollection;

    TreeDeleteD9C2* FUN_00d9c2e0(unsigned char flags);
};

// Assigns a global address to a field, calls two member functions, optionally deallocates this when flags bit 0 is set, then returns this.
// @fnv 0x00d9c2e0
TreeDeleteD9C2* TreeDeleteD9C2::FUN_00d9c2e0(unsigned char flags)
{
    m_ppVirtualMethodTable = (*reinterpret_cast<const void * (*)[]>(&::DAT_010d40a4));
    reinterpret_cast<::FUN_00d9be30_class *>(this)->FUN_00d9be30();
    reinterpret_cast<::fnv_00d9c010::FUN_00d9c010_cls *>(&(m_kNodeCollection))->ClearBuffers();
    if (flags & 1) {
        AllocHolder* holder = FUN_00c85750();
        reinterpret_cast<TreeDeleteAllocatorD9C2*>(holder->m_pThreadAllocator)->Deallocate(this, 0x80);
    }
    return this;
}


struct TreeVector4
{
    __m128 m_vComponents;
    __forceinline void setMin4(const TreeVector4& a, const TreeVector4& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMax4(const TreeVector4& a, const TreeVector4& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }
};

struct TreeAabb
{
    TreeVector4 m_kMinimumCorner;
    TreeVector4 m_kMaximumCorner;
    void setUnion(const TreeAabb& a, const TreeAabb& b) { m_kMinimumCorner.m_vComponents = _mm_min_ps(a.m_kMinimumCorner.m_vComponents, b.m_kMinimumCorner.m_vComponents); m_kMaximumCorner.m_vComponents = _mm_max_ps(a.m_kMaximumCorner.m_vComponents, b.m_kMaximumCorner.m_vComponents); }
    bool contains(const TreeAabb& o) const { __m128 a = _mm_cmple_ps(m_kMinimumCorner.m_vComponents, o.m_kMinimumCorner.m_vComponents); __m128 b = _mm_cmple_ps(o.m_kMaximumCorner.m_vComponents, m_kMaximumCorner.m_vComponents); return (_mm_movemask_ps(_mm_and_ps(a, b)) & 7) == 7; }
};
struct TreeNode
{
    TreeAabb m_kBounds;
    int m_children[2];
    unsigned int m_parent;
    int m_next;

    unsigned int isLeaf() const { return m_parent & 0x80000000u; }
    unsigned int getParent() const { return m_parent & 0x7fffffffu; }
    void setParent(unsigned int parent) { m_parent = (m_parent & 0x80000000u) | parent; }
};

struct TreeNodeArray
{
};

struct AabbTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TreeNode* m_pTreeNode;
    int m_rootIndex;
    int unk18;
    TreeNodeArray m_kNodeCollection;

    void FUN_00d9afe0(int root, int leaf, int branch);
};

// @fnv 0x00d9afe0
void AabbTree::FUN_00d9afe0(int root, int leaf, int branch)
{
    TreeNode* leafNode = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(leaf)));
    TreeNode* branchNode = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(branch)));
    TreeAabb volume = leafNode->m_kBounds;
    __m128 center = _mm_add_ps(volume.m_kMinimumCorner.m_vComponents, volume.m_kMaximumCorner.m_vComponents);

    TreeNode* siblingNode = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(root)));
    int sibling = root;
    int side = 0;
    while (!siblingNode->isLeaf())
    {
        TreeNode* child0 = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(siblingNode->m_children[0])));
        TreeNode* child1 = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(siblingNode->m_children[1])));
        __m128 d0 = _mm_sub_ps(_mm_add_ps(child0->m_kBounds.m_kMinimumCorner.m_vComponents, child0->m_kBounds.m_kMaximumCorner.m_vComponents), center);
        __m128 d1 = _mm_sub_ps(_mm_add_ps(child1->m_kBounds.m_kMinimumCorner.m_vComponents, child1->m_kBounds.m_kMaximumCorner.m_vComponents), center);
        __m128 diff = _mm_sub_ps(_mm_mul_ps(d1, d1), _mm_mul_ps(d0, d0));
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(diff, diff, 0x55), diff);
        sum = _mm_add_ss(_mm_shuffle_ps(diff, diff, 0xaa), sum);
        side = (~_mm_movemask_ps(sum)) & 1;
        sibling = siblingNode->m_children[side];
        siblingNode = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(sibling)));
    }

    unsigned int parent = siblingNode->getParent();
    TreeNode* parentNode = (parent != 0x7fffffffu) ? ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(parent))) : 0;

    branchNode->m_kBounds.setUnion(leafNode->m_kBounds, siblingNode->m_kBounds);
    int* children = branchNode->m_children;
    children[0] = sibling;
    children[1] = leaf;
    siblingNode->setParent(branch);
    leafNode->setParent(branch);
    int next = siblingNode->m_next;
    siblingNode->m_next = leaf;
    leafNode->m_next = next;
    branchNode->m_next = next;

    if (parentNode != 0)
    {
        parentNode->m_children[side] = branch;
        branchNode->setParent(parent);
        if (side == 1)
        {
            TreeNode* node = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(parentNode->m_children[0])));
            node->m_next = branch;
            while (!node->isLeaf())
            {
                node = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(node->m_children[1])));
                node->m_next = branch;
            }
        }
        while (parentNode != 0)
        {
            __m128 minIn = _mm_cmpge_ps(volume.m_kMinimumCorner.m_vComponents, parentNode->m_kBounds.m_kMinimumCorner.m_vComponents);
            __m128 maxIn = _mm_cmple_ps(volume.m_kMaximumCorner.m_vComponents, parentNode->m_kBounds.m_kMaximumCorner.m_vComponents);
            if ((_mm_movemask_ps(_mm_and_ps(minIn, maxIn)) & 7) == 7)
            {
                return;
            }
            parentNode->m_kBounds.m_kMinimumCorner.m_vComponents = _mm_min_ps(parentNode->m_kBounds.m_kMinimumCorner.m_vComponents, volume.m_kMinimumCorner.m_vComponents);
            parentNode->m_kBounds.m_kMaximumCorner.m_vComponents = _mm_max_ps(parentNode->m_kBounds.m_kMaximumCorner.m_vComponents, volume.m_kMaximumCorner.m_vComponents);
            unsigned int up = parentNode->getParent();
            if (up == 0x7fffffffu)
            {
                return;
            }
            parentNode = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(up)));
        }
    }
    else
    {
        m_pTreeNode = branchNode;
        branchNode->m_parent |= 0x7fffffffu;
        m_rootIndex = branch;
    }
}

struct S00d9b240_Mask { __m128 mask; unsigned char allXYZ() const {unsigned int m=_mm_movemask_ps(_mm_and_ps(mask,mask))&7;return m==7;} };
struct S00d9b240_Bounds {
 __m128 minimum,maximum;
 void setUnion(const S00d9b240_Bounds& a,const S00d9b240_Bounds& b) {minimum=_mm_min_ps(a.minimum,b.minimum);maximum=_mm_max_ps(a.maximum,b.maximum);}
};
struct S00d9b240_Node : S00d9b240_Bounds {
 int children[2];
 unsigned int parentAndLeaf;
 int escape;
};
struct S00d9b240_Pool {  };
struct S00d9b240_Node;

struct S00d9b240_Tree {
 int unk00,unk04,unk08,unk0c;
 S00d9b240_Node* root;
 int rootIndex,numLeaves;
 S00d9b240_Pool pool;
 S00d9b240_Node* FUN_00d9b240(int leafIndex,int* removedParentIndex);
 S00d9b240_Node* getSibling(const S00d9b240_Node* p,const S00d9b240_Node* c) { S00d9b240_Node* a=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(p->children[0]))); S00d9b240_Node* b=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(p->children[1]))); return (S00d9b240_Node*)((unsigned int)a^(unsigned int)b^(unsigned int)c); }
 int getSiblingIndex(const S00d9b240_Node* p,int c) { return p->children[0]^p->children[1]^c; }
};
// @fnv 0x00d9b240
S00d9b240_Node* S00d9b240_Tree::FUN_00d9b240(int leafIndex,int* removedParentIndex) {
 S00d9b240_Node* leaf=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(leafIndex)));
 unsigned int parentIndex=leaf->parentAndLeaf&0x7fffffffu;
 S00d9b240_Node* __restrict parent=parentIndex!=0x7fffffffu ? ((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(parentIndex))):0;
 unsigned int grandparentIndex=parent->parentAndLeaf&0x7fffffffu;
 S00d9b240_Node* grandparent=grandparentIndex!=0x7fffffffu ? ((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(grandparentIndex))):0;
 const int& firstIndex=parent->children[0];
 int secondIndex=parent->children[1];
 S00d9b240_Node* sibling=(S00d9b240_Node*)((unsigned int)((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(firstIndex)))^(unsigned int)((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(secondIndex))));
 sibling=(S00d9b240_Node*)((unsigned int)sibling^(unsigned int)leaf);
 int siblingIndex=firstIndex^parent->children[1]^leafIndex;
 *removedParentIndex=parentIndex;
 S00d9b240_Node* result;
 if(grandparent) {
  int child=(((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(grandparent->children[1])))==parent);
  grandparent->children[child]=siblingIndex;
  sibling->parentAndLeaf=(sibling->parentAndLeaf&0x80000000u)|grandparentIndex;
  result=root;
  if(child==1) {
   S00d9b240_Node* cursor=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(grandparent->children[0])));
   for(;;) {
    cursor->escape=siblingIndex;
    if(cursor->parentAndLeaf&0x80000000u) break;
    cursor=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(cursor->children[1])));
   }
  }
  while(grandparent) {
   S00d9b240_Node* right=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(grandparent->children[1])));
   S00d9b240_Node* left=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(grandparent->children[0])));
   S00d9b240_Bounds merged;
   merged.setUnion(*left,*right);
   S00d9b240_Mask equal;equal.mask=_mm_cmpeq_ps(grandparent->maximum,merged.maximum);
   if(equal.allXYZ()) {result=grandparent;break;}
   grandparent->minimum=merged.minimum;
   grandparent->maximum=merged.maximum;
   unsigned int next=grandparent->parentAndLeaf&0x7fffffffu;
   grandparent=next!=0x7fffffffu ? ((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(next))):0;
  }
 } else {
  root=sibling;
  sibling->parentAndLeaf|=0x7fffffffu;
  result=root;
  rootIndex=siblingIndex;
 }
 S00d9b240_Node* __restrict tailParent=parent;
 if(((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(tailParent->children[0])))==sibling) {
  int escape=tailParent->escape;
  S00d9b240_Node* cursor=sibling;
  for(;;) {
   cursor->escape=escape;
   if(cursor->parentAndLeaf&0x80000000u) break;
   cursor=((::S00d9b240_Node *)(reinterpret_cast<::IdxStand_ *>(&(pool))->FUN_00d9a4c0(cursor->children[1])));
  }
 }
 return result;
}

struct Aabb {
    Vec4 lo;
    Vec4 hi;
};

struct Rec {
    Vec4 lo;
    Vec4 hi;
    int f20;
    int f24;
    int f28;
    int f2c;
};

struct Sub {
    int unk00;
    int unk04;
    int* m_pStackBuffer;
    int m_uiItemCount;
    int push(Rec** a1, int* a2, const Rec& r);
};

struct Outer {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Rec* m_10;
    int m_14;
    int m_18;
    Sub m_1c;
    int FUN_00d9d110(const Aabb* box, int arg2);
};

// @fnv 0x00d9d110
int Outer::FUN_00d9d110(const Aabb* box, int arg2) {
    Rec rec;
    rec.hi = box->hi;
    rec.lo = box->lo;
    rec.f20 = arg2;
    rec.f28 = 0x80000000;

    int idx = reinterpret_cast<::ElemPool *>(&(m_1c))->AllocElem((int)(&m_10), (int)(&m_14), (const ::Elem &)(rec));
    if (m_14 == 0x7fffffff) {
        Rec* p = ((::Rec *)(reinterpret_cast<::IdxStand_ *>(&(m_1c))->FUN_00d9a4c0(idx)));
        p->f28 |= 0x7fffffff;
        p->f2c = 0x7fffffff;
        m_10 = p;
        m_14 = idx;
    } else {
        int out;
        reinterpret_cast<::FUN_00d9ce00_Class *>(&(m_1c))->PopItem((int)(&m_10), (int)(&m_14), &out);
        reinterpret_cast<::AabbTree *>(this)->FUN_00d9afe0(m_14, idx, out);
    }
    m_18++;
    return idx;
}

struct S00d9bb50_Aabb {
    S00d9bb50_Aabb() {}
    unsigned short min[3];
    unsigned short max[3];
    bool equals(const S00d9bb50_Aabb& o) const {
        for (int i = 0; i < 3; ++i) {
            if (max[i] != o.max[i] || min[i] != o.min[i])
                return false;
        }
        return true;
    }
};

inline unsigned short s00d9bb50_min(const unsigned short& a, const unsigned short& b) { return b < a ? b : a; }
inline unsigned short s00d9bb50_max(const unsigned short& a, const unsigned short& b) { return b > a ? b : a; }

template<class B, class I> struct CurrentTree {
    struct Node {
        B aabb;
        I child[2];
        I parent, next;
        static const I mask = I(~0) >> 1;
        I parentIndex() const { return parent & mask; }
        I childIndex(int side) const { return child[side]; }
    };
    struct Pool {
        Node* nodes;
        int count, capacity;
        __declspec(noinline) Node* GetEntryOffset(I i);
        __declspec(noinline) const Node* GetEntryOffset(I i) const;
        Node* get(I i) { return i != Node::mask ? GetEntryOffset(i) : 0; }
    };
    int m00,m04,m08,m0c;
    Node* m_pTreeNode;
    I m_usManagerValue,m16;
    int m18;
    Pool m_kNodePool;
    __forceinline Node* parentOf(const Node* n) const {
        return (n->parent & Node::mask) != Node::mask ? const_cast<Node*>(((const ::CurrentTree< ::S00d9bb50_Aabb, unsigned short>::Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>((void *)(((const Pool*)&m_kNodePool)))->GetEntryOffset(n->parent & Node::mask)))) : 0;
    }
    __forceinline Node* childOf(const Node* n, int i) const { return const_cast<Node*>(((const ::CurrentTree< ::S00d9bb50_Aabb, unsigned short>::Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>((void *)(((const Pool*)&m_kNodePool)))->GetEntryOffset(n->child[i])))); }
    Node* FUN_00d9bb50(I leafIdx, I* outParent);
};
template<class B,class I> typename CurrentTree<B,I>::Node* CurrentTree<B,I>::Pool::GetEntryOffset(I i) { return &nodes[i]; }
template<class B,class I> const typename CurrentTree<B,I>::Node* CurrentTree<B,I>::Pool::GetEntryOffset(I i) const { return &nodes[i]; }

// @fnv 0x00d9bb50
template<class B,class I> typename CurrentTree<B,I>::Node* CurrentTree<B,I>::FUN_00d9bb50(I leafIdx,I* outParent)
{
    Pool* pool = &m_kNodePool;
    Node* leaf = ((::CurrentTree< ::S00d9bb50_Aabb, unsigned short>::Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>((pool))->GetEntryOffset(leafIdx)));
    Node* parent = parentOf(leaf);
    Node* prev = parentOf(parent);
    I prevIdx = parent->parentIndex();
    Node* sib = (Node*)((unsigned int)childOf(parent, 0) ^ (unsigned int)childOf(parent, 1) ^ (unsigned int)leaf);
    I sibIdx = parent->childIndex(0) ^ parent->childIndex(1) ^ leafIdx;
    *outParent = leaf->parentIndex();
    Node* root;
    if (prev) {
        int which = childOf(prev, 1) == parent;
        prev->child[which] = sibIdx;
        sib->parent = (sib->parent & 0x8000) | prevIdx;
        root = m_pTreeNode;
        if (which == 1) {
            Node* n = childOf(prev, 0);
            n->next = sibIdx;
            while (!(n->parent & 0x8000)) {
                n = childOf(n, 1);
                n->next = sibIdx;
            }
        }
        do {
            Node* r = childOf(prev, 1);
            Node* l = childOf(prev, 0);
            S00d9bb50_Aabb nb;
            for (int k = 0; k < 3; ++k) {
                nb.max[k] = s00d9bb50_min(r->aabb.max[k], l->aabb.max[k]);
                nb.min[k] = s00d9bb50_max(r->aabb.min[k], l->aabb.min[k]);
            }
            if (prev->aabb.equals(nb)) {
                root = prev;
                break;
            }
            prev->aabb = nb;
            prev = (prev->parent & Node::mask) != Node::mask ? ((::CurrentTree< ::S00d9bb50_Aabb, unsigned short>::Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>((pool))->GetEntryOffset(prev->parent & Node::mask))) : 0;
        } while (prev);
    } else {
        m_pTreeNode = sib;
        sib->parent |= Node::mask;
        m_usManagerValue = sibIdx;
        root = m_pTreeNode;
    }
done:
    if (childOf(parent, 0) == sib) {
        unsigned short nx = parent->next;
        Node* n = sib;
        for (;;) {
            n->next = nx;
            if (n->parent & 0x8000)
                break;
            n = childOf(n, 1);
        }
    }
    return root;
}

template CurrentTree<S00d9bb50_Aabb,unsigned short>::Node* CurrentTree<S00d9bb50_Aabb,unsigned short>::FUN_00d9bb50(unsigned short,unsigned short*);


   // 0x011b6d70: 2147352576.0f x4
     // 0x01267e30

struct TreeHeap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct TreeRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TreeHeap* m_pStreamAllocator;
    TreeHeap& heap() { return *m_pStreamAllocator; }
};


__forceinline TreeRouter& GetTreeRouter() { return *(TreeRouter*)FUN_00c85750(); }

template <typename T>
struct TreeArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline TreeArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~TreeArray() { _clearAndDeallocate(GetTreeRouter().heap()); }

    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    __forceinline void _clearAndDeallocate(TreeHeap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(TreeHeap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(GetTreeRouter().heap(), n);
        m_iElementCount = n;
    }
};

struct TreeVec4 {
    __m128 m_vComponents;
    __forceinline float getComponent(int i) const { return fnv_simd_as<float>(m_vComponents)[i]; }
};

struct TreeAabb16 {
    unsigned short m_kMinimumCorner[3];
    unsigned short m_kMaximumCorner[3];
};

struct TreeNode16 {
    TreeAabb16 m_kBounds;
    int m_key;
    unsigned short m_parent;
    unsigned short m_pChildAtom;

    __forceinline void setLeaf(int key)
    {
        m_key = key;
        m_parent |= 0x8000;
    }
};

struct TreeNodePool {
};

struct AabbTree16 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TreeNode16* m_kNodeCollection;
    unsigned short m_pTreeNode;
    unsigned short unk16;
    int m_iNodeCount;
    TreeNodePool m_kNodePool;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    __m128 m_kVectorAt50;
    __m128 m_kVectorAt40;
    __m128 m_vScale;


    __forceinline void convertAabb(const TreeAabb& in, TreeAabb16& out)
    {
        TreeVec4 maxVal;
        maxVal.m_vComponents = ::DAT_011b6d70;
        TreeVec4 hi;
        hi.m_vComponents = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(m_kVectorAt50, in.m_kMinimumCorner.m_vComponents), m_vScale), maxVal.m_vComponents), (*reinterpret_cast<::__m128 *>(&::DAT_01267e30)));
        int hi0 = fnv_FloatToInt(hi.getComponent(0));
        int hi1 = fnv_FloatToInt(hi.getComponent(1));
        int hi2 = fnv_FloatToInt(hi.getComponent(2));
        int hi3 = fnv_FloatToInt(hi.getComponent(3));

        TreeVec4 lo;
        lo.m_vComponents = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(in.m_kMaximumCorner.m_vComponents, m_kVectorAt40), m_vScale), maxVal.m_vComponents), (*reinterpret_cast<::__m128 *>(&::DAT_01267e30)));
        int lo0 = fnv_FloatToInt(lo.getComponent(0));
        int lo1 = fnv_FloatToInt(lo.getComponent(1));
        int lo2 = fnv_FloatToInt(lo.getComponent(2));
        int lo3 = fnv_FloatToInt(lo.getComponent(3));

        out.m_kMinimumCorner[0] = (unsigned short)((unsigned int)lo0 >> 15);
        out.m_kMaximumCorner[0] = (unsigned short)((unsigned int)hi0 >> 15);
        out.m_kMinimumCorner[1] = (unsigned short)((unsigned int)lo1 >> 15);
        out.m_kMaximumCorner[1] = (unsigned short)((unsigned int)hi1 >> 15);
        out.m_kMinimumCorner[2] = (unsigned short)((unsigned int)lo2 >> 15);
        out.m_kMaximumCorner[2] = (unsigned short)((unsigned int)hi2 >> 15);
    }

    void FUN_00d9ce50(const TreeAabb* aabbs, const int* keys, int n, TreeArray<unsigned short>* out) throw();
};

namespace Simd840 {

}
typedef __m128 NativeSimd840;
extern "C" {
void _ReadWriteBarrier();
}
__forceinline void copyCount840(int* a,const int* b){_ReadWriteBarrier();*a=*b;}
struct Vector840 {
 union { NativeSimd840 q; struct { float x,y,z,w; }; };
 void operator=(const Vector840& other) { q=other.q; }
 __forceinline void set(float a,float b,float c,float d=0.0f) { q=_mm_setr_ps(a,b,c,d); }
 void broadcast(float a) { q=_mm_set_ps1(a); }
};

struct Bounds840 { Vector840 minimum, maximum; void operator=(const Bounds840& other) { minimum=other.minimum; _ReadWriteBarrier(); maximum=other.maximum;  } };
struct Source840 {
 unsigned short minimum[3],maximum[3];
 __forceinline void center(Vector840& result) const {
  Vector840 low;
  low.set((float)minimum[0],(float)minimum[1],(float)minimum[2]);
  result.set((float)maximum[0],(float)maximum[1],(float)maximum[2]);
  result.q=_mm_mul_ps(_mm_add_ps(result.q,low.q),_mm_set_ps1(::fnv_00c88020::DAT_01016248));
 }
};
struct Node840 { int unk00,unk04,unk08; union { int key; unsigned short children[2]; }; unsigned short flags,escape; };
struct ParentAlias840 {Node840* value;};
struct Task840 {
    static __forceinline void* operator new(std::size_t, void* destination) { return destination; }
    Bounds840 bounds;
    unsigned short start,unused22;
    int count;
    Node840* node;
    int unused2c;
};
struct Words840 { unsigned short* data; int count; unsigned int capacity; };
struct Tasks840 {
    Task840* data;
    int count;
    unsigned int capacity;
    Task840 local[64];
};
struct Manager840 {
    Node840* GetEntryOffset(unsigned short index);
};
struct Tree840 {
    int unk00,unk04,unk08,unk0c;
    Node840* root;
    int rootIndex,numLeaves;
    Manager840 manager;
    __forceinline Node840* allocate(int& index) { return ((::Node840 *)(reinterpret_cast<::fnv_00d9c280::FUN_00d9c280_cls *>(&(manager))->PopGlyphRecord((int *)(::Node840 **)(&root),(unsigned short *)(int *)(&rootIndex),(unsigned short *)(int *)(&index)))); }
    __forceinline Node840* lookup(unsigned short index) { return ((::Node840 *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(manager))->GetEntryOffset(index))); }
    void FUN_00d9c840(const Source840* source,const int* keys,int count,Node840* rootNode,Words840& mapping,unsigned char reuse);
};
// @fnv 0x00d9ce50
void AabbTree16::FUN_00d9ce50(const TreeAabb* aabbs, const int* keys, int n, TreeArray<unsigned short>* out) throw()
{
    m_iNodeCount = n;
    if (n == 0)
    {
        return;
    }

    out->SetSizeAndGrow(n);
    reinterpret_cast<::FUN_00d9bf30_cls *>(&(m_kNodePool))->AllocateRecords(n + n - 1, (::S_d9bf30_Rec **)(::TreeNode16 **)(&m_kNodeCollection), &m_pTreeNode);
    m_kNodeCollection = ((::TreeNode16 *)(reinterpret_cast<::fnv_00d9c280::FUN_00d9c280_cls *>(&(m_kNodePool))->PopGlyphRecord((int *)(::TreeNode16 **)(&m_kNodeCollection), &m_pTreeNode, &m_pTreeNode)));
    m_kNodeCollection->m_parent |= 0x7fff;

    TreeArray<TreeAabb16> aabbs16;
    aabbs16.SetSizeAndGrow(n);
    for (int i = 0; i < n; i++)
    {
        convertAabb(aabbs[i], aabbs16.m_data[i]);
    }

    if (n == 1)
    {
        m_kNodeCollection->setLeaf(keys[0]);
        m_kNodeCollection->m_pChildAtom = 0x7fff;
        m_kNodeCollection->m_kBounds = aabbs16.m_data[0];
        out->m_data[0] = m_pTreeNode;
    }
    else
    {
        reinterpret_cast<::Tree840 *>(this)->FUN_00d9c840((const ::Source840 *)(aabbs16.m_data), keys, n, (::Node840 *)(m_kNodeCollection), (*(::Words840 *)(out)), 0);
    }

    reinterpret_cast<::FUN_00d9b450_cls *>(this)->UpdateBoundsNode((::BoundsNode *)(m_kNodeCollection), m_pTreeNode, 0x7fff);
    reinterpret_cast<::Pool_d9c520 *>(this)->TraverseNodeTree((::Node_d9c520 *)(m_kNodeCollection), 0);
}
// @fnv 0x00d9c840
void Tree840::FUN_00d9c840(const Source840* source,const int* keys,int count,Node840* rootNode,Words840& mapping,unsigned char reuse) {
    Words840 indices;
    indices.data=0;
    indices.count=0;
    indices.capacity=0x80000000;
    AllocHolder* holder=FUN_00c85750();
    Allocator* heap=holder->m_pThreadAllocator;
    int capacity=indices.capacity&0x3fffffff;
    if(capacity<count) {
        int newSize=capacity*2;
        if(count>=newSize) newSize=count;
        ::FUN_00c908c0((::SpawnedObject *)(heap),(::SpawnedArray *)(void **)((void**)&indices.data),newSize,2);
    }
    indices.count=count;
    for(int i=0;i<count;++i) indices.data[i]=(unsigned short)i;
    Tasks840 tasks;
    tasks.data=tasks.local;
    tasks.capacity=0x80000040;
    Vector840 minBounds,maxBounds;
    minBounds.broadcast(::DAT_0104da48);
    maxBounds.broadcast(::DAT_0104e148);
    for(int i=0;i<count;++i) {
        Vector840 center;
        source[i].center(center);
        minBounds.q=_mm_min_ps(minBounds.q,center.q);
        maxBounds.q=_mm_max_ps(maxBounds.q,center.q);
    }
    tasks.count=1;
    tasks.local[0].start=0;
    tasks.local[0].count=count;
    tasks.local[0].bounds.minimum.q=minBounds.q;
    tasks.local[0].bounds.maximum.q=maxBounds.q;
    tasks.local[0].node=rootNode;
    do {
        Task840 current=tasks.data[tasks.count-1];
        --tasks.count;
        if(current.count<=2) {
            int first=current.start*2;
            unsigned short* cursor=current.node->children;
            for(int i=2;i!=0;--i) {
                int sourceIndex=*(unsigned short*)((char*)indices.data+first);
                int outputIndex;
                int nodeIndex;
                Node840* node;
                if(reuse) {
                    nodeIndex=outputIndex=mapping.data[sourceIndex];
                    node=lookup((unsigned short)nodeIndex);
                } else {
                    node=allocate(outputIndex); nodeIndex=outputIndex;
                }
                mapping.data[sourceIndex]=(unsigned short)nodeIndex;
                const int* data=(const int*)&source[sourceIndex];
                node->unk00=data[0];
                node->unk04=data[1];
                node->unk08=data[2];
                node->key=keys[sourceIndex];
                node->flags|=0x8000;
                *cursor++=(unsigned short)nodeIndex;
                first+=2;
            }
        } else {
            Bounds840 bounds[2];
            int sizes[2];
            ::FUN_00d9a850((*(const ::PartitionBounds *)(&current)),(const ::PartitionQuantizedBounds *)(source),(*(::PartitionIndices *)(&indices)),current.start,current.count,(*(::PartitionBounds *)(&bounds[0])),(*(::PartitionBounds *)(&bounds[1])),(*(int *)(&sizes[0])),(*(int *)(&sizes[1])));
            Task840 children[2];
            int i=0;
            int start=0;
            __declspec(align(16)) Bounds840* boundsCursor=bounds;
            ParentAlias840 parent;parent.value=current.node;

            for(;i<2;++i) {
                int outputIndex;
                int nodeIndex;
                if(sizes[i]>1) {
                    Node840* node=allocate(outputIndex); nodeIndex=outputIndex;
                    children[i].node=node;
                    int copied=sizes[i];copyCount840(&children[i].count,&copied);
                    children[i].bounds=*boundsCursor;
                    children[i].start=(unsigned short)(current.start+i*sizes[0]);
                } else {
                    int sourceIndex=indices.data[current.start+start];
                    Node840* node;
                    if(reuse) {
                        nodeIndex=outputIndex=mapping.data[sourceIndex];
                        node=lookup((unsigned short)nodeIndex);
                    } else {
                        node=allocate(outputIndex); nodeIndex=outputIndex;
                    }
                    const int* data=(const int*)&source[sourceIndex];
                    node->unk00=data[0];
                    node->unk04=data[1];
                    node->unk08=data[2];
                    node->key=keys[sourceIndex];
                    node->flags|=0x8000;
                    mapping.data[sourceIndex]=(unsigned short)nodeIndex;
                }
                ++boundsCursor;
                start+=sizes[0];
                parent.value->children[i]=(unsigned short)nodeIndex;
            }
            for(int i=1;i>=0;--i) {
                if(sizes[i]>1) {
                    AllocHolder* holder=FUN_00c85750();
                    Allocator* allocator=holder->m_pThreadAllocator;
                    if(tasks.count==(int)(tasks.capacity&0x3fffffff))
                        ::ResizeAudioStream((::AudioAllocator *)(allocator),(::AudioStream *)(::UnsignedShortArray *)((UnsignedShortArray*)&tasks),48);
                    Task840* dest=&tasks.data[tasks.count];
                    new(dest) Task840(children[i]);
                    ++tasks.count;
                }
            }
        }
    } while(tasks.count);
    AllocHolder* taskHolder=FUN_00c85750();
    Allocator* taskHeap=taskHolder->m_pThreadAllocator;
    tasks.count=0;
    if((tasks.capacity&0x80000000)==0) taskHeap->Free(tasks.data,(tasks.capacity&0x3fffffff)*48);
    tasks.data=0;
    tasks.capacity=0x80000000;
    AllocHolder* wordHolder=FUN_00c85750();
    Allocator* wordHeap=wordHolder->m_pThreadAllocator;
    indices.count=0;
    if((indices.capacity&0x80000000)==0) wordHeap->Free(indices.data,(indices.capacity&0x3fffffff)*2);
    indices.data=0;
    indices.capacity=0x80000000;
}
void __cdecl ResizeAudioStream(void* memory, UnsignedShortArray* buffer, unsigned int count);
void __cdecl FUN_00c908c0(Allocator* allocator, void** data, unsigned int capacity, unsigned int elemSize);
void __cdecl FUN_00c908c0(S_00d9d650_Heap& alloc, void* array, int reqCapacity, int sizeElem);
void __cdecl FUN_00c908c0(TreeHeap& alloc, void* array, int reqCapacity, int sizeElem) throw();


class Sd9_SimdReal
{
public:
    __forceinline Sd9_SimdReal(const __m128& x) : m_vValue(x) {}
    __forceinline Sd9_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return m_vValue; }
private:
    __m128 m_vValue;
};

class Sd9_Vector4
{
public:
    __forceinline void set(float a, float b, float c, float d = 0.0f) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline void add4(const Sd9_Vector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void sub4(const Sd9_Vector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(const Sd9_Vector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(const Sd9_SimdReal& s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline Sd9_SimdReal horizontalAdd3() const
    {
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    __m128 m_vComponents;
};

template <typename T> __forceinline T Sd9_max2(T x, T y) { return x > y ? x : y; }
template <typename T> __forceinline T Sd9_min2(T x, T y) { return x < y ? x : y; }
__forceinline int Sd9_isNegative(const Sd9_SimdReal& r0) { return _mm_movemask_ps(r0.getQuad()) & 1; }

class Sd9_Bool
{
public:
    __forceinline Sd9_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
private:
    char m_cBooleanValue;
};

struct Sd9_Aabb16
{
    struct Metric
    {
        Sd9_Vector4 m_kCenterPosition;
        __forceinline int select(const Sd9_Aabb16& a, const Sd9_Aabb16& b) const;
    };
    __forceinline Metric getMetric() const;
    __forceinline void center(Sd9_Vector4& centerOut) const;
    __forceinline static void combine(const Sd9_Aabb16& a, const Sd9_Aabb16& b, Sd9_Aabb16& out);
    __forceinline Sd9_Bool contains(const Sd9_Aabb16& other) const;
    __forceinline void includeAabb(const Sd9_Aabb16& aabb);

    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];
};

__forceinline int Sd9_Aabb16::Metric::select(const Sd9_Aabb16& a, const Sd9_Aabb16& b) const
{
    Sd9_Vector4 centerA; a.center(centerA);
    Sd9_Vector4 centerB; b.center(centerB);
    centerA.sub4(m_kCenterPosition);
    centerB.sub4(m_kCenterPosition);
    centerA.mul4(centerA);
    centerB.mul4(centerB);
    centerB.sub4(centerA);
    int index = Sd9_isNegative(centerB.horizontalAdd3());
    return index;
}

__forceinline Sd9_Aabb16::Metric Sd9_Aabb16::getMetric() const
{
    Metric metric;
    center(metric.m_kCenterPosition);
    return metric;
}

__forceinline void Sd9_Aabb16::center(Sd9_Vector4& centerOut) const
{
    centerOut.set(m_kMaximumCorner[0], m_kMaximumCorner[1], m_kMaximumCorner[2]);
    Sd9_Vector4 myMin;
    myMin.set(m_kMinimumCorner[0], m_kMinimumCorner[1], m_kMinimumCorner[2]);
    centerOut.add4(myMin);
    centerOut.mul4(0.5f);
}

__forceinline void Sd9_Aabb16::combine(const Sd9_Aabb16& a, const Sd9_Aabb16& b, Sd9_Aabb16& out)
{
    for (int i = 0; i < 3; i++)
    {
        out.m_kMinimumCorner[i] = Sd9_min2(a.m_kMinimumCorner[i], b.m_kMinimumCorner[i]);
        out.m_kMaximumCorner[i] = Sd9_max2(a.m_kMaximumCorner[i], b.m_kMaximumCorner[i]);
    }
}

__forceinline Sd9_Bool Sd9_Aabb16::contains(const Sd9_Aabb16& other) const
{
    bool outside = false;
    for (int i = 0; i < 3; i++)
    {
        outside |= (m_kMaximumCorner[i] < other.m_kMaximumCorner[i] || other.m_kMinimumCorner[i] < m_kMinimumCorner[i]);
    }
    return !outside;
}

__forceinline void Sd9_Aabb16::includeAabb(const Sd9_Aabb16& aabb)
{
    combine(*this, aabb, *this);
}

struct Sd9_Node
{
    static const unsigned short s_leafMask = 0x7fff;
    static const unsigned short s_leafFlag = 0x8000;

    Sd9_Aabb16 m_iBufferSize;
    union
    {
        struct { unsigned short m_ausChildIndices[2]; } m_kChildIndices;
        struct { void* m_ulUserData; } m_kLeafData;
    };
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;

    unsigned short getParentIdx() const { return m_usNodeValue & s_leafMask; }
    unsigned short getSkipNodeIdx() const { return m_iSkipNodeIndex; }
    unsigned short getChildIdx(int i) const { return m_kChildIndices.m_ausChildIndices[i]; }
    void setSkipNodeIdx(unsigned short idx) { m_iSkipNodeIndex = idx; }
    void setParentNodeIdx(unsigned short idx) { m_usNodeValue = idx | (m_usNodeValue & s_leafFlag); }
    void setChildIdx(int iChild, unsigned short idx) { m_kChildIndices.m_ausChildIndices[iChild] = idx; }
    int isLeaf() const { return m_usNodeValue & s_leafFlag; }
};

struct Sd9_NodeManager
{
    Sd9_Node* m_data;
    int m_iElementCount;
    int m_pRayCursor;
    Sd9_Node* GetEntryOffset(unsigned short idx);
    const Sd9_Node* GetEntryOffset(unsigned short idx) const;
};

struct Sd9_Tree
{
    static const unsigned short s_invalidIdx = 0x7fff;
    typedef Sd9_Node Node;

    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    Node* m_pAabbRootNode;
    unsigned short m_usManagerValue;
    int m_iNodeCount;
    Sd9_NodeManager m_kNodeManager;

    __forceinline Node* getChild(const Node* node, int i) const
    {
        return const_cast<Node*>(((const ::Sd9_Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>((void *)&(m_kNodeManager))->GetEntryOffset(node->m_kChildIndices.m_ausChildIndices[i]))));
    }
    __forceinline Node* getParent(const Node* node) const
    {
        return ((node->m_usNodeValue & Node::s_leafMask) != s_invalidIdx) ?
            const_cast<Node*>(((const ::Sd9_Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>((void *)&(m_kNodeManager))->GetEntryOffset(node->m_usNodeValue & Node::s_leafMask)))) : 0;
    }

    void FUN_00d9b580(unsigned short insertPointIdx, unsigned short newLeafIdx, unsigned short scratchNodeIdx);
};

// @fnv 0x00d9b580
void Sd9_Tree::FUN_00d9b580(unsigned short insertPointIdx, unsigned short newLeafIdx, unsigned short scratchNodeIdx)
{
    Node* insertPoint = ((::Sd9_Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(m_kNodeManager))->GetEntryOffset(insertPointIdx)));
    Node* newLeaf = ((::Sd9_Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(m_kNodeManager))->GetEntryOffset(newLeafIdx)));
    Node* scratch = ((::Sd9_Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(m_kNodeManager))->GetEntryOffset(scratchNodeIdx)));

    Sd9_Aabb16 volume = newLeaf->m_iBufferSize;
    Sd9_Aabb16::Metric metric = volume.getMetric();

    Node* cur = insertPoint;
    unsigned short curIdx = insertPointIdx;
    int index = 0;
    while (!cur->isLeaf())
    {
        Node* a = getChild(cur, 0);
        Node* b = getChild(cur, 1);
        index = metric.select(a->m_iBufferSize, b->m_iBufferSize);
        curIdx = cur->getChildIdx(index);
        cur = getChild(cur, index);
    }

    Node* parent = getParent(cur);
    unsigned short parentIdx = cur->getParentIdx();

    Sd9_Aabb16::combine(newLeaf->m_iBufferSize, cur->m_iBufferSize, scratch->m_iBufferSize);
    scratch->setChildIdx(0, curIdx);
    scratch->setChildIdx(1, newLeafIdx);
    cur->setParentNodeIdx(scratchNodeIdx);
    newLeaf->setParentNodeIdx(scratchNodeIdx);

    unsigned short skipIdx = cur->getSkipNodeIdx();
    cur->setSkipNodeIdx(newLeafIdx);
    newLeaf->setSkipNodeIdx(skipIdx);
    scratch->setSkipNodeIdx(skipIdx);

    if (parent)
    {
        parent->setChildIdx(index, scratchNodeIdx);
        scratch->setParentNodeIdx(parentIdx);
        if (index == 1)
        {
            Node* n = getChild(parent, 0);
            while (1)
            {
                n->setSkipNodeIdx(scratchNodeIdx);
                if (n->isLeaf())
                {
                    break;
                }
                n = getChild(n, 1);
            }
        }
        do
        {
            if (parent->m_iBufferSize.contains(volume))
            {
                break;
            }
            parent->m_iBufferSize.includeAabb(volume);
            parent = getParent(parent);
        } while (parent);
    }
    else
    {
        m_pAabbRootNode = scratch;
        m_pAabbRootNode->setParentNodeIdx(s_invalidIdx);
        m_usManagerValue = scratchNodeIdx;
    }
}


void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

struct BuildVector4
{
    __m128 m_vComponents;
    void operator=(const BuildVector4& v) { m_vComponents = v.m_vComponents; }
};

struct BuildAabb
{
    BuildVector4 m_kMinimumCorner;
    BuildVector4 m_kMaximumCorner;
};

struct BuildTreeNode
{
    BuildAabb m_kBounds;
    int m_children[2];
    unsigned int m_parent;
    int m_next;

    void setLeaf(int key)
    {
        m_children[0] = key;
        m_parent |= 0x80000000;
    }
};

template <typename T>
struct BuildArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    BuildArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    BuildArray(T* data, int flags) : m_data(data), m_iCapacityState(flags) {}
    __forceinline ~BuildArray() { _clearAndDeallocate(fnvc_adapt::FUN_00c85750().heap()); }

    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    T& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }

    __forceinline void _clearAndDeallocate(S_00d9d650_Heap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00d9d650_Heap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(fnvc_adapt::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
    __forceinline T& expandOneUnchecked()
    {
        return m_data[m_iElementCount++];
    }
    __forceinline void AddBack(const T& t)
    {
        S_00d9d650_Heap& alloc = fnvc_adapt::FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

struct BuildWorkItem
{
    BuildAabb m_kBounds;
    int m_kRayStart;
    int m_uiItemCount;
    BuildTreeNode* m_node;
};

template <typename T, int N>
struct BuildInplaceArray : public BuildArray<T>
{
    T m_kStorage[N];

    BuildInplaceArray() : BuildArray<T>(m_kStorage, N | 0x80000000)
    {
        this->m_data = m_kStorage;

        this->m_iCapacityState = N | 0x80000000;
    }
};

struct BuildNodePool
{
};

void __cdecl FUN_00d9a520(const BuildAabb* item, const BuildAabb* aabbs, BuildArray<int>* indices, int start, int count,
                          BuildAabb* leftAabb, BuildAabb* rightAabb, int* numLeft, int* numRight);
struct BuildAabb;
struct BuildTreeNode;
template <class> struct BuildArray;


struct BuildTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BuildTreeNode* m_pTreeNode;
    int m_rootIndex;
    int unk18;
    BuildNodePool m_kNodeCollection;

    void FUN_00d9d1c0(const BuildAabb* aabbs, const int* keys, int numAabbs, BuildTreeNode* root, BuildArray<int>& nodeIndices, bool reuseNodes);
};

static __forceinline __m128 centerOf(const BuildAabb& b)
{
    __m128 half = _mm_load_ss(&::fnv_00c88020::DAT_01016248);
    return _mm_mul_ps(_mm_add_ps(b.m_kMinimumCorner.m_vComponents,b.m_kMaximumCorner.m_vComponents), _mm_shuffle_ps(half,half,0));
}
static __forceinline void includeCenter(BuildAabb& b,__m128 p)
{
    b.m_kMinimumCorner.m_vComponents = _mm_min_ps(b.m_kMinimumCorner.m_vComponents,p);
    b.m_kMaximumCorner.m_vComponents = _mm_max_ps(b.m_kMaximumCorner.m_vComponents,p);
}
__declspec(noinline) void __cdecl FUN_00d9a520(const BuildAabb* item, const BuildAabb* aabbs, BuildArray<int>* indices, int start, int count,
                          BuildAabb* leftAabb, BuildAabb* rightAabb, int* numLeft, int* numRight)
{
    leftAabb->m_kMinimumCorner.m_vComponents = rightAabb->m_kMinimumCorner.m_vComponents = _mm_set_ps1(3.40282e+38f);
    leftAabb->m_kMaximumCorner.m_vComponents = rightAabb->m_kMaximumCorner.m_vComponents = _mm_set_ps1(-3.40282e+38f);
    __m128 sum = _mm_add_ps(item->m_kMaximumCorner.m_vComponents,item->m_kMinimumCorner.m_vComponents);
    float extent[4];
    _mm_store_ps(extent,_mm_sub_ps(item->m_kMaximumCorner.m_vComponents,item->m_kMinimumCorner.m_vComponents));
    int axis = extent[0] > extent[1] ? 0 : 1;
    if(extent[2] > extent[axis]) axis=2;
    float s[4]; _mm_store_ps(s,sum);
    float mid=s[axis]*0.5f;
    int cut;
    if(extent[axis]*0.5f > 2.384185791015625e-7) {
        int l=start;
        int r=start+count-1;
        do {
            for(;;) {
                __m128 center=centerOf(aabbs[(*indices)[l]]);
                float c[4]; _mm_store_ps(c,center);
                if(c[axis]>mid) break;
                ++l; includeCenter(*leftAabb,center);
            }
            for(;;) {
                __m128 center=centerOf(aabbs[(*indices)[r]]);
                float c[4]; _mm_store_ps(c,center);
                if(c[axis]<=mid) break;
                --r; includeCenter(*rightAabb,center);
            }
            if(l>=r) break;
            int t=(*indices)[l]; (*indices)[l]=(*indices)[r]; (*indices)[r]=t;
            includeCenter(*leftAabb,centerOf(aabbs[(*indices)[l]]));
            includeCenter(*rightAabb,centerOf(aabbs[(*indices)[r]]));
            ++l; --r;
        } while(l<=r);
        cut=l;
    } else {
        cut=start+count/2;
        *leftAabb=*item;
        *rightAabb=*item;
    }
    *numLeft=cut-start;
    *numRight=count-*numLeft;
}

// @fnv 0x00d9d1c0
void BuildTree::FUN_00d9d1c0(const BuildAabb* aabbs, const int* keys, int numAabbs, BuildTreeNode* root, BuildArray<int>& nodeIndices, bool reuseNodes)
{
    BuildArray<int> indices;
    indices.SetSizeAndGrow(numAabbs);
    for (int i = 0; i < numAabbs; i++)
    {
        indices.m_data[i]=i;
    }

    BuildInplaceArray<BuildWorkItem, 64> stack;

    __m128 lo = _mm_set_ps1(3.40282e+38f);
    __m128 hi = _mm_set_ps1(-3.40282e+38f);
    for (int i = 0; i < numAabbs; i++)
    {
        __m128 scalarHalf = _mm_load_ss(&::fnv_00c88020::DAT_01016248);
        __m128 center = _mm_mul_ps(_mm_add_ps(aabbs[i].m_kMinimumCorner.m_vComponents, aabbs[i].m_kMaximumCorner.m_vComponents), _mm_shuffle_ps(scalarHalf,scalarHalf,0));
        lo = _mm_min_ps(lo, center);
        hi = _mm_max_ps(hi, center);
    }

    {
        BuildWorkItem& first = stack.m_data[0];
        stack.m_iElementCount = 1;
        first.m_kRayStart = 0;
        first.m_uiItemCount = numAabbs;
        first.m_kBounds.m_kMinimumCorner.m_vComponents = lo;
        first.m_kBounds.m_kMaximumCorner.m_vComponents = hi;
        first.m_node = root;
    }

    while (stack.GetLogicalSize())
    {
        BuildWorkItem item = stack.back();
        stack.popBack();

        if (item.m_uiItemCount <= 2)
        {
            int start = item.m_kRayStart;
            BuildTreeNode* parent = item.m_node;
            for (int j = 0; j < 2; j++)
            {
                int idx = indices[start + j];
                int nodeIndex;
                BuildTreeNode* node;
                if (reuseNodes)
                {
                    nodeIndex = nodeIndices[idx];
                    node = ((::BuildTreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(nodeIndex)));
                }
                else
                {
                    node = ((::BuildTreeNode *)(reinterpret_cast<::FUN_00d9ce00_Class *>(&(m_kNodeCollection))->PopItem((int)(&m_pTreeNode), (int)(&m_rootIndex), &nodeIndex)));
                }
                nodeIndices[idx] = nodeIndex;
                node->m_kBounds = aabbs[idx];
                node->setLeaf(keys[idx]);
                parent->m_children[j] = nodeIndex;
            }
        }
        else
        {
            BuildAabb childAabbs[2];
            int counts[2];
            int start = item.m_kRayStart;
            FUN_00d9a520(&item.m_kBounds, aabbs, &indices, start, item.m_uiItemCount, &childAabbs[0], &childAabbs[1], &counts[0], &counts[1]);

            BuildWorkItem children[2];

            for (int i = 0; i < 2; i++)
            {
                int count = counts[i];
                int nodeIndex;
                if (count > 1)
                {
                    BuildTreeNode* node = ((::BuildTreeNode *)(reinterpret_cast<::FUN_00d9ce00_Class *>(&(m_kNodeCollection))->PopItem((int)(&m_pTreeNode), (int)(&m_rootIndex), &nodeIndex)));
                    children[i].m_node = node;
                    children[i].m_uiItemCount = count;
                    children[i].m_kBounds = childAabbs[i];
                    children[i].m_kRayStart = item.m_kRayStart + i * counts[0];

                }
                else
                {
                    int idx = indices[item.m_kRayStart + i * counts[0]];
                    BuildTreeNode* node;
                    if (reuseNodes)
                    {
                        nodeIndex = nodeIndices[idx];
                        node = ((::BuildTreeNode *)(reinterpret_cast<::IdxStand_ *>(&(m_kNodeCollection))->FUN_00d9a4c0(nodeIndex)));
                    }
                    else
                    {
                        node = ((::BuildTreeNode *)(reinterpret_cast<::FUN_00d9ce00_Class *>(&(m_kNodeCollection))->PopItem((int)(&m_pTreeNode), (int)(&m_rootIndex), &nodeIndex)));
                    }

                    node->m_kBounds = aabbs[idx];
                    node->setLeaf(keys[idx]);
                    nodeIndices[idx] = nodeIndex;
                }
                item.m_node->m_children[i] = nodeIndex;

            }

            for (int i = 1; i >= 0; i--)
            {
                if (counts[i] > 1)
                {
                    stack.AddBack(children[i]);
                }
            }
        }
    }
}


struct S00d9c610_Vector4 {
    __m128 m_vComponents;
    __forceinline void setAdd4(const S00d9c610_Vector4& a, const S00d9c610_Vector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const S00d9c610_Vector4& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    __forceinline void setMin4(const S00d9c610_Vector4& a, const S00d9c610_Vector4& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMax4(const S00d9c610_Vector4& a, const S00d9c610_Vector4& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline const float& operator()(int i) const { return fnv_simd_as<float>(m_vComponents)[i]; }
};

struct S00d9c610_Aabb {
    S00d9c610_Vector4 m_kMinimumCorner;
    S00d9c610_Vector4 m_kMaximumCorner;
};

struct __declspec(align(16)) S00d9c610_AabbUint32 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_expansionMin0, m_expansionMin1, m_expansionMin2;
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_expansionMax0, m_expansionMax1, m_expansionMax2;
    unsigned char m_expansionMaxXYZ;
};

__forceinline void S00d9c610_convertToUint32WithClip(const S00d9c610_Vector4& in, const S00d9c610_Vector4& offset, const S00d9c610_Vector4& scale, const S00d9c610_Vector4& minv, const S00d9c610_Vector4& maxv, unsigned int* out)
{
    S00d9c610_Vector4 x;
    x.setAdd4(in, offset);
    x.mul4(scale);
    x.setMin4(x, maxv);
    x.setMax4(x, minv);

    out[0] = static_cast<unsigned int>(fnv_FloatToInt(x(0)));
    out[1] = static_cast<unsigned int>(fnv_FloatToInt(x(1)));
    out[2] = static_cast<unsigned int>(fnv_FloatToInt(x(2)));
    out[3] = static_cast<unsigned int>(fnv_FloatToInt(x(3)));
}

__forceinline void S00d9c610_convertAabbToUint32(const S00d9c610_Aabb& aabb, const S00d9c610_Vector4& offsetLow, const S00d9c610_Vector4& offsetHigh, const S00d9c610_Vector4& scale, S00d9c610_AabbUint32& aabbOut)
{
    S00d9c610_Vector4 maxVal; maxVal.m_vComponents = DAT_011b6d70;
    S00d9c610_convertToUint32WithClip(aabb.m_kMinimumCorner, offsetLow, scale, (const S00d9c610_Vector4&)(*reinterpret_cast<::hkVector4 *>(&::DAT_01267e30)), maxVal, aabbOut.m_kMinimumCorner);
    S00d9c610_convertToUint32WithClip(aabb.m_kMaximumCorner, offsetHigh, scale, (const S00d9c610_Vector4&)(*reinterpret_cast<::hkVector4 *>(&::DAT_01267e30)), maxVal, aabbOut.m_kMaximumCorner);
}

struct S00d9c610_TreeAabb16 {
    unsigned short m_max0, m_max1, m_max2;
    unsigned short m_min0, m_min1, m_min2;
    static __forceinline void convertAabbToTreeSpace(const S00d9c610_AabbUint32& volumeIn, S00d9c610_TreeAabb16& volumeOut)
    {
        volumeOut.m_max0 = (unsigned short)(volumeIn.m_kMaximumCorner[0] >> 15);
        volumeOut.m_min0 = (unsigned short)(volumeIn.m_kMinimumCorner[0] >> 15);
        volumeOut.m_max1 = (unsigned short)(volumeIn.m_kMaximumCorner[1] >> 15);
        volumeOut.m_min1 = (unsigned short)(volumeIn.m_kMinimumCorner[1] >> 15);
        volumeOut.m_max2 = (unsigned short)(volumeIn.m_kMaximumCorner[2] >> 15);
        volumeOut.m_min2 = (unsigned short)(volumeIn.m_kMinimumCorner[2] >> 15);
    }
    static __forceinline void convertAabbToTreeSpace(const S00d9c610_Aabb& volume, const S00d9c610_Vector4& bitOffsetLow, const S00d9c610_Vector4& bitOffsetHigh, const S00d9c610_Vector4& bitScale, S00d9c610_TreeAabb16& volumeOut)
    {
        S00d9c610_AabbUint32 qAabb;
        S00d9c610_convertAabbToUint32(volume, bitOffsetLow, bitOffsetHigh, bitScale, qAabb);
        convertAabbToTreeSpace(qAabb, volumeOut);
    }
};

struct S00d9c610_Node {
    S00d9c610_TreeAabb16 m_iBufferSize;
    union {
        struct { unsigned short m_childIdx0, m_childIdx1; } m_kChildIndices;
        struct { void* m_ulUserData; } m_kLeafData;
    };
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;
    S00d9c610_Node() : m_usNodeValue(0) {}
    void setSkipNodeIdx(unsigned short idx) { m_iSkipNodeIndex = idx; }
    void setParentNodeIdx(unsigned short idx) { m_usNodeValue = idx | (m_usNodeValue & 0x8000); }
    void setLeafData(void* userData) { m_kLeafData.m_ulUserData = userData; m_usNodeValue |= 0x8000; }
};

struct S00d9c610_NodeManager {
};

struct S00d9c610_AabbTree {
    void* vtbl;
    unsigned int unk04, unk08, unk0c;
    S00d9c610_Node* m_pAabbRootNode;
    unsigned short m_usManagerValue;
    int m_iNodeCount;
    S00d9c610_NodeManager m_kNodeManager;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    S00d9c610_Vector4 m_kAabbMin;
    S00d9c610_Vector4 m_kAabbMaximum;
    S00d9c610_Vector4 m_kAabbScale;
    unsigned short FUN_00d9c610(const S00d9c610_Aabb& aabb, void* userData);
};

// @fnv 0x00d9c610
unsigned short S00d9c610_AabbTree::FUN_00d9c610(const S00d9c610_Aabb& aabb, void* userData)
{
    S00d9c610_AabbUint32 qAabb;
    S00d9c610_convertAabbToUint32(aabb, m_kAabbMin, m_kAabbMaximum, m_kAabbScale, qAabb);
    unsigned short leafIdx;
    {
        S00d9c610_Node node;
        S00d9c610_TreeAabb16::convertAabbToTreeSpace(qAabb, node.m_iBufferSize);
        node.setLeafData(userData);
        leafIdx = reinterpret_cast<::RecordPool *>(&(m_kNodeManager))->AddRecord((int)&(m_pAabbRootNode), (int)&(m_usManagerValue), (const ::Record20 *)&(node));
    }
    if (m_usManagerValue == 0x7fff)
    {
        S00d9c610_Node* n = ((::S00d9c610_Node *)(reinterpret_cast<::FUN_00d9a4d0_Class *>(&(m_kNodeManager))->GetEntryOffset(leafIdx)));
        n->setParentNodeIdx(0x7fff);
        n->setSkipNodeIdx(0x7fff);
        m_pAabbRootNode = n;
        m_usManagerValue = leafIdx;
    }
    else
    {
        unsigned short scratchNodeIdx;
        reinterpret_cast<::fnv_00d9c280::FUN_00d9c280_cls *>(&(m_kNodeManager))->PopGlyphRecord((int *)&(m_pAabbRootNode), (unsigned short *)&(m_usManagerValue), (unsigned short *)&(scratchNodeIdx));
        reinterpret_cast<::Sd9_Tree *>(this)->FUN_00d9b580(m_usManagerValue, leafIdx, scratchNodeIdx);
    }
    m_iNodeCount++;
    return leafIdx;
}
