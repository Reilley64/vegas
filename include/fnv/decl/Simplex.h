#pragma once

struct Transform;
struct Vector;

struct Simplex {
public:
    // 0x00da8500
    int FUN_00da8500(const ::Vector *, ::Vector *, int);
    // 0x00daa7e0
    void FUN_00daa7e0(void *, void *, const struct ::Transform *);
};
