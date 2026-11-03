// fallout_shared/tesquesttarget.cpp: free functions (5 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041c8d0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tesquesttarget_decls.h"

// Resolves the stored reference form ID against the quest's file, warns if it is missing, then initializes the conditions.
// @fnv 0x00610040
void RegionObjectEntry::InitItem(TESForm* form)
{
    if (m_pReference)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pReference);
        ::ResolveFormID((unsigned int *)&(formID), form->GetFile(-1));
        m_pReference = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(formID));
        if (!m_pReference)
            ::FUN_005b5e40();
    }
    else
    {
        ::FUN_005b5e40();
    }
    if (((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData())))
        ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()))->InitItem(form);
}

// @fnv 0x0060f440
void QuestStage::Load(TESFile* file)
{
    if (file && ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x58444e49)
    {
        if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 8)
        {
            TESQuestStageLegacyData legacy;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&legacy), sizeof(legacy));
            m_Data.m_bCompleted = legacy.data.m_bCompleted;
            m_Data.m_ucClipIdentifier = legacy.data.m_ucClipIdentifier;
        }
        else
        {
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_Data), sizeof(m_Data));
        }
    }
}

// Returns the stored reference, replacing it with its extra-data replacement when it is deleted and resolveDeleted is set.
// @fnv 0x006101b0
TESObjectREFR* RegionObjectEntry::GetReference(bool resolveDeleted)
{
    TESObjectREFR* reference = m_pReference;
    if (reference && reinterpret_cast<::FUN_00440d80_shell *>((void *)(reference))->FUN_00440d80() && resolveDeleted)
    {
        TESObjectREFR* replacement = reinterpret_cast<::FUN_0041c8d0_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041c8d0();
        if (replacement)
            reference = replacement;
    }
    return reference;
}

struct CondS
{
    void* pHead;
    void* pTail;
    CondS();
    ~CondS();
};
struct PathingPath
{
    char _pad[0x10];
    PathingPath();
};

struct FUN_0060ff70
{
    unsigned char cFlags;
    CondS m_kInfoConditions;
    void* m_pReference;
    PathingPath m_auiData;
    FUN_0060ff70();
};

// @fnv 0x0060ff70
FUN_0060ff70::FUN_0060ff70()
{
    m_pReference = 0;
    cFlags = 0;
}

struct FUN_006808b0
{
    void* pHead;
    void* pTail;
    ~FUN_006808b0();
};
struct TeleportPathHelper
{
    char _pad[0x10];
    ~TeleportPathHelper();
};
struct FUN_0060ffe0
{
    unsigned char cFlags;
    FUN_006808b0 mCond;
    void* m_pReference;
    TeleportPathHelper mPath;
    ~FUN_0060ffe0();
};
// Destructor for the object; the body is empty, so member destruction is handled by the compiler-generated code.
// @fnv 0x0060ffe0
FUN_0060ffe0::~FUN_0060ffe0()
{}
