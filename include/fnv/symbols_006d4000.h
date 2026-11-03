#pragma once

#include <cstdint>

class PathingActorData;
struct CoverSortItem;
struct EdgeHandleList;
struct LocS;
struct Location;
struct LocationView;
struct PathActor;
struct Result;

// 0x006d4020
int CompareCoverSortItems(const ::CoverSortItem *, const ::CoverSortItem *);
// 0x006d4120
int CollectNearbyEdges(::PathActor *, unsigned int, ::EdgeHandleList *);
// 0x006d4570
bool FUN_006d4570(::LocationView *, float, ::LocationView *);
// 0x006d4d20
bool FUN_006d4d20(::LocS *, ::LocS *, void *, int, float, ::PathingActorData *, int);
// 0x006d4f70
bool BuildPathWithDoors(::Location *, ::Location *, ::Result *, std::intptr_t, int);
