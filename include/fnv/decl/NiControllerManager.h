#pragma once

class NiControllerSequence;
class NiFixedString;

class NiControllerManager {
public:
    // 0x0047a510
    static ::NiFixedString *FindSequenceByName();
    // 0x0047aab0
    bool ActivateControllerSequence(::NiControllerSequence *, int, bool, float, float, ::NiControllerSequence *);
    // 0x0047b220
    bool StopSequence(::NiControllerSequence *, float);
    // 0x0048fef0
    void DeactivateAllSequences(float);
};
