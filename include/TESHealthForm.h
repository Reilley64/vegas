// Source layout: TESHealthForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESHEALTHFORM_H
#define FNV_TESHEALTHFORM_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;  // +0x4
    void InitializeComponent();
};
#endif
