#pragma once

struct A3B0Filter;

struct A3B0Controller {
public:
    // 0x0062a3b0
    void SetFilter(int, const ::A3B0Filter &);
};
