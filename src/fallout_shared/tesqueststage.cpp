// fallout_shared/tesqueststage.cpp: PlayerQuestData, TESQuest, StageHolder (15 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_005dc960_shell.h"
#include "fnv/decl/FUN_0060ca30_shell.h"
#include "fnv/decl/FUN_0060caf0_shell.h"
#include "fnv/decl/FUN_0060d5e0_shell.h"
#include "fnv/decl/FUN_0060f3a0_shell.h"
#include "fnv/decl/FUN_0060fd90_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00867c60_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_009528c0_shell.h"
#include "fnv/decl/Obj_009529d0.h"
#include "fnv/decl/Scr.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_00722f60__SL.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005cb000.h"
#include "fnv/symbols_005dc000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011de000.h"
#include "tesqueststage_decls.h"
#include <malloc.h>

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" const char DAT_0104af30[];

// @fnv 0x0060f6a0
bool PlayerQuestData::Load(TESFile* file)
{
    if (!file)
        return false;

    switch (static_cast<int>(((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))))
    {
    case 0x44534c53:
    case 0x52564353:
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x44534c53)
        {
            DAT_011cb8ec = new ScriptVariableInfo();
            DAT_011cb8ec->Load(file);
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(&(m_pScript))->FUN_005d43e0()))))->FUN_00905820((void *)&(DAT_011cb8ec));
        }
        else if (DAT_011cb8ec)
        {
            char* data = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(data), 0x200);
            reinterpret_cast<::TextString *>(&(DAT_011cb8ec->m_name))->FUN_004037f0(data, 0);
        }
        break;
    case 0x52484353: {
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(m_pScript))->GetConditions()))), 0);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_00414220_shell *>((((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(m_pScript))->GetConditions()))))->FUN_00414220();
        break;
    }
    case 0x41444353: {
        unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
        char* data = static_cast<char*>(_alloca(size));
        memset(data, 0, size);
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(data), 0);
        reinterpret_cast<::FUN_005aae70_shell *>(&(m_pScript))->FUN_005aae70(size, data);
        break;
    }
    case 0x4f524353: {
        ScriptReferencedObject* object = new ScriptReferencedObject();
        unsigned int value;
        file->GetChunkData(&value);
        object->m_iOwnerObjectOffset = value;
        reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(m_pScript))->FUN_005d43c0()))))->FUN_00905820((void *)&(object));
        break;
    }
    case 0x56524353: {
        ScriptReferencedObject* object = new ScriptReferencedObject();
        unsigned int value;
        file->GetChunkData(&value);
        object->m_uiFilterValue = value;
        reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(m_pScript))->FUN_005d43c0()))))->FUN_00905820((void *)&(object));
        break;
    }
    case 0x54445351:
        m_formID = file->GetOffset();
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(this), 1);
        break;
    }

    if (!file->NextChunk())
        return false;
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x304d414e)
    {
        unsigned int nameIndex;
        file->GetChunkData(&nameIndex);
        m_nameIndex = nameIndex;
        if (!file->NextChunk())
            return false;
    }
    return true;
}

// Empty destructor for the object; performs no work.
// @fnv 0x0060c840
QuestStage::~QuestStage()
{}

void TriggerTESQuestStageDelete(QuestStage* stage)
{
    delete stage;
}

// Reads a QSTA chunk from the file, applies endian conversion if needed, and stores its two fields into the object.
// @fnv 0x00610120
void RegionObjectEntry::Load(TESFile* file)
{
    if (file)
    {
        if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x41545351)
        {
            RegionDataEntry data;
            memset(&data, 0, 8);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), 0);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>(&(data))->FUN_00503210();
            m_uiEdgeIndex = data.m_ucClipIdentifier;
            m_done = data.m_bCompleted;
        }
    }
}

// Walks the quest's stage list and returns the entry whose index matches the given index, or null if none matches.
// @fnv 0x0060db40
QuestStage* TESQuest::GetStage(unsigned char index)
{
    BSSimpleList<TESFile*>* stage = reinterpret_cast<BSSimpleList<TESFile*>*>(((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0())));
    while (stage)
    {
        QuestStage* item = reinterpret_cast<QuestStage*>(((::TESFile *)(new ((void *)(stage)) ::Vec3())));
        if (item && ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((item))->FUN_009373f0())) == index)
            return item;
        stage = ((::BSSimpleList< ::TESFile *> *)(reinterpret_cast<::Callees *>((stage))->FUN_00726070()));
    }
    return 0;
}

// @fnv 0x0060fa10
void PlayerQuestData::InitItem(TESForm* form, QuestStage* stage)
{
    int iErrorCount;
    unsigned int auiFormId;
    unsigned int iOldCount;
    if (((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData())))
        ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()))->InitItem(form);
    iOldCount = ::FUN_0046e8a0();
    ::FUN_0043b2b0(true);
    ::FUN_004fffe0(0);
    reinterpret_cast<::Scr *>((((::Script *)(::GetOffsetC((int)this)))))->FUN_005ab400(form);
    ::FUN_0043b2b0(false);
    iErrorCount = ::FUN_0046e8a0();
    ::FUN_004fffe0(iOldCount);
    if (iErrorCount)
        ::FUN_005b5e40();
    m_pSharedOwner = dynamic_cast<TESQuest*>(form);
    auiFormId = m_nameIndex;
    if (auiFormId)
    {
        ::ResolveFormID((unsigned int *)&(auiFormId), form->GetFile(-1));
        TESQuest* next = dynamic_cast<TESQuest*>(::FUN_004839c0(auiFormId));
        if (!next)
            ::FUN_005b5e40();
        reinterpret_cast<::fnv_0057bd60::fnv_anon_tesobjectrefr::Dummy *>(this)->FUN_0057bd60((::fnv_0057bd60::MobileObject *)(next));
    }
}

void __fastcall ResetFlags(void* pThis);

class RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
};

// @fnv 0x0060f210
void* __fastcall FUN_0060f210(char* pThis)
{
    ResetFlags(pThis);
    new ((void *)(((RecursiveSpinLock*)(pThis + 4)))) ::fnv_00722f60::SL();
    return pThis;
}

struct IntList
{
    ~IntList();
};
struct FUN_0060f260
{
    char pad[4];
    IntList list;
    ~FUN_0060f260();
};
// @fnv 0x0060f260
FUN_0060f260::~FUN_0060f260()
{
    reinterpret_cast<::FUN_0060f3a0_shell *>(this)->FUN_0060f3a0();
}

struct FUN_0060f320_shell : public QuestStage
{
    void FUN_0060f320(TESForm*);
};

struct StageItemNode;

// Walks the stage item list, calls InitItem on each non-null item, clears a header byte, and counts the items.
// @fnv 0x0060f320
void FUN_0060f320_shell::FUN_0060f320(TESForm* apOwner)
{
    StageItemNode* pNode = ((::StageItemNode *)(reinterpret_cast<::BaseProcess *>((this))->GetCurrentProcessData()));
    int iCount = 0;
    while (pNode)
    {
        PlayerQuestData* pitem = *((::PlayerQuestData **)(new ((void *)(pNode)) ::Vec3()));
        if (pitem)
        {
            pitem->InitItem(apOwner, this);
            reinterpret_cast<unsigned char*>(((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((((::Script *)(::GetOffsetC((int)(pitem))))))->GetConditions())))[0x10] = 0;
            iCount = iCount + 1;
        }
        pNode = ((::StageItemNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
}

struct StageHolder
{
    void FUN_0060f4a0(TESQuest* quest, bool done);
};
// @fnv 0x0060f4a0
void StageHolder::FUN_0060f4a0(TESQuest* quest, bool done)
{
    QuestStage* stage;
    BSSimpleList<QuestStage*>* list;
    if (!reinterpret_cast<::FUN_005dc960_shell *>(this)->FUN_005dc960() || (quest && reinterpret_cast<::FUN_0060d5e0_shell *>((quest))->HasFlag8()))
    {
        ((char*)this)[1] = 1;
        list = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
        while (list)
        {
            stage = ((::QuestStage *)(new ((void *)(list)) ::Vec3()));
            list = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
            if (stage)
                stage->MarkDone(done);
        }
    }
}

struct CondS
{
    char p[8];
    CondS();
    ~CondS();
};
struct HdrS
{
    char p[0x10];
    char flag;
};
struct ScriptS
{
    char p[0x54];
    ScriptS();
    ~ScriptS();
};
struct FUN_0060f520
{
    char b0[4];
    CondS cond;
    ScriptS script;
    int v60;
    char v64;
    char v65;
    char pad[2];
    int v68;
    int v6c;
    int v70;
    FUN_0060f520();
};
// @fnv 0x0060f520
FUN_0060f520::FUN_0060f520()
{
    memset(this, 0, 1);
    v70 = 0;
    reinterpret_cast<::TESForm *>(&(script))->SetInitializationState(0);
    reinterpret_cast<::TESForm *>(&(script))->NotifySaveLoadGameOfFormChange();
    ((::HdrS *)(reinterpret_cast<::BGSCameraPath *>(&(script))->GetConditions()))->flag = 1;
    v60 = 0;
    v68 = 0;
    v6c = 0;
    v64 = 0;
    v65 = 0;
}

struct FUN_0060fd70_shell : public PlayerQuestData
{
    bool FUN_0060fd70();
};
// @fnv 0x0060fb60
void QuestStage::MarkDone(bool done)
{
    if (m_pCompletionDate && m_pSharedOwner && !reinterpret_cast<::FUN_0060d5e0_shell *>((m_pSharedOwner))->HasFlag8())
    {
        ::FUN_005b5e40();
        return;
    }
    if (done || ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<PlayerQuestData*>(this)))->GetCurrentProcessData()))->ContainsTrait(::_g_thePlayer, 0))
    {
        m_pCompletionDate = new Date(((signed char)(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::Calendar *>(&::g_011de7b8))))->GetDayOfMonth())), (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetCurrentMonth(), reinterpret_cast<::FUN_00867c60_shell *>(&((*reinterpret_cast<::Calendar *>(&::g_011de7b8))))->FUN_00867c60());

        if (reinterpret_cast<::FUN_0060fd70_shell *>(this)->FUN_0060fd70())
        {
            if (m_pSharedOwner)
            {
                reinterpret_cast<::FUN_0060ca30_shell *>((m_pSharedOwner))->FUN_0060ca30(true);
                if (m_pSharedOwner == ((::TESQuest *)(::FUN_005cbb50((char *)(::_g_thePlayer)))))
                    reinterpret_cast<::Obj_009529d0 *>((::_g_thePlayer))->FUN_009529d0(0);
            }
        }
        if (reinterpret_cast<::FUN_0060fd90_Class *>(this)->IsFlag2Set())
        {
            if (m_pSharedOwner)
            {
                reinterpret_cast<::FUN_0060caf0_shell *>((m_pSharedOwner))->FUN_0060caf0(true);
                if (m_pSharedOwner == ((::TESQuest *)(::FUN_005cbb50((char *)(::_g_thePlayer)))))
                    reinterpret_cast<::Obj_009529d0 *>((::_g_thePlayer))->FUN_009529d0(0);
            }
        }
        if (m_bCompleteObjective)
            reinterpret_cast<::FUN_009528c0_shell *>((::_g_thePlayer))->AddChallenge((::TESChallenge *)(::PlayerQuestData *)(reinterpret_cast<PlayerQuestData*>(this)));

        Script* script = ((::Script *)(::GetOffsetC((int)this)));
        if (::Script::IsConsolePlatform() && script && ((::PackageList *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<TESAIForm*>(script)))->GetConditions()))->packages)
        {
            ((::PackageList *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<TESAIForm*>(script)))->GetConditions()))->m_ucPackageFlag = 0;
            reinterpret_cast<::FUN_005ac1e0_shell *>((script))->FUN_005ac1e0(::_g_thePlayer, (::ScriptLocals *)(void *)(((void *)(reinterpret_cast<::FUN_00418830_shell *>((((::ScriptContext *)(reinterpret_cast<::FUN_005d43c0_ *>((::_g_thePlayer))->FUN_005d43c0()))))->FUN_00418830()))), {}, {});
        }
    }
}

// @fnv 0x0060fd70
bool FUN_0060fd70_shell::FUN_0060fd70()
{
    return (*(unsigned char*)this & 1) != 0;
}

namespace fnv_0060f2c0 {
struct StageItemNode;
struct FUN_0060f2c0_shell
{
    const char* FindItemByDoneFlag(unsigned char);
};
// Walks the linked StageItemNode list, returning the first item whose FUN_005dc980 result equals done, or null.
// @fnv 0x0060f2c0
const char* FUN_0060f2c0_shell::FindItemByDoneFlag(unsigned char done)
{
    StageItemNode* pNode = ((::fnv_0060f2c0::StageItemNode *)(reinterpret_cast<::BaseProcess *>((this))->GetCurrentProcessData()));
    while (pNode)
    {
        const char* item = *((const char **)(new ((void *)(pNode)) ::Vec3()));
        if (item && (unsigned char)::FUN_005dc980(item) == done)
            return item;
        pNode = ((::fnv_0060f2c0::StageItemNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return 0;
}
}  // namespace fnv_0060f2c0

// Stage reset helper: clears the two flag bytes of the stage object and
// hands the object back to the caller.
class FUN_0060f240_cls
{
  public:
    unsigned char m_bDone;
    unsigned char m_bHasSomething;
    FUN_0060f240_cls* ResetFlags();
};

// @fnv 0x0060f240
FUN_0060f240_cls* FUN_0060f240_cls::ResetFlags()
{
    m_bDone = 0;
    m_bHasSomething = 0;
    return this;
}

// Destructor: clear the shared current-entry globals and free the owned decal data; the member lists go after.

class F5F0String
{
  public:
};


class F5F0DecalData
{
  public:
    ~F5F0DecalData();
    int unk00;
};

class F5F0EntryList
{
  public:
    ~F5F0EntryList();
    int unk00;
    int unk04;
};

class F5F0EntryMap
{
  public:
    ~F5F0EntryMap();
    int unk00;
    int unk04;
    int unk08;
};

class FUN_0060f5f0
{
  public:
    ~FUN_0060f5f0();

    int m_iArrayLength;
    F5F0EntryList m_kEntries;
    F5F0EntryMap m_kFormatEntries;
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
    F5F0DecalData* m_pkDecalData;
};

// Resets the current entry index and name, then deletes m_pkDecalData if set.
// @fnv 0x0060f5f0
FUN_0060f5f0::~FUN_0060f5f0()
{
    g_iF5F0CurrentEntry = 0;
    reinterpret_cast<::TextString *>(&((*reinterpret_cast<::F5F0String *>(&::g_011cb8a0))))->FUN_004037f0(0, 0);
    if (m_pkDecalData)
        delete m_pkDecalData;
}
