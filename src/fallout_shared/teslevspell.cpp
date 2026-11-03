
// src/fallout_shared/teslevspell.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/teslevspell.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include <new>
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Owner487a60.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040c000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_01183000.h"
struct FUN_0050b980_shell
{
    void __thiscall FUN_0050b9b0();
    void* __thiscall Destroy(unsigned int flags);
};

struct TESForm
{
    virtual ~TESForm()
    {}
public:
    void ClearData();
public:
    void SetInitializationState(bool);
};
struct FUN_005e78f0_t : TESForm
{
};
struct TESLevSpell : FUN_005e78f0_t
{
    void FUN_0050bcd0(TESForm*);
};
// Casts apCopy to TESLevSpell and, if the cast succeeds, calls FUN_004851b0 on apCopy.
// @fnv 0x0050bcd0
void TESLevSpell::FUN_0050bcd0(TESForm* apCopy)
{
    TESLevSpell* pllcopy = dynamic_cast<TESLevSpell*>(apCopy);
    if (!pllcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apCopy);
}

extern "C" void* __cdecl _alloca(unsigned int);
enum ENUM_FORM_ID
{
};
class TESFile
{
  public:
    ENUM_FORM_ID GetTESForm();
    bool NextChunk();
    bool GetChunkData(unsigned int*);
public:
    bool IsEndianConversionRequired();
};
class ContainerItemExtra
{
  public:
    static void* operator new(unsigned int);
    ContainerItemExtra();
    bool Load(TESFile*);
    void* data[3];
};
class LeveledObject
{
  public:
    void* pad[2];
    ContainerItemExtra* pExtra;
};
struct LeveledFormEntry
{
    unsigned short sLevel;
    TESForm* pForm;
    unsigned short m_sCount;
};
struct TmpEndian
{
    void SwapEndian();
};
struct TESLeveledList
{
    void FUN_0042e680(unsigned char);
public:
    bool GetAllBelow();
public:
    bool GetUseAll();
};
struct T00485110;
struct S00485110
{
    void CallWithThis(T00485110*);
};
struct ScriptS
{
};
extern LeveledObject* DAT_011c8f98;
struct LevSpellS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void LoadBound(TESFile*);
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void SetEditorID(const char*);
    bool FUN_0050ba30(TESFile* apFile);
};
// @fnv 0x0050ba30
bool LevSpellS::FUN_0050ba30(TESFile* apFile)
{
    unsigned char formid = apFile->GetTESForm();
    if (formid != 0x4c)
        return false;
    ((S00485110*)this)->CallWithThis((T00485110*)apFile);
    do
    {
        switch (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())
        {
        case 'DIDE': {
            char* pEditorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pEditorID), 0x200);
            SetEditorID(pEditorID);
            break;
        }
        case 'DNBO':
            LoadBound(apFile);
            break;
        case 'OLVL':
        case 'DEOC':
            switch (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())
            {
            case 'OLVL': {
                LeveledFormEntry levObj;
                ::FUN_00403d30(&levObj, 0, 0xc);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&levObj), 0xc);
                if (apFile->IsEndianConversionRequired())
                    ((TmpEndian*)&levObj)->SwapEndian();
                DAT_011c8f98 = ((::LeveledObject *)(reinterpret_cast<::Owner487a60 *>((((TESLeveledList*)((char*)this + 0x30))))->InsertEntryByPriority(levObj.sLevel, levObj.m_sCount, (int)(levObj.pForm), (int)(0))));
                break;
            }
            case 'DEOC':
                if (DAT_011c8f98)
                {
                    ContainerItemExtra* pextra = new ContainerItemExtra;
                    pextra->Load(apFile);
                    DAT_011c8f98->pExtra = pextra;
                    DAT_011c8f98 = 0;
                }
                break;
            }
            break;
        case 'DLVL': {
            unsigned char cdata = 0;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&cdata), 0);
            ((TESLeveledList*)((char*)this + 0x30))->FUN_0042e680(cdata);
            break;
        }
        case 'FLVL':
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)((char*)this + 0x3d), 0);
            break;
        case 'GLVL': {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            *(unsigned int*)((char*)this + 0x40) = itempint;
            break;
        }
        }
    } while (apFile->NextChunk());
    reinterpret_cast<::TESForm *>((((ScriptS*)this)))->SetInitializationState(0);
    return true;
}

// Destructor of a form with a secondary component base: run the form cleanup, then the bases are destroyed.

class B9B0Form
{
  public:
    virtual ~B9B0Form();
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

class B9B0Component
{
  public:
    virtual ~B9B0Component();
    int unk04;
};

class FUN_0050b9b0 : public B9B0Form, public B9B0Component
{
  public:
    virtual ~FUN_0050b9b0();
};
// Calls FUN_0050b9b0, then frees this with Deallocate if flags has bit 1 set, and returns this.
// @fnv 0x0050b980
void* __thiscall FUN_0050b980_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_0050b9b0 *>(this)->FUN_0050b9b0::~FUN_0050b9b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0050b9b0
FUN_0050b9b0::~FUN_0050b9b0()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

struct FUN_0050bf90_cls
{
    unsigned int FUN_0050bf90(void* a1, unsigned short a2);
};

unsigned int __cdecl FUN_00ec43fb(unsigned int, int, void*, void*, int);

struct SpellItem : TESForm
{
};
struct SpellChoice : TESLevSpell
{
};
struct SpellEntry
{
    TESForm* form;
};
struct SpellEntryNode
{
};
struct SpellChoices
{
};
struct FUN_0096a2d0
{
    void* unk00;
    void* unk04;
    FUN_0096a2d0();
    void FUN_005ae3d0(SpellItem*&);
};
void* operator new(unsigned int);
struct SpellSelector
{
    int unk00;
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
    SpellChoices choices;
    FUN_0096a2d0* FUN_0050c000(void*, unsigned short);
};
// Builds a spell list from the selector's choices, resolving nested level spells via FUN_0050bf90, or falls back to a single spell; returns the new list or null.
// @fnv 0x0050c000
FUN_0096a2d0* SpellSelector::FUN_0050c000(void* actor, unsigned short level)
{
    FUN_0096a2d0* result = 0;
    if (reinterpret_cast<::TESLeveledList *>(&(choices))->GetUseAll())
    {
        SpellEntryNode* node = ((::SpellEntryNode *)(reinterpret_cast<::BaseProcess *>(&(choices))->GetCurrentProcessData()));
        while (node)
        {
            SpellEntry* entry = *((::SpellEntry **)(new ((void *)(node)) ::Vec3()));
            if (entry)
            {
                if (!result)
                    result = new FUN_0096a2d0;
                SpellItem* spell = dynamic_cast<SpellItem*>(entry->form);
                if (spell)
                {
                    result->FUN_005ae3d0(spell);
                }
                else
                {
                    TESLevSpell* nested = dynamic_cast<TESLevSpell*>(entry->form);
                    if (nested)
                    {
                        spell = ((::SpellItem *)(reinterpret_cast<::FUN_0050bf90_cls *>((static_cast<SpellChoice*>(nested)))->FUN_0050bf90(actor, level)));
                        if (spell)
                            result->FUN_005ae3d0(spell);
                    }
                }
            }
            node = ((::SpellEntryNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }
    else
    {
        SpellItem* spell = ((::SpellItem *)(reinterpret_cast<::FUN_0050bf90_cls *>(this)->FUN_0050bf90(actor, level)));
        if (spell)
        {
            result = new FUN_0096a2d0;
            result->FUN_005ae3d0(spell);
        }
    }
    return result;
}

namespace fnv_0050c1d0 {
class BGSHeadPart;
struct List_009e03e0
{
    BGSHeadPart* m_item;
    List_009e03e0* m_pkNext;
    ~List_009e03e0();
};
struct FUN_0096a2d0
{
    BGSHeadPart* m_item;
    FUN_0096a2d0* m_pkNext;
    FUN_0096a2d0();
    void FUN_005ae3d0(BGSHeadPart*& pkItem);
};
struct SpellSource
{
    virtual void v0();
    virtual void v1();
    virtual void* GetEntry(int iType);
};
struct SpellOwner
{
    char pad[0xa4];
    SpellSource m_kSource;
};
struct FUN_0050c1d0_shell
{
    FUN_0096a2d0* CollectHeadParts(SpellOwner* pkOwner);
};
// Iterates six source entries, gathers non-null BGSHeadPart items into a deduplicated FUN_0096a2d0 list, frees each temporary list, and returns the result.
// @fnv 0x0050c1d0
FUN_0096a2d0* FUN_0050c1d0_shell::CollectHeadParts(SpellOwner* pkOwner)
{
    FUN_0096a2d0* pkResult = 0;
    for (int i = 0; i < 6; i++)
    {
        List_009e03e0* pkIter = ((::fnv_0050c1d0::List_009e03e0 *)(reinterpret_cast<::SpellSelector *>(this)->FUN_0050c000((void *)(i), (unsigned short)(pkOwner->m_kSource.GetEntry(::GetMinusOne())))));
        List_009e03e0* pkListCur = pkIter;
        while (pkIter)
        {
            BGSHeadPart* pkItem = ((::fnv_0050c1d0::BGSHeadPart *)(new ((void *)(pkIter)) ::Vec3()));
            if (pkItem)
            {
                bool bAppend = true;
                if (!pkResult)
                    pkResult = new FUN_0096a2d0;
                else
                    bAppend = !reinterpret_cast<::RefList *>((pkResult))->FUN_005f65d0((void **)&(pkItem));
                if (bAppend)
                    pkResult->FUN_005ae3d0(pkItem);
            }
            pkIter = ((::fnv_0050c1d0::List_009e03e0 *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
        }
        if (pkListCur)
            reinterpret_cast<::FileMatchList *>((pkListCur))->RemoveAll();
        delete pkListCur;
    }
    return pkResult;
}
}  // namespace fnv_0050c1d0

extern int DAT_01187818;
unsigned int __cdecl FUN_00ec43fb(unsigned int, int, void*, void*, int);

struct Entry
{
    unsigned int form;
    unsigned short count;
    unsigned short level;
};
struct ListNode
{
};
struct ListData
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned char ChanceNone();
};
struct FormHandle
{
};
struct FieldLayout
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FormHandle form0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    ListData list30;
};
struct LeveledSpellList : FUN_0050bf90_cls
{
    void SelectLeveledSpell(void*, unsigned short, unsigned int*, unsigned short*, unsigned char);
};
// @fnv 0x0050bf90
unsigned int FUN_0050bf90_cls::FUN_0050bf90(void* a1, unsigned short a2)
{
    unsigned int aa = 0;
    unsigned int zz = 0;
    unsigned short word = 0;
    reinterpret_cast<::LeveledSpellList *>((this))->SelectLeveledSpell(a1, a2, &zz, &word, 1);
    if (zz != 0)
    {
        aa = FUN_00ec43fb(zz, 0, &DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_01183060)), 0);
    }
    return aa;
}
// @fnv 0x0050bd60
void LeveledSpellList::SelectLeveledSpell(void* desiredForm, unsigned short level, unsigned int* outForm,
                                          unsigned short* outCount, unsigned char recurse)
{
    *outForm = 0;
    *outCount = 0;
    unsigned int candidateCount;
    int maxLevel;
    ListNode* best;
    ListNode* node;
    unsigned char chanceNone = ((FieldLayout*)this)->list30.ChanceNone();
    if (chanceNone > 0)
    {
        int chanceRoll = (int)(::DialogueRandom() % 100);
        if (chanceRoll < chanceNone)
            return;
    }

    candidateCount = 1;
    maxLevel = 0;
    best = 0;
    node = ((::ListNode *)(reinterpret_cast<::BaseProcess *>(&(((FieldLayout*)this)->list30))->GetCurrentProcessData()));
    while (node != 0 && *((::Entry **)(new ((void *)(node)) ::Vec3())) != 0)
    {
        Entry* entryLevel = *((::Entry **)(new ((void *)(node)) ::Vec3()));
        FUN_0050bf90_cls* mapped =
            (FUN_0050bf90_cls*)FUN_00ec43fb(entryLevel->form, 0, &DAT_01183028, &DAT_01183140, 0);
        int entry = entryLevel->level;
        if (entry > level || (mapped != 0 && ((void *)(::GetSix())) != desiredForm))
            break;
        if (entry > maxLevel && (maxLevel == 0 || !((unsigned char)(reinterpret_cast<::TESLeveledList *>(&(((FieldLayout*)this)->list30))->GetAllBelow()))))
        {
            candidateCount = 1;
            best = node;
            maxLevel = entry;
        }
        else
        {
            ++candidateCount;
        }
        node = ((::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    if (best != 0)
    {
        unsigned int skip = ::DialogueRandom() % candidateCount;
        node = best;
        while (skip != 0)
        {
            node = ((::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            --skip;
            if (node == 0)
                return;
        }
        unsigned short nestedRecord;
        Entry* chosen = *((::Entry **)(new ((void *)(node)) ::Vec3()));
        unsigned int foundForm = chosen->form;
        nestedRecord = chosen->count;
        FUN_0050bf90_cls* selectedEntry =
            (FUN_0050bf90_cls*)FUN_00ec43fb(chosen->form, 0, &DAT_01183028, &DAT_01187818, 0);
        if (selectedEntry != 0 && recurse != 0)
        {
            unsigned short recursiveCount;
            unsigned int recursiveForm = 0;
            recursiveCount = 0;
            reinterpret_cast<::LeveledSpellList *>((selectedEntry))->SelectLeveledSpell(desiredForm, level, &recursiveForm, &recursiveCount, recurse);
            foundForm = recursiveForm;
            nestedRecord *= recursiveCount;
        }
        *outForm = foundForm;
        *outCount = nestedRecord;
    }
}

struct LeveledSpellComparison : TESLevSpell
{
    bool FUN_0050bd10(TESForm*);
};

// Returns true if apCompare is not a TESLevSpell or if FUN_00485270(pcomp) is true, otherwise false.
// @fnv 0x0050bd10
bool LeveledSpellComparison::FUN_0050bd10(TESForm* apCompare)
{
    TESLevSpell* pLevSpell = dynamic_cast<TESLevSpell*>(apCompare);
    if (!pLevSpell)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pLevSpell))
        return true;
    return false;
}
