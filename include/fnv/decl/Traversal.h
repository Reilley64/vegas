#pragma once

struct Region;
struct View;

struct Traversal {
public:
    // 0x0044e820
    bool FindKeyInTraversal(int, const int *);
    // 0x00b5f170
    void UpdateVisibility(::Region *, ::View *, int, bool);
};
