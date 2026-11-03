// gamebryo2.2/corelibs/nimain/niparallelupdatetaskmanager_decls.h: declares Interface, Main, NiParallelUpdateTaskManager
#ifndef NIPARALLELUPDATETASKMANAGER_DECLS_H
#define NIPARALLELUPDATETASKMANAGER_DECLS_H


#include "fnv/decl/fnv_007014a0__FM7.h"
#include "fnv/decl/fnv_00871dc0__FUN_00871dc0_class.h"
#include "fnv/decl/fnv_00877430__FUN_00877430_shell.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
class Interface
{
  public:
    enum enumMenus
    {
        MessageMenu = 0x3e9,
        DialogueMenu = 0x3f1,
        Menu_3f6 = 0x3f6,
        Menu_41e = 0x41e,
        VATSMenu = 0x420,
        Menu_424 = 0x424,
        Menu_432 = 0x432,
        Menu_438 = 0x438,
        Menu_439 = 0x439,
        Menu_43a = 0x43a,
        Menu_43b = 0x43b
    };

    static bool GetSelectedTargetIndex(enumMenus menu);
    static bool IsMenuActive(enumMenus menu, unsigned int flags);
};

class Main
{
  public:
};

class NiParallelUpdateTaskManager
{
  public:
    void DispatchParallelUpdates();
};

// The packet has no identities for these menu-state globals and helper.

#endif
