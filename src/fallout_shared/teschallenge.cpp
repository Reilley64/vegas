// fallout_shared/teschallenge.cpp: TESChallenge, ChallengeManager (16 functions)

#include <new>
#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00461150_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd3a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005ac340_t.h"
#include "fnv/decl/FUN_005f5f60_class.h"
#include "fnv/decl/FUN_005f5fa0_cls.h"
#include "fnv/decl/FUN_005f5fc0_class.h"
#include "fnv/decl/FUN_005f5fe0_class.h"
#include "fnv/decl/FUN_005f6000_Class.h"
#include "fnv/decl/FUN_005f6060_class.h"
#include "fnv/decl/FUN_005f60c0_Class.h"
#include "fnv/decl/FUN_006a1b60_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_005a6000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011de000.h"
#include "teschallenge_decls.h"

// @fnv 0x005F5080
void TESChallenge::InitItem()
{
    if (GetInitialized())
        return;
    TESScriptableForm::InitItem(this);
    unsigned int formID = (unsigned int)(std::uintptr_t)(m_pPrimaryForm);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pPrimaryForm = ::FUN_004839c0(formID);
        if (!m_pPrimaryForm)
            ::FUN_005b5e40();
    }
    formID = (unsigned int)(std::uintptr_t)(m_pSecondaryForm);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pSecondaryForm = ::FUN_004839c0(formID);
        if (!m_pSecondaryForm)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}

// @fnv 0x005F57C0
void TESChallenge::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESForm *>(this)->LoadGame(buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&progress.iProgress), sizeof(progress.iProgress));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&progress.m_iCompletionCount), sizeof(progress.m_iCompletionCount));
}

// @fnv 0x005F5880
void ChallengeManager::CheckCompletedChallenges()
{
    Clear();
    BSSimpleList<TESChallenge*>* list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::FUN_00461150_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_00461150()));
    TESChallenge* challenge = 0;
    while (list)
    {
        challenge = (list->m_item);
        if (challenge && !((int)(::FUN_005a6150((const unsigned char *)(challenge)))) && (!challenge->GetStartsLocked() || ((int)(::FUN_005a60d0((const char *)(challenge))))))
            (*reinterpret_cast<BSSimpleList<TESChallenge *> (*)[14]>(&::DAT_011cb3e0))[(*(::CHALLENGE_TYPE *)(reinterpret_cast<::FUN_006a1b60_Class *>((challenge))->GetField54()))].AddHead(challenge);
        else if (challenge)
            (*reinterpret_cast<BSSimpleList<TESChallenge *> (*)[14]>(&::DAT_011cb450))[(*(::CHALLENGE_TYPE *)(reinterpret_cast<::FUN_006a1b60_Class *>((challenge))->GetField54()))].AddHead(challenge);
        list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
}

// @fnv 0x005F4FD0
void TESChallenge::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    memset(&progress, 0, sizeof(progress));
    m_pPrimaryForm = 0;
    m_pSecondaryForm = 0;
    SetShowZero(true);
}

// Sets or clears bit 2 of data.nFlags according to show.
// @fnv 0x005f5020
void TESChallenge::SetShowZero(bool show)
{
    !show ? data.nFlags &= ~4 : data.nFlags |= 4;
}

// Clears all 14 entries by calling RemoveAll on both parallel arrays.
// @fnv 0x005f5840
void ChallengeManager::Clear()
{
    for (int i = 0; i < 14; ++i)
    {
        reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<BSSimpleList<TESChallenge *> (*)[14]>(&::DAT_011cb3e0))[i]))->RemoveAll();
        reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<BSSimpleList<TESChallenge *> (*)[14]>(&::DAT_011cb450))[i]))->RemoveAll();
    }
}

// @fnv 0x005f5800
void TESChallenge::MarkForSave()
{
    MarkAsModified(2);
}

// @fnv 0x005f5930
int TESChallenge::GetStartsLocked()
{
    return data.nFlags & 1;
}

struct FUN_005f4e00 : public TESForm,
                      public TESFullName,
                      public TESDescription,
                      public TESScriptableForm,
                      public TESIcon,
                      public BGSMessageIcon
{
    FUN_005f4e00();
    ~FUN_005f4e00();
};

// @fnv 0x005f4e00
FUN_005f4e00::FUN_005f4e00()
{
    ((TESChallenge*)this)->TESChallenge::ResetFormData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x71)));
}

struct FUN_00484bf0_shell
{
    unsigned short FUN_00484bf0(unsigned int aiFlags);
};

struct FUN_005a7770_shell
{
    unsigned short FUN_005a7770(unsigned int aiFlags);
};

// @fnv 0x005a7770
unsigned short FUN_005a7770_shell::FUN_005a7770(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0_shell*)this)->FUN_00484bf0(aiFlags);
    return isize;
}

struct FUN_005f5820_shell
{
    void ClearField6C();
};
// @fnv 0x005F5950
bool ChallengeManager::UpdateChallengeProgress(CHALLENGE_TYPE type, int count, TESForm* formOne, TESForm* formTwo,
                                               unsigned short specialOne, unsigned short specialTwo,
                                               unsigned short specialThree)
{
    if (type >= CHALLENGE_TYPE_CHALLENGE_TYPE_COUNT || type < 0)
        return false;
    BSSimpleList<TESChallenge*>* list = &(*reinterpret_cast<BSSimpleList<TESChallenge *> (*)[14]>(&::DAT_011cb3e0))[type];
    bool completed = false;
    TESChallenge* challenge = 0;
    while (list)
    {
        challenge = (list->m_item);
        bool applicable = true;
        if (challenge)
        {
            if (((int)(::FUN_005a6150((const unsigned char *)(challenge)))) && !reinterpret_cast<::FUN_005f5f60_class *>((challenge))->FUN_005f5f60())
            {
                list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                continue;
            }
            if (challenge->GetStartsLocked() && !((int)(::FUN_005a60d0((const char *)(challenge)))))
            {
                list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                continue;
            }
            if (((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((challenge))->FUN_004fd3a0())))
            {
                if (!formOne)
                    applicable = false;
                else
                {
                    switch (type)
                    {
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE_LIST: {
                        BGSListForm* formList = static_cast<BGSListForm*>(((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((challenge))->FUN_004fd3a0())));
                        if (formList && !reinterpret_cast<::RefList *>((((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::BGSCameraPath *>((formList))->GetConditions()))))->FUN_005f65d0((void **)&(formOne)))
                            applicable = false;
                        break;
                    }
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_USE_ITEM:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_AQUIRE:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_SKILL:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_CRAFT_WITH_ITEM:
                        if (formOne != ((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((challenge))->FUN_004fd3a0())))
                            applicable = false;
                        break;
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER:
                        if (formOne != ((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((challenge))->FUN_004fd3a0())))
                            applicable = false;
                        break;
                    }
                }
            }
            if (!applicable)
            {
                list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                continue;
            }
            if (((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((challenge))->FUN_00407820())))
            {
                if (!formTwo)
                    applicable = false;
                else
                {
                    switch (type)
                    {
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_LIST:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_SPECIFIC:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_KILL_CATEGORY:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DISCOVER:
                    case CHALLENGE_TYPE_CHALLENGE_TYPE_DAMAGE: {
                        BGSListForm* formList = static_cast<BGSListForm*>(((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((challenge))->FUN_00407820())));
                        if (formList && !reinterpret_cast<::RefList *>((((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::BGSCameraPath *>((formList))->GetConditions()))))->FUN_005f65d0((void **)&(formTwo)))
                            applicable = false;
                        break;
                    }
                    }
                }
            }
            if (!applicable)
            {
                list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                continue;
            }
            bool special = false;
            if (((int)(reinterpret_cast<::FUN_005f5fa0_cls *>((challenge))->GetShortAtOffset64())))
            {
                if (!specialOne)
                    applicable = false;
                if (specialOne != ((int)(reinterpret_cast<::FUN_005f5fa0_cls *>((challenge))->GetShortAtOffset64())))
                    applicable = false;
            }
            else if ((*(::CHALLENGE_TYPE *)(reinterpret_cast<::FUN_006a1b60_Class *>((challenge))->GetField54())) == CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT)
            {
                if (specialOne != ((int)(reinterpret_cast<::FUN_005f5fa0_cls *>((challenge))->GetShortAtOffset64())))
                    applicable = false;
            }
            if (((int)(reinterpret_cast<::FUN_005f5fc0_class *>((challenge))->GetShortAtOffset66())))
            {
                if (!specialTwo)
                    applicable = false;
                if (specialTwo != ((int)(reinterpret_cast<::FUN_005f5fc0_class *>((challenge))->GetShortAtOffset66())))
                    applicable = false;
            }
            else
            {
                switch ((*(::CHALLENGE_TYPE *)(reinterpret_cast<::FUN_006a1b60_Class *>((challenge))->GetField54())))
                {
                case CHALLENGE_TYPE_CHALLENGE_TYPE_HIT:
                    if (specialTwo && specialTwo != 1)
                        applicable = false;
                    break;
                }
            }
            if (((int)(reinterpret_cast<::FUN_005f5fe0_class *>((challenge))->GetShortAtOffset68())))
            {
                if (!specialThree)
                    applicable = false;
                if (specialThree != ((int)(reinterpret_cast<::FUN_005f5fe0_class *>((challenge))->GetShortAtOffset68())))
                    applicable = false;
            }
            if (!applicable)
            {
                list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                continue;
            }
            challenge->FUN_005f60e0(count);
            if (challenge->progress.iProgress >= reinterpret_cast<::LowProcess *>((challenge))->GetPackageObjectType())
            {
                if (((::Script *)(reinterpret_cast<::Callees *>((challenge))->FUN_00726070())))
                    reinterpret_cast<::FUN_005ac340_t *>((((::Script *)(reinterpret_cast<::Callees *>((challenge))->FUN_00726070()))))->RunScriptOnTarget(reinterpret_cast<TESObjectREFR*>(::_g_thePlayer), 0);
                if ((*(::CHALLENGE_TYPE *)(reinterpret_cast<::FUN_006a1b60_Class *>((challenge))->GetField54())) != CHALLENGE_TYPE_CHALLENGE_TYPE_MISC_STAT ||
                    ((int)(reinterpret_cast<::FUN_005f5fa0_cls *>((challenge))->GetShortAtOffset64())) != 27)
                    TopicMenuController::IncrementMiscStat(27);
                if (((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((challenge))->FUN_00408da0())) && challenge->GetDescription(0, (CHUNK_ID)0x43534544) &&
                    (*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011cb4d4)).Bool()->b)
                {
                    char message[512];
                    ::FUN_00406d00(message, sizeof(message), "%s   %d\\%d\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((challenge))->FUN_00408da0())),
                              reinterpret_cast<::LowProcess *>((challenge))->GetPackageObjectType(), reinterpret_cast<::LowProcess *>((challenge))->GetPackageObjectType(),
                              challenge->GetDescription(0, (CHUNK_ID)0x43534544));
                    ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::FUN_0048e730(challenge, (int)(0))), (const char *)(0),
                                           ::DAT_010162c0, false);
                    ::FUN_00706f30(21);
                }
                if (reinterpret_cast<::FUN_005f5f60_class *>((challenge))->FUN_005f5f60() && !reinterpret_cast<::FUN_005f60c0_Class *>((challenge))->HasFlag8())
                {
                    int excess = challenge->progress.iProgress - reinterpret_cast<::LowProcess *>((challenge))->GetPackageObjectType();
                    reinterpret_cast<::FUN_005f5820_shell *>((challenge))->ClearField6C();
                    reinterpret_cast<::FUN_005f6060_class *>((challenge))->FUN_005f6060(true);
                    challenge->FUN_005f60e0(excess);
                }
                else
                {
                    reinterpret_cast<::FUN_005f6000_Class *>((challenge))->SetFlagAndMarkForSave(true);
                    completed = true;
                }
            }
            else
            {
                struct ProgressInterval
                {
                    int interval;
                    int progress;
                } values;
                values.progress = challenge->progress.iProgress;
                values.interval = ((std::intptr_t)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((challenge))->FUN_005f5f80())) ? ((std::intptr_t)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((challenge))->FUN_005f5f80())) : 100;
                for (int value = values.progress; value >= 0; value -= values.interval)
                {
                    if (value == 0)
                    {
                        if (((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((challenge))->FUN_00408da0())) && challenge->GetDescription(0, (CHUNK_ID)0x43534544) &&
                            (*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011cb4d4)).Bool()->b)
                        {
                            char message[512];
                            ::FUN_00406d00(message, sizeof(message), "%s   %d\\%d\n%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((challenge))->FUN_00408da0())),
                                      challenge->progress.iProgress, reinterpret_cast<::LowProcess *>((challenge))->GetPackageObjectType(),
                                      challenge->GetDescription(0, (CHUNK_ID)0x43534544));
                            ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::FUN_0048e730(challenge, (int)(0))),
                                                   (const char *)(0), ::DAT_010162c0, false);
                        }
                    }
                }
            }
        }
        list = ((::BSSimpleList< ::TESChallenge *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
    if (completed)
        CheckCompletedChallenges();
    return true;
}

// @fnv 0x005f5820
void FUN_005f5820_shell::ClearField6C()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x6c) = 0;
}

struct FUN_0051b070_shell
{
};

struct FUN_0059adb0_shell
{
    void FUN_0059adb0(unsigned int aiFlags);
};

// @fnv 0x0059adb0
void FUN_0059adb0_shell::FUN_0059adb0(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>((((FUN_0051b070_shell*)this)))->FUN_00484c20(aiFlags);
}

struct TESFormStub
{
};

struct FUN_00616640_shell : public TESFormStub
{
    void FUN_00616640(unsigned int aiFlags, unsigned int aiCurrentFlags);
};

// @fnv 0x00616640
void FUN_00616640_shell::FUN_00616640(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((this))->FUN_00484c50(aiFlags, aiCurrentFlags);
}

struct TESQuest
{
    PerkEntryConditionSet* GetConditions(void);
};

struct FUN_005e79a0_t
{
};


struct FUN_005f56b0_shell
{
    bool IsNotEqual(TESForm* apCompare);
};

// Compares this TESChallenge against apCompare: returns true if it is not a TESChallenge or if data, form two, form one or the base comparison differ.
// @fnv 0x005f56b0
bool FUN_005f56b0_shell::IsNotEqual(TESForm* apCompare)
{
    TESChallenge* pcomp = dynamic_cast<TESChallenge*>(apCompare);
    if (!pcomp)
        return true;
    if (std::memcmp(&((TESChallenge*)this)->data, ((TESQuest*)pcomp)->GetConditions(), 0x18) != 0)
        return true;
    if (((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((((TESChallenge*)this)))->FUN_00407820())) != ((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((pcomp))->FUN_00407820())))
        return true;
    if (((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((((TESChallenge*)this)))->FUN_004fd3a0())) != ((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((pcomp))->FUN_004fd3a0())))
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcomp))
        return true;
    return false;
}

struct FUN_005f4ee0_shell
{
    void* FUN_005f4ee0(unsigned int);
};
struct FUN_004855a0
{
};
struct S_00487010
{
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_00482cb0_shell
{
    void FUN_00482cb0();
};
struct FUN_0048e370_obj
{
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct FUN_00485e00_shell
{
};
struct FUN_00485680
{
};
struct FUN_005f5540_shell : ::TESChallenge
{
    void Initialize();
};
struct FUN_005e78f0_t
{
};


struct FUN_005f5630_shell
{
    void CopyFromChallenge(TESForm* apCopy);
};

// Copies the TESChallenge data block and both forms from apCopy into this challenge, then calls FUN_004851b0 with apCopy.
// @fnv 0x005f5630
void FUN_005f5630_shell::CopyFromChallenge(TESForm* apCopy)
{
    TESChallenge* challenge = dynamic_cast<TESChallenge*>(apCopy);
    if (!challenge)
        return;
    ::__memcpy(&((TESChallenge*)this)->data, &challenge->data, sizeof(ChallengeData));
    reinterpret_cast<::TESObjectACTI *>((((TESChallenge*)this)))->SetLoopingSound((::TESSound *)(::TESForm *)(((::TESForm *)(reinterpret_cast<::FUN_004fd3a0_shell *>((challenge))->FUN_004fd3a0()))));
    reinterpret_cast<::TESObjectACTI *>((((TESChallenge*)this)))->SetActivateSound((::TESSound *)(::TESForm *)(((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((challenge))->FUN_00407820()))));
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)((TESChallenge*)this))))->FUN_004851b0(apCopy);
}

struct BGSSaveFormBuffer
{
};
struct FUN_00484d60_holder
{
};
struct FUN_005f5780_holder
{
    void FUN_005f5780(BGSSaveFormBuffer*);
};
// Calls the base save routine, then writes the 4-byte values at offsets 0x6C and 0x70 into the save buffer.
// @fnv 0x005f5780
void FUN_005f5780_holder::FUN_005f5780(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FakeForm *>((((FUN_00484d60_holder*)this)))->SaveIfChanged(apBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x6C, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x70, 4, 0);
}

struct BSIntToType1
{
    char c;
};
struct BSIntToType10
{
    char c;
};
struct BSIntToType2
{
    char c;
};
struct BSIntToType4
{
    char c;
};
struct BSIntToType8
{
    char c;
};
struct BSIntToType16
{
    char c;
};
struct BSIntToType32
{
    char c;
};

struct FUN_005f5480_shell : ::ChallengeData
{
    void SwapEndianFields();
};
// @fnv 0x005F51A0
bool TESChallenge::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    CHUNK_ID chunk;
    while (chunk = (CHUNK_ID)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case (CHUNK_ID)0x44494445: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case (CHUNK_ID)0x444e424f:
            readOBNDSubRecord(file);
            break;
        case (CHUNK_ID)0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case (CHUNK_ID)0x4e4f4349:
            ::TESTexture::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case (CHUNK_ID)0x4f43494d:
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case (CHUNK_ID)0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::Script *)(reinterpret_cast<Script*>(scriptID)));
            TESScriptableForm::InitItem(this);
            break;
        }
        case (CHUNK_ID)0x43534544:
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case (CHUNK_ID)0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_005f5480_shell *>(&(data))->SwapEndianFields();
            break;
        case (CHUNK_ID)0x4d414e53: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::TESObjectACTI *>(this)->SetLoopingSound((::TESSound *)(::TESForm *)(reinterpret_cast<TESForm*>(formID)));
            break;
        }
        case (CHUNK_ID)0x4d414e58: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound((::TESSound *)(::TESForm *)(reinterpret_cast<TESForm*>(formID)));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
// @fnv 0x005f5540
void FUN_005f5540_shell::Initialize()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)static_cast<TESFullName *>(this))))->FUN_00487010();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)static_cast<TESIcon *>(this))))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)static_cast<BGSMessageIcon *>(this))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)static_cast<TESScriptableForm *>(this))->FUN_0048cca0();
    ((FUN_00482cb0_shell*)static_cast<TESDescription *>(this))->FUN_00482cb0();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005f5480_shell *>(((&this->data)))->SwapEndianFields();
    reinterpret_cast<::SDSaveForm *>((((FUN_00485e00_shell*)this)))->FUN_00485e20((const void *)((std::intptr_t)((char*)&this->data)), 0x18);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005f5480_shell *>(((&this->data)))->SwapEndianFields();
    if (*(unsigned int*)((char*)this + 0x74))
    {
        unsigned int v1 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((&this->m_pPrimaryForm)[0]))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, v1);
    }
    if (*(unsigned int*)((char*)this + 0x78))
    {
        unsigned int v2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((&this->m_pSecondaryForm)[0]))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e58, v2);
    }
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

// Byte-swaps the fields at offsets 0, 4, 8, 12, 16, 18 and 20 of this object to the opposite endianness.
// @fnv 0x005f5480
void FUN_005f5480_shell::SwapEndianFields()
{
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this));
    ::FUN_00401080((int *)(unsigned char *)&this->m_iAuxiliaryValue);
    ::FUN_00407a90((short *)(unsigned char *)&this->nFlags);
    ::FUN_00401080((int *)(unsigned char *)&this->m_iRecordIndex);
    ::FUN_00407a90((short *)(unsigned char *)&this->FlaggedRecordValueEntry);
    ::FUN_00407a90((short *)(unsigned char *)&this->RecordIndexValueData);
    ::FUN_00407a90((short *)(unsigned char *)&this->IndexedRecordValueTriple);
}

class B5F4F10Form
{
  public:
    virtual ~B5F4F10Form();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    void* m_pkSourceFile;
    void* m_pkNextSourceFile;
};

class B5F4F10FullName
{
  public:
    virtual void Init();
    ~B5F4F10FullName();

    const char* m_pcName;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

class B5F4F10Description
{
  public:
    virtual void Init();

    unsigned int m_uiFileOffset;
};

class B5F4F10ScriptableForm
{
  public:
    virtual void Init();

    void* m_pkScript;
    bool m_bScriptReady;
};

class B5F4F10Icon
{
  public:
    virtual void Init();
    ~B5F4F10Icon();

    const char* m_pcPath;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

class B5F4F10Container
{
  public:
    virtual void Init();
    ~B5F4F10Container();

    void* m_pkFirst;
    void* m_pkNext;
};

class FUN_005f4f10_cls : public B5F4F10Form,
                         public B5F4F10FullName,
                         public B5F4F10Description,
                         public B5F4F10ScriptableForm,
                         public B5F4F10Icon,
                         public B5F4F10Container
{
  public:
    virtual ~FUN_005f4f10_cls();
};
// Calls FUN_005f4f10 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005f4ee0
void* FUN_005f4ee0_shell::FUN_005f4ee0(unsigned int flags)
{
    reinterpret_cast<::FUN_005f4f10_cls *>((this))->FUN_005f4f10_cls::~FUN_005f4f10_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x005f4f10
FUN_005f4f10_cls::~FUN_005f4f10_cls()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}
