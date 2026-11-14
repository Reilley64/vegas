#ifndef FNV_SETTING_T_H
#define FNV_SETTING_T_H

#include "fnv/setting_class.h"

// SettingT: the setting that adds itself to its collection.
//
// This is the one shared declaration of the template. It needs only Setting,
// so a unit can use it without the collection classes of SettingT.h, which
// declare NiTPrimitiveArray with one template parameter. It includes
// fnv/setting_class.h, not Setting.h, so a unit that cannot include
// layout_support.h can use it too (VEGAS-117).
template <class Collection> class SettingT : public Setting
{
  public:
    SettingT(const char* key, float value);
    SettingT(const char* key, int value);
    SettingT(const char* key, char* value);
    SettingT(const char* key, const char* value);
    SettingT(const char* key, bool value);
    virtual ~SettingT();
    static Collection* GetCollection();
    SETTING_VALUE* Bool(); // 0x00408d60, owned by src/fallout/ai/processlists.cpp

  protected:
    static Collection* ms_pCollection;
    static void EnsureCollection();
};

#endif
