#pragma once

class TESObjectCELL;
class TESWorldSpace;

// The leading data members of PathingLocation (as in pathfinding/PathingLocation.h), for units whose location
// stand-ins declare no fields. The 4-byte getter folded into 0x00441110 (BGSTerrainManager::GetMinLevel) reads
// `m_pContainingWorldspace` when called on a pathing location.
struct PathingLocationFields
{
    void** m_ppVirtualMethodTable;
    float Location[3];
    const void* m_pLocationNavMesh;
    const void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
};
