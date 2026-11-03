
// src/fallout_shared/tesmodel.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesmodel.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00401660_Class.h"
#include <string.h>
#include "fnv/decl/FUN_00481110_shell.h"
#include "fnv/decl/FUN_00487980_shell.h"
#include "fnv/decl/FUN_004f9ef0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b2010_shell.h"
#include "fnv/decl/FUN_008c1be0_Class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/Owner487a60.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/TESIdleForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f8000.h"
#include <cstring>
#include <malloc.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00478130_class.h"
#include "fnv/decl/FUN_00478570_holder.h"
#include "fnv/decl/FUN_00478690_shell.h"
#include "fnv/decl/FUN_00478e90_This.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/ManagedSceneHolder.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
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
    void ClearTextureList();
};

// @fnv 0x00488ff0
void FUN_00488ff0_shell::FUN_00488ff0()
{
    ((FUN_00489620_t*)this)->ClearTextureList();
}

namespace fnv_00489620 {
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
struct FUN_00489620_shell : public FileEntryList
{
    bool ClearTextureList();
};


// Frees the texture offset array if present, nulls it, resets the texture count, and returns whether anything was freed.
// @fnv 0x00489620
bool FUN_00489620_shell::ClearTextureList()
{
    bool bresult = false;
    if (m_ppFileEntries)
    {
        BSFileEntry** p = m_ppFileEntries;
        ::FUN_00401030(p);
        m_ppFileEntries = 0;
        bresult = true;
    }
    m_ucFileEntryCount = 0;
    return bresult;
}
}  // namespace fnv_00489620

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

// @fnv 0x004898c0
void FUN_004898c0_shell::FUN_004898c0(int param_1)
{
    reinterpret_cast<::FUN_008c1be0_Class *>((((FUN_008c1be0_shell*)((char*)this + 0xc))))->FUN_008c1be0(param_1);
}


// @fnv 0x004898e0
bool FUN_004898e0()
{
    return DAT_011acdf8;
}

struct FUN_004890e0_shell
{
    void ForwardToMember();
};

// @fnv 0x004890e0
void FUN_004890e0_shell::ForwardToMember()
{
    reinterpret_cast<::fnv_00489620::FUN_00489620_shell *>((((FUN_00489620_t*)((char*)this + 0xc))))->ClearTextureList();
}

struct FUN_00489860_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    unsigned char* FUN_00489860(unsigned char a, unsigned char b, unsigned char c, unsigned char d, int e);
};

// Stores the four byte arguments into b0..b3 and the int argument into i4, then returns this as an unsigned char pointer.
// @fnv 0x00489860
unsigned char* FUN_00489860_shell::FUN_00489860(unsigned char aucByte0, unsigned char aucByte1,
                                                           unsigned char aucByte2, unsigned char aucByte3, int aiValue)
{
    b0 = aucByte0;
    b1 = aucByte1;
    b2 = aucByte2;
    b3 = aucByte3;
    i4 = aiValue;
    return (unsigned char*)this;
}

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
// @fnv 0x00487a00
void FUN_00487a00_shell::FUN_00487a00(TESForm* apOwner, unsigned short asLevel, unsigned short asCount, TESForm* apForm,
                                      ContainerItemExtra* apExtra)
{
    LeveledObject* plev = ((::LeveledObject *)(reinterpret_cast<::Owner487a60 *>(this)->InsertEntryByPriority(asLevel, asCount, (std::intptr_t)(apForm), (std::intptr_t)(apExtra))));
    if (plev)
    {
        ((G2*)m_kLeveledObjects)->AddHead(plev);
        ((FakeOwner*)apOwner)->a18(0x80000000);
    }
}

struct TESModel
{
    virtual ~TESModel();
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
// If the BSStr member converts to a nonzero value, clears it via Set(0, 0), then zeroes the byte at offset 0x14.
// @fnv 0x00489040
void FUN_00489040_shell::ClearString()
{
    if ((Flt&)FullNameComponent)
        reinterpret_cast<::TextString *>(&(FullNameComponent))->FUN_004037f0(0, 0);
    *(unsigned char*)((char*)this + 0x14) = 0;
}

struct FUN_004898a0_shell : public FUN_004898c0_shell
{
    int FUN_004898c0(int param_1);
    bool FUN_004898a0();
};

// @fnv 0x004898a0
bool FUN_004898a0_shell::FUN_004898a0()
{
    return FUN_004898c0(256) != 0;
}

namespace fnv_004898f0 {
struct Flt
{
    operator unsigned int();
    int v;
};
// Returns the value at index param_1 from DAT_011f8190 if nonzero, otherwise from DAT_011f81b4.
// @fnv 0x004898f0
unsigned int GetFltValue(int aiIndex)
{
    Flt* b;
    {
        Flt* a;
        if ((unsigned int)(*reinterpret_cast<fnv_004898f0::Flt (*)[]>(&::DAT_011f8190))[aiIndex])
            a = &(*reinterpret_cast<fnv_004898f0::Flt (*)[]>(&::DAT_011f8190))[aiIndex];
        else
            a = &(*reinterpret_cast<fnv_004898f0::Flt (*)[]>(&::archive_master_lookup::DAT_011f81b4))[aiIndex];
        b = a;
    }
    return (unsigned int)*b;
}
}  // namespace fnv_004898f0

namespace fnv_00489940 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSFileEntry;
struct FileFormCollection;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBitArrayFile;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct TESObjectREFR;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
struct blob8
{
    char b[8];
};
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
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_00489940_shell : public FileEntryList
{
    void LoadChunkData(TESFile*, TESForm*, char*);
};

struct TESFile
{
};
// @fnv 0x00489940
void FUN_00489940_shell::LoadChunkData(TESFile* file, TESForm* form, char* name)
{
    unsigned int isize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
    if (isize % 24)
        return;
    unsigned int icount = isize / 24;
    int iusablesize = icount * 24;
    if (icount)
    {
        FileFormCollection* pdata = (FileFormCollection*)_alloca(iusablesize);
        memset(pdata, 0, iusablesize);
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pdata), iusablesize);
        WriteFileEntryToBuffer(pdata, icount, form, name);
    }
}
}  // namespace fnv_00489940

struct FUN_004f9ec0_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls CallInnerMethod, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x004f9ec0
void* FUN_004f9ec0_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004f9ef0_shell *>(this)->CallInnerMethod();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

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

// @fnv 0x00488f50
FUN_00488f50_cls::FUN_00488f50_cls()
{
    reinterpret_cast<::FUN_00489040_shell *>(this)->ClearString();
}

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


// @fnv 0x00489120
void FUN_00489120_cls::SetFarPath(char* path)
{
    char* ext;
    ::TaskQueueInterface::CopyStringToBuffer(path, 0x104, GetPath());
    ext = ::FUN_0040ab30((char *)(path), 0x2e);
    if (ext != 0)
    {
        ::TaskQueueInterface::CopyStringToBuffer(ext, 0x104 - (ext - path), "_far.NIF");
    }
}

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

    bool FUN_00479fb0(B479FB0Actor* pkActor, std::intptr_t iArg);
};

// @fnv 0x00479fb0
bool B479FB0IdleList::FUN_00479fb0(B479FB0Actor* pkActor, std::intptr_t iArg)
{
    if (pkActor)
    {
        for (int i = 0; i < m_ucCount; i++)
        {
            B479FB0Idle* pkIdle = m_ppkIdles[i];
            if (pkIdle && reinterpret_cast<::FUN_008b2010_shell *>((pkActor))->HasIdleInFormArray((::TESIdleForm *)(pkIdle)) && reinterpret_cast<::TESIdleForm *>((pkIdle))->IsValidForReferences((::TESObjectREFR *)(pkActor), (::TESObjectREFR *)(iArg), true))
                return true;
        }
    }
    return false;
}

struct FUN_00488fd0_shell
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int i4;
    void* FUN_00488fd0();
};

// @fnv 0x00488fd0
void* FUN_00488fd0_shell::FUN_00488fd0()
{
    b0 = 0;
    i4 = 0;
    return this;
}

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
// Calls the TESModel destructor and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x00489010
void* TESModel::FUN_00489010(unsigned int flags)
{
    reinterpret_cast<::FUN_00489070 *>((this))->FUN_00489070::~FUN_00489070();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00489070
FUN_00489070::~FUN_00489070()
{
    reinterpret_cast<::FUN_004890e0_shell *>(this)->ForwardToMember();
}


struct FUN_00489480_shell : public TESModel
{
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual const char* GetModelPath();

    bool IsModelPathDifferent(BaseFormComponent* pkComponent);
};

// @fnv 0x00489480
bool FUN_00489480_shell::IsModelPathDifferent(BaseFormComponent* pkComponent)
{
    FUN_00489480_shell* pkOther = static_cast<FUN_00489480_shell*>(dynamic_cast<TESModel*>(pkComponent));
    if (!pkOther)
        return true;
    const char* pcPath = GetModelPath();
    {
        const char* pcOtherPath = pkOther->GetModelPath();
        if (pcPath && pcOtherPath)
        {
            if (::FUN_00404dc0(pcPath, pcOtherPath))
                return true;
        }
        else if (!pcPath || !pcOtherPath)
        {
            if (pcPath && *pcPath)
                return true;
            if (pcOtherPath && *pcOtherPath)
                return true;
        }
    }
    return false;
}

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
    std::uintptr_t* m_04;
    void LoadTextureArchiveEntries(Elem* arr, unsigned int count, ModelRef* form, const char* model);
};
bool __cdecl FUN_004898e0();

// Stores the count and allocates an array, then for each Elem builds two keys, looks up an archive entry, and logs a warning when the lookup fails.
// @fnv 0x00489670
void Cls::LoadTextureArchiveEntries(Elem* aElems, unsigned int count, ModelRef* form, const char* model)
{
    FUN_004898a0_shell* s = ((::FUN_004898a0_shell *)(std::uintptr_t)(::fnv_004898f0::GetFltValue(1)));
    if (!(s != 0 && ((FUN_004898a0_shell*)((char*)s + 0x160))->FUN_004898a0() &&
          *((FUN_00408d60_shell*)&(*reinterpret_cast<char *>(&::g_011c5574)))->FUN_00408d60() != 0))
        return;
    m_00 = (unsigned char)count;
    m_04 = new std::uintptr_t[count];
    for (unsigned int i = 0; i < count; i++)
    {
        FUN_00489860_shell key0;
        key0.FUN_00489860(aElems[i].b0, aElems[i].b1, aElems[i].b2, aElems[i].b3, aElems[i].i4);
        FUN_00489860_shell key1;
        key1.FUN_00489860(aElems[i].c0, aElems[i].c1, aElems[i].c2, aElems[i].c3, aElems[i].i14);
        m_04[i] = ((std::uintptr_t)(::fnv_00af6540::FindFileEntryInArchives(1, (*(::fnv_00af6540::FileNameHash *)(&key1)), (*(::fnv_00af6540::FileNameHash *)(&key0)), (const char *)(0))));
        if (*((FUN_00408d60_shell*)&(*reinterpret_cast<char *>(&::g_011c555c)))->FUN_00408d60() != 0)
        {
            if (FUN_004898e0())
            {
                if (m_04[i] == 0)
                {
                    if (form != 0 && model != 0)
                    {
                        ::FUN_005b5e40(
                            );
                    }
                    else if (model != 0)
                    {
                        ::FUN_005b5e40(
                            );
                    }
                    else
                    {
                        ::FUN_005b5e40();
                    }
                }
            }
        }
    }
}


struct FUN_004891d0_hash
{
};

struct FUN_004891d0_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    int unk04;
    int unk08;
    FUN_004891d0_hash m_kObjectMap;
    unsigned int FUN_0048cee0();
    void WriteToBuffer(char* pcBuffer, void* pkOut);
};

// When FUN_0048cee0() is nonzero, copies GetPath() to pcBuffer and passes pkOut and GetPath() to m_kObjectMap.FUN_008d0600.
// @fnv 0x004891d0
void FUN_004891d0_cls::WriteToBuffer(char* pcBuffer, void* pkOut)
{
    if (FUN_0048cee0())
    {
        if (pcBuffer)
            ::FUN_004856f0(pcBuffer, (void *)(GetPath()), (void *)(std::uintptr_t)(FUN_0048cee0() + 1));
        if (pkOut)
            reinterpret_cast<::FUN_008d0600_s *>(&(m_kObjectMap))->FUN_008d0600((std::intptr_t)(pkOut), (std::intptr_t)(GetPath()));
    }
}

struct TESForm;
struct TESObjectREFR;
struct FUN_004895b0_model
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
};

extern "C" void* __cdecl FNV_DynamicCast(void* inptr, long vfDelta, void* srcType, void* targetType, int isReference);
extern unsigned char DAT_011831e8;

FUN_004895b0_model* FUN_00481010(TESForm* form, TESObjectREFR* ref);

// Calls FNV_DynamicCast and FUN_00481010, then returns v5() or an empty string.
// @fnv 0x004895b0
const char* FUN_004895b0(TESForm* apForm)
{
    FUN_004895b0_model* m = (FUN_004895b0_model*)FNV_DynamicCast(apForm, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_011831e8, 0);
    if (m == 0)
    {
        m = FUN_00481010(apForm,
                         (TESObjectREFR*)FNV_DynamicCast(apForm, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &::DAT_011841cc, 0));
    }
    if (m != 0)
    {
        return m->v5();
    }
    return "";
}

struct TESForm
{
    virtual ~TESForm();
};

struct DistantModelView : TESModel
{
};
// If apForm is a TESModel, cast it to DistantModelView and call FUN_00489120 with apModelName.
// @fnv 0x00489190
void FUN_00489190(char* apModelName, TESForm* apForm)
{
    TESModel* pmodel;
    if (apForm)
    {
        pmodel = dynamic_cast<TESModel*>(apForm);
        if (pmodel)
        {
            reinterpret_cast<::FUN_00489120_cls *>((static_cast<DistantModelView*>(pmodel)))->SetFarPath(apModelName);
        }
    }
}

struct TextureModelView : TESModel
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char* GetPath();
    char* modelName;
    unsigned short nameLength;
    unsigned short nameCapacity;
    FileEntryList textures;
};
// Loads texture file entries into the model's texture list from the given file, using the model's path and form context.
// @fnv 0x004893e0
void FUN_004893e0(TESModel* model, TESFile* file)
{
    if (model && file)
        reinterpret_cast<::fnv_00489940::FUN_00489940_shell *>(&(static_cast<TextureModelView*>(model)->textures))->LoadChunkData((::fnv_00489940::TESFile *)(file), (::fnv_00489940::TESForm *)(::TESForm *)(dynamic_cast<TESForm*>(model)),
                                                             static_cast<TextureModelView*>(model)->GetPath());
}

struct ModelCopyView : TESModel
{
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual int GetFlags();
    virtual void SetFlags(int flags);
    void FUN_00489430(BaseFormComponent* component);
};

// Copies the flags from a BaseFormComponent cast to TESModel into this ModelCopyView.
// @fnv 0x00489430
void ModelCopyView::FUN_00489430(BaseFormComponent* component)
{
    TESModel* copy = dynamic_cast<TESModel*>(component);
    if (copy == 0)
        return;
    SetFlags(reinterpret_cast<ModelCopyView*>(copy)->GetFlags());
}

// @fnv 0x00489540
unsigned int __cdecl FUN_00489540(void* apForm)
{
    void* result;

    result = dynamic_cast<::TESModel *>(reinterpret_cast<::TESForm *>(apForm));
    if (result == 0)
    {
        result = ::FUN_00481010((::TESForm*)apForm, (::TESObjectREFR*)::FNV_DynamicCast(apForm, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)),
                                                                                        &::DAT_011841cc, 0));
    }
    if (result != 0)
    {
        return ((::FUN_004891d0_cls*)result)->FUN_0048cee0();
    }
    return 0;
}

struct WorldModelEntry481010
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
};

class TESBipedModelForm : public BaseFormComponent
{
  public:
    unsigned int partMask;
    unsigned int flags;
    WorldModelEntry481010 maleBipedModel;
    WorldModelEntry481010 femaleBipedModel;
    FUN_004895b0_model worldModel;

};

struct ReferenceOwnerView481010
{
};

struct ActorSexView481010
{
    int FUN_005f0cc0();
};

int _FNV_GetFormType(TESForm*);

// Returns the biped model for a TESBipedModelForm, selecting the male or female variant based on the owner actor's sex when a reference is provided.
// @fnv 0x00481010
FUN_004895b0_model* __cdecl FUN_00481010(TESForm* apBipedModelForm, TESObjectREFR* apReference)
{
    TESBipedModelForm* sex = dynamic_cast<TESBipedModelForm*>(apBipedModelForm);
    TESForm* biped;
    int iOwnerSex;

    if (sex == 0)
        return 0;
    if (apReference == 0)
        return &sex->worldModel;

    biped = reinterpret_cast<::OwnerLookupView *>((reinterpret_cast<ReferenceOwnerView481010*>(apReference)))->FUN_00567790();
    iOwnerSex = 0;
    if (biped != 0 && _FNV_GetFormType(biped) == 0x2a)
        iOwnerSex = reinterpret_cast<ActorSexView481010*>(biped)->FUN_005f0cc0();
    return ((::FUN_004895b0_model *)(reinterpret_cast<::FUN_00481110_shell *>((sex))->GetWorldModel(iOwnerSex)));
}

struct TESForm_decl;

struct FileEntryList_decl
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm_decl*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm_decl*, char*);
    void Copy(FileEntryList_decl*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};

struct FUN_00488ff0_shell_decl : public FileEntryList_decl
{
    void FUN_00488ff0();
};

struct FUN_00489620_t_decl
{
};

bool FUN_004898e0();

struct TESForm_decl;

struct TESLeveledList_decl : public BaseFormComponent
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
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm_decl*, ContainerItemExtra*);
    void DeleteLeveledObject(LeveledObject*);
    void SelectLeveledObject(unsigned short, TESForm_decl**, unsigned short*, ContainerItemExtra**, bool, int);
    void PopulateContainerWithLeveledItems(unsigned short, unsigned short, TESContainer*, int);
    void PopulateContainerFromReference(TESObjectREFR*, TESContainer*);
    void AddScriptAddedLeveledObject(TESForm_decl*, unsigned short, unsigned short, TESForm_decl*, ContainerItemExtra*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm_decl*);
    static TESLeveledList_decl* GetFormAsLeveledList(TESForm_decl*);
    void* GetLeveledList();
    void* __vecDelDtor(unsigned int);
    char leveledList[8];
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    char _pad_e[2];
    TESGlobal* m_pLevelGlobal;
    char m_kLeveledObjects[8];
};

struct FUN_00487a00_shell_decl : public TESLeveledList_decl
{
    void FUN_00487a00(TESForm_decl*, unsigned short, unsigned short, TESForm_decl*, ContainerItemExtra*);
};

struct TESModel_decl
{
    virtual ~TESModel_decl();
    virtual void TM01();
    virtual void TM02();
    virtual void TM03();
    virtual void TM04();
    virtual void TM05();
    virtual void SetModelPath(const char* path);
    void* FUN_00489010(unsigned int flags);
};

struct FUN_004898a0_shell_decl : public FUN_004898c0_shell
{
    bool FUN_004898a0();
};

struct FUN_00489480_shell_decl : public TESModel_decl
{
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual const char* GetModelPath();

    bool IsModelPathDifferent(BaseFormComponent* pkComponent);
};

struct FUN_004898a0_shell_decl;

class String;

template <class T> struct tList
{
    T* item;
    tList<T>* next;
};

class TESForm_decl : public BaseFormComponent
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
    virtual bool Sort(TESForm_decl* form);
    virtual TESForm_decl* CreateForm(void* arg0, void* mapToAddTo);
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
    virtual void CopyFrom(const TESForm_decl* form);
    virtual bool Compare(TESForm_decl* form);
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
    TESForm_decl* explosion;
    TESForm_decl* debris;
    unsigned int debrisCount;
    TESModel_decl* replacementModel;
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
    TESForm_decl* explosion;
    TESForm_decl* debris;
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
            TESForm_decl* form = dynamic_cast<TESForm_decl*>(component);
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
                    FUN_004893e0(reinterpret_cast<TESModel*>(pkData->stages[index]->replacementModel), file);
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

struct FileEntryList_o2
{
    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void WriteFileEntryToBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Copy(FileEntryList_o2*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFileEntryCount;
    char _pad_1[3];
    BSFileEntry** m_ppFileEntries;
};

struct FUN_00488ff0_shell_o2 : public FileEntryList_o2
{
    void FUN_00488ff0();
};

struct FUN_00489620_t_o2
{
};

struct FUN_008c1be0_shell_o2
{
};

// sub ecx,0x30; jmp FUN_004029f0  ==  MSVC adjustor thunk (multiple inheritance,
// primary base occupies 0x30 bytes; both bases declare the same virtual, the derived
// class only defines its constructor so the compiler emits the this-adjusting thunk).
struct PrimaryBase
{
    virtual void FUN_00403a40();
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

struct SecondaryBase
{
    virtual void FUN_00403a40();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00403a40
    virtual void FUN_00403a40();
};

Derived::Derived()
{}

namespace fnv_0040a110 {
// sub ecx,0x30; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x30).
struct PrimaryBase
{
    virtual void FUN_0040a110();
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


struct SecondaryBase
{
    virtual void FUN_0040a110();
};

struct DerivedThunkHost : PrimaryBase, SecondaryBase
{
    DerivedThunkHost();
// @fnv 0x0040a110
    virtual void FUN_0040a110();
};

DerivedThunkHost::DerivedThunkHost()
{}
}
