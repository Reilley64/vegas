// fallout/misc/saveload/bgsloadformbuffer_decls.h: declares SaveLoadFile, PackedFormID, BGSSaveLoadFormInfo, FormChangeMask, FormLoadContext and more
#ifndef FNV_BGSLOADFORMBUFFER_DECLS_H
#define FNV_BGSLOADFORMBUFFER_DECLS_H

#include "fnv/decl/C42CE30.h"
#include "fnv/decl/FUN_00846490_t.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00483000.h"
#include "layout_support.h"
#include "TESForm.h"

class SaveLoadFile
{
  public:
public:
    unsigned int Read(void *, unsigned int);
};


#pragma pack(push, 1)

class PackedFormID
{
  public:
    PackedFormID();
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int numericID);
    bool IsZero();

    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};

class BGSSaveLoadFormInfo
{
  public:
    BGSSaveLoadFormInfo();
    ENUM_FORM_ID GetFormType();
    void SetFormType(ENUM_FORM_ID formType);
    void InitSaveGameFormTypes();

    unsigned char cData;
};

class FormChangeMask
{
  public:
    FormChangeMask();
    bool CheckFlagsExact(int flags);
    bool CheckFlagsExclusive(int flags);
    void SetFlags(int flags);
    void AddFlags(int flags);
    void RemoveFlags(int flags);
    FormChangeMask GetDifference(int flags);
    operator int();
    const char* GetFullFlagName(int flags, unsigned int, bool);
    const char* GetShortFlagName(int flags, unsigned int);
    bool IsFlagSetForType(int, unsigned int, unsigned int);
    bool HasFormChanged(TESForm* form);
    FormChangeMask CombineFlags(FormChangeMask, FormChangeMask, unsigned int, bool);

  protected:
    int iFlags;
};

class FormLoadContext
{
  public:
    FormLoadContext();
    void Endian();

    PackedFormID m_kFormIDIndex;
    FormChangeMask m_pDeathItem;
    BGSSaveLoadFormInfo FormInfo;
    unsigned char cVersion;
};

#pragma pack(pop)

class BGSLoadGameBuffer
{
  public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    void ResetReadPosition();
    void SetBuffer(char* buffer, unsigned int size, unsigned int position);
    char* GetCurrentBufferPointer();
    virtual unsigned char GetVersion();
    void AdvanceBuffer(unsigned int bytes);
    void ReadElementData(void* data, unsigned int size, unsigned int flags);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();

  protected:
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
    BGSLoadFormBuffer();
    bool IsFlag2Set();
    int LoadHeader(SaveLoadFile* file);
    int ReadFormData(SaveLoadFile* file);
    void SkipData(SaveLoadFile* file, unsigned int size);
    unsigned int GetFormID();
    void SetForm(TESForm* form);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    ENUM_FORM_ID GetFormType();
    void SetChangeFlags(FormChangeMask changeFlags);
    void SetOldChangeFlags(FormChangeMask oldChangeFlags);
    void SetVersion(unsigned char version);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool skipForm);
    bool GetSkipForm();
    void SetFormPending(bool formPending);
    bool GetFormPending();
    void SetRevertOnly(bool revertOnly);
    bool GetRevertOnly();
    void SetReconstructedForm(bool reconstructedForm);
    bool GetReconstructedForm();
    void SetCellChanged(bool cellChanged);
    bool GetCellChanged();
    ~BGSLoadFormBuffer();

  protected:
    unsigned int iFormID;
    FormLoadContext Header;
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    FormChangeMask m_cReservedBytes;
};

#endif
