#pragma once

class Actor;
class DialogueResponse;
struct FUN_00a57c10_This;

struct StandIn {
public:
    // 0x00479810
    void FUN_00479810();
    // 0x004a0490
    void *FUN_004a0490(unsigned int);
    // 0x006a2770
    void FUN_006a2770(unsigned int, unsigned int);
    // 0x0072ce30
    ::StandIn *Initialize();
    // 0x0083c8a0
    void FUN_0083c8a0(::DialogueResponse *);
    // 0x008c1680
    bool FUN_008c1680(::Actor *);
    // 0x00907430
    void CallTargetWithFloat(int, int, int);
    // 0x00a57c10
    int FUN_00a57c10(::FUN_00a57c10_This *, int);
    // 0x00a97700
    ::StandIn *InitializeRangeLODData();
    // 0x00b907f0
    void *FUN_00b907f0(unsigned int);
};
