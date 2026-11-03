#pragma once

class EffectItem;
class MagicCaster;
class MagicItem;

class ScriptEffect {
public:
    // 0x00827740
    ScriptEffect(::MagicCaster *, ::MagicItem *, ::EffectItem *);
};
