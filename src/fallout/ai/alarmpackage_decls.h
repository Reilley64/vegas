// fallout/ai/alarmpackage_decls.h: declares SpellItem, TESLevSpell, FormChangeMask, BGSLoadGameBuffer, BGSLoadFormBuffer and more
#ifndef FNV_ALARMPACKAGE_DECLS_H
#define FNV_ALARMPACKAGE_DECLS_H


#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/symbols_00483000.h"
#include "BaseFormComponent.h"
#include "TESForm.h"

// Only the TESForm inheritance is needed for these RTTI casts.
class SpellItem : public TESForm
{
};
class TESLevSpell : public TESForm
{
};

class FormChangeMask
{
  public:
    unsigned int uiFlags;
    FormChangeMask(unsigned int flags);
    operator bool() const;
};

// Buffer API declarations; this unit does not access their storage.
class BGSLoadGameBuffer
{
  public:
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int mask);
};


class TESSpellList : public BaseFormComponent
{
  public:
    BSSimpleList<SpellItem*> spellList;
    BSSimpleList<TESLevSpell*> leveledSpellList;
    void LoadGame(BGSLoadFormBuffer* buffer);
};


#endif
