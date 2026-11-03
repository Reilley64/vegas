// Source layout: TESScriptableForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESSCRIPTABLEFORM_H
#define FNV_TESSCRIPTABLEFORM_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class TESForm;
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
public:
    void InitItem(::TESForm *);
};
#endif
