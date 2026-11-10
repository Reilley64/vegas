// fallout_shared/teschallenge_decls.h: declares TESForm, TESScriptableForm, TESDescription, TESFullName, BGSMessageIcon and more

#include <cstring>
#include <malloc.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd3a0_shell.h"
#include "fnv/decl/FUN_005ac340_t.h"
#include "fnv/decl/FUN_005f5f60_class.h"
#include "fnv/decl/FUN_005f5fa0_cls.h"
#include "fnv/decl/FUN_005f5fc0_class.h"
#include "fnv/decl/FUN_005f5fe0_class.h"
#include "fnv/decl/FUN_005f6000_Class.h"
#include "fnv/decl/FUN_005f6060_class.h"
#include "fnv/decl/FUN_005f60c0_Class.h"
#include "fnv/decl/FUN_006a1b60_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_005a6000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011de000.h"
#include "teschallenge_support.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_CHALLENGE_TYPE_H
#define FNV_CHALLENGE_TYPE_H
#include "layout_support.h"
enum CHALLENGE_TYPE
{
    CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST = 0,
    CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC = 1,
    CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_CATEGORY = 2,
    CHALLENGE_TYPE_CHALLENGE_TYPE_HIT = 3,
    CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER = 4,
    CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM = 5,
    CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE = 6,
    CHALLENGE_TYPE_CHALLENGE_TYPE_SKILL = 7,
    CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE = 8,
    CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM_LIST = 9,
    CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE_LIST = 10,
    CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT = 11,
    CHALLENGE_TYPE_CHALLENGE_TYPE_CRAFT_WITH_ITEM = 12,
    CHALLENGE_TYPE_CHALLENGE_TYPE_SCRIPTED = 13,
    CHALLENGE_TYPE_CHALLENGE_TYPE_COUNT = 14
};
#endif

// Private PC declarations for this translation unit.
// Source layout: TESForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESFORM_H
#define FNV_TESFORM_H
#include "teschallenge_support.h"
#include "BaseFormComponent.h"
struct BGSLoadFormBuffer;
class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;             // +0x4
    unsigned int m_uiFormFlags;             // +0x8
    unsigned int iFormID;                   // +0xC
    BSSimpleList<TESFile*> m_kSourceFiles;  // +0x10
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
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
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
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
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    bool GetInitialized() const;
    TESForm();
    TESFile* GetFile(int fileIndex);
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
public:
    void LoadGame(void *);
};
#endif

// Source layout: TESScriptableForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESSCRIPTABLEFORM_H
#define FNV_TESSCRIPTABLEFORM_H
#include "teschallenge_support.h"
#include "BaseFormComponent.h"
class TESScriptableForm : public BaseFormComponent
{
  public:
    void InitItem(TESForm* form);
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9[3];
};
#endif

#ifndef FNV_TESCHALLENGE_H
#define FNV_TESCHALLENGE_H
#include "teschallenge_support.h"
#include "BaseFormComponent.h"
// Source layout: TESDescription. PC corrections are in generate_headers.py.
#ifndef FNV_TESDESCRIPTION_H
#define FNV_TESDESCRIPTION_H
#include "layout_support.h"
#include "BaseFormComponent.h"
class TESDescription : public BaseFormComponent
{
  public:
    virtual const char* GetDescription(TESForm*, CHUNK_ID);
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
#endif

#include "TESForm.h"
// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H
#include "layout_support.h"
#include "BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
};
#endif

#include "TESIcon.h"
#include "TESScriptableForm.h"
class BGSMessageIcon;
class ChallengeData;
class ChallengeProgress;
class TESChallenge;
class BGSMessageIcon : public BaseFormComponent
{
  public:
    TESIcon Icon;  // +0x4, 12 bytes
};
class ChallengeData
{
  public:
    int m_iPrimaryValue;    // +0x0, 4 bytes
    int m_iAuxiliaryValue;  // +0x4, 4 bytes
    unsigned short nFlags;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    int m_iRecordIndex;                       // +0xC, 4 bytes
    unsigned short FlaggedRecordValueEntry;   // +0x10, 2 bytes
    unsigned short RecordIndexValueData;      // +0x12, 2 bytes
    unsigned short IndexedRecordValueTriple;  // +0x14, 2 bytes
    unsigned char layoutPadding16[2];
};
class ChallengeProgress
{
  public:
    int iProgress;           // +0x0, 4 bytes
    int m_iCompletionCount;  // +0x4, 4 bytes
};
class TESChallenge : public TESForm,
                     public TESFullName,
                     public TESDescription,
                     public TESScriptableForm,
                     public TESIcon,
                     public BGSMessageIcon
{
  public:
    virtual void ResetFormData();
    virtual bool Load(TESFile* file);
    int GetStartsLocked();
    void SetShowZero(bool);
    void MarkForSave();
    virtual void InitItem();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    ChallengeData data;          // +0x54, 24 bytes
    ChallengeProgress progress;  // +0x6C, 8 bytes
    TESForm* m_pPrimaryForm;     // +0x74, 4 bytes
    TESForm* m_pSecondaryForm;   // +0x78, 4 bytes
public:
    void FUN_005f60e0(int);
};
#endif
struct BGSLoadFormBuffer
{
  public:
};

class ChallengeManager
{
  public:
    static void Clear();
    static void CheckCompletedChallenges();
    static bool UpdateChallengeProgress(CHALLENGE_TYPE type, int count, TESForm* formOne, TESForm* formTwo,
                                        unsigned short specialOne, unsigned short specialTwo,
                                        unsigned short specialThree);
};
class BGSListForm : public TESForm
{
  public:
};
class Script
{
  public:
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    const char* s;
};
template <> class SettingT<INISettingCollection>
{
  public:
    SETTING_VALUE* Bool();
};
class PlayerCharacter;
struct Interface
{
  public:
};
class TopicMenuController
{
  public:
    static void IncrementMiscStat(int);
};
class TESTextureLoader
{
  public:
};

class TESFullNameLoader
{
  public:
};
class TESFile
{
  public:
    bool GetChunkData(unsigned int*);
    bool IsEndianConversionRequired();
    bool NextChunk();
};
#pragma intrinsic(_alloca)

