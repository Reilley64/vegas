#pragma once

struct Context;
struct Ptr;
struct TraceArg;

struct Worker {
public:
    // 0x004e56c0
    void UpdateWaterSettings(::Context *);
    // 0x00666080
    bool AdvanceState(int, int);
    // 0x006662a0
    bool ProcessNodeChain(int, int);
    // 0x00c3ea60
    bool TryDequeue(::Ptr *);
    // 0x00d04d80
    void FUN_00d04d80(::TraceArg *, int);
};
