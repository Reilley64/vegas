// fallout_shared/teshealthform_decls.h: declares TESHealthForm
#ifndef TESHEALTHFORM_PRIVATE_DECLS_H
#define TESHEALTHFORM_PRIVATE_DECLS_H

#include "fnv/symbols_00487000.h"
#include "BaseFormComponent.h"
class TESForm;
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;
    void InitializeComponent();
    virtual unsigned int GetHealth();
    static unsigned int GetBaseHealth(TESForm* form);
};
#endif
