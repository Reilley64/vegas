#pragma once

class GlobalObject_00869f00;
class NavMeshEdgeSegment;
class NavMeshTriangleReference;
namespace fnv_006b35f0 { struct GlobalObject_00869f00; }
namespace fnv_006b3710 { class GlobalObject_00869f00; }
struct AX;
struct UW;
template <class, int> class BSSimpleArray;

// 0x006b3180
const ::NavMeshTriangleReference &GetFirstElement(const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *);
// 0x006b31a0
const ::NavMeshTriangleReference &GetLastElement(const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *);
// 0x006b35a0
void InitGlobalObject(::GlobalObject_00869f00 *);
// 0x006b35f0
namespace fnv_006b35f0 { void FUN_006b35f0(::fnv_006b35f0::GlobalObject_00869f00 *); }
// 0x006b3640
void InitSimpleArray(::BSSimpleArray< ::NavMeshEdgeSegment, 1024> *);
// 0x006b3710
namespace fnv_006b3710 { void FUN_006b3710(::fnv_006b3710::GlobalObject_00869f00 *); }
// 0x006b37e0
namespace fnv_006b37e0 { void FUN_006b37e0(char **); }
// 0x006b3eb0
void FUN_006b3eb0(::AX *, ::UW, ::UW);
