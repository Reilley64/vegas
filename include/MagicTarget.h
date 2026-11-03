// Source layout: MagicTarget. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICTARGET_H
#define FNV_MAGICTARGET_H
#include "layout_support.h"
#pragma pack(push, 4)
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
    static ::MagicTarget *GetMagicTargetByID(unsigned int);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MagicTarget) == 0x10);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_bLeadingFlag) == 0x4);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_bSecondFlag) == 0x5);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_kActiveEffectList) == 0x8);
#endif
