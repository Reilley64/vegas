// Source layout: MagicTarget. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICTARGET_H
#define FNV_MAGICTARGET_H
#include <cstdint>
#include "layout_support.h"
class ActiveEffect;
class MagicCaster;
class MagicItem;
class MagicTarget
{
  public:
    bool m_bLeadingFlag;  // +0x4
    bool m_bSecondFlag;         // +0x5
    unsigned short layoutPadding6;
    BSSimpleList<MagicEffectContext*> m_kActiveEffectList;  // +0x8
    virtual bool AddEffectToTarget(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect, bool immediate);
public:
    bool HasSpell(::MagicItem *, bool);
public:
    void UpdateActiveEffects(float);
public:
    void Dispel(::MagicItem *, ::MagicCaster *, ::ActiveEffect *);
public:
    void DispelAllEffects();
public:
    static ::MagicTarget *GetMagicTargetByID(std::uintptr_t);
};
#endif
