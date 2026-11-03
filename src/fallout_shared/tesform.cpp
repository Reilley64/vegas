// fallout_shared/tesform.cpp: TESForm, TESValueForm, TESFile, BGSSaveLoadChangesMap and more (128 functions)

#include <new>
#include <cstring>
#include "fileformat/compression.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSSimpleArrayActor.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00401280_Class.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_00460340_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00471a10_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472f60_cls.h"
#include "fnv/decl/FUN_00473070Class.h"
#include "fnv/decl/FUN_00473080_Class.h"
#include "fnv/decl/FUN_00473090_cls.h"
#include "fnv/decl/FUN_0047c600_cls.h"
#include "fnv/decl/FUN_0047c670_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047ff50_class.h"
#include "fnv/decl/FUN_00480100_shell.h"
#include "fnv/decl/FUN_00480130_shell.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_00485bc0_class.h"
#include "fnv/decl/FUN_00486ee0.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_005eeda0_this.h"
#include "fnv/decl/FUN_006796c0_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00857bf0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormArray.h"
#include "fnv/decl/FormComponentArray.h"
#include "fnv/decl/Holder_47c5b0.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00472e60__TESFile_Standin.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00470000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00486000.h"
#include "fnv/symbols_0048c000.h"
#include "fnv/symbols_00554000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00fff000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "tesform_calls.h"
#include "tesform_TESFile.h"

// Walks the source-file list, returning the last non-null TESFile, or the one at fileIndex when fileIndex is not -1.
// @fnv 0x00484e60
TESFile* TESForm::GetFile(int fileIndex)
{
    TESFile* sourceFile;
    int index;
    BSSimpleList<TESFile*>* fileList;
    TESFile* selected;
    fileList = ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)));
    index = 0;
    sourceFile = 0;
    selected = 0;
    while (fileList)
    {
        sourceFile = (fileList->m_item);
        fileList = ((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((fileList))->FUN_00726070()));
        if (sourceFile)
        {
            selected = sourceFile;
            if (fileIndex != -1)
            {
                ++index;
                if (index > fileIndex)
                {
                    break;
                }
            }
        }
    }
    return selected;
}

// Covered functions reconstructed from the supplied disassembly.
// @fnv 0x00401170
ENUM_FORM_ID TESForm::GetFormType() const
{
    return static_cast<ENUM_FORM_ID>(m_ucFormType);
}
// @fnv 0x00440da0
bool TESForm::GetDisabled() const
{
    return (m_uiFormFlags & 0x800);
}
// @fnv 0x00483710
void TESForm::ClearData()
{}
// @fnv 0x004844f0
void TESForm::SetMasterFile(bool set)
{
    if (set)
        m_uiFormFlags |= 0x1;
    else
        m_uiFormFlags &= ~0x1;
}

// @fnv 0x00484530
void TESForm::MarkForDeletion(bool set)
{
    if (set)
        m_uiFormFlags |= 0x20;
    else
        m_uiFormFlags &= ~0x20;
    MarkAsModified(1);
}

// @fnv 0x00484650
void TESForm::SetDestroyed(bool abDestroyed)
{
    if (abDestroyed)
        m_uiFormFlags |= 0x800000;
    else
        m_uiFormFlags &= ~0x800000;
    MarkAsModified(1);
}

// @fnv 0x004846a0
void TESForm::SetDestructible(bool set)
{
    if (set)
        m_uiFormFlags |= 0x1000000;
    else
        m_uiFormFlags &= ~0x1000000;
}

// @fnv 0x004848b0
void TESForm::SetFormFlag40(bool set)
{
    if (set)
        m_uiFormFlags |= 0x40;
    else
        m_uiFormFlags &= ~0x40;
    MarkAsModified(1);
}

// @fnv 0x00484900
void TESForm::SetHavokDeath(bool set)
{
    if (set)
        m_uiFormFlags |= 0x10000;
    else
        m_uiFormFlags &= ~0x10000;
    MarkAsModified(1);
}

// @fnv 0x00484950
void TESForm::SetNeedToChangeProcess(bool set)
{
    if (set)
        m_uiFormFlags |= 0x20000;
    else
        m_uiFormFlags &= ~0x20000;
}

// @fnv 0x00484990
void TESForm::SetIgnoreFriendlyHits(bool set)
{
    if (set)
        m_uiFormFlags |= 0x100000;
    else
        m_uiFormFlags &= ~0x100000;
}

// @fnv 0x00484ab0
void TESForm::SetInitializationState(bool set)
{
    if (set)
        m_uiFormFlags |= 0x8;
    else
        m_uiFormFlags &= ~0x8;
}

// @fnv 0x00484b40
bool TESForm::IsReservedFormID(unsigned int formID)
{
    if (formID != 0 && formID <= 0x7ff)
        return true;
    else
        return false;
}
// @fnv 0x00484e40
bool TESForm::IsReservedFormID()
{
    return IsReservedFormID(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())));
}
// @fnv 0x00484b60
void TESForm::MarkAsModified(unsigned int flags)
{
    ::g_BGSSaveLoadGame->NotifyFormIDChanged(this, flags, false);
}
// Forwards this form and the given flags to g_BGSSaveLoadGame's handler with the third argument set to true.
// @fnv 0x00484b90
void TESForm::SetFormFlags(int flags)
{
    ::g_BGSSaveLoadGame->NotifyFormIDChanged(this, flags, true);
}
// @fnv 0x00484bc0
void TESForm::MarkAsUnmodified(unsigned int flags)
{
    ::g_BGSSaveLoadGame->ClearFormChangeFlags(this, flags);
}
// Reads 4 bytes of change flags from the load buffer when flag 1 is set and merges the masked bits into the form's flags field.
// @fnv 0x00484da0
void TESForm::LoadGame(void* apLoadBuffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(static_cast<BGSLoadFormBuffer*>(apLoadBuffer)->GetChangeFlags(1)))->FUN_004280f0(1))
    {
        unsigned int flags = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((static_cast<BGSLoadFormBuffer*>(apLoadBuffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flags), 4);
        if (GetIsReference())
            m_uiFormFlags = (m_uiFormFlags & 0xff6ed79f) | (flags & 0x00912860);
        else
            m_uiFormFlags = (m_uiFormFlags & 0xbffff3df) | (flags & 0x40000c20);
    }
}
// Stores value in uiValue and, if this is a TESForm, marks it as modified with flag 2.
// @fnv 0x0048e960
void TESValueForm::SetFormValue(unsigned int value)
{
    uiValue = value;
    TESForm* form = dynamic_cast<TESForm*>(this);
    if (form)
        form->MarkAsModified(2);
}
// Stores item into m_item when item is non-null; returns early otherwise.
// @fnv 0x00726c60
template <> void BSSimpleList<TESFile*>::SetItem(TESFile* const& apFile)
{
    if (!apFile)
        return;
    m_item = apFile;
}
// @fnv 0x00484ee0
TESFile* TESForm::GetOwnerMaster()
{
    BSSimpleList<TESFile*>* pFileNode = ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)));
    TESFile* pOwnerMaster = 0;
    while (pFileNode && !pFileNode->IsEmpty())
    {
        TESFile* file = (pFileNode->m_item);
        pFileNode = ((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((pFileNode))->FUN_00726070()));
        if (file->IsMasterFile())
            pOwnerMaster = file;
    }
    return pOwnerMaster;
}

// Looks up editorID in the form table and returns the matching TESForm, or null if editorID is empty or not found.
// @fnv 0x00483a00
TESForm* TESForm::LookupFormByEditorID(const char* editorID)
{
    TESForm* form = 0;
    if (editorID && *editorID && (*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8)) && reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)((*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8))))->FUN_00853130((unsigned int)(editorID), (::fnv_00853130::CombatThreatRecord *&)(form)))
    {
        return form;
    }
    else
    {
        return 0;
    }
}

// Lazily allocates the three global form lookup containers (pointer map, case-insensitive string map, large primitive array) if they are null.
// @fnv 0x00483a50
void TESForm::InitializeFormIDMap()
{
    if (!::fnv_00483370::DAT_011c54c0)
    {
        ::fnv_00483370::DAT_011c54c0 = new NiTPointerMap<unsigned int, TESForm*>(0x2008D);
    }
    if (!(*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8)))
    {
        (*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8)) = new BSTCaseInsensitiveStringMap<TESForm*>(0xFA1, true);
    }
    if (!ms_pAllForms)
    {
        ms_pAllForms = new NiTLargePrimitiveArray<TESForm*>(32, 1);
    }
}

// @fnv 0x00484f50
void TESForm::SetFile(TESFile* file)
{
    TESFile* parentFile = file ? file->GetThreadSafeRootFile() : 0;
    if (parentFile)
    {
        file = parentFile;
    }
    if (!file)
    {
        BSSimpleList<TESFile*>* source = ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)));
        BSSimpleList<TESFile*>* lastSource = 0;
        while (source)
        {
            if ((source->m_item))
            {
                lastSource = source;
            }
            source = ((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((source))->FUN_00726070()));
        }
        if (lastSource)
        {
            lastSource->RemoveHead();
        }
        else
        {
            ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)))->RemoveHead();
        }
    }
    else if (file->IsMasterFile())
    {
        BSSimpleList<TESFile*>* source = ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)));
        BSSimpleList<TESFile*>* lastMaster = 0;
        while (source && !source->IsEmpty())
        {
            TESFile* sourceFile = (source->m_item);
            if (sourceFile->IsMasterFile())
            {
                lastMaster = source;
                source = ((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((source))->FUN_00726070()));
            }
            else
            {
                if (lastMaster)
                {
                    reinterpret_cast<::ItemChangeListNode *>((lastMaster))->FUN_00905330((::InventoryStackRecord *const &)(sourceFile));
                    source = ((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((lastMaster))->FUN_00726070()));
                }
                else
                {
                    source->RemoveHead();
                }
            }
        }
        reinterpret_cast<::Callees *>((((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)))))->FUN_00905820((void *)&(file));
    }
    else
    {
        BSSimpleList<TESFile*>* source = ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)));
        BSSimpleList<TESFile*>* lastSource = 0;
        while (source)
        {
            TESFile* sourceFile = (source->m_item);
            if (sourceFile)
            {
                lastSource = source;
                if (sourceFile == file)
                {
                    return;
                }
            }
            source = ((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((source))->FUN_00726070()));
        }
        if (lastSource)
        {
            reinterpret_cast<::Callees *>((lastSource))->FUN_00905820((void *)&(file));
        }
        else
        {
            ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)this)))->AddHead(file);
        }
    }
}

// @fnv 0x00467bb0
unsigned int TESFile::GetOffset()
{
    return m_uiRecordSize;
}

extern int DAT_01014210;

// @fnv 0x0040ecb0
void FUN_0040ecb0(int* p)
{
    *p = (int)&DAT_01014210;
}

struct FUN_00471d60_shell : public TESFile
{
    bool IsFlag8Set();
};

// @fnv 0x00471d60
bool FUN_00471d60_shell::IsFlag8Set()
{
    if (this->m_uiFileCount & 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x004835e0
unsigned int GetField20C(char* pThis)
{
    return *(unsigned int*)(pThis + 0x20c);
}

struct T00485110
{
};
struct S00485110
{
    void CallWithThis(T00485110* f);
};
// @fnv 0x00485110
void S00485110::CallWithThis(T00485110* apTarget)
{
    reinterpret_cast<::FUN_00472f60_cls *>((apTarget))->FUN_00472f60((::FUN_00472f60_arg *)(void *)(this));
}

// Returns the smaller of two unsigned short values.
// @fnv 0x004865f0
unsigned short __cdecl MinUnsignedShort(unsigned short ausValue1, unsigned short ausValue2)
{
    return ausValue1 < ausValue2 ? ausValue1 : ausValue2;
}

struct FormEnumEntry
{
    unsigned int m_uiFormID;
    int unk4;
    int unk8;
};

extern int DAT_011c54f0;
extern unsigned int DAT_011c54f4;

// @fnv 0x00486890
int __cdecl FindFormEnumIndex(unsigned int aiFormString)
{
    if (aiFormString == DAT_011c54f4)
    {
        return DAT_011c54f0;
    }
    for (int i = 0; i < 0x79; ++i)
    {
        if (DAT_01187008[i].m_uiFormID == aiFormString)
        {
            DAT_011c54f0 = i;
            DAT_011c54f4 = aiFormString;
            return DAT_011c54f0;
        }
    }
    return 0;
}

extern int DAT_01031fac;

struct FUN_00486930_arg
{
    unsigned int val;
};

void FUN_005890c0(int* self, FUN_00486930_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00486930
int* FUN_00486930(int* self, FUN_00486930_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}

struct S00486ab0
{
    const char* p;
    S00486ab0* Construct(unsigned int n, bool b);
};
// Calls FUN_00486ee0 with n and b, sets p to "0lH", and returns this.
// @fnv 0x00486ab0
S00486ab0* S00486ab0::Construct(unsigned int auiValue, bool b)
{
    reinterpret_cast<::FUN_00486ee0 *>(this)->Init((void *)(auiValue), b);
    p = "0lH";
    return this;
}

// @fnv 0x0048ce80
void ClearString(char* this_ptr)
{
    reinterpret_cast<::TextString *>((((BSStringT<char>*)(this_ptr + 4))))->FUN_004037f0(0, 0);
}

struct S00551440
{
    char pad[0x24];
    unsigned char flags;
    void FUN_00551440(bool v);
};
// Sets or clears bit 0x10 in the flags byte according to v.
// @fnv 0x00551440
void S00551440::FUN_00551440(bool v)
{
    if (v)
        flags |= 0x10;
    else
        flags &= ~0x10;
}

struct FUN_00576d30_shell : public TESForm
{
    bool FUN_00576d30();
};

// @fnv 0x00576d30
bool FUN_00576d30_shell::FUN_00576d30()
{
    return (m_uiFormFlags & 0x200000) ? true : false;
}

struct ListX
{
    ~ListX();
    char d[8];
};
struct List_009e03e0
{
};
struct FUN_00483630_slg
{
};
void __cdecl FUN_00483b80();
struct FUN_00483630_holder
{
    char pad[0xc];
    ListX l;
    virtual ~FUN_00483630_holder();
};
struct FUN_00483c70_shell : public TESForm
{
    void FUN_00483c70();
};
// @fnv 0x00484490
void TESForm::NotifySaveLoadGameOfFormChange()
{
    reinterpret_cast<::FUN_00483c70_shell *>(this)->FUN_00483c70();
    if (::g_TESSaveLoadGame)
        ::g_TESSaveLoadGame->HasFormChanges(this, false);
    if (::g_BGSSaveLoadGame)
        ::g_BGSSaveLoadGame->HasFormChanges(this);
    m_uiFormFlags |= 0x4000;
}
// @fnv 0x00483630
FUN_00483630_holder::~FUN_00483630_holder()
{
    reinterpret_cast<::FUN_00483c70_shell *>((((TESForm*)this)))->FUN_00483c70();
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)&l)))->RemoveAll();
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(((TESForm*)this)))->FUN_004077c0() && ::g_TESSaveLoadGame)
    {
        ::g_TESSaveLoadGame->HasFormChanges((TESForm*)this, false);
        reinterpret_cast<::TESSaveLoadGame *>((((FUN_00483630_slg*)::g_TESSaveLoadGame)))->FinalizeForm((TESForm*)this);
    }
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(((TESForm*)this)))->FUN_004077c0() && ::g_BGSSaveLoadGame)
        ::g_BGSSaveLoadGame->HasFormChanges((TESForm*)this);
    if (--DAT_011c54bc == 0)
        FUN_00483b80();
}

struct TESTopicInfo;
struct Arr
{
    unsigned int* GetAt(int);
};
struct DH
{
};
struct FUN_00485d50_slg
{
};
struct FUN_00485d50_file
{
};
// @fnv 0x00485d50
void ResolveFormID(unsigned int* aiID, TESFile* apFile)
{
    if (reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)::g_TESSaveLoadGame)))->EvaluateCondition())
    {
        *aiID = ((unsigned int)(reinterpret_cast<::FUN_00857bf0_Class *>((((FUN_00485d50_slg*)::g_TESSaveLoadGame)))->FUN_00857bf0(*aiID)));
    }
    else if (!TESForm::IsReservedFormID(*aiID))
    {
        if (apFile)
        {
            TESFile* pMasterFile = reinterpret_cast<::FUN_00471a10_shell *>((((FUN_00485d50_file*)apFile)))->GetFileByIndex((*aiID >> 24) + 1);
            if (pMasterFile)
            {
                *aiID = (reinterpret_cast<::TESFile *>((((FUN_00485d50_file*)pMasterFile)))->GetFileCompileIndex() << 24) | (*aiID & 0xffffff);
            }
            else
            {
                *aiID = (reinterpret_cast<::TESFile *>((((FUN_00485d50_file*)apFile)))->GetFileCompileIndex() << 24) | (*aiID & 0xffffff);
            }
        }
    }
}

struct NiFormArray;
struct PerkEntryConditionSet;
struct TESIdleForm;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectREFR;
struct FileEntryList;
struct IdleAnimationManager
{
    void RemoveIdleForm(TESIdleForm*);
    void InitializeIdleAnimations();
    void ResetIdleAnimations();
    void LoadIdleAnimations();
    NiFormArray* AddRootIdleArray(TESForm*);
    NiFormArray* AddRootIdleArray(char*, void*, bool);
    NiFormArray* GetRootIdleArray(TESForm*);
    NiFormArray* GetRootIdleArray(char*);
    NiFormArray* GetIdleArray(TESForm*);
    NiFormArray* GetIdleArray(char*);
    static void BuildIdlePath(char*, char*);
    void* FindIdleArrayEntry(char*, int);
    void ClearIdleData();
    static void SetUsedItem(TESObject*);
    static void SetUsedItemLevel(int);
    static int GetUsedItemLevel();
    static void SetUsedItemActivate(bool);
    static bool GetUsedItemActivate();
    bool GetInitialized();
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_acIdlePath[20];
    bool bInitialized;
    char _pad_15[3];
    char m_acIdleName[16];
};
struct FUN_005ffbf0_shell : public IdleAnimationManager
{
    void AddIdleToArray(TESIdleForm*);
};

struct NiTPrimitiveArray_unsigned_int_
{
    unsigned int AddFirstEmpty(const unsigned int&);
};
// @fnv 0x005ffbf0
void FUN_005ffbf0_shell::AddIdleToArray(TESIdleForm* apIdle)
{
    if (apIdle)
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)m_acIdleName)))->FUN_0096a610((int)&((const unsigned int&)apIdle));
}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct TESFileGroup;
struct FurnitureMark;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
struct FUN_004011d0_shell : public TESForm
{
    bool FUN_004011d0();
};

// @fnv 0x004011d0
bool FUN_004011d0_shell::FUN_004011d0()
{
    return (m_uiFormFlags & 0x20000) ? true : false;
}

namespace fnv_004011f0 {
struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct TESFileGroup;
struct FurnitureMark;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
struct FUN_004011f0_shell : public TESForm
{
    bool FUN_004011f0();
};

// @fnv 0x004011f0
bool FUN_004011f0_shell::FUN_004011f0()
{
    return (m_uiFormFlags & 0x80000) ? true : false;
}
}  // namespace fnv_004011f0

struct S3c60
{
    int FUN_00408a40(void);
};


// @fnv 0x00408a40
int S3c60::FUN_00408a40()
{
    return ((int)(::GetEntryByIndex(reinterpret_cast<::EffectSetting *>(this)->GetArchetype())));
}

extern unsigned char DAT_011c3c0d;

// @fnv 0x00456c70
unsigned char FUN_00456c70()
{
    return DAT_011c3c0d;
}

struct Base5a
{
    virtual ~Base5a();
};

void Deallocate(void* memory);

struct FUN_00483600_holder : Base5a
{
    void* DestroyHolder(unsigned int flags);
};

// Runs the base destructor, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00483600
void* FUN_00483600_holder::DestroyHolder(unsigned int flags)
{
    reinterpret_cast<::FUN_00483630_holder *>(this)->FUN_00483630_holder::~FUN_00483630_holder();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00484610_shell
{
    int _pad0;
    int _pad1;
    unsigned int m_uiFormFlags;
    void SetFlag2000(bool value);
};

// @fnv 0x00484610
void FUN_00484610_shell::SetFlag2000(bool abSet)
{
    if (abSet)
        m_uiFormFlags |= 0x2000;
    else
        m_uiFormFlags &= ~0x2000;
}

struct FUN_004849d0_shell
{
    unsigned int m0;
    unsigned int m1;
    unsigned int m_uiFormFlags;
    void SetFlag200(bool abVal);
};

// @fnv 0x004849d0
void FUN_004849d0_shell::SetFlag200(bool abVal)
{
    if (abVal)
        m_uiFormFlags |= 0x200;
    else
        m_uiFormFlags &= ~0x200;
}

struct FUN_00484bf0_shell
{
    unsigned short FUN_00484bf0(unsigned int aiFlags);
};

// Returns 4 when bit 0 of aiFlags is set, otherwise 0.
// @fnv 0x00484bf0
unsigned short FUN_00484bf0_shell::FUN_00484bf0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 1)
        isize += 4;
    return isize;
}


struct FUN_004854e0_shell : TESForm
{
    bool IsGroupFormOfType(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly);
};

// Returns true if apGroupFORM is a group form with form ID 0 whose flags match the value indexed by this form's type.
// @fnv 0x004854e0
bool FUN_004854e0_shell::IsGroupFormOfType(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->form == ::fnv_00543df0::kGroupFormType && apGroupFORM->iFormID == 0)
    {
        if (apGroupFORM->flags == *(unsigned int*)(this->GetFormType() * 0xc + 0x1187008))
            bretval = true;
    }
    return bretval;
}


// @fnv 0x004856d0
void __cdecl FUN_004856d0(int arg)
{
    ::AppendChunk(arg, (const void *)(0), 0);
}


// @fnv 0x004856f0
void __cdecl FUN_004856f0(void* apArg1, void* apArg2, void* apArg3)
{
    ::AppendChunk((unsigned int)(apArg1), apArg2, (unsigned int)(apArg3));
}

void __cdecl FUN_00485750(void* arg0, void* arg1, void* arg2);

// @fnv 0x00485710
void __cdecl FUN_00485710(void* arg0, void* arg1, void* arg2)
{
    FUN_00485750(arg0, arg1, arg2);
}


// @fnv 0x00485730
void __cdecl FUN_00485730(void* apArg1, void* apArg2, void* apArg3)
{
    ::FUN_00485820(apArg1, apArg2, (unsigned int)(apArg3));
}

extern void* DAT_011c54cc;
void __cdecl Deallocate(void*);

struct FUN_00485b30_shell
{
    void ResetGlobalPointer();
};

// Frees the pointer stored in DAT_011c54cc and sets it to null.
// @fnv 0x00485b30
void FUN_00485b30_shell::ResetGlobalPointer()
{
    ::FUN_00401030(DAT_011c54cc);
    DAT_011c54cc = 0;
}

struct FUN_00485e00_shell
{
    void FUN_00485e00();
};

struct NodePoolView
{
};

struct BGSSaveLoadChangesMap
{
    int m_auiShapeKeys[3];
    NodePoolView m_NodePoolView;
    void* FUN_00486a90();
};

// @fnv 0x00486a90
void* BGSSaveLoadChangesMap::FUN_00486a90()
{
    return ((void *)(reinterpret_cast<::FUN_0043a010_shell *>(&(m_NodePoolView))->FUN_0043a010()));
}

extern int DAT_0118a870[];

struct FUN_0051dab0_shell
{
    int GetIndexedValue();
};

// @fnv 0x0051dab0
int FUN_0051dab0_shell::GetIndexedValue()
{
    return DAT_0118a870[*(char*)(((char*)this) + 0xf4)];
}

struct ArrSI
{
};

struct FUN_005516c0
{
    bool IsCellPersistent();
};

// Returns true if GetFlags() has bit 0x400 set, otherwise false.
// @fnv 0x005516c0
bool FUN_005516c0::IsCellPersistent()
{
    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())) & 0x400)
    {
        return true;
    }
    else
    {
        return false;
    }
}


struct FUN_00554880_shell
{
    void FUN_00554880(unsigned char arg);
};

// @fnv 0x00554880
void FUN_00554880_shell::FUN_00554880(unsigned char arg)
{
    ::FUN_005548a0(arg);
}

extern unsigned char __cdecl FUN_00588a60(unsigned char);

struct FUN_00588a40_shell
{
    unsigned char FUN_00588a40(unsigned char arg);
};

// @fnv 0x00588a40
unsigned char FUN_00588a40_shell::FUN_00588a40(unsigned char arg)
{
    return FUN_00588a60(arg);
}

namespace fnv_005e9690 {

struct FUN_005e9690_shell
{
    void FUN_005e9690();
};

// @fnv 0x005e9690
void FUN_005e9690_shell::FUN_005e9690()
{
    ::FUN_004856d0(0x464b5250);
}
}  // namespace fnv_005e9690

struct FUN_0061bbd0_shell
{
    unsigned char FUN_0061bbd0(unsigned char param);
};


// @fnv 0x0061bbd0
unsigned char FUN_0061bbd0_shell::FUN_0061bbd0(unsigned char param)
{
    return ((unsigned char)(::FUN_0061bbf0(param)));
}

struct FUN_00621b00_shell
{
    float FUN_00621b00();
};

// @fnv 0x00621b00
float FUN_00621b00_shell::FUN_00621b00()
{
    return *(float*)((char*)this + 0x10);
}

struct FUN_008df040_shell
{
    unsigned char FUN_008df040();
};

// @fnv 0x008df040
unsigned char FUN_008df040_shell::FUN_008df040()
{
    return ((unsigned char*)this)[0x80];
}

struct FUN_004011b0_shell
{
    unsigned int m_BaseFormComponent;  // +0x00
    unsigned int m_Padding;            // +0x04
    unsigned int m_uiFormFlags;        // +0x08
    bool IsFlagSet() const;
};

// @fnv 0x004011b0
bool FUN_004011b0_shell::IsFlagSet() const
{
    return (m_uiFormFlags & 0x10000) ? true : false;
}

struct FUN_00401210_shell
{
    int _pad0;
    int _pad1;
    unsigned int m_uiFormFlags;
    bool HasFlag() const;
};

// @fnv 0x00401210
bool FUN_00401210_shell::HasFlag() const
{
    return (m_uiFormFlags & 0x2000000) ? true : false;
}

struct FUN_00401250_shell
{
    unsigned int m_BaseFormComponent[2];
    unsigned int m_uiFormFlags;
    bool IsFlag200Set();
};

// @fnv 0x00401250
bool FUN_00401250_shell::IsFlag200Set()
{
    return (m_uiFormFlags & 0x200) ? true : false;
}

struct FUN_00484a70_shell
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_00484a70(bool value);
};

// Sets or clears bit 0x80 in m_08 according to value.
// @fnv 0x00484a70
void FUN_00484a70_shell::FUN_00484a70(bool abSet)
{
    if (abSet)
        m_08 |= 0x80;
    else
        m_08 &= ~0x80;
}

struct BSExtraData
{
    virtual ~BSExtraData();
    int _a;
    int _b;
};
struct FUN_004362a0 : BSExtraData
{
    int _c;
    ~FUN_004362a0();
};
// Destructor that calls TESForm::ClearData on the _c member.
// @fnv 0x004362a0
FUN_004362a0::~FUN_004362a0()
{
    ((TESForm*)&_c)->TESForm::ClearData();
}

namespace fnv_004363c0 {
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_004363c0
{
    BSExtraData data;
    int _4;
    int _8;
    int _c;
    ~FUN_004363c0();
};
// @fnv 0x004363c0
FUN_004363c0::~FUN_004363c0()
{
    ((TESForm*)((char*)this + 12))->TESForm::ClearData();
}
}  // namespace fnv_004363c0

namespace fnv_004364e0 {
struct BSExtraData
{
    virtual ~BSExtraData();
    int _04;
    int _08;
};
struct SoundPlaybackHandle
{
    ~SoundPlaybackHandle();
};
struct FUN_004364e0 : BSExtraData
{
    SoundPlaybackHandle m;
    virtual ~FUN_004364e0();
};
// Destructor for a BSExtraData-derived object; destroys its member and the base class.
// @fnv 0x004364e0
FUN_004364e0::~FUN_004364e0()
{}
}  // namespace fnv_004364e0

namespace fnv_00436600 {
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_00436600 : BSExtraData
{
    ~FUN_00436600();
};
// @fnv 0x00436600
FUN_00436600::~FUN_00436600()
{
    ((TESForm*)((char*)this + 12))->TESForm::ClearData();
}
}  // namespace fnv_00436600

namespace fnv_00436720 {
struct BSExtraData
{
    virtual ~BSExtraData();
    int _a;
    int _b;
};
struct FUN_00436720 : BSExtraData
{
    int _f0c;
    ~FUN_00436720();
};
// @fnv 0x00436720
FUN_00436720::~FUN_00436720()
{
    ((TESForm*)&_f0c)->TESForm::ClearData();
}
}  // namespace fnv_00436720

struct FUN_004696f0_shell
{
    void FUN_004696f0(unsigned int value);
};
// @fnv 0x00483c70
void FUN_00483c70_shell::FUN_00483c70()
{
    if (reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
        return;
    if (::fnv_00483370::DAT_011c54c0)
        reinterpret_cast<::NiTMap_S *>((((NiTPointerMap<unsigned int, void*>*)::fnv_00483370::DAT_011c54c0)))->RemoveKey(this->iFormID);
    for (unsigned int iIndex = 0; ms_pAllForms && iIndex < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)ms_pAllForms)))->FUN_0084e3a0())); iIndex++)
    {
        if (*((Arr*)ms_pAllForms)->GetAt(iIndex) == (unsigned int)this)
        {
            ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)ms_pAllForms)->RemoveAt(iIndex);
            break;
        }
    }
    if (g_dataHandler)
        reinterpret_cast<::FUN_004696f0_shell *>((g_dataHandler))->FUN_004696f0(this->iFormID);
}
// @fnv 0x004696f0
void FUN_004696f0_shell::FUN_004696f0(unsigned int value)
{
    unsigned int desired;
    desired = *(unsigned int*)((char*)this + 0x218);
    desired = 0xff;
    if (value && (value >> 0x18) == desired && !((unsigned char*)this)[0x621] &&
        value < *(unsigned int*)((char*)this + 0x208) && (value & (unsigned int)&DAT_00ffffff) > 0x7ff)
        *(unsigned int*)((char*)this + 0x208) = value;
}

template <int N> struct EndianSizeTag
{
};
struct FUN_00470650_shell
{
    void FUN_00470650();
};
// @fnv 0x00470650
void FUN_00470650_shell::FUN_00470650()
{
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)((char*)this + 4)));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)((char*)this + 8)));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)((char*)this + 12)));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)((char*)this + 16)));
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)((char*)this + 20)));
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)((char*)this + 22)));
}

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
// Looks up aiSearchID in the form map and returns the stored TESForm pointer, or 0 if the map is null or has no entry.
// @fnv 0x004839c0
TESForm* FUN_004839c0(unsigned int aiSearchID)
{
    TESForm* pTempForm = 0;
    if (::fnv_00483370::DAT_011c54c0 &&
        reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)::fnv_00483370::DAT_011c54c0)))->FUN_00853130(aiSearchID, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)pTempForm)))
        return pTempForm;
    else
        return 0;
}

struct TESFile_Proxy
{
    TES_RETURN_CODE RunProbe(TESForm* pForm);
};
struct FUN_00483d20_shell : TESForm
{
    unsigned char SaveIfNotTemporary(TESFile* apFile);
};
// @fnv 0x00483d20
unsigned char FUN_00483d20_shell::SaveIfNotTemporary(TESFile* apFile)
{
    TES_RETURN_CODE eRetVal;
    if (reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
        return 0;
    SaveForm();
    eRetVal = ((TESFile_Proxy*)apFile)->RunProbe(this);
    return eRetVal == 0;
}

struct TESFileShell
{
};
struct FUN_00483fc0_shell : TESForm
{
    bool WriteToFile(TESFile* apFile);
};
// @fnv 0x00483fc0
bool FUN_00483fc0_shell::WriteToFile(TESFile* apFile)
{
    if (reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
        return false;
    if (reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
    {
        reinterpret_cast<::fnv_00472e60::TESFile_Standin *>((((TESFileShell*)apFile)))->FUN_00472e60(this);
        reinterpret_cast<::FUN_00473090_cls *>((((TESFileShell*)apFile)))->FUN_00473090();
        return true;
    }
    return AppendForm(apFile);
}

struct Fake84860
{
    int _pad;
    unsigned int _flags;
    virtual void v00()
    {}
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
    virtual void v18(int)
    {}
    void FUN_00484860(bool);
};
// Sets or clears bit 0x400 in _flags according to abQuest, then calls v18(1).
// @fnv 0x00484860
void Fake84860::FUN_00484860(bool abQuest)
{
    if (abQuest)
    {
        _flags |= 0x400;
    }
    else
    {
        _flags &= ~0x400;
    }
    v18(1);
}

struct PC7d
{
    void FUN_00484c20(unsigned int);
};
// If bit 0 of aiFlags is set, calls FUN_00484ce0 on the object at this+8 with 4.
// @fnv 0x00484c20
void PC7d::FUN_00484c20(unsigned int aiFlags)
{
    if (aiFlags & 1)
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)((unsigned int)((char*)this + 8)), 4);
}

struct SGL_Stub
{
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int* apNumericID, int aiSize);
};
// Forwards the numeric ID buffer and its size to the save/load game object's handler.
// @fnv 0x00484d40
void FUN_00484d40_Host::FUN_00484d40(unsigned int* apNumericID, int aiSize)
{
    reinterpret_cast<::FUN_00857aa0 *>((((SGL_Stub*)::g_TESSaveLoadGame)))->ValidateFormIDArray(apNumericID, aiSize);
}

struct BGSSaveFormBuffer
{
};
struct FakeForm
{
    char _pad[8];
    int _v08;
    void SaveIfChanged(BGSSaveFormBuffer*);
};
// If the form buffer reports change flags for bit 1, saves the 4-byte value at _v08 into the buffer.
// @fnv 0x00484d60
void FakeForm::SaveIfChanged(BGSSaveFormBuffer* buffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(((BGSLoadFormBuffer*)buffer)->GetChangeFlags(1)))->FUN_004280f0(1))
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&_v08, 4, 0);
}

struct FUN_00485130_shell
{
    void WarnCopyUnsupported(TESForm* apCopy);
};
struct TESForm_Proxy40e30
{
};
// Logs a warning that copying the given form is unsupported, printing its name and type name.
// @fnv 0x00485130
void FUN_00485130_shell::WarnCopyUnsupported(TESForm* apCopy)
{
    ::FUN_005b5e40();
}

struct Fake440e30
{
};
struct Mid485170
{
    bool FUN_00485170(TESForm*);
};
// Warns that no compare function exists for the form types and returns false.
// @fnv 0x00485170
bool Mid485170::FUN_00485170(TESForm* apCopy)
{
    ::FUN_005b5e40();
    return false;
}

extern void* DAT_011c54cc;
extern int DAT_011c54d0;
struct MyForm
{
    int _00;
    int length;
};
struct Holder : public TESForm
{
    void FUN_00485680();
public:
    void CallElements();
};
// @fnv 0x00485680
void Holder::FUN_00485680()
{
    MyForm* pForm;
    if (reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
        return;
    pForm = (MyForm*)DAT_011c54cc;
    pForm->length = DAT_011c54d0 - 0x18;
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00470650_shell *>((pForm))->FUN_00470650();
}

struct FUN_00485b60
{
    bool FUN_00485be0(unsigned int);
};
// Returns true when the low 24 bits of aiID equal the value returned by FUN_00485bc0, otherwise false.
// @fnv 0x00485be0
bool FUN_00485b60::FUN_00485be0(unsigned int aiID)
{
    if ((aiID & 0x00FFFFFF) != ((unsigned int)(reinterpret_cast<::FUN_00485bc0_class *>(this)->FUN_00485bc0())))
        return false;
    return true;
}

struct Unnamed00486960
{
    void FUN_00486a00();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00486a00, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x00486960
void* Unnamed00486960::DestroyIfFlagged(unsigned int flags)
{
    FUN_00486a00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_0101ca98;
struct MyMap
{
};
struct S_486a60
{
    void* vfptr;
    int unk4;
    void* entries;
    void FUN_00486a60();
};
// @fnv 0x00486a60
void S_486a60::FUN_00486a60()
{
    vfptr = (void*)&DAT_0101ca98;
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(entries);
}

struct TESModel
{
    unsigned int GetModelLength() const;
};
struct FNStub
{
    char const* GetFullName();
};
struct FUN_00487010_shell
{
    void FUN_00487010();
};
// @fnv 0x00487010
void FUN_00487010_shell::FUN_00487010()
{
    if (((TESModel*)this)->GetModelLength())
        ::FUN_004856f0((void *)(0x4C4C5546), (void*)((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)this)))->FUN_00408da0())), (void *)(((TESModel*)this)->GetModelLength() + 1));
}

struct FUN_00549580_shell
{
    bool FUN_00549580() const;
};

// @fnv 0x00549580
bool FUN_00549580_shell::FUN_00549580() const
{
    return (((const TESForm*)this)->m_uiFormFlags & 64) ? true : false;
}

struct FUN_009f87b0_shell
{
    void FUN_009f9720();
    unsigned int m_0x88;
    unsigned int m_0x8c;
};


// @fnv 0x009f9720
void FUN_009f87b0_shell::FUN_009f9720()
{
    reinterpret_cast<::FUN_006796c0_shell *>(this)->FUN_006796c0();
    unsigned int v3 = *(unsigned int*)((char*)this + 0x88);
    if (v3)
        *(unsigned int*)((char*)this + 0x88) = (unsigned int)::FUN_004839c0(v3);
    unsigned int v8c = *(unsigned int*)((char*)this + 0x8c);
    if (v8c)
        *(unsigned int*)((char*)this + 0x8c) = (unsigned int)::FUN_004839c0(v8c);
}

struct FUN_004846e0_shell
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
    virtual void v18(int);
    unsigned int _4;
    unsigned int _8;
    void FUN_004846e0(bool);
};
// @fnv 0x004846e0
void FUN_004846e0_shell::FUN_004846e0(bool abSet)
{
    if (abSet)
        _8 |= 0x4000000;
    else
        _8 &= 0xFBFFFFFF;
    v18(1);
}

namespace fnv_00483720 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct TESFileGroup;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESClimate;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct FormComponentArray
{
    void InitializeFromForm(TESForm*);
    void ClearFormComponentArray();
    void InitializeDataAllComponents();
    void ClearDataAllComponents();
    void CopyComponentData(FormComponentArray*);
    bool AreComponentsEqual(FormComponentArray*);
    void* __vecDelDtor(unsigned int);
    char m_pComponents[152];
};
struct FUN_00483720_shell : public TESForm
{
    void ClearFormData();
};

struct FUN_0047c050
{
    void* m_pComponents[38];
    FUN_0047c050();
    ~FUN_0047c050();
    void InitializeFromForm(TESForm*);
};

// @fnv 0x00483720
void FUN_00483720_shell::ClearFormData()
{
    switch (GetFormType())
    {
    case 0x39: {
        TESObjectCELL* pthiscell = (TESObjectCELL*)this;
        ::ClearString((char*)pthiscell + 0x18);
        ((TESForm*)pthiscell)->TESForm::ClearData();
        break;
    }
    case 0x11:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x49:
    case 0x69:
        TESForm::ClearData();
        break;
    default: {
        FUN_0047c050 components;
        reinterpret_cast<::FormComponentArray *>(&(components))->InitializeFromForm(this);
        reinterpret_cast<::Holder *>(&(components))->CallElements();
        break;
    }
    }
}
}  // namespace fnv_00483720

namespace fnv_00483870 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct TESFileGroup;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESClimate;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct FormComponentArray
{
    void InitializeFromForm(TESForm*);
    void ClearFormComponentArray();
    void InitializeDataAllComponents();
    void ClearDataAllComponents();
    void CopyComponentData(FormComponentArray*);
    bool AreComponentsEqual(FormComponentArray*);
    void* __vecDelDtor(unsigned int);
    char m_pComponents[152];
};
struct FUN_00483870_shell : public TESForm
{
    void FUN_00483870();
};

struct Holder_47c5b0
{
};
struct FUN_0047c050
{
    int m_pComponents[38];
    FUN_0047c050();
    ~FUN_0047c050();
};

// @fnv 0x00483870
void FUN_00483870_shell::FUN_00483870()
{
    switch (GetFormType())
    {
    case 0x39: {
        TESObjectCELL* pthiscell = (TESObjectCELL*)this;
        ((TESForm*)((char*)pthiscell + 0x18))->TESForm::ClearData();
        ((TESForm*)pthiscell)->TESForm::ClearData();
        break;
    }
    case 0x11:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x49:
    case 0x69:
        TESForm::ClearData();
        break;
    default: {
        FUN_0047c050 components;
        reinterpret_cast<::FormComponentArray *>((((FormComponentArray*)&components)))->InitializeFromForm(this);
        reinterpret_cast<::Holder_47c5b0 *>((((Holder_47c5b0*)&components)))->FUN_0047c5b0();
        break;
    }
    }
}
}  // namespace fnv_00483870

namespace fnv_00484730 {
struct TESObjectREFR;
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
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
struct ActorValueInfo : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
    virtual void __vslot_10();
    void SetEnumerated(int, ...);
    char* GetEnumeratedName(int);
    virtual void Save();
    virtual void InitItem();
    virtual bool Load(TESFile*);
    virtual void Copy(TESForm*);
    virtual bool Compare(TESForm*);
    virtual char* GetTextureResourcePath();
    static unsigned int GetActorValueFormID(int);
    static int GetAffectedActorValue(unsigned int);
    char* m_pName;
    char m_cAbbreviation[8];
    unsigned int uFlags;
    int m_iSection;
    int* m_pDerivedValueFunction;
    int* m_pActorValueMapping;
    int* m_pActorValueChangedCallback;
    int m_iEnumeratedValueCount;
    char m_aiEnumeratedValues[60];
    int m_iEnumeratedNameCount;
    char m_apEnumeratedNames[40];
};
struct FUN_00484730_shell : public TESForm
{
    void FUN_00484730(bool);
};

struct Pathing
{
};
struct FormArray
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct TESTopicInfo;
struct NiTLargeArray_TESTopicInfo
{
    TESTopicInfo* RemoveAt(unsigned int);
};

// @fnv 0x00484730
void FUN_00484730_shell::FUN_00484730(bool abAltered)
{
    if (abAltered)
    {
        if (!reinterpret_cast<::FUN_00460340_shell *>((((Pathing*)this)))->FUN_00460340() && !reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0() && ms_pAllForms)
        {
            bool bAddToList = true;
            for (unsigned int iIndex = 0; iIndex < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)ms_pAllForms)))->FUN_0084e3a0())); iIndex++)
            {
                if (*((Arr*)ms_pAllForms)->GetAt(iIndex) == (unsigned int)this)
                {
                    bAddToList = false;
                    break;
                }
            }
            if (bAddToList)
            {
                reinterpret_cast<::FormArray *>((((FormArray*)ms_pAllForms)))->AddElement((void **)&(const void *const &)((void*)this));
            }
        }
        this->m_uiFormFlags |= 2;
    }
    else
    {
        if (reinterpret_cast<::FUN_00460340_shell *>((((Pathing*)this)))->FUN_00460340() && ms_pAllForms)
        {
            for (unsigned int iIndex = 0; iIndex < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)ms_pAllForms)))->FUN_0084e3a0())); iIndex++)
            {
                if (*((Arr*)ms_pAllForms)->GetAt(iIndex) == (unsigned int)this)
                {
                    ((NiTLargeArray_TESTopicInfo*)ms_pAllForms)->RemoveAt(iIndex);
                    break;
                }
            }
        }
        this->m_uiFormFlags &= ~2u;
    }
}
}  // namespace fnv_00484730

struct BGSSaveFormBuffer;
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Save(void*);
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
struct BGSClipRoundsForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetClipRounds(TESForm*);
    int GetClipRounds();
    void SetFormClipRounds(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucClipRounds;
    char _pad_5[3];
};
struct TESUsesForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetFormUses(TESForm*);
    int GetFormUses();
    void SetFormUses(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucUses;
    char _pad_5[3];
};
struct TESQualityForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned char GetFormQuality(TESForm*);
    unsigned char GetFormQuality();
    void SetFormQuality(unsigned char);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFormQuality;
    char _pad_5[3];
};
struct TESWeightForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static float GetWeightForForm(TESForm*, bool);
    void SetFormWeight(float);
    void* __vecDelDtor(unsigned int);
    float fWeight;
};
struct FUN_00486620_shell : public TESForm
{
    unsigned int FUN_00486620();
};

struct TESAttackDamageForm : public BaseFormComponent
{
    virtual void InitializeComponent();
};
struct TESHealthForm : public BaseFormComponent
{
    virtual void InitializeComponent();
};
struct FUN_009d2510_shell
{
    unsigned int FUN_009d2510();
};

// Sums the save sizes contributed by the form's Uses, Value, Health, Weight, Quality, AttackDamage, Attributes and ClipRounds components.
// @fnv 0x00486620
unsigned int FUN_00486620_shell::FUN_00486620()
{
    TESAttributes* pAttributes;
    BGSClipRoundsForm* pClipRounds;
    TESUsesForm* pUses;
    TESQualityForm* pQuality;
    TESWeightForm* pWeight;
    TESAttackDamageForm* pAttack;
    TESValueForm* pValue;
    unsigned int uiSaveSize;
    TESHealthForm* pHealth;
    pUses = dynamic_cast<TESUsesForm*>((TESForm*)this);
    pValue = dynamic_cast<TESValueForm*>((TESForm*)this);
    pHealth = dynamic_cast<TESHealthForm*>((TESForm*)this);
    pWeight = dynamic_cast<TESWeightForm*>((TESForm*)this);
    pQuality = dynamic_cast<TESQualityForm*>((TESForm*)this);
    pAttack = dynamic_cast<TESAttackDamageForm*>((TESForm*)this);
    pAttributes = dynamic_cast<TESAttributes*>((TESForm*)this);
    pClipRounds = dynamic_cast<BGSClipRoundsForm*>((TESForm*)this);
    uiSaveSize = 0;
    if (pUses)
        uiSaveSize += 1;
    if (pValue)
        uiSaveSize += 4;
    if (pHealth)
        uiSaveSize += 4;
    if (pWeight)
        uiSaveSize += 4;
    if (pQuality)
        uiSaveSize += 4;
    if (pAttack)
        uiSaveSize += 2;
    if (pAttributes)
        uiSaveSize += ((FUN_009d2510_shell*)pAttributes)->FUN_009d2510();
    if (pClipRounds)
        uiSaveSize += 1;
    return uiSaveSize;
}

struct NiTPointerMapRemoveAll
{
};
struct BSTCaseInsensitiveStringMapRemoveAll
{
};
struct FUN_00863db0_class
{
    void ClearItems();
};

// @fnv 0x00483b80
void FUN_00483b80()
{
    if (::fnv_00483370::DAT_011c54c0)
    {
        reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMapRemoveAll*)::fnv_00483370::DAT_011c54c0)))->FUN_00438af0();
        delete ::fnv_00483370::DAT_011c54c0;
        ::fnv_00483370::DAT_011c54c0 = 0;
    }
    if ((*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8)))
    {
        reinterpret_cast<::FUN_00438af0_Class *>((((BSTCaseInsensitiveStringMapRemoveAll*)(*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8)))))->FUN_00438af0();
        delete (*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8));
        (*reinterpret_cast<::BSTCaseInsensitiveStringMap< ::TESForm *> * *>(&::DAT_011c54c8)) = 0;
    }
    if (TESForm::ms_pAllForms)
    {
        ((FUN_00863db0_class*)TESForm::ms_pAllForms)->ClearItems();
        delete TESForm::ms_pAllForms;
        TESForm::ms_pAllForms = 0;
    }
}

namespace fnv_00485340 {
struct ArrSI
{
};
struct Pathing
{
};
struct FUN_00485340_shell : public TESForm
{
    void FUN_00485340(BaseFormComponent* apCopyFC);
};
// Copies the form type, flags and a pathing state from apCopyFC into this form, marking it altered when the pathing state differs.
// @fnv 0x00485340
void FUN_00485340_shell::FUN_00485340(BaseFormComponent* apCopyFC)
{
    TESForm* pCopy = dynamic_cast<TESForm*>(apCopyFC);
    if (!pCopy)
        return;
    if (reinterpret_cast<::FUN_00460340_shell *>((((Pathing*)this)))->FUN_00460340() != reinterpret_cast<::FUN_00460340_shell *>((((Pathing*)pCopy)))->FUN_00460340())
        SetAltered(reinterpret_cast<::FUN_00460340_shell *>((((Pathing*)pCopy)))->FUN_00460340());
    this->m_ucFormType = pCopy->GetFormType();
    m_uiFormFlags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)pCopy)))->GetName())) & 0xffffbfff | (m_uiFormFlags & 0x4000);
}
}  // namespace fnv_00485340

namespace fnv_00436180 {
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_00436180 : BSExtraData
{
    virtual ~FUN_00436180();
};
// Destructor that calls ClearData on the object at offset 0xc.
// @fnv 0x00436180
FUN_00436180::~FUN_00436180()
{
    reinterpret_cast<::TESForm *>((((FUN_00436180*)((char*)this + 0xc))))->ClearData();
}
}  // namespace fnv_00436180

struct FUN_00484580_shell : TESForm
{
    void FUN_00484580(bool set);
};

struct TESSaveLoadGameLoader
{
};

// @fnv 0x00484580
void FUN_00484580_shell::FUN_00484580(bool set)
{
    if (set)
    {
        if (!reinterpret_cast<::FUN_0047c850 *>((reinterpret_cast<TESSaveLoadGameLoader*>(::g_TESSaveLoadGame)))->EvaluateCondition())
            MarkAsModified(0x200000);
        this->m_uiFormFlags |= 0x2000;
    }
    else
    {
        if (!reinterpret_cast<::FUN_0047c850 *>((reinterpret_cast<TESSaveLoadGameLoader*>(::g_TESSaveLoadGame)))->EvaluateCondition())
            MarkAsUnmodified(0x200000);
        this->m_uiFormFlags &= ~0x2000;
    }
}

struct GroupEntry
{
    unsigned int form;
    unsigned int length;
    unsigned int flags;
    unsigned int iFormID;
    unsigned int m_uiVersionControlInfo;
    unsigned short m_usFormVersion;
    unsigned short m_usHeaderUnknown;
};
struct GroupData
{
    GroupEntry Data;
};
struct FUN_00485530_shell : TESForm
{
    void InitGroupForm(GroupEntry* apOutGroupFORM, GroupData* apParentGroup);
};
// @fnv 0x00485530
void FUN_00485530_shell::InitGroupForm(GroupEntry* apOutGroupFORM, GroupData* apParentGroup)
{
    if (apOutGroupFORM && !apParentGroup)
    {
        apOutGroupFORM->form = ::fnv_00543df0::kGroupFormType;
        apOutGroupFORM->iFormID = 0;
        apOutGroupFORM->flags = *(unsigned int*)(0x1187008 + GetFormType() * 12);
        apOutGroupFORM->length = 0;
        apOutGroupFORM->m_uiVersionControlInfo = 0;
        apOutGroupFORM->m_usFormVersion = 0;
        apOutGroupFORM->m_usHeaderUnknown = 0;
    }
}

int DAT_0101ca98;

struct FUN_00486990_shell
{
    int* pVT;
    int iCount;
    void* pBuffer;
    int iMax;
    FUN_00486990_shell(int iSize);
};

// Sets the vtable, stores iSize as the count, allocates iSize*4 bytes zeroed into pBuffer, and sets iMax to 0.
// @fnv 0x00486990
FUN_00486990_shell::FUN_00486990_shell(int iSize)
{
    pVT = &DAT_0101ca98;
    iCount = iSize;
    iMax = 0;
    int iByteCount = iCount << 2;
    pBuffer = ::FUN_00aa1070(iByteCount);
    memset(pBuffer, 0, iCount << 2);
}

namespace fnv_00486a00 {
struct S_486a60
{
    void FUN_00486a60();
    virtual ~S_486a60();
};
struct FUN_00486a00 : S_486a60
{
    ~FUN_00486a00();
};
// @fnv 0x00486a00
FUN_00486a00::~FUN_00486a00()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}
}  // namespace fnv_00486a00

namespace fnv_004855a0 {
class ArrSI : public TESForm
{
  public:
    void FUN_004855a0();
};


struct FormEnumEntry
{
    unsigned int iFormString;
    unsigned char padding[8];
};



// @fnv 0x004855a0
void ArrSI::FUN_004855a0()
{
    FormRecordHeader* pForm;

    if (reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
        return;

    ::DAT_011c54d0 = sizeof(FormRecordHeader);
    ::DAT_011c54cc = ::FUN_00401000(::DAT_011c54d0);
    pForm = static_cast<FormRecordHeader*>(::DAT_011c54cc);
    pForm->flags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    if (GetFormType() != 1)
        pForm->flags = pForm->flags & 0x30032FE0;
    pForm->form = (*reinterpret_cast<fnv_004855a0::FormEnumEntry (*)[]>(&::DAT_01187008))[GetFormType()].iFormString;
    pForm->iFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    pForm->length = 0;
    pForm->m_usFormVersion = ::FUN_00470bb0();
    pForm->m_uiVersionControlInfo = 0;
    pForm->m_usHeaderUnknown = 0;
    Unk_37();
}
}  // namespace fnv_004855a0

void* DAT_011c54cc;
int DAT_011c54d0;


struct FUN_004141e0_class
{
    unsigned int chunk;
    unsigned short length;
    void FUN_004141e0();
};

// @fnv 0x00485990
void AppendChunk(unsigned int chunk, const void* data, unsigned int size)
{
    unsigned int offset;
    {
        unsigned short length = static_cast<unsigned short>(size);
        if (size > 0xffff)
        {
            ::FUN_00485910(0x58585858, size);
            length = 0;
        }

        {
            unsigned char* chunkData;
            {
                unsigned char* dataDestination;
                {
                    FUN_004141e0_class* newChunk;

                    offset = DAT_011c54d0;
                    DAT_011c54d0 = DAT_011c54d0 + size + 6;
                    DAT_011c54cc = ::Reallocate(DAT_011c54cc, DAT_011c54d0);

                    newChunk =
                        reinterpret_cast<FUN_004141e0_class*>(static_cast<unsigned char*>(DAT_011c54cc) + offset);
                    chunkData = static_cast<unsigned char*>(DAT_011c54cc) + offset;

                    newChunk->chunk = chunk;
                    newChunk->length = length;

                    if (::FUN_00401500())
                        newChunk->FUN_004141e0();

                    __memcpy(chunkData, newChunk, 6);

                    dataDestination = static_cast<unsigned char*>(DAT_011c54cc) + offset + 6;
                    __memcpy(dataDestination, data, size);
                }
            }
        }
    }
}

namespace fnv_00485a70 {
struct FUN_004141e0_class
{
    unsigned char _padding[3];

};

struct CHUNK : public FUN_004141e0_class
{
    unsigned short length;
};

struct FUN_00485a70_class
{
    bool FUN_00485a70(CHUNK* apChunk, unsigned short asExpandSize);
};


void* DAT_011c54cc;
int DAT_011c54d0;

// @fnv 0x00485a70
bool FUN_00485a70_class::FUN_00485a70(CHUNK* apChunk, unsigned short asExpandSize)
{
    bool bendian = false;
    bendian = ((bool)(::FUN_00401500()));

    if (bendian)
        reinterpret_cast<::FUN_004141e0_class *>((apChunk))->FUN_004141e0();

    if ((apChunk->length == 0 && asExpandSize == 0) || (apChunk->length + asExpandSize > 0xffff))
    {
        if (bendian)
            reinterpret_cast<::FUN_004141e0_class *>((apChunk))->FUN_004141e0();
        return false;
    }

    apChunk->length += asExpandSize;

    if (bendian)
        reinterpret_cast<::FUN_004141e0_class *>((apChunk))->FUN_004141e0();

    ::DAT_011c54d0 += asExpandSize;
    ::DAT_011c54cc = ::Reallocate(::DAT_011c54cc, ::DAT_011c54d0);
    return true;
}
}  // namespace fnv_00485a70

class FUN_00484a10_cls : public TESForm
{
  public:
    void SetFlag40(bool set);
};

// Sets or clears bit 0x40 in the form's flags field and marks the form as modified.
// @fnv 0x00484a10
void FUN_00484a10_cls::SetFlag40(bool set)
{
    set ? (m_uiFormFlags |= 0x40) : (m_uiFormFlags &= 0xffffffbf);
    MarkAsModified(1);
}

struct FUN_0047c050
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
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
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    FUN_0047c050();
    ~FUN_0047c050();
};
struct FormCloneOperation
{
    void FUN_004851b0(void* targetForm);
};
// @fnv 0x004851b0
void FormCloneOperation::FUN_004851b0(void* targetForm)
{
    FUN_0047c050 z;
    FUN_0047c050 a;
    reinterpret_cast<::FormComponentArray *>(&(z))->InitializeFromForm((::TESForm *)(void *)(this));
    reinterpret_cast<::FormComponentArray *>(&(a))->InitializeFromForm((::TESForm *)(targetForm));
    reinterpret_cast<::FUN_0047c600_cls *>(&(z))->FUN_0047c600((::FormComponentArray *)(::FUN_0047c050 *)(&a));
}

class TESForm;

struct FUN_00509540_obj
{
    FUN_00509540_obj();
    ~FUN_00509540_obj();
    bool FUN_00485270(TESForm* apArg);
    int unk00;
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
    int unk30;
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
};

// @fnv 0x00485270
bool FUN_00509540_obj::FUN_00485270(TESForm* apArg)
{
    if (apArg == 0)
        return true;
    FUN_00509540_obj p;
    FUN_00509540_obj a;
    reinterpret_cast<::FormComponentArray *>(&(p))->InitializeFromForm((::TESForm *)(void *)(this));
    reinterpret_cast<::FormComponentArray *>(&(a))->InitializeFromForm((::TESForm *)(apArg));
    return reinterpret_cast<::FUN_0047c670_shell *>(&(p))->CompareComponents((::FormComponentArray *)(::FUN_00509540_obj *)(&a));
}

struct CompareForm : TESForm
{
    bool FUN_004853e0(BaseFormComponent* rhs);
};

// @fnv 0x004853e0
bool CompareForm::FUN_004853e0(BaseFormComponent* apOther)
{
    TESForm* otherForm = dynamic_cast<TESForm*>(apOther);
    if (!otherForm)
        return true;

    if (m_ucFormType != otherForm->GetFormType())
        return true;

    if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning() || reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CompareForm*>(otherForm)))->HasNameForWarning())
    {
        if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning() != reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CompareForm*>(otherForm)))->HasNameForWarning())
            return true;
        else
        {
            if (::FUN_00404dc0(GetName(), otherForm->GetName()))
                return true;
        }
    }

    unsigned int flagsA = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    unsigned int flagsB = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<CompareForm*>(otherForm)))->GetName()));
    flagsA &= 0xffffbff4;
    flagsB &= 0xffffbff4;
    if (flagsA != flagsB)
        return true;
    return false;
}

struct FUN_004867a0_vbase
{
    virtual void v00(void* a);
    virtual void v01(void* a);
    virtual void v02(void* a);
    virtual void v03(void* a);
    virtual void v04(void* a);
    virtual void v05(void* a);
    virtual void v06(void* a);
    virtual void v07(void* a);
    virtual void v08(void* a);
    virtual void v09(void* a);
    virtual void v0A(void* a);
    virtual void v0B(void* a);
    virtual void v0C(void* a);
    virtual void v0D(void* a);
    virtual void v0E(void* a);
    virtual void v0F(void* a);
    virtual void v10(void* a);
    virtual void v11(void* a);
    virtual void v12(void* a);
    virtual void v13(void* a);
    virtual void v14(void* a);
    virtual void v15(void* a);
    virtual void v16(void* a);
    virtual void v17(void* a);
    virtual void v18(void* a);
    virtual void v19(void* a);
    virtual void v1A(void* a);
    virtual void v1B(void* a);
    virtual void v1C(void* a);
    virtual void v1D(void* a);
    virtual void v1E(void* a);
    virtual void v1F(void* a);
    virtual void v20(void* a);
    virtual void v21(void* a);
    virtual void v22(void* a);
    virtual void v23(void* a);
    virtual void v24(void* a);
    virtual void v25(void* a);
    virtual void v26(void* a);
    virtual void v27(void* a);
    virtual void v28(void* a);
    virtual void v29(void* a);
    virtual void v2A(void* a);
    virtual void v2B(void* a);
    virtual void v2C(void* a);
    virtual void v2D(void* a);
    virtual void v2E(void* a);
    virtual void v2F(void* a);
    virtual void v30(void* a);
    virtual void v31(void* a);
    virtual void v32(void* a);
    virtual void v33(void* a);
    virtual void v34(void* a);
    virtual void v35(void* a);
    virtual void v36(void* a);
    virtual void v37(void* a);
    virtual void v38(void* a);
    virtual void v39(void* a);
    virtual void v3A(void* a);
    virtual void v3B(void* a);
    virtual void v3C(void* a);
    virtual void v3D(void* a);
    virtual void v3E(void* a);
    virtual void v3F(void* a);
    virtual void v40(void* a);
    virtual void v41(void* a);
    virtual void v42(void* a);
    virtual void v43(void* a);
    virtual void v44(void* a);
    virtual void v45(void* a);
    virtual void v46(void* a);
    virtual void v47(void* a);
    virtual void v48(void* a);
    virtual void v49(void* a);
    virtual void v4A(void* a);
    virtual void v4B(void* a);
    virtual void v4C(void* a);
    virtual void v4D(void* a);
    virtual void v4E(void* a);
    virtual void v4F(void* a);
};

struct FUN_004867a0_holder
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_004867a0_holder(void* p);
    ~FUN_004867a0_holder();
};

struct FUN_004867a0_cls : FUN_004867a0_vbase
{
    void* GetA();
    void* FUN_004867a0(void* unused, void* arg);
};

struct FUN_004867a0_arg
{
};


// @fnv 0x004867a0
void* FUN_004867a0_cls::FUN_004867a0(void* unused, void* arg)
{
    FUN_004867a0_vbase* obj = (FUN_004867a0_vbase*)((void *)(::TESDataHandler::CreateFormForType((unsigned char)(GetA()))));
    if (obj != 0)
    {
        FUN_004867a0_holder holder(((void *)(reinterpret_cast<::FUN_00401280_Class *>(this)->FUN_00401280())));
        this->v4D("");
        obj->v42(this);
        if (((void *)(::FUN_00559450((int *)&(holder)))) != 0)
        {
            this->v4D(((void *)(::FUN_00559450((int *)&(holder)))));
        }
    }
    if (obj != 0 && arg != 0)
    {
        reinterpret_cast<::FUN_00844700_Class *>((((FUN_004867a0_arg*)arg)))->FUN_00844700((unsigned int)(this), (unsigned int)(obj));
    }
    return obj;
}

struct S4868f0_host
{
    void FUN_004868f0(unsigned int a);
};


// @fnv 0x004868f0
void S4868f0_host::FUN_004868f0(unsigned int a)
{
    ::FUN_00406f60((::FUN_00406f90_this *)(a), "%s Form '%s' (%08X)", ((unsigned int)(reinterpret_cast<::FUN_00440e30_This *>(this)->FUN_00440e30())), ((unsigned int)(reinterpret_cast<::FUN_00401280_Class *>(this)->FUN_00401280())), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())));
}

extern char DAT_011841cc;
extern "C" void* __cdecl FUN_00ec43fb(void* key, int option, const void* source, const void* destination, int flags);

struct ActionObject
{
    void** methods;
};

typedef void(* ActionHandler)(ActionObject* self, int target, void* data, unsigned char mode);

struct ActionCaller
{
    bool InvokeAction(int target, void* key, unsigned char mode, int unused, void* data);
};

// @fnv 0x0050f670
bool ActionCaller::InvokeAction(int target, void* key, unsigned char mode, int unused, void* data)
{
    ActionObject* object = (ActionObject*)FUN_00ec43fb(key, 0, &DAT_011841cc, &DAT_011846d4, 0);
    if (object != 0 && target != 0)
    {
        void* savedData = data;
        ((ActionHandler)object->methods[244])(object, target, savedData, mode);
        return true;
    }
    return false;
}

struct FUN_0050f780_Class
{
    void ForwardTo008d0600(int arg1, unsigned char arg2);
};

// @fnv 0x0050f780
void FUN_0050f780_Class::ForwardTo008d0600(int arg1, unsigned char arg2)
{
    reinterpret_cast<::FUN_008d0600_s *>(this)->FUN_008d0600(arg1, arg2);
}

void __cdecl AppendChunk(unsigned int record, const void* data, unsigned int bytes);
struct Record
{
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
};
struct FUN_005e9620_class
{
    unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
    void FUN_005e9620(unsigned char value);
};
// @fnv 0x005e9620
void FUN_005e9620_class::FUN_005e9620(unsigned char value)
{
    Record data;
    data.field2 = unk05;
    data.field1 = unk04;
    data.field0 = value;
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::TESForm *>(&(data))->ClearData();
    }
    AppendChunk(0x454b5250, &data, 3);
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::TESForm *>(&(data))->ClearData();
    }
}


struct C67ACD0Package
{
    int unk00;

    const char* GetTypeName();
};

// @fnv 0x0067acd0
const char* C67ACD0Package::GetTypeName()
{
    return g_packageTypeNames[reinterpret_cast<struct ::FUN_0041ca90 *>(this)->get()];
}

struct CompressionRecord
{
    unsigned int type;
    unsigned int size;
    unsigned int flags;
    unsigned int formID;
    unsigned int versionControl;
    unsigned int version;
};

// Local roles: j = write cursor, e = output buffer, c = record header,
// k = new record size, ba = compressed buffer, b = stored original size,
// q = input size, eb = compression capacity, f = compressed size.
// @fnv 0x00483d70
void CompressSaveLoadRecord()
{
    if (DAT_011c54cc && (unsigned int)DAT_011c54d0 > 24)
    {
        CompressionRecord* c = (CompressionRecord*)DAT_011c54cc;
        if (((bool)(::FUN_00401500())))
            ((FUN_00470650_shell*)c)->FUN_00470650();
        if (c->flags & 0x40000)
        {
            if (((bool)(::FUN_00401500())))
                ((FUN_00470650_shell*)c)->FUN_00470650();
            return;
        }
        unsigned int q = DAT_011c54d0 - 24;
        unsigned char* j = (unsigned char*)DAT_011c54cc;
        j += 24;
        unsigned int eb = q * 2;
        unsigned char* ba = new unsigned char[eb];
        unsigned int f = (unsigned int)fileformat::Deflate(std::span<const std::byte>((const std::byte*)j, q),
                                                           std::span<std::byte>((std::byte*)ba, eb));
        if (f == 0)
        {
            ::FUN_005b5e40();
            delete[] ba;
            return;
        }
        unsigned int k = f + 28;
        unsigned char* e = new unsigned char[k];
        j = e;
        c->flags |= 0x40000;
        c->size = k - 24;
        if (((bool)(::FUN_00401500())))
            ((FUN_00470650_shell*)c)->FUN_00470650();
        __memcpy(j, c, 24);
        j += 24;
        unsigned int b = q;
        if (((bool)(::FUN_00401500())))
            ::FUN_00401080((int*)&b);
        __memcpy(j, &b, 4);
        j += 4;
        __memcpy(j, ba, f);
        ::FUN_00401030(DAT_011c54cc);
        DAT_011c54cc = e;
        DAT_011c54d0 = k;
        delete[] ba;
    }
}

struct TESFormSortProxy : public TESForm
{
    bool IsLessThan(TESForm* apOther);
};

// Compares this form's remapped form-type rank against another form's and returns true when this rank is lower.
// @fnv 0x00484020
bool TESFormSortProxy::IsLessThan(TESForm* apOther)
{
    unsigned int uiThisRank;
    unsigned int uiOtherRank;
    uiOtherRank = apOther->GetFormType();
    uiThisRank = GetFormType();
    switch (uiOtherRank)
    {
    case 0x67:
        uiOtherRank = 0x137;
        break;
    case 0x6C:
        uiOtherRank = 0x138;
        break;
    case 0x73:
        uiOtherRank = 0x139;
        break;
    case 0x74:
        uiOtherRank = 0x13A;
        break;
    default:
        uiOtherRank *= 10;
        break;
    }
    switch (uiThisRank)
    {
    case 0x67:
        uiThisRank = 0x137;
        break;
    case 0x6C:
        uiThisRank = 0x138;
        break;
    case 0x73:
        uiThisRank = 0x139;
        break;
    case 0x74:
        uiThisRank = 0x13A;
        break;
    default:
        uiThisRank *= 10;
        break;
    }
    if (uiThisRank < uiOtherRank)
        return true;
    return false;
}

struct FormMap
{
};
struct DebugTarget
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
    virtual void GetDebugInfo(BSStringT<char>*);
};
extern const char DAT_0101c9c8[];
void __cdecl FUN_00461300();
struct FUN_00485c10_shell : public TESForm
{
    void FUN_00485c10(unsigned int id, bool notify);
};
// @fnv 0x00485c10
void FUN_00485c10_shell::FUN_00485c10(unsigned int id, bool notify)
{
    if (id == iFormID)
        return;
    if (!reinterpret_cast<::FUN_004077c0_shell *>(this)->FUN_004077c0())
    {
        DebugTarget* debug = 0;
        if (iFormID != 0)
        {
            reinterpret_cast<::NiTMap_S *>((reinterpret_cast<FormMap*>(::fnv_00483370::DAT_011c54c0)))->RemoveKey(iFormID);
        }
        debug = 0;
        if (debug != 0)
        {
            FUN_00461300();
            BSStringT<char> details;
            debug->GetDebugInfo(&details);
            ::FUN_005b5e40();
            (*reinterpret_cast<unsigned char *>(&::DAT_011c54b9)) = 1;
        }
        else if (notify && iFormID != 0)
        {
            reinterpret_cast<::FUN_004696f0_shell *>((g_dataHandler))->FUN_004696f0(iFormID);
        }
        if (id != 0)
        {
            reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<FormMap*>(::fnv_00483370::DAT_011c54c0)))->FUN_00844700(id, (unsigned int)(this));
        }
    }
    iFormID = id;
}

struct SDEndianTag
{
};


struct SDIntComponent
{
};

struct SDDamageComponent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual short GetAttackDamage();
};

struct SDSaveForm : TESForm
{
    void FUN_00485e20(const void* apData, unsigned int auiSize);
};
// @fnv 0x00485e00
void FUN_00485e00_shell::FUN_00485e00()
{
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20((const void *)(0), 0);
}

// @fnv 0x00485e20
void SDSaveForm::FUN_00485e20(const void* apData, unsigned int auiSize)
{
    if (auiSize > 0xffff)
    {
        ::FUN_005b5e40();
        return;
    }

    unsigned short usSize9 = 0;
    int _iOffset = reinterpret_cast<::FUN_00473080_Class *>(this)->GetGlobalValue();
    ::AppendChunk('ATAD', apData, auiSize);
    char* pStart = ((char *)(reinterpret_cast<::FUN_00473070Class *>(this)->GetGlobalPointer())) + _iOffset;

    TESUsesForm* pUses7 = dynamic_cast<TESUsesForm*>(static_cast<TESForm*>(this));
    TESValueForm* pValueTmp = dynamic_cast<TESValueForm*>(static_cast<TESForm*>(this));
    TESHealthForm* pHealth5 = dynamic_cast<TESHealthForm*>(static_cast<TESForm*>(this));
    TESWeightForm* pWeight4 = dynamic_cast<TESWeightForm*>(static_cast<TESForm*>(this));
    TESQualityForm* pQuality2 = dynamic_cast<TESQualityForm*>(static_cast<TESForm*>(this));
    TESAttackDamageForm* pDamage2 = dynamic_cast<TESAttackDamageForm*>(static_cast<TESForm*>(this));
    TESAttributes* kPAttributes = dynamic_cast<TESAttributes*>(static_cast<TESForm*>(this));
    BGSClipRoundsForm* pClipRounds3 = dynamic_cast<BGSClipRoundsForm*>(static_cast<TESForm*>(this));

    if (pUses7)
        usSize9 += 1;
    if (pValueTmp)
        usSize9 += 4;
    if (pHealth5)
        usSize9 += 4;
    if (pWeight4)
        usSize9 += 4;
    if (pQuality2)
        usSize9 += 4;
    if (pDamage2)
        usSize9 += 2;
    if (kPAttributes)
        usSize9 += reinterpret_cast<::FUN_009d2510_shell *>((kPAttributes))->FUN_009d2510();
    if (pClipRounds3)
        usSize9 += 1;

    if (!usSize9)
        return;

    _iOffset = reinterpret_cast<::FUN_00473080_Class *>(this)->GetGlobalValue();
    if (!reinterpret_cast<::fnv_00485a70::FUN_00485a70_class *>(this)->FUN_00485a70((::fnv_00485a70::CHUNK *)(pStart), usSize9))
        return;

    char* pWrite2 = ((char *)(reinterpret_cast<::FUN_00473070Class *>(this)->GetGlobalPointer())) + _iOffset;
    if (pUses7)
    {
        *pWrite2 = pUses7->GetFormUses();
        pWrite2 += 1;
    }
    if (pValueTmp)
    {
        *(int*)pWrite2 = ((int)(reinterpret_cast<::Callees *>((((SDIntComponent*)pValueTmp)))->FUN_00726070()));
        if (((bool)(::FUN_00401500())))
            ::FUN_00401080((int*)pWrite2);
        pWrite2 += 4;
    }
    if (pHealth5)
    {
        *(int*)pWrite2 = ((int)(reinterpret_cast<::Callees *>((((SDIntComponent*)pHealth5)))->FUN_00726070()));
        if (((bool)(::FUN_00401500())))
            ::FUN_00401080((int*)pWrite2);
        pWrite2 += 4;
    }
    if (pWeight4)
    {
        float fWeight = reinterpret_cast<::TimeoutTimer *>((pWeight4))->FUN_006b9130();
        if (((bool)(::FUN_00401500())))
            ::FUN_00401080((int *)(float *)(&fWeight));
        ::__memcpy(pWrite2, &fWeight, 4);
        pWrite2 += 4;
    }
    if (pQuality2)
    {
        float fQuality4 = ((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((pQuality2))->IsPatrolling()));
        if (((bool)(::FUN_00401500())))
            ::FUN_00401080((int *)(float *)(&fQuality4));
        ::__memcpy(pWrite2, &fQuality4, 4);
        pWrite2 += 4;
    }
    if (pDamage2)
    {
        *(short*)pWrite2 = ((SDDamageComponent*)pDamage2)->GetAttackDamage();
        if (((bool)(::FUN_00401500())))
            ::FUN_00407a90((short*)pWrite2);
        pWrite2 += 2;
    }
    if (kPAttributes)
        pWrite2 += reinterpret_cast<::FUN_00480100_shell *>((kPAttributes))->FUN_00480100(pWrite2);
    if (pClipRounds3)
    {
        *pWrite2 = pClipRounds3->GetClipRounds();
        pWrite2 += 1;
    }
}

namespace fnv_00483370 {
extern char DAT_0101c748, DAT_0101c6e0, DAT_0101c6a0;
extern bool DAT_011c54b8;
struct TypeInfo
{
    unsigned char unk00;
    const char* unk04;
    unsigned int unk08;
};
struct TESDataHandler
{
};
struct BaseFC
{
    virtual void slot();
    BaseFC();
};
struct FUN_00483370 : BaseFC
{
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
    virtual void slot();
    FUN_00483370();
};
// @fnv 0x00483370
FUN_00483370::FUN_00483370()
{
    if (::DAT_011c54bc == 0)
        ::TESForm::InitializeFormIDMap();
    ::DAT_011c54bc++;
    if (!DAT_011c54b8)
    {
        bool bInvalid = false;
        ::FUN_0043b2b0(true);
        for (unsigned int i = 0; i < 121; ++i)
        {
            (*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[i].unk08 = (*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[i].unk04[0] | ((*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[i].unk04[1] << 8) |
                                    ((*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[i].unk04[2] << 16) | ((*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[i].unk04[3] << 24);
            if ((*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[i].unk00 != i)
            {
                ::FUN_005b5e40();
                bInvalid = true;
            }
            for (unsigned int j = 0; j < 121; ++j)
            {
                if (i != j && (*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[i].unk08 == (*reinterpret_cast<fnv_00483370::TypeInfo (*)[]>(&::ChangeReport::DAT_01187000))[j].unk08)
                {
                    ::FUN_005b5e40();
                    bInvalid = true;
                }
            }
        }
        ::FUN_0043b2b0(false);
        if (bInvalid)
            ::FUN_0040fbe0();
        DAT_011c54b8 = true;
    }
    m_ucFormType = 0;
    m_uiFormFlags = 8;
    iFormID = 0;
    if ((*reinterpret_cast<::fnv_00483370::TESDataHandler * *>(&::g_dataHandler)) && !reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_00483370::TESDataHandler * *>(&::g_dataHandler))))->LoadDescriptionForForm())
    {
        iFormID = reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_00483370::TESDataHandler * *>(&::g_dataHandler))))->GetNextID();
        if (((::TESFile *)(::GetField20C((char*)(*reinterpret_cast<::fnv_00483370::TESDataHandler * *>(&::g_dataHandler))))))
            ((TESForm*)this)->SetFile(((::TESFile *)(::GetField20C((char*)(*reinterpret_cast<::fnv_00483370::TESDataHandler * *>(&::g_dataHandler))))));
        if (iFormID <= 0x7ff)
            reinterpret_cast<::FUN_00485c10_shell *>((((TESForm*)this)))->FUN_00485c10(0x800, true);
    }
    if (iFormID)
        reinterpret_cast<::FUN_00844700_Class *>((DAT_011c54c0))->FUN_00844700(iFormID, (unsigned int)((TESForm*)this));
}
}  // namespace fnv_00483370


struct BoolBox
{
    bool value;
};

struct Slot4
{
    unsigned int value;
};

// When FUN_00401500() is true, copies arg1 into a temporary array, calls FUN_00401080 on each element with false, then appends it.
// @fnv 0x00485750
void __cdecl FUN_00485750(void* apDestination, void* apSource, void* aiCount)
{
    Slot4* p4;
    unsigned int bytes7 = (unsigned int)aiCount * 4;

    if (((bool)(::FUN_00401500())))
    {
        unsigned int i;
        p4 = new Slot4[(unsigned int)aiCount];
        ::__memcpy(p4, apSource, bytes7);
        for (i = 0; i < (unsigned int)aiCount; ++i)
        {

            ::FUN_00401080((int *)(void *)(&p4[i]));
        }
        ::AppendChunk((unsigned int)(apDestination), p4, (unsigned int)((void*)bytes7));
        delete[] p4;
    }
    else
    {
        ::AppendChunk((unsigned int)(apDestination), apSource, (unsigned int)((void*)bytes7));
    }
}

namespace fnv_0069da40 {

template <int N> struct EndianSizeTag
{
};

class DA00694f80
{
  public:
    DA00694f80();
    virtual ~DA00694f80();
    unsigned short& GetAt(int index);
    int unk04;
    int unk08;
    int unk0C;
};

class TESFileRecordLoader
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    DA00694f80* unk24;

    bool LoadRecord(void* src, int unused, TESFile* file);
};

// Copies a 0x24-byte header from src, converts header values if needed, allocates unk24, then reads counts and unsigned-short values from src.
// @fnv 0x0069da40
bool TESFileRecordLoader::LoadRecord(void* src, int unused, TESFile* file)
{
    unsigned int totalCount;
    unsigned int headerSize7 = 0x24;
    unsigned short* dataPtr;
    unsigned int i4;
    unsigned short subCount2;
    unsigned short j;

    ::__memcpy(this, src, headerSize7);
    if (file->IsEndianConversionRequired())
    {
        ::FUN_00401080(&unk00);
        ::FUN_00401080(&unk04);
        ::FUN_00401080(&unk08);
        ::FUN_00401080(&unk0C);
        ::FUN_00401080(&unk10);
        ::FUN_00401080(&unk14);
        ::FUN_00401080(&unk18);
        ::FUN_00401080(&unk1C);
        ::FUN_00401080(&unk20);
    }
    if (unk00 == 0)
    {
        unk24 = 0;
        return false;
    }
    totalCount = unk00 * unk00;
    unk24 = new DA00694f80[totalCount];
    dataPtr = (unsigned short*)((char*)src + headerSize7);
    for (i4 = 0; i4 < totalCount; ++i4)
    {
        subCount2 = *dataPtr++;
        if (file->IsEndianConversionRequired())
        {
            ::FUN_00407a90((short *)(unsigned short *)(&subCount2));
        }
        reinterpret_cast<::BSSimpleArrayActor *>(&(unk24[i4]))->FUN_005eee80(subCount2, true);
        if (subCount2 > 0)
        {
            if (file->IsEndianConversionRequired())
            {
                for (j = 0; j < subCount2; ++j)
                {
                    ::FUN_00407a90((short *)(unsigned short *)(&dataPtr[j]));
                }
            }
            ::__memcpy(&reinterpret_cast<::FUN_005eeda0_this *>(&(unk24[i4]))->GetBufferEntry(0), dataPtr, subCount2 * 2);
            dataPtr += subCount2;
        }
    }
    return true;
}
}  // namespace fnv_0069da40

int __cdecl FindFormEnumIndex(unsigned int);

struct FUN_00484150_shell : public TESForm
{
    bool IsFormTypeBelowThreshold(FormRecordHeader* apGroupForm);
};

// Checks if a group form's form type is below a threshold based on its iFormID, returning true if the type index is less than the threshold.
// @fnv 0x00484150
bool FUN_00484150_shell::IsFormTypeBelowThreshold(FormRecordHeader* apGroupForm)
{
    bool bResultTmp = false;
    unsigned int v1;
    unsigned int v2;
    unsigned int v9;
    unsigned int v8;
    unsigned int v7;

    if (apGroupForm && apGroupForm->form == ::fnv_00543df0::kGroupFormType)
    {
        switch (apGroupForm->iFormID)
        {
        case 0:
            v2 = FindFormEnumIndex(apGroupForm->flags);
            v1 = GetFormType();
            switch (v2)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v2 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v2 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v2 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v2 = 314;
                break;
            default:
                v2 *= 10;
                break;
            }
            switch (v1)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v1 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v1 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v1 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v1 = 314;
                break;
            default:
                v1 *= 10;
                break;
            }
            if (v1 < v2)
            {
                bResultTmp = true;
            }
            break;
        case 2:
        case 3:
        case 6:
            v9 = GetFormType();
            switch (v9)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v9 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v9 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v9 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v9 = 314;
                break;
            default:
                v9 *= 10;
                break;
            }
            if (v9 < 570)
            {
                bResultTmp = true;
            }
            break;
        case 1:
        case 4:
        case 5:
            v8 = GetFormType();
            switch (v8)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v8 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v8 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v8 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v8 = 314;
                break;
            default:
                v8 *= 10;
                break;
            }
            if (v8 < 650)
            {
                bResultTmp = true;
            }
            break;
        case 7:
            v7 = GetFormType();
            switch (v7)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v7 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v7 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v7 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v7 = 314;
                break;
            default:
                v7 *= 10;
                break;
            }
            if (v7 < 690)
            {
                bResultTmp = true;
            }
            break;
        }
    }
    return bResultTmp;
}

namespace fnv_004861f0 {
/* rework: avoid defining TESUsesForm/TESHealthForm/... which clash with tesform.cpp structs (C2011) */
extern "C" void* __cdecl FUN_00ec43fb(void* in, int vfDelta, void* srcType, void* targetType, int isReference);
extern char DAT_01183028[]; /* .?AVTESForm@@ */
extern char DAT_01186b88[]; /* .?AVTESUsesForm@@ */
extern char DAT_01186b6c[]; /* .?AVTESValueForm@@ */
extern char DAT_01186c3c[]; /* .?AVTESHealthForm@@ */
extern char DAT_01183274[]; /* .?AVTESWeightForm@@ */
extern char DAT_01186bdc[]; /* .?AVTESQualityForm@@ */
extern char DAT_01186c90[]; /* .?AVTESAttackDamageForm@@ */
extern char DAT_01186c74[]; /* .?AVTESAttributes@@ */
extern char DAT_011868d4[]; /* .?AVBGSClipRoundsForm@@ */

extern "C" void* __cdecl memcpy(void* dest, const void* src, size_t count);
struct Swap_004861f0
{
};

/* neutral stand-ins for member calls only (names must not collide with tesform.cpp) */
class UsesFormX : public BaseFormComponent
{
  public:
};
class HealthFormX : public BaseFormComponent
{
  public:
};
class WeightFormX : public BaseFormComponent
{
  public:
};
class QualityFormX : public BaseFormComponent
{
  public:
};
class AttackDamageFormX : public BaseFormComponent
{
  public:
};
class AttributesX : public BaseFormComponent
{
  public:
};
class ClipRoundsFormX : public BaseFormComponent
{
  public:
};

struct Form_004861f0 : TESForm
{
    void FUN_004861f0(TESFile* file, void* dest, unsigned short count);
};

// Reads a chunk from the file into a stack buffer, copies it to dest, and parses form fields into the component objects.
// @fnv 0x004861f0
void Form_004861f0::FUN_004861f0(TESFile* file, void* dest, unsigned short count)
{
    AttributesX* pAttr9;
    ClipRoundsFormX* pClip;
    UsesFormX* pUses;
    QualityFormX* pQuality;
    unsigned short pos4;
    WeightFormX* pWeightFormTmp;
    AttackDamageFormX* pDamage5;
    TESValueForm* pValue;
    unsigned short chunkSize3;
    int val3;
    char* buffer2;
    HealthFormX* pHealth4;
    short damage9;
    float fval;

    chunkSize3 = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
    pos4 = count;
    buffer2 = (char*)_alloca(chunkSize3);
    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer2), chunkSize3);
    memcpy(dest, buffer2, ::MinUnsignedShort(chunkSize3, count));

    pUses = (UsesFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186b88, 0);
    pValue = (TESValueForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186b6c, 0);
    pHealth4 = (HealthFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c3c, 0);
    pWeightFormTmp = (WeightFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01183274, 0);
    pQuality = (QualityFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186bdc, 0);
    pDamage5 = (AttackDamageFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c90, 0);
    pAttr9 = (AttributesX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c74, 0);
    pClip = (ClipRoundsFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_011868d4, 0);

    if (pUses && pos4 < chunkSize3)
    {
        reinterpret_cast<::FUN_004f15a0_shell *>((pUses))->FUN_004f15a0((unsigned char)buffer2[pos4]);
        pos4 += 1;
    }
    if (pValue && pos4 < chunkSize3)
    {
        val3 = *(int*)(buffer2 + pos4);
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            ::FUN_00401080(&val3);
        pValue->SetFormValue(val3);
    }
    if (pHealth4 && pos4 < chunkSize3)
    {
        val3 = *(int*)(buffer2 + pos4);
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            ::FUN_00401080(&val3);
        reinterpret_cast<::CombatProcedure *>((pHealth4))->Initialize((::CombatController *)(val3));
    }
    if (pWeightFormTmp && pos4 < chunkSize3)
    {
        float weight;
        memcpy(&weight, buffer2 + pos4, 4);
        fval = weight;
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            ::FUN_00401080((int*)&fval);
        reinterpret_cast<::FUN_004f5d90_shell *>((pWeightFormTmp))->FUN_004f5d90(fval);
    }
    if (pQuality && pos4 < chunkSize3)
    {
        float quality;
        memcpy(&quality, buffer2 + pos4, 4);
        fval = quality;
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            ::FUN_00401080((int*)&fval);
        reinterpret_cast<::FUN_004f15a0_shell *>((pQuality))->FUN_004f15a0((unsigned char)fval);
    }
    if (pDamage5 && pos4 < chunkSize3)
    {
        damage9 = *(short*)(buffer2 + pos4);
        pos4 += 2;
        if (file->IsEndianConversionRequired())
            ::FUN_00407a90(&damage9);
        reinterpret_cast<::FUN_0047ff50_class *>((pDamage5))->FUN_0047ff50(damage9);
    }
    if (pAttr9)
    {
        pos4 += reinterpret_cast<::FUN_00480130_shell *>((pAttr9))->FUN_00480130(buffer2 + pos4);
    }
    if (pClip && pos4 < chunkSize3)
    {
        reinterpret_cast<::FUN_004f15a0_shell *>((pClip))->FUN_004f15a0((unsigned char)buffer2[pos4]);
        pos4 += 1;
    }
}
}  // namespace fnv_004861f0

namespace form_load_legacy {

extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern char DAT_01183028[];
extern char DAT_011841cc[];

struct TESFormLoadProxy : public ::TESForm
{
    void FUN_00484c50(unsigned int, unsigned int);
};

// When bit 0 of flags is set, reads a value into itempFormFlags and merges masked bits into m_uiFormFlags according to whether pref is nonnull.
// @fnv 0x00484c50
void TESFormLoadProxy::FUN_00484c50(unsigned int flags, unsigned int currentFlags)
{
    ::TESObjectREFR* pref;
    unsigned int itempFormFlags;

    if (flags & 1)
    {
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&itempFormFlags, 4);
        pref = (::TESObjectREFR*)FUN_00ec43fb(this, 0, &DAT_01183028, &DAT_011841cc, 0);
        if (pref)
        {
            m_uiFormFlags = (m_uiFormFlags & 0xff6ed79f) | (itempFormFlags & 0x00912860);
        }
        else
        {
            m_uiFormFlags = (m_uiFormFlags & 0xbffff3df) | (itempFormFlags & 0x40000c20);
        }
    }
}

}



#include "generated/data/fallout_shared/tesform.inc"
