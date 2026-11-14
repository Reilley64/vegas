#pragma once

struct RefObject;

struct CellRefScan {
public:
    // 0x0054cf20
    ::RefObject *FindFirstRefByType(int, bool);
};
