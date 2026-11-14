// gamebryo2.2/corelibs/nimain/nitpool_decls.h: declares D3DRenderStateGroup, NiStreamLinkIDSet

#include "fnv/decl/FUN_00a311e0_s.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00e7f000.h"
#include "fnv/symbols_011f6000.h"
#include "MemoryManager.h"
class D3DRenderStateGroup
{
  public:
    unsigned char data[20];
};
class NiStreamLinkIDSet
{
  public:
    D3DRenderStateGroup** m_pBase;
    unsigned int m_uiElementCount, m_uiAllocatedCapacity;
    void Add(D3DRenderStateGroup* p)
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            reinterpret_cast<::FUN_00a311e0_s *>(this)->FUN_00a311e0(m_uiElementCount > 0 ? m_uiElementCount * 2 : 1);
        m_pBase[m_uiAllocatedCapacity++] = p;
    }
};
template <class T, class A> class ObjectPoolBlock
{
  public:
    T* objects;
    unsigned int count;
    ObjectPoolBlock* next;
    ObjectPoolBlock(unsigned int n) throw() : count(n), next(0)
    {
        if (n > 0)
            objects = ((::D3DRenderStateGroup *)(::FUN_00e7f0a0(n)));
        else
            objects = 0;
    }
    T* GetAt(unsigned int i)
    {
        if (i >= count)
            return 0;
        return objects + i;
    }
};
template <class T, class A> class ObjectPool
{
  public:
    NiStreamLinkIDSet freeObjects;
    ObjectPoolBlock<T, A>* containers;
    unsigned int currentSize, initialSize;
    void AddPoolBlock(unsigned int n);
};
