#pragma once

struct SearchLocation;
struct SearchResult;

struct DoorSearchInit {
public:
    // 0x006f34e0
    bool InitDoorSearch(::SearchLocation *, ::SearchLocation *, ::SearchResult *, int, float, void *, int);
};
