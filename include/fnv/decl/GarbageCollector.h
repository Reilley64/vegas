#pragma once

class TESObjectREFR;

class GarbageCollector {
public:
    // 0x0040fc90
    static void QueryCurrentThread(bool);
    // 0x00868270
    static void Remove(::TESObjectREFR *);
    // 0x00868850
    static void Update();
    // 0x00868d10
    static void ClearTempEffects();
};
