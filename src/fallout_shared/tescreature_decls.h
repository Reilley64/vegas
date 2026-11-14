// fallout_shared/tescreature_decls.h: declares FormChangeMask, BGSLoadFormBuffer, TESAttackDamageForm, TESModelList, BGSBodyPartData and more
#ifndef TESCREATURE_DECLS_H
#define TESCREATURE_DECLS_H


#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_00489a60.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
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
    FormChangeMask GetChangeFlags(unsigned int flag);
};

class TESAttackDamageForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char attackLayout[4];
    TESAttackDamageForm();
    ~TESAttackDamageForm();
public:
    unsigned short GetAttackDamage();
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

class TESCreature;
class TESFile;
enum CREATURE_SOUND_TYPE;
class CreatureSoundCollection
{
  public:
    unsigned char soundLists[0x58];
    CreatureSoundCollection();
    ~CreatureSoundCollection();
public:
    bool LoadSoundsFromFile(::TESFile *, ::CREATURE_SOUND_TYPE, ::TESCreature *);
public:
    void *DeleteThis(unsigned int);
};

class TESActorBaseData
{
  public:
    virtual void vfn_00() = 0;
    virtual void D01();
    virtual void D02();
    virtual void D03();
    virtual void D04();
    virtual void D05();
    virtual void D06();
    virtual void D07();
    virtual void D08();
    virtual void D09();
    virtual void D10();
    virtual void D11();
    virtual void D12();
    virtual void D13();
    virtual void D14();
    virtual void D15();
    virtual void D16();
    virtual void D17();
    virtual void D18();
    virtual void D19();
    virtual void D20();
    virtual void D21();
    virtual int GetBloodImpactMaterial();
    unsigned int uiFlags;
    unsigned char componentLayout[0x2c];
    bool GetFlag(unsigned int flag) const;
public:
    unsigned short GetFatigue() const;
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
    virtual ~TESForm();
    bool GetInitialized() const;
    ::TESFile *GetFile(int);
public:
    void ClearData();
public:
    void SetInitializationState(bool);
};
extern TESDataHandlerTypes::TESFaction* DAT_011cb550;
class TESDataHandler
{
  public:
};
class BaseFormComponent;
struct PackedRecordData;
class TESAIForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[0x1c];
    void SetResponsibility(unsigned char, bool);
    void SetAggression(unsigned char, bool);
    void SetConfidence(unsigned char, bool);
    void SetEnergy(unsigned char, bool);
public:
    void SetAIMood(unsigned char);
public:
    void CopyAIDataFromAIDATA(::PackedRecordData *);
public:
    void BaseFormRecord(::BaseFormComponent *);
};
class TESBoundAnimObject
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[44];
};
class BaseFormComponent;
class TESForm;
class TESContainer
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
    void InitItem(::TESForm *);
public:
    void CopyFromBase(::BaseFormComponent *);
};
class BGSTouchSpellForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
    void InitItem(::TESForm *);
};
class TESSpellList
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[16];
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
class TESFile;
class TESForm;
class TESAnimation
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
public:
    void LoadComponent(::TESForm *, ::TESFile *);
};
class TESFullName
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[8];
};
class TESFile;
class TESModel
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[20];
public:
    static void LoadModelData(::TESModel *, ::TESFile *);
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
class BaseFormComponent;
class BGSDestructibleObjectForm
{
  public:
    virtual void vfn_00() = 0;
    unsigned char componentLayout[4];
    void InitItem(::TESForm *);
public:
    void FUN_004786e0(::BaseFormComponent *);
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
    void LoadGame(BGSLoadFormBuffer*);
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
    virtual void C01();
    virtual void C02();
    virtual void C03();
    virtual void C04();
    virtual void C05();
    virtual void C06();
    virtual void C07();
    virtual void C08();
    virtual void C09();
    virtual void C10();
    virtual void C11();
    virtual void C12();
    virtual void C13();
    virtual void C14();
    virtual void C15();
    virtual void C16();
    virtual void C17();
    virtual void C18();
    virtual void C19();
    virtual void C20();
    virtual void C21();
    virtual void C22();
    virtual void C23();
    virtual void C24();
    virtual void C25();
    virtual void C26();
    virtual void C27();
    virtual void C28();
    virtual void C29();
    virtual void C30();
    virtual void C31();
    virtual void C32();
    virtual void C33();
    virtual void C34();
    virtual void C35();
    virtual void C36();
    virtual void C37();
    virtual void C38();
    virtual void C39();
    virtual void C40();
    virtual void C41();
    virtual void C42();
    virtual void C43();
    virtual void C44();
    virtual void C45();
    virtual void C46();
    virtual void C47();
    virtual void C48();
    virtual void C49();
    virtual void C50();
    virtual void C51();
    virtual void C52();
    virtual void C53();
    virtual void C54();
    virtual void C55();
    virtual void C56();
    virtual void C57();
    virtual void C58();
    virtual void C59();
    virtual void C60();
    virtual void C61();
    virtual void C62();
    virtual void C63();
    virtual void C64();
    virtual void C65();
    virtual void C66();
    virtual void C67();
    virtual void C68();
    virtual void C69();
    virtual void C70();
    virtual void C71();
    virtual void C72();
    virtual void C73();
    virtual void C74();
    virtual void C75();
    virtual void C76();
    virtual void C77();
    virtual void C78();
    virtual void C79();
    virtual void C80();
    virtual void C81();
    virtual void C82();
    virtual void C83();
    virtual void C84();
    virtual void C85();
    virtual void C86();
    virtual void C87();
    virtual void C88();
    virtual void C89();
    virtual void C90();
    virtual void C91();
    virtual void C92();
    virtual void C93();
    virtual void C94();
    virtual void C95();
    virtual BGSBodyPartData* GetBodyPartData();
    virtual void C97();
    virtual TESCombatStyle* GetCombatStyle();
    bool FUN_005f9b90(TESForm* otherForm);
    void ClearData();
    void ResetFormData();
    void LoadGame(BGSLoadFormBuffer* buffer);
    CreatureSoundCollection* GetMutableCreatureSounds();
    void SetCreatureSoundsFrom(TESCreature* soundCreature);
    void SetBodyPartData(BGSBodyPartData* bodyPartData);
    void Revert(BGSLoadFormBuffer* buffer);
public:
    char FUN_005fbf20() const;
};

#endif
