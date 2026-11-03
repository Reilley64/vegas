#pragma once

class NiPoint3;
class PathingRequest;
class PathingSolution;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;

class Pathing {
public:
    // 0x00693d70
    ::TESObjectREFR *FindReferenceByFormId(unsigned int);
    // 0x006d0900
    static bool BuildPath(::PathingRequest *, ::PathingSolution *);
    // 0x006d6f80
    static bool FindClosestPathingPoint(::TESWorldSpace *, ::TESObjectCELL *, const ::NiPoint3 &, ::NiPoint3 *);
};
