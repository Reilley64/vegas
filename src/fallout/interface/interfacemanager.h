#ifndef FNV_INTERFACEMANAGER_H
#define FNV_INTERFACEMANAGER_H

#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00717000.h"
#include "interfacemanager_decls.h"
// @fnv 0x00719320
unsigned int SystemColorManager::SoftSystemColor::GetColor()
{
    return ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(setting))))->color;
}
// @fnv 0x00707af0
FORenderedMenu* InterfaceManager::GetActiveRenderedMenu()
{
    return ::FUN_007178a0() ? pipboyRenderedMenu : renderedMenu;
}
#endif
