#pragma once

struct ProcessArgs;
struct SearchObject;

struct ShadowProcessor {
public:
    // 0x00b5bbe0
    void ProcessTargetIfEligible(::SearchObject *, ::ProcessArgs, char *);
};
