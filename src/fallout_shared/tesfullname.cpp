
// src/fallout_shared/tesfullname.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesfullname.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/B408A80String.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "TESFullName.h"

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
struct TESDescription : public BaseFormComponent
{
    virtual char* GetDescription(TESForm*, int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    static void LoadDescriptionAtOffset(TESDescription*, int);
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetDescriptionLength(TESForm*);
    unsigned int GetDescriptionLength();
    static char* GetDescription(TESForm*);
    unsigned long GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned long);
    void LoadDescriptionForForm(TESForm*, int);
    void UnLoadDescription();
    void SetDescription(char*);
    unsigned long m_uiDescriptionFileOffset;
};
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
struct FUN_004870f0_shell : public TESFullName
{
    void CopyFullNameFrom(BaseFormComponent*);
};

struct BSStr
{
};
struct FNStub
{
};

// Casts apCopyFC to TESFullName and, if successful, copies its full name into this object's BSStr at offset 4.
// @fnv 0x004870f0
void FUN_004870f0_shell::CopyFullNameFrom(BaseFormComponent* apCopyFC)
{
    TESFullName* pCopy = dynamic_cast<TESFullName*>(apCopyFC);
    if (!pCopy)
        return;
    reinterpret_cast<::TextString *>((((BSStr*)((char*)this + 4))))->FUN_004037f0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)pCopy)))->FUN_00408da0())), 0);
}

struct TESForm
{
    virtual ~TESForm();
};
// Casts apObj to TESFullName and returns its full name, or an empty string if the cast fails.
// @fnv 0x00482720
const char* FUN_00482720(TESForm* apObj)
{
    TESFullName* pFullName = dynamic_cast<TESFullName*>(apObj);
    return pFullName ? ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)pFullName)))->FUN_00408da0())) : "";
}

class StringShell487 : public BSStringT<char>
{
  public:
};

class FullNameShell487 : public TESFullName
{
  public:
    unsigned int GetLength() const;

    bool CompareFullName(BaseFormComponent* pkComponent);
};

// Compares this full name with another TESFullName component: returns true if lengths differ or names differ case-insensitively, false if equal.
// @fnv 0x00487140
bool FullNameShell487::CompareFullName(BaseFormComponent* pkComponent)
{
    TESFullName* pkOther = dynamic_cast<TESFullName*>(pkComponent);
    if (!pkOther)
        return true;
    if (GetLength() || static_cast<FullNameShell487*>(pkOther)->GetLength())
    {
        if (GetLength() != static_cast<FullNameShell487*>(pkOther)->GetLength())
            return true;
        else if (reinterpret_cast<::B408A80String *>((void *)(static_cast<StringShell487*>(&m_kName)))->FUN_00408a80(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(static_cast<FullNameShell487*>(pkOther)))->FUN_00408da0())),
                                                                false))
            return true;
    }
    return false;
}

struct TESFullNameSetter : public TESFullName
{
};

// Reads the FULL chunk from apFile and sets the name on apName via TESFullNameSetter::SetName.
// @fnv 0x00487050
void ReadFullName(TESFullName* apName, TESFile* apFile)
{
    if (!apFile || !apName)
    {
        return;
    }
    unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()));
    switch (id)
    {
    case CHUNK_ID_FULL_ID: {
        void* pChunkData;
        if (reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C())
        {
            pChunkData = _alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pChunkData), 0);
            reinterpret_cast<::TESFullName *>((((TESFullNameSetter*)apName)))->SetFullName((const char*)pChunkData);
        }
        else
        {
            reinterpret_cast<::TESFullName *>((((TESFullNameSetter*)apName)))->SetFullName(0);
        }
    }
    break;
    }
}
