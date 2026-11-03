// Source layout: TESHealthForm. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_CREATURE_TESHEALTHFORM_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_CREATURE_TESHEALTHFORM_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_BaseFormComponent.h"
class TESForm;
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;  // +0x4
    void InitializeComponent();
public:
    static unsigned int GetBaseHealth(::TESForm *);
};
#endif
