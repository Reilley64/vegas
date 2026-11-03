#pragma once

struct Arc;
struct Ball;
struct Edge;
struct Location;
struct Point;

struct Search {
public:
    // 0x006a0c50
    bool TraceArcOnBall(const ::Edge &, const ::Ball &, struct ::Arc, ::Edge &);
    // 0x006ab670
    ::Point FindPath(int, ::Location *, ::Point *, ::Location *, float);
};
