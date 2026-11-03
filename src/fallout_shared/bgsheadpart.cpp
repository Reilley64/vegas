// fallout_shared/bgsheadpart.cpp: BGSHeadPart, Deleter, HeadPartInit (13 functions)

#include <new>
#include <malloc.h>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00471d60_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005e6c60_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/MessageHandler.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/TESModel.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkLiquidAction.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004721d0__FUN_004721d0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/S00485110.h"
extern "C" void ref_008256d0();
extern "C" void ref_0063f7b0();
extern "C" void ref_00726c60();
extern "C" void ref_00485110();
extern "C" void ref_0048a7b0();
extern "C" void ref_005e7790();
extern "C" unsigned char data_011863b8[];
extern "C" unsigned char data_010465ec[];

enum ENUM_FORM_ID
{
    kBGSHeadPart = 9
};
class TESFile;
class TESFile;
class TESForm
{
  public:
    TESForm();
    virtual ~TESForm()
    {}

  private:
    unsigned char formData[20];
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
public:
    ::TESFile *GetFile(int);
};
class TESFullName
{
  public:
    TESFullName();
    virtual ~TESFullName()
    {}

  private:
    unsigned char nameData[8];
};
class TESForm;
class TESModelTextureSwap
{
  public:
    TESModelTextureSwap();
    virtual ~TESModelTextureSwap()
    {}

  private:
    unsigned char modelData[28];
public:
    void InitItem(::TESForm *);
};
class BGSHeadPart;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    ~BSSimpleList()
    {}

  private:
    T* item;
    BSSimpleList<T>* next;
};
class BGSHeadPart : public TESForm, public TESFullName, public TESModelTextureSwap
{
  public:
    BGSHeadPart();
    void ResetFormData();
    virtual void InitItem();
    virtual bool Load(TESFile*);
    unsigned char cFlags;
    unsigned char padding[3];
    BSSimpleList<BGSHeadPart*> m_kExtraParts;
public:
    void AddExtraPart(::BGSHeadPart *);
};

// @fnv 0x005e7440
void BGSHeadPart::ResetFormData()
{
    cFlags = 0;
}

// @fnv 0x005e72c0
BGSHeadPart::BGSHeadPart() : TESForm(), TESFullName(), TESModelTextureSwap(), m_kExtraParts()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(kBGSHeadPart)));
    ResetFormData();
}

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
struct FUN_005e7530_shell : public BGSHeadPart
{
    bool FUN_005e7530(TESFile*);
};

struct TESForm_vtable_helper : public BGSHeadPart
{
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54(TESFile*);
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void v72()
    {}
    virtual void v73()
    {}
    virtual void v74()
    {}
    virtual void v75(char*);
};

// @fnv 0x005e7530
bool FUN_005e7530_shell::FUN_005e7530(TESFile* apFile)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((apFile))->FUN_00472660() != 9)
        return false;

    ((void(*)(TESForm*, TESFile*))ref_00485110)(this, apFile);

    int chunkid;
    while ((chunkid = reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pMessage), 0x200);
            ((TESForm_vtable_helper*)this)->v75(pMessage);
            break;
        }
        case 0x444E424F:
            ((TESForm_vtable_helper*)this)->v54(apFile);
            break;
        case 0x4C4C5546:
            ((void(__cdecl*)(TESFullName*, TESFile*))((void (&)())::ReadFullName))(this, apFile);
            break;
        case 0x4C444F4D:
        case 0x44444F4D:
        case 0x44534F4D:
        case 0x54444F4D:
            ((void(__cdecl*)(TESModelTextureSwap*, TESFile*))((void (&)())::TESModel::LoadModelData))(this, apFile);
            break;
        case 0x53444F4D: {
            unsigned int isize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
            void* pdata = _alloca(isize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pdata), isize);
            ((void(*)(TESModelTextureSwap*, void*, unsigned int, unsigned int))ref_0048a7b0)(
                static_cast<TESModelTextureSwap *>(this), pdata, isize, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((apFile))->FUN_00403570());
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&cFlags), 1);
            break;
        case 0x4D414E48: {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            ((void(*)(BGSHeadPart*, unsigned int))ref_005e7790)(this, itempint);
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }

    return true;
}

struct FUN_00624700_shell : public BGSHeadPart
{
    void* FUN_00624700();
};

// @fnv 0x00624700
void* FUN_00624700_shell::FUN_00624700()
{
    return &m_kExtraParts;
}

struct List_005e7480
{
    bool FUN_008256d0();
};
struct S_00487010
{
};
struct S_0048a520
{
};
struct FUN_005e7480_t : public BGSHeadPart
{
    void InitializeHeadPart();
};
// @fnv 0x005e7480
void FUN_005e7480_t::InitializeHeadPart()
{
    BSSimpleList<BGSHeadPart*>* pCurrentElementNext;
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<S_00487010*>(static_cast<TESFullName *>(this))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<S_0048a520*>(static_cast<TESModelTextureSwap *>(this))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    FUN_004858f0(0x41544144, cFlags);
    pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(((::List_005e7480 *)(reinterpret_cast<::FUN_00624700_shell *>(this)->FUN_00624700())));
    while (pCurrentElementNext && !reinterpret_cast<List_005e7480*>(pCurrentElementNext)->FUN_008256d0())
    {
        unsigned int itempint;
        BGSHeadPart* ppart;
        ppart = ((::BGSHeadPart *)((void *)(reinterpret_cast<List_005e7480*>(pCurrentElementNext))));
        pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(((::List_005e7480 *)(reinterpret_cast<::Callees *>((reinterpret_cast<List_005e7480*>(pCurrentElementNext)))->FUN_00726070())));
        itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((static_cast<FUN_005e7480_t*>(ppart)))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e48, itempint);
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct List_009e03e0
{
    bool FUN_008256d0();
};
struct FUN_005e78f0_t : public BGSHeadPart
{
    void FUN_005e78f0(TESForm* apCopy);
};
// @fnv 0x005e78f0
void FUN_005e78f0_t::FUN_005e78f0(TESForm* apCopy)
{
    BSSimpleList<BGSHeadPart*>* pCurrentElementNext;
    BGSHeadPart* pSourcePart;
    pSourcePart = dynamic_cast<BGSHeadPart*>(apCopy);
    if (!pSourcePart)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apCopy);
    cFlags = pSourcePart->cFlags;
    pCurrentElementNext = 0;
    reinterpret_cast<::FileMatchList *>((((::List_009e03e0 *)(reinterpret_cast<::FUN_00624700_shell *>(this)->FUN_00624700()))))->RemoveAll();
    pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(((::List_009e03e0 *)(reinterpret_cast<::FUN_00624700_shell *>((static_cast<FUN_005e78f0_t*>(pSourcePart)))->FUN_00624700())));
    while (pCurrentElementNext && !reinterpret_cast<List_009e03e0*>(pCurrentElementNext)->FUN_008256d0())
    {
        BGSHeadPart* ppart = ((::BGSHeadPart *)((void *)(reinterpret_cast<List_009e03e0*>(pCurrentElementNext))));
        pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(((::List_009e03e0 *)(reinterpret_cast<::Callees *>((reinterpret_cast<List_009e03e0*>(pCurrentElementNext)))->FUN_00726070())));
        reinterpret_cast<::BGSHeadPart *>(this)->AddExtraPart(ppart);
    }
}

struct LH
{
    bool FUN_008256d0();
};
struct FUN_005e79a0_t : public BGSHeadPart
{
    bool FUN_005e79a0(TESForm* apCompare);
};
// @fnv 0x005e79a0
bool FUN_005e79a0_t::FUN_005e79a0(TESForm* apCompare)
{
    BGSHeadPart* pcomp;
    BSSimpleList<BGSHeadPart*>* pCurrentElementNext;
    pcomp = dynamic_cast<BGSHeadPart*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pcomp))
        return true;
    if ((char)pcomp->cFlags != (char)cFlags)
        return true;
    pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(((::LH *)(reinterpret_cast<::FUN_00624700_shell *>((static_cast<FUN_005e79a0_t*>(pcomp)))->FUN_00624700())));
    while (pCurrentElementNext && !reinterpret_cast<LH*>(pCurrentElementNext)->FUN_008256d0())
    {
        BGSHeadPart* ppart = ((::BGSHeadPart *)((void *)(reinterpret_cast<LH*>(pCurrentElementNext))));
        pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(((::LH *)(reinterpret_cast<::Callees *>((reinterpret_cast<LH*>(pCurrentElementNext)))->FUN_00726070())));
        if (!reinterpret_cast<::RefList *>((void *)(((::LH *)(reinterpret_cast<::FUN_00624700_shell *>(this)->FUN_00624700()))))->FUN_005f65d0((void **)&(ppart)))
            return true;
    }
    return false;
}

struct DtorCaller
{
    void FUN_005e73a0();
};
struct Deleter
{
    void* Destroy(unsigned int);
};
struct Base5a
{
    virtual ~Base5a();
    unsigned char formData[20];
};
struct FUN_00591300
{
    virtual ~FUN_00591300();
    unsigned char nameData[8];
};
struct ListX
{
    ~ListX();
    void* item;
    ListX* next;
};
struct FUN_005e73a0 : public Base5a, public FUN_00591300, public TESModelTextureSwap
{
    ~FUN_005e73a0();
    void FUN_005e7460();
    unsigned char cFlags;
    unsigned char padding[3];
    ListX m_kExtraParts;
};
// Calls FUN_005e73a0 on this, frees this when flags has bit 1 set, and returns this.
// @fnv 0x005e7370
void* Deleter::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_005e73a0 *>((((DtorCaller*)this)))->FUN_005e73a0::~FUN_005e73a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x005e73a0
FUN_005e73a0::~FUN_005e73a0()
{
    FUN_005e7460();
}

// FUN_005e6600: real destructor (, no params) of a class with:
//   - a polymorphic base at offset 0 (total size 8, its dtor at 0x5e6470)
//   - a member object at offset 8 whose dtor is 0x5aa1a0
//   - a destructor body calling this->FUN_005e6c60(0)

struct FUN_005e6470
{
    virtual ~FUN_005e6470();
    int unk04;
};

struct FUN_005aa1a0
{
    ~FUN_005aa1a0();
};

struct FUN_005e6600 : FUN_005e6470
{
    FUN_005aa1a0 unk08;
    ~FUN_005e6600();
};

// Destructor that calls FUN_005e6c60 with 0 on this object.
// @fnv 0x005e6600
FUN_005e6600::~FUN_005e6600()
{
    reinterpret_cast<::FUN_005e6c60_shell *>((this))->FUN_005e6c60((const char *)(0));
}

// FUN_005e7a60 : thiscall member returning a flag bit of the head-part data.
class FUN_005e7a60_cls
{
  public:
    unsigned char FUN_005e7a60();

  private:
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    char m_cActionFlags;  // +0x44
};

// @fnv 0x005e7a60
unsigned char FUN_005e7a60_cls::FUN_005e7a60()
{
    return (m_cActionFlags & 1) != 0;
}

struct HeadPartListOperations
{
};

// @fnv 0x005e7460
void FUN_005e73a0::FUN_005e7460()
{
    reinterpret_cast<::FileMatchList *>((reinterpret_cast<HeadPartListOperations*>(reinterpret_cast<FUN_00624700_shell*>(this)->FUN_00624700())))->RemoveAll();
}

struct HeadPartList
{
    bool IsEmpty();
    void RemoveHead();
    void SetItem(BGSHeadPart* const&);
};
struct TexSwapStub : public TESModelTextureSwap
{
};
struct HeadPartInit : public TESForm, public TESFullName, public TexSwapStub
{
    virtual void pad01()
    {}
    virtual void pad02()
    {}
    virtual void pad03()
    {}
    virtual void pad04()
    {}
    virtual void pad05()
    {}
    virtual void pad06()
    {}
    virtual void pad07()
    {}
    virtual void pad08()
    {}
    virtual void pad09()
    {}
    virtual void pad10()
    {}
    virtual void pad11()
    {}
    virtual void pad12()
    {}
    virtual void pad13()
    {}
    virtual void pad14()
    {}
    virtual void pad15()
    {}
    virtual void pad16()
    {}
    virtual void pad17()
    {}
    virtual void pad18()
    {}
    virtual void pad19()
    {}
    virtual void pad20()
    {}
    virtual void pad21()
    {}
    virtual void pad22()
    {}
    virtual void pad23()
    {}
    virtual void pad24()
    {}
    virtual void pad25()
    {}
    virtual void pad26()
    {}
    virtual void pad27()
    {}
    virtual void pad28()
    {}
    virtual void pad29()
    {}
    virtual void pad30()
    {}
    virtual void pad31()
    {}
    virtual void pad32()
    {}
    virtual void pad33()
    {}
    virtual void pad34()
    {}
    virtual void pad35()
    {}
    virtual void pad36()
    {}
    virtual void pad37()
    {}
    virtual void pad38()
    {}
    virtual void pad39()
    {}
    virtual void pad40()
    {}
    virtual void pad41()
    {}
    virtual void pad42()
    {}
    virtual void pad43()
    {}
    virtual void pad44()
    {}
    virtual void pad45()
    {}
    virtual void pad46()
    {}
    virtual void pad47()
    {}
    virtual void pad48()
    {}
    virtual void pad49()
    {}
    virtual void pad50()
    {}
    virtual void pad51()
    {}
    virtual void pad52()
    {}
    virtual void pad53()
    {}
    virtual void pad54()
    {}
    virtual void pad55()
    {}
    virtual void pad56()
    {}
    virtual void pad57()
    {}
    virtual void pad58()
    {}
    virtual void pad59()
    {}
    virtual void pad60()
    {}
    virtual void pad61()
    {}
    virtual void pad62()
    {}
    virtual void pad63()
    {}
    virtual void pad64()
    {}
    virtual void pad65()
    {}
    virtual void pad66()
    {}
    virtual void pad67()
    {}
    virtual void pad68()
    {}
    virtual void pad69()
    {}
    virtual void pad70()
    {}
    virtual void pad71()
    {}
    virtual void pad72()
    {}
    virtual void pad73()
    {}
    virtual void pad74()
    {}
    virtual void pad75()
    {}
    virtual const char* GetEditorID();
    TESFile* GetFile(int);
    unsigned char cFlags;
    unsigned char ucPad31;
    unsigned char ucPad32;
    unsigned char ucPad33;
    void* pExtraPartsItem;
    void* pExtraPartsNext;
    void FUN_005e77b0();
};

// @fnv 0x005e77b0
void HeadPartInit::FUN_005e77b0()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    reinterpret_cast<::TESModelTextureSwap *>(this)->InitItem(this);
    HeadPartList* pIter = ((::HeadPartList *)(reinterpret_cast<::FUN_00624700_shell *>(this)->FUN_00624700()));
    HeadPartList* pPrev = 0;
    while (pIter && !pIter->IsEmpty())
    {
        unsigned int auiFormId = (unsigned int)(std::uintptr_t)((::BGSHeadPart *)((void *)(pIter)));
        ::ResolveFormID(&auiFormId, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
        BGSHeadPart* m_pModel = dynamic_cast<BGSHeadPart*>(::FUN_004839c0(auiFormId));
        if (!m_pModel)
        {
            ::FUN_005b5e40();
            if (pPrev)
            {
                reinterpret_cast<::ItemChangeListNode *>((pPrev))->FUN_00905330((::InventoryStackRecord *const &)((const ::BGSHeadPart *const &)((BGSHeadPart*)auiFormId)));
                pIter = ((::HeadPartList *)(reinterpret_cast<::Callees *>((pPrev))->FUN_00726070()));
            }
            else
            {
                pIter->RemoveHead();
            }
        }
        else
        {
            pIter->SetItem(m_pModel);
            pPrev = pIter;
            pIter = ((::HeadPartList *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
    }
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
}

extern "C" void ref_00ec43fb();

extern "C" void ref_00ec5ec0();

extern "C" void ref_00ec408c();

// sub ecx,0x24; jmp target == MSVC adjustor thunk: Derived overrides a virtual that both of its
// bases declare, so the second base's vtable gets a thunk that moves `this` back by the size of
// the first base (vptr + 8 ints = 0x24).
struct PrimaryBase
{
    virtual void FUN_005e7a80();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct SecondaryBase
{
    virtual void FUN_005e7a80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005e7a80
    virtual void FUN_005e7a80();
};

Derived::Derived()
{}
