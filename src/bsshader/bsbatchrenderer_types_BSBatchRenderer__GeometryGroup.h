// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSBATCHRENDERER_GEOMETRYGROUP_H
#define FNV_BSBATCHRENDERER_GEOMETRYGROUP_H

#include "layout_support.h"
#include "layout_support.h"
class BSBatchRenderer;
class BSBatchRenderer__GeometryGroup;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTPointerAllocator_unsigned_int_;
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int ItemUpdateArray;  // +0x0, 4 bytes
};
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem*
        pHead;  // +0x4, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem*
        pTail;  // +0x8, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem*
        m_pCachedListItems;  // +0xC, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator
        Allocator;  // +0x10, 4 bytes
};
class BSBatchRenderer__GeometryGroup
{
  public:
    unsigned char m_ucEntryType;  // +0x0, 1 bytes
    unsigned char layoutPadding1[1];
    unsigned short m_usPassCountLocal;             // +0x2, 2 bytes
    unsigned int auiGroupKey;           // +0x4, 4 bytes
    BSBatchRenderer* m_pGroupRenderer;  // +0x8, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___
        PassTextureSlotCollection;  // +0xC, 20 bytes
    float m_fProjectionDepth;       // +0x20, 4 bytes
    void ClearPassTextureSlots();
};
#endif
