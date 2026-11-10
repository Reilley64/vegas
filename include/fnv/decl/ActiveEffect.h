#pragma once

struct BGSLoadFormBuffer;
class EffectItem;
class EffectSetting;
class MagicCaster;
class MagicItem;
template <class> class BSSimpleList;

class ActiveEffect {
public:
    // 0x00705cf0
    bool IsDone() const;
    // 0x007df1d0
    ::EffectSetting *GetEffectSetting() const;
    // 0x007df1f0
    float GetDuration() const;
    // 0x00803d30
    ActiveEffect(::MagicCaster *, ::MagicItem *, ::EffectItem *);
    // 0x00803e80
    void AddFlags(unsigned int);
    // 0x00804090
    void CopyData(::ActiveEffect *);
    // 0x00804160
    void Finalize();
    // 0x008043f0
    void AdvanceEffect(float, bool);
    // 0x00804b60
    bool IsFlagged();
    // 0x00804bc0
    void SetEffectiveness(float);
    // 0x008067b0
    void ApplyLoadBuffer(::BGSLoadFormBuffer *);
    // 0x00806a90
    static void LoadActiveEffectList(::BGSLoadFormBuffer *, ::BSSimpleList< ::ActiveEffect *> *);
    // 0x00806b50
    static void WriteActiveEffectList(::BGSLoadFormBuffer *, ::BSSimpleList< ::ActiveEffect *> *);
};
