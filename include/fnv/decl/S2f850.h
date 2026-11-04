#pragma once

struct NavMeshPtr;

struct S2f850 {
public:
    // 0x0042f850
    unsigned int AppendValue(const ::NavMeshPtr &);
    // 0x0042fcb0
    void FUN_0042fcb0(unsigned int, unsigned int);
    // 0x006c61b0
    unsigned int FUN_006c61b0(const ::NavMeshPtr &);
};
