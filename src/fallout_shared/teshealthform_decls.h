// fallout_shared/teshealthform_decls.h: declares TESHealthForm
#ifndef TESHEALTHFORM_PRIVATE_DECLS_H
#define TESHEALTHFORM_PRIVATE_DECLS_H

#include <cstdint>
#include "fnv/symbols_00487000.h"
#include "BaseFormComponent.h"
class TESForm;
class TESHealthForm : public BaseFormComponent
{
  public:
    std::uintptr_t m_uiHealthValue;
    void InitializeComponent();
    virtual unsigned int GetHealth();
    static unsigned int GetBaseHealth(TESForm* form);
};
#endif
