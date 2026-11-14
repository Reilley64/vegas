#pragma once

class BGSImpactData;
struct ImpactSwap;

class BGSImpactDataSet {
public:
    // 0x0058e9d0
    ::BGSImpactData *GetImpactDataForMaterial(int);
    // 0x0058eeb0
    static void RefreshImpactData(::ImpactSwap *);
    // 0x011ca830
    static ::BGSImpactDataSet *ms_pImpactDataSet;
};
