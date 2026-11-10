#pragma once

class Actor;
struct PathingRequest;
class PathingSolution;

class PathBuilder {
public:
    // 0x006c8d30
    PathBuilder(::PathingRequest *, ::PathingSolution *);
    // 0x006c9b20
    bool FUN_006c9b20();
    // 0x006ca850
    bool BuildActorPathSegments(::Actor *);
    // 0x009dfd50
    void *FUN_009dfd50();
};
