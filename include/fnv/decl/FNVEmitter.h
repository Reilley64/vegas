#pragma once

struct FNVElement;

struct FNVEmitter {
public:
    // 0x005882a0
    ::FNVElement *GetOrCreateElement(bool);
};
