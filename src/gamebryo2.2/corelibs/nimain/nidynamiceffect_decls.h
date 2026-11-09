// gamebryo2.2/corelibs/nimain/nidynamiceffect_decls.h: declares NiBinaryStream, NiAVObject
#ifndef FNV_NIDYNAMICEFFECT_DECLS_H
#define FNV_NIDYNAMICEFFECT_DECLS_H

#include "fnv/list_node.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/symbols_0043a000.h"
#include "fnv/symbols_011c5000.h"
#include "NiObjectNET.h"
#include "NiPoint3.h"

#include "nidynamiceffect_stream.h"
class NiCollisionObject;
class FourComponentFloatVector;
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* data, unsigned int size)
    {
        unsigned int componentSizes[1] = {size};
        return BinaryRead(data, size, componentSizes, 1);
    }
    unsigned int BinaryRead(void* data, unsigned int size, unsigned int* componentSizes, unsigned int components)
    {
        unsigned int read = m_pfnRead(this, data, size, componentSizes, components);
        m_uiStreamFlags += read;
        return read;
    }
};
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    reinterpret_cast<::FUN_00462d80_shell *>((stream.m_pUnderlyingStream))->ReadBytes(&value, sizeof(T));
}
class FNV_ALIGN(32) RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    unsigned char layoutPadding8[24];
    FNV_FORCEINLINE void Unlock()
    {
        if (--m_uiRecursionCount == 0)
            m_uiOwningThreadID = 0;
    }
public:
    void FUN_0040fba0();
};
template <class T> class PoolMemoryAllocator : public PoolAllocatorBase<T>
{
  public:
    static void CreateFreeMem();
};
inline NiTListItem<NiNode*>* NiDynamicEffectNewListItem()
{
    auto* item = static_cast<NiTListItem<NiNode*>*>(fnv::list::AcquireStorage());
    item->m_element = nullptr;
    item->m_pkNext = nullptr;
    item->m_pkPrev = nullptr;
    return item;
}
struct NiDynamicEffectTransform
{
    float m_kOrientation[9];
    NiPoint3 m_kTranslation;
    float m_fScale;
};
class NiAVObject : public NiObjectNET
{
  public:
    NiAVObject();
    virtual ~NiAVObject();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> > SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiDynamicEffectTransform m_kLocalTransform;
    NiDynamicEffectTransform m_kWorldSpaceTransform;
};
extern volatile long DAT_011a9b58;
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
  public:
    NiTPointerList()
    {
        m_kItemCount.m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
};
class NiDynamicEffect : public NiAVObject
{
  public:
    NiDynamicEffect();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    bool m_bEffectEnabled;
    unsigned char m_ucEffectCategory;
    int m_iIndex;
    unsigned int m_uiEffectPushCount;
    unsigned int m_uiRevID;
    NiTPointerList<NiNode*> m_kEffectTargetNodes;
    NiTPointerList<NiNode*> m_kAffectedNodes;
};
#endif
