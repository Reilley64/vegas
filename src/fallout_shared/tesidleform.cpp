// fallout_shared/tesidleform.cpp: TESIdleForm, IdleCopy, IdleFormDetach, IdleInit (29 functions)

#include <new>
#include <cstring>
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004867a0_cls.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005ff5d0_class.h"
#include "fnv/decl/FUN_005ffbf0_shell.h"
#include "fnv/decl/FUN_006004f0_shell.h"
#include "fnv/decl/FUN_006005c0_shell.h"
#include "fnv/decl/FUN_00600d90.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_00680a70_shell.h"
#include "fnv/decl/FUN_00843150_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cb000.h"
#include "tesidleform_match_decls.h"
class TESObjectREFR;
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
public:
    ::TESObjectREFR *GetTarget();
public:
    void SetCurrentCombatTarget(::TESObjectREFR *);
};

// @fnv 0x005fe3b0
void TESIdleForm::ResetFormData(void)
{
    data.m_ucAnimationGroupSection = 7;
    data.m_ucLoopingMin = 0;
    data.m_ucLoopingMax = 0;
    data.m_usReplayDelay = 0;
    data.m_ucIdleFlags = 0;
    m_pParentIdleForm = 0;
    m_pIdleForm = 0;
}

// @fnv 0x005ff280
bool TESIdleForm::IsIdleFile(void)
{
    bool isIdleFile = false;
    const char* extension = strrchr(GetModelFilePath(), '.');
    if (extension && ::FUN_00404dc0(extension, ".kf") == 0)
        isIdleFile = true;
    return isIdleFile;
}

// @fnv 0x005ff430
bool TESIdleForm::IsValidForReferences(TESObjectREFR* actionRef, TESObjectREFR* targetRef, bool recurseUp)
{
    bool conditionsMet = false;
    if (reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
            ->ContainsTrait(actionRef, targetRef))
    {
        if (recurseUp && reinterpret_cast<LowProcess*>(this)->GetActiveCombatTarget())
        {
            conditionsMet = reinterpret_cast<TESIdleForm*>(reinterpret_cast<LowProcess*>(this)->GetActiveCombatTarget())
                                ->IsValidForReferences(actionRef, targetRef, recurseUp);
        }
        else
        {
            conditionsMet = true;
        }
    }
    return conditionsMet;
}

// Scans the form array for this idle and its next idle, then moves the next idle to directly follow this one and reorders it.
// @fnv 0x005fefa0
void TESIdleForm::BuildIdleParentPath(NiFormArray* array)
{
    if (!array)
        return;
    struct IdleOrderState
    {
        unsigned int missing;
        unsigned int nextIndex;
        unsigned int index;
        TESIdleForm* next;
        unsigned int size;
    } orderState;
    orderState.missing = 0;
    orderState.index = -1;
    orderState.size = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((array))->FUN_0084e3a0()));
    orderState.nextIndex = -1;
    orderState.next = 0;
    for (unsigned int i = 0; i < orderState.size; ++i)
    {
        TESIdleForm* idle = dynamic_cast<TESObjectANIO*>(array->FUN_00877a30(i));
        if (idle)
        {
            if (idle == this)
                orderState.index = i;
            else if (reinterpret_cast<TESIdleForm*>(reinterpret_cast<BGSImpactData*>(idle)->GetDecalTextureSet()) ==
                     this)
            {
                if (!orderState.next)
                {
                    orderState.next = idle;
                    orderState.nextIndex = i;
                }
                else
                {
                    BSStringT<char> name;
                    GetDebugName(&name);
                    ::FUN_005b5e40();
                }
            }
        }
        else
            ++orderState.missing;
    }
    if (orderState.index != -1 && orderState.nextIndex != -1 && orderState.nextIndex != orderState.index + 1)
    {
        unsigned int removed = 0;
        array->SetSize(orderState.nextIndex, &removed);
        array->Compact();
        if (orderState.nextIndex < orderState.index)
            ++orderState.missing;
        orderState.index -= orderState.missing;
        array->SetFormAtIndex(orderState.index + 1, orderState.next);
        array->Compact();
        orderState.next->BuildIdleParentPath(array);
    }
}

template <int N> struct EndianSizeTag
{
};


struct FUN_005fea20_shell
{
    void SwapEndian();
};
// Reads the idle form's chunk stream (EDID, OBND, MODL/MODT, DATA, CTDA, ANAM), applying each subrecord and returning true on success.
// @fnv 0x005fe810
bool TESIdleForm::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((reinterpret_cast<TESFileFormInt*>(file)))->FUN_00472660() != 0x48)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    struct ReferenceItemCountEntry
    {
        FUN_005a71d0 links;
        char* editorID;
        int chunk;
    } idleRecord;
    while ((idleRecord.chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (idleRecord.chunk)
        {
        case 0x44494445:
            idleRecord.editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(idleRecord.editorID), 512);
            SetEditorID_AtRuntime(idleRecord.editorID);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, &data, 8);
            break;
        case 0x41445443:
            reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())->Load(file);
            break;
        case 0x4d414e41:
            memset(&idleRecord.links, 0, 8);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&idleRecord.links), 8);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::S_00462230 *>(&(idleRecord.links))->FUN_00462230();
            m_pParentIdleForm = reinterpret_cast<TESIdleForm*>(idleRecord.links.parent);
            m_pIdleForm = reinterpret_cast<TESIdleForm*>(idleRecord.links.previous);
            reinterpret_cast<::FUN_005ffbf0_shell *>((DAT_011cb6a0))->AddIdleToArray(this);
            break;
        }
        if (idleRecord.chunk == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_005fea20_shell *>(&(data))->SwapEndian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Swaps the byte order of the 16-bit value at object offset 4 using BSEndian.
// @fnv 0x005fea20
void FUN_005fea20_shell::SwapEndian()
{
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)((char*)this + 4)));
}

struct FUN_005ff190_shell
{
    char pad[0x38];
    unsigned char m_0x38;
    void FUN_005ff190(bool set);
};

// @fnv 0x005ff190
void FUN_005ff190_shell::FUN_005ff190(bool set)
{
    bool b = set;
    m_0x38 &= 0xC0;
    m_0x38 |= b;
}

struct FUN_005ff1d0_shell : public TESIdleForm
{
    bool FUN_005ff1d0();
};

// Returns true when the flag bit 0x80 is set in the byte at offset 0x38 of this TESIdleForm, otherwise false.
// @fnv 0x005ff1d0
bool FUN_005ff1d0_shell::FUN_005ff1d0()
{
    if (this->data.m_ucAnimationGroupSection & 0x80)
        return true;
    else
        return false;
}

struct FUN_005ff200_shell
{
    unsigned char m_0x38;
    bool IsFlag40Set();
};
// @fnv 0x005fedb0
bool TESIdleForm::HasMissingPathArray()
{
    bool success = true;
    struct ParentState
    {
        TESIdleForm* parent;
        unsigned int index;
        TESIdleForm* previous;
        NiFormArray* array;
    } state;
    state.parent = m_pParentIdleForm;
    state.previous = m_pIdleForm;
    if (reinterpret_cast<::FUN_005ff200_shell *>(this)->IsFlag40Set())
    {
        NiFormArray* loose = DAT_011cb6a0->GetIdleArray(this);
        if (!loose)
        {
            reinterpret_cast<::FUN_006004f0_shell *>((DAT_011cb6a0))->GetFormArray((::TESForm *)(::TESIdleForm *)(this));
            loose = DAT_011cb6a0->GetIdleArray(this);
        }
        if (loose)
        {
            unsigned int size = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((loose))->FUN_0084e3a0()));
            loose->SetFormAtIndex(size, this);
        }
        else
        {
            ::FUN_005b5e40();
            success = false;
        }
        return success;
    }
    state.index = 0;
    state.array = 0;
    if (state.parent)
        state.array = state.parent->AssignParentPath();
    else
        state.array = reinterpret_cast<::FUN_006004f0_shell *>((DAT_011cb6a0))->GetFormArray((::TESForm *)(::TESIdleForm *)(this));
    if (state.array)
    {
        if (state.previous)
        {
            unsigned int previousIndex = state.array->GetIndexOfForm(state.previous);
            if (previousIndex != -1)
                ++previousIndex;
            state.index = previousIndex;
        }
        if (state.index == -1 || reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
            state.index = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((state.array))->FUN_0084e3a0())) + 1;
        state.array->SetFormAtIndex(state.index, this);
        BuildIdleParentPath(state.array);
    }
    else
    {
        BSStringT<char> name;
        GetDebugName(&name);
        ::FUN_005b5e40();
        success = false;
    }
    return success;
}

// @fnv 0x005ff200
bool FUN_005ff200_shell::IsFlag40Set()
{
    if (((unsigned char*)this)[0x38] & 0x40)
        return true;
    else
        return false;
}

struct FUN_005ff220_shell
{
    void SetFlag40(bool bFlag);
};

// Sets or clears bit 0x40 in the byte at offset 0x38 of this object based on bFlag.
// @fnv 0x005ff220
void FUN_005ff220_shell::SetFlag40(bool abSet)
{
    if (abSet)
        ((unsigned char*)this)[0x38] |= 0x40;
    else
        ((unsigned char*)this)[0x38] &= ~0x40;
}

struct FUN_005ff260_shell
{
    unsigned char m_3e;
    bool FUN_005ff260();
};

// @fnv 0x005ff260
bool FUN_005ff260_shell::FUN_005ff260()
{
    if (reinterpret_cast<unsigned char*>(this)[0x3e] & 1)
        return true;
    else
        return false;
}

struct FUN_005ff4a0_shell : public TESIdleForm
{
    unsigned int FUN_005ff4a0();
};

// Returns the form ID of the TESForm pointer stored at offset 0x40, or 0 if that pointer is null.
// @fnv 0x005ff4a0
unsigned int FUN_005ff4a0_shell::FUN_005ff4a0()
{
    unsigned int iretval = 0;
    if (reinterpret_cast<TESForm**>(&this->m_pParentPath)[0])
        iretval = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm**>(&this->m_pParentPath)[0]))->FUN_0084e3a0()));
    return iretval;
}

struct FUN_005ff160_shell : public TESIdleForm
{
    int GetFlagsMasked();
};

// Reads the byte at offset 0x38, clears bits 0x40 and 0x80, and returns the result.
// @fnv 0x005ff160
int FUN_005ff160_shell::GetFlagsMasked()
{
    unsigned char ctemp = this->data.m_ucAnimationGroupSection;
    ctemp &= 0xffffff3f;
    return ctemp;
}

struct FUN_00600d90_shell
{
};

struct FUN_00600d70_shell
{
    void FUN_00600d70();
};

// @fnv 0x00600d70
void FUN_00600d70_shell::FUN_00600d70()
{
    reinterpret_cast<::FUN_00600d90 *>((((FUN_00600d90_shell*)this)))->FUN_00600d90::~FUN_00600d90();
}

struct FUN_005fe130_shell
{
    void FUN_005fe180();
    void* FUN_005fe130(unsigned int);
};
struct FUN_005fe160_shell : public TESModel
{
    FUN_005fe160_shell();
};
// @fnv 0x005fe160
FUN_005fe160_shell::FUN_005fe160_shell()
{}

struct FUN_005ff4d0_shell : public TESIdleForm
{
    TESIdleForm* GetIdleFormByIndex(unsigned int);
};
// @fnv 0x005ff2e0
TESIdleForm* TESIdleForm::FindIdleFormForObject(TESObjectREFR* actionRef, TESObjectREFR* targetRef,
                                                BSSimpleList<IdleReplayDelayEntry*>* replayDelays)
{
    TESIdleForm* idle = 0;
    if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80() && reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
                            ->ContainsTrait(actionRef, targetRef))
    {
        bool delayed;
        if (IsIdleFile())
        {
            BSSimpleList<IdleReplayDelayEntry*>* pDelayIter = replayDelays;
            delayed = false;
            while (pDelayIter && !delayed && !reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(pDelayIter)->IsEmpty())
            {
                IdleReplayDelayEntry* pDelayEntry = reinterpret_cast<IdleReplayDelayEntry*>(
                    ((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pDelayIter))->m_item));
                if (*reinterpret_cast<TESIdleForm**>(pDelayEntry) == this)
                    delayed = true;
                pDelayIter = reinterpret_cast<BSSimpleList<IdleReplayDelayEntry*>*>(
                    ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pDelayIter)))->FUN_00726070())));
            }
            if (!delayed)
                idle = this;
        }
        else if (reinterpret_cast<::FUN_005ff1d0_shell *>(this)->FUN_005ff1d0())
            idle = this;
        unsigned int count = reinterpret_cast<::FUN_005ff4a0_shell *>(this)->FUN_005ff4a0();
        if (count)
        {
            TESIdleForm* childIdle = 0;
            for (unsigned int i = 0; i < count; ++i)
            {
                TESIdleForm* child = reinterpret_cast<::FUN_005ff4d0_shell *>(this)->GetIdleFormByIndex(i);
                if (child)
                    childIdle = child->FindIdleFormForObject(actionRef, targetRef, replayDelays);
                if (childIdle)
                    break;
            }
            if (childIdle)
                idle = childIdle;
        }
    }
    return idle;
}

struct FUN_004d6170_shell
{
    TESForm* FUN_004d6170(unsigned int);
};
struct Off40_5ff4d0
{
    char _0[0x40];
    FUN_004d6170_shell* p;
};
// Looks up the form at aiIndex through the pointer at offset 0x40 and returns it cast to TESIdleForm, or null if that pointer is unset.
// @fnv 0x005ff4d0
TESIdleForm* FUN_005ff4d0_shell::GetIdleFormByIndex(unsigned int aiIndex)
{
    TESIdleForm* pretidle = 0;
    if (((Off40_5ff4d0*)this)->p)
    {
        pretidle = dynamic_cast<TESIdleForm*>(((Off40_5ff4d0*)this)->p->FUN_004d6170(aiIndex));
    }
    return pretidle;
}


struct FUN_005ff770_shell
{
    char pad[0x39];
    unsigned char m_39;
    unsigned char m_3a;
    char GetRandomValue();
};

// Returns 0 if m_39 or m_3a is zero, m_39 if it is 0xff, m_3a-1 if m_3a <= m_39, else a random value in [m_39, m_3a] minus 1.
// @fnv 0x005ff770
char FUN_005ff770_shell::GetRandomValue()
{
    if (!m_39 || !m_3a)
        return 0;
    if (m_39 == 0xff)
        return (char)m_39;
    if (m_3a <= m_39)
        return (char)(m_3a - 1);
    return (char)(GetRandomNumberInRange(m_39, m_3a) - 1);
}

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char* dest, unsigned int size, const char* src);
};
struct BSStr
{
};
struct FUN_005ff7f0_shell
{
    bool SetStringIfChanged(const char* str);
};
// @fnv 0x005ff7f0
bool FUN_005ff7f0_shell::SetStringIfChanged(const char* str)
{
    unsigned int len = ::FUN_0044a670(str) + 1;
    char* buf = (char*)_alloca(len);
    TaskQueueInterface::CopyStringToBuffer(buf, len, str);
    if (reinterpret_cast<::B408A80String *>((void *)(((BSStr*)((char*)this + 0x4c))))->FUN_00408a80(buf, true) == 0)
        return false;
    reinterpret_cast<::TextString *>((((BSStr*)((char*)this + 0x4c))))->FUN_004037f0(buf, 0);
    return true;
}

struct FUN_005e79a0_t
{
};

struct FUN_005fe510_compare_shell
{
};

struct FUN_005fe510_shell
{
    char pad_0x00[0x38];
    unsigned char m_0x38;
    unsigned char m_0x39;
    unsigned char m_0x3a;
    char pad_0x3b;
    unsigned short m_0x3c;
    char pad_0x3d;
    unsigned char m_0x3e;

    bool IsDifferentFrom(TESForm* apCompare);
};

// Compares this TESIdleForm against apCompare: returns true if apCompare is not a TESIdleForm or if any compared field or add-topic list differs.
// @fnv 0x005fe510
bool FUN_005fe510_shell::IsDifferentFrom(TESForm* apCompare)
{
    TESIdleForm* pOtherIdle = dynamic_cast<TESIdleForm*>(apCompare);
    if (!pOtherIdle)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pOtherIdle))
        return true;

    if (reinterpret_cast<::PerkEntryConditionSet *>((reinterpret_cast<FUN_005fe510_compare_shell*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())))->Compare(reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(pOtherIdle)->GetAddTopicList())))
        return true;

    if (m_0x38 != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x38)
        return true;

    if (m_0x39 != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x39)
        return true;

    if (m_0x3a != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x3a)
        return true;

    if (m_0x3c != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x3c)
        return true;

    if (*(reinterpret_cast<unsigned char*>(&this->pad_0x3d)) !=
        *(reinterpret_cast<unsigned char*>(&(reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle))->pad_0x3d)))
        return true;

    return false;
}

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct FUN_004891d0_obj
{
};

struct Idle_008b2010
{
};

struct TESConditionSave
{
};

struct FUN_00485e00_shell
{
};

struct FUN_005fea50_shell
{
    void FUN_005fea50();
};


// @fnv 0x005fea50
void FUN_005fea50_shell::FUN_005fea50()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    reinterpret_cast<::FUN_004891d0_cls *>((reinterpret_cast<FUN_004891d0_obj*>(reinterpret_cast<char*>(this) + 0x18)))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));

    reinterpret_cast<::FUN_00680910_shell *>((reinterpret_cast<TESConditionSave*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())))->ProcessItems();

    FUN_005a71d0 a;
    BGSImpactData* pImpactData;

    memset(&a, 0, 8);

    if (((::Idle_008b2010 *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<Idle_008b2010*>(this)))->GetActiveCombatTarget())))
    {
        a.parent = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::Idle_008b2010 *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<Idle_008b2010*>(this)))->GetActiveCombatTarget())))))->FUN_0084e3a0()));
    }

    if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)(reinterpret_cast<TESForm*>(this)))->FUN_00440d80())
    {
        pImpactData = reinterpret_cast<BGSImpactData*>(reinterpret_cast<BGSImpactData*>(this)->GetDecalTextureSet());
        while (pImpactData && reinterpret_cast<::FUN_00440d80_shell *>((void *)(reinterpret_cast<TESForm*>(pImpactData)))->FUN_00440d80())
            pImpactData = reinterpret_cast<BGSImpactData*>(pImpactData->GetDecalTextureSet());
        if (pImpactData)
            a.previous = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(pImpactData)))->FUN_0084e3a0()));
    }

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::S_00462230 *>(&(a))->FUN_00462230();

    ::AppendChunk(0x4d414e41, &a, 8);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::S_00462230 *>(&(a))->FUN_00462230();

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005fea20_shell *>((reinterpret_cast<IdleAnimationData*>(reinterpret_cast<char*>(this) + 0x38)))->SwapEndian();

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20(
        (const void *)(reinterpret_cast<int>(reinterpret_cast<char*>(this) + 0x38)), 8);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_005fea20_shell *>((reinterpret_cast<IdleAnimationData*>(reinterpret_cast<char*>(this) + 0x38)))->SwapEndian();

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct FUN_00680a70_obj
{
};

struct FUN_005054b0_shell
{
};


struct FUN_005fe470_shell : public TESIdleForm
{
    void CopyFromIdleForm(TESForm* apForm);
};

// Casts apForm to TESIdleForm, copies its base data and add-topic list, then restores the previous flag if FUN_004077c0 returns false.
// @fnv 0x005fe470
void FUN_005fe470_shell::CopyFromIdleForm(TESForm* apForm)
{
    TESIdleForm* other = dynamic_cast<TESIdleForm*>(apForm);
    if (!other)
        return;
    reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005054b0_shell*>(this)))->FUN_004851b0(other);
    reinterpret_cast<::FUN_00680a70_shell *>((reinterpret_cast<FUN_00680a70_obj*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())))->CopyConditions((::PerkEntryConditionSet *)(::FUN_00680a70_obj *)(reinterpret_cast<FUN_00680a70_obj*>(reinterpret_cast<TESTopicInfo*>(other)->GetAddTopicList())),
                         (::PerkEntryConditionSet *)(0));
    bool bFlag = reinterpret_cast<FUN_005ff200_shell*>(this)->IsFlag40Set();
    data = other->data;
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(this))->FUN_004077c0())
        reinterpret_cast<FUN_005ff220_shell*>(this)->SetFlag40(bFlag);
}

struct FormCopyMap
{
};
struct IdleArrayMethods
{
    void FUN_0061bdc0();
    TESForm*& FUN_00877a30(unsigned int);
    void FUN_00864280(unsigned int);
};
struct IdleCopy : TESIdleForm
{
    TESIdleForm* CopyIdleForm(unsigned char flag, FormCopyMap* map);
};
// Creates a copy of a TESIdleForm via FUN_004867a0, remaps two referenced forms through map, and copies the idle array entries into the copy's array.
// @fnv 0x005fe600
TESIdleForm* IdleCopy::CopyIdleForm(unsigned char flag, FormCopyMap* map)
{
    TESIdleForm* p;
    TESForm* h;
    TESIdleForm* i;
    TESIdleForm* s;
    TESForm* f;
    IdleArrayMethods* eb;
    unsigned int cf;
    unsigned int q;
    TESForm* b;
    TESForm* ba;
    TESForm* k;
    i = dynamic_cast<TESIdleForm*>(((::TESForm *)(reinterpret_cast<::FUN_004867a0_cls *>(this)->FUN_004867a0((void *)(flag), map))));
    h = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((map))->FUN_00853130((std::uintptr_t)(m_pParentIdleForm), (::fnv_00853130::CombatThreatRecord *&)(h)) || !h)
        h = m_pParentIdleForm;
    s = static_cast<TESIdleForm*>(h);
    reinterpret_cast<::LowProcess *>((static_cast<IdleCopy*>(i)))->SetCurrentCombatTarget((::TESObjectREFR *)(s));
    h = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((map))->FUN_00853130((std::uintptr_t)(m_pIdleForm), (::fnv_00853130::CombatThreatRecord *&)(h)) || !h)
        h = m_pIdleForm;
    p = static_cast<TESIdleForm*>(h);
    reinterpret_cast<::TESIdleForm *>((static_cast<IdleCopy*>(i)))->m_pIdleForm = (::TESIdleForm *)(p);
    if (m_pParentPath)
    {
        reinterpret_cast<IdleArrayMethods*>(m_pParentPath)->FUN_0061bdc0();
        cf = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<IdleArrayMethods*>(m_pParentPath)))->FUN_0084e3a0()));
        eb = ((::IdleArrayMethods *)(reinterpret_cast<::TESIdleForm *>((static_cast<IdleCopy*>(i)))->AssignParentPath()));
        eb->FUN_00864280(cf);
        f = 0;
        for (q = 0; q < cf; q++)
        {
            ba = reinterpret_cast<IdleArrayMethods*>(m_pParentPath)->FUN_00877a30(q);
            b = ba->CreateForm(reinterpret_cast<void*>(flag), map);
            k = b;
            reinterpret_cast<::NiFormArray *>((eb))->SetSize(q, (unsigned int *)&(k));
            f = b;
        }
    }
    return i;
}

struct IdleFormRemovableArray
{
    TESForm* RemoveAt(unsigned int index);
    void Compact();
    TESForm*& GetAt(unsigned int index);
};

struct IdleManagerStub
{
};

struct IdleChildHolder
{
};

struct IdleFormLinks
{
    IdleFormLinks* GetPrevIdle();
};

struct IdleFormDetach : public IdleFormLinks
{
    void DetachFromIdleList();
};
// @fnv 0x005fe400
void TESIdleForm::ClearData()
{
    if (reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004516b0() && !reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004226e0() && reinterpret_cast<::FUN_00843150_shell *>((DAT_011cb6a0))->FUN_00843150() &&
        GetInitialized())
        reinterpret_cast<::IdleFormDetach *>(this)->DetachFromIdleList();
    reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
        ->InitializeConditionItems();
}

// Removes this idle form from its loose-idle or sibling array, compacts the array, and relinks the neighbouring entry's previous pointer.
// @fnv 0x005ff610
void IdleFormDetach::DetachFromIdleList()
{
    if (reinterpret_cast<::FUN_005ff200_shell *>(this)->IsFlag40Set())
    {
        IdleFormRemovableArray* pArray = ((::IdleFormRemovableArray *)(reinterpret_cast<::IdleAnimationManager *>((((IdleManagerStub*)DAT_011cb6a0)))->GetIdleArray((::TESForm *)(::TESIdleForm *)((TESIdleForm*)this))));
        unsigned int uiIndex_2 = reinterpret_cast<::NiFormArray *>((pArray))->GetIndexOfForm((TESForm*)this);
        if (uiIndex_2 != -1)
        {
            pArray->RemoveAt(uiIndex_2);
            pArray->Compact();
        }
        reinterpret_cast<::FUN_005ff220_shell *>(this)->SetFlag40(false);
    }
    else
    {
        IdleFormRemovableArray* pSiblingsA = 0;
        if (((::IdleChildHolder *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())))
            pSiblingsA = ((::IdleFormRemovableArray *)(reinterpret_cast<::LowProcess *>((((::IdleChildHolder *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget()))))->GetTarget()));
        else
            pSiblingsA = ((::IdleFormRemovableArray *)(reinterpret_cast<::FUN_006005c0_shell *>((((IdleManagerStub*)DAT_011cb6a0)))->FUN_006005c0((const char *)(::TESIdleForm *)((TESIdleForm*)this))));
        if (pSiblingsA)
        {
            unsigned int uiPos4 = reinterpret_cast<::NiFormArray *>((pSiblingsA))->GetIndexOfForm((TESForm*)this);
            if (uiPos4 != -1)
            {
                pSiblingsA->RemoveAt(uiPos4);
                pSiblingsA->Compact();
                reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((::TESObjectREFR *)(0));
                IdleFormLinks* pNext2 = (IdleFormLinks*)pSiblingsA->GetAt(uiPos4);
                if (pNext2)
                {
                    if (reinterpret_cast<::TESForm *>((void *)(pNext2))->GetInitialized())
                    {
                        reinterpret_cast<::TESIdleForm *>((pNext2))->m_pIdleForm = (::TESIdleForm *)(GetPrevIdle());
                    }
                    else
                    {
                        IdleFormLinks* pPrev8 = GetPrevIdle();
                        reinterpret_cast<::TESIdleForm *>((pNext2))->m_pIdleForm = (::TESIdleForm *)((std::uintptr_t)(pPrev8 ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pPrev8))->FUN_0084e3a0())) : 0));
                    }
                    reinterpret_cast<::TESIdleForm *>(this)->m_pIdleForm = nullptr;
                }
            }
        }
    }
}

struct IdleBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~IdleBase();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct IdleModel
{
    virtual ~IdleModel();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct IdleChildren
{
    virtual ~IdleChildren();
};
struct IdleBaseArray
{
    IdleBase* Remove(unsigned int);
    void Compact();
};
struct IdleLink : IdleBase
{
    IdleLink* Previous();
};
struct IdleParent
{
};
struct IdleManager
{
};
struct IdleHandler
{
    bool Busy();
};

struct FUN_005fe180 : IdleBase, IdleModel
{
    PerkEntryConditionSet conditions;
    int data38;
    int data3c;
    IdleChildren* children;
    int parent44;
    int prev48;
    BSStringT<char> name;
    virtual ~FUN_005fe180();
    IdleLink* Previous();
};
// Calls FUN_005fe180, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x005fe130
void* FUN_005fe130_shell::FUN_005fe130(unsigned int flags)
{
    reinterpret_cast<::FUN_005fe180 *>(this)->FUN_005fe180::~FUN_005fe180();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Clears the idle, unlinks it from its parent or the root/other arrays, then detaches and deletes all children and the children container.
// @fnv 0x005fe180
FUN_005fe180::~FUN_005fe180()
{
    reinterpret_cast<::TESIdleForm *>(this)->ClearData();
    if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004226e0())
    {
        if (((::IdleParent *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())))
        {
            reinterpret_cast<::FUN_005ff5d0_class *>((((::IdleParent *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget()))))->FUN_005ff5d0((unsigned int)(this));
        }
        else
        {
            IdleBaseArray* array = ((::IdleBaseArray *)(reinterpret_cast<::FUN_006005c0_shell *>((((IdleManager*)DAT_011cb6a0)))->FUN_006005c0((const char *)(void *)(this))));
            if (array)
            {
                unsigned int index = reinterpret_cast<::NiFormArray *>((array))->GetIndexOfForm((::TESForm *)(void *)(this));
                if (index != -1)
                {
                    IdleLink* next = (IdleLink*)((::IdleBase *)(reinterpret_cast<::FUN_004d6170_shell *>((array))->FUN_004d6170(index + 1)));
                    if (next)
                        reinterpret_cast<::TESIdleForm *>((next))->m_pIdleForm = (::TESIdleForm *)(Previous());
                    array->Remove(index);
                    array->Compact();
                }
            }
            array = ((::IdleBaseArray *)(reinterpret_cast<::IdleAnimationManager *>((((IdleManager*)DAT_011cb6a0)))->GetIdleArray((::TESForm *)(void *)(this))));
            if (array)
            {
                unsigned int other = reinterpret_cast<::NiFormArray *>((array))->GetIndexOfForm((::TESForm *)(void *)(this));
                if (other != -1)
                {
                    array->Remove(other);
                    array->Compact();
                }
            }
        }
    }
    if (children)
    {
        unsigned int count = reinterpret_cast<::FUN_005ff4a0_shell *>(this)->FUN_005ff4a0();
        if (count)
        {
            for (unsigned int pos = 0; pos < count; pos++)
            {
                IdleLink* child = ((::IdleLink *)(reinterpret_cast<::FUN_005ff4d0_shell *>(this)->GetIdleFormByIndex(pos)));
                reinterpret_cast<::LowProcess *>((child))->SetCurrentCombatTarget((::TESObjectREFR *)(0));
                delete child;
            }
        }
        delete children;
    }
}

struct TESConditionInit
{
    void InitItem(TESForm*);
};
struct IdleInit : TESIdleForm
{
    void InitLoad();
};
// Initializes the idle form once: sets up the add-topic list, validates the anim group, resolves parent and previous idle forms, and marks it initialized.
// @fnv 0x005feb90
void IdleInit::InitLoad()
{
    if (GetInitialized())
        return;
    reinterpret_cast<::PerkEntryConditionSet *>((((::TESConditionInit *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()))))->InitItem(this);
    int id = reinterpret_cast<::FUN_005ff160_shell *>(this)->GetFlagsMasked();
    if (id >= 8)
    {
        switch (id)
        {
        case 20:
        case 21:
            break;
        default:
            ::FUN_005b5e40(
                );
            reinterpret_cast<::FUN_005ff190_shell *>(this)->FUN_005ff190(7);
            break;
        }
    }
    unsigned int uiFormId = (unsigned int)(std::uintptr_t)m_pParentIdleForm;
    if (uiFormId)
    {
        ResolveFormID(&uiFormId, GetFile(-1));
        TESIdleForm* parent = dynamic_cast<TESIdleForm*>(FUN_004839c0(uiFormId));
        if (!parent)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            ::FUN_005b5e40();
        }
        reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((::TESObjectREFR *)(parent));
    }
    uiFormId = (unsigned int)m_pIdleForm;
    if (uiFormId)
    {
        ResolveFormID(&uiFormId, GetFile(-1));
        TESIdleForm* previous = dynamic_cast<TESIdleForm*>(FUN_004839c0(uiFormId));
        if (!previous)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            ::FUN_005b5e40();
        }
        reinterpret_cast<::TESIdleForm *>(this)->m_pIdleForm = (::TESIdleForm *)(previous);
    }
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
}

class LowProcess_o2
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};

// FUN_005ff880 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x18 ; jmp FUN_005fe130
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base: a vtable
// pointer plus 5 int members (4 + 20 = 0x18 bytes).  Both bases declare the
// same virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct IdlePrimaryBase
{
    virtual void FUN_005ff880();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct IdleSecondaryBase
{
    virtual void FUN_005ff880();
};

struct IdleDerived : IdlePrimaryBase, IdleSecondaryBase
{
    IdleDerived();
// @fnv 0x005ff880
    virtual void FUN_005ff880();
};

IdleDerived::IdleDerived()
{}
