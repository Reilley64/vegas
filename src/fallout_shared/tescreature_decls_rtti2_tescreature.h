// fallout_shared/tescreature_decls_rtti2_tescreature.h: declares FormChangeMask, BGSLoadFormBuffer, TESAttackDamageForm, TESModelList, BGSBodyPartData and more
#ifndef TESCREATURE_DECLS_H
#define TESCREATURE_DECLS_H

#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_00489a60.h"
#include "fnv/decl/FUN_005f75e0.h"
#include "fnv/decl/FUN_005f77b0.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011c3000.h"
namespace TESDataHandlerTypes {
class TESFaction;
}
class BGSBodyPartData;
struct BGSLoadFormBuffer;

class FormChangeMask
{
  public:
    int flags;
    FormChangeMask(const FormChangeMask& other);
    operator bool() const;
};

struct BGSLoadFormBuffer
{
  public:
};

class TESAttackDamageForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char attackLayout[4];
    TESAttackDamageForm();
    ~TESAttackDamageForm();
};

class TESModelList
{
  public:
    virtual void vfn_00() = 0;
    unsigned char modelListLayout[0x10];
    TESModelList();
    ~TESModelList();
};

class BGSBodyPartData
{
  public:
    virtual ~BGSBodyPartData();  // the original class is polymorphic (rtti_variants.py)
  public:
    static BGSBodyPartData* ms_pBodyPartData;
    char _pdbpad_1[51];
    char pPartArray_pad33_pad33_pad33[60];
    void* m_pRagdoll;
};

class TESCombatStyle;
class BGSImpactDataSet;
class BGSListForm;
struct CombatController;

extern "C" char gVtable_TESCreature;
extern "C" char gVtable_30;
extern "C" char gVtable_64;
extern "C" char gVtable_70;
extern "C" char gVtable_7c;
extern "C" char gVtable_90;
extern "C" char gVtable_b0;
extern "C" char gVtable_b8;
extern "C" char gVtable_c4;
extern "C" char gVtable_d0;
extern "C" char gVtable_dc;
extern "C" char gVtable_f4;
extern "C" char gVtable_100;
extern "C" char gVtable_104;
extern "C" char gVtable_10c;
extern "C" char gVtable_114;
extern "C" char gDestructorEhHandler;

class CreatureSoundCollection
{
  public:
    unsigned char soundLists[0x58];
    CreatureSoundCollection();
    ~CreatureSoundCollection();
};

class TESActorBaseData
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[0x30];
    bool GetFlag(unsigned int flag) const;
};

class CombatProcedure
{
  public:
    void Initialize(CombatController* controller);
};

class TESNPC
{
  public:
    void Revert(BGSLoadFormBuffer* buffer);
};

enum ENUM_FORM_ID
{
    kCreature = 0x2b
};
class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
  public:
    void SetFormType(ENUM_FORM_ID);
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
public:
    ::TESFile *GetFile(int);
};
extern TESDataHandlerTypes::TESFaction* DAT_011cb550;
class TESDataHandler
{
  public:
};
class TESAIForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[0x1c];
    void SetResponsibility(unsigned char, bool);
    void SetAggression(unsigned char, bool);
    void SetConfidence(unsigned char, bool);
    void SetEnergy(unsigned char, bool);
};
class TESBoundAnimObject
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[44];
};
class TESForm;
class TESContainer
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
public:
    void InitItem(::TESForm *);
};
class TESForm;
class BGSTouchSpellForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
public:
    void InitItem(::TESForm *);
};
class TESForm;
class TESSpellList
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[16];
public:
    void InitItem(::TESForm *);
};
class TESHealthForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[4];
};
class TESAttributes
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
};
class TESAnimation
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
};
class TESFullName
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
};
class TESModel
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[20];
};
class TESForm;
class TESScriptableForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
public:
    void InitItem(::TESForm *);
};
class ActorValueOwner
{
  public:
    virtual void vfn_00() = 0;
};
class TESForm;
class BGSDestructibleObjectForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[4];
public:
    void InitItem(::TESForm *);
};
class TESActorBase : public TESBoundAnimObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
  public:
    TESActorBase();
    ~TESActorBase();
};

class TESCreature : public TESActorBase, public TESAttackDamageForm, public TESModelList
{
  public:
    union
    {
        CreatureSoundCollection* m_pCreatureSounds;
        TESCreature* m_pCreature;
    };
    unsigned char dataPadding;
    unsigned char m_ucField00;
    unsigned char m_ucField01;
    unsigned char m_ucField02;
    unsigned char m_ucCreatureType;
    unsigned char pad131[3];
    float m_fFirstCreatureStat;
    float m_fSecondCreatureStat;
    float m_fThirdCreatureStatCur;
    TESCombatStyle* m_pCombatStyle;
    BGSBodyPartData* m_pBodyPartDataCur;
    int m_eImpactMaterial;
    BGSImpactDataSet* m_pImpactDataSet;
    bool m_bHasImpactDataSet;
    unsigned char pad151[3];
    int m_eSoundLevel;
    BGSListForm* m_pCreatureListForm;
    unsigned char m_cCreatureDataFlag;

    TESCreature();
    ~TESCreature();
    void ClearData();
    BGSBodyPartData* GetBodyPartData();
    void ResetFormData();
    void LoadGame(BGSLoadFormBuffer* buffer);
    CreatureSoundCollection* GetMutableCreatureSounds();
    void SetCreatureSoundsFrom(TESCreature* soundCreature);
    void SetBodyPartData(BGSBodyPartData* bodyPartData);
    void Revert(BGSLoadFormBuffer* buffer);
};

#endif
