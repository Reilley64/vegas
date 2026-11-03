// Source layout: Setting. PC corrections are in generate_headers.py.
#ifndef FNV_SETTING_H
#define FNV_SETTING_H
#include "layout_support.h"
#include "SETTING_VALUE.h"
class Setting
{
  public:
    SETTING_VALUE uValue;  // +0x4
    const char* pKey;      // +0x8
    Setting(const char* key, float value);
    Setting(const char* key, int value);
    Setting(const char* key, char* value);
    Setting(const char* key, const char* value);
    Setting(const char* key, bool value);
    virtual ~Setting();
    virtual bool IsPrefSetting();
};
#endif
