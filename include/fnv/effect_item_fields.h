#ifndef FNV_EFFECT_ITEM_FIELDS_H
#define FNV_EFFECT_ITEM_FIELDS_H

class EffectSetting;

// The leading data members of EffectItem. The 32-bit getter folded into
// 0x00825c00 reads `setting` when called on an effect item.
struct EffectItemFields
{
    int magnitude;
    int area;
    int duration;
    int range;
    int actorValue;
    EffectSetting* setting;
};

#endif
