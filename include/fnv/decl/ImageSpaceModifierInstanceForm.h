#pragma once

class NiAVObject;
class TESImageSpaceModifier;

class ImageSpaceModifierInstanceForm {
public:
    // 0x005299a0
    static ::ImageSpaceModifierInstanceForm *Trigger(::TESImageSpaceModifier *, float, ::NiAVObject *);
    // 0x00529c90
    static void Stop(::TESImageSpaceModifier *);
};
