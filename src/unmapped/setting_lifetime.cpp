// Setting's five constructors and its destructor, in a unit of their own
// (VEGAS-129). They were defined in src/unmapped/setting.cpp. The unit that
// defines them also emits Setting's table and its deleting destructor, so
// all six move together and only this unit emits those. A link that
// reaches one of them now loads this member instead of setting.cpp.
#include "fnv/setting_class.h"
#include "fnv/symbols_00401000.h"

// Setting constructors for 4-byte values and floats share their code with other classes' two-field constructors
// (0x00404920, 0x0040e130), so only the bool form has an address of its own.
Setting::Setting(const char* key, int value)
{
    uValue.i = value;
    pKey = key;
}

Setting::Setting(const char* key, char* value)
{
    uValue.str = value;
    pKey = key;
}

Setting::Setting(const char* key, const char* value)
{
    uValue.str = value;
    pKey = key;
}

Setting::Setting(const char* key, float value)
{
    uValue.f = value;
    pKey = key;
}

// @fnv 0x0045cfb0
Setting::Setting(const char* key, bool value)
{
    uValue.b = value;
    pKey = key;
}

// @fnv 0x00404950
Setting::~Setting()
{
    if (pKey && *pKey == 'S')
        ::FUN_00401030(const_cast<char*>(pKey));
}
