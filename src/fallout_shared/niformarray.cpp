// fallout_shared/niformarray.cpp: NiFormArray (3 functions)

#include <cstring>
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "niformarray_decls.h"

// @fnv 0x0061bc10
void NiFormArray::SetFormAtIndex(unsigned int index, TESForm* form)
{
    Compact();
    if (index > m_uiSize)
        SetAt(index, form);
    else
    {
        unsigned int newSize = m_uiSize + 1;
        if (m_uiMaxSize < newSize)
            SetSize(newSize + m_uiGrowBy);
        std::memmove(m_pBase + index + 1, m_pBase + index, (m_uiSize - index) * sizeof(TESForm*));
        ++m_uiSize;
        m_uiESize = m_uiSize;
        m_pBase[index] = form;
    }
}

// @fnv 0x004d6100
unsigned int NiFormArray::GetIndexOfForm(TESForm* form)
{
    unsigned int foundIndex = 0xffffffff;
    if (form)
    {
        unsigned int size = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
        if (size)
        {
            for (unsigned int index = 0; index < size; ++index)
            {
                if (FUN_00877a30(index) == form)
                {
                    foundIndex = index;
                    break;
                }
            }
        }
    }
    return foundIndex;
}

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
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_004d6170_shell : public NiFormArray
{
    TESForm* FUN_004d6170(unsigned int);
};

// Returns the form at aiIndex if it is within GetSize(), otherwise returns null.
// @fnv 0x004d6170
TESForm* FUN_004d6170_shell::FUN_004d6170(unsigned int aiIndex)
{
    TESForm* pretform = 0;
    if (aiIndex < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())))
    {
        pretform = FUN_00877a30(aiIndex);
    }
    return pretform;
}
