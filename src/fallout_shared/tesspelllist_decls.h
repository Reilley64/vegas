// fallout_shared/tesspelllist_decls.h: declares BaseProcess, TESForm, BGSCameraPath, SpellItem, TESLevSpell and more
#ifndef FNV_TESSPELLLIST_DECLS_H
#define FNV_TESSPELLLIST_DECLS_H


#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/xEffOwner.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011de000.h"
class ActorPackageContext;
class InventoryStackRecord;

class BaseProcess
{
  public:
    ActorPackageContext* GetCurrentProcessData();
};

#include "fnv/bs_simple_list.h"

class TESFile;
class BGSCameraShot;
class BGSPerkEntry;
class SpellItem;
class TESLevSpell;
class TESActorBase;
class TESForm
{
  public:
    TESFile* GetFile(int);
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
public:
    void ClearData();
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};
class SpellItem : public TESForm
{
};
class TESLevSpell : public TESForm
{
};
class TESActorBase : public TESForm
{
};
class Actor
{
  public:
    TESActorBase* GetActorBase();
};
class PlayerCharacter : public Actor
{
  public:
};
class TESAttributes
{
  public:
    virtual ~TESAttributes();
};

class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void InitializeComponent();
};

class TESSpellList : public BaseFormComponent
{
  public:
    TESSpellList();
    void InitItem(TESForm*);
    virtual void InitializeComponent();
    BSSimpleList<InventoryStackRecord*> spells;
    BSSimpleList<InventoryStackRecord*> leveledSpells;
    void ClearComponent();
    void ClearSpells();
};

#endif
