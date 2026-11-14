// fallout_shared/tesweightform_decls.h: declares TESForm, TESBoundObject, TESWeightForm
#ifndef FNV_TESWEIGHTFORM_DECLS_H
#define FNV_TESWEIGHTFORM_DECLS_H


#include "fnv/decl/FUN_0048ee50_Class.h"
#include "fnv/decl/TimeoutTimer.h"
enum ENUM_FORM_ID
{
    ENUM_FORM_ID_Unknown = 0
};

class TESForm
{
  public:
};

class TESBoundObject
{
  public:
    int GetFormType() const;
};
class ActiveEffect
{
  public:
};

class TESWeightForm
{
  public:
    static float GetWeightForForm(TESForm* form, bool useFormWeight);
};

#endif
