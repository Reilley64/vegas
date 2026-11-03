#pragma once
#include <cstdint>

class CollectorD1C;
class QueryAabb;
class QueryTree16;
struct AabbCollector;
struct CompressedTree;
struct LeafCollector;
struct NTreeQ;
struct Node;
struct RayCollector;
struct RayInput;
struct RayQuerySet;
struct RayTree;
struct SweptBoxQuery;
struct TreeD1C;
struct VoidArray;
struct hkAabbD1C;
struct hkArrayIntD1C;

// 0x00d1c2b0
int FUN_00d1c2b0(::CompressedTree *, intptr_t, const ::SweptBoxQuery *, ::LeafCollector *, float, int *, int);
// 0x00d1c560
int FUN_00d1c560(const ::QueryTree16 *, const ::QueryAabb &, ::AabbCollector *, ::VoidArray *, void ***, intptr_t);
// 0x00d1ca00
void FUN_00d1ca00(::RayTree *, ::Node *, ::Node *, const ::RayQuerySet *, ::RayCollector **, const float *);
// 0x00d1cc50
int FUN_00d1cc50(::NTreeQ *, void *, const ::RayInput *, ::RayCollector *, float, unsigned int *, int);
// 0x00d1ce50
intptr_t FUN_00d1ce50(::TreeD1C *, const ::hkAabbD1C &, ::CollectorD1C *, ::hkArrayIntD1C *, int **, intptr_t);
