#pragma once

class SearchNode;
struct PathNode;

struct PathSearch {
public:
    // 0x006b3a30
    ::SearchNode *FUN_006b3a30();
    // 0x006f3d90
    bool FindPath(int, int, bool);
    // 0x00996860
    ::PathNode *FindPath();
};
