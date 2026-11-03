// fallout_shared/packageeventaction_decls.h: declares TESObjectANIO, TESTopic, BGSCameraPath, PackageEventActionData
#ifndef PACKAGEEVENTACTION_DECLS_H
#define PACKAGEEVENTACTION_DECLS_H

#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_005b5000.h"
class TESQuest;
class ScriptVariableInfo;
class ScriptReferencedObject;
class ScriptLocals;
class PerkEntryConditionSet;
#include "layout_support.h"
#include "TESForm.h"
#include "Script.h"
#include "ScriptVariableInfo.h"
#include "ScriptReferencedObject.h"
class TESObjectANIO : public TESForm
{
};
class TESTopic : public TESForm
{
};
class BGSCameraShot;
template <class> class BSSimpleList;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
    PerkEntryConditionSet* GetConditions();
public:
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
extern ScriptVariableInfo* DAT_011d66ac;
class PackageEventActionData : public BSSimpleList<TESForm*>
{
  public:
    TESForm* pTopic;
    int eType;
    PackageEventActionData();
    void InitItem(TESForm* owner);
    void Load(TESFile* file);
};
#endif
