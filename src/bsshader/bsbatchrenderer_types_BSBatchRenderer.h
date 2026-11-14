// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSBATCHRENDERER_H
#define FNV_BSBATCHRENDERER_H

#include "fnv/symbols_00b99000.h"
#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class BSBatchRenderer;
class BSBatchRenderer__GeometryGroup;
class BSBatchRenderer__PassGroup;
class BSBatchRenderer__RenderContext;
class DFALL_NiTMapItem_unsigned_int_unsigned_int___;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___;
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator;
class NiTListItem_BSBatchRenderer__GeometryGroup___;
class NiTMap_unsigned_int_unsigned_int_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_BSBatchRenderer__GeometryGroup___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___;
class DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // void* __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*()
    // void __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*(void*)
};
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
    : public DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // base DFALL<NiTMapItem<unsigned int,unsigned int> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_
{
  public:
    void** m_ppVirtualMethodTable;                                          // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                // +0x4, 4 bytes
    NiTMapItem<unsigned int, unsigned int>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(void*&, unsigned int&, unsigned int&)
    // NiTMapItem<unsigned int,unsigned int>* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>& __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(const NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
};
class NiTMap_unsigned_int_unsigned_int_
    : public NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_
{
  public:
    // base NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int> at +0x0, size 16
    // NiTMap<unsigned int,unsigned int>
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
    // NiTMapItem<unsigned int,unsigned int>* __cdecl NiTMap<unsigned int,unsigned int>::*()
    // void __cdecl NiTMap<unsigned int,unsigned int>::*(NiTMapItem<unsigned int,unsigned int>*)
    // NiTMap<unsigned int,unsigned int>& __cdecl NiTMap<unsigned int,unsigned int>::*(const NiTMap<unsigned int,unsigned int>&)
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
};
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
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
{
  public:
    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
};
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
{
  public:
};
class NiTPointerList_BSBatchRenderer__GeometryGroup___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
{
  public:
};
struct BSBatchRenderer__PassBucketEntry
{
    unsigned int padding;
    void* m_pRenderPass;
    unsigned char tail[12];
};
class BSBatchRenderer : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    BSBatchRenderer__PassBucketEntry* m_pPassBucketEntries;     // +0x8, 4 bytes
    NiTMap_unsigned_int_unsigned_int_ m_kGroupIndexMap;         // +0xC, 16 bytes
    unsigned int m_uiGroupCount;                                // +0x1C, 4 bytes
    unsigned int m_uiPassCount;                                 // +0x20, 4 bytes
    unsigned int m_uiBucketCount;                               // +0x24, 4 bytes
    BSBatchRenderer__RenderContext* m_pGeometryGroupAllocator;  // +0x28, 4 bytes
    BSSimpleList<unsigned short> m_kActivePassList;             // +0x2C, 8 bytes
    int m_iActiveGroupCount;                                    // +0x34, 4 bytes
    bool m_bHasActiveGroups;                                    // +0x38, 1 bytes
    unsigned char layoutPadding39[3];
    BSBatchRenderer__GeometryGroup* m_pGeometryGroups[13];                  // +0x3C, 52 bytes
    BSBatchRenderer__GeometryGroup* m_pSecondaryGeometryGroups[2];          // +0x70, 8 bytes
    NiTPointerList_BSBatchRenderer__GeometryGroup___ AlphaGeometryList[2];  // +0x78, 24 bytes
    BSBatchRenderer__GeometryGroup* m_pAlphaGeometryGroups[2];              // +0x90, 8 bytes
    // const NiRTTI* __cdecl BSBatchRenderer::*()
    // BSBatchRenderer
    // void __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*(bool)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&, bool&)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&)
    // bool __cdecl BSBatchRenderer::*(unsigned int, int&)
    // void __cdecl BSBatchRenderer::*(unsigned int, int, bool&)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&, bool&, bool)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&, bool&, bool)
    // void __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // bool __cdecl BSBatchRenderer::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // bool __cdecl BSBatchRenderer::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // bool __cdecl BSBatchRenderer::*(unsigned int)
    // void __cdecl BSBatchRenderer::*(unsigned int)
    // void __cdecl BSBatchRenderer::*(const NiBound&, bool, const NiCamera*, bool)
    // void __cdecl BSBatchRenderer::*()
    // bool __cdecl BSBatchRenderer::*()
    // bool __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*(BSBatchRenderer::GEOMETRY_GROUP_ENUM, bool)
    // void __cdecl BSBatchRenderer::*(const NiCamera*, bool)
    // float __cdecl BSBatchRenderer::*(unsigned int, const NiCamera*, bool)
    // void __cdecl BSBatchRenderer::*(unsigned int, const NiCamera*, bool, float)
    // void __cdecl BSBatchRenderer::*(int)
    // int __cdecl BSBatchRenderer::*(BSBatchRenderer::GEOMETRY_GROUP_ENUM)
    // BSBatchRenderer& __cdecl BSBatchRenderer::*(const BSBatchRenderer&)
    bool FindBucketIndex(unsigned int, int&);
    bool FindPassBucket(unsigned int&, int&, bool&);
    void ReleaseGeometryGroups();
    void FUN_00b99730();
};
#endif
