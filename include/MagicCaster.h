// Source layout: MagicCaster. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_H
#define FNV_MAGICCASTER_H
#include "layout_support.h"
class EffectItem;
class MagicCaster
{
  public:
    MagicEffectCollection* apTargetLight;         // +0x4
    MagicCaster__State eState;  // +0x8
    virtual void CastSpellOnCaster(SpellItem* spell, bool immediate);
    virtual void CastSpellOnSelf(SpellItem* spell, bool immediate);
    virtual void CastSpellAtLocation(SpellItem* spell, bool immediate);
    virtual void CastMagicItem(MagicItem* item, bool immediate, MagicTarget* target, float value, bool flag);
    virtual void CastSpellAtTarget(SpellItem* spell, MagicTarget* target, bool immediate);
    virtual void CastMagicItemOnObject(MagicItem* item, TESBoundObject* object, bool immediate);
    virtual MagicTarget* GetSpellTarget();
    virtual void UpdateCastState();
    virtual void CompleteCast();
    virtual void SpellCast(MagicItem* item, bool immediate);
    virtual bool CanCast(MagicItem* item, float* value, int* reason, bool flag);
    virtual TESObjectREFR* GetCasterReference();
    virtual NiNode* GetMagicNode();
    virtual MagicItem* GetSelectedMagicItem();
    virtual bool HasActiveEffect(ActiveEffect* effect);
    virtual float GetCasterEffectiveness(bool flag, float value);
    virtual void SetSelectedMagicItem(MagicItem* item);
    virtual MagicTarget* GetCurrentMagicTarget();
    virtual void SetMagicTarget(MagicTarget* target);
    virtual ActiveEffect* CreateActiveEffect(MagicItem* item, EffectItem* effect, TESBoundObject* source);
public:
    void RemoveCastingArt();
};
#endif
