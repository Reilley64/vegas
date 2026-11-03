// Source layout: TESReactionForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESREACTIONFORM_H
#define FNV_TESREACTIONFORM_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class BGSLoadFormBuffer;
class TESForm;
class TESReactionForm : public BaseFormComponent
{
  public:
    BSSimpleList<ReactionInfo*> m_kReactionList;  // +0x4
    unsigned char m_ucReactionFlags;                // +0xC
    unsigned char layoutPaddingD;
    unsigned short layoutPaddingE;
    void InitializeComponent();
public:
    void InitItem(::TESForm *);
public:
    void InitLoadGame(::BGSLoadFormBuffer *);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESReactionForm) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESReactionForm, m_kReactionList) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESReactionForm, m_ucReactionFlags) == 0xC);
#endif
