#ifndef BSBATCHRENDERER_PRIVATE_H
#define BSBATCHRENDERER_PRIVATE_H

#include "fnv/decl/AlphaList.h"
#include "fnv/decl/FUN_00b63e90_cls.h"
#include "fnv/symbols_011f6000.h"
#include "bsbatchrenderer_types_BSBatchRenderer.h"
class BSBatchRenderer__ActivePassList
{
  public:
    unsigned short item;
    BSBatchRenderer__ActivePassList* next;
    __forceinline BSBatchRenderer__ActivePassList* GetHead()
    {
        if (next || item)
            return this;
        return 0;
    }
    void FUN_00b99730();
};
__forceinline int BSBatchRenderer_Max(int a, int b)
{
    return a > b ? a : b;
}
#include "MemoryManager.h"
class BSBatchRenderer__AlphaList
{
  public:
};
struct BSBatchRenderer__PassGroup
{
    BSBatchRenderer__PassBucketEntry buckets[5];
    unsigned int padding;
};
struct BSBatchRenderer__RenderPassInfo
{
    unsigned char padding[7];
    bool bAlpha;
};
struct BSBatchRenderer__RenderPass
{
    unsigned char padding[8];
    BSBatchRenderer__RenderPassInfo* pInfo;
};
struct BSBatchRenderer__PassList
{
  public:
    void* pHead;
    void* pTail;
    void* m_pCachedListItems;
    struct AllocatorData
    {
        unsigned int ItemUpdateArray;
    } Allocator;
    __declspec(nothrow) virtual ~BSBatchRenderer__PassList()
    {
        reinterpret_cast<::FUN_00b63e90_cls *>(this)->ReleasePoolNodes();
        m_pCachedListItems = pHead;
        pHead = 0;
        pTail = 0;
        Allocator.ItemUpdateArray = 0;
        reinterpret_cast<::FUN_00b63e90_cls *>(this)->ReleasePoolNodes();
    }
};
class BSBatchRenderer__GeometryGroup
{
  public:
    unsigned char m_ucEntryType;
    unsigned char padding1;
    unsigned short m_usPassCountLocal;
    unsigned int auiGroupKey;
    BSBatchRenderer* m_pGroupRenderer;
    BSBatchRenderer__PassList PassTextureSlotCollection;
    float m_fProjectionDepth;
    void ClearPassTextureSlots();
    ~BSBatchRenderer__GeometryGroup();
};
#endif
