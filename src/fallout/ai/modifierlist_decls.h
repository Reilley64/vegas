// fallout/ai/modifierlist_decls.h: declares Modifier
#ifndef FNV_MODIFIERLIST_DECLS_H
#define FNV_MODIFIERLIST_DECLS_H


#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/ModifierRoutingList.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/symbols_00937000.h"
#include "layout_support.h"

class Modifier
{
  public:
    char cKey;
    unsigned char padding[3];
    float fValue;

    Modifier(Modifier* other);
    Modifier(char key, float value);
};

class ModifierPointerList
{
  public:
    Modifier** m_ppModifiers;
    ModifierPointerList();
    ModifierPointerList(ModifierPointerList* other);
    void RemoveModifier(int key);
    ~ModifierPointerList();
};

class ActorValueModifierList : public BSSimpleList<Modifier*>
{
  public:
    bool m_bAllowZeroValueModifiers;
    unsigned char padding[3];
    ModifierPointerList* m_ppModifiedActorValues;

    Modifier* GetModifierItem(char key);
    float GetActorValueModifierAmount(char key, bool& found);
    float GetActorValueModifierAmount(char key);
    enum ClampStyle
    {
        ClampNone = 0
    };
    void ModifyModifier(char key, float delta, ClampStyle clamp);
    void CopyModifierListFrom(ActorValueModifierList* other);
    void RemoveAllModifiers();
    void AddFastModifier(char key, Modifier* modifier);
};



#endif
