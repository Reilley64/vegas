#pragma once

struct BoolResult;
struct VMState;

struct Interpreter {
public:
    // 0x00e66950
    ::BoolResult *FUN_00e66950(::BoolResult *, const ::VMState *, const unsigned char *, int);
};
