#pragma once

struct QueryState;

struct VirtualMachine {
public:
    // 0x00dd1400
    void Execute(const ::QueryState *, unsigned char *__restrict, int);
};
