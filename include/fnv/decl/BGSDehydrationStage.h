#pragma once

class SpellItem;

class BGSDehydrationStage {
public:
    // 0x004018b0
    static ::BGSDehydrationStage *FindStage(float);
    // 0x004024e0
    static ::BGSDehydrationStage **AllocateStageArray(unsigned int);
    // 0x0050f9a0
    void FUN_0050f9a0(::SpellItem *);
    // 0x005a7160
    BGSDehydrationStage();
};
