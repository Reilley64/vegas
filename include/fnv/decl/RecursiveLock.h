#pragma once

struct BSCriticalSectionEntry;

class RecursiveLock {
public:
    // 0x00a0c850
    void Unlock(::BSCriticalSectionEntry **, unsigned int *, unsigned int *);
};
