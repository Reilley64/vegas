#pragma once

#include <cstdint>

class FormChangeMask;
class FormChangeRecord;

struct FUN_00845b90_shell
{
    void** vtable_;
    unsigned int count_;
    void** data_;
    unsigned int tail_;

    // 0x00845b90
    FUN_00845b90_shell* InitArray(int size);
};

class BGSSaveLoadChangesMapBase : public FUN_00845b90_shell
{};

class BGSSaveLoadChangesMap : public BGSSaveLoadChangesMapBase
{
public:
    // 0x00845550
    BGSSaveLoadChangesMap();
    // 0x008455b0
    ~BGSSaveLoadChangesMap();
    FormChangeRecord* FUN_009a4250(uintptr_t formID);
    bool ContainsChangeFlags(unsigned int formID, FormChangeMask flags);
    // 0x008457b0
    void AddFormChangeFlags(unsigned int formID, FormChangeMask flags);
    // 0x008458b0
    void ApplyFormQuantityChange(unsigned int formID, FormChangeMask flags);
    // 0x00845a20
    bool HasFormChanges(uintptr_t formID);
    // 0x00845a80
    bool ClearChangeFlags(unsigned int formID, FormChangeMask flags);
};
