#pragma once

struct NiPoint3;
struct Parent;

struct SeenDataShell {
public:
    // 0x00879f20
    void AttachMarkersForSeenData(::Parent *, const ::NiPoint3 &, int);
};
