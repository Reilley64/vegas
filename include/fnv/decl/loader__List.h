#pragma once

namespace loader { struct File; }

namespace loader {
struct List {
public:
    // 0x004144a0
    void LoadExtraData(::loader::File *, void *);
};
}
