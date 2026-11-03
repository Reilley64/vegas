#pragma once

namespace P516 { struct Owner; }
namespace P516 { struct Paths; }
namespace P516 { struct Task; }

namespace P516 {
struct Loader {
public:
    // 0x004465f0
    void LoadFiles(::P516::Paths *, ::P516::Owner *, int, ::P516::Task *, const char *);
};
}
