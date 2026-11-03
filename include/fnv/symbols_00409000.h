#pragma once

class EffectSetting;
class TESBoundObject;
struct ItemExtraList;

// 0x00409060
void RegisterEffectSetting(int *);
// 0x00409720
bool FUN_00409720(::TESBoundObject *, ::ItemExtraList *, ::EffectSetting *);
