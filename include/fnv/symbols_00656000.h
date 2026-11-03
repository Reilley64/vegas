#pragma once

#include <cstdint>

class RegionObjectEntry;
struct BoundingSphere;
struct FUN_00656d80_this;
struct PointIterator;
template <class> class BSSimpleList;

// 0x00656d80
::BSSimpleList< ::RegionObjectEntry *> *GetObjectiveTargetList(::FUN_00656d80_this *);
// 0x00656db0
namespace fnv_00656db0 { std::uintptr_t FUN_00656db0(); }
// 0x00656dc0
void ComputeBoundingSphere(::BoundingSphere *, ::PointIterator *, int);
