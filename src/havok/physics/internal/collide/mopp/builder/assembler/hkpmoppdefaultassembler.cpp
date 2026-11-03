
// src/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <new>
#include <cstring>
#include "fnv/decl/E06490Stack.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00e06d70_Class.h"
#include "fnv/decl/KdQuantizer.h"
#include "fnv/decl/SearchObject.h"
#include "fnv/decl/SomeClass.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_00e06000.h"
#include "fnv/symbols_00e07000.h"
#include "fnv/symbols_01000000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_0102e000.h"
extern "C" void __cdecl GrowBuffer();

struct FUN_00e06780_class
{
    void AppendChar(char b);
};

// Writes character b at the current write position, advances the offset, and calls GrowBuffer when the offset reaches the capacity.
// @fnv 0x00e06780
void FUN_00e06780_class::AppendChar(char acValue)
{
    char* p = *(char**)((char*)this + 0x10) - *(int*)((char*)this + 0xc);
    int base = *(int*)((char*)this + 8);
    *(p + base - 1) = acValue;
    ++*(int*)((char*)this + 0xc);
    if (*(int*)((char*)this + 0xc) >= *(int*)((char*)this + 8))
        static_cast<::E06490Stack *>(nullptr)->GrowBuffer();
}

struct S_00e066f0_Src
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_pRayStart;
    int m_kRayEnd;
    int m_uiItemCount;
    int m_offsets[8];
};

struct S_00e066f0
{
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
    int m_iElementCount;
    int m_uiItemCount;
    int m_entries[8];

    void CopyOffsets(const S_00e066f0_Src* src);
};

// @fnv 0x00e066f0
void S_00e066f0::CopyOffsets(const S_00e066f0_Src* src)
{
    m_iElementCount = src->m_kRayEnd - src->m_pRayStart;
    m_uiItemCount = src->m_uiItemCount;
    for (int i = 0; i < src->m_uiItemCount; i++)
    {
        m_entries[i] = src->m_offsets[i];
        m_entries[i + 1] = src->m_offsets[i + 1] - src->m_offsets[i];
    }
}

struct AlignRange
{
    volatile int m_iMinControlPoint;
    volatile int m_iMaxControlPoint;
};

struct FUN_00e06730_cls
{
    int unk00;
    int unk04;
    int unk08;
    AlignRange m_akRange[3];
    volatile int m_iShift;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    volatile int m_aiAlignedMin[3];
    volatile int m_aiAlignedMax[3];
    void AlignRanges();
};

// @fnv 0x00e06730
void FUN_00e06730_cls::AlignRanges()
{
    int iShift0 = m_iShift;
    int iMax0 = ((m_akRange[0].m_iMaxControlPoint >> iShift0) + 1) << iShift0;
    int iMin0 = (m_akRange[0].m_iMinControlPoint >> iShift0) << iShift0;
    m_aiAlignedMax[0] = iMax0;
    m_aiAlignedMin[0] = iMin0;

    int iShift1 = m_iShift;
    int iMax1 = ((m_akRange[1].m_iMaxControlPoint >> iShift1) + 1) << iShift1;
    int iMin1 = (m_akRange[1].m_iMinControlPoint >> iShift1) << iShift1;
    m_aiAlignedMin[1] = iMin1;
    m_aiAlignedMax[1] = iMax1;

    int iShift2 = m_iShift;
    int iMax2 = ((m_akRange[2].m_iMaxControlPoint >> iShift2) + 1) << iShift2;
    int iMin2 = (m_akRange[2].m_iMinControlPoint >> iShift2) << iShift2;
    m_aiAlignedMin[2] = iMin2;
    m_aiAlignedMax[2] = iMax2;
}

struct ByteSink
{
    int unk00;
    int unk04;
    int m_uiLogicalSize;
    int m_iUsed;
    char* m_pBuffer;


    void PutByte(char acValue)
    {
        m_pBuffer[m_uiLogicalSize - m_iUsed - 1] = acValue;
        m_iUsed++;
        if (m_iUsed >= m_uiLogicalSize)
            reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();
    }

    void PutBytePair(char acFirst, char acSecond);
};

// Writes acSecond then acFirst to the sink via PutByte, in that order.
// @fnv 0x00e067b0
void ByteSink::PutBytePair(char acFirst, char acSecond)
{
    PutByte(acSecond);
    PutByte(acFirst);
}

typedef void(* FlushFunction)(void*);
struct BufferWriter
{
    int unknown00;
    int unknown04;
    int capacity;
    int position;
    unsigned char* data;
    void WriteInt24(int value);
};
// Writes the low three bytes of value into the buffer from the end, advancing position and flushing when it reaches capacity.
// @fnv 0x00e06920
void BufferWriter::WriteInt24(int value)
{
    data[capacity - position - 1] = (unsigned char)value;
    ++position;
    if (position >= capacity)
        ((FlushFunction)GrowBuffer)(this);
    data[capacity - position - 1] = (unsigned char)(value >> 8);
    ++position;
    if (position >= capacity)
        ((FlushFunction)GrowBuffer)(this);
    data[capacity - position - 1] = (unsigned char)(value >> 16);
    ++position;
    if (position >= capacity)
        ((FlushFunction)GrowBuffer)(this);
}

struct S_00e06aa0_Pool
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void Free(void* p);
};
struct S_00e06aa0_Item
{
    int unk00;
    bool m_flag;
    char unk05;
    char unk06;
    char unk07;
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
    void* m_p70;
    void* m_p74;
};
struct S_00e06aa0
{
    int unk00;
    int unk04;
    int unk08;
    S_00e06aa0_Pool* m_kNodePool;
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
    bool m_enabled;
    void FUN_00e06aa0(S_00e06aa0_Item* item);
};
// If the item is not flagged and this object is enabled, frees the item's two pointers through the pool and nulls them.
// @fnv 0x00e06aa0
void S_00e06aa0::FUN_00e06aa0(S_00e06aa0_Item* item)
{
    if (!item->m_flag && m_enabled)
    {
        m_kNodePool->Free(item->m_p70);
        m_kNodePool->Free(item->m_p74);
        item->m_p70 = 0;
        item->m_p74 = 0;
    }
}

struct Node
{
    Node* next;
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
    char unk38;
    char unk39;
};
// Walks the linked list from node, marking each node's unk39 flag until one is already set or the list ends.
// @fnv 0x00e06b20
void FUN_00e06b20(Node* node)
{
    while (node)
    {
        if (node->unk39)
            return;
        node->unk39 = 1;
        node = node->next;
    }
}

struct Limits
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
};
// Copies second->unk34 into third->unk34, then compares unk38/unk24 thresholds and may overwrite third->unk34 with first->unk24.
// @fnv 0x00e06b50
void AdjustLimits(Limits* first, Limits* second, Limits* third)
{
    third->unk34 = second->unk34;
    unsigned int value = third->unk38 - second->unk34 + first->unk24;
    if (value < 0x20)
        return;
    if (third->unk38 <= 2 && value < 0x100)
        return;
    if (third->unk38 < 0x20 && second->unk38 >= 0x20)
    {
        third->unk34 = first->unk24;
        return;
    }
    if (third->unk38 < 0x100 && second->unk38 >= 0x100)
    {
        third->unk34 = first->unk24;
        return;
    }
    if (third->unk38 >= 0x10000)
        return;
    if (second->unk38 >= 0x10000)
        third->unk34 = first->unk24;
}

struct E06C20Writer
{
};

struct E06C20Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E06C20Writer* m_pStreamWriter;

    int FUN_00e06c20(void* data);
};

namespace fnv_00e06db0 {
struct Node
{
    char pad[0x40];
    void* m_40;
    int m_44;
};

struct FUN_00e06db0_class
{
    __declspec(nothrow) void WriteOp(int a, void* p);
    void FUN_00e06db0(int* flag, Node* b, Node* c);
};

// If *flag is set, calls WriteOp(0, c->m_40) when c->m_44 is 0 and b->m_44 is nonzero; otherwise when c->m_44 is 0 and c->m_40 is set.
// @fnv 0x00e06db0
void FUN_00e06db0_class::FUN_00e06db0(int* piFlag, Node* pNodeB, Node* pNodeC)
{
    if (*piFlag)
    {
        if (pNodeC->m_44 == 0 && pNodeB->m_44 != 0)
            WriteOp(0, pNodeC->m_40);
    }
    else
    {
        if (pNodeC->m_44 == 0 && pNodeC->m_40)
            WriteOp(0, pNodeC->m_40);
    }
}
}  // namespace fnv_00e06db0

struct S_00e07040_A
{
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
};
struct S_00e07040_B
{
    int unk00;
    int unk04;
    int unk08;
};
template <class T> inline T S_00e07040_Max(T a, T b)
{
    return a > b ? a : b;
}
// Returns the smaller of two values.
// @fnv 0x00e07040
template <class T> inline T S_00e07040_Min(T a, T b)
{
    return a < b ? a : b;
}
int FUN_00e07040(S_00e07040_A* a, S_00e07040_B* b)
{
    int n = b->unk08 - 8;
    if (n <= 0)
        n = 0;
    int r = a->unk24 - n;
    if (r > a->unk24)
        r = a->unk24;
    return r;
}

struct E07510Input
{
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
    unsigned char unk38;
    unsigned char unk39;
    unsigned char m_type;
};

struct E07510Solver
{
    void FUN_00e07510(E07510Input* a, void* b, void* c, void* d);
};

// If the input's m_type is 1, calls FUN_00e07070 with b, c and d, then always calls AdjustLimits with a, b and c.
// @fnv 0x00e07510
void E07510Solver::FUN_00e07510(E07510Input* pInput, void* b, void* c, void* d)
{
    if (pInput->m_type == 1)
        ::FUN_00e07070((::S_00e07070_Object *)this, (::S_00e07070_Object *)(b), (::S_00e07070_Result *)(c));
    ::AdjustLimits((::Limits *)this, (::Limits *)(pInput), (::Limits *)(b));
}

struct S_e07c50_Buf
{
    int unk0;
    int unk4;
    int unk8;
    int m_iElementCount;
};
struct S_e07c50_Item;
struct S_e07c50
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_e07c50_Buf* m_buf;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_uiItemCount;
    int FUN_00e07c50(S_e07c50_Item* item, int b, int c);
};
struct S_e07c50_Item
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    char m_flag38;
    char m_flag39;
    char unk3A;
    char unk3B;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_kRayEnd;
};
namespace fnv_00e08040 {
struct Node
{
    int unk00;
    unsigned char leaf;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    unsigned char complete;
    int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    Node* left;
    Node* right;
};
struct __declspec(align(8)) State
{
    int depth;
    bool retrying;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    State()
    {}
    State(const State&, Node*, float*);
    void FUN_00e095d0(const State*, Node*, float*);
};
struct MergeInfo
{
    bool changed;
    int index;
    int unk08, unk0C, unk10;
};
struct CheckResult
{
    bool value;
    CheckResult(bool v) : value(v)
    {}
    operator bool() const
    {
        return value;
    }
};
struct Tracker
{
    int unk00, unk04, unk08, count;
};
struct TreeOptimizer
{
    int unk00, unk04, unk08, unk0C;
    Tracker* tracker;
    int unk14, threshold, unk1C, unk20, limit, count, unk2C;
    float config30, config34, config38, config3C, config40, config44, config48, config4C, config50, config54, config58,
        config5C, config60, config64, config68, config6C;
    int period;
    CheckResult FUN_00e06af0(Node*, State*);
    int FUN_00e07ca0(Node*, void*, State*, MergeInfo*);
    int OptimizeTree(Node*, void*, State*);
};
// Recursively optimizes a node tree, retrying with a reduced threshold, merging child results and returning a combined score or -1.
// @fnv 0x00e08040
int TreeOptimizer::OptimizeTree(Node* node, void* context, State* state)
{
    if (node->complete)
        return 3;
    if (state->depth <= threshold && state->depth % period == 0 && !state->retrying)
    {
        state->retrying = true;
        int result = -1;
        int savedThreshold = threshold;
        while (!node->complete)
        {
            int previousCount = tracker->count;
            State stateCopy = *state;
            result = OptimizeTree(node, context, &stateCopy);
            if (count > limit)
                break;
            if (previousCount == tracker->count)
            {
                if (threshold < 0)
                    break;
                threshold -= period;
            }
        }
        threshold = savedThreshold;
        state->retrying = false;
        return result;
    }
    if (node->leaf)
    {
        ::FUN_00e06b20((::Node *)(node));
        if (FUN_00e06af0(node, state))
            return reinterpret_cast<::S_e07c50 *>(this)->FUN_00e07c50((::S_e07c50_Item *)(node), (int)(context), (int)(state));
    }
    else
    {
        MergeInfo info;
        info.changed = false;
        info.index = -1;
        reinterpret_cast<::E07510Solver *>((node))->FUN_00e07510((::E07510Input *)(context), state, &info, {});
        int score = -1;
        {

            Node* rightChild = node->right;
            if (rightChild)
            {
                State stateCopy;
                stateCopy.FUN_00e095d0(state, rightChild, &config30);
                score = OptimizeTree(rightChild, state, &stateCopy);
                if (score >= 0)
                    reinterpret_cast<::S_00e06aa0 *>(this)->FUN_00e06aa0((::S_00e06aa0_Item *)(rightChild));
            }
            Node* leftChild = node->left;
            if (leftChild)
            {
                State stateCopy;
                stateCopy.FUN_00e095d0(state, leftChild, &config30);
                int leftResult = OptimizeTree(leftChild, state, &stateCopy);
                if (leftResult >= 0)
                {
                    reinterpret_cast<::S_00e06aa0 *>(this)->FUN_00e06aa0((::S_00e06aa0_Item *)(leftChild));
                    if (score >= 0 && FUN_00e06af0(node, state))
                    {
                        ++count;
                        return FUN_00e07ca0(node, context, state, &info) + leftResult + score;
                    }
                }
            }
        }
    }
    return -1;
}
}  // namespace fnv_00e08040

struct Allocator
{
    virtual void* unk00(void* p);
    virtual void* unk04(void* p);
    virtual void ReleaseBlock(void* p, unsigned short size);
};
struct Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* allocator;
};
static inline Router* getMemoryRouter() { return static_cast<Router*>(::FUN_00c85750()); }
struct FUN_00e09640_class
{
    virtual void unknownVirtual();
    unsigned short unk04;
    FUN_00e09640_class* FUN_00e09640(int flags);
};
struct FUN_00e06800_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void FUN_00e06800(char a, intptr_t v);
};

// @fnv 0x00e06800
void FUN_00e06800_cls::FUN_00e06800(char acByte, intptr_t aiValue)
{
    m_buf[m_cap - m_uiItemCount - 1] = (char)aiValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    aiValue = aiValue >> 8;
    m_buf[m_cap - m_uiItemCount - 1] = (char)aiValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = acByte;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();
}

struct FUN_00e06880_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void FUN_00e06880(char a, int v);
};

// Writes the low three bytes of v and then a into the buffer from the end, flushing whenever the buffer fills.
// @fnv 0x00e06880
void FUN_00e06880_cls::FUN_00e06880(char acTrailingByte, int aiValue)
{
    m_buf[m_cap - m_uiItemCount - 1] = (char)aiValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(aiValue >> 8);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(aiValue >> 16);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = acTrailingByte;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();
}

struct FUN_00e069a0_cls
{
    int unk00;
    int unk04;
    int m_cap;
    int m_uiItemCount;
    char* m_buf;

    void FUN_00e069a0(char a, uintptr_t v);
};
// @fnv 0x00e06c20
int E06C20Object::FUN_00e06c20(void* data)
{
    reinterpret_cast<::FUN_00e069a0_cls *>((m_pStreamWriter))->FUN_00e069a0(0x70, reinterpret_cast<uintptr_t>(data));
    return 5;
}

// Writes the four bytes of v and then a into m_buf from the end backwards, flushing whenever the buffer fills.
// @fnv 0x00e069a0
void FUN_00e069a0_cls::FUN_00e069a0(char a, uintptr_t auValue)
{
    m_buf[m_cap - m_uiItemCount - 1] = (char)auValue;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(auValue >> 8);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(auValue >> 16);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = (char)(auValue >> 24);
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();

    m_buf[m_cap - m_uiItemCount - 1] = a;
    m_uiItemCount++;
    if (m_uiItemCount >= m_cap)
        reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();
}

struct FUN_00e06490_cls
{
};

struct FUN_00e06a60_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    void FillWithPattern(int count);
};

// @fnv 0x00e06a60
void FUN_00e06a60_cls::FillWithPattern(int count)
{
    if (count <= 0)
        return;
    int n = count;
    do
    {
        char* base = (char*)unk08;
        base[unk10 - unk0c - 1] = (char)0xcd;
        unk0c++;
        if (unk0c >= unk08)
        {
            reinterpret_cast<::E06490Stack *>((((FUN_00e06490_cls*)this)))->GrowBuffer();
        }
        n--;
    } while (n != 0);
}

// FUN_00e06af0 - a small member that fills in a result flag.
//
// The original code is exactly:
//     00e06af0  8b 44 24 08        mov eax, dword ptr [esp + 8]
//     00e06af4  83 78 08 16        cmp dword ptr [eax + 8], 16h
//     00e06af8  7d 0a              jge 0x00e06b04
//     00e06afa  8b 44 24 04        mov eax, dword ptr [esp + 4]
//     00e06afe  c6 00 01           mov byte ptr [eax], 1
//     00e06b01  c2 0c 00           ret 0ch
//     00e06b04  8b 54 24 0c        mov edx, dword ptr [esp + 0ch]
//     00e06b08  8b 02              mov eax, dword ptr [edx]
//     00e06b0a  3b 41 18           cmp eax, dword ptr [ecx + 18h]
//     00e06b0d  8b 44 24 04        mov eax, dword ptr [esp + 4]
//     00e06b11  7f eb              jg 0x00e06afe
//     00e06b13  c6 00 00           mov byte ptr [eax], 0
//     00e06b16  c2 0c 00           ret 0ch
//
// so the member is
//     char* FUN_00e06af0(char* out, Actor* actor, int* value)
// and it returns the flag pointer it was given:
//
//   * if actor->unk08 is below 0x16 the flag is set to 1 unconditionally;
//   * otherwise the flag is 1 when *value is greater than the member
//     field at +0x18 and 0 when it is not.
//
// The "return out;" in every branch matters for the code generation: the
// returned pointer is already in EAX, and because the branches are not
// plain assignments MSVC 2008 keeps the two stores as real branches
// instead of folding them into a single conditional store.

// The "actor" the first flag argument points at.
struct FUN_00e06780_actor
{
    int unk00;
    int unk04;
    int unk08;
};

// The class the member belongs to.  The unit's FUN_00e06780_class carries
// no data members, so the flag field lives in the derived stand-in.
struct FUN_00e06780_owner : public FUN_00e06780_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;  // +0x18
    char* FUN_00e06af0(char* out, FUN_00e06780_actor* actor, int* value);
};

// Writes 1 to out if actor->unk08 is below 0x16 or *value exceeds this->unk18, otherwise writes 0, and returns out.
// @fnv 0x00e06af0
char* FUN_00e06780_owner::FUN_00e06af0(char* pResult, FUN_00e06780_actor* actor, int* piValue)
{
    if (actor->unk08 < 0x16)
    {
        *pResult = 1;
        return pResult;
    }
    else
    {
        if (*piValue > this->unk18)
        {
            *pResult = 1;
            return pResult;
        }
        *pResult = 0;
        return pResult;
    }
}

struct Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char* unk10;


    void AppendChar(char b)
    {
        unk10[unk08 - unk0c - 1] = b;
        unk0c++;
        if (unk0c >= unk08)
        {
            reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();
        }
    }

};

struct FUN_00e06c40_class
{
    char pad[0x10];
    Stream* m_stream;

    int FUN_00e06c40(int a1, int a2);
};

// @fnv 0x00e06c40
int FUN_00e06c40_class::FUN_00e06c40(int a1, int a2)
{
    m_stream->AppendChar((char)a2);
    m_stream->AppendChar((char)(a2 >> 8));
    reinterpret_cast<::FUN_00e06800_cls *>((m_stream))->FUN_00e06800(0xd, a1);
    return 5;
}

extern "C" void __cdecl GrowBuffer();

struct Sink
{
    int unk00;
    int unk04;
    int m_iCap;
    int m_iArrayLength;
    int m_iEnd;
};

struct Pkt
{
    int unk00;
    char m_b04;
    char unk05;
    char unk06;
    char unk07;
    char m_b08;
    char unk09;
    char unk0a;
    char unk0b;
    char m_b0c;
    char unk0d;
    char unk0e;
    char unk0f;
    char m_b10;
};

class FUN_00e06cb0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Sink* m_pSink;

    void WritePacket(const Pkt* p);
};

// Writes four bytes of the packet (m_b10, m_b0c, m_b08, m_b04) into the sink buffer, flushing when it fills.
// @fnv 0x00e06cb0
void FUN_00e06cb0_cls::WritePacket(const Pkt* p)
{
    {
        Sink* s = m_pSink;
        char v = p->m_b10;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            reinterpret_cast<::E06490Stack *>((s))->GrowBuffer();
    }
    {
        Sink* s = m_pSink;
        char v = p->m_b0c;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            reinterpret_cast<::E06490Stack *>((s))->GrowBuffer();
    }
    {
        Sink* s = m_pSink;
        char v = p->m_b08;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            reinterpret_cast<::E06490Stack *>((s))->GrowBuffer();
    }
    {
        Sink* s = m_pSink;
        char v = p->m_b04;
        ((char*)s->m_iCap)[s->m_iEnd - s->m_iArrayLength - 1] = v;
        s->m_iArrayLength++;
        if (s->m_iArrayLength >= s->m_iCap)
            reinterpret_cast<::E06490Stack *>((s))->GrowBuffer();
    }
}


struct S_00e06e00_Item
{
    int unk0;
};

struct S_00e06e00_Buf
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

struct S_00e06e00_A0
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00e06e00_Item* unk30[12];
    unsigned int* unk60;
};

struct S_00e06e00_A1
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk44[16];
};

struct S_00e06e00_A2
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    unsigned int unk34;
};

struct S_00e06e00_Cls
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e06e00_Buf* unk10;
    int FUN_00e06e00(S_00e06e00_A0* a, S_00e06e00_A1* b, S_00e06e00_A2* c);
};

struct Vec3
{
    float x;
    float y;
    float z;
};

extern const double g_thresholdB;

// Compares the x, y and z components of a Vec3 against g_thresholdA and g_thresholdB and returns a code from 0 to 12 identifying the region.
// @fnv 0x00e06f20
int ClassifyVec3Region(const Vec3* pVec)
{
    int r;
    if ((double)pVec->x > ::DAT_0101ffa0)
    {
        r = 0;
        if ((double)pVec->z > ::DAT_0101ffa0)
        {
            r = 5;
            if ((double)pVec->y > ::DAT_0101ffa0)
            {
                r = 9;
            }
            else if ((double)pVec->y < g_thresholdB)
            {
                r = 11;
            }
        }
        else if ((double)pVec->z < g_thresholdB)
        {
            r = 6;
            if ((double)pVec->y > ::DAT_0101ffa0)
            {
                r = 10;
            }
            else if ((double)pVec->y < g_thresholdB)
            {
                r = 12;
            }
        }
        else
        {
            if ((double)pVec->y > ::DAT_0101ffa0)
            {
                r = 7;
            }
            else if ((double)pVec->y < g_thresholdB)
            {
                r = 8;
            }
        }
    }
    else
    {
        if ((double)pVec->y > ::DAT_0101ffa0)
        {
            r = 1;
            if ((double)pVec->z > ::DAT_0101ffa0)
            {
                r = 3;
            }
            else if ((double)pVec->z < g_thresholdB)
            {
                r = 4;
            }
        }
        else
        {
            r = 2;
        }
    }
    return r;
}

struct S_00e07070_Pair
{
    int unk00;
    int unk04;
};
struct S_00e07070_Object
{
    int unk00;
    int unk04;
    int unk08;
    S_00e07070_Pair r[3];
    int m_24;
    int v[3];
};

struct S_00e07070_Result
{
    char ok;
    int count;
    int q[3];
};


// @fnv 0x00e07070
void FUN_00e07070(S_00e07070_Object* a, S_00e07070_Object* b, S_00e07070_Result* out)
{
    int n = ::FUN_00e07040((::S_00e07040_A *)(a), (::S_00e07040_B *)(b));
    out->ok = 0;
    if (n > 0)
    {
        if (n >= 4)
            n = 4;
        for (;;)
        {
            b->m_24 = a->m_24 - n;
            int i = 0;
            while (i < 3)
            {
                int s = a->m_24;
                int q = (b->r[i].unk00 - a->v[i]) >> s;
                b->v[i] = (q << s) + a->v[i];
                out->q[i] = q;
                if (((b->r[i].unk04 - b->v[i]) >> b->m_24) >= 255)
                    goto retry;
                i++;
            }
            break;
        retry:
            n--;
        }
        out->count = n;
        out->ok = 1;
    }
    else
    {
        b->m_24 = a->m_24;
        b->v[0] = a->v[0];
        b->v[1] = a->v[1];
        b->v[2] = a->v[2];
    }
}

struct S_00e07680_Writer
{
    int unk0;
    int unk4;
    int m_cap;
    int m_pos;
    unsigned char* m_buf;
    void AppendChar(int b);
    __forceinline void put(unsigned char b)
    {
        m_buf[m_cap - m_pos - 1] = b;
        m_pos++;
        if (m_pos >= m_cap)
            reinterpret_cast<::E06490Stack *>(this)->GrowBuffer();
    }
};
struct S_00e07680
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00e07680_Writer* w;
    void FUN_00e07680(int a1, int a2, int a3, int a4, int a5);
};

struct Entry
{
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
    unsigned char unk38;
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
    Entry* unk70;
    Entry* unk74;
};
struct Handler
{
    int unk00, unk04, unk08, unk0c;
    Entry* unk10;
    int FUN_00e07ca0(Entry*, Entry*, Entry*, char*);
};

struct S_00e07da0_Bounds
{
    int unk0;
    char b4;
    int unk8;
    struct Range
    {
        int lo;
        int hi;
    } ranges[3];  // 0x0C
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40[1];
    int unk44[1];

};

struct S_00e07da0_Region : S_00e07da0_Bounds
{
    int lo48[3];
    int hi54[3];

};

struct S_00e07da0_Result
{
    bool valid;
    int value;
    int unk8;
    int unkC;
    int unk10;
};

struct S_00e07da0_Info
{
    char b0;
    char b1;
    char b2;
    char state[3];
    char pad6[2];
    int unk8;
    int mins[3];  // 0x0C
    int maxs[3];  // 0x18
};

struct S_00e07da0_Node
{
    int unk0;
    char b4;
    char pad5[3];
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int count2C;
    int offsets[2];        // 0x30
    S_00e07da0_Info info;  // 0x38
    void* unk5C;
    void* unk60;
    int unk64;
    int unk68;
    int unk6C;
    S_00e07da0_Node* child70;
    S_00e07da0_Node* child74;
};

struct S_00e07da0_Tree
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    float unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    float unk54;

    void BuildRegion(S_00e07da0_Node* node, S_00e07da0_Region* parent, S_00e07da0_Region* region);
};

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

struct BSAudio;

extern int DAT_010ea5dc;

struct FUN_00e09450_cls
{
    const void* m_vptr00;
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
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void DestroyAudioBuffer();
};
// @fnv 0x00e09640
FUN_00e09640_class* FUN_00e09640_class::FUN_00e09640(int flags)
{
    reinterpret_cast<::FUN_00e09450_cls *>(this)->DestroyAudioBuffer();
    if (flags & 1)
    {
        Router* router = getMemoryRouter();
        router->allocator->ReleaseBlock(this, unk04);
    }
    return this;
}

// @fnv 0x00e09450
void FUN_00e09450_cls::DestroyAudioBuffer()
{
    m_vptr00 = &::DAT_010ea5dc;
    AudioHolder* pAudioHolder = (AudioHolder*)getMemoryRouter();
    AudioAllocator* pAudioAllocator = pAudioHolder->m_pAllocator;
    m_iArrayLength = 0;
    unsigned int uCapacityBits = m_uCapBits;
    if ((uCapacityBits & 0x80000000u) == 0)
    {
        pAudioAllocator->FreeArray(m_pData, (uCapacityBits & 0x3fffffffu) * 32);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = &::DAT_0102e388;
}

int __cdecl FUN_00cbfe20(float v);

struct FUN_00e094a0_floatpair
{
    float lo;
    float hi;
};

struct FUN_00e094a0_intpair
{
    int lo;
    int hi;
};

struct FUN_00e094a0_floatset
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00e094a0_floatpair pairs[3];
};

struct FUN_00e094a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00e094a0_intpair m_0c[3];

    void BuildScaledRanges(FUN_00e094a0_floatset* a1, float* a2);
};

// @fnv 0x00e094a0
void FUN_00e094a0_cls::BuildScaledRanges(FUN_00e094a0_floatset* pFloatSet, float* pValues)
{
    int best = 0;
    for (int i = 0; i < 3; i++)
    {
        volatile float s = pValues[3];
        float v = (pFloatSet->pairs[i].lo - pValues[i]) * s;
        this->m_0c[i].lo = FUN_00cbfe20(v);
        volatile float fScale2 = pValues[3];
        float w = (pFloatSet->pairs[i].hi - pValues[i]) * fScale2;
        this->m_0c[i].hi = FUN_00cbfe20(w) + 1;
        int iSpan = this->m_0c[i].hi - this->m_0c[i].lo;
        if (best <= iSpan)
            best = iSpan;
    }
}

// FUN_00e09540 - compute the level of an object from its bounding box.
//
// this : the object
//   +0x08 : the resulting level (a byte-sized value in the original)
//   +0x0c/+0x10, +0x14/+0x18, +0x1c/+0x20 : the three axis bounds
//
// The largest of the three axis extents is taken, the number of bits it
// needs is counted and the level is derived from that; the result is
// clamped to 0x18.

struct FUN_00e09540_Self
{
    void* unk00;
    int unk04;
    int unk08;  // the level
    int unk0c;  // x min
    int unk10;  // x max
    int unk14;  // y min
    int unk18;  // y max
    int unk1c;  // z min
    int unk20;  // z max
    void FUN_00e09540();
};

// @fnv 0x00e09540
void FUN_00e09540_Self::FUN_00e09540()
{
    int size = this->unk10 - this->unk0c;
    int other = this->unk18 - this->unk14;
    if (size <= other)
        size = other;
    other = this->unk20 - this->unk1c;
    if (size <= other)
        size = other;

    int iBitCount = 0;
    unsigned int shifted = size;
    while (shifted)
    {
        shifted >>= 1;
        iBitCount++;
    }

    int level = -1;
    for (int i = 0; i < 3; i++)
    {
        int scaled = size + (1 << (iBitCount - 4));
        int count = 0;
        unsigned int value = scaled;
        while (value)
        {
            value >>= 1;
            count++;
        }
        if (count > level)
            level = count;
    }

    this->unk08 = (level > 0x18) ? 0x18 : level;
}

class FUN_00e095d0_cls
{
  public:
    unsigned int m_00;
    unsigned char m_04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;

    FUN_00e095d0_cls* FUN_00e095d0(FUN_00e095d0_cls* src, unsigned int a2, unsigned int a3);
};

// @fnv 0x00e095d0
FUN_00e095d0_cls* FUN_00e095d0_cls::FUN_00e095d0(FUN_00e095d0_cls* pSource, unsigned int a2, unsigned int a3)
{
    *this = *pSource;
    reinterpret_cast<::S_00e066f0 *>(this)->CopyOffsets((const ::S_00e066f0_Src *)(a2));
    reinterpret_cast<::FUN_00e094a0_cls *>(this)->BuildScaledRanges((::FUN_00e094a0_floatset *)(a2), (float *)(a3));
    m_00 = pSource->m_00 + 1;
    m_04 = 0;
    reinterpret_cast<::FUN_00e09540_Self *>(this)->FUN_00e09540();
    return this;
}

// Emit an opcode with an immediate, choosing the byte, short or int form (and its opcode offset) by value range.

class E6BC0Writer
{
  public:
};

class E6BC0Encoder
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E6BC0Writer* m_pkWriter;

    void WriteOp(int iOpcode, int iValue);
};
// @fnv 0x00e06e00
int S_00e06e00_Cls::FUN_00e06e00(S_00e06e00_A0* a, S_00e06e00_A1* b, S_00e06e00_A2* c)
{
    int start = unk10->unkC;
    unsigned int v = *a->unk60 - c->unk34;
    S_00e06e00_Buf* buf = unk10;
    if (v < 0x20)
    {
        *(char*)(buf->unk10 - buf->unkC + buf->unk8 - 1) = (char)(v + 0x30);
        buf->unkC++;
        if (buf->unkC >= buf->unk8)
        {
            static_cast<::E06490Stack *>(nullptr)->GrowBuffer();
        }
    }
    else if (v < 0x100)
    {
        reinterpret_cast<::ByteSink *>((buf))->PutBytePair(0x50, v);
    }
    else if (v < 0x10000)
    {
        reinterpret_cast<::FUN_00e06800_cls *>((buf))->FUN_00e06800(0x51, v);
    }
    else if (v < (unsigned int)&(*reinterpret_cast<char *>(&::DAT_01000000)))
    {
        reinterpret_cast<::FUN_00e06880_cls *>((buf))->FUN_00e06880(0x52, v);
    }
    else
    {
        reinterpret_cast<::FUN_00e069a0_cls *>((buf))->FUN_00e069a0(0x53, v);
    }
    for (int i = 0; i < a->unk2C; i++)
    {
        if (a->unk30[i] && b->unk44[i])
        {
            reinterpret_cast<::E6BC0Encoder *>(this)->WriteOp(i, (int)(a->unk30[i]));
        }
    }
    return unk10->unkC - start;
}

// Writes iValue to the writer using a byte, short or int opcode chosen by the value's magnitude, offset from iOpcode.
// @fnv 0x00e06bc0
void E6BC0Encoder::WriteOp(int iBaseOpcode, int iValue)
{
    E6BC0Writer* pkWriter = m_pkWriter;
    if (iValue < 0)
        reinterpret_cast<::FUN_00e069a0_cls *>((pkWriter))->FUN_00e069a0(iBaseOpcode + 0x68, iValue);
    else if (iValue < 0x100)
        reinterpret_cast<::ByteSink *>((pkWriter))->PutBytePair(iBaseOpcode + 0x60, iValue);
    else if (iValue < 0x10000)
        reinterpret_cast<::FUN_00e06800_cls *>((pkWriter))->FUN_00e06800(iBaseOpcode + 0x64, iValue);
    else
        reinterpret_cast<::FUN_00e069a0_cls *>((pkWriter))->FUN_00e069a0(iBaseOpcode + 0x68, iValue);
}

struct FUN_00e06ed0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e06e00_Buf* m_pStreamWriter;
    void WriteOffsetDelta(int iTarget);
};
// @fnv 0x00e07680
void S_00e07680::FUN_00e07680(int a1, int a2, int a3, int a4, int a5)
{
    int e = w->m_pos;
    int d = e - a5;
    if (a3 < 3)
    {
        e -= a4;
        if ((e > 0 || d > 0xf8) && e < 0x10000 && d < 0x10000)
        {
            reinterpret_cast<::FUN_00e06780_class *>((w))->AppendChar(d & 0xff);
            reinterpret_cast<::FUN_00e06780_class *>((w))->AppendChar((d >> 8) & 0xff);
            reinterpret_cast<::FUN_00e06780_class *>((w))->AppendChar(e & 0xff);
            reinterpret_cast<::FUN_00e06780_class *>((w))->AppendChar((e >> 8) & 0xff);
            reinterpret_cast<::FUN_00e06780_class *>((w))->AppendChar(a1);
            reinterpret_cast<::FUN_00e06780_class *>((w))->AppendChar(a2);
            reinterpret_cast<::FUN_00e06780_class *>((w))->AppendChar(a3 + 0x23);
            return;
        }
        if (a2 - a1 == 1)
        {
            if (d > 0xfb)
            {
                reinterpret_cast<::FUN_00e06ed0_Class *>(this)->WriteOffsetDelta(a5);
                a5 = w->m_pos;
            }
            reinterpret_cast<::FUN_00e06ed0_Class *>(this)->WriteOffsetDelta(a4);
            w->put(w->m_pos - a5);
            w->put(a1);
            w->put(a3 + 0x20);
            return;
        }
    }
    if (d > 0xfb)
    {
        reinterpret_cast<::FUN_00e06ed0_Class *>(this)->WriteOffsetDelta(a5);
        a5 = w->m_pos;
    }
    reinterpret_cast<::FUN_00e06ed0_Class *>(this)->WriteOffsetDelta(a4);
    w->put(w->m_pos - a5);
    w->put(a1);
    w->put(a2);
    w->put(a3 + 0x10);
}

// Computes the difference between the buffer's field at offset 12 and iTarget, then writes it with a width code (5-8) chosen by its magnitude if positive.
// @fnv 0x00e06ed0
void FUN_00e06ed0_Class::WriteOffsetDelta(int iTargetValue)
{
    int iOffset = m_pStreamWriter->unkC - iTargetValue;
    if (iOffset > 0)
    {
        if (iOffset < 0xff)
            reinterpret_cast<::ByteSink *>((m_pStreamWriter))->PutBytePair(5, iOffset);
        else if (iOffset < 0xffff)
            reinterpret_cast<::FUN_00e06800_cls *>((m_pStreamWriter))->FUN_00e06800(6, iOffset);
        else if (iOffset < 0xffffff)
            reinterpret_cast<::FUN_00e06880_cls *>((m_pStreamWriter))->FUN_00e06880(7, iOffset);
        else
            reinterpret_cast<::FUN_00e069a0_cls *>((m_pStreamWriter))->FUN_00e069a0(8, iOffset);
    }
}


struct Node07400
{
    int unk00;
    char b04;
    int unk08;
    struct Range
    {
        float fLo;
        float fHi;
    } ranges[3];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int mins[3];
    int maxs[3];
};

struct Region07400
{
    int unk00;
    char b04;
    int unk08;
    struct Range
    {
        int lo;
        int hi;
    } ranges[3];
    int m_iShift;
};

template <class T> inline T Min07400(T a, T b)
{
    return a < b ? a : b;
}
template <class T> inline T Max07400(T a, T b)
{
    return a > b ? a : b;
}

struct Tree07400
{
    int unk00[15];
    float m_fScale;
    int unk40[6];
    float m_fMinCount;
    int unk5C;
    float m_afMaxCount[3];

    void ComputeNodeBounds(Node07400* node, Region07400* region);
};
// Recursively builds a region for node from parent and region, merging child bounds and states into node->info.
// @fnv 0x00e07da0
void S_00e07da0_Tree::BuildRegion(S_00e07da0_Node* node, S_00e07da0_Region* parent, S_00e07da0_Region* region)
{
    S_00e07da0_Info* info = &node->info;
    if (info->b0 != 0)
        return;

    if (node->b4 != 0)
    {
        reinterpret_cast<::FUN_00e06730_cls *>((region))->AlignRanges();
        reinterpret_cast<::Tree07400 *>(this)->ComputeNodeBounds((::Node07400 *)(node), (::Region07400 *)(region));
        return;
    }

    S_00e07da0_Result out;
    if (info->b2 == 1)
        ::FUN_00e07070((::S_00e07070_Object *)this, (::S_00e07070_Object *)(parent), (::S_00e07070_Result *)(region));
    reinterpret_cast<::FUN_00e06730_cls *>((region))->AlignRanges();
    int axis = ::ClassifyVec3Region((const ::Vec3 *)this);
    {
        int lo, hi;
        reinterpret_cast<::KdQuantizer *>(this)->FUN_00e07880((const ::QuantNode *)(node), (const ::KdRegion *)(region), &lo, &hi);
    }

    S_00e07da0_Node* first = node->child74;
    S_00e07da0_Node* apChildren[2];
    apChildren[0] = first;
    apChildren[1] = node->child70;

    for (int k = 0; k < 3; k++)
    {
        float sc = unk3C;
        float* ps = &sc;
        FUN_00cbfef0(unk54 * *ps);
        info->mins[k] = 0;
        info->maxs[k] = 0x7fffffff;
    }

    for (int i = 0; i < 2; i++)
    {
        S_00e07da0_Node* child = apChildren[i];
        S_00e07da0_Info* pChildInfo = &child->info;
        if (child == 0)
            continue;

        S_00e07da0_Region childRegion;
        static_cast<S_00e07da0_Bounds&>(childRegion) = *region;
        childRegion.unk38 = child->unk28 - child->unk24;
        childRegion.unk3C = child->count2C;
        for (int iIndex = 0; iIndex < child->count2C; iIndex++)
        {
            childRegion.unk40[iIndex] = child->offsets[iIndex];
            childRegion.unk44[iIndex] = child->offsets[iIndex + 1] - child->offsets[iIndex];
        }
        reinterpret_cast<::FUN_00e094a0_cls *>(&(childRegion))->BuildScaledRanges((::FUN_00e094a0_floatset *)(child), (float *)(void *)(&unk30));
        childRegion.unk0 = region->unk0 + 1;
        childRegion.b4 = 0;
        reinterpret_cast<::FUN_00e09540_Self *>(&(childRegion))->FUN_00e09540();
        BuildRegion(child, region, &childRegion);

        if (child == first)
        {
            if (axis <= 2)
                child->info.mins[axis] = 0;
        }
        else
        {
            if (axis <= 2)
                child->info.maxs[axis] = 0x7fffffff;
        }

        for (int iIndex = 0; iIndex < 3; iIndex++)
        {
            int s = pChildInfo->state[iIndex];
            if (s == 1)
            {
                if (pChildInfo->mins[iIndex] <= region->lo48[iIndex] &&
                    pChildInfo->maxs[iIndex] >= region->hi54[iIndex])
                {
                    int t = info->state[iIndex];
                    info->state[iIndex] = t < 1 ? 1 : t;
                    pChildInfo->state[iIndex] = 0;
                }
            }
            else if (s == 2)
            {
                if (pChildInfo->mins[iIndex] <= region->ranges[iIndex].lo &&
                    pChildInfo->maxs[iIndex] >= region->ranges[iIndex].hi)
                {
                    info->state[iIndex] = 2;
                    pChildInfo->state[iIndex] = 0;
                }
            }
            if (pChildInfo->state[iIndex] == 0)
            {
                {
                    int c = pChildInfo->mins[iIndex];
                    int n = info->mins[iIndex];
                    info->mins[iIndex] = n > c ? n : c;
                }
                {
                    int c = pChildInfo->maxs[iIndex];
                    int n = info->maxs[iIndex];
                    info->maxs[iIndex] = n < c ? n : c;
                }
            }
        }
    }
}

// @fnv 0x00e07400
void Tree07400::ComputeNodeBounds(Node07400* node, Region07400* region)
{
    for (int i = 0; i < 3; i++)
    {
        float fExtent = node->ranges[i].fHi - node->ranges[i].fLo;
        float fCount = (float)(1 << region->m_iShift) / m_fScale;
        fCount = Max07400(fCount, m_fMinCount);
        float fMaxCount = m_afMaxCount[i];
        if (fExtent < fMaxCount)
            fCount = Min07400(fCount, fMaxCount);
        float fScale = m_fScale;
        int iMargin = FUN_00cbfef0(fScale * fCount);
        int iHi = region->ranges[i].hi;
        node->mins[i] = region->ranges[i].lo - iMargin;
        node->maxs[i] = iHi + iMargin + 1;
    }
}

struct Arg1Flags
{
    unsigned char unk00[0x3b];
    unsigned char m_3b[3];
};

struct Pair
{
    int m_ucLowNibble;
    int m_ucHighNibble;
};

struct Arg2Layout
{
    int unk00;
    int unk04;
    int unk08;
    Pair m_0c[3];
    int m_24;
    int m_28[3];
};

struct BufWriter
{
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int m_10;
};

inline void EmitByte(BufWriter* w, unsigned char v)
{
    ((char*)(w->m_10 - w->m_0c))[w->m_08 - 1] = v;
    w->m_0c++;
    if (w->m_0c >= w->m_08)
    {
        reinterpret_cast<::E06490Stack *>((w))->GrowBuffer();
    }
}

struct FUN_00e07550_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BufWriter* m_10;
    void FUN_00e07550(Arg1Flags* a1, Arg2Layout* a2);
};
// @fnv 0x00e07c50
int S_e07c50::FUN_00e07c50(S_e07c50_Item* item, int b, int c)
{
    ::FUN_00e06b20((::Node *)this);
    m_uiItemCount++;
    int start = m_buf->m_iElementCount;
    reinterpret_cast<::S_00e06e00_Cls *>(this)->FUN_00e06e00((::S_00e06e00_A0 *)(item), (::S_00e06e00_A1 *)(b), (::S_00e06e00_A2 *)(c));
    reinterpret_cast<::FUN_00e07550_cls *>(this)->FUN_00e07550((::Arg1Flags *)(item), (::Arg2Layout *)(c));
    item->m_kRayEnd = m_buf->m_iElementCount;
    int r = m_buf->m_iElementCount - start;
    item->m_flag38 = 1;
    return r;
}
// @fnv 0x00e07ca0
int Handler::FUN_00e07ca0(Entry* first, Entry* second, Entry* third, char* flag)
{
    Entry* originalFirst = first;
    ::FUN_00e06b20((::Node *)this);
    int previous = unk10->unk0c;
    int value = ::ClassifyVec3Region((const ::Vec3 *)this);
    Entry* originalThird = third;
    reinterpret_cast<::KdQuantizer *>(this)->FUN_00e07880((const ::QuantNode *)(originalFirst), (const ::KdRegion *)(originalThird), (int *)(::Entry **)(&first), (int *)(::Entry **)(&third));
    reinterpret_cast<::S_00e07680 *>(this)->FUN_00e07680((int)(third), (int)(first), value, originalFirst->unk70->unk5c, originalFirst->unk74->unk5c);
    int difference = originalThird->unk34 - second->unk34;
    if (difference != 0)
        reinterpret_cast<::FUN_00e06d70_Class *>(this)->WriteSize(difference);
    reinterpret_cast<::fnv_00e06db0::FUN_00e06db0_class *>(this)->FUN_00e06db0((int *)(originalFirst), (::fnv_00e06db0::Node *)(second), (::fnv_00e06db0::Node *)(originalThird));
    reinterpret_cast<::FUN_00e07550_cls *>(this)->FUN_00e07550((::Arg1Flags *)(originalFirst), (::Arg2Layout *)(originalThird));
    if (*flag)
        reinterpret_cast<::FUN_00e06cb0_cls *>(this)->WritePacket((const ::Pkt *)(flag));
    originalFirst->unk5c = unk10->unk0c;
    originalFirst->unk38 = 1;
    return unk10->unk0c - previous;
}

// @fnv 0x00e07550
void FUN_00e07550_cls::FUN_00e07550(Arg1Flags* apFlags, Arg2Layout* apLayout)
{
    int i = 0;
    int* pHighValue = &apLayout->m_0c[0].m_ucHighNibble;
    int* volatile pBaseValue = apLayout->m_28;
    for (; i < 3; i++)
    {
        if (apFlags->m_3b[i] == 1)
        {
            int base = *pBaseValue;
            int shift = apLayout->m_24;
            unsigned char ucHighDelta = (unsigned char)(((pHighValue[0] - base) >> shift) + 1);
            unsigned char ucLowDelta = (unsigned char)((pHighValue[-1] - base) >> shift);
            EmitByte(m_10, ucHighDelta);
            EmitByte(m_10, ucLowDelta);
            EmitByte(m_10, (unsigned char)(i + 0x26));
        }
        if (apFlags->m_3b[i] == 2)
        {
            int hi = pHighValue[0];
            int lo = pHighValue[-1];
            reinterpret_cast<::BufferWriter *>((m_10))->WriteInt24(hi + 1);
            reinterpret_cast<::BufferWriter *>((m_10))->WriteInt24(lo);
            EmitByte(m_10, (unsigned char)(i + 0x29));
        }
        pHighValue += 2;
        pBaseValue++;
    }
}

extern "C" unsigned int __cdecl _rotl(unsigned int, int);

struct KdNode;
struct KdCtx;

struct KdCtx
{
    int level;
    char flag;
    char unk05;
    char unk06;
    char unk07;
    int shift;
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

};

struct KdNode
{
    int unk00;
    char leaf;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    float b[6];
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    char unk38;
    char a;
    char bb;
    char cc[3];
    char unk3e;
    char unk3f;
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
    KdNode* ch[2];
};

struct MyTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int lim;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    float f3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float f58;
    int unk5c;
    float f60[3];

    int Recurse(KdNode* n, KdCtx* a, KdCtx* c);
};

// Recursively returns a shift level for n: a value from f3c, f58 and f60 for a leaf, else the minimum over its children, setting bb on some nodes.
// @fnv 0x00e07160
int MyTree::Recurse(KdNode* apNode, KdCtx* a, KdCtx* c)
{
    int lo = c->shift;
    if (apNode->leaf)
    {
        float prev = f58;
        int i = 0;
        int pObj = _rotl(1, lo);
        float* pBounds = &apNode->b[0];
        float* p = f60;
        float q;
        for (; i < 3; i++, p++, pBounds += 2)
        {
            if (!apNode->a)
                apNode->cc[i] = 1;
            q = *p;
            float d = pBounds[1] - pBounds[0];
            if (d < q && q < prev)
            {
                d = f3c;
                int cp;
                cp = FUN_00cbfef0(d * q);
                if ((cp << 7) >= pObj)
                {
                    prev = q;
                }
                else if (!apNode->a)
                {
                    apNode->cc[i] = 2;
                }
            }
        }
        unsigned int cp = (unsigned int)FUN_00cbfef0(f3c * double(0.9f) * prev);
        int k = 0;
        while (cp)
        {
            cp >>= 1;
            ++k;
        }
        int v = k + 6;
        return v > lo ? v : lo;
    }
    if (!apNode->a && c->level < lim && ::FUN_00e07040((::S_00e07040_A *)this, (::S_00e07040_B *)(a)) > 2)
    {
        apNode->bb = 1;
    }
    S_00e07070_Result buf;
    if (apNode->bb == 1)
    {
        ::FUN_00e07070((::S_00e07070_Object *)this, (::S_00e07070_Object *)(a), (::S_00e07070_Result *)(c));
    }
    long r[2] = {-1, -1};
    long t = 0x7fffffff;
    KdNode* apChildren[2] = {apNode->ch[0], apNode->ch[1]};
    for (int i = 1; i >= 0; i--)
    {
        KdNode* k = apChildren[i];
        if (k)
        {
            KdCtx stCtx = *c;
            reinterpret_cast<::S_00e066f0 *>(&(stCtx))->CopyOffsets((const ::S_00e066f0_Src *)(k));
            reinterpret_cast<::FUN_00e094a0_cls *>(&(stCtx))->BuildScaledRanges((::FUN_00e094a0_floatset *)(k), reinterpret_cast<float*>(&unk30));
            stCtx.level = c->level + 1;
            stCtx.flag = 0;
            reinterpret_cast<::FUN_00e09540_Self *>(&(stCtx))->FUN_00e09540();
            r[i] = Recurse(k, c, &stCtx);
            if (t >= stCtx.shift)
                t = stCtx.shift;
        }
    }
    int iMin = lo + 2 < t + 2 ? lo + 2 : t + 2;
    int v;
    KdNode* best = apChildren[0];
    if (best)
    {
        v = r[0];
        if (apNode->a)
        {
            if (!best->a && v < iMin)
                best->bb = 1;
        }
        else if (v < lo)
        {
            best->bb = 1;
        }
        if (!best->bb && iMin >= v)
            iMin = v;
    }
    KdNode* pSecond = apChildren[1];
    if (pSecond)
    {
        v = r[1];
        if (apNode->a)
        {
            if (!pSecond->a && v < iMin)
                pSecond->bb = 1;
        }
        else if (v < lo)
        {
            pSecond->bb = 1;
        }
        if (!pSecond->bb && iMin >= v)
            iMin = v;
    }
    return iMin;
}

#include <xmmintrin.h>
struct FUN_00e07b90_bounds
{
    float unk00, unk04, unk08, minimumX, maximumX, minimumY, maximumY, minimumZ, maximumZ;
};
struct FUN_00e07b90_vector
{
    float x, y, z, w;
};
// Stores the minimum corner of bounds into result and sets result->w to a scale factor derived from the largest axis extent.
// @fnv 0x00e07b90
void FUN_00e07b90(const FUN_00e07b90_bounds* bounds, FUN_00e07b90_vector* result)
{
    __m128 minCorner = _mm_setr_ps(bounds->minimumX, bounds->minimumY, bounds->minimumZ, 0.0f);
    _mm_store_ps(&result->x, minCorner);
    float fLargestExtent = 0.0f;
    float extent = bounds->maximumX - bounds->minimumX;
    if (!(extent < ::_DAT_01012060))
        fLargestExtent = extent;
    extent = bounds->maximumY - bounds->minimumY;
    if (!(fLargestExtent > extent))
        fLargestExtent = extent;
    extent = bounds->maximumZ - bounds->minimumZ;
    if (!(fLargestExtent > extent))
        fLargestExtent = extent;
    result->w = 65536.0 * (254.0 / fLargestExtent);
}

struct S_00e07d60_Info
{
    float x;
    float y;
    float z;
    __m128 v;
    int i;
    char b;
};

struct S_00e07d60
{
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
    float x;
    float y;
    float z;
    __m128 v;
    int i;
    char b;
    void FUN_00e07d60(const S_00e07d60_Info& info);
};

// @fnv 0x00e07d60
void S_00e07d60::FUN_00e07d60(const S_00e07d60_Info& info)
{
    x = info.x;
    y = info.y;
    z = info.z;
    v = info.v;
    i = info.i;
    b = info.b;
}

namespace e083 {
struct Alloc;
struct Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    Alloc* unk10;
};
struct Pair
{
    int a;
    int b;
};
struct PairArray
{
    Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct SrcW
{
    PairArray* p;
};
}


// Copies all pairs from srcp to dst, adding delta to each pair's a field, growing dst when full.
// @fnv 0x00e08320
static __declspec(noinline) void FUN_00e08320(e083::PairArray* srcp, e083::PairArray* dst, int delta)
{
    e083::PairArray* const* pp = &srcp;
    e083::PairArray* src = *pp;
    for (int i = 0; i < src->m_iElementCount; i++)
    {
        e083::Router* h = (e083::Router*)getMemoryRouter();
        if (dst->m_iElementCount == (dst->m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(h->unk10), (::AudioStream *)(dst), 8);
        int n = dst->m_iElementCount;
        e083::Pair* out = dst->m_data + n;
        dst->m_iElementCount = n + 1;
        out->b = src->m_data[i].b;
        out->a = src->m_data[i].a + delta;
    }
}

void e08320_caller(e083::SrcW sw, e083::PairArray* dst, int delta)
{
    FUN_00e08320(sw.p, dst, delta);
}

struct BvAllocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(unsigned int);
    virtual void v8();
    virtual void vc();
    virtual void ReleaseBlock(void*, int);
};
inline BvAllocator& GetHeap()
{
    return *(BvAllocator*)getMemoryRouter()->allocator;
}
struct BvHeapRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    BvAllocator* allocator;
};
inline BvHeapRouter* GetBvRouter()
{
    return (BvHeapRouter*)getMemoryRouter();
}
template <class T> struct BvArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void clear()
    {
        for (int i = 0; i < m_iElementCount; ++i)
            m_data[i].~T();
        m_iElementCount = 0;
    }
    void ClearAndRelease(BvAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000u) == 0)
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void AddBack(Router& router, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(router.allocator), (::AudioStream *)(void *)(this), sizeof(T));
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < 1; i++)
            p[i] = t;
        m_iElementCount++;
    }
};

struct BvFixup
{
    int offset;
    int value;
};
struct FUN_00e065f0
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_pRayCursor;
    int m_offset;
    unsigned char* m_data;
    BvArray<BvFixup> m_buffer;

    FUN_00e065f0(unsigned int id) throw();
    void* operator new(size_t n)
    {
        FUN_00e065f0* p = static_cast<FUN_00e065f0*>(GetBvRouter()->allocator->AllocateMemoryBlock(n));
        p->m_usMemSizeAndFlags = (unsigned short)n;
        return p;
    }
public:
    FUN_00e065f0(int);
};

struct WriterEntry
{
    FUN_00e065f0* m_pStreamWriter;
    unsigned int m_iOwnerObjectOffset;
};

struct BvReferenceConverter
{
    virtual void v0();
    virtual int ConvertReferences(int*, int);
    virtual void writeBuffer(int*, int, unsigned char*);
};
struct BvTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    WriterEntry* m_entries;
    int unk14;
    int unk18;
    BvReferenceConverter* m_converter;
};

struct BvNode;

struct BvInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_uiEdgeIndex;
};

struct BvNode
{
    int unk00;
    bool m_isLeaf;
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
    int m_depth;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    BvInfo* m_info;
    int unk64;
    int unk68;
    int unk6c;
    BvNode* m_fMinimumU;
    BvNode* m_fMaximumU;
};

struct BvRange
{
    bool m_valid;
    int m_uiEdgeIndex;
    int unk08;
    int unk0c;
    int unk10;
};

static void FUN_00e08320(BvArray<BvFixup>* destination, BvArray<BvFixup>* source, int adjustment)
{
    for (int i = 0; i < source->m_iElementCount; ++i)
    {
        BvAllocator& heap = GetHeap();
        if (destination->m_iElementCount == destination->getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&heap), (::AudioStream *)(destination), sizeof(BvFixup));
        BvFixup* out = destination->m_data + destination->m_iElementCount;
        ++destination->m_iElementCount;
        out->value = source->m_data[i].value;
        out->offset = source->m_data[i].offset + adjustment;
    }
}
static int FUN_00e08380(BvTree* tree, FUN_00e065f0* source, BvArray<int>* refs, FUN_00e065f0* destination)
{
    int padding = (-source->m_offset) & 3;
    if (!tree->m_converter)
        refs->m_iElementCount = 0;
    if (refs->m_iElementCount)
    {
        int bytes = tree->m_converter->ConvertReferences(refs->m_data, refs->m_iElementCount);
        reinterpret_cast<::FUN_00e06a60_cls *>((destination))->FillWithPattern(bytes);
        Router* router = getMemoryRouter();
        unsigned char* temporary = static_cast<unsigned char*>(router->unk00);
        router->unk00 = temporary + ((bytes + 127) & ~127);
        tree->m_converter->writeBuffer(refs->m_data, refs->m_iElementCount, temporary);
        ::FUN_00cb1260(destination->m_data + destination->m_pRayCursor - destination->m_offset, temporary, bytes);
        getMemoryRouter()->unk00 = temporary;
    }
    int before = destination->m_offset;
    reinterpret_cast<::FUN_00e06a60_cls *>((destination))->FillWithPattern(source->m_offset + padding);
    ::FUN_00cb1260(destination->m_data + destination->m_pRayCursor - destination->m_offset,
                 source->m_data + source->m_pRayCursor - source->m_offset, source->m_offset);
    ::FUN_00e06480();
    FUN_00e08320(&destination->m_buffer, &source->m_buffer, destination->m_offset - source->m_offset);
    ::FUN_00e06480();
    return destination->m_offset - before;
}

struct BvBuilder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00e065f0* m_pStreamWriter;
    BvTree* m_iValueAt40;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_info30;

    void FUN_00e08470(BvNode* node);
    void FUN_00e08a60(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, int depth, BvArray<int>* refs);
};

// Recursively walks a BvNode: deep nodes go to a separate writer, leaves add their edge index to refs, other nodes recurse into both children.
// @fnv 0x00e08a60
void BvBuilder::FUN_00e08a60(BvNode* node, FUN_00e095d0_cls* parent, FUN_00e095d0_cls* stack, int depth,
                             BvArray<int>* refs)
{
    if (node->m_depth > 0 && !stack->m_04)
    {
        int depthValue = node->m_depth;
        FUN_00e065f0* saved = m_pStreamWriter;
        WriterEntry& entry = m_iValueAt40->m_entries[depthValue];
        {
            FUN_00e065f0 writer(entry.m_iOwnerObjectOffset);
            m_pStreamWriter = &writer;
            stack->m_04 = true;
            BvArray<int> subRefs;
            subRefs.m_data = 0;
            subRefs.m_iElementCount = 0;
            subRefs.m_iCapacityState = 0x80000000;
            FUN_00e08a60(node, parent, stack, depthValue, &subRefs);
            if (m_iValueAt40->m_converter != 0)
            {
                int offset = m_pStreamWriter->m_offset + 5;
                reinterpret_cast<::FUN_00e06c40_class *>(this)->FUN_00e06c40(offset + ((-offset) & 3), subRefs.m_iElementCount);
            }
            entry.m_pStreamWriter = new FUN_00e065f0(entry.m_iOwnerObjectOffset);
            FUN_00e08380(m_iValueAt40, m_pStreamWriter, &subRefs, entry.m_pStreamWriter);
            m_pStreamWriter->m_buffer.clear();
            subRefs.ClearAndRelease(GetHeap());
            reinterpret_cast<::SomeClass *>(&(writer))->Destroy();
        }
        m_pStreamWriter = saved;
        FUN_00e08470(node);
        return;
    }

    if (node->m_isLeaf)
    {
        reinterpret_cast<::S_e07c50 *>((node))->FUN_00e07c50((::S_e07c50_Item *)(parent), (int)(stack), {});
        const int& index = node->m_info->m_uiEdgeIndex;
        refs->AddBack(*getMemoryRouter(), index);
        return;
    }

    {
        BvRange range;
        FUN_00e095d0_cls child;
        range.m_valid = false;
        range.m_uiEdgeIndex = -1;
        reinterpret_cast<::E07510Solver *>(this)->FUN_00e07510((::E07510Input *)(node), parent, stack, &range);
        BvNode* right = node->m_fMaximumU;
        child.FUN_00e095d0(stack, (unsigned int)right, (unsigned int)&m_info30);
        FUN_00e08a60(right, stack, &child, depth, refs);
        BvNode* left = node->m_fMinimumU;
        child.FUN_00e095d0(stack, (unsigned int)left, (unsigned int)&m_info30);
        FUN_00e08a60(left, stack, &child, depth, refs);
        reinterpret_cast<::Handler *>(this)->FUN_00e07ca0((::Entry *)(node), (::Entry *)(parent), (::Entry *)(stack), (char *)(::BvRange *)(&range));
    }
}

template <class T> __forceinline void constructCopy(T* p, int n, const T& value)
{
    for (int i = 0; i < n; ++i)
        p[i] = value;
}
struct P154Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void*, unsigned);
};
struct P154System
{
    int unk00, unk04, unk08, unk0c;
    P154Allocator* allocator;
};
struct P154Memory
{
    static inline P154System* getMemoryRouter() { return static_cast<P154System*>(::FUN_00c85750()); }
};

struct P154Array
{
    int* data;
    int count;
    unsigned capacity;
    P154Array() : data(0), count(0), capacity(0x80000000)
    {}
    void append(const int& v)
    {
        P154System* s = P154Memory::getMemoryRouter();
        if (count == int(capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(s->allocator), (::AudioStream *)(void *)(this), 4);
        constructCopy(data + count, 1, v);
        ++count;
    }
    void insert(int* src, int pos, int n)
    {
        P154System* r = P154Memory::getMemoryRouter();
        P154Allocator* a = r->allocator;
        reinterpret_cast<::SearchObject *>(this)->Search((unsigned int)(a), pos, (unsigned int)(src), n);
    }
    void clear()
    {
        P154System* r = P154Memory::getMemoryRouter();
        P154Allocator* a = r->allocator;
        count = 0;
        if (!(capacity & 0x80000000))
            a->Free(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
public:
    void append(const int& v)
    {
        P154System* s = P154Memory::getMemoryRouter();
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream(s->allocator, this, 4);
        constructCopy(data + count, 1, v);
        ++count;
    }
};
struct P154Pair
{
    int first, second;
};
struct P154PairArray
{
    P154Pair* data;
    int count;
    unsigned capacity;
    P154Pair& grow()
    {
        P154System* s = P154Memory::getMemoryRouter();
        if (count == int(capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(s->allocator), (::AudioStream *)(void *)(this), 8);
        for (int i = 0; i < 1; ++i)
            new (data + count + i) P154Pair;
        return data[count++];
    }
public:
    P154Pair& grow()
    {
        P154System* s = P154Memory::getMemoryRouter();
        if (count == int(capacity & 0x3fffffff))
            ResizeAudioStream(s->allocator, this, 8);
        for (int i = 0; i < 1; ++i)
            new (data + count + i) P154Pair;
        return data[count++];
    }
};
struct P154Cost
{
    virtual void v00();
    virtual int cost(int*, int);
};
struct P154Settings
{
    int limit, unk04, unk08, unk0c;
    P154PairArray pairs;
    P154Cost* metric;
    int base;
};
struct P154Writer
{
    int unk00, unk04, unk08, count;
};
struct P154Region
{
    int depth;
    char leaf;
    int unk08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, context, unk38, unk3c, unk40, unk44;
};
struct P154Node
{
    int unk00;
    char leaf;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, index, unk44,
        unk48, unk4c, unk50, unk54, unk58, offset;
    int* values;
    int unk64, unk68, unk6c;
    P154Node* high;
    P154Node* low;
    __forceinline void shift(int amount, bool change)
    {
        if (change)
            offset += amount;
    }
};
__forceinline void adjustOffset(P154Node* node, int amount, bool change)
{
    if (change)
        node->offset += amount;
}
struct P154Result
{
    bool valid;
    int value;
    int unk08, unk0c, unk10;
};
struct P154Tree
{
    int unk00, unk04, unk08, unk0c;
    P154Writer* writer;
    P154Settings* settings;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int scale30, scale34, scale38;
    __forceinline int getCost(P154Array& a, int size)
    {
        int result = size;
        if (settings->metric && a.count)
            result += settings->metric->cost(a.data, a.count);
        return result;
    }
    int FUN_00e084f0(P154Node*, P154Region*, P154Region*, P154Array*);
};
// Recursively sizes node's children via writer->count with optional metric costs, collapses the costlier child while size reaches limit minus base, returns size.
// @fnv 0x00e084f0
int P154Tree::FUN_00e084f0(P154Node* node, P154Region* parent, P154Region* region, P154Array* output)
{
    int size;
    if (settings->metric)
        region->context = parent->context;
    if (node->leaf)
    {
        if (settings->metric)
            region->context = *node->values;
        int start = writer->count;
        reinterpret_cast<::S_e07c50 *>(this)->FUN_00e07c50((::S_e07c50_Item *)(node), (int)(parent), (int)(region));
        int leafSize = writer->count - start;
        output->append(*node->values);
        int value = *node->values;
        int result = leafSize;
        if (settings->metric)
            result += settings->metric->cost(&value, 1);
        return result;
    }
    else
    {
        P154Result info;
        info.valid = false;
        info.value = -1;
        reinterpret_cast<::E07510Solver *>(this)->FUN_00e07510((::E07510Input *)(node), parent, region, &info);
        region->context = parent->context;
        P154Array lowValues;
        P154Node* low = node->low;
        P154Region child = *region;
        reinterpret_cast<::S_00e066f0 *>(&(child))->CopyOffsets((const ::S_00e066f0_Src *)(low));
        reinterpret_cast<::FUN_00e094a0_cls *>(&(child))->BuildScaledRanges((::FUN_00e094a0_floatset *)(low), reinterpret_cast<float*>(&scale30));
        child.depth = region->depth + 1;
        child.leaf = false;
        reinterpret_cast<::FUN_00e09540_Self *>(&(child))->FUN_00e09540();
        int lowSize = writer->count;
        FUN_00e084f0(low, region, &child, &lowValues);
        lowSize = writer->count - lowSize;
        int lowCost = getCost(lowValues, lowSize);
        P154Array highValues;
        P154Node* high = node->high;
        child = *region;
        reinterpret_cast<::S_00e066f0 *>(&(child))->CopyOffsets((const ::S_00e066f0_Src *)(high));
        reinterpret_cast<::FUN_00e094a0_cls *>(&(child))->BuildScaledRanges((::FUN_00e094a0_floatset *)(high), reinterpret_cast<float*>(&scale30));
        child.depth = region->depth + 1;
        child.leaf = false;
        reinterpret_cast<::FUN_00e09540_Self *>(&(child))->FUN_00e09540();
        int highSize = writer->count;
        FUN_00e084f0(high, region, &child, &highValues);
        highSize = writer->count - highSize;
        int highCost = getCost(highValues, highSize);
        int splitSize = writer->count;
        reinterpret_cast<::Handler *>(this)->FUN_00e07ca0((::Entry *)(node), (::Entry *)(parent), (::Entry *)(region), (char *)(::P154Result *)(&info));
        splitSize = writer->count - splitSize;
        P154Array merged;
        merged.insert(lowValues.data, 0, lowValues.count);
        merged.insert(highValues.data, merged.count, highValues.count);
        size = highSize + splitSize + lowSize;
        if (settings->metric && merged.count)
            size += settings->metric->cost(merged.data, merged.count);
        bool highRemoved = false, lowRemoved = false;
        while (size >= settings->limit - settings->base)
        {
            int index = settings->pairs.count;
            P154Pair& pair = settings->pairs.grow();
            P154Node* selected;
            int oldSize, cost;
            if (highCost > lowCost)
            {
                selected = node->high;
                cost = highCost;
                oldSize = highSize;
                highCost = 5;
                highRemoved = true;
                size = lowRemoved ? splitSize + 10 : splitSize + lowCost + 5;
            }
            else
            {
                selected = node->low;
                cost = lowCost;
                oldSize = lowSize;
                lowCost = 5;
                lowRemoved = true;
                size = highRemoved ? splitSize + 10 : splitSize + highCost + 5;
            }
            pair.second = settings->base + cost + 5;
            selected->index = index;
            writer->count += 5 - oldSize;
            P154Node* lowChild = node->low;
            if (lowRemoved)
                lowChild->offset += 5 - oldSize;
            node->high->offset += 5 - oldSize;
            node->offset += 5 - oldSize;
        }
        output->count = 0;
        if (!lowRemoved)
            output->insert(lowValues.data, 0, lowValues.count);
        if (!highRemoved)
            output->insert(highValues.data, output->count, highValues.count);
        merged.clear();
        highValues.clear();
        lowValues.clear();
    }
    return size;
}

namespace fnv_00e08240 {
struct PairEntry
{
    void* m_pHeadNode;
    void* m_iSecondInteger;
};

struct PairList
{
    PairEntry* m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

static inline AllocHolder* getMemoryRouter() { return static_cast<AllocHolder*>(::FUN_00c85750()); }

struct SlotPair
{
    int m_00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
};

struct Ctx
{
    int unk00;
    PairList m_kNode;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
};

struct Node
{
    int unk00;
    unsigned char m_04;
    unsigned char unk05;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    int m_28;
    int unk2C;
    int unk30;
    int unk34;
    unsigned char m_38;
    unsigned char unk39;
    unsigned short unk3A;
    int unk3C;
    int m_40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    SlotPair* m_60;
    int unk64;
    int unk68;
    int unk6C;
    Node* m_70;
    Node* m_74;
};

struct FUN_00e08240_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Ctx* m_14;
    int FUN_00e08240(Node* a1, int a2, int a3);
};

// Recursively visits a1's m_74 and m_70 children, setting m_24/m_28 and, when m_04 is set, appending a pair entry to the context list; returns an index.
// @fnv 0x00e08240
int FUN_00e08240_cls::FUN_00e08240(Node* apNode, int a2, int aiIndex)
{
    int* pIndex = &aiIndex;
    int idx = aiIndex;
    volatile int* pv = &aiIndex;
    *pv = idx;
    int hi = apNode->m_40;
    apNode->m_38 = 0;
    if (hi >= 0)
    {
        idx = 0;
    }
    else
    {
        hi = a2;
    }
    if (this->m_14->m_1c != 0)
    {
        apNode->m_24 = idx;
    }
    if (apNode->m_04 != 0)
    {
        if (this->m_14->m_1c != 0)
        {
            SlotPair* slot = apNode->m_60;
            slot->m_10 = slot->m_00;
            PairList* list = &this->m_14->m_kNode;
            AllocHolder* holder = getMemoryRouter();
            if (list->m_uiItemCount == (int)(list->m_capBits & 0x3fffffff))
            {
                ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(list), 8);
            }
            PairEntry* e = &list->m_data[list->m_uiItemCount];
            list->m_uiItemCount++;
            hi = (hi * 256) | idx;
            e->m_iSecondInteger = (void*)hi;
            e->m_pHeadNode = (void*)apNode->m_60->m_00;
            apNode->m_60->m_00 = idx;
            idx++;
        }
    }
    else
    {
        Node* f = apNode->m_74;
        int r = this->FUN_00e08240(f, hi, idx);
        Node* g = apNode->m_70;
        idx = this->FUN_00e08240(g, hi, r);
    }
    if (this->m_14->m_1c != 0)
    {
        apNode->m_24 = 0;
        apNode->m_28 = idx;
    }
    if (apNode->m_40 < 0)
    {
        return idx;
    }
    return aiIndex;
}
}  // namespace fnv_00e08240

namespace fnv_00e08470 {
struct S_00e08470_Context
{
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
    char unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    void* unk5c;
};

struct S_00e08470_Entry
{
    void* unk00;
    int unk04;
};

struct S_00e08470_Vector
{
    S_00e08470_Entry* unk00;
    int unk04;
    int unk08;
};

struct S_00e08470_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
};

struct S_00e08470_Data
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0c;
    S_00e08470_Holder* unk10;
    S_00e08470_Vector unk14;

};

static inline S_00e08470_Holder* getMemoryRouter() { return static_cast<S_00e08470_Holder*>(::FUN_00c85750()); }

struct S_00e08470_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00e08470_Data* unk10;

    int FUN_00e08470(S_00e08470_Context*);
};

// Calls FUN_00e06c20 with context->unk40, records the new pointer and unk40 in a vector entry, and returns its difference from the old pointer.
// @fnv 0x00e08470
int S_00e08470_Class::FUN_00e08470(S_00e08470_Context* context)
{
    void* saved = this->unk10->unk0c;

    reinterpret_cast<::E06C20Object *>((this))->FUN_00e06c20((void *)(context->unk40));

    void* current = this->unk10->unk0c;

    context->unk5c = current;
    context->unk38 = 1;

    S_00e08470_Vector* vector = &this->unk10->unk14;

    S_00e08470_Holder* holder = getMemoryRouter();

    if (vector->unk04 == (vector->unk08 & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(holder->unk10), (::AudioStream *)(vector), 8);
    }

    S_00e08470_Entry* entry = vector->unk00 + vector->unk04;
    ++vector->unk04;

    entry->unk04 = context->unk40;
    entry->unk00 = current;

    ::FUN_00e06480();

    return (unsigned int)current - (unsigned int)saved;
}
}  // namespace fnv_00e08470

struct CodeCopySource : FUN_00e065f0
{
};

// Writes converter-produced reference data and then source's data into destination, adjusts fixups, and returns how far destination's offset grew.
// @fnv 0x00e08380
static __declspec(noinline) int FUN_00e08380(BvTree* tree, CodeCopySource* source, BvArray<int>* refs,
                                             FUN_00e065f0* destination)
{
    int padding = (-source->m_offset) & 3;
    if (!tree->m_converter)
        refs->m_iElementCount = 0;
    if (refs->m_iElementCount)
    {
        int* data = refs->m_data;
        int count = refs->m_iElementCount;
        int bytes = tree->m_converter->ConvertReferences(data, count);
        reinterpret_cast<::FUN_00e06a60_cls *>((destination))->FillWithPattern(bytes);
        Router* router = getMemoryRouter();
        unsigned char* temporary = static_cast<unsigned char*>(router->unk00);
        router->unk00 = temporary + ((bytes + 127) & ~127);
        tree->m_converter->writeBuffer(refs->m_data, refs->m_iElementCount, temporary);
        ::FUN_00cb1260(destination->m_data + destination->m_pRayCursor - destination->m_offset, temporary, bytes);
        getMemoryRouter()->unk00 = temporary;
    }
    int before = destination->m_offset;
    reinterpret_cast<::FUN_00e06a60_cls *>((destination))->FillWithPattern(source->m_offset + padding);
    ::FUN_00cb1260(destination->m_data + destination->m_pRayCursor - destination->m_offset,
                 source->m_data + source->m_pRayCursor - source->m_offset, source->m_offset);
    ::FUN_00e06480();
    FUN_00e08320(&destination->m_buffer, &source->m_buffer, destination->m_offset - source->m_offset);
    ::FUN_00e06480();
    return destination->m_offset - before;
}

int copy_code_caller(BvTree* tree, CodeCopySource* source, BvArray<int>* refs, FUN_00e065f0* destination)
{
    return FUN_00e08380(tree, source, refs, destination);
}

struct ObjectWriter
{
    int unk00;
    int unk04;
    int m_cap;
    int m_pos;
    char* m_data;
    int unk14;
    int unk18;
    int unk1c;

    void FUN_00e065f0(int size) throw();
    ObjectWriter(int size) throw()
    {
        ::new ((void *)this) ::FUN_00e065f0(size);
    }
    ~ObjectWriter() throw()
    {
        reinterpret_cast<::SomeClass *>(this)->Destroy();
    }
};

struct HelperEntry
{
    ObjectWriter* ptr;
    int pos;
};

struct EntryArray
{
    HelperEntry* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct AssemblerHelper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryArray m_entries;
    int unk1C;
};

template <typename T> struct MyArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline MyArray() throw()
    {
        memset(this, 0, 8);
        m_iCapacityState = 0x80000000;
    }
    __forceinline ~MyArray() throw()
    {
        AudioHolder* holder = (AudioHolder*)getMemoryRouter();
        AudioAllocator* alloc = holder->m_pAllocator;
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            alloc->FreeArray(m_data, (m_iCapacityState & 0x3fffffff) * 4);
    }
    __forceinline void ClearAndRelease() throw()
    {
        AudioAllocator* alloc = ((AudioHolder*)getMemoryRouter())->m_pAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if (!(cap & 0x80000000))
        {
            int bytes = (cap & 0x3fffffff) * 4;
            alloc->FreeArray(m_data, bytes);
        }
        m_data = 0;
        m_iElementCount = 0;
    }
};

struct __declspec(align(8)) MyBounds
{
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
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

};

struct __declspec(align(8)) MyRegion : public MyBounds
{
    int lo48_0;
    int lo48_1;
    int lo48_2;
    int hi54_0;
    int hi54_1;
    int hi54_2;

};

extern "C" void __cdecl FUN_00e08380(AssemblerHelper*, ObjectWriter*, void*) throw();

struct Tree : public FUN_00e09640_class
{
    virtual void vf04() throw();
    virtual void vf08() throw();
    virtual void vf0c() throw();
    virtual void vf10() throw();
    virtual void FUN_00e08cc0(S_00e07da0_Node* node, int arg2, int arg3);
    virtual void vf18(S_00e07da0_Node* node, void* p) throw();

    int unk08;
    int unkC;
    ObjectWriter* m_stream;
    AssemblerHelper* m_pAssemblerHelper;
    int unk18;
    int unk1C;
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

};

typedef void(* Vf18Fn)(Tree*, S_00e07da0_Node*, void*) throw();

// Sets up MyBounds and MyRegion state for node, then writes node data into streams via m_pAssemblerHelper if present, else calls FUN_00e08040.
// @fnv 0x00e08cc0
void Tree::FUN_00e08cc0(S_00e07da0_Node* node, int arg2, int arg3)
{
    MyRegion p;
    MyBounds s;
    MyBounds x;
    MyRegion n;

    this->unkC = arg2;
    this->unk24 = arg3;
    this->unk28 = 0;
    this->vf18(node, &this->unk30);
    if (!node)
        return;

    this->unk18 = 0;
    unsigned int bits = node->unk28;
    while (bits != 0)
    {
        bits >>= 1;
        ++this->unk18;
    }

    this->unk1C = this->unk18 >> 1;
    this->unk18 = ((this->unk18 / this->unk70) + 2) * this->unk70 - 1;

    reinterpret_cast<::FUN_00e094a0_cls *>(&(s))->BuildScaledRanges((::FUN_00e094a0_floatset *)(node), (float *)(void *)(&this->unk30));
    s.unk24 = 0x10;
    s.unk30 = 0;
    s.unk2c = 0;
    s.unk28 = 0;
    s.unk00 = -1;
    s.unk34 = 0;
    s.unk04 = 0;
    reinterpret_cast<::S_00e066f0 *>(&(s))->CopyOffsets((const ::S_00e066f0_Src *)(node));
    reinterpret_cast<::FUN_00e09540_Self *>(&(s))->FUN_00e09540();

    (MyBounds&)p = s;
    reinterpret_cast<::S_00e066f0 *>(&(p))->CopyOffsets((const ::S_00e066f0_Src *)(node));
    reinterpret_cast<::FUN_00e094a0_cls *>(&(p))->BuildScaledRanges((::FUN_00e094a0_floatset *)(node), (float *)(void *)(&this->unk30));
    p.unk00 = s.unk00 + 1;
    p.unk04 = 0;
    reinterpret_cast<::FUN_00e09540_Self *>(&(p))->FUN_00e09540();

    reinterpret_cast<::MyTree *>((this))->Recurse((::KdNode *)(node), (::KdCtx *)(::MyBounds *)(&s), (::KdCtx *)(::MyRegion *)(&p));

    reinterpret_cast<::FUN_00e094a0_cls *>(&(p))->BuildScaledRanges((::FUN_00e094a0_floatset *)(node), (float *)(void *)(&this->unk30));
    p.unk24 = 0x10;
    p.unk30 = 0;
    p.unk2c = 0;
    p.unk28 = 0;
    p.unk00 = -1;
    p.unk34 = 0;
    p.unk04 = 0;
    reinterpret_cast<::S_00e066f0 *>(&(p))->CopyOffsets((const ::S_00e066f0_Src *)(node));
    reinterpret_cast<::FUN_00e09540_Self *>(&(p))->FUN_00e09540();

    (MyBounds&)n = (MyBounds&)p;
    reinterpret_cast<::S_00e066f0 *>(&(n))->CopyOffsets((const ::S_00e066f0_Src *)(node));
    reinterpret_cast<::FUN_00e094a0_cls *>(&(n))->BuildScaledRanges((::FUN_00e094a0_floatset *)(node), (float *)(void *)(&this->unk30));
    n.unk00 = p.unk00 + 1;
    n.unk04 = 0;
    reinterpret_cast<::FUN_00e09540_Self *>(&(n))->FUN_00e09540();
    reinterpret_cast<::S_00e07da0_Tree *>((this))->BuildRegion(node, (::S_00e07da0_Region *)(::MyRegion *)(&p), (::S_00e07da0_Region *)(::MyRegion *)(&n));

    x = s;
    reinterpret_cast<::S_00e066f0 *>(&(x))->CopyOffsets((const ::S_00e066f0_Src *)(node));
    reinterpret_cast<::FUN_00e094a0_cls *>(&(x))->BuildScaledRanges((::FUN_00e094a0_floatset *)(node), (float *)(void *)(&this->unk30));
    x.unk00 = s.unk00 + 1;
    x.unk04 = 0;
    reinterpret_cast<::FUN_00e09540_Self *>(&(x))->FUN_00e09540();

    if (!this->m_pAssemblerHelper)
    {
        reinterpret_cast<::fnv_00e08040::TreeOptimizer *>((this))->OptimizeTree((::fnv_00e08040::Node *)(node), &s, (::fnv_00e08040::State *)(::MyBounds *)(&x));
        return;
    }

    node->info.unk8 = 0;
    {
        EntryArray& entries = this->m_pAssemblerHelper->m_entries;
        Router* router = getMemoryRouter();
        if (entries.m_iElementCount == (entries.m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(router->allocator), (::AudioStream *)(void *)(&entries), 8);
        entries.m_iElementCount++;
    }

    ObjectWriter* saved = this->m_stream;
    reinterpret_cast<::FUN_00e095d0_cls *>(&(p))->FUN_00e095d0((::FUN_00e095d0_cls *)(::MyBounds *)(&s), (unsigned int)(node), (unsigned int)(&this->unk30));

    MyArray<unsigned int> arr1;
    {
        ObjectWriter stream1(0x100000);
        this->m_stream = &stream1;
        reinterpret_cast<::P154Tree *>((this))->FUN_00e084f0((::P154Node *)(node), (::P154Region *)(::MyBounds *)(&s), (::P154Region *)(::MyRegion *)(&p), (::P154Array *)(void *)(&arr1));
        reinterpret_cast<::fnv_00e08240::FUN_00e08240_cls *>((this))->FUN_00e08240((::fnv_00e08240::Node *)(node), node->info.unk8, 0);
    }

    arr1.ClearAndRelease();
    arr1.m_iCapacityState = 0x80000000;
    {
        ObjectWriter stream2(0x100000);
        this->m_stream = &stream2;
        reinterpret_cast<::BvBuilder *>((this))->FUN_00e08a60((::BvNode *)(node), (::FUN_00e095d0_cls *)(::MyBounds *)(&s), (::FUN_00e095d0_cls *)(::MyBounds *)(&x), node->info.unk8, (::BvArray<int> *)(void *)(&arr1));
        if (this->m_pAssemblerHelper->unk1C)
        {
            int pos = this->m_stream->m_pos + 5;
            reinterpret_cast<::FUN_00e06c40_class *>((this))->FUN_00e06c40(pos + (-pos & 3), arr1.m_iElementCount);
        }
        this->m_stream = saved;
        FUN_00e08380(this->m_pAssemblerHelper, &stream2, &arr1);
        HelperEntry* entry = &this->m_pAssemblerHelper->m_entries.m_data[node->info.unk8];
        ObjectWriter* w = this->m_stream;
        entry->ptr = w;
        reinterpret_cast<::FUN_00c90510_class *>((w))->FUN_00c90510();
        entry->pos = this->m_stream->m_pos;
    }
}

// Moved from hkpmoppdefaultassembler_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
void FUN_00e07b90(const FUN_00e07b90_bounds* bounds, FUN_00e07b90_vector* result);
void __cdecl ResizeAudioStream(e083::Alloc* a, void* arr, int elemSize);
static void FUN_00e08320(e083::PairArray* srcp, e083::PairArray* dst, int delta);
void e08320_caller(e083::SrcW sw, e083::PairArray* dst, int delta);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> struct BvArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void clear()
    {
        for (int i = 0; i < m_iElementCount; ++i)
            m_data[i].~T();
        m_iElementCount = 0;
    }
    void ClearAndRelease(BvAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000u) == 0)
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void AddBack(Router& router, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.allocator, this, sizeof(T));
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < 1; i++)
            p[i] = t;
        m_iElementCount++;
    }
};
static void FUN_00e08320(BvArray<BvFixup>* destination, BvArray<BvFixup>* source, int adjustment)
{
    for (int i = 0; i < source->m_iElementCount; ++i)
    {
        BvAllocator& heap = GetHeap();
        if (destination->m_iElementCount == destination->getCapacity())
            ResizeAudioStream(&heap, destination, sizeof(BvFixup));
        BvFixup* out = destination->m_data + destination->m_iElementCount;
        ++destination->m_iElementCount;
        out->value = source->m_data[i].value;
        out->offset = source->m_data[i].offset + adjustment;
    }
}
static int FUN_00e08380(BvTree* tree, FUN_00e065f0* source, BvArray<int>* refs, FUN_00e065f0* destination);
void __cdecl ResizeAudioStream(P154Allocator*, void*, int);

typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef size_t hk_size_t;
class FinishingFlag
{
  public:
    FinishingFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
class hkClass;
class hkBool
{
  public:
    typedef char CompileTimeTrueType;
    inline hkBool& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }

  private:
    char m_cBooleanValue;
};
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    hkEnum()
    {}
    hkEnum(ENUM e)
    {
        m_kStorage = static_cast<STORAGE>(e);
    }

  private:
    STORAGE m_kStorage;
};
template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline ValueWrapper()
    {}

  private:
    TYPE m_kStorage;
};
template <typename T> struct TypeSizeConstant
{
    enum
    {
        val = sizeof(T)
    };
};
class hkMemoryAllocator
{
  public:
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes) = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    template <typename TYPE> inline TYPE* _bufAlloc(int& reqNumInOut)
    {
        const int SIZE_ELEM = TypeSizeConstant<TYPE>::val;
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<TYPE*>(p);
    }

  public:
    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };
};
struct StringPointerTriple
{
  public:
    __forceinline StringPointerTriple();

  protected:
    ValueWrapper<void*> m_next;
    ValueWrapper<void*> m_kRayStart;
    ValueWrapper<void*> m_kRayEnd;
};
class NineIntegerRecord
{
  public:
    typedef hkMemoryAllocator Allocator;
    static NineIntegerRecord& __cdecl GetMonitorStream();
    inline Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    StringPointerTriple m_aiEntries;
    Allocator* m_pTemp;
    Allocator* m_pStreamAllocator;
    Allocator* m_pDebugAllocator;
};
class hkBaseObject
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    __forceinline hkBaseObject()
    {}
};
class hkReferencedObject : public hkBaseObject
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    __forceinline hkReferencedObject();
    virtual ~hkReferencedObject()
    {}

  public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };
    hkUint16 m_usMemSizeAndFlags;
    mutable hkInt16 m_sReferenceCount;

  public:
    hkReferencedObject(class FinishingFlag flag)
    {}
};
__forceinline hkReferencedObject::hkReferencedObject() : m_sReferenceCount(1)
{}
template <bool N> struct BooleanTypeConstant
{
    typedef BooleanTypeConstant<N> type;
    enum
    {
        result = N
    };
};
typedef BooleanTypeConstant<true> hkTypeIsPod;
struct RouterHeapAllocatorProvider
{
    hkMemoryAllocator& get(const void*)
    {
        return NineIntegerRecord::GetMonitorStream().heap();
    }
};
template <typename T> class HavokElementArray
{
  public:
    typedef HavokElementArray<T> ThisType;
    __forceinline HavokElementArray();

  protected:
    __forceinline HavokElementArray(const HavokElementArray& a)
    {
        ;
    }

  public:
    __forceinline void _useExternalArray(T*, int cap);
    __forceinline T& operator[](int i);
    __forceinline void setOwnedData(T* ptr, int size, int capacity);

  protected:
    __forceinline HavokElementArray<T>& copyFromArray(hkMemoryAllocator&, const HavokElementArray<T>& src, hkTypeIsPod);

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };

  protected:
    friend class hkStatisticsCollector;
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

  public:
    HavokElementArray(FinishingFlag f)
    {}
};
template <typename T, typename Allocator = RouterHeapAllocatorProvider> class hkArray : public HavokElementArray<T>
{
  public:
    typedef Allocator AllocatorType;
    __forceinline hkArray() : HavokElementArray<T>()
    {}
    explicit __forceinline hkArray(int size);

  protected:
    __forceinline hkArray(const hkArray& a);

  public:
    __forceinline hkArray& operator=(const HavokElementArray<T>& a);
};
template <typename T> __forceinline T& HavokElementArray<T>::operator[](int i)
{
    ;
    return m_data[i];
}
template <typename T>
__forceinline HavokElementArray<T>::HavokElementArray() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
{}
template <typename T> void HavokElementArray<T>::setOwnedData(T* ptr, int size, int capacity)
{
    ;
    ;
    m_data = ptr;
    m_iElementCount = size;
    m_iCapacityState = capacity;
}
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::hkArray(int n) : HavokElementArray<T>()
{
    hkMemoryAllocator& a = Allocator().get(this);
    T* p = n ? a._bufAlloc<T>(n) : 0;
    int cap = n ? n : HavokElementArray<T>::DONT_DEALLOCATE_FLAG;
    HavokElementArray<T>::setOwnedData(p, n, cap);
}
typedef float hkReal;
typedef __m128 hkQuadReal;
class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
class hkVector4
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w = 0);
    __forceinline void setZero4();
    __forceinline VectorComponentValue dot3(const hkVector4& a) const;
    __forceinline VectorComponentValue lengthInverse3() const;
    __forceinline void normalize3();

  private:
    hkQuadReal m_vComponents;

  public:
    operator hkQuadReal() const
    {
        return m_vComponents;
    }
};
inline void hkVector4::set(hkReal a, hkReal b, hkReal c, hkReal d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}
inline VectorComponentValue hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
inline VectorComponentValue hkVector4::lengthInverse3() const
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = this->dot3(*this).getQuad();
    const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal approx = _mm_rsqrt_ss(len2);
    const hkQuadReal refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}
inline void hkVector4::normalize3()
{
    hkQuadReal lenInv = lengthInverse3().broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}
class hkpMoppCode : public hkReferencedObject
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    enum BuildType
    {
        BUILT_WITH_CHUNK_SUBDIVISION,
        BUILT_WITHOUT_CHUNK_SUBDIVISION,
        BUILD_NOT_SET
    };
    struct CodeInfo
    {
        __forceinline void* __cdecl operator new(std::size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(hkpMoppCode::CodeInfo));
            }
        }
        __forceinline void* __cdecl operator new(std::size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](std::size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        static const struct ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;
        inline hkReal getScale() const;
        inline void setScale(hkReal inVal);
        hkVector4 m_offset;
    };

  public:
    hkpMoppCode()
    {
        m_info.m_offset.setZero4();
        m_eBuildType = BUILD_NOT_SET;
    }

  public:
    struct CodeInfo m_info;
    hkArray<hkUint8> m_data;
    hkEnum<BuildType, hkInt8> m_eBuildType;
};
class hkpMoppMediator;
class hkpMoppNodeMgr;
class hkpMoppCodeGenerator;
class MoppBuildComponent;
struct MoppSplitPlane
{
    hkVector4 m_direction;
    hkReal m_fSplitOffset;
    int m_uiEdgeIndex;
};
class hkpMoppAssembler : public hkReferencedObject
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    struct MoppAssemblerSettings
    {
        __forceinline void* __cdecl operator new(std::size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(
                    p, sizeof(hkpMoppAssembler::MoppAssemblerSettings));
            }
        }
        __forceinline void* __cdecl operator new(std::size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](std::size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        MoppAssemblerSettings()
            : m_fFirstParameter(0.5f), m_fSecondaryScalar(0.2f), m_fTertiaryScalar(1.0f), m_iIntegerParameter(5)
        {
            m_kParameterVector.set(0.2f, 0.2f, 0.05f, 0.0f);
            m_bOptionEnabled = true;
        }
        hkReal m_fFirstParameter;
        hkReal m_fSecondaryScalar;
        hkReal m_fTertiaryScalar;
        hkVector4 m_kParameterVector;
        int m_iIntegerParameter;
        hkBool m_bOptionEnabled;
    };
};
class FUN_00e090c0 : public hkpMoppAssembler
{
  public:
    FUN_00e090c0(const MoppAssemblerSettings& ap, hkpMoppCodeGenerator* code, hkpMoppMediator* mediator);
    ~FUN_00e090c0();
    hkpMoppMediator* m_pMoppMediator;
    hkpMoppNodeMgr* m_pNodeManager;
    hkpMoppCodeGenerator* m_pMoppCode;
    MoppBuildComponent* m_pAdditionalAssemblerData;
    int m_iFirstValue;
    int m_iSecondValue;
    int m_iThirdValue;
    hkpMoppCode::CodeInfo m_kMoppInfo;
    hkArray<MoppSplitPlane, RouterHeapAllocatorProvider> kMoppArray;
    MoppAssemblerSettings m_params;
};
// @fnv 0x00e090c0
FUN_00e090c0::FUN_00e090c0(const MoppAssemblerSettings& ap, hkpMoppCodeGenerator* code, hkpMoppMediator* mediator)
    : kMoppArray(13)
{
    kMoppArray[0].m_direction.set(1.0f, 0.0f, 0.0f, 0.0f);
    kMoppArray[1].m_direction.set(0.0f, 1.0f, 0.0f, 0.0f);
    kMoppArray[2].m_direction.set(0.0f, 0.0f, 1.0f, 0.0f);
    kMoppArray[0].m_fSplitOffset = 0.0f;
    kMoppArray[1].m_fSplitOffset = 0.0f;
    kMoppArray[2].m_fSplitOffset = 0.0f;
    kMoppArray[3].m_direction.set(0.0f, 1.0f, 1.0f, 0.0f);
    kMoppArray[4].m_direction.set(1.0f, 0.0f, 1.0f, 0.0f);
    kMoppArray[5].m_direction.set(1.0f, 1.0f, 0.0f, 0.0f);
    kMoppArray[3].m_fSplitOffset = 0.2f;
    kMoppArray[4].m_fSplitOffset = 0.2f;
    kMoppArray[5].m_fSplitOffset = 0.2f;
    kMoppArray[6].m_direction.set(0.0f, 1.0f, -1.0f, 0.0f);
    kMoppArray[7].m_direction.set(1.0f, 0.0f, -1.0f, 0.0f);
    kMoppArray[8].m_direction.set(1.0f, -1.0f, 0.0f, 0.0f);
    kMoppArray[6].m_fSplitOffset = 0.25f;
    kMoppArray[7].m_fSplitOffset = 0.25f;
    kMoppArray[8].m_fSplitOffset = 0.25f;
    kMoppArray[9].m_direction.set(1.0f, 1.0f, 1.0f, 0.0f);
    kMoppArray[10].m_direction.set(1.0f, 1.0f, -1.0f, 0.0f);
    kMoppArray[11].m_direction.set(1.0f, -1.0f, 1.0f, 0.0f);
    kMoppArray[12].m_direction.set(1.0f, -1.0f, -1.0f, 0.0f);
    kMoppArray[9].m_fSplitOffset = 0.3f;
    kMoppArray[10].m_fSplitOffset = 0.32f;
    kMoppArray[11].m_fSplitOffset = 0.32f;
    kMoppArray[12].m_fSplitOffset = 0.34f;
    for (int i = 0; i < 13; i++)
    {
        kMoppArray[i].m_direction.normalize3();
        kMoppArray[i].m_uiEdgeIndex = i;
    }
    reinterpret_cast<::S_00e07d60 *>(this)->FUN_00e07d60((const ::S_00e07d60_Info &)(ap));
    m_pMoppCode = code;
    m_pMoppMediator = mediator;
    m_pNodeManager = 0;
}

// Moved from hkpmoppdefaultassembler_rtm_variant.cpp (VEGAS-15).
static int FUN_00e08380(BvTree* tree, CodeCopySource* source, BvArray<int>* refs, FUN_00e065f0* destination);
int copy_code_caller(BvTree* tree, CodeCopySource* source, BvArray<int>* refs, FUN_00e065f0* destination);

typedef __m128 E078Quad;

struct ScalarLane
{
    E078Quad data;
    __forceinline ScalarLane(float x)
    {
        data = _mm_load_ss(&x);
    }
    __forceinline E078Quad splat() const
    {
        return _mm_shuffle_ps(data, data, 0);
    }
};

struct hkVector4Unaligned
{
    hkReal x, y, z, w;
};

union hkVector4Copy
{
    hkVector4Unaligned m_v;
    E078Quad m_q;
};

hkReal FUN_00cbfd80(hkReal f);
int FUN_00cbfe20(hkReal f);
extern "C" const double DAT_010ea5c0;

struct QuantNode
{
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
    const hkVector4* m_vHitNormal;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
};

struct KdRegion
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_iIndex;
    int m_offset[3];
};

struct KdQuantizer
{
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
    hkVector4Unaligned m_vRayOrigins;

    void FUN_00e07880(const QuantNode* node, const KdRegion* region, int* hiOut, int* loOut);
};

static __forceinline int toCell(hkReal scale, double x)
{
    return FUN_00cbfef0(FUN_00cbfd80(x * scale));
}

static __forceinline int clampIndex(int i)
{
    if (i <= 0)
    {
        return 0;
    }
    if (i >= 255)
    {
        return 255;
    }
    return i;
}

// @fnv 0x00e07880
void KdQuantizer::FUN_00e07880(const QuantNode* node, const KdRegion* region, int* hiOut, int* loOut)
{
    const hkReal* n = &node->m_vHitNormal->m_vComponents[0];
    int numNonZero = 0;
    int numNegative = 0;
    int axis = 0;
    for (int i = 0; i < 3; i++)
    {
        hkReal c = n[i];
        if (c != 0.0f)
        {
            numNonZero++;
            axis = i;
            if (c < 0.0f)
            {
                numNegative++;
            }
        }
    }

    double minDist = node->m_kMinimumCorner;
    double maxDist = node->m_kMaximumCorner;

    if (numNonZero == 1)
    {
        const hkReal* origin = &m_vRayOrigins.x;
        int lo = toCell(m_vRayOrigins.w, minDist - origin[axis]);
        int hi = toCell(m_vRayOrigins.w, maxDist - origin[axis]);
        int offset = region->m_offset[axis];
        lo = (lo - offset) >> region->m_iIndex;
        hi = ((hi - offset) >> region->m_iIndex) + 1;
        lo = clampIndex(lo);
        hi = clampIndex(hi);
        *loOut = lo;
        *hiOut = hi;
        if (*loOut < 0)
        {
            *loOut = 0;
        }
        return;
    }

    hkReal scale = m_vRayOrigins.w;
    hkVector4Copy origin;
    origin.m_v = m_vRayOrigins;

    hkVector4 p;
    p.set((hkReal)region->m_offset[0], (hkReal)region->m_offset[1], (hkReal)region->m_offset[2], 0.0f);
    p.mul4(1.0f / scale);
    p.add4(origin.m_q);
    double d = p.dot3(*node->m_vHitNormal);

    hkReal cellSize = (hkReal)(1 << region->m_iIndex);
    double lo = (minDist - d) * m_vRayOrigins.w / cellSize;
    maxDist = (maxDist - d) * m_vRayOrigins.w / cellSize;

    double stretch = 1.0;
    double norm = 1.0;
    if (numNonZero == 2)
    {
        stretch = 1.4142135381698608;
        norm = 0.5;
    }
    else if (numNonZero == 3)
    {
        stretch = DAT_010ea5c0;
        norm = 0.3333333432674408;
    }

    double dlo = lo * stretch;
    maxDist *= stretch;
    if (numNegative)
    {
        dlo += numNegative * 255;
        maxDist += numNegative * 255;
    }

    int ilo = FUN_00cbfe20((hkReal)(dlo * norm));
    int ihi = FUN_00cbfe20((hkReal)(maxDist * norm)) + 1;
    ilo = clampIndex(ilo);
    ihi = clampIndex(ihi);
    *loOut = ilo;
    *hiOut = ihi;
}
#include "generated/data/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler.inc"
#include "generated/data/havok/physics/internal/collide/mopp/builder/assembler/hkpmoppdefaultassembler_rtm_variant.inc"
