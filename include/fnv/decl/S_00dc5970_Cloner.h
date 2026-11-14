#pragma once

struct S_00dc5970_ClassImpl;
struct S_00dc5970_Object;

struct S_00dc5970_Cloner {
public:
    // 0x00dc5440
    ::S_00dc5970_ClassImpl *FUN_00dc5440(::S_00dc5970_ClassImpl *);
    // 0x00dc5970
    ::S_00dc5970_Object CloneObject(const ::S_00dc5970_Object &);
};
