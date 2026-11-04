// bshavok/bhkcharactercontroller_decls.h: declares bhkCharacterController, MobileObject
#ifndef BHKCHARACTERCONTROLLER_PACKET_DECLS_H
#define BHKCHARACTERCONTROLLER_PACKET_DECLS_H

#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
class GlobalObject_008c71b0
{
  public:
    int value;
    GlobalObject_008c71b0(int initial);
};
class bhkCharacterController
{
  public:
    float components[4];
    float& GetVectorElement(int index);
    GlobalObject_008c71b0 FUN_0070c440();
};
class MobileObject
{
  public:
    GlobalObject_008c71b0 GetVectorElement();
};
#endif
