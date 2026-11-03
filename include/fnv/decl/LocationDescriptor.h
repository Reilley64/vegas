#pragma once

class MobileObject;
class TESForm;
class TESObjectCELL;
class TESObjectREFR;

class LocationDescriptor {
public:
    // 0x0067f2a0
    ::TESObjectREFR *ResolveLocationReference(::MobileObject *);
    // 0x0067f390
    ::TESObjectREFR *GetLocationReference();
    // 0x0067f3c0
    void FUN_0067f3c0(::TESObjectREFR *);
    // 0x0067f3e0
    ::TESObjectCELL *GetLocationCellReference();
    // 0x0067f4d0
    void Copy(::LocationDescriptor *, bool);
    // 0x0067f760
    void InitItem(::TESForm *);
};
