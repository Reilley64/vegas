#pragma once
#include <cstdint>

class NiObject;
struct ArgClass;

struct HostClass {
public:
    // 0x004d7ab0
    void SendModifierMessages(intptr_t, ::NiObject *);
    // 0x00c6d3f0
    bool FUN_00c6d3f0(::ArgClass *, int);
};
