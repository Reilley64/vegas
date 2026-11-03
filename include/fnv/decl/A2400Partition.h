#pragma once

class A2400Source;
struct A2400TriangleSet;

class A2400Partition {
public:
    // 0x00a82400
    void BuildTriangleList(::A2400TriangleSet *, ::A2400Source *, unsigned short *);
};
