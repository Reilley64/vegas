#ifndef FNV_ASTARSEARCH_H
#define FNV_ASTARSEARCH_H

#include "fnv/decl/A83A0ScrapHeap.h"
#include "fnv/decl/FUN_006a83f0_cls.h"
#include "fnv/decl/FUN_006a8490_class.h"
#include "fnv/decl/FUN_006b9420_Class.h"
#include "fnv/decl/FUN_006b9540_class.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/SlotOwnerCls.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "astarsearch_decls.h"

// @fnv 0x00b00a00
inline BSWin32TaskletManager& GetTaskletManager()
{
    static BSWin32TaskletManager s_TaskletManager(6);
    return s_TaskletManager;
}

template <>
// @fnv 0x006a7e00
CREATE_ASTARNODE_RESULT AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::CreateOrUpdateNode(
    unsigned int uiKey, float m_fPathingCostCur, AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>*& pNodeOut)
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>** ppBucket =
        &m_kNodeHashTable.m_ppNodes[m_kNodeHashTable.FUN_00996840(uiKey)];
    if (*ppBucket)
    {
        if ((*ppBucket)->iKey == uiKey)
        {
            if ((*ppBucket)->m_fPathingCostCur > m_fPathingCostCur)
            {
                pNodeOut = *ppBucket;
                reinterpret_cast<::FUN_006a8490_class *>(&(AStarBucketQueue))->UnlinkNode((::FUN_006a8490_node *)(pNodeOut));
                pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
            }
            else
                return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
        }
        else
        {
            AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pPrev = *ppBucket;
            AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pCur;
            pCur = (*ppBucket)->m_pNextHashNode;
            while (pCur)
            {
                if (pCur->iKey == uiKey)
                {
                    if (pCur->m_fPathingCostCur > m_fPathingCostCur)
                    {
                        pNodeOut = pCur;
                        reinterpret_cast<::FUN_006a8490_class *>(&(AStarBucketQueue))->UnlinkNode((::FUN_006a8490_node *)(pNodeOut));
                        pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                        return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
                    }
                    else
                        return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
                }
                pPrev = pCur;
                pCur = pCur->m_pNextHashNode;
            }
        }
    }
    pNodeOut = ((::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *)(reinterpret_cast<::A83A0ScrapHeap *>(&(m_kNodeAllocator))->CreateNode()));
    pNodeOut->iKey = uiKey;
    pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
    pNodeOut->m_pNextHashNode = *ppBucket;
    *ppBucket = pNodeOut;
    return CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE;
}

template <>
// @fnv 0x006b8fe0
CREATE_ASTARNODE_RESULT AStarSearch<AStarNodeData*, AStarNodeLink*>::CreateOrUpdateNode(
    unsigned int uiKey, float m_fPathingCostCur, AStarNode<AStarNodeData*, AStarNodeLink*>*& pNodeOut)
{
    AStarNode<AStarNodeData*, AStarNodeLink*>** ppBucket =
        &m_kNodeHashTable.m_ppNodes[m_kNodeHashTable.FUN_00996840(uiKey)];
    if (*ppBucket)
    {
        if ((*ppBucket)->iKey == uiKey)
        {
            if ((*ppBucket)->m_fPathingCostCur > m_fPathingCostCur)
            {
                pNodeOut = *ppBucket;
                reinterpret_cast<::FUN_006b9540_class *>(&(AStarBucketQueue))->UnlinkFromNeighbors((int)(pNodeOut));
                pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
            }
            else
                return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
        }
        else
        {
            AStarNode<AStarNodeData*, AStarNodeLink*>* pPrev = *ppBucket;
            AStarNode<AStarNodeData*, AStarNodeLink*>* pCur;
            pCur = (*ppBucket)->m_pNextHashNode;
            while (pCur)
            {
                if (pCur->iKey == uiKey)
                {
                    if (pCur->m_fPathingCostCur > m_fPathingCostCur)
                    {
                        pNodeOut = pCur;
                        reinterpret_cast<::FUN_006b9540_class *>(&(AStarBucketQueue))->UnlinkFromNeighbors((int)(pNodeOut));
                        pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                        return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
                    }
                    else
                        return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
                }
                pPrev = pCur;
                pCur = pCur->m_pNextHashNode;
            }
        }
    }
    pNodeOut = ((::AStarNode< ::AStarNodeData *, ::AStarNodeLink *> *)(reinterpret_cast<::FUN_006b9420_Class *>(&(m_kNodeAllocator))->FUN_006b9420()));
    pNodeOut->iKey = uiKey;
    pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
    pNodeOut->m_pNextHashNode = *ppBucket;
    *ppBucket = pNodeOut;
    return CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE;
}

template <class BoundingVolumeNode, class TLink>
// @fnv 0x006a7c90
AStarNode<BoundingVolumeNode, TLink>* AStarSearch<BoundingVolumeNode, TLink>::FindOrCreateSearchNode(
    unsigned int uiKey, const BoundingVolumeNode& ObjectResolver, float m_fCost)
{
    AStarNode<BoundingVolumeNode, TLink>* pNode;
    switch (((NavMeshSearch*)this)->CreateOrUpdateNode(uiKey, 0.0f, pNode))
    {
    case CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE:
        pNode->m_fCost = m_fCost;
        pNode->ObjectResolver = ObjectResolver;
        reinterpret_cast<::FUN_006a83f0_cls *>(&(AStarBucketQueue))->InsertSortedNode((::SortNode *)(pNode));
        m_pLastCreatedNode = pNode;
        return pNode;
    case CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA:
        return pNode;
    case CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER:
        return 0;
    default:
        return 0;
    }
}

template <class BoundingVolumeNode, class TLink>
// @fnv 0x006a8010
AStarNode<BoundingVolumeNode, TLink>* AStarSearch<BoundingVolumeNode, TLink>::ComputePath()
{
    AStarNode<BoundingVolumeNode, TLink>* pCurNode;
    AStarConnectionArray<BoundingVolumeNode, TLink> ConnectionArray;
    unsigned int uiCounter;
    AStarNode<BoundingVolumeNode, TLink>* i;
    unsigned int pSavedLastNode;
    i = m_pCurrentNode;
    m_pCurrentNode = ((::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *)(reinterpret_cast<::SlotOwnerCls *>(&(AStarBucketQueue))->PopSlotNode()));
    if (m_pCurrentNode == NULL)
        return NULL;
    m_pFirstNode = m_pCurrentNode;
    uiCounter = 0;
    while (m_pCurrentNode)
    {
        if (HasReachedGoal(m_pCurrentNode))
        {
            m_pFirstNode = m_pCurrentNode;
            return m_pCurrentNode;
        }
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(ConnectionArray))->Clear(0);
        CollectConnections(m_pCurrentNode, &ConnectionArray);
        for (pSavedLastNode = 0; pSavedLastNode < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(ConnectionArray))->GetName())); pSavedLastNode++)
        {
            pCurNode = ConnectionArray[pSavedLastNode];
            reinterpret_cast<::FUN_006a8490_class *>(&(AStarBucketQueue))->UnlinkNode((::FUN_006a8490_node *)(pCurNode));
            if (m_pCurrentNode->m_pParentNode == pCurNode)
                return NULL;
            pCurNode->m_pParentNode = m_pCurrentNode;
            reinterpret_cast<::FUN_006a83f0_cls *>(&(AStarBucketQueue))->InsertSortedNode((::SortNode *)(pCurNode));
            if (((double)(reinterpret_cast<::TimeoutTimer *>((pCurNode))->FUN_006b9130())) < ((double)(reinterpret_cast<::TimeoutTimer *>((m_pFirstNode))->FUN_006b9130())))
                m_pFirstNode = pCurNode;
        }
        if (m_bUseBestNode)
        {
            if (++uiCounter == 50)
            {
                uiCounter = 0;
                FUN_0040fca0(0);
            }
        }
        i = m_pCurrentNode;
        m_pCurrentNode = ((::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *)(reinterpret_cast<::SlotOwnerCls *>(&(AStarBucketQueue))->PopSlotNode()));
    }
    m_pCurrentNode = i;
    return NULL;
}

template <class BoundingVolumeNode, class TLink>
// @fnv 0x006a7d60
bool AStarSearch<BoundingVolumeNode, TLink>::Search(unsigned int uiParam1, unsigned int uiParam2, bool bUseBestNode)
{
    AStarNode<BoundingVolumeNode, TLink>* pNode;
    bool bSuccess;
    AStarNode<BoundingVolumeNode, TLink>* pOutNode;
    m_bUseBestNode = GetTaskletManager().TryRunAsTasklet(gm_GetCurrentThreadId());
    pNode = ComputePath();
    if (pNode)
    {
        bSuccess = true;
        pOutNode = pNode;
    }
    else if (bUseBestNode)
    {
        bSuccess = false;
        pOutNode = m_pFirstNode;
    }
    else
    {
        bSuccess = false;
        pOutNode = NULL;
    }
    if (pOutNode)
        reinterpret_cast<::HX *>(this)->FUN_006a8290((::PNode *)(pOutNode), (::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(uiParam1), (::BSSimpleArray< ::EdgeExtraInfo, 1024> *)(uiParam2));
    return bSuccess;
}

template AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* AStarSearch<
    NavMeshTriangleReference, NavMeshTriangleEdgeReference>::FindOrCreateSearchNode(unsigned int,
                                                                                    const NavMeshTriangleReference&,
                                                                                    float);
template bool AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::Search(unsigned int, unsigned int,
                                                                                          bool);

template AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* AStarSearch<
    NavMeshTriangleReference, NavMeshTriangleEdgeReference>::ComputePath();
#endif
