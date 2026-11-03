#pragma once
#include <cstdint>

struct NiPoint3;
struct Node;
struct P1;
struct P2Vtbl;

struct This {
public:
    // 0x009ad670
    void FUN_009ad670();
    // 0x009cc510
    void FUN_009cc510();
    // 0x00b12720
    float FUN_00b12720(const ::NiPoint3 &);
    // 0x00bb6f40
    void InitShaderParams();
    // 0x00c84e20
    void FUN_00c84e20(unsigned int *);
    // 0x00ca4e50
    void FUN_00ca4e50(intptr_t, intptr_t);
    // 0x00dba690
    void FUN_00dba690();
    // 0x00de59f0
    void FUN_00de59f0(::P1 *, ::P2Vtbl *, int, int);
    // 0x00e24140
    void PushFront(::Node *volatile);
};
