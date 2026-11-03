#ifndef FNV_MODIFIERLIST_H
#define FNV_MODIFIERLIST_H
#include "layout_support.h"
class ActorValueModifierList : public BSSimpleList<Modifier*>
{
  public:
    bool m_bAllowZeroValueModifiers;  // +0x8
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
    ModifierPointerList* m_ppModifiedActorValues;  // +0xC
public:
    void RemoveAllModifiers();
public:
    float GetActorValueModifierAmount(char, bool &);
public:
    float GetActorValueModifierAmount(char);
public:
    void FUN_00937d50(int);
};
#endif
