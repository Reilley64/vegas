#pragma once

struct BGSLoadGameBuffer;
struct CoordinateTriple;
class NavMeshInfo;
struct NavMeshPtr;
struct NiPoint3;
class TESObjectCELL;
class TESObjectREFR;

struct PathingLocation {
public:
    // 0x004ff7e0
    bool HasValidTriangle();
    // 0x006dcce0
    ::PathingLocation &operator=(const ::PathingLocation &);
    // 0x006dce10
    PathingLocation(const ::NiPoint3 &, ::TESObjectREFR *);
    // 0x006dd010
    PathingLocation(const ::CoordinateTriple &, ::NavMeshInfo *, unsigned short);
    // 0x006dd4f0
    ::TESObjectCELL *GetContainingCell();
    // 0x006dd610
    bool ResolveNavMesh(::NavMeshPtr &);
    // 0x006dd640
    bool FindNavMeshTriangle(::NavMeshPtr &, unsigned short &);
    // 0x006dd6a0
    bool HasValidTriangle_006dd6a0();
    // 0x006ddbe0
    void ResetLocation();
    // 0x006de250
    bool HasPathingLocation();
    // 0x006df010
    void LoadGame(::BGSLoadGameBuffer *);
};
