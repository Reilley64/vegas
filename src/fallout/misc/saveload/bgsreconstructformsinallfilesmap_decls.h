#ifndef FNV_BGSRECONSTRUCTFORMSINALLFILESMAP_DECLS_H
#define FNV_BGSRECONSTRUCTFORMSINALLFILESMAP_DECLS_H


#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_00550890_shell.h"
#include "fnv/decl/FUN_00845610_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
class TESBoundObject;
class BGSReconstructFormsInFileMap;
class FormChangeMap;
struct ChangedFormRecord;

class BGSSaveLoadChangesMapBase
{
  public:
    virtual ~BGSSaveLoadChangesMapBase();
};

class BGSSaveLoadChangesMap : public BGSSaveLoadChangesMapBase
{
  public:
    virtual ~BGSSaveLoadChangesMap();
};

class BGSReconstructFormsInAllFilesMapBase
{
  public:
    BGSReconstructFormsInAllFilesMapBase(unsigned int capacity);
    virtual ~BGSReconstructFormsInAllFilesMapBase();
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
};

struct TESRecordHeader;
class TESFile
{
  public:
    TESFile* GetParentTESFile();
public:
    bool IsEndianConversionRequired();
public:
    ::TESRecordHeader *GetRecordHeader();
public:
    unsigned int GetOffset();
public:
    bool GetOptimizedFile();
public:
    bool NextChunk();
public:
    bool IsGroupOpen();
};

class TESFile;
class TESForm
{
  public:
#define FNV_VIRTUAL_SLOT(n) virtual void vfn_##n();
    FNV_VIRTUAL_SLOT(00)
    FNV_VIRTUAL_SLOT(01)
    FNV_VIRTUAL_SLOT(02) FNV_VIRTUAL_SLOT(03) FNV_VIRTUAL_SLOT(04) FNV_VIRTUAL_SLOT(05) FNV_VIRTUAL_SLOT(06)
        FNV_VIRTUAL_SLOT(07) FNV_VIRTUAL_SLOT(08) FNV_VIRTUAL_SLOT(09) FNV_VIRTUAL_SLOT(10) FNV_VIRTUAL_SLOT(11)
            FNV_VIRTUAL_SLOT(12) FNV_VIRTUAL_SLOT(13) FNV_VIRTUAL_SLOT(14) FNV_VIRTUAL_SLOT(15) FNV_VIRTUAL_SLOT(16)
                FNV_VIRTUAL_SLOT(17) FNV_VIRTUAL_SLOT(18) FNV_VIRTUAL_SLOT(19) FNV_VIRTUAL_SLOT(20) FNV_VIRTUAL_SLOT(21)
                    FNV_VIRTUAL_SLOT(22) FNV_VIRTUAL_SLOT(23) FNV_VIRTUAL_SLOT(24) FNV_VIRTUAL_SLOT(25)
                        FNV_VIRTUAL_SLOT(26) FNV_VIRTUAL_SLOT(27) FNV_VIRTUAL_SLOT(28) FNV_VIRTUAL_SLOT(29)
                            FNV_VIRTUAL_SLOT(30) FNV_VIRTUAL_SLOT(31) FNV_VIRTUAL_SLOT(32) FNV_VIRTUAL_SLOT(33)
#undef FNV_VIRTUAL_SLOT
                                virtual void InitItem();
#define FNV_VIRTUAL_SLOT(n) virtual void vfn_##n();
    FNV_VIRTUAL_SLOT(35)
    FNV_VIRTUAL_SLOT(36)
    FNV_VIRTUAL_SLOT(37) FNV_VIRTUAL_SLOT(38) FNV_VIRTUAL_SLOT(39) FNV_VIRTUAL_SLOT(40) FNV_VIRTUAL_SLOT(41)
        FNV_VIRTUAL_SLOT(42) FNV_VIRTUAL_SLOT(43) FNV_VIRTUAL_SLOT(44) FNV_VIRTUAL_SLOT(45) FNV_VIRTUAL_SLOT(46)
            FNV_VIRTUAL_SLOT(47) FNV_VIRTUAL_SLOT(48) FNV_VIRTUAL_SLOT(49) FNV_VIRTUAL_SLOT(50) FNV_VIRTUAL_SLOT(51)
                FNV_VIRTUAL_SLOT(52) FNV_VIRTUAL_SLOT(53) FNV_VIRTUAL_SLOT(54) FNV_VIRTUAL_SLOT(55) FNV_VIRTUAL_SLOT(56)
                    FNV_VIRTUAL_SLOT(57) FNV_VIRTUAL_SLOT(58) FNV_VIRTUAL_SLOT(59)
#undef FNV_VIRTUAL_SLOT
                        virtual bool GetIsReference() const;
public:
    bool GetInitialized() const;
public:
    bool GetDisabled() const;
public:
    ::TESFile *GetFile(int);
public:
    void SetCollisionDisabled(bool);
};

class TESObjectREFR
{
  public:
public:
    float GetScale();
};

struct ChangedFormRecord
{
    TESForm* pForm;
    unsigned int iFlags;
};

template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    virtual ~BSSimpleArray();
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};

class FormChangeMap
{
  public:
    BSSimpleArray<ChangedFormRecord, 1024> m_kOrdinaryFormChanges;
    BSSimpleArray<ChangedFormRecord, 1024> m_kSpecialFormChanges;
    FormChangeMap();
    ~FormChangeMap();
    ChangedFormRecord* FUN_008432e0(unsigned int index);
};

class BGSReconstructFormsInFileMap
{
  public:
    virtual ~BGSReconstructFormsInFileMap();
};

template <class T_Key, class T_Data> class NiTPointerMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*& position, T_Key& key, T_Data& data);
    void RemoveAll();
};

class BGSReconstructFormsInAllFilesMap : public BGSReconstructFormsInAllFilesMapBase
{
  public:
    FormChangeMap m_kFormChangeMap;
    unsigned int iCount;
    void* GetFirstPos();
    void GetNext(void*& position, TESFile*& file, BGSReconstructFormsInFileMap*& map);
    void Clear();
    void BuildMap();
    void AddFormFlagEntry(ChangedFormRecord* data);
    BGSReconstructFormsInAllFilesMap();
    virtual ~BGSReconstructFormsInAllFilesMap();
};

struct BGSSaveLoadGame
{
  public:
};

class TESFile;
class TESForm;
class TESDataHandler
{
  public:
public:
    ::TESFile *GetCompiledFileByIndex(int);
public:
    bool ConstructObject(::TESFile *, bool, ::TESForm *, bool);
};

class TESFormInitFlag
{
  public:
};


#endif
