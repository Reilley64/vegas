#ifndef XGAMESETTING_H
#define XGAMESETTING_H

#include "fnv/symbols_00404000.h"
#include "fnv/symbols_011c8000.h"
class GameSettingCollection;

GameSettingCollection* GetGameSettingCollection();

// @fnv 0x00404a70
GameSettingCollection* GetGameSettingCollection()
{
    ::EnsureSpawnedObj();
    return (*reinterpret_cast<::GameSettingCollection * *>(&::DAT_011c8048));
}

#endif
