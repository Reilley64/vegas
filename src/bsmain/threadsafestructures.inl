
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0044edd0_owner.h"
#include "fnv/symbols_01017000.h"
#include "threadsafestructures_ThreadSafeStructuresMatch.h"

template<>
// @fnv 0x0044B350
LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueue(unsigned int maxThreads, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 253);
    iCount = 0;
    pHead = new LockFreeQueueEntry;
    pTail = pHead;
    m_uiDeleteBatchSize = deleteBatchSize;
    m_ppDeletedNodeBuffers = new LockFreeQueueEntry*[maxThreads * 2];
    pMenuInterfaceManager = new Manager(maxThreads);
}

template<>
// @fnv 0x006C6450
LockFreeQueue<bhkRigidBody*>::LockFreeQueue(unsigned int maxThreads, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 253);
    iCount = 0;
    pHead = new LockFreeQueueEntry;
    pTail = pHead;
    m_uiDeleteBatchSize = deleteBatchSize;
    m_ppDeletedNodeBuffers = new LockFreeQueueEntry*[maxThreads * 2];
    pMenuInterfaceManager = new Manager(maxThreads);
}

template<>
// @fnv 0x005289E0
LockFreeMap<TESObjectREFR*, BSTreeNode*>::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 912);
    ItemUpdateArray = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new ThreadSafePointer<ThreadSafeHashTableNode>[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}

template<>
// @fnv 0x0044F070
void LockFreeMap<TESObjectREFR*, BSTreeNode*>::DeletedNodeScanner::ScanForDeletedNodes()
{
    AutoMemContext kContext(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 866);
    unsigned int numReferences = pOwner->GetMaxThreads() * 3;
    ThreadSafeHashTableNode** referencedNodes = new ThreadSafeHashTableNode*[numReferences];
    memcpy(referencedNodes, pOwner->m_ppDeletedNodeBuffers, numReferences * sizeof(ThreadSafeHashTableNode*));
    ThreadSafeHashTableNode* deleteHead = 0;
    unsigned int deleteCount = 0;
    while (m_pDeletedNodeHead != 0)
    {
        ThreadSafeHashTableNode* pNode = m_pDeletedNodeHead;
        m_pDeletedNodeHead = ((::LockFreeMap< ::TESObjectREFR *, ::BSTreeNode *>::ThreadSafeHashTableNode *)(reinterpret_cast<::Callees *>((m_pDeletedNodeHead))->FUN_00726070()));
        {
            bool bReferenced = false;
            for (unsigned int index = 0; index < numReferences; ++index)
            {
                if (pNode == referencedNodes[index])
                {
                    bReferenced = true;
                    break;
                }
            }
            if (bReferenced)
            {
                reinterpret_cast<::CombatProcedure *>((pNode))->Initialize((::CombatController *)(deleteHead));
                deleteHead = pNode;
                ++deleteCount;
            }
            else
            {
                reinterpret_cast<::CombatProcedure *>((pNode))->Initialize((::CombatController *)(::LockFreeMap< ::TESObjectREFR *, ::BSTreeNode *>::ThreadSafeHashTableNode *)(0));
                reinterpret_cast<::FUN_0044edd0_owner *>((pOwner))->DispatchAndDelete((::FUN_0044edd0_Disposable *)(pNode));
            }
        }
    }
    delete[] referencedNodes;
    m_pDeletedNodeHead = deleteHead;
    m_uiDeleteCount = deleteCount;
}

template<>
// @fnv 0x006C73B0
ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>::ThreadInterfaceManager(unsigned int maxThreads)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 20);
    uiThreadCount = 0;
    uiMaxThreads = maxThreads;
    m_pThreadInterfaceEntries = new ThreadInterfaceEntry[uiMaxThreads];
    uiTLSIndex = FUN_0044e330();
}

namespace ThreadSafeStructuresPC_0044b750 {
template<>
// @fnv 0x0044B750
LockFreeMap<TESObjectREFR*, BSTreeNode*>::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 912);
    ItemUpdateArray = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new Bucket[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}
}

namespace ThreadSafeStructuresPC_0044ba10 {
template<>
// @fnv 0x0044BA10
LockFreeMap<TESObjectREFR*, BSTreeNode*>::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 912);
    ItemUpdateArray = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new Bucket[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}
}

namespace ThreadSafeStructuresPC_0044bbe0 {
template<>
// @fnv 0x0044BBE0
LockFreeMap<TESObjectREFR*, BSTreeNode*>::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 912);
    ItemUpdateArray = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new Bucket[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}
}

namespace ThreadSafeStructuresPC_0044be80 {
template<>
// @fnv 0x0044BE80
LockFreeMap<TESObjectREFR*, BSTreeNode*>::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 912);
    ItemUpdateArray = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new Bucket[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}
}

namespace ThreadSafeStructuresPC_0044c040 {
template<>
// @fnv 0x0044C040
LockFreeMap<TESObjectREFR*, BSTreeNode*>::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        ::kThreadSafeStructuresSourceFile, 912);
    ItemUpdateArray = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new Bucket[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}
}
