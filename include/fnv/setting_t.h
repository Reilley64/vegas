#ifndef FNV_SETTING_T_H
#define FNV_SETTING_T_H

#include "Setting.h"

// SettingT: the setting that adds itself to its collection.
//
// This is the one shared declaration of the template. It needs only Setting,
// so a unit can use it without the collection classes of SettingT.h, which
// declare NiTPrimitiveArray with one template parameter.
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

  protected:
    static Collection* ms_pCollection;
    static void EnsureCollection();
};

#endif
