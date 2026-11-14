#pragma once

class CBFC10Registry;
class CBFC60Dispatcher;
class WorldCBFD;

// 0x00cbfc10
void RegisterAll(::CBFC10Registry *);
// 0x00cbfc60
void FUN_00cbfc60(::CBFC60Dispatcher *);
// 0x00cbfcb0
void FUN_00cbfcb0(void *);
// 0x00cbfd20
void InitializeWorld(::WorldCBFD *);
// 0x00cbfef0
int FUN_00cbfef0(float);
// 0x00cbff80
float Atan2(float, float);
