// fallout/interface/interfacemanager_decls.h: declares SettingT_GameSettingCollection_, SystemColorManager, SoftSystemColor, InterfaceManager
#ifndef FNV_INTERFACEMANAGER_DECLS_H
#define FNV_INTERFACEMANAGER_DECLS_H

#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00717000.h"
union SETTING_VALUE
{
    unsigned int color;
    int integer;
    float real;
    char* string;
};
class SettingT_GameSettingCollection_
{
  public:
};
class SystemColorManager
{
  public:
    class SoftSystemColor
    {
      public:
        unsigned char padding[12];
        SettingT_GameSettingCollection_* setting;
        unsigned int GetColor();
    };
};
class FORenderedMenu;
class InterfaceManager
{
  public:
    unsigned char padding[0x16c];
    FORenderedMenu* renderedMenu;
    unsigned int padding170;
    FORenderedMenu* pipboyRenderedMenu;
    FORenderedMenu* GetActiveRenderedMenu();
};
#endif
