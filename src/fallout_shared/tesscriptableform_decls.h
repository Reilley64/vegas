// fallout_shared/tesscriptableform_decls.h: declares Script, TESScriptableForm, BGSCameraPath
#ifndef TESSCRIPTABLEFORM_DECLS_H
#define TESSCRIPTABLEFORM_DECLS_H

#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "TESForm.h"
class Script : public TESForm
{
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char padding[3];
    void InitItem(TESForm* owner);
};
class BGSCameraShot;
template <class> class BSSimpleList;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
public:
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
#endif
