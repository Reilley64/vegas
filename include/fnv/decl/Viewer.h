#pragma once

struct Display;
struct Input;
struct LineDrawer;

struct Viewer {
public:
    // 0x00de7020
    void FUN_00de7020(::Input *, ::LineDrawer *, int, int);
    // 0x00de7a70
    void FUN_00de7a70(::Input *, ::Display *, int, int);
};
