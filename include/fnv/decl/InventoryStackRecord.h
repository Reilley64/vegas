#pragma once

class Actor;
struct BGSLoadFormBuffer;

class InventoryStackRecord {
public:
    // 0x00476b20
    static float GetConditionPercent(float);
    // 0x004bcb70
    bool HasPerkEntry();
    // 0x004bd510
    static float RoundToNearestStep(float, float);
    // 0x004be0b0
    float GetArmorDamageThreshold(::Actor *);
    // 0x004bef60
    void InitLoadGame(::BGSLoadFormBuffer *);
    // 0x0076b630
    InventoryStackRecord();
    // 0x007b5370
    void *GetPayloadAddress();
    // 0x009c8a90
    void SetPointers(void *, void *);
};
