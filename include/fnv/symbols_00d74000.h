#pragma once
#include <cstdint>

class hkpEntityD748;
struct Cache_d74480;
struct Node;
struct PayloadOwner;
struct Shp_d74480;
struct hkShapeEntryArrayD748;
struct hkShapeOutputD748;

// 0x00d74480
::Shp_d74480 *ProcessShape(::Shp_d74480 *, void *, ::Cache_d74480 *, void *);
// 0x00d74850
int RemapCollisionShapes(::hkShapeEntryArrayD748 *, void *, ::hkShapeOutputD748 *);
// 0x00d748d0
int FUN_00d748d0(::hkpEntityD748 *, void *, ::hkShapeOutputD748 *);
// 0x00d74b70
void AssignNodeFlags(::Node **, int, unsigned int);
// 0x00d74ed0
int *FUN_00d74ed0(::PayloadOwner *);
