#pragma once

struct BaseShape;
struct Cont;
struct Display;
struct Transform;
struct XfResult;
template <class> struct Array;

struct Node {
public:
    // 0x00ddfd10
    void FUN_00ddfd10(const ::BaseShape *, const struct ::Transform &, ::Array< ::Display *> &);
    // 0x00de0f90
    void FUN_00de0f90(void *, ::XfResult *);
    // 0x00de2da0
    void FUN_00de2da0(::Cont *);
};
