// Fallout shared perk entry declarations, reconstructed to the PC release layout.
#ifndef FNV_FALL_SHARED_BGSPERK_WORKER_H
#define FNV_FALL_SHARED_BGSPERK_WORKER_H


#include <stddef.h>

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f6de0_shell.h"
#include "fnv/decl/FUN_005eac70_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e6000.h"
#include "fnv/symbols_005e9000.h"


class PerkEntryPointData
{
  public:
    unsigned char m_ucEntryPoint;
    unsigned char m_ucFunction;
    unsigned char m_ucConditionCount;
};

#include "fnv/bs_simple_list.h"

class TESFullName;
class TESFullNameLoader
{
  public:
};

class Actor;
class BGSPerkEntry;
class TESFile
{
  public:
    bool IsEndianConversionRequired();
    bool NextChunk();
};
enum ENUM_FORM_ID
{
    kPerk = 0x56
};
class TESForm
{
  public:
    TESForm();
    virtual ~TESForm();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool Load(TESFile* file);
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
    virtual void InitItem();
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
    virtual void readOBNDSubRecord(TESFile* file);
    virtual bool IsActor_InEditor();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual bool GetIsReference() const;
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
    virtual const char* GetName() const;
    virtual bool SetEditorID(const char* id);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    TESFile* GetFile(int);
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    bool GetInitialized() const;
    unsigned char layoutData[0x14];
public:
    void ClearData();
};

class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};

class PerkEntryFunctionType
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual int GetFunctionType();
};

class RegionDataEntry
{
  public:
    void Endian();
};

class PerkEntryConditionSet
{
  public:
    void* pFirstCondition;
    void* pNextCondition;
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitItem(TESForm* form);
    void Load(TESFile* file);
    bool ContainsTrait(class TESObjectREFR*, class TESObjectREFR*, bool&, bool);
public:
    bool Compare(::PerkEntryConditionSet *);
public:
    void InitializeConditionItems();
};

class TESFullName
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(void*);
    virtual bool CompareWithBase(void*);
    unsigned char data[8];
    TESFullName();
    ~TESFullName();
};

class TESDescription
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(void*);
    virtual bool CompareWithBase(void*);
    unsigned char data[4];
    TESDescription();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};

class TESTexture
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(void*);
    virtual bool CompareWithBase(void*);
    unsigned char data[8];
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};

class PerkData
{
  public:
    bool m_bTrait;
    unsigned char cLevel;
    unsigned char m_ucRankCount;
    bool bPlayable;
    bool bHidden;
    unsigned char padding[3];
};

class BGSPerk : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
  public:
    PerkData Data;
    PerkEntryConditionSet m_kConditions;
    BSSimpleList<BGSPerkEntry*> m_kEntryList;
    BGSPerk();
    bool AppendPerkEntry(BGSPerkEntry* entry);
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    void ApplyPerkEntries(Actor* actor, unsigned char rank, bool alternate);
};

class BGSEntryPointFunctionData
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Load(TESFile* file);
    virtual void InitItem(TESForm* form);
};

class BGSPerkEntry
{
  public:
    unsigned char m_ucRank;               // +0x4
    unsigned char m_ucRegionPriority;  // +0x5
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual void InitItem(TESForm* form);
    virtual void Save();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual bool Load(TESFile* file);
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void Copy(BGSPerkEntry* entry);
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void ClearData();
    virtual ~BGSPerkEntry();
};

class BGSEntryPointPerkEntry : public BGSPerkEntry
{
  public:
    PerkEntryPointData Data;  // +0x8
    unsigned char layoutPaddingB[1];
    BGSEntryPointFunctionData* m_pFunctionData;  // +0xC
    PerkEntryConditionSet* m_pConditions;                 // +0x10
    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual void ClearData();
    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual unsigned char GetEntryPoint();
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void RemoveEntryPointEffect(Actor* actor, bool remove);
    BGSEntryPointPerkEntry& operator=(const BGSEntryPointPerkEntry& entry);
};

class BGSQuestPerkEntry : public BGSPerkEntry
{
  public:
    struct
    {
        class TESQuest* pQuest;
        unsigned char stage;
        unsigned char padding[3];
    } Data;
    virtual bool Load(TESFile* file);
    virtual void InitItem(TESForm* form);
};

#ifndef __GNUC__
#endif

#endif



class TESBoundObject : public TESForm
{
};
class TESObjectREFR : public TESForm
{
  public:
    TESObjectREFR();
    virtual ~TESObjectREFR();
    unsigned char referenceData[0x50];
};

class TESQuest : public TESForm
{
public:
    bool IsStageComplete(unsigned char);
};
class SpellItem : public TESForm
{
};
class BGSAbilityPerkEntry : public BGSPerkEntry
{
  public:
    SpellItem* m_pSpell;
    BGSAbilityPerkEntry* Initialize();
    virtual void InitItem(TESForm* form);
    virtual bool Load(TESFile* file);
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};

template <int N> struct EndianSizeTag
{
};


class TESAIForm
{
  public:
};
int ComparePerkEntries(BGSPerkEntry*, BGSPerkEntry*);

class BGSIdleMarker
{
  public:
};
extern unsigned int BGSAbilityPerkEntry_vtable[];
class TESObjectREFR;
class TESConditionItem
{
  public:
    unsigned char data[8];
    unsigned short function;
    unsigned int FUN_005eb680();
public:
    float GetConditionValue();
public:
    bool ContainsTrait(::TESObjectREFR *, ::TESObjectREFR *, bool &);
};
