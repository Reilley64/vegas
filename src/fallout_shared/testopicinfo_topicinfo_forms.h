// Unit-private API-only declarations. No objects allocated or field-layout claims.
#ifndef TOPICINFO_FORMS_H
#define TOPICINFO_FORMS_H
#include "testopicinfo_topicinfo_TESForm.h"
class PerkEntryConditionSet;
class TESQuest : public TESForm
{
  public:
    virtual const char* GetEditorName() const;
public:
    ::PerkEntryConditionSet *GetConditions();
};
class TESActorBase : public TESForm
{
};
class ActorValueInfo : public TESForm
{
};
class BGSPerk : public TESForm
{
};
#endif
