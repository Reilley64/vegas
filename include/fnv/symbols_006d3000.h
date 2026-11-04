#pragma once

class NiPoint3;
class TESObjectREFR;
namespace fnv_006d3b40 { struct RequestAccess; }
struct Object;
struct Vec3;

// 0x006d33c0
void GetObjectPosition(::Object *, ::Vec3 *);
// 0x006d34d0
bool FUN_006d34d0(void *, ::NiPoint3 *);
// 0x006d3780
bool BuildPathingRequest(::TESObjectREFR *, ::TESObjectREFR *, float, void *);
// 0x006d3b40
namespace fnv_006d3b40 { bool FindPathToTarget(::fnv_006d3b40::RequestAccess *, ::NiPoint3 *); }
