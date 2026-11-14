#pragma once

class ReferenceIntersectionData;
class TESForm;
class TESObjectREFR;

class ExtraDecalRefs {
public:
    // 0x00433db0
    void FUN_00433db0(::TESForm *);
    // 0x00434410
    ::ReferenceIntersectionData *FindDecalReference(::TESObjectREFR *);
};
