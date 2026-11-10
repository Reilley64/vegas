#pragma once
#include <cstdint>

struct PathingRequest;
struct FUN_006abbb0;
class PathingSolution;
struct RouteLocation;

// 0x006d5340
int ConstructAndCallMethod(int, int, int, intptr_t);
// 0x006d53b0
int FUN_006d53b0(::PathingRequest *, ::PathingSolution *);
// 0x006d5420
int QueryPathScope(void *, void *, void *);
// 0x006d5490
bool FUN_006d5490(::RouteLocation *, ::RouteLocation *, void *, float *, ::FUN_006abbb0 *);
