#pragma once

class EdgeExtraInfo;
class NavMeshTriangleReference;
struct BGSLoadFormBuffer;
struct CombatCoverPointData;
struct EI;
struct PNode;
struct WeaponObject;
template <class, unsigned int> class BSSimpleArray;

struct HX {
public:
    // 0x00406ee0
    ::EI *FUN_00406ee0(unsigned char);
    // 0x004efd10
    void FUN_004efd10(::BGSLoadFormBuffer *, float);
    // 0x006a8290
    bool FUN_006a8290(::PNode *, ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *, ::BSSimpleArray< ::EdgeExtraInfo, 1024> *);
    // 0x006d3100
    void FUN_006d3100(::CombatCoverPointData *);
    // 0x008a5eb0
    ::WeaponObject *GetWeaponObject();
};
