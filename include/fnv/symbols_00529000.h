#pragma once

class ImageSpaceModifierInstance;
class ImageSpaceModifierInstanceForm;
class NiAVObject;
class TESImageSpaceModifier;

// 0x005293f0
void FUN_005293f0(::ImageSpaceModifierInstance *);
// 0x00529ae0
::ImageSpaceModifierInstanceForm *CreateImageSpaceModifierInstance(::TESImageSpaceModifier *, float, ::NiAVObject *);
