
#include <new>
#include "fnv/decl/FUN_00905aa0_cls.h"
#include "fnv/decl/Vec3.h"
#include "bstmessagequeue_decls.h"
template <>
// @fnv 0x00905770
bool BSTCommonLLMessageQueue<QueuedMessage>::RemoveMessage(QueuedMessage& output)
{
    BSTFreeListElement<QueuedMessage>* pElem = pHead;
    bool bResult;
    if (pElem)
    {
        output = reinterpret_cast<QueuedMessage&>(((::BGSPerkEntry *)(new ((void *)(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pElem))) ::Vec3())));
        pHead = pElem->pNext;
        pSizeClassFreeList->Elem(pElem);
        bResult = true;
    }
    else
        bResult = false;
    return bResult;
}
template <>
// @fnv 0x009056f0
bool BSTCommonLLMessageQueue<QueuedMessage>::EnqueueMessage(const QueuedMessage& input)
{
    BSTFreeListElement<QueuedMessage>* pElem;
    bool bResult;
    if (pSizeClassFreeList && reinterpret_cast<::FUN_00905aa0_cls *>((pSizeClassFreeList))->FUN_00905aa0((::FUN_00905b00_stub **)&(pElem), (const void *)&(input)))
    {
        if (!pHead)
            m_ppTailLink = &pHead;
        *m_ppTailLink = pElem;
        pElem->pNext = 0;
        m_ppTailLink = &pElem->pNext;
        bResult = true;
    }
    else
        bResult = false;
    return bResult;
}
