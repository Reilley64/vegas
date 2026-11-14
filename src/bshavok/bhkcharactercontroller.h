
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "bhkcharactercontroller_decls.h"

// @fnv 0x00560d30
float& bhkCharacterController::GetVectorElement(int index)
{
    return components[index];
}

// @fnv 0x00931ed0
GlobalObject_008c71b0 MobileObject::GetVectorElement()
{
    bhkCharacterController* controller = ((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    return controller ? controller->FUN_0070c440() : GlobalObject_008c71b0(0);
}
