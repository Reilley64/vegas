#ifndef FNV_MODIFIERLIST_H
#define FNV_MODIFIERLIST_H
#include "fnv/decl/FUN_00937b30_shell.h"
#include "fnv/decl/fnv_00937c60__ModifierList_h.h"
#include "layout_support.h"
class ActorValueModifierList : public BSSimpleList<Modifier*>
{
  public:
    void CopyModifierListFrom(ActorValueModifierList*);
    float GetActorValueModifierAmount(char);
    void InitLoadGame(BGSLoadFormBuffer*);

    bool m_bAllowZeroValueModifiers;  // +0x8
    unsigned char layoutPadding9[3];
    ModifierPointerList* m_ppModifiedActorValues;  // +0xC
};
#endif
