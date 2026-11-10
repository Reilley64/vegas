
// src/fallout_shared/bgscliproundsform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgscliproundsform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004f15a0_shell.h"
class TESForm;
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
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
struct FUN_00475100_shell : public BGSClipRoundsForm
{
    void SetClipRounds();
};

// @fnv 0x00475100
void FUN_00475100_shell::SetClipRounds()
{
    m_ucClipRounds = 0xc;
}

struct SFTX
{
};
struct FUN_00475120_shell : public BGSClipRoundsForm
{
    void CopyFormTypeFromComponent(BaseFormComponent*);
    int GetFormType();
};
// Casts component to BGSClipRoundsForm and, if successful, sets this object's form type to the component's form type.
// @fnv 0x00475120
void FUN_00475120_shell::CopyFormTypeFromComponent(BaseFormComponent* component)
{
    BGSClipRoundsForm* clipRounds = dynamic_cast<BGSClipRoundsForm*>(component);
    if (!clipRounds)
        return;
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)this)))->FUN_004f15a0(((FUN_00475120_shell*)clipRounds)->GetFormType());
}

class TESForm
{
  public:
    int FNV_GetFormType();
};
struct FUN_00475170_shell : public BGSClipRoundsForm
{
    bool FUN_00475170(BaseFormComponent*);
};
// Casts other to BGSClipRoundsForm and returns true if the cast fails or the form types differ, otherwise false.
// @fnv 0x00475170
bool FUN_00475170_shell::FUN_00475170(BaseFormComponent* other)
{
    BGSClipRoundsForm* pClipRoundsForm = dynamic_cast<BGSClipRoundsForm*>(other);
    if (!pClipRoundsForm)
        return true;
    if (reinterpret_cast<TESForm*>(this)->FNV_GetFormType() !=
        reinterpret_cast<TESForm*>(pClipRoundsForm)->FNV_GetFormType())
        return true;
    return false;
}
