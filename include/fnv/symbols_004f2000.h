#pragma once

class TESSound;
struct NiTexturingProperty;
struct RDLItem;

// 0x004f24e0
void FUN_004f24e0(::TESSound *, bool, bool);
// 0x004f2640
bool FUN_004f2640(::RDLItem *);
// 0x004f2ee0
::NiTexturingProperty *GetDefaultFullMaskTextureProperty();
