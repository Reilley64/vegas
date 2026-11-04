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
    bool FUN_00822f70(ActorValue::Index actorValue);
    bool m_bLeadingFlag;  // +0x4
    bool m_bSecondFlag;         // +0x5
    unsigned char layoutPadding6[2];
    BSSimpleList<MagicEffectContext*> m_kActiveEffectList;  // +0x8
    virtual bool AddEffectToTarget(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect, bool immediate);
public:
    bool HasSpell(::MagicItem *, bool);
public:
    void UpdateActiveEffects(float);
public:
    void Dispel(::MagicItem *, ::MagicCaster *, ::ActiveEffect *);
public:
    static ::MagicTarget *GetMagicTargetByID(uintptr_t);
};
#endif
