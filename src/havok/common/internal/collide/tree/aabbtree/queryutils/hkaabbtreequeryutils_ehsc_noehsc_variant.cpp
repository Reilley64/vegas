
// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/IdxStand_.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d1b000.h"
#include "fnv/symbols_00d1c000.h"
#include "fnv/symbols_00d1d000.h"
#include "fnv/symbols_0104d000.h"
struct FUN_00d1bb40_Class
{
    int* FUN_00d1bb40(unsigned short index);
};
struct S_00d1bcb0_Allocator
{
    int unk00;
};
struct S_00d1bcb0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d1bcb0_Allocator* m_pStreamAllocator;
    S_00d1bcb0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00d1bcb0_Router* FUN_00c85750();
struct S_00d1bcb0_Entry
{
    int m_kPointA;
    int m_kPointB;
};
struct S_00d1bcb0_Array
{
    S_00d1bcb0_Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _pushBack(S_00d1bcb0_Allocator& alloc, const S_00d1bcb0_Entry& e)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(S_00d1bcb0_Entry));
        new (m_data + m_iElementCount) S_00d1bcb0_Entry(e);
        m_iElementCount++;
    }
    void AddBack(const S_00d1bcb0_Entry& e)
    {
        _pushBack(FUN_00c85750()->heap(), e);
    }
};
struct S_00d1bcb0
{
    int unk00;
    S_00d1bcb0_Array* m_ppData;
    bool FUN_00d1bcb0(int a, int b);
};
// @fnv 0x00d1d540
extern "C" void* __cdecl FUN_00d1d540(void* p, int a, int d, int e)
{
    if (!p)
        return 0;
    return ((void *)(::FUN_00d1ce50((::TreeD1C *)(p), (*(const ::hkAabbD1C *)(a)), (::CollectorD1C *)(0), (::hkArrayIntD1C *)(0), (int **)(d), e)));
}

extern "C" void* __cdecl FUN_00d1d240(void* p, int a, int b, int c, int d, int e);
// @fnv 0x00d1d570
extern "C" void* __cdecl FUN_00d1d570(void* p, int a, int b)
{
    if (!p)
        return p;
    return FUN_00d1d240(p, a, b, 0, 0, 0);
}

// @fnv 0x00d1d530
extern "C" void __cdecl FUN_00d1d530()
{
    ::FUN_00d1ca00({}, {}, {}, {}, {}, {});
}


union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};


struct VectorQ
{
    __m128 m_vComponents;
};

struct AabbQ
{
    VectorQ m_kMinimumCorner;
    VectorQ m_kMaximumCorner;

    __forceinline void operator=(const AabbQ& o)
    {
        m_kMinimumCorner.m_vComponents = o.m_kMinimumCorner.m_vComponents;
        m_kMaximumCorner.m_vComponents = o.m_kMaximumCorner.m_vComponents;
    }
};

struct TreeNode
{
    AabbQ m_kBounds;
    int m_children[2];
    unsigned int m_flags;

    __forceinline unsigned int isLeaf() const
    {
        return m_flags & 0x80000000;
    }
};

struct TreeNodeArray
{
};

struct AabbTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TreeNode* m_pTreeNode;
    int unk14;
    int unk18;
    TreeNodeArray m_kNodeCollection;
};

struct ClosestCollector
{
    virtual void unk00();
    virtual float processLeaf(const TreeNode* leaf);
};

struct HeapAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

extern "C" void _ReadWriteBarrier(void);


struct NodeStack
{
    TreeNode** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    TreeNode* m_kStorage[128];

    __forceinline NodeStack()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000080;
    }
    __forceinline ~NodeStack()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _clearAndDeallocate(S_00d1bcb0_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            reinterpret_cast<HeapAllocator&>(alloc).ReturnMemory(m_data, getCapacity() * sizeof(TreeNode*));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _pushBack(S_00d1bcb0_Allocator& alloc, TreeNode* const& t)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(alloc), (::AudioStream *)(void *)(this), sizeof(TreeNode*));
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void AddBack(TreeNode* const& t)
    {
        _pushBack(FUN_00c85750()->heap(), t);
    }
};

// @fnv 0x00d1dbb0
void __cdecl FUN_00d1dbb0(AabbTree* tree, const VectorQ& point, ClosestCollector* collector)
{
    TreeNode* root = tree->m_pTreeNode;
    if (root)
    {
        float maxDist = ::DAT_0104da48;
        NodeStack stack;
        if (!root->isLeaf())
        {
            stack.AddBack(root);
            _ReadWriteBarrier();
            do
            {
                TreeNode* node = stack.m_data[stack.m_iElementCount - 1];
                stack.m_iElementCount--;
                if (!node->isLeaf())
                {
                    TreeNode* c0 = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(tree->m_kNodeCollection))->FUN_00d9a4c0(node->m_children[0])));
                    TreeNode* c1 = ((::TreeNode *)(reinterpret_cast<::IdxStand_ *>(&(tree->m_kNodeCollection))->FUN_00d9a4c0(node->m_children[1])));
                    AabbQ a0;
                    a0 = c0->m_kBounds;
                    AabbQ a1;
                    a1 = c1->m_kBounds;
                    float d0 = ::FUN_00d1bad0((float *)(&a0), (float *)(&point));
                    float d1 = ::FUN_00d1bad0((float *)(&a1), (float *)(&point));
                    int mask = ((d0 < maxDist) ? 1 : 0) + ((maxDist > d1) ? 2 : 0);
                    switch (mask & 3)
                    {
                    case 1:
                        stack.AddBack(c0);
                        break;
                    case 2:
                        stack.AddBack(c1);
                        break;
                    case 3:
                        if (d0 < d1)
                        {
                            stack.AddBack(c1);
                            stack.AddBack(c0);
                        }
                        else
                        {
                            stack.AddBack(c0);
                            stack.AddBack(c1);
                        }
                        break;
                    }
                }
                else
                {
                    maxDist = collector->processLeaf(node);
                    if (maxDist == 0.0f)
                        break;
                }
            } while (stack.m_iElementCount);
        }
        else
        {
            collector->processLeaf(root);
        }
    }
}
