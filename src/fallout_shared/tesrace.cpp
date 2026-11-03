// fallout_shared/tesrace.cpp: TESRace, Obj, RaceCleanup, RaceReset and more (42 functions)

#include <new>
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/BSFaceGenModel.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FR2MatrixVTCData.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00402d50.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00480100_shell.h"
#include "fnv/decl/FUN_00480130_shell.h"
#include "fnv/decl/FUN_00482cb0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_00488f50_cls.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_00489240_Class.h"
#include "fnv/decl/FUN_0048bb70_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00503650_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005fdfa0_shell.h"
#include "fnv/decl/FUN_00601800_shell.h"
#include "fnv/decl/FUN_00602130_shell.h"
#include "fnv/decl/FUN_00602170_shell.h"
#include "fnv/decl/FUN_00604210_shell.h"
#include "fnv/decl/FUN_006042d0_Owner.h"
#include "fnv/decl/FUN_006044c0_shell.h"
#include "fnv/decl/FUN_00604780_shell.h"
#include "fnv/decl/FUN_006047a0_shell.h"
#include "fnv/decl/FUN_00607350_shell.h"
#include "fnv/decl/FUN_006130c0_Class.h"
#include "fnv/decl/FUN_00613790_shell.h"
#include "fnv/decl/FUN_006137b0_shell.h"
#include "fnv/decl/FUN_00613810_shell.h"
#include "fnv/decl/FUN_00613870_Class.h"
#include "fnv/decl/FUN_00613890_Class.h"
#include "fnv/decl/FUN_006138b0_shell.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009d2510_shell.h"
#include "fnv/decl/FUN_00a5fba0_class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/TESSpellListShell.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TextureFileEntrySetter.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048d290__FUN_0048d290_shell.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_006044e0__FUN_006044e0_shell.h"
#include "fnv/decl/fnv_00650780__BSFaceGenModelMap_t.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00604000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_00614000.h"
#include "fnv/symbols_00615000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00654000.h"
#include "fnv/symbols_00655000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_0119a000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "tesrace_types.h"

// @fnv 0x00611e30
void TESRace::SetDefaultHairColor(SEX sex, unsigned char color)
{
    m_acDefaultHairColors[sex] = color;
}

// Assigns voice to the race's voice-type slot for sex, or falls back to the male/female default when voice is null.
// @fnv 0x00610c70
void TESRace::SetDefaultVoiceType(SEX sex, BGSVoiceType* voice)
{
    if (!voice)
    {
        if (sex == SEX_SEX_MALE)
            m_apDefaultVoiceTypes[sex] = ::DAT_011cb298;
        if (sex == SEX_SEX_FEMALE)
            m_apDefaultVoiceTypes[sex] = ::DAT_011cb29c;
    }
    else
    {
        m_apDefaultVoiceTypes[sex] = voice;
    }
}

// @fnv 0x006128c0
void TESRace::InitItem()
{
    if (GetInitialized())
        return;
    if (m_apDefaultVoiceTypes[0])
    {
        unsigned int maleVoiceID = reinterpret_cast<unsigned int>(m_apDefaultVoiceTypes[0]);
        ::ResolveFormID((unsigned int *)&(maleVoiceID), GetFile(-1));
        m_apDefaultVoiceTypes[0] = dynamic_cast<BGSVoiceType*>(::FUN_004839c0(maleVoiceID));
        if (!m_apDefaultVoiceTypes[0])
            ::FUN_005b5e40();
    }
    if (m_apDefaultVoiceTypes[1])
    {
        unsigned int femaleVoiceID = reinterpret_cast<unsigned int>(m_apDefaultVoiceTypes[1]);
        ::ResolveFormID((unsigned int *)&(femaleVoiceID), GetFile(-1));
        m_apDefaultVoiceTypes[1] = dynamic_cast<BGSVoiceType*>(::FUN_004839c0(femaleVoiceID));
        if (!m_apDefaultVoiceTypes[1])
            ::FUN_005b5e40();
    }
    if (m_apDefaultHairStyles[0])
    {
        unsigned int maleHairID = reinterpret_cast<unsigned int>(m_apDefaultHairStyles[0]);
        ::ResolveFormID((unsigned int *)&(maleHairID), GetFile(-1));
        m_apDefaultHairStyles[0] = dynamic_cast<TESHair*>(::FUN_004839c0(maleHairID));
        if (!m_apDefaultHairStyles[0])
            ::FUN_005b5e40();
    }
    if (m_apDefaultHairStyles[1])
    {
        unsigned int femaleHairID = reinterpret_cast<unsigned int>(m_apDefaultHairStyles[1]);
        ::ResolveFormID((unsigned int *)&(femaleHairID), GetFile(-1));
        m_apDefaultHairStyles[1] = dynamic_cast<TESHair*>(::FUN_004839c0(femaleHairID));
        if (!m_apDefaultHairStyles[1])
            ::FUN_005b5e40();
    }
    if (m_pOlderRace)
    {
        unsigned int olderRaceID = reinterpret_cast<unsigned int>(m_pOlderRace);
        ::ResolveFormID((unsigned int *)&(olderRaceID), GetFile(-1));
        m_pOlderRace = dynamic_cast<TESRace*>(::FUN_004839c0(olderRaceID));
        if (!m_pOlderRace)
            ::FUN_005b5e40();
    }
    if (m_pYoungerRace)
    {
        unsigned int youngerRaceID = reinterpret_cast<unsigned int>(m_pYoungerRace);
        ::ResolveFormID((unsigned int *)&(youngerRaceID), GetFile(-1));
        m_pYoungerRace = dynamic_cast<TESRace*>(::FUN_004839c0(youngerRaceID));
        if (!m_pYoungerRace)
            ::FUN_005b5e40();
    }
    TESSpellList::InitItem(this);
    TESReactionForm::InitItem(this);
    SetInitializationState(true);
}

// Builds a "<raceID>_<rootID>ModBody<Male|Female>" or "<rootID>ModBody<Male|Female>" string from the race and the deepest template NPC's form IDs.
// @fnv 0x006147e0
void TESRace::BuildBodyTexturePath(TESNPC* npc, char* out)
{
    TESNPC* npcID = npc;
    char acRacePath[16];
    if (reinterpret_cast<::FUN_006044c0_shell *>((npc))->FUN_006044c0())
    {
        npcID = reinterpret_cast<::FUN_006044c0_shell *>((npc))->FUN_006044c0();
        while (npcID && reinterpret_cast<::FUN_006044c0_shell *>((npcID))->FUN_006044c0())
            npcID = reinterpret_cast<::FUN_006044c0_shell *>((npcID))->FUN_006044c0();
    }
    if (npc->GetSex() == SEX_SEX_FEMALE)
        sprintf(acRacePath, "Female");
    else
        sprintf(acRacePath, "Male");
    unsigned int raceID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)this)->FUN_0084e3a0())) & 0xffffff;
    unsigned int root = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((void *)(npcID))->FUN_0084e3a0())) & 0xffffff;
    if (npc->model.HasModel())
        ::FUN_00406d00(out, 260, "%08x_%08XModBody%s", raceID, root, acRacePath);
    else
        ::FUN_00406d00(out, 260, "%08XModBody%s", root, acRacePath);
}

// Builds a model path for the given BIPED_OBJECT and sex, appending a first-person suffix for the player, and returns false if no model exists.
// @fnv 0x00614640
bool TESRace::GetBipedObjectModelPath(TESNPC* npc, BIPED_OBJECT part, char* out)
{
    int sex = ::NormalizePartIndex((*(int *)&(part)));
    if (sex < 0 || sex >= 3)
        return false;
    SEX index = npc ? npc->GetSex() : SEX_SEX_MALE;
    if (!reinterpret_cast<TESModel*>(&m_kHeadPartTextures[index][sex])->GetModelLength() && sex == 2)
        sex = 1;
    if (!reinterpret_cast<TESModel*>(&m_kHeadPartTextures[index][sex])->GetModelLength())
        return false;
    TaskQueueInterface::CopyStringToBuffer(out, 260, "Textures\\");
    strcat_s(out, 260, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<TESFullName*>(&m_kHeadPartTextures[index][sex])))->FUN_00408da0())));
    if (npc && npc == reinterpret_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430()))) && (sex == 1 || sex == 2))
    {
        const char* extension =
            strrchr(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<TESFullName*>(&m_kHeadPartTextures[index][sex])))->FUN_00408da0())), '.');
        char* dot = FUN_0040ab30(out, '.');
        if (dot && extension)
        {
            *dot = 0;
            strcat_s(out, 260, "_1st");
            strcat_s(out, 260, extension);
        }
    }
    return true;
}

extern int DAT_0104b5f8;

// @fnv 0x006104a0
TESModel* ConstructTESModel(TESModel* pThis)
{
    new ((void *)(pThis)) ::FUN_00488f50_cls();
    *(int**)pThis = &DAT_0104b5f8;
    return pThis;
}

struct FUN_00613970_shell : public TESRace
{
    TESModel* FUN_00613970(int, int);
};
// @fnv 0x00613fd0
void TESRace::ClearFaceGenUndo()
{
    BSStringT<char> filename;
    char path[260];
    for (int i = 0; i < 8; i++)
    {
        TESModel* female = reinterpret_cast<::FUN_00613970_shell *>(this)->FUN_00613970((*(int *)&(const ::SEX &)(SEX_SEX_MALE)), i);
        if (female && *female->GetModelFilePath())
        {
            TaskQueueInterface::CopyStringToBuffer(path, 260, "Meshes\\");
            strcat_s(path, 260, female->GetModelFilePath());
            ::GetModelEgtFilename((::BSStr *)&(filename), path);
            reinterpret_cast<::fnv_00650780::BSFaceGenModelMap_t *>((BSFaceGenManager::GetModelMap()))->FUN_00650780(
                reinterpret_cast<const char*>(reinterpret_cast<GarbageCollectorObjectPtr*>(&filename)->operator->()));
        }
        TESModel* male = reinterpret_cast<::FUN_00613970_shell *>(this)->FUN_00613970((*(int *)&(const ::SEX &)(SEX_SEX_FEMALE)), i);
        if (male && *male->GetModelFilePath() && male->CompareWithBase(female))
        {
            TaskQueueInterface::CopyStringToBuffer(path, 260, "Meshes\\");
            strcat_s(path, 260, male->GetModelFilePath());
            ::GetModelEgtFilename((::BSStr *)&(filename), path);
            reinterpret_cast<::fnv_00650780::BSFaceGenModelMap_t *>((BSFaceGenManager::GetModelMap()))->FUN_00650780(
                reinterpret_cast<const char*>(reinterpret_cast<GarbageCollectorObjectPtr*>(&filename)->operator->()));
        }
    }
}

// Returns the TESModel for the given sex and body part index, or null if the part index is out of range.
// @fnv 0x00613970
TESModel* FUN_00613970_shell::FUN_00613970(int aeSex, int aePart)
{
    if (aePart < 0 || aePart >= 8)
        return 0;
    return &m_kBodyPartModels[aeSex][aePart];
}

struct FUN_00613a20_shell : public TESRace
{
    TESModel* FUN_00613a20(int, int);
};
// Returns the model for the given sex and biped part, falling back to the opposite sex's model if the requested one is empty.
// @fnv 0x006151f0
TESModel* TESRace::GetBipedObjectModel(SEX sex, BIPED_OBJECT part)
{
    int index = ::NormalizePartIndex((*(int *)&(part)));
    if (sex < 0 || sex >= 2 || index < 0 || index >= 3)
        return 0;
    if (reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(sex)), index) && reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(sex)), index)->GetModelLength())
        return reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(sex)), index);
    switch (sex)
    {
    case SEX_SEX_MALE:
        if (reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(const ::SEX &)(SEX_SEX_FEMALE)), index) && reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(const ::SEX &)(SEX_SEX_FEMALE)), index)->GetModelLength())
            return reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(const ::SEX &)(SEX_SEX_FEMALE)), index);
        break;
    case SEX_SEX_FEMALE:
        if (reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(const ::SEX &)(SEX_SEX_MALE)), index) && reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(const ::SEX &)(SEX_SEX_MALE)), index)->GetModelLength())
            return reinterpret_cast<::FUN_00613a20_shell *>(this)->FUN_00613a20((*(int *)&(const ::SEX &)(SEX_SEX_MALE)), index);
        break;
    }
    return 0;
}

// Returns the TESModel for the given sex and body part index, or null if the part index is outside 0..2.
// @fnv 0x00613a20
TESModel* FUN_00613a20_shell::FUN_00613a20(int aeSex, int aePart)
{
    if (aePart < 0 || aePart >= 3)
        return 0;
    return &m_kHeadPartModels[aeSex][aePart];
}

struct FUN_00613b20_shell : public TESRace
{
    TESTexture* GetBodyPartTexture(int, int);
};

// Returns the TESTexture for the given sex and body part index, or null if the part index is out of range (0-7).
// @fnv 0x00613b20
TESTexture* FUN_00613b20_shell::GetBodyPartTexture(int aeSex, int aePart)
{
    if (aePart < 0 || aePart >= 8)
        return 0;
    return &m_kBodyPartTextures[aeSex][aePart];
}

struct FUN_00613fb0_C
{
    char _pad[0xe1];
    bool bIAmPlayerCharacter;
    void Set(bool abIAmPC);
};

// @fnv 0x00613fb0
void FUN_00613fb0_C::Set(bool abIAmPC)
{
    bIAmPlayerCharacter = abIAmPC;
}

namespace fnv_006148f0 {
struct BSFile;
struct FormRecordHeader;
struct TESFileGroup;
struct TESBitArrayFile;
struct TESObjectCELL;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
struct TESFile
{
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
    float GetFileVersion();
    void SetFileVersion(float);
    bool IsValidFileVersion();
    unsigned int GetFORMSize();
    char* GetPath();
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
    bool HasNextForm();
    void RewindForm();
    int GetTESForm();
    unsigned int GetOffset();
    unsigned int GetOffsetChunk();
    bool SetOffset(unsigned int);
    bool SetOffsetChunk(unsigned int);
    int GetFormAtOffset(unsigned int);
    unsigned int CopyCurrentFormToBuffer(void*, unsigned int);
    int ReadCurrentForm();
    bool NextChunk();
    unsigned int GetChunkSize();
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
    bool GetActive();
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
    unsigned short GetFormVersion();
    bool TakeOwnership();
    static bool TakeFileOwnership(char*);
    static unsigned short GetFileFormVersion();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCached();
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
struct FUN_006148f0_shell : public TESRace
{
    bool BuildBodyModTexturePath(TESNPC*, char*, char*);
};

int __cdecl __mbsnicmp(const char*, const char*, unsigned int);

struct TESForm_ext : public TESForm
{
};

// @fnv 0x006148f0
bool FUN_006148f0_shell::BuildBodyModTexturePath(TESNPC* apNPC, char* apName, char* apFileName)
{
    TESNPC* pfacenpc = apNPC;
    bool bUpdate;
    if (reinterpret_cast<::FUN_006044c0_shell *>((apNPC))->FUN_006044c0())
    {
        pfacenpc = reinterpret_cast<::FUN_006044c0_shell *>((apNPC))->FUN_006044c0();
        while (pfacenpc && reinterpret_cast<::FUN_006044c0_shell *>((pfacenpc))->FUN_006044c0())
        {
            pfacenpc = reinterpret_cast<::FUN_006044c0_shell *>((pfacenpc))->FUN_006044c0();
        }
    }
    TESFile* pmaster = ((::fnv_006148f0::TESFile *)(reinterpret_cast<::TESForm *>((((TESForm_ext*)pfacenpc)))->GetOwnerMaster()));
    if (!pmaster)
        return false;
    bUpdate = false;
    if (!__mbsnicmp(((char *)(reinterpret_cast<::BGSCameraPath *>((pmaster))->GetShotList())), "update", 6))
        bUpdate = true;
    ::FUN_00406d00(apFileName, 0x104, "data\\Textures\\Characters\\BodyMods\\%s\\%s.dds",
               !bUpdate ? ((char *)(reinterpret_cast<::BGSCameraPath *>((pmaster))->GetShotList())) : "FalloutNV.ESM", apName);
    return true;
}
}  // namespace fnv_006148f0

class GlobalObject2_0040c150
{
  public:
};


// @fnv 0x006151d0
int FUN_006151d0()
{
    return *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011d5a50))))));
}

// Subtracts 2 from aePart and returns the result if it is in [0,3), otherwise returns -1.
// @fnv 0x00615300
int __cdecl NormalizePartIndex(int aePart)
{
    int epart = aePart - 2;
    if (epart < 0 || epart >= 3)
        return -1;
    else
        return epart;
}

struct FUN_00610430_shell : public TESForm
{
    char* GetStringOrEmpty();
};

struct Flt_00610430
{
};
// Returns the string from the Flt_00610430 object at offset 0x50c, or an empty string if it is null.
// @fnv 0x00610430
char* FUN_00610430_shell::GetStringOrEmpty()
{
    return ((char *)(::FUN_00559450((int *)(((Flt_00610430*)((char*)this + 0x50c)))))) ? ((char *)(::FUN_00559450((int *)(((Flt_00610430*)((char*)this + 0x50c)))))) : "";
}

struct FUN_00613100_shell
{
    char GetByteAtOffset(int offset);
};

// @fnv 0x00613100
char FUN_00613100_shell::GetByteAtOffset(int offset)
{
    return ((char*)this)[offset + 0x9c];
}

extern int DAT_0119b4e4;

// @fnv 0x00614630
int FUN_00614630()
{
    return DAT_0119b4e4;
}

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void __cdecl _security_check_cookie(unsigned int);

struct BSStr
{
};

struct BSStringT_char
{
};

struct FUN_00615330_shell
{
    bool SetWeaponName(char const* aWeapon);
};

// Copies aWeapon into a stack buffer, compares it with the string at this+0x50c, and if different stores it there and returns true.
// @fnv 0x00615330
bool FUN_00615330_shell::SetWeaponName(char const* aWeapon)
{
    unsigned int len = ::FUN_0044a670(aWeapon) + 1;
    char* buf = (char*)_alloca(len);
    TaskQueueInterface::CopyStringToBuffer(buf, len, aWeapon);
    if (reinterpret_cast<::B408A80String *>((void *)(((BSStringT_char*)((char*)this + 0x50c))))->FUN_00408a80(buf, true) == 0)
    {
        return false;
    }
    reinterpret_cast<::TextString *>((((BSStr*)((char*)this + 0x50c))))->FUN_004037f0(buf, 0);
    return true;
}

struct FUN_00610470_shell
{
    void FUN_006104c0();
    void* FUN_00610470(unsigned int);
};
// Calls FUN_006104c0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00610470
void* FUN_00610470_shell::FUN_00610470(unsigned int flags)
{
    FUN_006104c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct List_009e03e0
{
};
struct FUN_00613850_shell
{
    void FUN_00613850();
};
// @fnv 0x00613850
void FUN_00613850_shell::FUN_00613850()
{
    reinterpret_cast<::FileMatchList *>((((::List_009e03e0 *)(::FUN_0045bb80((int)this)))))->RemoveAll();
}

namespace fnv_00613950 {
struct List_009e03e0
{
};
struct FUN_00613950_shell : public TESDataHandler
{
    void ClearRecipeCategoryList();
};
// @fnv 0x00613950
void FUN_00613950_shell::ClearRecipeCategoryList()
{
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((void *)(reinterpret_cast<::FUN_00503650_shell *>(this)->FUN_00503650())))))->RemoveAll();
}
}  // namespace fnv_00613950

struct FullNameEx
{
    char _pad[12];
};
struct Mid
{
    FullNameEx arr[8];
};
struct Obj
{
    char _pad[0x230];
    Mid m[3];
    void FUN_00613b60(int, int, char const*);
};
// Bounds-checks a (0-2) and b (0-7), then calls SetFullName on m[a].arr[b] with the given string.
// @fnv 0x00613b60
void Obj::FUN_00613b60(int a, int aiIndex, char const* apName)
{
    if (aiIndex < 0 || aiIndex >= 8 || a < 0 || a > 2)
        return;
    reinterpret_cast<::TESFullName *>(&(m[a].arr[aiIndex]))->SetFullName(apName);
}

namespace fnv_00613c00 {
struct FullNameEx
{
};
struct FUN_00613c00_shell
{
    FullNameEx m[3];
    void FUN_00613c00(int a, int b, const char* c);
};
// @fnv 0x00613c00
void FUN_00613c00_shell::FUN_00613c00(int aiIndex, int aiSubIndex, const char* apName)
{
    if (aiIndex < 0 || aiIndex >= 2 || aiSubIndex < 0 || aiSubIndex >= 3)
        return;
    reinterpret_cast<::TESFullName *>((((FullNameEx*)((char*)this + 0x2f0) + aiIndex * 36 + aiSubIndex * 12)))->SetFullName(apName);
}
}  // namespace fnv_00613c00

struct Holder00613120
{
    unsigned char _pad[0xA0];
    float f0xA0;
    float FUN_00613120();
};
// Returns f0xA0 when it is greater than _gModifierZero, otherwise returns 5.0f.
// @fnv 0x00613120
float Holder00613120::FUN_00613120()
{
    return f0xA0 > ::_DAT_01012060 ? f0xA0 : 5.0f;
}

struct S00613160
{
    unsigned char _pad[0xA4];
    float fieldA4;
    float GetFieldA4OrDefault();
};
// Returns fieldA4 if it is greater than _gModifierZero, otherwise returns 3.0f.
// @fnv 0x00613160
float S00613160::GetFieldA4OrDefault()
{
    return fieldA4 > ::_DAT_01012060 ? fieldA4 : 3.0f;
}

struct FUN_Elem12
{
    int f0;
    int f1;
    int f2;
};
struct FUN_Row36
{
    FUN_Elem12 e[3];
};
struct FUN_00613bb0_shell
{
    char _pad[0x2F0];
    FUN_Row36 m[2];
    FUN_Elem12* FUN_00613bb0(int a, int b);
};
// Returns a pointer to element e[b] of row m[a] when a is in [0,2) and b in [0,3), otherwise returns null.
// @fnv 0x00613bb0
FUN_Elem12* FUN_00613bb0_shell::FUN_00613bb0(int aiRow, int aiColumn)
{
    if (aiRow < 0 || aiRow >= 2 || aiColumn < 0 || aiColumn >= 3)
        return 0;
    return &m[aiRow].e[aiColumn];
}

struct RaceCleanup : TESRace
{
    void FUN_00610ac0();
};
// @fnv 0x00610ac0
void RaceCleanup::FUN_00610ac0()
{
    reinterpret_cast<::FUN_00613850_shell *>(this)->FUN_00613850();
    reinterpret_cast<::fnv_00613950::FUN_00613950_shell *>(this)->ClearRecipeCategoryList();
    unsigned int uiOuterIndex, i;
    for (uiOuterIndex = 0; uiOuterIndex < 2; ++uiOuterIndex)
    {
        for (i = 0; i < 8; ++i)
        {
            reinterpret_cast<::FUN_00402d50 *>(&(m_kBodyPartModels[uiOuterIndex][i]))->FUN_00402d50::~FUN_00402d50();
            reinterpret_cast<::FUN_00402d50 *>(&(m_kBodyPartTextures[uiOuterIndex][i]))->FUN_00402d50::~FUN_00402d50();
        }
    }
    for (uiOuterIndex = 0; uiOuterIndex < 2; ++uiOuterIndex)
    {
        for (i = 0; i < 3; ++i)
        {
            reinterpret_cast<::FUN_00402d50 *>(&(m_kHeadPartTextures[uiOuterIndex][i]))->FUN_00402d50::~FUN_00402d50();
            reinterpret_cast<::FUN_00402d50 *>(&(m_kHeadPartModels[uiOuterIndex][i]))->FUN_00402d50::~FUN_00402d50();
        }
        reinterpret_cast<::FUN_00402d50 *>(&(m_kFaceGenTextureModels[uiOuterIndex]))->FUN_00402d50::~FUN_00402d50();
    }
}

struct FlagBox_cls
{
    bool v;
};
struct FUN_00611db0_cls
{
    char unk00[0x10];
    int m_10[2];
    int m_18[2];
    int m_20;

    void FUN_00611db0();
};


// @fnv 0x00611db0
void FUN_00611db0_cls::FUN_00611db0()
{
    for (int i = 0; i < 2; i++)
    {
        FlagBox_cls a = {};
        ::FUN_00401080((int *)(void *)(&m_10[i]));
        FlagBox_cls b = {};
        ::FUN_00401080((int *)(void *)(&m_18[i]));
    }
    {
        FlagBox_cls c = {};
        ::FUN_00401080((int *)(void *)(&m_20));
    }
}

struct SkillBonusEntry
{
    char m_eWeaponSkill;
    char m_cBonus;
};
struct TextureNameHolder
{
};
struct AttributeSource;

struct RaceAccess : public TESRace
{
    int GetFlags();
    TESModel* GetBodyTexModel(unsigned int auiSex);
    BSSimpleList<TESEyes*>* GetEyeList();
};

struct FUN_00612c90_cls : public RaceAccess
{
    void CopyFromRace(TESForm* apSource);
};

struct FUN_006139b0_elem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int c);
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

class FUN_006139b0_cls
{
  public:
    char unk00[0xb0];
    FUN_006139b0_elem m_pElements[2][8];
    void CallElementVirtual(int a, int b, int c);
};

// @fnv 0x006139b0
void FUN_006139b0_cls::CallElementVirtual(int aiRow, int aiColumn, int c)
{
    if (aiColumn < 0 || aiColumn >= 8 || aiRow < 0 || aiRow >= 2)
    {
    }
    else
    {
        m_pElements[aiRow][aiColumn].v06(c);
    }
}

struct S_00613ad0_Base
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int);
};

void S_00613ad0_Base::V0()
{}
void S_00613ad0_Base::V1()
{}
void S_00613ad0_Base::V2()
{}
void S_00613ad0_Base::V3()
{}
void S_00613ad0_Base::V4()
{}
void S_00613ad0_Base::V5()
{}
void S_00613ad0_Base::V6(int)
{}

struct S_00613ad0_Element : public S_00613ad0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S_00613ad0_Class
{
    double unk000;
    double unk008;
    double unk010;
    double unk018;
    double unk020;
    double unk028;
    double unk030;
    double unk038;
    double unk040;
    double unk048;
    double unk050;
    double unk058;
    double unk060;
    double unk068;
    double unk070;
    double unk078;
    double unk080;
    double unk088;
    double unk090;
    double unk098;
    double unk0a0;
    double unk0a8;
    double unk0b0;
    double unk0b8;
    double unk0c0;
    double unk0c8;
    double unk0d0;
    double unk0d8;
    double unk0e0;
    double unk0e8;
    double unk0f0;
    double unk0f8;
    double unk100;
    double unk108;
    double unk110;
    double unk118;
    double unk120;
    double unk128;
    double unk130;
    double unk138;
    double unk140;
    double unk148;
    double unk150;
    double unk158;
    double unk160;
    double unk168;
    double unk170;
    double unk178;
    double unk180;
    double unk188;
    double unk190;
    double unk198;
    double unk1a0;
    double unk1a8;
    double unk1b0;
    double unk1b8;
    double unk1c0;
    double unk1c8;
    double unk1d0;
    double unk1d8;
    double unk1e0;
    double unk1e8;
    double unk1f0;
    double unk1f8;
    double unk200;
    double unk208;
    double unk210;
    double unk218;
    double unk220;
    double unk228;
    double unk230;
    double unk238;
    double unk240;
    double unk248;
    double unk250;
    double unk258;
    double unk260;
    double unk268;
    double unk270;
    double unk278;
    double unk280;
    double unk288;
    double unk290;
    double unk298;
    double unk2a0;
    double unk2a8;
    double unk2b0;
    double unk2b8;
    double unk2c0;
    double unk2c8;
    double unk2d0;
    double unk2d8;
    double unk2e0;
    double unk2e8;
    double unk2f0;
    double unk2f8;
    double unk300;
    double unk308;
    double unk310;
    double unk318;
    double unk320;
    double unk328;
    double unk330;
    double unk338;
    double unk340;
    double unk348;
    double unk350;
    double unk358;
    double unk360;
    double unk368;
    double unk370;
    double unk378;
    double unk380;
    double unk388;
    double unk390;
    double unk398;
    double unk3a0;
    double unk3a8;
    double unk3b0;
    double unk3b8;
    int unk3c0;
    int unk3c4;

    S_00613ad0_Element m[2];

    void DispatchToElement(int, int);
};

// Bounds-checks a against the two-element array m and, if valid, calls the element's virtual V6 with b.
// @fnv 0x00613ad0
void S_00613ad0_Class::DispatchToElement(int aiIndex, int b)
{
    if (aiIndex < 0 || aiIndex >= 2)
        return;

    m[aiIndex].V6(b);
}

extern const char* DAT_0119a068[2][3];
struct TextureAccess : TESTexture
{
};
struct RaceReset : TESRace
{
    void ResetRaceData();
};
// @fnv 0x00610210
TESRace::TESRace() : m_kFaceGenUndoList(0, 1)
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_RACE_ID)));
    reinterpret_cast<::RaceReset *>(this)->ResetRaceData();
}
// @fnv 0x006106a0
void RaceReset::ResetRaceData()
{
    unsigned int index, sex, part;
    ::FUN_00403d30(&Data, 0, 0x24);
    for (index = 0; index < 7; index++)
        Data.m_kSkillBonuses[index].m_eWeaponSkill = -1;
    for (index = 0; index < 2; index++)
    {
        Data.fWeight[index] = 1.0f;
        Data.m_fGlyphExtent[index] = 1.0f;
    }
    m_apDefaultHairStyles[0] = 0;
    m_apDefaultHairStyles[1] = 0;
    m_apDefaultVoiceTypes[0] = DAT_011cb298;
    m_apDefaultVoiceTypes[1] = DAT_011cb29c;
    m_fFaceGenMainClamp = 0.0f;
    m_fFaceGenFaceClamp = 0.0f;
    m_acDefaultHairColors[0] = 0;
    m_acDefaultHairColors[1] = 0;
    ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(void *)(((void *)(::BSFaceGenManager::GetFaceGenCoordinates()))), (FaceGenCoordArray (*)[2])(void *)(((void *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(0)))), 0, 0);
    ::BSFaceGenManager::InitializeFaceGenCoordinates((::FaceGenCoordinates *)(void *)(((void *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(0)))));
    ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(void *)(((void *)(::BSFaceGenManager::GetFaceGenCoordinates()))), (FaceGenCoordArray (*)[2])(void *)(((void *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(1)))), 0, 0);
    ::BSFaceGenManager::InitializeFaceGenCoordinates((::FaceGenCoordinates *)(void *)(((void *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(1)))));
    m_usRaceAttribute = 0;
    for (sex = 0; sex < 2; sex++)
    {
        for (part = 0; part < 8; part++)
        {
            m_kBodyPartModels[sex][part].Init();
            m_kBodyPartModels[sex][part].SetModelFilePath(DAT_01199fe8[sex][part]);
            m_kBodyPartTextures[sex][part].Init();
            reinterpret_cast<::TESFullName *>((((TextureAccess*)&m_kBodyPartTextures[sex][part])))->SetFullName(DAT_0119a028[sex][part]);
        }
    }
    for (sex = 0; sex < 2; sex++)
    {
        for (part = 0; part < 3; part++)
        {
            m_kHeadPartTextures[sex][part].Init();
            reinterpret_cast<::TESFullName *>((((TextureAccess*)&m_kHeadPartTextures[sex][part])))->SetFullName(DAT_0119a068[sex][part]);
            m_kHeadPartModels[sex][part].Init();
            m_kHeadPartModels[sex][part].SetModelFilePath(DAT_0119a080[sex][part]);
        }
        m_kFaceGenTextureModels[sex].Init();
        m_kFaceGenTextureModels[sex].SetModelFilePath(DAT_01199fbc[sex]);
    }
    m_pOlderRace = 0;
    m_pYoungerRace = 0;
}

extern "C" void* __cdecl _alloca(unsigned int);
struct SaveComponent611e50
{
};
struct SaveForm611e50
{
};
struct SaveList611e50
{
    unsigned int FUN_005ae380();
};
struct FaceValue611e50
{
    int unk00, unk04;
};
struct FaceMatrix611e50
{
    FaceValue611e50 FUN_0060b370(unsigned int, int);
};
struct SaveRace611e50
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    RaceDefinitionData Data;
    TESAttributes m_kMaleAttributes, m_kFemaleAttributes;
    BSSimpleList<TESHair*> m_kHairList;
    TESHair* m_apDefaultHairStyles[2];
    unsigned char m_acDefaultHairColors[2];
    float m_fFaceGenMainClamp, m_fFaceGenFaceClamp;
    BSSimpleList<TESEyes*> m_kEyeList;
    TESModel m_kBodyPartModels[2][8];
    TESTexture m_kBodyPartTextures[2][8];
    TESTexture m_kHeadPartTextures[2][3];
    TESModel m_kHeadPartModels[2][3];
    BGSTextureModel m_kFaceGenTextureModels[2];
    FaceGenMatrix<float> m_kFirstFloatPairBySex[2][2], m_kSecondFloatPairBySex[2][2];
    unsigned short m_usRaceAttribute;
    BGSVoiceType* m_apDefaultVoiceTypes[2];
    TESRace* m_pOlderRace;
    TESRace* m_pYoungerRace;
    void SaveRace();
};
// @fnv 0x00611e50
void SaveRace611e50::SaveRace()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((SaveComponent611e50*)&unk18)))->FUN_00487010();
    reinterpret_cast<::FUN_00482cb0_shell *>((((SaveComponent611e50*)&unk24)))->FUN_00482cb0();
    reinterpret_cast<::TESSpellListShell *>((((SaveComponent611e50*)&unk2c)))->FUN_0048d330();
    reinterpret_cast<::FUN_0048bb70_shell *>((((SaveComponent611e50*)&unk40)))->WriteCameraShotList();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00611db0_cls *>((((SaveComponent611e50*)&Data)))->FUN_00611db0();
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20(&Data, 0x24);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00611db0_cls *>((((SaveComponent611e50*)&Data)))->FUN_00611db0();
    unsigned int formid51 = 0;
    if (m_pOlderRace)
    {
        formid51 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm611e50*)m_pOlderRace)))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e4f, formid51);
    }
    if (m_pYoungerRace)
    {
        formid51 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm611e50*)m_pYoungerRace)))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e59, formid51);
    }
    ::FUN_004856d0(0x324d414e);
    if (m_apDefaultVoiceTypes[0] || m_apDefaultVoiceTypes[1])
    {
        unsigned int voiceids[2];
        for (int voiceindex = 0; voiceindex < 2; voiceindex++)
        {
            if (m_apDefaultVoiceTypes[voiceindex])
                voiceids[voiceindex] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm611e50*)m_apDefaultVoiceTypes[voiceindex])))->FUN_0084e3a0()));
            else
                voiceids[voiceindex] = 0;
        }
        ::FUN_00485710((void *)(0x4b435456), (void *)(voiceids), (void *)(2));
    }
    if (m_apDefaultHairStyles[0] || m_apDefaultHairStyles[1])
    {
        unsigned int hairids[2];
        for (int hairindex = 0; hairindex < 2; hairindex++)
        {
            if (m_apDefaultHairStyles[hairindex])
                hairids[hairindex] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm611e50*)m_apDefaultHairStyles[hairindex])))->FUN_0084e3a0()));
            else
                hairids[hairindex] = 0;
        }
        ::FUN_00485710((void *)(0x4d414e44), (void *)(hairids), (void *)(2));
    }
    ::FUN_004856f0((void *)(0x4d414e43), (void *)(m_acDefaultHairColors), (void *)(2));
    ::FUN_00485910(0x4d414e50, m_fFaceGenMainClamp);
    ::FUN_00485910(0x4d414e55, m_fFaceGenFaceClamp);
    unsigned int attributeSize72 = reinterpret_cast<::FUN_009d2510_shell *>((((SaveComponent611e50*)&m_kMaleAttributes)))->FUN_009d2510();
    char* attributeData20 = (char*)_alloca(attributeSize72 * 2);
    reinterpret_cast<::FUN_00480100_shell *>((((SaveComponent611e50*)&m_kMaleAttributes)))->FUN_00480100(attributeData20);
    reinterpret_cast<::FUN_00480100_shell *>((((SaveComponent611e50*)&m_kFemaleAttributes)))->FUN_00480100(attributeData20 + attributeSize72);
    ::FUN_004856f0((void *)(0x52545441), (void *)(attributeData20), (void *)(2));
    ::FUN_004856d0(0x304d414e);
    unsigned int sex3, part2;
    for (sex3 = 0; sex3 < 2; sex3++)
    {
        if (sex3 == 0)
            ::FUN_004856d0(0x4d414e4d);
        else if (sex3 == 1)
            ::FUN_004856d0(0x4d414e46);
        for (part2 = 0; part2 < 8; part2++)
        {
            ::FUN_00485910(0x58444e49, part2);
            reinterpret_cast<::FUN_004891d0_cls *>((((SaveComponent611e50*)&m_kBodyPartModels[sex3][part2])))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
            reinterpret_cast<::FUN_00489240_Class *>((((SaveComponent611e50*)&m_kBodyPartModels[sex3][part2])))->FUN_00489240(0x44444f4d);
            reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((SaveComponent611e50*)&m_kBodyPartTextures[sex3][part2])))->FUN_0048e370(0x4e4f4349);
        }
    }
    ::FUN_004856d0(0x314d414e);
    for (sex3 = 0; sex3 < 2; sex3++)
    {
        if (sex3 == 0)
            ::FUN_004856d0(0x4d414e4d);
        else if (sex3 == 1)
            ::FUN_004856d0(0x4d414e46);
        for (part2 = 0; part2 < 3; part2++)
        {
            ::FUN_00485910(0x58444e49, part2);
            reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((SaveComponent611e50*)&m_kHeadPartTextures[sex3][part2])))->FUN_0048e370(0x4e4f4349);
            reinterpret_cast<::FUN_004891d0_cls *>((((SaveComponent611e50*)&m_kHeadPartModels[sex3][part2])))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
            reinterpret_cast<::FUN_00489240_Class *>((((SaveComponent611e50*)&m_kHeadPartModels[sex3][part2])))->FUN_00489240(0x44444f4d);
        }
        ::FUN_00485910(0x58444e49, part2);
        reinterpret_cast<::FUN_004891d0_cls *>((((SaveComponent611e50*)&m_kFaceGenTextureModels[sex3])))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    }
    {
        SaveList611e50* hairlist7 = ((::SaveList611e50 *)(::FUN_0045bb80((int)this)));
        unsigned int hairposition7 = 0;
        unsigned int haircount2 = hairlist7->FUN_005ae380();
        unsigned int* hairdata1 = new unsigned int[haircount2];
        while (hairlist7 && *((::SaveForm611e50 **)(new ((void *)(hairlist7)) ::Vec3())))
        {
            hairdata1[hairposition7] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*((::SaveForm611e50 **)(new ((void *)(hairlist7)) ::Vec3())))))->FUN_0084e3a0()));
            hairposition7++;
            hairlist7 = ((::SaveList611e50 *)(reinterpret_cast<::Callees *>((hairlist7))->FUN_00726070()));
        }
        ::FUN_00485710((void *)(0x4d414e48), (void *)(hairdata1), (void *)(haircount2));
        delete[] hairdata1;
    }
    {
        SaveList611e50* eyelist45 = ((::SaveList611e50 *)(reinterpret_cast<::FUN_00503650_shell *>(this)->FUN_00503650()));
        unsigned int eyeposition15 = 0;
        unsigned int eyecount20 = eyelist45->FUN_005ae380();
        unsigned int* eyedata3 = new unsigned int[eyecount20];
        while (eyelist45 && *((::SaveForm611e50 **)(new ((void *)(eyelist45)) ::Vec3())))
        {
            eyedata3[eyeposition15] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*((::SaveForm611e50 **)(new ((void *)(eyelist45)) ::Vec3())))))->FUN_0084e3a0()));
            eyeposition15++;
            eyelist45 = ((::SaveList611e50 *)(reinterpret_cast<::Callees *>((eyelist45))->FUN_00726070()));
        }
        ::FUN_00485710((void *)(0x4d414e45), (void *)(eyedata3), (void *)(eyecount20));
        delete[] eyedata3;
    }
    for (sex3 = 0; sex3 < 2; sex3++)
    {
        if (sex3 == 0)
            ::FUN_004856d0(0x4d414e4d);
        else if (sex3 == 1)
            ::FUN_004856d0(0x4d414e46);
        unsigned int count = 0;
        if (sex3 == 0)
            count = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][0])))->FUN_009611e0()));
        else if (sex3 == 1)
            count = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][0])))->FUN_009611e0()));
        if (count)
        {
            unsigned int geometrybytes31 = count * 4;
            float* geometrydata18 = (float*)FUN_00401000(geometrybytes31);
            ::FUN_00403d30(geometrydata18, 0, geometrybytes31);
            for (unsigned int geometryindex = 0; geometryindex < count; geometryindex++)
            {
                if (sex3 == 0)
                    geometrydata18[geometryindex] = *((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue611e50 &)(((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][0])
                                                         ->FUN_0060b370(geometryindex, 0)))->FUN_00629ab0({})));
                else if (sex3 == 1)
                    geometrydata18[geometryindex] = *((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue611e50 &)(((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][0])
                                                         ->FUN_0060b370(geometryindex, 0)))->FUN_00629ab0({})));
            }
            ::FUN_00485710((void *)(0x53474746), (void *)(geometrydata18), (void *)(count));
            FUN_00401030(geometrydata18);
            geometrydata18 = 0;
        }
        if (sex3 == 0)
            count = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][1])))->FUN_009611e0()));
        else if (sex3 == 1)
            count = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][1])))->FUN_009611e0()));
        if (count)
        {
            unsigned int asymmetrybytes4 = count * 4;
            float* asymmetrydata24 = (float*)FUN_00401000(asymmetrybytes4);
            ::FUN_00403d30(asymmetrydata24, 0, asymmetrybytes4);
            for (unsigned int asymmetryindex = 0; asymmetryindex < count; asymmetryindex++)
            {
                if (sex3 == 0)
                    asymmetrydata24[asymmetryindex] = *((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue611e50 &)(((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][1])
                                                           ->FUN_0060b370(asymmetryindex, 0)))->FUN_00629ab0({})));
                else if (sex3 == 1)
                    asymmetrydata24[asymmetryindex] = *((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue611e50 &)(((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][1])
                                                           ->FUN_0060b370(asymmetryindex, 0)))->FUN_00629ab0({})));
            }
            ::FUN_00485710((void *)(0x41474746), (void *)(asymmetrydata24), (void *)(count));
            FUN_00401030(asymmetrydata24);
            asymmetrydata24 = 0;
        }
        if (sex3 == 0)
            count = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix611e50*)&m_kSecondFloatPairBySex[1][0])))->FUN_009611e0()));
        else if (sex3 == 1)
            count = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((FaceMatrix611e50*)&m_kFirstFloatPairBySex[1][0])))->FUN_009611e0()));
        if (count)
        {
            unsigned int texturebytes2 = count * 4;
            float* texturedata16 = (float*)FUN_00401000(texturebytes2);
            ::FUN_00403d30(texturedata16, 0, texturebytes2);
            for (unsigned int textureindex = 0; textureindex < count; textureindex++)
            {
                if (sex3 == 0)
                    texturedata16[textureindex] = *((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue611e50 &)(((FaceMatrix611e50*)&m_kSecondFloatPairBySex[1][0])
                                                       ->FUN_0060b370(textureindex, 0)))->FUN_00629ab0({})));
                else if (sex3 == 1)
                    texturedata16[textureindex] = *((float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceValue611e50 &)(((FaceMatrix611e50*)&m_kFirstFloatPairBySex[1][0])
                                                       ->FUN_0060b370(textureindex, 0)))->FUN_00629ab0({})));
            }
            ::FUN_00485710((void *)(0x53544746), (void *)(texturedata16), (void *)(count));
            FUN_00401030(texturedata16);
            texturedata16 = 0;
        }
        ::FUN_00485950((void *)(0x4d414e53), m_usRaceAttribute);
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct RaceListItem
{
};
struct RaceList
{
    unsigned FUN_005ae380();
};
struct RaceComparer : TESRace
{
    bool IsDifferentFrom(TESForm*);
    TESEyes* FUN_00613870(unsigned);
};
int FUN_00ec4835(const void*, const void*, unsigned);
// Compares this race against another TESRace field by field and returns true as soon as any difference is found.
// @fnv 0x006131c0
bool RaceComparer::IsDifferentFrom(TESForm* form)
{
    RaceComparer* pOtherRace = (RaceComparer*)dynamic_cast<TESRace*>(form);
    if (!pOtherRace)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(pOtherRace)))
        return true;
    if (FUN_00ec4835(&Data, ((::RaceDefinitionData *)(reinterpret_cast<::FUN_00613790_shell *>((pOtherRace))->FUN_00613790())), 36))
        return true;
    if (m_pOlderRace != pOtherRace->m_pOlderRace)
        return true;
    if (m_pYoungerRace != pOtherRace->m_pYoungerRace)
        return true;
    if (((::TESHair *)(reinterpret_cast<::FUN_00604780_shell *>(this)->FUN_00604780(0))) != ((::TESHair *)(reinterpret_cast<::FUN_00604780_shell *>((pOtherRace))->FUN_00604780(0))))
        return true;
    if (((::TESHair *)(reinterpret_cast<::FUN_00604780_shell *>(this)->FUN_00604780(1))) != ((::TESHair *)(reinterpret_cast<::FUN_00604780_shell *>((pOtherRace))->FUN_00604780(1))))
        return true;
    if (FUN_00613870(0) != pOtherRace->FUN_00613870(0))
        return true;
    if (FUN_00613870(1) != pOtherRace->FUN_00613870(1))
        return true;
    if (reinterpret_cast<::FUN_00613100_shell *>(this)->GetByteAtOffset(0) != reinterpret_cast<::FUN_00613100_shell *>((pOtherRace))->GetByteAtOffset(0))
        return true;
    if (reinterpret_cast<::FUN_00613100_shell *>(this)->GetByteAtOffset(1) != reinterpret_cast<::FUN_00613100_shell *>((pOtherRace))->GetByteAtOffset(1))
        return true;
    if (reinterpret_cast<::Holder00613120 *>(this)->FUN_00613120() != reinterpret_cast<::Holder00613120 *>((pOtherRace))->FUN_00613120())
        return true;
    if (reinterpret_cast<::S00613160 *>(this)->GetFieldA4OrDefault() != reinterpret_cast<::S00613160 *>((pOtherRace))->GetFieldA4OrDefault())
        return true;
    if (m_kMaleAttributes.CompareWithBase(((::TESAttributes *)(reinterpret_cast<::BGSExplosion *>((pOtherRace))->FUN_004fadc0()))))
        return true;
    if (m_kFemaleAttributes.CompareWithBase(((::TESAttributes *)(reinterpret_cast<::TESDataHandler *>((pOtherRace))->GetTESClassList()))))
        return true;
    for (unsigned uiSex = 0; uiSex < 2; ++uiSex)
    {
        for (unsigned part = 0; part < 8; ++part)
        {
            if (m_kBodyPartModels[uiSex][part].CompareWithBase(reinterpret_cast<::FUN_00613970_shell *>((pOtherRace))->FUN_00613970(uiSex, part)) ||
                m_kBodyPartTextures[uiSex][part].CompareWithBase(reinterpret_cast<::FUN_00613b20_shell *>((pOtherRace))->GetBodyPartTexture(uiSex, part)))
                return true;
        }
    }
    for (unsigned uiBodySex = 0; uiBodySex < 2; ++uiBodySex)
    {
        for (unsigned part = 0; part < 3; ++part)
        {
            if (m_kHeadPartTextures[uiBodySex][part].CompareWithBase(&pOtherRace->m_kHeadPartTextures[uiBodySex][part]))
                return true;
            if (m_kHeadPartModels[uiBodySex][part].CompareWithBase(&pOtherRace->m_kHeadPartModels[uiBodySex][part]))
                return true;
        }
        if (m_kFaceGenTextureModels[uiBodySex].CompareWithBase(&pOtherRace->m_kFaceGenTextureModels[uiBodySex]))
            return true;
    }
    {
        RaceList* hair = ((::RaceList *)(::FUN_0045bb80((int)(pOtherRace))));
        if (((::RaceList *)(::FUN_0045bb80((int)this)))->FUN_005ae380() != hair->FUN_005ae380())
            return true;
        while (hair && ((::RaceListItem *)(new ((void *)(hair)) ::Vec3())))
        {
            if (!((int)(reinterpret_cast<::FUN_006137b0_shell *>(this)->FindByKey((int)(((const char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RaceListItem *)(new ((void *)(hair)) ::Vec3()))))->FUN_0084e3a0())))))))
                return true;
            hair = ((::RaceList *)(reinterpret_cast<::Callees *>((hair))->FUN_00726070()));
        }
    }
    {
        RaceList* pEyesList = ((::RaceList *)(reinterpret_cast<::FUN_00503650_shell *>((pOtherRace))->FUN_00503650()));
        if (((::RaceList *)(reinterpret_cast<::FUN_00503650_shell *>(this)->FUN_00503650()))->FUN_005ae380() != pEyesList->FUN_005ae380())
            return true;
        while (pEyesList && ((::RaceListItem *)(new ((void *)(pEyesList)) ::Vec3())))
        {
            if (!((int)(reinterpret_cast<::FUN_006138b0_shell *>(this)->FindRecipeCategoryById((int)(((const char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RaceListItem *)(new ((void *)(pEyesList)) ::Vec3()))))->FUN_0084e3a0())))))))
                return true;
            pEyesList = ((::RaceList *)(reinterpret_cast<::Callees *>((pEyesList))->FUN_00726070()));
        }
    }
    if (::fnv_00652900::FUN_00652900((const fnv_00652900::FaceGenMatrix<float> (*)[2])(::BGSVoiceType *)(((::BGSVoiceType *)(reinterpret_cast<::S9fb0 *>((pOtherRace))->FUN_005d9fb0(0)))), (fnv_00652900::FaceGenMatrix<float> (*)[2])(::BGSVoiceType *)(((::BGSVoiceType *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(0))))))
    {
        m_usRaceAttribute = ((unsigned short)(::DialogueRandom()));
        return true;
    }
    if (::fnv_00652900::FUN_00652900((const fnv_00652900::FaceGenMatrix<float> (*)[2])(::BGSVoiceType *)(((::BGSVoiceType *)(reinterpret_cast<::S9fb0 *>((pOtherRace))->FUN_005d9fb0(1)))), (fnv_00652900::FaceGenMatrix<float> (*)[2])(::BGSVoiceType *)(((::BGSVoiceType *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(1))))))
    {
        m_usRaceAttribute = ((unsigned short)(::DialogueRandom()));
        return true;
    }
    if (reinterpret_cast<::FUN_00607350_shell *>(this)->FUN_00607350() != reinterpret_cast<::FUN_00607350_shell *>((pOtherRace))->FUN_00607350())
        return true;
    return false;
}

// Forward a value to one cell of the 2x3 slot grid (ignored when out of range).

class D3A60Slot
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void SetValue(int iValue);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D3A60Grid
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    D3A60Slot m_aakSlots[2][3];

    void SetSlotValue(int iRow, int iColumn, int iValue);
};
// Copies voice, hair, attributes, skill bonuses, models, textures, hair/eye lists and face data from another TESRace into this race.
// @fnv 0x00612c90
void FUN_00612c90_cls::CopyFromRace(TESForm* apSource)
{
    BSSimpleList<TESEyes*>* pEyes;
    RaceAccess* pRace3;
    BSSimpleList<TESHair*>* _pHair;
    unsigned int i;
    int j3;
    unsigned int uiSexB;
    unsigned int uiPartA;
    unsigned int uiSex4;
    unsigned int uiPart2;
    unsigned int uiPart8;

    pRace3 = (RaceAccess*)dynamic_cast<TESRace*>(apSource);
    if (pRace3 == 0)
    {
        return;
    }
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0((void *)(apSource));
    m_pOlderRace = pRace3->m_pOlderRace;
    m_pYoungerRace = pRace3->m_pYoungerRace;
    m_apDefaultVoiceTypes[0] = ((::BGSVoiceType *)(reinterpret_cast<::FUN_00604780_shell *>((pRace3))->FUN_00604780(0)));
    m_apDefaultVoiceTypes[1] = ((::BGSVoiceType *)(reinterpret_cast<::FUN_00604780_shell *>((pRace3))->FUN_00604780(1)));
    m_apDefaultHairStyles[0] = ((::TESHair *)(reinterpret_cast<::FUN_00613870_Class *>((pRace3))->FUN_00613870(0)));
    m_apDefaultHairStyles[1] = ((::TESHair *)(reinterpret_cast<::FUN_00613870_Class *>((pRace3))->FUN_00613870(1)));
    m_acDefaultHairColors[0] = reinterpret_cast<::FUN_00613100_shell *>((pRace3))->GetByteAtOffset(0);
    m_acDefaultHairColors[1] = reinterpret_cast<::FUN_00613100_shell *>((pRace3))->GetByteAtOffset(1);
    m_fFaceGenMainClamp = reinterpret_cast<::Holder00613120 *>((pRace3))->FUN_00613120();
    m_fFaceGenFaceClamp = reinterpret_cast<::S00613160 *>((pRace3))->GetFieldA4OrDefault();
    m_kMaleAttributes.CopyFromBase(((::BaseFormComponent *)(reinterpret_cast<::BGSExplosion *>((pRace3))->FUN_004fadc0())));
    m_kFemaleAttributes.CopyFromBase(((::BaseFormComponent *)(reinterpret_cast<::TESDataHandler *>((pRace3))->GetTESClassList())));
    for (i = 0; i < 7; i++)
    {
        Data.m_kSkillBonuses[i].m_eWeaponSkill = ((::SkillBonusEntry *)(reinterpret_cast<::FUN_006130c0_Class *>((pRace3))->FUN_006130c0(i)))->m_eWeaponSkill;
        Data.m_kSkillBonuses[i].m_cBonus = ((::SkillBonusEntry *)(reinterpret_cast<::FUN_006130c0_Class *>((pRace3))->FUN_006130c0(i)))->m_cBonus;
    }
    for (j3 = 0; j3 < 2; j3++)
    {
        Data.m_fGlyphExtent[j3] = reinterpret_cast<::FUN_00604210_shell *>((pRace3))->FUN_00604210(j3);
        Data.fWeight[j3] = reinterpret_cast<::FUN_006042d0_Owner *>((pRace3))->GetArrValue(j3);
    }
    Data.iFlags = ((int)(reinterpret_cast<::FUN_004fd380_shell *>((pRace3))->FUN_004fd380()));
    for (uiSexB = 0; uiSexB < 2; uiSexB++)
    {
        for (uiPartA = 0; uiPartA < 8; uiPartA++)
        {
            reinterpret_cast<::FUN_006139b0_cls *>(this)->CallElementVirtual(uiSexB, uiPartA, (int)(reinterpret_cast<::FUN_00613970_shell *>((pRace3))->FUN_00613970(uiSexB, uiPartA)->GetModelFilePath()));
            reinterpret_cast<::Obj *>(this)->FUN_00613b60(uiSexB, uiPartA, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::TextureNameHolder *)(reinterpret_cast<::FUN_00613b20_shell *>((pRace3))->GetBodyPartTexture(uiSexB, uiPartA)))))->FUN_00408da0())));
        }
    }
    for (uiSex4 = 0; uiSex4 < 2; uiSex4++)
    {
        for (uiPart2 = 0; uiPart2 < 3; uiPart2++)
        {
            reinterpret_cast<::fnv_00613c00::FUN_00613c00_shell *>(this)->FUN_00613c00(uiSex4, uiPart2, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::TextureNameHolder *)(reinterpret_cast<::FUN_00613bb0_shell *>((pRace3))->FUN_00613bb0(uiSex4, uiPart2)))))->FUN_00408da0())));
        }
        for (uiPart8 = 0; uiPart8 < 3; uiPart8++)
        {
            reinterpret_cast<::D3A60Grid *>(this)->SetSlotValue(uiSex4, uiPart8, (int)(reinterpret_cast<::FUN_00613a20_shell *>((pRace3))->FUN_00613a20(uiSex4, uiPart8)->GetModelFilePath()));
        }
        reinterpret_cast<::S_00613ad0_Class *>(this)->DispatchToElement(uiSex4, (int)(pRace3->GetBodyTexModel(uiSex4)->GetModelFilePath()));
    }
    _pHair = ((::BSSimpleList< ::TESHair *> *)(::FUN_0045bb80((int)(pRace3))));
    reinterpret_cast<::FUN_00613850_shell *>(this)->FUN_00613850();
    while (_pHair != 0 && ((::TESHair *)(new ((void *)(_pHair)) ::Vec3())) != 0)
    {
        reinterpret_cast<::Callees *>((((::BSSimpleList< ::TESHair *> *)(::FUN_0045bb80((int)this)))))->FUN_00905820((void *)&(((::TESHair *)(new ((void *)(_pHair)) ::Vec3()))));
        _pHair = ((::BSSimpleList< ::TESHair *> *)(reinterpret_cast<::Callees *>((_pHair))->FUN_00726070()));
    }
    pEyes = pRace3->GetEyeList();
    reinterpret_cast<::fnv_00613950::FUN_00613950_shell *>(this)->ClearRecipeCategoryList();
    while (pEyes != 0 && pEyes->GetItem() != 0)
    {
        GetEyeList()->AddTail(pEyes->GetItem());
        pEyes = pEyes->GetNext();
    }
    ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::S9fb0 *>((pRace3))->FUN_005d9fb0((*(int *)&(const ::SEX &)(SEX_SEX_MALE)))))), (FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0((*(int *)&(const ::SEX &)(SEX_SEX_MALE)))))),
                                             false, false);
    ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::S9fb0 *>((pRace3))->FUN_005d9fb0((*(int *)&(const ::SEX &)(SEX_SEX_FEMALE)))))), (FaceGenCoordArray (*)[2])(FaceGenMatrix<float> (*)[2])(((FaceGenMatrix<float> (*)[2])(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0((*(int *)&(const ::SEX &)(SEX_SEX_FEMALE)))))),
                                             false, false);
    m_usRaceAttribute = reinterpret_cast<::FUN_00607350_shell *>((pRace3))->FUN_00607350();
}

// Bounds-checks iRow against 2 and iColumn against 3, then calls SetValue(iValue) on the addressed slot.
// @fnv 0x00613a60
void D3A60Grid::SetSlotValue(int iRow, int iColumn, int iValue)
{
    if (iColumn < 0 || iColumn >= 3 || iRow < 0 || iRow >= 2)
        return;
    m_aakSlots[iRow][iColumn].SetValue(iValue);
}

namespace RaceAppearance {
struct NPC;
struct Output;
struct Part;
struct List;
struct Name
{
};
struct Part
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Name name;
};
struct List
{
    bool FUN_008256d0();
};
struct Hair
{
};
struct String
{
    void* value;
    String(int);
    ~String();
};
struct Array
{
    unsigned int unk0, unk4, unk8, unkc;
};
struct Parts
{
    void FUN_005ae3d0(Part* const&);
};
struct Output
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    Hair* hair;
    int color;
    float length;
    Part* eyes;
    int sex;
    Array models, textures, slots, strings;
    unsigned char enabled, player, unkd6, unkd7;
    void* mouth;
    void* teeth;
    int texture;
    Parts parts;
};
struct NPC
{
    int FUN_005f0cc0();
};
struct Player
{
};
struct Setting
{
    bool* FUN_00408d60();
};
struct Data
{
};
extern const char DAT_0104b8a0[];
struct Race
{
    Hair* FUN_00613870(int);
    void BuildAppearance(NPC*, Output*, int, bool);
};
// Fills an Output appearance record from an NPC or, when npc is null, from race defaults: hair, eyes, color, models, textures, slots, parts, mouth and teeth.
// @fnv 0x006141f0
void Race::BuildAppearance(NPC* npc, Output* apOutput, int sex, bool skip)
{
    bool special = false;
    if (npc)
    {
        reinterpret_cast<::TESNPC *>((npc))->GetFaceGenCoords((FaceGenMatrix<float> (&)[2][2])(apOutput));
        sex = npc->FUN_005f0cc0();
        if (npc == ((::RaceAppearance::NPC *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::RaceAppearance::Player * *>(&::_g_thePlayer))))->FUN_007af430())))
        {
            apOutput->player = 1;
            if (reinterpret_cast<::FUN_006047a0_shell *>(((*reinterpret_cast<::RaceAppearance::Player * *>(&::_g_thePlayer))))->FUN_006047a0())
                special = true;
        }
    }
    else
    {
        void* model = ((void *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(sex)));
        if (!model)
            model = ((void *)(::BSFaceGenManager::GetFaceGenCoordinates()));
        ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(model), (FaceGenCoordArray (*)[2])(apOutput), 0, 0);
    }
    if (npc)
    {
        if (special || !((::RaceAppearance::Hair *)(reinterpret_cast<::TESNPC *>((npc))->GetHair())) || !reinterpret_cast<::FUN_005fdfa0_shell *>((((::RaceAppearance::Hair *)(reinterpret_cast<::TESNPC *>((npc))->GetHair()))))->IsHairValidForNPC((::TESNPC *)(npc)))
            apOutput->hair = ((::RaceAppearance::Hair *)(reinterpret_cast<::FUN_00613870_Class *>(this)->FUN_00613870(sex)));
        else
            apOutput->hair = ((::RaceAppearance::Hair *)(reinterpret_cast<::TESNPC *>((npc))->GetHair()));
        apOutput->length = reinterpret_cast<::FUN_00602130_shell *>((npc))->FUN_00602130();
        apOutput->color = ((int)(reinterpret_cast<::FUN_004169d0_shell *>((npc))->FUN_004169d0()));
        apOutput->eyes = ((::RaceAppearance::Part *)(reinterpret_cast<::MiddleHighProcess *>((npc))->GetAnimation()));
        apOutput->sex = npc->FUN_005f0cc0();
    }
    else
    {
        apOutput->hair = ((::RaceAppearance::Hair *)(reinterpret_cast<::FUN_00613870_Class *>(this)->FUN_00613870(sex)));
        apOutput->color = ((signed char)(reinterpret_cast<::FUN_00613100_shell *>(this)->GetByteAtOffset(sex)));
    }
    for (unsigned int i = 0; i < 8; i++)
    {
        reinterpret_cast<::S_0060ba10 *>(&(apOutput->models))->FUN_0096a610((int)&(const void *const &)(((void *)(reinterpret_cast<::FUN_00613970_shell *>(this)->FUN_00613970(sex, i)))));
        reinterpret_cast<::S_0060ba10 *>(&(apOutput->textures))->FUN_0096a610((int)&(const void *const &)(((void *)(reinterpret_cast<::FUN_00613b20_shell *>(this)->GetBodyPartTexture(sex, i)))));
        reinterpret_cast<::S_0060ba10 *>(&(apOutput->slots))->FUN_0096a610((int)&(const void *const &)(::FUN_00605d40(i)));
        if (npc && *(*reinterpret_cast<::RaceAppearance::Setting *>(&::g_011cb99c)).FUN_00408d60() && !skip)
        {
            String path(0);
            reinterpret_cast<::fnv_006044e0::FUN_006044e0_shell *>((npc))->CreatePartTexture(i, (void *)&(path));
            reinterpret_cast<::S_0060ba10 *>(&(apOutput->strings))->FUN_0060ba10((int)&(path));
        }
    }
    apOutput->enabled = *(*reinterpret_cast<::RaceAppearance::Setting *>(&::g_011cb99c)).FUN_00408d60();
    apOutput->texture = ::FUN_00614630();
    if (npc && !special)
    {
        List* parts = ((::RaceAppearance::List *)(reinterpret_cast<::FUN_00602170_shell *>((npc))->FUN_00602170()));
        while (parts && !parts->FUN_008256d0())
        {
            Part* part = *((::RaceAppearance::Part **)(new ((void *)(parts)) ::Vec3()));
            parts = ((::RaceAppearance::List *)(reinterpret_cast<::Callees *>((parts))->FUN_00726070()));
            apOutput->parts.FUN_005ae3d0(part);
            List* children = ((::RaceAppearance::List *)(reinterpret_cast<::FUN_00624700_shell *>((part))->FUN_00624700()));
            while (children && !children->FUN_008256d0())
            {
                Part* child = *((::RaceAppearance::Part **)(new ((void *)(children)) ::Vec3()));
                children = ((::RaceAppearance::List *)(reinterpret_cast<::Callees *>((children))->FUN_00726070()));
                apOutput->parts.FUN_005ae3d0(child);
            }
        }
    }
    apOutput->mouth = ((void *)(reinterpret_cast<::FUN_00613970_shell *>(this)->FUN_00613970(sex, 6)));
    apOutput->teeth = ((void *)(reinterpret_cast<::FUN_00613970_shell *>(this)->FUN_00613970(sex, 7)));
    if (!apOutput->eyes)
    {
        List* eyes = ((::RaceAppearance::List *)(reinterpret_cast<::FUN_00503650_shell *>(this)->FUN_00503650()));
        Part* pEyeSlot = 0;
        if (eyes && !eyes->FUN_008256d0())
        {
            pEyeSlot = *((::RaceAppearance::Part **)(new ((void *)(eyes)) ::Vec3()));
            apOutput->eyes = pEyeSlot;
        }
        else
        {
            eyes = ((::RaceAppearance::List *)&(reinterpret_cast<::NiAVObject *>(((*reinterpret_cast<::RaceAppearance::Data * *>(&::g_dataHandler))))->FUN_0043c490()));
            while (eyes)
            {
                pEyeSlot = *((::RaceAppearance::Part **)(new ((void *)(eyes)) ::Vec3()));
                if (pEyeSlot && !::FUN_00404dc0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pEyeSlot->name))->FUN_00408da0())), DAT_0104b8a0))
                {
                    apOutput->eyes = pEyeSlot;
                    break;
                }
                eyes = ((::RaceAppearance::List *)(reinterpret_cast<::Callees *>((eyes))->FUN_00726070()));
            }
        }
    }
}
}

namespace fnv_00613c50 {
// reconstruction of 0x00613c50
extern "C" char DAT_0104b860[];

class AutoMemHelper
{
  public:
    int m_ctx;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};

class NiFixedString
{
  public:
    int m_str;
    NiFixedString(const char*);
    ~NiFixedString();
};

class NiObjectNET
{
  public:
};

struct FUN_00613fb0_C
{
};

struct FUN_0084e3a0_shell
{
};

struct Q16
{
    int a, b, c, d;
};
struct FUN_005dd590_C
{
    Q16 q0, q1, q2, RunFourthVirtual, InvokeFifthVirtualFunction, q5, RunSeventhVirtualOperation, q7, q8, q9, q10, q11,
        q12, q13, q14;
    FUN_005dd590_C();
    ~FUN_005dd590_C();
};

struct FUN_00649680_C
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    char pad[0x1c0];
    FUN_00649680_C();
};

struct FUN_006628c0_C
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    char pad[0xec];
    FUN_006628c0_C();
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65(void*);
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69(bool);
    virtual void v70();
    virtual void v71(bool);
};


struct FUN_00613c50_C
{
    bool CreateFaceGenNodes(FUN_006628c0_C**, FUN_006628c0_C**, TESActorBase*, bool, bool, int);
};

// @fnv 0x00613c50
bool FUN_00613c50_C::CreateFaceGenNodes(FUN_006628c0_C** pA, FUN_006628c0_C** pB, TESActorBase* actor, bool fSwap,
                                        bool fFlag, int sex)
{
    AutoMemHelper mem3(0x37, true, DAT_0104b860, 0x623);
    *pA = 0;
    *pB = 0;
    FUN_00649680_C* biped2 = new FUN_00649680_C();
    *pA = new FUN_006628c0_C();
    ::AssignFixedString((char *)(((NiObjectNET*)*pA)), (int)&(const ::fnv_00613c50::NiFixedString &)(NiFixedString("BSFaceGenNiNodeBiped")), {});
    (*pA)->v65(biped2);
    (*pA)->v69(true);
    (*pA)->v71(true);
    *pB = new FUN_006628c0_C();
    ::AssignFixedString((char *)(((NiObjectNET*)*pB)), (int)&(const ::fnv_00613c50::NiFixedString &)(NiFixedString("BSFaceGenNiNodeSkinned")), {});
    (*pB)->v65(biped2);
    (*pB)->v69(false);
    (*pB)->v71(false);
    FUN_005dd590_C obj;
    reinterpret_cast<::RaceAppearance::Race *>(this)->BuildAppearance((::RaceAppearance::NPC *)(actor), (::RaceAppearance::Output *)(void *)(&obj), sex, false);
    ::fnv_00654720::BuildCharacterParts((::fnv_00654720::FG547Node **)(pA), (::fnv_00654720::FG547Node **)(pB), (::fnv_00654720::FG547Data *)(void *)(&obj), fFlag);
    if (fSwap)
    {
        ::fnv_00655fa0::ApplyFaceGenTextures((::fnv_00655fa0::NiAVObject *)(*pA), (::fnv_00655fa0::FaceGenData *)(void *)(&obj));
        ::fnv_00655fa0::ApplyFaceGenTextures((::fnv_00655fa0::NiAVObject *)(*pB), (::fnv_00655fa0::FaceGenData *)(void *)(&obj));
    }
    if (actor && reinterpret_cast<::FUN_0084e3a0_Class *>((((FUN_0084e3a0_shell*)actor)))->FUN_0084e3a0() == 7)
    {
        reinterpret_cast<::FUN_00613fb0_C *>((((FUN_00613fb0_C*)*pA)))->Set(true);
        reinterpret_cast<::FUN_00613fb0_C *>((((FUN_00613fb0_C*)*pB)))->Set(true);
    }
    return true;
}
}  // namespace fnv_00613c50

namespace fnv_006149b0 {
class NiTexture;
class NiSourceTexture;
class BSFaceGenModel;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* object = 0);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer<T>& operator=(T*);
    bool operator==(T*) const;
};
class TES
{
  public:
};
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
struct NiFixedString
{
    const char* value;
    NiFixedString(const char*);
    ~NiFixedString();
};
class BSFaceGenModel
{
  public:
};
class TextureAccess
{
  public:
};
class NpcCoords : public TESNPC
{
  public:
};
struct RaceTexture : TESRace
{
    bool ApplyBodyTexture(NiPointer<NiSourceTexture>&, NiPointer<NiTexture>&, TESNPC*, BIPED_OBJECT, bool);
};

// Creates or reuses a body texture for a biped part, building a FaceGen model and applying coordinates when needed.
// @fnv 0x006149b0
bool RaceTexture::ApplyBodyTexture(NiPointer<NiSourceTexture>& source, NiPointer<NiTexture>& texture, TESNPC* npc,
                                   BIPED_OBJECT part, bool force)
{
    NiPointer<BSFaceGenModel> model6;
    NiPointer<NiTexture> spC2;
    NiPointer<NiTexture> sp2;
    NiPointer<NiTexture> spB3;
    FaceGenMatrix<float> coords9[2][2];
    int sex4 = npc ? npc->GetSex() : 0;
    BSStringT<char> egt5;
    char path20[260];
    char buf26[260];
    char path3[260];
    BGSTextureModel* modelX;
    char modelPath_[260];
    source = 0;
    if (!force && (void*)npc != (void*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430())))
        texture = ((::fnv_006149b0::NiTexture *)(::GetFaceGenManagerValue()));
    if (!GetBipedObjectModelPath(npc, part, path20))
        return false;
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_006149b0::TES * *>(&::g_TES))))->FUN_004568c0(path20, (::TexPtr< ::NiSourceTexture> &)(source), false, false);
    if (!source)
        return false;
    if (!*(*reinterpret_cast<::fnv_006149b0::GlobalObject_0045cf30 *>(&::g_011cb99c)).Bool())
        return true;
    BuildBodyTexturePath(npc, buf26);
    if (reinterpret_cast<::fnv_006148f0::FUN_006148f0_shell *>(this)->BuildBodyModTexturePath(npc, buf26, path3) && !force)
        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_006149b0::TES * *>(&::g_TES))))->FUN_004568c0(path3, (::TexPtr< ::NiSourceTexture> &)((NiPointer<NiSourceTexture>&)texture), true, false);
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::fnv_006149b0::NiPointer< ::fnv_006149b0::NiTexture> &)(texture))->operator==((int)((NiTexture*)0)) || force)
    {
        if (!force && (void*)npc != (void*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430())))
            ::FUN_005b5e40();
        modelX = GetBodyTextureModel(npc->GetSex());
        if (!modelX)
            return false;
        if (!force && (void*)npc != (void*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430())))
        {
            ::FindTextureByPath(buf26, (::NiTexture **)(::fnv_006149b0::NiPointer< ::fnv_006149b0::NiTexture> *)(&texture));
            if (texture)
                return true;
        }
        ::TaskQueueInterface::CopyStringToBuffer(modelPath_, 260, "Meshes\\");
        strcat_s(modelPath_, 260, modelX->GetModelFilePath());
        model6 = ((::fnv_006149b0::BSFaceGenModel *)(::GetOrCreateFaceGenModel((char *)(0), (char *)(0), (char *)(0), (char *)(::GetModelEgtFilename((::BSStr *)(::BSStringT<char> *)(&egt5), modelPath_)), 1, -1, 0)));
        if (!model6)
            return false;
        if (npc)
        {
            ::FUN_00652af0((CoordArray (*)[2])(void *)(((void *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(npc->GetSex())))), (CoordArray (*)[2])(void *)(reinterpret_cast<::FUN_00601800_shell *>((((NpcCoords*)npc)))->FUN_00601800()), (CoordArray (*)[2])(coords9), false, 0.0f);
        }
        else
        {
            void* _fallback = ((void *)(reinterpret_cast<::S9fb0 *>(this)->FUN_005d9fb0(sex4)));
            if (!_fallback)
                _fallback = ((void *)(::BSFaceGenManager::GetFaceGenCoordinates()));
            ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(_fallback), (FaceGenCoordArray (*)[2])(coords9), false, false);
        }
        if (force)
            ::FUN_00a61fb0(path3);
        reinterpret_cast<::BSFaceGenModel *>((((BSFaceGenModel*)model6)))->ApplyTextureCoordinate((FaceGenCoordinates*)coords9, (::NiPointer< ::NiTexture> &)(texture), ((unsigned int)(::FUN_006151d0())));
        if (!texture)
            return false;
        reinterpret_cast<::FUN_00a5fba0_class *>((((TextureAccess*)(NiTexture*)texture)))->FUN_00a5fba0((const ::NiFixedString *)(const ::fnv_006149b0::NiFixedString *)(&NiFixedString(path3)));
        ::TextureFileEntrySetter::SetTexture((::NiTexture *)(::fnv_006149b0::NiTexture *)(texture), (const ::BSFileEntry *)(0));
    }
    return true;
}
}  // namespace fnv_006149b0

namespace RaceLoadDetail {
struct RaceLoadFile
{
    bool ReadChunkInt(void*);
};
struct RaceLoadComponents
{
    TESForm form;
    TESFullName fullName;
    TESDescription description;
    TESSpellList spells;
    TESReactionForm reactions;
};
struct RaceLoadReaction
{
    TESForm* pForm;
    int iFactionReaction;
    int m_iAdditionalFactionReaction;
};
using ::TESEyes;
class TESEyes : public TESForm
{
};
struct RaceLoadTarget : public TESRace
{
    bool FUN_00610cd0(TESFile*);
};

template <int N> struct RaceLoadEndianTag
{
};
extern "C" void* __cdecl _alloca(unsigned int);

struct RaceLoadShortChunk
{
};
struct RaceLoadReactionEndian
{
};
struct RaceLoadReactionList
{
};
class NiPoint3;
struct RaceLoadReactionAccess
{
};
struct RaceLoadTextureName
{
};
struct RaceLoadCoordArray
{
};
struct RaceLoadCoordScalar
{
};
struct RaceLoadCoordValue : public RaceLoadCoordScalar
{
    int a;
    int b;
};
struct RaceLoadCoordAccess
{
    RaceLoadCoordValue FUN_0060b370(int);
};
struct RaceLoadAttributes
{
};
struct RaceLoadSpellList
{
};
struct RaceLoadHairList
{
};
struct RaceLoadHairDefault
{
};
struct RaceLoadEyeList
{
    void FUN_00613910(TESEyes*);
};
struct RaceLoadDataReader
{
};
struct RaceLoadEndianState
{
};
struct RaceLoadDataEndian
{
};
struct RaceLoadTextureChunk
{
};
struct RaceLoadVirtuals
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56(TESFile*);
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* v76();
    virtual void v77(const char*);
};

// Reads a race record from apFile, parsing chunks into fields and returning false if the record type is not 0xc.
// @fnv 0x00610cd0
bool RaceLoadTarget::FUN_00610cd0(TESFile* apFile)
{
    int isex;
    int esymm;
    int chunkid;
    int ipart;
    bool boldSchool;
    int etype;
    bool bfacepart;

    isex = 0;
    ipart = 0;
    etype = -1;
    esymm = -1;
    bfacepart = false;
    boldSchool = true;
    if (reinterpret_cast<::FUN_00472660_shell *>((((RaceLoadFile*)apFile)))->FUN_00472660() != 0xc)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(apFile));
    while ((chunkid = reinterpret_cast<::FUN_004726b0_class *>((((RaceLoadFile*)apFile)))->FUN_004726b0()) != 0)
    {
        etype = esymm = -1;
        switch (chunkid)
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(pMessage), 0x200);
            ((RaceLoadVirtuals*)this)->v77(pMessage);
            break;
        }
        case 0x444e424f:
            ((RaceLoadVirtuals*)this)->v56(apFile);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, apFile);
            break;
        case 0x43534544:
            ::TESDescription::ReadDescriptionFromFile(this, apFile);
            break;
        case 0x4f4c5053: {
            unsigned int tempint = 0;
            ((RaceLoadFile*)apFile)->ReadChunkInt(&tempint);
            reinterpret_cast<::fnv_0048d290::FUN_0048d290_shell *>((((RaceLoadSpellList*)(&((RaceLoadComponents*)this)->spells))))->FUN_0048d290((::TESForm *)(tempint));
            break;
        }
        case 0x4d414e58: {
            RaceLoadReaction* pdata = new RaceLoadReaction;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(pdata), 0xc);
            if (reinterpret_cast<::TESFile *>((((RaceLoadEndianState*)apFile)))->IsEndianConversionRequired())
                reinterpret_cast<::Class005a6b10 *>((((RaceLoadReactionEndian*)pdata)))->FUN_005a6b10();
            reinterpret_cast<::Callees *>(&(((RaceLoadReactionList&)(*(const ::RaceLoadDetail::NiPoint3 *)(reinterpret_cast<::BaseProcess *>((((RaceLoadReactionAccess*)(&((RaceLoadComponents*)this)->reactions))))->GetCurrentProcessData())))))->FUN_00905820((void *)&(reinterpret_cast<char*&>(pdata)));
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((RaceLoadDataReader*)this)))->FUN_004861f0(apFile, &Data, 0x24);
            break;
        case 0x4d414e4f: {
            unsigned int itempint = 0;
            ((RaceLoadFile*)apFile)->ReadChunkInt(&itempint);
            m_pOlderRace = (TESRace*)itempint;
            break;
        }
        case 0x4d414e59: {
            unsigned int itempint = 0;
            ((RaceLoadFile*)apFile)->ReadChunkInt(&itempint);
            m_pYoungerRace = (TESRace*)itempint;
            break;
        }
        case 0x4b435456:
            if (reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C() == 4)
            {
                SetDefaultVoiceType(SEX_SEX_MALE, ::DAT_011cb298);
                SetDefaultVoiceType(SEX_SEX_FEMALE, ::DAT_011cb29c);
            }
            else if (reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C() == 8)
            {
                unsigned int ptempint[2];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(ptempint), 8);
                if (reinterpret_cast<::TESFile *>((((RaceLoadEndianState*)apFile)))->IsEndianConversionRequired())
                {
                    for (int i = 0; i < 2; i++)
                        ::FUN_00401080((int*)&ptempint[i]);
                }
                SetDefaultVoiceType(SEX_SEX_MALE, (BGSVoiceType*)ptempint[0]);
                SetDefaultVoiceType(SEX_SEX_FEMALE, (BGSVoiceType*)ptempint[1]);
            }
            break;
        case 0x4d414e43:
            if (reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C() == 1)
            {
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(void *)(&m_acDefaultHairColors[0]), 2);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(void *)(&m_acDefaultHairColors[1]), 2);
            }
            else if (reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C() == 2)
            {
                unsigned char ptempcolor[2];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(ptempcolor), 2);
                for (int isex = 0; isex < 2; isex++)
                    SetDefaultHairColor((SEX)isex, ptempcolor[isex]);
            }
            break;
        case 0x4d414e50:
            ((RaceLoadFile*)apFile)->ReadChunkInt(&m_fFaceGenMainClamp);
            break;
        case 0x4d414e55:
            ((RaceLoadFile*)apFile)->ReadChunkInt(&m_fFaceGenFaceClamp);
            break;
        case 0x4d414e44: {
            unsigned int ptempint[2];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(ptempint), 8);
            if (reinterpret_cast<::TESFile *>((((RaceLoadEndianState*)apFile)))->IsEndianConversionRequired())
            {
                for (int i = 0; i < 2; i++)
                    ::FUN_00401080((int*)&ptempint[i]);
            }
            reinterpret_cast<::FUN_00613890_Class *>((((RaceLoadHairDefault*)this)))->SetIndexedInt(0, ptempint[0]);
            reinterpret_cast<::FUN_00613890_Class *>((((RaceLoadHairDefault*)this)))->SetIndexedInt(1, ptempint[1]);
            break;
        }
        case 0x52545441: {
            unsigned int iattribSize = reinterpret_cast<::FUN_009d2510_shell *>((&m_kMaleAttributes))->FUN_009d2510();
            char* pdata = (char*)_alloca(iattribSize * 2);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(pdata), iattribSize * 2);
            reinterpret_cast<::FUN_00480130_shell *>((((RaceLoadAttributes*)&m_kMaleAttributes)))->FUN_00480130((unsigned char*)pdata);
            pdata = pdata + iattribSize;
            reinterpret_cast<::FUN_00480130_shell *>((((RaceLoadAttributes*)&m_kFemaleAttributes)))->FUN_00480130((unsigned char*)pdata);
            break;
        }
        case 0x53474746:
            if (etype == -1)
            {
                etype = 0;
                esymm = 0;
            }
        case 0x41474746:
            if (etype == -1)
            {
                etype = 0;
                esymm = 1;
            }
        case 0x53544746: {
            if (etype == -1)
            {
                etype = 1;
                esymm = 0;
            }
            float* pfloats = 0;
            unsigned int imemsize = reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C();
            int isize = imemsize >> 2;
            if (!isex || boldSchool)
                reinterpret_cast<::FR2MatrixVTCData *>((((RaceLoadCoordArray*)&m_kSecondFloatPairBySex[etype][esymm])))->SetDimensions(isize, true);
            reinterpret_cast<::FR2MatrixVTCData *>((((RaceLoadCoordArray*)&m_kFirstFloatPairBySex[etype][esymm])))->SetDimensions(isize, true);
            pfloats = (float*)_alloca(imemsize);
            ::FUN_00403d30(pfloats, 0, imemsize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(pfloats), imemsize);
            for (unsigned int i = 0; i < isize; i++)
            {
                if (reinterpret_cast<::TESFile *>((((RaceLoadEndianState*)apFile)))->IsEndianConversionRequired())
                    ::FUN_00401080((int*)&pfloats[i]);
                if (!isex || boldSchool)
                    reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::RaceLoadDetail::RaceLoadCoordScalar &)(((RaceLoadCoordAccess*)&m_kSecondFloatPairBySex[etype][esymm])->FUN_0060b370(i)))->FUN_00629ab0(0) =
                        pfloats[i];
                reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::RaceLoadDetail::RaceLoadCoordScalar &)(((RaceLoadCoordAccess*)&m_kFirstFloatPairBySex[etype][esymm])->FUN_0060b370(i)))->FUN_00629ab0(0) =
                    pfloats[i];
            }
            break;
        }
        case 0x4d414e46:
            isex = 1;
            break;
        case 0x4d414e4d:
            isex = 0;
            break;
        case 0x58444e49:
            ((RaceLoadFile*)apFile)->ReadChunkInt(&ipart);
            if (bfacepart)
            {
                int isub = (boldSchool && ipart > 1) ? 1 : 0;
                if (ipart < 8 && ipart - isub != 1)
                {
                    m_kBodyPartModels[isex][ipart - isub].Init();
                    m_kBodyPartModels[isex][ipart - isub].SetModelFilePath(::DAT_01199fe8[isex][ipart - isub]);
                    m_kBodyPartTextures[isex][ipart - isub].Init();
                    reinterpret_cast<::TESFullName *>((((RaceLoadTextureName*)&m_kBodyPartTextures[isex][ipart - isub])))->SetFullName(::DAT_0119a028[isex][ipart - isub]);
                }
            }
            else
            {
                if (ipart < 3)
                {
                    m_kHeadPartModels[isex][ipart].Init();
                    m_kHeadPartModels[isex][ipart].SetModelFilePath(::DAT_0119a080[isex][ipart]);
                    m_kHeadPartTextures[isex][ipart].Init();
                }
                if (ipart == 3)
                {
                    m_kFaceGenTextureModels[isex].Init();
                    m_kFaceGenTextureModels[isex].SetModelFilePath(::DAT_01199fbc[isex]);
                }
            }
            break;
        case 0x304d414e:
            bfacepart = true;
            break;
        case 0x314d414e:
            bfacepart = false;
            break;
        case 0x324d414e:
            boldSchool = false;
            break;
        case 0x4d414e53:
            if (reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C() >= 2)
                reinterpret_cast<::FUN_00472840_impl *>((((RaceLoadShortChunk*)apFile)))->ReadChunkData(&m_usRaceAttribute);
            break;
        case 0x4d414e48: {
            unsigned int* phairIDs = 0;
            unsigned int ichunksize = reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C();
            if (ichunksize % 4 != 0)
                break;
            unsigned int inumHair = ichunksize >> 2;
            if (inumHair != 0)
            {
                phairIDs = new unsigned int[inumHair];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(phairIDs), ichunksize);
                for (unsigned int i = 0; i < inumHair; i++)
                {
                    if (reinterpret_cast<::TESFile *>((((RaceLoadEndianState*)apFile)))->IsEndianConversionRequired())
                        ::FUN_00401080((int*)&phairIDs[i]);
                    ::ResolveFormID((unsigned int *)&(phairIDs[i]), apFile);
                    TESHair* phair = dynamic_cast<TESHair*>(::FUN_004839c0(phairIDs[i]));
                    if (phair)
                        reinterpret_cast<::FUN_00613810_shell *>((((RaceLoadHairList*)this)))->FUN_00613810((char *)(phair));
                    else
                        ::FUN_005b5e40();
                }
                delete[] phairIDs;
            }
            break;
        }
        case 0x4d414e45: {
            unsigned int* peyesIDs = 0;
            unsigned int ichunksize = reinterpret_cast<::FUN_00401660_Class *>((((RaceLoadFile*)apFile)))->GetField25C();
            if (ichunksize % 4 != 0)
                break;
            unsigned int inumEyes = ichunksize >> 2;
            if (inumEyes != 0)
            {
                peyesIDs = new unsigned int[inumEyes];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((RaceLoadFile*)apFile)))->FUN_00472890((char *)(peyesIDs), ichunksize);
                for (unsigned int i = 0; i < inumEyes; i++)
                {
                    if (reinterpret_cast<::TESFile *>((((RaceLoadEndianState*)apFile)))->IsEndianConversionRequired())
                        ::FUN_00401080((int*)&peyesIDs[i]);
                    ::ResolveFormID((unsigned int *)&(peyesIDs[i]), apFile);
                    TESEyes* peyes = dynamic_cast<TESEyes*>(::FUN_004839c0(peyesIDs[i]));
                    if (peyes)
                        ((RaceLoadEyeList*)this)->FUN_00613910(peyes);
                    else
                        ::FUN_005b5e40();
                }
                delete[] peyesIDs;
            }
            break;
        }
        default:
            if (bfacepart)
            {
                int isub = (boldSchool && ipart > 1) ? 1 : 0;
                if (ipart - isub < 8 && ipart - isub != 1)
                {
                    if (::IsChunkTypeIcon(chunkid))
                        ::TESTexture::ReadTextureData(&m_kBodyPartTextures[isex][ipart - isub], apFile);
                    else if (::FUN_00489280(chunkid))
                        ::TESModel::LoadModelData(&m_kBodyPartModels[isex][ipart - isub], apFile);
                }
            }
            else
            {
                if (ipart < 3)
                {
                    if (::IsChunkTypeIcon(chunkid))
                        ::TESTexture::ReadTextureData(&m_kHeadPartTextures[isex][ipart], apFile);
                    else if (::FUN_00489280(chunkid))
                        ::TESModel::LoadModelData(&m_kHeadPartModels[isex][ipart], apFile);
                }
                if (ipart == 3)
                    ::TESModel::LoadModelData(&m_kFaceGenTextureModels[isex], apFile);
            }
            break;
        }
        if (chunkid == 0x41544144 && reinterpret_cast<::TESFile *>((((RaceLoadEndianState*)apFile)))->IsEndianConversionRequired())
            reinterpret_cast<::FUN_00611db0_cls *>((((RaceLoadDataEndian*)&Data)))->FUN_00611db0();
        if (!reinterpret_cast<::TESFile *>((((RaceLoadFile*)apFile)))->NextChunk())
            break;
    }
    return true;
}

}

namespace TESRaceCleanup6104c0 {
class FUN_00483630_RaceFormCleanup : public TESForm
{
  public:
    virtual ~FUN_00483630_RaceFormCleanup();
};
class FUN_006104c0 : public FUN_00483630_RaceFormCleanup,
                     public TESFullName,
                     public TESDescription,
                     public TESSpellList,
                     public TESReactionForm
{
  public:
    RaceDefinitionData Data;
    TESAttributes m_kMaleAttributes, m_kFemaleAttributes;
    BSSimpleList<TESHair*> m_kHairList;
    TESHair* m_apDefaultHairStyles[2];
    unsigned char m_acDefaultHairColors[2];
    float m_fFaceGenMainClamp, m_fFaceGenFaceClamp;
    BSSimpleList<TESEyes*> m_kEyeList;
    TESModel m_kBodyPartModels[2][8];
    TESTexture m_kBodyPartTextures[2][8];
    TESTexture m_kHeadPartTextures[2][3];
    TESModel m_kHeadPartModels[2][3];
    BGSTextureModel m_kFaceGenTextureModels[2];
    FaceGenMatrix<float> m_kFirstFloatPairBySex[2][2], m_kSecondFloatPairBySex[2][2];
    unsigned short m_usRaceAttribute;
    BGSVoiceType* m_apDefaultVoiceTypes[2];
    TESRace* m_pOlderRace;
    TESRace* m_pYoungerRace;
    BSStringT<char> strEditorID;
    NiTPrimitiveArray<FaceGenUndo*> m_kFaceGenUndoList;
    virtual ~FUN_006104c0();
};
// Calls FUN_00610ac0 on this through a RaceCleanup pointer.
// @fnv 0x006104c0
FUN_006104c0::~FUN_006104c0()
{
    ((RaceCleanup*)this)->FUN_00610ac0();
}
}
