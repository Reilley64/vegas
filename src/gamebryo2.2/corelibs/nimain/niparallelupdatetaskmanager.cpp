// gamebryo2.2/corelibs/nimain/niparallelupdatetaskmanager.cpp: Interface, NiParallelUpdateTaskManager (1 function)

#include "fnv/decl/fnv_007014a0__FM7.h"
#include "fnv/decl/fnv_00871dc0__FUN_00871dc0_class.h"
#include "fnv/decl/fnv_00877430__FUN_00877430_shell.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "niparallelupdatetaskmanager_decls.h"

// @fnv 0x0086f450
void NiParallelUpdateTaskManager::DispatchParallelUpdates()
{
    if (DAT_011dea2b && !Interface::GetSelectedTargetIndex(Interface::DialogueMenu) && !FUN_0070edf0() &&
        !Interface::IsMenuActive(Interface::VATSMenu, 11) && !Interface::IsMenuActive(Interface::MessageMenu, 11) &&
        !::fnv_00705a00::FUN_00705a00() && !::fnv_00703d50::FUN_00703d50() && !DAT_011dea29 && DAT_011dea28)
    {
        reinterpret_cast<::fnv_00871dc0::FUN_00871dc0_class *>((reinterpret_cast<Main*>(this)))->FUN_00871dc0();
    }
    else if (DAT_011dea29 &&
             (!DAT_011dea2b || FUN_0070edf0() || (::fnv_00703d50::FUN_00703d50() && !::FUN_007079b0()) ||
              Interface::GetSelectedTargetIndex(Interface::DialogueMenu) ||
              Interface::GetSelectedTargetIndex(Interface::VATSMenu)) &&
             !reinterpret_cast<::fnv_007014a0::FM7 *>((DAT_011d8804))->FUN_007014a0(true) && !Interface::IsMenuActive(Interface::Menu_41e, 0) &&
             !Interface::IsMenuActive(Interface::Menu_3f6, 0) && !Interface::IsMenuActive(Interface::Menu_424, 0) &&
             !Interface::IsMenuActive(Interface::Menu_432, 0) && !Interface::IsMenuActive(Interface::Menu_438, 0) &&
             !Interface::IsMenuActive(Interface::Menu_439, 0) && !Interface::IsMenuActive(Interface::Menu_43a, 0) &&
             !Interface::IsMenuActive(Interface::Menu_43b, 0))
    {
        reinterpret_cast<::fnv_00877430::FUN_00877430_shell *>((reinterpret_cast<Main*>(this)))->FUN_00877430();
    }
}
