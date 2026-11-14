#pragma once

class HeapStatsX;

struct AbstractHeapX {
public:
    // 0x00aaa0e0
    void GetHeapStats(::HeapStatsX *, bool);
};
