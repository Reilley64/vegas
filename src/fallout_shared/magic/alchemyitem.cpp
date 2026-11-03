// fallout_shared/magic/alchemyitem.cpp: AlchemyItem, AlchemySave, AlchemyItemMagic (26 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00874460_cls.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/TESModel.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESTexture.h"
#include "fnv/decl/fnv_00406340__EffectItemList.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011ca000.h"
#include "alchemyitem_decls.h"

// @fnv 0x00402ea0
void AlchemyItem::ResetFormData()
{
    unk0B8 = -1;
    unk0BC = 0;
    unk0C0 = 0;
    unk0C4 = 0.0f;
    unk0C8 = 0;
    reinterpret_cast<::TESForm *>((((IngredientItem*)this)))->ClearData();
}

// @fnv 0x004030f0
void AlchemyItem::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(((TESFormInitFlag*)this)))->GetInitialized())
        return;

    ((TESScriptableForm*)((char*)this + 0x88))->InitItem((TESForm*)this);
    ((BGSDestructibleObjectForm*)((char*)this + 0xA4))->InitItem((TESForm*)this);
    ((TESModelTextureSwap*)((char*)this + 0x4C))->InitItem((TESForm*)this);
    ((MagicItemObject*)this)->MagicItemObject::InitItem();
    ((BGSPickupPutdownSounds*)((char*)this + 0xAC))->InitItem((TESForm*)this);

    unsigned int formID = (unsigned int)FUN_004030b0();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), ((TESForm*)this)->GetFile(-1));
        reinterpret_cast<::FUN_00874460_cls *>(this)->set((int)(dynamic_cast<SpellItem*>(::FUN_004839c0(formID))));
        if (!FUN_004030b0())
        {
            ::FUN_005b5e40();
        }
    }

    formID = reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), ((TESForm*)this)->GetFile(-1));
        SetSound(dynamic_cast<TESSound*>(::FUN_004839c0(formID)));
        if (!reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8())
        {
            ::FUN_005b5e40();
        }
    }
}

// @fnv 0x00402ef0
void AlchemyItem::ClearData()
{
    reinterpret_cast<::fnv_00406340::EffectItemList *>((((EffectItemList*)((char*)this + 0x3C))))->FUN_00406340();
    reinterpret_cast<::TESForm *>((((IngredientItem*)this)))->ClearData();
}

// @fnv 0x004030d0
void AlchemyItem::SetSound(TESSound* sound)
{
    unk0C8 = (int)sound;
}

// @fnv 0x004030b0
void* AlchemyItem::FUN_004030b0()
{
    return (void*)unk0C0;
}

struct FUN_004029d0_shell : public AlchemyItem
{
    bool FUN_004029d0(int);
};

// @fnv 0x004029d0
bool FUN_004029d0_shell::FUN_004029d0(int aiFlag)
{
    return (*((unsigned char*)this + 0xbc) & aiFlag) != 0;
}

extern int DAT_01011d68;

// @fnv 0x00402d30
int* FUN_00402d30(int* this_ptr)
{
    *this_ptr = (int)&DAT_01011d68;
    return this_ptr;
}

namespace fnv_00403570 {
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
struct FUN_00403570_shell : public TESFile
{
    unsigned short FUN_00403570();
};

// @fnv 0x00403570
unsigned short FUN_00403570_shell::FUN_00403570()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x254);
}
}  // namespace fnv_00403570

extern unsigned int _data_011c16bc;
struct TESBoundObject
{
    char pad[0x2c];
    TESBoundObject();
    ~TESBoundObject();
    virtual void v();
};
namespace nsx {
struct Prim
{
    virtual void v0();
    int a;
    int b;
};
struct Sec
{
    virtual void v1();
};
struct EffectItemList : public Prim, public Sec
{
    EffectItemList();
};
}
struct FUN_00402b40 : public TESBoundObject, public nsx::EffectItemList
{
    FUN_00402b40();
};
// Empty constructor for a class deriving from TESBoundObject and nsx::EffectItemList.
// @fnv 0x00402b40
FUN_00402b40::FUN_00402b40()
{}

namespace fnv_004029b0 {
struct FUN_004029d0_shell
{
    bool FUN_004029b0();
};

// @fnv 0x004029b0
bool FUN_004029d0_shell::FUN_004029b0()
{
    return !reinterpret_cast<::FUN_004029d0_shell *>(this)->FUN_004029d0(1);
}
}  // namespace fnv_004029b0

struct BaseFormComponent
{
    virtual void Free();
};


struct FUN_00402b10_shell : BaseFormComponent
{
    void* FreeAndMaybeDeallocate(unsigned int flags);
};

template <int N> struct EndianSizeTag
{
};


struct FUN_00403720_shell
{
    void SwapEndian();
};

// @fnv 0x00403720
void FUN_00403720_shell::SwapEndian()
{
    ::FUN_00401080((int*)this);
    ::FUN_00401080((int*)((char*)this + 8));
    ::FUN_00401080((int*)((char*)this + 12));
    ::FUN_00401080((int*)((char*)this + 16));
}

namespace fnv_00402a90 {
struct FUN_004029d0_shell
{
};
struct FUN_00405da0_shell
{
};
struct FUN_00402a90_shell
{
    bool FUN_00402a90();
};
// Returns true when the object at this-0x3c passes FUN_004029d0(2) and this object's FUN_00405da0 returns false.
// @fnv 0x00402a90
bool FUN_00402a90_shell::FUN_00402a90()
{
    return reinterpret_cast<::FUN_004029d0_shell *>((((FUN_004029d0_shell*)((char*)this - 0x3c))))->FUN_004029d0(2) && !reinterpret_cast<::EffectItemList *>((((FUN_00405da0_shell*)this)))->FUN_00405da0();
}
}  // namespace fnv_00402a90

namespace fnv_00402ae0 {
struct FUN_004029d0_shell
{
};

struct FUN_00402ae0_shell
{
    bool FUN_00402ae0();
};

// @fnv 0x00402ae0
bool FUN_00402ae0_shell::FUN_00402ae0()
{
    return reinterpret_cast<::FUN_004029d0_shell *>((((FUN_004029d0_shell*)((char*)this - 0x3c))))->FUN_004029d0(4);
}
}  // namespace fnv_00402ae0

namespace fnv_00402bc0 {
extern int _data_011c16bc;
struct FUN_0040a140
{
    ~FUN_0040a140();
};
struct FUN_0050e9f0
{
    char _pad[0x30];
    ~FUN_0050e9f0();
};
struct FUN_00402bc0 : FUN_0050e9f0
{
    FUN_0040a140 m;
    ~FUN_00402bc0();
};
// @fnv 0x00402bc0
FUN_00402bc0::~FUN_00402bc0()
{}
}  // namespace fnv_00402bc0

struct S00402c60
{
    void FUN_00402bc0();
    void* FUN_00402c60(unsigned int);
};
// Calls FUN_00402bc0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00402c60
void* S00402c60::FUN_00402c60(unsigned int flags)
{
    reinterpret_cast<::fnv_00402bc0::FUN_00402bc0 *>(this)->fnv_00402bc0::FUN_00402bc0::~FUN_00402bc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_0048a520
{
};
struct FUN_0048e370_obj
{
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct S_0048cca0
{
    void FUN_0048cca0(void);
};
struct S_00477f20
{
};
struct FUN_0047b560_holder
{
};
struct FUN_00479350_shell
{
    void FUN_00479350(void);
};
struct FUN_00485e00_shell
{
    void FUN_00485e00(void);
};

struct FUN_00402f10_shell
{
    void FUN_00402f10();
};

// @fnv 0x00402f10
void FUN_00402f10_shell::FUN_00402f10()
{
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)((char*)this + 0x1c))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)((char*)this + 0x3c))))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x48))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x58))->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>((((S_00477f20*)((char*)this + 0x74))))->FUN_00477f20();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>((((FUN_0047b560_holder*)((char*)this + 0x7c))))->LogFormIDs();
    ((FUN_00479350_shell*)((char*)this + 0x6c))->FUN_00479350();
    ((FUN_00485e00_shell*)((char*)this - 0x30))->FUN_00485e00();
}

namespace fnv_00403790 {
struct FUN_00403720_shell
{
};
struct FUN_00403790_shell
{
    void CallNestedAtOffsetB8();
};
// @fnv 0x00403790
void FUN_00403790_shell::CallNestedAtOffsetB8()
{
    reinterpret_cast<::FUN_00403720_shell *>((((FUN_00403720_shell*)((char*)this + 0xb8))))->SwapEndian();
}
}  // namespace fnv_00403790

class TESObjectSTAT;
struct H0050fb90
{
    int _FNV_GetFormType();
    bool FUN_0050fb90();
};
// Returns true if this object's form type is 0x20 and it matches one of the three TESObjectSTAT globals; otherwise false.
// @fnv 0x0050fb90
bool H0050fb90::FUN_0050fb90()
{
    if (!this)
        return false;
    if (_FNV_GetFormType() == 0x20 && (DAT_011ca238 == reinterpret_cast<TESObjectSTAT*>(this) ||
                                       DAT_011ca234 == reinterpret_cast<TESObjectSTAT*>(this) ||
                                       DAT_011ca23c == reinterpret_cast<TESObjectSTAT*>(this)))
        return true;
    return false;
}

struct TESFile;
extern "C" void* __cdecl _alloca(unsigned int);
struct FUN_00401660_t
{
};
struct FUN_00472890_t
{
};
struct FUN_00403570_t
{
};
struct FUN_004727f0_t
{
    bool ReadChunkInt(unsigned int*);
};
struct AlchBase00
{
    virtual void v0();
    char pad[0x2c];
};
struct AlchBase30
{
    virtual void FUN_00403280(TESFile*, int);
    char pad[0x18];
};
struct AlchTexSwap
{
    virtual void v0();
    char pad[0x1c];
};
struct AlchTexture
{
    virtual void v0();
    char pad[0x8];
};
struct AlchMsgIcon
{
    virtual void v0();
    char pad[0xc];
};
struct AlchScript
{
    virtual void v0();
    char pad[0x10];
};
struct AlchEquip
{
    virtual void v0();
    char pad[0x4];
};
struct AlchDestr
{
    virtual void v0();
    char pad[0x4];
};
struct AlchPickup
{
    virtual void v0();
    char pad[0x8];
};
struct FUN_00403280_t : AlchBase00,
                        AlchBase30,
                        AlchTexSwap,
                        AlchTexture,
                        AlchMsgIcon,
                        AlchScript,
                        AlchEquip,
                        AlchDestr,
                        AlchPickup
{
    void FUN_00403280(TESFile* apFile, int aiChunk);
};

// Dispatches on the chunk type and loads the matching subrecord (model, icon, script, equipment, pickup, destruction or data) from the file.
// @fnv 0x00403280
void FUN_00403280_t::FUN_00403280(TESFile* apFile, int aiChunk)
{
    switch (aiChunk)
    {
    case 0x4c444f4d:
    case 0x54444f4d:
    case 0x44444f4d:
    case 0x44534f4d:
        ::TESModel::LoadModelData((::TESModel *)(::AlchTexSwap *)(this), apFile);
        break;
    case 0x53444f4d: {
        unsigned int uiChunkSize = reinterpret_cast<::FUN_00401660_Class *>((((FUN_00401660_t*)apFile)))->GetField25C();
        char* pChunkData = (char*)_alloca(uiChunkSize);
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((FUN_00472890_t*)apFile)))->FUN_00472890((char *)(pChunkData), uiChunkSize);
        reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(pChunkData, uiChunkSize, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((FUN_00403570_t*)apFile)))->FUN_00403570());
        break;
    }
    case 0x4e4f4349:
        ::TESTexture::ReadTextureData((::TESTexture *)(::AlchTexture *)(this), apFile);
        break;
    case 0x4f43494d:
        ::FUN_0047a290((::TeleportableReference *)(::AlchMsgIcon *)(this), apFile);
        break;
    case 0x49524353: {
        unsigned int formID = 0;
        ((FUN_004727f0_t*)apFile)->ReadChunkInt(&formID);
        reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(formID));
        reinterpret_cast<::TESScriptableForm *>(this)->InitItem((::TESForm *)(::AlchBase00 *)(this));
        break;
    }
    case 0x54534544:
    case 0x44545344:
        ::FUN_004781e0((::BGSDestructibleObjectForm *)(::AlchDestr *)(this), apFile);
        break;
    case 0x50595445: {
        unsigned int formID = 0;
        ((FUN_004727f0_t*)apFile)->ReadChunkInt(&formID);
        reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(formID));
        break;
    }
    case 0x4d414e59: {
        unsigned int formID = 0;
        ((FUN_004727f0_t*)apFile)->ReadChunkInt(&formID);
        reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(formID));
        break;
    }
    case 0x4d414e5a: {
        unsigned int formID = 0;
        ((FUN_004727f0_t*)apFile)->ReadChunkInt(&formID);
        reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(formID));
        break;
    }
    case 0x41544144:
        reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(apFile, 0, 0);
        break;
    }
}

struct BGSListForm : TESForm
{
    bool IsInList(BGSListForm*&);
};
struct ScriptS
{
};
struct LH
{
    bool IsInList(int&);
};
struct FUN_004036d0_shell
{
    bool IsInWaterList();
};
// Looks up the form list "WaterLIST" and returns whether this object is contained in its header's list.
// @fnv 0x004036d0
bool FUN_004036d0_shell::IsInWaterList()
{
    BGSListForm* pWaterList = (BGSListForm*)::TESForm::LookupFormByEditorID("WaterLIST");
    if (pWaterList)
    {
        BGSListForm* pThis = (BGSListForm*)this;
        if (reinterpret_cast<::RefList *>((((LH*)((void *)(reinterpret_cast<::BGSCameraPath *>((((ScriptS*)pWaterList)))->GetConditions())))))->FUN_005f65d0((void **)&((int&)pThis)))
            return true;
    }
    return false;
}

struct MagicItemObjectBase
{
    MagicItemObjectBase();
    virtual ~MagicItemObjectBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
struct MagicItemFullName
{
    virtual void v0();
    int unk04;
    int unk08;
};
struct MagicItemEffects
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0C;
};
struct MagicItemBase : MagicItemObjectBase, MagicItemFullName, MagicItemEffects
{
    MagicItemBase();
    ~MagicItemBase();
};
struct ModelTexSwapC
{
    ModelTexSwapC();
    ~ModelTexSwapC();
    virtual void v0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct IconC
{
    IconC();
    ~IconC();
    virtual void v0();
    int unk04;
    int unk08;
};
struct MessageIconC
{
    MessageIconC();
    ~MessageIconC();
    virtual void v0();
    int unk04;
    int unk08;
    int unk0C;
};
struct ScriptableC
{
    ScriptableC();
    virtual void v0();
    int unk04;
    int unk08;
};
struct WeightC
{
    WeightC();
    ~WeightC();
    virtual void v0();
    int unk04;
};
struct EquipTypeC
{
    EquipTypeC();
    virtual void v0();
    int unk04;
};
struct DestructibleC
{
    DestructibleC();
    ~DestructibleC();
    virtual void v0();
    int unk04;
};
struct PickupC
{
    PickupC();
    ~PickupC();
    virtual void v0();
    int unk04;
    int unk08;
};

struct FUN_00402820 : MagicItemBase,
                      ModelTexSwapC,
                      IconC,
                      MessageIconC,
                      ScriptableC,
                      WeightC,
                      EquipTypeC,
                      DestructibleC,
                      PickupC
{
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    IconC icon;

    FUN_00402820();
    ~FUN_00402820();
};

// Initializes the object by setting its form type to 0x2f and calling InitData.
// @fnv 0x00402820
FUN_00402820::FUN_00402820()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x2f);
    reinterpret_cast<::AlchemyItem *>(this)->ResetFormData();
}

struct Part0
{
    virtual void v();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct Part30
{
    virtual void v();
    int unk04;
    int unk08;
};
struct Part3c
{
    virtual void v();
    int unk04;
    int unk08;
    int unk0c;
};
struct BaseMagic : Part0, Part30, Part3c
{
    ~BaseMagic();
};
struct ModelPart
{
    virtual void v();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ~ModelPart();
};
struct IconPart
{
    virtual void v();
    int unk04;
    int unk08;
    ~IconPart();
};
struct MessagePart
{
    virtual void v();
    int unk04;
    int unk08;
    int unk0c;
    ~MessagePart();
};
struct ScriptPart
{
    virtual void v();
    int unk04;
    int unk08;
};
struct EquipPart
{
    virtual void v();
    int unk04;
    ~EquipPart();
};
struct DestructPart
{
    virtual void v();
    int unk04;
};
struct RepairPart
{
    virtual void v();
    int unk04;
    ~RepairPart();
};
struct PickupPart
{
    virtual void v();
    int unk04;
    int unk08;
    ~PickupPart();
};
struct FUN_00402d50 : BaseMagic,
                      ModelPart,
                      IconPart,
                      MessagePart,
                      ScriptPart,
                      EquipPart,
                      DestructPart,
                      RepairPart,
                      PickupPart
{
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    IconPart icon;
    ~FUN_00402d50();
};
// Calls BaseFormComponent::Free, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00402b10
void* FUN_00402b10_shell::FreeAndMaybeDeallocate(unsigned int flags)
{
    reinterpret_cast<::FUN_00402d50 *>(this)->FUN_00402d50::~FUN_00402d50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00402d50
FUN_00402d50::~FUN_00402d50()
{
    reinterpret_cast<::AlchemyItem *>(this)->ClearData();
}

struct FormStub
{
};
struct AlchData
{
};

struct AlchPrimBase
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
struct AlchSaveBase
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual unsigned int s24();
    virtual void FUN_00402f90();
};
struct AlchemySave : AlchPrimBase, AlchSaveBase
{
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    AlchData data;

    virtual void FUN_00402f90();
};

// @fnv 0x00402f90
void AlchemySave::FUN_00402f90()
{
    FormStub* oldItem = ((::FormStub *)(reinterpret_cast<::AlchemyItem *>(this)->FUN_004030b0()));
    reinterpret_cast<::FUN_00874460_cls *>(this)->set((int)(((::FormStub *)(reinterpret_cast<::AlchemyItem *>(this)->FUN_004030b0())) ? (FormStub*)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::FormStub *)(reinterpret_cast<::AlchemyItem *>(this)->FUN_004030b0()))))->FUN_0084e3a0())) : 0));
    FormStub* pOldSound = ((::FormStub *)(reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8()));
    reinterpret_cast<::AlchemyItem *>(this)->SetSound((::TESSound *)(::FormStub *)(((::FormStub *)(reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8())) ? (FormStub*)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::FormStub *)(reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8()))))->FUN_0084e3a0())) : 0));
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00403720_shell *>(&(data))->SwapEndian();
    ::AppendChunk(s24(), &data, 0x14);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00403720_shell *>(&(data))->SwapEndian();
    reinterpret_cast<::FUN_00874460_cls *>(this)->set((int)(oldItem));
    reinterpret_cast<::AlchemyItem *>(this)->SetSound((::TESSound *)(pOldSound));
}

extern int DAT_011830cc;
void* __cdecl FUN_00ec43fb(int, int, int*, int*, int);
int __cdecl FUN_00ec4835(void*, unsigned int, int);

struct FUN_00403590_sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual unsigned int v28();
};

class FUN_00403590_cls
{
  public:
    bool FUN_00403590(int aParam);
};

// @fnv 0x00403590
bool FUN_00403590_cls::FUN_00403590(int aParam)
{
    char* pObject = (char*)FUN_00ec43fb(aParam, 0, &DAT_01183140, &DAT_011830cc, 0);
    if (pObject == 0)
    {
        return true;
    }
    if (FUN_00ec4835((char*)this + 0x88, ((FUN_00403590_sub*)(pObject + 0x30))->v28(), 0x14) != 0)
    {
        return true;
    }
    return false;
}


class MagicItem
{
  public:
    virtual ~MagicItem();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00C();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01C();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void* GetData();
    virtual void FUN_00403600(MagicItem* source);
};

class AlchemyItemBound
{
  public:
    virtual ~AlchemyItemBound();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

class AlchemyItemMagic : public AlchemyItemBound, public MagicItem
{
  public:
    virtual void FUN_00403600(MagicItem* source);
};

// Copies 0x14 bytes of data from the source MagicItem into this AlchemyItemMagic after casting source to AlchemyItem.
// @fnv 0x00403600
void AlchemyItemMagic::FUN_00403600(MagicItem* source)
{
    AlchemyItem* item = dynamic_cast<AlchemyItem*>(source);
    if (item == 0)
    {
        return;
    }
    ::__memcpy(GetData(), ((AlchemyItemMagic*)item)->GetData(), 0x14);
}
