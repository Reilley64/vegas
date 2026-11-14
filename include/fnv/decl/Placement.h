#pragma once

struct NiPoint3;
struct PlacedRef;

struct Placement {
public:
    // 0x004c6dd0
    ::PlacedRef *PlaceObject(::PlacedRef *, void *, int, int, ::NiPoint3 *, ::NiPoint3 *);
};
