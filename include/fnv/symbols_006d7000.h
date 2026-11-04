#pragma once

class NavMesh;
class NiPoint3;
class P110DataPtr;
class P110Location;
class PathingLocation;
class TESObjectCELL;
class TESWorldSpace;
namespace fnv_006d74c0 { struct EdgeFilter; }
namespace fnv_006d7a40 { struct Location; }
struct EntryListNode;
struct PathSource;
struct WeightList;
template <class> class NiPointer;

// 0x006d7110
bool FUN_006d7110(::TESWorldSpace *, ::TESObjectCELL *, const ::NiPoint3 &, float, ::NiPoint3 &);
// 0x006d74c0
namespace fnv_006d74c0 { bool FUN_006d74c0(::PathingLocation &, const ::NiPoint3 &, ::NavMesh *, unsigned short, ::PathingLocation *, ::fnv_006d74c0::EdgeFilter *); }
// 0x006d7a40
namespace fnv_006d7a40 { ::fnv_006d7a40::Location FUN_006d7a40(::fnv_006d7a40::Location &, ::fnv_006d7a40::Location &, float); }
// 0x006d7ca0
bool BuildPathNodeHolder(::NiPointer< ::PathSource> &, ::EntryListNode *, ::WeightList *);
// 0x006d7f40
bool MarkReachableTriangles(::P110Location *, ::P110DataPtr *, bool, float, float);
