#pragma once

class TESForm;
enum DEFAULT_OBJECT;

class BGSDefaultObjectManager {
public:
    // 0x0058db10
    static ::TESForm *GetDefaultObjectByIndex(::DEFAULT_OBJECT);
};
