#ifndef FNV_SETTING_CLASS_H
#define FNV_SETTING_CLASS_H

#include "fnv/setting_value_union.h"

// The setting. Setting.h includes this header after layout_support.h; a
// unit that cannot include layout_support.h includes this one (VEGAS-111).
// The offset comments are those of the 32-bit layout; on windows-x64 uValue
// is at 8 and pKey at 16.
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
    // 0x005e0190; tesscriptfunctions.cpp defines it.
    Setting& FUN_005e0190(const char* name);
};

#endif
