#pragma once

struct NiRTTI;

struct NiObject {
public:
    // 0x00621a40
    void *FUN_00621a40();
    // 0x00653290
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
