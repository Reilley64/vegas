#pragma once

class NiTStringMapB58;
struct Input;
struct Map_00b585c0;
struct Resource;

// 0x00b58070
bool SetRootAppCulled(bool);
// 0x00b585c0
::Map_00b585c0 *FUN_00b585c0();
// 0x00b58670
::NiTStringMapB58 *GetNiTStringMap();
// 0x00b58720
bool IsNamedObjectPresent(const char *);
// 0x00b587c0
::Resource *FUN_00b587c0(::Input *);
