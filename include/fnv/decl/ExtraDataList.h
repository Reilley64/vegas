#pragma once

class ExtraDismemberedLimbs;
class InventoryChanges;

class ExtraDataList {
public:
    // 0x00410360
    ExtraDataList();
    // 0x00418520
    ::InventoryChanges *GetContainerChangeData();
    // 0x00418750
    bool HasExtraDataType0x2F();
    // 0x00419970
    void SetExtraHealth(float);
    // 0x0041aeb0
    void RemoveExtraDataType0x15();
    // 0x0042e8c0
    ::ExtraDismemberedLimbs *GetDismemberedLimbs();
    // 0x004bca60
    bool IsEmpty();
    // 0x00554910
    bool FUN_00554910();
};
