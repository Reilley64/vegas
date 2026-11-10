#pragma once

class NiPoint3Ex;
struct PathingLocation;
struct TargetNavInfo;
struct VirtParam;

struct TargetHost {
public:
    // 0x004ee5d0
    void CallVirtualAndForward(::VirtParam *, void *);
    // 0x006f0050
    bool FUN_006f0050(const ::NiPoint3Ex &, ::NiPoint3Ex &, ::TargetNavInfo *, int, const ::NiPoint3Ex &, ::PathingLocation &, ::PathingLocation &);
};
