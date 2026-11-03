#ifndef FNV_SETTING_AUTHORED_BODIES_H
#define FNV_SETTING_AUTHORED_BODIES_H


#include "fnv/decl/FUN_005e0860_cls.h"
#include "fnv/symbols_004de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f9000.h"
#include "setting_declarations.h"

// @fnv 0x0044f570
template <> void SettingT<INISettingCollection>::EnsureCollection()
{
    if (!(*reinterpret_cast<::INISettingCollection * *>(&::g_coll_011f96a0)))
        (*reinterpret_cast<::INISettingCollection * *>(&::g_coll_011f96a0)) = new INISettingCollection;
}

// @fnv 0x0044f560
template <> INISettingCollection* SettingT<INISettingCollection>::GetCollection()
{
    EnsureCollection();
    return (*reinterpret_cast<::INISettingCollection * *>(&::g_coll_011f96a0));
}

// @fnv 0x004de490
template <> INIPrefSettingCollection* SettingT<INIPrefSettingCollection>::GetCollection()
{
    ::FUN_004de4a0();
    return (*reinterpret_cast<::INIPrefSettingCollection * *>(&::DAT_011f35a0));
}

// @fnv 0x005e02b0
template <> Setting* SettingCollectionList<Setting>::GetPtr(const char* key)
{
    Setting* result = 0;
    reinterpret_cast<::FUN_005e0860_cls *>(this)->FindByKey((void *)(key), (::FNVObject **)&(result));
    return result;
}

#endif
