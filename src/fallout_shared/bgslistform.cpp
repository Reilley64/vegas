// fallout_shared/bgslistform.cpp: BGSListForm, ThisHolder (12 functions)

#include <new>
#include "fnv/decl/BGSHungerStage.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/HungerStageData.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "bgslistform_decls.h"

// @fnv 0x0058FB00
void BGSListForm::ClearData()
{
    reinterpret_cast<::FileMatchList *>((reinterpret_cast<BSSimpleList<ActorCause*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())))->RemoveAll();
    m_uiFormCount = 0;
}

// @fnv 0x00590010
void BGSListForm::IncludeForm(TESForm* form)
{
    if (form != 0)
    {
        if (!reinterpret_cast<::RefList *>((reinterpret_cast<BSSimpleList<BGSQuestObjective*>*>(
                 reinterpret_cast<BGSCameraPath*>(this)->GetConditions())))->FUN_005f65d0((void **)&(reinterpret_cast<BGSQuestObjective*&>(form))))
        {
            reinterpret_cast<BSSimpleList<EffectSetting*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())
                ->AddHead(reinterpret_cast<EffectSetting*&>(form));
            ++m_uiFormCount;
            MarkAsModified(0x80000000);
        }
    }
}

// @fnv 0x00591B70
BGSListForm::BGSListForm()
{
    new ((void *)(reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<unsigned char*>(this) + 0x18))) ::HungerStageData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x5A)));
    reinterpret_cast<::BGSHungerStage *>((reinterpret_cast<BGSRadiationStage*>(this)))->ResetFormData();
}

// @fnv 0x0058FD40
bool BGSListForm::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);

    unsigned int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e4c: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            {
                reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<MediaSet*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())))->FUN_00905820((void *)&(const ::MediaSet *const &)((MediaSet*)formID));
            }
            break;
        }
        default:
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0058FE50
void BGSListForm::InitItem()
{
    if (GetInitialized())
        return;
    BSSimpleList<BGSCameraShot*>* current =
        reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions());
    BSSimpleList<BGSCameraShot*>* previous = 0;
    TESForm* form;
    while (current != 0 && !current->IsEmpty())
    {
        unsigned int formID = (unsigned int)((::BGSPerkEntry *)(new ((void *)(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(current))) ::Vec3()));
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        form = ::FUN_004839c0(formID);
        if (form != 0)
        {
            current->SetItem(reinterpret_cast<BGSCameraShot* const&>(form));
            previous = current;
            current = reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(
                ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(current)))->FUN_00726070())));
        }
        else
        {
            ::FUN_005b5e40();
            if (previous != 0)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)((const ::BGSCameraShot *const &)((BGSCameraShot*)formID)));
                current = reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(
                    ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(previous)))->FUN_00726070())));
            }
            else
            {
                current->RemoveHead();
            }
        }
    }
    SetInitializationState(true);
}

struct FUN_0058fa60_shell
{
    void* DestroyIfFlagged(unsigned int);
};
struct CallTarget_0063f7b0
{
    void _ref_0063f7b0();
};
struct ThisHolder
{
    void FUN_0058ffd0();
};
// @fnv 0x005901C0
void BGSListForm::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((unsigned int)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x80000000)))->FUN_004280f0())
        reinterpret_cast<::ThisHolder *>(this)->FUN_0058ffd0();
}
// @fnv 0x00590120
void BGSListForm::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESForm *>(this)->LoadGame(buffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x80000000)))->FUN_004280f0())
    {
        if (m_uiFormCount != 0)
            reinterpret_cast<::ThisHolder *>(this)->FUN_0058ffd0();

        unsigned int formCount = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&formCount), 4);
        for (unsigned int index = 0; index < formCount; ++index)
        {
            TESForm* form = ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0());
            IncludeForm(form);
        }
    }
}
// @fnv 0x0058ffd0
void ThisHolder::FUN_0058ffd0()
{
    while (*(unsigned int*)((char*)this + 0x20) != 0)
    {
        ((CallTarget_0063f7b0*)((BGSCameraPath*)this)->GetConditions())->_ref_0063f7b0();
        *(unsigned int*)((char*)this + 0x20) = *(unsigned int*)((char*)this + 0x20) - 1;
    }
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct _ref_006815c0_shell
{
};
struct _ref_008256d0_shell
{
    bool _ref_008256d0();
};
struct _ref_00726070_shell
{
};
struct FUN_0058fcc0_shell
{
    void FUN_0058fcc0();
};
// @fnv 0x0058fcc0
void FUN_0058fcc0_shell::FUN_0058fcc0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    PerkEntryConditionSet* pCondition = ((BGSCameraPath*)this)->GetConditions();
    while (pCondition && !(((_ref_008256d0_shell*)pCondition)->_ref_008256d0()))
    {
        TESForm* pForm = *((::TESForm **)(new ((void *)(((_ref_006815c0_shell*)pCondition))) ::Vec3()));
        unsigned int formID6 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pForm))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e4c, formID6);
        pCondition = ((::PerkEntryConditionSet *)(reinterpret_cast<::Callees *>((((_ref_00726070_shell*)pCondition)))->FUN_00726070()));
    }
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct _ref_008256d0_shell2
{
    bool FUN_008256d0();
};
struct _ref_006815c0_shell2
{
};
struct FUN_005e79a0_t
{
};
struct BSSimpleListGetNext
{
};
struct FUN_0058fbc0_shell : BGSCameraPath
{
    bool IsNotEqual(TESForm* apCompare);
};

// @fnv 0x0058fbc0
bool FUN_0058fbc0_shell::IsNotEqual(TESForm* apCompare)
{
    BGSListForm* pcompare = dynamic_cast<BGSListForm*>(apCompare);
    if (!pcompare)
        return true;
    if (((BSSimpleListTESRaceSize*)GetConditions())->GetSize() !=
        ((BSSimpleListTESRaceSize*)((BGSCameraPath*)pcompare)->GetConditions())->GetSize())
        return true;
    BSSimpleList<TESForm*>* pCurrentElementNext = (BSSimpleList<TESForm*>*)GetConditions();
    BSSimpleList<TESForm*>* pcomplist = (BSSimpleList<TESForm*>*)((BGSCameraPath*)pcompare)->GetConditions();
    while (pCurrentElementNext && !((_ref_008256d0_shell2*)pCurrentElementNext)->FUN_008256d0() && pcomplist &&
           !((_ref_008256d0_shell2*)pcomplist)->FUN_008256d0())
    {
        if (*((::TESForm **)(new ((void *)(((_ref_006815c0_shell2*)pCurrentElementNext))) ::Vec3())) != *((::TESForm **)(new ((void *)(((_ref_006815c0_shell2*)pcomplist))) ::Vec3())))
            return true;
        pCurrentElementNext = ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((((BSSimpleListGetNext*)pCurrentElementNext)))->FUN_00726070()));
        pcomplist = ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((((BSSimpleListGetNext*)pcomplist)))->FUN_00726070()));
    }
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcompare))
        return true;
    return false;
}

struct FUN_005e78f0_t
{
};
struct SoundListView
{
};
struct FUN_0058fb30_shell : BGSCameraPath
{
    void CopyConditionsFromListForm(TESForm* apCopy);
};
// Casts apCopy to BGSListForm, appends each of its condition entries to this object's condition list, then calls FUN_004851b0 with the list form.
// @fnv 0x0058fb30
void FUN_0058fb30_shell::CopyConditionsFromListForm(TESForm* apCopy)
{
    BGSListForm* pListForm = dynamic_cast<BGSListForm*>(apCopy);
    if (!pListForm)
        return;
    BSSimpleList<TESForm*>* pCurrentElementNext =
        reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<BGSCameraPath*>(pListForm)->GetConditions());
    while (pCurrentElementNext && !reinterpret_cast<_ref_008256d0_shell2*>(pCurrentElementNext)->FUN_008256d0())
    {
        TESForm* pform = ((::TESForm **)(new ((void *)(reinterpret_cast<_ref_006815c0_shell2*>(pCurrentElementNext))) ::Vec3()))[0];
        reinterpret_cast<::Callees *>((reinterpret_cast<SoundListView*>(GetConditions())))->FUN_00905820((void *)&(reinterpret_cast<char* const&>(pform)));
        pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleListGetNext*>(pCurrentElementNext)))->FUN_00726070())));
    }
    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005e78f0_t*>(this)))->FUN_004851b0(reinterpret_cast<TESForm*>(pListForm));
}

struct FUN_0058ff60_shell : BGSCameraPath
{
    int GetConditionIndex(TESForm*);
};

// @fnv 0x0058ff60
int FUN_0058ff60_shell::GetConditionIndex(TESForm* apForm)
{
    int iElementIndex = 0;
    BSSimpleList<TESForm*>* pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(GetConditions());
    while (pCurrentElementNext && !reinterpret_cast<_ref_008256d0_shell*>(pCurrentElementNext)->_ref_008256d0())
    {
        if (((::TESForm **)(new ((void *)(reinterpret_cast<_ref_006815c0_shell*>(pCurrentElementNext))) ::Vec3()))[0] == apForm)
            break;
        iElementIndex++;
        pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleListGetNext*>(pCurrentElementNext)))->FUN_00726070())));
    }
    if (!pCurrentElementNext)
        iElementIndex = -1;
    return iElementIndex;
}

struct BGSSaveFormBuffer
{
};
struct SaveFormIDHelper
{
};
struct FUN_00484d60_holder
{
};
struct FUN_00590080_shell : public BGSListForm
{
    void SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x00590080
void FUN_00590080_shell::SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged((::BGSSaveFormBuffer *)(reinterpret_cast<unsigned int>(apSaveGameBuffer)));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(reinterpret_cast<BGSLoadFormBuffer*>(apSaveGameBuffer)->GetChangeFlags(0x80000000)))->FUN_004280f0())
    {
        BSSimpleList<TESForm*>* pCurrentElementNext =
            reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<unsigned char*>(this) + 0x18);
        reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x20), 4, 0);
        for (unsigned int i = 0; i < m_uiFormCount; ++i)
        {
            TESForm* pform = ((::TESForm **)(new ((void *)(reinterpret_cast<_ref_006815c0_shell*>(pCurrentElementNext))) ::Vec3()))[0];
            pCurrentElementNext = ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleListGetNext*>(pCurrentElementNext)))->FUN_00726070()));
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((reinterpret_cast<SaveFormIDHelper*>(apSaveGameBuffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(pform), 0);
        }
    }
}

class FUN_0058f9d0_base
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0058f9d0_base();
    virtual ~FUN_0058f9d0_base();
};

struct FUN_0058f9d0_member
{
    int unk00;
    int unk04;
    FUN_0058f9d0_member();
    ~FUN_0058f9d0_member();
};

class FUN_0058f9d0 : public FUN_0058f9d0_base
{
  public:
    FUN_0058f9d0_member m_18;
    int m_20;
    FUN_0058f9d0();
    virtual ~FUN_0058f9d0();
};

// Initializes the object by calling Unk_a, calling Unk_b with 0x55, and setting m_20 to 0.
// @fnv 0x0058f9d0
FUN_0058f9d0::FUN_0058f9d0()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x55);
    m_20 = 0;
}

struct Base_58fa90
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    ~Base_58fa90();
};

struct Member_58fa90
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~Member_58fa90();
};

class FUN_0058fa90_cls : public Base_58fa90
{
  public:
    Member_58fa90 m_18;

    virtual ~FUN_0058fa90_cls();
};
// Calls FUN_0058fa90, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0058fa60
void* FUN_0058fa60_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0058fa90_cls *>(this)->FUN_0058fa90_cls::~FUN_0058fa90_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0058fa90
FUN_0058fa90_cls::~FUN_0058fa90_cls()
{
    reinterpret_cast<::BGSListForm *>(this)->ClearData();
}

class Base_5effc0
{
  public:
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    Base_5effc0();
    ~Base_5effc0();
};

class Member_5effc0
{
  public:
    int unk00;

    Member_5effc0();
    ~Member_5effc0();
};

class FUN_005effc0 : public Base_5effc0
{
  public:
    virtual void v00();
    unsigned char m_18;
    Member_5effc0 m_1c;

    FUN_005effc0();
};

// Initializes the object by calling Method_5effc0 with 0x5d and setting m_18 to 0.
// @fnv 0x005effc0
FUN_005effc0::FUN_005effc0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x5d);
    m_18 = 0;
}
