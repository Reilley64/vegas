#pragma once

struct Package;
struct Shape;

struct State {
public:
    // 0x00980ae0
    void SetupPackageTarget(::Package *);
    // 0x00e4bbe0
    int FUN_00e4bbe0(::Shape *, ::Shape *, int *__restrict, int *__restrict, unsigned char, int);
};
