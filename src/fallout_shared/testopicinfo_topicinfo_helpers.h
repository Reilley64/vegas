// fallout_shared/testopicinfo_topicinfo_helpers.h: declares TopicInfoArray, FormChangeMask, BGSLoadFormBuffer, PlayerCharacter
#ifndef TOPICINFO_HELPERS_H
#define TOPICINFO_HELPERS_H

#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_009527b0_Class.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/symbols_011de000.h"
#include "testopicinfo_topicinfo_layout_support.h"
class TopicInfoArray : public NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >
{
};
class QuestDialogueInfo
{
  public:
};
class FormChangeMask
{
  protected:
    int iFlags;

  public:
    FormChangeMask();
    FormChangeMask(int flags);
};
struct BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags();
    FormChangeMask GetOldChangeFlags();
};
class PlayerCharacter
{
  public:
};
#endif
