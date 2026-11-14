// fallout_shared/bgsquestobjective.cpp: BGSQuestObjective, StandIn (15 functions)

#include <new>
#include <malloc.h>
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00471d60_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005ec700_shell.h"
#include "fnv/decl/FUN_0060ffe0.h"
#include "fnv/decl/FUN_00610190_cls.h"
#include "fnv/decl/FUN_00952a20_shell.h"
#include "fnv/decl/FUN_00952d60_stand.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MessageHandler.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/Obj_009529d0.h"
#include "fnv/decl/PerkEntryConditionSet.h"
#include "fnv/decl/TESFaction_RankDataView.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESQuest.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkLiquidAction.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004721d0__FUN_004721d0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005cb000.h"
#include "fnv/symbols_0077a000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_011de000.h"
#include "bgsquestobjective_decls.h"
// If not yet initialized, stores quest and calls InitItem on each entry of the target list, then marks the objective initialized.
// @fnv 0x005ec210
void BGSQuestObjective::InitItem(TESQuest* quest)
{
    if (bInitialized)
        return;
    m_pOwnerQuest = quest;
    BSSimpleList<RegionObjectEntry*>* targets = ((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::NonActorMagicTarget *>(this)->GetActiveEffectList()));
    while (targets && !reinterpret_cast<BSSimpleList<const char*>*>(targets)->IsEmpty())
    {
        reinterpret_cast<RegionObjectEntry*>(((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(targets))->m_item))
            ->InitItem(reinterpret_cast<TESForm*>(quest));
        targets = reinterpret_cast<BSSimpleList<RegionObjectEntry*>*>(
            ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(targets)))->FUN_00726070())));
    }
    bInitialized = true;
}

// @fnv 0x005ec1b0
void BGSQuestObjective::Initialize()
{
    iIndex = 0;
    m_kDisplayText = ::DAT_01011584;
    bInitialized = false;
    state = 0;
    m_pOwnerQuest = 0;
}

class RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
    ~RecursiveSpinLock();
    int pad[2];
};
struct StrMem
{
    StrMem();
    ~StrMem();
    int pad[3];
};
struct InitStub
{
};
struct FUN_005ec090
{
    FUN_005ec090();
    virtual void vfn_0();
    unsigned int iIndex;
    StrMem m_kDisplayText;
    RecursiveSpinLock lock;
};
// @fnv 0x005ec090
FUN_005ec090::FUN_005ec090()
{
    reinterpret_cast<::BGSQuestObjective *>((((InitStub*)this)))->Initialize();
}

struct FUN_005ec330_shell : public BGSQuestObjective
{
    char* GetPromptText();
};

struct StrH
{
    operator const char*() const;
};
// Returns the string stored at offset 8 of this objective, or g_emptyTopicInfoPrompt when that string is empty.
// @fnv 0x005ec330
char* FUN_005ec330_shell::GetPromptText()
{
    return (char*)((const char*)*(StrH*)&this->m_kDisplayText.storage[0] ? (const char*)*(StrH*)&this->m_kDisplayText.storage[0]
                                                          : ::DAT_01011584);
}

struct BSFile;
struct FormRecordHeader;
struct TESFileGroup;
struct TESBitArrayFile;
class TESForm;
class TESObjectCELL;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
class TESFile
{
  public:
    bool CreateTES(char*, char*, int);
    bool CreateTES(int);
    bool OpenTESFile(char*, char*, int, bool);
    bool OpenTESFile(int, bool);
    bool CloseTESFile();
    bool DeleteTES();
    bool IsOpen();
    bool QDLC();
    void SetDLC(bool);
    int ReadTESInfo();
    int SaveTESInfo();
    int RewriteFormHeader();
    TESForm* BuildTESInfoForm();
    int GetFormCount();
    void ModFormCount(int);
    void SetFormCount(int);
    int GetFileLanguage();
    void SetFileLanguage(int);
    void SetFileVersion(float);
    bool IsValidFileVersion();
    char* GetPath();
    char* GetFilename();
    unsigned int GetFileSize();
    _WIN32_FIND_DATAA* GetFileData();
    void GetCreateTime(_SYSTEMTIME*);
    void GetLastWriteTime(_FILETIME*);
    void GetLastWriteTime(_SYSTEMTIME*);
    void* GetCreator();
    void* GetSummary();
    bool MastersChecked(void*);
    bool CheckMasterFiles(void*, bool);
    TESFile* GetMasterFile(unsigned int);
    char* GetMasterFileName(unsigned int);
    unsigned int GetMasterFileCount();
    unsigned int GetFileIndex(TESFile*);
    void ClearMasters();
    void AddMaster(char*);
    bool AddMasters(void*);
    void RemoveMaster(unsigned int);
    bool DependsOnMaster(char*);
    bool MastersChanged();
    bool CheckLODPlugins();
    void* GetMasterList();
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char);
    void AddToDataHandler();
    bool CurrentGroupMayContainForm(TESForm*);
    void GetAnimationSequence(FormRecordHeader*);
    void ClearGroupStack();
    void OpenGroup(FormRecordHeader*);
    void CloseGroup();
    bool IsFormInCurrentGroup(TESForm*);
    bool IsGroupOpen();
    void SetCurrentForm(TESForm*);
    void ResetCurrentForm();
    TESFileGroup* GetCurrentGroup();
    void* GetGroupList();
    void SetGroupMode(bool);
    void TESRewindChunk();
    bool NextForm(bool);
    void RewindForm();
    unsigned int GetOffset();
    unsigned int GetOffsetChunk();
    bool SetOffsetChunk(unsigned int);
    int GetFormAtOffset(unsigned int);
    unsigned int CopyCurrentFormToBuffer(void*, unsigned int);
    bool NextChunk();
    bool GetChunkData(unsigned short*);
    bool GetChunkData(short*);
    bool GetChunkData(float*);
    bool GetChunkData(unsigned int*);
    bool GetChunkData(int*);
    bool GetChunkData(void*, unsigned int);
    void ClearCurrentChunk();
    bool HasMaster(char*);
    int WriteForm(TESForm*);
    int WriteFormContents(TESForm*);
    void LoadForm(TESForm*);
    int WriteChunkData(int, void*, unsigned int);
    unsigned int GetCurrentReadPosition();
    bool ForceSaveFormHeader(FormRecordHeader*, unsigned int);
    void SetMasterFile(bool);
    bool IsMasterFile();
    void SetOptimizedFile(bool);
    bool GetOptimizedFile();
    void SetChecked(bool);
    bool GetIsChecked();
    void SetAltered(bool);
    bool GetAltered();
    void SetActive(bool);
    void SetLittleEndian(bool);
    bool GetLittleEndian();
    bool QEndian();
    void SetUnicode(bool);
    bool GetUnicode();
    bool GetHasGroups();
    void SetHasGroups(bool);
    float GetPercentage();
    void CopyToBackup();
    static void DeleteFileList(void*);
    TESFile* GetParentTESFile();
    TESFile* GetThreadSafeRootFile();
    void CopyThreadSafeParentAuxBuffer();
    void ClearAuxBuffer();
    void SetFile(BSFile*);
    BSFile* GetFile();
    int GetLastFileError();
    FormRecordHeader* GetFormData();
    unsigned int GetID();
    bool TakeOwnership();
    static bool TakeFileOwnership(char*);
    static unsigned short GetFileFormVersion();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCaching();
    unsigned int GetMasterCount();
    unsigned int GetFlags();
    unsigned int GetFNVVersionInfo();
    void InitEndian();
    bool IsCurrentFormCompressed();
    unsigned int GetDecompressedBufferSize();
    char* GetDecompressedBuffer();
    void ReleaseDecompressedBuffer();
    void ClearDecompressedBuffer();
    bool ReadFormHeader();
    bool ReadChunkHeader();
    void* GetMasterDataList();
    void ClearMasterLists();
    void ClearThreadSafeFiles();
    void SetThreadSafeParent(TESFile*);
    TESFile* GetFileForThread(unsigned int);
    int ReadFileBuffer(void*, unsigned int);
    void MoveToFilePosition(int);
    bool IsTempIDLoadable(unsigned int, unsigned int);
    void SetTempIDOwner(bool);
    bool GetTempIDOwner();
    static void SetTempIDOwnerForForm(unsigned int, TESFile*);
    static bool GetTempIDCanLoadFromFile(unsigned int, TESFile*);
    static TESFile* GetTempIDOwnerFile(unsigned int);
    void ClearTempIDOwner();
    void* __vecDelDtor(unsigned int);
    int m_eReturnCode;
    TESFile* m_pThreadSafeParent;
    void* m_pThreadSafeFileMap;
    BSFile* m_pSecondaryFile;
    BSFile* m_pFile;
    TESBitArrayFile* m_pBitArrayFile1;
    TESBitArrayFile* m_pBitArrayFile2;
    TESBitArrayFile* m_pBitArrayFile3;
    char m_acFilename[260];
    char m_acPath[260];
    char* m_pBuffer;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiReadPosition;
    unsigned int m_uiBufferSize;
    TESObjectCELL* m_pCurrentCell;
    unsigned int m_uiFormCount;
    char m_kRecordInfo[24];
    int m_eChunkID;
    unsigned int m_uiChunkSize;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
    char m_kChunkInfo[24];
    unsigned int m_uiChunkValue1;
    unsigned int m_uiChunkValue2;
    char m_kRecordList[8];
    bool m_bIsLoading;
    bool m_bIsSaving;
    bool m_bHasCurrentGroup;
    char _pad_29b[1];
    char m_kFindData[320];
    char m_kFileMetadata[12];
    unsigned int m_uiFileCount;
    char m_kFilenameList[8];
    char m_kFileSizeList[8];
    unsigned int m_uiTESFileCount;
    TESFile** m_ppTESFiles;
    char m_kLastWriteTime[8];
    unsigned char m_ucCompileIndex;
    char _pad_40d[3];
    char m_kCreator[8];
    char m_kSummary[8];
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
    bool m_bIsMaster;
    bool m_bOptimizedFile;
    bool m_bIsDLC;
    char _pad_42b[1];
};
struct FUN_005ec370_shell : public BGSQuestObjective
{
    void FUN_005ec370(TESFile*);
};

struct S_005ec440
{
    void FUN_005ec440(char*);
};
struct FUN_005ec500_shell : public BGSQuestObjective
{
    void AddMatchingTargetsToList(void*);
};

struct QObjOps
{
};
struct ListOps
{
};
struct TgtOps
{
};
struct CondOps
{
};
struct PlayerOps
{
};
struct OutList
{
};

// If the objective's object reference is 1, walks the target list and appends targets whose condition passes to apListToFill, calling the player op on each.
// @fnv 0x005ec500
void FUN_005ec500_shell::AddMatchingTargetsToList(void* apListToFill)
{
    if (((int)(std::uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((QObjOps*)this)))->FUN_007af430())) != 1)
        return;
    ListOps* pMasterList = (ListOps*)((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::NonActorMagicTarget *>((((BGSQuestObjective*)this)))->GetActiveEffectList()));
    RegionObjectEntry* pTarget = 0;
    while (pMasterList && *((::RegionObjectEntry **)((void *)(pMasterList))))
    {
        pTarget = *((::RegionObjectEntry **)((void *)(pMasterList)));
        pMasterList = ((::ListOps *)(reinterpret_cast<::Callees *>((pMasterList))->FUN_00726070()));
        if (reinterpret_cast<::PerkEntryConditionSet *>((((CondOps*)((void *)(reinterpret_cast<::BaseProcess *>((((TgtOps*)pTarget)))->GetCurrentProcessData())))))->ContainsTrait((::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::RegionObjectEntry *>((((TgtOps*)pTarget)))->GetReference(0)))), (::TESObjectREFR *)(0)))
        {
            reinterpret_cast<::FUN_00952d60_stand *>(((*reinterpret_cast<::PlayerOps * *>(&::_g_thePlayer))))->FUN_00952d60((::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::RegionObjectEntry *>((((TgtOps*)pTarget)))->GetReference(1)))), (::PathingPath *)(void *)(((void *)(::FUN_00460140((std::intptr_t)(((TgtOps*)pTarget)))))),
                                      reinterpret_cast<::FUN_00610190_cls *>((((TgtOps*)pTarget)))->IsFlagSet());
            reinterpret_cast<::Callees *>((((OutList*)apListToFill)))->FUN_00905820(&pTarget);
        }
    }
}

struct S7010
{
};

struct FUN_005ec310_shell
{
    unsigned int GetLength();
};

// @fnv 0x005ec310
unsigned int FUN_005ec310_shell::GetLength()
{
    return ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)((char*)this + 8))))->FUN_004048e0()));
}

struct S_005ec110
{
    void FUN_005ec140();
    void* FUN_005ec110(unsigned int);
};
struct StandIn
{
    void* FUN_005ec4d0(unsigned int);
};
// Calls FUN_0060ffe0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005ec4d0
void* StandIn::FUN_005ec4d0(unsigned int flags)
{
    reinterpret_cast<::FUN_0060ffe0 *>(this)->FUN_0060ffe0::~FUN_0060ffe0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005ec1f0_shell
{
    void FUN_005ec1f0();
};

struct BSStr
{
};

struct FUN_005ec440
{
    char pad[8];
    BSStr m_str;  // +0x08
    void Set(const char* name);
};
// Reads chunks from apFile: stores the QOBJ chunk's int in iIndex, and on the NNAM chunk passes its data (or null) to FUN_005ec440, then returns.
// @fnv 0x005ec370
void FUN_005ec370_shell::FUN_005ec370(TESFile* apFile)
{
    int chunkid;
    while ((chunkid = reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()) != 0)
    {
        switch (chunkid)
        {
        case 0x4a424f51:
            apFile->GetChunkData(&iIndex);
            break;
        case 0x4d414e4e:
            if (reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C())
            {
                char* pMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pMessage), 0);
                reinterpret_cast<::FUN_005ec440 *>((((S_005ec440*)this)))->Set(pMessage);
            }
            else
            {
                reinterpret_cast<::FUN_005ec440 *>((((S_005ec440*)this)))->Set(0);
            }
            return;
        }
        if (!apFile->NextChunk())
            break;
    }
}

// @fnv 0x005ec440
void FUN_005ec440::Set(const char* name)
{
    reinterpret_cast<::TextString *>(&(m_str))->FUN_004037f0(name, 0);
}

namespace fnv_005ec280 {
struct FUN_00485910_shell
{
};
struct FUN_004856f0_shell
{
};
struct FUN_005ec310_shell
{
};
struct FUN_005ec330_shell
{
};
struct Date
{
    ~Date();
};
struct FUN_005ec280_shell
{
    void FUN_005ec280();
};
// @fnv 0x005ec280
void FUN_005ec280_shell::FUN_005ec280()
{
    ::FUN_00485910(0x4a424f51, (int)(std::uintptr_t)(((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<RegionObjectEntry*>*)this)))->FUN_00726070()))));
    ::FUN_004856f0((void *)(0x4d414e4e), (void *)(reinterpret_cast<::FUN_005ec330_shell *>((((FUN_005ec330_shell*)this)))->GetPromptText()),
                                     (void *)(std::uintptr_t)(reinterpret_cast<::FUN_005ec310_shell *>((((FUN_005ec310_shell*)this)))->GetLength() + 1));
    BSSimpleList<RegionObjectEntry*>* list = ((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::NonActorMagicTarget *>((((BGSQuestObjective*)this)))->GetActiveEffectList()));
    while (list && !list->IsEmpty())
    {
        reinterpret_cast<::TESForm *>((((Date*)(list->m_item))))->ClearData();
        list = ((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
}
}  // namespace fnv_005ec280

namespace fnv_005ec5d0 {
enum QUEST_OBJECTIVE_STATE
{
    QUEST_OBJECTIVE_STATE_0 = 0,
    QUEST_OBJECTIVE_STATE_1 = 1,
    QUEST_OBJECTIVE_STATE_3 = 3
};

struct BSAudio
{
};

class TESQuest
{
  public:
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void FUN_005ec000(unsigned int);

};

struct TESFaction_RankDataView
{
};

struct FUN_005ec700_shell
{
};

struct FUN_005ec330_shell
{
};

struct Obj_009529d0
{
};

struct FUN_00952a20_shell
{
};

class PlayerCharacter : public Obj_009529d0
{
};



struct FUN_005ec5d0_shell : BGSQuestObjective
{
    void FUN_005ec5d0(QUEST_OBJECTIVE_STATE);
};

// @fnv 0x005ec5d0
void FUN_005ec5d0_shell::FUN_005ec5d0(QUEST_OBJECTIVE_STATE aeNewState)
{
    TESQuest* powner = reinterpret_cast<TESQuest*>(((std::intptr_t)(reinterpret_cast<::MagicCaster_shell *>((reinterpret_cast<BSAudio*>(this)))->FUN_0044edb0())));

    powner->FUN_005ec000(0x20000000);

    if (aeNewState == QUEST_OBJECTIVE_STATE_1 || state == 0)
    {
        if (aeNewState == QUEST_OBJECTIVE_STATE_1)
        {
            if (!reinterpret_cast<::FUN_0059e400_shell *>((powner))->FUN_0059e400())
            {
                reinterpret_cast<::TESQuest *>((powner))->SetEnabled(true);
                if (!::FUN_005cbb50(reinterpret_cast<char*>((*reinterpret_cast<::fnv_005ec5d0::PlayerCharacter * *>(&::_g_thePlayer)))))
                {
                    reinterpret_cast<::Obj_009529d0 *>((reinterpret_cast<Obj_009529d0*>((*reinterpret_cast<::fnv_005ec5d0::PlayerCharacter * *>(&::_g_thePlayer)))))->FUN_009529d0(reinterpret_cast<std::intptr_t>(powner));
                }
            }

            ::FUN_0077a5b0(reinterpret_cast<::FUN_005ec330_shell *>((reinterpret_cast<FUN_005ec330_shell*>(this)))->GetPromptText(), 0, 0);

            if (!reinterpret_cast<::TESFaction_RankDataView *>((reinterpret_cast<TESFaction_RankDataView*>(powner)))->HasFlag20())
            {
                ::fnv_0077a480::FUN_0077a480((::fnv_0077a480::TESQuest *)(powner));
                reinterpret_cast<::FUN_005ec700_shell *>((reinterpret_cast<FUN_005ec700_shell*>(powner)))->SetFlag20(true);
            }
        }

        reinterpret_cast<::FUN_00952a20_shell *>((reinterpret_cast<FUN_00952a20_shell*>((*reinterpret_cast<::fnv_005ec5d0::PlayerCharacter * *>(&::_g_thePlayer)))))->FUN_00952a20(this);
    }

    if (aeNewState == QUEST_OBJECTIVE_STATE_3 && state == QUEST_OBJECTIVE_STATE_1 && !reinterpret_cast<::FUN_0059e400_shell *>((powner))->FUN_0059e400())
    {
        ::FUN_0077a5b0(reinterpret_cast<::FUN_005ec330_shell *>((reinterpret_cast<FUN_005ec330_shell*>(this)))->GetPromptText(), 1, 0);
    }

    state = aeNewState;
}
}  // namespace fnv_005ec5d0

struct FUN_005ec140
{
    virtual void vfn_0();
    unsigned int iIndex;
    StrMem m_kDisplayText;
    RecursiveSpinLock lock;
    ~FUN_005ec140();
};
// Calls FUN_005ec140, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005ec110
void* S_005ec110::FUN_005ec110(unsigned int flags)
{
    reinterpret_cast<::FUN_005ec140 *>(this)->FUN_005ec140::~FUN_005ec140();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x005ec140
FUN_005ec140::~FUN_005ec140()
{
    reinterpret_cast<::FUN_005ec1f0_shell *>(this)->FUN_005ec1f0();
}

struct FUN_005ec460_List
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};
struct FUN_005ec460_Owner
{
    void FUN_005ec460();
};
// @fnv 0x005ec1f0
void FUN_005ec1f0_shell::FUN_005ec1f0()
{
    reinterpret_cast<::FUN_005ec460_Owner *>(this)->FUN_005ec460();
}
// @fnv 0x005ec460
void FUN_005ec460_Owner::FUN_005ec460()
{
    FUN_005ec460_List* list = ((::FUN_005ec460_List *)(reinterpret_cast<::NonActorMagicTarget *>(this)->GetActiveEffectList()));
    while (list && !list->FUN_008256d0())
    {
        StandIn* target = *((::StandIn **)((void *)(list)));
        StandIn* deletionTarget = target;
        deletionTarget ? deletionTarget->FUN_005ec4d0(1) : 0;
        list->FUN_0063f7b0();
    }
}
