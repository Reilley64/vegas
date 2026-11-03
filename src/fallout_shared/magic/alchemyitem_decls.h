// fallout_shared/magic/alchemyitem_decls.h: declares TESForm, TESFormInitFlag, EffectItemList, IngredientItem, TESScriptableForm and more
#ifndef ALCHEMYITEM_DECLS_H
#define ALCHEMYITEM_DECLS_H


#include <cstdint>
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00874460_cls.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/fnv_00406340__EffectItemList.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
class TESFile;
class TESForm;
class SpellItem;
class TESSound;

class TESForm
{
  public:
    virtual ~TESForm();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00C();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01C();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02C();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03C();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04C();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05C();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06C();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07C();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08C();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09C();
    virtual void vfn_0A0();
    virtual void vfn_0A4();
    virtual void vfn_0A8();
    virtual void vfn_0AC();
    virtual void vfn_0B0();
    virtual void vfn_0B4();
    virtual void vfn_0B8();
    virtual void vfn_0BC();
    virtual void vfn_0C0();
    virtual void vfn_0C4();
    virtual void vfn_0C8();
    virtual void vfn_0CC();
    virtual void vfn_0D0();
    virtual void vfn_0D4();
    virtual void vfn_0D8();
    virtual void vfn_0DC();
    virtual void vfn_0E0();
    virtual void vfn_0E4();
    virtual void vfn_0E8();
    virtual void vfn_0EC();
    virtual void vfn_0F0();
    virtual void vfn_0F4();
    virtual void vfn_0F8();
    virtual void vfn_0FC();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10C();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11C();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12C();
    virtual const char* vfn_130();

    TESFile* GetFile(int fileIndex);
public:
    bool GetInitialized() const;
public:
    void ClearData();
public:
    static ::TESForm *LookupFormByEditorID(const char *);
};

class TESFormInitFlag
{
  public:
};

class EffectItemList
{
  public:
public:
    bool FUN_00405da0();
};

class IngredientItem
{
  public:
};

class TESScriptableForm
{
  public:
    void InitItem(TESForm* form);
};

class BGSDestructibleObjectForm
{
  public:
    void InitItem(TESForm* form);
};

class TESModelTextureSwap
{
  public:
    void InitItem(TESForm* form);
};

class BGSPickupPutdownSounds
{
  public:
    void InitItem(TESForm* form);
};

class MagicItemObject
{
  public:
    virtual void InitItem();
};

class SpellItem : public TESForm
{
};
class TESSound : public TESForm
{
};

class AlchemyItem : public TESForm
{
  public:
    unsigned char pad004[0xB4];
    int unk0B8;
    unsigned char unk0BC;
    unsigned char pad0BD[3];
    std::intptr_t unk0C0;
    float unk0C4;
    std::intptr_t unk0C8;

    void ClearData();
    void ResetFormData();
    void InitItem();
    void* FUN_004030b0();
    void SetSound(TESSound* sound);
};


#endif
