// fallout_shared/magic/effectitem_decls.h: declares TESForm, InterfaceManager, TESFile, BGSImpactData__IMPACT_DATA_DATA, EffectSetting and more
#ifndef FNV_EFFECTITEM_DECLS_H
#define FNV_EFFECTITEM_DECLS_H


#include "fnv/decl/BGSDebris.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Node406.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0070e000.h"
class TESForm
{
  public:
    bool GetInitialized() const;
};

class Tile;
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};

class PerkEntryConditionSet
{
  public:
    void InitItem(TESForm* form);
    void Load(class TESFile* file);
    bool Compare(PerkEntryConditionSet* other);
public:
    void InitializeConditionItems();
};

class TESFile
{
  public:
    bool IsEndianConversionRequired();
};

class BGSImpactData__IMPACT_DATA_DATA
{
  public:
    void Endian();
};

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);

class MagicCaster;
class MagicItem;
class EffectItem;

template <class T> class BSStringT
{
  public:
    T* data;
    unsigned int length;
    ~BSStringT();
};

class EffectSetting
{
  public:
    bool IsDetrimental();
    int GetAssociatedActorValue();
public:
    int GetArchetype();
};

class MemoryManager
{
  public:
};


struct MagicEffectEntry
{
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
    void Endian();
};

class EffectItem
{
  public:
    MagicEffectEntry data;
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    PerkEntryConditionSet Conditions;

    int GetEffectID();
    int GetAffectedActorValue();
    bool IsDetrimental();
    bool IsHostile();
    void* GetScript();
    BSStringT<char> GetEffectName();
    bool IsScriptBasedEffect();
    bool Load(TESFile* file, const char* actorEffect);
    EffectItem* Delete(unsigned int flags);
};

class ActiveEffect
{
  public:
    virtual void Destroy(bool);
    unsigned char storage[68];
    ActiveEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
    ~ActiveEffect();
};

class ScriptEffect : public ActiveEffect
{
  public:
    virtual void Destroy(bool);
    void* script;
    unsigned int unknown;
    ScriptEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};

class EffectItemListItems
{
  public:
    void* first;
    void* last;
};

class EffectItemList
{
  public:
    void* vtable;
    EffectItemListItems Items;
    int hostileCount;
    void AddItem(EffectItem* item);
};

#endif
