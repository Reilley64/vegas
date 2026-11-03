#ifndef BSSHADERLIGHTINGPROPERTY_GLOBALS_H
#define BSSHADERLIGHTINGPROPERTY_GLOBALS_H

#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/symbols_011c5000.h"
class RecursiveSpinLock
{
  public:
    unsigned int m_lock;
};
inline bool bsshaderlightingproperty_IsActive(ShadowSceneLight* light)
{
    return light && *(unsigned short*)((char*)light + 0x110) != 0xff &&
           !(*(unsigned int*)(*(char**)((char*)light + 0xf8) + 0x30) & 1);
}
#endif
