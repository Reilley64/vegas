// Authored research header for fallout_shared/magic/magicitem.cpp.
//   TESForm 0x18, TESBoundObject 0x30, TESFullName 0xC,
//   EffectItemList 0x10 (vftable + BSSimpleList<EffectItem*> base at +4,
//   hostile count at +0xC), MagicItem 0x1C (TESFullName + EffectItemList).
// MagicItemForm carries MagicItem as second base at +0x18;
// MagicItemObject carries it as second base at +0x30.
#ifndef FNV_MAGICITEM_DECLS_H
#define FNV_MAGICITEM_DECLS_H

#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_00403db0_shell.h"
#include "fnv/decl/FUN_00403f80_shell.h"
#include "fnv/decl/FUN_004086e0_shell.h"
#include "fnv/decl/FUN_004087e0_Shell.h"
#include "fnv/decl/FUN_00408a00_Struct.h"
#include "fnv/decl/FUN_0043b410_class.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_004811e0_shell.h"
#include "fnv/decl/FUN_0092c870_shell.h"
#include "fnv/decl/NPCModelView.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/fnv_00444f10__FUN_00444f10_shell.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004471c0__FUN_004471c0_shell.h"
#include "fnv/decl/fnv_00447330__FUN_00447330_shell.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_011c3000.h"
#include "layout_support.h"

struct MagicSystem
{
    enum Range
    {
        SELF = 0,
        TOUCH = 1,
        TARGET = 2,
        RANGE_COUNT = 3
    };
};

class TESForm
{
  public:
    virtual ~TESForm();
    unsigned char formPad[20];
};

class TESBoundObject : public TESForm
{
  public:
    virtual ~TESBoundObject();
    unsigned char boundPad[24];
};

class TESFullName
{
  public:
    virtual ~TESFullName();
    unsigned char namePad[8];
};

// in EffectSetting. The unused tail of TESModel is retained at its real size.
class TESModel
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(TESModel* component);
    virtual bool CompareWithBase(TESModel* component);
    BSStringT<char> m_kModelFilePath;
    unsigned char modelTail[12];
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    unsigned int GetModelLength() const;
};

class EffectSetting : public TESForm, public TESModel
{
  public:
    void FUN_004088c0();
    bool HasEffectID();
    bool UsesAssociatedActorValue();
    bool HasNoAssociatedActorValue();
public:
    int NormalizeEffectLoadedCount();
};

class EffectItem
{
  public:
    bool IsHostile();
    bool IsDetrimental();
    MagicSystem::Range GetRange();
};

class EffectItemList : public BSSimpleList<EffectItem*>
{
  public:
    virtual ~EffectItemList();
    int m_iEffectCount;
};

class MagicItem : public TESFullName, public EffectItemList
{
  public:
    virtual ~MagicItem();
    static MagicItem* GetMagicItemByID(unsigned int auiID);
    EffectSetting* GetEffectSettingForRange(MagicSystem::Range aeRange);
    void ClearEffectList();
    void Preload(bool);
    void Unload(bool);
    bool IsLoaded();
    bool IsLoading();

  protected:
    void LoadEffectsFromForm(TESForm* apForm);
};

class MagicItemForm : public TESForm, public MagicItem
{
  public:
    virtual ~MagicItemForm();
};

class MagicItemObject : public TESBoundObject, public MagicItem
{
  public:
    virtual ~MagicItemObject();
};

// PC component offsets used by associated weapon, armor, and creature loads.
class TESObjectWEAP : public TESBoundObject
{
  public:
    unsigned char fullName[12];
    TESModel model;
};
class TESBipedModelForm
{
  public:
};
class TESObjectARMO : public TESBoundObject
{
  public:
    unsigned char components[0x40];
    TESBipedModelForm biped;
};
class TESNPC : public TESForm
{
  public:
};
class TESAnimation
{
  public:
    unsigned char data[0x18];
    bool HasSpecialAnimations();
};
class TESModelList
{
  public:
};
class TESCreature : public TESForm
{
  public:
    unsigned char actorComponents[0xAC];
    TESAnimation animation;
    TESModel model;
    unsigned char creatureComponents[0x20];
    TESModelList modelList;
};
class Model
{
  public:
};
template <class T> class NiPointer
{
    T* object;

  public:
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
};
struct KFModel;
struct ModelLoader
{
  public:
};
void FUN_0040ab50();
struct TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
char* FUN_0040ab30(char*, int);
extern "C" void FormHeapFreeAndLog(const void*);
#endif
