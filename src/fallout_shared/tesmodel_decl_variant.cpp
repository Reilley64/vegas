
// src/fallout_shared/tesmodel_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x004781e0: the skeleton of src/fallout_shared/tesmodel.cpp
// with declarations corrected to what the original code does (unit: struct TESModel { virtual ~TESModel(); void* FUN_004 -> struct TESModel { virtual ~TESModel(); virtual void ). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesmodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesmodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstring>
#include <malloc.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00478130_class.h"
#include "fnv/decl/FUN_00478570_holder.h"
#include "fnv/decl/FUN_00478690_shell.h"
#include "fnv/decl/FUN_00478e90_This.h"
#include "fnv/decl/FUN_00487980_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f9ef0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b2010_shell.h"
#include "fnv/decl/ManagedSceneHolder.h"
#include "fnv/decl/TESIdleForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00489620__FUN_00489620_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011c5000.h"
struct BSFileEntry;
struct FileFormCollection;
struct TESFile;
struct TESForm;
struct FileEntryList
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Copy(FileEntryList*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};
struct FUN_00488ff0_shell : public FileEntryList
{
    void FUN_00488ff0();
};
struct FUN_00489620_t
{
};
struct FUN_008c1be0_shell
{
    void FUN_008c1be0(int param_1);
};
void FUN_008c1be0_shell::FUN_008c1be0(int param_1)
{}
struct FUN_004898c0_shell
{
    void FUN_004898c0(int param_1);
};
bool FUN_004898e0();
struct FUN_004890e0_shell
{
    void ForwardToMember();
};
struct FUN_00489860_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    unsigned char* FUN_00489860(unsigned char a, unsigned char b, unsigned char c, unsigned char d, int e);
};
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct ContainerItemExtra;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct LeveledObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESHealthForm;
struct TESNPC;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESLeveledList : public BaseFormComponent
{
    virtual unsigned char GetChanceNone();
    virtual bool UsesAllEntries();
    virtual int GetMaxLevelDifference();
    virtual void ErrorCheckList();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void SetChanceNone(unsigned char);
    bool GetCalcAllBelow();
    void SetCalcAllBelow(bool);
    void SetMultCalc(bool);
    bool GetUseAll();
    void SetUseAll(bool);
    TESGlobal* GetChanceGlobal();
    void SetChanceGlobal(TESGlobal*);
    void InitializeLeveledList();
    void SortLeveledList();
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void DeleteLeveledObject(LeveledObject*);
    void SelectLeveledObject(unsigned short, TESForm**, unsigned short*, ContainerItemExtra**, bool, int);
    void PopulateContainerWithLeveledItems(unsigned short, unsigned short, TESContainer*, int);
    void PopulateContainerFromReference(TESObjectREFR*, TESContainer*);
    void AddScriptAddedLeveledObject(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESLeveledList* GetFormAsLeveledList(TESForm*);
    void* GetLeveledList();
    void* __vecDelDtor(unsigned int);
    char leveledList[8];
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    char _pad_e[2];
    TESGlobal* m_pLevelGlobal;
    char m_kLeveledObjects[8];
};
struct FUN_00487a00_shell : public TESLeveledList
{
    void FUN_00487a00(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
};
struct G2
{
    void AddHead(LeveledObject*&);
};
struct FakeOwner
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18(unsigned int);
};
struct TESModel
{
    virtual ~TESModel();
    virtual void TM01();
    virtual void TM02();
    virtual void TM03();
    virtual void TM04();
    virtual void TM05();
    virtual void SetModelPath(const char* path);
    void* FUN_00489010(unsigned int flags);
};
struct BSStr
{
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00489040_shell
{
    char b0;
    char b1;
    char b2;
    char b3;
    BSStr FullNameComponent;
    void ClearString();
};
struct FUN_004898a0_shell : public FUN_004898c0_shell
{
    bool FUN_004898a0();
};
struct FUN_004f9ec0_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
struct SpawnedBase
{
    virtual void unk00();
    SpawnedBase();
};
struct SubObjA
{
    int unk00;
    int unk04;
    SubObjA();
    ~SubObjA();
};
struct SubObjB
{
    int unk00;
    int unk04;
    SubObjB();
    ~SubObjB();
};
struct FUN_00488f50_cls : SpawnedBase
{
    SubObjA m_04;
    SubObjB m_0c;

    FUN_00488f50_cls();
    virtual void unk00();
};
struct FUN_00489120_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    void SetFarPath(char* path);
};
class B479FB0Actor;
class B479FB0Idle
{
  public:
};
class B479FB0Actor
{
  public:
};
class B479FB0IdleList
{
  public:
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    unsigned char m_ucCount;
    short unk06;
    B479FB0Idle** m_ppkIdles;

    bool FUN_00479fb0(B479FB0Actor* pkActor, int iArg);
};
struct FUN_00488fd0_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    void* FUN_00488fd0();
};
// Destructor: clear the entries; the entry list and the name string are destroyed afterwards.
class B9070String
{
  public:
    ~B9070String();
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMax;
};
class B9070List
{
  public:
    ~B9070List();
    void* m_pkHead;
    void* m_pkNext;
};
class FUN_00489070
{
  public:
    virtual ~FUN_00489070();

    B9070String m_kName;
    B9070List m_kEntries;
};
struct FUN_00489480_shell : public TESModel
{
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual const char* GetModelPath();

    bool IsModelPathDifferent(BaseFormComponent* pkComponent);
};
struct FUN_004898a0_shell;
struct FUN_00489860_shell;
struct Elem
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    int unk08;
    int unk0c;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    int i14;
};
struct ModelRef
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk2A();
    virtual void unk2B();
    virtual void unk2C();
    virtual void unk2D();
    virtual void unk2E();
    virtual void unk2F();
    virtual void unk30();
    virtual void unk31();
    virtual void unk32();
    virtual void unk33();
    virtual void unk34();
    virtual void unk35();
    virtual void unk36();
    virtual void unk37();
    virtual void unk38();
    virtual void unk39();
    virtual void unk3A();
    virtual void unk3B();
    virtual void unk3C();
    virtual void unk3D();
    virtual void unk3E();
    virtual void unk3F();
    virtual void unk40();
    virtual void unk41();
    virtual void unk42();
    virtual void unk43();
    virtual void unk44();
    virtual void unk45();
    virtual void unk46();
    virtual void unk47();
    virtual void unk48();
    virtual void unk49();
    virtual void unk4A();
    virtual void unk4B();
    virtual const char* GetEditorName();
};
struct FUN_00408d60_shell
{
    unsigned char* FUN_00408d60();
};
struct Cls
{
    unsigned char m_00;
    unsigned int* m_04;
    void LoadTextureArchiveEntries(Elem* arr, unsigned int count, ModelRef* form, const char* model);
};
bool __cdecl FUN_004898e0();

class String;
template <class T> struct tList
{
    T* item;
    tList<T>* next;
};
class TESForm : public BaseFormComponent
{
  public:
    virtual void* Destroy(bool doFree);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual bool Unk_07(void);
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned long changedFlags);
    virtual void MarkAsUnmodified(unsigned long changedFlags);
    virtual unsigned long GetSaveSize(unsigned long changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned long changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned long changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned long changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned long GetTypeID(void);
    virtual void GetDebugName(String* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool Unk_3F(void) const;
    virtual bool IsActor_Runtime(void);
    virtual unsigned long Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned long formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned long refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    unsigned char typeID;
    unsigned char typeIDPad[3];
    unsigned long flags;
    unsigned long refID;
    tList<TESFile> mods;
};

struct TESFile
{
    bool IsEndianConversionRequired();
    bool NextChunk();
};
struct DestructionStage
{
    unsigned char damageStage;
    unsigned char healthPercent;
    unsigned char flags;
    unsigned int selfDamage;
    TESForm* explosion;
    TESForm* debris;
    unsigned int debrisCount;
    TESModel* replacementModel;
};
struct DestructibleData
{
    unsigned int health;
    unsigned char stageCount;
    unsigned char flags;
    DestructionStage** stages;
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    DestructibleData* pkData;
};
struct DestructibleHeader
{
    unsigned int health;
    unsigned char stageCount;
    unsigned char flags;
    unsigned short unused;
    DestructibleHeader();
};
struct DestructionStageChunk
{
    unsigned char healthPercent;
    unsigned char index;
    unsigned char damageStage;
    unsigned char flags;
    unsigned int selfDamage;
    TESForm* explosion;
    TESForm* debris;
    unsigned int debrisCount;
};
// @fnv 0x004781e0
void __cdecl FUN_004781e0(BGSDestructibleObjectForm* component, TESFile* file)
{
    if (!file || !component)
        return;
    int chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()));
    reinterpret_cast<::ManagedSceneHolder *>((component))->EnsureCurrentEntry();
    DestructibleData* pkData = ((::DestructibleData *)(reinterpret_cast<::Callees *>((component))->FUN_00726070()));
    switch (chunkID)
    {
    case 0x54534544: {
        DestructibleHeader header;
        if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() != 8)
        {
            TESForm* form = dynamic_cast<TESForm*>(component);
            ::FUN_005b5e40();
            reinterpret_cast<::FUN_00478690_shell *>((component))->FUN_00478690();
            return;
        }
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&header), 0);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::fnv_00503210::Unk *>(&(header))->FUN_00503210();
        pkData->health = header.health;
        pkData->stageCount = header.stageCount;
        pkData->flags = header.flags;
        if (pkData->stageCount)
            pkData->stages = ((::DestructionStage **)(reinterpret_cast<::FUN_00478e90_This *>((component))->AllocateSpawnedItemArray(pkData->stageCount)));
        break;
    }
    case 0x44545344: {
        DestructionStageChunk stage;
        memset(&stage, 0, sizeof(stage));
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&stage), sizeof(stage));
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_00478130_class *>(&(stage))->FUN_00478130();
        unsigned char index = stage.index;
        if (index < pkData->stageCount)
        {
            pkData->stages[index]->damageStage = stage.damageStage;
            pkData->stages[index]->healthPercent = stage.healthPercent;
            pkData->stages[index]->flags = stage.flags;
            pkData->stages[index]->selfDamage = stage.selfDamage;
            pkData->stages[index]->explosion = stage.explosion;
            pkData->stages[index]->debris = stage.debris;
            pkData->stages[index]->debrisCount = stage.debrisCount;
            while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
            {
                switch (chunkID)
                {
                case 0x4c444d44: {
                    reinterpret_cast<::FUN_00478570_holder *>((pkData->stages[index]))->EnsureB2_4fe();
                    char* path = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(path), 0);
                    pkData->stages[index]->replacementModel->SetModelPath(path);
                    break;
                }
                case 0x54444d44:
                    reinterpret_cast<::FUN_00478570_holder *>((pkData->stages[index]))->EnsureB2_4fe();
                    FUN_004893e0(pkData->stages[index]->replacementModel, file);
                    break;
                case 0x53444d44: {
                    reinterpret_cast<::FUN_00478570_holder *>((pkData->stages[index]))->EnsureB2_4fe();
                    unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
                    void* pBuffer = _alloca(size);
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pBuffer), size);
                    reinterpret_cast<::FUN_0048a7b0_shell *>((pkData->stages[index]->replacementModel))->LoadTextureSwapList(pBuffer, size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570());
                    break;
                }
                case 0x46545344:
                    return;
                }
                if (!file->NextChunk())
                    break;
            }
        }
        break;
    }
    }
}
