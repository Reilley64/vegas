#pragma once

struct QHeadPtr;

struct LockFreeQueue {
public:
    // 0x0044cd40
    void Enqueue(const ::QHeadPtr &);
};
