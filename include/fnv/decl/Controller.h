#pragma once

struct OwnerB;
struct Ref;
struct TargetList;

struct Controller {
public:
    // 0x004f6060
    ::TargetList *CopyTargetList(::TargetList *);
    // 0x00528110
    void ProcessQueries();
    // 0x00954a70
    bool IsPlayerTargeted(::Ref *, bool);
    // 0x00a255b0
    void FUN_00a255b0(float, float, int, int, int, unsigned char, bool);
    // 0x00a2feb0
    void FUN_00a2feb0(unsigned short);
    // 0x00c5c790
    void FUN_00c5c790(float, float, float, float, float, float);
    // 0x00c66c90
    void CreateChildAndNotifySim(::OwnerB *);
    // 0x00c7b6a0
    void FUN_00c7b6a0(bool);
};
