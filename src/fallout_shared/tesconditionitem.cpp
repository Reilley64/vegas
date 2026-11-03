// fallout_shared/tesconditionitem.cpp: TESConditionItem, ConditionSerializer (11 functions)

#include <new>
#include <cstdio>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/C81110Header.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005ec060_shell.h"
#include "fnv/decl/FUN_00619d00_shell.h"
#include "fnv/decl/FUN_0061e2b0_shell.h"
#include "fnv/decl/FUN_00681500_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Foo.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00681000.h"
#include "fnv/symbols_00682000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01190000.h"
#define TESFile TESFileStub
#include "layout_support.h"
#undef TESFile
#include "tesconditionitem_packet.h"
#include "tesconditionitem_decls.h"

enum
{
    kConditionDataChunk = 0x41445443
};

// TESConditionItem has no generated header in this task folder; the layout
class TESConditionItem
{
  public:
    char m_flags;  // +0x00
    unsigned char m_pad01[3];
    union
    {
        float m_comparisonValue;  // +0x04
        TESGlobal* m_comparisonGlobal;
    };
    unsigned short m_usFunctionCode;  // +0x08
    unsigned char m_pad0A[2];
    unsigned int m_data0C;       // +0x0C
    unsigned int m_data10;       // +0x10
    int m_objectType;            // +0x14
    TESObjectREFR* m_objectRef;  // +0x18

    TESConditionItem();
    float GetConditionValue();
    void Load(TESFile* file);
    void SetFunction(int functionCode);
    void InitItem(TESForm*);
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*, bool&);
    unsigned int FUN_005eb680();
public:
    bool GetValueIsGlobal() const;
};

// 0x00526ac0 reads the float at +0x24 of the comparison global. The
// generated TESGlobal header declares no getter, so this TU calls it through
// a derived helper instead of editing shared headers.
struct TESGlobalValueReader : public TESGlobal
{
};

#include <cstring>

// Zero-initialises the condition item and sets its function code to 0x1048.
// @fnv 0x006811e0
TESConditionItem::TESConditionItem()
{
    memset(this, 0, sizeof(TESConditionItem));
    m_objectRef = 0;
    SetFunction(0x1048);
}

// @fnv 0x00681490
float TESConditionItem::GetConditionValue()
{
    float value = 0.0f;
    if (reinterpret_cast<::TESConditionItem *>(this)->GetValueIsGlobal())
    {
        if (m_comparisonGlobal)
            value = reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)m_comparisonGlobal)))->FUN_00526ac0();
    }
    else
    {
        value = m_comparisonValue;
    }
    return value;
}

// Local spellings are retained for MSVC9 stack-home ordering.
// pData is the boolean result, pParam the evaluated number, pTarget the
// selected subject, pSubject the other reference, bResult the first parameter,
// and dValue the function data.
// Evaluates the condition item's script function against the subject/target references and compares the result to the comparison value.
// @fnv 0x00681600
bool TESConditionItem::ContainsTrait(TESObjectREFR* pSubjectRef, TESObjectREFR* target, bool& special)
{
    bool pData = false;
    double pParam = 0.0;
    TESObjectREFR* pTarget = pSubjectRef;
    TESObjectREFR* pSubject = target;
    special = false;
    switch (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((TimeGlobal*)this)))->FUN_00825c00())
    {
    case 0:
        break;
    case 1:
        pTarget = pSubject;
        pSubject = pSubjectRef;
        break;
    case 2:
        pTarget = m_objectRef;
        break;
    case 3:
        pTarget = 0;
        pSubject = pSubjectRef;
        if (pSubjectRef && pSubjectRef->IsActor())
        {
            Actor* pActor = (Actor*)pSubjectRef;
            pTarget = pActor->vfn_42c();
        }
        break;
    case 4:
        pTarget = 0;
        pSubject = 0;
        if (pSubjectRef)
            pTarget = reinterpret_cast<::FUN_00569b80_shell *>((pSubjectRef))->FUN_00569b80();
        break;
    }
    FUNCTION_DATA* dValue = (FUNCTION_DATA*)((TESTopicInfoData*)this)->GetLinkToList();
    TESObjectREFR* bResult = dValue->param;
    if (!bResult && ::FUN_00682320((const ::FunctionData *)(dValue), 0))
        bResult = pSubject;
    if (g_scriptCommands[dValue->function].eval && (!g_scriptCommands[dValue->function].needsRef || pTarget))
    {
        if (g_scriptCommands[dValue->function].eval(pTarget, bResult, dValue->param2, pParam))
        {
            float fComparison;
            if (m_comparisonGlobal && reinterpret_cast<::TESConditionItem *>(this)->GetValueIsGlobal())
                fComparison = reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)m_comparisonGlobal)))->FUN_00526ac0();
            else
                fComparison = m_comparisonValue;
            pData = ::CompareFloatsByCondition(reinterpret_cast<::FUN_005ec060_shell *>(this)->FUN_005ec060(), (float)pParam, fComparison);
            if (!pData)
            {
                unsigned int uiFunction = FUN_005eb680() + 0x1000;
                switch (uiFunction)
                {
                case 0x104c:
                    if (reinterpret_cast<::FUN_005ec060_shell *>(this)->FUN_005ec060() == 2 || reinterpret_cast<::FUN_005ec060_shell *>(this)->FUN_005ec060() == 3)
                        special = true;
                    break;
                case 0x1193:
                    special = true;
                    break;
                }
            }
        }
    }
    return pData;
}

// In the diagnostic scopes, info holds display text, topic holds the topic
// info form, quest holds its topic, and text holds its quest. These spellings
// preserve the original compiler allocation order.
// @fnv 0x006819e0
void TESConditionItem::InitItem(TESForm* owner)
{
    ::ScriptFunctionData::InitItem(owner, (::FunctionData *)(::FUNCTION_DATA *)((FUNCTION_DATA*)((TESTopicInfoData*)this)->GetLinkToList()));
    unsigned int referenceID = (unsigned int)(std::uintptr_t)m_objectRef;
    if (referenceID)
    {
        ::ResolveFormID((unsigned int *)&(referenceID), owner->GetFile(-1));
        m_objectRef = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(referenceID));
        if (!m_objectRef)
        {
            if (owner)
                ::FUN_005b5e40();
            else
                ::FUN_005b5e40();
        }
    }
    if (!g_scriptCommands[FUN_005eb680()].eval)
    {
        char buffer[0x410];
        if (owner->GetFormType() == 0x46)
        {
            TESTopicInfo* topic = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* quest = ::fnv_0061a310::FindTopicByInfo(topic);
            TESQuest* text = 0;
            if (quest)
                text = reinterpret_cast<::FUN_00619d00_shell *>((quest))->FindQuestForTopicInfo(topic);
            BSStringT<char> info;
            reinterpret_cast<::FUN_0061e2b0_shell *>((topic))->BuildResponseText(info, false);
            sprintf(buffer, DAT_0104cae0, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((topic))->FUN_0084e3a0())), ((NiPointer<NiNode>*)&info)->operator->(),
                    text ? text->vfn_138() : ::DAT_01011584, text ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((text))->FUN_0084e3a0())) : 0,
                    quest ? quest->GetEditorID() : ::DAT_01011584, quest ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((quest))->FUN_0084e3a0())) : 0);
        }
        else
        {
            sprintf(buffer, DAT_01069440, ((const char *)(reinterpret_cast<::FUN_00440e30_This *>((owner))->FUN_00440e30())), owner->GetEditorID(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((owner))->FUN_0084e3a0())));
        }
        ::FUN_005b5e40();
    }
    if (reinterpret_cast<::TESConditionItem *>(this)->GetValueIsGlobal() && m_comparisonGlobal)
    {
        unsigned int globalID = (unsigned int)(std::uintptr_t)m_comparisonGlobal;
        ::ResolveFormID((unsigned int *)&(globalID), owner->GetFile(-1));
        m_comparisonGlobal = dynamic_cast<TESGlobal*>(::FUN_004839c0(globalID));
        if (!m_comparisonGlobal)
        {
            char buffer[0x410];
            if (owner->GetFormType() == 0x46)
            {
                TESTopicInfo* topic = dynamic_cast<TESTopicInfo*>(owner);
                TESTopic* quest = ::fnv_0061a310::FindTopicByInfo(topic);
                TESQuest* text = 0;
                if (quest)
                    text = reinterpret_cast<::FUN_00619d00_shell *>((quest))->FindQuestForTopicInfo(topic);
                BSStringT<char> info;
                reinterpret_cast<::FUN_0061e2b0_shell *>((topic))->BuildResponseText(info, false);
                std::snprintf(buffer, 0x410, DAT_0104cae0, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((topic))->FUN_0084e3a0())), ((NiPointer<NiNode>*)&info)->operator->(),
                             text ? text->vfn_138() : ::DAT_01011584, text ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((text))->FUN_0084e3a0())) : 0,
                             quest ? quest->GetEditorID() : ::DAT_01011584, quest ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((quest))->FUN_0084e3a0())) : 0);
            }
            else
            {
                std::snprintf(buffer, 0x410, DAT_01069440, ((const char *)(reinterpret_cast<::FUN_00440e30_This *>((owner))->FUN_00440e30())), owner->GetEditorID(),
                             ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((owner))->FUN_0084e3a0())));
            }
            ::FUN_005b5e40();
        }
    }
}

struct FUN_00600ab0_shell : public TESConditionItem
{
    void FUN_00600ab0(int);
};

// @fnv 0x00600ab0
void FUN_00600ab0_shell::FUN_00600ab0(int aeCheck)
{
    m_objectType = aeCheck;
}

struct FUN_00681460_helper : public TESConditionItem
{
    void ClearAndSetFunctionCode(int functionCode);
};

// @fnv 0x00681460
void FUN_00681460_helper::ClearAndSetFunctionCode(int functionCode)
{
    memset(&m_usFunctionCode, 0, 0x0C);
    m_usFunctionCode = functionCode;
}

template <int N> struct EndianSizeTag
{
};
struct FUN_00681110_shell
{
};
struct FUN_00681170_shell : ::TESConditionItem
{
    void SwapEndianAndProcess();
};
// Loads a TESConditionItem from a TESFile chunk, applies endian fixup, and derives the object type from m_flags bits 2 and 8.
// @fnv 0x00681950
void TESConditionItem::Load(TESFile* file)
{
    if (file && ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == kConditionDataChunk)
    {
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(this), sizeof(TESConditionItem));
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_00681170_shell *>(this)->SwapEndianAndProcess();
    }
    if (m_flags & 2)
    {
        reinterpret_cast<::FUN_00600ab0_shell *>(this)->FUN_00600ab0(1);
        m_flags &= ~2;
    }
    if (m_flags & 8)
    {
        reinterpret_cast<::FUN_00600ab0_shell *>(this)->FUN_00600ab0(2);
        m_flags &= ~8;
    }
}
// @fnv 0x00681170
void FUN_00681170_shell::SwapEndianAndProcess()
{
    ::FUN_00401080(reinterpret_cast<int*>(&this->m_comparisonValue));
    ::FUN_00401080(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18));
    ::FUN_00401080(&this->m_objectType);
    reinterpret_cast<::C81110Header *>((reinterpret_cast<FUN_00681110_shell*>(&this->m_usFunctionCode)))->ClearFields();
}

struct S_006815c0
{
};
struct S_006815d0
{
    bool IsDifferentFrom(TESConditionItem* apCompare);
};
// Compares 0x1C bytes of apCompare's referenced data against this object and returns true if they differ.
// @fnv 0x006815d0
bool S_006815d0::IsDifferentFrom(TESConditionItem* apCompare)
{
    if (std::memcmp(((void *)((void *)(((S_006815c0*)apCompare)))), this, 0x1C))
        return true;
    return false;
}

struct SavedCondition
{
    unsigned int flags;
    unsigned int comparison;
    unsigned int function;
    unsigned int params[2];
    int objectType;
    unsigned int reference;
};
struct ConditionForm
{
};
struct ConditionSerializer
{
    unsigned int flags;
    ConditionForm* comparison;
    unsigned int function;
    unsigned int params[2];
    int objectType;
    ConditionForm* reference;
    void SerializeCondition();
};
// @fnv 0x00681840
void ConditionSerializer::SerializeCondition()
{
    SavedCondition savedCondition;
    ::__memcpy(&savedCondition, this, 0x1c);
    std::intptr_t functionCode = ((std::intptr_t)(reinterpret_cast<::TESTopicInfoData *>(this)->GetLinkToList()));
    int count = ((int)(::ScriptFunctionData::GetParamCount((const ::FunctionData *)(functionCode))));
    for (int index = 0; index < count; index++)
    {
        if (::ScriptFunctionData::IsParamTESForm((const ::FunctionData *)(functionCode), index))
        {
            ConditionForm* form = reinterpret_cast<ConditionForm*>(savedCondition.params[index]);
            if (form)
                savedCondition.params[index] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0()));
        }
    }
    if (reinterpret_cast<::TESConditionItem *>(this)->GetValueIsGlobal() && comparison)
        savedCondition.comparison = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((comparison))->FUN_0084e3a0()));
    if (reference)
        savedCondition.reference = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reference))->FUN_0084e3a0()));
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00681170_shell *>(&(savedCondition))->SwapEndianAndProcess();
    AppendChunk(0x41445443, &savedCondition, 0x1c);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00681170_shell *>(&(savedCondition))->SwapEndianAndProcess();
}

namespace fnv_00681220 {
struct FUN_00681460_helper
{
};

struct FUN_00681500_class
{
};

struct FUN_00681530_class
{
};

struct FUN_00681220_class
{
    unsigned int m_flags;
    unsigned int m_comparisonValue;
    unsigned int m_usFunctionCode;
    unsigned int m_data0C;
    void FUN_00681220(int functionCode);
};

// Normalizes functionCode into the 0x280 range, applies it via ClearAndSetFunctionCode, then sets count and value based on the function code.
// @fnv 0x00681220
void FUN_00681220_class::FUN_00681220(int functionCode)
{
    int iNormalizedFunction = functionCode;
    if (functionCode >= 0x1000 && functionCode < 0x1280)
    {
        iNormalizedFunction -= 0x1000;
    }
    else if (functionCode >= 0 && functionCode < 0x280)
    {
        functionCode += 0x1000;
    }
    if (iNormalizedFunction >= 0 && iNormalizedFunction < 0x280)
    {
        reinterpret_cast<::FUN_00681460_helper *>((((FUN_00681460_helper*)this)))->ClearAndSetFunctionCode(iNormalizedFunction);

        switch (functionCode)
        {
        case 0x103E:
        case 0x1040:
        case 0x1043:
        case 0x1044:
        case 0x1045:
        case 0x1046:
        case 0x1047:
        case 0x1048:
        case 0x105B:
        case 0x1065:
        case 0x1066:
        case 0x1067:
        case 0x106A:
        case 0x106F:
        case 0x1070:
        case 0x1136:
            reinterpret_cast<::Foo *>((((FUN_00681530_class*)this)))->FUN_00681530(0);
            reinterpret_cast<::FUN_00681500_class *>((((FUN_00681500_class*)this)))->SetValueIfNoParams(1.0f);
            break;
        case 0x1001:
            reinterpret_cast<::Foo *>((((FUN_00681530_class*)this)))->FUN_00681530(4);
            reinterpret_cast<::FUN_00681500_class *>((((FUN_00681500_class*)this)))->SetValueIfNoParams(100.0f);
            break;
        case 0x106B:
            reinterpret_cast<::Foo *>((((FUN_00681530_class*)this)))->FUN_00681530(1);
            reinterpret_cast<::FUN_00681500_class *>((((FUN_00681500_class*)this)))->SetValueIfNoParams(0.0f);
            break;
        case 0x10F7:
            m_data0C = 0x28;
            reinterpret_cast<::Foo *>((((FUN_00681530_class*)this)))->FUN_00681530(0);
            reinterpret_cast<::FUN_00681500_class *>((((FUN_00681500_class*)this)))->SetValueIfNoParams(1.0f);
            break;
        }
    }
}
}  // namespace fnv_00681220

#include "generated/data/fallout_shared/tesconditionitem.inc"
