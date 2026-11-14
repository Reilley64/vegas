// Private call declarations from supplied identities and audited public declarations.
#ifndef FNV_UNIT_TESFORM_CALLS_H
#define FNV_UNIT_TESFORM_CALLS_H

#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "tesform_TESForm.h"
#include "tesform_TESFile.h"
class FormChangeMask
{
  public:
    int iFlags;
    FormChangeMask(int flags);
    operator bool() const;
};
struct BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int flags);
};
struct BGSSaveLoadGame
{
  public:
    void NotifyFormIDChanged(TESForm* form, FormChangeMask flags, bool force);
    void ClearFormChangeFlags(TESForm* form, FormChangeMask flags);
    void HasFormChanges(TESForm* form);
};
class TESForm;
class TESSaveLoadGame
{
  public:
    void HasFormChanges(TESForm* form, bool force);
public:
    void FinalizeForm(::TESForm *);
};
class TESValueForm : public BaseFormComponent
{
  public:
    virtual unsigned int GetSaveSizeTES(unsigned int flags) const;
    virtual void SaveGameTES(unsigned int flags);
    virtual void LoadGameTES(unsigned int flags, unsigned int currentFlags);
    unsigned int uiValue;
    void SetFormValue(unsigned int value);
};
#endif
