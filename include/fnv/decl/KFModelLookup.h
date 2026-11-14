#pragma once

struct KFModel;

class KFModelLookup {
public:
    // 0x004483e0
    ::KFModel *Lookup(const char *);
};
