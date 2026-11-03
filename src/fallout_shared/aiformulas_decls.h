// fallout_shared/aiformulas_decls.h: declares AIFormulas
#ifndef FNV_AIFORMULAS_DECLS_H
#define FNV_AIFORMULAS_DECLS_H

#include "fnv/symbols_00406000.h"
#include "fnv/symbols_004e4000.h"
union SETTING_VALUE
{
    float f;
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting326;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting314;
class AIFormulas
{
  public:
    static float __cdecl CalculateSkillValue(float, float, float);
};
#endif
