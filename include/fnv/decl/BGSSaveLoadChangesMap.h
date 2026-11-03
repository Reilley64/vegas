#pragma once

class FormChangeMask;

class BGSSaveLoadChangesMap {
public:
    // 0x00845550
    BGSSaveLoadChangesMap();
    // 0x008455b0
    ~BGSSaveLoadChangesMap();
    // 0x008457b0
    void AddFormChangeFlags(unsigned int, ::FormChangeMask);
    // 0x008458b0
    void ApplyFormQuantityChange(unsigned int, ::FormChangeMask);
    // 0x00845a20
    bool HasFormChanges(unsigned int);
    // 0x00845a80
    bool ClearChangeFlags(unsigned int, ::FormChangeMask);
};
