#pragma once

struct ItemValue;

struct ActivePassNode {
public:
    // 0x00b99770
    void InsertItem(volatile ::ItemValue, int (*)(unsigned int, unsigned short));
};
