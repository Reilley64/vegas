// gamebryo2.2/corelibs/nimain/nidynamiceffect.cpp: EffectObject, FNVEffect (7 functions)

#include "fnv/decl/A5a260Object.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a5a390_shell.h"
#include "fnv/decl/FUN_00a5ad00_shell.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a68e30_shell.h"
#include "fnv/decl/LoadObject.h"
#include "fnv/decl/LoadedNode.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a5a900__Obj00a5a900.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_0043a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f4000.h"
#include "nidynamiceffect_decls.h"

// @fnv 0x00a68ea0
void NiDynamicEffect::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::LoadObject *>(this)->FUN_00a5a510((::LoadStream &)(stream));
    if (stream.m_uiNifVersion >= 0x0a010066)
    {
        unsigned char on;
        ReadBinaryValue(stream, on);
        m_bEffectEnabled = on != 0;
    }
    if (stream.m_uiNifVersion < 0x04010000)
    {
        int count;
        ReadBinaryValue(stream, count);
        for (int i = 0; i < count; ++i)
        {
            unsigned int linkID;
            ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(linkID));
        }
    }
    if (stream.m_uiNifVersion >= 0x0a00010e)
        reinterpret_cast<::S_00a64670_Foo *>(&(stream))->FUN_00a64670();
}

// @fnv 0x00a69070
void NiDynamicEffect::LinkObject(NiStream& stream)
{
    reinterpret_cast<::LoadedNode *>(this)->ReadFromStream((::LoadedStream *)&(stream));
    if (stream.m_uiNifVersion >= 0x0a00010e)
    {
        unsigned int count = reinterpret_cast<::FUN_00a63460_shell *>(&(stream))->FUN_00a63460();
        while (count--)
        {
            NiNode* node = reinterpret_cast<NiNode*>(stream.GetLoadedObject());
            if (node)
            {
                NiTListItem<NiNode*>* item = NiDynamicEffectNewListItem();
                item->m_element = node;
                item->m_pkPrev = 0;
                item->m_pkNext = m_kAffectedNodes.m_pkHead;
                if (m_kAffectedNodes.m_pkHead)
                    m_kAffectedNodes.m_pkHead->m_pkPrev = item;
                else
                    m_kAffectedNodes.m_pkTail = item;
                ++m_kAffectedNodes.m_kItemCount.m_uiCount;
                m_kAffectedNodes.m_pkHead = item;
            }
        }
    }
}

// @fnv 0x00a69320
NiDynamicEffect::NiDynamicEffect()
    : m_bEffectEnabled(true), m_ucEffectCategory(0xff), m_uiEffectPushCount(0), m_uiRevID(1)
{
    m_iIndex = InterlockedIncrement(&DAT_011a9b58);
}

struct BSShaderLightingProperty
{
    void ClearLights();
};

extern const void* vftable_NiDynamicEffect;

struct FUN_00a69390_shell : public NiDynamicEffect
{
    void* DestroyNiDynamicEffect(unsigned int flags);
};

// @fnv 0x00a69390
void* FUN_00a69390_shell::DestroyNiDynamicEffect(unsigned int flags)
{
    *reinterpret_cast<void**>(this) = &vftable_NiDynamicEffect;
    reinterpret_cast<::FUN_00a68e30_shell *>((this))->FUN_00a68e30();
    reinterpret_cast<BSShaderLightingProperty*>(reinterpret_cast<char*>(this) + 0xb8)->ClearLights();
    reinterpret_cast<BSShaderLightingProperty*>(reinterpret_cast<char*>(this) + 0xac)->ClearLights();
    reinterpret_cast<::FUN_00a5a390_shell *>((this))->FUN_00a5a390();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xc4);
    return this;
}

struct StrArr
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
    void SetAtInline(unsigned int uiIndex, char* element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else
        {
            if (element)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int AddInline(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        SetAtInline(uiIndex, element);
        return uiIndex;
    }
};
struct FUN_00a5ea70_t
{
};
struct NiNode;
struct Zx3ListNode
{
    Zx3ListNode* m_pkNext;
    Zx3ListNode* m_pkPrev;
    NiNode* m_element;
};
inline NiNode* Zx3GetNext(Zx3ListNode*& kPos)
{
    NiNode*& element = kPos->m_element;
    kPos = kPos->m_pkNext;
    return element;
}
struct Zx3Effect : public NiAVObject
{
    bool m_bEffectEnabled;
    unsigned char m_ucEffectCategory;
    int m_iIndex;
    unsigned int m_uiEffectPushCount;
    unsigned int m_uiRevID;
    Zx3ListNode* m_pkAffectedHead;
    Zx3ListNode* m_pkAffectedTail;
    int m_uiAffectedCount;
    Zx3ListNode* m_pkUnaffectedHead;
    void FUN_00a69140(StrArr* pkStrings);
};

// @fnv 0x00a69140
void Zx3Effect::FUN_00a69140(StrArr* pkStrings)
{
    reinterpret_cast<::FUN_00a5ad00_shell *>((((FUN_00a5ea70_t*)this)))->FUN_00a5ad00((::Stream *)(pkStrings));
    pkStrings->Add(FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f4988))));
    if (m_uiAffectedCount)
    {
        Zx3ListNode* kPos = m_pkAffectedHead;
        int i = 0;
        while (kPos)
        {
            NiNode* pkNode = Zx3GetNext(kPos);
            char acPrefix[64];
            NiSprintf(acPrefix, 64, "affected node[%d]", i);
            pkStrings->AddInline(FUN_00a7d5a0(acPrefix, pkNode));
            i++;
        }
        kPos = m_pkUnaffectedHead;
        while (kPos)
        {
            NiNode* pkNode = Zx3GetNext(kPos);
            char acPrefix[64];
            NiSprintf(acPrefix, 64, "unaffected node[%d]", i);
            pkStrings->AddInline(FUN_00a7d5a0(acPrefix, pkNode));
            i++;
        }
    }
}

struct EffectObject : NiDynamicEffect
{
    void SaveToStream(NiStream* stream);
};
static __forceinline unsigned int WriteBytes(NiBinaryStream* output, const void* bytes, unsigned int length)
{
    unsigned int componentLength = length;
    unsigned int written = output->m_pfnWrite(output, bytes, length, &componentLength, 1);
    output->m_uiStreamFlags += written;
    return written;
}
typedef void(* SaveLinkedObject)(NiStream*, NiNode*);
static __forceinline void WriteLinkedObject(NiStream* stream, NiNode*& object)
{
    ((SaveLinkedObject*)stream->m_ppVirtualMethodTable)[12](stream, object);
}
// @fnv 0x00a68f80
void EffectObject::SaveToStream(NiStream* stream)
{
    reinterpret_cast<::fnv_00a5a900::Obj00a5a900 *>(this)->FUN_00a5a900((*(::fnv_00a5a900::NiStream *)(stream)));
    unsigned char enabled = m_bEffectEnabled;
    NiBinaryStream* output = stream->m_pBackingStream;
    WriteBytes(output, &enabled, 1);
    int objectCount = m_kAffectedNodes.m_kItemCount.m_uiCount;
    output = stream->m_pBackingStream;
    WriteBytes(output, &objectCount, 4);
    if (objectCount > 0)
    {
        NiTListItem<NiNode*>* node = m_kAffectedNodes.m_pkTail;
        while (node)
        {
            NiNode*& element = node->m_element;
            node = node->m_pkPrev;
            WriteLinkedObject(stream, element);
        }
    }
}

static inline NiNode* GetNext(NiTListItem<NiNode*>*& node)
{
    NiNode*& element = node->m_element;
    node = node->m_pkNext;
    return element;
}
class FNVEffect : public NiDynamicEffect
{
  public:
    bool FUN_00a68d80(FNVEffect* other);
};
// Returns false if counts differ or paired entries differ in nullness; otherwise returns true if FUN_00a5a260 succeeds.
// @fnv 0x00a68d80
bool FNVEffect::FUN_00a68d80(FNVEffect* other)
{
    if (!reinterpret_cast<::A5a260Object *>(this)->FUN_00a5a260((::A5a260CompareBase *)(other)))
        return false;
    if (m_kEffectTargetNodes.m_kItemCount.m_uiCount != other->m_kEffectTargetNodes.m_kItemCount.m_uiCount)
        return false;
    if (m_kEffectTargetNodes.m_kItemCount.m_uiCount > 0)
    {
        NiTListItem<NiNode*>* left = m_kEffectTargetNodes.m_pkHead;
        NiTListItem<NiNode*>* right = other->m_kEffectTargetNodes.m_pkHead;
        while (left)
        {
            NiNode* pLeftNode = GetNext(left);
            NiNode* pRightNode = GetNext(right);
            if (pLeftNode && !pRightNode)
                return false;
            if (!pLeftNode && pRightNode)
                return false;
        }
    }
    if (m_kAffectedNodes.m_kItemCount.m_uiCount != other->m_kAffectedNodes.m_kItemCount.m_uiCount)
        return false;
    if (m_kAffectedNodes.m_kItemCount.m_uiCount > 0)
    {
        NiTListItem<NiNode*>* left = m_kAffectedNodes.m_pkHead;
        NiTListItem<NiNode*>* right = other->m_kAffectedNodes.m_pkHead;
        while (left)
        {
            NiNode* pLeftNode = GetNext(left);
            NiNode* pRightNode = GetNext(right);
            if (pLeftNode && !pRightNode)
                return false;
            if (!pLeftNode && pRightNode)
                return false;
        }
    }
    return true;
}
