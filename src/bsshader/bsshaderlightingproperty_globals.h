#ifndef BSSHADERLIGHTINGPROPERTY_GLOBALS_H
#define BSSHADERLIGHTINGPROPERTY_GLOBALS_H

#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/symbols_011c5000.h"
class RecursiveSpinLock
{
  public:
    unsigned int m_lock;
};
struct Helper_00b707d0_Obj
{
    char pad[0x30];
    unsigned char flags;
};

struct Helper_00b707d0_Light
{
    char pad0[0xec];
    bool byteEC;
    char pad1[0xf8 - 0xed];
    Helper_00b707d0_Obj* objF8;
    char pad2[0x110 - 0xfc];
    unsigned short word110;
};

inline bool bsshaderlightingproperty_IsActive(ShadowSceneLight* light)
{
    Helper_00b707d0_Light* view = (Helper_00b707d0_Light*)light;
    return light && view->word110 != 0xff && !(view->objF8->flags & 1);
}
#endif
