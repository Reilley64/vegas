#pragma once

class TESBoundObject;
class TESForm;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;
struct NiPoint3;

struct HandlerView {
public:
    // 0x004698a0
    ::TESObjectREFR *PlaceObjectReference(::TESBoundObject *, ::NiPoint3 *, ::NiPoint3 *, ::TESObjectCELL *, ::TESWorldSpace *, ::TESObjectREFR *, const char *, ::TESForm *);
};
